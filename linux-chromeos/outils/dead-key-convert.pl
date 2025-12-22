#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-10-23T2145+0200
# 2025-11-15T0554+0100
# 2025-12-22T0452+0100
# = last modified.
#
# This “dead key converter” generates DEADTRANS macro calls for Windows. As it
# takes in the dead key configuration file for Linux, Compose.yml, it is part
# of the toolset for Linux that also encompasses the HTML	table generators for
# the documentation.
#
# This script has the two replacerulesets documented in Compose.yml built in,
# and sorting is improved.
# https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
# See Compose.yml # # Notes for maintenance
#
# Chained dead keys started being supported on 2025-10-18. New dead key chains
# require a dedicated dead character in the subroutine get_dead_character, and
# need to be added in @chained for a virtual dead key to be generated. Chains
# need to be supported incrementally, even when there is no output for a given
# intermediate chain.
# See Compose.yml # # Lenient dead key press
#
# Not all chained dead keys are symmetric. As the symmetricity of chained dead
# keys cannot be assumed and so, cannot be relied upon, dead key chains have a
# distinctive dead character each one throughout except for the group dead key,
# where the outcome is predictable and allows for a consistent user experience.
# See Compose.yml # # Order of mixed dead keys
# See Compose.yml # # MACRON&DIAERESIS
# See Compose.yml # # DIAERESIS&MACRON
# See Compose.yml # # SUPERSCRIPT&TURNED&BREVE
# See Compose.yml # # SUPERSCRIPT&RETROFLEX_HOOK&BREVE
# See Compose.yml # # SUPERSCRIPT&BREVE
# See Compose.yml # # SUPERSCRIPT&BAR
# See Compose.yml # # SUPERSCRIPT&SUBSCRIPT&BREVE
# See Compose.yml # # SUBSCRIPT&BREVE
# See Compose.yml # # SUBSCRIPT&BAR
#
# The sequences ending in dead_greek are required because dead_greek is
# duplicated on the position of the at sign on the ASCII symbol map, key D06.
#
# Polytonic Greek was first skipped as off-topic, to alleviate development of
# premium user experience on Windows. That saved 256 chained dead keys (as well
# as 1,886 dead key sequences). But support was unlocked on 2025-10-28.
# See Compose.yml # # End note about polytonic Greek
#
# Multikey sequences need to be processed separately. These are unrelated to,
# or not congruent with, the dead key output, as about 100 multikey equivalents
# are commented out due to conflicts.
#
# Multikey equivalents of dead keys cannot be supported on Windows because that
# bloats the layout drivers, that are then prone to crashing the keyboard, and
# because the first private use area E000..F8FF encompassing 6400 code points
# is nearly used up by dedicated multikey sequences. On 2025-12-21, a resulting
# set of 5252 multikey chains used E202..F683.
#
# For test purposes, this part can be toggled here:
my $support_multikey_equivalents = !1;
#
# This is different from dedicated multikey, that is indispensable. After an
# attempt to support all multikey sequences on 2025-11-12, the subset of the
# dedicated multikey sequences is ultimately supported since 2025-12-22.
#
# On 2025-10-29, 1 097 sequences have multicharacter output. Most are letters
# with combining diacritics, since composed letters are standard and mostly do
# not have precomposed equivalents. Additionally, an "ê" key and a "ç" key are
# emulated by digraphs or trigraphs output by the related dead keys.
#
# But Windows is unable to output any of these strings by dead keys, due to an
# improperly designed DEADTRANS macro. To mitigate the resulting UX disruption,
# string start output is configured in kbdeadtrans.c.
# See there * Diacriticized letter key emulations.
#
# In order to compensate Windows users for a defective dead key implementation
# that disregards the official Unicode recommendation as of supporting composed
# letters by dead keys, alternative input may be provided in Compose.yml, so as
# to have all sequences in a single place, given that documenting them requires
# special formatting in the dead key tables, that Compose.yml is the source of.
# These lines starting with "#@" are parsed in Compose.yml alongside.
# https://www.unicode.org/versions/Unicode17.0.0/core-spec/chapter-5/#G1076
# See Compose.yml # # Notes about documentation
# See Compose.yml # # Notes for maintenance
#
# 2 145 dead key sequences yield Latin letters or mathematical symbols encoded
# in the SMP that Windows is unable to output in one go by a dead key. As a
# workaround, the dead key output is restricted to the low surrogate. An input
# method for the high surrogates is provided separately at the root of related
# dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
# most dead keys, at level 4 of the space bar in French mode.
#
# The 7 required high surrogates are:
#
#     D801, D807,
#     D835, D837, D83C, D83D, D83E.
#
# These are dispatched among dead keys:
#
#     D801 dead_superscript (modifier letters)
#     D807 dead_turned (U+11FB0 "𑾰" LISU LETTER YHA)
#     D835 dead_group (mathematical alphanumeric symbols)
#     D837 dead_bar; dead_breve; dead_hook; dead_retroflexhook; others (Latin)
#     D83C dead_flag; dead_greek (flag letters, squared letters)
#     D83D dead_doubleacute; dead_acute; others (ornamental quotation marks)
#     D83E dead_stroke; dead_group 11 and 12 as built-in (wide-headed arrows)
#
# The output is directly in C, where an array of DEADTRANS macro calls makes
# for a flat layout of dead key data, while in KLC format, the data is grouped
# under DEADKEY headers. When KbdUTool transpiles from KLC to C, comments are
# ignored under the assumption that development happens in KLC only. But this
# is just not possible, given that KbdUTool’s KLC-to-C transpiler is broken, as
# it is unable to handle dead characters above 0x0FFF and to transpile KanaLock
# levels. Moreover, ligatures are transpiled only up to 5 code units due to the
# general header not supporting the architectural limit almost exhausted by the
# subdivision flags. And KLC only supports end-of-line comments, while leading
# block comments (in addition to EOL comments) are best for human readability,
# and with long lists are more readable than the grouped layout.
#
# Another upside of writing dead key data in C is that any DEADTRANS macro call
# can be overridden by a similar call, with the same input and the same dead
# character, but another output, provided that the valid call precedes in the
# source code.
#
# XKB keysyms are converted as needed, without directly using keysymdef.h, and
# many custom keysyms are added. Furthermore, the Compose.yml file has been set
# up from scratch without being based on any Compose file found in X11.
# See Compose.yml Legal note
#
# Printing the terminal output both to the console and to a file requires
# duplicating the print statements.
# https://stackoverflow.com/questions/16652836/printing-to-stdout-and-file-simultaneously
#
#
# Using old-style file handles.
use strict;
use warnings;
# By courtesy of https://stackoverflow.com/questions/33341223/suppress-uninitailized-perl-warning
no warnings 'uninitialized';
use utf8;
use feature 'unicode_strings';

# By courtesy of https://stackoverflow.com/a/12291409
use open ":std", ":encoding(UTF-8)";

my $console_log_path = 'WINDOWS/dead-key-convert-display.txt';
open( CONSOLE, '>', $console_log_path ) or die $!;
print( "Opened file $console_log_path.\n" );
print CONSOLE ( "Opened file $console_log_path.\n" );

my $input_path = 'Compose.yml';
open( INPUT, '<', $input_path ) or die $!;
print( "Opened file $input_path.\n" );
print CONSOLE ( "Opened file $input_path.\n" );

my $deadkey_path = 'WINDOWS/dead-keys.c';
open( DEADKEYS, '>', $deadkey_path ) or die $!;
print( "Opened file $deadkey_path.\n" );
print CONSOLE ( "Opened file $deadkey_path.\n" );

my $multikey_path = 'WINDOWS/multikey.c';
open( MULTIKEY, '>', $multikey_path ) or die $!;
print( "Opened file $multikey_path.\n" );
print CONSOLE ( "Opened file $multikey_path.\n" );

my $equivalents_path = 'WINDOWS/multikey-equivalents.c';
open( EQUIVALENTS, '>', $equivalents_path ) or die $!;
print( "Opened file $equivalents_path.\n" );
print CONSOLE ( "Opened file $equivalents_path.\n" );

my $report_path = 'WINDOWS/dead-keys.txt';
open( REPORT, '>', $report_path ) or die $!;
print( "Opened file $report_path.\n" );
print CONSOLE ( "Opened file $report_path.\n" );

my $log_path = 'WINDOWS/dead-key-high-log.txt';
open( LOG, '>', $log_path ) or die $!;
print( "Opened file $log_path.\n" );
print CONSOLE ( "Opened file $log_path.\n" );

print( "Processing content from $input_path to $deadkey_path and $multikey_path.\n" );
print CONSOLE ( "Processing content from $input_path to $deadkey_path and $multikey_path.\n" );
print( "This takes a lot of time to complete. There is some visual feedback to help with waiting,\n" );
print CONSOLE ( "This takes a lot of time to complete. There is some visual feedback to help with waiting,\n" );
print( "but it goes very fast and overflows the terminal, so this is logged in $console_log_path.\n" );
print CONSOLE ( "but it goes very fast and overflows the terminal, so this is logged in $console_log_path.\n" );

my $parse_on          = !0;
my $parse_equivalents = !1;
my @dead_key_out      = ();
my @unsupported       = ();
my @high_surrogates   = ();
my @bad_format        = ();
my $delim             = '"';
my $multichar         = 0;
my $half              = 0;
my $full              = 0;
my $overlong          = 0;
my $dead_hex          = 'E200';
my $dead_dec          = 57856;
my @multikey_parsed   = ();
my @multikey_complete = ();
my @multikey_out      = ();
my @multikey_dchars   = ();
my @multikey_print    = ();
my @mk_equiv_parsed   = ();
my @mk_equiv_complete = ();
my @mk_equiv_out      = ();
my @mk_equiv_print    = ();
my ( $chain, $comment, $deadchar, $deadkey, $full_chain, $high_out, $input, $input_string, $length,
		$output_code, $output_string, $preceding, $print, $high_su );
my $keysym            = '%ampersand';
my $multikey          = '<!M>';

sub format_character {
	my ( $character ) = @_;
	$character =~ s/<([^>]+)>/$1/;
	$character =~ s/<>>/>/;
	if ( $character =~ /^\\?.$/ ) {
		$character = "L'$character'";
	} elsif ( $character =~ /^[0-9a-fA-F]{4}$/ ) {
		$character = '0x' . $character;
	} else {
		push( @bad_format, "'" . $character . "'" );
		$character = 'badf'; # Comment this out to see the actual string in context.
	}
	return $character;
}

sub dekeysym {
	my ( $keysym ) = @_;

	$keysym =~ s/~spacezerowidth/200B/;
	$keysym =~ s/~space/ /;
	$keysym =~ s/~nbspace/00A0/;
	$keysym =~ s/~nbthinspace/202F/;
	$keysym =~ s/%exclam/!/;
	$keysym =~ s/%quotedbl/"/;
	$keysym =~ s/%hash/#/;
	$keysym =~ s/%dollar/\$/;
	$keysym =~ s/%percent/%/;
	$keysym =~ s/%ampersand/&/;
	$keysym =~ s/%apostrophe/\\'/;
	$keysym =~ s/%parenleft/(/;
	$keysym =~ s/%parenright/)/;
	$keysym =~ s/%asterisk/*/;
	$keysym =~ s/%plus/+/;
	$keysym =~ s/%comma/,/;
	$keysym =~ s/%minus/-/;
	$keysym =~ s/%period/./;
	$keysym =~ s/%slash/\//;
	$keysym =~ s/%colon/:/;
	$keysym =~ s/%semicolon/;/;
	$keysym =~ s/%less/</;
	$keysym =~ s/%equal/=/;
	$keysym =~ s/%greater/>/;
	$keysym =~ s/%question/?/;
	$keysym =~ s/%at/@/;
	$keysym =~ s/%bracketleft/[/;
	$keysym =~ s/%backslash/\\\\/;
	$keysym =~ s/%bracketright/]/;
	$keysym =~ s/%circum/^/;
	$keysym =~ s/%underscore/_/;
	$keysym =~ s/%grave/`/;
	$keysym =~ s/%braceleft/{/;
	$keysym =~ s/%bar/|/;
	$keysym =~ s/%braceright/}/;
	$keysym =~ s/%tilde/~/;
	$keysym =~ s/%aprightsingquotmark/2019/;
	$keysym =~ s/%semsection/00A7/;
	$keysym =~ s/%quotEuroSign/20AC/;
	$keysym =~ s/paragraph/00A7/;
	$keysym =~ s/guillemotleft/00AB/;
	$keysym =~ s/guillemotright/00BB/;
	$keysym =~ s/hyphen/00AD/;
	$keysym =~ s/degree/00B0/;
	$keysym =~ s/twosuperior/00B2/;
	$keysym =~ s/threesuperior/00B3/;
	$keysym =~ s/multiply/00D7/;
	$keysym =~ s/division/00F7/;
	$keysym =~ s/endash/2013/;
	$keysym =~ s/emdash/2014/;
	$keysym =~ s/Greek_horizbar/2015/;
	$keysym =~ s/ellipsis/2026/;
	$keysym =~ s/periodcentered/00B7/;
	$keysym =~ s/eacute/00E9/;
	$keysym =~ s/Eacute/00C9/;
	$keysym =~ s/egrave/00E8/;
	$keysym =~ s/Egrave/00C8/;
	$keysym =~ s/ccedilla/00E7/;
	$keysym =~ s/Ccedilla/00C7/;
	$keysym =~ s/agrave/00E0/;
	$keysym =~ s/Agrave/00C0/;
	$keysym =~ s/ugrave/00F9/;
	$keysym =~ s/Ugrave/00D9/;
	$keysym =~ s/adiaeresis/00E4/;
	$keysym =~ s/Adiaeresis/00C4/;
	$keysym =~ s/odiaeresis/00F6/;
	$keysym =~ s/Odiaeresis/00D6/;
	$keysym =~ s/udiaeresis/00FC/;
	$keysym =~ s/Udiaeresis/00DC/;
	$keysym =~ s/ntilde/00F1/;
	$keysym =~ s/Ntilde/00D1/;
	$keysym =~ s/eopen/025B/;
	$keysym =~ s/Eopen/0190/;
	$keysym =~ s/oopen/0254/;
	$keysym =~ s/Oopen/0186/;

	return $keysym;
}

sub get_dead_character {
	my ( $deadkey ) = @_;

	# Single-press dead keys (33).
	$deadkey =~ s/^<!superscript>$/^/;
	$deadkey =~ s/^<!turned>$/0250/;
	$deadkey =~ s/^<!doubleacute>$/0151/;
	$deadkey =~ s/^<!reversed>$/1D19/;
	$deadkey =~ s/^<!tilde>$/00F5/;
	$deadkey =~ s/^<!greek>$/03B5/;
	$deadkey =~ s/^<!acute>$/00E1/;
	$deadkey =~ s/^<!hook>$/0192/;
	$deadkey =~ s/^<!retroflexhook>$/0273/;
	$deadkey =~ s/^<!abovedot>$/1E57/;
	$deadkey =~ s/^<!group>$/2460/;
	$deadkey =~ s/^<!currency>$/00A4/;
	$deadkey =~ s/^<!invertedbreve>$/0213/;
	$deadkey =~ s/^<!breve>$/0115/;
	$deadkey =~ s/^<!bar>$/024D/;
	$deadkey =~ s/^<!horn>$/01A1/;
	$deadkey =~ s/^<!subscript>$/_/;
	$deadkey =~ s/^<!ogonek>$/01EB/;
	$deadkey =~ s/^<!abovehook>$/1EBB/;
	$deadkey =~ s/^<!macron>$/0101/;
	$deadkey =~ s/^<!stroke>$/00F8/;
	$deadkey =~ s/^<!abovering>$/00E5/;
	$deadkey =~ s/^<!circumflex>$/00EA/;
	$deadkey =~ s/^<!caron>$/021F/;
	$deadkey =~ s/^<!flag>$/2690/;
	$deadkey =~ s/^<!grave>$/00F2/;
	$deadkey =~ s/^<!cedilla>$/00E7/;
	$deadkey =~ s/^<!belowdot>$/1E05/;
	$deadkey =~ s/^<!diaeresis>$/00EB/;
	$deadkey =~ s/^<!belowcomma>$/0219/;
	$deadkey =~ s/^<!legacygrave>$/`/;
	$deadkey =~ s/^<!legacytilde>$/~/;
	$deadkey =~ s/^<!M>$/00A6/;

	# Dead key chains (575).
	$deadkey =~ s/^<!abovedot><!abovedot>$/02C8/;#<dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!abovedot><!abovedot><!acute>$/02C7/;#<dead_abovedot><dead_abovedot><dead_acute>
	$deadkey =~ s/^<!abovedot><!abovedot><!acute><!grave>$/02B7/;#<dead_abovedot><dead_abovedot><dead_acute><dead_grave>
	$deadkey =~ s/^<!abovedot><!abovedot><!grave>$/02C6/;#<dead_abovedot><dead_abovedot><dead_grave>
	$deadkey =~ s/^<!abovedot><!abovedot><!grave><!acute>$/1D50/;#<dead_abovedot><dead_abovedot><dead_grave><dead_acute>
	$deadkey =~ s/^<!abovedot><!abovedot><!macron>$/1D38/;#<dead_abovedot><dead_abovedot><dead_macron>
	$deadkey =~ s/^<!abovedot><!acute>$/1E64/;#<dead_abovedot><dead_acute>
	$deadkey =~ s/^<!abovedot><!acute><!grave>$/1D3B/;#<dead_abovedot><dead_acute><dead_grave>
	$deadkey =~ s/^<!abovedot><!bar>$/025F/;#<dead_abovedot><UEFD8>
	$deadkey =~ s/^<!abovedot><!belowdot>$/1E68/;#<dead_abovedot><dead_belowdot>
	$deadkey =~ s/^<!abovedot><!breve>$/A8F2/;#<dead_abovedot><dead_breve>
	$deadkey =~ s/^<!abovedot><!caron>$/1E66/;#<dead_abovedot><dead_caron>
	$deadkey =~ s/^<!abovedot><!grave>$/A718/;#<dead_abovedot><dead_grave>
	$deadkey =~ s/^<!abovedot><!grave><!acute>$/1D3A/;#<dead_abovedot><dead_grave><dead_acute>
	$deadkey =~ s/^<!abovedot><!group>$/1E9B/;#<dead_abovedot><UEFD0>
	$deadkey =~ s/^<!abovedot><!group><!group>$/2A81/;#<dead_abovedot><UEFD0><UEFD0>
	$deadkey =~ s/^<!abovedot><!group><!group><!group>$/2A6D/;#<dead_abovedot><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!abovedot><!group><3>$/2A6D/;#<dead_abovedot><UEFD0><3>
	$deadkey =~ s/^<!abovedot><!macron>$/01E1/;#<dead_abovedot><dead_macron>
	$deadkey =~ s/^<!abovehook><!abovehook>$/A7BB/;#<UEFD3><UEFD3>
	$deadkey =~ s/^<!abovehook><!breve>$/1EB2/;#<UEFD3><dead_breve>
	$deadkey =~ s/^<!abovehook><!circumflex>$/1EA9/;#<UEFD3><dead_circumflex>
	$deadkey =~ s/^<!abovehook><!horn>$/1EDF/;#<UEFD3><dead_horn>
	$deadkey =~ s/^<!abovering><!abovering>$/1E01/;#<dead_abovering><dead_abovering>
	$deadkey =~ s/^<!abovering><!acute>$/01FB/;#<dead_abovering><dead_acute>
	$deadkey =~ s/^<!abovering><!currency>$/222E/;#<dead_abovering><dead_currency>
	$deadkey =~ s/^<!abovering><!diaeresis>$/02DA/;#<dead_abovering><dead_diaeresis>
	$deadkey =~ s/^<!abovering><!group>$/AB4C/;#<dead_abovering><UEFD0>
	$deadkey =~ s/^<!abovering><!group><!group>$/222F/;#<dead_abovering><UEFD0><UEFD0>
	$deadkey =~ s/^<!abovering><!group><!group><!group>$/2230/;#<dead_abovering><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!abovering><!group><!group><!group><!group>$/AB4d/;#<dead_abovering><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!abovering><!group><1>$/AB4f/;#<dead_abovering><UEFD0><1>
	$deadkey =~ s/^<!abovering><!group><2>$/AB4b/;#<dead_abovering><UEFD0><2>
	$deadkey =~ s/^<!abovering><!group><3>$/2230/;#<dead_abovering><UEFD0><3>
	$deadkey =~ s/^<!abovering><!group><4>$/AB4d/;#<dead_abovering><UEFD0><4>
	$deadkey =~ s/^<!abovering><!group><5>$/AB4e/;#<dead_abovering><UEFD0><5>
	$deadkey =~ s/^<!acute><!abovedot>$/1E65/;#<dead_acute><dead_abovedot>
	$deadkey =~ s/^<!acute><!abovedot><!abovedot>$/02BF/;#<dead_acute><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!acute><!abovering>$/01FA/;#<dead_acute><dead_abovering>
	$deadkey =~ s/^<!acute><!acute>$/0171/;#<dead_acute><dead_acute>
	$deadkey =~ s/^<!acute><!breve>$/1EAE/;#<dead_acute><dead_breve>
	$deadkey =~ s/^<!acute><!cedilla>$/1E09/;#<dead_acute><dead_cedilla>
	$deadkey =~ s/^<!acute><!circumflex>$/1EA5/;#<dead_acute><dead_circumflex>
	$deadkey =~ s/^<!acute><!diaeresis>$/1E2E/;#<dead_acute><dead_diaeresis>
	$deadkey =~ s/^<!acute><!grave>$/02C4/;#<dead_acute><dead_grave>
	$deadkey =~ s/^<!acute><!grave><!macron>$/02DF/;#<dead_acute><dead_grave><dead_macron>
	$deadkey =~ s/^<!acute><!group>$/01FD/;#<dead_acute><UEFD0>
	$deadkey =~ s/^<!acute><!group><!group>$/275E/;#<dead_acute><UEFD0><UEFD0>
	$deadkey =~ s/^<!acute><!horn>$/1EDA/;#<dead_acute><dead_horn>
	$deadkey =~ s/^<!acute><!macron>$/1E16/;#<dead_acute><dead_macron>
	$deadkey =~ s/^<!acute><!macron><!grave>$/02C9/;#<dead_acute><dead_macron><dead_grave>
	$deadkey =~ s/^<!acute><!stroke>$/01FE/;#<dead_acute><dead_stroke>
	$deadkey =~ s/^<!acute><!tilde>$/1E4C/;#<dead_acute><dead_tilde>
	$deadkey =~ s/^<!bar><!abovedot>$/0284/;#<UEFD8><dead_abovedot>
	$deadkey =~ s/^<!bar><!bar>$/A78A/;#<UEFD8><UEFD8>
	$deadkey =~ s/^<!bar><!bar><!bar>$/02C2/;#<UEFD8><UEFD8><UEFD8>
	$deadkey =~ s/^<!bar><!bar><!group>$/A767/;#<UEFD8><UEFD8><UEFD0>
	$deadkey =~ s/^<!bar><!bar><!hook>$/0286/;#<UEFD8><UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!bar><!hook><!hook>$/0283/;#<UEFD8><UEFD8><dead_hook><dead_hook>
	$deadkey =~ s/^<!bar><!bar><!hook><!hook><!group>$/1D98/;#<UEFD8><UEFD8><dead_hook><dead_hook><UEFD0>
	$deadkey =~ s/^<!bar><!group>$/1D7C/;#<UEFD8><UEFD0>
	$deadkey =~ s/^<!bar><!group><!group>$/AB30/;#<UEFD8><UEFD0><UEFD0>
	$deadkey =~ s/^<!bar><!group><!group><!group>$/1E9D/;#<UEFD8><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!bar><!group><3>$/1E9D/;#<UEFD8><UEFD0><3>
	$deadkey =~ s/^<!bar><!hook>$/1D8B/;#<UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!bar>$/0285/;#<UEFD8><dead_hook><UEFD8>
	$deadkey =~ s/^<!bar><!hook><!bar><!hook>$/01AA/;#<UEFD8><dead_hook><UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!bar><!hook><!group>$/0282/;#<UEFD8><dead_hook><UEFD8><dead_hook><UEFD0>
	$deadkey =~ s/^<!bar><!hook><!hook>$/01A9/;#<UEFD8><dead_hook><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!hook><!bar>$/0287/;#<UEFD8><dead_hook><dead_hook><UEFD8>
	$deadkey =~ s/^<!bar><!hook><!hook><!bar><!group>$/0288/;#<UEFD8><dead_hook><dead_hook><UEFD8><UEFD0>
	$deadkey =~ s/^<!bar><!retroflexhook>$/0268/;#<UEFD8><UEFD4>
	$deadkey =~ s/^<!bar><!reversed>$/029E/;#<UEFD8><UEFD6>
	$deadkey =~ s/^<!bar><!stroke>$/A745/;#<UEFD8><dead_stroke>
	$deadkey =~ s/^<!bar><!subscript>$/1D03/;#<UEFD8><UEFD2>
	$deadkey =~ s/^<!bar><!superscript>$/02A1/;#<UEFD8><UEFD1>
	$deadkey =~ s/^<!bar><!superscript><!group>$/1D2F/;#<UEFD8><UEFD1><UEFD0>
	$deadkey =~ s/^<!bar><!turned>$/2013/;#<UEFD8><UEFD5>
	$deadkey =~ s/^<!bar><!turned><!group>$/0153/;#<UEFD8><UEFD5><UEFD0>
	$deadkey =~ s/^<!belowcomma><!belowcomma>$/02BC/;#<dead_belowcomma><dead_belowcomma>
	$deadkey =~ s/^<!belowcomma><!group>$/A72F/;#<dead_belowcomma><UEFD0>
	$deadkey =~ s/^<!belowcomma><!group><!group>$/A72E/;#<dead_belowcomma><UEFD0><UEFD0>
	$deadkey =~ s/^<!belowcomma><!group><!group><!group>$/A72D/;#<dead_belowcomma><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!belowcomma><!group><!group><!group><!group>$/A72C/;#<dead_belowcomma><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!belowcomma><!group><3>$/A72D/;#<dead_belowcomma><UEFD0><3>
	$deadkey =~ s/^<!belowcomma><!group><4>$/A72C/;#<dead_belowcomma><UEFD0><4>
	$deadkey =~ s/^<!belowcomma><!group><5>$/A72B/;#<dead_belowcomma><UEFD0><5>
	$deadkey =~ s/^<!belowdot><!abovedot>$/1E69/;#<dead_belowdot><dead_abovedot>
	$deadkey =~ s/^<!belowdot><!belowdot>$/02CC/;#<dead_belowdot><dead_belowdot>
	$deadkey =~ s/^<!belowdot><!breve>$/1EB6/;#<dead_belowdot><dead_breve>
	$deadkey =~ s/^<!belowdot><!circumflex>$/1EAD/;#<dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!horn>$/1EE2/;#<dead_belowdot><dead_horn>
	$deadkey =~ s/^<!belowdot><!macron>$/1E39/;#<dead_belowdot><dead_macron>
	$deadkey =~ s/^<!breve><!abovedot>$/A8F3/;#<dead_breve><dead_abovedot>
	$deadkey =~ s/^<!breve><!abovehook>$/1EB3/;#<dead_breve><UEFD3>
	$deadkey =~ s/^<!breve><!acute>$/1EAF/;#<dead_breve><dead_acute>
	$deadkey =~ s/^<!breve><!belowdot>$/1EB7/;#<dead_breve><dead_belowdot>
	$deadkey =~ s/^<!breve><!breve>$/1E2B/;#<dead_breve><dead_breve>
	$deadkey =~ s/^<!breve><!breve><!retroflexhook>$/026D/;#<dead_breve><dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!breve><!retroflexhook><!retroflexhook>$/026C/;#<dead_breve><dead_breve><UEFD4><UEFD4>
	$deadkey =~ s/^<!breve><!breve><!subscript>$/1DAB/;#<dead_breve><dead_breve><UEFD2>
	$deadkey =~ s/^<!breve><!breve><!superscript>$/028E/;#<dead_breve><dead_breve><UEFD1>
	$deadkey =~ s/^<!breve><!breve><!turned>$/028C/;#<dead_breve><dead_breve><UEFD5>
	$deadkey =~ s/^<!breve><!cedilla>$/1E1D/;#<dead_breve><dead_cedilla>
	$deadkey =~ s/^<!breve><!grave>$/1EB1/;#<dead_breve><dead_grave>
	$deadkey =~ s/^<!breve><!macron>$/02D8/;#<dead_breve><dead_macron>
	$deadkey =~ s/^<!breve><!retroflexhook>$/A78D/;#<dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!breve>$/026B/;#<dead_breve><UEFD4><dead_breve>
	$deadkey =~ s/^<!breve><!retroflexhook><!breve><!retroflexhook>$/026E/;#<dead_breve><UEFD4><dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!retroflexhook>$/1D85/;#<dead_breve><UEFD4><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!retroflexhook><!breve>$/0269/;#<dead_breve><UEFD4><UEFD4><dead_breve>
	$deadkey =~ s/^<!breve><!subscript>$/029F/;#<dead_breve><UEFD2>
	$deadkey =~ s/^<!breve><!subscript><!breve>$/1DA9/;#<dead_breve><UEFD2><dead_breve>
	$deadkey =~ s/^<!breve><!superscript>$/1DAA/;#<dead_breve><UEFD1>
	$deadkey =~ s/^<!breve><!superscript><!breve>$/1DA1/;#<dead_breve><UEFD1><dead_breve>
	$deadkey =~ s/^<!breve><!tilde>$/1EB5/;#<dead_breve><dead_tilde>
	$deadkey =~ s/^<!breve><!turned>$/028D/;#<dead_breve><UEFD5>
	$deadkey =~ s/^<!breve><!turned><!breve>$/028F/;#<dead_breve><UEFD5><dead_breve>
	$deadkey =~ s/^<!caron><!abovedot>$/1E67/;#<dead_caron><dead_abovedot>
	$deadkey =~ s/^<!caron><!caron>$/02EC/;#<dead_caron><dead_caron>
	$deadkey =~ s/^<!caron><!diaeresis>$/01D9/;#<dead_caron><dead_diaeresis>
	$deadkey =~ s/^<!caron><!group>$/01EF/;#<dead_caron><UEFD0>
	$deadkey =~ s/^<!cedilla><!acute>$/1E08/;#<dead_cedilla><dead_acute>
	$deadkey =~ s/^<!cedilla><!breve>$/1E1C/;#<dead_cedilla><dead_breve>
	$deadkey =~ s/^<!cedilla><!cedilla>$/02BB/;#<dead_cedilla><dead_cedilla>
	$deadkey =~ s/^<!circumflex><!abovehook>$/1EA8/;#<dead_circumflex><UEFD3>
	$deadkey =~ s/^<!circumflex><!acute>$/1EA4/;#<dead_circumflex><dead_acute>
	$deadkey =~ s/^<!circumflex><!belowdot>$/1EAC/;#<dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!circumflex>$/01CD/;#<dead_circumflex><dead_circumflex>
	$deadkey =~ s/^<!circumflex><!circumflex><!circumflex>$/1E19/;#<dead_circumflex><dead_circumflex><dead_circumflex>
	$deadkey =~ s/^<!circumflex><!grave>$/1EA7/;#<dead_circumflex><dead_grave>
	$deadkey =~ s/^<!circumflex><!group>$/2A6F/;#<dead_circumflex><UEFD0>
	$deadkey =~ s/^<!circumflex><!group><!group>$/2661/;#<dead_circumflex><UEFD0><UEFD0>
	$deadkey =~ s/^<!circumflex><!group><!group><!group>$/2667/;#<dead_circumflex><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!circumflex><!group><!group><!group><!group>$/2662/;#<dead_circumflex><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!circumflex><!group><3>$/2667/;#<dead_circumflex><UEFD0><3>
	$deadkey =~ s/^<!circumflex><!group><4>$/2662/;#<dead_circumflex><UEFD0><4>
	$deadkey =~ s/^<!circumflex><!group><5>$/2663/;#<dead_circumflex><UEFD0><5>
	$deadkey =~ s/^<!circumflex><!tilde>$/1EAB/;#<dead_circumflex><dead_tilde>
	$deadkey =~ s/^<!currency><!abovering>$/2232/;#<dead_currency><dead_abovering>
	$deadkey =~ s/^<!currency><!cedilla>$/20B5/;#<dead_currency><dead_cedilla>
	$deadkey =~ s/^<!currency><!currency>$/09F2/;#<dead_currency><dead_currency>
	$deadkey =~ s/^<!diaeresis><!abovering>$/00A8/;#<dead_diaeresis><dead_abovering>
	$deadkey =~ s/^<!diaeresis><!acute>$/1E2F/;#<dead_diaeresis><dead_acute>
	$deadkey =~ s/^<!diaeresis><!caron>$/01DA/;#<dead_diaeresis><dead_caron>
	$deadkey =~ s/^<!diaeresis><!diaeresis>$/010E/;#<dead_diaeresis><dead_diaeresis>
	$deadkey =~ s/^<!diaeresis><!diaeresis><!diaeresis>$/1E73/;#<dead_diaeresis><dead_diaeresis><dead_diaeresis>
	$deadkey =~ s/^<!diaeresis><!grave>$/01DC/;#<dead_diaeresis><dead_grave>
	$deadkey =~ s/^<!diaeresis><!group>$/275F/;#<dead_diaeresis><UEFD0>
	$deadkey =~ s/^<!diaeresis><!group><!group>$/2760/;#<dead_diaeresis><UEFD0><UEFD0>
	$deadkey =~ s/^<!diaeresis><!macron>$/01D6/;#<dead_diaeresis><dead_macron>
	$deadkey =~ s/^<!diaeresis><!superscript>$/00E4/;#<dead_diaeresis><UEFD1>
	$deadkey =~ s/^<!diaeresis><!superscript><!superscript>$/00F6/;#<dead_diaeresis><UEFD1><UEFD1>
	$deadkey =~ s/^<!diaeresis><!tilde>$/1E4E/;#<dead_diaeresis><dead_tilde>
	$deadkey =~ s/^<!diaeresis><!turned>$/00FC/;#<dead_diaeresis><UEFD5>
	$deadkey =~ s/^<!diaeresis><!turned><!turned>$/00DC/;#<dead_diaeresis><UEFD5><UEFD5>
	$deadkey =~ s/^<!doubleacute><!doubleacute>$/2034/;#<dead_doubleacute><dead_doubleacute>
	$deadkey =~ s/^<!doubleacute><!reversed>$/263B/;#<dead_doubleacute><UEFD6>
	$deadkey =~ s/^<!flag><!flag>$/2691/;#<UEFD7><UEFD7>
	$deadkey =~ s/^<!flag><!flag><!flag>$/=/;#<UEFD7><UEFD7><UEFD7>
	$deadkey =~ s/^<!flag><!group>$/2E40/;#<UEFD7><UEFD0>
	$deadkey =~ s/^<!flag><!group><!group>$/22BC/;#<UEFD7><UEFD0><UEFD0>
	$deadkey =~ s/^<!flag><!group><!group><!group>$/2287/;#<UEFD7><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!flag><!group><3>$/2287/;#<UEFD7><UEFD0><3>
	$deadkey =~ s/^<!grave><!abovedot>$/A717/;#<dead_grave><dead_abovedot>
	$deadkey =~ s/^<!grave><!abovedot><!abovedot>$/2301/;#<dead_grave><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!grave><!acute>$/02C5/;#<dead_grave><dead_acute>
	$deadkey =~ s/^<!grave><!acute><!macron>$/2305/;#<dead_grave><dead_acute><dead_macron>
	$deadkey =~ s/^<!grave><!breve>$/1EB0/;#<dead_grave><dead_breve>
	$deadkey =~ s/^<!grave><!circumflex>$/1EA6/;#<dead_grave><dead_circumflex>
	$deadkey =~ s/^<!grave><!diaeresis>$/01DB/;#<dead_grave><dead_diaeresis>
	$deadkey =~ s/^<!grave><!grave>$/0201/;#<dead_grave><dead_grave>
	$deadkey =~ s/^<!grave><!horn>$/1EDC/;#<dead_grave><dead_horn>
	$deadkey =~ s/^<!grave><!macron>$/1E14/;#<dead_grave><dead_macron>
	$deadkey =~ s/^<!grave><!macron><!acute>$/2306/;#<dead_grave><dead_macron><dead_acute>
	$deadkey =~ s/^<!greek><!greek>$/229A/;#<dead_greek><dead_greek>
	$deadkey =~ s/^<!greek><!subscript>$/1D66/;#<dead_greek><UEFD2>
	$deadkey =~ s/^<!greek><%backslash>$/277F/;#<dead_greek><backslash>
	$deadkey =~ s/^<!greek><%backslash><%quotEuroSign>$/24EB/;#<dead_greek><backslash><EuroSign>
	$deadkey =~ s/^<!greek><%backslash><%quotedbl>$/24EC/;#<dead_greek><backslash><quotedbl>
	$deadkey =~ s/^<!greek><%backslash><%tilde>$/278A/;#<dead_greek><backslash><asciitilde>
	$deadkey =~ s/^<!greek><%bracketleft>$/2792/;#<dead_greek><bracketleft>
	$deadkey =~ s/^<!greek><%quotEuroSign>$/2473/;#<dead_greek><EuroSign>
	$deadkey =~ s/^<!greek><%quotEuroSign><%backslash>$/24F4/;#<dead_greek><EuroSign><backslash>
	$deadkey =~ s/^<!greek><%quotedbl>$/246E/;#<dead_greek><quotedbl>
	$deadkey =~ s/^<!greek><%quotedbl><%backslash>$/24F3/;#<dead_greek><quotedbl><backslash>
	$deadkey =~ s/^<!greek><%tilde>$/2789/;#<dead_greek><asciitilde>
	$deadkey =~ s/^<!greek><%tilde><%backslash>$/2793/;#<dead_greek><asciitilde><backslash>
	$deadkey =~ s/^<!group><!group>$/2461/;#<UEFD0><UEFD0>
	$deadkey =~ s/^<!group><!group><!group>$/2462/;#<UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!group><!group><!group><!group>$/2463/;#<UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!group><0>$/2469/;#<UEFD0><0>
	$deadkey =~ s/^<!group><0><%comma>$/213F/;#<UEFD0><0><comma>
	$deadkey =~ s/^<!group><0><%comma><%period>$/2145/;#<UEFD0><0><comma><period>
	$deadkey =~ s/^<!group><0><%period>$/2115/;#<UEFD0><0><period>
	$deadkey =~ s/^<!group><0><%period><%comma>$/2145/;#<UEFD0><0><period><comma>
	$deadkey =~ s/^<!group><1>$/246A/;#<UEFD0><1>
	$deadkey =~ s/^<!group><2>$/246B/;#<UEFD0><2>
	$deadkey =~ s/^<!group><3>$/2462/;#<UEFD0><3>
	$deadkey =~ s/^<!group><4>$/2463/;#<UEFD0><4>
	$deadkey =~ s/^<!group><5>$/2464/;#<UEFD0><5>
	$deadkey =~ s/^<!group><6>$/2465/;#<UEFD0><6>
	$deadkey =~ s/^<!group><6><%comma>$/213E/;#<UEFD0><6><comma>
	$deadkey =~ s/^<!group><6><%comma><%comma>$/2140/;#<UEFD0><6><comma><comma>
	$deadkey =~ s/^<!group><6><%comma><%comma><%period>$/2141/;#<UEFD0><6><comma><comma><period>
	$deadkey =~ s/^<!group><6><%comma><%period>$/213D/;#<UEFD0><6><comma><period>
	$deadkey =~ s/^<!group><6><%comma><%period><%comma>$/2141/;#<UEFD0><6><comma><period><comma>
	$deadkey =~ s/^<!group><6><%period>$/2147/;#<UEFD0><6><period>
	$deadkey =~ s/^<!group><6><%period><%comma>$/213D/;#<UEFD0><6><period><comma>
	$deadkey =~ s/^<!group><6><%period><%comma><%comma>$/2141/;#<UEFD0><6><period><comma><comma>
	$deadkey =~ s/^<!group><7>$/2466/;#<UEFD0><7>
	$deadkey =~ s/^<!group><7><%comma>$/212C/;#<UEFD0><7><comma>
	$deadkey =~ s/^<!group><7><%period>$/2148/;#<UEFD0><7><period>
	$deadkey =~ s/^<!group><8>$/2467/;#<UEFD0><8>
	$deadkey =~ s/^<!group><8><%comma>$/211D/;#<UEFD0><8><comma>
	$deadkey =~ s/^<!group><8><%comma><%period>$/2148/;#<UEFD0><8><comma><period>
	$deadkey =~ s/^<!group><8><%period>$/210E/;#<UEFD0><8><period>
	$deadkey =~ s/^<!group><8><%period><%comma>$/2148/;#<UEFD0><8><period><comma>
	$deadkey =~ s/^<!group><9>$/2468/;#<UEFD0><9>
	$deadkey =~ s/^<!group><9><%comma>$/2111/;#<UEFD0><9><comma>
	$deadkey =~ s/^<!group><9><%period>$/2102/;#<UEFD0><9><period>
	$deadkey =~ s/^<!group><ellipsis>$/263C/;#<UEFD0><ellipsis>
	$deadkey =~ s/^<!hook><!bar>$/AB3A/;#<dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!bar>$/027D/;#<dead_hook><UEFD8><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!bar><!hook>$/0278/;#<dead_hook><UEFD8><UEFD8><dead_hook>
	$deadkey =~ s/^<!hook><!bar><!bar><!hook><!group>$/027C/;#<dead_hook><UEFD8><UEFD8><dead_hook><UEFD0>
	$deadkey =~ s/^<!hook><!bar><!hook>$/027F/;#<dead_hook><UEFD8><dead_hook>
	$deadkey =~ s/^<!hook><!bar><!hook><!bar>$/0279/;#<dead_hook><UEFD8><dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!hook><!bar><!group>$/0280/;#<dead_hook><UEFD8><dead_hook><UEFD8><UEFD0>
	$deadkey =~ s/^<!hook><!group>$/0267/;#<dead_hook><UEFD0>
	$deadkey =~ s/^<!hook><!group><!group>$/01BA/;#<dead_hook><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!group><!group><!group>$/1D94/;#<dead_hook><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!group><3>$/1D94/;#<dead_hook><UEFD0><3>
	$deadkey =~ s/^<!hook><!hook>$/0255/;#<dead_hook><dead_hook>
	$deadkey =~ s/^<!hook><!hook><!bar>$/0257/;#<dead_hook><dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!hook><!bar><!bar>$/0256/;#<dead_hook><dead_hook><UEFD8><UEFD8>
	$deadkey =~ s/^<!hook><!hook><!bar><!bar><!group>$/0253/;#<dead_hook><dead_hook><UEFD8><UEFD8><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!group>$/02A5/;#<dead_hook><dead_hook><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!group><!group>$/AB36/;#<dead_hook><dead_hook><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!group><!group><!group>$/AB4A/;#<dead_hook><dead_hook><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!group><!group><!group><!group>$/02A8/;#<dead_hook><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!group><3>$/AB4A/;#<dead_hook><dead_hook><UEFD0><3>
	$deadkey =~ s/^<!hook><!hook><!group><4>$/02A8/;#<dead_hook><dead_hook><UEFD0><4>
	$deadkey =~ s/^<!hook><!hook><!group><5>$/02A7/;#<dead_hook><dead_hook><UEFD0><5>
	$deadkey =~ s/^<!hook><!hook><!hook>$/A796/;#<dead_hook><dead_hook><dead_hook>
	$deadkey =~ s/^<!hook><!hook><!superscript>$/1DA8/;#<dead_hook><dead_hook><UEFD1>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group>$/02A4/;#<dead_hook><dead_hook><UEFD1><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group>$/02A3/;#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group><!group>$/02B0/;#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group><!group><!group>$/02B1/;#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><3>$/02B0/;#<dead_hook><dead_hook><UEFD1><UEFD0><3>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><4>$/02B1/;#<dead_hook><dead_hook><UEFD1><UEFD0><4>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><5>$/02B2/;#<dead_hook><dead_hook><UEFD1><UEFD0><5>
	$deadkey =~ s/^<!hook><!hook><!turned>$/028A/;#<dead_hook><dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!hook><!turned><!turned>$/0296/;#<dead_hook><dead_hook><UEFD5><UEFD5>
	$deadkey =~ s/^<!hook><!retroflexhook>$/1D91/;#<dead_hook><UEFD4>
	$deadkey =~ s/^<!hook><!retroflexhook><!retroflexhook>$/01AB/;#<dead_hook><UEFD4><UEFD4>
	$deadkey =~ s/^<!hook><!retroflexhook><!turned>$/02AF/;#<dead_hook><UEFD4><UEFD5>
	$deadkey =~ s/^<!hook><!reversed>$/025D/;#<dead_hook><UEFD6>
	$deadkey =~ s/^<!hook><!reversed><!group>$/025C/;#<dead_hook><UEFD6><UEFD0>
	$deadkey =~ s/^<!hook><!reversed><!group><!group>$/025E/;#<dead_hook><UEFD6><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!subscript>$/029B/;#<dead_hook><UEFD2>
	$deadkey =~ s/^<!hook><!superscript>$/1D9D/;#<dead_hook><UEFD1>
	$deadkey =~ s/^<!hook><!superscript><!group>$/1DAC/;#<dead_hook><UEFD1><UEFD0>
	$deadkey =~ s/^<!hook><!superscript><!hook>$/1DBD/;#<dead_hook><UEFD1><dead_hook>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group>$/1DBF/;#<dead_hook><UEFD1><dead_hook><UEFD0>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group>$/1DBE/;#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group><!group>$/1DBC/;#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group><!group><!group>$/1DBA/;#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><3>$/1DBC/;#<dead_hook><UEFD1><dead_hook><UEFD0><3>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><4>$/1DBA/;#<dead_hook><UEFD1><dead_hook><UEFD0><4>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><5>$/1DB9/;#<dead_hook><UEFD1><dead_hook><UEFD0><5>
	$deadkey =~ s/^<!hook><!superscript><!turned>$/02B5/;#<dead_hook><UEFD1><UEFD5>
	$deadkey =~ s/^<!hook><!tilde>$/1D73/;#<dead_hook><dead_tilde>
	$deadkey =~ s/^<!hook><!turned>$/01BE/;#<dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!hook>$/0295/;#<dead_hook><UEFD5><dead_hook>
	$deadkey =~ s/^<!hook><!turned><!hook><!turned>$/0294/;#<dead_hook><UEFD5><dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!retroflexhook>$/02AE/;#<dead_hook><UEFD5><UEFD4>
	$deadkey =~ s/^<!hook><!turned><!superscript>$/02B8/;#<dead_hook><UEFD5><UEFD1>
	$deadkey =~ s/^<!hook><!turned><!turned>$/02C0/;#<dead_hook><UEFD5><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!turned><!hook>$/02C1/;#<dead_hook><UEFD5><UEFD5><dead_hook>
	$deadkey =~ s/^<!horn><!abovehook>$/1EDE/;#<dead_horn><UEFD3>
	$deadkey =~ s/^<!horn><!acute>$/1EDB/;#<dead_horn><dead_acute>
	$deadkey =~ s/^<!horn><!belowdot>$/1EE3/;#<dead_horn><dead_belowdot>
	$deadkey =~ s/^<!horn><!grave>$/1EDD/;#<dead_horn><dead_grave>
	$deadkey =~ s/^<!horn><!horn>$/1E18/;#<dead_horn><dead_horn>
	$deadkey =~ s/^<!horn><!tilde>$/1EE1/;#<dead_horn><dead_tilde>
	$deadkey =~ s/^<!invertedbreve><!group>$/02A9/;#<dead_invertedbreve><UEFD0>
	$deadkey =~ s/^<!invertedbreve><!group><!group>$/0238/;#<dead_invertedbreve><UEFD0><UEFD0>
	$deadkey =~ s/^<!invertedbreve><!group><!group><!group>$/0239/;#<dead_invertedbreve><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!invertedbreve><!group><!group><!group><!group>$/023A/;#<dead_invertedbreve><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!invertedbreve><!group><1>$/023C/;#<dead_invertedbreve><UEFD0><1>
	$deadkey =~ s/^<!invertedbreve><!group><3>$/0239/;#<dead_invertedbreve><UEFD0><3>
	$deadkey =~ s/^<!invertedbreve><!group><4>$/023A/;#<dead_invertedbreve><UEFD0><4>
	$deadkey =~ s/^<!invertedbreve><!group><5>$/023B/;#<dead_invertedbreve><UEFD0><5>
	$deadkey =~ s/^<!invertedbreve><!invertedbreve>$/1D16/;#<dead_invertedbreve><dead_invertedbreve>
	$deadkey =~ s/^<!macron><!abovedot>$/01E0/;#<dead_macron><dead_abovedot>
	$deadkey =~ s/^<!macron><!abovedot><!abovedot>$/02D4/;#<dead_macron><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!macron><!acute>$/1E17/;#<dead_macron><dead_acute>
	$deadkey =~ s/^<!macron><!acute><!grave>$/02CA/;#<dead_macron><dead_acute><dead_grave>
	$deadkey =~ s/^<!macron><!belowdot>$/1E38/;#<dead_macron><dead_belowdot>
	$deadkey =~ s/^<!macron><!breve>$/02D7/;#<dead_macron><dead_breve>
	$deadkey =~ s/^<!macron><!diaeresis>$/1E7B/;#<dead_macron><dead_diaeresis>
	$deadkey =~ s/^<!macron><!grave>$/1E15/;#<dead_macron><dead_grave>
	$deadkey =~ s/^<!macron><!grave><!acute>$/02CD/;#<dead_macron><dead_grave><dead_acute>
	$deadkey =~ s/^<!macron><!group>$/01E3/;#<dead_macron><UEFD0>
	$deadkey =~ s/^<!macron><!group><!group>$/0297/;#<dead_macron><UEFD0><UEFD0>
	$deadkey =~ s/^<!macron><!macron>$/1E07/;#<dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!macron><!macron>$/2A60/;#<dead_macron><dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!ogonek>$/01EC/;#<dead_macron><dead_ogonek>
	$deadkey =~ s/^<!macron><!retroflexhook>$/02FD/;#<dead_macron><UEFD4>
	$deadkey =~ s/^<!macron><!retroflexhook><!superscript>$/0271/;#<dead_macron><UEFD4><UEFD1>
	$deadkey =~ s/^<!macron><!retroflexhook><!turned>$/0270/;#<dead_macron><UEFD4><UEFD5>
	$deadkey =~ s/^<!macron><!superscript>$/02E5/;#<dead_macron><UEFD1>
	$deadkey =~ s/^<!macron><!superscript><!retroflexhook>$/026F/;#<dead_macron><UEFD1><UEFD4>
	$deadkey =~ s/^<!macron><!superscript><!turned>$/1DAD/;#<dead_macron><UEFD1><UEFD5>
	$deadkey =~ s/^<!macron><!tilde>$/022C/;#<dead_macron><dead_tilde>
	$deadkey =~ s/^<!macron><!turned>$/027A/;#<dead_macron><UEFD5>
	$deadkey =~ s/^<!macron><!turned><!retroflexhook>$/0281/;#<dead_macron><UEFD5><UEFD4>
	$deadkey =~ s/^<!macron><!turned><!superscript>$/0265/;#<dead_macron><UEFD5><UEFD1>
	$deadkey =~ s/^<!ogonek><!macron>$/01ED/;#<dead_ogonek><dead_macron>
	$deadkey =~ s/^<!ogonek><!ogonek>$/A71A/;#<dead_ogonek><dead_ogonek>
	$deadkey =~ s/^<!retroflexhook><!bar>$/026A/;#<UEFD4><UEFD8>
	$deadkey =~ s/^<!retroflexhook><!breve>$/A78E/;#<UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!breve><!breve>$/A799/;#<UEFD4><dead_breve><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!breve><!breve><!retroflexhook>$/0264/;#<UEFD4><dead_breve><dead_breve><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!breve><!retroflexhook>$/0263/;#<UEFD4><dead_breve><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!breve><!retroflexhook><!breve>$/0260/;#<UEFD4><dead_breve><UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!group>$/1D90/;#<UEFD4><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!group><!group>$/1D95/;#<UEFD4><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!group><!group><!group>$/1D93/;#<UEFD4><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!group><!group><!group><!group>$/1D97/;#<UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!group><3>$/1D93/;#<UEFD4><UEFD0><3>
	$deadkey =~ s/^<!retroflexhook><!group><4>$/1D97/;#<UEFD4><UEFD0><4>
	$deadkey =~ s/^<!retroflexhook><!group><5>$/AB67/;#<UEFD4><UEFD0><5>
	$deadkey =~ s/^<!retroflexhook><!hook>$/1D8F/;#<UEFD4><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!hook><!retroflexhook>$/027E/;#<UEFD4><dead_hook><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!hook><!turned>$/02B3/;#<UEFD4><dead_hook><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!macron>$/02FE/;#<UEFD4><dead_macron>
	$deadkey =~ s/^<!retroflexhook><!macron><!superscript>$/02B4/;#<UEFD4><dead_macron><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!macron><!turned>$/2A1B/;#<UEFD4><dead_macron><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook>$/1D80/;#<UEFD4><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!breve>$/A791/;#<UEFD4><UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!breve><!breve>$/A790/;#<UEFD4><UEFD4><dead_breve><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group>$/1D8C/;#<UEFD4><UEFD4><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group>$/025A/;#<UEFD4><UEFD4><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group><!group>$/02A6/;#<UEFD4><UEFD4><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group><!group><!group>$/02AA/;#<UEFD4><UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><3>$/02A6/;#<UEFD4><UEFD4><UEFD0><3>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><4>$/02AA/;#<UEFD4><UEFD4><UEFD0><4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><5>$/02AB/;#<UEFD4><UEFD4><UEFD0><5>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!hook>$/0276/;#<UEFD4><UEFD4><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!retroflexhook>$/023F/;#<UEFD4><UEFD4><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!superscript>$/1DB5/;#<UEFD4><UEFD4><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!turned>$/2C79/;#<UEFD4><UEFD4><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!reversed>$/1D92/;#<UEFD4><UEFD6>
	$deadkey =~ s/^<!retroflexhook><!reversed><!group>$/1D8A/;#<UEFD4><UEFD6><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!reversed><!group><!group>$/1D9F/;#<UEFD4><UEFD6><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!superscript>$/1DBB/;#<UEFD4><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group>$/1DAF/;#<UEFD4><UEFD1><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group>$/1DB8/;#<UEFD4><UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group><!group>$/AB66/;#<UEFD4><UEFD1><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group><!group><!group>$/01C3/;#<UEFD4><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><3>$/AB66/;#<UEFD4><UEFD1><UEFD0><3>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><4>$/01C3/;#<UEFD4><UEFD1><UEFD0><4>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><5>$/01C2/;#<UEFD4><UEFD1><UEFD0><5>
	$deadkey =~ s/^<!retroflexhook><!superscript><!macron>$/AB64/;#<UEFD4><UEFD1><dead_macron>
	$deadkey =~ s/^<!retroflexhook><!superscript><!retroflexhook>$/1DAE/;#<UEFD4><UEFD1><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!turned>$/2C7B/;#<UEFD4><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!turned><!hook>$/02B6/;#<UEFD4><UEFD5><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!turned><!macron>$/0272/;#<UEFD4><UEFD5><dead_macron>
	$deadkey =~ s/^<!retroflexhook><!turned><!retroflexhook>$/2C7A/;#<UEFD4><UEFD5><UEFD4>
	$deadkey =~ s/^<!reversed><!bar>$/02A2/;#<UEFD6><UEFD8>
	$deadkey =~ s/^<!reversed><!doubleacute>$/263A/;#<UEFD6><dead_doubleacute>
	$deadkey =~ s/^<!reversed><!group>$/2B88/;#<UEFD6><UEFD0>
	$deadkey =~ s/^<!reversed><!group><!group>$/A7AB/;#<UEFD6><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!group><!group><!group>$/A7F6/;#<UEFD6><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!group><!group><!group><!group>$/A7F5/;#<UEFD6><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!group><2>$/01B8/;#<UEFD6><UEFD0><2>
	$deadkey =~ s/^<!reversed><!group><3>$/A7F6/;#<UEFD6><UEFD0><3>
	$deadkey =~ s/^<!reversed><!group><4>$/A7F5/;#<UEFD6><UEFD0><4>
	$deadkey =~ s/^<!reversed><!group><5>$/01B9/;#<UEFD6><UEFD0><5>
	$deadkey =~ s/^<!reversed><!hook>$/0259/;#<UEFD6><dead_hook>
	$deadkey =~ s/^<!reversed><!hook><!group>$/0258/;#<UEFD6><dead_hook><UEFD0>
	$deadkey =~ s/^<!reversed><!hook><!group><!group>$/0252/;#<UEFD6><dead_hook><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!retroflexhook>$/028B/;#<UEFD6><UEFD4>
	$deadkey =~ s/^<!reversed><!retroflexhook><!group>$/0290/;#<UEFD6><UEFD4><UEFD0>
	$deadkey =~ s/^<!reversed><!retroflexhook><!group><!group>$/0291/;#<UEFD6><UEFD4><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!subscript>$/1D0E/;#<UEFD6><UEFD2>
	$deadkey =~ s/^<!reversed><!superscript>$/02BD/;#<UEFD6><UEFD1>
	$deadkey =~ s/^<!reversed><!superscript><!group>$/1D32/;#<UEFD6><UEFD1><UEFD0>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group>$/1D9E/;#<UEFD6><UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group><!group>$/1D9C/;#<UEFD6><UEFD1><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group><!group><!group>$/1D9B/;#<UEFD6><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!reversed><!superscript><!group><3>$/1D9C/;#<UEFD6><UEFD1><UEFD0><3>
	$deadkey =~ s/^<!reversed><!superscript><!group><4>$/1D9B/;#<UEFD6><UEFD1><UEFD0><4>
	$deadkey =~ s/^<!reversed><!superscript><!group><5>$/1D9A/;#<UEFD6><UEFD1><UEFD0><5>
	$deadkey =~ s/^<!stroke><!acute>$/01FF/;#<dead_stroke><dead_acute>
	$deadkey =~ s/^<!stroke><!bar>$/A744/;#<dead_stroke><UEFD8>
	$deadkey =~ s/^<!stroke><!group>$/019B/;#<dead_stroke><UEFD0>
	$deadkey =~ s/^<!stroke><!group><!group>$/AB3F/;#<dead_stroke><UEFD0><UEFD0>
	$deadkey =~ s/^<!stroke><!group><!group><!group>$/1E9C/;#<dead_stroke><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!stroke><!group><!group><!group><!group>$/A7DC/;#<dead_stroke><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!stroke><!group><1>$/2270/;#<dead_stroke><UEFD0><1>
	$deadkey =~ s/^<!stroke><!group><2>$/2271/;#<dead_stroke><UEFD0><2>
	$deadkey =~ s/^<!stroke><!group><3>$/1E9C/;#<dead_stroke><UEFD0><3>
	$deadkey =~ s/^<!stroke><!group><4>$/A7DC/;#<dead_stroke><UEFD0><4>
	$deadkey =~ s/^<!stroke><!group><5>$/2262/;#<dead_stroke><UEFD0><5>
	$deadkey =~ s/^<!stroke><!stroke>$/A7A1/;#<dead_stroke><dead_stroke>
	$deadkey =~ s/^<!stroke><!stroke><!stroke>$/2425/;#<dead_stroke><dead_stroke><dead_stroke>
	$deadkey =~ s/^<!stroke><!subscript>$/1D7E/;#<dead_stroke><UEFD2>
	$deadkey =~ s/^<!stroke><!tilde>$/2241/;#<dead_stroke><dead_tilde>
	$deadkey =~ s/^<!stroke><!turned>$/0152/;#<dead_stroke><UEFD5>
	$deadkey =~ s/^<!stroke><!turned><!group>$/00E6/;#<dead_stroke><UEFD5><UEFD0>
	$deadkey =~ s/^<!stroke><!turned><!group><!group>$/00C6/;#<dead_stroke><UEFD5><UEFD0><UEFD0>
	$deadkey =~ s/^<!stroke><!turned><!group><!group><!group>$/A7F9/;#<dead_stroke><UEFD5><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!stroke><!turned><!group><3>$/A7F9/;#<dead_stroke><UEFD5><UEFD0><3>
	$deadkey =~ s/^<!stroke><!turned><!turned>$/1D14/;#<dead_stroke><UEFD5><UEFD5>
	$deadkey =~ s/^<!subscript><!bar>$/1D7B/;#<UEFD2><UEFD8>
	$deadkey =~ s/^<!subscript><!breve>$/029C/;#<UEFD2><dead_breve>
	$deadkey =~ s/^<!subscript><!breve><!breve>$/1DA7/;#<UEFD2><dead_breve><dead_breve>
	$deadkey =~ s/^<!subscript><!greek>$/1D69/;#<UEFD2><dead_greek>
	$deadkey =~ s/^<!subscript><!group>$/1D01/;#<UEFD2><UEFD0>
	$deadkey =~ s/^<!subscript><!group><!group>$/2094/;#<UEFD2><UEFD0><UEFD0>
	$deadkey =~ s/^<!subscript><!group><!group><!group>$/1D10/;#<UEFD2><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!subscript><!group><!group><!group><!group>$/1D2A/;#<UEFD2><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!subscript><!group><3>$/1D10/;#<UEFD2><UEFD0><3>
	$deadkey =~ s/^<!subscript><!group><4>$/1D2A/;#<UEFD2><UEFD0><4>
	$deadkey =~ s/^<!subscript><!group><6>$/1D27/;#<UEFD2><UEFD0><6>
	$deadkey =~ s/^<!subscript><!hook>$/AB46/;#<UEFD2><dead_hook>
	$deadkey =~ s/^<!subscript><!reversed>$/A71F/;#<UEFD2><UEFD6>
	$deadkey =~ s/^<!subscript><!stroke>$/1D0C/;#<UEFD2><dead_stroke>
	$deadkey =~ s/^<!subscript><!subscript>$/2017/;#<UEFD2><UEFD2>
	$deadkey =~ s/^<!subscript><!subscript><!turned>$/0292/;#<UEFD2><UEFD2><UEFD5>
	$deadkey =~ s/^<!subscript><!superscript>$/1DA6/;#<UEFD2><UEFD1>
	$deadkey =~ s/^<!subscript><!superscript><!group>$/1DB0/;#<UEFD2><UEFD1><UEFD0>
	$deadkey =~ s/^<!subscript><!turned>$/A7FA/;#<UEFD2><UEFD5>
	$deadkey =~ s/^<!subscript><!turned><!subscript>$/02CF/;#<UEFD2><UEFD5><UEFD2>
	$deadkey =~ s/^<!subscript><!turned><!turned>$/1D1A/;#<UEFD2><UEFD5><UEFD5>
	$deadkey =~ s/^<!superscript><!bar>$/A7F8/;#<UEFD1><UEFD8>
	$deadkey =~ s/^<!superscript><!bar><!group>$/1DB6/;#<UEFD1><UEFD8><UEFD0>
	$deadkey =~ s/^<!superscript><!breve>$/1DB1/;#<UEFD1><dead_breve>
	$deadkey =~ s/^<!superscript><!breve><!breve>$/1DB2/;#<UEFD1><dead_breve><dead_breve>
	$deadkey =~ s/^<!superscript><!diaeresis>$/00C4/;#<UEFD1><dead_diaeresis>
	$deadkey =~ s/^<!superscript><!diaeresis><!superscript>$/1D40/;#<UEFD1><dead_diaeresis><UEFD1>
	$deadkey =~ s/^<!superscript><!group>$/1D2D/;#<UEFD1><UEFD0>
	$deadkey =~ s/^<!superscript><!group><!group>$/1D5D/;#<UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!group><!group><!group>$/1D45/;#<UEFD1><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!group><!group><!group><!group>$/1D4A/;#<UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!group><3>$/1D45/;#<UEFD1><UEFD0><3>
	$deadkey =~ s/^<!superscript><!group><4>$/1D4A/;#<UEFD1><UEFD0><4>
	$deadkey =~ s/^<!superscript><!group><5>$/1DA2/;#<UEFD1><UEFD0><5>
	$deadkey =~ s/^<!superscript><!group><6>$/1D60/;#<UEFD1><UEFD0><6>
	$deadkey =~ s/^<!superscript><!hook>$/1DB3/;#<UEFD1><dead_hook>
	$deadkey =~ s/^<!superscript><!hook><!group>$/AB5F/;#<UEFD1><dead_hook><UEFD0>
	$deadkey =~ s/^<!superscript><!hook><!hook>$/1DB7/;#<UEFD1><dead_hook><dead_hook>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group>$/1DB4/;#<UEFD1><dead_hook><dead_hook><UEFD0>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group>$/1DA5/;#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group><!group>$/1DA4/;#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group><!group><!group>$/1DA3/;#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><3>$/1DA4/;#<UEFD1><dead_hook><dead_hook><UEFD0><3>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><4>$/1DA3/;#<UEFD1><dead_hook><dead_hook><UEFD0><4>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><5>$/1DA0/;#<UEFD1><dead_hook><dead_hook><UEFD0><5>
	$deadkey =~ s/^<!superscript><!hook><!turned>$/02AD/;#<UEFD1><dead_hook><UEFD5>
	$deadkey =~ s/^<!superscript><!macron>$/02E6/;#<UEFD1><dead_macron>
	$deadkey =~ s/^<!superscript><!macron><!retroflexhook>$/02AC/;#<UEFD1><dead_macron><UEFD4>
	$deadkey =~ s/^<!superscript><!macron><!turned>$/1D99/;#<UEFD1><dead_macron><UEFD5>
	$deadkey =~ s/^<!superscript><!retroflexhook>$/1D96/;#<UEFD1><UEFD4>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group>$/1D8E/;#<UEFD1><UEFD4><UEFD0>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group>$/1D8D/;#<UEFD1><UEFD4><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group><!group>$/1D89/;#<UEFD1><UEFD4><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group><!group><!group>$/1D88/;#<UEFD1><UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><3>$/1D89/;#<UEFD1><UEFD4><UEFD0><3>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><4>$/1D88/;#<UEFD1><UEFD4><UEFD0><4>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><5>$/1D87/;#<UEFD1><UEFD4><UEFD0><5>
	$deadkey =~ s/^<!superscript><!retroflexhook><!macron>$/1D86/;#<UEFD1><UEFD4><dead_macron>
	$deadkey =~ s/^<!superscript><!retroflexhook><!retroflexhook>$/1D84/;#<UEFD1><UEFD4><UEFD4>
	$deadkey =~ s/^<!superscript><!reversed>$/1D83/;#<UEFD1><UEFD6>
	$deadkey =~ s/^<!superscript><!reversed><!group>$/02E4/;#<UEFD1><UEFD6><UEFD0>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group>$/1D82/;#<UEFD1><UEFD6><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group><!group>$/1D81/;#<UEFD1><UEFD6><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group><!group><!group>$/1D7F/;#<UEFD1><UEFD6><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!reversed><!group><3>$/1D81/;#<UEFD1><UEFD6><UEFD0><3>
	$deadkey =~ s/^<!superscript><!reversed><!group><4>$/1D7F/;#<UEFD1><UEFD6><UEFD0><4>
	$deadkey =~ s/^<!superscript><!reversed><!group><5>$/1D7D/;#<UEFD1><UEFD6><UEFD0><5>
	$deadkey =~ s/^<!superscript><!subscript>$/1D7A/;#<UEFD1><UEFD2>
	$deadkey =~ s/^<!superscript><!subscript><!group>$/1D79/;#<UEFD1><UEFD2><UEFD0>
	$deadkey =~ s/^<!superscript><!superscript>$/FE4C/;#<UEFD1><UEFD1>
	$deadkey =~ s/^<!superscript><!superscript><!diaeresis>$/00D6/;#<UEFD1><UEFD1><dead_diaeresis>
	$deadkey =~ s/^<!superscript><!superscript><!group>$/1D78/;#<UEFD1><UEFD1><UEFD0>
	$deadkey =~ s/^<!superscript><!superscript><!group><!group>$/1D77/;#<UEFD1><UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!superscript><!group><2>$/1D76/;#<UEFD1><UEFD1><UEFD0><2>
	$deadkey =~ s/^<!superscript><!tilde>$/AB5E/;#<UEFD1><dead_tilde>
	$deadkey =~ s/^<!superscript><!turned>$/1D44/;#<UEFD1><UEFD5>
	$deadkey =~ s/^<!superscript><!turned><!group>$/1D46/;#<UEFD1><UEFD5><UEFD0>
	$deadkey =~ s/^<!superscript><!turned><!group><!group>$/1D4C/;#<UEFD1><UEFD5><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!turned><!group><!group><!group>$/1D5A/;#<UEFD1><UEFD5><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!superscript><!turned><!group><3>$/1D5A/;#<UEFD1><UEFD5><UEFD0><3>
	$deadkey =~ s/^<!superscript><!turned><!hook>$/02B9/;#<UEFD1><UEFD5><dead_hook>
	$deadkey =~ s/^<!superscript><!turned><!macron>$/02BA/;#<UEFD1><UEFD5><dead_macron>
	$deadkey =~ s/^<!superscript><!turned><!turned>$/A71E/;#<UEFD1><UEFD5><UEFD5>
	$deadkey =~ s/^<!tilde><!acute>$/1E4D/;#<dead_tilde><dead_acute>
	$deadkey =~ s/^<!tilde><!breve>$/1EB4/;#<dead_tilde><dead_breve>
	$deadkey =~ s/^<!tilde><!circumflex>$/1EAA/;#<dead_tilde><dead_circumflex>
	$deadkey =~ s/^<!tilde><!diaeresis>$/1E4F/;#<dead_tilde><dead_diaeresis>
	$deadkey =~ s/^<!tilde><!hook>$/1D72/;#<dead_tilde><dead_hook>
	$deadkey =~ s/^<!tilde><!horn>$/1EE0/;#<dead_tilde><dead_horn>
	$deadkey =~ s/^<!tilde><!macron>$/022D/;#<dead_tilde><dead_macron>
	$deadkey =~ s/^<!tilde><!stroke>$/2244/;#<dead_tilde><dead_stroke>
	$deadkey =~ s/^<!tilde><!superscript>$/2245/;#<dead_tilde><UEFD1>
	$deadkey =~ s/^<!tilde><!tilde>$/02F7/;#<dead_tilde><dead_tilde>
	$deadkey =~ s/^<!tilde><!tilde><!tilde>$/AB38/;#<dead_tilde><dead_tilde><dead_tilde>
	$deadkey =~ s/^<!tilde><!tilde><!turned>$/223F/;#<dead_tilde><dead_tilde><UEFD5>
	$deadkey =~ s/^<!tilde><!turned>$/223D/;#<dead_tilde><UEFD5>
	$deadkey =~ s/^<!tilde><!turned><!tilde>$/223C/;#<dead_tilde><UEFD5><dead_tilde>
	$deadkey =~ s/^<!tilde><%ampersand>$/25B3/;#<dead_tilde><ampersand>
	$deadkey =~ s/^<!turned><!bar>$/AB42/;#<UEFD5><UEFD8>
	$deadkey =~ s/^<!turned><!bar><!group>$/AB43/;#<UEFD5><UEFD8><UEFD0>
	$deadkey =~ s/^<!turned><!breve>$/AB45/;#<UEFD5><dead_breve>
	$deadkey =~ s/^<!turned><!breve><!breve>$/AB3B/;#<UEFD5><dead_breve><dead_breve>
	$deadkey =~ s/^<!turned><!diaeresis>$/1D1E/;#<UEFD5><dead_diaeresis>
	$deadkey =~ s/^<!turned><!diaeresis><!turned>$/00CB/;#<UEFD5><dead_diaeresis><UEFD5>
	$deadkey =~ s/^<!turned><!group>$/1D02/;#<UEFD5><UEFD0>
	$deadkey =~ s/^<!turned><!group><!group>$/2C70/;#<UEFD5><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!group><!group><!group>$/1D08/;#<UEFD5><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!group><!group><!group><!group>$/A77F/;#<UEFD5><UEFD0><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!group><1>$/2319/;#<UEFD5><UEFD0><1>
	$deadkey =~ s/^<!turned><!group><2>$/29A2/;#<UEFD5><UEFD0><2>
	$deadkey =~ s/^<!turned><!group><3>$/1D08/;#<UEFD5><UEFD0><3>
	$deadkey =~ s/^<!turned><!group><4>$/A77F/;#<UEFD5><UEFD0><4>
	$deadkey =~ s/^<!turned><!group><5>$/A77E/;#<UEFD5><UEFD0><5>
	$deadkey =~ s/^<!turned><!hook>$/027B/;#<UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!hook><!hook>$/AB39/;#<UEFD5><dead_hook><dead_hook>
	$deadkey =~ s/^<!turned><!hook><!hook><!turned>$/AB37/;#<UEFD5><dead_hook><dead_hook><UEFD5>
	$deadkey =~ s/^<!turned><!hook><!retroflexhook>$/AB35/;#<UEFD5><dead_hook><UEFD4>
	$deadkey =~ s/^<!turned><!hook><!superscript>$/AB4B/;#<UEFD5><dead_hook><UEFD1>
	$deadkey =~ s/^<!turned><!hook><!turned>$/AB4E/;#<UEFD5><dead_hook><UEFD5>
	$deadkey =~ s/^<!turned><!hook><!turned><!hook>$/AB4D/;#<UEFD5><dead_hook><UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!macron>$/AB4F/;#<UEFD5><dead_macron>
	$deadkey =~ s/^<!turned><!macron><!retroflexhook>$/AB50/;#<UEFD5><dead_macron><UEFD4>
	$deadkey =~ s/^<!turned><!macron><!superscript>$/AB51/;#<UEFD5><dead_macron><UEFD1>
	$deadkey =~ s/^<!turned><!retroflexhook>$/AB52/;#<UEFD5><UEFD4>
	$deadkey =~ s/^<!turned><!retroflexhook><!hook>$/AB5A/;#<UEFD5><UEFD4><dead_hook>
	$deadkey =~ s/^<!turned><!retroflexhook><!macron>$/AB5C/;#<UEFD5><UEFD4><dead_macron>
	$deadkey =~ s/^<!turned><!retroflexhook><!retroflexhook>$/AB5D/;#<UEFD5><UEFD4><UEFD4>
	$deadkey =~ s/^<!turned><!stroke>$/AB41/;#<UEFD5><dead_stroke>
	$deadkey =~ s/^<!turned><!stroke><!group>$/AB60/;#<UEFD5><dead_stroke><UEFD0>
	$deadkey =~ s/^<!turned><!stroke><!group><!group>$/AB61/;#<UEFD5><dead_stroke><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!stroke><!group><!group><!group>$/AB62/;#<UEFD5><dead_stroke><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!stroke><!group><3>$/AB62/;#<UEFD5><dead_stroke><UEFD0><3>
	$deadkey =~ s/^<!turned><!stroke><!turned>$/1D12/;#<UEFD5><dead_stroke><UEFD5>
	$deadkey =~ s/^<!turned><!subscript>$/AB63/;#<UEFD5><UEFD2>
	$deadkey =~ s/^<!turned><!subscript><!subscript>$/AB65/;#<UEFD5><UEFD2><UEFD2>
	$deadkey =~ s/^<!turned><!subscript><!turned>$/02BE/;#<UEFD5><UEFD2><UEFD5>
	$deadkey =~ s/^<!turned><!superscript>$/1D4E/;#<UEFD5><UEFD1>
	$deadkey =~ s/^<!turned><!superscript><!group>$/AB69/;#<UEFD5><UEFD1><UEFD0>
	$deadkey =~ s/^<!turned><!superscript><!group><!group>$/AB6A/;#<UEFD5><UEFD1><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!superscript><!group><!group><!group>$/AB6B/;#<UEFD5><UEFD1><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!superscript><!group><3>$/AB6B/;#<UEFD5><UEFD1><UEFD0><3>
	$deadkey =~ s/^<!turned><!superscript><!hook>$/AB48/;#<UEFD5><UEFD1><dead_hook>
	$deadkey =~ s/^<!turned><!superscript><!macron>$/AB49/;#<UEFD5><UEFD1><dead_macron>
	$deadkey =~ s/^<!turned><!superscript><!turned>$/AB31/;#<UEFD5><UEFD1><UEFD5>
	$deadkey =~ s/^<!turned><!tilde>$/AB68/;#<UEFD5><dead_tilde>
	$deadkey =~ s/^<!turned><!tilde><!tilde>$/2240/;#<UEFD5><dead_tilde><dead_tilde>
	$deadkey =~ s/^<!turned><!turned>$/A7FD/;#<UEFD5><UEFD5>
	$deadkey =~ s/^<!turned><!turned><!diaeresis>$/1D1F/;#<UEFD5><UEFD5><dead_diaeresis>
	$deadkey =~ s/^<!turned><!turned><!group>$/1D11/;#<UEFD5><UEFD5><UEFD0>
	$deadkey =~ s/^<!turned><!turned><!group><!group>$/223E/;#<UEFD5><UEFD5><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!turned><!group><!group><!group>$/1D1D/;#<UEFD5><UEFD5><UEFD0><UEFD0><UEFD0>
	$deadkey =~ s/^<!turned><!turned><!group><3>$/1D1D/;#<UEFD5><UEFD5><UEFD0><3>
	$deadkey =~ s/^<!turned><!turned><!hook>$/AB34/;#<UEFD5><UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!turned><!hook><!hook>$/AB40/;#<UEFD5><UEFD5><dead_hook><dead_hook>
	$deadkey =~ s/^<!turned><!turned><!stroke>$/1D13/;#<UEFD5><UEFD5><dead_stroke>
	$deadkey =~ s/^<!turned><!turned><!subscript>$/0298/;#<UEFD5><UEFD5><UEFD2>
	$deadkey =~ s/^<!turned><!turned><!superscript>$/1D59/;#<UEFD5><UEFD5><UEFD1>

	# Polytonic and monotonic Greek (256).
	$deadkey =~ s/^<!abovehook><!greek>$/1FBD/;#<UEFD3><dead_greek>
	$deadkey =~ s/^<!acute><!belowdot><!breve><!greek>$/1F84/;#<dead_acute><dead_belowdot><dead_breve><dead_greek>
	$deadkey =~ s/^<!acute><!belowdot><!greek>$/1FB4/;#<dead_acute><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!acute><!belowdot><!greek><!breve>$/1F8C/;#<dead_acute><dead_belowdot><dead_greek><dead_breve>
	$deadkey =~ s/^<!acute><!belowdot><!greek><!invertedbreve>$/1F8D/;#<dead_acute><dead_belowdot><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!acute><!belowdot><!invertedbreve><!greek>$/1F85/;#<dead_acute><dead_belowdot><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!acute><!breve><!belowdot><!greek>$/1F9C/;#<dead_acute><dead_breve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!acute><!breve><!greek>$/1FCE/;#<dead_acute><dead_breve><dead_greek>
	$deadkey =~ s/^<!acute><!breve><!greek><!belowdot>$/1F94/;#<dead_acute><dead_breve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!acute><!diaeresis><!greek>$/1FEE/;#<dead_acute><dead_diaeresis><dead_greek>
	$deadkey =~ s/^<!acute><!greek>$/1FFD/;#<dead_acute><dead_greek>
	$deadkey =~ s/^<!acute><!greek><!belowdot>$/1FC4/;#<dead_acute><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!acute><!greek><!belowdot><!breve>$/1FAC/;#<dead_acute><dead_greek><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!acute><!greek><!belowdot><!invertedbreve>$/1F9D/;#<dead_acute><dead_greek><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!acute><!greek><!breve>$/1F0C/;#<dead_acute><dead_greek><dead_breve>
	$deadkey =~ s/^<!acute><!greek><!breve><!belowdot>$/1FA4/;#<dead_acute><dead_greek><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!acute><!greek><!diaeresis>$/1FD3/;#<dead_acute><dead_greek><dead_diaeresis>
	$deadkey =~ s/^<!acute><!greek><!invertedbreve>$/1FDE/;#<dead_acute><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!acute><!greek><!invertedbreve><!belowdot>$/1F95/;#<dead_acute><dead_greek><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!acute><!invertedbreve><!belowdot><!greek>$/1FAD/;#<dead_acute><dead_invertedbreve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!acute><!invertedbreve><!greek>$/1F0D/;#<dead_acute><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!acute><!invertedbreve><!greek><!belowdot>$/1FA5/;#<dead_acute><dead_invertedbreve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!belowdot><!acute><!breve><!greek>$/1FCF/;#<dead_belowdot><dead_acute><dead_breve><dead_greek>
	$deadkey =~ s/^<!belowdot><!acute><!greek>$/1FF4/;#<dead_belowdot><dead_acute><dead_greek>
	$deadkey =~ s/^<!belowdot><!acute><!greek><!breve>$/1F0E/;#<dead_belowdot><dead_acute><dead_greek><dead_breve>
	$deadkey =~ s/^<!belowdot><!acute><!greek><!invertedbreve>$/1FDF/;#<dead_belowdot><dead_acute><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!acute><!invertedbreve><!greek>$/1F0F/;#<dead_belowdot><dead_acute><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!belowdot><!breve><!acute><!greek>$/1F06/;#<dead_belowdot><dead_breve><dead_acute><dead_greek>
	$deadkey =~ s/^<!belowdot><!breve><!circumflex><!greek>$/1F8E/;#<dead_belowdot><dead_breve><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!belowdot><!breve><!grave><!greek>$/1F8A/;#<dead_belowdot><dead_breve><dead_grave><dead_greek>
	$deadkey =~ s/^<!belowdot><!breve><!greek>$/1F88/;#<dead_belowdot><dead_breve><dead_greek>
	$deadkey =~ s/^<!belowdot><!breve><!greek><!acute>$/1F2E/;#<dead_belowdot><dead_breve><dead_greek><dead_acute>
	$deadkey =~ s/^<!belowdot><!breve><!greek><!circumflex>$/1F86/;#<dead_belowdot><dead_breve><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!breve><!greek><!grave>$/1F82/;#<dead_belowdot><dead_breve><dead_greek><dead_grave>
	$deadkey =~ s/^<!belowdot><!circumflex><!breve><!greek>$/1F9E/;#<dead_belowdot><dead_circumflex><dead_breve><dead_greek>
	$deadkey =~ s/^<!belowdot><!circumflex><!greek>$/1FB7/;#<dead_belowdot><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!belowdot><!circumflex><!greek><!breve>$/1F96/;#<dead_belowdot><dead_circumflex><dead_greek><dead_breve>
	$deadkey =~ s/^<!belowdot><!circumflex><!greek><!invertedbreve>$/1F8F/;#<dead_belowdot><dead_circumflex><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!circumflex><!invertedbreve><!greek>$/1F87/;#<dead_belowdot><dead_circumflex><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!belowdot><!grave><!breve><!greek>$/1F9A/;#<dead_belowdot><dead_grave><dead_breve><dead_greek>
	$deadkey =~ s/^<!belowdot><!grave><!greek>$/1FB2/;#<dead_belowdot><dead_grave><dead_greek>
	$deadkey =~ s/^<!belowdot><!grave><!greek><!breve>$/1F92/;#<dead_belowdot><dead_grave><dead_greek><dead_breve>
	$deadkey =~ s/^<!belowdot><!grave><!greek><!invertedbreve>$/1F8B/;#<dead_belowdot><dead_grave><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!grave><!invertedbreve><!greek>$/1F83/;#<dead_belowdot><dead_grave><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!belowdot><!greek>$/037A/;#<dead_belowdot><dead_greek>
	$deadkey =~ s/^<!belowdot><!greek><!acute>$/1FFE/;#<dead_belowdot><dead_greek><dead_acute>
	$deadkey =~ s/^<!belowdot><!greek><!acute><!breve>$/1F26/;#<dead_belowdot><dead_greek><dead_acute><dead_breve>
	$deadkey =~ s/^<!belowdot><!greek><!acute><!invertedbreve>$/1F07/;#<dead_belowdot><dead_greek><dead_acute><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!greek><!breve>$/1F80/;#<dead_belowdot><dead_greek><dead_breve>
	$deadkey =~ s/^<!belowdot><!greek><!breve><!acute>$/1F3E/;#<dead_belowdot><dead_greek><dead_breve><dead_acute>
	$deadkey =~ s/^<!belowdot><!greek><!breve><!circumflex>$/1FAE/;#<dead_belowdot><dead_greek><dead_breve><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!greek><!breve><!grave>$/1FAA/;#<dead_belowdot><dead_greek><dead_breve><dead_grave>
	$deadkey =~ s/^<!belowdot><!greek><!circumflex>$/1FC7/;#<dead_belowdot><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!greek><!circumflex><!breve>$/1FA6/;#<dead_belowdot><dead_greek><dead_circumflex><dead_breve>
	$deadkey =~ s/^<!belowdot><!greek><!circumflex><!invertedbreve>$/1F9F/;#<dead_belowdot><dead_greek><dead_circumflex><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!greek><!grave>$/1FC2/;#<dead_belowdot><dead_greek><dead_grave>
	$deadkey =~ s/^<!belowdot><!greek><!grave><!breve>$/1FA2/;#<dead_belowdot><dead_greek><dead_grave><dead_breve>
	$deadkey =~ s/^<!belowdot><!greek><!grave><!invertedbreve>$/1F9B/;#<dead_belowdot><dead_greek><dead_grave><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!greek><!invertedbreve>$/1F89/;#<dead_belowdot><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!belowdot><!greek><!invertedbreve><!acute>$/1F2F/;#<dead_belowdot><dead_greek><dead_invertedbreve><dead_acute>
	$deadkey =~ s/^<!belowdot><!greek><!invertedbreve><!circumflex>$/1F97/;#<dead_belowdot><dead_greek><dead_invertedbreve><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!greek><!invertedbreve><!grave>$/1F93/;#<dead_belowdot><dead_greek><dead_invertedbreve><dead_grave>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!acute><!greek>$/1F27/;#<dead_belowdot><dead_invertedbreve><dead_acute><dead_greek>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!circumflex><!greek>$/1FAF/;#<dead_belowdot><dead_invertedbreve><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!grave><!greek>$/1FAB/;#<dead_belowdot><dead_invertedbreve><dead_grave><dead_greek>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!greek>$/1F81/;#<dead_belowdot><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!greek><!acute>$/1F3F/;#<dead_belowdot><dead_invertedbreve><dead_greek><dead_acute>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!greek><!circumflex>$/1FA7/;#<dead_belowdot><dead_invertedbreve><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!invertedbreve><!greek><!grave>$/1FA3/;#<dead_belowdot><dead_invertedbreve><dead_greek><dead_grave>
	$deadkey =~ s/^<!breve><!acute><!belowdot><!greek>$/1F36/;#<dead_breve><dead_acute><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!breve><!acute><!greek>$/1F04/;#<dead_breve><dead_acute><dead_greek>
	$deadkey =~ s/^<!breve><!acute><!greek><!belowdot>$/1F6E/;#<dead_breve><dead_acute><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!breve><!belowdot><!acute><!greek>$/1F66/;#<dead_breve><dead_belowdot><dead_acute><dead_greek>
	$deadkey =~ s/^<!breve><!belowdot><!circumflex><!greek>$/1FCD/;#<dead_breve><dead_belowdot><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!breve><!belowdot><!grave><!greek>$/1F98/;#<dead_breve><dead_belowdot><dead_grave><dead_greek>
	$deadkey =~ s/^<!breve><!belowdot><!greek>$/1F90/;#<dead_breve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!breve><!belowdot><!greek><!acute>$/1F56/;#<dead_breve><dead_belowdot><dead_greek><dead_acute>
	$deadkey =~ s/^<!breve><!belowdot><!greek><!circumflex>$/1F0A/;#<dead_breve><dead_belowdot><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!breve><!belowdot><!greek><!grave>$/1FA8/;#<dead_breve><dead_belowdot><dead_greek><dead_grave>
	$deadkey =~ s/^<!breve><!circumflex><!belowdot><!greek>$/1F02/;#<dead_breve><dead_circumflex><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!breve><!circumflex><!greek>$/1F1A/;#<dead_breve><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!breve><!circumflex><!greek><!belowdot>$/1F12/;#<dead_breve><dead_circumflex><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!breve><!grave><!belowdot><!greek>$/1FA0/;#<dead_breve><dead_grave><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!breve><!grave><!greek>$/1F2A/;#<dead_breve><dead_grave><dead_greek>
	$deadkey =~ s/^<!breve><!grave><!greek><!belowdot>$/00AF/;#<dead_breve><dead_grave><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!breve><!greek>$/1FBF/;#<dead_breve><dead_greek>
	$deadkey =~ s/^<!breve><!greek><!acute>$/1F1C/;#<dead_breve><dead_greek><dead_acute>
	$deadkey =~ s/^<!breve><!greek><!acute><!belowdot>$/1F22/;#<dead_breve><dead_greek><dead_acute><dead_belowdot>
	$deadkey =~ s/^<!breve><!greek><!belowdot>$/1F43/;#<dead_breve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!breve><!greek><!belowdot><!acute>$/1F3A/;#<dead_breve><dead_greek><dead_belowdot><dead_acute>
	$deadkey =~ s/^<!breve><!greek><!belowdot><!circumflex>$/1F32/;#<dead_breve><dead_greek><dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!breve><!greek><!belowdot><!grave>$/1FB1/;#<dead_breve><dead_greek><dead_belowdot><dead_grave>
	$deadkey =~ s/^<!breve><!greek><!circumflex>$/1F4A/;#<dead_breve><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!breve><!greek><!circumflex><!belowdot>$/1F42/;#<dead_breve><dead_greek><dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!breve><!greek><!grave>$/1F6A/;#<dead_breve><dead_greek><dead_grave>
	$deadkey =~ s/^<!breve><!greek><!grave><!belowdot>$/1FD9/;#<dead_breve><dead_greek><dead_grave><dead_belowdot>
	$deadkey =~ s/^<!caron><!greek>$/1FB8/;#<dead_caron><dead_greek>
	$deadkey =~ s/^<!circumflex><!belowdot><!breve><!greek>$/1FB0/;#<dead_circumflex><dead_belowdot><dead_breve><dead_greek>
	$deadkey =~ s/^<!circumflex><!belowdot><!greek>$/1FF7/;#<dead_circumflex><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!circumflex><!belowdot><!greek><!breve>$/1FD8/;#<dead_circumflex><dead_belowdot><dead_greek><dead_breve>
	$deadkey =~ s/^<!circumflex><!belowdot><!greek><!invertedbreve>$/1FD0/;#<dead_circumflex><dead_belowdot><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!circumflex><!belowdot><!invertedbreve><!greek>$/1FE8/;#<dead_circumflex><dead_belowdot><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!circumflex><!breve><!belowdot><!greek>$/1FE0/;#<dead_circumflex><dead_breve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!circumflex><!breve><!greek>$/1FFC/;#<dead_circumflex><dead_breve><dead_greek>
	$deadkey =~ s/^<!circumflex><!breve><!greek><!belowdot>$/1FFB/;#<dead_circumflex><dead_breve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!diaeresis><!greek>$/1FC1/;#<dead_circumflex><dead_diaeresis><dead_greek>
	$deadkey =~ s/^<!circumflex><!greek>$/1FC0/;#<dead_circumflex><dead_greek>
	$deadkey =~ s/^<!circumflex><!greek><!belowdot>$/1FFA/;#<dead_circumflex><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!greek><!belowdot><!breve>$/1FF9/;#<dead_circumflex><dead_greek><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!circumflex><!greek><!belowdot><!invertedbreve>$/1FF8/;#<dead_circumflex><dead_greek><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!circumflex><!greek><!breve>$/1FF6/;#<dead_circumflex><dead_greek><dead_breve>
	$deadkey =~ s/^<!circumflex><!greek><!breve><!belowdot>$/1FF3/;#<dead_circumflex><dead_greek><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!greek><!diaeresis>$/1FD7/;#<dead_circumflex><dead_greek><dead_diaeresis>
	$deadkey =~ s/^<!circumflex><!greek><!invertedbreve>$/1F37/;#<dead_circumflex><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!circumflex><!greek><!invertedbreve><!belowdot>$/1FF2/;#<dead_circumflex><dead_greek><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!invertedbreve><!belowdot><!greek>$/1FEF/;#<dead_circumflex><dead_invertedbreve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!circumflex><!invertedbreve><!greek>$/1F6F/;#<dead_circumflex><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!circumflex><!invertedbreve><!greek><!belowdot>$/1FED/;#<dead_circumflex><dead_invertedbreve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!diaeresis><!acute><!greek>$/1FE3/;#<dead_diaeresis><dead_acute><dead_greek>
	$deadkey =~ s/^<!diaeresis><!circumflex><!greek>$/1FE7/;#<dead_diaeresis><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!diaeresis><!doubleacute><!greek>$/0344/;#<dead_diaeresis><dead_doubleacute><dead_greek>
	$deadkey =~ s/^<!diaeresis><!grave><!greek>$/1FD2/;#<dead_diaeresis><dead_grave><dead_greek>
	$deadkey =~ s/^<!diaeresis><!greek>$/03AA/;#<dead_diaeresis><dead_greek>
	$deadkey =~ s/^<!diaeresis><!greek><!acute>$/1FEC/;#<dead_diaeresis><dead_greek><dead_acute>
	$deadkey =~ s/^<!diaeresis><!greek><!circumflex>$/1FEB/;#<dead_diaeresis><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!diaeresis><!greek><!doubleacute>$/0385/;#<dead_diaeresis><dead_greek><dead_doubleacute>
	$deadkey =~ s/^<!diaeresis><!greek><!grave>$/1FE2/;#<dead_diaeresis><dead_greek><dead_grave>
	$deadkey =~ s/^<!doubleacute><!diaeresis><!greek>$/0390/;#<dead_doubleacute><dead_diaeresis><dead_greek>
	$deadkey =~ s/^<!doubleacute><!greek>$/0384/;#<dead_doubleacute><dead_greek>
	$deadkey =~ s/^<!doubleacute><!greek><!diaeresis>$/03B0/;#<dead_doubleacute><dead_greek><dead_diaeresis>
	$deadkey =~ s/^<!grave><!belowdot><!breve><!greek>$/1FEA/;#<dead_grave><dead_belowdot><dead_breve><dead_greek>
	$deadkey =~ s/^<!grave><!belowdot><!greek>$/1FE9/;#<dead_grave><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!grave><!belowdot><!greek><!breve>$/1FE6/;#<dead_grave><dead_belowdot><dead_greek><dead_breve>
	$deadkey =~ s/^<!grave><!belowdot><!greek><!invertedbreve>$/1FE5/;#<dead_grave><dead_belowdot><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!grave><!belowdot><!invertedbreve><!greek>$/1FE4/;#<dead_grave><dead_belowdot><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!grave><!breve><!belowdot><!greek>$/1FE1/;#<dead_grave><dead_breve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!grave><!breve><!greek>$/1F62/;#<dead_grave><dead_breve><dead_greek>
	$deadkey =~ s/^<!grave><!breve><!greek><!belowdot>$/1FDD/;#<dead_grave><dead_breve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!grave><!diaeresis><!greek>$/1FDB/;#<dead_grave><dead_diaeresis><dead_greek>
	$deadkey =~ s/^<!grave><!greek>$/1FBA/;#<dead_grave><dead_greek>
	$deadkey =~ s/^<!grave><!greek><!belowdot>$/1F5B/;#<dead_grave><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!grave><!greek><!belowdot><!breve>$/1F72/;#<dead_grave><dead_greek><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!grave><!greek><!belowdot><!invertedbreve>$/1F74/;#<dead_grave><dead_greek><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!grave><!greek><!breve>$/1F52/;#<dead_grave><dead_greek><dead_breve>
	$deadkey =~ s/^<!grave><!greek><!breve><!belowdot>$/1F76/;#<dead_grave><dead_greek><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!grave><!greek><!diaeresis>$/1F78/;#<dead_grave><dead_greek><dead_diaeresis>
	$deadkey =~ s/^<!grave><!greek><!invertedbreve>$/1F0B/;#<dead_grave><dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!grave><!greek><!invertedbreve><!belowdot>$/1F7A/;#<dead_grave><dead_greek><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!grave><!invertedbreve><!belowdot><!greek>$/1F7C/;#<dead_grave><dead_invertedbreve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!grave><!invertedbreve><!greek>$/1F03/;#<dead_grave><dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!grave><!invertedbreve><!greek><!belowdot>$/1FC8/;#<dead_grave><dead_invertedbreve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!greek><!abovehook>$/1FDA/;#<dead_greek><UEFD3>
	$deadkey =~ s/^<!greek><!acute>$/1FBB/;#<dead_greek><dead_acute>
	$deadkey =~ s/^<!greek><!acute><!belowdot>$/1F71/;#<dead_greek><dead_acute><dead_belowdot>
	$deadkey =~ s/^<!greek><!acute><!belowdot><!breve>$/1F73/;#<dead_greek><dead_acute><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!greek><!acute><!belowdot><!invertedbreve>$/1F75/;#<dead_greek><dead_acute><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!acute><!breve>$/1F14/;#<dead_greek><dead_acute><dead_breve>
	$deadkey =~ s/^<!greek><!acute><!breve><!belowdot>$/1F2C/;#<dead_greek><dead_acute><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!greek><!acute><!diaeresis>$/1F77/;#<dead_greek><dead_acute><dead_diaeresis>
	$deadkey =~ s/^<!greek><!acute><!invertedbreve>$/1F05/;#<dead_greek><dead_acute><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!acute><!invertedbreve><!belowdot>$/1F15/;#<dead_greek><dead_acute><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!greek><!belowdot>$/1FBE/;#<dead_greek><dead_belowdot>
	$deadkey =~ s/^<!greek><!belowdot><!acute>$/1F79/;#<dead_greek><dead_belowdot><dead_acute>
	$deadkey =~ s/^<!greek><!belowdot><!acute><!breve>$/1F7B/;#<dead_greek><dead_belowdot><dead_acute><dead_breve>
	$deadkey =~ s/^<!greek><!belowdot><!acute><!invertedbreve>$/1F7D/;#<dead_greek><dead_belowdot><dead_acute><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!belowdot><!breve>$/1FC3/;#<dead_greek><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!greek><!belowdot><!breve><!acute>$/1FC9/;#<dead_greek><dead_belowdot><dead_breve><dead_acute>
	$deadkey =~ s/^<!greek><!belowdot><!breve><!circumflex>$/1FD6/;#<dead_greek><dead_belowdot><dead_breve><dead_circumflex>
	$deadkey =~ s/^<!greek><!belowdot><!breve><!grave>$/1FCA/;#<dead_greek><dead_belowdot><dead_breve><dead_grave>
	$deadkey =~ s/^<!greek><!belowdot><!circumflex>$/1F1D/;#<dead_greek><dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!greek><!belowdot><!circumflex><!breve>$/1F25/;#<dead_greek><dead_belowdot><dead_circumflex><dead_breve>
	$deadkey =~ s/^<!greek><!belowdot><!circumflex><!invertedbreve>$/1F65/;#<dead_greek><dead_belowdot><dead_circumflex><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!belowdot><!grave>$/1F53/;#<dead_greek><dead_belowdot><dead_grave>
	$deadkey =~ s/^<!greek><!belowdot><!grave><!breve>$/1F6D/;#<dead_greek><dead_belowdot><dead_grave><dead_breve>
	$deadkey =~ s/^<!greek><!belowdot><!grave><!invertedbreve>$/1FD1/;#<dead_greek><dead_belowdot><dead_grave><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!belowdot><!invertedbreve>$/1F99/;#<dead_greek><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!belowdot><!invertedbreve><!acute>$/1FCC/;#<dead_greek><dead_belowdot><dead_invertedbreve><dead_acute>
	$deadkey =~ s/^<!greek><!belowdot><!invertedbreve><!circumflex>$/1FCB/;#<dead_greek><dead_belowdot><dead_invertedbreve><dead_circumflex>
	$deadkey =~ s/^<!greek><!belowdot><!invertedbreve><!grave>$/1FC6/;#<dead_greek><dead_belowdot><dead_invertedbreve><dead_grave>
	$deadkey =~ s/^<!greek><!breve>$/1F08/;#<dead_greek><dead_breve>
	$deadkey =~ s/^<!greek><!breve><!acute>$/1F24/;#<dead_greek><dead_breve><dead_acute>
	$deadkey =~ s/^<!greek><!breve><!acute><!belowdot>$/1F34/;#<dead_greek><dead_breve><dead_acute><dead_belowdot>
	$deadkey =~ s/^<!greek><!breve><!belowdot>$/1F00/;#<dead_greek><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!greek><!breve><!belowdot><!acute>$/1F3C/;#<dead_greek><dead_breve><dead_belowdot><dead_acute>
	$deadkey =~ s/^<!greek><!breve><!belowdot><!circumflex>$/1F10/;#<dead_greek><dead_breve><dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!greek><!breve><!belowdot><!grave>$/1F18/;#<dead_greek><dead_breve><dead_belowdot><dead_grave>
	$deadkey =~ s/^<!greek><!breve><!circumflex>$/03CE/;#<dead_greek><dead_breve><dead_circumflex>
	$deadkey =~ s/^<!greek><!breve><!circumflex><!belowdot>$/1F20/;#<dead_greek><dead_breve><dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!greek><!breve><!grave>$/1F28/;#<dead_greek><dead_breve><dead_grave>
	$deadkey =~ s/^<!greek><!breve><!grave><!belowdot>$/1F30/;#<dead_greek><dead_breve><dead_grave><dead_belowdot>
	$deadkey =~ s/^<!greek><!caron>$/1F50/;#<dead_greek><dead_caron>
	$deadkey =~ s/^<!greek><!circumflex>$/1FB6/;#<dead_greek><dead_circumflex>
	$deadkey =~ s/^<!greek><!circumflex><!belowdot>$/1F60/;#<dead_greek><dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!greek><!circumflex><!belowdot><!breve>$/1F38/;#<dead_greek><dead_circumflex><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!greek><!circumflex><!belowdot><!invertedbreve>$/1FBC/;#<dead_greek><dead_circumflex><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!circumflex><!breve>$/1F40/;#<dead_greek><dead_circumflex><dead_breve>
	$deadkey =~ s/^<!greek><!circumflex><!breve><!belowdot>$/1F48/;#<dead_greek><dead_circumflex><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!greek><!circumflex><!diaeresis>$/03AB/;#<dead_greek><dead_circumflex><dead_diaeresis>
	$deadkey =~ s/^<!greek><!circumflex><!invertedbreve>$/1F67/;#<dead_greek><dead_circumflex><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!circumflex><!invertedbreve><!belowdot>$/1FB3/;#<dead_greek><dead_circumflex><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!greek><!diaeresis>$/03CA/;#<dead_greek><dead_diaeresis>
	$deadkey =~ s/^<!greek><!diaeresis><!acute>$/03CB/;#<dead_greek><dead_diaeresis><dead_acute>
	$deadkey =~ s/^<!greek><!diaeresis><!circumflex>$/1F44/;#<dead_greek><dead_diaeresis><dead_circumflex>
	$deadkey =~ s/^<!greek><!diaeresis><!doubleacute>$/1F4C/;#<dead_greek><dead_diaeresis><dead_doubleacute>
	$deadkey =~ s/^<!greek><!diaeresis><!grave>$/1F54/;#<dead_greek><dead_diaeresis><dead_grave>
	$deadkey =~ s/^<!greek><!doubleacute>$/0386/;#<dead_greek><dead_doubleacute>
	$deadkey =~ s/^<!greek><!doubleacute><!diaeresis>$/0388/;#<dead_greek><dead_doubleacute><dead_diaeresis>
	$deadkey =~ s/^<!greek><!grave>$/1F70/;#<dead_greek><dead_grave>
	$deadkey =~ s/^<!greek><!grave><!belowdot>$/1FA9/;#<dead_greek><dead_grave><dead_belowdot>
	$deadkey =~ s/^<!greek><!grave><!belowdot><!breve>$/1F68/;#<dead_greek><dead_grave><dead_belowdot><dead_breve>
	$deadkey =~ s/^<!greek><!grave><!belowdot><!invertedbreve>$/1FA1/;#<dead_greek><dead_grave><dead_belowdot><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!grave><!breve>$/1F91/;#<dead_greek><dead_grave><dead_breve>
	$deadkey =~ s/^<!greek><!grave><!breve><!belowdot>$/1F6C/;#<dead_greek><dead_grave><dead_breve><dead_belowdot>
	$deadkey =~ s/^<!greek><!grave><!diaeresis>$/1F6B/;#<dead_greek><dead_grave><dead_diaeresis>
	$deadkey =~ s/^<!greek><!grave><!invertedbreve>$/1F69/;#<dead_greek><dead_grave><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!grave><!invertedbreve><!belowdot>$/1F64/;#<dead_greek><dead_grave><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!greek><!invertedbreve>$/1F09/;#<dead_greek><dead_invertedbreve>
	$deadkey =~ s/^<!greek><!invertedbreve><!acute>$/03AF/;#<dead_greek><dead_invertedbreve><dead_acute>
	$deadkey =~ s/^<!greek><!invertedbreve><!acute><!belowdot>$/03CC/;#<dead_greek><dead_invertedbreve><dead_acute><dead_belowdot>
	$deadkey =~ s/^<!greek><!invertedbreve><!belowdot>$/1F35/;#<dead_greek><dead_invertedbreve><dead_belowdot>
	$deadkey =~ s/^<!greek><!invertedbreve><!belowdot><!acute>$/03CD/;#<dead_greek><dead_invertedbreve><dead_belowdot><dead_acute>
	$deadkey =~ s/^<!greek><!invertedbreve><!belowdot><!circumflex>$/1F11/;#<dead_greek><dead_invertedbreve><dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!greek><!invertedbreve><!belowdot><!grave>$/1F19/;#<dead_greek><dead_invertedbreve><dead_belowdot><dead_grave>
	$deadkey =~ s/^<!greek><!invertedbreve><!circumflex>$/1F5F/;#<dead_greek><dead_invertedbreve><dead_circumflex>
	$deadkey =~ s/^<!greek><!invertedbreve><!circumflex><!belowdot>$/1F57/;#<dead_greek><dead_invertedbreve><dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!greek><!invertedbreve><!grave>$/1F21/;#<dead_greek><dead_invertedbreve><dead_grave>
	$deadkey =~ s/^<!greek><!invertedbreve><!grave><!belowdot>$/1F29/;#<dead_greek><dead_invertedbreve><dead_grave><dead_belowdot>
	$deadkey =~ s/^<!greek><!macron>$/1FB9/;#<dead_greek><dead_macron>
	$deadkey =~ s/^<!invertedbreve><!acute><!belowdot><!greek>$/0389/;#<dead_invertedbreve><dead_acute><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!acute><!greek>$/038A/;#<dead_invertedbreve><dead_acute><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!acute><!greek><!belowdot>$/038C/;#<dead_invertedbreve><dead_acute><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!acute><!greek>$/038E/;#<dead_invertedbreve><dead_belowdot><dead_acute><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!circumflex><!greek>$/1F31/;#<dead_invertedbreve><dead_belowdot><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!grave><!greek>$/1F39/;#<dead_invertedbreve><dead_belowdot><dead_grave><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!greek>$/1F41/;#<dead_invertedbreve><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!greek><!acute>$/038F/;#<dead_invertedbreve><dead_belowdot><dead_greek><dead_acute>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!greek><!circumflex>$/1F49/;#<dead_invertedbreve><dead_belowdot><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!invertedbreve><!belowdot><!greek><!grave>$/1F51/;#<dead_invertedbreve><dead_belowdot><dead_greek><dead_grave>
	$deadkey =~ s/^<!invertedbreve><!circumflex><!belowdot><!greek>$/1F59/;#<dead_invertedbreve><dead_circumflex><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!circumflex><!greek>$/1F61/;#<dead_invertedbreve><dead_circumflex><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!circumflex><!greek><!belowdot>$/1F4D/;#<dead_invertedbreve><dead_circumflex><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!grave><!belowdot><!greek>$/1F4B/;#<dead_invertedbreve><dead_grave><dead_belowdot><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!grave><!greek>$/1F45/;#<dead_invertedbreve><dead_grave><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!grave><!greek><!belowdot>$/1F63/;#<dead_invertedbreve><dead_grave><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!greek>$/1F01/;#<dead_invertedbreve><dead_greek>
	$deadkey =~ s/^<!invertedbreve><!greek><!acute>$/03AE/;#<dead_invertedbreve><dead_greek><dead_acute>
	$deadkey =~ s/^<!invertedbreve><!greek><!acute><!belowdot>$/03AC/;#<dead_invertedbreve><dead_greek><dead_acute><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!greek><!belowdot>$/1F13/;#<dead_invertedbreve><dead_greek><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!greek><!belowdot><!acute>$/03AD/;#<dead_invertedbreve><dead_greek><dead_belowdot><dead_acute>
	$deadkey =~ s/^<!invertedbreve><!greek><!belowdot><!circumflex>$/1F23/;#<dead_invertedbreve><dead_greek><dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!invertedbreve><!greek><!belowdot><!grave>$/1F2D/;#<dead_invertedbreve><dead_greek><dead_belowdot><dead_grave>
	$deadkey =~ s/^<!invertedbreve><!greek><!circumflex>$/1F2B/;#<dead_invertedbreve><dead_greek><dead_circumflex>
	$deadkey =~ s/^<!invertedbreve><!greek><!circumflex><!belowdot>$/1F33/;#<dead_invertedbreve><dead_greek><dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!invertedbreve><!greek><!grave>$/1F1B/;#<dead_invertedbreve><dead_greek><dead_grave>
	$deadkey =~ s/^<!invertedbreve><!greek><!grave><!belowdot>$/1F3B/;#<dead_invertedbreve><dead_greek><dead_grave><dead_belowdot>
	$deadkey =~ s/^<!macron><!greek>$/1F3D/;#<dead_macron><dead_greek>

	# Latin dead key chains for Greek (54).
	$deadkey =~ s/^<!acute><!belowdot><!breve>$/2500/;
	$deadkey =~ s/^<!acute><!belowdot>$/2501/;
	$deadkey =~ s/^<!acute><!belowdot><!invertedbreve>$/2502/;
	$deadkey =~ s/^<!acute><!breve><!belowdot>$/2503/;
	$deadkey =~ s/^<!acute><!invertedbreve><!belowdot>$/2504/;
	$deadkey =~ s/^<!acute><!invertedbreve>$/2505/;
	$deadkey =~ s/^<!belowdot><!acute><!breve>$/2506/;
	$deadkey =~ s/^<!belowdot><!acute>$/2507/;
	$deadkey =~ s/^<!belowdot><!acute><!invertedbreve>$/2508/;
	$deadkey =~ s/^<!belowdot><!breve><!acute>$/2509/;
	$deadkey =~ s/^<!belowdot><!breve><!circumflex>$/250A/;
	$deadkey =~ s/^<!belowdot><!breve><!grave>$/250B/;
	$deadkey =~ s/^<!belowdot><!circumflex><!breve>$/250C/;
	$deadkey =~ s/^<!belowdot><!circumflex><!invertedbreve>$/250D/;
	$deadkey =~ s/^<!belowdot><!grave><!breve>$/250E/;
	$deadkey =~ s/^<!belowdot><!grave>$/250F/;
	$deadkey =~ s/^<!belowdot><!grave><!invertedbreve>$/2510/;
	$deadkey =~ s/^<!belowdot><!invertedbreve><!acute>$/2511/;
	$deadkey =~ s/^<!belowdot><!invertedbreve><!circumflex>$/2512/;
	$deadkey =~ s/^<!belowdot><!invertedbreve><!grave>$/2513/;
	$deadkey =~ s/^<!belowdot><!invertedbreve>$/2514/;
	$deadkey =~ s/^<!breve><!acute><!belowdot>$/2515/;
	$deadkey =~ s/^<!breve><!belowdot><!acute>$/2516/;
	$deadkey =~ s/^<!breve><!belowdot><!circumflex>$/2517/;
	$deadkey =~ s/^<!breve><!belowdot><!grave>$/2518/;
	$deadkey =~ s/^<!breve><!circumflex><!belowdot>$/2519/;
	$deadkey =~ s/^<!breve><!circumflex>$/251A/;
	$deadkey =~ s/^<!breve><!grave><!belowdot>$/251B/;
	$deadkey =~ s/^<!circumflex><!belowdot><!breve>$/251C/;
	$deadkey =~ s/^<!circumflex><!belowdot><!invertedbreve>$/251D/;
	$deadkey =~ s/^<!circumflex><!breve><!belowdot>$/251E/;
	$deadkey =~ s/^<!circumflex><!breve>$/251F/;
	$deadkey =~ s/^<!circumflex><!diaeresis>$/2520/;
	$deadkey =~ s/^<!circumflex><!invertedbreve><!belowdot>$/2521/;
	$deadkey =~ s/^<!circumflex><!invertedbreve>$/2522/;
	$deadkey =~ s/^<!diaeresis><!circumflex>$/2523/;
	$deadkey =~ s/^<!diaeresis><!doubleacute>$/2524/;
	$deadkey =~ s/^<!doubleacute><!diaeresis>$/2525/;
	$deadkey =~ s/^<!grave><!belowdot><!breve>$/2526/;
	$deadkey =~ s/^<!grave><!belowdot>$/2527/;
	$deadkey =~ s/^<!grave><!belowdot><!invertedbreve>$/2528/;
	$deadkey =~ s/^<!grave><!breve><!belowdot>$/2529/;
	$deadkey =~ s/^<!grave><!invertedbreve><!belowdot>$/252A/;
	$deadkey =~ s/^<!grave><!invertedbreve>$/252B/;
	$deadkey =~ s/^<!invertedbreve><!acute><!belowdot>$/252C/;
	$deadkey =~ s/^<!invertedbreve><!acute>$/252D/;
	$deadkey =~ s/^<!invertedbreve><!belowdot><!acute>$/252E/;
	$deadkey =~ s/^<!invertedbreve><!belowdot><!circumflex>$/252F/;
	$deadkey =~ s/^<!invertedbreve><!belowdot><!grave>$/2530/;
	$deadkey =~ s/^<!invertedbreve><!belowdot>$/2531/;
	$deadkey =~ s/^<!invertedbreve><!circumflex><!belowdot>$/2532/;
	$deadkey =~ s/^<!invertedbreve><!circumflex>$/2533/;
	$deadkey =~ s/^<!invertedbreve><!grave><!belowdot>$/2534/;
	$deadkey =~ s/^<!invertedbreve><!grave>$/2535/;

	# Additional dead key chains (0).

	# When adding dead key chains, please make sure to add them in @chained, too.

	return $deadkey;
}

# Used to generate the required chained dead keys.
my @chained = (

	# Additional, 0.

	# Main set, 575.
	'<!abovedot><!abovedot>',
	'<!abovedot><!abovedot><!acute>',
	'<!abovedot><!abovedot><!acute><!grave>',
	'<!abovedot><!abovedot><!grave>',
	'<!abovedot><!abovedot><!grave><!acute>',
	'<!abovedot><!abovedot><!macron>',
	'<!abovedot><!acute>',
	'<!abovedot><!acute><!grave>',
	'<!abovedot><!bar>',
	'<!abovedot><!belowdot>',
	'<!abovedot><!breve>',
	'<!abovedot><!caron>',
	'<!abovedot><!grave>',
	'<!abovedot><!grave><!acute>',
	'<!abovedot><!group>',
	'<!abovedot><!group><!group>',
	'<!abovedot><!group><!group><!group>',
	'<!abovedot><!group><3>',
	'<!abovedot><!macron>',
	'<!abovehook><!abovehook>',
	'<!abovehook><!breve>',
	'<!abovehook><!circumflex>',
	'<!abovehook><!horn>',
	'<!abovering><!abovering>',
	'<!abovering><!acute>',
	'<!abovering><!currency>',
	'<!abovering><!diaeresis>',
	'<!abovering><!group>',
	'<!abovering><!group><!group>',
	'<!abovering><!group><!group><!group>',
	'<!abovering><!group><!group><!group><!group>',
	'<!abovering><!group><1>',
	'<!abovering><!group><2>',
	'<!abovering><!group><3>',
	'<!abovering><!group><4>',
	'<!abovering><!group><5>',
	'<!acute><!abovedot>',
	'<!acute><!abovedot><!abovedot>',
	'<!acute><!abovering>',
	'<!acute><!acute>',
	'<!acute><!breve>',
	'<!acute><!cedilla>',
	'<!acute><!circumflex>',
	'<!acute><!diaeresis>',
	'<!acute><!grave>',
	'<!acute><!grave><!macron>',
	'<!acute><!group>',
	'<!acute><!group><!group>',
	'<!acute><!horn>',
	'<!acute><!macron>',
	'<!acute><!macron><!grave>',
	'<!acute><!stroke>',
	'<!acute><!tilde>',
	'<!bar><!abovedot>',
	'<!bar><!bar>',
	'<!bar><!bar><!bar>',
	'<!bar><!bar><!group>',
	'<!bar><!bar><!hook>',
	'<!bar><!bar><!hook><!hook>',
	'<!bar><!bar><!hook><!hook><!group>',
	'<!bar><!group>',
	'<!bar><!group><!group>',
	'<!bar><!group><!group><!group>',
	'<!bar><!group><3>',
	'<!bar><!hook>',
	'<!bar><!hook><!bar>',
	'<!bar><!hook><!bar><!hook>',
	'<!bar><!hook><!bar><!hook><!group>',
	'<!bar><!hook><!hook>',
	'<!bar><!hook><!hook><!bar>',
	'<!bar><!hook><!hook><!bar><!group>',
	'<!bar><!retroflexhook>',
	'<!bar><!reversed>',
	'<!bar><!stroke>',
	'<!bar><!subscript>',
	'<!bar><!superscript>',
	'<!bar><!superscript><!group>',
	'<!bar><!turned>',
	'<!bar><!turned><!group>',
	'<!belowcomma><!belowcomma>',
	'<!belowcomma><!group>',
	'<!belowcomma><!group><!group>',
	'<!belowcomma><!group><!group><!group>',
	'<!belowcomma><!group><!group><!group><!group>',
	'<!belowcomma><!group><3>',
	'<!belowcomma><!group><4>',
	'<!belowcomma><!group><5>',
	'<!belowdot><!abovedot>',
	'<!belowdot><!belowdot>',
	'<!belowdot><!breve>',
	'<!belowdot><!circumflex>',
	'<!belowdot><!horn>',
	'<!belowdot><!macron>',
	'<!breve><!abovedot>',
	'<!breve><!abovehook>',
	'<!breve><!acute>',
	'<!breve><!belowdot>',
	'<!breve><!breve>',
	'<!breve><!breve><!retroflexhook>',
	'<!breve><!breve><!retroflexhook><!retroflexhook>',
	'<!breve><!breve><!subscript>',
	'<!breve><!breve><!superscript>',
	'<!breve><!breve><!turned>',
	'<!breve><!cedilla>',
	'<!breve><!grave>',
	'<!breve><!macron>',
	'<!breve><!retroflexhook>',
	'<!breve><!retroflexhook><!breve>',
	'<!breve><!retroflexhook><!breve><!retroflexhook>',
	'<!breve><!retroflexhook><!retroflexhook>',
	'<!breve><!retroflexhook><!retroflexhook><!breve>',
	'<!breve><!subscript>',
	'<!breve><!subscript><!breve>',
	'<!breve><!superscript>',
	'<!breve><!superscript><!breve>',
	'<!breve><!tilde>',
	'<!breve><!turned>',
	'<!breve><!turned><!breve>',
	'<!caron><!abovedot>',
	'<!caron><!caron>',
	'<!caron><!diaeresis>',
	'<!caron><!group>',
	'<!cedilla><!acute>',
	'<!cedilla><!breve>',
	'<!cedilla><!cedilla>',
	'<!circumflex><!abovehook>',
	'<!circumflex><!acute>',
	'<!circumflex><!belowdot>',
	'<!circumflex><!circumflex>',
	'<!circumflex><!circumflex><!circumflex>',
	'<!circumflex><!grave>',
	'<!circumflex><!group>',
	'<!circumflex><!group><!group>',
	'<!circumflex><!group><!group><!group>',
	'<!circumflex><!group><!group><!group><!group>',
	'<!circumflex><!group><3>',
	'<!circumflex><!group><4>',
	'<!circumflex><!group><5>',
	'<!circumflex><!tilde>',
	'<!currency><!abovering>',
	'<!currency><!cedilla>',
	'<!currency><!currency>',
	'<!diaeresis><!abovering>',
	'<!diaeresis><!acute>',
	'<!diaeresis><!caron>',
	'<!diaeresis><!diaeresis>',
	'<!diaeresis><!diaeresis><!diaeresis>',
	'<!diaeresis><!grave>',
	'<!diaeresis><!group>',
	'<!diaeresis><!group><!group>',
	'<!diaeresis><!macron>',
	'<!diaeresis><!superscript>',
	'<!diaeresis><!superscript><!superscript>',
	'<!diaeresis><!tilde>',
	'<!diaeresis><!turned>',
	'<!diaeresis><!turned><!turned>',
	'<!doubleacute><!doubleacute>',
	'<!doubleacute><!reversed>',
	'<!flag><!flag>',
	'<!flag><!flag><!flag>',
	'<!flag><!group>',
	'<!flag><!group><!group>',
	'<!flag><!group><!group><!group>',
	'<!flag><!group><3>',
	'<!grave><!abovedot>',
	'<!grave><!abovedot><!abovedot>',
	'<!grave><!acute>',
	'<!grave><!acute><!macron>',
	'<!grave><!breve>',
	'<!grave><!circumflex>',
	'<!grave><!diaeresis>',
	'<!grave><!grave>',
	'<!grave><!horn>',
	'<!grave><!macron>',
	'<!grave><!macron><!acute>',
	'<!greek><!greek>',
	'<!greek><!subscript>',
	'<!greek><%backslash>',
	'<!greek><%backslash><%quotEuroSign>',
	'<!greek><%backslash><%quotedbl>',
	'<!greek><%backslash><%tilde>',
	'<!greek><%bracketleft>',
	'<!greek><%quotEuroSign>',
	'<!greek><%quotEuroSign><%backslash>',
	'<!greek><%quotedbl>',
	'<!greek><%quotedbl><%backslash>',
	'<!greek><%tilde>',
	'<!greek><%tilde><%backslash>',
	'<!group><!group>',
	'<!group><!group><!group>',
	'<!group><!group><!group><!group>',
	'<!group><0>',
	'<!group><0><%comma>',
	'<!group><0><%comma><%period>',
	'<!group><0><%period>',
	'<!group><0><%period><%comma>',
	'<!group><1>',
	'<!group><2>',
	'<!group><3>',
	'<!group><4>',
	'<!group><5>',
	'<!group><6>',
	'<!group><6><%comma>',
	'<!group><6><%comma><%comma>',
	'<!group><6><%comma><%comma><%period>',
	'<!group><6><%comma><%period>',
	'<!group><6><%comma><%period><%comma>',
	'<!group><6><%period>',
	'<!group><6><%period><%comma>',
	'<!group><6><%period><%comma><%comma>',
	'<!group><7>',
	'<!group><7><%comma>',
	'<!group><7><%period>',
	'<!group><8>',
	'<!group><8><%comma>',
	'<!group><8><%comma><%period>',
	'<!group><8><%period>',
	'<!group><8><%period><%comma>',
	'<!group><9>',
	'<!group><9><%comma>',
	'<!group><9><%period>',
	'<!group><ellipsis>',
	'<!hook><!bar>',
	'<!hook><!bar><!bar>',
	'<!hook><!bar><!bar><!hook>',
	'<!hook><!bar><!bar><!hook><!group>',
	'<!hook><!bar><!hook>',
	'<!hook><!bar><!hook><!bar>',
	'<!hook><!bar><!hook><!bar><!group>',
	'<!hook><!group>',
	'<!hook><!group><!group>',
	'<!hook><!group><!group><!group>',
	'<!hook><!group><3>',
	'<!hook><!hook>',
	'<!hook><!hook><!bar>',
	'<!hook><!hook><!bar><!bar>',
	'<!hook><!hook><!bar><!bar><!group>',
	'<!hook><!hook><!group>',
	'<!hook><!hook><!group><!group>',
	'<!hook><!hook><!group><!group><!group>',
	'<!hook><!hook><!group><!group><!group><!group>',
	'<!hook><!hook><!group><3>',
	'<!hook><!hook><!group><4>',
	'<!hook><!hook><!group><5>',
	'<!hook><!hook><!hook>',
	'<!hook><!hook><!superscript>',
	'<!hook><!hook><!superscript><!group>',
	'<!hook><!hook><!superscript><!group><!group>',
	'<!hook><!hook><!superscript><!group><!group><!group>',
	'<!hook><!hook><!superscript><!group><!group><!group><!group>',
	'<!hook><!hook><!superscript><!group><3>',
	'<!hook><!hook><!superscript><!group><4>',
	'<!hook><!hook><!superscript><!group><5>',
	'<!hook><!hook><!turned>',
	'<!hook><!hook><!turned><!turned>',
	'<!hook><!retroflexhook>',
	'<!hook><!retroflexhook><!retroflexhook>',
	'<!hook><!retroflexhook><!turned>',
	'<!hook><!reversed>',
	'<!hook><!reversed><!group>',
	'<!hook><!reversed><!group><!group>',
	'<!hook><!subscript>',
	'<!hook><!superscript>',
	'<!hook><!superscript><!group>',
	'<!hook><!superscript><!hook>',
	'<!hook><!superscript><!hook><!group>',
	'<!hook><!superscript><!hook><!group><!group>',
	'<!hook><!superscript><!hook><!group><!group><!group>',
	'<!hook><!superscript><!hook><!group><!group><!group><!group>',
	'<!hook><!superscript><!hook><!group><3>',
	'<!hook><!superscript><!hook><!group><4>',
	'<!hook><!superscript><!hook><!group><5>',
	'<!hook><!superscript><!turned>',
	'<!hook><!tilde>',
	'<!hook><!turned>',
	'<!hook><!turned><!hook>',
	'<!hook><!turned><!hook><!turned>',
	'<!hook><!turned><!retroflexhook>',
	'<!hook><!turned><!superscript>',
	'<!hook><!turned><!turned>',
	'<!hook><!turned><!turned><!hook>',
	'<!horn><!abovehook>',
	'<!horn><!acute>',
	'<!horn><!belowdot>',
	'<!horn><!grave>',
	'<!horn><!horn>',
	'<!horn><!tilde>',
	'<!invertedbreve><!group>',
	'<!invertedbreve><!group><!group>',
	'<!invertedbreve><!group><!group><!group>',
	'<!invertedbreve><!group><!group><!group><!group>',
	'<!invertedbreve><!group><1>',
	'<!invertedbreve><!group><3>',
	'<!invertedbreve><!group><4>',
	'<!invertedbreve><!group><5>',
	'<!invertedbreve><!invertedbreve>',
	'<!macron><!abovedot>',
	'<!macron><!abovedot><!abovedot>',
	'<!macron><!acute>',
	'<!macron><!acute><!grave>',
	'<!macron><!belowdot>',
	'<!macron><!breve>',
	'<!macron><!diaeresis>',
	'<!macron><!grave>',
	'<!macron><!grave><!acute>',
	'<!macron><!group>',
	'<!macron><!group><!group>',
	'<!macron><!macron>',
	'<!macron><!macron><!macron>',
	'<!macron><!ogonek>',
	'<!macron><!retroflexhook>',
	'<!macron><!retroflexhook><!superscript>',
	'<!macron><!retroflexhook><!turned>',
	'<!macron><!superscript>',
	'<!macron><!superscript><!retroflexhook>',
	'<!macron><!superscript><!turned>',
	'<!macron><!tilde>',
	'<!macron><!turned>',
	'<!macron><!turned><!retroflexhook>',
	'<!macron><!turned><!superscript>',
	'<!ogonek><!macron>',
	'<!ogonek><!ogonek>',
	'<!retroflexhook><!bar>',
	'<!retroflexhook><!breve>',
	'<!retroflexhook><!breve><!breve>',
	'<!retroflexhook><!breve><!breve><!retroflexhook>',
	'<!retroflexhook><!breve><!retroflexhook>',
	'<!retroflexhook><!breve><!retroflexhook><!breve>',
	'<!retroflexhook><!group>',
	'<!retroflexhook><!group><!group>',
	'<!retroflexhook><!group><!group><!group>',
	'<!retroflexhook><!group><!group><!group><!group>',
	'<!retroflexhook><!group><3>',
	'<!retroflexhook><!group><4>',
	'<!retroflexhook><!group><5>',
	'<!retroflexhook><!hook>',
	'<!retroflexhook><!hook><!retroflexhook>',
	'<!retroflexhook><!hook><!turned>',
	'<!retroflexhook><!macron>',
	'<!retroflexhook><!macron><!superscript>',
	'<!retroflexhook><!macron><!turned>',
	'<!retroflexhook><!retroflexhook>',
	'<!retroflexhook><!retroflexhook><!breve>',
	'<!retroflexhook><!retroflexhook><!breve><!breve>',
	'<!retroflexhook><!retroflexhook><!group>',
	'<!retroflexhook><!retroflexhook><!group><!group>',
	'<!retroflexhook><!retroflexhook><!group><!group><!group>',
	'<!retroflexhook><!retroflexhook><!group><!group><!group><!group>',
	'<!retroflexhook><!retroflexhook><!group><3>',
	'<!retroflexhook><!retroflexhook><!group><4>',
	'<!retroflexhook><!retroflexhook><!group><5>',
	'<!retroflexhook><!retroflexhook><!hook>',
	'<!retroflexhook><!retroflexhook><!retroflexhook>',
	'<!retroflexhook><!retroflexhook><!superscript>',
	'<!retroflexhook><!retroflexhook><!turned>',
	'<!retroflexhook><!reversed>',
	'<!retroflexhook><!reversed><!group>',
	'<!retroflexhook><!reversed><!group><!group>',
	'<!retroflexhook><!superscript>',
	'<!retroflexhook><!superscript><!group>',
	'<!retroflexhook><!superscript><!group><!group>',
	'<!retroflexhook><!superscript><!group><!group><!group>',
	'<!retroflexhook><!superscript><!group><!group><!group><!group>',
	'<!retroflexhook><!superscript><!group><3>',
	'<!retroflexhook><!superscript><!group><4>',
	'<!retroflexhook><!superscript><!group><5>',
	'<!retroflexhook><!superscript><!macron>',
	'<!retroflexhook><!superscript><!retroflexhook>',
	'<!retroflexhook><!turned>',
	'<!retroflexhook><!turned><!hook>',
	'<!retroflexhook><!turned><!macron>',
	'<!retroflexhook><!turned><!retroflexhook>',
	'<!reversed><!bar>',
	'<!reversed><!doubleacute>',
	'<!reversed><!group>',
	'<!reversed><!group><!group>',
	'<!reversed><!group><!group><!group>',
	'<!reversed><!group><!group><!group><!group>',
	'<!reversed><!group><2>',
	'<!reversed><!group><3>',
	'<!reversed><!group><4>',
	'<!reversed><!group><5>',
	'<!reversed><!hook>',
	'<!reversed><!hook><!group>',
	'<!reversed><!hook><!group><!group>',
	'<!reversed><!retroflexhook>',
	'<!reversed><!retroflexhook><!group>',
	'<!reversed><!retroflexhook><!group><!group>',
	'<!reversed><!subscript>',
	'<!reversed><!superscript>',
	'<!reversed><!superscript><!group>',
	'<!reversed><!superscript><!group><!group>',
	'<!reversed><!superscript><!group><!group><!group>',
	'<!reversed><!superscript><!group><!group><!group><!group>',
	'<!reversed><!superscript><!group><3>',
	'<!reversed><!superscript><!group><4>',
	'<!reversed><!superscript><!group><5>',
	'<!stroke><!acute>',
	'<!stroke><!bar>',
	'<!stroke><!group>',
	'<!stroke><!group><!group>',
	'<!stroke><!group><!group><!group>',
	'<!stroke><!group><!group><!group><!group>',
	'<!stroke><!group><1>',
	'<!stroke><!group><2>',
	'<!stroke><!group><3>',
	'<!stroke><!group><4>',
	'<!stroke><!group><5>',
	'<!stroke><!stroke>',
	'<!stroke><!stroke><!stroke>',
	'<!stroke><!subscript>',
	'<!stroke><!tilde>',
	'<!stroke><!turned>',
	'<!stroke><!turned><!group>',
	'<!stroke><!turned><!group><!group>',
	'<!stroke><!turned><!group><!group><!group>',
	'<!stroke><!turned><!group><3>',
	'<!stroke><!turned><!turned>',
	'<!subscript><!bar>',
	'<!subscript><!breve>',
	'<!subscript><!breve><!breve>',
	'<!subscript><!greek>',
	'<!subscript><!group>',
	'<!subscript><!group><!group>',
	'<!subscript><!group><!group><!group>',
	'<!subscript><!group><!group><!group><!group>',
	'<!subscript><!group><3>',
	'<!subscript><!group><4>',
	'<!subscript><!group><6>',
	'<!subscript><!hook>',
	'<!subscript><!reversed>',
	'<!subscript><!stroke>',
	'<!subscript><!subscript>',
	'<!subscript><!subscript><!turned>',
	'<!subscript><!superscript>',
	'<!subscript><!superscript><!group>',
	'<!subscript><!turned>',
	'<!subscript><!turned><!subscript>',
	'<!subscript><!turned><!turned>',
	'<!superscript><!bar>',
	'<!superscript><!bar><!group>',
	'<!superscript><!breve>',
	'<!superscript><!breve><!breve>',
	'<!superscript><!diaeresis>',
	'<!superscript><!diaeresis><!superscript>',
	'<!superscript><!group>',
	'<!superscript><!group><!group>',
	'<!superscript><!group><!group><!group>',
	'<!superscript><!group><!group><!group><!group>',
	'<!superscript><!group><3>',
	'<!superscript><!group><4>',
	'<!superscript><!group><5>',
	'<!superscript><!group><6>',
	'<!superscript><!hook>',
	'<!superscript><!hook><!group>',
	'<!superscript><!hook><!hook>',
	'<!superscript><!hook><!hook><!group>',
	'<!superscript><!hook><!hook><!group><!group>',
	'<!superscript><!hook><!hook><!group><!group><!group>',
	'<!superscript><!hook><!hook><!group><!group><!group><!group>',
	'<!superscript><!hook><!hook><!group><3>',
	'<!superscript><!hook><!hook><!group><4>',
	'<!superscript><!hook><!hook><!group><5>',
	'<!superscript><!hook><!turned>',
	'<!superscript><!macron>',
	'<!superscript><!macron><!retroflexhook>',
	'<!superscript><!macron><!turned>',
	'<!superscript><!retroflexhook>',
	'<!superscript><!retroflexhook><!group>',
	'<!superscript><!retroflexhook><!group><!group>',
	'<!superscript><!retroflexhook><!group><!group><!group>',
	'<!superscript><!retroflexhook><!group><!group><!group><!group>',
	'<!superscript><!retroflexhook><!group><3>',
	'<!superscript><!retroflexhook><!group><4>',
	'<!superscript><!retroflexhook><!group><5>',
	'<!superscript><!retroflexhook><!macron>',
	'<!superscript><!retroflexhook><!retroflexhook>',
	'<!superscript><!reversed>',
	'<!superscript><!reversed><!group>',
	'<!superscript><!reversed><!group><!group>',
	'<!superscript><!reversed><!group><!group><!group>',
	'<!superscript><!reversed><!group><!group><!group><!group>',
	'<!superscript><!reversed><!group><3>',
	'<!superscript><!reversed><!group><4>',
	'<!superscript><!reversed><!group><5>',
	'<!superscript><!subscript>',
	'<!superscript><!subscript><!group>',
	'<!superscript><!superscript>',
	'<!superscript><!superscript><!diaeresis>',
	'<!superscript><!superscript><!group>',
	'<!superscript><!superscript><!group><!group>',
	'<!superscript><!superscript><!group><2>',
	'<!superscript><!tilde>',
	'<!superscript><!turned>',
	'<!superscript><!turned><!group>',
	'<!superscript><!turned><!group><!group>',
	'<!superscript><!turned><!group><!group><!group>',
	'<!superscript><!turned><!group><3>',
	'<!superscript><!turned><!hook>',
	'<!superscript><!turned><!macron>',
	'<!superscript><!turned><!turned>',
	'<!tilde><!acute>',
	'<!tilde><!breve>',
	'<!tilde><!circumflex>',
	'<!tilde><!diaeresis>',
	'<!tilde><!hook>',
	'<!tilde><!horn>',
	'<!tilde><!macron>',
	'<!tilde><!stroke>',
	'<!tilde><!superscript>',
	'<!tilde><!tilde>',
	'<!tilde><!tilde><!tilde>',
	'<!tilde><!tilde><!turned>',
	'<!tilde><!turned>',
	'<!tilde><!turned><!tilde>',
	'<!tilde><%ampersand>',
	'<!turned><!bar>',
	'<!turned><!bar><!group>',
	'<!turned><!breve>',
	'<!turned><!breve><!breve>',
	'<!turned><!diaeresis>',
	'<!turned><!diaeresis><!turned>',
	'<!turned><!group>',
	'<!turned><!group><!group>',
	'<!turned><!group><!group><!group>',
	'<!turned><!group><!group><!group><!group>',
	'<!turned><!group><1>',
	'<!turned><!group><2>',
	'<!turned><!group><3>',
	'<!turned><!group><4>',
	'<!turned><!group><5>',
	'<!turned><!hook>',
	'<!turned><!hook><!hook>',
	'<!turned><!hook><!hook><!turned>',
	'<!turned><!hook><!retroflexhook>',
	'<!turned><!hook><!superscript>',
	'<!turned><!hook><!turned>',
	'<!turned><!hook><!turned><!hook>',
	'<!turned><!macron>',
	'<!turned><!macron><!retroflexhook>',
	'<!turned><!macron><!superscript>',
	'<!turned><!retroflexhook>',
	'<!turned><!retroflexhook><!hook>',
	'<!turned><!retroflexhook><!macron>',
	'<!turned><!retroflexhook><!retroflexhook>',
	'<!turned><!stroke>',
	'<!turned><!stroke><!group>',
	'<!turned><!stroke><!group><!group>',
	'<!turned><!stroke><!group><!group><!group>',
	'<!turned><!stroke><!group><3>',
	'<!turned><!stroke><!turned>',
	'<!turned><!subscript>',
	'<!turned><!subscript><!subscript>',
	'<!turned><!subscript><!turned>',
	'<!turned><!superscript>',
	'<!turned><!superscript><!group>',
	'<!turned><!superscript><!group><!group>',
	'<!turned><!superscript><!group><!group><!group>',
	'<!turned><!superscript><!group><3>',
	'<!turned><!superscript><!hook>',
	'<!turned><!superscript><!macron>',
	'<!turned><!superscript><!turned>',
	'<!turned><!tilde>',
	'<!turned><!tilde><!tilde>',
	'<!turned><!turned>',
	'<!turned><!turned><!diaeresis>',
	'<!turned><!turned><!group>',
	'<!turned><!turned><!group><!group>',
	'<!turned><!turned><!group><!group><!group>',
	'<!turned><!turned><!group><3>',
	'<!turned><!turned><!hook>',
	'<!turned><!turned><!hook><!hook>',
	'<!turned><!turned><!stroke>',
	'<!turned><!turned><!subscript>',
	'<!turned><!turned><!superscript>',

	# Greek, 256.
	'<!abovehook><!greek>',
	'<!acute><!belowdot><!breve><!greek>',
	'<!acute><!belowdot><!greek>',
	'<!acute><!belowdot><!greek><!breve>',
	'<!acute><!belowdot><!greek><!invertedbreve>',
	'<!acute><!belowdot><!invertedbreve><!greek>',
	'<!acute><!breve><!belowdot><!greek>',
	'<!acute><!breve><!greek>',
	'<!acute><!breve><!greek><!belowdot>',
	'<!acute><!diaeresis><!greek>',
	'<!acute><!greek>',
	'<!acute><!greek><!belowdot>',
	'<!acute><!greek><!belowdot><!breve>',
	'<!acute><!greek><!belowdot><!invertedbreve>',
	'<!acute><!greek><!breve>',
	'<!acute><!greek><!breve><!belowdot>',
	'<!acute><!greek><!diaeresis>',
	'<!acute><!greek><!invertedbreve>',
	'<!acute><!greek><!invertedbreve><!belowdot>',
	'<!acute><!invertedbreve><!belowdot><!greek>',
	'<!acute><!invertedbreve><!greek>',
	'<!acute><!invertedbreve><!greek><!belowdot>',
	'<!belowdot><!acute><!breve><!greek>',
	'<!belowdot><!acute><!greek>',
	'<!belowdot><!acute><!greek><!breve>',
	'<!belowdot><!acute><!greek><!invertedbreve>',
	'<!belowdot><!acute><!invertedbreve><!greek>',
	'<!belowdot><!breve><!acute><!greek>',
	'<!belowdot><!breve><!circumflex><!greek>',
	'<!belowdot><!breve><!grave><!greek>',
	'<!belowdot><!breve><!greek>',
	'<!belowdot><!breve><!greek><!acute>',
	'<!belowdot><!breve><!greek><!circumflex>',
	'<!belowdot><!breve><!greek><!grave>',
	'<!belowdot><!circumflex><!breve><!greek>',
	'<!belowdot><!circumflex><!greek>',
	'<!belowdot><!circumflex><!greek><!breve>',
	'<!belowdot><!circumflex><!greek><!invertedbreve>',
	'<!belowdot><!circumflex><!invertedbreve><!greek>',
	'<!belowdot><!grave><!breve><!greek>',
	'<!belowdot><!grave><!greek>',
	'<!belowdot><!grave><!greek><!breve>',
	'<!belowdot><!grave><!greek><!invertedbreve>',
	'<!belowdot><!grave><!invertedbreve><!greek>',
	'<!belowdot><!greek>',
	'<!belowdot><!greek><!acute>',
	'<!belowdot><!greek><!acute><!breve>',
	'<!belowdot><!greek><!acute><!invertedbreve>',
	'<!belowdot><!greek><!breve>',
	'<!belowdot><!greek><!breve><!acute>',
	'<!belowdot><!greek><!breve><!circumflex>',
	'<!belowdot><!greek><!breve><!grave>',
	'<!belowdot><!greek><!circumflex>',
	'<!belowdot><!greek><!circumflex><!breve>',
	'<!belowdot><!greek><!circumflex><!invertedbreve>',
	'<!belowdot><!greek><!grave>',
	'<!belowdot><!greek><!grave><!breve>',
	'<!belowdot><!greek><!grave><!invertedbreve>',
	'<!belowdot><!greek><!invertedbreve>',
	'<!belowdot><!greek><!invertedbreve><!acute>',
	'<!belowdot><!greek><!invertedbreve><!circumflex>',
	'<!belowdot><!greek><!invertedbreve><!grave>',
	'<!belowdot><!invertedbreve><!acute><!greek>',
	'<!belowdot><!invertedbreve><!circumflex><!greek>',
	'<!belowdot><!invertedbreve><!grave><!greek>',
	'<!belowdot><!invertedbreve><!greek>',
	'<!belowdot><!invertedbreve><!greek><!acute>',
	'<!belowdot><!invertedbreve><!greek><!circumflex>',
	'<!belowdot><!invertedbreve><!greek><!grave>',
	'<!breve><!acute><!belowdot><!greek>',
	'<!breve><!acute><!greek>',
	'<!breve><!acute><!greek><!belowdot>',
	'<!breve><!belowdot><!acute><!greek>',
	'<!breve><!belowdot><!circumflex><!greek>',
	'<!breve><!belowdot><!grave><!greek>',
	'<!breve><!belowdot><!greek>',
	'<!breve><!belowdot><!greek><!acute>',
	'<!breve><!belowdot><!greek><!circumflex>',
	'<!breve><!belowdot><!greek><!grave>',
	'<!breve><!circumflex><!belowdot><!greek>',
	'<!breve><!circumflex><!greek>',
	'<!breve><!circumflex><!greek><!belowdot>',
	'<!breve><!grave><!belowdot><!greek>',
	'<!breve><!grave><!greek>',
	'<!breve><!grave><!greek><!belowdot>',
	'<!breve><!greek>',
	'<!breve><!greek><!acute>',
	'<!breve><!greek><!acute><!belowdot>',
	'<!breve><!greek><!belowdot>',
	'<!breve><!greek><!belowdot><!acute>',
	'<!breve><!greek><!belowdot><!circumflex>',
	'<!breve><!greek><!belowdot><!grave>',
	'<!breve><!greek><!circumflex>',
	'<!breve><!greek><!circumflex><!belowdot>',
	'<!breve><!greek><!grave>',
	'<!breve><!greek><!grave><!belowdot>',
	'<!caron><!greek>',
	'<!circumflex><!belowdot><!breve><!greek>',
	'<!circumflex><!belowdot><!greek>',
	'<!circumflex><!belowdot><!greek><!breve>',
	'<!circumflex><!belowdot><!greek><!invertedbreve>',
	'<!circumflex><!belowdot><!invertedbreve><!greek>',
	'<!circumflex><!breve><!belowdot><!greek>',
	'<!circumflex><!breve><!greek>',
	'<!circumflex><!breve><!greek><!belowdot>',
	'<!circumflex><!diaeresis><!greek>',
	'<!circumflex><!greek>',
	'<!circumflex><!greek><!belowdot>',
	'<!circumflex><!greek><!belowdot><!breve>',
	'<!circumflex><!greek><!belowdot><!invertedbreve>',
	'<!circumflex><!greek><!breve>',
	'<!circumflex><!greek><!breve><!belowdot>',
	'<!circumflex><!greek><!diaeresis>',
	'<!circumflex><!greek><!invertedbreve>',
	'<!circumflex><!greek><!invertedbreve><!belowdot>',
	'<!circumflex><!invertedbreve><!belowdot><!greek>',
	'<!circumflex><!invertedbreve><!greek>',
	'<!circumflex><!invertedbreve><!greek><!belowdot>',
	'<!diaeresis><!acute><!greek>',
	'<!diaeresis><!circumflex><!greek>',
	'<!diaeresis><!doubleacute><!greek>',
	'<!diaeresis><!grave><!greek>',
	'<!diaeresis><!greek>',
	'<!diaeresis><!greek><!acute>',
	'<!diaeresis><!greek><!circumflex>',
	'<!diaeresis><!greek><!doubleacute>',
	'<!diaeresis><!greek><!grave>',
	'<!doubleacute><!diaeresis><!greek>',
	'<!doubleacute><!greek>',
	'<!doubleacute><!greek><!diaeresis>',
	'<!grave><!belowdot><!breve><!greek>',
	'<!grave><!belowdot><!greek>',
	'<!grave><!belowdot><!greek><!breve>',
	'<!grave><!belowdot><!greek><!invertedbreve>',
	'<!grave><!belowdot><!invertedbreve><!greek>',
	'<!grave><!breve><!belowdot><!greek>',
	'<!grave><!breve><!greek>',
	'<!grave><!breve><!greek><!belowdot>',
	'<!grave><!diaeresis><!greek>',
	'<!grave><!greek>',
	'<!grave><!greek><!belowdot>',
	'<!grave><!greek><!belowdot><!breve>',
	'<!grave><!greek><!belowdot><!invertedbreve>',
	'<!grave><!greek><!breve>',
	'<!grave><!greek><!breve><!belowdot>',
	'<!grave><!greek><!diaeresis>',
	'<!grave><!greek><!invertedbreve>',
	'<!grave><!greek><!invertedbreve><!belowdot>',
	'<!grave><!invertedbreve><!belowdot><!greek>',
	'<!grave><!invertedbreve><!greek>',
	'<!grave><!invertedbreve><!greek><!belowdot>',
	'<!greek><!abovehook>',
	'<!greek><!acute>',
	'<!greek><!acute><!belowdot>',
	'<!greek><!acute><!belowdot><!breve>',
	'<!greek><!acute><!belowdot><!invertedbreve>',
	'<!greek><!acute><!breve>',
	'<!greek><!acute><!breve><!belowdot>',
	'<!greek><!acute><!diaeresis>',
	'<!greek><!acute><!invertedbreve>',
	'<!greek><!acute><!invertedbreve><!belowdot>',
	'<!greek><!belowdot>',
	'<!greek><!belowdot><!acute>',
	'<!greek><!belowdot><!acute><!breve>',
	'<!greek><!belowdot><!acute><!invertedbreve>',
	'<!greek><!belowdot><!breve>',
	'<!greek><!belowdot><!breve><!acute>',
	'<!greek><!belowdot><!breve><!circumflex>',
	'<!greek><!belowdot><!breve><!grave>',
	'<!greek><!belowdot><!circumflex>',
	'<!greek><!belowdot><!circumflex><!breve>',
	'<!greek><!belowdot><!circumflex><!invertedbreve>',
	'<!greek><!belowdot><!grave>',
	'<!greek><!belowdot><!grave><!breve>',
	'<!greek><!belowdot><!grave><!invertedbreve>',
	'<!greek><!belowdot><!invertedbreve>',
	'<!greek><!belowdot><!invertedbreve><!acute>',
	'<!greek><!belowdot><!invertedbreve><!circumflex>',
	'<!greek><!belowdot><!invertedbreve><!grave>',
	'<!greek><!breve>',
	'<!greek><!breve><!acute>',
	'<!greek><!breve><!acute><!belowdot>',
	'<!greek><!breve><!belowdot>',
	'<!greek><!breve><!belowdot><!acute>',
	'<!greek><!breve><!belowdot><!circumflex>',
	'<!greek><!breve><!belowdot><!grave>',
	'<!greek><!breve><!circumflex>',
	'<!greek><!breve><!circumflex><!belowdot>',
	'<!greek><!breve><!grave>',
	'<!greek><!breve><!grave><!belowdot>',
	'<!greek><!caron>',
	'<!greek><!circumflex>',
	'<!greek><!circumflex><!belowdot>',
	'<!greek><!circumflex><!belowdot><!breve>',
	'<!greek><!circumflex><!belowdot><!invertedbreve>',
	'<!greek><!circumflex><!breve>',
	'<!greek><!circumflex><!breve><!belowdot>',
	'<!greek><!circumflex><!diaeresis>',
	'<!greek><!circumflex><!invertedbreve>',
	'<!greek><!circumflex><!invertedbreve><!belowdot>',
	'<!greek><!diaeresis>',
	'<!greek><!diaeresis><!acute>',
	'<!greek><!diaeresis><!circumflex>',
	'<!greek><!diaeresis><!doubleacute>',
	'<!greek><!diaeresis><!grave>',
	'<!greek><!doubleacute>',
	'<!greek><!doubleacute><!diaeresis>',
	'<!greek><!grave>',
	'<!greek><!grave><!belowdot>',
	'<!greek><!grave><!belowdot><!breve>',
	'<!greek><!grave><!belowdot><!invertedbreve>',
	'<!greek><!grave><!breve>',
	'<!greek><!grave><!breve><!belowdot>',
	'<!greek><!grave><!diaeresis>',
	'<!greek><!grave><!invertedbreve>',
	'<!greek><!grave><!invertedbreve><!belowdot>',
	'<!greek><!invertedbreve>',
	'<!greek><!invertedbreve><!acute>',
	'<!greek><!invertedbreve><!acute><!belowdot>',
	'<!greek><!invertedbreve><!belowdot>',
	'<!greek><!invertedbreve><!belowdot><!acute>',
	'<!greek><!invertedbreve><!belowdot><!circumflex>',
	'<!greek><!invertedbreve><!belowdot><!grave>',
	'<!greek><!invertedbreve><!circumflex>',
	'<!greek><!invertedbreve><!circumflex><!belowdot>',
	'<!greek><!invertedbreve><!grave>',
	'<!greek><!invertedbreve><!grave><!belowdot>',
	'<!greek><!macron>',
	'<!invertedbreve><!acute><!belowdot><!greek>',
	'<!invertedbreve><!acute><!greek>',
	'<!invertedbreve><!acute><!greek><!belowdot>',
	'<!invertedbreve><!belowdot><!acute><!greek>',
	'<!invertedbreve><!belowdot><!circumflex><!greek>',
	'<!invertedbreve><!belowdot><!grave><!greek>',
	'<!invertedbreve><!belowdot><!greek>',
	'<!invertedbreve><!belowdot><!greek><!acute>',
	'<!invertedbreve><!belowdot><!greek><!circumflex>',
	'<!invertedbreve><!belowdot><!greek><!grave>',
	'<!invertedbreve><!circumflex><!belowdot><!greek>',
	'<!invertedbreve><!circumflex><!greek>',
	'<!invertedbreve><!circumflex><!greek><!belowdot>',
	'<!invertedbreve><!grave><!belowdot><!greek>',
	'<!invertedbreve><!grave><!greek>',
	'<!invertedbreve><!grave><!greek><!belowdot>',
	'<!invertedbreve><!greek>',
	'<!invertedbreve><!greek><!acute>',
	'<!invertedbreve><!greek><!acute><!belowdot>',
	'<!invertedbreve><!greek><!belowdot>',
	'<!invertedbreve><!greek><!belowdot><!acute>',
	'<!invertedbreve><!greek><!belowdot><!circumflex>',
	'<!invertedbreve><!greek><!belowdot><!grave>',
	'<!invertedbreve><!greek><!circumflex>',
	'<!invertedbreve><!greek><!circumflex><!belowdot>',
	'<!invertedbreve><!greek><!grave>',
	'<!invertedbreve><!greek><!grave><!belowdot>',
	'<!macron><!greek>',

	# Latin for Greek, 54.
	'<!acute><!belowdot><!breve>',
	'<!acute><!belowdot>',
	'<!acute><!belowdot><!invertedbreve>',
	'<!acute><!breve><!belowdot>',
	'<!acute><!invertedbreve><!belowdot>',
	'<!acute><!invertedbreve>',
	'<!belowdot><!acute><!breve>',
	'<!belowdot><!acute>',
	'<!belowdot><!acute><!invertedbreve>',
	'<!belowdot><!breve><!acute>',
	'<!belowdot><!breve><!circumflex>',
	'<!belowdot><!breve><!grave>',
	'<!belowdot><!circumflex><!breve>',
	'<!belowdot><!circumflex><!invertedbreve>',
	'<!belowdot><!grave><!breve>',
	'<!belowdot><!grave>',
	'<!belowdot><!grave><!invertedbreve>',
	'<!belowdot><!invertedbreve><!acute>',
	'<!belowdot><!invertedbreve><!circumflex>',
	'<!belowdot><!invertedbreve><!grave>',
	'<!belowdot><!invertedbreve>',
	'<!breve><!acute><!belowdot>',
	'<!breve><!belowdot><!acute>',
	'<!breve><!belowdot><!circumflex>',
	'<!breve><!belowdot><!grave>',
	'<!breve><!circumflex><!belowdot>',
	'<!breve><!circumflex>',
	'<!breve><!grave><!belowdot>',
	'<!circumflex><!belowdot><!breve>',
	'<!circumflex><!belowdot><!invertedbreve>',
	'<!circumflex><!breve><!belowdot>',
	'<!circumflex><!breve>',
	'<!circumflex><!diaeresis>',
	'<!circumflex><!invertedbreve><!belowdot>',
	'<!circumflex><!invertedbreve>',
	'<!diaeresis><!circumflex>',
	'<!diaeresis><!doubleacute>',
	'<!doubleacute><!diaeresis>',
	'<!grave><!belowdot><!breve>',
	'<!grave><!belowdot>',
	'<!grave><!belowdot><!invertedbreve>',
	'<!grave><!breve><!belowdot>',
	'<!grave><!invertedbreve><!belowdot>',
	'<!grave><!invertedbreve>',
	'<!invertedbreve><!acute><!belowdot>',
	'<!invertedbreve><!acute>',
	'<!invertedbreve><!belowdot><!acute>',
	'<!invertedbreve><!belowdot><!circumflex>',
	'<!invertedbreve><!belowdot><!grave>',
	'<!invertedbreve><!belowdot>',
	'<!invertedbreve><!circumflex><!belowdot>',
	'<!invertedbreve><!circumflex>',
	'<!invertedbreve><!grave><!belowdot>',
	'<!invertedbreve><!grave>',

);

# Generates the required chained dead keys.
foreach my $deadkey ( @chained ) {
	$deadkey  =~ m/(<.+>)(<.+>)/;
	$deadchar = get_dead_character( $1 );
	$input    = get_dead_character( $2 );
	$input    =~ s/<(.+)>/$1/;
	$input    = dekeysym( $input );
	print DEADKEYS $print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) )
				. "*/ DEADTRANS( " . format_character( $input ) . "\t," . format_character( $deadchar )
				. "\t," . format_character( get_dead_character( $deadkey ) ) . "\t,0x0001), // Dead key chain\n";
}

# To work around Perl’s "uninitialized value" warning,
# multikey dead characters are hard-coded like the dead
# key dead characters where this makes actual sense.
# This is based on the list of 5252 multikey chains with
# their dead character generated on 2025-12-21.
sub get_multikey_dead_character {
	my ( $multikey ) = @_;

	$multikey =~ s/^<!M>$/00A6/;# The Multikey.
	$multikey =~ s/^<!M><!M>$/E201/;# Not a dead key.

	$multikey =~ s/^<!M><%ampersand>$/E202/;
	$multikey =~ s/^<!M><%ampersand><%apostrophe>$/E203/;
	$multikey =~ s/^<!M><%ampersand><%apostrophe><%minus>$/E204/;
	$multikey =~ s/^<!M><%ampersand><%apostrophe><~nbspace>$/E205/;
	$multikey =~ s/^<!M><%ampersand><%apostrophe><~space>$/E206/;
	$multikey =~ s/^<!M><%ampersand><%aprightsingquotmark>$/E207/;
	$multikey =~ s/^<!M><%ampersand><%aprightsingquotmark><%minus>$/E208/;
	$multikey =~ s/^<!M><%ampersand><%aprightsingquotmark><~nbspace>$/E209/;
	$multikey =~ s/^<!M><%ampersand><%aprightsingquotmark><~space>$/E20A/;
	$multikey =~ s/^<!M><%ampersand><%backslash>$/E20B/;
	$multikey =~ s/^<!M><%ampersand><%bar>$/E20C/;
	$multikey =~ s/^<!M><%ampersand><%bar><%bar>$/E20D/;
	$multikey =~ s/^<!M><%ampersand><%bar><~nbspace>$/E20E/;
	$multikey =~ s/^<!M><%ampersand><%bar><~space>$/E20F/;
	$multikey =~ s/^<!M><%ampersand><%comma>$/E210/;
	$multikey =~ s/^<!M><%ampersand><%grave>$/E211/;
	$multikey =~ s/^<!M><%ampersand><%less>$/E212/;
	$multikey =~ s/^<!M><%ampersand><%less><%minus>$/E213/;
	$multikey =~ s/^<!M><%ampersand><%less><%minus><%greater>$/E214/;
	$multikey =~ s/^<!M><%ampersand><%less><%minus><~nbspace>$/E215/;
	$multikey =~ s/^<!M><%ampersand><%less><%minus><~space>$/E216/;
	$multikey =~ s/^<!M><%ampersand><%less><%parenleft>$/E217/;
	$multikey =~ s/^<!M><%ampersand><%less><%underscore>$/E218/;
	$multikey =~ s/^<!M><%ampersand><%minus>$/E219/;
	$multikey =~ s/^<!M><%ampersand><%minus><%apostrophe>$/E21A/;
	$multikey =~ s/^<!M><%ampersand><%minus><%aprightsingquotmark>$/E21B/;
	$multikey =~ s/^<!M><%ampersand><%minus><%grave>$/E21C/;
	$multikey =~ s/^<!M><%ampersand><%minus><%greater>$/E21D/;
	$multikey =~ s/^<!M><%ampersand><%parenleft>$/E21E/;
	$multikey =~ s/^<!M><%ampersand><%percent>$/E21F/;
	$multikey =~ s/^<!M><%ampersand><%period>$/E220/;
	$multikey =~ s/^<!M><%ampersand><%period><%period>$/E221/;
	$multikey =~ s/^<!M><%ampersand><%period><%period><%period>$/E222/;
	$multikey =~ s/^<!M><%ampersand><%period><%period><%period><%period>$/E223/;
	$multikey =~ s/^<!M><%ampersand><%period><%period><%period><~nbspace>$/E224/;
	$multikey =~ s/^<!M><%ampersand><%period><%period><%period><~space>$/E225/;
	$multikey =~ s/^<!M><%ampersand><%plus>$/E226/;
	$multikey =~ s/^<!M><%ampersand><%slash>$/E227/;
	$multikey =~ s/^<!M><%ampersand><%underscore>$/E228/;
	$multikey =~ s/^<!M><%ampersand><%underscore><%apostrophe>$/E229/;
	$multikey =~ s/^<!M><%ampersand><%underscore><%aprightsingquotmark>$/E22A/;
	$multikey =~ s/^<!M><%ampersand><%underscore><%greater>$/E22B/;
	$multikey =~ s/^<!M><%ampersand><3>$/E22C/;
	$multikey =~ s/^<!M><%ampersand><4>$/E22D/;
	$multikey =~ s/^<!M><%ampersand><9>$/E22E/;
	$multikey =~ s/^<!M><%ampersand><a>$/E22F/;
	$multikey =~ s/^<!M><%ampersand><a><e>$/E230/;
	$multikey =~ s/^<!M><%ampersand><a><o>$/E231/;
	$multikey =~ s/^<!M><%ampersand><a><v>$/E232/;
	$multikey =~ s/^<!M><%ampersand><a><w>$/E233/;
	$multikey =~ s/^<!M><%ampersand><f>$/E234/;
	$multikey =~ s/^<!M><%ampersand><i>$/E235/;
	$multikey =~ s/^<!M><%ampersand><n>$/E236/;
	$multikey =~ s/^<!M><%ampersand><o>$/E237/;
	$multikey =~ s/^<!M><%ampersand><o><%greater>$/E238/;
	$multikey =~ s/^<!M><%ampersand><o><%greater><%backslash>$/E239/;
	$multikey =~ s/^<!M><%ampersand><o><%greater><%percent>$/E23A/;
	$multikey =~ s/^<!M><%ampersand><o><%greater><~nbspace>$/E23B/;
	$multikey =~ s/^<!M><%ampersand><o><%greater><~space>$/E23C/;
	$multikey =~ s/^<!M><%ampersand><o><%less>$/E23D/;
	$multikey =~ s/^<!M><%ampersand><o><~nbspace>$/E23E/;
	$multikey =~ s/^<!M><%ampersand><o><~space>$/E23F/;
	$multikey =~ s/^<!M><%ampersand><u>$/E240/;
	$multikey =~ s/^<!M><%ampersand><u><r>$/E241/;
	$multikey =~ s/^<!M><%ampersand><u><s>$/E242/;
	$multikey =~ s/^<!M><%ampersand><x>$/E243/;
	$multikey =~ s/^<!M><%ampersand><z>$/E244/;
	$multikey =~ s/^<!M><%apostrophe>$/E245/;
	$multikey =~ s/^<!M><%apostrophe><%equal>$/E246/;
	$multikey =~ s/^<!M><%apostrophe><%equal><%apostrophe>$/E247/;
	$multikey =~ s/^<!M><%apostrophe><%equal><~nbspace>$/E248/;
	$multikey =~ s/^<!M><%apostrophe><%equal><~space>$/E249/;
	$multikey =~ s/^<!M><%apostrophe><%exclam>$/E24A/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%apostrophe>$/E24B/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%bar>$/E24C/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%exclam>$/E24D/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%grave>$/E24E/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%grave><%exclam>$/E24F/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%grave><~nbspace>$/E250/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%grave><~space>$/E251/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><~nbspace>$/E252/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><~space>$/E253/;
	$multikey =~ s/^<!M><%apostrophe><%minus>$/E254/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%apostrophe>$/E255/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%bar>$/E256/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%comma>$/E257/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%grave>$/E258/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%grave><%minus>$/E259/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%grave><~nbspace>$/E25A/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%grave><~space>$/E25B/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus>$/E25C/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus><%apostrophe>$/E25D/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus><%comma>$/E25E/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus><%grave>$/E25F/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus><%minus>$/E260/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus><0>$/E261/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%underscore>$/E262/;
	$multikey =~ s/^<!M><%apostrophe><%minus><0>$/E263/;
	$multikey =~ s/^<!M><%apostrophe><%minus><~nbspace>$/E264/;
	$multikey =~ s/^<!M><%apostrophe><%minus><~space>$/E265/;
	$multikey =~ s/^<!M><%apostrophe><%parenleft>$/E266/;
	$multikey =~ s/^<!M><%apostrophe><%parenleft><~nbspace>$/E267/;
	$multikey =~ s/^<!M><%apostrophe><%parenleft><~space>$/E268/;
	$multikey =~ s/^<!M><%aprightsingquotmark>$/E269/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%equal>$/E26A/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%equal><%aprightsingquotmark>$/E26B/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%equal><~nbspace>$/E26C/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%equal><~space>$/E26D/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam>$/E26E/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%aprightsingquotmark>$/E26F/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%bar>$/E270/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%exclam>$/E271/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%grave>$/E272/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%grave><%exclam>$/E273/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%grave><~nbspace>$/E274/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%grave><~space>$/E275/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><~nbspace>$/E276/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><~space>$/E277/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus>$/E278/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%aprightsingquotmark>$/E279/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%bar>$/E27A/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%comma>$/E27B/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%grave>$/E27C/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%grave><%minus>$/E27D/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%grave><~nbspace>$/E27E/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%grave><~space>$/E27F/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus>$/E280/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus><%aprightsingquotmark>$/E281/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus><%comma>$/E282/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus><%grave>$/E283/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus><%minus>$/E284/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus><0>$/E285/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%underscore>$/E286/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><0>$/E287/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><~nbspace>$/E288/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><~space>$/E289/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%parenleft>$/E28A/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%parenleft><~nbspace>$/E28B/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%parenleft><~space>$/E28C/;
	$multikey =~ s/^<!M><%aprightsingquotmark><n>$/E28D/;
	$multikey =~ s/^<!M><%asterisk>$/E28E/;
	$multikey =~ s/^<!M><%asterisk><%equal>$/E28F/;
	$multikey =~ s/^<!M><%backslash>$/E290/;
	$multikey =~ s/^<!M><%backslash><%backslash>$/E291/;
	$multikey =~ s/^<!M><%backslash><%backslash><%slash>$/E292/;
	$multikey =~ s/^<!M><%backslash><%backslash><%slash><%slash>$/E293/;
	$multikey =~ s/^<!M><%backslash><%backslash><%slash><~nbspace>$/E294/;
	$multikey =~ s/^<!M><%backslash><%backslash><%slash><~space>$/E295/;
	$multikey =~ s/^<!M><%backslash><%bar>$/E296/;
	$multikey =~ s/^<!M><%backslash><%bar><%hash>$/E297/;
	$multikey =~ s/^<!M><%backslash><%greater>$/E298/;
	$multikey =~ s/^<!M><%backslash><%greater><%equal>$/E299/;
	$multikey =~ s/^<!M><%backslash><%greater><%less>$/E29A/;
	$multikey =~ s/^<!M><%backslash><%greater><%parenright>$/E29B/;
	$multikey =~ s/^<!M><%backslash><%greater><%parenright><%minus>$/E29C/;
	$multikey =~ s/^<!M><%backslash><%greater><%slash>$/E29D/;
	$multikey =~ s/^<!M><%backslash><%greater><2>$/E29E/;
	$multikey =~ s/^<!M><%backslash><%greater><~nbspace>$/E29F/;
	$multikey =~ s/^<!M><%backslash><%greater><~space>$/E2A0/;
	$multikey =~ s/^<!M><%backslash><%hash>$/E2A1/;
	$multikey =~ s/^<!M><%backslash><%hash><%bar>$/E2A2/;
	$multikey =~ s/^<!M><%backslash><%minus>$/E2A3/;
	$multikey =~ s/^<!M><%backslash><%minus><%underscore>$/E2A4/;
	$multikey =~ s/^<!M><%backslash><%minus><~nbspace>$/E2A5/;
	$multikey =~ s/^<!M><%backslash><%minus><~space>$/E2A6/;
	$multikey =~ s/^<!M><%backslash><%parenleft>$/E2A7/;
	$multikey =~ s/^<!M><%backslash><%parenleft><%minus>$/E2A8/;
	$multikey =~ s/^<!M><%backslash><%parenleft><%slash>$/E2A9/;
	$multikey =~ s/^<!M><%backslash><%parenright>$/E2AA/;
	$multikey =~ s/^<!M><%backslash><%parenright><%slash>$/E2AB/;
	$multikey =~ s/^<!M><%backslash><%slash>$/E2AC/;
	$multikey =~ s/^<!M><%backslash><%slash><%backslash>$/E2AD/;
	$multikey =~ s/^<!M><%backslash><%slash><%bar>$/E2AE/;
	$multikey =~ s/^<!M><%backslash><%slash><%greater>$/E2AF/;
	$multikey =~ s/^<!M><%backslash><%slash><%hash>$/E2B0/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore>$/E2B1/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><%minus>$/E2B2/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><%plus>$/E2B3/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><%underscore>$/E2B4/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><o>$/E2B5/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><s>$/E2B6/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><x>$/E2B7/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><~nbspace>$/E2B8/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore><~space>$/E2B9/;
	$multikey =~ s/^<!M><%backslash><%slash><~nbspace>$/E2BA/;
	$multikey =~ s/^<!M><%backslash><%slash><~space>$/E2BB/;
	$multikey =~ s/^<!M><%backslash><%underscore>$/E2BC/;
	$multikey =~ s/^<!M><%backslash><%underscore><%bar>$/E2BD/;
	$multikey =~ s/^<!M><%backslash><%underscore><%hash>$/E2BE/;
	$multikey =~ s/^<!M><%backslash><%underscore><%slash>$/E2BF/;
	$multikey =~ s/^<!M><%bar>$/E2C0/;
	$multikey =~ s/^<!M><%bar><%apostrophe>$/E2C1/;
	$multikey =~ s/^<!M><%bar><%apostrophe><%exclam>$/E2C2/;
	$multikey =~ s/^<!M><%bar><%apostrophe><%minus>$/E2C3/;
	$multikey =~ s/^<!M><%bar><%aprightsingquotmark>$/E2C4/;
	$multikey =~ s/^<!M><%bar><%aprightsingquotmark><%exclam>$/E2C5/;
	$multikey =~ s/^<!M><%bar><%aprightsingquotmark><%minus>$/E2C6/;
	$multikey =~ s/^<!M><%bar><%backslash>$/E2C7/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash>$/E2C8/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash><%bar>$/E2C9/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash><%bracketleft>$/E2CA/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash><%hash>$/E2CB/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash><~nbspace>$/E2CC/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash><~space>$/E2CD/;
	$multikey =~ s/^<!M><%bar><%backslash><%underscore>$/E2CE/;
	$multikey =~ s/^<!M><%bar><%backslash><~nbspace>$/E2CF/;
	$multikey =~ s/^<!M><%bar><%backslash><~space>$/E2D0/;
	$multikey =~ s/^<!M><%bar><%bar>$/E2D1/;
	$multikey =~ s/^<!M><%bar><%bar><%bar>$/E2D2/;
	$multikey =~ s/^<!M><%bar><%bar><%bar><%minus>$/E2D3/;
	$multikey =~ s/^<!M><%bar><%bar><%equal>$/E2D4/;
	$multikey =~ s/^<!M><%bar><%bar><%equal><%slash>$/E2D5/;
	$multikey =~ s/^<!M><%bar><%bar><%equal><~nbspace>$/E2D6/;
	$multikey =~ s/^<!M><%bar><%bar><%equal><~space>$/E2D7/;
	$multikey =~ s/^<!M><%bar><%bar><%greater>$/E2D8/;
	$multikey =~ s/^<!M><%bar><%bar><%minus>$/E2D9/;
	$multikey =~ s/^<!M><%bar><%bar><%minus><%slash>$/E2DA/;
	$multikey =~ s/^<!M><%bar><%bar><%minus><~nbspace>$/E2DB/;
	$multikey =~ s/^<!M><%bar><%bar><%minus><~space>$/E2DC/;
	$multikey =~ s/^<!M><%bar><%bar><%slash>$/E2DD/;
	$multikey =~ s/^<!M><%bar><%bar><%tilde>$/E2DE/;
	$multikey =~ s/^<!M><%bar><%equal>$/E2DF/;
	$multikey =~ s/^<!M><%bar><%equal><%bar>$/E2E0/;
	$multikey =~ s/^<!M><%bar><%equal><%equal>$/E2E1/;
	$multikey =~ s/^<!M><%bar><%equal><%equal><%greater>$/E2E2/;
	$multikey =~ s/^<!M><%bar><%equal><%equal><%slash>$/E2E3/;
	$multikey =~ s/^<!M><%bar><%equal><%equal><~nbspace>$/E2E4/;
	$multikey =~ s/^<!M><%bar><%equal><%equal><~space>$/E2E5/;
	$multikey =~ s/^<!M><%bar><%equal><%greater>$/E2E6/;
	$multikey =~ s/^<!M><%bar><%equal><%minus>$/E2E7/;
	$multikey =~ s/^<!M><%bar><%equal><%slash>$/E2E8/;
	$multikey =~ s/^<!M><%bar><%equal><~nbspace>$/E2E9/;
	$multikey =~ s/^<!M><%bar><%equal><~space>$/E2EA/;
	$multikey =~ s/^<!M><%bar><%exclam>$/E2EB/;
	$multikey =~ s/^<!M><%bar><%exclam><%apostrophe>$/E2EC/;
	$multikey =~ s/^<!M><%bar><%exclam><%aprightsingquotmark>$/E2ED/;
	$multikey =~ s/^<!M><%bar><%exclam><%grave>$/E2EE/;
	$multikey =~ s/^<!M><%bar><%exclam><%greater>$/E2EF/;
	$multikey =~ s/^<!M><%bar><%exclam><o>$/E2F0/;
	$multikey =~ s/^<!M><%bar><%grave>$/E2F1/;
	$multikey =~ s/^<!M><%bar><%grave><%exclam>$/E2F2/;
	$multikey =~ s/^<!M><%bar><%grave><%minus>$/E2F3/;
	$multikey =~ s/^<!M><%bar><%greater>$/E2F4/;
	$multikey =~ s/^<!M><%bar><%greater><%less>$/E2F5/;
	$multikey =~ s/^<!M><%bar><%greater><%slash>$/E2F6/;
	$multikey =~ s/^<!M><%bar><%greater><%slash><%underscore>$/E2F7/;
	$multikey =~ s/^<!M><%bar><%greater><%slash><~nbspace>$/E2F8/;
	$multikey =~ s/^<!M><%bar><%greater><%slash><~space>$/E2F9/;
	$multikey =~ s/^<!M><%bar><%greater><%underscore>$/E2FA/;
	$multikey =~ s/^<!M><%bar><%greater><%underscore><%slash>$/E2FB/;
	$multikey =~ s/^<!M><%bar><%greater><%underscore><~nbspace>$/E2FC/;
	$multikey =~ s/^<!M><%bar><%greater><%underscore><~space>$/E2FD/;
	$multikey =~ s/^<!M><%bar><%greater><~nbspace>$/E2FE/;
	$multikey =~ s/^<!M><%bar><%greater><~space>$/E2FF/;
	$multikey =~ s/^<!M><%bar><%hash>$/E300/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash>$/E301/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash>$/E302/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash><%bar>$/E303/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash><%hash>$/E304/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash><~nbspace>$/E305/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash><~space>$/E306/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%underscore>$/E307/;
	$multikey =~ s/^<!M><%bar><%hash><%slash>$/E308/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash>$/E309/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash><%bar>$/E30A/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash><%hash>$/E30B/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash><~nbspace>$/E30C/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash><~space>$/E30D/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%underscore>$/E30E/;
	$multikey =~ s/^<!M><%bar><%hash><%underscore>$/E30F/;
	$multikey =~ s/^<!M><%bar><%hash><%underscore><%backslash>$/E310/;
	$multikey =~ s/^<!M><%bar><%hash><%underscore><%slash>$/E311/;
	$multikey =~ s/^<!M><%bar><%less>$/E312/;
	$multikey =~ s/^<!M><%bar><%less><%exclam>$/E313/;
	$multikey =~ s/^<!M><%bar><%less><%minus>$/E314/;
	$multikey =~ s/^<!M><%bar><%minus>$/E315/;
	$multikey =~ s/^<!M><%bar><%minus><%apostrophe>$/E316/;
	$multikey =~ s/^<!M><%bar><%minus><%aprightsingquotmark>$/E317/;
	$multikey =~ s/^<!M><%bar><%minus><%bar>$/E318/;
	$multikey =~ s/^<!M><%bar><%minus><%bar><%minus>$/E319/;
	$multikey =~ s/^<!M><%bar><%minus><%bar><~nbspace>$/E31A/;
	$multikey =~ s/^<!M><%bar><%minus><%bar><~space>$/E31B/;
	$multikey =~ s/^<!M><%bar><%minus><%equal>$/E31C/;
	$multikey =~ s/^<!M><%bar><%minus><%grave>$/E31D/;
	$multikey =~ s/^<!M><%bar><%minus><%greater>$/E31E/;
	$multikey =~ s/^<!M><%bar><%minus><%greater><%greater>$/E31F/;
	$multikey =~ s/^<!M><%bar><%minus><%greater><%less>$/E320/;
	$multikey =~ s/^<!M><%bar><%minus><%greater><~nbspace>$/E321/;
	$multikey =~ s/^<!M><%bar><%minus><%greater><~space>$/E322/;
	$multikey =~ s/^<!M><%bar><%minus><%minus>$/E323/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%greater>$/E324/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%minus>$/E325/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%minus><~nbspace>$/E326/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%minus><~space>$/E327/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%slash>$/E328/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><~nbspace>$/E329/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><~space>$/E32A/;
	$multikey =~ s/^<!M><%bar><%minus><%slash>$/E32B/;
	$multikey =~ s/^<!M><%bar><%minus><~nbspace>$/E32C/;
	$multikey =~ s/^<!M><%bar><%minus><~space>$/E32D/;
	$multikey =~ s/^<!M><%bar><%parenleft>$/E32E/;
	$multikey =~ s/^<!M><%bar><%parenright>$/E32F/;
	$multikey =~ s/^<!M><%bar><%parenright><%backslash>$/E330/;
	$multikey =~ s/^<!M><%bar><%parenright><%slash>$/E331/;
	$multikey =~ s/^<!M><%bar><%period>$/E332/;
	$multikey =~ s/^<!M><%bar><%period><~nbspace>$/E333/;
	$multikey =~ s/^<!M><%bar><%period><~space>$/E334/;
	$multikey =~ s/^<!M><%bar><%slash>$/E335/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash>$/E336/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash><%bar>$/E337/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash><%bracketleft>$/E338/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash><%hash>$/E339/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash><~nbspace>$/E33A/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash><~space>$/E33B/;
	$multikey =~ s/^<!M><%bar><%slash><%underscore>$/E33C/;
	$multikey =~ s/^<!M><%bar><%slash><~nbspace>$/E33D/;
	$multikey =~ s/^<!M><%bar><%slash><~space>$/E33E/;
	$multikey =~ s/^<!M><%bar><%tilde>$/E33F/;
	$multikey =~ s/^<!M><%bar><%tilde><%bar>$/E340/;
	$multikey =~ s/^<!M><%bar><%underscore>$/E341/;
	$multikey =~ s/^<!M><%bar><%underscore><%backslash>$/E342/;
	$multikey =~ s/^<!M><%bar><%underscore><%slash>$/E343/;
	$multikey =~ s/^<!M><%bar><%underscore><%underscore>$/E344/;
	$multikey =~ s/^<!M><%bar><%underscore><s>$/E345/;
	$multikey =~ s/^<!M><%bar><%underscore><~nbspace>$/E346/;
	$multikey =~ s/^<!M><%bar><%underscore><~space>$/E347/;
	$multikey =~ s/^<!M><%bar><p>$/E348/;
	$multikey =~ s/^<!M><%bar><P>$/E349/;
	$multikey =~ s/^<!M><%bar><w>$/E34A/;
	$multikey =~ s/^<!M><%bracketleft>$/E34B/;
	$multikey =~ s/^<!M><%bracketleft><%apostrophe>$/E34C/;
	$multikey =~ s/^<!M><%bracketleft><%apostrophe><~nbspace>$/E34D/;
	$multikey =~ s/^<!M><%bracketleft><%apostrophe><~space>$/E34E/;
	$multikey =~ s/^<!M><%bracketleft><%asterisk>$/E34F/;
	$multikey =~ s/^<!M><%bracketleft><%backslash>$/E350/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%bracketright>$/E351/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%colon>$/E352/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%colon><%bracketright>$/E353/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%minus>$/E354/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%minus><%bracketright>$/E355/;
	$multikey =~ s/^<!M><%bracketleft><%bar>$/E356/;
	$multikey =~ s/^<!M><%bracketleft><%bar><%bracketright>$/E357/;
	$multikey =~ s/^<!M><%bracketleft><%bar><%hash>$/E358/;
	$multikey =~ s/^<!M><%bracketleft><%bracketleft>$/E359/;
	$multikey =~ s/^<!M><%bracketleft><%bracketleft><%bracketright>$/E35A/;
	$multikey =~ s/^<!M><%bracketleft><%bracketleft><w>$/E35B/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright>$/E35C/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><%bar>$/E35D/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><%minus>$/E35E/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><0>$/E35F/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><1>$/E360/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><~nbspace>$/E361/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright><~space>$/E362/;
	$multikey =~ s/^<!M><%bracketleft><%circum>$/E363/;
	$multikey =~ s/^<!M><%bracketleft><%grave>$/E364/;
	$multikey =~ s/^<!M><%bracketleft><%hash>$/E365/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bar>$/E366/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright>$/E367/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright><%bar>$/E368/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright><0>$/E369/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright><1>$/E36A/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright><~nbspace>$/E36B/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright><~space>$/E36C/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%slash>$/E36D/;
	$multikey =~ s/^<!M><%bracketleft><%minus>$/E36E/;
	$multikey =~ s/^<!M><%bracketleft><%minus><%backslash>$/E36F/;
	$multikey =~ s/^<!M><%bracketleft><%minus><%backslash><%bracketright>$/E370/;
	$multikey =~ s/^<!M><%bracketleft><%minus><%bracketright>$/E371/;
	$multikey =~ s/^<!M><%bracketleft><%parenleft>$/E372/;
	$multikey =~ s/^<!M><%bracketleft><%period>$/E373/;
	$multikey =~ s/^<!M><%bracketleft><%plus>$/E374/;
	$multikey =~ s/^<!M><%bracketleft><%slash>$/E375/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%bracketright>$/E376/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%colon>$/E377/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%colon><%bracketright>$/E378/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%hash>$/E379/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%minus>$/E37A/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%minus><%bracketright>$/E37B/;
	$multikey =~ s/^<!M><%bracketleft><%underscore>$/E37C/;
	$multikey =~ s/^<!M><%bracketleft><%underscore><%bracketright>$/E37D/;
	$multikey =~ s/^<!M><%bracketleft><%underscore><~nbspace>$/E37E/;
	$multikey =~ s/^<!M><%bracketleft><%underscore><~space>$/E37F/;
	$multikey =~ s/^<!M><%bracketleft><V>$/E380/;
	$multikey =~ s/^<!M><%bracketleft><v>$/E381/;
	$multikey =~ s/^<!M><%bracketleft><V><%bracketright>$/E382/;
	$multikey =~ s/^<!M><%bracketleft><v><%bracketright>$/E383/;
	$multikey =~ s/^<!M><%bracketleft><v><%percent>$/E384/;
	$multikey =~ s/^<!M><%bracketleft><v><~nbspace>$/E385/;
	$multikey =~ s/^<!M><%bracketleft><v><~space>$/E386/;
	$multikey =~ s/^<!M><%bracketleft><w>$/E387/;
	$multikey =~ s/^<!M><%bracketleft><x>$/E388/;
	$multikey =~ s/^<!M><%bracketleft><X>$/E389/;
	$multikey =~ s/^<!M><%bracketleft><X><%bracketright>$/E38A/;
	$multikey =~ s/^<!M><%bracketleft><X><L>$/E38B/;
	$multikey =~ s/^<!M><%bracketleft><X><L><%bracketright>$/E38C/;
	$multikey =~ s/^<!M><%bracketright>$/E38D/;
	$multikey =~ s/^<!M><%bracketright><%apostrophe>$/E38E/;
	$multikey =~ s/^<!M><%bracketright><%backslash>$/E38F/;
	$multikey =~ s/^<!M><%bracketright><%backslash><%slash>$/E390/;
	$multikey =~ s/^<!M><%bracketright><%backslash><%slash><%bar>$/E391/;
	$multikey =~ s/^<!M><%bracketright><%backslash><%slash><%bracketleft>$/E392/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft>$/E393/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><%bar>$/E394/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><%minus>$/E395/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><0>$/E396/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><1>$/E397/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><~nbspace>$/E398/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft><~space>$/E399/;
	$multikey =~ s/^<!M><%bracketright><%bracketright>$/E39A/;
	$multikey =~ s/^<!M><%bracketright><%bracketright><w>$/E39B/;
	$multikey =~ s/^<!M><%bracketright><%circum>$/E39C/;
	$multikey =~ s/^<!M><%bracketright><%grave>$/E39D/;
	$multikey =~ s/^<!M><%bracketright><%parenright>$/E39E/;
	$multikey =~ s/^<!M><%bracketright><%parenright><~nbspace>$/E39F/;
	$multikey =~ s/^<!M><%bracketright><%parenright><~space>$/E3A0/;
	$multikey =~ s/^<!M><%bracketright><%slash>$/E3A1/;
	$multikey =~ s/^<!M><%bracketright><%slash><%backslash>$/E3A2/;
	$multikey =~ s/^<!M><%bracketright><%slash><%backslash><%bar>$/E3A3/;
	$multikey =~ s/^<!M><%bracketright><%slash><%backslash><%bracketleft>$/E3A4/;
	$multikey =~ s/^<!M><%bracketright><%underscore>$/E3A5/;
	$multikey =~ s/^<!M><%bracketright><w>$/E3A6/;
	$multikey =~ s/^<!M><%circum>$/E3A7/;
	$multikey =~ s/^<!M><%circum><%ampersand>$/E3A8/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft>$/E3A9/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><%braceleft>$/E3AA/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><%braceleft><d>$/E3AB/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><%braceleft><t>$/E3AC/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><d>$/E3AD/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><t>$/E3AE/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceright>$/E3AF/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceright><d>$/E3B0/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceright><l>$/E3B1/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceright><t>$/E3B2/;
	$multikey =~ s/^<!M><%circum><%ampersand><9>$/E3B3/;
	$multikey =~ s/^<!M><%circum><%ampersand><A>$/E3B4/;
	$multikey =~ s/^<!M><%circum><%ampersand><A><A>$/E3B5/;
	$multikey =~ s/^<!M><%circum><%ampersand><d>$/E3B6/;
	$multikey =~ s/^<!M><%circum><%ampersand><d><3>$/E3B7/;
	$multikey =~ s/^<!M><%circum><%ampersand><d><z>$/E3B8/;
	$multikey =~ s/^<!M><%circum><%ampersand><f>$/E3B9/;
	$multikey =~ s/^<!M><%circum><%ampersand><f><g>$/E3BA/;
	$multikey =~ s/^<!M><%circum><%ampersand><f><n>$/E3BB/;
	$multikey =~ s/^<!M><%circum><%ampersand><l>$/E3BC/;
	$multikey =~ s/^<!M><%circum><%ampersand><l><3>$/E3BD/;
	$multikey =~ s/^<!M><%circum><%ampersand><l><s>$/E3BE/;
	$multikey =~ s/^<!M><%circum><%ampersand><l><z>$/E3BF/;
	$multikey =~ s/^<!M><%circum><%ampersand><t>$/E3C0/;
	$multikey =~ s/^<!M><%circum><%ampersand><t><c>$/E3C1/;
	$multikey =~ s/^<!M><%circum><%ampersand><t><e>$/E3C2/;
	$multikey =~ s/^<!M><%circum><%ampersand><t><s>$/E3C3/;
	$multikey =~ s/^<!M><%circum><%ampersand><t><S>$/E3C4/;
	$multikey =~ s/^<!M><%circum><%ampersand><u>$/E3C5/;
	$multikey =~ s/^<!M><%circum><%bracketright>$/E3C6/;
	$multikey =~ s/^<!M><%circum><%hash>$/E3C7/;
	$multikey =~ s/^<!M><%circum><%hash><%underscore>$/E3C8/;
	$multikey =~ s/^<!M><%circum><%plus>$/E3C9/;
	$multikey =~ s/^<!M><%circum><%tilde>$/E3CA/;
	$multikey =~ s/^<!M><%circum><%tilde><%tilde>$/E3CB/;
	$multikey =~ s/^<!M><%colon>$/E3CC/;
	$multikey =~ s/^<!M><%colon><%colon>$/E3CD/;
	$multikey =~ s/^<!M><%colon><%colon><%equal>$/E3CE/;
	$multikey =~ s/^<!M><%colon><%colon><%equal><~nbspace>$/E3CF/;
	$multikey =~ s/^<!M><%colon><%colon><%equal><~space>$/E3D0/;
	$multikey =~ s/^<!M><%colon><%equal>$/E3D1/;
	$multikey =~ s/^<!M><%colon><%minus>$/E3D2/;
	$multikey =~ s/^<!M><%colon><%minus><%colon>$/E3D3/;
	$multikey =~ s/^<!M><%colon><%minus><%greater>$/E3D4/;
	$multikey =~ s/^<!M><%colon><%minus><x>$/E3D5/;
	$multikey =~ s/^<!M><%colon><%minus><~nbspace>$/E3D6/;
	$multikey =~ s/^<!M><%colon><%minus><~space>$/E3D7/;
	$multikey =~ s/^<!M><%colon><%parenleft>$/E3D8/;
	$multikey =~ s/^<!M><%colon><%parenright>$/E3D9/;
	$multikey =~ s/^<!M><%colon><%period>$/E3DA/;
	$multikey =~ s/^<!M><%comma>$/E3DB/;
	$multikey =~ s/^<!M><%comma><%minus>$/E3DC/;
	$multikey =~ s/^<!M><%equal>$/E3DD/;
	$multikey =~ s/^<!M><%equal><%apostrophe>$/E3DE/;
	$multikey =~ s/^<!M><%equal><%apostrophe><%equal>$/E3DF/;
	$multikey =~ s/^<!M><%equal><%apostrophe><~nbspace>$/E3E0/;
	$multikey =~ s/^<!M><%equal><%apostrophe><~space>$/E3E1/;
	$multikey =~ s/^<!M><%equal><%aprightsingquotmark>$/E3E2/;
	$multikey =~ s/^<!M><%equal><%aprightsingquotmark><%equal>$/E3E3/;
	$multikey =~ s/^<!M><%equal><%aprightsingquotmark><~nbspace>$/E3E4/;
	$multikey =~ s/^<!M><%equal><%aprightsingquotmark><~space>$/E3E5/;
	$multikey =~ s/^<!M><%equal><%bar>$/E3E6/;
	$multikey =~ s/^<!M><%equal><%bar><%bar>$/E3E7/;
	$multikey =~ s/^<!M><%equal><%bar><%bar><%equal>$/E3E8/;
	$multikey =~ s/^<!M><%equal><%bar><%bar><~nbspace>$/E3E9/;
	$multikey =~ s/^<!M><%equal><%bar><%bar><~space>$/E3EA/;
	$multikey =~ s/^<!M><%equal><%bar><%equal>$/E3EB/;
	$multikey =~ s/^<!M><%equal><%bar><%greater>$/E3EC/;
	$multikey =~ s/^<!M><%equal><%bar><~nbspace>$/E3ED/;
	$multikey =~ s/^<!M><%equal><%bar><~space>$/E3EE/;
	$multikey =~ s/^<!M><%equal><%circum>$/E3EF/;
	$multikey =~ s/^<!M><%equal><%colon>$/E3F0/;
	$multikey =~ s/^<!M><%equal><%equal>$/E3F1/;
	$multikey =~ s/^<!M><%equal><%equal><%equal>$/E3F2/;
	$multikey =~ s/^<!M><%equal><%equal><%equal><~nbspace>$/E3F3/;
	$multikey =~ s/^<!M><%equal><%equal><%equal><~space>$/E3F4/;
	$multikey =~ s/^<!M><%equal><%equal><%greater>$/E3F5/;
	$multikey =~ s/^<!M><%equal><%greater>$/E3F6/;
	$multikey =~ s/^<!M><%equal><%greater><%grave>$/E3F7/;
	$multikey =~ s/^<!M><%equal><%greater><~nbspace>$/E3F8/;
	$multikey =~ s/^<!M><%equal><%greater><~space>$/E3F9/;
	$multikey =~ s/^<!M><%equal><%less>$/E3FA/;
	$multikey =~ s/^<!M><%equal><%less><%grave>$/E3FB/;
	$multikey =~ s/^<!M><%equal><%less><%minus>$/E3FC/;
	$multikey =~ s/^<!M><%equal><%less><~nbspace>$/E3FD/;
	$multikey =~ s/^<!M><%equal><%less><~space>$/E3FE/;
	$multikey =~ s/^<!M><%equal><%minus>$/E3FF/;
	$multikey =~ s/^<!M><%equal><%minus><%bar>$/E400/;
	$multikey =~ s/^<!M><%equal><%minus><%bar><%bar>$/E401/;
	$multikey =~ s/^<!M><%equal><%minus><%bar><%bar><%bar>$/E402/;
	$multikey =~ s/^<!M><%equal><%minus><%bar><%bar><~nbspace>$/E403/;
	$multikey =~ s/^<!M><%equal><%minus><%bar><%bar><~space>$/E404/;
	$multikey =~ s/^<!M><%equal><%minus><%slash>$/E405/;
	$multikey =~ s/^<!M><%equal><%minus><%slash><~nbspace>$/E406/;
	$multikey =~ s/^<!M><%equal><%minus><%slash><~space>$/E407/;
	$multikey =~ s/^<!M><%equal><%minus><~nbspace>$/E408/;
	$multikey =~ s/^<!M><%equal><%minus><~space>$/E409/;
	$multikey =~ s/^<!M><%equal><%parenright>$/E40A/;
	$multikey =~ s/^<!M><%equal><%period>$/E40B/;
	$multikey =~ s/^<!M><%equal><%plus>$/E40C/;
	$multikey =~ s/^<!M><%equal><%slash>$/E40D/;
	$multikey =~ s/^<!M><%equal><%slash><%greater>$/E40E/;
	$multikey =~ s/^<!M><%equal><%slash><%slash>$/E40F/;
	$multikey =~ s/^<!M><%equal><%slash><~nbspace>$/E410/;
	$multikey =~ s/^<!M><%equal><%slash><~space>$/E411/;
	$multikey =~ s/^<!M><%equal><%tilde>$/E412/;
	$multikey =~ s/^<!M><%equal><%underscore>$/E413/;
	$multikey =~ s/^<!M><%exclam>$/E414/;
	$multikey =~ s/^<!M><%exclam><%apostrophe>$/E415/;
	$multikey =~ s/^<!M><%exclam><%apostrophe><%bar>$/E416/;
	$multikey =~ s/^<!M><%exclam><%apostrophe><~nbspace>$/E417/;
	$multikey =~ s/^<!M><%exclam><%apostrophe><~space>$/E418/;
	$multikey =~ s/^<!M><%exclam><%aprightsingquotmark>$/E419/;
	$multikey =~ s/^<!M><%exclam><%aprightsingquotmark><%bar>$/E41A/;
	$multikey =~ s/^<!M><%exclam><%aprightsingquotmark><~nbspace>$/E41B/;
	$multikey =~ s/^<!M><%exclam><%aprightsingquotmark><~space>$/E41C/;
	$multikey =~ s/^<!M><%exclam><%bar>$/E41D/;
	$multikey =~ s/^<!M><%exclam><%bar><%exclam>$/E41E/;
	$multikey =~ s/^<!M><%exclam><%bar><%greater>$/E41F/;
	$multikey =~ s/^<!M><%exclam><%circum>$/E420/;
	$multikey =~ s/^<!M><%exclam><%comma>$/E421/;
	$multikey =~ s/^<!M><%exclam><%comma><%minus>$/E422/;
	$multikey =~ s/^<!M><%exclam><%comma><%minus><%greater>$/E423/;
	$multikey =~ s/^<!M><%exclam><%exclam>$/E424/;
	$multikey =~ s/^<!M><%exclam><%exclam><%exclam>$/E425/;
	$multikey =~ s/^<!M><%exclam><%grave>$/E426/;
	$multikey =~ s/^<!M><%exclam><%grave><%bar>$/E427/;
	$multikey =~ s/^<!M><%exclam><%grave><%exclam>$/E428/;
	$multikey =~ s/^<!M><%exclam><%grave><%exclam><%apostrophe>$/E429/;
	$multikey =~ s/^<!M><%exclam><%grave><%exclam><%aprightsingquotmark>$/E42A/;
	$multikey =~ s/^<!M><%exclam><%grave><%grave>$/E42B/;
	$multikey =~ s/^<!M><%exclam><%grave><~nbspace>$/E42C/;
	$multikey =~ s/^<!M><%exclam><%grave><~space>$/E42D/;
	$multikey =~ s/^<!M><%exclam><%greater>$/E42E/;
	$multikey =~ s/^<!M><%exclam><%greater><%bar>$/E42F/;
	$multikey =~ s/^<!M><%exclam><%greater><%equal>$/E430/;
	$multikey =~ s/^<!M><%exclam><%greater><%exclam>$/E431/;
	$multikey =~ s/^<!M><%exclam><%greater><%greater>$/E432/;
	$multikey =~ s/^<!M><%exclam><%greater><%greater><~nbspace>$/E433/;
	$multikey =~ s/^<!M><%exclam><%greater><%greater><~space>$/E434/;
	$multikey =~ s/^<!M><%exclam><%greater><%less>$/E435/;
	$multikey =~ s/^<!M><%exclam><%greater><2>$/E436/;
	$multikey =~ s/^<!M><%exclam><%greater><3>$/E437/;
	$multikey =~ s/^<!M><%exclam><%greater><4>$/E438/;
	$multikey =~ s/^<!M><%exclam><%greater><~nbspace>$/E439/;
	$multikey =~ s/^<!M><%exclam><%greater><~space>$/E43A/;
	$multikey =~ s/^<!M><%exclam><%minus>$/E43B/;
	$multikey =~ s/^<!M><%exclam><%minus><%greater>$/E43C/;
	$multikey =~ s/^<!M><%exclam><%question>$/E43D/;
	$multikey =~ s/^<!M><%exclam><p>$/E43E/;
	$multikey =~ s/^<!M><%exclam><P>$/E43F/;
	$multikey =~ s/^<!M><%grave>$/E440/;
	$multikey =~ s/^<!M><%grave><%exclam>$/E441/;
	$multikey =~ s/^<!M><%grave><%exclam><%apostrophe>$/E442/;
	$multikey =~ s/^<!M><%grave><%exclam><%aprightsingquotmark>$/E443/;
	$multikey =~ s/^<!M><%grave><%exclam><%bar>$/E444/;
	$multikey =~ s/^<!M><%grave><%exclam><%grave>$/E445/;
	$multikey =~ s/^<!M><%grave><%exclam><~nbspace>$/E446/;
	$multikey =~ s/^<!M><%grave><%exclam><~space>$/E447/;
	$multikey =~ s/^<!M><%grave><%minus>$/E448/;
	$multikey =~ s/^<!M><%grave><%minus><%apostrophe>$/E449/;
	$multikey =~ s/^<!M><%grave><%minus><%aprightsingquotmark>$/E44A/;
	$multikey =~ s/^<!M><%grave><%minus><%bar>$/E44B/;
	$multikey =~ s/^<!M><%grave><%minus><%grave>$/E44C/;
	$multikey =~ s/^<!M><%grave><%minus><%minus>$/E44D/;
	$multikey =~ s/^<!M><%grave><%minus><%minus><%apostrophe>$/E44E/;
	$multikey =~ s/^<!M><%grave><%minus><%minus><%aprightsingquotmark>$/E44F/;
	$multikey =~ s/^<!M><%grave><%minus><~nbspace>$/E450/;
	$multikey =~ s/^<!M><%grave><%minus><~space>$/E451/;
	$multikey =~ s/^<!M><%greater>$/E452/;
	$multikey =~ s/^<!M><%greater><%bar>$/E453/;
	$multikey =~ s/^<!M><%greater><%bar><%slash>$/E454/;
	$multikey =~ s/^<!M><%greater><%bar><%slash><~nbspace>$/E455/;
	$multikey =~ s/^<!M><%greater><%bar><%slash><~space>$/E456/;
	$multikey =~ s/^<!M><%greater><%bracketleft>$/E457/;
	$multikey =~ s/^<!M><%greater><%bracketright>$/E458/;
	$multikey =~ s/^<!M><%greater><%equal>$/E459/;
	$multikey =~ s/^<!M><%greater><%equal><%grave>$/E45A/;
	$multikey =~ s/^<!M><%greater><%equal><%less>$/E45B/;
	$multikey =~ s/^<!M><%greater><%equal><%slash>$/E45C/;
	$multikey =~ s/^<!M><%greater><%equal><~nbspace>$/E45D/;
	$multikey =~ s/^<!M><%greater><%equal><~space>$/E45E/;
	$multikey =~ s/^<!M><%greater><%greater>$/E45F/;
	$multikey =~ s/^<!M><%greater><%greater><%bracketleft>$/E460/;
	$multikey =~ s/^<!M><%greater><%greater><%bracketright>$/E461/;
	$multikey =~ s/^<!M><%greater><%greater><%minus>$/E462/;
	$multikey =~ s/^<!M><%greater><%greater><%parenleft>$/E463/;
	$multikey =~ s/^<!M><%greater><%greater><%parenright>$/E464/;
	$multikey =~ s/^<!M><%greater><%less>$/E465/;
	$multikey =~ s/^<!M><%greater><%less><%equal>$/E466/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft>$/E467/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft><%parenright>$/E468/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft><%parenright><%minus>$/E469/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft><%parenright><~nbspace>$/E46A/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft><%parenright><~space>$/E46B/;
	$multikey =~ s/^<!M><%greater><%less><%parenright>$/E46C/;
	$multikey =~ s/^<!M><%greater><%less><%parenright><%parenleft>$/E46D/;
	$multikey =~ s/^<!M><%greater><%less><%parenright><%parenleft><%minus>$/E46E/;
	$multikey =~ s/^<!M><%greater><%less><%parenright><%parenleft><~nbspace>$/E46F/;
	$multikey =~ s/^<!M><%greater><%less><%parenright><%parenleft><~space>$/E470/;
	$multikey =~ s/^<!M><%greater><%less><%slash>$/E471/;
	$multikey =~ s/^<!M><%greater><%less><~nbspace>$/E472/;
	$multikey =~ s/^<!M><%greater><%less><~space>$/E473/;
	$multikey =~ s/^<!M><%greater><%minus>$/E474/;
	$multikey =~ s/^<!M><%greater><%minus><%bar>$/E475/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar>$/E476/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%greater>$/E477/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%greater><%greater>$/E478/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%greater><~nbspace>$/E479/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%greater><~space>$/E47A/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus>$/E47B/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus><%greater>$/E47C/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus><%greater><%greater>$/E47D/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus><%greater><~nbspace>$/E47E/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus><%greater><~space>$/E47F/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%greater>$/E480/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%greater><%greater>$/E481/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%greater><~nbspace>$/E482/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%greater><~space>$/E483/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus>$/E484/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus><%greater>$/E485/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus><%greater><%greater>$/E486/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus><%greater><~nbspace>$/E487/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus><%greater><~space>$/E488/;
	$multikey =~ s/^<!M><%greater><%minus><%greater>$/E489/;
	$multikey =~ s/^<!M><%greater><%minus><%greater><%greater>$/E48A/;
	$multikey =~ s/^<!M><%greater><%minus><%greater><~nbspace>$/E48B/;
	$multikey =~ s/^<!M><%greater><%minus><%greater><~space>$/E48C/;
	$multikey =~ s/^<!M><%greater><%minus><%underscore>$/E48D/;
	$multikey =~ s/^<!M><%greater><%minus><0>$/E48E/;
	$multikey =~ s/^<!M><%greater><%minus><~nbspace>$/E48F/;
	$multikey =~ s/^<!M><%greater><%minus><~space>$/E490/;
	$multikey =~ s/^<!M><%greater><%parenleft>$/E491/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenleft>$/E492/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright>$/E493/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%bracketleft>$/E494/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%bracketright>$/E495/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%equal>$/E496/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%equal><%slash>$/E497/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%equal><~nbspace>$/E498/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%equal><~space>$/E499/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%slash>$/E49A/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde>$/E49B/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%slash>$/E49C/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%tilde>$/E49D/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%tilde><%slash>$/E49E/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%tilde><~nbspace>$/E49F/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%tilde><~space>$/E4A0/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><~nbspace>$/E4A1/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><~space>$/E4A2/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%underscore>$/E4A3/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%underscore><%slash>$/E4A4/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%underscore><~nbspace>$/E4A5/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%underscore><~space>$/E4A6/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><~nbspace>$/E4A7/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><~space>$/E4A8/;
	$multikey =~ s/^<!M><%greater><%parenright>$/E4A9/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft>$/E4AA/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%bracketleft>$/E4AB/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%bracketright>$/E4AC/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%equal>$/E4AD/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%equal><%slash>$/E4AE/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%equal><~nbspace>$/E4AF/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%equal><~space>$/E4B0/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%slash>$/E4B1/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde>$/E4B2/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%slash>$/E4B3/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%tilde>$/E4B4/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%tilde><%slash>$/E4B5/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%tilde><~nbspace>$/E4B6/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%tilde><~space>$/E4B7/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><~nbspace>$/E4B8/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><~space>$/E4B9/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%underscore>$/E4BA/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%underscore><%slash>$/E4BB/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%underscore><~nbspace>$/E4BC/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%underscore><~space>$/E4BD/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><~nbspace>$/E4BE/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><~space>$/E4BF/;
	$multikey =~ s/^<!M><%greater><%period>$/E4C0/;
	$multikey =~ s/^<!M><%greater><%period><%underscore>$/E4C1/;
	$multikey =~ s/^<!M><%greater><%period><~nbspace>$/E4C2/;
	$multikey =~ s/^<!M><%greater><%period><~space>$/E4C3/;
	$multikey =~ s/^<!M><%greater><%slash>$/E4C4/;
	$multikey =~ s/^<!M><%greater><%slash><%tilde>$/E4C5/;
	$multikey =~ s/^<!M><%greater><%slash><%underscore>$/E4C6/;
	$multikey =~ s/^<!M><%greater><%slash><~nbspace>$/E4C7/;
	$multikey =~ s/^<!M><%greater><%slash><~space>$/E4C8/;
	$multikey =~ s/^<!M><%greater><%tilde>$/E4C9/;
	$multikey =~ s/^<!M><%greater><%tilde><%less>$/E4CA/;
	$multikey =~ s/^<!M><%greater><%tilde><%minus>$/E4CB/;
	$multikey =~ s/^<!M><%greater><%tilde><%slash>$/E4CC/;
	$multikey =~ s/^<!M><%greater><%tilde><%tilde>$/E4CD/;
	$multikey =~ s/^<!M><%greater><%tilde><%tilde><%slash>$/E4CE/;
	$multikey =~ s/^<!M><%greater><%tilde><%tilde><~nbspace>$/E4CF/;
	$multikey =~ s/^<!M><%greater><%tilde><%tilde><~space>$/E4D0/;
	$multikey =~ s/^<!M><%greater><%tilde><%underscore>$/E4D1/;
	$multikey =~ s/^<!M><%greater><%tilde><~nbspace>$/E4D2/;
	$multikey =~ s/^<!M><%greater><%tilde><~space>$/E4D3/;
	$multikey =~ s/^<!M><%greater><%underscore>$/E4D4/;
	$multikey =~ s/^<!M><%greater><%underscore><%grave>$/E4D5/;
	$multikey =~ s/^<!M><%greater><%underscore><%less>$/E4D6/;
	$multikey =~ s/^<!M><%greater><%underscore><%less><%underscore>$/E4D7/;
	$multikey =~ s/^<!M><%greater><%underscore><%less><~nbspace>$/E4D8/;
	$multikey =~ s/^<!M><%greater><%underscore><%less><~space>$/E4D9/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft>$/E4DA/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft><%parenright>$/E4DB/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft><%parenright><%slash>$/E4DC/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft><%parenright><~nbspace>$/E4DD/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft><%parenright><~space>$/E4DE/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright>$/E4DF/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright><%parenleft>$/E4E0/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright><%parenleft><%slash>$/E4E1/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright><%parenleft><~nbspace>$/E4E2/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright><%parenleft><~space>$/E4E3/;
	$multikey =~ s/^<!M><%greater><%underscore><%period>$/E4E4/;
	$multikey =~ s/^<!M><%greater><%underscore><%slash>$/E4E5/;
	$multikey =~ s/^<!M><%greater><%underscore><~nbspace>$/E4E6/;
	$multikey =~ s/^<!M><%greater><%underscore><~space>$/E4E7/;
	$multikey =~ s/^<!M><%less>$/E4E8/;
	$multikey =~ s/^<!M><%less><%backslash>$/E4E9/;
	$multikey =~ s/^<!M><%less><%backslash><%equal>$/E4EA/;
	$multikey =~ s/^<!M><%less><%backslash><%greater>$/E4EB/;
	$multikey =~ s/^<!M><%less><%backslash><%less>$/E4EC/;
	$multikey =~ s/^<!M><%less><%backslash><%parenleft>$/E4ED/;
	$multikey =~ s/^<!M><%less><%backslash><%parenleft><%minus>$/E4EE/;
	$multikey =~ s/^<!M><%less><%backslash><%parenright>$/E4EF/;
	$multikey =~ s/^<!M><%less><%backslash><%slash>$/E4F0/;
	$multikey =~ s/^<!M><%less><%backslash><2>$/E4F1/;
	$multikey =~ s/^<!M><%less><%backslash><~nbspace>$/E4F2/;
	$multikey =~ s/^<!M><%less><%backslash><~space>$/E4F3/;
	$multikey =~ s/^<!M><%less><%bar>$/E4F4/;
	$multikey =~ s/^<!M><%less><%bar><%bar>$/E4F5/;
	$multikey =~ s/^<!M><%less><%bar><%bar><%minus>$/E4F6/;
	$multikey =~ s/^<!M><%less><%bar><%bar><%minus><%less>$/E4F7/;
	$multikey =~ s/^<!M><%less><%bar><%bar><%minus><~nbspace>$/E4F8/;
	$multikey =~ s/^<!M><%less><%bar><%bar><%minus><~space>$/E4F9/;
	$multikey =~ s/^<!M><%less><%bar><%bar><~nbspace>$/E4FA/;
	$multikey =~ s/^<!M><%less><%bar><%bar><~space>$/E4FB/;
	$multikey =~ s/^<!M><%less><%bar><%equal>$/E4FC/;
	$multikey =~ s/^<!M><%less><%bar><%exclam>$/E4FD/;
	$multikey =~ s/^<!M><%less><%bar><%minus>$/E4FE/;
	$multikey =~ s/^<!M><%less><%bar><%minus><%bar>$/E4FF/;
	$multikey =~ s/^<!M><%less><%bar><%minus><%less>$/E500/;
	$multikey =~ s/^<!M><%less><%bar><%minus><~nbspace>$/E501/;
	$multikey =~ s/^<!M><%less><%bar><%minus><~space>$/E502/;
	$multikey =~ s/^<!M><%less><%bar><%slash>$/E503/;
	$multikey =~ s/^<!M><%less><%bar><%slash><%underscore>$/E504/;
	$multikey =~ s/^<!M><%less><%bar><%slash><~nbspace>$/E505/;
	$multikey =~ s/^<!M><%less><%bar><%slash><~space>$/E506/;
	$multikey =~ s/^<!M><%less><%bar><%underscore>$/E507/;
	$multikey =~ s/^<!M><%less><%bar><%underscore><%slash>$/E508/;
	$multikey =~ s/^<!M><%less><%bar><%underscore><~nbspace>$/E509/;
	$multikey =~ s/^<!M><%less><%bar><%underscore><~space>$/E50A/;
	$multikey =~ s/^<!M><%less><%bar><~nbspace>$/E50B/;
	$multikey =~ s/^<!M><%less><%bar><~space>$/E50C/;
	$multikey =~ s/^<!M><%less><%bracketleft>$/E50D/;
	$multikey =~ s/^<!M><%less><%bracketleft><%greater>$/E50E/;
	$multikey =~ s/^<!M><%less><%bracketleft><%hash>$/E50F/;
	$multikey =~ s/^<!M><%less><%bracketleft><%minus>$/E510/;
	$multikey =~ s/^<!M><%less><%bracketleft><%period>$/E511/;
	$multikey =~ s/^<!M><%less><%bracketleft><~nbspace>$/E512/;
	$multikey =~ s/^<!M><%less><%bracketleft><~space>$/E513/;
	$multikey =~ s/^<!M><%less><%bracketright>$/E514/;
	$multikey =~ s/^<!M><%less><%bracketright><%greater>$/E515/;
	$multikey =~ s/^<!M><%less><%bracketright><%hash>$/E516/;
	$multikey =~ s/^<!M><%less><%bracketright><%minus>$/E517/;
	$multikey =~ s/^<!M><%less><%bracketright><%period>$/E518/;
	$multikey =~ s/^<!M><%less><%bracketright><~nbspace>$/E519/;
	$multikey =~ s/^<!M><%less><%bracketright><~space>$/E51A/;
	$multikey =~ s/^<!M><%less><%equal>$/E51B/;
	$multikey =~ s/^<!M><%less><%equal><%bar>$/E51C/;
	$multikey =~ s/^<!M><%less><%equal><%bar><%equal>$/E51D/;
	$multikey =~ s/^<!M><%less><%equal><%bar><%equal><%greater>$/E51E/;
	$multikey =~ s/^<!M><%less><%equal><%bar><%equal><~nbspace>$/E51F/;
	$multikey =~ s/^<!M><%less><%equal><%bar><%equal><~space>$/E520/;
	$multikey =~ s/^<!M><%less><%equal><%bar><~nbspace>$/E521/;
	$multikey =~ s/^<!M><%less><%equal><%bar><~space>$/E522/;
	$multikey =~ s/^<!M><%less><%equal><%equal>$/E523/;
	$multikey =~ s/^<!M><%less><%equal><%equal><%bar>$/E524/;
	$multikey =~ s/^<!M><%less><%equal><%equal><%greater>$/E525/;
	$multikey =~ s/^<!M><%less><%equal><%equal><~nbspace>$/E526/;
	$multikey =~ s/^<!M><%less><%equal><%equal><~space>$/E527/;
	$multikey =~ s/^<!M><%less><%equal><%grave>$/E528/;
	$multikey =~ s/^<!M><%less><%equal><%greater>$/E529/;
	$multikey =~ s/^<!M><%less><%equal><%slash>$/E52A/;
	$multikey =~ s/^<!M><%less><%equal><%slash><%greater>$/E52B/;
	$multikey =~ s/^<!M><%less><%equal><%slash><~nbspace>$/E52C/;
	$multikey =~ s/^<!M><%less><%equal><%slash><~space>$/E52D/;
	$multikey =~ s/^<!M><%less><%equal><~nbspace>$/E52E/;
	$multikey =~ s/^<!M><%less><%equal><~space>$/E52F/;
	$multikey =~ s/^<!M><%less><%exclam>$/E530/;
	$multikey =~ s/^<!M><%less><%exclam><%bar>$/E531/;
	$multikey =~ s/^<!M><%less><%exclam><%bar><%exclam>$/E532/;
	$multikey =~ s/^<!M><%less><%exclam><%bar><~nbspace>$/E533/;
	$multikey =~ s/^<!M><%less><%exclam><%bar><~space>$/E534/;
	$multikey =~ s/^<!M><%less><%exclam><%equal>$/E535/;
	$multikey =~ s/^<!M><%less><%exclam><%exclam>$/E536/;
	$multikey =~ s/^<!M><%less><%exclam><%greater>$/E537/;
	$multikey =~ s/^<!M><%less><%exclam><%greater><%bar>$/E538/;
	$multikey =~ s/^<!M><%less><%exclam><%greater><%equal>$/E539/;
	$multikey =~ s/^<!M><%less><%exclam><%greater><2>$/E53A/;
	$multikey =~ s/^<!M><%less><%exclam><%greater><~nbspace>$/E53B/;
	$multikey =~ s/^<!M><%less><%exclam><%greater><~space>$/E53C/;
	$multikey =~ s/^<!M><%less><%exclam><%less>$/E53D/;
	$multikey =~ s/^<!M><%less><%exclam><%less><%exclam>$/E53E/;
	$multikey =~ s/^<!M><%less><%exclam><2>$/E53F/;
	$multikey =~ s/^<!M><%less><%exclam><3>$/E540/;
	$multikey =~ s/^<!M><%less><%exclam><4>$/E541/;
	$multikey =~ s/^<!M><%less><%exclam><~nbspace>$/E542/;
	$multikey =~ s/^<!M><%less><%exclam><~space>$/E543/;
	$multikey =~ s/^<!M><%less><%greater>$/E544/;
	$multikey =~ s/^<!M><%less><%greater><%equal>$/E545/;
	$multikey =~ s/^<!M><%less><%greater><%less>$/E546/;
	$multikey =~ s/^<!M><%less><%greater><%less><%minus>$/E547/;
	$multikey =~ s/^<!M><%less><%greater><%less><%minus><%bar>$/E548/;
	$multikey =~ s/^<!M><%less><%greater><%less><%minus><~nbspace>$/E549/;
	$multikey =~ s/^<!M><%less><%greater><%less><%minus><~space>$/E54A/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft>$/E54B/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft><%parenright>$/E54C/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft><%parenright><%minus>$/E54D/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft><%parenright><~nbspace>$/E54E/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft><%parenright><~space>$/E54F/;
	$multikey =~ s/^<!M><%less><%greater><%parenright>$/E550/;
	$multikey =~ s/^<!M><%less><%greater><%parenright><%parenleft>$/E551/;
	$multikey =~ s/^<!M><%less><%greater><%parenright><%parenleft><%minus>$/E552/;
	$multikey =~ s/^<!M><%less><%greater><%parenright><%parenleft><~nbspace>$/E553/;
	$multikey =~ s/^<!M><%less><%greater><%parenright><%parenleft><~space>$/E554/;
	$multikey =~ s/^<!M><%less><%greater><%slash>$/E555/;
	$multikey =~ s/^<!M><%less><%greater><~nbspace>$/E556/;
	$multikey =~ s/^<!M><%less><%greater><~space>$/E557/;
	$multikey =~ s/^<!M><%less><%hash>$/E558/;
	$multikey =~ s/^<!M><%less><%hash><%greater>$/E559/;
	$multikey =~ s/^<!M><%less><%hash><%greater><%exclam>$/E55A/;
	$multikey =~ s/^<!M><%less><%hash><%greater><~nbspace>$/E55B/;
	$multikey =~ s/^<!M><%less><%hash><%greater><~space>$/E55C/;
	$multikey =~ s/^<!M><%less><%less>$/E55D/;
	$multikey =~ s/^<!M><%less><%less><%bar>$/E55E/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar>$/E55F/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar><%minus>$/E560/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar><%minus><%less>$/E561/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar><%minus><~nbspace>$/E562/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar><%minus><~space>$/E563/;
	$multikey =~ s/^<!M><%less><%less><%bar><%minus>$/E564/;
	$multikey =~ s/^<!M><%less><%less><%bar><%minus><%less>$/E565/;
	$multikey =~ s/^<!M><%less><%less><%bar><%minus><~nbspace>$/E566/;
	$multikey =~ s/^<!M><%less><%less><%bar><%minus><~space>$/E567/;
	$multikey =~ s/^<!M><%less><%less><%bracketleft>$/E568/;
	$multikey =~ s/^<!M><%less><%less><%bracketright>$/E569/;
	$multikey =~ s/^<!M><%less><%less><%exclam>$/E56A/;
	$multikey =~ s/^<!M><%less><%less><%exclam><o>$/E56B/;
	$multikey =~ s/^<!M><%less><%less><%exclam><~nbspace>$/E56C/;
	$multikey =~ s/^<!M><%less><%less><%exclam><~space>$/E56D/;
	$multikey =~ s/^<!M><%less><%less><%minus>$/E56E/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar>$/E56F/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar>$/E570/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar><%minus>$/E571/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar><%minus><%less>$/E572/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar><%minus><~nbspace>$/E573/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar><%minus><~space>$/E574/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%minus>$/E575/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%minus><%less>$/E576/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%minus><~nbspace>$/E577/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%minus><~space>$/E578/;
	$multikey =~ s/^<!M><%less><%less><%minus><%less>$/E579/;
	$multikey =~ s/^<!M><%less><%less><%minus><0>$/E57A/;
	$multikey =~ s/^<!M><%less><%less><%minus><~nbspace>$/E57B/;
	$multikey =~ s/^<!M><%less><%less><%minus><~space>$/E57C/;
	$multikey =~ s/^<!M><%less><%less><%parenleft>$/E57D/;
	$multikey =~ s/^<!M><%less><%less><%parenright>$/E57E/;
	$multikey =~ s/^<!M><%less><%minus>$/E57F/;
	$multikey =~ s/^<!M><%less><%minus><%bar>$/E580/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar>$/E581/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus>$/E582/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus><%greater>$/E583/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus><%less>$/E584/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus><~nbspace>$/E585/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus><~space>$/E586/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><~nbspace>$/E587/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><~space>$/E588/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%greater>$/E589/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus>$/E58A/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus><%greater>$/E58B/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus><%less>$/E58C/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus><~nbspace>$/E58D/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus><~space>$/E58E/;
	$multikey =~ s/^<!M><%less><%minus><%bar><~nbspace>$/E58F/;
	$multikey =~ s/^<!M><%less><%minus><%bar><~space>$/E590/;
	$multikey =~ s/^<!M><%less><%minus><%comma>$/E591/;
	$multikey =~ s/^<!M><%less><%minus><%comma><%exclam>$/E592/;
	$multikey =~ s/^<!M><%less><%minus><%comma><%minus>$/E593/;
	$multikey =~ s/^<!M><%less><%minus><%exclam>$/E594/;
	$multikey =~ s/^<!M><%less><%minus><%greater>$/E595/;
	$multikey =~ s/^<!M><%less><%minus><%less>$/E596/;
	$multikey =~ s/^<!M><%less><%minus><%less><%minus>$/E597/;
	$multikey =~ s/^<!M><%less><%minus><%less><%minus><%less>$/E598/;
	$multikey =~ s/^<!M><%less><%minus><%less><%minus><~nbspace>$/E599/;
	$multikey =~ s/^<!M><%less><%minus><%less><%minus><~space>$/E59A/;
	$multikey =~ s/^<!M><%less><%minus><%less><~nbspace>$/E59B/;
	$multikey =~ s/^<!M><%less><%minus><%less><~space>$/E59C/;
	$multikey =~ s/^<!M><%less><%minus><%minus>$/E59D/;
	$multikey =~ s/^<!M><%less><%minus><%minus><%bar>$/E59E/;
	$multikey =~ s/^<!M><%less><%minus><%minus><%greater>$/E59F/;
	$multikey =~ s/^<!M><%less><%minus><%minus><~nbspace>$/E5A0/;
	$multikey =~ s/^<!M><%less><%minus><%minus><~space>$/E5A1/;
	$multikey =~ s/^<!M><%less><%minus><%parenright>$/E5A2/;
	$multikey =~ s/^<!M><%less><%minus><%period>$/E5A3/;
	$multikey =~ s/^<!M><%less><%minus><%plus>$/E5A4/;
	$multikey =~ s/^<!M><%less><%minus><%slash>$/E5A5/;
	$multikey =~ s/^<!M><%less><%minus><%slash><%minus>$/E5A6/;
	$multikey =~ s/^<!M><%less><%minus><%slash><~nbspace>$/E5A7/;
	$multikey =~ s/^<!M><%less><%minus><%slash><~space>$/E5A8/;
	$multikey =~ s/^<!M><%less><%minus><%tilde>$/E5A9/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%backslash>$/E5AA/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%tilde>$/E5AB/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%tilde><%backslash>$/E5AC/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%tilde><~nbspace>$/E5AD/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%tilde><~space>$/E5AE/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><~nbspace>$/E5AF/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><~space>$/E5B0/;
	$multikey =~ s/^<!M><%less><%minus><%underscore>$/E5B1/;
	$multikey =~ s/^<!M><%less><%minus><0>$/E5B2/;
	$multikey =~ s/^<!M><%less><%minus><0><%minus>$/E5B3/;
	$multikey =~ s/^<!M><%less><%minus><0><%minus><0>$/E5B4/;
	$multikey =~ s/^<!M><%less><%minus><0><%minus><~nbspace>$/E5B5/;
	$multikey =~ s/^<!M><%less><%minus><0><%minus><~space>$/E5B6/;
	$multikey =~ s/^<!M><%less><%minus><3>$/E5B7/;
	$multikey =~ s/^<!M><%less><%minus><4>$/E5B8/;
	$multikey =~ s/^<!M><%less><%minus><c>$/E5B9/;
	$multikey =~ s/^<!M><%less><%minus><o>$/E5BA/;
	$multikey =~ s/^<!M><%less><%minus><O>$/E5BB/;
	$multikey =~ s/^<!M><%less><%minus><O><%minus>$/E5BC/;
	$multikey =~ s/^<!M><%less><%minus><o><%minus>$/E5BD/;
	$multikey =~ s/^<!M><%less><%minus><o><%minus><%greater>$/E5BE/;
	$multikey =~ s/^<!M><%less><%minus><o><%minus><~nbspace>$/E5BF/;
	$multikey =~ s/^<!M><%less><%minus><o><%minus><~space>$/E5C0/;
	$multikey =~ s/^<!M><%less><%minus><o><%plus>$/E5C1/;
	$multikey =~ s/^<!M><%less><%minus><O><%plus>$/E5C2/;
	$multikey =~ s/^<!M><%less><%minus><O><%slash>$/E5C3/;
	$multikey =~ s/^<!M><%less><%minus><o><~nbspace>$/E5C4/;
	$multikey =~ s/^<!M><%less><%minus><o><~space>$/E5C5/;
	$multikey =~ s/^<!M><%less><%minus><x>$/E5C6/;
	$multikey =~ s/^<!M><%less><%minus><~nbspace>$/E5C7/;
	$multikey =~ s/^<!M><%less><%minus><~space>$/E5C8/;
	$multikey =~ s/^<!M><%less><%parenleft>$/E5C9/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright>$/E5CA/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%bracketleft>$/E5CB/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%bracketright>$/E5CC/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%equal>$/E5CD/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%equal><%slash>$/E5CE/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%equal><~nbspace>$/E5CF/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%equal><~space>$/E5D0/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%slash>$/E5D1/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde>$/E5D2/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%slash>$/E5D3/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%tilde>$/E5D4/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%tilde><%slash>$/E5D5/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%tilde><~nbspace>$/E5D6/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%tilde><~space>$/E5D7/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><~nbspace>$/E5D8/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><~space>$/E5D9/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%underscore>$/E5DA/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%underscore><%slash>$/E5DB/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%underscore><~nbspace>$/E5DC/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%underscore><~space>$/E5DD/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><~nbspace>$/E5DE/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><~space>$/E5DF/;
	$multikey =~ s/^<!M><%less><%parenleft><%plus>$/E5E0/;
	$multikey =~ s/^<!M><%less><%parenleft><~nbspace>$/E5E1/;
	$multikey =~ s/^<!M><%less><%parenleft><~space>$/E5E2/;
	$multikey =~ s/^<!M><%less><%parenright>$/E5E3/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft>$/E5E4/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%bracketleft>$/E5E5/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%bracketright>$/E5E6/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%equal>$/E5E7/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%equal><%slash>$/E5E8/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%equal><~nbspace>$/E5E9/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%equal><~space>$/E5EA/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%slash>$/E5EB/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde>$/E5EC/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%slash>$/E5ED/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%tilde>$/E5EE/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%tilde><%slash>$/E5EF/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%tilde><~nbspace>$/E5F0/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%tilde><~space>$/E5F1/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><~nbspace>$/E5F2/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><~space>$/E5F3/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%underscore>$/E5F4/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%underscore><%slash>$/E5F5/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%underscore><~nbspace>$/E5F6/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%underscore><~space>$/E5F7/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><~nbspace>$/E5F8/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><~space>$/E5F9/;
	$multikey =~ s/^<!M><%less><%parenright><%parenright>$/E5FA/;
	$multikey =~ s/^<!M><%less><%parenright><%underscore>$/E5FB/;
	$multikey =~ s/^<!M><%less><%period>$/E5FC/;
	$multikey =~ s/^<!M><%less><%period><%greater>$/E5FD/;
	$multikey =~ s/^<!M><%less><%period><%period>$/E5FE/;
	$multikey =~ s/^<!M><%less><%period><%underscore>$/E5FF/;
	$multikey =~ s/^<!M><%less><%period><~nbspace>$/E600/;
	$multikey =~ s/^<!M><%less><%period><~space>$/E601/;
	$multikey =~ s/^<!M><%less><%slash>$/E602/;
	$multikey =~ s/^<!M><%less><%slash><%equal>$/E603/;
	$multikey =~ s/^<!M><%less><%slash><%greater>$/E604/;
	$multikey =~ s/^<!M><%less><%slash><%parenleft>$/E605/;
	$multikey =~ s/^<!M><%less><%slash><%parenright>$/E606/;
	$multikey =~ s/^<!M><%less><%slash><%tilde>$/E607/;
	$multikey =~ s/^<!M><%less><%slash><%underscore>$/E608/;
	$multikey =~ s/^<!M><%less><%slash><2>$/E609/;
	$multikey =~ s/^<!M><%less><%slash><~nbspace>$/E60A/;
	$multikey =~ s/^<!M><%less><%slash><~space>$/E60B/;
	$multikey =~ s/^<!M><%less><%tilde>$/E60C/;
	$multikey =~ s/^<!M><%less><%tilde><%greater>$/E60D/;
	$multikey =~ s/^<!M><%less><%tilde><%minus>$/E60E/;
	$multikey =~ s/^<!M><%less><%tilde><%slash>$/E60F/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde>$/E610/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde><%slash>$/E611/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde><%tilde>$/E612/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde><~nbspace>$/E613/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde><~space>$/E614/;
	$multikey =~ s/^<!M><%less><%tilde><%underscore>$/E615/;
	$multikey =~ s/^<!M><%less><%tilde><~nbspace>$/E616/;
	$multikey =~ s/^<!M><%less><%tilde><~space>$/E617/;
	$multikey =~ s/^<!M><%less><%underscore>$/E618/;
	$multikey =~ s/^<!M><%less><%underscore><%grave>$/E619/;
	$multikey =~ s/^<!M><%less><%underscore><%greater>$/E61A/;
	$multikey =~ s/^<!M><%less><%underscore><%greater><%underscore>$/E61B/;
	$multikey =~ s/^<!M><%less><%underscore><%greater><~nbspace>$/E61C/;
	$multikey =~ s/^<!M><%less><%underscore><%greater><~space>$/E61D/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft>$/E61E/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft><%parenright>$/E61F/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft><%parenright><%slash>$/E620/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft><%parenright><~nbspace>$/E621/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft><%parenright><~space>$/E622/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright>$/E623/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright><%parenleft>$/E624/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright><%parenleft><%slash>$/E625/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright><%parenleft><~nbspace>$/E626/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright><%parenleft><~space>$/E627/;
	$multikey =~ s/^<!M><%less><%underscore><%period>$/E628/;
	$multikey =~ s/^<!M><%less><%underscore><%slash>$/E629/;
	$multikey =~ s/^<!M><%less><%underscore><~nbspace>$/E62A/;
	$multikey =~ s/^<!M><%less><%underscore><~space>$/E62B/;
	$multikey =~ s/^<!M><%less><0>$/E62C/;
	$multikey =~ s/^<!M><%less><1>$/E62D/;
	$multikey =~ s/^<!M><%less><2>$/E62E/;
	$multikey =~ s/^<!M><%less><3>$/E62F/;
	$multikey =~ s/^<!M><%less><4>$/E630/;
	$multikey =~ s/^<!M><%less><5>$/E631/;
	$multikey =~ s/^<!M><%less><6>$/E632/;
	$multikey =~ s/^<!M><%less><7>$/E633/;
	$multikey =~ s/^<!M><%less><8>$/E634/;
	$multikey =~ s/^<!M><%less><9>$/E635/;
	$multikey =~ s/^<!M><%minus>$/E636/;
	$multikey =~ s/^<!M><%minus><%apostrophe>$/E637/;
	$multikey =~ s/^<!M><%minus><%apostrophe><%apostrophe>$/E638/;
	$multikey =~ s/^<!M><%minus><%apostrophe><%bar>$/E639/;
	$multikey =~ s/^<!M><%minus><%apostrophe><%grave>$/E63A/;
	$multikey =~ s/^<!M><%minus><%apostrophe><%minus>$/E63B/;
	$multikey =~ s/^<!M><%minus><%apostrophe><~nbspace>$/E63C/;
	$multikey =~ s/^<!M><%minus><%apostrophe><~space>$/E63D/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark>$/E63E/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><%aprightsingquotmark>$/E63F/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><%bar>$/E640/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><%grave>$/E641/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><%minus>$/E642/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><~nbspace>$/E643/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark><~space>$/E644/;
	$multikey =~ s/^<!M><%minus><%backslash>$/E645/;
	$multikey =~ s/^<!M><%minus><%backslash><~nbspace>$/E646/;
	$multikey =~ s/^<!M><%minus><%backslash><~space>$/E647/;
	$multikey =~ s/^<!M><%minus><%bar>$/E648/;
	$multikey =~ s/^<!M><%minus><%bar><%bar>$/E649/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%greater>$/E64A/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%greater><%greater>$/E64B/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%greater><~nbspace>$/E64C/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%greater><~space>$/E64D/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus>$/E64E/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><%greater>$/E64F/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><%greater><%greater>$/E650/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><%greater><~nbspace>$/E651/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><%greater><~space>$/E652/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><~nbspace>$/E653/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><~space>$/E654/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><~nbspace>$/E655/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><~space>$/E656/;
	$multikey =~ s/^<!M><%minus><%bar><%greater>$/E657/;
	$multikey =~ s/^<!M><%minus><%bar><%greater><%greater>$/E658/;
	$multikey =~ s/^<!M><%minus><%bar><%greater><~nbspace>$/E659/;
	$multikey =~ s/^<!M><%minus><%bar><%greater><~space>$/E65A/;
	$multikey =~ s/^<!M><%minus><%bar><%minus>$/E65B/;
	$multikey =~ s/^<!M><%minus><%bar><%minus><%greater>$/E65C/;
	$multikey =~ s/^<!M><%minus><%bar><%minus><%greater><%greater>$/E65D/;
	$multikey =~ s/^<!M><%minus><%bar><%minus><%greater><~nbspace>$/E65E/;
	$multikey =~ s/^<!M><%minus><%bar><%minus><%greater><~space>$/E65F/;
	$multikey =~ s/^<!M><%minus><%bar><o>$/E660/;
	$multikey =~ s/^<!M><%minus><%bar><~nbspace>$/E661/;
	$multikey =~ s/^<!M><%minus><%bar><~space>$/E662/;
	$multikey =~ s/^<!M><%minus><%circum>$/E663/;
	$multikey =~ s/^<!M><%minus><%circum><~nbspace>$/E664/;
	$multikey =~ s/^<!M><%minus><%circum><~space>$/E665/;
	$multikey =~ s/^<!M><%minus><%colon>$/E666/;
	$multikey =~ s/^<!M><%minus><%comma>$/E667/;
	$multikey =~ s/^<!M><%minus><%comma><%exclam>$/E668/;
	$multikey =~ s/^<!M><%minus><%comma><%exclam><%greater>$/E669/;
	$multikey =~ s/^<!M><%minus><%comma><%less>$/E66A/;
	$multikey =~ s/^<!M><%minus><%comma><%less><%exclam>$/E66B/;
	$multikey =~ s/^<!M><%minus><%equal>$/E66C/;
	$multikey =~ s/^<!M><%minus><%equal><%bar>$/E66D/;
	$multikey =~ s/^<!M><%minus><%equal><%bar><%bar>$/E66E/;
	$multikey =~ s/^<!M><%minus><%equal><%bar><%bar><%bar>$/E66F/;
	$multikey =~ s/^<!M><%minus><%equal><%bar><%bar><~nbspace>$/E670/;
	$multikey =~ s/^<!M><%minus><%equal><%bar><%bar><~space>$/E671/;
	$multikey =~ s/^<!M><%minus><%equal><%minus>$/E672/;
	$multikey =~ s/^<!M><%minus><%equal><%slash>$/E673/;
	$multikey =~ s/^<!M><%minus><%equal><%slash><%slash>$/E674/;
	$multikey =~ s/^<!M><%minus><%equal><%slash><~nbspace>$/E675/;
	$multikey =~ s/^<!M><%minus><%equal><%slash><~space>$/E676/;
	$multikey =~ s/^<!M><%minus><%equal><~nbspace>$/E677/;
	$multikey =~ s/^<!M><%minus><%equal><~space>$/E678/;
	$multikey =~ s/^<!M><%minus><%grave>$/E679/;
	$multikey =~ s/^<!M><%minus><%grave><%apostrophe>$/E67A/;
	$multikey =~ s/^<!M><%minus><%grave><%aprightsingquotmark>$/E67B/;
	$multikey =~ s/^<!M><%minus><%grave><%bar>$/E67C/;
	$multikey =~ s/^<!M><%minus><%grave><%grave>$/E67D/;
	$multikey =~ s/^<!M><%minus><%grave><%grave><%minus>$/E67E/;
	$multikey =~ s/^<!M><%minus><%grave><%grave><%minus><%minus>$/E67F/;
	$multikey =~ s/^<!M><%minus><%grave><%grave><%minus><~nbspace>$/E680/;
	$multikey =~ s/^<!M><%minus><%grave><%grave><%minus><~space>$/E681/;
	$multikey =~ s/^<!M><%minus><%grave><%minus>$/E682/;
	$multikey =~ s/^<!M><%minus><%grave><%minus><%apostrophe>$/E683/;
	$multikey =~ s/^<!M><%minus><%grave><%minus><%aprightsingquotmark>$/E684/;
	$multikey =~ s/^<!M><%minus><%grave><%underscore>$/E685/;
	$multikey =~ s/^<!M><%minus><%grave><~nbspace>$/E686/;
	$multikey =~ s/^<!M><%minus><%grave><~space>$/E687/;
	$multikey =~ s/^<!M><%minus><%greater>$/E688/;
	$multikey =~ s/^<!M><%minus><%greater><%bar>$/E689/;
	$multikey =~ s/^<!M><%minus><%greater><%greater>$/E68A/;
	$multikey =~ s/^<!M><%minus><%greater><%greater><~nbspace>$/E68B/;
	$multikey =~ s/^<!M><%minus><%greater><%greater><~space>$/E68C/;
	$multikey =~ s/^<!M><%minus><%greater><%less>$/E68D/;
	$multikey =~ s/^<!M><%minus><%greater><%less><%greater>$/E68E/;
	$multikey =~ s/^<!M><%minus><%greater><%less><%minus>$/E68F/;
	$multikey =~ s/^<!M><%minus><%greater><%less><%parenleft>$/E690/;
	$multikey =~ s/^<!M><%minus><%greater><%less><%parenright>$/E691/;
	$multikey =~ s/^<!M><%minus><%greater><%less><%period>$/E692/;
	$multikey =~ s/^<!M><%minus><%greater><%minus>$/E693/;
	$multikey =~ s/^<!M><%minus><%greater><%minus><%greater>$/E694/;
	$multikey =~ s/^<!M><%minus><%greater><%minus><%greater><%minus>$/E695/;
	$multikey =~ s/^<!M><%minus><%greater><%minus><%greater><~nbspace>$/E696/;
	$multikey =~ s/^<!M><%minus><%greater><%minus><%greater><~space>$/E697/;
	$multikey =~ s/^<!M><%minus><%greater><%plus>$/E698/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde>$/E699/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%backslash>$/E69A/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%tilde>$/E69B/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%tilde><%backslash>$/E69C/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%tilde><~nbspace>$/E69D/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%tilde><~space>$/E69E/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><~nbspace>$/E69F/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><~space>$/E6A0/;
	$multikey =~ s/^<!M><%minus><%greater><3>$/E6A1/;
	$multikey =~ s/^<!M><%minus><%greater><4>$/E6A2/;
	$multikey =~ s/^<!M><%minus><%greater><O>$/E6A3/;
	$multikey =~ s/^<!M><%minus><%greater><~nbspace>$/E6A4/;
	$multikey =~ s/^<!M><%minus><%greater><~space>$/E6A5/;
	$multikey =~ s/^<!M><%minus><%less>$/E6A6/;
	$multikey =~ s/^<!M><%minus><%less><%greater>$/E6A7/;
	$multikey =~ s/^<!M><%minus><%less><%less>$/E6A8/;
	$multikey =~ s/^<!M><%minus><%less><~nbspace>$/E6A9/;
	$multikey =~ s/^<!M><%minus><%less><~space>$/E6AA/;
	$multikey =~ s/^<!M><%minus><%minus>$/E6AB/;
	$multikey =~ s/^<!M><%minus><%minus><%bar>$/E6AC/;
	$multikey =~ s/^<!M><%minus><%minus><%grave>$/E6AD/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave>$/E6AE/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave><%minus>$/E6AF/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave><%minus><%minus>$/E6B0/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave><%minus><~nbspace>$/E6B1/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave><%minus><~space>$/E6B2/;
	$multikey =~ s/^<!M><%minus><%minus><%greater>$/E6B3/;
	$multikey =~ s/^<!M><%minus><%minus><%greater><%less>$/E6B4/;
	$multikey =~ s/^<!M><%minus><%minus><%greater><~nbspace>$/E6B5/;
	$multikey =~ s/^<!M><%minus><%minus><%greater><~space>$/E6B6/;
	$multikey =~ s/^<!M><%minus><%minus><%minus>$/E6B7/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%bar>$/E6B8/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave>$/E6B9/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave>$/E6BA/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave><%minus>$/E6BB/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave><%minus><%minus>$/E6BC/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave><%minus><~nbspace>$/E6BD/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave><%minus><~space>$/E6BE/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%greater>$/E6BF/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%greater><%less>$/E6C0/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%minus>$/E6C1/;
	$multikey =~ s/^<!M><%minus><%minus><A>$/E6C2/;
	$multikey =~ s/^<!M><%minus><%minus><a>$/E6C3/;
	$multikey =~ s/^<!M><%minus><%minus><v>$/E6C4/;
	$multikey =~ s/^<!M><%minus><%minus><V>$/E6C5/;
	$multikey =~ s/^<!M><%minus><%minus><v><%percent>$/E6C6/;
	$multikey =~ s/^<!M><%minus><%minus><V><%percent>$/E6C7/;
	$multikey =~ s/^<!M><%minus><%minus><v><~nbspace>$/E6C8/;
	$multikey =~ s/^<!M><%minus><%minus><V><~nbspace>$/E6C9/;
	$multikey =~ s/^<!M><%minus><%minus><v><~space>$/E6CA/;
	$multikey =~ s/^<!M><%minus><%minus><V><~space>$/E6CB/;
	$multikey =~ s/^<!M><%minus><%parenleft>$/E6CC/;
	$multikey =~ s/^<!M><%minus><%parenleft><%less>$/E6CD/;
	$multikey =~ s/^<!M><%minus><%parenleft><%parenright>$/E6CE/;
	$multikey =~ s/^<!M><%minus><%parenright>$/E6CF/;
	$multikey =~ s/^<!M><%minus><%parenright><%parenleft>$/E6D0/;
	$multikey =~ s/^<!M><%minus><%parenright><%slash>$/E6D1/;
	$multikey =~ s/^<!M><%minus><%parenright><%slash><%greater>$/E6D2/;
	$multikey =~ s/^<!M><%minus><%parenright><%slash><~nbspace>$/E6D3/;
	$multikey =~ s/^<!M><%minus><%parenright><%slash><~space>$/E6D4/;
	$multikey =~ s/^<!M><%minus><%period>$/E6D5/;
	$multikey =~ s/^<!M><%minus><%period><~nbspace>$/E6D6/;
	$multikey =~ s/^<!M><%minus><%period><~space>$/E6D7/;
	$multikey =~ s/^<!M><%minus><%plus>$/E6D8/;
	$multikey =~ s/^<!M><%minus><%slash>$/E6D9/;
	$multikey =~ s/^<!M><%minus><%slash><%bar>$/E6DA/;
	$multikey =~ s/^<!M><%minus><%slash><%slash>$/E6DB/;
	$multikey =~ s/^<!M><%minus><%slash><s>$/E6DC/;
	$multikey =~ s/^<!M><%minus><%slash><~nbspace>$/E6DD/;
	$multikey =~ s/^<!M><%minus><%slash><~space>$/E6DE/;
	$multikey =~ s/^<!M><%minus><%tilde>$/E6DF/;
	$multikey =~ s/^<!M><%minus><%underscore>$/E6E0/;
	$multikey =~ s/^<!M><%minus><%underscore><~nbspace>$/E6E1/;
	$multikey =~ s/^<!M><%minus><%underscore><~space>$/E6E2/;
	$multikey =~ s/^<!M><%minus><0>$/E6E3/;
	$multikey =~ s/^<!M><%minus><0><%minus>$/E6E4/;
	$multikey =~ s/^<!M><%minus><0><%minus><%greater>$/E6E5/;
	$multikey =~ s/^<!M><%minus><0><%minus><0>$/E6E6/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus>$/E6E7/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus><%greater>$/E6E8/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus><%greater><%greater>$/E6E9/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus><%greater><~nbspace>$/E6EA/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus><%greater><~space>$/E6EB/;
	$multikey =~ s/^<!M><%minus><x>$/E6EC/;
	$multikey =~ s/^<!M><%minus><x><%colon>$/E6ED/;
	$multikey =~ s/^<!M><%minus><x><%minus>$/E6EE/;
	$multikey =~ s/^<!M><%parenleft>$/E6EF/;
	$multikey =~ s/^<!M><%parenleft><%backslash>$/E6F0/;
	$multikey =~ s/^<!M><%parenleft><%bracketleft>$/E6F1/;
	$multikey =~ s/^<!M><%parenleft><%circum>$/E6F2/;
	$multikey =~ s/^<!M><%parenleft><%equal>$/E6F3/;
	$multikey =~ s/^<!M><%parenleft><%greater>$/E6F4/;
	$multikey =~ s/^<!M><%parenleft><%greater><%minus>$/E6F5/;
	$multikey =~ s/^<!M><%parenleft><%greater><%parenleft>$/E6F6/;
	$multikey =~ s/^<!M><%parenleft><%greater><%underscore>$/E6F7/;
	$multikey =~ s/^<!M><%parenleft><%greater><~nbspace>$/E6F8/;
	$multikey =~ s/^<!M><%parenleft><%greater><~space>$/E6F9/;
	$multikey =~ s/^<!M><%parenleft><%less>$/E6FA/;
	$multikey =~ s/^<!M><%parenleft><%less><~nbspace>$/E6FB/;
	$multikey =~ s/^<!M><%parenleft><%less><~space>$/E6FC/;
	$multikey =~ s/^<!M><%parenleft><%minus>$/E6FD/;
	$multikey =~ s/^<!M><%parenleft><%minus><%equal>$/E6FE/;
	$multikey =~ s/^<!M><%parenleft><%minus><%greater>$/E6FF/;
	$multikey =~ s/^<!M><%parenleft><%minus><~nbspace>$/E700/;
	$multikey =~ s/^<!M><%parenleft><%minus><~space>$/E701/;
	$multikey =~ s/^<!M><%parenleft><%parenleft>$/E702/;
	$multikey =~ s/^<!M><%parenleft><%parenleft><%bracketleft>$/E703/;
	$multikey =~ s/^<!M><%parenleft><%parenleft><%bracketright>$/E704/;
	$multikey =~ s/^<!M><%parenleft><%parenleft><%greater>$/E705/;
	$multikey =~ s/^<!M><%parenleft><%parenright>$/E706/;
	$multikey =~ s/^<!M><%parenleft><%parenright><%minus>$/E707/;
	$multikey =~ s/^<!M><%parenleft><%parenright><%slash>$/E708/;
	$multikey =~ s/^<!M><%parenleft><%parenright><c>$/E709/;
	$multikey =~ s/^<!M><%parenleft><%parenright><C>$/E70A/;
	$multikey =~ s/^<!M><%parenleft><%parenright><p>$/E70B/;
	$multikey =~ s/^<!M><%parenleft><%parenright><P>$/E70C/;
	$multikey =~ s/^<!M><%parenleft><%parenright><r>$/E70D/;
	$multikey =~ s/^<!M><%parenleft><%parenright><R>$/E70E/;
	$multikey =~ s/^<!M><%parenleft><%parenright><~nbspace>$/E70F/;
	$multikey =~ s/^<!M><%parenleft><%parenright><~space>$/E710/;
	$multikey =~ s/^<!M><%parenleft><%plus>$/E711/;
	$multikey =~ s/^<!M><%parenleft><%slash>$/E712/;
	$multikey =~ s/^<!M><%parenleft><%underscore>$/E713/;
	$multikey =~ s/^<!M><%parenleft><%underscore><%parenright>$/E714/;
	$multikey =~ s/^<!M><%parenleft><%underscore><~nbspace>$/E715/;
	$multikey =~ s/^<!M><%parenleft><%underscore><~space>$/E716/;
	$multikey =~ s/^<!M><%parenleft><0>$/E717/;
	$multikey =~ s/^<!M><%parenleft><0><%parenright>$/E718/;
	$multikey =~ s/^<!M><%parenleft><0><0>$/E719/;
	$multikey =~ s/^<!M><%parenleft><0><0><1>$/E71A/;
	$multikey =~ s/^<!M><%parenleft><0><0><1><1>$/E71B/;
	$multikey =~ s/^<!M><%parenleft><0><1>$/E71C/;
	$multikey =~ s/^<!M><%parenleft><0><1><1>$/E71D/;
	$multikey =~ s/^<!M><%parenleft><0><1><1><0>$/E71E/;
	$multikey =~ s/^<!M><%parenleft><1>$/E71F/;
	$multikey =~ s/^<!M><%parenleft><1><%parenright>$/E720/;
	$multikey =~ s/^<!M><%parenleft><1><0>$/E721/;
	$multikey =~ s/^<!M><%parenleft><1><0><%parenright>$/E722/;
	$multikey =~ s/^<!M><%parenleft><1><0><0>$/E723/;
	$multikey =~ s/^<!M><%parenleft><1><0><0><1>$/E724/;
	$multikey =~ s/^<!M><%parenleft><1><1>$/E725/;
	$multikey =~ s/^<!M><%parenleft><1><1><%parenright>$/E726/;
	$multikey =~ s/^<!M><%parenleft><1><1><0>$/E727/;
	$multikey =~ s/^<!M><%parenleft><1><1><0><0>$/E728/;
	$multikey =~ s/^<!M><%parenleft><1><2>$/E729/;
	$multikey =~ s/^<!M><%parenleft><1><3>$/E72A/;
	$multikey =~ s/^<!M><%parenleft><1><4>$/E72B/;
	$multikey =~ s/^<!M><%parenleft><1><5>$/E72C/;
	$multikey =~ s/^<!M><%parenleft><1><6>$/E72D/;
	$multikey =~ s/^<!M><%parenleft><1><7>$/E72E/;
	$multikey =~ s/^<!M><%parenleft><1><8>$/E72F/;
	$multikey =~ s/^<!M><%parenleft><1><9>$/E730/;
	$multikey =~ s/^<!M><%parenleft><2>$/E731/;
	$multikey =~ s/^<!M><%parenleft><2><%parenright>$/E732/;
	$multikey =~ s/^<!M><%parenleft><2><0>$/E733/;
	$multikey =~ s/^<!M><%parenleft><2><1>$/E734/;
	$multikey =~ s/^<!M><%parenleft><2><2>$/E735/;
	$multikey =~ s/^<!M><%parenleft><2><3>$/E736/;
	$multikey =~ s/^<!M><%parenleft><2><4>$/E737/;
	$multikey =~ s/^<!M><%parenleft><2><5>$/E738/;
	$multikey =~ s/^<!M><%parenleft><2><6>$/E739/;
	$multikey =~ s/^<!M><%parenleft><2><7>$/E73A/;
	$multikey =~ s/^<!M><%parenleft><2><8>$/E73B/;
	$multikey =~ s/^<!M><%parenleft><2><9>$/E73C/;
	$multikey =~ s/^<!M><%parenleft><3>$/E73D/;
	$multikey =~ s/^<!M><%parenleft><3><%parenright>$/E73E/;
	$multikey =~ s/^<!M><%parenleft><3><0>$/E73F/;
	$multikey =~ s/^<!M><%parenleft><3><1>$/E740/;
	$multikey =~ s/^<!M><%parenleft><3><2>$/E741/;
	$multikey =~ s/^<!M><%parenleft><3><3>$/E742/;
	$multikey =~ s/^<!M><%parenleft><3><4>$/E743/;
	$multikey =~ s/^<!M><%parenleft><3><5>$/E744/;
	$multikey =~ s/^<!M><%parenleft><3><6>$/E745/;
	$multikey =~ s/^<!M><%parenleft><3><7>$/E746/;
	$multikey =~ s/^<!M><%parenleft><3><8>$/E747/;
	$multikey =~ s/^<!M><%parenleft><3><9>$/E748/;
	$multikey =~ s/^<!M><%parenleft><4>$/E749/;
	$multikey =~ s/^<!M><%parenleft><4><%parenright>$/E74A/;
	$multikey =~ s/^<!M><%parenleft><4><0>$/E74B/;
	$multikey =~ s/^<!M><%parenleft><4><1>$/E74C/;
	$multikey =~ s/^<!M><%parenleft><4><2>$/E74D/;
	$multikey =~ s/^<!M><%parenleft><4><3>$/E74E/;
	$multikey =~ s/^<!M><%parenleft><4><4>$/E74F/;
	$multikey =~ s/^<!M><%parenleft><4><5>$/E750/;
	$multikey =~ s/^<!M><%parenleft><4><6>$/E751/;
	$multikey =~ s/^<!M><%parenleft><4><7>$/E752/;
	$multikey =~ s/^<!M><%parenleft><4><8>$/E753/;
	$multikey =~ s/^<!M><%parenleft><4><9>$/E754/;
	$multikey =~ s/^<!M><%parenleft><5>$/E755/;
	$multikey =~ s/^<!M><%parenleft><5><%parenright>$/E756/;
	$multikey =~ s/^<!M><%parenleft><5><0>$/E757/;
	$multikey =~ s/^<!M><%parenleft><6>$/E758/;
	$multikey =~ s/^<!M><%parenleft><7>$/E759/;
	$multikey =~ s/^<!M><%parenleft><8>$/E75A/;
	$multikey =~ s/^<!M><%parenleft><9>$/E75B/;
	$multikey =~ s/^<!M><%parenleft><x>$/E75C/;
	$multikey =~ s/^<!M><%parenright>$/E75D/;
	$multikey =~ s/^<!M><%parenright><%bracketright>$/E75E/;
	$multikey =~ s/^<!M><%parenright><%bracketright><~nbspace>$/E75F/;
	$multikey =~ s/^<!M><%parenright><%bracketright><~space>$/E760/;
	$multikey =~ s/^<!M><%parenright><%circum>$/E761/;
	$multikey =~ s/^<!M><%parenright><%circum><~nbspace>$/E762/;
	$multikey =~ s/^<!M><%parenright><%circum><~space>$/E763/;
	$multikey =~ s/^<!M><%parenright><%greater>$/E764/;
	$multikey =~ s/^<!M><%parenright><%less>$/E765/;
	$multikey =~ s/^<!M><%parenright><%less><%parenright>$/E766/;
	$multikey =~ s/^<!M><%parenright><%less><~nbspace>$/E767/;
	$multikey =~ s/^<!M><%parenright><%less><~space>$/E768/;
	$multikey =~ s/^<!M><%parenright><%parenleft>$/E769/;
	$multikey =~ s/^<!M><%parenright><%parenleft><%slash>$/E76A/;
	$multikey =~ s/^<!M><%parenright><%parenleft><~nbspace>$/E76B/;
	$multikey =~ s/^<!M><%parenright><%parenleft><~space>$/E76C/;
	$multikey =~ s/^<!M><%parenright><%parenright>$/E76D/;
	$multikey =~ s/^<!M><%parenright><%parenright><%bracketleft>$/E76E/;
	$multikey =~ s/^<!M><%parenright><%parenright><%bracketright>$/E76F/;
	$multikey =~ s/^<!M><%parenright><%parenright><%less>$/E770/;
	$multikey =~ s/^<!M><%parenright><%underscore>$/E771/;
	$multikey =~ s/^<!M><%parenright><%underscore><%circum>$/E772/;
	$multikey =~ s/^<!M><%parenright><%underscore><%circum><~nbspace>$/E773/;
	$multikey =~ s/^<!M><%parenright><%underscore><%circum><~space>$/E774/;
	$multikey =~ s/^<!M><%parenright><%underscore><~nbspace>$/E775/;
	$multikey =~ s/^<!M><%parenright><%underscore><~space>$/E776/;
	$multikey =~ s/^<!M><%parenright><0>$/E777/;
	$multikey =~ s/^<!M><%parenright><0><0>$/E778/;
	$multikey =~ s/^<!M><%parenright><0><0><0>$/E779/;
	$multikey =~ s/^<!M><%parenright><0><0><0><1>$/E77A/;
	$multikey =~ s/^<!M><%parenright><0><0><0><3>$/E77B/;
	$multikey =~ s/^<!M><%parenright><0><0><1>$/E77C/;
	$multikey =~ s/^<!M><%parenright><0><0><1><0>$/E77D/;
	$multikey =~ s/^<!M><%parenright><0><0><1><1>$/E77E/;
	$multikey =~ s/^<!M><%parenright><0><0><1><2>$/E77F/;
	$multikey =~ s/^<!M><%parenright><0><0><1><3>$/E780/;
	$multikey =~ s/^<!M><%parenright><0><0><2>$/E781/;
	$multikey =~ s/^<!M><%parenright><0><0><2><1>$/E782/;
	$multikey =~ s/^<!M><%parenright><0><0><2><2>$/E783/;
	$multikey =~ s/^<!M><%parenright><0><0><3>$/E784/;
	$multikey =~ s/^<!M><%parenright><0><0><3><0>$/E785/;
	$multikey =~ s/^<!M><%parenright><0><0><3><1>$/E786/;
	$multikey =~ s/^<!M><%parenright><0><0><3><3>$/E787/;
	$multikey =~ s/^<!M><%parenright><0><1>$/E788/;
	$multikey =~ s/^<!M><%parenright><0><1><0>$/E789/;
	$multikey =~ s/^<!M><%parenright><0><1><0><0>$/E78A/;
	$multikey =~ s/^<!M><%parenright><0><1><0><1>$/E78B/;
	$multikey =~ s/^<!M><%parenright><0><1><0><3>$/E78C/;
	$multikey =~ s/^<!M><%parenright><0><1><1>$/E78D/;
	$multikey =~ s/^<!M><%parenright><0><1><1><0>$/E78E/;
	$multikey =~ s/^<!M><%parenright><0><1><1><1>$/E78F/;
	$multikey =~ s/^<!M><%parenright><0><1><1><3>$/E790/;
	$multikey =~ s/^<!M><%parenright><0><1><2>$/E791/;
	$multikey =~ s/^<!M><%parenright><0><1><2><0>$/E792/;
	$multikey =~ s/^<!M><%parenright><0><1><2><1>$/E793/;
	$multikey =~ s/^<!M><%parenright><0><1><3>$/E794/;
	$multikey =~ s/^<!M><%parenright><0><1><3><0>$/E795/;
	$multikey =~ s/^<!M><%parenright><0><1><3><1>$/E796/;
	$multikey =~ s/^<!M><%parenright><0><1><3><3>$/E797/;
	$multikey =~ s/^<!M><%parenright><0><2>$/E798/;
	$multikey =~ s/^<!M><%parenright><0><2><0>$/E799/;
	$multikey =~ s/^<!M><%parenright><0><2><0><2>$/E79A/;
	$multikey =~ s/^<!M><%parenright><0><2><1>$/E79B/;
	$multikey =~ s/^<!M><%parenright><0><2><1><0>$/E79C/;
	$multikey =~ s/^<!M><%parenright><0><2><1><2>$/E79D/;
	$multikey =~ s/^<!M><%parenright><0><2><2>$/E79E/;
	$multikey =~ s/^<!M><%parenright><0><2><2><0>$/E79F/;
	$multikey =~ s/^<!M><%parenright><0><2><2><2>$/E7A0/;
	$multikey =~ s/^<!M><%parenright><0><3>$/E7A1/;
	$multikey =~ s/^<!M><%parenright><0><3><0>$/E7A2/;
	$multikey =~ s/^<!M><%parenright><0><3><0><0>$/E7A3/;
	$multikey =~ s/^<!M><%parenright><0><3><0><1>$/E7A4/;
	$multikey =~ s/^<!M><%parenright><0><3><0><3>$/E7A5/;
	$multikey =~ s/^<!M><%parenright><0><3><1>$/E7A6/;
	$multikey =~ s/^<!M><%parenright><0><3><1><0>$/E7A7/;
	$multikey =~ s/^<!M><%parenright><0><3><1><1>$/E7A8/;
	$multikey =~ s/^<!M><%parenright><0><3><1><3>$/E7A9/;
	$multikey =~ s/^<!M><%parenright><0><3><3>$/E7AA/;
	$multikey =~ s/^<!M><%parenright><0><3><3><0>$/E7AB/;
	$multikey =~ s/^<!M><%parenright><0><3><3><1>$/E7AC/;
	$multikey =~ s/^<!M><%parenright><0><3><3><3>$/E7AD/;
	$multikey =~ s/^<!M><%parenright><1>$/E7AE/;
	$multikey =~ s/^<!M><%parenright><1><0>$/E7AF/;
	$multikey =~ s/^<!M><%parenright><1><0><0>$/E7B0/;
	$multikey =~ s/^<!M><%parenright><1><0><0><0>$/E7B1/;
	$multikey =~ s/^<!M><%parenright><1><0><0><1>$/E7B2/;
	$multikey =~ s/^<!M><%parenright><1><0><0><2>$/E7B3/;
	$multikey =~ s/^<!M><%parenright><1><0><0><3>$/E7B4/;
	$multikey =~ s/^<!M><%parenright><1><0><1>$/E7B5/;
	$multikey =~ s/^<!M><%parenright><1><0><1><0>$/E7B6/;
	$multikey =~ s/^<!M><%parenright><1><0><1><1>$/E7B7/;
	$multikey =~ s/^<!M><%parenright><1><0><1><2>$/E7B8/;
	$multikey =~ s/^<!M><%parenright><1><0><1><3>$/E7B9/;
	$multikey =~ s/^<!M><%parenright><1><0><3>$/E7BA/;
	$multikey =~ s/^<!M><%parenright><1><0><3><0>$/E7BB/;
	$multikey =~ s/^<!M><%parenright><1><0><3><1>$/E7BC/;
	$multikey =~ s/^<!M><%parenright><1><0><3><3>$/E7BD/;
	$multikey =~ s/^<!M><%parenright><1><1>$/E7BE/;
	$multikey =~ s/^<!M><%parenright><1><1><0>$/E7BF/;
	$multikey =~ s/^<!M><%parenright><1><1><0><0>$/E7C0/;
	$multikey =~ s/^<!M><%parenright><1><1><0><1>$/E7C1/;
	$multikey =~ s/^<!M><%parenright><1><1><0><3>$/E7C2/;
	$multikey =~ s/^<!M><%parenright><1><1><1>$/E7C3/;
	$multikey =~ s/^<!M><%parenright><1><1><1><0>$/E7C4/;
	$multikey =~ s/^<!M><%parenright><1><1><1><1>$/E7C5/;
	$multikey =~ s/^<!M><%parenright><1><1><1><3>$/E7C6/;
	$multikey =~ s/^<!M><%parenright><1><1><3>$/E7C7/;
	$multikey =~ s/^<!M><%parenright><1><1><3><0>$/E7C8/;
	$multikey =~ s/^<!M><%parenright><1><1><3><1>$/E7C9/;
	$multikey =~ s/^<!M><%parenright><1><1><3><3>$/E7CA/;
	$multikey =~ s/^<!M><%parenright><1><2>$/E7CB/;
	$multikey =~ s/^<!M><%parenright><1><2><0>$/E7CC/;
	$multikey =~ s/^<!M><%parenright><1><2><0><0>$/E7CD/;
	$multikey =~ s/^<!M><%parenright><1><2><0><2>$/E7CE/;
	$multikey =~ s/^<!M><%parenright><1><2><1>$/E7CF/;
	$multikey =~ s/^<!M><%parenright><1><2><1><0>$/E7D0/;
	$multikey =~ s/^<!M><%parenright><1><2><1><2>$/E7D1/;
	$multikey =~ s/^<!M><%parenright><1><2><d>$/E7D2/;
	$multikey =~ s/^<!M><%parenright><1><3>$/E7D3/;
	$multikey =~ s/^<!M><%parenright><1><3><0>$/E7D4/;
	$multikey =~ s/^<!M><%parenright><1><3><0><0>$/E7D5/;
	$multikey =~ s/^<!M><%parenright><1><3><0><1>$/E7D6/;
	$multikey =~ s/^<!M><%parenright><1><3><0><3>$/E7D7/;
	$multikey =~ s/^<!M><%parenright><1><3><1>$/E7D8/;
	$multikey =~ s/^<!M><%parenright><1><3><1><0>$/E7D9/;
	$multikey =~ s/^<!M><%parenright><1><3><1><1>$/E7DA/;
	$multikey =~ s/^<!M><%parenright><1><3><1><3>$/E7DB/;
	$multikey =~ s/^<!M><%parenright><1><3><3>$/E7DC/;
	$multikey =~ s/^<!M><%parenright><1><3><3><0>$/E7DD/;
	$multikey =~ s/^<!M><%parenright><1><3><3><1>$/E7DE/;
	$multikey =~ s/^<!M><%parenright><1><3><3><3>$/E7DF/;
	$multikey =~ s/^<!M><%parenright><1><d>$/E7E0/;
	$multikey =~ s/^<!M><%parenright><2>$/E7E1/;
	$multikey =~ s/^<!M><%parenright><2><0>$/E7E2/;
	$multikey =~ s/^<!M><%parenright><2><0><0>$/E7E3/;
	$multikey =~ s/^<!M><%parenright><2><0><0><1>$/E7E4/;
	$multikey =~ s/^<!M><%parenright><2><0><0><2>$/E7E5/;
	$multikey =~ s/^<!M><%parenright><2><0><2>$/E7E6/;
	$multikey =~ s/^<!M><%parenright><2><0><2><0>$/E7E7/;
	$multikey =~ s/^<!M><%parenright><2><0><2><1>$/E7E8/;
	$multikey =~ s/^<!M><%parenright><2><0><2><2>$/E7E9/;
	$multikey =~ s/^<!M><%parenright><2><1>$/E7EA/;
	$multikey =~ s/^<!M><%parenright><2><1><0>$/E7EB/;
	$multikey =~ s/^<!M><%parenright><2><1><0><0>$/E7EC/;
	$multikey =~ s/^<!M><%parenright><2><1><0><1>$/E7ED/;
	$multikey =~ s/^<!M><%parenright><2><1><2>$/E7EE/;
	$multikey =~ s/^<!M><%parenright><2><1><2><0>$/E7EF/;
	$multikey =~ s/^<!M><%parenright><2><1><2><1>$/E7F0/;
	$multikey =~ s/^<!M><%parenright><2><1><d>$/E7F1/;
	$multikey =~ s/^<!M><%parenright><2><2>$/E7F2/;
	$multikey =~ s/^<!M><%parenright><2><2><0>$/E7F3/;
	$multikey =~ s/^<!M><%parenright><2><2><0><0>$/E7F4/;
	$multikey =~ s/^<!M><%parenright><2><2><0><2>$/E7F5/;
	$multikey =~ s/^<!M><%parenright><2><2><2>$/E7F6/;
	$multikey =~ s/^<!M><%parenright><2><2><2><0>$/E7F7/;
	$multikey =~ s/^<!M><%parenright><2><2><2><2>$/E7F8/;
	$multikey =~ s/^<!M><%parenright><2><2><h>$/E7F9/;
	$multikey =~ s/^<!M><%parenright><2><2><v>$/E7FA/;
	$multikey =~ s/^<!M><%parenright><2><d>$/E7FB/;
	$multikey =~ s/^<!M><%parenright><2><h>$/E7FC/;
	$multikey =~ s/^<!M><%parenright><2><v>$/E7FD/;
	$multikey =~ s/^<!M><%parenright><3>$/E7FE/;
	$multikey =~ s/^<!M><%parenright><3><0>$/E7FF/;
	$multikey =~ s/^<!M><%parenright><3><0><0>$/E800/;
	$multikey =~ s/^<!M><%parenright><3><0><0><0>$/E801/;
	$multikey =~ s/^<!M><%parenright><3><0><0><1>$/E802/;
	$multikey =~ s/^<!M><%parenright><3><0><0><3>$/E803/;
	$multikey =~ s/^<!M><%parenright><3><0><1>$/E804/;
	$multikey =~ s/^<!M><%parenright><3><0><1><0>$/E805/;
	$multikey =~ s/^<!M><%parenright><3><0><1><1>$/E806/;
	$multikey =~ s/^<!M><%parenright><3><0><1><3>$/E807/;
	$multikey =~ s/^<!M><%parenright><3><0><3>$/E808/;
	$multikey =~ s/^<!M><%parenright><3><0><3><0>$/E809/;
	$multikey =~ s/^<!M><%parenright><3><0><3><1>$/E80A/;
	$multikey =~ s/^<!M><%parenright><3><0><3><3>$/E80B/;
	$multikey =~ s/^<!M><%parenright><3><1>$/E80C/;
	$multikey =~ s/^<!M><%parenright><3><1><0>$/E80D/;
	$multikey =~ s/^<!M><%parenright><3><1><0><0>$/E80E/;
	$multikey =~ s/^<!M><%parenright><3><1><0><1>$/E80F/;
	$multikey =~ s/^<!M><%parenright><3><1><0><3>$/E810/;
	$multikey =~ s/^<!M><%parenright><3><1><1>$/E811/;
	$multikey =~ s/^<!M><%parenright><3><1><1><0>$/E812/;
	$multikey =~ s/^<!M><%parenright><3><1><1><1>$/E813/;
	$multikey =~ s/^<!M><%parenright><3><1><1><3>$/E814/;
	$multikey =~ s/^<!M><%parenright><3><1><3>$/E815/;
	$multikey =~ s/^<!M><%parenright><3><1><3><0>$/E816/;
	$multikey =~ s/^<!M><%parenright><3><1><3><1>$/E817/;
	$multikey =~ s/^<!M><%parenright><3><1><3><3>$/E818/;
	$multikey =~ s/^<!M><%parenright><3><3>$/E819/;
	$multikey =~ s/^<!M><%parenright><3><3><0>$/E81A/;
	$multikey =~ s/^<!M><%parenright><3><3><0><0>$/E81B/;
	$multikey =~ s/^<!M><%parenright><3><3><0><1>$/E81C/;
	$multikey =~ s/^<!M><%parenright><3><3><0><3>$/E81D/;
	$multikey =~ s/^<!M><%parenright><3><3><1>$/E81E/;
	$multikey =~ s/^<!M><%parenright><3><3><1><0>$/E81F/;
	$multikey =~ s/^<!M><%parenright><3><3><1><1>$/E820/;
	$multikey =~ s/^<!M><%parenright><3><3><1><3>$/E821/;
	$multikey =~ s/^<!M><%parenright><3><3><3>$/E822/;
	$multikey =~ s/^<!M><%parenright><3><3><3><0>$/E823/;
	$multikey =~ s/^<!M><%parenright><3><3><3><1>$/E824/;
	$multikey =~ s/^<!M><%parenright><3><3><3><3>$/E825/;
	$multikey =~ s/^<!M><%parenright><3><3><h>$/E826/;
	$multikey =~ s/^<!M><%parenright><3><3><v>$/E827/;
	$multikey =~ s/^<!M><%parenright><3><h>$/E828/;
	$multikey =~ s/^<!M><%parenright><3><v>$/E829/;
	$multikey =~ s/^<!M><%parenright><4>$/E82A/;
	$multikey =~ s/^<!M><%parenright><4><4>$/E82B/;
	$multikey =~ s/^<!M><%parenright><4><4><h>$/E82C/;
	$multikey =~ s/^<!M><%parenright><4><4><v>$/E82D/;
	$multikey =~ s/^<!M><%parenright><4><h>$/E82E/;
	$multikey =~ s/^<!M><%parenright><4><v>$/E82F/;
	$multikey =~ s/^<!M><%period>$/E830/;
	$multikey =~ s/^<!M><%period><%backslash>$/E831/;
	$multikey =~ s/^<!M><%period><%circum>$/E832/;
	$multikey =~ s/^<!M><%period><%colon>$/E833/;
	$multikey =~ s/^<!M><%period><%equal>$/E834/;
	$multikey =~ s/^<!M><%period><%equal><%minus>$/E835/;
	$multikey =~ s/^<!M><%period><%equal><%period>$/E836/;
	$multikey =~ s/^<!M><%period><%equal><%period><%backslash>$/E837/;
	$multikey =~ s/^<!M><%period><%equal><%period><%slash>$/E838/;
	$multikey =~ s/^<!M><%period><%equal><%period><~nbspace>$/E839/;
	$multikey =~ s/^<!M><%period><%equal><%period><~space>$/E83A/;
	$multikey =~ s/^<!M><%period><%equal><~nbspace>$/E83B/;
	$multikey =~ s/^<!M><%period><%equal><~space>$/E83C/;
	$multikey =~ s/^<!M><%period><%greater>$/E83D/;
	$multikey =~ s/^<!M><%period><%greater><%bracketleft>$/E83E/;
	$multikey =~ s/^<!M><%period><%greater><%bracketright>$/E83F/;
	$multikey =~ s/^<!M><%period><%greater><%less>$/E840/;
	$multikey =~ s/^<!M><%period><%greater><%underscore>$/E841/;
	$multikey =~ s/^<!M><%period><%greater><~nbspace>$/E842/;
	$multikey =~ s/^<!M><%period><%greater><~space>$/E843/;
	$multikey =~ s/^<!M><%period><%less>$/E844/;
	$multikey =~ s/^<!M><%period><%minus>$/E845/;
	$multikey =~ s/^<!M><%period><%minus><%equal>$/E846/;
	$multikey =~ s/^<!M><%period><%minus><%period>$/E847/;
	$multikey =~ s/^<!M><%period><%minus><%period><%backslash>$/E848/;
	$multikey =~ s/^<!M><%period><%minus><%period><%slash>$/E849/;
	$multikey =~ s/^<!M><%period><%minus><%period><x>$/E84A/;
	$multikey =~ s/^<!M><%period><%minus><%period><~nbspace>$/E84B/;
	$multikey =~ s/^<!M><%period><%minus><%period><~space>$/E84C/;
	$multikey =~ s/^<!M><%period><%minus><o>$/E84D/;
	$multikey =~ s/^<!M><%period><%minus><~nbspace>$/E84E/;
	$multikey =~ s/^<!M><%period><%minus><~space>$/E84F/;
	$multikey =~ s/^<!M><%period><%period>$/E850/;
	$multikey =~ s/^<!M><%period><%period><%equal>$/E851/;
	$multikey =~ s/^<!M><%period><%period><%greater>$/E852/;
	$multikey =~ s/^<!M><%period><%period><%period>$/E853/;
	$multikey =~ s/^<!M><%period><%period><%period><%backslash>$/E854/;
	$multikey =~ s/^<!M><%period><%period><%period><%bar>$/E855/;
	$multikey =~ s/^<!M><%period><%period><%period><%exclam>$/E856/;
	$multikey =~ s/^<!M><%period><%period><%period><%greater>$/E857/;
	$multikey =~ s/^<!M><%period><%period><%period><%minus>$/E858/;
	$multikey =~ s/^<!M><%period><%period><%period><%period>$/E859/;
	$multikey =~ s/^<!M><%period><%period><%period><%slash>$/E85A/;
	$multikey =~ s/^<!M><%period><%period><%period><%underscore>$/E85B/;
	$multikey =~ s/^<!M><%period><%period><%period><a>$/E85C/;
	$multikey =~ s/^<!M><%period><%period><%period><A>$/E85D/;
	$multikey =~ s/^<!M><%period><%period><%period><v>$/E85E/;
	$multikey =~ s/^<!M><%period><%period><%period><V>$/E85F/;
	$multikey =~ s/^<!M><%period><%period><%underscore>$/E860/;
	$multikey =~ s/^<!M><%period><%plus>$/E861/;
	$multikey =~ s/^<!M><%period><%slash>$/E862/;
	$multikey =~ s/^<!M><%period><%slash><%backslash>$/E863/;
	$multikey =~ s/^<!M><%period><%slash><%period>$/E864/;
	$multikey =~ s/^<!M><%period><%tilde>$/E865/;
	$multikey =~ s/^<!M><%period><%tilde><%equal>$/E866/;
	$multikey =~ s/^<!M><%period><%tilde><%period>$/E867/;
	$multikey =~ s/^<!M><%period><%tilde><~nbspace>$/E868/;
	$multikey =~ s/^<!M><%period><%tilde><~space>$/E869/;
	$multikey =~ s/^<!M><%period><%underscore>$/E86A/;
	$multikey =~ s/^<!M><%plus>$/E86B/;
	$multikey =~ s/^<!M><%plus><%asterisk>$/E86C/;
	$multikey =~ s/^<!M><%plus><%backslash>$/E86D/;
	$multikey =~ s/^<!M><%plus><%circum>$/E86E/;
	$multikey =~ s/^<!M><%plus><%equal>$/E86F/;
	$multikey =~ s/^<!M><%plus><%minus>$/E870/;
	$multikey =~ s/^<!M><%plus><%parenleft>$/E871/;
	$multikey =~ s/^<!M><%plus><%parenleft><%parenright>$/E872/;
	$multikey =~ s/^<!M><%plus><%parenright>$/E873/;
	$multikey =~ s/^<!M><%plus><%parenright><%parenleft>$/E874/;
	$multikey =~ s/^<!M><%plus><%parenright><~nbspace>$/E875/;
	$multikey =~ s/^<!M><%plus><%parenright><~space>$/E876/;
	$multikey =~ s/^<!M><%plus><%period>$/E877/;
	$multikey =~ s/^<!M><%plus><%plus>$/E878/;
	$multikey =~ s/^<!M><%plus><%plus><%plus>$/E879/;
	$multikey =~ s/^<!M><%plus><%tilde>$/E87A/;
	$multikey =~ s/^<!M><%plus><%tilde><~nbspace>$/E87B/;
	$multikey =~ s/^<!M><%plus><%tilde><~space>$/E87C/;
	$multikey =~ s/^<!M><%plus><%underscore>$/E87D/;
	$multikey =~ s/^<!M><%question>$/E87E/;
	$multikey =~ s/^<!M><%question><%equal>$/E87F/;
	$multikey =~ s/^<!M><%question><%exclam>$/E880/;
	$multikey =~ s/^<!M><%question><%greater>$/E881/;
	$multikey =~ s/^<!M><%question><%less>$/E882/;
	$multikey =~ s/^<!M><%question><%question>$/E883/;
	$multikey =~ s/^<!M><%slash>$/E884/;
	$multikey =~ s/^<!M><%slash><%backslash>$/E885/;
	$multikey =~ s/^<!M><%slash><%backslash><%bar>$/E886/;
	$multikey =~ s/^<!M><%slash><%backslash><%greater>$/E887/;
	$multikey =~ s/^<!M><%slash><%backslash><%hash>$/E888/;
	$multikey =~ s/^<!M><%slash><%backslash><%slash>$/E889/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore>$/E88A/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><%minus>$/E88B/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><%plus>$/E88C/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><%underscore>$/E88D/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><o>$/E88E/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><s>$/E88F/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><x>$/E890/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><~nbspace>$/E891/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore><~space>$/E892/;
	$multikey =~ s/^<!M><%slash><%backslash><~nbspace>$/E893/;
	$multikey =~ s/^<!M><%slash><%backslash><~space>$/E894/;
	$multikey =~ s/^<!M><%slash><%bar>$/E895/;
	$multikey =~ s/^<!M><%slash><%bar><%underscore>$/E896/;
	$multikey =~ s/^<!M><%slash><%bar><~nbspace>$/E897/;
	$multikey =~ s/^<!M><%slash><%bar><~space>$/E898/;
	$multikey =~ s/^<!M><%slash><%greater>$/E899/;
	$multikey =~ s/^<!M><%slash><%greater><%backslash>$/E89A/;
	$multikey =~ s/^<!M><%slash><%greater><%equal>$/E89B/;
	$multikey =~ s/^<!M><%slash><%greater><%less>$/E89C/;
	$multikey =~ s/^<!M><%slash><%greater><%parenright>$/E89D/;
	$multikey =~ s/^<!M><%slash><%greater><2>$/E89E/;
	$multikey =~ s/^<!M><%slash><%greater><~nbspace>$/E89F/;
	$multikey =~ s/^<!M><%slash><%greater><~space>$/E8A0/;
	$multikey =~ s/^<!M><%slash><%hash>$/E8A1/;
	$multikey =~ s/^<!M><%slash><%hash><%underscore>$/E8A2/;
	$multikey =~ s/^<!M><%slash><%hash><%underscore><%backslash>$/E8A3/;
	$multikey =~ s/^<!M><%slash><%hash><%underscore><%slash>$/E8A4/;
	$multikey =~ s/^<!M><%slash><%minus>$/E8A5/;
	$multikey =~ s/^<!M><%slash><%minus><%bar>$/E8A6/;
	$multikey =~ s/^<!M><%slash><%minus><%greater>$/E8A7/;
	$multikey =~ s/^<!M><%slash><%parenleft>$/E8A8/;
	$multikey =~ s/^<!M><%slash><%period>$/E8A9/;
	$multikey =~ s/^<!M><%slash><%slash>$/E8AA/;
	$multikey =~ s/^<!M><%slash><%slash><%backslash>$/E8AB/;
	$multikey =~ s/^<!M><%slash><%slash><%backslash><%backslash>$/E8AC/;
	$multikey =~ s/^<!M><%slash><%slash><%backslash><~nbspace>$/E8AD/;
	$multikey =~ s/^<!M><%slash><%slash><%backslash><~space>$/E8AE/;
	$multikey =~ s/^<!M><%slash><%underscore>$/E8AF/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash>$/E8B0/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash><%underscore>$/E8B1/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash><o>$/E8B2/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash><~nbspace>$/E8B3/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash><~space>$/E8B4/;
	$multikey =~ s/^<!M><%slash><%underscore><%bar>$/E8B5/;
	$multikey =~ s/^<!M><%slash><%underscore><%hash>$/E8B6/;
	$multikey =~ s/^<!M><%slash><%underscore><%slash>$/E8B7/;
	$multikey =~ s/^<!M><%slash><%underscore><%underscore>$/E8B8/;
	$multikey =~ s/^<!M><%slash><%underscore><%underscore><%backslash>$/E8B9/;
	$multikey =~ s/^<!M><%slash><%underscore><%underscore><%bar>$/E8BA/;
	$multikey =~ s/^<!M><%tilde>$/E8BB/;
	$multikey =~ s/^<!M><%tilde><%backslash>$/E8BC/;
	$multikey =~ s/^<!M><%tilde><%backslash><%equal>$/E8BD/;
	$multikey =~ s/^<!M><%tilde><%backslash><%greater>$/E8BE/;
	$multikey =~ s/^<!M><%tilde><%backslash><%greater><%equal>$/E8BF/;
	$multikey =~ s/^<!M><%tilde><%backslash><%greater><~nbspace>$/E8C0/;
	$multikey =~ s/^<!M><%tilde><%backslash><%greater><~space>$/E8C1/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less>$/E8C2/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less><%equal>$/E8C3/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less><%minus>$/E8C4/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less><~nbspace>$/E8C5/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less><~space>$/E8C6/;
	$multikey =~ s/^<!M><%tilde><%backslash><%minus>$/E8C7/;
	$multikey =~ s/^<!M><%tilde><%backslash><%underscore>$/E8C8/;
	$multikey =~ s/^<!M><%tilde><%backslash><~nbspace>$/E8C9/;
	$multikey =~ s/^<!M><%tilde><%backslash><~space>$/E8CA/;
	$multikey =~ s/^<!M><%tilde><%bar>$/E8CB/;
	$multikey =~ s/^<!M><%tilde><%bar><%bar>$/E8CC/;
	$multikey =~ s/^<!M><%tilde><%greater>$/E8CD/;
	$multikey =~ s/^<!M><%tilde><%greater><%equal>$/E8CE/;
	$multikey =~ s/^<!M><%tilde><%greater><~nbspace>$/E8CF/;
	$multikey =~ s/^<!M><%tilde><%greater><~space>$/E8D0/;
	$multikey =~ s/^<!M><%tilde><%hash>$/E8D1/;
	$multikey =~ s/^<!M><%tilde><%hash><~nbspace>$/E8D2/;
	$multikey =~ s/^<!M><%tilde><%hash><~space>$/E8D3/;
	$multikey =~ s/^<!M><%tilde><%less>$/E8D4/;
	$multikey =~ s/^<!M><%tilde><%less><%equal>$/E8D5/;
	$multikey =~ s/^<!M><%tilde><%less><%minus>$/E8D6/;
	$multikey =~ s/^<!M><%tilde><%less><~nbspace>$/E8D7/;
	$multikey =~ s/^<!M><%tilde><%less><~space>$/E8D8/;
	$multikey =~ s/^<!M><%tilde><%minus>$/E8D9/;
	$multikey =~ s/^<!M><%tilde><%minus><%greater>$/E8DA/;
	$multikey =~ s/^<!M><%tilde><%minus><%slash>$/E8DB/;
	$multikey =~ s/^<!M><%tilde><%minus><%tilde>$/E8DC/;
	$multikey =~ s/^<!M><%tilde><%minus><~nbspace>$/E8DD/;
	$multikey =~ s/^<!M><%tilde><%minus><~space>$/E8DE/;
	$multikey =~ s/^<!M><%tilde><%plus>$/E8DF/;
	$multikey =~ s/^<!M><%tilde><%plus><~nbspace>$/E8E0/;
	$multikey =~ s/^<!M><%tilde><%plus><~space>$/E8E1/;
	$multikey =~ s/^<!M><%tilde><%slash>$/E8E2/;
	$multikey =~ s/^<!M><%tilde><%slash><%equal>$/E8E3/;
	$multikey =~ s/^<!M><%tilde><%tilde>$/E8E4/;
	$multikey =~ s/^<!M><%tilde><%tilde><%greater>$/E8E5/;
	$multikey =~ s/^<!M><%tilde><%tilde><%minus>$/E8E6/;
	$multikey =~ s/^<!M><%tilde><%tilde><%slash>$/E8E7/;
	$multikey =~ s/^<!M><%tilde><%tilde><%tilde>$/E8E8/;
	$multikey =~ s/^<!M><%tilde><%tilde><%tilde><%greater>$/E8E9/;
	$multikey =~ s/^<!M><%underscore>$/E8EA/;
	$multikey =~ s/^<!M><%underscore><%backslash>$/E8EB/;
	$multikey =~ s/^<!M><%underscore><%backslash><%bar>$/E8EC/;
	$multikey =~ s/^<!M><%underscore><%backslash><%hash>$/E8ED/;
	$multikey =~ s/^<!M><%underscore><%backslash><%slash>$/E8EE/;
	$multikey =~ s/^<!M><%underscore><%backslash><%slash><0>$/E8EF/;
	$multikey =~ s/^<!M><%underscore><%backslash><%slash><~nbspace>$/E8F0/;
	$multikey =~ s/^<!M><%underscore><%backslash><%slash><~space>$/E8F1/;
	$multikey =~ s/^<!M><%underscore><%bar>$/E8F2/;
	$multikey =~ s/^<!M><%underscore><%bar><s>$/E8F3/;
	$multikey =~ s/^<!M><%underscore><%bar><~nbspace>$/E8F4/;
	$multikey =~ s/^<!M><%underscore><%bar><~space>$/E8F5/;
	$multikey =~ s/^<!M><%underscore><%bracketright>$/E8F6/;
	$multikey =~ s/^<!M><%underscore><%grave>$/E8F7/;
	$multikey =~ s/^<!M><%underscore><%greater>$/E8F8/;
	$multikey =~ s/^<!M><%underscore><%greater><%grave>$/E8F9/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenleft>$/E8FA/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenleft><%parenright>$/E8FB/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenright>$/E8FC/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenright><%parenleft>$/E8FD/;
	$multikey =~ s/^<!M><%underscore><%greater><%period>$/E8FE/;
	$multikey =~ s/^<!M><%underscore><%greater><~nbspace>$/E8FF/;
	$multikey =~ s/^<!M><%underscore><%greater><~space>$/E900/;
	$multikey =~ s/^<!M><%underscore><%hash>$/E901/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash>$/E902/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash><%slash>$/E903/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash><%slash><0>$/E904/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash><%slash><~nbspace>$/E905/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash><%slash><~space>$/E906/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash>$/E907/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash><%backslash>$/E908/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash><%backslash><0>$/E909/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash><%backslash><~nbspace>$/E90A/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash><%backslash><~space>$/E90B/;
	$multikey =~ s/^<!M><%underscore><%less>$/E90C/;
	$multikey =~ s/^<!M><%underscore><%less><%grave>$/E90D/;
	$multikey =~ s/^<!M><%underscore><%less><%parenleft>$/E90E/;
	$multikey =~ s/^<!M><%underscore><%less><%parenleft><%parenright>$/E90F/;
	$multikey =~ s/^<!M><%underscore><%less><%parenright>$/E910/;
	$multikey =~ s/^<!M><%underscore><%less><%parenright><%parenleft>$/E911/;
	$multikey =~ s/^<!M><%underscore><%less><%period>$/E912/;
	$multikey =~ s/^<!M><%underscore><%less><~nbspace>$/E913/;
	$multikey =~ s/^<!M><%underscore><%less><~space>$/E914/;
	$multikey =~ s/^<!M><%underscore><%slash>$/E915/;
	$multikey =~ s/^<!M><%underscore><%slash><%backslash>$/E916/;
	$multikey =~ s/^<!M><%underscore><%slash><%backslash><0>$/E917/;
	$multikey =~ s/^<!M><%underscore><%slash><%backslash><~nbspace>$/E918/;
	$multikey =~ s/^<!M><%underscore><%slash><%backslash><~space>$/E919/;
	$multikey =~ s/^<!M><%underscore><%slash><%bar>$/E91A/;
	$multikey =~ s/^<!M><%underscore><%slash><%hash>$/E91B/;
	$multikey =~ s/^<!M><%underscore><%slash><~nbspace>$/E91C/;
	$multikey =~ s/^<!M><%underscore><%slash><~space>$/E91D/;
	$multikey =~ s/^<!M><%underscore><%underscore>$/E91E/;
	$multikey =~ s/^<!M><%underscore><%underscore><A>$/E91F/;
	$multikey =~ s/^<!M><%underscore><%underscore><a>$/E920/;
	$multikey =~ s/^<!M><0>$/E921/;
	$multikey =~ s/^<!M><0><%asterisk>$/E922/;
	$multikey =~ s/^<!M><0><%hash>$/E923/;
	$multikey =~ s/^<!M><0><%minus>$/E924/;
	$multikey =~ s/^<!M><0><%percent>$/E925/;
	$multikey =~ s/^<!M><0><%slash>$/E926/;
	$multikey =~ s/^<!M><0><0>$/E927/;
	$multikey =~ s/^<!M><0><3>$/E928/;
	$multikey =~ s/^<!M><1>$/E929/;
	$multikey =~ s/^<!M><1><%apostrophe>$/E92A/;
	$multikey =~ s/^<!M><1><%aprightsingquotmark>$/E92B/;
	$multikey =~ s/^<!M><1><%asterisk>$/E92C/;
	$multikey =~ s/^<!M><1><%grave>$/E92D/;
	$multikey =~ s/^<!M><1><%hash>$/E92E/;
	$multikey =~ s/^<!M><1><%minus>$/E92F/;
	$multikey =~ s/^<!M><1><%slash>$/E930/;
	$multikey =~ s/^<!M><1><%slash><0>$/E931/;
	$multikey =~ s/^<!M><1><%slash><1>$/E932/;
	$multikey =~ s/^<!M><1><%slash><2>$/E933/;
	$multikey =~ s/^<!M><1><%slash><3>$/E934/;
	$multikey =~ s/^<!M><1><%slash><4>$/E935/;
	$multikey =~ s/^<!M><1><%slash><5>$/E936/;
	$multikey =~ s/^<!M><1><%slash><6>$/E937/;
	$multikey =~ s/^<!M><1><%slash><7>$/E938/;
	$multikey =~ s/^<!M><1><%slash><8>$/E939/;
	$multikey =~ s/^<!M><1><%slash><9>$/E93A/;
	$multikey =~ s/^<!M><1><%slash><~space>$/E93B/;
	$multikey =~ s/^<!M><1><%underscore>$/E93C/;
	$multikey =~ s/^<!M><1><0>$/E93D/;
	$multikey =~ s/^<!M><1><1>$/E93E/;
	$multikey =~ s/^<!M><1><2>$/E93F/;
	$multikey =~ s/^<!M><1><3>$/E940/;
	$multikey =~ s/^<!M><1><4>$/E941/;
	$multikey =~ s/^<!M><1><5>$/E942/;
	$multikey =~ s/^<!M><1><6>$/E943/;
	$multikey =~ s/^<!M><1><7>$/E944/;
	$multikey =~ s/^<!M><1><8>$/E945/;
	$multikey =~ s/^<!M><1><9>$/E946/;
	$multikey =~ s/^<!M><1><i>$/E947/;
	$multikey =~ s/^<!M><1><I>$/E948/;
	$multikey =~ s/^<!M><1><t>$/E949/;
	$multikey =~ s/^<!M><1><T>$/E94A/;
	$multikey =~ s/^<!M><1><~space>$/E94B/;
	$multikey =~ s/^<!M><2>$/E94C/;
	$multikey =~ s/^<!M><2><%apostrophe>$/E94D/;
	$multikey =~ s/^<!M><2><%aprightsingquotmark>$/E94E/;
	$multikey =~ s/^<!M><2><%asterisk>$/E94F/;
	$multikey =~ s/^<!M><2><%backslash>$/E950/;
	$multikey =~ s/^<!M><2><%bar>$/E951/;
	$multikey =~ s/^<!M><2><%bracketleft>$/E952/;
	$multikey =~ s/^<!M><2><%bracketleft><%bracketright>$/E953/;
	$multikey =~ s/^<!M><2><%bracketleft><w>$/E954/;
	$multikey =~ s/^<!M><2><%bracketright>$/E955/;
	$multikey =~ s/^<!M><2><%bracketright><w>$/E956/;
	$multikey =~ s/^<!M><2><%exclam>$/E957/;
	$multikey =~ s/^<!M><2><%grave>$/E958/;
	$multikey =~ s/^<!M><2><%greater>$/E959/;
	$multikey =~ s/^<!M><2><%hash>$/E95A/;
	$multikey =~ s/^<!M><2><%less>$/E95B/;
	$multikey =~ s/^<!M><2><%less><%exclam>$/E95C/;
	$multikey =~ s/^<!M><2><%less><%minus>$/E95D/;
	$multikey =~ s/^<!M><2><%less><~nbspace>$/E95E/;
	$multikey =~ s/^<!M><2><%less><~space>$/E95F/;
	$multikey =~ s/^<!M><2><%minus>$/E960/;
	$multikey =~ s/^<!M><2><%slash>$/E961/;
	$multikey =~ s/^<!M><2><%slash><%backslash>$/E962/;
	$multikey =~ s/^<!M><2><%slash><3>$/E963/;
	$multikey =~ s/^<!M><2><%slash><5>$/E964/;
	$multikey =~ s/^<!M><2><%slash><~nbspace>$/E965/;
	$multikey =~ s/^<!M><2><%slash><~space>$/E966/;
	$multikey =~ s/^<!M><2><%underscore>$/E967/;
	$multikey =~ s/^<!M><2><3>$/E968/;
	$multikey =~ s/^<!M><2><5>$/E969/;
	$multikey =~ s/^<!M><2><A>$/E96A/;
	$multikey =~ s/^<!M><2><a>$/E96B/;
	$multikey =~ s/^<!M><2><b>$/E96C/;
	$multikey =~ s/^<!M><2><c>$/E96D/;
	$multikey =~ s/^<!M><2><c><%backslash>$/E96E/;
	$multikey =~ s/^<!M><2><c><c>$/E96F/;
	$multikey =~ s/^<!M><2><c><~nbspace>$/E970/;
	$multikey =~ s/^<!M><2><c><~space>$/E971/;
	$multikey =~ s/^<!M><2><d>$/E972/;
	$multikey =~ s/^<!M><2><D>$/E973/;
	$multikey =~ s/^<!M><2><h>$/E974/;
	$multikey =~ s/^<!M><2><H>$/E975/;
	$multikey =~ s/^<!M><2><i>$/E976/;
	$multikey =~ s/^<!M><2><I>$/E977/;
	$multikey =~ s/^<!M><2><n>$/E978/;
	$multikey =~ s/^<!M><2><n><%bracketleft>$/E979/;
	$multikey =~ s/^<!M><2><n><%bracketright>$/E97A/;
	$multikey =~ s/^<!M><2><n><~nbspace>$/E97B/;
	$multikey =~ s/^<!M><2><n><~space>$/E97C/;
	$multikey =~ s/^<!M><2><s>$/E97D/;
	$multikey =~ s/^<!M><2><S>$/E97E/;
	$multikey =~ s/^<!M><2><s><o>$/E97F/;
	$multikey =~ s/^<!M><2><S><o>$/E980/;
	$multikey =~ s/^<!M><2><s><~nbspace>$/E981/;
	$multikey =~ s/^<!M><2><S><~nbspace>$/E982/;
	$multikey =~ s/^<!M><2><s><~space>$/E983/;
	$multikey =~ s/^<!M><2><S><~space>$/E984/;
	$multikey =~ s/^<!M><2><t>$/E985/;
	$multikey =~ s/^<!M><2><T>$/E986/;
	$multikey =~ s/^<!M><2><T><%apostrophe>$/E987/;
	$multikey =~ s/^<!M><2><T><%aprightsingquotmark>$/E988/;
	$multikey =~ s/^<!M><2><T><%greater>$/E989/;
	$multikey =~ s/^<!M><2><T><%greater><%slash>$/E98A/;
	$multikey =~ s/^<!M><2><T><%greater><~nbspace>$/E98B/;
	$multikey =~ s/^<!M><2><T><%greater><~space>$/E98C/;
	$multikey =~ s/^<!M><2><T><%less>$/E98D/;
	$multikey =~ s/^<!M><2><T><%percent>$/E98E/;
	$multikey =~ s/^<!M><2><T><2>$/E98F/;
	$multikey =~ s/^<!M><2><T><2><%greater>$/E990/;
	$multikey =~ s/^<!M><2><T><2><%greater><%slash>$/E991/;
	$multikey =~ s/^<!M><2><T><2><%greater><~nbspace>$/E992/;
	$multikey =~ s/^<!M><2><T><2><%greater><~space>$/E993/;
	$multikey =~ s/^<!M><2><T><2><%less>$/E994/;
	$multikey =~ s/^<!M><2><u>$/E995/;
	$multikey =~ s/^<!M><2><u><%bracketleft>$/E996/;
	$multikey =~ s/^<!M><2><u><%bracketright>$/E997/;
	$multikey =~ s/^<!M><2><u><~nbspace>$/E998/;
	$multikey =~ s/^<!M><2><u><~space>$/E999/;
	$multikey =~ s/^<!M><2><v>$/E99A/;
	$multikey =~ s/^<!M><2><V>$/E99B/;
	$multikey =~ s/^<!M><2><V><V>$/E99C/;
	$multikey =~ s/^<!M><2><v><v>$/E99D/;
	$multikey =~ s/^<!M><2><v><~nbspace>$/E99E/;
	$multikey =~ s/^<!M><2><V><~nbspace>$/E99F/;
	$multikey =~ s/^<!M><2><v><~space>$/E9A0/;
	$multikey =~ s/^<!M><2><V><~space>$/E9A1/;
	$multikey =~ s/^<!M><2><w>$/E9A2/;
	$multikey =~ s/^<!M><2><w><%bracketleft>$/E9A3/;
	$multikey =~ s/^<!M><2><w><%bracketright>$/E9A4/;
	$multikey =~ s/^<!M><2><Z>$/E9A5/;
	$multikey =~ s/^<!M><2><z>$/E9A6/;
	$multikey =~ s/^<!M><2><~nbspace>$/E9A7/;
	$multikey =~ s/^<!M><2><~space>$/E9A8/;
	$multikey =~ s/^<!M><3>$/E9A9/;
	$multikey =~ s/^<!M><3><%apostrophe>$/E9AA/;
	$multikey =~ s/^<!M><3><%aprightsingquotmark>$/E9AB/;
	$multikey =~ s/^<!M><3><%asterisk>$/E9AC/;
	$multikey =~ s/^<!M><3><%bar>$/E9AD/;
	$multikey =~ s/^<!M><3><%bracketleft>$/E9AE/;
	$multikey =~ s/^<!M><3><%colon>$/E9AF/;
	$multikey =~ s/^<!M><3><%grave>$/E9B0/;
	$multikey =~ s/^<!M><3><%greater>$/E9B1/;
	$multikey =~ s/^<!M><3><%hash>$/E9B2/;
	$multikey =~ s/^<!M><3><%less>$/E9B3/;
	$multikey =~ s/^<!M><3><%less><%minus>$/E9B4/;
	$multikey =~ s/^<!M><3><%less><~nbspace>$/E9B5/;
	$multikey =~ s/^<!M><3><%less><~space>$/E9B6/;
	$multikey =~ s/^<!M><3><%minus>$/E9B7/;
	$multikey =~ s/^<!M><3><%plus>$/E9B8/;
	$multikey =~ s/^<!M><3><%slash>$/E9B9/;
	$multikey =~ s/^<!M><3><%slash><4>$/E9BA/;
	$multikey =~ s/^<!M><3><%slash><5>$/E9BB/;
	$multikey =~ s/^<!M><3><%slash><8>$/E9BC/;
	$multikey =~ s/^<!M><3><%slash><~nbspace>$/E9BD/;
	$multikey =~ s/^<!M><3><%slash><~space>$/E9BE/;
	$multikey =~ s/^<!M><3><%underscore>$/E9BF/;
	$multikey =~ s/^<!M><3><4>$/E9C0/;
	$multikey =~ s/^<!M><3><5>$/E9C1/;
	$multikey =~ s/^<!M><3><8>$/E9C2/;
	$multikey =~ s/^<!M><3><d>$/E9C3/;
	$multikey =~ s/^<!M><3><D>$/E9C4/;
	$multikey =~ s/^<!M><3><h>$/E9C5/;
	$multikey =~ s/^<!M><3><H>$/E9C6/;
	$multikey =~ s/^<!M><3><i>$/E9C7/;
	$multikey =~ s/^<!M><3><I>$/E9C8/;
	$multikey =~ s/^<!M><3><s>$/E9C9/;
	$multikey =~ s/^<!M><3><S>$/E9CA/;
	$multikey =~ s/^<!M><3><s><o>$/E9CB/;
	$multikey =~ s/^<!M><3><S><o>$/E9CC/;
	$multikey =~ s/^<!M><3><s><~nbspace>$/E9CD/;
	$multikey =~ s/^<!M><3><S><~nbspace>$/E9CE/;
	$multikey =~ s/^<!M><3><s><~space>$/E9CF/;
	$multikey =~ s/^<!M><3><S><~space>$/E9D0/;
	$multikey =~ s/^<!M><3><t>$/E9D1/;
	$multikey =~ s/^<!M><3><v>$/E9D2/;
	$multikey =~ s/^<!M><3><Z>$/E9D3/;
	$multikey =~ s/^<!M><3><z>$/E9D4/;
	$multikey =~ s/^<!M><4>$/E9D5/;
	$multikey =~ s/^<!M><4><%apostrophe>$/E9D6/;
	$multikey =~ s/^<!M><4><%aprightsingquotmark>$/E9D7/;
	$multikey =~ s/^<!M><4><%asterisk>$/E9D8/;
	$multikey =~ s/^<!M><4><%hash>$/E9D9/;
	$multikey =~ s/^<!M><4><%minus>$/E9DA/;
	$multikey =~ s/^<!M><4><%slash>$/E9DB/;
	$multikey =~ s/^<!M><4><%slash><5>$/E9DC/;
	$multikey =~ s/^<!M><4><%underscore>$/E9DD/;
	$multikey =~ s/^<!M><4><5>$/E9DE/;
	$multikey =~ s/^<!M><4><i>$/E9DF/;
	$multikey =~ s/^<!M><4><I>$/E9E0/;
	$multikey =~ s/^<!M><4><s>$/E9E1/;
	$multikey =~ s/^<!M><4><S>$/E9E2/;
	$multikey =~ s/^<!M><4><t>$/E9E3/;
	$multikey =~ s/^<!M><4><T>$/E9E4/;
	$multikey =~ s/^<!M><4><v>$/E9E5/;
	$multikey =~ s/^<!M><4><Z>$/E9E6/;
	$multikey =~ s/^<!M><4><z>$/E9E7/;
	$multikey =~ s/^<!M><5>$/E9E8/;
	$multikey =~ s/^<!M><5><%asterisk>$/E9E9/;
	$multikey =~ s/^<!M><5><%minus>$/E9EA/;
	$multikey =~ s/^<!M><5><%slash>$/E9EB/;
	$multikey =~ s/^<!M><5><%slash><6>$/E9EC/;
	$multikey =~ s/^<!M><5><%slash><8>$/E9ED/;
	$multikey =~ s/^<!M><5><6>$/E9EE/;
	$multikey =~ s/^<!M><5><8>$/E9EF/;
	$multikey =~ s/^<!M><5><i>$/E9F0/;
	$multikey =~ s/^<!M><5><I>$/E9F1/;
	$multikey =~ s/^<!M><5><t>$/E9F2/;
	$multikey =~ s/^<!M><5><T>$/E9F3/;
	$multikey =~ s/^<!M><5><Z>$/E9F4/;
	$multikey =~ s/^<!M><5><z>$/E9F5/;
	$multikey =~ s/^<!M><6>$/E9F6/;
	$multikey =~ s/^<!M><6><%apostrophe>$/E9F7/;
	$multikey =~ s/^<!M><6><%aprightsingquotmark>$/E9F8/;
	$multikey =~ s/^<!M><6><%asterisk>$/E9F9/;
	$multikey =~ s/^<!M><6><%minus>$/E9FA/;
	$multikey =~ s/^<!M><6><%quotedbl>$/E9FB/;
	$multikey =~ s/^<!M><6><%quotEuroSign>$/E9FC/;
	$multikey =~ s/^<!M><6><Z>$/E9FD/;
	$multikey =~ s/^<!M><6><z>$/E9FE/;
	$multikey =~ s/^<!M><7>$/E9FF/;
	$multikey =~ s/^<!M><7><%asterisk>$/EA00/;
	$multikey =~ s/^<!M><7><%circum>$/EA01/;
	$multikey =~ s/^<!M><7><%circum><R>$/EA02/;
	$multikey =~ s/^<!M><7><%circum><r>$/EA03/;
	$multikey =~ s/^<!M><7><%circum><s>$/EA04/;
	$multikey =~ s/^<!M><7><%circum><U>$/EA05/;
	$multikey =~ s/^<!M><7><%circum><u>$/EA06/;
	$multikey =~ s/^<!M><7><%minus>$/EA07/;
	$multikey =~ s/^<!M><7><%slash>$/EA08/;
	$multikey =~ s/^<!M><7><%slash><8>$/EA09/;
	$multikey =~ s/^<!M><7><7>$/EA0A/;
	$multikey =~ s/^<!M><7><8>$/EA0B/;
	$multikey =~ s/^<!M><7><C>$/EA0C/;
	$multikey =~ s/^<!M><7><c>$/EA0D/;
	$multikey =~ s/^<!M><7><I>$/EA0E/;
	$multikey =~ s/^<!M><7><i>$/EA0F/;
	$multikey =~ s/^<!M><7><M>$/EA10/;
	$multikey =~ s/^<!M><7><m>$/EA11/;
	$multikey =~ s/^<!M><7><R>$/EA12/;
	$multikey =~ s/^<!M><7><r>$/EA13/;
	$multikey =~ s/^<!M><7><S>$/EA14/;
	$multikey =~ s/^<!M><7><s>$/EA15/;
	$multikey =~ s/^<!M><7><U>$/EA16/;
	$multikey =~ s/^<!M><7><u>$/EA17/;
	$multikey =~ s/^<!M><8>$/EA18/;
	$multikey =~ s/^<!M><8><%asterisk>$/EA19/;
	$multikey =~ s/^<!M><8><%backslash>$/EA1A/;
	$multikey =~ s/^<!M><8><%bar>$/EA1B/;
	$multikey =~ s/^<!M><8><%greater>$/EA1C/;
	$multikey =~ s/^<!M><8><%minus>$/EA1D/;
	$multikey =~ s/^<!M><8><x>$/EA1E/;
	$multikey =~ s/^<!M><8><X>$/EA1F/;
	$multikey =~ s/^<!M><8><x><a>$/EA20/;
	$multikey =~ s/^<!M><8><X><A>$/EA21/;
	$multikey =~ s/^<!M><8><x><b>$/EA22/;
	$multikey =~ s/^<!M><8><X><B>$/EA23/;
	$multikey =~ s/^<!M><8><x><c>$/EA24/;
	$multikey =~ s/^<!M><8><X><C>$/EA25/;
	$multikey =~ s/^<!M><8><x><h>$/EA26/;
	$multikey =~ s/^<!M><8><X><H>$/EA27/;
	$multikey =~ s/^<!M><8><x><l>$/EA28/;
	$multikey =~ s/^<!M><8><X><L>$/EA29/;
	$multikey =~ s/^<!M><8><x><o>$/EA2A/;
	$multikey =~ s/^<!M><8><X><O>$/EA2B/;
	$multikey =~ s/^<!M><8><x><p>$/EA2C/;
	$multikey =~ s/^<!M><8><X><P>$/EA2D/;
	$multikey =~ s/^<!M><8><x><s>$/EA2E/;
	$multikey =~ s/^<!M><8><X><S>$/EA2F/;
	$multikey =~ s/^<!M><8><x><u>$/EA30/;
	$multikey =~ s/^<!M><8><X><U>$/EA31/;
	$multikey =~ s/^<!M><8><x><~space>$/EA32/;
	$multikey =~ s/^<!M><8><X><~space>$/EA33/;
	$multikey =~ s/^<!M><8><~nbspace>$/EA34/;
	$multikey =~ s/^<!M><8><~space>$/EA35/;
	$multikey =~ s/^<!M><9>$/EA36/;
	$multikey =~ s/^<!M><9><%apostrophe>$/EA37/;
	$multikey =~ s/^<!M><9><%aprightsingquotmark>$/EA38/;
	$multikey =~ s/^<!M><9><%asterisk>$/EA39/;
	$multikey =~ s/^<!M><9><%comma>$/EA3A/;
	$multikey =~ s/^<!M><9><%minus>$/EA3B/;
	$multikey =~ s/^<!M><9><%quotedbl>$/EA3C/;
	$multikey =~ s/^<!M><9><%quotEuroSign>$/EA3D/;
	$multikey =~ s/^<!M><9><%underscore>$/EA3E/;
	$multikey =~ s/^<!M><9><C>$/EA3F/;
	$multikey =~ s/^<!M><9><c>$/EA40/;
	$multikey =~ s/^<!M><a>$/EA41/;
	$multikey =~ s/^<!M><A>$/EA42/;
	$multikey =~ s/^<!M><A><%asterisk>$/EA43/;
	$multikey =~ s/^<!M><a><%asterisk>$/EA44/;
	$multikey =~ s/^<!M><a><%backslash>$/EA45/;
	$multikey =~ s/^<!M><A><%backslash>$/EA46/;
	$multikey =~ s/^<!M><a><%bar>$/EA47/;
	$multikey =~ s/^<!M><A><%bar>$/EA48/;
	$multikey =~ s/^<!M><a><%bracketright>$/EA49/;
	$multikey =~ s/^<!M><A><%equal>$/EA4A/;
	$multikey =~ s/^<!M><a><%equal>$/EA4B/;
	$multikey =~ s/^<!M><a><%hash>$/EA4C/;
	$multikey =~ s/^<!M><A><%minus>$/EA4D/;
	$multikey =~ s/^<!M><a><%minus>$/EA4E/;
	$multikey =~ s/^<!M><A><%minus><V>$/EA4F/;
	$multikey =~ s/^<!M><A><%minus><v>$/EA50/;
	$multikey =~ s/^<!M><a><%minus><v>$/EA51/;
	$multikey =~ s/^<!M><A><%minus><V><%minus>$/EA52/;
	$multikey =~ s/^<!M><A><%minus><v><%minus>$/EA53/;
	$multikey =~ s/^<!M><a><%minus><v><%minus>$/EA54/;
	$multikey =~ s/^<!M><a><%minus><v><~nbspace>$/EA55/;
	$multikey =~ s/^<!M><A><%minus><v><~nbspace>$/EA56/;
	$multikey =~ s/^<!M><A><%minus><V><~nbspace>$/EA57/;
	$multikey =~ s/^<!M><a><%minus><v><~space>$/EA58/;
	$multikey =~ s/^<!M><A><%minus><v><~space>$/EA59/;
	$multikey =~ s/^<!M><A><%minus><V><~space>$/EA5A/;
	$multikey =~ s/^<!M><A><%minus><~nbspace>$/EA5B/;
	$multikey =~ s/^<!M><a><%minus><~nbspace>$/EA5C/;
	$multikey =~ s/^<!M><A><%minus><~space>$/EA5D/;
	$multikey =~ s/^<!M><a><%minus><~space>$/EA5E/;
	$multikey =~ s/^<!M><a><%parenleft>$/EA5F/;
	$multikey =~ s/^<!M><a><%parenleft><%parenright>$/EA60/;
	$multikey =~ s/^<!M><a><%parenright>$/EA61/;
	$multikey =~ s/^<!M><a><%parenright><%parenleft>$/EA62/;
	$multikey =~ s/^<!M><a><%period>$/EA63/;
	$multikey =~ s/^<!M><A><%plus>$/EA64/;
	$multikey =~ s/^<!M><A><%slash>$/EA65/;
	$multikey =~ s/^<!M><a><%slash>$/EA66/;
	$multikey =~ s/^<!M><a><%slash><c>$/EA67/;
	$multikey =~ s/^<!M><a><%slash><s>$/EA68/;
	$multikey =~ s/^<!M><a><%underscore>$/EA69/;
	$multikey =~ s/^<!M><A><%underscore>$/EA6A/;
	$multikey =~ s/^<!M><A><A>$/EA6B/;
	$multikey =~ s/^<!M><A><a>$/EA6C/;
	$multikey =~ s/^<!M><a><a>$/EA6D/;
	$multikey =~ s/^<!M><a><c>$/EA6E/;
	$multikey =~ s/^<!M><a><C>$/EA6F/;
	$multikey =~ s/^<!M><A><C>$/EA70/;
	$multikey =~ s/^<!M><A><c>$/EA71/;
	$multikey =~ s/^<!M><A><e>$/EA72/;
	$multikey =~ s/^<!M><A><E>$/EA73/;
	$multikey =~ s/^<!M><a><e>$/EA74/;
	$multikey =~ s/^<!M><a><e><d>$/EA75/;
	$multikey =~ s/^<!M><A><E><D>$/EA76/;
	$multikey =~ s/^<!M><A><E><~space>$/EA77/;
	$multikey =~ s/^<!M><a><e><~space>$/EA78/;
	$multikey =~ s/^<!M><a><f>$/EA79/;
	$multikey =~ s/^<!M><A><F>$/EA7A/;
	$multikey =~ s/^<!M><a><f><n>$/EA7B/;
	$multikey =~ s/^<!M><A><F><N>$/EA7C/;
	$multikey =~ s/^<!M><a><l>$/EA7D/;
	$multikey =~ s/^<!M><A><L>$/EA7E/;
	$multikey =~ s/^<!M><a><l><t>$/EA7F/;
	$multikey =~ s/^<!M><A><L><T>$/EA80/;
	$multikey =~ s/^<!M><a><m>$/EA81/;
	$multikey =~ s/^<!M><A><M>$/EA82/;
	$multikey =~ s/^<!M><a><m><d>$/EA83/;
	$multikey =~ s/^<!M><A><M><D>$/EA84/;
	$multikey =~ s/^<!M><a><n>$/EA85/;
	$multikey =~ s/^<!M><A><N>$/EA86/;
	$multikey =~ s/^<!M><a><n><d>$/EA87/;
	$multikey =~ s/^<!M><A><N><D>$/EA88/;
	$multikey =~ s/^<!M><a><n><g>$/EA89/;
	$multikey =~ s/^<!M><A><N><G>$/EA8A/;
	$multikey =~ s/^<!M><A><O>$/EA8B/;
	$multikey =~ s/^<!M><A><o>$/EA8C/;
	$multikey =~ s/^<!M><a><o>$/EA8D/;
	$multikey =~ s/^<!M><A><Q>$/EA8E/;
	$multikey =~ s/^<!M><a><q>$/EA8F/;
	$multikey =~ s/^<!M><a><q><u>$/EA90/;
	$multikey =~ s/^<!M><a><q><u><a>$/EA91/;
	$multikey =~ s/^<!M><A><R>$/EA92/;
	$multikey =~ s/^<!M><a><r>$/EA93/;
	$multikey =~ s/^<!M><a><r><i>$/EA94/;
	$multikey =~ s/^<!M><a><r><i><e>$/EA95/;
	$multikey =~ s/^<!M><A><S>$/EA96/;
	$multikey =~ s/^<!M><a><s>$/EA97/;
	$multikey =~ s/^<!M><A><U>$/EA98/;
	$multikey =~ s/^<!M><A><u>$/EA99/;
	$multikey =~ s/^<!M><a><u>$/EA9A/;
	$multikey =~ s/^<!M><A><V>$/EA9B/;
	$multikey =~ s/^<!M><A><v>$/EA9C/;
	$multikey =~ s/^<!M><a><v>$/EA9D/;
	$multikey =~ s/^<!M><a><w>$/EA9E/;
	$multikey =~ s/^<!M><A><W>$/EA9F/;
	$multikey =~ s/^<!M><a><w><g>$/EAA0/;
	$multikey =~ s/^<!M><A><W><G>$/EAA1/;
	$multikey =~ s/^<!M><A><x>$/EAA2/;
	$multikey =~ s/^<!M><A><Y>$/EAA3/;
	$multikey =~ s/^<!M><A><y>$/EAA4/;
	$multikey =~ s/^<!M><a><y>$/EAA5/;
	$multikey =~ s/^<!M><a><z>$/EAA6/;
	$multikey =~ s/^<!M><A><Z>$/EAA7/;
	$multikey =~ s/^<!M><a><z><n>$/EAA8/;
	$multikey =~ s/^<!M><A><Z><N>$/EAA9/;
	$multikey =~ s/^<!M><A><~nbspace>$/EAAA/;
	$multikey =~ s/^<!M><a><~nbspace>$/EAAB/;
	$multikey =~ s/^<!M><A><~space>$/EAAC/;
	$multikey =~ s/^<!M><a><~space>$/EAAD/;
	$multikey =~ s/^<!M><b>$/EAAE/;
	$multikey =~ s/^<!M><B>$/EAAF/;
	$multikey =~ s/^<!M><B><%apostrophe>$/EAB0/;
	$multikey =~ s/^<!M><b><%apostrophe>$/EAB1/;
	$multikey =~ s/^<!M><b><%apostrophe><%parenleft>$/EAB2/;
	$multikey =~ s/^<!M><B><%aprightsingquotmark>$/EAB3/;
	$multikey =~ s/^<!M><b><%aprightsingquotmark>$/EAB4/;
	$multikey =~ s/^<!M><b><%aprightsingquotmark><%parenleft>$/EAB5/;
	$multikey =~ s/^<!M><B><%asterisk>$/EAB6/;
	$multikey =~ s/^<!M><b><%asterisk>$/EAB7/;
	$multikey =~ s/^<!M><b><%at>$/EAB8/;
	$multikey =~ s/^<!M><b><%backslash>$/EAB9/;
	$multikey =~ s/^<!M><B><%backslash>$/EABA/;
	$multikey =~ s/^<!M><b><%bracketleft>$/EABB/;
	$multikey =~ s/^<!M><b><%bracketleft><%slash>$/EABC/;
	$multikey =~ s/^<!M><b><%bracketleft><%underscore>$/EABD/;
	$multikey =~ s/^<!M><b><%bracketleft><%underscore><%slash>$/EABE/;
	$multikey =~ s/^<!M><b><%bracketright>$/EABF/;
	$multikey =~ s/^<!M><b><%bracketright><%slash>$/EAC0/;
	$multikey =~ s/^<!M><b><%bracketright><%underscore>$/EAC1/;
	$multikey =~ s/^<!M><b><%bracketright><%underscore><%slash>$/EAC2/;
	$multikey =~ s/^<!M><b><%bracketright><%underscore><~nbspace>$/EAC3/;
	$multikey =~ s/^<!M><b><%bracketright><%underscore><~space>$/EAC4/;
	$multikey =~ s/^<!M><b><%bracketright><~nbspace>$/EAC5/;
	$multikey =~ s/^<!M><b><%bracketright><~space>$/EAC6/;
	$multikey =~ s/^<!M><b><%equal>$/EAC7/;
	$multikey =~ s/^<!M><b><%equal><%slash>$/EAC8/;
	$multikey =~ s/^<!M><b><%equal><~nbspace>$/EAC9/;
	$multikey =~ s/^<!M><b><%equal><~space>$/EACA/;
	$multikey =~ s/^<!M><b><%hash>$/EACB/;
	$multikey =~ s/^<!M><b><%less>$/EACC/;
	$multikey =~ s/^<!M><b><%minus>$/EACD/;
	$multikey =~ s/^<!M><b><%minus><%greater>$/EACE/;
	$multikey =~ s/^<!M><b><%minus><c>$/EACF/;
	$multikey =~ s/^<!M><b><%parenleft>$/EAD0/;
	$multikey =~ s/^<!M><B><%parenleft>$/EAD1/;
	$multikey =~ s/^<!M><b><%parenright>$/EAD2/;
	$multikey =~ s/^<!M><B><%parenright>$/EAD3/;
	$multikey =~ s/^<!M><b><%period>$/EAD4/;
	$multikey =~ s/^<!M><b><%plus>$/EAD5/;
	$multikey =~ s/^<!M><b><%slash>$/EAD6/;
	$multikey =~ s/^<!M><b><%slash><%underscore>$/EAD7/;
	$multikey =~ s/^<!M><b><%slash><~nbspace>$/EAD8/;
	$multikey =~ s/^<!M><b><%slash><~space>$/EAD9/;
	$multikey =~ s/^<!M><B><%tilde>$/EADA/;
	$multikey =~ s/^<!M><b><%tilde>$/EADB/;
	$multikey =~ s/^<!M><b><%tilde><%tilde>$/EADC/;
	$multikey =~ s/^<!M><b><%tilde><~nbspace>$/EADD/;
	$multikey =~ s/^<!M><b><%tilde><~space>$/EADE/;
	$multikey =~ s/^<!M><b><%underscore>$/EADF/;
	$multikey =~ s/^<!M><b><%underscore><%slash>$/EAE0/;
	$multikey =~ s/^<!M><b><%underscore><~nbspace>$/EAE1/;
	$multikey =~ s/^<!M><b><%underscore><~space>$/EAE2/;
	$multikey =~ s/^<!M><B><A>$/EAE3/;
	$multikey =~ s/^<!M><b><a>$/EAE4/;
	$multikey =~ s/^<!M><b><a><l>$/EAE5/;
	$multikey =~ s/^<!M><b><a><l><a>$/EAE6/;
	$multikey =~ s/^<!M><b><b>$/EAE7/;
	$multikey =~ s/^<!M><b><c>$/EAE8/;
	$multikey =~ s/^<!M><b><d>$/EAE9/;
	$multikey =~ s/^<!M><B><D>$/EAEA/;
	$multikey =~ s/^<!M><b><d><t>$/EAEB/;
	$multikey =~ s/^<!M><B><D><T>$/EAEC/;
	$multikey =~ s/^<!M><B><E>$/EAED/;
	$multikey =~ s/^<!M><b><e>$/EAEE/;
	$multikey =~ s/^<!M><b><e><l>$/EAEF/;
	$multikey =~ s/^<!M><b><e><l><i>$/EAF0/;
	$multikey =~ s/^<!M><B><Eacute>$/EAF1/;
	$multikey =~ s/^<!M><b><eacute>$/EAF2/;
	$multikey =~ s/^<!M><b><eacute><l>$/EAF3/;
	$multikey =~ s/^<!M><b><eacute><l><i>$/EAF4/;
	$multikey =~ s/^<!M><b><g>$/EAF5/;
	$multikey =~ s/^<!M><B><G>$/EAF6/;
	$multikey =~ s/^<!M><b><g><n>$/EAF7/;
	$multikey =~ s/^<!M><B><G><N>$/EAF8/;
	$multikey =~ s/^<!M><b><h>$/EAF9/;
	$multikey =~ s/^<!M><B><H>$/EAFA/;
	$multikey =~ s/^<!M><b><h><d>$/EAFB/;
	$multikey =~ s/^<!M><B><H><D>$/EAFC/;
	$multikey =~ s/^<!M><b><i>$/EAFD/;
	$multikey =~ s/^<!M><B><I>$/EAFE/;
	$multikey =~ s/^<!M><B><I><L>$/EAFF/;
	$multikey =~ s/^<!M><b><i><p>$/EB00/;
	$multikey =~ s/^<!M><b><i><p><l>$/EB01/;
	$multikey =~ s/^<!M><b><i><p><r>$/EB02/;
	$multikey =~ s/^<!M><B><I><R>$/EB03/;
	$multikey =~ s/^<!M><b><k>$/EB04/;
	$multikey =~ s/^<!M><B><K>$/EB05/;
	$multikey =~ s/^<!M><b><m>$/EB06/;
	$multikey =~ s/^<!M><b><o>$/EB07/;
	$multikey =~ s/^<!M><b><x>$/EB08/;
	$multikey =~ s/^<!M><b><~nbspace>$/EB09/;
	$multikey =~ s/^<!M><b><~space>$/EB0A/;
	$multikey =~ s/^<!M><c>$/EB0B/;
	$multikey =~ s/^<!M><C>$/EB0C/;
	$multikey =~ s/^<!M><C><%asterisk>$/EB0D/;
	$multikey =~ s/^<!M><c><%asterisk>$/EB0E/;
	$multikey =~ s/^<!M><c><%backslash>$/EB0F/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft>$/EB10/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft><%slash>$/EB11/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft><%underscore>$/EB12/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft><%underscore><%slash>$/EB13/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright>$/EB14/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%slash>$/EB15/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%underscore>$/EB16/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%underscore><%slash>$/EB17/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%underscore><~nbspace>$/EB18/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%underscore><~space>$/EB19/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><~nbspace>$/EB1A/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><~space>$/EB1B/;
	$multikey =~ s/^<!M><c><%backslash><%equal>$/EB1C/;
	$multikey =~ s/^<!M><c><%backslash><%equal><%slash>$/EB1D/;
	$multikey =~ s/^<!M><c><%backslash><%equal><~nbspace>$/EB1E/;
	$multikey =~ s/^<!M><c><%backslash><%equal><~space>$/EB1F/;
	$multikey =~ s/^<!M><c><%backslash><%less>$/EB20/;
	$multikey =~ s/^<!M><c><%backslash><%minus>$/EB21/;
	$multikey =~ s/^<!M><c><%backslash><%period>$/EB22/;
	$multikey =~ s/^<!M><c><%backslash><%plus>$/EB23/;
	$multikey =~ s/^<!M><c><%backslash><%slash>$/EB24/;
	$multikey =~ s/^<!M><c><%backslash><%slash><%underscore>$/EB25/;
	$multikey =~ s/^<!M><c><%backslash><%slash><~nbspace>$/EB26/;
	$multikey =~ s/^<!M><c><%backslash><%slash><~space>$/EB27/;
	$multikey =~ s/^<!M><c><%backslash><%tilde>$/EB28/;
	$multikey =~ s/^<!M><c><%backslash><%tilde><%tilde>$/EB29/;
	$multikey =~ s/^<!M><c><%backslash><%tilde><~nbspace>$/EB2A/;
	$multikey =~ s/^<!M><c><%backslash><%tilde><~space>$/EB2B/;
	$multikey =~ s/^<!M><c><%backslash><%underscore>$/EB2C/;
	$multikey =~ s/^<!M><c><%backslash><%underscore><%slash>$/EB2D/;
	$multikey =~ s/^<!M><c><%backslash><%underscore><~nbspace>$/EB2E/;
	$multikey =~ s/^<!M><c><%backslash><%underscore><~space>$/EB2F/;
	$multikey =~ s/^<!M><c><%backslash><o>$/EB30/;
	$multikey =~ s/^<!M><c><%backslash><x>$/EB31/;
	$multikey =~ s/^<!M><c><%backslash><~nbspace>$/EB32/;
	$multikey =~ s/^<!M><c><%backslash><~space>$/EB33/;
	$multikey =~ s/^<!M><C><%bar>$/EB34/;
	$multikey =~ s/^<!M><c><%bar>$/EB35/;
	$multikey =~ s/^<!M><c><%bar><%period>$/EB36/;
	$multikey =~ s/^<!M><c><%bar><%underscore>$/EB37/;
	$multikey =~ s/^<!M><c><%bar><~nbspace>$/EB38/;
	$multikey =~ s/^<!M><c><%bar><~space>$/EB39/;
	$multikey =~ s/^<!M><c><%bracketleft>$/EB3A/;
	$multikey =~ s/^<!M><c><%bracketleft><%slash>$/EB3B/;
	$multikey =~ s/^<!M><c><%bracketleft><%underscore>$/EB3C/;
	$multikey =~ s/^<!M><c><%bracketleft><%underscore><%slash>$/EB3D/;
	$multikey =~ s/^<!M><c><%bracketleft><%underscore><~nbspace>$/EB3E/;
	$multikey =~ s/^<!M><c><%bracketleft><%underscore><~space>$/EB3F/;
	$multikey =~ s/^<!M><c><%bracketleft><~nbspace>$/EB40/;
	$multikey =~ s/^<!M><c><%bracketleft><~space>$/EB41/;
	$multikey =~ s/^<!M><c><%bracketright>$/EB42/;
	$multikey =~ s/^<!M><c><%bracketright><%slash>$/EB43/;
	$multikey =~ s/^<!M><c><%bracketright><%underscore>$/EB44/;
	$multikey =~ s/^<!M><c><%bracketright><%underscore><%slash>$/EB45/;
	$multikey =~ s/^<!M><c><%bracketright><%underscore><~nbspace>$/EB46/;
	$multikey =~ s/^<!M><c><%bracketright><%underscore><~space>$/EB47/;
	$multikey =~ s/^<!M><c><%bracketright><~nbspace>$/EB48/;
	$multikey =~ s/^<!M><c><%bracketright><~space>$/EB49/;
	$multikey =~ s/^<!M><C><%equal>$/EB4A/;
	$multikey =~ s/^<!M><c><%equal>$/EB4B/;
	$multikey =~ s/^<!M><c><%equal><%slash>$/EB4C/;
	$multikey =~ s/^<!M><c><%equal><~nbspace>$/EB4D/;
	$multikey =~ s/^<!M><c><%equal><~space>$/EB4E/;
	$multikey =~ s/^<!M><C><%greater>$/EB4F/;
	$multikey =~ s/^<!M><C><%hash>$/EB50/;
	$multikey =~ s/^<!M><C><%minus>$/EB51/;
	$multikey =~ s/^<!M><c><%minus>$/EB52/;
	$multikey =~ s/^<!M><C><%minus><%bar>$/EB53/;
	$multikey =~ s/^<!M><c><%minus><%bar>$/EB54/;
	$multikey =~ s/^<!M><c><%minus><%greater>$/EB55/;
	$multikey =~ s/^<!M><C><%minus><%period>$/EB56/;
	$multikey =~ s/^<!M><c><%minus><%period>$/EB57/;
	$multikey =~ s/^<!M><c><%percent>$/EB58/;
	$multikey =~ s/^<!M><c><%percent><e>$/EB59/;
	$multikey =~ s/^<!M><C><%period>$/EB5A/;
	$multikey =~ s/^<!M><c><%period>$/EB5B/;
	$multikey =~ s/^<!M><C><%period><%bar>$/EB5C/;
	$multikey =~ s/^<!M><c><%period><%bar>$/EB5D/;
	$multikey =~ s/^<!M><C><%period><%minus>$/EB5E/;
	$multikey =~ s/^<!M><c><%period><%minus>$/EB5F/;
	$multikey =~ s/^<!M><C><%period><%slash>$/EB60/;
	$multikey =~ s/^<!M><c><%period><%slash>$/EB61/;
	$multikey =~ s/^<!M><c><%period><~nbspace>$/EB62/;
	$multikey =~ s/^<!M><c><%period><~space>$/EB63/;
	$multikey =~ s/^<!M><c><%plus>$/EB64/;
	$multikey =~ s/^<!M><C><%slash>$/EB65/;
	$multikey =~ s/^<!M><c><%slash>$/EB66/;
	$multikey =~ s/^<!M><c><%slash><%period>$/EB67/;
	$multikey =~ s/^<!M><c><%slash><%underscore>$/EB68/;
	$multikey =~ s/^<!M><c><%slash><o>$/EB69/;
	$multikey =~ s/^<!M><c><%slash><u>$/EB6A/;
	$multikey =~ s/^<!M><c><%slash><~nbspace>$/EB6B/;
	$multikey =~ s/^<!M><c><%slash><~space>$/EB6C/;
	$multikey =~ s/^<!M><c><%tilde>$/EB6D/;
	$multikey =~ s/^<!M><c><%tilde><%tilde>$/EB6E/;
	$multikey =~ s/^<!M><c><%tilde><~nbspace>$/EB6F/;
	$multikey =~ s/^<!M><c><%tilde><~space>$/EB70/;
	$multikey =~ s/^<!M><c><%underscore>$/EB71/;
	$multikey =~ s/^<!M><c><%underscore><%slash>$/EB72/;
	$multikey =~ s/^<!M><c><%underscore><~nbspace>$/EB73/;
	$multikey =~ s/^<!M><c><%underscore><~space>$/EB74/;
	$multikey =~ s/^<!M><C><9>$/EB75/;
	$multikey =~ s/^<!M><c><9>$/EB76/;
	$multikey =~ s/^<!M><c><a>$/EB77/;
	$multikey =~ s/^<!M><C><A>$/EB78/;
	$multikey =~ s/^<!M><C><a>$/EB79/;
	$multikey =~ s/^<!M><c><a><n>$/EB7A/;
	$multikey =~ s/^<!M><C><A><N>$/EB7B/;
	$multikey =~ s/^<!M><C><a><p>$/EB7C/;
	$multikey =~ s/^<!M><c><a><p>$/EB7D/;
	$multikey =~ s/^<!M><C><A><P>$/EB7E/;
	$multikey =~ s/^<!M><c><a><p><d>$/EB7F/;
	$multikey =~ s/^<!M><c><a><p><d><o>$/EB80/;
	$multikey =~ s/^<!M><c><a><p><d><o><t>$/EB81/;
	$multikey =~ s/^<!M><c><a><p><l>$/EB82/;
	$multikey =~ s/^<!M><C><A><P><L>$/EB83/;
	$multikey =~ s/^<!M><c><a><p><r>$/EB84/;
	$multikey =~ s/^<!M><C><A><P><R>$/EB85/;
	$multikey =~ s/^<!M><c><a><p><s>$/EB86/;
	$multikey =~ s/^<!M><C><A><P><S>$/EB87/;
	$multikey =~ s/^<!M><c><a><p><~nbspace>$/EB88/;
	$multikey =~ s/^<!M><c><a><p><~space>$/EB89/;
	$multikey =~ s/^<!M><c><b>$/EB8A/;
	$multikey =~ s/^<!M><C><C>$/EB8B/;
	$multikey =~ s/^<!M><c><c>$/EB8C/;
	$multikey =~ s/^<!M><c><c><%bracketleft>$/EB8D/;
	$multikey =~ s/^<!M><c><c><%bracketleft><%underscore>$/EB8E/;
	$multikey =~ s/^<!M><c><c><%bracketleft><%underscore><%slash>$/EB8F/;
	$multikey =~ s/^<!M><c><c><%bracketright>$/EB90/;
	$multikey =~ s/^<!M><c><c><%bracketright><%underscore>$/EB91/;
	$multikey =~ s/^<!M><c><c><%bracketright><%underscore><%slash>$/EB92/;
	$multikey =~ s/^<!M><c><c><%bracketright><%underscore><~nbspace>$/EB93/;
	$multikey =~ s/^<!M><c><c><%bracketright><%underscore><~space>$/EB94/;
	$multikey =~ s/^<!M><c><c><%bracketright><~nbspace>$/EB95/;
	$multikey =~ s/^<!M><c><c><%bracketright><~space>$/EB96/;
	$multikey =~ s/^<!M><c><c><%equal>$/EB97/;
	$multikey =~ s/^<!M><c><c><%equal><%slash>$/EB98/;
	$multikey =~ s/^<!M><c><c><%equal><~nbspace>$/EB99/;
	$multikey =~ s/^<!M><c><c><%equal><~space>$/EB9A/;
	$multikey =~ s/^<!M><c><c><%less>$/EB9B/;
	$multikey =~ s/^<!M><c><c><%minus>$/EB9C/;
	$multikey =~ s/^<!M><c><c><%plus>$/EB9D/;
	$multikey =~ s/^<!M><c><c><%slash>$/EB9E/;
	$multikey =~ s/^<!M><c><c><%slash><%underscore>$/EB9F/;
	$multikey =~ s/^<!M><c><c><%slash><~nbspace>$/EBA0/;
	$multikey =~ s/^<!M><c><c><%slash><~space>$/EBA1/;
	$multikey =~ s/^<!M><c><c><%tilde>$/EBA2/;
	$multikey =~ s/^<!M><c><c><%tilde><%tilde>$/EBA3/;
	$multikey =~ s/^<!M><c><c><%tilde><~nbspace>$/EBA4/;
	$multikey =~ s/^<!M><c><c><%tilde><~space>$/EBA5/;
	$multikey =~ s/^<!M><c><c><%underscore>$/EBA6/;
	$multikey =~ s/^<!M><c><c><%underscore><%slash>$/EBA7/;
	$multikey =~ s/^<!M><c><c><%underscore><~nbspace>$/EBA8/;
	$multikey =~ s/^<!M><c><c><%underscore><~space>$/EBA9/;
	$multikey =~ s/^<!M><c><c><o>$/EBAA/;
	$multikey =~ s/^<!M><c><c><x>$/EBAB/;
	$multikey =~ s/^<!M><c><c><~nbspace>$/EBAC/;
	$multikey =~ s/^<!M><c><c><~space>$/EBAD/;
	$multikey =~ s/^<!M><c><e>$/EBAE/;
	$multikey =~ s/^<!M><C><E>$/EBAF/;
	$multikey =~ s/^<!M><c><l>$/EBB0/;
	$multikey =~ s/^<!M><C><L>$/EBB1/;
	$multikey =~ s/^<!M><C><M>$/EBB2/;
	$multikey =~ s/^<!M><c><m>$/EBB3/;
	$multikey =~ s/^<!M><c><m><p>$/EBB4/;
	$multikey =~ s/^<!M><c><n>$/EBB5/;
	$multikey =~ s/^<!M><C><N>$/EBB6/;
	$multikey =~ s/^<!M><c><n><y>$/EBB7/;
	$multikey =~ s/^<!M><C><N><Y>$/EBB8/;
	$multikey =~ s/^<!M><c><o>$/EBB9/;
	$multikey =~ s/^<!M><c><O>$/EBBA/;
	$multikey =~ s/^<!M><C><O>$/EBBB/;
	$multikey =~ s/^<!M><C><o>$/EBBC/;
	$multikey =~ s/^<!M><C><P>$/EBBD/;
	$multikey =~ s/^<!M><c><p>$/EBBE/;
	$multikey =~ s/^<!M><c><q>$/EBBF/;
	$multikey =~ s/^<!M><C><Q>$/EBC0/;
	$multikey =~ s/^<!M><C><r>$/EBC1/;
	$multikey =~ s/^<!M><c><r>$/EBC2/;
	$multikey =~ s/^<!M><C><R>$/EBC3/;
	$multikey =~ s/^<!M><c><r><c>$/EBC4/;
	$multikey =~ s/^<!M><C><R><C>$/EBC5/;
	$multikey =~ s/^<!M><c><t>$/EBC6/;
	$multikey =~ s/^<!M><C><T>$/EBC7/;
	$multikey =~ s/^<!M><c><u>$/EBC8/;
	$multikey =~ s/^<!M><C><U>$/EBC9/;
	$multikey =~ s/^<!M><C><u>$/EBCA/;
	$multikey =~ s/^<!M><C><u><p>$/EBCB/;
	$multikey =~ s/^<!M><c><u><p>$/EBCC/;
	$multikey =~ s/^<!M><c><u><p><d>$/EBCD/;
	$multikey =~ s/^<!M><c><u><p><d><o>$/EBCE/;
	$multikey =~ s/^<!M><c><u><p><d><o><t>$/EBCF/;
	$multikey =~ s/^<!M><c><u><p><p>$/EBD0/;
	$multikey =~ s/^<!M><c><u><p><p><l>$/EBD1/;
	$multikey =~ s/^<!M><c><u><p><p><l><u>$/EBD2/;
	$multikey =~ s/^<!M><c><u><p><p><l><u><s>$/EBD3/;
	$multikey =~ s/^<!M><c><u><p><~nbspace>$/EBD4/;
	$multikey =~ s/^<!M><c><u><p><~space>$/EBD5/;
	$multikey =~ s/^<!M><c><u><~space>$/EBD6/;
	$multikey =~ s/^<!M><C><U><~space>$/EBD7/;
	$multikey =~ s/^<!M><c><x>$/EBD8/;
	$multikey =~ s/^<!M><c><z>$/EBD9/;
	$multikey =~ s/^<!M><C><Z>$/EBDA/;
	$multikey =~ s/^<!M><c><z><k>$/EBDB/;
	$multikey =~ s/^<!M><C><Z><K>$/EBDC/;
	$multikey =~ s/^<!M><C><~nbspace>$/EBDD/;
	$multikey =~ s/^<!M><c><~nbspace>$/EBDE/;
	$multikey =~ s/^<!M><C><~space>$/EBDF/;
	$multikey =~ s/^<!M><c><~space>$/EBE0/;
	$multikey =~ s/^<!M><d>$/EBE1/;
	$multikey =~ s/^<!M><D>$/EBE2/;
	$multikey =~ s/^<!M><D><%asterisk>$/EBE3/;
	$multikey =~ s/^<!M><d><%asterisk>$/EBE4/;
	$multikey =~ s/^<!M><d><%backslash>$/EBE5/;
	$multikey =~ s/^<!M><D><%backslash>$/EBE6/;
	$multikey =~ s/^<!M><d><%bar>$/EBE7/;
	$multikey =~ s/^<!M><d><%equal>$/EBE8/;
	$multikey =~ s/^<!M><D><%equal>$/EBE9/;
	$multikey =~ s/^<!M><D><%greater>$/EBEA/;
	$multikey =~ s/^<!M><d><%greater>$/EBEB/;
	$multikey =~ s/^<!M><D><%greater><Z>$/EBEC/;
	$multikey =~ s/^<!M><D><%greater><z>$/EBED/;
	$multikey =~ s/^<!M><d><%greater><z>$/EBEE/;
	$multikey =~ s/^<!M><d><%hash>$/EBEF/;
	$multikey =~ s/^<!M><D><%hash>$/EBF0/;
	$multikey =~ s/^<!M><d><%less>$/EBF1/;
	$multikey =~ s/^<!M><D><%percent>$/EBF2/;
	$multikey =~ s/^<!M><D><%underscore>$/EBF3/;
	$multikey =~ s/^<!M><d><b>$/EBF4/;
	$multikey =~ s/^<!M><D><D>$/EBF5/;
	$multikey =~ s/^<!M><d><d>$/EBF6/;
	$multikey =~ s/^<!M><d><e>$/EBF7/;
	$multikey =~ s/^<!M><D><E>$/EBF8/;
	$multikey =~ s/^<!M><d><e><b>$/EBF9/;
	$multikey =~ s/^<!M><D><E><B>$/EBFA/;
	$multikey =~ s/^<!M><d><e><f>$/EBFB/;
	$multikey =~ s/^<!M><d><e><l>$/EBFC/;
	$multikey =~ s/^<!M><D><E><L>$/EBFD/;
	$multikey =~ s/^<!M><d><e><z>$/EBFE/;
	$multikey =~ s/^<!M><d><eacute>$/EBFF/;
	$multikey =~ s/^<!M><D><Eacute>$/EC00/;
	$multikey =~ s/^<!M><d><eacute><b>$/EC01/;
	$multikey =~ s/^<!M><D><Eacute><B>$/EC02/;
	$multikey =~ s/^<!M><D><H>$/EC03/;
	$multikey =~ s/^<!M><D><h>$/EC04/;
	$multikey =~ s/^<!M><d><h>$/EC05/;
	$multikey =~ s/^<!M><d><i>$/EC06/;
	$multikey =~ s/^<!M><d><i><a>$/EC07/;
	$multikey =~ s/^<!M><d><i><a><m>$/EC08/;
	$multikey =~ s/^<!M><d><i><a><m><e>$/EC09/;
	$multikey =~ s/^<!M><d><i><a><m><e><t>$/EC0A/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><e>$/EC0B/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><e><r>$/EC0C/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><r>$/EC0D/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><r><e>$/EC0E/;
	$multikey =~ s/^<!M><d><i><a><m><egrave>$/EC0F/;
	$multikey =~ s/^<!M><d><i><a><m><egrave><t>$/EC10/;
	$multikey =~ s/^<!M><d><i><a><m><egrave><t><r>$/EC11/;
	$multikey =~ s/^<!M><d><i><a><m><egrave><t><r><e>$/EC12/;
	$multikey =~ s/^<!M><d><m>$/EC13/;
	$multikey =~ s/^<!M><D><M>$/EC14/;
	$multikey =~ s/^<!M><D><r>$/EC15/;
	$multikey =~ s/^<!M><d><t>$/EC16/;
	$multikey =~ s/^<!M><D><t>$/EC17/;
	$multikey =~ s/^<!M><D><T>$/EC18/;
	$multikey =~ s/^<!M><d><u>$/EC19/;
	$multikey =~ s/^<!M><D><z>$/EC1A/;
	$multikey =~ s/^<!M><D><Z>$/EC1B/;
	$multikey =~ s/^<!M><d><z>$/EC1C/;
	$multikey =~ s/^<!M><d><z><%period>$/EC1D/;
	$multikey =~ s/^<!M><d><z><d>$/EC1E/;
	$multikey =~ s/^<!M><D><Z><D>$/EC1F/;
	$multikey =~ s/^<!M><D><Z><~space>$/EC20/;
	$multikey =~ s/^<!M><d><z><~space>$/EC21/;
	$multikey =~ s/^<!M><d><~nbspace>$/EC22/;
	$multikey =~ s/^<!M><D><~nbspace>$/EC23/;
	$multikey =~ s/^<!M><d><~space>$/EC24/;
	$multikey =~ s/^<!M><D><~space>$/EC25/;
	$multikey =~ s/^<!M><degree>$/EC26/;
	$multikey =~ s/^<!M><degree><C>$/EC27/;
	$multikey =~ s/^<!M><degree><c>$/EC28/;
	$multikey =~ s/^<!M><degree><F>$/EC29/;
	$multikey =~ s/^<!M><degree><f>$/EC2A/;
	$multikey =~ s/^<!M><division>$/EC2B/;
	$multikey =~ s/^<!M><division><multiply>$/EC2C/;
	$multikey =~ s/^<!M><E>$/EC2D/;
	$multikey =~ s/^<!M><e>$/EC2E/;
	$multikey =~ s/^<!M><e><%at>$/EC2F/;
	$multikey =~ s/^<!M><E><%at>$/EC30/;
	$multikey =~ s/^<!M><e><%backslash>$/EC31/;
	$multikey =~ s/^<!M><e><%backslash><%at>$/EC32/;
	$multikey =~ s/^<!M><e><%backslash><%bar>$/EC33/;
	$multikey =~ s/^<!M><e><%backslash><%bar><%comma>$/EC34/;
	$multikey =~ s/^<!M><e><%backslash><%bar><~nbspace>$/EC35/;
	$multikey =~ s/^<!M><e><%backslash><%bar><~space>$/EC36/;
	$multikey =~ s/^<!M><e><%backslash><%comma>$/EC37/;
	$multikey =~ s/^<!M><e><%backslash><%minus>$/EC38/;
	$multikey =~ s/^<!M><e><%backslash><%slash>$/EC39/;
	$multikey =~ s/^<!M><e><%backslash><~nbspace>$/EC3A/;
	$multikey =~ s/^<!M><e><%backslash><~space>$/EC3B/;
	$multikey =~ s/^<!M><e><%bar>$/EC3C/;
	$multikey =~ s/^<!M><e><%bar><%comma>$/EC3D/;
	$multikey =~ s/^<!M><e><%bar><~nbspace>$/EC3E/;
	$multikey =~ s/^<!M><e><%bar><~space>$/EC3F/;
	$multikey =~ s/^<!M><e><%bracketleft>$/EC40/;
	$multikey =~ s/^<!M><e><%bracketright>$/EC41/;
	$multikey =~ s/^<!M><e><%comma>$/EC42/;
	$multikey =~ s/^<!M><E><%equal>$/EC43/;
	$multikey =~ s/^<!M><e><%equal>$/EC44/;
	$multikey =~ s/^<!M><e><%greater>$/EC45/;
	$multikey =~ s/^<!M><e><%hash>$/EC46/;
	$multikey =~ s/^<!M><E><%hash>$/EC47/;
	$multikey =~ s/^<!M><e><%less>$/EC48/;
	$multikey =~ s/^<!M><e><%minus>$/EC49/;
	$multikey =~ s/^<!M><E><%percent>$/EC4A/;
	$multikey =~ s/^<!M><e><%percent>$/EC4B/;
	$multikey =~ s/^<!M><e><%percent><%percent>$/EC4C/;
	$multikey =~ s/^<!M><e><%percent><~nbspace>$/EC4D/;
	$multikey =~ s/^<!M><e><%percent><~space>$/EC4E/;
	$multikey =~ s/^<!M><E><%slash>$/EC4F/;
	$multikey =~ s/^<!M><e><%slash>$/EC50/;
	$multikey =~ s/^<!M><e><%tilde>$/EC51/;
	$multikey =~ s/^<!M><E><%tilde>$/EC52/;
	$multikey =~ s/^<!M><e><%underscore>$/EC53/;
	$multikey =~ s/^<!M><e><a>$/EC54/;
	$multikey =~ s/^<!M><E><A>$/EC55/;
	$multikey =~ s/^<!M><e><e>$/EC56/;
	$multikey =~ s/^<!M><e><m>$/EC57/;
	$multikey =~ s/^<!M><E><M>$/EC58/;
	$multikey =~ s/^<!M><e><m><f>$/EC59/;
	$multikey =~ s/^<!M><E><M><F>$/EC5A/;
	$multikey =~ s/^<!M><e><m><f><c>$/EC5B/;
	$multikey =~ s/^<!M><E><M><F><C>$/EC5C/;
	$multikey =~ s/^<!M><e><m><f><r>$/EC5D/;
	$multikey =~ s/^<!M><E><M><F><R>$/EC5E/;
	$multikey =~ s/^<!M><e><m><o>$/EC5F/;
	$multikey =~ s/^<!M><E><M><O>$/EC60/;
	$multikey =~ s/^<!M><e><m><o><r>$/EC61/;
	$multikey =~ s/^<!M><E><M><O><R>$/EC62/;
	$multikey =~ s/^<!M><e><m><p>$/EC63/;
	$multikey =~ s/^<!M><e><n>$/EC64/;
	$multikey =~ s/^<!M><E><N>$/EC65/;
	$multikey =~ s/^<!M><E><n>$/EC66/;
	$multikey =~ s/^<!M><e><n><d>$/EC67/;
	$multikey =~ s/^<!M><E><N><D>$/EC68/;
	$multikey =~ s/^<!M><e><n><f>$/EC69/;
	$multikey =~ s/^<!M><E><N><F>$/EC6A/;
	$multikey =~ s/^<!M><e><n><f><c>$/EC6B/;
	$multikey =~ s/^<!M><E><N><F><C>$/EC6C/;
	$multikey =~ s/^<!M><e><n><f><r>$/EC6D/;
	$multikey =~ s/^<!M><E><N><F><R>$/EC6E/;
	$multikey =~ s/^<!M><e><n><f><s>$/EC6F/;
	$multikey =~ s/^<!M><E><N><F><S>$/EC70/;
	$multikey =~ s/^<!M><e><n><o>$/EC71/;
	$multikey =~ s/^<!M><E><N><O>$/EC72/;
	$multikey =~ s/^<!M><e><n><o><c>$/EC73/;
	$multikey =~ s/^<!M><E><N><O><C>$/EC74/;
	$multikey =~ s/^<!M><e><n><o><s>$/EC75/;
	$multikey =~ s/^<!M><E><N><O><S>$/EC76/;
	$multikey =~ s/^<!M><e><n><s>$/EC77/;
	$multikey =~ s/^<!M><e><n><t>$/EC78/;
	$multikey =~ s/^<!M><E><N><T>$/EC79/;
	$multikey =~ s/^<!M><e><n><u>$/EC7A/;
	$multikey =~ s/^<!M><e><n><u><s>$/EC7B/;
	$multikey =~ s/^<!M><e><n><v>$/EC7C/;
	$multikey =~ s/^<!M><E><n><v>$/EC7D/;
	$multikey =~ s/^<!M><E><n><v><e>$/EC7E/;
	$multikey =~ s/^<!M><E><n><v><e><l>$/EC7F/;
	$multikey =~ s/^<!M><E><n><v><e><l><o>$/EC80/;
	$multikey =~ s/^<!M><E><n><v><e><l><o><p>$/EC81/;
	$multikey =~ s/^<!M><E><n><v><e><l><o><p><e>$/EC82/;
	$multikey =~ s/^<!M><e><o>$/EC83/;
	$multikey =~ s/^<!M><E><O>$/EC84/;
	$multikey =~ s/^<!M><e><s>$/EC85/;
	$multikey =~ s/^<!M><E><S>$/EC86/;
	$multikey =~ s/^<!M><e><s><c>$/EC87/;
	$multikey =~ s/^<!M><E><S><C>$/EC88/;
	$multikey =~ s/^<!M><e><s><t>$/EC89/;
	$multikey =~ s/^<!M><E><S><T>$/EC8A/;
	$multikey =~ s/^<!M><e><t>$/EC8B/;
	$multikey =~ s/^<!M><e><u>$/EC8C/;
	$multikey =~ s/^<!M><E><U>$/EC8D/;
	$multikey =~ s/^<!M><E><u>$/EC8E/;
	$multikey =~ s/^<!M><E><U><L>$/EC8F/;
	$multikey =~ s/^<!M><E><u><l>$/EC90/;
	$multikey =~ s/^<!M><e><u><l>$/EC91/;
	$multikey =~ s/^<!M><e><u><r>$/EC92/;
	$multikey =~ s/^<!M><E><U><R>$/EC93/;
	$multikey =~ s/^<!M><E><Z>$/EC94/;
	$multikey =~ s/^<!M><E><z>$/EC95/;
	$multikey =~ s/^<!M><e><z>$/EC96/;
	$multikey =~ s/^<!M><E><~nbspace>$/EC97/;
	$multikey =~ s/^<!M><e><~nbspace>$/EC98/;
	$multikey =~ s/^<!M><E><~space>$/EC99/;
	$multikey =~ s/^<!M><e><~space>$/EC9A/;
	$multikey =~ s/^<!M><eacute>$/EC9B/;
	$multikey =~ s/^<!M><Eacute>$/EC9C/;
	$multikey =~ s/^<!M><eacute><a>$/EC9D/;
	$multikey =~ s/^<!M><Eacute><a>$/EC9E/;
	$multikey =~ s/^<!M><f>$/EC9F/;
	$multikey =~ s/^<!M><F>$/ECA0/;
	$multikey =~ s/^<!M><f><%at>$/ECA1/;
	$multikey =~ s/^<!M><f><%greater>$/ECA2/;
	$multikey =~ s/^<!M><f><%hash>$/ECA3/;
	$multikey =~ s/^<!M><f><%less>$/ECA4/;
	$multikey =~ s/^<!M><f><%slash>$/ECA5/;
	$multikey =~ s/^<!M><F><%slash>$/ECA6/;
	$multikey =~ s/^<!M><F><%tilde>$/ECA7/;
	$multikey =~ s/^<!M><f><a>$/ECA8/;
	$multikey =~ s/^<!M><F><a>$/ECA9/;
	$multikey =~ s/^<!M><F><A>$/ECAA/;
	$multikey =~ s/^<!M><f><e>$/ECAB/;
	$multikey =~ s/^<!M><f><e><n>$/ECAC/;
	$multikey =~ s/^<!M><f><e><n><g>$/ECAD/;
	$multikey =~ s/^<!M><F><F>$/ECAE/;
	$multikey =~ s/^<!M><F><f>$/ECAF/;
	$multikey =~ s/^<!M><f><f>$/ECB0/;
	$multikey =~ s/^<!M><f><g>$/ECB1/;
	$multikey =~ s/^<!M><f><i>$/ECB2/;
	$multikey =~ s/^<!M><F><I>$/ECB3/;
	$multikey =~ s/^<!M><f><l>$/ECB4/;
	$multikey =~ s/^<!M><F><L>$/ECB5/;
	$multikey =~ s/^<!M><f><l><i>$/ECB6/;
	$multikey =~ s/^<!M><F><L><I>$/ECB7/;
	$multikey =~ s/^<!M><f><l><p>$/ECB8/;
	$multikey =~ s/^<!M><F><L><P>$/ECB9/;
	$multikey =~ s/^<!M><f><l><t>$/ECBA/;
	$multikey =~ s/^<!M><F><L><T>$/ECBB/;
	$multikey =~ s/^<!M><f><n>$/ECBC/;
	$multikey =~ s/^<!M><f><n><g>$/ECBD/;
	$multikey =~ s/^<!M><f><r>$/ECBE/;
	$multikey =~ s/^<!M><F><R>$/ECBF/;
	$multikey =~ s/^<!M><f><r><b>$/ECC0/;
	$multikey =~ s/^<!M><F><R><B>$/ECC1/;
	$multikey =~ s/^<!M><f><r><i>$/ECC2/;
	$multikey =~ s/^<!M><F><R><I>$/ECC3/;
	$multikey =~ s/^<!M><f><r><p>$/ECC4/;
	$multikey =~ s/^<!M><F><R><P>$/ECC5/;
	$multikey =~ s/^<!M><f><r><t>$/ECC6/;
	$multikey =~ s/^<!M><F><R><T>$/ECC7/;
	$multikey =~ s/^<!M><f><s>$/ECC8/;
	$multikey =~ s/^<!M><f><t>$/ECC9/;
	$multikey =~ s/^<!M><F><T>$/ECCA/;
	$multikey =~ s/^<!M><f><t><d>$/ECCB/;
	$multikey =~ s/^<!M><F><T><D>$/ECCC/;
	$multikey =~ s/^<!M><f><t><u>$/ECCD/;
	$multikey =~ s/^<!M><F><T><U>$/ECCE/;
	$multikey =~ s/^<!M><g>$/ECCF/;
	$multikey =~ s/^<!M><G>$/ECD0/;
	$multikey =~ s/^<!M><g><%backslash>$/ECD1/;
	$multikey =~ s/^<!M><G><%backslash>$/ECD2/;
	$multikey =~ s/^<!M><g><%bar>$/ECD3/;
	$multikey =~ s/^<!M><G><%bar>$/ECD4/;
	$multikey =~ s/^<!M><G><%percent>$/ECD5/;
	$multikey =~ s/^<!M><G><%slash>$/ECD6/;
	$multikey =~ s/^<!M><g><%tilde>$/ECD7/;
	$multikey =~ s/^<!M><g><e>$/ECD8/;
	$multikey =~ s/^<!M><G><E>$/ECD9/;
	$multikey =~ s/^<!M><g><e><l>$/ECDA/;
	$multikey =~ s/^<!M><G><E><L>$/ECDB/;
	$multikey =~ s/^<!M><g><e><m>$/ECDC/;
	$multikey =~ s/^<!M><G><E><M>$/ECDD/;
	$multikey =~ s/^<!M><g><e><m><e>$/ECDE/;
	$multikey =~ s/^<!M><G><E><M><E>$/ECDF/;
	$multikey =~ s/^<!M><g><e><m><i>$/ECE0/;
	$multikey =~ s/^<!M><G><E><M><I>$/ECE1/;
	$multikey =~ s/^<!M><g><e><n>$/ECE2/;
	$multikey =~ s/^<!M><G><E><N>$/ECE3/;
	$multikey =~ s/^<!M><g><eacute>$/ECE4/;
	$multikey =~ s/^<!M><G><Eacute>$/ECE5/;
	$multikey =~ s/^<!M><g><eacute><m>$/ECE6/;
	$multikey =~ s/^<!M><G><Eacute><M>$/ECE7/;
	$multikey =~ s/^<!M><g><eacute><m><e>$/ECE8/;
	$multikey =~ s/^<!M><G><Eacute><M><E>$/ECE9/;
	$multikey =~ s/^<!M><g><g>$/ECEA/;
	$multikey =~ s/^<!M><G><G>$/ECEB/;
	$multikey =~ s/^<!M><g><g><%at>$/ECEC/;
	$multikey =~ s/^<!M><G><G><%at>$/ECED/;
	$multikey =~ s/^<!M><G><h>$/ECEE/;
	$multikey =~ s/^<!M><G><H>$/ECEF/;
	$multikey =~ s/^<!M><g><h>$/ECF0/;
	$multikey =~ s/^<!M><g><h><s>$/ECF1/;
	$multikey =~ s/^<!M><G><H><S>$/ECF2/;
	$multikey =~ s/^<!M><G><H><~space>$/ECF3/;
	$multikey =~ s/^<!M><g><h><~space>$/ECF4/;
	$multikey =~ s/^<!M><G><~nbspace>$/ECF5/;
	$multikey =~ s/^<!M><G><~space>$/ECF6/;
	$multikey =~ s/^<!M><h>$/ECF7/;
	$multikey =~ s/^<!M><H>$/ECF8/;
	$multikey =~ s/^<!M><h><%apostrophe>$/ECF9/;
	$multikey =~ s/^<!M><H><%apostrophe>$/ECFA/;
	$multikey =~ s/^<!M><h><%apostrophe><%parenleft>$/ECFB/;
	$multikey =~ s/^<!M><H><%apostrophe><%parenleft>$/ECFC/;
	$multikey =~ s/^<!M><h><%aprightsingquotmark>$/ECFD/;
	$multikey =~ s/^<!M><H><%aprightsingquotmark>$/ECFE/;
	$multikey =~ s/^<!M><h><%aprightsingquotmark><%parenleft>$/ECFF/;
	$multikey =~ s/^<!M><H><%aprightsingquotmark><%parenleft>$/ED00/;
	$multikey =~ s/^<!M><h><%hash>$/ED01/;
	$multikey =~ s/^<!M><H><%hash>$/ED02/;
	$multikey =~ s/^<!M><h><%minus>$/ED03/;
	$multikey =~ s/^<!M><H><%minus>$/ED04/;
	$multikey =~ s/^<!M><h><%parenleft>$/ED05/;
	$multikey =~ s/^<!M><H><%parenleft>$/ED06/;
	$multikey =~ s/^<!M><h><%parenright>$/ED07/;
	$multikey =~ s/^<!M><H><%parenright>$/ED08/;
	$multikey =~ s/^<!M><h><%slash>$/ED09/;
	$multikey =~ s/^<!M><h><%slash><%slash>$/ED0A/;
	$multikey =~ s/^<!M><h><%slash><~nbspace>$/ED0B/;
	$multikey =~ s/^<!M><h><%slash><~space>$/ED0C/;
	$multikey =~ s/^<!M><H><%tilde>$/ED0D/;
	$multikey =~ s/^<!M><h><d>$/ED0E/;
	$multikey =~ s/^<!M><H><D>$/ED0F/;
	$multikey =~ s/^<!M><h><d><p>$/ED10/;
	$multikey =~ s/^<!M><H><D><P>$/ED11/;
	$multikey =~ s/^<!M><h><d><p><e>$/ED12/;
	$multikey =~ s/^<!M><H><D><P><E>$/ED13/;
	$multikey =~ s/^<!M><H><H>$/ED14/;
	$multikey =~ s/^<!M><H><N>$/ED15/;
	$multikey =~ s/^<!M><H><n>$/ED16/;
	$multikey =~ s/^<!M><h><n>$/ED17/;
	$multikey =~ s/^<!M><h><o>$/ED18/;
	$multikey =~ s/^<!M><H><O>$/ED19/;
	$multikey =~ s/^<!M><h><o><m>$/ED1A/;
	$multikey =~ s/^<!M><H><O><M>$/ED1B/;
	$multikey =~ s/^<!M><H><V>$/ED1C/;
	$multikey =~ s/^<!M><H><v>$/ED1D/;
	$multikey =~ s/^<!M><h><v>$/ED1E/;
	$multikey =~ s/^<!M><H><~nbspace>$/ED1F/;
	$multikey =~ s/^<!M><H><~space>$/ED20/;
	$multikey =~ s/^<!M><i>$/ED21/;
	$multikey =~ s/^<!M><I>$/ED22/;
	$multikey =~ s/^<!M><i><%at>$/ED23/;
	$multikey =~ s/^<!M><i><%at><%percent>$/ED24/;
	$multikey =~ s/^<!M><i><%at><~nbspace>$/ED25/;
	$multikey =~ s/^<!M><i><%at><~space>$/ED26/;
	$multikey =~ s/^<!M><i><%bar>$/ED27/;
	$multikey =~ s/^<!M><I><%bracketleft>$/ED28/;
	$multikey =~ s/^<!M><I><%bracketleft><%bracketright>$/ED29/;
	$multikey =~ s/^<!M><I><%bracketleft><%hash>$/ED2A/;
	$multikey =~ s/^<!M><I><%bracketright>$/ED2B/;
	$multikey =~ s/^<!M><i><%equal>$/ED2C/;
	$multikey =~ s/^<!M><i><%greater>$/ED2D/;
	$multikey =~ s/^<!M><I><%greater>$/ED2E/;
	$multikey =~ s/^<!M><I><%hash>$/ED2F/;
	$multikey =~ s/^<!M><i><%less>$/ED30/;
	$multikey =~ s/^<!M><I><%less>$/ED31/;
	$multikey =~ s/^<!M><I><%less><%greater>$/ED32/;
	$multikey =~ s/^<!M><I><%less><%hash>$/ED33/;
	$multikey =~ s/^<!M><i><%percent>$/ED34/;
	$multikey =~ s/^<!M><i><%percent><%at>$/ED35/;
	$multikey =~ s/^<!M><i><%percent><~nbspace>$/ED36/;
	$multikey =~ s/^<!M><i><%percent><~space>$/ED37/;
	$multikey =~ s/^<!M><I><%tilde>$/ED38/;
	$multikey =~ s/^<!M><I><%underscore>$/ED39/;
	$multikey =~ s/^<!M><I><%underscore><%apostrophe>$/ED3A/;
	$multikey =~ s/^<!M><I><%underscore><%bar>$/ED3B/;
	$multikey =~ s/^<!M><I><%underscore><~nbspace>$/ED3C/;
	$multikey =~ s/^<!M><I><%underscore><~space>$/ED3D/;
	$multikey =~ s/^<!M><i><1>$/ED3E/;
	$multikey =~ s/^<!M><I><1>$/ED3F/;
	$multikey =~ s/^<!M><i><2>$/ED40/;
	$multikey =~ s/^<!M><I><2>$/ED41/;
	$multikey =~ s/^<!M><i><3>$/ED42/;
	$multikey =~ s/^<!M><I><3>$/ED43/;
	$multikey =~ s/^<!M><i><4>$/ED44/;
	$multikey =~ s/^<!M><I><4>$/ED45/;
	$multikey =~ s/^<!M><i><5>$/ED46/;
	$multikey =~ s/^<!M><I><5>$/ED47/;
	$multikey =~ s/^<!M><i><e>$/ED48/;
	$multikey =~ s/^<!M><I><I>$/ED49/;
	$multikey =~ s/^<!M><i><i>$/ED4A/;
	$multikey =~ s/^<!M><i><i><%slash>$/ED4B/;
	$multikey =~ s/^<!M><i><i><~nbspace>$/ED4C/;
	$multikey =~ s/^<!M><i><i><~space>$/ED4D/;
	$multikey =~ s/^<!M><I><J>$/ED4E/;
	$multikey =~ s/^<!M><I><j>$/ED4F/;
	$multikey =~ s/^<!M><i><j>$/ED50/;
	$multikey =~ s/^<!M><i><l>$/ED51/;
	$multikey =~ s/^<!M><I><L>$/ED52/;
	$multikey =~ s/^<!M><i><l><s>$/ED53/;
	$multikey =~ s/^<!M><I><L><S>$/ED54/;
	$multikey =~ s/^<!M><i><n>$/ED55/;
	$multikey =~ s/^<!M><I><N>$/ED56/;
	$multikey =~ s/^<!M><i><n><r>$/ED57/;
	$multikey =~ s/^<!M><I><N><R>$/ED58/;
	$multikey =~ s/^<!M><i><n><t>$/ED59/;
	$multikey =~ s/^<!M><i><n><t><e>$/ED5A/;
	$multikey =~ s/^<!M><i><n><t><e><r>$/ED5B/;
	$multikey =~ s/^<!M><i><n><t><e><r><s>$/ED5C/;
	$multikey =~ s/^<!M><i><n><t><e><r><s><e>$/ED5D/;
	$multikey =~ s/^<!M><i><n><t><e><r><s><e><c>$/ED5E/;
	$multikey =~ s/^<!M><i><o>$/ED5F/;
	$multikey =~ s/^<!M><I><o>$/ED60/;
	$multikey =~ s/^<!M><I><O>$/ED61/;
	$multikey =~ s/^<!M><I><O><%hash>$/ED62/;
	$multikey =~ s/^<!M><I><O><~nbspace>$/ED63/;
	$multikey =~ s/^<!M><I><O><~space>$/ED64/;
	$multikey =~ s/^<!M><i><p>$/ED65/;
	$multikey =~ s/^<!M><I><P>$/ED66/;
	$multikey =~ s/^<!M><i><p><d>$/ED67/;
	$multikey =~ s/^<!M><I><P><D>$/ED68/;
	$multikey =~ s/^<!M><i><p><g>$/ED69/;
	$multikey =~ s/^<!M><I><P><G>$/ED6A/;
	$multikey =~ s/^<!M><i><q>$/ED6B/;
	$multikey =~ s/^<!M><I><Q>$/ED6C/;
	$multikey =~ s/^<!M><i><q><d>$/ED6D/;
	$multikey =~ s/^<!M><I><Q><D>$/ED6E/;
	$multikey =~ s/^<!M><i><r>$/ED6F/;
	$multikey =~ s/^<!M><I><R>$/ED70/;
	$multikey =~ s/^<!M><i><r><m>$/ED71/;
	$multikey =~ s/^<!M><I><R><M>$/ED72/;
	$multikey =~ s/^<!M><i><r><m><p>$/ED73/;
	$multikey =~ s/^<!M><I><R><M><P>$/ED74/;
	$multikey =~ s/^<!M><i><r><m><p><d>$/ED75/;
	$multikey =~ s/^<!M><I><R><M><P><D>$/ED76/;
	$multikey =~ s/^<!M><i><r><m><p><g>$/ED77/;
	$multikey =~ s/^<!M><I><R><M><P><G>$/ED78/;
	$multikey =~ s/^<!M><i><r><r>$/ED79/;
	$multikey =~ s/^<!M><I><R><R>$/ED7A/;
	$multikey =~ s/^<!M><I><S>$/ED7B/;
	$multikey =~ s/^<!M><I><s>$/ED7C/;
	$multikey =~ s/^<!M><i><s>$/ED7D/;
	$multikey =~ s/^<!M><j>$/ED7E/;
	$multikey =~ s/^<!M><J>$/ED7F/;
	$multikey =~ s/^<!M><j><%exclam>$/ED80/;
	$multikey =~ s/^<!M><J><%exclam>$/ED81/;
	$multikey =~ s/^<!M><j><%greater>$/ED82/;
	$multikey =~ s/^<!M><j><%less>$/ED83/;
	$multikey =~ s/^<!M><j><%minus>$/ED84/;
	$multikey =~ s/^<!M><J><%minus>$/ED85/;
	$multikey =~ s/^<!M><j><a>$/ED86/;
	$multikey =~ s/^<!M><j><j>$/ED87/;
	$multikey =~ s/^<!M><j><o>$/ED88/;
	$multikey =~ s/^<!M><J><O>$/ED89/;
	$multikey =~ s/^<!M><j><o><d>$/ED8A/;
	$multikey =~ s/^<!M><J><O><D>$/ED8B/;
	$multikey =~ s/^<!M><j><p>$/ED8C/;
	$multikey =~ s/^<!M><J><P>$/ED8D/;
	$multikey =~ s/^<!M><j><p><y>$/ED8E/;
	$multikey =~ s/^<!M><J><P><Y>$/ED8F/;
	$multikey =~ s/^<!M><k>$/ED90/;
	$multikey =~ s/^<!M><K>$/ED91/;
	$multikey =~ s/^<!M><k><%at>$/ED92/;
	$multikey =~ s/^<!M><k><%equal>$/ED93/;
	$multikey =~ s/^<!M><K><%equal>$/ED94/;
	$multikey =~ s/^<!M><k><%minus>$/ED95/;
	$multikey =~ s/^<!M><K><%minus>$/ED96/;
	$multikey =~ s/^<!M><k><d>$/ED97/;
	$multikey =~ s/^<!M><K><D>$/ED98/;
	$multikey =~ s/^<!M><k><g>$/ED99/;
	$multikey =~ s/^<!M><K><G>$/ED9A/;
	$multikey =~ s/^<!M><k><g><s>$/ED9B/;
	$multikey =~ s/^<!M><K><G><S>$/ED9C/;
	$multikey =~ s/^<!M><k><h>$/ED9D/;
	$multikey =~ s/^<!M><K><H>$/ED9E/;
	$multikey =~ s/^<!M><k><h><r>$/ED9F/;
	$multikey =~ s/^<!M><K><H><R>$/EDA0/;
	$multikey =~ s/^<!M><k><o>$/EDA1/;
	$multikey =~ s/^<!M><K><O>$/EDA2/;
	$multikey =~ s/^<!M><k><o><m>$/EDA3/;
	$multikey =~ s/^<!M><K><O><M>$/EDA4/;
	$multikey =~ s/^<!M><k><p>$/EDA5/;
	$multikey =~ s/^<!M><K><P>$/EDA6/;
	$multikey =~ s/^<!M><k><p><w>$/EDA7/;
	$multikey =~ s/^<!M><K><P><W>$/EDA8/;
	$multikey =~ s/^<!M><k><r>$/EDA9/;
	$multikey =~ s/^<!M><K><R>$/EDAA/;
	$multikey =~ s/^<!M><k><r><w>$/EDAB/;
	$multikey =~ s/^<!M><K><R><W>$/EDAC/;
	$multikey =~ s/^<!M><k><u>$/EDAD/;
	$multikey =~ s/^<!M><K><U>$/EDAE/;
	$multikey =~ s/^<!M><k><w>$/EDAF/;
	$multikey =~ s/^<!M><K><W>$/EDB0/;
	$multikey =~ s/^<!M><k><w><d>$/EDB1/;
	$multikey =~ s/^<!M><K><W><D>$/EDB2/;
	$multikey =~ s/^<!M><k><z>$/EDB3/;
	$multikey =~ s/^<!M><K><Z>$/EDB4/;
	$multikey =~ s/^<!M><k><z><t>$/EDB5/;
	$multikey =~ s/^<!M><K><Z><T>$/EDB6/;
	$multikey =~ s/^<!M><l>$/EDB7/;
	$multikey =~ s/^<!M><L>$/EDB8/;
	$multikey =~ s/^<!M><l><%apostrophe>$/EDB9/;
	$multikey =~ s/^<!M><L><%apostrophe>$/EDBA/;
	$multikey =~ s/^<!M><l><%apostrophe><%parenleft>$/EDBB/;
	$multikey =~ s/^<!M><L><%apostrophe><%parenleft>$/EDBC/;
	$multikey =~ s/^<!M><l><%aprightsingquotmark>$/EDBD/;
	$multikey =~ s/^<!M><L><%aprightsingquotmark>$/EDBE/;
	$multikey =~ s/^<!M><l><%aprightsingquotmark><%parenleft>$/EDBF/;
	$multikey =~ s/^<!M><L><%aprightsingquotmark><%parenleft>$/EDC0/;
	$multikey =~ s/^<!M><L><%backslash>$/EDC1/;
	$multikey =~ s/^<!M><L><%backslash><%period>$/EDC2/;
	$multikey =~ s/^<!M><L><%backslash><~nbspace>$/EDC3/;
	$multikey =~ s/^<!M><L><%backslash><~space>$/EDC4/;
	$multikey =~ s/^<!M><L><%bracketright>$/EDC5/;
	$multikey =~ s/^<!M><L><%equal>$/EDC6/;
	$multikey =~ s/^<!M><l><%minus>$/EDC7/;
	$multikey =~ s/^<!M><L><%minus>$/EDC8/;
	$multikey =~ s/^<!M><l><%parenleft>$/EDC9/;
	$multikey =~ s/^<!M><L><%parenleft>$/EDCA/;
	$multikey =~ s/^<!M><l><%parenright>$/EDCB/;
	$multikey =~ s/^<!M><L><%parenright>$/EDCC/;
	$multikey =~ s/^<!M><L><%parenright><%period>$/EDCD/;
	$multikey =~ s/^<!M><L><%parenright><~nbspace>$/EDCE/;
	$multikey =~ s/^<!M><L><%parenright><~space>$/EDCF/;
	$multikey =~ s/^<!M><L><%percent>$/EDD0/;
	$multikey =~ s/^<!M><L><%percent><%percent>$/EDD1/;
	$multikey =~ s/^<!M><L><%percent><%percent><%period>$/EDD2/;
	$multikey =~ s/^<!M><L><%percent><%period>$/EDD3/;
	$multikey =~ s/^<!M><L><%percent><~nbspace>$/EDD4/;
	$multikey =~ s/^<!M><L><%percent><~space>$/EDD5/;
	$multikey =~ s/^<!M><L><%period>$/EDD6/;
	$multikey =~ s/^<!M><l><%period>$/EDD7/;
	$multikey =~ s/^<!M><L><%slash>$/EDD8/;
	$multikey =~ s/^<!M><L><%tilde>$/EDD9/;
	$multikey =~ s/^<!M><l><%tilde>$/EDDA/;
	$multikey =~ s/^<!M><l><2>$/EDDB/;
	$multikey =~ s/^<!M><L><2>$/EDDC/;
	$multikey =~ s/^<!M><l><3>$/EDDD/;
	$multikey =~ s/^<!M><L><3>$/EDDE/;
	$multikey =~ s/^<!M><l><5>$/EDDF/;
	$multikey =~ s/^<!M><L><5>$/EDE0/;
	$multikey =~ s/^<!M><l><a>$/EDE1/;
	$multikey =~ s/^<!M><L><A>$/EDE2/;
	$multikey =~ s/^<!M><l><a><k>$/EDE3/;
	$multikey =~ s/^<!M><L><A><K>$/EDE4/;
	$multikey =~ s/^<!M><l><b>$/EDE5/;
	$multikey =~ s/^<!M><L><B>$/EDE6/;
	$multikey =~ s/^<!M><l><b><%minus>$/EDE7/;
	$multikey =~ s/^<!M><l><b><p>$/EDE8/;
	$multikey =~ s/^<!M><L><B><P>$/EDE9/;
	$multikey =~ s/^<!M><l><d>$/EDEA/;
	$multikey =~ s/^<!M><L><D>$/EDEB/;
	$multikey =~ s/^<!M><l><d><p>$/EDEC/;
	$multikey =~ s/^<!M><L><D><P>$/EDED/;
	$multikey =~ s/^<!M><l><d><p><e>$/EDEE/;
	$multikey =~ s/^<!M><L><D><P><E>$/EDEF/;
	$multikey =~ s/^<!M><l><e>$/EDF0/;
	$multikey =~ s/^<!M><L><E>$/EDF1/;
	$multikey =~ s/^<!M><l><e><o>$/EDF2/;
	$multikey =~ s/^<!M><L><E><O>$/EDF3/;
	$multikey =~ s/^<!M><l><e><z>$/EDF4/;
	$multikey =~ s/^<!M><l><e><z><h>$/EDF5/;
	$multikey =~ s/^<!M><l><f>$/EDF6/;
	$multikey =~ s/^<!M><L><F>$/EDF7/;
	$multikey =~ s/^<!M><l><i>$/EDF8/;
	$multikey =~ s/^<!M><L><I>$/EDF9/;
	$multikey =~ s/^<!M><l><i><b>$/EDFA/;
	$multikey =~ s/^<!M><L><I><B>$/EDFB/;
	$multikey =~ s/^<!M><l><i><b><r>$/EDFC/;
	$multikey =~ s/^<!M><L><I><B><R>$/EDFD/;
	$multikey =~ s/^<!M><l><i><o>$/EDFE/;
	$multikey =~ s/^<!M><L><I><O>$/EDFF/;
	$multikey =~ s/^<!M><l><i><o><n>$/EE00/;
	$multikey =~ s/^<!M><L><I><O><N>$/EE01/;
	$multikey =~ s/^<!M><L><J>$/EE02/;
	$multikey =~ s/^<!M><L><j>$/EE03/;
	$multikey =~ s/^<!M><l><j>$/EE04/;
	$multikey =~ s/^<!M><L><L>$/EE05/;
	$multikey =~ s/^<!M><L><l>$/EE06/;
	$multikey =~ s/^<!M><l><l>$/EE07/;
	$multikey =~ s/^<!M><L><N>$/EE08/;
	$multikey =~ s/^<!M><L><P>$/EE09/;
	$multikey =~ s/^<!M><l><p>$/EE0A/;
	$multikey =~ s/^<!M><L><p>$/EE0B/;
	$multikey =~ s/^<!M><L><p><a>$/EE0C/;
	$multikey =~ s/^<!M><L><p><a><r>$/EE0D/;
	$multikey =~ s/^<!M><L><p><a><r><e>$/EE0E/;
	$multikey =~ s/^<!M><L><p><a><r><e><n>$/EE0F/;
	$multikey =~ s/^<!M><L><p><a><r><e><n><g>$/EE10/;
	$multikey =~ s/^<!M><L><p><a><r><e><n><g><t>$/EE11/;
	$multikey =~ s/^<!M><l><r>$/EE12/;
	$multikey =~ s/^<!M><L><R>$/EE13/;
	$multikey =~ s/^<!M><l><r><e>$/EE14/;
	$multikey =~ s/^<!M><L><R><E>$/EE15/;
	$multikey =~ s/^<!M><l><r><e><t>$/EE16/;
	$multikey =~ s/^<!M><L><R><E><T>$/EE17/;
	$multikey =~ s/^<!M><l><s>$/EE18/;
	$multikey =~ s/^<!M><l><u>$/EE19/;
	$multikey =~ s/^<!M><l><z>$/EE1A/;
	$multikey =~ s/^<!M><L><Z>$/EE1B/;
	$multikey =~ s/^<!M><L><z>$/EE1C/;
	$multikey =~ s/^<!M><L><~nbspace>$/EE1D/;
	$multikey =~ s/^<!M><L><~space>$/EE1E/;
	$multikey =~ s/^<!M><m>$/EE1F/;
	$multikey =~ s/^<!M><M>$/EE20/;
	$multikey =~ s/^<!M><m><%equal>$/EE21/;
	$multikey =~ s/^<!M><m><%greater>$/EE22/;
	$multikey =~ s/^<!M><m><%less>$/EE23/;
	$multikey =~ s/^<!M><m><%percent>$/EE24/;
	$multikey =~ s/^<!M><m><%slash>$/EE25/;
	$multikey =~ s/^<!M><M><%tilde>$/EE26/;
	$multikey =~ s/^<!M><m><c>$/EE27/;
	$multikey =~ s/^<!M><M><C>$/EE28/;
	$multikey =~ s/^<!M><m><d>$/EE29/;
	$multikey =~ s/^<!M><M><D>$/EE2A/;
	$multikey =~ s/^<!M><m><h>$/EE2B/;
	$multikey =~ s/^<!M><M><h>$/EE2C/;
	$multikey =~ s/^<!M><M><H>$/EE2D/;
	$multikey =~ s/^<!M><m><k>$/EE2E/;
	$multikey =~ s/^<!M><M><K>$/EE2F/;
	$multikey =~ s/^<!M><m><k><d>$/EE30/;
	$multikey =~ s/^<!M><M><K><D>$/EE31/;
	$multikey =~ s/^<!M><m><n>$/EE32/;
	$multikey =~ s/^<!M><M><N>$/EE33/;
	$multikey =~ s/^<!M><m><n><t>$/EE34/;
	$multikey =~ s/^<!M><M><N><T>$/EE35/;
	$multikey =~ s/^<!M><m><r>$/EE36/;
	$multikey =~ s/^<!M><M><R>$/EE37/;
	$multikey =~ s/^<!M><m><s>$/EE38/;
	$multikey =~ s/^<!M><M><S>$/EE39/;
	$multikey =~ s/^<!M><m><t>$/EE3A/;
	$multikey =~ s/^<!M><M><T>$/EE3B/;
	$multikey =~ s/^<!M><m><u>$/EE3C/;
	$multikey =~ s/^<!M><M><U>$/EE3D/;
	$multikey =~ s/^<!M><m><u><l>$/EE3E/;
	$multikey =~ s/^<!M><M><U><L>$/EE3F/;
	$multikey =~ s/^<!M><m><u><r>$/EE40/;
	$multikey =~ s/^<!M><M><U><R>$/EE41/;
	$multikey =~ s/^<!M><m><u><~space>$/EE42/;
	$multikey =~ s/^<!M><m><v>$/EE43/;
	$multikey =~ s/^<!M><M><V>$/EE44/;
	$multikey =~ s/^<!M><m><v><r>$/EE45/;
	$multikey =~ s/^<!M><M><V><R>$/EE46/;
	$multikey =~ s/^<!M><m><~nbspace>$/EE47/;
	$multikey =~ s/^<!M><m><~space>$/EE48/;
	$multikey =~ s/^<!M><multiply>$/EE49/;
	$multikey =~ s/^<!M><multiply><division>$/EE4A/;
	$multikey =~ s/^<!M><N>$/EE4B/;
	$multikey =~ s/^<!M><n>$/EE4C/;
	$multikey =~ s/^<!M><n><%bar>$/EE4D/;
	$multikey =~ s/^<!M><n><%bracketleft>$/EE4E/;
	$multikey =~ s/^<!M><N><%bracketleft>$/EE4F/;
	$multikey =~ s/^<!M><n><%bracketright>$/EE50/;
	$multikey =~ s/^<!M><N><%bracketright>$/EE51/;
	$multikey =~ s/^<!M><n><%circum>$/EE52/;
	$multikey =~ s/^<!M><N><%equal>$/EE53/;
	$multikey =~ s/^<!M><n><%equal>$/EE54/;
	$multikey =~ s/^<!M><N><%greater>$/EE55/;
	$multikey =~ s/^<!M><n><%greater>$/EE56/;
	$multikey =~ s/^<!M><n><%hash>$/EE57/;
	$multikey =~ s/^<!M><n><%less>$/EE58/;
	$multikey =~ s/^<!M><n><%period>$/EE59/;
	$multikey =~ s/^<!M><n><%underscore>$/EE5A/;
	$multikey =~ s/^<!M><n><%underscore><u>$/EE5B/;
	$multikey =~ s/^<!M><n><%underscore><~nbspace>$/EE5C/;
	$multikey =~ s/^<!M><n><%underscore><~space>$/EE5D/;
	$multikey =~ s/^<!M><n><2>$/EE5E/;
	$multikey =~ s/^<!M><N><2>$/EE5F/;
	$multikey =~ s/^<!M><n><3>$/EE60/;
	$multikey =~ s/^<!M><N><3>$/EE61/;
	$multikey =~ s/^<!M><n><4>$/EE62/;
	$multikey =~ s/^<!M><N><4>$/EE63/;
	$multikey =~ s/^<!M><n><5>$/EE64/;
	$multikey =~ s/^<!M><N><5>$/EE65/;
	$multikey =~ s/^<!M><n><8>$/EE66/;
	$multikey =~ s/^<!M><N><8>$/EE67/;
	$multikey =~ s/^<!M><N><A>$/EE68/;
	$multikey =~ s/^<!M><n><a>$/EE69/;
	$multikey =~ s/^<!M><n><a><n>$/EE6A/;
	$multikey =~ s/^<!M><n><a><~nbspace>$/EE6B/;
	$multikey =~ s/^<!M><n><a><~space>$/EE6C/;
	$multikey =~ s/^<!M><n><b>$/EE6D/;
	$multikey =~ s/^<!M><N><B>$/EE6E/;
	$multikey =~ s/^<!M><n><b><s>$/EE6F/;
	$multikey =~ s/^<!M><N><B><S>$/EE70/;
	$multikey =~ s/^<!M><n><b><t>$/EE71/;
	$multikey =~ s/^<!M><N><B><T>$/EE72/;
	$multikey =~ s/^<!M><n><e>$/EE73/;
	$multikey =~ s/^<!M><N><E>$/EE74/;
	$multikey =~ s/^<!M><N><g>$/EE75/;
	$multikey =~ s/^<!M><N><G>$/EE76/;
	$multikey =~ s/^<!M><n><g>$/EE77/;
	$multikey =~ s/^<!M><n><g><n>$/EE78/;
	$multikey =~ s/^<!M><N><G><N>$/EE79/;
	$multikey =~ s/^<!M><N><G><~space>$/EE7A/;
	$multikey =~ s/^<!M><n><g><~space>$/EE7B/;
	$multikey =~ s/^<!M><n><I>$/EE7C/;
	$multikey =~ s/^<!M><N><J>$/EE7D/;
	$multikey =~ s/^<!M><N><j>$/EE7E/;
	$multikey =~ s/^<!M><n><j>$/EE7F/;
	$multikey =~ s/^<!M><n><m>$/EE80/;
	$multikey =~ s/^<!M><N><M>$/EE81/;
	$multikey =~ s/^<!M><n><m><l>$/EE82/;
	$multikey =~ s/^<!M><N><M><L>$/EE83/;
	$multikey =~ s/^<!M><N><N>$/EE84/;
	$multikey =~ s/^<!M><n><n>$/EE85/;
	$multikey =~ s/^<!M><N><o>$/EE86/;
	$multikey =~ s/^<!M><n><O>$/EE87/;
	$multikey =~ s/^<!M><n><o>$/EE88/;
	$multikey =~ s/^<!M><N><O>$/EE89/;
	$multikey =~ s/^<!M><n><o><%underscore>$/EE8A/;
	$multikey =~ s/^<!M><N><O><%underscore>$/EE8B/;
	$multikey =~ s/^<!M><n><o><r>$/EE8C/;
	$multikey =~ s/^<!M><N><O><R>$/EE8D/;
	$multikey =~ s/^<!M><n><p>$/EE8E/;
	$multikey =~ s/^<!M><N><P>$/EE8F/;
	$multikey =~ s/^<!M><n><p><r>$/EE90/;
	$multikey =~ s/^<!M><N><P><R>$/EE91/;
	$multikey =~ s/^<!M><n><s>$/EE92/;
	$multikey =~ s/^<!M><N><S>$/EE93/;
	$multikey =~ s/^<!M><n><u>$/EE94/;
	$multikey =~ s/^<!M><n><u><m>$/EE95/;
	$multikey =~ s/^<!M><n><u><~nbspace>$/EE96/;
	$multikey =~ s/^<!M><n><u><~space>$/EE97/;
	$multikey =~ s/^<!M><n><~nbspace>$/EE98/;
	$multikey =~ s/^<!M><N><~nbspace>$/EE99/;
	$multikey =~ s/^<!M><n><~space>$/EE9A/;
	$multikey =~ s/^<!M><N><~space>$/EE9B/;
	$multikey =~ s/^<!M><o>$/EE9C/;
	$multikey =~ s/^<!M><O>$/EE9D/;
	$multikey =~ s/^<!M><o><%asterisk>$/EE9E/;
	$multikey =~ s/^<!M><O><%asterisk>$/EE9F/;
	$multikey =~ s/^<!M><o><%backslash>$/EEA0/;
	$multikey =~ s/^<!M><O><%backslash>$/EEA1/;
	$multikey =~ s/^<!M><o><%backslash><c>$/EEA2/;
	$multikey =~ s/^<!M><o><%backslash><C>$/EEA3/;
	$multikey =~ s/^<!M><O><%backslash><C>$/EEA4/;
	$multikey =~ s/^<!M><O><%backslash><c>$/EEA5/;
	$multikey =~ s/^<!M><O><%backslash><~nbspace>$/EEA6/;
	$multikey =~ s/^<!M><o><%backslash><~nbspace>$/EEA7/;
	$multikey =~ s/^<!M><O><%backslash><~space>$/EEA8/;
	$multikey =~ s/^<!M><o><%backslash><~space>$/EEA9/;
	$multikey =~ s/^<!M><O><%bar>$/EEAA/;
	$multikey =~ s/^<!M><o><%bar>$/EEAB/;
	$multikey =~ s/^<!M><O><%bar><%bar>$/EEAC/;
	$multikey =~ s/^<!M><O><%bar><%hash>$/EEAD/;
	$multikey =~ s/^<!M><o><%bar><%underscore>$/EEAE/;
	$multikey =~ s/^<!M><O><%bar><%underscore>$/EEAF/;
	$multikey =~ s/^<!M><O><%bar><~nbspace>$/EEB0/;
	$multikey =~ s/^<!M><o><%bar><~nbspace>$/EEB1/;
	$multikey =~ s/^<!M><O><%bar><~space>$/EEB2/;
	$multikey =~ s/^<!M><o><%bar><~space>$/EEB3/;
	$multikey =~ s/^<!M><o><%circum>$/EEB4/;
	$multikey =~ s/^<!M><o><%colon>$/EEB5/;
	$multikey =~ s/^<!M><O><%colon>$/EEB6/;
	$multikey =~ s/^<!M><O><%colon><%minus>$/EEB7/;
	$multikey =~ s/^<!M><o><%colon><%minus>$/EEB8/;
	$multikey =~ s/^<!M><O><%colon><%slash>$/EEB9/;
	$multikey =~ s/^<!M><o><%colon><%slash>$/EEBA/;
	$multikey =~ s/^<!M><o><%colon><~nbspace>$/EEBB/;
	$multikey =~ s/^<!M><o><%colon><~space>$/EEBC/;
	$multikey =~ s/^<!M><o><%equal>$/EEBD/;
	$multikey =~ s/^<!M><O><%equal>$/EEBE/;
	$multikey =~ s/^<!M><O><%exclam>$/EEBF/;
	$multikey =~ s/^<!M><o><%greater>$/EEC0/;
	$multikey =~ s/^<!M><O><%greater>$/EEC1/;
	$multikey =~ s/^<!M><o><%hash>$/EEC2/;
	$multikey =~ s/^<!M><O><%hash>$/EEC3/;
	$multikey =~ s/^<!M><O><%hash><%bar>$/EEC4/;
	$multikey =~ s/^<!M><O><%hash><%exclam>$/EEC5/;
	$multikey =~ s/^<!M><O><%hash><%minus>$/EEC6/;
	$multikey =~ s/^<!M><o><%hash><e>$/EEC7/;
	$multikey =~ s/^<!M><O><%hash><~nbspace>$/EEC8/;
	$multikey =~ s/^<!M><O><%hash><~space>$/EEC9/;
	$multikey =~ s/^<!M><o><%less>$/EECA/;
	$multikey =~ s/^<!M><O><%less>$/EECB/;
	$multikey =~ s/^<!M><O><%less><%exclam>$/EECC/;
	$multikey =~ s/^<!M><O><%less><~nbspace>$/EECD/;
	$multikey =~ s/^<!M><O><%less><~space>$/EECE/;
	$multikey =~ s/^<!M><o><%minus>$/EECF/;
	$multikey =~ s/^<!M><O><%minus>$/EED0/;
	$multikey =~ s/^<!M><O><%minus><%bar>$/EED1/;
	$multikey =~ s/^<!M><O><%minus><%colon>$/EED2/;
	$multikey =~ s/^<!M><o><%minus><%colon>$/EED3/;
	$multikey =~ s/^<!M><o><%minus><%greater>$/EED4/;
	$multikey =~ s/^<!M><O><%minus><%hash>$/EED5/;
	$multikey =~ s/^<!M><o><%minus><%minus>$/EED6/;
	$multikey =~ s/^<!M><o><%minus><%period>$/EED7/;
	$multikey =~ s/^<!M><o><%minus><o>$/EED8/;
	$multikey =~ s/^<!M><o><%minus><~nbspace>$/EED9/;
	$multikey =~ s/^<!M><O><%minus><~nbspace>$/EEDA/;
	$multikey =~ s/^<!M><o><%minus><~space>$/EEDB/;
	$multikey =~ s/^<!M><O><%minus><~space>$/EEDC/;
	$multikey =~ s/^<!M><o><%parenright>$/EEDD/;
	$multikey =~ s/^<!M><o><%percent>$/EEDE/;
	$multikey =~ s/^<!M><O><%percent>$/EEDF/;
	$multikey =~ s/^<!M><O><%percent><C>$/EEE0/;
	$multikey =~ s/^<!M><O><%percent><~nbspace>$/EEE1/;
	$multikey =~ s/^<!M><O><%percent><~space>$/EEE2/;
	$multikey =~ s/^<!M><o><%period>$/EEE3/;
	$multikey =~ s/^<!M><O><%period>$/EEE4/;
	$multikey =~ s/^<!M><o><%plus>$/EEE5/;
	$multikey =~ s/^<!M><O><%plus>$/EEE6/;
	$multikey =~ s/^<!M><o><%plus><%minus>$/EEE7/;
	$multikey =~ s/^<!M><O><%plus><%minus>$/EEE8/;
	$multikey =~ s/^<!M><o><%plus><~nbspace>$/EEE9/;
	$multikey =~ s/^<!M><O><%plus><~nbspace>$/EEEA/;
	$multikey =~ s/^<!M><o><%plus><~space>$/EEEB/;
	$multikey =~ s/^<!M><O><%plus><~space>$/EEEC/;
	$multikey =~ s/^<!M><o><%semicolon>$/EEED/;
	$multikey =~ s/^<!M><o><%semsection>$/EEEE/;
	$multikey =~ s/^<!M><O><%slash>$/EEEF/;
	$multikey =~ s/^<!M><o><%slash>$/EEF0/;
	$multikey =~ s/^<!M><o><%slash><%greater>$/EEF1/;
	$multikey =~ s/^<!M><o><%slash><~nbspace>$/EEF2/;
	$multikey =~ s/^<!M><o><%slash><~space>$/EEF3/;
	$multikey =~ s/^<!M><o><%tilde>$/EEF4/;
	$multikey =~ s/^<!M><o><%underscore>$/EEF5/;
	$multikey =~ s/^<!M><O><%underscore>$/EEF6/;
	$multikey =~ s/^<!M><o><0>$/EEF7/;
	$multikey =~ s/^<!M><O><0>$/EEF8/;
	$multikey =~ s/^<!M><o><1>$/EEF9/;
	$multikey =~ s/^<!M><O><1>$/EEFA/;
	$multikey =~ s/^<!M><o><2>$/EEFB/;
	$multikey =~ s/^<!M><O><2>$/EEFC/;
	$multikey =~ s/^<!M><o><3>$/EEFD/;
	$multikey =~ s/^<!M><O><3>$/EEFE/;
	$multikey =~ s/^<!M><o><4>$/EEFF/;
	$multikey =~ s/^<!M><O><4>$/EF00/;
	$multikey =~ s/^<!M><o><5>$/EF01/;
	$multikey =~ s/^<!M><O><5>$/EF02/;
	$multikey =~ s/^<!M><o><6>$/EF03/;
	$multikey =~ s/^<!M><O><6>$/EF04/;
	$multikey =~ s/^<!M><o><7>$/EF05/;
	$multikey =~ s/^<!M><O><7>$/EF06/;
	$multikey =~ s/^<!M><o><8>$/EF07/;
	$multikey =~ s/^<!M><O><8>$/EF08/;
	$multikey =~ s/^<!M><o><9>$/EF09/;
	$multikey =~ s/^<!M><O><9>$/EF0A/;
	$multikey =~ s/^<!M><o><A>$/EF0B/;
	$multikey =~ s/^<!M><o><a>$/EF0C/;
	$multikey =~ s/^<!M><O><A>$/EF0D/;
	$multikey =~ s/^<!M><O><a>$/EF0E/;
	$multikey =~ s/^<!M><o><b>$/EF0F/;
	$multikey =~ s/^<!M><O><b>$/EF10/;
	$multikey =~ s/^<!M><O><B>$/EF11/;
	$multikey =~ s/^<!M><o><C>$/EF12/;
	$multikey =~ s/^<!M><O><C>$/EF13/;
	$multikey =~ s/^<!M><o><c>$/EF14/;
	$multikey =~ s/^<!M><O><c>$/EF15/;
	$multikey =~ s/^<!M><O><E>$/EF16/;
	$multikey =~ s/^<!M><O><e>$/EF17/;
	$multikey =~ s/^<!M><o><e>$/EF18/;
	$multikey =~ s/^<!M><o><h>$/EF19/;
	$multikey =~ s/^<!M><O><h>$/EF1A/;
	$multikey =~ s/^<!M><O><H>$/EF1B/;
	$multikey =~ s/^<!M><O><I>$/EF1C/;
	$multikey =~ s/^<!M><o><I>$/EF1D/;
	$multikey =~ s/^<!M><o><i>$/EF1E/;
	$multikey =~ s/^<!M><o><i><n>$/EF1F/;
	$multikey =~ s/^<!M><o><i><n><f>$/EF20/;
	$multikey =~ s/^<!M><o><i><~nbspace>$/EF21/;
	$multikey =~ s/^<!M><o><i><~space>$/EF22/;
	$multikey =~ s/^<!M><o><m>$/EF23/;
	$multikey =~ s/^<!M><O><M>$/EF24/;
	$multikey =~ s/^<!M><o><m><r>$/EF25/;
	$multikey =~ s/^<!M><O><M><R>$/EF26/;
	$multikey =~ s/^<!M><O><O>$/EF27/;
	$multikey =~ s/^<!M><o><o>$/EF28/;
	$multikey =~ s/^<!M><o><O>$/EF29/;
	$multikey =~ s/^<!M><O><o>$/EF2A/;
	$multikey =~ s/^<!M><O><o><x>$/EF2B/;
	$multikey =~ s/^<!M><O><o><~nbspace>$/EF2C/;
	$multikey =~ s/^<!M><O><o><~space>$/EF2D/;
	$multikey =~ s/^<!M><o><P>$/EF2E/;
	$multikey =~ s/^<!M><O><p>$/EF2F/;
	$multikey =~ s/^<!M><o><p>$/EF30/;
	$multikey =~ s/^<!M><O><P>$/EF31/;
	$multikey =~ s/^<!M><o><p><h>$/EF32/;
	$multikey =~ s/^<!M><O><P><H>$/EF33/;
	$multikey =~ s/^<!M><o><p><t>$/EF34/;
	$multikey =~ s/^<!M><O><P><T>$/EF35/;
	$multikey =~ s/^<!M><o><R>$/EF36/;
	$multikey =~ s/^<!M><O><r>$/EF37/;
	$multikey =~ s/^<!M><o><r>$/EF38/;
	$multikey =~ s/^<!M><O><R>$/EF39/;
	$multikey =~ s/^<!M><O><S>$/EF3A/;
	$multikey =~ s/^<!M><o><S>$/EF3B/;
	$multikey =~ s/^<!M><o><s>$/EF3C/;
	$multikey =~ s/^<!M><o><s><t>$/EF3D/;
	$multikey =~ s/^<!M><o><s><u>$/EF3E/;
	$multikey =~ s/^<!M><o><s><u><p>$/EF3F/;
	$multikey =~ s/^<!M><o><t>$/EF40/;
	$multikey =~ s/^<!M><O><T>$/EF41/;
	$multikey =~ s/^<!M><o><T>$/EF42/;
	$multikey =~ s/^<!M><o><T><%percent>$/EF43/;
	$multikey =~ s/^<!M><o><t><d>$/EF44/;
	$multikey =~ s/^<!M><O><T><D>$/EF45/;
	$multikey =~ s/^<!M><o><t><h>$/EF46/;
	$multikey =~ s/^<!M><O><T><H>$/EF47/;
	$multikey =~ s/^<!M><o><t><r>$/EF48/;
	$multikey =~ s/^<!M><O><T><R>$/EF49/;
	$multikey =~ s/^<!M><o><T><T>$/EF4A/;
	$multikey =~ s/^<!M><o><t><u>$/EF4B/;
	$multikey =~ s/^<!M><O><T><U>$/EF4C/;
	$multikey =~ s/^<!M><O><U>$/EF4D/;
	$multikey =~ s/^<!M><O><u>$/EF4E/;
	$multikey =~ s/^<!M><o><u>$/EF4F/;
	$multikey =~ s/^<!M><o><x>$/EF50/;
	$multikey =~ s/^<!M><O><X>$/EF51/;
	$multikey =~ s/^<!M><O><x>$/EF52/;
	$multikey =~ s/^<!M><o><~nbspace>$/EF53/;
	$multikey =~ s/^<!M><O><~nbspace>$/EF54/;
	$multikey =~ s/^<!M><o><~space>$/EF55/;
	$multikey =~ s/^<!M><O><~space>$/EF56/;
	$multikey =~ s/^<!M><p>$/EF57/;
	$multikey =~ s/^<!M><P>$/EF58/;
	$multikey =~ s/^<!M><p><%bar>$/EF59/;
	$multikey =~ s/^<!M><p><%bar><%comma>$/EF5A/;
	$multikey =~ s/^<!M><p><%bar><~nbspace>$/EF5B/;
	$multikey =~ s/^<!M><p><%bar><~space>$/EF5C/;
	$multikey =~ s/^<!M><p><%comma>$/EF5D/;
	$multikey =~ s/^<!M><p><%equal>$/EF5E/;
	$multikey =~ s/^<!M><P><%equal>$/EF5F/;
	$multikey =~ s/^<!M><p><%exclam>$/EF60/;
	$multikey =~ s/^<!M><P><%exclam>$/EF61/;
	$multikey =~ s/^<!M><p><%greater>$/EF62/;
	$multikey =~ s/^<!M><p><%less>$/EF63/;
	$multikey =~ s/^<!M><P><%minus>$/EF64/;
	$multikey =~ s/^<!M><p><%minus>$/EF65/;
	$multikey =~ s/^<!M><P><%percent>$/EF66/;
	$multikey =~ s/^<!M><p><%percent>$/EF67/;
	$multikey =~ s/^<!M><p><%slash>$/EF68/;
	$multikey =~ s/^<!M><P><%tilde>$/EF69/;
	$multikey =~ s/^<!M><P><2>$/EF6A/;
	$multikey =~ s/^<!M><p><2>$/EF6B/;
	$multikey =~ s/^<!M><p><a>$/EF6C/;
	$multikey =~ s/^<!M><P><A>$/EF6D/;
	$multikey =~ s/^<!M><p><a><c>$/EF6E/;
	$multikey =~ s/^<!M><P><A><C>$/EF6F/;
	$multikey =~ s/^<!M><p><a><c><a>$/EF70/;
	$multikey =~ s/^<!M><P><A><C><A>$/EF71/;
	$multikey =~ s/^<!M><p><a><c><d>$/EF72/;
	$multikey =~ s/^<!M><P><A><C><D>$/EF73/;
	$multikey =~ s/^<!M><p><a><r>$/EF74/;
	$multikey =~ s/^<!M><P><A><R>$/EF75/;
	$multikey =~ s/^<!M><p><a><r><c>$/EF76/;
	$multikey =~ s/^<!M><P><A><R><C>$/EF77/;
	$multikey =~ s/^<!M><p><a><r><o>$/EF78/;
	$multikey =~ s/^<!M><P><A><R><O>$/EF79/;
	$multikey =~ s/^<!M><p><a><t>$/EF7A/;
	$multikey =~ s/^<!M><P><A><T>$/EF7B/;
	$multikey =~ s/^<!M><p><a><t><b>$/EF7C/;
	$multikey =~ s/^<!M><P><A><T><B>$/EF7D/;
	$multikey =~ s/^<!M><p><a><t><h>$/EF7E/;
	$multikey =~ s/^<!M><P><A><T><H>$/EF7F/;
	$multikey =~ s/^<!M><p><d>$/EF80/;
	$multikey =~ s/^<!M><p><d><i>$/EF81/;
	$multikey =~ s/^<!M><p><e>$/EF82/;
	$multikey =~ s/^<!M><P><e>$/EF83/;
	$multikey =~ s/^<!M><P><E>$/EF84/;
	$multikey =~ s/^<!M><p><e><h>$/EF85/;
	$multikey =~ s/^<!M><P><E><H>$/EF86/;
	$multikey =~ s/^<!M><p><e><h><d>$/EF87/;
	$multikey =~ s/^<!M><P><E><H><D>$/EF88/;
	$multikey =~ s/^<!M><p><e><l>$/EF89/;
	$multikey =~ s/^<!M><P><E><L>$/EF8A/;
	$multikey =~ s/^<!M><p><e><l><d>$/EF8B/;
	$multikey =~ s/^<!M><P><E><L><D>$/EF8C/;
	$multikey =~ s/^<!M><p><e><r>$/EF8D/;
	$multikey =~ s/^<!M><P><e><r>$/EF8E/;
	$multikey =~ s/^<!M><P><E><R>$/EF8F/;
	$multikey =~ s/^<!M><p><e><t>$/EF90/;
	$multikey =~ s/^<!M><P><E><T>$/EF91/;
	$multikey =~ s/^<!M><P><f>$/EF92/;
	$multikey =~ s/^<!M><p><h>$/EF93/;
	$multikey =~ s/^<!M><P><H>$/EF94/;
	$multikey =~ s/^<!M><p><h><p>$/EF95/;
	$multikey =~ s/^<!M><P><H><P>$/EF96/;
	$multikey =~ s/^<!M><p><i>$/EF97/;
	$multikey =~ s/^<!M><P><I>$/EF98/;
	$multikey =~ s/^<!M><p><i><s>$/EF99/;
	$multikey =~ s/^<!M><P><I><S>$/EF9A/;
	$multikey =~ s/^<!M><p><i><s><c>$/EF9B/;
	$multikey =~ s/^<!M><P><I><S><C>$/EF9C/;
	$multikey =~ s/^<!M><p><i><~nbspace>$/EF9D/;
	$multikey =~ s/^<!M><p><i><~space>$/EF9E/;
	$multikey =~ s/^<!M><p><l>$/EF9F/;
	$multikey =~ s/^<!M><P><L>$/EFA0/;
	$multikey =~ s/^<!M><P><l>$/EFA1/;
	$multikey =~ s/^<!M><P><L><A>$/EFA2/;
	$multikey =~ s/^<!M><P><l><a>$/EFA3/;
	$multikey =~ s/^<!M><p><l><a>$/EFA4/;
	$multikey =~ s/^<!M><p><l><n>$/EFA5/;
	$multikey =~ s/^<!M><P><L><N>$/EFA6/;
	$multikey =~ s/^<!M><P><o>$/EFA7/;
	$multikey =~ s/^<!M><p><O>$/EFA8/;
	$multikey =~ s/^<!M><p><o>$/EFA9/;
	$multikey =~ s/^<!M><P><O>$/EFAA/;
	$multikey =~ s/^<!M><p><o><i>$/EFAB/;
	$multikey =~ s/^<!M><P><O><I>$/EFAC/;
	$multikey =~ s/^<!M><p><o><i><s>$/EFAD/;
	$multikey =~ s/^<!M><P><O><I><S>$/EFAE/;
	$multikey =~ s/^<!M><p><p>$/EFAF/;
	$multikey =~ s/^<!M><P><P>$/EFB0/;
	$multikey =~ s/^<!M><p><p><%at>$/EFB1/;
	$multikey =~ s/^<!M><P><P><%at>$/EFB2/;
	$multikey =~ s/^<!M><p><p><c>$/EFB3/;
	$multikey =~ s/^<!M><P><P><C>$/EFB4/;
	$multikey =~ s/^<!M><p><p><c><a>$/EFB5/;
	$multikey =~ s/^<!M><P><P><C><A>$/EFB6/;
	$multikey =~ s/^<!M><p><p><c><c>$/EFB7/;
	$multikey =~ s/^<!M><P><P><C><C>$/EFB8/;
	$multikey =~ s/^<!M><p><p><c><d>$/EFB9/;
	$multikey =~ s/^<!M><P><P><C><D>$/EFBA/;
	$multikey =~ s/^<!M><p><p><m>$/EFBB/;
	$multikey =~ s/^<!M><P><P><M>$/EFBC/;
	$multikey =~ s/^<!M><p><p><m><d>$/EFBD/;
	$multikey =~ s/^<!M><P><P><M><D>$/EFBE/;
	$multikey =~ s/^<!M><p><p><m><g>$/EFBF/;
	$multikey =~ s/^<!M><P><P><M><G>$/EFC0/;
	$multikey =~ s/^<!M><p><p><p>$/EFC1/;
	$multikey =~ s/^<!M><P><P><P>$/EFC2/;
	$multikey =~ s/^<!M><p><p><r>$/EFC3/;
	$multikey =~ s/^<!M><P><P><R>$/EFC4/;
	$multikey =~ s/^<!M><p><p><r><c>$/EFC5/;
	$multikey =~ s/^<!M><P><P><R><C>$/EFC6/;
	$multikey =~ s/^<!M><p><p><r><d>$/EFC7/;
	$multikey =~ s/^<!M><P><P><R><D>$/EFC8/;
	$multikey =~ s/^<!M><p><p><r><e>$/EFC9/;
	$multikey =~ s/^<!M><P><P><R><E>$/EFCA/;
	$multikey =~ s/^<!M><p><p><r><o>$/EFCB/;
	$multikey =~ s/^<!M><P><P><R><O>$/EFCC/;
	$multikey =~ s/^<!M><p><p><t>$/EFCD/;
	$multikey =~ s/^<!M><P><P><T>$/EFCE/;
	$multikey =~ s/^<!M><p><p><t><b>$/EFCF/;
	$multikey =~ s/^<!M><P><P><T><B>$/EFD0/;
	$multikey =~ s/^<!M><p><p><t><d>$/EFD1/;
	$multikey =~ s/^<!M><P><P><T><D>$/EFD2/;
	$multikey =~ s/^<!M><p><p><t><g>$/EFD3/;
	$multikey =~ s/^<!M><P><P><T><G>$/EFD4/;
	$multikey =~ s/^<!M><p><p><t><h>$/EFD5/;
	$multikey =~ s/^<!M><P><P><T><H>$/EFD6/;
	$multikey =~ s/^<!M><P><P><~nbspace>$/EFD7/;
	$multikey =~ s/^<!M><P><P><~space>$/EFD8/;
	$multikey =~ s/^<!M><p><s>$/EFD9/;
	$multikey =~ s/^<!M><P><S>$/EFDA/;
	$multikey =~ s/^<!M><P><t>$/EFDB/;
	$multikey =~ s/^<!M><p><t>$/EFDC/;
	$multikey =~ s/^<!M><P><T>$/EFDD/;
	$multikey =~ s/^<!M><p><t><0>$/EFDE/;
	$multikey =~ s/^<!M><P><T><0>$/EFDF/;
	$multikey =~ s/^<!M><p><t><1>$/EFE0/;
	$multikey =~ s/^<!M><P><T><1>$/EFE1/;
	$multikey =~ s/^<!M><p><t><2>$/EFE2/;
	$multikey =~ s/^<!M><P><T><2>$/EFE3/;
	$multikey =~ s/^<!M><p><t><3>$/EFE4/;
	$multikey =~ s/^<!M><P><T><3>$/EFE5/;
	$multikey =~ s/^<!M><p><t><4>$/EFE6/;
	$multikey =~ s/^<!M><P><T><4>$/EFE7/;
	$multikey =~ s/^<!M><p><t><5>$/EFE8/;
	$multikey =~ s/^<!M><P><T><5>$/EFE9/;
	$multikey =~ s/^<!M><p><t><6>$/EFEA/;
	$multikey =~ s/^<!M><P><T><6>$/EFEB/;
	$multikey =~ s/^<!M><p><t><7>$/EFEC/;
	$multikey =~ s/^<!M><P><T><7>$/EFED/;
	$multikey =~ s/^<!M><p><t><8>$/EFEE/;
	$multikey =~ s/^<!M><P><T><8>$/EFEF/;
	$multikey =~ s/^<!M><p><t><9>$/EFF0/;
	$multikey =~ s/^<!M><P><T><9>$/EFF1/;
	$multikey =~ s/^<!M><p><v>$/EFF2/;
	$multikey =~ s/^<!M><P><V>$/EFF3/;
	$multikey =~ s/^<!M><p><v><c>$/EFF4/;
	$multikey =~ s/^<!M><P><V><C>$/EFF5/;
	$multikey =~ s/^<!M><p><y>$/EFF6/;
	$multikey =~ s/^<!M><P><Y>$/EFF7/;
	$multikey =~ s/^<!M><p><y><g>$/EFF8/;
	$multikey =~ s/^<!M><P><Y><G>$/EFF9/;
	$multikey =~ s/^<!M><p><~nbspace>$/EFFA/;
	$multikey =~ s/^<!M><P><~nbspace>$/EFFB/;
	$multikey =~ s/^<!M><p><~space>$/EFFC/;
	$multikey =~ s/^<!M><P><~space>$/EFFD/;
	$multikey =~ s/^<!M><q>$/EFFE/;
	$multikey =~ s/^<!M><Q>$/EFFF/;
	$multikey =~ s/^<!M><q><%hash>$/F000/;
	$multikey =~ s/^<!M><Q><%hash>$/F001/;
	$multikey =~ s/^<!M><Q><0>$/F002/;
	$multikey =~ s/^<!M><q><0>$/F003/;
	$multikey =~ s/^<!M><Q><1>$/F004/;
	$multikey =~ s/^<!M><q><1>$/F005/;
	$multikey =~ s/^<!M><Q><2>$/F006/;
	$multikey =~ s/^<!M><q><2>$/F007/;
	$multikey =~ s/^<!M><Q><3>$/F008/;
	$multikey =~ s/^<!M><q><3>$/F009/;
	$multikey =~ s/^<!M><Q><4>$/F00A/;
	$multikey =~ s/^<!M><q><4>$/F00B/;
	$multikey =~ s/^<!M><q><a>$/F00C/;
	$multikey =~ s/^<!M><Q><A>$/F00D/;
	$multikey =~ s/^<!M><q><a><r>$/F00E/;
	$multikey =~ s/^<!M><Q><A><R>$/F00F/;
	$multikey =~ s/^<!M><q><e>$/F010/;
	$multikey =~ s/^<!M><Q><E>$/F011/;
	$multikey =~ s/^<!M><q><p>$/F012/;
	$multikey =~ s/^<!M><Q><Q>$/F013/;
	$multikey =~ s/^<!M><r>$/F014/;
	$multikey =~ s/^<!M><R>$/F015/;
	$multikey =~ s/^<!M><r><%at>$/F016/;
	$multikey =~ s/^<!M><r><%equal>$/F017/;
	$multikey =~ s/^<!M><R><%equal>$/F018/;
	$multikey =~ s/^<!M><R><%hash>$/F019/;
	$multikey =~ s/^<!M><R><%minus>$/F01A/;
	$multikey =~ s/^<!M><r><%minus>$/F01B/;
	$multikey =~ s/^<!M><r><%parenleft>$/F01C/;
	$multikey =~ s/^<!M><R><%parenleft>$/F01D/;
	$multikey =~ s/^<!M><R><%slash>$/F01E/;
	$multikey =~ s/^<!M><r><%slash>$/F01F/;
	$multikey =~ s/^<!M><R><%tilde>$/F020/;
	$multikey =~ s/^<!M><R><C>$/F021/;
	$multikey =~ s/^<!M><R><C><C>$/F022/;
	$multikey =~ s/^<!M><R><C><C><C>$/F023/;
	$multikey =~ s/^<!M><R><C><C><C><D>$/F024/;
	$multikey =~ s/^<!M><R><C><C><C><D><D>$/F025/;
	$multikey =~ s/^<!M><R><C><C><C><D><D><D>$/F026/;
	$multikey =~ s/^<!M><R><C><C><D>$/F027/;
	$multikey =~ s/^<!M><R><C><C><D><D>$/F028/;
	$multikey =~ s/^<!M><R><C><D>$/F029/;
	$multikey =~ s/^<!M><R><C><V>$/F02A/;
	$multikey =~ s/^<!M><R><C><V><I>$/F02B/;
	$multikey =~ s/^<!M><R><D>$/F02C/;
	$multikey =~ s/^<!M><R><D><D>$/F02D/;
	$multikey =~ s/^<!M><R><D><D><D>$/F02E/;
	$multikey =~ s/^<!M><R><D><D><~space>$/F02F/;
	$multikey =~ s/^<!M><r><e>$/F030/;
	$multikey =~ s/^<!M><R><E>$/F031/;
	$multikey =~ s/^<!M><r><e><c>$/F032/;
	$multikey =~ s/^<!M><R><E><C>$/F033/;
	$multikey =~ s/^<!M><r><e><c><a>$/F034/;
	$multikey =~ s/^<!M><R><E><C><A>$/F035/;
	$multikey =~ s/^<!M><r><e><c><e>$/F036/;
	$multikey =~ s/^<!M><R><E><C><E>$/F037/;
	$multikey =~ s/^<!M><r><e><c><f>$/F038/;
	$multikey =~ s/^<!M><R><E><C><F>$/F039/;
	$multikey =~ s/^<!M><r><e><c><g>$/F03A/;
	$multikey =~ s/^<!M><R><E><C><G>$/F03B/;
	$multikey =~ s/^<!M><r><e><c><i>$/F03C/;
	$multikey =~ s/^<!M><R><E><C><I>$/F03D/;
	$multikey =~ s/^<!M><r><e><c><o>$/F03E/;
	$multikey =~ s/^<!M><R><E><C><O>$/F03F/;
	$multikey =~ s/^<!M><r><e><c><p>$/F040/;
	$multikey =~ s/^<!M><R><E><C><P>$/F041/;
	$multikey =~ s/^<!M><r><e><c><u>$/F042/;
	$multikey =~ s/^<!M><R><E><C><U>$/F043/;
	$multikey =~ s/^<!M><r><e><c><v>$/F044/;
	$multikey =~ s/^<!M><R><E><C><V>$/F045/;
	$multikey =~ s/^<!M><r><e><t>$/F046/;
	$multikey =~ s/^<!M><R><E><T>$/F047/;
	$multikey =~ s/^<!M><R><L>$/F048/;
	$multikey =~ s/^<!M><R><L><L>$/F049/;
	$multikey =~ s/^<!M><r><m>$/F04A/;
	$multikey =~ s/^<!M><R><M>$/F04B/;
	$multikey =~ s/^<!M><r><o>$/F04C/;
	$multikey =~ s/^<!M><R><O>$/F04D/;
	$multikey =~ s/^<!M><R><p>$/F04E/;
	$multikey =~ s/^<!M><R><p><a>$/F04F/;
	$multikey =~ s/^<!M><R><p><a><r>$/F050/;
	$multikey =~ s/^<!M><R><p><a><r><e>$/F051/;
	$multikey =~ s/^<!M><R><p><a><r><e><n>$/F052/;
	$multikey =~ s/^<!M><R><p><a><r><e><n><l>$/F053/;
	$multikey =~ s/^<!M><R><p><a><r><e><n><l><t>$/F054/;
	$multikey =~ s/^<!M><r><r>$/F055/;
	$multikey =~ s/^<!M><R><R>$/F056/;
	$multikey =~ s/^<!M><R><s>$/F057/;
	$multikey =~ s/^<!M><R><U>$/F058/;
	$multikey =~ s/^<!M><R><u>$/F059/;
	$multikey =~ s/^<!M><r><u>$/F05A/;
	$multikey =~ s/^<!M><r><u><b>$/F05B/;
	$multikey =~ s/^<!M><R><U><B>$/F05C/;
	$multikey =~ s/^<!M><R><U><M>$/F05D/;
	$multikey =~ s/^<!M><R><u><m>$/F05E/;
	$multikey =~ s/^<!M><r><u><m>$/F05F/;
	$multikey =~ s/^<!M><R><U><R>$/F060/;
	$multikey =~ s/^<!M><R><u><r>$/F061/;
	$multikey =~ s/^<!M><r><u><r>$/F062/;
	$multikey =~ s/^<!M><s>$/F063/;
	$multikey =~ s/^<!M><S>$/F064/;
	$multikey =~ s/^<!M><s><%backslash>$/F065/;
	$multikey =~ s/^<!M><s><%backslash><%percent>$/F066/;
	$multikey =~ s/^<!M><s><%backslash><%slash>$/F067/;
	$multikey =~ s/^<!M><s><%braceleft>$/F068/;
	$multikey =~ s/^<!M><S><%braceleft>$/F069/;
	$multikey =~ s/^<!M><s><%braceright>$/F06A/;
	$multikey =~ s/^<!M><S><%braceright>$/F06B/;
	$multikey =~ s/^<!M><s><%bracketleft>$/F06C/;
	$multikey =~ s/^<!M><S><%bracketleft>$/F06D/;
	$multikey =~ s/^<!M><s><%bracketleft><%bracketright>$/F06E/;
	$multikey =~ s/^<!M><S><%bracketleft><%bracketright>$/F06F/;
	$multikey =~ s/^<!M><s><%bracketleft><~nbspace>$/F070/;
	$multikey =~ s/^<!M><S><%bracketleft><~nbspace>$/F071/;
	$multikey =~ s/^<!M><s><%bracketleft><~space>$/F072/;
	$multikey =~ s/^<!M><S><%bracketleft><~space>$/F073/;
	$multikey =~ s/^<!M><s><%bracketright>$/F074/;
	$multikey =~ s/^<!M><S><%bracketright>$/F075/;
	$multikey =~ s/^<!M><s><%bracketright><%bracketleft>$/F076/;
	$multikey =~ s/^<!M><S><%bracketright><%bracketleft>$/F077/;
	$multikey =~ s/^<!M><s><%bracketright><~nbspace>$/F078/;
	$multikey =~ s/^<!M><S><%bracketright><~nbspace>$/F079/;
	$multikey =~ s/^<!M><s><%bracketright><~space>$/F07A/;
	$multikey =~ s/^<!M><S><%bracketright><~space>$/F07B/;
	$multikey =~ s/^<!M><S><%equal>$/F07C/;
	$multikey =~ s/^<!M><s><%equal>$/F07D/;
	$multikey =~ s/^<!M><s><%exclam>$/F07E/;
	$multikey =~ s/^<!M><S><%exclam>$/F07F/;
	$multikey =~ s/^<!M><S><%hash>$/F080/;
	$multikey =~ s/^<!M><s><%hash>$/F081/;
	$multikey =~ s/^<!M><s><%less>$/F082/;
	$multikey =~ s/^<!M><S><%less>$/F083/;
	$multikey =~ s/^<!M><s><%less><%minus>$/F084/;
	$multikey =~ s/^<!M><S><%less><%minus>$/F085/;
	$multikey =~ s/^<!M><S><%minus>$/F086/;
	$multikey =~ s/^<!M><s><%minus>$/F087/;
	$multikey =~ s/^<!M><s><%parenleft>$/F088/;
	$multikey =~ s/^<!M><S><%parenleft>$/F089/;
	$multikey =~ s/^<!M><s><%parenright>$/F08A/;
	$multikey =~ s/^<!M><S><%parenright>$/F08B/;
	$multikey =~ s/^<!M><s><%percent>$/F08C/;
	$multikey =~ s/^<!M><s><%percent><%backslash>$/F08D/;
	$multikey =~ s/^<!M><s><%percent><%percent>$/F08E/;
	$multikey =~ s/^<!M><s><%percent><~nbspace>$/F08F/;
	$multikey =~ s/^<!M><s><%percent><~space>$/F090/;
	$multikey =~ s/^<!M><s><%period>$/F091/;
	$multikey =~ s/^<!M><S><%period>$/F092/;
	$multikey =~ s/^<!M><s><%period><%bracketright>$/F093/;
	$multikey =~ s/^<!M><S><%period><%bracketright>$/F094/;
	$multikey =~ s/^<!M><s><%period><%parenright>$/F095/;
	$multikey =~ s/^<!M><S><%period><%parenright>$/F096/;
	$multikey =~ s/^<!M><s><%period><o>$/F097/;
	$multikey =~ s/^<!M><S><%period><o>$/F098/;
	$multikey =~ s/^<!M><S><%slash>$/F099/;
	$multikey =~ s/^<!M><s><%slash>$/F09A/;
	$multikey =~ s/^<!M><s><%slash><%backslash>$/F09B/;
	$multikey =~ s/^<!M><s><%slash><~nbspace>$/F09C/;
	$multikey =~ s/^<!M><s><%slash><~space>$/F09D/;
	$multikey =~ s/^<!M><s><%underscore>$/F09E/;
	$multikey =~ s/^<!M><S><%underscore>$/F09F/;
	$multikey =~ s/^<!M><s><a>$/F0A0/;
	$multikey =~ s/^<!M><S><a>$/F0A1/;
	$multikey =~ s/^<!M><S><A>$/F0A2/;
	$multikey =~ s/^<!M><s><a><g>$/F0A3/;
	$multikey =~ s/^<!M><S><A><G>$/F0A4/;
	$multikey =~ s/^<!M><s><a><g><i>$/F0A5/;
	$multikey =~ s/^<!M><S><A><G><I>$/F0A6/;
	$multikey =~ s/^<!M><s><a><m>$/F0A7/;
	$multikey =~ s/^<!M><S><a><m>$/F0A8/;
	$multikey =~ s/^<!M><S><A><M>$/F0A9/;
	$multikey =~ s/^<!M><s><a><r>$/F0AA/;
	$multikey =~ s/^<!M><S><A><R>$/F0AB/;
	$multikey =~ s/^<!M><s><c>$/F0AC/;
	$multikey =~ s/^<!M><S><c>$/F0AD/;
	$multikey =~ s/^<!M><S><C>$/F0AE/;
	$multikey =~ s/^<!M><s><c><o>$/F0AF/;
	$multikey =~ s/^<!M><S><C><O>$/F0B0/;
	$multikey =~ s/^<!M><s><c><o><r>$/F0B1/;
	$multikey =~ s/^<!M><S><C><O><R>$/F0B2/;
	$multikey =~ s/^<!M><s><c><r>$/F0B3/;
	$multikey =~ s/^<!M><S><c><r>$/F0B4/;
	$multikey =~ s/^<!M><S><C><R>$/F0B5/;
	$multikey =~ s/^<!M><s><c><~nbspace>$/F0B6/;
	$multikey =~ s/^<!M><S><c><~nbspace>$/F0B7/;
	$multikey =~ s/^<!M><S><C><~nbspace>$/F0B8/;
	$multikey =~ s/^<!M><s><c><~space>$/F0B9/;
	$multikey =~ s/^<!M><S><c><~space>$/F0BA/;
	$multikey =~ s/^<!M><S><C><~space>$/F0BB/;
	$multikey =~ s/^<!M><s><d>$/F0BC/;
	$multikey =~ s/^<!M><S><D>$/F0BD/;
	$multikey =~ s/^<!M><s><d><g>$/F0BE/;
	$multikey =~ s/^<!M><S><D><G>$/F0BF/;
	$multikey =~ s/^<!M><s><e>$/F0C0/;
	$multikey =~ s/^<!M><S><E>$/F0C1/;
	$multikey =~ s/^<!M><s><e><r>$/F0C2/;
	$multikey =~ s/^<!M><S><E><R>$/F0C3/;
	$multikey =~ s/^<!M><s><e><t>$/F0C4/;
	$multikey =~ s/^<!M><s><e><t><m>$/F0C5/;
	$multikey =~ s/^<!M><s><e><t><m><i>$/F0C6/;
	$multikey =~ s/^<!M><s><e><t><m><i><n>$/F0C7/;
	$multikey =~ s/^<!M><s><e><t><m><i><n><u>$/F0C8/;
	$multikey =~ s/^<!M><s><e><t><m><i><n><u><s>$/F0C9/;
	$multikey =~ s/^<!M><S><H>$/F0CA/;
	$multikey =~ s/^<!M><S><h>$/F0CB/;
	$multikey =~ s/^<!M><s><h>$/F0CC/;
	$multikey =~ s/^<!M><s><i>$/F0CD/;
	$multikey =~ s/^<!M><S><I>$/F0CE/;
	$multikey =~ s/^<!M><s><i><n>$/F0CF/;
	$multikey =~ s/^<!M><S><I><N>$/F0D0/;
	$multikey =~ s/^<!M><s><l>$/F0D1/;
	$multikey =~ s/^<!M><s><m>$/F0D2/;
	$multikey =~ s/^<!M><S><M>$/F0D3/;
	$multikey =~ s/^<!M><S><n>$/F0D4/;
	$multikey =~ s/^<!M><s><n>$/F0D5/;
	$multikey =~ s/^<!M><S><N>$/F0D6/;
	$multikey =~ s/^<!M><s><n><o>$/F0D7/;
	$multikey =~ s/^<!M><S><N><O>$/F0D8/;
	$multikey =~ s/^<!M><s><n><~nbspace>$/F0D9/;
	$multikey =~ s/^<!M><S><N><~nbspace>$/F0DA/;
	$multikey =~ s/^<!M><s><n><~space>$/F0DB/;
	$multikey =~ s/^<!M><S><N><~space>$/F0DC/;
	$multikey =~ s/^<!M><s><o>$/F0DD/;
	$multikey =~ s/^<!M><S><O>$/F0DE/;
	$multikey =~ s/^<!M><S><o>$/F0DF/;
	$multikey =~ s/^<!M><s><o><%greater>$/F0E0/;
	$multikey =~ s/^<!M><S><o><%greater>$/F0E1/;
	$multikey =~ s/^<!M><s><o><%less>$/F0E2/;
	$multikey =~ s/^<!M><S><o><%less>$/F0E3/;
	$multikey =~ s/^<!M><s><o><%period>$/F0E4/;
	$multikey =~ s/^<!M><S><o><%period>$/F0E5/;
	$multikey =~ s/^<!M><S><O><%period>$/F0E6/;
	$multikey =~ s/^<!M><s><o><l>$/F0E7/;
	$multikey =~ s/^<!M><S><O><L>$/F0E8/;
	$multikey =~ s/^<!M><s><o><~nbspace>$/F0E9/;
	$multikey =~ s/^<!M><S><o><~nbspace>$/F0EA/;
	$multikey =~ s/^<!M><s><o><~space>$/F0EB/;
	$multikey =~ s/^<!M><S><o><~space>$/F0EC/;
	$multikey =~ s/^<!M><s><p>$/F0ED/;
	$multikey =~ s/^<!M><S><P>$/F0EE/;
	$multikey =~ s/^<!M><s><S>$/F0EF/;
	$multikey =~ s/^<!M><S><S>$/F0F0/;
	$multikey =~ s/^<!M><S><s>$/F0F1/;
	$multikey =~ s/^<!M><s><s>$/F0F2/;
	$multikey =~ s/^<!M><S><u>$/F0F3/;
	$multikey =~ s/^<!M><s><u>$/F0F4/;
	$multikey =~ s/^<!M><S><U>$/F0F5/;
	$multikey =~ s/^<!M><s><u><n>$/F0F6/;
	$multikey =~ s/^<!M><S><U><N>$/F0F7/;
	$multikey =~ s/^<!M><s><u><~nbspace>$/F0F8/;
	$multikey =~ s/^<!M><S><U><~nbspace>$/F0F9/;
	$multikey =~ s/^<!M><s><u><~space>$/F0FA/;
	$multikey =~ s/^<!M><S><U><~space>$/F0FB/;
	$multikey =~ s/^<!M><s><v>$/F0FC/;
	$multikey =~ s/^<!M><S><V>$/F0FD/;
	$multikey =~ s/^<!M><s><v><c>$/F0FE/;
	$multikey =~ s/^<!M><S><V><C>$/F0FF/;
	$multikey =~ s/^<!M><s><x>$/F100/;
	$multikey =~ s/^<!M><S><x>$/F101/;
	$multikey =~ s/^<!M><S><X>$/F102/;
	$multikey =~ s/^<!M><S><Z>$/F103/;
	$multikey =~ s/^<!M><S><z>$/F104/;
	$multikey =~ s/^<!M><s><z>$/F105/;
	$multikey =~ s/^<!M><S><~nbspace>$/F106/;
	$multikey =~ s/^<!M><s><~nbspace>$/F107/;
	$multikey =~ s/^<!M><S><~space>$/F108/;
	$multikey =~ s/^<!M><s><~space>$/F109/;
	$multikey =~ s/^<!M><T>$/F10A/;
	$multikey =~ s/^<!M><t>$/F10B/;
	$multikey =~ s/^<!M><T><%apostrophe>$/F10C/;
	$multikey =~ s/^<!M><T><%aprightsingquotmark>$/F10D/;
	$multikey =~ s/^<!M><t><%at>$/F10E/;
	$multikey =~ s/^<!M><T><%at>$/F10F/;
	$multikey =~ s/^<!M><T><%bar>$/F110/;
	$multikey =~ s/^<!M><t><%equal>$/F111/;
	$multikey =~ s/^<!M><T><%equal>$/F112/;
	$multikey =~ s/^<!M><T><%greater>$/F113/;
	$multikey =~ s/^<!M><T><%greater><%apostrophe>$/F114/;
	$multikey =~ s/^<!M><T><%greater><%aprightsingquotmark>$/F115/;
	$multikey =~ s/^<!M><T><%greater><%bar>$/F116/;
	$multikey =~ s/^<!M><T><%greater><%less>$/F117/;
	$multikey =~ s/^<!M><T><%greater><%slash>$/F118/;
	$multikey =~ s/^<!M><T><%greater><~nbspace>$/F119/;
	$multikey =~ s/^<!M><T><%greater><~space>$/F11A/;
	$multikey =~ s/^<!M><T><%less>$/F11B/;
	$multikey =~ s/^<!M><T><%less><%apostrophe>$/F11C/;
	$multikey =~ s/^<!M><T><%less><%aprightsingquotmark>$/F11D/;
	$multikey =~ s/^<!M><T><%less><%bar>$/F11E/;
	$multikey =~ s/^<!M><T><%less><%greater>$/F11F/;
	$multikey =~ s/^<!M><T><%less><~nbspace>$/F120/;
	$multikey =~ s/^<!M><T><%less><~space>$/F121/;
	$multikey =~ s/^<!M><t><%minus>$/F122/;
	$multikey =~ s/^<!M><T><%minus>$/F123/;
	$multikey =~ s/^<!M><T><%percent>$/F124/;
	$multikey =~ s/^<!M><T><%percent><%apostrophe>$/F125/;
	$multikey =~ s/^<!M><T><%percent><%bar>$/F126/;
	$multikey =~ s/^<!M><T><%percent><%percent>$/F127/;
	$multikey =~ s/^<!M><T><%percent><~nbspace>$/F128/;
	$multikey =~ s/^<!M><T><%percent><~space>$/F129/;
	$multikey =~ s/^<!M><t><1>$/F12A/;
	$multikey =~ s/^<!M><T><1>$/F12B/;
	$multikey =~ s/^<!M><t><2>$/F12C/;
	$multikey =~ s/^<!M><T><2>$/F12D/;
	$multikey =~ s/^<!M><T><2><%greater>$/F12E/;
	$multikey =~ s/^<!M><T><2><%greater><%apostrophe>$/F12F/;
	$multikey =~ s/^<!M><T><2><%greater><%aprightsingquotmark>$/F130/;
	$multikey =~ s/^<!M><T><2><%greater><%less>$/F131/;
	$multikey =~ s/^<!M><T><2><%greater><%slash>$/F132/;
	$multikey =~ s/^<!M><T><2><%greater><~nbspace>$/F133/;
	$multikey =~ s/^<!M><T><2><%greater><~space>$/F134/;
	$multikey =~ s/^<!M><T><2><%less>$/F135/;
	$multikey =~ s/^<!M><T><2><%less><%greater>$/F136/;
	$multikey =~ s/^<!M><T><2><%less><~nbspace>$/F137/;
	$multikey =~ s/^<!M><T><2><%less><~space>$/F138/;
	$multikey =~ s/^<!M><T><2><%percent>$/F139/;
	$multikey =~ s/^<!M><T><2><~nbspace>$/F13A/;
	$multikey =~ s/^<!M><T><2><~space>$/F13B/;
	$multikey =~ s/^<!M><t><3>$/F13C/;
	$multikey =~ s/^<!M><T><3>$/F13D/;
	$multikey =~ s/^<!M><T><3><%greater>$/F13E/;
	$multikey =~ s/^<!M><t><4>$/F13F/;
	$multikey =~ s/^<!M><T><4>$/F140/;
	$multikey =~ s/^<!M><t><5>$/F141/;
	$multikey =~ s/^<!M><T><5>$/F142/;
	$multikey =~ s/^<!M><t><a>$/F143/;
	$multikey =~ s/^<!M><T><A>$/F144/;
	$multikey =~ s/^<!M><t><a><b>$/F145/;
	$multikey =~ s/^<!M><T><A><B>$/F146/;
	$multikey =~ s/^<!M><t><a><i>$/F147/;
	$multikey =~ s/^<!M><T><A><I>$/F148/;
	$multikey =~ s/^<!M><t><a><u>$/F149/;
	$multikey =~ s/^<!M><T><A><U>$/F14A/;
	$multikey =~ s/^<!M><t><a><u><r>$/F14B/;
	$multikey =~ s/^<!M><T><A><U><R>$/F14C/;
	$multikey =~ s/^<!M><t><c>$/F14D/;
	$multikey =~ s/^<!M><T><E>$/F14E/;
	$multikey =~ s/^<!M><T><e>$/F14F/;
	$multikey =~ s/^<!M><t><e>$/F150/;
	$multikey =~ s/^<!M><t><e><c>$/F151/;
	$multikey =~ s/^<!M><t><e><l>$/F152/;
	$multikey =~ s/^<!M><t><e><s>$/F153/;
	$multikey =~ s/^<!M><T><h>$/F154/;
	$multikey =~ s/^<!M><T><H>$/F155/;
	$multikey =~ s/^<!M><t><h>$/F156/;
	$multikey =~ s/^<!M><t><h><%slash>$/F157/;
	$multikey =~ s/^<!M><t><h><b>$/F158/;
	$multikey =~ s/^<!M><T><H><B>$/F159/;
	$multikey =~ s/^<!M><T><H><~space>$/F15A/;
	$multikey =~ s/^<!M><t><h><~space>$/F15B/;
	$multikey =~ s/^<!M><t><m>$/F15C/;
	$multikey =~ s/^<!M><T><M>$/F15D/;
	$multikey =~ s/^<!M><T><n>$/F15E/;
	$multikey =~ s/^<!M><t><n>$/F15F/;
	$multikey =~ s/^<!M><T><N>$/F160/;
	$multikey =~ s/^<!M><t><n><d>$/F161/;
	$multikey =~ s/^<!M><T><N><D>$/F162/;
	$multikey =~ s/^<!M><t><n><~nbspace>$/F163/;
	$multikey =~ s/^<!M><t><n><~space>$/F164/;
	$multikey =~ s/^<!M><T><o>$/F165/;
	$multikey =~ s/^<!M><t><o>$/F166/;
	$multikey =~ s/^<!M><T><O>$/F167/;
	$multikey =~ s/^<!M><t><o><p>$/F168/;
	$multikey =~ s/^<!M><T><O><P>$/F169/;
	$multikey =~ s/^<!M><t><o><x>$/F16A/;
	$multikey =~ s/^<!M><T><O><X>$/F16B/;
	$multikey =~ s/^<!M><t><o><~nbspace>$/F16C/;
	$multikey =~ s/^<!M><t><o><~space>$/F16D/;
	$multikey =~ s/^<!M><t><r>$/F16E/;
	$multikey =~ s/^<!M><T><R>$/F16F/;
	$multikey =~ s/^<!M><t><r><y>$/F170/;
	$multikey =~ s/^<!M><T><R><Y>$/F171/;
	$multikey =~ s/^<!M><t><s>$/F172/;
	$multikey =~ s/^<!M><T><T>$/F173/;
	$multikey =~ s/^<!M><T><T><%apostrophe>$/F174/;
	$multikey =~ s/^<!M><T><T><%bar>$/F175/;
	$multikey =~ s/^<!M><T><T><%percent>$/F176/;
	$multikey =~ s/^<!M><T><T><%percent><%apostrophe>$/F177/;
	$multikey =~ s/^<!M><T><T><%percent><%aprightsingquotmark>$/F178/;
	$multikey =~ s/^<!M><T><T><%percent><~nbspace>$/F179/;
	$multikey =~ s/^<!M><T><T><%percent><~space>$/F17A/;
	$multikey =~ s/^<!M><T><T><~nbspace>$/F17B/;
	$multikey =~ s/^<!M><T><T><~space>$/F17C/;
	$multikey =~ s/^<!M><t><u>$/F17D/;
	$multikey =~ s/^<!M><T><Z>$/F17E/;
	$multikey =~ s/^<!M><T><z>$/F17F/;
	$multikey =~ s/^<!M><t><z>$/F180/;
	$multikey =~ s/^<!M><T><~nbspace>$/F181/;
	$multikey =~ s/^<!M><t><~nbspace>$/F182/;
	$multikey =~ s/^<!M><T><~space>$/F183/;
	$multikey =~ s/^<!M><t><~space>$/F184/;
	$multikey =~ s/^<!M><u>$/F185/;
	$multikey =~ s/^<!M><U>$/F186/;
	$multikey =~ s/^<!M><u><%at>$/F187/;
	$multikey =~ s/^<!M><U><%at>$/F188/;
	$multikey =~ s/^<!M><u><%bracketleft>$/F189/;
	$multikey =~ s/^<!M><U><%bracketleft>$/F18A/;
	$multikey =~ s/^<!M><u><%bracketright>$/F18B/;
	$multikey =~ s/^<!M><U><%bracketright>$/F18C/;
	$multikey =~ s/^<!M><u><%less>$/F18D/;
	$multikey =~ s/^<!M><u><%minus>$/F18E/;
	$multikey =~ s/^<!M><u><%minus><~nbspace>$/F18F/;
	$multikey =~ s/^<!M><u><%minus><~space>$/F190/;
	$multikey =~ s/^<!M><u><%period>$/F191/;
	$multikey =~ s/^<!M><U><%period>$/F192/;
	$multikey =~ s/^<!M><u><%plus>$/F193/;
	$multikey =~ s/^<!M><U><%plus>$/F194/;
	$multikey =~ s/^<!M><u><%underscore>$/F195/;
	$multikey =~ s/^<!M><u><a>$/F196/;
	$multikey =~ s/^<!M><U><A>$/F197/;
	$multikey =~ s/^<!M><u><a><h>$/F198/;
	$multikey =~ s/^<!M><U><A><H>$/F199/;
	$multikey =~ s/^<!M><u><e>$/F19A/;
	$multikey =~ s/^<!M><u><i>$/F19B/;
	$multikey =~ s/^<!M><u><m>$/F19C/;
	$multikey =~ s/^<!M><u><n>$/F19D/;
	$multikey =~ s/^<!M><u><n><i>$/F19E/;
	$multikey =~ s/^<!M><u><n><i><o>$/F19F/;
	$multikey =~ s/^<!M><u><n><i><o><n>$/F1A0/;
	$multikey =~ s/^<!M><u><n><~nbspace>$/F1A1/;
	$multikey =~ s/^<!M><u><n><~space>$/F1A2/;
	$multikey =~ s/^<!M><u><o>$/F1A3/;
	$multikey =~ s/^<!M><u><u>$/F1A4/;
	$multikey =~ s/^<!M><u><v>$/F1A5/;
	$multikey =~ s/^<!M><u><~nbspace>$/F1A6/;
	$multikey =~ s/^<!M><U><~nbspace>$/F1A7/;
	$multikey =~ s/^<!M><u><~space>$/F1A8/;
	$multikey =~ s/^<!M><U><~space>$/F1A9/;
	$multikey =~ s/^<!M><V>$/F1AA/;
	$multikey =~ s/^<!M><v>$/F1AB/;
	$multikey =~ s/^<!M><V><%backslash>$/F1AC/;
	$multikey =~ s/^<!M><v><%backslash>$/F1AD/;
	$multikey =~ s/^<!M><v><%backslash><%parenleft>$/F1AE/;
	$multikey =~ s/^<!M><v><%backslash><%parenleft><%parenright>$/F1AF/;
	$multikey =~ s/^<!M><v><%backslash><%parenright>$/F1B0/;
	$multikey =~ s/^<!M><v><%backslash><%parenright><%parenleft>$/F1B1/;
	$multikey =~ s/^<!M><v><%bar>$/F1B2/;
	$multikey =~ s/^<!M><V><%bar>$/F1B3/;
	$multikey =~ s/^<!M><v><%bracketright>$/F1B4/;
	$multikey =~ s/^<!M><v><%equal>$/F1B5/;
	$multikey =~ s/^<!M><v><%minus>$/F1B6/;
	$multikey =~ s/^<!M><V><%minus>$/F1B7/;
	$multikey =~ s/^<!M><v><%parenleft>$/F1B8/;
	$multikey =~ s/^<!M><v><%parenleft><%parenright>$/F1B9/;
	$multikey =~ s/^<!M><v><%parenright>$/F1BA/;
	$multikey =~ s/^<!M><v><%parenright><%parenleft>$/F1BB/;
	$multikey =~ s/^<!M><v><%percent>$/F1BC/;
	$multikey =~ s/^<!M><V><%percent>$/F1BD/;
	$multikey =~ s/^<!M><v><%percent><%bar>$/F1BE/;
	$multikey =~ s/^<!M><V><%percent><%bar>$/F1BF/;
	$multikey =~ s/^<!M><v><%percent><%bracketright>$/F1C0/;
	$multikey =~ s/^<!M><v><%percent><%minus>$/F1C1/;
	$multikey =~ s/^<!M><V><%percent><%minus>$/F1C2/;
	$multikey =~ s/^<!M><v><%percent><%period>$/F1C3/;
	$multikey =~ s/^<!M><v><%percent><%underscore>$/F1C4/;
	$multikey =~ s/^<!M><V><%percent><%underscore>$/F1C5/;
	$multikey =~ s/^<!M><v><%percent><%underscore><%underscore>$/F1C6/;
	$multikey =~ s/^<!M><V><%percent><%underscore><%underscore>$/F1C7/;
	$multikey =~ s/^<!M><v><%percent><%underscore><~nbspace>$/F1C8/;
	$multikey =~ s/^<!M><V><%percent><%underscore><~nbspace>$/F1C9/;
	$multikey =~ s/^<!M><v><%percent><%underscore><~space>$/F1CA/;
	$multikey =~ s/^<!M><V><%percent><%underscore><~space>$/F1CB/;
	$multikey =~ s/^<!M><v><%percent><v>$/F1CC/;
	$multikey =~ s/^<!M><V><%percent><V>$/F1CD/;
	$multikey =~ s/^<!M><v><%percent><~nbspace>$/F1CE/;
	$multikey =~ s/^<!M><v><%percent><~space>$/F1CF/;
	$multikey =~ s/^<!M><v><%period>$/F1D0/;
	$multikey =~ s/^<!M><V><%slash>$/F1D1/;
	$multikey =~ s/^<!M><v><%slash>$/F1D2/;
	$multikey =~ s/^<!M><v><%underscore>$/F1D3/;
	$multikey =~ s/^<!M><v><%underscore><%comma>$/F1D4/;
	$multikey =~ s/^<!M><v><%underscore><%underscore>$/F1D5/;
	$multikey =~ s/^<!M><v><%underscore><~nbspace>$/F1D6/;
	$multikey =~ s/^<!M><v><%underscore><~space>$/F1D7/;
	$multikey =~ s/^<!M><v><2>$/F1D8/;
	$multikey =~ s/^<!M><v><3>$/F1D9/;
	$multikey =~ s/^<!M><v><4>$/F1DA/;
	$multikey =~ s/^<!M><v><a>$/F1DB/;
	$multikey =~ s/^<!M><v><A>$/F1DC/;
	$multikey =~ s/^<!M><V><A>$/F1DD/;
	$multikey =~ s/^<!M><v><e>$/F1DE/;
	$multikey =~ s/^<!M><V><E>$/F1DF/;
	$multikey =~ s/^<!M><v><e><r>$/F1E0/;
	$multikey =~ s/^<!M><V><E><R>$/F1E1/;
	$multikey =~ s/^<!M><v><e><r><s>$/F1E2/;
	$multikey =~ s/^<!M><V><E><R><S>$/F1E3/;
	$multikey =~ s/^<!M><v><i>$/F1E4/;
	$multikey =~ s/^<!M><V><I>$/F1E5/;
	$multikey =~ s/^<!M><v><i><e>$/F1E6/;
	$multikey =~ s/^<!M><V><I><E>$/F1E7/;
	$multikey =~ s/^<!M><v><i><e><r>$/F1E8/;
	$multikey =~ s/^<!M><V><I><E><R>$/F1E9/;
	$multikey =~ s/^<!M><v><i><r>$/F1EA/;
	$multikey =~ s/^<!M><V><I><R>$/F1EB/;
	$multikey =~ s/^<!M><v><i><r><g>$/F1EC/;
	$multikey =~ s/^<!M><V><I><R><G>$/F1ED/;
	$multikey =~ s/^<!M><v><n>$/F1EE/;
	$multikey =~ s/^<!M><V><N>$/F1EF/;
	$multikey =~ s/^<!M><v><n><d>$/F1F0/;
	$multikey =~ s/^<!M><V><N><D>$/F1F1/;
	$multikey =~ s/^<!M><v><u>$/F1F2/;
	$multikey =~ s/^<!M><v><v>$/F1F3/;
	$multikey =~ s/^<!M><v><v><%equal>$/F1F4/;
	$multikey =~ s/^<!M><V><Y>$/F1F5/;
	$multikey =~ s/^<!M><V><y>$/F1F6/;
	$multikey =~ s/^<!M><v><y>$/F1F7/;
	$multikey =~ s/^<!M><v><~nbspace>$/F1F8/;
	$multikey =~ s/^<!M><V><~nbspace>$/F1F9/;
	$multikey =~ s/^<!M><v><~space>$/F1FA/;
	$multikey =~ s/^<!M><V><~space>$/F1FB/;
	$multikey =~ s/^<!M><w>$/F1FC/;
	$multikey =~ s/^<!M><W>$/F1FD/;
	$multikey =~ s/^<!M><w><%bracketleft>$/F1FE/;
	$multikey =~ s/^<!M><w><%bracketright>$/F1FF/;
	$multikey =~ s/^<!M><w><%equal>$/F200/;
	$multikey =~ s/^<!M><W><%equal>$/F201/;
	$multikey =~ s/^<!M><W><%percent>$/F202/;
	$multikey =~ s/^<!M><w><%percent>$/F203/;
	$multikey =~ s/^<!M><w><l>$/F204/;
	$multikey =~ s/^<!M><W><L>$/F205/;
	$multikey =~ s/^<!M><w><v>$/F206/;
	$multikey =~ s/^<!M><W><V>$/F207/;
	$multikey =~ s/^<!M><w><w>$/F208/;
	$multikey =~ s/^<!M><w><w><%bracketleft>$/F209/;
	$multikey =~ s/^<!M><w><w><%bracketright>$/F20A/;
	$multikey =~ s/^<!M><w><z>$/F20B/;
	$multikey =~ s/^<!M><W><Z>$/F20C/;
	$multikey =~ s/^<!M><W><~nbspace>$/F20D/;
	$multikey =~ s/^<!M><w><~nbspace>$/F20E/;
	$multikey =~ s/^<!M><W><~space>$/F20F/;
	$multikey =~ s/^<!M><w><~space>$/F210/;
	$multikey =~ s/^<!M><X>$/F211/;
	$multikey =~ s/^<!M><x>$/F212/;
	$multikey =~ s/^<!M><x><%colon>$/F213/;
	$multikey =~ s/^<!M><X><%hash>$/F214/;
	$multikey =~ s/^<!M><x><%minus>$/F215/;
	$multikey =~ s/^<!M><x><%parenright>$/F216/;
	$multikey =~ s/^<!M><x><%period>$/F217/;
	$multikey =~ s/^<!M><X><%underscore>$/F218/;
	$multikey =~ s/^<!M><x><%underscore>$/F219/;
	$multikey =~ s/^<!M><X><o>$/F21A/;
	$multikey =~ s/^<!M><x><O>$/F21B/;
	$multikey =~ s/^<!M><x><o>$/F21C/;
	$multikey =~ s/^<!M><X><O>$/F21D/;
	$multikey =~ s/^<!M><x><o><r>$/F21E/;
	$multikey =~ s/^<!M><X><O><R>$/F21F/;
	$multikey =~ s/^<!M><X><R>$/F220/;
	$multikey =~ s/^<!M><x><R>$/F221/;
	$multikey =~ s/^<!M><X><r>$/F222/;
	$multikey =~ s/^<!M><x><r>$/F223/;
	$multikey =~ s/^<!M><x><t>$/F224/;
	$multikey =~ s/^<!M><X><T>$/F225/;
	$multikey =~ s/^<!M><x><t><l>$/F226/;
	$multikey =~ s/^<!M><X><T><L>$/F227/;
	$multikey =~ s/^<!M><x><t><r>$/F228/;
	$multikey =~ s/^<!M><X><T><R>$/F229/;
	$multikey =~ s/^<!M><x><~nbspace>$/F22A/;
	$multikey =~ s/^<!M><X><~nbspace>$/F22B/;
	$multikey =~ s/^<!M><x><~space>$/F22C/;
	$multikey =~ s/^<!M><X><~space>$/F22D/;
	$multikey =~ s/^<!M><y>$/F22E/;
	$multikey =~ s/^<!M><Y>$/F22F/;
	$multikey =~ s/^<!M><Y><%at>$/F230/;
	$multikey =~ s/^<!M><y><%equal>$/F231/;
	$multikey =~ s/^<!M><Y><%equal>$/F232/;
	$multikey =~ s/^<!M><Y><%exclam>$/F233/;
	$multikey =~ s/^<!M><y><%minus>$/F234/;
	$multikey =~ s/^<!M><Y><%minus>$/F235/;
	$multikey =~ s/^<!M><Y><%percent>$/F236/;
	$multikey =~ s/^<!M><y><e>$/F237/;
	$multikey =~ s/^<!M><Y><E>$/F238/;
	$multikey =~ s/^<!M><y><e><r>$/F239/;
	$multikey =~ s/^<!M><Y><E><R>$/F23A/;
	$multikey =~ s/^<!M><z>$/F23B/;
	$multikey =~ s/^<!M><Z>$/F23C/;
	$multikey =~ s/^<!M><z><%bar>$/F23D/;
	$multikey =~ s/^<!M><Z><%bar>$/F23E/;
	$multikey =~ s/^<!M><z><%colon>$/F23F/;
	$multikey =~ s/^<!M><Z><%colon>$/F240/;
	$multikey =~ s/^<!M><z><%exclam>$/F241/;
	$multikey =~ s/^<!M><Z><%exclam>$/F242/;
	$multikey =~ s/^<!M><z><%greater>$/F243/;
	$multikey =~ s/^<!M><Z><%greater>$/F244/;
	$multikey =~ s/^<!M><z><%greater><%greater>$/F245/;
	$multikey =~ s/^<!M><Z><%greater><%greater>$/F246/;
	$multikey =~ s/^<!M><z><%greater><%minus>$/F247/;
	$multikey =~ s/^<!M><Z><%greater><%minus>$/F248/;
	$multikey =~ s/^<!M><z><%greater><~nbspace>$/F249/;
	$multikey =~ s/^<!M><Z><%greater><~nbspace>$/F24A/;
	$multikey =~ s/^<!M><z><%greater><~space>$/F24B/;
	$multikey =~ s/^<!M><Z><%greater><~space>$/F24C/;
	$multikey =~ s/^<!M><Z><%hash>$/F24D/;
	$multikey =~ s/^<!M><z><%less>$/F24E/;
	$multikey =~ s/^<!M><Z><%less>$/F24F/;
	$multikey =~ s/^<!M><z><%less><%minus>$/F250/;
	$multikey =~ s/^<!M><Z><%less><%minus>$/F251/;
	$multikey =~ s/^<!M><z><%less><~nbspace>$/F252/;
	$multikey =~ s/^<!M><Z><%less><~nbspace>$/F253/;
	$multikey =~ s/^<!M><z><%less><~space>$/F254/;
	$multikey =~ s/^<!M><Z><%less><~space>$/F255/;
	$multikey =~ s/^<!M><z><%parenleft>$/F256/;
	$multikey =~ s/^<!M><Z><%parenleft>$/F257/;
	$multikey =~ s/^<!M><z><%parenright>$/F258/;
	$multikey =~ s/^<!M><Z><%parenright>$/F259/;
	$multikey =~ s/^<!M><z><%period>$/F25A/;
	$multikey =~ s/^<!M><Z><%period>$/F25B/;
	$multikey =~ s/^<!M><z><%semicolon>$/F25C/;
	$multikey =~ s/^<!M><Z><%semicolon>$/F25D/;
	$multikey =~ s/^<!M><z><%semsection>$/F25E/;
	$multikey =~ s/^<!M><Z><%semsection>$/F25F/;
	$multikey =~ s/^<!M><z><1>$/F260/;
	$multikey =~ s/^<!M><Z><1>$/F261/;
	$multikey =~ s/^<!M><Z><2>$/F262/;
	$multikey =~ s/^<!M><z><2>$/F263/;
	$multikey =~ s/^<!M><Z><3>$/F264/;
	$multikey =~ s/^<!M><z><3>$/F265/;
	$multikey =~ s/^<!M><Z><4>$/F266/;
	$multikey =~ s/^<!M><z><4>$/F267/;
	$multikey =~ s/^<!M><Z><5>$/F268/;
	$multikey =~ s/^<!M><z><5>$/F269/;
	$multikey =~ s/^<!M><Z><6>$/F26A/;
	$multikey =~ s/^<!M><z><6>$/F26B/;
	$multikey =~ s/^<!M><z><e>$/F26C/;
	$multikey =~ s/^<!M><Z><e>$/F26D/;
	$multikey =~ s/^<!M><z><E>$/F26E/;
	$multikey =~ s/^<!M><Z><E>$/F26F/;
	$multikey =~ s/^<!M><Z><H>$/F270/;
	$multikey =~ s/^<!M><Z><h>$/F271/;
	$multikey =~ s/^<!M><z><h>$/F272/;
	$multikey =~ s/^<!M><z><w>$/F273/;
	$multikey =~ s/^<!M><Z><W>$/F274/;
	$multikey =~ s/^<!M><z><z>$/F275/;
	$multikey =~ s/^<!M><Z><z>$/F276/;
	$multikey =~ s/^<!M><z><Z>$/F277/;
	$multikey =~ s/^<!M><Z><Z>$/F278/;
	$multikey =~ s/^<!M><~nbspace>$/F279/;
	$multikey =~ s/^<!M><~nbspace><%ampersand>$/F27A/;
	$multikey =~ s/^<!M><~nbspace><%ampersand><%bar>$/F27B/;
	$multikey =~ s/^<!M><~nbspace><%ampersand><%less>$/F27C/;
	$multikey =~ s/^<!M><~nbspace><%ampersand><%minus>$/F27D/;
	$multikey =~ s/^<!M><~nbspace><%apostrophe>$/F27E/;
	$multikey =~ s/^<!M><~nbspace><%apostrophe><%equal>$/F27F/;
	$multikey =~ s/^<!M><~nbspace><%apostrophe><%minus>$/F280/;
	$multikey =~ s/^<!M><~nbspace><%apostrophe><%plus>$/F281/;
	$multikey =~ s/^<!M><~nbspace><%aprightsingquotmark>$/F282/;
	$multikey =~ s/^<!M><~nbspace><%aprightsingquotmark><%equal>$/F283/;
	$multikey =~ s/^<!M><~nbspace><%aprightsingquotmark><%minus>$/F284/;
	$multikey =~ s/^<!M><~nbspace><%aprightsingquotmark><%plus>$/F285/;
	$multikey =~ s/^<!M><~nbspace><%asterisk>$/F286/;
	$multikey =~ s/^<!M><~nbspace><%asterisk><%equal>$/F287/;
	$multikey =~ s/^<!M><~nbspace><%asterisk><~nbspace>$/F288/;
	$multikey =~ s/^<!M><~nbspace><%asterisk><~space>$/F289/;
	$multikey =~ s/^<!M><~nbspace><%backslash>$/F28A/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%greater>$/F28B/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%minus>$/F28C/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%slash>$/F28D/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%slash><%bar>$/F28E/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%slash><%hash>$/F28F/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%slash><%underscore>$/F290/;
	$multikey =~ s/^<!M><~nbspace><%backslash><c>$/F291/;
	$multikey =~ s/^<!M><~nbspace><%backslash><~nbspace>$/F292/;
	$multikey =~ s/^<!M><~nbspace><%backslash><~space>$/F293/;
	$multikey =~ s/^<!M><~nbspace><%bar>$/F294/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash>$/F295/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash><%slash>$/F296/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash><%slash><%bar>$/F297/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash><%slash><~nbspace>$/F298/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash><%slash><~space>$/F299/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar>$/F29A/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%bar>$/F29B/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%bar><%minus>$/F29C/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%bar><~nbspace>$/F29D/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%bar><~space>$/F29E/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%minus>$/F29F/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><~nbspace>$/F2A0/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><~space>$/F2A1/;
	$multikey =~ s/^<!M><~nbspace><%bar><%equal>$/F2A2/;
	$multikey =~ s/^<!M><~nbspace><%bar><%hash>$/F2A3/;
	$multikey =~ s/^<!M><~nbspace><%bar><%minus>$/F2A4/;
	$multikey =~ s/^<!M><~nbspace><%bar><%parenright>$/F2A5/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash>$/F2A6/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><%backslash>$/F2A7/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><%backslash><%bar>$/F2A8/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><%backslash><~nbspace>$/F2A9/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><%backslash><~space>$/F2AA/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><~nbspace>$/F2AB/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><~space>$/F2AC/;
	$multikey =~ s/^<!M><~nbspace><%bar><e>$/F2AD/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><%backslash>$/F2AE/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><%backslash><%comma>$/F2AF/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><%backslash><~nbspace>$/F2B0/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><%backslash><~space>$/F2B1/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><e>$/F2B2/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><e><%comma>$/F2B3/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><e><~nbspace>$/F2B4/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><e><~space>$/F2B5/;
	$multikey =~ s/^<!M><~nbspace><%bar><o>$/F2B6/;
	$multikey =~ s/^<!M><~nbspace><%bar><p>$/F2B7/;
	$multikey =~ s/^<!M><~nbspace><%bar><p><%comma>$/F2B8/;
	$multikey =~ s/^<!M><~nbspace><%bar><p><~nbspace>$/F2B9/;
	$multikey =~ s/^<!M><~nbspace><%bar><p><~space>$/F2BA/;
	$multikey =~ s/^<!M><~nbspace><%bar><~nbspace>$/F2BB/;
	$multikey =~ s/^<!M><~nbspace><%bar><~space>$/F2BC/;
	$multikey =~ s/^<!M><~nbspace><%braceleft>$/F2BD/;
	$multikey =~ s/^<!M><~nbspace><%braceright>$/F2BE/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft>$/F2BF/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><%bracketleft>$/F2C0/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><%bracketright>$/F2C1/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><%hash>$/F2C2/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><%minus>$/F2C3/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><%underscore>$/F2C4/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><a>$/F2C5/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft><o>$/F2C6/;
	$multikey =~ s/^<!M><~nbspace><%bracketright>$/F2C7/;
	$multikey =~ s/^<!M><~nbspace><%bracketright><%bracketleft>$/F2C8/;
	$multikey =~ s/^<!M><~nbspace><%bracketright><%bracketright>$/F2C9/;
	$multikey =~ s/^<!M><~nbspace><%bracketright><%underscore>$/F2CA/;
	$multikey =~ s/^<!M><~nbspace><%circum>$/F2CB/;
	$multikey =~ s/^<!M><~nbspace><%circum><%circum>$/F2CC/;
	$multikey =~ s/^<!M><~nbspace><%circum><%equal>$/F2CD/;
	$multikey =~ s/^<!M><~nbspace><%circum><%underscore>$/F2CE/;
	$multikey =~ s/^<!M><~nbspace><%circum><o>$/F2CF/;
	$multikey =~ s/^<!M><~nbspace><%circum><O>$/F2D0/;
	$multikey =~ s/^<!M><~nbspace><%circum><~nbspace>$/F2D1/;
	$multikey =~ s/^<!M><~nbspace><%circum><~space>$/F2D2/;
	$multikey =~ s/^<!M><~nbspace><%colon>$/F2D3/;
	$multikey =~ s/^<!M><~nbspace><%colon><%colon>$/F2D4/;
	$multikey =~ s/^<!M><~nbspace><%colon><%tilde>$/F2D5/;
	$multikey =~ s/^<!M><~nbspace><%colon><~nbspace>$/F2D6/;
	$multikey =~ s/^<!M><~nbspace><%colon><~space>$/F2D7/;
	$multikey =~ s/^<!M><~nbspace><%equal>$/F2D8/;
	$multikey =~ s/^<!M><~nbspace><%equal><%bar>$/F2D9/;
	$multikey =~ s/^<!M><~nbspace><%equal><%bar><%bar>$/F2DA/;
	$multikey =~ s/^<!M><~nbspace><%equal><%bar><~nbspace>$/F2DB/;
	$multikey =~ s/^<!M><~nbspace><%equal><%bar><~space>$/F2DC/;
	$multikey =~ s/^<!M><~nbspace><%equal><%equal>$/F2DD/;
	$multikey =~ s/^<!M><~nbspace><%equal><%greater>$/F2DE/;
	$multikey =~ s/^<!M><~nbspace><%equal><%minus>$/F2DF/;
	$multikey =~ s/^<!M><~nbspace><%equal><%minus><%greater>$/F2E0/;
	$multikey =~ s/^<!M><~nbspace><%equal><%minus><%slash>$/F2E1/;
	$multikey =~ s/^<!M><~nbspace><%exclam>$/F2E2/;
	$multikey =~ s/^<!M><~nbspace><%exclam><%exclam>$/F2E3/;
	$multikey =~ s/^<!M><~nbspace><%exclam><j>$/F2E4/;
	$multikey =~ s/^<!M><~nbspace><%exclam><J>$/F2E5/;
	$multikey =~ s/^<!M><~nbspace><%exclam><Y>$/F2E6/;
	$multikey =~ s/^<!M><~nbspace><%greater>$/F2E7/;
	$multikey =~ s/^<!M><~nbspace><%greater><%greater>$/F2E8/;
	$multikey =~ s/^<!M><~nbspace><%greater><%greater><%greater>$/F2E9/;
	$multikey =~ s/^<!M><~nbspace><%greater><%greater><~nbspace>$/F2EA/;
	$multikey =~ s/^<!M><~nbspace><%greater><%greater><~space>$/F2EB/;
	$multikey =~ s/^<!M><~nbspace><%greater><%less>$/F2EC/;
	$multikey =~ s/^<!M><~nbspace><%greater><%minus>$/F2ED/;
	$multikey =~ s/^<!M><~nbspace><%greater><%minus><%greater>$/F2EE/;
	$multikey =~ s/^<!M><~nbspace><%greater><%minus><~nbspace>$/F2EF/;
	$multikey =~ s/^<!M><~nbspace><%greater><%minus><~space>$/F2F0/;
	$multikey =~ s/^<!M><~nbspace><%greater><%parenright>$/F2F1/;
	$multikey =~ s/^<!M><~nbspace><%greater><o>$/F2F2/;
	$multikey =~ s/^<!M><~nbspace><%greater><~nbspace>$/F2F3/;
	$multikey =~ s/^<!M><~nbspace><%greater><~space>$/F2F4/;
	$multikey =~ s/^<!M><~nbspace><%hash>$/F2F5/;
	$multikey =~ s/^<!M><~nbspace><%hash><%percent>$/F2F6/;
	$multikey =~ s/^<!M><~nbspace><%less>$/F2F7/;
	$multikey =~ s/^<!M><~nbspace><%less><%backslash>$/F2F8/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal>$/F2F9/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal><%greater>$/F2FA/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal><%slash>$/F2FB/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal><~nbspace>$/F2FC/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal><~space>$/F2FD/;
	$multikey =~ s/^<!M><~nbspace><%less><%exclam>$/F2FE/;
	$multikey =~ s/^<!M><~nbspace><%less><%greater>$/F2FF/;
	$multikey =~ s/^<!M><~nbspace><%less><%less>$/F300/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%less>$/F301/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%minus>$/F302/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%minus><%bar>$/F303/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%minus><~nbspace>$/F304/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%minus><~space>$/F305/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><~nbspace>$/F306/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><~space>$/F307/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus>$/F308/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><%bar>$/F309/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><%less>$/F30A/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><%minus>$/F30B/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><%tilde>$/F30C/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><~nbspace>$/F30D/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus><~space>$/F30E/;
	$multikey =~ s/^<!M><~nbspace><%less><%parenleft>$/F30F/;
	$multikey =~ s/^<!M><~nbspace><%less><%parenright>$/F310/;
	$multikey =~ s/^<!M><~nbspace><%less><%slash>$/F311/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde>$/F312/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde><%greater>$/F313/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde><%tilde>$/F314/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde><~nbspace>$/F315/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde><~space>$/F316/;
	$multikey =~ s/^<!M><~nbspace><%less><3>$/F317/;
	$multikey =~ s/^<!M><~nbspace><%less><C>$/F318/;
	$multikey =~ s/^<!M><~nbspace><%less><n>$/F319/;
	$multikey =~ s/^<!M><~nbspace><%less><o>$/F31A/;
	$multikey =~ s/^<!M><~nbspace><%less><~nbspace>$/F31B/;
	$multikey =~ s/^<!M><~nbspace><%less><~space>$/F31C/;
	$multikey =~ s/^<!M><~nbspace><%minus>$/F31D/;
	$multikey =~ s/^<!M><~nbspace><%minus><%apostrophe>$/F31E/;
	$multikey =~ s/^<!M><~nbspace><%minus><%apostrophe><%minus>$/F31F/;
	$multikey =~ s/^<!M><~nbspace><%minus><%apostrophe><~nbspace>$/F320/;
	$multikey =~ s/^<!M><~nbspace><%minus><%apostrophe><~space>$/F321/;
	$multikey =~ s/^<!M><~nbspace><%minus><%aprightsingquotmark>$/F322/;
	$multikey =~ s/^<!M><~nbspace><%minus><%aprightsingquotmark><%minus>$/F323/;
	$multikey =~ s/^<!M><~nbspace><%minus><%aprightsingquotmark><~nbspace>$/F324/;
	$multikey =~ s/^<!M><~nbspace><%minus><%aprightsingquotmark><~space>$/F325/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bar>$/F326/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketleft>$/F327/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketright>$/F328/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketright><%bracketleft>$/F329/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketright><~nbspace>$/F32A/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketright><~space>$/F32B/;
	$multikey =~ s/^<!M><~nbspace><%minus><%slash>$/F32C/;
	$multikey =~ s/^<!M><~nbspace><%minus><e>$/F32D/;
	$multikey =~ s/^<!M><~nbspace><%minus><j>$/F32E/;
	$multikey =~ s/^<!M><~nbspace><%minus><J>$/F32F/;
	$multikey =~ s/^<!M><~nbspace><%minus><O>$/F330/;
	$multikey =~ s/^<!M><~nbspace><%minus><o>$/F331/;
	$multikey =~ s/^<!M><~nbspace><%minus><o><%minus>$/F332/;
	$multikey =~ s/^<!M><~nbspace><%minus><o><~nbspace>$/F333/;
	$multikey =~ s/^<!M><~nbspace><%minus><o><~space>$/F334/;
	$multikey =~ s/^<!M><~nbspace><%minus><S>$/F335/;
	$multikey =~ s/^<!M><~nbspace><%minus><s>$/F336/;
	$multikey =~ s/^<!M><~nbspace><%minus><s><%slash>$/F337/;
	$multikey =~ s/^<!M><~nbspace><%minus><s><~nbspace>$/F338/;
	$multikey =~ s/^<!M><~nbspace><%minus><s><~space>$/F339/;
	$multikey =~ s/^<!M><~nbspace><%minus><Y>$/F33A/;
	$multikey =~ s/^<!M><~nbspace><%parenleft>$/F33B/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%bracketleft>$/F33C/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%bracketright>$/F33D/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%equal>$/F33E/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%greater>$/F33F/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%less>$/F340/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><%parenleft>$/F341/;
	$multikey =~ s/^<!M><~nbspace><%parenleft><8>$/F342/;
	$multikey =~ s/^<!M><~nbspace><%parenright>$/F343/;
	$multikey =~ s/^<!M><~nbspace><%parenright><%bracketleft>$/F344/;
	$multikey =~ s/^<!M><~nbspace><%parenright><%bracketright>$/F345/;
	$multikey =~ s/^<!M><~nbspace><%parenright><%greater>$/F346/;
	$multikey =~ s/^<!M><~nbspace><%parenright><%parenright>$/F347/;
	$multikey =~ s/^<!M><~nbspace><%period>$/F348/;
	$multikey =~ s/^<!M><~nbspace><%period><a>$/F349/;
	$multikey =~ s/^<!M><~nbspace><%period><A>$/F34A/;
	$multikey =~ s/^<!M><~nbspace><%period><b>$/F34B/;
	$multikey =~ s/^<!M><~nbspace><%period><c>$/F34C/;
	$multikey =~ s/^<!M><~nbspace><%period><c><%backslash>$/F34D/;
	$multikey =~ s/^<!M><~nbspace><%period><c><%underscore>$/F34E/;
	$multikey =~ s/^<!M><~nbspace><%period><c><c>$/F34F/;
	$multikey =~ s/^<!M><~nbspace><%period><e>$/F350/;
	$multikey =~ s/^<!M><~nbspace><%period><v>$/F351/;
	$multikey =~ s/^<!M><~nbspace><%period><V>$/F352/;
	$multikey =~ s/^<!M><~nbspace><%period><v><v>$/F353/;
	$multikey =~ s/^<!M><~nbspace><%period><V><V>$/F354/;
	$multikey =~ s/^<!M><~nbspace><%period><v><~nbspace>$/F355/;
	$multikey =~ s/^<!M><~nbspace><%period><V><~nbspace>$/F356/;
	$multikey =~ s/^<!M><~nbspace><%period><v><~space>$/F357/;
	$multikey =~ s/^<!M><~nbspace><%period><V><~space>$/F358/;
	$multikey =~ s/^<!M><~nbspace><%period><x>$/F359/;
	$multikey =~ s/^<!M><~nbspace><%period><~nbspace>$/F35A/;
	$multikey =~ s/^<!M><~nbspace><%period><~space>$/F35B/;
	$multikey =~ s/^<!M><~nbspace><%plus>$/F35C/;
	$multikey =~ s/^<!M><~nbspace><%plus><%apostrophe>$/F35D/;
	$multikey =~ s/^<!M><~nbspace><%plus><%aprightsingquotmark>$/F35E/;
	$multikey =~ s/^<!M><~nbspace><%plus><%circum>$/F35F/;
	$multikey =~ s/^<!M><~nbspace><%plus><%plus>$/F360/;
	$multikey =~ s/^<!M><~nbspace><%plus><2>$/F361/;
	$multikey =~ s/^<!M><~nbspace><%semicolon>$/F362/;
	$multikey =~ s/^<!M><~nbspace><%semsection>$/F363/;
	$multikey =~ s/^<!M><~nbspace><%slash>$/F364/;
	$multikey =~ s/^<!M><~nbspace><%slash><%backslash>$/F365/;
	$multikey =~ s/^<!M><~nbspace><%slash><%backslash><%bar>$/F366/;
	$multikey =~ s/^<!M><~nbspace><%slash><%backslash><%hash>$/F367/;
	$multikey =~ s/^<!M><~nbspace><%slash><%backslash><%underscore>$/F368/;
	$multikey =~ s/^<!M><~nbspace><%slash><%hash>$/F369/;
	$multikey =~ s/^<!M><~nbspace><%slash><%hash><%underscore>$/F36A/;
	$multikey =~ s/^<!M><~nbspace><%slash><%hash><%underscore><%backslash>$/F36B/;
	$multikey =~ s/^<!M><~nbspace><%slash><%slash>$/F36C/;
	$multikey =~ s/^<!M><~nbspace><%slash><%slash><%slash>$/F36D/;
	$multikey =~ s/^<!M><~nbspace><%slash><%slash><~nbspace>$/F36E/;
	$multikey =~ s/^<!M><~nbspace><%slash><%slash><~space>$/F36F/;
	$multikey =~ s/^<!M><~nbspace><%slash><%underscore>$/F370/;
	$multikey =~ s/^<!M><~nbspace><%slash><%underscore><%backslash>$/F371/;
	$multikey =~ s/^<!M><~nbspace><%slash><c>$/F372/;
	$multikey =~ s/^<!M><~nbspace><%slash><~nbspace>$/F373/;
	$multikey =~ s/^<!M><~nbspace><%slash><~space>$/F374/;
	$multikey =~ s/^<!M><~nbspace><%tilde>$/F375/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%colon>$/F376/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal>$/F377/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><%slash>$/F378/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><%slash><%slash>$/F379/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><%slash><~nbspace>$/F37A/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><%slash><~space>$/F37B/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><~nbspace>$/F37C/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><~space>$/F37D/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%greater>$/F37E/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%minus>$/F37F/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%percent>$/F380/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%slash>$/F381/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%slash><~nbspace>$/F382/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%slash><~space>$/F383/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde>$/F384/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde><%equal>$/F385/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde><%tilde>$/F386/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde><~nbspace>$/F387/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde><~space>$/F388/;
	$multikey =~ s/^<!M><~nbspace><%tilde><~nbspace>$/F389/;
	$multikey =~ s/^<!M><~nbspace><%tilde><~space>$/F38A/;
	$multikey =~ s/^<!M><~nbspace><%underscore>$/F38B/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%backslash>$/F38C/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%hash>$/F38D/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%minus>$/F38E/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%minus><%apostrophe>$/F38F/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%minus><%aprightsingquotmark>$/F390/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%minus><%slash>$/F391/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%slash>$/F392/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore>$/F393/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><v>$/F394/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><V>$/F395/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><v><%percent>$/F396/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><V><%percent>$/F397/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><v><~nbspace>$/F398/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><V><~nbspace>$/F399/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><v><~space>$/F39A/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><V><~space>$/F39B/;
	$multikey =~ s/^<!M><~nbspace><%underscore><a>$/F39C/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e>$/F39D/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%backslash>$/F39E/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%backslash><%comma>$/F39F/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%backslash><~nbspace>$/F3A0/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%backslash><~space>$/F3A1/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%comma>$/F3A2/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><~nbspace>$/F3A3/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><~space>$/F3A4/;
	$multikey =~ s/^<!M><~nbspace><%underscore><n>$/F3A5/;
	$multikey =~ s/^<!M><~nbspace><%underscore><p>$/F3A6/;
	$multikey =~ s/^<!M><~nbspace><%underscore><p><%comma>$/F3A7/;
	$multikey =~ s/^<!M><~nbspace><%underscore><p><~nbspace>$/F3A8/;
	$multikey =~ s/^<!M><~nbspace><%underscore><p><~space>$/F3A9/;
	$multikey =~ s/^<!M><~nbspace><%underscore><u>$/F3AA/;
	$multikey =~ s/^<!M><~nbspace><%underscore><u><%hash>$/F3AB/;
	$multikey =~ s/^<!M><~nbspace><%underscore><u><~nbspace>$/F3AC/;
	$multikey =~ s/^<!M><~nbspace><%underscore><u><~space>$/F3AD/;
	$multikey =~ s/^<!M><~nbspace><%underscore><v>$/F3AE/;
	$multikey =~ s/^<!M><~nbspace><%underscore><v><v>$/F3AF/;
	$multikey =~ s/^<!M><~nbspace><%underscore><v><~nbspace>$/F3B0/;
	$multikey =~ s/^<!M><~nbspace><%underscore><v><~space>$/F3B1/;
	$multikey =~ s/^<!M><~nbspace><%underscore><X>$/F3B2/;
	$multikey =~ s/^<!M><~nbspace><%underscore><X><%hash>$/F3B3/;
	$multikey =~ s/^<!M><~nbspace><%underscore><X><%underscore>$/F3B4/;
	$multikey =~ s/^<!M><~nbspace><2>$/F3B5/;
	$multikey =~ s/^<!M><~nbspace><2><%less>$/F3B6/;
	$multikey =~ s/^<!M><~nbspace><2><%minus>$/F3B7/;
	$multikey =~ s/^<!M><~nbspace><3>$/F3B8/;
	$multikey =~ s/^<!M><~nbspace><3><%bar>$/F3B9/;
	$multikey =~ s/^<!M><~nbspace><3><%minus>$/F3BA/;
	$multikey =~ s/^<!M><~nbspace><8>$/F3BB/;
	$multikey =~ s/^<!M><~nbspace><A>$/F3BC/;
	$multikey =~ s/^<!M><~nbspace><a>$/F3BD/;
	$multikey =~ s/^<!M><~nbspace><A><%minus>$/F3BE/;
	$multikey =~ s/^<!M><~nbspace><A><%underscore>$/F3BF/;
	$multikey =~ s/^<!M><~nbspace><A><%underscore><%underscore>$/F3C0/;
	$multikey =~ s/^<!M><~nbspace><A><%underscore><~nbspace>$/F3C1/;
	$multikey =~ s/^<!M><~nbspace><A><%underscore><~space>$/F3C2/;
	$multikey =~ s/^<!M><~nbspace><A><A>$/F3C3/;
	$multikey =~ s/^<!M><~nbspace><a><a>$/F3C4/;
	$multikey =~ s/^<!M><~nbspace><A><V>$/F3C5/;
	$multikey =~ s/^<!M><~nbspace><a><v>$/F3C6/;
	$multikey =~ s/^<!M><~nbspace><A><~nbspace>$/F3C7/;
	$multikey =~ s/^<!M><~nbspace><A><~space>$/F3C8/;
	$multikey =~ s/^<!M><~nbspace><b>$/F3C9/;
	$multikey =~ s/^<!M><~nbspace><b><%slash>$/F3CA/;
	$multikey =~ s/^<!M><~nbspace><b><c>$/F3CB/;
	$multikey =~ s/^<!M><~nbspace><b><o>$/F3CC/;
	$multikey =~ s/^<!M><~nbspace><c>$/F3CD/;
	$multikey =~ s/^<!M><~nbspace><c><%backslash>$/F3CE/;
	$multikey =~ s/^<!M><~nbspace><c><%backslash><%slash>$/F3CF/;
	$multikey =~ s/^<!M><~nbspace><c><%backslash><o>$/F3D0/;
	$multikey =~ s/^<!M><~nbspace><c><c>$/F3D1/;
	$multikey =~ s/^<!M><~nbspace><c><c><%slash>$/F3D2/;
	$multikey =~ s/^<!M><~nbspace><c><c><o>$/F3D3/;
	$multikey =~ s/^<!M><~nbspace><c><c><~nbspace>$/F3D4/;
	$multikey =~ s/^<!M><~nbspace><c><c><~space>$/F3D5/;
	$multikey =~ s/^<!M><~nbspace><c><o>$/F3D6/;
	$multikey =~ s/^<!M><~nbspace><D>$/F3D7/;
	$multikey =~ s/^<!M><~nbspace><e>$/F3D8/;
	$multikey =~ s/^<!M><~nbspace><e><e>$/F3D9/;
	$multikey =~ s/^<!M><~nbspace><e><e><%bar>$/F3DA/;
	$multikey =~ s/^<!M><~nbspace><e><e><%bar><%comma>$/F3DB/;
	$multikey =~ s/^<!M><~nbspace><e><e><%bar><~nbspace>$/F3DC/;
	$multikey =~ s/^<!M><~nbspace><e><e><%bar><~space>$/F3DD/;
	$multikey =~ s/^<!M><~nbspace><e><e><%comma>$/F3DE/;
	$multikey =~ s/^<!M><~nbspace><e><e><%slash>$/F3DF/;
	$multikey =~ s/^<!M><~nbspace><e><e><~nbspace>$/F3E0/;
	$multikey =~ s/^<!M><~nbspace><e><e><~space>$/F3E1/;
	$multikey =~ s/^<!M><~nbspace><G>$/F3E2/;
	$multikey =~ s/^<!M><~nbspace><I>$/F3E3/;
	$multikey =~ s/^<!M><~nbspace><K>$/F3E4/;
	$multikey =~ s/^<!M><~nbspace><k>$/F3E5/;
	$multikey =~ s/^<!M><~nbspace><n>$/F3E6/;
	$multikey =~ s/^<!M><~nbspace><n><%bar>$/F3E7/;
	$multikey =~ s/^<!M><~nbspace><o>$/F3E8/;
	$multikey =~ s/^<!M><~nbspace><O>$/F3E9/;
	$multikey =~ s/^<!M><~nbspace><O><%backslash>$/F3EA/;
	$multikey =~ s/^<!M><~nbspace><o><%equal>$/F3EB/;
	$multikey =~ s/^<!M><~nbspace><o><%greater>$/F3EC/;
	$multikey =~ s/^<!M><~nbspace><o><%minus>$/F3ED/;
	$multikey =~ s/^<!M><~nbspace><o><%minus><%greater>$/F3EE/;
	$multikey =~ s/^<!M><~nbspace><o><%minus><~nbspace>$/F3EF/;
	$multikey =~ s/^<!M><~nbspace><o><%minus><~space>$/F3F0/;
	$multikey =~ s/^<!M><~nbspace><O><%percent>$/F3F1/;
	$multikey =~ s/^<!M><~nbspace><o><%percent>$/F3F2/;
	$multikey =~ s/^<!M><~nbspace><O><%period>$/F3F3/;
	$multikey =~ s/^<!M><~nbspace><o><%plus>$/F3F4/;
	$multikey =~ s/^<!M><~nbspace><o><%semicolon>$/F3F5/;
	$multikey =~ s/^<!M><~nbspace><o><%semsection>$/F3F6/;
	$multikey =~ s/^<!M><~nbspace><o><%slash>$/F3F7/;
	$multikey =~ s/^<!M><~nbspace><o><8>$/F3F8/;
	$multikey =~ s/^<!M><~nbspace><O><o>$/F3F9/;
	$multikey =~ s/^<!M><~nbspace><R>$/F3FA/;
	$multikey =~ s/^<!M><~nbspace><r>$/F3FB/;
	$multikey =~ s/^<!M><~nbspace><R><%slash>$/F3FC/;
	$multikey =~ s/^<!M><~nbspace><r><%slash>$/F3FD/;
	$multikey =~ s/^<!M><~nbspace><s>$/F3FE/;
	$multikey =~ s/^<!M><~nbspace><S>$/F3FF/;
	$multikey =~ s/^<!M><~nbspace><S><s>$/F400/;
	$multikey =~ s/^<!M><~nbspace><S><S>$/F401/;
	$multikey =~ s/^<!M><~nbspace><S><S><%at>$/F402/;
	$multikey =~ s/^<!M><~nbspace><S><S><~nbspace>$/F403/;
	$multikey =~ s/^<!M><~nbspace><S><S><~space>$/F404/;
	$multikey =~ s/^<!M><~nbspace><T>$/F405/;
	$multikey =~ s/^<!M><~nbspace><T><%percent>$/F406/;
	$multikey =~ s/^<!M><~nbspace><T><T>$/F407/;
	$multikey =~ s/^<!M><~nbspace><v>$/F408/;
	$multikey =~ s/^<!M><~nbspace><V>$/F409/;
	$multikey =~ s/^<!M><~nbspace><V><V>$/F40A/;
	$multikey =~ s/^<!M><~nbspace><x>$/F40B/;
	$multikey =~ s/^<!M><~nbspace><Y>$/F40C/;
	$multikey =~ s/^<!M><~nbspace><Y><%minus>$/F40D/;
	$multikey =~ s/^<!M><~nbspace><z>$/F40E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace>$/F40F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%asterisk>$/F410/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%backslash>$/F411/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%backslash><%slash>$/F412/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%backslash><~nbspace>$/F413/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%backslash><~space>$/F414/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bar>$/F415/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bar><%bar>$/F416/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bar><~nbspace>$/F417/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bar><~space>$/F418/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketleft>$/F419/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketleft><%bracketright>$/F41A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketleft><%hash>$/F41B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketright>$/F41C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketright><%bracketleft>$/F41D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%colon>$/F41E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%equal>$/F41F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%equal><%equal>$/F420/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%greater>$/F421/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%greater><%less>$/F422/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%greater><%minus>$/F423/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%hash>$/F424/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%less>$/F425/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%less><%greater>$/F426/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%less><o>$/F427/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%minus>$/F428/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%minus><%apostrophe>$/F429/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%minus><%aprightsingquotmark>$/F42A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%minus><%slash>$/F42B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%period>$/F42C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%semicolon>$/F42D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%semsection>$/F42E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash>$/F42F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash><%backslash>$/F430/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash><%minus>$/F431/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash><~nbspace>$/F432/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash><~space>$/F433/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%underscore>$/F434/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><3>$/F435/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><3><%bar>$/F436/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><8>$/F437/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><I>$/F438/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><O>$/F439/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><o>$/F43A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><o><%minus>$/F43B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><o><%plus>$/F43C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T>$/F43D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T><%percent>$/F43E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T><T>$/F43F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T><~nbspace>$/F440/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T><~space>$/F441/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace>$/F442/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%asterisk>$/F443/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%asterisk><%hash>$/F444/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%asterisk><~nbspace>$/F445/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%asterisk><~space>$/F446/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%backslash>$/F447/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%bar>$/F448/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%less>$/F449/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%slash>$/F44A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><o>$/F44B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~nbspace>$/F44C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~nbspace><%backslash>$/F44D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~nbspace><%slash>$/F44E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~space>$/F44F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~space><%backslash>$/F450/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~space><%slash>$/F451/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space>$/F452/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%asterisk>$/F453/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%asterisk><%hash>$/F454/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%asterisk><~nbspace>$/F455/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%asterisk><~space>$/F456/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%backslash>$/F457/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%bar>$/F458/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%less>$/F459/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%slash>$/F45A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><o>$/F45B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><~space>$/F45C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><~space><%backslash>$/F45D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><~space><%slash>$/F45E/;
	$multikey =~ s/^<!M><~nbspace><~space>$/F45F/;
	$multikey =~ s/^<!M><~nbspace><~space><%asterisk>$/F460/;
	$multikey =~ s/^<!M><~nbspace><~space><%backslash>$/F461/;
	$multikey =~ s/^<!M><~nbspace><~space><%backslash><%slash>$/F462/;
	$multikey =~ s/^<!M><~nbspace><~space><%backslash><~nbspace>$/F463/;
	$multikey =~ s/^<!M><~nbspace><~space><%backslash><~space>$/F464/;
	$multikey =~ s/^<!M><~nbspace><~space><%bar>$/F465/;
	$multikey =~ s/^<!M><~nbspace><~space><%bar><%bar>$/F466/;
	$multikey =~ s/^<!M><~nbspace><~space><%bar><~nbspace>$/F467/;
	$multikey =~ s/^<!M><~nbspace><~space><%bar><~space>$/F468/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketleft>$/F469/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketleft><%bracketright>$/F46A/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketleft><%hash>$/F46B/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketright>$/F46C/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketright><%bracketleft>$/F46D/;
	$multikey =~ s/^<!M><~nbspace><~space><%colon>$/F46E/;
	$multikey =~ s/^<!M><~nbspace><~space><%equal>$/F46F/;
	$multikey =~ s/^<!M><~nbspace><~space><%equal><%equal>$/F470/;
	$multikey =~ s/^<!M><~nbspace><~space><%greater>$/F471/;
	$multikey =~ s/^<!M><~nbspace><~space><%greater><%less>$/F472/;
	$multikey =~ s/^<!M><~nbspace><~space><%greater><%minus>$/F473/;
	$multikey =~ s/^<!M><~nbspace><~space><%hash>$/F474/;
	$multikey =~ s/^<!M><~nbspace><~space><%less>$/F475/;
	$multikey =~ s/^<!M><~nbspace><~space><%less><%greater>$/F476/;
	$multikey =~ s/^<!M><~nbspace><~space><%less><o>$/F477/;
	$multikey =~ s/^<!M><~nbspace><~space><%minus>$/F478/;
	$multikey =~ s/^<!M><~nbspace><~space><%minus><%apostrophe>$/F479/;
	$multikey =~ s/^<!M><~nbspace><~space><%minus><%aprightsingquotmark>$/F47A/;
	$multikey =~ s/^<!M><~nbspace><~space><%minus><%slash>$/F47B/;
	$multikey =~ s/^<!M><~nbspace><~space><%period>$/F47C/;
	$multikey =~ s/^<!M><~nbspace><~space><%semicolon>$/F47D/;
	$multikey =~ s/^<!M><~nbspace><~space><%semsection>$/F47E/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash>$/F47F/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash><%backslash>$/F480/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash><%minus>$/F481/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash><~nbspace>$/F482/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash><~space>$/F483/;
	$multikey =~ s/^<!M><~nbspace><~space><%underscore>$/F484/;
	$multikey =~ s/^<!M><~nbspace><~space><3>$/F485/;
	$multikey =~ s/^<!M><~nbspace><~space><3><%bar>$/F486/;
	$multikey =~ s/^<!M><~nbspace><~space><8>$/F487/;
	$multikey =~ s/^<!M><~nbspace><~space><I>$/F488/;
	$multikey =~ s/^<!M><~nbspace><~space><O>$/F489/;
	$multikey =~ s/^<!M><~nbspace><~space><o>$/F48A/;
	$multikey =~ s/^<!M><~nbspace><~space><o><%minus>$/F48B/;
	$multikey =~ s/^<!M><~nbspace><~space><o><%plus>$/F48C/;
	$multikey =~ s/^<!M><~nbspace><~space><T>$/F48D/;
	$multikey =~ s/^<!M><~nbspace><~space><T><%percent>$/F48E/;
	$multikey =~ s/^<!M><~nbspace><~space><T><T>$/F48F/;
	$multikey =~ s/^<!M><~nbspace><~space><T><~nbspace>$/F490/;
	$multikey =~ s/^<!M><~nbspace><~space><T><~space>$/F491/;
	$multikey =~ s/^<!M><~nbspace><~space><~space>$/F492/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%asterisk>$/F493/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%asterisk><%hash>$/F494/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%asterisk><~nbspace>$/F495/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%asterisk><~space>$/F496/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%backslash>$/F497/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%bar>$/F498/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%less>$/F499/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%slash>$/F49A/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><o>$/F49B/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><~space>$/F49C/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><~space><%backslash>$/F49D/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><~space><%slash>$/F49E/;
	$multikey =~ s/^<!M><~nbthinspace>$/F49F/;
	$multikey =~ s/^<!M><~nbthinspace><~space>$/F4A0/;
	$multikey =~ s/^<!M><~space>$/F4A1/;
	$multikey =~ s/^<!M><~space><%ampersand>$/F4A2/;
	$multikey =~ s/^<!M><~space><%ampersand><%bar>$/F4A3/;
	$multikey =~ s/^<!M><~space><%ampersand><%less>$/F4A4/;
	$multikey =~ s/^<!M><~space><%ampersand><%minus>$/F4A5/;
	$multikey =~ s/^<!M><~space><%apostrophe>$/F4A6/;
	$multikey =~ s/^<!M><~space><%apostrophe><%equal>$/F4A7/;
	$multikey =~ s/^<!M><~space><%apostrophe><%minus>$/F4A8/;
	$multikey =~ s/^<!M><~space><%apostrophe><%plus>$/F4A9/;
	$multikey =~ s/^<!M><~space><%aprightsingquotmark>$/F4AA/;
	$multikey =~ s/^<!M><~space><%aprightsingquotmark><%equal>$/F4AB/;
	$multikey =~ s/^<!M><~space><%aprightsingquotmark><%minus>$/F4AC/;
	$multikey =~ s/^<!M><~space><%aprightsingquotmark><%plus>$/F4AD/;
	$multikey =~ s/^<!M><~space><%asterisk>$/F4AE/;
	$multikey =~ s/^<!M><~space><%asterisk><%equal>$/F4AF/;
	$multikey =~ s/^<!M><~space><%asterisk><~nbspace>$/F4B0/;
	$multikey =~ s/^<!M><~space><%asterisk><~space>$/F4B1/;
	$multikey =~ s/^<!M><~space><%backslash>$/F4B2/;
	$multikey =~ s/^<!M><~space><%backslash><%greater>$/F4B3/;
	$multikey =~ s/^<!M><~space><%backslash><%minus>$/F4B4/;
	$multikey =~ s/^<!M><~space><%backslash><%slash>$/F4B5/;
	$multikey =~ s/^<!M><~space><%backslash><%slash><%bar>$/F4B6/;
	$multikey =~ s/^<!M><~space><%backslash><%slash><%hash>$/F4B7/;
	$multikey =~ s/^<!M><~space><%backslash><%slash><%underscore>$/F4B8/;
	$multikey =~ s/^<!M><~space><%backslash><c>$/F4B9/;
	$multikey =~ s/^<!M><~space><%backslash><~nbspace>$/F4BA/;
	$multikey =~ s/^<!M><~space><%backslash><~space>$/F4BB/;
	$multikey =~ s/^<!M><~space><%bar>$/F4BC/;
	$multikey =~ s/^<!M><~space><%bar><%backslash>$/F4BD/;
	$multikey =~ s/^<!M><~space><%bar><%backslash><%slash>$/F4BE/;
	$multikey =~ s/^<!M><~space><%bar><%backslash><%slash><%bar>$/F4BF/;
	$multikey =~ s/^<!M><~space><%bar><%backslash><%slash><~nbspace>$/F4C0/;
	$multikey =~ s/^<!M><~space><%bar><%backslash><%slash><~space>$/F4C1/;
	$multikey =~ s/^<!M><~space><%bar><%bar>$/F4C2/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%bar>$/F4C3/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%bar><%minus>$/F4C4/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%bar><~nbspace>$/F4C5/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%bar><~space>$/F4C6/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%minus>$/F4C7/;
	$multikey =~ s/^<!M><~space><%bar><%bar><~nbspace>$/F4C8/;
	$multikey =~ s/^<!M><~space><%bar><%bar><~space>$/F4C9/;
	$multikey =~ s/^<!M><~space><%bar><%equal>$/F4CA/;
	$multikey =~ s/^<!M><~space><%bar><%hash>$/F4CB/;
	$multikey =~ s/^<!M><~space><%bar><%minus>$/F4CC/;
	$multikey =~ s/^<!M><~space><%bar><%parenright>$/F4CD/;
	$multikey =~ s/^<!M><~space><%bar><%slash>$/F4CE/;
	$multikey =~ s/^<!M><~space><%bar><%slash><%backslash>$/F4CF/;
	$multikey =~ s/^<!M><~space><%bar><%slash><%backslash><%bar>$/F4D0/;
	$multikey =~ s/^<!M><~space><%bar><%slash><%backslash><~nbspace>$/F4D1/;
	$multikey =~ s/^<!M><~space><%bar><%slash><%backslash><~space>$/F4D2/;
	$multikey =~ s/^<!M><~space><%bar><%slash><~nbspace>$/F4D3/;
	$multikey =~ s/^<!M><~space><%bar><%slash><~space>$/F4D4/;
	$multikey =~ s/^<!M><~space><%bar><e>$/F4D5/;
	$multikey =~ s/^<!M><~space><%bar><e><%backslash>$/F4D6/;
	$multikey =~ s/^<!M><~space><%bar><e><%backslash><%comma>$/F4D7/;
	$multikey =~ s/^<!M><~space><%bar><e><%backslash><~nbspace>$/F4D8/;
	$multikey =~ s/^<!M><~space><%bar><e><%backslash><~space>$/F4D9/;
	$multikey =~ s/^<!M><~space><%bar><e><e>$/F4DA/;
	$multikey =~ s/^<!M><~space><%bar><e><e><%comma>$/F4DB/;
	$multikey =~ s/^<!M><~space><%bar><e><e><~nbspace>$/F4DC/;
	$multikey =~ s/^<!M><~space><%bar><e><e><~space>$/F4DD/;
	$multikey =~ s/^<!M><~space><%bar><o>$/F4DE/;
	$multikey =~ s/^<!M><~space><%bar><p>$/F4DF/;
	$multikey =~ s/^<!M><~space><%bar><p><%comma>$/F4E0/;
	$multikey =~ s/^<!M><~space><%bar><p><~nbspace>$/F4E1/;
	$multikey =~ s/^<!M><~space><%bar><p><~space>$/F4E2/;
	$multikey =~ s/^<!M><~space><%bar><~nbspace>$/F4E3/;
	$multikey =~ s/^<!M><~space><%bar><~space>$/F4E4/;
	$multikey =~ s/^<!M><~space><%braceleft>$/F4E5/;
	$multikey =~ s/^<!M><~space><%braceright>$/F4E6/;
	$multikey =~ s/^<!M><~space><%bracketleft>$/F4E7/;
	$multikey =~ s/^<!M><~space><%bracketleft><%bracketleft>$/F4E8/;
	$multikey =~ s/^<!M><~space><%bracketleft><%bracketright>$/F4E9/;
	$multikey =~ s/^<!M><~space><%bracketleft><%hash>$/F4EA/;
	$multikey =~ s/^<!M><~space><%bracketleft><%minus>$/F4EB/;
	$multikey =~ s/^<!M><~space><%bracketleft><%underscore>$/F4EC/;
	$multikey =~ s/^<!M><~space><%bracketleft><a>$/F4ED/;
	$multikey =~ s/^<!M><~space><%bracketleft><o>$/F4EE/;
	$multikey =~ s/^<!M><~space><%bracketright>$/F4EF/;
	$multikey =~ s/^<!M><~space><%bracketright><%bracketleft>$/F4F0/;
	$multikey =~ s/^<!M><~space><%bracketright><%bracketright>$/F4F1/;
	$multikey =~ s/^<!M><~space><%bracketright><%underscore>$/F4F2/;
	$multikey =~ s/^<!M><~space><%circum>$/F4F3/;
	$multikey =~ s/^<!M><~space><%circum><%circum>$/F4F4/;
	$multikey =~ s/^<!M><~space><%circum><%equal>$/F4F5/;
	$multikey =~ s/^<!M><~space><%circum><%underscore>$/F4F6/;
	$multikey =~ s/^<!M><~space><%circum><o>$/F4F7/;
	$multikey =~ s/^<!M><~space><%circum><O>$/F4F8/;
	$multikey =~ s/^<!M><~space><%circum><~nbspace>$/F4F9/;
	$multikey =~ s/^<!M><~space><%circum><~space>$/F4FA/;
	$multikey =~ s/^<!M><~space><%colon>$/F4FB/;
	$multikey =~ s/^<!M><~space><%colon><%colon>$/F4FC/;
	$multikey =~ s/^<!M><~space><%colon><%tilde>$/F4FD/;
	$multikey =~ s/^<!M><~space><%colon><~nbspace>$/F4FE/;
	$multikey =~ s/^<!M><~space><%colon><~space>$/F4FF/;
	$multikey =~ s/^<!M><~space><%equal>$/F500/;
	$multikey =~ s/^<!M><~space><%equal><%bar>$/F501/;
	$multikey =~ s/^<!M><~space><%equal><%bar><%bar>$/F502/;
	$multikey =~ s/^<!M><~space><%equal><%bar><~nbspace>$/F503/;
	$multikey =~ s/^<!M><~space><%equal><%bar><~space>$/F504/;
	$multikey =~ s/^<!M><~space><%equal><%equal>$/F505/;
	$multikey =~ s/^<!M><~space><%equal><%greater>$/F506/;
	$multikey =~ s/^<!M><~space><%equal><%minus>$/F507/;
	$multikey =~ s/^<!M><~space><%equal><%minus><%greater>$/F508/;
	$multikey =~ s/^<!M><~space><%equal><%minus><%slash>$/F509/;
	$multikey =~ s/^<!M><~space><%exclam>$/F50A/;
	$multikey =~ s/^<!M><~space><%exclam><%exclam>$/F50B/;
	$multikey =~ s/^<!M><~space><%exclam><j>$/F50C/;
	$multikey =~ s/^<!M><~space><%exclam><J>$/F50D/;
	$multikey =~ s/^<!M><~space><%exclam><Y>$/F50E/;
	$multikey =~ s/^<!M><~space><%greater>$/F50F/;
	$multikey =~ s/^<!M><~space><%greater><%greater>$/F510/;
	$multikey =~ s/^<!M><~space><%greater><%greater><%greater>$/F511/;
	$multikey =~ s/^<!M><~space><%greater><%greater><~nbspace>$/F512/;
	$multikey =~ s/^<!M><~space><%greater><%greater><~space>$/F513/;
	$multikey =~ s/^<!M><~space><%greater><%less>$/F514/;
	$multikey =~ s/^<!M><~space><%greater><%minus>$/F515/;
	$multikey =~ s/^<!M><~space><%greater><%minus><%greater>$/F516/;
	$multikey =~ s/^<!M><~space><%greater><%minus><~nbspace>$/F517/;
	$multikey =~ s/^<!M><~space><%greater><%minus><~space>$/F518/;
	$multikey =~ s/^<!M><~space><%greater><%parenright>$/F519/;
	$multikey =~ s/^<!M><~space><%greater><o>$/F51A/;
	$multikey =~ s/^<!M><~space><%greater><~nbspace>$/F51B/;
	$multikey =~ s/^<!M><~space><%greater><~space>$/F51C/;
	$multikey =~ s/^<!M><~space><%hash>$/F51D/;
	$multikey =~ s/^<!M><~space><%hash><%percent>$/F51E/;
	$multikey =~ s/^<!M><~space><%hash><~nbspace>$/F51F/;
	$multikey =~ s/^<!M><~space><%hash><~space>$/F520/;
	$multikey =~ s/^<!M><~space><%less>$/F521/;
	$multikey =~ s/^<!M><~space><%less><%backslash>$/F522/;
	$multikey =~ s/^<!M><~space><%less><%equal>$/F523/;
	$multikey =~ s/^<!M><~space><%less><%equal><%greater>$/F524/;
	$multikey =~ s/^<!M><~space><%less><%equal><%slash>$/F525/;
	$multikey =~ s/^<!M><~space><%less><%equal><~nbspace>$/F526/;
	$multikey =~ s/^<!M><~space><%less><%equal><~space>$/F527/;
	$multikey =~ s/^<!M><~space><%less><%exclam>$/F528/;
	$multikey =~ s/^<!M><~space><%less><%greater>$/F529/;
	$multikey =~ s/^<!M><~space><%less><%less>$/F52A/;
	$multikey =~ s/^<!M><~space><%less><%less><%less>$/F52B/;
	$multikey =~ s/^<!M><~space><%less><%less><%minus>$/F52C/;
	$multikey =~ s/^<!M><~space><%less><%less><%minus><%bar>$/F52D/;
	$multikey =~ s/^<!M><~space><%less><%less><%minus><~nbspace>$/F52E/;
	$multikey =~ s/^<!M><~space><%less><%less><%minus><~space>$/F52F/;
	$multikey =~ s/^<!M><~space><%less><%less><~nbspace>$/F530/;
	$multikey =~ s/^<!M><~space><%less><%less><~space>$/F531/;
	$multikey =~ s/^<!M><~space><%less><%minus>$/F532/;
	$multikey =~ s/^<!M><~space><%less><%minus><%bar>$/F533/;
	$multikey =~ s/^<!M><~space><%less><%minus><%less>$/F534/;
	$multikey =~ s/^<!M><~space><%less><%minus><%minus>$/F535/;
	$multikey =~ s/^<!M><~space><%less><%minus><%tilde>$/F536/;
	$multikey =~ s/^<!M><~space><%less><%minus><~nbspace>$/F537/;
	$multikey =~ s/^<!M><~space><%less><%minus><~space>$/F538/;
	$multikey =~ s/^<!M><~space><%less><%parenleft>$/F539/;
	$multikey =~ s/^<!M><~space><%less><%parenright>$/F53A/;
	$multikey =~ s/^<!M><~space><%less><%slash>$/F53B/;
	$multikey =~ s/^<!M><~space><%less><%tilde>$/F53C/;
	$multikey =~ s/^<!M><~space><%less><%tilde><%greater>$/F53D/;
	$multikey =~ s/^<!M><~space><%less><%tilde><%tilde>$/F53E/;
	$multikey =~ s/^<!M><~space><%less><%tilde><~nbspace>$/F53F/;
	$multikey =~ s/^<!M><~space><%less><%tilde><~space>$/F540/;
	$multikey =~ s/^<!M><~space><%less><3>$/F541/;
	$multikey =~ s/^<!M><~space><%less><C>$/F542/;
	$multikey =~ s/^<!M><~space><%less><n>$/F543/;
	$multikey =~ s/^<!M><~space><%less><o>$/F544/;
	$multikey =~ s/^<!M><~space><%less><~nbspace>$/F545/;
	$multikey =~ s/^<!M><~space><%less><~space>$/F546/;
	$multikey =~ s/^<!M><~space><%minus>$/F547/;
	$multikey =~ s/^<!M><~space><%minus><%apostrophe>$/F548/;
	$multikey =~ s/^<!M><~space><%minus><%apostrophe><%minus>$/F549/;
	$multikey =~ s/^<!M><~space><%minus><%apostrophe><~nbspace>$/F54A/;
	$multikey =~ s/^<!M><~space><%minus><%apostrophe><~space>$/F54B/;
	$multikey =~ s/^<!M><~space><%minus><%aprightsingquotmark>$/F54C/;
	$multikey =~ s/^<!M><~space><%minus><%aprightsingquotmark><%minus>$/F54D/;
	$multikey =~ s/^<!M><~space><%minus><%aprightsingquotmark><~nbspace>$/F54E/;
	$multikey =~ s/^<!M><~space><%minus><%aprightsingquotmark><~space>$/F54F/;
	$multikey =~ s/^<!M><~space><%minus><%bar>$/F550/;
	$multikey =~ s/^<!M><~space><%minus><%bracketleft>$/F551/;
	$multikey =~ s/^<!M><~space><%minus><%bracketright>$/F552/;
	$multikey =~ s/^<!M><~space><%minus><%bracketright><%bracketleft>$/F553/;
	$multikey =~ s/^<!M><~space><%minus><%bracketright><~nbspace>$/F554/;
	$multikey =~ s/^<!M><~space><%minus><%bracketright><~space>$/F555/;
	$multikey =~ s/^<!M><~space><%minus><%slash>$/F556/;
	$multikey =~ s/^<!M><~space><%minus><e>$/F557/;
	$multikey =~ s/^<!M><~space><%minus><j>$/F558/;
	$multikey =~ s/^<!M><~space><%minus><J>$/F559/;
	$multikey =~ s/^<!M><~space><%minus><O>$/F55A/;
	$multikey =~ s/^<!M><~space><%minus><o>$/F55B/;
	$multikey =~ s/^<!M><~space><%minus><o><%minus>$/F55C/;
	$multikey =~ s/^<!M><~space><%minus><o><~nbspace>$/F55D/;
	$multikey =~ s/^<!M><~space><%minus><o><~space>$/F55E/;
	$multikey =~ s/^<!M><~space><%minus><S>$/F55F/;
	$multikey =~ s/^<!M><~space><%minus><s>$/F560/;
	$multikey =~ s/^<!M><~space><%minus><s><%slash>$/F561/;
	$multikey =~ s/^<!M><~space><%minus><s><~nbspace>$/F562/;
	$multikey =~ s/^<!M><~space><%minus><s><~space>$/F563/;
	$multikey =~ s/^<!M><~space><%minus><Y>$/F564/;
	$multikey =~ s/^<!M><~space><%minus><~nbspace>$/F565/;
	$multikey =~ s/^<!M><~space><%minus><~space>$/F566/;
	$multikey =~ s/^<!M><~space><%parenleft>$/F567/;
	$multikey =~ s/^<!M><~space><%parenleft><%bracketleft>$/F568/;
	$multikey =~ s/^<!M><~space><%parenleft><%bracketright>$/F569/;
	$multikey =~ s/^<!M><~space><%parenleft><%equal>$/F56A/;
	$multikey =~ s/^<!M><~space><%parenleft><%greater>$/F56B/;
	$multikey =~ s/^<!M><~space><%parenleft><%less>$/F56C/;
	$multikey =~ s/^<!M><~space><%parenleft><%parenleft>$/F56D/;
	$multikey =~ s/^<!M><~space><%parenleft><8>$/F56E/;
	$multikey =~ s/^<!M><~space><%parenleft><~nbspace>$/F56F/;
	$multikey =~ s/^<!M><~space><%parenleft><~space>$/F570/;
	$multikey =~ s/^<!M><~space><%parenright>$/F571/;
	$multikey =~ s/^<!M><~space><%parenright><%bracketleft>$/F572/;
	$multikey =~ s/^<!M><~space><%parenright><%bracketright>$/F573/;
	$multikey =~ s/^<!M><~space><%parenright><%greater>$/F574/;
	$multikey =~ s/^<!M><~space><%parenright><%parenright>$/F575/;
	$multikey =~ s/^<!M><~space><%period>$/F576/;
	$multikey =~ s/^<!M><~space><%period><a>$/F577/;
	$multikey =~ s/^<!M><~space><%period><A>$/F578/;
	$multikey =~ s/^<!M><~space><%period><b>$/F579/;
	$multikey =~ s/^<!M><~space><%period><c>$/F57A/;
	$multikey =~ s/^<!M><~space><%period><c><%backslash>$/F57B/;
	$multikey =~ s/^<!M><~space><%period><c><%underscore>$/F57C/;
	$multikey =~ s/^<!M><~space><%period><c><c>$/F57D/;
	$multikey =~ s/^<!M><~space><%period><e>$/F57E/;
	$multikey =~ s/^<!M><~space><%period><v>$/F57F/;
	$multikey =~ s/^<!M><~space><%period><V>$/F580/;
	$multikey =~ s/^<!M><~space><%period><v><v>$/F581/;
	$multikey =~ s/^<!M><~space><%period><V><V>$/F582/;
	$multikey =~ s/^<!M><~space><%period><v><~nbspace>$/F583/;
	$multikey =~ s/^<!M><~space><%period><V><~nbspace>$/F584/;
	$multikey =~ s/^<!M><~space><%period><v><~space>$/F585/;
	$multikey =~ s/^<!M><~space><%period><V><~space>$/F586/;
	$multikey =~ s/^<!M><~space><%period><x>$/F587/;
	$multikey =~ s/^<!M><~space><%period><~nbspace>$/F588/;
	$multikey =~ s/^<!M><~space><%period><~space>$/F589/;
	$multikey =~ s/^<!M><~space><%plus>$/F58A/;
	$multikey =~ s/^<!M><~space><%plus><%apostrophe>$/F58B/;
	$multikey =~ s/^<!M><~space><%plus><%aprightsingquotmark>$/F58C/;
	$multikey =~ s/^<!M><~space><%plus><%circum>$/F58D/;
	$multikey =~ s/^<!M><~space><%plus><%plus>$/F58E/;
	$multikey =~ s/^<!M><~space><%plus><2>$/F58F/;
	$multikey =~ s/^<!M><~space><%semicolon>$/F590/;
	$multikey =~ s/^<!M><~space><%semsection>$/F591/;
	$multikey =~ s/^<!M><~space><%slash>$/F592/;
	$multikey =~ s/^<!M><~space><%slash><%backslash>$/F593/;
	$multikey =~ s/^<!M><~space><%slash><%backslash><%bar>$/F594/;
	$multikey =~ s/^<!M><~space><%slash><%backslash><%hash>$/F595/;
	$multikey =~ s/^<!M><~space><%slash><%backslash><%underscore>$/F596/;
	$multikey =~ s/^<!M><~space><%slash><%hash>$/F597/;
	$multikey =~ s/^<!M><~space><%slash><%hash><%underscore>$/F598/;
	$multikey =~ s/^<!M><~space><%slash><%hash><%underscore><%backslash>$/F599/;
	$multikey =~ s/^<!M><~space><%slash><%slash>$/F59A/;
	$multikey =~ s/^<!M><~space><%slash><%slash><%slash>$/F59B/;
	$multikey =~ s/^<!M><~space><%slash><%slash><~nbspace>$/F59C/;
	$multikey =~ s/^<!M><~space><%slash><%slash><~space>$/F59D/;
	$multikey =~ s/^<!M><~space><%slash><%underscore>$/F59E/;
	$multikey =~ s/^<!M><~space><%slash><%underscore><%backslash>$/F59F/;
	$multikey =~ s/^<!M><~space><%slash><c>$/F5A0/;
	$multikey =~ s/^<!M><~space><%slash><~nbspace>$/F5A1/;
	$multikey =~ s/^<!M><~space><%slash><~space>$/F5A2/;
	$multikey =~ s/^<!M><~space><%tilde>$/F5A3/;
	$multikey =~ s/^<!M><~space><%tilde><%colon>$/F5A4/;
	$multikey =~ s/^<!M><~space><%tilde><%equal>$/F5A5/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><%slash>$/F5A6/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><%slash><%slash>$/F5A7/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><%slash><~nbspace>$/F5A8/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><%slash><~space>$/F5A9/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><~nbspace>$/F5AA/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><~space>$/F5AB/;
	$multikey =~ s/^<!M><~space><%tilde><%greater>$/F5AC/;
	$multikey =~ s/^<!M><~space><%tilde><%minus>$/F5AD/;
	$multikey =~ s/^<!M><~space><%tilde><%percent>$/F5AE/;
	$multikey =~ s/^<!M><~space><%tilde><%slash>$/F5AF/;
	$multikey =~ s/^<!M><~space><%tilde><%slash><~nbspace>$/F5B0/;
	$multikey =~ s/^<!M><~space><%tilde><%slash><~space>$/F5B1/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde>$/F5B2/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde><%equal>$/F5B3/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde><%tilde>$/F5B4/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde><~nbspace>$/F5B5/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde><~space>$/F5B6/;
	$multikey =~ s/^<!M><~space><%tilde><~nbspace>$/F5B7/;
	$multikey =~ s/^<!M><~space><%tilde><~space>$/F5B8/;
	$multikey =~ s/^<!M><~space><%underscore>$/F5B9/;
	$multikey =~ s/^<!M><~space><%underscore><%backslash>$/F5BA/;
	$multikey =~ s/^<!M><~space><%underscore><%hash>$/F5BB/;
	$multikey =~ s/^<!M><~space><%underscore><%minus>$/F5BC/;
	$multikey =~ s/^<!M><~space><%underscore><%minus><%apostrophe>$/F5BD/;
	$multikey =~ s/^<!M><~space><%underscore><%minus><%aprightsingquotmark>$/F5BE/;
	$multikey =~ s/^<!M><~space><%underscore><%minus><%slash>$/F5BF/;
	$multikey =~ s/^<!M><~space><%underscore><%slash>$/F5C0/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore>$/F5C1/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><v>$/F5C2/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><V>$/F5C3/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><v><%percent>$/F5C4/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><V><%percent>$/F5C5/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><v><~nbspace>$/F5C6/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><V><~nbspace>$/F5C7/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><v><~space>$/F5C8/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><V><~space>$/F5C9/;
	$multikey =~ s/^<!M><~space><%underscore><a>$/F5CA/;
	$multikey =~ s/^<!M><~space><%underscore><e>$/F5CB/;
	$multikey =~ s/^<!M><~space><%underscore><e><%backslash>$/F5CC/;
	$multikey =~ s/^<!M><~space><%underscore><e><%backslash><%comma>$/F5CD/;
	$multikey =~ s/^<!M><~space><%underscore><e><%backslash><~nbspace>$/F5CE/;
	$multikey =~ s/^<!M><~space><%underscore><e><%backslash><~space>$/F5CF/;
	$multikey =~ s/^<!M><~space><%underscore><e><%comma>$/F5D0/;
	$multikey =~ s/^<!M><~space><%underscore><e><~nbspace>$/F5D1/;
	$multikey =~ s/^<!M><~space><%underscore><e><~space>$/F5D2/;
	$multikey =~ s/^<!M><~space><%underscore><n>$/F5D3/;
	$multikey =~ s/^<!M><~space><%underscore><p>$/F5D4/;
	$multikey =~ s/^<!M><~space><%underscore><p><%comma>$/F5D5/;
	$multikey =~ s/^<!M><~space><%underscore><p><~nbspace>$/F5D6/;
	$multikey =~ s/^<!M><~space><%underscore><p><~space>$/F5D7/;
	$multikey =~ s/^<!M><~space><%underscore><u>$/F5D8/;
	$multikey =~ s/^<!M><~space><%underscore><u><%hash>$/F5D9/;
	$multikey =~ s/^<!M><~space><%underscore><u><~nbspace>$/F5DA/;
	$multikey =~ s/^<!M><~space><%underscore><u><~space>$/F5DB/;
	$multikey =~ s/^<!M><~space><%underscore><v>$/F5DC/;
	$multikey =~ s/^<!M><~space><%underscore><v><v>$/F5DD/;
	$multikey =~ s/^<!M><~space><%underscore><v><~nbspace>$/F5DE/;
	$multikey =~ s/^<!M><~space><%underscore><v><~space>$/F5DF/;
	$multikey =~ s/^<!M><~space><%underscore><X>$/F5E0/;
	$multikey =~ s/^<!M><~space><%underscore><X><%hash>$/F5E1/;
	$multikey =~ s/^<!M><~space><%underscore><X><%underscore>$/F5E2/;
	$multikey =~ s/^<!M><~space><2>$/F5E3/;
	$multikey =~ s/^<!M><~space><2><%less>$/F5E4/;
	$multikey =~ s/^<!M><~space><2><%minus>$/F5E5/;
	$multikey =~ s/^<!M><~space><3>$/F5E6/;
	$multikey =~ s/^<!M><~space><3><%bar>$/F5E7/;
	$multikey =~ s/^<!M><~space><3><%minus>$/F5E8/;
	$multikey =~ s/^<!M><~space><8>$/F5E9/;
	$multikey =~ s/^<!M><~space><A>$/F5EA/;
	$multikey =~ s/^<!M><~space><a>$/F5EB/;
	$multikey =~ s/^<!M><~space><A><%minus>$/F5EC/;
	$multikey =~ s/^<!M><~space><A><%underscore>$/F5ED/;
	$multikey =~ s/^<!M><~space><A><%underscore><%underscore>$/F5EE/;
	$multikey =~ s/^<!M><~space><A><%underscore><~nbspace>$/F5EF/;
	$multikey =~ s/^<!M><~space><A><%underscore><~space>$/F5F0/;
	$multikey =~ s/^<!M><~space><A><A>$/F5F1/;
	$multikey =~ s/^<!M><~space><a><a>$/F5F2/;
	$multikey =~ s/^<!M><~space><A><V>$/F5F3/;
	$multikey =~ s/^<!M><~space><a><v>$/F5F4/;
	$multikey =~ s/^<!M><~space><A><~nbspace>$/F5F5/;
	$multikey =~ s/^<!M><~space><A><~space>$/F5F6/;
	$multikey =~ s/^<!M><~space><b>$/F5F7/;
	$multikey =~ s/^<!M><~space><b><%slash>$/F5F8/;
	$multikey =~ s/^<!M><~space><b><c>$/F5F9/;
	$multikey =~ s/^<!M><~space><b><o>$/F5FA/;
	$multikey =~ s/^<!M><~space><b><~nbspace>$/F5FB/;
	$multikey =~ s/^<!M><~space><b><~space>$/F5FC/;
	$multikey =~ s/^<!M><~space><c>$/F5FD/;
	$multikey =~ s/^<!M><~space><c><%backslash>$/F5FE/;
	$multikey =~ s/^<!M><~space><c><%backslash><%slash>$/F5FF/;
	$multikey =~ s/^<!M><~space><c><%backslash><o>$/F600/;
	$multikey =~ s/^<!M><~space><c><c>$/F601/;
	$multikey =~ s/^<!M><~space><c><c><%slash>$/F602/;
	$multikey =~ s/^<!M><~space><c><c><o>$/F603/;
	$multikey =~ s/^<!M><~space><c><c><~nbspace>$/F604/;
	$multikey =~ s/^<!M><~space><c><c><~space>$/F605/;
	$multikey =~ s/^<!M><~space><c><o>$/F606/;
	$multikey =~ s/^<!M><~space><D>$/F607/;
	$multikey =~ s/^<!M><~space><e>$/F608/;
	$multikey =~ s/^<!M><~space><e><e>$/F609/;
	$multikey =~ s/^<!M><~space><e><e><%bar>$/F60A/;
	$multikey =~ s/^<!M><~space><e><e><%bar><%comma>$/F60B/;
	$multikey =~ s/^<!M><~space><e><e><%bar><~nbspace>$/F60C/;
	$multikey =~ s/^<!M><~space><e><e><%bar><~space>$/F60D/;
	$multikey =~ s/^<!M><~space><e><e><%comma>$/F60E/;
	$multikey =~ s/^<!M><~space><e><e><%slash>$/F60F/;
	$multikey =~ s/^<!M><~space><e><e><~nbspace>$/F610/;
	$multikey =~ s/^<!M><~space><e><e><~space>$/F611/;
	$multikey =~ s/^<!M><~space><G>$/F612/;
	$multikey =~ s/^<!M><~space><h>$/F613/;
	$multikey =~ s/^<!M><~space><I>$/F614/;
	$multikey =~ s/^<!M><~space><K>$/F615/;
	$multikey =~ s/^<!M><~space><k>$/F616/;
	$multikey =~ s/^<!M><~space><n>$/F617/;
	$multikey =~ s/^<!M><~space><n><%bar>$/F618/;
	$multikey =~ s/^<!M><~space><o>$/F619/;
	$multikey =~ s/^<!M><~space><O>$/F61A/;
	$multikey =~ s/^<!M><~space><O><%backslash>$/F61B/;
	$multikey =~ s/^<!M><~space><o><%equal>$/F61C/;
	$multikey =~ s/^<!M><~space><o><%greater>$/F61D/;
	$multikey =~ s/^<!M><~space><o><%minus>$/F61E/;
	$multikey =~ s/^<!M><~space><o><%minus><%greater>$/F61F/;
	$multikey =~ s/^<!M><~space><o><%minus><~nbspace>$/F620/;
	$multikey =~ s/^<!M><~space><o><%minus><~space>$/F621/;
	$multikey =~ s/^<!M><~space><O><%percent>$/F622/;
	$multikey =~ s/^<!M><~space><o><%percent>$/F623/;
	$multikey =~ s/^<!M><~space><O><%period>$/F624/;
	$multikey =~ s/^<!M><~space><o><%plus>$/F625/;
	$multikey =~ s/^<!M><~space><o><%semicolon>$/F626/;
	$multikey =~ s/^<!M><~space><o><%semsection>$/F627/;
	$multikey =~ s/^<!M><~space><o><%slash>$/F628/;
	$multikey =~ s/^<!M><~space><o><8>$/F629/;
	$multikey =~ s/^<!M><~space><O><o>$/F62A/;
	$multikey =~ s/^<!M><~space><R>$/F62B/;
	$multikey =~ s/^<!M><~space><r>$/F62C/;
	$multikey =~ s/^<!M><~space><R><%slash>$/F62D/;
	$multikey =~ s/^<!M><~space><r><%slash>$/F62E/;
	$multikey =~ s/^<!M><~space><s>$/F62F/;
	$multikey =~ s/^<!M><~space><S>$/F630/;
	$multikey =~ s/^<!M><~space><S><s>$/F631/;
	$multikey =~ s/^<!M><~space><S><S>$/F632/;
	$multikey =~ s/^<!M><~space><S><S><%at>$/F633/;
	$multikey =~ s/^<!M><~space><S><S><~nbspace>$/F634/;
	$multikey =~ s/^<!M><~space><S><S><~space>$/F635/;
	$multikey =~ s/^<!M><~space><T>$/F636/;
	$multikey =~ s/^<!M><~space><T><%percent>$/F637/;
	$multikey =~ s/^<!M><~space><T><T>$/F638/;
	$multikey =~ s/^<!M><~space><T><~nbspace>$/F639/;
	$multikey =~ s/^<!M><~space><T><~space>$/F63A/;
	$multikey =~ s/^<!M><~space><v>$/F63B/;
	$multikey =~ s/^<!M><~space><V>$/F63C/;
	$multikey =~ s/^<!M><~space><V><V>$/F63D/;
	$multikey =~ s/^<!M><~space><x>$/F63E/;
	$multikey =~ s/^<!M><~space><Y>$/F63F/;
	$multikey =~ s/^<!M><~space><Y><%minus>$/F640/;
	$multikey =~ s/^<!M><~space><z>$/F641/;
	$multikey =~ s/^<!M><~space><Z>$/F642/;
	$multikey =~ s/^<!M><~space><~nbspace>$/F643/;
	$multikey =~ s/^<!M><~space><~space>$/F644/;
	$multikey =~ s/^<!M><~space><~space><%asterisk>$/F645/;
	$multikey =~ s/^<!M><~space><~space><%backslash>$/F646/;
	$multikey =~ s/^<!M><~space><~space><%backslash><%slash>$/F647/;
	$multikey =~ s/^<!M><~space><~space><%backslash><~nbspace>$/F648/;
	$multikey =~ s/^<!M><~space><~space><%backslash><~space>$/F649/;
	$multikey =~ s/^<!M><~space><~space><%bar>$/F64A/;
	$multikey =~ s/^<!M><~space><~space><%bar><%bar>$/F64B/;
	$multikey =~ s/^<!M><~space><~space><%bar><~nbspace>$/F64C/;
	$multikey =~ s/^<!M><~space><~space><%bar><~space>$/F64D/;
	$multikey =~ s/^<!M><~space><~space><%bracketleft>$/F64E/;
	$multikey =~ s/^<!M><~space><~space><%bracketleft><%bracketright>$/F64F/;
	$multikey =~ s/^<!M><~space><~space><%bracketleft><%hash>$/F650/;
	$multikey =~ s/^<!M><~space><~space><%bracketright>$/F651/;
	$multikey =~ s/^<!M><~space><~space><%bracketright><%bracketleft>$/F652/;
	$multikey =~ s/^<!M><~space><~space><%colon>$/F653/;
	$multikey =~ s/^<!M><~space><~space><%equal>$/F654/;
	$multikey =~ s/^<!M><~space><~space><%equal><%equal>$/F655/;
	$multikey =~ s/^<!M><~space><~space><%greater>$/F656/;
	$multikey =~ s/^<!M><~space><~space><%greater><%less>$/F657/;
	$multikey =~ s/^<!M><~space><~space><%greater><%minus>$/F658/;
	$multikey =~ s/^<!M><~space><~space><%hash>$/F659/;
	$multikey =~ s/^<!M><~space><~space><%less>$/F65A/;
	$multikey =~ s/^<!M><~space><~space><%less><%greater>$/F65B/;
	$multikey =~ s/^<!M><~space><~space><%less><o>$/F65C/;
	$multikey =~ s/^<!M><~space><~space><%minus>$/F65D/;
	$multikey =~ s/^<!M><~space><~space><%minus><%apostrophe>$/F65E/;
	$multikey =~ s/^<!M><~space><~space><%minus><%aprightsingquotmark>$/F65F/;
	$multikey =~ s/^<!M><~space><~space><%minus><%slash>$/F660/;
	$multikey =~ s/^<!M><~space><~space><%period>$/F661/;
	$multikey =~ s/^<!M><~space><~space><%semicolon>$/F662/;
	$multikey =~ s/^<!M><~space><~space><%semsection>$/F663/;
	$multikey =~ s/^<!M><~space><~space><%slash>$/F664/;
	$multikey =~ s/^<!M><~space><~space><%slash><%backslash>$/F665/;
	$multikey =~ s/^<!M><~space><~space><%slash><%minus>$/F666/;
	$multikey =~ s/^<!M><~space><~space><%slash><~nbspace>$/F667/;
	$multikey =~ s/^<!M><~space><~space><%slash><~space>$/F668/;
	$multikey =~ s/^<!M><~space><~space><%underscore>$/F669/;
	$multikey =~ s/^<!M><~space><~space><3>$/F66A/;
	$multikey =~ s/^<!M><~space><~space><3><%bar>$/F66B/;
	$multikey =~ s/^<!M><~space><~space><8>$/F66C/;
	$multikey =~ s/^<!M><~space><~space><I>$/F66D/;
	$multikey =~ s/^<!M><~space><~space><O>$/F66E/;
	$multikey =~ s/^<!M><~space><~space><o>$/F66F/;
	$multikey =~ s/^<!M><~space><~space><o><%minus>$/F670/;
	$multikey =~ s/^<!M><~space><~space><o><%plus>$/F671/;
	$multikey =~ s/^<!M><~space><~space><T>$/F672/;
	$multikey =~ s/^<!M><~space><~space><T><%percent>$/F673/;
	$multikey =~ s/^<!M><~space><~space><T><T>$/F674/;
	$multikey =~ s/^<!M><~space><~space><T><~nbspace>$/F675/;
	$multikey =~ s/^<!M><~space><~space><T><~space>$/F676/;
	$multikey =~ s/^<!M><~space><~space><~space>$/F677/;
	$multikey =~ s/^<!M><~space><~space><~space><%asterisk>$/F678/;
	$multikey =~ s/^<!M><~space><~space><~space><%asterisk><%hash>$/F679/;
	$multikey =~ s/^<!M><~space><~space><~space><%asterisk><~nbspace>$/F67A/;
	$multikey =~ s/^<!M><~space><~space><~space><%asterisk><~space>$/F67B/;
	$multikey =~ s/^<!M><~space><~space><~space><%backslash>$/F67C/;
	$multikey =~ s/^<!M><~space><~space><~space><%bar>$/F67D/;
	$multikey =~ s/^<!M><~space><~space><~space><%less>$/F67E/;
	$multikey =~ s/^<!M><~space><~space><~space><%slash>$/F67F/;
	$multikey =~ s/^<!M><~space><~space><~space><o>$/F680/;
	$multikey =~ s/^<!M><~space><~space><~space><~space>$/F681/;
	$multikey =~ s/^<!M><~space><~space><~space><~space><%backslash>$/F682/;
	$multikey =~ s/^<!M><~space><~space><~space><~space><%slash>$/F683/;

	return $multikey;
}

# Processes the source.
print( "Parsing $input_path in progress ---\n" );
print CONSOLE ( "Parsing $input_path in progress ---\n" );

while ( my $line = <INPUT> ) {
	if ( $line =~ /START_GREEK/ ) {

		# To include polytonic Greek, comment this out.
		# $parse_on = !1;

		# Multikey equivalents of dead keys are output separately.
		$parse_equivalents = !0;
	}
	if ( $line =~ /START_LATIN_BY_DEAD_KEYS/ ) {
		$parse_on = !0;
	}

	if ( $parse_on ) {
		unless ( $line =~ /^#[^@]/         # Annotations, without Windows-specific.
			|| $line =~ /^<[^>]+> * :/       # Multichar for live keys.
			|| $line =~ /# [Aa]vailable\.?$/ # Empty slots in letter groups.
			|| $line =~ /<KP_/               # Keypad equivalents, a Linux feature.
		) {

			# Remove the Windows-specific prefix.
			$line =~ s/^#@//;

			# Collapse spaces.
			$line =~ s/ {2,}/ /g;

			# Concatenate keysyms.
			$line =~ s/> </></g;

			# Simplify dead key names and prepare for sorting.
			$line =~ s/<dead_/<!/g;
			$line =~ s/<Multi_key/<!M/g;

			# Decode keysyms.
			$line =~ s/<UEFD0>/<!group>/g;
			$line =~ s/<UEFD1>/<!superscript>/g;
			$line =~ s/<UEFD2>/<!subscript>/g;
			$line =~ s/<UEFD3>/<!abovehook>/g;
			$line =~ s/<UEFD4>/<!retroflexhook>/g;
			$line =~ s/<UEFD5>/<!turned>/g;
			$line =~ s/<UEFD6>/<!reversed>/g;
			$line =~ s/<UEFD7>/<!flag>/g;
			$line =~ s/<UEFD8>/<!bar>/g;
			$line =~ s/<UEFD9>/<!legacytilde>/g;
			$line =~ s/<UEFDA>/<!legacygrave>/g;
			$line =~ s/<U0190>/<Eopen>/g;
			$line =~ s/<U025B>/<eopen>/g;
			$line =~ s/<U0186>/<Oopen>/g;
			$line =~ s/<U0254>/<oopen>/g;

			# Prepare for sorting, shorten, further decode.
			$line =~ s/<EuroSign>/<\%quotEuroSign>/g;
			$line =~ s/<section>/<\%semsection>/g;
			$line =~ s/<rightsinglequotemark>/<\%aprightsingquotmark>/g;
			$line =~ s/<ascii(circum|tilde)>/<\%$1>/g;
			$line =~ s/<numbersign>/<\%hash>/g;
			$line =~ s/<(ampersand|apostrophe|asterisk|at|backslash|bar|braceleft|braceright|bracketleft|bracketright
									|colon|comma|dollar|equal|exclam|grave|greater|less|minus|parenleft|parenright
									|percent|period|plus|question|quotedbl|semicolon|slash|underscore)>/<\%$1>/gx;
			$line =~ s/<(space)>/<~$1>/g;
			$line =~ s/<nobreak(space)>/<~nb$1>/g;
			$line =~ s/<U202F>/<~nbthinspace>/g;
			$line =~ s/<U200B>/<~spacezerowidth>/g;

			# Store dead keys and multikey in 3 arrays.
			if ( $line =~ /^(#@)?<!M>/ ) {
				if ( $parse_equivalents eq !0 && $support_multikey_equivalents eq !0 ) {
					push( @mk_equiv_out, $line );

					# Add to catalog.
					$line =~ m/(<.+>).+/;
					push( @mk_equiv_parsed, $1 );

				} elsif ( $parse_equivalents eq !1 ) {
					push( @multikey_out, $line );

					# Add to catalog.
					$line =~ m/(<.+>).+/;
					push( @multikey_parsed, $1 );
				}

			} else {
				push( @dead_key_out, $line );
			}
		}
	}
}
print( "Parsing $input_path complete.\n" );
print CONSOLE ( "Parsing $input_path complete.\n" );

# Add missing links to multikey chains.
print( "Adding missing links to multikey chains in progress ---\n" );
print CONSOLE ( "Adding missing links to multikey chains in progress ---\n" );
@multikey_complete = @multikey_parsed;
print( "multikey_parsed has " . @multikey_parsed . " elements.\n" );
print CONSOLE ( "multikey_parsed has " . @multikey_parsed . " elements.\n" );
my $counter = 0;
foreach my $entry ( @multikey_parsed ) {
	++$counter;
	#print( "element number $counter\n" );
	#print CONSOLE ( "element number $counter\n" );
	do {
		$entry =~ m/^(<.+>)<.+>$/;
		#print( "entry is $entry\n" );
		#print CONSOLE ( "entry is $entry\n" );
		$preceding = $1;
		#print( "preceding is $preceding\n" );
		#print CONSOLE ( "preceding is $preceding\n" );
		# This should work better than "unless ( grep { /^\Q$preceding$/ } @multikey_complete ) {".
		my $ok = !1;
		foreach my $item ( @multikey_complete ) {
			if ( $item eq $preceding ) {
				$ok = !0;
				last;
				#print( "The element $preceding is already in the list.\n" );
				#print CONSOLE ( "The element $preceding is already in the list.\n" );
			}
		}
		if ( $ok eq !1 ) {
			push( @multikey_complete, $preceding );
			push( @multikey_out, $preceding );
			#print( "added $preceding\n" );
			#print CONSOLE ( "added $preceding\n" );
		}
		$entry =~ s/^(<.+>)<.+>$/$1/;
		#print( "new entry will be $entry\n" );
		#print CONSOLE ( "new entry will be $entry\n" );
	} while ( $entry =~ /^<.+><.+>$/ );
}
print( "Adding missing links to multikey chains complete.\n" );
print CONSOLE ( "Adding missing links to multikey chains complete.\n" );

# Add missing links to multikey equivalent chains.
print( "Adding missing links to multikey equivalent chains in progress ---\n" );
print CONSOLE ( "Adding missing links to multikey equivalent chains in progress ---\n" );
@mk_equiv_complete = @mk_equiv_parsed;
foreach my $entry ( @mk_equiv_parsed ) {
	do {
		$entry =~ m/^(<.+>)<.+>$/;
		$preceding = $1;
		# This should work better than "unless ( grep { /^\Q$preceding$/ } @mk_equiv_complete ) {".
		my $ok = !1;
		foreach my $item ( @multikey_complete ) {
			if ( $item eq $preceding ) {
				$ok = !0;
				last;
			}
		}
		if ( $ok eq !1 ) {
			push( @multikey_complete, $preceding );
			push( @multikey_out, $preceding );
		}
		$entry =~ s/^(<.+>)<.+>$/$1/;
	} while ( $entry =~ /^<.+><.+>$/ );
}
print( "Adding missing links to multikey equivalent chains complete.\n" );
print CONSOLE ( "Adding missing links to multikey equivalent chains complete.\n" );

# Case insensitive sorting.
# By courtesy of https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
print( "Case insensitive sorting in progress ---\n" );
print CONSOLE ( "Case insensitive sorting in progress ---\n" );
@dead_key_out      = sort { "\L$a" cmp "\L$b" } @dead_key_out;
@multikey_complete = sort { "\L$a" cmp "\L$b" } @multikey_complete;
@multikey_out      = sort { "\L$a" cmp "\L$b" } @multikey_out;
@mk_equiv_complete = sort { "\L$a" cmp "\L$b" } @mk_equiv_complete;
@mk_equiv_out      = sort { "\L$a" cmp "\L$b" } @mk_equiv_out;
print( "Case insensitive sorting complete.\n" );
print CONSOLE ( "Case insensitive sorting complete.\n" );

# Define the multikey dead characters.
print( "Defining the multikey dead characters in progress ---\n" );
print CONSOLE ( "Defining the multikey dead characters in progress ---\n" );
foreach my $entry ( @multikey_complete ) {
	push( @multikey_dchars, $entry . '➔' . $dead_hex );
	++$dead_dec;
	$dead_hex = sprintf( "%X", $dead_dec ); # To hex.
}
print( "Defining the multikey dead characters complete.\n" );
print CONSOLE ( "Defining the multikey dead characters complete.\n" );

# Define the dead key multikey equivalent dead characters in the same array.
print( "Defining the multikey equivalent dead characters in progress ---\n" );
print CONSOLE ( "Defining the multikey equivalent dead characters in progress ---\n" );
foreach my $entry ( @mk_equiv_complete ) {
	push( @multikey_dchars, $entry . '➔' . $dead_hex );
	++$dead_dec;
	$dead_hex = sprintf( "%X", $dead_dec ); # To hex.
}
print( "Defining the multikey equivalent dead characters complete.\n" );
print CONSOLE ( "Defining the multikey equivalent dead characters complete.\n" );

# Process single-character dead key output without multicharacter input.
print( "Processing the dead key output in progress ---\n" );
print CONSOLE ( "Processing the dead key output in progress ---\n" );
foreach my $line ( @dead_key_out ) {
	if ( $line =~ /" U[0-9A-F]{4,5}/ ) { # Single-character output.
		unless ( $line =~ /<UEF/ ) {       # Multicharacter input.
			$line          =~ m/(<.+>)(<.+>) : "(.)" U([0-9A-F]{4,5}) # (.+)/u;
			$deadkey       = $1;
			$input         = $2;
			$output_string = $3;
			$output_code   = $4;
			$comment       = $5;

			$deadchar = get_dead_character( $deadkey );

			# Register unsupported keysym.
			if ( $deadchar =~ /^<.+>$/ ) {
				unless ( grep( /^\Q$deadchar$/, @unsupported ) ) {
					push( @unsupported, $deadchar );
				}
				$deadchar = 'dead';
			}

			# Get input code for DEADTRANS call.
			$input = get_dead_character( $input );
			$input =~ s/<(.+)>/$1/;
			$input =~ s/U([0-9A-F]{4})/$1/;
			$input = dekeysym( $input );

			# Get input character for annotation.
			if ( $input =~ /[0-9A-F]{4}/ ) {
				$input_string = chr( hex( $input ) );
			} else {
				$input_string = $input;
				$input_string =~ s/\\?(.)/$1/;
				if ( $input_string =~ /^"$/ ) {
					$delim = "'";
				}
			}

			# Convert SMP characters to surrogate pairs.
			if ( $output_code =~ /[0-9A-F]{5}/ ) {
				$high_su = sprintf( "%X", ( 55232 + int( hex( $output_code ) / 1024 ) ) );
				unless ( grep( /^$high_su$/, @high_surrogates ) ) {
					push( @high_surrogates, $high_su );
				}
				$high_out    = 'High surrogate: ' . $high_su . '; U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
				++$half;
				print LOG $high_su . ', ' . $deadkey . "\n";

			} else {
				$high_out = '';
				++$full;
			}

			# Generate annotated DEADTRANS call.
			$print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		++$multichar;
		$print = '';
	}
 
	print DEADKEYS $print;

}
print( "Processing the dead key output complete.\n" );
print CONSOLE ( "Processing the dead key output complete.\n" );

# Process single-character multikey output without multicharacter input.
print( "Processing the dedicated multikey output in progress ---\n" );
print CONSOLE ( "Processing the dedicated multikey output in progress ---\n" );
foreach my $line ( @multikey_out ) {
	if ( $line =~ /" U[0-9A-F]{4,5}/ ) { # Single-character output.
		unless ( $line =~ /<UEF/ ) {       # Multicharacter input.
			$line          =~ m/((<.+>)(<.+>)) : "(.)" U([0-9A-F]{4,5}) # (.+)/u;
			$full_chain    = $1;
			$deadkey       = $2;
			$input         = $3;
			$output_string = $4;
			$output_code   = $5;
			$comment       = $6;

			$deadchar = get_multikey_dead_character( $deadkey );

			# Get input code for DEADTRANS call.
			$input = get_dead_character( $input );
			$input =~ s/<(.+)>/$1/;
			$input =~ s/U([0-9A-F]{4})/$1/;
			$input = dekeysym( $input );

			# Get input character for annotation.
			if ( $input =~ /[0-9A-F]{4}/ ) {
				$input_string = chr( hex( $input ) );
			} else {
				$input_string = $input;
				$input_string =~ s/\\?(.)/$1/;
				if ( $input_string =~ /^"$/ ) {
					$delim = "'";
				}
			}

			if ( $output_code =~ /[0-9A-F]{5}/ ) {
				$high_su = sprintf( "%X", ( 55232 + int( hex( $output_code ) / 1024 ) ) );
				$high_out    = 'High surrogate: ' . $high_su . '; U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
			} else {
				$high_out = '';
			}

			$length = length( $full_chain );
			if ( $length > 65 ) {
				$length = 65;
				++$overlong;
			}
			$print = '/*' . $full_chain . ( " " x ( 65 - $length ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		if ( $line =~ /^<.+>$/ ) {
			if ( $line eq '<!M>' ) {
				$print = '';
			} else {
				$line       =~ m/(<.+>)(<.+>)/;
				$deadkey    = $1;
				$input      = $2;
				$deadchar   = get_multikey_dead_character( $deadkey );
				$input      =~ s/<(.+)>/$input/;
				$input      = dekeysym( $input );
				$print      = '/*' . $line . ( " " x ( 65 - length( $line ) ) )
				               . "*/ DEADTRANS( " . format_character( $input ) . "\t," . format_character( $deadchar )
				               . "\t," . format_character( get_multikey_dead_character( $line ) ) . "\t,0x0001), // Multikey chain\n";
			}
		} else {
			++$multichar;
			$print = '';
		}
	}
	push( @multikey_print, $print );
}
print( "Processing the dedicated multikey output complete.\n" );
print CONSOLE ( "Processing the dedicated multikey output complete.\n" );

print MULTIKEY @multikey_print;

#
# Output multikey in 2 files is required because a single file exceeds the 2MB
# file size limit of github.com (not github.dev).
#
# Wrapping this code in a subroutine to comply with the D.R.Y. principle gets
# perl 5, version 38, subversion 0 (v5.38.0) built for MSWin32-x64-multi-thread
# to crash the computer.
#
# Process single-character dead key multikey equivalent output without multicharacter input.
print( "Processing the dead key multikey equivalent output in progress ---\n" );
print CONSOLE ( "Processing the dead key multikey equivalent output in progress ---\n" );
foreach my $line ( @mk_equiv_out ) {
	if ( $line =~ /" U[0-9A-F]{4,5}/ ) { # Single-character output.
		unless ( $line =~ /<UEF/ ) {       # Multicharacter input.
			$line          =~ m/((<.+>)(<.+>)) : "(.)" U([0-9A-F]{4,5}) # (.+)/u;
			$full_chain    = $1;
			$deadkey       = $2;
			$input         = $3;
			$output_string = $4;
			$output_code   = $5;
			$comment       = $6;

			if ( $deadkey eq '<!M>' ) {
				$deadchar = '00A6';
			} else {
				$deadchar = get_multikey_dead_character( $deadkey );
			}

			$input = get_multikey_dead_character( $input );
			$input =~ s/<(.+)>/$1/;
			$input =~ s/U([0-9A-F]{4})/$1/;
			$input = dekeysym( $input );

			if ( $input =~ /[0-9A-F]{4}/ ) {
				$input_string = chr( hex( $input ) );
			} else {
				$input_string = $input;
				$input_string =~ s/\\?(.)/$1/;
				if ( $input_string =~ /^"$/ ) {
					$delim = "'";
				}
			}

			if ( $output_code =~ /[0-9A-F]{5}/ ) {
				$high_su = sprintf( "%X", ( 55232 + int( hex( $output_code ) / 1024 ) ) );
				$high_out    = 'High surrogate: ' . $high_su . '; U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
			} else {
				$high_out = '';
			}

			$length = length( $full_chain );
			if ( $length > 65 ) {
				$length = 65;
				++$overlong;
			}
			$print = '/*' . $full_chain . ( " " x ( 65 - $length ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		if ( $line =~ /^<.+>$/ ) {
			$line       =~ m/((<.+>)(<.+>))/;
			$full_chain = $1;
			$deadkey    = $2;
			$input      = $3;
			$deadchar   = get_multikey_dead_character( $deadkey );
			$input      =~ s/<(.+)>/$input/;
			$input      = dekeysym( $input );
			$print      = '/*' . $line . ( " " x ( 65 - length( $line ) ) )
			               . "*/ DEADTRANS( " . format_character( $input ) . "\t," . format_character( $deadchar )
			               . "\t," . format_character( get_multikey_dead_character( $line ) ) . "\t,0x0001), // Multikey chain\n";
		} else {
			++$multichar;
			$print = '';
		}
	}
	push( @mk_equiv_print, $print );
}
print( "Processing the dead key multikey equivalent output complete.\n" );
print CONSOLE ( "Processing the dead key multikey equivalent output complete.\n" );

print EQUIVALENTS @mk_equiv_print;

# Print report to a file.
print( "Printing the reports in progress ---\n" );
print CONSOLE ( "Printing the reports in progress ---\n" );
if ( @unsupported == 0 ) {
	print REPORT ( "There are no unsupported chains.\n\n" );
} elsif ( @unsupported == 1 ) {
	print REPORT ( "There is one unsupported chain to transpile:\n\n" );
} else {
	@unsupported = sort( @unsupported );
	print REPORT ( "This is the full list of " . @unsupported . " unsupported chains to transpile.\n\n" );
}
print REPORT join( "\n", @unsupported );

if ( @bad_format == 0 ) {
	print REPORT ( "\n\n\nThere are no characters in a bad format.\n\n" );
} elsif ( @bad_format == 1 ) {
	print REPORT ( "\n\n\nThere is one character in a bad format:\n\n" );
} else {
	@bad_format = sort( @bad_format );
	print REPORT ( "\n\n\nThis is the full list of " . @bad_format . " characters in a bad format.\n\n" );
}
print REPORT join( "\n", @bad_format );

print REPORT ( "\n\n\nThis is the list of " . @multikey_dchars . " multikey chains with their dead character:\n\n" );
print REPORT join( "\n", @multikey_dchars );
print( "Printing the reports complete.\n" );
print CONSOLE ( "Printing the reports complete.\n" );

close( INPUT );
print( "Closed file $input_path.\n" );
print CONSOLE ( "Closed file $input_path.\n" );
close( DEADKEYS );
print( "Closed file $deadkey_path.\n" );
print CONSOLE ( "Closed file $deadkey_path.\n" );
close( EQUIVALENTS );
print( "Closed file $equivalents_path.\n" );
print CONSOLE ( "Closed file $equivalents_path.\n" );
close( MULTIKEY );
print( "Closed file $multikey_path.\n" );
print CONSOLE ( "Closed file $multikey_path.\n" );
close( LOG );
print( "Closed file $log_path.\n" );
print CONSOLE ( "Closed file $log_path.\n" );
close( REPORT );
print( "Closed file $report_path.\n\n" );
print CONSOLE ( "Closed file $report_path.\n\n" );
unless ( @bad_format == 0 ) {
	if ( @bad_format == 1 ) {
		print( '  ' . @bad_format . " character is in a bad format: @bad_format.\n" );
		print CONSOLE ( '  ' . @bad_format . " character is in a bad format: @bad_format.\n" );
	} else {
		print( '  ' . @bad_format . " characters are in a bad format: @bad_format.\n" );
		print CONSOLE ( '  ' . @bad_format . " characters are in a bad format: @bad_format.\n" );
	}
	print( "  This enumeration is appended as a list in $report_path.\n\n" );
	print CONSOLE ( "  This enumeration is appended as a list in $report_path.\n\n" );
}
@high_surrogates = sort( @high_surrogates );
print( "  $full fully functional dead key sequences in $deadkey_path.\n" );
print CONSOLE ( "  $full fully functional dead key sequences in $deadkey_path.\n" );
print( "  $half other sequences in the same file output only a low surrogate.\n" );
print CONSOLE ( "  $half other sequences in the same file output only a low surrogate.\n" );
print( "  The " . @high_surrogates . " required high surrogates are @high_surrogates.\n" );
print CONSOLE ( "  The " . @high_surrogates . " required high surrogates are @high_surrogates.\n" );
print( "  Their relationship to the dead keys is logged in $log_path.\n" );
print CONSOLE ( "  Their relationship to the dead keys is logged in $log_path.\n" );
print( "  $multichar unsupported multicharacter input/output dead key sequences not processed.\n" );
print CONSOLE ( "  $multichar unsupported multicharacter input/output dead key sequences not processed.\n" );
print( '  ' . @multikey_print . " potential multikey-only sequences in $multikey_path.\n" );
print CONSOLE ( '  ' . @multikey_print . " potential multikey-only sequences in $multikey_path.\n" );
print( '  ' . @mk_equiv_print . " dead key multikey equivalent sequences in $equivalents_path.\n" );
print CONSOLE ( '  ' . @mk_equiv_print . " dead key multikey equivalent sequences in $equivalents_path.\n" );
unless ( @unsupported == 0 ) {
	if ( @unsupported == 1 ) {
		print( "  The unsupported chain is listed in $report_path.\n" );
		print CONSOLE ( "  The unsupported chain is listed in $report_path.\n" );
	} else {
		print( "  The " . @unsupported . " unsupported chains are listed in $report_path.\n" );
		print CONSOLE ( "  The " . @unsupported . " unsupported chains are listed in $report_path.\n" );
	}
}
unless ( $overlong == 0 ) {
	if ( $overlong == 1 ) {
		print( "  $overlong multikey chain ID is overlong and is disturbing the source code layout.\n" );
		print CONSOLE ( "  $overlong multikey chain ID is overlong and is disturbing the source code layout.\n" );
	} else {
		print( "  $overlong multikey chain IDs are overlong and are disturbing the source code layout.\n" );
		print CONSOLE ( "  $overlong multikey chain IDs are overlong and are disturbing the source code layout.\n" );
	}
}
print( "  This terminal output is logged in $console_log_path.\n" );
print CONSOLE ( "  This terminal output is logged in $console_log_path.\n" );
print( "\nDone processing.\n" );
print CONSOLE ( "\nDone processing.\n" );
print( "Closing file $console_log_path.\n" );
print CONSOLE ( "Closing file $console_log_path.\n" );
close( CONSOLE );

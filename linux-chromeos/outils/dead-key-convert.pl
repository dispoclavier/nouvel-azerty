#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-10-23T2145+0200
# 2025-11-15T0554+0100
# 2025-12-23T0450+0100
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
#
# Dead key chains
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
#
# Multikey
#
# Multikey sequences need to be processed separately. These are unrelated to,
# or not congruent with, the dead key output, as about 100 multikey equivalents
# are commented out due to conflicts.
#
# Multikey equivalents of dead keys cannot be supported on Windows because that
# bloats the layout drivers, that are then prone to crashing the keyboard. That
# notwithstanding, there are ways to support more intermediate chains, as the
# first private use area E000..F8FF encompassing 6400 code points is not used
# up by dedicated multikey sequences. On 2025-12-22, a set of 1302 intermediate
# multikey chains used E201..E715.
#
# For test purposes, this part can be toggled here:
my $support_multikey_equivalents = !1;
#
# This is different from dedicated multikey, that is indispensable. After an
# attempt to support all multikey sequences on 2025-11-12, the subset of the
# dedicated multikey sequences is ultimately supported since 2025-12-22.
#
#
# Multicharacter output
#
# On 2025-10-29, 1 097 sequences had multicharacter output. Most are letters
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
#
# SMP characters
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
#
# Programming languages
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
# Warnings about “uninitialized values” are filtered out as they are pointless,
# distracting and unadressable, given that these variables are actually
# initialized and assigned a value.
# By courtesy of https://stackoverflow.com/questions/33341223/suppress-uninitailized-perl-warning
no warnings 'uninitialized';
#
#
# Using old-style file handles.
use strict;
use warnings;
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
my ( $chain, $comment, $deadchar, $deadkey, $full_chain, $high_out, $high_su, $input, $input_string, $length,
		$output_code, $output_string, $preceding, $print, $uplus_output );
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
# This is based on a list of 1302 intermediate multikey
# chains with their dead character output on 2025-12-22.
sub get_multikey_dead_character {
	my ( $multikey ) = @_;

	$multikey =~ s/^<!M>$/00A6/;# The Multikey.

	$multikey =~ s/^<!M><%ampersand>$/E201/;
	$multikey =~ s/^<!M><%ampersand><%apostrophe>$/E202/;
	$multikey =~ s/^<!M><%ampersand><%aprightsingquotmark>$/E203/;
	$multikey =~ s/^<!M><%ampersand><%bar>$/E204/;
	$multikey =~ s/^<!M><%ampersand><%less>$/E205/;
	$multikey =~ s/^<!M><%ampersand><%less><%minus>$/E206/;
	$multikey =~ s/^<!M><%ampersand><%minus>$/E207/;
	$multikey =~ s/^<!M><%ampersand><%period>$/E208/;
	$multikey =~ s/^<!M><%ampersand><%period><%period>$/E209/;
	$multikey =~ s/^<!M><%ampersand><%period><%period><%period>$/E20A/;
	$multikey =~ s/^<!M><%ampersand><%underscore>$/E20B/;
	$multikey =~ s/^<!M><%ampersand><a>$/E20C/;
	$multikey =~ s/^<!M><%ampersand><o>$/E20D/;
	$multikey =~ s/^<!M><%ampersand><o><%greater>$/E20E/;
	$multikey =~ s/^<!M><%ampersand><u>$/E20F/;
	$multikey =~ s/^<!M><%apostrophe>$/E210/;
	$multikey =~ s/^<!M><%apostrophe><%equal>$/E211/;
	$multikey =~ s/^<!M><%apostrophe><%exclam>$/E212/;
	$multikey =~ s/^<!M><%apostrophe><%exclam><%grave>$/E213/;
	$multikey =~ s/^<!M><%apostrophe><%minus>$/E214/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%grave>$/E215/;
	$multikey =~ s/^<!M><%apostrophe><%minus><%minus>$/E216/;
	$multikey =~ s/^<!M><%apostrophe><%parenleft>$/E217/;
	$multikey =~ s/^<!M><%aprightsingquotmark>$/E218/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%equal>$/E219/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam>$/E21A/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%exclam><%grave>$/E21B/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus>$/E21C/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%grave>$/E21D/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%minus><%minus>$/E21E/;
	$multikey =~ s/^<!M><%aprightsingquotmark><%parenleft>$/E21F/;
	$multikey =~ s/^<!M><%asterisk>$/E220/;
	$multikey =~ s/^<!M><%backslash>$/E221/;
	$multikey =~ s/^<!M><%backslash><%backslash>$/E222/;
	$multikey =~ s/^<!M><%backslash><%backslash><%slash>$/E223/;
	$multikey =~ s/^<!M><%backslash><%bar>$/E224/;
	$multikey =~ s/^<!M><%backslash><%greater>$/E225/;
	$multikey =~ s/^<!M><%backslash><%greater><%parenright>$/E226/;
	$multikey =~ s/^<!M><%backslash><%hash>$/E227/;
	$multikey =~ s/^<!M><%backslash><%minus>$/E228/;
	$multikey =~ s/^<!M><%backslash><%parenleft>$/E229/;
	$multikey =~ s/^<!M><%backslash><%parenright>$/E22A/;
	$multikey =~ s/^<!M><%backslash><%slash>$/E22B/;
	$multikey =~ s/^<!M><%backslash><%slash><%underscore>$/E22C/;
	$multikey =~ s/^<!M><%backslash><%underscore>$/E22D/;
	$multikey =~ s/^<!M><%bar>$/E22E/;
	$multikey =~ s/^<!M><%bar><%apostrophe>$/E22F/;
	$multikey =~ s/^<!M><%bar><%aprightsingquotmark>$/E230/;
	$multikey =~ s/^<!M><%bar><%backslash>$/E231/;
	$multikey =~ s/^<!M><%bar><%backslash><%slash>$/E232/;
	$multikey =~ s/^<!M><%bar><%bar>$/E233/;
	$multikey =~ s/^<!M><%bar><%bar><%bar>$/E234/;
	$multikey =~ s/^<!M><%bar><%bar><%equal>$/E235/;
	$multikey =~ s/^<!M><%bar><%bar><%minus>$/E236/;
	$multikey =~ s/^<!M><%bar><%equal>$/E237/;
	$multikey =~ s/^<!M><%bar><%equal><%equal>$/E238/;
	$multikey =~ s/^<!M><%bar><%exclam>$/E239/;
	$multikey =~ s/^<!M><%bar><%grave>$/E23A/;
	$multikey =~ s/^<!M><%bar><%greater>$/E23B/;
	$multikey =~ s/^<!M><%bar><%greater><%slash>$/E23C/;
	$multikey =~ s/^<!M><%bar><%greater><%underscore>$/E23D/;
	$multikey =~ s/^<!M><%bar><%hash>$/E23E/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash>$/E23F/;
	$multikey =~ s/^<!M><%bar><%hash><%backslash><%slash>$/E240/;
	$multikey =~ s/^<!M><%bar><%hash><%slash>$/E241/;
	$multikey =~ s/^<!M><%bar><%hash><%slash><%backslash>$/E242/;
	$multikey =~ s/^<!M><%bar><%hash><%underscore>$/E243/;
	$multikey =~ s/^<!M><%bar><%less>$/E244/;
	$multikey =~ s/^<!M><%bar><%minus>$/E245/;
	$multikey =~ s/^<!M><%bar><%minus><%bar>$/E246/;
	$multikey =~ s/^<!M><%bar><%minus><%greater>$/E247/;
	$multikey =~ s/^<!M><%bar><%minus><%minus>$/E248/;
	$multikey =~ s/^<!M><%bar><%minus><%minus><%minus>$/E249/;
	$multikey =~ s/^<!M><%bar><%parenright>$/E24A/;
	$multikey =~ s/^<!M><%bar><%period>$/E24B/;
	$multikey =~ s/^<!M><%bar><%slash>$/E24C/;
	$multikey =~ s/^<!M><%bar><%slash><%backslash>$/E24D/;
	$multikey =~ s/^<!M><%bar><%tilde>$/E24E/;
	$multikey =~ s/^<!M><%bar><%underscore>$/E24F/;
	$multikey =~ s/^<!M><%bracketleft>$/E250/;
	$multikey =~ s/^<!M><%bracketleft><%apostrophe>$/E251/;
	$multikey =~ s/^<!M><%bracketleft><%backslash>$/E252/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%colon>$/E253/;
	$multikey =~ s/^<!M><%bracketleft><%backslash><%minus>$/E254/;
	$multikey =~ s/^<!M><%bracketleft><%bar>$/E255/;
	$multikey =~ s/^<!M><%bracketleft><%bracketleft>$/E256/;
	$multikey =~ s/^<!M><%bracketleft><%bracketright>$/E257/;
	$multikey =~ s/^<!M><%bracketleft><%hash>$/E258/;
	$multikey =~ s/^<!M><%bracketleft><%hash><%bracketright>$/E259/;
	$multikey =~ s/^<!M><%bracketleft><%minus>$/E25A/;
	$multikey =~ s/^<!M><%bracketleft><%minus><%backslash>$/E25B/;
	$multikey =~ s/^<!M><%bracketleft><%slash>$/E25C/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%colon>$/E25D/;
	$multikey =~ s/^<!M><%bracketleft><%slash><%minus>$/E25E/;
	$multikey =~ s/^<!M><%bracketleft><%underscore>$/E25F/;
	$multikey =~ s/^<!M><%bracketleft><V>$/E260/;
	$multikey =~ s/^<!M><%bracketleft><v>$/E261/;
	$multikey =~ s/^<!M><%bracketleft><X>$/E262/;
	$multikey =~ s/^<!M><%bracketleft><X><L>$/E263/;
	$multikey =~ s/^<!M><%bracketright>$/E264/;
	$multikey =~ s/^<!M><%bracketright><%backslash>$/E265/;
	$multikey =~ s/^<!M><%bracketright><%backslash><%slash>$/E266/;
	$multikey =~ s/^<!M><%bracketright><%bracketleft>$/E267/;
	$multikey =~ s/^<!M><%bracketright><%bracketright>$/E268/;
	$multikey =~ s/^<!M><%bracketright><%parenright>$/E269/;
	$multikey =~ s/^<!M><%bracketright><%slash>$/E26A/;
	$multikey =~ s/^<!M><%bracketright><%slash><%backslash>$/E26B/;
	$multikey =~ s/^<!M><%circum>$/E26C/;
	$multikey =~ s/^<!M><%circum><%ampersand>$/E26D/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft>$/E26E/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceleft><%braceleft>$/E26F/;
	$multikey =~ s/^<!M><%circum><%ampersand><%braceright>$/E270/;
	$multikey =~ s/^<!M><%circum><%ampersand><A>$/E271/;
	$multikey =~ s/^<!M><%circum><%ampersand><d>$/E272/;
	$multikey =~ s/^<!M><%circum><%ampersand><f>$/E273/;
	$multikey =~ s/^<!M><%circum><%ampersand><l>$/E274/;
	$multikey =~ s/^<!M><%circum><%ampersand><t>$/E275/;
	$multikey =~ s/^<!M><%circum><%hash>$/E276/;
	$multikey =~ s/^<!M><%circum><%tilde>$/E277/;
	$multikey =~ s/^<!M><%colon>$/E278/;
	$multikey =~ s/^<!M><%colon><%colon>$/E279/;
	$multikey =~ s/^<!M><%colon><%colon><%equal>$/E27A/;
	$multikey =~ s/^<!M><%colon><%minus>$/E27B/;
	$multikey =~ s/^<!M><%comma>$/E27C/;
	$multikey =~ s/^<!M><%equal>$/E27D/;
	$multikey =~ s/^<!M><%equal><%apostrophe>$/E27E/;
	$multikey =~ s/^<!M><%equal><%aprightsingquotmark>$/E27F/;
	$multikey =~ s/^<!M><%equal><%bar>$/E280/;
	$multikey =~ s/^<!M><%equal><%bar><%bar>$/E281/;
	$multikey =~ s/^<!M><%equal><%equal>$/E282/;
	$multikey =~ s/^<!M><%equal><%equal><%equal>$/E283/;
	$multikey =~ s/^<!M><%equal><%greater>$/E284/;
	$multikey =~ s/^<!M><%equal><%less>$/E285/;
	$multikey =~ s/^<!M><%equal><%minus>$/E286/;
	$multikey =~ s/^<!M><%equal><%minus><%bar>$/E287/;
	$multikey =~ s/^<!M><%equal><%minus><%bar><%bar>$/E288/;
	$multikey =~ s/^<!M><%equal><%minus><%slash>$/E289/;
	$multikey =~ s/^<!M><%equal><%slash>$/E28A/;
	$multikey =~ s/^<!M><%exclam>$/E28B/;
	$multikey =~ s/^<!M><%exclam><%apostrophe>$/E28C/;
	$multikey =~ s/^<!M><%exclam><%aprightsingquotmark>$/E28D/;
	$multikey =~ s/^<!M><%exclam><%bar>$/E28E/;
	$multikey =~ s/^<!M><%exclam><%comma>$/E28F/;
	$multikey =~ s/^<!M><%exclam><%comma><%minus>$/E290/;
	$multikey =~ s/^<!M><%exclam><%exclam>$/E291/;
	$multikey =~ s/^<!M><%exclam><%grave>$/E292/;
	$multikey =~ s/^<!M><%exclam><%grave><%exclam>$/E293/;
	$multikey =~ s/^<!M><%exclam><%greater>$/E294/;
	$multikey =~ s/^<!M><%exclam><%greater><%greater>$/E295/;
	$multikey =~ s/^<!M><%exclam><%minus>$/E296/;
	$multikey =~ s/^<!M><%grave>$/E297/;
	$multikey =~ s/^<!M><%grave><%exclam>$/E298/;
	$multikey =~ s/^<!M><%grave><%minus>$/E299/;
	$multikey =~ s/^<!M><%grave><%minus><%minus>$/E29A/;
	$multikey =~ s/^<!M><%greater>$/E29B/;
	$multikey =~ s/^<!M><%greater><%bar>$/E29C/;
	$multikey =~ s/^<!M><%greater><%bar><%slash>$/E29D/;
	$multikey =~ s/^<!M><%greater><%equal>$/E29E/;
	$multikey =~ s/^<!M><%greater><%greater>$/E29F/;
	$multikey =~ s/^<!M><%greater><%less>$/E2A0/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft>$/E2A1/;
	$multikey =~ s/^<!M><%greater><%less><%parenleft><%parenright>$/E2A2/;
	$multikey =~ s/^<!M><%greater><%less><%parenright>$/E2A3/;
	$multikey =~ s/^<!M><%greater><%less><%parenright><%parenleft>$/E2A4/;
	$multikey =~ s/^<!M><%greater><%minus>$/E2A5/;
	$multikey =~ s/^<!M><%greater><%minus><%bar>$/E2A6/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar>$/E2A7/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%greater>$/E2A8/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus>$/E2A9/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%bar><%minus><%greater>$/E2AA/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%greater>$/E2AB/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus>$/E2AC/;
	$multikey =~ s/^<!M><%greater><%minus><%bar><%minus><%greater>$/E2AD/;
	$multikey =~ s/^<!M><%greater><%minus><%greater>$/E2AE/;
	$multikey =~ s/^<!M><%greater><%parenleft>$/E2AF/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright>$/E2B0/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%equal>$/E2B1/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde>$/E2B2/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%tilde><%tilde>$/E2B3/;
	$multikey =~ s/^<!M><%greater><%parenleft><%parenright><%underscore>$/E2B4/;
	$multikey =~ s/^<!M><%greater><%parenright>$/E2B5/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft>$/E2B6/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%equal>$/E2B7/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde>$/E2B8/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%tilde><%tilde>$/E2B9/;
	$multikey =~ s/^<!M><%greater><%parenright><%parenleft><%underscore>$/E2BA/;
	$multikey =~ s/^<!M><%greater><%period>$/E2BB/;
	$multikey =~ s/^<!M><%greater><%slash>$/E2BC/;
	$multikey =~ s/^<!M><%greater><%tilde>$/E2BD/;
	$multikey =~ s/^<!M><%greater><%tilde><%tilde>$/E2BE/;
	$multikey =~ s/^<!M><%greater><%underscore>$/E2BF/;
	$multikey =~ s/^<!M><%greater><%underscore><%less>$/E2C0/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft>$/E2C1/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenleft><%parenright>$/E2C2/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright>$/E2C3/;
	$multikey =~ s/^<!M><%greater><%underscore><%parenright><%parenleft>$/E2C4/;
	$multikey =~ s/^<!M><%less>$/E2C5/;
	$multikey =~ s/^<!M><%less><%backslash>$/E2C6/;
	$multikey =~ s/^<!M><%less><%backslash><%parenleft>$/E2C7/;
	$multikey =~ s/^<!M><%less><%bar>$/E2C8/;
	$multikey =~ s/^<!M><%less><%bar><%bar>$/E2C9/;
	$multikey =~ s/^<!M><%less><%bar><%bar><%minus>$/E2CA/;
	$multikey =~ s/^<!M><%less><%bar><%minus>$/E2CB/;
	$multikey =~ s/^<!M><%less><%bar><%slash>$/E2CC/;
	$multikey =~ s/^<!M><%less><%bar><%underscore>$/E2CD/;
	$multikey =~ s/^<!M><%less><%bracketleft>$/E2CE/;
	$multikey =~ s/^<!M><%less><%bracketright>$/E2CF/;
	$multikey =~ s/^<!M><%less><%equal>$/E2D0/;
	$multikey =~ s/^<!M><%less><%equal><%bar>$/E2D1/;
	$multikey =~ s/^<!M><%less><%equal><%bar><%equal>$/E2D2/;
	$multikey =~ s/^<!M><%less><%equal><%equal>$/E2D3/;
	$multikey =~ s/^<!M><%less><%equal><%slash>$/E2D4/;
	$multikey =~ s/^<!M><%less><%exclam>$/E2D5/;
	$multikey =~ s/^<!M><%less><%exclam><%bar>$/E2D6/;
	$multikey =~ s/^<!M><%less><%exclam><%greater>$/E2D7/;
	$multikey =~ s/^<!M><%less><%exclam><%less>$/E2D8/;
	$multikey =~ s/^<!M><%less><%greater>$/E2D9/;
	$multikey =~ s/^<!M><%less><%greater><%less>$/E2DA/;
	$multikey =~ s/^<!M><%less><%greater><%less><%minus>$/E2DB/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft>$/E2DC/;
	$multikey =~ s/^<!M><%less><%greater><%parenleft><%parenright>$/E2DD/;
	$multikey =~ s/^<!M><%less><%greater><%parenright>$/E2DE/;
	$multikey =~ s/^<!M><%less><%greater><%parenright><%parenleft>$/E2DF/;
	$multikey =~ s/^<!M><%less><%hash>$/E2E0/;
	$multikey =~ s/^<!M><%less><%hash><%greater>$/E2E1/;
	$multikey =~ s/^<!M><%less><%less>$/E2E2/;
	$multikey =~ s/^<!M><%less><%less><%bar>$/E2E3/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar>$/E2E4/;
	$multikey =~ s/^<!M><%less><%less><%bar><%bar><%minus>$/E2E5/;
	$multikey =~ s/^<!M><%less><%less><%bar><%minus>$/E2E6/;
	$multikey =~ s/^<!M><%less><%less><%exclam>$/E2E7/;
	$multikey =~ s/^<!M><%less><%less><%minus>$/E2E8/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar>$/E2E9/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar>$/E2EA/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%bar><%minus>$/E2EB/;
	$multikey =~ s/^<!M><%less><%less><%minus><%bar><%minus>$/E2EC/;
	$multikey =~ s/^<!M><%less><%minus>$/E2ED/;
	$multikey =~ s/^<!M><%less><%minus><%bar>$/E2EE/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar>$/E2EF/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%bar><%minus>$/E2F0/;
	$multikey =~ s/^<!M><%less><%minus><%bar><%minus>$/E2F1/;
	$multikey =~ s/^<!M><%less><%minus><%comma>$/E2F2/;
	$multikey =~ s/^<!M><%less><%minus><%less>$/E2F3/;
	$multikey =~ s/^<!M><%less><%minus><%less><%minus>$/E2F4/;
	$multikey =~ s/^<!M><%less><%minus><%minus>$/E2F5/;
	$multikey =~ s/^<!M><%less><%minus><%slash>$/E2F6/;
	$multikey =~ s/^<!M><%less><%minus><%tilde>$/E2F7/;
	$multikey =~ s/^<!M><%less><%minus><%tilde><%tilde>$/E2F8/;
	$multikey =~ s/^<!M><%less><%minus><0>$/E2F9/;
	$multikey =~ s/^<!M><%less><%minus><0><%minus>$/E2FA/;
	$multikey =~ s/^<!M><%less><%minus><o>$/E2FB/;
	$multikey =~ s/^<!M><%less><%minus><O>$/E2FC/;
	$multikey =~ s/^<!M><%less><%minus><o><%minus>$/E2FD/;
	$multikey =~ s/^<!M><%less><%parenleft>$/E2FE/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright>$/E2FF/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%equal>$/E300/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde>$/E301/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%tilde><%tilde>$/E302/;
	$multikey =~ s/^<!M><%less><%parenleft><%parenright><%underscore>$/E303/;
	$multikey =~ s/^<!M><%less><%parenright>$/E304/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft>$/E305/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%equal>$/E306/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde>$/E307/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%tilde><%tilde>$/E308/;
	$multikey =~ s/^<!M><%less><%parenright><%parenleft><%underscore>$/E309/;
	$multikey =~ s/^<!M><%less><%period>$/E30A/;
	$multikey =~ s/^<!M><%less><%slash>$/E30B/;
	$multikey =~ s/^<!M><%less><%tilde>$/E30C/;
	$multikey =~ s/^<!M><%less><%tilde><%tilde>$/E30D/;
	$multikey =~ s/^<!M><%less><%underscore>$/E30E/;
	$multikey =~ s/^<!M><%less><%underscore><%greater>$/E30F/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft>$/E310/;
	$multikey =~ s/^<!M><%less><%underscore><%parenleft><%parenright>$/E311/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright>$/E312/;
	$multikey =~ s/^<!M><%less><%underscore><%parenright><%parenleft>$/E313/;
	$multikey =~ s/^<!M><%minus>$/E314/;
	$multikey =~ s/^<!M><%minus><%apostrophe>$/E315/;
	$multikey =~ s/^<!M><%minus><%aprightsingquotmark>$/E316/;
	$multikey =~ s/^<!M><%minus><%backslash>$/E317/;
	$multikey =~ s/^<!M><%minus><%bar>$/E318/;
	$multikey =~ s/^<!M><%minus><%bar><%bar>$/E319/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%greater>$/E31A/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus>$/E31B/;
	$multikey =~ s/^<!M><%minus><%bar><%bar><%minus><%greater>$/E31C/;
	$multikey =~ s/^<!M><%minus><%bar><%greater>$/E31D/;
	$multikey =~ s/^<!M><%minus><%bar><%minus>$/E31E/;
	$multikey =~ s/^<!M><%minus><%bar><%minus><%greater>$/E31F/;
	$multikey =~ s/^<!M><%minus><%circum>$/E320/;
	$multikey =~ s/^<!M><%minus><%comma>$/E321/;
	$multikey =~ s/^<!M><%minus><%comma><%exclam>$/E322/;
	$multikey =~ s/^<!M><%minus><%comma><%less>$/E323/;
	$multikey =~ s/^<!M><%minus><%equal>$/E324/;
	$multikey =~ s/^<!M><%minus><%equal><%bar>$/E325/;
	$multikey =~ s/^<!M><%minus><%equal><%bar><%bar>$/E326/;
	$multikey =~ s/^<!M><%minus><%equal><%slash>$/E327/;
	$multikey =~ s/^<!M><%minus><%grave>$/E328/;
	$multikey =~ s/^<!M><%minus><%grave><%grave>$/E329/;
	$multikey =~ s/^<!M><%minus><%grave><%grave><%minus>$/E32A/;
	$multikey =~ s/^<!M><%minus><%grave><%minus>$/E32B/;
	$multikey =~ s/^<!M><%minus><%greater>$/E32C/;
	$multikey =~ s/^<!M><%minus><%greater><%greater>$/E32D/;
	$multikey =~ s/^<!M><%minus><%greater><%less>$/E32E/;
	$multikey =~ s/^<!M><%minus><%greater><%minus>$/E32F/;
	$multikey =~ s/^<!M><%minus><%greater><%minus><%greater>$/E330/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde>$/E331/;
	$multikey =~ s/^<!M><%minus><%greater><%tilde><%tilde>$/E332/;
	$multikey =~ s/^<!M><%minus><%less>$/E333/;
	$multikey =~ s/^<!M><%minus><%minus>$/E334/;
	$multikey =~ s/^<!M><%minus><%minus><%grave>$/E335/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave>$/E336/;
	$multikey =~ s/^<!M><%minus><%minus><%grave><%grave><%minus>$/E337/;
	$multikey =~ s/^<!M><%minus><%minus><%greater>$/E338/;
	$multikey =~ s/^<!M><%minus><%minus><%minus>$/E339/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave>$/E33A/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave>$/E33B/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%grave><%grave><%minus>$/E33C/;
	$multikey =~ s/^<!M><%minus><%minus><%minus><%greater>$/E33D/;
	$multikey =~ s/^<!M><%minus><%minus><v>$/E33E/;
	$multikey =~ s/^<!M><%minus><%minus><V>$/E33F/;
	$multikey =~ s/^<!M><%minus><%parenleft>$/E340/;
	$multikey =~ s/^<!M><%minus><%parenright>$/E341/;
	$multikey =~ s/^<!M><%minus><%parenright><%slash>$/E342/;
	$multikey =~ s/^<!M><%minus><%period>$/E343/;
	$multikey =~ s/^<!M><%minus><%slash>$/E344/;
	$multikey =~ s/^<!M><%minus><%underscore>$/E345/;
	$multikey =~ s/^<!M><%minus><0>$/E346/;
	$multikey =~ s/^<!M><%minus><0><%minus>$/E347/;
	$multikey =~ s/^<!M><%minus><0><%minus><0>$/E348/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus>$/E349/;
	$multikey =~ s/^<!M><%minus><0><%minus><0><%minus><%greater>$/E34A/;
	$multikey =~ s/^<!M><%minus><x>$/E34B/;
	$multikey =~ s/^<!M><%parenleft>$/E34C/;
	$multikey =~ s/^<!M><%parenleft><%greater>$/E34D/;
	$multikey =~ s/^<!M><%parenleft><%less>$/E34E/;
	$multikey =~ s/^<!M><%parenleft><%minus>$/E34F/;
	$multikey =~ s/^<!M><%parenleft><%parenleft>$/E350/;
	$multikey =~ s/^<!M><%parenleft><%parenright>$/E351/;
	$multikey =~ s/^<!M><%parenleft><%underscore>$/E352/;
	$multikey =~ s/^<!M><%parenleft><0>$/E353/;
	$multikey =~ s/^<!M><%parenleft><0><0>$/E354/;
	$multikey =~ s/^<!M><%parenleft><0><0><1>$/E355/;
	$multikey =~ s/^<!M><%parenleft><0><1>$/E356/;
	$multikey =~ s/^<!M><%parenleft><0><1><1>$/E357/;
	$multikey =~ s/^<!M><%parenleft><1>$/E358/;
	$multikey =~ s/^<!M><%parenleft><1><0>$/E359/;
	$multikey =~ s/^<!M><%parenleft><1><0><0>$/E35A/;
	$multikey =~ s/^<!M><%parenleft><1><1>$/E35B/;
	$multikey =~ s/^<!M><%parenleft><1><1><0>$/E35C/;
	$multikey =~ s/^<!M><%parenleft><2>$/E35D/;
	$multikey =~ s/^<!M><%parenleft><3>$/E35E/;
	$multikey =~ s/^<!M><%parenleft><4>$/E35F/;
	$multikey =~ s/^<!M><%parenleft><5>$/E360/;
	$multikey =~ s/^<!M><%parenright>$/E361/;
	$multikey =~ s/^<!M><%parenright><%bracketright>$/E362/;
	$multikey =~ s/^<!M><%parenright><%circum>$/E363/;
	$multikey =~ s/^<!M><%parenright><%less>$/E364/;
	$multikey =~ s/^<!M><%parenright><%parenleft>$/E365/;
	$multikey =~ s/^<!M><%parenright><%parenright>$/E366/;
	$multikey =~ s/^<!M><%parenright><%underscore>$/E367/;
	$multikey =~ s/^<!M><%parenright><%underscore><%circum>$/E368/;
	$multikey =~ s/^<!M><%parenright><0>$/E369/;
	$multikey =~ s/^<!M><%parenright><0><0>$/E36A/;
	$multikey =~ s/^<!M><%parenright><0><0><0>$/E36B/;
	$multikey =~ s/^<!M><%parenright><0><0><1>$/E36C/;
	$multikey =~ s/^<!M><%parenright><0><0><2>$/E36D/;
	$multikey =~ s/^<!M><%parenright><0><0><3>$/E36E/;
	$multikey =~ s/^<!M><%parenright><0><1>$/E36F/;
	$multikey =~ s/^<!M><%parenright><0><1><0>$/E370/;
	$multikey =~ s/^<!M><%parenright><0><1><1>$/E371/;
	$multikey =~ s/^<!M><%parenright><0><1><2>$/E372/;
	$multikey =~ s/^<!M><%parenright><0><1><3>$/E373/;
	$multikey =~ s/^<!M><%parenright><0><2>$/E374/;
	$multikey =~ s/^<!M><%parenright><0><2><0>$/E375/;
	$multikey =~ s/^<!M><%parenright><0><2><1>$/E376/;
	$multikey =~ s/^<!M><%parenright><0><2><2>$/E377/;
	$multikey =~ s/^<!M><%parenright><0><3>$/E378/;
	$multikey =~ s/^<!M><%parenright><0><3><0>$/E379/;
	$multikey =~ s/^<!M><%parenright><0><3><1>$/E37A/;
	$multikey =~ s/^<!M><%parenright><0><3><3>$/E37B/;
	$multikey =~ s/^<!M><%parenright><1>$/E37C/;
	$multikey =~ s/^<!M><%parenright><1><0>$/E37D/;
	$multikey =~ s/^<!M><%parenright><1><0><0>$/E37E/;
	$multikey =~ s/^<!M><%parenright><1><0><1>$/E37F/;
	$multikey =~ s/^<!M><%parenright><1><0><3>$/E380/;
	$multikey =~ s/^<!M><%parenright><1><1>$/E381/;
	$multikey =~ s/^<!M><%parenright><1><1><0>$/E382/;
	$multikey =~ s/^<!M><%parenright><1><1><1>$/E383/;
	$multikey =~ s/^<!M><%parenright><1><1><3>$/E384/;
	$multikey =~ s/^<!M><%parenright><1><2>$/E385/;
	$multikey =~ s/^<!M><%parenright><1><2><0>$/E386/;
	$multikey =~ s/^<!M><%parenright><1><2><1>$/E387/;
	$multikey =~ s/^<!M><%parenright><1><3>$/E388/;
	$multikey =~ s/^<!M><%parenright><1><3><0>$/E389/;
	$multikey =~ s/^<!M><%parenright><1><3><1>$/E38A/;
	$multikey =~ s/^<!M><%parenright><1><3><3>$/E38B/;
	$multikey =~ s/^<!M><%parenright><2>$/E38C/;
	$multikey =~ s/^<!M><%parenright><2><0>$/E38D/;
	$multikey =~ s/^<!M><%parenright><2><0><0>$/E38E/;
	$multikey =~ s/^<!M><%parenright><2><0><2>$/E38F/;
	$multikey =~ s/^<!M><%parenright><2><1>$/E390/;
	$multikey =~ s/^<!M><%parenright><2><1><0>$/E391/;
	$multikey =~ s/^<!M><%parenright><2><1><2>$/E392/;
	$multikey =~ s/^<!M><%parenright><2><2>$/E393/;
	$multikey =~ s/^<!M><%parenright><2><2><0>$/E394/;
	$multikey =~ s/^<!M><%parenright><2><2><2>$/E395/;
	$multikey =~ s/^<!M><%parenright><3>$/E396/;
	$multikey =~ s/^<!M><%parenright><3><0>$/E397/;
	$multikey =~ s/^<!M><%parenright><3><0><0>$/E398/;
	$multikey =~ s/^<!M><%parenright><3><0><1>$/E399/;
	$multikey =~ s/^<!M><%parenright><3><0><3>$/E39A/;
	$multikey =~ s/^<!M><%parenright><3><1>$/E39B/;
	$multikey =~ s/^<!M><%parenright><3><1><0>$/E39C/;
	$multikey =~ s/^<!M><%parenright><3><1><1>$/E39D/;
	$multikey =~ s/^<!M><%parenright><3><1><3>$/E39E/;
	$multikey =~ s/^<!M><%parenright><3><3>$/E39F/;
	$multikey =~ s/^<!M><%parenright><3><3><0>$/E3A0/;
	$multikey =~ s/^<!M><%parenright><3><3><1>$/E3A1/;
	$multikey =~ s/^<!M><%parenright><3><3><3>$/E3A2/;
	$multikey =~ s/^<!M><%parenright><4>$/E3A3/;
	$multikey =~ s/^<!M><%parenright><4><4>$/E3A4/;
	$multikey =~ s/^<!M><%period>$/E3A5/;
	$multikey =~ s/^<!M><%period><%equal>$/E3A6/;
	$multikey =~ s/^<!M><%period><%equal><%period>$/E3A7/;
	$multikey =~ s/^<!M><%period><%greater>$/E3A8/;
	$multikey =~ s/^<!M><%period><%minus>$/E3A9/;
	$multikey =~ s/^<!M><%period><%minus><%period>$/E3AA/;
	$multikey =~ s/^<!M><%period><%period>$/E3AB/;
	$multikey =~ s/^<!M><%period><%period><%period>$/E3AC/;
	$multikey =~ s/^<!M><%period><%slash>$/E3AD/;
	$multikey =~ s/^<!M><%period><%tilde>$/E3AE/;
	$multikey =~ s/^<!M><%plus>$/E3AF/;
	$multikey =~ s/^<!M><%plus><%parenleft>$/E3B0/;
	$multikey =~ s/^<!M><%plus><%parenright>$/E3B1/;
	$multikey =~ s/^<!M><%plus><%plus>$/E3B2/;
	$multikey =~ s/^<!M><%plus><%tilde>$/E3B3/;
	$multikey =~ s/^<!M><%question>$/E3B4/;
	$multikey =~ s/^<!M><%slash>$/E3B5/;
	$multikey =~ s/^<!M><%slash><%backslash>$/E3B6/;
	$multikey =~ s/^<!M><%slash><%backslash><%underscore>$/E3B7/;
	$multikey =~ s/^<!M><%slash><%bar>$/E3B8/;
	$multikey =~ s/^<!M><%slash><%greater>$/E3B9/;
	$multikey =~ s/^<!M><%slash><%hash>$/E3BA/;
	$multikey =~ s/^<!M><%slash><%hash><%underscore>$/E3BB/;
	$multikey =~ s/^<!M><%slash><%minus>$/E3BC/;
	$multikey =~ s/^<!M><%slash><%slash>$/E3BD/;
	$multikey =~ s/^<!M><%slash><%slash><%backslash>$/E3BE/;
	$multikey =~ s/^<!M><%slash><%underscore>$/E3BF/;
	$multikey =~ s/^<!M><%slash><%underscore><%backslash>$/E3C0/;
	$multikey =~ s/^<!M><%slash><%underscore><%underscore>$/E3C1/;
	$multikey =~ s/^<!M><%tilde>$/E3C2/;
	$multikey =~ s/^<!M><%tilde><%backslash>$/E3C3/;
	$multikey =~ s/^<!M><%tilde><%backslash><%greater>$/E3C4/;
	$multikey =~ s/^<!M><%tilde><%backslash><%less>$/E3C5/;
	$multikey =~ s/^<!M><%tilde><%bar>$/E3C6/;
	$multikey =~ s/^<!M><%tilde><%greater>$/E3C7/;
	$multikey =~ s/^<!M><%tilde><%hash>$/E3C8/;
	$multikey =~ s/^<!M><%tilde><%less>$/E3C9/;
	$multikey =~ s/^<!M><%tilde><%minus>$/E3CA/;
	$multikey =~ s/^<!M><%tilde><%plus>$/E3CB/;
	$multikey =~ s/^<!M><%tilde><%slash>$/E3CC/;
	$multikey =~ s/^<!M><%tilde><%tilde>$/E3CD/;
	$multikey =~ s/^<!M><%tilde><%tilde><%tilde>$/E3CE/;
	$multikey =~ s/^<!M><%underscore>$/E3CF/;
	$multikey =~ s/^<!M><%underscore><%backslash>$/E3D0/;
	$multikey =~ s/^<!M><%underscore><%backslash><%slash>$/E3D1/;
	$multikey =~ s/^<!M><%underscore><%bar>$/E3D2/;
	$multikey =~ s/^<!M><%underscore><%greater>$/E3D3/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenleft>$/E3D4/;
	$multikey =~ s/^<!M><%underscore><%greater><%parenright>$/E3D5/;
	$multikey =~ s/^<!M><%underscore><%hash>$/E3D6/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash>$/E3D7/;
	$multikey =~ s/^<!M><%underscore><%hash><%backslash><%slash>$/E3D8/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash>$/E3D9/;
	$multikey =~ s/^<!M><%underscore><%hash><%slash><%backslash>$/E3DA/;
	$multikey =~ s/^<!M><%underscore><%less>$/E3DB/;
	$multikey =~ s/^<!M><%underscore><%less><%parenleft>$/E3DC/;
	$multikey =~ s/^<!M><%underscore><%less><%parenright>$/E3DD/;
	$multikey =~ s/^<!M><%underscore><%slash>$/E3DE/;
	$multikey =~ s/^<!M><%underscore><%slash><%backslash>$/E3DF/;
	$multikey =~ s/^<!M><%underscore><%underscore>$/E3E0/;
	$multikey =~ s/^<!M><0>$/E3E1/;
	$multikey =~ s/^<!M><1>$/E3E2/;
	$multikey =~ s/^<!M><1><%slash>$/E3E3/;
	$multikey =~ s/^<!M><2>$/E3E4/;
	$multikey =~ s/^<!M><2><%bracketleft>$/E3E5/;
	$multikey =~ s/^<!M><2><%bracketright>$/E3E6/;
	$multikey =~ s/^<!M><2><%less>$/E3E7/;
	$multikey =~ s/^<!M><2><%slash>$/E3E8/;
	$multikey =~ s/^<!M><2><c>$/E3E9/;
	$multikey =~ s/^<!M><2><n>$/E3EA/;
	$multikey =~ s/^<!M><2><s>$/E3EB/;
	$multikey =~ s/^<!M><2><S>$/E3EC/;
	$multikey =~ s/^<!M><2><T>$/E3ED/;
	$multikey =~ s/^<!M><2><T><%greater>$/E3EE/;
	$multikey =~ s/^<!M><2><T><2>$/E3EF/;
	$multikey =~ s/^<!M><2><T><2><%greater>$/E3F0/;
	$multikey =~ s/^<!M><2><u>$/E3F1/;
	$multikey =~ s/^<!M><2><v>$/E3F2/;
	$multikey =~ s/^<!M><2><V>$/E3F3/;
	$multikey =~ s/^<!M><2><w>$/E3F4/;
	$multikey =~ s/^<!M><3>$/E3F5/;
	$multikey =~ s/^<!M><3><%less>$/E3F6/;
	$multikey =~ s/^<!M><3><%slash>$/E3F7/;
	$multikey =~ s/^<!M><3><s>$/E3F8/;
	$multikey =~ s/^<!M><3><S>$/E3F9/;
	$multikey =~ s/^<!M><4>$/E3FA/;
	$multikey =~ s/^<!M><4><%slash>$/E3FB/;
	$multikey =~ s/^<!M><5>$/E3FC/;
	$multikey =~ s/^<!M><5><%slash>$/E3FD/;
	$multikey =~ s/^<!M><6>$/E3FE/;
	$multikey =~ s/^<!M><7>$/E3FF/;
	$multikey =~ s/^<!M><7><%circum>$/E400/;
	$multikey =~ s/^<!M><7><%slash>$/E401/;
	$multikey =~ s/^<!M><8>$/E402/;
	$multikey =~ s/^<!M><8><x>$/E403/;
	$multikey =~ s/^<!M><8><X>$/E404/;
	$multikey =~ s/^<!M><9>$/E405/;
	$multikey =~ s/^<!M><a>$/E406/;
	$multikey =~ s/^<!M><A>$/E407/;
	$multikey =~ s/^<!M><A><%minus>$/E408/;
	$multikey =~ s/^<!M><a><%minus>$/E409/;
	$multikey =~ s/^<!M><A><%minus><V>$/E40A/;
	$multikey =~ s/^<!M><A><%minus><v>$/E40B/;
	$multikey =~ s/^<!M><a><%minus><v>$/E40C/;
	$multikey =~ s/^<!M><a><%parenleft>$/E40D/;
	$multikey =~ s/^<!M><a><%parenright>$/E40E/;
	$multikey =~ s/^<!M><a><%slash>$/E40F/;
	$multikey =~ s/^<!M><A><E>$/E410/;
	$multikey =~ s/^<!M><a><e>$/E411/;
	$multikey =~ s/^<!M><a><f>$/E412/;
	$multikey =~ s/^<!M><A><F>$/E413/;
	$multikey =~ s/^<!M><a><l>$/E414/;
	$multikey =~ s/^<!M><A><L>$/E415/;
	$multikey =~ s/^<!M><a><m>$/E416/;
	$multikey =~ s/^<!M><A><M>$/E417/;
	$multikey =~ s/^<!M><a><n>$/E418/;
	$multikey =~ s/^<!M><A><N>$/E419/;
	$multikey =~ s/^<!M><a><q>$/E41A/;
	$multikey =~ s/^<!M><a><q><u>$/E41B/;
	$multikey =~ s/^<!M><a><r>$/E41C/;
	$multikey =~ s/^<!M><a><r><i>$/E41D/;
	$multikey =~ s/^<!M><a><w>$/E41E/;
	$multikey =~ s/^<!M><A><W>$/E41F/;
	$multikey =~ s/^<!M><a><z>$/E420/;
	$multikey =~ s/^<!M><A><Z>$/E421/;
	$multikey =~ s/^<!M><b>$/E422/;
	$multikey =~ s/^<!M><B>$/E423/;
	$multikey =~ s/^<!M><b><%apostrophe>$/E424/;
	$multikey =~ s/^<!M><b><%aprightsingquotmark>$/E425/;
	$multikey =~ s/^<!M><b><%bracketleft>$/E426/;
	$multikey =~ s/^<!M><b><%bracketleft><%underscore>$/E427/;
	$multikey =~ s/^<!M><b><%bracketright>$/E428/;
	$multikey =~ s/^<!M><b><%bracketright><%underscore>$/E429/;
	$multikey =~ s/^<!M><b><%equal>$/E42A/;
	$multikey =~ s/^<!M><b><%minus>$/E42B/;
	$multikey =~ s/^<!M><b><%slash>$/E42C/;
	$multikey =~ s/^<!M><b><%tilde>$/E42D/;
	$multikey =~ s/^<!M><b><%underscore>$/E42E/;
	$multikey =~ s/^<!M><b><a>$/E42F/;
	$multikey =~ s/^<!M><b><a><l>$/E430/;
	$multikey =~ s/^<!M><b><d>$/E431/;
	$multikey =~ s/^<!M><B><D>$/E432/;
	$multikey =~ s/^<!M><b><e>$/E433/;
	$multikey =~ s/^<!M><b><e><l>$/E434/;
	$multikey =~ s/^<!M><b><eacute>$/E435/;
	$multikey =~ s/^<!M><b><eacute><l>$/E436/;
	$multikey =~ s/^<!M><b><g>$/E437/;
	$multikey =~ s/^<!M><B><G>$/E438/;
	$multikey =~ s/^<!M><b><h>$/E439/;
	$multikey =~ s/^<!M><B><H>$/E43A/;
	$multikey =~ s/^<!M><b><i>$/E43B/;
	$multikey =~ s/^<!M><B><I>$/E43C/;
	$multikey =~ s/^<!M><b><i><p>$/E43D/;
	$multikey =~ s/^<!M><c>$/E43E/;
	$multikey =~ s/^<!M><C>$/E43F/;
	$multikey =~ s/^<!M><c><%backslash>$/E440/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft>$/E441/;
	$multikey =~ s/^<!M><c><%backslash><%bracketleft><%underscore>$/E442/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright>$/E443/;
	$multikey =~ s/^<!M><c><%backslash><%bracketright><%underscore>$/E444/;
	$multikey =~ s/^<!M><c><%backslash><%equal>$/E445/;
	$multikey =~ s/^<!M><c><%backslash><%slash>$/E446/;
	$multikey =~ s/^<!M><c><%backslash><%tilde>$/E447/;
	$multikey =~ s/^<!M><c><%backslash><%underscore>$/E448/;
	$multikey =~ s/^<!M><c><%bar>$/E449/;
	$multikey =~ s/^<!M><c><%bracketleft>$/E44A/;
	$multikey =~ s/^<!M><c><%bracketleft><%underscore>$/E44B/;
	$multikey =~ s/^<!M><c><%bracketright>$/E44C/;
	$multikey =~ s/^<!M><c><%bracketright><%underscore>$/E44D/;
	$multikey =~ s/^<!M><c><%equal>$/E44E/;
	$multikey =~ s/^<!M><C><%minus>$/E44F/;
	$multikey =~ s/^<!M><c><%minus>$/E450/;
	$multikey =~ s/^<!M><c><%percent>$/E451/;
	$multikey =~ s/^<!M><C><%period>$/E452/;
	$multikey =~ s/^<!M><c><%period>$/E453/;
	$multikey =~ s/^<!M><c><%slash>$/E454/;
	$multikey =~ s/^<!M><c><%tilde>$/E455/;
	$multikey =~ s/^<!M><c><%underscore>$/E456/;
	$multikey =~ s/^<!M><c><a>$/E457/;
	$multikey =~ s/^<!M><C><A>$/E458/;
	$multikey =~ s/^<!M><C><a>$/E459/;
	$multikey =~ s/^<!M><c><a><p>$/E45A/;
	$multikey =~ s/^<!M><C><A><P>$/E45B/;
	$multikey =~ s/^<!M><c><a><p><d>$/E45C/;
	$multikey =~ s/^<!M><c><a><p><d><o>$/E45D/;
	$multikey =~ s/^<!M><c><c>$/E45E/;
	$multikey =~ s/^<!M><c><c><%bracketleft>$/E45F/;
	$multikey =~ s/^<!M><c><c><%bracketleft><%underscore>$/E460/;
	$multikey =~ s/^<!M><c><c><%bracketright>$/E461/;
	$multikey =~ s/^<!M><c><c><%bracketright><%underscore>$/E462/;
	$multikey =~ s/^<!M><c><c><%equal>$/E463/;
	$multikey =~ s/^<!M><c><c><%slash>$/E464/;
	$multikey =~ s/^<!M><c><c><%tilde>$/E465/;
	$multikey =~ s/^<!M><c><c><%underscore>$/E466/;
	$multikey =~ s/^<!M><c><m>$/E467/;
	$multikey =~ s/^<!M><c><n>$/E468/;
	$multikey =~ s/^<!M><C><N>$/E469/;
	$multikey =~ s/^<!M><c><r>$/E46A/;
	$multikey =~ s/^<!M><C><R>$/E46B/;
	$multikey =~ s/^<!M><c><u>$/E46C/;
	$multikey =~ s/^<!M><C><U>$/E46D/;
	$multikey =~ s/^<!M><C><u>$/E46E/;
	$multikey =~ s/^<!M><c><u><p>$/E46F/;
	$multikey =~ s/^<!M><c><u><p><d>$/E470/;
	$multikey =~ s/^<!M><c><u><p><d><o>$/E471/;
	$multikey =~ s/^<!M><c><u><p><p>$/E472/;
	$multikey =~ s/^<!M><c><u><p><p><l>$/E473/;
	$multikey =~ s/^<!M><c><u><p><p><l><u>$/E474/;
	$multikey =~ s/^<!M><c><z>$/E475/;
	$multikey =~ s/^<!M><C><Z>$/E476/;
	$multikey =~ s/^<!M><d>$/E477/;
	$multikey =~ s/^<!M><D>$/E478/;
	$multikey =~ s/^<!M><D><%greater>$/E479/;
	$multikey =~ s/^<!M><d><%greater>$/E47A/;
	$multikey =~ s/^<!M><d><e>$/E47B/;
	$multikey =~ s/^<!M><D><E>$/E47C/;
	$multikey =~ s/^<!M><d><eacute>$/E47D/;
	$multikey =~ s/^<!M><D><Eacute>$/E47E/;
	$multikey =~ s/^<!M><d><i>$/E47F/;
	$multikey =~ s/^<!M><d><i><a>$/E480/;
	$multikey =~ s/^<!M><d><i><a><m>$/E481/;
	$multikey =~ s/^<!M><d><i><a><m><e>$/E482/;
	$multikey =~ s/^<!M><d><i><a><m><e><t>$/E483/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><e>$/E484/;
	$multikey =~ s/^<!M><d><i><a><m><e><t><r>$/E485/;
	$multikey =~ s/^<!M><d><i><a><m><egrave>$/E486/;
	$multikey =~ s/^<!M><d><i><a><m><egrave><t>$/E487/;
	$multikey =~ s/^<!M><d><i><a><m><egrave><t><r>$/E488/;
	$multikey =~ s/^<!M><D><Z>$/E489/;
	$multikey =~ s/^<!M><d><z>$/E48A/;
	$multikey =~ s/^<!M><degree>$/E48B/;
	$multikey =~ s/^<!M><division>$/E48C/;
	$multikey =~ s/^<!M><E>$/E48D/;
	$multikey =~ s/^<!M><e>$/E48E/;
	$multikey =~ s/^<!M><e><%backslash>$/E48F/;
	$multikey =~ s/^<!M><e><%backslash><%bar>$/E490/;
	$multikey =~ s/^<!M><e><%bar>$/E491/;
	$multikey =~ s/^<!M><e><%percent>$/E492/;
	$multikey =~ s/^<!M><e><m>$/E493/;
	$multikey =~ s/^<!M><E><M>$/E494/;
	$multikey =~ s/^<!M><e><m><f>$/E495/;
	$multikey =~ s/^<!M><E><M><F>$/E496/;
	$multikey =~ s/^<!M><e><m><o>$/E497/;
	$multikey =~ s/^<!M><E><M><O>$/E498/;
	$multikey =~ s/^<!M><e><n>$/E499/;
	$multikey =~ s/^<!M><E><N>$/E49A/;
	$multikey =~ s/^<!M><E><n>$/E49B/;
	$multikey =~ s/^<!M><e><n><f>$/E49C/;
	$multikey =~ s/^<!M><E><N><F>$/E49D/;
	$multikey =~ s/^<!M><e><n><o>$/E49E/;
	$multikey =~ s/^<!M><E><N><O>$/E49F/;
	$multikey =~ s/^<!M><e><n><u>$/E4A0/;
	$multikey =~ s/^<!M><E><n><v>$/E4A1/;
	$multikey =~ s/^<!M><E><n><v><e>$/E4A2/;
	$multikey =~ s/^<!M><E><n><v><e><l>$/E4A3/;
	$multikey =~ s/^<!M><E><n><v><e><l><o>$/E4A4/;
	$multikey =~ s/^<!M><E><n><v><e><l><o><p>$/E4A5/;
	$multikey =~ s/^<!M><e><s>$/E4A6/;
	$multikey =~ s/^<!M><E><S>$/E4A7/;
	$multikey =~ s/^<!M><e><u>$/E4A8/;
	$multikey =~ s/^<!M><E><U>$/E4A9/;
	$multikey =~ s/^<!M><E><u>$/E4AA/;
	$multikey =~ s/^<!M><eacute>$/E4AB/;
	$multikey =~ s/^<!M><Eacute>$/E4AC/;
	$multikey =~ s/^<!M><f>$/E4AD/;
	$multikey =~ s/^<!M><F>$/E4AE/;
	$multikey =~ s/^<!M><f><e>$/E4AF/;
	$multikey =~ s/^<!M><f><e><n>$/E4B0/;
	$multikey =~ s/^<!M><f><l>$/E4B1/;
	$multikey =~ s/^<!M><F><L>$/E4B2/;
	$multikey =~ s/^<!M><f><n>$/E4B3/;
	$multikey =~ s/^<!M><f><r>$/E4B4/;
	$multikey =~ s/^<!M><F><R>$/E4B5/;
	$multikey =~ s/^<!M><f><t>$/E4B6/;
	$multikey =~ s/^<!M><F><T>$/E4B7/;
	$multikey =~ s/^<!M><g>$/E4B8/;
	$multikey =~ s/^<!M><G>$/E4B9/;
	$multikey =~ s/^<!M><g><e>$/E4BA/;
	$multikey =~ s/^<!M><G><E>$/E4BB/;
	$multikey =~ s/^<!M><g><e><m>$/E4BC/;
	$multikey =~ s/^<!M><G><E><M>$/E4BD/;
	$multikey =~ s/^<!M><g><eacute>$/E4BE/;
	$multikey =~ s/^<!M><G><Eacute>$/E4BF/;
	$multikey =~ s/^<!M><g><eacute><m>$/E4C0/;
	$multikey =~ s/^<!M><G><Eacute><M>$/E4C1/;
	$multikey =~ s/^<!M><g><g>$/E4C2/;
	$multikey =~ s/^<!M><G><G>$/E4C3/;
	$multikey =~ s/^<!M><G><H>$/E4C4/;
	$multikey =~ s/^<!M><g><h>$/E4C5/;
	$multikey =~ s/^<!M><h>$/E4C6/;
	$multikey =~ s/^<!M><H>$/E4C7/;
	$multikey =~ s/^<!M><h><%apostrophe>$/E4C8/;
	$multikey =~ s/^<!M><H><%apostrophe>$/E4C9/;
	$multikey =~ s/^<!M><h><%aprightsingquotmark>$/E4CA/;
	$multikey =~ s/^<!M><H><%aprightsingquotmark>$/E4CB/;
	$multikey =~ s/^<!M><h><%slash>$/E4CC/;
	$multikey =~ s/^<!M><h><d>$/E4CD/;
	$multikey =~ s/^<!M><H><D>$/E4CE/;
	$multikey =~ s/^<!M><h><d><p>$/E4CF/;
	$multikey =~ s/^<!M><H><D><P>$/E4D0/;
	$multikey =~ s/^<!M><h><o>$/E4D1/;
	$multikey =~ s/^<!M><H><O>$/E4D2/;
	$multikey =~ s/^<!M><i>$/E4D3/;
	$multikey =~ s/^<!M><I>$/E4D4/;
	$multikey =~ s/^<!M><i><%at>$/E4D5/;
	$multikey =~ s/^<!M><I><%bracketleft>$/E4D6/;
	$multikey =~ s/^<!M><I><%less>$/E4D7/;
	$multikey =~ s/^<!M><i><%percent>$/E4D8/;
	$multikey =~ s/^<!M><I><%underscore>$/E4D9/;
	$multikey =~ s/^<!M><i><i>$/E4DA/;
	$multikey =~ s/^<!M><i><l>$/E4DB/;
	$multikey =~ s/^<!M><I><L>$/E4DC/;
	$multikey =~ s/^<!M><i><n>$/E4DD/;
	$multikey =~ s/^<!M><I><N>$/E4DE/;
	$multikey =~ s/^<!M><i><n><t>$/E4DF/;
	$multikey =~ s/^<!M><i><n><t><e>$/E4E0/;
	$multikey =~ s/^<!M><i><n><t><e><r>$/E4E1/;
	$multikey =~ s/^<!M><i><n><t><e><r><s>$/E4E2/;
	$multikey =~ s/^<!M><i><n><t><e><r><s><e>$/E4E3/;
	$multikey =~ s/^<!M><I><O>$/E4E4/;
	$multikey =~ s/^<!M><i><p>$/E4E5/;
	$multikey =~ s/^<!M><I><P>$/E4E6/;
	$multikey =~ s/^<!M><i><q>$/E4E7/;
	$multikey =~ s/^<!M><I><Q>$/E4E8/;
	$multikey =~ s/^<!M><i><r>$/E4E9/;
	$multikey =~ s/^<!M><I><R>$/E4EA/;
	$multikey =~ s/^<!M><i><r><m>$/E4EB/;
	$multikey =~ s/^<!M><I><R><M>$/E4EC/;
	$multikey =~ s/^<!M><i><r><m><p>$/E4ED/;
	$multikey =~ s/^<!M><I><R><M><P>$/E4EE/;
	$multikey =~ s/^<!M><j>$/E4EF/;
	$multikey =~ s/^<!M><J>$/E4F0/;
	$multikey =~ s/^<!M><j><o>$/E4F1/;
	$multikey =~ s/^<!M><J><O>$/E4F2/;
	$multikey =~ s/^<!M><j><p>$/E4F3/;
	$multikey =~ s/^<!M><J><P>$/E4F4/;
	$multikey =~ s/^<!M><k>$/E4F5/;
	$multikey =~ s/^<!M><K>$/E4F6/;
	$multikey =~ s/^<!M><k><g>$/E4F7/;
	$multikey =~ s/^<!M><K><G>$/E4F8/;
	$multikey =~ s/^<!M><k><h>$/E4F9/;
	$multikey =~ s/^<!M><K><H>$/E4FA/;
	$multikey =~ s/^<!M><k><o>$/E4FB/;
	$multikey =~ s/^<!M><K><O>$/E4FC/;
	$multikey =~ s/^<!M><k><p>$/E4FD/;
	$multikey =~ s/^<!M><K><P>$/E4FE/;
	$multikey =~ s/^<!M><k><r>$/E4FF/;
	$multikey =~ s/^<!M><K><R>$/E500/;
	$multikey =~ s/^<!M><k><w>$/E501/;
	$multikey =~ s/^<!M><K><W>$/E502/;
	$multikey =~ s/^<!M><k><z>$/E503/;
	$multikey =~ s/^<!M><K><Z>$/E504/;
	$multikey =~ s/^<!M><l>$/E505/;
	$multikey =~ s/^<!M><L>$/E506/;
	$multikey =~ s/^<!M><l><%apostrophe>$/E507/;
	$multikey =~ s/^<!M><L><%apostrophe>$/E508/;
	$multikey =~ s/^<!M><l><%aprightsingquotmark>$/E509/;
	$multikey =~ s/^<!M><L><%aprightsingquotmark>$/E50A/;
	$multikey =~ s/^<!M><L><%backslash>$/E50B/;
	$multikey =~ s/^<!M><L><%parenright>$/E50C/;
	$multikey =~ s/^<!M><L><%percent>$/E50D/;
	$multikey =~ s/^<!M><L><%percent><%percent>$/E50E/;
	$multikey =~ s/^<!M><l><a>$/E50F/;
	$multikey =~ s/^<!M><L><A>$/E510/;
	$multikey =~ s/^<!M><l><b>$/E511/;
	$multikey =~ s/^<!M><L><B>$/E512/;
	$multikey =~ s/^<!M><l><d>$/E513/;
	$multikey =~ s/^<!M><L><D>$/E514/;
	$multikey =~ s/^<!M><l><d><p>$/E515/;
	$multikey =~ s/^<!M><L><D><P>$/E516/;
	$multikey =~ s/^<!M><l><e>$/E517/;
	$multikey =~ s/^<!M><L><E>$/E518/;
	$multikey =~ s/^<!M><l><e><z>$/E519/;
	$multikey =~ s/^<!M><l><i>$/E51A/;
	$multikey =~ s/^<!M><L><I>$/E51B/;
	$multikey =~ s/^<!M><l><i><b>$/E51C/;
	$multikey =~ s/^<!M><L><I><B>$/E51D/;
	$multikey =~ s/^<!M><l><i><o>$/E51E/;
	$multikey =~ s/^<!M><L><I><O>$/E51F/;
	$multikey =~ s/^<!M><L><p>$/E520/;
	$multikey =~ s/^<!M><L><p><a>$/E521/;
	$multikey =~ s/^<!M><L><p><a><r>$/E522/;
	$multikey =~ s/^<!M><L><p><a><r><e>$/E523/;
	$multikey =~ s/^<!M><L><p><a><r><e><n>$/E524/;
	$multikey =~ s/^<!M><L><p><a><r><e><n><g>$/E525/;
	$multikey =~ s/^<!M><l><r>$/E526/;
	$multikey =~ s/^<!M><L><R>$/E527/;
	$multikey =~ s/^<!M><l><r><e>$/E528/;
	$multikey =~ s/^<!M><L><R><E>$/E529/;
	$multikey =~ s/^<!M><m>$/E52A/;
	$multikey =~ s/^<!M><M>$/E52B/;
	$multikey =~ s/^<!M><m><k>$/E52C/;
	$multikey =~ s/^<!M><M><K>$/E52D/;
	$multikey =~ s/^<!M><m><n>$/E52E/;
	$multikey =~ s/^<!M><M><N>$/E52F/;
	$multikey =~ s/^<!M><m><u>$/E530/;
	$multikey =~ s/^<!M><M><U>$/E531/;
	$multikey =~ s/^<!M><m><v>$/E532/;
	$multikey =~ s/^<!M><M><V>$/E533/;
	$multikey =~ s/^<!M><multiply>$/E534/;
	$multikey =~ s/^<!M><N>$/E535/;
	$multikey =~ s/^<!M><n>$/E536/;
	$multikey =~ s/^<!M><n><%underscore>$/E537/;
	$multikey =~ s/^<!M><n><a>$/E538/;
	$multikey =~ s/^<!M><n><b>$/E539/;
	$multikey =~ s/^<!M><N><B>$/E53A/;
	$multikey =~ s/^<!M><N><G>$/E53B/;
	$multikey =~ s/^<!M><n><g>$/E53C/;
	$multikey =~ s/^<!M><n><m>$/E53D/;
	$multikey =~ s/^<!M><N><M>$/E53E/;
	$multikey =~ s/^<!M><n><o>$/E53F/;
	$multikey =~ s/^<!M><N><O>$/E540/;
	$multikey =~ s/^<!M><n><p>$/E541/;
	$multikey =~ s/^<!M><N><P>$/E542/;
	$multikey =~ s/^<!M><n><u>$/E543/;
	$multikey =~ s/^<!M><o>$/E544/;
	$multikey =~ s/^<!M><O>$/E545/;
	$multikey =~ s/^<!M><o><%backslash>$/E546/;
	$multikey =~ s/^<!M><O><%backslash>$/E547/;
	$multikey =~ s/^<!M><O><%bar>$/E548/;
	$multikey =~ s/^<!M><o><%bar>$/E549/;
	$multikey =~ s/^<!M><o><%colon>$/E54A/;
	$multikey =~ s/^<!M><O><%colon>$/E54B/;
	$multikey =~ s/^<!M><o><%hash>$/E54C/;
	$multikey =~ s/^<!M><O><%hash>$/E54D/;
	$multikey =~ s/^<!M><O><%less>$/E54E/;
	$multikey =~ s/^<!M><o><%minus>$/E54F/;
	$multikey =~ s/^<!M><O><%minus>$/E550/;
	$multikey =~ s/^<!M><O><%percent>$/E551/;
	$multikey =~ s/^<!M><o><%plus>$/E552/;
	$multikey =~ s/^<!M><O><%plus>$/E553/;
	$multikey =~ s/^<!M><o><%slash>$/E554/;
	$multikey =~ s/^<!M><o><i>$/E555/;
	$multikey =~ s/^<!M><o><i><n>$/E556/;
	$multikey =~ s/^<!M><o><m>$/E557/;
	$multikey =~ s/^<!M><O><M>$/E558/;
	$multikey =~ s/^<!M><O><o>$/E559/;
	$multikey =~ s/^<!M><o><p>$/E55A/;
	$multikey =~ s/^<!M><O><P>$/E55B/;
	$multikey =~ s/^<!M><o><s>$/E55C/;
	$multikey =~ s/^<!M><o><s><u>$/E55D/;
	$multikey =~ s/^<!M><o><t>$/E55E/;
	$multikey =~ s/^<!M><O><T>$/E55F/;
	$multikey =~ s/^<!M><o><T>$/E560/;
	$multikey =~ s/^<!M><p>$/E561/;
	$multikey =~ s/^<!M><P>$/E562/;
	$multikey =~ s/^<!M><p><%bar>$/E563/;
	$multikey =~ s/^<!M><p><a>$/E564/;
	$multikey =~ s/^<!M><P><A>$/E565/;
	$multikey =~ s/^<!M><p><a><c>$/E566/;
	$multikey =~ s/^<!M><P><A><C>$/E567/;
	$multikey =~ s/^<!M><p><a><r>$/E568/;
	$multikey =~ s/^<!M><P><A><R>$/E569/;
	$multikey =~ s/^<!M><p><a><t>$/E56A/;
	$multikey =~ s/^<!M><P><A><T>$/E56B/;
	$multikey =~ s/^<!M><p><d>$/E56C/;
	$multikey =~ s/^<!M><p><e>$/E56D/;
	$multikey =~ s/^<!M><P><e>$/E56E/;
	$multikey =~ s/^<!M><P><E>$/E56F/;
	$multikey =~ s/^<!M><p><e><h>$/E570/;
	$multikey =~ s/^<!M><P><E><H>$/E571/;
	$multikey =~ s/^<!M><p><e><l>$/E572/;
	$multikey =~ s/^<!M><P><E><L>$/E573/;
	$multikey =~ s/^<!M><p><h>$/E574/;
	$multikey =~ s/^<!M><P><H>$/E575/;
	$multikey =~ s/^<!M><p><i>$/E576/;
	$multikey =~ s/^<!M><P><I>$/E577/;
	$multikey =~ s/^<!M><p><i><s>$/E578/;
	$multikey =~ s/^<!M><P><I><S>$/E579/;
	$multikey =~ s/^<!M><p><l>$/E57A/;
	$multikey =~ s/^<!M><P><L>$/E57B/;
	$multikey =~ s/^<!M><P><l>$/E57C/;
	$multikey =~ s/^<!M><p><o>$/E57D/;
	$multikey =~ s/^<!M><P><O>$/E57E/;
	$multikey =~ s/^<!M><p><o><i>$/E57F/;
	$multikey =~ s/^<!M><P><O><I>$/E580/;
	$multikey =~ s/^<!M><p><p>$/E581/;
	$multikey =~ s/^<!M><P><P>$/E582/;
	$multikey =~ s/^<!M><p><p><c>$/E583/;
	$multikey =~ s/^<!M><P><P><C>$/E584/;
	$multikey =~ s/^<!M><p><p><m>$/E585/;
	$multikey =~ s/^<!M><P><P><M>$/E586/;
	$multikey =~ s/^<!M><p><p><r>$/E587/;
	$multikey =~ s/^<!M><P><P><R>$/E588/;
	$multikey =~ s/^<!M><p><p><t>$/E589/;
	$multikey =~ s/^<!M><P><P><T>$/E58A/;
	$multikey =~ s/^<!M><p><t>$/E58B/;
	$multikey =~ s/^<!M><P><T>$/E58C/;
	$multikey =~ s/^<!M><p><v>$/E58D/;
	$multikey =~ s/^<!M><P><V>$/E58E/;
	$multikey =~ s/^<!M><p><y>$/E58F/;
	$multikey =~ s/^<!M><P><Y>$/E590/;
	$multikey =~ s/^<!M><q>$/E591/;
	$multikey =~ s/^<!M><Q>$/E592/;
	$multikey =~ s/^<!M><q><a>$/E593/;
	$multikey =~ s/^<!M><Q><A>$/E594/;
	$multikey =~ s/^<!M><r>$/E595/;
	$multikey =~ s/^<!M><R>$/E596/;
	$multikey =~ s/^<!M><R><C>$/E597/;
	$multikey =~ s/^<!M><R><C><C>$/E598/;
	$multikey =~ s/^<!M><R><C><C><C>$/E599/;
	$multikey =~ s/^<!M><R><C><C><C><D>$/E59A/;
	$multikey =~ s/^<!M><R><C><C><C><D><D>$/E59B/;
	$multikey =~ s/^<!M><R><C><C><D>$/E59C/;
	$multikey =~ s/^<!M><R><C><V>$/E59D/;
	$multikey =~ s/^<!M><R><D>$/E59E/;
	$multikey =~ s/^<!M><R><D><D>$/E59F/;
	$multikey =~ s/^<!M><r><e>$/E5A0/;
	$multikey =~ s/^<!M><R><E>$/E5A1/;
	$multikey =~ s/^<!M><r><e><c>$/E5A2/;
	$multikey =~ s/^<!M><R><E><C>$/E5A3/;
	$multikey =~ s/^<!M><R><L>$/E5A4/;
	$multikey =~ s/^<!M><R><p>$/E5A5/;
	$multikey =~ s/^<!M><R><p><a>$/E5A6/;
	$multikey =~ s/^<!M><R><p><a><r>$/E5A7/;
	$multikey =~ s/^<!M><R><p><a><r><e>$/E5A8/;
	$multikey =~ s/^<!M><R><p><a><r><e><n>$/E5A9/;
	$multikey =~ s/^<!M><R><p><a><r><e><n><l>$/E5AA/;
	$multikey =~ s/^<!M><R><U>$/E5AB/;
	$multikey =~ s/^<!M><R><u>$/E5AC/;
	$multikey =~ s/^<!M><r><u>$/E5AD/;
	$multikey =~ s/^<!M><s>$/E5AE/;
	$multikey =~ s/^<!M><S>$/E5AF/;
	$multikey =~ s/^<!M><s><%backslash>$/E5B0/;
	$multikey =~ s/^<!M><s><%bracketleft>$/E5B1/;
	$multikey =~ s/^<!M><S><%bracketleft>$/E5B2/;
	$multikey =~ s/^<!M><s><%bracketright>$/E5B3/;
	$multikey =~ s/^<!M><S><%bracketright>$/E5B4/;
	$multikey =~ s/^<!M><s><%less>$/E5B5/;
	$multikey =~ s/^<!M><S><%less>$/E5B6/;
	$multikey =~ s/^<!M><s><%percent>$/E5B7/;
	$multikey =~ s/^<!M><s><%period>$/E5B8/;
	$multikey =~ s/^<!M><S><%period>$/E5B9/;
	$multikey =~ s/^<!M><s><%slash>$/E5BA/;
	$multikey =~ s/^<!M><s><a>$/E5BB/;
	$multikey =~ s/^<!M><S><a>$/E5BC/;
	$multikey =~ s/^<!M><S><A>$/E5BD/;
	$multikey =~ s/^<!M><s><a><g>$/E5BE/;
	$multikey =~ s/^<!M><S><A><G>$/E5BF/;
	$multikey =~ s/^<!M><s><c>$/E5C0/;
	$multikey =~ s/^<!M><S><c>$/E5C1/;
	$multikey =~ s/^<!M><S><C>$/E5C2/;
	$multikey =~ s/^<!M><s><c><o>$/E5C3/;
	$multikey =~ s/^<!M><S><C><O>$/E5C4/;
	$multikey =~ s/^<!M><s><d>$/E5C5/;
	$multikey =~ s/^<!M><S><D>$/E5C6/;
	$multikey =~ s/^<!M><s><e>$/E5C7/;
	$multikey =~ s/^<!M><S><E>$/E5C8/;
	$multikey =~ s/^<!M><s><e><t>$/E5C9/;
	$multikey =~ s/^<!M><s><e><t><m>$/E5CA/;
	$multikey =~ s/^<!M><s><e><t><m><i>$/E5CB/;
	$multikey =~ s/^<!M><s><e><t><m><i><n>$/E5CC/;
	$multikey =~ s/^<!M><s><e><t><m><i><n><u>$/E5CD/;
	$multikey =~ s/^<!M><s><i>$/E5CE/;
	$multikey =~ s/^<!M><S><I>$/E5CF/;
	$multikey =~ s/^<!M><s><n>$/E5D0/;
	$multikey =~ s/^<!M><S><N>$/E5D1/;
	$multikey =~ s/^<!M><s><o>$/E5D2/;
	$multikey =~ s/^<!M><S><O>$/E5D3/;
	$multikey =~ s/^<!M><S><o>$/E5D4/;
	$multikey =~ s/^<!M><s><u>$/E5D5/;
	$multikey =~ s/^<!M><S><U>$/E5D6/;
	$multikey =~ s/^<!M><s><v>$/E5D7/;
	$multikey =~ s/^<!M><S><V>$/E5D8/;
	$multikey =~ s/^<!M><T>$/E5D9/;
	$multikey =~ s/^<!M><t>$/E5DA/;
	$multikey =~ s/^<!M><T><%greater>$/E5DB/;
	$multikey =~ s/^<!M><T><%less>$/E5DC/;
	$multikey =~ s/^<!M><T><%percent>$/E5DD/;
	$multikey =~ s/^<!M><T><2>$/E5DE/;
	$multikey =~ s/^<!M><T><2><%greater>$/E5DF/;
	$multikey =~ s/^<!M><T><2><%less>$/E5E0/;
	$multikey =~ s/^<!M><T><3>$/E5E1/;
	$multikey =~ s/^<!M><t><a>$/E5E2/;
	$multikey =~ s/^<!M><T><A>$/E5E3/;
	$multikey =~ s/^<!M><t><a><u>$/E5E4/;
	$multikey =~ s/^<!M><T><A><U>$/E5E5/;
	$multikey =~ s/^<!M><t><e>$/E5E6/;
	$multikey =~ s/^<!M><T><H>$/E5E7/;
	$multikey =~ s/^<!M><t><h>$/E5E8/;
	$multikey =~ s/^<!M><t><n>$/E5E9/;
	$multikey =~ s/^<!M><T><N>$/E5EA/;
	$multikey =~ s/^<!M><t><o>$/E5EB/;
	$multikey =~ s/^<!M><T><O>$/E5EC/;
	$multikey =~ s/^<!M><t><r>$/E5ED/;
	$multikey =~ s/^<!M><T><R>$/E5EE/;
	$multikey =~ s/^<!M><T><T>$/E5EF/;
	$multikey =~ s/^<!M><T><T><%percent>$/E5F0/;
	$multikey =~ s/^<!M><u>$/E5F1/;
	$multikey =~ s/^<!M><U>$/E5F2/;
	$multikey =~ s/^<!M><u><%minus>$/E5F3/;
	$multikey =~ s/^<!M><u><a>$/E5F4/;
	$multikey =~ s/^<!M><U><A>$/E5F5/;
	$multikey =~ s/^<!M><u><n>$/E5F6/;
	$multikey =~ s/^<!M><u><n><i>$/E5F7/;
	$multikey =~ s/^<!M><u><n><i><o>$/E5F8/;
	$multikey =~ s/^<!M><V>$/E5F9/;
	$multikey =~ s/^<!M><v>$/E5FA/;
	$multikey =~ s/^<!M><v><%backslash>$/E5FB/;
	$multikey =~ s/^<!M><v><%backslash><%parenleft>$/E5FC/;
	$multikey =~ s/^<!M><v><%backslash><%parenright>$/E5FD/;
	$multikey =~ s/^<!M><v><%parenleft>$/E5FE/;
	$multikey =~ s/^<!M><v><%parenright>$/E5FF/;
	$multikey =~ s/^<!M><v><%percent>$/E600/;
	$multikey =~ s/^<!M><V><%percent>$/E601/;
	$multikey =~ s/^<!M><v><%percent><%underscore>$/E602/;
	$multikey =~ s/^<!M><V><%percent><%underscore>$/E603/;
	$multikey =~ s/^<!M><v><%underscore>$/E604/;
	$multikey =~ s/^<!M><v><e>$/E605/;
	$multikey =~ s/^<!M><V><E>$/E606/;
	$multikey =~ s/^<!M><v><e><r>$/E607/;
	$multikey =~ s/^<!M><V><E><R>$/E608/;
	$multikey =~ s/^<!M><v><i>$/E609/;
	$multikey =~ s/^<!M><V><I>$/E60A/;
	$multikey =~ s/^<!M><v><i><e>$/E60B/;
	$multikey =~ s/^<!M><V><I><E>$/E60C/;
	$multikey =~ s/^<!M><v><i><r>$/E60D/;
	$multikey =~ s/^<!M><V><I><R>$/E60E/;
	$multikey =~ s/^<!M><v><n>$/E60F/;
	$multikey =~ s/^<!M><V><N>$/E610/;
	$multikey =~ s/^<!M><v><v>$/E611/;
	$multikey =~ s/^<!M><w>$/E612/;
	$multikey =~ s/^<!M><W>$/E613/;
	$multikey =~ s/^<!M><w><w>$/E614/;
	$multikey =~ s/^<!M><X>$/E615/;
	$multikey =~ s/^<!M><x>$/E616/;
	$multikey =~ s/^<!M><x><o>$/E617/;
	$multikey =~ s/^<!M><X><O>$/E618/;
	$multikey =~ s/^<!M><x><t>$/E619/;
	$multikey =~ s/^<!M><X><T>$/E61A/;
	$multikey =~ s/^<!M><y>$/E61B/;
	$multikey =~ s/^<!M><Y>$/E61C/;
	$multikey =~ s/^<!M><y><e>$/E61D/;
	$multikey =~ s/^<!M><Y><E>$/E61E/;
	$multikey =~ s/^<!M><z>$/E61F/;
	$multikey =~ s/^<!M><Z>$/E620/;
	$multikey =~ s/^<!M><z><%greater>$/E621/;
	$multikey =~ s/^<!M><Z><%greater>$/E622/;
	$multikey =~ s/^<!M><z><%less>$/E623/;
	$multikey =~ s/^<!M><Z><%less>$/E624/;
	$multikey =~ s/^<!M><~nbspace>$/E625/;
	$multikey =~ s/^<!M><~nbspace><%ampersand>$/E626/;
	$multikey =~ s/^<!M><~nbspace><%apostrophe>$/E627/;
	$multikey =~ s/^<!M><~nbspace><%aprightsingquotmark>$/E628/;
	$multikey =~ s/^<!M><~nbspace><%asterisk>$/E629/;
	$multikey =~ s/^<!M><~nbspace><%backslash>$/E62A/;
	$multikey =~ s/^<!M><~nbspace><%backslash><%slash>$/E62B/;
	$multikey =~ s/^<!M><~nbspace><%bar>$/E62C/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash>$/E62D/;
	$multikey =~ s/^<!M><~nbspace><%bar><%backslash><%slash>$/E62E/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar>$/E62F/;
	$multikey =~ s/^<!M><~nbspace><%bar><%bar><%bar>$/E630/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash>$/E631/;
	$multikey =~ s/^<!M><~nbspace><%bar><%slash><%backslash>$/E632/;
	$multikey =~ s/^<!M><~nbspace><%bar><e>$/E633/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><%backslash>$/E634/;
	$multikey =~ s/^<!M><~nbspace><%bar><e><e>$/E635/;
	$multikey =~ s/^<!M><~nbspace><%bar><p>$/E636/;
	$multikey =~ s/^<!M><~nbspace><%bracketleft>$/E637/;
	$multikey =~ s/^<!M><~nbspace><%bracketright>$/E638/;
	$multikey =~ s/^<!M><~nbspace><%circum>$/E639/;
	$multikey =~ s/^<!M><~nbspace><%colon>$/E63A/;
	$multikey =~ s/^<!M><~nbspace><%equal>$/E63B/;
	$multikey =~ s/^<!M><~nbspace><%equal><%bar>$/E63C/;
	$multikey =~ s/^<!M><~nbspace><%equal><%minus>$/E63D/;
	$multikey =~ s/^<!M><~nbspace><%exclam>$/E63E/;
	$multikey =~ s/^<!M><~nbspace><%greater>$/E63F/;
	$multikey =~ s/^<!M><~nbspace><%greater><%greater>$/E640/;
	$multikey =~ s/^<!M><~nbspace><%greater><%minus>$/E641/;
	$multikey =~ s/^<!M><~nbspace><%hash>$/E642/;
	$multikey =~ s/^<!M><~nbspace><%less>$/E643/;
	$multikey =~ s/^<!M><~nbspace><%less><%equal>$/E644/;
	$multikey =~ s/^<!M><~nbspace><%less><%less>$/E645/;
	$multikey =~ s/^<!M><~nbspace><%less><%less><%minus>$/E646/;
	$multikey =~ s/^<!M><~nbspace><%less><%minus>$/E647/;
	$multikey =~ s/^<!M><~nbspace><%less><%tilde>$/E648/;
	$multikey =~ s/^<!M><~nbspace><%minus>$/E649/;
	$multikey =~ s/^<!M><~nbspace><%minus><%apostrophe>$/E64A/;
	$multikey =~ s/^<!M><~nbspace><%minus><%aprightsingquotmark>$/E64B/;
	$multikey =~ s/^<!M><~nbspace><%minus><%bracketright>$/E64C/;
	$multikey =~ s/^<!M><~nbspace><%minus><o>$/E64D/;
	$multikey =~ s/^<!M><~nbspace><%minus><s>$/E64E/;
	$multikey =~ s/^<!M><~nbspace><%parenleft>$/E64F/;
	$multikey =~ s/^<!M><~nbspace><%parenright>$/E650/;
	$multikey =~ s/^<!M><~nbspace><%period>$/E651/;
	$multikey =~ s/^<!M><~nbspace><%period><c>$/E652/;
	$multikey =~ s/^<!M><~nbspace><%period><v>$/E653/;
	$multikey =~ s/^<!M><~nbspace><%period><V>$/E654/;
	$multikey =~ s/^<!M><~nbspace><%plus>$/E655/;
	$multikey =~ s/^<!M><~nbspace><%slash>$/E656/;
	$multikey =~ s/^<!M><~nbspace><%slash><%backslash>$/E657/;
	$multikey =~ s/^<!M><~nbspace><%slash><%hash>$/E658/;
	$multikey =~ s/^<!M><~nbspace><%slash><%hash><%underscore>$/E659/;
	$multikey =~ s/^<!M><~nbspace><%slash><%slash>$/E65A/;
	$multikey =~ s/^<!M><~nbspace><%slash><%underscore>$/E65B/;
	$multikey =~ s/^<!M><~nbspace><%tilde>$/E65C/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal>$/E65D/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%equal><%slash>$/E65E/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%slash>$/E65F/;
	$multikey =~ s/^<!M><~nbspace><%tilde><%tilde>$/E660/;
	$multikey =~ s/^<!M><~nbspace><%underscore>$/E661/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%minus>$/E662/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore>$/E663/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><v>$/E664/;
	$multikey =~ s/^<!M><~nbspace><%underscore><%underscore><V>$/E665/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e>$/E666/;
	$multikey =~ s/^<!M><~nbspace><%underscore><e><%backslash>$/E667/;
	$multikey =~ s/^<!M><~nbspace><%underscore><p>$/E668/;
	$multikey =~ s/^<!M><~nbspace><%underscore><u>$/E669/;
	$multikey =~ s/^<!M><~nbspace><%underscore><v>$/E66A/;
	$multikey =~ s/^<!M><~nbspace><%underscore><X>$/E66B/;
	$multikey =~ s/^<!M><~nbspace><2>$/E66C/;
	$multikey =~ s/^<!M><~nbspace><3>$/E66D/;
	$multikey =~ s/^<!M><~nbspace><A>$/E66E/;
	$multikey =~ s/^<!M><~nbspace><a>$/E66F/;
	$multikey =~ s/^<!M><~nbspace><A><%underscore>$/E670/;
	$multikey =~ s/^<!M><~nbspace><b>$/E671/;
	$multikey =~ s/^<!M><~nbspace><c>$/E672/;
	$multikey =~ s/^<!M><~nbspace><c><%backslash>$/E673/;
	$multikey =~ s/^<!M><~nbspace><c><c>$/E674/;
	$multikey =~ s/^<!M><~nbspace><e>$/E675/;
	$multikey =~ s/^<!M><~nbspace><e><e>$/E676/;
	$multikey =~ s/^<!M><~nbspace><e><e><%bar>$/E677/;
	$multikey =~ s/^<!M><~nbspace><n>$/E678/;
	$multikey =~ s/^<!M><~nbspace><o>$/E679/;
	$multikey =~ s/^<!M><~nbspace><O>$/E67A/;
	$multikey =~ s/^<!M><~nbspace><o><%minus>$/E67B/;
	$multikey =~ s/^<!M><~nbspace><R>$/E67C/;
	$multikey =~ s/^<!M><~nbspace><r>$/E67D/;
	$multikey =~ s/^<!M><~nbspace><S>$/E67E/;
	$multikey =~ s/^<!M><~nbspace><S><S>$/E67F/;
	$multikey =~ s/^<!M><~nbspace><T>$/E680/;
	$multikey =~ s/^<!M><~nbspace><V>$/E681/;
	$multikey =~ s/^<!M><~nbspace><Y>$/E682/;
	$multikey =~ s/^<!M><~nbspace><~nbspace>$/E683/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%backslash>$/E684/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bar>$/E685/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketleft>$/E686/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%bracketright>$/E687/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%equal>$/E688/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%greater>$/E689/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%less>$/E68A/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%minus>$/E68B/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><%slash>$/E68C/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><3>$/E68D/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><o>$/E68E/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><T>$/E68F/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace>$/E690/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><%asterisk>$/E691/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~nbspace>$/E692/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~nbspace><~space>$/E693/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space>$/E694/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><%asterisk>$/E695/;
	$multikey =~ s/^<!M><~nbspace><~nbspace><~space><~space>$/E696/;
	$multikey =~ s/^<!M><~nbspace><~space>$/E697/;
	$multikey =~ s/^<!M><~nbspace><~space><%backslash>$/E698/;
	$multikey =~ s/^<!M><~nbspace><~space><%bar>$/E699/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketleft>$/E69A/;
	$multikey =~ s/^<!M><~nbspace><~space><%bracketright>$/E69B/;
	$multikey =~ s/^<!M><~nbspace><~space><%equal>$/E69C/;
	$multikey =~ s/^<!M><~nbspace><~space><%greater>$/E69D/;
	$multikey =~ s/^<!M><~nbspace><~space><%less>$/E69E/;
	$multikey =~ s/^<!M><~nbspace><~space><%minus>$/E69F/;
	$multikey =~ s/^<!M><~nbspace><~space><%slash>$/E6A0/;
	$multikey =~ s/^<!M><~nbspace><~space><3>$/E6A1/;
	$multikey =~ s/^<!M><~nbspace><~space><o>$/E6A2/;
	$multikey =~ s/^<!M><~nbspace><~space><T>$/E6A3/;
	$multikey =~ s/^<!M><~nbspace><~space><~space>$/E6A4/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><%asterisk>$/E6A5/;
	$multikey =~ s/^<!M><~nbspace><~space><~space><~space>$/E6A6/;
	$multikey =~ s/^<!M><~nbthinspace>$/E6A7/;
	$multikey =~ s/^<!M><~space>$/E6A8/;
	$multikey =~ s/^<!M><~space><%ampersand>$/E6A9/;
	$multikey =~ s/^<!M><~space><%apostrophe>$/E6AA/;
	$multikey =~ s/^<!M><~space><%aprightsingquotmark>$/E6AB/;
	$multikey =~ s/^<!M><~space><%asterisk>$/E6AC/;
	$multikey =~ s/^<!M><~space><%backslash>$/E6AD/;
	$multikey =~ s/^<!M><~space><%backslash><%slash>$/E6AE/;
	$multikey =~ s/^<!M><~space><%bar>$/E6AF/;
	$multikey =~ s/^<!M><~space><%bar><%backslash>$/E6B0/;
	$multikey =~ s/^<!M><~space><%bar><%backslash><%slash>$/E6B1/;
	$multikey =~ s/^<!M><~space><%bar><%bar>$/E6B2/;
	$multikey =~ s/^<!M><~space><%bar><%bar><%bar>$/E6B3/;
	$multikey =~ s/^<!M><~space><%bar><%slash>$/E6B4/;
	$multikey =~ s/^<!M><~space><%bar><%slash><%backslash>$/E6B5/;
	$multikey =~ s/^<!M><~space><%bar><e>$/E6B6/;
	$multikey =~ s/^<!M><~space><%bar><e><%backslash>$/E6B7/;
	$multikey =~ s/^<!M><~space><%bar><e><e>$/E6B8/;
	$multikey =~ s/^<!M><~space><%bar><p>$/E6B9/;
	$multikey =~ s/^<!M><~space><%bracketleft>$/E6BA/;
	$multikey =~ s/^<!M><~space><%bracketright>$/E6BB/;
	$multikey =~ s/^<!M><~space><%circum>$/E6BC/;
	$multikey =~ s/^<!M><~space><%colon>$/E6BD/;
	$multikey =~ s/^<!M><~space><%equal>$/E6BE/;
	$multikey =~ s/^<!M><~space><%equal><%bar>$/E6BF/;
	$multikey =~ s/^<!M><~space><%equal><%minus>$/E6C0/;
	$multikey =~ s/^<!M><~space><%exclam>$/E6C1/;
	$multikey =~ s/^<!M><~space><%greater>$/E6C2/;
	$multikey =~ s/^<!M><~space><%greater><%greater>$/E6C3/;
	$multikey =~ s/^<!M><~space><%greater><%minus>$/E6C4/;
	$multikey =~ s/^<!M><~space><%hash>$/E6C5/;
	$multikey =~ s/^<!M><~space><%less>$/E6C6/;
	$multikey =~ s/^<!M><~space><%less><%equal>$/E6C7/;
	$multikey =~ s/^<!M><~space><%less><%less>$/E6C8/;
	$multikey =~ s/^<!M><~space><%less><%less><%minus>$/E6C9/;
	$multikey =~ s/^<!M><~space><%less><%minus>$/E6CA/;
	$multikey =~ s/^<!M><~space><%less><%tilde>$/E6CB/;
	$multikey =~ s/^<!M><~space><%minus>$/E6CC/;
	$multikey =~ s/^<!M><~space><%minus><%apostrophe>$/E6CD/;
	$multikey =~ s/^<!M><~space><%minus><%aprightsingquotmark>$/E6CE/;
	$multikey =~ s/^<!M><~space><%minus><%bracketright>$/E6CF/;
	$multikey =~ s/^<!M><~space><%minus><o>$/E6D0/;
	$multikey =~ s/^<!M><~space><%minus><s>$/E6D1/;
	$multikey =~ s/^<!M><~space><%parenleft>$/E6D2/;
	$multikey =~ s/^<!M><~space><%parenright>$/E6D3/;
	$multikey =~ s/^<!M><~space><%period>$/E6D4/;
	$multikey =~ s/^<!M><~space><%period><c>$/E6D5/;
	$multikey =~ s/^<!M><~space><%period><v>$/E6D6/;
	$multikey =~ s/^<!M><~space><%period><V>$/E6D7/;
	$multikey =~ s/^<!M><~space><%plus>$/E6D8/;
	$multikey =~ s/^<!M><~space><%slash>$/E6D9/;
	$multikey =~ s/^<!M><~space><%slash><%backslash>$/E6DA/;
	$multikey =~ s/^<!M><~space><%slash><%hash>$/E6DB/;
	$multikey =~ s/^<!M><~space><%slash><%hash><%underscore>$/E6DC/;
	$multikey =~ s/^<!M><~space><%slash><%slash>$/E6DD/;
	$multikey =~ s/^<!M><~space><%slash><%underscore>$/E6DE/;
	$multikey =~ s/^<!M><~space><%tilde>$/E6DF/;
	$multikey =~ s/^<!M><~space><%tilde><%equal>$/E6E0/;
	$multikey =~ s/^<!M><~space><%tilde><%equal><%slash>$/E6E1/;
	$multikey =~ s/^<!M><~space><%tilde><%slash>$/E6E2/;
	$multikey =~ s/^<!M><~space><%tilde><%tilde>$/E6E3/;
	$multikey =~ s/^<!M><~space><%underscore>$/E6E4/;
	$multikey =~ s/^<!M><~space><%underscore><%minus>$/E6E5/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore>$/E6E6/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><v>$/E6E7/;
	$multikey =~ s/^<!M><~space><%underscore><%underscore><V>$/E6E8/;
	$multikey =~ s/^<!M><~space><%underscore><e>$/E6E9/;
	$multikey =~ s/^<!M><~space><%underscore><e><%backslash>$/E6EA/;
	$multikey =~ s/^<!M><~space><%underscore><p>$/E6EB/;
	$multikey =~ s/^<!M><~space><%underscore><u>$/E6EC/;
	$multikey =~ s/^<!M><~space><%underscore><v>$/E6ED/;
	$multikey =~ s/^<!M><~space><%underscore><X>$/E6EE/;
	$multikey =~ s/^<!M><~space><2>$/E6EF/;
	$multikey =~ s/^<!M><~space><3>$/E6F0/;
	$multikey =~ s/^<!M><~space><A>$/E6F1/;
	$multikey =~ s/^<!M><~space><a>$/E6F2/;
	$multikey =~ s/^<!M><~space><A><%underscore>$/E6F3/;
	$multikey =~ s/^<!M><~space><b>$/E6F4/;
	$multikey =~ s/^<!M><~space><c>$/E6F5/;
	$multikey =~ s/^<!M><~space><c><%backslash>$/E6F6/;
	$multikey =~ s/^<!M><~space><c><c>$/E6F7/;
	$multikey =~ s/^<!M><~space><e>$/E6F8/;
	$multikey =~ s/^<!M><~space><e><e>$/E6F9/;
	$multikey =~ s/^<!M><~space><e><e><%bar>$/E6FA/;
	$multikey =~ s/^<!M><~space><n>$/E6FB/;
	$multikey =~ s/^<!M><~space><o>$/E6FC/;
	$multikey =~ s/^<!M><~space><O>$/E6FD/;
	$multikey =~ s/^<!M><~space><o><%minus>$/E6FE/;
	$multikey =~ s/^<!M><~space><R>$/E6FF/;
	$multikey =~ s/^<!M><~space><r>$/E700/;
	$multikey =~ s/^<!M><~space><S>$/E701/;
	$multikey =~ s/^<!M><~space><S><S>$/E702/;
	$multikey =~ s/^<!M><~space><T>$/E703/;
	$multikey =~ s/^<!M><~space><V>$/E704/;
	$multikey =~ s/^<!M><~space><Y>$/E705/;
	$multikey =~ s/^<!M><~space><~space>$/E706/;
	$multikey =~ s/^<!M><~space><~space><%backslash>$/E707/;
	$multikey =~ s/^<!M><~space><~space><%bar>$/E708/;
	$multikey =~ s/^<!M><~space><~space><%bracketleft>$/E709/;
	$multikey =~ s/^<!M><~space><~space><%bracketright>$/E70A/;
	$multikey =~ s/^<!M><~space><~space><%equal>$/E70B/;
	$multikey =~ s/^<!M><~space><~space><%greater>$/E70C/;
	$multikey =~ s/^<!M><~space><~space><%less>$/E70D/;
	$multikey =~ s/^<!M><~space><~space><%minus>$/E70E/;
	$multikey =~ s/^<!M><~space><~space><%slash>$/E70F/;
	$multikey =~ s/^<!M><~space><~space><3>$/E710/;
	$multikey =~ s/^<!M><~space><~space><o>$/E711/;
	$multikey =~ s/^<!M><~space><~space><T>$/E712/;
	$multikey =~ s/^<!M><~space><~space><~space>$/E713/;
	$multikey =~ s/^<!M><~space><~space><~space><%asterisk>$/E714/;
	$multikey =~ s/^<!M><~space><~space><~space><~space>$/E715/;

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
print( "multikey_parsed has " . @multikey_parsed . " elements.\n" );
print CONSOLE ( "multikey_parsed has " . @multikey_parsed . " elements.\n" );
my $counter = 0;
foreach my $entry ( @multikey_parsed ) {
	do {
		$entry =~ m/^(<.+>)<.+>$/;
		$preceding = $1;
		# This should work better than "unless ( grep { /^\Q$preceding$/ } @multikey_complete ) {".
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
print( "Adding missing links to multikey chains complete.\n" );
print CONSOLE ( "Adding missing links to multikey chains complete.\n" );

# Add missing links to multikey equivalent chains.
print( "Adding missing links to multikey equivalent chains in progress ---\n" );
print CONSOLE ( "Adding missing links to multikey equivalent chains in progress ---\n" );
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
				$high_out     = 'High surrogate: ' . $high_su . '; ';
				$uplus_output = 'U+' . $output_code . ' ';
				$output_code  = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
				++$half;
				print LOG $high_su . ', ' . $deadkey . "\n";

			} else {
				$uplus_output = 'U+' . $output_code . ' ';
				$high_out     = '';
				++$full;
			}

			# Generate annotated DEADTRANS call.
			$print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $uplus_output . $comment . "\n";
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

			# Convert SMP characters to surrogate pairs.
			if ( $output_code =~ /[0-9A-F]{5}/ ) {
				$high_su = sprintf( "%X", ( 55232 + int( hex( $output_code ) / 1024 ) ) );
				unless ( grep( /^$high_su$/, @high_surrogates ) ) {
					push( @high_surrogates, $high_su );
				}
				$high_out     = 'High surrogate: ' . $high_su . '; ';
				$uplus_output = 'U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
				++$half;
				print LOG $high_su . ', ' . $deadkey . "\n";

			} else {
				$uplus_output = 'U+' . $output_code . ' ';
				$high_out     = '';
				++$full;
			}

			$length = length( $full_chain );
			if ( $length > 65 ) {
				$length = 65;
				++$overlong;
			}
			$print = '/*' . $full_chain . ( " " x ( 65 - $length ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $uplus_output . $comment . "\n";
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

print REPORT ( "\n\n\nThis is the list of " . @multikey_dchars . " intermediate multikey chains with their dead character:\n\n" );
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

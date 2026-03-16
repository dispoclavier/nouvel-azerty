#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-10-23T2145+0200
# 2025-11-15T0554+0100
# 2025-12-23T0450+0100
# 2025-12-25T0221+0100
# 2025-12-31T1259+0100
# 2026-01-26T0514+0100
# 2026-03-04T1042+0100
# 2026-03-16T1433+0100
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
# intermediate chain. Missing dead key chains are reported in dead-keys.txt.
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
# Multikey sequences need to be processed separately, as they are unrelated to,
# or not congruent with, the dead key output: About 160 multikey equivalents
# are commented out due to conflicts.
#
# Dedicated multikey sequences are an indispensable part of the keyboard layout
# and are the only sustainable input method for precomposed fractions, as well
# as for most mathematical symbols. After an attempt to support all multikey
# sequences on 2025-11-12, the subset of the dedicated multikey sequences is
# ultimately supported since 2025-12-22, and the transpiler was fixed from
# 2025-12-24 until 2026-03-03.
#
# Multikey equivalents of dead keys, by contrast, are an XCompose feature for
# incomplete keyboard layouts. As a consequence, these are sort of optional.
# Supporting all available multikey equivalents of dead key chains on Windows
# causes issues progressively, when exceeding some layout driver file size
# threshold. Not 256 kB; issues also occur at 243 kB and 244 kB, but not at
# 231 kB. The affected layout does not show up in the Language bar, and if it
# is the default, the keyboard does not work in some of the applications.
# VSCode is affected, but the Windows File Explorer is not. Additionally,
# a vendor-specific touchpad driver may be deactivated. This affects the
# Touchpad Dell and its driver GlidePoint® provided by ALPSALPINE Co., Ltd,
# v.10.3201.101.121 (https://dl.dell.com/FOLDER06037821M/6/Dell-Touchpad-Driver_18D77_WIN_10.3201.101.215_A08_03.EXE).
#
# As multikey equivalents may increase the DLL file size from 219 to 289 kB,
# half of the equivalents could still be supported. As a compromise, only
# unchained dead keys may have their multikey equivalent supported.
#
# However, on Windows, the dead characters cannot be in sync with those of
# dead key chains, because if they were, the commented-out multikey equivalents
# would be uncommented, and the conflicts would break part of the sequences.
#
# Given that supporting all multikey equivalents breaks the layout drivers and
# the OS, keeping the source code file size below the 2MB file size limit of
# github.com is not mandatory. Yet, when skipping all equivalents, it happens.
#
# Even for all equivalents, using private use characters, all the intermediate
# chains can be supported, as the first area E000..F8FF encompassing 6400 code
# points is not used up by dedicated multikey sequences, and not even when
# multikey equivalents are added. On 2025-12-22, a set of 1302 intermediate
# multikey chains used E201..E715. The full set of 2357 intermediate multikey
# chains with multikey equivalents of dead keys used E200..EAAF (2026-01-03).
#
# For test purposes, this can be toggled here by replacing false (!1) with
# true (!0):
my $support_simple_multikey_equivalents = !1;
my $support_all_multikey_equivalents    = !1;
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
# The 8 required high surrogates are:
#
#     D801, D807,
#     D833, D835, D837,
#     D83C, D83D, D83E.
#
# These are dispatched among dead keys:
#
#     D801 dead_superscript (modifier letters)
#     D807 dead_turned (U+11FB0 "𑾰" LISU LETTER YHA)
#     D833 dead_breve (mathematical arrows)
#     D835 dead_group (mathematical alphanumeric symbols)
#     D837 dead_bar; dead_hook; dead_retroflexhook; others (Latin)
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
my $multikey_count    = 0;
my @multikey_dchars   = ();
my @multikey_print    = ();
my ( $chain, $comment, $deadchar, $deadkey, $full_chain, $high_out, $high_su, $input, $input_string, $length,
		$output_code, $output_string, $preceding, $print, $uplus_output );
my $keysym            = '%ampersand';
my $multikey          = '<!M>';

sub format_character {
	my ( $character ) = @_;
	if ( length( $character ) < 7 ) {
		$character =~ s/<([^>]+)>/$1/;
		$character =~ s/<>>/>/;
	}
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
	$keysym =~ s/%quotEuroSign/20AC/;
	$keysym =~ s/%hash/#/;
	$keysym =~ s/%dollar/\$/;
	$keysym =~ s/%percent/%/;
	$keysym =~ s/%ampersand/&/;
	$keysym =~ s/%apostrophe/\\'/;
	$keysym =~ s/%aprightsingquotmark/2019/;
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
	$keysym =~ s/%excsection/00A7/;
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

my @dead_key_characters = (

	# Intermediate dead key chain links (575).
	'<!abovedot><!abovedot>➔02C8',#<dead_abovedot><dead_abovedot>
	'<!abovedot><!abovedot><!acute>➔02C7',#<dead_abovedot><dead_abovedot><dead_acute>
	'<!abovedot><!abovedot><!acute><!grave>➔02B7',#<dead_abovedot><dead_abovedot><dead_acute><dead_grave>
	'<!abovedot><!abovedot><!grave>➔02C6',#<dead_abovedot><dead_abovedot><dead_grave>
	'<!abovedot><!abovedot><!grave><!acute>➔1D50',#<dead_abovedot><dead_abovedot><dead_grave><dead_acute>
	'<!abovedot><!abovedot><!macron>➔1D38',#<dead_abovedot><dead_abovedot><dead_macron>
	'<!abovedot><!acute>➔1E64',#<dead_abovedot><dead_acute>
	'<!abovedot><!acute><!grave>➔1D3B',#<dead_abovedot><dead_acute><dead_grave>
	'<!abovedot><!bar>➔025F',#<dead_abovedot><UEFD8>
	'<!abovedot><!belowdot>➔1E68',#<dead_abovedot><dead_belowdot>
	'<!abovedot><!breve>➔A8F2',#<dead_abovedot><dead_breve>
	'<!abovedot><!caron>➔1E66',#<dead_abovedot><dead_caron>
	'<!abovedot><!grave>➔A718',#<dead_abovedot><dead_grave>
	'<!abovedot><!grave><!acute>➔1D3A',#<dead_abovedot><dead_grave><dead_acute>
	'<!abovedot><!group>➔1E9B',#<dead_abovedot><UEFD0>
	'<!abovedot><!group><!group>➔2A81',#<dead_abovedot><UEFD0><UEFD0>
	'<!abovedot><!group><!group><!group>➔2A6D',#<dead_abovedot><UEFD0><UEFD0><UEFD0>
	'<!abovedot><!group><3>➔2A6D',#<dead_abovedot><UEFD0><3>
	'<!abovedot><!macron>➔01E1',#<dead_abovedot><dead_macron>
	'<!abovehook><!abovehook>➔A7BB',#<UEFD3><UEFD3>
	'<!abovehook><!breve>➔1EB2',#<UEFD3><dead_breve>
	'<!abovehook><!circumflex>➔1EA9',#<UEFD3><dead_circumflex>
	'<!abovehook><!horn>➔1EDF',#<UEFD3><dead_horn>
	'<!abovering><!abovering>➔1E01',#<dead_abovering><dead_abovering>
	'<!abovering><!acute>➔01FB',#<dead_abovering><dead_acute>
	'<!abovering><!currency>➔222E',#<dead_abovering><dead_currency>
	'<!abovering><!diaeresis>➔02DA',#<dead_abovering><dead_diaeresis>
	'<!abovering><!group>➔AB4C',#<dead_abovering><UEFD0>
	'<!abovering><!group><!group>➔222F',#<dead_abovering><UEFD0><UEFD0>
	'<!abovering><!group><!group><!group>➔2230',#<dead_abovering><UEFD0><UEFD0><UEFD0>
	'<!abovering><!group><!group><!group><!group>➔AB4d',#<dead_abovering><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!abovering><!group><1>➔AB4f',#<dead_abovering><UEFD0><1>
	'<!abovering><!group><2>➔AB4b',#<dead_abovering><UEFD0><2>
	'<!abovering><!group><3>➔2230',#<dead_abovering><UEFD0><3>
	'<!abovering><!group><4>➔AB4d',#<dead_abovering><UEFD0><4>
	'<!abovering><!group><5>➔AB4e',#<dead_abovering><UEFD0><5>
	'<!acute><!abovedot>➔1E65',#<dead_acute><dead_abovedot>
	'<!acute><!abovedot><!abovedot>➔02BF',#<dead_acute><dead_abovedot><dead_abovedot>
	'<!acute><!abovering>➔01FA',#<dead_acute><dead_abovering>
	'<!acute><!acute>➔0171',#<dead_acute><dead_acute>
	'<!acute><!breve>➔1EAE',#<dead_acute><dead_breve>
	'<!acute><!cedilla>➔1E09',#<dead_acute><dead_cedilla>
	'<!acute><!circumflex>➔1EA5',#<dead_acute><dead_circumflex>
	'<!acute><!diaeresis>➔1E2E',#<dead_acute><dead_diaeresis>
	'<!acute><!grave>➔02C4',#<dead_acute><dead_grave>
	'<!acute><!grave><!macron>➔02DF',#<dead_acute><dead_grave><dead_macron>
	'<!acute><!group>➔01FD',#<dead_acute><UEFD0>
	'<!acute><!group><!group>➔275E',#<dead_acute><UEFD0><UEFD0>
	'<!acute><!horn>➔1EDA',#<dead_acute><dead_horn>
	'<!acute><!macron>➔1E16',#<dead_acute><dead_macron>
	'<!acute><!macron><!grave>➔02C9',#<dead_acute><dead_macron><dead_grave>
	'<!acute><!stroke>➔01FE',#<dead_acute><dead_stroke>
	'<!acute><!tilde>➔1E4C',#<dead_acute><dead_tilde>
	'<!bar><!abovedot>➔0284',#<UEFD8><dead_abovedot>
	'<!bar><!bar>➔A78A',#<UEFD8><UEFD8>
	'<!bar><!bar><!bar>➔02C2',#<UEFD8><UEFD8><UEFD8>
	'<!bar><!bar><!group>➔A767',#<UEFD8><UEFD8><UEFD0>
	'<!bar><!bar><!hook>➔0286',#<UEFD8><UEFD8><dead_hook>
	'<!bar><!bar><!hook><!hook>➔0283',#<UEFD8><UEFD8><dead_hook><dead_hook>
	'<!bar><!bar><!hook><!hook><!group>➔1D98',#<UEFD8><UEFD8><dead_hook><dead_hook><UEFD0>
	'<!bar><!group>➔1D7C',#<UEFD8><UEFD0>
	'<!bar><!group><!group>➔AB30',#<UEFD8><UEFD0><UEFD0>
	'<!bar><!group><!group><!group>➔1E9D',#<UEFD8><UEFD0><UEFD0><UEFD0>
	'<!bar><!group><3>➔1E9D',#<UEFD8><UEFD0><3>
	'<!bar><!hook>➔1D8B',#<UEFD8><dead_hook>
	'<!bar><!hook><!bar>➔0285',#<UEFD8><dead_hook><UEFD8>
	'<!bar><!hook><!bar><!hook>➔01AA',#<UEFD8><dead_hook><UEFD8><dead_hook>
	'<!bar><!hook><!bar><!hook><!group>➔0282',#<UEFD8><dead_hook><UEFD8><dead_hook><UEFD0>
	'<!bar><!hook><!hook>➔01A9',#<UEFD8><dead_hook><dead_hook>
	'<!bar><!hook><!hook><!bar>➔0287',#<UEFD8><dead_hook><dead_hook><UEFD8>
	'<!bar><!hook><!hook><!bar><!group>➔0288',#<UEFD8><dead_hook><dead_hook><UEFD8><UEFD0>
	'<!bar><!retroflexhook>➔0268',#<UEFD8><UEFD4>
	'<!bar><!reversed>➔029E',#<UEFD8><UEFD6>
	'<!bar><!stroke>➔A745',#<UEFD8><dead_stroke>
	'<!bar><!subscript>➔1D03',#<UEFD8><UEFD2>
	'<!bar><!superscript>➔02A1',#<UEFD8><UEFD1>
	'<!bar><!superscript><!group>➔1D2F',#<UEFD8><UEFD1><UEFD0>
	'<!bar><!turned>➔2013',#<UEFD8><UEFD5>
	'<!bar><!turned><!group>➔0153',#<UEFD8><UEFD5><UEFD0>
	'<!belowcomma><!belowcomma>➔02BC',#<dead_belowcomma><dead_belowcomma>
	'<!belowcomma><!group>➔A72F',#<dead_belowcomma><UEFD0>
	'<!belowcomma><!group><!group>➔A72E',#<dead_belowcomma><UEFD0><UEFD0>
	'<!belowcomma><!group><!group><!group>➔A72D',#<dead_belowcomma><UEFD0><UEFD0><UEFD0>
	'<!belowcomma><!group><!group><!group><!group>➔A72C',#<dead_belowcomma><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!belowcomma><!group><3>➔A72D',#<dead_belowcomma><UEFD0><3>
	'<!belowcomma><!group><4>➔A72C',#<dead_belowcomma><UEFD0><4>
	'<!belowcomma><!group><5>➔A72B',#<dead_belowcomma><UEFD0><5>
	'<!belowdot><!abovedot>➔1E69',#<dead_belowdot><dead_abovedot>
	'<!belowdot><!belowdot>➔02CC',#<dead_belowdot><dead_belowdot>
	'<!belowdot><!breve>➔1EB6',#<dead_belowdot><dead_breve>
	'<!belowdot><!circumflex>➔1EAD',#<dead_belowdot><dead_circumflex>
	'<!belowdot><!horn>➔1EE2',#<dead_belowdot><dead_horn>
	'<!belowdot><!macron>➔1E39',#<dead_belowdot><dead_macron>
	'<!breve><!abovedot>➔A8F3',#<dead_breve><dead_abovedot>
	'<!breve><!abovehook>➔1EB3',#<dead_breve><UEFD3>
	'<!breve><!acute>➔1EAF',#<dead_breve><dead_acute>
	'<!breve><!belowdot>➔1EB7',#<dead_breve><dead_belowdot>
	'<!breve><!breve>➔1E2B',#<dead_breve><dead_breve>
	'<!breve><!breve><!retroflexhook>➔026D',#<dead_breve><dead_breve><UEFD4>
	'<!breve><!breve><!retroflexhook><!retroflexhook>➔026C',#<dead_breve><dead_breve><UEFD4><UEFD4>
	'<!breve><!breve><!subscript>➔1DAB',#<dead_breve><dead_breve><UEFD2>
	'<!breve><!breve><!superscript>➔028E',#<dead_breve><dead_breve><UEFD1>
	'<!breve><!breve><!turned>➔028C',#<dead_breve><dead_breve><UEFD5>
	'<!breve><!cedilla>➔1E1D',#<dead_breve><dead_cedilla>
	'<!breve><!grave>➔1EB1',#<dead_breve><dead_grave>
	'<!breve><!macron>➔02D8',#<dead_breve><dead_macron>
	'<!breve><!retroflexhook>➔A78D',#<dead_breve><UEFD4>
	'<!breve><!retroflexhook><!breve>➔026B',#<dead_breve><UEFD4><dead_breve>
	'<!breve><!retroflexhook><!breve><!retroflexhook>➔026E',#<dead_breve><UEFD4><dead_breve><UEFD4>
	'<!breve><!retroflexhook><!retroflexhook>➔1D85',#<dead_breve><UEFD4><UEFD4>
	'<!breve><!retroflexhook><!retroflexhook><!breve>➔0269',#<dead_breve><UEFD4><UEFD4><dead_breve>
	'<!breve><!subscript>➔029F',#<dead_breve><UEFD2>
	'<!breve><!subscript><!breve>➔1DA9',#<dead_breve><UEFD2><dead_breve>
	'<!breve><!superscript>➔1DAA',#<dead_breve><UEFD1>
	'<!breve><!superscript><!breve>➔1DA1',#<dead_breve><UEFD1><dead_breve>
	'<!breve><!tilde>➔1EB5',#<dead_breve><dead_tilde>
	'<!breve><!turned>➔028D',#<dead_breve><UEFD5>
	'<!breve><!turned><!breve>➔028F',#<dead_breve><UEFD5><dead_breve>
	'<!caron><!abovedot>➔1E67',#<dead_caron><dead_abovedot>
	'<!caron><!caron>➔02EC',#<dead_caron><dead_caron>
	'<!caron><!diaeresis>➔01D9',#<dead_caron><dead_diaeresis>
	'<!caron><!group>➔01EF',#<dead_caron><UEFD0>
	'<!cedilla><!acute>➔1E08',#<dead_cedilla><dead_acute>
	'<!cedilla><!breve>➔1E1C',#<dead_cedilla><dead_breve>
	'<!cedilla><!cedilla>➔02BB',#<dead_cedilla><dead_cedilla>
	'<!circumflex><!abovehook>➔1EA8',#<dead_circumflex><UEFD3>
	'<!circumflex><!acute>➔1EA4',#<dead_circumflex><dead_acute>
	'<!circumflex><!belowdot>➔1EAC',#<dead_circumflex><dead_belowdot>
	'<!circumflex><!circumflex>➔01CD',#<dead_circumflex><dead_circumflex>
	'<!circumflex><!circumflex><!circumflex>➔1E19',#<dead_circumflex><dead_circumflex><dead_circumflex>
	'<!circumflex><!grave>➔1EA7',#<dead_circumflex><dead_grave>
	'<!circumflex><!group>➔2A6F',#<dead_circumflex><UEFD0>
	'<!circumflex><!group><!group>➔2661',#<dead_circumflex><UEFD0><UEFD0>
	'<!circumflex><!group><!group><!group>➔2667',#<dead_circumflex><UEFD0><UEFD0><UEFD0>
	'<!circumflex><!group><!group><!group><!group>➔2662',#<dead_circumflex><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!circumflex><!group><3>➔2667',#<dead_circumflex><UEFD0><3>
	'<!circumflex><!group><4>➔2662',#<dead_circumflex><UEFD0><4>
	'<!circumflex><!group><5>➔2663',#<dead_circumflex><UEFD0><5>
	'<!circumflex><!tilde>➔1EAB',#<dead_circumflex><dead_tilde>
	'<!currency><!abovering>➔2232',#<dead_currency><dead_abovering>
	'<!currency><!cedilla>➔20B5',#<dead_currency><dead_cedilla>
	'<!currency><!currency>➔09F2',#<dead_currency><dead_currency>
	'<!diaeresis><!abovering>➔00A8',#<dead_diaeresis><dead_abovering>
	'<!diaeresis><!acute>➔1E2F',#<dead_diaeresis><dead_acute>
	'<!diaeresis><!caron>➔01DA',#<dead_diaeresis><dead_caron>
	'<!diaeresis><!diaeresis>➔010E',#<dead_diaeresis><dead_diaeresis>
	'<!diaeresis><!diaeresis><!diaeresis>➔1E73',#<dead_diaeresis><dead_diaeresis><dead_diaeresis>
	'<!diaeresis><!grave>➔01DC',#<dead_diaeresis><dead_grave>
	'<!diaeresis><!group>➔275F',#<dead_diaeresis><UEFD0>
	'<!diaeresis><!group><!group>➔2760',#<dead_diaeresis><UEFD0><UEFD0>
	'<!diaeresis><!macron>➔01D6',#<dead_diaeresis><dead_macron>
	'<!diaeresis><!superscript>➔00E4',#<dead_diaeresis><UEFD1>
	'<!diaeresis><!superscript><!superscript>➔00F6',#<dead_diaeresis><UEFD1><UEFD1>
	'<!diaeresis><!tilde>➔1E4E',#<dead_diaeresis><dead_tilde>
	'<!diaeresis><!turned>➔00FC',#<dead_diaeresis><UEFD5>
	'<!diaeresis><!turned><!turned>➔00DC',#<dead_diaeresis><UEFD5><UEFD5>
	'<!doubleacute><!doubleacute>➔2034',#<dead_doubleacute><dead_doubleacute>
	'<!doubleacute><!reversed>➔263B',#<dead_doubleacute><UEFD6>
	'<!flag><!flag>➔2691',#<UEFD7><UEFD7>
	'<!flag><!flag><!flag>➔003D',#<UEFD7><UEFD7><UEFD7>
	'<!flag><!group>➔2E40',#<UEFD7><UEFD0>
	'<!flag><!group><!group>➔22BC',#<UEFD7><UEFD0><UEFD0>
	'<!flag><!group><!group><!group>➔2287',#<UEFD7><UEFD0><UEFD0><UEFD0>
	'<!flag><!group><3>➔2287',#<UEFD7><UEFD0><3>
	'<!grave><!abovedot>➔A717',#<dead_grave><dead_abovedot>
	'<!grave><!abovedot><!abovedot>➔2301',#<dead_grave><dead_abovedot><dead_abovedot>
	'<!grave><!acute>➔02C5',#<dead_grave><dead_acute>
	'<!grave><!acute><!macron>➔2305',#<dead_grave><dead_acute><dead_macron>
	'<!grave><!breve>➔1EB0',#<dead_grave><dead_breve>
	'<!grave><!circumflex>➔1EA6',#<dead_grave><dead_circumflex>
	'<!grave><!diaeresis>➔01DB',#<dead_grave><dead_diaeresis>
	'<!grave><!grave>➔0201',#<dead_grave><dead_grave>
	'<!grave><!horn>➔1EDC',#<dead_grave><dead_horn>
	'<!grave><!macron>➔1E14',#<dead_grave><dead_macron>
	'<!grave><!macron><!acute>➔2306',#<dead_grave><dead_macron><dead_acute>
	'<!greek><!greek>➔229A',#<dead_greek><dead_greek>
	'<!greek><!subscript>➔1D66',#<dead_greek><UEFD2>
	'<!greek><%backslash>➔277F',#<dead_greek><backslash>
	'<!greek><%backslash><%quotEuroSign>➔24EB',#<dead_greek><backslash><EuroSign>
	'<!greek><%backslash><%quotedbl>➔24EC',#<dead_greek><backslash><quotedbl>
	'<!greek><%backslash><%tilde>➔278A',#<dead_greek><backslash><asciitilde>
	'<!greek><%bracketleft>➔2792',#<dead_greek><bracketleft>
	'<!greek><%quotEuroSign>➔2473',#<dead_greek><EuroSign>
	'<!greek><%quotEuroSign><%backslash>➔24F4',#<dead_greek><EuroSign><backslash>
	'<!greek><%quotedbl>➔246E',#<dead_greek><quotedbl>
	'<!greek><%quotedbl><%backslash>➔24F3',#<dead_greek><quotedbl><backslash>
	'<!greek><%tilde>➔2789',#<dead_greek><asciitilde>
	'<!greek><%tilde><%backslash>➔2793',#<dead_greek><asciitilde><backslash>
	'<!group><!group>➔2461',#<UEFD0><UEFD0>
	'<!group><!group><!group>➔2462',#<UEFD0><UEFD0><UEFD0>
	'<!group><!group><!group><!group>➔2463',#<UEFD0><UEFD0><UEFD0><UEFD0>
	'<!group><0>➔2469',#<UEFD0><0>
	'<!group><0><%comma>➔213F',#<UEFD0><0><comma>
	'<!group><0><%comma><%period>➔2145',#<UEFD0><0><comma><period>
	'<!group><0><%period>➔2115',#<UEFD0><0><period>
	'<!group><0><%period><%comma>➔2145',#<UEFD0><0><period><comma>
	'<!group><1>➔246A',#<UEFD0><1>
	'<!group><2>➔246B',#<UEFD0><2>
	'<!group><3>➔2462',#<UEFD0><3>
	'<!group><4>➔2463',#<UEFD0><4>
	'<!group><5>➔2464',#<UEFD0><5>
	'<!group><6>➔2465',#<UEFD0><6>
	'<!group><6><%comma>➔213E',#<UEFD0><6><comma>
	'<!group><6><%comma><%comma>➔2140',#<UEFD0><6><comma><comma>
	'<!group><6><%comma><%comma><%period>➔2141',#<UEFD0><6><comma><comma><period>
	'<!group><6><%comma><%period>➔213D',#<UEFD0><6><comma><period>
	'<!group><6><%comma><%period><%comma>➔2141',#<UEFD0><6><comma><period><comma>
	'<!group><6><%period>➔2147',#<UEFD0><6><period>
	'<!group><6><%period><%comma>➔213D',#<UEFD0><6><period><comma>
	'<!group><6><%period><%comma><%comma>➔2141',#<UEFD0><6><period><comma><comma>
	'<!group><7>➔2466',#<UEFD0><7>
	'<!group><7><%comma>➔212C',#<UEFD0><7><comma>
	'<!group><7><%period>➔2148',#<UEFD0><7><period>
	'<!group><8>➔2467',#<UEFD0><8>
	'<!group><8><%comma>➔211D',#<UEFD0><8><comma>
	'<!group><8><%comma><%period>➔2148',#<UEFD0><8><comma><period>
	'<!group><8><%period>➔210E',#<UEFD0><8><period>
	'<!group><8><%period><%comma>➔2148',#<UEFD0><8><period><comma>
	'<!group><9>➔2468',#<UEFD0><9>
	'<!group><9><%comma>➔2111',#<UEFD0><9><comma>
	'<!group><9><%period>➔2102',#<UEFD0><9><period>
	'<!group><ellipsis>➔263C',#<UEFD0><ellipsis>
	'<!hook><!bar>➔AB3A',#<dead_hook><UEFD8>
	'<!hook><!bar><!bar>➔027D',#<dead_hook><UEFD8><UEFD8>
	'<!hook><!bar><!bar><!hook>➔0278',#<dead_hook><UEFD8><UEFD8><dead_hook>
	'<!hook><!bar><!bar><!hook><!group>➔027C',#<dead_hook><UEFD8><UEFD8><dead_hook><UEFD0>
	'<!hook><!bar><!hook>➔027F',#<dead_hook><UEFD8><dead_hook>
	'<!hook><!bar><!hook><!bar>➔0279',#<dead_hook><UEFD8><dead_hook><UEFD8>
	'<!hook><!bar><!hook><!bar><!group>➔0280',#<dead_hook><UEFD8><dead_hook><UEFD8><UEFD0>
	'<!hook><!group>➔0267',#<dead_hook><UEFD0>
	'<!hook><!group><!group>➔01BA',#<dead_hook><UEFD0><UEFD0>
	'<!hook><!group><!group><!group>➔1D94',#<dead_hook><UEFD0><UEFD0><UEFD0>
	'<!hook><!group><3>➔1D94',#<dead_hook><UEFD0><3>
	'<!hook><!hook>➔0255',#<dead_hook><dead_hook>
	'<!hook><!hook><!bar>➔0257',#<dead_hook><dead_hook><UEFD8>
	'<!hook><!hook><!bar><!bar>➔0256',#<dead_hook><dead_hook><UEFD8><UEFD8>
	'<!hook><!hook><!bar><!bar><!group>➔0253',#<dead_hook><dead_hook><UEFD8><UEFD8><UEFD0>
	'<!hook><!hook><!group>➔02A5',#<dead_hook><dead_hook><UEFD0>
	'<!hook><!hook><!group><!group>➔AB36',#<dead_hook><dead_hook><UEFD0><UEFD0>
	'<!hook><!hook><!group><!group><!group>➔AB4A',#<dead_hook><dead_hook><UEFD0><UEFD0><UEFD0>
	'<!hook><!hook><!group><!group><!group><!group>➔02A8',#<dead_hook><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!hook><!hook><!group><3>➔AB4A',#<dead_hook><dead_hook><UEFD0><3>
	'<!hook><!hook><!group><4>➔02A8',#<dead_hook><dead_hook><UEFD0><4>
	'<!hook><!hook><!group><5>➔02A7',#<dead_hook><dead_hook><UEFD0><5>
	'<!hook><!hook><!hook>➔A796',#<dead_hook><dead_hook><dead_hook>
	'<!hook><!hook><!superscript>➔1DA8',#<dead_hook><dead_hook><UEFD1>
	'<!hook><!hook><!superscript><!group>➔02A4',#<dead_hook><dead_hook><UEFD1><UEFD0>
	'<!hook><!hook><!superscript><!group><!group>➔02A3',#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0>
	'<!hook><!hook><!superscript><!group><!group><!group>➔02B0',#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0><UEFD0>
	'<!hook><!hook><!superscript><!group><!group><!group><!group>➔02B1',#<dead_hook><dead_hook><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!hook><!hook><!superscript><!group><3>➔02B0',#<dead_hook><dead_hook><UEFD1><UEFD0><3>
	'<!hook><!hook><!superscript><!group><4>➔02B1',#<dead_hook><dead_hook><UEFD1><UEFD0><4>
	'<!hook><!hook><!superscript><!group><5>➔02B2',#<dead_hook><dead_hook><UEFD1><UEFD0><5>
	'<!hook><!hook><!turned>➔028A',#<dead_hook><dead_hook><UEFD5>
	'<!hook><!hook><!turned><!turned>➔0296',#<dead_hook><dead_hook><UEFD5><UEFD5>
	'<!hook><!retroflexhook>➔1D91',#<dead_hook><UEFD4>
	'<!hook><!retroflexhook><!retroflexhook>➔01AB',#<dead_hook><UEFD4><UEFD4>
	'<!hook><!retroflexhook><!turned>➔02AF',#<dead_hook><UEFD4><UEFD5>
	'<!hook><!reversed>➔025D',#<dead_hook><UEFD6>
	'<!hook><!reversed><!group>➔025C',#<dead_hook><UEFD6><UEFD0>
	'<!hook><!reversed><!group><!group>➔025E',#<dead_hook><UEFD6><UEFD0><UEFD0>
	'<!hook><!subscript>➔029B',#<dead_hook><UEFD2>
	'<!hook><!superscript>➔1D9D',#<dead_hook><UEFD1>
	'<!hook><!superscript><!group>➔1DAC',#<dead_hook><UEFD1><UEFD0>
	'<!hook><!superscript><!hook>➔1DBD',#<dead_hook><UEFD1><dead_hook>
	'<!hook><!superscript><!hook><!group>➔1DBF',#<dead_hook><UEFD1><dead_hook><UEFD0>
	'<!hook><!superscript><!hook><!group><!group>➔1DBE',#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0>
	'<!hook><!superscript><!hook><!group><!group><!group>➔1DBC',#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0><UEFD0>
	'<!hook><!superscript><!hook><!group><!group><!group><!group>➔1DBA',#<dead_hook><UEFD1><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!hook><!superscript><!hook><!group><3>➔1DBC',#<dead_hook><UEFD1><dead_hook><UEFD0><3>
	'<!hook><!superscript><!hook><!group><4>➔1DBA',#<dead_hook><UEFD1><dead_hook><UEFD0><4>
	'<!hook><!superscript><!hook><!group><5>➔1DB9',#<dead_hook><UEFD1><dead_hook><UEFD0><5>
	'<!hook><!superscript><!turned>➔02B5',#<dead_hook><UEFD1><UEFD5>
	'<!hook><!tilde>➔1D73',#<dead_hook><dead_tilde>
	'<!hook><!turned>➔01BE',#<dead_hook><UEFD5>
	'<!hook><!turned><!hook>➔0295',#<dead_hook><UEFD5><dead_hook>
	'<!hook><!turned><!hook><!turned>➔0294',#<dead_hook><UEFD5><dead_hook><UEFD5>
	'<!hook><!turned><!retroflexhook>➔02AE',#<dead_hook><UEFD5><UEFD4>
	'<!hook><!turned><!superscript>➔02B8',#<dead_hook><UEFD5><UEFD1>
	'<!hook><!turned><!turned>➔02C0',#<dead_hook><UEFD5><UEFD5>
	'<!hook><!turned><!turned><!hook>➔02C1',#<dead_hook><UEFD5><UEFD5><dead_hook>
	'<!horn><!abovehook>➔1EDE',#<dead_horn><UEFD3>
	'<!horn><!acute>➔1EDB',#<dead_horn><dead_acute>
	'<!horn><!belowdot>➔1EE3',#<dead_horn><dead_belowdot>
	'<!horn><!grave>➔1EDD',#<dead_horn><dead_grave>
	'<!horn><!horn>➔29FA',#<dead_horn><dead_horn>
	'<!abovering><!circumflex>➔1E18',#<dead_abovering><dead_circumflex>
	'<!circumflex><!abovering>➔1E18',#<dead_circumflex><dead_abovering>
	'<!horn><!tilde>➔1EE1',#<dead_horn><dead_tilde>
	'<!invertedbreve><!group>➔02A9',#<dead_invertedbreve><UEFD0>
	'<!invertedbreve><!group><!group>➔0238',#<dead_invertedbreve><UEFD0><UEFD0>
	'<!invertedbreve><!group><!group><!group>➔0239',#<dead_invertedbreve><UEFD0><UEFD0><UEFD0>
	'<!invertedbreve><!group><!group><!group><!group>➔023A',#<dead_invertedbreve><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!invertedbreve><!group><1>➔023C',#<dead_invertedbreve><UEFD0><1>
	'<!invertedbreve><!group><3>➔0239',#<dead_invertedbreve><UEFD0><3>
	'<!invertedbreve><!group><4>➔023A',#<dead_invertedbreve><UEFD0><4>
	'<!invertedbreve><!group><5>➔023B',#<dead_invertedbreve><UEFD0><5>
	'<!invertedbreve><!invertedbreve>➔1D16',#<dead_invertedbreve><dead_invertedbreve>
	'<!macron><!abovedot>➔01E0',#<dead_macron><dead_abovedot>
	'<!macron><!abovedot><!abovedot>➔02D4',#<dead_macron><dead_abovedot><dead_abovedot>
	'<!macron><!acute>➔1E17',#<dead_macron><dead_acute>
	'<!macron><!acute><!grave>➔02CA',#<dead_macron><dead_acute><dead_grave>
	'<!macron><!belowdot>➔1E38',#<dead_macron><dead_belowdot>
	'<!macron><!breve>➔02D7',#<dead_macron><dead_breve>
	'<!macron><!diaeresis>➔1E7B',#<dead_macron><dead_diaeresis>
	'<!macron><!grave>➔1E15',#<dead_macron><dead_grave>
	'<!macron><!grave><!acute>➔02CD',#<dead_macron><dead_grave><dead_acute>
	'<!macron><!group>➔01E3',#<dead_macron><UEFD0>
	'<!macron><!group><!group>➔0297',#<dead_macron><UEFD0><UEFD0>
	'<!macron><!macron>➔1E07',#<dead_macron><dead_macron>
	'<!macron><!macron><!macron>➔2A60',#<dead_macron><dead_macron><dead_macron>
	'<!macron><!ogonek>➔01EC',#<dead_macron><dead_ogonek>
	'<!macron><!retroflexhook>➔02FD',#<dead_macron><UEFD4>
	'<!macron><!retroflexhook><!superscript>➔0271',#<dead_macron><UEFD4><UEFD1>
	'<!macron><!retroflexhook><!turned>➔0270',#<dead_macron><UEFD4><UEFD5>
	'<!macron><!superscript>➔02E5',#<dead_macron><UEFD1>
	'<!macron><!superscript><!retroflexhook>➔026F',#<dead_macron><UEFD1><UEFD4>
	'<!macron><!superscript><!turned>➔1DAD',#<dead_macron><UEFD1><UEFD5>
	'<!macron><!tilde>➔022C',#<dead_macron><dead_tilde>
	'<!macron><!turned>➔027A',#<dead_macron><UEFD5>
	'<!macron><!turned><!retroflexhook>➔0281',#<dead_macron><UEFD5><UEFD4>
	'<!macron><!turned><!superscript>➔0265',#<dead_macron><UEFD5><UEFD1>
	'<!ogonek><!macron>➔01ED',#<dead_ogonek><dead_macron>
	'<!ogonek><!ogonek>➔A71A',#<dead_ogonek><dead_ogonek>
	'<!retroflexhook><!bar>➔026A',#<UEFD4><UEFD8>
	'<!retroflexhook><!breve>➔A78E',#<UEFD4><dead_breve>
	'<!retroflexhook><!breve><!breve>➔A799',#<UEFD4><dead_breve><dead_breve>
	'<!retroflexhook><!breve><!breve><!retroflexhook>➔0264',#<UEFD4><dead_breve><dead_breve><UEFD4>
	'<!retroflexhook><!breve><!retroflexhook>➔0263',#<UEFD4><dead_breve><UEFD4>
	'<!retroflexhook><!breve><!retroflexhook><!breve>➔0260',#<UEFD4><dead_breve><UEFD4><dead_breve>
	'<!retroflexhook><!group>➔1D90',#<UEFD4><UEFD0>
	'<!retroflexhook><!group><!group>➔1D95',#<UEFD4><UEFD0><UEFD0>
	'<!retroflexhook><!group><!group><!group>➔1D93',#<UEFD4><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!group><!group><!group><!group>➔1D97',#<UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!group><3>➔1D93',#<UEFD4><UEFD0><3>
	'<!retroflexhook><!group><4>➔1D97',#<UEFD4><UEFD0><4>
	'<!retroflexhook><!group><5>➔AB67',#<UEFD4><UEFD0><5>
	'<!retroflexhook><!hook>➔1D8F',#<UEFD4><dead_hook>
	'<!retroflexhook><!hook><!retroflexhook>➔027E',#<UEFD4><dead_hook><UEFD4>
	'<!retroflexhook><!hook><!turned>➔02B3',#<UEFD4><dead_hook><UEFD5>
	'<!retroflexhook><!macron>➔02FE',#<UEFD4><dead_macron>
	'<!retroflexhook><!macron><!superscript>➔02B4',#<UEFD4><dead_macron><UEFD1>
	'<!retroflexhook><!macron><!turned>➔2A1B',#<UEFD4><dead_macron><UEFD5>
	'<!retroflexhook><!retroflexhook>➔1D80',#<UEFD4><UEFD4>
	'<!retroflexhook><!retroflexhook><!breve>➔A791',#<UEFD4><UEFD4><dead_breve>
	'<!retroflexhook><!retroflexhook><!breve><!breve>➔A790',#<UEFD4><UEFD4><dead_breve><dead_breve>
	'<!retroflexhook><!retroflexhook><!group>➔1D8C',#<UEFD4><UEFD4><UEFD0>
	'<!retroflexhook><!retroflexhook><!group><!group>➔025A',#<UEFD4><UEFD4><UEFD0><UEFD0>
	'<!retroflexhook><!retroflexhook><!group><!group><!group>➔02A6',#<UEFD4><UEFD4><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!retroflexhook><!group><!group><!group><!group>➔02AA',#<UEFD4><UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!retroflexhook><!group><3>➔02A6',#<UEFD4><UEFD4><UEFD0><3>
	'<!retroflexhook><!retroflexhook><!group><4>➔02AA',#<UEFD4><UEFD4><UEFD0><4>
	'<!retroflexhook><!retroflexhook><!group><5>➔02AB',#<UEFD4><UEFD4><UEFD0><5>
	'<!retroflexhook><!retroflexhook><!hook>➔0276',#<UEFD4><UEFD4><dead_hook>
	'<!retroflexhook><!retroflexhook><!retroflexhook>➔023F',#<UEFD4><UEFD4><UEFD4>
	'<!retroflexhook><!retroflexhook><!superscript>➔1DB5',#<UEFD4><UEFD4><UEFD1>
	'<!retroflexhook><!retroflexhook><!turned>➔2C79',#<UEFD4><UEFD4><UEFD5>
	'<!retroflexhook><!reversed>➔1D92',#<UEFD4><UEFD6>
	'<!retroflexhook><!reversed><!group>➔1D8A',#<UEFD4><UEFD6><UEFD0>
	'<!retroflexhook><!reversed><!group><!group>➔1D9F',#<UEFD4><UEFD6><UEFD0><UEFD0>
	'<!retroflexhook><!superscript>➔1DBB',#<UEFD4><UEFD1>
	'<!retroflexhook><!superscript><!group>➔1DAF',#<UEFD4><UEFD1><UEFD0>
	'<!retroflexhook><!superscript><!group><!group>➔1DB8',#<UEFD4><UEFD1><UEFD0><UEFD0>
	'<!retroflexhook><!superscript><!group><!group><!group>➔AB66',#<UEFD4><UEFD1><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!superscript><!group><!group><!group><!group>➔01C3',#<UEFD4><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!retroflexhook><!superscript><!group><3>➔AB66',#<UEFD4><UEFD1><UEFD0><3>
	'<!retroflexhook><!superscript><!group><4>➔01C3',#<UEFD4><UEFD1><UEFD0><4>
	'<!retroflexhook><!superscript><!group><5>➔01C2',#<UEFD4><UEFD1><UEFD0><5>
	'<!retroflexhook><!superscript><!macron>➔AB64',#<UEFD4><UEFD1><dead_macron>
	'<!retroflexhook><!superscript><!retroflexhook>➔1DAE',#<UEFD4><UEFD1><UEFD4>
	'<!retroflexhook><!turned>➔2C7B',#<UEFD4><UEFD5>
	'<!retroflexhook><!turned><!hook>➔02B6',#<UEFD4><UEFD5><dead_hook>
	'<!retroflexhook><!turned><!macron>➔0272',#<UEFD4><UEFD5><dead_macron>
	'<!retroflexhook><!turned><!retroflexhook>➔2C7A',#<UEFD4><UEFD5><UEFD4>
	'<!reversed><!bar>➔02A2',#<UEFD6><UEFD8>
	'<!reversed><!doubleacute>➔263A',#<UEFD6><dead_doubleacute>
	'<!reversed><!group>➔2B88',#<UEFD6><UEFD0>
	'<!reversed><!group><!group>➔A7AB',#<UEFD6><UEFD0><UEFD0>
	'<!reversed><!group><!group><!group>➔A7F6',#<UEFD6><UEFD0><UEFD0><UEFD0>
	'<!reversed><!group><!group><!group><!group>➔A7F5',#<UEFD6><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!reversed><!group><2>➔01B8',#<UEFD6><UEFD0><2>
	'<!reversed><!group><3>➔A7F6',#<UEFD6><UEFD0><3>
	'<!reversed><!group><4>➔A7F5',#<UEFD6><UEFD0><4>
	'<!reversed><!group><5>➔01B9',#<UEFD6><UEFD0><5>
	'<!reversed><!hook>➔0259',#<UEFD6><dead_hook>
	'<!reversed><!hook><!group>➔0258',#<UEFD6><dead_hook><UEFD0>
	'<!reversed><!hook><!group><!group>➔0252',#<UEFD6><dead_hook><UEFD0><UEFD0>
	'<!reversed><!retroflexhook>➔028B',#<UEFD6><UEFD4>
	'<!reversed><!retroflexhook><!group>➔0290',#<UEFD6><UEFD4><UEFD0>
	'<!reversed><!retroflexhook><!group><!group>➔0291',#<UEFD6><UEFD4><UEFD0><UEFD0>
	'<!reversed><!subscript>➔1D0E',#<UEFD6><UEFD2>
	'<!reversed><!superscript>➔02BD',#<UEFD6><UEFD1>
	'<!reversed><!superscript><!group>➔1D32',#<UEFD6><UEFD1><UEFD0>
	'<!reversed><!superscript><!group><!group>➔1D9E',#<UEFD6><UEFD1><UEFD0><UEFD0>
	'<!reversed><!superscript><!group><!group><!group>➔1D9C',#<UEFD6><UEFD1><UEFD0><UEFD0><UEFD0>
	'<!reversed><!superscript><!group><!group><!group><!group>➔1D9B',#<UEFD6><UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!reversed><!superscript><!group><3>➔1D9C',#<UEFD6><UEFD1><UEFD0><3>
	'<!reversed><!superscript><!group><4>➔1D9B',#<UEFD6><UEFD1><UEFD0><4>
	'<!reversed><!superscript><!group><5>➔1D9A',#<UEFD6><UEFD1><UEFD0><5>
	'<!stroke><!acute>➔01FF',#<dead_stroke><dead_acute>
	'<!stroke><!bar>➔A744',#<dead_stroke><UEFD8>
	'<!stroke><!group>➔019B',#<dead_stroke><UEFD0>
	'<!stroke><!group><!group>➔AB3F',#<dead_stroke><UEFD0><UEFD0>
	'<!stroke><!group><!group><!group>➔1E9C',#<dead_stroke><UEFD0><UEFD0><UEFD0>
	'<!stroke><!group><!group><!group><!group>➔A7DC',#<dead_stroke><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!stroke><!group><1>➔2270',#<dead_stroke><UEFD0><1>
	'<!stroke><!group><2>➔2271',#<dead_stroke><UEFD0><2>
	'<!stroke><!group><3>➔1E9C',#<dead_stroke><UEFD0><3>
	'<!stroke><!group><4>➔A7DC',#<dead_stroke><UEFD0><4>
	'<!stroke><!group><5>➔2262',#<dead_stroke><UEFD0><5>
	'<!stroke><!stroke>➔A7A1',#<dead_stroke><dead_stroke>
	'<!stroke><!stroke><!stroke>➔2425',#<dead_stroke><dead_stroke><dead_stroke>
	'<!stroke><!subscript>➔1D7E',#<dead_stroke><UEFD2>
	'<!stroke><!tilde>➔2241',#<dead_stroke><dead_tilde>
	'<!stroke><!turned>➔0152',#<dead_stroke><UEFD5>
	'<!stroke><!turned><!group>➔00E6',#<dead_stroke><UEFD5><UEFD0>
	'<!stroke><!turned><!group><!group>➔00C6',#<dead_stroke><UEFD5><UEFD0><UEFD0>
	'<!stroke><!turned><!group><!group><!group>➔A7F9',#<dead_stroke><UEFD5><UEFD0><UEFD0><UEFD0>
	'<!stroke><!turned><!group><3>➔A7F9',#<dead_stroke><UEFD5><UEFD0><3>
	'<!stroke><!turned><!turned>➔1D14',#<dead_stroke><UEFD5><UEFD5>
	'<!subscript><!bar>➔1D7B',#<UEFD2><UEFD8>
	'<!subscript><!breve>➔029C',#<UEFD2><dead_breve>
	'<!subscript><!breve><!breve>➔1DA7',#<UEFD2><dead_breve><dead_breve>
	'<!subscript><!greek>➔1D69',#<UEFD2><dead_greek>
	'<!subscript><!group>➔1D01',#<UEFD2><UEFD0>
	'<!subscript><!group><!group>➔2094',#<UEFD2><UEFD0><UEFD0>
	'<!subscript><!group><!group><!group>➔1D10',#<UEFD2><UEFD0><UEFD0><UEFD0>
	'<!subscript><!group><!group><!group><!group>➔1D2A',#<UEFD2><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!subscript><!group><3>➔1D10',#<UEFD2><UEFD0><3>
	'<!subscript><!group><4>➔1D2A',#<UEFD2><UEFD0><4>
	'<!subscript><!group><6>➔1D27',#<UEFD2><UEFD0><6>
	'<!subscript><!hook>➔AB46',#<UEFD2><dead_hook>
	'<!subscript><!reversed>➔A71F',#<UEFD2><UEFD6>
	'<!subscript><!stroke>➔1D0C',#<UEFD2><dead_stroke>
	'<!subscript><!subscript>➔2017',#<UEFD2><UEFD2>
	'<!subscript><!subscript><!turned>➔0292',#<UEFD2><UEFD2><UEFD5>
	'<!subscript><!superscript>➔1DA6',#<UEFD2><UEFD1>
	'<!subscript><!superscript><!group>➔1DB0',#<UEFD2><UEFD1><UEFD0>
	'<!subscript><!turned>➔A7FA',#<UEFD2><UEFD5>
	'<!subscript><!turned><!subscript>➔02CF',#<UEFD2><UEFD5><UEFD2>
	'<!subscript><!turned><!turned>➔1D1A',#<UEFD2><UEFD5><UEFD5>
	'<!superscript><!bar>➔A7F8',#<UEFD1><UEFD8>
	'<!superscript><!bar><!group>➔1DB6',#<UEFD1><UEFD8><UEFD0>
	'<!superscript><!breve>➔1DB1',#<UEFD1><dead_breve>
	'<!superscript><!breve><!breve>➔1DB2',#<UEFD1><dead_breve><dead_breve>
	'<!superscript><!diaeresis>➔00C4',#<UEFD1><dead_diaeresis>
	'<!superscript><!diaeresis><!superscript>➔1D40',#<UEFD1><dead_diaeresis><UEFD1>
	'<!superscript><!group>➔1D2D',#<UEFD1><UEFD0>
	'<!superscript><!group><!group>➔1D5D',#<UEFD1><UEFD0><UEFD0>
	'<!superscript><!group><!group><!group>➔1D45',#<UEFD1><UEFD0><UEFD0><UEFD0>
	'<!superscript><!group><!group><!group><!group>➔1D4A',#<UEFD1><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!superscript><!group><3>➔1D45',#<UEFD1><UEFD0><3>
	'<!superscript><!group><4>➔1D4A',#<UEFD1><UEFD0><4>
	'<!superscript><!group><5>➔1DA2',#<UEFD1><UEFD0><5>
	'<!superscript><!group><6>➔1D60',#<UEFD1><UEFD0><6>
	'<!superscript><!hook>➔1DB3',#<UEFD1><dead_hook>
	'<!superscript><!hook><!group>➔AB5F',#<UEFD1><dead_hook><UEFD0>
	'<!superscript><!hook><!hook>➔1DB7',#<UEFD1><dead_hook><dead_hook>
	'<!superscript><!hook><!hook><!group>➔1DB4',#<UEFD1><dead_hook><dead_hook><UEFD0>
	'<!superscript><!hook><!hook><!group><!group>➔1DA5',#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0>
	'<!superscript><!hook><!hook><!group><!group><!group>➔1DA4',#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0><UEFD0>
	'<!superscript><!hook><!hook><!group><!group><!group><!group>➔1DA3',#<UEFD1><dead_hook><dead_hook><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!superscript><!hook><!hook><!group><3>➔1DA4',#<UEFD1><dead_hook><dead_hook><UEFD0><3>
	'<!superscript><!hook><!hook><!group><4>➔1DA3',#<UEFD1><dead_hook><dead_hook><UEFD0><4>
	'<!superscript><!hook><!hook><!group><5>➔1DA0',#<UEFD1><dead_hook><dead_hook><UEFD0><5>
	'<!superscript><!hook><!turned>➔02AD',#<UEFD1><dead_hook><UEFD5>
	'<!superscript><!macron>➔02E6',#<UEFD1><dead_macron>
	'<!superscript><!macron><!retroflexhook>➔02AC',#<UEFD1><dead_macron><UEFD4>
	'<!superscript><!macron><!turned>➔1D99',#<UEFD1><dead_macron><UEFD5>
	'<!superscript><!retroflexhook>➔1D96',#<UEFD1><UEFD4>
	'<!superscript><!retroflexhook><!group>➔1D8E',#<UEFD1><UEFD4><UEFD0>
	'<!superscript><!retroflexhook><!group><!group>➔1D8D',#<UEFD1><UEFD4><UEFD0><UEFD0>
	'<!superscript><!retroflexhook><!group><!group><!group>➔1D89',#<UEFD1><UEFD4><UEFD0><UEFD0><UEFD0>
	'<!superscript><!retroflexhook><!group><!group><!group><!group>➔1D88',#<UEFD1><UEFD4><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!superscript><!retroflexhook><!group><3>➔1D89',#<UEFD1><UEFD4><UEFD0><3>
	'<!superscript><!retroflexhook><!group><4>➔1D88',#<UEFD1><UEFD4><UEFD0><4>
	'<!superscript><!retroflexhook><!group><5>➔1D87',#<UEFD1><UEFD4><UEFD0><5>
	'<!superscript><!retroflexhook><!macron>➔1D86',#<UEFD1><UEFD4><dead_macron>
	'<!superscript><!retroflexhook><!retroflexhook>➔1D84',#<UEFD1><UEFD4><UEFD4>
	'<!superscript><!reversed>➔1D83',#<UEFD1><UEFD6>
	'<!superscript><!reversed><!group>➔02E4',#<UEFD1><UEFD6><UEFD0>
	'<!superscript><!reversed><!group><!group>➔1D82',#<UEFD1><UEFD6><UEFD0><UEFD0>
	'<!superscript><!reversed><!group><!group><!group>➔1D81',#<UEFD1><UEFD6><UEFD0><UEFD0><UEFD0>
	'<!superscript><!reversed><!group><!group><!group><!group>➔1D7F',#<UEFD1><UEFD6><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!superscript><!reversed><!group><3>➔1D81',#<UEFD1><UEFD6><UEFD0><3>
	'<!superscript><!reversed><!group><4>➔1D7F',#<UEFD1><UEFD6><UEFD0><4>
	'<!superscript><!reversed><!group><5>➔1D7D',#<UEFD1><UEFD6><UEFD0><5>
	'<!superscript><!subscript>➔1D7A',#<UEFD1><UEFD2>
	'<!superscript><!subscript><!group>➔1D79',#<UEFD1><UEFD2><UEFD0>
	'<!superscript><!superscript>➔FE4C',#<UEFD1><UEFD1>
	'<!superscript><!superscript><!diaeresis>➔00D6',#<UEFD1><UEFD1><dead_diaeresis>
	'<!superscript><!superscript><!group>➔1D78',#<UEFD1><UEFD1><UEFD0>
	'<!superscript><!superscript><!group><!group>➔1D77',#<UEFD1><UEFD1><UEFD0><UEFD0>
	'<!superscript><!superscript><!group><2>➔1D76',#<UEFD1><UEFD1><UEFD0><2>
	'<!superscript><!tilde>➔AB5E',#<UEFD1><dead_tilde>
	'<!superscript><!turned>➔1D44',#<UEFD1><UEFD5>
	'<!superscript><!turned><!group>➔1D46',#<UEFD1><UEFD5><UEFD0>
	'<!superscript><!turned><!group><!group>➔1D4C',#<UEFD1><UEFD5><UEFD0><UEFD0>
	'<!superscript><!turned><!group><!group><!group>➔1D5A',#<UEFD1><UEFD5><UEFD0><UEFD0><UEFD0>
	'<!superscript><!turned><!group><3>➔1D5A',#<UEFD1><UEFD5><UEFD0><3>
	'<!superscript><!turned><!hook>➔02B9',#<UEFD1><UEFD5><dead_hook>
	'<!superscript><!turned><!macron>➔02BA',#<UEFD1><UEFD5><dead_macron>
	'<!superscript><!turned><!turned>➔A71E',#<UEFD1><UEFD5><UEFD5>
	'<!tilde><!acute>➔1E4D',#<dead_tilde><dead_acute>
	'<!tilde><!breve>➔1EB4',#<dead_tilde><dead_breve>
	'<!tilde><!circumflex>➔1EAA',#<dead_tilde><dead_circumflex>
	'<!tilde><!diaeresis>➔1E4F',#<dead_tilde><dead_diaeresis>
	'<!tilde><!hook>➔1D72',#<dead_tilde><dead_hook>
	'<!tilde><!horn>➔1EE0',#<dead_tilde><dead_horn>
	'<!tilde><!macron>➔022D',#<dead_tilde><dead_macron>
	'<!tilde><!stroke>➔2244',#<dead_tilde><dead_stroke>
	'<!tilde><!superscript>➔2245',#<dead_tilde><UEFD1>
	'<!tilde><!tilde>➔02F7',#<dead_tilde><dead_tilde>
	'<!tilde><!tilde><!tilde>➔AB38',#<dead_tilde><dead_tilde><dead_tilde>
	'<!tilde><!tilde><!turned>➔223F',#<dead_tilde><dead_tilde><UEFD5>
	'<!tilde><!turned>➔223D',#<dead_tilde><UEFD5>
	'<!tilde><!turned><!tilde>➔223C',#<dead_tilde><UEFD5><dead_tilde>
	'<!tilde><%ampersand>➔25B3',#<dead_tilde><ampersand>
	'<!turned><!bar>➔AB42',#<UEFD5><UEFD8>
	'<!turned><!bar><!group>➔AB43',#<UEFD5><UEFD8><UEFD0>
	'<!turned><!breve>➔AB45',#<UEFD5><dead_breve>
	'<!turned><!breve><!breve>➔AB3B',#<UEFD5><dead_breve><dead_breve>
	'<!turned><!diaeresis>➔1D1E',#<UEFD5><dead_diaeresis>
	'<!turned><!diaeresis><!turned>➔00CB',#<UEFD5><dead_diaeresis><UEFD5>
	'<!turned><!group>➔1D02',#<UEFD5><UEFD0>
	'<!turned><!group><!group>➔2C70',#<UEFD5><UEFD0><UEFD0>
	'<!turned><!group><!group><!group>➔1D08',#<UEFD5><UEFD0><UEFD0><UEFD0>
	'<!turned><!group><!group><!group><!group>➔A77F',#<UEFD5><UEFD0><UEFD0><UEFD0><UEFD0>
	'<!turned><!group><1>➔2319',#<UEFD5><UEFD0><1>
	'<!turned><!group><2>➔29A2',#<UEFD5><UEFD0><2>
	'<!turned><!group><3>➔1D08',#<UEFD5><UEFD0><3>
	'<!turned><!group><4>➔A77F',#<UEFD5><UEFD0><4>
	'<!turned><!group><5>➔A77E',#<UEFD5><UEFD0><5>
	'<!turned><!hook>➔027B',#<UEFD5><dead_hook>
	'<!turned><!hook><!hook>➔AB39',#<UEFD5><dead_hook><dead_hook>
	'<!turned><!hook><!hook><!turned>➔AB37',#<UEFD5><dead_hook><dead_hook><UEFD5>
	'<!turned><!hook><!retroflexhook>➔AB35',#<UEFD5><dead_hook><UEFD4>
	'<!turned><!hook><!superscript>➔AB4B',#<UEFD5><dead_hook><UEFD1>
	'<!turned><!hook><!turned>➔AB4E',#<UEFD5><dead_hook><UEFD5>
	'<!turned><!hook><!turned><!hook>➔AB4D',#<UEFD5><dead_hook><UEFD5><dead_hook>
	'<!turned><!macron>➔AB4F',#<UEFD5><dead_macron>
	'<!turned><!macron><!retroflexhook>➔AB50',#<UEFD5><dead_macron><UEFD4>
	'<!turned><!macron><!superscript>➔AB51',#<UEFD5><dead_macron><UEFD1>
	'<!turned><!retroflexhook>➔AB52',#<UEFD5><UEFD4>
	'<!turned><!retroflexhook><!hook>➔AB5A',#<UEFD5><UEFD4><dead_hook>
	'<!turned><!retroflexhook><!macron>➔AB5C',#<UEFD5><UEFD4><dead_macron>
	'<!turned><!retroflexhook><!retroflexhook>➔AB5D',#<UEFD5><UEFD4><UEFD4>
	'<!turned><!stroke>➔AB41',#<UEFD5><dead_stroke>
	'<!turned><!stroke><!group>➔AB60',#<UEFD5><dead_stroke><UEFD0>
	'<!turned><!stroke><!group><!group>➔AB61',#<UEFD5><dead_stroke><UEFD0><UEFD0>
	'<!turned><!stroke><!group><!group><!group>➔AB62',#<UEFD5><dead_stroke><UEFD0><UEFD0><UEFD0>
	'<!turned><!stroke><!group><3>➔AB62',#<UEFD5><dead_stroke><UEFD0><3>
	'<!turned><!stroke><!turned>➔1D12',#<UEFD5><dead_stroke><UEFD5>
	'<!turned><!subscript>➔AB63',#<UEFD5><UEFD2>
	'<!turned><!subscript><!subscript>➔AB65',#<UEFD5><UEFD2><UEFD2>
	'<!turned><!subscript><!turned>➔02BE',#<UEFD5><UEFD2><UEFD5>
	'<!turned><!superscript>➔1D4E',#<UEFD5><UEFD1>
	'<!turned><!superscript><!group>➔AB69',#<UEFD5><UEFD1><UEFD0>
	'<!turned><!superscript><!group><!group>➔AB6A',#<UEFD5><UEFD1><UEFD0><UEFD0>
	'<!turned><!superscript><!group><!group><!group>➔AB6B',#<UEFD5><UEFD1><UEFD0><UEFD0><UEFD0>
	'<!turned><!superscript><!group><3>➔AB6B',#<UEFD5><UEFD1><UEFD0><3>
	'<!turned><!superscript><!hook>➔AB48',#<UEFD5><UEFD1><dead_hook>
	'<!turned><!superscript><!macron>➔AB49',#<UEFD5><UEFD1><dead_macron>
	'<!turned><!superscript><!turned>➔AB31',#<UEFD5><UEFD1><UEFD5>
	'<!turned><!tilde>➔AB68',#<UEFD5><dead_tilde>
	'<!turned><!tilde><!tilde>➔2240',#<UEFD5><dead_tilde><dead_tilde>
	'<!turned><!turned>➔A7FD',#<UEFD5><UEFD5>
	'<!turned><!turned><!diaeresis>➔1D1F',#<UEFD5><UEFD5><dead_diaeresis>
	'<!turned><!turned><!group>➔1D11',#<UEFD5><UEFD5><UEFD0>
	'<!turned><!turned><!group><!group>➔223E',#<UEFD5><UEFD5><UEFD0><UEFD0>
	'<!turned><!turned><!group><!group><!group>➔1D1D',#<UEFD5><UEFD5><UEFD0><UEFD0><UEFD0>
	'<!turned><!turned><!group><3>➔1D1D',#<UEFD5><UEFD5><UEFD0><3>
	'<!turned><!turned><!hook>➔AB34',#<UEFD5><UEFD5><dead_hook>
	'<!turned><!turned><!hook><!hook>➔AB40',#<UEFD5><UEFD5><dead_hook><dead_hook>
	'<!turned><!turned><!stroke>➔1D13',#<UEFD5><UEFD5><dead_stroke>
	'<!turned><!turned><!subscript>➔0298',#<UEFD5><UEFD5><UEFD2>
	'<!turned><!turned><!superscript>➔1D59',#<UEFD5><UEFD5><UEFD1>

	# Polytonic and monotonic Greek (256).
	'<!abovehook><!greek>➔1FBD',#<UEFD3><dead_greek>
	'<!acute><!belowdot><!breve><!greek>➔1F84',#<dead_acute><dead_belowdot><dead_breve><dead_greek>
	'<!acute><!belowdot><!greek>➔1FB4',#<dead_acute><dead_belowdot><dead_greek>
	'<!acute><!belowdot><!greek><!breve>➔1F8C',#<dead_acute><dead_belowdot><dead_greek><dead_breve>
	'<!acute><!belowdot><!greek><!invertedbreve>➔1F8D',#<dead_acute><dead_belowdot><dead_greek><dead_invertedbreve>
	'<!acute><!belowdot><!invertedbreve><!greek>➔1F85',#<dead_acute><dead_belowdot><dead_invertedbreve><dead_greek>
	'<!acute><!breve><!belowdot><!greek>➔1F9C',#<dead_acute><dead_breve><dead_belowdot><dead_greek>
	'<!acute><!breve><!greek>➔1FCE',#<dead_acute><dead_breve><dead_greek>
	'<!acute><!breve><!greek><!belowdot>➔1F94',#<dead_acute><dead_breve><dead_greek><dead_belowdot>
	'<!acute><!diaeresis><!greek>➔1FEE',#<dead_acute><dead_diaeresis><dead_greek>
	'<!acute><!greek>➔1FFD',#<dead_acute><dead_greek>
	'<!acute><!greek><!belowdot>➔1FC4',#<dead_acute><dead_greek><dead_belowdot>
	'<!acute><!greek><!belowdot><!breve>➔1FAC',#<dead_acute><dead_greek><dead_belowdot><dead_breve>
	'<!acute><!greek><!belowdot><!invertedbreve>➔1F9D',#<dead_acute><dead_greek><dead_belowdot><dead_invertedbreve>
	'<!acute><!greek><!breve>➔1F0C',#<dead_acute><dead_greek><dead_breve>
	'<!acute><!greek><!breve><!belowdot>➔1FA4',#<dead_acute><dead_greek><dead_breve><dead_belowdot>
	'<!acute><!greek><!diaeresis>➔1FD3',#<dead_acute><dead_greek><dead_diaeresis>
	'<!acute><!greek><!invertedbreve>➔1FDE',#<dead_acute><dead_greek><dead_invertedbreve>
	'<!acute><!greek><!invertedbreve><!belowdot>➔1F95',#<dead_acute><dead_greek><dead_invertedbreve><dead_belowdot>
	'<!acute><!invertedbreve><!belowdot><!greek>➔1FAD',#<dead_acute><dead_invertedbreve><dead_belowdot><dead_greek>
	'<!acute><!invertedbreve><!greek>➔1F0D',#<dead_acute><dead_invertedbreve><dead_greek>
	'<!acute><!invertedbreve><!greek><!belowdot>➔1FA5',#<dead_acute><dead_invertedbreve><dead_greek><dead_belowdot>
	'<!belowdot><!acute><!breve><!greek>➔1FCF',#<dead_belowdot><dead_acute><dead_breve><dead_greek>
	'<!belowdot><!acute><!greek>➔1FF4',#<dead_belowdot><dead_acute><dead_greek>
	'<!belowdot><!acute><!greek><!breve>➔1F0E',#<dead_belowdot><dead_acute><dead_greek><dead_breve>
	'<!belowdot><!acute><!greek><!invertedbreve>➔1FDF',#<dead_belowdot><dead_acute><dead_greek><dead_invertedbreve>
	'<!belowdot><!acute><!invertedbreve><!greek>➔1F0F',#<dead_belowdot><dead_acute><dead_invertedbreve><dead_greek>
	'<!belowdot><!breve><!acute><!greek>➔1F06',#<dead_belowdot><dead_breve><dead_acute><dead_greek>
	'<!belowdot><!breve><!circumflex><!greek>➔1F8E',#<dead_belowdot><dead_breve><dead_circumflex><dead_greek>
	'<!belowdot><!breve><!grave><!greek>➔1F8A',#<dead_belowdot><dead_breve><dead_grave><dead_greek>
	'<!belowdot><!breve><!greek>➔1F88',#<dead_belowdot><dead_breve><dead_greek>
	'<!belowdot><!breve><!greek><!acute>➔1F2E',#<dead_belowdot><dead_breve><dead_greek><dead_acute>
	'<!belowdot><!breve><!greek><!circumflex>➔1F86',#<dead_belowdot><dead_breve><dead_greek><dead_circumflex>
	'<!belowdot><!breve><!greek><!grave>➔1F82',#<dead_belowdot><dead_breve><dead_greek><dead_grave>
	'<!belowdot><!circumflex><!breve><!greek>➔1F9E',#<dead_belowdot><dead_circumflex><dead_breve><dead_greek>
	'<!belowdot><!circumflex><!greek>➔1FB7',#<dead_belowdot><dead_circumflex><dead_greek>
	'<!belowdot><!circumflex><!greek><!breve>➔1F96',#<dead_belowdot><dead_circumflex><dead_greek><dead_breve>
	'<!belowdot><!circumflex><!greek><!invertedbreve>➔1F8F',#<dead_belowdot><dead_circumflex><dead_greek><dead_invertedbreve>
	'<!belowdot><!circumflex><!invertedbreve><!greek>➔1F87',#<dead_belowdot><dead_circumflex><dead_invertedbreve><dead_greek>
	'<!belowdot><!grave><!breve><!greek>➔1F9A',#<dead_belowdot><dead_grave><dead_breve><dead_greek>
	'<!belowdot><!grave><!greek>➔1FB2',#<dead_belowdot><dead_grave><dead_greek>
	'<!belowdot><!grave><!greek><!breve>➔1F92',#<dead_belowdot><dead_grave><dead_greek><dead_breve>
	'<!belowdot><!grave><!greek><!invertedbreve>➔1F8B',#<dead_belowdot><dead_grave><dead_greek><dead_invertedbreve>
	'<!belowdot><!grave><!invertedbreve><!greek>➔1F83',#<dead_belowdot><dead_grave><dead_invertedbreve><dead_greek>
	'<!belowdot><!greek>➔037A',#<dead_belowdot><dead_greek>
	'<!belowdot><!greek><!acute>➔1FFE',#<dead_belowdot><dead_greek><dead_acute>
	'<!belowdot><!greek><!acute><!breve>➔1F26',#<dead_belowdot><dead_greek><dead_acute><dead_breve>
	'<!belowdot><!greek><!acute><!invertedbreve>➔1F07',#<dead_belowdot><dead_greek><dead_acute><dead_invertedbreve>
	'<!belowdot><!greek><!breve>➔1F80',#<dead_belowdot><dead_greek><dead_breve>
	'<!belowdot><!greek><!breve><!acute>➔1F3E',#<dead_belowdot><dead_greek><dead_breve><dead_acute>
	'<!belowdot><!greek><!breve><!circumflex>➔1FAE',#<dead_belowdot><dead_greek><dead_breve><dead_circumflex>
	'<!belowdot><!greek><!breve><!grave>➔1FAA',#<dead_belowdot><dead_greek><dead_breve><dead_grave>
	'<!belowdot><!greek><!circumflex>➔1FC7',#<dead_belowdot><dead_greek><dead_circumflex>
	'<!belowdot><!greek><!circumflex><!breve>➔1FA6',#<dead_belowdot><dead_greek><dead_circumflex><dead_breve>
	'<!belowdot><!greek><!circumflex><!invertedbreve>➔1F9F',#<dead_belowdot><dead_greek><dead_circumflex><dead_invertedbreve>
	'<!belowdot><!greek><!grave>➔1FC2',#<dead_belowdot><dead_greek><dead_grave>
	'<!belowdot><!greek><!grave><!breve>➔1FA2',#<dead_belowdot><dead_greek><dead_grave><dead_breve>
	'<!belowdot><!greek><!grave><!invertedbreve>➔1F9B',#<dead_belowdot><dead_greek><dead_grave><dead_invertedbreve>
	'<!belowdot><!greek><!invertedbreve>➔1F89',#<dead_belowdot><dead_greek><dead_invertedbreve>
	'<!belowdot><!greek><!invertedbreve><!acute>➔1F2F',#<dead_belowdot><dead_greek><dead_invertedbreve><dead_acute>
	'<!belowdot><!greek><!invertedbreve><!circumflex>➔1F97',#<dead_belowdot><dead_greek><dead_invertedbreve><dead_circumflex>
	'<!belowdot><!greek><!invertedbreve><!grave>➔1F93',#<dead_belowdot><dead_greek><dead_invertedbreve><dead_grave>
	'<!belowdot><!invertedbreve><!acute><!greek>➔1F27',#<dead_belowdot><dead_invertedbreve><dead_acute><dead_greek>
	'<!belowdot><!invertedbreve><!circumflex><!greek>➔1FAF',#<dead_belowdot><dead_invertedbreve><dead_circumflex><dead_greek>
	'<!belowdot><!invertedbreve><!grave><!greek>➔1FAB',#<dead_belowdot><dead_invertedbreve><dead_grave><dead_greek>
	'<!belowdot><!invertedbreve><!greek>➔1F81',#<dead_belowdot><dead_invertedbreve><dead_greek>
	'<!belowdot><!invertedbreve><!greek><!acute>➔1F3F',#<dead_belowdot><dead_invertedbreve><dead_greek><dead_acute>
	'<!belowdot><!invertedbreve><!greek><!circumflex>➔1FA7',#<dead_belowdot><dead_invertedbreve><dead_greek><dead_circumflex>
	'<!belowdot><!invertedbreve><!greek><!grave>➔1FA3',#<dead_belowdot><dead_invertedbreve><dead_greek><dead_grave>
	'<!breve><!acute><!belowdot><!greek>➔1F36',#<dead_breve><dead_acute><dead_belowdot><dead_greek>
	'<!breve><!acute><!greek>➔1F04',#<dead_breve><dead_acute><dead_greek>
	'<!breve><!acute><!greek><!belowdot>➔1F6E',#<dead_breve><dead_acute><dead_greek><dead_belowdot>
	'<!breve><!belowdot><!acute><!greek>➔1F66',#<dead_breve><dead_belowdot><dead_acute><dead_greek>
	'<!breve><!belowdot><!circumflex><!greek>➔1FCD',#<dead_breve><dead_belowdot><dead_circumflex><dead_greek>
	'<!breve><!belowdot><!grave><!greek>➔1F98',#<dead_breve><dead_belowdot><dead_grave><dead_greek>
	'<!breve><!belowdot><!greek>➔1F90',#<dead_breve><dead_belowdot><dead_greek>
	'<!breve><!belowdot><!greek><!acute>➔1F56',#<dead_breve><dead_belowdot><dead_greek><dead_acute>
	'<!breve><!belowdot><!greek><!circumflex>➔1F0A',#<dead_breve><dead_belowdot><dead_greek><dead_circumflex>
	'<!breve><!belowdot><!greek><!grave>➔1FA8',#<dead_breve><dead_belowdot><dead_greek><dead_grave>
	'<!breve><!circumflex><!belowdot><!greek>➔1F02',#<dead_breve><dead_circumflex><dead_belowdot><dead_greek>
	'<!breve><!circumflex><!greek>➔1F1A',#<dead_breve><dead_circumflex><dead_greek>
	'<!breve><!circumflex><!greek><!belowdot>➔1F12',#<dead_breve><dead_circumflex><dead_greek><dead_belowdot>
	'<!breve><!grave><!belowdot><!greek>➔1FA0',#<dead_breve><dead_grave><dead_belowdot><dead_greek>
	'<!breve><!grave><!greek>➔1F2A',#<dead_breve><dead_grave><dead_greek>
	'<!breve><!grave><!greek><!belowdot>➔00AF',#<dead_breve><dead_grave><dead_greek><dead_belowdot>
	'<!breve><!greek>➔1FBF',#<dead_breve><dead_greek>
	'<!breve><!greek><!acute>➔1F1C',#<dead_breve><dead_greek><dead_acute>
	'<!breve><!greek><!acute><!belowdot>➔1F22',#<dead_breve><dead_greek><dead_acute><dead_belowdot>
	'<!breve><!greek><!belowdot>➔1F43',#<dead_breve><dead_greek><dead_belowdot>
	'<!breve><!greek><!belowdot><!acute>➔1F3A',#<dead_breve><dead_greek><dead_belowdot><dead_acute>
	'<!breve><!greek><!belowdot><!circumflex>➔1F32',#<dead_breve><dead_greek><dead_belowdot><dead_circumflex>
	'<!breve><!greek><!belowdot><!grave>➔1FB1',#<dead_breve><dead_greek><dead_belowdot><dead_grave>
	'<!breve><!greek><!circumflex>➔1F4A',#<dead_breve><dead_greek><dead_circumflex>
	'<!breve><!greek><!circumflex><!belowdot>➔1F42',#<dead_breve><dead_greek><dead_circumflex><dead_belowdot>
	'<!breve><!greek><!grave>➔1F6A',#<dead_breve><dead_greek><dead_grave>
	'<!breve><!greek><!grave><!belowdot>➔1FD9',#<dead_breve><dead_greek><dead_grave><dead_belowdot>
	'<!caron><!greek>➔1FB8',#<dead_caron><dead_greek>
	'<!circumflex><!belowdot><!breve><!greek>➔1FB0',#<dead_circumflex><dead_belowdot><dead_breve><dead_greek>
	'<!circumflex><!belowdot><!greek>➔1FF7',#<dead_circumflex><dead_belowdot><dead_greek>
	'<!circumflex><!belowdot><!greek><!breve>➔1FD8',#<dead_circumflex><dead_belowdot><dead_greek><dead_breve>
	'<!circumflex><!belowdot><!greek><!invertedbreve>➔1FD0',#<dead_circumflex><dead_belowdot><dead_greek><dead_invertedbreve>
	'<!circumflex><!belowdot><!invertedbreve><!greek>➔1FE8',#<dead_circumflex><dead_belowdot><dead_invertedbreve><dead_greek>
	'<!circumflex><!breve><!belowdot><!greek>➔1FE0',#<dead_circumflex><dead_breve><dead_belowdot><dead_greek>
	'<!circumflex><!breve><!greek>➔1FFC',#<dead_circumflex><dead_breve><dead_greek>
	'<!circumflex><!breve><!greek><!belowdot>➔1FFB',#<dead_circumflex><dead_breve><dead_greek><dead_belowdot>
	'<!circumflex><!diaeresis><!greek>➔1FC1',#<dead_circumflex><dead_diaeresis><dead_greek>
	'<!circumflex><!greek>➔1FC0',#<dead_circumflex><dead_greek>
	'<!circumflex><!greek><!belowdot>➔1FFA',#<dead_circumflex><dead_greek><dead_belowdot>
	'<!circumflex><!greek><!belowdot><!breve>➔1FF9',#<dead_circumflex><dead_greek><dead_belowdot><dead_breve>
	'<!circumflex><!greek><!belowdot><!invertedbreve>➔1FF8',#<dead_circumflex><dead_greek><dead_belowdot><dead_invertedbreve>
	'<!circumflex><!greek><!breve>➔1FF6',#<dead_circumflex><dead_greek><dead_breve>
	'<!circumflex><!greek><!breve><!belowdot>➔1FF3',#<dead_circumflex><dead_greek><dead_breve><dead_belowdot>
	'<!circumflex><!greek><!diaeresis>➔1FD7',#<dead_circumflex><dead_greek><dead_diaeresis>
	'<!circumflex><!greek><!invertedbreve>➔1F37',#<dead_circumflex><dead_greek><dead_invertedbreve>
	'<!circumflex><!greek><!invertedbreve><!belowdot>➔1FF2',#<dead_circumflex><dead_greek><dead_invertedbreve><dead_belowdot>
	'<!circumflex><!invertedbreve><!belowdot><!greek>➔1FEF',#<dead_circumflex><dead_invertedbreve><dead_belowdot><dead_greek>
	'<!circumflex><!invertedbreve><!greek>➔1F6F',#<dead_circumflex><dead_invertedbreve><dead_greek>
	'<!circumflex><!invertedbreve><!greek><!belowdot>➔1FED',#<dead_circumflex><dead_invertedbreve><dead_greek><dead_belowdot>
	'<!diaeresis><!acute><!greek>➔1FE3',#<dead_diaeresis><dead_acute><dead_greek>
	'<!diaeresis><!circumflex><!greek>➔1FE7',#<dead_diaeresis><dead_circumflex><dead_greek>
	'<!diaeresis><!doubleacute><!greek>➔0344',#<dead_diaeresis><dead_doubleacute><dead_greek>
	'<!diaeresis><!grave><!greek>➔1FD2',#<dead_diaeresis><dead_grave><dead_greek>
	'<!diaeresis><!greek>➔03AA',#<dead_diaeresis><dead_greek>
	'<!diaeresis><!greek><!acute>➔1FEC',#<dead_diaeresis><dead_greek><dead_acute>
	'<!diaeresis><!greek><!circumflex>➔1FEB',#<dead_diaeresis><dead_greek><dead_circumflex>
	'<!diaeresis><!greek><!doubleacute>➔0385',#<dead_diaeresis><dead_greek><dead_doubleacute>
	'<!diaeresis><!greek><!grave>➔1FE2',#<dead_diaeresis><dead_greek><dead_grave>
	'<!doubleacute><!diaeresis><!greek>➔0390',#<dead_doubleacute><dead_diaeresis><dead_greek>
	'<!doubleacute><!greek>➔0384',#<dead_doubleacute><dead_greek>
	'<!doubleacute><!greek><!diaeresis>➔03B0',#<dead_doubleacute><dead_greek><dead_diaeresis>
	'<!grave><!belowdot><!breve><!greek>➔1FEA',#<dead_grave><dead_belowdot><dead_breve><dead_greek>
	'<!grave><!belowdot><!greek>➔1FE9',#<dead_grave><dead_belowdot><dead_greek>
	'<!grave><!belowdot><!greek><!breve>➔1FE6',#<dead_grave><dead_belowdot><dead_greek><dead_breve>
	'<!grave><!belowdot><!greek><!invertedbreve>➔1FE5',#<dead_grave><dead_belowdot><dead_greek><dead_invertedbreve>
	'<!grave><!belowdot><!invertedbreve><!greek>➔1FE4',#<dead_grave><dead_belowdot><dead_invertedbreve><dead_greek>
	'<!grave><!breve><!belowdot><!greek>➔1FE1',#<dead_grave><dead_breve><dead_belowdot><dead_greek>
	'<!grave><!breve><!greek>➔1F62',#<dead_grave><dead_breve><dead_greek>
	'<!grave><!breve><!greek><!belowdot>➔1FDD',#<dead_grave><dead_breve><dead_greek><dead_belowdot>
	'<!grave><!diaeresis><!greek>➔1FDB',#<dead_grave><dead_diaeresis><dead_greek>
	'<!grave><!greek>➔1FBA',#<dead_grave><dead_greek>
	'<!grave><!greek><!belowdot>➔1F5B',#<dead_grave><dead_greek><dead_belowdot>
	'<!grave><!greek><!belowdot><!breve>➔1F72',#<dead_grave><dead_greek><dead_belowdot><dead_breve>
	'<!grave><!greek><!belowdot><!invertedbreve>➔1F74',#<dead_grave><dead_greek><dead_belowdot><dead_invertedbreve>
	'<!grave><!greek><!breve>➔1F52',#<dead_grave><dead_greek><dead_breve>
	'<!grave><!greek><!breve><!belowdot>➔1F76',#<dead_grave><dead_greek><dead_breve><dead_belowdot>
	'<!grave><!greek><!diaeresis>➔1F78',#<dead_grave><dead_greek><dead_diaeresis>
	'<!grave><!greek><!invertedbreve>➔1F0B',#<dead_grave><dead_greek><dead_invertedbreve>
	'<!grave><!greek><!invertedbreve><!belowdot>➔1F7A',#<dead_grave><dead_greek><dead_invertedbreve><dead_belowdot>
	'<!grave><!invertedbreve><!belowdot><!greek>➔1F7C',#<dead_grave><dead_invertedbreve><dead_belowdot><dead_greek>
	'<!grave><!invertedbreve><!greek>➔1F03',#<dead_grave><dead_invertedbreve><dead_greek>
	'<!grave><!invertedbreve><!greek><!belowdot>➔1FC8',#<dead_grave><dead_invertedbreve><dead_greek><dead_belowdot>
	'<!greek><!abovehook>➔1FDA',#<dead_greek><UEFD3>
	'<!greek><!acute>➔1FBB',#<dead_greek><dead_acute>
	'<!greek><!acute><!belowdot>➔1F71',#<dead_greek><dead_acute><dead_belowdot>
	'<!greek><!acute><!belowdot><!breve>➔1F73',#<dead_greek><dead_acute><dead_belowdot><dead_breve>
	'<!greek><!acute><!belowdot><!invertedbreve>➔1F75',#<dead_greek><dead_acute><dead_belowdot><dead_invertedbreve>
	'<!greek><!acute><!breve>➔1F14',#<dead_greek><dead_acute><dead_breve>
	'<!greek><!acute><!breve><!belowdot>➔1F2C',#<dead_greek><dead_acute><dead_breve><dead_belowdot>
	'<!greek><!acute><!diaeresis>➔1F77',#<dead_greek><dead_acute><dead_diaeresis>
	'<!greek><!acute><!invertedbreve>➔1F05',#<dead_greek><dead_acute><dead_invertedbreve>
	'<!greek><!acute><!invertedbreve><!belowdot>➔1F15',#<dead_greek><dead_acute><dead_invertedbreve><dead_belowdot>
	'<!greek><!belowdot>➔1FBE',#<dead_greek><dead_belowdot>
	'<!greek><!belowdot><!acute>➔1F79',#<dead_greek><dead_belowdot><dead_acute>
	'<!greek><!belowdot><!acute><!breve>➔1F7B',#<dead_greek><dead_belowdot><dead_acute><dead_breve>
	'<!greek><!belowdot><!acute><!invertedbreve>➔1F7D',#<dead_greek><dead_belowdot><dead_acute><dead_invertedbreve>
	'<!greek><!belowdot><!breve>➔1FC3',#<dead_greek><dead_belowdot><dead_breve>
	'<!greek><!belowdot><!breve><!acute>➔1FC9',#<dead_greek><dead_belowdot><dead_breve><dead_acute>
	'<!greek><!belowdot><!breve><!circumflex>➔1FD6',#<dead_greek><dead_belowdot><dead_breve><dead_circumflex>
	'<!greek><!belowdot><!breve><!grave>➔1FCA',#<dead_greek><dead_belowdot><dead_breve><dead_grave>
	'<!greek><!belowdot><!circumflex>➔1F1D',#<dead_greek><dead_belowdot><dead_circumflex>
	'<!greek><!belowdot><!circumflex><!breve>➔1F25',#<dead_greek><dead_belowdot><dead_circumflex><dead_breve>
	'<!greek><!belowdot><!circumflex><!invertedbreve>➔1F65',#<dead_greek><dead_belowdot><dead_circumflex><dead_invertedbreve>
	'<!greek><!belowdot><!grave>➔1F53',#<dead_greek><dead_belowdot><dead_grave>
	'<!greek><!belowdot><!grave><!breve>➔1F6D',#<dead_greek><dead_belowdot><dead_grave><dead_breve>
	'<!greek><!belowdot><!grave><!invertedbreve>➔1FD1',#<dead_greek><dead_belowdot><dead_grave><dead_invertedbreve>
	'<!greek><!belowdot><!invertedbreve>➔1F99',#<dead_greek><dead_belowdot><dead_invertedbreve>
	'<!greek><!belowdot><!invertedbreve><!acute>➔1FCC',#<dead_greek><dead_belowdot><dead_invertedbreve><dead_acute>
	'<!greek><!belowdot><!invertedbreve><!circumflex>➔1FCB',#<dead_greek><dead_belowdot><dead_invertedbreve><dead_circumflex>
	'<!greek><!belowdot><!invertedbreve><!grave>➔1FC6',#<dead_greek><dead_belowdot><dead_invertedbreve><dead_grave>
	'<!greek><!breve>➔1F08',#<dead_greek><dead_breve>
	'<!greek><!breve><!acute>➔1F24',#<dead_greek><dead_breve><dead_acute>
	'<!greek><!breve><!acute><!belowdot>➔1F34',#<dead_greek><dead_breve><dead_acute><dead_belowdot>
	'<!greek><!breve><!belowdot>➔1F00',#<dead_greek><dead_breve><dead_belowdot>
	'<!greek><!breve><!belowdot><!acute>➔1F3C',#<dead_greek><dead_breve><dead_belowdot><dead_acute>
	'<!greek><!breve><!belowdot><!circumflex>➔1F10',#<dead_greek><dead_breve><dead_belowdot><dead_circumflex>
	'<!greek><!breve><!belowdot><!grave>➔1F18',#<dead_greek><dead_breve><dead_belowdot><dead_grave>
	'<!greek><!breve><!circumflex>➔03CE',#<dead_greek><dead_breve><dead_circumflex>
	'<!greek><!breve><!circumflex><!belowdot>➔1F20',#<dead_greek><dead_breve><dead_circumflex><dead_belowdot>
	'<!greek><!breve><!grave>➔1F28',#<dead_greek><dead_breve><dead_grave>
	'<!greek><!breve><!grave><!belowdot>➔1F30',#<dead_greek><dead_breve><dead_grave><dead_belowdot>
	'<!greek><!caron>➔1F50',#<dead_greek><dead_caron>
	'<!greek><!circumflex>➔1FB6',#<dead_greek><dead_circumflex>
	'<!greek><!circumflex><!belowdot>➔1F60',#<dead_greek><dead_circumflex><dead_belowdot>
	'<!greek><!circumflex><!belowdot><!breve>➔1F38',#<dead_greek><dead_circumflex><dead_belowdot><dead_breve>
	'<!greek><!circumflex><!belowdot><!invertedbreve>➔1FBC',#<dead_greek><dead_circumflex><dead_belowdot><dead_invertedbreve>
	'<!greek><!circumflex><!breve>➔1F40',#<dead_greek><dead_circumflex><dead_breve>
	'<!greek><!circumflex><!breve><!belowdot>➔1F48',#<dead_greek><dead_circumflex><dead_breve><dead_belowdot>
	'<!greek><!circumflex><!diaeresis>➔03AB',#<dead_greek><dead_circumflex><dead_diaeresis>
	'<!greek><!circumflex><!invertedbreve>➔1F67',#<dead_greek><dead_circumflex><dead_invertedbreve>
	'<!greek><!circumflex><!invertedbreve><!belowdot>➔1FB3',#<dead_greek><dead_circumflex><dead_invertedbreve><dead_belowdot>
	'<!greek><!diaeresis>➔03CA',#<dead_greek><dead_diaeresis>
	'<!greek><!diaeresis><!acute>➔03CB',#<dead_greek><dead_diaeresis><dead_acute>
	'<!greek><!diaeresis><!circumflex>➔1F44',#<dead_greek><dead_diaeresis><dead_circumflex>
	'<!greek><!diaeresis><!doubleacute>➔1F4C',#<dead_greek><dead_diaeresis><dead_doubleacute>
	'<!greek><!diaeresis><!grave>➔1F54',#<dead_greek><dead_diaeresis><dead_grave>
	'<!greek><!doubleacute>➔0386',#<dead_greek><dead_doubleacute>
	'<!greek><!doubleacute><!diaeresis>➔0388',#<dead_greek><dead_doubleacute><dead_diaeresis>
	'<!greek><!grave>➔1F70',#<dead_greek><dead_grave>
	'<!greek><!grave><!belowdot>➔1FA9',#<dead_greek><dead_grave><dead_belowdot>
	'<!greek><!grave><!belowdot><!breve>➔1F68',#<dead_greek><dead_grave><dead_belowdot><dead_breve>
	'<!greek><!grave><!belowdot><!invertedbreve>➔1FA1',#<dead_greek><dead_grave><dead_belowdot><dead_invertedbreve>
	'<!greek><!grave><!breve>➔1F91',#<dead_greek><dead_grave><dead_breve>
	'<!greek><!grave><!breve><!belowdot>➔1F6C',#<dead_greek><dead_grave><dead_breve><dead_belowdot>
	'<!greek><!grave><!diaeresis>➔1F6B',#<dead_greek><dead_grave><dead_diaeresis>
	'<!greek><!grave><!invertedbreve>➔1F69',#<dead_greek><dead_grave><dead_invertedbreve>
	'<!greek><!grave><!invertedbreve><!belowdot>➔1F64',#<dead_greek><dead_grave><dead_invertedbreve><dead_belowdot>
	'<!greek><!invertedbreve>➔1F09',#<dead_greek><dead_invertedbreve>
	'<!greek><!invertedbreve><!acute>➔03AF',#<dead_greek><dead_invertedbreve><dead_acute>
	'<!greek><!invertedbreve><!acute><!belowdot>➔03CC',#<dead_greek><dead_invertedbreve><dead_acute><dead_belowdot>
	'<!greek><!invertedbreve><!belowdot>➔1F35',#<dead_greek><dead_invertedbreve><dead_belowdot>
	'<!greek><!invertedbreve><!belowdot><!acute>➔03CD',#<dead_greek><dead_invertedbreve><dead_belowdot><dead_acute>
	'<!greek><!invertedbreve><!belowdot><!circumflex>➔1F11',#<dead_greek><dead_invertedbreve><dead_belowdot><dead_circumflex>
	'<!greek><!invertedbreve><!belowdot><!grave>➔1F19',#<dead_greek><dead_invertedbreve><dead_belowdot><dead_grave>
	'<!greek><!invertedbreve><!circumflex>➔1F5F',#<dead_greek><dead_invertedbreve><dead_circumflex>
	'<!greek><!invertedbreve><!circumflex><!belowdot>➔1F57',#<dead_greek><dead_invertedbreve><dead_circumflex><dead_belowdot>
	'<!greek><!invertedbreve><!grave>➔1F21',#<dead_greek><dead_invertedbreve><dead_grave>
	'<!greek><!invertedbreve><!grave><!belowdot>➔1F29',#<dead_greek><dead_invertedbreve><dead_grave><dead_belowdot>
	'<!greek><!macron>➔1FB9',#<dead_greek><dead_macron>
	'<!invertedbreve><!acute><!belowdot><!greek>➔0389',#<dead_invertedbreve><dead_acute><dead_belowdot><dead_greek>
	'<!invertedbreve><!acute><!greek>➔038A',#<dead_invertedbreve><dead_acute><dead_greek>
	'<!invertedbreve><!acute><!greek><!belowdot>➔038C',#<dead_invertedbreve><dead_acute><dead_greek><dead_belowdot>
	'<!invertedbreve><!belowdot><!acute><!greek>➔038E',#<dead_invertedbreve><dead_belowdot><dead_acute><dead_greek>
	'<!invertedbreve><!belowdot><!circumflex><!greek>➔1F31',#<dead_invertedbreve><dead_belowdot><dead_circumflex><dead_greek>
	'<!invertedbreve><!belowdot><!grave><!greek>➔1F39',#<dead_invertedbreve><dead_belowdot><dead_grave><dead_greek>
	'<!invertedbreve><!belowdot><!greek>➔1F41',#<dead_invertedbreve><dead_belowdot><dead_greek>
	'<!invertedbreve><!belowdot><!greek><!acute>➔038F',#<dead_invertedbreve><dead_belowdot><dead_greek><dead_acute>
	'<!invertedbreve><!belowdot><!greek><!circumflex>➔1F49',#<dead_invertedbreve><dead_belowdot><dead_greek><dead_circumflex>
	'<!invertedbreve><!belowdot><!greek><!grave>➔1F51',#<dead_invertedbreve><dead_belowdot><dead_greek><dead_grave>
	'<!invertedbreve><!circumflex><!belowdot><!greek>➔1F59',#<dead_invertedbreve><dead_circumflex><dead_belowdot><dead_greek>
	'<!invertedbreve><!circumflex><!greek>➔1F61',#<dead_invertedbreve><dead_circumflex><dead_greek>
	'<!invertedbreve><!circumflex><!greek><!belowdot>➔1F4D',#<dead_invertedbreve><dead_circumflex><dead_greek><dead_belowdot>
	'<!invertedbreve><!grave><!belowdot><!greek>➔1F4B',#<dead_invertedbreve><dead_grave><dead_belowdot><dead_greek>
	'<!invertedbreve><!grave><!greek>➔1F45',#<dead_invertedbreve><dead_grave><dead_greek>
	'<!invertedbreve><!grave><!greek><!belowdot>➔1F63',#<dead_invertedbreve><dead_grave><dead_greek><dead_belowdot>
	'<!invertedbreve><!greek>➔1F01',#<dead_invertedbreve><dead_greek>
	'<!invertedbreve><!greek><!acute>➔03AE',#<dead_invertedbreve><dead_greek><dead_acute>
	'<!invertedbreve><!greek><!acute><!belowdot>➔03AC',#<dead_invertedbreve><dead_greek><dead_acute><dead_belowdot>
	'<!invertedbreve><!greek><!belowdot>➔1F13',#<dead_invertedbreve><dead_greek><dead_belowdot>
	'<!invertedbreve><!greek><!belowdot><!acute>➔03AD',#<dead_invertedbreve><dead_greek><dead_belowdot><dead_acute>
	'<!invertedbreve><!greek><!belowdot><!circumflex>➔1F23',#<dead_invertedbreve><dead_greek><dead_belowdot><dead_circumflex>
	'<!invertedbreve><!greek><!belowdot><!grave>➔1F2D',#<dead_invertedbreve><dead_greek><dead_belowdot><dead_grave>
	'<!invertedbreve><!greek><!circumflex>➔1F2B',#<dead_invertedbreve><dead_greek><dead_circumflex>
	'<!invertedbreve><!greek><!circumflex><!belowdot>➔1F33',#<dead_invertedbreve><dead_greek><dead_circumflex><dead_belowdot>
	'<!invertedbreve><!greek><!grave>➔1F1B',#<dead_invertedbreve><dead_greek><dead_grave>
	'<!invertedbreve><!greek><!grave><!belowdot>➔1F3B',#<dead_invertedbreve><dead_greek><dead_grave><dead_belowdot>
	'<!macron><!greek>➔1F3D',#<dead_macron><dead_greek>

	# Latin dead key chains for Greek (54).
	'<!acute><!belowdot><!breve>➔2500',
	'<!acute><!belowdot>➔2501',
	'<!acute><!belowdot><!invertedbreve>➔2502',
	'<!acute><!breve><!belowdot>➔2503',
	'<!acute><!invertedbreve><!belowdot>➔2504',
	'<!acute><!invertedbreve>➔2505',
	'<!belowdot><!acute><!breve>➔2506',
	'<!belowdot><!acute>➔2507',
	'<!belowdot><!acute><!invertedbreve>➔2508',
	'<!belowdot><!breve><!acute>➔2509',
	'<!belowdot><!breve><!circumflex>➔250A',
	'<!belowdot><!breve><!grave>➔250B',
	'<!belowdot><!circumflex><!breve>➔250C',
	'<!belowdot><!circumflex><!invertedbreve>➔250D',
	'<!belowdot><!grave><!breve>➔250E',
	'<!belowdot><!grave>➔250F',
	'<!belowdot><!grave><!invertedbreve>➔2510',
	'<!belowdot><!invertedbreve><!acute>➔2511',
	'<!belowdot><!invertedbreve><!circumflex>➔2512',
	'<!belowdot><!invertedbreve><!grave>➔2513',
	'<!belowdot><!invertedbreve>➔2514',
	'<!breve><!acute><!belowdot>➔2515',
	'<!breve><!belowdot><!acute>➔2516',
	'<!breve><!belowdot><!circumflex>➔2517',
	'<!breve><!belowdot><!grave>➔2518',
	'<!breve><!circumflex><!belowdot>➔2519',
	'<!breve><!circumflex>➔251A',
	'<!breve><!grave><!belowdot>➔251B',
	'<!circumflex><!belowdot><!breve>➔251C',
	'<!circumflex><!belowdot><!invertedbreve>➔251D',
	'<!circumflex><!breve><!belowdot>➔251E',
	'<!circumflex><!breve>➔251F',
	'<!circumflex><!diaeresis>➔2520',
	'<!circumflex><!invertedbreve><!belowdot>➔2521',
	'<!circumflex><!invertedbreve>➔2522',
	'<!diaeresis><!circumflex>➔2523',
	'<!diaeresis><!doubleacute>➔2524',
	'<!doubleacute><!diaeresis>➔2525',
	'<!grave><!belowdot><!breve>➔2526',
	'<!grave><!belowdot>➔2527',
	'<!grave><!belowdot><!invertedbreve>➔2528',
	'<!grave><!breve><!belowdot>➔2529',
	'<!grave><!invertedbreve><!belowdot>➔252A',
	'<!grave><!invertedbreve>➔252B',
	'<!invertedbreve><!acute><!belowdot>➔252C',
	'<!invertedbreve><!acute>➔252D',
	'<!invertedbreve><!belowdot><!acute>➔252E',
	'<!invertedbreve><!belowdot><!circumflex>➔252F',
	'<!invertedbreve><!belowdot><!grave>➔2530',
	'<!invertedbreve><!belowdot>➔2531',
	'<!invertedbreve><!circumflex><!belowdot>➔2532',
	'<!invertedbreve><!circumflex>➔2533',
	'<!invertedbreve><!grave><!belowdot>➔2534',
	'<!invertedbreve><!grave>➔2535',

	# Additional dead key chains (7).
	'<!circumflex><!circumflex><!group>➔01EF',
	'<!diaeresis><!diaeresis><!group><!group><!group>➔01EE',
	'<!diaeresis><!diaeresis><!group><3>➔01EE',
	'<!macron><!group><!group><!group>➔01EE',
	'<!macron><!group><3>➔01EE',
	'<!diaeresis><!diaeresis><!group>➔01E3',
	'<!diaeresis><!diaeresis><!group><!group>➔0297',

);

# Generates the required chained dead keys.
foreach my $item ( @dead_key_characters ) {
	$deadkey  = substr( $item, 0, -5 );
	$deadkey  =~ m/(<.+>)(<.+>)/;
	$deadchar = get_dead_character( $1 );
	$input    = get_dead_character( $2 );
	$input    =~ s/<(.+)>/$1/;
	$input    = dekeysym( $input );
	print DEADKEYS $print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) )
				. "*/ DEADTRANS( " . format_character( $input ) . "\t," . format_character( $deadchar )
				. "\t," . format_character( get_dead_character( $deadkey ) ) . "\t,0x0001), // Virtual dead key’s intermediate chain link\n";
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

	foreach my $item ( @dead_key_characters ) {
		if ( substr( $item, 0, -5 ) eq $deadkey ) {
			$deadkey = substr( $item, -4, 4 );
			last;
		}
	}
	$deadkey = get_multikey_dead_character( $deadkey );
	return $deadkey;
}

sub get_multikey_dead_character {
	my ( $multikey ) = @_;

	$multikey =~ s/^<!M>$/00A6/; # The Multikey.

	unless ( $multikey eq '00A6' ) {
		foreach my $item ( @multikey_dchars ) {
			if ( substr( $item, 0, -5 ) eq $multikey ) {
				$multikey = substr( $item, -4, 4 );
				last;
			}
		}
	}
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
			|| $line =~ /^<[^>]+> * :/       # Multicharacter output for live keys.
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
			$line =~ s/<section>/<\%excsection>/g;
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

			# Store dead keys and multikey in 2 arrays.
			if ( $line =~ /^(#@)?<!M>/ ) {
				if ( $parse_equivalents eq !0 ) {
					if ( $line =~ /^(#@)?<!M><[^>]+><[^>]+>[^<]/ && $support_simple_multikey_equivalents eq !0 ) {
						push( @multikey_out, $line );
					} elsif ( $support_all_multikey_equivalents eq !0 ) {
						push( @multikey_out, $line );
					}
				} else {
					push( @multikey_out, $line );
				}

				# Add to catalog.
				$line =~ m/(<.+>).+/;
				push( @multikey_parsed, $1 );

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

# Case insensitive sorting.
# By courtesy of https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
print( "Case insensitive sorting in progress ---\n" );
print CONSOLE ( "Case insensitive sorting in progress ---\n" );
@dead_key_out      = sort { "\L$a" cmp "\L$b" } @dead_key_out;
@multikey_complete = sort { "\L$a" cmp "\L$b" } @multikey_complete;
@multikey_out      = sort { "\L$a" cmp "\L$b" } @multikey_out;
print( "Case insensitive sorting complete.\n" );
print CONSOLE ( "Case insensitive sorting complete.\n" );

# Define the multikey dead characters.
print( "Defining the multikey dead characters in progress ---\n" );
print CONSOLE ( "Defining the multikey dead characters in progress ---\n" );
foreach my $entry ( @multikey_complete ) {
	$deadkey = $entry;
	push( @multikey_dchars, $entry . '➔' . $dead_hex );
	++$dead_dec;
	$dead_hex = sprintf( "%X", $dead_dec ); # To hex.
}
print( "Defining the multikey dead characters complete.\n" );
print CONSOLE ( "Defining the multikey dead characters complete.\n" );

# Process single-character dead key output without multicharacter input.
print( "Processing the dead key output in progress ---\n" );
print CONSOLE ( "Processing the dead key output in progress ---\n" );
foreach my $line ( @dead_key_out ) {
	if ( $line =~ /" U[0-9A-F]{4,5}/ ) { # Single-character output.
		unless ( $line =~ /<UEF/ ) {       # Multicharacter input.
			$line          =~ m/(<.+>)(<.+>) *: *"(.)" *U([0-9A-F]{4,5}) *# *(.+)/u;
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
print( "Processing the multikey output in progress ---\n" );
print CONSOLE ( "Processing the multikey output in progress ---\n" );
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
				print LOG $high_su . ', ' . $deadkey . "\n";

			} else {
				$uplus_output = 'U+' . $output_code . ' ';
				$high_out     = '';
			}

			$length = length( $full_chain );
			if ( $length > 65 ) {
				$length = 65;
				++$overlong;
			}
			$print = '/*' . $full_chain . ( " " x ( 65 - $length ) ) . "*/ DEADTRANS( " . format_character( $input )
							. "\t," . format_character( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000), // " . $high_out . $delim
							. $input_string . $delim . ' ➔ "' . $output_string . '" ' . $uplus_output . $comment . "\n";
			++$multikey_count;
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
				               . "\t," . format_character( get_multikey_dead_character( $line ) ) . "\t,0x0001), // Intermediate multikey chain link\n";
			}
		} else {
			++$multichar;
			$print = '';
		}
	}
	push( @multikey_print, $print );
}
print( "Processing the multikey output complete.\n" );
print CONSOLE ( "Processing the multikey output complete.\n" );

print MULTIKEY @multikey_print;

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
print( "  $multikey_count potential multikey sequences in $multikey_path.\n" );
print CONSOLE ( "  $multikey_count potential multikey sequences in $multikey_path.\n" );
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

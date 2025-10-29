#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-10-23T2145+0200
# 2025-10-29T2303+0100
# = last modified.
#
# This “dead key converter” takes in the dead key configuration file for Linux,
# Compose.yml, due to having the two replacerulesets documented there built in.
# See Compose.yml # # Notes for maintenance
# And thanks to improved sorting.
# https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
#
# Chained dead keys started being supported on 2025-10-18. New dead key chains
# require a dedicated dead character in get_dead_char, and need to be added in
# @chained for a virtual dead key to be generated. Chains need to be supported
# incrementally, even when there is no output for a given intermediate chain.
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
# are commented out due to conflicts. Multikey is not yet supported.
#
# On 2025-10-29, 1 097 sequences have multicharacter output. Most are letters
# with combining diacritics, since composed letters are standard and mostly do
# not have precomposed equivalents. But Windows is unable to output any of them
# by dead keys due to an improperly designed DEADTRANS macro. As a consequence,
# the sequences are skipped throughout in order to not compromise the "ê" key
# and "ç" key emulations. Windows users are aware that composed letters are to
# be input the other way around.
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
#
# Using old-style file handles.
use strict;
use warnings;
use utf8;
use feature 'unicode_strings';

# By courtesy of https://stackoverflow.com/a/12291409
use open ":std", ":encoding(UTF-8)";

my $input_path = 'Compose.yml';
open( INPUT, '<', $input_path ) or die $!;
print( "Opened file $input_path.\n" );

my $output_path = 'WINDOWS/dead-keys.c';
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );

my $list_path = 'WINDOWS/dead-keys.txt';
open( LIST, '>', $list_path ) or die $!;
print( "Opened file $list_path.\n" );

my $log_path = 'WINDOWS/dead-key-high-log.txt';
open( LOG, '>', $log_path ) or die $!;
print( "Opened file $log_path.\n" );

print( "Processing content from $input_path to $output_path.\n" );

my $parse_on        = !0;
my @dead_key_out    = ();
my @unsupported     = ();
my @high_surrogates = ();
my @bad_format      = ();
my ( $deadkey, $input, $input_string, $output_string, $output_code, $comment, $deadchar, $print,
     $high_su, $high_out, $number_bad_format );
my $delim     = '"';
my $multichar = 0;
my $half      = 0;
my $full      = 0;

sub format_char {
	my ( $character ) = @_;
	if ( $character =~ /^\\?.$/ ) {
		$character = "L'$character'";
	} elsif ( $character =~ /^[0-9a-fA-F]{4}$/ ) {
		$character = '0x' . $character;
	} else {
		unless ( grep( /^$character$/, @bad_format ) ) {
			push( @bad_format, $character );
		}
#		$character = 'badf'; # Comment this out to see the actual string in context.
	}
	return $character;
}

sub dekeysym {
	my ( $keysym ) = @_;
	$keysym =~ s/~spacezerowidth/200B/;
	$keysym =~ s/~space/ /;
	$keysym =~ s/~nobreakspace/00A0/;
	$keysym =~ s/~nobreakthinspace/202F/;
	$keysym =~ s/%exclam/!/;
	$keysym =~ s/%quotedbl/"/;
	$keysym =~ s/%numbersign/#/;
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
	$keysym =~ s/%asciicircum/^/;
	$keysym =~ s/%underscore/_/;
	$keysym =~ s/%grave/`/;
	$keysym =~ s/%braceleft/{/;
	$keysym =~ s/%bar/|/;
	$keysym =~ s/%braceright/}/;
	$keysym =~ s/%asciitilde/~/;
	$keysym =~ s/%aprightsinglequotemark/2019/;
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

sub get_dead_char {
	my ( $deadkey ) = @_;

	# Single-press dead keys (32).
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

	# Dead key chains (561).
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
	$deadkey =~ s/^<!diaeresis><!diaeresis>$/1E73/;#<dead_diaeresis><dead_diaeresis>
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
	$deadkey =~ s/^<!greek><%asciitilde>$/2789/;#<dead_greek><asciitilde>
	$deadkey =~ s/^<!greek><%asciitilde><%backslash>$/2793/;#<dead_greek><asciitilde><backslash>
	$deadkey =~ s/^<!greek><%backslash>$/277F/;#<dead_greek><backslash>
	$deadkey =~ s/^<!greek><%backslash><%asciitilde>$/278A/;#<dead_greek><backslash><asciitilde>
	$deadkey =~ s/^<!greek><%backslash><%quotEuroSign>$/24EB/;#<dead_greek><backslash><EuroSign>
	$deadkey =~ s/^<!greek><%backslash><%quotedbl>$/24EC/;#<dead_greek><backslash><quotedbl>
	$deadkey =~ s/^<!greek><%bracketleft>$/2792/;#<dead_greek><bracketleft>
	$deadkey =~ s/^<!greek><%quotEuroSign>$/2473/;#<dead_greek><EuroSign>
	$deadkey =~ s/^<!greek><%quotEuroSign><%backslash>$/24F4/;#<dead_greek><EuroSign><backslash>
	$deadkey =~ s/^<!greek><%quotedbl>$/246E/;#<dead_greek><quotedbl>
	$deadkey =~ s/^<!greek><%quotedbl><%backslash>$/24F3/;#<dead_greek><quotedbl><backslash>
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
	$deadkey =~ s/^<!macron><!macron>$/1E07/;#<dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!macron><!macron>$/2A60/;#<dead_macron><dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!ogonek>$/01EC/;#<dead_macron><dead_ogonek>
	$deadkey =~ s/^<!macron><!retroflexhook><!superscript>$/0271/;#<dead_macron><UEFD4><UEFD1>
	$deadkey =~ s/^<!macron><!retroflexhook><!turned>$/0270/;#<dead_macron><UEFD4><UEFD5>
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
	$deadkey =~ s/^<!subscript><!turned><!turned>$/1D1A/;#<UEFD2><UEFD5><UEFD5>
	$deadkey =~ s/^<!superscript><!bar>$/A7F8/;#<UEFD1><UEFD8>
	$deadkey =~ s/^<!superscript><!bar><!group>$/1DB6/;#<UEFD1><UEFD8><UEFD0>
	$deadkey =~ s/^<!superscript><!breve>$/1DB1/;#<UEFD1><dead_breve>
	$deadkey =~ s/^<!superscript><!breve><!breve>$/1DB2/;#<UEFD1><dead_breve><dead_breve>
	$deadkey =~ s/^<!superscript><!diaeresis>$/00C4/;#<UEFD1><dead_diaeresis>
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
	$deadkey =~ s/^<!turned><!subscript>$/AB63/;#<UEFD5><UEFD2>
	$deadkey =~ s/^<!turned><!subscript><!subscript>$/AB65/;#<UEFD5><UEFD2><UEFD2>
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
	$deadkey =~ s/^<!turned><!turned><!superscript>$/0297/;#<UEFD5><UEFD5><UEFD1>

	# Additional dead key chains (11).
	$deadkey =~ s/^<!grave><!acute>$/02C5/;#<dead_grave><dead_acute>
	$deadkey =~ s/^<!macron><!retroflexhook>$/02FD/;#<dead_macron><UEFD4>
	$deadkey =~ s/^<!macron><!superscript>$/02E5/;#<dead_macron><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!macron>$/02FE/;#<UEFD4><dead_macron>
	$deadkey =~ s/^<!superscript><!macron>$/02E6/;#<UEFD1><dead_macron>
	$deadkey =~ s/^<!invertedbreve><!group><1>$/023C/;#<dead_invertedbreve><UEFD0><1>
	$deadkey =~ s/^<!turned><!stroke><!turned>$/1D12/;#<UEFD5><dead_stroke><UEFD5>
	$deadkey =~ s/^<!turned><!diaeresis><!turned>$/00CB/;#<UEFD5><dead_diaeresis><UEFD5>
	$deadkey =~ s/^<!superscript><!diaeresis><!superscript>$/1D40/;#<UEFD1><dead_diaeresis><UEFD1>
	$deadkey =~ s/^<!turned><!subscript><!turned>$/02BE/;#<UEFD5><UEFD2><UEFD5>
	$deadkey =~ s/^<!subscript><!turned><!subscript>$/02CF/;#<UEFD2><UEFD5><UEFD2>

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

	# When adding dead key chains, please make sure to add them in @chained, too.

	return $deadkey;
}

# Used to generate the required chained dead keys.
my @chained = (

	# Additional 11.
	'<!grave><!acute>',
	'<!macron><!retroflexhook>',
	'<!macron><!superscript>',
	'<!retroflexhook><!macron>',
	'<!superscript><!macron>',
	'<!invertedbreve><!group><1>',
	'<!turned><!stroke><!turned>',
	'<!turned><!diaeresis><!turned>',
	'<!superscript><!diaeresis><!superscript>',
	'<!turned><!subscript><!turned>',
	'<!subscript><!turned><!subscript>',

	# Main set, 561.
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
	'<!greek><%asciitilde>',
	'<!greek><%asciitilde><%backslash>',
	'<!greek><%backslash>',
	'<!greek><%backslash><%asciitilde>',
	'<!greek><%backslash><%quotEuroSign>',
	'<!greek><%backslash><%quotedbl>',
	'<!greek><%bracketleft>',
	'<!greek><%quotEuroSign>',
	'<!greek><%quotEuroSign><%backslash>',
	'<!greek><%quotedbl>',
	'<!greek><%quotedbl><%backslash>',
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
	'<!macron><!macron>',
	'<!macron><!macron><!macron>',
	'<!macron><!ogonek>',
	'<!macron><!retroflexhook><!superscript>',
	'<!macron><!retroflexhook><!turned>',
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
	'<!subscript><!turned><!turned>',
	'<!superscript><!bar>',
	'<!superscript><!bar><!group>',
	'<!superscript><!breve>',
	'<!superscript><!breve><!breve>',
	'<!superscript><!diaeresis>',
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
	'<!turned><!subscript>',
	'<!turned><!subscript><!subscript>',
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

	# Polytonic and monotonic Greek (256).
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

	# Latin dead key chains for Greek (54).
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
	$deadchar = get_dead_char( $1 );
	$input    = get_dead_char( $2 );
	$input    =~ s/<(.+)>/$1/;
	$input    = dekeysym( $input );
	print OUTPUT $print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) .
	"*/ DEADTRANS( " . format_char( $input ) . "\t," . format_char( $deadchar ) .
	"\t," . format_char( get_dead_char( $deadkey ) ) . "\t,0x0001), // Dead key chain.\n";
}

while ( my $line = <INPUT> ) {
	if ( $line =~ /START_GREEK/ ) {

		# If polytonic Greek should be included, comment this out.
		# $parse_on = !1;

	}
	if ( $line =~ /START_LATIN_BY_DEAD_KEYS/ ) {
		$parse_on = !0;
	}

	if ( $parse_on ) {
		unless ( $line =~ /^<Multi_key>/   # Multikey is not processed.
			|| $line =~ /^<[^>]+> * :/       # Multichar for live keys.
			|| $line =~ /# [Aa]vailable\.?$/ # Empty slots in letter groups.
			|| $line =~ /<KP_/               # Keypad equivalents, a Linux feature.
			|| $line =~ /^#/                 # Annotations.
		) {

			# Remove spaces.
			$line =~ s/ {2,}/ /g;
			$line =~ s/> </></g;

			# Simplify dead key names and prepare for sorting.
			$line =~ s/<dead_/<!/g;

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

			# Prepare for sorting, further decode.
			$line =~ s/<EuroSign>/<\%quotEuroSign>/g;
			$line =~ s/<section>/<\%semsection>/g;
			$line =~ s/<rightsinglequotemark>/<\%aprightsinglequotemark>/g;
			$line =~ s/<(ampersand|apostrophe|asciicircum|asciitilde|asterisk|at|backslash|bar|braceleft|braceright
							|bracketleft|bracketright|colon|comma|dollar|equal|exclam|grave|greater|less|minus|numbersign
							|parenleft|parenright|percent|period|plus|question|quotedbl|semicolon|slash|underscore)>/<\%$1>/gx;
			$line =~ s/<((nobreak)?space)>/<~$1>/g;
			$line =~ s/<U202F>/<~nobreakthinspace>/g;
			$line =~ s/<U200B>/<~spacezerowidth>/g;

			push( @dead_key_out, $line );
		}
	}
}

# Case insensitive sorting.
# By courtesy of https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
@dead_key_out = sort { "\L$a" cmp "\L$b" } @dead_key_out;

foreach my $line ( @dead_key_out ) {

	if ( $line =~ /" U[0-9A-F]{4,5}/ ) {
		unless ( $line =~ /<UEF/ ) {
			$line          =~ m/(<.+>)(<.+>) : "(.+)" U([0-9A-F]{4,5}) # (.+)/u;
			$deadkey       = $1;
			$input         = $2;
			$output_string = $3;
			$output_code   = $4;
			$comment       = $5;

			$deadchar = get_dead_char( $deadkey );
			if ( $deadchar =~ /^<.+>$/ ) {
				unless ( grep( /^$deadchar$/, @unsupported ) ) {
					push( @unsupported, $deadchar );
				}
				$deadchar = 'dead';
			}

			$input = get_dead_char( $input );
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

			$print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . format_char( $input ) .
							"\t," . format_char( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000\t), // " . $high_out . $delim .
							$input_string . $delim . ' ➔ "' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		++$multichar;
		$print = '';
	}

	print OUTPUT $print;

}

@unsupported = sort( @unsupported );
print LIST ( "This is the full list of " . @unsupported . " unsupported dead keys to transpile.\n\n" );
foreach my $line ( @unsupported ) {
	print LIST $line . "\n";
}

@bad_format = sort( @bad_format );
print LIST ( "\n\n\nThis is the full list of " . @bad_format . " characters in a bad format.\n\n" );
foreach my $line ( @bad_format ) {
	print LIST $line . "\n";
}

close( INPUT );
print( "Closed file $input_path.\n" );
close( OUTPUT );
print( "Closed file $output_path.\n" );
close( LOG );
print( "Closed file $log_path.\n" );
close( LIST );
print( "Closed file $list_path.\n\n" );
unless ( @bad_format == 0 ) {
	if ( @bad_format == 1 ) {
		print( '  ' . @bad_format . " character is in a bad format: @bad_format.\n" );
	} else {
		print( '  ' . @bad_format . " characters are in a bad format: @bad_format.\n" );
	}
	print( "  This enumeration is appended as a list in $list_path.\n\n" );
}
@high_surrogates = sort( @high_surrogates );
print( "  $full potentially functional dead key sequences in $output_path.\n" );
print( "  $half additional dead key sequences output only a low surrogate.\n" );
print( "  The " . @high_surrogates . " required high surrogates are @high_surrogates.\n" );
print( "  Their relationship to the dead keys is logged in $log_path.\n" );
unless ( @unsupported == 0 ) {
	if ( @unsupported == 1 ) {
		print( "  The unsupported chained dead key is listed in $list_path.\n" );
	} else {
		print( "  The " . @unsupported . " unsupported chained dead keys are listed in $list_path.\n" );
	}
}
print( "  $multichar unsupported multicharacter output dead key sequences not processed.\n\n" );
print( "Done processing.\n" );

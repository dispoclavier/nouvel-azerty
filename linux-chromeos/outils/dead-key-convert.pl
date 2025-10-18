#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-10-18T2159+0200
# = last modified.
#
# This “dead key converter” takes in the dead key configuration file for Linux,
# Compose.yml, due to having the two replacerulesets documented there under the
# heading "# # Notes for maintenance" built in, and thanks to improved sorting.
# https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
#
# Polytonic Greek is skipped as off-topic, to alleviate development of premium
# user experience on Windows. This saves 1,886 dead key sequences and, above
# all, 256 chained dead keys.
#
# Chained dead keys started being supported on 2025-10-18. New dead key chains
# require a dedicated dead character in get_dead_char, and need to be added in
# @chained for a virtual dead key to be generated. Chains need to be supported
# incrementally, even when there is no output for a given intermediate chain.
# See # # Lenient dead key press
# in Compose.yml
#
# Multikey sequences need to be processed separately. These are unrelated to,
# or not congruent with, the dead key output, as about 100 multikey equivalents
# are commented out due to conflicts. Multikey is not yet supported.
#
# The sequences ending in dead_greek are required because dead_greek is
# duplicated on the position of the at sign on the ASCII symbol map.
#
# Not all chained dead keys are symmetric.
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
# The issue is also documented.
# See Compose.yml # # Order of mixed dead keys
#
# On 2025-10-12, 1 097 sequences have multicharacter output. Most are letters
# with combining diacritics, since composed letters are standard and mostly do
# not have precomposed equivalents. But Windows is unable to output any of them
# by dead keys due to an improperly designed DEADTRANS macro. As a consequence,
# the sequences are skipped throughout in order to not compromise the "ê" key
# and "ç" key emulations. Windows users are aware that composed letters are to
# be input the other way around.
#
# 2 232 dead key sequences yield Latin letters or mathematical symbols encoded
# in the SMP that Windows is unable to output in one go by a dead key. As a
# workaround, the dead key output is restricted to the low surrogate. An input
# method for the high surrogates is provided separately at the root of related
# dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
# most dead keys, at level 4 of the space bar in French mode.
#
# The number of required high surrogates amounts to eight:
#
#     D801, D807,
#     D835, D837, D83C, D83D, D83E,
#     DB40.
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
#     DB40 dead_flag as built-in (tag characters)
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
# XKB keysyms are converted as needed, without directly using keysymdef.h.
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
	$deadkey =~ s/^<!abovedot><!abovedot>$/02C8/;#<dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!abovedot><!abovedot><!acute>$/dead/;#<dead_abovedot><dead_abovedot><dead_acute>
	$deadkey =~ s/^<!abovedot><!abovedot><!acute><!grave>$/dead/;#<dead_abovedot><dead_abovedot><dead_acute><dead_grave>
	$deadkey =~ s/^<!abovedot><!abovedot><!grave>$/dead/;#<dead_abovedot><dead_abovedot><dead_grave>
	$deadkey =~ s/^<!abovedot><!abovedot><!grave><!acute>$/dead/;#<dead_abovedot><dead_abovedot><dead_grave><dead_acute>
	$deadkey =~ s/^<!abovedot><!abovedot><!macron>$/dead/;#<dead_abovedot><dead_abovedot><dead_macron>
	$deadkey =~ s/^<!abovedot><!acute>$/dead/;#<dead_abovedot><dead_acute>
	$deadkey =~ s/^<!abovedot><!acute><!grave>$/dead/;#<dead_abovedot><dead_acute><dead_grave>
	$deadkey =~ s/^<!abovedot><!bar>$/dead/;#<dead_abovedot><UEFD8>
	$deadkey =~ s/^<!abovedot><!belowdot>$/dead/;#<dead_abovedot><dead_belowdot>
	$deadkey =~ s/^<!abovedot><!breve>$/dead/;#<dead_abovedot><dead_breve>
	$deadkey =~ s/^<!abovedot><!caron>$/dead/;#<dead_abovedot><dead_caron>
	$deadkey =~ s/^<!abovedot><!grave>$/dead/;#<dead_abovedot><dead_grave>
	$deadkey =~ s/^<!abovedot><!grave><!acute>$/dead/;#<dead_abovedot><dead_grave><dead_acute>
	$deadkey =~ s/^<!abovedot><!group>$/dead/;#<dead_abovedot><dead_group>
	$deadkey =~ s/^<!abovedot><!group><!group>$/dead/;#<dead_abovedot><dead_group><dead_group>
	$deadkey =~ s/^<!abovedot><!group><!group><!group>$/dead/;#<dead_abovedot><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!abovedot><!group><3>$/dead/;#<dead_abovedot><dead_group><3>
	$deadkey =~ s/^<!abovedot><!macron>$/dead/;#<dead_abovedot><dead_macron>
	$deadkey =~ s/^<!abovehook><!abovehook>$/dead/;#<UEFD3><UEFD3>
	$deadkey =~ s/^<!abovehook><!breve>$/dead/;#<UEFD3><dead_breve>
	$deadkey =~ s/^<!abovehook><!circumflex>$/dead/;#<UEFD3><dead_circumflex>
	$deadkey =~ s/^<!abovehook><!horn>$/dead/;#<UEFD3><dead_horn>
	$deadkey =~ s/^<!abovering><!abovering>$/dead/;#<dead_abovering><dead_abovering>
	$deadkey =~ s/^<!abovering><!acute>$/dead/;#<dead_abovering><dead_acute>
	$deadkey =~ s/^<!abovering><!currency>$/dead/;#<dead_abovering><dead_currency>
	$deadkey =~ s/^<!abovering><!diaeresis>$/dead/;#<dead_abovering><dead_diaeresis>
	$deadkey =~ s/^<!abovering><!group>$/dead/;#<dead_abovering><dead_group>
	$deadkey =~ s/^<!abovering><!group><!group>$/dead/;#<dead_abovering><dead_group><dead_group>
	$deadkey =~ s/^<!abovering><!group><!group><!group>$/dead/;#<dead_abovering><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!abovering><!group><!group><!group><!group>$/dead/;#<dead_abovering><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!abovering><!group><1>$/dead/;#<dead_abovering><dead_group><1>
	$deadkey =~ s/^<!abovering><!group><2>$/dead/;#<dead_abovering><dead_group><2>
	$deadkey =~ s/^<!abovering><!group><3>$/dead/;#<dead_abovering><dead_group><3>
	$deadkey =~ s/^<!abovering><!group><4>$/dead/;#<dead_abovering><dead_group><4>
	$deadkey =~ s/^<!abovering><!group><5>$/dead/;#<dead_abovering><dead_group><5>
	$deadkey =~ s/^<!acute><!abovedot>$/dead/;#<dead_acute><dead_abovedot>
	$deadkey =~ s/^<!acute><!abovedot><!abovedot>$/dead/;#<dead_acute><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!acute><!abovering>$/dead/;#<dead_acute><dead_abovering>
	$deadkey =~ s/^<!acute><!breve>$/dead/;#<dead_acute><dead_breve>
	$deadkey =~ s/^<!acute><!cedilla>$/dead/;#<dead_acute><dead_cedilla>
	$deadkey =~ s/^<!acute><!circumflex>$/dead/;#<dead_acute><dead_circumflex>
	$deadkey =~ s/^<!acute><!diaeresis>$/dead/;#<dead_acute><dead_diaeresis>
	$deadkey =~ s/^<!acute><!grave>$/dead/;#<dead_acute><dead_grave>
	$deadkey =~ s/^<!acute><!grave><!macron>$/dead/;#<dead_acute><dead_grave><dead_macron>
	$deadkey =~ s/^<!acute><!group>$/dead/;#<dead_acute><dead_group>
	$deadkey =~ s/^<!acute><!group><!group>$/dead/;#<dead_acute><dead_group><dead_group>
	$deadkey =~ s/^<!acute><!horn>$/dead/;#<dead_acute><dead_horn>
	$deadkey =~ s/^<!acute><!macron>$/dead/;#<dead_acute><dead_macron>
	$deadkey =~ s/^<!acute><!macron><!grave>$/dead/;#<dead_acute><dead_macron><dead_grave>
	$deadkey =~ s/^<!acute><!stroke>$/dead/;#<dead_acute><dead_stroke>
	$deadkey =~ s/^<!acute><!tilde>$/dead/;#<dead_acute><dead_tilde>
	$deadkey =~ s/^<!bar><!abovedot>$/dead/;#<UEFD8><dead_abovedot>
	$deadkey =~ s/^<!bar><!bar>$/dead/;#<UEFD8><UEFD8>
	$deadkey =~ s/^<!bar><!bar><!bar>$/dead/;#<UEFD8><UEFD8><UEFD8>
	$deadkey =~ s/^<!bar><!bar><!group>$/dead/;#<UEFD8><UEFD8><dead_group>
	$deadkey =~ s/^<!bar><!bar><!hook>$/dead/;#<UEFD8><UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!bar><!hook><!hook>$/dead/;#<UEFD8><UEFD8><dead_hook><dead_hook>
	$deadkey =~ s/^<!bar><!bar><!hook><!hook><!group>$/dead/;#<UEFD8><UEFD8><dead_hook><dead_hook><dead_group>
	$deadkey =~ s/^<!bar><!group>$/dead/;#<UEFD8><dead_group>
	$deadkey =~ s/^<!bar><!group><!group>$/dead/;#<UEFD8><dead_group><dead_group>
	$deadkey =~ s/^<!bar><!group><!group><!group>$/dead/;#<UEFD8><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!bar><!group><3>$/dead/;#<UEFD8><dead_group><3>
	$deadkey =~ s/^<!bar><!hook>$/dead/;#<UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!bar>$/dead/;#<UEFD8><dead_hook><UEFD8>
	$deadkey =~ s/^<!bar><!hook><!bar><!hook>$/dead/;#<UEFD8><dead_hook><UEFD8><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!bar><!hook><!group>$/dead/;#<UEFD8><dead_hook><UEFD8><dead_hook><dead_group>
	$deadkey =~ s/^<!bar><!hook><!hook>$/dead/;#<UEFD8><dead_hook><dead_hook>
	$deadkey =~ s/^<!bar><!hook><!hook><!bar>$/dead/;#<UEFD8><dead_hook><dead_hook><UEFD8>
	$deadkey =~ s/^<!bar><!hook><!hook><!bar><!group>$/dead/;#<UEFD8><dead_hook><dead_hook><UEFD8><dead_group>
	$deadkey =~ s/^<!bar><!retroflexhook>$/dead/;#<UEFD8><UEFD4>
	$deadkey =~ s/^<!bar><!reversed>$/dead/;#<UEFD8><UEFD6>
	$deadkey =~ s/^<!bar><!stroke>$/dead/;#<UEFD8><dead_stroke>
	$deadkey =~ s/^<!bar><!subscript>$/dead/;#<UEFD8><UEFD2>
	$deadkey =~ s/^<!bar><!superscript>$/dead/;#<UEFD8><UEFD1>
	$deadkey =~ s/^<!bar><!superscript><!group>$/dead/;#<UEFD8><UEFD1><dead_group>
	$deadkey =~ s/^<!bar><!turned>$/dead/;#<UEFD8><UEFD5>
	$deadkey =~ s/^<!bar><!turned><!group>$/dead/;#<UEFD8><UEFD5><dead_group>
	$deadkey =~ s/^<!belowcomma><!belowcomma>$/dead/;#<dead_belowcomma><dead_belowcomma>
	$deadkey =~ s/^<!belowcomma><!group>$/dead/;#<dead_belowcomma><dead_group>
	$deadkey =~ s/^<!belowcomma><!group><!group>$/dead/;#<dead_belowcomma><dead_group><dead_group>
	$deadkey =~ s/^<!belowcomma><!group><!group><!group>$/dead/;#<dead_belowcomma><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!belowcomma><!group><!group><!group><!group>$/dead/;#<dead_belowcomma><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!belowcomma><!group><3>$/dead/;#<dead_belowcomma><dead_group><3>
	$deadkey =~ s/^<!belowcomma><!group><4>$/dead/;#<dead_belowcomma><dead_group><4>
	$deadkey =~ s/^<!belowcomma><!group><5>$/dead/;#<dead_belowcomma><dead_group><5>
	$deadkey =~ s/^<!belowdot><!abovedot>$/dead/;#<dead_belowdot><dead_abovedot>
	$deadkey =~ s/^<!belowdot><!belowdot>$/dead/;#<dead_belowdot><dead_belowdot>
	$deadkey =~ s/^<!belowdot><!breve>$/dead/;#<dead_belowdot><dead_breve>
	$deadkey =~ s/^<!belowdot><!circumflex>$/dead/;#<dead_belowdot><dead_circumflex>
	$deadkey =~ s/^<!belowdot><!horn>$/dead/;#<dead_belowdot><dead_horn>
	$deadkey =~ s/^<!belowdot><!macron>$/dead/;#<dead_belowdot><dead_macron>
	$deadkey =~ s/^<!breve><!abovedot>$/dead/;#<dead_breve><dead_abovedot>
	$deadkey =~ s/^<!breve><!abovehook>$/dead/;#<dead_breve><UEFD3>
	$deadkey =~ s/^<!breve><!acute>$/dead/;#<dead_breve><dead_acute>
	$deadkey =~ s/^<!breve><!belowdot>$/dead/;#<dead_breve><dead_belowdot>
	$deadkey =~ s/^<!breve><!breve>$/dead/;#<dead_breve><dead_breve>
	$deadkey =~ s/^<!breve><!breve><!retroflexhook>$/dead/;#<dead_breve><dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!breve><!retroflexhook><!retroflexhook>$/dead/;#<dead_breve><dead_breve><UEFD4><UEFD4>
	$deadkey =~ s/^<!breve><!breve><!subscript>$/dead/;#<dead_breve><dead_breve><UEFD2>
	$deadkey =~ s/^<!breve><!breve><!superscript>$/dead/;#<dead_breve><dead_breve><UEFD1>
	$deadkey =~ s/^<!breve><!breve><!turned>$/dead/;#<dead_breve><dead_breve><UEFD5>
	$deadkey =~ s/^<!breve><!cedilla>$/dead/;#<dead_breve><dead_cedilla>
	$deadkey =~ s/^<!breve><!grave>$/dead/;#<dead_breve><dead_grave>
	$deadkey =~ s/^<!breve><!macron>$/dead/;#<dead_breve><dead_macron>
	$deadkey =~ s/^<!breve><!retroflexhook>$/dead/;#<dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!breve>$/dead/;#<dead_breve><UEFD4><dead_breve>
	$deadkey =~ s/^<!breve><!retroflexhook><!breve><!retroflexhook>$/dead/;#<dead_breve><UEFD4><dead_breve><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!retroflexhook>$/dead/;#<dead_breve><UEFD4><UEFD4>
	$deadkey =~ s/^<!breve><!retroflexhook><!retroflexhook><!breve>$/dead/;#<dead_breve><UEFD4><UEFD4><dead_breve>
	$deadkey =~ s/^<!breve><!subscript>$/dead/;#<dead_breve><UEFD2>
	$deadkey =~ s/^<!breve><!subscript><!breve>$/dead/;#<dead_breve><UEFD2><dead_breve>
	$deadkey =~ s/^<!breve><!superscript>$/dead/;#<dead_breve><UEFD1>
	$deadkey =~ s/^<!breve><!superscript><!breve>$/dead/;#<dead_breve><UEFD1><dead_breve>
	$deadkey =~ s/^<!breve><!tilde>$/dead/;#<dead_breve><dead_tilde>
	$deadkey =~ s/^<!breve><!turned>$/dead/;#<dead_breve><UEFD5>
	$deadkey =~ s/^<!breve><!turned><!breve>$/dead/;#<dead_breve><UEFD5><dead_breve>
	$deadkey =~ s/^<!caron><!abovedot>$/dead/;#<dead_caron><dead_abovedot>
	$deadkey =~ s/^<!caron><!caron>$/dead/;#<dead_caron><dead_caron>
	$deadkey =~ s/^<!caron><!diaeresis>$/dead/;#<dead_caron><dead_diaeresis>
	$deadkey =~ s/^<!caron><!group>$/dead/;#<dead_caron><dead_group>
	$deadkey =~ s/^<!cedilla><!acute>$/dead/;#<dead_cedilla><dead_acute>
	$deadkey =~ s/^<!cedilla><!breve>$/dead/;#<dead_cedilla><dead_breve>
	$deadkey =~ s/^<!cedilla><!cedilla>$/dead/;#<dead_cedilla><dead_cedilla>
	$deadkey =~ s/^<!circumflex><!abovehook>$/dead/;#<dead_circumflex><UEFD3>
	$deadkey =~ s/^<!circumflex><!acute>$/dead/;#<dead_circumflex><dead_acute>
	$deadkey =~ s/^<!circumflex><!belowdot>$/dead/;#<dead_circumflex><dead_belowdot>
	$deadkey =~ s/^<!circumflex><!circumflex>$/dead/;#<dead_circumflex><dead_circumflex>
	$deadkey =~ s/^<!circumflex><!circumflex><!circumflex>$/dead/;#<dead_circumflex><dead_circumflex><dead_circumflex>
	$deadkey =~ s/^<!circumflex><!grave>$/dead/;#<dead_circumflex><dead_grave>
	$deadkey =~ s/^<!circumflex><!group>$/dead/;#<dead_circumflex><dead_group>
	$deadkey =~ s/^<!circumflex><!group><!group>$/dead/;#<dead_circumflex><dead_group><dead_group>
	$deadkey =~ s/^<!circumflex><!group><!group><!group>$/dead/;#<dead_circumflex><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!circumflex><!group><!group><!group><!group>$/dead/;#<dead_circumflex><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!circumflex><!group><3>$/dead/;#<dead_circumflex><dead_group><3>
	$deadkey =~ s/^<!circumflex><!group><4>$/dead/;#<dead_circumflex><dead_group><4>
	$deadkey =~ s/^<!circumflex><!group><5>$/dead/;#<dead_circumflex><dead_group><5>
	$deadkey =~ s/^<!circumflex><!tilde>$/dead/;#<dead_circumflex><dead_tilde>
	$deadkey =~ s/^<!currency><!abovering>$/dead/;#<dead_currency><dead_abovering>
	$deadkey =~ s/^<!currency><!cedilla>$/dead/;#<dead_currency><dead_cedilla>
	$deadkey =~ s/^<!currency><!currency>$/dead/;#<dead_currency><dead_currency>
	$deadkey =~ s/^<!diaeresis><!abovering>$/dead/;#<dead_diaeresis><dead_abovering>
	$deadkey =~ s/^<!diaeresis><!acute>$/dead/;#<dead_diaeresis><dead_acute>
	$deadkey =~ s/^<!diaeresis><!caron>$/dead/;#<dead_diaeresis><dead_caron>
	$deadkey =~ s/^<!diaeresis><!diaeresis>$/dead/;#<dead_diaeresis><dead_diaeresis>
	$deadkey =~ s/^<!diaeresis><!grave>$/dead/;#<dead_diaeresis><dead_grave>
	$deadkey =~ s/^<!diaeresis><!group>$/dead/;#<dead_diaeresis><dead_group>
	$deadkey =~ s/^<!diaeresis><!group><!group>$/dead/;#<dead_diaeresis><dead_group><dead_group>
	$deadkey =~ s/^<!diaeresis><!macron>$/dead/;#<dead_diaeresis><dead_macron>
	$deadkey =~ s/^<!diaeresis><!superscript>$/dead/;#<dead_diaeresis><UEFD1>
	$deadkey =~ s/^<!diaeresis><!superscript><!superscript>$/dead/;#<dead_diaeresis><UEFD1><UEFD1>
	$deadkey =~ s/^<!diaeresis><!tilde>$/dead/;#<dead_diaeresis><dead_tilde>
	$deadkey =~ s/^<!diaeresis><!turned>$/dead/;#<dead_diaeresis><UEFD5>
	$deadkey =~ s/^<!diaeresis><!turned><!turned>$/dead/;#<dead_diaeresis><UEFD5><UEFD5>
	$deadkey =~ s/^<!doubleacute><!doubleacute>$/dead/;#<dead_doubleacute><dead_doubleacute>
	$deadkey =~ s/^<!doubleacute><!reversed>$/dead/;#<dead_doubleacute><UEFD6>
	$deadkey =~ s/^<!flag><!flag>$/dead/;#<UEFD7><UEFD7>
	$deadkey =~ s/^<!flag><!flag><!flag>$/dead/;#<UEFD7><UEFD7><UEFD7>
	$deadkey =~ s/^<!flag><!group>$/dead/;#<UEFD7><dead_group>
	$deadkey =~ s/^<!flag><!group><!group>$/dead/;#<UEFD7><dead_group><dead_group>
	$deadkey =~ s/^<!flag><!group><!group><!group>$/dead/;#<UEFD7><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!flag><!group><3>$/dead/;#<UEFD7><dead_group><3>
	$deadkey =~ s/^<!flag><~spacezerowidth>$/dead/;#<UEFD7><~spacezerowidth>
	$deadkey =~ s/^<!grave><!abovedot>$/dead/;#<dead_grave><dead_abovedot>
	$deadkey =~ s/^<!grave><!abovedot><!abovedot>$/dead/;#<dead_grave><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!grave><!acute><!macron>$/dead/;#<dead_grave><dead_acute><dead_macron>
	$deadkey =~ s/^<!grave><!breve>$/dead/;#<dead_grave><dead_breve>
	$deadkey =~ s/^<!grave><!circumflex>$/dead/;#<dead_grave><dead_circumflex>
	$deadkey =~ s/^<!grave><!diaeresis>$/dead/;#<dead_grave><dead_diaeresis>
	$deadkey =~ s/^<!grave><!grave>$/dead/;#<dead_grave><dead_grave>
	$deadkey =~ s/^<!grave><!horn>$/dead/;#<dead_grave><dead_horn>
	$deadkey =~ s/^<!grave><!macron>$/dead/;#<dead_grave><dead_macron>
	$deadkey =~ s/^<!grave><!macron><!acute>$/dead/;#<dead_grave><dead_macron><dead_acute>
	$deadkey =~ s/^<!greek><!greek>$/dead/;#<dead_greek><dead_greek>
	$deadkey =~ s/^<!greek><!subscript>$/dead/;#<dead_greek><UEFD2>
	$deadkey =~ s/^<!greek><%asciitilde>$/dead/;#<dead_greek><%asciitilde>
	$deadkey =~ s/^<!greek><%asciitilde><%backslash>$/dead/;#<dead_greek><%asciitilde><%backslash>
	$deadkey =~ s/^<!greek><%backslash>$/dead/;#<dead_greek><%backslash>
	$deadkey =~ s/^<!greek><%backslash><%asciitilde>$/dead/;#<dead_greek><%backslash><%asciitilde>
	$deadkey =~ s/^<!greek><%backslash><%quotEuroSign>$/dead/;#<dead_greek><%backslash><%quotEuroSign>
	$deadkey =~ s/^<!greek><%backslash><%quotedbl>$/dead/;#<dead_greek><%backslash><%quotedbl>
	$deadkey =~ s/^<!greek><%bracketleft>$/dead/;#<dead_greek><%bracketleft>
	$deadkey =~ s/^<!greek><%quotEuroSign>$/dead/;#<dead_greek><%quotEuroSign>
	$deadkey =~ s/^<!greek><%quotEuroSign><%backslash>$/dead/;#<dead_greek><%quotEuroSign><%backslash>
	$deadkey =~ s/^<!greek><%quotedbl>$/dead/;#<dead_greek><%quotedbl>
	$deadkey =~ s/^<!greek><%quotedbl><%backslash>$/dead/;#<dead_greek><%quotedbl><%backslash>
	$deadkey =~ s/^<!group><!group>$/dead/;#<dead_group><dead_group>
	$deadkey =~ s/^<!group><!group><!group>$/dead/;#<dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!group><!group><!group><!group>$/dead/;#<dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!group><0>$/dead/;#<dead_group><0>
	$deadkey =~ s/^<!group><0><%comma>$/dead/;#<dead_group><0><%comma>
	$deadkey =~ s/^<!group><0><%comma><%period>$/dead/;#<dead_group><0><%comma><%period>
	$deadkey =~ s/^<!group><0><%period>$/dead/;#<dead_group><0><%period>
	$deadkey =~ s/^<!group><0><%period><%comma>$/dead/;#<dead_group><0><%period><%comma>
	$deadkey =~ s/^<!group><1>$/dead/;#<dead_group><1>
	$deadkey =~ s/^<!group><2>$/dead/;#<dead_group><2>
	$deadkey =~ s/^<!group><3>$/dead/;#<dead_group><3>
	$deadkey =~ s/^<!group><4>$/dead/;#<dead_group><4>
	$deadkey =~ s/^<!group><5>$/dead/;#<dead_group><5>
	$deadkey =~ s/^<!group><6>$/dead/;#<dead_group><6>
	$deadkey =~ s/^<!group><6><%comma>$/dead/;#<dead_group><6><%comma>
	$deadkey =~ s/^<!group><6><%comma><%comma>$/dead/;#<dead_group><6><%comma><%comma>
	$deadkey =~ s/^<!group><6><%comma><%comma><%period>$/dead/;#<dead_group><6><%comma><%comma><%period>
	$deadkey =~ s/^<!group><6><%comma><%period>$/dead/;#<dead_group><6><%comma><%period>
	$deadkey =~ s/^<!group><6><%comma><%period><%comma>$/dead/;#<dead_group><6><%comma><%period><%comma>
	$deadkey =~ s/^<!group><6><%period>$/dead/;#<dead_group><6><%period>
	$deadkey =~ s/^<!group><6><%period><%comma>$/dead/;#<dead_group><6><%period><%comma>
	$deadkey =~ s/^<!group><6><%period><%comma><%comma>$/dead/;#<dead_group><6><%period><%comma><%comma>
	$deadkey =~ s/^<!group><7>$/dead/;#<dead_group><7>
	$deadkey =~ s/^<!group><7><%comma>$/dead/;#<dead_group><7><%comma>
	$deadkey =~ s/^<!group><7><%period>$/dead/;#<dead_group><7><%period>
	$deadkey =~ s/^<!group><8>$/dead/;#<dead_group><8>
	$deadkey =~ s/^<!group><8><%comma>$/dead/;#<dead_group><8><%comma>
	$deadkey =~ s/^<!group><8><%comma><%period>$/dead/;#<dead_group><8><%comma><%period>
	$deadkey =~ s/^<!group><8><%period>$/dead/;#<dead_group><8><%period>
	$deadkey =~ s/^<!group><8><%period><%comma>$/dead/;#<dead_group><8><%period><%comma>
	$deadkey =~ s/^<!group><9>$/dead/;#<dead_group><9>
	$deadkey =~ s/^<!group><9><%comma>$/dead/;#<dead_group><9><%comma>
	$deadkey =~ s/^<!group><9><%period>$/dead/;#<dead_group><9><%period>
	$deadkey =~ s/^<!group><ellipsis>$/dead/;#<dead_group><ellipsis>
	$deadkey =~ s/^<!hook><!bar>$/dead/;#<dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!bar>$/dead/;#<dead_hook><UEFD8><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!bar><!hook>$/dead/;#<dead_hook><UEFD8><UEFD8><dead_hook>
	$deadkey =~ s/^<!hook><!bar><!bar><!hook><!group>$/dead/;#<dead_hook><UEFD8><UEFD8><dead_hook><dead_group>
	$deadkey =~ s/^<!hook><!bar><!hook>$/dead/;#<dead_hook><UEFD8><dead_hook>
	$deadkey =~ s/^<!hook><!bar><!hook><!bar>$/dead/;#<dead_hook><UEFD8><dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!bar><!hook><!bar><!group>$/dead/;#<dead_hook><UEFD8><dead_hook><UEFD8><dead_group>
	$deadkey =~ s/^<!hook><!group>$/dead/;#<dead_hook><dead_group>
	$deadkey =~ s/^<!hook><!group><!group>$/dead/;#<dead_hook><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!group><!group><!group>$/dead/;#<dead_hook><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!group><3>$/dead/;#<dead_hook><dead_group><3>
	$deadkey =~ s/^<!hook><!hook>$/dead/;#<dead_hook><dead_hook>
	$deadkey =~ s/^<!hook><!hook><!bar>$/dead/;#<dead_hook><dead_hook><UEFD8>
	$deadkey =~ s/^<!hook><!hook><!bar><!bar>$/dead/;#<dead_hook><dead_hook><UEFD8><UEFD8>
	$deadkey =~ s/^<!hook><!hook><!bar><!bar><!group>$/dead/;#<dead_hook><dead_hook><UEFD8><UEFD8><dead_group>
	$deadkey =~ s/^<!hook><!hook><!group>$/dead/;#<dead_hook><dead_hook><dead_group>
	$deadkey =~ s/^<!hook><!hook><!group><!group>$/dead/;#<dead_hook><dead_hook><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!group><!group><!group>$/dead/;#<dead_hook><dead_hook><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!group><!group><!group><!group>$/dead/;#<dead_hook><dead_hook><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!group><3>$/dead/;#<dead_hook><dead_hook><dead_group><3>
	$deadkey =~ s/^<!hook><!hook><!group><4>$/dead/;#<dead_hook><dead_hook><dead_group><4>
	$deadkey =~ s/^<!hook><!hook><!group><5>$/dead/;#<dead_hook><dead_hook><dead_group><5>
	$deadkey =~ s/^<!hook><!hook><!hook>$/dead/;#<dead_hook><dead_hook><dead_hook>
	$deadkey =~ s/^<!hook><!hook><!superscript>$/dead/;#<dead_hook><dead_hook><UEFD1>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group><!group>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><!group><!group><!group>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><3>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><3>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><4>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><4>
	$deadkey =~ s/^<!hook><!hook><!superscript><!group><5>$/dead/;#<dead_hook><dead_hook><UEFD1><dead_group><5>
	$deadkey =~ s/^<!hook><!hook><!turned>$/dead/;#<dead_hook><dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!hook><!turned><!turned>$/dead/;#<dead_hook><dead_hook><UEFD5><UEFD5>
	$deadkey =~ s/^<!hook><!retroflexhook>$/dead/;#<dead_hook><UEFD4>
	$deadkey =~ s/^<!hook><!retroflexhook><!retroflexhook>$/dead/;#<dead_hook><UEFD4><UEFD4>
	$deadkey =~ s/^<!hook><!retroflexhook><!turned>$/dead/;#<dead_hook><UEFD4><UEFD5>
	$deadkey =~ s/^<!hook><!reversed>$/dead/;#<dead_hook><UEFD6>
	$deadkey =~ s/^<!hook><!reversed><!group>$/dead/;#<dead_hook><UEFD6><dead_group>
	$deadkey =~ s/^<!hook><!reversed><!group><!group>$/dead/;#<dead_hook><UEFD6><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!subscript>$/dead/;#<dead_hook><UEFD2>
	$deadkey =~ s/^<!hook><!superscript>$/dead/;#<dead_hook><UEFD1>
	$deadkey =~ s/^<!hook><!superscript><!group>$/dead/;#<dead_hook><UEFD1><dead_group>
	$deadkey =~ s/^<!hook><!superscript><!hook>$/dead/;#<dead_hook><UEFD1><dead_hook>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group><!group>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><!group><!group><!group>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><3>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><3>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><4>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><4>
	$deadkey =~ s/^<!hook><!superscript><!hook><!group><5>$/dead/;#<dead_hook><UEFD1><dead_hook><dead_group><5>
	$deadkey =~ s/^<!hook><!superscript><!turned>$/dead/;#<dead_hook><UEFD1><UEFD5>
	$deadkey =~ s/^<!hook><!tilde>$/dead/;#<dead_hook><dead_tilde>
	$deadkey =~ s/^<!hook><!turned>$/dead/;#<dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!hook>$/dead/;#<dead_hook><UEFD5><dead_hook>
	$deadkey =~ s/^<!hook><!turned><!hook><!turned>$/dead/;#<dead_hook><UEFD5><dead_hook><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!retroflexhook>$/dead/;#<dead_hook><UEFD5><UEFD4>
	$deadkey =~ s/^<!hook><!turned><!superscript>$/dead/;#<dead_hook><UEFD5><UEFD1>
	$deadkey =~ s/^<!hook><!turned><!turned>$/dead/;#<dead_hook><UEFD5><UEFD5>
	$deadkey =~ s/^<!hook><!turned><!turned><!hook>$/dead/;#<dead_hook><UEFD5><UEFD5><dead_hook>
	$deadkey =~ s/^<!horn><!abovehook>$/dead/;#<dead_horn><UEFD3>
	$deadkey =~ s/^<!horn><!acute>$/dead/;#<dead_horn><dead_acute>
	$deadkey =~ s/^<!horn><!belowdot>$/dead/;#<dead_horn><dead_belowdot>
	$deadkey =~ s/^<!horn><!grave>$/dead/;#<dead_horn><dead_grave>
	$deadkey =~ s/^<!horn><!horn>$/dead/;#<dead_horn><dead_horn>
	$deadkey =~ s/^<!horn><!tilde>$/dead/;#<dead_horn><dead_tilde>
	$deadkey =~ s/^<!invertedbreve><!group>$/dead/;#<dead_invertedbreve><dead_group>
	$deadkey =~ s/^<!invertedbreve><!group><!group>$/dead/;#<dead_invertedbreve><dead_group><dead_group>
	$deadkey =~ s/^<!invertedbreve><!group><!group><!group>$/dead/;#<dead_invertedbreve><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!invertedbreve><!group><!group><!group><!group>$/dead/;#<dead_invertedbreve><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!invertedbreve><!group><3>$/dead/;#<dead_invertedbreve><dead_group><3>
	$deadkey =~ s/^<!invertedbreve><!group><4>$/dead/;#<dead_invertedbreve><dead_group><4>
	$deadkey =~ s/^<!invertedbreve><!group><5>$/dead/;#<dead_invertedbreve><dead_group><5>
	$deadkey =~ s/^<!invertedbreve><!invertedbreve>$/dead/;#<dead_invertedbreve><dead_invertedbreve>
	$deadkey =~ s/^<!macron><!abovedot>$/dead/;#<dead_macron><dead_abovedot>
	$deadkey =~ s/^<!macron><!abovedot><!abovedot>$/dead/;#<dead_macron><dead_abovedot><dead_abovedot>
	$deadkey =~ s/^<!macron><!acute>$/dead/;#<dead_macron><dead_acute>
	$deadkey =~ s/^<!macron><!acute><!grave>$/dead/;#<dead_macron><dead_acute><dead_grave>
	$deadkey =~ s/^<!macron><!belowdot>$/dead/;#<dead_macron><dead_belowdot>
	$deadkey =~ s/^<!macron><!breve>$/dead/;#<dead_macron><dead_breve>
	$deadkey =~ s/^<!macron><!diaeresis>$/dead/;#<dead_macron><dead_diaeresis>
	$deadkey =~ s/^<!macron><!grave>$/dead/;#<dead_macron><dead_grave>
	$deadkey =~ s/^<!macron><!grave><!acute>$/dead/;#<dead_macron><dead_grave><dead_acute>
	$deadkey =~ s/^<!macron><!group>$/dead/;#<dead_macron><dead_group>
	$deadkey =~ s/^<!macron><!macron>$/dead/;#<dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!macron><!macron>$/dead/;#<dead_macron><dead_macron><dead_macron>
	$deadkey =~ s/^<!macron><!ogonek>$/dead/;#<dead_macron><dead_ogonek>
	$deadkey =~ s/^<!macron><!retroflexhook><!superscript>$/dead/;#<dead_macron><UEFD4><UEFD1>
	$deadkey =~ s/^<!macron><!retroflexhook><!turned>$/dead/;#<dead_macron><UEFD4><UEFD5>
	$deadkey =~ s/^<!macron><!superscript><!retroflexhook>$/dead/;#<dead_macron><UEFD1><UEFD4>
	$deadkey =~ s/^<!macron><!superscript><!turned>$/dead/;#<dead_macron><UEFD1><UEFD5>
	$deadkey =~ s/^<!macron><!tilde>$/dead/;#<dead_macron><dead_tilde>
	$deadkey =~ s/^<!macron><!turned>$/dead/;#<dead_macron><UEFD5>
	$deadkey =~ s/^<!macron><!turned><!retroflexhook>$/dead/;#<dead_macron><UEFD5><UEFD4>
	$deadkey =~ s/^<!macron><!turned><!superscript>$/dead/;#<dead_macron><UEFD5><UEFD1>
	$deadkey =~ s/^<!ogonek><!macron>$/dead/;#<dead_ogonek><dead_macron>
	$deadkey =~ s/^<!ogonek><!ogonek>$/dead/;#<dead_ogonek><dead_ogonek>
	$deadkey =~ s/^<!retroflexhook><!bar>$/dead/;#<UEFD4><UEFD8>
	$deadkey =~ s/^<!retroflexhook><!breve>$/dead/;#<UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!breve><!breve>$/dead/;#<UEFD4><dead_breve><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!breve><!breve><!retroflexhook>$/dead/;#<UEFD4><dead_breve><dead_breve><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!breve><!retroflexhook>$/dead/;#<UEFD4><dead_breve><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!breve><!retroflexhook><!breve>$/dead/;#<UEFD4><dead_breve><UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!group>$/dead/;#<UEFD4><dead_group>
	$deadkey =~ s/^<!retroflexhook><!group><!group>$/dead/;#<UEFD4><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!group><!group><!group>$/dead/;#<UEFD4><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!group><!group><!group><!group>$/dead/;#<UEFD4><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!group><3>$/dead/;#<UEFD4><dead_group><3>
	$deadkey =~ s/^<!retroflexhook><!group><4>$/dead/;#<UEFD4><dead_group><4>
	$deadkey =~ s/^<!retroflexhook><!group><5>$/dead/;#<UEFD4><dead_group><5>
	$deadkey =~ s/^<!retroflexhook><!hook>$/dead/;#<UEFD4><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!hook><!retroflexhook>$/dead/;#<UEFD4><dead_hook><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!hook><!turned>$/dead/;#<UEFD4><dead_hook><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!macron><!superscript>$/dead/;#<UEFD4><dead_macron><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!macron><!turned>$/dead/;#<UEFD4><dead_macron><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook>$/dead/;#<UEFD4><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!breve>$/dead/;#<UEFD4><UEFD4><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!breve><!breve>$/dead/;#<UEFD4><UEFD4><dead_breve><dead_breve>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group>$/dead/;#<UEFD4><UEFD4><dead_group>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group>$/dead/;#<UEFD4><UEFD4><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group><!group>$/dead/;#<UEFD4><UEFD4><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><!group><!group><!group>$/dead/;#<UEFD4><UEFD4><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><3>$/dead/;#<UEFD4><UEFD4><dead_group><3>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><4>$/dead/;#<UEFD4><UEFD4><dead_group><4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!group><5>$/dead/;#<UEFD4><UEFD4><dead_group><5>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!hook>$/dead/;#<UEFD4><UEFD4><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!retroflexhook>$/dead/;#<UEFD4><UEFD4><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!superscript>$/dead/;#<UEFD4><UEFD4><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!retroflexhook><!turned>$/dead/;#<UEFD4><UEFD4><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!reversed>$/dead/;#<UEFD4><UEFD6>
	$deadkey =~ s/^<!retroflexhook><!reversed><!group>$/dead/;#<UEFD4><UEFD6><dead_group>
	$deadkey =~ s/^<!retroflexhook><!reversed><!group><!group>$/dead/;#<UEFD4><UEFD6><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!superscript>$/dead/;#<UEFD4><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group>$/dead/;#<UEFD4><UEFD1><dead_group>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group>$/dead/;#<UEFD4><UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group><!group>$/dead/;#<UEFD4><UEFD1><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><!group><!group><!group>$/dead/;#<UEFD4><UEFD1><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><3>$/dead/;#<UEFD4><UEFD1><dead_group><3>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><4>$/dead/;#<UEFD4><UEFD1><dead_group><4>
	$deadkey =~ s/^<!retroflexhook><!superscript><!group><5>$/dead/;#<UEFD4><UEFD1><dead_group><5>
	$deadkey =~ s/^<!retroflexhook><!superscript><!macron>$/dead/;#<UEFD4><UEFD1><dead_macron>
	$deadkey =~ s/^<!retroflexhook><!superscript><!retroflexhook>$/dead/;#<UEFD4><UEFD1><UEFD4>
	$deadkey =~ s/^<!retroflexhook><!turned>$/dead/;#<UEFD4><UEFD5>
	$deadkey =~ s/^<!retroflexhook><!turned><!hook>$/dead/;#<UEFD4><UEFD5><dead_hook>
	$deadkey =~ s/^<!retroflexhook><!turned><!macron>$/dead/;#<UEFD4><UEFD5><dead_macron>
	$deadkey =~ s/^<!retroflexhook><!turned><!retroflexhook>$/dead/;#<UEFD4><UEFD5><UEFD4>
	$deadkey =~ s/^<!reversed><!bar>$/dead/;#<UEFD6><UEFD8>
	$deadkey =~ s/^<!reversed><!doubleacute>$/dead/;#<UEFD6><dead_doubleacute>
	$deadkey =~ s/^<!reversed><!group>$/dead/;#<UEFD6><dead_group>
	$deadkey =~ s/^<!reversed><!group><!group>$/dead/;#<UEFD6><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!group><!group><!group>$/dead/;#<UEFD6><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!group><!group><!group><!group>$/dead/;#<UEFD6><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!group><2>$/dead/;#<UEFD6><dead_group><2>
	$deadkey =~ s/^<!reversed><!group><3>$/dead/;#<UEFD6><dead_group><3>
	$deadkey =~ s/^<!reversed><!group><4>$/dead/;#<UEFD6><dead_group><4>
	$deadkey =~ s/^<!reversed><!group><5>$/dead/;#<UEFD6><dead_group><5>
	$deadkey =~ s/^<!reversed><!hook>$/dead/;#<UEFD6><dead_hook>
	$deadkey =~ s/^<!reversed><!hook><!group>$/dead/;#<UEFD6><dead_hook><dead_group>
	$deadkey =~ s/^<!reversed><!hook><!group><!group>$/dead/;#<UEFD6><dead_hook><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!retroflexhook>$/dead/;#<UEFD6><UEFD4>
	$deadkey =~ s/^<!reversed><!retroflexhook><!group>$/dead/;#<UEFD6><UEFD4><dead_group>
	$deadkey =~ s/^<!reversed><!retroflexhook><!group><!group>$/dead/;#<UEFD6><UEFD4><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!subscript>$/dead/;#<UEFD6><UEFD2>
	$deadkey =~ s/^<!reversed><!superscript>$/dead/;#<UEFD6><UEFD1>
	$deadkey =~ s/^<!reversed><!superscript><!group>$/dead/;#<UEFD6><UEFD1><dead_group>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group>$/dead/;#<UEFD6><UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group><!group>$/dead/;#<UEFD6><UEFD1><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!superscript><!group><!group><!group><!group>$/dead/;#<UEFD6><UEFD1><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!reversed><!superscript><!group><3>$/dead/;#<UEFD6><UEFD1><dead_group><3>
	$deadkey =~ s/^<!reversed><!superscript><!group><4>$/dead/;#<UEFD6><UEFD1><dead_group><4>
	$deadkey =~ s/^<!reversed><!superscript><!group><5>$/dead/;#<UEFD6><UEFD1><dead_group><5>
	$deadkey =~ s/^<!stroke><!acute>$/dead/;#<dead_stroke><dead_acute>
	$deadkey =~ s/^<!stroke><!bar>$/dead/;#<dead_stroke><UEFD8>
	$deadkey =~ s/^<!stroke><!group>$/dead/;#<dead_stroke><dead_group>
	$deadkey =~ s/^<!stroke><!group><!group>$/dead/;#<dead_stroke><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!group><!group><!group>$/dead/;#<dead_stroke><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!group><!group><!group><!group>$/dead/;#<dead_stroke><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!group><1>$/dead/;#<dead_stroke><dead_group><1>
	$deadkey =~ s/^<!stroke><!group><2>$/dead/;#<dead_stroke><dead_group><2>
	$deadkey =~ s/^<!stroke><!group><3>$/dead/;#<dead_stroke><dead_group><3>
	$deadkey =~ s/^<!stroke><!group><4>$/dead/;#<dead_stroke><dead_group><4>
	$deadkey =~ s/^<!stroke><!group><5>$/dead/;#<dead_stroke><dead_group><5>
	$deadkey =~ s/^<!stroke><!stroke>$/dead/;#<dead_stroke><dead_stroke>
	$deadkey =~ s/^<!stroke><!stroke><!flag>$/dead/;#<dead_stroke><dead_stroke><UEFD7>
	$deadkey =~ s/^<!stroke><!stroke><!flag><!group>$/dead/;#<dead_stroke><dead_stroke><UEFD7><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!flag><!group><!group>$/dead/;#<dead_stroke><dead_stroke><UEFD7><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!flag><!group><!group><!group>$/dead/;#<dead_stroke><dead_stroke><UEFD7><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!flag><!group><3>$/dead/;#<dead_stroke><dead_stroke><UEFD7><dead_group><3>
	$deadkey =~ s/^<!stroke><!stroke><!group>$/dead/;#<dead_stroke><dead_stroke><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!group><!group>$/dead/;#<dead_stroke><dead_stroke><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!group><!group><!group>$/dead/;#<dead_stroke><dead_stroke><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!stroke><!group><3>$/dead/;#<dead_stroke><dead_stroke><dead_group><3>
	$deadkey =~ s/^<!stroke><!stroke><!stroke>$/dead/;#<dead_stroke><dead_stroke><dead_stroke>
	$deadkey =~ s/^<!stroke><!subscript>$/dead/;#<dead_stroke><UEFD2>
	$deadkey =~ s/^<!stroke><!tilde>$/dead/;#<dead_stroke><dead_tilde>
	$deadkey =~ s/^<!stroke><!turned>$/dead/;#<dead_stroke><UEFD5>
	$deadkey =~ s/^<!stroke><!turned><!group>$/dead/;#<dead_stroke><UEFD5><dead_group>
	$deadkey =~ s/^<!stroke><!turned><!group><!group>$/dead/;#<dead_stroke><UEFD5><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!turned><!group><!group><!group>$/dead/;#<dead_stroke><UEFD5><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!stroke><!turned><!group><3>$/dead/;#<dead_stroke><UEFD5><dead_group><3>
	$deadkey =~ s/^<!stroke><!turned><!turned>$/dead/;#<dead_stroke><UEFD5><UEFD5>
	$deadkey =~ s/^<!subscript><!bar>$/dead/;#<UEFD2><UEFD8>
	$deadkey =~ s/^<!subscript><!breve>$/dead/;#<UEFD2><dead_breve>
	$deadkey =~ s/^<!subscript><!breve><!breve>$/dead/;#<UEFD2><dead_breve><dead_breve>
	$deadkey =~ s/^<!subscript><!greek>$/dead/;#<UEFD2><dead_greek>
	$deadkey =~ s/^<!subscript><!group>$/dead/;#<UEFD2><dead_group>
	$deadkey =~ s/^<!subscript><!group><!group>$/dead/;#<UEFD2><dead_group><dead_group>
	$deadkey =~ s/^<!subscript><!group><!group><!group>$/dead/;#<UEFD2><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!subscript><!group><!group><!group><!group>$/dead/;#<UEFD2><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!subscript><!group><3>$/dead/;#<UEFD2><dead_group><3>
	$deadkey =~ s/^<!subscript><!group><4>$/dead/;#<UEFD2><dead_group><4>
	$deadkey =~ s/^<!subscript><!group><6>$/dead/;#<UEFD2><dead_group><6>
	$deadkey =~ s/^<!subscript><!hook>$/dead/;#<UEFD2><dead_hook>
	$deadkey =~ s/^<!subscript><!reversed>$/dead/;#<UEFD2><UEFD6>
	$deadkey =~ s/^<!subscript><!stroke>$/dead/;#<UEFD2><dead_stroke>
	$deadkey =~ s/^<!subscript><!subscript>$/dead/;#<UEFD2><UEFD2>
	$deadkey =~ s/^<!subscript><!subscript><!turned>$/dead/;#<UEFD2><UEFD2><UEFD5>
	$deadkey =~ s/^<!subscript><!superscript>$/dead/;#<UEFD2><UEFD1>
	$deadkey =~ s/^<!subscript><!superscript><!group>$/dead/;#<UEFD2><UEFD1><dead_group>
	$deadkey =~ s/^<!subscript><!turned>$/dead/;#<UEFD2><UEFD5>
	$deadkey =~ s/^<!subscript><!turned><!turned>$/dead/;#<UEFD2><UEFD5><UEFD5>
	$deadkey =~ s/^<!superscript><!bar>$/dead/;#<UEFD1><UEFD8>
	$deadkey =~ s/^<!superscript><!bar><!group>$/dead/;#<UEFD1><UEFD8><dead_group>
	$deadkey =~ s/^<!superscript><!breve>$/dead/;#<UEFD1><dead_breve>
	$deadkey =~ s/^<!superscript><!breve><!breve>$/dead/;#<UEFD1><dead_breve><dead_breve>
	$deadkey =~ s/^<!superscript><!diaeresis>$/dead/;#<UEFD1><dead_diaeresis>
	$deadkey =~ s/^<!superscript><!group>$/dead/;#<UEFD1><dead_group>
	$deadkey =~ s/^<!superscript><!group><!group>$/dead/;#<UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!group><!group><!group>$/dead/;#<UEFD1><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!group><!group><!group><!group>$/dead/;#<UEFD1><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!group><3>$/dead/;#<UEFD1><dead_group><3>
	$deadkey =~ s/^<!superscript><!group><4>$/dead/;#<UEFD1><dead_group><4>
	$deadkey =~ s/^<!superscript><!group><5>$/dead/;#<UEFD1><dead_group><5>
	$deadkey =~ s/^<!superscript><!group><6>$/dead/;#<UEFD1><dead_group><6>
	$deadkey =~ s/^<!superscript><!hook>$/dead/;#<UEFD1><dead_hook>
	$deadkey =~ s/^<!superscript><!hook><!group>$/dead/;#<UEFD1><dead_hook><dead_group>
	$deadkey =~ s/^<!superscript><!hook><!hook>$/dead/;#<UEFD1><dead_hook><dead_hook>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group><!group>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><!group><!group><!group>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><3>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><3>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><4>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><4>
	$deadkey =~ s/^<!superscript><!hook><!hook><!group><5>$/dead/;#<UEFD1><dead_hook><dead_hook><dead_group><5>
	$deadkey =~ s/^<!superscript><!hook><!turned>$/dead/;#<UEFD1><dead_hook><UEFD5>
	$deadkey =~ s/^<!superscript><!macron><!retroflexhook>$/dead/;#<UEFD1><dead_macron><UEFD4>
	$deadkey =~ s/^<!superscript><!macron><!turned>$/dead/;#<UEFD1><dead_macron><UEFD5>
	$deadkey =~ s/^<!superscript><!retroflexhook>$/dead/;#<UEFD1><UEFD4>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group>$/dead/;#<UEFD1><UEFD4><dead_group>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group>$/dead/;#<UEFD1><UEFD4><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group><!group>$/dead/;#<UEFD1><UEFD4><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><!group><!group><!group>$/dead/;#<UEFD1><UEFD4><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><3>$/dead/;#<UEFD1><UEFD4><dead_group><3>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><4>$/dead/;#<UEFD1><UEFD4><dead_group><4>
	$deadkey =~ s/^<!superscript><!retroflexhook><!group><5>$/dead/;#<UEFD1><UEFD4><dead_group><5>
	$deadkey =~ s/^<!superscript><!retroflexhook><!macron>$/dead/;#<UEFD1><UEFD4><dead_macron>
	$deadkey =~ s/^<!superscript><!retroflexhook><!retroflexhook>$/dead/;#<UEFD1><UEFD4><UEFD4>
	$deadkey =~ s/^<!superscript><!reversed>$/dead/;#<UEFD1><UEFD6>
	$deadkey =~ s/^<!superscript><!reversed><!group>$/dead/;#<UEFD1><UEFD6><dead_group>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group>$/dead/;#<UEFD1><UEFD6><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group><!group>$/dead/;#<UEFD1><UEFD6><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!reversed><!group><!group><!group><!group>$/dead/;#<UEFD1><UEFD6><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!reversed><!group><3>$/dead/;#<UEFD1><UEFD6><dead_group><3>
	$deadkey =~ s/^<!superscript><!reversed><!group><4>$/dead/;#<UEFD1><UEFD6><dead_group><4>
	$deadkey =~ s/^<!superscript><!reversed><!group><5>$/dead/;#<UEFD1><UEFD6><dead_group><5>
	$deadkey =~ s/^<!superscript><!subscript>$/dead/;#<UEFD1><UEFD2>
	$deadkey =~ s/^<!superscript><!subscript><!group>$/dead/;#<UEFD1><UEFD2><dead_group>
	$deadkey =~ s/^<!superscript><!superscript>$/dead/;#<UEFD1><UEFD1>
	$deadkey =~ s/^<!superscript><!superscript><!diaeresis>$/dead/;#<UEFD1><UEFD1><dead_diaeresis>
	$deadkey =~ s/^<!superscript><!superscript><!group>$/dead/;#<UEFD1><UEFD1><dead_group>
	$deadkey =~ s/^<!superscript><!superscript><!group><!group>$/dead/;#<UEFD1><UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!superscript><!group><2>$/dead/;#<UEFD1><UEFD1><dead_group><2>
	$deadkey =~ s/^<!superscript><!tilde>$/dead/;#<UEFD1><dead_tilde>
	$deadkey =~ s/^<!superscript><!turned>$/dead/;#<UEFD1><UEFD5>
	$deadkey =~ s/^<!superscript><!turned><!group>$/dead/;#<UEFD1><UEFD5><dead_group>
	$deadkey =~ s/^<!superscript><!turned><!group><!group>$/dead/;#<UEFD1><UEFD5><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!turned><!group><!group><!group>$/dead/;#<UEFD1><UEFD5><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!superscript><!turned><!group><3>$/dead/;#<UEFD1><UEFD5><dead_group><3>
	$deadkey =~ s/^<!superscript><!turned><!hook>$/dead/;#<UEFD1><UEFD5><dead_hook>
	$deadkey =~ s/^<!superscript><!turned><!macron>$/dead/;#<UEFD1><UEFD5><dead_macron>
	$deadkey =~ s/^<!superscript><!turned><!turned>$/dead/;#<UEFD1><UEFD5><UEFD5>
	$deadkey =~ s/^<!tilde><!acute>$/dead/;#<dead_tilde><dead_acute>
	$deadkey =~ s/^<!tilde><!breve>$/dead/;#<dead_tilde><dead_breve>
	$deadkey =~ s/^<!tilde><!circumflex>$/dead/;#<dead_tilde><dead_circumflex>
	$deadkey =~ s/^<!tilde><!diaeresis>$/dead/;#<dead_tilde><dead_diaeresis>
	$deadkey =~ s/^<!tilde><!hook>$/dead/;#<dead_tilde><dead_hook>
	$deadkey =~ s/^<!tilde><!horn>$/dead/;#<dead_tilde><dead_horn>
	$deadkey =~ s/^<!tilde><!macron>$/dead/;#<dead_tilde><dead_macron>
	$deadkey =~ s/^<!tilde><!stroke>$/dead/;#<dead_tilde><dead_stroke>
	$deadkey =~ s/^<!tilde><!superscript>$/dead/;#<dead_tilde><UEFD1>
	$deadkey =~ s/^<!tilde><!tilde>$/dead/;#<dead_tilde><dead_tilde>
	$deadkey =~ s/^<!tilde><!tilde><!tilde>$/dead/;#<dead_tilde><dead_tilde><dead_tilde>
	$deadkey =~ s/^<!tilde><!tilde><!turned>$/dead/;#<dead_tilde><dead_tilde><UEFD5>
	$deadkey =~ s/^<!tilde><!turned>$/dead/;#<dead_tilde><UEFD5>
	$deadkey =~ s/^<!tilde><!turned><!tilde>$/dead/;#<dead_tilde><UEFD5><dead_tilde>
	$deadkey =~ s/^<!tilde><%ampersand>$/dead/;#<dead_tilde><%ampersand>
	$deadkey =~ s/^<!turned><!bar>$/dead/;#<UEFD5><UEFD8>
	$deadkey =~ s/^<!turned><!bar><!group>$/dead/;#<UEFD5><UEFD8><dead_group>
	$deadkey =~ s/^<!turned><!breve>$/dead/;#<UEFD5><dead_breve>
	$deadkey =~ s/^<!turned><!breve><!breve>$/dead/;#<UEFD5><dead_breve><dead_breve>
	$deadkey =~ s/^<!turned><!diaeresis>$/dead/;#<UEFD5><dead_diaeresis>
	$deadkey =~ s/^<!turned><!group>$/dead/;#<UEFD5><dead_group>
	$deadkey =~ s/^<!turned><!group><!group>$/dead/;#<UEFD5><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!group><!group><!group>$/dead/;#<UEFD5><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!group><!group><!group><!group>$/dead/;#<UEFD5><dead_group><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!group><1>$/dead/;#<UEFD5><dead_group><1>
	$deadkey =~ s/^<!turned><!group><2>$/dead/;#<UEFD5><dead_group><2>
	$deadkey =~ s/^<!turned><!group><3>$/dead/;#<UEFD5><dead_group><3>
	$deadkey =~ s/^<!turned><!group><4>$/dead/;#<UEFD5><dead_group><4>
	$deadkey =~ s/^<!turned><!group><5>$/dead/;#<UEFD5><dead_group><5>
	$deadkey =~ s/^<!turned><!hook>$/dead/;#<UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!hook><!hook>$/dead/;#<UEFD5><dead_hook><dead_hook>
	$deadkey =~ s/^<!turned><!hook><!hook><!turned>$/dead/;#<UEFD5><dead_hook><dead_hook><UEFD5>
	$deadkey =~ s/^<!turned><!hook><!retroflexhook>$/dead/;#<UEFD5><dead_hook><UEFD4>
	$deadkey =~ s/^<!turned><!hook><!superscript>$/dead/;#<UEFD5><dead_hook><UEFD1>
	$deadkey =~ s/^<!turned><!hook><!turned>$/dead/;#<UEFD5><dead_hook><UEFD5>
	$deadkey =~ s/^<!turned><!hook><!turned><!hook>$/dead/;#<UEFD5><dead_hook><UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!macron>$/dead/;#<UEFD5><dead_macron>
	$deadkey =~ s/^<!turned><!macron><!retroflexhook>$/dead/;#<UEFD5><dead_macron><UEFD4>
	$deadkey =~ s/^<!turned><!macron><!superscript>$/dead/;#<UEFD5><dead_macron><UEFD1>
	$deadkey =~ s/^<!turned><!retroflexhook>$/dead/;#<UEFD5><UEFD4>
	$deadkey =~ s/^<!turned><!retroflexhook><!hook>$/dead/;#<UEFD5><UEFD4><dead_hook>
	$deadkey =~ s/^<!turned><!retroflexhook><!macron>$/dead/;#<UEFD5><UEFD4><dead_macron>
	$deadkey =~ s/^<!turned><!retroflexhook><!retroflexhook>$/dead/;#<UEFD5><UEFD4><UEFD4>
	$deadkey =~ s/^<!turned><!stroke>$/dead/;#<UEFD5><dead_stroke>
	$deadkey =~ s/^<!turned><!stroke><!group>$/dead/;#<UEFD5><dead_stroke><dead_group>
	$deadkey =~ s/^<!turned><!stroke><!group><!group>$/dead/;#<UEFD5><dead_stroke><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!stroke><!group><!group><!group>$/dead/;#<UEFD5><dead_stroke><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!stroke><!group><3>$/dead/;#<UEFD5><dead_stroke><dead_group><3>
	$deadkey =~ s/^<!turned><!subscript>$/dead/;#<UEFD5><UEFD2>
	$deadkey =~ s/^<!turned><!subscript><!subscript>$/dead/;#<UEFD5><UEFD2><UEFD2>
	$deadkey =~ s/^<!turned><!superscript>$/dead/;#<UEFD5><UEFD1>
	$deadkey =~ s/^<!turned><!superscript><!group>$/dead/;#<UEFD5><UEFD1><dead_group>
	$deadkey =~ s/^<!turned><!superscript><!group><!group>$/dead/;#<UEFD5><UEFD1><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!superscript><!group><!group><!group>$/dead/;#<UEFD5><UEFD1><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!superscript><!group><3>$/dead/;#<UEFD5><UEFD1><dead_group><3>
	$deadkey =~ s/^<!turned><!superscript><!hook>$/dead/;#<UEFD5><UEFD1><dead_hook>
	$deadkey =~ s/^<!turned><!superscript><!macron>$/dead/;#<UEFD5><UEFD1><dead_macron>
	$deadkey =~ s/^<!turned><!superscript><!turned>$/dead/;#<UEFD5><UEFD1><UEFD5>
	$deadkey =~ s/^<!turned><!tilde>$/dead/;#<UEFD5><dead_tilde>
	$deadkey =~ s/^<!turned><!tilde><!tilde>$/dead/;#<UEFD5><dead_tilde><dead_tilde>
	$deadkey =~ s/^<!turned><!turned>$/dead/;#<UEFD5><UEFD5>
	$deadkey =~ s/^<!turned><!turned><!diaeresis>$/dead/;#<UEFD5><UEFD5><dead_diaeresis>
	$deadkey =~ s/^<!turned><!turned><!group>$/dead/;#<UEFD5><UEFD5><dead_group>
	$deadkey =~ s/^<!turned><!turned><!group><!group>$/dead/;#<UEFD5><UEFD5><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!turned><!group><!group><!group>$/dead/;#<UEFD5><UEFD5><dead_group><dead_group><dead_group>
	$deadkey =~ s/^<!turned><!turned><!group><3>$/dead/;#<UEFD5><UEFD5><dead_group><3>
	$deadkey =~ s/^<!turned><!turned><!hook>$/dead/;#<UEFD5><UEFD5><dead_hook>
	$deadkey =~ s/^<!turned><!turned><!hook><!hook>$/dead/;#<UEFD5><UEFD5><dead_hook><dead_hook>
	$deadkey =~ s/^<!turned><!turned><!stroke>$/dead/;#<UEFD5><UEFD5><dead_stroke>
	$deadkey =~ s/^<!turned><!turned><!subscript>$/dead/;#<UEFD5><UEFD5><UEFD2>
	$deadkey =~ s/^<!turned><!turned><!superscript>$/dead/;#<UEFD5><UEFD5><UEFD1>
	$deadkey =~ s/^<!grave><!acute>$/dead/;#<dead_grave><dead_acute>
	$deadkey =~ s/^<!macron><!retroflexhook>$/dead/;#<dead_macron><UEFD4>
	$deadkey =~ s/^<!macron><!superscript>$/dead/;#<dead_macron><UEFD1>
	$deadkey =~ s/^<!retroflexhook><!macron>$/dead/;#<UEFD4><dead_macron>
	$deadkey =~ s/^<!superscript><!macron>$/dead/;#<UEFD1><dead_macron>

	# When adding a dead key chain, make sure it is supported in @chained, too.

	return $deadkey;
}

my @chained = (
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
	'<!flag><~spacezerowidth>',
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
	'<!stroke><!stroke><!flag>',
	'<!stroke><!stroke><!flag><!group>',
	'<!stroke><!stroke><!flag><!group><!group>',
	'<!stroke><!stroke><!flag><!group><!group><!group>',
	'<!stroke><!stroke><!flag><!group><3>',
	'<!stroke><!stroke><!group>',
	'<!stroke><!stroke><!group><!group>',
	'<!stroke><!stroke><!group><!group><!group>',
	'<!stroke><!stroke><!group><3>',
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
	'<!grave><!acute>',
	'<!macron><!retroflexhook>',
	'<!macron><!superscript>',
	'<!retroflexhook><!macron>',
	'<!superscript><!macron>',
);
foreach my $deadkey ( @chained ) {
	$deadkey  =~ m/(<.+>)(<.+>)/;
	$deadchar = get_dead_char( $1 );
	$input    = get_dead_char( $2 );
	$input    =~ s/<(.+)>/$1/;
	$input    = dekeysym( $input );
	print OUTPUT $print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . format_char( $input ) . "\t," . format_char( $deadchar ) . "\t," . format_char( get_dead_char( $deadkey ) ) . "\t,0x0001), // Dead key chain.\n";
}

while ( my $line = <INPUT> ) {
	if ( $line =~ /START_GREEK/ ) {

		# If polytonic Greek should be included, comment this out.
		$parse_on = !1;

	}
	if ( $line =~ /START_LATIN_BY_DEAD_KEYS/ ) {
		$parse_on = !0;
	}

	if ( $parse_on ) {                   # Polytonic Greek may not be processed.
		unless ( $line =~ /^<Multi_key>/   # Multikey is not processed.
			|| $line =~ /^<[^>]+> * :/       # Multichar for live keys.
			|| $line =~ /# [Aa]vailable\.?$/ # Empty slots in letter groups.
			|| $line =~ /<KP_/               # Keypad equivalents, a Linux feature.
			|| $line =~ /^#/                 # Annotations.
		) {

			# Remove spaces.
			$line =~ s/ {2,}/ /g;
			$line =~ s/> </></g;

			# Decode keysyms.
			$line =~ s/<UEFD0>/<dead_group>/g;
			$line =~ s/<UEFD1>/<dead_superscript>/g;
			$line =~ s/<UEFD2>/<dead_subscript>/g;
			$line =~ s/<UEFD3>/<dead_abovehook>/g;
			$line =~ s/<UEFD4>/<dead_retroflexhook>/g;
			$line =~ s/<UEFD5>/<dead_turned>/g;
			$line =~ s/<UEFD6>/<dead_reversed>/g;
			$line =~ s/<UEFD7>/<dead_flag>/g;
			$line =~ s/<UEFD8>/<dead_bar>/g;
			$line =~ s/<UEFD9>/<dead_legacytilde>/g;
			$line =~ s/<UEFDA>/<dead_legacygrave>/g;
			$line =~ s/<U0190>/<Eopen>/g;
			$line =~ s/<U025B>/<eopen>/g;
			$line =~ s/<U0186>/<Oopen>/g;
			$line =~ s/<U0254>/<oopen>/g;

			# Simplify dead key names and prepare for sorting.
			$line =~ s/<dead_/<!/g;

			# Prepare for sorting, further decode.
			$line =~ s/<EuroSign>/<\%quotEuroSign>/g;
			$line =~ s/<section>/<\%semsection>/g;
			$line =~ s/<rightsinglequotemark>/<\%aprightsinglequotemark>/g;
			$line =~ s/<(ampersand|apostrophe|asciicircum|asciitilde|asterisk|at|backslash|bar|braceleft|braceright|bracketleft|bracketright|colon|comma|dollar|equal|exclam|grave|greater|less|minus|numbersign|parenleft|parenright|percent|period|plus|question|quotedbl|semicolon|slash|underscore)>/<\%$1>/g;
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

			$print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . format_char( $input ) . "\t," . format_char( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000\t), // " . $high_out . $delim . $input_string . $delim . ' ➔ "' . $output_string . '" ' . $comment . "\n";
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
		print( '  ' . @bad_format . " character is in a bad format: @bad_format.\n\n" );
	} else {
		print( '  ' . @bad_format . " characters are in a bad format: @bad_format.\n\n" );
	}
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

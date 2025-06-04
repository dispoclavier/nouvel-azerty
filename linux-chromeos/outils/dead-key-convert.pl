#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-10-14T0744+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-06-01T2127+0200
# 2025-06-05T0150+0200
# = last modified.
#
# This “dead key converter” takes in a preprocessed dead key list derived from
# Compose.yml by running the two replacerulesets documented under the heading
# # # Notes for maintenance, and sorting lines in a case insensitive ascending
# order so as to get uppercase and lowercase together in the output.
#
# Multikey sequences need to be processed separately, since these are either
# unrelated to or not congruent with the dead key output.
#
# The greek dead key terminated sequences are required because dead_greek is
# duplicated on the position of the at sign in the ASCII symbol map.
#
# Since not all chained dead keys are strictly symmetric, and with multikey too
# order may matter or it may not, taking advantage of a full verbatim list like
# the one derived from the lower part of Compose.yml, with multikey equivalents
# removed, but with redundant dead key lists, is advisable. Automating further
# processing is the only working solution when facing 9 500+ dead key sequences
# without their multikey equivalents, that need to be supported separately, by
# connecting them to the dead keys. Asymmetrically chained dead keys are found
# in the following sections.
# See Compose.yml # # GREEK&DIAERESIS&DOUBLEACUTE
# See Compose.yml # # GREEK&DIAERESIS&ACUTE
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
# Asymmetric multikey sequences are found in these sections.
# See Compose.yml #^# Abbreviations, Units and Legal Symbols
# See Compose.yml #^# Tone bars
# See Compose.yml # # Plus minus
#
# The issue is also documented.
# See Compose.yml # # Order of mixed dead keys
#
# On 2025-06-02, 1 091 sequences have multicharacter output. Most are letters
# with combining diacritics, since composed letters are standard and mostly do
# not have precomposed equivalents. But Windows is unable to output any of them
# by dead keys. As a consequence, the sequences are skipped throughout in order
# to not compromise the "ê" key and "ç" key emulations. Windows users are aware
# that composed letters are input the other way around.
#
# 1 926 dead key sequences yield Latin letters or mathematical symbols encoded
# in the SMP that Windows is unable to output in one go by a dead key. As a
# workaround, the dead key output is restricted to the low surrogate. An input
# method for the high surrogates is provided separately at the root of related
# dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
# most dead keys, on level 4 of the space bar in French mode.
#
# The number of required high surrogates amounts to six:
#
#     D801, D807,
#     D835, D837, D83C, D83E.
#
# These can be dispatched among dead keys most straightforwardly as follows:
#
#     D801 dead_superscript (modifier letters)
#     D807 dead_turned [dead_turned] (U+11FB0 "𑾰" LISU LETTER YHA)
#     D835 dead_group (mathematical alphanumeric symbols)
#     D837 dead_bar, dead_breve, dead_hook, dead_retroflexhook (Latin)
#     D83C dead_flag, dead_greek (flag letters, squared letters)
#     D83E dead_group dead_group (wide-headed arrows)
#
# The output is directly in C, where a series of DEADTRANS function calls makes
# for a flat layout of dead key data, while in KLC format, the data is grouped
# under DEADKEY headers. Transpilation by KbdUTool produces C code without any
# of the comments placed in the KLC file. Anyway, KLC only supports end-of-line
# comments, while leading block comments (in addition to EOL comments) are best
# for human readability, and with long lists are more readable than the grouped
# layout. Given that furthermore, the KLC-to-C transpiler in KbdUTool is broken
# and unable to support the Kana Lock levels, using the KLC format is pointless
# and induces a significant amount of waste.
#
# As a result, any DEADTRANS function call can be overridden by a similar call,
# with the same input and the same dead character, but another output, provided
# that the valid call precedes in the C source.
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

my $input_path = 'dead-key-out.yml';
open( INPUT, '<', $input_path ) or die $!;
print( "Opened file $input_path.\n" );

my $output_path = 'WINDOWS/dead-keys.c';
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );

print( "Processing content from $input_path to $output_path.\n" );

my ( $deadkey, $input, $output_string, $output_code, $comment, $deadchar, $print,
     $high_su, $high_out, $number_bad_format );
my $multichar        = 0;
my $half             = 0;
my $full             = 0;
my @high_surrogates  = ();
my @deadkey_high     = ([]);
my @bad_format       = ();

sub keysymsToDchars {
	my ( $deadkeys ) = @_;
	$deadkeys =~ s/!dead_superscript/^/;
	$deadkeys =~ s/!dead_turned/0250/;
	$deadkeys =~ s/!dead_doubleacute/0151/;
	$deadkeys =~ s/!dead_reversed/019E/;
	$deadkeys =~ s/!dead_tilde/00F5/;
	$deadkeys =~ s/!dead_greek/03B5/;
	$deadkeys =~ s/!dead_acute/00E1/;
	$deadkeys =~ s/!dead_hook/0192/;
	$deadkeys =~ s/!dead_retroflexhook/0273/;
	$deadkeys =~ s/!dead_abovedot/1E57/;
	$deadkeys =~ s/!dead_group/2460/;
	$deadkeys =~ s/!dead_currency/00A4/;
	$deadkeys =~ s/!dead_invertedbreve/0213/;
	$deadkeys =~ s/!dead_breve/0115/;
	$deadkeys =~ s/!dead_bar/024D/;
	$deadkeys =~ s/!dead_horn/01A1/;
	$deadkeys =~ s/!dead_subscript/_/;
	$deadkeys =~ s/!dead_ogonek/01EB/;
	$deadkeys =~ s/!dead_abovehook/1EBB/;
	$deadkeys =~ s/!dead_macron/0101/;
	$deadkeys =~ s/!dead_stroke/00F8/;
	$deadkeys =~ s/!dead_abovering/00E5/;
	$deadkeys =~ s/!dead_circumflex/00EA/;
	$deadkeys =~ s/!dead_caron/021F/;
	$deadkeys =~ s/!dead_flag/2690/;
	$deadkeys =~ s/!dead_grave/00F2/;
	$deadkeys =~ s/!dead_cedilla/0229/;
	$deadkeys =~ s/!dead_belowdot/1E05/;
	$deadkeys =~ s/!dead_diaeresis/00EB/;
	$deadkeys =~ s/!dead_belowcomma/0219/;
	$deadkeys =~ s/!dead_legacygrave/`/;
	$deadkeys =~ s/!dead_legacytilde/~/;
	return $deadkeys;
}

sub formatCharacter {
	my ( $character ) = @_;
	if ( $character =~ /^\\?.$/ ) {
		$character = "L'$character'";
	} elsif ( $character =~ /^[0-9a-fA-F]{4}$/ ) {
		$character = '0x' . $character;
	} else {
		unless ( grep( /^$character$/, @bad_format ) ) {
			push( @bad_format, $character );
		}
		$character = 'badf';
	}
	return $character;
}

while ( my $line = <INPUT> ) {
	if ( $line =~ /" U[0-9A-F]{4,5}/ ) {
		unless ( $line =~ /<UEF/ ) {
			$line =~ m/(<.+>)<(.+)> : "(.+)" U([0-9A-F]{4,5}) # (.+)/u;
			$deadkey       = $1;
			$input         = $2;
			$output_string = $3;
			$output_code   = $4;
			$comment       = $5;

			if ( $deadkey =~ /^<[^>]+>$/ ) {
				$deadchar = $deadkey;
				$deadchar =~ s/<(.+)>/$1/;
				$deadchar = keysymsToDchars( $deadchar );
			} else {
				$deadchar = 'dead';
			}

			$input = keysymsToDchars( $input );
			$input =~ s/U([0-9A-F]{4})/$1/;
			$input =~ s/~spacezerowidth/200B/;
			$input =~ s/~space/ /;
			$input =~ s/~nobreakspace/00A0/;
			$input =~ s/~nobreakthinspace/202F/;
			$input =~ s/%exclam/!/;
			$input =~ s/%quotedbl/"/;
			$input =~ s/%numbersign/#/;
			$input =~ s/%dollar/\$/;
			$input =~ s/%percent/%/;
			$input =~ s/%ampersand/&/;
			$input =~ s/%apostrophe/\\'/;
			$input =~ s/%parenleft/(/;
			$input =~ s/%parenright/)/;
			$input =~ s/%asterisk/*/;
			$input =~ s/%plus/+/;
			$input =~ s/%comma/,/;
			$input =~ s/%minus/-/;
			$input =~ s/%period/./;
			$input =~ s/%slash/\//;
			$input =~ s/%colon/:/;
			$input =~ s/%semicolon/;/;
			$input =~ s/%less/</;
			$input =~ s/%equal/=/;
			$input =~ s/%greater/>/;
			$input =~ s/%question/?/;
			$input =~ s/%aat/@/;
			$input =~ s/%bracketleft/[/;
			$input =~ s/%backslash/\\\\/;
			$input =~ s/%bracketright/]/;
			$input =~ s/%asciicircum/^/;
			$input =~ s/%underscore/_/;
			$input =~ s/%grave/`/;
			$input =~ s/%braceleft/{/;
			$input =~ s/%bar/|/;
			$input =~ s/%braceright/}/;
			$input =~ s/%asciitilde/~/;
			$input =~ s/%aprightsinglequotemark/2019/;
			$input =~ s/%semsection/00A7/;
			$input =~ s/%quotEuroSign/20AC/;
			$input =~ s/degree/00B0/;
			$input =~ s/twosuperior/00B2/;
			$input =~ s/threesuperior/00B3/;
			$input =~ s/multiply/00D7/;
			$input =~ s/division/00F7/;
			$input =~ s/paragraph/00A7/;
			$input =~ s/endash/2013/;
			$input =~ s/emdash/2014/;
			$input =~ s/Greek_horizbar/2015/;
			$input =~ s/ellipsis/2026/;
			$input =~ s/guillemotleft/00AB/;
			$input =~ s/guillemotright/00BB/;
			$input =~ s/eacute/00E9/;
			$input =~ s/Eacute/00C9/;
			$input =~ s/egrave/00E8/;
			$input =~ s/Egrave/00C8/;
			$input =~ s/ccedilla/00E7/;
			$input =~ s/Ccedilla/00C7/;
			$input =~ s/agrave/00E0/;
			$input =~ s/Agrave/00C0/;
			$input =~ s/ugrave/00F9/;
			$input =~ s/Ugrave/00F9/;
			$input =~ s/adiaeresis/00E4/;
			$input =~ s/Adiaeresis/00C4/;
			$input =~ s/odiaeresis/00F6/;
			$input =~ s/Odiaeresis/00D6/;
			$input =~ s/udiaeresis/00FC/;
			$input =~ s/Udiaeresis/00DC/;
			$input =~ s/ntilde/00F1/;
			$input =~ s/Ntilde/00D1/;
			$input =~ s/oopen/0254/;
			$input =~ s/Oopen/0186/;

			if ( $output_code =~ /[0-9A-F]{5}/ ) {
				$high_su = sprintf( "%X", ( 55232 + int( hex( $output_code ) / 1024 ) ) );
				unless ( grep( /^$high_su$/, @high_surrogates ) ) {
					push( @high_surrogates, $high_su );
				}
				$high_out    = 'High surrogate: ' . $high_su . '; Unicode: U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
				++$half;
				unless ( grep( { /$deadkey/ && /$high_su/ } @deadkey_high ) ) {
					push( @deadkey_high, ( $deadkey, $high_su ) );
				}
			} else {
				$high_out = '';
				++$full;
			}

			$print = '/*' . $deadkey . "*/\tDEADTRANS(\t" . formatCharacter( $input ) . "\t," . formatCharacter( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000\t), // " . $high_out . '"' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		++$multichar;
		$print = '';
	}
	
	print OUTPUT $print;

}

close( INPUT );
print( "Closed file $input_path.\n" );
close( OUTPUT );
print( "Closed file $output_path.\n\n" );
unless ( @bad_format == 0 ) {
	$number_bad_format = @bad_format;
	print( "  $number_bad_format characters are in a bad format: @bad_format.\n\n" );
}
print( "  $full potentially functional dead key sequences generated.\n" );
print( "  $half additional dead key sequences output only a low surrogate.\n" );
print( "  The required high surrogates are @high_surrogates.\n" );
print( "  Their relationship to the dead keys is @deadkey_high.\n" );
print( "  $multichar multicharacter output dead key sequences not processed.\n\n" );
print( "Done processing.\n" );

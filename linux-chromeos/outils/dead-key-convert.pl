#!/usr/bin/perl
# 2024-10-10T0617+0200
# 2024-12-31T0424+0100
# 2025-01-02T2142+0100
# 2025-06-26T1734+0200
# = last modified.
#
# This “dead key converter” takes in the dead key configuration file for Linux,
# Compose.yml, due to having the two replacerulesets documented there under the
# heading "# # Notes for maintenance" built in, and thanks to improved sorting.
# https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
#
# Multikey sequences need to be processed separately, since these are unrelated
# to or not congruent with the dead key output, as some are commented out.
#
# The sequences ending in dead_greek are required because dead_greek is
# duplicated on the position of the at sign in the ASCII symbol map.
#
# Not all chained dead keys are symmetric.
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
# The issue is also documented.
# See Compose.yml # # Order of mixed dead keys
#
# On 2025-06-22, 1 091 sequences have multicharacter output. Most are letters
# with combining diacritics, since composed letters are standard and mostly do
# not have precomposed equivalents. But Windows is unable to output any of them
# by dead keys. As a consequence, the sequences are skipped throughout in order
# to not compromise the "ê" key and "ç" key emulations. Windows users are aware
# that composed letters are input the other way around.
#
# 2 013 dead key sequences yield Latin letters or mathematical symbols encoded
# in the SMP that Windows is unable to output in one go by a dead key. As a
# workaround, the dead key output is restricted to the low surrogate. An input
# method for the high surrogates is provided separately at the root of related
# dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
# most dead keys, on level 4 of the space bar in French mode.
#
# The number of required high surrogates amounts to eight:
#
#     D801, D807,
#     D835, D837, D83C, D83D, D83E,
#     DB40.
#
# These can be dispatched among dead keys most straightforwardly as follows:
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
# levels. Anyway, KLC only supports end-of-line comments, while leading block
# comments (in addition to EOL comments) are best for human readability, and
# with long lists are more readable than the grouped layout.
#
# As a result, any DEADTRANS macro call can be overridden by a similar call,
# with the same input and the same dead character, but another output, provided
# that the valid call precedes anyhow in the source code.
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

my @dead_key_out      = ();
my @chained_dead_keys = ();
my @high_surrogates   = ();
my @bad_format        = ();
my ( $deadkey, $input, $output_string, $output_code, $comment, $deadchar, $print,
     $high_su, $high_out, $number_bad_format );
my $multichar = 0;
my $half      = 0;
my $full      = 0;

sub keysymsToDchars {
	my ( $deadkeys ) = @_;
	$deadkeys =~ s/!superscript/^/;
	$deadkeys =~ s/!turned/0250/;
	$deadkeys =~ s/!doubleacute/0151/;
	$deadkeys =~ s/!reversed/019E/;
	$deadkeys =~ s/!tilde/00F5/;
	$deadkeys =~ s/!greek/03B5/;
	$deadkeys =~ s/!acute/00E1/;
	$deadkeys =~ s/!hook/0192/;
	$deadkeys =~ s/!retroflexhook/0273/;
	$deadkeys =~ s/!abovedot/1E57/;
	$deadkeys =~ s/!group/2460/;
	$deadkeys =~ s/!currency/00A4/;
	$deadkeys =~ s/!invertedbreve/0213/;
	$deadkeys =~ s/!breve/0115/;
	$deadkeys =~ s/!bar/024D/;
	$deadkeys =~ s/!horn/01A1/;
	$deadkeys =~ s/!subscript/_/;
	$deadkeys =~ s/!ogonek/01EB/;
	$deadkeys =~ s/!abovehook/1EBB/;
	$deadkeys =~ s/!macron/0101/;
	$deadkeys =~ s/!stroke/00F8/;
	$deadkeys =~ s/!abovering/00E5/;
	$deadkeys =~ s/!circumflex/00EA/;
	$deadkeys =~ s/!caron/021F/;
	$deadkeys =~ s/!flag/2690/;
	$deadkeys =~ s/!grave/00F2/;
	$deadkeys =~ s/!cedilla/00E7/;
	$deadkeys =~ s/!belowdot/1E05/;
	$deadkeys =~ s/!diaeresis/00EB/;
	$deadkeys =~ s/!belowcomma/0219/;
	$deadkeys =~ s/!legacygrave/`/;
	$deadkeys =~ s/!legacytilde/~/;
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

	unless ( $line =~ /^<Multi_key>/         # Multikey not yet processed.
		|| $line =~ /^#/                 # Annotations.
		|| $line =~ /^<[^>]+> * :/       # Multichar for live keys.
		|| $line =~ /<KP_/               # Keypad equivalents, a Linux feature.
		|| $line =~ /# [Aa]vailable\.?$/ # Empty slots in letter groups.
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
		
		# Sort and simplify dead key names.
		$line =~ s/<dead_/<!/g;

		# Prepare for sorting, further decode.
		$line =~ s/<EuroSign>/<\%quotEuroSign>/g;
		$line =~ s/<section>/<\%semsection>/g;
		$line =~ s/<at>/<\%aat>/g;
		$line =~ s/<rightsinglequotemark>/<\%aprightsinglequotemark>/g;
		$line =~ s/<(ampersand|apostrophe|asciicircum|asciitilde|asterisk|backslash|bar|braceleft|braceright|bracketleft|bracketright|colon|comma|dollar|equal|exclam|grave|greater|less|minus|numbersign|parenleft|parenright|percent|period|plus|question|quotedbl|semicolon|slash|underscore)>/<\%$1>/g;
		$line =~ s/<((nobreak)?)space>/<~$1space>/g;
		$line =~ s/<U202F>/<~nobreakthinspace>/g;
		$line =~ s/<U200B>/<~spacezerowidth>/g;

		push( @dead_key_out, $line );
	}
}

# Case insensitive sorting.
# By courtesy of https://alvinalexander.com/perl/perl-array-sort-sorting-string-case-insensitive/
@dead_key_out = sort { "\L$a" cmp "\L$b" } @dead_key_out;

foreach my $line ( @dead_key_out ) {

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
				unless ( grep( /^$deadkey$/, @chained_dead_keys ) ) {
					push( @chained_dead_keys, $deadkey );
				}
				
				
				
				
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
				$high_out    = 'High surrogate: ' . $high_su . '; U+' . $output_code . ' ';
				$output_code = sprintf( "%X", ( 56320 + hex( $output_code ) - int( hex( $output_code ) / 1024 ) * 1024 ) );
				++$half;
				print LOG $high_su . ', ' . $deadkey . "\n";

			} else {
				$high_out = '';
				++$full;
			}

			$print = '/*' . $deadkey . ( " " x ( 65 - length( $deadkey ) ) ) . "*/ DEADTRANS( " . formatCharacter( $input ) . "\t," . formatCharacter( $deadchar ) . "\t,0x" . $output_code . "\t,0x0000\t), // " . $high_out . '"' . $output_string . '" ' . $comment . "\n";
		}
	} else {
		++$multichar;
		$print = '';
	}

	print OUTPUT $print;

}

@chained_dead_keys = sort( @chained_dead_keys );
print LIST ( "This is the full list of " . @chained_dead_keys . " chained dead keys to transpile.\n\n" );;
foreach my $line ( @chained_dead_keys ) {
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
	$number_bad_format = @bad_format;
	print( "  $number_bad_format characters are in a bad format: @bad_format.\n\n" );
}
@high_surrogates = sort( @high_surrogates );
print( "  $full potentially functional dead key sequences generated.\n" );
print( "  $half additional dead key sequences output only a low surrogate.\n" );
print( "  The " . @high_surrogates . " required high surrogates are @high_surrogates.\n" );
print( "  Their relationship to the dead keys is logged in $log_path.\n" );
print( "  $multichar unsupported multicharacter output dead key sequences not processed.\n\n" );
print( "Done processing.\n" );

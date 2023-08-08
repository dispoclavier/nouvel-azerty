#!/usr/bin/perl
# 2023-07-19T1747+0200
# 2023-07-23T1447+0200
# 2023-08-08T0752+0200
# Last modified: See datestamp above.
# 
# Generates an HTML table of math symbols, based on Multi_key sequences in
# `Compose.yml`.
#
# The input requires start and end tags.
#
# Alias sequences with no-break space or with right single quotation mark are
# skipped.
#
# Localized tooltips require the Unicode NamesList.txt or equivalents in the
# target locale as configured under `## Character names localization`.
# Descriptors, which means “edited French character names,” are prioritized.
# The file `Udescripteurs.txt` is optimized for developing `Compose.yml` for
# Linux and ChromeOS. At this point it is incomplete as it is based on v10.
# Tooltips for characters added to Unicode after v10 use `ListeNoms.txt`.
#
# The output is designed for use in WordPress.
#
# Using old-style file handles.
use warnings;
use strict;
use utf8;
use feature 'unicode_strings';

# Courtesy https://stackoverflow.com/a/12291409
use open ":std", ":encoding(UTF-8)";


## Character names localization
# my $names_file_path       = 'names/NamesList.txt';
my $names_file_path       = 'names/ListeNoms.txt';
# my $descriptors_file_path = '';
my $descriptors_file_path = 'names/Udescripteurs.txt';


my $file_path = 'Compose.yml';
open( INPUT, '<', $file_path ) or die $!;
print( "Opened file $file_path.\n" );

my $output_directory = 'multikey-tables';
unless ( -d $output_directory ) {
	mkdir $output_directory;
}
my $output_file_name = 'math-table-partial.html';
my $output_path      = "$output_directory/$output_file_name";
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );

print( "Processing math symbols from $file_path to $output_path.\n" );
my $math_flag = !1;
my $table_header_1 = 'Caractère';
my $table_header_2 = 'Séquence de composition';
my $table_header_3 = 'Identifiant Unicode';
my $line = "<figure class=\"wp-block-table alignwide multikey\"><table><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>";
print OUTPUT "$line\n";
my ( $str, $cp, $descrip, $tooltip, $anchor, @anchors, $regex, $test, $index );

while ( my $line = <INPUT> ) {
	if ( $line =~ /START_MATH/ ) {
		$math_flag = !0;
	}
	if ( $line =~ /END_MATH/ ) {
		$math_flag = !1;
	}
	if ( $math_flag ) {
		if ( $line =~ /^</ ) {
			unless ( $line =~ /<nobreakspace>/ || $line =~ /<rightsinglequotemark>/ ) {
				$line =~ s/<Multi_key>/<¦>/g;
				$line =~ s/<space>/<␣>/g;
				$line =~ s/<asciicircum>/<^>/g;
				$line =~ s/<percent>/<%>/g;
				$line =~ s/<braceleft>/<{>/g;
				$line =~ s/<braceright>/<}>/g;
				$line =~ s/<asciitilde>/<~>/g;
				$line =~ s/<at>/<@>/g;
				$line =~ s/<grave>/<`>/g;
				$line =~ s/<apostrophe>/<'>/g;
				$line =~ s/<quotedbl>/<">/g;
				$line =~ s/<ampersand>/<&amp;>/g;
				$line =~ s/<numbersign>/<#>/g;
				$line =~ s/<dollar>/<\$>/g;
				$line =~ s/<parenleft>/<(>/g;
				$line =~ s/<parenright>/<)>/g;
				$line =~ s/<minus>/<->/g;
				$line =~ s/<plus>/<+>/g;
				$line =~ s/<bracketleft>/<[>/g;
				$line =~ s/<bracketright>/<]>/g;
				$line =~ s/<underscore>/<_>/g;
				$line =~ s/<bar>/<|>/g;
				$line =~ s/<slash>/<\/>/g;
				$line =~ s/<asterisk>/<*>/g;
				$line =~ s/<less>/<&lt;>/g;
				$line =~ s/<greater>/<&gt;>/g;
				$line =~ s/<equal>/<=>/g;
				$line =~ s/<backslash>/<\\>/g;
				$line =~ s/<question>/<?>/g;
				$line =~ s/<exclam>/<!>/g;
				$line =~ s/<colon>/<:>/g;
				$line =~ s/<semicolon>/<;>/g;
				$line =~ s/<comma>/<,>/g;
				$line =~ s/<period>/<.>/g;
				$line =~ s/<egrave>/<è>/g;
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;
				$line =~ s/<(.+?)>/$1/g;
				$line =~ s/¦/<span class="tooltip" title="Touche de composition AltGr\/Option + £\$">¦<\/span>/g;
				$line =~ s/␣/<span class="tooltip" title="Espace">␣<\/span>/g;

				# Anchors and localized tooltips:
				$line    =~ m/^.+ : +"(.+?)"/u;
				$str     = $1;
				$cp      = ord( $str );
				$cp      = sprintf( "%X", $cp ); # To hex.
				$cp      =~ s/^(..)$/00$1/;
				$cp      =~ s/^(...)$/0$1/;
				$descrip = '';
				if ( $descriptors_file_path ) {
					open( DESCRIP, '<', $descriptors_file_path ) or die $!;
					while ( my $des_line = <DESCRIP> ) {
						if ( $des_line =~ /U$cp;/ ) {
							chomp( $des_line );
							$des_line =~ s/^.+; (.+)$/$1/;
							$descrip = $des_line;
							last;
							close( DESCRIP );
						}
					}
				}
				unless ( $descrip ) {
					open( NAMES, '<', $names_file_path ) or die $!;
					while ( my $name_line = <NAMES> ) {
						if ( $name_line =~ /^$cp\t/ ) {
							chomp( $name_line );
							$name_line =~ s/^.+\t(.+)$/$1/;
							$descrip = $name_line;
							last;
							close( NAMES );
						}
					}
				}
				$tooltip = $descrip . " U+$cp";
				$anchor  = 'U+' . $cp;
				$regex   = quotemeta( $anchor );
				$index   = 0;
				if ( grep( /^$regex$/, @anchors ) ) {
					$test = $regex;
					while ( grep( /^$test$/, @anchors ) ) {
						++$index;
						$test = $regex . '_' . $index;
					}
					$anchor = $anchor . '_' . $index;
				}
				push( @anchors, $anchor );
				
				$line =~ s/^(.+?) : "(.+?)" U(20[DE][0-9A-F]) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor">◌$2<\/a><\/td><td title="$4">U+$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				$line =~ s/^(.+?) : "(.+?)" U([0-9A-F]{4}) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor">$2<\/a><\/td><td title="$4">U+$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				print OUTPUT "$line";
			}
		}
	}
}
$line = '</tbody></table></figure>';
print OUTPUT "$line";

close( INPUT );
close( OUTPUT );
print( "Math table generated.\n\n" );

#!/usr/bin/perl
# 2023-07-19T1747+0200
# 2023-11-02T0819+0100
# 2024-05-16T1520+0200
# 2024-10-28T1417+0100
# 2025-09-25T0143+0200
# = last modified.
#
# Generates an HTML table of math symbols, based on multikey sequences in
# Compose.yml.
#
# The input requires the "START_MATH" start tag, and the "END_MATH" end tag.
#
# Alias sequences with no-break space or with numpad digits are skipped.
#
# The keyboard output is displayed on a white background span (class "bg") with
# a light-blue baseline for the purpose of delimiting whitespace characters and
# clarifying advance width and vertical alignment.
#
# Localized tooltips require the Unicode NamesList.txt and equivalents in the
# target locale as configured under ## Character names localization.
# ListeNoms.txt is used for characters missing from Udescripteurs.txt.
# Characters missing from both are counted and listed with their line number
# in Compose.yml, and documented in English.
#
# In print, Unicode character names may be replaced with descriptors in the
# last column.
#
# The output is designed for use in WordPress, where "{{{anrghg-classes}}}" can
# be replaced with additional CSS classes, as well as "{{{anrghg-value}}}" with
# anything, classes too in this file, using the A.N.R.GHG Publishing Toolkit.
#
# Emoji style display should be deactivated on the page that this math table
# is included in as a partial.
#
#
# Using old-style file handles.
use warnings;
use strict;
use utf8;
use feature 'unicode_strings';

# Courtesy https://stackoverflow.com/a/12291409
use open ":std", ":encoding(UTF-8)";

# Courtesy https://www.geeksforgeeks.org/perl-date-and-time/
use DateTime;

## Character names localization
my $names_file_path       = 'names/NamesList.txt';
my $fr_names_file_path    = 'names/ListeNoms.txt';
my $descriptors_file_path = 'names/Udescripteurs.txt';
my $names_count           = 0;
my $descriptors_count     = 0;
my $missing_count         = 0;
my $missing_log           = '';

my $input_path = 'Compose.yml';
open( INPUT, '<', $input_path ) or die $!;
print( "Opened file $input_path.\n" );

my $output_directory = 'multikey-tables';
unless ( -d $output_directory ) {
	mkdir $output_directory;
	print( "New directory $output_directory/.\n" );
}
my $output_file_name = 'math-table-partial.html';
my $output_path      = "$output_directory/$output_file_name";
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );

print( "Processing math symbols from $input_path to $output_path.\n" );
my $parse_on              = !1;
my $date_legend           = 'Tableau mis à jour le ';

# Courtesy https://stackoverflow.com/a/43881027
my $nowDate               = DateTime->now(time_zone => 'local');
my ($month, $day, $year)  = ($nowDate->month, $nowDate->day, $nowDate->year);
my $date                  = "$day/$month/$year";

my $table_id              = 'tableau-math';
my $table_header_1        = 'Caractère';
my $table_header_2        = 'Séquence de composition';
my $table_header_3        = 'Identifiant Unicode';
my $table_header_title    = 'Cliquer pour basculer entre français et anglais';
my $checkbox_label        = 'Imprimer les descripteurs, non les identifiants';
my $checkbox_checked      = '☑&nbsp;';
my $checkbox_not_checked  = '☐&nbsp;';
my $table_header_4        = 'Descripteur';

print OUTPUT "<input type=\"checkbox\" checked=\"checked\" id=\"print\" />\n";
print OUTPUT "<figure class=\"wp-block-table alignwide multikey math {{{anrghg-classes}}} {{{anrghg-value}}}\">\n";
print OUTPUT "<table id=\"$table_id\"><caption><a href=\"#$table_id\">$date_legend$date</a></caption>";
print OUTPUT "<thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th>";
print OUTPUT "<th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">\n";
print OUTPUT "<span class=\"en\">$table_header_3</span><span class=\"fr\">$table_header_4</span>\n";
print OUTPUT "<label for=\"print\"><div class=\"status\" title=\"$table_header_title\">";
print OUTPUT "<span class=\"fr\">$checkbox_checked</span><span class=\"en\">$checkbox_not_checked</span>$checkbox_label</div></label>\n";
print OUTPUT "</th></tr></thead><tbody>\n";
print OUTPUT "<!-- Symboles mathématiques -->\n";

my ( @anchors, $anchor, $cp, $descrip, $index, $line_nb, $regex, $str, $test, $tooltip );

while ( my $line = <INPUT> ) {
	$line_nb = $.;
	if ( $line =~ /START_MATH/ ) {
		$parse_on = !0;
	}
	if ( $line =~ /END_MATH/ ) {
		$parse_on = !1;
	}
	if ( $parse_on ) {
		if ( $line =~ /^</ ) {
			unless ( $line =~ /<nobreakspace>/ || $line =~ /<KP_/ ) {

				# Collapse spaces.
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;

				# Add tooltips.
				$line =~ s/<Multi_key>/<span class="tooltip" title="Touche de composition AltGr\/Option + ⟦+=}⟧ ou, en mode ASCII, AltGr\/Option + ⟦£\$¤⟧">¦<\/span>/g;
				$line =~ s/<space>/<span class="tooltip" title="Espace">␣<\/span>/g;
				$line =~ s/<rightsinglequotemark>/<span class="tooltip" title="Guillemet apostrophe Touche ⟦4&#x27;{⟧">’<\/span>/g;
				$line =~ s/<apostrophe>/<span class="tooltip" title="Apostrophe ASCII ou guillemet simple générique Touche ⟦5([⟧ en mode français, ou touche ⟦%ù⟧ en mode ASCII, ou AltGr\/Option + U">&#x27;<\/span>/g;

				# Convert remaining ASCII and iconic.
				$line =~ s/<asciicircum>/^/g;
				$line =~ s/<percent>/%/g;
				$line =~ s/<EuroSign>/€/g;
				$line =~ s/<quotedbl>/"/g;
				$line =~ s/<backslash>/\\/g;
				$line =~ s/<asciitilde>/~/g;
				$line =~ s/<at>/@/g;
				$line =~ s/<braceleft>/{/g;
				$line =~ s/<braceright>/}/g;
				$line =~ s/<ampersand>/&amp;/g;
				$line =~ s/<numbersign>/#/g;
				$line =~ s/<dollar>/\$/g;
				$line =~ s/<parenleft>/(/g;
				$line =~ s/<parenright>/)/g;
				$line =~ s/<minus>/-/g;
				$line =~ s/<plus>/+/g;
				$line =~ s/<underscore>/_/g;
				$line =~ s/<bracketleft>/[/g;
				$line =~ s/<bracketright>/]/g;
				$line =~ s/<bar>/|/g;
				$line =~ s/<slash>/\//g;
				$line =~ s/<asterisk>/*/g;
				$line =~ s/<less>/&lt;/g;
				$line =~ s/<greater>/&gt;/g;
				$line =~ s/<equal>/=/g;
				$line =~ s/<grave>/`/g;
				$line =~ s/<comma>/,/g;
				$line =~ s/<question>/?/g;
				$line =~ s/<period>/./g;
				$line =~ s/<exclam>/!/g;
				$line =~ s/<colon>/:/g;
				$line =~ s/<semicolon>/;/g;
				$line =~ s/<section>/§/g;
				$line =~ s/<egrave>/è/g;

				# Remove remaining delimiters.
				$line =~ s/<(.)>/$1/g;

				# Add anchors and localized tooltips.
				$line    =~ m/^.+ : +"(.+?)"/u;
				$str     = $1;
				$cp      = ord( $str ); # Code point.
				$cp      = sprintf( "%X", $cp ); # To hex.
				$cp      =~ s/^(.)$/000$1/;
				$cp      =~ s/^(..)$/00$1/;
				$cp      =~ s/^(...)$/0$1/;
				$descrip = '';
				if ( $descriptors_file_path ) {
					open( LIST, '<', $descriptors_file_path ) or die $!;
					while ( my $des_line = <LIST> ) {
						if ( $des_line =~ /U$cp;/ ) {
							chomp( $des_line );
							$des_line =~ s/^.+; (.+)$/$1/;
							$descrip = $des_line;
							++$descriptors_count;
							last;
						}
					}
					close( LIST );
				}
				unless ( $descrip ) {
					open( LIST, '<', $fr_names_file_path ) or die $!;
					while ( my $name_line = <LIST> ) {
						if ( $name_line =~ /^$cp\t/ ) {
							chomp( $name_line );
							$name_line =~ s/^.+\t(.+)$/$1/;
							$descrip = $name_line;
							++$names_count;
							last;
						}
					}
					close( LIST );
				}
				unless ( $descrip ) {
					++$missing_count;
					$missing_log .= $cp . ' (:' . $line_nb . ")\n";
					open( LIST, '<', $names_file_path ) or die $!;
					while ( my $name_line = <LIST> ) {
						if ( $name_line =~ /^$cp\t/ ) {
							chomp( $name_line );
							$name_line =~ s/^.+\t(.+)$/$1/;
							$descrip = $name_line;
							last;
						}
					}
					close( LIST );
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

				# Anchor end tags are spaced out so as to not match the regex adding a tooltip to anchor elements.
				# (For this to be effective, KSES needs to be turned off when this is loaded into the web page.)
				
				# Diacritics.
				$line =~ s/^(.+?) : "(.+?)" U(20[DE][0-9A-F]) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">◌$2<\/span><\/a ><\/td><td title="$4">U+$3<\/td><td>$1<\/td><td><span class="en">$4<\/span><span class="fr">$descrip<\/span><\/td><\/tr>/;
				
				# Spacing symbols.
				$line =~ s/^(.+?) : "(.+?)" U([0-9A-F]{4,5}) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">$2<\/span><\/a ><\/td><td title="$4">U+$3<\/td><td>$1<\/td><td><span class="en">$4<\/span><span class="fr">$descrip<\/span><\/td><\/tr>/;
				
				print OUTPUT "$line";
			}
		}
	}
}
print OUTPUT "</tbody></table></figure>\n";
close( INPUT );
print( "Closed file $input_path.\n" );
close( OUTPUT );
print( "Closed file $output_path.\n" );
print( "Math table generated in $output_directory/.\n" );
print( "Used $names_count times $fr_names_file_path.\n" );
print( "Used $descriptors_count times $descriptors_file_path.\n" );
if ( $missing_count == 1 ) {
	print( "Not localized: $missing_count name.\n" );
	print( "Affected code point (at line number): $missing_log" );
} elsif ( $missing_count > 1 ) {
	print( "Not localized: $missing_count names.\n" );
	print( "Affected code points (at line numbers):\n$missing_log" );
} else {
	print( "All names localized.\n" );
}

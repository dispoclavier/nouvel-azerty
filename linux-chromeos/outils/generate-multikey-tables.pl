#!/usr/bin/perl
# 2023-08-06T1935+0200
# 2023-08-20T0243+0200
# 2023-11-02T0819+0100
# 2024-05-16T1520+0200
# 2024-10-28T1415+0100
# 2025-10-25T2205+0200
# = last modified.
#
# Generates HTML tables of dedicated non-math multikey sequences found in
# Compose.yml.
#
# In the input file, parsing starts at "START_MULTIKEY", and parsing stops at
# "START_MATH".
#
# Section headings with a caret between the two leading hashes switch files.
#
# The keyboard output is displayed on a white background span (class "bg") with
# a light-blue baseline for the purpose of delimiting whitespace characters and
# clarifying advance width and vertical alignment.
#
# Localized tooltips require the Unicode NamesList.txt or equivalents in the
# target locale as configured under ## Character names localization.
# ListeNoms.txt is used for characters missing from Udescripteurs.txt.
# Characters missing from both are counted and listed with their line number
# in Compose.yml.
#
# The output is designed for use in WordPress, where "{{{anrghg-classes}}}" can
# be replaced with additional CSS classes, as well as "{{{anrghg-value}}}" with
# anything, classes too in this file, using the A.N.R.GHG Publishing Toolkit.
#
# The all-in-one table generated alongside can only be included in web pages in
# WordPress when using the “Include partial” block provided by this plugin, as
# posts with too much code in HTML blocks are not saved.
#
#
# Using old-style file handles.
use strict;
use warnings;
use utf8;
use feature 'unicode_strings';

# By courtesy of https://stackoverflow.com/a/12291409
use open ":std", ":encoding(UTF-8)";

# By courtesy of https://www.geeksforgeeks.org/perl-date-and-time/
use DateTime;

## Convert character names to localized names
# my $names_file_path       = 'names/NamesList.txt';
my $names_file_path       = 'names/ListeNoms.txt';
## Convert character names to descriptors
# my $descriptors_file_path = '';
my $descriptors_file_path = 'names/Udescripteurs.txt';
my $names_count           = 0;
my $descriptors_count     = 0;
my $missing_count         = 0;
my $missing_cp            = '';

my $input_path = 'Compose.yml';
open( INPUT, '<', $input_path ) or die $!;
print( "Opened file $input_path for reading.\n" );

my $output_directory = 'multikey-tables';
unless ( -d $output_directory ) {
	mkdir $output_directory;
	print( "New directory $output_directory/.\n" );
}
my $output_file_name_template = 'multikey-table-partial';
my $output_path_trunk         = "$output_directory/$output_file_name_template";
my $output_file_extension     = '.html';
my $output_path               = "$output_directory/ALL_$output_file_name_template$output_file_extension";
open( WHOLEOUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path for writing.\n" );
my $wholeoutput_path     = $output_path;
my $parsing_on           = !1;
my $date_legend          = 'Tableau mis à jour le ';

# By courtesy of https://stackoverflow.com/a/43881027
my $nowDate              = DateTime->now(time_zone => 'local');
my ($month, $day, $year) = ($nowDate->month, $nowDate->day, $nowDate->year);
my $date                 = "$day/$month/$year";

my $table_id             = 'tableau-compose';
my $table_header_1       = 'Caractère';
my $table_header_2       = 'Séquence de composition';
my $table_header_3       = 'Identifiant Unicode';
my $start_tags_1         = "<figure class=\"wp-block-table alignwide multikey {{{anrghg-classes}}} {{{anrghg-value}}}\"><table id=\"";
my $start_tags_2         = "\">$date_legend$date</a></caption><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>\n";
my $start_tags           = "$start_tags_1$table_id\"><caption><a href=\"#$table_id$start_tags_2";
my $end_tags             = "</tbody></table></figure>\n";
my $section_partial_open = !1;
my ( @anchors, $anchor, $comment, $cp, $descrip, $file_id, $index, $line_nb, $regex, $str, $test, $text, $tooltip, $ucodes );

print WHOLEOUTPUT $start_tags;

while ( my $line = <INPUT> ) {
	$line_nb = $.;
	if ( $line =~ /START_MULTIKEY/ ) {
		$parsing_on = !0;
	}
	if ( $line =~ /START_MATH/ ) {
		$parsing_on = !1;
	}
	if ( $parsing_on ) {
  	if ( $line =~ /^#\^# / ) {
			if ( $section_partial_open ) {
				print OUTPUT $end_tags;
		    close( OUTPUT );
		    print( "Closed file $output_path.\n" );
			}
			$line        =~ s/^....//;
			$line        =~ m/(.+)/;
			$comment     = $1;
			$line        =~ s/,//g;
			$line        =~ s/ /-/g;
			$line        =~ m/(.+)/;
			$file_id     = lc( $1 );
			$output_path = $output_path_trunk . '_' . $file_id . $output_file_extension;
			$table_id    = "tableau-compose-$file_id";
			$start_tags  = "$start_tags_1$table_id\"><caption><a href=\"#$table_id$start_tags_2";
	    open( OUTPUT, '>', $output_path ) or die $!;
			$section_partial_open = !0;
	    print( "Opened file $output_path for writing.\n" );
			print( "Processing multikey sequences from $input_path to $output_path.\n" );
			print OUTPUT $start_tags;
			print OUTPUT "<!-- $comment -->\n";
		}
		# Skip comments, numpad alternatives and output like "en_US.UTF-8/Compose".
		unless ( $line =~ /^#/ || $line =~ /<KP_/ || $line =~ /\/Compose"/ ) {
			if ( $line =~ /<Multi_key>/ ) {

				# Starting from here, this should be in sync with generate-deadkey-tables.pl.
				# Convert dead keys.
				$line =~ s/<Multi_key>/<kbd class="deadkey" title="Touche de composition AltGr\/Option + ⟦+=}⟧ ou AltGr\/Option + ⟦£\$¤⟧ (en mode ASCII uniquement)">¦<\/kbd>/g;
				$line =~ s/<dead_abovedot>/<kbd class="deadkey long" title="Touche morte point en chef Maj + AltGr\/Option + ⟦P⟧">point en chef<\/kbd>/g;
				$line =~ s/<dead_abovering>/<kbd class="deadkey long" title="Touche morte rond en chef Maj + AltGr\/Option + ⟦X⟧">rond en chef<\/kbd>/g;
				$line =~ s/<dead_acute>/<kbd class="deadkey" title="Touche morte accent aigu Touche £\$¤ ou Maj + AltGr\/Option + ⟦U⟧">aigu<\/kbd>/g;
				$line =~ s/<dead_belowcomma>/<kbd class="deadkey long" title="Touche morte virgule souscrite Maj + AltGr\/Option + ⟦§!⟧">virgule souscrite<\/kbd>/g;
				$line =~ s/<dead_belowdot>/<kbd class="deadkey long" title="Touche morte point souscrit Maj + AltGr\/Option + ⟦.;⟧">point souscrit<\/kbd>/g;
				$line =~ s/<dead_breve>/<kbd class="deadkey" title="Touche morte brève Maj + AltGr\/Option + ⟦F⟧">brève<\/kbd>/g;
				$line =~ s/<dead_caron>/<kbd class="deadkey" title="Touche morte hatchek Maj + AltGr\/Option + ⟦V⟧">hatchek<\/kbd>/g;
				$line =~ s/<dead_cedilla>/<kbd class="deadkey" title="Touche morte cédille Maj + AltGr\/Option + ⟦?,⟧">cédille<\/kbd>/g;
				$line =~ s/<dead_circumflex>/<kbd class="deadkey" title="Touche morte accent circonflexe Touche ⟦¨^⟧ ou Maj + AltGr\/Option + ⟦C⟧">circonflexe<\/kbd>/g;
				$line =~ s/<dead_currency>/<kbd class="deadkey long" title="Touche morte monétaire Maj + AltGr\/Option + ⟦S⟧">monétaire<\/kbd>/g;
				$line =~ s/<dead_diaeresis>/<kbd class="deadkey" title="Touche morte tréma Touche ⟦5([⟧ ou Maj + AltGr\/Option + \/:">tréma<\/kbd>/g;
				$line =~ s/<dead_doubleacute>/<kbd class="deadkey" title="Touche morte double accent aigu Maj + AltGr\/Option + ⟦E⟧">double aigu<\/kbd>/g;
				$line =~ s/<dead_grave>/<kbd class="deadkey" title="Touche morte accent grave AltGr\/Option + ⟦£\$¤⟧ ou Maj + AltGr\/Option + ⟦N⟧">grave<\/kbd>/g;
				$line =~ s/<dead_greek>/<kbd class="deadkey" title="Touche morte grec ou cerclé AltGr\/Option + ⟦Y⟧ ou Maj + AltGr\/Option + ⟦Y⟧">grec<\/kbd>/g;
				$line =~ s/<dead_hook>/<kbd class="deadkey" title="Touche morte crosse ou crochet Maj + AltGr\/Option + ⟦I⟧">crosse<\/kbd>/g;
				$line =~ s/<dead_horn>/<kbd class="deadkey" title="Touche morte cornu Maj + AltGr\/Option + ⟦H⟧">cornu<\/kbd>/g;
				$line =~ s/<dead_invertedbreve>/<kbd class="deadkey long" title="Touche morte brève inversée Maj + AltGr\/Option + ⟦D⟧">brève inversée<\/kbd>/g;
				$line =~ s/<dead_macron>/<kbd class="deadkey" title="Touche morte macron Maj + AltGr\/Option + ⟦M⟧">macron<\/kbd>/g;
				$line =~ s/<dead_ogonek>/<kbd class="deadkey" title="Touche morte ogonek Maj + AltGr\/Option + ⟦K⟧">ogonek<\/kbd>/g;
				$line =~ s/<dead_stroke>/<kbd class="deadkey" title="Touche morte barré Maj + AltGr\/Option + ⟦W⟧">barré<\/kbd>/g;
				$line =~ s/<dead_tilde>/<kbd class="deadkey" title="Touche morte tilde AltGr\/Option + ⟦¨^⟧ ou Maj + AltGr\/Option + ⟦T⟧">tilde<\/kbd>/g;
				$line =~ s/<UEFD0>/<kbd class="deadkey" title="Touche morte groupe Touche ⟦µ*⟧ ou Maj + AltGr\/Option + ⟦Q⟧">groupe<\/kbd>/g;
				$line =~ s/<UEFD1>/<kbd class="deadkey" title="Touche morte exposant Maj + AltGr\/Option + ⟦A⟧">exposant<\/kbd>/g;
				$line =~ s/<UEFD2>/<kbd class="deadkey" title="Touche morte indice Maj + AltGr\/Option + ⟦J⟧">indice<\/kbd>/g;
				$line =~ s/<UEFD3>/<kbd class="deadkey long" title="Touche morte crochet en chef Maj + AltGr\/Option + ⟦L⟧">crochet en chef<\/kbd>/g;
				$line =~ s/<UEFD4>/<kbd class="deadkey long" title="Touche morte crochet rétroflexe Maj + AltGr\/Option + ⟦O⟧">crochet rétroflexe<\/kbd>/g;
				$line =~ s/<UEFD5>/<kbd class="deadkey" title="Touche morte tourné Maj + AltGr\/Option + ⟦Z⟧">tourné<\/kbd>/g;
				$line =~ s/<UEFD6>/<kbd class="deadkey" title="Touche morte réfléchi Maj + AltGr\/Option + ⟦R⟧">réfléchi<\/kbd>/g;
				$line =~ s/<UEFD7>/<kbd class="deadkey" title="Touche morte drapeau Maj + AltGr\/Option + ⟦B⟧">drapeau<\/kbd>/g;
				$line =~ s/<UEFD8>/<kbd class="deadkey" title="Touche morte rayé Maj + AltGr\/Option + ⟦G⟧">rayé<\/kbd>/g;
				$line =~ s/<UEFD9>/<kbd class="deadkey long" title="Touche morte tilde rétrocompatible Maj + AltGr\/Option + ⟦2é~⟧">tilde rétrocompatible<\/kbd>/g;
				$line =~ s/<UEFDA>/<kbd class="deadkey long" title="Touche morte accent grave rétrocompatible Maj + AltGr\/Option + ⟦7è`⟧">grave rétrocompatible<\/kbd>/g;

				# Remove spaces.
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;

				# Mark up invisibles or confusables.
				$line =~ s/<U202F>/<kbd class="livekey" title="Espace fine insécable AltFr + ⟦Espace⟧ (en mode français uniquement)">fine insécable<\/kbd>/g;
				$line =~ s/<U200B>/<kbd class="livekey" title="Césure conditionnelle Maj + AltGr\/Option + ⟦Espace⟧ (en mode français uniquement)">espace nulle<\/kbd>/g;
				$line =~ s/<emdash>/<kbd class="livekey" title="Tiret cadratin Maj + ⟦4&#x27;{⟧">— tiret cadratin<\/kbd>/g;
				$line =~ s/<endash>/<kbd class="livekey" title="Tiret demi-cadratin Maj + ⟦3&#x22;#⟧">– tiret demi-cadratin<\/kbd>/g;
				$line =~ s/<U2212>/<kbd class="livekey" title="Signe moins AltFr + ⟦T⟧">− signe moins<\/kbd>/g;
				$line =~ s/<U02BB>/<kbd class="livekey" title="Lettre apostrophe tournée Maj + ⟦8_\\⟧ sur les variantes pour la Polynésie">ʻ lettre apostrophe tournée<\/kbd>/g;
				$line =~ s/<UEF60>/<kbd class="livekey" title="Point d’exclamation espacé AltFr + ⟦§!⟧">[fine insécable]!<\/kbd>/g;
				$line =~ s/<UEF63>/<kbd class="livekey" title="Point d’interrogation espacé AltFr + ⟦?,⟧">[fine insécable]?<\/kbd>/g;

				# Add tooltips.
				$line =~ s/<space>/<span class="tooltip" title="Espace">␣<\/span>/g;
				$line =~ s/<nobreakspace>/<span class="tooltip" title="Espace insécable AltGr\/Option + ⟦Espace⟧ (en mode français uniquement)">⍽<\/span>/g;
				$line =~ s/<rightsinglequotemark>/<span class="tooltip" title="Guillemet apostrophe Touche ⟦4&#x27;{⟧">’<\/span>/g;
				$line =~ s/<apostrophe>/<span class="tooltip" title="Apostrophe ASCII ou guillemet simple générique Touche ⟦+=}⟧ en mode français, ou touche ⟦%ù⟧ en mode ASCII, ou AltGr\/Option + ⟦U⟧">&#x27;<\/span>/g;
				$line =~ s/<degree>/<span class="tooltip" title="Symbole degré Maj + ⟦°)]⟧">°<\/span>/g;
				$line =~ s/<multiply>/<span class="tooltip" title="Symbole multiplication AltFr + ⟦C⟧">×<\/span>/g;
				$line =~ s/<paragraph>/<span class="tooltip" title="Symbole paragraphe américain Maj + AltFr + ⟦P⟧">¶<\/span>/g;
				$line =~ s/<U2039>/<span class="tooltip" title="Guillemet chevron simple AltFr + ⟦¨^⟧">‹<\/span>/g;
				$line =~ s/<U203A>/<span class="tooltip" title="Guillemet chevron simple AltFr + ⟦£\$¤⟧">›<\/span>/g;

				# Convert remaining ASCII and iconic.
				$line =~ s/<asciicircum>/^/g;
				$line =~ s/<percent>/%/g;
				$line =~ s/<EuroSign>/€/g;
				$line =~ s/<quotedbl>/&quot;/g;
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
				$line =~ s/<mu>/µ/g;
				$line =~ s/<agrave>/à/g;
				$line =~ s/<Agrave>/À/g;
				$line =~ s/<egrave>/è/g;
				$line =~ s/<Egrave>/È/g;
				$line =~ s/<ugrave>/ù/g;
				$line =~ s/<Ugrave>/Ù/g;
				$line =~ s/<eacute>/é/g;
				$line =~ s/<Eacute>/É/g;
				$line =~ s/<ccedilla>/ç/g;
				$line =~ s/<Ccedilla>/Ç/g;
				$line =~ s/<adiaeresis>/ä/g;
				$line =~ s/<Adiaeresis>/Ä/g;
				$line =~ s/<odiaeresis>/ö/g;
				$line =~ s/<Odiaeresis>/Ö/g;
				$line =~ s/<udiaeresis>/ü/g;
				$line =~ s/<Udiaeresis>/Ü/g;

				# Convert Unicode keysym to NCR.
				$line =~ s/<U([0-9A-F]{4})>/&#x$1;/g;

				# Format Unicode scalar in comment.
				$line =~ s/U([0-9A-F]{4,5})/U+$1/g;

				# Remove remaining delimiters.
				$line =~ s/<(.)>/$1/g;
				# Down to here, this should be in sync with generate-deadkey-tables.pl.

				# Add ZWNJ between a colon and a parenthesis to prevent WordPress from
				# parsing the sequence as an emoji.
				$line =~ s/:([()])/:&#x200C;$1/g;

				# Translate English comments to French.
				$line =~ s/( # .*) (\d\d?)th-ranking/$1 classé au rang $2/g;
				$line =~ s/( # .*) capitals lock/$1 verrouillage capitales/g;
				$line =~ s/( # .*) Control key ISO symbol/$1 symbole ISO de la touche Contrôle/g;
				$line =~ s/( # .*) emoji with skin tone support/$1 émoji avec prise en charge de la couleur de peau/g;
				$line =~ s/( # .*) Japanese kome/$1 kome japonais/g;
				$line =~ s/( # .*) Japanese tainome/$1 tainome japonais/g;
				$line =~ s/( # .*) level 3 select/$1 AltGr\/Option/g;
				$line =~ s/( # .*) numeric lock/$1 verrouillage numérique/g;
				$line =~ s/( # .*) outline scissors/$1 ciseaux ajourés/g;
				$line =~ s/( # .*) red emoji/$1 émoji rouge/g;
				$line =~ s/( # .*) repurposed as multikey symbol/$1 utilisé comme symbole de composition/g;
				$line =~ s/( # .*) tab with shift tab/$1 Tab avec Majuscule Tab/g;
				$line =~ s/( # .*) bullet/$1 puce/g;
				$line =~ s/( # .*) emoji/$1 émoji/g;
				$line =~ s/( # .*) not/$1 non/g;
				$line =~ s/( # .*) shift/$1 Majuscule/g;

				# Add text style emoji for searchability.
				if ( $line =~ m/ emoji/u ) {
					$line    =~ m/^.+ : +"(.+?)"/u;
					$text    = "$1&#xFE0E; ";
				} else {
					$text    = '';
				}

				# Add localized tooltips.
				$line    =~ m/^.+ : +"(.+?)"/u;
				$str     = $1;
				$tooltip = '';
				$ucodes  = '';
				$anchor  = '';
				until ( $str eq '' ) {
					$cp      = ord( $str );
					$cp      = sprintf( "%X", $cp ); # To hex.
					$cp      =~ s/^(.)$/000$1/;
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
								++$descriptors_count;
								last;
							}
						}
						close( DESCRIP );
					}
					unless ( $descrip ) {
						open( NAMES, '<', $names_file_path ) or die $!;
						while ( my $name_line = <NAMES> ) {
							if ( $name_line =~ /^$cp\t/ ) {
								chomp( $name_line );
								$name_line =~ s/^.+\t(.+)$/$1/;
								$descrip = $name_line;
								++$names_count;
								last;
							}
						}
						close( NAMES );
					}
					unless ( $descrip ) {
						++$missing_count;
						$missing_cp .= $cp . ' (:' . $line_nb . ")\n";
					}
					$tooltip .= $descrip . " U+$cp\n";
					$ucodes  .= "U+$cp<br />";
					$anchor  .= 'U+' . $cp . '-';
					$str     =~ s/.//u;
				}
				$tooltip =~ s/\n$//;
				$ucodes  =~ s/<br \/>$//;
				$anchor  =~ s/-$//;

				# Make sure anchors are unique.
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

				# Anchor end tags are spaced out to prevent adding another tooltip in this table.
				# The white background (span of class bg) clarifies whitespace and vertical alignment.
				# Characters with an XKB keysym instead of their scalar.
				$line =~ s/^(.+?) : +"(.+?)" +(?:[a-z]+ +)?# (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">$2<\/span><\/a ><\/td><td title="$3">$ucodes<\/td><td>$1<\/td><td>$3<\/td><\/tr>/;
				# Combining characters.
				$line =~ s/^(.+?) : +"(.+?)" +(U\+(?:03[0-6]|1A[BC]|1D[C-F]|20[D-F])[0-9A-F]) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">◌$2<\/span><\/a ><\/td><td title="$4">$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				# Other characters.
				$line =~ s/^(.+?) : +"(.+?)" +(U\+[0-9A-F]{4,5}) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">$2<\/span><\/a ><\/td><td title="$4">$text$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				print OUTPUT $line;
				print WHOLEOUTPUT $line;
			}
		}
	}
}
print OUTPUT $end_tags;
print WHOLEOUTPUT $end_tags;

close( INPUT );
print( "Closed file $input_path.\n" );
close( OUTPUT );
print( "Closed file $output_path.\n" );
close( WHOLEOUTPUT );
print( "Closed file $wholeoutput_path.\n" );
print( "Multi_key tables generated in $output_directory/.\n" );
print( "Used $names_count times $names_file_path.\n" );
print( "Used $descriptors_count times $descriptors_file_path.\n" );
if ( $missing_count == 1 ) {
	print( "Not localized: $missing_count name.\n" );
	print( "Affected code point (at line number): $missing_cp" );
} elsif ( $missing_count > 1 ) {
	print( "Not localized: $missing_count names.\n" );
	print( "Affected code points (at line numbers): $missing_cp" );
} else {
	print( "All names localized.\n" );
}

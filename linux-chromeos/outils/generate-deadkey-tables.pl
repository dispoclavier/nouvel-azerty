#!/usr/bin/perl
# 2023-07-23T0239+0200
# 2023-08-06T1934+0200
# 2023-11-22T2327+0100
# = last modified.
#
# Generates HTML tables of dead keys from dead key sequences in `Compose.yml`.
# Multi_key equivalents are skipped.
#
# The input requires start and end tags. Section headings switch files.
#
# Localized tooltips require the Unicode NamesList.txt or equivalents in the
# target locale as configured under `## Character names localization`.
# `ListeNoms.txt` is used for characters missing from `Udescripteurs.txt`.
#
# The output is designed for use in WordPress, where {{{anrghg-classes}}} can
# be replaced with additional CSS classes, as well as {{{anrghg-value}}} with
# anything, classes too in this file, using the A.N.R.GHG Publishing Toolkit.
# The all-in-one table generated alongside can only be included by the
# “Include partial” block of the A.N.R.GHG Publishing Toolkit.
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

my $output_directory = 'deadkey-tables';
unless ( -d $output_directory ) {
	mkdir $output_directory;
}
my $output_file_name_template = 'deadkey-table-partial';
my $output_path_trunk         = "$output_directory/$output_file_name_template";
my $output_file_index         = 0;
my $output_file_extension     = '.html';
my $output_path               = "$output_directory/ALL_$output_file_name_template$output_file_extension";
open( WHOLEOUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );
$output_path = $output_path_trunk . $output_file_extension;
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );
print( "Processing dead keys from $file_path to $output_path.\n" );

my $parse_on       = !1;
my $table_header_1 = 'Caractère(s)';
my $table_header_2 = 'Touches';
my $table_header_3 = 'Identifiant Unicode';
my $start_tags     = "<figure class=\"wp-block-table alignwide deadkeys {{{anrghg-classes}}} {{{anrghg-value}}}\"><table><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>\n";
my $end_tags       = "</tbody></table></figure>\n";
print WHOLEOUTPUT $start_tags;
print OUTPUT $start_tags;
my ( $str, $cp, $descrip, $tooltip, $ucodes, $anchor, @anchors, $regex, $test, $index );

while ( my $line = <INPUT> ) {
	if ( $line =~ /END_MATH/ ) {
		$parse_on = !0;
	}
	if ( $line =~ /START_GROUP_SELECTOR/ ) {
		$parse_on = !1;
	}
	if ( $parse_on ) {
  	if ( $line =~ /^#\*# /
			|| $line =~ /^# # Composed letters for languages in Togo/
			|| $line =~ /^### Ê-key emulation/
			|| $line =~ /^### Quotation mark input method/
			|| $line =~ /^### Shorthands for Portuguese and Spanish/
		) {
			print OUTPUT $end_tags;
	    close( OUTPUT );
	    print( "Closed file $output_path.\n" );
			$line =~ s/^....//;
			$line =~ s/,//g;
			$line =~ s/ /-/g;
			$line =~ m/(.+)/;
			$output_path = $output_path_trunk . '_' . $output_file_index . '_' . $1 . $output_file_extension;
			++$output_file_index;
	    open( OUTPUT, '>', $output_path ) or die $!;
	    print( "Opened file $output_path.\n" );
			print( "Processing dead keys from $file_path to $output_path.\n" );
			print OUTPUT $start_tags;
			print OUTPUT "<!-- $1 -->\n";
		}
		unless ( $line =~ /^<Multi_key>/ || $line =~ /^#/ || $line =~ /<KP_/ ) {
			if ( $line =~ /<Multi_key>/
				|| $line =~ /<dead_abovedot>/
				|| $line =~ /<dead_abovering>/
				|| $line =~ /<dead_acute>/
				|| $line =~ /<dead_belowcomma>/
				|| $line =~ /<dead_belowdot>/
				|| $line =~ /<dead_breve>/
				|| $line =~ /<dead_caron>/
				|| $line =~ /<dead_cedilla>/
				|| $line =~ /<dead_circumflex>/
				|| $line =~ /<dead_currency>/
				|| $line =~ /<dead_diaeresis>/
				|| $line =~ /<dead_doubleacute>/
				|| $line =~ /<dead_grave>/
				|| $line =~ /<dead_greek>/
				|| $line =~ /<dead_hook>/
				|| $line =~ /<dead_horn>/
				|| $line =~ /<dead_invertedbreve>/
				|| $line =~ /<dead_longsolidusoverlay>/
				|| $line =~ /<dead_macron>/
				|| $line =~ /<dead_ogonek>/
				|| $line =~ /<dead_stroke>/
				|| $line =~ /<dead_tilde>/
				|| $line =~ /<UEFD0>/
				|| $line =~ /<UEFD1>/
				|| $line =~ /<UEFD2>/
				|| $line =~ /<UEFD3>/
				|| $line =~ /<UEFD4>/
				|| $line =~ /<UEFD5>/
				|| $line =~ /<UEFD6>/
				|| $line =~ /<UEFD7>/
				|| $line =~ /<UEFD8>/
				|| $line =~ /<UEFD9>/
			) {
				# Dead keys.
				$line =~ s/<Multi_key>/<kbd class="deadkey" title="Touche de composition AltGr\/Option + £\$">¦<\/kbd>/g;
				$line =~ s/<dead_abovedot>/<kbd class="deadkey long" title="Touche morte point en chef Maj + AltGr\/Option + P">point en chef<\/kbd>/g;
				$line =~ s/<dead_abovering>/<kbd class="deadkey long" title="Touche morte rond en chef Maj + AltGr\/Option + X">rond en chef<\/kbd>/g;
				$line =~ s/<dead_acute>/<kbd class="deadkey" title="Touche morte accent aigu Touche £\$ ou Maj + AltGr\/Option + I">aigu<\/kbd>/g;
				$line =~ s/<dead_belowcomma>/<kbd class="deadkey long" title="Touche morte virgule souscrite Maj + AltGr\/Option + §!">virgule souscrite<\/kbd>/g;
				$line =~ s/<dead_belowdot>/<kbd class="deadkey long" title="Touche morte point souscrit Maj + AltGr\/Option + .;">point souscrit<\/kbd>/g;
				$line =~ s/<dead_breve>/<kbd class="deadkey" title="Touche morte brève Maj + AltGr\/Option + F">brève<\/kbd>/g;
				$line =~ s/<dead_caron>/<kbd class="deadkey" title="Touche morte hatchek Maj + AltGr\/Option + V">hatchek<\/kbd>/g;
				$line =~ s/<dead_cedilla>/<kbd class="deadkey" title="Touche morte cédille Maj + AltGr\/Option + ?,">cédille<\/kbd>/g;
				$line =~ s/<dead_circumflex>/<kbd class="deadkey" title="Touche morte accent circonflexe Touche ¨^ ou Maj + AltGr\/Option + C">circonflexe<\/kbd>/g;
				$line =~ s/<dead_currency>/<kbd class="deadkey long" title="Touche morte symbole monétaire Maj + AltGr\/Option + S">monétaire<\/kbd>/g;
				$line =~ s/<dead_diaeresis>/<kbd class="deadkey" title="Touche morte tréma Touche 5( ou Maj + AltGr\/Option + \/:">tréma<\/kbd>/g;
				$line =~ s/<dead_doubleacute>/<kbd class="deadkey" title="Touche morte double accent aigu Maj + AltGr\/Option + U">double aigu<\/kbd>/g;
				$line =~ s/<dead_grave>/<kbd class="deadkey" title="Touche morte accent grave Touche += ou Maj + AltGr\/Option + O">grave<\/kbd>/g;
				$line =~ s/<dead_greek>/<kbd class="deadkey" title="Touche morte lettre grecque Maj + AltGr\/Option + Y">grec<\/kbd>/g;
				$line =~ s/<dead_hook>/<kbd class="deadkey" title="Touche morte crosse ou crochet Maj + AltGr\/Option + E">crosse<\/kbd>/g;
				$line =~ s/<dead_horn>/<kbd class="deadkey" title="Touche morte cornu Maj + AltGr\/Option + H">cornu<\/kbd>/g;
				$line =~ s/<dead_invertedbreve>/<kbd class="deadkey long" title="Touche morte brève inversée Maj + AltGr\/Option + D">brève inversée<\/kbd>/g;
				$line =~ s/<dead_longsolidusoverlay>/<kbd class="deadkey" title="Touche morte barré Maj + AltGr\/Option + W">barré<\/kbd>/g;
				$line =~ s/<dead_macron>/<kbd class="deadkey" title="Touche morte macron Maj + AltGr\/Option + M">macron<\/kbd>/g;
				$line =~ s/<dead_ogonek>/<kbd class="deadkey" title="Touche morte ogonek Maj + AltGr\/Option + J">ogonek<\/kbd>/g;
				$line =~ s/<dead_stroke>/<kbd class="deadkey" title="Touche morte rayé Maj + AltGr\/Option + G">rayé<\/kbd>/g;
				$line =~ s/<dead_tilde>/<kbd class="deadkey" title="Touche morte tilde AltGr\/Option + ¨^ ou Maj + AltGr\/Option + T">tilde<\/kbd>/g;
				$line =~ s/<UEFD0>/<kbd class="deadkey" title="Touche morte sélectrice de groupe Touche µ* ou Maj + AltGr\/Option + Q">groupe<\/kbd>/g;
				$line =~ s/<UEFD1>/<kbd class="deadkey" title="Touche morte exposant Maj + AltGr\/Option + A">exposant<\/kbd>/g;
				$line =~ s/<UEFD2>/<kbd class="deadkey" title="Touche morte indice Maj + AltGr\/Option + L">indice<\/kbd>/g;
				$line =~ s/<UEFD3>/<kbd class="deadkey long" title="Touche morte crochet en chef Maj + AltGr\/Option + K">crochet en chef<\/kbd>/g;
				$line =~ s/<UEFD4>/<kbd class="deadkey long" title="Touche morte crochet rétroflexe Maj + AltGr\/Option + R">crochet rétroflexe<\/kbd>/g;
				$line =~ s/<UEFD5>/<kbd class="deadkey" title="Touche morte tourné Maj + AltGr\/Option + Z">tourné<\/kbd>/g;
				$line =~ s/<UEFD6>/<kbd class="deadkey" title="Touche morte réfléchi Maj + AltGr\/Option + N">réfléchi<\/kbd>/g;
				$line =~ s/<UEFD7>/<kbd class="deadkey" title="Touche morte drapeau Maj + AltGr\/Option + B">drapeau<\/kbd>/g;
				$line =~ s/<UEFD8>/<kbd class="deadkey long" title="Touche morte tilde rétrocompatible Maj + AltGr\/Option + 2é">tilde rétrocompatible<\/kbd>/g;
				$line =~ s/<UEFD9>/<kbd class="deadkey long" title="Touche morte accent grave rétrocompatible Maj + AltGr\/Option + 7è">grave rétrocompatible<\/kbd>/g;
				
				# Remove spaces.
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;
				
				# Invisibles or confusables.
				$line =~ s/<U202F>/<kbd class="livekey" title="Espace fine insécable AltFr + Espace">fine insécable<\/kbd>/g;
				$line =~ s/<U200B>/<kbd class="livekey" title="Césure conditionnelle Maj + AltGr\/Option + Espace">espace nulle<\/kbd>/g;
				$line =~ s/<emdash>/<kbd class="livekey" title="Tiret cadratin Maj + 4&#x27;">— tiret cadratin<\/kbd>/g;
				$line =~ s/<endash>/<kbd class="livekey" title="Tiret demi-cadratin Maj + 3&#x22;">– tiret demi-cadratin<\/kbd>/g;
				$line =~ s/<U2212>/<kbd class="livekey" title="Signe moins AltFr + T">− signe moins<\/kbd>/g;
				$line =~ s/<UEF60>/<kbd class="livekey" title="Point d’exclamation espacé AltFr + .;">[fine insécable]!<\/kbd>/g;
				$line =~ s/<UEF63>/<kbd class="livekey" title="Point d’interrogation espacé AltFr + ?,">[fine insécable]?<\/kbd>/g;
				
				# Tooltips.
				$line =~ s/<space>/<span class="tooltip" title="Espace">␣<\/span>/g;
				$line =~ s/<nobreakspace>/<span class="tooltip" title="Espace insécable AltGr\/Option + Espace">⍽<\/span>/g;
				$line =~ s/<rightsinglequotemark>/<span class="tooltip" title="Guillemet apostrophe Touche 4&#x27;">’<\/span>/g;
				$line =~ s/<degree>/<span class="tooltip" title="Symbole degré Maj + °)">°<\/span>/g;
				$line =~ s/<multiply>/<span class="tooltip" title="Symbole multiplication AltFr + C">×<\/span>/g;
				$line =~ s/<paragraph>/<span class="tooltip" title="Symbole paragraphe américain Maj + AltFr + P">¶<\/span>/g;
				$line =~ s/<U2039>/<span class="tooltip" title="Guillemet chevron simple Maj + ¨^">‹<\/span>/g;
				$line =~ s/<U203A>/<span class="tooltip" title="Guillemet chevron simple Maj + £\$">›<\/span>/g;
				
				# Keysyms.
				$line =~ s/<asciicircum>/^/g;
				$line =~ s/<percent>/%/g;
				$line =~ s/<braceleft>/{/g;
				$line =~ s/<braceright>/}/g;
				$line =~ s/<asciitilde>/~/g;
				$line =~ s/<at>/@/g;
				$line =~ s/<grave>/`/g;
				$line =~ s/<apostrophe>/&#x27;/g;
				$line =~ s/<quotedbl>/&quot;/g;
				$line =~ s/<ampersand>/&amp;/g;
				$line =~ s/<numbersign>/#/g;
				$line =~ s/<dollar>/\$/g;
				$line =~ s/<parenleft>/(/g;
				$line =~ s/<parenright>/)/g;
				$line =~ s/<minus>/-/g;
				$line =~ s/<plus>/+/g;
				$line =~ s/<bracketleft>/[/g;
				$line =~ s/<bracketright>/]/g;
				$line =~ s/<underscore>/_/g;
				$line =~ s/<bar>/|/g;
				$line =~ s/<slash>/\//g;
				$line =~ s/<asterisk>/*/g;
				$line =~ s/<less>/&lt;/g;
				$line =~ s/<greater>/&gt;/g;
				$line =~ s/<equal>/=/g;
				$line =~ s/<backslash>/\\/g;
				$line =~ s/<question>/?/g;
				$line =~ s/<exclam>/!/g;
				$line =~ s/<colon>/:/g;
				$line =~ s/<semicolon>/;/g;
				$line =~ s/<comma>/,/g;
				$line =~ s/<period>/./g;
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
				
				# Scalars.
				$line =~ s/<U([0-9A-F]{4})>/&#x$1;/g;
				$line =~ s/U([0-9A-F]{4,5})/U+$1/g;
				
				# Remove delimiters.
				$line =~ s/<(.)>/$1/g;
				
				# Translation.
				$line =~ s/( # .*), for convenience/$1, pour plus de facilité/g;
				$line =~ s/( # .*) for use in Rromani/$1 pour son usage en rromani/g;
				$line =~ s/( # .*) red emoji/$1 émoji rouge/g;
				$line =~ s/( # .*) emoji/$1 émoji/g;
				$line =~ s/ # Mathematical Alphanumeric Symbols high surrogate/ # Surrogat haut de symbole mathématique alphanumérique/g;
				$line =~ s/ # High surrogate of regional indicator symbol letters/ # Surrogat haut de symbole lettre drapeau/g;
				$line =~ s/ # High surrogate/ # surrogat haut/g;
				$line =~ s/( # .*) affected by glyph like (U\+[0-9A-F]{4,5}) disturbance/$1 victime d’une confusion de glyphes, s’affiche comme $2/g;
				$line =~ s/( # .*) repurposed as Multi_key symbol/$1 réutilisé comme symbole de composition/g;
				$line =~ s/( # .*) Canadian French:/$1 Français du Canada :/g;
				$line =~ s/( # .*) French:/$1 Français :/g;
				$line =~ s/( # .*) Breton/$1 breton/g;
				$line =~ s/( # .*) Overrides/$1 Remplace/g;
				$line =~ s/( # .*) overrides/$1 remplace/g;
				$line =~ s/( # .*) overridden by Ê key emulation/$1 remplacé par l’émulation de touche Ê/g;
				$line =~ s/( # .*) (.) key emulation/$1 émulation de touche $2/g;
				$line =~ s/( # .*) Arabic transliteration/$1 translittération arabe/g;
				$line =~ s/( # .*) Cuneiform transliteration/$1 translittération cunéiforme/g;
				$line =~ s/( # .*) Demotic transcription/$1 transcription démotique/g;
				$line =~ s/( # .*) Parthian transcription/$1 transcription parthe/g;
				$line =~ s/( # .*) Herero old orthography/$1 héréro ancienne orthographe/g;
				$line =~ s/( # .*) Yoruba in current Nigerian alphabet/$1 yoruba avec l’alphabet nigérian actuel/g;
				$line =~ s/( # .*) German dialectology/$1 dialectologie allemande/g;
				$line =~ s/( # .*) Swedish grave accent/$1 accent grave suédois/g;
				$line =~ s/( # .*) Languages of Gabon/$1 langues du Gabon/g;
				$line =~ s/( # .*) Languages of Togo/$1 langues du Togo/g;
				$line =~ s/( # .*) Marshallese/$1 marshallais/g;
				$line =~ s/( # .*) Malagasy/$1 malgache/g;
				$line =~ s/( # .*) Lithuanian/$1 lithuanien/g;
				$line =~ s/( # .*) Croatian/$1 croate/g;
				$line =~ s/( # .*) Serbian/$1 serbe/g;
				$line =~ s/( # .*) Slovene/$1 slovène/g;
				$line =~ s/( # .*) shortcut/$1 raccourci/g;
				$line =~ s/( # .*) for African and Breton variants/$1 pour variantes africaine et bretonne/g;
				$line =~ s/( # .*) for African variant/$1 pour variante africaine/g;
				$line =~ s/( # .*) for Breton variant/$1 pour variante bretonne/g;
				$line =~ s/( # .*) for Swiss layout/$1 pour disposition suisse/g;
				$line =~ s/( # .*) for use in Rromani/$1 pour son utilisation en rromani/g;
				$line =~ s/( # .*) twice/$1 deux fois/g;
				$line =~ s/( # .*) Lithuanian/$1 lithuanien/g;
				$line =~ s/( # .*) Hausa in Boko/$1 hausa en boko/g;
				$line =~ s/( # .*) Romanized Kharoṣṭhī/$1 kharoṣṭhī romanisé/g;
				$line =~ s/( # .*) Romanized Avestan/$1 avestique romanisé/g;
				$line =~ s/( # .*) Dutch/$1 néerlandais/g;
				$line =~ s/( # .*) Romanized Pashto following/$1 pachto romanisé selon/g;
				$line =~ s/( # .*) Chimane orthography of Wayne Gill/$1 Chimane orthographe de Wayne Gill/g;
				$line =~ s/( # .*) Portuguese/$1 portugais/g;
				$line =~ s/( # .*) Fula in Senegalese orthography/$1 fula selon l’orthographe sénégalaise/g;
				$line =~ s/( # .*) Moldovan and Romanian until 1904/$1 moldavien et roumain jusqu’en 1904/g;
				$line =~ s/( # .*) Pashto romanization/$1 romanisation pachto/g;
				$line =~ s/( # .*) ALA-LC romanization/$1 romanisation ALA-LC/g;
				$line =~ s/( # .*) ALA-LC for/$1 ALA-LC pour/g;
				$line =~ s/( # .*) Georgian/$1 géorgien/g;
				$line =~ s/( # .*) Spanish/$1 espagnol/g;
				$line =~ s/( # .*) Lezgian/$1 lezghien/g;
				$line =~ s/( # .*) Esperanto/$1 espéranto/g;
				$line =~ s/( # .*) most-used in France/$1 le plus utilisé en France/g;
				$line =~ s/( # .*) (\d\d?)th-ranking/$1 classé au rang $2/g;
				$line =~ s/( # .*) \(Pe̍h-ōe-jī orthography\)/$1 (orthographe Pe̍h-ōe-jī)/g;
				$line =~ s/( # .*) voiceless alveolar trill/$1 consonne roulée alvéolaire sourde/g;
				$line =~ s/( # .*) Medical notations/$1 notations médicales/g;
				$line =~ s/( # .*) double turned comma quotation mark/$1 guillemet apostrophe double tourné/g;
				$line =~ s/( # .*) single turned comma quotation mark/$1 guillemet apostrophe simple tourné/g;
				$line =~ s/( # .*) low double comma quotation mark/$1 guillemet virgule double tourné/g;
				$line =~ s/( # .*) low single comma quotation mark/$1 guillemet virgule simple tourné/g;
				$line =~ s/( # .*) double reversed comma quotation mark/$1 guillemet apostrophe double réfléchi/g;
				$line =~ s/( # .*) single reversed comma quotation mark/$1 guillemet apostrophe simple réfléchi/g;
				$line =~ s/( # .*) double comma quotation mark/$1 guillemet apostrophe double/g;
				$line =~ s/( # .*) single comma quotation mark/$1 guillemet apostrophe simple/g;
				$line =~ s/( # .*) pause button/$1 bouton pause/g;
				$line =~ s/( # .*) not /$1 pas /g;
				$line =~ s/( # .*\w): /$1 : /g;
				$line =~ s/( # .*\w); /$1 ; /g;

				# Anchors and localized tooltips.
				unless ( $line =~ m/: +"surrogat_haut_pour_Windows"/u ) {
					$line    =~ m/^.+ : +"(.+?)"/u;
					$str     = $1;
					$tooltip = '';
					$ucodes  = '';
					$anchor  = '';
					until ( $str eq '' ) {
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
						$tooltip = $tooltip . $descrip . " U+$cp\n";
						$ucodes  = $ucodes . "U+$cp<br />";
						$anchor  = $anchor . 'U+' . $cp . '-';
						$str     =~ s/.//u;
					}
					$tooltip =~ s/\n$//;
					$ucodes  =~ s/<br \/>$//;
					$anchor  =~ s/-$//;
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
				}

				# Anchor end tags are spaced out to prevent adding another tooltip in this table.
				$line =~ s/^(.+?) : "surrogat_haut_pour_Windows" (U\+D[8-9A-B][0-9A-F]{2}) # (.+)/<tr><td title="Surrogat haut pour Windows $2"><\/td><td title="$3">$2<\/td><td>$1<\/td><td>$3<\/td><\/tr>/;
				$line =~ s/^(.+?) : "(.+?)" # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor">$2<\/a ><\/td><td title="$3">$ucodes<\/td><td>$1<\/td><td>$3<\/td><\/tr>/;
				$line =~ s/^(.+?) : "(.+?)" (U\+(?:03[0-6]|1A[BC]|1D[C-F]|20[D-F])[0-9A-F]) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor">◌$2<\/a ><\/td><td title="$4">$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				$line =~ s/^(.+?) :(?: "(.+?)")? (U\+[0-9A-F]{4,5}) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor">$2<\/a ><\/td><td title="$4">$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				print OUTPUT $line;
				print WHOLEOUTPUT $line;
			}
		}
	}
}
print OUTPUT $end_tags;
print WHOLEOUTPUT $end_tags;

close( INPUT );
close( OUTPUT );
print( "Closed file $output_path.\n" );
close( WHOLEOUTPUT );
print( "Dead key tables generated.\n\n" );

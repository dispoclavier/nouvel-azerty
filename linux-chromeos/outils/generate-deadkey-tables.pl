#!/usr/bin/perl
# 2023-07-23T0239+0200
# 2023-08-06T1934+0200
# 2023-12-27T1519+0100
# 2024-05-16T1520+0200
# 2024-10-28T1416+0100
# 2025-05-26T2331+0200
# 2025-06-18T0815+0200
# = last modified.
#
# Generates HTML tables of dead keys from dead key sequences in Compose.yml.
# Multi_key equivalents are skipped.
#
# The input requires `START_LATIN_BY_DEAD_KEYS` as a start tag.
#
# Section headings with a leading `#*#` and the following headings switch files
# of partial tables:
#
#     # # Composed letters for languages in Togo
#     ### Space and symbol groups
#     ### Letter groups
#
# Parsing `START_LETTER_SYMBOL_GROUPS` as the end tag is commented out, so that
# space and symbol group tables and letter group tables are generated too.
# Other options may be configured after `/START_LETTER_SYMBOL_GROUPS/`.
#
# The keyboard output is marked up for display with a white background and with
# a light-blue baseline for the purpose of delimiting whitespace characters and
# clarifying advance width and vertical alignment.
#
# In these tables, a second instance of each emoji is displayed in text style,
# provided that the text style variation selector is supported. This feature
# is intended to make emoji searchable (the alt attribute is not).
#
# Math symbols get an appended link to their first instance on the math symbols
# page https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/
# on the condition that the "math" string occurs right before the EOL.
#
# Localized tooltips require the Unicode NamesList.txt or equivalents in the
# target locale as configured under ## Character names localization.
# ListeNoms.txt is used for characters missing from Udescripteurs.txt.
# Characters missing from both are counted and listed with their line number
# in Compose.yml.
#
# The output is designed for use in WordPress, where `{{{anrghg-classes}}}` can
# be replaced with additional CSS classes, as well as `{{{anrghg-value}}}` with
# anything, classes too in this file, using the A.N.R.GHG Publishing Toolkit.
#
# The all-in-one table generated alongside can only be included in web pages in
# WordPress when using the “Include partial” block provided by this plugin, as
# posts with too much code in HTML blocks are not saved in WordPress.
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
print( "Opened file $input_path.\n" );

my $output_directory = 'deadkey-tables';
unless ( -d $output_directory ) {
	mkdir $output_directory;
	print( "New directory $output_directory/.\n" );
}
my $output_file_name_template = 'deadkey-table-partial';
my $output_path_trunk         = "$output_directory/$output_file_name_template";
my $output_file_index         = 0;
my $output_file_extension     = '.html';
my $output_path               = "$output_directory/ALL_$output_file_name_template$output_file_extension";
open( WHOLEOUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );
my $wholeoutput_path = $output_path;
$output_path         = $output_path_trunk . $output_file_extension;
open( OUTPUT, '>', $output_path ) or die $!;
print( "Opened file $output_path.\n" );
print( "Processing dead keys from $input_path to $output_path.\n" );

my $parse_on       = !1;
my $comprehensive  = !0;
my $date_legend    = 'Tableau mis à jour le ';

# By courtesy of https://stackoverflow.com/a/43881027
my $nowDate        = DateTime->now(time_zone => 'local');
my ($month, $day, $year) = ($nowDate->month, $nowDate->day, $nowDate->year);
my $date           = "$day/$month/$year";
my $table_id       = 'tableau-tm';
my $table_header_1 = 'Caractère(s)';
my $table_header_2 = 'Touches';
my $table_header_3 = 'Identifiant Unicode';
my $start_tags_1   = "<figure class=\"wp-block-table alignwide deadkeys {{{anrghg-classes}}} {{{anrghg-value}}}\"><table id=\"";
my $start_tags_2   = "\">$date_legend$date</a></caption><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>\n";
my $start_tags     = "$start_tags_1$table_id\"><caption><a href=\"#$table_id$start_tags_2";
my $end_tags       = "</tbody></table></figure>\n";
print WHOLEOUTPUT $start_tags;
print OUTPUT $start_tags;
my ( @anchors, $anchor, $cp, $descrip, $index, $line_nb, $math, $regex, $str, $test, $text, $tooltip, $ucodes );

while ( my $line = <INPUT> ) {
	$line_nb = $.;
	if ( $line =~ /START_LATIN_BY_DEAD_KEYS/ ) {
		$parse_on = !0;
	}
	if ( $line =~ /START_LETTER_SYMBOL_GROUPS/ ) {

		# The symbol group table and the letter group table are generated alongside
		# as an alternative documentation that is searchable, as opposed to the two
		# image-based tables with tooltips.
		# To skip these HTML tables, uncomment this line:
		# $parse_on = !1;

		# If the symbol group and letter group tables are generated, symbol groups
		# and letter groups are included in the comprehensive table WHOLEOUTPUT.
		# To exclude these from WHOLEOUTPUT, uncomment this line:
		# $comprehensive = !1;

	}
	if ( $parse_on ) {
		if ( $line =~ /^#\*# /
			|| $line =~ /^# # Composed letters for languages in Togo/
			|| $line =~ /^### Space and symbol groups/
			|| $line =~ /^### Letter groups/
		) {
			print OUTPUT $end_tags;
			close( OUTPUT );
			print( "Closed file $output_path.\n" );
			$line =~ s/^....//;
			$line =~ s/,//g;
			$line =~ s/ /-/g;
			$line =~ m/(.+)/;
			$output_path = $output_path_trunk . '_' . $output_file_index . '_' . $1 . $output_file_extension;
			$table_id    = "tableau-tm-$output_file_index";
			$start_tags  = "$start_tags_1$table_id\"><caption><a href=\"#$table_id$start_tags_2";
			++$output_file_index;
			open( OUTPUT, '>', $output_path ) or die $!;
			print( "Opened file $output_path.\n" );
			print( "Processing dead keys from $input_path to $output_path.\n" );
			print OUTPUT $start_tags;
			print OUTPUT "<!-- $1 -->\n";
		}
		unless ( $line =~ /^<Multi_key>/         # Multikey equivalents are skipped.
			|| $line =~ /^#/                 # Annotations are not (yet) processed.
			|| $line =~ /<KP_/               # Keypad equivalents, a Linux feature.
			|| $line =~ /# [Aa]vailable\.?$/ # Empty slots in letter groups.
		) {
			if ( $line =~ /<Multi_key>/ # The only instance of non-initial "Multi_key" is "Multi_key" double press.
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
				|| $line =~ /<UEFDA>/
			) {

				# Convert dead keys.
				$line =~ s/<Multi_key>/<kbd class="deadkey" title="Touche de composition AltGr\/Option + += ou AltGr\/Option + £\$ en mode ASCII">¦<\/kbd>/g;
				$line =~ s/<dead_abovedot>/<kbd class="deadkey long" title="Touche morte point en chef Maj + AltGr\/Option + P">point en chef<\/kbd>/g;
				$line =~ s/<dead_abovering>/<kbd class="deadkey long" title="Touche morte rond en chef Maj + AltGr\/Option + X">rond en chef<\/kbd>/g;
				$line =~ s/<dead_acute>/<kbd class="deadkey" title="Touche morte accent aigu Touche £\$ ou Maj + AltGr\/Option + U">aigu<\/kbd>/g;
				$line =~ s/<dead_belowcomma>/<kbd class="deadkey long" title="Touche morte virgule souscrite Maj + AltGr\/Option + §!">virgule souscrite<\/kbd>/g;
				$line =~ s/<dead_belowdot>/<kbd class="deadkey long" title="Touche morte point souscrit Maj + AltGr\/Option + .;">point souscrit<\/kbd>/g;
				$line =~ s/<dead_breve>/<kbd class="deadkey" title="Touche morte brève Maj + AltGr\/Option + F">brève<\/kbd>/g;
				$line =~ s/<dead_caron>/<kbd class="deadkey" title="Touche morte hatchek Maj + AltGr\/Option + V">hatchek<\/kbd>/g;
				$line =~ s/<dead_cedilla>/<kbd class="deadkey" title="Touche morte cédille Maj + AltGr\/Option + ?,">cédille<\/kbd>/g;
				$line =~ s/<dead_circumflex>/<kbd class="deadkey" title="Touche morte accent circonflexe Touche ¨^ ou Maj + AltGr\/Option + C">circonflexe<\/kbd>/g;
				$line =~ s/<dead_currency>/<kbd class="deadkey long" title="Touche morte monétaire Maj + AltGr\/Option + S">monétaire<\/kbd>/g;
				$line =~ s/<dead_diaeresis>/<kbd class="deadkey" title="Touche morte tréma Touche 5( ou Maj + AltGr\/Option + \/:">tréma<\/kbd>/g;
				$line =~ s/<dead_doubleacute>/<kbd class="deadkey" title="Touche morte double accent aigu Maj + AltGr\/Option + E">double aigu<\/kbd>/g;
				$line =~ s/<dead_grave>/<kbd class="deadkey" title="Touche morte accent grave AltGr\/Option + £\$ ou Maj + AltGr\/Option + N">grave<\/kbd>/g;
				$line =~ s/<dead_greek>/<kbd class="deadkey" title="Touche morte grec ou cerclé AltGr\/Option + Y ou Maj + AltGr\/Option + Y">grec<\/kbd>/g;
				$line =~ s/<dead_hook>/<kbd class="deadkey" title="Touche morte crosse ou crochet Maj + AltGr\/Option + I">crosse<\/kbd>/g;
				$line =~ s/<dead_horn>/<kbd class="deadkey" title="Touche morte cornu Maj + AltGr\/Option + H">cornu<\/kbd>/g;
				$line =~ s/<dead_invertedbreve>/<kbd class="deadkey long" title="Touche morte brève inversée Maj + AltGr\/Option + D">brève inversée<\/kbd>/g;
				$line =~ s/<dead_macron>/<kbd class="deadkey" title="Touche morte macron Maj + AltGr\/Option + M">macron<\/kbd>/g;
				$line =~ s/<dead_ogonek>/<kbd class="deadkey" title="Touche morte ogonek Maj + AltGr\/Option + K">ogonek<\/kbd>/g;
				$line =~ s/<dead_stroke>/<kbd class="deadkey" title="Touche morte barré Maj + AltGr\/Option + W">barré<\/kbd>/g;
				$line =~ s/<dead_tilde>/<kbd class="deadkey" title="Touche morte tilde AltGr\/Option + ¨^ ou Maj + AltGr\/Option + T">tilde<\/kbd>/g;
				$line =~ s/<UEFD0>/<kbd class="deadkey" title="Touche morte sélectrice de groupe Touche µ* ou Maj + AltGr\/Option + Q">groupe<\/kbd>/g;
				$line =~ s/<UEFD1>/<kbd class="deadkey" title="Touche morte exposant Maj + AltGr\/Option + A">exposant<\/kbd>/g;
				$line =~ s/<UEFD2>/<kbd class="deadkey" title="Touche morte indice Maj + AltGr\/Option + J">indice<\/kbd>/g;
				$line =~ s/<UEFD3>/<kbd class="deadkey long" title="Touche morte crochet en chef Maj + AltGr\/Option + L">crochet en chef<\/kbd>/g;
				$line =~ s/<UEFD4>/<kbd class="deadkey long" title="Touche morte crochet rétroflexe Maj + AltGr\/Option + O">crochet rétroflexe<\/kbd>/g;
				$line =~ s/<UEFD5>/<kbd class="deadkey" title="Touche morte tourné Maj + AltGr\/Option + Z">tourné<\/kbd>/g;
				$line =~ s/<UEFD6>/<kbd class="deadkey" title="Touche morte réfléchi Maj + AltGr\/Option + R">réfléchi<\/kbd>/g;
				$line =~ s/<UEFD7>/<kbd class="deadkey" title="Touche morte drapeau Maj + AltGr\/Option + B">drapeau<\/kbd>/g;
				$line =~ s/<UEFD8>/<kbd class="deadkey" title="Touche morte rayé Maj + AltGr\/Option + G">rayé<\/kbd>/g;
				$line =~ s/<UEFD9>/<kbd class="deadkey long" title="Touche morte tilde rétrocompatible Maj + AltGr\/Option + 2é">tilde rétrocompatible<\/kbd>/g;
				$line =~ s/<UEFDA>/<kbd class="deadkey long" title="Touche morte accent grave rétrocompatible Maj + AltGr\/Option + 7è">grave rétrocompatible<\/kbd>/g;

				# Remove spaces.
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;

				# Mark up invisibles or confusables.
				$line =~ s/<U202F>/<kbd class="livekey" title="Espace fine insécable AltFr + Espace">fine insécable<\/kbd>/g;
				$line =~ s/<U200B>/<kbd class="livekey" title="Césure conditionnelle Maj + AltGr\/Option + Espace">espace nulle<\/kbd>/g;
				$line =~ s/<emdash>/<kbd class="livekey" title="Tiret cadratin Maj + 4&#x27;">— tiret cadratin<\/kbd>/g;
				$line =~ s/<endash>/<kbd class="livekey" title="Tiret demi-cadratin Maj + 3&#x22;">– tiret demi-cadratin<\/kbd>/g;
				$line =~ s/<U2212>/<kbd class="livekey" title="Signe moins AltFr + T">− signe moins<\/kbd>/g;
				$line =~ s/<U02BB>/<kbd class="livekey" title="Lettre apostrophe tournée Maj + 8_ sur les variantes pour la Polynésie">ʻ lettre apostrophe tournée<\/kbd>/g;
				$line =~ s/<UEF60>/<kbd class="livekey" title="Point d’exclamation espacé AltFr + .;">[fine insécable]!<\/kbd>/g;
				$line =~ s/<UEF63>/<kbd class="livekey" title="Point d’interrogation espacé AltFr + ?,">[fine insécable]?<\/kbd>/g;

				# Add tooltips.
				$line =~ s/<space>/<span class="tooltip" title="Espace">␣<\/span>/g;
				$line =~ s/<nobreakspace>/<span class="tooltip" title="Espace insécable AltGr\/Option + Espace">⍽<\/span>/g;
				$line =~ s/<rightsinglequotemark>/<span class="tooltip" title="Guillemet apostrophe Touche 4&#x27;">’<\/span>/g;
				$line =~ s/<apostrophe>/<span class="tooltip" title="Apostrophe ASCII ou guillemet simple générique Touche 5( en mode français, ou touche %ù en mode ASCII, ou AltGr\/Option + U">&#x27;<\/span>/g;
				$line =~ s/<degree>/<span class="tooltip" title="Symbole degré Maj + °)">°<\/span>/g;
				$line =~ s/<multiply>/<span class="tooltip" title="Symbole multiplication AltFr + C">×<\/span>/g;
				$line =~ s/<paragraph>/<span class="tooltip" title="Symbole paragraphe américain Maj + AltFr + P">¶<\/span>/g;
				$line =~ s/<U2039>/<span class="tooltip" title="Guillemet chevron simple Maj + ¨^">‹<\/span>/g;
				$line =~ s/<U203A>/<span class="tooltip" title="Guillemet chevron simple Maj + £\$">›<\/span>/g;

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

				# Translate English comments to French.
				$line =~ s/ # Wide-headed arrow high surrogate/ # Surrogat haut de flèche à pointe large/g;
				$line =~ s/( # .*) "(.)" key emulation/$1 émulation de touche &quot;$2&quot;/g;
				$line =~ s/( # .*) (\d\d?)th-ranking/$1 classé au rang $2/g;
				$line =~ s/( # .*) \(lenient\)/$1 pour une expérience utilisateur plus lisse/g;
				$line =~ s/( # .*) \(Pe̍h-ōe-jī orthography\)/$1 (orthographe Pe̍h-ōe-jī)/g;
				$line =~ s/( # .*) affected by glyph like (U\+[0-9A-F]{4,5}) disturbance/$1 victime d’une confusion de glyphes, s’affiche comme $2/g;
				$line =~ s/( # .*) ALA-LC for/$1 ALA-LC pour/g;
				$line =~ s/( # .*) ALA-LC romanization/$1 romanisation ALA-LC/g;
				$line =~ s/( # .*) Arabic transliteration/$1 translittération arabe/g;
				$line =~ s/( # .*) Canadian French:/$1 Français du Canada :/g;
				$line =~ s/( # .*) check mark button/$1 bouton de coche/g;
				$line =~ s/( # .*) Chimane orthography of Wayne Gill/$1 Chimane orthographe de Wayne Gill/g;
				$line =~ s/( # .*) Croatian/$1 croate/g;
				$line =~ s/( # .*) cross mark button/$1 bouton de croix/g;
				$line =~ s/( # .*) Cuneiform transliteration/$1 translittération cunéiforme/g;
				$line =~ s/( # .*) cursive joiner/$1 liant cursif/g;
				$line =~ s/( # .*) cursive non-joiner/$1 antiliant cursif/g;
				$line =~ s/( # .*) Demotic transcription/$1 transcription démotique/g;
				$line =~ s/( # .*) double comma quotation mark/$1 guillemet apostrophe double/g;
				$line =~ s/( # .*) double reversed comma quotation mark/$1 guillemet apostrophe double réfléchi/g;
				$line =~ s/( # .*) double turned comma quotation mark/$1 guillemet apostrophe double tourné/g;
				$line =~ s/( # .*) drive slow sign/$1 panneau aller doucement/g;
				$line =~ s/( # .*) Dutch/$1 néerlandais/g;
				$line =~ s/( # .*) emoji style/$1 style émoji/g;
				$line =~ s/( # .*) emoji with skin tone support/$1 émoji avec prise en charge de la couleur de peau/g;
				$line =~ s/( # .*) engaged, betrothed, wedding ring/$1 fiancé, fiancée, alliance/g;
				$line =~ s/( # .*) ergonomic mapping/$1 disposition ergonomique/g;
				$line =~ s/( # .*) Esperanto/$1 espéranto/g;
				$line =~ s/( # .*) fast down button/$1 bouton de diminution rapide/g;
				$line =~ s/( # .*) fast reverse button/$1 bouton de retour rapide/g;
				$line =~ s/( # .*) fast up button/$1 bouton d’augmentation rapide/g;
				$line =~ s/( # .*) fast-forward button/$1 bouton d’avance rapide/g;
				$line =~ s/( # .*) for African and Breton variants/$1 pour variantes africaine et bretonne/g;
				$line =~ s/( # .*) for African variant/$1 pour variante africaine/g;
				$line =~ s/( # .*) for Breton variant/$1 pour variante bretonne/g;
				$line =~ s/( # .*) for Swiss layout/$1 pour disposition suisse/g;
				$line =~ s/( # .*) for use in Rromani/$1 pour son usage en rromani/g;
				$line =~ s/( # .*) fountain pen/$1 stylo plume/g;
				$line =~ s/( # .*) French:/$1 Français :/g;
				$line =~ s/( # .*) Fula in Senegalese orthography/$1 fula selon l’orthographe sénégalaise/g;
				$line =~ s/( # .*) generic base character for combining diacritics/$1 caractère de base générique pour diacritiques combinants/g;
				$line =~ s/( # .*) Georgian/$1 géorgien/g;
				$line =~ s/( # .*) German dialectology/$1 dialectologie allemande/g;
				$line =~ s/( # .*) Hausa in Boko/$1 hausa en boko/g;
				$line =~ s/( # .*) heart suit/$1 couleur de cœur/g;
				$line =~ s/( # .*) Herero old orthography/$1 héréro ancienne orthographe/g;
				$line =~ s/( # .*) highlighter mark/$1 mise en évidence/g;
				$line =~ s/( # .*) hollow red circle/$1 anneau rouge/g;
				$line =~ s/( # .*) hourglass done/$1 sablier terminé/g;
				$line =~ s/( # .*) hourglass not done/$1 sablier non terminé/g;
				$line =~ s/( # .*) in legacy usage/$1 précédemment/g;
				$line =~ s/( # .*) infinity/$1 infinité/g;
				$line =~ s/( # .*) Japanese kome/$1 kome japonais/g;
				$line =~ s/( # .*) Languages of Gabon/$1 langues du Gabon/g;
				$line =~ s/( # .*) Languages of Togo/$1 langues du Togo/g;
				$line =~ s/( # .*) last track button/$1 bouton de la dernière piste/g;
				$line =~ s/( # .*) Lezgian/$1 lezghien/g;
				$line =~ s/( # .*) lightning/$1 éclair/g;
				$line =~ s/( # .*) Lithuanian/$1 lithuanien/g;
				$line =~ s/( # .*) low double comma quotation mark/$1 guillemet virgule double/g;
				$line =~ s/( # .*) low single comma quotation mark/$1 guillemet virgule simple/g;
				$line =~ s/( # .*) Malagasy/$1 malgache/g;
				$line =~ s/( # .*) mapped like on Greek keyboards/$1 disposé comme sur les claviers grecs/g;
				$line =~ s/( # .*) Marshallese/$1 marshallais/g;
				$line =~ s/( # .*) Medical notations/$1 notations médicales/g;
				$line =~ s/( # .*) medical symbol/$1 symbole médical/g;
				$line =~ s/( # .*) mnemonic mapping/$1 disposition mnémonique/g;
				$line =~ s/( # .*) Moldovan and Romanian until 1904/$1 moldavien et roumain jusqu’en 1904/g;
				$line =~ s/( # .*) most-used in France/$1 le plus utilisé en France/g;
				$line =~ s/( # .*) next track button/$1 bouton de la piste suivante/g;
				$line =~ s/( # .*) no-break space/$1 espace insécable/g;
				$line =~ s/( # .*) outline scissors/$1 ciseaux ajourés/g;
				$line =~ s/( # .*) overrides/$1 remplace/g;
				$line =~ s/( # .*) Overrides/$1 Remplace/g;
				$line =~ s/( # .*) page break in plain text/$1 saut de page en texte brut/g;
				$line =~ s/( # .*) part of alphabetic mathematical symbol input sequences/$1 utilisé pour l’accès à 10 alphabets mathématiques latins préformatés supplémentaires et aux 5 alphabets ou symboles mathématiques grecs/g;
				$line =~ s/( # .*) Parthian transcription/$1 transcription parthe/g;
				$line =~ s/( # .*) Pashto romanization/$1 romanisation pachto/g;
				$line =~ s/( # .*) pause button/$1 bouton pause/g;
				$line =~ s/( # .*) plain scissors/$1 ciseaux pleins/g;
				$line =~ s/( # .*) play button/$1 bouton lecture/g;
				$line =~ s/( # .*) play or pause button/$1 bouton lecture ou pause/g;
				$line =~ s/( # .*) Portuguese/$1 portugais/g;
				$line =~ s/( # .*) preferred glyph for Latin theta/$1 glyphe préféré pour le thêta latin/g;
				$line =~ s/( # .*) preferred in Rromani/$1 préféré en rromani/g;
				$line =~ s/( # .*) record button/$1 bouton d’enregistrement/g;
				$line =~ s/( # .*) red emoji/$1 émoji rouge/g;
				$line =~ s/( # .*) red heart/$1 cœur rouge/g;
				$line =~ s/( # .*) repurposed as multikey symbol/$1 utilisé comme symbole de composition/g;
				$line =~ s/( # .*) rescue worker’s helmet/$1 casque de secouriste/g;
				$line =~ s/( # .*) reverse button/$1 bouton marche arrière/g;
				$line =~ s/( # .*) Romanized Avestan/$1 avestique romanisé/g;
				$line =~ s/( # .*) Romanized Kharoṣṭhī/$1 kharoṣṭhī romanisé/g;
				$line =~ s/( # .*) Romanized Pashto following/$1 pachto romanisé selon/g;
				$line =~ s/( # .*) Serbian/$1 serbe/g;
				$line =~ s/( # .*) shortcut/$1 raccourci/g;
				$line =~ s/( # .*) single comma quotation mark/$1 guillemet apostrophe simple/g;
				$line =~ s/( # .*) single reversed comma quotation mark/$1 guillemet apostrophe simple réfléchi/g;
				$line =~ s/( # .*) single turned comma quotation mark/$1 guillemet apostrophe simple tourné/g;
				$line =~ s/( # .*) Slovene/$1 slovène/g;
				$line =~ s/( # .*) snowman with snow/$1 bonhomme de neige sous la neige/g;
				$line =~ s/( # .*) space character/$1 espace/g;
				$line =~ s/( # .*) Spanish/$1 espagnol/g;
				$line =~ s/( # .*) stop button/$1 bouton d’arrêt/g;
				$line =~ s/( # .*) Swedish grave accent/$1 accent grave suédois/g;
				$line =~ s/( # .*) text style/$1 style texte/g;
				$line =~ s/( # .*) twice/$1 deux fois/g;
				$line =~ s/( # .*) voiceless alveolar trill/$1 consonne roulée alvéolaire sourde/g;
				$line =~ s/( # .*) Yoruba in current Nigerian alphabet/$1 yoruba avec l’alphabet nigérian actuel/g;
				$line =~ s/( # .*) emoji/$1 émoji/g;
				$line =~ s/( # .*\w); /$1 ; /g;

				unless ( $line =~ m/: +"surrogat_haut_U"/u ) {

				# Text style emoji for searchability.
					if ( $line =~ m/ émoji/u ) {
						$line    =~ m/^.+ : +"(.+?)"/u;
						$text    = "$1&#xFE0E; ";
					} else {
						$text    = '';
					}

					# Localized tooltips.
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

					# Disambiguate anchors.
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

				# Link to first instance in math list if applicable.
				if ( $line =~ m/ math$/u ) {
					$line    =~ s/ math//u;
					$math = " <a href=\"https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/#U+$cp\">math</a>";
				} else {
					$math = '';
				}

				# High surrogates.
				$line =~ s/^(.+?) : "surrogat_haut_(U\+D[8-9A-B][0-9A-F]{2})" # (.+)/<tr><td title="Surrogat haut $2 (pour Windows)"><\/td><td title="$3">$2<\/td><td>$1<\/td><td>$3<\/td><\/tr>/;

				# Composed characters.
				# Anchor end tags are spaced out to prevent adding another tooltip in this table.
				$line =~ s/^(.+?) : "(.+?)" # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">$2<\/span><\/a ><\/td><td title="$3">$ucodes<\/td><td>$1<\/td><td>$3<\/td><\/tr>/;

				# Combining characters.
				$line =~ s/^(.+?) : "(.+?)" (U\+(?:03[0-6]|1A[BC]|1D[C-F]|20[D-F])[0-9A-F]) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">◌$2<\/span><\/a ><\/td><td title="$4">$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;

				# All other characters.
				$line =~ s/^(.+?) :(?: "(.+?)")? (U\+[0-9A-F]{4,5}) # (.+)/<tr id="$anchor"><td title="$tooltip"><a href="#$anchor"><span class="bg">$2<\/span><\/a ><\/td><td title="$4">$text$3<\/td><td>$1<\/td><td>$4$math<\/td><\/tr>/;
				
				print OUTPUT $line;
				if ( $comprehensive ) {
					print WHOLEOUTPUT $line;
				}
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
print( "Dead key tables generated in $output_directory/.\n" );
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

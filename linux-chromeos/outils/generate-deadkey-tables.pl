#!/usr/bin/perl
# 2023-07-23T0239+0200
# 2023-07-29T0146+0200
# Last modified: See datestamp above.
#
# Generates HTML tables of dead keys from dead key sequences in `Compose.yml`.
# Multi_key equivalents are skipped.
#
# The input requires start and end tags. Section headings are parsed to switch
# files.
#
# The output is designed for use in WordPress. An all-in-one table is generated
# alongside, although neither WordPress editor is able to register it. Tested
# with memory limit set to 1024M for the purpose, both in PHP and in WordPress.
#
#
# Using old-style file handles.
use warnings;
use strict;
use feature 'unicode_strings';

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

my $parse_on       = !1;
my $table_header_1 = 'Caractère';
my $table_header_2 = 'Touches';
my $table_header_3 = 'Identifiant Unicode';
my $start_tags     = "<figure class=\"wp-block-table alignwide deadkeys\"><table><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>\n";
my $end_tags       = "</tbody></table></figure>\n";
print WHOLEOUTPUT $start_tags;
print OUTPUT $start_tags;

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
			|| $line =~ /^# # Ê-key emulation/
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
		unless ( $line =~ /^<Multi_key>/ || $line =~ /^#/ ) {
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
				$line =~ s/<dead_doubleacute>/<kbd class="deadkey" title="Touche morte double accent aigu Maj + AltGr\/Option + O">double aigu<\/kbd>/g;
				$line =~ s/<dead_grave>/<kbd class="deadkey" title="Touche morte accent grave Touche += ou Maj + AltGr\/Option + U">grave<\/kbd>/g;
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
				$line =~ s/<UEFD7>/<kbd class="deadkey" title="Touche morte égal, lettre drapeau Maj + AltGr\/Option + B">égal<\/kbd>/g;
				$line =~ s/<UEFD8>/<kbd class="deadkey long" title="Touche morte tilde rétrocompatible Maj + AltGr\/Option + 2é">tilde rétrocompatible<\/kbd>/g;
				$line =~ s/<UEFD9>/<kbd class="deadkey long" title="Touche morte accent grave rétrocompatible Maj + AltGr\/Option + 7è">grave rétrocompatible<\/kbd>/g;
				$line =~ s/ {2,}/ /g;
				$line =~ s/> </></g;
				# Invisibles or confusables:
				$line =~ s/<emdash>/<kbd class="livekey" title="Tiret cadratin Maj + 4&#x27;">— Tiret cadratin<\/kbd>/g;
				$line =~ s/<endash>/<kbd class="livekey" title="Tiret demi-cadratin Maj + 3&#x22;">– Tiret demi-cadratin<\/kbd>/g;
				$line =~ s/<U202F>/<kbd class="livekey" title="Espace fine insécable AltFr + Espace">fine insécable<\/kbd>/g;
				$line =~ s/<U200B>/<kbd class="livekey" title="Césure conditionnelle Maj + AltGr\/Option + Espace">espace nulle<\/kbd>/g;
				# Clarifying tooltips only:
				$line =~ s/<space>/<span class="tooltip" title="Espace">␣<\/span>/g;
				$line =~ s/<nobreakspace>/<span class="tooltip" title="Espace insécable AltGr\/Option + Espace">⍽<\/span>/g;
				$line =~ s/<rightsinglequotemark>/<span class="tooltip" title="Guillemet apostrophe Touche 4&#x27;">’<\/span>/g;
				$line =~ s/<degree>/<span class="tooltip" title="Symbole degré Maj + °)">°<\/span>/g;
				$line =~ s/<multiply>/<span class="tooltip" title="Symbole multiplication AltFr + C">×<\/span>/g;
				$line =~ s/<paragraph>/<span class="tooltip" title="Symbole paragraphe américain Maj + AltFr + P">¶<\/span>/g;
				$line =~ s/<U2039>/<span class="tooltip" title="Guillemet chevron simple Maj + ¨^">‹<\/span>/g;
				$line =~ s/<U203A>/<span class="tooltip" title="Guillemet chevron simple Maj + £\$">›<\/span>/g;
				# Self-evident:
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
				$line =~ s/<section>/§/g;
				$line =~ s/<comma>/,/g;
				$line =~ s/<period>/./g;
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
				$line =~ s/<U([0-9A-F]{4})>/&#x$1;/g;
				$line =~ s/U([0-9A-F]{4,5})/U+$1/g;
				$line =~ s/<(.)>/$1/g;
				$line =~ s/^(.+?) : "(.+?)" # (.+)/<tr><td>$2<\/td><td><\/td><td>$1<\/td><td>$3<\/td><\/tr>/;
				$line =~ s/^(.+?) : "(.+?)" (U\+03[0-6][0-9A-F]) # (.+)/<tr><td>◌$2<\/td><td>$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
				$line =~ s/^(.+?) : "(.+?)" (U\+[0-9A-F]{4,5}) # (.+)/<tr><td>$2<\/td><td>$3<\/td><td>$1<\/td><td>$4<\/td><\/tr>/;
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
close( WHOLEOUTPUT );
print( "Dead key tables generated.\n\n" );
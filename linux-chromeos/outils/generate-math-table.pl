#!/usr/bin/perl
# 2023-07-19T1747+0200
# 2023-07-20T0131+0200
# 2023-07-22T0751+0200
# Last modified: See datestamp above.
# 
# Generates an HTML table of math symbols, based
# on dead key sequences in `Compose.yml`.
#
# The input requires start and end tags.
#
# Alias sequences with no-break space or with
# right single quotation mark are skipped.
#
# The output is designed for use in WordPress.
#
# Using old-style file handles.
use warnings;
use strict;
use feature 'unicode_strings';

my $file_path = 'Compose.yml';
open( INPUT, '<', $file_path ) or die $!;
print( "File $file_path opened successfully!\n" );

my $output_path = 'math-table-partial.html';
open( OUTPUT, '>', $output_path ) or die $!;
print( "File $output_path opened successfully!\n" );

print( "Processing math symbols from $file_path to $output_path.\n" );
my $math_flag = !1;
my $table_header_1 = 'Symbole';
my $table_header_2 = 'Séquence de composition';
my $table_header_3 = 'Identifiant Unicode';
my $line = "<figure class=\"wp-block-table alignwide math\"><table><thead><tr><th colspan=\"2\" class=\"has-text-align-left\" data-align=\"left\">$table_header_1</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_2</th><th class=\"has-text-align-left\" data-align=\"left\">$table_header_3</th></tr></thead><tbody>";
print OUTPUT "$line";
print OUTPUT "\n";
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
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$10<\/td><td>U+$11<\/td><td>$1$2$3$4$5$6$7$8$9<\/td><td>$12<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$9<\/td><td>U+$10<\/td><td>$1$2$3$4$5$6$7$8 <\/td><td>$11<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$8<\/td><td>U+$9<\/td><td>$1$2$3$4$5$6$7  <\/td><td>$10<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$7<\/td><td>U+$8<\/td><td>$1$2$3$4$5$6   <\/td><td>$9<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$6<\/td><td>U+$7<\/td><td>$1$2$3$4$5    <\/td><td>$8<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$5<\/td><td>U+$6<\/td><td>$1$2$3$4     <\/td><td>$7<\/td><\/tr>/;
				$line =~ s/^<(.+?)><(.+?)><(.+?)> : "(.+?)" U(....) # (.+)/<tr><td>$4<\/td><td>U+$5<\/td><td>$1$2$3      <\/td><td>$6<\/td><\/tr>/;
				print OUTPUT "$line";
			}
		}
	}
}
$line = '</tbody></table></figure>';
print OUTPUT "$line";

close( INPUT );
close( OUTPUT );
print( "Math table generated successfully!\n\n" );

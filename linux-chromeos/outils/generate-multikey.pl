#!/usr/bin/perl
# 2022-12-28T0901+0100
# 2022-12-30T0635+0100
# 2023-01-24T2215+0100
# 2023-03-19T1533+0100
# 2023-04-26T1950+0200
# 2023-05-12T1154+0200
# 
# Adds the Multi_key equivalent below all dead key
# lines prefixed with an '@' sign for the purpose.
# Supports also section sign in lieu of semicolon.
#
# Removes already existing Multi_key lines if they
# are prefixed with an '@' sign, in order to avoid
# adding duplicate Multi_key lines.
#
#  All dead keys are supposed to be aligned to the
#  left, without any space in between, as designed
#  with a streamlined, quick input in mind.
#
# Yet trailing dead_breve is supported as used for
# circled, and *dead_group UEFD0 may align to
# the right.
#
# Multi_key lines prefixed with '!' are removed.
#
# Adds the literal to lines prefixed with an '&'.
#
#
# Using old-style file handles.
use warnings;
use strict;
use feature 'unicode_strings';

my $file_path = 'Compose.yml';
open( INPUT, '<', $file_path ) or die $!;
print( "File $file_path opened successfully!\n" );

my $backup_path = 'Compose.bak';
open( BACKUP, '>', $backup_path ) or die $!;
print( "File $backup_path opened successfully!\n" );

print( "Copying content from $file_path to $backup_path.\n" );
while ( my $line = <INPUT> ) {
	print BACKUP $line;
}
print( "File content copied successfully!\n" );

close( INPUT );
close( BACKUP );

open( BACKUP, '<', $backup_path ) or die $!;
print( "File $backup_path opened successfully!\n" );

open( OUTPUT, '>', $file_path ) or die $!;
print( "File $file_path opened successfully!\n" );

print( "Processing content from $backup_path to $file_path.\n" );
while ( my $line = <BACKUP> ) {
	if ( $line =~ /^&/ ) {
		$line =~ s/^&//;
		if ( $line =~ /^(.+)(U([0-9A-F]{4}).+)$/ ) {
			$line = $1 . '"' . chr( hex( $3 ) ) . '" ' . $2 . "\n";
		}
		print OUTPUT $line;
	} elsif ( $line =~ /^@/ ) {
		$line =~ s/^@//;
		unless ( $line =~ /^<Multi_key>/ ) {
			print OUTPUT $line;
			if ( $line =~ /<UEFD0>/
				|| $line =~ /<UEFD1>/
				|| $line =~ /<UEFD2>/
				|| $line =~ /<UEFD3>/
				|| $line =~ /<UEFD4>/
				|| $line =~ /<UEFD5>/
				|| $line =~ /<UEFD6>/
				|| $line =~ /<UEFD7>/
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
			) {
				do {
					$line =~ s/^([^ ]*?)<UEFD0>([^ ]*)     /$1<numbersign>$2/;
					$line =~ s/^([^ ]*?)<UEFD1>([^ ]*)      /$1<asciicircum>$2/;
					$line =~ s/^([^ ]*?)<UEFD2>([^ ]*)     /$1<underscore>$2/;
					$line =~ s/^([^ ]*?)<UEFD3>([^ ]*)       /$1<bracketright>$2/;
					$line =~ s/^([^ ]*?)<UEFD4>([^ ]*)     /$1<braceright>$2/;
					$line =~ s/^([^ ]*?)<UEFD5>([^ ]*)  /$1<percent>$2/;
					$line =~ s/^([^ ]*?)<UEFD6>([^ ]*)     /$1<backslash>$2 /;
					$line =~ s/^([^ ]*?)<UEFD7>([^ ]*)/$1<equal>$2/;
					$line =~ s/^([^ ]*?)<dead_abovedot>([^ ]*)/$1<period>$2       /;
					$line =~ s/^([^ ]*?)<dead_abovering>([^ ]*)/$1<asterisk>$2      /;
					$line =~ s/^([^ ]*?)<dead_acute>([^ ]*)/$1<apostrophe>$2/;
					$line =~ s/^([^ ]*?)<dead_belowcomma>([^ ]*)/$1<semicolon>$2      /;
					$line =~ s/^([^ ]*?)<dead_belowdot>([^ ]*)/$1<exclam>$2       /;
					$line =~ s/^([^ ]*?)<dead_breve>([^ ]*)/$1<parenright>$2/;
					$line =~ s/^([^ ]*?)<dead_caron>([^ ]*)/$1<greater>$2   /;
					$line =~ s/^([^ ]*?)<dead_cedilla>([^ ]*)/$1<comma>$2       /;
					$line =~ s/^([^ ]*?)<dead_circumflex>([^ ]*)/$1<less>$2           /;
					$line =~ s/^([^ ]*?)<dead_currency>([^ ]*)/$1<dollar>$2       /;
					$line =~ s/^([^ ]*?)<dead_diaeresis>([^ ]*)/$1<colon>$2         /;
					$line =~ s/^([^ ]*?)<dead_doubleacute>([^ ]*)/$1<quotedbl>$2        /;
					$line =~ s/^([^ ]*?)<dead_grave>([^ ]*)/$1<grave>$2     /;
					$line =~ s/^([^ ]*?)<dead_greek>([^ ]*)/$1<at>$2        /;
					$line =~ s/^([^ ]*?)<dead_hook>([^ ]*)/$1<braceleft>$2/;
					$line =~ s/^([^ ]*?)<dead_horn>([^ ]*)/$1<plus>$2     /;
					$line =~ s/^([^ ]*?)<dead_invertedbreve>([^ ]*)/$1<parenleft>$2         /;
					$line =~ s/^([^ ]*?)<dead_longsolidusoverlay>([^ ]*)/$1<slash>$2                  /;
					$line =~ s/^([^ ]*?)<dead_macron>([^ ]*)/$1<bar>$2        /;
					$line =~ s/^([^ ]*?)<dead_ogonek>([^ ]*)/$1<bracketleft>$2/;
					$line =~ s/^([^ ]*?)<dead_stroke>([^ ]*)/$1<minus>$2      /;
					$line =~ s/^([^ ]*?)<dead_tilde>([^ ]*)/$1<asciitilde>$2/;
				} while (
					$line =~    /^([^ ]*?)<UEFD0>/
					|| $line =~ /^([^ ]*?)<UEFD1>/
					|| $line =~ /^([^ ]*?)<UEFD2>/
					|| $line =~ /^([^ ]*?)<UEFD3>/
					|| $line =~ /^([^ ]*?)<UEFD4>/
					|| $line =~ /^([^ ]*?)<UEFD5>/
					|| $line =~ /^([^ ]*?)<UEFD6>/
					|| $line =~ /^([^ ]*?)<UEFD7>/
					|| $line =~ /^([^ ]*?)<dead_abovedot>/
					|| $line =~ /^([^ ]*?)<dead_abovering>/
					|| $line =~ /^([^ ]*?)<dead_acute>/
					|| $line =~ /^([^ ]*?)<dead_belowcomma>/
					|| $line =~ /^([^ ]*?)<dead_belowdot>/
					|| $line =~ /^([^ ]*?)<dead_breve>/
					|| $line =~ /^([^ ]*?)<dead_caron>/
					|| $line =~ /^([^ ]*?)<dead_cedilla>/
					|| $line =~ /^([^ ]*?)<dead_circumflex>/
					|| $line =~ /^([^ ]*?)<dead_currency>/
					|| $line =~ /^([^ ]*?)<dead_diaeresis>/
					|| $line =~ /^([^ ]*?)<dead_doubleacute>/
					|| $line =~ /^([^ ]*?)<dead_grave>/
					|| $line =~ /^([^ ]*?)<dead_greek>/
					|| $line =~ /^([^ ]*?)<dead_hook>/
					|| $line =~ /^([^ ]*?)<dead_horn>/
					|| $line =~ /^([^ ]*?)<dead_invertedbreve>/
					|| $line =~ /^([^ ]*?)<dead_longsolidusoverlay>/
					|| $line =~ /^([^ ]*?)<dead_macron>/
					|| $line =~ /^([^ ]*?)<dead_ogonek>/
					|| $line =~ /^([^ ]*?)<dead_stroke>/
					|| $line =~ /^([^ ]*?)<dead_tilde>/
				);
				$line =~ s/<dead_breve>/<parenright>/;
				
				do {
					$line =~ s/     ([^ ]*?)<UEFD0>([^ ]*)/$1<numbersign>$2/;
				} while (
					$line =~ /([^ ]*?)<UEFD0>/
				);
				
				$line =~ s/^(?!#)(?!<Multi_key>)(.+) {11}/<Multi_key>$1/;
				$line =~ s/^(?!#)(?!<Multi_key>)(.+)/<Multi_key>$1/;
				print OUTPUT $line;
				if ( $line =~ /^<Multi_key>.*<semicolon>/ ) {
					do {
						$line =~ s/^([^ ]*?)<semicolon>([^ ]*)/$1<section>$2  /;
					} while ( $line =~ /^([^ ]*?)<semicolon>/ );
					print OUTPUT $line;
				}
			}
		}
	} elsif ( $line =~ /^!/ ) {
		unless ( $line =~ /^!<Multi_key>/ ) {
			$line =~ s/^!//;
			print OUTPUT $line;
		}
	} else {
		print OUTPUT $line;
	}
}

close( BACKUP );
close( OUTPUT );
print( "File content processed successfully!\n\n" );

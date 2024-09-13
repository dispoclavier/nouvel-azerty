#!/usr/bin/perl
# 2023-01-04T1037+0100
# 2024-09-13T0456+0200
# = last modified.
#
# This script formats the file `UnicodeData.txt`. It takes no arguments and is
# expected to be run in the directory of the `UnicodeData.txt` input, where the
# output is `UUnicodeData.txt` consistently with the 'U' prefix.
#
# * Prepends the quoted literals;
# * Prefixes the leading code points with a 'U', but without the plus sign, for
#   interoperability with the format used in XKB and XCompose;
# * Replaces the first semicolon with a space-padded hash.
#
# Hence the line start is formatted the way XCompose expects the result.
# https://www.x.org/releases/X11R7.5/doc/man/man5/Compose.5.html
#
# The first remaining semicolon separates the name from the General Category
# abbreviation, that is kept in the file as well as the other fields, for easy
# reference.
# https://www.unicode.org/L2/L1999/UnicodeData.html
#
#
# using old-style file handles.
use warnings;
use strict;
use utf8;
use feature 'unicode_strings';
use open ':std', ':encoding(UTF-8)';

my $input_path  = 'UnicodeData.txt';
my $output_path = 'UUnicodeData.txt';

open( INPUT, '<', $input_path ) or die $!;
print( "File $input_path opened.\n" );

open( OUTPUT, '>', $output_path ) or die $!;
print( "File $output_path opened.\n" );

while ( my $line = <INPUT> ) {
	if ( $line =~ /^([0-9A-F]{4,6});(.+)$/ ) {
		$line = '"' . chr( hex( $1 ) ) . '" U' . $1 . ' # ' . $2 . "\n";
	}
	print OUTPUT $line;
}

close( INPUT );
close( OUTPUT );
print( "File content processed.\n" );

/*****************************************************************************\
* Module name: kbdeadtrans-multikey-equivalents.c
*
* Multikey equivalents of dead keys
*
* Copyright:
* 1985..2001 Microsoft Corporation (pro parte)
* 2014..2026 Marcel Schneider dev[arobase]dispoclavier.com (pro parte)
*
* History:
* Update                                   6.1.9.0.0 Mon 2026-01-26T0658+0100
* Update                                   6.1.8.0.0 Sun 2026-01-25T0534+0100
* Update                                   6.1.7.4.0 Tue 2026-01-20T0336+0100
* Update to 6.1.7.3                        6.1.7.3.0 Mon 2026-01-19T2317+0100
* Update to 6.1.7.2                        6.1.7.2.0 Mon 2026-01-19T0719+0100
* Update to 6.1.7.0                        6.1.7.0.0 Sat 2026-01-03T2222+0100
* Debug by appending multikey chain links  6.1.6.1.0 Fri 2026-01-02T1245+0100
* Debug, sync dead chars, discard chained  6.1.6.0.0 Fri 2026-01-02T0902+0100
* Update annotations                       6.1.5.3.0 Wed 2025-12-31T0619+0100
* Update annotations after test failed     6.1.5.2.1 Wed 2025-12-31T0334+0100
* Debug and update to 6.1.5.2              6.1.5.2.0 Tue 2025-12-30T1616+0100
* Discard as broken and oversizing         6.1.3.2.0 Fri 2025-11-14T1333+0100
* Add the content as of build 6.1.3.0      6.1.3.0.0 Fri 2025-11-14T0659+0100
* Add kbdeadtrans-multikey-equivalents.c   6.1.3.0.0 Fri 2025-11-14T0535+0100
*
* This file is included in kbdeadtrans.c.
*
*
* WARNING: Layout drivers including the full set of multikey equivalents are
*          unavailable in the Language bar, and if one of these is the default
*          keyboard layout, the keyboard is broken in some of the applications
*          (e.g. in VSCode, not in Windows File Explorer).
*
* The source code of a full set of multikey equivalents has almost the size of
* the dead key partial:
*
*     + kbdeadtrans.c                      6.1.5.2     687 kB
*     + kbdeadtrans-deadkeys.c             6.1.5.2   1 699 kB
*     + kbdeadtrans-multikey.c             6.1.5.2     861 kB
*     ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
*     DLL                                                      219 kB
*
*     + kbdeadtrans-multikey-equivalents.c 6.1.5.2   1 590 kB
*     ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
*     DLL                                                      289 kB
*
* This seems to be the only explanation for the failure of the layout drivers.
*
* Given that multikey equivalents of dead keys are a Linux feature fostered by
* mutualized dead key configuration, and required as a workaround for missing
* dead keys on keyboard layouts still featuring a Multikey, they do not need
* to be supported on Windows except a small subset including unchained dead
* keys, merely as a proof of concept. The rest can be skipped so as to limit
* the layout driver file size below a presumed threshold of 254 kB.
*
* The code below is generated. Please do not edit in place.
*
* Cross-platform compatible changes should be done in the source Compose.yml.
* Windows-specific changes may be done in copies of DEADTRANS macro calls moved
* to the top in kbdeadtrans.c before the includes, or in the transpiler.
* https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/dead-key-convert.pl
*
* Multikey IDs are designed as a mix of brevity and intuitivity based on XKB
* keysyms and proposed extensions, while the purpose of the leading exclam is
* to get these sorted at the top, and padding accounts for the longest IDs of
* chained dead keys.
*
* Unlike the dead key IDs, these multikey IDs encompass the full sequence,
* including the input.
*
* Intermediate multikey chain links are appended at the bottom, because
* prepending does not work.
*
\*****************************************************************************/

/*<!M><%apostrophe><%ampersand>                                    */ DEADTRANS( L'&'	,0x00E1	,0x0317	,0x0000), // '&' ➔ "̗" U+0317 COMBINING ACUTE ACCENT BELOW
/*<!M><%apostrophe><%aprightsingquotmark>                          */ DEADTRANS( 0x2019	,0x00E1	,0x2019	,0x0000), // '’' ➔ "’" U+2019 RIGHT SINGLE QUOTATION MARK, single comma quotation mark
/*<!M><%apostrophe><%backslash>                                    */ DEADTRANS( L'\\'	,0x00E1	,0x27E7	,0x0000), // '\' ➔ "⟧" U+27E7 MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><%apostrophe><%bracketright>                                 */ DEADTRANS( L']'	,0x00E1	,0x2750	,0x0000), // ']' ➔ "❐" U+2750 UPPER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%apostrophe><%circum>                                       */ DEADTRANS( L'^'	,0x00E1	,0x2023	,0x0000), // '^' ➔ "‣" U+2023 TRIANGULAR BULLET
/*<!M><%apostrophe><%percent>                                      */ DEADTRANS( L'%'	,0x00E1	,0x2031	,0x0000), // '%' ➔ "‱" U+2031 PER TEN THOUSAND SIGN
/*<!M><%apostrophe><%question>                                     */ DEADTRANS( L'?'	,0x00E1	,0x2021	,0x0000), // '?' ➔ "‡" U+2021 DOUBLE DAGGER
/*<!M><%apostrophe><%quotedbl>                                     */ DEADTRANS( L'"'	,0x00E1	,0x201D	,0x0000), // '"' ➔ "”" U+201D RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!M><%apostrophe><%quotEuroSign>                                 */ DEADTRANS( 0x20AC	,0x00E1	,0x201D	,0x0000), // '€' ➔ "”" U+201D RIGHT DOUBLE QUOTATION MARK, double comma quotation mark
/*<!M><%apostrophe><%underscore>                                   */ DEADTRANS( L'_'	,0x00E1	,0x02CF	,0x0000), // '_' ➔ "ˏ" U+02CF MODIFIER LETTER LOW ACUTE ACCENT
/*<!M><%apostrophe><1>                                             */ DEADTRANS( L'1'	,0x00E1	,0x2032	,0x0000), // '1' ➔ "′" U+2032 PRIME
/*<!M><%apostrophe><2>                                             */ DEADTRANS( L'2'	,0x00E1	,0x2033	,0x0000), // '2' ➔ "″" U+2033 DOUBLE PRIME
/*<!M><%apostrophe><3>                                             */ DEADTRANS( L'3'	,0x00E1	,0x2034	,0x0000), // '3' ➔ "‴" U+2034 TRIPLE PRIME
/*<!M><%apostrophe><4>                                             */ DEADTRANS( L'4'	,0x00E1	,0x2057	,0x0000), // '4' ➔ "⁗" U+2057 QUADRUPLE PRIME
/*<!M><%apostrophe><7>                                             */ DEADTRANS( L'7'	,0x00E1	,0x0294	,0x0000), // '7' ➔ "ʔ" U+0294 LATIN LETTER GLOTTAL STOP
/*<!M><%apostrophe><A>                                             */ DEADTRANS( L'A'	,0x00E1	,0x00C1	,0x0000), // 'A' ➔ "Á" U+00C1 LATIN CAPITAL LETTER A WITH ACUTE
/*<!M><%apostrophe><a>                                             */ DEADTRANS( L'a'	,0x00E1	,0x00E1	,0x0000), // 'a' ➔ "á" U+00E1 LATIN SMALL LETTER A WITH ACUTE
/*<!M><%apostrophe><Agrave>                                        */ DEADTRANS( 0x00C0	,0x00E1	,0x00D5	,0x0000), // 'À' ➔ "Õ" U+00D5 LATIN CAPITAL LETTER O WITH TILDE
/*<!M><%apostrophe><agrave>                                        */ DEADTRANS( 0x00E0	,0x00E1	,0x00F5	,0x0000), // 'à' ➔ "õ" U+00F5 LATIN SMALL LETTER O WITH TILDE
/*<!M><%apostrophe><C>                                             */ DEADTRANS( L'C'	,0x00E1	,0x0106	,0x0000), // 'C' ➔ "Ć" U+0106 LATIN CAPITAL LETTER C WITH ACUTE
/*<!M><%apostrophe><c>                                             */ DEADTRANS( L'c'	,0x00E1	,0x0107	,0x0000), // 'c' ➔ "ć" U+0107 LATIN SMALL LETTER C WITH ACUTE
/*<!M><%apostrophe><Ccedilla>                                      */ DEADTRANS( 0x00C7	,0x00E1	,0x1E08	,0x0000), // 'Ç' ➔ "Ḉ" U+1E08 LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*<!M><%apostrophe><ccedilla>                                      */ DEADTRANS( 0x00E7	,0x00E1	,0x1E09	,0x0000), // 'ç' ➔ "ḉ" U+1E09 LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*<!M><%apostrophe><E>                                             */ DEADTRANS( L'E'	,0x00E1	,0x00C9	,0x0000), // 'E' ➔ "É" U+00C9 LATIN CAPITAL LETTER E WITH ACUTE
/*<!M><%apostrophe><e>                                             */ DEADTRANS( L'e'	,0x00E1	,0x00E9	,0x0000), // 'e' ➔ "é" U+00E9 LATIN SMALL LETTER E WITH ACUTE
/*<!M><%apostrophe><Eacute>                                        */ DEADTRANS( 0x00C9	,0x00E1	,0x00C3	,0x0000), // 'É' ➔ "Ã" U+00C3 LATIN CAPITAL LETTER A WITH TILDE
/*<!M><%apostrophe><eacute>                                        */ DEADTRANS( 0x00E9	,0x00E1	,0x00E3	,0x0000), // 'é' ➔ "ã" U+00E3 LATIN SMALL LETTER A WITH TILDE
/*<!M><%apostrophe><Egrave>                                        */ DEADTRANS( 0x00C8	,0x00E1	,0x00D1	,0x0000), // 'È' ➔ "Ñ" U+00D1 LATIN CAPITAL LETTER N WITH TILDE
/*<!M><%apostrophe><egrave>                                        */ DEADTRANS( 0x00E8	,0x00E1	,0x00F1	,0x0000), // 'è' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE
/*<!M><%apostrophe><G>                                             */ DEADTRANS( L'G'	,0x00E1	,0x01F4	,0x0000), // 'G' ➔ "Ǵ" U+01F4 LATIN CAPITAL LETTER G WITH ACUTE
/*<!M><%apostrophe><g>                                             */ DEADTRANS( L'g'	,0x00E1	,0x01F5	,0x0000), // 'g' ➔ "ǵ" U+01F5 LATIN SMALL LETTER G WITH ACUTE
/*<!M><%apostrophe><I>                                             */ DEADTRANS( L'I'	,0x00E1	,0x00CD	,0x0000), // 'I' ➔ "Í" U+00CD LATIN CAPITAL LETTER I WITH ACUTE
/*<!M><%apostrophe><i>                                             */ DEADTRANS( L'i'	,0x00E1	,0x00ED	,0x0000), // 'i' ➔ "í" U+00ED LATIN SMALL LETTER I WITH ACUTE
/*<!M><%apostrophe><K>                                             */ DEADTRANS( L'K'	,0x00E1	,0x1E30	,0x0000), // 'K' ➔ "Ḱ" U+1E30 LATIN CAPITAL LETTER K WITH ACUTE
/*<!M><%apostrophe><k>                                             */ DEADTRANS( L'k'	,0x00E1	,0x1E31	,0x0000), // 'k' ➔ "ḱ" U+1E31 LATIN SMALL LETTER K WITH ACUTE
/*<!M><%apostrophe><L>                                             */ DEADTRANS( L'L'	,0x00E1	,0x0139	,0x0000), // 'L' ➔ "Ĺ" U+0139 LATIN CAPITAL LETTER L WITH ACUTE
/*<!M><%apostrophe><l>                                             */ DEADTRANS( L'l'	,0x00E1	,0x013A	,0x0000), // 'l' ➔ "ĺ" U+013A LATIN SMALL LETTER L WITH ACUTE
/*<!M><%apostrophe><M>                                             */ DEADTRANS( L'M'	,0x00E1	,0x1E3E	,0x0000), // 'M' ➔ "Ḿ" U+1E3E LATIN CAPITAL LETTER M WITH ACUTE
/*<!M><%apostrophe><m>                                             */ DEADTRANS( L'm'	,0x00E1	,0x1E3F	,0x0000), // 'm' ➔ "ḿ" U+1E3F LATIN SMALL LETTER M WITH ACUTE
/*<!M><%apostrophe><N>                                             */ DEADTRANS( L'N'	,0x00E1	,0x0143	,0x0000), // 'N' ➔ "Ń" U+0143 LATIN CAPITAL LETTER N WITH ACUTE
/*<!M><%apostrophe><n>                                             */ DEADTRANS( L'n'	,0x00E1	,0x0144	,0x0000), // 'n' ➔ "ń" U+0144 LATIN SMALL LETTER N WITH ACUTE
/*<!M><%apostrophe><O>                                             */ DEADTRANS( L'O'	,0x00E1	,0x00D3	,0x0000), // 'O' ➔ "Ó" U+00D3 LATIN CAPITAL LETTER O WITH ACUTE
/*<!M><%apostrophe><o>                                             */ DEADTRANS( L'o'	,0x00E1	,0x00F3	,0x0000), // 'o' ➔ "ó" U+00F3 LATIN SMALL LETTER O WITH ACUTE
/*<!M><%apostrophe><P>                                             */ DEADTRANS( L'P'	,0x00E1	,0x1E54	,0x0000), // 'P' ➔ "Ṕ" U+1E54 LATIN CAPITAL LETTER P WITH ACUTE
/*<!M><%apostrophe><p>                                             */ DEADTRANS( L'p'	,0x00E1	,0x1E55	,0x0000), // 'p' ➔ "ṕ" U+1E55 LATIN SMALL LETTER P WITH ACUTE
/*<!M><%apostrophe><periodcentered>                                */ DEADTRANS( 0x00B7	,0x00E1	,0x27E7	,0x0000), // '·' ➔ "⟧" U+27E7 MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><%apostrophe><R>                                             */ DEADTRANS( L'R'	,0x00E1	,0x0154	,0x0000), // 'R' ➔ "Ŕ" U+0154 LATIN CAPITAL LETTER R WITH ACUTE
/*<!M><%apostrophe><r>                                             */ DEADTRANS( L'r'	,0x00E1	,0x0155	,0x0000), // 'r' ➔ "ŕ" U+0155 LATIN SMALL LETTER R WITH ACUTE
/*<!M><%apostrophe><S>                                             */ DEADTRANS( L'S'	,0x00E1	,0x015A	,0x0000), // 'S' ➔ "Ś" U+015A LATIN CAPITAL LETTER S WITH ACUTE
/*<!M><%apostrophe><s>                                             */ DEADTRANS( L's'	,0x00E1	,0x015B	,0x0000), // 's' ➔ "ś" U+015B LATIN SMALL LETTER S WITH ACUTE
/*<!M><%apostrophe><U>                                             */ DEADTRANS( L'U'	,0x00E1	,0x00DA	,0x0000), // 'U' ➔ "Ú" U+00DA LATIN CAPITAL LETTER U WITH ACUTE
/*<!M><%apostrophe><u>                                             */ DEADTRANS( L'u'	,0x00E1	,0x00FA	,0x0000), // 'u' ➔ "ú" U+00FA LATIN SMALL LETTER U WITH ACUTE
/*<!M><%apostrophe><Ugrave>                                        */ DEADTRANS( 0x00D9	,0x00E1	,0x0294	,0x0000), // 'Ù' ➔ "ʔ" U+0294 LATIN LETTER GLOTTAL STOP
/*<!M><%apostrophe><ugrave>                                        */ DEADTRANS( 0x00F9	,0x00E1	,0x0294	,0x0000), // 'ù' ➔ "ʔ" U+0294 LATIN LETTER GLOTTAL STOP
/*<!M><%apostrophe><W>                                             */ DEADTRANS( L'W'	,0x00E1	,0x1E82	,0x0000), // 'W' ➔ "Ẃ" U+1E82 LATIN CAPITAL LETTER W WITH ACUTE
/*<!M><%apostrophe><w>                                             */ DEADTRANS( L'w'	,0x00E1	,0x1E83	,0x0000), // 'w' ➔ "ẃ" U+1E83 LATIN SMALL LETTER W WITH ACUTE
/*<!M><%apostrophe><Y>                                             */ DEADTRANS( L'Y'	,0x00E1	,0x00DD	,0x0000), // 'Y' ➔ "Ý" U+00DD LATIN CAPITAL LETTER Y WITH ACUTE
/*<!M><%apostrophe><y>                                             */ DEADTRANS( L'y'	,0x00E1	,0x00FD	,0x0000), // 'y' ➔ "ý" U+00FD LATIN SMALL LETTER Y WITH ACUTE
/*<!M><%apostrophe><Z>                                             */ DEADTRANS( L'Z'	,0x00E1	,0x0179	,0x0000), // 'Z' ➔ "Ź" U+0179 LATIN CAPITAL LETTER Z WITH ACUTE
/*<!M><%apostrophe><z>                                             */ DEADTRANS( L'z'	,0x00E1	,0x017A	,0x0000), // 'z' ➔ "ź" U+017A LATIN SMALL LETTER Z WITH ACUTE
/*<!M><%apostrophe><~nbspace>                                      */ DEADTRANS( 0x00A0	,0x00E1	,0x00B4	,0x0000), // ' ' ➔ "´" U+00B4 ACUTE ACCENT
/*<!M><%apostrophe><~nbthinspace>                                  */ DEADTRANS( 0x202F	,0x00E1	,0x02CA	,0x0000), // ' ' ➔ "ˊ" U+02CA MODIFIER LETTER ACUTE ACCENT
/*<!M><%apostrophe><~space>                                        */ DEADTRANS( L' '	,0x00E1	,0x0301	,0x0000), // ' ' ➔ "́" U+0301 COMBINING ACUTE ACCENT
/*<!M><%apostrophe><~spacezerowidth>                               */ DEADTRANS( 0x200B	,0x00E1	,0x0301	,0x0000), // '​' ➔ "́" U+0301 COMBINING ACUTE ACCENT
/*<!M><%asterisk><%bar>                                            */ DEADTRANS( L'|'	,0x00E5	,0x2AEF	,0x0000), // '|' ➔ "⫯" U+2AEF VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><%asterisk><%braceright>                                     */ DEADTRANS( L'}'	,0x00E5	,0x29B2	,0x0000), // '}' ➔ "⦲" U+29B2 EMPTY SET WITH SMALL CIRCLE ABOVE
/*<!M><%asterisk><%parenleft>                                      */ DEADTRANS( L'('	,0x00E5	,0x0351	,0x0000), // '(' ➔ "͑" U+0351 COMBINING LEFT HALF RING ABOVE
/*<!M><%asterisk><%parenright>                                     */ DEADTRANS( L')'	,0x00E5	,0x0357	,0x0000), // ')' ➔ "͗" U+0357 COMBINING RIGHT HALF RING ABOVE
/*<!M><%asterisk><%period>                                         */ DEADTRANS( L'.'	,0x00E5	,0x2E30	,0x0000), // '.' ➔ "⸰" U+2E30 RING POINT
/*<!M><%asterisk><%plus>                                           */ DEADTRANS( L'+'	,0x00E5	,0x2A22	,0x0000), // '+' ➔ "⨢" U+2A22 PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><%asterisk><0>                                               */ DEADTRANS( L'0'	,0x00E5	,0x00B0	,0x0000), // '0' ➔ "°" U+00B0 DEGREE SIGN
/*<!M><%asterisk><1>                                               */ DEADTRANS( L'1'	,0x00E5	,0x204E	,0x0000), // '1' ➔ "⁎" U+204E LOW ASTERISK
/*<!M><%asterisk><2>                                               */ DEADTRANS( L'2'	,0x00E5	,0x2051	,0x0000), // '2' ➔ "⁑" U+2051 TWO ASTERISKS ALIGNED VERTICALLY
/*<!M><%asterisk><3>                                               */ DEADTRANS( L'3'	,0x00E5	,0x2042	,0x0000), // '3' ➔ "⁂" U+2042 ASTERISM
/*<!M><%asterisk><4>                                               */ DEADTRANS( L'4'	,0x00E5	,0x02D3	,0x0000), // '4' ➔ "˓" U+02D3 MODIFIER LETTER CENTRED LEFT HALF RING
/*<!M><%asterisk><5>                                               */ DEADTRANS( L'5'	,0x00E5	,0x2217	,0x0000), // '5' ➔ "∗" U+2217 ASTERISK OPERATOR
/*<!M><%asterisk><6>                                               */ DEADTRANS( L'6'	,0x00E5	,0x02D2	,0x0000), // '6' ➔ "˒" U+02D2 MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!M><%asterisk><7>                                               */ DEADTRANS( L'7'	,0x00E5	,0x02BF	,0x0000), // '7' ➔ "ʿ" U+02BF MODIFIER LETTER LEFT HALF RING
/*<!M><%asterisk><8>                                               */ DEADTRANS( L'8'	,0x00E5	,0x22C6	,0x0000), // '8' ➔ "⋆" U+22C6 STAR OPERATOR
/*<!M><%asterisk><9>                                               */ DEADTRANS( L'9'	,0x00E5	,0x02BE	,0x0000), // '9' ➔ "ʾ" U+02BE MODIFIER LETTER RIGHT HALF RING
/*<!M><%asterisk><A>                                               */ DEADTRANS( L'A'	,0x00E5	,0x00C5	,0x0000), // 'A' ➔ "Å" U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE
/*<!M><%asterisk><a>                                               */ DEADTRANS( L'a'	,0x00E5	,0x00E5	,0x0000), // 'a' ➔ "å" U+00E5 LATIN SMALL LETTER A WITH RING ABOVE
/*<!M><%asterisk><C>                                               */ DEADTRANS( L'C'	,0x00E5	,0x2103	,0x0000), // 'C' ➔ "℃" U+2103 DEGREE CELSIUS
/*<!M><%asterisk><c>                                               */ DEADTRANS( L'c'	,0x00E5	,0x2103	,0x0000), // 'c' ➔ "℃" U+2103 DEGREE CELSIUS
/*<!M><%asterisk><F>                                               */ DEADTRANS( L'F'	,0x00E5	,0x2109	,0x0000), // 'F' ➔ "℉" U+2109 DEGREE FAHRENHEIT
/*<!M><%asterisk><f>                                               */ DEADTRANS( L'f'	,0x00E5	,0x2109	,0x0000), // 'f' ➔ "℉" U+2109 DEGREE FAHRENHEIT
/*<!M><%asterisk><K>                                               */ DEADTRANS( L'K'	,0x00E5	,0x212A	,0x0000), // 'K' ➔ "K" U+212A KELVIN SIGN
/*<!M><%asterisk><k>                                               */ DEADTRANS( L'k'	,0x00E5	,0x212A	,0x0000), // 'k' ➔ "K" U+212A KELVIN SIGN
/*<!M><%asterisk><l>                                               */ DEADTRANS( L'l'	,0x00E5	,0xAB39	,0x0000), // 'l' ➔ "ꬹ" U+AB39 LATIN SMALL LETTER L WITH MIDDLE RING
/*<!M><%asterisk><o>                                               */ DEADTRANS( L'o'	,0x00E5	,0x2C7A	,0x0000), // 'o' ➔ "ⱺ" U+2C7A LATIN SMALL LETTER O WITH LOW RING INSIDE
/*<!M><%asterisk><r>                                               */ DEADTRANS( L'r'	,0x00E5	,0xAB4C	,0x0000), // 'r' ➔ "ꭌ" U+AB4C LATIN SMALL LETTER SCRIPT R WITH RING
/*<!M><%asterisk><T>                                               */ DEADTRANS( L'T'	,0x00E5	,0x27DF	,0x0000), // 'T' ➔ "⟟" U+27DF UP TACK WITH CIRCLE ABOVE
/*<!M><%asterisk><t>                                               */ DEADTRANS( L't'	,0x00E5	,0x27DF	,0x0000), // 't' ➔ "⟟" U+27DF UP TACK WITH CIRCLE ABOVE
/*<!M><%asterisk><U>                                               */ DEADTRANS( L'U'	,0x00E5	,0x016E	,0x0000), // 'U' ➔ "Ů" U+016E LATIN CAPITAL LETTER U WITH RING ABOVE
/*<!M><%asterisk><u>                                               */ DEADTRANS( L'u'	,0x00E5	,0x016F	,0x0000), // 'u' ➔ "ů" U+016F LATIN SMALL LETTER U WITH RING ABOVE
/*<!M><%asterisk><w>                                               */ DEADTRANS( L'w'	,0x00E5	,0x1E98	,0x0000), // 'w' ➔ "ẘ" U+1E98 LATIN SMALL LETTER W WITH RING ABOVE
/*<!M><%asterisk><X>                                               */ DEADTRANS( L'X'	,0x00E5	,0xAB54	,0x0000), // 'X' ➔ "ꭔ" U+AB54 LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*<!M><%asterisk><x>                                               */ DEADTRANS( L'x'	,0x00E5	,0xAB56	,0x0000), // 'x' ➔ "ꭖ" U+AB56 LATIN SMALL LETTER X WITH LOW RIGHT RING
/*<!M><%asterisk><y>                                               */ DEADTRANS( L'y'	,0x00E5	,0x1E99	,0x0000), // 'y' ➔ "ẙ" U+1E99 LATIN SMALL LETTER Y WITH RING ABOVE
/*<!M><%asterisk><~nbspace>                                        */ DEADTRANS( 0x00A0	,0x00E5	,0x02DA	,0x0000), // ' ' ➔ "˚" U+02DA RING ABOVE
/*<!M><%asterisk><~nbthinspace>                                    */ DEADTRANS( 0x202F	,0x00E5	,0x02DA	,0x0000), // ' ' ➔ "˚" U+02DA RING ABOVE
/*<!M><%asterisk><~space>                                          */ DEADTRANS( L' '	,0x00E5	,0x030A	,0x0000), // ' ' ➔ "̊" U+030A COMBINING RING ABOVE
/*<!M><%asterisk><~spacezerowidth>                                 */ DEADTRANS( 0x200B	,0x00E5	,0x030A	,0x0000), // '​' ➔ "̊" U+030A COMBINING RING ABOVE
/*<!M><%at><%asterisk>                                             */ DEADTRANS( L'*'	,0x03B5	,0x229B	,0x0000), // '*' ➔ "⊛" U+229B CIRCLED ASTERISK OPERATOR
/*<!M><%at><%equal>                                                */ DEADTRANS( L'='	,0x03B5	,0x229C	,0x0000), // '=' ➔ "⊜" U+229C CIRCLED EQUALS
/*<!M><%at><%minus>                                                */ DEADTRANS( L'-'	,0x03B5	,0x2296	,0x0000), // '-' ➔ "⊖" U+2296 CIRCLED MINUS
/*<!M><%at><%period>                                               */ DEADTRANS( L'.'	,0x03B5	,0x2299	,0x0000), // '.' ➔ "⊙" U+2299 CIRCLED DOT OPERATOR
/*<!M><%at><%plus>                                                 */ DEADTRANS( L'+'	,0x03B5	,0x2295	,0x0000), // '+' ➔ "⊕" U+2295 CIRCLED PLUS
/*<!M><%at><%semicolon>                                            */ DEADTRANS( L';'	,0x03B5	,0x2297	,0x0000), // ';' ➔ "⊗" U+2297 CIRCLED TIMES
/*<!M><%at><%slash>                                                */ DEADTRANS( L'/'	,0x03B5	,0x2298	,0x0000), // '/' ➔ "⊘" U+2298 CIRCLED DIVISION SLASH
/*<!M><%at><0>                                                     */ DEADTRANS( L'0'	,0x03B5	,0x2469	,0x0000), // '0' ➔ "⑩" U+2469 CIRCLED NUMBER TEN
/*<!M><%at><1>                                                     */ DEADTRANS( L'1'	,0x03B5	,0x2460	,0x0000), // '1' ➔ "①" U+2460 CIRCLED DIGIT ONE
/*<!M><%at><2>                                                     */ DEADTRANS( L'2'	,0x03B5	,0x2461	,0x0000), // '2' ➔ "②" U+2461 CIRCLED DIGIT TWO
/*<!M><%at><3>                                                     */ DEADTRANS( L'3'	,0x03B5	,0x2462	,0x0000), // '3' ➔ "③" U+2462 CIRCLED DIGIT THREE
/*<!M><%at><4>                                                     */ DEADTRANS( L'4'	,0x03B5	,0x2463	,0x0000), // '4' ➔ "④" U+2463 CIRCLED DIGIT FOUR
/*<!M><%at><5>                                                     */ DEADTRANS( L'5'	,0x03B5	,0x2464	,0x0000), // '5' ➔ "⑤" U+2464 CIRCLED DIGIT FIVE
/*<!M><%at><6>                                                     */ DEADTRANS( L'6'	,0x03B5	,0x2465	,0x0000), // '6' ➔ "⑥" U+2465 CIRCLED DIGIT SIX
/*<!M><%at><7>                                                     */ DEADTRANS( L'7'	,0x03B5	,0x2466	,0x0000), // '7' ➔ "⑦" U+2466 CIRCLED DIGIT SEVEN
/*<!M><%at><8>                                                     */ DEADTRANS( L'8'	,0x03B5	,0x2467	,0x0000), // '8' ➔ "⑧" U+2467 CIRCLED DIGIT EIGHT
/*<!M><%at><9>                                                     */ DEADTRANS( L'9'	,0x03B5	,0x2468	,0x0000), // '9' ➔ "⑨" U+2468 CIRCLED DIGIT NINE
/*<!M><%at><A>                                                     */ DEADTRANS( L'A'	,0x03B5	,0x0391	,0x0000), // 'A' ➔ "Α" U+0391 GREEK CAPITAL LETTER ALPHA
/*<!M><%at><a>                                                     */ DEADTRANS( L'a'	,0x03B5	,0x03B1	,0x0000), // 'a' ➔ "α" U+03B1 GREEK SMALL LETTER ALPHA
/*<!M><%at><B>                                                     */ DEADTRANS( L'B'	,0x03B5	,0x0392	,0x0000), // 'B' ➔ "Β" U+0392 GREEK CAPITAL LETTER BETA
/*<!M><%at><b>                                                     */ DEADTRANS( L'b'	,0x03B5	,0x03B2	,0x0000), // 'b' ➔ "β" U+03B2 GREEK SMALL LETTER BETA
/*<!M><%at><C>                                                     */ DEADTRANS( L'C'	,0x03B5	,0x03A8	,0x0000), // 'C' ➔ "Ψ" U+03A8 GREEK CAPITAL LETTER PSI
/*<!M><%at><c>                                                     */ DEADTRANS( L'c'	,0x03B5	,0x03C8	,0x0000), // 'c' ➔ "ψ" U+03C8 GREEK SMALL LETTER PSI
/*<!M><%at><D>                                                     */ DEADTRANS( L'D'	,0x03B5	,0x0394	,0x0000), // 'D' ➔ "Δ" U+0394 GREEK CAPITAL LETTER DELTA
/*<!M><%at><d>                                                     */ DEADTRANS( L'd'	,0x03B5	,0x03B4	,0x0000), // 'd' ➔ "δ" U+03B4 GREEK SMALL LETTER DELTA
/*<!M><%at><degree>                                                */ DEADTRANS( 0x00B0	,0x03B5	,0x25CE	,0x0000), // '°' ➔ "◎" U+25CE BULLSEYE
/*<!M><%at><division>                                              */ DEADTRANS( 0x00F7	,0x03B5	,0x2A38	,0x0000), // '÷' ➔ "⨸" U+2A38 CIRCLED DIVISION SIGN
/*<!M><%at><E>                                                     */ DEADTRANS( L'E'	,0x03B5	,0x0395	,0x0000), // 'E' ➔ "Ε" U+0395 GREEK CAPITAL LETTER EPSILON
/*<!M><%at><e>                                                     */ DEADTRANS( L'e'	,0x03B5	,0x03B5	,0x0000), // 'e' ➔ "ε" U+03B5 GREEK SMALL LETTER EPSILON
/*<!M><%at><emdash>                                                */ DEADTRANS( 0x2014	,0x03B5	,0x229D	,0x0000), // '—' ➔ "⊝" U+229D CIRCLED DASH
/*<!M><%at><endash>                                                */ DEADTRANS( 0x2013	,0x03B5	,0x229D	,0x0000), // '–' ➔ "⊝" U+229D CIRCLED DASH
/*<!M><%at><F>                                                     */ DEADTRANS( L'F'	,0x03B5	,0x03A6	,0x0000), // 'F' ➔ "Φ" U+03A6 GREEK CAPITAL LETTER PHI
/*<!M><%at><f>                                                     */ DEADTRANS( L'f'	,0x03B5	,0x03C6	,0x0000), // 'f' ➔ "φ" U+03C6 GREEK SMALL LETTER PHI
/*<!M><%at><G>                                                     */ DEADTRANS( L'G'	,0x03B5	,0x0393	,0x0000), // 'G' ➔ "Γ" U+0393 GREEK CAPITAL LETTER GAMMA
/*<!M><%at><g>                                                     */ DEADTRANS( L'g'	,0x03B5	,0x03B3	,0x0000), // 'g' ➔ "γ" U+03B3 GREEK SMALL LETTER GAMMA
/*<!M><%at><H>                                                     */ DEADTRANS( L'H'	,0x03B5	,0x0397	,0x0000), // 'H' ➔ "Η" U+0397 GREEK CAPITAL LETTER ETA
/*<!M><%at><h>                                                     */ DEADTRANS( L'h'	,0x03B5	,0x03B7	,0x0000), // 'h' ➔ "η" U+03B7 GREEK SMALL LETTER ETA
/*<!M><%at><I>                                                     */ DEADTRANS( L'I'	,0x03B5	,0x0399	,0x0000), // 'I' ➔ "Ι" U+0399 GREEK CAPITAL LETTER IOTA
/*<!M><%at><i>                                                     */ DEADTRANS( L'i'	,0x03B5	,0x03B9	,0x0000), // 'i' ➔ "ι" U+03B9 GREEK SMALL LETTER IOTA
/*<!M><%at><J>                                                     */ DEADTRANS( L'J'	,0x03B5	,0x039E	,0x0000), // 'J' ➔ "Ξ" U+039E GREEK CAPITAL LETTER XI
/*<!M><%at><j>                                                     */ DEADTRANS( L'j'	,0x03B5	,0x03BE	,0x0000), // 'j' ➔ "ξ" U+03BE GREEK SMALL LETTER XI
/*<!M><%at><K>                                                     */ DEADTRANS( L'K'	,0x03B5	,0x039A	,0x0000), // 'K' ➔ "Κ" U+039A GREEK CAPITAL LETTER KAPPA
/*<!M><%at><k>                                                     */ DEADTRANS( L'k'	,0x03B5	,0x03BA	,0x0000), // 'k' ➔ "κ" U+03BA GREEK SMALL LETTER KAPPA
/*<!M><%at><L>                                                     */ DEADTRANS( L'L'	,0x03B5	,0x039B	,0x0000), // 'L' ➔ "Λ" U+039B GREEK CAPITAL LETTER LAMDA
/*<!M><%at><l>                                                     */ DEADTRANS( L'l'	,0x03B5	,0x03BB	,0x0000), // 'l' ➔ "λ" U+03BB GREEK SMALL LETTER LAMDA
/*<!M><%at><M>                                                     */ DEADTRANS( L'M'	,0x03B5	,0x039C	,0x0000), // 'M' ➔ "Μ" U+039C GREEK CAPITAL LETTER MU
/*<!M><%at><m>                                                     */ DEADTRANS( L'm'	,0x03B5	,0x03BC	,0x0000), // 'm' ➔ "μ" U+03BC GREEK SMALL LETTER MU
/*<!M><%at><multiply>                                              */ DEADTRANS( 0x00D7	,0x03B5	,0x2297	,0x0000), // '×' ➔ "⊗" U+2297 CIRCLED TIMES
/*<!M><%at><N>                                                     */ DEADTRANS( L'N'	,0x03B5	,0x039D	,0x0000), // 'N' ➔ "Ν" U+039D GREEK CAPITAL LETTER NU
/*<!M><%at><n>                                                     */ DEADTRANS( L'n'	,0x03B5	,0x03BD	,0x0000), // 'n' ➔ "ν" U+03BD GREEK SMALL LETTER NU
/*<!M><%at><O>                                                     */ DEADTRANS( L'O'	,0x03B5	,0x039F	,0x0000), // 'O' ➔ "Ο" U+039F GREEK CAPITAL LETTER OMICRON
/*<!M><%at><o>                                                     */ DEADTRANS( L'o'	,0x03B5	,0x03BF	,0x0000), // 'o' ➔ "ο" U+03BF GREEK SMALL LETTER OMICRON
/*<!M><%at><P>                                                     */ DEADTRANS( L'P'	,0x03B5	,0x03A0	,0x0000), // 'P' ➔ "Π" U+03A0 GREEK CAPITAL LETTER PI
/*<!M><%at><p>                                                     */ DEADTRANS( L'p'	,0x03B5	,0x03C0	,0x0000), // 'p' ➔ "π" U+03C0 GREEK SMALL LETTER PI
/*<!M><%at><Q>                                                     */ DEADTRANS( L'Q'	,0x03B5	,0x03F4	,0x0000), // 'Q' ➔ "ϴ" U+03F4 GREEK CAPITAL THETA SYMBOL
/*<!M><%at><q>                                                     */ DEADTRANS( L'q'	,0x03B5	,0x03D1	,0x0000), // 'q' ➔ "ϑ" U+03D1 GREEK THETA SYMBOL
/*<!M><%at><R>                                                     */ DEADTRANS( L'R'	,0x03B5	,0x03A1	,0x0000), // 'R' ➔ "Ρ" U+03A1 GREEK CAPITAL LETTER RHO
/*<!M><%at><r>                                                     */ DEADTRANS( L'r'	,0x03B5	,0x03C1	,0x0000), // 'r' ➔ "ρ" U+03C1 GREEK SMALL LETTER RHO
/*<!M><%at><S>                                                     */ DEADTRANS( L'S'	,0x03B5	,0x03A3	,0x0000), // 'S' ➔ "Σ" U+03A3 GREEK CAPITAL LETTER SIGMA
/*<!M><%at><s>                                                     */ DEADTRANS( L's'	,0x03B5	,0x03C3	,0x0000), // 's' ➔ "σ" U+03C3 GREEK SMALL LETTER SIGMA
/*<!M><%at><T>                                                     */ DEADTRANS( L'T'	,0x03B5	,0x03A4	,0x0000), // 'T' ➔ "Τ" U+03A4 GREEK CAPITAL LETTER TAU
/*<!M><%at><t>                                                     */ DEADTRANS( L't'	,0x03B5	,0x03C4	,0x0000), // 't' ➔ "τ" U+03C4 GREEK SMALL LETTER TAU
/*<!M><%at><U>                                                     */ DEADTRANS( L'U'	,0x03B5	,0x0398	,0x0000), // 'U' ➔ "Θ" U+0398 GREEK CAPITAL LETTER THETA
/*<!M><%at><u>                                                     */ DEADTRANS( L'u'	,0x03B5	,0x03B8	,0x0000), // 'u' ➔ "θ" U+03B8 GREEK SMALL LETTER THETA
/*<!M><%at><V>                                                     */ DEADTRANS( L'V'	,0x03B5	,0x03A9	,0x0000), // 'V' ➔ "Ω" U+03A9 GREEK CAPITAL LETTER OMEGA
/*<!M><%at><v>                                                     */ DEADTRANS( L'v'	,0x03B5	,0x03C9	,0x0000), // 'v' ➔ "ω" U+03C9 GREEK SMALL LETTER OMEGA
/*<!M><%at><w>                                                     */ DEADTRANS( L'w'	,0x03B5	,0x03C2	,0x0000), // 'w' ➔ "ς" U+03C2 GREEK SMALL LETTER FINAL SIGMA
/*<!M><%at><W>                                                     */ DEADTRANS( L'W'	,0x03B5	,0x2207	,0x0000), // 'W' ➔ "∇" U+2207 NABLA
/*<!M><%at><X>                                                     */ DEADTRANS( L'X'	,0x03B5	,0x03A7	,0x0000), // 'X' ➔ "Χ" U+03A7 GREEK CAPITAL LETTER CHI
/*<!M><%at><x>                                                     */ DEADTRANS( L'x'	,0x03B5	,0x03C7	,0x0000), // 'x' ➔ "χ" U+03C7 GREEK SMALL LETTER CHI
/*<!M><%at><Y>                                                     */ DEADTRANS( L'Y'	,0x03B5	,0x03A5	,0x0000), // 'Y' ➔ "Υ" U+03A5 GREEK CAPITAL LETTER UPSILON
/*<!M><%at><y>                                                     */ DEADTRANS( L'y'	,0x03B5	,0x03C5	,0x0000), // 'y' ➔ "υ" U+03C5 GREEK SMALL LETTER UPSILON
/*<!M><%at><Z>                                                     */ DEADTRANS( L'Z'	,0x03B5	,0x0396	,0x0000), // 'Z' ➔ "Ζ" U+0396 GREEK CAPITAL LETTER ZETA
/*<!M><%at><z>                                                     */ DEADTRANS( L'z'	,0x03B5	,0x03B6	,0x0000), // 'z' ➔ "ζ" U+03B6 GREEK SMALL LETTER ZETA
/*<!M><%at><~nbspace>                                              */ DEADTRANS( 0x00A0	,0x03B5	,0x1FBE	,0x0000), // ' ' ➔ "ι" U+1FBE GREEK PROSGEGRAMMENI
/*<!M><%at><~nbthinspace>                                          */ DEADTRANS( 0x202F	,0x03B5	,0x1FBE	,0x0000), // ' ' ➔ "ι" U+1FBE GREEK PROSGEGRAMMENI
/*<!M><%at><~space>                                                */ DEADTRANS( L' '	,0x03B5	,0x0345	,0x0000), // ' ' ➔ "ͅ" U+0345 COMBINING GREEK YPOGEGRAMMENI
/*<!M><%at><~spacezerowidth>                                       */ DEADTRANS( 0x200B	,0x03B5	,0x0345	,0x0000), // '​' ➔ "ͅ" U+0345 COMBINING GREEK YPOGEGRAMMENI
/*<!M><%backslash><%apostrophe>                                    */ DEADTRANS( L'\''	,0x1D19	,0x02BD	,0x0000), // ''' ➔ "ʽ" U+02BD MODIFIER LETTER REVERSED COMMA
/*<!M><%backslash><%aprightsingquotmark>                           */ DEADTRANS( 0x2019	,0x1D19	,0x02BD	,0x0000), // '’' ➔ "ʽ" U+02BD MODIFIER LETTER REVERSED COMMA
/*<!M><%backslash><%comma>                                         */ DEADTRANS( L','	,0x1D19	,0x2E41	,0x0000), // ',' ➔ "⹁" U+2E41 REVERSED COMMA
/*<!M><%backslash><%equal>                                         */ DEADTRANS( L'='	,0x1D19	,0x22CD	,0x0000), // '=' ➔ "⋍" U+22CD REVERSED TILDE EQUALS
/*<!M><%backslash><%excsection>                                    */ DEADTRANS( 0x00A7	,0x1D19	,0x204F	,0x0000), // '§' ➔ "⁏" U+204F REVERSED SEMICOLON
/*<!M><%backslash><%grave>                                         */ DEADTRANS( L'`'	,0x1D19	,0x2310	,0x0000), // '`' ➔ "⌐" U+2310 REVERSED NOT SIGN
/*<!M><%backslash><%question>                                      */ DEADTRANS( L'?'	,0x1D19	,0x2E2E	,0x0000), // '?' ➔ "⸮" U+2E2E REVERSED QUESTION MARK
/*<!M><%backslash><%semicolon>                                     */ DEADTRANS( L';'	,0x1D19	,0x204F	,0x0000), // ';' ➔ "⁏" U+204F REVERSED SEMICOLON
/*<!M><%backslash><%tilde>                                         */ DEADTRANS( L'~'	,0x1D19	,0x223D	,0x0000), // '~' ➔ "∽" U+223D REVERSED TILDE
/*<!M><%backslash><1>                                              */ DEADTRANS( L'1'	,0x1D19	,0x2216	,0x0000), // '1' ➔ "∖" U+2216 SET MINUS
/*<!M><%backslash><2>                                              */ DEADTRANS( L'2'	,0x1D19	,0x29F9	,0x0000), // '2' ➔ "⧹" U+29F9 BIG REVERSE SOLIDUS
/*<!M><%backslash><3>                                              */ DEADTRANS( L'3'	,0x1D19	,0x27CD	,0x0000), // '3' ➔ "⟍" U+27CD MATHEMATICAL FALLING DIAGONAL
/*<!M><%backslash><4>                                              */ DEADTRANS( L'4'	,0x1D19	,0x29F5	,0x0000), // '4' ➔ "⧵" U+29F5 REVERSE SOLIDUS OPERATOR
/*<!M><%backslash><A>                                              */ DEADTRANS( L'A'	,0x1D19	,0x29A5	,0x0000), // 'A' ➔ "⦥" U+29A5 REVERSED ANGLE WITH UNDERBAR
/*<!M><%backslash><a>                                              */ DEADTRANS( L'a'	,0x1D19	,0xAB31	,0x0000), // 'a' ➔ "ꬱ" U+AB31 LATIN SMALL LETTER A REVERSED-SCHWA
/*<!M><%backslash><B>                                              */ DEADTRANS( L'B'	,0x1D19	,0x204D	,0x0000), // 'B' ➔ "⁍" U+204D BLACK RIGHTWARDS BULLET
/*<!M><%backslash><b>                                              */ DEADTRANS( L'b'	,0x1D19	,0x204D	,0x0000), // 'b' ➔ "⁍" U+204D BLACK RIGHTWARDS BULLET
/*<!M><%backslash><C>                                              */ DEADTRANS( L'C'	,0x1D19	,0x2183	,0x0000), // 'C' ➔ "Ↄ" U+2183 ROMAN NUMERAL REVERSED ONE HUNDRED
/*<!M><%backslash><c>                                              */ DEADTRANS( L'c'	,0x1D19	,0x2184	,0x0000), // 'c' ➔ "ↄ" U+2184 LATIN SMALL LETTER REVERSED C
/*<!M><%backslash><D>                                              */ DEADTRANS( L'D'	,0x1D19	,0x204C	,0x0000), // 'D' ➔ "⁌" U+204C BLACK LEFTWARDS BULLET
/*<!M><%backslash><d>                                              */ DEADTRANS( L'd'	,0x1D19	,0x204C	,0x0000), // 'd' ➔ "⁌" U+204C BLACK LEFTWARDS BULLET
/*<!M><%backslash><E>                                              */ DEADTRANS( L'E'	,0x1D19	,0x018E	,0x0000), // 'E' ➔ "Ǝ" U+018E LATIN CAPITAL LETTER REVERSED E
/*<!M><%backslash><e>                                              */ DEADTRANS( L'e'	,0x1D19	,0x0258	,0x0000), // 'e' ➔ "ɘ" U+0258 LATIN SMALL LETTER REVERSED E
/*<!M><%backslash><f>                                              */ DEADTRANS( L'f'	,0x1D19	,0x2619	,0x0000), // 'f' ➔ "☙" U+2619 REVERSED ROTATED FLORAL HEART BULLET
/*<!M><%backslash><F>                                              */ DEADTRANS( L'F'	,0x1D19	,0xA7FB	,0x0000), // 'F' ➔ "ꟻ" U+A7FB LATIN EPIGRAPHIC LETTER REVERSED F
/*<!M><%backslash><G>                                              */ DEADTRANS( L'G'	,0x1D19	,0x0295	,0x0000), // 'G' ➔ "ʕ" U+0295 LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*<!M><%backslash><g>                                              */ DEADTRANS( L'g'	,0x1D19	,0xDF01	,0x0000), // High surrogate: D837; 'g' ➔ "𝼁" U+1DF01 LATIN SMALL LETTER REVERSED SCRIPT G
/*<!M><%backslash><H>                                              */ DEADTRANS( L'H'	,0x1D19	,0xA7F5	,0x0000), // 'H' ➔ "Ꟶ" U+A7F5 LATIN CAPITAL LETTER REVERSED HALF H
/*<!M><%backslash><h>                                              */ DEADTRANS( L'h'	,0x1D19	,0xA7F6	,0x0000), // 'h' ➔ "ꟶ" U+A7F6 LATIN SMALL LETTER REVERSED HALF H
/*<!M><%backslash><k>                                              */ DEADTRANS( L'k'	,0x1D19	,0xDF03	,0x0000), // High surrogate: D837; 'k' ➔ "𝼃" U+1DF03 LATIN SMALL LETTER REVERSED K
/*<!M><%backslash><L>                                              */ DEADTRANS( L'L'	,0x1D19	,0x2143	,0x0000), // 'L' ➔ "⅃" U+2143 REVERSED SANS-SERIF CAPITAL L
/*<!M><%backslash><l>                                              */ DEADTRANS( L'l'	,0x1D19	,0x2BFE	,0x0000), // 'l' ➔ "⯾" U+2BFE REVERSED RIGHT ANGLE
/*<!M><%backslash><N>                                              */ DEADTRANS( L'N'	,0x1D19	,0x1D0E	,0x0000), // 'N' ➔ "ᴎ" U+1D0E LATIN LETTER SMALL CAPITAL REVERSED N
/*<!M><%backslash><n>                                              */ DEADTRANS( L'n'	,0x1D19	,0xDF07	,0x0000), // High surrogate: D837; 'n' ➔ "𝼇" U+1DF07 LATIN SMALL LETTER REVERSED ENG
/*<!M><%backslash><o>                                              */ DEADTRANS( L'o'	,0x1D19	,0xAB43	,0x0000), // 'o' ➔ "ꭃ" U+AB43 LATIN SMALL LETTER TURNED O OPEN-O
/*<!M><%backslash><p>                                              */ DEADTRANS( L'p'	,0x1D19	,0x204B	,0x0000), // 'p' ➔ "⁋" U+204B REVERSED PILCROW SIGN
/*<!M><%backslash><P>                                              */ DEADTRANS( L'P'	,0x1D19	,0xA7FC	,0x0000), // 'P' ➔ "ꟼ" U+A7FC LATIN EPIGRAPHIC LETTER REVERSED P
/*<!M><%backslash><paragraph>                                      */ DEADTRANS( 0x00A7	,0x1D19	,0x204B	,0x0000), // '§' ➔ "⁋" U+204B REVERSED PILCROW SIGN
/*<!M><%backslash><Q>                                              */ DEADTRANS( L'Q'	,0x1D19	,0xA7CE	,0x0000), // 'Q' ➔ "꟎" U+A7CE LATIN CAPITAL LETTER PHARYNGEAL VOICED FRICATIVE
/*<!M><%backslash><q>                                              */ DEADTRANS( L'q'	,0x1D19	,0xA7CF	,0x0000), // 'q' ➔ "꟏" U+A7CF LATIN SMALL LETTER PHARYNGEAL VOICED FRICATIVE
/*<!M><%backslash><r>                                              */ DEADTRANS( L'r'	,0x1D19	,0x027F	,0x0000), // 'r' ➔ "ɿ" U+027F LATIN SMALL LETTER REVERSED R WITH FISHHOOK
/*<!M><%backslash><R>                                              */ DEADTRANS( L'R'	,0x1D19	,0x1D19	,0x0000), // 'R' ➔ "ᴙ" U+1D19 LATIN LETTER SMALL CAPITAL REVERSED R
/*<!M><%backslash><S>                                              */ DEADTRANS( L'S'	,0x1D19	,0x01AA	,0x0000), // 'S' ➔ "ƪ" U+01AA LATIN LETTER REVERSED ESH LOOP
/*<!M><%backslash><s>                                              */ DEADTRANS( L's'	,0x1D19	,0x0285	,0x0000), // 's' ➔ "ʅ" U+0285 LATIN SMALL LETTER SQUAT REVERSED ESH
/*<!M><%backslash><V>                                              */ DEADTRANS( L'V'	,0x1D19	,0xA73E	,0x0000), // 'V' ➔ "Ꜿ" U+A73E LATIN CAPITAL LETTER REVERSED C WITH DOT
/*<!M><%backslash><v>                                              */ DEADTRANS( L'v'	,0x1D19	,0xA73F	,0x0000), // 'v' ➔ "ꜿ" U+A73F LATIN SMALL LETTER REVERSED C WITH DOT
/*<!M><%backslash><W>                                              */ DEADTRANS( L'W'	,0x1D19	,0x2AED	,0x0000), // 'W' ➔ "⫭" U+2AED REVERSED DOUBLE STROKE NOT SIGN
/*<!M><%backslash><w>                                              */ DEADTRANS( L'w'	,0x1D19	,0x2AED	,0x0000), // 'w' ➔ "⫭" U+2AED REVERSED DOUBLE STROKE NOT SIGN
/*<!M><%backslash><x>                                              */ DEADTRANS( L'x'	,0x1D19	,0x025C	,0x0000), // 'x' ➔ "ɜ" U+025C LATIN SMALL LETTER REVERSED OPEN E
/*<!M><%backslash><X>                                              */ DEADTRANS( L'X'	,0x1D19	,0xA7AB	,0x0000), // 'X' ➔ "Ɜ" U+A7AB LATIN CAPITAL LETTER REVERSED OPEN E
/*<!M><%backslash><Z>                                              */ DEADTRANS( L'Z'	,0x1D19	,0x01B8	,0x0000), // 'Z' ➔ "Ƹ" U+01B8 LATIN CAPITAL LETTER EZH REVERSED
/*<!M><%backslash><z>                                              */ DEADTRANS( L'z'	,0x1D19	,0x01B9	,0x0000), // 'z' ➔ "ƹ" U+01B9 LATIN SMALL LETTER EZH REVERSED
/*<!M><%backslash><~nbspace>                                       */ DEADTRANS( 0x00A0	,0x1D19	,0x02BD	,0x0000), // ' ' ➔ "ʽ" U+02BD MODIFIER LETTER REVERSED COMMA
/*<!M><%backslash><~nbthinspace>                                   */ DEADTRANS( 0x202F	,0x1D19	,0x02BD	,0x0000), // ' ' ➔ "ʽ" U+02BD MODIFIER LETTER REVERSED COMMA
/*<!M><%backslash><~space>                                         */ DEADTRANS( L' '	,0x1D19	,0x0314	,0x0000), // ' ' ➔ "̔" U+0314 COMBINING REVERSED COMMA ABOVE
/*<!M><%backslash><~spacezerowidth>                                */ DEADTRANS( 0x200B	,0x1D19	,0x0314	,0x0000), // '​' ➔ "̔" U+0314 COMBINING REVERSED COMMA ABOVE
/*<!M><%bar><%ampersand>                                           */ DEADTRANS( L'&'	,0x0101	,0xFE26	,0x0000), // '&' ➔ "︦" U+FE26 COMBINING CONJOINING MACRON
/*<!M><%bar><%dollar>                                              */ DEADTRANS( L'$'	,0x0101	,0x035E	,0x0000), // '$' ➔ "͞" U+035E COMBINING DOUBLE MACRON
/*<!M><%bar><%plus>                                                */ DEADTRANS( L'+'	,0x0101	,0x2020	,0x0000), // '+' ➔ "†" U+2020 DAGGER
/*<!M><%bar><%question>                                            */ DEADTRANS( L'?'	,0x0101	,0x22BD	,0x0000), // '?' ➔ "⊽" U+22BD NOR
/*<!M><%bar><0>                                                    */ DEADTRANS( L'0'	,0x0101	,0x2AFE	,0x0000), // '0' ➔ "⫾" U+2AFE WHITE VERTICAL BAR
/*<!M><%bar><1>                                                    */ DEADTRANS( L'1'	,0x0101	,0x2223	,0x0000), // '1' ➔ "∣" U+2223 DIVIDES
/*<!M><%bar><2>                                                    */ DEADTRANS( L'2'	,0x0101	,0x2016	,0x0000), // '2' ➔ "‖" U+2016 DOUBLE VERTICAL LINE
/*<!M><%bar><3>                                                    */ DEADTRANS( L'3'	,0x0101	,0x2980	,0x0000), // '3' ➔ "⦀" U+2980 TRIPLE VERTICAL BAR DELIMITER
/*<!M><%bar><4>                                                    */ DEADTRANS( L'4'	,0x0101	,0x2225	,0x0000), // '4' ➔ "∥" U+2225 PARALLEL TO
/*<!M><%bar><5>                                                    */ DEADTRANS( L'5'	,0x0101	,0x01C0	,0x0000), // '5' ➔ "ǀ" U+01C0 LATIN LETTER DENTAL CLICK
/*<!M><%bar><6>                                                    */ DEADTRANS( L'6'	,0x0101	,0x2AF4	,0x0000), // '6' ➔ "⫴" U+2AF4 TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><%bar><7>                                                    */ DEADTRANS( L'7'	,0x0101	,0x2AFF	,0x0000), // '7' ➔ "⫿" U+2AFF N-ARY WHITE VERTICAL BAR
/*<!M><%bar><8>                                                    */ DEADTRANS( L'8'	,0x0101	,0x01C1	,0x0000), // '8' ➔ "ǁ" U+01C1 LATIN LETTER LATERAL CLICK
/*<!M><%bar><9>                                                    */ DEADTRANS( L'9'	,0x0101	,0x2AFC	,0x0000), // '9' ➔ "⫼" U+2AFC LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><%bar><A>                                                    */ DEADTRANS( L'A'	,0x0101	,0x0100	,0x0000), // 'A' ➔ "Ā" U+0100 LATIN CAPITAL LETTER A WITH MACRON
/*<!M><%bar><a>                                                    */ DEADTRANS( L'a'	,0x0101	,0x0101	,0x0000), // 'a' ➔ "ā" U+0101 LATIN SMALL LETTER A WITH MACRON
/*<!M><%bar><B>                                                    */ DEADTRANS( L'B'	,0x0101	,0x0182	,0x0000), // 'B' ➔ "Ƃ" U+0182 LATIN CAPITAL LETTER B WITH TOPBAR
/*<!M><%bar><b>                                                    */ DEADTRANS( L'b'	,0x0101	,0x0183	,0x0000), // 'b' ➔ "ƃ" U+0183 LATIN SMALL LETTER B WITH TOPBAR
/*<!M><%bar><c>                                                    */ DEADTRANS( L'c'	,0x0101	,0x00A2	,0x0000), // 'c' ➔ "¢" U+00A2 CENT SIGN
/*<!M><%bar><C>                                                    */ DEADTRANS( L'C'	,0x0101	,0x20B5	,0x0000), // 'C' ➔ "₵" U+20B5 CEDI SIGN
/*<!M><%bar><D>                                                    */ DEADTRANS( L'D'	,0x0101	,0x018B	,0x0000), // 'D' ➔ "Ƌ" U+018B LATIN CAPITAL LETTER D WITH TOPBAR
/*<!M><%bar><d>                                                    */ DEADTRANS( L'd'	,0x0101	,0x018C	,0x0000), // 'd' ➔ "ƌ" U+018C LATIN SMALL LETTER D WITH TOPBAR
/*<!M><%bar><E>                                                    */ DEADTRANS( L'E'	,0x0101	,0x0112	,0x0000), // 'E' ➔ "Ē" U+0112 LATIN CAPITAL LETTER E WITH MACRON
/*<!M><%bar><e>                                                    */ DEADTRANS( L'e'	,0x0101	,0x0113	,0x0000), // 'e' ➔ "ē" U+0113 LATIN SMALL LETTER E WITH MACRON
/*<!M><%bar><Eacute>                                               */ DEADTRANS( 0x00C9	,0x0101	,0x1E16	,0x0000), // 'É' ➔ "Ḗ" U+1E16 LATIN CAPITAL LETTER E WITH MACRON AND ACUTE
/*<!M><%bar><eacute>                                               */ DEADTRANS( 0x00E9	,0x0101	,0x1E17	,0x0000), // 'é' ➔ "ḗ" U+1E17 LATIN SMALL LETTER E WITH MACRON AND ACUTE
/*<!M><%bar><Egrave>                                               */ DEADTRANS( 0x00C8	,0x0101	,0x1E14	,0x0000), // 'È' ➔ "Ḕ" U+1E14 LATIN CAPITAL LETTER E WITH MACRON AND GRAVE
/*<!M><%bar><egrave>                                               */ DEADTRANS( 0x00E8	,0x0101	,0x1E15	,0x0000), // 'è' ➔ "ḕ" U+1E15 LATIN SMALL LETTER E WITH MACRON AND GRAVE
/*<!M><%bar><emdash>                                               */ DEADTRANS( 0x2014	,0x0101	,0x035E	,0x0000), // '—' ➔ "͞" U+035E COMBINING DOUBLE MACRON
/*<!M><%bar><F>                                                    */ DEADTRANS( L'F'	,0x0101	,0xFE24	,0x0000), // 'F' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><f>                                                    */ DEADTRANS( L'f'	,0x0101	,0xFE25	,0x0000), // 'f' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><G>                                                    */ DEADTRANS( L'G'	,0x0101	,0x1E20	,0x0000), // 'G' ➔ "Ḡ" U+1E20 LATIN CAPITAL LETTER G WITH MACRON
/*<!M><%bar><g>                                                    */ DEADTRANS( L'g'	,0x0101	,0x1E21	,0x0000), // 'g' ➔ "ḡ" U+1E21 LATIN SMALL LETTER G WITH MACRON
/*<!M><%bar><H>                                                    */ DEADTRANS( L'H'	,0x0101	,0xFE24	,0x0000), // 'H' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><h>                                                    */ DEADTRANS( L'h'	,0x0101	,0xFE25	,0x0000), // 'h' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><I>                                                    */ DEADTRANS( L'I'	,0x0101	,0x012A	,0x0000), // 'I' ➔ "Ī" U+012A LATIN CAPITAL LETTER I WITH MACRON
/*<!M><%bar><i>                                                    */ DEADTRANS( L'i'	,0x0101	,0x012B	,0x0000), // 'i' ➔ "ī" U+012B LATIN SMALL LETTER I WITH MACRON
/*<!M><%bar><J>                                                    */ DEADTRANS( L'J'	,0x0101	,0xFE24	,0x0000), // 'J' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><j>                                                    */ DEADTRANS( L'j'	,0x0101	,0xFE25	,0x0000), // 'j' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><K>                                                    */ DEADTRANS( L'K'	,0x0101	,0xFE24	,0x0000), // 'K' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><k>                                                    */ DEADTRANS( L'k'	,0x0101	,0xFE25	,0x0000), // 'k' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><L>                                                    */ DEADTRANS( L'L'	,0x0101	,0x22F6	,0x0000), // 'L' ➔ "⋶" U+22F6 ELEMENT OF WITH OVERBAR
/*<!M><%bar><l>                                                    */ DEADTRANS( L'l'	,0x0101	,0x22F7	,0x0000), // 'l' ➔ "⋷" U+22F7 SMALL ELEMENT OF WITH OVERBAR
/*<!M><%bar><M>                                                    */ DEADTRANS( L'M'	,0x0101	,0x22FD	,0x0000), // 'M' ➔ "⋽" U+22FD CONTAINS WITH OVERBAR
/*<!M><%bar><m>                                                    */ DEADTRANS( L'm'	,0x0101	,0x22FE	,0x0000), // 'm' ➔ "⋾" U+22FE SMALL CONTAINS WITH OVERBAR
/*<!M><%bar><O>                                                    */ DEADTRANS( L'O'	,0x0101	,0x014C	,0x0000), // 'O' ➔ "Ō" U+014C LATIN CAPITAL LETTER O WITH MACRON
/*<!M><%bar><o>                                                    */ DEADTRANS( L'o'	,0x0101	,0x014D	,0x0000), // 'o' ➔ "ō" U+014D LATIN SMALL LETTER O WITH MACRON
/*<!M><%bar><Q>                                                    */ DEADTRANS( L'Q'	,0x0101	,0xFE24	,0x0000), // 'Q' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><q>                                                    */ DEADTRANS( L'q'	,0x0101	,0xFE25	,0x0000), // 'q' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><R>                                                    */ DEADTRANS( L'R'	,0x0101	,0x027A	,0x0000), // 'R' ➔ "ɺ" U+027A LATIN SMALL LETTER TURNED R WITH LONG LEG
/*<!M><%bar><r>                                                    */ DEADTRANS( L'r'	,0x0101	,0x027C	,0x0000), // 'r' ➔ "ɼ" U+027C LATIN SMALL LETTER R WITH LONG LEG
/*<!M><%bar><S>                                                    */ DEADTRANS( L'S'	,0x0101	,0x2A1B	,0x0000), // 'S' ➔ "⨛" U+2A1B INTEGRAL WITH OVERBAR
/*<!M><%bar><s>                                                    */ DEADTRANS( L's'	,0x0101	,0x2A1B	,0x0000), // 's' ➔ "⨛" U+2A1B INTEGRAL WITH OVERBAR
/*<!M><%bar><T>                                                    */ DEADTRANS( L'T'	,0x0101	,0x2AE7	,0x0000), // 'T' ➔ "⫧" U+2AE7 SHORT DOWN TACK WITH OVERBAR
/*<!M><%bar><t>                                                    */ DEADTRANS( L't'	,0x0101	,0x2AE7	,0x0000), // 't' ➔ "⫧" U+2AE7 SHORT DOWN TACK WITH OVERBAR
/*<!M><%bar><U>                                                    */ DEADTRANS( L'U'	,0x0101	,0x016A	,0x0000), // 'U' ➔ "Ū" U+016A LATIN CAPITAL LETTER U WITH MACRON
/*<!M><%bar><u>                                                    */ DEADTRANS( L'u'	,0x0101	,0x016B	,0x0000), // 'u' ➔ "ū" U+016B LATIN SMALL LETTER U WITH MACRON
/*<!M><%bar><V>                                                    */ DEADTRANS( L'V'	,0x0101	,0xFE24	,0x0000), // 'V' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><v>                                                    */ DEADTRANS( L'v'	,0x0101	,0xFE25	,0x0000), // 'v' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><x>                                                    */ DEADTRANS( L'x'	,0x0101	,0xAB57	,0x0000), // 'x' ➔ "ꭗ" U+AB57 LATIN SMALL LETTER X WITH LONG LEFT LEG
/*<!M><%bar><X>                                                    */ DEADTRANS( L'X'	,0x0101	,0xAB58	,0x0000), // 'X' ➔ "ꭘ" U+AB58 LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*<!M><%bar><Y>                                                    */ DEADTRANS( L'Y'	,0x0101	,0x0232	,0x0000), // 'Y' ➔ "Ȳ" U+0232 LATIN CAPITAL LETTER Y WITH MACRON
/*<!M><%bar><y>                                                    */ DEADTRANS( L'y'	,0x0101	,0x0233	,0x0000), // 'y' ➔ "ȳ" U+0233 LATIN SMALL LETTER Y WITH MACRON
/*<!M><%bar><Z>                                                    */ DEADTRANS( L'Z'	,0x0101	,0xFE24	,0x0000), // 'Z' ➔ "︤" U+FE24 COMBINING MACRON LEFT HALF
/*<!M><%bar><z>                                                    */ DEADTRANS( L'z'	,0x0101	,0xFE25	,0x0000), // 'z' ➔ "︥" U+FE25 COMBINING MACRON RIGHT HALF
/*<!M><%bar><~nbspace>                                             */ DEADTRANS( 0x00A0	,0x0101	,0x00AF	,0x0000), // ' ' ➔ "¯" U+00AF MACRON
/*<!M><%bar><~nbthinspace>                                         */ DEADTRANS( 0x202F	,0x0101	,0x02C9	,0x0000), // ' ' ➔ "ˉ" U+02C9 MODIFIER LETTER MACRON
/*<!M><%bar><~space>                                               */ DEADTRANS( L' '	,0x0101	,0x0304	,0x0000), // ' ' ➔ "̄" U+0304 COMBINING MACRON
/*<!M><%bar><~spacezerowidth>                                      */ DEADTRANS( 0x200B	,0x0101	,0x0304	,0x0000), // '​' ➔ "̄" U+0304 COMBINING MACRON
/*<!M><%braceleft><%period>                                        */ DEADTRANS( L'.'	,0x0192	,0x2055	,0x0000), // '.' ➔ "⁕" U+2055 FLOWER PUNCTUATION MARK
/*<!M><%braceleft><1>                                              */ DEADTRANS( L'1'	,0x0192	,0x02E9	,0x0000), // '1' ➔ "˩" U+02E9 MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!M><%braceleft><2>                                              */ DEADTRANS( L'2'	,0x0192	,0x02E8	,0x0000), // '2' ➔ "˨" U+02E8 MODIFIER LETTER LOW TONE BAR
/*<!M><%braceleft><3>                                              */ DEADTRANS( L'3'	,0x0192	,0x02E7	,0x0000), // '3' ➔ "˧" U+02E7 MODIFIER LETTER MID TONE BAR
/*<!M><%braceleft><4>                                              */ DEADTRANS( L'4'	,0x0192	,0x02E6	,0x0000), // '4' ➔ "˦" U+02E6 MODIFIER LETTER HIGH TONE BAR
/*<!M><%braceleft><5>                                              */ DEADTRANS( L'5'	,0x0192	,0x02E5	,0x0000), // '5' ➔ "˥" U+02E5 MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!M><%braceleft><B>                                              */ DEADTRANS( L'B'	,0x0192	,0x0181	,0x0000), // 'B' ➔ "Ɓ" U+0181 LATIN CAPITAL LETTER B WITH HOOK
/*<!M><%braceleft><b>                                              */ DEADTRANS( L'b'	,0x0192	,0x0253	,0x0000), // 'b' ➔ "ɓ" U+0253 LATIN SMALL LETTER B WITH HOOK
/*<!M><%braceleft><C>                                              */ DEADTRANS( L'C'	,0x0192	,0x0187	,0x0000), // 'C' ➔ "Ƈ" U+0187 LATIN CAPITAL LETTER C WITH HOOK
/*<!M><%braceleft><c>                                              */ DEADTRANS( L'c'	,0x0192	,0x0188	,0x0000), // 'c' ➔ "ƈ" U+0188 LATIN SMALL LETTER C WITH HOOK
/*<!M><%braceleft><D>                                              */ DEADTRANS( L'D'	,0x0192	,0x018A	,0x0000), // 'D' ➔ "Ɗ" U+018A LATIN CAPITAL LETTER D WITH HOOK
/*<!M><%braceleft><d>                                              */ DEADTRANS( L'd'	,0x0192	,0x0257	,0x0000), // 'd' ➔ "ɗ" U+0257 LATIN SMALL LETTER D WITH HOOK
/*<!M><%braceleft><e>                                              */ DEADTRANS( L'e'	,0x0192	,0x025D	,0x0000), // 'e' ➔ "ɝ" U+025D LATIN SMALL LETTER REVERSED OPEN E WITH HOOK
/*<!M><%braceleft><F>                                              */ DEADTRANS( L'F'	,0x0192	,0x0191	,0x0000), // 'F' ➔ "Ƒ" U+0191 LATIN CAPITAL LETTER F WITH HOOK
/*<!M><%braceleft><f>                                              */ DEADTRANS( L'f'	,0x0192	,0x0192	,0x0000), // 'f' ➔ "ƒ" U+0192 LATIN SMALL LETTER F WITH HOOK
/*<!M><%braceleft><G>                                              */ DEADTRANS( L'G'	,0x0192	,0x0193	,0x0000), // 'G' ➔ "Ɠ" U+0193 LATIN CAPITAL LETTER G WITH HOOK
/*<!M><%braceleft><g>                                              */ DEADTRANS( L'g'	,0x0192	,0x0260	,0x0000), // 'g' ➔ "ɠ" U+0260 LATIN SMALL LETTER G WITH HOOK
/*<!M><%braceleft><h>                                              */ DEADTRANS( L'h'	,0x0192	,0x0266	,0x0000), // 'h' ➔ "ɦ" U+0266 LATIN SMALL LETTER H WITH HOOK
/*<!M><%braceleft><H>                                              */ DEADTRANS( L'H'	,0x0192	,0xA7AA	,0x0000), // 'H' ➔ "Ɦ" U+A7AA LATIN CAPITAL LETTER H WITH HOOK
/*<!M><%braceleft><j>                                              */ DEADTRANS( L'j'	,0x0192	,0x0284	,0x0000), // 'j' ➔ "ʄ" U+0284 LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*<!M><%braceleft><K>                                              */ DEADTRANS( L'K'	,0x0192	,0x0198	,0x0000), // 'K' ➔ "Ƙ" U+0198 LATIN CAPITAL LETTER K WITH HOOK
/*<!M><%braceleft><k>                                              */ DEADTRANS( L'k'	,0x0192	,0x0199	,0x0000), // 'k' ➔ "ƙ" U+0199 LATIN SMALL LETTER K WITH HOOK
/*<!M><%braceleft><l>                                              */ DEADTRANS( L'l'	,0x0192	,0xDF11	,0x0000), // High surrogate: D837; 'l' ➔ "𝼑" U+1DF11 LATIN SMALL LETTER L WITH FISHHOOK
/*<!M><%braceleft><m>                                              */ DEADTRANS( L'm'	,0x0192	,0x0271	,0x0000), // 'm' ➔ "ɱ" U+0271 LATIN SMALL LETTER M WITH HOOK
/*<!M><%braceleft><M>                                              */ DEADTRANS( L'M'	,0x0192	,0x2C6E	,0x0000), // 'M' ➔ "Ɱ" U+2C6E LATIN CAPITAL LETTER M WITH HOOK
/*<!M><%braceleft><N>                                              */ DEADTRANS( L'N'	,0x0192	,0x019D	,0x0000), // 'N' ➔ "Ɲ" U+019D LATIN CAPITAL LETTER N WITH LEFT HOOK
/*<!M><%braceleft><n>                                              */ DEADTRANS( L'n'	,0x0192	,0x0272	,0x0000), // 'n' ➔ "ɲ" U+0272 LATIN SMALL LETTER N WITH LEFT HOOK
/*<!M><%braceleft><P>                                              */ DEADTRANS( L'P'	,0x0192	,0x01A4	,0x0000), // 'P' ➔ "Ƥ" U+01A4 LATIN CAPITAL LETTER P WITH HOOK
/*<!M><%braceleft><p>                                              */ DEADTRANS( L'p'	,0x0192	,0x01A5	,0x0000), // 'p' ➔ "ƥ" U+01A5 LATIN SMALL LETTER P WITH HOOK
/*<!M><%braceleft><q>                                              */ DEADTRANS( L'q'	,0x0192	,0x02A0	,0x0000), // 'q' ➔ "ʠ" U+02A0 LATIN SMALL LETTER Q WITH HOOK
/*<!M><%braceleft><r>                                              */ DEADTRANS( L'r'	,0x0192	,0x027E	,0x0000), // 'r' ➔ "ɾ" U+027E LATIN SMALL LETTER R WITH FISHHOOK
/*<!M><%braceleft><s>                                              */ DEADTRANS( L's'	,0x0192	,0x0282	,0x0000), // 's' ➔ "ʂ" U+0282 LATIN SMALL LETTER S WITH HOOK
/*<!M><%braceleft><S>                                              */ DEADTRANS( L'S'	,0x0192	,0xA7C5	,0x0000), // 'S' ➔ "Ʂ" U+A7C5 LATIN CAPITAL LETTER S WITH HOOK
/*<!M><%braceleft><T>                                              */ DEADTRANS( L'T'	,0x0192	,0x01AC	,0x0000), // 'T' ➔ "Ƭ" U+01AC LATIN CAPITAL LETTER T WITH HOOK
/*<!M><%braceleft><t>                                              */ DEADTRANS( L't'	,0x0192	,0x01AD	,0x0000), // 't' ➔ "ƭ" U+01AD LATIN SMALL LETTER T WITH HOOK
/*<!M><%braceleft><V>                                              */ DEADTRANS( L'V'	,0x0192	,0x01B2	,0x0000), // 'V' ➔ "Ʋ" U+01B2 LATIN CAPITAL LETTER V WITH HOOK
/*<!M><%braceleft><v>                                              */ DEADTRANS( L'v'	,0x0192	,0x028B	,0x0000), // 'v' ➔ "ʋ" U+028B LATIN SMALL LETTER V WITH HOOK
/*<!M><%braceleft><W>                                              */ DEADTRANS( L'W'	,0x0192	,0x2C72	,0x0000), // 'W' ➔ "Ⱳ" U+2C72 LATIN CAPITAL LETTER W WITH HOOK
/*<!M><%braceleft><w>                                              */ DEADTRANS( L'w'	,0x0192	,0x2C73	,0x0000), // 'w' ➔ "ⱳ" U+2C73 LATIN SMALL LETTER W WITH HOOK
/*<!M><%braceleft><Y>                                              */ DEADTRANS( L'Y'	,0x0192	,0x01B3	,0x0000), // 'Y' ➔ "Ƴ" U+01B3 LATIN CAPITAL LETTER Y WITH HOOK
/*<!M><%braceleft><y>                                              */ DEADTRANS( L'y'	,0x0192	,0x01B4	,0x0000), // 'y' ➔ "ƴ" U+01B4 LATIN SMALL LETTER Y WITH HOOK
/*<!M><%braceleft><Z>                                              */ DEADTRANS( L'Z'	,0x0192	,0x0224	,0x0000), // 'Z' ➔ "Ȥ" U+0224 LATIN CAPITAL LETTER Z WITH HOOK
/*<!M><%braceleft><z>                                              */ DEADTRANS( L'z'	,0x0192	,0x0225	,0x0000), // 'z' ➔ "ȥ" U+0225 LATIN SMALL LETTER Z WITH HOOK
/*<!M><%braceleft><~nbspace>                                       */ DEADTRANS( 0x00A0	,0x0192	,0x02DE	,0x0000), // ' ' ➔ "˞" U+02DE MODIFIER LETTER RHOTIC HOOK
/*<!M><%braceleft><~nbthinspace>                                   */ DEADTRANS( 0x202F	,0x0192	,0x02DE	,0x0000), // ' ' ➔ "˞" U+02DE MODIFIER LETTER RHOTIC HOOK
/*<!M><%braceleft><~space>                                         */ DEADTRANS( L' '	,0x0192	,0x0321	,0x0000), // ' ' ➔ "̡" U+0321 COMBINING PALATALIZED HOOK BELOW
/*<!M><%braceleft><~spacezerowidth>                                */ DEADTRANS( 0x200B	,0x0192	,0x0321	,0x0000), // '​' ➔ "̡" U+0321 COMBINING PALATALIZED HOOK BELOW
/*<!M><%braceright><%exclam>                                       */ DEADTRANS( L'!'	,0x0273	,0xDF0A	,0x0000), // High surrogate: D837; '!' ➔ "𝼊" U+1DF0A LATIN LETTER RETROFLEX CLICK WITH RETROFLEX HOOK
/*<!M><%braceright><0>                                             */ DEADTRANS( L'0'	,0x0273	,0x2672	,0x0000), // '0' ➔ "♲" U+2672 UNIVERSAL RECYCLING SYMBOL
/*<!M><%braceright><1>                                             */ DEADTRANS( L'1'	,0x0273	,0x2673	,0x0000), // '1' ➔ "♳" U+2673 RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><%braceright><2>                                             */ DEADTRANS( L'2'	,0x0273	,0x2674	,0x0000), // '2' ➔ "♴" U+2674 RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><%braceright><3>                                             */ DEADTRANS( L'3'	,0x0273	,0x2675	,0x0000), // '3' ➔ "♵" U+2675 RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><%braceright><4>                                             */ DEADTRANS( L'4'	,0x0273	,0x2676	,0x0000), // '4' ➔ "♶" U+2676 RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><%braceright><5>                                             */ DEADTRANS( L'5'	,0x0273	,0x2677	,0x0000), // '5' ➔ "♷" U+2677 RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><%braceright><6>                                             */ DEADTRANS( L'6'	,0x0273	,0x2678	,0x0000), // '6' ➔ "♸" U+2678 RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><%braceright><7>                                             */ DEADTRANS( L'7'	,0x0273	,0x2679	,0x0000), // '7' ➔ "♹" U+2679 RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><%braceright><8>                                             */ DEADTRANS( L'8'	,0x0273	,0x267A	,0x0000), // '8' ➔ "♺" U+267A RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><%braceright><9>                                             */ DEADTRANS( L'9'	,0x0273	,0x267B	,0x0000), // '9' ➔ "♻" U+267B BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><%braceright><a>                                             */ DEADTRANS( L'a'	,0x0273	,0x1D8F	,0x0000), // 'a' ➔ "ᶏ" U+1D8F LATIN SMALL LETTER A WITH RETROFLEX HOOK
/*<!M><%braceright><c>                                             */ DEADTRANS( L'c'	,0x0273	,0xDF1D	,0x0000), // High surrogate: D837; 'c' ➔ "𝼝" U+1DF1D LATIN SMALL LETTER C WITH RETROFLEX HOOK
/*<!M><%braceright><D>                                             */ DEADTRANS( L'D'	,0x0273	,0x0189	,0x0000), // 'D' ➔ "Ɖ" U+0189 LATIN CAPITAL LETTER AFRICAN D
/*<!M><%braceright><d>                                             */ DEADTRANS( L'd'	,0x0273	,0x0256	,0x0000), // 'd' ➔ "ɖ" U+0256 LATIN SMALL LETTER D WITH TAIL
/*<!M><%braceright><e>                                             */ DEADTRANS( L'e'	,0x0273	,0x1D92	,0x0000), // 'e' ➔ "ᶒ" U+1D92 LATIN SMALL LETTER E WITH RETROFLEX HOOK
/*<!M><%braceright><i>                                             */ DEADTRANS( L'i'	,0x0273	,0x1D96	,0x0000), // 'i' ➔ "ᶖ" U+1D96 LATIN SMALL LETTER I WITH RETROFLEX HOOK
/*<!M><%braceright><l>                                             */ DEADTRANS( L'l'	,0x0273	,0x026D	,0x0000), // 'l' ➔ "ɭ" U+026D LATIN SMALL LETTER L WITH RETROFLEX HOOK
/*<!M><%braceright><n>                                             */ DEADTRANS( L'n'	,0x0273	,0x0273	,0x0000), // 'n' ➔ "ɳ" U+0273 LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*<!M><%braceright><o>                                             */ DEADTRANS( L'o'	,0x0273	,0xDF1B	,0x0000), // High surrogate: D837; 'o' ➔ "𝼛" U+1DF1B LATIN SMALL LETTER O WITH RETROFLEX HOOK
/*<!M><%braceright><P>                                             */ DEADTRANS( L'P'	,0x0273	,0xA754	,0x0000), // 'P' ➔ "Ꝕ" U+A754 LATIN CAPITAL LETTER P WITH SQUIRREL TAIL
/*<!M><%braceright><p>                                             */ DEADTRANS( L'p'	,0x0273	,0xA755	,0x0000), // 'p' ➔ "ꝕ" U+A755 LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*<!M><%braceright><Q>                                             */ DEADTRANS( L'Q'	,0x0273	,0x024A	,0x0000), // 'Q' ➔ "Ɋ" U+024A LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*<!M><%braceright><q>                                             */ DEADTRANS( L'q'	,0x0273	,0x024B	,0x0000), // 'q' ➔ "ɋ" U+024B LATIN SMALL LETTER Q WITH HOOK TAIL
/*<!M><%braceright><r>                                             */ DEADTRANS( L'r'	,0x0273	,0x027D	,0x0000), // 'r' ➔ "ɽ" U+027D LATIN SMALL LETTER R WITH TAIL
/*<!M><%braceright><R>                                             */ DEADTRANS( L'R'	,0x0273	,0x2C64	,0x0000), // 'R' ➔ "Ɽ" U+2C64 LATIN CAPITAL LETTER R WITH TAIL
/*<!M><%braceright><s>                                             */ DEADTRANS( L's'	,0x0273	,0x0282	,0x0000), // 's' ➔ "ʂ" U+0282 LATIN SMALL LETTER S WITH HOOK
/*<!M><%braceright><T>                                             */ DEADTRANS( L'T'	,0x0273	,0x01AE	,0x0000), // 'T' ➔ "Ʈ" U+01AE LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*<!M><%braceright><t>                                             */ DEADTRANS( L't'	,0x0273	,0x0288	,0x0000), // 't' ➔ "ʈ" U+0288 LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*<!M><%braceright><u>                                             */ DEADTRANS( L'u'	,0x0273	,0x1D99	,0x0000), // 'u' ➔ "ᶙ" U+1D99 LATIN SMALL LETTER U WITH RETROFLEX HOOK
/*<!M><%braceright><v>                                             */ DEADTRANS( L'v'	,0x0273	,0x2C71	,0x0000), // 'v' ➔ "ⱱ" U+2C71 LATIN SMALL LETTER V WITH RIGHT HOOK
/*<!M><%braceright><z>                                             */ DEADTRANS( L'z'	,0x0273	,0x0290	,0x0000), // 'z' ➔ "ʐ" U+0290 LATIN SMALL LETTER Z WITH RETROFLEX HOOK
/*<!M><%braceright><~nbspace>                                      */ DEADTRANS( 0x00A0	,0x0273	,0x02FE	,0x0000), // ' ' ➔ "˾" U+02FE MODIFIER LETTER OPEN SHELF
/*<!M><%braceright><~nbthinspace>                                  */ DEADTRANS( 0x202F	,0x0273	,0x02FE	,0x0000), // ' ' ➔ "˾" U+02FE MODIFIER LETTER OPEN SHELF
/*<!M><%braceright><~space>                                        */ DEADTRANS( L' '	,0x0273	,0x0322	,0x0000), // ' ' ➔ "̢" U+0322 COMBINING RETROFLEX HOOK BELOW
/*<!M><%braceright><~spacezerowidth>                               */ DEADTRANS( 0x200B	,0x0273	,0x0322	,0x0000), // '​' ➔ "̢" U+0322 COMBINING RETROFLEX HOOK BELOW
/*<!M><%bracketleft><%aprightsingquotmark>                         */ DEADTRANS( 0x2019	,0x01EB	,0x1DCE	,0x0000), // '’' ➔ "᷎" U+1DCE COMBINING OGONEK ABOVE
/*<!M><%bracketleft><0>                                            */ DEADTRANS( L'0'	,0x01EB	,0x2789	,0x0000), // '0' ➔ "➉" U+2789 DINGBAT CIRCLED SANS-SERIF NUMBER TEN
/*<!M><%bracketleft><1>                                            */ DEADTRANS( L'1'	,0x01EB	,0x2780	,0x0000), // '1' ➔ "➀" U+2780 DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*<!M><%bracketleft><2>                                            */ DEADTRANS( L'2'	,0x01EB	,0x2781	,0x0000), // '2' ➔ "➁" U+2781 DINGBAT CIRCLED SANS-SERIF DIGIT TWO
/*<!M><%bracketleft><3>                                            */ DEADTRANS( L'3'	,0x01EB	,0x2782	,0x0000), // '3' ➔ "➂" U+2782 DINGBAT CIRCLED SANS-SERIF DIGIT THREE
/*<!M><%bracketleft><4>                                            */ DEADTRANS( L'4'	,0x01EB	,0x2783	,0x0000), // '4' ➔ "➃" U+2783 DINGBAT CIRCLED SANS-SERIF DIGIT FOUR
/*<!M><%bracketleft><5>                                            */ DEADTRANS( L'5'	,0x01EB	,0x2784	,0x0000), // '5' ➔ "➄" U+2784 DINGBAT CIRCLED SANS-SERIF DIGIT FIVE
/*<!M><%bracketleft><6>                                            */ DEADTRANS( L'6'	,0x01EB	,0x2785	,0x0000), // '6' ➔ "➅" U+2785 DINGBAT CIRCLED SANS-SERIF DIGIT SIX
/*<!M><%bracketleft><7>                                            */ DEADTRANS( L'7'	,0x01EB	,0x2786	,0x0000), // '7' ➔ "➆" U+2786 DINGBAT CIRCLED SANS-SERIF DIGIT SEVEN
/*<!M><%bracketleft><8>                                            */ DEADTRANS( L'8'	,0x01EB	,0x2787	,0x0000), // '8' ➔ "➇" U+2787 DINGBAT CIRCLED SANS-SERIF DIGIT EIGHT
/*<!M><%bracketleft><9>                                            */ DEADTRANS( L'9'	,0x01EB	,0x2788	,0x0000), // '9' ➔ "➈" U+2788 DINGBAT CIRCLED SANS-SERIF DIGIT NINE
/*<!M><%bracketleft><A>                                            */ DEADTRANS( L'A'	,0x01EB	,0x0104	,0x0000), // 'A' ➔ "Ą" U+0104 LATIN CAPITAL LETTER A WITH OGONEK
/*<!M><%bracketleft><a>                                            */ DEADTRANS( L'a'	,0x01EB	,0x0105	,0x0000), // 'a' ➔ "ą" U+0105 LATIN SMALL LETTER A WITH OGONEK
/*<!M><%bracketleft><E>                                            */ DEADTRANS( L'E'	,0x01EB	,0x0118	,0x0000), // 'E' ➔ "Ę" U+0118 LATIN CAPITAL LETTER E WITH OGONEK
/*<!M><%bracketleft><e>                                            */ DEADTRANS( L'e'	,0x01EB	,0x0119	,0x0000), // 'e' ➔ "ę" U+0119 LATIN SMALL LETTER E WITH OGONEK
/*<!M><%bracketleft><I>                                            */ DEADTRANS( L'I'	,0x01EB	,0x012E	,0x0000), // 'I' ➔ "Į" U+012E LATIN CAPITAL LETTER I WITH OGONEK
/*<!M><%bracketleft><i>                                            */ DEADTRANS( L'i'	,0x01EB	,0x012F	,0x0000), // 'i' ➔ "į" U+012F LATIN SMALL LETTER I WITH OGONEK
/*<!M><%bracketleft><O>                                            */ DEADTRANS( L'O'	,0x01EB	,0x01EA	,0x0000), // 'O' ➔ "Ǫ" U+01EA LATIN CAPITAL LETTER O WITH OGONEK
/*<!M><%bracketleft><o>                                            */ DEADTRANS( L'o'	,0x01EB	,0x01EB	,0x0000), // 'o' ➔ "ǫ" U+01EB LATIN SMALL LETTER O WITH OGONEK
/*<!M><%bracketleft><U>                                            */ DEADTRANS( L'U'	,0x01EB	,0x0172	,0x0000), // 'U' ➔ "Ų" U+0172 LATIN CAPITAL LETTER U WITH OGONEK
/*<!M><%bracketleft><u>                                            */ DEADTRANS( L'u'	,0x01EB	,0x0173	,0x0000), // 'u' ➔ "ų" U+0173 LATIN SMALL LETTER U WITH OGONEK
/*<!M><%bracketleft><~nbspace>                                     */ DEADTRANS( 0x00A0	,0x01EB	,0x02DB	,0x0000), // ' ' ➔ "˛" U+02DB OGONEK
/*<!M><%bracketleft><~nbthinspace>                                 */ DEADTRANS( 0x202F	,0x01EB	,0x02DB	,0x0000), // ' ' ➔ "˛" U+02DB OGONEK
/*<!M><%bracketleft><~space>                                       */ DEADTRANS( L' '	,0x01EB	,0x0328	,0x0000), // ' ' ➔ "̨" U+0328 COMBINING OGONEK
/*<!M><%bracketleft><~spacezerowidth>                              */ DEADTRANS( 0x200B	,0x01EB	,0x0328	,0x0000), // '​' ➔ "̨" U+0328 COMBINING OGONEK
/*<!M><%bracketright><0>                                           */ DEADTRANS( L'0'	,0x1EBB	,0x2793	,0x0000), // '0' ➔ "➓" U+2793 DINGBAT NEGATIVE CIRCLED SANS-SERIF NUMBER TEN
/*<!M><%bracketright><1>                                           */ DEADTRANS( L'1'	,0x1EBB	,0x278A	,0x0000), // '1' ➔ "➊" U+278A DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*<!M><%bracketright><2>                                           */ DEADTRANS( L'2'	,0x1EBB	,0x278B	,0x0000), // '2' ➔ "➋" U+278B DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT TWO
/*<!M><%bracketright><3>                                           */ DEADTRANS( L'3'	,0x1EBB	,0x278C	,0x0000), // '3' ➔ "➌" U+278C DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT THREE
/*<!M><%bracketright><4>                                           */ DEADTRANS( L'4'	,0x1EBB	,0x278D	,0x0000), // '4' ➔ "➍" U+278D DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FOUR
/*<!M><%bracketright><5>                                           */ DEADTRANS( L'5'	,0x1EBB	,0x278E	,0x0000), // '5' ➔ "➎" U+278E DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FIVE
/*<!M><%bracketright><6>                                           */ DEADTRANS( L'6'	,0x1EBB	,0x278F	,0x0000), // '6' ➔ "➏" U+278F DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SIX
/*<!M><%bracketright><7>                                           */ DEADTRANS( L'7'	,0x1EBB	,0x2790	,0x0000), // '7' ➔ "➐" U+2790 DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SEVEN
/*<!M><%bracketright><8>                                           */ DEADTRANS( L'8'	,0x1EBB	,0x2791	,0x0000), // '8' ➔ "➑" U+2791 DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT EIGHT
/*<!M><%bracketright><9>                                           */ DEADTRANS( L'9'	,0x1EBB	,0x2792	,0x0000), // '9' ➔ "➒" U+2792 DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT NINE
/*<!M><%bracketright><A>                                           */ DEADTRANS( L'A'	,0x1EBB	,0x1EA2	,0x0000), // 'A' ➔ "Ả" U+1EA2 LATIN CAPITAL LETTER A WITH HOOK ABOVE
/*<!M><%bracketright><a>                                           */ DEADTRANS( L'a'	,0x1EBB	,0x1EA3	,0x0000), // 'a' ➔ "ả" U+1EA3 LATIN SMALL LETTER A WITH HOOK ABOVE
/*<!M><%bracketright><E>                                           */ DEADTRANS( L'E'	,0x1EBB	,0x1EBA	,0x0000), // 'E' ➔ "Ẻ" U+1EBA LATIN CAPITAL LETTER E WITH HOOK ABOVE
/*<!M><%bracketright><e>                                           */ DEADTRANS( L'e'	,0x1EBB	,0x1EBB	,0x0000), // 'e' ➔ "ẻ" U+1EBB LATIN SMALL LETTER E WITH HOOK ABOVE
/*<!M><%bracketright><I>                                           */ DEADTRANS( L'I'	,0x1EBB	,0x1EC8	,0x0000), // 'I' ➔ "Ỉ" U+1EC8 LATIN CAPITAL LETTER I WITH HOOK ABOVE
/*<!M><%bracketright><i>                                           */ DEADTRANS( L'i'	,0x1EBB	,0x1EC9	,0x0000), // 'i' ➔ "ỉ" U+1EC9 LATIN SMALL LETTER I WITH HOOK ABOVE
/*<!M><%bracketright><O>                                           */ DEADTRANS( L'O'	,0x1EBB	,0x1ECE	,0x0000), // 'O' ➔ "Ỏ" U+1ECE LATIN CAPITAL LETTER O WITH HOOK ABOVE
/*<!M><%bracketright><o>                                           */ DEADTRANS( L'o'	,0x1EBB	,0x1ECF	,0x0000), // 'o' ➔ "ỏ" U+1ECF LATIN SMALL LETTER O WITH HOOK ABOVE
/*<!M><%bracketright><U>                                           */ DEADTRANS( L'U'	,0x1EBB	,0x1EE6	,0x0000), // 'U' ➔ "Ủ" U+1EE6 LATIN CAPITAL LETTER U WITH HOOK ABOVE
/*<!M><%bracketright><u>                                           */ DEADTRANS( L'u'	,0x1EBB	,0x1EE7	,0x0000), // 'u' ➔ "ủ" U+1EE7 LATIN SMALL LETTER U WITH HOOK ABOVE
/*<!M><%bracketright><Y>                                           */ DEADTRANS( L'Y'	,0x1EBB	,0x1EF6	,0x0000), // 'Y' ➔ "Ỷ" U+1EF6 LATIN CAPITAL LETTER Y WITH HOOK ABOVE
/*<!M><%bracketright><y>                                           */ DEADTRANS( L'y'	,0x1EBB	,0x1EF7	,0x0000), // 'y' ➔ "ỷ" U+1EF7 LATIN SMALL LETTER Y WITH HOOK ABOVE
/*<!M><%bracketright><~nbspace>                                    */ DEADTRANS( 0x00A0	,0x1EBB	,0x02BE	,0x0000), // ' ' ➔ "ʾ" U+02BE MODIFIER LETTER RIGHT HALF RING
/*<!M><%bracketright><~nbthinspace>                                */ DEADTRANS( 0x202F	,0x1EBB	,0x02BF	,0x0000), // ' ' ➔ "ʿ" U+02BF MODIFIER LETTER LEFT HALF RING
/*<!M><%bracketright><~space>                                      */ DEADTRANS( L' '	,0x1EBB	,0x0309	,0x0000), // ' ' ➔ "̉" U+0309 COMBINING HOOK ABOVE
/*<!M><%bracketright><~spacezerowidth>                             */ DEADTRANS( 0x200B	,0x1EBB	,0x0309	,0x0000), // '​' ➔ "̉" U+0309 COMBINING HOOK ABOVE
/*<!M><%circum><%apostrophe>                                       */ DEADTRANS( L'\''	,0x005E	,0x02C8	,0x0000), // ''' ➔ "ˈ" U+02C8 MODIFIER LETTER VERTICAL LINE
/*<!M><%circum><%aprightsingquotmark>                              */ DEADTRANS( 0x2019	,0x005E	,0x02C8	,0x0000), // '’' ➔ "ˈ" U+02C8 MODIFIER LETTER VERTICAL LINE
/*<!M><%circum><%asterisk>                                         */ DEADTRANS( L'*'	,0x005E	,0x2042	,0x0000), // '*' ➔ "⁂" U+2042 ASTERISM
/*<!M><%circum><%comma>                                            */ DEADTRANS( L','	,0x005E	,0x1DD7	,0x0000), // ',' ➔ "ᷗ" U+1DD7 COMBINING LATIN SMALL LETTER C CEDILLA
/*<!M><%circum><%equal>                                            */ DEADTRANS( L'='	,0x005E	,0x207C	,0x0000), // '=' ➔ "⁼" U+207C SUPERSCRIPT EQUALS SIGN
/*<!M><%circum><%exclam>                                           */ DEADTRANS( L'!'	,0x005E	,0xA71D	,0x0000), // '!' ➔ "ꜝ" U+A71D MODIFIER LETTER RAISED EXCLAMATION MARK
/*<!M><%circum><%greater>                                          */ DEADTRANS( L'>'	,0x005E	,0xA71C	,0x0000), // '>' ➔ "ꜜ" U+A71C MODIFIER LETTER RAISED DOWN ARROW
/*<!M><%circum><%less>                                             */ DEADTRANS( L'<'	,0x005E	,0xA71B	,0x0000), // '<' ➔ "ꜛ" U+A71B MODIFIER LETTER RAISED UP ARROW
/*<!M><%circum><%parenleft>                                        */ DEADTRANS( L'('	,0x005E	,0x207D	,0x0000), // '(' ➔ "⁽" U+207D SUPERSCRIPT LEFT PARENTHESIS
/*<!M><%circum><%period>                                           */ DEADTRANS( L'.'	,0x005E	,0x00B7	,0x0000), // '.' ➔ "·" U+00B7 MIDDLE DOT
/*<!M><%circum><%quotedbl>                                         */ DEADTRANS( L'"'	,0x005E	,0x02EE	,0x0000), // '"' ➔ "ˮ" U+02EE MODIFIER LETTER DOUBLE APOSTROPHE
/*<!M><%circum><%quotEuroSign>                                     */ DEADTRANS( 0x20AC	,0x005E	,0x02EE	,0x0000), // '€' ➔ "ˮ" U+02EE MODIFIER LETTER DOUBLE APOSTROPHE
/*<!M><%circum><%slash>                                            */ DEADTRANS( L'/'	,0x005E	,0xDFA2	,0x0000), // High surrogate: D801; '/' ➔ "𐞢" U+107A2 MODIFIER LETTER SMALL O WITH STROKE
/*<!M><%circum><0>                                                 */ DEADTRANS( L'0'	,0x005E	,0x2070	,0x0000), // '0' ➔ "⁰" U+2070 SUPERSCRIPT ZERO
/*<!M><%circum><1>                                                 */ DEADTRANS( L'1'	,0x005E	,0x00B9	,0x0000), // '1' ➔ "¹" U+00B9 SUPERSCRIPT ONE
/*<!M><%circum><2>                                                 */ DEADTRANS( L'2'	,0x005E	,0x00B2	,0x0000), // '2' ➔ "²" U+00B2 SUPERSCRIPT TWO
/*<!M><%circum><3>                                                 */ DEADTRANS( L'3'	,0x005E	,0x00B3	,0x0000), // '3' ➔ "³" U+00B3 SUPERSCRIPT THREE
/*<!M><%circum><4>                                                 */ DEADTRANS( L'4'	,0x005E	,0x2074	,0x0000), // '4' ➔ "⁴" U+2074 SUPERSCRIPT FOUR
/*<!M><%circum><5>                                                 */ DEADTRANS( L'5'	,0x005E	,0x2075	,0x0000), // '5' ➔ "⁵" U+2075 SUPERSCRIPT FIVE
/*<!M><%circum><6>                                                 */ DEADTRANS( L'6'	,0x005E	,0x2076	,0x0000), // '6' ➔ "⁶" U+2076 SUPERSCRIPT SIX
/*<!M><%circum><7>                                                 */ DEADTRANS( L'7'	,0x005E	,0x2077	,0x0000), // '7' ➔ "⁷" U+2077 SUPERSCRIPT SEVEN
/*<!M><%circum><8>                                                 */ DEADTRANS( L'8'	,0x005E	,0x2078	,0x0000), // '8' ➔ "⁸" U+2078 SUPERSCRIPT EIGHT
/*<!M><%circum><9>                                                 */ DEADTRANS( L'9'	,0x005E	,0x2079	,0x0000), // '9' ➔ "⁹" U+2079 SUPERSCRIPT NINE
/*<!M><%circum><A>                                                 */ DEADTRANS( L'A'	,0x005E	,0x1D2C	,0x0000), // 'A' ➔ "ᴬ" U+1D2C MODIFIER LETTER CAPITAL A
/*<!M><%circum><a>                                                 */ DEADTRANS( L'a'	,0x005E	,0x1D43	,0x0000), // 'a' ➔ "ᵃ" U+1D43 MODIFIER LETTER SMALL A
/*<!M><%circum><B>                                                 */ DEADTRANS( L'B'	,0x005E	,0x1D2E	,0x0000), // 'B' ➔ "ᴮ" U+1D2E MODIFIER LETTER CAPITAL B
/*<!M><%circum><b>                                                 */ DEADTRANS( L'b'	,0x005E	,0x1D47	,0x0000), // 'b' ➔ "ᵇ" U+1D47 MODIFIER LETTER SMALL B
/*<!M><%circum><c>                                                 */ DEADTRANS( L'c'	,0x005E	,0x1D9C	,0x0000), // 'c' ➔ "ᶜ" U+1D9C MODIFIER LETTER SMALL C
/*<!M><%circum><C>                                                 */ DEADTRANS( L'C'	,0x005E	,0xA7F2	,0x0000), // 'C' ➔ "ꟲ" U+A7F2 MODIFIER LETTER CAPITAL C: Chatino (Oaxaca, Mexico)
/*<!M><%circum><D>                                                 */ DEADTRANS( L'D'	,0x005E	,0x1D30	,0x0000), // 'D' ➔ "ᴰ" U+1D30 MODIFIER LETTER CAPITAL D
/*<!M><%circum><d>                                                 */ DEADTRANS( L'd'	,0x005E	,0x1D48	,0x0000), // 'd' ➔ "ᵈ" U+1D48 MODIFIER LETTER SMALL D
/*<!M><%circum><E>                                                 */ DEADTRANS( L'E'	,0x005E	,0x1D31	,0x0000), // 'E' ➔ "ᴱ" U+1D31 MODIFIER LETTER CAPITAL E
/*<!M><%circum><e>                                                 */ DEADTRANS( L'e'	,0x005E	,0x1D49	,0x0000), // 'e' ➔ "ᵉ" U+1D49 MODIFIER LETTER SMALL E
/*<!M><%circum><f>                                                 */ DEADTRANS( L'f'	,0x005E	,0x1DA0	,0x0000), // 'f' ➔ "ᶠ" U+1DA0 MODIFIER LETTER SMALL F
/*<!M><%circum><F>                                                 */ DEADTRANS( L'F'	,0x005E	,0xA7F3	,0x0000), // 'F' ➔ "ꟳ" U+A7F3 MODIFIER LETTER CAPITAL F: Chatino (Oaxaca, Mexico)
/*<!M><%circum><G>                                                 */ DEADTRANS( L'G'	,0x005E	,0x1D33	,0x0000), // 'G' ➔ "ᴳ" U+1D33 MODIFIER LETTER CAPITAL G
/*<!M><%circum><g>                                                 */ DEADTRANS( L'g'	,0x005E	,0x1D4D	,0x0000), // 'g' ➔ "ᵍ" U+1D4D MODIFIER LETTER SMALL G
/*<!M><%circum><h>                                                 */ DEADTRANS( L'h'	,0x005E	,0x02B0	,0x0000), // 'h' ➔ "ʰ" U+02B0 MODIFIER LETTER SMALL H
/*<!M><%circum><H>                                                 */ DEADTRANS( L'H'	,0x005E	,0x1D34	,0x0000), // 'H' ➔ "ᴴ" U+1D34 MODIFIER LETTER CAPITAL H
/*<!M><%circum><I>                                                 */ DEADTRANS( L'I'	,0x005E	,0x1D35	,0x0000), // 'I' ➔ "ᴵ" U+1D35 MODIFIER LETTER CAPITAL I
/*<!M><%circum><i>                                                 */ DEADTRANS( L'i'	,0x005E	,0x2071	,0x0000), // 'i' ➔ "ⁱ" U+2071 SUPERSCRIPT LATIN SMALL LETTER I
/*<!M><%circum><j>                                                 */ DEADTRANS( L'j'	,0x005E	,0x02B2	,0x0000), // 'j' ➔ "ʲ" U+02B2 MODIFIER LETTER SMALL J
/*<!M><%circum><J>                                                 */ DEADTRANS( L'J'	,0x005E	,0x1D36	,0x0000), // 'J' ➔ "ᴶ" U+1D36 MODIFIER LETTER CAPITAL J
/*<!M><%circum><K>                                                 */ DEADTRANS( L'K'	,0x005E	,0x1D37	,0x0000), // 'K' ➔ "ᴷ" U+1D37 MODIFIER LETTER CAPITAL K
/*<!M><%circum><k>                                                 */ DEADTRANS( L'k'	,0x005E	,0x1D4F	,0x0000), // 'k' ➔ "ᵏ" U+1D4F MODIFIER LETTER SMALL K
/*<!M><%circum><l>                                                 */ DEADTRANS( L'l'	,0x005E	,0x02E1	,0x0000), // 'l' ➔ "ˡ" U+02E1 MODIFIER LETTER SMALL L
/*<!M><%circum><L>                                                 */ DEADTRANS( L'L'	,0x005E	,0x1D38	,0x0000), // 'L' ➔ "ᴸ" U+1D38 MODIFIER LETTER CAPITAL L
/*<!M><%circum><M>                                                 */ DEADTRANS( L'M'	,0x005E	,0x1D39	,0x0000), // 'M' ➔ "ᴹ" U+1D39 MODIFIER LETTER CAPITAL M
/*<!M><%circum><m>                                                 */ DEADTRANS( L'm'	,0x005E	,0x1D50	,0x0000), // 'm' ➔ "ᵐ" U+1D50 MODIFIER LETTER SMALL M
/*<!M><%circum><multiply>                                          */ DEADTRANS( 0x00D7	,0x005E	,0x033D	,0x0000), // '×' ➔ "̽" U+033D COMBINING X ABOVE
/*<!M><%circum><N>                                                 */ DEADTRANS( L'N'	,0x005E	,0x1D3A	,0x0000), // 'N' ➔ "ᴺ" U+1D3A MODIFIER LETTER CAPITAL N
/*<!M><%circum><n>                                                 */ DEADTRANS( L'n'	,0x005E	,0x207F	,0x0000), // 'n' ➔ "ⁿ" U+207F SUPERSCRIPT LATIN SMALL LETTER N
/*<!M><%circum><O>                                                 */ DEADTRANS( L'O'	,0x005E	,0x1D3C	,0x0000), // 'O' ➔ "ᴼ" U+1D3C MODIFIER LETTER CAPITAL O
/*<!M><%circum><o>                                                 */ DEADTRANS( L'o'	,0x005E	,0x1D52	,0x0000), // 'o' ➔ "ᵒ" U+1D52 MODIFIER LETTER SMALL O
/*<!M><%circum><P>                                                 */ DEADTRANS( L'P'	,0x005E	,0x1D3E	,0x0000), // 'P' ➔ "ᴾ" U+1D3E MODIFIER LETTER CAPITAL P
/*<!M><%circum><p>                                                 */ DEADTRANS( L'p'	,0x005E	,0x1D56	,0x0000), // 'p' ➔ "ᵖ" U+1D56 MODIFIER LETTER SMALL P
/*<!M><%circum><Q>                                                 */ DEADTRANS( L'Q'	,0x005E	,0xA7F4	,0x0000), // 'Q' ➔ "ꟴ" U+A7F4 MODIFIER LETTER CAPITAL Q
/*<!M><%circum><q>                                                 */ DEADTRANS( L'q'	,0x005E	,0xDFA5	,0x0000), // High surrogate: D801; 'q' ➔ "𐞥" U+107A5 MODIFIER LETTER SMALL Q
/*<!M><%circum><r>                                                 */ DEADTRANS( L'r'	,0x005E	,0x02B3	,0x0000), // 'r' ➔ "ʳ" U+02B3 MODIFIER LETTER SMALL R
/*<!M><%circum><R>                                                 */ DEADTRANS( L'R'	,0x005E	,0x1D3F	,0x0000), // 'R' ➔ "ᴿ" U+1D3F MODIFIER LETTER CAPITAL R
/*<!M><%circum><s>                                                 */ DEADTRANS( L's'	,0x005E	,0x02E2	,0x0000), // 's' ➔ "ˢ" U+02E2 MODIFIER LETTER SMALL S
/*<!M><%circum><S>                                                 */ DEADTRANS( L'S'	,0x005E	,0xA7F1	,0x0000), // 'S' ➔ "꟱" U+A7F1 MODIFIER LETTER CAPITAL S
/*<!M><%circum><T>                                                 */ DEADTRANS( L'T'	,0x005E	,0x1D40	,0x0000), // 'T' ➔ "ᵀ" U+1D40 MODIFIER LETTER CAPITAL T
/*<!M><%circum><t>                                                 */ DEADTRANS( L't'	,0x005E	,0x1D57	,0x0000), // 't' ➔ "ᵗ" U+1D57 MODIFIER LETTER SMALL T
/*<!M><%circum><U>                                                 */ DEADTRANS( L'U'	,0x005E	,0x1D41	,0x0000), // 'U' ➔ "ᵁ" U+1D41 MODIFIER LETTER CAPITAL U
/*<!M><%circum><u>                                                 */ DEADTRANS( L'u'	,0x005E	,0x1D58	,0x0000), // 'u' ➔ "ᵘ" U+1D58 MODIFIER LETTER SMALL U
/*<!M><%circum><v>                                                 */ DEADTRANS( L'v'	,0x005E	,0x1D5B	,0x0000), // 'v' ➔ "ᵛ" U+1D5B MODIFIER LETTER SMALL V
/*<!M><%circum><V>                                                 */ DEADTRANS( L'V'	,0x005E	,0x2C7D	,0x0000), // 'V' ➔ "ⱽ" U+2C7D MODIFIER LETTER CAPITAL V
/*<!M><%circum><w>                                                 */ DEADTRANS( L'w'	,0x005E	,0x02B7	,0x0000), // 'w' ➔ "ʷ" U+02B7 MODIFIER LETTER SMALL W
/*<!M><%circum><W>                                                 */ DEADTRANS( L'W'	,0x005E	,0x1D42	,0x0000), // 'W' ➔ "ᵂ" U+1D42 MODIFIER LETTER CAPITAL W
/*<!M><%circum><x>                                                 */ DEADTRANS( L'x'	,0x005E	,0x02E3	,0x0000), // 'x' ➔ "ˣ" U+02E3 MODIFIER LETTER SMALL X
/*<!M><%circum><X>                                                 */ DEADTRANS( L'X'	,0x005E	,0x2204	,0x0000), // 'X' ➔ "∄" U+2204 THERE DOES NOT EXIST
/*<!M><%circum><y>                                                 */ DEADTRANS( L'y'	,0x005E	,0x02B8	,0x0000), // 'y' ➔ "ʸ" U+02B8 MODIFIER LETTER SMALL Y
/*<!M><%circum><Y>                                                 */ DEADTRANS( L'Y'	,0x005E	,0x2204	,0x0000), // 'Y' ➔ "∄" U+2204 THERE DOES NOT EXIST
/*<!M><%circum><z>                                                 */ DEADTRANS( L'z'	,0x005E	,0x1DBB	,0x0000), // 'z' ➔ "ᶻ" U+1DBB MODIFIER LETTER SMALL Z
/*<!M><%circum><Z>                                                 */ DEADTRANS( L'Z'	,0x005E	,0x2204	,0x0000), // 'Z' ➔ "∄" U+2204 THERE DOES NOT EXIST
/*<!M><%circum><~nbspace>                                          */ DEADTRANS( 0x00A0	,0x005E	,0x203E	,0x0000), // ' ' ➔ "‾" U+203E OVERLINE
/*<!M><%circum><~nbthinspace>                                      */ DEADTRANS( 0x202F	,0x005E	,0x203E	,0x0000), // ' ' ➔ "‾" U+203E OVERLINE
/*<!M><%circum><~space>                                            */ DEADTRANS( L' '	,0x005E	,0x0305	,0x0000), // ' ' ➔ "̅" U+0305 COMBINING OVERLINE
/*<!M><%circum><~spacezerowidth>                                   */ DEADTRANS( 0x200B	,0x005E	,0x0305	,0x0000), // '​' ➔ "̅" U+0305 COMBINING OVERLINE
/*<!M><%colon><%aprightsingquotmark>                               */ DEADTRANS( 0x2019	,0x00EB	,0x201A	,0x0000), // '’' ➔ "‚" U+201A SINGLE LOW-9 QUOTATION MARK, low single comma quotation mark
/*<!M><%colon><%backslash>                                         */ DEADTRANS( L'\\'	,0x00EB	,0x00A6	,0x0000), // '\' ➔ "¦" U+00A6 BROKEN BAR repurposed as multikey symbol
/*<!M><%colon><%slash>                                             */ DEADTRANS( L'/'	,0x00EB	,0x2016	,0x0000), // '/' ➔ "‖" U+2016 DOUBLE VERTICAL LINE
/*<!M><%colon><0>                                                  */ DEADTRANS( L'0'	,0x00EB	,0x2070	,0x0000), // '0' ➔ "⁰" U+2070 SUPERSCRIPT ZERO
/*<!M><%colon><1>                                                  */ DEADTRANS( L'1'	,0x00EB	,0x00B9	,0x0000), // '1' ➔ "¹" U+00B9 SUPERSCRIPT ONE
/*<!M><%colon><2>                                                  */ DEADTRANS( L'2'	,0x00EB	,0x00B2	,0x0000), // '2' ➔ "²" U+00B2 SUPERSCRIPT TWO
/*<!M><%colon><3>                                                  */ DEADTRANS( L'3'	,0x00EB	,0x00B3	,0x0000), // '3' ➔ "³" U+00B3 SUPERSCRIPT THREE
/*<!M><%colon><4>                                                  */ DEADTRANS( L'4'	,0x00EB	,0x2074	,0x0000), // '4' ➔ "⁴" U+2074 SUPERSCRIPT FOUR
/*<!M><%colon><5>                                                  */ DEADTRANS( L'5'	,0x00EB	,0x2075	,0x0000), // '5' ➔ "⁵" U+2075 SUPERSCRIPT FIVE
/*<!M><%colon><6>                                                  */ DEADTRANS( L'6'	,0x00EB	,0x2076	,0x0000), // '6' ➔ "⁶" U+2076 SUPERSCRIPT SIX
/*<!M><%colon><7>                                                  */ DEADTRANS( L'7'	,0x00EB	,0x2077	,0x0000), // '7' ➔ "⁷" U+2077 SUPERSCRIPT SEVEN
/*<!M><%colon><8>                                                  */ DEADTRANS( L'8'	,0x00EB	,0x2078	,0x0000), // '8' ➔ "⁸" U+2078 SUPERSCRIPT EIGHT
/*<!M><%colon><9>                                                  */ DEADTRANS( L'9'	,0x00EB	,0x2079	,0x0000), // '9' ➔ "⁹" U+2079 SUPERSCRIPT NINE
/*<!M><%colon><A>                                                  */ DEADTRANS( L'A'	,0x00EB	,0x00C4	,0x0000), // 'A' ➔ "Ä" U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS
/*<!M><%colon><a>                                                  */ DEADTRANS( L'a'	,0x00EB	,0x00E4	,0x0000), // 'a' ➔ "ä" U+00E4 LATIN SMALL LETTER A WITH DIAERESIS
/*<!M><%colon><Ccedilla>                                           */ DEADTRANS( 0x00C7	,0x00EB	,0x00D8	,0x0000), // 'Ç' ➔ "Ø" U+00D8 LATIN CAPITAL LETTER O WITH STROKE
/*<!M><%colon><ccedilla>                                           */ DEADTRANS( 0x00E7	,0x00EB	,0x00F8	,0x0000), // 'ç' ➔ "ø" U+00F8 LATIN SMALL LETTER O WITH STROKE
/*<!M><%colon><E>                                                  */ DEADTRANS( L'E'	,0x00EB	,0x00CB	,0x0000), // 'E' ➔ "Ë" U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS
/*<!M><%colon><e>                                                  */ DEADTRANS( L'e'	,0x00EB	,0x00EB	,0x0000), // 'e' ➔ "ë" U+00EB LATIN SMALL LETTER E WITH DIAERESIS
/*<!M><%colon><emdash>                                             */ DEADTRANS( 0x2014	,0x00EB	,0x2E3B	,0x0000), // '—' ➔ "⸻" U+2E3B THREE-EM DASH
/*<!M><%colon><endash>                                             */ DEADTRANS( 0x2013	,0x00EB	,0x2E3A	,0x0000), // '–' ➔ "⸺" U+2E3A TWO-EM DASH
/*<!M><%colon><H>                                                  */ DEADTRANS( L'H'	,0x00EB	,0x1E26	,0x0000), // 'H' ➔ "Ḧ" U+1E26 LATIN CAPITAL LETTER H WITH DIAERESIS
/*<!M><%colon><h>                                                  */ DEADTRANS( L'h'	,0x00EB	,0x1E27	,0x0000), // 'h' ➔ "ḧ" U+1E27 LATIN SMALL LETTER H WITH DIAERESIS
/*<!M><%colon><I>                                                  */ DEADTRANS( L'I'	,0x00EB	,0x00CF	,0x0000), // 'I' ➔ "Ï" U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS
/*<!M><%colon><i>                                                  */ DEADTRANS( L'i'	,0x00EB	,0x00EF	,0x0000), // 'i' ➔ "ï" U+00EF LATIN SMALL LETTER I WITH DIAERESIS
/*<!M><%colon><O>                                                  */ DEADTRANS( L'O'	,0x00EB	,0x00D6	,0x0000), // 'O' ➔ "Ö" U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS
/*<!M><%colon><o>                                                  */ DEADTRANS( L'o'	,0x00EB	,0x00F6	,0x0000), // 'o' ➔ "ö" U+00F6 LATIN SMALL LETTER O WITH DIAERESIS
/*<!M><%colon><periodcentered>                                     */ DEADTRANS( 0x00B7	,0x00EB	,0x00A6	,0x0000), // '·' ➔ "¦" U+00A6 BROKEN BAR repurposed as multikey symbol
/*<!M><%colon><s>                                                  */ DEADTRANS( L's'	,0x00EB	,0x017F	,0x0000), // 's' ➔ "ſ" U+017F LATIN SMALL LETTER LONG S
/*<!M><%colon><t>                                                  */ DEADTRANS( L't'	,0x00EB	,0x1E97	,0x0000), // 't' ➔ "ẗ" U+1E97 LATIN SMALL LETTER T WITH DIAERESIS
/*<!M><%colon><U>                                                  */ DEADTRANS( L'U'	,0x00EB	,0x00DC	,0x0000), // 'U' ➔ "Ü" U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS
/*<!M><%colon><u>                                                  */ DEADTRANS( L'u'	,0x00EB	,0x00FC	,0x0000), // 'u' ➔ "ü" U+00FC LATIN SMALL LETTER U WITH DIAERESIS
/*<!M><%colon><Ugrave>                                             */ DEADTRANS( 0x00D9	,0x00EB	,0x01DB	,0x0000), // 'Ù' ➔ "Ǜ" U+01DB LATIN CAPITAL LETTER U WITH DIAERESIS AND GRAVE
/*<!M><%colon><ugrave>                                             */ DEADTRANS( 0x00F9	,0x00EB	,0x01DC	,0x0000), // 'ù' ➔ "ǜ" U+01DC LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*<!M><%colon><W>                                                  */ DEADTRANS( L'W'	,0x00EB	,0x1E84	,0x0000), // 'W' ➔ "Ẅ" U+1E84 LATIN CAPITAL LETTER W WITH DIAERESIS
/*<!M><%colon><w>                                                  */ DEADTRANS( L'w'	,0x00EB	,0x1E85	,0x0000), // 'w' ➔ "ẅ" U+1E85 LATIN SMALL LETTER W WITH DIAERESIS
/*<!M><%colon><X>                                                  */ DEADTRANS( L'X'	,0x00EB	,0x1E8C	,0x0000), // 'X' ➔ "Ẍ" U+1E8C LATIN CAPITAL LETTER X WITH DIAERESIS
/*<!M><%colon><x>                                                  */ DEADTRANS( L'x'	,0x00EB	,0x1E8D	,0x0000), // 'x' ➔ "ẍ" U+1E8D LATIN SMALL LETTER X WITH DIAERESIS
/*<!M><%colon><y>                                                  */ DEADTRANS( L'y'	,0x00EB	,0x00FF	,0x0000), // 'y' ➔ "ÿ" U+00FF LATIN SMALL LETTER Y WITH DIAERESIS
/*<!M><%colon><Y>                                                  */ DEADTRANS( L'Y'	,0x00EB	,0x0178	,0x0000), // 'Y' ➔ "Ÿ" U+0178 LATIN CAPITAL LETTER Y WITH DIAERESIS
/*<!M><%colon><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x00EB	,0x00A8	,0x0000), // ' ' ➔ "¨" U+00A8 DIAERESIS
/*<!M><%colon><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x00EB	,0x00A8	,0x0000), // ' ' ➔ "¨" U+00A8 DIAERESIS
/*<!M><%colon><~space>                                             */ DEADTRANS( L' '	,0x00EB	,0x0308	,0x0000), // ' ' ➔ "̈" U+0308 COMBINING DIAERESIS
/*<!M><%colon><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x00EB	,0x0308	,0x0000), // '​' ➔ "̈" U+0308 COMBINING DIAERESIS
/*<!M><%comma><%circum>                                            */ DEADTRANS( L'^'	,0x00E7	,0x1DD7	,0x0000), // '^' ➔ "ᷗ" U+1DD7 COMBINING LATIN SMALL LETTER C CEDILLA
/*<!M><%comma><0>                                                  */ DEADTRANS( L'0'	,0x00E7	,0x2491	,0x0000), // '0' ➔ "⒑" U+2491 NUMBER TEN FULL STOP
/*<!M><%comma><1>                                                  */ DEADTRANS( L'1'	,0x00E7	,0x2488	,0x0000), // '1' ➔ "⒈" U+2488 DIGIT ONE FULL STOP
/*<!M><%comma><2>                                                  */ DEADTRANS( L'2'	,0x00E7	,0x2489	,0x0000), // '2' ➔ "⒉" U+2489 DIGIT TWO FULL STOP
/*<!M><%comma><3>                                                  */ DEADTRANS( L'3'	,0x00E7	,0x248A	,0x0000), // '3' ➔ "⒊" U+248A DIGIT THREE FULL STOP
/*<!M><%comma><4>                                                  */ DEADTRANS( L'4'	,0x00E7	,0x248B	,0x0000), // '4' ➔ "⒋" U+248B DIGIT FOUR FULL STOP
/*<!M><%comma><5>                                                  */ DEADTRANS( L'5'	,0x00E7	,0x248C	,0x0000), // '5' ➔ "⒌" U+248C DIGIT FIVE FULL STOP
/*<!M><%comma><6>                                                  */ DEADTRANS( L'6'	,0x00E7	,0x248D	,0x0000), // '6' ➔ "⒍" U+248D DIGIT SIX FULL STOP
/*<!M><%comma><7>                                                  */ DEADTRANS( L'7'	,0x00E7	,0x248E	,0x0000), // '7' ➔ "⒎" U+248E DIGIT SEVEN FULL STOP
/*<!M><%comma><8>                                                  */ DEADTRANS( L'8'	,0x00E7	,0x248F	,0x0000), // '8' ➔ "⒏" U+248F DIGIT EIGHT FULL STOP
/*<!M><%comma><9>                                                  */ DEADTRANS( L'9'	,0x00E7	,0x2490	,0x0000), // '9' ➔ "⒐" U+2490 DIGIT NINE FULL STOP
/*<!M><%comma><C>                                                  */ DEADTRANS( L'C'	,0x00E7	,0x00C7	,0x0000), // 'C' ➔ "Ç" U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA
/*<!M><%comma><c>                                                  */ DEADTRANS( L'c'	,0x00E7	,0x00E7	,0x0000), // 'c' ➔ "ç" U+00E7 LATIN SMALL LETTER C WITH CEDILLA
/*<!M><%comma><D>                                                  */ DEADTRANS( L'D'	,0x00E7	,0x1E10	,0x0000), // 'D' ➔ "Ḑ" U+1E10 LATIN CAPITAL LETTER D WITH CEDILLA
/*<!M><%comma><d>                                                  */ DEADTRANS( L'd'	,0x00E7	,0x1E11	,0x0000), // 'd' ➔ "ḑ" U+1E11 LATIN SMALL LETTER D WITH CEDILLA
/*<!M><%comma><E>                                                  */ DEADTRANS( L'E'	,0x00E7	,0x0228	,0x0000), // 'E' ➔ "Ȩ" U+0228 LATIN CAPITAL LETTER E WITH CEDILLA
/*<!M><%comma><e>                                                  */ DEADTRANS( L'e'	,0x00E7	,0x0229	,0x0000), // 'e' ➔ "ȩ" U+0229 LATIN SMALL LETTER E WITH CEDILLA
/*<!M><%comma><G>                                                  */ DEADTRANS( L'G'	,0x00E7	,0x0122	,0x0000), // 'G' ➔ "Ģ" U+0122 LATIN CAPITAL LETTER G WITH CEDILLA
/*<!M><%comma><g>                                                  */ DEADTRANS( L'g'	,0x00E7	,0x0123	,0x0000), // 'g' ➔ "ģ" U+0123 LATIN SMALL LETTER G WITH CEDILLA
/*<!M><%comma><H>                                                  */ DEADTRANS( L'H'	,0x00E7	,0x1E28	,0x0000), // 'H' ➔ "Ḩ" U+1E28 LATIN CAPITAL LETTER H WITH CEDILLA
/*<!M><%comma><h>                                                  */ DEADTRANS( L'h'	,0x00E7	,0x1E29	,0x0000), // 'h' ➔ "ḩ" U+1E29 LATIN SMALL LETTER H WITH CEDILLA
/*<!M><%comma><K>                                                  */ DEADTRANS( L'K'	,0x00E7	,0x0136	,0x0000), // 'K' ➔ "Ķ" U+0136 LATIN CAPITAL LETTER K WITH CEDILLA
/*<!M><%comma><k>                                                  */ DEADTRANS( L'k'	,0x00E7	,0x0137	,0x0000), // 'k' ➔ "ķ" U+0137 LATIN SMALL LETTER K WITH CEDILLA
/*<!M><%comma><L>                                                  */ DEADTRANS( L'L'	,0x00E7	,0x013B	,0x0000), // 'L' ➔ "Ļ" U+013B LATIN CAPITAL LETTER L WITH CEDILLA
/*<!M><%comma><l>                                                  */ DEADTRANS( L'l'	,0x00E7	,0x013C	,0x0000), // 'l' ➔ "ļ" U+013C LATIN SMALL LETTER L WITH CEDILLA
/*<!M><%comma><N>                                                  */ DEADTRANS( L'N'	,0x00E7	,0x0145	,0x0000), // 'N' ➔ "Ņ" U+0145 LATIN CAPITAL LETTER N WITH CEDILLA
/*<!M><%comma><n>                                                  */ DEADTRANS( L'n'	,0x00E7	,0x0146	,0x0000), // 'n' ➔ "ņ" U+0146 LATIN SMALL LETTER N WITH CEDILLA
/*<!M><%comma><R>                                                  */ DEADTRANS( L'R'	,0x00E7	,0x0156	,0x0000), // 'R' ➔ "Ŗ" U+0156 LATIN CAPITAL LETTER R WITH CEDILLA
/*<!M><%comma><r>                                                  */ DEADTRANS( L'r'	,0x00E7	,0x0157	,0x0000), // 'r' ➔ "ŗ" U+0157 LATIN SMALL LETTER R WITH CEDILLA
/*<!M><%comma><S>                                                  */ DEADTRANS( L'S'	,0x00E7	,0x015E	,0x0000), // 'S' ➔ "Ş" U+015E LATIN CAPITAL LETTER S WITH CEDILLA
/*<!M><%comma><s>                                                  */ DEADTRANS( L's'	,0x00E7	,0x015F	,0x0000), // 's' ➔ "ş" U+015F LATIN SMALL LETTER S WITH CEDILLA
/*<!M><%comma><T>                                                  */ DEADTRANS( L'T'	,0x00E7	,0x0162	,0x0000), // 'T' ➔ "Ţ" U+0162 LATIN CAPITAL LETTER T WITH CEDILLA
/*<!M><%comma><t>                                                  */ DEADTRANS( L't'	,0x00E7	,0x0163	,0x0000), // 't' ➔ "ţ" U+0163 LATIN SMALL LETTER T WITH CEDILLA
/*<!M><%comma><x>                                                  */ DEADTRANS( L'x'	,0x00E7	,0xAB55	,0x0000), // 'x' ➔ "ꭕ" U+AB55 LATIN SMALL LETTER CHI WITH LOW LEFT SERIF
/*<!M><%comma><X>                                                  */ DEADTRANS( L'X'	,0x00E7	,0xAB59	,0x0000), // 'X' ➔ "ꭙ" U+AB59 LATIN SMALL LETTER X WITH LONG LEFT LEG WITH SERIF
/*<!M><%comma><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x00E7	,0x00B8	,0x0000), // ' ' ➔ "¸" U+00B8 CEDILLA
/*<!M><%comma><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x00E7	,0x00B8	,0x0000), // ' ' ➔ "¸" U+00B8 CEDILLA
/*<!M><%comma><~space>                                             */ DEADTRANS( L' '	,0x00E7	,0x0327	,0x0000), // ' ' ➔ "̧" U+0327 COMBINING CEDILLA
/*<!M><%comma><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x00E7	,0x0327	,0x0000), // '​' ➔ "̧" U+0327 COMBINING CEDILLA
/*<!M><%dollar><0>                                                 */ DEADTRANS( L'0'	,0x00A4	,0x2231	,0x0000), // '0' ➔ "∱" U+2231 CLOCKWISE INTEGRAL
/*<!M><%dollar><1>                                                 */ DEADTRANS( L'1'	,0x00A4	,0x222B	,0x0000), // '1' ➔ "∫" U+222B INTEGRAL
/*<!M><%dollar><2>                                                 */ DEADTRANS( L'2'	,0x00A4	,0x222C	,0x0000), // '2' ➔ "∬" U+222C DOUBLE INTEGRAL
/*<!M><%dollar><3>                                                 */ DEADTRANS( L'3'	,0x00A4	,0x222D	,0x0000), // '3' ➔ "∭" U+222D TRIPLE INTEGRAL
/*<!M><%dollar><4>                                                 */ DEADTRANS( L'4'	,0x00A4	,0x2A0C	,0x0000), // '4' ➔ "⨌" U+2A0C QUADRUPLE INTEGRAL OPERATOR
/*<!M><%dollar><5>                                                 */ DEADTRANS( L'5'	,0x00A4	,0x222E	,0x0000), // '5' ➔ "∮" U+222E CONTOUR INTEGRAL
/*<!M><%dollar><6>                                                 */ DEADTRANS( L'6'	,0x00A4	,0x222F	,0x0000), // '6' ➔ "∯" U+222F SURFACE INTEGRAL
/*<!M><%dollar><7>                                                 */ DEADTRANS( L'7'	,0x00A4	,0x2230	,0x0000), // '7' ➔ "∰" U+2230 VOLUME INTEGRAL
/*<!M><%dollar><8>                                                 */ DEADTRANS( L'8'	,0x00A4	,0x2232	,0x0000), // '8' ➔ "∲" U+2232 CLOCKWISE CONTOUR INTEGRAL
/*<!M><%dollar><9>                                                 */ DEADTRANS( L'9'	,0x00A4	,0x2233	,0x0000), // '9' ➔ "∳" U+2233 ANTICLOCKWISE CONTOUR INTEGRAL
/*<!M><%dollar><a>                                                 */ DEADTRANS( L'a'	,0x00A4	,0x060B	,0x0000), // 'a' ➔ "؋" U+060B AFGHANI SIGN
/*<!M><%dollar><A>                                                 */ DEADTRANS( L'A'	,0x00A4	,0x20B3	,0x0000), // 'A' ➔ "₳" U+20B3 AUSTRAL SIGN
/*<!M><%dollar><b>                                                 */ DEADTRANS( L'b'	,0x00A4	,0x0E3F	,0x0000), // 'b' ➔ "฿" U+0E3F THAI CURRENCY SYMBOL BAHT
/*<!M><%dollar><B>                                                 */ DEADTRANS( L'B'	,0x00A4	,0x20B1	,0x0000), // 'B' ➔ "₱" U+20B1 PESO SIGN
/*<!M><%dollar><c>                                                 */ DEADTRANS( L'c'	,0x00A4	,0x00A2	,0x0000), // 'c' ➔ "¢" U+00A2 CENT SIGN
/*<!M><%dollar><C>                                                 */ DEADTRANS( L'C'	,0x00A4	,0x20A1	,0x0000), // 'C' ➔ "₡" U+20A1 COLON SIGN
/*<!M><%dollar><Ccedilla>                                          */ DEADTRANS( 0x00C7	,0x00A4	,0x20B5	,0x0000), // 'Ç' ➔ "₵" U+20B5 CEDI SIGN
/*<!M><%dollar><ccedilla>                                          */ DEADTRANS( 0x00E7	,0x00A4	,0x20B5	,0x0000), // 'ç' ➔ "₵" U+20B5 CEDI SIGN
/*<!M><%dollar><d>                                                 */ DEADTRANS( L'd'	,0x00A4	,0x20AB	,0x0000), // 'd' ➔ "₫" U+20AB DONG SIGN
/*<!M><%dollar><D>                                                 */ DEADTRANS( L'D'	,0x00A4	,0x20AF	,0x0000), // 'D' ➔ "₯" U+20AF DRACHMA SIGN
/*<!M><%dollar><E>                                                 */ DEADTRANS( L'E'	,0x00A4	,0x20A0	,0x0000), // 'E' ➔ "₠" U+20A0 EURO-CURRENCY SIGN
/*<!M><%dollar><e>                                                 */ DEADTRANS( L'e'	,0x00A4	,0x20AC	,0x0000), // 'e' ➔ "€" U+20AC EURO SIGN
/*<!M><%dollar><f>                                                 */ DEADTRANS( L'f'	,0x00A4	,0x0192	,0x0000), // 'f' ➔ "ƒ" U+0192 LATIN SMALL LETTER F WITH HOOK
/*<!M><%dollar><F>                                                 */ DEADTRANS( L'F'	,0x00A4	,0x20A3	,0x0000), // 'F' ➔ "₣" U+20A3 FRENCH FRANC SIGN
/*<!M><%dollar><G>                                                 */ DEADTRANS( L'G'	,0x00A4	,0x20B2	,0x0000), // 'G' ➔ "₲" U+20B2 GUARANI SIGN
/*<!M><%dollar><g>                                                 */ DEADTRANS( L'g'	,0x00A4	,0x20B2	,0x0000), // 'g' ➔ "₲" U+20B2 GUARANI SIGN
/*<!M><%dollar><H>                                                 */ DEADTRANS( L'H'	,0x00A4	,0x20B4	,0x0000), // 'H' ➔ "₴" U+20B4 HRYVNIA SIGN
/*<!M><%dollar><h>                                                 */ DEADTRANS( L'h'	,0x00A4	,0x20B4	,0x0000), // 'h' ➔ "₴" U+20B4 HRYVNIA SIGN
/*<!M><%dollar><I>                                                 */ DEADTRANS( L'I'	,0x00A4	,0x17DB	,0x0000), // 'I' ➔ "៛" U+17DB KHMER CURRENCY SYMBOL RIEL
/*<!M><%dollar><i>                                                 */ DEADTRANS( L'i'	,0x00A4	,0xFDFC	,0x0000), // 'i' ➔ "﷼" U+FDFC RIAL SIGN
/*<!M><%dollar><J>                                                 */ DEADTRANS( L'J'	,0x00A4	,0x09F2	,0x0000), // 'J' ➔ "৲" U+09F2 BENGALI RUPEE MARK
/*<!M><%dollar><j>                                                 */ DEADTRANS( L'j'	,0x00A4	,0x20B9	,0x0000), // 'j' ➔ "₹" U+20B9 INDIAN RUPEE SIGN
/*<!M><%dollar><K>                                                 */ DEADTRANS( L'K'	,0x00A4	,0x20AD	,0x0000), // 'K' ➔ "₭" U+20AD KIP SIGN
/*<!M><%dollar><k>                                                 */ DEADTRANS( L'k'	,0x00A4	,0x20AD	,0x0000), // 'k' ➔ "₭" U+20AD KIP SIGN
/*<!M><%dollar><l>                                                 */ DEADTRANS( L'l'	,0x00A4	,0x00A3	,0x0000), // 'l' ➔ "£" U+00A3 POUND SIGN
/*<!M><%dollar><L>                                                 */ DEADTRANS( L'L'	,0x00A4	,0x20A4	,0x0000), // 'L' ➔ "₤" U+20A4 LIRA SIGN
/*<!M><%dollar><m>                                                 */ DEADTRANS( L'm'	,0x00A4	,0x20A5	,0x0000), // 'm' ➔ "₥" U+20A5 MILL SIGN
/*<!M><%dollar><M>                                                 */ DEADTRANS( L'M'	,0x00A4	,0x2133	,0x0000), // 'M' ➔ "ℳ" U+2133 SCRIPT CAPITAL M
/*<!M><%dollar><N>                                                 */ DEADTRANS( L'N'	,0x00A4	,0x20A6	,0x0000), // 'N' ➔ "₦" U+20A6 NAIRA SIGN
/*<!M><%dollar><n>                                                 */ DEADTRANS( L'n'	,0x00A4	,0x20A6	,0x0000), // 'n' ➔ "₦" U+20A6 NAIRA SIGN
/*<!M><%dollar><O>                                                 */ DEADTRANS( L'O'	,0x00A4	,0x0AF1	,0x0000), // 'O' ➔ "૱" U+0AF1 GUJARATI RUPEE SIGN
/*<!M><%dollar><o>                                                 */ DEADTRANS( L'o'	,0x00A4	,0x0BF9	,0x0000), // 'o' ➔ "௹" U+0BF9 TAMIL RUPEE SIGN
/*<!M><%dollar><P>                                                 */ DEADTRANS( L'P'	,0x00A4	,0x20A7	,0x0000), // 'P' ➔ "₧" U+20A7 PESETA SIGN
/*<!M><%dollar><p>                                                 */ DEADTRANS( L'p'	,0x00A4	,0x20B0	,0x0000), // 'p' ➔ "₰" U+20B0 GERMAN PENNY SIGN
/*<!M><%dollar><q>                                                 */ DEADTRANS( L'q'	,0x00A4	,0x058F	,0x0000), // 'q' ➔ "֏" U+058F ARMENIAN DRAM SIGN
/*<!M><%dollar><Q>                                                 */ DEADTRANS( L'Q'	,0x00A4	,0x20B9	,0x0000), // 'Q' ➔ "₹" U+20B9 INDIAN RUPEE SIGN
/*<!M><%dollar><r>                                                 */ DEADTRANS( L'r'	,0x00A4	,0x20A2	,0x0000), // 'r' ➔ "₢" U+20A2 CRUZEIRO SIGN
/*<!M><%dollar><R>                                                 */ DEADTRANS( L'R'	,0x00A4	,0x20A8	,0x0000), // 'R' ➔ "₨" U+20A8 RUPEE SIGN
/*<!M><%dollar><s>                                                 */ DEADTRANS( L's'	,0x00A4	,0x20AA	,0x0000), // 's' ➔ "₪" U+20AA NEW SHEQEL SIGN
/*<!M><%dollar><S>                                                 */ DEADTRANS( L'S'	,0x00A4	,0x20C0	,0x0000), // 'S' ➔ "⃀" U+20C0 SOM SIGN
/*<!M><%dollar><t>                                                 */ DEADTRANS( L't'	,0x00A4	,0x09F3	,0x0000), // 't' ➔ "৳" U+09F3 BENGALI RUPEE SIGN
/*<!M><%dollar><T>                                                 */ DEADTRANS( L'T'	,0x00A4	,0x20AE	,0x0000), // 'T' ➔ "₮" U+20AE TUGRIK SIGN
/*<!M><%dollar><u>                                                 */ DEADTRANS( L'u'	,0x00A4	,0x5143	,0x0000), // 'u' ➔ "元" U+5143 YUAN / WEN
/*<!M><%dollar><U>                                                 */ DEADTRANS( L'U'	,0x00A4	,0x5713	,0x0000), // 'U' ➔ "圓" U+5713 YUAN / WEN
/*<!M><%dollar><V>                                                 */ DEADTRANS( L'V'	,0x00A4	,0x20BA	,0x0000), // 'V' ➔ "₺" U+20BA TURKISH LIRA SIGN
/*<!M><%dollar><v>                                                 */ DEADTRANS( L'v'	,0x00A4	,0x20BE	,0x0000), // 'v' ➔ "₾" U+20BE LARI SIGN
/*<!M><%dollar><W>                                                 */ DEADTRANS( L'W'	,0x00A4	,0x20A9	,0x0000), // 'W' ➔ "₩" U+20A9 WON SIGN
/*<!M><%dollar><w>                                                 */ DEADTRANS( L'w'	,0x00A4	,0x20A9	,0x0000), // 'w' ➔ "₩" U+20A9 WON SIGN
/*<!M><%dollar><X>                                                 */ DEADTRANS( L'X'	,0x00A4	,0x20B8	,0x0000), // 'X' ➔ "₸" U+20B8 TENGE SIGN
/*<!M><%dollar><x>                                                 */ DEADTRANS( L'x'	,0x00A4	,0x20BC	,0x0000), // 'x' ➔ "₼" U+20BC MANAT SIGN
/*<!M><%dollar><y>                                                 */ DEADTRANS( L'y'	,0x00A4	,0x00A5	,0x0000), // 'y' ➔ "¥" U+00A5 YEN SIGN
/*<!M><%dollar><Y>                                                 */ DEADTRANS( L'Y'	,0x00A4	,0x5186	,0x0000), // 'Y' ➔ "円" U+5186 YEN
/*<!M><%dollar><z>                                                 */ DEADTRANS( L'z'	,0x00A4	,0x20B7	,0x0000), // 'z' ➔ "₷" U+20B7 SPESMILO SIGN
/*<!M><%dollar><Z>                                                 */ DEADTRANS( L'Z'	,0x00A4	,0x20BD	,0x0000), // 'Z' ➔ "₽" U+20BD RUBLE SIGN
/*<!M><%dollar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0x00A4	,0x00A4	,0x0000), // ' ' ➔ "¤" U+00A4 CURRENCY SIGN
/*<!M><%dollar><~nbthinspace>                                      */ DEADTRANS( 0x202F	,0x00A4	,0x00A4	,0x0000), // ' ' ➔ "¤" U+00A4 CURRENCY SIGN
/*<!M><%dollar><~space>                                            */ DEADTRANS( L' '	,0x00A4	,0x00A4	,0x0000), // ' ' ➔ "¤" U+00A4 CURRENCY SIGN
/*<!M><%dollar><~spacezerowidth>                                   */ DEADTRANS( 0x200B	,0x00A4	,0x00A4	,0x0000), // '​' ➔ "¤" U+00A4 CURRENCY SIGN
/*<!M><%equal><0>                                                  */ DEADTRANS( L'0'	,0x2690	,0x21D5	,0x0000), // '0' ➔ "⇕" U+21D5 UP DOWN DOUBLE ARROW
/*<!M><%equal><1>                                                  */ DEADTRANS( L'1'	,0x2690	,0x21D9	,0x0000), // '1' ➔ "⇙" U+21D9 SOUTH WEST DOUBLE ARROW
/*<!M><%equal><2>                                                  */ DEADTRANS( L'2'	,0x2690	,0x21D3	,0x0000), // '2' ➔ "⇓" U+21D3 DOWNWARDS DOUBLE ARROW
/*<!M><%equal><3>                                                  */ DEADTRANS( L'3'	,0x2690	,0x21D8	,0x0000), // '3' ➔ "⇘" U+21D8 SOUTH EAST DOUBLE ARROW
/*<!M><%equal><4>                                                  */ DEADTRANS( L'4'	,0x2690	,0x21D0	,0x0000), // '4' ➔ "⇐" U+21D0 LEFTWARDS DOUBLE ARROW
/*<!M><%equal><5>                                                  */ DEADTRANS( L'5'	,0x2690	,0x21D4	,0x0000), // '5' ➔ "⇔" U+21D4 LEFT RIGHT DOUBLE ARROW
/*<!M><%equal><6>                                                  */ DEADTRANS( L'6'	,0x2690	,0x21D2	,0x0000), // '6' ➔ "⇒" U+21D2 RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><7>                                                  */ DEADTRANS( L'7'	,0x2690	,0x21D6	,0x0000), // '7' ➔ "⇖" U+21D6 NORTH WEST DOUBLE ARROW
/*<!M><%equal><8>                                                  */ DEADTRANS( L'8'	,0x2690	,0x21D1	,0x0000), // '8' ➔ "⇑" U+21D1 UPWARDS DOUBLE ARROW
/*<!M><%equal><9>                                                  */ DEADTRANS( L'9'	,0x2690	,0x21D7	,0x0000), // '9' ➔ "⇗" U+21D7 NORTH EAST DOUBLE ARROW
/*<!M><%equal><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x2690	,0x02ED	,0x0000), // ' ' ➔ "˭" U+02ED MODIFIER LETTER UNASPIRATED
/*<!M><%equal><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x2690	,0x02ED	,0x0000), // ' ' ➔ "˭" U+02ED MODIFIER LETTER UNASPIRATED
/*<!M><%equal><~space>                                             */ DEADTRANS( L' '	,0x2690	,0x1AE8	,0x0000), // ' ' ➔ "᫨" U+1AE8 COMBINING EQUALS SIGN ABOVE
/*<!M><%equal><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x2690	,0x1AE8	,0x0000), // '​' ➔ "᫨" U+1AE8 COMBINING EQUALS SIGN ABOVE
/*<!M><%exclam><%equal>                                            */ DEADTRANS( L'='	,0x1E05	,0x2A66	,0x0000), // '=' ➔ "⩦" U+2A66 EQUALS SIGN WITH DOT BELOW
/*<!M><%exclam><%underscore>                                       */ DEADTRANS( L'_'	,0x1E05	,0x20E8	,0x0000), // '_' ➔ "⃨" U+20E8 COMBINING TRIPLE UNDERDOT
/*<!M><%exclam><0>                                                 */ DEADTRANS( L'0'	,0x1E05	,0x2E2A	,0x0000), // '0' ➔ "⸪" U+2E2A TWO DOTS OVER ONE DOT PUNCTUATION
/*<!M><%exclam><1>                                                 */ DEADTRANS( L'1'	,0x1E05	,0x2E2B	,0x0000), // '1' ➔ "⸫" U+2E2B ONE DOT OVER TWO DOTS PUNCTUATION
/*<!M><%exclam><2>                                                 */ DEADTRANS( L'2'	,0x1E05	,0x205A	,0x0000), // '2' ➔ "⁚" U+205A TWO DOT PUNCTUATION
/*<!M><%exclam><3>                                                 */ DEADTRANS( L'3'	,0x1E05	,0x205D	,0x0000), // '3' ➔ "⁝" U+205D TRICOLON
/*<!M><%exclam><4>                                                 */ DEADTRANS( L'4'	,0x1E05	,0x205E	,0x0000), // '4' ➔ "⁞" U+205E VERTICAL FOUR DOTS
/*<!M><%exclam><5>                                                 */ DEADTRANS( L'5'	,0x1E05	,0x2059	,0x0000), // '5' ➔ "⁙" U+2059 FIVE DOT PUNCTUATION
/*<!M><%exclam><6>                                                 */ DEADTRANS( L'6'	,0x1E05	,0x2E3D	,0x0000), // '6' ➔ "⸽" U+2E3D VERTICAL SIX DOTS
/*<!M><%exclam><7>                                                 */ DEADTRANS( L'7'	,0x1E05	,0x2E2C	,0x0000), // '7' ➔ "⸬" U+2E2C SQUARED FOUR DOT PUNCTUATION
/*<!M><%exclam><8>                                                 */ DEADTRANS( L'8'	,0x1E05	,0x2058	,0x0000), // '8' ➔ "⁘" U+2058 FOUR DOT PUNCTUATION
/*<!M><%exclam><9>                                                 */ DEADTRANS( L'9'	,0x1E05	,0x205B	,0x0000), // '9' ➔ "⁛" U+205B FOUR DOT MARK
/*<!M><%exclam><A>                                                 */ DEADTRANS( L'A'	,0x1E05	,0x1EA0	,0x0000), // 'A' ➔ "Ạ" U+1EA0 LATIN CAPITAL LETTER A WITH DOT BELOW
/*<!M><%exclam><a>                                                 */ DEADTRANS( L'a'	,0x1E05	,0x1EA1	,0x0000), // 'a' ➔ "ạ" U+1EA1 LATIN SMALL LETTER A WITH DOT BELOW
/*<!M><%exclam><B>                                                 */ DEADTRANS( L'B'	,0x1E05	,0x1E04	,0x0000), // 'B' ➔ "Ḅ" U+1E04 LATIN CAPITAL LETTER B WITH DOT BELOW
/*<!M><%exclam><b>                                                 */ DEADTRANS( L'b'	,0x1E05	,0x1E05	,0x0000), // 'b' ➔ "ḅ" U+1E05 LATIN SMALL LETTER B WITH DOT BELOW
/*<!M><%exclam><D>                                                 */ DEADTRANS( L'D'	,0x1E05	,0x1E0C	,0x0000), // 'D' ➔ "Ḍ" U+1E0C LATIN CAPITAL LETTER D WITH DOT BELOW
/*<!M><%exclam><d>                                                 */ DEADTRANS( L'd'	,0x1E05	,0x1E0D	,0x0000), // 'd' ➔ "ḍ" U+1E0D LATIN SMALL LETTER D WITH DOT BELOW
/*<!M><%exclam><E>                                                 */ DEADTRANS( L'E'	,0x1E05	,0x1EB8	,0x0000), // 'E' ➔ "Ẹ" U+1EB8 LATIN CAPITAL LETTER E WITH DOT BELOW
/*<!M><%exclam><e>                                                 */ DEADTRANS( L'e'	,0x1E05	,0x1EB9	,0x0000), // 'e' ➔ "ẹ" U+1EB9 LATIN SMALL LETTER E WITH DOT BELOW
/*<!M><%exclam><H>                                                 */ DEADTRANS( L'H'	,0x1E05	,0x1E24	,0x0000), // 'H' ➔ "Ḥ" U+1E24 LATIN CAPITAL LETTER H WITH DOT BELOW
/*<!M><%exclam><h>                                                 */ DEADTRANS( L'h'	,0x1E05	,0x1E25	,0x0000), // 'h' ➔ "ḥ" U+1E25 LATIN SMALL LETTER H WITH DOT BELOW
/*<!M><%exclam><I>                                                 */ DEADTRANS( L'I'	,0x1E05	,0x1ECA	,0x0000), // 'I' ➔ "Ị" U+1ECA LATIN CAPITAL LETTER I WITH DOT BELOW
/*<!M><%exclam><i>                                                 */ DEADTRANS( L'i'	,0x1E05	,0x1ECB	,0x0000), // 'i' ➔ "ị" U+1ECB LATIN SMALL LETTER I WITH DOT BELOW
/*<!M><%exclam><K>                                                 */ DEADTRANS( L'K'	,0x1E05	,0x1E32	,0x0000), // 'K' ➔ "Ḳ" U+1E32 LATIN CAPITAL LETTER K WITH DOT BELOW
/*<!M><%exclam><k>                                                 */ DEADTRANS( L'k'	,0x1E05	,0x1E33	,0x0000), // 'k' ➔ "ḳ" U+1E33 LATIN SMALL LETTER K WITH DOT BELOW
/*<!M><%exclam><L>                                                 */ DEADTRANS( L'L'	,0x1E05	,0x1E36	,0x0000), // 'L' ➔ "Ḷ" U+1E36 LATIN CAPITAL LETTER L WITH DOT BELOW
/*<!M><%exclam><l>                                                 */ DEADTRANS( L'l'	,0x1E05	,0x1E37	,0x0000), // 'l' ➔ "ḷ" U+1E37 LATIN SMALL LETTER L WITH DOT BELOW
/*<!M><%exclam><M>                                                 */ DEADTRANS( L'M'	,0x1E05	,0x1E42	,0x0000), // 'M' ➔ "Ṃ" U+1E42 LATIN CAPITAL LETTER M WITH DOT BELOW
/*<!M><%exclam><m>                                                 */ DEADTRANS( L'm'	,0x1E05	,0x1E43	,0x0000), // 'm' ➔ "ṃ" U+1E43 LATIN SMALL LETTER M WITH DOT BELOW
/*<!M><%exclam><N>                                                 */ DEADTRANS( L'N'	,0x1E05	,0x1E46	,0x0000), // 'N' ➔ "Ṇ" U+1E46 LATIN CAPITAL LETTER N WITH DOT BELOW
/*<!M><%exclam><n>                                                 */ DEADTRANS( L'n'	,0x1E05	,0x1E47	,0x0000), // 'n' ➔ "ṇ" U+1E47 LATIN SMALL LETTER N WITH DOT BELOW
/*<!M><%exclam><O>                                                 */ DEADTRANS( L'O'	,0x1E05	,0x1ECC	,0x0000), // 'O' ➔ "Ọ" U+1ECC LATIN CAPITAL LETTER O WITH DOT BELOW
/*<!M><%exclam><o>                                                 */ DEADTRANS( L'o'	,0x1E05	,0x1ECD	,0x0000), // 'o' ➔ "ọ" U+1ECD LATIN SMALL LETTER O WITH DOT BELOW
/*<!M><%exclam><R>                                                 */ DEADTRANS( L'R'	,0x1E05	,0x1E5A	,0x0000), // 'R' ➔ "Ṛ" U+1E5A LATIN CAPITAL LETTER R WITH DOT BELOW
/*<!M><%exclam><r>                                                 */ DEADTRANS( L'r'	,0x1E05	,0x1E5B	,0x0000), // 'r' ➔ "ṛ" U+1E5B LATIN SMALL LETTER R WITH DOT BELOW
/*<!M><%exclam><S>                                                 */ DEADTRANS( L'S'	,0x1E05	,0x1E62	,0x0000), // 'S' ➔ "Ṣ" U+1E62 LATIN CAPITAL LETTER S WITH DOT BELOW
/*<!M><%exclam><s>                                                 */ DEADTRANS( L's'	,0x1E05	,0x1E63	,0x0000), // 's' ➔ "ṣ" U+1E63 LATIN SMALL LETTER S WITH DOT BELOW
/*<!M><%exclam><T>                                                 */ DEADTRANS( L'T'	,0x1E05	,0x1E6C	,0x0000), // 'T' ➔ "Ṭ" U+1E6C LATIN CAPITAL LETTER T WITH DOT BELOW
/*<!M><%exclam><t>                                                 */ DEADTRANS( L't'	,0x1E05	,0x1E6D	,0x0000), // 't' ➔ "ṭ" U+1E6D LATIN SMALL LETTER T WITH DOT BELOW
/*<!M><%exclam><U>                                                 */ DEADTRANS( L'U'	,0x1E05	,0x1EE4	,0x0000), // 'U' ➔ "Ụ" U+1EE4 LATIN CAPITAL LETTER U WITH DOT BELOW
/*<!M><%exclam><u>                                                 */ DEADTRANS( L'u'	,0x1E05	,0x1EE5	,0x0000), // 'u' ➔ "ụ" U+1EE5 LATIN SMALL LETTER U WITH DOT BELOW
/*<!M><%exclam><V>                                                 */ DEADTRANS( L'V'	,0x1E05	,0x1E7E	,0x0000), // 'V' ➔ "Ṿ" U+1E7E LATIN CAPITAL LETTER V WITH DOT BELOW
/*<!M><%exclam><v>                                                 */ DEADTRANS( L'v'	,0x1E05	,0x1E7F	,0x0000), // 'v' ➔ "ṿ" U+1E7F LATIN SMALL LETTER V WITH DOT BELOW
/*<!M><%exclam><W>                                                 */ DEADTRANS( L'W'	,0x1E05	,0x1E88	,0x0000), // 'W' ➔ "Ẉ" U+1E88 LATIN CAPITAL LETTER W WITH DOT BELOW
/*<!M><%exclam><w>                                                 */ DEADTRANS( L'w'	,0x1E05	,0x1E89	,0x0000), // 'w' ➔ "ẉ" U+1E89 LATIN SMALL LETTER W WITH DOT BELOW
/*<!M><%exclam><Y>                                                 */ DEADTRANS( L'Y'	,0x1E05	,0x1EF4	,0x0000), // 'Y' ➔ "Ỵ" U+1EF4 LATIN CAPITAL LETTER Y WITH DOT BELOW
/*<!M><%exclam><y>                                                 */ DEADTRANS( L'y'	,0x1E05	,0x1EF5	,0x0000), // 'y' ➔ "ỵ" U+1EF5 LATIN SMALL LETTER Y WITH DOT BELOW
/*<!M><%exclam><Z>                                                 */ DEADTRANS( L'Z'	,0x1E05	,0x1E92	,0x0000), // 'Z' ➔ "Ẓ" U+1E92 LATIN CAPITAL LETTER Z WITH DOT BELOW
/*<!M><%exclam><z>                                                 */ DEADTRANS( L'z'	,0x1E05	,0x1E93	,0x0000), // 'z' ➔ "ẓ" U+1E93 LATIN SMALL LETTER Z WITH DOT BELOW
/*<!M><%exclam><~nbspace>                                          */ DEADTRANS( 0x00A0	,0x1E05	,0x2E33	,0x0000), // ' ' ➔ "⸳" U+2E33 RAISED DOT
/*<!M><%exclam><~nbthinspace>                                      */ DEADTRANS( 0x202F	,0x1E05	,0x2E33	,0x0000), // ' ' ➔ "⸳" U+2E33 RAISED DOT
/*<!M><%exclam><~space>                                            */ DEADTRANS( L' '	,0x1E05	,0x0323	,0x0000), // ' ' ➔ "̣" U+0323 COMBINING DOT BELOW
/*<!M><%exclam><~spacezerowidth>                                   */ DEADTRANS( 0x200B	,0x1E05	,0x0323	,0x0000), // '​' ➔ "̣" U+0323 COMBINING DOT BELOW
/*<!M><%excsection><%equal>                                        */ DEADTRANS( L'='	,0x1E05	,0x2A66	,0x0000), // '=' ➔ "⩦" U+2A66 EQUALS SIGN WITH DOT BELOW
/*<!M><%excsection><%underscore>                                   */ DEADTRANS( L'_'	,0x1E05	,0x20E8	,0x0000), // '_' ➔ "⃨" U+20E8 COMBINING TRIPLE UNDERDOT
/*<!M><%excsection><0>                                             */ DEADTRANS( L'0'	,0x1E05	,0x2E2A	,0x0000), // '0' ➔ "⸪" U+2E2A TWO DOTS OVER ONE DOT PUNCTUATION
/*<!M><%excsection><1>                                             */ DEADTRANS( L'1'	,0x1E05	,0x2E2B	,0x0000), // '1' ➔ "⸫" U+2E2B ONE DOT OVER TWO DOTS PUNCTUATION
/*<!M><%excsection><2>                                             */ DEADTRANS( L'2'	,0x1E05	,0x205A	,0x0000), // '2' ➔ "⁚" U+205A TWO DOT PUNCTUATION
/*<!M><%excsection><3>                                             */ DEADTRANS( L'3'	,0x1E05	,0x205D	,0x0000), // '3' ➔ "⁝" U+205D TRICOLON
/*<!M><%excsection><4>                                             */ DEADTRANS( L'4'	,0x1E05	,0x205E	,0x0000), // '4' ➔ "⁞" U+205E VERTICAL FOUR DOTS
/*<!M><%excsection><5>                                             */ DEADTRANS( L'5'	,0x1E05	,0x2059	,0x0000), // '5' ➔ "⁙" U+2059 FIVE DOT PUNCTUATION
/*<!M><%excsection><6>                                             */ DEADTRANS( L'6'	,0x1E05	,0x2E3D	,0x0000), // '6' ➔ "⸽" U+2E3D VERTICAL SIX DOTS
/*<!M><%excsection><7>                                             */ DEADTRANS( L'7'	,0x1E05	,0x2E2C	,0x0000), // '7' ➔ "⸬" U+2E2C SQUARED FOUR DOT PUNCTUATION
/*<!M><%excsection><8>                                             */ DEADTRANS( L'8'	,0x1E05	,0x2058	,0x0000), // '8' ➔ "⁘" U+2058 FOUR DOT PUNCTUATION
/*<!M><%excsection><9>                                             */ DEADTRANS( L'9'	,0x1E05	,0x205B	,0x0000), // '9' ➔ "⁛" U+205B FOUR DOT MARK
/*<!M><%excsection><A>                                             */ DEADTRANS( L'A'	,0x1E05	,0x1EA0	,0x0000), // 'A' ➔ "Ạ" U+1EA0 LATIN CAPITAL LETTER A WITH DOT BELOW
/*<!M><%excsection><a>                                             */ DEADTRANS( L'a'	,0x1E05	,0x1EA1	,0x0000), // 'a' ➔ "ạ" U+1EA1 LATIN SMALL LETTER A WITH DOT BELOW
/*<!M><%excsection><B>                                             */ DEADTRANS( L'B'	,0x1E05	,0x1E04	,0x0000), // 'B' ➔ "Ḅ" U+1E04 LATIN CAPITAL LETTER B WITH DOT BELOW
/*<!M><%excsection><b>                                             */ DEADTRANS( L'b'	,0x1E05	,0x1E05	,0x0000), // 'b' ➔ "ḅ" U+1E05 LATIN SMALL LETTER B WITH DOT BELOW
/*<!M><%excsection><D>                                             */ DEADTRANS( L'D'	,0x1E05	,0x1E0C	,0x0000), // 'D' ➔ "Ḍ" U+1E0C LATIN CAPITAL LETTER D WITH DOT BELOW
/*<!M><%excsection><d>                                             */ DEADTRANS( L'd'	,0x1E05	,0x1E0D	,0x0000), // 'd' ➔ "ḍ" U+1E0D LATIN SMALL LETTER D WITH DOT BELOW
/*<!M><%excsection><E>                                             */ DEADTRANS( L'E'	,0x1E05	,0x1EB8	,0x0000), // 'E' ➔ "Ẹ" U+1EB8 LATIN CAPITAL LETTER E WITH DOT BELOW
/*<!M><%excsection><e>                                             */ DEADTRANS( L'e'	,0x1E05	,0x1EB9	,0x0000), // 'e' ➔ "ẹ" U+1EB9 LATIN SMALL LETTER E WITH DOT BELOW
/*<!M><%excsection><H>                                             */ DEADTRANS( L'H'	,0x1E05	,0x1E24	,0x0000), // 'H' ➔ "Ḥ" U+1E24 LATIN CAPITAL LETTER H WITH DOT BELOW
/*<!M><%excsection><h>                                             */ DEADTRANS( L'h'	,0x1E05	,0x1E25	,0x0000), // 'h' ➔ "ḥ" U+1E25 LATIN SMALL LETTER H WITH DOT BELOW
/*<!M><%excsection><I>                                             */ DEADTRANS( L'I'	,0x1E05	,0x1ECA	,0x0000), // 'I' ➔ "Ị" U+1ECA LATIN CAPITAL LETTER I WITH DOT BELOW
/*<!M><%excsection><i>                                             */ DEADTRANS( L'i'	,0x1E05	,0x1ECB	,0x0000), // 'i' ➔ "ị" U+1ECB LATIN SMALL LETTER I WITH DOT BELOW
/*<!M><%excsection><K>                                             */ DEADTRANS( L'K'	,0x1E05	,0x1E32	,0x0000), // 'K' ➔ "Ḳ" U+1E32 LATIN CAPITAL LETTER K WITH DOT BELOW
/*<!M><%excsection><k>                                             */ DEADTRANS( L'k'	,0x1E05	,0x1E33	,0x0000), // 'k' ➔ "ḳ" U+1E33 LATIN SMALL LETTER K WITH DOT BELOW
/*<!M><%excsection><L>                                             */ DEADTRANS( L'L'	,0x1E05	,0x1E36	,0x0000), // 'L' ➔ "Ḷ" U+1E36 LATIN CAPITAL LETTER L WITH DOT BELOW
/*<!M><%excsection><l>                                             */ DEADTRANS( L'l'	,0x1E05	,0x1E37	,0x0000), // 'l' ➔ "ḷ" U+1E37 LATIN SMALL LETTER L WITH DOT BELOW
/*<!M><%excsection><M>                                             */ DEADTRANS( L'M'	,0x1E05	,0x1E42	,0x0000), // 'M' ➔ "Ṃ" U+1E42 LATIN CAPITAL LETTER M WITH DOT BELOW
/*<!M><%excsection><m>                                             */ DEADTRANS( L'm'	,0x1E05	,0x1E43	,0x0000), // 'm' ➔ "ṃ" U+1E43 LATIN SMALL LETTER M WITH DOT BELOW
/*<!M><%excsection><N>                                             */ DEADTRANS( L'N'	,0x1E05	,0x1E46	,0x0000), // 'N' ➔ "Ṇ" U+1E46 LATIN CAPITAL LETTER N WITH DOT BELOW
/*<!M><%excsection><n>                                             */ DEADTRANS( L'n'	,0x1E05	,0x1E47	,0x0000), // 'n' ➔ "ṇ" U+1E47 LATIN SMALL LETTER N WITH DOT BELOW
/*<!M><%excsection><O>                                             */ DEADTRANS( L'O'	,0x1E05	,0x1ECC	,0x0000), // 'O' ➔ "Ọ" U+1ECC LATIN CAPITAL LETTER O WITH DOT BELOW
/*<!M><%excsection><o>                                             */ DEADTRANS( L'o'	,0x1E05	,0x1ECD	,0x0000), // 'o' ➔ "ọ" U+1ECD LATIN SMALL LETTER O WITH DOT BELOW
/*<!M><%excsection><R>                                             */ DEADTRANS( L'R'	,0x1E05	,0x1E5A	,0x0000), // 'R' ➔ "Ṛ" U+1E5A LATIN CAPITAL LETTER R WITH DOT BELOW
/*<!M><%excsection><r>                                             */ DEADTRANS( L'r'	,0x1E05	,0x1E5B	,0x0000), // 'r' ➔ "ṛ" U+1E5B LATIN SMALL LETTER R WITH DOT BELOW
/*<!M><%excsection><S>                                             */ DEADTRANS( L'S'	,0x1E05	,0x1E62	,0x0000), // 'S' ➔ "Ṣ" U+1E62 LATIN CAPITAL LETTER S WITH DOT BELOW
/*<!M><%excsection><s>                                             */ DEADTRANS( L's'	,0x1E05	,0x1E63	,0x0000), // 's' ➔ "ṣ" U+1E63 LATIN SMALL LETTER S WITH DOT BELOW
/*<!M><%excsection><T>                                             */ DEADTRANS( L'T'	,0x1E05	,0x1E6C	,0x0000), // 'T' ➔ "Ṭ" U+1E6C LATIN CAPITAL LETTER T WITH DOT BELOW
/*<!M><%excsection><t>                                             */ DEADTRANS( L't'	,0x1E05	,0x1E6D	,0x0000), // 't' ➔ "ṭ" U+1E6D LATIN SMALL LETTER T WITH DOT BELOW
/*<!M><%excsection><U>                                             */ DEADTRANS( L'U'	,0x1E05	,0x1EE4	,0x0000), // 'U' ➔ "Ụ" U+1EE4 LATIN CAPITAL LETTER U WITH DOT BELOW
/*<!M><%excsection><u>                                             */ DEADTRANS( L'u'	,0x1E05	,0x1EE5	,0x0000), // 'u' ➔ "ụ" U+1EE5 LATIN SMALL LETTER U WITH DOT BELOW
/*<!M><%excsection><V>                                             */ DEADTRANS( L'V'	,0x1E05	,0x1E7E	,0x0000), // 'V' ➔ "Ṿ" U+1E7E LATIN CAPITAL LETTER V WITH DOT BELOW
/*<!M><%excsection><v>                                             */ DEADTRANS( L'v'	,0x1E05	,0x1E7F	,0x0000), // 'v' ➔ "ṿ" U+1E7F LATIN SMALL LETTER V WITH DOT BELOW
/*<!M><%excsection><W>                                             */ DEADTRANS( L'W'	,0x1E05	,0x1E88	,0x0000), // 'W' ➔ "Ẉ" U+1E88 LATIN CAPITAL LETTER W WITH DOT BELOW
/*<!M><%excsection><w>                                             */ DEADTRANS( L'w'	,0x1E05	,0x1E89	,0x0000), // 'w' ➔ "ẉ" U+1E89 LATIN SMALL LETTER W WITH DOT BELOW
/*<!M><%excsection><Y>                                             */ DEADTRANS( L'Y'	,0x1E05	,0x1EF4	,0x0000), // 'Y' ➔ "Ỵ" U+1EF4 LATIN CAPITAL LETTER Y WITH DOT BELOW
/*<!M><%excsection><y>                                             */ DEADTRANS( L'y'	,0x1E05	,0x1EF5	,0x0000), // 'y' ➔ "ỵ" U+1EF5 LATIN SMALL LETTER Y WITH DOT BELOW
/*<!M><%excsection><Z>                                             */ DEADTRANS( L'Z'	,0x1E05	,0x1E92	,0x0000), // 'Z' ➔ "Ẓ" U+1E92 LATIN CAPITAL LETTER Z WITH DOT BELOW
/*<!M><%excsection><z>                                             */ DEADTRANS( L'z'	,0x1E05	,0x1E93	,0x0000), // 'z' ➔ "ẓ" U+1E93 LATIN SMALL LETTER Z WITH DOT BELOW
/*<!M><%excsection><~nbspace>                                      */ DEADTRANS( 0x00A0	,0x1E05	,0x2E33	,0x0000), // ' ' ➔ "⸳" U+2E33 RAISED DOT
/*<!M><%excsection><~nbthinspace>                                  */ DEADTRANS( 0x202F	,0x1E05	,0x2E33	,0x0000), // ' ' ➔ "⸳" U+2E33 RAISED DOT
/*<!M><%excsection><~space>                                        */ DEADTRANS( L' '	,0x1E05	,0x0323	,0x0000), // ' ' ➔ "̣" U+0323 COMBINING DOT BELOW
/*<!M><%excsection><~spacezerowidth>                               */ DEADTRANS( 0x200B	,0x1E05	,0x0323	,0x0000), // '​' ➔ "̣" U+0323 COMBINING DOT BELOW
/*<!M><%grave><%ampersand>                                         */ DEADTRANS( L'&'	,0x00F2	,0x0316	,0x0000), // '&' ➔ "̖" U+0316 COMBINING GRAVE ACCENT BELOW
/*<!M><%grave><%aprightsingquotmark>                               */ DEADTRANS( 0x2019	,0x00F2	,0x201B	,0x0000), // '’' ➔ "‛" U+201B SINGLE HIGH-REVERSED-9 QUOTATION MARK, single reversed comma quotation mark
/*<!M><%grave><%asterisk>                                          */ DEADTRANS( L'*'	,0x00F2	,0x02DF	,0x0000), // '*' ➔ "˟" U+02DF MODIFIER LETTER CROSS ACCENT, Swedish grave accent
/*<!M><%grave><%bracketleft>                                       */ DEADTRANS( L'['	,0x00F2	,0x2751	,0x0000), // '[' ➔ "❑" U+2751 LOWER RIGHT SHADOWED WHITE SQUARE
/*<!M><%grave><%bracketright>                                      */ DEADTRANS( L']'	,0x00F2	,0x274F	,0x0000), // ']' ➔ "❏" U+274F LOWER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%grave><%equal>                                             */ DEADTRANS( L'='	,0x00F2	,0x02F4	,0x0000), // '=' ➔ "˴" U+02F4 MODIFIER LETTER MIDDLE GRAVE ACCENT
/*<!M><%grave><%quotedbl>                                          */ DEADTRANS( L'"'	,0x00F2	,0x201F	,0x0000), // '"' ➔ "‟" U+201F DOUBLE HIGH-REVERSED-9 QUOTATION MARK, double reversed comma quotation mark
/*<!M><%grave><%quotEuroSign>                                      */ DEADTRANS( 0x20AC	,0x00F2	,0x201F	,0x0000), // '€' ➔ "‟" U+201F DOUBLE HIGH-REVERSED-9 QUOTATION MARK, double reversed comma quotation mark
/*<!M><%grave><%underscore>                                        */ DEADTRANS( L'_'	,0x00F2	,0x02CE	,0x0000), // '_' ➔ "ˎ" U+02CE MODIFIER LETTER LOW GRAVE ACCENT
/*<!M><%grave><1>                                                  */ DEADTRANS( L'1'	,0x00F2	,0x2035	,0x0000), // '1' ➔ "‵" U+2035 REVERSED PRIME
/*<!M><%grave><2>                                                  */ DEADTRANS( L'2'	,0x00F2	,0x2036	,0x0000), // '2' ➔ "‶" U+2036 REVERSED DOUBLE PRIME
/*<!M><%grave><3>                                                  */ DEADTRANS( L'3'	,0x00F2	,0x2037	,0x0000), // '3' ➔ "‷" U+2037 REVERSED TRIPLE PRIME
/*<!M><%grave><A>                                                  */ DEADTRANS( L'A'	,0x00F2	,0x00C0	,0x0000), // 'A' ➔ "À" U+00C0 LATIN CAPITAL LETTER A WITH GRAVE
/*<!M><%grave><a>                                                  */ DEADTRANS( L'a'	,0x00F2	,0x00E0	,0x0000), // 'a' ➔ "à" U+00E0 LATIN SMALL LETTER A WITH GRAVE
/*<!M><%grave><E>                                                  */ DEADTRANS( L'E'	,0x00F2	,0x00C8	,0x0000), // 'E' ➔ "È" U+00C8 LATIN CAPITAL LETTER E WITH GRAVE
/*<!M><%grave><e>                                                  */ DEADTRANS( L'e'	,0x00F2	,0x00E8	,0x0000), // 'e' ➔ "è" U+00E8 LATIN SMALL LETTER E WITH GRAVE
/*<!M><%grave><I>                                                  */ DEADTRANS( L'I'	,0x00F2	,0x00CC	,0x0000), // 'I' ➔ "Ì" U+00CC LATIN CAPITAL LETTER I WITH GRAVE
/*<!M><%grave><i>                                                  */ DEADTRANS( L'i'	,0x00F2	,0x00EC	,0x0000), // 'i' ➔ "ì" U+00EC LATIN SMALL LETTER I WITH GRAVE
/*<!M><%grave><N>                                                  */ DEADTRANS( L'N'	,0x00F2	,0x01F8	,0x0000), // 'N' ➔ "Ǹ" U+01F8 LATIN CAPITAL LETTER N WITH GRAVE
/*<!M><%grave><n>                                                  */ DEADTRANS( L'n'	,0x00F2	,0x01F9	,0x0000), // 'n' ➔ "ǹ" U+01F9 LATIN SMALL LETTER N WITH GRAVE
/*<!M><%grave><O>                                                  */ DEADTRANS( L'O'	,0x00F2	,0x00D2	,0x0000), // 'O' ➔ "Ò" U+00D2 LATIN CAPITAL LETTER O WITH GRAVE
/*<!M><%grave><o>                                                  */ DEADTRANS( L'o'	,0x00F2	,0x00F2	,0x0000), // 'o' ➔ "ò" U+00F2 LATIN SMALL LETTER O WITH GRAVE
/*<!M><%grave><U>                                                  */ DEADTRANS( L'U'	,0x00F2	,0x00D9	,0x0000), // 'U' ➔ "Ù" U+00D9 LATIN CAPITAL LETTER U WITH GRAVE
/*<!M><%grave><u>                                                  */ DEADTRANS( L'u'	,0x00F2	,0x00F9	,0x0000), // 'u' ➔ "ù" U+00F9 LATIN SMALL LETTER U WITH GRAVE
/*<!M><%grave><W>                                                  */ DEADTRANS( L'W'	,0x00F2	,0x1E80	,0x0000), // 'W' ➔ "Ẁ" U+1E80 LATIN CAPITAL LETTER W WITH GRAVE
/*<!M><%grave><w>                                                  */ DEADTRANS( L'w'	,0x00F2	,0x1E81	,0x0000), // 'w' ➔ "ẁ" U+1E81 LATIN SMALL LETTER W WITH GRAVE
/*<!M><%grave><Y>                                                  */ DEADTRANS( L'Y'	,0x00F2	,0x1EF2	,0x0000), // 'Y' ➔ "Ỳ" U+1EF2 LATIN CAPITAL LETTER Y WITH GRAVE
/*<!M><%grave><y>                                                  */ DEADTRANS( L'y'	,0x00F2	,0x1EF3	,0x0000), // 'y' ➔ "ỳ" U+1EF3 LATIN SMALL LETTER Y WITH GRAVE
/*<!M><%grave><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x00F2	,0x0060	,0x0000), // ' ' ➔ "`" U+0060 GRAVE ACCENT
/*<!M><%grave><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x00F2	,0x02CB	,0x0000), // ' ' ➔ "ˋ" U+02CB MODIFIER LETTER GRAVE ACCENT
/*<!M><%grave><~space>                                             */ DEADTRANS( L' '	,0x00F2	,0x0300	,0x0000), // ' ' ➔ "̀" U+0300 COMBINING GRAVE ACCENT
/*<!M><%grave><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x00F2	,0x0300	,0x0000), // '​' ➔ "̀" U+0300 COMBINING GRAVE ACCENT
/*<!M><%greater><%comma>                                           */ DEADTRANS( L','	,0x021F	,0x02BB	,0x0000), // ',' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%greater><0>                                                */ DEADTRANS( L'0'	,0x021F	,0x2080	,0x0000), // '0' ➔ "₀" U+2080 SUBSCRIPT ZERO
/*<!M><%greater><1>                                                */ DEADTRANS( L'1'	,0x021F	,0x2081	,0x0000), // '1' ➔ "₁" U+2081 SUBSCRIPT ONE
/*<!M><%greater><2>                                                */ DEADTRANS( L'2'	,0x021F	,0x2082	,0x0000), // '2' ➔ "₂" U+2082 SUBSCRIPT TWO
/*<!M><%greater><3>                                                */ DEADTRANS( L'3'	,0x021F	,0x2083	,0x0000), // '3' ➔ "₃" U+2083 SUBSCRIPT THREE
/*<!M><%greater><4>                                                */ DEADTRANS( L'4'	,0x021F	,0x2084	,0x0000), // '4' ➔ "₄" U+2084 SUBSCRIPT FOUR
/*<!M><%greater><5>                                                */ DEADTRANS( L'5'	,0x021F	,0x2085	,0x0000), // '5' ➔ "₅" U+2085 SUBSCRIPT FIVE
/*<!M><%greater><6>                                                */ DEADTRANS( L'6'	,0x021F	,0x2086	,0x0000), // '6' ➔ "₆" U+2086 SUBSCRIPT SIX
/*<!M><%greater><7>                                                */ DEADTRANS( L'7'	,0x021F	,0x2087	,0x0000), // '7' ➔ "₇" U+2087 SUBSCRIPT SEVEN
/*<!M><%greater><8>                                                */ DEADTRANS( L'8'	,0x021F	,0x2088	,0x0000), // '8' ➔ "₈" U+2088 SUBSCRIPT EIGHT
/*<!M><%greater><9>                                                */ DEADTRANS( L'9'	,0x021F	,0x2089	,0x0000), // '9' ➔ "₉" U+2089 SUBSCRIPT NINE
/*<!M><%greater><A>                                                */ DEADTRANS( L'A'	,0x021F	,0x01CD	,0x0000), // 'A' ➔ "Ǎ" U+01CD LATIN CAPITAL LETTER A WITH CARON
/*<!M><%greater><a>                                                */ DEADTRANS( L'a'	,0x021F	,0x01CE	,0x0000), // 'a' ➔ "ǎ" U+01CE LATIN SMALL LETTER A WITH CARON
/*<!M><%greater><C>                                                */ DEADTRANS( L'C'	,0x021F	,0x010C	,0x0000), // 'C' ➔ "Č" U+010C LATIN CAPITAL LETTER C WITH CARON
/*<!M><%greater><c>                                                */ DEADTRANS( L'c'	,0x021F	,0x010D	,0x0000), // 'c' ➔ "č" U+010D LATIN SMALL LETTER C WITH CARON
/*<!M><%greater><D>                                                */ DEADTRANS( L'D'	,0x021F	,0x010E	,0x0000), // 'D' ➔ "Ď" U+010E LATIN CAPITAL LETTER D WITH CARON
/*<!M><%greater><d>                                                */ DEADTRANS( L'd'	,0x021F	,0x010F	,0x0000), // 'd' ➔ "ď" U+010F LATIN SMALL LETTER D WITH CARON
/*<!M><%greater><E>                                                */ DEADTRANS( L'E'	,0x021F	,0x011A	,0x0000), // 'E' ➔ "Ě" U+011A LATIN CAPITAL LETTER E WITH CARON
/*<!M><%greater><e>                                                */ DEADTRANS( L'e'	,0x021F	,0x011B	,0x0000), // 'e' ➔ "ě" U+011B LATIN SMALL LETTER E WITH CARON
/*<!M><%greater><G>                                                */ DEADTRANS( L'G'	,0x021F	,0x01E6	,0x0000), // 'G' ➔ "Ǧ" U+01E6 LATIN CAPITAL LETTER G WITH CARON
/*<!M><%greater><g>                                                */ DEADTRANS( L'g'	,0x021F	,0x01E7	,0x0000), // 'g' ➔ "ǧ" U+01E7 LATIN SMALL LETTER G WITH CARON
/*<!M><%greater><H>                                                */ DEADTRANS( L'H'	,0x021F	,0x021E	,0x0000), // 'H' ➔ "Ȟ" U+021E LATIN CAPITAL LETTER H WITH CARON
/*<!M><%greater><h>                                                */ DEADTRANS( L'h'	,0x021F	,0x021F	,0x0000), // 'h' ➔ "ȟ" U+021F LATIN SMALL LETTER H WITH CARON
/*<!M><%greater><I>                                                */ DEADTRANS( L'I'	,0x021F	,0x01CF	,0x0000), // 'I' ➔ "Ǐ" U+01CF LATIN CAPITAL LETTER I WITH CARON
/*<!M><%greater><i>                                                */ DEADTRANS( L'i'	,0x021F	,0x01D0	,0x0000), // 'i' ➔ "ǐ" U+01D0 LATIN SMALL LETTER I WITH CARON
/*<!M><%greater><j>                                                */ DEADTRANS( L'j'	,0x021F	,0x01F0	,0x0000), // 'j' ➔ "ǰ" U+01F0 LATIN SMALL LETTER J WITH CARON
/*<!M><%greater><K>                                                */ DEADTRANS( L'K'	,0x021F	,0x01E8	,0x0000), // 'K' ➔ "Ǩ" U+01E8 LATIN CAPITAL LETTER K WITH CARON
/*<!M><%greater><k>                                                */ DEADTRANS( L'k'	,0x021F	,0x01E9	,0x0000), // 'k' ➔ "ǩ" U+01E9 LATIN SMALL LETTER K WITH CARON
/*<!M><%greater><L>                                                */ DEADTRANS( L'L'	,0x021F	,0x013D	,0x0000), // 'L' ➔ "Ľ" U+013D LATIN CAPITAL LETTER L WITH CARON
/*<!M><%greater><l>                                                */ DEADTRANS( L'l'	,0x021F	,0x013E	,0x0000), // 'l' ➔ "ľ" U+013E LATIN SMALL LETTER L WITH CARON
/*<!M><%greater><N>                                                */ DEADTRANS( L'N'	,0x021F	,0x0147	,0x0000), // 'N' ➔ "Ň" U+0147 LATIN CAPITAL LETTER N WITH CARON
/*<!M><%greater><n>                                                */ DEADTRANS( L'n'	,0x021F	,0x0148	,0x0000), // 'n' ➔ "ň" U+0148 LATIN SMALL LETTER N WITH CARON
/*<!M><%greater><O>                                                */ DEADTRANS( L'O'	,0x021F	,0x01D1	,0x0000), // 'O' ➔ "Ǒ" U+01D1 LATIN CAPITAL LETTER O WITH CARON
/*<!M><%greater><o>                                                */ DEADTRANS( L'o'	,0x021F	,0x01D2	,0x0000), // 'o' ➔ "ǒ" U+01D2 LATIN SMALL LETTER O WITH CARON
/*<!M><%greater><R>                                                */ DEADTRANS( L'R'	,0x021F	,0x0158	,0x0000), // 'R' ➔ "Ř" U+0158 LATIN CAPITAL LETTER R WITH CARON
/*<!M><%greater><r>                                                */ DEADTRANS( L'r'	,0x021F	,0x0159	,0x0000), // 'r' ➔ "ř" U+0159 LATIN SMALL LETTER R WITH CARON
/*<!M><%greater><S>                                                */ DEADTRANS( L'S'	,0x021F	,0x0160	,0x0000), // 'S' ➔ "Š" U+0160 LATIN CAPITAL LETTER S WITH CARON
/*<!M><%greater><s>                                                */ DEADTRANS( L's'	,0x021F	,0x0161	,0x0000), // 's' ➔ "š" U+0161 LATIN SMALL LETTER S WITH CARON
/*<!M><%greater><T>                                                */ DEADTRANS( L'T'	,0x021F	,0x0164	,0x0000), // 'T' ➔ "Ť" U+0164 LATIN CAPITAL LETTER T WITH CARON
/*<!M><%greater><t>                                                */ DEADTRANS( L't'	,0x021F	,0x0165	,0x0000), // 't' ➔ "ť" U+0165 LATIN SMALL LETTER T WITH CARON
/*<!M><%greater><U>                                                */ DEADTRANS( L'U'	,0x021F	,0x01D3	,0x0000), // 'U' ➔ "Ǔ" U+01D3 LATIN CAPITAL LETTER U WITH CARON
/*<!M><%greater><u>                                                */ DEADTRANS( L'u'	,0x021F	,0x01D4	,0x0000), // 'u' ➔ "ǔ" U+01D4 LATIN SMALL LETTER U WITH CARON
/*<!M><%greater><W>                                                */ DEADTRANS( L'W'	,0x021F	,0x1ACF	,0x0000), // 'W' ➔ "᫏" U+1ACF COMBINING DOUBLE CARON
/*<!M><%greater><w>                                                */ DEADTRANS( L'w'	,0x021F	,0x1ACF	,0x0000), // 'w' ➔ "᫏" U+1ACF COMBINING DOUBLE CARON
/*<!M><%greater><Z>                                                */ DEADTRANS( L'Z'	,0x021F	,0x017D	,0x0000), // 'Z' ➔ "Ž" U+017D LATIN CAPITAL LETTER Z WITH CARON
/*<!M><%greater><z>                                                */ DEADTRANS( L'z'	,0x021F	,0x017E	,0x0000), // 'z' ➔ "ž" U+017E LATIN SMALL LETTER Z WITH CARON
/*<!M><%greater><~nbspace>                                         */ DEADTRANS( 0x00A0	,0x021F	,0x02C7	,0x0000), // ' ' ➔ "ˇ" U+02C7 CARON
/*<!M><%greater><~nbthinspace>                                     */ DEADTRANS( 0x202F	,0x021F	,0x02C7	,0x0000), // ' ' ➔ "ˇ" U+02C7 CARON
/*<!M><%greater><~space>                                           */ DEADTRANS( L' '	,0x021F	,0x030C	,0x0000), // ' ' ➔ "̌" U+030C COMBINING CARON
/*<!M><%greater><~spacezerowidth>                                  */ DEADTRANS( 0x200B	,0x021F	,0x030C	,0x0000), // '​' ➔ "̌" U+030C COMBINING CARON
/*<!M><%hash><!acute>                                              */ DEADTRANS( 0x00E1	,0x2460	,0x0024	,0x0000), // 'á' ➔ "$" U+0024 DOLLAR SIGN
/*<!M><%hash><!circumflex>                                         */ DEADTRANS( 0x00EA	,0x2460	,0x005E	,0x0000), // 'ê' ➔ "^" U+005E CIRCUMFLEX ACCENT
/*<!M><%hash><!diaeresis>                                          */ DEADTRANS( 0x00EB	,0x2460	,0x003D	,0x0000), // 'ë' ➔ "=" U+003D EQUALS SIGN
/*<!M><%hash><!grave>                                              */ DEADTRANS( 0x00F2	,0x2460	,0x00A4	,0x0000), // 'ò' ➔ "¤" U+00A4 CURRENCY SIGN
/*<!M><%hash><!greek>                                              */ DEADTRANS( 0x03B5	,0x2460	,0x25CC	,0x0000), // 'ε' ➔ "◌" U+25CC DOTTED CIRCLE, generic base character for combining diacritics
/*<!M><%hash><%ampersand>                                          */ DEADTRANS( L'&'	,0x2460	,0x03C0	,0x0000), // '&' ➔ "π" U+03C0 GREEK SMALL LETTER PI math
/*<!M><%hash><%apostrophe>                                         */ DEADTRANS( L'\''	,0x2460	,0x02BC	,0x0000), // ''' ➔ "ʼ" U+02BC MODIFIER LETTER APOSTROPHE
/*<!M><%hash><%aprightsingquotmark>                                */ DEADTRANS( 0x2019	,0x2460	,0x02BC	,0x0000), // '’' ➔ "ʼ" U+02BC MODIFIER LETTER APOSTROPHE
/*<!M><%hash><%asterisk>                                           */ DEADTRANS( L'*'	,0x2460	,0x2717	,0x0000), // '*' ➔ "✗" U+2717 BALLOT X
/*<!M><%hash><%at>                                                 */ DEADTRANS( L'@'	,0x2460	,0x25CC	,0x0000), // '@' ➔ "◌" U+25CC DOTTED CIRCLE, generic base character for combining diacritics
/*<!M><%hash><%backslash>                                          */ DEADTRANS( L'\\'	,0x2460	,0x221A	,0x0000), // '\' ➔ "√" U+221A SQUARE ROOT math
/*<!M><%hash><%bar>                                                */ DEADTRANS( L'|'	,0x2460	,0x2020	,0x0000), // '|' ➔ "†" U+2020 DAGGER
/*<!M><%hash><%braceleft>                                          */ DEADTRANS( L'{'	,0x2460	,0x222B	,0x0000), // '{' ➔ "∫" U+222B INTEGRAL math
/*<!M><%hash><%braceright>                                         */ DEADTRANS( L'}'	,0x2460	,0x03A9	,0x0000), // '}' ➔ "Ω" U+03A9 GREEK CAPITAL LETTER OMEGA
/*<!M><%hash><%bracketleft>                                        */ DEADTRANS( L'['	,0x2460	,0x27E8	,0x0000), // '[' ➔ "⟨" U+27E8 MATHEMATICAL LEFT ANGLE BRACKET math
/*<!M><%hash><%bracketright>                                       */ DEADTRANS( L']'	,0x2460	,0x27E9	,0x0000), // ']' ➔ "⟩" U+27E9 MATHEMATICAL RIGHT ANGLE BRACKET math
/*<!M><%hash><%circum>                                             */ DEADTRANS( L'^'	,0x2460	,0x26A0	,0x0000), // '^' ➔ "⚠" U+26A0 WARNING SIGN emoji, ergonomic mapping
/*<!M><%hash><%colon>                                              */ DEADTRANS( L':'	,0x2460	,0x22C5	,0x0000), // ':' ➔ "⋅" U+22C5 DOT OPERATOR math
/*<!M><%hash><%comma>                                              */ DEADTRANS( L','	,0x2460	,0x2764	,0x0000), // ',' ➔ "❤" U+2764 HEAVY BLACK HEART emoji, red heart, most-used in France
/*<!M><%hash><%dollar>                                             */ DEADTRANS( L'$'	,0x2460	,0x2423	,0x0000), // '$' ➔ "␣" U+2423 OPEN BOX, space character
/*<!M><%hash><%equal>                                              */ DEADTRANS( L'='	,0x2460	,0x2261	,0x0000), // '=' ➔ "≡" U+2261 IDENTICAL TO math
/*<!M><%hash><%exclam>                                             */ DEADTRANS( L'!'	,0x2460	,0x00A1	,0x0000), // '!' ➔ "¡" U+00A1 INVERTED EXCLAMATION MARK
/*<!M><%hash><%excsection>                                         */ DEADTRANS( 0x00A7	,0x2460	,0x02D0	,0x0000), // '§' ➔ "ː" U+02D0 MODIFIER LETTER TRIANGULAR COLON
/*<!M><%hash><%grave>                                              */ DEADTRANS( L'`'	,0x2460	,0x02BB	,0x0000), // '`' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%hash><%greater>                                            */ DEADTRANS( L'>'	,0x2460	,0x2714	,0x0000), // '>' ➔ "✔" U+2714 HEAVY CHECK MARK emoji
/*<!M><%hash><%less>                                               */ DEADTRANS( L'<'	,0x2460	,0x2713	,0x0000), // '<' ➔ "✓" U+2713 CHECK MARK
/*<!M><%hash><%minus>                                              */ DEADTRANS( L'-'	,0x2460	,0x2043	,0x0000), // '-' ➔ "⁃" U+2043 HYPHEN BULLET
/*<!M><%hash><%parenleft>                                          */ DEADTRANS( L'('	,0x2460	,0x2300	,0x0000), // '(' ➔ "⌀" U+2300 DIAMETER SIGN math
/*<!M><%hash><%parenright>                                         */ DEADTRANS( L')'	,0x2460	,0x2794	,0x0000), // ')' ➔ "➔" U+2794 HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*<!M><%hash><%percent>                                            */ DEADTRANS( L'%'	,0x2460	,0x2606	,0x0000), // '%' ➔ "☆" U+2606 WHITE STAR math
/*<!M><%hash><%period>                                             */ DEADTRANS( L'.'	,0x2460	,0x2027	,0x0000), // '.' ➔ "‧" U+2027 HYPHENATION POINT
/*<!M><%hash><%plus>                                               */ DEADTRANS( L'+'	,0x2460	,0x00B1	,0x0000), // '+' ➔ "±" U+00B1 PLUS-MINUS SIGN math
/*<!M><%hash><%question>                                           */ DEADTRANS( L'?'	,0x2460	,0x00BF	,0x0000), // '?' ➔ "¿" U+00BF INVERTED QUESTION MARK
/*<!M><%hash><%quotedbl>                                           */ DEADTRANS( L'"'	,0x2460	,0x2605	,0x0000), // '"' ➔ "★" U+2605 BLACK STAR math
/*<!M><%hash><%quotEuroSign>                                       */ DEADTRANS( 0x20AC	,0x2460	,0x2605	,0x0000), // '€' ➔ "★" U+2605 BLACK STAR math
/*<!M><%hash><%semicolon>                                          */ DEADTRANS( L';'	,0x2460	,0x02D0	,0x0000), // ';' ➔ "ː" U+02D0 MODIFIER LETTER TRIANGULAR COLON
/*<!M><%hash><%slash>                                              */ DEADTRANS( L'/'	,0x2460	,0x2718	,0x0000), // '/' ➔ "✘" U+2718 HEAVY BALLOT X
/*<!M><%hash><%tilde>                                              */ DEADTRANS( L'~'	,0x2460	,0x2243	,0x0000), // '~' ➔ "≃" U+2243 ASYMPTOTICALLY EQUAL TO math
/*<!M><%hash><%underscore>                                         */ DEADTRANS( L'_'	,0x2460	,0x2022	,0x0000), // '_' ➔ "•" U+2022 BULLET
/*<!M><%hash><A>                                                   */ DEADTRANS( L'A'	,0x2460	,0x00C6	,0x0000), // 'A' ➔ "Æ" U+00C6 LATIN CAPITAL LETTER AE
/*<!M><%hash><a>                                                   */ DEADTRANS( L'a'	,0x2460	,0x00E6	,0x0000), // 'a' ➔ "æ" U+00E6 LATIN SMALL LETTER AE
/*<!M><%hash><Adiaeresis>                                          */ DEADTRANS( 0x00C4	,0x2460	,0x00C5	,0x0000), // 'Ä' ➔ "Å" U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE shortcut for Swiss layout
/*<!M><%hash><adiaeresis>                                          */ DEADTRANS( 0x00E4	,0x2460	,0x00E5	,0x0000), // 'ä' ➔ "å" U+00E5 LATIN SMALL LETTER A WITH RING ABOVE shortcut for Swiss layout
/*<!M><%hash><Agrave>                                              */ DEADTRANS( 0x00C0	,0x2460	,0x00C5	,0x0000), // 'À' ➔ "Å" U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE shortcut
/*<!M><%hash><agrave>                                              */ DEADTRANS( 0x00E0	,0x2460	,0x00E5	,0x0000), // 'à' ➔ "å" U+00E5 LATIN SMALL LETTER A WITH RING ABOVE shortcut
/*<!M><%hash><B>                                                   */ DEADTRANS( L'B'	,0x2460	,0x0189	,0x0000), // 'B' ➔ "Ɖ" U+0189 LATIN CAPITAL LETTER AFRICAN D
/*<!M><%hash><b>                                                   */ DEADTRANS( L'b'	,0x2460	,0x0256	,0x0000), // 'b' ➔ "ɖ" U+0256 LATIN SMALL LETTER D WITH TAIL
/*<!M><%hash><C>                                                   */ DEADTRANS( L'C'	,0x2460	,0x0186	,0x0000), // 'C' ➔ "Ɔ" U+0186 LATIN CAPITAL LETTER OPEN O
/*<!M><%hash><c>                                                   */ DEADTRANS( L'c'	,0x2460	,0x0254	,0x0000), // 'c' ➔ "ɔ" U+0254 LATIN SMALL LETTER OPEN O
/*<!M><%hash><Ccedilla>                                            */ DEADTRANS( 0x00C7	,0x2460	,0x00D8	,0x0000), // 'Ç' ➔ "Ø" U+00D8 LATIN CAPITAL LETTER O WITH STROKE shortcut
/*<!M><%hash><ccedilla>                                            */ DEADTRANS( 0x00E7	,0x2460	,0x00F8	,0x0000), // 'ç' ➔ "ø" U+00F8 LATIN SMALL LETTER O WITH STROKE shortcut
/*<!M><%hash><D>                                                   */ DEADTRANS( L'D'	,0x2460	,0x00D0	,0x0000), // 'D' ➔ "Ð" U+00D0 LATIN CAPITAL LETTER ETH
/*<!M><%hash><d>                                                   */ DEADTRANS( L'd'	,0x2460	,0x00F0	,0x0000), // 'd' ➔ "ð" U+00F0 LATIN SMALL LETTER ETH
/*<!M><%hash><E>                                                   */ DEADTRANS( L'E'	,0x2460	,0x018E	,0x0000), // 'E' ➔ "Ǝ" U+018E LATIN CAPITAL LETTER REVERSED E
/*<!M><%hash><e>                                                   */ DEADTRANS( L'e'	,0x2460	,0x01DD	,0x0000), // 'e' ➔ "ǝ" U+01DD LATIN SMALL LETTER TURNED E
/*<!M><%hash><eacute>                                              */ DEADTRANS( 0x00E9	,0x2460	,0x00B2	,0x0000), // 'é' ➔ "²" U+00B2 SUPERSCRIPT TWO
/*<!M><%hash><Eacute>                                              */ DEADTRANS( 0x00C9	,0x2460	,0x00B3	,0x0000), // 'É' ➔ "³" U+00B3 SUPERSCRIPT THREE
/*<!M><%hash><Egrave>                                              */ DEADTRANS( 0x00C8	,0x2460	,0x00D1	,0x0000), // 'È' ➔ "Ñ" U+00D1 LATIN CAPITAL LETTER N WITH TILDE shortcut
/*<!M><%hash><egrave>                                              */ DEADTRANS( 0x00E8	,0x2460	,0x00F1	,0x0000), // 'è' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut
/*<!M><%hash><emdash>                                              */ DEADTRANS( 0x2014	,0x2460	,0x2E3B	,0x0000), // '—' ➔ "⸻" U+2E3B THREE-EM DASH
/*<!M><%hash><endash>                                              */ DEADTRANS( 0x2013	,0x2460	,0x2E3A	,0x0000), // '–' ➔ "⸺" U+2E3A TWO-EM DASH
/*<!M><%hash><F>                                                   */ DEADTRANS( L'F'	,0x2460	,0x0191	,0x0000), // 'F' ➔ "Ƒ" U+0191 LATIN CAPITAL LETTER F WITH HOOK
/*<!M><%hash><f>                                                   */ DEADTRANS( L'f'	,0x2460	,0x0192	,0x0000), // 'f' ➔ "ƒ" U+0192 LATIN SMALL LETTER F WITH HOOK
/*<!M><%hash><G>                                                   */ DEADTRANS( L'G'	,0x2460	,0x014A	,0x0000), // 'G' ➔ "Ŋ" U+014A LATIN CAPITAL LETTER ENG
/*<!M><%hash><g>                                                   */ DEADTRANS( L'g'	,0x2460	,0x014B	,0x0000), // 'g' ➔ "ŋ" U+014B LATIN SMALL LETTER ENG
/*<!M><%hash><guillemotleft>                                       */ DEADTRANS( 0x00AB	,0x2460	,0x0025	,0x0000), // '«' ➔ "%" U+0025 PERCENT SIGN
/*<!M><%hash><guillemotright>                                      */ DEADTRANS( 0x00BB	,0x2460	,0x00B5	,0x0000), // '»' ➔ "µ" U+00B5 MICRO SIGN
/*<!M><%hash><H>                                                   */ DEADTRANS( L'H'	,0x2460	,0x018F	,0x0000), // 'H' ➔ "Ə" U+018F LATIN CAPITAL LETTER SCHWA
/*<!M><%hash><h>                                                   */ DEADTRANS( L'h'	,0x2460	,0x0259	,0x0000), // 'h' ➔ "ə" U+0259 LATIN SMALL LETTER SCHWA
/*<!M><%hash><hyphen>                                              */ DEADTRANS( 0x00AD	,0x2460	,0x2015	,0x0000), // '­' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><I>                                                   */ DEADTRANS( L'I'	,0x2460	,0x0196	,0x0000), // 'I' ➔ "Ɩ" U+0196 LATIN CAPITAL LETTER IOTA
/*<!M><%hash><i>                                                   */ DEADTRANS( L'i'	,0x2460	,0x0269	,0x0000), // 'i' ➔ "ɩ" U+0269 LATIN SMALL LETTER IOTA
/*<!M><%hash><J>                                                   */ DEADTRANS( L'J'	,0x2460	,0x0132	,0x0000), // 'J' ➔ "Ĳ" U+0132 LATIN CAPITAL LIGATURE IJ
/*<!M><%hash><j>                                                   */ DEADTRANS( L'j'	,0x2460	,0x0133	,0x0000), // 'j' ➔ "ĳ" U+0133 LATIN SMALL LIGATURE IJ
/*<!M><%hash><k>                                                   */ DEADTRANS( L'k'	,0x2460	,0x0251	,0x0000), // 'k' ➔ "ɑ" U+0251 LATIN SMALL LETTER ALPHA
/*<!M><%hash><K>                                                   */ DEADTRANS( L'K'	,0x2460	,0x2C6D	,0x0000), // 'K' ➔ "Ɑ" U+2C6D LATIN CAPITAL LETTER ALPHA
/*<!M><%hash><l>                                                   */ DEADTRANS( L'l'	,0x2460	,0x02BF	,0x0000), // 'l' ➔ "ʿ" U+02BF MODIFIER LETTER LEFT HALF RING
/*<!M><%hash><L>                                                   */ DEADTRANS( L'L'	,0x2460	,0x2113	,0x0000), // 'L' ➔ "ℓ" U+2113 SCRIPT SMALL L
/*<!M><%hash><M>                                                   */ DEADTRANS( L'M'	,0x2460	,0x0294	,0x0000), // 'M' ➔ "ʔ" U+0294 LATIN LETTER GLOTTAL STOP
/*<!M><%hash><m>                                                   */ DEADTRANS( L'm'	,0x2460	,0x02BE	,0x0000), // 'm' ➔ "ʾ" U+02BE MODIFIER LETTER RIGHT HALF RING
/*<!M><%hash><N>                                                   */ DEADTRANS( L'N'	,0x2460	,0x019D	,0x0000), // 'N' ➔ "Ɲ" U+019D LATIN CAPITAL LETTER N WITH LEFT HOOK
/*<!M><%hash><n>                                                   */ DEADTRANS( L'n'	,0x2460	,0x0272	,0x0000), // 'n' ➔ "ɲ" U+0272 LATIN SMALL LETTER N WITH LEFT HOOK
/*<!M><%hash><ntilde>                                              */ DEADTRANS( 0x00F1	,0x2460	,0x2015	,0x0000), // 'ñ' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><Ntilde>                                              */ DEADTRANS( 0x00D1	,0x2460	,0x2015	,0x0000), // 'Ñ' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><O>                                                   */ DEADTRANS( L'O'	,0x2460	,0x0152	,0x0000), // 'O' ➔ "Œ" U+0152 LATIN CAPITAL LIGATURE OE
/*<!M><%hash><o>                                                   */ DEADTRANS( L'o'	,0x2460	,0x0153	,0x0000), // 'o' ➔ "œ" U+0153 LATIN SMALL LIGATURE OE
/*<!M><%hash><Odiaeresis>                                          */ DEADTRANS( 0x00D6	,0x2460	,0x00D8	,0x0000), // 'Ö' ➔ "Ø" U+00D8 LATIN CAPITAL LETTER O WITH STROKE shortcut for Swiss layout
/*<!M><%hash><odiaeresis>                                          */ DEADTRANS( 0x00F6	,0x2460	,0x00F8	,0x0000), // 'ö' ➔ "ø" U+00F8 LATIN SMALL LETTER O WITH STROKE shortcut for Swiss layout
/*<!M><%hash><oopen>                                               */ DEADTRANS( 0x0254	,0x2460	,0x2015	,0x0000), // 'ɔ' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><Oopen>                                               */ DEADTRANS( 0x0186	,0x2460	,0x2015	,0x0000), // 'Ɔ' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><P>                                                   */ DEADTRANS( L'P'	,0x2460	,0x00B7	,0x0000), // 'P' ➔ "·" U+00B7 MIDDLE DOT
/*<!M><%hash><p>                                                   */ DEADTRANS( L'p'	,0x2460	,0x00B7	,0x0000), // 'p' ➔ "·" U+00B7 MIDDLE DOT
/*<!M><%hash><Q>                                                   */ DEADTRANS( L'Q'	,0x2460	,0x0241	,0x0000), // 'Q' ➔ "Ɂ" U+0241 LATIN CAPITAL LETTER GLOTTAL STOP
/*<!M><%hash><q>                                                   */ DEADTRANS( L'q'	,0x2460	,0x0242	,0x0000), // 'q' ➔ "ɂ" U+0242 LATIN SMALL LETTER GLOTTAL STOP
/*<!M><%hash><R>                                                   */ DEADTRANS( L'R'	,0x2460	,0x211F	,0x0000), // 'R' ➔ "℟" U+211F RESPONSE
/*<!M><%hash><r>                                                   */ DEADTRANS( L'r'	,0x2460	,0x211F	,0x0000), // 'r' ➔ "℟" U+211F RESPONSE
/*<!M><%hash><s>                                                   */ DEADTRANS( L's'	,0x2460	,0x00DF	,0x0000), // 's' ➔ "ß" U+00DF LATIN SMALL LETTER SHARP S
/*<!M><%hash><S>                                                   */ DEADTRANS( L'S'	,0x2460	,0x1E9E	,0x0000), // 'S' ➔ "ẞ" U+1E9E LATIN CAPITAL LETTER SHARP S
/*<!M><%hash><T>                                                   */ DEADTRANS( L'T'	,0x2460	,0x00DE	,0x0000), // 'T' ➔ "Þ" U+00DE LATIN CAPITAL LETTER THORN
/*<!M><%hash><t>                                                   */ DEADTRANS( L't'	,0x2460	,0x00FE	,0x0000), // 't' ➔ "þ" U+00FE LATIN SMALL LETTER THORN
/*<!M><%hash><twosuperior>                                         */ DEADTRANS( 0x00B2	,0x2460	,0x0026	,0x0000), // '²' ➔ "&" U+0026 AMPERSAND
/*<!M><%hash><U2011>                                               */ DEADTRANS( 0x2011	,0x2460	,0x2015	,0x0000), // '‑' ➔ "―" U+2015 HORIZONTAL BAR
/*<!M><%hash><U2039>                                               */ DEADTRANS( 0x2039	,0x2460	,0x00A8	,0x0000), // '‹' ➔ "¨" U+00A8 DIAERESIS
/*<!M><%hash><U203A>                                               */ DEADTRANS( 0x203A	,0x2460	,0x00A3	,0x0000), // '›' ➔ "£" U+00A3 POUND SIGN
/*<!M><%hash><U2212>                                               */ DEADTRANS( 0x2212	,0x2460	,0x2012	,0x0000), // '−' ➔ "‒" U+2012 FIGURE DASH
/*<!M><%hash><U>                                                   */ DEADTRANS( L'U'	,0x2460	,0x01B2	,0x0000), // 'U' ➔ "Ʋ" U+01B2 LATIN CAPITAL LETTER V WITH HOOK
/*<!M><%hash><u>                                                   */ DEADTRANS( L'u'	,0x2460	,0x028B	,0x0000), // 'u' ➔ "ʋ" U+028B LATIN SMALL LETTER V WITH HOOK
/*<!M><%hash><Udiaeresis>                                          */ DEADTRANS( 0x00DC	,0x2460	,0x00D1	,0x0000), // 'Ü' ➔ "Ñ" U+00D1 LATIN CAPITAL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><udiaeresis>                                          */ DEADTRANS( 0x00FC	,0x2460	,0x00F1	,0x0000), // 'ü' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE shortcut for Swiss layout
/*<!M><%hash><V>                                                   */ DEADTRANS( L'V'	,0x2460	,0x2123	,0x0000), // 'V' ➔ "℣" U+2123 VERSICLE
/*<!M><%hash><v>                                                   */ DEADTRANS( L'v'	,0x2460	,0x2123	,0x0000), // 'v' ➔ "℣" U+2123 VERSICLE
/*<!M><%hash><W>                                                   */ DEADTRANS( L'W'	,0x2460	,0x01A9	,0x0000), // 'W' ➔ "Ʃ" U+01A9 LATIN CAPITAL LETTER ESH
/*<!M><%hash><w>                                                   */ DEADTRANS( L'w'	,0x2460	,0x0283	,0x0000), // 'w' ➔ "ʃ" U+0283 LATIN SMALL LETTER ESH
/*<!M><%hash><X>                                                   */ DEADTRANS( L'X'	,0x2460	,0x0190	,0x0000), // 'X' ➔ "Ɛ" U+0190 LATIN CAPITAL LETTER OPEN E
/*<!M><%hash><x>                                                   */ DEADTRANS( L'x'	,0x2460	,0x025B	,0x0000), // 'x' ➔ "ɛ" U+025B LATIN SMALL LETTER OPEN E
/*<!M><%hash><Y>                                                   */ DEADTRANS( L'Y'	,0x2460	,0x01B1	,0x0000), // 'Y' ➔ "Ʊ" U+01B1 LATIN CAPITAL LETTER UPSILON
/*<!M><%hash><y>                                                   */ DEADTRANS( L'y'	,0x2460	,0x028A	,0x0000), // 'y' ➔ "ʊ" U+028A LATIN SMALL LETTER UPSILON
/*<!M><%hash><Z>                                                   */ DEADTRANS( L'Z'	,0x2460	,0x01B7	,0x0000), // 'Z' ➔ "Ʒ" U+01B7 LATIN CAPITAL LETTER EZH
/*<!M><%hash><z>                                                   */ DEADTRANS( L'z'	,0x2460	,0x0292	,0x0000), // 'z' ➔ "ʒ" U+0292 LATIN SMALL LETTER EZH
/*<!M><%hash><~nbspace>                                            */ DEADTRANS( 0x00A0	,0x2460	,0x2001	,0x0000), // ' ' ➔ " " U+2001 EM QUAD
/*<!M><%hash><~nbthinspace>                                        */ DEADTRANS( 0x202F	,0x2460	,0x200A	,0x0000), // ' ' ➔ " " U+200A HAIR SPACE
/*<!M><%hash><~space>                                              */ DEADTRANS( L' '	,0x2460	,0x2003	,0x0000), // ' ' ➔ " " U+2003 EM SPACE
/*<!M><%less><%aprightsingquotmark>                                */ DEADTRANS( 0x2019	,0x00EA	,0x2018	,0x0000), // '’' ➔ "‘" U+2018 LEFT SINGLE QUOTATION MARK, single turned comma quotation mark
/*<!M><%less><%braceright>                                         */ DEADTRANS( L'}'	,0x00EA	,0x27E9	,0x0000), // '}' ➔ "⟩" U+27E9 MATHEMATICAL RIGHT ANGLE BRACKET
/*<!M><%less><%comma>                                              */ DEADTRANS( L','	,0x00EA	,0x02BC	,0x0000), // ',' ➔ "ʼ" U+02BC MODIFIER LETTER APOSTROPHE
/*<!M><%less><%dollar>                                             */ DEADTRANS( L'$'	,0x00EA	,0x1DCD	,0x0000), // '$' ➔ "᷍" U+1DCD COMBINING DOUBLE CIRCUMFLEX ABOVE
/*<!M><%less><%percent>                                            */ DEADTRANS( L'%'	,0x00EA	,0x2030	,0x0000), // '%' ➔ "‰" U+2030 PER MILLE SIGN
/*<!M><%less><%plus>                                               */ DEADTRANS( L'+'	,0x00EA	,0x2A23	,0x0000), // '+' ➔ "⨣" U+2A23 PLUS SIGN WITH CIRCUMFLEX ACCENT ABOVE
/*<!M><%less><%question>                                           */ DEADTRANS( L'?'	,0x00EA	,0x203D	,0x0000), // '?' ➔ "‽" U+203D INTERROBANG
/*<!M><%less><%quotedbl>                                           */ DEADTRANS( L'"'	,0x00EA	,0x201C	,0x0000), // '"' ➔ "“" U+201C LEFT DOUBLE QUOTATION MARK, double turned comma quotation mark
/*<!M><%less><%quotEuroSign>                                       */ DEADTRANS( 0x20AC	,0x00EA	,0x201C	,0x0000), // '€' ➔ "“" U+201C LEFT DOUBLE QUOTATION MARK, double turned comma quotation mark
/*<!M><%less><%semicolon>                                          */ DEADTRANS( L';'	,0x00EA	,0x2027	,0x0000), // ';' ➔ "‧" U+2027 HYPHENATION POINT
/*<!M><%less><A>                                                   */ DEADTRANS( L'A'	,0x00EA	,0x00C2	,0x0000), // 'A' ➔ "Â" U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX
/*<!M><%less><a>                                                   */ DEADTRANS( L'a'	,0x00EA	,0x00E2	,0x0000), // 'a' ➔ "â" U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX
/*<!M><%less><Agrave>                                              */ DEADTRANS( 0x00C0	,0x00EA	,0x1EA6	,0x0000), // 'À' ➔ "Ầ" U+1EA6 LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND GRAVE
/*<!M><%less><agrave>                                              */ DEADTRANS( 0x00E0	,0x00EA	,0x1EA7	,0x0000), // 'à' ➔ "ầ" U+1EA7 LATIN SMALL LETTER A WITH CIRCUMFLEX AND GRAVE
/*<!M><%less><B>                                                   */ DEADTRANS( L'B'	,0x00EA	,0x016C	,0x0000), // 'B' ➔ "Ŭ" U+016C LATIN CAPITAL LETTER U WITH BREVE
/*<!M><%less><b>                                                   */ DEADTRANS( L'b'	,0x00EA	,0x016D	,0x0000), // 'b' ➔ "ŭ" U+016D LATIN SMALL LETTER U WITH BREVE
/*<!M><%less><C>                                                   */ DEADTRANS( L'C'	,0x00EA	,0x0108	,0x0000), // 'C' ➔ "Ĉ" U+0108 LATIN CAPITAL LETTER C WITH CIRCUMFLEX
/*<!M><%less><c>                                                   */ DEADTRANS( L'c'	,0x00EA	,0x0109	,0x0000), // 'c' ➔ "ĉ" U+0109 LATIN SMALL LETTER C WITH CIRCUMFLEX
/*<!M><%less><Ccedilla>                                            */ DEADTRANS( 0x00C7	,0x00EA	,0x00D1	,0x0000), // 'Ç' ➔ "Ñ" U+00D1 LATIN CAPITAL LETTER N WITH TILDE
/*<!M><%less><ccedilla>                                            */ DEADTRANS( 0x00E7	,0x00EA	,0x00F1	,0x0000), // 'ç' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE
/*<!M><%less><D>                                                   */ DEADTRANS( L'D'	,0x00EA	,0x1AB0	,0x0000), // 'D' ➔ "᪰" U+1AB0 COMBINING DOUBLED CIRCUMFLEX ACCENT
/*<!M><%less><d>                                                   */ DEADTRANS( L'd'	,0x00EA	,0x1AB0	,0x0000), // 'd' ➔ "᪰" U+1AB0 COMBINING DOUBLED CIRCUMFLEX ACCENT
/*<!M><%less><E>                                                   */ DEADTRANS( L'E'	,0x00EA	,0x00CA	,0x0000), // 'E' ➔ "Ê" U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!M><%less><e>                                                   */ DEADTRANS( L'e'	,0x00EA	,0x00EA	,0x0000), // 'e' ➔ "ê" U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX
/*<!M><%less><Eacute>                                              */ DEADTRANS( 0x00C9	,0x00EA	,0x1EBE	,0x0000), // 'É' ➔ "Ế" U+1EBE LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND ACUTE
/*<!M><%less><eacute>                                              */ DEADTRANS( 0x00E9	,0x00EA	,0x1EBF	,0x0000), // 'é' ➔ "ế" U+1EBF LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*<!M><%less><Egrave>                                              */ DEADTRANS( 0x00C8	,0x00EA	,0x1EC0	,0x0000), // 'È' ➔ "Ề" U+1EC0 LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND GRAVE
/*<!M><%less><egrave>                                              */ DEADTRANS( 0x00E8	,0x00EA	,0x1EC1	,0x0000), // 'è' ➔ "ề" U+1EC1 LATIN SMALL LETTER E WITH CIRCUMFLEX AND GRAVE
/*<!M><%less><emdash>                                              */ DEADTRANS( 0x2014	,0x00EA	,0x1DCD	,0x0000), // '—' ➔ "᷍" U+1DCD COMBINING DOUBLE CIRCUMFLEX ABOVE
/*<!M><%less><F>                                                   */ DEADTRANS( L'F'	,0x00EA	,0x0053	,0x0000), // 'F' ➔ "S" U+0053 LATIN CAPITAL LETTER S
/*<!M><%less><f>                                                   */ DEADTRANS( L'f'	,0x00EA	,0x017F	,0x0000), // 'f' ➔ "ſ" U+017F LATIN SMALL LETTER LONG S
/*<!M><%less><G>                                                   */ DEADTRANS( L'G'	,0x00EA	,0x011C	,0x0000), // 'G' ➔ "Ĝ" U+011C LATIN CAPITAL LETTER G WITH CIRCUMFLEX
/*<!M><%less><g>                                                   */ DEADTRANS( L'g'	,0x00EA	,0x011D	,0x0000), // 'g' ➔ "ĝ" U+011D LATIN SMALL LETTER G WITH CIRCUMFLEX
/*<!M><%less><H>                                                   */ DEADTRANS( L'H'	,0x00EA	,0x0124	,0x0000), // 'H' ➔ "Ĥ" U+0124 LATIN CAPITAL LETTER H WITH CIRCUMFLEX
/*<!M><%less><h>                                                   */ DEADTRANS( L'h'	,0x00EA	,0x0125	,0x0000), // 'h' ➔ "ĥ" U+0125 LATIN SMALL LETTER H WITH CIRCUMFLEX
/*<!M><%less><I>                                                   */ DEADTRANS( L'I'	,0x00EA	,0x00CE	,0x0000), // 'I' ➔ "Î" U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX
/*<!M><%less><i>                                                   */ DEADTRANS( L'i'	,0x00EA	,0x00EE	,0x0000), // 'i' ➔ "î" U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX
/*<!M><%less><J>                                                   */ DEADTRANS( L'J'	,0x00EA	,0x0134	,0x0000), // 'J' ➔ "Ĵ" U+0134 LATIN CAPITAL LETTER J WITH CIRCUMFLEX
/*<!M><%less><j>                                                   */ DEADTRANS( L'j'	,0x00EA	,0x0135	,0x0000), // 'j' ➔ "ĵ" U+0135 LATIN SMALL LETTER J WITH CIRCUMFLEX
/*<!M><%less><O>                                                   */ DEADTRANS( L'O'	,0x00EA	,0x00D4	,0x0000), // 'O' ➔ "Ô" U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX
/*<!M><%less><o>                                                   */ DEADTRANS( L'o'	,0x00EA	,0x00F4	,0x0000), // 'o' ➔ "ô" U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX
/*<!M><%less><S>                                                   */ DEADTRANS( L'S'	,0x00EA	,0x015C	,0x0000), // 'S' ➔ "Ŝ" U+015C LATIN CAPITAL LETTER S WITH CIRCUMFLEX
/*<!M><%less><s>                                                   */ DEADTRANS( L's'	,0x00EA	,0x015D	,0x0000), // 's' ➔ "ŝ" U+015D LATIN SMALL LETTER S WITH CIRCUMFLEX
/*<!M><%less><threesuperior>                                       */ DEADTRANS( 0x00B3	,0x00EA	,0x2033	,0x0000), // '³' ➔ "″" U+2033 DOUBLE PRIME
/*<!M><%less><twosuperior>                                         */ DEADTRANS( 0x00B2	,0x00EA	,0x2032	,0x0000), // '²' ➔ "′" U+2032 PRIME
/*<!M><%less><U>                                                   */ DEADTRANS( L'U'	,0x00EA	,0x00DB	,0x0000), // 'U' ➔ "Û" U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX
/*<!M><%less><u>                                                   */ DEADTRANS( L'u'	,0x00EA	,0x00FB	,0x0000), // 'u' ➔ "û" U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX
/*<!M><%less><Ugrave>                                              */ DEADTRANS( 0x00D9	,0x00EA	,0x016C	,0x0000), // 'Ù' ➔ "Ŭ" U+016C LATIN CAPITAL LETTER U WITH BREVE
/*<!M><%less><ugrave>                                              */ DEADTRANS( 0x00F9	,0x00EA	,0x016D	,0x0000), // 'ù' ➔ "ŭ" U+016D LATIN SMALL LETTER U WITH BREVE
/*<!M><%less><W>                                                   */ DEADTRANS( L'W'	,0x00EA	,0x0174	,0x0000), // 'W' ➔ "Ŵ" U+0174 LATIN CAPITAL LETTER W WITH CIRCUMFLEX
/*<!M><%less><w>                                                   */ DEADTRANS( L'w'	,0x00EA	,0x0175	,0x0000), // 'w' ➔ "ŵ" U+0175 LATIN SMALL LETTER W WITH CIRCUMFLEX
/*<!M><%less><Y>                                                   */ DEADTRANS( L'Y'	,0x00EA	,0x0176	,0x0000), // 'Y' ➔ "Ŷ" U+0176 LATIN CAPITAL LETTER Y WITH CIRCUMFLEX
/*<!M><%less><y>                                                   */ DEADTRANS( L'y'	,0x00EA	,0x0177	,0x0000), // 'y' ➔ "ŷ" U+0177 LATIN SMALL LETTER Y WITH CIRCUMFLEX
/*<!M><%less><Z>                                                   */ DEADTRANS( L'Z'	,0x00EA	,0x1E90	,0x0000), // 'Z' ➔ "Ẑ" U+1E90 LATIN CAPITAL LETTER Z WITH CIRCUMFLEX
/*<!M><%less><z>                                                   */ DEADTRANS( L'z'	,0x00EA	,0x1E91	,0x0000), // 'z' ➔ "ẑ" U+1E91 LATIN SMALL LETTER Z WITH CIRCUMFLEX
/*<!M><%less><~nbspace>                                            */ DEADTRANS( 0x00A0	,0x00EA	,0x005E	,0x0000), // ' ' ➔ "^" U+005E CIRCUMFLEX ACCENT
/*<!M><%less><~nbthinspace>                                        */ DEADTRANS( 0x202F	,0x00EA	,0x02C6	,0x0000), // ' ' ➔ "ˆ" U+02C6 MODIFIER LETTER CIRCUMFLEX ACCENT
/*<!M><%less><~space>                                              */ DEADTRANS( L' '	,0x00EA	,0x0302	,0x0000), // ' ' ➔ "̂" U+0302 COMBINING CIRCUMFLEX ACCENT
/*<!M><%less><~spacezerowidth>                                     */ DEADTRANS( 0x200B	,0x00EA	,0x0302	,0x0000), // '​' ➔ "̂" U+0302 COMBINING CIRCUMFLEX ACCENT
/*<!M><%minus><%bracketleft>                                       */ DEADTRANS( L'['	,0x024D	,0x2045	,0x0000), // '[' ➔ "⁅" U+2045 LEFT SQUARE BRACKET WITH QUILL
/*<!M><%minus><%bracketright>                                      */ DEADTRANS( L']'	,0x024D	,0x2046	,0x0000), // ']' ➔ "⁆" U+2046 RIGHT SQUARE BRACKET WITH QUILL
/*<!M><%minus><%question>                                          */ DEADTRANS( L'?'	,0x024D	,0x02A1	,0x0000), // '?' ➔ "ʡ" U+02A1 LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!M><%minus><2>                                                  */ DEADTRANS( L'2'	,0x024D	,0x01BB	,0x0000), // '2' ➔ "ƻ" U+01BB LATIN LETTER TWO WITH STROKE
/*<!M><%minus><7>                                                  */ DEADTRANS( L'7'	,0x024D	,0x02A1	,0x0000), // '7' ➔ "ʡ" U+02A1 LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!M><%minus><A>                                                  */ DEADTRANS( L'A'	,0x024D	,0xA73A	,0x0000), // 'A' ➔ "Ꜻ" U+A73A LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*<!M><%minus><a>                                                  */ DEADTRANS( L'a'	,0x024D	,0xA73B	,0x0000), // 'a' ➔ "ꜻ" U+A73B LATIN SMALL LETTER AV WITH HORIZONTAL BAR
/*<!M><%minus><b>                                                  */ DEADTRANS( L'b'	,0x024D	,0x0180	,0x0000), // 'b' ➔ "ƀ" U+0180 LATIN SMALL LETTER B WITH STROKE
/*<!M><%minus><B>                                                  */ DEADTRANS( L'B'	,0x024D	,0x0243	,0x0000), // 'B' ➔ "Ƀ" U+0243 LATIN CAPITAL LETTER B WITH STROKE
/*<!M><%minus><C>                                                  */ DEADTRANS( L'C'	,0x024D	,0xA792	,0x0000), // 'C' ➔ "Ꞓ" U+A792 LATIN CAPITAL LETTER C WITH BAR
/*<!M><%minus><c>                                                  */ DEADTRANS( L'c'	,0x024D	,0xA793	,0x0000), // 'c' ➔ "ꞓ" U+A793 LATIN SMALL LETTER C WITH BAR
/*<!M><%minus><D>                                                  */ DEADTRANS( L'D'	,0x024D	,0x0110	,0x0000), // 'D' ➔ "Đ" U+0110 LATIN CAPITAL LETTER D WITH STROKE
/*<!M><%minus><d>                                                  */ DEADTRANS( L'd'	,0x024D	,0x0111	,0x0000), // 'd' ➔ "đ" U+0111 LATIN SMALL LETTER D WITH STROKE
/*<!M><%minus><e>                                                  */ DEADTRANS( L'e'	,0x024D	,0xAB33	,0x0000), // 'e' ➔ "ꬳ" U+AB33 LATIN SMALL LETTER BARRED E
/*<!M><%minus><F>                                                  */ DEADTRANS( L'F'	,0x024D	,0xA798	,0x0000), // 'F' ➔ "Ꞙ" U+A798 LATIN CAPITAL LETTER F WITH STROKE
/*<!M><%minus><f>                                                  */ DEADTRANS( L'f'	,0x024D	,0xA799	,0x0000), // 'f' ➔ "ꞙ" U+A799 LATIN SMALL LETTER F WITH STROKE
/*<!M><%minus><G>                                                  */ DEADTRANS( L'G'	,0x024D	,0x01E4	,0x0000), // 'G' ➔ "Ǥ" U+01E4 LATIN CAPITAL LETTER G WITH STROKE
/*<!M><%minus><g>                                                  */ DEADTRANS( L'g'	,0x024D	,0x01E5	,0x0000), // 'g' ➔ "ǥ" U+01E5 LATIN SMALL LETTER G WITH STROKE
/*<!M><%minus><H>                                                  */ DEADTRANS( L'H'	,0x024D	,0x0126	,0x0000), // 'H' ➔ "Ħ" U+0126 LATIN CAPITAL LETTER H WITH STROKE
/*<!M><%minus><h>                                                  */ DEADTRANS( L'h'	,0x024D	,0x0127	,0x0000), // 'h' ➔ "ħ" U+0127 LATIN SMALL LETTER H WITH STROKE
/*<!M><%minus><I>                                                  */ DEADTRANS( L'I'	,0x024D	,0x0197	,0x0000), // 'I' ➔ "Ɨ" U+0197 LATIN CAPITAL LETTER I WITH STROKE
/*<!M><%minus><i>                                                  */ DEADTRANS( L'i'	,0x024D	,0x0268	,0x0000), // 'i' ➔ "ɨ" U+0268 LATIN SMALL LETTER I WITH STROKE
/*<!M><%minus><J>                                                  */ DEADTRANS( L'J'	,0x024D	,0x0248	,0x0000), // 'J' ➔ "Ɉ" U+0248 LATIN CAPITAL LETTER J WITH STROKE
/*<!M><%minus><j>                                                  */ DEADTRANS( L'j'	,0x024D	,0x0249	,0x0000), // 'j' ➔ "ɉ" U+0249 LATIN SMALL LETTER J WITH STROKE
/*<!M><%minus><K>                                                  */ DEADTRANS( L'K'	,0x024D	,0xA740	,0x0000), // 'K' ➔ "Ꝁ" U+A740 LATIN CAPITAL LETTER K WITH STROKE
/*<!M><%minus><k>                                                  */ DEADTRANS( L'k'	,0x024D	,0xA741	,0x0000), // 'k' ➔ "ꝁ" U+A741 LATIN SMALL LETTER K WITH STROKE
/*<!M><%minus><l>                                                  */ DEADTRANS( L'l'	,0x024D	,0x019A	,0x0000), // 'l' ➔ "ƚ" U+019A LATIN SMALL LETTER L WITH BAR
/*<!M><%minus><L>                                                  */ DEADTRANS( L'L'	,0x024D	,0x023D	,0x0000), // 'L' ➔ "Ƚ" U+023D LATIN CAPITAL LETTER L WITH BAR
/*<!M><%minus><O>                                                  */ DEADTRANS( L'O'	,0x024D	,0x019F	,0x0000), // 'O' ➔ "Ɵ" U+019F LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*<!M><%minus><o>                                                  */ DEADTRANS( L'o'	,0x024D	,0x0275	,0x0000), // 'o' ➔ "ɵ" U+0275 LATIN SMALL LETTER BARRED O
/*<!M><%minus><p>                                                  */ DEADTRANS( L'p'	,0x024D	,0x1D7D	,0x0000), // 'p' ➔ "ᵽ" U+1D7D LATIN SMALL LETTER P WITH STROKE
/*<!M><%minus><P>                                                  */ DEADTRANS( L'P'	,0x024D	,0x2C63	,0x0000), // 'P' ➔ "Ᵽ" U+2C63 LATIN CAPITAL LETTER P WITH STROKE
/*<!M><%minus><Q>                                                  */ DEADTRANS( L'Q'	,0x024D	,0x01BE	,0x0000), // 'Q' ➔ "ƾ" U+01BE LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*<!M><%minus><q>                                                  */ DEADTRANS( L'q'	,0x024D	,0x02A1	,0x0000), // 'q' ➔ "ʡ" U+02A1 LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!M><%minus><R>                                                  */ DEADTRANS( L'R'	,0x024D	,0x024C	,0x0000), // 'R' ➔ "Ɍ" U+024C LATIN CAPITAL LETTER R WITH STROKE
/*<!M><%minus><r>                                                  */ DEADTRANS( L'r'	,0x024D	,0x024D	,0x0000), // 'r' ➔ "ɍ" U+024D LATIN SMALL LETTER R WITH STROKE
/*<!M><%minus><S>                                                  */ DEADTRANS( L'S'	,0x024D	,0xA7C9	,0x0000), // 'S' ➔ "Ꟊ" U+A7C9 LATIN CAPITAL LETTER S WITH SHORT STROKE OVERLAY
/*<!M><%minus><s>                                                  */ DEADTRANS( L's'	,0x024D	,0xA7CA	,0x0000), // 's' ➔ "ꟊ" U+A7CA LATIN SMALL LETTER S WITH SHORT STROKE OVERLAY
/*<!M><%minus><T>                                                  */ DEADTRANS( L'T'	,0x024D	,0x0166	,0x0000), // 'T' ➔ "Ŧ" U+0166 LATIN CAPITAL LETTER T WITH STROKE
/*<!M><%minus><t>                                                  */ DEADTRANS( L't'	,0x024D	,0x0167	,0x0000), // 't' ➔ "ŧ" U+0167 LATIN SMALL LETTER T WITH STROKE
/*<!M><%minus><U>                                                  */ DEADTRANS( L'U'	,0x024D	,0x0244	,0x0000), // 'U' ➔ "Ʉ" U+0244 LATIN CAPITAL LETTER U BAR
/*<!M><%minus><u>                                                  */ DEADTRANS( L'u'	,0x024D	,0x0289	,0x0000), // 'u' ➔ "ʉ" U+0289 LATIN SMALL LETTER U BAR
/*<!M><%minus><Y>                                                  */ DEADTRANS( L'Y'	,0x024D	,0x024E	,0x0000), // 'Y' ➔ "Ɏ" U+024E LATIN CAPITAL LETTER Y WITH STROKE
/*<!M><%minus><y>                                                  */ DEADTRANS( L'y'	,0x024D	,0x024F	,0x0000), // 'y' ➔ "ɏ" U+024F LATIN SMALL LETTER Y WITH STROKE
/*<!M><%minus><Z>                                                  */ DEADTRANS( L'Z'	,0x024D	,0x01B5	,0x0000), // 'Z' ➔ "Ƶ" U+01B5 LATIN CAPITAL LETTER Z WITH STROKE
/*<!M><%minus><z>                                                  */ DEADTRANS( L'z'	,0x024D	,0x01B6	,0x0000), // 'z' ➔ "ƶ" U+01B6 LATIN SMALL LETTER Z WITH STROKE
/*<!M><%minus><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x024D	,0x02D7	,0x0000), // ' ' ➔ "˗" U+02D7 MODIFIER LETTER MINUS SIGN
/*<!M><%minus><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x024D	,0x02D7	,0x0000), // ' ' ➔ "˗" U+02D7 MODIFIER LETTER MINUS SIGN
/*<!M><%minus><~space>                                             */ DEADTRANS( L' '	,0x024D	,0x0335	,0x0000), // ' ' ➔ "̵" U+0335 COMBINING SHORT STROKE OVERLAY
/*<!M><%minus><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x024D	,0x0335	,0x0000), // '​' ➔ "̵" U+0335 COMBINING SHORT STROKE OVERLAY
/*<!M><%parenleft><%dollar>                                        */ DEADTRANS( L'$'	,0x0213	,0x0361	,0x0000), // '$' ➔ "͡" U+0361 COMBINING DOUBLE INVERTED BREVE
/*<!M><%parenleft><A>                                              */ DEADTRANS( L'A'	,0x0213	,0x0202	,0x0000), // 'A' ➔ "Ȃ" U+0202 LATIN CAPITAL LETTER A WITH INVERTED BREVE
/*<!M><%parenleft><a>                                              */ DEADTRANS( L'a'	,0x0213	,0x0203	,0x0000), // 'a' ➔ "ȃ" U+0203 LATIN SMALL LETTER A WITH INVERTED BREVE
/*<!M><%parenleft><C>                                              */ DEADTRANS( L'C'	,0x0213	,0x02D3	,0x0000), // 'C' ➔ "˓" U+02D3 MODIFIER LETTER CENTRED LEFT HALF RING
/*<!M><%parenleft><c>                                              */ DEADTRANS( L'c'	,0x0213	,0x02D3	,0x0000), // 'c' ➔ "˓" U+02D3 MODIFIER LETTER CENTRED LEFT HALF RING
/*<!M><%parenleft><E>                                              */ DEADTRANS( L'E'	,0x0213	,0x0206	,0x0000), // 'E' ➔ "Ȇ" U+0206 LATIN CAPITAL LETTER E WITH INVERTED BREVE
/*<!M><%parenleft><e>                                              */ DEADTRANS( L'e'	,0x0213	,0x0207	,0x0000), // 'e' ➔ "ȇ" U+0207 LATIN SMALL LETTER E WITH INVERTED BREVE
/*<!M><%parenleft><emdash>                                         */ DEADTRANS( 0x2014	,0x0213	,0x0361	,0x0000), // '—' ➔ "͡" U+0361 COMBINING DOUBLE INVERTED BREVE
/*<!M><%parenleft><F>                                              */ DEADTRANS( L'F'	,0x0213	,0xDF00	,0x0000), // High surrogate: D837; 'F' ➔ "𝼀" U+1DF00 LATIN SMALL LETTER FENG DIGRAPH WITH TRILL
/*<!M><%parenleft><f>                                              */ DEADTRANS( L'f'	,0x0213	,0xDF00	,0x0000), // High surrogate: D837; 'f' ➔ "𝼀" U+1DF00 LATIN SMALL LETTER FENG DIGRAPH WITH TRILL
/*<!M><%parenleft><G>                                              */ DEADTRANS( L'G'	,0x0213	,0x2050	,0x0000), // 'G' ➔ "⁐" U+2050 CLOSE UP
/*<!M><%parenleft><g>                                              */ DEADTRANS( L'g'	,0x0213	,0x2050	,0x0000), // 'g' ➔ "⁐" U+2050 CLOSE UP
/*<!M><%parenleft><I>                                              */ DEADTRANS( L'I'	,0x0213	,0x020A	,0x0000), // 'I' ➔ "Ȋ" U+020A LATIN CAPITAL LETTER I WITH INVERTED BREVE
/*<!M><%parenleft><i>                                              */ DEADTRANS( L'i'	,0x0213	,0x020B	,0x0000), // 'i' ➔ "ȋ" U+020B LATIN SMALL LETTER I WITH INVERTED BREVE
/*<!M><%parenleft><O>                                              */ DEADTRANS( L'O'	,0x0213	,0x020E	,0x0000), // 'O' ➔ "Ȏ" U+020E LATIN CAPITAL LETTER O WITH INVERTED BREVE
/*<!M><%parenleft><o>                                              */ DEADTRANS( L'o'	,0x0213	,0x020F	,0x0000), // 'o' ➔ "ȏ" U+020F LATIN SMALL LETTER O WITH INVERTED BREVE
/*<!M><%parenleft><R>                                              */ DEADTRANS( L'R'	,0x0213	,0x0212	,0x0000), // 'R' ➔ "Ȓ" U+0212 LATIN CAPITAL LETTER R WITH INVERTED BREVE
/*<!M><%parenleft><r>                                              */ DEADTRANS( L'r'	,0x0213	,0x0213	,0x0000), // 'r' ➔ "ȓ" U+0213 LATIN SMALL LETTER R WITH INVERTED BREVE
/*<!M><%parenleft><U>                                              */ DEADTRANS( L'U'	,0x0213	,0x0216	,0x0000), // 'U' ➔ "Ȗ" U+0216 LATIN CAPITAL LETTER U WITH INVERTED BREVE
/*<!M><%parenleft><u>                                              */ DEADTRANS( L'u'	,0x0213	,0x0217	,0x0000), // 'u' ➔ "ȗ" U+0217 LATIN SMALL LETTER U WITH INVERTED BREVE
/*<!M><%parenleft><~nbspace>                                       */ DEADTRANS( 0x00A0	,0x0213	,0xAB5B	,0x0000), // ' ' ➔ "꭛" U+AB5B MODIFIER BREVE WITH INVERTED BREVE
/*<!M><%parenleft><~nbthinspace>                                   */ DEADTRANS( 0x202F	,0x0213	,0xAB5B	,0x0000), // ' ' ➔ "꭛" U+AB5B MODIFIER BREVE WITH INVERTED BREVE
/*<!M><%parenleft><~space>                                         */ DEADTRANS( L' '	,0x0213	,0x0311	,0x0000), // ' ' ➔ "̑" U+0311 COMBINING INVERTED BREVE
/*<!M><%parenleft><~spacezerowidth>                                */ DEADTRANS( 0x200B	,0x0213	,0x0311	,0x0000), // '​' ➔ "̑" U+0311 COMBINING INVERTED BREVE
/*<!M><%parenright><%bar>                                          */ DEADTRANS( L'|'	,0x0115	,0x1DCB	,0x0000), // '|' ➔ "᷋" U+1DCB COMBINING BREVE-MACRON
/*<!M><%parenright><%dollar>                                       */ DEADTRANS( L'$'	,0x0115	,0x035D	,0x0000), // '$' ➔ "͝" U+035D COMBINING DOUBLE BREVE
/*<!M><%parenright><%period>                                       */ DEADTRANS( L'.'	,0x0115	,0x0310	,0x0000), // '.' ➔ "̐" U+0310 COMBINING CANDRABINDU
/*<!M><%parenright><A>                                             */ DEADTRANS( L'A'	,0x0115	,0x0102	,0x0000), // 'A' ➔ "Ă" U+0102 LATIN CAPITAL LETTER A WITH BREVE
/*<!M><%parenright><a>                                             */ DEADTRANS( L'a'	,0x0115	,0x0103	,0x0000), // 'a' ➔ "ă" U+0103 LATIN SMALL LETTER A WITH BREVE
/*<!M><%parenright><Agrave>                                        */ DEADTRANS( 0x00C0	,0x0115	,0x1EB0	,0x0000), // 'À' ➔ "Ằ" U+1EB0 LATIN CAPITAL LETTER A WITH BREVE AND GRAVE
/*<!M><%parenright><agrave>                                        */ DEADTRANS( 0x00E0	,0x0115	,0x1EB1	,0x0000), // 'à' ➔ "ằ" U+1EB1 LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*<!M><%parenright><C>                                             */ DEADTRANS( L'C'	,0x0115	,0x02D2	,0x0000), // 'C' ➔ "˒" U+02D2 MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!M><%parenright><c>                                             */ DEADTRANS( L'c'	,0x0115	,0x02D2	,0x0000), // 'c' ➔ "˒" U+02D2 MODIFIER LETTER CENTRED RIGHT HALF RING
/*<!M><%parenright><E>                                             */ DEADTRANS( L'E'	,0x0115	,0x0114	,0x0000), // 'E' ➔ "Ĕ" U+0114 LATIN CAPITAL LETTER E WITH BREVE
/*<!M><%parenright><e>                                             */ DEADTRANS( L'e'	,0x0115	,0x0115	,0x0000), // 'e' ➔ "ĕ" U+0115 LATIN SMALL LETTER E WITH BREVE
/*<!M><%parenright><emdash>                                        */ DEADTRANS( 0x2014	,0x0115	,0x035D	,0x0000), // '—' ➔ "͝" U+035D COMBINING DOUBLE BREVE
/*<!M><%parenright><G>                                             */ DEADTRANS( L'G'	,0x0115	,0x011E	,0x0000), // 'G' ➔ "Ğ" U+011E LATIN CAPITAL LETTER G WITH BREVE
/*<!M><%parenright><g>                                             */ DEADTRANS( L'g'	,0x0115	,0x011F	,0x0000), // 'g' ➔ "ğ" U+011F LATIN SMALL LETTER G WITH BREVE
/*<!M><%parenright><H>                                             */ DEADTRANS( L'H'	,0x0115	,0x1E2A	,0x0000), // 'H' ➔ "Ḫ" U+1E2A LATIN CAPITAL LETTER H WITH BREVE BELOW
/*<!M><%parenright><h>                                             */ DEADTRANS( L'h'	,0x0115	,0x1E2B	,0x0000), // 'h' ➔ "ḫ" U+1E2B LATIN SMALL LETTER H WITH BREVE BELOW
/*<!M><%parenright><I>                                             */ DEADTRANS( L'I'	,0x0115	,0x012C	,0x0000), // 'I' ➔ "Ĭ" U+012C LATIN CAPITAL LETTER I WITH BREVE
/*<!M><%parenright><i>                                             */ DEADTRANS( L'i'	,0x0115	,0x012D	,0x0000), // 'i' ➔ "ĭ" U+012D LATIN SMALL LETTER I WITH BREVE
/*<!M><%parenright><O>                                             */ DEADTRANS( L'O'	,0x0115	,0x014E	,0x0000), // 'O' ➔ "Ŏ" U+014E LATIN CAPITAL LETTER O WITH BREVE
/*<!M><%parenright><o>                                             */ DEADTRANS( L'o'	,0x0115	,0x014F	,0x0000), // 'o' ➔ "ŏ" U+014F LATIN SMALL LETTER O WITH BREVE
/*<!M><%parenright><r>                                             */ DEADTRANS( L'r'	,0x0115	,0xAB47	,0x0000), // 'r' ➔ "ꭇ" U+AB47 LATIN SMALL LETTER R WITHOUT HANDLE
/*<!M><%parenright><U>                                             */ DEADTRANS( L'U'	,0x0115	,0x016C	,0x0000), // 'U' ➔ "Ŭ" U+016C LATIN CAPITAL LETTER U WITH BREVE
/*<!M><%parenright><u>                                             */ DEADTRANS( L'u'	,0x0115	,0x016D	,0x0000), // 'u' ➔ "ŭ" U+016D LATIN SMALL LETTER U WITH BREVE
/*<!M><%parenright><v>                                             */ DEADTRANS( L'v'	,0x0115	,0xAB4E	,0x0000), // 'v' ➔ "ꭎ" U+AB4E LATIN SMALL LETTER U WITH SHORT RIGHT LEG
/*<!M><%parenright><V>                                             */ DEADTRANS( L'V'	,0x0115	,0xAB4F	,0x0000), // 'V' ➔ "ꭏ" U+AB4F LATIN SMALL LETTER U BAR WITH SHORT RIGHT LEG
/*<!M><%parenright><y>                                             */ DEADTRANS( L'y'	,0x0115	,0xAB5A	,0x0000), // 'y' ➔ "ꭚ" U+AB5A LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*<!M><%parenright><~nbspace>                                      */ DEADTRANS( 0x00A0	,0x0115	,0x02D8	,0x0000), // ' ' ➔ "˘" U+02D8 BREVE
/*<!M><%parenright><~nbthinspace>                                  */ DEADTRANS( 0x202F	,0x0115	,0x02D8	,0x0000), // ' ' ➔ "˘" U+02D8 BREVE
/*<!M><%parenright><~space>                                        */ DEADTRANS( L' '	,0x0115	,0x0306	,0x0000), // ' ' ➔ "̆" U+0306 COMBINING BREVE
/*<!M><%parenright><~spacezerowidth>                               */ DEADTRANS( 0x200B	,0x0115	,0x0306	,0x0000), // '​' ➔ "̆" U+0306 COMBINING BREVE
/*<!M><%percent><%ampersand>                                       */ DEADTRANS( L'&'	,0x0250	,0x214B	,0x0000), // '&' ➔ "⅋" U+214B TURNED AMPERSAND
/*<!M><%percent><%apostrophe>                                      */ DEADTRANS( L'\''	,0x0250	,0x02BB	,0x0000), // ''' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%percent><%aprightsingquotmark>                             */ DEADTRANS( 0x2019	,0x0250	,0x02BB	,0x0000), // '’' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%percent><%comma>                                           */ DEADTRANS( L','	,0x0250	,0x2E32	,0x0000), // ',' ➔ "⸲" U+2E32 TURNED COMMA
/*<!M><%percent><%exclam>                                          */ DEADTRANS( L'!'	,0x0250	,0x00A1	,0x0000), // '!' ➔ "¡" U+00A1 INVERTED EXCLAMATION MARK
/*<!M><%percent><%excsection>                                      */ DEADTRANS( 0x00A7	,0x0250	,0x2E35	,0x0000), // '§' ➔ "⸵" U+2E35 TURNED SEMICOLON
/*<!M><%percent><%parenleft>                                       */ DEADTRANS( L'('	,0x0250	,0x2040	,0x0000), // '(' ➔ "⁀" U+2040 CHARACTER TIE
/*<!M><%percent><%question>                                        */ DEADTRANS( L'?'	,0x0250	,0x00BF	,0x0000), // '?' ➔ "¿" U+00BF INVERTED QUESTION MARK
/*<!M><%percent><%semicolon>                                       */ DEADTRANS( L';'	,0x0250	,0x2E35	,0x0000), // ';' ➔ "⸵" U+2E35 TURNED SEMICOLON
/*<!M><%percent><2>                                                */ DEADTRANS( L'2'	,0x0250	,0x218A	,0x0000), // '2' ➔ "↊" U+218A TURNED DIGIT TWO
/*<!M><%percent><3>                                                */ DEADTRANS( L'3'	,0x0250	,0x218B	,0x0000), // '3' ➔ "↋" U+218B TURNED DIGIT THREE
/*<!M><%percent><8>                                                */ DEADTRANS( L'8'	,0x0250	,0x221E	,0x0000), // '8' ➔ "∞" U+221E INFINITY
/*<!M><%percent><a>                                                */ DEADTRANS( L'a'	,0x0250	,0x0250	,0x0000), // 'a' ➔ "ɐ" U+0250 LATIN SMALL LETTER TURNED A
/*<!M><%percent><A>                                                */ DEADTRANS( L'A'	,0x0250	,0x2C6F	,0x0000), // 'A' ➔ "Ɐ" U+2C6F LATIN CAPITAL LETTER TURNED A
/*<!M><%percent><B>                                                */ DEADTRANS( L'B'	,0x0250	,0xA4ED	,0x0000), // 'B' ➔ "ꓭ" U+A4ED LISU LETTER GHA
/*<!M><%percent><C>                                                */ DEADTRANS( L'C'	,0x0250	,0x0186	,0x0000), // 'C' ➔ "Ɔ" U+0186 LATIN CAPITAL LETTER OPEN O
/*<!M><%percent><c>                                                */ DEADTRANS( L'c'	,0x0250	,0x0254	,0x0000), // 'c' ➔ "ɔ" U+0254 LATIN SMALL LETTER OPEN O
/*<!M><%percent><D>                                                */ DEADTRANS( L'D'	,0x0250	,0xA4F7	,0x0000), // 'D' ➔ "ꓷ" U+A4F7 LISU LETTER OE
/*<!M><%percent><E>                                                */ DEADTRANS( L'E'	,0x0250	,0x018E	,0x0000), // 'E' ➔ "Ǝ" U+018E LATIN CAPITAL LETTER REVERSED E
/*<!M><%percent><e>                                                */ DEADTRANS( L'e'	,0x0250	,0x01DD	,0x0000), // 'e' ➔ "ǝ" U+01DD LATIN SMALL LETTER TURNED E
/*<!M><%percent><f>                                                */ DEADTRANS( L'f'	,0x0250	,0x025F	,0x0000), // 'f' ➔ "ɟ" U+025F LATIN SMALL LETTER DOTLESS J WITH STROKE
/*<!M><%percent><F>                                                */ DEADTRANS( L'F'	,0x0250	,0xA4DE	,0x0000), // 'F' ➔ "ꓞ" U+A4DE LISU LETTER TSHA
/*<!M><%percent><g>                                                */ DEADTRANS( L'g'	,0x0250	,0x1D77	,0x0000), // 'g' ➔ "ᵷ" U+1D77 LATIN SMALL LETTER TURNED G
/*<!M><%percent><G>                                                */ DEADTRANS( L'G'	,0x0250	,0x2141	,0x0000), // 'G' ➔ "⅁" U+2141 TURNED SANS-SERIF CAPITAL G
/*<!M><%percent><h>                                                */ DEADTRANS( L'h'	,0x0250	,0x0265	,0x0000), // 'h' ➔ "ɥ" U+0265 LATIN SMALL LETTER TURNED H
/*<!M><%percent><H>                                                */ DEADTRANS( L'H'	,0x0250	,0xA78D	,0x0000), // 'H' ➔ "Ɥ" U+A78D LATIN CAPITAL LETTER TURNED H
/*<!M><%percent><i>                                                */ DEADTRANS( L'i'	,0x0250	,0x1D09	,0x0000), // 'i' ➔ "ᴉ" U+1D09 LATIN SMALL LETTER TURNED I
/*<!M><%percent><I>                                                */ DEADTRANS( L'I'	,0x0250	,0xA7F7	,0x0000), // 'I' ➔ "ꟷ" U+A7F7 LATIN EPIGRAPHIC LETTER SIDEWAYS I
/*<!M><%percent><J>                                                */ DEADTRANS( L'J'	,0x0250	,0xA4E9	,0x0000), // 'J' ➔ "ꓩ" U+A4E9 LISU LETTER FA
/*<!M><%percent><k>                                                */ DEADTRANS( L'k'	,0x0250	,0x029E	,0x0000), // 'k' ➔ "ʞ" U+029E LATIN SMALL LETTER TURNED K
/*<!M><%percent><K>                                                */ DEADTRANS( L'K'	,0x0250	,0xA7B0	,0x0000), // 'K' ➔ "Ʞ" U+A7B0 LATIN CAPITAL LETTER TURNED K
/*<!M><%percent><L>                                                */ DEADTRANS( L'L'	,0x0250	,0xA780	,0x0000), // 'L' ➔ "Ꞁ" U+A780 LATIN CAPITAL LETTER TURNED L
/*<!M><%percent><l>                                                */ DEADTRANS( L'l'	,0x0250	,0xA781	,0x0000), // 'l' ➔ "ꞁ" U+A781 LATIN SMALL LETTER TURNED L
/*<!M><%percent><M>                                                */ DEADTRANS( L'M'	,0x0250	,0x019C	,0x0000), // 'M' ➔ "Ɯ" U+019C LATIN CAPITAL LETTER TURNED M
/*<!M><%percent><m>                                                */ DEADTRANS( L'm'	,0x0250	,0x026F	,0x0000), // 'm' ➔ "ɯ" U+026F LATIN SMALL LETTER TURNED M
/*<!M><%percent><N>                                                */ DEADTRANS( L'N'	,0x0250	,0xA4E0	,0x0000), // 'N' ➔ "ꓠ" U+A4E0 LISU LETTER NA
/*<!M><%percent><o>                                                */ DEADTRANS( L'o'	,0x0250	,0x1D11	,0x0000), // 'o' ➔ "ᴑ" U+1D11 LATIN SMALL LETTER SIDEWAYS O
/*<!M><%percent><O>                                                */ DEADTRANS( L'O'	,0x0250	,0xA4F3	,0x0000), // 'O' ➔ "ꓳ" U+A4F3 LISU LETTER O
/*<!M><%percent><p>                                                */ DEADTRANS( L'p'	,0x0250	,0x1AE3	,0x0000), // 'p' ➔ "᫣" U+1AE3 COMBINING INVERTED BRIDGE ABOVE
/*<!M><%percent><P>                                                */ DEADTRANS( L'P'	,0x0250	,0xA4D2	,0x0000), // 'P' ➔ "ꓒ" U+A4D2 LISU LETTER PHA
/*<!M><%percent><Q>                                                */ DEADTRANS( L'Q'	,0x0250	,0x213A	,0x0000), // 'Q' ➔ "℺" U+213A ROTATED CAPITAL Q
/*<!M><%percent><r>                                                */ DEADTRANS( L'r'	,0x0250	,0x0279	,0x0000), // 'r' ➔ "ɹ" U+0279 LATIN SMALL LETTER TURNED R
/*<!M><%percent><R>                                                */ DEADTRANS( L'R'	,0x0250	,0xA4E4	,0x0000), // 'R' ➔ "ꓤ" U+A4E4 LISU LETTER ZA
/*<!M><%percent><S>                                                */ DEADTRANS( L'S'	,0x0250	,0xA4E2	,0x0000), // 'S' ➔ "ꓢ" U+A4E2 LISU LETTER SA
/*<!M><%percent><t>                                                */ DEADTRANS( L't'	,0x0250	,0x0287	,0x0000), // 't' ➔ "ʇ" U+0287 LATIN SMALL LETTER TURNED T
/*<!M><%percent><T>                                                */ DEADTRANS( L'T'	,0x0250	,0xA7B1	,0x0000), // 'T' ➔ "Ʇ" U+A7B1 LATIN CAPITAL LETTER TURNED T
/*<!M><%percent><U>                                                */ DEADTRANS( L'U'	,0x0250	,0xA4F5	,0x0000), // 'U' ➔ "ꓵ" U+A4F5 LISU LETTER UE
/*<!M><%percent><u>                                                */ DEADTRANS( L'u'	,0x0250	,0xAB51	,0x0000), // 'u' ➔ "ꭑ" U+AB51 LATIN SMALL LETTER TURNED UI
/*<!M><%percent><V>                                                */ DEADTRANS( L'V'	,0x0250	,0x0245	,0x0000), // 'V' ➔ "Ʌ" U+0245 LATIN CAPITAL LETTER TURNED V
/*<!M><%percent><v>                                                */ DEADTRANS( L'v'	,0x0250	,0x028C	,0x0000), // 'v' ➔ "ʌ" U+028C LATIN SMALL LETTER TURNED V
/*<!M><%percent><X>                                                */ DEADTRANS( L'X'	,0x0250	,0xA4EB	,0x0000), // 'X' ➔ "ꓫ" U+A4EB LISU LETTER SHA
/*<!M><%percent><y>                                                */ DEADTRANS( L'y'	,0x0250	,0x028E	,0x0000), // 'y' ➔ "ʎ" U+028E LATIN SMALL LETTER TURNED Y
/*<!M><%percent><Y>                                                */ DEADTRANS( L'Y'	,0x0250	,0x2144	,0x0000), // 'Y' ➔ "⅄" U+2144 TURNED SANS-SERIF CAPITAL Y
/*<!M><%percent><Z>                                                */ DEADTRANS( L'Z'	,0x0250	,0xA4DC	,0x0000), // 'Z' ➔ "ꓜ" U+A4DC LISU LETTER DZA
/*<!M><%percent><~nbspace>                                         */ DEADTRANS( 0x00A0	,0x0250	,0x02BB	,0x0000), // ' ' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%percent><~nbthinspace>                                     */ DEADTRANS( 0x202F	,0x0250	,0x02BB	,0x0000), // ' ' ➔ "ʻ" U+02BB MODIFIER LETTER TURNED COMMA
/*<!M><%percent><~space>                                           */ DEADTRANS( L' '	,0x0250	,0x0312	,0x0000), // ' ' ➔ "̒" U+0312 COMBINING TURNED COMMA ABOVE
/*<!M><%percent><~spacezerowidth>                                  */ DEADTRANS( 0x200B	,0x0250	,0x0312	,0x0000), // '​' ➔ "̒" U+0312 COMBINING TURNED COMMA ABOVE
/*<!M><%period><%aprightsingquotmark>                              */ DEADTRANS( 0x2019	,0x1E57	,0x2AC3	,0x0000), // '’' ➔ "⫃" U+2AC3 SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><%period><%braceleft>                                        */ DEADTRANS( L'{'	,0x1E57	,0x2AC4	,0x0000), // '{' ➔ "⫄" U+2AC4 SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><%period><%parenright>                                       */ DEADTRANS( L')'	,0x1E57	,0x0310	,0x0000), // ')' ➔ "̐" U+0310 COMBINING CANDRABINDU
/*<!M><%period><%percent>                                          */ DEADTRANS( L'%'	,0x1E57	,0x29CA	,0x0000), // '%' ➔ "⧊" U+29CA TRIANGLE WITH DOT ABOVE
/*<!M><%period><%question>                                         */ DEADTRANS( L'?'	,0x1E57	,0x2A52	,0x0000), // '?' ➔ "⩒" U+2A52 LOGICAL OR WITH DOT ABOVE
/*<!M><%period><%quotedbl>                                         */ DEADTRANS( L'"'	,0x1E57	,0x22F5	,0x0000), // '"' ➔ "⋵" U+22F5 ELEMENT OF WITH DOT ABOVE
/*<!M><%period><%quotEuroSign>                                     */ DEADTRANS( 0x20AC	,0x1E57	,0x22F5	,0x0000), // '€' ➔ "⋵" U+22F5 ELEMENT OF WITH DOT ABOVE
/*<!M><%period><%semicolon>                                        */ DEADTRANS( L';'	,0x1E57	,0x2A30	,0x0000), // ';' ➔ "⨰" U+2A30 MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><%period><0>                                                 */ DEADTRANS( L'0'	,0x1E57	,0x267C	,0x0000), // '0' ➔ "♼" U+267C RECYCLED PAPER SYMBOL
/*<!M><%period><1>                                                 */ DEADTRANS( L'1'	,0x1E57	,0x1DFA	,0x0000), // '1' ➔ "᷺" U+1DFA COMBINING DOT BELOW LEFT
/*<!M><%period><2>                                                 */ DEADTRANS( L'2'	,0x1E57	,0x267D	,0x0000), // '2' ➔ "♽" U+267D PARTIALLY-RECYCLED PAPER SYMBOL
/*<!M><%period><3>                                                 */ DEADTRANS( L'3'	,0x1E57	,0x1AB4	,0x0000), // '3' ➔ "᪴" U+1AB4 COMBINING TRIPLE DOT
/*<!M><%period><4>                                                 */ DEADTRANS( L'4'	,0x1E57	,0x267D	,0x0000), // '4' ➔ "♽" U+267D PARTIALLY-RECYCLED PAPER SYMBOL
/*<!M><%period><5>                                                 */ DEADTRANS( L'5'	,0x1E57	,0x0352	,0x0000), // '5' ➔ "͒" U+0352 COMBINING FERMATA
/*<!M><%period><6>                                                 */ DEADTRANS( L'6'	,0x1E57	,0x267C	,0x0000), // '6' ➔ "♼" U+267C RECYCLED PAPER SYMBOL
/*<!M><%period><7>                                                 */ DEADTRANS( L'7'	,0x1E57	,0x1DF8	,0x0000), // '7' ➔ "᷸" U+1DF8 COMBINING DOT ABOVE LEFT
/*<!M><%period><8>                                                 */ DEADTRANS( L'8'	,0x1E57	,0x267E	,0x0000), // '8' ➔ "♾" U+267E PERMANENT PAPER SIGN emoji
/*<!M><%period><9>                                                 */ DEADTRANS( L'9'	,0x1E57	,0x0358	,0x0000), // '9' ➔ "͘" U+0358 COMBINING DOT ABOVE RIGHT
/*<!M><%period><A>                                                 */ DEADTRANS( L'A'	,0x1E57	,0x0226	,0x0000), // 'A' ➔ "Ȧ" U+0226 LATIN CAPITAL LETTER A WITH DOT ABOVE
/*<!M><%period><a>                                                 */ DEADTRANS( L'a'	,0x1E57	,0x0227	,0x0000), // 'a' ➔ "ȧ" U+0227 LATIN SMALL LETTER A WITH DOT ABOVE
/*<!M><%period><B>                                                 */ DEADTRANS( L'B'	,0x1E57	,0x1E02	,0x0000), // 'B' ➔ "Ḃ" U+1E02 LATIN CAPITAL LETTER B WITH DOT ABOVE
/*<!M><%period><b>                                                 */ DEADTRANS( L'b'	,0x1E57	,0x1E03	,0x0000), // 'b' ➔ "ḃ" U+1E03 LATIN SMALL LETTER B WITH DOT ABOVE
/*<!M><%period><C>                                                 */ DEADTRANS( L'C'	,0x1E57	,0x010A	,0x0000), // 'C' ➔ "Ċ" U+010A LATIN CAPITAL LETTER C WITH DOT ABOVE
/*<!M><%period><c>                                                 */ DEADTRANS( L'c'	,0x1E57	,0x010B	,0x0000), // 'c' ➔ "ċ" U+010B LATIN SMALL LETTER C WITH DOT ABOVE
/*<!M><%period><D>                                                 */ DEADTRANS( L'D'	,0x1E57	,0x1E0A	,0x0000), // 'D' ➔ "Ḋ" U+1E0A LATIN CAPITAL LETTER D WITH DOT ABOVE
/*<!M><%period><d>                                                 */ DEADTRANS( L'd'	,0x1E57	,0x1E0B	,0x0000), // 'd' ➔ "ḋ" U+1E0B LATIN SMALL LETTER D WITH DOT ABOVE
/*<!M><%period><E>                                                 */ DEADTRANS( L'E'	,0x1E57	,0x0116	,0x0000), // 'E' ➔ "Ė" U+0116 LATIN CAPITAL LETTER E WITH DOT ABOVE
/*<!M><%period><e>                                                 */ DEADTRANS( L'e'	,0x1E57	,0x0117	,0x0000), // 'e' ➔ "ė" U+0117 LATIN SMALL LETTER E WITH DOT ABOVE
/*<!M><%period><F>                                                 */ DEADTRANS( L'F'	,0x1E57	,0x1E1E	,0x0000), // 'F' ➔ "Ḟ" U+1E1E LATIN CAPITAL LETTER F WITH DOT ABOVE
/*<!M><%period><f>                                                 */ DEADTRANS( L'f'	,0x1E57	,0x1E1F	,0x0000), // 'f' ➔ "ḟ" U+1E1F LATIN SMALL LETTER F WITH DOT ABOVE
/*<!M><%period><G>                                                 */ DEADTRANS( L'G'	,0x1E57	,0x0120	,0x0000), // 'G' ➔ "Ġ" U+0120 LATIN CAPITAL LETTER G WITH DOT ABOVE
/*<!M><%period><g>                                                 */ DEADTRANS( L'g'	,0x1E57	,0x0121	,0x0000), // 'g' ➔ "ġ" U+0121 LATIN SMALL LETTER G WITH DOT ABOVE
/*<!M><%period><H>                                                 */ DEADTRANS( L'H'	,0x1E57	,0x1E22	,0x0000), // 'H' ➔ "Ḣ" U+1E22 LATIN CAPITAL LETTER H WITH DOT ABOVE
/*<!M><%period><h>                                                 */ DEADTRANS( L'h'	,0x1E57	,0x1E23	,0x0000), // 'h' ➔ "ḣ" U+1E23 LATIN SMALL LETTER H WITH DOT ABOVE
/*<!M><%period><I>                                                 */ DEADTRANS( L'I'	,0x1E57	,0x0130	,0x0000), // 'I' ➔ "İ" U+0130 LATIN CAPITAL LETTER I WITH DOT ABOVE
/*<!M><%period><i>                                                 */ DEADTRANS( L'i'	,0x1E57	,0x0131	,0x0000), // 'i' ➔ "ı" U+0131 LATIN SMALL LETTER DOTLESS I
/*<!M><%period><J>                                                 */ DEADTRANS( L'J'	,0x1E57	,0x0237	,0x0000), // 'J' ➔ "ȷ" U+0237 LATIN SMALL LETTER DOTLESS J
/*<!M><%period><j>                                                 */ DEADTRANS( L'j'	,0x1E57	,0x0237	,0x0000), // 'j' ➔ "ȷ" U+0237 LATIN SMALL LETTER DOTLESS J
/*<!M><%period><L>                                                 */ DEADTRANS( L'L'	,0x1E57	,0x013F	,0x0000), // 'L' ➔ "Ŀ" U+013F LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*<!M><%period><l>                                                 */ DEADTRANS( L'l'	,0x1E57	,0x0140	,0x0000), // 'l' ➔ "ŀ" U+0140 LATIN SMALL LETTER L WITH MIDDLE DOT
/*<!M><%period><M>                                                 */ DEADTRANS( L'M'	,0x1E57	,0x1E40	,0x0000), // 'M' ➔ "Ṁ" U+1E40 LATIN CAPITAL LETTER M WITH DOT ABOVE
/*<!M><%period><m>                                                 */ DEADTRANS( L'm'	,0x1E57	,0x1E41	,0x0000), // 'm' ➔ "ṁ" U+1E41 LATIN SMALL LETTER M WITH DOT ABOVE
/*<!M><%period><multiply>                                          */ DEADTRANS( 0x00D7	,0x1E57	,0x2A30	,0x0000), // '×' ➔ "⨰" U+2A30 MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><%period><N>                                                 */ DEADTRANS( L'N'	,0x1E57	,0x1E44	,0x0000), // 'N' ➔ "Ṅ" U+1E44 LATIN CAPITAL LETTER N WITH DOT ABOVE
/*<!M><%period><n>                                                 */ DEADTRANS( L'n'	,0x1E57	,0x1E45	,0x0000), // 'n' ➔ "ṅ" U+1E45 LATIN SMALL LETTER N WITH DOT ABOVE
/*<!M><%period><O>                                                 */ DEADTRANS( L'O'	,0x1E57	,0x022E	,0x0000), // 'O' ➔ "Ȯ" U+022E LATIN CAPITAL LETTER O WITH DOT ABOVE
/*<!M><%period><o>                                                 */ DEADTRANS( L'o'	,0x1E57	,0x022F	,0x0000), // 'o' ➔ "ȯ" U+022F LATIN SMALL LETTER O WITH DOT ABOVE
/*<!M><%period><P>                                                 */ DEADTRANS( L'P'	,0x1E57	,0x1E56	,0x0000), // 'P' ➔ "Ṗ" U+1E56 LATIN CAPITAL LETTER P WITH DOT ABOVE
/*<!M><%period><p>                                                 */ DEADTRANS( L'p'	,0x1E57	,0x1E57	,0x0000), // 'p' ➔ "ṗ" U+1E57 LATIN SMALL LETTER P WITH DOT ABOVE
/*<!M><%period><R>                                                 */ DEADTRANS( L'R'	,0x1E57	,0x1E58	,0x0000), // 'R' ➔ "Ṙ" U+1E58 LATIN CAPITAL LETTER R WITH DOT ABOVE
/*<!M><%period><r>                                                 */ DEADTRANS( L'r'	,0x1E57	,0x1E59	,0x0000), // 'r' ➔ "ṙ" U+1E59 LATIN SMALL LETTER R WITH DOT ABOVE
/*<!M><%period><S>                                                 */ DEADTRANS( L'S'	,0x1E57	,0x1E60	,0x0000), // 'S' ➔ "Ṡ" U+1E60 LATIN CAPITAL LETTER S WITH DOT ABOVE
/*<!M><%period><s>                                                 */ DEADTRANS( L's'	,0x1E57	,0x1E61	,0x0000), // 's' ➔ "ṡ" U+1E61 LATIN SMALL LETTER S WITH DOT ABOVE
/*<!M><%period><T>                                                 */ DEADTRANS( L'T'	,0x1E57	,0x1E6A	,0x0000), // 'T' ➔ "Ṫ" U+1E6A LATIN CAPITAL LETTER T WITH DOT ABOVE
/*<!M><%period><t>                                                 */ DEADTRANS( L't'	,0x1E57	,0x1E6B	,0x0000), // 't' ➔ "ṫ" U+1E6B LATIN SMALL LETTER T WITH DOT ABOVE
/*<!M><%period><W>                                                 */ DEADTRANS( L'W'	,0x1E57	,0x1E86	,0x0000), // 'W' ➔ "Ẇ" U+1E86 LATIN CAPITAL LETTER W WITH DOT ABOVE
/*<!M><%period><w>                                                 */ DEADTRANS( L'w'	,0x1E57	,0x1E87	,0x0000), // 'w' ➔ "ẇ" U+1E87 LATIN SMALL LETTER W WITH DOT ABOVE
/*<!M><%period><X>                                                 */ DEADTRANS( L'X'	,0x1E57	,0x1E8A	,0x0000), // 'X' ➔ "Ẋ" U+1E8A LATIN CAPITAL LETTER X WITH DOT ABOVE
/*<!M><%period><x>                                                 */ DEADTRANS( L'x'	,0x1E57	,0x1E8B	,0x0000), // 'x' ➔ "ẋ" U+1E8B LATIN SMALL LETTER X WITH DOT ABOVE
/*<!M><%period><Y>                                                 */ DEADTRANS( L'Y'	,0x1E57	,0x1E8E	,0x0000), // 'Y' ➔ "Ẏ" U+1E8E LATIN CAPITAL LETTER Y WITH DOT ABOVE
/*<!M><%period><y>                                                 */ DEADTRANS( L'y'	,0x1E57	,0x1E8F	,0x0000), // 'y' ➔ "ẏ" U+1E8F LATIN SMALL LETTER Y WITH DOT ABOVE
/*<!M><%period><Z>                                                 */ DEADTRANS( L'Z'	,0x1E57	,0x017B	,0x0000), // 'Z' ➔ "Ż" U+017B LATIN CAPITAL LETTER Z WITH DOT ABOVE
/*<!M><%period><z>                                                 */ DEADTRANS( L'z'	,0x1E57	,0x017C	,0x0000), // 'z' ➔ "ż" U+017C LATIN SMALL LETTER Z WITH DOT ABOVE
/*<!M><%period><~nbspace>                                          */ DEADTRANS( 0x00A0	,0x1E57	,0x02D9	,0x0000), // ' ' ➔ "˙" U+02D9 DOT ABOVE
/*<!M><%period><~nbthinspace>                                      */ DEADTRANS( 0x202F	,0x1E57	,0x02D9	,0x0000), // ' ' ➔ "˙" U+02D9 DOT ABOVE
/*<!M><%period><~space>                                            */ DEADTRANS( L' '	,0x1E57	,0x0307	,0x0000), // ' ' ➔ "̇" U+0307 COMBINING DOT ABOVE
/*<!M><%period><~spacezerowidth>                                   */ DEADTRANS( 0x200B	,0x1E57	,0x0307	,0x0000), // '​' ➔ "̇" U+0307 COMBINING DOT ABOVE
/*<!M><%plus><%ampersand>                                          */ DEADTRANS( L'&'	,0x01A1	,0x1ACA	,0x0000), // '&' ➔ "᫊" U+1ACA COMBINING DOUBLE PLUS SIGN BELOW
/*<!M><%plus><%greater>                                            */ DEADTRANS( L'>'	,0x01A1	,0x2945	,0x0000), // '>' ➔ "⥅" U+2945 RIGHTWARDS ARROW WITH PLUS BELOW
/*<!M><%plus><%less>                                               */ DEADTRANS( L'<'	,0x01A1	,0x2946	,0x0000), // '<' ➔ "⥆" U+2946 LEFTWARDS ARROW WITH PLUS BELOW
/*<!M><%plus><%quotedbl>                                           */ DEADTRANS( L'"'	,0x01A1	,0x1AC9	,0x0000), // '"' ➔ "᫉" U+1AC9 COMBINING DOUBLE PLUS SIGN ABOVE
/*<!M><%plus><%quotEuroSign>                                       */ DEADTRANS( 0x20AC	,0x01A1	,0x1AC9	,0x0000), // '€' ➔ "᫉" U+1AC9 COMBINING DOUBLE PLUS SIGN ABOVE
/*<!M><%plus><0>                                                   */ DEADTRANS( L'0'	,0x01A1	,0x2195	,0x0000), // '0' ➔ "↕" U+2195 UP DOWN ARROW emoji
/*<!M><%plus><1>                                                   */ DEADTRANS( L'1'	,0x01A1	,0x2199	,0x0000), // '1' ➔ "↙" U+2199 SOUTH WEST ARROW emoji
/*<!M><%plus><2>                                                   */ DEADTRANS( L'2'	,0x01A1	,0x2193	,0x0000), // '2' ➔ "↓" U+2193 DOWNWARDS ARROW
/*<!M><%plus><3>                                                   */ DEADTRANS( L'3'	,0x01A1	,0x2198	,0x0000), // '3' ➔ "↘" U+2198 SOUTH EAST ARROW emoji
/*<!M><%plus><4>                                                   */ DEADTRANS( L'4'	,0x01A1	,0x2190	,0x0000), // '4' ➔ "←" U+2190 LEFTWARDS ARROW
/*<!M><%plus><5>                                                   */ DEADTRANS( L'5'	,0x01A1	,0x2194	,0x0000), // '5' ➔ "↔" U+2194 LEFT RIGHT ARROW emoji
/*<!M><%plus><6>                                                   */ DEADTRANS( L'6'	,0x01A1	,0x2192	,0x0000), // '6' ➔ "→" U+2192 RIGHTWARDS ARROW
/*<!M><%plus><7>                                                   */ DEADTRANS( L'7'	,0x01A1	,0x2196	,0x0000), // '7' ➔ "↖" U+2196 NORTH WEST ARROW emoji
/*<!M><%plus><8>                                                   */ DEADTRANS( L'8'	,0x01A1	,0x2191	,0x0000), // '8' ➔ "↑" U+2191 UPWARDS ARROW
/*<!M><%plus><9>                                                   */ DEADTRANS( L'9'	,0x01A1	,0x2197	,0x0000), // '9' ➔ "↗" U+2197 NORTH EAST ARROW emoji
/*<!M><%plus><A>                                                   */ DEADTRANS( L'A'	,0x01A1	,0x02D6	,0x0000), // 'A' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><a>                                                   */ DEADTRANS( L'a'	,0x01A1	,0x02D6	,0x0000), // 'a' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><B>                                                   */ DEADTRANS( L'B'	,0x01A1	,0x02D6	,0x0000), // 'B' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><b>                                                   */ DEADTRANS( L'b'	,0x01A1	,0x02D6	,0x0000), // 'b' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><C>                                                   */ DEADTRANS( L'C'	,0x01A1	,0x02D6	,0x0000), // 'C' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><c>                                                   */ DEADTRANS( L'c'	,0x01A1	,0x02D6	,0x0000), // 'c' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><D>                                                   */ DEADTRANS( L'D'	,0x01A1	,0x02D6	,0x0000), // 'D' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><d>                                                   */ DEADTRANS( L'd'	,0x01A1	,0x02D6	,0x0000), // 'd' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><e>                                                   */ DEADTRANS( L'e'	,0x01A1	,0x2C78	,0x0000), // 'e' ➔ "ⱸ" U+2C78 LATIN SMALL LETTER E WITH NOTCH
/*<!M><%plus><F>                                                   */ DEADTRANS( L'F'	,0x01A1	,0x02D6	,0x0000), // 'F' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><f>                                                   */ DEADTRANS( L'f'	,0x01A1	,0x02D6	,0x0000), // 'f' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><G>                                                   */ DEADTRANS( L'G'	,0x01A1	,0x02D6	,0x0000), // 'G' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><g>                                                   */ DEADTRANS( L'g'	,0x01A1	,0x02D6	,0x0000), // 'g' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><H>                                                   */ DEADTRANS( L'H'	,0x01A1	,0x2C67	,0x0000), // 'H' ➔ "Ⱨ" U+2C67 LATIN CAPITAL LETTER H WITH DESCENDER
/*<!M><%plus><h>                                                   */ DEADTRANS( L'h'	,0x01A1	,0x2C68	,0x0000), // 'h' ➔ "ⱨ" U+2C68 LATIN SMALL LETTER H WITH DESCENDER
/*<!M><%plus><I>                                                   */ DEADTRANS( L'I'	,0x01A1	,0x02D6	,0x0000), // 'I' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><i>                                                   */ DEADTRANS( L'i'	,0x01A1	,0x02D6	,0x0000), // 'i' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><J>                                                   */ DEADTRANS( L'J'	,0x01A1	,0x02D6	,0x0000), // 'J' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><j>                                                   */ DEADTRANS( L'j'	,0x01A1	,0x02D6	,0x0000), // 'j' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><K>                                                   */ DEADTRANS( L'K'	,0x01A1	,0x2C69	,0x0000), // 'K' ➔ "Ⱪ" U+2C69 LATIN CAPITAL LETTER K WITH DESCENDER
/*<!M><%plus><k>                                                   */ DEADTRANS( L'k'	,0x01A1	,0x2C6A	,0x0000), // 'k' ➔ "ⱪ" U+2C6A LATIN SMALL LETTER K WITH DESCENDER
/*<!M><%plus><L>                                                   */ DEADTRANS( L'L'	,0x01A1	,0x02D6	,0x0000), // 'L' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><l>                                                   */ DEADTRANS( L'l'	,0x01A1	,0x02D6	,0x0000), // 'l' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><M>                                                   */ DEADTRANS( L'M'	,0x01A1	,0x02D6	,0x0000), // 'M' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><m>                                                   */ DEADTRANS( L'm'	,0x01A1	,0x02D6	,0x0000), // 'm' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><N>                                                   */ DEADTRANS( L'N'	,0x01A1	,0xA790	,0x0000), // 'N' ➔ "Ꞑ" U+A790 LATIN CAPITAL LETTER N WITH DESCENDER
/*<!M><%plus><n>                                                   */ DEADTRANS( L'n'	,0x01A1	,0xA791	,0x0000), // 'n' ➔ "ꞑ" U+A791 LATIN SMALL LETTER N WITH DESCENDER
/*<!M><%plus><O>                                                   */ DEADTRANS( L'O'	,0x01A1	,0x01A0	,0x0000), // 'O' ➔ "Ơ" U+01A0 LATIN CAPITAL LETTER O WITH HORN
/*<!M><%plus><o>                                                   */ DEADTRANS( L'o'	,0x01A1	,0x01A1	,0x0000), // 'o' ➔ "ơ" U+01A1 LATIN SMALL LETTER O WITH HORN
/*<!M><%plus><P>                                                   */ DEADTRANS( L'P'	,0x01A1	,0x204B	,0x0000), // 'P' ➔ "⁋" U+204B REVERSED PILCROW SIGN
/*<!M><%plus><p>                                                   */ DEADTRANS( L'p'	,0x01A1	,0x204D	,0x0000), // 'p' ➔ "⁍" U+204D BLACK RIGHTWARDS BULLET
/*<!M><%plus><Q>                                                   */ DEADTRANS( L'Q'	,0x01A1	,0x00B6	,0x0000), // 'Q' ➔ "¶" U+00B6 PILCROW SIGN
/*<!M><%plus><q>                                                   */ DEADTRANS( L'q'	,0x01A1	,0x204C	,0x0000), // 'q' ➔ "⁌" U+204C BLACK LEFTWARDS BULLET
/*<!M><%plus><R>                                                   */ DEADTRANS( L'R'	,0x01A1	,0x02D6	,0x0000), // 'R' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><r>                                                   */ DEADTRANS( L'r'	,0x01A1	,0x02D6	,0x0000), // 'r' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><S>                                                   */ DEADTRANS( L'S'	,0x01A1	,0x02D6	,0x0000), // 'S' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><s>                                                   */ DEADTRANS( L's'	,0x01A1	,0x02D6	,0x0000), // 's' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><T>                                                   */ DEADTRANS( L'T'	,0x01A1	,0x02D6	,0x0000), // 'T' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><t>                                                   */ DEADTRANS( L't'	,0x01A1	,0x02D6	,0x0000), // 't' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><U>                                                   */ DEADTRANS( L'U'	,0x01A1	,0x01AF	,0x0000), // 'U' ➔ "Ư" U+01AF LATIN CAPITAL LETTER U WITH HORN
/*<!M><%plus><u>                                                   */ DEADTRANS( L'u'	,0x01A1	,0x01B0	,0x0000), // 'u' ➔ "ư" U+01B0 LATIN SMALL LETTER U WITH HORN
/*<!M><%plus><Ugrave>                                              */ DEADTRANS( 0x00D9	,0x01A1	,0x1EEA	,0x0000), // 'Ù' ➔ "Ừ" U+1EEA LATIN CAPITAL LETTER U WITH HORN AND GRAVE
/*<!M><%plus><ugrave>                                              */ DEADTRANS( 0x00F9	,0x01A1	,0x1EEB	,0x0000), // 'ù' ➔ "ừ" U+1EEB LATIN SMALL LETTER U WITH HORN AND GRAVE
/*<!M><%plus><V>                                                   */ DEADTRANS( L'V'	,0x01A1	,0x02D6	,0x0000), // 'V' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><v>                                                   */ DEADTRANS( L'v'	,0x01A1	,0x02D6	,0x0000), // 'v' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><W>                                                   */ DEADTRANS( L'W'	,0x01A1	,0x02D6	,0x0000), // 'W' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><w>                                                   */ DEADTRANS( L'w'	,0x01A1	,0x02D6	,0x0000), // 'w' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><X>                                                   */ DEADTRANS( L'X'	,0x01A1	,0x02D6	,0x0000), // 'X' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><x>                                                   */ DEADTRANS( L'x'	,0x01A1	,0x02D6	,0x0000), // 'x' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><Y>                                                   */ DEADTRANS( L'Y'	,0x01A1	,0x02D6	,0x0000), // 'Y' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><y>                                                   */ DEADTRANS( L'y'	,0x01A1	,0x02D6	,0x0000), // 'y' ➔ "˖" U+02D6 MODIFIER LETTER PLUS SIGN
/*<!M><%plus><Z>                                                   */ DEADTRANS( L'Z'	,0x01A1	,0x2C6B	,0x0000), // 'Z' ➔ "Ⱬ" U+2C6B LATIN CAPITAL LETTER Z WITH DESCENDER
/*<!M><%plus><z>                                                   */ DEADTRANS( L'z'	,0x01A1	,0x2C6C	,0x0000), // 'z' ➔ "ⱬ" U+2C6C LATIN SMALL LETTER Z WITH DESCENDER
/*<!M><%plus><~nbspace>                                            */ DEADTRANS( 0x00A0	,0x01A1	,0xA71A	,0x0000), // ' ' ➔ "ꜚ" U+A71A MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><%plus><~nbthinspace>                                        */ DEADTRANS( 0x202F	,0x01A1	,0xA71A	,0x0000), // ' ' ➔ "ꜚ" U+A71A MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><%plus><~space>                                              */ DEADTRANS( L' '	,0x01A1	,0x031B	,0x0000), // ' ' ➔ "̛" U+031B COMBINING HORN
/*<!M><%plus><~spacezerowidth>                                     */ DEADTRANS( 0x200B	,0x01A1	,0x031B	,0x0000), // '​' ➔ "̛" U+031B COMBINING HORN
/*<!M><%quotedbl><%apostrophe>                                     */ DEADTRANS( L'\''	,0x0151	,0x030E	,0x0000), // ''' ➔ "̎" U+030E COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!M><%quotedbl><%aprightsingquotmark>                            */ DEADTRANS( 0x2019	,0x0151	,0x030E	,0x0000), // '’' ➔ "̎" U+030E COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!M><%quotedbl><%equal>                                          */ DEADTRANS( L'='	,0x0151	,0x02F6	,0x0000), // '=' ➔ "˶" U+02F6 MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
/*<!M><%quotedbl><0>                                               */ DEADTRANS( L'0'	,0x0151	,0x24FE	,0x0000), // '0' ➔ "⓾" U+24FE DOUBLE CIRCLED NUMBER TEN
/*<!M><%quotedbl><1>                                               */ DEADTRANS( L'1'	,0x0151	,0x24F5	,0x0000), // '1' ➔ "⓵" U+24F5 DOUBLE CIRCLED DIGIT ONE
/*<!M><%quotedbl><2>                                               */ DEADTRANS( L'2'	,0x0151	,0x24F6	,0x0000), // '2' ➔ "⓶" U+24F6 DOUBLE CIRCLED DIGIT TWO
/*<!M><%quotedbl><3>                                               */ DEADTRANS( L'3'	,0x0151	,0x24F7	,0x0000), // '3' ➔ "⓷" U+24F7 DOUBLE CIRCLED DIGIT THREE
/*<!M><%quotedbl><4>                                               */ DEADTRANS( L'4'	,0x0151	,0x24F8	,0x0000), // '4' ➔ "⓸" U+24F8 DOUBLE CIRCLED DIGIT FOUR
/*<!M><%quotedbl><5>                                               */ DEADTRANS( L'5'	,0x0151	,0x24F9	,0x0000), // '5' ➔ "⓹" U+24F9 DOUBLE CIRCLED DIGIT FIVE
/*<!M><%quotedbl><6>                                               */ DEADTRANS( L'6'	,0x0151	,0x24FA	,0x0000), // '6' ➔ "⓺" U+24FA DOUBLE CIRCLED DIGIT SIX
/*<!M><%quotedbl><7>                                               */ DEADTRANS( L'7'	,0x0151	,0x24FB	,0x0000), // '7' ➔ "⓻" U+24FB DOUBLE CIRCLED DIGIT SEVEN
/*<!M><%quotedbl><8>                                               */ DEADTRANS( L'8'	,0x0151	,0x24FC	,0x0000), // '8' ➔ "⓼" U+24FC DOUBLE CIRCLED DIGIT EIGHT
/*<!M><%quotedbl><9>                                               */ DEADTRANS( L'9'	,0x0151	,0x24FD	,0x0000), // '9' ➔ "⓽" U+24FD DOUBLE CIRCLED DIGIT NINE
/*<!M><%quotedbl><O>                                               */ DEADTRANS( L'O'	,0x0151	,0x0150	,0x0000), // 'O' ➔ "Ő" U+0150 LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*<!M><%quotedbl><o>                                               */ DEADTRANS( L'o'	,0x0151	,0x0151	,0x0000), // 'o' ➔ "ő" U+0151 LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*<!M><%quotedbl><U>                                               */ DEADTRANS( L'U'	,0x0151	,0x0170	,0x0000), // 'U' ➔ "Ű" U+0170 LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*<!M><%quotedbl><u>                                               */ DEADTRANS( L'u'	,0x0151	,0x0171	,0x0000), // 'u' ➔ "ű" U+0171 LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*<!M><%quotedbl><~nbspace>                                        */ DEADTRANS( 0x00A0	,0x0151	,0x02DD	,0x0000), // ' ' ➔ "˝" U+02DD DOUBLE ACUTE ACCENT
/*<!M><%quotedbl><~nbthinspace>                                    */ DEADTRANS( 0x202F	,0x0151	,0x02DD	,0x0000), // ' ' ➔ "˝" U+02DD DOUBLE ACUTE ACCENT
/*<!M><%quotedbl><~space>                                          */ DEADTRANS( L' '	,0x0151	,0x030B	,0x0000), // ' ' ➔ "̋" U+030B COMBINING DOUBLE ACUTE ACCENT
/*<!M><%quotedbl><~spacezerowidth>                                 */ DEADTRANS( 0x200B	,0x0151	,0x030B	,0x0000), // '​' ➔ "̋" U+030B COMBINING DOUBLE ACUTE ACCENT
/*<!M><%quotEuroSign><%apostrophe>                                 */ DEADTRANS( L'\''	,0x0151	,0x030E	,0x0000), // ''' ➔ "̎" U+030E COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!M><%quotEuroSign><%aprightsingquotmark>                        */ DEADTRANS( 0x2019	,0x0151	,0x030E	,0x0000), // '’' ➔ "̎" U+030E COMBINING DOUBLE VERTICAL LINE ABOVE: Marshallese
/*<!M><%quotEuroSign><%equal>                                      */ DEADTRANS( L'='	,0x0151	,0x02F6	,0x0000), // '=' ➔ "˶" U+02F6 MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
/*<!M><%quotEuroSign><0>                                           */ DEADTRANS( L'0'	,0x0151	,0x24FE	,0x0000), // '0' ➔ "⓾" U+24FE DOUBLE CIRCLED NUMBER TEN
/*<!M><%quotEuroSign><1>                                           */ DEADTRANS( L'1'	,0x0151	,0x24F5	,0x0000), // '1' ➔ "⓵" U+24F5 DOUBLE CIRCLED DIGIT ONE
/*<!M><%quotEuroSign><2>                                           */ DEADTRANS( L'2'	,0x0151	,0x24F6	,0x0000), // '2' ➔ "⓶" U+24F6 DOUBLE CIRCLED DIGIT TWO
/*<!M><%quotEuroSign><3>                                           */ DEADTRANS( L'3'	,0x0151	,0x24F7	,0x0000), // '3' ➔ "⓷" U+24F7 DOUBLE CIRCLED DIGIT THREE
/*<!M><%quotEuroSign><4>                                           */ DEADTRANS( L'4'	,0x0151	,0x24F8	,0x0000), // '4' ➔ "⓸" U+24F8 DOUBLE CIRCLED DIGIT FOUR
/*<!M><%quotEuroSign><5>                                           */ DEADTRANS( L'5'	,0x0151	,0x24F9	,0x0000), // '5' ➔ "⓹" U+24F9 DOUBLE CIRCLED DIGIT FIVE
/*<!M><%quotEuroSign><6>                                           */ DEADTRANS( L'6'	,0x0151	,0x24FA	,0x0000), // '6' ➔ "⓺" U+24FA DOUBLE CIRCLED DIGIT SIX
/*<!M><%quotEuroSign><7>                                           */ DEADTRANS( L'7'	,0x0151	,0x24FB	,0x0000), // '7' ➔ "⓻" U+24FB DOUBLE CIRCLED DIGIT SEVEN
/*<!M><%quotEuroSign><8>                                           */ DEADTRANS( L'8'	,0x0151	,0x24FC	,0x0000), // '8' ➔ "⓼" U+24FC DOUBLE CIRCLED DIGIT EIGHT
/*<!M><%quotEuroSign><9>                                           */ DEADTRANS( L'9'	,0x0151	,0x24FD	,0x0000), // '9' ➔ "⓽" U+24FD DOUBLE CIRCLED DIGIT NINE
/*<!M><%quotEuroSign><O>                                           */ DEADTRANS( L'O'	,0x0151	,0x0150	,0x0000), // 'O' ➔ "Ő" U+0150 LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*<!M><%quotEuroSign><o>                                           */ DEADTRANS( L'o'	,0x0151	,0x0151	,0x0000), // 'o' ➔ "ő" U+0151 LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*<!M><%quotEuroSign><U>                                           */ DEADTRANS( L'U'	,0x0151	,0x0170	,0x0000), // 'U' ➔ "Ű" U+0170 LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*<!M><%quotEuroSign><u>                                           */ DEADTRANS( L'u'	,0x0151	,0x0171	,0x0000), // 'u' ➔ "ű" U+0171 LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*<!M><%quotEuroSign><~nbspace>                                    */ DEADTRANS( 0x00A0	,0x0151	,0x02DD	,0x0000), // ' ' ➔ "˝" U+02DD DOUBLE ACUTE ACCENT
/*<!M><%quotEuroSign><~nbthinspace>                                */ DEADTRANS( 0x202F	,0x0151	,0x02DD	,0x0000), // ' ' ➔ "˝" U+02DD DOUBLE ACUTE ACCENT
/*<!M><%quotEuroSign><~space>                                      */ DEADTRANS( L' '	,0x0151	,0x030B	,0x0000), // ' ' ➔ "̋" U+030B COMBINING DOUBLE ACUTE ACCENT
/*<!M><%quotEuroSign><~spacezerowidth>                             */ DEADTRANS( 0x200B	,0x0151	,0x030B	,0x0000), // '​' ➔ "̋" U+030B COMBINING DOUBLE ACUTE ACCENT
/*<!M><%semicolon><0>                                              */ DEADTRANS( L'0'	,0x0219	,0x249B	,0x0000), // '0' ➔ "⒛" U+249B NUMBER TWENTY FULL STOP
/*<!M><%semicolon><1>                                              */ DEADTRANS( L'1'	,0x0219	,0x2492	,0x0000), // '1' ➔ "⒒" U+2492 NUMBER ELEVEN FULL STOP
/*<!M><%semicolon><2>                                              */ DEADTRANS( L'2'	,0x0219	,0x2493	,0x0000), // '2' ➔ "⒓" U+2493 NUMBER TWELVE FULL STOP
/*<!M><%semicolon><3>                                              */ DEADTRANS( L'3'	,0x0219	,0x2494	,0x0000), // '3' ➔ "⒔" U+2494 NUMBER THIRTEEN FULL STOP
/*<!M><%semicolon><4>                                              */ DEADTRANS( L'4'	,0x0219	,0x2495	,0x0000), // '4' ➔ "⒕" U+2495 NUMBER FOURTEEN FULL STOP
/*<!M><%semicolon><5>                                              */ DEADTRANS( L'5'	,0x0219	,0x2496	,0x0000), // '5' ➔ "⒖" U+2496 NUMBER FIFTEEN FULL STOP
/*<!M><%semicolon><6>                                              */ DEADTRANS( L'6'	,0x0219	,0x2497	,0x0000), // '6' ➔ "⒗" U+2497 NUMBER SIXTEEN FULL STOP
/*<!M><%semicolon><7>                                              */ DEADTRANS( L'7'	,0x0219	,0x2498	,0x0000), // '7' ➔ "⒘" U+2498 NUMBER SEVENTEEN FULL STOP
/*<!M><%semicolon><8>                                              */ DEADTRANS( L'8'	,0x0219	,0x2499	,0x0000), // '8' ➔ "⒙" U+2499 NUMBER EIGHTEEN FULL STOP
/*<!M><%semicolon><9>                                              */ DEADTRANS( L'9'	,0x0219	,0x249A	,0x0000), // '9' ➔ "⒚" U+249A NUMBER NINETEEN FULL STOP
/*<!M><%semicolon><A>                                              */ DEADTRANS( L'A'	,0x0219	,0xA7BA	,0x0000), // 'A' ➔ "Ꞻ" U+A7BA LATIN CAPITAL LETTER GLOTTAL A
/*<!M><%semicolon><a>                                              */ DEADTRANS( L'a'	,0x0219	,0xA7BB	,0x0000), // 'a' ➔ "ꞻ" U+A7BB LATIN SMALL LETTER GLOTTAL A
/*<!M><%semicolon><I>                                              */ DEADTRANS( L'I'	,0x0219	,0xA7BC	,0x0000), // 'I' ➔ "Ꞽ" U+A7BC LATIN CAPITAL LETTER GLOTTAL I
/*<!M><%semicolon><i>                                              */ DEADTRANS( L'i'	,0x0219	,0xA7BD	,0x0000), // 'i' ➔ "ꞽ" U+A7BD LATIN SMALL LETTER GLOTTAL I
/*<!M><%semicolon><K>                                              */ DEADTRANS( L'K'	,0x0219	,0xA72E	,0x0000), // 'K' ➔ "Ꜯ" U+A72E LATIN CAPITAL LETTER CUATRILLO WITH COMMA
/*<!M><%semicolon><k>                                              */ DEADTRANS( L'k'	,0x0219	,0xA72F	,0x0000), // 'k' ➔ "ꜯ" U+A72F LATIN SMALL LETTER CUATRILLO WITH COMMA
/*<!M><%semicolon><S>                                              */ DEADTRANS( L'S'	,0x0219	,0x0218	,0x0000), // 'S' ➔ "Ș" U+0218 LATIN CAPITAL LETTER S WITH COMMA BELOW
/*<!M><%semicolon><s>                                              */ DEADTRANS( L's'	,0x0219	,0x0219	,0x0000), // 's' ➔ "ș" U+0219 LATIN SMALL LETTER S WITH COMMA BELOW
/*<!M><%semicolon><T>                                              */ DEADTRANS( L'T'	,0x0219	,0x021A	,0x0000), // 'T' ➔ "Ț" U+021A LATIN CAPITAL LETTER T WITH COMMA BELOW
/*<!M><%semicolon><t>                                              */ DEADTRANS( L't'	,0x0219	,0x021B	,0x0000), // 't' ➔ "ț" U+021B LATIN SMALL LETTER T WITH COMMA BELOW
/*<!M><%semicolon><U>                                              */ DEADTRANS( L'U'	,0x0219	,0xA7BE	,0x0000), // 'U' ➔ "Ꞿ" U+A7BE LATIN CAPITAL LETTER GLOTTAL U
/*<!M><%semicolon><u>                                              */ DEADTRANS( L'u'	,0x0219	,0xA7BF	,0x0000), // 'u' ➔ "ꞿ" U+A7BF LATIN SMALL LETTER GLOTTAL U
/*<!M><%semicolon><~nbspace>                                       */ DEADTRANS( 0x00A0	,0x0219	,0x2E34	,0x0000), // ' ' ➔ "⸴" U+2E34 RAISED COMMA
/*<!M><%semicolon><~nbthinspace>                                   */ DEADTRANS( 0x202F	,0x0219	,0x2E34	,0x0000), // ' ' ➔ "⸴" U+2E34 RAISED COMMA
/*<!M><%semicolon><~space>                                         */ DEADTRANS( L' '	,0x0219	,0x0326	,0x0000), // ' ' ➔ "̦" U+0326 COMBINING COMMA BELOW
/*<!M><%semicolon><~spacezerowidth>                                */ DEADTRANS( 0x200B	,0x0219	,0x0326	,0x0000), // '​' ➔ "̦" U+0326 COMBINING COMMA BELOW
/*<!M><%slash><%circum>                                            */ DEADTRANS( L'^'	,0x00F8	,0xDFA2	,0x0000), // High surrogate: D801; '^' ➔ "𐞢" U+107A2 MODIFIER LETTER SMALL O WITH STROKE
/*<!M><%slash><%less>                                              */ DEADTRANS( L'<'	,0x00F8	,0x226E	,0x0000), // '<' ➔ "≮" U+226E NOT LESS-THAN
/*<!M><%slash><%quotedbl>                                          */ DEADTRANS( L'"'	,0x00F8	,0x2204	,0x0000), // '"' ➔ "∄" U+2204 THERE DOES NOT EXIST
/*<!M><%slash><%quotEuroSign>                                      */ DEADTRANS( 0x20AC	,0x00F8	,0x2204	,0x0000), // '€' ➔ "∄" U+2204 THERE DOES NOT EXIST
/*<!M><%slash><1>                                                  */ DEADTRANS( L'1'	,0x00F8	,0x2215	,0x0000), // '1' ➔ "∕" U+2215 DIVISION SLASH
/*<!M><%slash><2>                                                  */ DEADTRANS( L'2'	,0x00F8	,0x29F8	,0x0000), // '2' ➔ "⧸" U+29F8 BIG SOLIDUS
/*<!M><%slash><3>                                                  */ DEADTRANS( L'3'	,0x00F8	,0x27CB	,0x0000), // '3' ➔ "⟋" U+27CB MATHEMATICAL RISING DIAGONAL
/*<!M><%slash><4>                                                  */ DEADTRANS( L'4'	,0x00F8	,0x2044	,0x0000), // '4' ➔ "⁄" U+2044 FRACTION SLASH
/*<!M><%slash><A>                                                  */ DEADTRANS( L'A'	,0x00F8	,0x023A	,0x0000), // 'A' ➔ "Ⱥ" U+023A LATIN CAPITAL LETTER A WITH STROKE
/*<!M><%slash><a>                                                  */ DEADTRANS( L'a'	,0x00F8	,0x2C65	,0x0000), // 'a' ➔ "ⱥ" U+2C65 LATIN SMALL LETTER A WITH STROKE
/*<!M><%slash><b>                                                  */ DEADTRANS( L'b'	,0x00F8	,0x0180	,0x0000), // 'b' ➔ "ƀ" U+0180 LATIN SMALL LETTER B WITH STROKE (lenient)
/*<!M><%slash><B>                                                  */ DEADTRANS( L'B'	,0x00F8	,0x0243	,0x0000), // 'B' ➔ "Ƀ" U+0243 LATIN CAPITAL LETTER B WITH STROKE (lenient)
/*<!M><%slash><C>                                                  */ DEADTRANS( L'C'	,0x00F8	,0x023B	,0x0000), // 'C' ➔ "Ȼ" U+023B LATIN CAPITAL LETTER C WITH STROKE
/*<!M><%slash><c>                                                  */ DEADTRANS( L'c'	,0x00F8	,0x023C	,0x0000), // 'c' ➔ "ȼ" U+023C LATIN SMALL LETTER C WITH STROKE
/*<!M><%slash><D>                                                  */ DEADTRANS( L'D'	,0x00F8	,0x0110	,0x0000), // 'D' ➔ "Đ" U+0110 LATIN CAPITAL LETTER D WITH STROKE (lenient)
/*<!M><%slash><d>                                                  */ DEADTRANS( L'd'	,0x00F8	,0x0111	,0x0000), // 'd' ➔ "đ" U+0111 LATIN SMALL LETTER D WITH STROKE (lenient)
/*<!M><%slash><E>                                                  */ DEADTRANS( L'E'	,0x00F8	,0x0246	,0x0000), // 'E' ➔ "Ɇ" U+0246 LATIN CAPITAL LETTER E WITH STROKE
/*<!M><%slash><e>                                                  */ DEADTRANS( L'e'	,0x00F8	,0x0247	,0x0000), // 'e' ➔ "ɇ" U+0247 LATIN SMALL LETTER E WITH STROKE
/*<!M><%slash><F>                                                  */ DEADTRANS( L'F'	,0x00F8	,0xA798	,0x0000), // 'F' ➔ "Ꞙ" U+A798 LATIN CAPITAL LETTER F WITH STROKE (lenient)
/*<!M><%slash><f>                                                  */ DEADTRANS( L'f'	,0x00F8	,0xA799	,0x0000), // 'f' ➔ "ꞙ" U+A799 LATIN SMALL LETTER F WITH STROKE (lenient)
/*<!M><%slash><G>                                                  */ DEADTRANS( L'G'	,0x00F8	,0xA7A0	,0x0000), // 'G' ➔ "Ꞡ" U+A7A0 LATIN CAPITAL LETTER G WITH OBLIQUE STROKE
/*<!M><%slash><g>                                                  */ DEADTRANS( L'g'	,0x00F8	,0xA7A1	,0x0000), // 'g' ➔ "ꞡ" U+A7A1 LATIN SMALL LETTER G WITH OBLIQUE STROKE
/*<!M><%slash><H>                                                  */ DEADTRANS( L'H'	,0x00F8	,0x0126	,0x0000), // 'H' ➔ "Ħ" U+0126 LATIN CAPITAL LETTER H WITH STROKE (lenient)
/*<!M><%slash><h>                                                  */ DEADTRANS( L'h'	,0x00F8	,0x0127	,0x0000), // 'h' ➔ "ħ" U+0127 LATIN SMALL LETTER H WITH STROKE (lenient)
/*<!M><%slash><I>                                                  */ DEADTRANS( L'I'	,0x00F8	,0x0197	,0x0000), // 'I' ➔ "Ɨ" U+0197 LATIN CAPITAL LETTER I WITH STROKE (lenient)
/*<!M><%slash><i>                                                  */ DEADTRANS( L'i'	,0x00F8	,0x0268	,0x0000), // 'i' ➔ "ɨ" U+0268 LATIN SMALL LETTER I WITH STROKE (lenient)
/*<!M><%slash><J>                                                  */ DEADTRANS( L'J'	,0x00F8	,0x0248	,0x0000), // 'J' ➔ "Ɉ" U+0248 LATIN CAPITAL LETTER J WITH STROKE (lenient)
/*<!M><%slash><j>                                                  */ DEADTRANS( L'j'	,0x00F8	,0x0249	,0x0000), // 'j' ➔ "ɉ" U+0249 LATIN SMALL LETTER J WITH STROKE (lenient)
/*<!M><%slash><K>                                                  */ DEADTRANS( L'K'	,0x00F8	,0xA742	,0x0000), // 'K' ➔ "Ꝃ" U+A742 LATIN CAPITAL LETTER K WITH DIAGONAL STROKE
/*<!M><%slash><k>                                                  */ DEADTRANS( L'k'	,0x00F8	,0xA743	,0x0000), // 'k' ➔ "ꝃ" U+A743 LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*<!M><%slash><L>                                                  */ DEADTRANS( L'L'	,0x00F8	,0x0141	,0x0000), // 'L' ➔ "Ł" U+0141 LATIN CAPITAL LETTER L WITH STROKE
/*<!M><%slash><l>                                                  */ DEADTRANS( L'l'	,0x00F8	,0x0142	,0x0000), // 'l' ➔ "ł" U+0142 LATIN SMALL LETTER L WITH STROKE
/*<!M><%slash><N>                                                  */ DEADTRANS( L'N'	,0x00F8	,0xA7A4	,0x0000), // 'N' ➔ "Ꞥ" U+A7A4 LATIN CAPITAL LETTER N WITH OBLIQUE STROKE
/*<!M><%slash><n>                                                  */ DEADTRANS( L'n'	,0x00F8	,0xA7A5	,0x0000), // 'n' ➔ "ꞥ" U+A7A5 LATIN SMALL LETTER N WITH OBLIQUE STROKE
/*<!M><%slash><O>                                                  */ DEADTRANS( L'O'	,0x00F8	,0x00D8	,0x0000), // 'O' ➔ "Ø" U+00D8 LATIN CAPITAL LETTER O WITH STROKE
/*<!M><%slash><o>                                                  */ DEADTRANS( L'o'	,0x00F8	,0x00F8	,0x0000), // 'o' ➔ "ø" U+00F8 LATIN SMALL LETTER O WITH STROKE
/*<!M><%slash><p>                                                  */ DEADTRANS( L'p'	,0x00F8	,0x1D7D	,0x0000), // 'p' ➔ "ᵽ" U+1D7D LATIN SMALL LETTER P WITH STROKE (lenient)
/*<!M><%slash><P>                                                  */ DEADTRANS( L'P'	,0x00F8	,0x2C63	,0x0000), // 'P' ➔ "Ᵽ" U+2C63 LATIN CAPITAL LETTER P WITH STROKE (lenient)
/*<!M><%slash><Q>                                                  */ DEADTRANS( L'Q'	,0x00F8	,0xA758	,0x0000), // 'Q' ➔ "Ꝙ" U+A758 LATIN CAPITAL LETTER Q WITH DIAGONAL STROKE
/*<!M><%slash><q>                                                  */ DEADTRANS( L'q'	,0x00F8	,0xA759	,0x0000), // 'q' ➔ "ꝙ" U+A759 LATIN SMALL LETTER Q WITH DIAGONAL STROKE
/*<!M><%slash><R>                                                  */ DEADTRANS( L'R'	,0x00F8	,0xA7A6	,0x0000), // 'R' ➔ "Ꞧ" U+A7A6 LATIN CAPITAL LETTER R WITH OBLIQUE STROKE
/*<!M><%slash><r>                                                  */ DEADTRANS( L'r'	,0x00F8	,0xA7A7	,0x0000), // 'r' ➔ "ꞧ" U+A7A7 LATIN SMALL LETTER R WITH OBLIQUE STROKE
/*<!M><%slash><S>                                                  */ DEADTRANS( L'S'	,0x00F8	,0xA7CC	,0x0000), // 'S' ➔ "Ꟍ" U+A7CC LATIN CAPITAL LETTER S WITH DIAGONAL STROKE
/*<!M><%slash><s>                                                  */ DEADTRANS( L's'	,0x00F8	,0xA7CD	,0x0000), // 's' ➔ "ꟍ" U+A7CD LATIN SMALL LETTER S WITH DIAGONAL STROKE
/*<!M><%slash><T>                                                  */ DEADTRANS( L'T'	,0x00F8	,0x023E	,0x0000), // 'T' ➔ "Ⱦ" U+023E LATIN CAPITAL LETTER T WITH DIAGONAL STROKE
/*<!M><%slash><t>                                                  */ DEADTRANS( L't'	,0x00F8	,0x2C66	,0x0000), // 't' ➔ "ⱦ" U+2C66 LATIN SMALL LETTER T WITH DIAGONAL STROKE
/*<!M><%slash><U>                                                  */ DEADTRANS( L'U'	,0x00F8	,0xA7B8	,0x0000), // 'U' ➔ "Ꞹ" U+A7B8 LATIN CAPITAL LETTER U WITH STROKE
/*<!M><%slash><u>                                                  */ DEADTRANS( L'u'	,0x00F8	,0xA7B9	,0x0000), // 'u' ➔ "ꞹ" U+A7B9 LATIN SMALL LETTER U WITH STROKE
/*<!M><%slash><V>                                                  */ DEADTRANS( L'V'	,0x00F8	,0xA75E	,0x0000), // 'V' ➔ "Ꝟ" U+A75E LATIN CAPITAL LETTER V WITH DIAGONAL STROKE
/*<!M><%slash><v>                                                  */ DEADTRANS( L'v'	,0x00F8	,0xA75F	,0x0000), // 'v' ➔ "ꝟ" U+A75F LATIN SMALL LETTER V WITH DIAGONAL STROKE
/*<!M><%slash><Y>                                                  */ DEADTRANS( L'Y'	,0x00F8	,0x024E	,0x0000), // 'Y' ➔ "Ɏ" U+024E LATIN CAPITAL LETTER Y WITH STROKE (lenient)
/*<!M><%slash><y>                                                  */ DEADTRANS( L'y'	,0x00F8	,0x024F	,0x0000), // 'y' ➔ "ɏ" U+024F LATIN SMALL LETTER Y WITH STROKE (lenient)
/*<!M><%slash><Z>                                                  */ DEADTRANS( L'Z'	,0x00F8	,0x01B5	,0x0000), // 'Z' ➔ "Ƶ" U+01B5 LATIN CAPITAL LETTER Z WITH STROKE (lenient)
/*<!M><%slash><z>                                                  */ DEADTRANS( L'z'	,0x00F8	,0x01B6	,0x0000), // 'z' ➔ "ƶ" U+01B6 LATIN SMALL LETTER Z WITH STROKE (lenient)
/*<!M><%slash><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x00F8	,0x2215	,0x0000), // ' ' ➔ "∕" U+2215 DIVISION SLASH
/*<!M><%slash><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x00F8	,0x2215	,0x0000), // ' ' ➔ "∕" U+2215 DIVISION SLASH
/*<!M><%slash><~space>                                             */ DEADTRANS( L' '	,0x00F8	,0x0338	,0x0000), // ' ' ➔ "̸" U+0338 COMBINING LONG SOLIDUS OVERLAY
/*<!M><%slash><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x00F8	,0x0338	,0x0000), // '​' ➔ "̸" U+0338 COMBINING LONG SOLIDUS OVERLAY
/*<!M><%tilde><%asterisk>                                          */ DEADTRANS( L'*'	,0x00F5	,0x2051	,0x0000), // '*' ➔ "⁑" U+2051 TWO ASTERISKS ALIGNED VERTICALLY
/*<!M><%tilde><%braceright>                                        */ DEADTRANS( L'}'	,0x00F5	,0x2771	,0x0000), // '}' ➔ "❱" U+2771 HEAVY RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*<!M><%tilde><%bracketright>                                      */ DEADTRANS( L']'	,0x00F5	,0x276D	,0x0000), // ']' ➔ "❭" U+276D MEDIUM RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*<!M><%tilde><%dollar>                                            */ DEADTRANS( L'$'	,0x00F5	,0x0360	,0x0000), // '$' ➔ "͠" U+0360 COMBINING DOUBLE TILDE
/*<!M><%tilde><%equal>                                             */ DEADTRANS( L'='	,0x00F5	,0x034C	,0x0000), // '=' ➔ "͌" U+034C COMBINING ALMOST EQUAL TO ABOVE
/*<!M><%tilde><%parenleft>                                         */ DEADTRANS( L'('	,0x00F5	,0x034F	,0x0000), // '(' ➔ "͏" U+034F COMBINING GRAPHEME JOINER
/*<!M><%tilde><%quotedbl>                                          */ DEADTRANS( L'"'	,0x00F5	,0xFE0F	,0x0000), // '"' ➔ "️" U+FE0F VARIATION SELECTOR-16, emoji style
/*<!M><%tilde><%quotEuroSign>                                      */ DEADTRANS( 0x20AC	,0x00F5	,0xFE0F	,0x0000), // '€' ➔ "️" U+FE0F VARIATION SELECTOR-16, emoji style
/*<!M><%tilde><%underscore>                                        */ DEADTRANS( L'_'	,0x00F5	,0x2053	,0x0000), // '_' ➔ "⁓" U+2053 SWUNG DASH
/*<!M><%tilde><0>                                                  */ DEADTRANS( L'0'	,0x00F5	,0x02D5	,0x0000), // '0' ➔ "˕" U+02D5 MODIFIER LETTER DOWN TACK
/*<!M><%tilde><1>                                                  */ DEADTRANS( L'1'	,0x00F5	,0x2020	,0x0000), // '1' ➔ "†" U+2020 DAGGER
/*<!M><%tilde><2>                                                  */ DEADTRANS( L'2'	,0x00F5	,0x2021	,0x0000), // '2' ➔ "‡" U+2021 DOUBLE DAGGER
/*<!M><%tilde><3>                                                  */ DEADTRANS( L'3'	,0x00F5	,0x2E4B	,0x0000), // '3' ➔ "⹋" U+2E4B TRIPLE DAGGER
/*<!M><%tilde><4>                                                  */ DEADTRANS( L'4'	,0x00F5	,0x2E36	,0x0000), // '4' ➔ "⸶" U+2E36 DAGGER WITH LEFT GUARD
/*<!M><%tilde><5>                                                  */ DEADTRANS( L'5'	,0x00F5	,0x2E38	,0x0000), // '5' ➔ "⸸" U+2E38 TURNED DAGGER
/*<!M><%tilde><6>                                                  */ DEADTRANS( L'6'	,0x00F5	,0x2E37	,0x0000), // '6' ➔ "⸷" U+2E37 DAGGER WITH RIGHT GUARD
/*<!M><%tilde><7>                                                  */ DEADTRANS( L'7'	,0x00F5	,0xAB6A	,0x0000), // '7' ➔ "꭪" U+AB6A MODIFIER LETTER LEFT TACK
/*<!M><%tilde><8>                                                  */ DEADTRANS( L'8'	,0x00F5	,0x02D4	,0x0000), // '8' ➔ "˔" U+02D4 MODIFIER LETTER UP TACK
/*<!M><%tilde><9>                                                  */ DEADTRANS( L'9'	,0x00F5	,0xAB6B	,0x0000), // '9' ➔ "꭫" U+AB6B MODIFIER LETTER RIGHT TACK
/*<!M><%tilde><A>                                                  */ DEADTRANS( L'A'	,0x00F5	,0x00C3	,0x0000), // 'A' ➔ "Ã" U+00C3 LATIN CAPITAL LETTER A WITH TILDE
/*<!M><%tilde><a>                                                  */ DEADTRANS( L'a'	,0x00F5	,0x00E3	,0x0000), // 'a' ➔ "ã" U+00E3 LATIN SMALL LETTER A WITH TILDE
/*<!M><%tilde><b>                                                  */ DEADTRANS( L'b'	,0x00F5	,0x1D6C	,0x0000), // 'b' ➔ "ᵬ" U+1D6C LATIN SMALL LETTER B WITH MIDDLE TILDE
/*<!M><%tilde><C>                                                  */ DEADTRANS( L'C'	,0x00F5	,0xFE22	,0x0000), // 'C' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><c>                                                  */ DEADTRANS( L'c'	,0x00F5	,0xFE23	,0x0000), // 'c' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><d>                                                  */ DEADTRANS( L'd'	,0x00F5	,0x1D6D	,0x0000), // 'd' ➔ "ᵭ" U+1D6D LATIN SMALL LETTER D WITH MIDDLE TILDE
/*<!M><%tilde><E>                                                  */ DEADTRANS( L'E'	,0x00F5	,0x1EBC	,0x0000), // 'E' ➔ "Ẽ" U+1EBC LATIN CAPITAL LETTER E WITH TILDE
/*<!M><%tilde><e>                                                  */ DEADTRANS( L'e'	,0x00F5	,0x1EBD	,0x0000), // 'e' ➔ "ẽ" U+1EBD LATIN SMALL LETTER E WITH TILDE
/*<!M><%tilde><emdash>                                             */ DEADTRANS( 0x2014	,0x00F5	,0x0360	,0x0000), // '—' ➔ "͠" U+0360 COMBINING DOUBLE TILDE
/*<!M><%tilde><endash>                                             */ DEADTRANS( 0x2013	,0x00F5	,0x2053	,0x0000), // '–' ➔ "⁓" U+2053 SWUNG DASH
/*<!M><%tilde><f>                                                  */ DEADTRANS( L'f'	,0x00F5	,0x1D6E	,0x0000), // 'f' ➔ "ᵮ" U+1D6E LATIN SMALL LETTER F WITH MIDDLE TILDE
/*<!M><%tilde><G>                                                  */ DEADTRANS( L'G'	,0x00F5	,0xFE22	,0x0000), // 'G' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><g>                                                  */ DEADTRANS( L'g'	,0x00F5	,0xFE23	,0x0000), // 'g' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><Greek_horizbar>                                     */ DEADTRANS( 0x2015	,0x00F5	,0x2053	,0x0000), // '―' ➔ "⁓" U+2053 SWUNG DASH
/*<!M><%tilde><H>                                                  */ DEADTRANS( L'H'	,0x00F5	,0xFE22	,0x0000), // 'H' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><h>                                                  */ DEADTRANS( L'h'	,0x00F5	,0xFE23	,0x0000), // 'h' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><I>                                                  */ DEADTRANS( L'I'	,0x00F5	,0x0128	,0x0000), // 'I' ➔ "Ĩ" U+0128 LATIN CAPITAL LETTER I WITH TILDE
/*<!M><%tilde><i>                                                  */ DEADTRANS( L'i'	,0x00F5	,0x0129	,0x0000), // 'i' ➔ "ĩ" U+0129 LATIN SMALL LETTER I WITH TILDE
/*<!M><%tilde><K>                                                  */ DEADTRANS( L'K'	,0x00F5	,0xFE22	,0x0000), // 'K' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><k>                                                  */ DEADTRANS( L'k'	,0x00F5	,0xFE23	,0x0000), // 'k' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><N>                                                  */ DEADTRANS( L'N'	,0x00F5	,0x00D1	,0x0000), // 'N' ➔ "Ñ" U+00D1 LATIN CAPITAL LETTER N WITH TILDE
/*<!M><%tilde><n>                                                  */ DEADTRANS( L'n'	,0x00F5	,0x00F1	,0x0000), // 'n' ➔ "ñ" U+00F1 LATIN SMALL LETTER N WITH TILDE
/*<!M><%tilde><O>                                                  */ DEADTRANS( L'O'	,0x00F5	,0x00D5	,0x0000), // 'O' ➔ "Õ" U+00D5 LATIN CAPITAL LETTER O WITH TILDE
/*<!M><%tilde><o>                                                  */ DEADTRANS( L'o'	,0x00F5	,0x00F5	,0x0000), // 'o' ➔ "õ" U+00F5 LATIN SMALL LETTER O WITH TILDE
/*<!M><%tilde><p>                                                  */ DEADTRANS( L'p'	,0x00F5	,0x1D71	,0x0000), // 'p' ➔ "ᵱ" U+1D71 LATIN SMALL LETTER P WITH MIDDLE TILDE
/*<!M><%tilde><Q>                                                  */ DEADTRANS( L'Q'	,0x00F5	,0xFE22	,0x0000), // 'Q' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><q>                                                  */ DEADTRANS( L'q'	,0x00F5	,0xFE23	,0x0000), // 'q' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><s>                                                  */ DEADTRANS( L's'	,0x00F5	,0x1D74	,0x0000), // 's' ➔ "ᵴ" U+1D74 LATIN SMALL LETTER S WITH MIDDLE TILDE
/*<!M><%tilde><t>                                                  */ DEADTRANS( L't'	,0x00F5	,0x1D75	,0x0000), // 't' ➔ "ᵵ" U+1D75 LATIN SMALL LETTER T WITH MIDDLE TILDE
/*<!M><%tilde><U>                                                  */ DEADTRANS( L'U'	,0x00F5	,0x0168	,0x0000), // 'U' ➔ "Ũ" U+0168 LATIN CAPITAL LETTER U WITH TILDE
/*<!M><%tilde><u>                                                  */ DEADTRANS( L'u'	,0x00F5	,0x0169	,0x0000), // 'u' ➔ "ũ" U+0169 LATIN SMALL LETTER U WITH TILDE
/*<!M><%tilde><V>                                                  */ DEADTRANS( L'V'	,0x00F5	,0x1E7C	,0x0000), // 'V' ➔ "Ṽ" U+1E7C LATIN CAPITAL LETTER V WITH TILDE
/*<!M><%tilde><v>                                                  */ DEADTRANS( L'v'	,0x00F5	,0x1E7D	,0x0000), // 'v' ➔ "ṽ" U+1E7D LATIN SMALL LETTER V WITH TILDE
/*<!M><%tilde><W>                                                  */ DEADTRANS( L'W'	,0x00F5	,0xFE22	,0x0000), // 'W' ➔ "︢" U+FE22 COMBINING DOUBLE TILDE LEFT HALF
/*<!M><%tilde><w>                                                  */ DEADTRANS( L'w'	,0x00F5	,0xFE23	,0x0000), // 'w' ➔ "︣" U+FE23 COMBINING DOUBLE TILDE RIGHT HALF
/*<!M><%tilde><Y>                                                  */ DEADTRANS( L'Y'	,0x00F5	,0x1EF8	,0x0000), // 'Y' ➔ "Ỹ" U+1EF8 LATIN CAPITAL LETTER Y WITH TILDE
/*<!M><%tilde><y>                                                  */ DEADTRANS( L'y'	,0x00F5	,0x1EF9	,0x0000), // 'y' ➔ "ỹ" U+1EF9 LATIN SMALL LETTER Y WITH TILDE
/*<!M><%tilde><z>                                                  */ DEADTRANS( L'z'	,0x00F5	,0x1D76	,0x0000), // 'z' ➔ "ᵶ" U+1D76 LATIN SMALL LETTER Z WITH MIDDLE TILDE
/*<!M><%tilde><~nbspace>                                           */ DEADTRANS( 0x00A0	,0x00F5	,0x007E	,0x0000), // ' ' ➔ "~" U+007E TILDE
/*<!M><%tilde><~nbthinspace>                                       */ DEADTRANS( 0x202F	,0x00F5	,0x02DC	,0x0000), // ' ' ➔ "˜" U+02DC SMALL TILDE
/*<!M><%tilde><~space>                                             */ DEADTRANS( L' '	,0x00F5	,0x0303	,0x0000), // ' ' ➔ "̃" U+0303 COMBINING TILDE
/*<!M><%tilde><~spacezerowidth>                                    */ DEADTRANS( 0x200B	,0x00F5	,0x0303	,0x0000), // '​' ➔ "̃" U+0303 COMBINING TILDE
/*<!M><%underscore><%equal>                                        */ DEADTRANS( L'='	,0x005F	,0x208C	,0x0000), // '=' ➔ "₌" U+208C SUBSCRIPT EQUALS SIGN
/*<!M><%underscore><%parenleft>                                    */ DEADTRANS( L'('	,0x005F	,0x208D	,0x0000), // '(' ➔ "₍" U+208D SUBSCRIPT LEFT PARENTHESIS
/*<!M><%underscore><%plus>                                         */ DEADTRANS( L'+'	,0x005F	,0x208A	,0x0000), // '+' ➔ "₊" U+208A SUBSCRIPT PLUS SIGN
/*<!M><%underscore><0>                                             */ DEADTRANS( L'0'	,0x005F	,0x2080	,0x0000), // '0' ➔ "₀" U+2080 SUBSCRIPT ZERO
/*<!M><%underscore><1>                                             */ DEADTRANS( L'1'	,0x005F	,0x2081	,0x0000), // '1' ➔ "₁" U+2081 SUBSCRIPT ONE
/*<!M><%underscore><2>                                             */ DEADTRANS( L'2'	,0x005F	,0x2082	,0x0000), // '2' ➔ "₂" U+2082 SUBSCRIPT TWO
/*<!M><%underscore><3>                                             */ DEADTRANS( L'3'	,0x005F	,0x2083	,0x0000), // '3' ➔ "₃" U+2083 SUBSCRIPT THREE
/*<!M><%underscore><4>                                             */ DEADTRANS( L'4'	,0x005F	,0x2084	,0x0000), // '4' ➔ "₄" U+2084 SUBSCRIPT FOUR
/*<!M><%underscore><5>                                             */ DEADTRANS( L'5'	,0x005F	,0x2085	,0x0000), // '5' ➔ "₅" U+2085 SUBSCRIPT FIVE
/*<!M><%underscore><6>                                             */ DEADTRANS( L'6'	,0x005F	,0x2086	,0x0000), // '6' ➔ "₆" U+2086 SUBSCRIPT SIX
/*<!M><%underscore><7>                                             */ DEADTRANS( L'7'	,0x005F	,0x2087	,0x0000), // '7' ➔ "₇" U+2087 SUBSCRIPT SEVEN
/*<!M><%underscore><8>                                             */ DEADTRANS( L'8'	,0x005F	,0x2088	,0x0000), // '8' ➔ "₈" U+2088 SUBSCRIPT EIGHT
/*<!M><%underscore><9>                                             */ DEADTRANS( L'9'	,0x005F	,0x2089	,0x0000), // '9' ➔ "₉" U+2089 SUBSCRIPT NINE
/*<!M><%underscore><A>                                             */ DEADTRANS( L'A'	,0x005F	,0x1D00	,0x0000), // 'A' ➔ "ᴀ" U+1D00 LATIN LETTER SMALL CAPITAL A
/*<!M><%underscore><a>                                             */ DEADTRANS( L'a'	,0x005F	,0x2090	,0x0000), // 'a' ➔ "ₐ" U+2090 LATIN SUBSCRIPT SMALL LETTER A
/*<!M><%underscore><B>                                             */ DEADTRANS( L'B'	,0x005F	,0x0299	,0x0000), // 'B' ➔ "ʙ" U+0299 LATIN LETTER SMALL CAPITAL B
/*<!M><%underscore><b>                                             */ DEADTRANS( L'b'	,0x005F	,0x1D66	,0x0000), // 'b' ➔ "ᵦ" U+1D66 GREEK SUBSCRIPT SMALL LETTER BETA
/*<!M><%underscore><C>                                             */ DEADTRANS( L'C'	,0x005F	,0x1D04	,0x0000), // 'C' ➔ "ᴄ" U+1D04 LATIN LETTER SMALL CAPITAL C
/*<!M><%underscore><c>                                             */ DEADTRANS( L'c'	,0x005F	,0x1D28	,0x0000), // 'c' ➔ "ᴨ" U+1D28 GREEK LETTER SMALL CAPITAL PI
/*<!M><%underscore><D>                                             */ DEADTRANS( L'D'	,0x005F	,0x1D05	,0x0000), // 'D' ➔ "ᴅ" U+1D05 LATIN LETTER SMALL CAPITAL D
/*<!M><%underscore><d>                                             */ DEADTRANS( L'd'	,0x005F	,0x1D29	,0x0000), // 'd' ➔ "ᴩ" U+1D29 GREEK LETTER SMALL CAPITAL RHO
/*<!M><%underscore><E>                                             */ DEADTRANS( L'E'	,0x005F	,0x1D07	,0x0000), // 'E' ➔ "ᴇ" U+1D07 LATIN LETTER SMALL CAPITAL E
/*<!M><%underscore><e>                                             */ DEADTRANS( L'e'	,0x005F	,0x2091	,0x0000), // 'e' ➔ "ₑ" U+2091 LATIN SUBSCRIPT SMALL LETTER E
/*<!M><%underscore><ellipsis>                                      */ DEADTRANS( 0x2026	,0x005F	,0x20E8	,0x0000), // '…' ➔ "⃨" U+20E8 COMBINING TRIPLE UNDERDOT
/*<!M><%underscore><f>                                             */ DEADTRANS( L'f'	,0x005F	,0x1D69	,0x0000), // 'f' ➔ "ᵩ" U+1D69 GREEK SUBSCRIPT SMALL LETTER PHI
/*<!M><%underscore><F>                                             */ DEADTRANS( L'F'	,0x005F	,0xA730	,0x0000), // 'F' ➔ "ꜰ" U+A730 LATIN LETTER SMALL CAPITAL F
/*<!M><%underscore><G>                                             */ DEADTRANS( L'G'	,0x005F	,0x0262	,0x0000), // 'G' ➔ "ɢ" U+0262 LATIN LETTER SMALL CAPITAL G
/*<!M><%underscore><g>                                             */ DEADTRANS( L'g'	,0x005F	,0x1D26	,0x0000), // 'g' ➔ "ᴦ" U+1D26 GREEK LETTER SMALL CAPITAL GAMMA
/*<!M><%underscore><H>                                             */ DEADTRANS( L'H'	,0x005F	,0x029C	,0x0000), // 'H' ➔ "ʜ" U+029C LATIN LETTER SMALL CAPITAL H
/*<!M><%underscore><h>                                             */ DEADTRANS( L'h'	,0x005F	,0x2095	,0x0000), // 'h' ➔ "ₕ" U+2095 LATIN SUBSCRIPT SMALL LETTER H
/*<!M><%underscore><I>                                             */ DEADTRANS( L'I'	,0x005F	,0x026A	,0x0000), // 'I' ➔ "ɪ" U+026A LATIN LETTER SMALL CAPITAL I
/*<!M><%underscore><i>                                             */ DEADTRANS( L'i'	,0x005F	,0x1D62	,0x0000), // 'i' ➔ "ᵢ" U+1D62 LATIN SUBSCRIPT SMALL LETTER I
/*<!M><%underscore><J>                                             */ DEADTRANS( L'J'	,0x005F	,0x1D0A	,0x0000), // 'J' ➔ "ᴊ" U+1D0A LATIN LETTER SMALL CAPITAL J
/*<!M><%underscore><j>                                             */ DEADTRANS( L'j'	,0x005F	,0x2C7C	,0x0000), // 'j' ➔ "ⱼ" U+2C7C LATIN SUBSCRIPT SMALL LETTER J
/*<!M><%underscore><K>                                             */ DEADTRANS( L'K'	,0x005F	,0x1D0B	,0x0000), // 'K' ➔ "ᴋ" U+1D0B LATIN LETTER SMALL CAPITAL K
/*<!M><%underscore><k>                                             */ DEADTRANS( L'k'	,0x005F	,0x2096	,0x0000), // 'k' ➔ "ₖ" U+2096 LATIN SUBSCRIPT SMALL LETTER K
/*<!M><%underscore><L>                                             */ DEADTRANS( L'L'	,0x005F	,0x029F	,0x0000), // 'L' ➔ "ʟ" U+029F LATIN LETTER SMALL CAPITAL L
/*<!M><%underscore><l>                                             */ DEADTRANS( L'l'	,0x005F	,0x2097	,0x0000), // 'l' ➔ "ₗ" U+2097 LATIN SUBSCRIPT SMALL LETTER L
/*<!M><%underscore><M>                                             */ DEADTRANS( L'M'	,0x005F	,0x1D0D	,0x0000), // 'M' ➔ "ᴍ" U+1D0D LATIN LETTER SMALL CAPITAL M
/*<!M><%underscore><m>                                             */ DEADTRANS( L'm'	,0x005F	,0x2098	,0x0000), // 'm' ➔ "ₘ" U+2098 LATIN SUBSCRIPT SMALL LETTER M
/*<!M><%underscore><N>                                             */ DEADTRANS( L'N'	,0x005F	,0x0274	,0x0000), // 'N' ➔ "ɴ" U+0274 LATIN LETTER SMALL CAPITAL N
/*<!M><%underscore><n>                                             */ DEADTRANS( L'n'	,0x005F	,0x2099	,0x0000), // 'n' ➔ "ₙ" U+2099 LATIN SUBSCRIPT SMALL LETTER N
/*<!M><%underscore><O>                                             */ DEADTRANS( L'O'	,0x005F	,0x1D0F	,0x0000), // 'O' ➔ "ᴏ" U+1D0F LATIN LETTER SMALL CAPITAL O
/*<!M><%underscore><o>                                             */ DEADTRANS( L'o'	,0x005F	,0x2092	,0x0000), // 'o' ➔ "ₒ" U+2092 LATIN SUBSCRIPT SMALL LETTER O
/*<!M><%underscore><P>                                             */ DEADTRANS( L'P'	,0x005F	,0x1D18	,0x0000), // 'P' ➔ "ᴘ" U+1D18 LATIN LETTER SMALL CAPITAL P
/*<!M><%underscore><p>                                             */ DEADTRANS( L'p'	,0x005F	,0x209A	,0x0000), // 'p' ➔ "ₚ" U+209A LATIN SUBSCRIPT SMALL LETTER P
/*<!M><%underscore><q>                                             */ DEADTRANS( L'q'	,0x005F	,0x1D68	,0x0000), // 'q' ➔ "ᵨ" U+1D68 GREEK SUBSCRIPT SMALL LETTER RHO
/*<!M><%underscore><Q>                                             */ DEADTRANS( L'Q'	,0x005F	,0xA7AF	,0x0000), // 'Q' ➔ "ꞯ" U+A7AF LATIN LETTER SMALL CAPITAL Q
/*<!M><%underscore><R>                                             */ DEADTRANS( L'R'	,0x005F	,0x0280	,0x0000), // 'R' ➔ "ʀ" U+0280 LATIN LETTER SMALL CAPITAL R
/*<!M><%underscore><r>                                             */ DEADTRANS( L'r'	,0x005F	,0x1D63	,0x0000), // 'r' ➔ "ᵣ" U+1D63 LATIN SUBSCRIPT SMALL LETTER R
/*<!M><%underscore><s>                                             */ DEADTRANS( L's'	,0x005F	,0x209B	,0x0000), // 's' ➔ "ₛ" U+209B LATIN SUBSCRIPT SMALL LETTER S
/*<!M><%underscore><S>                                             */ DEADTRANS( L'S'	,0x005F	,0xA731	,0x0000), // 'S' ➔ "ꜱ" U+A731 LATIN LETTER SMALL CAPITAL S
/*<!M><%underscore><T>                                             */ DEADTRANS( L'T'	,0x005F	,0x1D1B	,0x0000), // 'T' ➔ "ᴛ" U+1D1B LATIN LETTER SMALL CAPITAL T
/*<!M><%underscore><t>                                             */ DEADTRANS( L't'	,0x005F	,0x209C	,0x0000), // 't' ➔ "ₜ" U+209C LATIN SUBSCRIPT SMALL LETTER T
/*<!M><%underscore><U>                                             */ DEADTRANS( L'U'	,0x005F	,0x1D1C	,0x0000), // 'U' ➔ "ᴜ" U+1D1C LATIN LETTER SMALL CAPITAL U
/*<!M><%underscore><u>                                             */ DEADTRANS( L'u'	,0x005F	,0x1D64	,0x0000), // 'u' ➔ "ᵤ" U+1D64 LATIN SUBSCRIPT SMALL LETTER U
/*<!M><%underscore><V>                                             */ DEADTRANS( L'V'	,0x005F	,0x1D20	,0x0000), // 'V' ➔ "ᴠ" U+1D20 LATIN LETTER SMALL CAPITAL V
/*<!M><%underscore><v>                                             */ DEADTRANS( L'v'	,0x005F	,0x1D65	,0x0000), // 'v' ➔ "ᵥ" U+1D65 LATIN SUBSCRIPT SMALL LETTER V
/*<!M><%underscore><W>                                             */ DEADTRANS( L'W'	,0x005F	,0x1D21	,0x0000), // 'W' ➔ "ᴡ" U+1D21 LATIN LETTER SMALL CAPITAL W
/*<!M><%underscore><w>                                             */ DEADTRANS( L'w'	,0x005F	,0x1D27	,0x0000), // 'w' ➔ "ᴧ" U+1D27 GREEK LETTER SMALL CAPITAL LAMDA
/*<!M><%underscore><X>                                             */ DEADTRANS( L'X'	,0x005F	,0x1D6A	,0x0000), // 'X' ➔ "ᵪ" U+1D6A GREEK SUBSCRIPT SMALL LETTER CHI
/*<!M><%underscore><x>                                             */ DEADTRANS( L'x'	,0x005F	,0x2093	,0x0000), // 'x' ➔ "ₓ" U+2093 LATIN SUBSCRIPT SMALL LETTER X
/*<!M><%underscore><Y>                                             */ DEADTRANS( L'Y'	,0x005F	,0x028F	,0x0000), // 'Y' ➔ "ʏ" U+028F LATIN LETTER SMALL CAPITAL Y
/*<!M><%underscore><y>                                             */ DEADTRANS( L'y'	,0x005F	,0x1D67	,0x0000), // 'y' ➔ "ᵧ" U+1D67 GREEK SUBSCRIPT SMALL LETTER GAMMA
/*<!M><%underscore><Z>                                             */ DEADTRANS( L'Z'	,0x005F	,0x1D22	,0x0000), // 'Z' ➔ "ᴢ" U+1D22 LATIN LETTER SMALL CAPITAL Z
/*<!M><%underscore><z>                                             */ DEADTRANS( L'z'	,0x005F	,0x1D2A	,0x0000), // 'z' ➔ "ᴪ" U+1D2A GREEK LETTER SMALL CAPITAL PSI
/*<!M><%underscore><~nbspace>                                      */ DEADTRANS( 0x00A0	,0x005F	,0x005F	,0x0000), // ' ' ➔ "_" U+005F LOW LINE
/*<!M><%underscore><~nbthinspace>                                  */ DEADTRANS( 0x202F	,0x005F	,0x005F	,0x0000), // ' ' ➔ "_" U+005F LOW LINE
/*<!M><%underscore><~space>                                        */ DEADTRANS( L' '	,0x005F	,0x0332	,0x0000), // ' ' ➔ "̲" U+0332 COMBINING LOW LINE
/*<!M><%underscore><~spacezerowidth>                               */ DEADTRANS( 0x200B	,0x005F	,0x0332	,0x0000), // '​' ➔ "̲" U+0332 COMBINING LOW LINE
/*<!M><%apostrophe>                                                */ DEADTRANS( L'\''	,0x00A6	,0x00E1	,0x0001), // Intermediate multikey chain link
/*<!M><%aprightsingquotmark>                                       */ DEADTRANS( 0x2019	,0x00A6	,0x00E1	,0x0001), // Intermediate multikey chain link
/*<!M><%asterisk>                                                  */ DEADTRANS( L'*'	,0x00A6	,0x00E5	,0x0001), // Intermediate multikey chain link
/*<!M><%at>                                                        */ DEADTRANS( L'@'	,0x00A6	,0x03B5	,0x0001), // Intermediate multikey chain link
/*<!M><%backslash>                                                 */ DEADTRANS( L'\\'	,0x00A6	,0x1D19	,0x0001), // Intermediate multikey chain link
/*<!M><%bar>                                                       */ DEADTRANS( L'|'	,0x00A6	,0x0101	,0x0001), // Intermediate multikey chain link
/*<!M><%braceleft>                                                 */ DEADTRANS( L'{'	,0x00A6	,0x0192	,0x0001), // Intermediate multikey chain link
/*<!M><%braceright>                                                */ DEADTRANS( L'}'	,0x00A6	,0x0273	,0x0001), // Intermediate multikey chain link
/*<!M><%bracketleft>                                               */ DEADTRANS( L'['	,0x00A6	,0x01EB	,0x0001), // Intermediate multikey chain link
/*<!M><%bracketright>                                              */ DEADTRANS( L']'	,0x00A6	,0x1EBB	,0x0001), // Intermediate multikey chain link
/*<!M><%circum>                                                    */ DEADTRANS( L'^'	,0x00A6	,0x005E	,0x0001), // Intermediate multikey chain link
/*<!M><%colon>                                                     */ DEADTRANS( L':'	,0x00A6	,0x00EB	,0x0001), // Intermediate multikey chain link
/*<!M><%comma>                                                     */ DEADTRANS( L','	,0x00A6	,0x00E7	,0x0001), // Intermediate multikey chain link
/*<!M><%dollar>                                                    */ DEADTRANS( L'$'	,0x00A6	,0x00A4	,0x0001), // Intermediate multikey chain link
/*<!M><%equal>                                                     */ DEADTRANS( L'='	,0x00A6	,0x2690	,0x0001), // Intermediate multikey chain link
/*<!M><%exclam>                                                    */ DEADTRANS( L'!'	,0x00A6	,0x1E05	,0x0001), // Intermediate multikey chain link
/*<!M><%excsection>                                                */ DEADTRANS( 0x00A7	,0x00A6	,0x1E05	,0x0001), // Intermediate multikey chain link
/*<!M><%grave>                                                     */ DEADTRANS( L'`'	,0x00A6	,0x00F2	,0x0001), // Intermediate multikey chain link
/*<!M><%greater>                                                   */ DEADTRANS( L'>'	,0x00A6	,0x021F	,0x0001), // Intermediate multikey chain link
/*<!M><%hash>                                                      */ DEADTRANS( L'#'	,0x00A6	,0x2460	,0x0001), // Intermediate multikey chain link
/*<!M><%less>                                                      */ DEADTRANS( L'<'	,0x00A6	,0x00EA	,0x0001), // Intermediate multikey chain link
/*<!M><%minus>                                                     */ DEADTRANS( L'-'	,0x00A6	,0x024D	,0x0001), // Intermediate multikey chain link
/*<!M><%parenleft>                                                 */ DEADTRANS( L'('	,0x00A6	,0x0213	,0x0001), // Intermediate multikey chain link
/*<!M><%parenright>                                                */ DEADTRANS( L')'	,0x00A6	,0x0115	,0x0001), // Intermediate multikey chain link
/*<!M><%percent>                                                   */ DEADTRANS( L'%'	,0x00A6	,0x0250	,0x0001), // Intermediate multikey chain link
/*<!M><%period>                                                    */ DEADTRANS( L'.'	,0x00A6	,0x1E57	,0x0001), // Intermediate multikey chain link
/*<!M><%plus>                                                      */ DEADTRANS( L'+'	,0x00A6	,0x01A1	,0x0001), // Intermediate multikey chain link
/*<!M><%quotEuroSign>                                              */ DEADTRANS( 0x20AC	,0x00A6	,0x0151	,0x0001), // Intermediate multikey chain link
/*<!M><%quotedbl>                                                  */ DEADTRANS( L'"'	,0x00A6	,0x0151	,0x0001), // Intermediate multikey chain link
/*<!M><%semicolon>                                                 */ DEADTRANS( L';'	,0x00A6	,0x0219	,0x0001), // Intermediate multikey chain link
/*<!M><%slash>                                                     */ DEADTRANS( L'/'	,0x00A6	,0x00F8	,0x0001), // Intermediate multikey chain link
/*<!M><%tilde>                                                     */ DEADTRANS( L'~'	,0x00A6	,0x00F5	,0x0001), // Intermediate multikey chain link
/*<!M><%underscore>                                                */ DEADTRANS( L'_'	,0x00A6	,0x005F	,0x0001), // Intermediate multikey chain link

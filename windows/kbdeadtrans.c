 /*****************************************************************************\
* Module name: kbdeadtrans.c
*
* Dead key content
*
* Copyright:
* 1985..2001 Microsoft Corporation pro parte
* 2014..2025 Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Exclude multikey until it is debugged    6.1.3.2.1 Sat 2025-11-15T0453+0100
* Uppercase the legacy dead key code       6.1.3.2.0 Fri 2025-11-14T1327+0100
* Exclude multikey equivalents             6.1.3.1.0 Fri 2025-11-14T0829+0100
* Include multikey sequences in 2 files    6.1.3.0.0 Fri 2025-11-14T0554+0100
* Split off kbdeadtrans-deadkeys.c         6.1.2.0.0 Thu 2025-10-30T0026+0100
* Support diacriticized Greek letters too  6.1.1.0.0 Wed 2025-10-29T0201+0100
* Complete dead key chains                 6.1.0.2.0 Thu 2025-10-23T2152+0200
* Test overlapping dead characters         6.1.0.1.0 Tue 2025-10-21T1850+0200
* Test generated dead key chain            6.1.0.0.0 Sat 2025-10-18T2208+0200
* Update transpiled dead key data         6.0.10.0.3 Sun 2025-10-12T0108+0200
* Add annotations about backporting       6.0.10.0.2 Sun 2025-10-12T0025+0200
* Add annotation about U+107A2            6.0.10.0.1 Sat 2025-10-11T2334+0200
* Improve readability, add progressmark   6.0.10.0.0 Sat 2025-10-11T2247+0200
* Update transpiled dead key data          6.0.8.0.0 Thu 2025-09-25T1145+0200
* Update transpiled dead key data          6.0.7.3.0 Mon 2025-09-22T0640+0200
* Update after correcting sortability      6.0.7.2.1 Sun 2025-09-21T0447+0200
* Move kbdeadtrans.c #inc to kbcommon.c    6.0.7.2.0 Tue 2025-09-16T0315+0200
* Outline brackets U27E6.. in !acute       6.0.7.1.2 Sun 2025-09-14T1926+0200
* Outline brackets U27E6.. in !tilde       6.0.7.1.1 Sun 2025-09-14T1911+0200
* "°" U00B0 2 ➔ "⋆" U22C6 in !abovering    6.0.7.1.0 Fri 2025-09-12T0441+0200
* Outline brackets U27E6.. in !grave       6.0.7.0.0 Wed 2025-09-03T0803+0200
* Improve Polynesian French variant        6.0.6.0.0 Tue 2025-09-02T1459+0200
* Upgrade to Unicode 17.0                  6.0.4.2.0 Wed 2025-08-27T2006+0200
* Move DEADTRANS calls to kbdeadtrans.c    6.0.2.1.0 Tue 2025-08-19T1952+0200
* Add partial file kbdeadtrans.c           6.0.2.1.0 Tue 2025-08-19T1952+0200
*
* By courtesy of respondents to:
* https://stackoverflow.com/questions/11334371/cant-we-include-c-file
*
* This file is included in kbcommon-2.c.
*
* This file includes the files containing the transpiled dead key data, so as
* to not exceed the 2MB file size limit of github.com (not github.dev).
* See #include "kbdeadtrans-deadkeys.c"
* See #include "kbdeadtrans-multikey.c"
*
*
* DEADTRANS macro calls
*
* On Windows, the dead key output is restricted to the low surrogate. An input
* method for the high surrogates is provided separately at the root of related
* dead keys, with U+200B ZERO WIDTH SPACE as a base character, in synergy with
* most dead keys, at level 4 of the space bar in French mode.
*
* The number of required high surrogates amounts to eight:
*
*     D801, D807,
*     D835, D837, D83C, D83D, D83E,
*     DB40.
*
* These are dispatched among dead keys:
*
*     D801 dead_superscript (modifier letters)
*     D807 dead_turned [dead_turned] (U+11FB0 "𑾰" LISU LETTER YHA)
*     D835 dead_group (mathematical alphanumeric symbols)
*     D837 dead_bar, dead_breve, dead_hook, dead_retroflexhook, others (Latin)
*     D83C dead_flag, dead_greek (flag letters, squared letters)
*     D83D dead_doubleacute, dead_acute, others (ornamental quotation marks)
*     D83E dead_stroke, dead_group 11 and 12 as built-in (wide-headed arrows)
*     DB40 dead_flag as built-in (tag characters)
*
* The output is directly in C, where an array of DEADTRANS macro calls makes
* for a flat layout of dead key data, while in KLC format, the data is grouped
* under DEADKEY headers. When KbdUTool transpiles from KLC to C, comments are
* ignored under the assumption that development happens in KLC only. But this
* is just not possible, given that KbdUTool’s KLC-to-C transpiler is broken, as
* it is unable to handle dead characters above 0x0FFF and to transpile KanaLock
* levels. Moreover, ligatures are transpiled only up to 5 code units due to the
* general header not supporting the architectural limit almost exhausted by the
* subdivision flags. And KLC only supports end-of-line comments, while leading
* block comments (in addition to EOL comments) are best for human readability,
* and with long lists are more readable than the grouped layout.
*
* Another upside of writing dead key data in C is that any DEADTRANS macro call
* can be overridden by a similar call, with the same input and the same dead
* character, but another output, provided that the valid call precedes in the
* source code.
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA DEADKEY aDeadKey[] = {

/*****************************************************************************\
* High surrogates
*
\*****************************************************************************/

/*<!dead_abovedot>     */ DEADTRANS( 0x200B ,0x1E57 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_abovehook>    */ DEADTRANS( 0x200B ,0x1EBB ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_abovering>    */ DEADTRANS( 0x200B ,0x00E5 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_acute>        */ DEADTRANS( 0x200B ,0x00E1 ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks
/*<!dead_bar>          */ DEADTRANS( 0x200B ,0x024D ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_belowcomma>   */ DEADTRANS( 0x200B ,0x0219 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_belowdot>     */ DEADTRANS( 0x200B ,0x1E05 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_breve>        */ DEADTRANS( 0x200B ,0x0115 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_caron>        */ DEADTRANS( 0x200B ,0x021F ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_cedilla>      */ DEADTRANS( 0x200B ,0x00E7 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_circumflex>   */ DEADTRANS( 0x200B ,0x00EA ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks
/*<!dead_currency>     */ DEADTRANS( 0x200B ,0x00A4 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_diaeresis>    */ DEADTRANS( 0x200B ,0x00EB ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks
/*<!dead_doubleacute>  */ DEADTRANS( 0x200B ,0x0151 ,0xD83D ,0x0000 ), // High surrogate for ornamental quotation marks
/*<!dead_flag>         */ DEADTRANS( 0x200B ,0x2690 ,0xD83C ,0x0000 ), // High surrogate for flag letters, squared letters
/*<!dead_grave>        */ DEADTRANS( 0x200B ,0x00F2 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_greek>        */ DEADTRANS( 0x200B ,0x03B5 ,0xD83C ,0x0000 ), // High surrogate for flag letters, squared letters
/*<!dead_group>        */ DEADTRANS( 0x200B ,0x2460 ,0xD835 ,0x0000 ), // High surrogate for mathematical alphanumeric symbols
/*<!dead_hook>         */ DEADTRANS( 0x200B ,0x0192 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_horn>         */ DEADTRANS( 0x200B ,0x01A1 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_invertedbreve>*/ DEADTRANS( 0x200B ,0x0213 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_macron>       */ DEADTRANS( 0x200B ,0x0101 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_ogonek>       */ DEADTRANS( 0x200B ,0x01EB ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_retroflexhook>*/ DEADTRANS( 0x200B ,0x0273 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_reversed>     */ DEADTRANS( 0x200B ,0x1D19 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_stroke>       */ DEADTRANS( 0x200B ,0x00F8 ,0xD83E ,0x0000 ), // High surrogate for wide-headed arrows
/*<!dead_subscript>    */ DEADTRANS( 0x200B ,L'_'   ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_superscript>  */ DEADTRANS( 0x200B ,L'^'   ,0xD801 ,0x0000 ), // High surrogate for modifier letters
/*<!dead_tilde>        */ DEADTRANS( 0x200B ,0x00F5 ,0xD837 ,0x0000 ), // High surrogate for Latin
/*<!dead_turned>       */ DEADTRANS( 0x200B ,0x0250 ,0xD807 ,0x0000 ), // High surrogate for U+11FB0 "𑾰" LISU LETTER YHA

/*****************************************************************************\
* Diacriticized letter key emulations
*
* On Windows, the dead key output is restricted to a single code unit, due to a
* bad design decision, based on a misconception of Unicode as a 16-bit charset,
* and on the ignorance of the Unicode encoding model using combining diacritics
* whenever possible, and the Unicode recommendation to support composed letters
* by dead keys. Since extending the DEADTRANS macro to support 5 of the missing
* code units would be pointless, due to Windows’ inability to look the array up
* for the additional code units and append them to the output if non-null, the
* degradation of the user experience compared to Linux and macOS (and ChromeOS’
* precompiled Linux layouts) should be mitigated as far as possible.
*
* On Linux and macOS, the "ê" key emulation supports uppercase, "êq" expands to
* "êqu", and "x" yields the "êch" trigraph. On Windows, lowercase digraphs work
* as intended due to default handling of the dead character. As uppercase would
* be mixed with lowercase "ê", this UX disruption is mitigated in that the set
* of unsupported base letters output "Ê"/"ê" as the start of the full sequence.
*
* A "ç" key is also emulated, for Canadian French.
*
\*****************************************************************************/

/*<!dead_circumflex>*/ DEADTRANS( L'K' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'L' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'M' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'N' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'P' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'Q' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'R' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'T' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'V' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'X' ,0x00EA ,0x00CA ,0x0000 ), // "Ê" LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*<!dead_circumflex>*/ DEADTRANS( L'x' ,0x00EA ,0x00EA ,0x0000 ), // "ê" LATIN SMALL LETTER E WITH CIRCUMFLEX
/*<!dead_cedilla>   */ DEADTRANS( L'A' ,0x00E7 ,0x00C7 ,0x0000 ), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA
/*<!dead_cedilla>   */ DEADTRANS( L'O' ,0x00E7 ,0x00C7 ,0x0000 ), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA
/*<!dead_cedilla>   */ DEADTRANS( L'U' ,0x00E7 ,0x00C7 ,0x0000 ), // "Ç" LATIN CAPITAL LETTER C WITH CEDILLA

/*****************************************************************************\
* Flag letters
*
* Windows has flag letters on live keys, level AltLe (like Letter emoji), and
* flag letters with an appended word joiner one level up for writing in letter
* emoji fluently. AltLe is on top of the Caps Lock key.
*
* As a result, flag letters by dead keys on Windows are pointless, the more as
* they would need to be adapted to Windows, where a single dead key press is
* to output the regional indicator symbol letter’s low surrogate right away, as
* the system is unable to output more than a single code unit (as opposed to
* Linux and macOS, where the single-press output fits the needs of writing in
* letter emoji, by appending a word joiner U2060 WJ).
*
\*****************************************************************************/

/*<!dead_flag>*/ DEADTRANS( L'a'	,0x2690	,0xDDE6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E6 "🇦" REGIONAL INDICATOR SYMBOL LETTER A
/*<!dead_flag>*/ DEADTRANS( L'A'	,0x2690	,0xDDE6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E6 "🇦" REGIONAL INDICATOR SYMBOL LETTER A
/*<!dead_flag>*/ DEADTRANS( L'b'	,0x2690	,0xDDE7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E7 "🇧" REGIONAL INDICATOR SYMBOL LETTER B
/*<!dead_flag>*/ DEADTRANS( L'B'	,0x2690	,0xDDE7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E7 "🇧" REGIONAL INDICATOR SYMBOL LETTER B
/*<!dead_flag>*/ DEADTRANS( L'c'	,0x2690	,0xDDE8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E8 "🇨" REGIONAL INDICATOR SYMBOL LETTER C
/*<!dead_flag>*/ DEADTRANS( L'C'	,0x2690	,0xDDE8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E8 "🇨" REGIONAL INDICATOR SYMBOL LETTER C
/*<!dead_flag>*/ DEADTRANS( L'd'	,0x2690	,0xDDE9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E9 "🇩" REGIONAL INDICATOR SYMBOL LETTER D
/*<!dead_flag>*/ DEADTRANS( L'D'	,0x2690	,0xDDE9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1E9 "🇩" REGIONAL INDICATOR SYMBOL LETTER D
/*<!dead_flag>*/ DEADTRANS( L'e'	,0x2690	,0xDDEA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EA "🇪" REGIONAL INDICATOR SYMBOL LETTER E
/*<!dead_flag>*/ DEADTRANS( L'E'	,0x2690	,0xDDEA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EA "🇪" REGIONAL INDICATOR SYMBOL LETTER E
/*<!dead_flag>*/ DEADTRANS( L'f'	,0x2690	,0xDDEB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EB "🇫" REGIONAL INDICATOR SYMBOL LETTER F
/*<!dead_flag>*/ DEADTRANS( L'F'	,0x2690	,0xDDEB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EB "🇫" REGIONAL INDICATOR SYMBOL LETTER F
/*<!dead_flag>*/ DEADTRANS( L'g'	,0x2690	,0xDDEC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EC "🇬" REGIONAL INDICATOR SYMBOL LETTER G
/*<!dead_flag>*/ DEADTRANS( L'G'	,0x2690	,0xDDEC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EC "🇬" REGIONAL INDICATOR SYMBOL LETTER G
/*<!dead_flag>*/ DEADTRANS( L'h'	,0x2690	,0xDDED	,0x0000	), // High surrogate: D83C; Unicode: U+1F1ED "🇭" REGIONAL INDICATOR SYMBOL LETTER H
/*<!dead_flag>*/ DEADTRANS( L'H'	,0x2690	,0xDDED	,0x0000	), // High surrogate: D83C; Unicode: U+1F1ED "🇭" REGIONAL INDICATOR SYMBOL LETTER H
/*<!dead_flag>*/ DEADTRANS( L'i'	,0x2690	,0xDDEE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EE "🇮" REGIONAL INDICATOR SYMBOL LETTER I
/*<!dead_flag>*/ DEADTRANS( L'I'	,0x2690	,0xDDEE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EE "🇮" REGIONAL INDICATOR SYMBOL LETTER I
/*<!dead_flag>*/ DEADTRANS( L'j'	,0x2690	,0xDDEF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EF "🇯" REGIONAL INDICATOR SYMBOL LETTER J
/*<!dead_flag>*/ DEADTRANS( L'J'	,0x2690	,0xDDEF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1EF "🇯" REGIONAL INDICATOR SYMBOL LETTER J
/*<!dead_flag>*/ DEADTRANS( L'k'	,0x2690	,0xDDF0	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F0 "🇰" REGIONAL INDICATOR SYMBOL LETTER K
/*<!dead_flag>*/ DEADTRANS( L'K'	,0x2690	,0xDDF0	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F0 "🇰" REGIONAL INDICATOR SYMBOL LETTER K
/*<!dead_flag>*/ DEADTRANS( L'l'	,0x2690	,0xDDF1	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F1 "🇱" REGIONAL INDICATOR SYMBOL LETTER L
/*<!dead_flag>*/ DEADTRANS( L'L'	,0x2690	,0xDDF1	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F1 "🇱" REGIONAL INDICATOR SYMBOL LETTER L
/*<!dead_flag>*/ DEADTRANS( L'm'	,0x2690	,0xDDF2	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F2 "🇲" REGIONAL INDICATOR SYMBOL LETTER M
/*<!dead_flag>*/ DEADTRANS( L'M'	,0x2690	,0xDDF2	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F2 "🇲" REGIONAL INDICATOR SYMBOL LETTER M
/*<!dead_flag>*/ DEADTRANS( L'n'	,0x2690	,0xDDF3	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F3 "🇳" REGIONAL INDICATOR SYMBOL LETTER N
/*<!dead_flag>*/ DEADTRANS( L'N'	,0x2690	,0xDDF3	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F3 "🇳" REGIONAL INDICATOR SYMBOL LETTER N
/*<!dead_flag>*/ DEADTRANS( L'o'	,0x2690	,0xDDF4	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F4 "🇴" REGIONAL INDICATOR SYMBOL LETTER O
/*<!dead_flag>*/ DEADTRANS( L'O'	,0x2690	,0xDDF4	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F4 "🇴" REGIONAL INDICATOR SYMBOL LETTER O
/*<!dead_flag>*/ DEADTRANS( L'p'	,0x2690	,0xDDF5	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F5 "🇵" REGIONAL INDICATOR SYMBOL LETTER P
/*<!dead_flag>*/ DEADTRANS( L'P'	,0x2690	,0xDDF5	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F5 "🇵" REGIONAL INDICATOR SYMBOL LETTER P
/*<!dead_flag>*/ DEADTRANS( L'q'	,0x2690	,0xDDF6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F6 "🇶" REGIONAL INDICATOR SYMBOL LETTER Q
/*<!dead_flag>*/ DEADTRANS( L'Q'	,0x2690	,0xDDF6	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F6 "🇶" REGIONAL INDICATOR SYMBOL LETTER Q
/*<!dead_flag>*/ DEADTRANS( L'r'	,0x2690	,0xDDF7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F7 "🇷" REGIONAL INDICATOR SYMBOL LETTER R
/*<!dead_flag>*/ DEADTRANS( L'R'	,0x2690	,0xDDF7	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F7 "🇷" REGIONAL INDICATOR SYMBOL LETTER R
/*<!dead_flag>*/ DEADTRANS( L's'	,0x2690	,0xDDF8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F8 "🇸" REGIONAL INDICATOR SYMBOL LETTER S
/*<!dead_flag>*/ DEADTRANS( L'S'	,0x2690	,0xDDF8	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F8 "🇸" REGIONAL INDICATOR SYMBOL LETTER S
/*<!dead_flag>*/ DEADTRANS( L't'	,0x2690	,0xDDF9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F9 "🇹" REGIONAL INDICATOR SYMBOL LETTER T
/*<!dead_flag>*/ DEADTRANS( L'T'	,0x2690	,0xDDF9	,0x0000	), // High surrogate: D83C; Unicode: U+1F1F9 "🇹" REGIONAL INDICATOR SYMBOL LETTER T
/*<!dead_flag>*/ DEADTRANS( L'u'	,0x2690	,0xDDFA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FA "🇺" REGIONAL INDICATOR SYMBOL LETTER U
/*<!dead_flag>*/ DEADTRANS( L'U'	,0x2690	,0xDDFA	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FA "🇺" REGIONAL INDICATOR SYMBOL LETTER U
/*<!dead_flag>*/ DEADTRANS( L'v'	,0x2690	,0xDDFB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FB "🇻" REGIONAL INDICATOR SYMBOL LETTER V
/*<!dead_flag>*/ DEADTRANS( L'V'	,0x2690	,0xDDFB	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FB "🇻" REGIONAL INDICATOR SYMBOL LETTER V
/*<!dead_flag>*/ DEADTRANS( L'w'	,0x2690	,0xDDFC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FC "🇼" REGIONAL INDICATOR SYMBOL LETTER W
/*<!dead_flag>*/ DEADTRANS( L'W'	,0x2690	,0xDDFC	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FC "🇼" REGIONAL INDICATOR SYMBOL LETTER W
/*<!dead_flag>*/ DEADTRANS( L'x'	,0x2690	,0xDDFD	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FD "🇽" REGIONAL INDICATOR SYMBOL LETTER X
/*<!dead_flag>*/ DEADTRANS( L'X'	,0x2690	,0xDDFD	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FD "🇽" REGIONAL INDICATOR SYMBOL LETTER X
/*<!dead_flag>*/ DEADTRANS( L'y'	,0x2690	,0xDDFE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FE "🇾" REGIONAL INDICATOR SYMBOL LETTER Y
/*<!dead_flag>*/ DEADTRANS( L'Y'	,0x2690	,0xDDFE	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FE "🇾" REGIONAL INDICATOR SYMBOL LETTER Y
/*<!dead_flag>*/ DEADTRANS( L'z'	,0x2690	,0xDDFF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FF "🇿" REGIONAL INDICATOR SYMBOL LETTER Z
/*<!dead_flag>*/ DEADTRANS( L'Z'	,0x2690	,0xDDFF	,0x0000	), // High surrogate: D83C; Unicode: U+1F1FF "🇿" REGIONAL INDICATOR SYMBOL LETTER Z

/*****************************************************************************\
* Diacritical and transformational dead key content
*
* This is up-to-date and overrides the legacy dead key content.
* See kbdeadtrans-deadkeys.c
*
\*****************************************************************************/
#include "kbdeadtrans-deadkeys.c"

/*****************************************************************************\
* Dedicated multikey sequences
*
* This is a broken transpilation awaiting bugfixes in the transpiler.
* https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/dead-key-convert.pl
* See kbdeadtrans-multikey.c
*
#include "kbdeadtrans-multikey.c"
\*****************************************************************************/

/*****************************************************************************\
* Multikey equivalents of dead keys
*
* This is another broken transpilation. Given that multikey equivalents of
* dead keys are a Linux feature fostered by mutualized dead key configuration,
* this can be skipped on Windows in order to limit the layout driver file size
* under the menace of a total keyboard blackout.
* See kbdeadtrans-multikey-equivalents.c
*
#include "kbdeadtrans-multikey-equivalents.c"
\*****************************************************************************/

/*****************************************************************************\
* Legacy dead key content
*
* This is partly overridden by the transpilations included above.
*
* Many of the never overridden DEADTRANS calls are yet to be ported to the
* dead key source Compose.yml, because these are valuable complements with
* respect to the enhanced user experience design goal, and were skipped to
* streamline and speed up the initial support on Linux.
*
* Some shortcuts are not ported because they have been redesigned, and the
* current option is better, such as "a" with tilde in the acute accent dead key
* by "é" mnemonically near "a", instead of former "à", that is now used for "o"
* with tilde, because it is close to the "o" key.
*
* Many others cannot be ported, such as a shortcut for "n" with tilde in
* the acute accent dead key with "b" as a base character due to its use in
* Breton, as they are particular to Windows, while regular support includes
* composed letters, "b́" for instance.
*
* These Windows-specific shortcuts, however, are required to compensate users
* for the defective dead key implementation that disregards official Unicode
* recommendations as of supporting composed letters by dead keys, and worse,
* the UTF-16 encoding model of the Supplemental Multilingual Plane on Windows.
*
* Progress is not always linear, but "//@" marks the point down to where
* all DEADTRANS calls have been reviewed.
*
\*****************************************************************************/

/*ACUTE&DOT_ABOVE    */	DEADTRANS(	L'S'	,0x1E65	,0x1E64	,0x0000	), // LATIN CAPITAL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE&DOT_ABOVE    */	DEADTRANS(	L's'	,0x1E65	,0x1E65	,0x0000	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00A0	,0x00E1	,0x00B4	,0x0000	), // ACUTE ACCENT
/*ACUTE_ACCENT       */	DEADTRANS(	0x202F	,0x00E1	,0x02CA	,0x0000	), // MODIFIER LETTER ACUTE ACCENT
/*ACUTE_ACCENT       */	DEADTRANS(	L'A'	,0x00E1	,0x00C1	,0x0000	), // LATIN CAPITAL LETTER A WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'a'	,0x00E1	,0x00E1	,0x0000	), // LATIN SMALL LETTER A WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'B'	,0x00E1	,0x00D1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	L'b'	,0x00E1	,0x00F1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	L'C'	,0x00E1	,0x0106	,0x0000	), // LATIN CAPITAL LETTER C WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'c'	,0x00E1	,0x0107	,0x0000	), // LATIN SMALL LETTER C WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'D'	,0x00E1	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*ACUTE_ACCENT       */	DEADTRANS(	L'd'	,0x00E1	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*ACUTE_ACCENT       */	DEADTRANS(	L'E'	,0x00E1	,0x00C9	,0x0000	), // LATIN CAPITAL LETTER E WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'e'	,0x00E1	,0x00E9	,0x0000	), // LATIN SMALL LETTER E WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'F'	,0x00E1	,0x018E	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*ACUTE_ACCENT       */	DEADTRANS(	L'f'	,0x00E1	,0x01DD	,0x0000	), // LATIN SMALL LETTER TURNED E
/*ACUTE_ACCENT       */	DEADTRANS(	L'G'	,0x00E1	,0x01F4	,0x0000	), // LATIN CAPITAL LETTER G WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'g'	,0x00E1	,0x01F5	,0x0000	), // LATIN SMALL LETTER G WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'H'	,0x00E1	,0x1E24	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT BELOW
/*ACUTE_ACCENT       */	DEADTRANS(	L'h'	,0x00E1	,0x1E25	,0x0000	), // LATIN SMALL LETTER H WITH DOT BELOW
/*ACUTE_ACCENT       */	DEADTRANS(	L'I'	,0x00E1	,0x00CD	,0x0000	), // LATIN CAPITAL LETTER I WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'i'	,0x00E1	,0x00ED	,0x0000	), // LATIN SMALL LETTER I WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'J'	,0x00E1	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'j'	,0x00E1	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'K'	,0x00E1	,0x1E30	,0x0000	), // LATIN CAPITAL LETTER K WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'k'	,0x00E1	,0x1E31	,0x0000	), // LATIN SMALL LETTER K WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'L'	,0x00E1	,0x0139	,0x0000	), // LATIN CAPITAL LETTER L WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'l'	,0x00E1	,0x013A	,0x0000	), // LATIN SMALL LETTER L WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'M'	,0x00E1	,0x1E3E	,0x0000	), // LATIN CAPITAL LETTER M WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'm'	,0x00E1	,0x1E3F	,0x0000	), // LATIN SMALL LETTER M WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'N'	,0x00E1	,0x0143	,0x0000	), // LATIN CAPITAL LETTER N WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'n'	,0x00E1	,0x0144	,0x0000	), // LATIN SMALL LETTER N WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'O'	,0x00E1	,0x00D3	,0x0000	), // LATIN CAPITAL LETTER O WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'o'	,0x00E1	,0x00F3	,0x0000	), // LATIN SMALL LETTER O WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'P'	,0x00E1	,0x1E54	,0x0000	), // LATIN CAPITAL LETTER P WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'p'	,0x00E1	,0x1E55	,0x0000	), // LATIN SMALL LETTER P WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'Q'	,0x00E1	,0x00A6	,0x0001	), // BROKEN BAR
/*ACUTE_ACCENT       */	DEADTRANS(	L'q'	,0x00E1	,0x00A6	,0x0001	), // BROKEN BAR
/*ACUTE_ACCENT       */	DEADTRANS(	L'R'	,0x00E1	,0x0154	,0x0000	), // LATIN CAPITAL LETTER R WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'r'	,0x00E1	,0x0155	,0x0000	), // LATIN SMALL LETTER R WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'S'	,0x00E1	,0x015A	,0x0000	), // LATIN CAPITAL LETTER S WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L's'	,0x00E1	,0x015B	,0x0000	), // LATIN SMALL LETTER S WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'T'	,0x00E1	,0x01AE	,0x0000	), // LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L't'	,0x00E1	,0x0288	,0x0000	), // LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*ACUTE_ACCENT       */	DEADTRANS(	L'U'	,0x00E1	,0x00DA	,0x0000	), // LATIN CAPITAL LETTER U WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'u'	,0x00E1	,0x00FA	,0x0000	), // LATIN SMALL LETTER U WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'V'	,0x00E1	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*ACUTE_ACCENT       */	DEADTRANS(	L'v'	,0x00E1	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*ACUTE_ACCENT       */	DEADTRANS(	L'W'	,0x00E1	,0x1E82	,0x0000	), // LATIN CAPITAL LETTER W WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'w'	,0x00E1	,0x1E83	,0x0000	), // LATIN SMALL LETTER W WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'X'	,0x00E1	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*ACUTE_ACCENT       */	DEADTRANS(	L'x'	,0x00E1	,0x014B	,0x0000	), // LATIN SMALL LETTER ENG
/*ACUTE_ACCENT       */	DEADTRANS(	L'Y'	,0x00E1	,0x00DD	,0x0000	), // LATIN CAPITAL LETTER Y WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'y'	,0x00E1	,0x00FD	,0x0000	), // LATIN SMALL LETTER Y WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'Z'	,0x00E1	,0x0179	,0x0000	), // LATIN CAPITAL LETTER Z WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'z'	,0x00E1	,0x017A	,0x0000	), // LATIN SMALL LETTER Z WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00C0	,0x00E1	,0x00C3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E0	,0x00E1	,0x00E3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00C6	,0x00E1	,0x01FC	,0x0000	), // LATIN CAPITAL LETTER AE WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E6	,0x00E1	,0x01FD	,0x0000	), // LATIN SMALL LETTER AE WITH ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00C7	,0x00E1	,0x1E08	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E7	,0x00E1	,0x1E09	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00C8	,0x00E1	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E8	,0x00E1	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x00C9	,0x00E1	,0x00D5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E9	,0x00E1	,0x00F5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0152	,0x00E1	,0x00D5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0153	,0x00E1	,0x00F5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00D9	,0x00E1	,0x00D1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00F9	,0x00E1	,0x00F1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*ACUTE_ACCENT       */	DEADTRANS(	L'1'	,0x00E1	,0x2032	,0x0000	), // PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'2'	,0x00E1	,0x2033	,0x0000	), // DOUBLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'3'	,0x00E1	,0x2034	,0x0000	), // TRIPLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	L'4'	,0x00E1	,0x2057	,0x0000	), // QUADRUPLE PRIME
/*ACUTE_ACCENT       */	DEADTRANS(	0x0027	,0x00E1	,0x2019	,0x0000	), // RIGHT SINGLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0022	,0x00E1	,0x201D	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0023	,0x00E1	,0x201D	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x0021	,0x00E1	,0x2020	,0x0000	), // DAGGER
/*ACUTE_ACCENT       */	DEADTRANS(	0x003F	,0x00E1	,0x2021	,0x0000	), // DOUBLE DAGGER
/*ACUTE_ACCENT       */	DEADTRANS(	0x0025	,0x00E1	,0x2030	,0x0000	), // PER MILLE SIGN
/*ACUTE_ACCENT       */	DEADTRANS(	0x0028	,0x00E1	,0xAB45	,0x0000	), // LATIN SMALL LETTER STIRRUP R
/*ACUTE_ACCENT       */	DEADTRANS(	0x0029	,0x00E1	,0x1EAF	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002A	,0x00E1	,0x2022	,0x0000	), // BULLET
/*ACUTE_ACCENT       */	DEADTRANS(	0x002B	,0x00E1	,0x00B1	,0x0000	), // PLUS-MINUS SIGN
/*ACUTE_ACCENT       */	DEADTRANS(	0x002C	,0x00E1	,0x1EDB	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002D	,0x00E1	,0x2013	,0x0000	), // EN DASH
/*ACUTE_ACCENT       */	DEADTRANS(	0x002E	,0x00E1	,0x1E65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x002F	,0x00E1	,0x01FF	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	L'7'	,0x00E1	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*ACUTE_ACCENT       */	DEADTRANS(	0x003A	,0x00E1	,0x01D8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x003C	,0x00E1	,0x1EBF	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x003D	,0x00E1	,0x2260	,0x0000	), // NOT EQUAL TO
/*ACUTE_ACCENT       */	DEADTRANS(	0x00B0	,0x00E1	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*ACUTE_ACCENT       */	DEADTRANS(	0x0040	,0x00E1	,0x25CC	,0x0000	), // DOTTED CIRCLE
/*ACUTE_ACCENT       */	DEADTRANS(	0x007C	,0x00E1	,0x1E53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0060	,0x00E1	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*ACUTE_ACCENT       */	DEADTRANS(	0x007E	,0x00E1	,0x1E4D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00AB	,0x00E1	,0x201C	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x00BB	,0x00E1	,0x201D	,0x0000	), // RIGHT DOUBLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x00E1	,0x00E1	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00EA	,0x00E1	,0x1ED1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00EB	,0x00E1	,0x01D8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x00F2	,0x00E1	,0x021F	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*ACUTE_ACCENT       */	DEADTRANS(	0x00F8	,0x00E1	,0x01FF	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x2019	,0x00E1	,0x2019	,0x0000	), // RIGHT SINGLE QUOTATION MARK
/*ACUTE_ACCENT       */	DEADTRANS(	0x2212	,0x00E1	,0x2012	,0x0000	), // FIGURE DASH
/*ACUTE_ACCENT       */	DEADTRANS(	0x2610	,0x00E1	,0x2752	,0x0000	), // UPPER RIGHT SHADOWED WHITE SQUARE
/*ACUTE_ACCENT       */	DEADTRANS(	0x222A	,0x00E1	,0x2282	,0x0000	), // SUBSET OF
/*ACUTE_ACCENT       */	DEADTRANS(	0x0101	,0x00E1	,0x1E53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0115	,0x00E1	,0x1EAF	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x0229	,0x00E1	,0x1EDB	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x01A1	,0x00E1	,0x1EDB	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*ACUTE_ACCENT       */	DEADTRANS(	0x1E57	,0x00E1	,0x1E65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*ACUTE_BELOW        */	DEADTRANS(	0x0020	,0x02CF	,0x0317	,0x0000	), // COMBINING ACUTE ACCENT BELOW
/*ACUTE_BELOW        */	DEADTRANS(	0x00A0	,0x02CF	,0x02CF	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*ACUTE_BELOW        */	DEADTRANS(	0x202F	,0x02CF	,0x02CF	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*BAR&STROKE         */	DEADTRANS(	L'K'	,0xA745	,0xA744	,0x0000	), // LATIN CAPITAL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR&STROKE         */	DEADTRANS(	L'k'	,0xA745	,0xA745	,0x0000	), // LATIN SMALL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR&STROKE         */	DEADTRANS(	0x222A	,0xA745	,0x2209	,0x0000	), // NOT AN ELEMENT OF
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0020	,0x024D	,0x0335	,0x0000	), // COMBINING SHORT STROKE OVERLAY
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'A'	,0x024D	,0xA73A	,0x0000	), // LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'a'	,0x024D	,0xA73B	,0x0000	), // LATIN SMALL LETTER AV WITH HORIZONTAL BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'B'	,0x024D	,0x0243	,0x0000	), // LATIN CAPITAL LETTER B WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'b'	,0x024D	,0x0180	,0x0000	), // LATIN SMALL LETTER B WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'C'	,0x024D	,0xA792	,0x0000	), // LATIN CAPITAL LETTER C WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'c'	,0x024D	,0xA793	,0x0000	), // LATIN SMALL LETTER C WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'D'	,0x024D	,0x0110	,0x0000	), // LATIN CAPITAL LETTER D WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'd'	,0x024D	,0x0111	,0x0000	), // LATIN SMALL LETTER D WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'e'	,0x024D	,0xAB33	,0x0000	), // LATIN SMALL LETTER BARRED E
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'F'	,0x024D	,0xA798	,0x0000	), // LATIN CAPITAL LETTER F WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'f'	,0x024D	,0xA799	,0x0000	), // LATIN SMALL LETTER F WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'G'	,0x024D	,0x01E4	,0x0000	), // LATIN CAPITAL LETTER G WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'g'	,0x024D	,0x01E5	,0x0000	), // LATIN SMALL LETTER G WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'H'	,0x024D	,0x0126	,0x0000	), // LATIN CAPITAL LETTER H WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'h'	,0x024D	,0x0127	,0x0000	), // LATIN SMALL LETTER H WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'I'	,0x024D	,0x0197	,0x0000	), // LATIN CAPITAL LETTER I WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'i'	,0x024D	,0x0268	,0x0000	), // LATIN SMALL LETTER I WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'J'	,0x024D	,0x0248	,0x0000	), // LATIN CAPITAL LETTER J WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'j'	,0x024D	,0x0249	,0x0000	), // LATIN SMALL LETTER J WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'K'	,0x024D	,0xA740	,0x0000	), // LATIN CAPITAL LETTER K WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'k'	,0x024D	,0xA741	,0x0000	), // LATIN SMALL LETTER K WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'L'	,0x024D	,0x023D	,0x0000	), // LATIN CAPITAL LETTER L WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'l'	,0x024D	,0x019A	,0x0000	), // LATIN SMALL LETTER L WITH BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'O'	,0x024D	,0x019F	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'o'	,0x024D	,0x0275	,0x0000	), // LATIN SMALL LETTER BARRED O
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'P'	,0x024D	,0x2C63	,0x0000	), // LATIN CAPITAL LETTER P WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'p'	,0x024D	,0x1D7D	,0x0000	), // LATIN SMALL LETTER P WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'R'	,0x024D	,0x024C	,0x0000	), // LATIN CAPITAL LETTER R WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'r'	,0x024D	,0x024D	,0x0000	), // LATIN SMALL LETTER R WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'T'	,0x024D	,0x0166	,0x0000	), // LATIN CAPITAL LETTER T WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L't'	,0x024D	,0x0167	,0x0000	), // LATIN SMALL LETTER T WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'U'	,0x024D	,0x0244	,0x0000	), // LATIN CAPITAL LETTER U BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'u'	,0x024D	,0x0289	,0x0000	), // LATIN SMALL LETTER U BAR
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'Y'	,0x024D	,0x024E	,0x0000	), // LATIN CAPITAL LETTER Y WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'y'	,0x024D	,0x024F	,0x0000	), // LATIN SMALL LETTER Y WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'Z'	,0x024D	,0x01B5	,0x0000	), // LATIN CAPITAL LETTER Z WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'z'	,0x024D	,0x01B6	,0x0000	), // LATIN SMALL LETTER Z WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0025	,0x024D	,0x01BE	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0027	,0x024D	,0x02A1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003F	,0x024D	,0x02A1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005C	,0x024D	,0x02A2	,0x0000	), // LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005B	,0x024D	,0x2045	,0x0000	), // LEFT SQUARE BRACKET WITH QUILL
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005D	,0x024D	,0x2046	,0x0000	), // RIGHT SQUARE BRACKET WITH QUILL
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x007C	,0x024D	,0x2020	,0x0000	), // DAGGER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x2020	,0x024D	,0x2021	,0x0000	), // DOUBLE DAGGER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'2'	,0x024D	,0x01BB	,0x0000	), // LATIN LETTER TWO WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'7'	,0x024D	,0x02A1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x0029	,0x024D	,0x279C	,0x0000	), // HEAVY ROUND-TIPPED RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x007D	,0x024D	,0x2794	,0x0000	), // HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003C	,0x024D	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003E	,0x024D	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002B	,0x024D	,0x2213	,0x0000	), // MINUS-OR-PLUS SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002C	,0x024D	,0x00AC	,0x0000	), // NOT SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002D	,0x024D	,0x2013	,0x0001	), // EN DASH
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x002F	,0x024D	,0xA745	,0x0001	), // LATIN SMALL LETTER K WITH STROKE AND DIAGONAL STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x003A	,0x024D	,0x00F7	,0x0000	), // DIVISION SIGN
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x005F	,0x024D	,0xA751	,0x0001	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x00FE	,0x024D	,0xA765	,0x0001	), // LATIN SMALL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'a'	,0xA765	,0xAB30	,0x0000	), // LATIN SMALL LETTER BARRED ALPHA
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'c'	,0xA765	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'i'	,0xA765	,0x1D7C	,0x0000	), // LATIN SMALL LETTER IOTA WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'l'	,0xA765	,0x019B	,0x0000	), // LATIN SMALL LETTER LAMBDA WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L's'	,0xA765	,0x1E9D	,0x0000	), // LATIN SMALL LETTER LONG S WITH HIGH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'T'	,0xA765	,0xA764	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L't'	,0xA765	,0xA765	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	L'u'	,0xA765	,0x1D7F	,0x0000	), // LATIN SMALL LETTER UPSILON WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x2019	,0x024D	,0x02A1	,0x0000	), // LATIN LETTER GLOTTAL STOP WITH STROKE
/*BAR_(HORIZONTAL)   */	DEADTRANS(	0x222A	,0x024D	,0x2208	,0x0000	), // ELEMENT OF
/*BARRED_DESCENDER   */	DEADTRANS(	L'P'	,0xA751	,0xA750	,0x0000	), // LATIN CAPITAL LETTER P WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'p'	,0xA751	,0xA751	,0x0000	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'Q'	,0xA751	,0xA756	,0x0000	), // LATIN CAPITAL LETTER Q WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'q'	,0xA751	,0xA757	,0x0000	), // LATIN SMALL LETTER Q WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L'T'	,0xA751	,0xA766	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE THROUGH DESCENDER
/*BARRED_DESCENDER   */	DEADTRANS(	L't'	,0xA751	,0xA767	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE THROUGH DESCENDER
/*BLACKLETTER        */	DEADTRANS(	L'e'	,0xAB32	,0xAB32	,0x0000	), // LATIN SMALL LETTER BLACKLETTER E
/*BLACKLETTER        */	DEADTRANS(	L'o'	,0xAB32	,0xAB3D	,0x0000	), // LATIN SMALL LETTER BLACKLETTER O
/*BREVE              */	DEADTRANS(	0x0020	,0x0115	,0x0306	,0x0000	), // COMBINING BREVE
/*BREVE              */	DEADTRANS(	0x202F	,0x0115	,0x02D8	,0x0000	), // BREVE
/*BREVE              */	DEADTRANS(	0x00A0	,0x0115	,0x222A	,0x0000	), // UNION
/*BREVE              */	DEADTRANS(	L'A'	,0x0115	,0x0102	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE
/*BREVE              */	DEADTRANS(	L'a'	,0x0115	,0x0103	,0x0000	), // LATIN SMALL LETTER A WITH BREVE
/*BREVE              */	DEADTRANS(	L'E'	,0x0115	,0x0114	,0x0000	), // LATIN CAPITAL LETTER E WITH BREVE
/*BREVE              */	DEADTRANS(	L'e'	,0x0115	,0x0115	,0x0000	), // LATIN SMALL LETTER E WITH BREVE
/*BREVE              */	DEADTRANS(	L'G'	,0x0115	,0x011E	,0x0000	), // LATIN CAPITAL LETTER G WITH BREVE
/*BREVE              */	DEADTRANS(	L'g'	,0x0115	,0x011F	,0x0000	), // LATIN SMALL LETTER G WITH BREVE
/*BREVE              */	DEADTRANS(	L'H'	,0x0115	,0x1E2A	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*BREVE              */	DEADTRANS(	L'h'	,0x0115	,0x1E2B	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*BREVE              */	DEADTRANS(	L'I'	,0x0115	,0x012C	,0x0000	), // LATIN CAPITAL LETTER I WITH BREVE
/*BREVE              */	DEADTRANS(	L'i'	,0x0115	,0x012D	,0x0000	), // LATIN SMALL LETTER I WITH BREVE
/*BREVE              */	DEADTRANS(	L'n'	,0x0115	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*BREVE              */	DEADTRANS(	L'O'	,0x0115	,0x014E	,0x0000	), // LATIN CAPITAL LETTER O WITH BREVE
/*BREVE              */	DEADTRANS(	L'o'	,0x0115	,0x014F	,0x0000	), // LATIN SMALL LETTER O WITH BREVE
/*BREVE              */	DEADTRANS(	L'r'	,0x0115	,0xAB47	,0x0000	), // LATIN SMALL LETTER R WITHOUT HANDLE
/*BREVE              */	DEADTRANS(	L'U'	,0x0115	,0x016C	,0x0000	), // LATIN CAPITAL LETTER U WITH BREVE
/*BREVE              */	DEADTRANS(	L'u'	,0x0115	,0x016D	,0x0000	), // LATIN SMALL LETTER U WITH BREVE
/*BREVE              */	DEADTRANS(	L'y'	,0x0115	,0xAB5A	,0x0000	), // LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*BREVE              */	DEADTRANS(	0x0021	,0x0115	,0x1EB7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE              */	DEADTRANS(	0x0023	,0x0115	,0xAB4E	,0x0001	), // LATIN SMALL LETTER U WITH SHORT RIGHT LEG
/*BREVE              */	DEADTRANS(	0x0027	,0x0115	,0x1EAF	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE              */	DEADTRANS(	0x0028	,0x0115	,0xAB5B	,0x0000	), // MODIFIER BREVE WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x0029	,0x0115	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x002C	,0x0115	,0x1E1D	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*BREVE              */	DEADTRANS(	0x002E	,0x0115	,0x0310	,0x0000	), // COMBINING CANDRABINDU
/*BREVE              */	DEADTRANS(	0x005F	,0x0115	,0x1DCB	,0x0000	), // COMBINING BREVE-MACRON
/*BREVE              */	DEADTRANS(	0x005D	,0x0115	,0x1EB3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE              */	DEADTRANS(	0x0060	,0x0115	,0x1EB1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE              */	DEADTRANS(	0x007E	,0x0115	,0x1EB5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE              */	DEADTRANS(	0x00E1	,0x0115	,0x1EAF	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE              */	DEADTRANS(	0x00F2	,0x0115	,0x1EB1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE              */	DEADTRANS(	0x00F5	,0x0115	,0x1EB5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE              */	DEADTRANS(	0x2610	,0x0115	,0x25EF	,0x0000	), // LARGE CIRCLE
/*BREVE              */	DEADTRANS(	0x0229	,0x0115	,0x1E1D	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*BREVE              */	DEADTRANS(	0x1EBB	,0x0115	,0x1EB3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE              */	DEADTRANS(	0x0115	,0x0115	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*BREVE              */	DEADTRANS(	0x014D	,0x0115	,0x1DCB	,0x0000	), // COMBINING BREVE-MACRON
/*BREVE              */	DEADTRANS(	0x1EE5	,0x0115	,0x1EB7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&ACUTE_ACCENT */	DEADTRANS(	L'A'	,0x1EAF	,0x1EAE	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND ACUTE
/*BREVE&ACUTE_ACCENT */	DEADTRANS(	L'a'	,0x1EAF	,0x1EAF	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND ACUTE
/*BREVE&DOT_BELOW    */	DEADTRANS(	L'A'	,0x1EB7	,0x1EB6	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&DOT_BELOW    */	DEADTRANS(	L'a'	,0x1EB7	,0x1EB7	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*BREVE&GRAVE        */	DEADTRANS(	L'A'	,0x1EB1	,0x1EB0	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND GRAVE
/*BREVE&GRAVE        */	DEADTRANS(	L'a'	,0x1EB1	,0x1EB1	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*BREVE&HOOK_ABOVE   */	DEADTRANS(	L'A'	,0x1EB3	,0x1EB2	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE&HOOK_ABOVE   */	DEADTRANS(	L'a'	,0x1EB3	,0x1EB3	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*BREVE&TILDE        */	DEADTRANS(	L'A'	,0x1EB5	,0x1EB4	,0x0000	), // LATIN CAPITAL LETTER A WITH BREVE AND TILDE
/*BREVE&TILDE        */	DEADTRANS(	L'a'	,0x1EB5	,0x1EB5	,0x0000	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*BREVE_BELOW        */	DEADTRANS(	0x0020	,0x1E2B	,0x032E	,0x0000	), // COMBINING BREVE BELOW
/*BREVE_BELOW        */	DEADTRANS(	L'H'	,0x1E2B	,0x1E2A	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*BREVE_BELOW        */	DEADTRANS(	L'h'	,0x1E2B	,0x1E2B	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*CEDILLA            */	DEADTRANS(	0x0020	,0x0229	,0x0327	,0x0000	), // COMBINING CEDILLA
/*CEDILLA            */	DEADTRANS(	0x00A0	,0x0229	,0x00B8	,0x0000	), // CEDILLA
/*CEDILLA            */	DEADTRANS(	0x202F	,0x0229	,0x00B8	,0x0000	), // CEDILLA
/*CEDILLA            */	DEADTRANS(	L'C'	,0x0229	,0x00C7	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'c'	,0x0229	,0x00E7	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'D'	,0x0229	,0x1E10	,0x0000	), // LATIN CAPITAL LETTER D WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'd'	,0x0229	,0x1E11	,0x0000	), // LATIN SMALL LETTER D WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'E'	,0x0229	,0x0228	,0x0000	), // LATIN CAPITAL LETTER E WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'e'	,0x0229	,0x0229	,0x0000	), // LATIN SMALL LETTER E WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'G'	,0x0229	,0x0122	,0x0000	), // LATIN CAPITAL LETTER G WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'g'	,0x0229	,0x0123	,0x0000	), // LATIN SMALL LETTER G WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'H'	,0x0229	,0x1E28	,0x0000	), // LATIN CAPITAL LETTER H WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'h'	,0x0229	,0x1E29	,0x0000	), // LATIN SMALL LETTER H WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'K'	,0x0229	,0x0136	,0x0000	), // LATIN CAPITAL LETTER K WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'k'	,0x0229	,0x0137	,0x0000	), // LATIN SMALL LETTER K WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'L'	,0x0229	,0x013B	,0x0000	), // LATIN CAPITAL LETTER L WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'l'	,0x0229	,0x013C	,0x0000	), // LATIN SMALL LETTER L WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'N'	,0x0229	,0x0145	,0x0000	), // LATIN CAPITAL LETTER N WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'n'	,0x0229	,0x0146	,0x0000	), // LATIN SMALL LETTER N WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'R'	,0x0229	,0x0156	,0x0000	), // LATIN CAPITAL LETTER R WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'r'	,0x0229	,0x0157	,0x0000	), // LATIN SMALL LETTER R WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'S'	,0x0229	,0x015E	,0x0000	), // LATIN CAPITAL LETTER S WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L's'	,0x0229	,0x015F	,0x0000	), // LATIN SMALL LETTER S WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'T'	,0x0229	,0x0162	,0x0000	), // LATIN CAPITAL LETTER T WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L't'	,0x0229	,0x0163	,0x0000	), // LATIN SMALL LETTER T WITH CEDILLA
/*CEDILLA            */	DEADTRANS(	L'x'	,0x0229	,0xAB55	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW LEFT SERIF
/*CEDILLA            */	DEADTRANS(	0x002F	,0x0229	,0xAB59	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG WITH SERIF
/*CEDILLA            */	DEADTRANS(	0x0027	,0x0229	,0x1E09	,0x0001	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*CEDILLA            */	DEADTRANS(	0x0029	,0x0229	,0x1E1D	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA            */	DEADTRANS(	0x002C	,0x0229	,0x01B0	,0x0001	), // LATIN SMALL LETTER U WITH HORN
/*CEDILLA            */	DEADTRANS(	0x003B	,0x0229	,0x2C6A	,0x0001	), // LATIN SMALL LETTER K WITH DESCENDER
/*CEDILLA            */	DEADTRANS(	0x00E1	,0x0229	,0x1E09	,0x0001	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*CEDILLA            */	DEADTRANS(	0x0115	,0x0229	,0x1E1D	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA            */	DEADTRANS(	0x0229	,0x0229	,0x1EBB	,0x0001	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*CEDILLA&BREVE      */	DEADTRANS(	L'E'	,0x1E1D	,0x1E1C	,0x0000	), // LATIN CAPITAL LETTER E WITH CEDILLA AND BREVE
/*CEDILLA&BREVE      */	DEADTRANS(	L'e'	,0x1E1D	,0x1E1D	,0x0000	), // LATIN SMALL LETTER E WITH CEDILLA AND BREVE
/*CIRCLED            */	DEADTRANS(	0x0020	,0x25EF	,0x20DD	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*CIRCLED            */	DEADTRANS(	0x0029	,0x25EF	,0x20DD	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*CIRCLED            */	DEADTRANS(	0x003E	,0x25EF	,0x20DF	,0x0000	), // COMBINING ENCLOSING DIAMOND
/*CIRCLED            */	DEADTRANS(	0x005C	,0x25EF	,0x20E0	,0x0000	), // COMBINING ENCLOSING CIRCLE BACKSLASH
/*CIRCLED            */	DEADTRANS(	0x005D	,0x25EF	,0x20DE	,0x0000	), // COMBINING ENCLOSING SQUARE
/*CIRCLED            */	DEADTRANS(	0x00A0	,0x25EF	,0x25EF	,0x0000	), // LARGE CIRCLE
/*CIRCLED            */	DEADTRANS(	0x202F	,0x25EF	,0x25EF	,0x0000	), // LARGE CIRCLE
/*CIRCLED            */	DEADTRANS(	L'A'	,0x25EF	,0x24B6	,0x0000	), // CIRCLED LATIN CAPITAL LETTER A
/*CIRCLED            */	DEADTRANS(	L'a'	,0x25EF	,0x24D0	,0x0000	), // CIRCLED LATIN SMALL LETTER A
/*CIRCLED            */	DEADTRANS(	L'B'	,0x25EF	,0x24B7	,0x0000	), // CIRCLED LATIN CAPITAL LETTER B
/*CIRCLED            */	DEADTRANS(	L'b'	,0x25EF	,0x24D1	,0x0000	), // CIRCLED LATIN SMALL LETTER B
/*CIRCLED            */	DEADTRANS(	L'C'	,0x25EF	,0x24B8	,0x0000	), // CIRCLED LATIN CAPITAL LETTER C
/*CIRCLED            */	DEADTRANS(	L'c'	,0x25EF	,0x24D2	,0x0000	), // CIRCLED LATIN SMALL LETTER C
/*CIRCLED            */	DEADTRANS(	L'D'	,0x25EF	,0x24B9	,0x0000	), // CIRCLED LATIN CAPITAL LETTER D
/*CIRCLED            */	DEADTRANS(	L'd'	,0x25EF	,0x24D3	,0x0000	), // CIRCLED LATIN SMALL LETTER D
/*CIRCLED            */	DEADTRANS(	L'E'	,0x25EF	,0x24BA	,0x0000	), // CIRCLED LATIN CAPITAL LETTER E
/*CIRCLED            */	DEADTRANS(	L'e'	,0x25EF	,0x24D4	,0x0000	), // CIRCLED LATIN SMALL LETTER E
/*CIRCLED            */	DEADTRANS(	L'F'	,0x25EF	,0x24BB	,0x0000	), // CIRCLED LATIN CAPITAL LETTER F
/*CIRCLED            */	DEADTRANS(	L'f'	,0x25EF	,0x24D5	,0x0000	), // CIRCLED LATIN SMALL LETTER F
/*CIRCLED            */	DEADTRANS(	L'G'	,0x25EF	,0x24BC	,0x0000	), // CIRCLED LATIN CAPITAL LETTER G
/*CIRCLED            */	DEADTRANS(	L'g'	,0x25EF	,0x24D6	,0x0000	), // CIRCLED LATIN SMALL LETTER G
/*CIRCLED            */	DEADTRANS(	L'H'	,0x25EF	,0x24BD	,0x0000	), // CIRCLED LATIN CAPITAL LETTER H
/*CIRCLED            */	DEADTRANS(	L'h'	,0x25EF	,0x24D7	,0x0000	), // CIRCLED LATIN SMALL LETTER H
/*CIRCLED            */	DEADTRANS(	L'I'	,0x25EF	,0x24BE	,0x0000	), // CIRCLED LATIN CAPITAL LETTER I
/*CIRCLED            */	DEADTRANS(	L'i'	,0x25EF	,0x24D8	,0x0000	), // CIRCLED LATIN SMALL LETTER I
/*CIRCLED            */	DEADTRANS(	L'J'	,0x25EF	,0x24BF	,0x0000	), // CIRCLED LATIN CAPITAL LETTER J
/*CIRCLED            */	DEADTRANS(	L'j'	,0x25EF	,0x24D9	,0x0000	), // CIRCLED LATIN SMALL LETTER J
/*CIRCLED            */	DEADTRANS(	L'K'	,0x25EF	,0x24C0	,0x0000	), // CIRCLED LATIN CAPITAL LETTER K
/*CIRCLED            */	DEADTRANS(	L'k'	,0x25EF	,0x24DA	,0x0000	), // CIRCLED LATIN SMALL LETTER K
/*CIRCLED            */	DEADTRANS(	L'L'	,0x25EF	,0x24C1	,0x0000	), // CIRCLED LATIN CAPITAL LETTER L
/*CIRCLED            */	DEADTRANS(	L'l'	,0x25EF	,0x24DB	,0x0000	), // CIRCLED LATIN SMALL LETTER L
/*CIRCLED            */	DEADTRANS(	L'M'	,0x25EF	,0x24C2	,0x0000	), // CIRCLED LATIN CAPITAL LETTER M
/*CIRCLED            */	DEADTRANS(	L'm'	,0x25EF	,0x24DC	,0x0000	), // CIRCLED LATIN SMALL LETTER M
/*CIRCLED            */	DEADTRANS(	L'N'	,0x25EF	,0x24C3	,0x0000	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	L'n'	,0x25EF	,0x24DD	,0x0000	), // CIRCLED LATIN SMALL LETTER N
/*CIRCLED            */	DEADTRANS(	L'O'	,0x25EF	,0x24C4	,0x0000	), // CIRCLED LATIN CAPITAL LETTER O
/*CIRCLED            */	DEADTRANS(	L'o'	,0x25EF	,0x24DE	,0x0000	), // CIRCLED LATIN SMALL LETTER O
/*CIRCLED            */	DEADTRANS(	L'P'	,0x25EF	,0x24C5	,0x0000	), // CIRCLED LATIN CAPITAL LETTER P
/*CIRCLED            */	DEADTRANS(	L'p'	,0x25EF	,0x24DF	,0x0000	), // CIRCLED LATIN SMALL LETTER P
/*CIRCLED            */	DEADTRANS(	L'Q'	,0x25EF	,0x24C6	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Q
/*CIRCLED            */	DEADTRANS(	L'q'	,0x25EF	,0x24E0	,0x0000	), // CIRCLED LATIN SMALL LETTER Q
/*CIRCLED            */	DEADTRANS(	L'R'	,0x25EF	,0x24C7	,0x0000	), // CIRCLED LATIN CAPITAL LETTER R
/*CIRCLED            */	DEADTRANS(	L'r'	,0x25EF	,0x24E1	,0x0000	), // CIRCLED LATIN SMALL LETTER R
/*CIRCLED            */	DEADTRANS(	L'S'	,0x25EF	,0x24C8	,0x0000	), // CIRCLED LATIN CAPITAL LETTER S
/*CIRCLED            */	DEADTRANS(	L's'	,0x25EF	,0x24E2	,0x0000	), // CIRCLED LATIN SMALL LETTER S
/*CIRCLED            */	DEADTRANS(	L'T'	,0x25EF	,0x24C9	,0x0000	), // CIRCLED LATIN CAPITAL LETTER T
/*CIRCLED            */	DEADTRANS(	L't'	,0x25EF	,0x24E3	,0x0000	), // CIRCLED LATIN SMALL LETTER T
/*CIRCLED            */	DEADTRANS(	L'U'	,0x25EF	,0x24CA	,0x0000	), // CIRCLED LATIN CAPITAL LETTER U
/*CIRCLED            */	DEADTRANS(	L'u'	,0x25EF	,0x24E4	,0x0000	), // CIRCLED LATIN SMALL LETTER U
/*CIRCLED            */	DEADTRANS(	L'V'	,0x25EF	,0x24CB	,0x0000	), // CIRCLED LATIN CAPITAL LETTER V
/*CIRCLED            */	DEADTRANS(	L'v'	,0x25EF	,0x24E5	,0x0000	), // CIRCLED LATIN SMALL LETTER V
/*CIRCLED            */	DEADTRANS(	L'W'	,0x25EF	,0x24CC	,0x0000	), // CIRCLED LATIN CAPITAL LETTER W
/*CIRCLED            */	DEADTRANS(	L'w'	,0x25EF	,0x24E6	,0x0000	), // CIRCLED LATIN SMALL LETTER W
/*CIRCLED            */	DEADTRANS(	L'X'	,0x25EF	,0x24CD	,0x0000	), // CIRCLED LATIN CAPITAL LETTER X
/*CIRCLED            */	DEADTRANS(	L'x'	,0x25EF	,0x24E7	,0x0000	), // CIRCLED LATIN SMALL LETTER X
/*CIRCLED            */	DEADTRANS(	L'Y'	,0x25EF	,0x24CE	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Y
/*CIRCLED            */	DEADTRANS(	L'y'	,0x25EF	,0x24E8	,0x0000	), // CIRCLED LATIN SMALL LETTER Y
/*CIRCLED            */	DEADTRANS(	L'Z'	,0x25EF	,0x24CF	,0x0000	), // CIRCLED LATIN CAPITAL LETTER Z
/*CIRCLED            */	DEADTRANS(	L'z'	,0x25EF	,0x24E9	,0x0000	), // CIRCLED LATIN SMALL LETTER Z
/*CIRCLED            */	DEADTRANS(	0x00D9	,0x25EF	,0x24FF	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x00F9	,0x25EF	,0x24FF	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x0023	,0x25EF	,0x24C3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x0024	,0x25EF	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x0025	,0x25EF	,0x24FF	,0x0001	), // NEGATIVE CIRCLED DIGIT ZERO
/*CIRCLED            */	DEADTRANS(	0x0028	,0x25EF	,0x24AA	,0x0001	), // PARENTHESIZED LATIN SMALL LETTER O
/*CIRCLED            */	DEADTRANS(	0x002A	,0x25EF	,0x229B	,0x0000	), // CIRCLED ASTERISK OPERATOR
/*CIRCLED            */	DEADTRANS(	0x002B	,0x25EF	,0x2295	,0x0000	), // CIRCLED PLUS
/*CIRCLED            */	DEADTRANS(	0x002D	,0x25EF	,0x2296	,0x0000	), // CIRCLED MINUS
/*CIRCLED            */	DEADTRANS(	0x002E	,0x25EF	,0x2299	,0x0000	), // CIRCLED DOT OPERATOR
/*CIRCLED            */	DEADTRANS(	0x002F	,0x25EF	,0x2298	,0x0000	), // CIRCLED DIVISION SLASH
/*CIRCLED            */	DEADTRANS(	L'0'	,0x25EF	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*CIRCLED            */	DEADTRANS(	L'1'	,0x25EF	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*CIRCLED            */	DEADTRANS(	L'2'	,0x25EF	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*CIRCLED            */	DEADTRANS(	L'3'	,0x25EF	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*CIRCLED            */	DEADTRANS(	L'4'	,0x25EF	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*CIRCLED            */	DEADTRANS(	L'5'	,0x25EF	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*CIRCLED            */	DEADTRANS(	L'6'	,0x25EF	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*CIRCLED            */	DEADTRANS(	L'7'	,0x25EF	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*CIRCLED            */	DEADTRANS(	L'8'	,0x25EF	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*CIRCLED            */	DEADTRANS(	L'9'	,0x25EF	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*CIRCLED            */	DEADTRANS(	0x003B	,0x25EF	,0x2297	,0x0000	), // CIRCLED TIMES
/*CIRCLED            */	DEADTRANS(	0x003D	,0x25EF	,0x229C	,0x0000	), // CIRCLED EQUALS
/*CIRCLED            */	DEADTRANS(	0x0040	,0x25EF	,0x25CE	,0x0001	), // BULLSEYE
/*CIRCLED            */	DEADTRANS(	0x005E	,0x25EF	,0x24C3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x005F	,0x25EF	,0x229D	,0x0000	), // CIRCLED DASH
/*CIRCLED            */	DEADTRANS(	0x007C	,0x25EF	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x00B0	,0x25EF	,0x229A	,0x0000	), // CIRCLED RING OPERATOR
/*CIRCLED            */	DEADTRANS(	0x00D7	,0x25EF	,0x2297	,0x0000	), // CIRCLED TIMES
/*CIRCLED            */	DEADTRANS(	0x00EA	,0x25EF	,0x24C3	,0x0001	), // CIRCLED LATIN CAPITAL LETTER N
/*CIRCLED            */	DEADTRANS(	0x00F2	,0x25EF	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x00F5	,0x25EF	,0x2780	,0x0001	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED            */	DEADTRANS(	0x2212	,0x25EF	,0x2296	,0x0000	), // CIRCLED MINUS
/*CIRCLED_##         */	DEADTRANS(	L'0'	,0x24C3	,0x24EA	,0x0001	), // CIRCLED DIGIT ZERO
/*CIRCLED_##         */	DEADTRANS(	L'1'	,0x24C3	,0x2469	,0x0001	), // CIRCLED NUMBER TEN
/*CIRCLED_##         */	DEADTRANS(	L'2'	,0x24C3	,0x2473	,0x0001	), // CIRCLED NUMBER TWENTY
/*CIRCLED_##         */	DEADTRANS(	L'3'	,0x24C3	,0x325A	,0x0001	), // CIRCLED NUMBER THIRTY
/*CIRCLED_##         */	DEADTRANS(	L'4'	,0x24C3	,0x32B5	,0x0001	), // CIRCLED NUMBER FORTY
/*CIRCLED_##         */	DEADTRANS(	L'5'	,0x24C3	,0x32BF	,0x0000	), // CIRCLED NUMBER FIFTY
/*CIRCLED_0#         */	DEADTRANS(	L'0'	,0x24EA	,0x24EA	,0x0000	), // CIRCLED DIGIT ZERO
/*CIRCLED_0#         */	DEADTRANS(	L'1'	,0x24EA	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*CIRCLED_0#         */	DEADTRANS(	L'2'	,0x24EA	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*CIRCLED_0#         */	DEADTRANS(	L'3'	,0x24EA	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*CIRCLED_0#         */	DEADTRANS(	L'4'	,0x24EA	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*CIRCLED_0#         */	DEADTRANS(	L'5'	,0x24EA	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*CIRCLED_0#         */	DEADTRANS(	L'6'	,0x24EA	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*CIRCLED_0#         */	DEADTRANS(	L'7'	,0x24EA	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*CIRCLED_0#         */	DEADTRANS(	L'8'	,0x24EA	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*CIRCLED_0#         */	DEADTRANS(	L'9'	,0x24EA	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*CIRCLED_1#         */	DEADTRANS(	L'0'	,0x2469	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*CIRCLED_1#         */	DEADTRANS(	L'1'	,0x2469	,0x246A	,0x0000	), // CIRCLED NUMBER ELEVEN
/*CIRCLED_1#         */	DEADTRANS(	L'2'	,0x2469	,0x246B	,0x0000	), // CIRCLED NUMBER TWELVE
/*CIRCLED_1#         */	DEADTRANS(	L'3'	,0x2469	,0x246C	,0x0000	), // CIRCLED NUMBER THIRTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'4'	,0x2469	,0x246D	,0x0000	), // CIRCLED NUMBER FOURTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'5'	,0x2469	,0x246E	,0x0000	), // CIRCLED NUMBER FIFTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'6'	,0x2469	,0x246F	,0x0000	), // CIRCLED NUMBER SIXTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'7'	,0x2469	,0x2470	,0x0000	), // CIRCLED NUMBER SEVENTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'8'	,0x2469	,0x2471	,0x0000	), // CIRCLED NUMBER EIGHTEEN
/*CIRCLED_1#         */	DEADTRANS(	L'9'	,0x2469	,0x2472	,0x0000	), // CIRCLED NUMBER NINETEEN
/*CIRCLED_2#         */	DEADTRANS(	L'0'	,0x2473	,0x2473	,0x0000	), // CIRCLED NUMBER TWENTY
/*CIRCLED_2#         */	DEADTRANS(	L'1'	,0x2473	,0x3251	,0x0000	), // CIRCLED NUMBER TWENTY ONE
/*CIRCLED_2#         */	DEADTRANS(	L'2'	,0x2473	,0x3252	,0x0000	), // CIRCLED NUMBER TWENTY TWO
/*CIRCLED_2#         */	DEADTRANS(	L'3'	,0x2473	,0x3253	,0x0000	), // CIRCLED NUMBER TWENTY THREE
/*CIRCLED_2#         */	DEADTRANS(	L'4'	,0x2473	,0x3254	,0x0000	), // CIRCLED NUMBER TWENTY FOUR
/*CIRCLED_2#         */	DEADTRANS(	L'5'	,0x2473	,0x3255	,0x0000	), // CIRCLED NUMBER TWENTY FIVE
/*CIRCLED_2#         */	DEADTRANS(	L'6'	,0x2473	,0x3256	,0x0000	), // CIRCLED NUMBER TWENTY SIX
/*CIRCLED_2#         */	DEADTRANS(	L'7'	,0x2473	,0x3257	,0x0000	), // CIRCLED NUMBER TWENTY SEVEN
/*CIRCLED_2#         */	DEADTRANS(	L'8'	,0x2473	,0x3258	,0x0000	), // CIRCLED NUMBER TWENTY EIGHT
/*CIRCLED_2#         */	DEADTRANS(	L'9'	,0x2473	,0x3259	,0x0000	), // CIRCLED NUMBER TWENTY NINE
/*CIRCLED_3#         */	DEADTRANS(	L'0'	,0x325A	,0x325A	,0x0000	), // CIRCLED NUMBER THIRTY
/*CIRCLED_3#         */	DEADTRANS(	L'1'	,0x325A	,0x325B	,0x0000	), // CIRCLED NUMBER THIRTY ONE
/*CIRCLED_3#         */	DEADTRANS(	L'2'	,0x325A	,0x325C	,0x0000	), // CIRCLED NUMBER THIRTY TWO
/*CIRCLED_3#         */	DEADTRANS(	L'3'	,0x325A	,0x325D	,0x0000	), // CIRCLED NUMBER THIRTY THREE
/*CIRCLED_3#         */	DEADTRANS(	L'4'	,0x325A	,0x325E	,0x0000	), // CIRCLED NUMBER THIRTY FOUR
/*CIRCLED_3#         */	DEADTRANS(	L'5'	,0x325A	,0x325F	,0x0000	), // CIRCLED NUMBER THIRTY FIVE
/*CIRCLED_3#         */	DEADTRANS(	L'6'	,0x325A	,0x32B1	,0x0000	), // CIRCLED NUMBER THIRTY SIX
/*CIRCLED_3#         */	DEADTRANS(	L'7'	,0x325A	,0x32B2	,0x0000	), // CIRCLED NUMBER THIRTY SEVEN
/*CIRCLED_3#         */	DEADTRANS(	L'8'	,0x325A	,0x32B3	,0x0000	), // CIRCLED NUMBER THIRTY EIGHT
/*CIRCLED_3#         */	DEADTRANS(	L'9'	,0x325A	,0x32B4	,0x0000	), // CIRCLED NUMBER THIRTY NINE
/*CIRCLED_4#         */	DEADTRANS(	L'0'	,0x32B5	,0x32B5	,0x0000	), // CIRCLED NUMBER FORTY
/*CIRCLED_4#         */	DEADTRANS(	L'1'	,0x32B5	,0x32B6	,0x0000	), // CIRCLED NUMBER FORTY ONE
/*CIRCLED_4#         */	DEADTRANS(	L'2'	,0x32B5	,0x32B7	,0x0000	), // CIRCLED NUMBER FORTY TWO
/*CIRCLED_4#         */	DEADTRANS(	L'3'	,0x32B5	,0x32B8	,0x0000	), // CIRCLED NUMBER FORTY THREE
/*CIRCLED_4#         */	DEADTRANS(	L'4'	,0x32B5	,0x32B9	,0x0000	), // CIRCLED NUMBER FORTY FOUR
/*CIRCLED_4#         */	DEADTRANS(	L'5'	,0x32B5	,0x32BA	,0x0000	), // CIRCLED NUMBER FORTY FIVE
/*CIRCLED_4#         */	DEADTRANS(	L'6'	,0x32B5	,0x32BB	,0x0000	), // CIRCLED NUMBER FORTY SIX
/*CIRCLED_4#         */	DEADTRANS(	L'7'	,0x32B5	,0x32BC	,0x0000	), // CIRCLED NUMBER FORTY SEVEN
/*CIRCLED_4#         */	DEADTRANS(	L'8'	,0x32B5	,0x32BD	,0x0000	), // CIRCLED NUMBER FORTY EIGHT
/*CIRCLED_4#         */	DEADTRANS(	L'9'	,0x32B5	,0x32BE	,0x0000	), // CIRCLED NUMBER FORTY NINE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'0'	,0x25CE	,0x24FE	,0x0000	), // DOUBLE CIRCLED NUMBER TEN
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'1'	,0x25CE	,0x24F5	,0x0000	), // DOUBLE CIRCLED DIGIT ONE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'2'	,0x25CE	,0x24F6	,0x0000	), // DOUBLE CIRCLED DIGIT TWO
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'3'	,0x25CE	,0x24F7	,0x0000	), // DOUBLE CIRCLED DIGIT THREE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'4'	,0x25CE	,0x24F8	,0x0000	), // DOUBLE CIRCLED DIGIT FOUR
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'5'	,0x25CE	,0x24F9	,0x0000	), // DOUBLE CIRCLED DIGIT FIVE
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'6'	,0x25CE	,0x24FA	,0x0000	), // DOUBLE CIRCLED DIGIT SIX
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'7'	,0x25CE	,0x24FB	,0x0000	), // DOUBLE CIRCLED DIGIT SEVEN
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'8'	,0x25CE	,0x24FC	,0x0000	), // DOUBLE CIRCLED DIGIT EIGHT
/*CIRCLED_DOUBLE     */	DEADTRANS(	L'9'	,0x25CE	,0x24FD	,0x0000	), // DOUBLE CIRCLED DIGIT NINE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'0'	,0x278A	,0x2793	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF NUMBER TEN
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'1'	,0x278A	,0x278A	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'2'	,0x278A	,0x278B	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT TWO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'3'	,0x278A	,0x278C	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT THREE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'4'	,0x278A	,0x278D	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FOUR
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'5'	,0x278A	,0x278E	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT FIVE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'6'	,0x278A	,0x278F	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SIX
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'7'	,0x278A	,0x2790	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT SEVEN
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'8'	,0x278A	,0x2791	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT EIGHT
/*CIRCLED_NEG_SANS   */	DEADTRANS(	L'9'	,0x278A	,0x2792	,0x0000	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT NINE
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x0023	,0x278A	,0xDD0C	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x005E	,0x278A	,0xDD0C	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEG_SANS   */	DEADTRANS(	0x00EA	,0x278A	,0xDD0C	,0x0000	), // U+1F10C; input D83C high surrogate first; DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x0023	,0x24FF	,0x277F	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x0024	,0x24FF	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'0'	,0x24FF	,0x277F	,0x0000	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'1'	,0x24FF	,0x2776	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'2'	,0x24FF	,0x2777	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT TWO
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'3'	,0x24FF	,0x2778	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT THREE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'4'	,0x24FF	,0x2779	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FOUR
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'5'	,0x24FF	,0x277A	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FIVE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'6'	,0x24FF	,0x277B	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SIX
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'7'	,0x24FF	,0x277C	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SEVEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'8'	,0x24FF	,0x277D	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT EIGHT
/*CIRCLED_NEGATIVE   */	DEADTRANS(	L'9'	,0x24FF	,0x277E	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT NINE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x005E	,0x24FF	,0x277F	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x007C	,0x24FF	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x007D	,0x24FF	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00EA	,0x24FF	,0x277F	,0x0001	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00F2	,0x24FF	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE   */	DEADTRANS(	0x00F5	,0x24FF	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'0'	,0x277F	,0x24F4	,0x0001	), // NEGATIVE CIRCLED NUMBER TWENTY
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'1'	,0x277F	,0x24EB	,0x0001	), // NEGATIVE CIRCLED NUMBER ELEVEN
/*CIRCLED_NEGATIVE_##*/	DEADTRANS(	L'2'	,0x277F	,0x24F4	,0x0000	), // NEGATIVE CIRCLED NUMBER TWENTY
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'1'	,0x24F4	,0x2776	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT ONE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'2'	,0x24F4	,0x2777	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT TWO
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'3'	,0x24F4	,0x2778	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT THREE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'4'	,0x24F4	,0x2779	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FOUR
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'5'	,0x24F4	,0x277A	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT FIVE
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'6'	,0x24F4	,0x277B	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SIX
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'7'	,0x24F4	,0x277C	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT SEVEN
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'8'	,0x24F4	,0x277D	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT EIGHT
/*CIRCLED_NEGATIVE_0#*/	DEADTRANS(	L'9'	,0x24F4	,0x277E	,0x0000	), // DINGBAT NEGATIVE CIRCLED DIGIT NINE
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'0'	,0x24EB	,0x277F	,0x0000	), // DINGBAT NEGATIVE CIRCLED NUMBER TEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'1'	,0x24EB	,0x24EB	,0x0000	), // NEGATIVE CIRCLED NUMBER ELEVEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'2'	,0x24EB	,0x24EC	,0x0000	), // NEGATIVE CIRCLED NUMBER TWELVE
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'3'	,0x24EB	,0x24ED	,0x0000	), // NEGATIVE CIRCLED NUMBER THIRTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'4'	,0x24EB	,0x24EE	,0x0000	), // NEGATIVE CIRCLED NUMBER FOURTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'5'	,0x24EB	,0x24EF	,0x0000	), // NEGATIVE CIRCLED NUMBER FIFTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'6'	,0x24EB	,0x24F0	,0x0000	), // NEGATIVE CIRCLED NUMBER SIXTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'7'	,0x24EB	,0x24F1	,0x0000	), // NEGATIVE CIRCLED NUMBER SEVENTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'8'	,0x24EB	,0x24F2	,0x0000	), // NEGATIVE CIRCLED NUMBER EIGHTEEN
/*CIRCLED_NEGATIVE_1#*/	DEADTRANS(	L'9'	,0x24EB	,0x24F3	,0x0000	), // NEGATIVE CIRCLED NUMBER NINETEEN
/*CIRCLED_SANS       */	DEADTRANS(	0x00D9	,0x2780	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	0x00F9	,0x2780	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	0x0023	,0x2780	,0xDD0B	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_SANS       */	DEADTRANS(	0x0025	,0x2780	,0x278A	,0x0001	), // DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	L'0'	,0x2780	,0x2789	,0x0000	), // DINGBAT CIRCLED SANS-SERIF NUMBER TEN
/*CIRCLED_SANS       */	DEADTRANS(	L'1'	,0x2780	,0x2780	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT ONE
/*CIRCLED_SANS       */	DEADTRANS(	L'2'	,0x2780	,0x2781	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT TWO
/*CIRCLED_SANS       */	DEADTRANS(	L'3'	,0x2780	,0x2782	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT THREE
/*CIRCLED_SANS       */	DEADTRANS(	L'4'	,0x2780	,0x2783	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT FOUR
/*CIRCLED_SANS       */	DEADTRANS(	L'5'	,0x2780	,0x2784	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT FIVE
/*CIRCLED_SANS       */	DEADTRANS(	L'6'	,0x2780	,0x2785	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT SIX
/*CIRCLED_SANS       */	DEADTRANS(	L'7'	,0x2780	,0x2786	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT SEVEN
/*CIRCLED_SANS       */	DEADTRANS(	L'8'	,0x2780	,0x2787	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT EIGHT
/*CIRCLED_SANS       */	DEADTRANS(	L'9'	,0x2780	,0x2788	,0x0000	), // DINGBAT CIRCLED SANS-SERIF DIGIT NINE
/*CIRCLED_SANS       */	DEADTRANS(	0x005E	,0x2780	,0xDD0B	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCLED_SANS       */	DEADTRANS(	0x00EA	,0x2780	,0xDD0B	,0x0000	), // U+1F10B; input D83C high surrogate first; DINGBAT CIRCLED SANS-SERIF DIGIT ZERO
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'A'	,0x1EBF	,0x1EA4	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'a'	,0x1EBF	,0x1EA5	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'E'	,0x1EBF	,0x1EBE	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'e'	,0x1EBF	,0x1EBF	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'O'	,0x1EBF	,0x1ED0	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	L'o'	,0x1EBF	,0x1ED1	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	0x00C7	,0x1EBF	,0x01FE	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*CIRCUMFLEX&ACUTE   */	DEADTRANS(	0x00E7	,0x1EBF	,0x01FF	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'A'	,0x1ED9	,0x1EAC	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'a'	,0x1ED9	,0x1EAD	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'E'	,0x1ED9	,0x1EC6	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'e'	,0x1ED9	,0x1EC7	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'O'	,0x1ED9	,0x1ED8	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&DOT_BELO*/	DEADTRANS(	L'o'	,0x1ED9	,0x1ED9	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'A'	,0x1ED3	,0x1EA6	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'a'	,0x1ED3	,0x1EA7	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'E'	,0x1ED3	,0x1EC0	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'e'	,0x1ED3	,0x1EC1	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'O'	,0x1ED3	,0x1ED2	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&GRAVE   */	DEADTRANS(	L'o'	,0x1ED3	,0x1ED3	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'A'	,0x1ED5	,0x1EA8	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'a'	,0x1ED5	,0x1EA9	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'E'	,0x1ED5	,0x1EC2	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'e'	,0x1ED5	,0x1EC3	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'O'	,0x1ED5	,0x1ED4	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'o'	,0x1ED5	,0x1ED5	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'D'	,0x1ED5	,0x276C	,0x0001	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'd'	,0x1ED5	,0x276C	,0x0001	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'D'	,0x276C	,0x2770	,0x0001	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	L'd'	,0x276C	,0x2770	,0x0001	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x2770	,0x2770	,0x0000	), // HEAVY LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x2770	,0x2771	,0x0000	), // HEAVY RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x276C	,0x276C	,0x0000	), // MEDIUM LEFT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x276C	,0x276D	,0x0000	), // MEDIUM RIGHT-POINTING ANGLE BRACKET ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x1ED5	,0x27E8	,0x0000	), // MATHEMATICAL LEFT ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x1ED5	,0x27E9	,0x0000	), // MATHEMATICAL RIGHT ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x003C	,0x1ED5	,0x276E	,0x0000	), // HEAVY LEFT-POINTING ANGLE QUOTATION MARK ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x003E	,0x1ED5	,0x276F	,0x0000	), // HEAVY RIGHT-POINTING ANGLE QUOTATION MARK ORNAMENT
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x005D	,0x1ED5	,0x27EA	,0x0001	), // MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0028	,0x27EA	,0x27EA	,0x0000	), // MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&HOOK_ABV*/	DEADTRANS(	0x0029	,0x27EA	,0x27EB	,0x0000	), // MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'A'	,0x1ED7	,0x1EAA	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'a'	,0x1ED7	,0x1EAB	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'E'	,0x1ED7	,0x1EC4	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'e'	,0x1ED7	,0x1EC5	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'O'	,0x1ED7	,0x1ED6	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX&TILDE   */	DEADTRANS(	L'o'	,0x1ED7	,0x1ED7	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0020	,0x00EA	,0x0302	,0x0000	), // COMBINING CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00A0	,0x00EA	,0x005E	,0x0000	), // CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x202F	,0x00EA	,0x02C6	,0x0000	), // MODIFIER LETTER CIRCUMFLEX ACCENT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'A'	,0x00EA	,0x00C2	,0x0000	), // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'a'	,0x00EA	,0x00E2	,0x0000	), // LATIN SMALL LETTER A WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'B'	,0x00EA	,0x00A6	,0x0000	), // BROKEN BAR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'b'	,0x00EA	,0x00A6	,0x0000	), // BROKEN BAR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'C'	,0x00EA	,0x0108	,0x0000	), // LATIN CAPITAL LETTER C WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'c'	,0x00EA	,0x0109	,0x0000	), // LATIN SMALL LETTER C WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'E'	,0x00EA	,0x00CA	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'e'	,0x00EA	,0x00EA	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'G'	,0x00EA	,0x011C	,0x0000	), // LATIN CAPITAL LETTER G WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'g'	,0x00EA	,0x011D	,0x0000	), // LATIN SMALL LETTER G WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'H'	,0x00EA	,0x0124	,0x0000	), // LATIN CAPITAL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'h'	,0x00EA	,0x0125	,0x0000	), // LATIN SMALL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'I'	,0x00EA	,0x00CE	,0x0000	), // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'i'	,0x00EA	,0x00EE	,0x0000	), // LATIN SMALL LETTER I WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'J'	,0x00EA	,0x0134	,0x0000	), // LATIN CAPITAL LETTER J WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'j'	,0x00EA	,0x0135	,0x0000	), // LATIN SMALL LETTER J WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'O'	,0x00EA	,0x00D4	,0x0000	), // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'o'	,0x00EA	,0x00F4	,0x0000	), // LATIN SMALL LETTER O WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'S'	,0x00EA	,0x015C	,0x0000	), // LATIN CAPITAL LETTER S WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L's'	,0x00EA	,0x015D	,0x0000	), // LATIN SMALL LETTER S WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'U'	,0x00EA	,0x00DB	,0x0000	), // LATIN CAPITAL LETTER U WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'u'	,0x00EA	,0x00FB	,0x0000	), // LATIN SMALL LETTER U WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'W'	,0x00EA	,0x0174	,0x0000	), // LATIN CAPITAL LETTER W WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'w'	,0x00EA	,0x0175	,0x0000	), // LATIN SMALL LETTER W WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'Y'	,0x00EA	,0x0176	,0x0000	), // LATIN CAPITAL LETTER Y WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'y'	,0x00EA	,0x0177	,0x0000	), // LATIN SMALL LETTER Y WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'Z'	,0x00EA	,0x1E90	,0x0000	), // LATIN CAPITAL LETTER Z WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'z'	,0x00EA	,0x1E91	,0x0000	), // LATIN SMALL LETTER Z WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00C0	,0x00EA	,0x00C5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E0	,0x00EA	,0x00E5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00C6	,0x00EA	,0x00AD	,0x0000	), // SOFT HYPHEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E6	,0x00EA	,0x00AD	,0x0000	), // SOFT HYPHEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00C7	,0x00EA	,0x00D8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E7	,0x00EA	,0x00F8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00C8	,0x00EA	,0x0130	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E8	,0x00EA	,0x0131	,0x0000	), // LATIN SMALL LETTER DOTLESS I
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00C9	,0x00EA	,0x00B2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E9	,0x00EA	,0x00B2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0152	,0x00EA	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0153	,0x00EA	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00D9	,0x00EA	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00F9	,0x00EA	,0x0026	,0x0000	), // AMPERSAND
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0021	,0x00EA	,0x1ED9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0022	,0x00EA	,0x201C	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0023	,0x00EA	,0x00B3	,0x0000	), // SUPERSCRIPT THREE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0024	,0x00EA	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0025	,0x00EA	,0x2030	,0x0000	), // PER MILLE SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0027	,0x00EA	,0x2018	,0x0000	), // LEFT SINGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0028	,0x00EA	,0x02BF	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0029	,0x00EA	,0x02BE	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002A	,0x00EA	,0x2042	,0x0000	), // ASTERISM
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002B	,0x00EA	,0x207A	,0x0000	), // SUPERSCRIPT PLUS SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002C	,0x00EA	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002D	,0x00EA	,0x2014	,0x0000	), // EM DASH
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002E	,0x00EA	,0x00B7	,0x0000	), // MIDDLE DOT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x002F	,0x00EA	,0x2044	,0x0000	), // FRACTION SLASH
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'0'	,0x00EA	,0x2070	,0x0000	), // SUPERSCRIPT ZERO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'1'	,0x00EA	,0x00B9	,0x0000	), // SUPERSCRIPT ONE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'2'	,0x00EA	,0x00B2	,0x0000	), // SUPERSCRIPT TWO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'3'	,0x00EA	,0x00B3	,0x0000	), // SUPERSCRIPT THREE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'4'	,0x00EA	,0x2074	,0x0000	), // SUPERSCRIPT FOUR
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'5'	,0x00EA	,0x2075	,0x0000	), // SUPERSCRIPT FIVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'6'	,0x00EA	,0x2076	,0x0000	), // SUPERSCRIPT SIX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'7'	,0x00EA	,0x2077	,0x0000	), // SUPERSCRIPT SEVEN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'8'	,0x00EA	,0x2078	,0x0000	), // SUPERSCRIPT EIGHT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	L'9'	,0x00EA	,0x2079	,0x0000	), // SUPERSCRIPT NINE
//@
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003A	,0x00EA	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003B	,0x00EA	,0x2027	,0x0000	), // HYPHENATION POINT
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003C	,0x00EA	,0x2A7D	,0x0000	), // LESS-THAN OR SLANTED EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003D	,0x00EA	,0x2266	,0x0000	), // LESS-THAN OVER EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003E	,0x00EA	,0x2276	,0x0000	), // LESS-THAN OR GREATER-THAN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003F	,0x00EA	,0x203D	,0x0000	), // INTERROBANG
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0040	,0x00EA	,0x25B3	,0x0000	), // WHITE UP-POINTING TRIANGLE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005B	,0x00EA	,0x0188	,0x0001	), // LATIN SMALL LETTER C WITH HOOK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0028	,0x0188	,0x2329	,0x0000	), // LEFT-POINTING ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0029	,0x0188	,0x232A	,0x0000	), // RIGHT-POINTING ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003C	,0x0188	,0x3008	,0x0000	), // LEFT ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003E	,0x0188	,0x3009	,0x0000	), // RIGHT ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005B	,0x0188	,0x300A	,0x0001	), // LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003C	,0x300A	,0x300A	,0x0000	), // LEFT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x003E	,0x300A	,0x300B	,0x0000	), // RIGHT DOUBLE ANGLE BRACKET
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2026	,0x0188	,0xF900	,0x0001	), // CJK COMPATIBILITY IDEOGRAPH-F900
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005D	,0xF900	,0x0125	,0x0000	), // LATIN SMALL LETTER H WITH CIRCUMFLEX
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005D	,0x00EA	,0x1ED5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x005F	,0x00EA	,0x2264	,0x0000	), // LESS-THAN OR EQUAL TO
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0060	,0x00EA	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x007C	,0x00EA	,0x2020	,0x0000	), // DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x007E	,0x00EA	,0x1ED7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x20AC	,0x00EA	,0x20A6	,0x0000	), // NAIRA SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2021	,0x00EA	,0x2E4B	,0x0000	), // TRIPLE DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0027	,0x2460	,0x1ED1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0060	,0x2460	,0x1ED3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00A7	,0x00EA	,0x00B6	,0x0000	), // PILCROW SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00AB	,0x00EA	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00B5	,0x00EA	,0x2208	,0x0000	), // ELEMENT OF
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00BB	,0x00EA	,0x203A	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00E1	,0x00EA	,0x1ED1	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00EA	,0x00EA	,0x1E19	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00EB	,0x00EA	,0x022F	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00F2	,0x00EA	,0x1ED3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x00F5	,0x00EA	,0x1ED7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x02BC	,0x00EA	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2019	,0x00EA	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2212	,0x00EA	,0x207B	,0x0000	), // SUPERSCRIPT MINUS
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x2610	,0x00EA	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x222A	,0x00EA	,0x2229	,0x0000	), // INTERSECTION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x1EBB	,0x00EA	,0x1ED5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0132	,0x00EA	,0x2021	,0x0000	), // DOUBLE DAGGER
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x0133	,0x00EA	,0x00A5	,0x0000	), // YEN SIGN
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x1EE5	,0x00EA	,0x1ED9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03B8	,0x00EA	,0x2229	,0x0000	), // INTERSECTION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03F4	,0x00EA	,0x222A	,0x0000	), // UNION
/*CIRCUMFLEX_ACCENT  */	DEADTRANS(	0x03C0	,0x00EA	,0x220B	,0x0000	), // CONTAINS AS MEMBER
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x0020	,0x1E19	,0x032D	,0x0000	), // COMBINING CIRCUMFLEX ACCENT BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x00A0	,0x1E19	,0xA788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x202F	,0x1E19	,0xA788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'D'	,0x1E19	,0x1E12	,0x0000	), // LATIN CAPITAL LETTER D WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'd'	,0x1E19	,0x1E13	,0x0000	), // LATIN SMALL LETTER D WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'E'	,0x1E19	,0x1E18	,0x0000	), // LATIN CAPITAL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'e'	,0x1E19	,0x1E19	,0x0000	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'L'	,0x1E19	,0x1E3C	,0x0000	), // LATIN CAPITAL LETTER L WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'l'	,0x1E19	,0x1E3D	,0x0000	), // LATIN SMALL LETTER L WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'N'	,0x1E19	,0x1E4A	,0x0000	), // LATIN CAPITAL LETTER N WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'n'	,0x1E19	,0x1E4B	,0x0000	), // LATIN SMALL LETTER N WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'T'	,0x1E19	,0x1E70	,0x0000	), // LATIN CAPITAL LETTER T WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L't'	,0x1E19	,0x1E71	,0x0000	), // LATIN SMALL LETTER T WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'U'	,0x1E19	,0x1E76	,0x0000	), // LATIN CAPITAL LETTER U WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'u'	,0x1E19	,0x1E77	,0x0000	), // LATIN SMALL LETTER U WITH CIRCUMFLEX BELOW
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	L'X'	,0x1E19	,0x2716	,0x0000	), // HEAVY MULTIPLICATION X
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x0025	,0x1E19	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x00EA	,0x1E19	,0x021F	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*CIRCUMFLEX_BELOW   */	DEADTRANS(	0x2610	,0x1E19	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMBINING_ABOVE    */	DEADTRANS(	L'A'	,0x002A	,0x031A	,0x0000	), // COMBINING LEFT ANGLE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'a'	,0x002A	,0x0363	,0x0000	), // COMBINING LATIN SMALL LETTER A
/*COMBINING_ABOVE    */	DEADTRANS(	L'b'	,0x002A	,0x1DE8	,0x0000	), // COMBINING LATIN SMALL LETTER B
/*COMBINING_ABOVE    */	DEADTRANS(	L'c'	,0x002A	,0x0368	,0x0000	), // COMBINING LATIN SMALL LETTER C
/*COMBINING_ABOVE    */	DEADTRANS(	L'd'	,0x002A	,0x0369	,0x0000	), // COMBINING LATIN SMALL LETTER D
/*COMBINING_ABOVE    */	DEADTRANS(	L'e'	,0x002A	,0x0364	,0x0000	), // COMBINING LATIN SMALL LETTER E
/*COMBINING_ABOVE    */	DEADTRANS(	L'f'	,0x002A	,0x1DEB	,0x0000	), // COMBINING LATIN SMALL LETTER F
/*COMBINING_ABOVE    */	DEADTRANS(	L'G'	,0x002A	,0x1DDB	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL G
/*COMBINING_ABOVE    */	DEADTRANS(	L'g'	,0x002A	,0x1DDA	,0x0000	), // COMBINING LATIN SMALL LETTER G
/*COMBINING_ABOVE    */	DEADTRANS(	L'h'	,0x002A	,0x036A	,0x0000	), // COMBINING LATIN SMALL LETTER H
/*COMBINING_ABOVE    */	DEADTRANS(	L'i'	,0x002A	,0x0365	,0x0000	), // COMBINING LATIN SMALL LETTER I
/*COMBINING_ABOVE    */	DEADTRANS(	L'k'	,0x002A	,0x1DDC	,0x0000	), // COMBINING LATIN SMALL LETTER K
/*COMBINING_ABOVE    */	DEADTRANS(	L'L'	,0x002A	,0x1DDE	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL L
/*COMBINING_ABOVE    */	DEADTRANS(	L'l'	,0x002A	,0x1DDD	,0x0000	), // COMBINING LATIN SMALL LETTER L
/*COMBINING_ABOVE    */	DEADTRANS(	L'M'	,0x002A	,0x1DDF	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL M
/*COMBINING_ABOVE    */	DEADTRANS(	L'm'	,0x002A	,0x036B	,0x0000	), // COMBINING LATIN SMALL LETTER M
/*COMBINING_ABOVE    */	DEADTRANS(	L'N'	,0x002A	,0x1DE1	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL N
/*COMBINING_ABOVE    */	DEADTRANS(	L'n'	,0x002A	,0x1DE0	,0x0000	), // COMBINING LATIN SMALL LETTER N
/*COMBINING_ABOVE    */	DEADTRANS(	L'o'	,0x002A	,0x0366	,0x0000	), // COMBINING LATIN SMALL LETTER O
/*COMBINING_ABOVE    */	DEADTRANS(	L'p'	,0x002A	,0x1DEE	,0x0000	), // COMBINING LATIN SMALL LETTER P
/*COMBINING_ABOVE    */	DEADTRANS(	L'R'	,0x002A	,0x1DE2	,0x0000	), // COMBINING LATIN LETTER SMALL CAPITAL R
/*COMBINING_ABOVE    */	DEADTRANS(	L'r'	,0x002A	,0x036C	,0x0000	), // COMBINING LATIN SMALL LETTER R
/*COMBINING_ABOVE    */	DEADTRANS(	L'S'	,0x002A	,0x1DD1	,0x0000	), // COMBINING UR ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L's'	,0x002A	,0x1DE4	,0x0000	), // COMBINING LATIN SMALL LETTER S
/*COMBINING_ABOVE    */	DEADTRANS(	L'T'	,0x002A	,0x1DF5	,0x0000	), // COMBINING UP TACK ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L't'	,0x002A	,0x036D	,0x0000	), // COMBINING LATIN SMALL LETTER T
/*COMBINING_ABOVE    */	DEADTRANS(	L'u'	,0x002A	,0x0367	,0x0000	), // COMBINING LATIN SMALL LETTER U
/*COMBINING_ABOVE    */	DEADTRANS(	L'V'	,0x002A	,0x1DC3	,0x0000	), // COMBINING SUSPENSION MARK
/*COMBINING_ABOVE    */	DEADTRANS(	L'v'	,0x002A	,0x036E	,0x0000	), // COMBINING LATIN SMALL LETTER V
/*COMBINING_ABOVE    */	DEADTRANS(	L'w'	,0x002A	,0x1DF1	,0x0000	), // COMBINING LATIN SMALL LETTER W
/*COMBINING_ABOVE    */	DEADTRANS(	L'X'	,0x002A	,0x033D	,0x0000	), // COMBINING X ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'x'	,0x002A	,0x036F	,0x0000	), // COMBINING LATIN SMALL LETTER X
/*COMBINING_ABOVE    */	DEADTRANS(	L'Z'	,0x002A	,0x035B	,0x0000	), // COMBINING ZIGZAG ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	L'z'	,0x002A	,0x1DE6	,0x0000	), // COMBINING LATIN SMALL LETTER Z
/*COMBINING_ABOVE    */	DEADTRANS(	0x00E7	,0x002A	,0x1DD7	,0x0000	), // COMBINING LATIN SMALL LETTER C CEDILLA
/*COMBINING_ABOVE    */	DEADTRANS(	0x005E	,0x002A	,0x1DCD	,0x0000	), // COMBINING DOUBLE CIRCUMFLEX ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x00EA	,0x002A	,0x1DCD	,0x0000	), // COMBINING DOUBLE CIRCUMFLEX ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x00F5	,0x002A	,0x0360	,0x0000	), // COMBINING DOUBLE TILDE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0022	,0x002A	,0x030E	,0x0000	), // COMBINING DOUBLE VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0023	,0x002A	,0x030E	,0x0000	), // COMBINING DOUBLE VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0026	,0x002A	,0x0363	,0x0000	), // COMBINING LATIN SMALL LETTER A
/*COMBINING_ABOVE    */	DEADTRANS(	0x0027	,0x002A	,0x030D	,0x0000	), // COMBINING VERTICAL LINE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0028	,0x002A	,0x0351	,0x0000	), // COMBINING LEFT HALF RING ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0029	,0x002A	,0x0357	,0x0000	), // COMBINING RIGHT HALF RING ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x002C	,0x002A	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x002D	,0x002A	,0x1AB3	,0x0000	), // COMBINING DOWNWARDS ARROW
/*COMBINING_ABOVE    */	DEADTRANS(	L'2'	,0x002A	,0x1AB3	,0x0000	), // COMBINING DOWNWARDS ARROW
/*COMBINING_ABOVE    */	DEADTRANS(	0x005F	,0x002A	,0xFE26	,0x0000	), // COMBINING CONJOINING MACRON
/*COMBINING_ABOVE    */	DEADTRANS(	0x002E	,0x002A	,0x0358	,0x0000	), // COMBINING DOT ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00E1	,0x002A	,0x1DC1	,0x0000	), // COMBINING DOTTED ACUTE ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00F2	,0x002A	,0x1DC0	,0x0000	), // COMBINING DOTTED GRAVE ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x002F	,0x002A	,0x1DED	,0x0000	), // COMBINING LATIN SMALL LETTER O WITH LIGHT CENTRALIZATION STROKE
/*COMBINING_ABOVE    */	DEADTRANS(	L'8'	,0x002A	,0x1AB2	,0x0000	), // COMBINING INFINITY
/*COMBINING_ABOVE    */	DEADTRANS(	L'9'	,0x002A	,0x1DD2	,0x0000	), // COMBINING US ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003B	,0x002A	,0x1DCE	,0x0000	), // COMBINING OGONEK ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003C	,0x002A	,0x1DFE	,0x0000	), // COMBINING LEFT ARROWHEAD ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003D	,0x002A	,0x033F	,0x0000	), // COMBINING DOUBLE OVERLINE
/*COMBINING_ABOVE    */	DEADTRANS(	0x003E	,0x002A	,0x0350	,0x0000	), // COMBINING RIGHT ARROWHEAD ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x005B	,0x002A	,0x0346	,0x0000	), // COMBINING BRIDGE ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x007E	,0x002A	,0xFE22	,0x0000	), // COMBINING DOUBLE TILDE LEFT HALF
/*COMBINING_ABOVE    */	DEADTRANS(	0x005D	,0x002A	,0xFE25	,0x0000	), // COMBINING MACRON RIGHT HALF
/*COMBINING_ABOVE    */	DEADTRANS(	0x00A3	,0x002A	,0x1DD8	,0x0000	), // COMBINING LATIN SMALL LETTER INSULAR D
/*COMBINING_ABOVE    */	DEADTRANS(	0x00A9	,0x002A	,0x1DE5	,0x0001	), // COMBINING LATIN SMALL LETTER LONG S
/*COMBINING_ABOVE    */	DEADTRANS(	0x00B0	,0x002A	,0x1DE3	,0x0000	), // COMBINING LATIN SMALL LETTER R ROTUNDA
/*COMBINING_ABOVE    */	DEADTRANS(	0x00B5	,0x002A	,0x1DE7	,0x0000	), // COMBINING LATIN SMALL LETTER ALPHA
/*COMBINING_ABOVE    */	DEADTRANS(	0x00D7	,0x002A	,0x033D	,0x0000	), // COMBINING X ABOVE
/*COMBINING_ABOVE    */	DEADTRANS(	0x0020	,0x002A	,0x1AB0	,0x0000	), // COMBINING DOUBLED CIRCUMFLEX ACCENT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00F9	,0x002A	,0x0315	,0x0000	), // COMBINING COMMA ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x2019	,0x002A	,0x0315	,0x0000	), // COMBINING COMMA ABOVE RIGHT
/*COMBINING_ABOVE    */	DEADTRANS(	0x00EB	,0x002A	,0x1DF2	,0x0000	), // COMBINING LATIN SMALL LETTER A WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00E0	,0x002A	,0x1DF3	,0x0000	), // COMBINING LATIN SMALL LETTER O WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00E8	,0x002A	,0x1DF4	,0x0000	), // COMBINING LATIN SMALL LETTER U WITH DIAERESIS
/*COMBINING_ABOVE    */	DEADTRANS(	0x00E9	,0x002A	,0x1DF2	,0x0000	), // COMBINING LATIN SMALL LETTER A WITH DIAERESIS
/*COMBINING_BELOW    */	DEADTRANS(	L'A'	,0x2038	,0x0349	,0x0000	), // COMBINING LEFT ANGLE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'i'	,0x2038	,0x1DD0	,0x0000	), // COMBINING IS BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'j'	,0x2038	,0x1AB7	,0x0000	), // COMBINING OPEN MARK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'r'	,0x2038	,0x1DCA	,0x0000	), // COMBINING LATIN SMALL LETTER R BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L's'	,0x2038	,0x1DC2	,0x0000	), // COMBINING SNAKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L't'	,0x2038	,0x031D	,0x0001	), // COMBINING UP TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'b'	,0x031D	,0x031E	,0x0000	), // COMBINING DOWN TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'd'	,0x031D	,0x0319	,0x0000	), // COMBINING RIGHT TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'g'	,0x031D	,0x0318	,0x0000	), // COMBINING LEFT TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'h'	,0x031D	,0x031D	,0x0000	), // COMBINING UP TACK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'V'	,0x2038	,0x1DFF	,0x0000	), // COMBINING RIGHT ARROWHEAD AND DOWN ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'v'	,0x2038	,0x033C	,0x0000	), // COMBINING SEAGULL BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'w'	,0x2038	,0x1AB6	,0x0000	), // COMBINING WIGGLY LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'x'	,0x2038	,0x0353	,0x0000	), // COMBINING X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'z'	,0x2038	,0x1DCF	,0x0000	), // COMBINING ZIGZAG BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00F9	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0022	,0x2038	,0x0348	,0x0000	), // COMBINING DOUBLE VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0024	,0x2038	,0x00C7	,0x0001	), // LATIN CAPITAL LETTER C WITH CEDILLA
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x00C7	,0x035C	,0x0000	), // COMBINING DOUBLE BREVE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002D	,0x00C7	,0x0362	,0x0000	), // COMBINING DOUBLE RIGHTWARDS ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005F	,0x00C7	,0x035F	,0x0000	), // COMBINING DOUBLE MACRON BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0027	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x2038	,0x031C	,0x0000	), // COMBINING LEFT HALF RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x1ABD	,0x032F	,0x0000	), // COMBINING INVERTED BREVE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x1ABD	,0x1ABD	,0x0000	), // COMBINING PARENTHESES BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x2038	,0x0339	,0x0000	), // COMBINING RIGHT HALF RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002A	,0x2038	,0x0359	,0x0000	), // COMBINING ASTERISK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002B	,0x2038	,0x031F	,0x0000	), // COMBINING PLUS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002D	,0x2038	,0x1E07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'5'	,0x1E07	,0x034D	,0x0000	), // COMBINING LEFT RIGHT ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'8'	,0x1E07	,0x034E	,0x0000	), // COMBINING UPWARDS ARROW BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002D	,0x1E07	,0x0320	,0x0000	), // COMBINING MINUS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005F	,0x1E07	,0xFE2D	,0x0000	), // COMBINING CONJOINING MACRON BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002E	,0x2038	,0x1ABA	,0x0000	), // COMBINING STRONG CENTRALIZATION STROKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x002F	,0x2038	,0x1AB9	,0x0000	), // COMBINING LIGHT CENTRALIZATION STROKE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'8'	,0x2038	,0x035A	,0x0000	), // COMBINING DOUBLE RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003C	,0x2038	,0x0354	,0x0000	), // COMBINING LEFT ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003D	,0x2038	,0x2017	,0x0001	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	L'j'	,0x2017	,0x1AB8	,0x0000	), // COMBINING DOUBLE OPEN MARK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	L'x'	,0x2017	,0x1AB5	,0x0000	), // COMBINING X-X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x2017	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x0029	,0x2017	,0x032B	,0x0000	), // COMBINING INVERTED DOUBLE ARCH BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003D	,0x2017	,0x0347	,0x0000	), // COMBINING EQUALS SIGN BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00A0	,0x2017	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x00B0	,0x2017	,0x035A	,0x0000	), // COMBINING DOUBLE RING BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00D7	,0x2017	,0x1AB5	,0x0000	), // COMBINING X-X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202F	,0x2017	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*COMBINING_BELOW    */	DEADTRANS(	0x003E	,0x2038	,0x0355	,0x0000	), // COMBINING RIGHT ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005B	,0x2038	,0x032A	,0x0001	), // COMBINING BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x032A	,0xFE27	,0x0000	), // COMBINING LIGATURE LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005B	,0x032A	,0x032A	,0x0000	), // COMBINING BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005F	,0x032A	,0xFE2B	,0x0000	), // COMBINING MACRON LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x007E	,0x032A	,0xFE29	,0x0000	), // COMBINING TILDE LEFT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005D	,0x2038	,0x033A	,0x0001	), // COMBINING INVERTED BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x033A	,0x0321	,0x0000	), // COMBINING PALATALIZED HOOK BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x0028	,0x033A	,0xFE28	,0x0000	), // COMBINING LIGATURE RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005D	,0x033A	,0x033A	,0x0000	), // COMBINING INVERTED BRIDGE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005F	,0x033A	,0xFE2C	,0x0000	), // COMBINING MACRON RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x007E	,0x033A	,0xFE2A	,0x0000	), // COMBINING TILDE RIGHT HALF BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x005E	,0x2038	,0x0356	,0x0000	), // COMBINING RIGHT ARROWHEAD AND UP ARROWHEAD BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00D7	,0x2038	,0x0353	,0x0000	), // COMBINING X BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00E1	,0x2038	,0x02CF	,0x0000	), // MODIFIER LETTER LOW ACUTE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x00EA	,0x2038	,0x2041	,0x0001	), // CARET INSERTION POINT
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x2041	,0x032D	,0x0000	), // COMBINING CIRCUMFLEX ACCENT BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00EA	,0x2041	,0xA788	,0x0000	), // MODIFIER LETTER LOW CIRCUMFLEX ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x202F	,0x2041	,0x2041	,0x0000	), // CARET INSERTION POINT
/*COMBINING_BELOW    */	DEADTRANS(	0x00EB	,0x2038	,0x0324	,0x0000	), // COMBINING DIAERESIS BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00F2	,0x2038	,0x02CE	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x02CE	,0x0316	,0x0000	), // COMBINING GRAVE ACCENT BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202F	,0x02CE	,0x02CE	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*COMBINING_BELOW    */	DEADTRANS(	0x00F5	,0x2038	,0x02F7	,0x0001	), // MODIFIER LETTER LOW TILDE
/*COMBINING_BELOW    */	DEADTRANS(	0x0020	,0x02F7	,0x0330	,0x0000	), // COMBINING TILDE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x003D	,0x02F7	,0x1DFD	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x00F5	,0x02F7	,0x1DFD	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x202F	,0x02F7	,0x02F7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*COMBINING_BELOW    */	DEADTRANS(	0x2019	,0x2038	,0x0329	,0x0000	), // COMBINING VERTICAL LINE BELOW
/*COMBINING_BELOW    */	DEADTRANS(	0x2610	,0x2038	,0x033B	,0x0000	), // COMBINING SQUARE BELOW
/*COMBINING_OVERLAY  */	DEADTRANS(	L'P'	,0x002B	,0x204D	,0x0000	), // BLACK RIGHTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'p'	,0x002B	,0x204D	,0x0000	), // BLACK RIGHTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'Q'	,0x002B	,0x204C	,0x0000	), // BLACK LEFTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	L'q'	,0x002B	,0x204C	,0x0000	), // BLACK LEFTWARDS BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x0025	,0x002B	,0x0337	,0x0000	), // COMBINING SHORT SOLIDUS OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002A	,0x002B	,0x2055	,0x0000	), // FLOWER PUNCTUATION MARK
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002B	,0x002B	,0x00B1	,0x0000	), // PLUS-MINUS SIGN
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002D	,0x002B	,0x0335	,0x0000	), // COMBINING SHORT STROKE OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002E	,0x002B	,0x2022	,0x0000	), // BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x002F	,0x002B	,0x0338	,0x0000	), // COMBINING LONG SOLIDUS OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003A	,0x002B	,0x205C	,0x0000	), // DOTTED CROSS
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003D	,0x002B	,0x2043	,0x0000	), // HYPHEN BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x003E	,0x002B	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*COMBINING_OVERLAY  */	DEADTRANS(	0x005F	,0x002B	,0x0336	,0x0000	), // COMBINING LONG STROKE OVERLAY
/*COMBINING_OVERLAY  */	DEADTRANS(	0x007E	,0x002B	,0x026B	,0x0001	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*COMBINING_OVERLAY  */	DEADTRANS(	0x00F5	,0x002B	,0x026B	,0x0001	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*COMBINING_OVERLAY  */	DEADTRANS(	0x2212	,0x002B	,0x00B1	,0x0000	), // PLUS-MINUS SIGN
/*COMMA_BELOW        */	DEADTRANS(	0x0020	,0x0219	,0x0326	,0x0000	), // COMBINING COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'J'	,0x0219	,0xA72E	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO WITH COMMA
/*COMMA_BELOW        */	DEADTRANS(	L'j'	,0x0219	,0xA72F	,0x0000	), // LATIN SMALL LETTER CUATRILLO WITH COMMA
/*COMMA_BELOW        */	DEADTRANS(	L'S'	,0x0219	,0x0218	,0x0000	), // LATIN CAPITAL LETTER S WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L's'	,0x0219	,0x0219	,0x0000	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'T'	,0x0219	,0x021A	,0x0000	), // LATIN CAPITAL LETTER T WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L't'	,0x0219	,0x021B	,0x0000	), // LATIN SMALL LETTER T WITH COMMA BELOW
/*COMMA_BELOW        */	DEADTRANS(	L'X'	,0x0219	,0xAB55	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW LEFT SERIF
/*COMMA_BELOW        */	DEADTRANS(	L'x'	,0x0219	,0xAB58	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*COMPOSE            */	DEADTRANS(	0x202F	,0x00A6	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	L'A'	,0x00A6	,0x0041	,0x0001	), // LATIN CAPITAL LETTER A
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0041	,0xA732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0041	,0xA732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0041	,0x00C6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0041	,0x00C6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0041	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0041	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0041	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0041	,0xA734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0041	,0xA734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0041	,0x214D	,0x0000	), // AKTIESELSKAB
/*COMPOSE            */	DEADTRANS(	L'U'	,0x0041	,0xA736	,0x0000	), // LATIN CAPITAL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0041	,0xA736	,0x0000	), // LATIN CAPITAL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0041	,0xA738	,0x0000	), // LATIN CAPITAL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0041	,0xA738	,0x0000	), // LATIN CAPITAL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0041	,0xA73C	,0x0000	), // LATIN CAPITAL LETTER AY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0041	,0xA73C	,0x0000	), // LATIN CAPITAL LETTER AY
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0041	,0x01C2	,0x0000	), // LATIN LETTER ALVEOLAR CLICK
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0041	,0x2100	,0x0001	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2100	,0x2100	,0x0000	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'S'	,0x2100	,0x214D	,0x0000	), // AKTIESELSKAB
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0041	,0xA79A	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK AE
/*COMPOSE            */	DEADTRANS(	0x005F	,0x0041	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'a'	,0x00A6	,0x0061	,0x0001	), // LATIN SMALL LETTER A
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0061	,0xA732	,0x0000	), // LATIN CAPITAL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0061	,0xA733	,0x0000	), // LATIN SMALL LETTER AA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0061	,0x00C6	,0x0000	), // LATIN CAPITAL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0061	,0x00E6	,0x0000	), // LATIN SMALL LETTER AE
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0061	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0061	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0061	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0061	,0xA734	,0x0000	), // LATIN CAPITAL LETTER AO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0061	,0xA735	,0x0000	), // LATIN SMALL LETTER AO
/*COMPOSE            */	DEADTRANS(	L's'	,0x0061	,0x2101	,0x0000	), // ADDRESSED TO THE SUBJECT
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0061	,0xA737	,0x0000	), // LATIN SMALL LETTER AU
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0061	,0xA739	,0x0000	), // LATIN SMALL LETTER AV
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0061	,0xA73D	,0x0000	), // LATIN SMALL LETTER AY
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0061	,0x01C2	,0x0000	), // LATIN LETTER ALVEOLAR CLICK
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0061	,0x1E9A	,0x0000	), // LATIN SMALL LETTER A WITH RIGHT HALF RING
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0061	,0x2100	,0x0001	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2100	,0x2100	,0x0000	), // ACCOUNT OF
/*COMPOSE            */	DEADTRANS(	L's'	,0x2100	,0x2101	,0x0000	), // ADDRESSED TO THE SUBJECT
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0061	,0xA79B	,0x0000	), // LATIN SMALL LETTER VOLAPUK AE
/*COMPOSE            */	DEADTRANS(	0x005C	,0x0061	,0xAB31	,0x0000	), // LATIN SMALL LETTER A REVERSED-SCHWA
/*COMPOSE            */	DEADTRANS(	0x005F	,0x0061	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'B'	,0x00A6	,0x0062	,0x0001	), // LATIN SMALL LETTER B
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0042	,0x264E	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'B'	,0x0042	,0x266D	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0042	,0x2658	,0x0000	), // WHITE CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0042	,0x2655	,0x0000	), // WHITE CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0042	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'F'	,0x0042	,0x2657	,0x0000	), // WHITE CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0042	,0xA7B4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0042	,0xA7B4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0042	,0x266D	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0042	,0x2659	,0x0000	), // WHITE CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x0042	,0x266E	,0x0000	), // MUSIC NATURAL SIGN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0042	,0x2654	,0x0000	), // WHITE CHESS KING
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0042	,0x2656	,0x0000	), // WHITE CHESS ROOK
/*COMPOSE            */	DEADTRANS(	0x00C9	,0x0042	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0042	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0042	,0x02FB	,0x0000	), // MODIFIER LETTER BEGIN LOW TONE
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0042	,0x02FC	,0x0000	), // MODIFIER LETTER END LOW TONE
/*COMPOSE            */	DEADTRANS(	L'b'	,0x00A6	,0x0062	,0x0001	), // LATIN SMALL LETTER B
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0062	,0x264E	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'b'	,0x0062	,0x266D	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0062	,0x2658	,0x0000	), // WHITE CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0062	,0x2655	,0x0000	), // WHITE CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0062	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0062	,0x2657	,0x0000	), // WHITE CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0062	,0xA7B5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0062	,0xA7B5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0062	,0x266D	,0x0000	), // MUSIC FLAT SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0062	,0x2659	,0x0000	), // WHITE CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'q'	,0x0062	,0x266E	,0x0000	), // MUSIC NATURAL SIGN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0062	,0x2654	,0x0000	), // WHITE CHESS KING
/*COMPOSE            */	DEADTRANS(	L't'	,0x0062	,0x2656	,0x0000	), // WHITE CHESS ROOK
/*COMPOSE            */	DEADTRANS(	0x00E9	,0x0062	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0062	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0062	,0x02FB	,0x0000	), // MODIFIER LETTER BEGIN LOW TONE
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0062	,0x02FC	,0x0000	), // MODIFIER LETTER END LOW TONE
/*COMPOSE            */	DEADTRANS(	L'C'	,0x00A6	,0x0043	,0x0001	), // LATIN CAPITAL LETTER C
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0043	,0x264B	,0x0001	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'N'	,0x264B	,0x264B	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'P'	,0x264B	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0043	,0x2102	,0x0000	), // DOUBLE-STRUCK CAPITAL C
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0043	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0043	,0x264B	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0043	,0xA76E	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0043	,0xA76E	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0043	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0043	,0x00A9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0043	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0043	,0x0436	,0x0001	), // CYRILLIC SMALL LETTER ZHE
/*COMPOSE            */	DEADTRANS(	0x00C9	,0x0043	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	0x002D	,0x0043	,0x266B	,0x0000	), // BEAMED EIGHTH NOTES
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0043	,0x2105	,0x0001	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2105	,0x2105	,0x0000	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'U'	,0x2105	,0x2106	,0x0000	), // CADA UNA
/*COMPOSE            */	DEADTRANS(	L'0'	,0x0043	,0x2648	,0x0001	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0043	,0x2651	,0x0001	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0043	,0xA72C	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x003D	,0x0043	,0x266C	,0x0000	), // BEAMED SIXTEENTH NOTES
/*COMPOSE            */	DEADTRANS(	0x00EA	,0x0043	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x00EB	,0x0043	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'c'	,0x00A6	,0x0063	,0x0001	), // LATIN SMALL LETTER C
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0063	,0x264B	,0x0001	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'n'	,0x264B	,0x264B	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'p'	,0x264B	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0063	,0xAB62	,0x0000	), // LATIN SMALL LETTER OPEN OE
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0063	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0063	,0x264B	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0063	,0xA76E	,0x0000	), // LATIN CAPITAL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0063	,0xA76F	,0x0000	), // LATIN SMALL LETTER CON
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0063	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0063	,0x00A9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L's'	,0x0063	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0063	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*COMPOSE            */	DEADTRANS(	0x00E9	,0x0063	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	0x002D	,0x0063	,0x266B	,0x0000	), // BEAMED EIGHTH NOTES
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0063	,0x2105	,0x0001	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2105	,0x2105	,0x0000	), // CARE OF
/*COMPOSE            */	DEADTRANS(	L'u'	,0x2105	,0x2106	,0x0000	), // CADA UNA
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0063	,0xA72D	,0x0000	), // LATIN SMALL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x003D	,0x0063	,0x266C	,0x0000	), // BEAMED SIXTEENTH NOTES
/*COMPOSE            */	DEADTRANS(	0x00EA	,0x0063	,0xA702	,0x0001	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x0028	,0xA702	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	0x0029	,0xA702	,0xA704	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN QU
/*COMPOSE            */	DEADTRANS(	0x005F	,0xA702	,0xA703	,0x0001	), // MODIFIER LETTER CHINESE TONE YANG SHANG
/*COMPOSE            */	DEADTRANS(	0x0028	,0xA703	,0xA703	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG SHANG
/*COMPOSE            */	DEADTRANS(	0x0029	,0xA703	,0xA705	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG QU
/*COMPOSE            */	DEADTRANS(	0x00EB	,0x0063	,0xA700	,0x0001	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	0x0028	,0xA700	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	0x0029	,0xA700	,0xA706	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN RU
/*COMPOSE            */	DEADTRANS(	0x005F	,0xA700	,0xA701	,0x0001	), // MODIFIER LETTER CHINESE TONE YANG PING
/*COMPOSE            */	DEADTRANS(	0x0028	,0xA701	,0xA701	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG PING
/*COMPOSE            */	DEADTRANS(	0x0029	,0xA701	,0xA707	,0x0000	), // MODIFIER LETTER CHINESE TONE YANG RU
/*COMPOSE            */	DEADTRANS(	L'D'	,0x00A6	,0x0044	,0x0001	), // LATIN CAPITAL LETTER D
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0044	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0044	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0044	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0044	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0044	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0044	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0044	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0044	,0x01F1	,0x0000	), // LATIN CAPITAL LETTER DZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0044	,0x01F2	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z
/*COMPOSE            */	DEADTRANS(	0x00C8	,0x0044	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0044	,0x01C0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0023	,0x0044	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0044	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0044	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005D	,0x0044	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	L'd'	,0x00A6	,0x0064	,0x0001	), // LATIN SMALL LETTER D
/*COMPOSE            */	DEADTRANS(	L'b'	,0x0064	,0x0238	,0x0000	), // LATIN SMALL LETTER DB DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0064	,0xFB00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0064	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0064	,0x00F0	,0x0000	), // LATIN SMALL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0064	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0064	,0x1E9F	,0x0000	), // LATIN SMALL LETTER DELTA
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0064	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L's'	,0x0064	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0064	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0064	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0064	,0xA771	,0x0000	), // LATIN SMALL LETTER DUM
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0064	,0x01F3	,0x0000	), // LATIN SMALL LETTER DZ
/*COMPOSE            */	DEADTRANS(	0x00E8	,0x0064	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0064	,0x01C0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0023	,0x0064	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*COMPOSE            */	DEADTRANS(	0x0026	,0x0064	,0x02A3	,0x0000	), // LATIN SMALL LETTER DZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x0029	,0x0064	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0064	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x005D	,0x0064	,0x266A	,0x0000	), // EIGHTH NOTE
/*COMPOSE            */	DEADTRANS(	0x00A9	,0x0064	,0x02A4	,0x0000	), // LATIN SMALL LETTER DEZH DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'E'	,0x00A6	,0x0045	,0x0001	), // LATIN CAPITAL LETTER E
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0045	,0x018F	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0045	,0x018F	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0045	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0045	,0x212E	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0045	,0xA76A	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L't'	,0x0045	,0xA76A	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0045	,0x2205	,0x0000	), // EMPTY SET
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0045	,0xA72A	,0x0000	), // LATIN CAPITAL LETTER TRESILLO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0045	,0x204A	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'e'	,0x00A6	,0x0065	,0x0001	), // LATIN SMALL LETTER E
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0065	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0065	,0x018F	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0065	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0065	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0065	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0065	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L's'	,0x0065	,0x212E	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0065	,0xA76A	,0x0000	), // LATIN CAPITAL LETTER ET
/*COMPOSE            */	DEADTRANS(	L't'	,0x0065	,0xA76B	,0x0000	), // LATIN SMALL LETTER ET
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0065	,0x2205	,0x0000	), // EMPTY SET
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0065	,0xA72B	,0x0000	), // LATIN SMALL LETTER TRESILLO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0065	,0x204A	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'F'	,0x00A6	,0x0046	,0x0001	), // LATIN CAPITAL LETTER F
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0046	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'f'	,0x00A6	,0x0066	,0x0001	), // LATIN SMALL LETTER F
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0066	,0xAB35	,0x0000	), // LATIN SMALL LETTER LENIS F
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0066	,0xFB00	,0x0001	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'f'	,0xFB00	,0xFB00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'i'	,0xFB00	,0xFB03	,0x0000	), // LATIN SMALL LIGATURE FFI
/*COMPOSE            */	DEADTRANS(	L'l'	,0xFB00	,0xFB04	,0x0000	), // LATIN SMALL LIGATURE FFL
/*COMPOSE            */	DEADTRANS(	0x0020	,0xFB00	,0xFB00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0066	,0xFB01	,0x0000	), // LATIN SMALL LIGATURE FI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0066	,0xFB02	,0x0000	), // LATIN SMALL LIGATURE FL
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0066	,0x02A9	,0x0000	), // LATIN SMALL LETTER FENG DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0066	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'G'	,0x00A6	,0x0047	,0x0001	), // LATIN CAPITAL LETTER G
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0047	,0x264A	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0047	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0047	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0047	,0x01A2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0047	,0x01A2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0047	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0047	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0047	,0xFEFF	,0x0000	), // ZERO WIDTH NO-BREAK SPACE
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0047	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0047	,0x03A9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00C9	,0x0047	,0x264A	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'g'	,0x00A6	,0x0067	,0x0001	), // LATIN SMALL LETTER G
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0067	,0x264A	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0067	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0067	,0x021D	,0x0000	), // LATIN SMALL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0067	,0x01A2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0067	,0x01A3	,0x0000	), // LATIN SMALL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0067	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0067	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0067	,0x2060	,0x0000	), // WORD JOINER
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0067	,0x014B	,0x0000	), // LATIN SMALL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0067	,0x03A9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00E9	,0x0067	,0x264A	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'H'	,0x00A6	,0x0048	,0x0001	), // LATIN CAPITAL LETTER H
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0048	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0048	,0x2135	,0x0000	), // ALEF SYMBOL
/*COMPOSE            */	DEADTRANS(	L'G'	,0x0048	,0x01A2	,0x0000	), // LATIN CAPITAL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0048	,0x210D	,0x0000	), // DOUBLE-STRUCK CAPITAL H
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0048	,0xA726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0048	,0xA726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0048	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0048	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0048	,0x00DE	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'W'	,0x0048	,0x01F6	,0x0000	), // LATIN CAPITAL LETTER HWAIR
/*COMPOSE            */	DEADTRANS(	L'w'	,0x0048	,0x01F6	,0x0000	), // LATIN CAPITAL LETTER HWAIR
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0048	,0x01B7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	0x0028	,0x0048	,0x2C75	,0x0000	), // LATIN CAPITAL LETTER HALF H
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0048	,0x02F9	,0x0000	), // MODIFIER LETTER BEGIN HIGH TONE
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0048	,0x02FA	,0x0000	), // MODIFIER LETTER END HIGH TONE
/*COMPOSE            */	DEADTRANS(	L'h'	,0x00A6	,0x0068	,0x0001	), // LATIN SMALL LETTER H
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0068	,0x00F0	,0x0000	), // LATIN SMALL LETTER ETH
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0068	,0x2135	,0x0000	), // ALEF SYMBOL
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0068	,0x01A3	,0x0000	), // LATIN SMALL LETTER OI
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0068	,0xA726	,0x0000	), // LATIN CAPITAL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0068	,0xA727	,0x0000	), // LATIN SMALL LETTER HENG
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0068	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L's'	,0x0068	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L't'	,0x0068	,0x00FE	,0x0000	), // LATIN SMALL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0068	,0x0195	,0x0000	), // LATIN SMALL LETTER HV
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0068	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*COMPOSE            */	DEADTRANS(	0x0028	,0x0068	,0x2C76	,0x0000	), // LATIN SMALL LETTER HALF H
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0068	,0x02F9	,0x0000	), // MODIFIER LETTER BEGIN HIGH TONE
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0068	,0x02FA	,0x0000	), // MODIFIER LETTER END HIGH TONE
/*COMPOSE            */	DEADTRANS(	L'I'	,0x00A6	,0x0049	,0x0001	), // LATIN CAPITAL LETTER I
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0049	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0049	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'F'	,0x0049	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0049	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0049	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'J'	,0x0049	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x0049	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0049	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0049	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0049	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0049	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0049	,0x00B6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0049	,0xA76C	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	L's'	,0x0049	,0xA76C	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	0x00F9	,0x0049	,0xA78B	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x0027	,0x0049	,0xA78B	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0049	,0xA72C	,0x0000	), // LATIN CAPITAL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x2019	,0x0049	,0xA78B	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'i'	,0x00A6	,0x0069	,0x0001	), // LATIN SMALL LETTER I
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0069	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0069	,0x2300	,0x0000	), // DIAMETER SIGN
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0069	,0xAB61	,0x0000	), // LATIN SMALL LETTER IOTIFIED E
/*COMPOSE            */	DEADTRANS(	L'f'	,0x0069	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0069	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0069	,0x026A	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*COMPOSE            */	DEADTRANS(	L'J'	,0x0069	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x0069	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0069	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0069	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0069	,0x2282	,0x0000	), // SUBSET OF
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0069	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0069	,0x00B6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0069	,0x00B6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0069	,0xA76C	,0x0000	), // LATIN CAPITAL LETTER IS
/*COMPOSE            */	DEADTRANS(	L's'	,0x0069	,0xA76D	,0x0000	), // LATIN SMALL LETTER IS
/*COMPOSE            */	DEADTRANS(	0x00F9	,0x0069	,0xA78C	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x0027	,0x0069	,0xA78C	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0069	,0x2284	,0x0000	), // NOT A SUBSET OF
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0069	,0xA72D	,0x0000	), // LATIN SMALL LETTER CUATRILLO
/*COMPOSE            */	DEADTRANS(	0x2019	,0x0069	,0xA78C	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*COMPOSE            */	DEADTRANS(	L'J'	,0x00A6	,0x004A	,0x0001	), // LATIN CAPITAL LETTER J
/*COMPOSE            */	DEADTRANS(	L'j'	,0x00A6	,0x006A	,0x0001	), // LATIN SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'K'	,0x00A6	,0x004B	,0x0001	), // LATIN CAPITAL LETTER K
/*COMPOSE            */	DEADTRANS(	L'B'	,0x004B	,0x2328	,0x0000	), // KEYBOARD
/*COMPOSE            */	DEADTRANS(	L'k'	,0x00A6	,0x006B	,0x0001	), // LATIN SMALL LETTER K
/*COMPOSE            */	DEADTRANS(	L'b'	,0x006B	,0x2328	,0x0000	), // KEYBOARD
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006B	,0x0138	,0x0000	), // LATIN SMALL LETTER KRA
/*COMPOSE            */	DEADTRANS(	L'L'	,0x00A6	,0x004C	,0x0001	), // LATIN CAPITAL LETTER L
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004C	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'B'	,0x004C	,0xA7B4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'E'	,0x004C	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'G'	,0x004C	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'I'	,0x004C	,0x264C	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'J'	,0x004C	,0x01C7	,0x0000	), // LATIN CAPITAL LETTER LJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x004C	,0x01C8	,0x0000	), // LATIN CAPITAL LETTER L WITH SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004C	,0x1EFA	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'L'	,0x006C	,0x1EFA	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004C	,0xA7B6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004C	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'X'	,0x004C	,0xA7B3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x004C	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	0x0021	,0x004C	,0x01C1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*COMPOSE            */	DEADTRANS(	L'l'	,0x00A6	,0x006C	,0x0001	), // LATIN SMALL LETTER L
/*COMPOSE            */	DEADTRANS(	L'a'	,0x006C	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*COMPOSE            */	DEADTRANS(	L'b'	,0x006C	,0xA7B5	,0x0000	), // LATIN SMALL LETTER BETA
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006C	,0x2113	,0x0000	), // SCRIPT SMALL L
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006C	,0x1E9F	,0x0000	), // LATIN SMALL LETTER DELTA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x006C	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006C	,0xFB00	,0x0000	), // LATIN SMALL LIGATURE FF
/*COMPOSE            */	DEADTRANS(	L'g'	,0x006C	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006C	,0x264C	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'j'	,0x006C	,0x01C9	,0x0000	), // LATIN SMALL LETTER LJ
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004C	,0x1EFA	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006C	,0x1EFB	,0x0000	), // LATIN SMALL LETTER MIDDLE-WELSH LL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006C	,0xA7B7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L's'	,0x006C	,0x02AA	,0x0000	), // LATIN SMALL LETTER LS DIGRAPH
/*COMPOSE            */	DEADTRANS(	L't'	,0x006C	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006C	,0xA772	,0x0000	), // LATIN SMALL LETTER LUM
/*COMPOSE            */	DEADTRANS(	L'x'	,0x006C	,0xAB53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'y'	,0x006C	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'z'	,0x006C	,0x02AB	,0x0001	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x02AB	,0x026E	,0x0000	), // LATIN SMALL LETTER LEZH
/*COMPOSE            */	DEADTRANS(	0x0020	,0x02AB	,0x02AB	,0x0000	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x002E	,0x02AB	,0x02AB	,0x0000	), // LATIN SMALL LETTER LZ DIGRAPH
/*COMPOSE            */	DEADTRANS(	0x0021	,0x006C	,0x01C1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*COMPOSE            */	DEADTRANS(	0x0025	,0x006C	,0xAB37	,0x0000	), // LATIN SMALL LETTER L WITH INVERTED LAZY S
/*COMPOSE            */	DEADTRANS(	0x00B0	,0x006C	,0xAB58	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG AND LOW RIGHT RING
/*COMPOSE            */	DEADTRANS(	L'M'	,0x00A6	,0x004D	,0x0001	), // LATIN CAPITAL LETTER M
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004D	,0xA7FF	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'a'	,0x004D	,0xA7FF	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004D	,0xDD6A	,0x0000	), // U+1F16A; input D83C high surrogate first; RAISED MC SIGN
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004D	,0xDD6B	,0x0000	), // U+1F16B; input D83C high surrogate first; RAISED MD SIGN
/*COMPOSE            */	DEADTRANS(	L'M'	,0x004D	,0x2133	,0x0001	), // SCRIPT CAPITAL M
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004D	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004D	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'W'	,0x004D	,0xA7FF	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'm'	,0x00A6	,0x006D	,0x0001	), // LATIN SMALL LETTER M
/*COMPOSE            */	DEADTRANS(	L'A'	,0x006D	,0xA7FF	,0x0000	), // LATIN EPIGRAPHIC LETTER ARCHAIC M
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006D	,0xDD6A	,0x0000	), // U+1F16A; input D83C high surrogate first; RAISED MC SIGN
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006D	,0xDD6B	,0x0000	), // U+1F16B; input D83C high surrogate first; RAISED MD SIGN
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006D	,0x00B5	,0x0000	), // MICRO SIGN
/*COMPOSE            */	DEADTRANS(	L'm'	,0x006D	,0x2133	,0x0001	), // SCRIPT CAPITAL M
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006D	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L't'	,0x006D	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006D	,0xA773	,0x0000	), // LATIN SMALL LETTER MUM
/*COMPOSE            */	DEADTRANS(	L'N'	,0x00A6	,0x004E	,0x0001	), // LATIN CAPITAL LETTER N
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004E	,0x265E	,0x0000	), // BLACK CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004E	,0x265B	,0x0000	), // BLACK CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'F'	,0x004E	,0x265D	,0x0000	), // BLACK CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'G'	,0x004E	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'g'	,0x004E	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'J'	,0x004E	,0x01CA	,0x0000	), // LATIN CAPITAL LETTER NJ
/*COMPOSE            */	DEADTRANS(	L'j'	,0x004E	,0x01CB	,0x0000	), // LATIN CAPITAL LETTER N WITH SMALL LETTER J
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004E	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004E	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'N'	,0x004E	,0x2115	,0x0000	), // DOUBLE-STRUCK CAPITAL N
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004E	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x004E	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'P'	,0x004E	,0x265F	,0x0000	), // BLACK CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'R'	,0x004E	,0x265A	,0x0000	), // BLACK CHESS KING
/*COMPOSE            */	DEADTRANS(	L'T'	,0x004E	,0x265C	,0x0000	), // BLACK CHESS ROOK
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x004E	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'y'	,0x004E	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'n'	,0x00A6	,0x006E	,0x0001	), // LATIN SMALL LETTER N
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006E	,0x265E	,0x0000	), // BLACK CHESS KNIGHT
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006E	,0x265B	,0x0000	), // BLACK CHESS QUEEN
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006E	,0x265D	,0x0000	), // BLACK CHESS BISHOP
/*COMPOSE            */	DEADTRANS(	L'G'	,0x006E	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'g'	,0x006E	,0x014B	,0x0000	), // LATIN SMALL LETTER ENG
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006E	,0x2283	,0x0000	), // SUPERSET OF
/*COMPOSE            */	DEADTRANS(	L'j'	,0x006E	,0x01CC	,0x0000	), // LATIN SMALL LETTER NJ
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006E	,0x019E	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*COMPOSE            */	DEADTRANS(	L'n'	,0x006E	,0x2669	,0x0000	), // QUARTER NOTE
/*COMPOSE            */	DEADTRANS(	L'O'	,0x006E	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006E	,0x2116	,0x0000	), // NUMERO SIGN
/*COMPOSE            */	DEADTRANS(	L'p'	,0x006E	,0x265F	,0x0000	), // BLACK CHESS PAWN
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006E	,0x265A	,0x0000	), // BLACK CHESS KING
/*COMPOSE            */	DEADTRANS(	L't'	,0x006E	,0x265C	,0x0000	), // BLACK CHESS ROOK
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006E	,0xA774	,0x0000	), // LATIN SMALL LETTER NUM
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x006E	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'y'	,0x006E	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	0x002F	,0x006E	,0x2285	,0x0000	), // NOT A SUPERSET OF
/*COMPOSE            */	DEADTRANS(	L'O'	,0x00A6	,0x004F	,0x0001	), // LATIN CAPITAL LETTER O
/*COMPOSE            */	DEADTRANS(	L'A'	,0x004F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'a'	,0x004F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'C'	,0x004F	,0x00A9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'D'	,0x004F	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x004F	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x004F	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'F'	,0x004F	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'H'	,0x004F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'h'	,0x004F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'I'	,0x004F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x004F	,0xA7B6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x004F	,0xA7B6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'M'	,0x004F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x004F	,0xA74E	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x004F	,0xA74E	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'P'	,0x004F	,0x2117	,0x0000	), // SOUND RECORDING COPYRIGHT
/*COMPOSE            */	DEADTRANS(	L'R'	,0x004F	,0x00AE	,0x0000	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	L'U'	,0x004F	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x004F	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'3'	,0x004F	,0xA79C	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK OE
/*COMPOSE            */	DEADTRANS(	0x005F	,0x004F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	0x0186	,0x004F	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x00A6	,0x006F	,0x0001	), // LATIN SMALL LETTER O
/*COMPOSE            */	DEADTRANS(	L'A'	,0x006F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'a'	,0x006F	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'c'	,0x006F	,0x00A9	,0x0000	), // COPYRIGHT SIGN
/*COMPOSE            */	DEADTRANS(	L'd'	,0x006F	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x006F	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'e'	,0x006F	,0x0153	,0x0000	), // LATIN SMALL LIGATURE OE
/*COMPOSE            */	DEADTRANS(	L'f'	,0x006F	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'H'	,0x006F	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'h'	,0x006F	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*COMPOSE            */	DEADTRANS(	L'i'	,0x006F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'L'	,0x006F	,0xA7B7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'l'	,0x006F	,0xA7B7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x006F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	L'O'	,0x006F	,0xA74E	,0x0000	), // LATIN CAPITAL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'o'	,0x006F	,0xA74F	,0x0000	), // LATIN SMALL LETTER OO
/*COMPOSE            */	DEADTRANS(	L'p'	,0x006F	,0x2117	,0x0000	), // SOUND RECORDING COPYRIGHT
/*COMPOSE            */	DEADTRANS(	L'r'	,0x006F	,0x00AE	,0x0000	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	L'U'	,0x006F	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*COMPOSE            */	DEADTRANS(	L'u'	,0x006F	,0x0223	,0x0000	), // LATIN SMALL LETTER OU
/*COMPOSE            */	DEADTRANS(	0x0028	,0x006F	,0x1D16	,0x0000	), // LATIN SMALL LETTER TOP HALF O
/*COMPOSE            */	DEADTRANS(	0x0029	,0x006F	,0x1D17	,0x0000	), // LATIN SMALL LETTER BOTTOM HALF O
/*COMPOSE            */	DEADTRANS(	L'3'	,0x006F	,0xA79D	,0x0000	), // LATIN SMALL LETTER VOLAPUK OE
/*COMPOSE            */	DEADTRANS(	0x005F	,0x006F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*COMPOSE            */	DEADTRANS(	0x0254	,0x006F	,0xDD2F	,0x0000	), // U+1F12F; input D83C high surrogate first; COPYLEFT SYMBOL
/*COMPOSE            */	DEADTRANS(	L'P'	,0x00A6	,0x0050	,0x0000	), // LATIN CAPITAL LETTER P
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0050	,0x00B6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0050	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0050	,0x2119	,0x0000	), // DOUBLE-STRUCK CAPITAL P
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0050	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'p'	,0x00A6	,0x0070	,0x0001	), // LATIN SMALL LETTER P
/*COMPOSE            */	DEADTRANS(	L'g'	,0x0070	,0x0264	,0x0000	), // LATIN SMALL LETTER RAMS HORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0070	,0x0278	,0x0000	), // LATIN SMALL LETTER PHI
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0070	,0x00B6	,0x0000	), // PILCROW SIGN
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0070	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0070	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x00A6	,0x0051	,0x0001	), // LATIN CAPITAL LETTER Q
/*COMPOSE            */	DEADTRANS(	L'Q'	,0x0051	,0x211A	,0x0000	), // DOUBLE-STRUCK CAPITAL Q
/*COMPOSE            */	DEADTRANS(	L'q'	,0x00A6	,0x0071	,0x0001	), // LATIN SMALL LETTER Q
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0071	,0x0239	,0x0000	), // LATIN SMALL LETTER QP DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'R'	,0x00A6	,0x0052	,0x0001	), // LATIN CAPITAL LETTER R
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0052	,0x211D	,0x0000	), // DOUBLE-STRUCK CAPITAL R
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0052	,0x01C3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*COMPOSE            */	DEADTRANS(	L'r'	,0x00A6	,0x0072	,0x0001	), // LATIN SMALL LETTER R
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0072	,0x027C	,0x0000	), // LATIN SMALL LETTER R WITH LONG LEG
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0072	,0xAB48	,0x0000	), // LATIN SMALL LETTER DOUBLE R
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0072	,0xA775	,0x0000	), // LATIN SMALL LETTER RUM
/*COMPOSE            */	DEADTRANS(	0x00E9	,0x0072	,0xAB45	,0x0000	), // LATIN SMALL LETTER STIRRUP R
/*COMPOSE            */	DEADTRANS(	0x0021	,0x0072	,0x01C3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*COMPOSE            */	DEADTRANS(	L'S'	,0x00A6	,0x0053	,0x0001	), // LATIN CAPITAL LETTER S
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0053	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'C'	,0x0053	,0x264F	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0053	,0x212E	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0053	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0053	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0053	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x0053	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0053	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0053	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x00A6	,0x0073	,0x0001	), // LATIN SMALL LETTER S
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0073	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0073	,0x264F	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0073	,0x212E	,0x0000	), // ESTIMATED SYMBOL
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0073	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0073	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0073	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0073	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L's'	,0x0073	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L't'	,0x0073	,0xFB06	,0x0000	), // LATIN SMALL LIGATURE ST
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0073	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0073	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	0x002E	,0x0073	,0xA78F	,0x0000	), // LATIN LETTER SINOLOGICAL DOT
/*COMPOSE            */	DEADTRANS(	L'0'	,0x0073	,0x2648	,0x0001	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'1'	,0x2648	,0x2648	,0x0000	), // ARIES
/*COMPOSE            */	DEADTRANS(	L'2'	,0x2648	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'3'	,0x2648	,0x264A	,0x0000	), // GEMINI
/*COMPOSE            */	DEADTRANS(	L'4'	,0x2648	,0x264B	,0x0000	), // CANCER
/*COMPOSE            */	DEADTRANS(	L'5'	,0x2648	,0x264C	,0x0000	), // LEO
/*COMPOSE            */	DEADTRANS(	L'6'	,0x2648	,0x264D	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'7'	,0x2648	,0x264E	,0x0000	), // LIBRA
/*COMPOSE            */	DEADTRANS(	L'8'	,0x2648	,0x264F	,0x0000	), // SCORPIUS
/*COMPOSE            */	DEADTRANS(	L'9'	,0x2648	,0x2650	,0x0000	), // SAGITTARIUS
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0073	,0x2651	,0x0001	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'0'	,0x2651	,0x2651	,0x0000	), // CAPRICORN
/*COMPOSE            */	DEADTRANS(	L'1'	,0x2651	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'2'	,0x2651	,0x2653	,0x0000	), // PISCES
/*COMPOSE            */	DEADTRANS(	0x007C	,0x0073	,0xFB05	,0x0000	), // LATIN SMALL LIGATURE LONG S T
/*COMPOSE            */	DEADTRANS(	L'T'	,0x00A6	,0x0054	,0x0001	), // LATIN CAPITAL LETTER T
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0054	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'D'	,0x0054	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0054	,0x204A	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0054	,0x00DE	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0054	,0x00DE	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0054	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0054	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0054	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0054	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0054	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0054	,0xA728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0054	,0xA728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0054	,0x02D4	,0x0000	), // MODIFIER LETTER UP TACK
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0054	,0x01A7	,0x0000	), // LATIN CAPITAL LETTER TONE TWO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0054	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0054	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0054	,0x01BC	,0x0000	), // LATIN CAPITAL LETTER TONE FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0054	,0x0184	,0x0000	), // LATIN CAPITAL LETTER TONE SIX
/*COMPOSE            */	DEADTRANS(	0x005C	,0x0054	,0x02D5	,0x0000	), // MODIFIER LETTER DOWN TACK
/*COMPOSE            */	DEADTRANS(	L't'	,0x00A6	,0x0074	,0x0001	), // LATIN SMALL LETTER T
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0074	,0x2649	,0x0000	), // TAURUS
/*COMPOSE            */	DEADTRANS(	L'c'	,0x0074	,0x02A7	,0x0000	), // LATIN SMALL LETTER TESH DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'd'	,0x0074	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0074	,0x204A	,0x0000	), // TIRONIAN SIGN ET
/*COMPOSE            */	DEADTRANS(	L'H'	,0x0074	,0x00DE	,0x0000	), // LATIN CAPITAL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'h'	,0x0074	,0x00FE	,0x0000	), // LATIN SMALL LETTER THORN
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0074	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0074	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0074	,0x2122	,0x0000	), // TRADE MARK SIGN
/*COMPOSE            */	DEADTRANS(	L's'	,0x0074	,0x02A6	,0x0000	), // LATIN SMALL LETTER TS DIGRAPH
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0074	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*COMPOSE            */	DEADTRANS(	L't'	,0x0074	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0074	,0xA777	,0x0000	), // LATIN SMALL LETTER TUM
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x0074	,0xA728	,0x0000	), // LATIN CAPITAL LETTER TZ
/*COMPOSE            */	DEADTRANS(	L'z'	,0x0074	,0xA729	,0x0000	), // LATIN SMALL LETTER TZ
/*COMPOSE            */	DEADTRANS(	0x002D	,0x0074	,0x01BE	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0074	,0x02D4	,0x0000	), // MODIFIER LETTER UP TACK
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0074	,0x01A8	,0x0000	), // LATIN SMALL LETTER TONE TWO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0074	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0074	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0074	,0x01BD	,0x0000	), // LATIN SMALL LETTER TONE FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0074	,0x0185	,0x0000	), // LATIN SMALL LETTER TONE SIX
/*COMPOSE            */	DEADTRANS(	0x005C	,0x0074	,0x02D5	,0x0000	), // MODIFIER LETTER DOWN TACK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0055	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0055	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0055	,0xA79E	,0x0000	), // LATIN CAPITAL LETTER VOLAPUK UE
/*COMPOSE            */	DEADTRANS(	L'u'	,0x00A6	,0x0075	,0x0001	), // LATIN SMALL LETTER U
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0075	,0x1D6B	,0x0000	), // LATIN SMALL LETTER UE
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0075	,0xAB50	,0x0000	), // LATIN SMALL LETTER UI
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0075	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0075	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0075	,0xA778	,0x0000	), // LATIN SMALL LETTER UM
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0075	,0xAB63	,0x0000	), // LATIN SMALL LETTER UO
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0075	,0xA79F	,0x0000	), // LATIN SMALL LETTER VOLAPUK UE
/*COMPOSE            */	DEADTRANS(	L'V'	,0x00A6	,0x0056	,0x0001	), // LATIN CAPITAL LETTER V
/*COMPOSE            */	DEADTRANS(	L'E'	,0x0056	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0056	,0x264D	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0056	,0xA768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0056	,0xA768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L't'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0056	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0056	,0xA760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0056	,0xA760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	0x002E	,0x0056	,0x02D1	,0x0000	), // MODIFIER LETTER HALF TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x003A	,0x0056	,0x02D0	,0x0000	), // MODIFIER LETTER TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0056	,0xDDF9	,0x0000	), // U+1F5F9; input D83D high surrogate first; BALLOT BOX WITH BOLD CHECK
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0056	,0xDDF9	,0x0000	), // U+1F5F9; input D83D high surrogate first; BALLOT BOX WITH BOLD CHECK
/*COMPOSE            */	DEADTRANS(	L'v'	,0x00A6	,0x0076	,0x0001	), // LATIN SMALL LETTER V
/*COMPOSE            */	DEADTRANS(	L'e'	,0x0076	,0x2652	,0x0000	), // AQUARIUS
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0076	,0x264D	,0x0000	), // VIRGO
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0076	,0xA768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0076	,0xA769	,0x0000	), // LATIN SMALL LETTER VEND
/*COMPOSE            */	DEADTRANS(	L'T'	,0x0076	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L't'	,0x0076	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0076	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0076	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0076	,0xA760	,0x0000	), // LATIN CAPITAL LETTER VY
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0076	,0xA761	,0x0000	), // LATIN SMALL LETTER VY
/*COMPOSE            */	DEADTRANS(	0x002E	,0x0076	,0x02D1	,0x0000	), // MODIFIER LETTER HALF TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x003A	,0x0076	,0x02D0	,0x0000	), // MODIFIER LETTER TRIANGULAR COLON
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0076	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0076	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*COMPOSE            */	DEADTRANS(	L'W'	,0x00A6	,0x0057	,0x0001	), // LATIN CAPITAL LETTER W
/*COMPOSE            */	DEADTRANS(	L'W'	,0x0057	,0x02AC	,0x0000	), // LATIN LETTER BILABIAL PERCUSSIVE
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0057	,0x01F7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0057	,0x01F7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'w'	,0x00A6	,0x0077	,0x0001	), // LATIN SMALL LETTER W
/*COMPOSE            */	DEADTRANS(	L'w'	,0x0077	,0x02AC	,0x0000	), // LATIN LETTER BILABIAL PERCUSSIVE
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x0077	,0x01F7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*COMPOSE            */	DEADTRANS(	L'y'	,0x0077	,0x01BF	,0x0000	), // LATIN LETTER WYNN
/*COMPOSE            */	DEADTRANS(	0x007C	,0x0077	,0x2307	,0x0000	), // WAVY LINE
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0058	,0xA7B3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0058	,0xA7B3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'X'	,0x0058	,0x00D7	,0x0000	), // MULTIPLICATION SIGN
/*COMPOSE            */	DEADTRANS(	0x003A	,0x0058	,0x203B	,0x0000	), // REFERENCE MARK
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0058	,0xDDF7	,0x0000	), // U+1F5F7; input D83D high surrogate first; BALLOT BOX WITH BOLD SCRIPT X
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0058	,0xDDF7	,0x0000	), // U+1F5F7; input D83D high surrogate first; BALLOT BOX WITH BOLD SCRIPT X
/*COMPOSE            */	DEADTRANS(	L'x'	,0x00A6	,0x0078	,0x0001	), // LATIN SMALL LETTER X
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0078	,0xAB53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0078	,0xAB53	,0x0000	), // LATIN SMALL LETTER CHI
/*COMPOSE            */	DEADTRANS(	L'x'	,0x0078	,0x00D7	,0x0000	), // MULTIPLICATION SIGN
/*COMPOSE            */	DEADTRANS(	0x003A	,0x0078	,0x203B	,0x0000	), // REFERENCE MARK
/*COMPOSE            */	DEADTRANS(	0x005B	,0x0078	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*COMPOSE            */	DEADTRANS(	0x2610	,0x0078	,0x2612	,0x0000	), // BALLOT BOX WITH X
/*COMPOSE            */	DEADTRANS(	L'Y'	,0x00A6	,0x0059	,0x0001	), // LATIN CAPITAL LETTER Y
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0059	,0x02EB	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0059	,0x02EB	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0059	,0x02EA	,0x0000	), // MODIFIER LETTER YIN DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0059	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0059	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'N'	,0x0059	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0059	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0059	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0059	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0059	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0059	,0x01A6	,0x0000	), // LATIN LETTER YR
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0059	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L's'	,0x0059	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L'y'	,0x00A6	,0x0079	,0x0001	), // LATIN SMALL LETTER Y
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0079	,0x02EB	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0079	,0x02EB	,0x0001	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'n'	,0x02EB	,0x02EB	,0x0000	), // MODIFIER LETTER YANG DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L't'	,0x02EB	,0xAB60	,0x0000	), // LATIN SMALL LETTER SAKHA YAT
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0079	,0x02EA	,0x0000	), // MODIFIER LETTER YIN DEPARTING TONE MARK
/*COMPOSE            */	DEADTRANS(	L'L'	,0x0079	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'l'	,0x0079	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0079	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*COMPOSE            */	DEADTRANS(	L'O'	,0x0079	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'o'	,0x0079	,0x021D	,0x0000	), // LATIN SMALL LETTER YOGH
/*COMPOSE            */	DEADTRANS(	L'P'	,0x0079	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'p'	,0x0079	,0xA700	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN PING
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0079	,0x01A6	,0x0000	), // LATIN LETTER YR
/*COMPOSE            */	DEADTRANS(	L'S'	,0x0079	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L's'	,0x0079	,0xA702	,0x0000	), // MODIFIER LETTER CHINESE TONE YIN SHANG
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x00A6	,0x005A	,0x0001	), // LATIN CAPITAL LETTER Z
/*COMPOSE            */	DEADTRANS(	L'H'	,0x005A	,0x01B7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x005A	,0x01B7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'S'	,0x005A	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	L'Z'	,0x005A	,0x2124	,0x0000	), // DOUBLE-STRUCK CAPITAL Z
/*COMPOSE            */	DEADTRANS(	L'z'	,0x00A6	,0x007A	,0x0001	), // LATIN SMALL LETTER Z
/*COMPOSE            */	DEADTRANS(	L'H'	,0x007A	,0x01B7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L'h'	,0x007A	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*COMPOSE            */	DEADTRANS(	L's'	,0x007A	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*COMPOSE            */	DEADTRANS(	0x00E8	,0x020F	,0x1ABE	,0x0000	), // COMBINING PARENTHESES OVERLAY
/*COMPOSE            */	DEADTRANS(	0x00E9	,0x020F	,0x1ABB	,0x0000	), // COMBINING PARENTHESES ABOVE
/*COMPOSE            */	DEADTRANS(	0x00F9	,0x020F	,0x1ABB	,0x0000	), // COMBINING PARENTHESES ABOVE
/*COMPOSE            */	DEADTRANS(	0x0020	,0x00A6	,0x005F	,0x0001	), // LOW LINE
/*COMPOSE            */	DEADTRANS(	0x0021	,0x00A6	,0x1E05	,0x0001	), // LATIN SMALL LETTER B WITH DOT BELOW
/*COMPOSE            */	DEADTRANS(	0x0022	,0x00A6	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*COMPOSE            */	DEADTRANS(	0x0023	,0x00A6	,0x0250	,0x0001	), // LATIN SMALL LETTER TURNED A
/*COMPOSE            */	DEADTRANS(	0x0025	,0x00A6	,0x0281	,0x0001	), // LATIN LETTER SMALL CAPITAL INVERTED R
/*COMPOSE            */	DEADTRANS(	0x0026	,0x00A6	,0x0221	,0x0001	), // LATIN SMALL LETTER D WITH CURL
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00A6	,0x00E1	,0x0001	), // LATIN SMALL LETTER A WITH ACUTE
/*COMPOSE            */	DEADTRANS(	0x0028	,0x00A6	,0x0213	,0x0001	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*COMPOSE            */	DEADTRANS(	0x0029	,0x00A6	,0x014F	,0x0001	), // LATIN SMALL LETTER O WITH BREVE
/*COMPOSE            */	DEADTRANS(	0x002A	,0x00A6	,0x002A	,0x0001	), // ASTERISK
/*COMPOSE            */	DEADTRANS(	0x002B	,0x00A6	,0x002B	,0x0001	), // PLUS SIGN
/*COMPOSE            */	DEADTRANS(	0x002C	,0x00A6	,0x0229	,0x0001	), // LATIN SMALL LETTER E WITH CEDILLA
/*COMPOSE            */	DEADTRANS(	0x002D	,0x00A6	,0x024D	,0x0001	), // LATIN SMALL LETTER R WITH STROKE
/*COMPOSE            */	DEADTRANS(	0x002E	,0x00A6	,0x1E57	,0x0001	), // LATIN SMALL LETTER P WITH DOT ABOVE
/*COMPOSE            */	DEADTRANS(	0x002F	,0x00A6	,0x00F8	,0x0001	), // LATIN SMALL LETTER O WITH STROKE
/*COMPOSE            */	DEADTRANS(	L'0'	,0x00A6	,0x2189	,0x0000	), // VULGAR FRACTION ZERO THIRDS
/*COMPOSE            */	DEADTRANS(	L'1'	,0x00A6	,0x0031	,0x0001	), // DIGIT ONE
/*COMPOSE            */	DEADTRANS(	0x002F	,0x0031	,0x215F	,0x0000	), // FRACTION NUMERATOR ONE
/*COMPOSE            */	DEADTRANS(	L'1'	,0x0031	,0x2152	,0x0000	), // VULGAR FRACTION ONE TENTH
/*COMPOSE            */	DEADTRANS(	L'2'	,0x0031	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0031	,0x2153	,0x0000	), // VULGAR FRACTION ONE THIRD
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0031	,0x00BC	,0x0000	), // VULGAR FRACTION ONE QUARTER
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0031	,0x2155	,0x0000	), // VULGAR FRACTION ONE FIFTH
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0031	,0x2159	,0x0000	), // VULGAR FRACTION ONE SIXTH
/*COMPOSE            */	DEADTRANS(	L'7'	,0x0031	,0x2150	,0x0000	), // VULGAR FRACTION ONE SEVENTH
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0031	,0x215B	,0x0000	), // VULGAR FRACTION ONE EIGHTH
/*COMPOSE            */	DEADTRANS(	L'9'	,0x0031	,0x2151	,0x0000	), // VULGAR FRACTION ONE NINTH
/*COMPOSE            */	DEADTRANS(	L'2'	,0x00A6	,0x0032	,0x0001	), // DIGIT TWO
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0032	,0x221A	,0x0000	), // SQUARE ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0032	,0x221A	,0x0000	), // SQUARE ROOT
/*COMPOSE            */	DEADTRANS(	L'3'	,0x0032	,0x2154	,0x0000	), // VULGAR FRACTION TWO THIRDS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0032	,0x2156	,0x0000	), // VULGAR FRACTION TWO FIFTHS
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0032	,0x226A	,0x0000	), // MUCH LESS-THAN
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0032	,0x226B	,0x0000	), // MUCH GREATER-THAN
/*COMPOSE            */	DEADTRANS(	L'3'	,0x00A6	,0x0033	,0x0001	), // DIGIT THREE
/*COMPOSE            */	DEADTRANS(	L'A'	,0x0033	,0xA722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*COMPOSE            */	DEADTRANS(	L'a'	,0x0033	,0xA723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0033	,0x221B	,0x0000	), // CUBE ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0033	,0x221B	,0x0000	), // CUBE ROOT
/*COMPOSE            */	DEADTRANS(	L'4'	,0x0033	,0x00BE	,0x0000	), // VULGAR FRACTION THREE QUARTERS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0033	,0x2157	,0x0000	), // VULGAR FRACTION THREE FIFTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0033	,0x215C	,0x0000	), // VULGAR FRACTION THREE EIGHTHS
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0033	,0x22D8	,0x0000	), // VERY MUCH LESS-THAN
/*COMPOSE            */	DEADTRANS(	0x003E	,0x0033	,0x22D9	,0x0000	), // VERY MUCH GREATER-THAN
/*COMPOSE            */	DEADTRANS(	L'4'	,0x00A6	,0x0034	,0x0001	), // DIGIT FOUR
/*COMPOSE            */	DEADTRANS(	L'V'	,0x0034	,0x221C	,0x0000	), // FOURTH ROOT
/*COMPOSE            */	DEADTRANS(	L'v'	,0x0034	,0x221C	,0x0000	), // FOURTH ROOT
/*COMPOSE            */	DEADTRANS(	L'5'	,0x0034	,0x2158	,0x0000	), // VULGAR FRACTION FOUR FIFTHS
/*COMPOSE            */	DEADTRANS(	L'5'	,0x00A6	,0x0035	,0x0001	), // DIGIT FIVE
/*COMPOSE            */	DEADTRANS(	L'6'	,0x0035	,0x215A	,0x0000	), // VULGAR FRACTION FIVE SIXTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0035	,0x215D	,0x0000	), // VULGAR FRACTION FIVE EIGHTHS
/*COMPOSE            */	DEADTRANS(	L'6'	,0x00A6	,0x007C	,0x0001	), // VERTICAL LINE
/*COMPOSE            */	DEADTRANS(	L'7'	,0x00A6	,0x0037	,0x0001	), // DIGIT SEVEN
/*COMPOSE            */	DEADTRANS(	L'I'	,0x0037	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'i'	,0x0037	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'M'	,0x0037	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'm'	,0x0037	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'R'	,0x0037	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*COMPOSE            */	DEADTRANS(	L'r'	,0x0037	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*COMPOSE            */	DEADTRANS(	L'U'	,0x0037	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'u'	,0x0037	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*COMPOSE            */	DEADTRANS(	L'8'	,0x0037	,0x215E	,0x0000	), // VULGAR FRACTION SEVEN EIGHTHS
/*COMPOSE            */	DEADTRANS(	L'8'	,0x00A6	,0x0038	,0x0001	), // DIGIT EIGHT
/*COMPOSE            */	DEADTRANS(	0x003C	,0x0038	,0x2702	,0x0001	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'A'	,0x2702	,0x2700	,0x0000	), // BLACK SAFETY SCISSORS
/*COMPOSE            */	DEADTRANS(	L'a'	,0x2702	,0x2700	,0x0000	), // BLACK SAFETY SCISSORS
/*COMPOSE            */	DEADTRANS(	L'B'	,0x2702	,0x2704	,0x0000	), // WHITE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'b'	,0x2702	,0x2704	,0x0000	), // WHITE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'I'	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'i'	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L'N'	,0x2702	,0x2702	,0x0000	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'n'	,0x2702	,0x2702	,0x0000	), // BLACK SCISSORS
/*COMPOSE            */	DEADTRANS(	L'S'	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	L's'	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x002F	,0x2702	,0x2701	,0x0000	), // UPPER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x005C	,0x2702	,0x2703	,0x0000	), // LOWER BLADE SCISSORS
/*COMPOSE            */	DEADTRANS(	0x003A	,0x00A6	,0x00EB	,0x0001	), // LATIN SMALL LETTER E WITH DIAERESIS
/*COMPOSE            */	DEADTRANS(	0x003B	,0x00A6	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*COMPOSE            */	DEADTRANS(	0x003C	,0x00A6	,0x00EA	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX
/*COMPOSE            */	DEADTRANS(	0x003D	,0x00A6	,0x003D	,0x0001	), // EQUALS SIGN
/*COMPOSE            */	DEADTRANS(	0x003E	,0x00A6	,0x021F	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*COMPOSE            */	DEADTRANS(	0x003F	,0x00A6	,0x003F	,0x0001	), // QUESTION MARK
/*COMPOSE            */	DEADTRANS(	0x2B06	,0x00A6	,0x005E	,0x0001	), // CIRCUMFLEX ACCENT
/*COMPOSE            */	DEADTRANS(	0x0021	,0x003F	,0x2048	,0x0000	), // QUESTION EXCLAMATION MARK
/*COMPOSE            */	DEADTRANS(	0x0025	,0x003F	,0x1D24	,0x0000	), // LATIN LETTER VOICED LARYNGEAL SPIRANT
/*COMPOSE            */	DEADTRANS(	0x002B	,0x003F	,0x203D	,0x0000	), // INTERROBANG
/*COMPOSE            */	DEADTRANS(	0x002E	,0x003F	,0x203D	,0x0000	), // INTERROBANG
/*COMPOSE            */	DEADTRANS(	0x003F	,0x003F	,0x2047	,0x0000	), // DOUBLE QUESTION MARK
/*COMPOSE            */	DEADTRANS(	0x0040	,0x00A6	,0x25EF	,0x0001	), // LARGE CIRCLE
/*COMPOSE            */	DEADTRANS(	0x005B	,0x00A6	,0x01EB	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK
/*COMPOSE            */	DEADTRANS(	0x005C	,0x00A6	,0x1D19	,0x0001	), // LATIN LETTER SMALL CAPITAL REVERSED R
/*COMPOSE            */	DEADTRANS(	0x005D	,0x00A6	,0x1EBB	,0x0001	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*COMPOSE            */	DEADTRANS(	0x005E	,0x00A6	,0x005E	,0x0001	), // CIRCUMFLEX ACCENT
/*COMPOSE            */	DEADTRANS(	0x0060	,0x00A6	,0x00F2	,0x0001	), // LATIN SMALL LETTER O WITH GRAVE
/*COMPOSE            */	DEADTRANS(	0x007B	,0x00A6	,0x0273	,0x0001	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*COMPOSE            */	DEADTRANS(	0x007C	,0x00A6	,0x0101	,0x0001	), // LATIN SMALL LETTER A WITH MACRON
/*COMPOSE            */	DEADTRANS(	0x007D	,0x00A6	,0x0192	,0x0001	), // LATIN SMALL LETTER F WITH HOOK
/*COMPOSE            */	DEADTRANS(	0x007E	,0x00A6	,0x00F5	,0x0001	), // LATIN SMALL LETTER O WITH TILDE
/*COMPOSE            */	DEADTRANS(	0x20AC	,0x00A6	,0x00A4	,0x0001	), // CURRENCY SIGN
/*COMPOSE            */	DEADTRANS(	0x00A4	,0x00A6	,0x1D79	,0x0001	), // LATIN SMALL LETTER INSULAR G
/*COMPOSE            */	DEADTRANS(	0x00A9	,0x00A6	,0x00AE	,0x0001	), // REGISTERED SIGN
/*COMPOSE            */	DEADTRANS(	0x00B0	,0x00A6	,0x00E5	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE
/*COMPOSE            */	DEADTRANS(	0x00B5	,0x00A6	,0x03A9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*COMPOSE            */	DEADTRANS(	0x00F9	,0x03B5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x03B5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x03B5	,0x0313	,0x0000	), // COMBINING COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00EA	,0x00A6	,0x2191	,0x0001	), // UPWARDS ARROW
/*COMPOSE            */	DEADTRANS(	0x00EB	,0x00A6	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*COMPOSE            */	DEADTRANS(	0x002E	,0x2193	,0x1AB4	,0x0000	), // COMBINING TRIPLE DOT
/*COMPOSE            */	DEADTRANS(	0x003A	,0x2193	,0x205A	,0x0000	), // TWO DOT PUNCTUATION
/*COMPOSE            */	DEADTRANS(	0x00EB	,0x2193	,0x205B	,0x0000	), // FOUR DOT MARK
/*COMPOSE            */	DEADTRANS(	0x00F2	,0x00A6	,0x00D2	,0x0001	), // LATIN CAPITAL LETTER O WITH GRAVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00D2	,0x0312	,0x0000	), // COMBINING TURNED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00D2	,0x0312	,0x0000	), // COMBINING TURNED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00F5	,0x00A6	,0x00D5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*COMPOSE            */	DEADTRANS(	0x00F9	,0x00D5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x0027	,0x00D5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x00A3	,0x00D5	,0x1E1B	,0x0001	), // LATIN SMALL LETTER E WITH TILDE BELOW
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00D5	,0x0314	,0x0000	), // COMBINING REVERSED COMMA ABOVE
/*COMPOSE            */	DEADTRANS(	0x02BC	,0x00A6	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	0x2019	,0x00A6	,0x0149	,0x0001	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	L'n'	,0x0149	,0x0149	,0x0000	), // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*COMPOSE            */	DEADTRANS(	0x2610	,0x00A6	,0x2610	,0x0001	), // BALLOT BOX
/*COMPOSE            */	DEADTRANS(	L'O'	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	L'o'	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*COMPOSE            */	DEADTRANS(	0x0040	,0x2610	,0x2384	,0x0000	), // COMPOSITION SYMBOL
/*CROSSED_TAIL       */	DEADTRANS(	L'g'	,0xAB3A	,0xAB36	,0x0000	), // LATIN SMALL LETTER SCRIPT G WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'J'	,0xAB3A	,0xA7B2	,0x0000	), // LATIN CAPITAL LETTER J WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'j'	,0xAB3A	,0x029D	,0x0000	), // LATIN SMALL LETTER J WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'm'	,0xAB3A	,0xAB3A	,0x0000	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'n'	,0xAB3A	,0xAB3B	,0x0000	), // LATIN SMALL LETTER N WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	L'r'	,0xAB3A	,0xAB49	,0x0000	), // LATIN SMALL LETTER R WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	0x003D	,0xAB3A	,0xAB4A	,0x0000	), // LATIN SMALL LETTER DOUBLE R WITH CROSSED-TAIL
/*CROSSED_TAIL       */	DEADTRANS(	0x00A9	,0xAB3A	,0xAB3C	,0x0000	), // LATIN SMALL LETTER ENG WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'a'	,0x0221	,0x1D25	,0x0000	), // LATIN LETTER AIN
/*CURL               */	DEADTRANS(	L'c'	,0x0221	,0x0255	,0x0000	), // LATIN SMALL LETTER C WITH CURL
/*CURL               */	DEADTRANS(	L'd'	,0x0221	,0x0221	,0x0000	), // LATIN SMALL LETTER D WITH CURL
/*CURL               */	DEADTRANS(	L'g'	,0x0221	,0xAB36	,0x0000	), // LATIN SMALL LETTER SCRIPT G WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'J'	,0x0221	,0xA7B2	,0x0000	), // LATIN CAPITAL LETTER J WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'j'	,0x0221	,0x029D	,0x0000	), // LATIN SMALL LETTER J WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'l'	,0x0221	,0x0234	,0x0000	), // LATIN SMALL LETTER L WITH CURL
/*CURL               */	DEADTRANS(	L'n'	,0x0221	,0x0235	,0x0000	), // LATIN SMALL LETTER N WITH CURL
/*CURL               */	DEADTRANS(	L'O'	,0x0221	,0xA74C	,0x0000	), // LATIN CAPITAL LETTER O WITH LOOP
/*CURL               */	DEADTRANS(	L'o'	,0x0221	,0xA74D	,0x0000	), // LATIN SMALL LETTER O WITH LOOP
/*CURL               */	DEADTRANS(	L's'	,0x0221	,0x0286	,0x0000	), // LATIN SMALL LETTER ESH WITH CURL
/*CURL               */	DEADTRANS(	L't'	,0x0221	,0x0236	,0x0000	), // LATIN SMALL LETTER T WITH CURL
/*CURL               */	DEADTRANS(	L'v'	,0x0221	,0x2C74	,0x0000	), // LATIN SMALL LETTER V WITH CURL
/*CURL               */	DEADTRANS(	L'X'	,0x0221	,0xAB3A	,0x0001	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'x'	,0x0221	,0xAB3A	,0x0001	), // LATIN SMALL LETTER M WITH CROSSED-TAIL
/*CURL               */	DEADTRANS(	L'Y'	,0x0221	,0x1EFE	,0x0000	), // LATIN CAPITAL LETTER Y WITH LOOP
/*CURL               */	DEADTRANS(	L'y'	,0x0221	,0x1EFF	,0x0000	), // LATIN SMALL LETTER Y WITH LOOP
/*CURL               */	DEADTRANS(	L'z'	,0x0221	,0x0291	,0x0000	), // LATIN SMALL LETTER Z WITH CURL
/*CURL               */	DEADTRANS(	0x0026	,0x0221	,0x2113	,0x0001	), // SCRIPT SMALL L
/*CURL               */	DEADTRANS(	0x002E	,0x0221	,0x2055	,0x0000	), // FLOWER PUNCTUATION MARK
/*CURL               */	DEADTRANS(	0x007C	,0x0221	,0x2055	,0x0001	), // FLOWER PUNCTUATION MARK
/*CURL               */	DEADTRANS(	L'A'	,0x2055	,0xA724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*CURL               */	DEADTRANS(	L'a'	,0x2055	,0xA725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*CURL               */	DEADTRANS(	0x00A9	,0x0221	,0x0255	,0x0001	), // LATIN SMALL LETTER C WITH CURL
/*CURL               */	DEADTRANS(	L'd'	,0x0255	,0x02A5	,0x0000	), // LATIN SMALL LETTER DZ DIGRAPH WITH CURL
/*CURL               */	DEADTRANS(	L's'	,0x0255	,0x0286	,0x0000	), // LATIN SMALL LETTER ESH WITH CURL
/*CURL               */	DEADTRANS(	L't'	,0x0255	,0x02A8	,0x0000	), // LATIN SMALL LETTER TC DIGRAPH WITH CURL
/*CURL               */	DEADTRANS(	L'z'	,0x0255	,0x0293	,0x0000	), // LATIN SMALL LETTER EZH WITH CURL
/*CURRENCY           */	DEADTRANS(	0x0020	,0x00A4	,0x00A4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	0x202F	,0x00A4	,0x00A4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'A'	,0x00A4	,0x20B3	,0x0000	), // AUSTRAL SIGN
/*CURRENCY           */	DEADTRANS(	L'a'	,0x00A4	,0x060B	,0x0000	), // AFGHANI SIGN
/*CURRENCY           */	DEADTRANS(	L'B'	,0x00A4	,0x0E3F	,0x0000	), // THAI CURRENCY SYMBOL BAHT
/*CURRENCY           */	DEADTRANS(	L'b'	,0x00A4	,0x20BF	,0x0000	), // BITCOIN SIGN
/*CURRENCY           */	DEADTRANS(	L'C'	,0x00A4	,0x20B5	,0x0000	), // CEDI SIGN
/*CURRENCY           */	DEADTRANS(	L'c'	,0x00A4	,0x00A2	,0x0001	), // CENT SIGN
/*CURRENCY           */	DEADTRANS(	L'e'	,0x00A2	,0x20B5	,0x0000	), // CEDI SIGN
/*CURRENCY           */	DEADTRANS(	L'o'	,0x00A2	,0x20A1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x00A2	,0x20A2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	0x002F	,0x00A2	,0x00A2	,0x0000	), // CENT SIGN
/*CURRENCY           */	DEADTRANS(	L'D'	,0x00A4	,0x20AF	,0x0000	), // DRACHMA SIGN
/*CURRENCY           */	DEADTRANS(	L'd'	,0x00A4	,0x20AB	,0x0000	), // DONG SIGN
/*CURRENCY           */	DEADTRANS(	L'E'	,0x00A4	,0x20AC	,0x0000	), // EURO SIGN
/*CURRENCY           */	DEADTRANS(	L'e'	,0x00A4	,0x20AC	,0x0000	), // EURO SIGN
/*CURRENCY           */	DEADTRANS(	L'F'	,0x00A4	,0x20A3	,0x0000	), // FRENCH FRANC SIGN
/*CURRENCY           */	DEADTRANS(	L'f'	,0x00A4	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*CURRENCY           */	DEADTRANS(	L'G'	,0x00A4	,0x20B2	,0x0000	), // GUARANI SIGN
/*CURRENCY           */	DEADTRANS(	L'H'	,0x00A4	,0x20BD	,0x0000	), // RUBLE SIGN
/*CURRENCY           */	DEADTRANS(	L'h'	,0x00A4	,0x20B4	,0x0000	), // HRYVNIA SIGN
/*CURRENCY           */	DEADTRANS(	L'I'	,0x00A4	,0x20A4	,0x0000	), // LIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'K'	,0x00A4	,0x20AD	,0x0000	), // KIP SIGN
/*CURRENCY           */	DEADTRANS(	L'k'	,0x00A4	,0x17DB	,0x0000	), // KHMER CURRENCY SYMBOL RIEL
/*CURRENCY           */	DEADTRANS(	L'L'	,0x00A4	,0x20BE	,0x0000	), // LARI SIGN
/*CURRENCY           */	DEADTRANS(	L'l'	,0x00A4	,0x20BA	,0x0000	), // TURKISH LIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'M'	,0x00A4	,0x20BC	,0x0000	), // MANAT SIGN
/*CURRENCY           */	DEADTRANS(	L'm'	,0x00A4	,0x20A5	,0x0000	), // MILL SIGN
/*CURRENCY           */	DEADTRANS(	L'N'	,0x00A4	,0x20A6	,0x0000	), // NAIRA SIGN
/*CURRENCY           */	DEADTRANS(	L'n'	,0x00A4	,0x20AA	,0x0000	), // NEW SHEQEL SIGN
/*CURRENCY           */	DEADTRANS(	L'O'	,0x00A4	,0x20A1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'o'	,0x00A4	,0x20A1	,0x0000	), // COLON SIGN
/*CURRENCY           */	DEADTRANS(	L'P'	,0x00A4	,0x20B1	,0x0000	), // PESO SIGN
/*CURRENCY           */	DEADTRANS(	L'p'	,0x00A4	,0x20A7	,0x0001	), // PESETA SIGN
/*CURRENCY           */	DEADTRANS(	L'f'	,0x20A7	,0x20B0	,0x0000	), // GERMAN PENNY SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x20A7	,0x20A7	,0x0000	), // PESETA SIGN
/*CURRENCY           */	DEADTRANS(	L'Q'	,0x00A4	,0x00A4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'q'	,0x00A4	,0x00A4	,0x0000	), // CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	L'R'	,0x00A4	,0x20B9	,0x0001	), // INDIAN RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'b'	,0x20B9	,0x09F2	,0x0000	), // BENGALI RUPEE MARK
/*CURRENCY           */	DEADTRANS(	L'g'	,0x20B9	,0x0AF1	,0x0000	), // GUJARATI RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x20B9	,0x20B9	,0x0000	), // INDIAN RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L's'	,0x20B9	,0x20A8	,0x0000	), // RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x20B9	,0x0BF9	,0x0000	), // TAMIL RUPEE SIGN
/*CURRENCY           */	DEADTRANS(	L'r'	,0x00A4	,0xFDFC	,0x0000	), // RIAL SIGN
/*CURRENCY           */	DEADTRANS(	L'S'	,0x00A4	,0x20B7	,0x0000	), // SPESMILO SIGN
/*CURRENCY           */	DEADTRANS(	0x007C	,0x00A4	,0x0024	,0x0000	), // DOLLAR SIGN
/*CURRENCY           */	DEADTRANS(	L'T'	,0x00A4	,0x20B8	,0x0000	), // TENGE SIGN
/*CURRENCY           */	DEADTRANS(	L't'	,0x00A4	,0x20AE	,0x0000	), // TUGRIK SIGN
/*CURRENCY           */	DEADTRANS(	L'W'	,0x00A4	,0x20A9	,0x0000	), // WON SIGN
/*CURRENCY           */	DEADTRANS(	L'w'	,0x00A4	,0x20A9	,0x0000	), // WON SIGN
/*CURRENCY           */	DEADTRANS(	L'X'	,0x00A4	,0x2133	,0x0000	), // SCRIPT CAPITAL M
/*CURRENCY           */	DEADTRANS(	L'Y'	,0x00A4	,0x00A5	,0x0000	), // YEN SIGN
/*CURRENCY           */	DEADTRANS(	L'y'	,0x00A4	,0x00A5	,0x0000	), // YEN SIGN
/*CURRENCY           */	DEADTRANS(	L'Z'	,0x00A4	,0x20A2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	L'z'	,0x00A4	,0x20A2	,0x0000	), // CRUZEIRO SIGN
/*CURRENCY           */	DEADTRANS(	0x20AC	,0x00A4	,0x20A0	,0x0000	), // EURO-CURRENCY SIGN
/*CURRENCY           */	DEADTRANS(	0x00A3	,0x00A4	,0x00A3	,0x0000	), // POUND SIGN
/*CURRENCY           */	DEADTRANS(	0x00B5	,0x00A4	,0x20BB	,0x0000	), // NORDIC MARK SIGN
/*CURRENCY           */	DEADTRANS(	0x2610	,0x00A4	,0x20B6	,0x0000	), // LIVRE TOURNOIS SIGN
/*CYRILLIC           */	DEADTRANS(	L'A'	,0x0436	,0x0410	,0x0000	), // CYRILLIC CAPITAL LETTER A
/*CYRILLIC           */	DEADTRANS(	L'a'	,0x0436	,0x0430	,0x0000	), // CYRILLIC SMALL LETTER A
/*CYRILLIC           */	DEADTRANS(	L'B'	,0x0436	,0x0411	,0x0000	), // CYRILLIC CAPITAL LETTER BE
/*CYRILLIC           */	DEADTRANS(	L'b'	,0x0436	,0x0431	,0x0000	), // CYRILLIC SMALL LETTER BE
/*CYRILLIC           */	DEADTRANS(	L'C'	,0x0436	,0x0426	,0x0000	), // CYRILLIC CAPITAL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	L'c'	,0x0436	,0x0446	,0x0000	), // CYRILLIC SMALL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	L'D'	,0x0436	,0x0414	,0x0000	), // CYRILLIC CAPITAL LETTER DE
/*CYRILLIC           */	DEADTRANS(	L'd'	,0x0436	,0x0434	,0x0000	), // CYRILLIC SMALL LETTER DE
/*CYRILLIC           */	DEADTRANS(	L'E'	,0x0436	,0x0415	,0x0000	), // CYRILLIC CAPITAL LETTER IE
/*CYRILLIC           */	DEADTRANS(	L'e'	,0x0436	,0x0435	,0x0000	), // CYRILLIC SMALL LETTER IE
/*CYRILLIC           */	DEADTRANS(	L'F'	,0x0436	,0x0424	,0x0000	), // CYRILLIC CAPITAL LETTER EF
/*CYRILLIC           */	DEADTRANS(	L'f'	,0x0436	,0x0444	,0x0000	), // CYRILLIC SMALL LETTER EF
/*CYRILLIC           */	DEADTRANS(	L'G'	,0x0436	,0x0413	,0x0000	), // CYRILLIC CAPITAL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	L'g'	,0x0436	,0x0433	,0x0000	), // CYRILLIC SMALL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	L'H'	,0x0436	,0x0425	,0x0000	), // CYRILLIC CAPITAL LETTER HA
/*CYRILLIC           */	DEADTRANS(	L'h'	,0x0436	,0x0445	,0x0000	), // CYRILLIC SMALL LETTER HA
/*CYRILLIC           */	DEADTRANS(	L'I'	,0x0436	,0x0418	,0x0000	), // CYRILLIC CAPITAL LETTER I
/*CYRILLIC           */	DEADTRANS(	L'i'	,0x0436	,0x0438	,0x0000	), // CYRILLIC SMALL LETTER I
/*CYRILLIC           */	DEADTRANS(	L'J'	,0x0436	,0x0419	,0x0000	), // CYRILLIC CAPITAL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	L'j'	,0x0436	,0x0439	,0x0000	), // CYRILLIC SMALL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	L'K'	,0x0436	,0x041A	,0x0000	), // CYRILLIC CAPITAL LETTER KA
/*CYRILLIC           */	DEADTRANS(	L'k'	,0x0436	,0x043A	,0x0000	), // CYRILLIC SMALL LETTER KA
/*CYRILLIC           */	DEADTRANS(	L'L'	,0x0436	,0x041B	,0x0000	), // CYRILLIC CAPITAL LETTER EL
/*CYRILLIC           */	DEADTRANS(	L'l'	,0x0436	,0x043B	,0x0000	), // CYRILLIC SMALL LETTER EL
/*CYRILLIC           */	DEADTRANS(	L'M'	,0x0436	,0x041C	,0x0000	), // CYRILLIC CAPITAL LETTER EM
/*CYRILLIC           */	DEADTRANS(	L'm'	,0x0436	,0x043C	,0x0000	), // CYRILLIC SMALL LETTER EM
/*CYRILLIC           */	DEADTRANS(	L'N'	,0x0436	,0x041D	,0x0000	), // CYRILLIC CAPITAL LETTER EN
/*CYRILLIC           */	DEADTRANS(	L'n'	,0x0436	,0x043D	,0x0000	), // CYRILLIC SMALL LETTER EN
/*CYRILLIC           */	DEADTRANS(	L'O'	,0x0436	,0x041E	,0x0000	), // CYRILLIC CAPITAL LETTER O
/*CYRILLIC           */	DEADTRANS(	L'o'	,0x0436	,0x043E	,0x0000	), // CYRILLIC SMALL LETTER O
/*CYRILLIC           */	DEADTRANS(	L'P'	,0x0436	,0x041F	,0x0000	), // CYRILLIC CAPITAL LETTER PE
/*CYRILLIC           */	DEADTRANS(	L'p'	,0x0436	,0x043F	,0x0000	), // CYRILLIC SMALL LETTER PE
/*CYRILLIC           */	DEADTRANS(	L'Q'	,0x0436	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	L'q'	,0x0436	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	L'R'	,0x0436	,0x0420	,0x0000	), // CYRILLIC CAPITAL LETTER ER
/*CYRILLIC           */	DEADTRANS(	L'r'	,0x0436	,0x0440	,0x0000	), // CYRILLIC SMALL LETTER ER
/*CYRILLIC           */	DEADTRANS(	L'S'	,0x0436	,0x0421	,0x0000	), // CYRILLIC CAPITAL LETTER ES
/*CYRILLIC           */	DEADTRANS(	L's'	,0x0436	,0x0441	,0x0000	), // CYRILLIC SMALL LETTER ES
/*CYRILLIC           */	DEADTRANS(	L'T'	,0x0436	,0x0422	,0x0000	), // CYRILLIC CAPITAL LETTER TE
/*CYRILLIC           */	DEADTRANS(	L't'	,0x0436	,0x0442	,0x0000	), // CYRILLIC SMALL LETTER TE
/*CYRILLIC           */	DEADTRANS(	L'U'	,0x0436	,0x0423	,0x0000	), // CYRILLIC CAPITAL LETTER U
/*CYRILLIC           */	DEADTRANS(	L'u'	,0x0436	,0x0443	,0x0000	), // CYRILLIC SMALL LETTER U
/*CYRILLIC           */	DEADTRANS(	L'V'	,0x0436	,0x0412	,0x0000	), // CYRILLIC CAPITAL LETTER VE
/*CYRILLIC           */	DEADTRANS(	L'v'	,0x0436	,0x0432	,0x0000	), // CYRILLIC SMALL LETTER VE
/*CYRILLIC           */	DEADTRANS(	L'W'	,0x0436	,0x0428	,0x0000	), // CYRILLIC CAPITAL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	L'w'	,0x0436	,0x0448	,0x0000	), // CYRILLIC SMALL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	L'X'	,0x0436	,0x0416	,0x0000	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	L'x'	,0x0436	,0x0436	,0x0000	), // CYRILLIC SMALL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	L'Y'	,0x0436	,0x042A	,0x0000	), // CYRILLIC CAPITAL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	L'y'	,0x0436	,0x044A	,0x0000	), // CYRILLIC SMALL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	L'Z'	,0x0436	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	L'z'	,0x0436	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x002A	,0x0436	,0x0482	,0x0000	), // CYRILLIC THOUSANDS SIGN
/*CYRILLIC           */	DEADTRANS(	0x0436	,0x0436	,0x0416	,0x0001	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x1F12	,0x0436	,0x0482	,0x0000	), // CYRILLIC THOUSANDS SIGN
/*CYRILLIC           */	DEADTRANS(	0x00E1	,0x0436	,0x0449	,0x0000	), // CYRILLIC SMALL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x1F7D	,0x0436	,0x0449	,0x0000	), // CYRILLIC SMALL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x00EA	,0x0436	,0x044F	,0x0000	), // CYRILLIC SMALL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x1FC6	,0x0436	,0x044F	,0x0000	), // CYRILLIC SMALL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x00EB	,0x0436	,0x042F	,0x0000	), // CYRILLIC CAPITAL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x03CA	,0x0436	,0x042F	,0x0000	), // CYRILLIC CAPITAL LETTER YA
/*CYRILLIC           */	DEADTRANS(	0x00F2	,0x0436	,0x044C	,0x0000	), // CYRILLIC SMALL LETTER SOFT SIGN
/*CYRILLIC           */	DEADTRANS(	0x1F70	,0x0436	,0x044C	,0x0000	), // CYRILLIC SMALL LETTER SOFT SIGN
/*CYRILLIC           */	DEADTRANS(	0x00F5	,0x0436	,0x0429	,0x0000	), // CYRILLIC CAPITAL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x1F14	,0x0436	,0x0429	,0x0000	), // CYRILLIC CAPITAL LETTER SHCHA
/*CYRILLIC           */	DEADTRANS(	0x03CC	,0x0436	,0x045D	,0x0000	), // CYRILLIC SMALL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x2019	,0x0436	,0x045D	,0x0000	), // CYRILLIC SMALL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x02BC	,0x0436	,0x040D	,0x0000	), // CYRILLIC CAPITAL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x0390	,0x0436	,0x040D	,0x0000	), // CYRILLIC CAPITAL LETTER I WITH GRAVE
/*CYRILLIC           */	DEADTRANS(	0x0391	,0x0436	,0x0410	,0x0000	), // CYRILLIC CAPITAL LETTER A
/*CYRILLIC           */	DEADTRANS(	0x03B1	,0x0436	,0x0430	,0x0000	), // CYRILLIC SMALL LETTER A
/*CYRILLIC           */	DEADTRANS(	0x0392	,0x0436	,0x0411	,0x0000	), // CYRILLIC CAPITAL LETTER BE
/*CYRILLIC           */	DEADTRANS(	0x03B2	,0x0436	,0x0431	,0x0000	), // CYRILLIC SMALL LETTER BE
/*CYRILLIC           */	DEADTRANS(	0x0393	,0x0436	,0x0413	,0x0000	), // CYRILLIC CAPITAL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	0x03B3	,0x0436	,0x0433	,0x0000	), // CYRILLIC SMALL LETTER GHE
/*CYRILLIC           */	DEADTRANS(	0x0394	,0x0436	,0x0414	,0x0000	), // CYRILLIC CAPITAL LETTER DE
/*CYRILLIC           */	DEADTRANS(	0x03B4	,0x0436	,0x0434	,0x0000	), // CYRILLIC SMALL LETTER DE
/*CYRILLIC           */	DEADTRANS(	0x0395	,0x0436	,0x0415	,0x0000	), // CYRILLIC CAPITAL LETTER IE
/*CYRILLIC           */	DEADTRANS(	0x03B5	,0x0436	,0x0435	,0x0000	), // CYRILLIC SMALL LETTER IE
/*CYRILLIC           */	DEADTRANS(	0x0396	,0x0436	,0x0417	,0x0000	), // CYRILLIC CAPITAL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x03B6	,0x0436	,0x0437	,0x0000	), // CYRILLIC SMALL LETTER ZE
/*CYRILLIC           */	DEADTRANS(	0x0397	,0x0436	,0x0425	,0x0000	), // CYRILLIC CAPITAL LETTER HA
/*CYRILLIC           */	DEADTRANS(	0x03B7	,0x0436	,0x0445	,0x0000	), // CYRILLIC SMALL LETTER HA
/*CYRILLIC           */	DEADTRANS(	0x0398	,0x0436	,0x0423	,0x0000	), // CYRILLIC CAPITAL LETTER U
/*CYRILLIC           */	DEADTRANS(	0x03B8	,0x0436	,0x0443	,0x0000	), // CYRILLIC SMALL LETTER U
/*CYRILLIC           */	DEADTRANS(	0x0399	,0x0436	,0x0418	,0x0000	), // CYRILLIC CAPITAL LETTER I
/*CYRILLIC           */	DEADTRANS(	0x03B9	,0x0436	,0x0438	,0x0000	), // CYRILLIC SMALL LETTER I
/*CYRILLIC           */	DEADTRANS(	0x039A	,0x0436	,0x041A	,0x0000	), // CYRILLIC CAPITAL LETTER KA
/*CYRILLIC           */	DEADTRANS(	0x03BA	,0x0436	,0x043A	,0x0000	), // CYRILLIC SMALL LETTER KA
/*CYRILLIC           */	DEADTRANS(	0x039B	,0x0436	,0x041B	,0x0000	), // CYRILLIC CAPITAL LETTER EL
/*CYRILLIC           */	DEADTRANS(	0x03BB	,0x0436	,0x043B	,0x0000	), // CYRILLIC SMALL LETTER EL
/*CYRILLIC           */	DEADTRANS(	0x039C	,0x0436	,0x041C	,0x0000	), // CYRILLIC CAPITAL LETTER EM
/*CYRILLIC           */	DEADTRANS(	0x03BC	,0x0436	,0x043C	,0x0000	), // CYRILLIC SMALL LETTER EM
/*CYRILLIC           */	DEADTRANS(	0x039D	,0x0436	,0x041D	,0x0000	), // CYRILLIC CAPITAL LETTER EN
/*CYRILLIC           */	DEADTRANS(	0x03BD	,0x0436	,0x043D	,0x0000	), // CYRILLIC SMALL LETTER EN
/*CYRILLIC           */	DEADTRANS(	0x039E	,0x0436	,0x0419	,0x0000	), // CYRILLIC CAPITAL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	0x03BE	,0x0436	,0x0439	,0x0000	), // CYRILLIC SMALL LETTER SHORT I
/*CYRILLIC           */	DEADTRANS(	0x039F	,0x0436	,0x041E	,0x0000	), // CYRILLIC CAPITAL LETTER O
/*CYRILLIC           */	DEADTRANS(	0x03BF	,0x0436	,0x043E	,0x0000	), // CYRILLIC SMALL LETTER O
/*CYRILLIC           */	DEADTRANS(	0x03A0	,0x0436	,0x041F	,0x0000	), // CYRILLIC CAPITAL LETTER PE
/*CYRILLIC           */	DEADTRANS(	0x03C0	,0x0436	,0x043F	,0x0000	), // CYRILLIC SMALL LETTER PE
/*CYRILLIC           */	DEADTRANS(	0x03A1	,0x0436	,0x0420	,0x0000	), // CYRILLIC CAPITAL LETTER ER
/*CYRILLIC           */	DEADTRANS(	0x03C1	,0x0436	,0x0440	,0x0000	), // CYRILLIC SMALL LETTER ER
/*CYRILLIC           */	DEADTRANS(	0x03A3	,0x0436	,0x0421	,0x0000	), // CYRILLIC CAPITAL LETTER ES
/*CYRILLIC           */	DEADTRANS(	0x03C2	,0x0436	,0x0447	,0x0000	), // CYRILLIC SMALL LETTER CHE
/*CYRILLIC           */	DEADTRANS(	0x03C3	,0x0436	,0x0441	,0x0000	), // CYRILLIC SMALL LETTER ES
/*CYRILLIC           */	DEADTRANS(	0x03A4	,0x0436	,0x0422	,0x0000	), // CYRILLIC CAPITAL LETTER TE
/*CYRILLIC           */	DEADTRANS(	0x03C4	,0x0436	,0x0442	,0x0000	), // CYRILLIC SMALL LETTER TE
/*CYRILLIC           */	DEADTRANS(	0x03A5	,0x0436	,0x042A	,0x0000	), // CYRILLIC CAPITAL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	0x03C5	,0x0436	,0x044A	,0x0000	), // CYRILLIC SMALL LETTER HARD SIGN
/*CYRILLIC           */	DEADTRANS(	0x03A6	,0x0436	,0x0424	,0x0000	), // CYRILLIC CAPITAL LETTER EF
/*CYRILLIC           */	DEADTRANS(	0x03C6	,0x0436	,0x0444	,0x0000	), // CYRILLIC SMALL LETTER EF
/*CYRILLIC           */	DEADTRANS(	0x03A7	,0x0436	,0x0416	,0x0000	), // CYRILLIC CAPITAL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x03C7	,0x0436	,0x0436	,0x0000	), // CYRILLIC SMALL LETTER ZHE
/*CYRILLIC           */	DEADTRANS(	0x03A8	,0x0436	,0x0426	,0x0000	), // CYRILLIC CAPITAL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	0x03C8	,0x0436	,0x0446	,0x0000	), // CYRILLIC SMALL LETTER TSE
/*CYRILLIC           */	DEADTRANS(	0x03A9	,0x0436	,0x0412	,0x0000	), // CYRILLIC CAPITAL LETTER VE
/*CYRILLIC           */	DEADTRANS(	0x03C9	,0x0436	,0x0432	,0x0000	), // CYRILLIC SMALL LETTER VE
/*CYRILLIC           */	DEADTRANS(	0x03DA	,0x0436	,0x0428	,0x0000	), // CYRILLIC CAPITAL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	0x0448	,0x0436	,0x0448	,0x0000	), // CYRILLIC SMALL LETTER SHA
/*CYRILLIC           */	DEADTRANS(	0x2211	,0x0436	,0x0427	,0x0000	), // CYRILLIC CAPITAL LETTER CHE
/*DESCENDER          */	DEADTRANS(	L'e'	,0x2C6A	,0x2C78	,0x0000	), // LATIN SMALL LETTER E WITH NOTCH
/*DESCENDER          */	DEADTRANS(	L'H'	,0x2C6A	,0x2C67	,0x0000	), // LATIN CAPITAL LETTER H WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'h'	,0x2C6A	,0x2C68	,0x0000	), // LATIN SMALL LETTER H WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'K'	,0x2C6A	,0x2C69	,0x0000	), // LATIN CAPITAL LETTER K WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'k'	,0x2C6A	,0x2C6A	,0x0000	), // LATIN SMALL LETTER K WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'N'	,0x2C6A	,0xA790	,0x0000	), // LATIN CAPITAL LETTER N WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'n'	,0x2C6A	,0xA791	,0x0000	), // LATIN SMALL LETTER N WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'Z'	,0x2C6A	,0x2C6B	,0x0000	), // LATIN CAPITAL LETTER Z WITH DESCENDER
/*DESCENDER          */	DEADTRANS(	L'z'	,0x2C6A	,0x2C6C	,0x0000	), // LATIN SMALL LETTER Z WITH DESCENDER
/*DIAERESIS          */	DEADTRANS(	0x0020	,0x00EB	,0x0308	,0x0000	), // COMBINING DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x00B0	,0x00EB	,0x1AB1	,0x0000	), // COMBINING DIAERESIS-RING
/*DIAERESIS          */	DEADTRANS(	0x00A0	,0x00EB	,0x00A8	,0x0000	), // DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x202F	,0x00EB	,0x00A8	,0x0000	), // DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'A'	,0x00EB	,0x00C4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'a'	,0x00EB	,0x00E4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'B'	,0x00EB	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*DIAERESIS          */	DEADTRANS(	L'b'	,0x00EB	,0x014B	,0x0000	), // LATIN SMALL LETTER ENG
/*DIAERESIS          */	DEADTRANS(	L'C'	,0x00EB	,0x00B0	,0x0000	), // DEGREE SIGN
/*DIAERESIS          */	DEADTRANS(	L'c'	,0x00EB	,0x00B0	,0x0000	), // DEGREE SIGN
/*DIAERESIS          */	DEADTRANS(	L'D'	,0x00EB	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*DIAERESIS          */	DEADTRANS(	L'd'	,0x00EB	,0x00F0	,0x0000	), // LATIN SMALL LETTER ETH
/*DIAERESIS          */	DEADTRANS(	L'E'	,0x00EB	,0x00CB	,0x0000	), // LATIN CAPITAL LETTER E WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'e'	,0x00EB	,0x00EB	,0x0000	), // LATIN SMALL LETTER E WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'F'	,0x00EB	,0x00A6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	L'f'	,0x00EB	,0x00A6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	L'G'	,0x00EB	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*DIAERESIS          */	DEADTRANS(	L'g'	,0x00EB	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*DIAERESIS          */	DEADTRANS(	L'H'	,0x00EB	,0x1E26	,0x0000	), // LATIN CAPITAL LETTER H WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'h'	,0x00EB	,0x1E27	,0x0000	), // LATIN SMALL LETTER H WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'I'	,0x00EB	,0x00CF	,0x0000	), // LATIN CAPITAL LETTER I WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'i'	,0x00EB	,0x00EF	,0x0000	), // LATIN SMALL LETTER I WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'J'	,0x00EB	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*DIAERESIS          */	DEADTRANS(	L'j'	,0x00EB	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*DIAERESIS          */	DEADTRANS(	L'l'	,0x00EB	,0x019B	,0x0000	), // LATIN SMALL LETTER LAMBDA WITH STROKE
/*DIAERESIS          */	DEADTRANS(	L'O'	,0x00EB	,0x00D6	,0x0000	), // LATIN CAPITAL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'o'	,0x00EB	,0x00F6	,0x0000	), // LATIN SMALL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Q'	,0x00EB	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*DIAERESIS          */	DEADTRANS(	L'q'	,0x00EB	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*DIAERESIS          */	DEADTRANS(	L'r'	,0x00EB	,0x027E	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK
/*DIAERESIS          */	DEADTRANS(	L'S'	,0x00EB	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*DIAERESIS          */	DEADTRANS(	L's'	,0x00EB	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*DIAERESIS          */	DEADTRANS(	L'T'	,0x00EB	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DIAERESIS          */	DEADTRANS(	0x2011	,0x00EB	,0x2010	,0x0000	), // HYPHEN
/*DIAERESIS          */	DEADTRANS(	L't'	,0x00EB	,0x1E97	,0x0000	), // LATIN SMALL LETTER T WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'U'	,0x00EB	,0x00DC	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'u'	,0x00EB	,0x00FC	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'W'	,0x00EB	,0x1E84	,0x0000	), // LATIN CAPITAL LETTER W WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'w'	,0x00EB	,0x1E85	,0x0000	), // LATIN SMALL LETTER W WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'X'	,0x00EB	,0x1E8C	,0x0000	), // LATIN CAPITAL LETTER X WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'x'	,0x00EB	,0x1E8D	,0x0000	), // LATIN SMALL LETTER X WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Y'	,0x00EB	,0x0178	,0x0000	), // LATIN CAPITAL LETTER Y WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'y'	,0x00EB	,0x00FF	,0x0000	), // LATIN SMALL LETTER Y WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	L'Z'	,0x00EB	,0x2260	,0x0000	), // NOT EQUAL TO
/*DIAERESIS          */	DEADTRANS(	L'z'	,0x00EB	,0x2260	,0x0000	), // NOT EQUAL TO
/*DIAERESIS          */	DEADTRANS(	0x00C9	,0x00C0	,0x00C5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00E9	,0x00E0	,0x00E5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00C9	,0x00EB	,0x00C5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x00E9	,0x00EB	,0x00E5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*DIAERESIS          */	DEADTRANS(	0x0152	,0x00EB	,0x00D8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*DIAERESIS          */	DEADTRANS(	0x0153	,0x00EB	,0x00F8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*DIAERESIS          */	DEADTRANS(	0x0021	,0x00EB	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0022	,0x00EB	,0x201E	,0x0000	), // DOUBLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0023	,0x00EB	,0x201E	,0x0000	), // DOUBLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0027	,0x00EB	,0x201A	,0x0000	), // SINGLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x0028	,0x00EB	,0x208D	,0x0000	), // SUBSCRIPT LEFT PARENTHESIS
/*DIAERESIS          */	DEADTRANS(	0x0029	,0x00EB	,0x208E	,0x0000	), // SUBSCRIPT RIGHT PARENTHESIS
/*DIAERESIS          */	DEADTRANS(	0x002A	,0x00EB	,0x2051	,0x0000	), // TWO ASTERISKS ALIGNED VERTICALLY
/*DIAERESIS          */	DEADTRANS(	0x002B	,0x00EB	,0x208A	,0x0000	), // SUBSCRIPT PLUS SIGN
/*DIAERESIS          */	DEADTRANS(	0x002D	,0x00EB	,0x2E3A	,0x0000	), // TWO-EM DASH
/*DIAERESIS          */	DEADTRANS(	0x002E	,0x00EB	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DIAERESIS          */	DEADTRANS(	0x002F	,0x00EB	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DIAERESIS          */	DEADTRANS(	L'0'	,0x00EB	,0x2080	,0x0000	), // SUBSCRIPT ZERO
/*DIAERESIS          */	DEADTRANS(	L'1'	,0x00EB	,0x2081	,0x0000	), // SUBSCRIPT ONE
/*DIAERESIS          */	DEADTRANS(	L'2'	,0x00EB	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*DIAERESIS          */	DEADTRANS(	L'3'	,0x00EB	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*DIAERESIS          */	DEADTRANS(	L'4'	,0x00EB	,0x2084	,0x0000	), // SUBSCRIPT FOUR
/*DIAERESIS          */	DEADTRANS(	L'5'	,0x00EB	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*DIAERESIS          */	DEADTRANS(	L'6'	,0x00EB	,0x2086	,0x0000	), // SUBSCRIPT SIX
/*DIAERESIS          */	DEADTRANS(	L'7'	,0x00EB	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*DIAERESIS          */	DEADTRANS(	L'8'	,0x00EB	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*DIAERESIS          */	DEADTRANS(	L'9'	,0x00EB	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*DIAERESIS          */	DEADTRANS(	0x003A	,0x00EB	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DIAERESIS          */	DEADTRANS(	0x003E	,0x00EB	,0x01DA	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS          */	DEADTRANS(	0x003D	,0x00EB	,0x208C	,0x0000	), // SUBSCRIPT EQUALS SIGN
/*DIAERESIS          */	DEADTRANS(	0x003F	,0x00EB	,0x00BF	,0x0000	), // INVERTED QUESTION MARK
/*DIAERESIS          */	DEADTRANS(	0x0060	,0x00EB	,0x01DC	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS          */	DEADTRANS(	0x005F	,0x00EB	,0x022B	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS          */	DEADTRANS(	0x007C	,0x00EB	,0x00A6	,0x0000	), // BROKEN BAR
/*DIAERESIS          */	DEADTRANS(	0x007E	,0x00EB	,0x1E4F	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x00A9	,0x00EB	,0x00F6	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x0027	,0x00F6	,0x01D8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS          */	DEADTRANS(	0x00A7	,0x00EB	,0x204B	,0x0000	), // REVERSED PILCROW SIGN
/*DIAERESIS          */	DEADTRANS(	0x00AB	,0x00EB	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x00B5	,0x00EB	,0x2282	,0x0000	), // SUBSET OF
/*DIAERESIS          */	DEADTRANS(	0x00BB	,0x00EB	,0x203A	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x00E1	,0x00EB	,0x01D8	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS          */	DEADTRANS(	0x00EA	,0x00EB	,0x1ECD	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*DIAERESIS          */	DEADTRANS(	0x00EB	,0x00EB	,0x1E73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*DIAERESIS          */	DEADTRANS(	0x00F2	,0x00EB	,0x01DC	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS          */	DEADTRANS(	0x00F5	,0x00EB	,0x1E4F	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*DIAERESIS          */	DEADTRANS(	0x02BC	,0x00EB	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DIAERESIS          */	DEADTRANS(	0x2019	,0x00EB	,0x201A	,0x0000	), // SINGLE LOW-9 QUOTATION MARK
/*DIAERESIS          */	DEADTRANS(	0x2212	,0x00EB	,0x208B	,0x0000	), // SUBSCRIPT MINUS
/*DIAERESIS          */	DEADTRANS(	0x2610	,0x00EB	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*DIAERESIS          */	DEADTRANS(	0x021F	,0x00EB	,0x01DA	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS          */	DEADTRANS(	0x014D	,0x00EB	,0x022B	,0x0001	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS          */	DEADTRANS(	0x03C0	,0x00EB	,0x2283	,0x0000	), // SUPERSET OF
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'I'	,0x01D8	,0x1E2E	,0x0000	), // LATIN CAPITAL LETTER I WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'i'	,0x01D8	,0x1E2F	,0x0000	), // LATIN SMALL LETTER I WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'U'	,0x01D8	,0x01D7	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS&ACUTE    */	DEADTRANS(	L'u'	,0x01D8	,0x01D8	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
/*DIAERESIS&GRAVE    */	DEADTRANS(	L'U'	,0x01DC	,0x01DB	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS&GRAVE    */	DEADTRANS(	L'u'	,0x01DC	,0x01DC	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*DIAERESIS&HACEK    */	DEADTRANS(	L'U'	,0x01DA	,0x01D9	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS&HACEK    */	DEADTRANS(	L'u'	,0x01DA	,0x01DA	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'A'	,0x022B	,0x01DE	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'a'	,0x022B	,0x01DF	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'O'	,0x022B	,0x022A	,0x0000	), // LATIN CAPITAL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'o'	,0x022B	,0x022B	,0x0000	), // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'U'	,0x022B	,0x01D5	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND MACRON
/*DIAERESIS&MACRON   */	DEADTRANS(	L'u'	,0x022B	,0x01D6	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND MACRON
/*DIAERESIS_BELOW    */	DEADTRANS(	0x0020	,0x1E73	,0x0324	,0x0000	), // COMBINING DIAERESIS BELOW
/*DIAERESIS_BELOW    */	DEADTRANS(	L'U'	,0x1E73	,0x1E72	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS BELOW
/*DIAERESIS_BELOW    */	DEADTRANS(	L'u'	,0x1E73	,0x1E73	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*DOT_ABOVE          */	DEADTRANS(	0x0020	,0x1E57	,0x0307	,0x0000	), // COMBINING DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0028	,0x1E57	,0x0352	,0x0000	), // COMBINING FERMATA
/*DOT_ABOVE          */	DEADTRANS(	0x0029	,0x1E57	,0x0310	,0x0000	), // COMBINING CANDRABINDU
/*DOT_ABOVE          */	DEADTRANS(	0x00EB	,0x1E57	,0x1AB4	,0x0000	), // COMBINING TRIPLE DOT
/*DOT_ABOVE          */	DEADTRANS(	0x00A0	,0x1E57	,0x02D9	,0x0000	), // DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x202F	,0x1E57	,0x02D9	,0x0000	), // DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'A'	,0x1E57	,0x0226	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'a'	,0x1E57	,0x0227	,0x0000	), // LATIN SMALL LETTER A WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'B'	,0x1E57	,0x1E02	,0x0000	), // LATIN CAPITAL LETTER B WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'b'	,0x1E57	,0x1E03	,0x0000	), // LATIN SMALL LETTER B WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'C'	,0x1E57	,0x010A	,0x0000	), // LATIN CAPITAL LETTER C WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'c'	,0x1E57	,0x010B	,0x0000	), // LATIN SMALL LETTER C WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'D'	,0x1E57	,0x1E0A	,0x0000	), // LATIN CAPITAL LETTER D WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'd'	,0x1E57	,0x1E0B	,0x0000	), // LATIN SMALL LETTER D WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'E'	,0x1E57	,0x0116	,0x0000	), // LATIN CAPITAL LETTER E WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'e'	,0x1E57	,0x0117	,0x0000	), // LATIN SMALL LETTER E WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'F'	,0x1E57	,0x1E1E	,0x0000	), // LATIN CAPITAL LETTER F WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'f'	,0x1E57	,0x1E1F	,0x0000	), // LATIN SMALL LETTER F WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'G'	,0x1E57	,0x0120	,0x0000	), // LATIN CAPITAL LETTER G WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'g'	,0x1E57	,0x0121	,0x0000	), // LATIN SMALL LETTER G WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'H'	,0x1E57	,0x1E22	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'h'	,0x1E57	,0x1E23	,0x0000	), // LATIN SMALL LETTER H WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'I'	,0x1E57	,0x0130	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'i'	,0x1E57	,0x0131	,0x0000	), // LATIN SMALL LETTER DOTLESS I
/*DOT_ABOVE          */	DEADTRANS(	L'j'	,0x1E57	,0x0237	,0x0000	), // LATIN SMALL LETTER DOTLESS J
/*DOT_ABOVE          */	DEADTRANS(	L'L'	,0x1E57	,0x013F	,0x0000	), // LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*DOT_ABOVE          */	DEADTRANS(	L'l'	,0x1E57	,0x0140	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE DOT
/*DOT_ABOVE          */	DEADTRANS(	L'M'	,0x1E57	,0x1E40	,0x0000	), // LATIN CAPITAL LETTER M WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'm'	,0x1E57	,0x1E41	,0x0000	), // LATIN SMALL LETTER M WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'N'	,0x1E57	,0x1E44	,0x0000	), // LATIN CAPITAL LETTER N WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'n'	,0x1E57	,0x1E45	,0x0000	), // LATIN SMALL LETTER N WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'O'	,0x1E57	,0x022E	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'o'	,0x1E57	,0x022F	,0x0000	), // LATIN SMALL LETTER O WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'P'	,0x1E57	,0x1E56	,0x0000	), // LATIN CAPITAL LETTER P WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'p'	,0x1E57	,0x1E57	,0x0000	), // LATIN SMALL LETTER P WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'R'	,0x1E57	,0x1E58	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'r'	,0x1E57	,0x1E59	,0x0000	), // LATIN SMALL LETTER R WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'S'	,0x1E57	,0x1E60	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L's'	,0x1E57	,0x1E61	,0x0000	), // LATIN SMALL LETTER S WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'T'	,0x1E57	,0x1E6A	,0x0000	), // LATIN CAPITAL LETTER T WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L't'	,0x1E57	,0x1E6B	,0x0000	), // LATIN SMALL LETTER T WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'W'	,0x1E57	,0x1E86	,0x0000	), // LATIN CAPITAL LETTER W WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'w'	,0x1E57	,0x1E87	,0x0000	), // LATIN SMALL LETTER W WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'X'	,0x1E57	,0x1E8A	,0x0000	), // LATIN CAPITAL LETTER X WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'x'	,0x1E57	,0x1E8B	,0x0000	), // LATIN SMALL LETTER X WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'Y'	,0x1E57	,0x1E8E	,0x0000	), // LATIN CAPITAL LETTER Y WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'y'	,0x1E57	,0x1E8F	,0x0000	), // LATIN SMALL LETTER Y WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'Z'	,0x1E57	,0x017B	,0x0000	), // LATIN CAPITAL LETTER Z WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	L'z'	,0x1E57	,0x017C	,0x0000	), // LATIN SMALL LETTER Z WITH DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0021	,0x1E57	,0x1E69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x0025	,0x1E57	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DOT_ABOVE          */	DEADTRANS(	0x0027	,0x1E57	,0x1E65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x002E	,0x1E57	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DOT_ABOVE          */	DEADTRANS(	0x002F	,0x1E57	,0x2052	,0x0000	), // COMMERCIAL MINUS SIGN
/*DOT_ABOVE          */	DEADTRANS(	L'1'	,0x1E57	,0x2024	,0x0000	), // ONE DOT LEADER
/*DOT_ABOVE          */	DEADTRANS(	L'2'	,0x1E57	,0x2025	,0x0000	), // TWO DOT LEADER
/*DOT_ABOVE          */	DEADTRANS(	L'3'	,0x1E57	,0x2026	,0x0000	), // HORIZONTAL ELLIPSIS
/*DOT_ABOVE          */	DEADTRANS(	0x003A	,0x1E57	,0x2056	,0x0000	), // THREE DOT PUNCTUATION
/*DOT_ABOVE          */	DEADTRANS(	0x003E	,0x1E57	,0x1E67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x005F	,0x1E57	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE          */	DEADTRANS(	L'0'	,0x1E9B	,0xA70C	,0x0000	), // MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'1'	,0x1E9B	,0xA70B	,0x0000	), // MODIFIER LETTER LOW DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'2'	,0x1E9B	,0xA70A	,0x0000	), // MODIFIER LETTER MID DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'3'	,0x1E9B	,0xA709	,0x0000	), // MODIFIER LETTER HIGH DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	L'4'	,0x1E9B	,0xA708	,0x0000	), // MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*DOT_ABOVE          */	DEADTRANS(	0x00E1	,0x1E57	,0x1E65	,0x0001	), // LATIN SMALL LETTER S WITH ACUTE AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x021F	,0x1E57	,0x1E67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x014D	,0x1E57	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE          */	DEADTRANS(	0x1EE5	,0x1E57	,0x1E69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE          */	DEADTRANS(	0x017F	,0x1E57	,0x1E9B	,0x0001	), // LATIN SMALL LETTER LONG S WITH DOT ABOVE
/*DOT_ABOVE&DOT_BELOW*/	DEADTRANS(	L'S'	,0x1E69	,0x1E68	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE&DOT_BELOW*/	DEADTRANS(	L's'	,0x1E69	,0x1E69	,0x0000	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'A'	,0x0231	,0x01E0	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'a'	,0x0231	,0x01E1	,0x0000	), // LATIN SMALL LETTER A WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'O'	,0x0231	,0x0230	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_ABOVE&MACRON   */	DEADTRANS(	L'o'	,0x0231	,0x0231	,0x0000	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x0020	,0x1E05	,0x0323	,0x0000	), // COMBINING DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'A'	,0x1E05	,0x1EA0	,0x0000	), // LATIN CAPITAL LETTER A WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'a'	,0x1E05	,0x1EA1	,0x0000	), // LATIN SMALL LETTER A WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'B'	,0x1E05	,0x1E04	,0x0000	), // LATIN CAPITAL LETTER B WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'b'	,0x1E05	,0x1E05	,0x0000	), // LATIN SMALL LETTER B WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'D'	,0x1E05	,0x1E0C	,0x0000	), // LATIN CAPITAL LETTER D WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'd'	,0x1E05	,0x1E0D	,0x0000	), // LATIN SMALL LETTER D WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'E'	,0x1E05	,0x1EB8	,0x0000	), // LATIN CAPITAL LETTER E WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'e'	,0x1E05	,0x1EB9	,0x0000	), // LATIN SMALL LETTER E WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'H'	,0x1E05	,0x1E24	,0x0000	), // LATIN CAPITAL LETTER H WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'h'	,0x1E05	,0x1E25	,0x0000	), // LATIN SMALL LETTER H WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'I'	,0x1E05	,0x1ECA	,0x0000	), // LATIN CAPITAL LETTER I WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'i'	,0x1E05	,0x1ECB	,0x0000	), // LATIN SMALL LETTER I WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'K'	,0x1E05	,0x1E32	,0x0000	), // LATIN CAPITAL LETTER K WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'k'	,0x1E05	,0x1E33	,0x0000	), // LATIN SMALL LETTER K WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'L'	,0x1E05	,0x1E36	,0x0000	), // LATIN CAPITAL LETTER L WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'l'	,0x1E05	,0x1E37	,0x0000	), // LATIN SMALL LETTER L WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'M'	,0x1E05	,0x1E42	,0x0000	), // LATIN CAPITAL LETTER M WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'm'	,0x1E05	,0x1E43	,0x0000	), // LATIN SMALL LETTER M WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'N'	,0x1E05	,0x1E46	,0x0000	), // LATIN CAPITAL LETTER N WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'n'	,0x1E05	,0x1E47	,0x0000	), // LATIN SMALL LETTER N WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'O'	,0x1E05	,0x1ECC	,0x0000	), // LATIN CAPITAL LETTER O WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'o'	,0x1E05	,0x1ECD	,0x0000	), // LATIN SMALL LETTER O WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'R'	,0x1E05	,0x1E5A	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'r'	,0x1E05	,0x1E5B	,0x0000	), // LATIN SMALL LETTER R WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'S'	,0x1E05	,0x1E62	,0x0000	), // LATIN CAPITAL LETTER S WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L's'	,0x1E05	,0x1E63	,0x0000	), // LATIN SMALL LETTER S WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'T'	,0x1E05	,0x1E6C	,0x0000	), // LATIN CAPITAL LETTER T WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L't'	,0x1E05	,0x1E6D	,0x0000	), // LATIN SMALL LETTER T WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'U'	,0x1E05	,0x1EE4	,0x0000	), // LATIN CAPITAL LETTER U WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'u'	,0x1E05	,0x1EE5	,0x0000	), // LATIN SMALL LETTER U WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'V'	,0x1E05	,0x1E7E	,0x0000	), // LATIN CAPITAL LETTER V WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'v'	,0x1E05	,0x1E7F	,0x0000	), // LATIN SMALL LETTER V WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'W'	,0x1E05	,0x1E88	,0x0000	), // LATIN CAPITAL LETTER W WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'w'	,0x1E05	,0x1E89	,0x0000	), // LATIN SMALL LETTER W WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'Y'	,0x1E05	,0x1EF4	,0x0000	), // LATIN CAPITAL LETTER Y WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'y'	,0x1E05	,0x1EF5	,0x0000	), // LATIN SMALL LETTER Y WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'Z'	,0x1E05	,0x1E92	,0x0000	), // LATIN CAPITAL LETTER Z WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	L'z'	,0x1E05	,0x1E93	,0x0000	), // LATIN SMALL LETTER Z WITH DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x0021	,0x1E05	,0x203C	,0x0000	), // DOUBLE EXCLAMATION MARK
/*DOT_BELOW          */	DEADTRANS(	0x0029	,0x1E05	,0x1EB7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002B	,0x1E05	,0x203D	,0x0000	), // INTERROBANG
/*DOT_BELOW          */	DEADTRANS(	0x002C	,0x1E05	,0x1EE3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002E	,0x1E05	,0x1E69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_BELOW          */	DEADTRANS(	0x003F	,0x1E69	,0x203D	,0x0000	), // INTERROBANG
/*DOT_BELOW          */	DEADTRANS(	0x003A	,0x1E05	,0x205D	,0x0000	), // TRICOLON
/*DOT_BELOW          */	DEADTRANS(	0x003F	,0x1E05	,0x2049	,0x0000	), // EXCLAMATION QUESTION MARK
/*DOT_BELOW          */	DEADTRANS(	0x005E	,0x1E05	,0x1ED9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x005F	,0x1E05	,0x1E5D	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x00EA	,0x1E05	,0x1ED9	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x0229	,0x1E05	,0x1EE3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x022F	,0x1E05	,0x1E69	,0x0001	), // LATIN SMALL LETTER S WITH DOT BELOW AND DOT ABOVE
/*DOT_BELOW          */	DEADTRANS(	0x014F	,0x1E05	,0x1EB7	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x014D	,0x1E05	,0x1E5D	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW          */	DEADTRANS(	0x01A1	,0x1E05	,0x1EE3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*DOT_BELOW          */	DEADTRANS(	0x002D	,0x1E05	,0xA719	,0x0000	), // MODIFIER LETTER DOT HORIZONTAL BAR
/*DOT_BELOW          */	DEADTRANS(	0x002F	,0x1E05	,0xA718	,0x0000	), // MODIFIER LETTER DOT SLASH
/*DOT_BELOW          */	DEADTRANS(	0x007C	,0x1E05	,0xA717	,0x0000	), // MODIFIER LETTER DOT VERTICAL BAR
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'L'	,0x1E5D	,0x1E38	,0x0000	), // LATIN CAPITAL LETTER L WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'l'	,0x1E5D	,0x1E39	,0x0000	), // LATIN SMALL LETTER L WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'R'	,0x1E5D	,0x1E5C	,0x0000	), // LATIN CAPITAL LETTER R WITH DOT BELOW AND MACRON
/*DOT_BELOW&MACRON   */	DEADTRANS(	L'r'	,0x1E5D	,0x1E5D	,0x0000	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*DOUBLE             */	DEADTRANS(	0x0020	,0x003D	,0x030B	,0x0000	), // COMBINING DOUBLE ACUTE ACCENT
/*DOUBLE             */	DEADTRANS(	0x202F	,0x003D	,0xA78A	,0x0000	), // MODIFIER LETTER SHORT EQUALS SIGN
/*DOUBLE             */	DEADTRANS(	L'L'	,0x003D	,0x2C60	,0x0000	), // LATIN CAPITAL LETTER L WITH DOUBLE BAR
/*DOUBLE             */	DEADTRANS(	L'l'	,0x003D	,0x2C61	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE BAR
/*DOUBLE             */	DEADTRANS(	L'O'	,0x003D	,0x0150	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'o'	,0x003D	,0x0151	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'U'	,0x003D	,0x0170	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	L'u'	,0x003D	,0x0171	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	0x0021	,0x003D	,0x203C	,0x0001	), // DOUBLE EXCLAMATION MARK
/*DOUBLE             */	DEADTRANS(	0x0025	,0x003D	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*DOUBLE             */	DEADTRANS(	0x0027	,0x003D	,0x0151	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE             */	DEADTRANS(	0x002D	,0x003D	,0x2261	,0x0000	), // IDENTICAL TO
/*DOUBLE             */	DEADTRANS(	0x002F	,0x003D	,0x2288	,0x0001	), // NEITHER A SUBSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	L'i'	,0x2288	,0x2288	,0x0000	), // NEITHER A SUBSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	L'n'	,0x2288	,0x2289	,0x0000	), // NEITHER A SUPERSET OF NOR EQUAL TO
/*DOUBLE             */	DEADTRANS(	0x002D	,0x2288	,0x2262	,0x0000	), // NOT IDENTICAL TO
/*DOUBLE             */	DEADTRANS(	L'0'	,0x003D	,0x21D5	,0x0000	), // UP DOWN DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'1'	,0x003D	,0x21D9	,0x0000	), // SOUTH WEST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'2'	,0x003D	,0x21D3	,0x0000	), // DOWNWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'3'	,0x003D	,0x21D8	,0x0000	), // SOUTH EAST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'4'	,0x003D	,0x21D0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'5'	,0x003D	,0x21D4	,0x0000	), // LEFT RIGHT DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'6'	,0x003D	,0x21D2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'7'	,0x003D	,0x21D6	,0x0000	), // NORTH WEST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'8'	,0x003D	,0x21D1	,0x0000	), // UPWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	L'9'	,0x003D	,0x21D7	,0x0000	), // NORTH EAST DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003C	,0x003D	,0x21D0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003D	,0x003D	,0x2263	,0x0000	), // STRICTLY EQUIVALENT TO
/*DOUBLE             */	DEADTRANS(	0x003E	,0x003D	,0x21D2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE             */	DEADTRANS(	0x003F	,0x003D	,0x2047	,0x0000	), // DOUBLE QUESTION MARK
/*DOUBLE             */	DEADTRANS(	0x005F	,0x003D	,0x2017	,0x0000	), // DOUBLE LOW LINE
/*DOUBLE             */	DEADTRANS(	0x0060	,0x003D	,0x020D	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*DOUBLE             */	DEADTRANS(	0x007C	,0x0151	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0020	,0x0151	,0x030B	,0x0000	), // COMBINING DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x00A0	,0x0151	,0x02DD	,0x0000	), // DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x202F	,0x0151	,0x02DD	,0x0000	), // DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'A'	,0x0151	,0x00C3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'a'	,0x0151	,0x00E3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'E'	,0x0151	,0x018E	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'e'	,0x0151	,0x01DD	,0x0000	), // LATIN SMALL LETTER TURNED E
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'i'	,0x0151	,0x2286	,0x0000	), // SUBSET OF OR EQUAL TO
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'N'	,0x0151	,0x00D1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'n'	,0x0151	,0x00F1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'O'	,0x0151	,0x0150	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'o'	,0x0151	,0x0151	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L't'	,0x0151	,0x2021	,0x0000	), // DOUBLE DAGGER
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'U'	,0x0151	,0x0170	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'u'	,0x0151	,0x0171	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0152	,0x0151	,0x01FE	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0153	,0x0151	,0x01FF	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0022	,0x0151	,0x02EE	,0x0000	), // MODIFIER LETTER DOUBLE APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0023	,0x0151	,0x02EE	,0x0000	), // MODIFIER LETTER DOUBLE APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x0027	,0x0151	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x002B	,0x0151	,0x02F6	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE ACUTE ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'0'	,0x0151	,0x2195	,0x0000	), // UP DOWN ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'1'	,0x0151	,0x2199	,0x0000	), // SOUTH WEST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'2'	,0x0151	,0x2193	,0x0000	), // DOWNWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'3'	,0x0151	,0x2198	,0x0000	), // SOUTH EAST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'4'	,0x0151	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'5'	,0x0151	,0x2194	,0x0000	), // LEFT RIGHT ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'6'	,0x0151	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'7'	,0x0151	,0x2196	,0x0000	), // NORTH WEST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'8'	,0x0151	,0x2191	,0x0000	), // UPWARDS ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	L'9'	,0x0151	,0x2197	,0x0000	), // NORTH EAST ARROW
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x003D	,0x0151	,0x02BA	,0x0000	), // MODIFIER LETTER DOUBLE PRIME
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x00EA	,0x0151	,0x1AB0	,0x0000	), // COMBINING DOUBLED CIRCUMFLEX ACCENT
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x2019	,0x0151	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x2610	,0x0151	,0x2750	,0x0000	), // UPPER RIGHT DROP-SHADOWED WHITE SQUARE
/*DOUBLE_ACUTE_ACCENT*/	DEADTRANS(	0x222A	,0x0151	,0x2284	,0x0000	), // NOT A SUBSET OF
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0020	,0x020D	,0x030F	,0x0000	), // COMBINING DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00C0	,0x020D	,0x02F5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00E0	,0x020D	,0x02F5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00A0	,0x020D	,0x02F5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x202F	,0x020D	,0x02F5	,0x0000	), // MODIFIER LETTER MIDDLE DOUBLE GRAVE ACCENT
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'A'	,0x020D	,0x0200	,0x0000	), // LATIN CAPITAL LETTER A WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'a'	,0x020D	,0x0201	,0x0000	), // LATIN SMALL LETTER A WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'E'	,0x020D	,0x0204	,0x0000	), // LATIN CAPITAL LETTER E WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'e'	,0x020D	,0x0205	,0x0000	), // LATIN SMALL LETTER E WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'I'	,0x020D	,0x0208	,0x0000	), // LATIN CAPITAL LETTER I WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'i'	,0x020D	,0x0209	,0x0000	), // LATIN SMALL LETTER I WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'N'	,0x020D	,0x1DAF	,0x0000	), // MODIFIER LETTER SMALL N WITH RETROFLEX HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'n'	,0x020D	,0x0273	,0x0000	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'O'	,0x020D	,0x020C	,0x0000	), // LATIN CAPITAL LETTER O WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'o'	,0x020D	,0x020D	,0x0000	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'R'	,0x020D	,0x0210	,0x0000	), // LATIN CAPITAL LETTER R WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'r'	,0x020D	,0x0211	,0x0000	), // LATIN SMALL LETTER R WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'U'	,0x020D	,0x0214	,0x0000	), // LATIN CAPITAL LETTER U WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'u'	,0x020D	,0x0215	,0x0000	), // LATIN SMALL LETTER U WITH DOUBLE GRAVE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'W'	,0x020D	,0x2C72	,0x0000	), // LATIN CAPITAL LETTER W WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'w'	,0x020D	,0x2C73	,0x0000	), // LATIN SMALL LETTER W WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'Y'	,0x020D	,0x01B3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'y'	,0x020D	,0x01B4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0152	,0x020D	,0x00D8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0153	,0x020D	,0x00F8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x00F9	,0x020D	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x0027	,0x020D	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'0'	,0x020D	,0x21D5	,0x0000	), // UP DOWN DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'1'	,0x020D	,0x21D9	,0x0000	), // SOUTH WEST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'2'	,0x020D	,0x21D3	,0x0000	), // DOWNWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'3'	,0x020D	,0x21D8	,0x0000	), // SOUTH EAST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'4'	,0x020D	,0x21D0	,0x0000	), // LEFTWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'5'	,0x020D	,0x21D4	,0x0000	), // LEFT RIGHT DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'6'	,0x020D	,0x21D2	,0x0000	), // RIGHTWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'7'	,0x020D	,0x21D6	,0x0000	), // NORTH WEST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'8'	,0x020D	,0x21D1	,0x0000	), // UPWARDS DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	L'9'	,0x020D	,0x21D7	,0x0000	), // NORTH EAST DOUBLE ARROW
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x2019	,0x020D	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x2610	,0x020D	,0x274F	,0x0000	), // LOWER RIGHT DROP-SHADOWED WHITE SQUARE
/*DOUBLE_GRAVE_ACCENT*/	DEADTRANS(	0x222A	,0x020D	,0x2285	,0x0000	), // NOT A SUPERSET OF
/*DOUBLE_MIDDLE_TILDE*/	DEADTRANS(	L'l'	,0xAB38	,0xAB38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*DOUBLE_TILDE       */	DEADTRANS(	L'l'	,0x00D5	,0xAB38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*DOUBLE_TILDE       */	DEADTRANS(	0x003D	,0x00D5	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*G_DASIA            */	DEADTRANS(	0x00A0	,0x1F51	,0x1FFE	,0x0000	), // GREEK DASIA
/*G_DASIA            */	DEADTRANS(	0x202F	,0x1F51	,0x1FFE	,0x0000	), // GREEK DASIA
/*G_DASIA            */	DEADTRANS(	L'A'	,0x1F51	,0x1F09	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'a'	,0x1F51	,0x1F01	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'E'	,0x1F51	,0x1F19	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'e'	,0x1F51	,0x1F11	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'H'	,0x1F51	,0x1F29	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'h'	,0x1F51	,0x1F21	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'I'	,0x1F51	,0x1F39	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'i'	,0x1F51	,0x1F31	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'O'	,0x1F51	,0x1F49	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'o'	,0x1F51	,0x1F41	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'R'	,0x1F51	,0x1FEC	,0x0000	), // GREEK CAPITAL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'r'	,0x1F51	,0x1FE5	,0x0000	), // GREEK SMALL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'V'	,0x1F51	,0x1F69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'v'	,0x1F51	,0x1F61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'W'	,0x1F51	,0x1F69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'w'	,0x1F51	,0x1F61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'Y'	,0x1F51	,0x1F59	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	L'y'	,0x1F51	,0x1F51	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x1F70	,0x1F51	,0x1F53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA            */	DEADTRANS(	0x1F7D	,0x1F51	,0x1F55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA            */	DEADTRANS(	0x1FC3	,0x1F51	,0x1FA1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA            */	DEADTRANS(	0x1FC6	,0x1F51	,0x1F57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA            */	DEADTRANS(	0x002C	,0x1F51	,0x1F55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA            */	DEADTRANS(	0x003B	,0x1F51	,0x1FA1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA            */	DEADTRANS(	0x0060	,0x1F51	,0x1F53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA            */	DEADTRANS(	0x007E	,0x1F51	,0x1F57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA            */	DEADTRANS(	0x0391	,0x1F51	,0x1F09	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03B1	,0x1F51	,0x1F01	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0395	,0x1F51	,0x1F19	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03B5	,0x1F51	,0x1F11	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0397	,0x1F51	,0x1F29	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03B7	,0x1F51	,0x1F21	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x0399	,0x1F51	,0x1F39	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03B9	,0x1F51	,0x1F31	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x039F	,0x1F51	,0x1F49	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03BF	,0x1F51	,0x1F41	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03A1	,0x1F51	,0x1FEC	,0x0000	), // GREEK CAPITAL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03C1	,0x1F51	,0x1FE5	,0x0000	), // GREEK SMALL LETTER RHO WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03A5	,0x1F51	,0x1F59	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03C5	,0x1F51	,0x1F51	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03A9	,0x1F51	,0x1F69	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA
/*G_DASIA            */	DEADTRANS(	0x03C9	,0x1F51	,0x1F61	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA
/*G_DASIA&I          */	DEADTRANS(	L'A'	,0x1FA1	,0x1F89	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'a'	,0x1FA1	,0x1F81	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'H'	,0x1FA1	,0x1F99	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'h'	,0x1FA1	,0x1F91	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'V'	,0x1FA1	,0x1FA9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'v'	,0x1FA1	,0x1FA1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'W'	,0x1FA1	,0x1FA9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	L'w'	,0x1FA1	,0x1FA1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x1F70	,0x1FA1	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x1F7D	,0x1FA1	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x002C	,0x1FA1	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0060	,0x1FA1	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0391	,0x1FA1	,0x1F89	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03B1	,0x1FA1	,0x1F81	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x0397	,0x1FA1	,0x1F99	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03B7	,0x1FA1	,0x1F91	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03A9	,0x1FA1	,0x1FA9	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PROSGEGRAMMENI
/*G_DASIA&I          */	DEADTRANS(	0x03C9	,0x1FA1	,0x1FA1	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x00A0	,0x1F55	,0x1FDE	,0x0000	), // GREEK DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'A'	,0x1F55	,0x1F0D	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'a'	,0x1F55	,0x1F05	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'E'	,0x1F55	,0x1F1D	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'e'	,0x1F55	,0x1F15	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'H'	,0x1F55	,0x1F2D	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'h'	,0x1F55	,0x1F25	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'I'	,0x1F55	,0x1F3D	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'i'	,0x1F55	,0x1F35	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'O'	,0x1F55	,0x1F4D	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'o'	,0x1F55	,0x1F45	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'V'	,0x1F55	,0x1F6D	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'v'	,0x1F55	,0x1F65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'W'	,0x1F55	,0x1F6D	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'w'	,0x1F55	,0x1F65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'Y'	,0x1F55	,0x1F5D	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	L'y'	,0x1F55	,0x1F55	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x1FC3	,0x1F55	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x003B	,0x1F55	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA       */	DEADTRANS(	0x0391	,0x1F55	,0x1F0D	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03B1	,0x1F55	,0x1F05	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0395	,0x1F55	,0x1F1D	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03B5	,0x1F55	,0x1F15	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0397	,0x1F55	,0x1F2D	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03B7	,0x1F55	,0x1F25	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x0399	,0x1F55	,0x1F3D	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03B9	,0x1F55	,0x1F35	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x039F	,0x1F55	,0x1F4D	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03BF	,0x1F55	,0x1F45	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03A5	,0x1F55	,0x1F5D	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03C5	,0x1F55	,0x1F55	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03A9	,0x1F55	,0x1F6D	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA       */	DEADTRANS(	0x03C9	,0x1F55	,0x1F65	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x0391	,0x1FA5	,0x1F8D	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x0397	,0x1FA5	,0x1F9D	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03A9	,0x1FA5	,0x1FAD	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03B1	,0x1FA5	,0x1F85	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03B7	,0x1FA5	,0x1F95	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	0x03C9	,0x1FA5	,0x1FA5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'A'	,0x1FA5	,0x1F8D	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'H'	,0x1FA5	,0x1F9D	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'V'	,0x1FA5	,0x1FAD	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'W'	,0x1FA5	,0x1FAD	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND OXIA AND PROSGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'a'	,0x1FA5	,0x1F85	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'h'	,0x1FA5	,0x1F95	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'v'	,0x1FA5	,0x1FA5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&OXIA&I     */	DEADTRANS(	L'w'	,0x1FA5	,0x1FA5	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x00A0	,0x1F57	,0x1FDF	,0x0000	), // GREEK DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x202F	,0x1F57	,0x1FDF	,0x0000	), // GREEK DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'A'	,0x1F57	,0x1F0F	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'a'	,0x1F57	,0x1F07	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'H'	,0x1F57	,0x1F2F	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'h'	,0x1F57	,0x1F27	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'I'	,0x1F57	,0x1F3F	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'i'	,0x1F57	,0x1F37	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'V'	,0x1F57	,0x1F6F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'v'	,0x1F57	,0x1F67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'W'	,0x1F57	,0x1F6F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'w'	,0x1F57	,0x1F67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'Y'	,0x1F57	,0x1F5F	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	L'y'	,0x1F57	,0x1F57	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x1FC3	,0x1F57	,0x1F87	,0x0001	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x003B	,0x1F57	,0x1F87	,0x0001	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0391	,0x1F57	,0x1F0F	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03B1	,0x1F57	,0x1F07	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0397	,0x1F57	,0x1F2F	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03B7	,0x1F57	,0x1F27	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x0399	,0x1F57	,0x1F3F	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03B9	,0x1F57	,0x1F37	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03A5	,0x1F57	,0x1F5F	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03C5	,0x1F57	,0x1F57	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03A9	,0x1F57	,0x1F6F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI       */	DEADTRANS(	0x03C9	,0x1F57	,0x1F67	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'A'	,0x1F87	,0x1F8F	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'H'	,0x1F87	,0x1F9F	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'V'	,0x1F87	,0x1FAF	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'W'	,0x1F87	,0x1FAF	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'a'	,0x1F87	,0x1F87	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'h'	,0x1F87	,0x1F97	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'v'	,0x1F87	,0x1FA7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	L'w'	,0x1F87	,0x1FA7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x0391	,0x1F87	,0x1F8F	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03B1	,0x1F87	,0x1F87	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x0397	,0x1F87	,0x1F9F	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03B7	,0x1F87	,0x1F97	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03A9	,0x1F87	,0x1FAF	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND PERISPOMENI AND PROSGEGRAMMENI
/*G_DASIA&PERI&I     */	DEADTRANS(	0x03C9	,0x1F87	,0x1FA7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND PERISPOMENI AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x00A0	,0x1F53	,0x1FDD	,0x0000	), // GREEK DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'A'	,0x1F53	,0x1F0B	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'a'	,0x1F53	,0x1F03	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'E'	,0x1F53	,0x1F1B	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'e'	,0x1F53	,0x1F13	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'H'	,0x1F53	,0x1F2B	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'h'	,0x1F53	,0x1F23	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'I'	,0x1F53	,0x1F3B	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'i'	,0x1F53	,0x1F33	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'O'	,0x1F53	,0x1F4B	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'o'	,0x1F53	,0x1F43	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'V'	,0x1F53	,0x1F6B	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'v'	,0x1F53	,0x1F63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'W'	,0x1F53	,0x1F6B	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'w'	,0x1F53	,0x1F63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'Y'	,0x1F53	,0x1F5B	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	L'y'	,0x1F53	,0x1F53	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x1FC3	,0x1F53	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x003B	,0x1F53	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA      */	DEADTRANS(	0x0391	,0x1F53	,0x1F0B	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03B1	,0x1F53	,0x1F03	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0395	,0x1F53	,0x1F1B	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03B5	,0x1F53	,0x1F13	,0x0000	), // GREEK SMALL LETTER EPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0397	,0x1F53	,0x1F2B	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03B7	,0x1F53	,0x1F23	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x0399	,0x1F53	,0x1F3B	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03B9	,0x1F53	,0x1F33	,0x0000	), // GREEK SMALL LETTER IOTA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x039F	,0x1F53	,0x1F4B	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03BF	,0x1F53	,0x1F43	,0x0000	), // GREEK SMALL LETTER OMICRON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03A5	,0x1F53	,0x1F5B	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03C5	,0x1F53	,0x1F53	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03A9	,0x1F53	,0x1F6B	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA      */	DEADTRANS(	0x03C9	,0x1F53	,0x1F63	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'A'	,0x1F93	,0x1F8B	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'H'	,0x1F93	,0x1F9B	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'V'	,0x1F93	,0x1FAB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'W'	,0x1F93	,0x1FAB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'a'	,0x1F93	,0x1F83	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'h'	,0x1F93	,0x1F93	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'v'	,0x1F93	,0x1FA3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	L'w'	,0x1F93	,0x1FA3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x0391	,0x1F93	,0x1F8B	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03B1	,0x1F93	,0x1F83	,0x0000	), // GREEK SMALL LETTER ALPHA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x0397	,0x1F93	,0x1F9B	,0x0000	), // GREEK CAPITAL LETTER ETA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03B7	,0x1F93	,0x1F93	,0x0000	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03A9	,0x1F93	,0x1FAB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH DASIA AND VARIA AND PROSGEGRAMMENI
/*G_DASIA&VARIA&I    */	DEADTRANS(	0x03C9	,0x1F93	,0x1FA3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x0020	,0x03CA	,0x0308	,0x0000	), // COMBINING DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	0x00A0	,0x03CA	,0x00A8	,0x0000	), // DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	0x202F	,0x03CA	,0x00A8	,0x0000	), // DIAERESIS
/*G_DIALYTIKA        */	DEADTRANS(	L'I'	,0x03CA	,0x03AA	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'i'	,0x03CA	,0x03CA	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'Y'	,0x03CA	,0x03AB	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	L'y'	,0x03CA	,0x03CB	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03CC	,0x03CA	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA        */	DEADTRANS(	0x1F70	,0x03CA	,0x1FE2	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA        */	DEADTRANS(	0x1F7D	,0x03CA	,0x1FE3	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA        */	DEADTRANS(	0x1FC6	,0x03CA	,0x1FE7	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x002C	,0x03CA	,0x1FE3	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA        */	DEADTRANS(	0x0027	,0x03CA	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA        */	DEADTRANS(	0x0060	,0x03CA	,0x1FE2	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA        */	DEADTRANS(	0x007E	,0x03CA	,0x1FE7	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA        */	DEADTRANS(	0x0399	,0x03CA	,0x03AA	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03B9	,0x03CA	,0x03CA	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03A5	,0x03CA	,0x03AB	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA        */	DEADTRANS(	0x03C5	,0x03CA	,0x03CB	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x00A0	,0x1FE3	,0x1FEE	,0x0000	), // GREEK DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	L'i'	,0x1FE3	,0x1FD3	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	L'y'	,0x1FE3	,0x1FE3	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x03B9	,0x1FE3	,0x1FD3	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&OXIA   */	DEADTRANS(	0x03C5	,0x1FE3	,0x1FE3	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND OXIA
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x00A0	,0x1FE7	,0x1FC1	,0x0000	), // GREEK DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	L'i'	,0x1FE7	,0x1FD7	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	L'y'	,0x1FE7	,0x1FE7	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x03B9	,0x1FE7	,0x1FD7	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&PERI   */	DEADTRANS(	0x03C5	,0x1FE7	,0x1FE7	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND PERISPOMENI
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x0020	,0x0390	,0x0344	,0x0000	), // COMBINING GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x00A0	,0x0390	,0x0385	,0x0000	), // GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x202F	,0x0390	,0x0385	,0x0000	), // GREEK DIALYTIKA TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	L'i'	,0x0390	,0x0390	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	L'y'	,0x0390	,0x03B0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x03B9	,0x0390	,0x0390	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&TONOS  */	DEADTRANS(	0x03C5	,0x0390	,0x03B0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x00A0	,0x1FE2	,0x1FED	,0x0000	), // GREEK DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	L'i'	,0x1FE2	,0x1FD2	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	L'y'	,0x1FE2	,0x1FE2	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x03B9	,0x1FE2	,0x1FD2	,0x0000	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND VARIA
/*G_DIALYTIKA&VARIA  */	DEADTRANS(	0x03C5	,0x1FE2	,0x1FE2	,0x0000	), // GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND VARIA
/*G_KORONIS          */	DEADTRANS(	0x0020	,0x1FBD	,0x0343	,0x0000	), // COMBINING GREEK KORONIS
/*G_KORONIS          */	DEADTRANS(	0x00A0	,0x1FBD	,0x1FBD	,0x0000	), // GREEK KORONIS
/*G_MACRON           */	DEADTRANS(	0x0020	,0x1FB1	,0x0304	,0x0000	), // COMBINING MACRON
/*G_MACRON           */	DEADTRANS(	0x00A0	,0x1FB1	,0x00AF	,0x0000	), // MACRON
/*G_MACRON           */	DEADTRANS(	0x202F	,0x1FB1	,0x02C9	,0x0000	), // MODIFIER LETTER MACRON
/*G_MACRON           */	DEADTRANS(	L'A'	,0x1FB1	,0x1FB9	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'a'	,0x1FB1	,0x1FB1	,0x0000	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'I'	,0x1FB1	,0x1FD9	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'i'	,0x1FB1	,0x1FD1	,0x0000	), // GREEK SMALL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'Y'	,0x1FB1	,0x1FE9	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	L'y'	,0x1FB1	,0x1FE1	,0x0000	), // GREEK SMALL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x0391	,0x1FB1	,0x1FB9	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03B1	,0x1FB1	,0x1FB1	,0x0000	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x0399	,0x1FB1	,0x1FD9	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03B9	,0x1FB1	,0x1FD1	,0x0000	), // GREEK SMALL LETTER IOTA WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03A5	,0x1FB1	,0x1FE9	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH MACRON
/*G_MACRON           */	DEADTRANS(	0x03C5	,0x1FB1	,0x1FE1	,0x0000	), // GREEK SMALL LETTER UPSILON WITH MACRON
/*G_OXIA             */	DEADTRANS(	0x0020	,0x1F7D	,0x0301	,0x0000	), // COMBINING ACUTE ACCENT
/*G_OXIA             */	DEADTRANS(	0x00A0	,0x1F7D	,0x1FFD	,0x0000	), // GREEK OXIA
/*G_OXIA             */	DEADTRANS(	0x202F	,0x1F7D	,0x1FFD	,0x0000	), // GREEK OXIA
/*G_OXIA             */	DEADTRANS(	L'A'	,0x1F7D	,0x1FBB	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'a'	,0x1F7D	,0x1F71	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'E'	,0x1F7D	,0x1FC9	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'e'	,0x1F7D	,0x1F73	,0x0000	), // GREEK SMALL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'H'	,0x1F7D	,0x1FCB	,0x0000	), // GREEK CAPITAL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'h'	,0x1F7D	,0x1F75	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'I'	,0x1F7D	,0x1FDB	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'i'	,0x1F7D	,0x1F77	,0x0000	), // GREEK SMALL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'O'	,0x1F7D	,0x1FF9	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'o'	,0x1F7D	,0x1F79	,0x0000	), // GREEK SMALL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'V'	,0x1F7D	,0x1FFB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'v'	,0x1F7D	,0x1F7D	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'W'	,0x1F7D	,0x1FFB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'w'	,0x1F7D	,0x1F7D	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'Y'	,0x1F7D	,0x1FEB	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	L'y'	,0x1F7D	,0x1F7B	,0x0000	), // GREEK SMALL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x1F10	,0x1F7D	,0x1F14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_OXIA             */	DEADTRANS(	0x1F51	,0x1F7D	,0x1F55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_OXIA             */	DEADTRANS(	0x003C	,0x1F7D	,0x1F55	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA
/*G_OXIA             */	DEADTRANS(	0x003E	,0x1F7D	,0x1F14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_OXIA             */	DEADTRANS(	0x0391	,0x1F7D	,0x1FBB	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03B1	,0x1F7D	,0x1F71	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0395	,0x1F7D	,0x1FC9	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03B5	,0x1F7D	,0x1F73	,0x0000	), // GREEK SMALL LETTER EPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0397	,0x1F7D	,0x1FCB	,0x0000	), // GREEK CAPITAL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03B7	,0x1F7D	,0x1F75	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x0399	,0x1F7D	,0x1FDB	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03B9	,0x1F7D	,0x1F77	,0x0000	), // GREEK SMALL LETTER IOTA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x039F	,0x1F7D	,0x1FF9	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03BF	,0x1F7D	,0x1F79	,0x0000	), // GREEK SMALL LETTER OMICRON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03A5	,0x1F7D	,0x1FEB	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03C5	,0x1F7D	,0x1F7B	,0x0000	), // GREEK SMALL LETTER UPSILON WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03A9	,0x1F7D	,0x1FFB	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH OXIA
/*G_OXIA             */	DEADTRANS(	0x03C9	,0x1F7D	,0x1F7D	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*G_OXIA&I           */	DEADTRANS(	L'a'	,0x1FF4	,0x1FB4	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'h'	,0x1FF4	,0x1FC4	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'v'	,0x1FF4	,0x1FF4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	L'w'	,0x1FF4	,0x1FF4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x1F10	,0x1FF4	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x1F51	,0x1FF4	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x003C	,0x1FF4	,0x1FA5	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x003E	,0x1FF4	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03B1	,0x1FF4	,0x1FB4	,0x0000	), // GREEK SMALL LETTER ALPHA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03B7	,0x1FF4	,0x1FC4	,0x0000	), // GREEK SMALL LETTER ETA WITH OXIA AND YPOGEGRAMMENI
/*G_OXIA&I           */	DEADTRANS(	0x03C9	,0x1FF4	,0x1FF4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x0020	,0x1FC6	,0x0342	,0x0000	), // COMBINING GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x00A0	,0x1FC6	,0x1FC0	,0x0000	), // GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x202F	,0x1FC6	,0x1FC0	,0x0000	), // GREEK PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'a'	,0x1FC6	,0x1FB6	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'h'	,0x1FC6	,0x1FC6	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'i'	,0x1FC6	,0x1FD6	,0x0000	), // GREEK SMALL LETTER IOTA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'v'	,0x1FC6	,0x1FF6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'w'	,0x1FC6	,0x1FF6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	L'y'	,0x1FC6	,0x1FE6	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x1F10	,0x1FC6	,0x1F26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x1F51	,0x1FC6	,0x1F57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x003C	,0x1FC6	,0x1F57	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x003E	,0x1FC6	,0x1F26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03B1	,0x1FC6	,0x1FB6	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03B7	,0x1FC6	,0x1FC6	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03B9	,0x1FC6	,0x1FD6	,0x0000	), // GREEK SMALL LETTER IOTA WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03C5	,0x1FC6	,0x1FE6	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PERISPOMENI
/*G_PERISPOMENI      */	DEADTRANS(	0x03C9	,0x1FC6	,0x1FF6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'a'	,0x1FC7	,0x1FB7	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'h'	,0x1FC7	,0x1FC7	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'v'	,0x1FC7	,0x1FF7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	L'w'	,0x1FC7	,0x1FF7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03B1	,0x1FC7	,0x1FB7	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03B7	,0x1FC7	,0x1FC7	,0x0000	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PERISPOMENI&I    */	DEADTRANS(	0x03C9	,0x1FC7	,0x1FF7	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x00A0	,0x1F10	,0x1FBF	,0x0000	), // GREEK PSILI
/*G_PSILI            */	DEADTRANS(	0x202F	,0x1F10	,0x1FBF	,0x0000	), // GREEK PSILI
/*G_PSILI            */	DEADTRANS(	L'A'	,0x1F10	,0x1F08	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'a'	,0x1F10	,0x1F00	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'E'	,0x1F10	,0x1F18	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'e'	,0x1F10	,0x1F10	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'H'	,0x1F10	,0x1F28	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'h'	,0x1F10	,0x1F20	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'I'	,0x1F10	,0x1F38	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'i'	,0x1F10	,0x1F30	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'O'	,0x1F10	,0x1F48	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'o'	,0x1F10	,0x1F40	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'r'	,0x1F10	,0x1FE4	,0x0000	), // GREEK SMALL LETTER RHO WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'V'	,0x1F10	,0x1F68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'v'	,0x1F10	,0x1F60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'W'	,0x1F10	,0x1F68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'w'	,0x1F10	,0x1F60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	L'y'	,0x1F10	,0x1F50	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x1F70	,0x1F10	,0x1F12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI            */	DEADTRANS(	0x1F7D	,0x1F10	,0x1F14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI            */	DEADTRANS(	0x1FC3	,0x1F10	,0x1F90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x1FC6	,0x1F10	,0x1F26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI            */	DEADTRANS(	0x002C	,0x1F10	,0x1F14	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI            */	DEADTRANS(	0x003B	,0x1F10	,0x1F90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI            */	DEADTRANS(	0x0060	,0x1F10	,0x1F12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI            */	DEADTRANS(	0x007E	,0x1F10	,0x1F26	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI            */	DEADTRANS(	0x0391	,0x1F10	,0x1F08	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03B1	,0x1F10	,0x1F00	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0395	,0x1F10	,0x1F18	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03B5	,0x1F10	,0x1F10	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0397	,0x1F10	,0x1F28	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03B7	,0x1F10	,0x1F20	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x0399	,0x1F10	,0x1F38	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03B9	,0x1F10	,0x1F30	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x039F	,0x1F10	,0x1F48	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03BF	,0x1F10	,0x1F40	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03C1	,0x1F10	,0x1FE4	,0x0000	), // GREEK SMALL LETTER RHO WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03C5	,0x1F10	,0x1F50	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03A9	,0x1F10	,0x1F68	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI
/*G_PSILI            */	DEADTRANS(	0x03C9	,0x1F10	,0x1F60	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI
/*G_PSILI&I          */	DEADTRANS(	L'A'	,0x1F90	,0x1F88	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'a'	,0x1F90	,0x1F80	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'H'	,0x1F90	,0x1F98	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'h'	,0x1F90	,0x1F90	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'V'	,0x1F90	,0x1FA8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'v'	,0x1F90	,0x1FA0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'W'	,0x1F90	,0x1FA8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	L'w'	,0x1F90	,0x1FA0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x1F70	,0x1F90	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x1F7D	,0x1F90	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x002C	,0x1F90	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0060	,0x1F90	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0391	,0x1F90	,0x1F88	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03B1	,0x1F90	,0x1F80	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x0397	,0x1F90	,0x1F98	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03B7	,0x1F90	,0x1F90	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03A9	,0x1F90	,0x1FA8	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PROSGEGRAMMENI
/*G_PSILI&I          */	DEADTRANS(	0x03C9	,0x1F90	,0x1FA0	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x00A0	,0x1F14	,0x1FCE	,0x0000	), // GREEK PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'A'	,0x1F14	,0x1F0C	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'a'	,0x1F14	,0x1F04	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'E'	,0x1F14	,0x1F1C	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'e'	,0x1F14	,0x1F14	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'H'	,0x1F14	,0x1F2C	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'h'	,0x1F14	,0x1F24	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'I'	,0x1F14	,0x1F3C	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'i'	,0x1F14	,0x1F34	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'O'	,0x1F14	,0x1F4C	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'o'	,0x1F14	,0x1F44	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'V'	,0x1F14	,0x1F6C	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'v'	,0x1F14	,0x1F64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'W'	,0x1F14	,0x1F6C	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'w'	,0x1F14	,0x1F64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	L'y'	,0x1F14	,0x1F54	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x1FC3	,0x1F14	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x003B	,0x1F14	,0x1F84	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA       */	DEADTRANS(	0x0391	,0x1F14	,0x1F0C	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03B1	,0x1F14	,0x1F04	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0395	,0x1F14	,0x1F1C	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03B5	,0x1F14	,0x1F14	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0397	,0x1F14	,0x1F2C	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03B7	,0x1F14	,0x1F24	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x0399	,0x1F14	,0x1F3C	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03B9	,0x1F14	,0x1F34	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x039F	,0x1F14	,0x1F4C	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03BF	,0x1F14	,0x1F44	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03C5	,0x1F14	,0x1F54	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03A9	,0x1F14	,0x1F6C	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA       */	DEADTRANS(	0x03C9	,0x1F14	,0x1F64	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'A'	,0x1F84	,0x1F8C	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'a'	,0x1F84	,0x1F84	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'H'	,0x1F84	,0x1F9C	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'h'	,0x1F84	,0x1F94	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'V'	,0x1F84	,0x1FAC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'v'	,0x1F84	,0x1FA4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'W'	,0x1F84	,0x1FAC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	L'w'	,0x1F84	,0x1FA4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x0391	,0x1F84	,0x1F8C	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03B1	,0x1F84	,0x1F84	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x0397	,0x1F84	,0x1F9C	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03B7	,0x1F84	,0x1F94	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03A9	,0x1F84	,0x1FAC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND OXIA AND PROSGEGRAMMENI
/*G_PSILI&OXIA&I     */	DEADTRANS(	0x03C9	,0x1F84	,0x1FA4	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND OXIA AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x00A0	,0x1F26	,0x1FCF	,0x0000	), // GREEK PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x202F	,0x1F26	,0x1FCF	,0x0000	), // GREEK PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'A'	,0x1F26	,0x1F0E	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'a'	,0x1F26	,0x1F06	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'H'	,0x1F26	,0x1F2E	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'h'	,0x1F26	,0x1F26	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'I'	,0x1F26	,0x1F3E	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'i'	,0x1F26	,0x1F36	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'V'	,0x1F26	,0x1F6E	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'v'	,0x1F26	,0x1F66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'W'	,0x1F26	,0x1F6E	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'w'	,0x1F26	,0x1F66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	L'y'	,0x1F26	,0x1F56	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x1FC3	,0x1F26	,0x1FA6	,0x0001	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x003B	,0x1F26	,0x1FA6	,0x0001	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0391	,0x1F26	,0x1F0E	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03B1	,0x1F26	,0x1F06	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0397	,0x1F26	,0x1F2E	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03B7	,0x1F26	,0x1F26	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x0399	,0x1F26	,0x1F3E	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03B9	,0x1F26	,0x1F36	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03C5	,0x1F26	,0x1F56	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03A9	,0x1F26	,0x1F6E	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI       */	DEADTRANS(	0x03C9	,0x1F26	,0x1F66	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'A'	,0x1FA6	,0x1F8E	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'a'	,0x1FA6	,0x1F86	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'H'	,0x1FA6	,0x1F9E	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'h'	,0x1FA6	,0x1F96	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'V'	,0x1FA6	,0x1FAE	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'v'	,0x1FA6	,0x1FA6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'W'	,0x1FA6	,0x1FAE	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	L'w'	,0x1FA6	,0x1FA6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x0391	,0x1FA6	,0x1F8E	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03B1	,0x1FA6	,0x1F86	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x0397	,0x1FA6	,0x1F9E	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03B7	,0x1FA6	,0x1F96	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03A9	,0x1FA6	,0x1FAE	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND PERISPOMENI AND PROSGEGRAMMENI
/*G_PSILI&PERI&I     */	DEADTRANS(	0x03C9	,0x1FA6	,0x1FA6	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND PERISPOMENI AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x00A0	,0x1F12	,0x1FCD	,0x0000	), // GREEK PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'A'	,0x1F12	,0x1F0A	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'a'	,0x1F12	,0x1F02	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'E'	,0x1F12	,0x1F1A	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'e'	,0x1F12	,0x1F12	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'H'	,0x1F12	,0x1F2A	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'h'	,0x1F12	,0x1F22	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'I'	,0x1F12	,0x1F3A	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'i'	,0x1F12	,0x1F32	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'O'	,0x1F12	,0x1F4A	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'o'	,0x1F12	,0x1F42	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'V'	,0x1F12	,0x1F6A	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'v'	,0x1F12	,0x1F62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'W'	,0x1F12	,0x1F6A	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'w'	,0x1F12	,0x1F62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	L'y'	,0x1F12	,0x1F52	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x1FC3	,0x1F12	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x003B	,0x1F12	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA      */	DEADTRANS(	0x0391	,0x1F12	,0x1F0A	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03B1	,0x1F12	,0x1F02	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0395	,0x1F12	,0x1F1A	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03B5	,0x1F12	,0x1F12	,0x0000	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0397	,0x1F12	,0x1F2A	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03B7	,0x1F12	,0x1F22	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x0399	,0x1F12	,0x1F3A	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03B9	,0x1F12	,0x1F32	,0x0000	), // GREEK SMALL LETTER IOTA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x039F	,0x1F12	,0x1F4A	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03BF	,0x1F12	,0x1F42	,0x0000	), // GREEK SMALL LETTER OMICRON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03C5	,0x1F12	,0x1F52	,0x0000	), // GREEK SMALL LETTER UPSILON WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03A9	,0x1F12	,0x1F6A	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA      */	DEADTRANS(	0x03C9	,0x1F12	,0x1F62	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'A'	,0x1F82	,0x1F8A	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'a'	,0x1F82	,0x1F82	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'H'	,0x1F82	,0x1F9A	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'h'	,0x1F82	,0x1F92	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'V'	,0x1F82	,0x1FAA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'v'	,0x1F82	,0x1FA2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'W'	,0x1F82	,0x1FAA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	L'w'	,0x1F82	,0x1FA2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x0391	,0x1F82	,0x1F8A	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03B1	,0x1F82	,0x1F82	,0x0000	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x0397	,0x1F82	,0x1F9A	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03B7	,0x1F82	,0x1F92	,0x0000	), // GREEK SMALL LETTER ETA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03A9	,0x1F82	,0x1FAA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PSILI AND VARIA AND PROSGEGRAMMENI
/*G_PSILI&VARIA&I    */	DEADTRANS(	0x03C9	,0x1F82	,0x1FA2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_TONOS            */	DEADTRANS(	0x0020	,0x03CC	,0x0301	,0x0000	), // COMBINING ACUTE ACCENT
/*G_TONOS            */	DEADTRANS(	0x00A0	,0x03CC	,0x0384	,0x0000	), // GREEK TONOS
/*G_TONOS            */	DEADTRANS(	0x202F	,0x03CC	,0x0384	,0x0000	), // GREEK TONOS
/*G_TONOS            */	DEADTRANS(	L'A'	,0x03CC	,0x0386	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'a'	,0x03CC	,0x03AC	,0x0000	), // GREEK SMALL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'E'	,0x03CC	,0x0388	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'e'	,0x03CC	,0x03AD	,0x0000	), // GREEK SMALL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'H'	,0x03CC	,0x0389	,0x0000	), // GREEK CAPITAL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'h'	,0x03CC	,0x03AE	,0x0000	), // GREEK SMALL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'I'	,0x03CC	,0x038A	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'i'	,0x03CC	,0x03AF	,0x0000	), // GREEK SMALL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'O'	,0x03CC	,0x038C	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'o'	,0x03CC	,0x03CC	,0x0000	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'V'	,0x03CC	,0x038F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'v'	,0x03CC	,0x03CE	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'W'	,0x03CC	,0x038F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'w'	,0x03CC	,0x03CE	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'Y'	,0x03CC	,0x038E	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	L'y'	,0x03CC	,0x03CD	,0x0000	), // GREEK SMALL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03CA	,0x03CC	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_TONOS            */	DEADTRANS(	0x003A	,0x03CC	,0x0390	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS
/*G_TONOS            */	DEADTRANS(	0x0391	,0x03CC	,0x0386	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03B1	,0x03CC	,0x03AC	,0x0000	), // GREEK SMALL LETTER ALPHA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0395	,0x03CC	,0x0388	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03B5	,0x03CC	,0x03AD	,0x0000	), // GREEK SMALL LETTER EPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0397	,0x03CC	,0x0389	,0x0000	), // GREEK CAPITAL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03B7	,0x03CC	,0x03AE	,0x0000	), // GREEK SMALL LETTER ETA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x0399	,0x03CC	,0x038A	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03B9	,0x03CC	,0x03AF	,0x0000	), // GREEK SMALL LETTER IOTA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x039F	,0x03CC	,0x038C	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03BF	,0x03CC	,0x03CC	,0x0000	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03A5	,0x03CC	,0x038E	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03C5	,0x03CC	,0x03CD	,0x0000	), // GREEK SMALL LETTER UPSILON WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03A9	,0x03CC	,0x038F	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH TONOS
/*G_TONOS            */	DEADTRANS(	0x03C9	,0x03CC	,0x03CE	,0x0000	), // GREEK SMALL LETTER OMEGA WITH TONOS
/*G_VARIA            */	DEADTRANS(	0x0020	,0x1F70	,0x0300	,0x0000	), // COMBINING GRAVE ACCENT
/*G_VARIA            */	DEADTRANS(	0x00A0	,0x1F70	,0x1FEF	,0x0000	), // GREEK VARIA
/*G_VARIA            */	DEADTRANS(	0x202F	,0x1F70	,0x1FEF	,0x0000	), // GREEK VARIA
/*G_VARIA            */	DEADTRANS(	L'A'	,0x1F70	,0x1FBA	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'a'	,0x1F70	,0x1F70	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'E'	,0x1F70	,0x1FC8	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'e'	,0x1F70	,0x1F72	,0x0000	), // GREEK SMALL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'H'	,0x1F70	,0x1FCA	,0x0000	), // GREEK CAPITAL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'h'	,0x1F70	,0x1F74	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'I'	,0x1F70	,0x1FDA	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'i'	,0x1F70	,0x1F76	,0x0000	), // GREEK SMALL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'O'	,0x1F70	,0x1FF8	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'o'	,0x1F70	,0x1F78	,0x0000	), // GREEK SMALL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'V'	,0x1F70	,0x1FFA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'v'	,0x1F70	,0x1F7C	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'W'	,0x1F70	,0x1FFA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'w'	,0x1F70	,0x1F7C	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'Y'	,0x1F70	,0x1FEA	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	L'y'	,0x1F70	,0x1F7A	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x1F10	,0x1F70	,0x1F12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_VARIA            */	DEADTRANS(	0x1F51	,0x1F70	,0x1F53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_VARIA            */	DEADTRANS(	0x003C	,0x1F70	,0x1F53	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA
/*G_VARIA            */	DEADTRANS(	0x003E	,0x1F70	,0x1F12	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI AND VARIA
/*G_VARIA            */	DEADTRANS(	0x0391	,0x1F70	,0x1FBA	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03B1	,0x1F70	,0x1F70	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0395	,0x1F70	,0x1FC8	,0x0000	), // GREEK CAPITAL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03B5	,0x1F70	,0x1F72	,0x0000	), // GREEK SMALL LETTER EPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0397	,0x1F70	,0x1FCA	,0x0000	), // GREEK CAPITAL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03B7	,0x1F70	,0x1F74	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x0399	,0x1F70	,0x1FDA	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03B9	,0x1F70	,0x1F76	,0x0000	), // GREEK SMALL LETTER IOTA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x039F	,0x1F70	,0x1FF8	,0x0000	), // GREEK CAPITAL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03BF	,0x1F70	,0x1F78	,0x0000	), // GREEK SMALL LETTER OMICRON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03A5	,0x1F70	,0x1FEA	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03C5	,0x1F70	,0x1F7A	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03A9	,0x1F70	,0x1FFA	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH VARIA
/*G_VARIA            */	DEADTRANS(	0x03C9	,0x1F70	,0x1F7C	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA
/*G_VARIA&I          */	DEADTRANS(	L'a'	,0x1FB2	,0x1FB2	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'h'	,0x1FB2	,0x1FC2	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'v'	,0x1FB2	,0x1FF2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	L'w'	,0x1FB2	,0x1FF2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x1F10	,0x1FB2	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x1F51	,0x1FB2	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x003C	,0x1FB2	,0x1F93	,0x0001	), // GREEK SMALL LETTER ETA WITH DASIA AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x003E	,0x1FB2	,0x1F82	,0x0001	), // GREEK SMALL LETTER ALPHA WITH PSILI AND VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03B1	,0x1FB2	,0x1FB2	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03B7	,0x1FB2	,0x1FC2	,0x0000	), // GREEK SMALL LETTER ETA WITH VARIA AND YPOGEGRAMMENI
/*G_VARIA&I          */	DEADTRANS(	0x03C9	,0x1FB2	,0x1FF2	,0x0000	), // GREEK SMALL LETTER OMEGA WITH VARIA AND YPOGEGRAMMENI
/*G_VRACHY           */	DEADTRANS(	0x0020	,0x1FE0	,0x0306	,0x0000	), // COMBINING BREVE
/*G_VRACHY           */	DEADTRANS(	L'A'	,0x1FE0	,0x1FB8	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'a'	,0x1FE0	,0x1FB0	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'I'	,0x1FE0	,0x1FD8	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'i'	,0x1FE0	,0x1FD0	,0x0000	), // GREEK SMALL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'Y'	,0x1FE0	,0x1FE8	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	L'y'	,0x1FE0	,0x1FE0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x0391	,0x1FE0	,0x1FB8	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03B1	,0x1FE0	,0x1FB0	,0x0000	), // GREEK SMALL LETTER ALPHA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x0399	,0x1FE0	,0x1FD8	,0x0000	), // GREEK CAPITAL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03B9	,0x1FE0	,0x1FD0	,0x0000	), // GREEK SMALL LETTER IOTA WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03A5	,0x1FE0	,0x1FE8	,0x0000	), // GREEK CAPITAL LETTER UPSILON WITH VRACHY
/*G_VRACHY           */	DEADTRANS(	0x03C5	,0x1FE0	,0x1FE0	,0x0000	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x00A0	,0x1FC3	,0x037A	,0x0000	), // GREEK YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x202F	,0x1FC3	,0x1FBE	,0x0000	), // GREEK PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'A'	,0x1FC3	,0x1FBC	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'a'	,0x1FC3	,0x1FB3	,0x0000	), // GREEK SMALL LETTER ALPHA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'H'	,0x1FC3	,0x1FCC	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'h'	,0x1FC3	,0x1FC3	,0x0000	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'V'	,0x1FC3	,0x1FFC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'v'	,0x1FC3	,0x1FF3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'W'	,0x1FC3	,0x1FFC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	L'w'	,0x1FC3	,0x1FF3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1F10	,0x1FC3	,0x1F90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1F51	,0x1FC3	,0x1FA1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1F70	,0x1FC3	,0x1FB2	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1F7D	,0x1FC3	,0x1FF4	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x1FC6	,0x1FC3	,0x1FC7	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0020	,0x1FC3	,0x0345	,0x0000	), // COMBINING GREEK YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x002C	,0x1FC3	,0x1FF4	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x003C	,0x1FC3	,0x1FA1	,0x0001	), // GREEK SMALL LETTER OMEGA WITH DASIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x003E	,0x1FC3	,0x1F90	,0x0001	), // GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0060	,0x1FC3	,0x1FB2	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x007E	,0x1FC3	,0x1FC7	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI AND YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0391	,0x1FC3	,0x1FBC	,0x0000	), // GREEK CAPITAL LETTER ALPHA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03B1	,0x1FC3	,0x1FB3	,0x0000	), // GREEK SMALL LETTER ALPHA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x0397	,0x1FC3	,0x1FCC	,0x0000	), // GREEK CAPITAL LETTER ETA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03B7	,0x1FC3	,0x1FC3	,0x0000	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03A9	,0x1FC3	,0x1FFC	,0x0000	), // GREEK CAPITAL LETTER OMEGA WITH PROSGEGRAMMENI
/*G_YPOGEGRAMMENI    */	DEADTRANS(	0x03C9	,0x1FC3	,0x1FF3	,0x0000	), // GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI
/*GRAVE_ACCENT       */	DEADTRANS(	0x0020	,0x00F2	,0x0300	,0x0000	), // COMBINING GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x00F2	,0x021F	,0x1DC8	,0x0000	), // COMBINING GRAVE-ACUTE-GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00A0	,0x00F2	,0x0060	,0x0000	), // GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x00A3	,0x00F2	,0x02CE	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x202F	,0x00F2	,0x02CB	,0x0000	), // MODIFIER LETTER GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	L'A'	,0x00F2	,0x00C0	,0x0000	), // LATIN CAPITAL LETTER A WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'a'	,0x00F2	,0x00E0	,0x0000	), // LATIN SMALL LETTER A WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'B'	,0x00F2	,0x0181	,0x0000	), // LATIN CAPITAL LETTER B WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'b'	,0x00F2	,0x0253	,0x0000	), // LATIN SMALL LETTER B WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'C'	,0x00F2	,0x0187	,0x0000	), // LATIN CAPITAL LETTER C WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'c'	,0x00F2	,0x0188	,0x0000	), // LATIN SMALL LETTER C WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'D'	,0x00F2	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GRAVE_ACCENT       */	DEADTRANS(	L'd'	,0x00F2	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GRAVE_ACCENT       */	DEADTRANS(	L'E'	,0x00F2	,0x00C8	,0x0000	), // LATIN CAPITAL LETTER E WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'e'	,0x00F2	,0x00E8	,0x0000	), // LATIN SMALL LETTER E WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'F'	,0x00F2	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'f'	,0x00F2	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'G'	,0x00F2	,0x0193	,0x0000	), // LATIN CAPITAL LETTER G WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'g'	,0x00F2	,0x0260	,0x0000	), // LATIN SMALL LETTER G WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'H'	,0x00F2	,0xA7AA	,0x0000	), // LATIN CAPITAL LETTER H WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'h'	,0x00F2	,0x0266	,0x0000	), // LATIN SMALL LETTER H WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'I'	,0x00F2	,0x00CC	,0x0000	), // LATIN CAPITAL LETTER I WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'i'	,0x00F2	,0x00EC	,0x0000	), // LATIN SMALL LETTER I WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'J'	,0x00F2	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*GRAVE_ACCENT       */	DEADTRANS(	L'j'	,0x00F2	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*GRAVE_ACCENT       */	DEADTRANS(	L'K'	,0x00F2	,0x0198	,0x0000	), // LATIN CAPITAL LETTER K WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'k'	,0x00F2	,0x0199	,0x0000	), // LATIN SMALL LETTER K WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'L'	,0x00F2	,0x01B3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'l'	,0x00F2	,0x01B4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'M'	,0x00F2	,0x2C6E	,0x0000	), // LATIN CAPITAL LETTER M WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'm'	,0x00F2	,0x0271	,0x0000	), // LATIN SMALL LETTER M WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'N'	,0x00F2	,0x01F8	,0x0000	), // LATIN CAPITAL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'n'	,0x00F2	,0x01F9	,0x0000	), // LATIN SMALL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'O'	,0x00F2	,0x00D2	,0x0000	), // LATIN CAPITAL LETTER O WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'o'	,0x00F2	,0x00F2	,0x0000	), // LATIN SMALL LETTER O WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'P'	,0x00F2	,0x01A4	,0x0000	), // LATIN CAPITAL LETTER P WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'p'	,0x00F2	,0x01A5	,0x0000	), // LATIN SMALL LETTER P WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'Q'	,0x00F2	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GRAVE_ACCENT       */	DEADTRANS(	L'q'	,0x00F2	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GRAVE_ACCENT       */	DEADTRANS(	L'R'	,0x00F2	,0x2C64	,0x0000	), // LATIN CAPITAL LETTER R WITH TAIL
/*GRAVE_ACCENT       */	DEADTRANS(	L'r'	,0x00F2	,0x027D	,0x0000	), // LATIN SMALL LETTER R WITH TAIL
/*GRAVE_ACCENT       */	DEADTRANS(	L'S'	,0x00F2	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*GRAVE_ACCENT       */	DEADTRANS(	L's'	,0x00F2	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*GRAVE_ACCENT       */	DEADTRANS(	L'T'	,0x00F2	,0x01AC	,0x0000	), // LATIN CAPITAL LETTER T WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L't'	,0x00F2	,0x01AD	,0x0000	), // LATIN SMALL LETTER T WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'U'	,0x00F2	,0x00D9	,0x0000	), // LATIN CAPITAL LETTER U WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'u'	,0x00F2	,0x00F9	,0x0000	), // LATIN SMALL LETTER U WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'V'	,0x00F2	,0x01B2	,0x0000	), // LATIN CAPITAL LETTER V WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'v'	,0x00F2	,0x028B	,0x0000	), // LATIN SMALL LETTER V WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'W'	,0x00F2	,0x1E80	,0x0000	), // LATIN CAPITAL LETTER W WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'w'	,0x00F2	,0x1E81	,0x0000	), // LATIN SMALL LETTER W WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'X'	,0x00F2	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'x'	,0x00F2	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'Y'	,0x00F2	,0x1EF2	,0x0000	), // LATIN CAPITAL LETTER Y WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'y'	,0x00F2	,0x1EF3	,0x0000	), // LATIN SMALL LETTER Y WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	L'Z'	,0x00F2	,0x0224	,0x0000	), // LATIN CAPITAL LETTER Z WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	L'z'	,0x00F2	,0x0225	,0x0000	), // LATIN SMALL LETTER Z WITH HOOK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00C0	,0x00F2	,0x00C4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E0	,0x00F2	,0x00E4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00C6	,0x00F2	,0x00C4	,0x0000	), // LATIN CAPITAL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E6	,0x00F2	,0x00E4	,0x0000	), // LATIN SMALL LETTER A WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00C7	,0x00F2	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E7	,0x00F2	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*GRAVE_ACCENT       */	DEADTRANS(	0x00C8	,0x00F2	,0x00D8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E8	,0x00F2	,0x00F8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00C9	,0x00F2	,0x00C5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E9	,0x00F2	,0x00E5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0152	,0x00F2	,0x00C6	,0x0000	), // LATIN CAPITAL LETTER AE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0153	,0x00F2	,0x00E6	,0x0000	), // LATIN SMALL LETTER AE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00D9	,0x00F2	,0x00DC	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x00F9	,0x00F2	,0x00FC	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS
/*GRAVE_ACCENT       */	DEADTRANS(	0x0021	,0x00F2	,0x01C3	,0x0000	), // LATIN LETTER RETROFLEX CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0022	,0x00F2	,0x201F	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0023	,0x00F2	,0x201C	,0x0000	), // LEFT DOUBLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0025	,0x00F2	,0x2031	,0x0000	), // PER TEN THOUSAND SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x0027	,0x00F2	,0x201B	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x0029	,0x00F2	,0x1EB1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x002A	,0x00F2	,0x00D7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x002B	,0x00F2	,0x02F4	,0x0000	), // MODIFIER LETTER MIDDLE GRAVE ACCENT
/*GRAVE_ACCENT       */	DEADTRANS(	0x002C	,0x00F2	,0x1EDD	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x002D	,0x00F2	,0x2015	,0x0000	), // HORIZONTAL BAR
/*GRAVE_ACCENT       */	DEADTRANS(	0x002E	,0x00F2	,0x00D7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x002F	,0x00F2	,0x00F7	,0x0000	), // DIVISION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	L'0'	,0x00F2	,0x0298	,0x0000	), // LATIN LETTER BILABIAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	L'1'	,0x00F2	,0x2035	,0x0000	), // REVERSED PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'2'	,0x00F2	,0x2036	,0x0000	), // REVERSED DOUBLE PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'3'	,0x00F2	,0x2037	,0x0000	), // REVERSED TRIPLE PRIME
/*GRAVE_ACCENT       */	DEADTRANS(	L'6'	,0x00F2	,0x01C0	,0x0000	), // LATIN LETTER DENTAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	L'7'	,0x00F2	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*GRAVE_ACCENT       */	DEADTRANS(	0x003A	,0x00F2	,0x01DC	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x003B	,0x00F2	,0x00D7	,0x0000	), // MULTIPLICATION SIGN
/*GRAVE_ACCENT       */	DEADTRANS(	0x003C	,0x00F2	,0x2264	,0x0000	), // LESS-THAN OR EQUAL TO
/*GRAVE_ACCENT       */	DEADTRANS(	0x003D	,0x00F2	,0x00AD	,0x0000	), // SOFT HYPHEN
/*GRAVE_ACCENT       */	DEADTRANS(	0x003E	,0x00F2	,0x2265	,0x0000	), // GREATER-THAN OR EQUAL TO
/*GRAVE_ACCENT       */	DEADTRANS(	0x003F	,0x00F2	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*GRAVE_ACCENT       */	DEADTRANS(	0x0040	,0x00F2	,0x20DD	,0x0000	), // COMBINING ENCLOSING CIRCLE
/*GRAVE_ACCENT       */	DEADTRANS(	0x005E	,0x00F2	,0x1ED3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x005F	,0x00F2	,0x1E51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0060	,0x00F2	,0x020D	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x007C	,0x00F2	,0x01C1	,0x0000	), // LATIN LETTER LATERAL CLICK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00A9	,0x00F2	,0x01F9	,0x0001	), // LATIN SMALL LETTER N WITH GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00A7	,0x00F2	,0x203B	,0x0000	), // REFERENCE MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00AB	,0x00F2	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00B5	,0x00F2	,0x03C0	,0x0000	), // GREEK SMALL LETTER PI
/*GRAVE_ACCENT       */	DEADTRANS(	0x00BB	,0x00F2	,0x203A	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x00E1	,0x00F2	,0x021F	,0x0001	), // LATIN SMALL LETTER H WITH CARON
/*GRAVE_ACCENT       */	DEADTRANS(	0x00EA	,0x00F2	,0x1ED3	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x00EB	,0x00F2	,0x1ECD	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*GRAVE_ACCENT       */	DEADTRANS(	0x00F2	,0x00F2	,0x020D	,0x0001	), // LATIN SMALL LETTER O WITH DOUBLE GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x2019	,0x00F2	,0x2018	,0x0000	), // LEFT SINGLE QUOTATION MARK
/*GRAVE_ACCENT       */	DEADTRANS(	0x2212	,0x00F2	,0x2011	,0x0000	), // NON-BREAKING HYPHEN
/*GRAVE_ACCENT       */	DEADTRANS(	0x2610	,0x00F2	,0x2751	,0x0000	), // LOWER RIGHT SHADOWED WHITE SQUARE
/*GRAVE_ACCENT       */	DEADTRANS(	0x222A	,0x00F2	,0x2228	,0x0000	), // LOGICAL OR
/*GRAVE_ACCENT       */	DEADTRANS(	0x0186	,0x00F2	,0x019F	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*GRAVE_ACCENT       */	DEADTRANS(	0x0254	,0x00F2	,0x0275	,0x0000	), // LATIN SMALL LETTER BARRED O
/*GRAVE_ACCENT       */	DEADTRANS(	0x0229	,0x00F2	,0x1EDD	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x014F	,0x00F2	,0x1EB1	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x014D	,0x00F2	,0x1E51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*GRAVE_ACCENT       */	DEADTRANS(	0x01A1	,0x00F2	,0x1EDD	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*GRAVE_BELOW        */	DEADTRANS(	0x00A0	,0x02CE	,0x02CE	,0x0000	), // MODIFIER LETTER LOW GRAVE ACCENT
/*GREEK              */	DEADTRANS(	L'A'	,0x03B5	,0x0391	,0x0000	), // GREEK CAPITAL LETTER ALPHA
/*GREEK              */	DEADTRANS(	L'a'	,0x03B5	,0x03B1	,0x0000	), // GREEK SMALL LETTER ALPHA
/*GREEK              */	DEADTRANS(	L'B'	,0x03B5	,0x0392	,0x0000	), // GREEK CAPITAL LETTER BETA
/*GREEK              */	DEADTRANS(	L'b'	,0x03B5	,0x03B2	,0x0000	), // GREEK SMALL LETTER BETA
/*GREEK              */	DEADTRANS(	L'C'	,0x03B5	,0x03A8	,0x0000	), // GREEK CAPITAL LETTER PSI
/*GREEK              */	DEADTRANS(	L'c'	,0x03B5	,0x03C8	,0x0000	), // GREEK SMALL LETTER PSI
/*GREEK              */	DEADTRANS(	L'D'	,0x03B5	,0x0394	,0x0000	), // GREEK CAPITAL LETTER DELTA
/*GREEK              */	DEADTRANS(	L'd'	,0x03B5	,0x03B4	,0x0000	), // GREEK SMALL LETTER DELTA
/*GREEK              */	DEADTRANS(	L'E'	,0x03B5	,0x0395	,0x0000	), // GREEK CAPITAL LETTER EPSILON
/*GREEK              */	DEADTRANS(	L'e'	,0x03B5	,0x03B5	,0x0000	), // GREEK SMALL LETTER EPSILON
/*GREEK              */	DEADTRANS(	L'F'	,0x03B5	,0x03A6	,0x0000	), // GREEK CAPITAL LETTER PHI
/*GREEK              */	DEADTRANS(	L'f'	,0x03B5	,0x03C6	,0x0000	), // GREEK SMALL LETTER PHI
/*GREEK              */	DEADTRANS(	L'G'	,0x03B5	,0x0393	,0x0000	), // GREEK CAPITAL LETTER GAMMA
/*GREEK              */	DEADTRANS(	L'g'	,0x03B5	,0x03B3	,0x0000	), // GREEK SMALL LETTER GAMMA
/*GREEK              */	DEADTRANS(	L'H'	,0x03B5	,0x0397	,0x0000	), // GREEK CAPITAL LETTER ETA
/*GREEK              */	DEADTRANS(	L'h'	,0x03B5	,0x03B7	,0x0000	), // GREEK SMALL LETTER ETA
/*GREEK              */	DEADTRANS(	L'I'	,0x03B5	,0x0399	,0x0000	), // GREEK CAPITAL LETTER IOTA
/*GREEK              */	DEADTRANS(	L'i'	,0x03B5	,0x03B9	,0x0000	), // GREEK SMALL LETTER IOTA
/*GREEK              */	DEADTRANS(	L'J'	,0x03B5	,0x039E	,0x0000	), // GREEK CAPITAL LETTER XI
/*GREEK              */	DEADTRANS(	L'j'	,0x03B5	,0x03BE	,0x0000	), // GREEK SMALL LETTER XI
/*GREEK              */	DEADTRANS(	L'K'	,0x03B5	,0x039A	,0x0000	), // GREEK CAPITAL LETTER KAPPA
/*GREEK              */	DEADTRANS(	L'k'	,0x03B5	,0x03BA	,0x0000	), // GREEK SMALL LETTER KAPPA
/*GREEK              */	DEADTRANS(	L'L'	,0x03B5	,0x039B	,0x0000	), // GREEK CAPITAL LETTER LAMDA
/*GREEK              */	DEADTRANS(	L'l'	,0x03B5	,0x03BB	,0x0000	), // GREEK SMALL LETTER LAMDA
/*GREEK              */	DEADTRANS(	L'M'	,0x03B5	,0x039C	,0x0000	), // GREEK CAPITAL LETTER MU
/*GREEK              */	DEADTRANS(	L'm'	,0x03B5	,0x03BC	,0x0000	), // GREEK SMALL LETTER MU
/*GREEK              */	DEADTRANS(	L'N'	,0x03B5	,0x039D	,0x0000	), // GREEK CAPITAL LETTER NU
/*GREEK              */	DEADTRANS(	L'n'	,0x03B5	,0x03BD	,0x0000	), // GREEK SMALL LETTER NU
/*GREEK              */	DEADTRANS(	L'O'	,0x03B5	,0x039F	,0x0000	), // GREEK CAPITAL LETTER OMICRON
/*GREEK              */	DEADTRANS(	L'o'	,0x03B5	,0x03BF	,0x0000	), // GREEK SMALL LETTER OMICRON
/*GREEK              */	DEADTRANS(	L'P'	,0x03B5	,0x03A0	,0x0000	), // GREEK CAPITAL LETTER PI
/*GREEK              */	DEADTRANS(	L'p'	,0x03B5	,0x03C0	,0x0000	), // GREEK SMALL LETTER PI
/*GREEK              */	DEADTRANS(	L'Q'	,0x03B5	,0x2211	,0x0000	), // N-ARY SUMMATION
/*GREEK              */	DEADTRANS(	L'q'	,0x03B5	,0x03C2	,0x0000	), // GREEK SMALL LETTER FINAL SIGMA
/*GREEK              */	DEADTRANS(	L'R'	,0x03B5	,0x03A1	,0x0000	), // GREEK CAPITAL LETTER RHO
/*GREEK              */	DEADTRANS(	L'r'	,0x03B5	,0x03C1	,0x0000	), // GREEK SMALL LETTER RHO
/*GREEK              */	DEADTRANS(	L'S'	,0x03B5	,0x03A3	,0x0000	), // GREEK CAPITAL LETTER SIGMA
/*GREEK              */	DEADTRANS(	L's'	,0x03B5	,0x03C3	,0x0000	), // GREEK SMALL LETTER SIGMA
/*GREEK              */	DEADTRANS(	L'T'	,0x03B5	,0x03A4	,0x0000	), // GREEK CAPITAL LETTER TAU
/*GREEK              */	DEADTRANS(	L't'	,0x03B5	,0x03C4	,0x0000	), // GREEK SMALL LETTER TAU
/*GREEK              */	DEADTRANS(	L'U'	,0x03B5	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GREEK              */	DEADTRANS(	L'u'	,0x03B5	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*GREEK              */	DEADTRANS(	L'V'	,0x03B5	,0x03A9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'v'	,0x03B5	,0x03C9	,0x0000	), // GREEK SMALL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'W'	,0x03B5	,0x03A9	,0x0000	), // GREEK CAPITAL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'w'	,0x03B5	,0x03C9	,0x0000	), // GREEK SMALL LETTER OMEGA
/*GREEK              */	DEADTRANS(	L'X'	,0x03B5	,0x03A7	,0x0000	), // GREEK CAPITAL LETTER CHI
/*GREEK              */	DEADTRANS(	L'x'	,0x03B5	,0x03C7	,0x0000	), // GREEK SMALL LETTER CHI
/*GREEK              */	DEADTRANS(	L'Y'	,0x03B5	,0x03A5	,0x0000	), // GREEK CAPITAL LETTER UPSILON
/*GREEK              */	DEADTRANS(	L'y'	,0x03B5	,0x03C5	,0x0000	), // GREEK SMALL LETTER UPSILON
/*GREEK              */	DEADTRANS(	L'Z'	,0x03B5	,0x0396	,0x0000	), // GREEK CAPITAL LETTER ZETA
/*GREEK              */	DEADTRANS(	L'z'	,0x03B5	,0x03B6	,0x0000	), // GREEK SMALL LETTER ZETA
/*GREEK              */	DEADTRANS(	0x0029	,0x03B5	,0x1FE0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK              */	DEADTRANS(	0x03B5	,0x03B5	,0x0395	,0x0001	), // GREEK CAPITAL LETTER EPSILON
/*GREEK              */	DEADTRANS(	0x002C	,0x03B5	,0x1F7D	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK              */	DEADTRANS(	0x003A	,0x03B5	,0x03CA	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK              */	DEADTRANS(	0x003B	,0x03B5	,0x1FC3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK              */	DEADTRANS(	0x003C	,0x03B5	,0x1F51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK              */	DEADTRANS(	0x003E	,0x03B5	,0x1F10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK              */	DEADTRANS(	0x005F	,0x03B5	,0x1FB1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK              */	DEADTRANS(	0x0060	,0x03B5	,0x1F70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK              */	DEADTRANS(	0x007E	,0x03B5	,0x1FC6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK              */	DEADTRANS(	0x00B5	,0x03B5	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*GREEK              */	DEADTRANS(	0x1F70	,0x03B5	,0x1F70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK              */	DEADTRANS(	0x1FB1	,0x03B5	,0x1FB1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK              */	DEADTRANS(	0x1F10	,0x03B5	,0x1F10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK              */	DEADTRANS(	0x1FC6	,0x03B5	,0x1FC6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK              */	DEADTRANS(	0x1FC3	,0x03B5	,0x1FC3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK              */	DEADTRANS(	0x03CA	,0x03B5	,0x03CA	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK              */	DEADTRANS(	0x03CC	,0x03B5	,0x03CC	,0x0001	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*GREEK              */	DEADTRANS(	0x1FE0	,0x03B5	,0x1FE0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK              */	DEADTRANS(	0x1F51	,0x03B5	,0x1F51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK              */	DEADTRANS(	0x1F7D	,0x03B5	,0x1F7D	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK_LOCK         */	DEADTRANS(	L'A'	,0x0395	,0x0391	,0x0001	), // GREEK CAPITAL LETTER ALPHA
/*GREEK_LOCK         */	DEADTRANS(	L'a'	,0x0395	,0x03B1	,0x0001	), // GREEK SMALL LETTER ALPHA
/*GREEK_LOCK         */	DEADTRANS(	L'B'	,0x0395	,0x0392	,0x0001	), // GREEK CAPITAL LETTER BETA
/*GREEK_LOCK         */	DEADTRANS(	L'b'	,0x0395	,0x03B2	,0x0001	), // GREEK SMALL LETTER BETA
/*GREEK_LOCK         */	DEADTRANS(	L'C'	,0x0395	,0x03A8	,0x0001	), // GREEK CAPITAL LETTER PSI
/*GREEK_LOCK         */	DEADTRANS(	L'c'	,0x0395	,0x03C8	,0x0001	), // GREEK SMALL LETTER PSI
/*GREEK_LOCK         */	DEADTRANS(	L'D'	,0x0395	,0x0394	,0x0001	), // GREEK CAPITAL LETTER DELTA
/*GREEK_LOCK         */	DEADTRANS(	L'd'	,0x0395	,0x03B4	,0x0001	), // GREEK SMALL LETTER DELTA
/*GREEK_LOCK         */	DEADTRANS(	L'E'	,0x0395	,0x0395	,0x0001	), // GREEK CAPITAL LETTER EPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'e'	,0x0395	,0x03B5	,0x0001	), // GREEK SMALL LETTER EPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'F'	,0x0395	,0x03A6	,0x0001	), // GREEK CAPITAL LETTER PHI
/*GREEK_LOCK         */	DEADTRANS(	L'f'	,0x0395	,0x03C6	,0x0001	), // GREEK SMALL LETTER PHI
/*GREEK_LOCK         */	DEADTRANS(	L'G'	,0x0395	,0x0393	,0x0001	), // GREEK CAPITAL LETTER GAMMA
/*GREEK_LOCK         */	DEADTRANS(	L'g'	,0x0395	,0x03B3	,0x0001	), // GREEK SMALL LETTER GAMMA
/*GREEK_LOCK         */	DEADTRANS(	L'H'	,0x0395	,0x0397	,0x0001	), // GREEK CAPITAL LETTER ETA
/*GREEK_LOCK         */	DEADTRANS(	L'h'	,0x0395	,0x03B7	,0x0001	), // GREEK SMALL LETTER ETA
/*GREEK_LOCK         */	DEADTRANS(	L'I'	,0x0395	,0x0399	,0x0001	), // GREEK CAPITAL LETTER IOTA
/*GREEK_LOCK         */	DEADTRANS(	L'i'	,0x0395	,0x03B9	,0x0001	), // GREEK SMALL LETTER IOTA
/*GREEK_LOCK         */	DEADTRANS(	L'J'	,0x0395	,0x039E	,0x0001	), // GREEK CAPITAL LETTER XI
/*GREEK_LOCK         */	DEADTRANS(	L'j'	,0x0395	,0x03BE	,0x0001	), // GREEK SMALL LETTER XI
/*GREEK_LOCK         */	DEADTRANS(	L'K'	,0x0395	,0x039A	,0x0001	), // GREEK CAPITAL LETTER KAPPA
/*GREEK_LOCK         */	DEADTRANS(	L'k'	,0x0395	,0x03BA	,0x0001	), // GREEK SMALL LETTER KAPPA
/*GREEK_LOCK         */	DEADTRANS(	L'L'	,0x0395	,0x039B	,0x0001	), // GREEK CAPITAL LETTER LAMDA
/*GREEK_LOCK         */	DEADTRANS(	L'l'	,0x0395	,0x03BB	,0x0001	), // GREEK SMALL LETTER LAMDA
/*GREEK_LOCK         */	DEADTRANS(	L'M'	,0x0395	,0x039C	,0x0001	), // GREEK CAPITAL LETTER MU
/*GREEK_LOCK         */	DEADTRANS(	L'm'	,0x0395	,0x03BC	,0x0001	), // GREEK SMALL LETTER MU
/*GREEK_LOCK         */	DEADTRANS(	L'N'	,0x0395	,0x039D	,0x0001	), // GREEK CAPITAL LETTER NU
/*GREEK_LOCK         */	DEADTRANS(	L'n'	,0x0395	,0x03BD	,0x0001	), // GREEK SMALL LETTER NU
/*GREEK_LOCK         */	DEADTRANS(	L'O'	,0x0395	,0x039F	,0x0001	), // GREEK CAPITAL LETTER OMICRON
/*GREEK_LOCK         */	DEADTRANS(	L'o'	,0x0395	,0x03BF	,0x0001	), // GREEK SMALL LETTER OMICRON
/*GREEK_LOCK         */	DEADTRANS(	L'P'	,0x0395	,0x03A0	,0x0001	), // GREEK CAPITAL LETTER PI
/*GREEK_LOCK         */	DEADTRANS(	L'p'	,0x0395	,0x03C0	,0x0001	), // GREEK SMALL LETTER PI
/*GREEK_LOCK         */	DEADTRANS(	L'Q'	,0x0395	,0x2211	,0x0001	), // N-ARY SUMMATION
/*GREEK_LOCK         */	DEADTRANS(	L'q'	,0x0395	,0x03C2	,0x0001	), // GREEK SMALL LETTER FINAL SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L'R'	,0x0395	,0x03A1	,0x0001	), // GREEK CAPITAL LETTER RHO
/*GREEK_LOCK         */	DEADTRANS(	L'r'	,0x0395	,0x03C1	,0x0001	), // GREEK SMALL LETTER RHO
/*GREEK_LOCK         */	DEADTRANS(	L'S'	,0x0395	,0x03A3	,0x0001	), // GREEK CAPITAL LETTER SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L's'	,0x0395	,0x03C3	,0x0001	), // GREEK SMALL LETTER SIGMA
/*GREEK_LOCK         */	DEADTRANS(	L'T'	,0x0395	,0x03A4	,0x0001	), // GREEK CAPITAL LETTER TAU
/*GREEK_LOCK         */	DEADTRANS(	L't'	,0x0395	,0x03C4	,0x0001	), // GREEK SMALL LETTER TAU
/*GREEK_LOCK         */	DEADTRANS(	L'U'	,0x0395	,0x0398	,0x0001	), // GREEK CAPITAL LETTER THETA
/*GREEK_LOCK         */	DEADTRANS(	L'u'	,0x0395	,0x03B8	,0x0001	), // GREEK SMALL LETTER THETA
/*GREEK_LOCK         */	DEADTRANS(	L'V'	,0x0395	,0x03A9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'v'	,0x0395	,0x03C9	,0x0001	), // GREEK SMALL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'W'	,0x0395	,0x03A9	,0x0001	), // GREEK CAPITAL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'w'	,0x0395	,0x03C9	,0x0001	), // GREEK SMALL LETTER OMEGA
/*GREEK_LOCK         */	DEADTRANS(	L'X'	,0x0395	,0x03A7	,0x0001	), // GREEK CAPITAL LETTER CHI
/*GREEK_LOCK         */	DEADTRANS(	L'x'	,0x0395	,0x03C7	,0x0001	), // GREEK SMALL LETTER CHI
/*GREEK_LOCK         */	DEADTRANS(	L'Y'	,0x0395	,0x03A5	,0x0001	), // GREEK CAPITAL LETTER UPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'y'	,0x0395	,0x03C5	,0x0001	), // GREEK SMALL LETTER UPSILON
/*GREEK_LOCK         */	DEADTRANS(	L'Z'	,0x0395	,0x0396	,0x0001	), // GREEK CAPITAL LETTER ZETA
/*GREEK_LOCK         */	DEADTRANS(	L'z'	,0x0395	,0x03B6	,0x0001	), // GREEK SMALL LETTER ZETA
/*GREEK_LOCK         */	DEADTRANS(	0x0029	,0x0395	,0x1FE0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK_LOCK         */	DEADTRANS(	0x002C	,0x0395	,0x1F7D	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GREEK_LOCK         */	DEADTRANS(	0x003A	,0x0395	,0x03CA	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK_LOCK         */	DEADTRANS(	0x003B	,0x0395	,0x1FC3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK_LOCK         */	DEADTRANS(	0x003C	,0x0395	,0x1F51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK_LOCK         */	DEADTRANS(	0x003E	,0x0395	,0x1F10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK_LOCK         */	DEADTRANS(	0x005F	,0x0395	,0x1FB1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK_LOCK         */	DEADTRANS(	0x0060	,0x0395	,0x1F70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK_LOCK         */	DEADTRANS(	0x007E	,0x0395	,0x1FC6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK_LOCK         */	DEADTRANS(	0x00B5	,0x0395	,0x0448	,0x0001	), // CYRILLIC SMALL LETTER SHA
/*GREEK_LOCK         */	DEADTRANS(	0x1F70	,0x0395	,0x1F70	,0x0001	), // GREEK SMALL LETTER ALPHA WITH VARIA
/*GREEK_LOCK         */	DEADTRANS(	0x1FB1	,0x0395	,0x1FB1	,0x0001	), // GREEK SMALL LETTER ALPHA WITH MACRON
/*GREEK_LOCK         */	DEADTRANS(	0x1F10	,0x0395	,0x1F10	,0x0001	), // GREEK SMALL LETTER EPSILON WITH PSILI
/*GREEK_LOCK         */	DEADTRANS(	0x1FC6	,0x0395	,0x1FC6	,0x0001	), // GREEK SMALL LETTER ETA WITH PERISPOMENI
/*GREEK_LOCK         */	DEADTRANS(	0x1FC3	,0x0395	,0x1FC3	,0x0001	), // GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI
/*GREEK_LOCK         */	DEADTRANS(	0x03CA	,0x0395	,0x03CA	,0x0001	), // GREEK SMALL LETTER IOTA WITH DIALYTIKA
/*GREEK_LOCK         */	DEADTRANS(	0x03CC	,0x0395	,0x03CC	,0x0001	), // GREEK SMALL LETTER OMICRON WITH TONOS
/*GREEK_LOCK         */	DEADTRANS(	0x1FE0	,0x0395	,0x1FE0	,0x0001	), // GREEK SMALL LETTER UPSILON WITH VRACHY
/*GREEK_LOCK         */	DEADTRANS(	0x1F51	,0x0395	,0x1F51	,0x0001	), // GREEK SMALL LETTER UPSILON WITH DASIA
/*GREEK_LOCK         */	DEADTRANS(	0x1F7D	,0x0395	,0x1F7D	,0x0001	), // GREEK SMALL LETTER OMEGA WITH OXIA
/*GROUP_02           */	DEADTRANS(	L'A'	,0x2460	,0x00C6	,0x0000	), // LATIN CAPITAL LETTER AE
/*GROUP_02           */	DEADTRANS(	L'a'	,0x2460	,0x00E6	,0x0000	), // LATIN SMALL LETTER AE
/*GROUP_02           */	DEADTRANS(	L'B'	,0x2460	,0xA7B4	,0x0000	), // LATIN CAPITAL LETTER BETA
/*GROUP_02           */	DEADTRANS(	L'b'	,0x2460	,0xA7B5	,0x0000	), // LATIN SMALL LETTER BETA
/*GROUP_02           */	DEADTRANS(	L'C'	,0x2460	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GROUP_02           */	DEADTRANS(	L'c'	,0x2460	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GROUP_02           */	DEADTRANS(	L'D'	,0x2460	,0x00D0	,0x0000	), // LATIN CAPITAL LETTER ETH
/*GROUP_02           */	DEADTRANS(	L'd'	,0x2460	,0x00F0	,0x0000	), // LATIN SMALL LETTER ETH
/*GROUP_02           */	DEADTRANS(	L'E'	,0x2460	,0x018E	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*GROUP_02           */	DEADTRANS(	L'e'	,0x2460	,0x01DD	,0x0000	), // LATIN SMALL LETTER TURNED E
/*GROUP_02           */	DEADTRANS(	L'F'	,0x2460	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'f'	,0x2460	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'G'	,0x2460	,0x0194	,0x0000	), // LATIN CAPITAL LETTER GAMMA
/*GROUP_02           */	DEADTRANS(	L'g'	,0x2460	,0x0263	,0x0000	), // LATIN SMALL LETTER GAMMA
/*GROUP_02           */	DEADTRANS(	L'H'	,0x2460	,0x0241	,0x0000	), // LATIN CAPITAL LETTER GLOTTAL STOP
/*GROUP_02           */	DEADTRANS(	L'h'	,0x2460	,0x0242	,0x0000	), // LATIN SMALL LETTER GLOTTAL STOP
/*GROUP_02           */	DEADTRANS(	L'I'	,0x2460	,0x0196	,0x0000	), // LATIN CAPITAL LETTER IOTA
/*GROUP_02           */	DEADTRANS(	L'i'	,0x2460	,0x0269	,0x0000	), // LATIN SMALL LETTER IOTA
/*GROUP_02           */	DEADTRANS(	L'J'	,0x2460	,0x0132	,0x0000	), // LATIN CAPITAL LIGATURE IJ
/*GROUP_02           */	DEADTRANS(	L'j'	,0x2460	,0x0133	,0x0000	), // LATIN SMALL LIGATURE IJ
/*GROUP_02           */	DEADTRANS(	L'K'	,0x2460	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GROUP_02           */	DEADTRANS(	L'k'	,0x2460	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GROUP_02           */	DEADTRANS(	L'L'	,0x2460	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*GROUP_02           */	DEADTRANS(	L'l'	,0x2460	,0x021D	,0x0000	), // LATIN SMALL LETTER YOGH
/*GROUP_02           */	DEADTRANS(	L'M'	,0x2460	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'm'	,0x2460	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	L'N'	,0x2460	,0x014A	,0x0000	), // LATIN CAPITAL LETTER ENG
/*GROUP_02           */	DEADTRANS(	L'n'	,0x2460	,0x014B	,0x0000	), // LATIN SMALL LETTER ENG
/*GROUP_02           */	DEADTRANS(	L'O'	,0x2460	,0x0152	,0x0000	), // LATIN CAPITAL LIGATURE OE
/*GROUP_02           */	DEADTRANS(	L'o'	,0x2460	,0x0153	,0x0000	), // LATIN SMALL LIGATURE OE
/*GROUP_02           */	DEADTRANS(	L'P'	,0x2460	,0x018F	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*GROUP_02           */	DEADTRANS(	L'p'	,0x2460	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*GROUP_02           */	DEADTRANS(	L'Q'	,0x2460	,0x004B	,0x0000	), // LATIN CAPITAL LETTER K
/*GROUP_02           */	DEADTRANS(	L'q'	,0x2460	,0x0138	,0x0000	), // LATIN SMALL LETTER KRA
/*GROUP_02           */	DEADTRANS(	L'R'	,0x2460	,0xA78B	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*GROUP_02           */	DEADTRANS(	L'r'	,0x2460	,0xA78C	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*GROUP_02           */	DEADTRANS(	L'S'	,0x2460	,0x1E9E	,0x0000	), // LATIN CAPITAL LETTER SHARP S
/*GROUP_02           */	DEADTRANS(	L's'	,0x2460	,0x00DF	,0x0000	), // LATIN SMALL LETTER SHARP S
/*GROUP_02           */	DEADTRANS(	L'T'	,0x2460	,0x00DE	,0x0000	), // LATIN CAPITAL LETTER THORN
/*GROUP_02           */	DEADTRANS(	L't'	,0x2460	,0x00FE	,0x0000	), // LATIN SMALL LETTER THORN
/*GROUP_02           */	DEADTRANS(	L'U'	,0x2460	,0xA78D	,0x0000	), // LATIN CAPITAL LETTER TURNED H
/*GROUP_02           */	DEADTRANS(	L'u'	,0x2460	,0x0265	,0x0000	), // LATIN SMALL LETTER TURNED H
/*GROUP_02           */	DEADTRANS(	L'V'	,0x2460	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*GROUP_02           */	DEADTRANS(	L'v'	,0x2460	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*GROUP_02           */	DEADTRANS(	L'W'	,0x2460	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	L'w'	,0x2460	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	L'X'	,0x2460	,0xA7B3	,0x0000	), // LATIN CAPITAL LETTER CHI
/*GROUP_02           */	DEADTRANS(	L'x'	,0x2460	,0xAB53	,0x0000	), // LATIN SMALL LETTER CHI
/*GROUP_02           */	DEADTRANS(	L'Y'	,0x2460	,0x01B1	,0x0000	), // LATIN CAPITAL LETTER UPSILON
/*GROUP_02           */	DEADTRANS(	L'y'	,0x2460	,0x028A	,0x0000	), // LATIN SMALL LETTER UPSILON
/*GROUP_02           */	DEADTRANS(	L'Z'	,0x2460	,0x01B7	,0x0000	), // LATIN CAPITAL LETTER EZH
/*GROUP_02           */	DEADTRANS(	L'z'	,0x2460	,0x0292	,0x0000	), // LATIN SMALL LETTER EZH
/*GROUP_02           */	DEADTRANS(	0x00C0	,0x2460	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*GROUP_02           */	DEADTRANS(	0x00E0	,0x2460	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*GROUP_02           */	DEADTRANS(	0x00C6	,0x2460	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*GROUP_02           */	DEADTRANS(	0x00E6	,0x2460	,0x026A	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*GROUP_02           */	DEADTRANS(	0x00C7	,0x2460	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*GROUP_02           */	DEADTRANS(	0x00E7	,0x2460	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*GROUP_02           */	DEADTRANS(	0x00C8	,0x2460	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	0x00E8	,0x2460	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_02           */	DEADTRANS(	0x00C9	,0x2460	,0xA722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_02           */	DEADTRANS(	0x00E9	,0x2460	,0xA723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_02           */	DEADTRANS(	0x0152	,0x2460	,0xA7B6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*GROUP_02           */	DEADTRANS(	0x0153	,0x2460	,0xA7B7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*GROUP_02           */	DEADTRANS(	0x00D9	,0x2460	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GROUP_02           */	DEADTRANS(	0x00F9	,0x2460	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_02           */	DEADTRANS(	0x0020	,0x2460	,0x2002	,0x0000	), // EN SPACE
/*GROUP_02           */	DEADTRANS(	0x0021	,0x2460	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*GROUP_02           */	DEADTRANS(	0x0022	,0x2460	,0x2033	,0x0000	), // DOUBLE PRIME
/*GROUP_02           */	DEADTRANS(	0x0023	,0x2460	,0x00A2	,0x0000	), // CENT SIGN
/*GROUP_02           */	DEADTRANS(	0x0024	,0x2460	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*GROUP_02           */	DEADTRANS(	0x0025	,0x2460	,0x2030	,0x0000	), // PER MILLE SIGN
/*GROUP_02           */	DEADTRANS(	0x0026	,0x2460	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	0x0027	,0x2460	,0x2032	,0x0000	), // PRIME
/*GROUP_02           */	DEADTRANS(	0x0028	,0x2460	,0x02BF	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*GROUP_02           */	DEADTRANS(	0x0029	,0x2460	,0x02BE	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*GROUP_02           */	DEADTRANS(	0x002A	,0x2460	,0x2022	,0x0000	), // BULLET
/*GROUP_02           */	DEADTRANS(	0x002B	,0x2460	,0x00B1	,0x0000	), // PLUS-MINUS SIGN
/*GROUP_02           */	DEADTRANS(	0x002C	,0x2460	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*GROUP_02           */	DEADTRANS(	0x002D	,0x2460	,0x2043	,0x0000	), // HYPHEN BULLET
/*GROUP_02           */	DEADTRANS(	0x002E	,0x2460	,0x2027	,0x0000	), // HYPHENATION POINT
/*GROUP_02           */	DEADTRANS(	0x002F	,0x2460	,0x2044	,0x0000	), // FRACTION SLASH
/*GROUP_02           */	DEADTRANS(	L'0'	,0x2460	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_02           */	DEADTRANS(	L'1'	,0x2460	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_02           */	DEADTRANS(	L'2'	,0x2460	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_02           */	DEADTRANS(	L'3'	,0x2460	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_02           */	DEADTRANS(	L'4'	,0x2460	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_02           */	DEADTRANS(	L'5'	,0x2460	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_02           */	DEADTRANS(	L'6'	,0x2460	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_02           */	DEADTRANS(	L'7'	,0x2460	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_02           */	DEADTRANS(	L'8'	,0x2460	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_02           */	DEADTRANS(	L'9'	,0x2460	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_02           */	DEADTRANS(	0x003A	,0x2460	,0x00A6	,0x0000	), // BROKEN BAR
/*GROUP_02           */	DEADTRANS(	0x003B	,0x2460	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*GROUP_02           */	DEADTRANS(	0x003C	,0x2460	,0x2023	,0x0000	), // TRIANGULAR BULLET
/*GROUP_02           */	DEADTRANS(	0x003D	,0x2460	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*GROUP_02           */	DEADTRANS(	0x003E	,0x2460	,0x2794	,0x0000	), // HEAVY WIDE-HEADED RIGHTWARDS ARROW
/*GROUP_02           */	DEADTRANS(	0x003F	,0x2460	,0x00BF	,0x0000	), // INVERTED QUESTION MARK
/*GROUP_02           */	DEADTRANS(	0x0040	,0x2460	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*GROUP_02           */	DEADTRANS(	0x005B	,0x2460	,0x00AB	,0x0000	), // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x005C	,0x2460	,0x203B	,0x0000	), // REFERENCE MARK
/*GROUP_02           */	DEADTRANS(	0x005D	,0x2460	,0x00BB	,0x0000	), // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x005E	,0x2460	,0x266F	,0x0000	), // MUSIC SHARP SIGN
/*GROUP_02           */	DEADTRANS(	0x005F	,0x2460	,0x203E	,0x0000	), // OVERLINE
/*GROUP_02           */	DEADTRANS(	0x0060	,0x2460	,0x266D	,0x0000	), // MUSIC FLAT SIGN
/*GROUP_02           */	DEADTRANS(	0x007B	,0x2460	,0x2039	,0x0000	), // SINGLE LEFT-POINTING ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x007C	,0x2460	,0x2016	,0x0000	), // DOUBLE VERTICAL LINE
/*GROUP_02           */	DEADTRANS(	0x007D	,0x2460	,0x203A	,0x0000	), // SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
/*GROUP_02           */	DEADTRANS(	0x007E	,0x2460	,0x2248	,0x0000	), // ALMOST EQUAL TO
/*GROUP_02           */	DEADTRANS(	0x20AC	,0x2460	,0x20BD	,0x0000	), // RUBLE SIGN
/*GROUP_02           */	DEADTRANS(	0x2026	,0x2460	,0x2999	,0x0000	), // DOTTED FENCE
/*GROUP_02           */	DEADTRANS(	0x00A0	,0x2460	,0x2003	,0x0000	), // EM SPACE
/*GROUP_02           */	DEADTRANS(	0x00A7	,0x2460	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*GROUP_02           */	DEADTRANS(	0x00B0	,0x2460	,0x25CC	,0x0000	), // DOTTED CIRCLE
/*GROUP_02           */	DEADTRANS(	0x00B2	,0x2460	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_02           */	DEADTRANS(	0x00B7	,0x2460	,0x2022	,0x0000	), // BULLET
/*GROUP_02           */	DEADTRANS(	0x2019	,0x2460	,0x02BC	,0x0000	), // MODIFIER LETTER APOSTROPHE
/*GROUP_02           */	DEADTRANS(	0x222A	,0x2460	,0x2229	,0x0000	), // INTERSECTION
/*GROUP_03           */	DEADTRANS(	L'A'	,0x00B3	,0x2C6D	,0x0000	), // LATIN CAPITAL LETTER ALPHA
/*GROUP_03           */	DEADTRANS(	L'a'	,0x00B3	,0x0251	,0x0000	), // LATIN SMALL LETTER ALPHA
/*GROUP_03           */	DEADTRANS(	L'B'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'b'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'C'	,0x00B3	,0xA722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_03           */	DEADTRANS(	L'c'	,0x00B3	,0xA723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_03           */	DEADTRANS(	L'D'	,0x00B3	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*GROUP_03           */	DEADTRANS(	L'd'	,0x00B3	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*GROUP_03           */	DEADTRANS(	L'E'	,0x00B3	,0x018F	,0x0000	), // LATIN CAPITAL LETTER SCHWA
/*GROUP_03           */	DEADTRANS(	L'e'	,0x00B3	,0x0259	,0x0000	), // LATIN SMALL LETTER SCHWA
/*GROUP_03           */	DEADTRANS(	L'F'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'f'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'G'	,0x00B3	,0x021C	,0x0000	), // LATIN CAPITAL LETTER YOGH
/*GROUP_03           */	DEADTRANS(	L'g'	,0x00B3	,0x021D	,0x0000	), // LATIN SMALL LETTER YOGH
/*GROUP_03           */	DEADTRANS(	L'H'	,0x00B3	,0xA78B	,0x0000	), // LATIN CAPITAL LETTER SALTILLO
/*GROUP_03           */	DEADTRANS(	L'h'	,0x00B3	,0xA78C	,0x0000	), // LATIN SMALL LETTER SALTILLO
/*GROUP_03           */	DEADTRANS(	L'I'	,0x00B3	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*GROUP_03           */	DEADTRANS(	L'i'	,0x00B3	,0x026A	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*GROUP_03           */	DEADTRANS(	L'J'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'j'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'K'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'k'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'L'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'l'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'M'	,0x00B3	,0xA724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*GROUP_03           */	DEADTRANS(	L'm'	,0x00B3	,0xA725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*GROUP_03           */	DEADTRANS(	L'N'	,0x00B3	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*GROUP_03           */	DEADTRANS(	L'n'	,0x00B3	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*GROUP_03           */	DEADTRANS(	L'O'	,0x00B3	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*GROUP_03           */	DEADTRANS(	L'o'	,0x00B3	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*GROUP_03           */	DEADTRANS(	L'P'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'p'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Q'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'q'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'R'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'r'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'S'	,0x00B3	,0x01A9	,0x0000	), // LATIN CAPITAL LETTER ESH
/*GROUP_03           */	DEADTRANS(	L's'	,0x00B3	,0x0283	,0x0000	), // LATIN SMALL LETTER ESH
/*GROUP_03           */	DEADTRANS(	L'T'	,0x00B3	,0x0398	,0x0000	), // GREEK CAPITAL LETTER THETA
/*GROUP_03           */	DEADTRANS(	L't'	,0x00B3	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_03           */	DEADTRANS(	L'U'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'u'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'V'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'v'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'W'	,0x00B3	,0x01F7	,0x0000	), // LATIN CAPITAL LETTER WYNN
/*GROUP_03           */	DEADTRANS(	L'w'	,0x00B3	,0x01BF	,0x0000	), // LATIN LETTER WYNN
/*GROUP_03           */	DEADTRANS(	L'X'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'x'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Y'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'y'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'Z'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'z'	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00C0	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00E0	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00C6	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00E6	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00C7	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00E7	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00C8	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00E8	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00C9	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00E9	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0152	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0153	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00D9	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00F9	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0020	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0021	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0022	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0023	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0024	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0025	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0026	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0027	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0028	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0029	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002A	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002B	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002C	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002D	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002E	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x002F	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	L'0'	,0x00B3	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_03           */	DEADTRANS(	L'1'	,0x00B3	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_03           */	DEADTRANS(	L'2'	,0x00B3	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_03           */	DEADTRANS(	L'3'	,0x00B3	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_03           */	DEADTRANS(	L'4'	,0x00B3	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_03           */	DEADTRANS(	L'5'	,0x00B3	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_03           */	DEADTRANS(	L'6'	,0x00B3	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_03           */	DEADTRANS(	L'7'	,0x00B3	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_03           */	DEADTRANS(	L'8'	,0x00B3	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_03           */	DEADTRANS(	L'9'	,0x00B3	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_03           */	DEADTRANS(	0x003A	,0x00B3	,0x2999	,0x0000	), // DOTTED FENCE
/*GROUP_03           */	DEADTRANS(	0x003B	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003C	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003D	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003E	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x003F	,0x00B3	,0x0294	,0x0000	), // LATIN LETTER GLOTTAL STOP
/*GROUP_03           */	DEADTRANS(	0x0040	,0x00B3	,0x25CB	,0x0000	), // WHITE CIRCLE
/*GROUP_03           */	DEADTRANS(	0x005B	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005C	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005D	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005E	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x005F	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0060	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x0060	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007B	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007C	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007D	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x007E	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x20AC	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x2026	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00A0	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00A7	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00B0	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x00B2	,0x00B3	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_03           */	DEADTRANS(	0x00B7	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x2019	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_03           */	DEADTRANS(	0x222A	,0x00B3	,0x0033	,0x0000	), // DIGIT THREE
/*GROUP_04           */	DEADTRANS(	L'A'	,0x2074	,0xA722	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL ALEF
/*GROUP_04           */	DEADTRANS(	L'a'	,0x2074	,0xA723	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL ALEF
/*GROUP_04           */	DEADTRANS(	L'B'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'b'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'C'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'c'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'D'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'd'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'E'	,0x2074	,0x0190	,0x0000	), // LATIN CAPITAL LETTER OPEN E
/*GROUP_04           */	DEADTRANS(	L'e'	,0x2074	,0x025B	,0x0000	), // LATIN SMALL LETTER OPEN E
/*GROUP_04           */	DEADTRANS(	L'F'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'f'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'G'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'g'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'H'	,0x2074	,0xA724	,0x0000	), // LATIN CAPITAL LETTER EGYPTOLOGICAL AIN
/*GROUP_04           */	DEADTRANS(	L'h'	,0x2074	,0xA725	,0x0000	), // LATIN SMALL LETTER EGYPTOLOGICAL AIN
/*GROUP_04           */	DEADTRANS(	L'I'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'i'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'J'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'j'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'K'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'k'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'L'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'l'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'M'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'm'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'N'	,0x2074	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*GROUP_04           */	DEADTRANS(	L'n'	,0x2074	,0x019E	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*GROUP_04           */	DEADTRANS(	L'O'	,0x2074	,0xA7B6	,0x0000	), // LATIN CAPITAL LETTER OMEGA
/*GROUP_04           */	DEADTRANS(	L'o'	,0x2074	,0xA7B7	,0x0000	), // LATIN SMALL LETTER OMEGA
/*GROUP_04           */	DEADTRANS(	L'P'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'p'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'Q'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'q'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'R'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'r'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'S'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L's'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'T'	,0x2074	,0x03F4	,0x0000	), // GREEK CAPITAL THETA SYMBOL
/*GROUP_04           */	DEADTRANS(	L't'	,0x2074	,0x03B8	,0x0000	), // GREEK SMALL LETTER THETA
/*GROUP_04           */	DEADTRANS(	L'U'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'u'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'V'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'v'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'W'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'w'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'X'	,0x2074	,0x2714	,0x0000	), // HEAVY CHECK MARK
/*GROUP_04           */	DEADTRANS(	L'x'	,0x2074	,0x2713	,0x0000	), // CHECK MARK
/*GROUP_04           */	DEADTRANS(	L'Y'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'y'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'Z'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'z'	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00C0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00E0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00C6	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00E6	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00C7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00E7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00C8	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00E8	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00C9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00E9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0152	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0153	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00D9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00F9	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0020	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0021	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0022	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0023	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0024	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0025	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0026	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0027	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0028	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0029	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002A	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002B	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002C	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002D	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002E	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x002F	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	L'0'	,0x2074	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_04           */	DEADTRANS(	L'1'	,0x2074	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_04           */	DEADTRANS(	L'2'	,0x2074	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_04           */	DEADTRANS(	L'3'	,0x2074	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_04           */	DEADTRANS(	L'4'	,0x2074	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_04           */	DEADTRANS(	L'5'	,0x2074	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_04           */	DEADTRANS(	L'6'	,0x2074	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_04           */	DEADTRANS(	L'7'	,0x2074	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_04           */	DEADTRANS(	L'8'	,0x2074	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_04           */	DEADTRANS(	L'9'	,0x2074	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_04           */	DEADTRANS(	0x003A	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003B	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003C	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003D	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003E	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x003F	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0040	,0x2074	,0x25CC	,0x0000	), // DOTTED CIRCLE
/*GROUP_04           */	DEADTRANS(	0x005B	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005C	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005D	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005E	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x005F	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0060	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x0060	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007B	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007C	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007D	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x007E	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x20AC	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x2026	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00A0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00A7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00B0	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x00B2	,0x2074	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_04           */	DEADTRANS(	0x00B7	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x2019	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_04           */	DEADTRANS(	0x222A	,0x2074	,0x0034	,0x0000	), // DIGIT FOUR
/*GROUP_05           */	DEADTRANS(	L'A'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'a'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'B'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'b'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'C'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'c'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'D'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'd'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'E'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'e'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'F'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'f'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'G'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'g'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'H'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'h'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'I'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'i'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'J'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'j'	,0x2075	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_05           */	DEADTRANS(	L'K'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'k'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'L'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'l'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'M'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'm'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'N'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'n'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'O'	,0x2075	,0x0222	,0x0000	), // LATIN CAPITAL LETTER OU
/*GROUP_05           */	DEADTRANS(	L'o'	,0x2075	,0x0223	,0x0000	), // LATIN SMALL LETTER OU
/*GROUP_05           */	DEADTRANS(	L'P'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'p'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Q'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'q'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'R'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'r'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'S'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L's'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'T'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L't'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'U'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'u'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'V'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'v'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'W'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'w'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'X'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'x'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Y'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'y'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'Z'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'z'	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00C0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00E0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00C6	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00E6	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00C7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00E7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00C8	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00E8	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00C9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00E9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0152	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0153	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00D9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00F9	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0020	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0021	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0022	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0023	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0024	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0025	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0026	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0027	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0028	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0029	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002A	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002B	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002C	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002D	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002E	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x002F	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	L'0'	,0x2075	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_05           */	DEADTRANS(	L'1'	,0x2075	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_05           */	DEADTRANS(	L'2'	,0x2075	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_05           */	DEADTRANS(	L'3'	,0x2075	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_05           */	DEADTRANS(	L'4'	,0x2075	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_05           */	DEADTRANS(	L'5'	,0x2075	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_05           */	DEADTRANS(	L'6'	,0x2075	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_05           */	DEADTRANS(	L'7'	,0x2075	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_05           */	DEADTRANS(	L'8'	,0x2075	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_05           */	DEADTRANS(	L'9'	,0x2075	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_05           */	DEADTRANS(	0x003A	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003B	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003C	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003D	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003E	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x003F	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0040	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005B	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005C	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005D	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005E	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x005F	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0060	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x0060	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007B	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007C	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007D	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x007E	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x20AC	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x2026	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00A0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00A7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00B0	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x00B2	,0x2075	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_05           */	DEADTRANS(	0x00B7	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x2019	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_05           */	DEADTRANS(	0x222A	,0x2075	,0x0035	,0x0000	), // DIGIT FIVE
/*GROUP_06           */	DEADTRANS(	L'A'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'a'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'B'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'b'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'C'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'c'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'D'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'd'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'E'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'e'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'F'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'f'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'G'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'g'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'H'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'h'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'I'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'i'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'J'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'j'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'K'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'k'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'L'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'l'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'M'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'm'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'N'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'n'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'O'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'o'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'P'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'p'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Q'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'q'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'R'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'r'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'S'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L's'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'T'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L't'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'U'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'u'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'V'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'v'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'W'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'w'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'X'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'x'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Y'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'y'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'Z'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'z'	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00C0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00E0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00C6	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00E6	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00C7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00E7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00C8	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00E8	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00C9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00E9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0152	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0153	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00D9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00F9	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0020	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0021	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0022	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0023	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0024	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0025	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0026	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0027	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0028	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0029	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002A	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002B	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002C	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002D	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002E	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x002F	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	L'0'	,0x2076	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_06           */	DEADTRANS(	L'1'	,0x2076	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_06           */	DEADTRANS(	L'2'	,0x2076	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_06           */	DEADTRANS(	L'3'	,0x2076	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_06           */	DEADTRANS(	L'4'	,0x2076	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_06           */	DEADTRANS(	L'5'	,0x2076	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_06           */	DEADTRANS(	L'6'	,0x2076	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_06           */	DEADTRANS(	L'7'	,0x2076	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_06           */	DEADTRANS(	L'8'	,0x2076	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_06           */	DEADTRANS(	L'9'	,0x2076	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_06           */	DEADTRANS(	0x003A	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003B	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003C	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003D	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003E	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x003F	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0040	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005B	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005C	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005D	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005E	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x005F	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0060	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x0060	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007B	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007C	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007D	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x007E	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x20AC	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x2026	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00A0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00A7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00B0	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x00B2	,0x2076	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_06           */	DEADTRANS(	0x00B7	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x2019	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_06           */	DEADTRANS(	0x222A	,0x2076	,0x0036	,0x0000	), // DIGIT SIX
/*GROUP_07           */	DEADTRANS(	L'A'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'a'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'B'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'b'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'C'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'c'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'D'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'd'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'E'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'e'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'F'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'f'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'G'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'g'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'H'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'h'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'I'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'i'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'J'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'j'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'K'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'k'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'L'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'l'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'M'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'm'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'N'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'n'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'O'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'o'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'P'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'p'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Q'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'q'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'R'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'r'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'S'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L's'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'T'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L't'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'U'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'u'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'V'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'v'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'W'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'w'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'X'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'x'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Y'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'y'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'Z'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'z'	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00C0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00E0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00C6	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00E6	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00C7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00E7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00C8	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00E8	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00C9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00E9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0152	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0153	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00D9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00F9	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0020	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0021	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0022	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0023	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0024	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0025	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0026	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0027	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0028	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0029	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002A	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002B	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002C	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002D	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002E	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x002F	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	L'0'	,0x2077	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_07           */	DEADTRANS(	L'1'	,0x2077	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_07           */	DEADTRANS(	L'2'	,0x2077	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_07           */	DEADTRANS(	L'3'	,0x2077	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_07           */	DEADTRANS(	L'4'	,0x2077	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_07           */	DEADTRANS(	L'5'	,0x2077	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_07           */	DEADTRANS(	L'6'	,0x2077	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_07           */	DEADTRANS(	L'7'	,0x2077	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_07           */	DEADTRANS(	L'8'	,0x2077	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_07           */	DEADTRANS(	L'9'	,0x2077	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_07           */	DEADTRANS(	0x003A	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003B	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003C	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003D	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003E	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x003F	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0040	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005B	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005C	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005D	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005E	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x005F	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0060	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x0060	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007B	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007C	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007D	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x007E	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x20AC	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x2026	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00A0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00A7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00B0	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x00B2	,0x2077	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_07           */	DEADTRANS(	0x00B7	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x2019	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_07           */	DEADTRANS(	0x222A	,0x2077	,0x0037	,0x0000	), // DIGIT SEVEN
/*GROUP_08           */	DEADTRANS(	L'A'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'a'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'B'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'b'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'C'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'c'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'D'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'd'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'E'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'e'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'F'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'f'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'G'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'g'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'H'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'h'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'I'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'i'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'J'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'j'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'K'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'k'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'L'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'l'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'M'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'm'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'N'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'n'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'O'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'o'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'P'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'p'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Q'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'q'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'R'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'r'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'S'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L's'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'T'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L't'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'U'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'u'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'V'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'v'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'W'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'w'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'X'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'x'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Y'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'y'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'Z'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'z'	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00C0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00E0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00C6	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00E6	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00C7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00E7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00C8	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00E8	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00C9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00E9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0152	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0153	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00D9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00F9	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0020	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0021	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0022	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0023	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0024	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0025	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0026	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0027	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0028	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0029	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002A	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002B	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002C	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002D	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002E	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x002F	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	L'0'	,0x2078	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_08           */	DEADTRANS(	L'1'	,0x2078	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_08           */	DEADTRANS(	L'2'	,0x2078	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_08           */	DEADTRANS(	L'3'	,0x2078	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_08           */	DEADTRANS(	L'4'	,0x2078	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_08           */	DEADTRANS(	L'5'	,0x2078	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_08           */	DEADTRANS(	L'6'	,0x2078	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_08           */	DEADTRANS(	L'7'	,0x2078	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_08           */	DEADTRANS(	L'8'	,0x2078	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_08           */	DEADTRANS(	L'9'	,0x2078	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_08           */	DEADTRANS(	0x003A	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003B	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003C	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003D	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003E	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x003F	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0040	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005B	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005C	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005D	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005E	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x005F	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0060	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x0060	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007B	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007C	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007D	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x007E	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x20AC	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x2026	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00A0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00A7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00B0	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x00B2	,0x2078	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_08           */	DEADTRANS(	0x00B7	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x2019	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_08           */	DEADTRANS(	0x222A	,0x2078	,0x0038	,0x0000	), // DIGIT EIGHT
/*GROUP_09           */	DEADTRANS(	L'A'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'a'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'B'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'b'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'C'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'c'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'D'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'd'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'E'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'e'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'F'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'f'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'G'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'g'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'H'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'h'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'I'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'i'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'J'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'j'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'K'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'k'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'L'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'l'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'M'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'm'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'N'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'n'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'O'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'o'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'P'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'p'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Q'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'q'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'R'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'r'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'S'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L's'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'T'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L't'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'U'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'u'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'V'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'v'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'W'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'w'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'X'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'x'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Y'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'y'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'Z'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'z'	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00C0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00E0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00C6	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00E6	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00C7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00E7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00C8	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00E8	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00C9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00E9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0152	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0153	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00D9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00F9	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0020	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0021	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0022	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0023	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0024	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0025	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0026	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0027	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0028	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0029	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002A	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002B	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002C	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002D	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002E	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x002F	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	L'0'	,0x2079	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_09           */	DEADTRANS(	L'1'	,0x2079	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_09           */	DEADTRANS(	L'2'	,0x2079	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_09           */	DEADTRANS(	L'3'	,0x2079	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_09           */	DEADTRANS(	L'4'	,0x2079	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_09           */	DEADTRANS(	L'5'	,0x2079	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_09           */	DEADTRANS(	L'6'	,0x2079	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_09           */	DEADTRANS(	L'7'	,0x2079	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_09           */	DEADTRANS(	L'8'	,0x2079	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_09           */	DEADTRANS(	L'9'	,0x2079	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_09           */	DEADTRANS(	0x003A	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003B	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003C	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003D	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003E	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x003F	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0040	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005B	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005C	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005D	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005E	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x005F	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0060	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x0060	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007B	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007C	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007D	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x007E	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x20AC	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x2026	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00A0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00A7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00B0	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x00B2	,0x2079	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_09           */	DEADTRANS(	0x00B7	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x2019	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_09           */	DEADTRANS(	0x222A	,0x2079	,0x0039	,0x0000	), // DIGIT NINE
/*GROUP_10           */	DEADTRANS(	L'A'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'a'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'B'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'b'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'C'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'c'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'D'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'd'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'E'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'e'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'F'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'f'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'G'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'g'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'H'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'h'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'I'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'i'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'J'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'j'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'K'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'k'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'L'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'l'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'M'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'm'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'N'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'n'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'O'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'o'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'P'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'p'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Q'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'q'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'R'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'r'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'S'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L's'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'T'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L't'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'U'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'u'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'V'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'v'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'W'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'w'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'X'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'x'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Y'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'y'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'Z'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'z'	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00C0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00E0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00C6	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00E6	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00C7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00E7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00C8	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00E8	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00C9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00E9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0152	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0153	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00D9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00F9	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0020	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0021	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0022	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0023	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0024	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0025	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0026	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0027	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0028	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0029	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002A	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002B	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002C	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002D	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002E	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x002F	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	L'0'	,0x2070	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_10           */	DEADTRANS(	L'1'	,0x2070	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_10           */	DEADTRANS(	L'2'	,0x2070	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_10           */	DEADTRANS(	L'3'	,0x2070	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_10           */	DEADTRANS(	L'4'	,0x2070	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_10           */	DEADTRANS(	L'5'	,0x2070	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_10           */	DEADTRANS(	L'6'	,0x2070	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_10           */	DEADTRANS(	L'7'	,0x2070	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_10           */	DEADTRANS(	L'8'	,0x2070	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_10           */	DEADTRANS(	L'9'	,0x2070	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_10           */	DEADTRANS(	0x003A	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003B	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003C	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003D	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003E	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x003F	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0040	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005B	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005C	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005D	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005E	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x005F	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0060	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x0060	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007B	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007C	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007D	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x007E	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x20AC	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x2026	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00A0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00A7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00B0	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x00B2	,0x2070	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_10           */	DEADTRANS(	0x00B7	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x2019	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_10           */	DEADTRANS(	0x222A	,0x2070	,0x0030	,0x0000	), // DIGIT ZERO
/*GROUP_11           */	DEADTRANS(	L'A'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'a'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'B'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'b'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'C'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'c'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'D'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'd'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'E'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'e'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'F'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'f'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'G'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'g'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'H'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'h'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'I'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'i'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'J'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'j'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'K'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'k'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'L'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'l'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'M'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'm'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'N'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'n'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'O'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'o'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'P'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'p'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Q'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'q'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'R'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'r'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'S'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L's'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'T'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L't'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'U'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'u'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'V'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'v'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'W'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'w'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'X'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'x'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Y'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'y'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'Z'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'z'	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00C0	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00E0	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00C6	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00E6	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00C7	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00E7	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00C8	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00E8	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00C9	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00E9	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0152	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0153	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00D9	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00F9	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0020	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0021	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0022	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0023	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0024	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0025	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0026	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0027	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0028	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0029	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002A	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002B	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002C	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002D	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002E	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x002F	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	L'0'	,0x00B9	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_11           */	DEADTRANS(	L'1'	,0x00B9	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_11           */	DEADTRANS(	L'2'	,0x00B9	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_11           */	DEADTRANS(	L'3'	,0x00B9	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_11           */	DEADTRANS(	L'4'	,0x00B9	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_11           */	DEADTRANS(	L'5'	,0x00B9	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_11           */	DEADTRANS(	L'6'	,0x00B9	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_11           */	DEADTRANS(	L'7'	,0x00B9	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_11           */	DEADTRANS(	L'8'	,0x00B9	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_11           */	DEADTRANS(	L'9'	,0x00B9	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_11           */	DEADTRANS(	0x003A	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003B	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003C	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003D	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003E	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x003F	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0040	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005B	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005C	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005D	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005E	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x005F	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0060	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x0060	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007B	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007C	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007D	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x007E	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x20AC	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x2026	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00A0	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00A7	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00B0	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x00B2	,0x00B9	,0x00B2	,0x0001	), // SUPERSCRIPT TWO
/*GROUP_11           */	DEADTRANS(	0x00B7	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x2019	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_11           */	DEADTRANS(	0x222A	,0x00B9	,0x0031	,0x0000	), // DIGIT ONE
/*GROUP_12           */	DEADTRANS(	L'A'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'a'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'B'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'b'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'C'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'c'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'D'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'd'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'E'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'e'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'F'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'f'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'G'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'g'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'H'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'h'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'I'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'i'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'J'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'j'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'K'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'k'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'L'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'l'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'M'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'm'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'N'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'n'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'O'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'o'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'P'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'p'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Q'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'q'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'R'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'r'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'S'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L's'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'T'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L't'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'U'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'u'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'V'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'v'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'W'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'w'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'X'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'x'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Y'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'y'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'Z'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'z'	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00C0	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00E0	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00C6	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00E6	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00C7	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00E7	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00C8	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00E8	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00C9	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00E9	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0152	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0153	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00D9	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00F9	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0020	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0021	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0022	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0023	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0024	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0025	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0026	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0027	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0028	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0029	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002A	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002B	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002C	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002D	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002E	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x002F	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'0'	,0x00BD	,0x2070	,0x0001	), // SUPERSCRIPT ZERO
/*GROUP_12           */	DEADTRANS(	L'1'	,0x00BD	,0x00B9	,0x0001	), // SUPERSCRIPT ONE
/*GROUP_12           */	DEADTRANS(	L'2'	,0x00BD	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	L'3'	,0x00BD	,0x00B3	,0x0001	), // SUPERSCRIPT THREE
/*GROUP_12           */	DEADTRANS(	L'4'	,0x00BD	,0x2074	,0x0001	), // SUPERSCRIPT FOUR
/*GROUP_12           */	DEADTRANS(	L'5'	,0x00BD	,0x2075	,0x0001	), // SUPERSCRIPT FIVE
/*GROUP_12           */	DEADTRANS(	L'6'	,0x00BD	,0x2076	,0x0001	), // SUPERSCRIPT SIX
/*GROUP_12           */	DEADTRANS(	L'7'	,0x00BD	,0x2077	,0x0001	), // SUPERSCRIPT SEVEN
/*GROUP_12           */	DEADTRANS(	L'8'	,0x00BD	,0x2078	,0x0001	), // SUPERSCRIPT EIGHT
/*GROUP_12           */	DEADTRANS(	L'9'	,0x00BD	,0x2079	,0x0001	), // SUPERSCRIPT NINE
/*GROUP_12           */	DEADTRANS(	0x003A	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003B	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003C	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003D	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003E	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x003F	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0040	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005B	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005C	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005D	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005E	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x005F	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0060	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x0060	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007B	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007C	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007D	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x007E	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x20AC	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x2026	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00A0	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00A7	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00B0	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00B2	,0x00BD	,0x00BD	,0x0001	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x00B7	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x2019	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*GROUP_12           */	DEADTRANS(	0x222A	,0x00BD	,0x00BD	,0x0000	), // VULGAR FRACTION ONE HALF
/*HACEK              */	DEADTRANS(	0x0020	,0x021F	,0x030C	,0x0000	), // COMBINING CARON
/*HACEK              */	DEADTRANS(	0x00A3	,0x021F	,0x032C	,0x0000	), // COMBINING CARON BELOW
/*HACEK              */	DEADTRANS(	0x00A0	,0x021F	,0x02C7	,0x0000	), // CARON
/*HACEK              */	DEADTRANS(	0x202F	,0x021F	,0x02C7	,0x0000	), // CARON
/*HACEK              */	DEADTRANS(	0x00E1	,0x021F	,0x1DC9	,0x0000	), // COMBINING ACUTE-GRAVE-ACUTE
/*HACEK              */	DEADTRANS(	L'A'	,0x021F	,0x01CD	,0x0000	), // LATIN CAPITAL LETTER A WITH CARON
/*HACEK              */	DEADTRANS(	L'a'	,0x021F	,0x01CE	,0x0000	), // LATIN SMALL LETTER A WITH CARON
/*HACEK              */	DEADTRANS(	L'C'	,0x021F	,0x010C	,0x0000	), // LATIN CAPITAL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'c'	,0x021F	,0x010D	,0x0000	), // LATIN SMALL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'D'	,0x021F	,0x010E	,0x0000	), // LATIN CAPITAL LETTER D WITH CARON
/*HACEK              */	DEADTRANS(	L'd'	,0x021F	,0x010F	,0x0000	), // LATIN SMALL LETTER D WITH CARON
/*HACEK              */	DEADTRANS(	L'E'	,0x021F	,0x011A	,0x0000	), // LATIN CAPITAL LETTER E WITH CARON
/*HACEK              */	DEADTRANS(	L'e'	,0x021F	,0x011B	,0x0000	), // LATIN SMALL LETTER E WITH CARON
/*HACEK              */	DEADTRANS(	L'F'	,0x021F	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'f'	,0x021F	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'G'	,0x021F	,0x01E6	,0x0000	), // LATIN CAPITAL LETTER G WITH CARON
/*HACEK              */	DEADTRANS(	L'g'	,0x021F	,0x01E7	,0x0000	), // LATIN SMALL LETTER G WITH CARON
/*HACEK              */	DEADTRANS(	L'H'	,0x021F	,0x021E	,0x0000	), // LATIN CAPITAL LETTER H WITH CARON
/*HACEK              */	DEADTRANS(	L'h'	,0x021F	,0x021F	,0x0000	), // LATIN SMALL LETTER H WITH CARON
/*HACEK              */	DEADTRANS(	L'I'	,0x021F	,0x01CF	,0x0000	), // LATIN CAPITAL LETTER I WITH CARON
/*HACEK              */	DEADTRANS(	L'i'	,0x021F	,0x01D0	,0x0000	), // LATIN SMALL LETTER I WITH CARON
/*HACEK              */	DEADTRANS(	L'j'	,0x021F	,0x01F0	,0x0000	), // LATIN SMALL LETTER J WITH CARON
/*HACEK              */	DEADTRANS(	L'K'	,0x021F	,0x01E8	,0x0000	), // LATIN CAPITAL LETTER K WITH CARON
/*HACEK              */	DEADTRANS(	L'k'	,0x021F	,0x01E9	,0x0000	), // LATIN SMALL LETTER K WITH CARON
/*HACEK              */	DEADTRANS(	L'L'	,0x021F	,0x013D	,0x0000	), // LATIN CAPITAL LETTER L WITH CARON
/*HACEK              */	DEADTRANS(	L'l'	,0x021F	,0x013E	,0x0000	), // LATIN SMALL LETTER L WITH CARON
/*HACEK              */	DEADTRANS(	L'M'	,0x021F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'm'	,0x021F	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*HACEK              */	DEADTRANS(	L'N'	,0x021F	,0x0147	,0x0000	), // LATIN CAPITAL LETTER N WITH CARON
/*HACEK              */	DEADTRANS(	L'n'	,0x021F	,0x0148	,0x0000	), // LATIN SMALL LETTER N WITH CARON
/*HACEK              */	DEADTRANS(	L'O'	,0x021F	,0x01D1	,0x0000	), // LATIN CAPITAL LETTER O WITH CARON
/*HACEK              */	DEADTRANS(	L'o'	,0x021F	,0x01D2	,0x0000	), // LATIN SMALL LETTER O WITH CARON
/*HACEK              */	DEADTRANS(	L'R'	,0x021F	,0x0158	,0x0000	), // LATIN CAPITAL LETTER R WITH CARON
/*HACEK              */	DEADTRANS(	L'r'	,0x021F	,0x0159	,0x0000	), // LATIN SMALL LETTER R WITH CARON
/*HACEK              */	DEADTRANS(	L'S'	,0x021F	,0x0160	,0x0000	), // LATIN CAPITAL LETTER S WITH CARON
/*HACEK              */	DEADTRANS(	L's'	,0x021F	,0x0161	,0x0000	), // LATIN SMALL LETTER S WITH CARON
/*HACEK              */	DEADTRANS(	L'T'	,0x021F	,0x0164	,0x0000	), // LATIN CAPITAL LETTER T WITH CARON
/*HACEK              */	DEADTRANS(	L't'	,0x021F	,0x0165	,0x0000	), // LATIN SMALL LETTER T WITH CARON
/*HACEK              */	DEADTRANS(	L'U'	,0x021F	,0x01D3	,0x0000	), // LATIN CAPITAL LETTER U WITH CARON
/*HACEK              */	DEADTRANS(	L'u'	,0x021F	,0x01D4	,0x0000	), // LATIN SMALL LETTER U WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x021F	,0x017D	,0x0000	), // LATIN CAPITAL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x021F	,0x017E	,0x0000	), // LATIN SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	0x00C9	,0x021F	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x00E9	,0x021F	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x0152	,0x021F	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x0153	,0x021F	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	0x00F9	,0x021F	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x0023	,0x021F	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*HACEK              */	DEADTRANS(	0x0025	,0x021F	,0x2031	,0x0001	), // PER TEN THOUSAND SIGN
/*HACEK              */	DEADTRANS(	0x0027	,0x021F	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x002E	,0x021F	,0x1E67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HACEK              */	DEADTRANS(	L'0'	,0x021F	,0x2080	,0x0000	), // SUBSCRIPT ZERO
/*HACEK              */	DEADTRANS(	L'1'	,0x021F	,0x2081	,0x0000	), // SUBSCRIPT ONE
/*HACEK              */	DEADTRANS(	L'2'	,0x021F	,0x2082	,0x0000	), // SUBSCRIPT TWO
/*HACEK              */	DEADTRANS(	L'3'	,0x021F	,0x2083	,0x0000	), // SUBSCRIPT THREE
/*HACEK              */	DEADTRANS(	L'4'	,0x021F	,0x2084	,0x0000	), // SUBSCRIPT FOUR
/*HACEK              */	DEADTRANS(	L'5'	,0x021F	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*HACEK              */	DEADTRANS(	L'6'	,0x021F	,0x2086	,0x0000	), // SUBSCRIPT SIX
/*HACEK              */	DEADTRANS(	L'7'	,0x021F	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*HACEK              */	DEADTRANS(	L'8'	,0x021F	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*HACEK              */	DEADTRANS(	L'9'	,0x021F	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*HACEK              */	DEADTRANS(	0x003C	,0x021F	,0x2277	,0x0000	), // GREATER-THAN OR LESS-THAN
/*HACEK              */	DEADTRANS(	0x003D	,0x021F	,0x2267	,0x0000	), // GREATER-THAN OVER EQUAL TO
/*HACEK              */	DEADTRANS(	0x003E	,0x021F	,0x2A7E	,0x0000	), // GREATER-THAN OR SLANTED EQUAL TO
/*HACEK              */	DEADTRANS(	0x0040	,0x021F	,0x25B2	,0x0000	), // BLACK UP-POINTING TRIANGLE
/*HACEK              */	DEADTRANS(	0x005F	,0x021F	,0x2265	,0x0000	), // GREATER-THAN OR EQUAL TO
/*HACEK              */	DEADTRANS(	0x007C	,0x021F	,0x2021	,0x0000	), // DOUBLE DAGGER
/*HACEK              */	DEADTRANS(	0x00A9	,0x021F	,0x010D	,0x0001	), // LATIN SMALL LETTER C WITH CARON
/*HACEK              */	DEADTRANS(	L'D'	,0x010D	,0x01C5	,0x0001	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x01C5	,0x01C4	,0x0000	), // LATIN CAPITAL LETTER DZ WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x01C5	,0x01C5	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*HACEK              */	DEADTRANS(	L'd'	,0x010D	,0x01C6	,0x0000	), // LATIN SMALL LETTER DZ WITH CARON
/*HACEK              */	DEADTRANS(	L'Z'	,0x010D	,0x01EE	,0x0000	), // LATIN CAPITAL LETTER EZH WITH CARON
/*HACEK              */	DEADTRANS(	L'z'	,0x010D	,0x01EF	,0x0000	), // LATIN SMALL LETTER EZH WITH CARON
/*HACEK              */	DEADTRANS(	0x00EA	,0x021F	,0x1E19	,0x0001	), // LATIN SMALL LETTER E WITH CIRCUMFLEX BELOW
/*HACEK              */	DEADTRANS(	0x00EB	,0x021F	,0x01DA	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x00C8	,0x01DA	,0x01D9	,0x0000	), // LATIN CAPITAL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x00E8	,0x01DA	,0x01DA	,0x0000	), // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
/*HACEK              */	DEADTRANS(	0x2019	,0x021F	,0x02BB	,0x0000	), // MODIFIER LETTER TURNED COMMA
/*HACEK              */	DEADTRANS(	0x2610	,0x021F	,0x2611	,0x0000	), // BALLOT BOX WITH CHECK
/*HACEK              */	DEADTRANS(	0x022F	,0x021F	,0x1E67	,0x0001	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HACEK&DOT_ABOVE    */	DEADTRANS(	L'S'	,0x1E67	,0x1E66	,0x0000	), // LATIN CAPITAL LETTER S WITH CARON AND DOT ABOVE
/*HACEK&DOT_ABOVE    */	DEADTRANS(	L's'	,0x1E67	,0x1E67	,0x0000	), // LATIN SMALL LETTER S WITH CARON AND DOT ABOVE
/*HEBREW             */	DEADTRANS(	L'a'	,0x05D0	,0x05D0	,0x0000	), // HEBREW LETTER ALEF
/*HEBREW             */	DEADTRANS(	0x05D0	,0x05D0	,0x05D1	,0x0001	), // HEBREW LETTER BET
/*HEBREW             */	DEADTRANS(	L'b'	,0x05D0	,0x05D1	,0x0000	), // HEBREW LETTER BET
/*HEBREW             */	DEADTRANS(	L'd'	,0x05D0	,0x05D3	,0x0000	), // HEBREW LETTER DALET
/*HEBREW             */	DEADTRANS(	L'g'	,0x05D0	,0x05D2	,0x0000	), // HEBREW LETTER GIMEL
/*HEBREW             */	DEADTRANS(	L'h'	,0x05D0	,0x05D4	,0x0000	), // HEBREW LETTER HE
/*HEBREW             */	DEADTRANS(	L'i'	,0x05D0	,0x05D5	,0x0000	), // HEBREW LETTER VAV
/*HEBREW             */	DEADTRANS(	L'j'	,0x05D0	,0x05D9	,0x0000	), // HEBREW LETTER YOD
/*HEBREW             */	DEADTRANS(	L'K'	,0x05D0	,0x05DA	,0x0000	), // HEBREW LETTER FINAL KAF
/*HEBREW             */	DEADTRANS(	L'k'	,0x05D0	,0x05DB	,0x0000	), // HEBREW LETTER KAF
/*HEBREW             */	DEADTRANS(	L'l'	,0x05D0	,0x05DC	,0x0000	), // HEBREW LETTER LAMED
/*HEBREW             */	DEADTRANS(	L'M'	,0x05D0	,0x05DD	,0x0000	), // HEBREW LETTER FINAL MEM
/*HEBREW             */	DEADTRANS(	L'm'	,0x05D0	,0x05DE	,0x0000	), // HEBREW LETTER MEM
/*HEBREW             */	DEADTRANS(	L'N'	,0x05D0	,0x05DF	,0x0000	), // HEBREW LETTER FINAL NUN
/*HEBREW             */	DEADTRANS(	L'n'	,0x05D0	,0x05E0	,0x0000	), // HEBREW LETTER NUN
/*HEBREW             */	DEADTRANS(	L'P'	,0x05D0	,0x05E3	,0x0000	), // HEBREW LETTER FINAL PE
/*HEBREW             */	DEADTRANS(	L'p'	,0x05D0	,0x05E4	,0x0000	), // HEBREW LETTER PE
/*HEBREW             */	DEADTRANS(	L'q'	,0x05D0	,0x05E7	,0x0000	), // HEBREW LETTER QOF
/*HEBREW             */	DEADTRANS(	L'r'	,0x05D0	,0x05E8	,0x0000	), // HEBREW LETTER RESH
/*HEBREW             */	DEADTRANS(	L's'	,0x05D0	,0x05E1	,0x0000	), // HEBREW LETTER SAMEKH
/*HEBREW             */	DEADTRANS(	L't'	,0x05D0	,0x05EA	,0x0000	), // HEBREW LETTER TAV
/*HEBREW             */	DEADTRANS(	L'u'	,0x05D0	,0x05D8	,0x0000	), // HEBREW LETTER TET
/*HEBREW             */	DEADTRANS(	L'v'	,0x05D0	,0x05E2	,0x0000	), // HEBREW LETTER AYIN
/*HEBREW             */	DEADTRANS(	L'w'	,0x05D0	,0x05E9	,0x0000	), // HEBREW LETTER SHIN
/*HEBREW             */	DEADTRANS(	L'x'	,0x05D0	,0x05D7	,0x0000	), // HEBREW LETTER HET
/*HEBREW             */	DEADTRANS(	L'Y'	,0x05D0	,0x05E5	,0x0000	), // HEBREW LETTER FINAL TSADI
/*HEBREW             */	DEADTRANS(	L'y'	,0x05D0	,0x05E6	,0x0000	), // HEBREW LETTER TSADI
/*HEBREW             */	DEADTRANS(	L'z'	,0x05D0	,0x05D6	,0x0000	), // HEBREW LETTER ZAYIN
/*HEBREW_LOCK        */	DEADTRANS(	L'a'	,0x05D1	,0x05D0	,0x0001	), // HEBREW LETTER ALEF
/*HEBREW_LOCK        */	DEADTRANS(	L'b'	,0x05D1	,0x05D1	,0x0001	), // HEBREW LETTER BET
/*HEBREW_LOCK        */	DEADTRANS(	L'd'	,0x05D1	,0x05D3	,0x0001	), // HEBREW LETTER DALET
/*HEBREW_LOCK        */	DEADTRANS(	L'g'	,0x05D1	,0x05D2	,0x0001	), // HEBREW LETTER GIMEL
/*HEBREW_LOCK        */	DEADTRANS(	L'h'	,0x05D1	,0x05D4	,0x0001	), // HEBREW LETTER HE
/*HEBREW_LOCK        */	DEADTRANS(	L'i'	,0x05D1	,0x05D5	,0x0001	), // HEBREW LETTER VAV
/*HEBREW_LOCK        */	DEADTRANS(	L'j'	,0x05D1	,0x05D9	,0x0001	), // HEBREW LETTER YOD
/*HEBREW_LOCK        */	DEADTRANS(	L'K'	,0x05D1	,0x05DA	,0x0001	), // HEBREW LETTER FINAL KAF
/*HEBREW_LOCK        */	DEADTRANS(	L'k'	,0x05D1	,0x05DB	,0x0001	), // HEBREW LETTER KAF
/*HEBREW_LOCK        */	DEADTRANS(	L'l'	,0x05D1	,0x05DC	,0x0001	), // HEBREW LETTER LAMED
/*HEBREW_LOCK        */	DEADTRANS(	L'M'	,0x05D1	,0x05DD	,0x0001	), // HEBREW LETTER FINAL MEM
/*HEBREW_LOCK        */	DEADTRANS(	L'm'	,0x05D1	,0x05DE	,0x0001	), // HEBREW LETTER MEM
/*HEBREW_LOCK        */	DEADTRANS(	L'N'	,0x05D1	,0x05DF	,0x0001	), // HEBREW LETTER FINAL NUN
/*HEBREW_LOCK        */	DEADTRANS(	L'n'	,0x05D1	,0x05E0	,0x0001	), // HEBREW LETTER NUN
/*HEBREW_LOCK        */	DEADTRANS(	L'P'	,0x05D1	,0x05E3	,0x0001	), // HEBREW LETTER FINAL PE
/*HEBREW_LOCK        */	DEADTRANS(	L'p'	,0x05D1	,0x05E4	,0x0001	), // HEBREW LETTER PE
/*HEBREW_LOCK        */	DEADTRANS(	L'q'	,0x05D1	,0x05E7	,0x0001	), // HEBREW LETTER QOF
/*HEBREW_LOCK        */	DEADTRANS(	L'r'	,0x05D1	,0x05E8	,0x0001	), // HEBREW LETTER RESH
/*HEBREW_LOCK        */	DEADTRANS(	L's'	,0x05D1	,0x05E1	,0x0001	), // HEBREW LETTER SAMEKH
/*HEBREW_LOCK        */	DEADTRANS(	L't'	,0x05D1	,0x05EA	,0x0001	), // HEBREW LETTER TAV
/*HEBREW_LOCK        */	DEADTRANS(	L'u'	,0x05D1	,0x05D8	,0x0001	), // HEBREW LETTER TET
/*HEBREW_LOCK        */	DEADTRANS(	L'v'	,0x05D1	,0x05E2	,0x0001	), // HEBREW LETTER AYIN
/*HEBREW_LOCK        */	DEADTRANS(	L'w'	,0x05D1	,0x05E9	,0x0001	), // HEBREW LETTER SHIN
/*HEBREW_LOCK        */	DEADTRANS(	L'x'	,0x05D1	,0x05D7	,0x0001	), // HEBREW LETTER HET
/*HEBREW_LOCK        */	DEADTRANS(	L'Y'	,0x05D1	,0x05E5	,0x0001	), // HEBREW LETTER FINAL TSADI
/*HEBREW_LOCK        */	DEADTRANS(	L'y'	,0x05D1	,0x05E6	,0x0001	), // HEBREW LETTER TSADI
/*HEBREW_LOCK        */	DEADTRANS(	L'z'	,0x05D1	,0x05D6	,0x0001	), // HEBREW LETTER ZAYIN
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'B'	,0x0183	,0x0182	,0x0000	), // LATIN CAPITAL LETTER B WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'b'	,0x0183	,0x0183	,0x0000	), // LATIN SMALL LETTER B WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'D'	,0x0183	,0x018B	,0x0000	), // LATIN CAPITAL LETTER D WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'd'	,0x0183	,0x018C	,0x0000	), // LATIN SMALL LETTER D WITH TOPBAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'H'	,0x0183	,0xA7F8	,0x0000	), // MODIFIER LETTER CAPITAL H WITH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'i'	,0x0183	,0x1DA4	,0x0000	), // MODIFIER LETTER SMALL I WITH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'L'	,0x0183	,0xA748	,0x0000	), // LATIN CAPITAL LETTER L WITH HIGH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'l'	,0x0183	,0xA749	,0x0000	), // LATIN SMALL LETTER L WITH HIGH STROKE
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'o'	,0x0183	,0x1DB1	,0x0000	), // MODIFIER LETTER SMALL BARRED O
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'u'	,0x0183	,0x1DB6	,0x0000	), // MODIFIER LETTER SMALL U BAR
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'v'	,0x0183	,0x02C5	,0x0000	), // MODIFIER LETTER DOWN ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x002D	,0x0183	,0x207B	,0x0000	), // SUPERSCRIPT MINUS
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'2'	,0x0183	,0xA71C	,0x0000	), // MODIFIER LETTER RAISED DOWN ARROW
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	L'8'	,0x0183	,0xA71B	,0x0000	), // MODIFIER LETTER RAISED UP ARROW
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x003C	,0x0183	,0x02C2	,0x0000	), // MODIFIER LETTER LEFT ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x003E	,0x0183	,0x02C3	,0x0000	), // MODIFIER LETTER RIGHT ARROWHEAD
/*HIGH_BAR_(HORIZONT)*/	DEADTRANS(	0x005E	,0x0183	,0x02C4	,0x0000	), // MODIFIER LETTER UP ARROWHEAD
/*HOOK_ABOVE         */	DEADTRANS(	0x0020	,0x1EBB	,0x0309	,0x0000	), // COMBINING HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'A'	,0x1EBB	,0x1EA2	,0x0000	), // LATIN CAPITAL LETTER A WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'a'	,0x1EBB	,0x1EA3	,0x0000	), // LATIN SMALL LETTER A WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'b'	,0x1EBB	,0x1D80	,0x0000	), // LATIN SMALL LETTER B WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'c'	,0x1EBB	,0xA794	,0x0000	), // LATIN SMALL LETTER C WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'd'	,0x1EBB	,0x1D81	,0x0000	), // LATIN SMALL LETTER D WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'E'	,0x1EBB	,0x1EBA	,0x0000	), // LATIN CAPITAL LETTER E WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'e'	,0x1EBB	,0x1EBB	,0x0000	), // LATIN SMALL LETTER E WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'f'	,0x1EBB	,0x1D82	,0x0000	), // LATIN SMALL LETTER F WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'g'	,0x1EBB	,0x1D83	,0x0000	), // LATIN SMALL LETTER G WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'h'	,0x1EBB	,0xA795	,0x0000	), // LATIN SMALL LETTER H WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'I'	,0x1EBB	,0x1EC8	,0x0000	), // LATIN CAPITAL LETTER I WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'i'	,0x1EBB	,0x1EC9	,0x0000	), // LATIN SMALL LETTER I WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'k'	,0x1EBB	,0x1D84	,0x0000	), // LATIN SMALL LETTER K WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'l'	,0x1EBB	,0x1D85	,0x0000	), // LATIN SMALL LETTER L WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'm'	,0x1EBB	,0x1D86	,0x0000	), // LATIN SMALL LETTER M WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'n'	,0x1EBB	,0x1D87	,0x0000	), // LATIN SMALL LETTER N WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'O'	,0x1EBB	,0x1ECE	,0x0000	), // LATIN CAPITAL LETTER O WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'o'	,0x1EBB	,0x1ECF	,0x0000	), // LATIN SMALL LETTER O WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'p'	,0x1EBB	,0x1D88	,0x0000	), // LATIN SMALL LETTER P WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'r'	,0x1EBB	,0x1D89	,0x0000	), // LATIN SMALL LETTER R WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L's'	,0x1EBB	,0x1D8A	,0x0000	), // LATIN SMALL LETTER S WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L't'	,0x1EBB	,0x01AB	,0x0000	), // LATIN SMALL LETTER T WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'U'	,0x1EBB	,0x1EE6	,0x0000	), // LATIN CAPITAL LETTER U WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'u'	,0x1EBB	,0x1EE7	,0x0000	), // LATIN SMALL LETTER U WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'v'	,0x1EBB	,0x1D8C	,0x0000	), // LATIN SMALL LETTER V WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'x'	,0x1EBB	,0x1D8D	,0x0000	), // LATIN SMALL LETTER X WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'Y'	,0x1EBB	,0x1EF6	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'y'	,0x1EBB	,0x1EF7	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	L'z'	,0x1EBB	,0x1D8E	,0x0000	), // LATIN SMALL LETTER Z WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	0x0029	,0x1EBB	,0x1EB3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x002C	,0x1EBB	,0x1EDF	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x002D	,0x1ECF	,0x266B	,0x0000	), // BEAMED EIGHTH NOTES
/*HOOK_ABOVE         */	DEADTRANS(	0x003C	,0x1EBB	,0x1ED5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x003D	,0x1ECF	,0x266C	,0x0000	), // BEAMED SIXTEENTH NOTES
/*HOOK_ABOVE         */	DEADTRANS(	0x005D	,0x1EBB	,0xAB32	,0x0001	), // LATIN SMALL LETTER BLACKLETTER E
/*HOOK_ABOVE         */	DEADTRANS(	0x00A9	,0x1EBB	,0x1D8B	,0x0001	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L'c'	,0x1D8B	,0x1D8B	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	L's'	,0x1D8B	,0x1D8B	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*HOOK_ABOVE         */	DEADTRANS(	0x00EA	,0x1EBB	,0x1ED5	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x0229	,0x1EBB	,0x1EDF	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x014F	,0x1EBB	,0x1EB3	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE
/*HOOK_ABOVE         */	DEADTRANS(	0x01A1	,0x1EBB	,0x1EDF	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x0020	,0x01A1	,0x031B	,0x0000	), // COMBINING HORN
/*HORN               */	DEADTRANS(	L'O'	,0x01A1	,0x01A0	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN
/*HORN               */	DEADTRANS(	L'o'	,0x01A1	,0x01A1	,0x0000	), // LATIN SMALL LETTER O WITH HORN
/*HORN               */	DEADTRANS(	L'U'	,0x01A1	,0x01AF	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN
/*HORN               */	DEADTRANS(	L'u'	,0x01A1	,0x01B0	,0x0000	), // LATIN SMALL LETTER U WITH HORN
/*HORN               */	DEADTRANS(	0x0021	,0x01A1	,0x1EE3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN               */	DEADTRANS(	0x0027	,0x01A1	,0x1EDB	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN               */	DEADTRANS(	0x005D	,0x01A1	,0x1EDF	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x0060	,0x01A1	,0x1EDD	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN               */	DEADTRANS(	0x007E	,0x01A1	,0x1EE1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN               */	DEADTRANS(	0x00E1	,0x01A1	,0x1EDB	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN               */	DEADTRANS(	0x00F2	,0x01A1	,0x1EDD	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN               */	DEADTRANS(	0x00F5	,0x01A1	,0x1EE1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN               */	DEADTRANS(	0x1EBB	,0x01A1	,0x1EDF	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN               */	DEADTRANS(	0x1EE5	,0x01A1	,0x1EE3	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'C'	,0x1E09	,0x1E08	,0x0000	), // LATIN CAPITAL LETTER C WITH CEDILLA AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'c'	,0x1E09	,0x1E09	,0x0000	), // LATIN SMALL LETTER C WITH CEDILLA AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'O'	,0x1E09	,0x1EDA	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'o'	,0x1E09	,0x1EDB	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'U'	,0x1E09	,0x1EE8	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND ACUTE
/*HORN&ACUTE_ACCENT  */	DEADTRANS(	L'u'	,0x1E09	,0x1EE9	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND ACUTE
/*HORN&DOT_BELOW     */	DEADTRANS(	L'O'	,0x1EE3	,0x1EE2	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'o'	,0x1EE3	,0x1EE3	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'U'	,0x1EE3	,0x1EF0	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND DOT BELOW
/*HORN&DOT_BELOW     */	DEADTRANS(	L'u'	,0x1EE3	,0x1EF1	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND DOT BELOW
/*HORN&GRAVE         */	DEADTRANS(	L'O'	,0x1EDD	,0x1EDC	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'o'	,0x1EDD	,0x1EDD	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'U'	,0x1EDD	,0x1EEA	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND GRAVE
/*HORN&GRAVE         */	DEADTRANS(	L'u'	,0x1EDD	,0x1EEB	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND GRAVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'O'	,0x1EDF	,0x1EDE	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'o'	,0x1EDF	,0x1EDF	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'U'	,0x1EDF	,0x1EEC	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND HOOK ABOVE
/*HORN&HOOK_ABOVE    */	DEADTRANS(	L'u'	,0x1EDF	,0x1EED	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND HOOK ABOVE
/*HORN&TILDE         */	DEADTRANS(	L'O'	,0x1EE1	,0x1EE0	,0x0000	), // LATIN CAPITAL LETTER O WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'o'	,0x1EE1	,0x1EE1	,0x0000	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'U'	,0x1EE1	,0x1EEE	,0x0000	), // LATIN CAPITAL LETTER U WITH HORN AND TILDE
/*HORN&TILDE         */	DEADTRANS(	L'u'	,0x1EE1	,0x1EEF	,0x0000	), // LATIN SMALL LETTER U WITH HORN AND TILDE
/*INSULAR            */	DEADTRANS(	L'D'	,0x1D79	,0xA779	,0x0000	), // LATIN CAPITAL LETTER INSULAR D
/*INSULAR            */	DEADTRANS(	L'd'	,0x1D79	,0xA77A	,0x0000	), // LATIN SMALL LETTER INSULAR D
/*INSULAR            */	DEADTRANS(	L'F'	,0x1D79	,0xA77B	,0x0000	), // LATIN CAPITAL LETTER INSULAR F
/*INSULAR            */	DEADTRANS(	L'f'	,0x1D79	,0xA77C	,0x0000	), // LATIN SMALL LETTER INSULAR F
/*INSULAR            */	DEADTRANS(	L'G'	,0x1D79	,0xA77D	,0x0000	), // LATIN CAPITAL LETTER INSULAR G
/*INSULAR            */	DEADTRANS(	L'g'	,0x1D79	,0x1D79	,0x0000	), // LATIN SMALL LETTER INSULAR G
/*INSULAR            */	DEADTRANS(	L'R'	,0x1D79	,0xA782	,0x0000	), // LATIN CAPITAL LETTER INSULAR R
/*INSULAR            */	DEADTRANS(	L'r'	,0x1D79	,0xA783	,0x0000	), // LATIN SMALL LETTER INSULAR R
/*INSULAR            */	DEADTRANS(	L'S'	,0x1D79	,0xA784	,0x0000	), // LATIN CAPITAL LETTER INSULAR S
/*INSULAR            */	DEADTRANS(	L's'	,0x1D79	,0xA785	,0x0000	), // LATIN SMALL LETTER INSULAR S
/*INSULAR            */	DEADTRANS(	L'T'	,0x1D79	,0xA786	,0x0000	), // LATIN CAPITAL LETTER INSULAR T
/*INSULAR            */	DEADTRANS(	L't'	,0x1D79	,0xA787	,0x0000	), // LATIN SMALL LETTER INSULAR T
/*INVERTED           */	DEADTRANS(	L'A'	,0x0281	,0x2C6F	,0x0000	), // LATIN CAPITAL LETTER TURNED A
/*INVERTED           */	DEADTRANS(	L'a'	,0x0281	,0xAB64	,0x0000	), // LATIN SMALL LETTER INVERTED ALPHA
/*INVERTED           */	DEADTRANS(	L'M'	,0x0281	,0xA7FD	,0x0000	), // LATIN EPIGRAPHIC LETTER INVERTED M
/*INVERTED           */	DEADTRANS(	L'o'	,0x0281	,0xAB40	,0x0000	), // LATIN SMALL LETTER INVERTED OE
/*INVERTED           */	DEADTRANS(	L'T'	,0x0281	,0xA7B1	,0x0000	), // LATIN CAPITAL LETTER TURNED T
/*INVERTED           */	DEADTRANS(	L'V'	,0x0281	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*INVERTED           */	DEADTRANS(	L'v'	,0x0281	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*INVERTED           */	DEADTRANS(	0x00F9	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED           */	DEADTRANS(	0x0021	,0x0281	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*INVERTED           */	DEADTRANS(	0x0025	,0x0281	,0x2030	,0x0000	), // PER MILLE SIGN
/*INVERTED           */	DEADTRANS(	0x0027	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED           */	DEADTRANS(	0x003F	,0x0281	,0x00BF	,0x0000	), // INVERTED QUESTION MARK
/*INVERTED           */	DEADTRANS(	0x2019	,0x0281	,0x0296	,0x0000	), // LATIN LETTER INVERTED GLOTTAL STOP
/*INVERTED_BREVE     */	DEADTRANS(	0x0020	,0x0213	,0x0311	,0x0000	), // COMBINING INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	0x202F	,0x0213	,0x2229	,0x0000	), // INTERSECTION
/*INVERTED_BREVE     */	DEADTRANS(	0x00A0	,0x0213	,0x2229	,0x0000	), // INTERSECTION
/*INVERTED_BREVE     */	DEADTRANS(	0x0029	,0x0213	,0x2050	,0x0000	), // CLOSE UP
/*INVERTED_BREVE     */	DEADTRANS(	0x002E	,0x0213	,0x0352	,0x0000	), // COMBINING FERMATA
/*INVERTED_BREVE     */	DEADTRANS(	L'A'	,0x0213	,0x0202	,0x0000	), // LATIN CAPITAL LETTER A WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'a'	,0x0213	,0x0203	,0x0000	), // LATIN SMALL LETTER A WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'E'	,0x0213	,0x0206	,0x0000	), // LATIN CAPITAL LETTER E WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'e'	,0x0213	,0x0207	,0x0000	), // LATIN SMALL LETTER E WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'H'	,0x0213	,0x1E2A	,0x0000	), // LATIN CAPITAL LETTER H WITH BREVE BELOW
/*INVERTED_BREVE     */	DEADTRANS(	L'h'	,0x0213	,0x1E2B	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*INVERTED_BREVE     */	DEADTRANS(	L'I'	,0x0213	,0x020A	,0x0000	), // LATIN CAPITAL LETTER I WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'i'	,0x0213	,0x020B	,0x0000	), // LATIN SMALL LETTER I WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'O'	,0x0213	,0x020E	,0x0000	), // LATIN CAPITAL LETTER O WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'o'	,0x0213	,0x020F	,0x0000	), // LATIN SMALL LETTER O WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'R'	,0x0213	,0x0212	,0x0000	), // LATIN CAPITAL LETTER R WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'r'	,0x0213	,0x0213	,0x0000	), // LATIN SMALL LETTER R WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'U'	,0x0213	,0x0216	,0x0000	), // LATIN CAPITAL LETTER U WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	L'u'	,0x0213	,0x0217	,0x0000	), // LATIN SMALL LETTER U WITH INVERTED BREVE
/*INVERTED_BREVE     */	DEADTRANS(	0x0115	,0x0213	,0x1E2B	,0x0000	), // LATIN SMALL LETTER H WITH BREVE BELOW
/*LONG               */	DEADTRANS(	L'c'	,0x007C	,0x0297	,0x0000	), // LATIN LETTER STRETCHED C
/*LONG               */	DEADTRANS(	L'I'	,0x007C	,0xA7FE	,0x0000	), // LATIN EPIGRAPHIC LETTER I LONGA
/*LONG               */	DEADTRANS(	L'i'	,0x007C	,0xA7FE	,0x0000	), // LATIN EPIGRAPHIC LETTER I LONGA
/*LONG               */	DEADTRANS(	L'N'	,0x007C	,0x0220	,0x0000	), // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
/*LONG               */	DEADTRANS(	L'n'	,0x007C	,0x019E	,0x0000	), // LATIN SMALL LETTER N WITH LONG RIGHT LEG
/*LONG               */	DEADTRANS(	L'o'	,0x007C	,0x2C77	,0x0000	), // LATIN SMALL LETTER TAILLESS PHI
/*LONG               */	DEADTRANS(	L'P'	,0x007C	,0x00B6	,0x0000	), // PILCROW SIGN
/*LONG               */	DEADTRANS(	L'p'	,0x007C	,0x00B6	,0x0000	), // PILCROW SIGN
/*LONG               */	DEADTRANS(	L'R'	,0x007C	,0xAB46	,0x0000	), // LATIN LETTER SMALL CAPITAL R WITH RIGHT LEG
/*LONG               */	DEADTRANS(	L'r'	,0x007C	,0x027C	,0x0000	), // LATIN SMALL LETTER R WITH LONG LEG
/*LONG               */	DEADTRANS(	L'V'	,0x007C	,0xA768	,0x0000	), // LATIN CAPITAL LETTER VEND
/*LONG               */	DEADTRANS(	L'v'	,0x007C	,0xA769	,0x0000	), // LATIN SMALL LETTER VEND
/*LONG               */	DEADTRANS(	L'x'	,0x007C	,0xAB57	,0x0000	), // LATIN SMALL LETTER X WITH LONG LEFT LEG
/*LONG               */	DEADTRANS(	L'0'	,0x007C	,0x02E9	,0x0000	), // MODIFIER LETTER EXTRA-LOW TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0x007C	,0x02E8	,0x0000	), // MODIFIER LETTER LOW TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0x007C	,0x02E7	,0x0000	), // MODIFIER LETTER MID TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0x007C	,0x02E6	,0x0000	), // MODIFIER LETTER HIGH TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0x007C	,0x02E5	,0x0000	), // MODIFIER LETTER EXTRA-HIGH TONE BAR
/*LONG               */	DEADTRANS(	0x0023	,0x007C	,0x2E38	,0x0000	), // TURNED DAGGER
/*LONG               */	DEADTRANS(	0x0025	,0x007C	,0x2E4B	,0x0000	), // TRIPLE DAGGER
/*LONG               */	DEADTRANS(	0x002B	,0x007C	,0x2020	,0x0000	), // DAGGER
/*LONG               */	DEADTRANS(	0x002D	,0x007C	,0xA714	,0x0001	), // MODIFIER LETTER MID LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'0'	,0xA714	,0xA716	,0x0000	), // MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0xA714	,0xA715	,0x0000	), // MODIFIER LETTER LOW LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0xA714	,0xA714	,0x0000	), // MODIFIER LETTER MID LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0xA714	,0xA713	,0x0000	), // MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0xA714	,0xA712	,0x0000	), // MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	0x002E	,0x007C	,0xA70F	,0x0001	), // MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'0'	,0xA70F	,0xA711	,0x0000	), // MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'1'	,0xA70F	,0xA710	,0x0000	), // MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'2'	,0xA70F	,0xA70F	,0x0000	), // MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'3'	,0xA70F	,0xA70E	,0x0000	), // MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	L'4'	,0xA70F	,0xA70D	,0x0000	), // MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*LONG               */	DEADTRANS(	0x003A	,0xA70F	,0x205B	,0x0000	), // FOUR DOT MARK
/*LONG               */	DEADTRANS(	0x003A	,0x007C	,0x205A	,0x0000	), // TWO DOT PUNCTUATION
/*LONG               */	DEADTRANS(	0x003C	,0x007C	,0x2E36	,0x0000	), // DAGGER WITH LEFT GUARD
/*LONG               */	DEADTRANS(	0x003D	,0x007C	,0x2021	,0x0000	), // DOUBLE DAGGER
/*LONG               */	DEADTRANS(	0x003E	,0x007C	,0x2E37	,0x0000	), // DAGGER WITH RIGHT GUARD
/*LONG               */	DEADTRANS(	0x007C	,0x007C	,0x2016	,0x0000	), // DOUBLE VERTICAL LINE
/*LONG               */	DEADTRANS(	0x00B0	,0x007C	,0x2020	,0x0000	), // DAGGER
/*LONG_BAR           */	DEADTRANS(	0x0020	,0x2013	,0x0336	,0x0000	), // COMBINING LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	0x0021	,0x2013	,0x2013	,0x0000	), // EN DASH
/*LONG_BAR           */	DEADTRANS(	0x002D	,0x2013	,0x2014	,0x0000	), // EM DASH
/*LONG_BAR           */	DEADTRANS(	L'O'	,0x2013	,0xA74A	,0x0000	), // LATIN CAPITAL LETTER O WITH LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	L'o'	,0x2013	,0xA74B	,0x0000	), // LATIN SMALL LETTER O WITH LONG STROKE OVERLAY
/*LONG_BAR           */	DEADTRANS(	L'0'	,0x2013	,0x2195	,0x0000	), // UP DOWN ARROW
/*LONG_BAR           */	DEADTRANS(	L'1'	,0x2013	,0x2199	,0x0000	), // SOUTH WEST ARROW
/*LONG_BAR           */	DEADTRANS(	L'2'	,0x2013	,0x2193	,0x0000	), // DOWNWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'3'	,0x2013	,0x2198	,0x0000	), // SOUTH EAST ARROW
/*LONG_BAR           */	DEADTRANS(	L'4'	,0x2013	,0x2190	,0x0000	), // LEFTWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'5'	,0x2013	,0x2194	,0x0000	), // LEFT RIGHT ARROW
/*LONG_BAR           */	DEADTRANS(	L'6'	,0x2013	,0x2192	,0x0000	), // RIGHTWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'7'	,0x2013	,0x2196	,0x0000	), // NORTH WEST ARROW
/*LONG_BAR           */	DEADTRANS(	L'8'	,0x2013	,0x2191	,0x0000	), // UPWARDS ARROW
/*LONG_BAR           */	DEADTRANS(	L'9'	,0x2013	,0x2197	,0x0000	), // NORTH EAST ARROW
/*M_BOLD             */	DEADTRANS(	L'A'	,0x212C	,0xDC00	,0x0000	), // U+1D400; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL A
/*M_BOLD             */	DEADTRANS(	L'a'	,0x212C	,0xDC1A	,0x0000	), // U+1D41A; input D835 high surrogate first; MATHEMATICAL BOLD SMALL A
/*M_BOLD             */	DEADTRANS(	L'B'	,0x212C	,0xDC01	,0x0000	), // U+1D401; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL B
/*M_BOLD             */	DEADTRANS(	L'b'	,0x212C	,0xDC1B	,0x0000	), // U+1D41B; input D835 high surrogate first; MATHEMATICAL BOLD SMALL B
/*M_BOLD             */	DEADTRANS(	L'C'	,0x212C	,0xDC02	,0x0000	), // U+1D402; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL C
/*M_BOLD             */	DEADTRANS(	L'c'	,0x212C	,0xDC1C	,0x0000	), // U+1D41C; input D835 high surrogate first; MATHEMATICAL BOLD SMALL C
/*M_BOLD             */	DEADTRANS(	L'D'	,0x212C	,0xDC03	,0x0000	), // U+1D403; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL D
/*M_BOLD             */	DEADTRANS(	L'd'	,0x212C	,0xDC1D	,0x0000	), // U+1D41D; input D835 high surrogate first; MATHEMATICAL BOLD SMALL D
/*M_BOLD             */	DEADTRANS(	L'E'	,0x212C	,0xDC04	,0x0000	), // U+1D404; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL E
/*M_BOLD             */	DEADTRANS(	L'e'	,0x212C	,0xDC1E	,0x0000	), // U+1D41E; input D835 high surrogate first; MATHEMATICAL BOLD SMALL E
/*M_BOLD             */	DEADTRANS(	L'F'	,0x212C	,0xDC05	,0x0000	), // U+1D405; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL F
/*M_BOLD             */	DEADTRANS(	L'f'	,0x212C	,0xDC1F	,0x0000	), // U+1D41F; input D835 high surrogate first; MATHEMATICAL BOLD SMALL F
/*M_BOLD             */	DEADTRANS(	L'G'	,0x212C	,0xDC06	,0x0000	), // U+1D406; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL G
/*M_BOLD             */	DEADTRANS(	L'g'	,0x212C	,0xDC20	,0x0000	), // U+1D420; input D835 high surrogate first; MATHEMATICAL BOLD SMALL G
/*M_BOLD             */	DEADTRANS(	L'H'	,0x212C	,0xDC07	,0x0000	), // U+1D407; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL H
/*M_BOLD             */	DEADTRANS(	L'h'	,0x212C	,0xDC21	,0x0000	), // U+1D421; input D835 high surrogate first; MATHEMATICAL BOLD SMALL H
/*M_BOLD             */	DEADTRANS(	L'I'	,0x212C	,0xDC08	,0x0000	), // U+1D408; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL I
/*M_BOLD             */	DEADTRANS(	L'i'	,0x212C	,0xDC22	,0x0000	), // U+1D422; input D835 high surrogate first; MATHEMATICAL BOLD SMALL I
/*M_BOLD             */	DEADTRANS(	L'J'	,0x212C	,0xDC09	,0x0000	), // U+1D409; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL J
/*M_BOLD             */	DEADTRANS(	L'j'	,0x212C	,0xDC23	,0x0000	), // U+1D423; input D835 high surrogate first; MATHEMATICAL BOLD SMALL J
/*M_BOLD             */	DEADTRANS(	L'K'	,0x212C	,0xDC0A	,0x0000	), // U+1D40A; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL K
/*M_BOLD             */	DEADTRANS(	L'k'	,0x212C	,0xDC24	,0x0000	), // U+1D424; input D835 high surrogate first; MATHEMATICAL BOLD SMALL K
/*M_BOLD             */	DEADTRANS(	L'L'	,0x212C	,0xDC0B	,0x0000	), // U+1D40B; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL L
/*M_BOLD             */	DEADTRANS(	L'l'	,0x212C	,0xDC25	,0x0000	), // U+1D425; input D835 high surrogate first; MATHEMATICAL BOLD SMALL L
/*M_BOLD             */	DEADTRANS(	L'M'	,0x212C	,0xDC0C	,0x0000	), // U+1D40C; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL M
/*M_BOLD             */	DEADTRANS(	L'm'	,0x212C	,0xDC26	,0x0000	), // U+1D426; input D835 high surrogate first; MATHEMATICAL BOLD SMALL M
/*M_BOLD             */	DEADTRANS(	L'N'	,0x212C	,0xDC0D	,0x0000	), // U+1D40D; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL N
/*M_BOLD             */	DEADTRANS(	L'n'	,0x212C	,0xDC27	,0x0000	), // U+1D427; input D835 high surrogate first; MATHEMATICAL BOLD SMALL N
/*M_BOLD             */	DEADTRANS(	L'O'	,0x212C	,0xDC0E	,0x0000	), // U+1D40E; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL O
/*M_BOLD             */	DEADTRANS(	L'o'	,0x212C	,0xDC28	,0x0000	), // U+1D428; input D835 high surrogate first; MATHEMATICAL BOLD SMALL O
/*M_BOLD             */	DEADTRANS(	L'P'	,0x212C	,0xDC0F	,0x0000	), // U+1D40F; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL P
/*M_BOLD             */	DEADTRANS(	L'p'	,0x212C	,0xDC29	,0x0000	), // U+1D429; input D835 high surrogate first; MATHEMATICAL BOLD SMALL P
/*M_BOLD             */	DEADTRANS(	L'Q'	,0x212C	,0xDC10	,0x0000	), // U+1D410; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Q
/*M_BOLD             */	DEADTRANS(	L'q'	,0x212C	,0xDC2A	,0x0000	), // U+1D42A; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Q
/*M_BOLD             */	DEADTRANS(	L'R'	,0x212C	,0xDC11	,0x0000	), // U+1D411; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL R
/*M_BOLD             */	DEADTRANS(	L'r'	,0x212C	,0xDC2B	,0x0000	), // U+1D42B; input D835 high surrogate first; MATHEMATICAL BOLD SMALL R
/*M_BOLD             */	DEADTRANS(	L'S'	,0x212C	,0xDC12	,0x0000	), // U+1D412; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL S
/*M_BOLD             */	DEADTRANS(	L's'	,0x212C	,0xDC2C	,0x0000	), // U+1D42C; input D835 high surrogate first; MATHEMATICAL BOLD SMALL S
/*M_BOLD             */	DEADTRANS(	L'T'	,0x212C	,0xDC13	,0x0000	), // U+1D413; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL T
/*M_BOLD             */	DEADTRANS(	L't'	,0x212C	,0xDC2D	,0x0000	), // U+1D42D; input D835 high surrogate first; MATHEMATICAL BOLD SMALL T
/*M_BOLD             */	DEADTRANS(	L'U'	,0x212C	,0xDC14	,0x0000	), // U+1D414; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL U
/*M_BOLD             */	DEADTRANS(	L'u'	,0x212C	,0xDC2E	,0x0000	), // U+1D42E; input D835 high surrogate first; MATHEMATICAL BOLD SMALL U
/*M_BOLD             */	DEADTRANS(	L'V'	,0x212C	,0xDC15	,0x0000	), // U+1D415; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL V
/*M_BOLD             */	DEADTRANS(	L'v'	,0x212C	,0xDC2F	,0x0000	), // U+1D42F; input D835 high surrogate first; MATHEMATICAL BOLD SMALL V
/*M_BOLD             */	DEADTRANS(	L'W'	,0x212C	,0xDC16	,0x0000	), // U+1D416; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL W
/*M_BOLD             */	DEADTRANS(	L'w'	,0x212C	,0xDC30	,0x0000	), // U+1D430; input D835 high surrogate first; MATHEMATICAL BOLD SMALL W
/*M_BOLD             */	DEADTRANS(	L'X'	,0x212C	,0xDC17	,0x0000	), // U+1D417; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL X
/*M_BOLD             */	DEADTRANS(	L'x'	,0x212C	,0xDC31	,0x0000	), // U+1D431; input D835 high surrogate first; MATHEMATICAL BOLD SMALL X
/*M_BOLD             */	DEADTRANS(	L'Y'	,0x212C	,0xDC18	,0x0000	), // U+1D418; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Y
/*M_BOLD             */	DEADTRANS(	L'y'	,0x212C	,0xDC32	,0x0000	), // U+1D432; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Y
/*M_BOLD             */	DEADTRANS(	L'Z'	,0x212C	,0xDC19	,0x0000	), // U+1D419; input D835 high surrogate first; MATHEMATICAL BOLD CAPITAL Z
/*M_BOLD             */	DEADTRANS(	L'z'	,0x212C	,0xDC33	,0x0000	), // U+1D433; input D835 high surrogate first; MATHEMATICAL BOLD SMALL Z
/*M_BOLD             */	DEADTRANS(	0x0024	,0x212C	,0x211B	,0x0001	), // SCRIPT CAPITAL R
/*M_BOLD             */	DEADTRANS(	0x0025	,0x212C	,0x211C	,0x0001	), // BLACK-LETTER CAPITAL R
/*M_BOLD             */	DEADTRANS(	0x0026	,0x212C	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*M_BOLD             */	DEADTRANS(	0x002F	,0x212C	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'A'	,0x2110	,0xDC68	,0x0000	), // U+1D468; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL A
/*M_BOLD_ITALIC      */	DEADTRANS(	L'a'	,0x2110	,0xDC82	,0x0000	), // U+1D482; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL A
/*M_BOLD_ITALIC      */	DEADTRANS(	L'B'	,0x2110	,0xDC69	,0x0000	), // U+1D469; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL B
/*M_BOLD_ITALIC      */	DEADTRANS(	L'b'	,0x2110	,0xDC83	,0x0000	), // U+1D483; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL B
/*M_BOLD_ITALIC      */	DEADTRANS(	L'C'	,0x2110	,0xDC6A	,0x0000	), // U+1D46A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL C
/*M_BOLD_ITALIC      */	DEADTRANS(	L'c'	,0x2110	,0xDC84	,0x0000	), // U+1D484; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL C
/*M_BOLD_ITALIC      */	DEADTRANS(	L'D'	,0x2110	,0xDC6B	,0x0000	), // U+1D46B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL D
/*M_BOLD_ITALIC      */	DEADTRANS(	L'd'	,0x2110	,0xDC85	,0x0000	), // U+1D485; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL D
/*M_BOLD_ITALIC      */	DEADTRANS(	L'E'	,0x2110	,0xDC6C	,0x0000	), // U+1D46C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL E
/*M_BOLD_ITALIC      */	DEADTRANS(	L'e'	,0x2110	,0xDC86	,0x0000	), // U+1D486; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL E
/*M_BOLD_ITALIC      */	DEADTRANS(	L'F'	,0x2110	,0xDC6D	,0x0000	), // U+1D46D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL F
/*M_BOLD_ITALIC      */	DEADTRANS(	L'f'	,0x2110	,0xDC87	,0x0000	), // U+1D487; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL F
/*M_BOLD_ITALIC      */	DEADTRANS(	L'G'	,0x2110	,0xDC6E	,0x0000	), // U+1D46E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL G
/*M_BOLD_ITALIC      */	DEADTRANS(	L'g'	,0x2110	,0xDC88	,0x0000	), // U+1D488; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL G
/*M_BOLD_ITALIC      */	DEADTRANS(	L'H'	,0x2110	,0xDC6F	,0x0000	), // U+1D46F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL H
/*M_BOLD_ITALIC      */	DEADTRANS(	L'h'	,0x2110	,0xDC89	,0x0000	), // U+1D489; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL H
/*M_BOLD_ITALIC      */	DEADTRANS(	L'I'	,0x2110	,0xDC70	,0x0000	), // U+1D470; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'i'	,0x2110	,0xDC8A	,0x0000	), // U+1D48A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL I
/*M_BOLD_ITALIC      */	DEADTRANS(	L'J'	,0x2110	,0xDC71	,0x0000	), // U+1D471; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL J
/*M_BOLD_ITALIC      */	DEADTRANS(	L'j'	,0x2110	,0xDC8B	,0x0000	), // U+1D48B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL J
/*M_BOLD_ITALIC      */	DEADTRANS(	L'K'	,0x2110	,0xDC72	,0x0000	), // U+1D472; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL K
/*M_BOLD_ITALIC      */	DEADTRANS(	L'k'	,0x2110	,0xDC8C	,0x0000	), // U+1D48C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL K
/*M_BOLD_ITALIC      */	DEADTRANS(	L'L'	,0x2110	,0xDC73	,0x0000	), // U+1D473; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL L
/*M_BOLD_ITALIC      */	DEADTRANS(	L'l'	,0x2110	,0xDC8D	,0x0000	), // U+1D48D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL L
/*M_BOLD_ITALIC      */	DEADTRANS(	L'M'	,0x2110	,0xDC74	,0x0000	), // U+1D474; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL M
/*M_BOLD_ITALIC      */	DEADTRANS(	L'm'	,0x2110	,0xDC8E	,0x0000	), // U+1D48E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL M
/*M_BOLD_ITALIC      */	DEADTRANS(	L'N'	,0x2110	,0xDC75	,0x0000	), // U+1D475; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL N
/*M_BOLD_ITALIC      */	DEADTRANS(	L'n'	,0x2110	,0xDC8F	,0x0000	), // U+1D48F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL N
/*M_BOLD_ITALIC      */	DEADTRANS(	L'O'	,0x2110	,0xDC76	,0x0000	), // U+1D476; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL O
/*M_BOLD_ITALIC      */	DEADTRANS(	L'o'	,0x2110	,0xDC90	,0x0000	), // U+1D490; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL O
/*M_BOLD_ITALIC      */	DEADTRANS(	L'P'	,0x2110	,0xDC77	,0x0000	), // U+1D477; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL P
/*M_BOLD_ITALIC      */	DEADTRANS(	L'p'	,0x2110	,0xDC91	,0x0000	), // U+1D491; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL P
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Q'	,0x2110	,0xDC78	,0x0000	), // U+1D478; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Q
/*M_BOLD_ITALIC      */	DEADTRANS(	L'q'	,0x2110	,0xDC92	,0x0000	), // U+1D492; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Q
/*M_BOLD_ITALIC      */	DEADTRANS(	L'R'	,0x2110	,0xDC79	,0x0000	), // U+1D479; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL R
/*M_BOLD_ITALIC      */	DEADTRANS(	L'r'	,0x2110	,0xDC93	,0x0000	), // U+1D493; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL R
/*M_BOLD_ITALIC      */	DEADTRANS(	L'S'	,0x2110	,0xDC7A	,0x0000	), // U+1D47A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL S
/*M_BOLD_ITALIC      */	DEADTRANS(	L's'	,0x2110	,0xDC94	,0x0000	), // U+1D494; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL S
/*M_BOLD_ITALIC      */	DEADTRANS(	L'T'	,0x2110	,0xDC7B	,0x0000	), // U+1D47B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL T
/*M_BOLD_ITALIC      */	DEADTRANS(	L't'	,0x2110	,0xDC95	,0x0000	), // U+1D495; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL T
/*M_BOLD_ITALIC      */	DEADTRANS(	L'U'	,0x2110	,0xDC7C	,0x0000	), // U+1D47C; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL U
/*M_BOLD_ITALIC      */	DEADTRANS(	L'u'	,0x2110	,0xDC96	,0x0000	), // U+1D496; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL U
/*M_BOLD_ITALIC      */	DEADTRANS(	L'V'	,0x2110	,0xDC7D	,0x0000	), // U+1D47D; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL V
/*M_BOLD_ITALIC      */	DEADTRANS(	L'v'	,0x2110	,0xDC97	,0x0000	), // U+1D497; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL V
/*M_BOLD_ITALIC      */	DEADTRANS(	L'W'	,0x2110	,0xDC7E	,0x0000	), // U+1D47E; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL W
/*M_BOLD_ITALIC      */	DEADTRANS(	L'w'	,0x2110	,0xDC98	,0x0000	), // U+1D498; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL W
/*M_BOLD_ITALIC      */	DEADTRANS(	L'X'	,0x2110	,0xDC7F	,0x0000	), // U+1D47F; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL X
/*M_BOLD_ITALIC      */	DEADTRANS(	L'x'	,0x2110	,0xDC99	,0x0000	), // U+1D499; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL X
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Y'	,0x2110	,0xDC80	,0x0000	), // U+1D480; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Y
/*M_BOLD_ITALIC      */	DEADTRANS(	L'y'	,0x2110	,0xDC9A	,0x0000	), // U+1D49A; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Y
/*M_BOLD_ITALIC      */	DEADTRANS(	L'Z'	,0x2110	,0xDC81	,0x0000	), // U+1D481; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC CAPITAL Z
/*M_BOLD_ITALIC      */	DEADTRANS(	L'z'	,0x2110	,0xDC9B	,0x0000	), // U+1D49B; input D835 high surrogate first; MATHEMATICAL BOLD ITALIC SMALL Z
/*M_BOLD_ITALIC      */	DEADTRANS(	0x0024	,0x2110	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'A'	,0x211C	,0xDD6C	,0x0000	), // U+1D56C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'a'	,0x211C	,0xDD86	,0x0000	), // U+1D586; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'B'	,0x211C	,0xDD6D	,0x0000	), // U+1D56D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'b'	,0x211C	,0xDD87	,0x0000	), // U+1D587; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'C'	,0x211C	,0xDD6E	,0x0000	), // U+1D56E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'c'	,0x211C	,0xDD88	,0x0000	), // U+1D588; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'D'	,0x211C	,0xDD6F	,0x0000	), // U+1D56F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'd'	,0x211C	,0xDD89	,0x0000	), // U+1D589; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'E'	,0x211C	,0xDD70	,0x0000	), // U+1D570; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'e'	,0x211C	,0xDD8A	,0x0000	), // U+1D58A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'F'	,0x211C	,0xDD71	,0x0000	), // U+1D571; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'f'	,0x211C	,0xDD8B	,0x0000	), // U+1D58B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'G'	,0x211C	,0xDD72	,0x0000	), // U+1D572; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'g'	,0x211C	,0xDD8C	,0x0000	), // U+1D58C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'H'	,0x211C	,0xDD73	,0x0000	), // U+1D573; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'h'	,0x211C	,0xDD8D	,0x0000	), // U+1D58D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'I'	,0x211C	,0xDD74	,0x0000	), // U+1D574; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'i'	,0x211C	,0xDD8E	,0x0000	), // U+1D58E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'J'	,0x211C	,0xDD75	,0x0000	), // U+1D575; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'j'	,0x211C	,0xDD8F	,0x0000	), // U+1D58F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'K'	,0x211C	,0xDD76	,0x0000	), // U+1D576; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'k'	,0x211C	,0xDD90	,0x0000	), // U+1D590; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'L'	,0x211C	,0xDD77	,0x0000	), // U+1D577; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'l'	,0x211C	,0xDD91	,0x0000	), // U+1D591; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'M'	,0x211C	,0xDD78	,0x0000	), // U+1D578; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'm'	,0x211C	,0xDD92	,0x0000	), // U+1D592; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'N'	,0x211C	,0xDD79	,0x0000	), // U+1D579; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'n'	,0x211C	,0xDD93	,0x0000	), // U+1D593; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'O'	,0x211C	,0xDD7A	,0x0000	), // U+1D57A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'o'	,0x211C	,0xDD94	,0x0000	), // U+1D594; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'P'	,0x211C	,0xDD7B	,0x0000	), // U+1D57B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'p'	,0x211C	,0xDD95	,0x0000	), // U+1D595; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Q'	,0x211C	,0xDD7C	,0x0000	), // U+1D57C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'q'	,0x211C	,0xDD96	,0x0000	), // U+1D596; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'R'	,0x211C	,0xDD7D	,0x0000	), // U+1D57D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'r'	,0x211C	,0xDD97	,0x0000	), // U+1D597; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'S'	,0x211C	,0xDD7E	,0x0000	), // U+1D57E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L's'	,0x211C	,0xDD98	,0x0000	), // U+1D598; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'T'	,0x211C	,0xDD7F	,0x0000	), // U+1D57F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L't'	,0x211C	,0xDD99	,0x0000	), // U+1D599; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'U'	,0x211C	,0xDD80	,0x0000	), // U+1D580; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'u'	,0x211C	,0xDD9A	,0x0000	), // U+1D59A; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'V'	,0x211C	,0xDD81	,0x0000	), // U+1D581; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'v'	,0x211C	,0xDD9B	,0x0000	), // U+1D59B; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'W'	,0x211C	,0xDD82	,0x0000	), // U+1D582; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'w'	,0x211C	,0xDD9C	,0x0000	), // U+1D59C; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'X'	,0x211C	,0xDD83	,0x0000	), // U+1D583; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'x'	,0x211C	,0xDD9D	,0x0000	), // U+1D59D; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Y'	,0x211C	,0xDD84	,0x0000	), // U+1D584; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'y'	,0x211C	,0xDD9E	,0x0000	), // U+1D59E; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Z'	,0x211C	,0xDD85	,0x0000	), // U+1D585; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR CAPITAL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'z'	,0x211C	,0xDD9F	,0x0000	), // U+1D59F; input D835 high surrogate first; MATHEMATICAL BOLD FRAKTUR SMALL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'A'	,0x2131	,0xDCD0	,0x0000	), // U+1D4D0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'a'	,0x2131	,0xDCEA	,0x0000	), // U+1D4EA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL A
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'B'	,0x2131	,0xDCD1	,0x0000	), // U+1D4D1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'b'	,0x2131	,0xDCEB	,0x0000	), // U+1D4EB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL B
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'C'	,0x2131	,0xDCD2	,0x0000	), // U+1D4D2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'c'	,0x2131	,0xDCEC	,0x0000	), // U+1D4EC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL C
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'D'	,0x2131	,0xDCD3	,0x0000	), // U+1D4D3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'd'	,0x2131	,0xDCED	,0x0000	), // U+1D4ED; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL D
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'E'	,0x2131	,0xDCD4	,0x0000	), // U+1D4D4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'e'	,0x2131	,0xDCEE	,0x0000	), // U+1D4EE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL E
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'F'	,0x2131	,0xDCD5	,0x0000	), // U+1D4D5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'f'	,0x2131	,0xDCEF	,0x0000	), // U+1D4EF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL F
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'G'	,0x2131	,0xDCD6	,0x0000	), // U+1D4D6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'g'	,0x2131	,0xDCF0	,0x0000	), // U+1D4F0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL G
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'H'	,0x2131	,0xDCD7	,0x0000	), // U+1D4D7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'h'	,0x2131	,0xDCF1	,0x0000	), // U+1D4F1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL H
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'I'	,0x2131	,0xDCD8	,0x0000	), // U+1D4D8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'i'	,0x2131	,0xDCF2	,0x0000	), // U+1D4F2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL I
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'J'	,0x2131	,0xDCD9	,0x0000	), // U+1D4D9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'j'	,0x2131	,0xDCF3	,0x0000	), // U+1D4F3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL J
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'K'	,0x2131	,0xDCDA	,0x0000	), // U+1D4DA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'k'	,0x2131	,0xDCF4	,0x0000	), // U+1D4F4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL K
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'L'	,0x2131	,0xDCDB	,0x0000	), // U+1D4DB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'l'	,0x2131	,0xDCF5	,0x0000	), // U+1D4F5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL L
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'M'	,0x2131	,0xDCDC	,0x0000	), // U+1D4DC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'm'	,0x2131	,0xDCF6	,0x0000	), // U+1D4F6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL M
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'N'	,0x2131	,0xDCDD	,0x0000	), // U+1D4DD; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'n'	,0x2131	,0xDCF7	,0x0000	), // U+1D4F7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL N
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'O'	,0x2131	,0xDCDE	,0x0000	), // U+1D4DE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'o'	,0x2131	,0xDCF8	,0x0000	), // U+1D4F8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL O
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'P'	,0x2131	,0xDCDF	,0x0000	), // U+1D4DF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'p'	,0x2131	,0xDCF9	,0x0000	), // U+1D4F9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL P
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Q'	,0x2131	,0xDCE0	,0x0000	), // U+1D4E0; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'q'	,0x2131	,0xDCFA	,0x0000	), // U+1D4FA; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Q
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'R'	,0x2131	,0xDCE1	,0x0000	), // U+1D4E1; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'r'	,0x2131	,0xDCFB	,0x0000	), // U+1D4FB; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL R
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'S'	,0x2131	,0xDCE2	,0x0000	), // U+1D4E2; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L's'	,0x2131	,0xDCFC	,0x0000	), // U+1D4FC; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL S
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'T'	,0x2131	,0xDCE3	,0x0000	), // U+1D4E3; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L't'	,0x2131	,0xDCFD	,0x0000	), // U+1D4FD; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL T
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'U'	,0x2131	,0xDCE4	,0x0000	), // U+1D4E4; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'u'	,0x2131	,0xDCFE	,0x0000	), // U+1D4FE; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL U
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'V'	,0x2131	,0xDCE5	,0x0000	), // U+1D4E5; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'v'	,0x2131	,0xDCFF	,0x0000	), // U+1D4FF; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL V
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'W'	,0x2131	,0xDCE6	,0x0000	), // U+1D4E6; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'w'	,0x2131	,0xDD00	,0x0000	), // U+1D500; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL W
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'X'	,0x2131	,0xDCE7	,0x0000	), // U+1D4E7; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'x'	,0x2131	,0xDD01	,0x0000	), // U+1D501; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL X
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Y'	,0x2131	,0xDCE8	,0x0000	), // U+1D4E8; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'y'	,0x2131	,0xDD02	,0x0000	), // U+1D502; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Y
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'Z'	,0x2131	,0xDCE9	,0x0000	), // U+1D4E9; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT CAPITAL Z
/*M_BOLD_SCRIPT      */	DEADTRANS(	L'z'	,0x2131	,0xDD03	,0x0000	), // U+1D503; input D835 high surrogate first; MATHEMATICAL BOLD SCRIPT SMALL Z
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'A'	,0x2115	,0xDD38	,0x0000	), // U+1D538; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL A
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'a'	,0x2115	,0xDD52	,0x0000	), // U+1D552; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL A
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'B'	,0x2115	,0xDD39	,0x0000	), // U+1D539; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL B
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'b'	,0x2115	,0xDD53	,0x0000	), // U+1D553; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL B
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'C'	,0x2115	,0x2102	,0x0000	), // DOUBLE-STRUCK CAPITAL C
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'c'	,0x2115	,0xDD54	,0x0000	), // U+1D554; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL C
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'D'	,0x2115	,0xDD3B	,0x0000	), // U+1D53B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL D
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'd'	,0x2115	,0xDD55	,0x0000	), // U+1D555; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL D
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'E'	,0x2115	,0xDD3C	,0x0000	), // U+1D53C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL E
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'e'	,0x2115	,0xDD56	,0x0000	), // U+1D556; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL E
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'F'	,0x2115	,0xDD3D	,0x0000	), // U+1D53D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL F
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'f'	,0x2115	,0xDD57	,0x0000	), // U+1D557; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL F
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'G'	,0x2115	,0xDD3E	,0x0000	), // U+1D53E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL G
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'g'	,0x2115	,0xDD58	,0x0000	), // U+1D558; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL G
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'H'	,0x2115	,0x210D	,0x0000	), // DOUBLE-STRUCK CAPITAL H
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'h'	,0x2115	,0xDD59	,0x0000	), // U+1D559; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL H
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'I'	,0x2115	,0xDD40	,0x0000	), // U+1D540; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL I
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'i'	,0x2115	,0xDD5A	,0x0000	), // U+1D55A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL I
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'J'	,0x2115	,0xDD41	,0x0000	), // U+1D541; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL J
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'j'	,0x2115	,0xDD5B	,0x0000	), // U+1D55B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL J
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'K'	,0x2115	,0xDD42	,0x0000	), // U+1D542; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL K
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'k'	,0x2115	,0xDD5C	,0x0000	), // U+1D55C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL K
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'L'	,0x2115	,0xDD43	,0x0000	), // U+1D543; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL L
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'l'	,0x2115	,0xDD5D	,0x0000	), // U+1D55D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL L
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'M'	,0x2115	,0xDD44	,0x0000	), // U+1D544; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL M
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'm'	,0x2115	,0xDD5E	,0x0000	), // U+1D55E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL M
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'N'	,0x2115	,0x2115	,0x0000	), // DOUBLE-STRUCK CAPITAL N
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'n'	,0x2115	,0xDD5F	,0x0000	), // U+1D55F; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL N
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'O'	,0x2115	,0xDD46	,0x0000	), // U+1D546; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL O
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'o'	,0x2115	,0xDD60	,0x0000	), // U+1D560; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL O
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'P'	,0x2115	,0x2119	,0x0000	), // DOUBLE-STRUCK CAPITAL P
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'p'	,0x2115	,0xDD61	,0x0000	), // U+1D561; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL P
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Q'	,0x2115	,0x211A	,0x0000	), // DOUBLE-STRUCK CAPITAL Q
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'q'	,0x2115	,0xDD62	,0x0000	), // U+1D562; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Q
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'R'	,0x2115	,0x211D	,0x0000	), // DOUBLE-STRUCK CAPITAL R
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'r'	,0x2115	,0xDD63	,0x0000	), // U+1D563; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL R
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'S'	,0x2115	,0xDD4A	,0x0000	), // U+1D54A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL S
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L's'	,0x2115	,0xDD64	,0x0000	), // U+1D564; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL S
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'T'	,0x2115	,0xDD4B	,0x0000	), // U+1D54B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL T
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L't'	,0x2115	,0xDD65	,0x0000	), // U+1D565; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL T
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'U'	,0x2115	,0xDD4C	,0x0000	), // U+1D54C; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL U
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'u'	,0x2115	,0xDD66	,0x0000	), // U+1D566; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL U
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'V'	,0x2115	,0xDD4D	,0x0000	), // U+1D54D; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL V
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'v'	,0x2115	,0xDD67	,0x0000	), // U+1D567; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL V
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'W'	,0x2115	,0xDD4E	,0x0000	), // U+1D54E; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL W
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'w'	,0x2115	,0xDD68	,0x0000	), // U+1D568; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL W
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'X'	,0x2115	,0xDD4F	,0x0000	), // U+1D54F; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL X
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'x'	,0x2115	,0xDD69	,0x0000	), // U+1D569; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL X
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Y'	,0x2115	,0xDD50	,0x0000	), // U+1D550; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK CAPITAL Y
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'y'	,0x2115	,0xDD6A	,0x0000	), // U+1D56A; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Y
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'Z'	,0x2115	,0x2124	,0x0000	), // DOUBLE-STRUCK CAPITAL Z
/*M_DOUBLE-STRUCK    */	DEADTRANS(	L'z'	,0x2115	,0xDD6B	,0x0000	), // U+1D56B; input D835 high surrogate first; MATHEMATICAL DOUBLE-STRUCK SMALL Z
/*M_FRAKTUR          */	DEADTRANS(	L'A'	,0x212D	,0xDD04	,0x0000	), // U+1D504; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL A
/*M_FRAKTUR          */	DEADTRANS(	L'a'	,0x212D	,0xDD1E	,0x0000	), // U+1D51E; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL A
/*M_FRAKTUR          */	DEADTRANS(	L'B'	,0x212D	,0xDD05	,0x0000	), // U+1D505; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL B
/*M_FRAKTUR          */	DEADTRANS(	L'b'	,0x212D	,0xDD1F	,0x0000	), // U+1D51F; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL B
/*M_FRAKTUR          */	DEADTRANS(	L'C'	,0x212D	,0x212D	,0x0000	), // BLACK-LETTER CAPITAL C
/*M_FRAKTUR          */	DEADTRANS(	L'c'	,0x212D	,0xDD20	,0x0000	), // U+1D520; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL C
/*M_FRAKTUR          */	DEADTRANS(	L'D'	,0x212D	,0xDD07	,0x0000	), // U+1D507; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL D
/*M_FRAKTUR          */	DEADTRANS(	L'd'	,0x212D	,0xDD21	,0x0000	), // U+1D521; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL D
/*M_FRAKTUR          */	DEADTRANS(	L'E'	,0x212D	,0xDD08	,0x0000	), // U+1D508; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL E
/*M_FRAKTUR          */	DEADTRANS(	L'e'	,0x212D	,0xDD22	,0x0000	), // U+1D522; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL E
/*M_FRAKTUR          */	DEADTRANS(	L'F'	,0x212D	,0xDD09	,0x0000	), // U+1D509; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL F
/*M_FRAKTUR          */	DEADTRANS(	L'f'	,0x212D	,0xDD23	,0x0000	), // U+1D523; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL F
/*M_FRAKTUR          */	DEADTRANS(	L'G'	,0x212D	,0xDD0A	,0x0000	), // U+1D50A; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL G
/*M_FRAKTUR          */	DEADTRANS(	L'g'	,0x212D	,0xDD24	,0x0000	), // U+1D524; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL G
/*M_FRAKTUR          */	DEADTRANS(	L'H'	,0x212D	,0x210C	,0x0000	), // BLACK-LETTER CAPITAL H
/*M_FRAKTUR          */	DEADTRANS(	L'h'	,0x212D	,0xDD25	,0x0000	), // U+1D525; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL H
/*M_FRAKTUR          */	DEADTRANS(	L'I'	,0x212D	,0x2111	,0x0000	), // BLACK-LETTER CAPITAL I
/*M_FRAKTUR          */	DEADTRANS(	L'i'	,0x212D	,0xDD26	,0x0000	), // U+1D526; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL I
/*M_FRAKTUR          */	DEADTRANS(	L'J'	,0x212D	,0xDD0D	,0x0000	), // U+1D50D; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL J
/*M_FRAKTUR          */	DEADTRANS(	L'j'	,0x212D	,0xDD27	,0x0000	), // U+1D527; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL J
/*M_FRAKTUR          */	DEADTRANS(	L'K'	,0x212D	,0xDD0E	,0x0000	), // U+1D50E; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL K
/*M_FRAKTUR          */	DEADTRANS(	L'k'	,0x212D	,0xDD28	,0x0000	), // U+1D528; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL K
/*M_FRAKTUR          */	DEADTRANS(	L'L'	,0x212D	,0xDD0F	,0x0000	), // U+1D50F; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL L
/*M_FRAKTUR          */	DEADTRANS(	L'l'	,0x212D	,0xDD29	,0x0000	), // U+1D529; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL L
/*M_FRAKTUR          */	DEADTRANS(	L'M'	,0x212D	,0xDD10	,0x0000	), // U+1D510; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL M
/*M_FRAKTUR          */	DEADTRANS(	L'm'	,0x212D	,0xDD2A	,0x0000	), // U+1D52A; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL M
/*M_FRAKTUR          */	DEADTRANS(	L'N'	,0x212D	,0xDD11	,0x0000	), // U+1D511; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL N
/*M_FRAKTUR          */	DEADTRANS(	L'n'	,0x212D	,0xDD2B	,0x0000	), // U+1D52B; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL N
/*M_FRAKTUR          */	DEADTRANS(	L'O'	,0x212D	,0xDD12	,0x0000	), // U+1D512; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL O
/*M_FRAKTUR          */	DEADTRANS(	L'o'	,0x212D	,0xDD2C	,0x0000	), // U+1D52C; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL O
/*M_FRAKTUR          */	DEADTRANS(	L'P'	,0x212D	,0xDD13	,0x0000	), // U+1D513; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL P
/*M_FRAKTUR          */	DEADTRANS(	L'p'	,0x212D	,0xDD2D	,0x0000	), // U+1D52D; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL P
/*M_FRAKTUR          */	DEADTRANS(	L'Q'	,0x212D	,0xDD14	,0x0000	), // U+1D514; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL Q
/*M_FRAKTUR          */	DEADTRANS(	L'q'	,0x212D	,0xDD2E	,0x0000	), // U+1D52E; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Q
/*M_FRAKTUR          */	DEADTRANS(	L'R'	,0x212D	,0x211C	,0x0000	), // BLACK-LETTER CAPITAL R
/*M_FRAKTUR          */	DEADTRANS(	L'r'	,0x212D	,0xDD2F	,0x0000	), // U+1D52F; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL R
/*M_FRAKTUR          */	DEADTRANS(	L'S'	,0x212D	,0xDD16	,0x0000	), // U+1D516; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL S
/*M_FRAKTUR          */	DEADTRANS(	L's'	,0x212D	,0xDD30	,0x0000	), // U+1D530; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL S
/*M_FRAKTUR          */	DEADTRANS(	L'T'	,0x212D	,0xDD17	,0x0000	), // U+1D517; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL T
/*M_FRAKTUR          */	DEADTRANS(	L't'	,0x212D	,0xDD31	,0x0000	), // U+1D531; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL T
/*M_FRAKTUR          */	DEADTRANS(	L'U'	,0x212D	,0xDD18	,0x0000	), // U+1D518; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL U
/*M_FRAKTUR          */	DEADTRANS(	L'u'	,0x212D	,0xDD32	,0x0000	), // U+1D532; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL U
/*M_FRAKTUR          */	DEADTRANS(	L'V'	,0x212D	,0xDD19	,0x0000	), // U+1D519; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL V
/*M_FRAKTUR          */	DEADTRANS(	L'v'	,0x212D	,0xDD33	,0x0000	), // U+1D533; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL V
/*M_FRAKTUR          */	DEADTRANS(	L'W'	,0x212D	,0xDD1A	,0x0000	), // U+1D51A; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL W
/*M_FRAKTUR          */	DEADTRANS(	L'w'	,0x212D	,0xDD34	,0x0000	), // U+1D534; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL W
/*M_FRAKTUR          */	DEADTRANS(	L'X'	,0x212D	,0xDD1B	,0x0000	), // U+1D51B; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL X
/*M_FRAKTUR          */	DEADTRANS(	L'x'	,0x212D	,0xDD35	,0x0000	), // U+1D535; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL X
/*M_FRAKTUR          */	DEADTRANS(	L'Y'	,0x212D	,0xDD1C	,0x0000	), // U+1D51C; input D835 high surrogate first; MATHEMATICAL FRAKTUR CAPITAL Y
/*M_FRAKTUR          */	DEADTRANS(	L'y'	,0x212D	,0xDD36	,0x0000	), // U+1D536; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Y
/*M_FRAKTUR          */	DEADTRANS(	L'Z'	,0x212D	,0x2128	,0x0000	), // BLACK-LETTER CAPITAL Z
/*M_FRAKTUR          */	DEADTRANS(	L'z'	,0x212D	,0xDD37	,0x0000	), // U+1D537; input D835 high surrogate first; MATHEMATICAL FRAKTUR SMALL Z
/*M_FRAKTUR          */	DEADTRANS(	0x002A	,0x212D	,0x211C	,0x0001	), // BLACK-LETTER CAPITAL R
/*M_ITALIC           */	DEADTRANS(	L'A'	,0x210E	,0xDC34	,0x0000	), // U+1D434; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL A
/*M_ITALIC           */	DEADTRANS(	L'a'	,0x210E	,0xDC4E	,0x0000	), // U+1D44E; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL A
/*M_ITALIC           */	DEADTRANS(	L'B'	,0x210E	,0xDC35	,0x0000	), // U+1D435; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL B
/*M_ITALIC           */	DEADTRANS(	L'b'	,0x210E	,0xDC4F	,0x0000	), // U+1D44F; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL B
/*M_ITALIC           */	DEADTRANS(	L'C'	,0x210E	,0xDC36	,0x0000	), // U+1D436; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL C
/*M_ITALIC           */	DEADTRANS(	L'c'	,0x210E	,0xDC50	,0x0000	), // U+1D450; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL C
/*M_ITALIC           */	DEADTRANS(	L'D'	,0x210E	,0xDC37	,0x0000	), // U+1D437; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL D
/*M_ITALIC           */	DEADTRANS(	L'd'	,0x210E	,0xDC51	,0x0000	), // U+1D451; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL D
/*M_ITALIC           */	DEADTRANS(	L'E'	,0x210E	,0xDC38	,0x0000	), // U+1D438; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL E
/*M_ITALIC           */	DEADTRANS(	L'e'	,0x210E	,0xDC52	,0x0000	), // U+1D452; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL E
/*M_ITALIC           */	DEADTRANS(	L'F'	,0x210E	,0xDC39	,0x0000	), // U+1D439; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL F
/*M_ITALIC           */	DEADTRANS(	L'f'	,0x210E	,0xDC53	,0x0000	), // U+1D453; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL F
/*M_ITALIC           */	DEADTRANS(	L'G'	,0x210E	,0xDC3A	,0x0000	), // U+1D43A; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL G
/*M_ITALIC           */	DEADTRANS(	L'g'	,0x210E	,0xDC54	,0x0000	), // U+1D454; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL G
/*M_ITALIC           */	DEADTRANS(	L'H'	,0x210E	,0xDC3B	,0x0000	), // U+1D43B; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL H
/*M_ITALIC           */	DEADTRANS(	L'h'	,0x210E	,0x210E	,0x0000	), // PLANCK CONSTANT
/*M_ITALIC           */	DEADTRANS(	L'I'	,0x210E	,0xDC3C	,0x0000	), // U+1D43C; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL I
/*M_ITALIC           */	DEADTRANS(	L'i'	,0x210E	,0xDC56	,0x0000	), // U+1D456; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL I
/*M_ITALIC           */	DEADTRANS(	L'J'	,0x210E	,0xDC3D	,0x0000	), // U+1D43D; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL J
/*M_ITALIC           */	DEADTRANS(	L'j'	,0x210E	,0xDC57	,0x0000	), // U+1D457; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL J
/*M_ITALIC           */	DEADTRANS(	L'K'	,0x210E	,0xDC3E	,0x0000	), // U+1D43E; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL K
/*M_ITALIC           */	DEADTRANS(	L'k'	,0x210E	,0xDC58	,0x0000	), // U+1D458; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL K
/*M_ITALIC           */	DEADTRANS(	L'L'	,0x210E	,0xDC3F	,0x0000	), // U+1D43F; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL L
/*M_ITALIC           */	DEADTRANS(	L'l'	,0x210E	,0xDC59	,0x0000	), // U+1D459; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL L
/*M_ITALIC           */	DEADTRANS(	L'M'	,0x210E	,0xDC40	,0x0000	), // U+1D440; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL M
/*M_ITALIC           */	DEADTRANS(	L'm'	,0x210E	,0xDC5A	,0x0000	), // U+1D45A; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL M
/*M_ITALIC           */	DEADTRANS(	L'N'	,0x210E	,0xDC41	,0x0000	), // U+1D441; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL N
/*M_ITALIC           */	DEADTRANS(	L'n'	,0x210E	,0xDC5B	,0x0000	), // U+1D45B; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL N
/*M_ITALIC           */	DEADTRANS(	L'O'	,0x210E	,0xDC42	,0x0000	), // U+1D442; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL O
/*M_ITALIC           */	DEADTRANS(	L'o'	,0x210E	,0xDC5C	,0x0000	), // U+1D45C; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL O
/*M_ITALIC           */	DEADTRANS(	L'P'	,0x210E	,0xDC43	,0x0000	), // U+1D443; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL P
/*M_ITALIC           */	DEADTRANS(	L'p'	,0x210E	,0xDC5D	,0x0000	), // U+1D45D; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL P
/*M_ITALIC           */	DEADTRANS(	L'Q'	,0x210E	,0xDC44	,0x0000	), // U+1D444; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Q
/*M_ITALIC           */	DEADTRANS(	L'q'	,0x210E	,0xDC5E	,0x0000	), // U+1D45E; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Q
/*M_ITALIC           */	DEADTRANS(	L'R'	,0x210E	,0xDC45	,0x0000	), // U+1D445; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL R
/*M_ITALIC           */	DEADTRANS(	L'r'	,0x210E	,0xDC5F	,0x0000	), // U+1D45F; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL R
/*M_ITALIC           */	DEADTRANS(	L'S'	,0x210E	,0xDC46	,0x0000	), // U+1D446; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL S
/*M_ITALIC           */	DEADTRANS(	L's'	,0x210E	,0xDC60	,0x0000	), // U+1D460; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL S
/*M_ITALIC           */	DEADTRANS(	L'T'	,0x210E	,0xDC47	,0x0000	), // U+1D447; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL T
/*M_ITALIC           */	DEADTRANS(	L't'	,0x210E	,0xDC61	,0x0000	), // U+1D461; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL T
/*M_ITALIC           */	DEADTRANS(	L'U'	,0x210E	,0xDC48	,0x0000	), // U+1D448; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL U
/*M_ITALIC           */	DEADTRANS(	L'u'	,0x210E	,0xDC62	,0x0000	), // U+1D462; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL U
/*M_ITALIC           */	DEADTRANS(	L'V'	,0x210E	,0xDC49	,0x0000	), // U+1D449; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL V
/*M_ITALIC           */	DEADTRANS(	L'v'	,0x210E	,0xDC63	,0x0000	), // U+1D463; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL V
/*M_ITALIC           */	DEADTRANS(	L'W'	,0x210E	,0xDC4A	,0x0000	), // U+1D44A; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL W
/*M_ITALIC           */	DEADTRANS(	L'w'	,0x210E	,0xDC64	,0x0000	), // U+1D464; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL W
/*M_ITALIC           */	DEADTRANS(	L'X'	,0x210E	,0xDC4B	,0x0000	), // U+1D44B; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL X
/*M_ITALIC           */	DEADTRANS(	L'x'	,0x210E	,0xDC65	,0x0000	), // U+1D465; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL X
/*M_ITALIC           */	DEADTRANS(	L'Y'	,0x210E	,0xDC4C	,0x0000	), // U+1D44C; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Y
/*M_ITALIC           */	DEADTRANS(	L'y'	,0x210E	,0xDC66	,0x0000	), // U+1D466; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Y
/*M_ITALIC           */	DEADTRANS(	L'Z'	,0x210E	,0xDC4D	,0x0000	), // U+1D44D; input D835 high surrogate first; MATHEMATICAL ITALIC CAPITAL Z
/*M_ITALIC           */	DEADTRANS(	L'z'	,0x210E	,0xDC67	,0x0000	), // U+1D467; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL Z
/*M_ITALIC           */	DEADTRANS(	0x0024	,0x210E	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*M_ITALIC           */	DEADTRANS(	0x002A	,0x210E	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*M_ITALIC           */	DEADTRANS(	0x002C	,0x210E	,0xDEA5	,0x0000	), // U+1D6A5; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS J
/*M_ITALIC           */	DEADTRANS(	0x002E	,0x210E	,0xDEA4	,0x0000	), // U+1D6A4; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS I
/*M_ITALIC           */	DEADTRANS(	0x003B	,0x210E	,0xDEA4	,0x0000	), // U+1D6A4; input D835 high surrogate first; MATHEMATICAL ITALIC SMALL DOTLESS I
/*M_MONOSPACE        */	DEADTRANS(	L'A'	,0x2102	,0xDE70	,0x0000	), // U+1D670; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL A
/*M_MONOSPACE        */	DEADTRANS(	L'a'	,0x2102	,0xDE8A	,0x0000	), // U+1D68A; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL A
/*M_MONOSPACE        */	DEADTRANS(	L'B'	,0x2102	,0xDE71	,0x0000	), // U+1D671; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL B
/*M_MONOSPACE        */	DEADTRANS(	L'b'	,0x2102	,0xDE8B	,0x0000	), // U+1D68B; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL B
/*M_MONOSPACE        */	DEADTRANS(	L'C'	,0x2102	,0xDE72	,0x0000	), // U+1D672; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL C
/*M_MONOSPACE        */	DEADTRANS(	L'c'	,0x2102	,0xDE8C	,0x0000	), // U+1D68C; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL C
/*M_MONOSPACE        */	DEADTRANS(	L'D'	,0x2102	,0xDE73	,0x0000	), // U+1D673; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL D
/*M_MONOSPACE        */	DEADTRANS(	L'd'	,0x2102	,0xDE8D	,0x0000	), // U+1D68D; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL D
/*M_MONOSPACE        */	DEADTRANS(	L'E'	,0x2102	,0xDE74	,0x0000	), // U+1D674; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL E
/*M_MONOSPACE        */	DEADTRANS(	L'e'	,0x2102	,0xDE8E	,0x0000	), // U+1D68E; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL E
/*M_MONOSPACE        */	DEADTRANS(	L'F'	,0x2102	,0xDE75	,0x0000	), // U+1D675; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL F
/*M_MONOSPACE        */	DEADTRANS(	L'f'	,0x2102	,0xDE8F	,0x0000	), // U+1D68F; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL F
/*M_MONOSPACE        */	DEADTRANS(	L'G'	,0x2102	,0xDE76	,0x0000	), // U+1D676; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL G
/*M_MONOSPACE        */	DEADTRANS(	L'g'	,0x2102	,0xDE90	,0x0000	), // U+1D690; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL G
/*M_MONOSPACE        */	DEADTRANS(	L'H'	,0x2102	,0xDE77	,0x0000	), // U+1D677; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL H
/*M_MONOSPACE        */	DEADTRANS(	L'h'	,0x2102	,0xDE91	,0x0000	), // U+1D691; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL H
/*M_MONOSPACE        */	DEADTRANS(	L'I'	,0x2102	,0xDE78	,0x0000	), // U+1D678; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL I
/*M_MONOSPACE        */	DEADTRANS(	L'i'	,0x2102	,0xDE92	,0x0000	), // U+1D692; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL I
/*M_MONOSPACE        */	DEADTRANS(	L'J'	,0x2102	,0xDE79	,0x0000	), // U+1D679; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL J
/*M_MONOSPACE        */	DEADTRANS(	L'j'	,0x2102	,0xDE93	,0x0000	), // U+1D693; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL J
/*M_MONOSPACE        */	DEADTRANS(	L'K'	,0x2102	,0xDE7A	,0x0000	), // U+1D67A; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL K
/*M_MONOSPACE        */	DEADTRANS(	L'k'	,0x2102	,0xDE94	,0x0000	), // U+1D694; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL K
/*M_MONOSPACE        */	DEADTRANS(	L'L'	,0x2102	,0xDE7B	,0x0000	), // U+1D67B; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL L
/*M_MONOSPACE        */	DEADTRANS(	L'l'	,0x2102	,0xDE95	,0x0000	), // U+1D695; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL L
/*M_MONOSPACE        */	DEADTRANS(	L'M'	,0x2102	,0xDE7C	,0x0000	), // U+1D67C; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL M
/*M_MONOSPACE        */	DEADTRANS(	L'm'	,0x2102	,0xDE96	,0x0000	), // U+1D696; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL M
/*M_MONOSPACE        */	DEADTRANS(	L'N'	,0x2102	,0xDE7D	,0x0000	), // U+1D67D; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL N
/*M_MONOSPACE        */	DEADTRANS(	L'n'	,0x2102	,0xDE97	,0x0000	), // U+1D697; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL N
/*M_MONOSPACE        */	DEADTRANS(	L'O'	,0x2102	,0xDE7E	,0x0000	), // U+1D67E; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL O
/*M_MONOSPACE        */	DEADTRANS(	L'o'	,0x2102	,0xDE98	,0x0000	), // U+1D698; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL O
/*M_MONOSPACE        */	DEADTRANS(	L'P'	,0x2102	,0xDE7F	,0x0000	), // U+1D67F; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL P
/*M_MONOSPACE        */	DEADTRANS(	L'p'	,0x2102	,0xDE99	,0x0000	), // U+1D699; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL P
/*M_MONOSPACE        */	DEADTRANS(	L'Q'	,0x2102	,0xDE80	,0x0000	), // U+1D680; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Q
/*M_MONOSPACE        */	DEADTRANS(	L'q'	,0x2102	,0xDE9A	,0x0000	), // U+1D69A; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Q
/*M_MONOSPACE        */	DEADTRANS(	L'R'	,0x2102	,0xDE81	,0x0000	), // U+1D681; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL R
/*M_MONOSPACE        */	DEADTRANS(	L'r'	,0x2102	,0xDE9B	,0x0000	), // U+1D69B; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL R
/*M_MONOSPACE        */	DEADTRANS(	L'S'	,0x2102	,0xDE82	,0x0000	), // U+1D682; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL S
/*M_MONOSPACE        */	DEADTRANS(	L's'	,0x2102	,0xDE9C	,0x0000	), // U+1D69C; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL S
/*M_MONOSPACE        */	DEADTRANS(	L'T'	,0x2102	,0xDE83	,0x0000	), // U+1D683; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL T
/*M_MONOSPACE        */	DEADTRANS(	L't'	,0x2102	,0xDE9D	,0x0000	), // U+1D69D; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL T
/*M_MONOSPACE        */	DEADTRANS(	L'U'	,0x2102	,0xDE84	,0x0000	), // U+1D684; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL U
/*M_MONOSPACE        */	DEADTRANS(	L'u'	,0x2102	,0xDE9E	,0x0000	), // U+1D69E; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL U
/*M_MONOSPACE        */	DEADTRANS(	L'V'	,0x2102	,0xDE85	,0x0000	), // U+1D685; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL V
/*M_MONOSPACE        */	DEADTRANS(	L'v'	,0x2102	,0xDE9F	,0x0000	), // U+1D69F; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL V
/*M_MONOSPACE        */	DEADTRANS(	L'W'	,0x2102	,0xDE86	,0x0000	), // U+1D686; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL W
/*M_MONOSPACE        */	DEADTRANS(	L'w'	,0x2102	,0xDEA0	,0x0000	), // U+1D6A0; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL W
/*M_MONOSPACE        */	DEADTRANS(	L'X'	,0x2102	,0xDE87	,0x0000	), // U+1D687; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL X
/*M_MONOSPACE        */	DEADTRANS(	L'x'	,0x2102	,0xDEA1	,0x0000	), // U+1D6A1; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL X
/*M_MONOSPACE        */	DEADTRANS(	L'Y'	,0x2102	,0xDE88	,0x0000	), // U+1D688; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Y
/*M_MONOSPACE        */	DEADTRANS(	L'y'	,0x2102	,0xDEA2	,0x0000	), // U+1D6A2; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Y
/*M_MONOSPACE        */	DEADTRANS(	L'Z'	,0x2102	,0xDE89	,0x0000	), // U+1D689; input D835 high surrogate first; MATHEMATICAL MONOSPACE CAPITAL Z
/*M_MONOSPACE        */	DEADTRANS(	L'z'	,0x2102	,0xDEA3	,0x0000	), // U+1D6A3; input D835 high surrogate first; MATHEMATICAL MONOSPACE SMALL Z
/*M_SANS             */	DEADTRANS(	L'A'	,0x210B	,0xDDA0	,0x0000	), // U+1D5A0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL A
/*M_SANS             */	DEADTRANS(	L'a'	,0x210B	,0xDDBA	,0x0000	), // U+1D5BA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL A
/*M_SANS             */	DEADTRANS(	L'B'	,0x210B	,0xDDA1	,0x0000	), // U+1D5A1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL B
/*M_SANS             */	DEADTRANS(	L'b'	,0x210B	,0xDDBB	,0x0000	), // U+1D5BB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL B
/*M_SANS             */	DEADTRANS(	L'C'	,0x210B	,0xDDA2	,0x0000	), // U+1D5A2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL C
/*M_SANS             */	DEADTRANS(	L'c'	,0x210B	,0xDDBC	,0x0000	), // U+1D5BC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL C
/*M_SANS             */	DEADTRANS(	L'D'	,0x210B	,0xDDA3	,0x0000	), // U+1D5A3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL D
/*M_SANS             */	DEADTRANS(	L'd'	,0x210B	,0xDDBD	,0x0000	), // U+1D5BD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL D
/*M_SANS             */	DEADTRANS(	L'E'	,0x210B	,0xDDA4	,0x0000	), // U+1D5A4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL E
/*M_SANS             */	DEADTRANS(	L'e'	,0x210B	,0xDDBE	,0x0000	), // U+1D5BE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL E
/*M_SANS             */	DEADTRANS(	L'F'	,0x210B	,0xDDA5	,0x0000	), // U+1D5A5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL F
/*M_SANS             */	DEADTRANS(	L'f'	,0x210B	,0xDDBF	,0x0000	), // U+1D5BF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL F
/*M_SANS             */	DEADTRANS(	L'G'	,0x210B	,0xDDA6	,0x0000	), // U+1D5A6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL G
/*M_SANS             */	DEADTRANS(	L'g'	,0x210B	,0xDDC0	,0x0000	), // U+1D5C0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL G
/*M_SANS             */	DEADTRANS(	L'H'	,0x210B	,0xDDA7	,0x0000	), // U+1D5A7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL H
/*M_SANS             */	DEADTRANS(	L'h'	,0x210B	,0xDDC1	,0x0000	), // U+1D5C1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL H
/*M_SANS             */	DEADTRANS(	L'I'	,0x210B	,0xDDA8	,0x0000	), // U+1D5A8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL I
/*M_SANS             */	DEADTRANS(	L'i'	,0x210B	,0xDDC2	,0x0000	), // U+1D5C2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL I
/*M_SANS             */	DEADTRANS(	L'J'	,0x210B	,0xDDA9	,0x0000	), // U+1D5A9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL J
/*M_SANS             */	DEADTRANS(	L'j'	,0x210B	,0xDDC3	,0x0000	), // U+1D5C3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL J
/*M_SANS             */	DEADTRANS(	L'K'	,0x210B	,0xDDAA	,0x0000	), // U+1D5AA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL K
/*M_SANS             */	DEADTRANS(	L'k'	,0x210B	,0xDDC4	,0x0000	), // U+1D5C4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL K
/*M_SANS             */	DEADTRANS(	L'L'	,0x210B	,0xDDAB	,0x0000	), // U+1D5AB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL L
/*M_SANS             */	DEADTRANS(	L'l'	,0x210B	,0xDDC5	,0x0000	), // U+1D5C5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL L
/*M_SANS             */	DEADTRANS(	L'M'	,0x210B	,0xDDAC	,0x0000	), // U+1D5AC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL M
/*M_SANS             */	DEADTRANS(	L'm'	,0x210B	,0xDDC6	,0x0000	), // U+1D5C6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL M
/*M_SANS             */	DEADTRANS(	L'N'	,0x210B	,0xDDAD	,0x0000	), // U+1D5AD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL N
/*M_SANS             */	DEADTRANS(	L'n'	,0x210B	,0xDDC7	,0x0000	), // U+1D5C7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL N
/*M_SANS             */	DEADTRANS(	L'O'	,0x210B	,0xDDAE	,0x0000	), // U+1D5AE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL O
/*M_SANS             */	DEADTRANS(	L'o'	,0x210B	,0xDDC8	,0x0000	), // U+1D5C8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL O
/*M_SANS             */	DEADTRANS(	L'P'	,0x210B	,0xDDAF	,0x0000	), // U+1D5AF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL P
/*M_SANS             */	DEADTRANS(	L'p'	,0x210B	,0xDDC9	,0x0000	), // U+1D5C9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL P
/*M_SANS             */	DEADTRANS(	L'Q'	,0x210B	,0xDDB0	,0x0000	), // U+1D5B0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Q
/*M_SANS             */	DEADTRANS(	L'q'	,0x210B	,0xDDCA	,0x0000	), // U+1D5CA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Q
/*M_SANS             */	DEADTRANS(	L'R'	,0x210B	,0xDDB1	,0x0000	), // U+1D5B1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL R
/*M_SANS             */	DEADTRANS(	L'r'	,0x210B	,0xDDCB	,0x0000	), // U+1D5CB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL R
/*M_SANS             */	DEADTRANS(	L'S'	,0x210B	,0xDDB2	,0x0000	), // U+1D5B2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL S
/*M_SANS             */	DEADTRANS(	L's'	,0x210B	,0xDDCC	,0x0000	), // U+1D5CC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL S
/*M_SANS             */	DEADTRANS(	L'T'	,0x210B	,0xDDB3	,0x0000	), // U+1D5B3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL T
/*M_SANS             */	DEADTRANS(	L't'	,0x210B	,0xDDCD	,0x0000	), // U+1D5CD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL T
/*M_SANS             */	DEADTRANS(	L'U'	,0x210B	,0xDDB4	,0x0000	), // U+1D5B4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL U
/*M_SANS             */	DEADTRANS(	L'u'	,0x210B	,0xDDCE	,0x0000	), // U+1D5CE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL U
/*M_SANS             */	DEADTRANS(	L'V'	,0x210B	,0xDDB5	,0x0000	), // U+1D5B5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL V
/*M_SANS             */	DEADTRANS(	L'v'	,0x210B	,0xDDCF	,0x0000	), // U+1D5CF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL V
/*M_SANS             */	DEADTRANS(	L'W'	,0x210B	,0xDDB6	,0x0000	), // U+1D5B6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL W
/*M_SANS             */	DEADTRANS(	L'w'	,0x210B	,0xDDD0	,0x0000	), // U+1D5D0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL W
/*M_SANS             */	DEADTRANS(	L'X'	,0x210B	,0xDDB7	,0x0000	), // U+1D5B7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL X
/*M_SANS             */	DEADTRANS(	L'x'	,0x210B	,0xDDD1	,0x0000	), // U+1D5D1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL X
/*M_SANS             */	DEADTRANS(	L'Y'	,0x210B	,0xDDB8	,0x0000	), // U+1D5B8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Y
/*M_SANS             */	DEADTRANS(	L'y'	,0x210B	,0xDDD2	,0x0000	), // U+1D5D2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Y
/*M_SANS             */	DEADTRANS(	L'Z'	,0x210B	,0xDDB9	,0x0000	), // U+1D5B9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF CAPITAL Z
/*M_SANS             */	DEADTRANS(	L'z'	,0x210B	,0xDDD3	,0x0000	), // U+1D5D3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF SMALL Z
/*M_SANS             */	DEADTRANS(	0x002A	,0x210B	,0x211B	,0x0001	), // SCRIPT CAPITAL R
/*M_SANS             */	DEADTRANS(	0x002F	,0x210B	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*M_SANS_BOLD        */	DEADTRANS(	L'A'	,0x211B	,0xDDD4	,0x0000	), // U+1D5D4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL A
/*M_SANS_BOLD        */	DEADTRANS(	L'a'	,0x211B	,0xDDEE	,0x0000	), // U+1D5EE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL A
/*M_SANS_BOLD        */	DEADTRANS(	L'B'	,0x211B	,0xDDD5	,0x0000	), // U+1D5D5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL B
/*M_SANS_BOLD        */	DEADTRANS(	L'b'	,0x211B	,0xDDEF	,0x0000	), // U+1D5EF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL B
/*M_SANS_BOLD        */	DEADTRANS(	L'C'	,0x211B	,0xDDD6	,0x0000	), // U+1D5D6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL C
/*M_SANS_BOLD        */	DEADTRANS(	L'c'	,0x211B	,0xDDF0	,0x0000	), // U+1D5F0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL C
/*M_SANS_BOLD        */	DEADTRANS(	L'D'	,0x211B	,0xDDD7	,0x0000	), // U+1D5D7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL D
/*M_SANS_BOLD        */	DEADTRANS(	L'd'	,0x211B	,0xDDF1	,0x0000	), // U+1D5F1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL D
/*M_SANS_BOLD        */	DEADTRANS(	L'E'	,0x211B	,0xDDD8	,0x0000	), // U+1D5D8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL E
/*M_SANS_BOLD        */	DEADTRANS(	L'e'	,0x211B	,0xDDF2	,0x0000	), // U+1D5F2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL E
/*M_SANS_BOLD        */	DEADTRANS(	L'F'	,0x211B	,0xDDD9	,0x0000	), // U+1D5D9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL F
/*M_SANS_BOLD        */	DEADTRANS(	L'f'	,0x211B	,0xDDF3	,0x0000	), // U+1D5F3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL F
/*M_SANS_BOLD        */	DEADTRANS(	L'G'	,0x211B	,0xDDDA	,0x0000	), // U+1D5DA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL G
/*M_SANS_BOLD        */	DEADTRANS(	L'g'	,0x211B	,0xDDF4	,0x0000	), // U+1D5F4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL G
/*M_SANS_BOLD        */	DEADTRANS(	L'H'	,0x211B	,0xDDDB	,0x0000	), // U+1D5DB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL H
/*M_SANS_BOLD        */	DEADTRANS(	L'h'	,0x211B	,0xDDF5	,0x0000	), // U+1D5F5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL H
/*M_SANS_BOLD        */	DEADTRANS(	L'I'	,0x211B	,0xDDDC	,0x0000	), // U+1D5DC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL I
/*M_SANS_BOLD        */	DEADTRANS(	L'i'	,0x211B	,0xDDF6	,0x0000	), // U+1D5F6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL I
/*M_SANS_BOLD        */	DEADTRANS(	L'J'	,0x211B	,0xDDDD	,0x0000	), // U+1D5DD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL J
/*M_SANS_BOLD        */	DEADTRANS(	L'j'	,0x211B	,0xDDF7	,0x0000	), // U+1D5F7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL J
/*M_SANS_BOLD        */	DEADTRANS(	L'K'	,0x211B	,0xDDDE	,0x0000	), // U+1D5DE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL K
/*M_SANS_BOLD        */	DEADTRANS(	L'k'	,0x211B	,0xDDF8	,0x0000	), // U+1D5F8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL K
/*M_SANS_BOLD        */	DEADTRANS(	L'L'	,0x211B	,0xDDDF	,0x0000	), // U+1D5DF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL L
/*M_SANS_BOLD        */	DEADTRANS(	L'l'	,0x211B	,0xDDF9	,0x0000	), // U+1D5F9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL L
/*M_SANS_BOLD        */	DEADTRANS(	L'M'	,0x211B	,0xDDE0	,0x0000	), // U+1D5E0; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL M
/*M_SANS_BOLD        */	DEADTRANS(	L'm'	,0x211B	,0xDDFA	,0x0000	), // U+1D5FA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL M
/*M_SANS_BOLD        */	DEADTRANS(	L'N'	,0x211B	,0xDDE1	,0x0000	), // U+1D5E1; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL N
/*M_SANS_BOLD        */	DEADTRANS(	L'n'	,0x211B	,0xDDFB	,0x0000	), // U+1D5FB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL N
/*M_SANS_BOLD        */	DEADTRANS(	L'O'	,0x211B	,0xDDE2	,0x0000	), // U+1D5E2; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL O
/*M_SANS_BOLD        */	DEADTRANS(	L'o'	,0x211B	,0xDDFC	,0x0000	), // U+1D5FC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL O
/*M_SANS_BOLD        */	DEADTRANS(	L'P'	,0x211B	,0xDDE3	,0x0000	), // U+1D5E3; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL P
/*M_SANS_BOLD        */	DEADTRANS(	L'p'	,0x211B	,0xDDFD	,0x0000	), // U+1D5FD; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL P
/*M_SANS_BOLD        */	DEADTRANS(	L'Q'	,0x211B	,0xDDE4	,0x0000	), // U+1D5E4; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Q
/*M_SANS_BOLD        */	DEADTRANS(	L'q'	,0x211B	,0xDDFE	,0x0000	), // U+1D5FE; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Q
/*M_SANS_BOLD        */	DEADTRANS(	L'R'	,0x211B	,0xDDE5	,0x0000	), // U+1D5E5; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL R
/*M_SANS_BOLD        */	DEADTRANS(	L'r'	,0x211B	,0xDDFF	,0x0000	), // U+1D5FF; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL R
/*M_SANS_BOLD        */	DEADTRANS(	L'S'	,0x211B	,0xDDE6	,0x0000	), // U+1D5E6; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL S
/*M_SANS_BOLD        */	DEADTRANS(	L's'	,0x211B	,0xDE00	,0x0000	), // U+1D600; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL S
/*M_SANS_BOLD        */	DEADTRANS(	L'T'	,0x211B	,0xDDE7	,0x0000	), // U+1D5E7; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL T
/*M_SANS_BOLD        */	DEADTRANS(	L't'	,0x211B	,0xDE01	,0x0000	), // U+1D601; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL T
/*M_SANS_BOLD        */	DEADTRANS(	L'U'	,0x211B	,0xDDE8	,0x0000	), // U+1D5E8; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL U
/*M_SANS_BOLD        */	DEADTRANS(	L'u'	,0x211B	,0xDE02	,0x0000	), // U+1D602; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL U
/*M_SANS_BOLD        */	DEADTRANS(	L'V'	,0x211B	,0xDDE9	,0x0000	), // U+1D5E9; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL V
/*M_SANS_BOLD        */	DEADTRANS(	L'v'	,0x211B	,0xDE03	,0x0000	), // U+1D603; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL V
/*M_SANS_BOLD        */	DEADTRANS(	L'W'	,0x211B	,0xDDEA	,0x0000	), // U+1D5EA; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL W
/*M_SANS_BOLD        */	DEADTRANS(	L'w'	,0x211B	,0xDE04	,0x0000	), // U+1D604; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL W
/*M_SANS_BOLD        */	DEADTRANS(	L'X'	,0x211B	,0xDDEB	,0x0000	), // U+1D5EB; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL X
/*M_SANS_BOLD        */	DEADTRANS(	L'x'	,0x211B	,0xDE05	,0x0000	), // U+1D605; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL X
/*M_SANS_BOLD        */	DEADTRANS(	L'Y'	,0x211B	,0xDDEC	,0x0000	), // U+1D5EC; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Y
/*M_SANS_BOLD        */	DEADTRANS(	L'y'	,0x211B	,0xDE06	,0x0000	), // U+1D606; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Y
/*M_SANS_BOLD        */	DEADTRANS(	L'Z'	,0x211B	,0xDDED	,0x0000	), // U+1D5ED; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD CAPITAL Z
/*M_SANS_BOLD        */	DEADTRANS(	L'z'	,0x211B	,0xDE07	,0x0000	), // U+1D607; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD SMALL Z
/*M_SANS_BOLD        */	DEADTRANS(	0x002F	,0x211B	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'A'	,0x2130	,0xDE3C	,0x0000	), // U+1D63C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL A
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'B'	,0x2130	,0xDE3D	,0x0000	), // U+1D63D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL B
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'C'	,0x2130	,0xDE3E	,0x0000	), // U+1D63E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL C
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'D'	,0x2130	,0xDE3F	,0x0000	), // U+1D63F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL D
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'E'	,0x2130	,0xDE40	,0x0000	), // U+1D640; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'F'	,0x2130	,0xDE41	,0x0000	), // U+1D641; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL F
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'G'	,0x2130	,0xDE42	,0x0000	), // U+1D642; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL G
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'H'	,0x2130	,0xDE43	,0x0000	), // U+1D643; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL H
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'I'	,0x2130	,0xDE44	,0x0000	), // U+1D644; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL I
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'J'	,0x2130	,0xDE45	,0x0000	), // U+1D645; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL J
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'K'	,0x2130	,0xDE46	,0x0000	), // U+1D646; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL K
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'L'	,0x2130	,0xDE47	,0x0000	), // U+1D647; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL L
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'M'	,0x2130	,0xDE48	,0x0000	), // U+1D648; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL M
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'N'	,0x2130	,0xDE49	,0x0000	), // U+1D649; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL N
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'O'	,0x2130	,0xDE4A	,0x0000	), // U+1D64A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL O
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'P'	,0x2130	,0xDE4B	,0x0000	), // U+1D64B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL P
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Q'	,0x2130	,0xDE4C	,0x0000	), // U+1D64C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Q
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'R'	,0x2130	,0xDE4D	,0x0000	), // U+1D64D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL R
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'S'	,0x2130	,0xDE4E	,0x0000	), // U+1D64E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL S
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'T'	,0x2130	,0xDE4F	,0x0000	), // U+1D64F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL T
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'U'	,0x2130	,0xDE50	,0x0000	), // U+1D650; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL U
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'V'	,0x2130	,0xDE51	,0x0000	), // U+1D651; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL V
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'W'	,0x2130	,0xDE52	,0x0000	), // U+1D652; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL W
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'X'	,0x2130	,0xDE53	,0x0000	), // U+1D653; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL X
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Y'	,0x2130	,0xDE54	,0x0000	), // U+1D654; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Y
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'Z'	,0x2130	,0xDE55	,0x0000	), // U+1D655; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL Z
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'a'	,0x2130	,0xDE56	,0x0000	), // U+1D656; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL A
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'b'	,0x2130	,0xDE57	,0x0000	), // U+1D657; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL B
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'c'	,0x2130	,0xDE58	,0x0000	), // U+1D658; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL C
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'd'	,0x2130	,0xDE59	,0x0000	), // U+1D659; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL D
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'e'	,0x2130	,0xDE5A	,0x0000	), // U+1D65A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL E
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'f'	,0x2130	,0xDE5B	,0x0000	), // U+1D65B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL F
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'g'	,0x2130	,0xDE5C	,0x0000	), // U+1D65C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL G
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'h'	,0x2130	,0xDE5D	,0x0000	), // U+1D65D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL H
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'i'	,0x2130	,0xDE5E	,0x0000	), // U+1D65E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL I
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'j'	,0x2130	,0xDE5F	,0x0000	), // U+1D65F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL J
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'k'	,0x2130	,0xDE60	,0x0000	), // U+1D660; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL K
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'l'	,0x2130	,0xDE61	,0x0000	), // U+1D661; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL L
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'm'	,0x2130	,0xDE62	,0x0000	), // U+1D662; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL M
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'n'	,0x2130	,0xDE63	,0x0000	), // U+1D663; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL N
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'o'	,0x2130	,0xDE64	,0x0000	), // U+1D664; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL O
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'p'	,0x2130	,0xDE65	,0x0000	), // U+1D665; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL P
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'q'	,0x2130	,0xDE66	,0x0000	), // U+1D666; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Q
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'r'	,0x2130	,0xDE67	,0x0000	), // U+1D667; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL R
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L's'	,0x2130	,0xDE68	,0x0000	), // U+1D668; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL S
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L't'	,0x2130	,0xDE69	,0x0000	), // U+1D669; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL T
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'u'	,0x2130	,0xDE6A	,0x0000	), // U+1D66A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL U
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'v'	,0x2130	,0xDE6B	,0x0000	), // U+1D66B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL V
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'w'	,0x2130	,0xDE6C	,0x0000	), // U+1D66C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL W
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'x'	,0x2130	,0xDE6D	,0x0000	), // U+1D66D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL X
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'y'	,0x2130	,0xDE6E	,0x0000	), // U+1D66E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Y
/*M_SANS_BOLD_ITALIC */	DEADTRANS(	L'z'	,0x2130	,0xDE6F	,0x0000	), // U+1D66F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF BOLD ITALIC SMALL Z
/*M_SANS_ITALIC      */	DEADTRANS(	L'A'	,0x2112	,0xDE08	,0x0000	), // U+1D608; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL A
/*M_SANS_ITALIC      */	DEADTRANS(	L'a'	,0x2112	,0xDE22	,0x0000	), // U+1D622; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL A
/*M_SANS_ITALIC      */	DEADTRANS(	L'B'	,0x2112	,0xDE09	,0x0000	), // U+1D609; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL B
/*M_SANS_ITALIC      */	DEADTRANS(	L'b'	,0x2112	,0xDE23	,0x0000	), // U+1D623; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL B
/*M_SANS_ITALIC      */	DEADTRANS(	L'C'	,0x2112	,0xDE0A	,0x0000	), // U+1D60A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL C
/*M_SANS_ITALIC      */	DEADTRANS(	L'c'	,0x2112	,0xDE24	,0x0000	), // U+1D624; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL C
/*M_SANS_ITALIC      */	DEADTRANS(	L'D'	,0x2112	,0xDE0B	,0x0000	), // U+1D60B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL D
/*M_SANS_ITALIC      */	DEADTRANS(	L'd'	,0x2112	,0xDE25	,0x0000	), // U+1D625; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL D
/*M_SANS_ITALIC      */	DEADTRANS(	L'E'	,0x2112	,0xDE0C	,0x0000	), // U+1D60C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL E
/*M_SANS_ITALIC      */	DEADTRANS(	L'e'	,0x2112	,0xDE26	,0x0000	), // U+1D626; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL E
/*M_SANS_ITALIC      */	DEADTRANS(	L'F'	,0x2112	,0xDE0D	,0x0000	), // U+1D60D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL F
/*M_SANS_ITALIC      */	DEADTRANS(	L'f'	,0x2112	,0xDE27	,0x0000	), // U+1D627; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL F
/*M_SANS_ITALIC      */	DEADTRANS(	L'G'	,0x2112	,0xDE0E	,0x0000	), // U+1D60E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL G
/*M_SANS_ITALIC      */	DEADTRANS(	L'g'	,0x2112	,0xDE28	,0x0000	), // U+1D628; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL G
/*M_SANS_ITALIC      */	DEADTRANS(	L'H'	,0x2112	,0xDE0F	,0x0000	), // U+1D60F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL H
/*M_SANS_ITALIC      */	DEADTRANS(	L'h'	,0x2112	,0xDE29	,0x0000	), // U+1D629; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL H
/*M_SANS_ITALIC      */	DEADTRANS(	L'I'	,0x2112	,0xDE10	,0x0000	), // U+1D610; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL I
/*M_SANS_ITALIC      */	DEADTRANS(	L'i'	,0x2112	,0xDE2A	,0x0000	), // U+1D62A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL I
/*M_SANS_ITALIC      */	DEADTRANS(	L'J'	,0x2112	,0xDE11	,0x0000	), // U+1D611; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL J
/*M_SANS_ITALIC      */	DEADTRANS(	L'j'	,0x2112	,0xDE2B	,0x0000	), // U+1D62B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL J
/*M_SANS_ITALIC      */	DEADTRANS(	L'K'	,0x2112	,0xDE12	,0x0000	), // U+1D612; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL K
/*M_SANS_ITALIC      */	DEADTRANS(	L'k'	,0x2112	,0xDE2C	,0x0000	), // U+1D62C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL K
/*M_SANS_ITALIC      */	DEADTRANS(	L'L'	,0x2112	,0xDE13	,0x0000	), // U+1D613; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL L
/*M_SANS_ITALIC      */	DEADTRANS(	L'l'	,0x2112	,0xDE2D	,0x0000	), // U+1D62D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL L
/*M_SANS_ITALIC      */	DEADTRANS(	L'M'	,0x2112	,0xDE14	,0x0000	), // U+1D614; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL M
/*M_SANS_ITALIC      */	DEADTRANS(	L'm'	,0x2112	,0xDE2E	,0x0000	), // U+1D62E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL M
/*M_SANS_ITALIC      */	DEADTRANS(	L'N'	,0x2112	,0xDE15	,0x0000	), // U+1D615; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL N
/*M_SANS_ITALIC      */	DEADTRANS(	L'n'	,0x2112	,0xDE2F	,0x0000	), // U+1D62F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL N
/*M_SANS_ITALIC      */	DEADTRANS(	L'O'	,0x2112	,0xDE16	,0x0000	), // U+1D616; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL O
/*M_SANS_ITALIC      */	DEADTRANS(	L'o'	,0x2112	,0xDE30	,0x0000	), // U+1D630; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL O
/*M_SANS_ITALIC      */	DEADTRANS(	L'P'	,0x2112	,0xDE17	,0x0000	), // U+1D617; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL P
/*M_SANS_ITALIC      */	DEADTRANS(	L'p'	,0x2112	,0xDE31	,0x0000	), // U+1D631; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL P
/*M_SANS_ITALIC      */	DEADTRANS(	L'Q'	,0x2112	,0xDE18	,0x0000	), // U+1D618; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Q
/*M_SANS_ITALIC      */	DEADTRANS(	L'q'	,0x2112	,0xDE32	,0x0000	), // U+1D632; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Q
/*M_SANS_ITALIC      */	DEADTRANS(	L'R'	,0x2112	,0xDE19	,0x0000	), // U+1D619; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL R
/*M_SANS_ITALIC      */	DEADTRANS(	L'r'	,0x2112	,0xDE33	,0x0000	), // U+1D633; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL R
/*M_SANS_ITALIC      */	DEADTRANS(	L'S'	,0x2112	,0xDE1A	,0x0000	), // U+1D61A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL S
/*M_SANS_ITALIC      */	DEADTRANS(	L's'	,0x2112	,0xDE34	,0x0000	), // U+1D634; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL S
/*M_SANS_ITALIC      */	DEADTRANS(	L'T'	,0x2112	,0xDE1B	,0x0000	), // U+1D61B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL T
/*M_SANS_ITALIC      */	DEADTRANS(	L't'	,0x2112	,0xDE35	,0x0000	), // U+1D635; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL T
/*M_SANS_ITALIC      */	DEADTRANS(	L'U'	,0x2112	,0xDE1C	,0x0000	), // U+1D61C; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL U
/*M_SANS_ITALIC      */	DEADTRANS(	L'u'	,0x2112	,0xDE36	,0x0000	), // U+1D636; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL U
/*M_SANS_ITALIC      */	DEADTRANS(	L'V'	,0x2112	,0xDE1D	,0x0000	), // U+1D61D; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL V
/*M_SANS_ITALIC      */	DEADTRANS(	L'v'	,0x2112	,0xDE37	,0x0000	), // U+1D637; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL V
/*M_SANS_ITALIC      */	DEADTRANS(	L'W'	,0x2112	,0xDE1E	,0x0000	), // U+1D61E; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL W
/*M_SANS_ITALIC      */	DEADTRANS(	L'w'	,0x2112	,0xDE38	,0x0000	), // U+1D638; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL W
/*M_SANS_ITALIC      */	DEADTRANS(	L'X'	,0x2112	,0xDE1F	,0x0000	), // U+1D61F; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL X
/*M_SANS_ITALIC      */	DEADTRANS(	L'x'	,0x2112	,0xDE39	,0x0000	), // U+1D639; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL X
/*M_SANS_ITALIC      */	DEADTRANS(	L'Y'	,0x2112	,0xDE20	,0x0000	), // U+1D620; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Y
/*M_SANS_ITALIC      */	DEADTRANS(	L'y'	,0x2112	,0xDE3A	,0x0000	), // U+1D63A; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Y
/*M_SANS_ITALIC      */	DEADTRANS(	L'Z'	,0x2112	,0xDE21	,0x0000	), // U+1D621; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC CAPITAL Z
/*M_SANS_ITALIC      */	DEADTRANS(	L'z'	,0x2112	,0xDE3B	,0x0000	), // U+1D63B; input D835 high surrogate first; MATHEMATICAL SANS-SERIF ITALIC SMALL Z
/*M_SANS_ITALIC      */	DEADTRANS(	0x002A	,0x2112	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*M_SCRIPT           */	DEADTRANS(	L'A'	,0x212F	,0xDC9C	,0x0000	), // U+1D49C; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL A
/*M_SCRIPT           */	DEADTRANS(	L'a'	,0x212F	,0xDCB6	,0x0000	), // U+1D4B6; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL A
/*M_SCRIPT           */	DEADTRANS(	L'B'	,0x212F	,0x212C	,0x0000	), // SCRIPT CAPITAL B
/*M_SCRIPT           */	DEADTRANS(	L'b'	,0x212F	,0xDCB7	,0x0000	), // U+1D4B7; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL B
/*M_SCRIPT           */	DEADTRANS(	L'C'	,0x212F	,0xDC9E	,0x0000	), // U+1D49E; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL C
/*M_SCRIPT           */	DEADTRANS(	L'c'	,0x212F	,0xDCB8	,0x0000	), // U+1D4B8; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL C
/*M_SCRIPT           */	DEADTRANS(	L'D'	,0x212F	,0xDC9F	,0x0000	), // U+1D49F; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL D
/*M_SCRIPT           */	DEADTRANS(	L'd'	,0x212F	,0xDCB9	,0x0000	), // U+1D4B9; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL D
/*M_SCRIPT           */	DEADTRANS(	L'E'	,0x212F	,0x2130	,0x0000	), // SCRIPT CAPITAL E
/*M_SCRIPT           */	DEADTRANS(	L'e'	,0x212F	,0x212F	,0x0000	), // SCRIPT SMALL E
/*M_SCRIPT           */	DEADTRANS(	L'F'	,0x212F	,0x2131	,0x0000	), // SCRIPT CAPITAL F
/*M_SCRIPT           */	DEADTRANS(	L'f'	,0x212F	,0xDCBB	,0x0000	), // U+1D4BB; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL F
/*M_SCRIPT           */	DEADTRANS(	L'G'	,0x212F	,0xDCA2	,0x0000	), // U+1D4A2; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL G
/*M_SCRIPT           */	DEADTRANS(	L'g'	,0x212F	,0x210A	,0x0000	), // SCRIPT SMALL G
/*M_SCRIPT           */	DEADTRANS(	L'H'	,0x212F	,0x210B	,0x0000	), // SCRIPT CAPITAL H
/*M_SCRIPT           */	DEADTRANS(	L'h'	,0x212F	,0xDCBD	,0x0000	), // U+1D4BD; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL H
/*M_SCRIPT           */	DEADTRANS(	L'I'	,0x212F	,0x2110	,0x0000	), // SCRIPT CAPITAL I
/*M_SCRIPT           */	DEADTRANS(	L'i'	,0x212F	,0xDCBE	,0x0000	), // U+1D4BE; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL I
/*M_SCRIPT           */	DEADTRANS(	L'J'	,0x212F	,0xDCA5	,0x0000	), // U+1D4A5; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL J
/*M_SCRIPT           */	DEADTRANS(	L'j'	,0x212F	,0xDCBF	,0x0000	), // U+1D4BF; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL J
/*M_SCRIPT           */	DEADTRANS(	L'K'	,0x212F	,0xDCA6	,0x0000	), // U+1D4A6; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL K
/*M_SCRIPT           */	DEADTRANS(	L'k'	,0x212F	,0xDCC0	,0x0000	), // U+1D4C0; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL K
/*M_SCRIPT           */	DEADTRANS(	L'L'	,0x212F	,0x2112	,0x0000	), // SCRIPT CAPITAL L
/*M_SCRIPT           */	DEADTRANS(	L'l'	,0x212F	,0xDCC1	,0x0000	), // U+1D4C1; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL L
/*M_SCRIPT           */	DEADTRANS(	L'M'	,0x212F	,0x2133	,0x0000	), // SCRIPT CAPITAL M
/*M_SCRIPT           */	DEADTRANS(	L'm'	,0x212F	,0xDCC2	,0x0000	), // U+1D4C2; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL M
/*M_SCRIPT           */	DEADTRANS(	L'N'	,0x212F	,0xDCA9	,0x0000	), // U+1D4A9; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL N
/*M_SCRIPT           */	DEADTRANS(	L'n'	,0x212F	,0xDCC3	,0x0000	), // U+1D4C3; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL N
/*M_SCRIPT           */	DEADTRANS(	L'O'	,0x212F	,0xDCAA	,0x0000	), // U+1D4AA; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL O
/*M_SCRIPT           */	DEADTRANS(	L'o'	,0x212F	,0x2134	,0x0000	), // SCRIPT SMALL O
/*M_SCRIPT           */	DEADTRANS(	L'P'	,0x212F	,0xDCAB	,0x0000	), // U+1D4AB; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL P
/*M_SCRIPT           */	DEADTRANS(	L'p'	,0x212F	,0xDCC5	,0x0000	), // U+1D4C5; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL P
/*M_SCRIPT           */	DEADTRANS(	L'Q'	,0x212F	,0xDCAC	,0x0000	), // U+1D4AC; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Q
/*M_SCRIPT           */	DEADTRANS(	L'q'	,0x212F	,0xDCC6	,0x0000	), // U+1D4C6; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Q
/*M_SCRIPT           */	DEADTRANS(	L'R'	,0x212F	,0x211B	,0x0000	), // SCRIPT CAPITAL R
/*M_SCRIPT           */	DEADTRANS(	L'r'	,0x212F	,0xDCC7	,0x0000	), // U+1D4C7; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL R
/*M_SCRIPT           */	DEADTRANS(	L'S'	,0x212F	,0xDCAE	,0x0000	), // U+1D4AE; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL S
/*M_SCRIPT           */	DEADTRANS(	L's'	,0x212F	,0xDCC8	,0x0000	), // U+1D4C8; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL S
/*M_SCRIPT           */	DEADTRANS(	L'T'	,0x212F	,0xDCAF	,0x0000	), // U+1D4AF; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL T
/*M_SCRIPT           */	DEADTRANS(	L't'	,0x212F	,0xDCC9	,0x0000	), // U+1D4C9; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL T
/*M_SCRIPT           */	DEADTRANS(	L'U'	,0x212F	,0xDCB0	,0x0000	), // U+1D4B0; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL U
/*M_SCRIPT           */	DEADTRANS(	L'u'	,0x212F	,0xDCCA	,0x0000	), // U+1D4CA; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL U
/*M_SCRIPT           */	DEADTRANS(	L'V'	,0x212F	,0xDCB1	,0x0000	), // U+1D4B1; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL V
/*M_SCRIPT           */	DEADTRANS(	L'v'	,0x212F	,0xDCCB	,0x0000	), // U+1D4CB; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL V
/*M_SCRIPT           */	DEADTRANS(	L'W'	,0x212F	,0xDCB2	,0x0000	), // U+1D4B2; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL W
/*M_SCRIPT           */	DEADTRANS(	L'w'	,0x212F	,0xDCCC	,0x0000	), // U+1D4CC; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL W
/*M_SCRIPT           */	DEADTRANS(	L'X'	,0x212F	,0xDCB3	,0x0000	), // U+1D4B3; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL X
/*M_SCRIPT           */	DEADTRANS(	L'x'	,0x212F	,0xDCCD	,0x0000	), // U+1D4CD; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL X
/*M_SCRIPT           */	DEADTRANS(	L'Y'	,0x212F	,0xDCB4	,0x0000	), // U+1D4B4; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Y
/*M_SCRIPT           */	DEADTRANS(	L'y'	,0x212F	,0xDCCE	,0x0000	), // U+1D4CE; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Y
/*M_SCRIPT           */	DEADTRANS(	L'Z'	,0x212F	,0xDCB5	,0x0000	), // U+1D4B5; input D835 high surrogate first; MATHEMATICAL SCRIPT CAPITAL Z
/*M_SCRIPT           */	DEADTRANS(	L'z'	,0x212F	,0xDCCF	,0x0000	), // U+1D4CF; input D835 high surrogate first; MATHEMATICAL SCRIPT SMALL Z
/*M_SCRIPT           */	DEADTRANS(	0x002A	,0x212F	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MACRON             */	DEADTRANS(	0x0020	,0x02CD	,0x0331	,0x0000	), // COMBINING MACRON BELOW
/*MACRON             */	DEADTRANS(	0x0020	,0x0101	,0x0304	,0x0000	), // COMBINING MACRON
/*MACRON             */	DEADTRANS(	0x0028	,0x0101	,0x1DCC	,0x0000	), // COMBINING MACRON-BREVE
/*MACRON             */	DEADTRANS(	0x005F	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	0x0020	,0x1E53	,0x1DC4	,0x0000	), // COMBINING MACRON-ACUTE
/*MACRON             */	DEADTRANS(	0x0020	,0x1E51	,0x1DC6	,0x0000	), // COMBINING MACRON-GRAVE
/*MACRON             */	DEADTRANS(	0x002A	,0x0101	,0x02C9	,0x0000	), // MODIFIER LETTER MACRON
/*MACRON             */	DEADTRANS(	0x202F	,0x02CD	,0x02CD	,0x0000	), // MODIFIER LETTER LOW MACRON
/*MACRON             */	DEADTRANS(	0x00A0	,0x0101	,0x00AF	,0x0000	), // MACRON
/*MACRON             */	DEADTRANS(	L'A'	,0x0101	,0x0100	,0x0000	), // LATIN CAPITAL LETTER A WITH MACRON
/*MACRON             */	DEADTRANS(	L'a'	,0x0101	,0x0101	,0x0000	), // LATIN SMALL LETTER A WITH MACRON
/*MACRON             */	DEADTRANS(	L'B'	,0x0101	,0x1E06	,0x0000	), // LATIN CAPITAL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'b'	,0x0101	,0x1E07	,0x0000	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'D'	,0x0101	,0x1E0E	,0x0000	), // LATIN CAPITAL LETTER D WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'd'	,0x0101	,0x1E0F	,0x0000	), // LATIN SMALL LETTER D WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'E'	,0x0101	,0x0112	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON
/*MACRON             */	DEADTRANS(	L'e'	,0x0101	,0x0113	,0x0000	), // LATIN SMALL LETTER E WITH MACRON
/*MACRON             */	DEADTRANS(	L'G'	,0x0101	,0x1E20	,0x0000	), // LATIN CAPITAL LETTER G WITH MACRON
/*MACRON             */	DEADTRANS(	L'g'	,0x0101	,0x1E21	,0x0000	), // LATIN SMALL LETTER G WITH MACRON
/*MACRON             */	DEADTRANS(	L'h'	,0x0101	,0x1E96	,0x0000	), // LATIN SMALL LETTER H WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'I'	,0x0101	,0x012A	,0x0000	), // LATIN CAPITAL LETTER I WITH MACRON
/*MACRON             */	DEADTRANS(	L'i'	,0x0101	,0x012B	,0x0000	), // LATIN SMALL LETTER I WITH MACRON
/*MACRON             */	DEADTRANS(	L'K'	,0x0101	,0x1E34	,0x0000	), // LATIN CAPITAL LETTER K WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'k'	,0x0101	,0x1E35	,0x0000	), // LATIN SMALL LETTER K WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'L'	,0x0101	,0x1E3A	,0x0000	), // LATIN CAPITAL LETTER L WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'l'	,0x0101	,0x1E3B	,0x0000	), // LATIN SMALL LETTER L WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'N'	,0x0101	,0x1E48	,0x0000	), // LATIN CAPITAL LETTER N WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'n'	,0x0101	,0x1E49	,0x0000	), // LATIN SMALL LETTER N WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'O'	,0x0101	,0x014C	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON
/*MACRON             */	DEADTRANS(	L'o'	,0x0101	,0x014D	,0x0000	), // LATIN SMALL LETTER O WITH MACRON
/*MACRON             */	DEADTRANS(	L'R'	,0x0101	,0x1E5E	,0x0000	), // LATIN CAPITAL LETTER R WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'r'	,0x0101	,0x1E5F	,0x0000	), // LATIN SMALL LETTER R WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L's'	,0x0101	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*MACRON             */	DEADTRANS(	L'T'	,0x0101	,0x1E6E	,0x0000	), // LATIN CAPITAL LETTER T WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L't'	,0x0101	,0x1E6F	,0x0000	), // LATIN SMALL LETTER T WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'U'	,0x0101	,0x016A	,0x0000	), // LATIN CAPITAL LETTER U WITH MACRON
/*MACRON             */	DEADTRANS(	L'u'	,0x0101	,0x016B	,0x0000	), // LATIN SMALL LETTER U WITH MACRON
/*MACRON             */	DEADTRANS(	L'V'	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	L'v'	,0x0101	,0x0332	,0x0000	), // COMBINING LOW LINE
/*MACRON             */	DEADTRANS(	L'W'	,0x0101	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*MACRON             */	DEADTRANS(	L'w'	,0x0101	,0x0333	,0x0000	), // COMBINING DOUBLE LOW LINE
/*MACRON             */	DEADTRANS(	L'Y'	,0x0101	,0x0232	,0x0000	), // LATIN CAPITAL LETTER Y WITH MACRON
/*MACRON             */	DEADTRANS(	L'y'	,0x0101	,0x0233	,0x0000	), // LATIN SMALL LETTER Y WITH MACRON
/*MACRON             */	DEADTRANS(	L'Z'	,0x0101	,0x1E94	,0x0000	), // LATIN CAPITAL LETTER Z WITH LINE BELOW
/*MACRON             */	DEADTRANS(	L'z'	,0x0101	,0x1E95	,0x0000	), // LATIN SMALL LETTER Z WITH LINE BELOW
/*MACRON             */	DEADTRANS(	0x00C6	,0x0101	,0x01E2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00E6	,0x0101	,0x01E3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00A3	,0x0101	,0x02CD	,0x0001	), // MODIFIER LETTER LOW MACRON
/*MACRON             */	DEADTRANS(	0x0152	,0x0101	,0x01E2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x0153	,0x0101	,0x01E3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x0021	,0x0101	,0x1E5D	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*MACRON             */	DEADTRANS(	0x0025	,0x0101	,0x246B	,0x0000	), // CIRCLED NUMBER TWELVE
/*MACRON             */	DEADTRANS(	0x0027	,0x0101	,0x1E53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON             */	DEADTRANS(	0x002E	,0x0101	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*MACRON             */	DEADTRANS(	L'0'	,0x0101	,0x2469	,0x0000	), // CIRCLED NUMBER TEN
/*MACRON             */	DEADTRANS(	L'1'	,0x0101	,0x2460	,0x0000	), // CIRCLED DIGIT ONE
/*MACRON             */	DEADTRANS(	L'2'	,0x0101	,0x2461	,0x0000	), // CIRCLED DIGIT TWO
/*MACRON             */	DEADTRANS(	L'3'	,0x0101	,0x2462	,0x0000	), // CIRCLED DIGIT THREE
/*MACRON             */	DEADTRANS(	L'4'	,0x0101	,0x2463	,0x0000	), // CIRCLED DIGIT FOUR
/*MACRON             */	DEADTRANS(	L'5'	,0x0101	,0x2464	,0x0000	), // CIRCLED DIGIT FIVE
/*MACRON             */	DEADTRANS(	L'6'	,0x0101	,0x2465	,0x0000	), // CIRCLED DIGIT SIX
/*MACRON             */	DEADTRANS(	L'7'	,0x0101	,0x2466	,0x0000	), // CIRCLED DIGIT SEVEN
/*MACRON             */	DEADTRANS(	L'8'	,0x0101	,0x2467	,0x0000	), // CIRCLED DIGIT EIGHT
/*MACRON             */	DEADTRANS(	L'9'	,0x0101	,0x2468	,0x0000	), // CIRCLED DIGIT NINE
/*MACRON             */	DEADTRANS(	0x003A	,0x0101	,0x1E7B	,0x0001	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON             */	DEADTRANS(	0x003D	,0x0101	,0x2261	,0x0000	), // IDENTICAL TO
/*MACRON             */	DEADTRANS(	0x005B	,0x0101	,0x01ED	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*MACRON             */	DEADTRANS(	0x0060	,0x0101	,0x1E51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON             */	DEADTRANS(	0x007E	,0x0101	,0x022D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*MACRON             */	DEADTRANS(	0x00A9	,0x0101	,0x01E3	,0x0001	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	L'A'	,0x01E3	,0x01E2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	L'a'	,0x01E3	,0x01E3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*MACRON             */	DEADTRANS(	0x00B0	,0x0101	,0x246A	,0x0000	), // CIRCLED NUMBER ELEVEN
/*MACRON             */	DEADTRANS(	0x00E1	,0x0101	,0x1E53	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON             */	DEADTRANS(	0x00EB	,0x0101	,0x1E7B	,0x0001	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON             */	DEADTRANS(	0x00F2	,0x0101	,0x1E51	,0x0001	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON             */	DEADTRANS(	0x00F5	,0x0101	,0x022D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*MACRON             */	DEADTRANS(	0x022F	,0x0101	,0x0231	,0x0001	), // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
/*MACRON             */	DEADTRANS(	0x0101	,0x0101	,0x1E07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON             */	DEADTRANS(	0x01EB	,0x0101	,0x01ED	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*MACRON             */	DEADTRANS(	0x1EE5	,0x0101	,0x1E5D	,0x0001	), // LATIN SMALL LETTER R WITH DOT BELOW AND MACRON
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'E'	,0x1E53	,0x1E16	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'e'	,0x1E53	,0x1E17	,0x0000	), // LATIN SMALL LETTER E WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'O'	,0x1E53	,0x1E52	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON AND ACUTE
/*MACRON&ACUTE_ACCENT*/	DEADTRANS(	L'o'	,0x1E53	,0x1E53	,0x0000	), // LATIN SMALL LETTER O WITH MACRON AND ACUTE
/*MACRON&DIAERESIS   */	DEADTRANS(	L'U'	,0x1E7B	,0x1E7A	,0x0000	), // LATIN CAPITAL LETTER U WITH MACRON AND DIAERESIS
/*MACRON&DIAERESIS   */	DEADTRANS(	L'u'	,0x1E7B	,0x1E7B	,0x0000	), // LATIN SMALL LETTER U WITH MACRON AND DIAERESIS
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'E'	,0x1E51	,0x1E14	,0x0000	), // LATIN CAPITAL LETTER E WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'e'	,0x1E51	,0x1E15	,0x0000	), // LATIN SMALL LETTER E WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'O'	,0x1E51	,0x1E50	,0x0000	), // LATIN CAPITAL LETTER O WITH MACRON AND GRAVE
/*MACRON&GRAVE_ACCENT*/	DEADTRANS(	L'o'	,0x1E51	,0x1E51	,0x0000	), // LATIN SMALL LETTER O WITH MACRON AND GRAVE
/*MACRON_BELOW       */	DEADTRANS(	0x0020	,0x1E07	,0x0331	,0x0000	), // COMBINING MACRON BELOW
/*MACRON_BELOW       */	DEADTRANS(	0x00A0	,0x1E07	,0x005F	,0x0000	), // LOW LINE
/*MACRON_BELOW       */	DEADTRANS(	0x202F	,0x1E07	,0x02CD	,0x0000	), // MODIFIER LETTER LOW MACRON
/*MACRON_BELOW       */	DEADTRANS(	L'B'	,0x1E07	,0x1E06	,0x0000	), // LATIN CAPITAL LETTER B WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'b'	,0x1E07	,0x1E07	,0x0000	), // LATIN SMALL LETTER B WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'D'	,0x1E07	,0x1E0E	,0x0000	), // LATIN CAPITAL LETTER D WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'd'	,0x1E07	,0x1E0F	,0x0000	), // LATIN SMALL LETTER D WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'h'	,0x1E07	,0x1E96	,0x0000	), // LATIN SMALL LETTER H WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'K'	,0x1E07	,0x1E34	,0x0000	), // LATIN CAPITAL LETTER K WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'k'	,0x1E07	,0x1E35	,0x0000	), // LATIN SMALL LETTER K WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'L'	,0x1E07	,0x1E3A	,0x0000	), // LATIN CAPITAL LETTER L WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'l'	,0x1E07	,0x1E3B	,0x0000	), // LATIN SMALL LETTER L WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'N'	,0x1E07	,0x1E48	,0x0000	), // LATIN CAPITAL LETTER N WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'n'	,0x1E07	,0x1E49	,0x0000	), // LATIN SMALL LETTER N WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'R'	,0x1E07	,0x1E5E	,0x0000	), // LATIN CAPITAL LETTER R WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'r'	,0x1E07	,0x1E5F	,0x0000	), // LATIN SMALL LETTER R WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'T'	,0x1E07	,0x1E6E	,0x0000	), // LATIN CAPITAL LETTER T WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L't'	,0x1E07	,0x1E6F	,0x0000	), // LATIN SMALL LETTER T WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'Z'	,0x1E07	,0x1E94	,0x0000	), // LATIN CAPITAL LETTER Z WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	L'z'	,0x1E07	,0x1E95	,0x0000	), // LATIN SMALL LETTER Z WITH LINE BELOW
/*MACRON_BELOW       */	DEADTRANS(	0x007C	,0x1E07	,0x007C	,0x0001	), // VERTICAL LINE
/*MATHEMATICAL       */	DEADTRANS(	L'A'	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	L'a'	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	L'B'	,0x2133	,0x212C	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	L'b'	,0x2133	,0x212C	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	L'C'	,0x2133	,0x212F	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	L'c'	,0x2133	,0x212F	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	L'D'	,0x2133	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MATHEMATICAL       */	DEADTRANS(	L'd'	,0x2133	,0x2131	,0x0001	), // SCRIPT CAPITAL F
/*MATHEMATICAL       */	DEADTRANS(	L'F'	,0x2133	,0x212D	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'f'	,0x2133	,0x212D	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'G'	,0x2133	,0x210A	,0x0001	), // SCRIPT SMALL G
/*MATHEMATICAL       */	DEADTRANS(	L'g'	,0x2133	,0x210A	,0x0001	), // SCRIPT SMALL G
/*MATHEMATICAL       */	DEADTRANS(	L'H'	,0x2133	,0x211C	,0x0001	), // BLACK-LETTER CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'h'	,0x2133	,0x211C	,0x0001	), // BLACK-LETTER CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'I'	,0x2133	,0x210E	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	L'i'	,0x2133	,0x210E	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	L'J'	,0x2133	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*MATHEMATICAL       */	DEADTRANS(	L'j'	,0x2133	,0x2110	,0x0001	), // SCRIPT CAPITAL I
/*MATHEMATICAL       */	DEADTRANS(	L'M'	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'm'	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	L'S'	,0x2133	,0x210B	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	L's'	,0x2133	,0x210B	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	L'T'	,0x2133	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*MATHEMATICAL       */	DEADTRANS(	L't'	,0x2133	,0x2112	,0x0001	), // SCRIPT CAPITAL L
/*MATHEMATICAL       */	DEADTRANS(	L'U'	,0x2133	,0x211B	,0x0001	), // SCRIPT CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'u'	,0x2133	,0x211B	,0x0001	), // SCRIPT CAPITAL R
/*MATHEMATICAL       */	DEADTRANS(	L'V'	,0x2133	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*MATHEMATICAL       */	DEADTRANS(	L'v'	,0x2133	,0x2130	,0x0001	), // SCRIPT CAPITAL E
/*MATHEMATICAL       */	DEADTRANS(	0x0023	,0x2133	,0x2115	,0x0001	), // DOUBLE-STRUCK CAPITAL N
/*MATHEMATICAL       */	DEADTRANS(	0x0024	,0x2133	,0x210B	,0x0001	), // SCRIPT CAPITAL H
/*MATHEMATICAL       */	DEADTRANS(	0x0025	,0x2133	,0x212D	,0x0001	), // BLACK-LETTER CAPITAL C
/*MATHEMATICAL       */	DEADTRANS(	0x0026	,0x2133	,0x212F	,0x0001	), // SCRIPT SMALL E
/*MATHEMATICAL       */	DEADTRANS(	0x002A	,0x2133	,0x212C	,0x0001	), // SCRIPT CAPITAL B
/*MATHEMATICAL       */	DEADTRANS(	0x002F	,0x2133	,0x210E	,0x0001	), // PLANCK CONSTANT
/*MATHEMATICAL       */	DEADTRANS(	0x003D	,0x2133	,0x2102	,0x0001	), // DOUBLE-STRUCK CAPITAL C
/*OGONEK&MACRON      */	DEADTRANS(	L'O'	,0x01ED	,0x01EC	,0x0000	), // LATIN CAPITAL LETTER O WITH OGONEK AND MACRON
/*OGONEK&MACRON      */	DEADTRANS(	L'o'	,0x01ED	,0x01ED	,0x0000	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*OGONEK/CROOK       */	DEADTRANS(	0x0020	,0x01EB	,0x0328	,0x0000	), // COMBINING OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	0x00A0	,0x01EB	,0x02DB	,0x0000	), // OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	0x202F	,0x01EB	,0x02DB	,0x0000	), // OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'A'	,0x01EB	,0x0104	,0x0000	), // LATIN CAPITAL LETTER A WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'a'	,0x01EB	,0x0105	,0x0000	), // LATIN SMALL LETTER A WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'B'	,0x01EB	,0x0181	,0x0000	), // LATIN CAPITAL LETTER B WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'b'	,0x01EB	,0x0253	,0x0000	), // LATIN SMALL LETTER B WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'C'	,0x01EB	,0x0187	,0x0000	), // LATIN CAPITAL LETTER C WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'c'	,0x01EB	,0x0188	,0x0000	), // LATIN SMALL LETTER C WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'D'	,0x01EB	,0x018A	,0x0000	), // LATIN CAPITAL LETTER D WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'd'	,0x01EB	,0x0257	,0x0000	), // LATIN SMALL LETTER D WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'E'	,0x01EB	,0x0118	,0x0000	), // LATIN CAPITAL LETTER E WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x01EB	,0x0119	,0x0000	), // LATIN SMALL LETTER E WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'F'	,0x01EB	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'f'	,0x01EB	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'G'	,0x01EB	,0x0193	,0x0000	), // LATIN CAPITAL LETTER G WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'g'	,0x01EB	,0x0260	,0x0000	), // LATIN SMALL LETTER G WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'H'	,0x01EB	,0xA7AA	,0x0000	), // LATIN CAPITAL LETTER H WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'h'	,0x01EB	,0x0266	,0x0000	), // LATIN SMALL LETTER H WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'I'	,0x01EB	,0x012E	,0x0000	), // LATIN CAPITAL LETTER I WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'i'	,0x01EB	,0x012F	,0x0000	), // LATIN SMALL LETTER I WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'K'	,0x01EB	,0x0198	,0x0000	), // LATIN CAPITAL LETTER K WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'k'	,0x01EB	,0x0199	,0x0000	), // LATIN SMALL LETTER K WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'O'	,0x01EB	,0x01EA	,0x0000	), // LATIN CAPITAL LETTER O WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'o'	,0x01EB	,0x01EB	,0x0000	), // LATIN SMALL LETTER O WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'P'	,0x01EB	,0x01A4	,0x0000	), // LATIN CAPITAL LETTER P WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'p'	,0x01EB	,0x01A5	,0x0000	), // LATIN SMALL LETTER P WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'q'	,0x01EB	,0x02A0	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'r'	,0x01EB	,0x027E	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'T'	,0x01EB	,0x01AC	,0x0000	), // LATIN CAPITAL LETTER T WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L't'	,0x01EB	,0x01AD	,0x0000	), // LATIN SMALL LETTER T WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'U'	,0x01EB	,0x0172	,0x0000	), // LATIN CAPITAL LETTER U WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'u'	,0x01EB	,0x0173	,0x0000	), // LATIN SMALL LETTER U WITH OGONEK
/*OGONEK/CROOK       */	DEADTRANS(	L'V'	,0x01EB	,0x01B2	,0x0000	), // LATIN CAPITAL LETTER V WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'v'	,0x01EB	,0x028B	,0x0000	), // LATIN SMALL LETTER V WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'W'	,0x01EB	,0x2C72	,0x0000	), // LATIN CAPITAL LETTER W WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'w'	,0x01EB	,0x2C73	,0x0000	), // LATIN SMALL LETTER W WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'Y'	,0x01EB	,0x01B3	,0x0000	), // LATIN CAPITAL LETTER Y WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'y'	,0x01EB	,0x01B4	,0x0000	), // LATIN SMALL LETTER Y WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'Z'	,0x01EB	,0x0224	,0x0000	), // LATIN CAPITAL LETTER Z WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'z'	,0x01EB	,0x0225	,0x0000	), // LATIN SMALL LETTER Z WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	0x005B	,0x01EB	,0x02AD	,0x0000	), // LATIN LETTER BIDENTAL PERCUSSIVE
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x02AD	,0x029A	,0x0000	), // LATIN SMALL LETTER CLOSED OPEN E
/*OGONEK/CROOK       */	DEADTRANS(	L'o'	,0x02AD	,0x0277	,0x0000	), // LATIN SMALL LETTER CLOSED OMEGA
/*OGONEK/CROOK       */	DEADTRANS(	0x005C	,0x02AD	,0x025E	,0x0000	), // LATIN SMALL LETTER CLOSED REVERSED OPEN E
/*OGONEK/CROOK       */	DEADTRANS(	0x005F	,0x01EB	,0x01ED	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*OGONEK/CROOK       */	DEADTRANS(	0x007B	,0x01EB	,0x1D91	,0x0000	), // LATIN SMALL LETTER D WITH HOOK AND TAIL
/*OGONEK/CROOK       */	DEADTRANS(	0x007E	,0x01EB	,0x1D73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*OGONEK/CROOK       */	DEADTRANS(	0x00A9	,0x01EB	,0x025A	,0x0001	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	L'e'	,0x025A	,0x025A	,0x0000	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*OGONEK/CROOK       */	DEADTRANS(	0x00F5	,0x01EB	,0x1D73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*OGONEK/CROOK       */	DEADTRANS(	0x014D	,0x01EB	,0x01ED	,0x0001	), // LATIN SMALL LETTER O WITH OGONEK AND MACRON
/*PALATAL_HOOK       */	DEADTRANS(	L'B'	,0x0192	,0xA796	,0x0000	), // LATIN CAPITAL LETTER B WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'b'	,0x0192	,0xA797	,0x0000	), // LATIN SMALL LETTER B WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'e'	,0x0192	,0xAB34	,0x0000	), // LATIN SMALL LETTER E WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'F'	,0x0192	,0x0191	,0x0000	), // LATIN CAPITAL LETTER F WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'f'	,0x0192	,0x0192	,0x0000	), // LATIN SMALL LETTER F WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'M'	,0x0192	,0x2C6E	,0x0000	), // LATIN CAPITAL LETTER M WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'm'	,0x0192	,0x0271	,0x0000	), // LATIN SMALL LETTER M WITH HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'N'	,0x0192	,0x019D	,0x0000	), // LATIN CAPITAL LETTER N WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'n'	,0x0192	,0x0272	,0x0000	), // LATIN SMALL LETTER N WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'P'	,0x0192	,0xA752	,0x0000	), // LATIN CAPITAL LETTER P WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'p'	,0x0192	,0xA753	,0x0000	), // LATIN SMALL LETTER P WITH FLOURISH
/*PALATAL_HOOK       */	DEADTRANS(	L'Q'	,0x0192	,0x024A	,0x0000	), // LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'q'	,0x0192	,0x024B	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'S'	,0x0192	,0x2C7E	,0x0000	), // LATIN CAPITAL LETTER S WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L's'	,0x0192	,0x023F	,0x0000	), // LATIN SMALL LETTER S WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'u'	,0x0192	,0xAB52	,0x0000	), // LATIN SMALL LETTER U WITH LEFT HOOK
/*PALATAL_HOOK       */	DEADTRANS(	L'Z'	,0x0192	,0x2C7F	,0x0000	), // LATIN CAPITAL LETTER Z WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'z'	,0x0192	,0x0240	,0x0000	), // LATIN SMALL LETTER Z WITH SWASH TAIL
/*PALATAL_HOOK       */	DEADTRANS(	0x007D	,0x0192	,0xA755	,0x0001	), // LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'P'	,0xA755	,0xA754	,0x0000	), // LATIN CAPITAL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	L'p'	,0xA755	,0xA755	,0x0000	), // LATIN SMALL LETTER P WITH SQUIRREL TAIL
/*PALATAL_HOOK       */	DEADTRANS(	0x00A9	,0x0192	,0x01BA	,0x0000	), // LATIN SMALL LETTER EZH WITH TAIL
/*PARENTHESIZED      */	DEADTRANS(	L'a'	,0x24AA	,0x249C	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER A
/*PARENTHESIZED      */	DEADTRANS(	L'b'	,0x24AA	,0x249D	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER B
/*PARENTHESIZED      */	DEADTRANS(	L'c'	,0x24AA	,0x249E	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER C
/*PARENTHESIZED      */	DEADTRANS(	L'd'	,0x24AA	,0x249F	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER D
/*PARENTHESIZED      */	DEADTRANS(	L'e'	,0x24AA	,0x24A0	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER E
/*PARENTHESIZED      */	DEADTRANS(	L'f'	,0x24AA	,0x24A1	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER F
/*PARENTHESIZED      */	DEADTRANS(	L'g'	,0x24AA	,0x24A2	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER G
/*PARENTHESIZED      */	DEADTRANS(	L'h'	,0x24AA	,0x24A3	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER H
/*PARENTHESIZED      */	DEADTRANS(	L'i'	,0x24AA	,0x24A4	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER I
/*PARENTHESIZED      */	DEADTRANS(	L'j'	,0x24AA	,0x24A5	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER J
/*PARENTHESIZED      */	DEADTRANS(	L'k'	,0x24AA	,0x24A6	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER K
/*PARENTHESIZED      */	DEADTRANS(	L'l'	,0x24AA	,0x24A7	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER L
/*PARENTHESIZED      */	DEADTRANS(	L'm'	,0x24AA	,0x24A8	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER M
/*PARENTHESIZED      */	DEADTRANS(	L'n'	,0x24AA	,0x24A9	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER N
/*PARENTHESIZED      */	DEADTRANS(	L'o'	,0x24AA	,0x24AA	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER O
/*PARENTHESIZED      */	DEADTRANS(	L'p'	,0x24AA	,0x24AB	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER P
/*PARENTHESIZED      */	DEADTRANS(	L'q'	,0x24AA	,0x24AC	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Q
/*PARENTHESIZED      */	DEADTRANS(	L'r'	,0x24AA	,0x24AD	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER R
/*PARENTHESIZED      */	DEADTRANS(	L's'	,0x24AA	,0x24AE	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER S
/*PARENTHESIZED      */	DEADTRANS(	L't'	,0x24AA	,0x24AF	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER T
/*PARENTHESIZED      */	DEADTRANS(	L'u'	,0x24AA	,0x24B0	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER U
/*PARENTHESIZED      */	DEADTRANS(	L'v'	,0x24AA	,0x24B1	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER V
/*PARENTHESIZED      */	DEADTRANS(	L'w'	,0x24AA	,0x24B2	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER W
/*PARENTHESIZED      */	DEADTRANS(	L'x'	,0x24AA	,0x24B3	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER X
/*PARENTHESIZED      */	DEADTRANS(	L'y'	,0x24AA	,0x24B4	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Y
/*PARENTHESIZED      */	DEADTRANS(	L'z'	,0x24AA	,0x24B5	,0x0000	), // PARENTHESIZED LATIN SMALL LETTER Z
/*PARENTHESIZED      */	DEADTRANS(	L'1'	,0x24AA	,0x2474	,0x0001	), // PARENTHESIZED DIGIT ONE
/*PARENTHESIZED      */	DEADTRANS(	L'2'	,0x24AA	,0x2475	,0x0001	), // PARENTHESIZED DIGIT TWO
/*PARENTHESIZED      */	DEADTRANS(	L'3'	,0x24AA	,0x2476	,0x0000	), // PARENTHESIZED DIGIT THREE
/*PARENTHESIZED      */	DEADTRANS(	L'4'	,0x24AA	,0x2477	,0x0000	), // PARENTHESIZED DIGIT FOUR
/*PARENTHESIZED      */	DEADTRANS(	L'5'	,0x24AA	,0x2478	,0x0000	), // PARENTHESIZED DIGIT FIVE
/*PARENTHESIZED      */	DEADTRANS(	L'6'	,0x24AA	,0x2479	,0x0000	), // PARENTHESIZED DIGIT SIX
/*PARENTHESIZED      */	DEADTRANS(	L'7'	,0x24AA	,0x247A	,0x0000	), // PARENTHESIZED DIGIT SEVEN
/*PARENTHESIZED      */	DEADTRANS(	L'8'	,0x24AA	,0x247B	,0x0000	), // PARENTHESIZED DIGIT EIGHT
/*PARENTHESIZED      */	DEADTRANS(	L'9'	,0x24AA	,0x247C	,0x0000	), // PARENTHESIZED DIGIT NINE
/*PARENTHESIZED_1#   */	DEADTRANS(	L'0'	,0x2474	,0x247D	,0x0000	), // PARENTHESIZED NUMBER TEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'1'	,0x2474	,0x247E	,0x0000	), // PARENTHESIZED NUMBER ELEVEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'2'	,0x2474	,0x247F	,0x0000	), // PARENTHESIZED NUMBER TWELVE
/*PARENTHESIZED_1#   */	DEADTRANS(	L'3'	,0x2474	,0x2480	,0x0000	), // PARENTHESIZED NUMBER THIRTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'4'	,0x2474	,0x2481	,0x0000	), // PARENTHESIZED NUMBER FOURTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'5'	,0x2474	,0x2482	,0x0000	), // PARENTHESIZED NUMBER FIFTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'6'	,0x2474	,0x2483	,0x0000	), // PARENTHESIZED NUMBER SIXTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'7'	,0x2474	,0x2484	,0x0000	), // PARENTHESIZED NUMBER SEVENTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'8'	,0x2474	,0x2485	,0x0000	), // PARENTHESIZED NUMBER EIGHTEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	L'9'	,0x2474	,0x2486	,0x0000	), // PARENTHESIZED NUMBER NINETEEN
/*PARENTHESIZED_1#   */	DEADTRANS(	0x0029	,0x2474	,0x2474	,0x0000	), // PARENTHESIZED DIGIT ONE
/*PARENTHESIZED_2#   */	DEADTRANS(	L'0'	,0x2475	,0x2487	,0x0000	), // PARENTHESIZED NUMBER TWENTY
/*PARENTHESIZED_2#   */	DEADTRANS(	0x0029	,0x2475	,0x2475	,0x0000	), // PARENTHESIZED DIGIT TWO
/*RECOMPOSE          */	DEADTRANS(	0x00E9	,0x00AE	,0x1DEF	,0x0001	), // COMBINING LATIN SMALL LETTER ESH
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1DEF	,0x1DEF	,0x0000	), // COMBINING LATIN SMALL LETTER ESH
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x1DEF	,0x1DD9	,0x0000	), // COMBINING LATIN SMALL LETTER ETH
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x1DEF	,0x1DEA	,0x0000	), // COMBINING LATIN SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x1DEF	,0x1DE5	,0x0000	), // COMBINING LATIN SMALL LETTER LONG S
/*RECOMPOSE          */	DEADTRANS(	L'w'	,0x1DEF	,0x035B	,0x0000	), // COMBINING ZIGZAG ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'x'	,0x1DEF	,0x033D	,0x0000	), // COMBINING X ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1DEF	,0x035B	,0x0000	), // COMBINING ZIGZAG ABOVE
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x00AE	,0x02A4	,0x0000	), // LATIN SMALL LETTER DEZH DIGRAPH
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x00AE	,0xAB4D	,0x0000	), // LATIN SMALL LETTER BASELINE ESH
/*RECOMPOSE          */	DEADTRANS(	0x00A7	,0x00AE	,0xAB51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*RECOMPOSE          */	DEADTRANS(	0x0024	,0x00AE	,0x00A4	,0x0001	), // CURRENCY SIGN
/*RECOMPOSE          */	DEADTRANS(	0x0026	,0x00AE	,0x2113	,0x0001	), // SCRIPT SMALL L
/*RECOMPOSE          */	DEADTRANS(	0x002D	,0x00AE	,0x0284	,0x0001	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x0284	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x0284	,0x1E9D	,0x0000	), // LATIN SMALL LETTER LONG S WITH HIGH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'T'	,0x0284	,0xA764	,0x0000	), // LATIN CAPITAL LETTER THORN WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L't'	,0x0284	,0xA765	,0x0000	), // LATIN SMALL LETTER THORN WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	0x002F	,0x00AE	,0x1E9C	,0x0001	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*RECOMPOSE          */	DEADTRANS(	0x00A6	,0x00AE	,0x00A6	,0x0001	), // BROKEN BAR
/*RECOMPOSE          */	DEADTRANS(	0x003C	,0x00AE	,0x01EF	,0x0001	), // LATIN SMALL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'D'	,0x01EF	,0x01C4	,0x0001	), // LATIN CAPITAL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x01C4	,0x01C4	,0x0000	), // LATIN CAPITAL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x01C4	,0x01C5	,0x0000	), // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x01EF	,0x01C6	,0x0000	), // LATIN SMALL LETTER DZ WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x01EF	,0x01EE	,0x0000	), // LATIN CAPITAL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x01EF	,0x01EF	,0x0000	), // LATIN SMALL LETTER EZH WITH CARON
/*RECOMPOSE          */	DEADTRANS(	0x005B	,0x00AE	,0x0267	,0x0001	), // LATIN SMALL LETTER HENG WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x0267	,0x025A	,0x0000	), // LATIN SMALL LETTER SCHWA WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'h'	,0x0267	,0x0267	,0x0000	), // LATIN SMALL LETTER HENG WITH HOOK
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x0267	,0xA762	,0x0000	), // LATIN CAPITAL LETTER VISIGOTHIC Z
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x0267	,0xA763	,0x0000	), // LATIN SMALL LETTER VISIGOTHIC Z
/*RECOMPOSE          */	DEADTRANS(	0x005D	,0x00AE	,0x1D8B	,0x0000	), // LATIN SMALL LETTER ESH WITH PALATAL HOOK
/*RECOMPOSE          */	DEADTRANS(	0x005E	,0x00AE	,0x1D9E	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	0x005F	,0x00AE	,0x01E2	,0x0001	), // LATIN CAPITAL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	L'A'	,0x01E2	,0x01E2	,0x0000	), // LATIN CAPITAL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	L'a'	,0x01E2	,0x01E3	,0x0000	), // LATIN SMALL LETTER AE WITH MACRON
/*RECOMPOSE          */	DEADTRANS(	0x0060	,0x00AE	,0x00A4	,0x0001	), // CURRENCY SIGN
/*RECOMPOSE          */	DEADTRANS(	0x007B	,0x00AE	,0x1D98	,0x0001	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1D98	,0x1D98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x1D98	,0x1D95	,0x0000	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L's'	,0x1D98	,0x1D98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1D98	,0x1D9A	,0x0000	), // LATIN SMALL LETTER EZH WITH RETROFLEX HOOK
/*RECOMPOSE          */	DEADTRANS(	0x00B0	,0x00AE	,0xA75C	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	L'R'	,0xA75C	,0xA75C	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	L'r'	,0xA75C	,0xA75D	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RECOMPOSE          */	DEADTRANS(	0x00EA	,0x00AE	,0x1D9E	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1D9E	,0x1D9D	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*RECOMPOSE          */	DEADTRANS(	L'd'	,0x1D9E	,0x1D9E	,0x0000	), // MODIFIER LETTER SMALL ETH
/*RECOMPOSE          */	DEADTRANS(	0x0259	,0x1D9E	,0x1D4A	,0x0000	), // MODIFIER LETTER SMALL SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'h'	,0x1D9E	,0xAB5C	,0x0000	), // MODIFIER LETTER SMALL HENG
/*RECOMPOSE          */	DEADTRANS(	L'j'	,0x1D9E	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	0x014B	,0x1D9E	,0x1D51	,0x0000	), // MODIFIER LETTER SMALL ENG
/*RECOMPOSE          */	DEADTRANS(	L'O'	,0x1D9E	,0x1D3D	,0x0000	), // MODIFIER LETTER CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'o'	,0x1D9E	,0x1D54	,0x0001	), // MODIFIER LETTER SMALL TOP HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0028	,0x1D54	,0x1D54	,0x0000	), // MODIFIER LETTER SMALL TOP HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0029	,0x1D54	,0x1D55	,0x0000	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*RECOMPOSE          */	DEADTRANS(	0x0283	,0x1D9E	,0x1DB4	,0x0000	), // MODIFIER LETTER SMALL ESH
/*RECOMPOSE          */	DEADTRANS(	0x0292	,0x1D9E	,0x1DBE	,0x0000	), // MODIFIER LETTER SMALL EZH
/*RECOMPOSE          */	DEADTRANS(	0x0153	,0x1D9E	,0x1DA8	,0x0001	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	L'c'	,0x1DA8	,0x1D9D	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*RECOMPOSE          */	DEADTRANS(	L'j'	,0x1DA8	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x1DA8	,0x1DBD	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*RECOMPOSE          */	DEADTRANS(	0x0153	,0x1DA8	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*RECOMPOSE          */	DEADTRANS(	0x0026	,0x1D9E	,0x1DBD	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*RECOMPOSE          */	DEADTRANS(	0x002D	,0x1D9E	,0x1D2F	,0x0000	), // MODIFIER LETTER CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	0x00A9	,0x2193	,0x2094	,0x0001	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'A'	,0x2094	,0x1D01	,0x0000	), // LATIN LETTER SMALL CAPITAL AE
/*RECOMPOSE          */	DEADTRANS(	L'e'	,0x2094	,0x2094	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*RECOMPOSE          */	DEADTRANS(	L'O'	,0x2094	,0x1D15	,0x0001	), // LATIN LETTER SMALL CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'E'	,0x1D15	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*RECOMPOSE          */	DEADTRANS(	L'U'	,0x1D15	,0x1D15	,0x0000	), // LATIN LETTER SMALL CAPITAL OU
/*RECOMPOSE          */	DEADTRANS(	L'R'	,0x2094	,0xA776	,0x0000	), // LATIN LETTER SMALL CAPITAL RUM
/*RECOMPOSE          */	DEADTRANS(	L'Z'	,0x2094	,0x1D23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*RECOMPOSE          */	DEADTRANS(	L'z'	,0x2094	,0x1D23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*RECOMPOSE          */	DEADTRANS(	0x002D	,0x2094	,0x1D03	,0x0001	), // LATIN LETTER SMALL CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	L'B'	,0x1D03	,0x1D03	,0x0000	), // LATIN LETTER SMALL CAPITAL BARRED B
/*RECOMPOSE          */	DEADTRANS(	L'I'	,0x1D03	,0x1D7B	,0x0000	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'L'	,0x1D03	,0x1D0C	,0x0000	), // LATIN LETTER SMALL CAPITAL L WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	L'U'	,0x1D03	,0x1D7E	,0x0000	), // LATIN SMALL CAPITAL LETTER U WITH STROKE
/*RECOMPOSE          */	DEADTRANS(	0x2191	,0x00AE	,0x1D9E	,0x0001	), // MODIFIER LETTER SMALL ETH
/*RETROFLEX_HOOK     */	DEADTRANS(	0x0020	,0x0273	,0x0322	,0x0000	), // COMBINING RETROFLEX HOOK BELOW
/*RETROFLEX_HOOK     */	DEADTRANS(	L'a'	,0x0273	,0x1D8F	,0x0000	), // LATIN SMALL LETTER A WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'D'	,0x0273	,0x0189	,0x0000	), // LATIN CAPITAL LETTER AFRICAN D
/*RETROFLEX_HOOK     */	DEADTRANS(	L'd'	,0x0273	,0x0256	,0x0000	), // LATIN SMALL LETTER D WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x0273	,0x1D92	,0x0000	), // LATIN SMALL LETTER E WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'i'	,0x0273	,0x1D96	,0x0000	), // LATIN SMALL LETTER I WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'l'	,0x0273	,0x026D	,0x0000	), // LATIN SMALL LETTER L WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'n'	,0x0273	,0x0273	,0x0000	), // LATIN SMALL LETTER N WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'Q'	,0x0273	,0x024A	,0x0000	), // LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'q'	,0x0273	,0x024B	,0x0000	), // LATIN SMALL LETTER Q WITH HOOK TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'R'	,0x0273	,0x2C64	,0x0000	), // LATIN CAPITAL LETTER R WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L'r'	,0x0273	,0x027D	,0x0000	), // LATIN SMALL LETTER R WITH TAIL
/*RETROFLEX_HOOK     */	DEADTRANS(	L's'	,0x0273	,0x0282	,0x0000	), // LATIN SMALL LETTER S WITH HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'T'	,0x0273	,0x01AE	,0x0000	), // LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L't'	,0x0273	,0x0288	,0x0000	), // LATIN SMALL LETTER T WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'u'	,0x0273	,0x1D99	,0x0000	), // LATIN SMALL LETTER U WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'v'	,0x0273	,0x2C71	,0x0000	), // LATIN SMALL LETTER V WITH RIGHT HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'z'	,0x0273	,0x0290	,0x0000	), // LATIN SMALL LETTER Z WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00F9	,0x0273	,0x0282	,0x0001	), // LATIN SMALL LETTER S WITH HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'a'	,0x0282	,0x1D90	,0x0000	), // LATIN SMALL LETTER ALPHA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x0282	,0x1D93	,0x0000	), // LATIN SMALL LETTER OPEN E WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x0024	,0x0273	,0xA78E	,0x0000	), // LATIN SMALL LETTER L WITH RETROFLEX HOOK AND BELT
/*RETROFLEX_HOOK     */	DEADTRANS(	0x005C	,0x0273	,0x0285	,0x0000	), // LATIN SMALL LETTER SQUAT REVERSED ESH
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00A9	,0x1D97	,0x1D95	,0x0001	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'c'	,0x1D95	,0x1D98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'e'	,0x1D95	,0x1D95	,0x0000	), // LATIN SMALL LETTER SCHWA WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L's'	,0x1D95	,0x1D98	,0x0000	), // LATIN SMALL LETTER ESH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'z'	,0x1D95	,0x1D9A	,0x0000	), // LATIN SMALL LETTER EZH WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	0x00A7	,0x0273	,0x1D97	,0x0001	), // LATIN SMALL LETTER OPEN O WITH RETROFLEX HOOK
/*RETROFLEX_HOOK     */	DEADTRANS(	L'c'	,0x1D97	,0x1D97	,0x0000	), // LATIN SMALL LETTER OPEN O WITH RETROFLEX HOOK
/*REVERSED           */	DEADTRANS(	L'C'	,0x1D19	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*REVERSED           */	DEADTRANS(	L'c'	,0x1D19	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*REVERSED           */	DEADTRANS(	L'E'	,0x1D19	,0x018E	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*REVERSED           */	DEADTRANS(	L'e'	,0x1D19	,0x0258	,0x0000	), // LATIN SMALL LETTER REVERSED E
/*REVERSED           */	DEADTRANS(	L'F'	,0x1D19	,0xA7FB	,0x0000	), // LATIN EPIGRAPHIC LETTER REVERSED F
/*REVERSED           */	DEADTRANS(	L'o'	,0x1D19	,0xAB43	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O
/*REVERSED           */	DEADTRANS(	L'P'	,0x1D19	,0xA7FC	,0x0000	), // LATIN EPIGRAPHIC LETTER REVERSED P
/*REVERSED           */	DEADTRANS(	L'S'	,0x1D19	,0x01AA	,0x0000	), // LATIN LETTER REVERSED ESH LOOP
/*REVERSED           */	DEADTRANS(	L's'	,0x1D19	,0x01AA	,0x0000	), // LATIN LETTER REVERSED ESH LOOP
/*REVERSED           */	DEADTRANS(	L'Z'	,0x1D19	,0x01B8	,0x0000	), // LATIN CAPITAL LETTER EZH REVERSED
/*REVERSED           */	DEADTRANS(	L'z'	,0x1D19	,0x01B9	,0x0000	), // LATIN SMALL LETTER EZH REVERSED
/*REVERSED           */	DEADTRANS(	0x00F9	,0x1D19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*REVERSED           */	DEADTRANS(	0x0027	,0x1D19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*REVERSED           */	DEADTRANS(	0x002D	,0x1D19	,0x02A2	,0x0000	), // LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*REVERSED           */	DEADTRANS(	0x002E	,0x1D19	,0xA73F	,0x0001	), // LATIN SMALL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	L'C'	,0xA73F	,0xA73E	,0x0000	), // LATIN CAPITAL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	L'c'	,0xA73F	,0xA73F	,0x0000	), // LATIN SMALL LETTER REVERSED C WITH DOT
/*REVERSED           */	DEADTRANS(	0x003B	,0x1D19	,0x204F	,0x0000	), // REVERSED SEMICOLON
/*REVERSED           */	DEADTRANS(	0x005B	,0x1D19	,0x027F	,0x0000	), // LATIN SMALL LETTER REVERSED R WITH FISHHOOK
/*REVERSED           */	DEADTRANS(	0x005D	,0x1D19	,0x025D	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E WITH HOOK
/*REVERSED           */	DEADTRANS(	0x007B	,0x1D19	,0x1D94	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E WITH RETROFLEX HOOK
/*REVERSED           */	DEADTRANS(	0x007C	,0x1D19	,0x204B	,0x0000	), // REVERSED PILCROW SIGN
/*REVERSED           */	DEADTRANS(	0x00B5	,0x1D19	,0x025C	,0x0001	), // LATIN SMALL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	L'E'	,0x025C	,0xA7AB	,0x0000	), // LATIN CAPITAL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	L'e'	,0x025C	,0x025C	,0x0000	), // LATIN SMALL LETTER REVERSED OPEN E
/*REVERSED           */	DEADTRANS(	0x2019	,0x1D19	,0x0295	,0x0000	), // LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*RING_ABOVE         */	DEADTRANS(	0x0020	,0x00E5	,0x030A	,0x0000	), // COMBINING RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x00EB	,0x00E5	,0x1AB1	,0x0000	), // COMBINING DIAERESIS-RING
/*RING_ABOVE         */	DEADTRANS(	0x00A0	,0x00E5	,0x02DA	,0x0000	), // RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x202F	,0x00E5	,0x02DA	,0x0000	), // RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'A'	,0x00E5	,0x00C5	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'a'	,0x00E5	,0x00E5	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'C'	,0x00E5	,0x2103	,0x0000	), // DEGREE CELSIUS
/*RING_ABOVE         */	DEADTRANS(	L'c'	,0x00E5	,0x2103	,0x0000	), // DEGREE CELSIUS
/*RING_ABOVE         */	DEADTRANS(	L'F'	,0x00E5	,0x2109	,0x0000	), // DEGREE FAHRENHEIT
/*RING_ABOVE         */	DEADTRANS(	L'f'	,0x00E5	,0x2109	,0x0000	), // DEGREE FAHRENHEIT
/*RING_ABOVE         */	DEADTRANS(	L'l'	,0x00E5	,0xAB39	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE RING
/*RING_ABOVE         */	DEADTRANS(	L'o'	,0x00E5	,0x2C7A	,0x0000	), // LATIN SMALL LETTER O WITH LOW RING INSIDE
/*RING_ABOVE         */	DEADTRANS(	L'R'	,0x00E5	,0xA75A	,0x0000	), // LATIN CAPITAL LETTER R ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'r'	,0x00E5	,0xA75B	,0x0000	), // LATIN SMALL LETTER R ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'U'	,0x00E5	,0x016E	,0x0000	), // LATIN CAPITAL LETTER U WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'u'	,0x00E5	,0x016F	,0x0000	), // LATIN SMALL LETTER U WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'V'	,0x00E5	,0x1EFC	,0x0000	), // LATIN CAPITAL LETTER MIDDLE-WELSH V
/*RING_ABOVE         */	DEADTRANS(	L'v'	,0x00E5	,0x1EFD	,0x0000	), // LATIN SMALL LETTER MIDDLE-WELSH V
/*RING_ABOVE         */	DEADTRANS(	L'w'	,0x00E5	,0x1E98	,0x0000	), // LATIN SMALL LETTER W WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	L'x'	,0x00E5	,0xAB56	,0x0000	), // LATIN SMALL LETTER X WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	L'y'	,0x00E5	,0x1E99	,0x0000	), // LATIN SMALL LETTER Y WITH RING ABOVE
/*RING_ABOVE         */	DEADTRANS(	0x00F9	,0x00E5	,0xAB54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	0x0026	,0x00E5	,0xAB4C	,0x0000	), // LATIN SMALL LETTER SCRIPT R WITH RING
/*RING_ABOVE         */	DEADTRANS(	0x0027	,0x00E5	,0x01FB	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE         */	DEADTRANS(	0x00A9	,0x00E5	,0xA75D	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'R'	,0xA75D	,0xA75C	,0x0000	), // LATIN CAPITAL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	L'r'	,0xA75D	,0xA75D	,0x0000	), // LATIN SMALL LETTER RUM ROTUNDA
/*RING_ABOVE         */	DEADTRANS(	0x00B0	,0x00E5	,0x1E01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_ABOVE         */	DEADTRANS(	0x00E5	,0x00E5	,0x1E01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_ABOVE         */	DEADTRANS(	0x00B5	,0x00E5	,0xAB54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_ABOVE         */	DEADTRANS(	0x00E1	,0x00E5	,0x01FB	,0x0001	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE         */	DEADTRANS(	0x2610	,0x00E5	,0x274D	,0x0000	), // SHADOWED WHITE CIRCLE
/*RING_ABOVE&ACUTE   */	DEADTRANS(	L'A'	,0x01FB	,0x01FA	,0x0000	), // LATIN CAPITAL LETTER A WITH RING ABOVE AND ACUTE
/*RING_ABOVE&ACUTE   */	DEADTRANS(	L'a'	,0x01FB	,0x01FB	,0x0000	), // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
/*RING_BELOW         */	DEADTRANS(	0x0020	,0x1E01	,0x0325	,0x0000	), // COMBINING RING BELOW
/*RING_BELOW         */	DEADTRANS(	0x00A0	,0x1E01	,0x02F3	,0x0000	), // MODIFIER LETTER LOW RING
/*RING_BELOW         */	DEADTRANS(	0x202F	,0x1E01	,0x02F3	,0x0000	), // MODIFIER LETTER LOW RING
/*RING_BELOW         */	DEADTRANS(	L'A'	,0x1E01	,0x1E00	,0x0000	), // LATIN CAPITAL LETTER A WITH RING BELOW
/*RING_BELOW         */	DEADTRANS(	L'a'	,0x1E01	,0x1E01	,0x0000	), // LATIN SMALL LETTER A WITH RING BELOW
/*RING_BELOW         */	DEADTRANS(	L'L'	,0x1E01	,0xA7AD	,0x0000	), // LATIN CAPITAL LETTER L WITH BELT
/*RING_BELOW         */	DEADTRANS(	L'l'	,0x1E01	,0x026C	,0x0000	), // LATIN SMALL LETTER L WITH BELT
/*RING_BELOW         */	DEADTRANS(	L'X'	,0x1E01	,0xAB54	,0x0000	), // LATIN SMALL LETTER CHI WITH LOW RIGHT RING
/*RING_BELOW         */	DEADTRANS(	L'x'	,0x1E01	,0xAB56	,0x0000	), // LATIN SMALL LETTER X WITH LOW RIGHT RING
/*SCRIPT             */	DEADTRANS(	L'G'	,0x2113	,0xA7AC	,0x0000	), // LATIN CAPITAL LETTER SCRIPT G
/*SCRIPT             */	DEADTRANS(	L'g'	,0x2113	,0x0261	,0x0000	), // LATIN SMALL LETTER SCRIPT G
/*SCRIPT             */	DEADTRANS(	L'L'	,0x2113	,0x2112	,0x0000	), // SCRIPT CAPITAL L
/*SCRIPT             */	DEADTRANS(	L'l'	,0x2113	,0x2113	,0x0000	), // SCRIPT SMALL L
/*SCRIPT             */	DEADTRANS(	L'r'	,0x2113	,0xAB4B	,0x0000	), // LATIN SMALL LETTER SCRIPT R
/*SCRIPT             */	DEADTRANS(	L't'	,0x2113	,0x204A	,0x0000	), // TIRONIAN SIGN ET
/*SHORTENED          */	DEADTRANS(	L'r'	,0xAB4E	,0xAB47	,0x0000	), // LATIN SMALL LETTER R WITHOUT HANDLE
/*SHORTENED          */	DEADTRANS(	L'u'	,0xAB4E	,0xAB4E	,0x0000	), // LATIN SMALL LETTER U WITH SHORT RIGHT LEG
/*SHORTENED          */	DEADTRANS(	L'y'	,0xAB4E	,0xAB5A	,0x0000	), // LATIN SMALL LETTER Y WITH SHORT RIGHT LEG
/*SHORTENED          */	DEADTRANS(	0x0020	,0xAB4E	,0x1DD3	,0x0000	), // COMBINING LATIN SMALL LETTER FLATTENED OPEN A ABOVE
/*SHORTENED          */	DEADTRANS(	0x002D	,0xAB4E	,0xAB4F	,0x0000	), // LATIN SMALL LETTER U BAR WITH SHORT RIGHT LEG
/*SPACE/FORMAT       */	DEADTRANS(	0x0020	,0x005F	,0x2423	,0x0000	), // OPEN BOX
/*SPACE/FORMAT       */	DEADTRANS(	0x00A0	,0x005F	,0x237D	,0x0000	), // SHOULDERED OPEN BOX
/*SPACE/FORMAT       */	DEADTRANS(	0x202F	,0x005F	,0x2422	,0x0000	), // BLANK SYMBOL
/*SPACE/FORMAT       */	DEADTRANS(	L'a'	,0x005F	,0x200C	,0x0000	), // ZERO WIDTH NON-JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'b'	,0x005F	,0x034F	,0x0000	), // COMBINING GRAPHEME JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'C'	,0x005F	,0x2001	,0x0000	), // EM QUAD
/*SPACE/FORMAT       */	DEADTRANS(	L'c'	,0x005F	,0x2003	,0x0000	), // EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'D'	,0x005F	,0x2000	,0x0000	), // EN QUAD
/*SPACE/FORMAT       */	DEADTRANS(	L'd'	,0x005F	,0x2002	,0x0000	), // EN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'E'	,0x005F	,0x202A	,0x0001	), // LEFT-TO-RIGHT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	0x003C	,0x202A	,0x202B	,0x0000	), // RIGHT-TO-LEFT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	0x003E	,0x202A	,0x202A	,0x0000	), // LEFT-TO-RIGHT EMBEDDING
/*SPACE/FORMAT       */	DEADTRANS(	L'F'	,0x005F	,0x202D	,0x0001	), // LEFT-TO-RIGHT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	0x003C	,0x202D	,0x202E	,0x0000	), // RIGHT-TO-LEFT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	0x003E	,0x202D	,0x202D	,0x0000	), // LEFT-TO-RIGHT OVERRIDE
/*SPACE/FORMAT       */	DEADTRANS(	L'f'	,0x005F	,0x2009	,0x0000	), // THIN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'G'	,0x005F	,0xFEFF	,0x0000	), // ZERO WIDTH NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'g'	,0x005F	,0x2060	,0x0000	), // WORD JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'I'	,0x005F	,0x2066	,0x0001	), // LEFT-TO-RIGHT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	L'a'	,0x2066	,0x2068	,0x0000	), // FIRST STRONG ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003C	,0x2066	,0x2067	,0x0000	), // RIGHT-TO-LEFT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003D	,0x2066	,0x2069	,0x0000	), // POP DIRECTIONAL ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	0x003E	,0x2066	,0x2066	,0x0000	), // LEFT-TO-RIGHT ISOLATE
/*SPACE/FORMAT       */	DEADTRANS(	L'i'	,0x005F	,0x00A0	,0x0000	), // NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'j'	,0x005F	,0x202F	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'k'	,0x005F	,0x202F	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'l'	,0x005F	,0x200D	,0x0000	), // ZERO WIDTH JOINER
/*SPACE/FORMAT       */	DEADTRANS(	L'm'	,0x005F	,0x205F	,0x0000	), // MEDIUM MATHEMATICAL SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'p'	,0x005F	,0x2008	,0x0000	), // PUNCTUATION SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'q'	,0x005F	,0x2005	,0x0000	), // FOUR-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'S'	,0x005F	,0x3000	,0x0000	), // IDEOGRAPHIC SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L's'	,0x005F	,0x2006	,0x0000	), // SIX-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L't'	,0x005F	,0x2007	,0x0000	), // FIGURE SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'u'	,0x005F	,0x200A	,0x0000	), // HAIR SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x00C9	,0x005F	,0x202F	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x00E9	,0x005F	,0x202F	,0x0000	), // NARROW NO-BREAK SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x002F	,0x005F	,0x2028	,0x0000	), // LINE SEPARATOR
/*SPACE/FORMAT       */	DEADTRANS(	L'0'	,0x005F	,0x200B	,0x0000	), // ZERO WIDTH SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'1'	,0x005F	,0x2003	,0x0000	), // EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'2'	,0x005F	,0x2002	,0x0000	), // EN SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'3'	,0x005F	,0x2004	,0x0000	), // THREE-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'4'	,0x005F	,0x2005	,0x0000	), // FOUR-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	L'6'	,0x005F	,0x2006	,0x0000	), // SIX-PER-EM SPACE
/*SPACE/FORMAT       */	DEADTRANS(	0x003C	,0x005F	,0x200F	,0x0000	), // RIGHT-TO-LEFT MARK
/*SPACE/FORMAT       */	DEADTRANS(	0x003D	,0x005F	,0x202C	,0x0000	), // POP DIRECTIONAL FORMATTING
/*SPACE/FORMAT       */	DEADTRANS(	0x003E	,0x005F	,0x200E	,0x0000	), // LEFT-TO-RIGHT MARK
/*SPACE/FORMAT       */	DEADTRANS(	0x007C	,0x005F	,0x2029	,0x0000	), // PARAGRAPH SEPARATOR
/*STROKE&ACUTE       */	DEADTRANS(	L'O'	,0x01FF	,0x01FE	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
/*STROKE&ACUTE       */	DEADTRANS(	L'o'	,0x01FF	,0x01FF	,0x0000	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0020	,0x00F8	,0x0338	,0x0000	), // COMBINING LONG SOLIDUS OVERLAY
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'A'	,0x00F8	,0x023A	,0x0000	), // LATIN CAPITAL LETTER A WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'a'	,0x00F8	,0x2C65	,0x0000	), // LATIN SMALL LETTER A WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'C'	,0x00F8	,0x023B	,0x0000	), // LATIN CAPITAL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'c'	,0x00F8	,0x023C	,0x0000	), // LATIN SMALL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'd'	,0x00F8	,0xAB3F	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'E'	,0x00F8	,0x0246	,0x0000	), // LATIN CAPITAL LETTER E WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'e'	,0x00F8	,0x0247	,0x0000	), // LATIN SMALL LETTER E WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'F'	,0x00F8	,0xA798	,0x0000	), // LATIN CAPITAL LETTER F WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'f'	,0x00F8	,0xA799	,0x0000	), // LATIN SMALL LETTER F WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'G'	,0x00F8	,0xA7A0	,0x0000	), // LATIN CAPITAL LETTER G WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'g'	,0x00F8	,0xA7A1	,0x0000	), // LATIN SMALL LETTER G WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'K'	,0x00F8	,0xA742	,0x0000	), // LATIN CAPITAL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'k'	,0x00F8	,0xA743	,0x0000	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'L'	,0x00F8	,0x0141	,0x0000	), // LATIN CAPITAL LETTER L WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'l'	,0x00F8	,0x0142	,0x0000	), // LATIN SMALL LETTER L WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'm'	,0x00F8	,0x20A5	,0x0000	), // MILL SIGN
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'N'	,0x00F8	,0xA7A4	,0x0000	), // LATIN CAPITAL LETTER N WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'n'	,0x00F8	,0xA7A5	,0x0000	), // LATIN SMALL LETTER N WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'O'	,0x00F8	,0x00D8	,0x0000	), // LATIN CAPITAL LETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'o'	,0x00F8	,0x00F8	,0x0000	), // LATIN SMALL LETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'Q'	,0x00F8	,0xA758	,0x0000	), // LATIN CAPITAL LETTER Q WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'q'	,0x00F8	,0xA759	,0x0000	), // LATIN SMALL LETTER Q WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'R'	,0x00F8	,0xA7A6	,0x0000	), // LATIN CAPITAL LETTER R WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'r'	,0x00F8	,0xA7A7	,0x0000	), // LATIN SMALL LETTER R WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'S'	,0x00F8	,0xA7A8	,0x0000	), // LATIN CAPITAL LETTER S WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x00F8	,0xA7A9	,0x0000	), // LATIN SMALL LETTER S WITH OBLIQUE STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'T'	,0x00F8	,0x023E	,0x0000	), // LATIN CAPITAL LETTER T WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x00F8	,0x2C66	,0x0000	), // LATIN SMALL LETTER T WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'U'	,0x00F8	,0xA7B8	,0x0000	), // LATIN CAPITAL LETTER U WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'u'	,0x00F8	,0xA7B9	,0x0000	), // LATIN SMALL LETTER U WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'V'	,0x00F8	,0xA75E	,0x0000	), // LATIN CAPITAL LETTER V WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'v'	,0x00F8	,0xA75F	,0x0000	), // LATIN SMALL LETTER V WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0027	,0x00F8	,0x01FF	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x002F	,0x00F8	,0xA743	,0x0001	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'0'	,0x00F8	,0x2205	,0x0000	), // EMPTY SET
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x003A	,0x00F8	,0x2E4A	,0x0000	), // DOTTED SOLIDUS
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x003D	,0x00F8	,0x2260	,0x0000	), // NOT EQUAL TO
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x005D	,0x00F8	,0xAB3E	,0x0000	), // LATIN SMALL LETTER BLACKLETTER O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x007C	,0x00F8	,0x1E9C	,0x0001	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x1E9C	,0x1E9C	,0x0000	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x1E9C	,0x1D7A	,0x0000	), // LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00A9	,0x00F8	,0x023C	,0x0001	), // LATIN SMALL LETTER C WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L'o'	,0x023C	,0xAB3F	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L's'	,0x023C	,0x1E9C	,0x0000	), // LATIN SMALL LETTER LONG S WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	L't'	,0x023C	,0x1D7A	,0x0000	), // LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00A7	,0x00F8	,0xAB3F	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00E1	,0x00F8	,0x01FF	,0x0001	), // LATIN SMALL LETTER O WITH STROKE AND ACUTE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00F5	,0x00F8	,0x034A	,0x0000	), // COMBINING NOT TILDE ABOVE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x00F8	,0x00F8	,0xA743	,0x0001	), // LATIN SMALL LETTER K WITH DIAGONAL STROKE
/*STROKE_(DIAGONAL)  */	DEADTRANS(	0x0254	,0x00F8	,0xAB3F	,0x0000	), // LATIN SMALL LETTER OPEN O WITH STROKE
/*STROKE_SHORT       */	DEADTRANS(	0x0020	,0xA743	,0x0337	,0x0000	), // COMBINING SHORT SOLIDUS OVERLAY
/*STROKE_SHORT       */	DEADTRANS(	L'K'	,0xA743	,0xA7A2	,0x0000	), // LATIN CAPITAL LETTER K WITH OBLIQUE STROKE
/*STROKE_SHORT       */	DEADTRANS(	L'k'	,0xA743	,0xA7A3	,0x0000	), // LATIN SMALL LETTER K WITH OBLIQUE STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'A'	,0x005F	,0x1D00	,0x0000	), // LATIN LETTER SMALL CAPITAL A
/*SUBSCRIPT          */	DEADTRANS(	L'B'	,0x005F	,0x0299	,0x0000	), // LATIN LETTER SMALL CAPITAL B
/*SUBSCRIPT          */	DEADTRANS(	L'e'	,0x005F	,0x2091	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER E
/*SUBSCRIPT          */	DEADTRANS(	L'H'	,0x005F	,0x029C	,0x0000	), // LATIN LETTER SMALL CAPITAL H
/*SUBSCRIPT          */	DEADTRANS(	L'h'	,0x005F	,0x2095	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER H
/*SUBSCRIPT          */	DEADTRANS(	L'J'	,0x005F	,0x1D0A	,0x0000	), // LATIN LETTER SMALL CAPITAL J
/*SUBSCRIPT          */	DEADTRANS(	L'K'	,0x005F	,0x1D0B	,0x0000	), // LATIN LETTER SMALL CAPITAL K
/*SUBSCRIPT          */	DEADTRANS(	L'L'	,0x005F	,0x029F	,0x0000	), // LATIN LETTER SMALL CAPITAL L
/*SUBSCRIPT          */	DEADTRANS(	L'M'	,0x005F	,0x1D0D	,0x0000	), // LATIN LETTER SMALL CAPITAL M
/*SUBSCRIPT          */	DEADTRANS(	L'N'	,0x005F	,0x0274	,0x0000	), // LATIN LETTER SMALL CAPITAL N
/*SUBSCRIPT          */	DEADTRANS(	L'n'	,0x005F	,0x2099	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER N
/*SUBSCRIPT          */	DEADTRANS(	L'O'	,0x005F	,0x1D0F	,0x0000	), // LATIN LETTER SMALL CAPITAL O
/*SUBSCRIPT          */	DEADTRANS(	L'o'	,0x005F	,0x2092	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER O
/*SUBSCRIPT          */	DEADTRANS(	L'P'	,0x005F	,0x1D18	,0x0000	), // LATIN LETTER SMALL CAPITAL P
/*SUBSCRIPT          */	DEADTRANS(	L'Q'	,0x005F	,0xA7AF	,0x0000	), // LATIN LETTER SMALL CAPITAL Q
/*SUBSCRIPT          */	DEADTRANS(	L'R'	,0x005F	,0x0280	,0x0000	), // LATIN LETTER SMALL CAPITAL R
/*SUBSCRIPT          */	DEADTRANS(	L'r'	,0x005F	,0x1D63	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER R
/*SUBSCRIPT          */	DEADTRANS(	L'T'	,0x005F	,0x1D1B	,0x0000	), // LATIN LETTER SMALL CAPITAL T
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x005F	,0x1D1C	,0x0000	), // LATIN LETTER SMALL CAPITAL U
/*SUBSCRIPT          */	DEADTRANS(	L'V'	,0x005F	,0x1D20	,0x0000	), // LATIN LETTER SMALL CAPITAL V
/*SUBSCRIPT          */	DEADTRANS(	L'v'	,0x005F	,0x1D65	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER V
/*SUBSCRIPT          */	DEADTRANS(	L'W'	,0x005F	,0x1D21	,0x0000	), // LATIN LETTER SMALL CAPITAL W
/*SUBSCRIPT          */	DEADTRANS(	L'x'	,0x005F	,0x2093	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER X
/*SUBSCRIPT          */	DEADTRANS(	L'Y'	,0x005F	,0x028F	,0x0000	), // LATIN LETTER SMALL CAPITAL Y
/*SUBSCRIPT          */	DEADTRANS(	L'Z'	,0x005F	,0x1D22	,0x0000	), // LATIN LETTER SMALL CAPITAL Z
/*SUBSCRIPT          */	DEADTRANS(	0x0152	,0x005F	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	0x0153	,0x005F	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	0x0023	,0x005F	,0x203F	,0x0001	), // UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0021	,0x203F	,0xA71F	,0x0000	), // MODIFIER LETTER LOW INVERTED EXCLAMATION MARK
/*SUBSCRIPT          */	DEADTRANS(	0x0028	,0x203F	,0x2054	,0x0000	), // INVERTED UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0029	,0x203F	,0x203F	,0x0000	), // UNDERTIE
/*SUBSCRIPT          */	DEADTRANS(	0x0025	,0x005F	,0xA71F	,0x0000	), // MODIFIER LETTER LOW INVERTED EXCLAMATION MARK
/*SUBSCRIPT          */	DEADTRANS(	0x0027	,0x005F	,0x02CF	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x0028	,0x1E2B	,0x1D10	,0x0000	), // LATIN LETTER SMALL CAPITAL OPEN O
/*SUBSCRIPT          */	DEADTRANS(	0x002A	,0x005F	,0x204E	,0x0000	), // LOW ASTERISK
/*SUBSCRIPT          */	DEADTRANS(	0x002B	,0x005F	,0x208A	,0x0000	), // SUBSCRIPT PLUS SIGN
/*SUBSCRIPT          */	DEADTRANS(	0x002C	,0x005F	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x002D	,0x005F	,0xA751	,0x0001	), // LATIN SMALL LETTER P WITH STROKE THROUGH DESCENDER
/*SUBSCRIPT          */	DEADTRANS(	0x2190	,0x005F	,0x02FF	,0x0000	), // MODIFIER LETTER LOW LEFT ARROW
/*SUBSCRIPT          */	DEADTRANS(	0x002E	,0x005F	,0x1ECD	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUBSCRIPT          */	DEADTRANS(	L'5'	,0x005F	,0x2085	,0x0000	), // SUBSCRIPT FIVE
/*SUBSCRIPT          */	DEADTRANS(	L'7'	,0x005F	,0x2087	,0x0000	), // SUBSCRIPT SEVEN
/*SUBSCRIPT          */	DEADTRANS(	L'8'	,0x005F	,0x2088	,0x0000	), // SUBSCRIPT EIGHT
/*SUBSCRIPT          */	DEADTRANS(	L'9'	,0x005F	,0x2089	,0x0000	), // SUBSCRIPT NINE
/*SUBSCRIPT          */	DEADTRANS(	0x003A	,0x005F	,0x1E73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x005B	,0x005F	,0x029B	,0x0000	), // LATIN LETTER SMALL CAPITAL G WITH HOOK
/*SUBSCRIPT          */	DEADTRANS(	0x005C	,0x005F	,0x1D0E	,0x0000	), // LATIN LETTER SMALL CAPITAL REVERSED N
/*SUBSCRIPT          */	DEADTRANS(	0x005D	,0x005F	,0x02FD	,0x0000	), // MODIFIER LETTER SHELF
/*SUBSCRIPT          */	DEADTRANS(	0x005E	,0x005F	,0x2038	,0x0000	), // CARET
/*SUBSCRIPT          */	DEADTRANS(	0x005F	,0x005F	,0x2038	,0x0001	), // CARET
/*SUBSCRIPT          */	DEADTRANS(	0x0060	,0x005F	,0x02CE	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	L'v'	,0x02CC	,0x02EF	,0x0000	), // MODIFIER LETTER LOW DOWN ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x003C	,0x02CC	,0x02F1	,0x0000	), // MODIFIER LETTER LOW LEFT ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x003E	,0x02CC	,0x02F2	,0x0000	), // MODIFIER LETTER LOW RIGHT ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x005E	,0x02CC	,0x02F0	,0x0000	), // MODIFIER LETTER LOW UP ARROWHEAD
/*SUBSCRIPT          */	DEADTRANS(	0x202F	,0x02CC	,0x02CC	,0x0000	), // MODIFIER LETTER LOW VERTICAL LINE
/*SUBSCRIPT          */	DEADTRANS(	0x007E	,0x005F	,0x1E75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00A9	,0x005F	,0x1D01	,0x0001	), // LATIN LETTER SMALL CAPITAL AE
/*SUBSCRIPT          */	DEADTRANS(	L'A'	,0x1D01	,0x1D01	,0x0000	), // LATIN LETTER SMALL CAPITAL AE
/*SUBSCRIPT          */	DEADTRANS(	L'e'	,0x1D01	,0x2094	,0x0000	), // LATIN SUBSCRIPT SMALL LETTER SCHWA
/*SUBSCRIPT          */	DEADTRANS(	L'O'	,0x1D01	,0x0276	,0x0001	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	L'E'	,0x0276	,0x0276	,0x0000	), // LATIN LETTER SMALL CAPITAL OE
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x0276	,0x1D15	,0x0000	), // LATIN LETTER SMALL CAPITAL OU
/*SUBSCRIPT          */	DEADTRANS(	L'R'	,0x1D01	,0xA776	,0x0000	), // LATIN LETTER SMALL CAPITAL RUM
/*SUBSCRIPT          */	DEADTRANS(	L'Z'	,0x1D01	,0x1D23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*SUBSCRIPT          */	DEADTRANS(	L'z'	,0x1D01	,0x1D23	,0x0000	), // LATIN LETTER SMALL CAPITAL EZH
/*SUBSCRIPT          */	DEADTRANS(	0x002D	,0x1D01	,0x1D7B	,0x0001	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'B'	,0x1D7B	,0x1D03	,0x0000	), // LATIN LETTER SMALL CAPITAL BARRED B
/*SUBSCRIPT          */	DEADTRANS(	L'I'	,0x1D7B	,0x1D7B	,0x0000	), // LATIN SMALL CAPITAL LETTER I WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'L'	,0x1D7B	,0x1D0C	,0x0000	), // LATIN LETTER SMALL CAPITAL L WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	L'U'	,0x1D7B	,0x1D7E	,0x0000	), // LATIN SMALL CAPITAL LETTER U WITH STROKE
/*SUBSCRIPT          */	DEADTRANS(	0x00B0	,0x005F	,0x1E01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00D0	,0x005F	,0x1D06	,0x0000	), // LATIN LETTER SMALL CAPITAL ETH
/*SUBSCRIPT          */	DEADTRANS(	0x00E1	,0x005F	,0x02CF	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x00EB	,0x005F	,0x1E73	,0x0001	), // LATIN SMALL LETTER U WITH DIAERESIS BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x00F2	,0x005F	,0x02CE	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUBSCRIPT          */	DEADTRANS(	0x00F5	,0x005F	,0x1E75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x2212	,0x005F	,0x208B	,0x0000	), // SUBSCRIPT MINUS
/*SUBSCRIPT          */	DEADTRANS(	0x022F	,0x005F	,0x1ECD	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUBSCRIPT          */	DEADTRANS(	0x014D	,0x005F	,0x1E07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x202F	,0x005E	,0x2191	,0x0000	), // UPWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	L'A'	,0x005E	,0x1D2C	,0x0000	), // MODIFIER LETTER CAPITAL A
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x005E	,0x1D43	,0x0000	), // MODIFIER LETTER SMALL A
/*SUPERSCRIPT        */	DEADTRANS(	L'B'	,0x005E	,0x1D2E	,0x0000	), // MODIFIER LETTER CAPITAL B
/*SUPERSCRIPT        */	DEADTRANS(	L'b'	,0x005E	,0x1D47	,0x0000	), // MODIFIER LETTER SMALL B
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x005E	,0x1D9C	,0x0000	), // MODIFIER LETTER SMALL C
/*SUPERSCRIPT        */	DEADTRANS(	L'D'	,0x005E	,0x1D30	,0x0000	), // MODIFIER LETTER CAPITAL D
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0x005E	,0x1D48	,0x0000	), // MODIFIER LETTER SMALL D
/*SUPERSCRIPT        */	DEADTRANS(	L'E'	,0x005E	,0x1D31	,0x0000	), // MODIFIER LETTER CAPITAL E
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x005E	,0x1D49	,0x0000	), // MODIFIER LETTER SMALL E
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x005E	,0x1DA0	,0x0000	), // MODIFIER LETTER SMALL F
/*SUPERSCRIPT        */	DEADTRANS(	L'G'	,0x005E	,0x1D33	,0x0000	), // MODIFIER LETTER CAPITAL G
/*SUPERSCRIPT        */	DEADTRANS(	L'g'	,0x005E	,0x1D4D	,0x0000	), // MODIFIER LETTER SMALL G
/*SUPERSCRIPT        */	DEADTRANS(	L'H'	,0x005E	,0x1D34	,0x0000	), // MODIFIER LETTER CAPITAL H
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x005E	,0x02B0	,0x0000	), // MODIFIER LETTER SMALL H
/*SUPERSCRIPT        */	DEADTRANS(	L'I'	,0x005E	,0x1D35	,0x0000	), // MODIFIER LETTER CAPITAL I
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x005E	,0x2071	,0x0000	), // SUPERSCRIPT LATIN SMALL LETTER I
/*SUPERSCRIPT        */	DEADTRANS(	L'J'	,0x005E	,0x1D36	,0x0000	), // MODIFIER LETTER CAPITAL J
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0x005E	,0x02B2	,0x0000	), // MODIFIER LETTER SMALL J
/*SUPERSCRIPT        */	DEADTRANS(	L'K'	,0x005E	,0x1D37	,0x0000	), // MODIFIER LETTER CAPITAL K
/*SUPERSCRIPT        */	DEADTRANS(	L'k'	,0x005E	,0x1D4F	,0x0000	), // MODIFIER LETTER SMALL K
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x005E	,0x1D38	,0x0000	), // MODIFIER LETTER CAPITAL L
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x005E	,0x02E1	,0x0000	), // MODIFIER LETTER SMALL L
/*SUPERSCRIPT        */	DEADTRANS(	L'M'	,0x005E	,0x1D39	,0x0000	), // MODIFIER LETTER CAPITAL M
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0x005E	,0x1D50	,0x0000	), // MODIFIER LETTER SMALL M
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x005E	,0x1D3A	,0x0000	), // MODIFIER LETTER CAPITAL N
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0x005E	,0x207F	,0x0000	), // SUPERSCRIPT LATIN SMALL LETTER N
/*SUPERSCRIPT        */	DEADTRANS(	L'O'	,0x005E	,0x1D3C	,0x0000	), // MODIFIER LETTER CAPITAL O
/*SUPERSCRIPT        */	DEADTRANS(	L'o'	,0x005E	,0x1D52	,0x0000	), // MODIFIER LETTER SMALL O
/*SUPERSCRIPT        */	DEADTRANS(	L'P'	,0x005E	,0x1D3E	,0x0000	), // MODIFIER LETTER CAPITAL P
/*SUPERSCRIPT        */	DEADTRANS(	L'p'	,0x005E	,0x1D56	,0x0000	), // MODIFIER LETTER SMALL P
/*SUPERSCRIPT        */	DEADTRANS(	L'R'	,0x005E	,0x1D3F	,0x0000	), // MODIFIER LETTER CAPITAL R
/*SUPERSCRIPT        */	DEADTRANS(	L'r'	,0x005E	,0x02B3	,0x0000	), // MODIFIER LETTER SMALL R
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x005E	,0x02E2	,0x0000	), // MODIFIER LETTER SMALL S
/*SUPERSCRIPT        */	DEADTRANS(	L'T'	,0x005E	,0x1D40	,0x0000	), // MODIFIER LETTER CAPITAL T
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x005E	,0x1D57	,0x0000	), // MODIFIER LETTER SMALL T
/*SUPERSCRIPT        */	DEADTRANS(	L'U'	,0x005E	,0x1D41	,0x0000	), // MODIFIER LETTER CAPITAL U
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x005E	,0x1D58	,0x0000	), // MODIFIER LETTER SMALL U
/*SUPERSCRIPT        */	DEADTRANS(	L'V'	,0x005E	,0x2C7D	,0x0000	), // MODIFIER LETTER CAPITAL V
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x005E	,0x1D5B	,0x0000	), // MODIFIER LETTER SMALL V
/*SUPERSCRIPT        */	DEADTRANS(	L'W'	,0x005E	,0x1D42	,0x0000	), // MODIFIER LETTER CAPITAL W
/*SUPERSCRIPT        */	DEADTRANS(	L'w'	,0x005E	,0x02B7	,0x0000	), // MODIFIER LETTER SMALL W
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x005E	,0x02E3	,0x0000	), // MODIFIER LETTER SMALL X
/*SUPERSCRIPT        */	DEADTRANS(	L'y'	,0x005E	,0x02B8	,0x0000	), // MODIFIER LETTER SMALL Y
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x005E	,0x1DBB	,0x0000	), // MODIFIER LETTER SMALL Z
/*SUPERSCRIPT        */	DEADTRANS(	0x00C6	,0x005E	,0x1D2D	,0x0000	), // MODIFIER LETTER CAPITAL AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00E8	,0x005E	,0x02C0	,0x0000	), // MODIFIER LETTER GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x005E	,0xA7F9	,0x0000	), // MODIFIER LETTER SMALL LIGATURE OE
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x02E0	,0x1D45	,0x0000	), // MODIFIER LETTER SMALL ALPHA
/*SUPERSCRIPT        */	DEADTRANS(	L'b'	,0x02E0	,0x1D5D	,0x0000	), // MODIFIER LETTER SMALL BETA
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0x02E0	,0x1D5F	,0x0000	), // MODIFIER LETTER SMALL DELTA
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x02E0	,0x1D4B	,0x0000	), // MODIFIER LETTER SMALL OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x02E0	,0x1D60	,0x0000	), // MODIFIER LETTER SMALL GREEK PHI
/*SUPERSCRIPT        */	DEADTRANS(	L'g'	,0x02E0	,0x02E0	,0x0000	), // MODIFIER LETTER SMALL GAMMA
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x02E0	,0x1DA5	,0x0000	), // MODIFIER LETTER SMALL IOTA
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x02E0	,0x1DBF	,0x0000	), // MODIFIER LETTER SMALL THETA
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x02E0	,0x1DB7	,0x0000	), // MODIFIER LETTER SMALL UPSILON
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x02E0	,0x1D61	,0x0000	), // MODIFIER LETTER SMALL CHI
/*SUPERSCRIPT        */	DEADTRANS(	0x0021	,0x005E	,0xA71D	,0x0000	), // MODIFIER LETTER RAISED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0023	,0x005E	,0x02B4	,0x0001	), // MODIFIER LETTER SMALL TURNED R
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x02B4	,0x1D44	,0x0000	), // MODIFIER LETTER SMALL TURNED A
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x02B4	,0x1D53	,0x0000	), // MODIFIER LETTER SMALL OPEN O
/*SUPERSCRIPT        */	DEADTRANS(	L'f'	,0x02B4	,0x1DA1	,0x0000	), // MODIFIER LETTER SMALL DOTLESS J WITH STROKE
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x02B4	,0x1DA3	,0x0000	), // MODIFIER LETTER SMALL TURNED H
/*SUPERSCRIPT        */	DEADTRANS(	L'i'	,0x02B4	,0x1D4E	,0x0000	), // MODIFIER LETTER SMALL TURNED I
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x02B4	,0x1DAD	,0x0000	), // MODIFIER LETTER SMALL TURNED M WITH LONG LEG
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0x02B4	,0x1D5A	,0x0000	), // MODIFIER LETTER SMALL TURNED M
/*SUPERSCRIPT        */	DEADTRANS(	L'r'	,0x02B4	,0x02B4	,0x0000	), // MODIFIER LETTER SMALL TURNED R
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x02B4	,0xAB5D	,0x0000	), // MODIFIER LETTER SMALL L WITH INVERTED LAZY S
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x02B4	,0x1DBA	,0x0000	), // MODIFIER LETTER SMALL TURNED V
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x02B4	,0x1D46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00F9	,0x02B4	,0x1D4C	,0x0001	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	L'a'	,0x1D4C	,0x1D9B	,0x0000	), // MODIFIER LETTER SMALL TURNED ALPHA
/*SUPERSCRIPT        */	DEADTRANS(	L'e'	,0x1D4C	,0x1D4C	,0x0000	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x0021	,0x02B4	,0xA71E	,0x0000	), // MODIFIER LETTER RAISED INVERTED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0023	,0x02B4	,0x1D59	,0x0001	), // MODIFIER LETTER SMALL SIDEWAYS U
/*SUPERSCRIPT        */	DEADTRANS(	L'F'	,0x1D59	,0xA720	,0x0000	), // MODIFIER LETTER STRESS AND HIGH TONE
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x1D59	,0xA71A	,0x0000	), // MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0x1D59	,0x1D59	,0x0000	), // MODIFIER LETTER SMALL SIDEWAYS U
/*SUPERSCRIPT        */	DEADTRANS(	0x005B	,0x02B4	,0x02B5	,0x0000	), // MODIFIER LETTER SMALL TURNED R WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x00A9	,0x02B4	,0x1D46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x00B5	,0x02B4	,0x1D4C	,0x0001	), // MODIFIER LETTER SMALL TURNED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x00F2	,0x02B4	,0x1D46	,0x0000	), // MODIFIER LETTER SMALL TURNED AE
/*SUPERSCRIPT        */	DEADTRANS(	0x0024	,0x005E	,0x017F	,0x0000	), // LATIN SMALL LETTER LONG S
/*SUPERSCRIPT        */	DEADTRANS(	0x0025	,0x005E	,0xA71E	,0x0000	), // MODIFIER LETTER RAISED INVERTED EXCLAMATION MARK
/*SUPERSCRIPT        */	DEADTRANS(	0x0026	,0x005E	,0x1DA2	,0x0000	), // MODIFIER LETTER SMALL SCRIPT G
/*SUPERSCRIPT        */	DEADTRANS(	0x0027	,0x005E	,0x02CF	,0x0001	), // MODIFIER LETTER LOW ACUTE ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x005E	,0x207D	,0x0000	), // SUPERSCRIPT LEFT PARENTHESIS
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x005E	,0x207E	,0x0000	), // SUPERSCRIPT RIGHT PARENTHESIS
/*SUPERSCRIPT        */	DEADTRANS(	0x002A	,0x005E	,0x1D5C	,0x0000	), // MODIFIER LETTER SMALL AIN
/*SUPERSCRIPT        */	DEADTRANS(	0x002B	,0x005E	,0x207A	,0x0000	), // SUPERSCRIPT PLUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x002C	,0x005E	,0x0219	,0x0001	), // LATIN SMALL LETTER S WITH COMMA BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x002D	,0x005E	,0x0183	,0x0001	), // LATIN SMALL LETTER B WITH TOPBAR
/*SUPERSCRIPT        */	DEADTRANS(	0x002E	,0x005E	,0x02D9	,0x0001	), // DOT ABOVE
/*SUPERSCRIPT        */	DEADTRANS(	0x002F	,0x005E	,0x2044	,0x0000	), // FRACTION SLASH
/*SUPERSCRIPT        */	DEADTRANS(	L'0'	,0x005E	,0x2070	,0x0000	), // SUPERSCRIPT ZERO
/*SUPERSCRIPT        */	DEADTRANS(	L'1'	,0x005E	,0x00B9	,0x0000	), // SUPERSCRIPT ONE
/*SUPERSCRIPT        */	DEADTRANS(	L'2'	,0x005E	,0x00B2	,0x0000	), // SUPERSCRIPT TWO
/*SUPERSCRIPT        */	DEADTRANS(	L'3'	,0x005E	,0x00B3	,0x0000	), // SUPERSCRIPT THREE
/*SUPERSCRIPT        */	DEADTRANS(	L'4'	,0x005E	,0x2074	,0x0000	), // SUPERSCRIPT FOUR
/*SUPERSCRIPT        */	DEADTRANS(	L'5'	,0x005E	,0x2075	,0x0000	), // SUPERSCRIPT FIVE
/*SUPERSCRIPT        */	DEADTRANS(	L'6'	,0x005E	,0x2076	,0x0000	), // SUPERSCRIPT SIX
/*SUPERSCRIPT        */	DEADTRANS(	L'7'	,0x005E	,0x2077	,0x0000	), // SUPERSCRIPT SEVEN
/*SUPERSCRIPT        */	DEADTRANS(	L'8'	,0x005E	,0x2078	,0x0000	), // SUPERSCRIPT EIGHT
/*SUPERSCRIPT        */	DEADTRANS(	L'9'	,0x005E	,0x2079	,0x0000	), // SUPERSCRIPT NINE
/*SUPERSCRIPT        */	DEADTRANS(	0x003A	,0x005E	,0x02F8	,0x0000	), // MODIFIER LETTER RAISED COLON
/*SUPERSCRIPT        */	DEADTRANS(	0x003D	,0x005E	,0x207C	,0x0000	), // SUPERSCRIPT EQUALS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x005B	,0x005E	,0x02B1	,0x0001	), // MODIFIER LETTER SMALL H WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0x02B1	,0x02B1	,0x0000	), // MODIFIER LETTER SMALL H WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'v'	,0x02B1	,0x1DB9	,0x0000	), // MODIFIER LETTER SMALL V WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x005C	,0x005E	,0x1D32	,0x0001	), // MODIFIER LETTER CAPITAL REVERSED E
/*SUPERSCRIPT        */	DEADTRANS(	L'E'	,0x1D32	,0x1D32	,0x0000	), // MODIFIER LETTER CAPITAL REVERSED E
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x1D32	,0x1D3B	,0x0000	), // MODIFIER LETTER CAPITAL REVERSED N
/*SUPERSCRIPT        */	DEADTRANS(	0x00F2	,0x1D32	,0x02E4	,0x0000	), // MODIFIER LETTER SMALL REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x00F9	,0x1D32	,0x02C1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x0027	,0x1D32	,0x02C1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x00B5	,0x1D32	,0x1D9F	,0x0000	), // MODIFIER LETTER SMALL REVERSED OPEN E
/*SUPERSCRIPT        */	DEADTRANS(	0x2019	,0x1D32	,0x02C1	,0x0000	), // MODIFIER LETTER REVERSED GLOTTAL STOP
/*SUPERSCRIPT        */	DEADTRANS(	0x005D	,0x005E	,0x1DB5	,0x0001	), // MODIFIER LETTER SMALL T WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x1DB5	,0x1DAA	,0x0000	), // MODIFIER LETTER SMALL L WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L't'	,0x1DB5	,0x1DB5	,0x0000	), // MODIFIER LETTER SMALL T WITH PALATAL HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x005E	,0x005E	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	0x005F	,0x005E	,0x203E	,0x0000	), // OVERLINE
/*SUPERSCRIPT        */	DEADTRANS(	0x0060	,0x005E	,0x02CE	,0x0001	), // MODIFIER LETTER LOW GRAVE ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x007B	,0x005E	,0x1DBC	,0x0001	), // MODIFIER LETTER SMALL Z WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0x1DBC	,0x1DA9	,0x0000	), // MODIFIER LETTER SMALL L WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0x1DBC	,0x1DAF	,0x0000	), // MODIFIER LETTER SMALL N WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L's'	,0x1DBC	,0x1DB3	,0x0000	), // MODIFIER LETTER SMALL S WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x1DBC	,0x1DBC	,0x0000	), // MODIFIER LETTER SMALL Z WITH RETROFLEX HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x007D	,0x005E	,0xAB5F	,0x0001	), // MODIFIER LETTER SMALL U WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'm'	,0xAB5F	,0x1DAC	,0x0000	), // MODIFIER LETTER SMALL M WITH HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'n'	,0xAB5F	,0x1DAE	,0x0000	), // MODIFIER LETTER SMALL N WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	L'u'	,0xAB5F	,0xAB5F	,0x0000	), // MODIFIER LETTER SMALL U WITH LEFT HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x007E	,0x005E	,0xAB5E	,0x0001	), // MODIFIER LETTER SMALL L WITH MIDDLE TILDE
/*SUPERSCRIPT        */	DEADTRANS(	L'l'	,0xAB5E	,0xAB5E	,0x0000	), // MODIFIER LETTER SMALL L WITH MIDDLE TILDE
/*SUPERSCRIPT        */	DEADTRANS(	0x00A9	,0x005E	,0xA7F9	,0x0001	), // MODIFIER LETTER SMALL LIGATURE OE
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0xA7F9	,0x1D9D	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'd'	,0xA7F9	,0x1D9E	,0x0000	), // MODIFIER LETTER SMALL ETH
/*SUPERSCRIPT        */	DEADTRANS(	0x0259	,0xA7F9	,0x1D4A	,0x0000	), // MODIFIER LETTER SMALL SCHWA
/*SUPERSCRIPT        */	DEADTRANS(	L'h'	,0xA7F9	,0xAB5C	,0x0000	), // MODIFIER LETTER SMALL HENG
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0xA7F9	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	0x014B	,0xA7F9	,0x1D51	,0x0000	), // MODIFIER LETTER SMALL ENG
/*SUPERSCRIPT        */	DEADTRANS(	L'O'	,0xA7F9	,0x1D3D	,0x0000	), // MODIFIER LETTER CAPITAL OU
/*SUPERSCRIPT        */	DEADTRANS(	L'o'	,0xA7F9	,0x1D55	,0x0001	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x1D55	,0x1D54	,0x0000	), // MODIFIER LETTER SMALL TOP HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x1D55	,0x1D55	,0x0000	), // MODIFIER LETTER SMALL BOTTOM HALF O
/*SUPERSCRIPT        */	DEADTRANS(	0x0283	,0xA7F9	,0x1DB4	,0x0000	), // MODIFIER LETTER SMALL ESH
/*SUPERSCRIPT        */	DEADTRANS(	0x0292	,0xA7F9	,0x1DBE	,0x0000	), // MODIFIER LETTER SMALL EZH
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0xA7F9	,0x1D9D	,0x0001	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'c'	,0x1D9D	,0x1D9D	,0x0000	), // MODIFIER LETTER SMALL C WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	L'j'	,0x1D9D	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	L'z'	,0x1D9D	,0x1DBD	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	0x0153	,0x1D9D	,0x1DA8	,0x0000	), // MODIFIER LETTER SMALL J WITH CROSSED-TAIL
/*SUPERSCRIPT        */	DEADTRANS(	0x0026	,0xA7F9	,0x1DBD	,0x0000	), // MODIFIER LETTER SMALL Z WITH CURL
/*SUPERSCRIPT        */	DEADTRANS(	0x002D	,0xA7F9	,0x1D2F	,0x0000	), // MODIFIER LETTER CAPITAL BARRED B
/*SUPERSCRIPT        */	DEADTRANS(	0x00A7	,0x005E	,0x2040	,0x0000	), // CHARACTER TIE
/*SUPERSCRIPT        */	DEADTRANS(	0x00B0	,0x005E	,0x1E01	,0x0001	), // LATIN SMALL LETTER A WITH RING BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x00B5	,0x005E	,0x02E0	,0x0001	), // MODIFIER LETTER SMALL GAMMA
/*SUPERSCRIPT        */	DEADTRANS(	0x00EA	,0x005E	,0x02DF	,0x0001	), // MODIFIER LETTER CROSS ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	L'x'	,0x02DF	,0x02DF	,0x0000	), // MODIFIER LETTER CROSS ACCENT
/*SUPERSCRIPT        */	DEADTRANS(	0x00F9	,0x005E	,0x02C8	,0x0000	), // MODIFIER LETTER VERTICAL LINE
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x02DF	,0x02BF	,0x0000	), // MODIFIER LETTER LEFT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x02DF	,0x02BE	,0x0000	), // MODIFIER LETTER RIGHT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x002B	,0x02DF	,0x02D6	,0x0000	), // MODIFIER LETTER PLUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x002D	,0x02DF	,0x02D7	,0x0000	), // MODIFIER LETTER MINUS SIGN
/*SUPERSCRIPT        */	DEADTRANS(	0x003D	,0x02DF	,0x02ED	,0x0000	), // MODIFIER LETTER UNASPIRATED
/*SUPERSCRIPT        */	DEADTRANS(	0x005B	,0x02DF	,0x02DE	,0x0000	), // MODIFIER LETTER RHOTIC HOOK
/*SUPERSCRIPT        */	DEADTRANS(	0x2019	,0x005E	,0x02C8	,0x0000	), // MODIFIER LETTER VERTICAL LINE
/*SUPERSCRIPT        */	DEADTRANS(	0x00EB	,0x005E	,0x02B6	,0x0001	), // MODIFIER LETTER SMALL CAPITAL INVERTED R
/*SUPERSCRIPT        */	DEADTRANS(	L'H'	,0x02B6	,0x1D78	,0x0000	), // MODIFIER LETTER CYRILLIC EN
/*SUPERSCRIPT        */	DEADTRANS(	L'I'	,0x02B6	,0x1DA6	,0x0000	), // MODIFIER LETTER SMALL CAPITAL I
/*SUPERSCRIPT        */	DEADTRANS(	L'L'	,0x02B6	,0x1DAB	,0x0000	), // MODIFIER LETTER SMALL CAPITAL L
/*SUPERSCRIPT        */	DEADTRANS(	L'N'	,0x02B6	,0x1DB0	,0x0000	), // MODIFIER LETTER SMALL CAPITAL N
/*SUPERSCRIPT        */	DEADTRANS(	L'U'	,0x02B6	,0x1DB8	,0x0000	), // MODIFIER LETTER SMALL CAPITAL U
/*SUPERSCRIPT        */	DEADTRANS(	0x0025	,0x02B6	,0x02B6	,0x0000	), // MODIFIER LETTER SMALL CAPITAL INVERTED R
/*SUPERSCRIPT        */	DEADTRANS(	0x0028	,0x02D5	,0x02D3	,0x0000	), // MODIFIER LETTER CENTRED LEFT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x0029	,0x02D5	,0x02D2	,0x0000	), // MODIFIER LETTER CENTRED RIGHT HALF RING
/*SUPERSCRIPT        */	DEADTRANS(	0x002D	,0x02B6	,0x1DA7	,0x0000	), // MODIFIER LETTER SMALL CAPITAL I WITH STROKE
/*SUPERSCRIPT        */	DEADTRANS(	0x00F5	,0x005E	,0x1E75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x2212	,0x005E	,0x207B	,0x0000	), // SUPERSCRIPT MINUS
/*SUPERSCRIPT        */	DEADTRANS(	0x2191	,0x005E	,0x2193	,0x0001	), // DOWNWARDS ARROW
/*SUPERSCRIPT        */	DEADTRANS(	0x022F	,0x005E	,0x1ECD	,0x0001	), // LATIN SMALL LETTER O WITH DOT BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x014D	,0x005E	,0x1E07	,0x0001	), // LATIN SMALL LETTER B WITH LINE BELOW
/*SUPERSCRIPT        */	DEADTRANS(	0x024D	,0x005E	,0x0183	,0x0001	), // LATIN SMALL LETTER B WITH TOPBAR
/*TILDE              */	DEADTRANS(	0x0020	,0x00F5	,0x0303	,0x0000	), // COMBINING TILDE
/*TILDE              */	DEADTRANS(	0x0020	,0x1D6F	,0x0334	,0x0000	), // COMBINING TILDE OVERLAY
/*TILDE              */	DEADTRANS(	0x0020	,0x00D5	,0x034C	,0x0000	), // COMBINING ALMOST EQUAL TO ABOVE
/*TILDE              */	DEADTRANS(	0x202F	,0x00F5	,0x02DC	,0x0000	), // SMALL TILDE
/*TILDE              */	DEADTRANS(	0x00A0	,0x00F5	,0x007E	,0x0000	), // TILDE
/*TILDE              */	DEADTRANS(	L'A'	,0x00F5	,0x00C3	,0x0000	), // LATIN CAPITAL LETTER A WITH TILDE
/*TILDE              */	DEADTRANS(	L'a'	,0x00F5	,0x00E3	,0x0000	), // LATIN SMALL LETTER A WITH TILDE
/*TILDE              */	DEADTRANS(	L'b'	,0x00F5	,0x1D6C	,0x0000	), // LATIN SMALL LETTER B WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'd'	,0x00F5	,0x1D6D	,0x0000	), // LATIN SMALL LETTER D WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'E'	,0x00F5	,0x1EBC	,0x0000	), // LATIN CAPITAL LETTER E WITH TILDE
/*TILDE              */	DEADTRANS(	L'e'	,0x00F5	,0x1EBD	,0x0000	), // LATIN SMALL LETTER E WITH TILDE
/*TILDE              */	DEADTRANS(	L'F'	,0x00F5	,0x00AA	,0x0000	), // FEMININE ORDINAL INDICATOR
/*TILDE              */	DEADTRANS(	L'f'	,0x00F5	,0x1D6E	,0x0000	), // LATIN SMALL LETTER F WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'I'	,0x00F5	,0x0128	,0x0000	), // LATIN CAPITAL LETTER I WITH TILDE
/*TILDE              */	DEADTRANS(	L'i'	,0x00F5	,0x0129	,0x0000	), // LATIN SMALL LETTER I WITH TILDE
/*TILDE              */	DEADTRANS(	L'J'	,0x00F5	,0xA7AE	,0x0000	), // LATIN CAPITAL LETTER SMALL CAPITAL I
/*TILDE              */	DEADTRANS(	L'j'	,0x00F5	,0x026A	,0x0000	), // LATIN LETTER SMALL CAPITAL I
/*TILDE              */	DEADTRANS(	L'L'	,0x00F5	,0x2C62	,0x0000	), // LATIN CAPITAL LETTER L WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'l'	,0x00F5	,0x026B	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'M'	,0x00F5	,0x00BA	,0x0000	), // MASCULINE ORDINAL INDICATOR
/*TILDE              */	DEADTRANS(	L'm'	,0x00F5	,0x1D6F	,0x0000	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'N'	,0x00F5	,0x00D1	,0x0000	), // LATIN CAPITAL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	L'n'	,0x00F5	,0x00F1	,0x0000	), // LATIN SMALL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	L'O'	,0x00F5	,0x00D5	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	L'o'	,0x00F5	,0x00F5	,0x0000	), // LATIN SMALL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	L'p'	,0x00F5	,0x1D71	,0x0000	), // LATIN SMALL LETTER P WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'r'	,0x00F5	,0x1D72	,0x0000	), // LATIN SMALL LETTER R WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L's'	,0x00F5	,0x1D74	,0x0000	), // LATIN SMALL LETTER S WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L't'	,0x00F5	,0x1D75	,0x0000	), // LATIN SMALL LETTER T WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	L'U'	,0x00F5	,0x0168	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE
/*TILDE              */	DEADTRANS(	L'u'	,0x00F5	,0x0169	,0x0000	), // LATIN SMALL LETTER U WITH TILDE
/*TILDE              */	DEADTRANS(	L'V'	,0x00F5	,0x1E7C	,0x0000	), // LATIN CAPITAL LETTER V WITH TILDE
/*TILDE              */	DEADTRANS(	L'v'	,0x00F5	,0x1E7D	,0x0000	), // LATIN SMALL LETTER V WITH TILDE
/*TILDE              */	DEADTRANS(	L'Y'	,0x00F5	,0x1EF8	,0x0000	), // LATIN CAPITAL LETTER Y WITH TILDE
/*TILDE              */	DEADTRANS(	L'y'	,0x00F5	,0x1EF9	,0x0000	), // LATIN SMALL LETTER Y WITH TILDE
/*TILDE              */	DEADTRANS(	L'z'	,0x00F5	,0x1D76	,0x0000	), // LATIN SMALL LETTER Z WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x0021	,0x00F5	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*TILDE              */	DEADTRANS(	0x0022	,0x00F5	,0x201F	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0023	,0x00F5	,0x201F	,0x0000	), // DOUBLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0027	,0x00F5	,0x201B	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x0029	,0x00F5	,0x1EB5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*TILDE              */	DEADTRANS(	0x002A	,0x00F5	,0x02DC	,0x0000	), // SMALL TILDE
/*TILDE              */	DEADTRANS(	0x002B	,0x00F5	,0x1D6F	,0x0001	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x002C	,0x00F5	,0x1EE1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE              */	DEADTRANS(	0x002D	,0x00F5	,0x2053	,0x0000	), // SWUNG DASH
/*TILDE              */	DEADTRANS(	0x003D	,0x00F5	,0x2243	,0x0000	), // ASYMPTOTICALLY EQUAL TO
/*TILDE              */	DEADTRANS(	0x003F	,0x00F5	,0x00BF	,0x0000	), // INVERTED QUESTION MARK
/*TILDE              */	DEADTRANS(	0x005B	,0x00F5	,0x1D73	,0x0000	), // LATIN SMALL LETTER R WITH FISHHOOK AND MIDDLE TILDE
/*TILDE              */	DEADTRANS(	0x005F	,0x00F5	,0x022D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE              */	DEADTRANS(	0x007E	,0x00F5	,0x00D5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	0x00A3	,0x00F5	,0x1E75	,0x0001	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*TILDE              */	DEADTRANS(	0x00A9	,0x00F5	,0x00F1	,0x0001	), // LATIN SMALL LETTER N WITH TILDE
/*TILDE              */	DEADTRANS(	0x0022	,0x00F1	,0x1E4F	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE              */	DEADTRANS(	0x0027	,0x00F1	,0x1E4D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE              */	DEADTRANS(	0x00E1	,0x00F5	,0x1E4D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE              */	DEADTRANS(	0x00EA	,0x00F5	,0x1ED7	,0x0001	), // LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE
/*TILDE              */	DEADTRANS(	0x00EB	,0x00F5	,0x1E4F	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE              */	DEADTRANS(	0x00F5	,0x00F5	,0x00D5	,0x0001	), // LATIN CAPITAL LETTER O WITH TILDE
/*TILDE              */	DEADTRANS(	0x2019	,0x00F5	,0x201B	,0x0000	), // SINGLE HIGH-REVERSED-9 QUOTATION MARK
/*TILDE              */	DEADTRANS(	0x2610	,0x00F5	,0x274D	,0x0000	), // SHADOWED WHITE CIRCLE
/*TILDE              */	DEADTRANS(	0x0229	,0x00F5	,0x1EE1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE              */	DEADTRANS(	0x014F	,0x00F5	,0x1EB5	,0x0001	), // LATIN SMALL LETTER A WITH BREVE AND TILDE
/*TILDE              */	DEADTRANS(	0x014D	,0x00F5	,0x022D	,0x0001	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE              */	DEADTRANS(	0x01A1	,0x00F5	,0x1EE1	,0x0001	), // LATIN SMALL LETTER O WITH HORN AND TILDE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'O'	,0x1E4D	,0x1E4C	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'o'	,0x1E4D	,0x1E4D	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'U'	,0x1E4D	,0x1E78	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE AND ACUTE
/*TILDE&ACUTE_ACCENT */	DEADTRANS(	L'u'	,0x1E4D	,0x1E79	,0x0000	), // LATIN SMALL LETTER U WITH TILDE AND ACUTE
/*TILDE&DIAERESIS    */	DEADTRANS(	L'O'	,0x1E4F	,0x1E4E	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND DIAERESIS
/*TILDE&DIAERESIS    */	DEADTRANS(	L'o'	,0x1E4F	,0x1E4F	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND DIAERESIS
/*TILDE&MACRON       */	DEADTRANS(	L'O'	,0x022D	,0x022C	,0x0000	), // LATIN CAPITAL LETTER O WITH TILDE AND MACRON
/*TILDE&MACRON       */	DEADTRANS(	L'o'	,0x022D	,0x022D	,0x0000	), // LATIN SMALL LETTER O WITH TILDE AND MACRON
/*TILDE_BELOW        */	DEADTRANS(	0x0020	,0x1E75	,0x0330	,0x0000	), // COMBINING TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x00A3	,0x1E75	,0x1DFD	,0x0000	), // COMBINING ALMOST EQUAL TO BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x00A0	,0x1E75	,0x02F7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*TILDE_BELOW        */	DEADTRANS(	0x202F	,0x1E75	,0x02F7	,0x0000	), // MODIFIER LETTER LOW TILDE
/*TILDE_BELOW        */	DEADTRANS(	L'E'	,0x1E75	,0x1E1A	,0x0000	), // LATIN CAPITAL LETTER E WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'e'	,0x1E75	,0x1E1B	,0x0000	), // LATIN SMALL LETTER E WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'I'	,0x1E75	,0x1E2C	,0x0000	), // LATIN CAPITAL LETTER I WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'i'	,0x1E75	,0x1E2D	,0x0000	), // LATIN SMALL LETTER I WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'l'	,0x1E75	,0xAB38	,0x0000	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TILDE_BELOW        */	DEADTRANS(	L'U'	,0x1E75	,0x1E74	,0x0000	), // LATIN CAPITAL LETTER U WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	L'u'	,0x1E75	,0x1E75	,0x0000	), // LATIN SMALL LETTER U WITH TILDE BELOW
/*TILDE_BELOW        */	DEADTRANS(	0x0022	,0x1E75	,0x2E42	,0x0000	), // DOUBLE LOW-REVERSED-9 QUOTATION MARK
/*TILDE_BELOW        */	DEADTRANS(	0x0027	,0x1E75	,0x02BD	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_BELOW        */	DEADTRANS(	0x003D	,0x1E75	,0x2248	,0x0000	), // ALMOST EQUAL TO
/*TILDE_BELOW        */	DEADTRANS(	0x00F9	,0x1E75	,0x02BD	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_BELOW        */	DEADTRANS(	0x2019	,0x1E75	,0x02BD	,0x0000	), // MODIFIER LETTER REVERSED COMMA
/*TILDE_MIDDLE       */	DEADTRANS(	L'l'	,0x1D6F	,0x026B	,0x0000	), // LATIN SMALL LETTER L WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'm'	,0x1D6F	,0x1D6F	,0x0000	), // LATIN SMALL LETTER M WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'n'	,0x1D6F	,0x1D70	,0x0000	), // LATIN SMALL LETTER N WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	L'O'	,0x1D6F	,0x019F	,0x0000	), // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	0x007E	,0x1D6F	,0xAB38	,0x0001	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TILDE_MIDDLE       */	DEADTRANS(	0x00F5	,0x1D6F	,0xAB38	,0x0001	), // LATIN SMALL LETTER L WITH DOUBLE MIDDLE TILDE
/*TURNED             */	DEADTRANS(	L'A'	,0x0250	,0x2C6F	,0x0000	), // LATIN CAPITAL LETTER TURNED A
/*TURNED             */	DEADTRANS(	L'a'	,0x0250	,0x0250	,0x0000	), // LATIN SMALL LETTER TURNED A
/*TURNED             */	DEADTRANS(	L'C'	,0x0250	,0x0186	,0x0000	), // LATIN CAPITAL LETTER OPEN O
/*TURNED             */	DEADTRANS(	L'c'	,0x0250	,0x0254	,0x0000	), // LATIN SMALL LETTER OPEN O
/*TURNED             */	DEADTRANS(	L'E'	,0x0250	,0x018E	,0x0000	), // LATIN CAPITAL LETTER REVERSED E
/*TURNED             */	DEADTRANS(	L'e'	,0x0250	,0x01DD	,0x0000	), // LATIN SMALL LETTER TURNED E
/*TURNED             */	DEADTRANS(	L'f'	,0x0250	,0x025F	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE
/*TURNED             */	DEADTRANS(	L'g'	,0x0250	,0x1D77	,0x0000	), // LATIN SMALL LETTER TURNED G
/*TURNED             */	DEADTRANS(	L'H'	,0x0250	,0xA78D	,0x0000	), // LATIN CAPITAL LETTER TURNED H
/*TURNED             */	DEADTRANS(	L'h'	,0x0250	,0x0265	,0x0000	), // LATIN SMALL LETTER TURNED H
/*TURNED             */	DEADTRANS(	L'i'	,0x0250	,0x1D09	,0x0000	), // LATIN SMALL LETTER TURNED I
/*TURNED             */	DEADTRANS(	L'K'	,0x0250	,0xA7B0	,0x0000	), // LATIN CAPITAL LETTER TURNED K
/*TURNED             */	DEADTRANS(	L'k'	,0x0250	,0x029E	,0x0000	), // LATIN SMALL LETTER TURNED K
/*TURNED             */	DEADTRANS(	L'L'	,0x0250	,0xA780	,0x0000	), // LATIN CAPITAL LETTER TURNED L
/*TURNED             */	DEADTRANS(	L'l'	,0x0250	,0xA781	,0x0000	), // LATIN SMALL LETTER TURNED L
/*TURNED             */	DEADTRANS(	L'M'	,0x0250	,0x019C	,0x0000	), // LATIN CAPITAL LETTER TURNED M
/*TURNED             */	DEADTRANS(	L'm'	,0x0250	,0x026F	,0x0000	), // LATIN SMALL LETTER TURNED M
/*TURNED             */	DEADTRANS(	L'o'	,0x0250	,0xAB43	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O
/*TURNED             */	DEADTRANS(	L'r'	,0x0250	,0x0279	,0x0000	), // LATIN SMALL LETTER TURNED R
/*TURNED             */	DEADTRANS(	L'T'	,0x0250	,0xA7B1	,0x0000	), // LATIN CAPITAL LETTER TURNED T
/*TURNED             */	DEADTRANS(	L't'	,0x0250	,0x0287	,0x0000	), // LATIN SMALL LETTER TURNED T
/*TURNED             */	DEADTRANS(	L'u'	,0x0250	,0xAB51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*TURNED             */	DEADTRANS(	L'V'	,0x0250	,0x0245	,0x0000	), // LATIN CAPITAL LETTER TURNED V
/*TURNED             */	DEADTRANS(	L'v'	,0x0250	,0x028C	,0x0000	), // LATIN SMALL LETTER TURNED V
/*TURNED             */	DEADTRANS(	L'w'	,0x0250	,0x028D	,0x0000	), // LATIN SMALL LETTER TURNED W
/*TURNED             */	DEADTRANS(	L'y'	,0x0250	,0x028E	,0x0000	), // LATIN SMALL LETTER TURNED Y
/*TURNED             */	DEADTRANS(	0x00E6	,0x0250	,0x1D02	,0x0000	), // LATIN SMALL LETTER TURNED AE
/*TURNED             */	DEADTRANS(	0x00F9	,0x0250	,0x0252	,0x0001	), // LATIN SMALL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'A'	,0x0252	,0x2C70	,0x0000	), // LATIN CAPITAL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'a'	,0x0252	,0x0252	,0x0000	), // LATIN SMALL LETTER TURNED ALPHA
/*TURNED             */	DEADTRANS(	L'd'	,0x0252	,0x018D	,0x0000	), // LATIN SMALL LETTER TURNED DELTA
/*TURNED             */	DEADTRANS(	L'e'	,0x0252	,0x1D08	,0x0000	), // LATIN SMALL LETTER TURNED OPEN E
/*TURNED             */	DEADTRANS(	0x0021	,0x0250	,0x00A1	,0x0000	), // INVERTED EXCLAMATION MARK
/*TURNED             */	DEADTRANS(	0x0023	,0x0250	,0x1D1F	,0x0001	), // LATIN SMALL LETTER SIDEWAYS TURNED M
/*TURNED             */	DEADTRANS(	L'c'	,0x1D1F	,0x1D12	,0x0000	), // LATIN SMALL LETTER SIDEWAYS OPEN O
/*TURNED             */	DEADTRANS(	L'I'	,0x1D1F	,0xA7F7	,0x0000	), // LATIN EPIGRAPHIC LETTER SIDEWAYS I
/*TURNED             */	DEADTRANS(	L'm'	,0x1D1F	,0x1D1F	,0x0000	), // LATIN SMALL LETTER SIDEWAYS TURNED M
/*TURNED             */	DEADTRANS(	L'o'	,0x1D1F	,0x1D11	,0x0000	), // LATIN SMALL LETTER SIDEWAYS O
/*TURNED             */	DEADTRANS(	L'u'	,0x1D1F	,0x1D1D	,0x0000	), // LATIN SMALL LETTER SIDEWAYS U
/*TURNED             */	DEADTRANS(	0x00EB	,0x1D1F	,0x1D1E	,0x0000	), // LATIN SMALL LETTER SIDEWAYS DIAERESIZED U
/*TURNED             */	DEADTRANS(	0x002D	,0x0250	,0xAB42	,0x0001	), // LATIN SMALL LETTER TURNED OE WITH HORIZONTAL STROKE
/*TURNED             */	DEADTRANS(	0x0153	,0xAB42	,0xAB42	,0x0000	), // LATIN SMALL LETTER TURNED OE WITH HORIZONTAL STROKE
/*TURNED             */	DEADTRANS(	0x002F	,0x0250	,0xAB41	,0x0001	), // LATIN SMALL LETTER TURNED OE WITH STROKE
/*TURNED             */	DEADTRANS(	L'o'	,0xAB41	,0xAB44	,0x0000	), // LATIN SMALL LETTER TURNED O OPEN-O WITH STROKE
/*TURNED             */	DEADTRANS(	0x0153	,0xAB41	,0xAB41	,0x0000	), // LATIN SMALL LETTER TURNED OE WITH STROKE
/*TURNED             */	DEADTRANS(	L'2'	,0x0250	,0x218A	,0x0000	), // TURNED DIGIT TWO
/*TURNED             */	DEADTRANS(	L'3'	,0x0250	,0x218B	,0x0000	), // TURNED DIGIT THREE
/*TURNED             */	DEADTRANS(	L'8'	,0x0250	,0x221E	,0x0000	), // INFINITY
/*TURNED             */	DEADTRANS(	0x003C	,0x0250	,0x1D1A	,0x0001	), // LATIN LETTER SMALL CAPITAL TURNED R
/*TURNED             */	DEADTRANS(	L'E'	,0x1D1A	,0x2C7B	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED E
/*TURNED             */	DEADTRANS(	L'M'	,0x1D1A	,0xA7FA	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED M
/*TURNED             */	DEADTRANS(	L'R'	,0x1D1A	,0x1D1A	,0x0000	), // LATIN LETTER SMALL CAPITAL TURNED R
/*TURNED             */	DEADTRANS(	0x003F	,0x0250	,0x00BF	,0x0000	), // INVERTED QUESTION MARK
/*TURNED             */	DEADTRANS(	L'h'	,0x027B	,0x02AE	,0x0000	), // LATIN SMALL LETTER TURNED H WITH FISHHOOK
/*TURNED             */	DEADTRANS(	0x007B	,0x027B	,0x02AF	,0x0000	), // LATIN SMALL LETTER TURNED H WITH FISHHOOK AND TAIL
/*TURNED             */	DEADTRANS(	0x007B	,0x0250	,0x027B	,0x0000	), // LATIN SMALL LETTER TURNED R WITH HOOK
/*TURNED             */	DEADTRANS(	0x007C	,0x0250	,0x0270	,0x0001	), // LATIN SMALL LETTER TURNED M WITH LONG LEG
/*TURNED             */	DEADTRANS(	L'm'	,0x0270	,0x0270	,0x0000	), // LATIN SMALL LETTER TURNED M WITH LONG LEG
/*TURNED             */	DEADTRANS(	L'r'	,0x0270	,0x027A	,0x0000	), // LATIN SMALL LETTER TURNED R WITH LONG LEG
/*TURNED             */	DEADTRANS(	0x007D	,0x0250	,0x0284	,0x0001	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*TURNED             */	DEADTRANS(	L'f'	,0x0284	,0x0284	,0x0000	), // LATIN SMALL LETTER DOTLESS J WITH STROKE AND HOOK
/*TURNED             */	DEADTRANS(	L'r'	,0x0284	,0x2C79	,0x0000	), // LATIN SMALL LETTER TURNED R WITH TAIL
/*TURNED             */	DEADTRANS(	0x00A4	,0x0250	,0xA77F	,0x0001	), // LATIN SMALL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	L'G'	,0xA77F	,0xA77E	,0x0000	), // LATIN CAPITAL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	L'g'	,0xA77F	,0xA77F	,0x0000	), // LATIN SMALL LETTER TURNED INSULAR G
/*TURNED             */	DEADTRANS(	0x00A9	,0x0250	,0xAB51	,0x0000	), // LATIN SMALL LETTER TURNED UI
/*TURNED             */	DEADTRANS(	0x00B5	,0x0250	,0x0252	,0x0001	), // LATIN SMALL LETTER TURNED ALPHA

    0, 0
};

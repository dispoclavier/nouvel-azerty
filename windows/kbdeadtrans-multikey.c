/*****************************************************************************\
* Module name: kbdeadtrans-multikey.c
*
* Dedicated multikey sequences.
*
* Copyright:
* 1985..2001 Microsoft Corporation pro parte
* 2014..2025 Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Add the content as of build 6.1.3.0      6.1.3.0.0 Fri 2025-11-14T0658+0100
* Add partial kbdeadtrans-multikey.c       6.1.3.0.0 Fri 2025-11-14T0535+0100
*
* This file is included in kbdeadtrans.c.
*
*
* This is up-to-date and overrides the legacy multikey content.
*
* Near the bottom, this file lists all chained multikey virtual dead keys,
* also those for kbdeadtrans-multikey-equivalents.c.
* See // Multikey chain.
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
* multikey sequences.
*
\*****************************************************************************/

/*<!M>                                                             */ DEADTRANS( 0x00A6	,0x00A6	,0x00A6	,0x0000	), // '¦' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><%ampersand><%apostrophe>                                    */ DEADTRANS( L'-'	,0xE200	,0x20D0	,0x0000	), // '-' ➔ "⃐" COMBINING LEFT HARPOON ABOVE
/*<!M><%ampersand><%apostrophe>                                    */ DEADTRANS( 0x00A0	,0xE200	,0x20D3	,0x0000	), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%apostrophe>                                    */ DEADTRANS( L' '	,0xE200	,0x20D3	,0x0000	), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%aprightsinglequotemark>                        */ DEADTRANS( L'-'	,0xE201	,0x20D0	,0x0000	), // '-' ➔ "⃐" COMBINING LEFT HARPOON ABOVE
/*<!M><%ampersand><%aprightsinglequotemark>                        */ DEADTRANS( 0x00A0	,0xE201	,0x20D3	,0x0000	), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%aprightsinglequotemark>                        */ DEADTRANS( L' '	,0xE201	,0x20D3	,0x0000	), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand>                                                 */ DEADTRANS( L'\\'	,0xE202	,0x20E5	,0x0000	), // '\' ➔ "⃥" COMBINING REVERSE SOLIDUS OVERLAY
/*<!M><%ampersand><%bar>                                           */ DEADTRANS( L'|'	,0xE203	,0x20E6	,0x0000	), // '|' ➔ "⃦" COMBINING DOUBLE VERTICAL STROKE OVERLAY
/*<!M><%ampersand><%bar>                                           */ DEADTRANS( 0x00A0	,0xE203	,0x20D2	,0x0000	), // ' ' ➔ "⃒" COMBINING LONG VERTICAL LINE OVERLAY
/*<!M><%ampersand><%bar>                                           */ DEADTRANS( L' '	,0xE203	,0x20D2	,0x0000	), // ' ' ➔ "⃒" COMBINING LONG VERTICAL LINE OVERLAY
/*<!M><%ampersand>                                                 */ DEADTRANS( L','	,0xE202	,0x2063	,0x0000	), // ',' ➔ "⁣" INVISIBLE SEPARATOR
/*<!M><%ampersand>                                                 */ DEADTRANS( L'`'	,0xE202	,0x20ED	,0x0000	), // '`' ➔ "⃭" COMBINING LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%less><%minus>                                  */ DEADTRANS( L'>'	,0xE204	,0x20E1	,0x0000	), // '>' ➔ "⃡" COMBINING LEFT RIGHT ARROW ABOVE
/*<!M><%ampersand><%less><%minus>                                  */ DEADTRANS( 0x00A0	,0xE204	,0x20D6	,0x0000	), // ' ' ➔ "⃖" COMBINING LEFT ARROW ABOVE
/*<!M><%ampersand><%less><%minus>                                  */ DEADTRANS( L' '	,0xE204	,0x20D6	,0x0000	), // ' ' ➔ "⃖" COMBINING LEFT ARROW ABOVE
/*<!M><%ampersand><%less>                                          */ DEADTRANS( L'('	,0xE205	,0x20D4	,0x0000	), // '(' ➔ "⃔" COMBINING ANTICLOCKWISE ARROW ABOVE
/*<!M><%ampersand><%less>                                          */ DEADTRANS( L'_'	,0xE205	,0x20EE	,0x0000	), // '_' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( L'\''	,0xE206	,0x20EC	,0x0000	), // ''' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( 0x2019	,0xE206	,0x20EC	,0x0000	), // '’' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( L'`'	,0xE206	,0x20D1	,0x0000	), // '`' ➔ "⃑" COMBINING RIGHT HARPOON ABOVE
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( L'>'	,0xE206	,0x20D7	,0x0000	), // '>' ➔ "⃗" COMBINING RIGHT ARROW ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'('	,0xE202	,0x20D5	,0x0000	), // '(' ➔ "⃕" COMBINING CLOCKWISE ARROW ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'%'	,0xE202	,0x214B	,0x0000	), // '%' ➔ "⅋" TURNED AMPERSAND
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L'.'	,0xE207	,0x20DC	,0x0000	), // '.' ➔ "⃜" COMBINING FOUR DOTS ABOVE
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( 0x00A0	,0xE207	,0x20DB	,0x0000	), // ' ' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L' '	,0xE207	,0x20DB	,0x0000	), // ' ' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'+'	,0xE202	,0x2064	,0x0000	), // '+' ➔ "⁤" INVISIBLE PLUS
/*<!M><%ampersand>                                                 */ DEADTRANS( L'/'	,0xE202	,0x20EB	,0x0000	), // '/' ➔ "⃫" COMBINING LONG DOUBLE SOLIDUS OVERLAY
/*<!M><%ampersand><%underscore>                                    */ DEADTRANS( L'\''	,0xE208	,0x20EC	,0x0000	), // ''' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%underscore>                                    */ DEADTRANS( 0x2019	,0xE208	,0x20EC	,0x0000	), // '’' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%underscore>                                    */ DEADTRANS( L'>'	,0xE208	,0x20EF	,0x0000	), // '>' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><%ampersand>                                                 */ DEADTRANS( L'3'	,0xE202	,0x20DB	,0x0000	), // '3' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'4'	,0xE202	,0x20DC	,0x0000	), // '4' ➔ "⃜" COMBINING FOUR DOTS ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'9'	,0xE202	,0x1DD2	,0x0000	), // '9' ➔ "᷒" COMBINING US ABOVE
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'e'	,0xE209	,0x1DD4	,0x0000	), // 'e' ➔ "ᷔ" COMBINING LATIN SMALL LETTER AE
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'o'	,0xE209	,0x1DD5	,0x0000	), // 'o' ➔ "ᷕ" COMBINING LATIN SMALL LETTER AO
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'v'	,0xE209	,0x1DD6	,0x0000	), // 'v' ➔ "ᷖ" COMBINING LATIN SMALL LETTER AV
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'w'	,0xE209	,0x1DD3	,0x0000	), // 'w' ➔ "ᷓ" COMBINING LATIN SMALL LETTER FLATTENED OPEN A ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'f'	,0xE202	,0x2061	,0x0000	), // 'f' ➔ "⁡" FUNCTION APPLICATION invisible
/*<!M><%ampersand>                                                 */ DEADTRANS( L'i'	,0xE202	,0x1DD0	,0x0000	), // 'i' ➔ "᷐" COMBINING IS BELOW
/*<!M><%ampersand>                                                 */ DEADTRANS( L'n'	,0xE202	,0x0149	,0x0000	), // 'n' ➔ "ŉ" LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( L'\\'	,0xE20A	,0x20DA	,0x0000	), // '\' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( L'%'	,0xE20A	,0x20DA	,0x0000	), // '%' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( 0x00A0	,0xE20A	,0x20D9	,0x0000	), // ' ' ➔ "⃙" COMBINING CLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( L' '	,0xE20A	,0x20D9	,0x0000	), // ' ' ➔ "⃙" COMBINING CLOCKWISE RING OVERLAY
/*<!M><%ampersand><o>                                              */ DEADTRANS( L'<'	,0xE20B	,0x20DA	,0x0000	), // '<' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o>                                              */ DEADTRANS( 0x00A0	,0xE20B	,0x20D8	,0x0000	), // ' ' ➔ "⃘" COMBINING RING OVERLAY
/*<!M><%ampersand><o>                                              */ DEADTRANS( L' '	,0xE20B	,0x20D8	,0x0000	), // ' ' ➔ "⃘" COMBINING RING OVERLAY
/*<!M><%ampersand><u>                                              */ DEADTRANS( L'r'	,0xE20C	,0x1DD1	,0x0000	), // 'r' ➔ "᷑" COMBINING UR ABOVE
/*<!M><%ampersand><u>                                              */ DEADTRANS( L's'	,0xE20C	,0x1DD2	,0x0000	), // 's' ➔ "᷒" COMBINING US ABOVE
/*<!M><%ampersand>                                                 */ DEADTRANS( L'x'	,0xE202	,0x2062	,0x0000	), // 'x' ➔ "⁢" INVISIBLE TIMES
/*<!M><%ampersand>                                                 */ DEADTRANS( L'z'	,0xE202	,0x1DCF	,0x0000	), // 'z' ➔ "᷏" COMBINING ZIGZAG BELOW
/*<!M><%apostrophe><%equal>                                        */ DEADTRANS( L'\''	,0xE20D	,0x2AE9	,0x0000	), // ''' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><%apostrophe><%equal>                                        */ DEADTRANS( 0x00A0	,0xE20D	,0x2AE8	,0x0000	), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%apostrophe><%equal>                                        */ DEADTRANS( L' '	,0xE20D	,0x2AE8	,0x0000	), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L'\''	,0xE20E	,0x294D	,0x0000	), // ''' ➔ "⥍" UP BARB LEFT DOWN BARB RIGHT HARPOON
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L'|'	,0xE20E	,0x2960	,0x0000	), // '|' ➔ "⥠" UPWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L'!'	,0xE20E	,0x296E	,0x0000	), // '!' ➔ "⥮" UPWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%apostrophe><%exclam><%grave>                               */ DEADTRANS( L'!'	,0xE20F	,0x2963	,0x0000	), // '!' ➔ "⥣" UPWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%apostrophe><%exclam><%grave>                               */ DEADTRANS( 0x00A0	,0xE20F	,0x2951	,0x0000	), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%apostrophe><%exclam><%grave>                               */ DEADTRANS( L' '	,0xE20F	,0x2951	,0x0000	), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( 0x00A0	,0xE20E	,0x21BF	,0x0000	), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L' '	,0xE20E	,0x21BF	,0x0000	), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'\''	,0xE210	,0x294A	,0x0000	), // ''' ➔ "⥊" LEFT BARB UP RIGHT BARB DOWN HARPOON
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'|'	,0xE210	,0x295A	,0x0000	), // '|' ➔ "⥚" LEFTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L','	,0xE210	,0xDCD5	,0x0000	), // High surrogate: D83E; U+1F8D5 ',' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%grave>                                */ DEADTRANS( L'-'	,0xE211	,0x2962	,0x0000	), // '-' ➔ "⥢" LEFTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%apostrophe><%minus><%grave>                                */ DEADTRANS( 0x00A0	,0xE211	,0x294E	,0x0000	), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%apostrophe><%minus><%grave>                                */ DEADTRANS( L' '	,0xE211	,0x294E	,0x0000	), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'\''	,0xE212	,0x21CB	,0x0000	), // ''' ➔ "⇋" LEFTWARDS HARPOON OVER RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L','	,0xE212	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 ',' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'`'	,0xE212	,0x2966	,0x0000	), // '`' ➔ "⥦" LEFTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB UP
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'-'	,0xE212	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 '-' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'0'	,0xE212	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 '0' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'_'	,0xE210	,0x296A	,0x0000	), // '_' ➔ "⥪" LEFTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'0'	,0xE210	,0xDCD5	,0x0000	), // High surrogate: D83E; U+1F8D5 '0' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( 0x00A0	,0xE210	,0x21BC	,0x0000	), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L' '	,0xE210	,0x21BC	,0x0000	), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%aprightsinglequotemark><%equal>                            */ DEADTRANS( 0x2019	,0xE213	,0x2AE9	,0x0000	), // '’' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><%aprightsinglequotemark><%equal>                            */ DEADTRANS( 0x00A0	,0xE213	,0x2AE8	,0x0000	), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%aprightsinglequotemark><%equal>                            */ DEADTRANS( L' '	,0xE213	,0x2AE8	,0x0000	), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( 0x2019	,0xE214	,0x294D	,0x0000	), // '’' ➔ "⥍" UP BARB LEFT DOWN BARB RIGHT HARPOON
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( L'|'	,0xE214	,0x2960	,0x0000	), // '|' ➔ "⥠" UPWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( L'!'	,0xE214	,0x296E	,0x0000	), // '!' ➔ "⥮" UPWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%aprightsinglequotemark><%exclam><%grave>                   */ DEADTRANS( L'!'	,0xE215	,0x2963	,0x0000	), // '!' ➔ "⥣" UPWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%aprightsinglequotemark><%exclam><%grave>                   */ DEADTRANS( 0x00A0	,0xE215	,0x2951	,0x0000	), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%aprightsinglequotemark><%exclam><%grave>                   */ DEADTRANS( L' '	,0xE215	,0x2951	,0x0000	), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( 0x00A0	,0xE214	,0x21BF	,0x0000	), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( L' '	,0xE214	,0x21BF	,0x0000	), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( 0x2019	,0xE216	,0x294A	,0x0000	), // '’' ➔ "⥊" LEFT BARB UP RIGHT BARB DOWN HARPOON
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L'|'	,0xE216	,0x295A	,0x0000	), // '|' ➔ "⥚" LEFTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L','	,0xE216	,0xDCD5	,0x0000	), // High surrogate: D83E; U+1F8D5 ',' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus><%grave>                    */ DEADTRANS( L'-'	,0xE217	,0x2962	,0x0000	), // '-' ➔ "⥢" LEFTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%aprightsinglequotemark><%minus><%grave>                    */ DEADTRANS( 0x00A0	,0xE217	,0x294E	,0x0000	), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%aprightsinglequotemark><%minus><%grave>                    */ DEADTRANS( L' '	,0xE217	,0x294E	,0x0000	), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( 0x2019	,0xE218	,0x21CB	,0x0000	), // '’' ➔ "⇋" LEFTWARDS HARPOON OVER RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( L','	,0xE218	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 ',' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( L'`'	,0xE218	,0x2966	,0x0000	), // '`' ➔ "⥦" LEFTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB UP
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( L'-'	,0xE218	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 '-' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( L'0'	,0xE218	,0xDCD4	,0x0000	), // High surrogate: D83E; U+1F8D4 '0' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L'_'	,0xE216	,0x296A	,0x0000	), // '_' ➔ "⥪" LEFTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L'0'	,0xE216	,0xDCD5	,0x0000	), // High surrogate: D83E; U+1F8D5 '0' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( 0x00A0	,0xE216	,0x21BC	,0x0000	), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L' '	,0xE216	,0x21BC	,0x0000	), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%aprightsinglequotemark>                                    */ DEADTRANS( L'n'	,0xE219	,0x0149	,0x0000	), // 'n' ➔ "ŉ" LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*<!M><%asterisk>                                                  */ DEADTRANS( L'='	,0xE21A	,0x2A6E	,0x0000	), // '=' ➔ "⩮" EQUALS WITH ASTERISK
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L'/'	,0xE21B	,0x2A33	,0x0000	), // '/' ➔ "⨳" SMASH PRODUCT
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( 0x00A0	,0xE21B	,0x22CB	,0x0000	), // ' ' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L' '	,0xE21B	,0x22CB	,0x0000	), // ' ' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%bar>                                           */ DEADTRANS( L'#'	,0xE21C	,0x29E9	,0x0000	), // '#' ➔ "⧩" DOWN-POINTING TRIANGLE WITH RIGHT HALF BLACK
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'='	,0xE21D	,0x21D8	,0x0000	), // '=' ➔ "⇘" SOUTH EAST DOUBLE ARROW
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'<'	,0xE21D	,0x2929	,0x0000	), // '<' ➔ "⤩" SOUTH EAST ARROW AND SOUTH WEST ARROW
/*<!M><%backslash><%greater><%parenright>                          */ DEADTRANS( L'-'	,0xE21E	,0x29AA	,0x0000	), // '-' ➔ "⦪" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING DOWN AND RIGHT
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'/'	,0xE21D	,0x2928	,0x0000	), // '/' ➔ "⤨" NORTH EAST ARROW AND SOUTH EAST ARROW
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'2'	,0xE21D	,0x21D8	,0x0000	), // '2' ➔ "⇘" SOUTH EAST DOUBLE ARROW
/*<!M><%backslash><%greater>                                       */ DEADTRANS( 0x00A0	,0xE21D	,0x2198	,0x0000	), // ' ' ➔ "↘" SOUTH EAST ARROW
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L' '	,0xE21D	,0x2198	,0x0000	), // ' ' ➔ "↘" SOUTH EAST ARROW
/*<!M><%backslash><%hash>                                          */ DEADTRANS( L'|'	,0xE21F	,0x29E8	,0x0000	), // '|' ➔ "⧨" DOWN-POINTING TRIANGLE WITH LEFT HALF BLACK
/*<!M><%backslash><%minus>                                         */ DEADTRANS( L'_'	,0xE220	,0x29A5	,0x0000	), // '_' ➔ "⦥" REVERSED ANGLE WITH UNDERBAR
/*<!M><%backslash><%minus>                                         */ DEADTRANS( 0x00A0	,0xE220	,0x29F7	,0x0000	), // ' ' ➔ "⧷" REVERSE SOLIDUS WITH HORIZONTAL STROKE
/*<!M><%backslash><%minus>                                         */ DEADTRANS( L' '	,0xE220	,0x29F7	,0x0000	), // ' ' ➔ "⧷" REVERSE SOLIDUS WITH HORIZONTAL STROKE
/*<!M><%backslash><%parenleft>                                     */ DEADTRANS( L'-'	,0xE221	,0x299B	,0x0000	), // '-' ➔ "⦛" MEASURED ANGLE OPENING LEFT
/*<!M><%backslash><%parenleft>                                     */ DEADTRANS( L'/'	,0xE221	,0x29A0	,0x0000	), // '/' ➔ "⦠" SPHERICAL ANGLE OPENING LEFT
/*<!M><%backslash><%parenright>                                    */ DEADTRANS( L'/'	,0xE222	,0x2222	,0x0000	), // '/' ➔ "∢" SPHERICAL ANGLE
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'\\'	,0xE223	,0x22CB	,0x0000	), // '\' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'|'	,0xE223	,0x22CA	,0x0000	), // '|' ➔ "⋊" RIGHT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'>'	,0xE223	,0x292F	,0x0000	), // '>' ➔ "⤯" FALLING DIAGONAL CROSSING NORTH EAST ARROW
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'#'	,0xE223	,0x29D5	,0x0000	), // '#' ➔ "⧕" TIMES WITH RIGHT HALF BLACK
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'-'	,0xE224	,0x2A3A	,0x0000	), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'+'	,0xE224	,0x2A39	,0x0000	), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'_'	,0xE224	,0x29CB	,0x0000	), // '_' ➔ "⧋" TRIANGLE WITH UNDERBAR
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'o'	,0xE224	,0x27C1	,0x0000	), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L's'	,0xE224	,0x29CC	,0x0000	), // 's' ➔ "⧌" S IN TRIANGLE
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'x'	,0xE224	,0x2A3B	,0x0000	), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( 0x00A0	,0xE224	,0x2A32	,0x0000	), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L' '	,0xE224	,0x2A32	,0x0000	), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%backslash><%slash>                                         */ DEADTRANS( 0x00A0	,0xE223	,0x292C	,0x0000	), // ' ' ➔ "⤬" FALLING DIAGONAL CROSSING RISING DIAGONAL
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L' '	,0xE223	,0x292C	,0x0000	), // ' ' ➔ "⤬" FALLING DIAGONAL CROSSING RISING DIAGONAL
/*<!M><%backslash><%underscore>                                    */ DEADTRANS( L'|'	,0xE225	,0x25F9	,0x0000	), // '|' ➔ "◹" UPPER RIGHT TRIANGLE
/*<!M><%backslash><%underscore>                                    */ DEADTRANS( L'#'	,0xE225	,0x25E5	,0x0000	), // '#' ➔ "◥" BLACK UPPER RIGHT TRIANGLE
/*<!M><%backslash><%underscore>                                    */ DEADTRANS( L'/'	,0xE225	,0x2A32	,0x0000	), // '/' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%bar><%apostrophe>                                          */ DEADTRANS( L'!'	,0xE226	,0x2958	,0x0000	), // '!' ➔ "⥘" UPWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%bar><%apostrophe>                                          */ DEADTRANS( L'-'	,0xE226	,0x2952	,0x0000	), // '-' ➔ "⥒" LEFTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%bar><%aprightsinglequotemark>                              */ DEADTRANS( L'!'	,0xE227	,0x2958	,0x0000	), // '!' ➔ "⥘" UPWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%bar><%aprightsinglequotemark>                              */ DEADTRANS( L'-'	,0xE227	,0x2952	,0x0000	), // '-' ➔ "⥒" LEFTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L'|'	,0xE228	,0x22C8	,0x0000	), // '|' ➔ "⋈" BOWTIE
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L'['	,0xE228	,0x27D6	,0x0000	), // '[' ➔ "⟖" RIGHT OUTER JOIN
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L'#'	,0xE228	,0x29D2	,0x0000	), // '#' ➔ "⧒" BOWTIE WITH RIGHT HALF BLACK
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( 0x00A0	,0xE228	,0x22C9	,0x0000	), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L' '	,0xE228	,0x22C9	,0x0000	), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%backslash>                                           */ DEADTRANS( L'_'	,0xE229	,0x25FA	,0x0000	), // '_' ➔ "◺" LOWER LEFT TRIANGLE
/*<!M><%bar><%backslash>                                           */ DEADTRANS( 0x00A0	,0xE229	,0x2AEE	,0x0000	), // ' ' ➔ "⫮" DOES NOT DIVIDE WITH REVERSED NEGATION SLASH
/*<!M><%bar><%backslash>                                           */ DEADTRANS( L' '	,0xE229	,0x2AEE	,0x0000	), // ' ' ➔ "⫮" DOES NOT DIVIDE WITH REVERSED NEGATION SLASH
/*<!M><%bar><%bar><%bar>                                           */ DEADTRANS( L'-'	,0xE22A	,0x2AF5	,0x0000	), // '-' ➔ "⫵" TRIPLE VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><%bar><%bar><%equal>                                         */ DEADTRANS( L'/'	,0xE22B	,0x22AF	,0x0000	), // '/' ➔ "⊯" NEGATED DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar><%equal>                                         */ DEADTRANS( 0x00A0	,0xE22B	,0x22AB	,0x0000	), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar><%equal>                                         */ DEADTRANS( L' '	,0xE22B	,0x22AB	,0x0000	), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar>                                                 */ DEADTRANS( L'>'	,0xE22C	,0x29D0	,0x0000	), // '>' ➔ "⧐" VERTICAL BAR BESIDE RIGHT TRIANGLE
/*<!M><%bar><%bar><%minus>                                         */ DEADTRANS( L'/'	,0xE22D	,0x22AE	,0x0000	), // '/' ➔ "⊮" DOES NOT FORCE
/*<!M><%bar><%bar><%minus>                                         */ DEADTRANS( 0x00A0	,0xE22D	,0x2AF2	,0x0000	), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%bar><%minus>                                         */ DEADTRANS( L' '	,0xE22D	,0x2AF2	,0x0000	), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%bar>                                                 */ DEADTRANS( L'/'	,0xE22C	,0x2226	,0x0000	), // '/' ➔ "∦" NOT PARALLEL TO
/*<!M><%bar><%bar>                                                 */ DEADTRANS( L'~'	,0xE22C	,0x2AF3	,0x0000	), // '~' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'|'	,0xE22E	,0x29E6	,0x0000	), // '|' ➔ "⧦" GLEICH STARK
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( L'>'	,0xE22F	,0x27FE	,0x0000	), // '>' ➔ "⟾" LONG RIGHTWARDS DOUBLE ARROW FROM BAR
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( L'/'	,0xE22F	,0x22AD	,0x0000	), // '/' ➔ "⊭" NOT TRUE
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( 0x00A0	,0xE22F	,0x22A8	,0x0000	), // ' ' ➔ "⊨" TRUE
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( L' '	,0xE22F	,0x22A8	,0x0000	), // ' ' ➔ "⊨" TRUE
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'>'	,0xE22E	,0x2907	,0x0000	), // '>' ➔ "⤇" RIGHTWARDS DOUBLE ARROW FROM BAR
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'-'	,0xE22E	,0x2AE2	,0x0000	), // '-' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'/'	,0xE22E	,0x22AD	,0x0000	), // '/' ➔ "⊭" NOT TRUE
/*<!M><%bar><%equal>                                               */ DEADTRANS( 0x00A0	,0xE22E	,0x22A7	,0x0000	), // ' ' ➔ "⊧" MODELS
/*<!M><%bar><%equal>                                               */ DEADTRANS( L' '	,0xE22E	,0x22A7	,0x0000	), // ' ' ➔ "⊧" MODELS
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'\''	,0xE230	,0x295D	,0x0000	), // ''' ➔ "⥝" DOWNWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%bar><%exclam>                                              */ DEADTRANS( 0x2019	,0xE230	,0x295D	,0x0000	), // '’' ➔ "⥝" DOWNWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'`'	,0xE230	,0x2961	,0x0000	), // '`' ➔ "⥡" DOWNWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'>'	,0xE230	,0x21A7	,0x0000	), // '>' ➔ "↧" DOWNWARDS ARROW FROM BAR
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'o'	,0xE230	,0x2AF1	,0x0000	), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><%bar><%grave>                                               */ DEADTRANS( L'!'	,0xE231	,0x2954	,0x0000	), // '!' ➔ "⥔" UPWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%bar><%grave>                                               */ DEADTRANS( L'-'	,0xE231	,0x2956	,0x0000	), // '-' ➔ "⥖" LEFTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%bar><%greater>                                             */ DEADTRANS( L'<'	,0xE232	,0x29CE	,0x0000	), // '<' ➔ "⧎" RIGHT TRIANGLE ABOVE LEFT TRIANGLE
/*<!M><%bar><%greater><%slash>                                     */ DEADTRANS( L'_'	,0xE233	,0x22ED	,0x0000	), // '_' ➔ "⋭" DOES NOT CONTAIN AS NORMAL SUBGROUP OR EQUAL
/*<!M><%bar><%greater><%slash>                                     */ DEADTRANS( 0x00A0	,0xE233	,0x22EB	,0x0000	), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%bar><%greater><%slash>                                     */ DEADTRANS( L' '	,0xE233	,0x22EB	,0x0000	), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%bar><%greater><%underscore>                                */ DEADTRANS( L'/'	,0xE234	,0x22ED	,0x0000	), // '/' ➔ "⋭" DOES NOT CONTAIN AS NORMAL SUBGROUP OR EQUAL
/*<!M><%bar><%greater><%underscore>                                */ DEADTRANS( 0x00A0	,0xE234	,0x22B5	,0x0000	), // ' ' ➔ "⊵" CONTAINS AS NORMAL SUBGROUP OR EQUAL TO
/*<!M><%bar><%greater><%underscore>                                */ DEADTRANS( L' '	,0xE234	,0x22B5	,0x0000	), // ' ' ➔ "⊵" CONTAINS AS NORMAL SUBGROUP OR EQUAL TO
/*<!M><%bar><%greater>                                             */ DEADTRANS( 0x00A0	,0xE232	,0x22B3	,0x0000	), // ' ' ➔ "⊳" CONTAINS AS NORMAL SUBGROUP
/*<!M><%bar><%greater>                                             */ DEADTRANS( L' '	,0xE232	,0x22B3	,0x0000	), // ' ' ➔ "⊳" CONTAINS AS NORMAL SUBGROUP
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( L'|'	,0xE235	,0x29D1	,0x0000	), // '|' ➔ "⧑" BOWTIE WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( L'#'	,0xE235	,0x29D3	,0x0000	), // '#' ➔ "⧓" BLACK BOWTIE
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( 0x00A0	,0xE235	,0x29D4	,0x0000	), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( L' '	,0xE235	,0x29D4	,0x0000	), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash>                                    */ DEADTRANS( L'_'	,0xE236	,0x25E3	,0x0000	), // '_' ➔ "◣" BLACK LOWER LEFT TRIANGLE
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( L'|'	,0xE237	,0x29D1	,0x0000	), // '|' ➔ "⧑" BOWTIE WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( L'#'	,0xE237	,0x29D3	,0x0000	), // '#' ➔ "⧓" BLACK BOWTIE
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( 0x00A0	,0xE237	,0x29D4	,0x0000	), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( L' '	,0xE237	,0x29D4	,0x0000	), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash>                                        */ DEADTRANS( L'_'	,0xE238	,0x25E4	,0x0000	), // '_' ➔ "◤" BLACK UPPER LEFT TRIANGLE
/*<!M><%bar><%hash><%underscore>                                   */ DEADTRANS( L'\\'	,0xE239	,0x25E3	,0x0000	), // '\' ➔ "◣" BLACK LOWER LEFT TRIANGLE
/*<!M><%bar><%hash><%underscore>                                   */ DEADTRANS( L'/'	,0xE239	,0x25E4	,0x0000	), // '/' ➔ "◤" BLACK UPPER LEFT TRIANGLE
/*<!M><%bar><%less>                                                */ DEADTRANS( L'!'	,0xE23A	,0x2912	,0x0000	), // '!' ➔ "⤒" UPWARDS ARROW TO BAR
/*<!M><%bar><%less>                                                */ DEADTRANS( L'-'	,0xE23A	,0x21E4	,0x0000	), // '-' ➔ "⇤" LEFTWARDS ARROW TO BAR
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'\''	,0xE23B	,0x295F	,0x0000	), // ''' ➔ "⥟" RIGHTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%bar><%minus>                                               */ DEADTRANS( 0x2019	,0xE23B	,0x295F	,0x0000	), // '’' ➔ "⥟" RIGHTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%bar><%minus><%bar>                                         */ DEADTRANS( L'-'	,0xE23C	,0x2AE6	,0x0000	), // '-' ➔ "⫦" LONG DASH FROM LEFT MEMBER OF DOUBLE VERTICAL
/*<!M><%bar><%minus><%bar>                                         */ DEADTRANS( 0x00A0	,0xE23C	,0x2AF2	,0x0000	), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%minus><%bar>                                         */ DEADTRANS( L' '	,0xE23C	,0x2AF2	,0x0000	), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'='	,0xE23B	,0x2AE2	,0x0000	), // '=' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'`'	,0xE23B	,0x295B	,0x0000	), // '`' ➔ "⥛" RIGHTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( L'>'	,0xE23D	,0x2905	,0x0000	), // '>' ➔ "⤅" RIGHTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( L'<'	,0xE23D	,0x2920	,0x0000	), // '<' ➔ "⤠" RIGHTWARDS ARROW FROM BAR TO BLACK DIAMOND
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( 0x00A0	,0xE23D	,0x21A6	,0x0000	), // ' ' ➔ "↦" RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( L' '	,0xE23D	,0x21A6	,0x0000	), // ' ' ➔ "↦" RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( L'>'	,0xE23E	,0x27FC	,0x0000	), // '>' ➔ "⟼" LONG RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%minus><%minus>                               */ DEADTRANS( 0x00A0	,0xE23F	,0x27DD	,0x0000	), // ' ' ➔ "⟝" LONG RIGHT TACK
/*<!M><%bar><%minus><%minus><%minus>                               */ DEADTRANS( L' '	,0xE23F	,0x27DD	,0x0000	), // ' ' ➔ "⟝" LONG RIGHT TACK
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( L'/'	,0xE23E	,0x22AC	,0x0000	), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( 0x00A0	,0xE23E	,0x22A2	,0x0000	), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( L' '	,0xE23E	,0x22A2	,0x0000	), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'/'	,0xE23B	,0x22AC	,0x0000	), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><%bar><%minus>                                               */ DEADTRANS( 0x00A0	,0xE23B	,0x22A6	,0x0000	), // ' ' ➔ "⊦" ASSERTION
/*<!M><%bar><%minus>                                               */ DEADTRANS( L' '	,0xE23B	,0x22A6	,0x0000	), // ' ' ➔ "⊦" ASSERTION
/*<!M><%bar>                                                       */ DEADTRANS( L'('	,0xE240	,0x29AD	,0x0000	), // '(' ➔ "⦭" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING LEFT AND UP
/*<!M><%bar><%parenright>                                          */ DEADTRANS( L'\\'	,0xE241	,0x29AE	,0x0000	), // '\' ➔ "⦮" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING RIGHT AND DOWN
/*<!M><%bar><%parenright>                                          */ DEADTRANS( L'/'	,0xE241	,0x2ADC	,0x0000	), // '/' ➔ "⫝̸" FORKING
/*<!M><%bar><%period>                                              */ DEADTRANS( 0x00A0	,0xE242	,0x2999	,0x0000	), // ' ' ➔ "⦙" DOTTED FENCE
/*<!M><%bar><%period>                                              */ DEADTRANS( L' '	,0xE242	,0x2999	,0x0000	), // ' ' ➔ "⦙" DOTTED FENCE
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L'|'	,0xE243	,0x22C8	,0x0000	), // '|' ➔ "⋈" BOWTIE
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L'['	,0xE243	,0x27D6	,0x0000	), // '[' ➔ "⟖" RIGHT OUTER JOIN
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L'#'	,0xE243	,0x29D2	,0x0000	), // '#' ➔ "⧒" BOWTIE WITH RIGHT HALF BLACK
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( 0x00A0	,0xE243	,0x22C9	,0x0000	), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L' '	,0xE243	,0x22C9	,0x0000	), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%slash>                                               */ DEADTRANS( L'_'	,0xE244	,0x27C0	,0x0000	), // '_' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><%bar><%slash>                                               */ DEADTRANS( 0x00A0	,0xE244	,0x2224	,0x0000	), // ' ' ➔ "∤" DOES NOT DIVIDE
/*<!M><%bar><%slash>                                               */ DEADTRANS( L' '	,0xE244	,0x2224	,0x0000	), // ' ' ➔ "∤" DOES NOT DIVIDE
/*<!M><%bar><%tilde>                                               */ DEADTRANS( L'|'	,0xE245	,0x2AF3	,0x0000	), // '|' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L'\\'	,0xE246	,0x25FA	,0x0000	), // '\' ➔ "◺" LOWER LEFT TRIANGLE
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L'/'	,0xE246	,0x25F8	,0x0000	), // '/' ➔ "◸" UPPER LEFT TRIANGLE
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L'_'	,0xE246	,0x23E2	,0x0000	), // '_' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L's'	,0xE246	,0x2AE1	,0x0000	), // 's' ➔ "⫡" PERPENDICULAR WITH S
/*<!M><%bar><%underscore>                                          */ DEADTRANS( 0x00A0	,0xE246	,0x27C2	,0x0000	), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L' '	,0xE246	,0x27C2	,0x0000	), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%bar>                                                       */ DEADTRANS( L'p'	,0xE240	,0x204B	,0x0000	), // 'p' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%bar>                                                       */ DEADTRANS( L'P'	,0xE240	,0x204B	,0x0000	), // 'P' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%bar>                                                       */ DEADTRANS( L'w'	,0xE240	,0x299A	,0x0000	), // 'w' ➔ "⦚" VERTICAL ZIGZAG LINE
/*<!M><%bracketleft><%apostrophe>                                  */ DEADTRANS( 0x00A0	,0xE247	,0x298F	,0x0000	), // ' ' ➔ "⦏" LEFT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketleft><%apostrophe>                                  */ DEADTRANS( L' '	,0xE247	,0x298F	,0x0000	), // ' ' ➔ "⦏" LEFT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketleft>                                               */ DEADTRANS( L'*'	,0xE248	,0x29C6	,0x0000	), // '*' ➔ "⧆" SQUARED ASTERISK
/*<!M><%bracketleft><%backslash>                                   */ DEADTRANS( L']'	,0xE249	,0x29C5	,0x0000	), // ']' ➔ "⧅" SQUARED FALLING DIAGONAL SLASH
/*<!M><%bracketleft><%backslash><%colon>                           */ DEADTRANS( L']'	,0xE24A	,0x274F	,0x0000	), // ']' ➔ "❏" LOWER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%backslash><%minus>                           */ DEADTRANS( L']'	,0xE24B	,0x2751	,0x0000	), // ']' ➔ "❑" LOWER RIGHT SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%bar>                                         */ DEADTRANS( L']'	,0xE24C	,0x25EB	,0x0000	), // ']' ➔ "◫" WHITE SQUARE WITH VERTICAL BISECTING LINE
/*<!M><%bracketleft><%bar>                                         */ DEADTRANS( L'#'	,0xE24C	,0x25E8	,0x0000	), // '#' ➔ "◨" SQUARE WITH RIGHT HALF BLACK
/*<!M><%bracketleft><%bracketleft>                                 */ DEADTRANS( L']'	,0xE24D	,0x29E0	,0x0000	), // ']' ➔ "⧠" SQUARE WITH CONTOURED OUTLINE
/*<!M><%bracketleft><%bracketleft>                                 */ DEADTRANS( L'w'	,0xE24D	,0x29DA	,0x0000	), // 'w' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L'|'	,0xE24E	,0x25AF	,0x0000	), // '|' ➔ "▯" WHITE VERTICAL RECTANGLE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L'-'	,0xE24E	,0x27E5	,0x0000	), // '-' ➔ "⟥" WHITE SQUARE WITH RIGHTWARDS TICK
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L'0'	,0xE24E	,0x25FD	,0x0000	), // '0' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L'1'	,0xE24E	,0x25FB	,0x0000	), // '1' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( 0x00A0	,0xE24E	,0x25A1	,0x0000	), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L' '	,0xE24E	,0x25A1	,0x0000	), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketleft>                                               */ DEADTRANS( L'^'	,0xE248	,0x2308	,0x0000	), // '^' ➔ "⌈" LEFT CEILING
/*<!M><%bracketleft>                                               */ DEADTRANS( L'`'	,0xE248	,0x298D	,0x0000	), // '`' ➔ "⦍" LEFT SQUARE BRACKET WITH TICK IN TOP CORNER
/*<!M><%bracketleft><%hash>                                        */ DEADTRANS( L'|'	,0xE24F	,0x25E7	,0x0000	), // '|' ➔ "◧" SQUARE WITH LEFT HALF BLACK
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L'|'	,0xE250	,0x25AE	,0x0000	), // '|' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L'0'	,0xE250	,0x25FE	,0x0000	), // '0' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L'1'	,0xE250	,0x25FC	,0x0000	), // '1' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( 0x00A0	,0xE250	,0x25A0	,0x0000	), // ' ' ➔ "■" BLACK SQUARE
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L' '	,0xE250	,0x25A0	,0x0000	), // ' ' ➔ "■" BLACK SQUARE
/*<!M><%bracketleft><%hash>                                        */ DEADTRANS( L'/'	,0xE24F	,0x25E9	,0x0000	), // '/' ➔ "◩" SQUARE WITH UPPER LEFT DIAGONAL HALF BLACK
/*<!M><%bracketleft><%minus><%backslash>                           */ DEADTRANS( L']'	,0xE251	,0x29E0	,0x0000	), // ']' ➔ "⧠" SQUARE WITH CONTOURED OUTLINE
/*<!M><%bracketleft><%minus>                                       */ DEADTRANS( L']'	,0xE252	,0x229F	,0x0000	), // ']' ➔ "⊟" SQUARED MINUS
/*<!M><%bracketleft>                                               */ DEADTRANS( L'('	,0xE248	,0x2997	,0x0000	), // '(' ➔ "⦗" LEFT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketleft>                                               */ DEADTRANS( L'.'	,0xE248	,0x22A1	,0x0000	), // '.' ➔ "⊡" SQUARED DOT OPERATOR
/*<!M><%bracketleft>                                               */ DEADTRANS( L'+'	,0xE248	,0x229E	,0x0000	), // '+' ➔ "⊞" SQUARED PLUS
/*<!M><%bracketleft><%slash>                                       */ DEADTRANS( L']'	,0xE253	,0x29C4	,0x0000	), // ']' ➔ "⧄" SQUARED RISING DIAGONAL SLASH
/*<!M><%bracketleft><%slash><%colon>                               */ DEADTRANS( L']'	,0xE254	,0x2750	,0x0000	), // ']' ➔ "❐" UPPER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%slash>                                       */ DEADTRANS( L'#'	,0xE253	,0x25EA	,0x0000	), // '#' ➔ "◪" SQUARE WITH LOWER RIGHT DIAGONAL HALF BLACK
/*<!M><%bracketleft><%slash><%minus>                               */ DEADTRANS( L']'	,0xE255	,0x2752	,0x0000	), // ']' ➔ "❒" UPPER RIGHT SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%underscore>                                  */ DEADTRANS( L']'	,0xE256	,0x2610	,0x0000	), // ']' ➔ "☐" BALLOT BOX
/*<!M><%bracketleft><%underscore>                                  */ DEADTRANS( 0x00A0	,0xE256	,0x230A	,0x0000	), // ' ' ➔ "⌊" LEFT FLOOR
/*<!M><%bracketleft><%underscore>                                  */ DEADTRANS( L' '	,0xE256	,0x230A	,0x0000	), // ' ' ➔ "⌊" LEFT FLOOR
/*<!M><%bracketleft><V>                                            */ DEADTRANS( L']'	,0xE257	,0x2611	,0x0000	), // ']' ➔ "☑" BALLOT BOX WITH CHECK emoji
/*<!M><%bracketleft><v>                                            */ DEADTRANS( L']'	,0xE258	,0x27CF	,0x0000	), // ']' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft><v>                                            */ DEADTRANS( L'%'	,0xE258	,0x27CE	,0x0000	), // '%' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><%bracketleft><v>                                            */ DEADTRANS( 0x00A0	,0xE258	,0x27CF	,0x0000	), // ' ' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft><v>                                            */ DEADTRANS( L' '	,0xE258	,0x27CF	,0x0000	), // ' ' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft>                                               */ DEADTRANS( L'w'	,0xE248	,0x29D8	,0x0000	), // 'w' ➔ "⧘" LEFT WIGGLY FENCE
/*<!M><%bracketleft>                                               */ DEADTRANS( L'x'	,0xE248	,0x22A0	,0x0000	), // 'x' ➔ "⊠" SQUARED TIMES
/*<!M><%bracketleft><X>                                            */ DEADTRANS( L']'	,0xE259	,0x2612	,0x0000	), // ']' ➔ "☒" BALLOT BOX WITH X
/*<!M><%bracketleft><X><L>                                         */ DEADTRANS( L']'	,0xE25A	,0x2BBD	,0x0000	), // ']' ➔ "⮽" BALLOT BOX WITH LIGHT X
/*<!M><%bracketright>                                              */ DEADTRANS( L'\''	,0xE25B	,0x2990	,0x0000	), // ''' ➔ "⦐" RIGHT SQUARE BRACKET WITH TICK IN TOP CORNER
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'|'	,0xE25C	,0x27D5	,0x0000	), // '|' ➔ "⟕" LEFT OUTER JOIN
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'['	,0xE25C	,0x27D7	,0x0000	), // '[' ➔ "⟗" FULL OUTER JOIN
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'|'	,0xE25D	,0x25AF	,0x0000	), // '|' ➔ "▯" WHITE VERTICAL RECTANGLE
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'-'	,0xE25D	,0x27E5	,0x0000	), // '-' ➔ "⟥" WHITE SQUARE WITH RIGHTWARDS TICK
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'0'	,0xE25D	,0x25FD	,0x0000	), // '0' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'1'	,0xE25D	,0x25FB	,0x0000	), // '1' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( 0x00A0	,0xE25D	,0x25A1	,0x0000	), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L' '	,0xE25D	,0x25A1	,0x0000	), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketright><%bracketright>                               */ DEADTRANS( L'w'	,0xE25E	,0x29DB	,0x0000	), // 'w' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><%bracketright>                                              */ DEADTRANS( L'^'	,0xE25B	,0x2309	,0x0000	), // '^' ➔ "⌉" RIGHT CEILING
/*<!M><%bracketright>                                              */ DEADTRANS( L'`'	,0xE25B	,0x298E	,0x0000	), // '`' ➔ "⦎" RIGHT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketright><%parenright>                                 */ DEADTRANS( 0x00A0	,0xE25F	,0x2998	,0x0000	), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketright><%parenright>                                 */ DEADTRANS( L' '	,0xE25F	,0x2998	,0x0000	), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'|'	,0xE260	,0x27D5	,0x0000	), // '|' ➔ "⟕" LEFT OUTER JOIN
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'['	,0xE260	,0x27D7	,0x0000	), // '[' ➔ "⟗" FULL OUTER JOIN
/*<!M><%bracketright>                                              */ DEADTRANS( L'_'	,0xE25B	,0x230B	,0x0000	), // '_' ➔ "⌋" RIGHT FLOOR
/*<!M><%bracketright>                                              */ DEADTRANS( L'w'	,0xE25B	,0x29D9	,0x0000	), // 'w' ➔ "⧙" RIGHT WIGGLY FENCE
/*<!M><%circum><%ampersand><%braceleft><%braceleft>                */ DEADTRANS( L'd'	,0xE261	,0xDF89	,0x0000	), // High surrogate: D801; U+10789 'd' ➔ "𐞉" MODIFIER LETTER SMALL DZ DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft><%braceleft>                */ DEADTRANS( L't'	,0xE261	,0xDFAB	,0x0000	), // High surrogate: D801; U+107AB 't' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft>                            */ DEADTRANS( L'd'	,0xE262	,0xDF89	,0x0000	), // High surrogate: D801; U+10789 'd' ➔ "𐞉" MODIFIER LETTER SMALL DZ DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft>                            */ DEADTRANS( L't'	,0xE262	,0xDFAB	,0x0000	), // High surrogate: D801; U+107AB 't' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceright>                           */ DEADTRANS( L'd'	,0xE263	,0xDF88	,0x0000	), // High surrogate: D801; U+10788 'd' ➔ "𐞈" MODIFIER LETTER SMALL DZ DIGRAPH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand><%braceright>                           */ DEADTRANS( L'l'	,0xE263	,0xDF9F	,0x0000	), // High surrogate: D801; U+1079F 'l' ➔ "𐞟" MODIFIER LETTER SMALL LEZH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand><%braceright>                           */ DEADTRANS( L't'	,0xE263	,0xDFAD	,0x0000	), // High surrogate: D801; U+107AD 't' ➔ "𐞭" MODIFIER LETTER SMALL TS DIGRAPH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand>                                        */ DEADTRANS( L'9'	,0xE264	,0xA770	,0x0000	), // '9' ➔ "ꝰ" MODIFIER LETTER US
/*<!M><%circum><%ampersand><A>                                     */ DEADTRANS( L'A'	,0xE265	,0xDF80	,0x0000	), // High surrogate: D801; U+10780 'A' ➔ "𐞀" MODIFIER LETTER SMALL CAPITAL AA
/*<!M><%circum><%ampersand><d>                                     */ DEADTRANS( L'3'	,0xE266	,0xDF8A	,0x0000	), // High surrogate: D801; U+1078A '3' ➔ "𐞊" MODIFIER LETTER SMALL DEZH DIGRAPH
/*<!M><%circum><%ampersand><d>                                     */ DEADTRANS( L'z'	,0xE266	,0xDF87	,0x0000	), // High surrogate: D801; U+10787 'z' ➔ "𐞇" MODIFIER LETTER SMALL DZ DIGRAPH
/*<!M><%circum><%ampersand><f>                                     */ DEADTRANS( L'g'	,0xE267	,0xDF90	,0x0000	), // High surrogate: D801; U+10790 'g' ➔ "𐞐" MODIFIER LETTER SMALL FENG DIGRAPH
/*<!M><%circum><%ampersand><f>                                     */ DEADTRANS( L'n'	,0xE267	,0xDF90	,0x0000	), // High surrogate: D801; U+10790 'n' ➔ "𐞐" MODIFIER LETTER SMALL FENG DIGRAPH
/*<!M><%circum><%ampersand><l>                                     */ DEADTRANS( L'3'	,0xE268	,0xDF9E	,0x0000	), // High surrogate: D801; U+1079E '3' ➔ "𐞞" MODIFIER LETTER SMALL LEZH
/*<!M><%circum><%ampersand><l>                                     */ DEADTRANS( L's'	,0xE268	,0xDF99	,0x0000	), // High surrogate: D801; U+10799 's' ➔ "𐞙" MODIFIER LETTER SMALL LS DIGRAPH
/*<!M><%circum><%ampersand><l>                                     */ DEADTRANS( L'z'	,0xE268	,0xDF9A	,0x0000	), // High surrogate: D801; U+1079A 'z' ➔ "𐞚" MODIFIER LETTER SMALL LZ DIGRAPH
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L'c'	,0xE269	,0xDFAB	,0x0000	), // High surrogate: D801; U+107AB 'c' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L'e'	,0xE269	,0xDFAE	,0x0000	), // High surrogate: D801; U+107AE 'e' ➔ "𐞮" MODIFIER LETTER SMALL TESH DIGRAPH
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L's'	,0xE269	,0xDFAC	,0x0000	), // High surrogate: D801; U+107AC 's' ➔ "𐞬" MODIFIER LETTER SMALL TS DIGRAPH
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L'S'	,0xE269	,0xDFAE	,0x0000	), // High surrogate: D801; U+107AE 'S' ➔ "𐞮" MODIFIER LETTER SMALL TESH DIGRAPH
/*<!M><%circum><%ampersand>                                        */ DEADTRANS( L'u'	,0xE264	,0xA770	,0x0000	), // 'u' ➔ "ꝰ" MODIFIER LETTER US
/*<!M><%circum>                                                    */ DEADTRANS( L']'	,0xE26A	,0x2309	,0x0000	), // ']' ➔ "⌉" RIGHT CEILING
/*<!M><%circum><%hash>                                             */ DEADTRANS( L'_'	,0xE26B	,0x25B4	,0x0000	), // '_' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><%circum>                                                    */ DEADTRANS( L'+'	,0xE26A	,0x2A23	,0x0000	), // '+' ➔ "⨣" PLUS SIGN WITH CIRCUMFLEX ACCENT ABOVE
/*<!M><%circum><%tilde>                                            */ DEADTRANS( L'~'	,0xE26C	,0x2A6F	,0x0000	), // '~' ➔ "⩯" ALMOST EQUAL TO WITH CIRCUMFLEX ACCENT
/*<!M><%colon><%colon><%equal>                                     */ DEADTRANS( 0x00A0	,0xE26D	,0x2A74	,0x0000	), // ' ' ➔ "⩴" DOUBLE COLON EQUAL
/*<!M><%colon><%colon><%equal>                                     */ DEADTRANS( L' '	,0xE26D	,0x2A74	,0x0000	), // ' ' ➔ "⩴" DOUBLE COLON EQUAL
/*<!M><%colon>                                                     */ DEADTRANS( L'='	,0xE26E	,0x2254	,0x0000	), // '=' ➔ "≔" COLON EQUALS
/*<!M><%colon><%minus>                                             */ DEADTRANS( L':'	,0xE26F	,0x223A	,0x0000	), // ':' ➔ "∺" GEOMETRIC PROPORTION
/*<!M><%colon><%minus>                                             */ DEADTRANS( L'>'	,0xE26F	,0x29F4	,0x0000	), // '>' ➔ "⧴" RULE-DELAYED
/*<!M><%colon><%minus>                                             */ DEADTRANS( L'x'	,0xE26F	,0x22C7	,0x0000	), // 'x' ➔ "⋇" DIVISION TIMES
/*<!M><%colon><%minus>                                             */ DEADTRANS( 0x00A0	,0xE26F	,0x00F7	,0x0000	), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%colon><%minus>                                             */ DEADTRANS( L' '	,0xE26F	,0x00F7	,0x0000	), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%colon>                                                     */ DEADTRANS( L'('	,0xE26E	,0x2639	,0x0000	), // '(' ➔ "☹" WHITE FROWNING FACE emoji with skin tone support
/*<!M><%colon>                                                     */ DEADTRANS( L')'	,0xE26E	,0x263A	,0x0000	), // ')' ➔ "☺" WHITE SMILING FACE emoji with skin tone support, 25th-ranking
/*<!M><%colon>                                                     */ DEADTRANS( L'.'	,0xE26E	,0x2AF6	,0x0000	), // '.' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><%comma>                                                     */ DEADTRANS( L'-'	,0xE270	,0x2A29	,0x0000	), // '-' ➔ "⨩" MINUS SIGN WITH COMMA ABOVE
/*<!M><%equal><%apostrophe>                                        */ DEADTRANS( L'='	,0xE271	,0x2AE7	,0x0000	), // '=' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><%equal><%apostrophe>                                        */ DEADTRANS( 0x00A0	,0xE271	,0x2AEC	,0x0000	), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%apostrophe>                                        */ DEADTRANS( L' '	,0xE271	,0x2AEC	,0x0000	), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%aprightsinglequotemark>                            */ DEADTRANS( L'='	,0xE272	,0x2AE7	,0x0000	), // '=' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><%equal><%aprightsinglequotemark>                            */ DEADTRANS( 0x00A0	,0xE272	,0x2AEC	,0x0000	), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%aprightsinglequotemark>                            */ DEADTRANS( L' '	,0xE272	,0x2AEC	,0x0000	), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%bar><%bar>                                         */ DEADTRANS( L'='	,0xE273	,0x27DA	,0x0000	), // '=' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><%equal><%bar><%bar>                                         */ DEADTRANS( 0x00A0	,0xE273	,0x2AE5	,0x0000	), // ' ' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar><%bar>                                         */ DEADTRANS( L' '	,0xE273	,0x2AE5	,0x0000	), // ' ' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar>                                               */ DEADTRANS( L'='	,0xE274	,0x2903	,0x0000	), // '=' ➔ "⤃" RIGHTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%equal><%bar>                                               */ DEADTRANS( L'>'	,0xE274	,0x2903	,0x0000	), // '>' ➔ "⤃" RIGHTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%equal><%bar>                                               */ DEADTRANS( 0x00A0	,0xE274	,0x2AE4	,0x0000	), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar>                                               */ DEADTRANS( L' '	,0xE274	,0x2AE4	,0x0000	), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal>                                                     */ DEADTRANS( L'^'	,0xE275	,0x207C	,0x0000	), // '^' ➔ "⁼" SUPERSCRIPT EQUALS SIGN
/*<!M><%equal>                                                     */ DEADTRANS( L':'	,0xE275	,0x2255	,0x0000	), // ':' ➔ "≕" EQUALS COLON
/*<!M><%equal><%equal><%equal>                                     */ DEADTRANS( 0x00A0	,0xE276	,0x2A76	,0x0000	), // ' ' ➔ "⩶" THREE CONSECUTIVE EQUALS SIGNS
/*<!M><%equal><%equal><%equal>                                     */ DEADTRANS( L' '	,0xE276	,0x2A76	,0x0000	), // ' ' ➔ "⩶" THREE CONSECUTIVE EQUALS SIGNS
/*<!M><%equal><%equal>                                             */ DEADTRANS( L'>'	,0xE277	,0x27F9	,0x0000	), // '>' ➔ "⟹" LONG RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%greater>                                           */ DEADTRANS( L'`'	,0xE278	,0x2A9C	,0x0000	), // '`' ➔ "⪜" DOUBLE-LINE SLANTED EQUAL TO OR GREATER-THAN
/*<!M><%equal><%greater>                                           */ DEADTRANS( 0x00A0	,0xE278	,0x21D2	,0x0000	), // ' ' ➔ "⇒" RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%greater>                                           */ DEADTRANS( L' '	,0xE278	,0x21D2	,0x0000	), // ' ' ➔ "⇒" RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%less>                                              */ DEADTRANS( L'`'	,0xE279	,0x2A9B	,0x0000	), // '`' ➔ "⪛" DOUBLE-LINE SLANTED EQUAL TO OR LESS-THAN
/*<!M><%equal><%less>                                              */ DEADTRANS( L'-'	,0xE279	,0x2B40	,0x0000	), // '-' ➔ "⭀" EQUALS SIGN ABOVE LEFTWARDS ARROW
/*<!M><%equal><%less>                                              */ DEADTRANS( 0x00A0	,0xE279	,0x2A99	,0x0000	), // ' ' ➔ "⪙" DOUBLE-LINE EQUAL TO OR LESS-THAN
/*<!M><%equal><%less>                                              */ DEADTRANS( L' '	,0xE279	,0x2A99	,0x0000	), // ' ' ➔ "⪙" DOUBLE-LINE EQUAL TO OR LESS-THAN
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE27A	,0x2A69	,0x0000	), // '|' ➔ "⩩" TRIPLE HORIZONTAL BAR WITH TRIPLE VERTICAL STROKE
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( 0x00A0	,0xE27A	,0x2A68	,0x0000	), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L' '	,0xE27A	,0x2A68	,0x0000	), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%equal><%minus><%slash>                                     */ DEADTRANS( 0x00A0	,0xE27B	,0x2262	,0x0000	), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%equal><%minus><%slash>                                     */ DEADTRANS( L' '	,0xE27B	,0x2262	,0x0000	), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%equal><%minus>                                             */ DEADTRANS( 0x00A0	,0xE27C	,0x2261	,0x0000	), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%equal><%minus>                                             */ DEADTRANS( L' '	,0xE27C	,0x2261	,0x0000	), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%equal>                                                     */ DEADTRANS( L')'	,0xE275	,0x2970	,0x0000	), // ')' ➔ "⥰" RIGHT DOUBLE ARROW WITH ROUNDED HEAD
/*<!M><%equal>                                                     */ DEADTRANS( L'.'	,0xE275	,0x2A66	,0x0000	), // '.' ➔ "⩦" EQUALS SIGN WITH DOT BELOW
/*<!M><%equal>                                                     */ DEADTRANS( L'+'	,0xE275	,0x2A71	,0x0000	), // '+' ➔ "⩱" EQUALS SIGN ABOVE PLUS SIGN
/*<!M><%equal><%slash>                                             */ DEADTRANS( L'>'	,0xE27D	,0x21CF	,0x0000	), // '>' ➔ "⇏" RIGHTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%equal><%slash>                                             */ DEADTRANS( L'/'	,0xE27D	,0x29E3	,0x0000	), // '/' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><%equal><%slash>                                             */ DEADTRANS( 0x00A0	,0xE27D	,0x2260	,0x0000	), // ' ' ➔ "≠" NOT EQUAL TO
/*<!M><%equal><%slash>                                             */ DEADTRANS( L' '	,0xE27D	,0x2260	,0x0000	), // ' ' ➔ "≠" NOT EQUAL TO
/*<!M><%equal>                                                     */ DEADTRANS( L'~'	,0xE275	,0x2A73	,0x0000	), // '~' ➔ "⩳" EQUALS SIGN ABOVE TILDE OPERATOR
/*<!M><%equal>                                                     */ DEADTRANS( L'_'	,0xE275	,0x208C	,0x0000	), // '_' ➔ "₌" SUBSCRIPT EQUALS SIGN
/*<!M><%exclam><%apostrophe>                                       */ DEADTRANS( L'|'	,0xE27E	,0x2955	,0x0000	), // '|' ➔ "⥕" DOWNWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%exclam><%apostrophe>                                       */ DEADTRANS( 0x00A0	,0xE27E	,0x21C2	,0x0000	), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%apostrophe>                                       */ DEADTRANS( L' '	,0xE27E	,0x21C2	,0x0000	), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%aprightsinglequotemark>                           */ DEADTRANS( L'|'	,0xE27F	,0x2955	,0x0000	), // '|' ➔ "⥕" DOWNWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%exclam><%aprightsinglequotemark>                           */ DEADTRANS( 0x00A0	,0xE27F	,0x21C2	,0x0000	), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%aprightsinglequotemark>                           */ DEADTRANS( L' '	,0xE27F	,0x21C2	,0x0000	), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%bar>                                              */ DEADTRANS( L'!'	,0xE280	,0x2908	,0x0000	), // '!' ➔ "⤈" DOWNWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%exclam><%bar>                                              */ DEADTRANS( L'>'	,0xE280	,0x2908	,0x0000	), // '>' ➔ "⤈" DOWNWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%exclam>                                                    */ DEADTRANS( L'^'	,0xE281	,0x00A6	,0x0000	), // '^' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><%exclam><%exclam>                                           */ DEADTRANS( L'!'	,0xE282	,0x00A1	,0x0000	), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><%exclam><%grave>                                            */ DEADTRANS( L'|'	,0xE283	,0x2959	,0x0000	), // '|' ➔ "⥙" DOWNWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%exclam><%grave><%exclam>                                   */ DEADTRANS( L'\''	,0xE284	,0x2965	,0x0000	), // ''' ➔ "⥥" DOWNWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave><%exclam>                                   */ DEADTRANS( 0x2019	,0xE284	,0x2965	,0x0000	), // '’' ➔ "⥥" DOWNWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave>                                            */ DEADTRANS( L'`'	,0xE283	,0x296F	,0x0000	), // '`' ➔ "⥯" DOWNWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave>                                            */ DEADTRANS( 0x00A0	,0xE283	,0x21C3	,0x0000	), // ' ' ➔ "⇃" DOWNWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%exclam><%grave>                                            */ DEADTRANS( L' '	,0xE283	,0x21C3	,0x0000	), // ' ' ➔ "⇃" DOWNWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'|'	,0xE285	,0x2913	,0x0000	), // '|' ➔ "⤓" DOWNWARDS ARROW TO BAR
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'='	,0xE285	,0x21D3	,0x0000	), // '=' ➔ "⇓" DOWNWARDS DOUBLE ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'!'	,0xE285	,0x21CA	,0x0000	), // '!' ➔ "⇊" DOWNWARDS PAIRED ARROWS
/*<!M><%exclam><%greater><%greater>                                */ DEADTRANS( 0x00A0	,0xE286	,0x21A1	,0x0000	), // ' ' ➔ "↡" DOWNWARDS TWO HEADED ARROW
/*<!M><%exclam><%greater><%greater>                                */ DEADTRANS( L' '	,0xE286	,0x21A1	,0x0000	), // ' ' ➔ "↡" DOWNWARDS TWO HEADED ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'<'	,0xE285	,0x21F5	,0x0000	), // '<' ➔ "⇵" DOWNWARDS ARROW LEFTWARDS OF UPWARDS ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'2'	,0xE285	,0x21D3	,0x0000	), // '2' ➔ "⇓" DOWNWARDS DOUBLE ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'3'	,0xE285	,0x290B	,0x0000	), // '3' ➔ "⤋" DOWNWARDS TRIPLE ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'4'	,0xE285	,0x27F1	,0x0000	), // '4' ➔ "⟱" DOWNWARDS QUADRUPLE ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( 0x00A0	,0xE285	,0x2193	,0x0000	), // ' ' ➔ "↓" DOWNWARDS ARROW
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L' '	,0xE285	,0x2193	,0x0000	), // ' ' ➔ "↓" DOWNWARDS ARROW
/*<!M><%exclam><%minus>                                            */ DEADTRANS( L'>'	,0xE287	,0x21B1	,0x0000	), // '>' ➔ "↱" UPWARDS ARROW WITH TIP RIGHTWARDS
/*<!M><%exclam>                                                    */ DEADTRANS( L'?'	,0xE281	,0x2E18	,0x0000	), // '?' ➔ "⸘" INVERTED INTERROBANG
/*<!M><%exclam>                                                    */ DEADTRANS( L'p'	,0xE281	,0x204B	,0x0000	), // 'p' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%exclam>                                                    */ DEADTRANS( L'P'	,0xE281	,0x204B	,0x0000	), // 'P' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%exclam>comma><%minus>                                      */ DEADTRANS( L'>'	,0xE288	,0x2937	,0x0000	), // '>' ➔ "⤷" ARROW POINTING DOWNWARDS THEN CURVING RIGHTWARDS
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L'\''	,0xE289	,0x294F	,0x0000	), // ''' ➔ "⥏" UP BARB RIGHT DOWN BARB RIGHT HARPOON
/*<!M><%grave><%exclam>                                            */ DEADTRANS( 0x2019	,0xE289	,0x294F	,0x0000	), // '’' ➔ "⥏" UP BARB RIGHT DOWN BARB RIGHT HARPOON
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L'|'	,0xE289	,0x295C	,0x0000	), // '|' ➔ "⥜" UPWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L'`'	,0xE289	,0x294C	,0x0000	), // '`' ➔ "⥌" UP BARB RIGHT DOWN BARB LEFT HARPOON
/*<!M><%grave><%exclam>                                            */ DEADTRANS( 0x00A0	,0xE289	,0x21BE	,0x0000	), // ' ' ➔ "↾" UPWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L' '	,0xE289	,0x21BE	,0x0000	), // ' ' ➔ "↾" UPWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%grave><%minus>                                             */ DEADTRANS( L'\''	,0xE28A	,0x2950	,0x0000	), // ''' ➔ "⥐" LEFT BARB DOWN RIGHT BARB DOWN HARPOON
/*<!M><%grave><%minus>                                             */ DEADTRANS( 0x2019	,0xE28A	,0x2950	,0x0000	), // '’' ➔ "⥐" LEFT BARB DOWN RIGHT BARB DOWN HARPOON
/*<!M><%grave><%minus>                                             */ DEADTRANS( L'|'	,0xE28A	,0x295E	,0x0000	), // '|' ➔ "⥞" LEFTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%grave><%minus>                                             */ DEADTRANS( L'`'	,0xE28A	,0x294B	,0x0000	), // '`' ➔ "⥋" LEFT BARB DOWN RIGHT BARB UP HARPOON
/*<!M><%grave><%minus><%minus>                                     */ DEADTRANS( L'\''	,0xE28B	,0x2967	,0x0000	), // ''' ➔ "⥧" LEFTWARDS HARPOON WITH BARB DOWN ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%grave><%minus><%minus>                                     */ DEADTRANS( 0x2019	,0xE28B	,0x2967	,0x0000	), // '’' ➔ "⥧" LEFTWARDS HARPOON WITH BARB DOWN ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%grave><%minus>                                             */ DEADTRANS( 0x00A0	,0xE28A	,0x21BD	,0x0000	), // ' ' ➔ "↽" LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%grave><%minus>                                             */ DEADTRANS( L' '	,0xE28A	,0x21BD	,0x0000	), // ' ' ➔ "↽" LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( 0x00A0	,0xE28C	,0x22EB	,0x0000	), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( L' '	,0xE28C	,0x22EB	,0x0000	), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%greater>                                                   */ DEADTRANS( L'['	,0xE28D	,0x27E9	,0x0000	), // '[' ➔ "⟩" MATHEMATICAL RIGHT ANGLE BRACKET
/*<!M><%greater>                                                   */ DEADTRANS( L']'	,0xE28D	,0x27E9	,0x0000	), // ']' ➔ "⟩" MATHEMATICAL RIGHT ANGLE BRACKET
/*<!M><%greater><%equal>                                           */ DEADTRANS( L'`'	,0xE28E	,0x2AFA	,0x0000	), // '`' ➔ "⫺" DOUBLE-LINE SLANTED GREATER-THAN OR EQUAL TO
/*<!M><%greater><%equal>                                           */ DEADTRANS( L'<'	,0xE28E	,0x2A8C	,0x0000	), // '<' ➔ "⪌" GREATER-THAN ABOVE DOUBLE-LINE EQUAL ABOVE LESS-THAN
/*<!M><%greater><%equal>                                           */ DEADTRANS( L'/'	,0xE28E	,0x2269	,0x0000	), // '/' ➔ "≩" GREATER-THAN BUT NOT EQUAL TO
/*<!M><%greater><%equal>                                           */ DEADTRANS( 0x00A0	,0xE28E	,0x2267	,0x0000	), // ' ' ➔ "≧" GREATER-THAN OVER EQUAL TO
/*<!M><%greater><%equal>                                           */ DEADTRANS( L' '	,0xE28E	,0x2267	,0x0000	), // ' ' ➔ "≧" GREATER-THAN OVER EQUAL TO
/*<!M><%greater><%greater>                                         */ DEADTRANS( L'['	,0xE28F	,0x27EB	,0x0000	), // '[' ➔ "⟫" MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*<!M><%greater><%greater>                                         */ DEADTRANS( L']'	,0xE28F	,0x27EB	,0x0000	), // ']' ➔ "⟫" MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*<!M><%greater><%greater>                                         */ DEADTRANS( L'-'	,0xE28F	,0x291C	,0x0000	), // '-' ➔ "⤜" RIGHTWARDS DOUBLE ARROW-TAIL
/*<!M><%greater><%greater>                                         */ DEADTRANS( L'('	,0xE28F	,0x2ABC	,0x0000	), // '(' ➔ "⪼" DOUBLE SUCCEEDS
/*<!M><%greater><%greater>                                         */ DEADTRANS( L')'	,0xE28F	,0x2ABC	,0x0000	), // ')' ➔ "⪼" DOUBLE SUCCEEDS
/*<!M><%greater><%less>                                            */ DEADTRANS( L'='	,0xE290	,0x2A92	,0x0000	), // '=' ➔ "⪒" GREATER-THAN ABOVE LESS-THAN ABOVE DOUBLE-LINE EQUAL
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L'-'	,0xE291	,0x27E3	,0x0000	), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( 0x00A0	,0xE291	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L' '	,0xE291	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L'-'	,0xE292	,0x27E3	,0x0000	), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( 0x00A0	,0xE292	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L' '	,0xE292	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less>                                            */ DEADTRANS( L'/'	,0xE290	,0x2279	,0x0000	), // '/' ➔ "≹" NEITHER GREATER-THAN NOR LESS-THAN
/*<!M><%greater><%less>                                            */ DEADTRANS( 0x00A0	,0xE290	,0x2277	,0x0000	), // ' ' ➔ "≷" GREATER-THAN OR LESS-THAN
/*<!M><%greater><%less>                                            */ DEADTRANS( L' '	,0xE290	,0x2277	,0x0000	), // ' ' ➔ "≷" GREATER-THAN OR LESS-THAN
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L'>'	,0xE293	,0x2918	,0x0000	), // '>' ➔ "⤘" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( 0x00A0	,0xE293	,0x2915	,0x0000	), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L' '	,0xE293	,0x2915	,0x0000	), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L'>'	,0xE294	,0x2918	,0x0000	), // '>' ➔ "⤘" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( 0x00A0	,0xE294	,0x2915	,0x0000	), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L' '	,0xE294	,0x2915	,0x0000	), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L'>'	,0xE295	,0x2917	,0x0000	), // '>' ➔ "⤗" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( 0x00A0	,0xE295	,0x2914	,0x0000	), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L' '	,0xE295	,0x2914	,0x0000	), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L'>'	,0xE296	,0x2917	,0x0000	), // '>' ➔ "⤗" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( 0x00A0	,0xE296	,0x2914	,0x0000	), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L' '	,0xE296	,0x2914	,0x0000	), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%greater>                                 */ DEADTRANS( L'>'	,0xE297	,0x2916	,0x0000	), // '>' ➔ "⤖" RIGHTWARDS TWO-HEADED ARROW WITH TAIL
/*<!M><%greater><%minus><%greater>                                 */ DEADTRANS( 0x00A0	,0xE297	,0x21A3	,0x0000	), // ' ' ➔ "↣" RIGHTWARDS ARROW WITH TAIL
/*<!M><%greater><%minus><%greater>                                 */ DEADTRANS( L' '	,0xE297	,0x21A3	,0x0000	), // ' ' ➔ "↣" RIGHTWARDS ARROW WITH TAIL
/*<!M><%greater><%minus>                                           */ DEADTRANS( L'_'	,0xE298	,0x2AAD	,0x0000	), // '_' ➔ "⪭" LARGER THAN OR EQUAL TO
/*<!M><%greater><%minus>                                           */ DEADTRANS( L'0'	,0xE298	,0x2910	,0x0000	), // '0' ➔ "⤐" RIGHTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%greater><%minus>                                           */ DEADTRANS( 0x00A0	,0xE298	,0x291A	,0x0000	), // ' ' ➔ "⤚" RIGHTWARDS ARROW-TAIL
/*<!M><%greater><%minus>                                           */ DEADTRANS( L' '	,0xE298	,0x291A	,0x0000	), // ' ' ➔ "⤚" RIGHTWARDS ARROW-TAIL
/*<!M><%greater><%parenleft>                                       */ DEADTRANS( L'('	,0xE299	,0x2995	,0x0000	), // '(' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L'['	,0xE29A	,0x29FD	,0x0000	), // '[' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L']'	,0xE29A	,0x29FD	,0x0000	), // ']' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenleft><%parenright><%equal>                  */ DEADTRANS( L'/'	,0xE29B	,0x2AB6	,0x0000	), // '/' ➔ "⪶" SUCCEEDS ABOVE NOT EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%equal>                  */ DEADTRANS( 0x00A0	,0xE29B	,0x2AB4	,0x0000	), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><%equal>                  */ DEADTRANS( L' '	,0xE29B	,0x2AB4	,0x0000	), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L'/'	,0xE29A	,0x2281	,0x0000	), // '/' ➔ "⊁" DOES NOT SUCCEED
/*<!M><%greater><%parenleft><%parenright><%tilde>                  */ DEADTRANS( L'/'	,0xE29C	,0x22E9	,0x0000	), // '/' ➔ "⋩" SUCCEEDS BUT NOT EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde>          */ DEADTRANS( L'/'	,0xE29D	,0x2ABA	,0x0000	), // '/' ➔ "⪺" SUCCEEDS ABOVE NOT ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde>          */ DEADTRANS( 0x00A0	,0xE29D	,0x2AB8	,0x0000	), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde>          */ DEADTRANS( L' '	,0xE29D	,0x2AB8	,0x0000	), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde>                  */ DEADTRANS( 0x00A0	,0xE29C	,0x227F	,0x0000	), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%tilde>                  */ DEADTRANS( L' '	,0xE29C	,0x227F	,0x0000	), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%underscore>             */ DEADTRANS( L'/'	,0xE29E	,0x2AB2	,0x0000	), // '/' ➔ "⪲" SUCCEEDS ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%underscore>             */ DEADTRANS( 0x00A0	,0xE29E	,0x2AB0	,0x0000	), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><%underscore>             */ DEADTRANS( L' '	,0xE29E	,0x2AB0	,0x0000	), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( 0x00A0	,0xE29A	,0x227B	,0x0000	), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L' '	,0xE29A	,0x227B	,0x0000	), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'['	,0xE29F	,0x29FD	,0x0000	), // '[' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L']'	,0xE29F	,0x29FD	,0x0000	), // ']' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenright><%parenleft><%equal>                  */ DEADTRANS( L'/'	,0xE2A0	,0x2AB6	,0x0000	), // '/' ➔ "⪶" SUCCEEDS ABOVE NOT EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%equal>                  */ DEADTRANS( 0x00A0	,0xE2A0	,0x2AB4	,0x0000	), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><%equal>                  */ DEADTRANS( L' '	,0xE2A0	,0x2AB4	,0x0000	), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'/'	,0xE29F	,0x2281	,0x0000	), // '/' ➔ "⊁" DOES NOT SUCCEED
/*<!M><%greater><%parenright><%parenleft><%tilde>                  */ DEADTRANS( L'/'	,0xE2A1	,0x22E9	,0x0000	), // '/' ➔ "⋩" SUCCEEDS BUT NOT EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde>          */ DEADTRANS( L'/'	,0xE2A2	,0x2ABA	,0x0000	), // '/' ➔ "⪺" SUCCEEDS ABOVE NOT ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde>          */ DEADTRANS( 0x00A0	,0xE2A2	,0x2AB8	,0x0000	), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde>          */ DEADTRANS( L' '	,0xE2A2	,0x2AB8	,0x0000	), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde>                  */ DEADTRANS( 0x00A0	,0xE2A1	,0x227F	,0x0000	), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%tilde>                  */ DEADTRANS( L' '	,0xE2A1	,0x227F	,0x0000	), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%underscore>             */ DEADTRANS( L'/'	,0xE2A3	,0x2AB2	,0x0000	), // '/' ➔ "⪲" SUCCEEDS ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%underscore>             */ DEADTRANS( 0x00A0	,0xE2A3	,0x2AB0	,0x0000	), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><%underscore>             */ DEADTRANS( L' '	,0xE2A3	,0x2AB0	,0x0000	), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( 0x00A0	,0xE29F	,0x227B	,0x0000	), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L' '	,0xE29F	,0x227B	,0x0000	), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%period>                                          */ DEADTRANS( L'_'	,0xE2A4	,0x2A82	,0x0000	), // '_' ➔ "⪂" GREATER-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!M><%greater><%period>                                          */ DEADTRANS( 0x00A0	,0xE2A4	,0x22D7	,0x0000	), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%greater><%period>                                          */ DEADTRANS( L' '	,0xE2A4	,0x22D7	,0x0000	), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%greater><%slash>                                           */ DEADTRANS( L'~'	,0xE2A5	,0x2275	,0x0000	), // '~' ➔ "≵" NEITHER GREATER-THAN NOR EQUIVALENT TO
/*<!M><%greater><%slash>                                           */ DEADTRANS( L'_'	,0xE2A5	,0x2271	,0x0000	), // '_' ➔ "≱" NEITHER GREATER-THAN NOR EQUAL TO
/*<!M><%greater><%slash>                                           */ DEADTRANS( 0x00A0	,0xE2A5	,0x226F	,0x0000	), // ' ' ➔ "≯" NOT GREATER-THAN
/*<!M><%greater><%slash>                                           */ DEADTRANS( L' '	,0xE2A5	,0x226F	,0x0000	), // ' ' ➔ "≯" NOT GREATER-THAN
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'<'	,0xE2A6	,0x2A90	,0x0000	), // '<' ➔ "⪐" GREATER-THAN ABOVE SIMILAR ABOVE LESS-THAN
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'-'	,0xE2A6	,0x2A8E	,0x0000	), // '-' ➔ "⪎" GREATER-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'/'	,0xE2A6	,0x22E7	,0x0000	), // '/' ➔ "⋧" GREATER-THAN BUT NOT EQUIVALENT TO
/*<!M><%greater><%tilde><%tilde>                                   */ DEADTRANS( L'/'	,0xE2A7	,0x2A8A	,0x0000	), // '/' ➔ "⪊" GREATER-THAN AND NOT APPROXIMATE
/*<!M><%greater><%tilde><%tilde>                                   */ DEADTRANS( 0x00A0	,0xE2A7	,0x2A86	,0x0000	), // ' ' ➔ "⪆" GREATER-THAN OR APPROXIMATE
/*<!M><%greater><%tilde><%tilde>                                   */ DEADTRANS( L' '	,0xE2A7	,0x2A86	,0x0000	), // ' ' ➔ "⪆" GREATER-THAN OR APPROXIMATE
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'_'	,0xE2A6	,0x2A8E	,0x0000	), // '_' ➔ "⪎" GREATER-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%greater><%tilde>                                           */ DEADTRANS( 0x00A0	,0xE2A6	,0x2273	,0x0000	), // ' ' ➔ "≳" GREATER-THAN OR EQUIVALENT TO
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L' '	,0xE2A6	,0x2273	,0x0000	), // ' ' ➔ "≳" GREATER-THAN OR EQUIVALENT TO
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L'`'	,0xE2A8	,0x2A7E	,0x0000	), // '`' ➔ "⩾" GREATER-THAN OR SLANTED EQUAL TO
/*<!M><%greater><%underscore><%less>                               */ DEADTRANS( L'_'	,0xE2A9	,0x2A94	,0x0000	), // '_' ➔ "⪔" GREATER-THAN ABOVE SLANTED EQUAL ABOVE LESS-THAN ABOVE SLANTED EQUAL
/*<!M><%greater><%underscore><%less>                               */ DEADTRANS( 0x00A0	,0xE2A9	,0x22DB	,0x0000	), // ' ' ➔ "⋛" GREATER-THAN EQUAL TO OR LESS-THAN
/*<!M><%greater><%underscore><%less>                               */ DEADTRANS( L' '	,0xE2A9	,0x22DB	,0x0000	), // ' ' ➔ "⋛" GREATER-THAN EQUAL TO OR LESS-THAN
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L'/'	,0xE2AA	,0x22E1	,0x0000	), // '/' ➔ "⋡" DOES NOT SUCCEED OR EQUAL
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( 0x00A0	,0xE2AA	,0x227D	,0x0000	), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L' '	,0xE2AA	,0x227D	,0x0000	), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L'/'	,0xE2AB	,0x22E1	,0x0000	), // '/' ➔ "⋡" DOES NOT SUCCEED OR EQUAL
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( 0x00A0	,0xE2AB	,0x227D	,0x0000	), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L' '	,0xE2AB	,0x227D	,0x0000	), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L'.'	,0xE2A8	,0x2A80	,0x0000	), // '.' ➔ "⪀" GREATER-THAN OR SLANTED EQUAL TO WITH DOT INSIDE
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L'/'	,0xE2A8	,0x2A88	,0x0000	), // '/' ➔ "⪈" GREATER-THAN AND SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%underscore>                                      */ DEADTRANS( 0x00A0	,0xE2A8	,0x2265	,0x0000	), // ' ' ➔ "≥" GREATER-THAN OR EQUAL TO
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L' '	,0xE2A8	,0x2265	,0x0000	), // ' ' ➔ "≥" GREATER-THAN OR EQUAL TO
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'='	,0xE2AC	,0x21D6	,0x0000	), // '=' ➔ "⇖" NORTH WEST DOUBLE ARROW
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'>'	,0xE2AC	,0x2921	,0x0000	), // '>' ➔ "⤡" NORTH WEST AND SOUTH EAST ARROW
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'<'	,0xE2AC	,0x292A	,0x0000	), // '<' ➔ "⤪" SOUTH WEST ARROW AND NORTH WEST ARROW
/*<!M><%less><%backslash><%parenleft>                              */ DEADTRANS( L'-'	,0xE2AD	,0x29A9	,0x0000	), // '-' ➔ "⦩" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING UP AND LEFT
/*<!M><%less><%backslash>                                          */ DEADTRANS( L')'	,0xE2AC	,0x2923	,0x0000	), // ')' ➔ "⤣" NORTH WEST ARROW WITH HOOK
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'/'	,0xE2AC	,0x2927	,0x0000	), // '/' ➔ "⤧" NORTH WEST ARROW AND NORTH EAST ARROW
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'2'	,0xE2AC	,0x21D6	,0x0000	), // '2' ➔ "⇖" NORTH WEST DOUBLE ARROW
/*<!M><%less><%backslash>                                          */ DEADTRANS( 0x00A0	,0xE2AC	,0x2196	,0x0000	), // ' ' ➔ "↖" NORTH WEST ARROW
/*<!M><%less><%backslash>                                          */ DEADTRANS( L' '	,0xE2AC	,0x2196	,0x0000	), // ' ' ➔ "↖" NORTH WEST ARROW
/*<!M><%less><%bar><%bar><%minus>                                  */ DEADTRANS( L'<'	,0xE2AE	,0x2B3A	,0x0000	), // '<' ➔ "⬺" LEFTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar><%minus>                                  */ DEADTRANS( 0x00A0	,0xE2AE	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar><%minus>                                  */ DEADTRANS( L' '	,0xE2AE	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar>                                          */ DEADTRANS( 0x00A0	,0xE2AF	,0x29CF	,0x0000	), // ' ' ➔ "⧏" LEFT TRIANGLE BESIDE VERTICAL BAR
/*<!M><%less><%bar><%bar>                                          */ DEADTRANS( L' '	,0xE2AF	,0x29CF	,0x0000	), // ' ' ➔ "⧏" LEFT TRIANGLE BESIDE VERTICAL BAR
/*<!M><%less><%bar>                                                */ DEADTRANS( L'='	,0xE2B0	,0x2902	,0x0000	), // '=' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%bar>                                                */ DEADTRANS( L'!'	,0xE2B0	,0x2909	,0x0000	), // '!' ➔ "⤉" UPWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( L'|'	,0xE2B1	,0x21FF	,0x0000	), // '|' ➔ "⇿" LEFT RIGHT OPEN-HEADED ARROW
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( L'<'	,0xE2B1	,0x2B39	,0x0000	), // '<' ➔ "⬹" LEFTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( 0x00A0	,0xE2B1	,0x21FD	,0x0000	), // ' ' ➔ "⇽" LEFTWARDS OPEN-HEADED ARROW
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( L' '	,0xE2B1	,0x21FD	,0x0000	), // ' ' ➔ "⇽" LEFTWARDS OPEN-HEADED ARROW
/*<!M><%less><%bar><%slash>                                        */ DEADTRANS( L'_'	,0xE2B2	,0x22EC	,0x0000	), // '_' ➔ "⋬" NOT NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%slash>                                        */ DEADTRANS( 0x00A0	,0xE2B2	,0x22EA	,0x0000	), // ' ' ➔ "⋪" NOT NORMAL SUBGROUP OF
/*<!M><%less><%bar><%slash>                                        */ DEADTRANS( L' '	,0xE2B2	,0x22EA	,0x0000	), // ' ' ➔ "⋪" NOT NORMAL SUBGROUP OF
/*<!M><%less><%bar><%underscore>                                   */ DEADTRANS( L'/'	,0xE2B3	,0x22EC	,0x0000	), // '/' ➔ "⋬" NOT NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%underscore>                                   */ DEADTRANS( 0x00A0	,0xE2B3	,0x22B4	,0x0000	), // ' ' ➔ "⊴" NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%underscore>                                   */ DEADTRANS( L' '	,0xE2B3	,0x22B4	,0x0000	), // ' ' ➔ "⊴" NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar>                                                */ DEADTRANS( 0x00A0	,0xE2B0	,0x22B2	,0x0000	), // ' ' ➔ "⊲" NORMAL SUBGROUP OF
/*<!M><%less><%bar>                                                */ DEADTRANS( L' '	,0xE2B0	,0x22B2	,0x0000	), // ' ' ➔ "⊲" NORMAL SUBGROUP OF
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'>'	,0xE2B4	,0x25CA	,0x0000	), // '>' ➔ "◊" LOZENGE
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'#'	,0xE2B4	,0x29EB	,0x0000	), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'-'	,0xE2B4	,0x27E0	,0x0000	), // '-' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'.'	,0xE2B4	,0x2991	,0x0000	), // '.' ➔ "⦑" LEFT ANGLE BRACKET WITH DOT
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( 0x00A0	,0xE2B4	,0x27E8	,0x0000	), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L' '	,0xE2B4	,0x27E8	,0x0000	), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L'>'	,0xE2B5	,0x25CA	,0x0000	), // '>' ➔ "◊" LOZENGE
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L'#'	,0xE2B5	,0x29EB	,0x0000	), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L'-'	,0xE2B5	,0x27E0	,0x0000	), // '-' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L'.'	,0xE2B5	,0x2991	,0x0000	), // '.' ➔ "⦑" LEFT ANGLE BRACKET WITH DOT
/*<!M><%less><%bracketright>                                       */ DEADTRANS( 0x00A0	,0xE2B5	,0x27E8	,0x0000	), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L' '	,0xE2B5	,0x27E8	,0x0000	), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%equal><%bar><%equal>                                */ DEADTRANS( L'>'	,0xE2B6	,0x2904	,0x0000	), // '>' ➔ "⤄" LEFT RIGHT DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar><%equal>                                */ DEADTRANS( 0x00A0	,0xE2B6	,0x2902	,0x0000	), // ' ' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar><%equal>                                */ DEADTRANS( L' '	,0xE2B6	,0x2902	,0x0000	), // ' ' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar>                                        */ DEADTRANS( 0x00A0	,0xE2B7	,0x2906	,0x0000	), // ' ' ➔ "⤆" LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%bar>                                        */ DEADTRANS( L' '	,0xE2B7	,0x2906	,0x0000	), // ' ' ➔ "⤆" LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( L'|'	,0xE2B8	,0x27FD	,0x0000	), // '|' ➔ "⟽" LONG LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( L'>'	,0xE2B8	,0x27FA	,0x0000	), // '>' ➔ "⟺" LONG LEFT RIGHT DOUBLE ARROW
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( 0x00A0	,0xE2B8	,0x27F8	,0x0000	), // ' ' ➔ "⟸" LONG LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( L' '	,0xE2B8	,0x27F8	,0x0000	), // ' ' ➔ "⟸" LONG LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal>                                              */ DEADTRANS( L'`'	,0xE2B9	,0x2AF9	,0x0000	), // '`' ➔ "⫹" DOUBLE-LINE SLANTED LESS-THAN OR EQUAL TO
/*<!M><%less><%equal>                                              */ DEADTRANS( L'>'	,0xE2B9	,0x21D4	,0x0000	), // '>' ➔ "⇔" LEFT RIGHT DOUBLE ARROW
/*<!M><%less><%equal><%slash>                                      */ DEADTRANS( L'>'	,0xE2BA	,0x21CE	,0x0000	), // '>' ➔ "⇎" LEFT RIGHT DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal><%slash>                                      */ DEADTRANS( 0x00A0	,0xE2BA	,0x21CD	,0x0000	), // ' ' ➔ "⇍" LEFTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal><%slash>                                      */ DEADTRANS( L' '	,0xE2BA	,0x21CD	,0x0000	), // ' ' ➔ "⇍" LEFTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal>                                              */ DEADTRANS( 0x00A0	,0xE2B9	,0x21D0	,0x0000	), // ' ' ➔ "⇐" LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal>                                              */ DEADTRANS( L' '	,0xE2B9	,0x21D0	,0x0000	), // ' ' ➔ "⇐" LEFTWARDS DOUBLE ARROW
/*<!M><%less><%exclam><%bar>                                       */ DEADTRANS( L'!'	,0xE2BB	,0x2909	,0x0000	), // '!' ➔ "⤉" UPWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%less><%exclam><%bar>                                       */ DEADTRANS( 0x00A0	,0xE2BB	,0x21A5	,0x0000	), // ' ' ➔ "↥" UPWARDS ARROW FROM BAR
/*<!M><%less><%exclam><%bar>                                       */ DEADTRANS( L' '	,0xE2BB	,0x21A5	,0x0000	), // ' ' ➔ "↥" UPWARDS ARROW FROM BAR
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'='	,0xE2BC	,0x21D1	,0x0000	), // '=' ➔ "⇑" UPWARDS DOUBLE ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'!'	,0xE2BC	,0x21C5	,0x0000	), // '!' ➔ "⇅" UPWARDS ARROW LEFTWARDS OF DOWNWARDS ARROW
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L'|'	,0xE2BD	,0x21A8	,0x0000	), // '|' ➔ "↨" UP DOWN ARROW WITH BASE
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L'='	,0xE2BD	,0x21D5	,0x0000	), // '=' ➔ "⇕" UP DOWN DOUBLE ARROW
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L'2'	,0xE2BD	,0x21D5	,0x0000	), // '2' ➔ "⇕" UP DOWN DOUBLE ARROW
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( 0x00A0	,0xE2BD	,0x2195	,0x0000	), // ' ' ➔ "↕" UP DOWN ARROW
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L' '	,0xE2BD	,0x2195	,0x0000	), // ' ' ➔ "↕" UP DOWN ARROW
/*<!M><%less><%exclam><%less>                                      */ DEADTRANS( L'!'	,0xE2BE	,0x21C8	,0x0000	), // '!' ➔ "⇈" UPWARDS PAIRED ARROWS
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'2'	,0xE2BC	,0x21D1	,0x0000	), // '2' ➔ "⇑" UPWARDS DOUBLE ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'3'	,0xE2BC	,0x290A	,0x0000	), // '3' ➔ "⤊" UPWARDS TRIPLE ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'4'	,0xE2BC	,0x27F0	,0x0000	), // '4' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( 0x00A0	,0xE2BC	,0x2191	,0x0000	), // ' ' ➔ "↑" UPWARDS ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( L' '	,0xE2BC	,0x2191	,0x0000	), // ' ' ➔ "↑" UPWARDS ARROW
/*<!M><%less><%greater>                                            */ DEADTRANS( L'='	,0xE2BF	,0x2A91	,0x0000	), // '=' ➔ "⪑" LESS-THAN ABOVE GREATER-THAN ABOVE DOUBLE-LINE EQUAL
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L'|'	,0xE2C0	,0x291F	,0x0000	), // '|' ➔ "⤟" LEFTWARDS ARROW FROM BAR TO BLACK DIAMOND
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( 0x00A0	,0xE2C0	,0x291D	,0x0000	), // ' ' ➔ "⤝" LEFTWARDS ARROW TO BLACK DIAMOND
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L' '	,0xE2C0	,0x291D	,0x0000	), // ' ' ➔ "⤝" LEFTWARDS ARROW TO BLACK DIAMOND
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L'-'	,0xE2C1	,0x27E3	,0x0000	), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( 0x00A0	,0xE2C1	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L' '	,0xE2C1	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L'-'	,0xE2C2	,0x27E3	,0x0000	), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( 0x00A0	,0xE2C2	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L' '	,0xE2C2	,0x27E1	,0x0000	), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater>                                            */ DEADTRANS( L'/'	,0xE2BF	,0x2278	,0x0000	), // '/' ➔ "≸" NEITHER LESS-THAN NOR GREATER-THAN
/*<!M><%less><%greater>                                            */ DEADTRANS( 0x00A0	,0xE2BF	,0x2276	,0x0000	), // ' ' ➔ "≶" LESS-THAN OR GREATER-THAN
/*<!M><%less><%greater>                                            */ DEADTRANS( L' '	,0xE2BF	,0x2276	,0x0000	), // ' ' ➔ "≶" LESS-THAN OR GREATER-THAN
/*<!M><%less><%hash><%greater>                                     */ DEADTRANS( L'!'	,0xE2C3	,0x29EA	,0x0000	), // '!' ➔ "⧪" BLACK DIAMOND WITH DOWN ARROW
/*<!M><%less><%hash><%greater>                                     */ DEADTRANS( 0x00A0	,0xE2C3	,0x25C6	,0x0000	), // ' ' ➔ "◆" BLACK DIAMOND
/*<!M><%less><%hash><%greater>                                     */ DEADTRANS( L' '	,0xE2C3	,0x25C6	,0x0000	), // ' ' ➔ "◆" BLACK DIAMOND
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L'<'	,0xE2C4	,0x2B3D	,0x0000	), // '<' ➔ "⬽" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( 0x00A0	,0xE2C4	,0x2B35	,0x0000	), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L' '	,0xE2C4	,0x2B35	,0x0000	), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L'<'	,0xE2C5	,0x2B3C	,0x0000	), // '<' ➔ "⬼" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( 0x00A0	,0xE2C5	,0x2B34	,0x0000	), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L' '	,0xE2C5	,0x2B34	,0x0000	), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less>                                               */ DEADTRANS( L'['	,0xE2C6	,0x27EA	,0x0000	), // '[' ➔ "⟪" MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*<!M><%less><%less>                                               */ DEADTRANS( L']'	,0xE2C6	,0x27EA	,0x0000	), // ']' ➔ "⟪" MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*<!M><%less><%less><%exclam>                                      */ DEADTRANS( L'o'	,0xE2C7	,0x2949	,0x0000	), // 'o' ➔ "⥉" UPWARDS TWO-HEADED ARROW FROM SMALL CIRCLE
/*<!M><%less><%less><%exclam>                                      */ DEADTRANS( 0x00A0	,0xE2C7	,0x219F	,0x0000	), // ' ' ➔ "↟" UPWARDS TWO HEADED ARROW
/*<!M><%less><%less><%exclam>                                      */ DEADTRANS( L' '	,0xE2C7	,0x219F	,0x0000	), // ' ' ➔ "↟" UPWARDS TWO HEADED ARROW
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L'<'	,0xE2C8	,0x2B3D	,0x0000	), // '<' ➔ "⬽" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( 0x00A0	,0xE2C8	,0x2B35	,0x0000	), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L' '	,0xE2C8	,0x2B35	,0x0000	), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L'<'	,0xE2C9	,0x2B3C	,0x0000	), // '<' ➔ "⬼" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( 0x00A0	,0xE2C9	,0x2B34	,0x0000	), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L' '	,0xE2C9	,0x2B34	,0x0000	), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( L'<'	,0xE2CA	,0x2B3B	,0x0000	), // '<' ➔ "⬻" LEFTWARDS TWO-HEADED ARROW WITH TAIL
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( L'0'	,0xE2CA	,0x2B37	,0x0000	), // '0' ➔ "⬷" LEFTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( 0x00A0	,0xE2CA	,0x219E	,0x0000	), // ' ' ➔ "↞" LEFTWARDS TWO HEADED ARROW
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( L' '	,0xE2CA	,0x219E	,0x0000	), // ' ' ➔ "↞" LEFTWARDS TWO HEADED ARROW
/*<!M><%less><%less>                                               */ DEADTRANS( L'('	,0xE2C6	,0x2ABB	,0x0000	), // '(' ➔ "⪻" DOUBLE PRECEDES
/*<!M><%less><%less>                                               */ DEADTRANS( L')'	,0xE2C6	,0x2ABB	,0x0000	), // ')' ➔ "⪻" DOUBLE PRECEDES
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( L'>'	,0xE2CB	,0x21FC	,0x0000	), // '>' ➔ "⇼" LEFT RIGHT ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( L'<'	,0xE2CB	,0x2B3A	,0x0000	), // '<' ➔ "⬺" LEFTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( 0x00A0	,0xE2CB	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( L' '	,0xE2CB	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar>                                  */ DEADTRANS( 0x00A0	,0xE2CC	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar>                                  */ DEADTRANS( L' '	,0xE2CC	,0x21FA	,0x0000	), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar>                                        */ DEADTRANS( L'>'	,0xE2CD	,0x21F9	,0x0000	), // '>' ➔ "⇹" LEFT RIGHT ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( L'>'	,0xE2CE	,0x21F9	,0x0000	), // '>' ➔ "⇹" LEFT RIGHT ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( L'<'	,0xE2CE	,0x2B39	,0x0000	), // '<' ➔ "⬹" LEFTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( 0x00A0	,0xE2CE	,0x21F7	,0x0000	), // ' ' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( L' '	,0xE2CE	,0x21F7	,0x0000	), // ' ' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar>                                        */ DEADTRANS( 0x00A0	,0xE2CD	,0x21A4	,0x0000	), // ' ' ➔ "↤" LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%bar>                                        */ DEADTRANS( L' '	,0xE2CD	,0x21A4	,0x0000	), // ' ' ➔ "↤" LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%comma>                                      */ DEADTRANS( L'!'	,0xE2CF	,0x2936	,0x0000	), // '!' ➔ "⤶" ARROW POINTING DOWNWARDS THEN CURVING LEFTWARDS
/*<!M><%less><%minus><%comma>                                      */ DEADTRANS( L'-'	,0xE2CF	,0xDCD8	,0x0000	), // High surrogate: D83E; U+1F8D8 '-' ➔ "🣘" LONG LEFT RIGHT ARROW WITH DEPENDENT LOBE
/*<!M><%less><%minus>                                              */ DEADTRANS( L'!'	,0xE2D0	,0x21B0	,0x0000	), // '!' ➔ "↰" UPWARDS ARROW WITH TIP LEFTWARDS
/*<!M><%less><%minus>                                              */ DEADTRANS( L'>'	,0xE2D0	,0x2194	,0x0000	), // '>' ➔ "↔" LEFT RIGHT ARROW
/*<!M><%less><%minus><%less><%minus>                               */ DEADTRANS( L'<'	,0xE2D1	,0x2B31	,0x0000	), // '<' ➔ "⬱" THREE LEFTWARDS ARROWS
/*<!M><%less><%minus><%less><%minus>                               */ DEADTRANS( 0x00A0	,0xE2D1	,0x21C7	,0x0000	), // ' ' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><%less><%minus><%less><%minus>                               */ DEADTRANS( L' '	,0xE2D1	,0x21C7	,0x0000	), // ' ' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><%less><%minus><%less>                                       */ DEADTRANS( 0x00A0	,0xE2D2	,0x21A2	,0x0000	), // ' ' ➔ "↢" LEFTWARDS ARROW WITH TAIL
/*<!M><%less><%minus><%less>                                       */ DEADTRANS( L' '	,0xE2D2	,0x21A2	,0x0000	), // ' ' ➔ "↢" LEFTWARDS ARROW WITH TAIL
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( L'|'	,0xE2D3	,0x27FB	,0x0000	), // '|' ➔ "⟻" LONG LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( L'>'	,0xE2D3	,0x21C6	,0x0000	), // '>' ➔ "⇆" LEFTWARDS ARROW OVER RIGHTWARDS ARROW
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( 0x00A0	,0xE2D3	,0x27F5	,0x0000	), // ' ' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( L' '	,0xE2D3	,0x27F5	,0x0000	), // ' ' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L')'	,0xE2D0	,0x21A9	,0x0000	), // ')' ➔ "↩" LEFTWARDS ARROW WITH HOOK
/*<!M><%less><%minus>                                              */ DEADTRANS( L'.'	,0xE2D0	,0x2943	,0x0000	), // '.' ➔ "⥃" LEFTWARDS ARROW ABOVE SHORT RIGHTWARDS ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L'+'	,0xE2D0	,0x2946	,0x0000	), // '+' ➔ "⥆" LEFTWARDS ARROW WITH PLUS BELOW
/*<!M><%less><%minus><%slash>                                      */ DEADTRANS( L'-'	,0xE2D4	,0x21AE	,0x0000	), // '-' ➔ "↮" LEFT RIGHT ARROW WITH STROKE
/*<!M><%less><%minus><%slash>                                      */ DEADTRANS( 0x00A0	,0xE2D4	,0x219A	,0x0000	), // ' ' ➔ "↚" LEFTWARDS ARROW WITH STROKE
/*<!M><%less><%minus><%slash>                                      */ DEADTRANS( L' '	,0xE2D4	,0x219A	,0x0000	), // ' ' ➔ "↚" LEFTWARDS ARROW WITH STROKE
/*<!M><%less><%minus><%tilde>                                      */ DEADTRANS( L'\\'	,0xE2D5	,0x2B4B	,0x0000	), // '\' ➔ "⭋" LEFTWARDS ARROW ABOVE REVERSE TILDE OPERATOR
/*<!M><%less><%minus><%tilde><%tilde>                              */ DEADTRANS( L'\\'	,0xE2D6	,0x2B42	,0x0000	), // '\' ➔ "⭂" LEFTWARDS ARROW ABOVE REVERSE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde><%tilde>                              */ DEADTRANS( 0x00A0	,0xE2D6	,0x2B4A	,0x0000	), // ' ' ➔ "⭊" LEFTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde><%tilde>                              */ DEADTRANS( L' '	,0xE2D6	,0x2B4A	,0x0000	), // ' ' ➔ "⭊" LEFTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde>                                      */ DEADTRANS( 0x00A0	,0xE2D5	,0x2B3F	,0x0000	), // ' ' ➔ "⬿" WAVE ARROW POINTING DIRECTLY LEFT
/*<!M><%less><%minus><%tilde>                                      */ DEADTRANS( L' '	,0xE2D5	,0x2B3F	,0x0000	), // ' ' ➔ "⬿" WAVE ARROW POINTING DIRECTLY LEFT
/*<!M><%less><%minus>                                              */ DEADTRANS( L'_'	,0xE2D0	,0x2AAC	,0x0000	), // '_' ➔ "⪬" SMALLER THAN OR EQUAL TO
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L'0'	,0xE2D7	,0x290E	,0x0000	), // '0' ➔ "⤎" LEFTWARDS TRIPLE DASH ARROW
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( 0x00A0	,0xE2D7	,0x290C	,0x0000	), // ' ' ➔ "⤌" LEFTWARDS DOUBLE DASH ARROW
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L' '	,0xE2D7	,0x290C	,0x0000	), // ' ' ➔ "⤌" LEFTWARDS DOUBLE DASH ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L'3'	,0xE2D0	,0x21DA	,0x0000	), // '3' ➔ "⇚" LEFTWARDS TRIPLE ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L'4'	,0xE2D0	,0x2B45	,0x0000	), // '4' ➔ "⭅" LEFTWARDS QUADRUPLE ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L'c'	,0xE2D0	,0x297A	,0x0000	), // 'c' ➔ "⥺" LEFTWARDS ARROW THROUGH SUBSET
/*<!M><%less><%minus><O>                                           */ DEADTRANS( L'-'	,0xE2D8	,0xDCD8	,0x0000	), // High surrogate: D83E; U+1F8D8 '-' ➔ "🣘" LONG LEFT RIGHT ARROW WITH DEPENDENT LOBE
/*<!M><%less><%minus><o><%minus>                                   */ DEADTRANS( L'>'	,0xE2D9	,0x2948	,0x0000	), // '>' ➔ "⥈" LEFT RIGHT ARROW THROUGH SMALL CIRCLE
/*<!M><%less><%minus><o><%minus>                                   */ DEADTRANS( 0x00A0	,0xE2D9	,0x2B30	,0x0000	), // ' ' ➔ "⬰" LEFT ARROW WITH SMALL CIRCLE
/*<!M><%less><%minus><o><%minus>                                   */ DEADTRANS( L' '	,0xE2D9	,0x2B30	,0x0000	), // ' ' ➔ "⬰" LEFT ARROW WITH SMALL CIRCLE
/*<!M><%less><%minus><o>                                           */ DEADTRANS( L'+'	,0xE2DA	,0x2B32	,0x0000	), // '+' ➔ "⬲" LEFT ARROW WITH CIRCLED PLUS
/*<!M><%less><%minus><O>                                           */ DEADTRANS( L'+'	,0xE2D8	,0x2B32	,0x0000	), // '+' ➔ "⬲" LEFT ARROW WITH CIRCLED PLUS
/*<!M><%less><%minus><O>                                           */ DEADTRANS( L'/'	,0xE2D8	,0x29B4	,0x0000	), // '/' ➔ "⦴" EMPTY SET WITH LEFT ARROW ABOVE
/*<!M><%less><%minus><o>                                           */ DEADTRANS( 0x00A0	,0xE2DA	,0x21AB	,0x0000	), // ' ' ➔ "↫" LEFTWARDS ARROW WITH LOOP
/*<!M><%less><%minus><o>                                           */ DEADTRANS( L' '	,0xE2DA	,0x21AB	,0x0000	), // ' ' ➔ "↫" LEFTWARDS ARROW WITH LOOP
/*<!M><%less><%minus>                                              */ DEADTRANS( L'x'	,0xE2D0	,0x2B3E	,0x0000	), // 'x' ➔ "⬾" LEFTWARDS ARROW THROUGH X
/*<!M><%less><%minus>                                              */ DEADTRANS( 0x00A0	,0xE2D0	,0x2190	,0x0000	), // ' ' ➔ "←" LEFTWARDS ARROW
/*<!M><%less><%minus>                                              */ DEADTRANS( L' '	,0xE2D0	,0x2190	,0x0000	), // ' ' ➔ "←" LEFTWARDS ARROW
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L'['	,0xE2DB	,0x29FC	,0x0000	), // '[' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L']'	,0xE2DB	,0x29FC	,0x0000	), // ']' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenleft><%parenright><%equal>                     */ DEADTRANS( L'/'	,0xE2DC	,0x2AB5	,0x0000	), // '/' ➔ "⪵" PRECEDES ABOVE NOT EQUAL TO
/*<!M><%less><%parenleft><%parenright><%equal>                     */ DEADTRANS( 0x00A0	,0xE2DC	,0x2AB3	,0x0000	), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><%equal>                     */ DEADTRANS( L' '	,0xE2DC	,0x2AB3	,0x0000	), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L'/'	,0xE2DB	,0x2280	,0x0000	), // '/' ➔ "⊀" DOES NOT PRECEDE
/*<!M><%less><%parenleft><%parenright><%tilde>                     */ DEADTRANS( L'/'	,0xE2DD	,0x22E8	,0x0000	), // '/' ➔ "⋨" PRECEDES BUT NOT EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde>             */ DEADTRANS( L'/'	,0xE2DE	,0x2AB9	,0x0000	), // '/' ➔ "⪹" PRECEDES ABOVE NOT ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde>             */ DEADTRANS( 0x00A0	,0xE2DE	,0x2AB7	,0x0000	), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde>             */ DEADTRANS( L' '	,0xE2DE	,0x2AB7	,0x0000	), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde>                     */ DEADTRANS( 0x00A0	,0xE2DD	,0x227E	,0x0000	), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%tilde>                     */ DEADTRANS( L' '	,0xE2DD	,0x227E	,0x0000	), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%underscore>                */ DEADTRANS( L'/'	,0xE2DF	,0x2AB1	,0x0000	), // '/' ➔ "⪱" PRECEDES ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%parenleft><%parenright><%underscore>                */ DEADTRANS( 0x00A0	,0xE2DF	,0x2AAF	,0x0000	), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><%underscore>                */ DEADTRANS( L' '	,0xE2DF	,0x2AAF	,0x0000	), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( 0x00A0	,0xE2DB	,0x227A	,0x0000	), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L' '	,0xE2DB	,0x227A	,0x0000	), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenleft>                                          */ DEADTRANS( L'+'	,0xE2E0	,0x293D	,0x0000	), // '+' ➔ "⤽" TOP ARC ANTICLOCKWISE ARROW WITH PLUS
/*<!M><%less><%parenleft>                                          */ DEADTRANS( 0x00A0	,0xE2E0	,0x293A	,0x0000	), // ' ' ➔ "⤺" TOP ARC ANTICLOCKWISE ARROW
/*<!M><%less><%parenleft>                                          */ DEADTRANS( L' '	,0xE2E0	,0x293A	,0x0000	), // ' ' ➔ "⤺" TOP ARC ANTICLOCKWISE ARROW
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L'['	,0xE2E1	,0x29FC	,0x0000	), // '[' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L']'	,0xE2E1	,0x29FC	,0x0000	), // ']' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenright><%parenleft><%equal>                     */ DEADTRANS( L'/'	,0xE2E2	,0x2AB5	,0x0000	), // '/' ➔ "⪵" PRECEDES ABOVE NOT EQUAL TO
/*<!M><%less><%parenright><%parenleft><%equal>                     */ DEADTRANS( 0x00A0	,0xE2E2	,0x2AB3	,0x0000	), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><%equal>                     */ DEADTRANS( L' '	,0xE2E2	,0x2AB3	,0x0000	), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L'/'	,0xE2E1	,0x2280	,0x0000	), // '/' ➔ "⊀" DOES NOT PRECEDE
/*<!M><%less><%parenright><%parenleft><%tilde>                     */ DEADTRANS( L'/'	,0xE2E3	,0x22E8	,0x0000	), // '/' ➔ "⋨" PRECEDES BUT NOT EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde>             */ DEADTRANS( L'/'	,0xE2E4	,0x2AB9	,0x0000	), // '/' ➔ "⪹" PRECEDES ABOVE NOT ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde>             */ DEADTRANS( 0x00A0	,0xE2E4	,0x2AB7	,0x0000	), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde>             */ DEADTRANS( L' '	,0xE2E4	,0x2AB7	,0x0000	), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde>                     */ DEADTRANS( 0x00A0	,0xE2E3	,0x227E	,0x0000	), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%tilde>                     */ DEADTRANS( L' '	,0xE2E3	,0x227E	,0x0000	), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%underscore>                */ DEADTRANS( L'/'	,0xE2E5	,0x2AB1	,0x0000	), // '/' ➔ "⪱" PRECEDES ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%parenright><%parenleft><%underscore>                */ DEADTRANS( 0x00A0	,0xE2E5	,0x2AAF	,0x0000	), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><%underscore>                */ DEADTRANS( L' '	,0xE2E5	,0x2AAF	,0x0000	), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( 0x00A0	,0xE2E1	,0x227A	,0x0000	), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L' '	,0xE2E1	,0x227A	,0x0000	), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenright>                                         */ DEADTRANS( L')'	,0xE2E6	,0x2996	,0x0000	), // ')' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%less><%parenright>                                         */ DEADTRANS( L'_'	,0xE2E6	,0x2AA8	,0x0000	), // '_' ➔ "⪨" LESS-THAN CLOSED BY CURVE ABOVE SLANTED EQUAL
/*<!M><%less><%period>                                             */ DEADTRANS( L'>'	,0xE2E7	,0x27D0	,0x0000	), // '>' ➔ "⟐" WHITE DIAMOND WITH CENTRED DOT
/*<!M><%less><%period>                                             */ DEADTRANS( L'.'	,0xE2E7	,0x2B38	,0x0000	), // '.' ➔ "⬸" LEFTWARDS ARROW WITH DOTTED STEM
/*<!M><%less><%period>                                             */ DEADTRANS( L'_'	,0xE2E7	,0x2A83	,0x0000	), // '_' ➔ "⪃" LESS-THAN OR SLANTED EQUAL TO WITH DOT ABOVE RIGHT
/*<!M><%less><%period>                                             */ DEADTRANS( 0x00A0	,0xE2E7	,0x22D6	,0x0000	), // ' ' ➔ "⋖" LESS-THAN WITH DOT
/*<!M><%less><%period>                                             */ DEADTRANS( L' '	,0xE2E7	,0x22D6	,0x0000	), // ' ' ➔ "⋖" LESS-THAN WITH DOT
/*<!M><%less><%slash>                                              */ DEADTRANS( L'='	,0xE2E8	,0x21D9	,0x0000	), // '=' ➔ "⇙" SOUTH WEST DOUBLE ARROW
/*<!M><%less><%slash>                                              */ DEADTRANS( L'>'	,0xE2E8	,0x2922	,0x0000	), // '>' ➔ "⤢" NORTH EAST AND SOUTH WEST ARROW
/*<!M><%less><%slash>                                              */ DEADTRANS( L'('	,0xE2E8	,0x29AF	,0x0000	), // '(' ➔ "⦯" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING LEFT AND DOWN
/*<!M><%less><%slash>                                              */ DEADTRANS( L')'	,0xE2E8	,0x2926	,0x0000	), // ')' ➔ "⤦" SOUTH WEST ARROW WITH HOOK
/*<!M><%less><%slash>                                              */ DEADTRANS( L'~'	,0xE2E8	,0x2274	,0x0000	), // '~' ➔ "≴" NEITHER LESS-THAN NOR EQUIVALENT TO
/*<!M><%less><%slash>                                              */ DEADTRANS( L'_'	,0xE2E8	,0x2270	,0x0000	), // '_' ➔ "≰" NEITHER LESS-THAN NOR EQUAL TO
/*<!M><%less><%slash>                                              */ DEADTRANS( L'2'	,0xE2E8	,0x21D9	,0x0000	), // '2' ➔ "⇙" SOUTH WEST DOUBLE ARROW
/*<!M><%less><%slash>                                              */ DEADTRANS( 0x00A0	,0xE2E8	,0x2199	,0x0000	), // ' ' ➔ "↙" SOUTH WEST ARROW
/*<!M><%less><%slash>                                              */ DEADTRANS( L' '	,0xE2E8	,0x2199	,0x0000	), // ' ' ➔ "↙" SOUTH WEST ARROW
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'>'	,0xE2E9	,0x2A8F	,0x0000	), // '>' ➔ "⪏" LESS-THAN ABOVE SIMILAR ABOVE GREATER-THAN
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'-'	,0xE2E9	,0x2A8D	,0x0000	), // '-' ➔ "⪍" LESS-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'/'	,0xE2E9	,0x22E6	,0x0000	), // '/' ➔ "⋦" LESS-THAN BUT NOT EQUIVALENT TO
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( L'/'	,0xE2EA	,0x2A89	,0x0000	), // '/' ➔ "⪉" LESS-THAN AND NOT APPROXIMATE
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( L'~'	,0xE2EA	,0x2B33	,0x0000	), // '~' ➔ "⬳" LONG LEFTWARDS SQUIGGLE ARROW
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( 0x00A0	,0xE2EA	,0x2A85	,0x0000	), // ' ' ➔ "⪅" LESS-THAN OR APPROXIMATE
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( L' '	,0xE2EA	,0x2A85	,0x0000	), // ' ' ➔ "⪅" LESS-THAN OR APPROXIMATE
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'_'	,0xE2E9	,0x2A8D	,0x0000	), // '_' ➔ "⪍" LESS-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%less><%tilde>                                              */ DEADTRANS( 0x00A0	,0xE2E9	,0x219C	,0x0000	), // ' ' ➔ "↜" LEFTWARDS WAVE ARROW
/*<!M><%less><%tilde>                                              */ DEADTRANS( L' '	,0xE2E9	,0x219C	,0x0000	), // ' ' ➔ "↜" LEFTWARDS WAVE ARROW
/*<!M><%less><%underscore>                                         */ DEADTRANS( L'`'	,0xE2EB	,0x2A7D	,0x0000	), // '`' ➔ "⩽" LESS-THAN OR SLANTED EQUAL TO
/*<!M><%less><%underscore><%greater>                               */ DEADTRANS( L'_'	,0xE2EC	,0x2A93	,0x0000	), // '_' ➔ "⪓" LESS-THAN ABOVE SLANTED EQUAL ABOVE GREATER-THAN ABOVE SLANTED EQUAL
/*<!M><%less><%underscore><%greater>                               */ DEADTRANS( 0x00A0	,0xE2EC	,0x22DA	,0x0000	), // ' ' ➔ "⋚" LESS-THAN EQUAL TO OR GREATER-THAN
/*<!M><%less><%underscore><%greater>                               */ DEADTRANS( L' '	,0xE2EC	,0x22DA	,0x0000	), // ' ' ➔ "⋚" LESS-THAN EQUAL TO OR GREATER-THAN
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L'/'	,0xE2ED	,0x22E0	,0x0000	), // '/' ➔ "⋠" DOES NOT PRECEDE OR EQUAL
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( 0x00A0	,0xE2ED	,0x227C	,0x0000	), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L' '	,0xE2ED	,0x227C	,0x0000	), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L'/'	,0xE2EE	,0x22E0	,0x0000	), // '/' ➔ "⋠" DOES NOT PRECEDE OR EQUAL
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( 0x00A0	,0xE2EE	,0x227C	,0x0000	), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L' '	,0xE2EE	,0x227C	,0x0000	), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore>                                         */ DEADTRANS( L'.'	,0xE2EB	,0x2A7F	,0x0000	), // '.' ➔ "⩿" LESS-THAN OR SLANTED EQUAL TO WITH DOT INSIDE
/*<!M><%less><%underscore>                                         */ DEADTRANS( L'/'	,0xE2EB	,0x2A87	,0x0000	), // '/' ➔ "⪇" LESS-THAN AND SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%underscore>                                         */ DEADTRANS( 0x00A0	,0xE2EB	,0x2264	,0x0000	), // ' ' ➔ "≤" LESS-THAN OR EQUAL TO
/*<!M><%less><%underscore>                                         */ DEADTRANS( L' '	,0xE2EB	,0x2264	,0x0000	), // ' ' ➔ "≤" LESS-THAN OR EQUAL TO
/*<!M><%less>                                                      */ DEADTRANS( L'0'	,0xE2EF	,0x27A3	,0x0000	), // '0' ➔ "➣" THREE-D BOTTOM-LIGHTED RIGHTWARDS ARROWHEAD
/*<!M><%less>                                                      */ DEADTRANS( L'1'	,0xE2EF	,0x2022	,0x0000	), // '1' ➔ "•" BULLET
/*<!M><%less>                                                      */ DEADTRANS( L'2'	,0xE2EF	,0x25E6	,0x0000	), // '2' ➔ "◦" WHITE BULLET
/*<!M><%less>                                                      */ DEADTRANS( L'3'	,0xE2EF	,0x2764	,0x0000	), // '3' ➔ "❤" HEAVY BLACK HEART emoji, red heart, most-used in France
/*<!M><%less>                                                      */ DEADTRANS( L'4'	,0xE2EF	,0x25AA	,0x0000	), // '4' ➔ "▪" BLACK SMALL SQUARE emoji
/*<!M><%less>                                                      */ DEADTRANS( L'5'	,0xE2EF	,0x25AB	,0x0000	), // '5' ➔ "▫" WHITE SMALL SQUARE emoji
/*<!M><%less>                                                      */ DEADTRANS( L'6'	,0xE2EF	,0x2023	,0x0000	), // '6' ➔ "‣" TRIANGULAR BULLET
/*<!M><%less>                                                      */ DEADTRANS( L'7'	,0xE2EF	,0x25B9	,0x0000	), // '7' ➔ "▹" WHITE RIGHT-POINTING SMALL TRIANGLE
/*<!M><%less>                                                      */ DEADTRANS( L'8'	,0xE2EF	,0x2665	,0x0000	), // '8' ➔ "♥" BLACK HEART SUIT red emoji, 14th-ranking
/*<!M><%less>                                                      */ DEADTRANS( L'9'	,0xE2EF	,0x27A2	,0x0000	), // '9' ➔ "➢" THREE-D TOP-LIGHTED RIGHTWARDS ARROWHEAD
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE2F0	,0x22B9	,0x0000	), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'|'	,0xE2F0	,0x2957	,0x0000	), // '|' ➔ "⥗" RIGHTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'`'	,0xE2F0	,0x2969	,0x0000	), // '`' ➔ "⥩" RIGHTWARDS HARPOON WITH BARB DOWN ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'-'	,0xE2F0	,0x2AE0	,0x0000	), // '-' ➔ "⫠" SHORT UP TACK
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( 0x00A0	,0xE2F0	,0x00AC	,0x0000	), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L' '	,0xE2F0	,0x00AC	,0x0000	), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( 0x2019	,0xE2F1	,0x22B9	,0x0000	), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( L'|'	,0xE2F1	,0x2957	,0x0000	), // '|' ➔ "⥗" RIGHTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( L'`'	,0xE2F1	,0x2969	,0x0000	), // '`' ➔ "⥩" RIGHTWARDS HARPOON WITH BARB DOWN ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( L'-'	,0xE2F1	,0x2AE0	,0x0000	), // '-' ➔ "⫠" SHORT UP TACK
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( 0x00A0	,0xE2F1	,0x00AC	,0x0000	), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( L' '	,0xE2F1	,0x00AC	,0x0000	), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%backslash>                                         */ DEADTRANS( 0x00A0	,0xE2F2	,0x29A6	,0x0000	), // ' ' ➔ "⦦" OBLIQUE ANGLE OPENING UP
/*<!M><%minus><%backslash>                                         */ DEADTRANS( L' '	,0xE2F2	,0x29A6	,0x0000	), // ' ' ➔ "⦦" OBLIQUE ANGLE OPENING UP
/*<!M><%minus><%bar><%bar><%greater>                               */ DEADTRANS( L'>'	,0xE2F3	,0x2901	,0x0000	), // '>' ➔ "⤁" RIGHTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%greater>                               */ DEADTRANS( 0x00A0	,0xE2F3	,0x21FB	,0x0000	), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%greater>                               */ DEADTRANS( L' '	,0xE2F3	,0x21FB	,0x0000	), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><%greater>                       */ DEADTRANS( L'>'	,0xE2F4	,0x2901	,0x0000	), // '>' ➔ "⤁" RIGHTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><%greater>                       */ DEADTRANS( 0x00A0	,0xE2F4	,0x21FB	,0x0000	), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><%greater>                       */ DEADTRANS( L' '	,0xE2F4	,0x21FB	,0x0000	), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus>                                 */ DEADTRANS( 0x00A0	,0xE2F5	,0x27DB	,0x0000	), // ' ' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><%minus><%bar><%bar><%minus>                                 */ DEADTRANS( L' '	,0xE2F5	,0x27DB	,0x0000	), // ' ' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><%minus><%bar><%bar>                                         */ DEADTRANS( 0x00A0	,0xE2F6	,0x2AE3	,0x0000	), // ' ' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><%minus><%bar><%bar>                                         */ DEADTRANS( L' '	,0xE2F6	,0x2AE3	,0x0000	), // ' ' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><%minus><%bar><%greater>                                     */ DEADTRANS( L'>'	,0xE2F7	,0x2900	,0x0000	), // '>' ➔ "⤀" RIGHTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%greater>                                     */ DEADTRANS( 0x00A0	,0xE2F7	,0x21FE	,0x0000	), // ' ' ➔ "⇾" RIGHTWARDS OPEN-HEADED ARROW
/*<!M><%minus><%bar><%greater>                                     */ DEADTRANS( L' '	,0xE2F7	,0x21FE	,0x0000	), // ' ' ➔ "⇾" RIGHTWARDS OPEN-HEADED ARROW
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE2F8	,0x2900	,0x0000	), // '>' ➔ "⤀" RIGHTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( 0x00A0	,0xE2F8	,0x21F8	,0x0000	), // ' ' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L' '	,0xE2F8	,0x21F8	,0x0000	), // ' ' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar>                                               */ DEADTRANS( L'o'	,0xE2F9	,0x2AF1	,0x0000	), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><%minus><%bar>                                               */ DEADTRANS( 0x00A0	,0xE2F9	,0x2ADE	,0x0000	), // ' ' ➔ "⫞" SHORT LEFT TACK
/*<!M><%minus><%bar>                                               */ DEADTRANS( L' '	,0xE2F9	,0x2ADE	,0x0000	), // ' ' ➔ "⫞" SHORT LEFT TACK
/*<!M><%minus><%circum>                                            */ DEADTRANS( 0x00A0	,0xE2FA	,0x207B	,0x0000	), // ' ' ➔ "⁻" SUPERSCRIPT MINUS
/*<!M><%minus><%circum>                                            */ DEADTRANS( L' '	,0xE2FA	,0x207B	,0x0000	), // ' ' ➔ "⁻" SUPERSCRIPT MINUS
/*<!M><%minus>                                                     */ DEADTRANS( L':'	,0xE2FB	,0x2239	,0x0000	), // ':' ➔ "∹" EXCESS
/*<!M><%minus><%comma><%exclam>                                    */ DEADTRANS( L'>'	,0xE2FC	,0x2935	,0x0000	), // '>' ➔ "⤵" ARROW POINTING RIGHTWARDS THEN CURVING DOWNWARDS
/*<!M><%minus><%comma><%less>                                      */ DEADTRANS( L'!'	,0xE2FD	,0x2934	,0x0000	), // '!' ➔ "⤴" ARROW POINTING RIGHTWARDS THEN CURVING UPWARDS
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE2FE	,0x2A69	,0x0000	), // '|' ➔ "⩩" TRIPLE HORIZONTAL BAR WITH TRIPLE VERTICAL STROKE
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( 0x00A0	,0xE2FE	,0x2A68	,0x0000	), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L' '	,0xE2FE	,0x2A68	,0x0000	), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%equal>                                             */ DEADTRANS( L'-'	,0xE2FF	,0x2263	,0x0000	), // '-' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><%minus><%equal><%slash>                                     */ DEADTRANS( L'/'	,0xE300	,0x29E5	,0x0000	), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><%minus><%equal><%slash>                                     */ DEADTRANS( 0x00A0	,0xE300	,0x2262	,0x0000	), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%minus><%equal><%slash>                                     */ DEADTRANS( L' '	,0xE300	,0x2262	,0x0000	), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%minus><%equal>                                             */ DEADTRANS( 0x00A0	,0xE2FF	,0x2261	,0x0000	), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%minus><%equal>                                             */ DEADTRANS( L' '	,0xE2FF	,0x2261	,0x0000	), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%minus><%grave>                                             */ DEADTRANS( L'\''	,0xE301	,0x2968	,0x0000	), // ''' ➔ "⥨" RIGHTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB UP
/*<!M><%minus><%grave>                                             */ DEADTRANS( 0x2019	,0xE301	,0x2968	,0x0000	), // '’' ➔ "⥨" RIGHTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB UP
/*<!M><%minus><%grave>                                             */ DEADTRANS( L'|'	,0xE301	,0x2953	,0x0000	), // '|' ➔ "⥓" RIGHTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L'-'	,0xE302	,0xDCD3	,0x0000	), // High surrogate: D83E; U+1F8D3 '-' ➔ "🣓" SHORT RIGHTWARDS HARPOON ABOVE LONG LEFTWARDS HARPOON
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( 0x00A0	,0xE302	,0x21CC	,0x0000	), // ' ' ➔ "⇌" RIGHTWARDS HARPOON OVER LEFTWARDS HARPOON
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L' '	,0xE302	,0x21CC	,0x0000	), // ' ' ➔ "⇌" RIGHTWARDS HARPOON OVER LEFTWARDS HARPOON
/*<!M><%minus><%grave><%minus>                                     */ DEADTRANS( L'\''	,0xE303	,0x2964	,0x0000	), // ''' ➔ "⥤" RIGHTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%grave><%minus>                                     */ DEADTRANS( 0x2019	,0xE303	,0x2964	,0x0000	), // '’' ➔ "⥤" RIGHTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%grave>                                             */ DEADTRANS( L'_'	,0xE301	,0x296C	,0x0000	), // '_' ➔ "⥬" RIGHTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%minus><%grave>                                             */ DEADTRANS( 0x00A0	,0xE301	,0x21C0	,0x0000	), // ' ' ➔ "⇀" RIGHTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%minus><%grave>                                             */ DEADTRANS( L' '	,0xE301	,0x21C0	,0x0000	), // ' ' ➔ "⇀" RIGHTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'|'	,0xE304	,0x21E5	,0x0000	), // '|' ➔ "⇥" RIGHTWARDS ARROW TO BAR
/*<!M><%minus><%greater><%greater>                                 */ DEADTRANS( 0x00A0	,0xE305	,0x21A0	,0x0000	), // ' ' ➔ "↠" RIGHTWARDS TWO HEADED ARROW
/*<!M><%minus><%greater><%greater>                                 */ DEADTRANS( L' '	,0xE305	,0x21A0	,0x0000	), // ' ' ➔ "↠" RIGHTWARDS TWO HEADED ARROW
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'>'	,0xE306	,0x291E	,0x0000	), // '>' ➔ "⤞" RIGHTWARDS ARROW TO BLACK DIAMOND
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'-'	,0xE306	,0x21C4	,0x0000	), // '-' ➔ "⇄" RIGHTWARDS ARROW OVER LEFTWARDS ARROW
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'('	,0xE306	,0x27E2	,0x0000	), // '(' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L')'	,0xE306	,0x27E2	,0x0000	), // ')' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'.'	,0xE306	,0x2942	,0x0000	), // '.' ➔ "⥂" RIGHTWARDS ARROW ABOVE SHORT LEFTWARDS ARROW
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L'-'	,0xE307	,0x21F6	,0x0000	), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( 0x00A0	,0xE307	,0x21C9	,0x0000	), // ' ' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L' '	,0xE307	,0x21C9	,0x0000	), // ' ' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'+'	,0xE304	,0x2945	,0x0000	), // '+' ➔ "⥅" RIGHTWARDS ARROW WITH PLUS BELOW
/*<!M><%minus><%greater><%tilde>                                   */ DEADTRANS( L'\\'	,0xE308	,0x2B4C	,0x0000	), // '\' ➔ "⭌" RIGHTWARDS ARROW ABOVE REVERSE TILDE OPERATOR
/*<!M><%minus><%greater><%tilde><%tilde>                           */ DEADTRANS( L'\\'	,0xE309	,0x2B48	,0x0000	), // '\' ➔ "⭈" RIGHTWARDS ARROW ABOVE REVERSE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde><%tilde>                           */ DEADTRANS( 0x00A0	,0xE309	,0x2975	,0x0000	), // ' ' ➔ "⥵" RIGHTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde><%tilde>                           */ DEADTRANS( L' '	,0xE309	,0x2975	,0x0000	), // ' ' ➔ "⥵" RIGHTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde>                                   */ DEADTRANS( 0x00A0	,0xE308	,0x2974	,0x0000	), // ' ' ➔ "⥴" RIGHTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><%minus><%greater><%tilde>                                   */ DEADTRANS( L' '	,0xE308	,0x2974	,0x0000	), // ' ' ➔ "⥴" RIGHTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'3'	,0xE304	,0x21DB	,0x0000	), // '3' ➔ "⇛" RIGHTWARDS TRIPLE ARROW
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'4'	,0xE304	,0x2B46	,0x0000	), // '4' ➔ "⭆" RIGHTWARDS QUADRUPLE ARROW
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'O'	,0xE304	,0x29B3	,0x0000	), // 'O' ➔ "⦳" EMPTY SET WITH RIGHT ARROW ABOVE
/*<!M><%minus><%greater>                                           */ DEADTRANS( 0x00A0	,0xE304	,0x2192	,0x0000	), // ' ' ➔ "→" RIGHTWARDS ARROW
/*<!M><%minus><%greater>                                           */ DEADTRANS( L' '	,0xE304	,0x2192	,0x0000	), // ' ' ➔ "→" RIGHTWARDS ARROW
/*<!M><%minus><%less>                                              */ DEADTRANS( L'>'	,0xE30A	,0x27E2	,0x0000	), // '>' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%less>                                              */ DEADTRANS( L'<'	,0xE30A	,0x291B	,0x0000	), // '<' ➔ "⤛" LEFTWARDS DOUBLE ARROW-TAIL
/*<!M><%minus><%less>                                              */ DEADTRANS( 0x00A0	,0xE30A	,0x2919	,0x0000	), // ' ' ➔ "⤙" LEFTWARDS ARROW-TAIL
/*<!M><%minus><%less>                                              */ DEADTRANS( L' '	,0xE30A	,0x2919	,0x0000	), // ' ' ➔ "⤙" LEFTWARDS ARROW-TAIL
/*<!M><%minus><%minus>                                             */ DEADTRANS( L'|'	,0xE30B	,0x22A3	,0x0000	), // '|' ➔ "⊣" LEFT TACK
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L'-'	,0xE30C	,0xDCD1	,0x0000	), // High surrogate: D83E; U+1F8D1 '-' ➔ "🣑" LONG RIGHTWARDS HARPOON OVER LONG LEFTWARDS HARPOON
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( 0x00A0	,0xE30C	,0xDCD2	,0x0000	), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L' '	,0xE30C	,0xDCD2	,0x0000	), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%greater>                                   */ DEADTRANS( L'<'	,0xE30D	,0xDCD0	,0x0000	), // High surrogate: D83E; U+1F8D0 '<' ➔ "🣐" LONG RIGHTWARDS ARROW OVER LONG LEFTWARDS ARROW
/*<!M><%minus><%minus><%greater>                                   */ DEADTRANS( 0x00A0	,0xE30D	,0x27F6	,0x0000	), // ' ' ➔ "⟶" LONG RIGHTWARDS ARROW
/*<!M><%minus><%minus><%greater>                                   */ DEADTRANS( L' '	,0xE30D	,0x27F6	,0x0000	), // ' ' ➔ "⟶" LONG RIGHTWARDS ARROW
/*<!M><%minus><%minus><%minus>                                     */ DEADTRANS( L'|'	,0xE30E	,0x27DE	,0x0000	), // '|' ➔ "⟞" LONG LEFT TACK
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L'-'	,0xE30F	,0xDCD1	,0x0000	), // High surrogate: D83E; U+1F8D1 '-' ➔ "🣑" LONG RIGHTWARDS HARPOON OVER LONG LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( 0x00A0	,0xE30F	,0xDCD2	,0x0000	), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L' '	,0xE30F	,0xDCD2	,0x0000	), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%greater>                           */ DEADTRANS( L'<'	,0xE310	,0xDCD0	,0x0000	), // High surrogate: D83E; U+1F8D0 '<' ➔ "🣐" LONG RIGHTWARDS ARROW OVER LONG LEFTWARDS ARROW
/*<!M><%minus><%minus><%minus>                                     */ DEADTRANS( L'-'	,0xE30E	,0x2014	,0x0000	), // '-' ➔ "—" EM DASH
/*<!M><%minus><%minus>                                             */ DEADTRANS( L'A'	,0xE30B	,0x2A5E	,0x0000	), // 'A' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus>                                             */ DEADTRANS( L'a'	,0xE30B	,0x2A5E	,0x0000	), // 'a' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v>                                          */ DEADTRANS( L'%'	,0xE311	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V>                                          */ DEADTRANS( L'%'	,0xE312	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v>                                          */ DEADTRANS( 0x00A0	,0xE311	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V>                                          */ DEADTRANS( 0x00A0	,0xE312	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v>                                          */ DEADTRANS( L' '	,0xE311	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V>                                          */ DEADTRANS( L' '	,0xE312	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%parenleft>                                         */ DEADTRANS( L'<'	,0xE313	,0x29AB	,0x0000	), // '<' ➔ "⦫" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING DOWN AND LEFT
/*<!M><%minus><%parenleft>                                         */ DEADTRANS( L')'	,0xE313	,0x29FF	,0x0000	), // ')' ➔ "⧿" MINY
/*<!M><%minus><%parenright>                                        */ DEADTRANS( L'('	,0xE314	,0x29FF	,0x0000	), // '(' ➔ "⧿" MINY
/*<!M><%minus><%parenright><%slash>                                */ DEADTRANS( L'>'	,0xE315	,0x29A8	,0x0000	), // '>' ➔ "⦨" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING UP AND RIGHT
/*<!M><%minus><%parenright><%slash>                                */ DEADTRANS( 0x00A0	,0xE315	,0x2221	,0x0000	), // ' ' ➔ "∡" MEASURED ANGLE
/*<!M><%minus><%parenright><%slash>                                */ DEADTRANS( L' '	,0xE315	,0x2221	,0x0000	), // ' ' ➔ "∡" MEASURED ANGLE
/*<!M><%minus><%period>                                            */ DEADTRANS( 0x00A0	,0xE316	,0x2A2A	,0x0000	), // ' ' ➔ "⨪" MINUS SIGN WITH DOT BELOW
/*<!M><%minus><%period>                                            */ DEADTRANS( L' '	,0xE316	,0x2A2A	,0x0000	), // ' ' ➔ "⨪" MINUS SIGN WITH DOT BELOW
/*<!M><%minus>                                                     */ DEADTRANS( L'+'	,0xE2FB	,0x2213	,0x0000	), // '+' ➔ "∓" MINUS-OR-PLUS SIGN
/*<!M><%minus><%slash>                                             */ DEADTRANS( L'|'	,0xE317	,0x27C0	,0x0000	), // '|' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><%minus><%slash>                                             */ DEADTRANS( L'/'	,0xE317	,0xDCD7	,0x0000	), // High surrogate: D83E; U+1F8D7 '/' ➔ "🣗" LONG RIGHTWARDS ARROW WITH DOUBLE SLASH
/*<!M><%minus><%slash>                                             */ DEADTRANS( L's'	,0xE317	,0x299E	,0x0000	), // 's' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><%minus><%slash>                                             */ DEADTRANS( 0x00A0	,0xE317	,0x2220	,0x0000	), // ' ' ➔ "∠" ANGLE
/*<!M><%minus><%slash>                                             */ DEADTRANS( L' '	,0xE317	,0x2220	,0x0000	), // ' ' ➔ "∠" ANGLE
/*<!M><%minus>                                                     */ DEADTRANS( L'~'	,0xE2FB	,0x2242	,0x0000	), // '~' ➔ "≂" MINUS TILDE
/*<!M><%minus><%underscore>                                        */ DEADTRANS( 0x00A0	,0xE318	,0x208B	,0x0000	), // ' ' ➔ "₋" SUBSCRIPT MINUS
/*<!M><%minus><%underscore>                                        */ DEADTRANS( L' '	,0xE318	,0x208B	,0x0000	), // ' ' ➔ "₋" SUBSCRIPT MINUS
/*<!M><%minus><0><%minus>                                          */ DEADTRANS( L'>'	,0xE319	,0x290D	,0x0000	), // '>' ➔ "⤍" RIGHTWARDS DOUBLE DASH ARROW
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L'>'	,0xE31A	,0x2910	,0x0000	), // '>' ➔ "⤐" RIGHTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( 0x00A0	,0xE31A	,0x290F	,0x0000	), // ' ' ➔ "⤏" RIGHTWARDS TRIPLE DASH ARROW
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L' '	,0xE31A	,0x290F	,0x0000	), // ' ' ➔ "⤏" RIGHTWARDS TRIPLE DASH ARROW
/*<!M><%minus><x>                                                  */ DEADTRANS( L':'	,0xE31B	,0x22C7	,0x0000	), // ':' ➔ "⋇" DIVISION TIMES
/*<!M><%minus><x>                                                  */ DEADTRANS( L'-'	,0xE31B	,0xDCD6	,0x0000	), // High surrogate: D83E; U+1F8D6 '-' ➔ "🣖" LONG RIGHTWARDS ARROW THROUGH X
/*<!M><%parenleft>                                                 */ DEADTRANS( L'\\'	,0xE31C	,0x2925	,0x0000	), // '\' ➔ "⤥" SOUTH EAST ARROW WITH HOOK
/*<!M><%parenleft>                                                 */ DEADTRANS( L'['	,0xE31C	,0x2997	,0x0000	), // '[' ➔ "⦗" LEFT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenleft>                                                 */ DEADTRANS( L'^'	,0xE31C	,0x207D	,0x0000	), // '^' ➔ "⁽" SUPERSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft>                                                 */ DEADTRANS( L'='	,0xE31C	,0x2258	,0x0000	), // '=' ➔ "≘" CORRESPONDS TO
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L'-'	,0xE31D	,0x293C	,0x0000	), // '-' ➔ "⤼" TOP ARC CLOCKWISE ARROW WITH MINUS
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L'('	,0xE31D	,0x2995	,0x0000	), // '(' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L'_'	,0xE31D	,0x2AA9	,0x0000	), // '_' ➔ "⪩" GREATER-THAN CLOSED BY CURVE ABOVE SLANTED EQUAL
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( 0x00A0	,0xE31D	,0x2939	,0x0000	), // ' ' ➔ "⤹" LEFT-SIDE ARC ANTICLOCKWISE ARROW
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L' '	,0xE31D	,0x2939	,0x0000	), // ' ' ➔ "⤹" LEFT-SIDE ARC ANTICLOCKWISE ARROW
/*<!M><%parenleft><%less>                                          */ DEADTRANS( 0x00A0	,0xE31E	,0x2993	,0x0000	), // ' ' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><%parenleft><%less>                                          */ DEADTRANS( L' '	,0xE31E	,0x2993	,0x0000	), // ' ' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( L'='	,0xE31F	,0x2AAE	,0x0000	), // '=' ➔ "⪮" EQUALS SIGN WITH BUMPY ABOVE
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( L'>'	,0xE31F	,0x21AA	,0x0000	), // '>' ➔ "↪" RIGHTWARDS ARROW WITH HOOK
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( 0x00A0	,0xE31F	,0x224F	,0x0000	), // ' ' ➔ "≏" DIFFERENCE BETWEEN
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( L' '	,0xE31F	,0x224F	,0x0000	), // ' ' ➔ "≏" DIFFERENCE BETWEEN
/*<!M><%parenleft><%parenleft>                                     */ DEADTRANS( L'['	,0xE320	,0x27EC	,0x0000	), // '[' ➔ "⟬" MATHEMATICAL LEFT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenleft><%parenleft>                                     */ DEADTRANS( L']'	,0xE320	,0x27EC	,0x0000	), // ']' ➔ "⟬" MATHEMATICAL LEFT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenleft><%parenleft>                                     */ DEADTRANS( L'>'	,0xE320	,0x2995	,0x0000	), // '>' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'-'	,0xE321	,0x2050	,0x0000	), // '-' ➔ "⁐" CLOSE UP
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'/'	,0xE321	,0x226D	,0x0000	), // '/' ➔ "≭" NOT EQUIVALENT TO
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'c'	,0xE321	,0x00A9	,0x0000	), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'C'	,0xE321	,0x00A9	,0x0000	), // 'C' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'p'	,0xE321	,0x2117	,0x0000	), // 'p' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'P'	,0xE321	,0x2117	,0x0000	), // 'P' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'r'	,0xE321	,0x00AE	,0x0000	), // 'r' ➔ "®" REGISTERED SIGN emoji
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L'R'	,0xE321	,0x00AE	,0x0000	), // 'R' ➔ "®" REGISTERED SIGN emoji
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( 0x00A0	,0xE321	,0x226C	,0x0000	), // ' ' ➔ "≬" BETWEEN
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L' '	,0xE321	,0x226C	,0x0000	), // ' ' ➔ "≬" BETWEEN
/*<!M><%parenleft>                                                 */ DEADTRANS( L'+'	,0xE31C	,0x2A2D	,0x0000	), // '+' ➔ "⨭" PLUS SIGN IN LEFT HALF CIRCLE
/*<!M><%parenleft>                                                 */ DEADTRANS( L'/'	,0xE31C	,0x2924	,0x0000	), // '/' ➔ "⤤" NORTH EAST ARROW WITH HOOK
/*<!M><%parenleft><%underscore>                                    */ DEADTRANS( L')'	,0xE322	,0x274D	,0x0000	), // ')' ➔ "❍" SHADOWED WHITE CIRCLE
/*<!M><%parenleft><%underscore>                                    */ DEADTRANS( 0x00A0	,0xE322	,0x208D	,0x0000	), // ' ' ➔ "₍" SUBSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft><%underscore>                                    */ DEADTRANS( L' '	,0xE322	,0x208D	,0x0000	), // ' ' ➔ "₍" SUBSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft><0>                                              */ DEADTRANS( L')'	,0xE323	,0x24EA	,0x0000	), // ')' ➔ "⓪" CIRCLED DIGIT ZERO
/*<!M><%parenleft><0><0><1>                                        */ DEADTRANS( L'1'	,0xE324	,0x256F	,0x0000	), // '1' ➔ "╯" BOX DRAWINGS LIGHT ARC UP AND LEFT
/*<!M><%parenleft><0><1><1>                                        */ DEADTRANS( L'0'	,0xE325	,0x256E	,0x0000	), // '0' ➔ "╮" BOX DRAWINGS LIGHT ARC DOWN AND LEFT
/*<!M><%parenleft><1>                                              */ DEADTRANS( L')'	,0xE326	,0x2460	,0x0000	), // ')' ➔ "①" CIRCLED DIGIT ONE
/*<!M><%parenleft><1><0>                                           */ DEADTRANS( L')'	,0xE327	,0x2469	,0x0000	), // ')' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><%parenleft><1><0><0>                                        */ DEADTRANS( L'1'	,0xE328	,0x2570	,0x0000	), // '1' ➔ "╰" BOX DRAWINGS LIGHT ARC UP AND RIGHT
/*<!M><%parenleft><1><1>                                           */ DEADTRANS( L')'	,0xE329	,0x246A	,0x0000	), // ')' ➔ "⑪" CIRCLED NUMBER ELEVEN
/*<!M><%parenleft><1><1><0>                                        */ DEADTRANS( L'0'	,0xE32A	,0x256D	,0x0000	), // '0' ➔ "╭" BOX DRAWINGS LIGHT ARC DOWN AND RIGHT
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'2'	,0xE326	,0x246B	,0x0000	), // '2' ➔ "⑫" CIRCLED NUMBER TWELVE
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'3'	,0xE326	,0x246C	,0x0000	), // '3' ➔ "⑬" CIRCLED NUMBER THIRTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'4'	,0xE326	,0x246D	,0x0000	), // '4' ➔ "⑭" CIRCLED NUMBER FOURTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'5'	,0xE326	,0x246E	,0x0000	), // '5' ➔ "⑮" CIRCLED NUMBER FIFTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'6'	,0xE326	,0x246F	,0x0000	), // '6' ➔ "⑯" CIRCLED NUMBER SIXTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'7'	,0xE326	,0x2470	,0x0000	), // '7' ➔ "⑰" CIRCLED NUMBER SEVENTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'8'	,0xE326	,0x2471	,0x0000	), // '8' ➔ "⑱" CIRCLED NUMBER EIGHTEEN
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'9'	,0xE326	,0x2472	,0x0000	), // '9' ➔ "⑲" CIRCLED NUMBER NINETEEN
/*<!M><%parenleft><2>                                              */ DEADTRANS( L')'	,0xE32B	,0x2461	,0x0000	), // ')' ➔ "②" CIRCLED DIGIT TWO
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'0'	,0xE32B	,0x2473	,0x0000	), // '0' ➔ "⑳" CIRCLED NUMBER TWENTY
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'1'	,0xE32B	,0x3251	,0x0000	), // '1' ➔ "㉑" CIRCLED NUMBER TWENTY ONE
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'2'	,0xE32B	,0x3252	,0x0000	), // '2' ➔ "㉒" CIRCLED NUMBER TWENTY TWO
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'3'	,0xE32B	,0x3253	,0x0000	), // '3' ➔ "㉓" CIRCLED NUMBER TWENTY THREE
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'4'	,0xE32B	,0x3254	,0x0000	), // '4' ➔ "㉔" CIRCLED NUMBER TWENTY FOUR
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'5'	,0xE32B	,0x3255	,0x0000	), // '5' ➔ "㉕" CIRCLED NUMBER TWENTY FIVE
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'6'	,0xE32B	,0x3256	,0x0000	), // '6' ➔ "㉖" CIRCLED NUMBER TWENTY SIX
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'7'	,0xE32B	,0x3257	,0x0000	), // '7' ➔ "㉗" CIRCLED NUMBER TWENTY SEVEN
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'8'	,0xE32B	,0x3258	,0x0000	), // '8' ➔ "㉘" CIRCLED NUMBER TWENTY EIGHT
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'9'	,0xE32B	,0x3259	,0x0000	), // '9' ➔ "㉙" CIRCLED NUMBER TWENTY NINE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L')'	,0xE32C	,0x2462	,0x0000	), // ')' ➔ "③" CIRCLED DIGIT THREE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'0'	,0xE32C	,0x325A	,0x0000	), // '0' ➔ "㉚" CIRCLED NUMBER THIRTY
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'1'	,0xE32C	,0x325B	,0x0000	), // '1' ➔ "㉛" CIRCLED NUMBER THIRTY ONE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'2'	,0xE32C	,0x325C	,0x0000	), // '2' ➔ "㉜" CIRCLED NUMBER THIRTY TWO
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'3'	,0xE32C	,0x325D	,0x0000	), // '3' ➔ "㉝" CIRCLED NUMBER THIRTY THREE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'4'	,0xE32C	,0x325E	,0x0000	), // '4' ➔ "㉞" CIRCLED NUMBER THIRTY FOUR
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'5'	,0xE32C	,0x325F	,0x0000	), // '5' ➔ "㉟" CIRCLED NUMBER THIRTY FIVE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'6'	,0xE32C	,0x32B1	,0x0000	), // '6' ➔ "㊱" CIRCLED NUMBER THIRTY SIX
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'7'	,0xE32C	,0x32B2	,0x0000	), // '7' ➔ "㊲" CIRCLED NUMBER THIRTY SEVEN
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'8'	,0xE32C	,0x32B3	,0x0000	), // '8' ➔ "㊳" CIRCLED NUMBER THIRTY EIGHT
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'9'	,0xE32C	,0x32B4	,0x0000	), // '9' ➔ "㊴" CIRCLED NUMBER THIRTY NINE
/*<!M><%parenleft><4>                                              */ DEADTRANS( L')'	,0xE32D	,0x2463	,0x0000	), // ')' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'0'	,0xE32D	,0x32B5	,0x0000	), // '0' ➔ "㊵" CIRCLED NUMBER FORTY
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'1'	,0xE32D	,0x32B6	,0x0000	), // '1' ➔ "㊶" CIRCLED NUMBER FORTY ONE
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'2'	,0xE32D	,0x32B7	,0x0000	), // '2' ➔ "㊷" CIRCLED NUMBER FORTY TWO
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'3'	,0xE32D	,0x32B8	,0x0000	), // '3' ➔ "㊸" CIRCLED NUMBER FORTY THREE
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'4'	,0xE32D	,0x32B9	,0x0000	), // '4' ➔ "㊹" CIRCLED NUMBER FORTY FOUR
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'5'	,0xE32D	,0x32BA	,0x0000	), // '5' ➔ "㊺" CIRCLED NUMBER FORTY FIVE
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'6'	,0xE32D	,0x32BB	,0x0000	), // '6' ➔ "㊻" CIRCLED NUMBER FORTY SIX
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'7'	,0xE32D	,0x32BC	,0x0000	), // '7' ➔ "㊼" CIRCLED NUMBER FORTY SEVEN
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'8'	,0xE32D	,0x32BD	,0x0000	), // '8' ➔ "㊽" CIRCLED NUMBER FORTY EIGHT
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'9'	,0xE32D	,0x32BE	,0x0000	), // '9' ➔ "㊾" CIRCLED NUMBER FORTY NINE
/*<!M><%parenleft><5>                                              */ DEADTRANS( L')'	,0xE32E	,0x2464	,0x0000	), // ')' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><%parenleft><5>                                              */ DEADTRANS( L'0'	,0xE32E	,0x32BF	,0x0000	), // '0' ➔ "㊿" CIRCLED NUMBER FIFTY
/*<!M><%parenleft>                                                 */ DEADTRANS( L'6'	,0xE31C	,0x2465	,0x0000	), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><%parenleft>                                                 */ DEADTRANS( L'7'	,0xE31C	,0x2466	,0x0000	), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><%parenleft>                                                 */ DEADTRANS( L'8'	,0xE31C	,0x2467	,0x0000	), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><%parenleft>                                                 */ DEADTRANS( L'9'	,0xE31C	,0x2468	,0x0000	), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><%parenleft>                                                 */ DEADTRANS( L'x'	,0xE31C	,0x2A34	,0x0000	), // 'x' ➔ "⨴" MULTIPLICATION SIGN IN LEFT HALF CIRCLE
/*<!M><%parenright><%bracketright>                                 */ DEADTRANS( 0x00A0	,0xE32F	,0x2998	,0x0000	), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenright><%bracketright>                                 */ DEADTRANS( L' '	,0xE32F	,0x2998	,0x0000	), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenright><%circum>                                       */ DEADTRANS( 0x00A0	,0xE330	,0x207E	,0x0000	), // ' ' ➔ "⁾" SUPERSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><%circum>                                       */ DEADTRANS( L' '	,0xE330	,0x207E	,0x0000	), // ' ' ➔ "⁾" SUPERSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright>                                                */ DEADTRANS( L'>'	,0xE331	,0x293B	,0x0000	), // '>' ➔ "⤻" BOTTOM ARC ANTICLOCKWISE ARROW
/*<!M><%parenright><%less>                                         */ DEADTRANS( L')'	,0xE332	,0x2996	,0x0000	), // ')' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%parenright><%less>                                         */ DEADTRANS( 0x00A0	,0xE332	,0x2938	,0x0000	), // ' ' ➔ "⤸" RIGHT-SIDE ARC CLOCKWISE ARROW
/*<!M><%parenright><%less>                                         */ DEADTRANS( L' '	,0xE332	,0x2938	,0x0000	), // ' ' ➔ "⤸" RIGHT-SIDE ARC CLOCKWISE ARROW
/*<!M><%parenright><%parenleft>                                    */ DEADTRANS( L'/'	,0xE333	,0x226D	,0x0000	), // '/' ➔ "≭" NOT EQUIVALENT TO
/*<!M><%parenright><%parenleft>                                    */ DEADTRANS( 0x00A0	,0xE333	,0x224D	,0x0000	), // ' ' ➔ "≍" EQUIVALENT TO
/*<!M><%parenright><%parenleft>                                    */ DEADTRANS( L' '	,0xE333	,0x224D	,0x0000	), // ' ' ➔ "≍" EQUIVALENT TO
/*<!M><%parenright><%parenright>                                   */ DEADTRANS( L'['	,0xE334	,0x27ED	,0x0000	), // '[' ➔ "⟭" MATHEMATICAL RIGHT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenright><%parenright>                                   */ DEADTRANS( L']'	,0xE334	,0x27ED	,0x0000	), // ']' ➔ "⟭" MATHEMATICAL RIGHT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenright><%parenright>                                   */ DEADTRANS( L'<'	,0xE334	,0x2996	,0x0000	), // '<' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%parenright><%underscore><%circum>                          */ DEADTRANS( 0x00A0	,0xE335	,0x27CC	,0x0000	), // ' ' ➔ "⟌" LONG DIVISION
/*<!M><%parenright><%underscore><%circum>                          */ DEADTRANS( L' '	,0xE335	,0x27CC	,0x0000	), // ' ' ➔ "⟌" LONG DIVISION
/*<!M><%parenright><%underscore>                                   */ DEADTRANS( 0x00A0	,0xE336	,0x208E	,0x0000	), // ' ' ➔ "₎" SUBSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><%underscore>                                   */ DEADTRANS( L' '	,0xE336	,0x208E	,0x0000	), // ' ' ➔ "₎" SUBSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'1'	,0xE337	,0x2575	,0x0000	), // '1' ➔ "╵" BOX DRAWINGS LIGHT UP
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'3'	,0xE337	,0x2579	,0x0000	), // '3' ➔ "╹" BOX DRAWINGS HEAVY UP
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'0'	,0xE338	,0x2574	,0x0000	), // '0' ➔ "╴" BOX DRAWINGS LIGHT LEFT
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'1'	,0xE338	,0x2518	,0x0000	), // '1' ➔ "┘" BOX DRAWINGS LIGHT UP AND LEFT
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'2'	,0xE338	,0x255C	,0x0000	), // '2' ➔ "╜" BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'3'	,0xE338	,0x251A	,0x0000	), // '3' ➔ "┚" BOX DRAWINGS UP HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'1'	,0xE339	,0x255B	,0x0000	), // '1' ➔ "╛" BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'2'	,0xE339	,0x255D	,0x0000	), // '2' ➔ "╝" BOX DRAWINGS DOUBLE UP AND LEFT
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'0'	,0xE33A	,0x2578	,0x0000	), // '0' ➔ "╸" BOX DRAWINGS HEAVY LEFT
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'1'	,0xE33A	,0x2519	,0x0000	), // '1' ➔ "┙" BOX DRAWINGS UP LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'3'	,0xE33A	,0x251B	,0x0000	), // '3' ➔ "┛" BOX DRAWINGS HEAVY UP AND LEFT
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'0'	,0xE33B	,0x2577	,0x0000	), // '0' ➔ "╷" BOX DRAWINGS LIGHT DOWN
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'1'	,0xE33B	,0x2502	,0x0000	), // '1' ➔ "│" BOX DRAWINGS LIGHT VERTICAL
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'3'	,0xE33B	,0x257F	,0x0000	), // '3' ➔ "╿" BOX DRAWINGS HEAVY UP AND LIGHT DOWN
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'0'	,0xE33C	,0x2510	,0x0000	), // '0' ➔ "┐" BOX DRAWINGS LIGHT DOWN AND LEFT
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'1'	,0xE33C	,0x2524	,0x0000	), // '1' ➔ "┤" BOX DRAWINGS LIGHT VERTICAL AND LEFT
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'3'	,0xE33C	,0x2526	,0x0000	), // '3' ➔ "┦" BOX DRAWINGS UP HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'0'	,0xE33D	,0x2555	,0x0000	), // '0' ➔ "╕" BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'1'	,0xE33D	,0x2561	,0x0000	), // '1' ➔ "╡" BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'0'	,0xE33E	,0x2511	,0x0000	), // '0' ➔ "┑" BOX DRAWINGS DOWN LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'1'	,0xE33E	,0x2525	,0x0000	), // '1' ➔ "┥" BOX DRAWINGS VERTICAL LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'3'	,0xE33E	,0x2529	,0x0000	), // '3' ➔ "┩" BOX DRAWINGS DOWN LIGHT AND LEFT UP HEAVY
/*<!M><%parenright><0><2><0>                                       */ DEADTRANS( L'2'	,0xE33F	,0x2551	,0x0000	), // '2' ➔ "║" BOX DRAWINGS DOUBLE VERTICAL
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'0'	,0xE340	,0x2556	,0x0000	), // '0' ➔ "╖" BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'2'	,0xE340	,0x2562	,0x0000	), // '2' ➔ "╢" BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'0'	,0xE341	,0x2557	,0x0000	), // '0' ➔ "╗" BOX DRAWINGS DOUBLE DOWN AND LEFT
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'2'	,0xE341	,0x2563	,0x0000	), // '2' ➔ "╣" BOX DRAWINGS DOUBLE VERTICAL AND LEFT
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'0'	,0xE342	,0x257B	,0x0000	), // '0' ➔ "╻" BOX DRAWINGS HEAVY DOWN
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'1'	,0xE342	,0x257D	,0x0000	), // '1' ➔ "╽" BOX DRAWINGS LIGHT UP AND HEAVY DOWN
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'3'	,0xE342	,0x2503	,0x0000	), // '3' ➔ "┃" BOX DRAWINGS HEAVY VERTICAL
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'0'	,0xE343	,0x2512	,0x0000	), // '0' ➔ "┒" BOX DRAWINGS DOWN HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'1'	,0xE343	,0x2527	,0x0000	), // '1' ➔ "┧" BOX DRAWINGS DOWN HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'3'	,0xE343	,0x2528	,0x0000	), // '3' ➔ "┨" BOX DRAWINGS VERTICAL HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'0'	,0xE344	,0x2513	,0x0000	), // '0' ➔ "┓" BOX DRAWINGS HEAVY DOWN AND LEFT
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'1'	,0xE344	,0x252A	,0x0000	), // '1' ➔ "┪" BOX DRAWINGS UP LIGHT AND LEFT DOWN HEAVY
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'3'	,0xE344	,0x252B	,0x0000	), // '3' ➔ "┫" BOX DRAWINGS HEAVY VERTICAL AND LEFT
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'0'	,0xE345	,0x2576	,0x0000	), // '0' ➔ "╶" BOX DRAWINGS LIGHT RIGHT
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'1'	,0xE345	,0x2514	,0x0000	), // '1' ➔ "└" BOX DRAWINGS LIGHT UP AND RIGHT
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'2'	,0xE345	,0x2559	,0x0000	), // '2' ➔ "╙" BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'3'	,0xE345	,0x2516	,0x0000	), // '3' ➔ "┖" BOX DRAWINGS UP HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'0'	,0xE346	,0x2500	,0x0000	), // '0' ➔ "─" BOX DRAWINGS LIGHT HORIZONTAL
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'1'	,0xE346	,0x2534	,0x0000	), // '1' ➔ "┴" BOX DRAWINGS LIGHT UP AND HORIZONTAL
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'2'	,0xE346	,0x2568	,0x0000	), // '2' ➔ "╨" BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'3'	,0xE346	,0x2538	,0x0000	), // '3' ➔ "┸" BOX DRAWINGS UP HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'0'	,0xE347	,0x257E	,0x0000	), // '0' ➔ "╾" BOX DRAWINGS HEAVY LEFT AND LIGHT RIGHT
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'1'	,0xE347	,0x2535	,0x0000	), // '1' ➔ "┵" BOX DRAWINGS LEFT HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'3'	,0xE347	,0x2539	,0x0000	), // '3' ➔ "┹" BOX DRAWINGS RIGHT LIGHT AND LEFT UP HEAVY
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'0'	,0xE348	,0x250C	,0x0000	), // '0' ➔ "┌" BOX DRAWINGS LIGHT DOWN AND RIGHT
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'1'	,0xE348	,0x251C	,0x0000	), // '1' ➔ "├" BOX DRAWINGS LIGHT VERTICAL AND RIGHT
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'3'	,0xE348	,0x251E	,0x0000	), // '3' ➔ "┞" BOX DRAWINGS UP HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'0'	,0xE349	,0x252C	,0x0000	), // '0' ➔ "┬" BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'1'	,0xE349	,0x253C	,0x0000	), // '1' ➔ "┼" BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'3'	,0xE349	,0x2540	,0x0000	), // '3' ➔ "╀" BOX DRAWINGS UP HEAVY AND DOWN HORIZONTAL LIGHT
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'0'	,0xE34A	,0x252D	,0x0000	), // '0' ➔ "┭" BOX DRAWINGS LEFT HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'1'	,0xE34A	,0x253D	,0x0000	), // '1' ➔ "┽" BOX DRAWINGS LEFT HEAVY AND RIGHT VERTICAL LIGHT
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'3'	,0xE34A	,0x2543	,0x0000	), // '3' ➔ "╃" BOX DRAWINGS LEFT UP HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><2><0>                                       */ DEADTRANS( L'0'	,0xE34B	,0x2553	,0x0000	), // '0' ➔ "╓" BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><2><0>                                       */ DEADTRANS( L'2'	,0xE34B	,0x255F	,0x0000	), // '2' ➔ "╟" BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><2><1>                                       */ DEADTRANS( L'0'	,0xE34C	,0x2565	,0x0000	), // '0' ➔ "╥" BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><2><1>                                       */ DEADTRANS( L'2'	,0xE34C	,0x256B	,0x0000	), // '2' ➔ "╫" BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><2>                                          */ DEADTRANS( L'd'	,0xE34D	,0x2573	,0x0000	), // 'd' ➔ "╳" BOX DRAWINGS LIGHT DIAGONAL CROSS
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'0'	,0xE34E	,0x250E	,0x0000	), // '0' ➔ "┎" BOX DRAWINGS DOWN HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'1'	,0xE34E	,0x251F	,0x0000	), // '1' ➔ "┟" BOX DRAWINGS DOWN HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'3'	,0xE34E	,0x2520	,0x0000	), // '3' ➔ "┠" BOX DRAWINGS VERTICAL HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'0'	,0xE34F	,0x2530	,0x0000	), // '0' ➔ "┰" BOX DRAWINGS DOWN HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'1'	,0xE34F	,0x2541	,0x0000	), // '1' ➔ "╁" BOX DRAWINGS DOWN HEAVY AND UP HORIZONTAL LIGHT
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'3'	,0xE34F	,0x2542	,0x0000	), // '3' ➔ "╂" BOX DRAWINGS VERTICAL HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'0'	,0xE350	,0x2531	,0x0000	), // '0' ➔ "┱" BOX DRAWINGS RIGHT LIGHT AND LEFT DOWN HEAVY
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'1'	,0xE350	,0x2545	,0x0000	), // '1' ➔ "╅" BOX DRAWINGS LEFT DOWN HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'3'	,0xE350	,0x2549	,0x0000	), // '3' ➔ "╉" BOX DRAWINGS RIGHT LIGHT AND LEFT VERTICAL HEAVY
/*<!M><%parenright><1>                                             */ DEADTRANS( L'd'	,0xE351	,0x2571	,0x0000	), // 'd' ➔ "╱" BOX DRAWINGS LIGHT DIAGONAL UPPER RIGHT TO LOWER LEFT
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'1'	,0xE352	,0x2558	,0x0000	), // '1' ➔ "╘" BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'2'	,0xE352	,0x255A	,0x0000	), // '2' ➔ "╚" BOX DRAWINGS DOUBLE UP AND RIGHT
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'0'	,0xE353	,0x2550	,0x0000	), // '0' ➔ "═" BOX DRAWINGS DOUBLE HORIZONTAL
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'1'	,0xE353	,0x2567	,0x0000	), // '1' ➔ "╧" BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'2'	,0xE353	,0x2569	,0x0000	), // '2' ➔ "╩" BOX DRAWINGS DOUBLE UP AND HORIZONTAL
/*<!M><%parenright><2><1><0>                                       */ DEADTRANS( L'0'	,0xE354	,0x2552	,0x0000	), // '0' ➔ "╒" BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><1><0>                                       */ DEADTRANS( L'1'	,0xE354	,0x255E	,0x0000	), // '1' ➔ "╞" BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><1><2>                                       */ DEADTRANS( L'0'	,0xE355	,0x2564	,0x0000	), // '0' ➔ "╤" BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><1><2>                                       */ DEADTRANS( L'1'	,0xE355	,0x256A	,0x0000	), // '1' ➔ "╪" BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><1>                                          */ DEADTRANS( L'd'	,0xE356	,0x2573	,0x0000	), // 'd' ➔ "╳" BOX DRAWINGS LIGHT DIAGONAL CROSS
/*<!M><%parenright><2><2><0>                                       */ DEADTRANS( L'0'	,0xE357	,0x2554	,0x0000	), // '0' ➔ "╔" BOX DRAWINGS DOUBLE DOWN AND RIGHT
/*<!M><%parenright><2><2><0>                                       */ DEADTRANS( L'2'	,0xE357	,0x2560	,0x0000	), // '2' ➔ "╠" BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
/*<!M><%parenright><2><2><2>                                       */ DEADTRANS( L'0'	,0xE358	,0x2566	,0x0000	), // '0' ➔ "╦" BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
/*<!M><%parenright><2><2><2>                                       */ DEADTRANS( L'2'	,0xE358	,0x256C	,0x0000	), // '2' ➔ "╬" BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
/*<!M><%parenright><2><2>                                          */ DEADTRANS( L'h'	,0xE359	,0x254D	,0x0000	), // 'h' ➔ "╍" BOX DRAWINGS HEAVY DOUBLE DASH HORIZONTAL
/*<!M><%parenright><2><2>                                          */ DEADTRANS( L'v'	,0xE359	,0x254F	,0x0000	), // 'v' ➔ "╏" BOX DRAWINGS HEAVY DOUBLE DASH VERTICAL
/*<!M><%parenright><2>                                             */ DEADTRANS( L'd'	,0xE35A	,0x2572	,0x0000	), // 'd' ➔ "╲" BOX DRAWINGS LIGHT DIAGONAL UPPER LEFT TO LOWER RIGHT
/*<!M><%parenright><2>                                             */ DEADTRANS( L'h'	,0xE35A	,0x254C	,0x0000	), // 'h' ➔ "╌" BOX DRAWINGS LIGHT DOUBLE DASH HORIZONTAL
/*<!M><%parenright><2>                                             */ DEADTRANS( L'v'	,0xE35A	,0x254E	,0x0000	), // 'v' ➔ "╎" BOX DRAWINGS LIGHT DOUBLE DASH VERTICAL
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'0'	,0xE35B	,0x257A	,0x0000	), // '0' ➔ "╺" BOX DRAWINGS HEAVY RIGHT
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'1'	,0xE35B	,0x2515	,0x0000	), // '1' ➔ "┕" BOX DRAWINGS UP LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'3'	,0xE35B	,0x2517	,0x0000	), // '3' ➔ "┗" BOX DRAWINGS HEAVY UP AND RIGHT
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'0'	,0xE35C	,0x257C	,0x0000	), // '0' ➔ "╼" BOX DRAWINGS LIGHT LEFT AND HEAVY RIGHT
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'1'	,0xE35C	,0x2536	,0x0000	), // '1' ➔ "┶" BOX DRAWINGS RIGHT HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'3'	,0xE35C	,0x253A	,0x0000	), // '3' ➔ "┺" BOX DRAWINGS LEFT LIGHT AND RIGHT UP HEAVY
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'0'	,0xE35D	,0x2501	,0x0000	), // '0' ➔ "━" BOX DRAWINGS HEAVY HORIZONTAL
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'1'	,0xE35D	,0x2537	,0x0000	), // '1' ➔ "┷" BOX DRAWINGS UP LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'3'	,0xE35D	,0x253B	,0x0000	), // '3' ➔ "┻" BOX DRAWINGS HEAVY UP AND HORIZONTAL
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'0'	,0xE35E	,0x250D	,0x0000	), // '0' ➔ "┍" BOX DRAWINGS DOWN LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'1'	,0xE35E	,0x251D	,0x0000	), // '1' ➔ "┝" BOX DRAWINGS VERTICAL LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'3'	,0xE35E	,0x2521	,0x0000	), // '3' ➔ "┡" BOX DRAWINGS DOWN LIGHT AND RIGHT UP HEAVY
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'0'	,0xE35F	,0x252E	,0x0000	), // '0' ➔ "┮" BOX DRAWINGS RIGHT HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'1'	,0xE35F	,0x253E	,0x0000	), // '1' ➔ "┾" BOX DRAWINGS RIGHT HEAVY AND LEFT VERTICAL LIGHT
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'3'	,0xE35F	,0x2544	,0x0000	), // '3' ➔ "╄" BOX DRAWINGS RIGHT UP HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'0'	,0xE360	,0x252F	,0x0000	), // '0' ➔ "┯" BOX DRAWINGS DOWN LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'1'	,0xE360	,0x253F	,0x0000	), // '1' ➔ "┿" BOX DRAWINGS VERTICAL LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'3'	,0xE360	,0x2547	,0x0000	), // '3' ➔ "╇" BOX DRAWINGS DOWN LIGHT AND UP HORIZONTAL HEAVY
/*<!M><%parenright><3><3><0>                                       */ DEADTRANS( L'0'	,0xE361	,0x250F	,0x0000	), // '0' ➔ "┏" BOX DRAWINGS HEAVY DOWN AND RIGHT
/*<!M><%parenright><3><3><0>                                       */ DEADTRANS( L'1'	,0xE361	,0x2522	,0x0000	), // '1' ➔ "┢" BOX DRAWINGS UP LIGHT AND RIGHT DOWN HEAVY
/*<!M><%parenright><3><3><0>                                       */ DEADTRANS( L'3'	,0xE361	,0x2523	,0x0000	), // '3' ➔ "┣" BOX DRAWINGS HEAVY VERTICAL AND RIGHT
/*<!M><%parenright><3><3><1>                                       */ DEADTRANS( L'0'	,0xE362	,0x2532	,0x0000	), // '0' ➔ "┲" BOX DRAWINGS LEFT LIGHT AND RIGHT DOWN HEAVY
/*<!M><%parenright><3><3><1>                                       */ DEADTRANS( L'1'	,0xE362	,0x2546	,0x0000	), // '1' ➔ "╆" BOX DRAWINGS RIGHT DOWN HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><3><3><1>                                       */ DEADTRANS( L'3'	,0xE362	,0x254A	,0x0000	), // '3' ➔ "╊" BOX DRAWINGS LEFT LIGHT AND RIGHT VERTICAL HEAVY
/*<!M><%parenright><3><3><3>                                       */ DEADTRANS( L'0'	,0xE363	,0x2533	,0x0000	), // '0' ➔ "┳" BOX DRAWINGS HEAVY DOWN AND HORIZONTAL
/*<!M><%parenright><3><3><3>                                       */ DEADTRANS( L'1'	,0xE363	,0x2548	,0x0000	), // '1' ➔ "╈" BOX DRAWINGS UP LIGHT AND DOWN HORIZONTAL HEAVY
/*<!M><%parenright><3><3><3>                                       */ DEADTRANS( L'3'	,0xE363	,0x254B	,0x0000	), // '3' ➔ "╋" BOX DRAWINGS HEAVY VERTICAL AND HORIZONTAL
/*<!M><%parenright><3><3>                                          */ DEADTRANS( L'h'	,0xE364	,0x2505	,0x0000	), // 'h' ➔ "┅" BOX DRAWINGS HEAVY TRIPLE DASH HORIZONTAL
/*<!M><%parenright><3><3>                                          */ DEADTRANS( L'v'	,0xE364	,0x2507	,0x0000	), // 'v' ➔ "┇" BOX DRAWINGS HEAVY TRIPLE DASH VERTICAL
/*<!M><%parenright><3>                                             */ DEADTRANS( L'h'	,0xE365	,0x2504	,0x0000	), // 'h' ➔ "┄" BOX DRAWINGS LIGHT TRIPLE DASH HORIZONTAL
/*<!M><%parenright><3>                                             */ DEADTRANS( L'v'	,0xE365	,0x2506	,0x0000	), // 'v' ➔ "┆" BOX DRAWINGS LIGHT TRIPLE DASH VERTICAL
/*<!M><%parenright><4><4>                                          */ DEADTRANS( L'h'	,0xE366	,0x2509	,0x0000	), // 'h' ➔ "┉" BOX DRAWINGS HEAVY QUADRUPLE DASH HORIZONTAL
/*<!M><%parenright><4><4>                                          */ DEADTRANS( L'v'	,0xE366	,0x250B	,0x0000	), // 'v' ➔ "┋" BOX DRAWINGS HEAVY QUADRUPLE DASH VERTICAL
/*<!M><%parenright><4>                                             */ DEADTRANS( L'h'	,0xE367	,0x2508	,0x0000	), // 'h' ➔ "┈" BOX DRAWINGS LIGHT QUADRUPLE DASH HORIZONTAL
/*<!M><%parenright><4>                                             */ DEADTRANS( L'v'	,0xE367	,0x250A	,0x0000	), // 'v' ➔ "┊" BOX DRAWINGS LIGHT QUADRUPLE DASH VERTICAL
/*<!M><%period>                                                    */ DEADTRANS( L'\\'	,0xE368	,0x29CA	,0x0000	), // '\' ➔ "⧊" TRIANGLE WITH DOT ABOVE
/*<!M><%period>                                                    */ DEADTRANS( L'^'	,0xE368	,0x00B7	,0x0000	), // '^' ➔ "·" MIDDLE DOT
/*<!M><%period>                                                    */ DEADTRANS( L':'	,0xE368	,0x2AF6	,0x0000	), // ':' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><%period><%equal>                                            */ DEADTRANS( L'-'	,0xE369	,0x2A67	,0x0000	), // '-' ➔ "⩧" IDENTICAL WITH DOT ABOVE
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( L'\\'	,0xE36A	,0x2252	,0x0000	), // '\' ➔ "≒" APPROXIMATELY EQUAL TO OR THE IMAGE OF
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( L'/'	,0xE36A	,0x2253	,0x0000	), // '/' ➔ "≓" IMAGE OF OR APPROXIMATELY EQUAL TO
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( 0x00A0	,0xE36A	,0x2251	,0x0000	), // ' ' ➔ "≑" GEOMETRICALLY EQUAL TO
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( L' '	,0xE36A	,0x2251	,0x0000	), // ' ' ➔ "≑" GEOMETRICALLY EQUAL TO
/*<!M><%period><%equal>                                            */ DEADTRANS( 0x00A0	,0xE369	,0x2250	,0x0000	), // ' ' ➔ "≐" APPROACHES THE LIMIT
/*<!M><%period><%equal>                                            */ DEADTRANS( L' '	,0xE369	,0x2250	,0x0000	), // ' ' ➔ "≐" APPROACHES THE LIMIT
/*<!M><%period><%greater>                                          */ DEADTRANS( L'['	,0xE36B	,0x2992	,0x0000	), // '[' ➔ "⦒" RIGHT ANGLE BRACKET WITH DOT
/*<!M><%period><%greater>                                          */ DEADTRANS( L']'	,0xE36B	,0x2992	,0x0000	), // ']' ➔ "⦒" RIGHT ANGLE BRACKET WITH DOT
/*<!M><%period><%greater>                                          */ DEADTRANS( L'<'	,0xE36B	,0x2944	,0x0000	), // '<' ➔ "⥄" SHORT RIGHTWARDS ARROW ABOVE LEFTWARDS ARROW
/*<!M><%period><%greater>                                          */ DEADTRANS( L'_'	,0xE36B	,0x2A84	,0x0000	), // '_' ➔ "⪄" GREATER-THAN OR SLANTED EQUAL TO WITH DOT ABOVE LEFT
/*<!M><%period><%greater>                                          */ DEADTRANS( 0x00A0	,0xE36B	,0x22D7	,0x0000	), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%period><%greater>                                          */ DEADTRANS( L' '	,0xE36B	,0x22D7	,0x0000	), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%period>                                                    */ DEADTRANS( L'<'	,0xE368	,0x2A81	,0x0000	), // '<' ➔ "⪁" LESS-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!M><%period><%minus>                                            */ DEADTRANS( L'='	,0xE36C	,0x2A67	,0x0000	), // '=' ➔ "⩧" IDENTICAL WITH DOT ABOVE
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L'\\'	,0xE36D	,0x2A2B	,0x0000	), // '\' ➔ "⨫" MINUS SIGN WITH FALLING DOTS
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L'/'	,0xE36D	,0x2A2C	,0x0000	), // '/' ➔ "⨬" MINUS SIGN WITH RISING DOTS
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L'x'	,0xE36D	,0x22C7	,0x0000	), // 'x' ➔ "⋇" DIVISION TIMES
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( 0x00A0	,0xE36D	,0x00F7	,0x0000	), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L' '	,0xE36D	,0x00F7	,0x0000	), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%period><%minus>                                            */ DEADTRANS( L'o'	,0xE36C	,0x22B7	,0x0000	), // 'o' ➔ "⊷" IMAGE OF
/*<!M><%period><%minus>                                            */ DEADTRANS( 0x00A0	,0xE36C	,0x2238	,0x0000	), // ' ' ➔ "∸" DOT MINUS
/*<!M><%period><%minus>                                            */ DEADTRANS( L' '	,0xE36C	,0x2238	,0x0000	), // ' ' ➔ "∸" DOT MINUS
/*<!M><%period><%period>                                           */ DEADTRANS( L'='	,0xE36E	,0x2A77	,0x0000	), // '=' ➔ "⩷" EQUALS SIGN WITH TWO DOTS ABOVE AND TWO DOTS BELOW
/*<!M><%period><%period>                                           */ DEADTRANS( L'>'	,0xE36E	,0x2911	,0x0000	), // '>' ➔ "⤑" RIGHTWARDS ARROW WITH DOTTED STEM
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'\\'	,0xE36F	,0x22F1	,0x0000	), // '\' ➔ "⋱" DOWN RIGHT DIAGONAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'|'	,0xE36F	,0x22EE	,0x0000	), // '|' ➔ "⋮" VERTICAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'!'	,0xE36F	,0x22EE	,0x0000	), // '!' ➔ "⋮" VERTICAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'>'	,0xE36F	,0x2911	,0x0000	), // '>' ➔ "⤑" RIGHTWARDS ARROW WITH DOTTED STEM
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'-'	,0xE36F	,0x22EF	,0x0000	), // '-' ➔ "⋯" MIDLINE HORIZONTAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'.'	,0xE36F	,0x2A78	,0x0000	), // '.' ➔ "⩸" EQUIVALENT WITH FOUR DOTS ABOVE
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'/'	,0xE36F	,0x22F0	,0x0000	), // '/' ➔ "⋰" UP RIGHT DIAGONAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'_'	,0xE36F	,0x2026	,0x0000	), // '_' ➔ "…" HORIZONTAL ELLIPSIS
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'a'	,0xE36F	,0x2234	,0x0000	), // 'a' ➔ "∴" THEREFORE
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'A'	,0xE36F	,0x2234	,0x0000	), // 'A' ➔ "∴" THEREFORE
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'v'	,0xE36F	,0x2235	,0x0000	), // 'v' ➔ "∵" BECAUSE
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'V'	,0xE36F	,0x2235	,0x0000	), // 'V' ➔ "∵" BECAUSE
/*<!M><%period><%period>                                           */ DEADTRANS( L'_'	,0xE36E	,0x2025	,0x0000	), // '_' ➔ "‥" TWO DOT LEADER
/*<!M><%period>                                                    */ DEADTRANS( L'+'	,0xE368	,0x2214	,0x0000	), // '+' ➔ "∔" DOT PLUS
/*<!M><%period><%slash>                                            */ DEADTRANS( L'\\'	,0xE370	,0x29CA	,0x0000	), // '\' ➔ "⧊" TRIANGLE WITH DOT ABOVE
/*<!M><%period><%slash>                                            */ DEADTRANS( L'.'	,0xE370	,0x2052	,0x0000	), // '.' ➔ "⁒" COMMERCIAL MINUS SIGN
/*<!M><%period><%tilde>                                            */ DEADTRANS( L'='	,0xE371	,0x2A6D	,0x0000	), // '=' ➔ "⩭" CONGRUENT WITH DOT ABOVE
/*<!M><%period><%tilde>                                            */ DEADTRANS( L'.'	,0xE371	,0x2A6B	,0x0000	), // '.' ➔ "⩫" TILDE OPERATOR WITH RISING DOTS
/*<!M><%period><%tilde>                                            */ DEADTRANS( 0x00A0	,0xE371	,0x2A6A	,0x0000	), // ' ' ➔ "⩪" TILDE OPERATOR WITH DOT ABOVE
/*<!M><%period><%tilde>                                            */ DEADTRANS( L' '	,0xE371	,0x2A6A	,0x0000	), // ' ' ➔ "⩪" TILDE OPERATOR WITH DOT ABOVE
/*<!M><%period>                                                    */ DEADTRANS( L'_'	,0xE368	,0x2024	,0x0000	), // '_' ➔ "․" ONE DOT LEADER
/*<!M><%plus>                                                      */ DEADTRANS( L'*'	,0xE372	,0x2A22	,0x0000	), // '*' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><%plus>                                                      */ DEADTRANS( L'\\'	,0xE372	,0xFB29	,0x0000	), // '\' ➔ "﬩" HEBREW LETTER ALTERNATIVE PLUS SIGN
/*<!M><%plus>                                                      */ DEADTRANS( L'^'	,0xE372	,0x207A	,0x0000	), // '^' ➔ "⁺" SUPERSCRIPT PLUS SIGN
/*<!M><%plus>                                                      */ DEADTRANS( L'='	,0xE372	,0x2A72	,0x0000	), // '=' ➔ "⩲" PLUS SIGN ABOVE EQUALS SIGN
/*<!M><%plus>                                                      */ DEADTRANS( L'-'	,0xE372	,0x00B1	,0x0000	), // '-' ➔ "±" PLUS-MINUS SIGN
/*<!M><%plus><%parenleft>                                          */ DEADTRANS( L')'	,0xE373	,0x29FE	,0x0000	), // ')' ➔ "⧾" TINY
/*<!M><%plus><%parenright>                                         */ DEADTRANS( L'('	,0xE374	,0x29FE	,0x0000	), // '(' ➔ "⧾" TINY
/*<!M><%plus><%parenright>                                         */ DEADTRANS( 0x00A0	,0xE374	,0x2A2E	,0x0000	), // ' ' ➔ "⨮" PLUS SIGN IN RIGHT HALF CIRCLE
/*<!M><%plus><%parenright>                                         */ DEADTRANS( L' '	,0xE374	,0x2A2E	,0x0000	), // ' ' ➔ "⨮" PLUS SIGN IN RIGHT HALF CIRCLE
/*<!M><%plus>                                                      */ DEADTRANS( L'.'	,0xE372	,0x2A25	,0x0000	), // '.' ➔ "⨥" PLUS SIGN WITH DOT BELOW
/*<!M><%plus><%plus>                                               */ DEADTRANS( L'+'	,0xE375	,0x29FB	,0x0000	), // '+' ➔ "⧻" TRIPLE PLUS
/*<!M><%plus><%tilde>                                              */ DEADTRANS( 0x00A0	,0xE376	,0x2A26	,0x0000	), // ' ' ➔ "⨦" PLUS SIGN WITH TILDE BELOW
/*<!M><%plus><%tilde>                                              */ DEADTRANS( L' '	,0xE376	,0x2A26	,0x0000	), // ' ' ➔ "⨦" PLUS SIGN WITH TILDE BELOW
/*<!M><%plus>                                                      */ DEADTRANS( L'_'	,0xE372	,0x208A	,0x0000	), // '_' ➔ "₊" SUBSCRIPT PLUS SIGN
/*<!M><%question>                                                  */ DEADTRANS( L'='	,0xE377	,0x225F	,0x0000	), // '=' ➔ "≟" QUESTIONED EQUAL TO
/*<!M><%question>                                                  */ DEADTRANS( L'!'	,0xE377	,0x203D	,0x0000	), // '!' ➔ "‽" INTERROBANG
/*<!M><%question>                                                  */ DEADTRANS( L'>'	,0xE377	,0x2A7C	,0x0000	), // '>' ➔ "⩼" GREATER-THAN WITH QUESTION MARK ABOVE
/*<!M><%question>                                                  */ DEADTRANS( L'<'	,0xE377	,0x2A7B	,0x0000	), // '<' ➔ "⩻" LESS-THAN WITH QUESTION MARK ABOVE
/*<!M><%question>                                                  */ DEADTRANS( L'?'	,0xE377	,0x00BF	,0x0000	), // '?' ➔ "¿" INVERTED QUESTION MARK
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'|'	,0xE378	,0x22CA	,0x0000	), // '|' ➔ "⋊" RIGHT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'>'	,0xE378	,0x2930	,0x0000	), // '>' ➔ "⤰" RISING DIAGONAL CROSSING SOUTH EAST ARROW
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'#'	,0xE378	,0x29D5	,0x0000	), // '#' ➔ "⧕" TIMES WITH RIGHT HALF BLACK
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'/'	,0xE378	,0x22CC	,0x0000	), // '/' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'-'	,0xE379	,0x2A3A	,0x0000	), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'+'	,0xE379	,0x2A39	,0x0000	), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'_'	,0xE379	,0x29CB	,0x0000	), // '_' ➔ "⧋" TRIANGLE WITH UNDERBAR
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'o'	,0xE379	,0x27C1	,0x0000	), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L's'	,0xE379	,0x29CC	,0x0000	), // 's' ➔ "⧌" S IN TRIANGLE
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'x'	,0xE379	,0x2A3B	,0x0000	), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( 0x00A0	,0xE379	,0x2A32	,0x0000	), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L' '	,0xE379	,0x2A32	,0x0000	), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%slash><%backslash>                                         */ DEADTRANS( 0x00A0	,0xE378	,0x292B	,0x0000	), // ' ' ➔ "⤫" RISING DIAGONAL CROSSING FALLING DIAGONAL
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L' '	,0xE378	,0x292B	,0x0000	), // ' ' ➔ "⤫" RISING DIAGONAL CROSSING FALLING DIAGONAL
/*<!M><%slash><%bar>                                               */ DEADTRANS( L'_'	,0xE37A	,0x29E1	,0x0000	), // '_' ➔ "⧡" INCREASES AS
/*<!M><%slash><%bar>                                               */ DEADTRANS( 0x00A0	,0xE37A	,0x2A58	,0x0000	), // ' ' ➔ "⩘" SLOPING LARGE AND
/*<!M><%slash><%bar>                                               */ DEADTRANS( L' '	,0xE37A	,0x2A58	,0x0000	), // ' ' ➔ "⩘" SLOPING LARGE AND
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'\\'	,0xE37B	,0x292E	,0x0000	), // '\' ➔ "⤮" NORTH EAST ARROW CROSSING SOUTH EAST ARROW
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'='	,0xE37B	,0x21D7	,0x0000	), // '=' ➔ "⇗" NORTH EAST DOUBLE ARROW
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'<'	,0xE37B	,0x2931	,0x0000	), // '<' ➔ "⤱" NORTH EAST ARROW CROSSING NORTH WEST ARROW
/*<!M><%slash><%greater>                                           */ DEADTRANS( L')'	,0xE37B	,0x29AC	,0x0000	), // ')' ➔ "⦬" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING RIGHT AND UP
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'2'	,0xE37B	,0x21D7	,0x0000	), // '2' ➔ "⇗" NORTH EAST DOUBLE ARROW
/*<!M><%slash><%greater>                                           */ DEADTRANS( 0x00A0	,0xE37B	,0x2197	,0x0000	), // ' ' ➔ "↗" NORTH EAST ARROW
/*<!M><%slash><%greater>                                           */ DEADTRANS( L' '	,0xE37B	,0x2197	,0x0000	), // ' ' ➔ "↗" NORTH EAST ARROW
/*<!M><%slash><%hash><%underscore>                                 */ DEADTRANS( L'\\'	,0xE37C	,0x25B2	,0x0000	), // '\' ➔ "▲" BLACK UP-POINTING TRIANGLE
/*<!M><%slash><%hash><%underscore>                                 */ DEADTRANS( L'/'	,0xE37C	,0x25B0	,0x0000	), // '/' ➔ "▰" BLACK PARALLELOGRAM
/*<!M><%slash><%minus>                                             */ DEADTRANS( L'|'	,0xE37D	,0x22BF	,0x0000	), // '|' ➔ "⊿" RIGHT TRIANGLE
/*<!M><%slash><%minus>                                             */ DEADTRANS( L'>'	,0xE37D	,0x219B	,0x0000	), // '>' ➔ "↛" RIGHTWARDS ARROW WITH STROKE
/*<!M><%slash>                                                     */ DEADTRANS( L'('	,0xE37E	,0x29A1	,0x0000	), // '(' ➔ "⦡" SPHERICAL ANGLE OPENING UP
/*<!M><%slash>                                                     */ DEADTRANS( L'.'	,0xE37E	,0x25EC	,0x0000	), // '.' ➔ "◬" WHITE UP-POINTING TRIANGLE WITH DOT
/*<!M><%slash><%slash><%backslash>                                 */ DEADTRANS( L'\\'	,0xE37F	,0x2A33	,0x0000	), // '\' ➔ "⨳" SMASH PRODUCT
/*<!M><%slash><%slash><%backslash>                                 */ DEADTRANS( 0x00A0	,0xE37F	,0x22CC	,0x0000	), // ' ' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%slash><%backslash>                                 */ DEADTRANS( L' '	,0xE37F	,0x22CC	,0x0000	), // ' ' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( L'_'	,0xE380	,0x23E2	,0x0000	), // '_' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( L'o'	,0xE380	,0x27C1	,0x0000	), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( 0x00A0	,0xE380	,0x25B3	,0x0000	), // ' ' ➔ "△" WHITE UP-POINTING TRIANGLE
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( L' '	,0xE380	,0x25B3	,0x0000	), // ' ' ➔ "△" WHITE UP-POINTING TRIANGLE
/*<!M><%slash><%underscore>                                        */ DEADTRANS( L'|'	,0xE381	,0x25FF	,0x0000	), // '|' ➔ "◿" LOWER RIGHT TRIANGLE
/*<!M><%slash><%underscore>                                        */ DEADTRANS( L'#'	,0xE381	,0x25E2	,0x0000	), // '#' ➔ "◢" BLACK LOWER RIGHT TRIANGLE
/*<!M><%slash><%underscore>                                        */ DEADTRANS( L'/'	,0xE381	,0x25B1	,0x0000	), // '/' ➔ "▱" WHITE PARALLELOGRAM
/*<!M><%slash><%underscore><%underscore>                           */ DEADTRANS( L'\\'	,0xE382	,0x23E2	,0x0000	), // '\' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%slash><%underscore><%underscore>                           */ DEADTRANS( L'|'	,0xE382	,0x29E1	,0x0000	), // '|' ➔ "⧡" INCREASES AS
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L'='	,0xE383	,0x224C	,0x0000	), // '=' ➔ "≌" ALL EQUAL TO
/*<!M><%tilde><%backslash><%greater>                               */ DEADTRANS( L'='	,0xE384	,0x2AA0	,0x0000	), // '=' ➔ "⪠" SIMILAR ABOVE GREATER-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%backslash><%greater>                               */ DEADTRANS( 0x00A0	,0xE384	,0x2A9E	,0x0000	), // ' ' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><%tilde><%backslash><%greater>                               */ DEADTRANS( L' '	,0xE384	,0x2A9E	,0x0000	), // ' ' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( L'='	,0xE385	,0x2A9F	,0x0000	), // '=' ➔ "⪟" SIMILAR ABOVE LESS-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( L'-'	,0xE385	,0x2B41	,0x0000	), // '-' ➔ "⭁" REVERSE TILDE OPERATOR ABOVE LEFTWARDS ARROW
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( 0x00A0	,0xE385	,0x2A9D	,0x0000	), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( L' '	,0xE385	,0x2A9D	,0x0000	), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L'-'	,0xE383	,0x2B47	,0x0000	), // '-' ➔ "⭇" REVERSE TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L'_'	,0xE383	,0x22CD	,0x0000	), // '_' ➔ "⋍" REVERSED TILDE EQUALS
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( 0x00A0	,0xE383	,0x223D	,0x0000	), // ' ' ➔ "∽" REVERSED TILDE
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L' '	,0xE383	,0x223D	,0x0000	), // ' ' ➔ "∽" REVERSED TILDE
/*<!M><%tilde><%bar>                                               */ DEADTRANS( L'|'	,0xE386	,0x2AF3	,0x0000	), // '|' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%tilde><%greater>                                           */ DEADTRANS( L'='	,0xE387	,0x2AA0	,0x0000	), // '=' ➔ "⪠" SIMILAR ABOVE GREATER-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%greater>                                           */ DEADTRANS( 0x00A0	,0xE387	,0x219D	,0x0000	), // ' ' ➔ "↝" RIGHTWARDS WAVE ARROW
/*<!M><%tilde><%greater>                                           */ DEADTRANS( L' '	,0xE387	,0x219D	,0x0000	), // ' ' ➔ "↝" RIGHTWARDS WAVE ARROW
/*<!M><%tilde><%hash>                                              */ DEADTRANS( 0x00A0	,0xE388	,0x29E4	,0x0000	), // ' ' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><%tilde><%hash>                                              */ DEADTRANS( L' '	,0xE388	,0x29E4	,0x0000	), // ' ' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><%tilde><%less>                                              */ DEADTRANS( L'='	,0xE389	,0x2A9F	,0x0000	), // '=' ➔ "⪟" SIMILAR ABOVE LESS-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%less>                                              */ DEADTRANS( L'-'	,0xE389	,0x2B49	,0x0000	), // '-' ➔ "⭉" TILDE OPERATOR ABOVE LEFTWARDS ARROW
/*<!M><%tilde><%less>                                              */ DEADTRANS( 0x00A0	,0xE389	,0x2A9D	,0x0000	), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%less>                                              */ DEADTRANS( L' '	,0xE389	,0x2A9D	,0x0000	), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L'>'	,0xE38A	,0x2933	,0x0000	), // '>' ➔ "⤳" WAVE ARROW POINTING DIRECTLY RIGHT
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L'/'	,0xE38A	,0x2244	,0x0000	), // '/' ➔ "≄" NOT ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L'~'	,0xE38A	,0x2A6C	,0x0000	), // '~' ➔ "⩬" SIMILAR MINUS SIMILAR
/*<!M><%tilde><%minus>                                             */ DEADTRANS( 0x00A0	,0xE38A	,0x2243	,0x0000	), // ' ' ➔ "≃" ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L' '	,0xE38A	,0x2243	,0x0000	), // ' ' ➔ "≃" ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%plus>                                              */ DEADTRANS( 0x00A0	,0xE38B	,0x2A24	,0x0000	), // ' ' ➔ "⨤" PLUS SIGN WITH TILDE ABOVE
/*<!M><%tilde><%plus>                                              */ DEADTRANS( L' '	,0xE38B	,0x2A24	,0x0000	), // ' ' ➔ "⨤" PLUS SIGN WITH TILDE ABOVE
/*<!M><%tilde><%slash>                                             */ DEADTRANS( L'='	,0xE38C	,0x2247	,0x0000	), // '=' ➔ "≇" NEITHER APPROXIMATELY NOR ACTUALLY EQUAL TO
/*<!M><%tilde><%tilde>                                             */ DEADTRANS( L'>'	,0xE38D	,0x21DD	,0x0000	), // '>' ➔ "⇝" RIGHTWARDS SQUIGGLE ARROW
/*<!M><%tilde><%tilde>                                             */ DEADTRANS( L'-'	,0xE38D	,0x224A	,0x0000	), // '-' ➔ "≊" ALMOST EQUAL OR EQUAL TO
/*<!M><%tilde><%tilde>                                             */ DEADTRANS( L'/'	,0xE38D	,0x2249	,0x0000	), // '/' ➔ "≉" NOT ALMOST EQUAL TO
/*<!M><%tilde><%tilde><%tilde>                                     */ DEADTRANS( L'>'	,0xE38E	,0x27FF	,0x0000	), // '>' ➔ "⟿" LONG RIGHTWARDS SQUIGGLE ARROW
/*<!M><%underscore><%backslash>                                    */ DEADTRANS( L'|'	,0xE38F	,0x25F9	,0x0000	), // '|' ➔ "◹" UPPER RIGHT TRIANGLE
/*<!M><%underscore><%backslash>                                    */ DEADTRANS( L'#'	,0xE38F	,0x25E5	,0x0000	), // '#' ➔ "◥" BLACK UPPER RIGHT TRIANGLE
/*<!M><%underscore><%backslash><%slash>                            */ DEADTRANS( L'0'	,0xE390	,0x25BF	,0x0000	), // '0' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%backslash><%slash>                            */ DEADTRANS( 0x00A0	,0xE390	,0x25BD	,0x0000	), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%backslash><%slash>                            */ DEADTRANS( L' '	,0xE390	,0x25BD	,0x0000	), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%bar>                                          */ DEADTRANS( L's'	,0xE391	,0x2AE1	,0x0000	), // 's' ➔ "⫡" PERPENDICULAR WITH S
/*<!M><%underscore><%bar>                                          */ DEADTRANS( 0x00A0	,0xE391	,0x27C2	,0x0000	), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%underscore><%bar>                                          */ DEADTRANS( L' '	,0xE391	,0x27C2	,0x0000	), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%underscore>                                                */ DEADTRANS( L']'	,0xE392	,0x230B	,0x0000	), // ']' ➔ "⌋" RIGHT FLOOR
/*<!M><%underscore>                                                */ DEADTRANS( L'`'	,0xE392	,0x296B	,0x0000	), // '`' ➔ "⥫" LEFTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><%underscore><%greater>                                      */ DEADTRANS( L'`'	,0xE393	,0x2A96	,0x0000	), // '`' ➔ "⪖" SLANTED EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%greater><%parenleft>                          */ DEADTRANS( L')'	,0xE394	,0x22DF	,0x0000	), // ')' ➔ "⋟" EQUAL TO OR SUCCEEDS
/*<!M><%underscore><%greater><%parenright>                         */ DEADTRANS( L'('	,0xE395	,0x22DF	,0x0000	), // '(' ➔ "⋟" EQUAL TO OR SUCCEEDS
/*<!M><%underscore><%greater>                                      */ DEADTRANS( L'.'	,0xE393	,0x2A98	,0x0000	), // '.' ➔ "⪘" SLANTED EQUAL TO OR GREATER-THAN WITH DOT INSIDE
/*<!M><%underscore><%greater>                                      */ DEADTRANS( 0x00A0	,0xE393	,0x22DD	,0x0000	), // ' ' ➔ "⋝" EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%greater>                                      */ DEADTRANS( L' '	,0xE393	,0x22DD	,0x0000	), // ' ' ➔ "⋝" EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L'0'	,0xE396	,0x25BE	,0x0000	), // '0' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( 0x00A0	,0xE396	,0x25BC	,0x0000	), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L' '	,0xE396	,0x25BC	,0x0000	), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L'0'	,0xE397	,0x25BE	,0x0000	), // '0' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( 0x00A0	,0xE397	,0x25BC	,0x0000	), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L' '	,0xE397	,0x25BC	,0x0000	), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%less>                                         */ DEADTRANS( L'`'	,0xE398	,0x2A95	,0x0000	), // '`' ➔ "⪕" SLANTED EQUAL TO OR LESS-THAN
/*<!M><%underscore><%less><%parenleft>                             */ DEADTRANS( L')'	,0xE399	,0x22DE	,0x0000	), // ')' ➔ "⋞" EQUAL TO OR PRECEDES
/*<!M><%underscore><%less><%parenright>                            */ DEADTRANS( L'('	,0xE39A	,0x22DE	,0x0000	), // '(' ➔ "⋞" EQUAL TO OR PRECEDES
/*<!M><%underscore><%less>                                         */ DEADTRANS( L'.'	,0xE398	,0x2A97	,0x0000	), // '.' ➔ "⪗" SLANTED EQUAL TO OR LESS-THAN WITH DOT INSIDE
/*<!M><%underscore><%less>                                         */ DEADTRANS( 0x00A0	,0xE398	,0x22DC	,0x0000	), // ' ' ➔ "⋜" EQUAL TO OR LESS-THAN
/*<!M><%underscore><%less>                                         */ DEADTRANS( L' '	,0xE398	,0x22DC	,0x0000	), // ' ' ➔ "⋜" EQUAL TO OR LESS-THAN
/*<!M><%underscore><%slash><%backslash>                            */ DEADTRANS( L'0'	,0xE39B	,0x25BF	,0x0000	), // '0' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%slash><%backslash>                            */ DEADTRANS( 0x00A0	,0xE39B	,0x25BD	,0x0000	), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%slash><%backslash>                            */ DEADTRANS( L' '	,0xE39B	,0x25BD	,0x0000	), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%slash>                                        */ DEADTRANS( L'|'	,0xE39C	,0x25FF	,0x0000	), // '|' ➔ "◿" LOWER RIGHT TRIANGLE
/*<!M><%underscore><%slash>                                        */ DEADTRANS( L'#'	,0xE39C	,0x25E2	,0x0000	), // '#' ➔ "◢" BLACK LOWER RIGHT TRIANGLE
/*<!M><%underscore><%slash>                                        */ DEADTRANS( 0x00A0	,0xE39C	,0x29F6	,0x0000	), // ' ' ➔ "⧶" SOLIDUS WITH OVERBAR
/*<!M><%underscore><%slash>                                        */ DEADTRANS( L' '	,0xE39C	,0x29F6	,0x0000	), // ' ' ➔ "⧶" SOLIDUS WITH OVERBAR
/*<!M><%underscore><%underscore>                                   */ DEADTRANS( L'A'	,0xE39D	,0x2A5E	,0x0000	), // 'A' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%underscore><%underscore>                                   */ DEADTRANS( L'a'	,0xE39D	,0x2A5E	,0x0000	), // 'a' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><0>                                                          */ DEADTRANS( L'*'	,0xE39E	,0x00B0	,0x0000	), // '*' ➔ "°" DEGREE SIGN
/*<!M><0>                                                          */ DEADTRANS( L'#'	,0xE39E	,0x266E	,0x0000	), // '#' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><0>                                                          */ DEADTRANS( L'-'	,0xE39E	,0x00AD	,0x0000	), // '-' ➔ "­" SOFT HYPHEN
/*<!M><0>                                                          */ DEADTRANS( L'%'	,0xE39E	,0x2030	,0x0000	), // '%' ➔ "‰" PER MILLE SIGN
/*<!M><0>                                                          */ DEADTRANS( L'/'	,0xE39E	,0x2189	,0x0000	), // '/' ➔ "↉" VULGAR FRACTION ZERO THIRDS
/*<!M><0>                                                          */ DEADTRANS( L'0'	,0xE39E	,0x2031	,0x0000	), // '0' ➔ "‱" PER TEN THOUSAND SIGN
/*<!M><0>                                                          */ DEADTRANS( L'3'	,0xE39E	,0x2189	,0x0000	), // '3' ➔ "↉" VULGAR FRACTION ZERO THIRDS
/*<!M><1>                                                          */ DEADTRANS( L'\''	,0xE39F	,0x2032	,0x0000	), // ''' ➔ "′" PRIME
/*<!M><1>                                                          */ DEADTRANS( 0x2019	,0xE39F	,0x2032	,0x0000	), // '’' ➔ "′" PRIME
/*<!M><1>                                                          */ DEADTRANS( L'*'	,0xE39F	,0x2648	,0x0000	), // '*' ➔ "♈" ARIES emoji
/*<!M><1>                                                          */ DEADTRANS( L'`'	,0xE39F	,0x2035	,0x0000	), // '`' ➔ "‵" REVERSED PRIME
/*<!M><1>                                                          */ DEADTRANS( L'#'	,0xE39F	,0x25AA	,0x0000	), // '#' ➔ "▪" BLACK SMALL SQUARE emoji
/*<!M><1>                                                          */ DEADTRANS( L'-'	,0xE39F	,0x2014	,0x0000	), // '-' ➔ "—" EM DASH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'0'	,0xE3A0	,0x2152	,0x0000	), // '0' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'1'	,0xE3A0	,0x2152	,0x0000	), // '1' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'2'	,0xE3A0	,0x00BD	,0x0000	), // '2' ➔ "½" VULGAR FRACTION ONE HALF
/*<!M><1><%slash>                                                  */ DEADTRANS( L'3'	,0xE3A0	,0x2153	,0x0000	), // '3' ➔ "⅓" VULGAR FRACTION ONE THIRD
/*<!M><1><%slash>                                                  */ DEADTRANS( L'4'	,0xE3A0	,0x00BC	,0x0000	), // '4' ➔ "¼" VULGAR FRACTION ONE QUARTER
/*<!M><1><%slash>                                                  */ DEADTRANS( L'5'	,0xE3A0	,0x2155	,0x0000	), // '5' ➔ "⅕" VULGAR FRACTION ONE FIFTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'6'	,0xE3A0	,0x2159	,0x0000	), // '6' ➔ "⅙" VULGAR FRACTION ONE SIXTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'7'	,0xE3A0	,0x2150	,0x0000	), // '7' ➔ "⅐" VULGAR FRACTION ONE SEVENTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'8'	,0xE3A0	,0x215B	,0x0000	), // '8' ➔ "⅛" VULGAR FRACTION ONE EIGHTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'9'	,0xE3A0	,0x2151	,0x0000	), // '9' ➔ "⅑" VULGAR FRACTION ONE NINTH
/*<!M><1><%slash>                                                  */ DEADTRANS( L' '	,0xE3A0	,0x215F	,0x0000	), // ' ' ➔ "⅟" FRACTION NUMERATOR ONE
/*<!M><1>                                                          */ DEADTRANS( L'_'	,0xE39F	,0x25AB	,0x0000	), // '_' ➔ "▫" WHITE SMALL SQUARE emoji
/*<!M><1>                                                          */ DEADTRANS( L'0'	,0xE39F	,0x2152	,0x0000	), // '0' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1>                                                          */ DEADTRANS( L'1'	,0xE39F	,0x2152	,0x0000	), // '1' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1>                                                          */ DEADTRANS( L'2'	,0xE39F	,0x00BD	,0x0000	), // '2' ➔ "½" VULGAR FRACTION ONE HALF
/*<!M><1>                                                          */ DEADTRANS( L'3'	,0xE39F	,0x2153	,0x0000	), // '3' ➔ "⅓" VULGAR FRACTION ONE THIRD
/*<!M><1>                                                          */ DEADTRANS( L'4'	,0xE39F	,0x00BC	,0x0000	), // '4' ➔ "¼" VULGAR FRACTION ONE QUARTER
/*<!M><1>                                                          */ DEADTRANS( L'5'	,0xE39F	,0x2155	,0x0000	), // '5' ➔ "⅕" VULGAR FRACTION ONE FIFTH
/*<!M><1>                                                          */ DEADTRANS( L'6'	,0xE39F	,0x2159	,0x0000	), // '6' ➔ "⅙" VULGAR FRACTION ONE SIXTH
/*<!M><1>                                                          */ DEADTRANS( L'7'	,0xE39F	,0x2150	,0x0000	), // '7' ➔ "⅐" VULGAR FRACTION ONE SEVENTH
/*<!M><1>                                                          */ DEADTRANS( L'8'	,0xE39F	,0x215B	,0x0000	), // '8' ➔ "⅛" VULGAR FRACTION ONE EIGHTH
/*<!M><1>                                                          */ DEADTRANS( L'9'	,0xE39F	,0x2151	,0x0000	), // '9' ➔ "⅑" VULGAR FRACTION ONE NINTH
/*<!M><1>                                                          */ DEADTRANS( L'i'	,0xE39F	,0xA70C	,0x0000	), // 'i' ➔ "꜌" MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*<!M><1>                                                          */ DEADTRANS( L'I'	,0xE39F	,0xA70C	,0x0000	), // 'I' ➔ "꜌" MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*<!M><1>                                                          */ DEADTRANS( L't'	,0xE39F	,0x02E9	,0x0000	), // 't' ➔ "˩" MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!M><1>                                                          */ DEADTRANS( L'T'	,0xE39F	,0x02E9	,0x0000	), // 'T' ➔ "˩" MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!M><1>                                                          */ DEADTRANS( L' '	,0xE39F	,0x215F	,0x0000	), // ' ' ➔ "⅟" FRACTION NUMERATOR ONE
/*<!M><2>                                                          */ DEADTRANS( L'\''	,0xE3A1	,0x2033	,0x0000	), // ''' ➔ "″" DOUBLE PRIME
/*<!M><2>                                                          */ DEADTRANS( 0x2019	,0xE3A1	,0x2033	,0x0000	), // '’' ➔ "″" DOUBLE PRIME
/*<!M><2>                                                          */ DEADTRANS( L'*'	,0xE3A1	,0x2649	,0x0000	), // '*' ➔ "♉" TAURUS emoji
/*<!M><2>                                                          */ DEADTRANS( L'\\'	,0xE3A1	,0x27C1	,0x0000	), // '\' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><2>                                                          */ DEADTRANS( L'|'	,0xE3A1	,0x2016	,0x0000	), // '|' ➔ "‖" DOUBLE VERTICAL LINE
/*<!M><2><%bracketleft>                                            */ DEADTRANS( L']'	,0xE3A2	,0x29C8	,0x0000	), // ']' ➔ "⧈" SQUARED SQUARE
/*<!M><2><%bracketleft>                                            */ DEADTRANS( L'w'	,0xE3A2	,0x29DA	,0x0000	), // 'w' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><2><%bracketright>                                           */ DEADTRANS( L'w'	,0xE3A3	,0x29DB	,0x0000	), // 'w' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><2>                                                          */ DEADTRANS( L'!'	,0xE3A1	,0x21CA	,0x0000	), // '!' ➔ "⇊" DOWNWARDS PAIRED ARROWS
/*<!M><2>                                                          */ DEADTRANS( L'`'	,0xE3A1	,0x2036	,0x0000	), // '`' ➔ "‶" REVERSED DOUBLE PRIME
/*<!M><2>                                                          */ DEADTRANS( L'>'	,0xE3A1	,0x2AA2	,0x0000	), // '>' ➔ "⪢" DOUBLE NESTED GREATER-THAN
/*<!M><2>                                                          */ DEADTRANS( L'#'	,0xE3A1	,0x25FE	,0x0000	), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE emoji
/*<!M><2><%less>                                                   */ DEADTRANS( L'!'	,0xE3A4	,0x21C8	,0x0000	), // '!' ➔ "⇈" UPWARDS PAIRED ARROWS
/*<!M><2><%less>                                                   */ DEADTRANS( L'-'	,0xE3A4	,0x21C7	,0x0000	), // '-' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><2><%less>                                                   */ DEADTRANS( 0x00A0	,0xE3A4	,0x2AA1	,0x0000	), // ' ' ➔ "⪡" DOUBLE NESTED LESS-THAN
/*<!M><2><%less>                                                   */ DEADTRANS( L' '	,0xE3A4	,0x2AA1	,0x0000	), // ' ' ➔ "⪡" DOUBLE NESTED LESS-THAN
/*<!M><2>                                                          */ DEADTRANS( L'-'	,0xE3A1	,0x2E3A	,0x0000	), // '-' ➔ "⸺" TWO-EM DASH
/*<!M><2><%slash>                                                  */ DEADTRANS( L'\\'	,0xE3A5	,0x27C1	,0x0000	), // '\' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><2><%slash>                                                  */ DEADTRANS( L'3'	,0xE3A5	,0x2154	,0x0000	), // '3' ➔ "⅔" VULGAR FRACTION TWO THIRDS
/*<!M><2><%slash>                                                  */ DEADTRANS( L'5'	,0xE3A5	,0x2156	,0x0000	), // '5' ➔ "⅖" VULGAR FRACTION TWO FIFTHS
/*<!M><2><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE3A5	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><2><%slash>                                                  */ DEADTRANS( L' '	,0xE3A5	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><2>                                                          */ DEADTRANS( L'_'	,0xE3A1	,0x25FD	,0x0000	), // '_' ➔ "◽" WHITE MEDIUM SMALL SQUARE emoji
/*<!M><2>                                                          */ DEADTRANS( L'3'	,0xE3A1	,0x2154	,0x0000	), // '3' ➔ "⅔" VULGAR FRACTION TWO THIRDS
/*<!M><2>                                                          */ DEADTRANS( L'5'	,0xE3A1	,0x2156	,0x0000	), // '5' ➔ "⅖" VULGAR FRACTION TWO FIFTHS
/*<!M><2>                                                          */ DEADTRANS( L'A'	,0xE3A1	,0x2A53	,0x0000	), // 'A' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2>                                                          */ DEADTRANS( L'a'	,0xE3A1	,0x2A53	,0x0000	), // 'a' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2>                                                          */ DEADTRANS( L'b'	,0xE3A1	,0x22D1	,0x0000	), // 'b' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c>                                                       */ DEADTRANS( L'\\'	,0xE3A6	,0x22D1	,0x0000	), // '\' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c>                                                       */ DEADTRANS( L'c'	,0xE3A6	,0x22D1	,0x0000	), // 'c' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c>                                                       */ DEADTRANS( 0x00A0	,0xE3A6	,0x22D0	,0x0000	), // ' ' ➔ "⋐" DOUBLE SUBSET
/*<!M><2><c>                                                       */ DEADTRANS( L' '	,0xE3A6	,0x22D0	,0x0000	), // ' ' ➔ "⋐" DOUBLE SUBSET
/*<!M><2>                                                          */ DEADTRANS( L'd'	,0xE3A1	,0x2B76	,0x0000	), // 'd' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2>                                                          */ DEADTRANS( L'D'	,0xE3A1	,0x2B76	,0x0000	), // 'D' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2>                                                          */ DEADTRANS( L'h'	,0xE3A1	,0x2B76	,0x0000	), // 'h' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2>                                                          */ DEADTRANS( L'H'	,0xE3A1	,0x2B76	,0x0000	), // 'H' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2>                                                          */ DEADTRANS( L'i'	,0xE3A1	,0xA70B	,0x0000	), // 'i' ➔ "꜋" MODIFIER LETTER LOW DOTTED TONE BAR
/*<!M><2>                                                          */ DEADTRANS( L'I'	,0xE3A1	,0xA70B	,0x0000	), // 'I' ➔ "꜋" MODIFIER LETTER LOW DOTTED TONE BAR
/*<!M><2><n>                                                       */ DEADTRANS( L'['	,0xE3A7	,0x2A4E	,0x0000	), // '[' ➔ "⩎" DOUBLE SQUARE INTERSECTION
/*<!M><2><n>                                                       */ DEADTRANS( L']'	,0xE3A7	,0x2A4E	,0x0000	), // ']' ➔ "⩎" DOUBLE SQUARE INTERSECTION
/*<!M><2><n>                                                       */ DEADTRANS( 0x00A0	,0xE3A7	,0x22D2	,0x0000	), // ' ' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><2><n>                                                       */ DEADTRANS( L' '	,0xE3A7	,0x22D2	,0x0000	), // ' ' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><2><s>                                                       */ DEADTRANS( L'o'	,0xE3A8	,0x222F	,0x0000	), // 'o' ➔ "∯" SURFACE INTEGRAL
/*<!M><2><S>                                                       */ DEADTRANS( L'o'	,0xE3A9	,0x222F	,0x0000	), // 'o' ➔ "∯" SURFACE INTEGRAL
/*<!M><2><s>                                                       */ DEADTRANS( 0x00A0	,0xE3A8	,0x222C	,0x0000	), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><S>                                                       */ DEADTRANS( 0x00A0	,0xE3A9	,0x222C	,0x0000	), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><s>                                                       */ DEADTRANS( L' '	,0xE3A8	,0x222C	,0x0000	), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><S>                                                       */ DEADTRANS( L' '	,0xE3A9	,0x222C	,0x0000	), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2>                                                          */ DEADTRANS( L't'	,0xE3A1	,0x02E8	,0x0000	), // 't' ➔ "˨" MODIFIER LETTER LOW TONE BAR
/*<!M><2><T>                                                       */ DEADTRANS( L'\''	,0xE3AA	,0x2AE7	,0x0000	), // ''' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><2><T>                                                       */ DEADTRANS( 0x2019	,0xE3AA	,0x2AE7	,0x0000	), // '’' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><2><T><%greater>                                             */ DEADTRANS( L'/'	,0xE3AB	,0x22AE	,0x0000	), // '/' ➔ "⊮" DOES NOT FORCE
/*<!M><2><T><%greater>                                             */ DEADTRANS( 0x00A0	,0xE3AB	,0x22A9	,0x0000	), // ' ' ➔ "⊩" FORCES
/*<!M><2><T><%greater>                                             */ DEADTRANS( L' '	,0xE3AB	,0x22A9	,0x0000	), // ' ' ➔ "⊩" FORCES
/*<!M><2><T>                                                       */ DEADTRANS( L'<'	,0xE3AA	,0x2AE3	,0x0000	), // '<' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><2><T>                                                       */ DEADTRANS( L'%'	,0xE3AA	,0x2AE8	,0x0000	), // '%' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><2><T><2><%greater>                                          */ DEADTRANS( L'/'	,0xE3AC	,0x22AF	,0x0000	), // '/' ➔ "⊯" NEGATED DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2><%greater>                                          */ DEADTRANS( 0x00A0	,0xE3AC	,0x22AB	,0x0000	), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2><%greater>                                          */ DEADTRANS( L' '	,0xE3AC	,0x22AB	,0x0000	), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2>                                                    */ DEADTRANS( L'<'	,0xE3AD	,0x2AE5	,0x0000	), // '<' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><2><u>                                                       */ DEADTRANS( L'['	,0xE3AE	,0x2A4F	,0x0000	), // '[' ➔ "⩏" DOUBLE SQUARE UNION
/*<!M><2><u>                                                       */ DEADTRANS( L']'	,0xE3AE	,0x2A4F	,0x0000	), // ']' ➔ "⩏" DOUBLE SQUARE UNION
/*<!M><2><u>                                                       */ DEADTRANS( 0x00A0	,0xE3AE	,0x22D3	,0x0000	), // ' ' ➔ "⋓" DOUBLE UNION
/*<!M><2><u>                                                       */ DEADTRANS( L' '	,0xE3AE	,0x22D3	,0x0000	), // ' ' ➔ "⋓" DOUBLE UNION
/*<!M><2><V>                                                       */ DEADTRANS( L'V'	,0xE3AF	,0x2A53	,0x0000	), // 'V' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><v>                                                       */ DEADTRANS( L'v'	,0xE3B0	,0x2A53	,0x0000	), // 'v' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><v>                                                       */ DEADTRANS( 0x00A0	,0xE3B0	,0x221A	,0x0000	), // ' ' ➔ "√" SQUARE ROOT
/*<!M><2><V>                                                       */ DEADTRANS( 0x00A0	,0xE3AF	,0x2A54	,0x0000	), // ' ' ➔ "⩔" DOUBLE LOGICAL OR
/*<!M><2><v>                                                       */ DEADTRANS( L' '	,0xE3B0	,0x221A	,0x0000	), // ' ' ➔ "√" SQUARE ROOT
/*<!M><2><V>                                                       */ DEADTRANS( L' '	,0xE3AF	,0x2A54	,0x0000	), // ' ' ➔ "⩔" DOUBLE LOGICAL OR
/*<!M><2><w>                                                       */ DEADTRANS( L'['	,0xE3B1	,0x29DA	,0x0000	), // '[' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><2><w>                                                       */ DEADTRANS( L']'	,0xE3B1	,0x29DB	,0x0000	), // ']' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><2>                                                          */ DEADTRANS( L'Z'	,0xE3A1	,0x01A7	,0x0000	), // 'Z' ➔ "Ƨ" LATIN CAPITAL LETTER TONE TWO
/*<!M><2>                                                          */ DEADTRANS( L'z'	,0xE3A1	,0x01A8	,0x0000	), // 'z' ➔ "ƨ" LATIN SMALL LETTER TONE TWO
/*<!M><2>                                                          */ DEADTRANS( 0x00A0	,0xE3A1	,0x29C9	,0x0000	), // ' ' ➔ "⧉" TWO JOINED SQUARES
/*<!M><2>                                                          */ DEADTRANS( L' '	,0xE3A1	,0x29C9	,0x0000	), // ' ' ➔ "⧉" TWO JOINED SQUARES
/*<!M><3>                                                          */ DEADTRANS( L'\''	,0xE3B2	,0x2034	,0x0000	), // ''' ➔ "‴" TRIPLE PRIME
/*<!M><3>                                                          */ DEADTRANS( 0x2019	,0xE3B2	,0x2034	,0x0000	), // '’' ➔ "‴" TRIPLE PRIME
/*<!M><3>                                                          */ DEADTRANS( L'*'	,0xE3B2	,0x264A	,0x0000	), // '*' ➔ "♊" GEMINI emoji
/*<!M><3>                                                          */ DEADTRANS( L'|'	,0xE3B2	,0x2980	,0x0000	), // '|' ➔ "⦀" TRIPLE VERTICAL BAR DELIMITER
/*<!M><3>                                                          */ DEADTRANS( L'['	,0xE3B2	,0x29C9	,0x0000	), // '[' ➔ "⧉" TWO JOINED SQUARES
/*<!M><3>                                                          */ DEADTRANS( L':'	,0xE3B2	,0x2AF6	,0x0000	), // ':' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><3>                                                          */ DEADTRANS( L'`'	,0xE3B2	,0x2037	,0x0000	), // '`' ➔ "‷" REVERSED TRIPLE PRIME
/*<!M><3>                                                          */ DEADTRANS( L'>'	,0xE3B2	,0x2AF8	,0x0000	), // '>' ➔ "⫸" TRIPLE NESTED GREATER-THAN
/*<!M><3>                                                          */ DEADTRANS( L'#'	,0xE3B2	,0x25FC	,0x0000	), // '#' ➔ "◼" BLACK MEDIUM SQUARE emoji
/*<!M><3><%less>                                                   */ DEADTRANS( L'-'	,0xE3B3	,0x2B31	,0x0000	), // '-' ➔ "⬱" THREE LEFTWARDS ARROWS
/*<!M><3><%less>                                                   */ DEADTRANS( 0x00A0	,0xE3B3	,0x2AF7	,0x0000	), // ' ' ➔ "⫷" TRIPLE NESTED LESS-THAN
/*<!M><3><%less>                                                   */ DEADTRANS( L' '	,0xE3B3	,0x2AF7	,0x0000	), // ' ' ➔ "⫷" TRIPLE NESTED LESS-THAN
/*<!M><3>                                                          */ DEADTRANS( L'-'	,0xE3B2	,0x2E3B	,0x0000	), // '-' ➔ "⸻" THREE-EM DASH
/*<!M><3>                                                          */ DEADTRANS( L'+'	,0xE3B2	,0x29FB	,0x0000	), // '+' ➔ "⧻" TRIPLE PLUS
/*<!M><3><%slash>                                                  */ DEADTRANS( L'4'	,0xE3B4	,0x00BE	,0x0000	), // '4' ➔ "¾" VULGAR FRACTION THREE QUARTERS
/*<!M><3><%slash>                                                  */ DEADTRANS( L'5'	,0xE3B4	,0x2157	,0x0000	), // '5' ➔ "⅗" VULGAR FRACTION THREE FIFTHS
/*<!M><3><%slash>                                                  */ DEADTRANS( L'8'	,0xE3B4	,0x215C	,0x0000	), // '8' ➔ "⅜" VULGAR FRACTION THREE EIGHTHS
/*<!M><3><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE3B4	,0x2AFB	,0x0000	), // ' ' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><3><%slash>                                                  */ DEADTRANS( L' '	,0xE3B4	,0x2AFB	,0x0000	), // ' ' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><3>                                                          */ DEADTRANS( L'_'	,0xE3B2	,0x25FB	,0x0000	), // '_' ➔ "◻" WHITE MEDIUM SQUARE emoji
/*<!M><3>                                                          */ DEADTRANS( L'4'	,0xE3B2	,0x00BE	,0x0000	), // '4' ➔ "¾" VULGAR FRACTION THREE QUARTERS
/*<!M><3>                                                          */ DEADTRANS( L'5'	,0xE3B2	,0x2157	,0x0000	), // '5' ➔ "⅗" VULGAR FRACTION THREE FIFTHS
/*<!M><3>                                                          */ DEADTRANS( L'8'	,0xE3B2	,0x215C	,0x0000	), // '8' ➔ "⅜" VULGAR FRACTION THREE EIGHTHS
/*<!M><3>                                                          */ DEADTRANS( L'd'	,0xE3B2	,0x21B8	,0x0000	), // 'd' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3>                                                          */ DEADTRANS( L'D'	,0xE3B2	,0x21B8	,0x0000	), // 'D' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3>                                                          */ DEADTRANS( L'h'	,0xE3B2	,0x21B8	,0x0000	), // 'h' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3>                                                          */ DEADTRANS( L'H'	,0xE3B2	,0x21B8	,0x0000	), // 'H' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3>                                                          */ DEADTRANS( L'i'	,0xE3B2	,0xA70A	,0x0000	), // 'i' ➔ "꜊" MODIFIER LETTER MID DOTTED TONE BAR
/*<!M><3>                                                          */ DEADTRANS( L'I'	,0xE3B2	,0xA70A	,0x0000	), // 'I' ➔ "꜊" MODIFIER LETTER MID DOTTED TONE BAR
/*<!M><3><s>                                                       */ DEADTRANS( L'o'	,0xE3B5	,0x2230	,0x0000	), // 'o' ➔ "∰" VOLUME INTEGRAL
/*<!M><3><S>                                                       */ DEADTRANS( L'o'	,0xE3B6	,0x2230	,0x0000	), // 'o' ➔ "∰" VOLUME INTEGRAL
/*<!M><3><s>                                                       */ DEADTRANS( 0x00A0	,0xE3B5	,0x222D	,0x0000	), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><S>                                                       */ DEADTRANS( 0x00A0	,0xE3B6	,0x222D	,0x0000	), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><s>                                                       */ DEADTRANS( L' '	,0xE3B5	,0x222D	,0x0000	), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><S>                                                       */ DEADTRANS( L' '	,0xE3B6	,0x222D	,0x0000	), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3>                                                          */ DEADTRANS( L't'	,0xE3B2	,0x02E7	,0x0000	), // 't' ➔ "˧" MODIFIER LETTER MID TONE BAR
/*<!M><3>                                                          */ DEADTRANS( L'v'	,0xE3B2	,0x221B	,0x0000	), // 'v' ➔ "∛" CUBE ROOT
/*<!M><3>                                                          */ DEADTRANS( L'Z'	,0xE3B2	,0x0417	,0x0000	), // 'Z' ➔ "З" CYRILLIC CAPITAL LETTER ZE
/*<!M><3>                                                          */ DEADTRANS( L'z'	,0xE3B2	,0x0437	,0x0000	), // 'z' ➔ "з" CYRILLIC SMALL LETTER ZE
/*<!M><4>                                                          */ DEADTRANS( L'\''	,0xE3B7	,0x2057	,0x0000	), // ''' ➔ "⁗" QUADRUPLE PRIME
/*<!M><4>                                                          */ DEADTRANS( 0x2019	,0xE3B7	,0x2057	,0x0000	), // '’' ➔ "⁗" QUADRUPLE PRIME
/*<!M><4>                                                          */ DEADTRANS( L'*'	,0xE3B7	,0x264B	,0x0000	), // '*' ➔ "♋" CANCER emoji
/*<!M><4>                                                          */ DEADTRANS( L'#'	,0xE3B7	,0x2B1B	,0x0000	), // '#' ➔ "⬛" BLACK LARGE SQUARE emoji
/*<!M><4>                                                          */ DEADTRANS( L'-'	,0xE3B7	,0x2010	,0x0000	), // '-' ➔ "‐" HYPHEN
/*<!M><4><%slash>                                                  */ DEADTRANS( L'5'	,0xE3B8	,0x2158	,0x0000	), // '5' ➔ "⅘" VULGAR FRACTION FOUR FIFTHS
/*<!M><4>                                                          */ DEADTRANS( L'_'	,0xE3B7	,0x2B1C	,0x0000	), // '_' ➔ "⬜" WHITE LARGE SQUARE emoji
/*<!M><4>                                                          */ DEADTRANS( L'5'	,0xE3B7	,0x2158	,0x0000	), // '5' ➔ "⅘" VULGAR FRACTION FOUR FIFTHS
/*<!M><4>                                                          */ DEADTRANS( L'i'	,0xE3B7	,0xA709	,0x0000	), // 'i' ➔ "꜉" MODIFIER LETTER HIGH DOTTED TONE BAR
/*<!M><4>                                                          */ DEADTRANS( L'I'	,0xE3B7	,0xA709	,0x0000	), // 'I' ➔ "꜉" MODIFIER LETTER HIGH DOTTED TONE BAR
/*<!M><4>                                                          */ DEADTRANS( L's'	,0xE3B7	,0x2A0C	,0x0000	), // 's' ➔ "⨌" QUADRUPLE INTEGRAL OPERATOR
/*<!M><4>                                                          */ DEADTRANS( L'S'	,0xE3B7	,0x2A0C	,0x0000	), // 'S' ➔ "⨌" QUADRUPLE INTEGRAL OPERATOR
/*<!M><4>                                                          */ DEADTRANS( L't'	,0xE3B7	,0x02E6	,0x0000	), // 't' ➔ "˦" MODIFIER LETTER HIGH TONE BAR
/*<!M><4>                                                          */ DEADTRANS( L'T'	,0xE3B7	,0x02E6	,0x0000	), // 'T' ➔ "˦" MODIFIER LETTER HIGH TONE BAR
/*<!M><4>                                                          */ DEADTRANS( L'v'	,0xE3B7	,0x221C	,0x0000	), // 'v' ➔ "∜" FOURTH ROOT
/*<!M><4>                                                          */ DEADTRANS( L'Z'	,0xE3B7	,0x0427	,0x0000	), // 'Z' ➔ "Ч" CYRILLIC CAPITAL LETTER CHE
/*<!M><4>                                                          */ DEADTRANS( L'z'	,0xE3B7	,0x0447	,0x0000	), // 'z' ➔ "ч" CYRILLIC SMALL LETTER CHE
/*<!M><5>                                                          */ DEADTRANS( L'*'	,0xE3B9	,0x264C	,0x0000	), // '*' ➔ "♌" LEO emoji
/*<!M><5>                                                          */ DEADTRANS( L'-'	,0xE3B9	,0x2013	,0x0000	), // '-' ➔ "–" EN DASH
/*<!M><5><%slash>                                                  */ DEADTRANS( L'6'	,0xE3BA	,0x215A	,0x0000	), // '6' ➔ "⅚" VULGAR FRACTION FIVE SIXTHS
/*<!M><5><%slash>                                                  */ DEADTRANS( L'8'	,0xE3BA	,0x215D	,0x0000	), // '8' ➔ "⅝" VULGAR FRACTION FIVE EIGHTHS
/*<!M><5>                                                          */ DEADTRANS( L'6'	,0xE3B9	,0x215A	,0x0000	), // '6' ➔ "⅚" VULGAR FRACTION FIVE SIXTHS
/*<!M><5>                                                          */ DEADTRANS( L'8'	,0xE3B9	,0x215D	,0x0000	), // '8' ➔ "⅝" VULGAR FRACTION FIVE EIGHTHS
/*<!M><5>                                                          */ DEADTRANS( L'i'	,0xE3B9	,0xA708	,0x0000	), // 'i' ➔ "꜈" MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*<!M><5>                                                          */ DEADTRANS( L'I'	,0xE3B9	,0xA708	,0x0000	), // 'I' ➔ "꜈" MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*<!M><5>                                                          */ DEADTRANS( L't'	,0xE3B9	,0x02E5	,0x0000	), // 't' ➔ "˥" MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!M><5>                                                          */ DEADTRANS( L'T'	,0xE3B9	,0x02E5	,0x0000	), // 'T' ➔ "˥" MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!M><5>                                                          */ DEADTRANS( L'Z'	,0xE3B9	,0x01BC	,0x0000	), // 'Z' ➔ "Ƽ" LATIN CAPITAL LETTER TONE FIVE
/*<!M><5>                                                          */ DEADTRANS( L'z'	,0xE3B9	,0x01BD	,0x0000	), // 'z' ➔ "ƽ" LATIN SMALL LETTER TONE FIVE
/*<!M><6>                                                          */ DEADTRANS( L'\''	,0xE3BB	,0x2018	,0x0000	), // ''' ➔ "‘" LEFT SINGLE QUOTATION MARK
/*<!M><6>                                                          */ DEADTRANS( 0x2019	,0xE3BB	,0x2018	,0x0000	), // '’' ➔ "‘" LEFT SINGLE QUOTATION MARK
/*<!M><6>                                                          */ DEADTRANS( L'*'	,0xE3BB	,0x264D	,0x0000	), // '*' ➔ "♍" VIRGO emoji
/*<!M><6>                                                          */ DEADTRANS( L'-'	,0xE3BB	,0x2011	,0x0000	), // '-' ➔ "‑" NON-BREAKING HYPHEN
/*<!M><6>                                                          */ DEADTRANS( L'"'	,0xE3BB	,0x201C	,0x0000	), // '"' ➔ "“" LEFT DOUBLE QUOTATION MARK
/*<!M><6>                                                          */ DEADTRANS( 0x20AC	,0xE3BB	,0x201C	,0x0000	), // '€' ➔ "“" LEFT DOUBLE QUOTATION MARK
/*<!M><6>                                                          */ DEADTRANS( L'Z'	,0xE3BB	,0x0184	,0x0000	), // 'Z' ➔ "Ƅ" LATIN CAPITAL LETTER TONE SIX
/*<!M><6>                                                          */ DEADTRANS( L'z'	,0xE3BB	,0x0185	,0x0000	), // 'z' ➔ "ƅ" LATIN SMALL LETTER TONE SIX
/*<!M><7>                                                          */ DEADTRANS( L'*'	,0xE3BC	,0x264E	,0x0000	), // '*' ➔ "♎" LIBRA emoji
/*<!M><7><%circum>                                                 */ DEADTRANS( L'r'	,0xE3BD	,0x02C1	,0x0000	), // 'r' ➔ "ˁ" MODIFIER LETTER REVERSED GLOTTAL STOP
/*<!M><7><%circum>                                                 */ DEADTRANS( L'R'	,0xE3BD	,0xDFB4	,0x0000	), // High surrogate: D801; U+107B4 'R' ➔ "𐞴" MODIFIER LETTER REVERSED GLOTTAL STOP WITH STROKE
/*<!M><7><%circum>                                                 */ DEADTRANS( L's'	,0xE3BD	,0x02E4	,0x0000	), // 's' ➔ "ˤ" MODIFIER LETTER SMALL REVERSED GLOTTAL STOP
/*<!M><7><%circum>                                                 */ DEADTRANS( L'u'	,0xE3BD	,0x02C0	,0x0000	), // 'u' ➔ "ˀ" MODIFIER LETTER GLOTTAL STOP
/*<!M><7><%circum>                                                 */ DEADTRANS( L'U'	,0xE3BD	,0xDFB3	,0x0000	), // High surrogate: D801; U+107B3 'U' ➔ "𐞳" MODIFIER LETTER GLOTTAL STOP WITH STROKE
/*<!M><7>                                                          */ DEADTRANS( L'-'	,0xE3BC	,0x2015	,0x0000	), // '-' ➔ "―" HORIZONTAL BAR
/*<!M><7><%slash>                                                  */ DEADTRANS( L'8'	,0xE3BE	,0x215E	,0x0000	), // '8' ➔ "⅞" VULGAR FRACTION SEVEN EIGHTHS
/*<!M><7>                                                          */ DEADTRANS( L'7'	,0xE3BC	,0x0294	,0x0000	), // '7' ➔ "ʔ" LATIN LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'8'	,0xE3BC	,0x215E	,0x0000	), // '8' ➔ "⅞" VULGAR FRACTION SEVEN EIGHTHS
/*<!M><7>                                                          */ DEADTRANS( L'c'	,0xE3BC	,0x0241	,0x0000	), // 'c' ➔ "Ɂ" LATIN CAPITAL LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'C'	,0xE3BC	,0xDF0E	,0x0000	), // High surrogate: D837; U+1DF0E 'C' ➔ "𝼎" LATIN LETTER INVERTED GLOTTAL STOP WITH CURL
/*<!M><7>                                                          */ DEADTRANS( L'I'	,0xE3BC	,0x01BE	,0x0000	), // 'I' ➔ "ƾ" LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*<!M><7>                                                          */ DEADTRANS( L'i'	,0xE3BC	,0x0296	,0x0000	), // 'i' ➔ "ʖ" LATIN LETTER INVERTED GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'M'	,0xE3BC	,0x0241	,0x0000	), // 'M' ➔ "Ɂ" LATIN CAPITAL LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'm'	,0xE3BC	,0x0242	,0x0000	), // 'm' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'r'	,0xE3BC	,0x0295	,0x0000	), // 'r' ➔ "ʕ" LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*<!M><7>                                                          */ DEADTRANS( L'R'	,0xE3BC	,0x02A2	,0x0000	), // 'R' ➔ "ʢ" LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*<!M><7>                                                          */ DEADTRANS( L'S'	,0xE3BC	,0x0242	,0x0000	), // 'S' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L's'	,0xE3BC	,0x0242	,0x0000	), // 's' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'u'	,0xE3BC	,0x0294	,0x0000	), // 'u' ➔ "ʔ" LATIN LETTER GLOTTAL STOP
/*<!M><7>                                                          */ DEADTRANS( L'U'	,0xE3BC	,0x02A1	,0x0000	), // 'U' ➔ "ʡ" LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!M><8>                                                          */ DEADTRANS( L'*'	,0xE3BF	,0x264F	,0x0000	), // '*' ➔ "♏" SCORPIUS emoji
/*<!M><8>                                                          */ DEADTRANS( L'\\'	,0xE3BF	,0x221D	,0x0000	), // '\' ➔ "∝" PROPORTIONAL TO
/*<!M><8>                                                          */ DEADTRANS( L'|'	,0xE3BF	,0x29DE	,0x0000	), // '|' ➔ "⧞" INFINITY NEGATED WITH VERTICAL BAR
/*<!M><8>                                                          */ DEADTRANS( L'>'	,0xE3BF	,0x2661	,0x0000	), // '>' ➔ "♡" WHITE HEART SUIT
/*<!M><8>                                                          */ DEADTRANS( L'-'	,0xE3BF	,0x2E40	,0x0000	), // '-' ➔ "⹀" DOUBLE HYPHEN
/*<!M><8><x>                                                       */ DEADTRANS( L'a'	,0xE3C0	,0x2704	,0x0000	), // 'a' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X>                                                       */ DEADTRANS( L'A'	,0xE3C1	,0x2704	,0x0000	), // 'A' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x>                                                       */ DEADTRANS( L'b'	,0xE3C0	,0x2703	,0x0000	), // 'b' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><X>                                                       */ DEADTRANS( L'B'	,0xE3C1	,0x2703	,0x0000	), // 'B' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><x>                                                       */ DEADTRANS( L'c'	,0xE3C0	,0x2704	,0x0000	), // 'c' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X>                                                       */ DEADTRANS( L'C'	,0xE3C1	,0x2704	,0x0000	), // 'C' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x>                                                       */ DEADTRANS( L'h'	,0xE3C0	,0x2701	,0x0000	), // 'h' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><X>                                                       */ DEADTRANS( L'H'	,0xE3C1	,0x2701	,0x0000	), // 'H' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><x>                                                       */ DEADTRANS( L'l'	,0xE3C0	,0x2703	,0x0000	), // 'l' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><X>                                                       */ DEADTRANS( L'L'	,0xE3C1	,0x2703	,0x0000	), // 'L' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><x>                                                       */ DEADTRANS( L'o'	,0xE3C0	,0x2704	,0x0000	), // 'o' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X>                                                       */ DEADTRANS( L'O'	,0xE3C1	,0x2704	,0x0000	), // 'O' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x>                                                       */ DEADTRANS( L'p'	,0xE3C0	,0x2702	,0x0000	), // 'p' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><X>                                                       */ DEADTRANS( L'P'	,0xE3C1	,0x2702	,0x0000	), // 'P' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><x>                                                       */ DEADTRANS( L's'	,0xE3C0	,0x2700	,0x0000	), // 's' ➔ "✀" BLACK SAFETY SCISSORS
/*<!M><8><X>                                                       */ DEADTRANS( L'S'	,0xE3C1	,0x2700	,0x0000	), // 'S' ➔ "✀" BLACK SAFETY SCISSORS
/*<!M><8><x>                                                       */ DEADTRANS( L'u'	,0xE3C0	,0x2701	,0x0000	), // 'u' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><X>                                                       */ DEADTRANS( L'U'	,0xE3C1	,0x2701	,0x0000	), // 'U' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><x>                                                       */ DEADTRANS( L' '	,0xE3C0	,0x2702	,0x0000	), // ' ' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><X>                                                       */ DEADTRANS( L' '	,0xE3C1	,0x2702	,0x0000	), // ' ' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8>                                                          */ DEADTRANS( 0x00A0	,0xE3BF	,0x221E	,0x0000	), // ' ' ➔ "∞" INFINITY
/*<!M><8>                                                          */ DEADTRANS( L' '	,0xE3BF	,0x221E	,0x0000	), // ' ' ➔ "∞" INFINITY
/*<!M><9>                                                          */ DEADTRANS( L'\''	,0xE3C2	,0x2019	,0x0000	), // ''' ➔ "’" RIGHT SINGLE QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( 0x2019	,0xE3C2	,0x2019	,0x0000	), // '’' ➔ "’" RIGHT SINGLE QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( L'*'	,0xE3C2	,0x2650	,0x0000	), // '*' ➔ "♐" SAGITTARIUS emoji
/*<!M><9>                                                          */ DEADTRANS( L','	,0xE3C2	,0x201A	,0x0000	), // ',' ➔ "‚" SINGLE LOW-9 QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( L'-'	,0xE3C2	,0x2012	,0x0000	), // '-' ➔ "‒" FIGURE DASH
/*<!M><9>                                                          */ DEADTRANS( L'"'	,0xE3C2	,0x201D	,0x0000	), // '"' ➔ "”" RIGHT DOUBLE QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( 0x20AC	,0xE3C2	,0x201D	,0x0000	), // '€' ➔ "”" RIGHT DOUBLE QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( L'_'	,0xE3C2	,0x201E	,0x0000	), // '_' ➔ "„" DOUBLE LOW-9 QUOTATION MARK
/*<!M><9>                                                          */ DEADTRANS( L'C'	,0xE3C2	,0xA76E	,0x0000	), // 'C' ➔ "Ꝯ" LATIN CAPITAL LETTER CON
/*<!M><9>                                                          */ DEADTRANS( L'c'	,0xE3C2	,0xA76F	,0x0000	), // 'c' ➔ "ꝯ" LATIN SMALL LETTER CON
/*<!M><A>                                                          */ DEADTRANS( L'*'	,0xE3C3	,0x2651	,0x0000	), // '*' ➔ "♑" CAPRICORN emoji
/*<!M><a>                                                          */ DEADTRANS( L'*'	,0xE3C4	,0x2651	,0x0000	), // '*' ➔ "♑" CAPRICORN emoji
/*<!M><a>                                                          */ DEADTRANS( L'\\'	,0xE3C4	,0x2135	,0x0000	), // '\' ➔ "ℵ" ALEF SYMBOL
/*<!M><A>                                                          */ DEADTRANS( L'\\'	,0xE3C3	,0x2135	,0x0000	), // '\' ➔ "ℵ" ALEF SYMBOL
/*<!M><a>                                                          */ DEADTRANS( L'|'	,0xE3C4	,0x2A5A	,0x0000	), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><A>                                                          */ DEADTRANS( L'|'	,0xE3C3	,0x2A5A	,0x0000	), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><a>                                                          */ DEADTRANS( L']'	,0xE3C4	,0x27CE	,0x0000	), // ']' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><A>                                                          */ DEADTRANS( L'='	,0xE3C3	,0x20B3	,0x0000	), // '=' ➔ "₳" AUSTRAL SIGN
/*<!M><a>                                                          */ DEADTRANS( L'='	,0xE3C4	,0x2259	,0x0000	), // '=' ➔ "≙" ESTIMATES
/*<!M><a>                                                          */ DEADTRANS( L'#'	,0xE3C4	,0x29EB	,0x0000	), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><a><%minus>                                                  */ DEADTRANS( L'v'	,0xE3C5	,0x27E0	,0x0000	), // 'v' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus>                                                  */ DEADTRANS( L'v'	,0xE3C6	,0x27E0	,0x0000	), // 'v' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus>                                                  */ DEADTRANS( L'V'	,0xE3C6	,0x27E0	,0x0000	), // 'V' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus>                                                  */ DEADTRANS( 0x00A0	,0xE3C6	,0x2A5C	,0x0000	), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%minus>                                                  */ DEADTRANS( 0x00A0	,0xE3C5	,0x2A5C	,0x0000	), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><A><%minus>                                                  */ DEADTRANS( L' '	,0xE3C6	,0x2A5C	,0x0000	), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%minus>                                                  */ DEADTRANS( L' '	,0xE3C5	,0x2A5C	,0x0000	), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%parenleft>                                              */ DEADTRANS( L')'	,0xE3C7	,0x22CF	,0x0000	), // ')' ➔ "⋏" CURLY LOGICAL AND
/*<!M><a><%parenright>                                             */ DEADTRANS( L'('	,0xE3C8	,0x22CF	,0x0000	), // '(' ➔ "⋏" CURLY LOGICAL AND
/*<!M><a>                                                          */ DEADTRANS( L'.'	,0xE3C4	,0x27D1	,0x0000	), // '.' ➔ "⟑" AND WITH DOT
/*<!M><A>                                                          */ DEADTRANS( L'+'	,0xE3C3	,0x2A39	,0x0000	), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><A>                                                          */ DEADTRANS( L'/'	,0xE3C3	,0x214D	,0x0000	), // '/' ➔ "⅍" AKTIESELSKAB
/*<!M><a><%slash>                                                  */ DEADTRANS( L'c'	,0xE3C9	,0x2100	,0x0000	), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><a><%slash>                                                  */ DEADTRANS( L's'	,0xE3C9	,0x2101	,0x0000	), // 's' ➔ "℁" ADDRESSED TO THE SUBJECT
/*<!M><a>                                                          */ DEADTRANS( L'_'	,0xE3C4	,0x00AA	,0x0000	), // '_' ➔ "ª" FEMININE ORDINAL INDICATOR
/*<!M><A>                                                          */ DEADTRANS( L'_'	,0xE3C3	,0x00AA	,0x0000	), // '_' ➔ "ª" FEMININE ORDINAL INDICATOR
/*<!M><A>                                                          */ DEADTRANS( L'A'	,0xE3C3	,0xA732	,0x0000	), // 'A' ➔ "Ꜳ" LATIN CAPITAL LETTER AA
/*<!M><A>                                                          */ DEADTRANS( L'a'	,0xE3C3	,0xA732	,0x0000	), // 'a' ➔ "Ꜳ" LATIN CAPITAL LETTER AA
/*<!M><a>                                                          */ DEADTRANS( L'a'	,0xE3C4	,0xA733	,0x0000	), // 'a' ➔ "ꜳ" LATIN SMALL LETTER AA
/*<!M><a>                                                          */ DEADTRANS( L'c'	,0xE3C4	,0x2100	,0x0000	), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><a>                                                          */ DEADTRANS( L'C'	,0xE3C4	,0x2100	,0x0000	), // 'C' ➔ "℀" ACCOUNT OF
/*<!M><A>                                                          */ DEADTRANS( L'C'	,0xE3C3	,0x2100	,0x0000	), // 'C' ➔ "℀" ACCOUNT OF
/*<!M><A>                                                          */ DEADTRANS( L'c'	,0xE3C3	,0x2100	,0x0000	), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><A>                                                          */ DEADTRANS( L'e'	,0xE3C3	,0x00C6	,0x0000	), // 'e' ➔ "Æ" LATIN CAPITAL LETTER AE
/*<!M><A><E>                                                       */ DEADTRANS( L' '	,0xE3CA	,0x00C6	,0x0000	), // ' ' ➔ "Æ" LATIN CAPITAL LETTER AE
/*<!M><a><e>                                                       */ DEADTRANS( L' '	,0xE3CB	,0x00E6	,0x0000	), // ' ' ➔ "æ" LATIN SMALL LETTER AE
/*<!M><a><f>                                                       */ DEADTRANS( L'n'	,0xE3CC	,0x060B	,0x0000	), // 'n' ➔ "؋" AFGHANI SIGN, Afghani AFGHANISTAN
/*<!M><A><F>                                                       */ DEADTRANS( L'N'	,0xE3CD	,0x060B	,0x0000	), // 'N' ➔ "؋" AFGHANI SIGN, Afghani AFGHANISTAN
/*<!M><a><l>                                                       */ DEADTRANS( L't'	,0xE3CE	,0x2387	,0x0000	), // 't' ➔ "⎇" ALTERNATIVE KEY SYMBOL
/*<!M><A><L>                                                       */ DEADTRANS( L'T'	,0xE3CF	,0x2387	,0x0000	), // 'T' ➔ "⎇" ALTERNATIVE KEY SYMBOL
/*<!M><a><m>                                                       */ DEADTRANS( L'd'	,0xE3D0	,0x058F	,0x0000	), // 'd' ➔ "֏" ARMENIAN DRAM SIGN, Armenian Dram ARMENIA
/*<!M><A><M>                                                       */ DEADTRANS( L'D'	,0xE3D1	,0x058F	,0x0000	), // 'D' ➔ "֏" ARMENIAN DRAM SIGN, Armenian Dram ARMENIA
/*<!M><a><n>                                                       */ DEADTRANS( L'd'	,0xE3D2	,0x2227	,0x0000	), // 'd' ➔ "∧" LOGICAL AND
/*<!M><A><N>                                                       */ DEADTRANS( L'D'	,0xE3D3	,0x2227	,0x0000	), // 'D' ➔ "∧" LOGICAL AND
/*<!M><a><n>                                                       */ DEADTRANS( L'g'	,0xE3D2	,0x0192	,0x0000	), // 'g' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Netherlands Antillean Guilder CURAÇAO, SINT MAARTEN (DUTCH PART)
/*<!M><A><N>                                                       */ DEADTRANS( L'G'	,0xE3D3	,0x0192	,0x0000	), // 'G' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Netherlands Antillean Guilder CURAÇAO, SINT MAARTEN (DUTCH PART)
/*<!M><A>                                                          */ DEADTRANS( L'O'	,0xE3C3	,0xA734	,0x0000	), // 'O' ➔ "Ꜵ" LATIN CAPITAL LETTER AO
/*<!M><A>                                                          */ DEADTRANS( L'o'	,0xE3C3	,0xA734	,0x0000	), // 'o' ➔ "Ꜵ" LATIN CAPITAL LETTER AO
/*<!M><a>                                                          */ DEADTRANS( L'o'	,0xE3C4	,0xA735	,0x0000	), // 'o' ➔ "ꜵ" LATIN SMALL LETTER AO
/*<!M><A>                                                          */ DEADTRANS( L'Q'	,0xE3C3	,0x2652	,0x0000	), // 'Q' ➔ "♒" AQUARIUS emoji
/*<!M><a><q><u>                                                    */ DEADTRANS( L'a'	,0xE3D4	,0x2652	,0x0000	), // 'a' ➔ "♒" AQUARIUS emoji
/*<!M><A>                                                          */ DEADTRANS( L'R'	,0xE3C3	,0x2648	,0x0000	), // 'R' ➔ "♈" ARIES emoji
/*<!M><a><r><i>                                                    */ DEADTRANS( L'e'	,0xE3D5	,0x2648	,0x0000	), // 'e' ➔ "♈" ARIES emoji
/*<!M><a>                                                          */ DEADTRANS( L's'	,0xE3C4	,0x2101	,0x0000	), // 's' ➔ "℁" ADDRESSED TO THE SUBJECT
/*<!M><A>                                                          */ DEADTRANS( L'S'	,0xE3C3	,0x214D	,0x0000	), // 'S' ➔ "⅍" AKTIESELSKAB
/*<!M><A>                                                          */ DEADTRANS( L'U'	,0xE3C3	,0xA736	,0x0000	), // 'U' ➔ "Ꜷ" LATIN CAPITAL LETTER AU
/*<!M><A>                                                          */ DEADTRANS( L'u'	,0xE3C3	,0xA736	,0x0000	), // 'u' ➔ "Ꜷ" LATIN CAPITAL LETTER AU
/*<!M><a>                                                          */ DEADTRANS( L'u'	,0xE3C4	,0xA737	,0x0000	), // 'u' ➔ "ꜷ" LATIN SMALL LETTER AU
/*<!M><A>                                                          */ DEADTRANS( L'V'	,0xE3C3	,0xA738	,0x0000	), // 'V' ➔ "Ꜹ" LATIN CAPITAL LETTER AV
/*<!M><A>                                                          */ DEADTRANS( L'v'	,0xE3C3	,0xA738	,0x0000	), // 'v' ➔ "Ꜹ" LATIN CAPITAL LETTER AV
/*<!M><a>                                                          */ DEADTRANS( L'v'	,0xE3C4	,0xA739	,0x0000	), // 'v' ➔ "ꜹ" LATIN SMALL LETTER AV
/*<!M><a><w>                                                       */ DEADTRANS( L'g'	,0xE3D6	,0x0192	,0x0000	), // 'g' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Aruban Florin ARUBA
/*<!M><A><W>                                                       */ DEADTRANS( L'G'	,0xE3D7	,0x0192	,0x0000	), // 'G' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Aruban Florin ARUBA
/*<!M><A>                                                          */ DEADTRANS( L'x'	,0xE3C3	,0x2A3B	,0x0000	), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><A>                                                          */ DEADTRANS( L'Y'	,0xE3C3	,0xA73C	,0x0000	), // 'Y' ➔ "Ꜽ" LATIN CAPITAL LETTER AY
/*<!M><A>                                                          */ DEADTRANS( L'y'	,0xE3C3	,0xA73C	,0x0000	), // 'y' ➔ "Ꜽ" LATIN CAPITAL LETTER AY
/*<!M><a>                                                          */ DEADTRANS( L'y'	,0xE3C4	,0xA73D	,0x0000	), // 'y' ➔ "ꜽ" LATIN SMALL LETTER AY
/*<!M><a><z>                                                       */ DEADTRANS( L'n'	,0xE3D8	,0x20BC	,0x0000	), // 'n' ➔ "₼" MANAT SIGN, Azerbaijan Manat AZERBAIJAN
/*<!M><A><Z>                                                       */ DEADTRANS( L'N'	,0xE3D9	,0x20BC	,0x0000	), // 'N' ➔ "₼" MANAT SIGN, Azerbaijan Manat AZERBAIJAN
/*<!M><A>                                                          */ DEADTRANS( 0x00A0	,0xE3C3	,0x2200	,0x0000	), // ' ' ➔ "∀" FOR ALL
/*<!M><a>                                                          */ DEADTRANS( 0x00A0	,0xE3C4	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><A>                                                          */ DEADTRANS( L' '	,0xE3C3	,0x2200	,0x0000	), // ' ' ➔ "∀" FOR ALL
/*<!M><a>                                                          */ DEADTRANS( L' '	,0xE3C4	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><B>                                                          */ DEADTRANS( L'\''	,0xE3DA	,0xA721	,0x0000	), // ''' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><b><%apostrophe>                                             */ DEADTRANS( L'('	,0xE3DB	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><B>                                                          */ DEADTRANS( 0x2019	,0xE3DA	,0xA721	,0x0000	), // '’' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><b><%aprightsinglequotemark>                                 */ DEADTRANS( L'('	,0xE3DC	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><B>                                                          */ DEADTRANS( L'*'	,0xE3DA	,0x2652	,0x0000	), // '*' ➔ "♒" AQUARIUS emoji
/*<!M><b>                                                          */ DEADTRANS( L'*'	,0xE3DD	,0x2652	,0x0000	), // '*' ➔ "♒" AQUARIUS emoji
/*<!M><b>                                                          */ DEADTRANS( L'@'	,0xE3DD	,0x03D0	,0x0000	), // '@' ➔ "ϐ" GREEK BETA SYMBOL
/*<!M><b>                                                          */ DEADTRANS( L'\\'	,0xE3DD	,0x2136	,0x0000	), // '\' ➔ "ℶ" BET SYMBOL
/*<!M><B>                                                          */ DEADTRANS( L'\\'	,0xE3DA	,0x2136	,0x0000	), // '\' ➔ "ℶ" BET SYMBOL
/*<!M><b><%bracketleft>                                            */ DEADTRANS( L'/'	,0xE3DE	,0x22E3	,0x0000	), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketleft><%underscore>                               */ DEADTRANS( L'/'	,0xE3DF	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><b><%bracketright>                                           */ DEADTRANS( L'/'	,0xE3E0	,0x22E3	,0x0000	), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright><%underscore>                              */ DEADTRANS( L'/'	,0xE3E1	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><b><%bracketright><%underscore>                              */ DEADTRANS( 0x00A0	,0xE3E1	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright><%underscore>                              */ DEADTRANS( L' '	,0xE3E1	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright>                                           */ DEADTRANS( 0x00A0	,0xE3E0	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><b><%bracketright>                                           */ DEADTRANS( L' '	,0xE3E0	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><b><%equal>                                                  */ DEADTRANS( L'/'	,0xE3E2	,0x2ACC	,0x0000	), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><b><%equal>                                                  */ DEADTRANS( 0x00A0	,0xE3E2	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><b><%equal>                                                  */ DEADTRANS( L' '	,0xE3E2	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><b>                                                          */ DEADTRANS( L'#'	,0xE3DD	,0x266D	,0x0000	), // '#' ➔ "♭" MUSIC FLAT SIGN
/*<!M><b>                                                          */ DEADTRANS( L'<'	,0xE3DD	,0x297B	,0x0000	), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><b><%minus>                                                  */ DEADTRANS( L'>'	,0xE3E3	,0x2B44	,0x0000	), // '>' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><b><%minus>                                                  */ DEADTRANS( L'c'	,0xE3E3	,0x2AD8	,0x0000	), // 'c' ➔ "⫘" SUPERSET BESIDE AND JOINED BY DASH WITH SUBSET
/*<!M><b>                                                          */ DEADTRANS( L'('	,0xE3DD	,0x02FB	,0x0000	), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><B>                                                          */ DEADTRANS( L'('	,0xE3DA	,0x02FB	,0x0000	), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><b>                                                          */ DEADTRANS( L')'	,0xE3DD	,0x02FC	,0x0000	), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><B>                                                          */ DEADTRANS( L')'	,0xE3DA	,0x02FC	,0x0000	), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><b>                                                          */ DEADTRANS( L'.'	,0xE3DD	,0x2ABE	,0x0000	), // '.' ➔ "⪾" SUPERSET WITH DOT
/*<!M><b>                                                          */ DEADTRANS( L'+'	,0xE3DD	,0x2AC0	,0x0000	), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><b><%slash>                                                  */ DEADTRANS( L'_'	,0xE3E4	,0x2289	,0x0000	), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><b><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE3E4	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><b><%slash>                                                  */ DEADTRANS( L' '	,0xE3E4	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><B>                                                          */ DEADTRANS( L'~'	,0xE3DA	,0x212C	,0x0000	), // '~' ➔ "ℬ" SCRIPT CAPITAL B
/*<!M><b><%tilde>                                                  */ DEADTRANS( L'~'	,0xE3E5	,0x2ACA	,0x0000	), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><b><%tilde>                                                  */ DEADTRANS( 0x00A0	,0xE3E5	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><b><%tilde>                                                  */ DEADTRANS( L' '	,0xE3E5	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><b><%underscore>                                             */ DEADTRANS( L'/'	,0xE3E6	,0x228B	,0x0000	), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><b><%underscore>                                             */ DEADTRANS( 0x00A0	,0xE3E6	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><b><%underscore>                                             */ DEADTRANS( L' '	,0xE3E6	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><B>                                                          */ DEADTRANS( L'A'	,0xE3DA	,0x264E	,0x0000	), // 'A' ➔ "♎" LIBRA emoji
/*<!M><b><a><l>                                                    */ DEADTRANS( L'a'	,0xE3E7	,0x264E	,0x0000	), // 'a' ➔ "♎" LIBRA emoji
/*<!M><b>                                                          */ DEADTRANS( L'b'	,0xE3DD	,0x2AD6	,0x0000	), // 'b' ➔ "⫖" SUPERSET ABOVE SUPERSET
/*<!M><b>                                                          */ DEADTRANS( L'c'	,0xE3DD	,0x2AD4	,0x0000	), // 'c' ➔ "⫔" SUPERSET ABOVE SUBSET
/*<!M><b><d>                                                       */ DEADTRANS( L't'	,0xE3E8	,0x09F3	,0x0000	), // 't' ➔ "৳" BENGALI RUPEE SIGN, Taka BANGLADESH
/*<!M><B><D>                                                       */ DEADTRANS( L'T'	,0xE3E9	,0x09F3	,0x0000	), // 'T' ➔ "৳" BENGALI RUPEE SIGN, Taka BANGLADESH
/*<!M><B>                                                          */ DEADTRANS( L'E'	,0xE3DA	,0x2648	,0x0000	), // 'E' ➔ "♈" ARIES emoji
/*<!M><b><e><l>                                                    */ DEADTRANS( L'i'	,0xE3EA	,0x2648	,0x0000	), // 'i' ➔ "♈" ARIES emoji
/*<!M><B>                                                          */ DEADTRANS( 0x00C9	,0xE3DA	,0x2648	,0x0000	), // 'É' ➔ "♈" ARIES emoji
/*<!M><b><eacute><l>                                               */ DEADTRANS( L'i'	,0xE3EB	,0x2648	,0x0000	), // 'i' ➔ "♈" ARIES emoji
/*<!M><B><I>                                                       */ DEADTRANS( L'L'	,0xE3EC	,0xDC48	,0x0000	), // High surrogate: D83D; U+1F448 'L' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><b><i><p>                                                    */ DEADTRANS( L'l'	,0xE3ED	,0xDC48	,0x0000	), // High surrogate: D83D; U+1F448 'l' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><b><i><p>                                                    */ DEADTRANS( L'r'	,0xE3ED	,0xDC49	,0x0000	), // High surrogate: D83D; U+1F449 'r' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><B><I>                                                       */ DEADTRANS( L'R'	,0xE3EC	,0xDC49	,0x0000	), // High surrogate: D83D; U+1F449 'R' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><b>                                                          */ DEADTRANS( L'k'	,0xE3DD	,0x27F5	,0x0000	), // 'k' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><B>                                                          */ DEADTRANS( L'K'	,0xE3DA	,0x27F5	,0x0000	), // 'K' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><b>                                                          */ DEADTRANS( L'm'	,0xE3DD	,0x266D	,0x0000	), // 'm' ➔ "♭" MUSIC FLAT SIGN
/*<!M><b>                                                          */ DEADTRANS( L'o'	,0xE3DD	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><b>                                                          */ DEADTRANS( L'x'	,0xE3DD	,0x2AC2	,0x0000	), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><b>                                                          */ DEADTRANS( 0x00A0	,0xE3DD	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><b>                                                          */ DEADTRANS( L' '	,0xE3DD	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><C>                                                          */ DEADTRANS( L'*'	,0xE3EE	,0x2653	,0x0000	), // '*' ➔ "♓" PISCES emoji
/*<!M><c>                                                          */ DEADTRANS( L'*'	,0xE3EF	,0x2653	,0x0000	), // '*' ➔ "♓" PISCES emoji
/*<!M><c><%backslash><%bracketleft>                                */ DEADTRANS( L'/'	,0xE3F0	,0x22E3	,0x0000	), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketleft><%underscore>                   */ DEADTRANS( L'/'	,0xE3F1	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><%backslash><%bracketright>                               */ DEADTRANS( L'/'	,0xE3F2	,0x22E3	,0x0000	), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore>                  */ DEADTRANS( L'/'	,0xE3F3	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore>                  */ DEADTRANS( 0x00A0	,0xE3F3	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore>                  */ DEADTRANS( L' '	,0xE3F3	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright>                               */ DEADTRANS( 0x00A0	,0xE3F2	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><%backslash><%bracketright>                               */ DEADTRANS( L' '	,0xE3F2	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><%backslash><%equal>                                      */ DEADTRANS( L'/'	,0xE3F4	,0x2ACC	,0x0000	), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><c><%backslash><%equal>                                      */ DEADTRANS( 0x00A0	,0xE3F4	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><%backslash><%equal>                                      */ DEADTRANS( L' '	,0xE3F4	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><%backslash>                                              */ DEADTRANS( L'<'	,0xE3F5	,0x297B	,0x0000	), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><c><%backslash>                                              */ DEADTRANS( L'-'	,0xE3F5	,0x2B44	,0x0000	), // '-' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><c><%backslash>                                              */ DEADTRANS( L'.'	,0xE3F5	,0x2ABE	,0x0000	), // '.' ➔ "⪾" SUPERSET WITH DOT
/*<!M><c><%backslash>                                              */ DEADTRANS( L'+'	,0xE3F5	,0x2AC0	,0x0000	), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><c><%backslash><%slash>                                      */ DEADTRANS( L'_'	,0xE3F6	,0x2289	,0x0000	), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><c><%backslash><%slash>                                      */ DEADTRANS( 0x00A0	,0xE3F6	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><%backslash><%slash>                                      */ DEADTRANS( L' '	,0xE3F6	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><%backslash><%tilde>                                      */ DEADTRANS( L'~'	,0xE3F7	,0x2ACA	,0x0000	), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><%backslash><%tilde>                                      */ DEADTRANS( 0x00A0	,0xE3F7	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><%backslash><%tilde>                                      */ DEADTRANS( L' '	,0xE3F7	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><%backslash><%underscore>                                 */ DEADTRANS( L'/'	,0xE3F8	,0x228B	,0x0000	), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><c><%backslash><%underscore>                                 */ DEADTRANS( 0x00A0	,0xE3F8	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><%backslash><%underscore>                                 */ DEADTRANS( L' '	,0xE3F8	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><%backslash>                                              */ DEADTRANS( L'o'	,0xE3F5	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><c><%backslash>                                              */ DEADTRANS( L'x'	,0xE3F5	,0x2AC2	,0x0000	), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><c><%backslash>                                              */ DEADTRANS( 0x00A0	,0xE3F5	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><%backslash>                                              */ DEADTRANS( L' '	,0xE3F5	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><C>                                                          */ DEADTRANS( L'|'	,0xE3EE	,0x20B5	,0x0000	), // '|' ➔ "₵" CEDI SIGN
/*<!M><c><%bar>                                                    */ DEADTRANS( L'.'	,0xE3F9	,0xA717	,0x0000	), // '.' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><c><%bar>                                                    */ DEADTRANS( L'_'	,0xE3F9	,0x2AD1	,0x0000	), // '_' ➔ "⫑" CLOSED SUBSET OR EQUAL TO
/*<!M><c><%bar>                                                    */ DEADTRANS( 0x00A0	,0xE3F9	,0x2ACF	,0x0000	), // ' ' ➔ "⫏" CLOSED SUBSET
/*<!M><c><%bar>                                                    */ DEADTRANS( L' '	,0xE3F9	,0x2ACF	,0x0000	), // ' ' ➔ "⫏" CLOSED SUBSET
/*<!M><c><%bracketleft>                                            */ DEADTRANS( L'/'	,0xE3FA	,0x22E2	,0x0000	), // '/' ➔ "⋢" NOT SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft><%underscore>                               */ DEADTRANS( L'/'	,0xE3FB	,0x22E4	,0x0000	), // '/' ➔ "⋤" SQUARE IMAGE OF OR NOT EQUAL TO
/*<!M><c><%bracketleft><%underscore>                               */ DEADTRANS( 0x00A0	,0xE3FB	,0x2291	,0x0000	), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft><%underscore>                               */ DEADTRANS( L' '	,0xE3FB	,0x2291	,0x0000	), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft>                                            */ DEADTRANS( 0x00A0	,0xE3FA	,0x228F	,0x0000	), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketleft>                                            */ DEADTRANS( L' '	,0xE3FA	,0x228F	,0x0000	), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketright>                                           */ DEADTRANS( L'/'	,0xE3FC	,0x22E2	,0x0000	), // '/' ➔ "⋢" NOT SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright><%underscore>                              */ DEADTRANS( L'/'	,0xE3FD	,0x22E4	,0x0000	), // '/' ➔ "⋤" SQUARE IMAGE OF OR NOT EQUAL TO
/*<!M><c><%bracketright><%underscore>                              */ DEADTRANS( 0x00A0	,0xE3FD	,0x2291	,0x0000	), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright><%underscore>                              */ DEADTRANS( L' '	,0xE3FD	,0x2291	,0x0000	), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright>                                           */ DEADTRANS( 0x00A0	,0xE3FC	,0x228F	,0x0000	), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketright>                                           */ DEADTRANS( L' '	,0xE3FC	,0x228F	,0x0000	), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><C>                                                          */ DEADTRANS( L'='	,0xE3EE	,0x20AC	,0x0000	), // '=' ➔ "€" EURO SIGN
/*<!M><c><%equal>                                                  */ DEADTRANS( L'/'	,0xE3FE	,0x2ACB	,0x0000	), // '/' ➔ "⫋" SUBSET OF ABOVE NOT EQUAL TO
/*<!M><c><%equal>                                                  */ DEADTRANS( 0x00A0	,0xE3FE	,0x2AC5	,0x0000	), // ' ' ➔ "⫅" SUBSET OF ABOVE EQUALS SIGN
/*<!M><c><%equal>                                                  */ DEADTRANS( L' '	,0xE3FE	,0x2AC5	,0x0000	), // ' ' ➔ "⫅" SUBSET OF ABOVE EQUALS SIGN
/*<!M><C>                                                          */ DEADTRANS( L'>'	,0xE3EE	,0x293F	,0x0000	), // '>' ➔ "⤿" LOWER LEFT SEMICIRCULAR ANTICLOCKWISE ARROW
/*<!M><C>                                                          */ DEADTRANS( L'#'	,0xE3EE	,0x212D	,0x0000	), // '#' ➔ "ℭ" BLACK-LETTER CAPITAL C
/*<!M><C><%minus>                                                  */ DEADTRANS( L'|'	,0xE3FF	,0xA71A	,0x0000	), // '|' ➔ "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><c><%minus>                                                  */ DEADTRANS( L'|'	,0xE400	,0xA71A	,0x0000	), // '|' ➔ "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><c><%minus>                                                  */ DEADTRANS( L'>'	,0xE400	,0x2979	,0x0000	), // '>' ➔ "⥹" SUBSET ABOVE RIGHTWARDS ARROW
/*<!M><C><%minus>                                                  */ DEADTRANS( L'.'	,0xE3FF	,0xA719	,0x0000	), // '.' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%minus>                                                  */ DEADTRANS( L'.'	,0xE400	,0xA719	,0x0000	), // '.' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%percent>                                                */ DEADTRANS( L'e'	,0xE401	,0xAB62	,0x0000	), // 'e' ➔ "ꭢ" LATIN SMALL LETTER OPEN OE
/*<!M><C><%period>                                                 */ DEADTRANS( L'|'	,0xE402	,0xA717	,0x0000	), // '|' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><c><%period>                                                 */ DEADTRANS( L'|'	,0xE403	,0xA717	,0x0000	), // '|' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><C><%period>                                                 */ DEADTRANS( L'-'	,0xE402	,0xA719	,0x0000	), // '-' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%period>                                                 */ DEADTRANS( L'-'	,0xE403	,0xA719	,0x0000	), // '-' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><C><%period>                                                 */ DEADTRANS( L'/'	,0xE402	,0xA718	,0x0000	), // '/' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%period>                                                 */ DEADTRANS( L'/'	,0xE403	,0xA718	,0x0000	), // '/' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%period>                                                 */ DEADTRANS( 0x00A0	,0xE403	,0x2ABD	,0x0000	), // ' ' ➔ "⪽" SUBSET WITH DOT
/*<!M><c><%period>                                                 */ DEADTRANS( L' '	,0xE403	,0x2ABD	,0x0000	), // ' ' ➔ "⪽" SUBSET WITH DOT
/*<!M><c>                                                          */ DEADTRANS( L'+'	,0xE3EF	,0x2ABF	,0x0000	), // '+' ➔ "⪿" SUBSET WITH PLUS SIGN BELOW
/*<!M><C>                                                          */ DEADTRANS( L'/'	,0xE3EE	,0x20A1	,0x0000	), // '/' ➔ "₡" COLON SIGN
/*<!M><c><%slash>                                                  */ DEADTRANS( L'.'	,0xE404	,0xA718	,0x0000	), // '.' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%slash>                                                  */ DEADTRANS( L'_'	,0xE404	,0x2288	,0x0000	), // '_' ➔ "⊈" NEITHER A SUBSET OF NOR EQUAL TO
/*<!M><c><%slash>                                                  */ DEADTRANS( L'o'	,0xE404	,0x2105	,0x0000	), // 'o' ➔ "℅" CARE OF
/*<!M><c><%slash>                                                  */ DEADTRANS( L'u'	,0xE404	,0x2106	,0x0000	), // 'u' ➔ "℆" CADA UNA
/*<!M><c><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE404	,0x2284	,0x0000	), // ' ' ➔ "⊄" NOT A SUBSET OF
/*<!M><c><%slash>                                                  */ DEADTRANS( L' '	,0xE404	,0x2284	,0x0000	), // ' ' ➔ "⊄" NOT A SUBSET OF
/*<!M><c><%tilde>                                                  */ DEADTRANS( L'~'	,0xE405	,0x2AC9	,0x0000	), // '~' ➔ "⫉" SUBSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><%tilde>                                                  */ DEADTRANS( 0x00A0	,0xE405	,0x2AC7	,0x0000	), // ' ' ➔ "⫇" SUBSET OF ABOVE TILDE OPERATOR
/*<!M><c><%tilde>                                                  */ DEADTRANS( L' '	,0xE405	,0x2AC7	,0x0000	), // ' ' ➔ "⫇" SUBSET OF ABOVE TILDE OPERATOR
/*<!M><c><%underscore>                                             */ DEADTRANS( L'/'	,0xE406	,0x228A	,0x0000	), // '/' ➔ "⊊" SUBSET OF WITH NOT EQUAL TO
/*<!M><c><%underscore>                                             */ DEADTRANS( 0x00A0	,0xE406	,0x2286	,0x0000	), // ' ' ➔ "⊆" SUBSET OF OR EQUAL TO
/*<!M><c><%underscore>                                             */ DEADTRANS( L' '	,0xE406	,0x2286	,0x0000	), // ' ' ➔ "⊆" SUBSET OF OR EQUAL TO
/*<!M><C>                                                          */ DEADTRANS( L'9'	,0xE3EE	,0xA76E	,0x0000	), // '9' ➔ "Ꝯ" LATIN CAPITAL LETTER CON
/*<!M><c>                                                          */ DEADTRANS( L'9'	,0xE3EF	,0xA76F	,0x0000	), // '9' ➔ "ꝯ" LATIN SMALL LETTER CON
/*<!M><c><a>                                                       */ DEADTRANS( L'n'	,0xE407	,0x264B	,0x0000	), // 'n' ➔ "♋" CANCER emoji
/*<!M><C><A>                                                       */ DEADTRANS( L'N'	,0xE408	,0x264B	,0x0000	), // 'N' ➔ "♋" CANCER emoji
/*<!M><C><a>                                                       */ DEADTRANS( L'p'	,0xE409	,0x22D2	,0x0000	), // 'p' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><c><a><p><d><o>                                              */ DEADTRANS( L't'	,0xE40A	,0x2A40	,0x0000	), // 't' ➔ "⩀" INTERSECTION WITH DOT
/*<!M><c><a><p>                                                    */ DEADTRANS( L'l'	,0xE40B	,0x21EC	,0x0000	), // 'l' ➔ "⇬" UPWARDS WHITE ARROW ON PEDESTAL WITH HORIZONTAL BAR, capitals lock
/*<!M><C><A><P>                                                    */ DEADTRANS( L'L'	,0xE40C	,0x21EC	,0x0000	), // 'L' ➔ "⇬" UPWARDS WHITE ARROW ON PEDESTAL WITH HORIZONTAL BAR, capitals lock
/*<!M><c><a><p>                                                    */ DEADTRANS( L'r'	,0xE40B	,0x2651	,0x0000	), // 'r' ➔ "♑" CAPRICORN emoji
/*<!M><C><A><P>                                                    */ DEADTRANS( L'R'	,0xE40C	,0x2651	,0x0000	), // 'R' ➔ "♑" CAPRICORN emoji
/*<!M><c><a><p>                                                    */ DEADTRANS( L's'	,0xE40B	,0x21EA	,0x0000	), // 's' ➔ "⇪" UPWARDS WHITE ARROW FROM BAR, capitals lock
/*<!M><C><A><P>                                                    */ DEADTRANS( L'S'	,0xE40C	,0x2BB8	,0x0000	), // 'S' ➔ "⇪" UPWARDS WHITE ARROW FROM BAR WITH HORIZONTAL BAR, capitals lock
/*<!M><c><a><p>                                                    */ DEADTRANS( 0x00A0	,0xE40B	,0x2229	,0x0000	), // ' ' ➔ "∩" INTERSECTION
/*<!M><c><a><p>                                                    */ DEADTRANS( L' '	,0xE40B	,0x2229	,0x0000	), // ' ' ➔ "∩" INTERSECTION
/*<!M><c>                                                          */ DEADTRANS( L'b'	,0xE3EF	,0x2AD3	,0x0000	), // 'b' ➔ "⫓" SUBSET ABOVE SUPERSET
/*<!M><C>                                                          */ DEADTRANS( L'C'	,0xE3EE	,0x2102	,0x0000	), // 'C' ➔ "ℂ" DOUBLE-STRUCK CAPITAL C
/*<!M><c><c><%bracketleft><%underscore>                            */ DEADTRANS( L'/'	,0xE40D	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><c><%bracketright><%underscore>                           */ DEADTRANS( L'/'	,0xE40E	,0x22E5	,0x0000	), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><c><%bracketright><%underscore>                           */ DEADTRANS( 0x00A0	,0xE40E	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><c><%bracketright><%underscore>                           */ DEADTRANS( L' '	,0xE40E	,0x2292	,0x0000	), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><c><%bracketright>                                        */ DEADTRANS( 0x00A0	,0xE40F	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><c><%bracketright>                                        */ DEADTRANS( L' '	,0xE40F	,0x2290	,0x0000	), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><c><%equal>                                               */ DEADTRANS( L'/'	,0xE410	,0x2ACC	,0x0000	), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><c><c><%equal>                                               */ DEADTRANS( 0x00A0	,0xE410	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><c><%equal>                                               */ DEADTRANS( L' '	,0xE410	,0x2AC6	,0x0000	), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><c>                                                       */ DEADTRANS( L'<'	,0xE411	,0x297B	,0x0000	), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><c><c>                                                       */ DEADTRANS( L'-'	,0xE411	,0x2B44	,0x0000	), // '-' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><c><c>                                                       */ DEADTRANS( L'+'	,0xE411	,0x2AC0	,0x0000	), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><c><c><%slash>                                               */ DEADTRANS( L'_'	,0xE412	,0x2289	,0x0000	), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><c><c><%slash>                                               */ DEADTRANS( 0x00A0	,0xE412	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><c><%slash>                                               */ DEADTRANS( L' '	,0xE412	,0x2285	,0x0000	), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><c><%tilde>                                               */ DEADTRANS( L'~'	,0xE413	,0x2ACA	,0x0000	), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><c><%tilde>                                               */ DEADTRANS( 0x00A0	,0xE413	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><c><%tilde>                                               */ DEADTRANS( L' '	,0xE413	,0x2AC8	,0x0000	), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><c><%underscore>                                          */ DEADTRANS( L'/'	,0xE414	,0x228B	,0x0000	), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><c><c><%underscore>                                          */ DEADTRANS( 0x00A0	,0xE414	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><c><%underscore>                                          */ DEADTRANS( L' '	,0xE414	,0x2287	,0x0000	), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><c>                                                       */ DEADTRANS( L'o'	,0xE411	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><c><c>                                                       */ DEADTRANS( L'x'	,0xE411	,0x2AC2	,0x0000	), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><c><c>                                                       */ DEADTRANS( 0x00A0	,0xE411	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><c>                                                       */ DEADTRANS( L' '	,0xE411	,0x2283	,0x0000	), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c>                                                          */ DEADTRANS( L'e'	,0xE3EF	,0x20A0	,0x0000	), // 'e' ➔ "₠" EURO-CURRENCY SIGN
/*<!M><C>                                                          */ DEADTRANS( L'E'	,0xE3EE	,0x20A0	,0x0000	), // 'E' ➔ "₠" EURO-CURRENCY SIGN
/*<!M><C>                                                          */ DEADTRANS( L'L'	,0xE3EE	,0x2104	,0x0000	), // 'L' ➔ "℄" CENTRE LINE SYMBOL
/*<!M><c>                                                          */ DEADTRANS( L'l'	,0xE3EF	,0xDD2F	,0x0000	), // High surrogate: D83C; U+1F12F 'l' ➔ "🄯" COPYLEFT SYMBOL
/*<!M><C>                                                          */ DEADTRANS( L'M'	,0xE3EE	,0x2384	,0x0000	), // 'M' ➔ "⎄" COMPOSITION SYMBOL
/*<!M><c><m>                                                       */ DEADTRANS( L'p'	,0xE415	,0x2384	,0x0000	), // 'p' ➔ "⎄" COMPOSITION SYMBOL
/*<!M><c><n>                                                       */ DEADTRANS( L'y'	,0xE416	,0x00A5	,0x0000	), // 'y' ➔ "¥" YEN SIGN, Yuan Renminbi CHINA
/*<!M><C><N>                                                       */ DEADTRANS( L'Y'	,0xE417	,0x00A5	,0x0000	), // 'Y' ➔ "¥" YEN SIGN, Yuan Renminbi CHINA
/*<!M><c>                                                          */ DEADTRANS( L'o'	,0xE3EF	,0x2105	,0x0000	), // 'o' ➔ "℅" CARE OF
/*<!M><c>                                                          */ DEADTRANS( L'O'	,0xE3EF	,0x2105	,0x0000	), // 'O' ➔ "℅" CARE OF
/*<!M><C>                                                          */ DEADTRANS( L'O'	,0xE3EE	,0x2105	,0x0000	), // 'O' ➔ "℅" CARE OF
/*<!M><C>                                                          */ DEADTRANS( L'o'	,0xE3EE	,0x2105	,0x0000	), // 'o' ➔ "℅" CARE OF
/*<!M><C>                                                          */ DEADTRANS( L'P'	,0xE3EE	,0x2210	,0x0000	), // 'P' ➔ "∐" N-ARY COPRODUCT
/*<!M><c>                                                          */ DEADTRANS( L'p'	,0xE3EF	,0x2A3F	,0x0000	), // 'p' ➔ "⨿" AMALGAMATION OR COPRODUCT
/*<!M><c>                                                          */ DEADTRANS( L'q'	,0xE3EF	,0x220E	,0x0000	), // 'q' ➔ "∎" END OF PROOF
/*<!M><C>                                                          */ DEADTRANS( L'Q'	,0xE3EE	,0x220E	,0x0000	), // 'Q' ➔ "∎" END OF PROOF
/*<!M><C>                                                          */ DEADTRANS( L'r'	,0xE3EE	,0x20A2	,0x0000	), // 'r' ➔ "₢" CRUZEIRO SIGN
/*<!M><c><r>                                                       */ DEADTRANS( L'c'	,0xE418	,0x20A1	,0x0000	), // 'c' ➔ "₡" COLON SIGN, Costa Rican Colon COSTA RICA
/*<!M><C><R>                                                       */ DEADTRANS( L'C'	,0xE419	,0x20A1	,0x0000	), // 'C' ➔ "₡" COLON SIGN, Costa Rican Colon COSTA RICA
/*<!M><c>                                                          */ DEADTRANS( L't'	,0xE3EF	,0x2388	,0x0000	), // 't' ➔ "⎈" HELM SYMBOL, Control key ISO symbol
/*<!M><C>                                                          */ DEADTRANS( L'T'	,0xE3EE	,0x2388	,0x0000	), // 'T' ➔ "⎈" HELM SYMBOL, Control key ISO symbol
/*<!M><C><u>                                                       */ DEADTRANS( L'p'	,0xE41A	,0x22D3	,0x0000	), // 'p' ➔ "⋓" DOUBLE UNION
/*<!M><c><u><p><d><o>                                              */ DEADTRANS( L't'	,0xE41B	,0x228D	,0x0000	), // 't' ➔ "⊍" MULTISET MULTIPLICATION
/*<!M><c><u><p><p><l><u>                                           */ DEADTRANS( L's'	,0xE41C	,0x228E	,0x0000	), // 's' ➔ "⊎" MULTISET UNION
/*<!M><c><u><p>                                                    */ DEADTRANS( 0x00A0	,0xE41D	,0x222A	,0x0000	), // ' ' ➔ "∪" UNION
/*<!M><c><u><p>                                                    */ DEADTRANS( L' '	,0xE41D	,0x222A	,0x0000	), // ' ' ➔ "∪" UNION
/*<!M><c><u>                                                       */ DEADTRANS( L' '	,0xE41E	,0x2106	,0x0000	), // ' ' ➔ "℆" CADA UNA
/*<!M><C><U>                                                       */ DEADTRANS( L' '	,0xE41F	,0x2106	,0x0000	), // ' ' ➔ "℆" CADA UNA
/*<!M><c>                                                          */ DEADTRANS( L'x'	,0xE3EF	,0x2AC1	,0x0000	), // 'x' ➔ "⫁" SUBSET WITH MULTIPLICATION SIGN BELOW
/*<!M><C>                                                          */ DEADTRANS( 0x00A0	,0xE3EE	,0x2201	,0x0000	), // ' ' ➔ "∁" COMPLEMENT
/*<!M><c>                                                          */ DEADTRANS( 0x00A0	,0xE3EF	,0x2282	,0x0000	), // ' ' ➔ "⊂" SUBSET OF
/*<!M><C>                                                          */ DEADTRANS( L' '	,0xE3EE	,0x2201	,0x0000	), // ' ' ➔ "∁" COMPLEMENT
/*<!M><c>                                                          */ DEADTRANS( L' '	,0xE3EF	,0x2282	,0x0000	), // ' ' ➔ "⊂" SUBSET OF
/*<!M><D>                                                          */ DEADTRANS( L'*'	,0xE420	,0x26CE	,0x0000	), // '*' ➔ "⛎" OPHIUCHUS emoji
/*<!M><d>                                                          */ DEADTRANS( L'*'	,0xE421	,0x26CE	,0x0000	), // '*' ➔ "⛎" OPHIUCHUS emoji
/*<!M><d>                                                          */ DEADTRANS( L'\\'	,0xE421	,0x2138	,0x0000	), // '\' ➔ "ℸ" DALET SYMBOL
/*<!M><D>                                                          */ DEADTRANS( L'\\'	,0xE420	,0x2138	,0x0000	), // '\' ➔ "ℸ" DALET SYMBOL
/*<!M><d>                                                          */ DEADTRANS( L'|'	,0xE421	,0x202C	,0x0000	), // '|' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><d>                                                          */ DEADTRANS( L'='	,0xE421	,0x20AB	,0x0000	), // '=' ➔ "₫" DONG SIGN
/*<!M><D>                                                          */ DEADTRANS( L'='	,0xE420	,0x225C	,0x0000	), // '=' ➔ "≜" DELTA EQUAL TO
/*<!M><D><%greater>                                                */ DEADTRANS( L'Z'	,0xE422	,0x01C4	,0x0000	), // 'Z' ➔ "Ǆ" LATIN CAPITAL LETTER DZ WITH CARON
/*<!M><D><%greater>                                                */ DEADTRANS( L'z'	,0xE422	,0x01C5	,0x0000	), // 'z' ➔ "ǅ" LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*<!M><d><%greater>                                                */ DEADTRANS( L'z'	,0xE423	,0x01C6	,0x0000	), // 'z' ➔ "ǆ" LATIN SMALL LETTER DZ WITH CARON
/*<!M><d>                                                          */ DEADTRANS( L'#'	,0xE421	,0x266F	,0x0000	), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><D>                                                          */ DEADTRANS( L'#'	,0xE420	,0x266F	,0x0000	), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><d>                                                          */ DEADTRANS( L'<'	,0xE421	,0x202C	,0x0000	), // '<' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><D>                                                          */ DEADTRANS( L'%'	,0xE420	,0x2207	,0x0000	), // '%' ➔ "∇" NABLA
/*<!M><D>                                                          */ DEADTRANS( L'_'	,0xE420	,0x2AD2	,0x0000	), // '_' ➔ "⫒" CLOSED SUPERSET OR EQUAL TO
/*<!M><d>                                                          */ DEADTRANS( L'b'	,0xE421	,0x0238	,0x0000	), // 'b' ➔ "ȸ" LATIN SMALL LETTER DB DIGRAPH
/*<!M><D>                                                          */ DEADTRANS( L'D'	,0xE420	,0x2145	,0x0000	), // 'D' ➔ "ⅅ" DOUBLE-STRUCK ITALIC CAPITAL D
/*<!M><d>                                                          */ DEADTRANS( L'd'	,0xE421	,0x2146	,0x0000	), // 'd' ➔ "ⅆ" DOUBLE-STRUCK ITALIC SMALL D
/*<!M><d><e>                                                       */ DEADTRANS( L'b'	,0xE424	,0x21F1	,0x0000	), // 'b' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D><E>                                                       */ DEADTRANS( L'B'	,0xE425	,0x21F1	,0x0000	), // 'B' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><d><e>                                                       */ DEADTRANS( L'f'	,0xE424	,0x225D	,0x0000	), // 'f' ➔ "≝" EQUAL TO BY DEFINITION
/*<!M><d><e>                                                       */ DEADTRANS( L'l'	,0xE424	,0x2327	,0x0000	), // 'l' ➔ "⌧" X IN A RECTANGLE BOX
/*<!M><D><E>                                                       */ DEADTRANS( L'L'	,0xE425	,0x2327	,0x0000	), // 'L' ➔ "⌧" X IN A RECTANGLE BOX
/*<!M><d><e>                                                       */ DEADTRANS( L'z'	,0xE424	,0x02A4	,0x0000	), // 'z' ➔ "ʤ" LATIN SMALL LETTER DEZH DIGRAPH
/*<!M><d><eacute>                                                  */ DEADTRANS( L'b'	,0xE426	,0x21F1	,0x0000	), // 'b' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D><Eacute>                                                  */ DEADTRANS( L'B'	,0xE427	,0x21F1	,0x0000	), // 'B' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D>                                                          */ DEADTRANS( L'H'	,0xE420	,0x00D0	,0x0000	), // 'H' ➔ "Ð" LATIN CAPITAL LETTER ETH
/*<!M><D>                                                          */ DEADTRANS( L'h'	,0xE420	,0x00D0	,0x0000	), // 'h' ➔ "Ð" LATIN CAPITAL LETTER ETH
/*<!M><d>                                                          */ DEADTRANS( L'h'	,0xE421	,0x00F0	,0x0000	), // 'h' ➔ "ð" LATIN SMALL LETTER ETH
/*<!M><d><i><a><m><e><t><e>                                        */ DEADTRANS( L'r'	,0xE428	,0x2300	,0x0000	), // 'r' ➔ "⌀" DIAMETER SIGN
/*<!M><d><i><a><m><e><t><r>                                        */ DEADTRANS( L'e'	,0xE429	,0x2300	,0x0000	), // 'e' ➔ "⌀" DIAMETER SIGN simplified French
/*<!M><d><i><a><m><egrave><t><r>                                   */ DEADTRANS( L'e'	,0xE42A	,0x2300	,0x0000	), // 'e' ➔ "⌀" DIAMETER SIGN French
/*<!M><d>                                                          */ DEADTRANS( L'm'	,0xE421	,0xDD6B	,0x0000	), // High surrogate: D83C; U+1F16B 'm' ➔ "🅫" RAISED MD SIGN
/*<!M><D>                                                          */ DEADTRANS( L'M'	,0xE420	,0xDD6B	,0x0000	), // High surrogate: D83C; U+1F16B 'M' ➔ "🅫" RAISED MD SIGN
/*<!M><D>                                                          */ DEADTRANS( L'r'	,0xE420	,0x20AF	,0x0000	), // 'r' ➔ "₯" DRACHMA SIGN
/*<!M><D>                                                          */ DEADTRANS( L't'	,0xE420	,0x0398	,0x0000	), // 't' ➔ "Θ" GREEK CAPITAL LETTER THETA for use in Rromani
/*<!M><D>                                                          */ DEADTRANS( L'T'	,0xE420	,0x0398	,0x0000	), // 'T' ➔ "Θ" GREEK CAPITAL LETTER THETA for use in Rromani
/*<!M><d>                                                          */ DEADTRANS( L't'	,0xE421	,0x03B8	,0x0000	), // 't' ➔ "θ" GREEK SMALL LETTER THETA for use in Rromani
/*<!M><d>                                                          */ DEADTRANS( L'u'	,0xE421	,0xA771	,0x0000	), // 'u' ➔ "ꝱ" LATIN SMALL LETTER DUM
/*<!M><D>                                                          */ DEADTRANS( L'z'	,0xE420	,0x01F2	,0x0000	), // 'z' ➔ "ǲ" LATIN CAPITAL LETTER D WITH SMALL LETTER Z
/*<!M><d><z>                                                       */ DEADTRANS( L'.'	,0xE42B	,0x01F3	,0x0000	), // '.' ➔ "ǳ" LATIN SMALL LETTER DZ
/*<!M><D><Z>                                                       */ DEADTRANS( L' '	,0xE42C	,0x01F1	,0x0000	), // ' ' ➔ "Ǳ" LATIN CAPITAL LETTER DZ
/*<!M><d><z>                                                       */ DEADTRANS( L' '	,0xE42B	,0x02A3	,0x0000	), // ' ' ➔ "ʣ" LATIN SMALL LETTER DZ DIGRAPH
/*<!M><d>                                                          */ DEADTRANS( 0x00A0	,0xE421	,0x2202	,0x0000	), // ' ' ➔ "∂" PARTIAL DIFFERENTIAL
/*<!M><D>                                                          */ DEADTRANS( 0x00A0	,0xE420	,0x2206	,0x0000	), // ' ' ➔ "∆" INCREMENT
/*<!M><d>                                                          */ DEADTRANS( L' '	,0xE421	,0x2202	,0x0000	), // ' ' ➔ "∂" PARTIAL DIFFERENTIAL
/*<!M><D>                                                          */ DEADTRANS( L' '	,0xE420	,0x2206	,0x0000	), // ' ' ➔ "∆" INCREMENT
/*<!M><degree>                                                     */ DEADTRANS( L'C'	,0xE42D	,0x2103	,0x0000	), // 'C' ➔ "℃" DEGREE CELSIUS
/*<!M><degree>                                                     */ DEADTRANS( L'c'	,0xE42D	,0x2103	,0x0000	), // 'c' ➔ "℃" DEGREE CELSIUS
/*<!M><degree>                                                     */ DEADTRANS( L'F'	,0xE42D	,0x2109	,0x0000	), // 'F' ➔ "℉" DEGREE FAHRENHEIT
/*<!M><degree>                                                     */ DEADTRANS( L'f'	,0xE42D	,0x2109	,0x0000	), // 'f' ➔ "℉" DEGREE FAHRENHEIT
/*<!M><division>                                                   */ DEADTRANS( 0x00D7	,0xE42E	,0x22C7	,0x0000	), // '×' ➔ "⋇" DIVISION TIMES
/*<!M><e>                                                          */ DEADTRANS( L'@'	,0xE42F	,0x03F5	,0x0000	), // '@' ➔ "ϵ" GREEK LUNATE EPSILON SYMBOL
/*<!M><E>                                                          */ DEADTRANS( L'@'	,0xE430	,0x03F6	,0x0000	), // '@' ➔ "϶" GREEK REVERSED LUNATE EPSILON SYMBOL
/*<!M><e><%backslash>                                              */ DEADTRANS( L'@'	,0xE431	,0x03F6	,0x0000	), // '@' ➔ "϶" GREEK REVERSED LUNATE EPSILON SYMBOL
/*<!M><e><%backslash><%bar>                                        */ DEADTRANS( L','	,0xE432	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash><%bar>                                        */ DEADTRANS( 0x00A0	,0xE432	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash><%bar>                                        */ DEADTRANS( L' '	,0xE432	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash>                                              */ DEADTRANS( L','	,0xE431	,0x220D	,0x0000	), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><e><%backslash>                                              */ DEADTRANS( L'-'	,0xE431	,0x22FA	,0x0000	), // '-' ➔ "⋺" CONTAINS WITH LONG HORIZONTAL STROKE
/*<!M><e><%backslash>                                              */ DEADTRANS( L'/'	,0xE431	,0x220C	,0x0000	), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><e><%backslash>                                              */ DEADTRANS( 0x00A0	,0xE431	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><e><%backslash>                                              */ DEADTRANS( L' '	,0xE431	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><e><%bar>                                                    */ DEADTRANS( L','	,0xE433	,0x22F4	,0x0000	), // ',' ➔ "⋴" SMALL ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%bar>                                                    */ DEADTRANS( 0x00A0	,0xE433	,0x22F3	,0x0000	), // ' ' ➔ "⋳" ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%bar>                                                    */ DEADTRANS( L' '	,0xE433	,0x22F3	,0x0000	), // ' ' ➔ "⋳" ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e>                                                          */ DEADTRANS( L'['	,0xE42F	,0x22FF	,0x0000	), // '[' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><e>                                                          */ DEADTRANS( L']'	,0xE42F	,0x22FF	,0x0000	), // ']' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><e>                                                          */ DEADTRANS( L','	,0xE42F	,0x220A	,0x0000	), // ',' ➔ "∊" SMALL ELEMENT OF
/*<!M><E>                                                          */ DEADTRANS( L'='	,0xE430	,0x20AC	,0x0000	), // '=' ➔ "€" EURO SIGN
/*<!M><e>                                                          */ DEADTRANS( L'='	,0xE42F	,0x22F9	,0x0000	), // '=' ➔ "⋹" ELEMENT OF WITH TWO HORIZONTAL STROKES
/*<!M><e>                                                          */ DEADTRANS( L'>'	,0xE42F	,0x202A	,0x0000	), // '>' ➔ "‪" LEFT-TO-RIGHT EMBEDDING
/*<!M><e>                                                          */ DEADTRANS( L'#'	,0xE42F	,0x266A	,0x0000	), // '#' ➔ "♪" EIGHTH NOTE
/*<!M><E>                                                          */ DEADTRANS( L'#'	,0xE430	,0x266B	,0x0000	), // '#' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><e>                                                          */ DEADTRANS( L'<'	,0xE42F	,0x202B	,0x0000	), // '<' ➔ "‫" RIGHT-TO-LEFT EMBEDDING
/*<!M><e>                                                          */ DEADTRANS( L'-'	,0xE42F	,0x22F2	,0x0000	), // '-' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><E>                                                          */ DEADTRANS( L'%'	,0xE430	,0x2108	,0x0000	), // '%' ➔ "℈" SCRUPLE
/*<!M><e><%percent>                                                */ DEADTRANS( L'%'	,0xE434	,0x2AD9	,0x0000	), // '%' ➔ "⫙" ELEMENT OF OPENING DOWNWARDS
/*<!M><e><%percent>                                                */ DEADTRANS( 0x00A0	,0xE434	,0x27D2	,0x0000	), // ' ' ➔ "⟒" ELEMENT OF OPENING UPWARDS
/*<!M><e><%percent>                                                */ DEADTRANS( L' '	,0xE434	,0x27D2	,0x0000	), // ' ' ➔ "⟒" ELEMENT OF OPENING UPWARDS
/*<!M><E>                                                          */ DEADTRANS( L'/'	,0xE430	,0x2204	,0x0000	), // '/' ➔ "∄" THERE DOES NOT EXIST
/*<!M><e>                                                          */ DEADTRANS( L'/'	,0xE42F	,0x2209	,0x0000	), // '/' ➔ "∉" NOT AN ELEMENT OF
/*<!M><e>                                                          */ DEADTRANS( L'~'	,0xE42F	,0x212F	,0x0000	), // '~' ➔ "ℯ" SCRIPT SMALL E
/*<!M><E>                                                          */ DEADTRANS( L'~'	,0xE430	,0x2130	,0x0000	), // '~' ➔ "ℰ" SCRIPT CAPITAL E
/*<!M><e>                                                          */ DEADTRANS( L'_'	,0xE42F	,0x22F8	,0x0000	), // '_' ➔ "⋸" ELEMENT OF WITH UNDERBAR
/*<!M><e>                                                          */ DEADTRANS( L'a'	,0xE42F	,0x2606	,0x0000	), // 'a' ➔ "☆" WHITE STAR
/*<!M><E>                                                          */ DEADTRANS( L'A'	,0xE430	,0x2606	,0x0000	), // 'A' ➔ "☆" WHITE STAR
/*<!M><e>                                                          */ DEADTRANS( L'e'	,0xE42F	,0x2147	,0x0000	), // 'e' ➔ "ⅇ" DOUBLE-STRUCK ITALIC SMALL E
/*<!M><e><m><f>                                                    */ DEADTRANS( L'c'	,0xE435	,0x25CF	,0x0000	), // 'c' ➔ "●" BLACK CIRCLE
/*<!M><E><M><F>                                                    */ DEADTRANS( L'C'	,0xE436	,0x25CF	,0x0000	), // 'C' ➔ "●" BLACK CIRCLE
/*<!M><e><m><f>                                                    */ DEADTRANS( L'r'	,0xE435	,0x25AC	,0x0000	), // 'r' ➔ "▬" BLACK RECTANGLE
/*<!M><E><M><F>                                                    */ DEADTRANS( L'R'	,0xE436	,0x25AC	,0x0000	), // 'R' ➔ "▬" BLACK RECTANGLE
/*<!M><e><m><o>                                                    */ DEADTRANS( L'r'	,0xE437	,0x25AD	,0x0000	), // 'r' ➔ "▭" WHITE RECTANGLE
/*<!M><E><M><O>                                                    */ DEADTRANS( L'R'	,0xE438	,0x25AD	,0x0000	), // 'R' ➔ "▭" WHITE RECTANGLE
/*<!M><e><m>                                                       */ DEADTRANS( L'p'	,0xE439	,0x2205	,0x0000	), // 'p' ➔ "∅" EMPTY SET
/*<!M><e><n>                                                       */ DEADTRANS( L'd'	,0xE43A	,0x21F2	,0x0000	), // 'd' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><E><N>                                                       */ DEADTRANS( L'D'	,0xE43B	,0x21F2	,0x0000	), // 'D' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><e><n><f>                                                    */ DEADTRANS( L'c'	,0xE43C	,0x2022	,0x0000	), // 'c' ➔ "•" BULLET
/*<!M><E><N><F>                                                    */ DEADTRANS( L'C'	,0xE43D	,0x2022	,0x0000	), // 'C' ➔ "•" BULLET
/*<!M><e><n><f>                                                    */ DEADTRANS( L'r'	,0xE43C	,0x25AE	,0x0000	), // 'r' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><E><N><F>                                                    */ DEADTRANS( L'R'	,0xE43D	,0x25AE	,0x0000	), // 'R' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><e><n><f>                                                    */ DEADTRANS( L's'	,0xE43C	,0x25AA	,0x0000	), // 's' ➔ "▪" BLACK SMALL SQUARE
/*<!M><E><N><F>                                                    */ DEADTRANS( L'S'	,0xE43D	,0x25AA	,0x0000	), // 'S' ➔ "▪" BLACK SMALL SQUARE
/*<!M><e><n><o>                                                    */ DEADTRANS( L'c'	,0xE43E	,0x25E6	,0x0000	), // 'c' ➔ "◦" WHITE BULLET
/*<!M><E><N><O>                                                    */ DEADTRANS( L'C'	,0xE43F	,0x25E6	,0x0000	), // 'C' ➔ "◦" WHITE BULLET
/*<!M><e><n><o>                                                    */ DEADTRANS( L's'	,0xE43E	,0x25AB	,0x0000	), // 's' ➔ "▫" WHITE SMALL SQUARE
/*<!M><E><N><O>                                                    */ DEADTRANS( L'S'	,0xE43F	,0x25AB	,0x0000	), // 'S' ➔ "▫" WHITE SMALL SQUARE
/*<!M><e><n>                                                       */ DEADTRANS( L's'	,0xE43A	,0x2205	,0x0000	), // 's' ➔ "∅" EMPTY SET French shortened name
/*<!M><e><n>                                                       */ DEADTRANS( L't'	,0xE43A	,0x2324	,0x0000	), // 't' ➔ "⌤" UP ARROWHEAD BETWEEN TWO HORIZONTAL BARS
/*<!M><E><N>                                                       */ DEADTRANS( L'T'	,0xE43B	,0x2386	,0x0000	), // 'T' ➔ "⎆" ENTER SYMBOL
/*<!M><e><n>                                                       */ DEADTRANS( L'v'	,0xE43A	,0x2709	,0x0000	), // 'v' ➔ "✉" ENVELOPE
/*<!M><E><n><v><e><l><o><p>                                        */ DEADTRANS( L'e'	,0xE440	,0x2709	,0x0000	), // 'e' ➔ "✉" ENVELOPE TeX control has title case
/*<!M><e>                                                          */ DEADTRANS( L'o'	,0xE42F	,0x220E	,0x0000	), // 'o' ➔ "∎" END OF PROOF
/*<!M><E>                                                          */ DEADTRANS( L'O'	,0xE430	,0x220E	,0x0000	), // 'O' ➔ "∎" END OF PROOF
/*<!M><e><s>                                                       */ DEADTRANS( L'c'	,0xE441	,0x238B	,0x0000	), // 'c' ➔ "⎋" BROKEN CIRCLE WITH NORTHWEST ARROW
/*<!M><E><S>                                                       */ DEADTRANS( L'C'	,0xE442	,0x238B	,0x0000	), // 'C' ➔ "⎋" BROKEN CIRCLE WITH NORTHWEST ARROW
/*<!M><e><s>                                                       */ DEADTRANS( L't'	,0xE441	,0x212E	,0x0000	), // 't' ➔ "℮" ESTIMATED SYMBOL
/*<!M><E><S>                                                       */ DEADTRANS( L'T'	,0xE442	,0x212E	,0x0000	), // 'T' ➔ "℮" ESTIMATED SYMBOL
/*<!M><e>                                                          */ DEADTRANS( L't'	,0xE42F	,0xA76B	,0x0000	), // 't' ➔ "ꝫ" LATIN SMALL LETTER ET
/*<!M><E><U>                                                       */ DEADTRANS( L'L'	,0xE443	,0x2107	,0x0000	), // 'L' ➔ "ℇ" EULER CONSTANT
/*<!M><E><u>                                                       */ DEADTRANS( L'l'	,0xE444	,0x2107	,0x0000	), // 'l' ➔ "ℇ" EULER CONSTANT
/*<!M><e><u>                                                       */ DEADTRANS( L'l'	,0xE445	,0x2107	,0x0000	), // 'l' ➔ "ℇ" EULER CONSTANT
/*<!M><e><u>                                                       */ DEADTRANS( L'r'	,0xE445	,0x20AC	,0x0000	), // 'r' ➔ "€" EURO SIGN, Euro EUROPEAN UNION
/*<!M><E><U>                                                       */ DEADTRANS( L'R'	,0xE443	,0x20AC	,0x0000	), // 'R' ➔ "€" EURO SIGN, Euro EUROPEAN UNION
/*<!M><E>                                                          */ DEADTRANS( 0x00A0	,0xE430	,0x2203	,0x0000	), // ' ' ➔ "∃" THERE EXISTS
/*<!M><e>                                                          */ DEADTRANS( 0x00A0	,0xE42F	,0x2208	,0x0000	), // ' ' ➔ "∈" ELEMENT OF
/*<!M><E>                                                          */ DEADTRANS( L' '	,0xE430	,0x2203	,0x0000	), // ' ' ➔ "∃" THERE EXISTS
/*<!M><e>                                                          */ DEADTRANS( L' '	,0xE42F	,0x2208	,0x0000	), // ' ' ➔ "∈" ELEMENT OF
/*<!M><eacute>                                                     */ DEADTRANS( L'a'	,0xE446	,0x2606	,0x0000	), // 'a' ➔ "☆" WHITE STAR
/*<!M><Eacute>                                                     */ DEADTRANS( L'a'	,0xE447	,0x2606	,0x0000	), // 'a' ➔ "☆" WHITE STAR
/*<!M><f>                                                          */ DEADTRANS( L'@'	,0xE448	,0x03D5	,0x0000	), // '@' ➔ "ϕ" GREEK PHI SYMBOL
/*<!M><f>                                                          */ DEADTRANS( L'>'	,0xE448	,0x202D	,0x0000	), // '>' ➔ "‭" LEFT-TO-RIGHT OVERRIDE
/*<!M><f>                                                          */ DEADTRANS( L'#'	,0xE448	,0x266D	,0x0000	), // '#' ➔ "♭" MUSIC FLAT SIGN
/*<!M><f>                                                          */ DEADTRANS( L'<'	,0xE448	,0x202E	,0x0000	), // '<' ➔ "‮" RIGHT-TO-LEFT OVERRIDE
/*<!M><f>                                                          */ DEADTRANS( L'/'	,0xE448	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><F>                                                          */ DEADTRANS( L'/'	,0xE449	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><F>                                                          */ DEADTRANS( L'~'	,0xE449	,0x2131	,0x0000	), // '~' ➔ "ℱ" SCRIPT CAPITAL F
/*<!M><f>                                                          */ DEADTRANS( L'a'	,0xE448	,0x213B	,0x0000	), // 'a' ➔ "℻" FACSIMILE SIGN
/*<!M><F>                                                          */ DEADTRANS( L'a'	,0xE449	,0x213B	,0x0000	), // 'a' ➔ "℻" FACSIMILE SIGN
/*<!M><F>                                                          */ DEADTRANS( L'A'	,0xE449	,0x213B	,0x0000	), // 'A' ➔ "℻" FACSIMILE SIGN
/*<!M><f><e><n>                                                    */ DEADTRANS( L'g'	,0xE44A	,0x02A9	,0x0000	), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><F>                                                          */ DEADTRANS( L'F'	,0xE449	,0x20A3	,0x0000	), // 'F' ➔ "₣" FRENCH FRANC SIGN
/*<!M><F>                                                          */ DEADTRANS( L'f'	,0xE449	,0x20A3	,0x0000	), // 'f' ➔ "₣" FRENCH FRANC SIGN
/*<!M><f>                                                          */ DEADTRANS( L'f'	,0xE448	,0x20A3	,0x0000	), // 'f' ➔ "₣" FRENCH FRANC SIGN
/*<!M><f>                                                          */ DEADTRANS( L'g'	,0xE448	,0x02A9	,0x0000	), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><f>                                                          */ DEADTRANS( L'i'	,0xE448	,0x21F2	,0x0000	), // 'i' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><F>                                                          */ DEADTRANS( L'I'	,0xE449	,0x21F2	,0x0000	), // 'I' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><f><l>                                                       */ DEADTRANS( L'i'	,0xE44B	,0x261A	,0x0000	), // 'i' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><F><L>                                                       */ DEADTRANS( L'I'	,0xE44C	,0x261A	,0x0000	), // 'I' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><f><l>                                                       */ DEADTRANS( L'p'	,0xE44B	,0x204C	,0x0000	), // 'p' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><F><L>                                                       */ DEADTRANS( L'P'	,0xE44C	,0x204C	,0x0000	), // 'P' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><f><l>                                                       */ DEADTRANS( L't'	,0xE44B	,0x25C2	,0x0000	), // 't' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><F><L>                                                       */ DEADTRANS( L'T'	,0xE44C	,0x25C2	,0x0000	), // 'T' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><f><n>                                                       */ DEADTRANS( L'g'	,0xE44D	,0x02A9	,0x0000	), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><f><r>                                                       */ DEADTRANS( L'b'	,0xE44E	,0x220E	,0x0000	), // 'b' ➔ "∎" END OF PROOF
/*<!M><F><R>                                                       */ DEADTRANS( L'B'	,0xE44F	,0x220E	,0x0000	), // 'B' ➔ "∎" END OF PROOF
/*<!M><f><r>                                                       */ DEADTRANS( L'i'	,0xE44E	,0x261B	,0x0000	), // 'i' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><F><R>                                                       */ DEADTRANS( L'I'	,0xE44F	,0x261B	,0x0000	), // 'I' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><f><r>                                                       */ DEADTRANS( L'p'	,0xE44E	,0x204D	,0x0000	), // 'p' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><F><R>                                                       */ DEADTRANS( L'P'	,0xE44F	,0x204D	,0x0000	), // 'P' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><f><r>                                                       */ DEADTRANS( L't'	,0xE44E	,0x2023	,0x0000	), // 't' ➔ "‣" TRIANGULAR BULLET
/*<!M><F><R>                                                       */ DEADTRANS( L'T'	,0xE44F	,0x2023	,0x0000	), // 'T' ➔ "‣" TRIANGULAR BULLET
/*<!M><f>                                                          */ DEADTRANS( L's'	,0xE448	,0x017F	,0x0000	), // 's' ➔ "ſ" LATIN SMALL LETTER LONG S
/*<!M><f><t>                                                       */ DEADTRANS( L'd'	,0xE450	,0x25BE	,0x0000	), // 'd' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><F><T>                                                       */ DEADTRANS( L'D'	,0xE451	,0x25BE	,0x0000	), // 'D' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><f><t>                                                       */ DEADTRANS( L'u'	,0xE450	,0x25B4	,0x0000	), // 'u' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><F><T>                                                       */ DEADTRANS( L'U'	,0xE451	,0x25B4	,0x0000	), // 'U' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><g>                                                          */ DEADTRANS( L'\\'	,0xE452	,0x2137	,0x0000	), // '\' ➔ "ℷ" GIMEL SYMBOL
/*<!M><G>                                                          */ DEADTRANS( L'\\'	,0xE453	,0x2137	,0x0000	), // '\' ➔ "ℷ" GIMEL SYMBOL
/*<!M><g>                                                          */ DEADTRANS( L'|'	,0xE452	,0x20B2	,0x0000	), // '|' ➔ "₲" GUARANI SIGN
/*<!M><G>                                                          */ DEADTRANS( L'|'	,0xE453	,0x20B2	,0x0000	), // '|' ➔ "₲" GUARANI SIGN
/*<!M><G>                                                          */ DEADTRANS( L'%'	,0xE453	,0x2141	,0x0000	), // '%' ➔ "⅁" TURNED SANS-SERIF CAPITAL G
/*<!M><G>                                                          */ DEADTRANS( L'/'	,0xE453	,0x20B2	,0x0000	), // '/' ➔ "₲" GUARANI SIGN
/*<!M><g>                                                          */ DEADTRANS( L'~'	,0xE452	,0x210A	,0x0000	), // '~' ➔ "ℊ" SCRIPT SMALL G
/*<!M><g><e>                                                       */ DEADTRANS( L'l'	,0xE454	,0x20BE	,0x0000	), // 'l' ➔ "₾" LARI SIGN, Lari GEORGIA
/*<!M><G><E>                                                       */ DEADTRANS( L'L'	,0xE455	,0x20BE	,0x0000	), // 'L' ➔ "₾" LARI SIGN, Lari GEORGIA
/*<!M><g><e><m>                                                    */ DEADTRANS( L'e'	,0xE456	,0x264A	,0x0000	), // 'e' ➔ "♊" GEMINI emoji
/*<!M><G><E><M>                                                    */ DEADTRANS( L'E'	,0xE457	,0x264A	,0x0000	), // 'E' ➔ "♊" GEMINI emoji
/*<!M><g><e><m>                                                    */ DEADTRANS( L'i'	,0xE456	,0x264A	,0x0000	), // 'i' ➔ "♊" GEMINI emoji
/*<!M><G><E><M>                                                    */ DEADTRANS( L'I'	,0xE457	,0x264A	,0x0000	), // 'I' ➔ "♊" GEMINI emoji
/*<!M><g><e>                                                       */ DEADTRANS( L'n'	,0xE454	,0x267A	,0x0000	), // 'n' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><G><E>                                                       */ DEADTRANS( L'N'	,0xE455	,0x267A	,0x0000	), // 'N' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><g><eacute><m>                                               */ DEADTRANS( L'e'	,0xE458	,0x264A	,0x0000	), // 'e' ➔ "♊" GEMINI emoji
/*<!M><G><Eacute><M>                                               */ DEADTRANS( L'E'	,0xE459	,0x264A	,0x0000	), // 'E' ➔ "♊" GEMINI emoji
/*<!M><g><g>                                                       */ DEADTRANS( L'@'	,0xE45A	,0x213D	,0x0000	), // '@' ➔ "ℽ" DOUBLE-STRUCK SMALL GAMMA
/*<!M><G><G>                                                       */ DEADTRANS( L'@'	,0xE45B	,0x213E	,0x0000	), // '@' ➔ "ℾ" DOUBLE-STRUCK CAPITAL GAMMA
/*<!M><G>                                                          */ DEADTRANS( L'h'	,0xE453	,0x01A2	,0x0000	), // 'h' ➔ "Ƣ" LATIN CAPITAL LETTER OI, LATIN CAPITAL LETTER GHA
/*<!M><g><h>                                                       */ DEADTRANS( L's'	,0xE45C	,0x20B5	,0x0000	), // 's' ➔ "₵" CEDI SIGN, Ghana Cedi GHANA
/*<!M><G><H>                                                       */ DEADTRANS( L'S'	,0xE45D	,0x20B5	,0x0000	), // 'S' ➔ "₵" CEDI SIGN, Ghana Cedi GHANA
/*<!M><G><H>                                                       */ DEADTRANS( L' '	,0xE45D	,0x01A2	,0x0000	), // ' ' ➔ "Ƣ" LATIN CAPITAL LETTER OI, LATIN CAPITAL LETTER GHA
/*<!M><g><h>                                                       */ DEADTRANS( L' '	,0xE45C	,0x01A3	,0x0000	), // ' ' ➔ "ƣ" LATIN SMALL LETTER OI, LATIN SMALL LETTER GHA
/*<!M><G>                                                          */ DEADTRANS( 0x00A0	,0xE453	,0x27F3	,0x0000	), // ' ' ➔ "⟳" CLOCKWISE GAPPED CIRCLE ARROW
/*<!M><G>                                                          */ DEADTRANS( L' '	,0xE453	,0x27F3	,0x0000	), // ' ' ➔ "⟳" CLOCKWISE GAPPED CIRCLE ARROW
/*<!M><h><%apostrophe>                                             */ DEADTRANS( L'('	,0xE45E	,0xA720	,0x0000	), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H><%apostrophe>                                             */ DEADTRANS( L'('	,0xE45F	,0xA720	,0x0000	), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><h><%aprightsinglequotemark>                                 */ DEADTRANS( L'('	,0xE460	,0xA720	,0x0000	), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H><%aprightsinglequotemark>                                 */ DEADTRANS( L'('	,0xE461	,0xA720	,0x0000	), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H>                                                          */ DEADTRANS( L'#'	,0xE462	,0x210C	,0x0000	), // '#' ➔ "ℌ" BLACK-LETTER CAPITAL H
/*<!M><h>                                                          */ DEADTRANS( L'#'	,0xE463	,0x266A	,0x0000	), // '#' ➔ "♪" EIGHTH NOTE
/*<!M><h>                                                          */ DEADTRANS( L'-'	,0xE463	,0x266B	,0x0000	), // '-' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><H>                                                          */ DEADTRANS( L'-'	,0xE462	,0x266B	,0x0000	), // '-' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><h>                                                          */ DEADTRANS( L'('	,0xE463	,0x02F9	,0x0000	), // '(' ➔ "˹" MODIFIER LETTER BEGIN HIGH TONE
/*<!M><H>                                                          */ DEADTRANS( L'('	,0xE462	,0x02F9	,0x0000	), // '(' ➔ "˹" MODIFIER LETTER BEGIN HIGH TONE
/*<!M><h>                                                          */ DEADTRANS( L')'	,0xE463	,0x02FA	,0x0000	), // ')' ➔ "˺" MODIFIER LETTER END HIGH TONE
/*<!M><H>                                                          */ DEADTRANS( L')'	,0xE462	,0x02FA	,0x0000	), // ')' ➔ "˺" MODIFIER LETTER END HIGH TONE
/*<!M><h>                                                          */ DEADTRANS( L'/'	,0xE463	,0x210F	,0x0000	), // '/' ➔ "ℏ" PLANCK CONSTANT OVER TWO PI
/*<!M><H>                                                          */ DEADTRANS( L'~'	,0xE462	,0x210B	,0x0000	), // '~' ➔ "ℋ" SCRIPT CAPITAL H
/*<!M><h><d><p>                                                    */ DEADTRANS( L'e'	,0xE464	,0x2674	,0x0000	), // 'e' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><H><D><P>                                                    */ DEADTRANS( L'E'	,0xE465	,0x2674	,0x0000	), // 'E' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><H>                                                          */ DEADTRANS( L'H'	,0xE462	,0x210D	,0x0000	), // 'H' ➔ "ℍ" DOUBLE-STRUCK CAPITAL H
/*<!M><H>                                                          */ DEADTRANS( L'N'	,0xE462	,0xA726	,0x0000	), // 'N' ➔ "Ꜧ" LATIN CAPITAL LETTER HENG
/*<!M><H>                                                          */ DEADTRANS( L'n'	,0xE462	,0xA726	,0x0000	), // 'n' ➔ "Ꜧ" LATIN CAPITAL LETTER HENG
/*<!M><h>                                                          */ DEADTRANS( L'n'	,0xE463	,0xA727	,0x0000	), // 'n' ➔ "ꜧ" LATIN SMALL LETTER HENG
/*<!M><h><o>                                                       */ DEADTRANS( L'm'	,0xE466	,0x21F1	,0x0000	), // 'm' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><H><O>                                                       */ DEADTRANS( L'M'	,0xE467	,0x21F1	,0x0000	), // 'M' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><h>                                                          */ DEADTRANS( L'v'	,0xE463	,0x0195	,0x0000	), // 'v' ➔ "ƕ" LATIN SMALL LETTER HV
/*<!M><H>                                                          */ DEADTRANS( L'V'	,0xE462	,0x01F6	,0x0000	), // 'V' ➔ "Ƕ" LATIN CAPITAL LETTER HWAIR
/*<!M><H>                                                          */ DEADTRANS( L'v'	,0xE462	,0x01F6	,0x0000	), // 'v' ➔ "Ƕ" LATIN CAPITAL LETTER HWAIR
/*<!M><H>                                                          */ DEADTRANS( 0x00A0	,0xE462	,0x2207	,0x0000	), // ' ' ➔ "∇" NABLA
/*<!M><H>                                                          */ DEADTRANS( L' '	,0xE462	,0x2207	,0x0000	), // ' ' ➔ "∇" NABLA
/*<!M><i><%at>                                                     */ DEADTRANS( L'%'	,0xE468	,0x2129	,0x0000	), // '%' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%at>                                                     */ DEADTRANS( 0x00A0	,0xE468	,0x2129	,0x0000	), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%at>                                                     */ DEADTRANS( L' '	,0xE468	,0x2129	,0x0000	), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i>                                                          */ DEADTRANS( L'|'	,0xE469	,0x2068	,0x0000	), // '|' ➔ "⁨" FIRST STRONG ISOLATE
/*<!M><I><%bracketleft>                                            */ DEADTRANS( L']'	,0xE46A	,0x29EE	,0x0000	), // ']' ➔ "⧮" ERROR-BARRED WHITE SQUARE
/*<!M><I><%bracketleft>                                            */ DEADTRANS( L'#'	,0xE46A	,0x29EF	,0x0000	), // '#' ➔ "⧯" ERROR-BARRED BLACK SQUARE
/*<!M><I>                                                          */ DEADTRANS( L']'	,0xE46B	,0x29EE	,0x0000	), // ']' ➔ "⧮" ERROR-BARRED WHITE SQUARE
/*<!M><i>                                                          */ DEADTRANS( L'='	,0xE469	,0x2069	,0x0000	), // '=' ➔ "⁩" POP DIRECTIONAL ISOLATE
/*<!M><i>                                                          */ DEADTRANS( L'>'	,0xE469	,0x2066	,0x0000	), // '>' ➔ "⁦" LEFT-TO-RIGHT ISOLATE
/*<!M><I>                                                          */ DEADTRANS( L'>'	,0xE46B	,0x29F0	,0x0000	), // '>' ➔ "⧰" ERROR-BARRED WHITE DIAMOND
/*<!M><I>                                                          */ DEADTRANS( L'#'	,0xE46B	,0x2111	,0x0000	), // '#' ➔ "ℑ" BLACK-LETTER CAPITAL I
/*<!M><i>                                                          */ DEADTRANS( L'<'	,0xE469	,0x2067	,0x0000	), // '<' ➔ "⁧" RIGHT-TO-LEFT ISOLATE
/*<!M><I><%less>                                                   */ DEADTRANS( L'>'	,0xE46C	,0x29F0	,0x0000	), // '>' ➔ "⧰" ERROR-BARRED WHITE DIAMOND
/*<!M><I><%less>                                                   */ DEADTRANS( L'#'	,0xE46C	,0x29F1	,0x0000	), // '#' ➔ "⧱" ERROR-BARRED BLACK DIAMOND
/*<!M><i><%percent>                                                */ DEADTRANS( L'@'	,0xE46D	,0x2129	,0x0000	), // '@' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%percent>                                                */ DEADTRANS( 0x00A0	,0xE46D	,0x2129	,0x0000	), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%percent>                                                */ DEADTRANS( L' '	,0xE46D	,0x2129	,0x0000	), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><I>                                                          */ DEADTRANS( L'~'	,0xE46B	,0x2110	,0x0000	), // '~' ➔ "ℐ" SCRIPT CAPITAL I
/*<!M><I><%underscore>                                             */ DEADTRANS( L'\''	,0xE46E	,0x2AE0	,0x0000	), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><I><%underscore>                                             */ DEADTRANS( L'|'	,0xE46E	,0x27D8	,0x0000	), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><I><%underscore>                                             */ DEADTRANS( 0x00A0	,0xE46E	,0x22A5	,0x0000	), // ' ' ➔ "⊥" UP TACK
/*<!M><I><%underscore>                                             */ DEADTRANS( L' '	,0xE46E	,0x22A5	,0x0000	), // ' ' ➔ "⊥" UP TACK
/*<!M><i>                                                          */ DEADTRANS( L'1'	,0xE469	,0xA70D	,0x0000	), // '1' ➔ "꜍" MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><I>                                                          */ DEADTRANS( L'1'	,0xE46B	,0xA70D	,0x0000	), // '1' ➔ "꜍" MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><i>                                                          */ DEADTRANS( L'2'	,0xE469	,0xA70E	,0x0000	), // '2' ➔ "꜎" MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><I>                                                          */ DEADTRANS( L'2'	,0xE46B	,0xA70E	,0x0000	), // '2' ➔ "꜎" MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><i>                                                          */ DEADTRANS( L'3'	,0xE469	,0xA70F	,0x0000	), // '3' ➔ "꜏" MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*<!M><I>                                                          */ DEADTRANS( L'3'	,0xE46B	,0xA70F	,0x0000	), // '3' ➔ "꜏" MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*<!M><i>                                                          */ DEADTRANS( L'4'	,0xE469	,0xA710	,0x0000	), // '4' ➔ "꜐" MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*<!M><I>                                                          */ DEADTRANS( L'4'	,0xE46B	,0xA710	,0x0000	), // '4' ➔ "꜐" MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*<!M><i>                                                          */ DEADTRANS( L'5'	,0xE469	,0xA711	,0x0000	), // '5' ➔ "꜑" MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*<!M><I>                                                          */ DEADTRANS( L'5'	,0xE46B	,0xA711	,0x0000	), // '5' ➔ "꜑" MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*<!M><i>                                                          */ DEADTRANS( L'e'	,0xE469	,0xAB61	,0x0000	), // 'e' ➔ "ꭡ" LATIN SMALL LETTER IOTIFIED E
/*<!M><I>                                                          */ DEADTRANS( L'I'	,0xE46B	,0x2AFF	,0x0000	), // 'I' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><i><i>                                                       */ DEADTRANS( L'/'	,0xE46F	,0x2148	,0x0000	), // '/' ➔ "ⅈ" DOUBLE-STRUCK ITALIC SMALL I
/*<!M><i><i>                                                       */ DEADTRANS( 0x00A0	,0xE46F	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><i><i>                                                       */ DEADTRANS( L' '	,0xE46F	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><I>                                                          */ DEADTRANS( L'J'	,0xE46B	,0x0132	,0x0000	), // 'J' ➔ "Ĳ" LATIN CAPITAL LIGATURE IJ
/*<!M><I>                                                          */ DEADTRANS( L'j'	,0xE46B	,0x0132	,0x0000	), // 'j' ➔ "Ĳ" LATIN CAPITAL LIGATURE IJ
/*<!M><i>                                                          */ DEADTRANS( L'j'	,0xE469	,0x0133	,0x0000	), // 'j' ➔ "ĳ" LATIN SMALL LIGATURE IJ
/*<!M><i><l>                                                       */ DEADTRANS( L's'	,0xE470	,0x20AA	,0x0000	), // 's' ➔ "₪" NEW SHEQEL SIGN, New Israeli Sheqel ISRAEL
/*<!M><I><L>                                                       */ DEADTRANS( L'S'	,0xE471	,0x20AA	,0x0000	), // 'S' ➔ "₪" NEW SHEQEL SIGN, New Israeli Sheqel ISRAEL
/*<!M><i><n>                                                       */ DEADTRANS( L'r'	,0xE472	,0x20B9	,0x0000	), // 'r' ➔ "₹" INDIAN RUPEE SIGN, Indian Rupee INDIA, BHUTAN
/*<!M><I><N>                                                       */ DEADTRANS( L'R'	,0xE473	,0x20B9	,0x0000	), // 'R' ➔ "₹" INDIAN RUPEE SIGN, Indian Rupee INDIA, BHUTAN
/*<!M><i><n><t><e><r><s><e>                                        */ DEADTRANS( L'c'	,0xE474	,0x2229	,0x0000	), // 'c' ➔ "∩" INTERSECTION French truncated name
/*<!M><i>                                                          */ DEADTRANS( L'o'	,0xE469	,0x2AF0	,0x0000	), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><I>                                                          */ DEADTRANS( L'o'	,0xE46B	,0x2AF0	,0x0000	), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><I><O>                                                       */ DEADTRANS( L'#'	,0xE475	,0x29F3	,0x0000	), // '#' ➔ "⧳" ERROR-BARRED BLACK CIRCLE
/*<!M><I><O>                                                       */ DEADTRANS( 0x00A0	,0xE475	,0x29F2	,0x0000	), // ' ' ➔ "⧲" ERROR-BARRED WHITE CIRCLE
/*<!M><I><O>                                                       */ DEADTRANS( L' '	,0xE475	,0x29F2	,0x0000	), // ' ' ➔ "⧲" ERROR-BARRED WHITE CIRCLE
/*<!M><i><p>                                                       */ DEADTRANS( L'd'	,0xE476	,0x261B	,0x0000	), // 'd' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><I><P>                                                       */ DEADTRANS( L'D'	,0xE477	,0x261B	,0x0000	), // 'D' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><i><p>                                                       */ DEADTRANS( L'g'	,0xE476	,0x261A	,0x0000	), // 'g' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><I><P>                                                       */ DEADTRANS( L'G'	,0xE477	,0x261A	,0x0000	), // 'G' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><i><q>                                                       */ DEADTRANS( L'd'	,0xE478	,0x0639	,0x0000	), // 'd' ➔ "ع" ARABIC LETTER AIN, Iraqi Dinar IRAQ
/*<!M><I><Q>                                                       */ DEADTRANS( L'D'	,0xE479	,0x0639	,0x0000	), // 'D' ➔ "ع" ARABIC LETTER AIN, Iraqi Dinar IRAQ
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'd'	,0xE47A	,0xDC49	,0x0000	), // High surrogate: D83D; U+1F449 'd' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'D'	,0xE47B	,0xDC49	,0x0000	), // High surrogate: D83D; U+1F449 'D' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'g'	,0xE47A	,0xDC48	,0x0000	), // High surrogate: D83D; U+1F448 'g' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'G'	,0xE47B	,0xDC48	,0x0000	), // High surrogate: D83D; U+1F448 'G' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><i><r>                                                       */ DEADTRANS( L'r'	,0xE47C	,0xFDFC	,0x0000	), // 'r' ➔ "﷼" RIAL SIGN, Iranian Rial ISLAMIC REPUBLIC OF IRAN
/*<!M><I><R>                                                       */ DEADTRANS( L'R'	,0xE47D	,0xFDFC	,0x0000	), // 'R' ➔ "﷼" RIAL SIGN, Iranian Rial ISLAMIC REPUBLIC OF IRAN
/*<!M><I>                                                          */ DEADTRANS( L'S'	,0xE46B	,0xA76C	,0x0000	), // 'S' ➔ "Ꝭ" LATIN CAPITAL LETTER IS
/*<!M><I>                                                          */ DEADTRANS( L's'	,0xE46B	,0xA76C	,0x0000	), // 's' ➔ "Ꝭ" LATIN CAPITAL LETTER IS
/*<!M><i>                                                          */ DEADTRANS( L's'	,0xE469	,0xA76D	,0x0000	), // 's' ➔ "ꝭ" LATIN SMALL LETTER IS
/*<!M><j>                                                          */ DEADTRANS( L'!'	,0xE47E	,0x297E	,0x0000	), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><J>                                                          */ DEADTRANS( L'!'	,0xE47F	,0x297E	,0x0000	), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><j>                                                          */ DEADTRANS( L'>'	,0xE47E	,0x22B1	,0x0000	), // '>' ➔ "⊱" SUCCEEDS UNDER RELATION
/*<!M><j>                                                          */ DEADTRANS( L'<'	,0xE47E	,0x22B0	,0x0000	), // '<' ➔ "⊰" PRECEDES UNDER RELATION
/*<!M><j>                                                          */ DEADTRANS( L'-'	,0xE47E	,0x297C	,0x0000	), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><J>                                                          */ DEADTRANS( L'-'	,0xE47F	,0x297C	,0x0000	), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><j>                                                          */ DEADTRANS( L'a'	,0xE47E	,0xAB60	,0x0000	), // 'a' ➔ "ꭠ" LATIN SMALL LETTER SAKHA YAT
/*<!M><j>                                                          */ DEADTRANS( L'j'	,0xE47E	,0x2149	,0x0000	), // 'j' ➔ "ⅉ" DOUBLE-STRUCK ITALIC SMALL J
/*<!M><j><p>                                                       */ DEADTRANS( L'y'	,0xE480	,0x00A5	,0x0000	), // 'y' ➔ "¥" YEN SIGN, Yen JAPAN
/*<!M><J><P>                                                       */ DEADTRANS( L'Y'	,0xE481	,0x00A5	,0x0000	), // 'Y' ➔ "¥" YEN SIGN, Yen JAPAN
/*<!M><k>                                                          */ DEADTRANS( L'@'	,0xE482	,0x03F0	,0x0000	), // '@' ➔ "ϰ" GREEK KAPPA SYMBOL
/*<!M><k>                                                          */ DEADTRANS( L'='	,0xE482	,0x20AD	,0x0000	), // '=' ➔ "₭" KIP SIGN
/*<!M><K>                                                          */ DEADTRANS( L'='	,0xE483	,0x20AD	,0x0000	), // '=' ➔ "₭" KIP SIGN
/*<!M><k>                                                          */ DEADTRANS( L'-'	,0xE482	,0x20AD	,0x0000	), // '-' ➔ "₭" KIP SIGN
/*<!M><K>                                                          */ DEADTRANS( L'-'	,0xE483	,0x20AD	,0x0000	), // '-' ➔ "₭" KIP SIGN
/*<!M><k>                                                          */ DEADTRANS( L'd'	,0xE482	,0x23F7	,0x0000	), // 'd' ➔ "⏷" BLACK MEDIUM DOWN-POINTING TRIANGLE
/*<!M><K>                                                          */ DEADTRANS( L'D'	,0xE483	,0x23F7	,0x0000	), // 'D' ➔ "⏷" BLACK MEDIUM DOWN-POINTING TRIANGLE
/*<!M><k><g>                                                       */ DEADTRANS( L's'	,0xE484	,0x20C0	,0x0000	), // 's' ➔ "⃀" SOM SIGN, Som KYRGYZSTAN
/*<!M><K><G>                                                       */ DEADTRANS( L'S'	,0xE485	,0x20C0	,0x0000	), // 'S' ➔ "⃀" SOM SIGN, Som KYRGYZSTAN
/*<!M><k><h>                                                       */ DEADTRANS( L'r'	,0xE486	,0x17DB	,0x0000	), // 'r' ➔ "៛" KHMER CURRENCY SYMBOL RIEL, Riel CAMBODIA
/*<!M><K><H>                                                       */ DEADTRANS( L'R'	,0xE487	,0x17DB	,0x0000	), // 'R' ➔ "៛" KHMER CURRENCY SYMBOL RIEL, Riel CAMBODIA
/*<!M><k><o>                                                       */ DEADTRANS( L'm'	,0xE488	,0x203B	,0x0000	), // 'm' ➔ "※" REFERENCE MARK, Japanese kome
/*<!M><K><O>                                                       */ DEADTRANS( L'M'	,0xE489	,0x203B	,0x0000	), // 'M' ➔ "※" REFERENCE MARK, Japanese kome
/*<!M><k><p>                                                       */ DEADTRANS( L'w'	,0xE48A	,0x20A9	,0x0000	), // 'w' ➔ "₩" WON SIGN, North Korean Won THE DEMOCRATIC PEOPLE’S REPUBLIC OF KOREA
/*<!M><K><P>                                                       */ DEADTRANS( L'W'	,0xE48B	,0x20A9	,0x0000	), // 'W' ➔ "₩" WON SIGN, North Korean Won THE DEMOCRATIC PEOPLE’S REPUBLIC OF KOREA
/*<!M><k><r>                                                       */ DEADTRANS( L'w'	,0xE48C	,0x20A9	,0x0000	), // 'w' ➔ "₩" WON SIGN, Won KOREA (THE REPUBLIC OF)
/*<!M><K><R>                                                       */ DEADTRANS( L'W'	,0xE48D	,0x20A9	,0x0000	), // 'W' ➔ "₩" WON SIGN, Won KOREA (THE REPUBLIC OF)
/*<!M><k>                                                          */ DEADTRANS( L'u'	,0xE482	,0x23F6	,0x0000	), // 'u' ➔ "⏶" BLACK MEDIUM UP-POINTING TRIANGLE
/*<!M><K>                                                          */ DEADTRANS( L'U'	,0xE483	,0x23F6	,0x0000	), // 'U' ➔ "⏶" BLACK MEDIUM UP-POINTING TRIANGLE
/*<!M><k><z>                                                       */ DEADTRANS( L't'	,0xE48E	,0x20B8	,0x0000	), // 't' ➔ "₸" TENGE SIGN, Tenge KAZAKHSTAN
/*<!M><K><Z>                                                       */ DEADTRANS( L'T'	,0xE48F	,0x20B8	,0x0000	), // 'T' ➔ "₸" TENGE SIGN, Tenge KAZAKHSTAN
/*<!M><l><%apostrophe>                                             */ DEADTRANS( L'('	,0xE490	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%apostrophe>                                             */ DEADTRANS( L'('	,0xE491	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><l><%aprightsinglequotemark>                                 */ DEADTRANS( L'('	,0xE492	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%aprightsinglequotemark>                                 */ DEADTRANS( L'('	,0xE493	,0xA721	,0x0000	), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%backslash>                                              */ DEADTRANS( L'.'	,0xE494	,0x27D3	,0x0000	), // '.' ➔ "⟓" LOWER RIGHT CORNER WITH DOT
/*<!M><L><%backslash>                                              */ DEADTRANS( 0x00A0	,0xE494	,0x2143	,0x0000	), // ' ' ➔ "⅃" REVERSED SANS-SERIF CAPITAL L
/*<!M><L><%backslash>                                              */ DEADTRANS( L' '	,0xE494	,0x2143	,0x0000	), // ' ' ➔ "⅃" REVERSED SANS-SERIF CAPITAL L
/*<!M><L>                                                          */ DEADTRANS( L']'	,0xE495	,0x299C	,0x0000	), // ']' ➔ "⦜" RIGHT ANGLE VARIANT WITH SQUARE
/*<!M><L>                                                          */ DEADTRANS( L'='	,0xE495	,0x20A4	,0x0000	), // '=' ➔ "₤" LIRA SIGN
/*<!M><l>                                                          */ DEADTRANS( L'-'	,0xE496	,0x00A3	,0x0000	), // '-' ➔ "£" POUND SIGN
/*<!M><L>                                                          */ DEADTRANS( L'-'	,0xE495	,0x00A3	,0x0000	), // '-' ➔ "£" POUND SIGN
/*<!M><l>                                                          */ DEADTRANS( L'('	,0xE496	,0x02FB	,0x0000	), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><L>                                                          */ DEADTRANS( L'('	,0xE495	,0x02FB	,0x0000	), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><l>                                                          */ DEADTRANS( L')'	,0xE496	,0x02FC	,0x0000	), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><L><%parenright>                                             */ DEADTRANS( L'.'	,0xE497	,0x299D	,0x0000	), // '.' ➔ "⦝" MEASURED RIGHT ANGLE WITH DOT
/*<!M><L><%parenright>                                             */ DEADTRANS( 0x00A0	,0xE497	,0x22BE	,0x0000	), // ' ' ➔ "⊾" RIGHT ANGLE WITH ARC
/*<!M><L><%parenright>                                             */ DEADTRANS( L' '	,0xE497	,0x22BE	,0x0000	), // ' ' ➔ "⊾" RIGHT ANGLE WITH ARC
/*<!M><L><%percent><%percent>                                      */ DEADTRANS( L'.'	,0xE498	,0x27D4	,0x0000	), // '.' ➔ "⟔" UPPER LEFT CORNER WITH DOT
/*<!M><L><%percent>                                                */ DEADTRANS( L'.'	,0xE499	,0x27D4	,0x0000	), // '.' ➔ "⟔" UPPER LEFT CORNER WITH DOT
/*<!M><L><%percent>                                                */ DEADTRANS( 0x00A0	,0xE499	,0x2142	,0x0000	), // ' ' ➔ "⅂" TURNED SANS-SERIF CAPITAL L
/*<!M><L><%percent>                                                */ DEADTRANS( L' '	,0xE499	,0x2142	,0x0000	), // ' ' ➔ "⅂" TURNED SANS-SERIF CAPITAL L
/*<!M><L>                                                          */ DEADTRANS( L'.'	,0xE495	,0x013F	,0x0000	), // '.' ➔ "Ŀ" LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*<!M><l>                                                          */ DEADTRANS( L'.'	,0xE496	,0x0140	,0x0000	), // '.' ➔ "ŀ" LATIN SMALL LETTER L WITH MIDDLE DOT
/*<!M><L>                                                          */ DEADTRANS( L'/'	,0xE495	,0x27C0	,0x0000	), // '/' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><L>                                                          */ DEADTRANS( L'~'	,0xE495	,0x2112	,0x0000	), // '~' ➔ "ℒ" SCRIPT CAPITAL L
/*<!M><l>                                                          */ DEADTRANS( L'~'	,0xE496	,0x2113	,0x0000	), // '~' ➔ "ℓ" SCRIPT SMALL L
/*<!M><l>                                                          */ DEADTRANS( L'2'	,0xE496	,0x21E7	,0x0000	), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><L>                                                          */ DEADTRANS( L'2'	,0xE495	,0x21E7	,0x0000	), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><l>                                                          */ DEADTRANS( L'3'	,0xE496	,0x026E	,0x0000	), // '3' ➔ "ɮ" LATIN SMALL LETTER LEZH
/*<!M><L>                                                          */ DEADTRANS( L'3'	,0xE495	,0x21EE	,0x0000	), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><l>                                                          */ DEADTRANS( L'5'	,0xE496	,0x27F0	,0x0000	), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><L>                                                          */ DEADTRANS( L'5'	,0xE495	,0x27F0	,0x0000	), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><l><a>                                                       */ DEADTRANS( L'k'	,0xE49A	,0x20AD	,0x0000	), // 'k' ➔ "₭" KIP SIGN, Lao Kip THE LAO PEOPLE’S DEMOCRATIC REPUBLIC
/*<!M><L><A>                                                       */ DEADTRANS( L'K'	,0xE49B	,0x20AD	,0x0000	), // 'K' ➔ "₭" KIP SIGN, Lao Kip THE LAO PEOPLE’S DEMOCRATIC REPUBLIC
/*<!M><l><b>                                                       */ DEADTRANS( L'-'	,0xE49C	,0x2114	,0x0000	), // '-' ➔ "℔" L B BAR SYMBOL
/*<!M><l><d><p>                                                    */ DEADTRANS( L'e'	,0xE49D	,0x2676	,0x0000	), // 'e' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><L><D><P>                                                    */ DEADTRANS( L'E'	,0xE49E	,0x2676	,0x0000	), // 'E' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><l><e>                                                       */ DEADTRANS( L'o'	,0xE49F	,0x264C	,0x0000	), // 'o' ➔ "♌" LEO emoji
/*<!M><L><E>                                                       */ DEADTRANS( L'O'	,0xE4A0	,0x264C	,0x0000	), // 'O' ➔ "♌" LEO emoji
/*<!M><l><e><z>                                                    */ DEADTRANS( L'h'	,0xE4A1	,0x026E	,0x0000	), // 'h' ➔ "ɮ" LATIN SMALL LETTER LEZH
/*<!M><l>                                                          */ DEADTRANS( L'f'	,0xE496	,0x21B4	,0x0000	), // 'f' ➔ "↴" RIGHTWARDS ARROW WITH CORNER DOWNWARDS
/*<!M><L>                                                          */ DEADTRANS( L'F'	,0xE495	,0x21B4	,0x0000	), // 'F' ➔ "↴" RIGHTWARDS ARROW WITH CORNER DOWNWARDS
/*<!M><l><i><b>                                                    */ DEADTRANS( L'r'	,0xE4A2	,0x264E	,0x0000	), // 'r' ➔ "♎" LIBRA emoji
/*<!M><L><I><B>                                                    */ DEADTRANS( L'R'	,0xE4A3	,0x264E	,0x0000	), // 'R' ➔ "♎" LIBRA emoji
/*<!M><l><i><o>                                                    */ DEADTRANS( L'n'	,0xE4A4	,0x264C	,0x0000	), // 'n' ➔ "♌" LEO emoji
/*<!M><L><I><O>                                                    */ DEADTRANS( L'N'	,0xE4A5	,0x264C	,0x0000	), // 'N' ➔ "♌" LEO emoji
/*<!M><L>                                                          */ DEADTRANS( L'J'	,0xE495	,0x01C7	,0x0000	), // 'J' ➔ "Ǉ" LATIN CAPITAL LETTER LJ
/*<!M><L>                                                          */ DEADTRANS( L'j'	,0xE495	,0x01C8	,0x0000	), // 'j' ➔ "ǈ" LATIN CAPITAL LETTER L WITH SMALL LETTER J
/*<!M><l>                                                          */ DEADTRANS( L'j'	,0xE496	,0x01C9	,0x0000	), // 'j' ➔ "ǉ" LATIN SMALL LETTER LJ
/*<!M><L>                                                          */ DEADTRANS( L'L'	,0xE495	,0x1EFA	,0x0000	), // 'L' ➔ "Ỻ" LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*<!M><L>                                                          */ DEADTRANS( L'l'	,0xE495	,0x1EFA	,0x0000	), // 'l' ➔ "Ỻ" LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*<!M><l>                                                          */ DEADTRANS( L'l'	,0xE496	,0x1EFB	,0x0000	), // 'l' ➔ "ỻ" LATIN SMALL LETTER MIDDLE-WELSH LL
/*<!M><L>                                                          */ DEADTRANS( L'N'	,0xE495	,0x237C	,0x0000	), // 'N' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L>                                                          */ DEADTRANS( L'P'	,0xE495	,0x214A	,0x0000	), // 'P' ➔ "⅊" PROPERTY LINE
/*<!M><l>                                                          */ DEADTRANS( L'p'	,0xE496	,0x214A	,0x0000	), // 'p' ➔ "⅊" PROPERTY LINE
/*<!M><L><p><a><r><e><n><g>                                        */ DEADTRANS( L't'	,0xE4A6	,0x2995	,0x0000	), // 't' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET TeX + HTML under max 9 keysym constraint
/*<!M><l><r><e>                                                    */ DEADTRANS( L't'	,0xE4A7	,0x2BA0	,0x0000	), // 't' ➔ "⮠" DOWNWARDS TRIANGLE-HEADED ARROW WITH LONG TIP LEFTWARDS
/*<!M><L><R><E>                                                    */ DEADTRANS( L'T'	,0xE4A8	,0x2BA0	,0x0000	), // 'T' ➔ "⮠" DOWNWARDS TRIANGLE-HEADED ARROW WITH LONG TIP LEFTWARDS
/*<!M><l>                                                          */ DEADTRANS( L's'	,0xE496	,0x02AA	,0x0000	), // 's' ➔ "ʪ" LATIN SMALL LETTER LS DIGRAPH
/*<!M><l>                                                          */ DEADTRANS( L'u'	,0xE496	,0xA772	,0x0000	), // 'u' ➔ "ꝲ" LATIN SMALL LETTER LUM
/*<!M><l>                                                          */ DEADTRANS( L'z'	,0xE496	,0x02AB	,0x0000	), // 'z' ➔ "ʫ" LATIN SMALL LETTER LZ DIGRAPH
/*<!M><L>                                                          */ DEADTRANS( L'Z'	,0xE495	,0x237C	,0x0000	), // 'Z' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L>                                                          */ DEADTRANS( L'z'	,0xE495	,0x237C	,0x0000	), // 'z' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L>                                                          */ DEADTRANS( 0x00A0	,0xE495	,0x221F	,0x0000	), // ' ' ➔ "∟" RIGHT ANGLE
/*<!M><L>                                                          */ DEADTRANS( L' '	,0xE495	,0x221F	,0x0000	), // ' ' ➔ "∟" RIGHT ANGLE
/*<!M><m>                                                          */ DEADTRANS( L'='	,0xE4A9	,0x225E	,0x0000	), // '=' ➔ "≞" MEASURED BY
/*<!M><m>                                                          */ DEADTRANS( L'>'	,0xE4A9	,0x200E	,0x0000	), // '>' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><m>                                                          */ DEADTRANS( L'<'	,0xE4A9	,0x200F	,0x0000	), // '<' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><m>                                                          */ DEADTRANS( L'%'	,0xE4A9	,0x29E2	,0x0000	), // '%' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><m>                                                          */ DEADTRANS( L'/'	,0xE4A9	,0x20A5	,0x0000	), // '/' ➔ "₥" MILL SIGN
/*<!M><M>                                                          */ DEADTRANS( L'~'	,0xE4AA	,0x2133	,0x0000	), // '~' ➔ "ℳ" SCRIPT CAPITAL M
/*<!M><m>                                                          */ DEADTRANS( L'c'	,0xE4A9	,0xDD6A	,0x0000	), // High surrogate: D83C; U+1F16A 'c' ➔ "🅪" RAISED MC SIGN
/*<!M><M>                                                          */ DEADTRANS( L'C'	,0xE4AA	,0xDD6A	,0x0000	), // High surrogate: D83C; U+1F16A 'C' ➔ "🅪" RAISED MC SIGN
/*<!M><m>                                                          */ DEADTRANS( L'd'	,0xE4A9	,0xDD6B	,0x0000	), // High surrogate: D83C; U+1F16B 'd' ➔ "🅫" RAISED MD SIGN
/*<!M><M>                                                          */ DEADTRANS( L'D'	,0xE4AA	,0xDD6B	,0x0000	), // High surrogate: D83C; U+1F16B 'D' ➔ "🅫" RAISED MD SIGN
/*<!M><m>                                                          */ DEADTRANS( L'h'	,0xE4A9	,0x2127	,0x0000	), // 'h' ➔ "℧" INVERTED OHM SIGN
/*<!M><M>                                                          */ DEADTRANS( L'h'	,0xE4AA	,0x2127	,0x0000	), // 'h' ➔ "℧" INVERTED OHM SIGN
/*<!M><M>                                                          */ DEADTRANS( L'H'	,0xE4AA	,0x2127	,0x0000	), // 'H' ➔ "℧" INVERTED OHM SIGN
/*<!M><m><n>                                                       */ DEADTRANS( L't'	,0xE4AB	,0x20AE	,0x0000	), // 't' ➔ "₮" TUGRIK SIGN, Tugrik MONGOLIA
/*<!M><M><N>                                                       */ DEADTRANS( L'T'	,0xE4AC	,0x20AE	,0x0000	), // 'T' ➔ "₮" TUGRIK SIGN, Tugrik MONGOLIA
/*<!M><m>                                                          */ DEADTRANS( L'r'	,0xE4A9	,0xDD6C	,0x0000	), // High surrogate: D83C; U+1F16C 'r' ➔ "🅬" RAISED MR SIGN
/*<!M><M>                                                          */ DEADTRANS( L'R'	,0xE4AA	,0xDD6C	,0x0000	), // High surrogate: D83C; U+1F16C 'R' ➔ "🅬" RAISED MR SIGN
/*<!M><m>                                                          */ DEADTRANS( L's'	,0xE4A9	,0x2120	,0x0000	), // 's' ➔ "℠" SERVICE MARK
/*<!M><M>                                                          */ DEADTRANS( L'S'	,0xE4AA	,0x2120	,0x0000	), // 'S' ➔ "℠" SERVICE MARK
/*<!M><m>                                                          */ DEADTRANS( L't'	,0xE4A9	,0x2122	,0x0000	), // 't' ➔ "™" TRADE MARK SIGN emoji
/*<!M><M>                                                          */ DEADTRANS( L'T'	,0xE4AA	,0x2122	,0x0000	), // 'T' ➔ "™" TRADE MARK SIGN emoji
/*<!M><m><u>                                                       */ DEADTRANS( L'l'	,0xE4AD	,0x00A6	,0x0000	), // 'l' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><M><U>                                                       */ DEADTRANS( L'L'	,0xE4AE	,0x00A6	,0x0000	), // 'L' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><m><u>                                                       */ DEADTRANS( L'r'	,0xE4AD	,0x20A8	,0x0000	), // 'r' ➔ "₨" RUPEE SIGN, Mauritius Rupee MAURITIUS
/*<!M><M><U>                                                       */ DEADTRANS( L'R'	,0xE4AE	,0x20A8	,0x0000	), // 'R' ➔ "₨" RUPEE SIGN, Mauritius Rupee MAURITIUS
/*<!M><m><u>                                                       */ DEADTRANS( L' '	,0xE4AD	,0xA773	,0x0000	), // ' ' ➔ "ꝳ" LATIN SMALL LETTER MUM
/*<!M><m><v>                                                       */ DEADTRANS( L'r'	,0xE4AF	,0x0783	,0x0000	), // 'r' ➔ "ރ" THAANA LETTER RAA, Rufiyaa MALDIVES
/*<!M><M><V>                                                       */ DEADTRANS( L'R'	,0xE4B0	,0x0783	,0x0000	), // 'R' ➔ "ރ" THAANA LETTER RAA, Rufiyaa MALDIVES
/*<!M><m>                                                          */ DEADTRANS( 0x00A0	,0xE4A9	,0x29E2	,0x0000	), // ' ' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><m>                                                          */ DEADTRANS( L' '	,0xE4A9	,0x29E2	,0x0000	), // ' ' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><multiply>                                                   */ DEADTRANS( 0x00F7	,0xE4B1	,0x22C7	,0x0000	), // '÷' ➔ "⋇" DIVISION TIMES
/*<!M><n>                                                          */ DEADTRANS( L'|'	,0xE4B2	,0x22D4	,0x0000	), // '|' ➔ "⋔" PITCHFORK
/*<!M><n>                                                          */ DEADTRANS( L'['	,0xE4B2	,0x2293	,0x0000	), // '[' ➔ "⊓" SQUARE CAP
/*<!M><N>                                                          */ DEADTRANS( L'['	,0xE4B3	,0x2A05	,0x0000	), // '[' ➔ "⨅" N-ARY SQUARE INTERSECTION OPERATOR
/*<!M><n>                                                          */ DEADTRANS( L']'	,0xE4B2	,0x2293	,0x0000	), // ']' ➔ "⊓" SQUARE CAP
/*<!M><N>                                                          */ DEADTRANS( L']'	,0xE4B3	,0x2A05	,0x0000	), // ']' ➔ "⨅" N-ARY SQUARE INTERSECTION OPERATOR
/*<!M><n>                                                          */ DEADTRANS( L'^'	,0xE4B2	,0x2A44	,0x0000	), // '^' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><N>                                                          */ DEADTRANS( L'='	,0xE4B3	,0x20A6	,0x0000	), // '=' ➔ "₦" NAIRA SIGN
/*<!M><n>                                                          */ DEADTRANS( L'='	,0xE4B2	,0x266C	,0x0000	), // '=' ➔ "♬" BEAMED SIXTEENTH NOTES
/*<!M><N>                                                          */ DEADTRANS( L'>'	,0xE4B3	,0x21AF	,0x0000	), // '>' ➔ "↯" DOWNWARDS ZIGZAG ARROW
/*<!M><n>                                                          */ DEADTRANS( L'>'	,0xE4B2	,0x21B7	,0x0000	), // '>' ➔ "↷" CLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><n>                                                          */ DEADTRANS( L'#'	,0xE4B2	,0x266E	,0x0000	), // '#' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><n>                                                          */ DEADTRANS( L'<'	,0xE4B2	,0x21B6	,0x0000	), // '<' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><n>                                                          */ DEADTRANS( L'.'	,0xE4B2	,0x2A40	,0x0000	), // '.' ➔ "⩀" INTERSECTION WITH DOT
/*<!M><n><%underscore>                                             */ DEADTRANS( L'u'	,0xE4B4	,0x2A49	,0x0000	), // 'u' ➔ "⩉" INTERSECTION ABOVE BAR ABOVE UNION
/*<!M><n><%underscore>                                             */ DEADTRANS( 0x00A0	,0xE4B4	,0x2A4D	,0x0000	), // ' ' ➔ "⩍" CLOSED INTERSECTION WITH SERIFS
/*<!M><n><%underscore>                                             */ DEADTRANS( L' '	,0xE4B4	,0x2A4D	,0x0000	), // ' ' ➔ "⩍" CLOSED INTERSECTION WITH SERIFS
/*<!M><n>                                                          */ DEADTRANS( L'2'	,0xE4B2	,0x21E7	,0x0000	), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><N>                                                          */ DEADTRANS( L'2'	,0xE4B3	,0x21E7	,0x0000	), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><n>                                                          */ DEADTRANS( L'3'	,0xE4B2	,0x21EE	,0x0000	), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><N>                                                          */ DEADTRANS( L'3'	,0xE4B3	,0x21EE	,0x0000	), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><n>                                                          */ DEADTRANS( L'4'	,0xE4B2	,0x2669	,0x0000	), // '4' ➔ "♩" QUARTER NOTE
/*<!M><N>                                                          */ DEADTRANS( L'4'	,0xE4B3	,0x2669	,0x0000	), // '4' ➔ "♩" QUARTER NOTE
/*<!M><n>                                                          */ DEADTRANS( L'5'	,0xE4B2	,0x27F0	,0x0000	), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><N>                                                          */ DEADTRANS( L'5'	,0xE4B3	,0x27F0	,0x0000	), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><n>                                                          */ DEADTRANS( L'8'	,0xE4B2	,0x266A	,0x0000	), // '8' ➔ "♪" EIGHTH NOTE
/*<!M><N>                                                          */ DEADTRANS( L'8'	,0xE4B3	,0x266A	,0x0000	), // '8' ➔ "♪" EIGHTH NOTE
/*<!M><N>                                                          */ DEADTRANS( L'A'	,0xE4B3	,0x22BC	,0x0000	), // 'A' ➔ "⊼" NAND
/*<!M><n><a>                                                       */ DEADTRANS( L'n'	,0xE4B5	,0x22BC	,0x0000	), // 'n' ➔ "⊼" NAND
/*<!M><n><a>                                                       */ DEADTRANS( 0x00A0	,0xE4B5	,0x2A44	,0x0000	), // ' ' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><n><a>                                                       */ DEADTRANS( L' '	,0xE4B5	,0x2A44	,0x0000	), // ' ' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><n><b>                                                       */ DEADTRANS( L's'	,0xE4B6	,0x25BF	,0x0000	), // 's' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><N><B>                                                       */ DEADTRANS( L'S'	,0xE4B7	,0x25BF	,0x0000	), // 'S' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><n><b>                                                       */ DEADTRANS( L't'	,0xE4B6	,0x25BE	,0x0000	), // 't' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><N><B>                                                       */ DEADTRANS( L'T'	,0xE4B7	,0x25BE	,0x0000	), // 'T' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><n>                                                          */ DEADTRANS( L'e'	,0xE4B2	,0x2744	,0x0000	), // 'e' ➔ "❄" SNOWFLAKE emoji
/*<!M><N>                                                          */ DEADTRANS( L'E'	,0xE4B3	,0x2744	,0x0000	), // 'E' ➔ "❄" SNOWFLAKE emoji
/*<!M><N>                                                          */ DEADTRANS( L'g'	,0xE4B3	,0x014A	,0x0000	), // 'g' ➔ "Ŋ" LATIN CAPITAL LETTER ENG
/*<!M><n><g>                                                       */ DEADTRANS( L'n'	,0xE4B8	,0x20A6	,0x0000	), // 'n' ➔ "₦" NAIRA SIGN, Naira NIGERIA
/*<!M><N><G>                                                       */ DEADTRANS( L'N'	,0xE4B9	,0x20A6	,0x0000	), // 'N' ➔ "₦" NAIRA SIGN, Naira NIGERIA
/*<!M><N><G>                                                       */ DEADTRANS( L' '	,0xE4B9	,0x014A	,0x0000	), // ' ' ➔ "Ŋ" LATIN CAPITAL LETTER ENG
/*<!M><n><g>                                                       */ DEADTRANS( L' '	,0xE4B8	,0x014B	,0x0000	), // ' ' ➔ "ŋ" LATIN SMALL LETTER ENG
/*<!M><n>                                                          */ DEADTRANS( L'I'	,0xE4B2	,0x2ADB	,0x0000	), // 'I' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><N>                                                          */ DEADTRANS( L'J'	,0xE4B3	,0x01CA	,0x0000	), // 'J' ➔ "Ǌ" LATIN CAPITAL LETTER NJ
/*<!M><N>                                                          */ DEADTRANS( L'j'	,0xE4B3	,0x01CB	,0x0000	), // 'j' ➔ "ǋ" LATIN CAPITAL LETTER N WITH SMALL LETTER J
/*<!M><n>                                                          */ DEADTRANS( L'j'	,0xE4B2	,0x01CC	,0x0000	), // 'j' ➔ "ǌ" LATIN SMALL LETTER NJ
/*<!M><n><m>                                                       */ DEADTRANS( L'l'	,0xE4BA	,0x21ED	,0x0000	), // 'l' ➔ "⇭" UPWARDS WHITE ARROW ON PEDESTAL WITH VERTICAL BAR, numeric lock
/*<!M><N><M>                                                       */ DEADTRANS( L'L'	,0xE4BB	,0x21ED	,0x0000	), // 'L' ➔ "⇭" UPWARDS WHITE ARROW ON PEDESTAL WITH VERTICAL BAR, numeric lock
/*<!M><N>                                                          */ DEADTRANS( L'N'	,0xE4B3	,0x2115	,0x0000	), // 'N' ➔ "ℕ" DOUBLE-STRUCK CAPITAL N
/*<!M><n>                                                          */ DEADTRANS( L'n'	,0xE4B2	,0x2A4B	,0x0000	), // 'n' ➔ "⩋" INTERSECTION BESIDE AND JOINED WITH INTERSECTION
/*<!M><N>                                                          */ DEADTRANS( L'o'	,0xE4B3	,0x2116	,0x0000	), // 'o' ➔ "№" NUMERO SIGN
/*<!M><n>                                                          */ DEADTRANS( L'O'	,0xE4B2	,0x2116	,0x0000	), // 'O' ➔ "№" NUMERO SIGN
/*<!M><n><o>                                                       */ DEADTRANS( L'_'	,0xE4BC	,0x2116	,0x0000	), // '_' ➔ "№" NUMERO SIGN
/*<!M><N><O>                                                       */ DEADTRANS( L'_'	,0xE4BD	,0x2116	,0x0000	), // '_' ➔ "№" NUMERO SIGN
/*<!M><n><o>                                                       */ DEADTRANS( L'r'	,0xE4BC	,0x22BD	,0x0000	), // 'r' ➔ "⊽" NOR
/*<!M><N><O>                                                       */ DEADTRANS( L'R'	,0xE4BD	,0x22BD	,0x0000	), // 'R' ➔ "⊽" NOR
/*<!M><n>                                                          */ DEADTRANS( L's'	,0xE4B2	,0x20AA	,0x0000	), // 's' ➔ "₪" NEW SHEQEL SIGN
/*<!M><N>                                                          */ DEADTRANS( L'S'	,0xE4B3	,0x20AA	,0x0000	), // 'S' ➔ "₪" NEW SHEQEL SIGN
/*<!M><n><u>                                                       */ DEADTRANS( L'm'	,0xE4BE	,0xA774	,0x0000	), // 'm' ➔ "ꝴ" LATIN SMALL LETTER NUM
/*<!M><n><u>                                                       */ DEADTRANS( 0x00A0	,0xE4BE	,0x2A47	,0x0000	), // ' ' ➔ "⩇" INTERSECTION ABOVE UNION
/*<!M><n><u>                                                       */ DEADTRANS( L' '	,0xE4BE	,0x2A47	,0x0000	), // ' ' ➔ "⩇" INTERSECTION ABOVE UNION
/*<!M><n>                                                          */ DEADTRANS( 0x00A0	,0xE4B2	,0x2229	,0x0000	), // ' ' ➔ "∩" INTERSECTION
/*<!M><N>                                                          */ DEADTRANS( 0x00A0	,0xE4B3	,0x22C2	,0x0000	), // ' ' ➔ "⋂" N-ARY INTERSECTION
/*<!M><n>                                                          */ DEADTRANS( L' '	,0xE4B2	,0x2229	,0x0000	), // ' ' ➔ "∩" INTERSECTION
/*<!M><N>                                                          */ DEADTRANS( L' '	,0xE4B3	,0x22C2	,0x0000	), // ' ' ➔ "⋂" N-ARY INTERSECTION
/*<!M><o>                                                          */ DEADTRANS( L'*'	,0xE4BF	,0x229B	,0x0000	), // '*' ➔ "⊛" CIRCLED ASTERISK OPERATOR
/*<!M><O>                                                          */ DEADTRANS( L'*'	,0xE4C0	,0x229B	,0x0000	), // '*' ➔ "⊛" CIRCLED ASTERISK OPERATOR
/*<!M><o><%backslash>                                              */ DEADTRANS( L'c'	,0xE4C1	,0xDD6E	,0x0000	), // High surrogate: D83C; U+1F16E 'c' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><o><%backslash>                                              */ DEADTRANS( L'C'	,0xE4C1	,0xDD6E	,0x0000	), // High surrogate: D83C; U+1F16E 'C' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash>                                              */ DEADTRANS( L'C'	,0xE4C2	,0xDD6E	,0x0000	), // High surrogate: D83C; U+1F16E 'C' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash>                                              */ DEADTRANS( L'c'	,0xE4C2	,0xDD6E	,0x0000	), // High surrogate: D83C; U+1F16E 'c' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash>                                              */ DEADTRANS( 0x00A0	,0xE4C2	,0x29B8	,0x0000	), // ' ' ➔ "⦸" CIRCLED REVERSE SOLIDUS
/*<!M><o><%backslash>                                              */ DEADTRANS( 0x00A0	,0xE4C1	,0x29F5	,0x0000	), // ' ' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><O><%backslash>                                              */ DEADTRANS( L' '	,0xE4C2	,0x29B8	,0x0000	), // ' ' ➔ "⦸" CIRCLED REVERSE SOLIDUS
/*<!M><o><%backslash>                                              */ DEADTRANS( L' '	,0xE4C1	,0x29F5	,0x0000	), // ' ' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><O><%bar>                                                    */ DEADTRANS( L'|'	,0xE4C3	,0x29B7	,0x0000	), // '|' ➔ "⦷" CIRCLED PARALLEL
/*<!M><O><%bar>                                                    */ DEADTRANS( L'#'	,0xE4C3	,0x25D1	,0x0000	), // '#' ➔ "◑" CIRCLE WITH RIGHT HALF BLACK
/*<!M><o><%bar>                                                    */ DEADTRANS( L'_'	,0xE4C4	,0x27DF	,0x0000	), // '_' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><O><%bar>                                                    */ DEADTRANS( L'_'	,0xE4C3	,0x29B9	,0x0000	), // '_' ➔ "⦹" CIRCLED PERPENDICULAR
/*<!M><O><%bar>                                                    */ DEADTRANS( 0x00A0	,0xE4C3	,0x29B6	,0x0000	), // ' ' ➔ "⦶" CIRCLED VERTICAL BAR
/*<!M><o><%bar>                                                    */ DEADTRANS( 0x00A0	,0xE4C4	,0x2AEF	,0x0000	), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><O><%bar>                                                    */ DEADTRANS( L' '	,0xE4C3	,0x29B6	,0x0000	), // ' ' ➔ "⦶" CIRCLED VERTICAL BAR
/*<!M><o><%bar>                                                    */ DEADTRANS( L' '	,0xE4C4	,0x2AEF	,0x0000	), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o>                                                          */ DEADTRANS( L'^'	,0xE4BF	,0x2A22	,0x0000	), // '^' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><O><%colon>                                                  */ DEADTRANS( L'-'	,0xE4C5	,0x2A38	,0x0000	), // '-' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%colon>                                                  */ DEADTRANS( L'-'	,0xE4C6	,0x2A38	,0x0000	), // '-' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><O><%colon>                                                  */ DEADTRANS( L'/'	,0xE4C5	,0x29BC	,0x0000	), // '/' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><o><%colon>                                                  */ DEADTRANS( L'/'	,0xE4C6	,0x29BC	,0x0000	), // '/' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><o><%colon>                                                  */ DEADTRANS( 0x00A0	,0xE4C6	,0x2982	,0x0000	), // ' ' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><o><%colon>                                                  */ DEADTRANS( L' '	,0xE4C6	,0x2982	,0x0000	), // ' ' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><o>                                                          */ DEADTRANS( L'='	,0xE4BF	,0x2257	,0x0000	), // '=' ➔ "≗" RING EQUAL TO
/*<!M><O>                                                          */ DEADTRANS( L'='	,0xE4C0	,0x29C3	,0x0000	), // '=' ➔ "⧃" CIRCLE WITH TWO HORIZONTAL STROKES TO THE RIGHT
/*<!M><O>                                                          */ DEADTRANS( L'!'	,0xE4C0	,0x29EC	,0x0000	), // '!' ➔ "⧬" WHITE CIRCLE WITH DOWN ARROW
/*<!M><o>                                                          */ DEADTRANS( L'>'	,0xE4BF	,0x2941	,0x0000	), // '>' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><O>                                                          */ DEADTRANS( L'>'	,0xE4C0	,0x29C1	,0x0000	), // '>' ➔ "⧁" CIRCLED GREATER-THAN
/*<!M><O><%hash>                                                   */ DEADTRANS( L'|'	,0xE4C7	,0x25D0	,0x0000	), // '|' ➔ "◐" CIRCLE WITH LEFT HALF BLACK
/*<!M><O><%hash>                                                   */ DEADTRANS( L'!'	,0xE4C7	,0x29ED	,0x0000	), // '!' ➔ "⧭" BLACK CIRCLE WITH DOWN ARROW
/*<!M><O><%hash>                                                   */ DEADTRANS( L'-'	,0xE4C7	,0x25D3	,0x0000	), // '-' ➔ "◓" CIRCLE WITH UPPER HALF BLACK
/*<!M><o><%hash>                                                   */ DEADTRANS( L'e'	,0xE4C8	,0xAB62	,0x0000	), // 'e' ➔ "ꭢ" LATIN SMALL LETTER OPEN OE
/*<!M><O><%hash>                                                   */ DEADTRANS( 0x00A0	,0xE4C7	,0x25CF	,0x0000	), // ' ' ➔ "●" BLACK CIRCLE
/*<!M><O><%hash>                                                   */ DEADTRANS( L' '	,0xE4C7	,0x25CF	,0x0000	), // ' ' ➔ "●" BLACK CIRCLE
/*<!M><o>                                                          */ DEADTRANS( L'<'	,0xE4BF	,0x2940	,0x0000	), // '<' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><O><%less>                                                   */ DEADTRANS( L'!'	,0xE4C9	,0x29BD	,0x0000	), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><O><%less>                                                   */ DEADTRANS( 0x00A0	,0xE4C9	,0x29C0	,0x0000	), // ' ' ➔ "⧀" CIRCLED LESS-THAN
/*<!M><O><%less>                                                   */ DEADTRANS( L' '	,0xE4C9	,0x29C0	,0x0000	), // ' ' ➔ "⧀" CIRCLED LESS-THAN
/*<!M><O><%minus>                                                  */ DEADTRANS( L'|'	,0xE4CA	,0x29BA	,0x0000	), // '|' ➔ "⦺" CIRCLE DIVIDED BY HORIZONTAL BAR AND TOP HALF DIVIDED BY VERTICAL BAR
/*<!M><O><%minus>                                                  */ DEADTRANS( L':'	,0xE4CA	,0x2A38	,0x0000	), // ':' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%minus>                                                  */ DEADTRANS( L':'	,0xE4CB	,0x2A38	,0x0000	), // ':' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%minus>                                                  */ DEADTRANS( L'>'	,0xE4CB	,0x21AC	,0x0000	), // '>' ➔ "↬" RIGHTWARDS ARROW WITH LOOP
/*<!M><O><%minus>                                                  */ DEADTRANS( L'#'	,0xE4CA	,0x25D2	,0x0000	), // '#' ➔ "◒" CIRCLE WITH LOWER HALF BLACK
/*<!M><o><%minus>                                                  */ DEADTRANS( L'-'	,0xE4CB	,0x229D	,0x0000	), // '-' ➔ "⊝" CIRCLED DASH
/*<!M><o><%minus>                                                  */ DEADTRANS( L'.'	,0xE4CB	,0x22B6	,0x0000	), // '.' ➔ "⊶" ORIGINAL OF
/*<!M><o><%minus>                                                  */ DEADTRANS( L'o'	,0xE4CB	,0x29DF	,0x0000	), // 'o' ➔ "⧟" DOUBLE-ENDED MULTIMAP
/*<!M><o><%minus>                                                  */ DEADTRANS( 0x00A0	,0xE4CB	,0x2296	,0x0000	), // ' ' ➔ "⊖" CIRCLED MINUS
/*<!M><O><%minus>                                                  */ DEADTRANS( 0x00A0	,0xE4CA	,0x29B5	,0x0000	), // ' ' ➔ "⦵" CIRCLE WITH HORIZONTAL BAR
/*<!M><o><%minus>                                                  */ DEADTRANS( L' '	,0xE4CB	,0x2296	,0x0000	), // ' ' ➔ "⊖" CIRCLED MINUS
/*<!M><O><%minus>                                                  */ DEADTRANS( L' '	,0xE4CA	,0x29B5	,0x0000	), // ' ' ➔ "⦵" CIRCLE WITH HORIZONTAL BAR
/*<!M><o>                                                          */ DEADTRANS( L')'	,0xE4BF	,0x29DC	,0x0000	), // ')' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><o>                                                          */ DEADTRANS( L'%'	,0xE4BF	,0x2127	,0x0000	), // '%' ➔ "℧" INVERTED OHM SIGN
/*<!M><O><%percent>                                                */ DEADTRANS( L'C'	,0xE4CC	,0xDD2F	,0x0000	), // High surrogate: D83C; U+1F12F 'C' ➔ "🄯" COPYLEFT SYMBOL
/*<!M><O><%percent>                                                */ DEADTRANS( 0x00A0	,0xE4CC	,0x2127	,0x0000	), // ' ' ➔ "℧" INVERTED OHM SIGN
/*<!M><O><%percent>                                                */ DEADTRANS( L' '	,0xE4CC	,0x2127	,0x0000	), // ' ' ➔ "℧" INVERTED OHM SIGN
/*<!M><o>                                                          */ DEADTRANS( L'.'	,0xE4BF	,0x2299	,0x0000	), // '.' ➔ "⊙" CIRCLED DOT OPERATOR
/*<!M><O>                                                          */ DEADTRANS( L'.'	,0xE4C0	,0x2A00	,0x0000	), // '.' ➔ "⨀" N-ARY CIRCLED DOT OPERATOR
/*<!M><o><%plus>                                                   */ DEADTRANS( L'-'	,0xE4CD	,0x27F4	,0x0000	), // '-' ➔ "⟴" RIGHT ARROW WITH CIRCLED PLUS
/*<!M><O><%plus>                                                   */ DEADTRANS( L'-'	,0xE4CE	,0x27F4	,0x0000	), // '-' ➔ "⟴" RIGHT ARROW WITH CIRCLED PLUS
/*<!M><o><%plus>                                                   */ DEADTRANS( 0x00A0	,0xE4CD	,0x2295	,0x0000	), // ' ' ➔ "⊕" CIRCLED PLUS
/*<!M><O><%plus>                                                   */ DEADTRANS( 0x00A0	,0xE4CE	,0x2A01	,0x0000	), // ' ' ➔ "⨁" N-ARY CIRCLED PLUS OPERATOR
/*<!M><o><%plus>                                                   */ DEADTRANS( L' '	,0xE4CD	,0x2295	,0x0000	), // ' ' ➔ "⊕" CIRCLED PLUS
/*<!M><O><%plus>                                                   */ DEADTRANS( L' '	,0xE4CE	,0x2A01	,0x0000	), // ' ' ➔ "⨁" N-ARY CIRCLED PLUS OPERATOR
/*<!M><o>                                                          */ DEADTRANS( L';'	,0xE4BF	,0x2A1F	,0x0000	), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><o>                                                          */ DEADTRANS( 0x00A7	,0xE4BF	,0x2A1F	,0x0000	), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><O>                                                          */ DEADTRANS( L'/'	,0xE4C0	,0x2205	,0x0000	), // '/' ➔ "∅" EMPTY SET
/*<!M><o><%slash>                                                  */ DEADTRANS( L'>'	,0xE4CF	,0x2642	,0x0000	), // '>' ➔ "♂" MALE SIGN
/*<!M><o><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE4CF	,0x2300	,0x0000	), // ' ' ➔ "⌀" DIAMETER SIGN
/*<!M><o><%slash>                                                  */ DEADTRANS( L' '	,0xE4CF	,0x2300	,0x0000	), // ' ' ➔ "⌀" DIAMETER SIGN
/*<!M><o>                                                          */ DEADTRANS( L'~'	,0xE4BF	,0x2134	,0x0000	), // '~' ➔ "ℴ" SCRIPT SMALL O
/*<!M><o>                                                          */ DEADTRANS( L'_'	,0xE4BF	,0x00BA	,0x0000	), // '_' ➔ "º" MASCULINE ORDINAL INDICATOR
/*<!M><O>                                                          */ DEADTRANS( L'_'	,0xE4C0	,0x00BA	,0x0000	), // '_' ➔ "º" MASCULINE ORDINAL INDICATOR
/*<!M><o>                                                          */ DEADTRANS( L'0'	,0xE4BF	,0x2469	,0x0000	), // '0' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><O>                                                          */ DEADTRANS( L'0'	,0xE4C0	,0x2469	,0x0000	), // '0' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><o>                                                          */ DEADTRANS( L'1'	,0xE4BF	,0x2460	,0x0000	), // '1' ➔ "①" CIRCLED DIGIT ONE
/*<!M><O>                                                          */ DEADTRANS( L'1'	,0xE4C0	,0x2460	,0x0000	), // '1' ➔ "①" CIRCLED DIGIT ONE
/*<!M><o>                                                          */ DEADTRANS( L'2'	,0xE4BF	,0x2461	,0x0000	), // '2' ➔ "②" CIRCLED DIGIT TWO
/*<!M><O>                                                          */ DEADTRANS( L'2'	,0xE4C0	,0x2461	,0x0000	), // '2' ➔ "②" CIRCLED DIGIT TWO
/*<!M><o>                                                          */ DEADTRANS( L'3'	,0xE4BF	,0x2462	,0x0000	), // '3' ➔ "③" CIRCLED DIGIT THREE
/*<!M><O>                                                          */ DEADTRANS( L'3'	,0xE4C0	,0x2462	,0x0000	), // '3' ➔ "③" CIRCLED DIGIT THREE
/*<!M><o>                                                          */ DEADTRANS( L'4'	,0xE4BF	,0x2463	,0x0000	), // '4' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><O>                                                          */ DEADTRANS( L'4'	,0xE4C0	,0x2463	,0x0000	), // '4' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><o>                                                          */ DEADTRANS( L'5'	,0xE4BF	,0x2464	,0x0000	), // '5' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><O>                                                          */ DEADTRANS( L'5'	,0xE4C0	,0x2464	,0x0000	), // '5' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><o>                                                          */ DEADTRANS( L'6'	,0xE4BF	,0x2465	,0x0000	), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><O>                                                          */ DEADTRANS( L'6'	,0xE4C0	,0x2465	,0x0000	), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><o>                                                          */ DEADTRANS( L'7'	,0xE4BF	,0x2466	,0x0000	), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><O>                                                          */ DEADTRANS( L'7'	,0xE4C0	,0x2466	,0x0000	), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><o>                                                          */ DEADTRANS( L'8'	,0xE4BF	,0x2467	,0x0000	), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><O>                                                          */ DEADTRANS( L'8'	,0xE4C0	,0x2467	,0x0000	), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><o>                                                          */ DEADTRANS( L'9'	,0xE4BF	,0x2468	,0x0000	), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><O>                                                          */ DEADTRANS( L'9'	,0xE4C0	,0x2468	,0x0000	), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><o>                                                          */ DEADTRANS( L'A'	,0xE4BF	,0x212B	,0x0000	), // 'A' ➔ "Å" ANGSTROM SIGN
/*<!M><o>                                                          */ DEADTRANS( L'a'	,0xE4BF	,0x212B	,0x0000	), // 'a' ➔ "Å" ANGSTROM SIGN
/*<!M><O>                                                          */ DEADTRANS( L'A'	,0xE4C0	,0x212B	,0x0000	), // 'A' ➔ "Å" ANGSTROM SIGN
/*<!M><O>                                                          */ DEADTRANS( L'a'	,0xE4C0	,0x212B	,0x0000	), // 'a' ➔ "Å" ANGSTROM SIGN
/*<!M><o>                                                          */ DEADTRANS( L'b'	,0xE4BF	,0xDD6F	,0x0000	), // High surrogate: D83C; U+1F16F 'b' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><O>                                                          */ DEADTRANS( L'b'	,0xE4C0	,0xDD6F	,0x0000	), // High surrogate: D83C; U+1F16F 'b' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><O>                                                          */ DEADTRANS( L'B'	,0xE4C0	,0xDD6F	,0x0000	), // High surrogate: D83C; U+1F16F 'B' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><o>                                                          */ DEADTRANS( L'c'	,0xE4BF	,0x00A9	,0x0000	), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><O>                                                          */ DEADTRANS( L'c'	,0xE4C0	,0x00A9	,0x0000	), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><o>                                                          */ DEADTRANS( L'C'	,0xE4BF	,0xDD6D	,0x0000	), // High surrogate: D83C; U+1F16D 'C' ➔ "🅭" CIRCLED CC
/*<!M><O>                                                          */ DEADTRANS( L'C'	,0xE4C0	,0xDD6D	,0x0000	), // High surrogate: D83C; U+1F16D 'C' ➔ "🅭" CIRCLED CC
/*<!M><O>                                                          */ DEADTRANS( L'E'	,0xE4C0	,0x0152	,0x0000	), // 'E' ➔ "Œ" LATIN CAPITAL LIGATURE OE
/*<!M><O>                                                          */ DEADTRANS( L'e'	,0xE4C0	,0x0152	,0x0000	), // 'e' ➔ "Œ" LATIN CAPITAL LIGATURE OE
/*<!M><o>                                                          */ DEADTRANS( L'e'	,0xE4BF	,0x0153	,0x0000	), // 'e' ➔ "œ" LATIN SMALL LIGATURE OE
/*<!M><o>                                                          */ DEADTRANS( L'h'	,0xE4BF	,0x2126	,0x0000	), // 'h' ➔ "Ω" OHM SIGN
/*<!M><O>                                                          */ DEADTRANS( L'h'	,0xE4C0	,0x2126	,0x0000	), // 'h' ➔ "Ω" OHM SIGN
/*<!M><O>                                                          */ DEADTRANS( L'H'	,0xE4C0	,0x2126	,0x0000	), // 'H' ➔ "Ω" OHM SIGN
/*<!M><O>                                                          */ DEADTRANS( L'I'	,0xE4C0	,0x23FB	,0x0000	), // 'I' ➔ "⏻" POWER SYMBOL
/*<!M><o>                                                          */ DEADTRANS( L'I'	,0xE4BF	,0x2AEF	,0x0000	), // 'I' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><i><n>                                                    */ DEADTRANS( L'f'	,0xE4D0	,0x1D17	,0x0000	), // 'f' ➔ "ᴗ" LATIN SMALL LETTER BOTTOM HALF O
/*<!M><o><i>                                                       */ DEADTRANS( 0x00A0	,0xE4D1	,0x2AEF	,0x0000	), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><i>                                                       */ DEADTRANS( L' '	,0xE4D1	,0x2AEF	,0x0000	), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o>                                                          */ DEADTRANS( L'O'	,0xE4BF	,0x29B2	,0x0000	), // 'O' ➔ "⦲" EMPTY SET WITH SMALL CIRCLE ABOVE
/*<!M><O>                                                          */ DEADTRANS( L'O'	,0xE4C0	,0xA74E	,0x0000	), // 'O' ➔ "Ꝏ" LATIN CAPITAL LETTER OO
/*<!M><o>                                                          */ DEADTRANS( L'o'	,0xE4BF	,0xA74F	,0x0000	), // 'o' ➔ "ꝏ" LATIN SMALL LETTER OO
/*<!M><O><o>                                                       */ DEADTRANS( L'x'	,0xE4D2	,0x2A37	,0x0000	), // 'x' ➔ "⨷" MULTIPLICATION SIGN IN DOUBLE CIRCLE
/*<!M><O><o>                                                       */ DEADTRANS( 0x00A0	,0xE4D2	,0x229A	,0x0000	), // ' ' ➔ "⊚" CIRCLED RING OPERATOR
/*<!M><O><o>                                                       */ DEADTRANS( L' '	,0xE4D2	,0x229A	,0x0000	), // ' ' ➔ "⊚" CIRCLED RING OPERATOR
/*<!M><o>                                                          */ DEADTRANS( L'P'	,0xE4BF	,0x2117	,0x0000	), // 'P' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><O>                                                          */ DEADTRANS( L'p'	,0xE4C0	,0x2117	,0x0000	), // 'p' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><o><p>                                                       */ DEADTRANS( L'h'	,0xE4D3	,0x26CE	,0x0000	), // 'h' ➔ "⛎" OPHIUCHUS emoji
/*<!M><O><P>                                                       */ DEADTRANS( L'H'	,0xE4D4	,0x26CE	,0x0000	), // 'H' ➔ "⛎" OPHIUCHUS emoji
/*<!M><o><p>                                                       */ DEADTRANS( L't'	,0xE4D3	,0x2325	,0x0000	), // 't' ➔ "⌥" OPTION KEY
/*<!M><O><P>                                                       */ DEADTRANS( L'T'	,0xE4D4	,0x2325	,0x0000	), // 'T' ➔ "⌥" OPTION KEY
/*<!M><o>                                                          */ DEADTRANS( L'R'	,0xE4BF	,0x00AE	,0x0000	), // 'R' ➔ "®" REGISTERED SIGN emoji
/*<!M><O>                                                          */ DEADTRANS( L'r'	,0xE4C0	,0x00AE	,0x0000	), // 'r' ➔ "®" REGISTERED SIGN emoji
/*<!M><o>                                                          */ DEADTRANS( L'r'	,0xE4BF	,0x2228	,0x0000	), // 'r' ➔ "∨" LOGICAL OR
/*<!M><O>                                                          */ DEADTRANS( L'R'	,0xE4C0	,0x2228	,0x0000	), // 'R' ➔ "∨" LOGICAL OR
/*<!M><O>                                                          */ DEADTRANS( L'S'	,0xE4C0	,0x2606	,0x0000	), // 'S' ➔ "☆" WHITE STAR
/*<!M><o>                                                          */ DEADTRANS( L'S'	,0xE4BF	,0x2A0A	,0x0000	), // 'S' ➔ "⨊" MODULO TWO SUM
/*<!M><o><s>                                                       */ DEADTRANS( L't'	,0xE4D5	,0x2606	,0x0000	), // 't' ➔ "☆" WHITE STAR
/*<!M><o><s><u>                                                    */ DEADTRANS( L'p'	,0xE4D6	,0x1D16	,0x0000	), // 'p' ➔ "ᴖ" LATIN SMALL LETTER TOP HALF O
/*<!M><o><T>                                                       */ DEADTRANS( L'%'	,0xE4D7	,0x27DF	,0x0000	), // '%' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><o><t>                                                       */ DEADTRANS( L'd'	,0xE4D8	,0x25BF	,0x0000	), // 'd' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><O><T>                                                       */ DEADTRANS( L'D'	,0xE4D9	,0x25BF	,0x0000	), // 'D' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><o><t>                                                       */ DEADTRANS( L'h'	,0xE4D8	,0x2679	,0x0000	), // 'h' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><O><T>                                                       */ DEADTRANS( L'H'	,0xE4D9	,0x2679	,0x0000	), // 'H' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><o><t>                                                       */ DEADTRANS( L'r'	,0xE4D8	,0x2679	,0x0000	), // 'r' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><O><T>                                                       */ DEADTRANS( L'R'	,0xE4D9	,0x2679	,0x0000	), // 'R' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><o><T>                                                       */ DEADTRANS( L'T'	,0xE4D7	,0x27DF	,0x0000	), // 'T' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><o><t>                                                       */ DEADTRANS( L'u'	,0xE4D8	,0x25B5	,0x0000	), // 'u' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><O><T>                                                       */ DEADTRANS( L'U'	,0xE4D9	,0x25B5	,0x0000	), // 'U' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><O>                                                          */ DEADTRANS( L'U'	,0xE4C0	,0x0222	,0x0000	), // 'U' ➔ "Ȣ" LATIN CAPITAL LETTER OU
/*<!M><O>                                                          */ DEADTRANS( L'u'	,0xE4C0	,0x0222	,0x0000	), // 'u' ➔ "Ȣ" LATIN CAPITAL LETTER OU
/*<!M><o>                                                          */ DEADTRANS( L'u'	,0xE4BF	,0x0223	,0x0000	), // 'u' ➔ "ȣ" LATIN SMALL LETTER OU
/*<!M><o>                                                          */ DEADTRANS( L'x'	,0xE4BF	,0x2297	,0x0000	), // 'x' ➔ "⊗" CIRCLED TIMES
/*<!M><O>                                                          */ DEADTRANS( L'X'	,0xE4C0	,0x29BB	,0x0000	), // 'X' ➔ "⦻" CIRCLE WITH SUPERIMPOSED X
/*<!M><O>                                                          */ DEADTRANS( L'x'	,0xE4C0	,0x2A02	,0x0000	), // 'x' ➔ "⨂" N-ARY CIRCLED TIMES OPERATOR
/*<!M><o>                                                          */ DEADTRANS( 0x00A0	,0xE4BF	,0x2218	,0x0000	), // ' ' ➔ "∘" RING OPERATOR
/*<!M><O>                                                          */ DEADTRANS( 0x00A0	,0xE4C0	,0x25CB	,0x0000	), // ' ' ➔ "○" WHITE CIRCLE
/*<!M><o>                                                          */ DEADTRANS( L' '	,0xE4BF	,0x2218	,0x0000	), // ' ' ➔ "∘" RING OPERATOR
/*<!M><O>                                                          */ DEADTRANS( L' '	,0xE4C0	,0x25CB	,0x0000	), // ' ' ➔ "○" WHITE CIRCLE
/*<!M><p><%bar>                                                    */ DEADTRANS( L','	,0xE4DA	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p><%bar>                                                    */ DEADTRANS( 0x00A0	,0xE4DA	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p><%bar>                                                    */ DEADTRANS( L' '	,0xE4DA	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p>                                                          */ DEADTRANS( L','	,0xE4DB	,0x220D	,0x0000	), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><p>                                                          */ DEADTRANS( L'='	,0xE4DB	,0x20B1	,0x0000	), // '=' ➔ "₱" PESO SIGN
/*<!M><P>                                                          */ DEADTRANS( L'='	,0xE4DC	,0x20B1	,0x0000	), // '=' ➔ "₱" PESO SIGN
/*<!M><p>                                                          */ DEADTRANS( L'!'	,0xE4DB	,0x00B6	,0x0000	), // '!' ➔ "¶" PILCROW SIGN
/*<!M><P>                                                          */ DEADTRANS( L'!'	,0xE4DC	,0x00B6	,0x0000	), // '!' ➔ "¶" PILCROW SIGN
/*<!M><p>                                                          */ DEADTRANS( L'>'	,0xE4DB	,0x202C	,0x0000	), // '>' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><p>                                                          */ DEADTRANS( L'<'	,0xE4DB	,0x202C	,0x0000	), // '<' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><P>                                                          */ DEADTRANS( L'-'	,0xE4DC	,0x20B1	,0x0000	), // '-' ➔ "₱" PESO SIGN
/*<!M><p>                                                          */ DEADTRANS( L'-'	,0xE4DB	,0x22FA	,0x0000	), // '-' ➔ "⋺" CONTAINS WITH LONG HORIZONTAL STROKE
/*<!M><P>                                                          */ DEADTRANS( L'%'	,0xE4DC	,0x2210	,0x0000	), // '%' ➔ "∐" N-ARY COPRODUCT
/*<!M><p>                                                          */ DEADTRANS( L'%'	,0xE4DB	,0x2A3F	,0x0000	), // '%' ➔ "⨿" AMALGAMATION OR COPRODUCT
/*<!M><p>                                                          */ DEADTRANS( L'/'	,0xE4DB	,0x220C	,0x0000	), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><P>                                                          */ DEADTRANS( L'~'	,0xE4DC	,0x2118	,0x0000	), // '~' ➔ "℘" SCRIPT CAPITAL P
/*<!M><p><a><c>                                                    */ DEADTRANS( L'a'	,0xE4DD	,0x25AB	,0x0000	), // 'a' ➔ "▫" WHITE SMALL SQUARE
/*<!M><P><A><C>                                                    */ DEADTRANS( L'A'	,0xE4DE	,0x25AB	,0x0000	), // 'A' ➔ "▫" WHITE SMALL SQUARE
/*<!M><p><a><c>                                                    */ DEADTRANS( L'd'	,0xE4DD	,0x25E6	,0x0000	), // 'd' ➔ "◦" WHITE BULLET
/*<!M><P><A><C>                                                    */ DEADTRANS( L'D'	,0xE4DE	,0x25E6	,0x0000	), // 'D' ➔ "◦" WHITE BULLET
/*<!M><p><a><r>                                                    */ DEADTRANS( L'c'	,0xE4DF	,0x25AD	,0x0000	), // 'c' ➔ "▭" WHITE RECTANGLE
/*<!M><P><A><R>                                                    */ DEADTRANS( L'C'	,0xE4E0	,0x25AD	,0x0000	), // 'C' ➔ "▭" WHITE RECTANGLE
/*<!M><p><a><r>                                                    */ DEADTRANS( L'o'	,0xE4DF	,0x25E6	,0x0000	), // 'o' ➔ "◦" WHITE BULLET
/*<!M><P><A><R>                                                    */ DEADTRANS( L'O'	,0xE4E0	,0x25E6	,0x0000	), // 'O' ➔ "◦" WHITE BULLET
/*<!M><p><a><t>                                                    */ DEADTRANS( L'b'	,0xE4E1	,0x25BF	,0x0000	), // 'b' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><P><A><T>                                                    */ DEADTRANS( L'B'	,0xE4E2	,0x25BF	,0x0000	), // 'B' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><p><a><t>                                                    */ DEADTRANS( L'h'	,0xE4E1	,0x25B5	,0x0000	), // 'h' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><P><A><T>                                                    */ DEADTRANS( L'H'	,0xE4E2	,0x25B5	,0x0000	), // 'H' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><p><d>                                                       */ DEADTRANS( L'i'	,0xE4E3	,0x2069	,0x0000	), // 'i' ➔ "⁩" POP DIRECTIONAL ISOLATE
/*<!M><p><e><h>                                                    */ DEADTRANS( L'd'	,0xE4E4	,0x2674	,0x0000	), // 'd' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><P><E><H>                                                    */ DEADTRANS( L'D'	,0xE4E5	,0x2674	,0x0000	), // 'D' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><p><e><l>                                                    */ DEADTRANS( L'd'	,0xE4E6	,0x2676	,0x0000	), // 'd' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><P><E><L>                                                    */ DEADTRANS( L'D'	,0xE4E7	,0x2676	,0x0000	), // 'D' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><p><e>                                                       */ DEADTRANS( L'r'	,0xE4E8	,0x214C	,0x0000	), // 'r' ➔ "⅌" PER SIGN
/*<!M><P><e>                                                       */ DEADTRANS( L'r'	,0xE4E9	,0x214C	,0x0000	), // 'r' ➔ "⅌" PER SIGN
/*<!M><P><E>                                                       */ DEADTRANS( L'R'	,0xE4EA	,0x214C	,0x0000	), // 'R' ➔ "⅌" PER SIGN
/*<!M><p><e>                                                       */ DEADTRANS( L't'	,0xE4E8	,0x2673	,0x0000	), // 't' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P><E>                                                       */ DEADTRANS( L'T'	,0xE4EA	,0x2673	,0x0000	), // 'T' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P>                                                          */ DEADTRANS( L'f'	,0xE4DC	,0x20B0	,0x0000	), // 'f' ➔ "₰" GERMAN PENNY SIGN
/*<!M><p><h>                                                       */ DEADTRANS( L'p'	,0xE4EB	,0x20B1	,0x0000	), // 'p' ➔ "₱" PESO SIGN, Philippine Peso THE PHILIPPINES
/*<!M><P><H>                                                       */ DEADTRANS( L'P'	,0xE4EC	,0x20B1	,0x0000	), // 'P' ➔ "₱" PESO SIGN, Philippine Peso THE PHILIPPINES
/*<!M><p><i><s>                                                    */ DEADTRANS( L'c'	,0xE4ED	,0x2653	,0x0000	), // 'c' ➔ "♓" PISCES emoji
/*<!M><P><I><S>                                                    */ DEADTRANS( L'C'	,0xE4EE	,0x2653	,0x0000	), // 'C' ➔ "♓" PISCES emoji
/*<!M><p><i>                                                       */ DEADTRANS( 0x00A0	,0xE4EF	,0x03C0	,0x0000	), // ' ' ➔ "π" GREEK SMALL LETTER PI
/*<!M><p><i>                                                       */ DEADTRANS( L' '	,0xE4EF	,0x03C0	,0x0000	), // ' ' ➔ "π" GREEK SMALL LETTER PI
/*<!M><P><L>                                                       */ DEADTRANS( L'A'	,0xE4F0	,0x210E	,0x0000	), // 'A' ➔ "ℎ" PLANCK CONSTANT
/*<!M><P><l>                                                       */ DEADTRANS( L'a'	,0xE4F1	,0x210E	,0x0000	), // 'a' ➔ "ℎ" PLANCK CONSTANT
/*<!M><p><l>                                                       */ DEADTRANS( L'a'	,0xE4F2	,0x210E	,0x0000	), // 'a' ➔ "ℎ" PLANCK CONSTANT
/*<!M><P>                                                          */ DEADTRANS( L'o'	,0xE4DC	,0x2117	,0x0000	), // 'o' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><p>                                                          */ DEADTRANS( L'O'	,0xE4DB	,0x2117	,0x0000	), // 'O' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><p><o><i>                                                    */ DEADTRANS( L's'	,0xE4F3	,0x2653	,0x0000	), // 's' ➔ "♓" PISCES emoji
/*<!M><P><O><I>                                                    */ DEADTRANS( L'S'	,0xE4F4	,0x2653	,0x0000	), // 'S' ➔ "♓" PISCES emoji
/*<!M><p><p>                                                       */ DEADTRANS( L'@'	,0xE4F5	,0x213C	,0x0000	), // '@' ➔ "ℼ" DOUBLE-STRUCK SMALL PI
/*<!M><P><P>                                                       */ DEADTRANS( L'@'	,0xE4F6	,0x213F	,0x0000	), // '@' ➔ "ℿ" DOUBLE-STRUCK CAPITAL PI
/*<!M><p><p><c>                                                    */ DEADTRANS( L'a'	,0xE4F7	,0x25AA	,0x0000	), // 'a' ➔ "▪" BLACK SMALL SQUARE
/*<!M><P><P><C>                                                    */ DEADTRANS( L'A'	,0xE4F8	,0x25AA	,0x0000	), // 'A' ➔ "▪" BLACK SMALL SQUARE
/*<!M><p><p><c>                                                    */ DEADTRANS( L'c'	,0xE4F7	,0x25CF	,0x0000	), // 'c' ➔ "●" BLACK CIRCLE
/*<!M><P><P><C>                                                    */ DEADTRANS( L'C'	,0xE4F8	,0x25CF	,0x0000	), // 'C' ➔ "●" BLACK CIRCLE
/*<!M><p><p><c>                                                    */ DEADTRANS( L'd'	,0xE4F7	,0x2022	,0x0000	), // 'd' ➔ "•" BULLET
/*<!M><P><P><C>                                                    */ DEADTRANS( L'D'	,0xE4F8	,0x2022	,0x0000	), // 'D' ➔ "•" BULLET
/*<!M><p><p><m>                                                    */ DEADTRANS( L'd'	,0xE4F9	,0x204D	,0x0000	), // 'd' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><P><P><M>                                                    */ DEADTRANS( L'D'	,0xE4FA	,0x204D	,0x0000	), // 'D' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><p><p><m>                                                    */ DEADTRANS( L'g'	,0xE4F9	,0x204C	,0x0000	), // 'g' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><P><P><M>                                                    */ DEADTRANS( L'G'	,0xE4FA	,0x204C	,0x0000	), // 'G' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><p><p>                                                       */ DEADTRANS( L'p'	,0xE4F5	,0x2677	,0x0000	), // 'p' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><P><P>                                                       */ DEADTRANS( L'P'	,0xE4F6	,0x2677	,0x0000	), // 'P' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><p><p><r>                                                    */ DEADTRANS( L'c'	,0xE4FB	,0x25AC	,0x0000	), // 'c' ➔ "▬" BLACK RECTANGLE
/*<!M><P><P><R>                                                    */ DEADTRANS( L'C'	,0xE4FC	,0x25AC	,0x0000	), // 'C' ➔ "▬" BLACK RECTANGLE
/*<!M><p><p><r>                                                    */ DEADTRANS( L'd'	,0xE4FB	,0x25AE	,0x0000	), // 'd' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><P><P><R>                                                    */ DEADTRANS( L'D'	,0xE4FC	,0x25AE	,0x0000	), // 'D' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><p><p><r>                                                    */ DEADTRANS( L'e'	,0xE4FB	,0x220E	,0x0000	), // 'e' ➔ "∎" END OF PROOF
/*<!M><P><P><R>                                                    */ DEADTRANS( L'E'	,0xE4FC	,0x220E	,0x0000	), // 'E' ➔ "∎" END OF PROOF
/*<!M><p><p><r>                                                    */ DEADTRANS( L'o'	,0xE4FB	,0x2022	,0x0000	), // 'o' ➔ "•" BULLET
/*<!M><P><P><R>                                                    */ DEADTRANS( L'O'	,0xE4FC	,0x2022	,0x0000	), // 'O' ➔ "•" BULLET
/*<!M><p><p><t>                                                    */ DEADTRANS( L'b'	,0xE4FD	,0x25BE	,0x0000	), // 'b' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><P><P><T>                                                    */ DEADTRANS( L'B'	,0xE4FE	,0x25BE	,0x0000	), // 'B' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><p><p><t>                                                    */ DEADTRANS( L'd'	,0xE4FD	,0x2023	,0x0000	), // 'd' ➔ "‣" TRIANGULAR BULLET
/*<!M><P><P><T>                                                    */ DEADTRANS( L'D'	,0xE4FE	,0x2023	,0x0000	), // 'D' ➔ "‣" TRIANGULAR BULLET
/*<!M><p><p><t>                                                    */ DEADTRANS( L'g'	,0xE4FD	,0x25C2	,0x0000	), // 'g' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><P><P><T>                                                    */ DEADTRANS( L'G'	,0xE4FE	,0x25C2	,0x0000	), // 'G' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><p><p><t>                                                    */ DEADTRANS( L'h'	,0xE4FD	,0x25B4	,0x0000	), // 'h' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><P><P><T>                                                    */ DEADTRANS( L'H'	,0xE4FE	,0x25B4	,0x0000	), // 'H' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><P><P>                                                       */ DEADTRANS( 0x00A0	,0xE4F6	,0x2119	,0x0000	), // ' ' ➔ "ℙ" DOUBLE-STRUCK CAPITAL P
/*<!M><P><P>                                                       */ DEADTRANS( L' '	,0xE4F6	,0x2119	,0x0000	), // ' ' ➔ "ℙ" DOUBLE-STRUCK CAPITAL P
/*<!M><p>                                                          */ DEADTRANS( L's'	,0xE4DB	,0x2678	,0x0000	), // 's' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><P>                                                          */ DEADTRANS( L'S'	,0xE4DC	,0x2678	,0x0000	), // 'S' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><P>                                                          */ DEADTRANS( L't'	,0xE4DC	,0x20A7	,0x0000	), // 't' ➔ "₧" PESETA SIGN
/*<!M><p><t>                                                       */ DEADTRANS( L'0'	,0xE4FF	,0x2672	,0x0000	), // '0' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><P><T>                                                       */ DEADTRANS( L'0'	,0xE500	,0x2672	,0x0000	), // '0' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><p><t>                                                       */ DEADTRANS( L'1'	,0xE4FF	,0x2673	,0x0000	), // '1' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'1'	,0xE500	,0x2673	,0x0000	), // '1' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'2'	,0xE4FF	,0x2674	,0x0000	), // '2' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'2'	,0xE500	,0x2674	,0x0000	), // '2' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'3'	,0xE4FF	,0x2675	,0x0000	), // '3' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'3'	,0xE500	,0x2675	,0x0000	), // '3' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'4'	,0xE4FF	,0x2676	,0x0000	), // '4' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'4'	,0xE500	,0x2676	,0x0000	), // '4' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'5'	,0xE4FF	,0x2677	,0x0000	), // '5' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'5'	,0xE500	,0x2677	,0x0000	), // '5' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'6'	,0xE4FF	,0x2678	,0x0000	), // '6' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'6'	,0xE500	,0x2678	,0x0000	), // '6' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'7'	,0xE4FF	,0x2679	,0x0000	), // '7' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><P><T>                                                       */ DEADTRANS( L'7'	,0xE500	,0x2679	,0x0000	), // '7' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L'8'	,0xE4FF	,0x267A	,0x0000	), // '8' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><P><T>                                                       */ DEADTRANS( L'8'	,0xE500	,0x267A	,0x0000	), // '8' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><p><t>                                                       */ DEADTRANS( L'9'	,0xE4FF	,0x267B	,0x0000	), // '9' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><P><T>                                                       */ DEADTRANS( L'9'	,0xE500	,0x267B	,0x0000	), // '9' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><p><v>                                                       */ DEADTRANS( L'c'	,0xE501	,0x2675	,0x0000	), // 'c' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><P><V>                                                       */ DEADTRANS( L'C'	,0xE502	,0x2675	,0x0000	), // 'C' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><p><y>                                                       */ DEADTRANS( L'g'	,0xE503	,0x20B2	,0x0000	), // 'g' ➔ "₲" GUARANI SIGN, Guarani PARAGUAY
/*<!M><P><Y>                                                       */ DEADTRANS( L'G'	,0xE504	,0x20B2	,0x0000	), // 'G' ➔ "₲" GUARANI SIGN, Guarani PARAGUAY
/*<!M><p>                                                          */ DEADTRANS( 0x00A0	,0xE4DB	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><P>                                                          */ DEADTRANS( 0x00A0	,0xE4DC	,0x220F	,0x0000	), // ' ' ➔ "∏" N-ARY PRODUCT
/*<!M><p>                                                          */ DEADTRANS( L' '	,0xE4DB	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><P>                                                          */ DEADTRANS( L' '	,0xE4DC	,0x220F	,0x0000	), // ' ' ➔ "∏" N-ARY PRODUCT
/*<!M><q>                                                          */ DEADTRANS( L'#'	,0xE505	,0x2669	,0x0000	), // '#' ➔ "♩" QUARTER NOTE
/*<!M><Q>                                                          */ DEADTRANS( L'#'	,0xE506	,0x2669	,0x0000	), // '#' ➔ "♩" QUARTER NOTE
/*<!M><Q>                                                          */ DEADTRANS( L'0'	,0xE506	,0x25CB	,0x0000	), // '0' ➔ "○" WHITE CIRCLE
/*<!M><q>                                                          */ DEADTRANS( L'0'	,0xE505	,0x25CB	,0x0000	), // '0' ➔ "○" WHITE CIRCLE
/*<!M><Q>                                                          */ DEADTRANS( L'1'	,0xE506	,0x25D4	,0x0000	), // '1' ➔ "◔" CIRCLE WITH UPPER RIGHT QUADRANT BLACK
/*<!M><q>                                                          */ DEADTRANS( L'1'	,0xE505	,0x25F7	,0x0000	), // '1' ➔ "◷" WHITE CIRCLE WITH UPPER RIGHT QUADRANT
/*<!M><Q>                                                          */ DEADTRANS( L'2'	,0xE506	,0x25D1	,0x0000	), // '2' ➔ "◑" CIRCLE WITH RIGHT HALF BLACK
/*<!M><q>                                                          */ DEADTRANS( L'2'	,0xE505	,0x25F6	,0x0000	), // '2' ➔ "◶" WHITE CIRCLE WITH LOWER RIGHT QUADRANT
/*<!M><Q>                                                          */ DEADTRANS( L'3'	,0xE506	,0x25D5	,0x0000	), // '3' ➔ "◕" CIRCLE WITH ALL BUT UPPER LEFT QUADRANT BLACK
/*<!M><q>                                                          */ DEADTRANS( L'3'	,0xE505	,0x25F5	,0x0000	), // '3' ➔ "◵" WHITE CIRCLE WITH LOWER LEFT QUADRANT
/*<!M><Q>                                                          */ DEADTRANS( L'4'	,0xE506	,0x25CF	,0x0000	), // '4' ➔ "●" BLACK CIRCLE
/*<!M><q>                                                          */ DEADTRANS( L'4'	,0xE505	,0x25F4	,0x0000	), // '4' ➔ "◴" WHITE CIRCLE WITH UPPER LEFT QUADRANT
/*<!M><q>                                                          */ DEADTRANS( L'e'	,0xE505	,0x220E	,0x0000	), // 'e' ➔ "∎" END OF PROOF
/*<!M><Q>                                                          */ DEADTRANS( L'E'	,0xE506	,0x220E	,0x0000	), // 'E' ➔ "∎" END OF PROOF
/*<!M><q>                                                          */ DEADTRANS( L'p'	,0xE505	,0x0239	,0x0000	), // 'p' ➔ "ȹ" LATIN SMALL LETTER QP DIGRAPH
/*<!M><Q>                                                          */ DEADTRANS( L'Q'	,0xE506	,0x211A	,0x0000	), // 'Q' ➔ "ℚ" DOUBLE-STRUCK CAPITAL Q
/*<!M><r>                                                          */ DEADTRANS( L'@'	,0xE507	,0x03F1	,0x0000	), // '@' ➔ "ϱ" GREEK RHO SYMBOL
/*<!M><r>                                                          */ DEADTRANS( L'='	,0xE507	,0x20B9	,0x0000	), // '=' ➔ "₹" INDIAN RUPEE SIGN
/*<!M><R>                                                          */ DEADTRANS( L'='	,0xE508	,0x20B9	,0x0000	), // '=' ➔ "₹" INDIAN RUPEE SIGN
/*<!M><R>                                                          */ DEADTRANS( L'#'	,0xE508	,0x211C	,0x0000	), // '#' ➔ "ℜ" BLACK-LETTER CAPITAL R
/*<!M><R>                                                          */ DEADTRANS( L'-'	,0xE508	,0x211E	,0x0000	), // '-' ➔ "℞" PRESCRIPTION TAKE
/*<!M><r>                                                          */ DEADTRANS( L'-'	,0xE507	,0x211E	,0x0000	), // '-' ➔ "℞" PRESCRIPTION TAKE
/*<!M><R>                                                          */ DEADTRANS( L'/'	,0xE508	,0x211F	,0x0000	), // '/' ➔ "℟" RESPONSE
/*<!M><r>                                                          */ DEADTRANS( L'/'	,0xE507	,0x211F	,0x0000	), // '/' ➔ "℟" RESPONSE
/*<!M><R>                                                          */ DEADTRANS( L'~'	,0xE508	,0x211B	,0x0000	), // '~' ➔ "ℛ" SCRIPT CAPITAL R
/*<!M><R><C><C><C><D><D>                                           */ DEADTRANS( L'D'	,0xE509	,0x2188	,0x0000	), // 'D' ➔ "ↈ" ROMAN NUMERAL ONE HUNDRED THOUSAND
/*<!M><R><C><C><D>                                                 */ DEADTRANS( L'D'	,0xE50A	,0x2182	,0x0000	), // 'D' ➔ "ↂ" ROMAN NUMERAL TEN THOUSAND
/*<!M><R><C>                                                       */ DEADTRANS( L'D'	,0xE50B	,0x2180	,0x0000	), // 'D' ➔ "ↀ" ROMAN NUMERAL ONE THOUSAND C D
/*<!M><R><C><V>                                                    */ DEADTRANS( L'I'	,0xE50C	,0x2185	,0x0000	), // 'I' ➔ "ↅ" ROMAN NUMERAL SIX LATE FORM
/*<!M><R><D><D>                                                    */ DEADTRANS( L'D'	,0xE50D	,0x2187	,0x0000	), // 'D' ➔ "ↇ" ROMAN NUMERAL FIFTY THOUSAND
/*<!M><R><D><D>                                                    */ DEADTRANS( L' '	,0xE50D	,0x2181	,0x0000	), // ' ' ➔ "ↁ" ROMAN NUMERAL FIVE THOUSAND
/*<!M><r><e><c>                                                    */ DEADTRANS( L'a'	,0xE50E	,0x2672	,0x0000	), // 'a' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C>                                                    */ DEADTRANS( L'A'	,0xE50F	,0x2672	,0x0000	), // 'A' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c>                                                    */ DEADTRANS( L'e'	,0xE50E	,0x2672	,0x0000	), // 'e' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C>                                                    */ DEADTRANS( L'E'	,0xE50F	,0x2672	,0x0000	), // 'E' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c>                                                    */ DEADTRANS( L'f'	,0xE50E	,0x267B	,0x0000	), // 'f' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C>                                                    */ DEADTRANS( L'F'	,0xE50F	,0x267B	,0x0000	), // 'F' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c>                                                    */ DEADTRANS( L'g'	,0xE50E	,0x267B	,0x0000	), // 'g' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C>                                                    */ DEADTRANS( L'G'	,0xE50F	,0x267B	,0x0000	), // 'G' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c>                                                    */ DEADTRANS( L'i'	,0xE50E	,0x267B	,0x0000	), // 'i' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C>                                                    */ DEADTRANS( L'I'	,0xE50F	,0x267B	,0x0000	), // 'I' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c>                                                    */ DEADTRANS( L'o'	,0xE50E	,0x2672	,0x0000	), // 'o' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C>                                                    */ DEADTRANS( L'O'	,0xE50F	,0x2672	,0x0000	), // 'O' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c>                                                    */ DEADTRANS( L'p'	,0xE50E	,0x267B	,0x0000	), // 'p' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C>                                                    */ DEADTRANS( L'P'	,0xE50F	,0x267B	,0x0000	), // 'P' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c>                                                    */ DEADTRANS( L'u'	,0xE50E	,0x2672	,0x0000	), // 'u' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C>                                                    */ DEADTRANS( L'U'	,0xE50F	,0x2672	,0x0000	), // 'U' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c>                                                    */ DEADTRANS( L'v'	,0xE50E	,0x267B	,0x0000	), // 'v' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C>                                                    */ DEADTRANS( L'V'	,0xE50F	,0x267B	,0x0000	), // 'V' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e>                                                       */ DEADTRANS( L't'	,0xE510	,0x21B5	,0x0000	), // 't' ➔ "↵" DOWNWARDS ARROW WITH CORNER LEFTWARDS
/*<!M><R><E>                                                       */ DEADTRANS( L'T'	,0xE511	,0x23CE	,0x0000	), // 'T' ➔ "⏎" RETURN SYMBOL
/*<!M><R><L>                                                       */ DEADTRANS( L'L'	,0xE512	,0x2186	,0x0000	), // 'L' ➔ "ↆ" ROMAN NUMERAL FIFTY EARLY FORM
/*<!M><r>                                                          */ DEADTRANS( L'm'	,0xE507	,0xDD6C	,0x0000	), // High surrogate: D83C; U+1F16C 'm' ➔ "🅬" RAISED MR SIGN
/*<!M><R>                                                          */ DEADTRANS( L'M'	,0xE508	,0xDD6C	,0x0000	), // High surrogate: D83C; U+1F16C 'M' ➔ "🅬" RAISED MR SIGN
/*<!M><r>                                                          */ DEADTRANS( L'o'	,0xE507	,0x00AE	,0x0000	), // 'o' ➔ "®" REGISTERED SIGN emoji
/*<!M><R>                                                          */ DEADTRANS( L'O'	,0xE508	,0x00AE	,0x0000	), // 'O' ➔ "®" REGISTERED SIGN emoji
/*<!M><R><p><a><r><e><n><l>                                        */ DEADTRANS( L't'	,0xE513	,0x2996	,0x0000	), // 't' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET TeX + HTML under max 9 keysym constraint
/*<!M><R>                                                          */ DEADTRANS( L'R'	,0xE508	,0x211D	,0x0000	), // 'R' ➔ "ℝ" DOUBLE-STRUCK CAPITAL R
/*<!M><r>                                                          */ DEADTRANS( L'r'	,0xE507	,0xAB48	,0x0000	), // 'r' ➔ "ꭈ" LATIN SMALL LETTER DOUBLE R
/*<!M><R>                                                          */ DEADTRANS( L's'	,0xE508	,0x20A8	,0x0000	), // 's' ➔ "₨" RUPEE SIGN
/*<!M><r><u>                                                       */ DEADTRANS( L'b'	,0xE514	,0x20BD	,0x0000	), // 'b' ➔ "₽" RUBLE SIGN, Russian Ruble THE RUSSIAN FEDERATION
/*<!M><R><U>                                                       */ DEADTRANS( L'B'	,0xE515	,0x20BD	,0x0000	), // 'B' ➔ "₽" RUBLE SIGN, Russian Ruble THE RUSSIAN FEDERATION
/*<!M><r><u>                                                       */ DEADTRANS( L'm'	,0xE514	,0xA775	,0x0000	), // 'm' ➔ "ꝵ" LATIN SMALL LETTER RUM
/*<!M><R><U>                                                       */ DEADTRANS( L'M'	,0xE515	,0xA776	,0x0000	), // 'M' ➔ "ꝶ" LATIN LETTER SMALL CAPITAL RUM
/*<!M><R><u>                                                       */ DEADTRANS( L'm'	,0xE516	,0xA776	,0x0000	), // 'm' ➔ "ꝶ" LATIN LETTER SMALL CAPITAL RUM
/*<!M><R><U>                                                       */ DEADTRANS( L'R'	,0xE515	,0xA75C	,0x0000	), // 'R' ➔ "Ꝝ" LATIN CAPITAL LETTER RUM ROTUNDA
/*<!M><R><u>                                                       */ DEADTRANS( L'r'	,0xE516	,0xA75C	,0x0000	), // 'r' ➔ "Ꝝ" LATIN CAPITAL LETTER RUM ROTUNDA
/*<!M><r><u>                                                       */ DEADTRANS( L'r'	,0xE514	,0xA75D	,0x0000	), // 'r' ➔ "ꝝ" LATIN SMALL LETTER RUM ROTUNDA
/*<!M><s><%backslash>                                              */ DEADTRANS( L'%'	,0xE517	,0x223E	,0x0000	), // '%' ➔ "∾" INVERTED LAZY S
/*<!M><s><%backslash>                                              */ DEADTRANS( L'/'	,0xE517	,0x29CC	,0x0000	), // '/' ➔ "⧌" S IN TRIANGLE
/*<!M><s>                                                          */ DEADTRANS( L'{'	,0xE518	,0x27C5	,0x0000	), // '{' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S>                                                          */ DEADTRANS( L'{'	,0xE519	,0x27C5	,0x0000	), // '{' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s>                                                          */ DEADTRANS( L'}'	,0xE518	,0x27C6	,0x0000	), // '}' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S>                                                          */ DEADTRANS( L'}'	,0xE519	,0x27C6	,0x0000	), // '}' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketleft>                                            */ DEADTRANS( L']'	,0xE51A	,0x2A16	,0x0000	), // ']' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><S><%bracketleft>                                            */ DEADTRANS( L']'	,0xE51B	,0x2A16	,0x0000	), // ']' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><s><%bracketleft>                                            */ DEADTRANS( 0x00A0	,0xE51A	,0x27C5	,0x0000	), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketleft>                                            */ DEADTRANS( 0x00A0	,0xE51B	,0x27C5	,0x0000	), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketleft>                                            */ DEADTRANS( L' '	,0xE51A	,0x27C5	,0x0000	), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketleft>                                            */ DEADTRANS( L' '	,0xE51B	,0x27C5	,0x0000	), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketright>                                           */ DEADTRANS( L'['	,0xE51C	,0x2A16	,0x0000	), // '[' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><S><%bracketright>                                           */ DEADTRANS( L'['	,0xE51D	,0x2A16	,0x0000	), // '[' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><s><%bracketright>                                           */ DEADTRANS( 0x00A0	,0xE51C	,0x27C6	,0x0000	), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketright>                                           */ DEADTRANS( 0x00A0	,0xE51D	,0x27C6	,0x0000	), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketright>                                           */ DEADTRANS( L' '	,0xE51C	,0x27C6	,0x0000	), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketright>                                           */ DEADTRANS( L' '	,0xE51D	,0x27C6	,0x0000	), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S>                                                          */ DEADTRANS( L'='	,0xE519	,0x20B4	,0x0000	), // '=' ➔ "₴" HRYVNIA SIGN
/*<!M><s>                                                          */ DEADTRANS( L'='	,0xE518	,0x2A0E	,0x0000	), // '=' ➔ "⨎" INTEGRAL WITH DOUBLE STROKE
/*<!M><s>                                                          */ DEADTRANS( L'!'	,0xE518	,0x00A7	,0x0000	), // '!' ➔ "§" SECTION SIGN
/*<!M><S>                                                          */ DEADTRANS( L'!'	,0xE519	,0x00A7	,0x0000	), // '!' ➔ "§" SECTION SIGN
/*<!M><S>                                                          */ DEADTRANS( L'#'	,0xE519	,0x266C	,0x0000	), // '#' ➔ "♬" BEAMED SIXTEENTH NOTES
/*<!M><s>                                                          */ DEADTRANS( L'#'	,0xE518	,0x266F	,0x0000	), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><s><%less>                                                   */ DEADTRANS( L'-'	,0xE51E	,0x2A17	,0x0000	), // '-' ➔ "⨗" INTEGRAL WITH LEFTWARDS ARROW WITH HOOK
/*<!M><S><%less>                                                   */ DEADTRANS( L'-'	,0xE51F	,0x2A17	,0x0000	), // '-' ➔ "⨗" INTEGRAL WITH LEFTWARDS ARROW WITH HOOK
/*<!M><S>                                                          */ DEADTRANS( L'-'	,0xE519	,0x20B4	,0x0000	), // '-' ➔ "₴" HRYVNIA SIGN
/*<!M><s>                                                          */ DEADTRANS( L'-'	,0xE518	,0x2A0D	,0x0000	), // '-' ➔ "⨍" FINITE PART INTEGRAL
/*<!M><s>                                                          */ DEADTRANS( L'('	,0xE518	,0x2231	,0x0000	), // '(' ➔ "∱" CLOCKWISE INTEGRAL
/*<!M><S>                                                          */ DEADTRANS( L'('	,0xE519	,0x2231	,0x0000	), // '(' ➔ "∱" CLOCKWISE INTEGRAL
/*<!M><s>                                                          */ DEADTRANS( L')'	,0xE518	,0x2A11	,0x0000	), // ')' ➔ "⨑" ANTICLOCKWISE INTEGRATION
/*<!M><S>                                                          */ DEADTRANS( L')'	,0xE519	,0x2A11	,0x0000	), // ')' ➔ "⨑" ANTICLOCKWISE INTEGRATION
/*<!M><s><%percent>                                                */ DEADTRANS( L'\\'	,0xE520	,0x223E	,0x0000	), // '\' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent>                                                */ DEADTRANS( L'%'	,0xE520	,0x223E	,0x0000	), // '%' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent>                                                */ DEADTRANS( 0x00A0	,0xE520	,0x223E	,0x0000	), // ' ' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent>                                                */ DEADTRANS( L' '	,0xE520	,0x223E	,0x0000	), // ' ' ➔ "∾" INVERTED LAZY S
/*<!M><s><%period>                                                 */ DEADTRANS( L']'	,0xE521	,0x2A12	,0x0000	), // ']' ➔ "⨒" LINE INTEGRATION WITH RECTANGULAR PATH AROUND POLE
/*<!M><S><%period>                                                 */ DEADTRANS( L']'	,0xE522	,0x2A12	,0x0000	), // ']' ➔ "⨒" LINE INTEGRATION WITH RECTANGULAR PATH AROUND POLE
/*<!M><s><%period>                                                 */ DEADTRANS( L')'	,0xE521	,0x2A13	,0x0000	), // ')' ➔ "⨓" LINE INTEGRATION WITH SEMICIRCULAR PATH AROUND POLE
/*<!M><S><%period>                                                 */ DEADTRANS( L')'	,0xE522	,0x2A13	,0x0000	), // ')' ➔ "⨓" LINE INTEGRATION WITH SEMICIRCULAR PATH AROUND POLE
/*<!M><s><%period>                                                 */ DEADTRANS( L'o'	,0xE521	,0x2A14	,0x0000	), // 'o' ➔ "⨔" LINE INTEGRATION NOT INCLUDING THE POLE
/*<!M><S><%period>                                                 */ DEADTRANS( L'o'	,0xE522	,0x2A14	,0x0000	), // 'o' ➔ "⨔" LINE INTEGRATION NOT INCLUDING THE POLE
/*<!M><S>                                                          */ DEADTRANS( L'/'	,0xE519	,0x2A0F	,0x0000	), // '/' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s><%slash>                                                  */ DEADTRANS( L'\\'	,0xE523	,0x29CC	,0x0000	), // '\' ➔ "⧌" S IN TRIANGLE
/*<!M><s><%slash>                                                  */ DEADTRANS( 0x00A0	,0xE523	,0x2A0F	,0x0000	), // ' ' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s><%slash>                                                  */ DEADTRANS( L' '	,0xE523	,0x2A0F	,0x0000	), // ' ' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s>                                                          */ DEADTRANS( L'_'	,0xE518	,0x2A1C	,0x0000	), // '_' ➔ "⨜" INTEGRAL WITH UNDERBAR
/*<!M><S>                                                          */ DEADTRANS( L'_'	,0xE519	,0x2A1C	,0x0000	), // '_' ➔ "⨜" INTEGRAL WITH UNDERBAR
/*<!M><s><a><g>                                                    */ DEADTRANS( L'i'	,0xE524	,0x2650	,0x0000	), // 'i' ➔ "♐" SAGITTARIUS emoji
/*<!M><S><A><G>                                                    */ DEADTRANS( L'I'	,0xE525	,0x2650	,0x0000	), // 'I' ➔ "♐" SAGITTARIUS emoji
/*<!M><s><a>                                                       */ DEADTRANS( L'm'	,0xE526	,0x214F	,0x0000	), // 'm' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><S><a>                                                       */ DEADTRANS( L'm'	,0xE527	,0x214F	,0x0000	), // 'm' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><S><A>                                                       */ DEADTRANS( L'M'	,0xE528	,0x214F	,0x0000	), // 'M' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><s><c><o>                                                    */ DEADTRANS( L'r'	,0xE529	,0x264F	,0x0000	), // 'r' ➔ "♏" SCORPIUS emoji
/*<!M><S><C><O>                                                    */ DEADTRANS( L'R'	,0xE52A	,0x264F	,0x0000	), // 'R' ➔ "♏" SCORPIUS emoji
/*<!M><s><c>                                                       */ DEADTRANS( L'r'	,0xE52B	,0x2108	,0x0000	), // 'r' ➔ "℈" SCRUPLE
/*<!M><S><c>                                                       */ DEADTRANS( L'r'	,0xE52C	,0x2108	,0x0000	), // 'r' ➔ "℈" SCRUPLE
/*<!M><S><C>                                                       */ DEADTRANS( L'R'	,0xE52D	,0x2108	,0x0000	), // 'R' ➔ "℈" SCRUPLE
/*<!M><s><c>                                                       */ DEADTRANS( 0x00A0	,0xE52B	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><c>                                                       */ DEADTRANS( 0x00A0	,0xE52C	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><C>                                                       */ DEADTRANS( 0x00A0	,0xE52D	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><s><c>                                                       */ DEADTRANS( L' '	,0xE52B	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><c>                                                       */ DEADTRANS( L' '	,0xE52C	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><C>                                                       */ DEADTRANS( L' '	,0xE52D	,0x2A10	,0x0000	), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><s><e>                                                       */ DEADTRANS( L'r'	,0xE52E	,0x26CE	,0x0000	), // 'r' ➔ "⛎" OPHIUCHUS emoji
/*<!M><S><E>                                                       */ DEADTRANS( L'R'	,0xE52F	,0x26CE	,0x0000	), // 'R' ➔ "⛎" OPHIUCHUS emoji
/*<!M><s><e><t><m><i><n><u>                                        */ DEADTRANS( L's'	,0xE530	,0x2216	,0x0000	), // 's' ➔ "∖" SET MINUS
/*<!M><S>                                                          */ DEADTRANS( L'H'	,0xE519	,0x01A9	,0x0000	), // 'H' ➔ "Ʃ" LATIN CAPITAL LETTER ESH
/*<!M><S>                                                          */ DEADTRANS( L'h'	,0xE519	,0x01A9	,0x0000	), // 'h' ➔ "Ʃ" LATIN CAPITAL LETTER ESH
/*<!M><s>                                                          */ DEADTRANS( L'h'	,0xE518	,0x0283	,0x0000	), // 'h' ➔ "ʃ" LATIN SMALL LETTER ESH
/*<!M><s><i>                                                       */ DEADTRANS( L'n'	,0xE531	,0x223F	,0x0000	), // 'n' ➔ "∿" SINE WAVE
/*<!M><S><I>                                                       */ DEADTRANS( L'N'	,0xE532	,0x223F	,0x0000	), // 'N' ➔ "∿" SINE WAVE
/*<!M><s>                                                          */ DEADTRANS( L'm'	,0xE518	,0x2120	,0x0000	), // 'm' ➔ "℠" SERVICE MARK
/*<!M><S>                                                          */ DEADTRANS( L'M'	,0xE519	,0x2120	,0x0000	), // 'M' ➔ "℠" SERVICE MARK
/*<!M><S>                                                          */ DEADTRANS( L'n'	,0xE519	,0x2A19	,0x0000	), // 'n' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><n>                                                       */ DEADTRANS( L'o'	,0xE533	,0x2744	,0x0000	), // 'o' ➔ "❄" SNOWFLAKE emoji
/*<!M><S><N>                                                       */ DEADTRANS( L'O'	,0xE534	,0x2744	,0x0000	), // 'O' ➔ "❄" SNOWFLAKE emoji
/*<!M><s><n>                                                       */ DEADTRANS( 0x00A0	,0xE533	,0x2A19	,0x0000	), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><S><N>                                                       */ DEADTRANS( 0x00A0	,0xE534	,0x2A19	,0x0000	), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><n>                                                       */ DEADTRANS( L' '	,0xE533	,0x2A19	,0x0000	), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><S><N>                                                       */ DEADTRANS( L' '	,0xE534	,0x2A19	,0x0000	), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><o>                                                       */ DEADTRANS( L'>'	,0xE535	,0x2232	,0x0000	), // '>' ➔ "∲" CLOCKWISE CONTOUR INTEGRAL
/*<!M><S><o>                                                       */ DEADTRANS( L'>'	,0xE536	,0x2232	,0x0000	), // '>' ➔ "∲" CLOCKWISE CONTOUR INTEGRAL
/*<!M><s><o>                                                       */ DEADTRANS( L'<'	,0xE535	,0x2233	,0x0000	), // '<' ➔ "∳" ANTICLOCKWISE CONTOUR INTEGRAL
/*<!M><S><o>                                                       */ DEADTRANS( L'<'	,0xE536	,0x2233	,0x0000	), // '<' ➔ "∳" ANTICLOCKWISE CONTOUR INTEGRAL
/*<!M><s><o>                                                       */ DEADTRANS( L'.'	,0xE535	,0x2A15	,0x0000	), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><S><o>                                                       */ DEADTRANS( L'.'	,0xE536	,0x2A15	,0x0000	), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><S><O>                                                       */ DEADTRANS( L'.'	,0xE537	,0x2A15	,0x0000	), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><s><o>                                                       */ DEADTRANS( L'l'	,0xE535	,0x2600	,0x0000	), // 'l' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><S><O>                                                       */ DEADTRANS( L'L'	,0xE537	,0x2600	,0x0000	), // 'L' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><s><o>                                                       */ DEADTRANS( 0x00A0	,0xE535	,0x222E	,0x0000	), // ' ' ➔ "∮" CONTOUR INTEGRAL
/*<!M><S><o>                                                       */ DEADTRANS( 0x00A0	,0xE536	,0x2A0A	,0x0000	), // ' ' ➔ "⨊" MODULO TWO SUM
/*<!M><s><o>                                                       */ DEADTRANS( L' '	,0xE535	,0x222E	,0x0000	), // ' ' ➔ "∮" CONTOUR INTEGRAL
/*<!M><S><o>                                                       */ DEADTRANS( L' '	,0xE536	,0x2A0A	,0x0000	), // ' ' ➔ "⨊" MODULO TWO SUM
/*<!M><s>                                                          */ DEADTRANS( L'p'	,0xE518	,0x2423	,0x0000	), // 'p' ➔ "␣" OPEN BOX
/*<!M><S>                                                          */ DEADTRANS( L'P'	,0xE519	,0x2423	,0x0000	), // 'P' ➔ "␣" OPEN BOX
/*<!M><s>                                                          */ DEADTRANS( L'S'	,0xE518	,0x00A7	,0x0000	), // 'S' ➔ "§" SECTION SIGN
/*<!M><s>                                                          */ DEADTRANS( L's'	,0xE518	,0x00DF	,0x0000	), // 's' ➔ "ß" LATIN SMALL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( L'S'	,0xE519	,0x1E9E	,0x0000	), // 'S' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( L's'	,0xE519	,0x1E9E	,0x0000	), // 's' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( L'u'	,0xE519	,0x2A1A	,0x0000	), // 'u' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><u>                                                       */ DEADTRANS( L'n'	,0xE538	,0x2600	,0x0000	), // 'n' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><S><U>                                                       */ DEADTRANS( L'N'	,0xE539	,0x2600	,0x0000	), // 'N' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><s><u>                                                       */ DEADTRANS( 0x00A0	,0xE538	,0x2A1A	,0x0000	), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><S><U>                                                       */ DEADTRANS( 0x00A0	,0xE539	,0x2A1A	,0x0000	), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><u>                                                       */ DEADTRANS( L' '	,0xE538	,0x2A1A	,0x0000	), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><S><U>                                                       */ DEADTRANS( L' '	,0xE539	,0x2A1A	,0x0000	), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><v>                                                       */ DEADTRANS( L'c'	,0xE53A	,0x20A1	,0x0000	), // 'c' ➔ "₡" COLON SIGN, El Salvador Colon EL SALVADOR
/*<!M><S><V>                                                       */ DEADTRANS( L'C'	,0xE53B	,0x20A1	,0x0000	), // 'C' ➔ "₡" COLON SIGN, El Salvador Colon EL SALVADOR
/*<!M><s>                                                          */ DEADTRANS( L'x'	,0xE518	,0x2A18	,0x0000	), // 'x' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><S>                                                          */ DEADTRANS( L'x'	,0xE519	,0x2A18	,0x0000	), // 'x' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><S>                                                          */ DEADTRANS( L'X'	,0xE519	,0x2A18	,0x0000	), // 'X' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><s>                                                          */ DEADTRANS( L'z'	,0xE518	,0x00DF	,0x0000	), // 'z' ➔ "ß" LATIN SMALL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( L'Z'	,0xE519	,0x1E9E	,0x0000	), // 'Z' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( L'z'	,0xE519	,0x1E9E	,0x0000	), // 'z' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S>                                                          */ DEADTRANS( 0x00A0	,0xE519	,0x2211	,0x0000	), // ' ' ➔ "∑" N-ARY SUMMATION
/*<!M><s>                                                          */ DEADTRANS( 0x00A0	,0xE518	,0x222B	,0x0000	), // ' ' ➔ "∫" INTEGRAL
/*<!M><S>                                                          */ DEADTRANS( L' '	,0xE519	,0x2211	,0x0000	), // ' ' ➔ "∑" N-ARY SUMMATION
/*<!M><s>                                                          */ DEADTRANS( L' '	,0xE518	,0x222B	,0x0000	), // ' ' ➔ "∫" INTEGRAL
/*<!M><T>                                                          */ DEADTRANS( L'\''	,0xE53C	,0x2ADF	,0x0000	), // ''' ➔ "⫟" SHORT DOWN TACK
/*<!M><T>                                                          */ DEADTRANS( 0x2019	,0xE53C	,0x2ADF	,0x0000	), // '’' ➔ "⫟" SHORT DOWN TACK
/*<!M><T>                                                          */ DEADTRANS( L'@'	,0xE53C	,0x03F4	,0x0000	), // '@' ➔ "ϴ" GREEK CAPITAL THETA SYMBOL
/*<!M><t>                                                          */ DEADTRANS( L'@'	,0xE53D	,0x03D1	,0x0000	), // '@' ➔ "ϑ" GREEK THETA SYMBOL
/*<!M><T>                                                          */ DEADTRANS( L'|'	,0xE53C	,0x27D9	,0x0000	), // '|' ➔ "⟙" LARGE DOWN TACK
/*<!M><t>                                                          */ DEADTRANS( L'='	,0xE53D	,0x20AE	,0x0000	), // '=' ➔ "₮" TUGRIK SIGN
/*<!M><T>                                                          */ DEADTRANS( L'='	,0xE53C	,0x20AE	,0x0000	), // '=' ➔ "₮" TUGRIK SIGN
/*<!M><T><%greater>                                                */ DEADTRANS( L'\''	,0xE53E	,0x22A6	,0x0000	), // ''' ➔ "⊦" ASSERTION
/*<!M><T><%greater>                                                */ DEADTRANS( 0x2019	,0xE53E	,0x22A6	,0x0000	), // '’' ➔ "⊦" ASSERTION
/*<!M><T><%greater>                                                */ DEADTRANS( L'|'	,0xE53E	,0x27DD	,0x0000	), // '|' ➔ "⟝" LONG RIGHT TACK
/*<!M><T><%greater>                                                */ DEADTRANS( L'<'	,0xE53E	,0x27DB	,0x0000	), // '<' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><T><%greater>                                                */ DEADTRANS( L'/'	,0xE53E	,0x22AC	,0x0000	), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><T><%greater>                                                */ DEADTRANS( 0x00A0	,0xE53E	,0x22A2	,0x0000	), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><T><%greater>                                                */ DEADTRANS( L' '	,0xE53E	,0x22A2	,0x0000	), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( L'\''	,0xE53F	,0x2ADE	,0x0000	), // ''' ➔ "⫞" SHORT LEFT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( 0x2019	,0xE53F	,0x2ADE	,0x0000	), // '’' ➔ "⫞" SHORT LEFT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( L'|'	,0xE53F	,0x27DE	,0x0000	), // '|' ➔ "⟞" LONG LEFT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( L'>'	,0xE53F	,0x27DB	,0x0000	), // '>' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( 0x00A0	,0xE53F	,0x22A3	,0x0000	), // ' ' ➔ "⊣" LEFT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( L' '	,0xE53F	,0x22A3	,0x0000	), // ' ' ➔ "⊣" LEFT TACK
/*<!M><t>                                                          */ DEADTRANS( L'-'	,0xE53D	,0x20AE	,0x0000	), // '-' ➔ "₮" TUGRIK SIGN
/*<!M><T>                                                          */ DEADTRANS( L'-'	,0xE53C	,0x20AE	,0x0000	), // '-' ➔ "₮" TUGRIK SIGN
/*<!M><T><%percent>                                                */ DEADTRANS( L'\''	,0xE540	,0x2AE0	,0x0000	), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><T><%percent>                                                */ DEADTRANS( L'|'	,0xE540	,0x27D8	,0x0000	), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><T><%percent>                                                */ DEADTRANS( L'%'	,0xE540	,0x2AE9	,0x0000	), // '%' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><%percent>                                                */ DEADTRANS( 0x00A0	,0xE540	,0x22A5	,0x0000	), // ' ' ➔ "⊥" UP TACK
/*<!M><T><%percent>                                                */ DEADTRANS( L' '	,0xE540	,0x22A5	,0x0000	), // ' ' ➔ "⊥" UP TACK
/*<!M><t>                                                          */ DEADTRANS( L'1'	,0xE53D	,0xA716	,0x0000	), // '1' ➔ "꜖" MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*<!M><T>                                                          */ DEADTRANS( L'1'	,0xE53C	,0xA716	,0x0000	), // '1' ➔ "꜖" MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*<!M><t>                                                          */ DEADTRANS( L'2'	,0xE53D	,0xA715	,0x0000	), // '2' ➔ "꜕" MODIFIER LETTER LOW LEFT-STEM TONE BAR
/*<!M><T><2><%greater>                                             */ DEADTRANS( L'\''	,0xE541	,0x22A7	,0x0000	), // ''' ➔ "⊧" MODELS
/*<!M><T><2><%greater>                                             */ DEADTRANS( 0x2019	,0xE541	,0x22A7	,0x0000	), // '’' ➔ "⊧" MODELS
/*<!M><T><2><%greater>                                             */ DEADTRANS( L'<'	,0xE541	,0x27DA	,0x0000	), // '<' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><T><2><%greater>                                             */ DEADTRANS( L'/'	,0xE541	,0x22AD	,0x0000	), // '/' ➔ "⊭" NOT TRUE
/*<!M><T><2><%greater>                                             */ DEADTRANS( 0x00A0	,0xE541	,0x22A8	,0x0000	), // ' ' ➔ "⊨" TRUE
/*<!M><T><2><%greater>                                             */ DEADTRANS( L' '	,0xE541	,0x22A8	,0x0000	), // ' ' ➔ "⊨" TRUE
/*<!M><T><2><%less>                                                */ DEADTRANS( L'>'	,0xE542	,0x27DA	,0x0000	), // '>' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><T><2><%less>                                                */ DEADTRANS( 0x00A0	,0xE542	,0x2AE4	,0x0000	), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><T><2><%less>                                                */ DEADTRANS( L' '	,0xE542	,0x2AE4	,0x0000	), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><T><2>                                                       */ DEADTRANS( L'%'	,0xE543	,0x2AEB	,0x0000	), // '%' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><2>                                                       */ DEADTRANS( 0x00A0	,0xE543	,0x2AEA	,0x0000	), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><T><2>                                                       */ DEADTRANS( L' '	,0xE543	,0x2AEA	,0x0000	), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><t>                                                          */ DEADTRANS( L'3'	,0xE53D	,0xA714	,0x0000	), // '3' ➔ "꜔" MODIFIER LETTER MID LEFT-STEM TONE BAR
/*<!M><T><3>                                                       */ DEADTRANS( L'>'	,0xE544	,0x2AE2	,0x0000	), // '>' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><t>                                                          */ DEADTRANS( L'4'	,0xE53D	,0xA713	,0x0000	), // '4' ➔ "꜓" MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*<!M><T>                                                          */ DEADTRANS( L'4'	,0xE53C	,0xA713	,0x0000	), // '4' ➔ "꜓" MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*<!M><t>                                                          */ DEADTRANS( L'5'	,0xE53D	,0xA712	,0x0000	), // '5' ➔ "꜒" MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*<!M><T>                                                          */ DEADTRANS( L'5'	,0xE53C	,0xA712	,0x0000	), // '5' ➔ "꜒" MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*<!M><t><a>                                                       */ DEADTRANS( L'b'	,0xE545	,0x21B9	,0x0000	), // 'b' ➔ "↹" LEFTWARDS ARROW TO BAR OVER RIGHTWARDS ARROW TO BAR, tab with shift tab
/*<!M><T><A>                                                       */ DEADTRANS( L'B'	,0xE546	,0x2B7E	,0x0000	), // 'B' ➔ "⭾" HORIZONTAL TAB KEY
/*<!M><t><a>                                                       */ DEADTRANS( L'i'	,0xE545	,0x25C9	,0x0000	), // 'i' ➔ "◉" FISHEYE, Japanese tainome, bullet
/*<!M><T><A>                                                       */ DEADTRANS( L'I'	,0xE546	,0x25C9	,0x0000	), // 'I' ➔ "◉" FISHEYE, Japanese tainome, bullet
/*<!M><t><a><u>                                                    */ DEADTRANS( L'r'	,0xE547	,0x2649	,0x0000	), // 'r' ➔ "♉" TAURUS emoji
/*<!M><T><A><U>                                                    */ DEADTRANS( L'R'	,0xE548	,0x2649	,0x0000	), // 'R' ➔ "♉" TAURUS emoji
/*<!M><t>                                                          */ DEADTRANS( L'c'	,0xE53D	,0x02A8	,0x0000	), // 'c' ➔ "ʨ" LATIN SMALL LETTER TC DIGRAPH WITH CURL
/*<!M><T>                                                          */ DEADTRANS( L'E'	,0xE53C	,0x2121	,0x0000	), // 'E' ➔ "℡" TELEPHONE SIGN
/*<!M><T>                                                          */ DEADTRANS( L'e'	,0xE53C	,0x2121	,0x0000	), // 'e' ➔ "℡" TELEPHONE SIGN
/*<!M><t><e>                                                       */ DEADTRANS( L'c'	,0xE549	,0x02A7	,0x0000	), // 'c' ➔ "ʧ" LATIN SMALL LETTER TESH DIGRAPH
/*<!M><t><e>                                                       */ DEADTRANS( L'l'	,0xE549	,0x2121	,0x0000	), // 'l' ➔ "℡" TELEPHONE SIGN
/*<!M><t><e>                                                       */ DEADTRANS( L's'	,0xE549	,0x02A7	,0x0000	), // 's' ➔ "ʧ" LATIN SMALL LETTER TESH DIGRAPH
/*<!M><T>                                                          */ DEADTRANS( L'h'	,0xE53C	,0x00DE	,0x0000	), // 'h' ➔ "Þ" LATIN CAPITAL LETTER THORN
/*<!M><t><h>                                                       */ DEADTRANS( L'/'	,0xE54A	,0x1D7A	,0x0000	), // '/' ➔ "ᵺ" LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*<!M><t><h>                                                       */ DEADTRANS( L'b'	,0xE54A	,0x0E3F	,0x0000	), // 'b' ➔ "฿" THAI CURRENCY SYMBOL BAHT, Baht THAILAND
/*<!M><T><H>                                                       */ DEADTRANS( L'B'	,0xE54B	,0x0E3F	,0x0000	), // 'B' ➔ "฿" THAI CURRENCY SYMBOL BAHT, Baht THAILAND
/*<!M><T><H>                                                       */ DEADTRANS( L' '	,0xE54B	,0x00DE	,0x0000	), // ' ' ➔ "Þ" LATIN CAPITAL LETTER THORN
/*<!M><t><h>                                                       */ DEADTRANS( L' '	,0xE54A	,0x00FE	,0x0000	), // ' ' ➔ "þ" LATIN SMALL LETTER THORN
/*<!M><t>                                                          */ DEADTRANS( L'm'	,0xE53D	,0x2122	,0x0000	), // 'm' ➔ "™" TRADE MARK SIGN emoji
/*<!M><T>                                                          */ DEADTRANS( L'M'	,0xE53C	,0x2122	,0x0000	), // 'M' ➔ "™" TRADE MARK SIGN emoji
/*<!M><T>                                                          */ DEADTRANS( L'n'	,0xE53C	,0x2ADA	,0x0000	), // 'n' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><t><n>                                                       */ DEADTRANS( 0x00A0	,0xE54C	,0x2ADA	,0x0000	), // ' ' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><t><n>                                                       */ DEADTRANS( L' '	,0xE54C	,0x2ADA	,0x0000	), // ' ' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><T>                                                          */ DEADTRANS( L'o'	,0xE53C	,0x2AF1	,0x0000	), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><o>                                                       */ DEADTRANS( L'x'	,0xE54D	,0x2620	,0x0000	), // 'x' ➔ "☠" SKULL AND CROSSBONES emoji
/*<!M><T><O>                                                       */ DEADTRANS( L'X'	,0xE54E	,0x2620	,0x0000	), // 'X' ➔ "☠" SKULL AND CROSSBONES emoji
/*<!M><t><o>                                                       */ DEADTRANS( 0x00A0	,0xE54D	,0x2AF1	,0x0000	), // ' ' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><o>                                                       */ DEADTRANS( L' '	,0xE54D	,0x2AF1	,0x0000	), // ' ' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><r>                                                       */ DEADTRANS( L'y'	,0xE54F	,0x20BA	,0x0000	), // 'y' ➔ "₺" TURKISH LIRA SIGN, Turkish Lira TÜRKİYE
/*<!M><T><R>                                                       */ DEADTRANS( L'Y'	,0xE550	,0x20BA	,0x0000	), // 'Y' ➔ "₺" TURKISH LIRA SIGN, Turkish Lira TÜRKİYE
/*<!M><t>                                                          */ DEADTRANS( L's'	,0xE53D	,0x02A6	,0x0000	), // 's' ➔ "ʦ" LATIN SMALL LETTER TS DIGRAPH
/*<!M><T><T>                                                       */ DEADTRANS( L'\''	,0xE551	,0x2AE0	,0x0000	), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><T><T>                                                       */ DEADTRANS( L'|'	,0xE551	,0x27D8	,0x0000	), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><T><T><%percent>                                             */ DEADTRANS( L'\''	,0xE552	,0x2AE9	,0x0000	), // ''' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><T><%percent>                                             */ DEADTRANS( 0x2019	,0xE552	,0x2AE9	,0x0000	), // '’' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><T><%percent>                                             */ DEADTRANS( 0x00A0	,0xE552	,0x2AEB	,0x0000	), // ' ' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><T><%percent>                                             */ DEADTRANS( L' '	,0xE552	,0x2AEB	,0x0000	), // ' ' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><T>                                                       */ DEADTRANS( 0x00A0	,0xE551	,0x2AEA	,0x0000	), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><T><T>                                                       */ DEADTRANS( L' '	,0xE551	,0x2AEA	,0x0000	), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><t>                                                          */ DEADTRANS( L'u'	,0xE53D	,0xA777	,0x0000	), // 'u' ➔ "ꝷ" LATIN SMALL LETTER TUM
/*<!M><T>                                                          */ DEADTRANS( L'Z'	,0xE53C	,0xA728	,0x0000	), // 'Z' ➔ "Ꜩ" LATIN CAPITAL LETTER TZ
/*<!M><T>                                                          */ DEADTRANS( L'z'	,0xE53C	,0xA728	,0x0000	), // 'z' ➔ "Ꜩ" LATIN CAPITAL LETTER TZ
/*<!M><t>                                                          */ DEADTRANS( L'z'	,0xE53D	,0xA729	,0x0000	), // 'z' ➔ "ꜩ" LATIN SMALL LETTER TZ
/*<!M><T>                                                          */ DEADTRANS( 0x00A0	,0xE53C	,0x22A4	,0x0000	), // ' ' ➔ "⊤" DOWN TACK
/*<!M><t>                                                          */ DEADTRANS( 0x00A0	,0xE53D	,0x22BA	,0x0000	), // ' ' ➔ "⊺" INTERCALATE
/*<!M><T>                                                          */ DEADTRANS( L' '	,0xE53C	,0x22A4	,0x0000	), // ' ' ➔ "⊤" DOWN TACK
/*<!M><t>                                                          */ DEADTRANS( L' '	,0xE53D	,0x22BA	,0x0000	), // ' ' ➔ "⊺" INTERCALATE
/*<!M><U>                                                          */ DEADTRANS( L'@'	,0xE553	,0x03F4	,0x0000	), // '@' ➔ "ϴ" GREEK CAPITAL THETA SYMBOL
/*<!M><u>                                                          */ DEADTRANS( L'@'	,0xE554	,0x03D1	,0x0000	), // '@' ➔ "ϑ" GREEK THETA SYMBOL
/*<!M><u>                                                          */ DEADTRANS( L'['	,0xE554	,0x2294	,0x0000	), // '[' ➔ "⊔" SQUARE CUP
/*<!M><U>                                                          */ DEADTRANS( L'['	,0xE553	,0x2A06	,0x0000	), // '[' ➔ "⨆" N-ARY SQUARE UNION OPERATOR
/*<!M><u>                                                          */ DEADTRANS( L']'	,0xE554	,0x2294	,0x0000	), // ']' ➔ "⊔" SQUARE CUP
/*<!M><U>                                                          */ DEADTRANS( L']'	,0xE553	,0x2A06	,0x0000	), // ']' ➔ "⨆" N-ARY SQUARE UNION OPERATOR
/*<!M><u>                                                          */ DEADTRANS( L'<'	,0xE554	,0x228C	,0x0000	), // '<' ➔ "⊌" MULTISET
/*<!M><u><%minus>                                                  */ DEADTRANS( 0x00A0	,0xE555	,0x2A41	,0x0000	), // ' ' ➔ "⩁" UNION WITH MINUS SIGN
/*<!M><u><%minus>                                                  */ DEADTRANS( L' '	,0xE555	,0x2A41	,0x0000	), // ' ' ➔ "⩁" UNION WITH MINUS SIGN
/*<!M><u>                                                          */ DEADTRANS( L'.'	,0xE554	,0x228D	,0x0000	), // '.' ➔ "⊍" MULTISET MULTIPLICATION
/*<!M><U>                                                          */ DEADTRANS( L'.'	,0xE553	,0x2A03	,0x0000	), // '.' ➔ "⨃" N-ARY UNION OPERATOR WITH DOT
/*<!M><u>                                                          */ DEADTRANS( L'+'	,0xE554	,0x228E	,0x0000	), // '+' ➔ "⊎" MULTISET UNION
/*<!M><U>                                                          */ DEADTRANS( L'+'	,0xE553	,0x2A04	,0x0000	), // '+' ➔ "⨄" N-ARY UNION OPERATOR WITH PLUS
/*<!M><u>                                                          */ DEADTRANS( L'_'	,0xE554	,0x2A48	,0x0000	), // '_' ➔ "⩈" UNION ABOVE BAR ABOVE INTERSECTION
/*<!M><u><a>                                                       */ DEADTRANS( L'h'	,0xE556	,0x20B4	,0x0000	), // 'h' ➔ "₴" HRYVNIA SIGN, Hryvnia UKRAINE
/*<!M><U><A>                                                       */ DEADTRANS( L'H'	,0xE557	,0x20B4	,0x0000	), // 'H' ➔ "₴" HRYVNIA SIGN, Hryvnia UKRAINE
/*<!M><u>                                                          */ DEADTRANS( L'e'	,0xE554	,0x1D6B	,0x0000	), // 'e' ➔ "ᵫ" LATIN SMALL LETTER UE
/*<!M><u>                                                          */ DEADTRANS( L'i'	,0xE554	,0xAB50	,0x0000	), // 'i' ➔ "ꭐ" LATIN SMALL LETTER UI
/*<!M><u>                                                          */ DEADTRANS( L'm'	,0xE554	,0xA778	,0x0000	), // 'm' ➔ "ꝸ" LATIN SMALL LETTER UM
/*<!M><u><n><i><o>                                                 */ DEADTRANS( L'n'	,0xE558	,0x222A	,0x0000	), // 'n' ➔ "∪" UNION French name
/*<!M><u><n>                                                       */ DEADTRANS( 0x00A0	,0xE559	,0x2A46	,0x0000	), // ' ' ➔ "⩆" UNION ABOVE INTERSECTION
/*<!M><u><n>                                                       */ DEADTRANS( L' '	,0xE559	,0x2A46	,0x0000	), // ' ' ➔ "⩆" UNION ABOVE INTERSECTION
/*<!M><u>                                                          */ DEADTRANS( L'o'	,0xE554	,0xAB63	,0x0000	), // 'o' ➔ "ꭣ" LATIN SMALL LETTER UO
/*<!M><u>                                                          */ DEADTRANS( L'u'	,0xE554	,0x2A4A	,0x0000	), // 'u' ➔ "⩊" UNION BESIDE AND JOINED WITH UNION
/*<!M><u>                                                          */ DEADTRANS( L'v'	,0xE554	,0x2A45	,0x0000	), // 'v' ➔ "⩅" UNION WITH LOGICAL OR
/*<!M><u>                                                          */ DEADTRANS( 0x00A0	,0xE554	,0x222A	,0x0000	), // ' ' ➔ "∪" UNION
/*<!M><U>                                                          */ DEADTRANS( 0x00A0	,0xE553	,0x22C3	,0x0000	), // ' ' ➔ "⋃" N-ARY UNION
/*<!M><u>                                                          */ DEADTRANS( L' '	,0xE554	,0x222A	,0x0000	), // ' ' ➔ "∪" UNION
/*<!M><U>                                                          */ DEADTRANS( L' '	,0xE553	,0x22C3	,0x0000	), // ' ' ➔ "⋃" N-ARY UNION
/*<!M><V>                                                          */ DEADTRANS( L'\\'	,0xE55A	,0x22C0	,0x0000	), // '\' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><v><%backslash><%parenleft>                                  */ DEADTRANS( L')'	,0xE55B	,0x22CF	,0x0000	), // ')' ➔ "⋏" CURLY LOGICAL AND
/*<!M><v><%backslash><%parenright>                                 */ DEADTRANS( L'('	,0xE55C	,0x22CF	,0x0000	), // '(' ➔ "⋏" CURLY LOGICAL AND
/*<!M><v>                                                          */ DEADTRANS( L'|'	,0xE55D	,0x2A5B	,0x0000	), // '|' ➔ "⩛" LOGICAL OR WITH MIDDLE STEM
/*<!M><V>                                                          */ DEADTRANS( L'|'	,0xE55A	,0x2A5B	,0x0000	), // '|' ➔ "⩛" LOGICAL OR WITH MIDDLE STEM
/*<!M><v>                                                          */ DEADTRANS( L']'	,0xE55D	,0x27CF	,0x0000	), // ']' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><v>                                                          */ DEADTRANS( L'='	,0xE55D	,0x225A	,0x0000	), // '=' ➔ "≚" EQUIANGULAR TO
/*<!M><v>                                                          */ DEADTRANS( L'-'	,0xE55D	,0x2A5D	,0x0000	), // '-' ➔ "⩝" LOGICAL OR WITH HORIZONTAL DASH
/*<!M><V>                                                          */ DEADTRANS( L'-'	,0xE55A	,0x2A5D	,0x0000	), // '-' ➔ "⩝" LOGICAL OR WITH HORIZONTAL DASH
/*<!M><v><%parenleft>                                              */ DEADTRANS( L')'	,0xE55E	,0x22CE	,0x0000	), // ')' ➔ "⋎" CURLY LOGICAL OR
/*<!M><v><%parenright>                                             */ DEADTRANS( L'('	,0xE55F	,0x22CE	,0x0000	), // '(' ➔ "⋎" CURLY LOGICAL OR
/*<!M><v><%percent>                                                */ DEADTRANS( L'|'	,0xE560	,0x2A5A	,0x0000	), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><V><%percent>                                                */ DEADTRANS( L'|'	,0xE561	,0x2A5A	,0x0000	), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><v><%percent>                                                */ DEADTRANS( L']'	,0xE560	,0x27CE	,0x0000	), // ']' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><v><%percent>                                                */ DEADTRANS( L'-'	,0xE560	,0x2A5C	,0x0000	), // '-' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><V><%percent>                                                */ DEADTRANS( L'-'	,0xE561	,0x2A5C	,0x0000	), // '-' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><v><%percent>                                                */ DEADTRANS( L'.'	,0xE560	,0x27D1	,0x0000	), // '.' ➔ "⟑" AND WITH DOT
/*<!M><v><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xE562	,0x2A60	,0x0000	), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><V><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xE563	,0x2A60	,0x0000	), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><v><%percent><%underscore>                                   */ DEADTRANS( 0x00A0	,0xE562	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><V><%percent><%underscore>                                   */ DEADTRANS( 0x00A0	,0xE563	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><v><%percent><%underscore>                                   */ DEADTRANS( L' '	,0xE562	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><V><%percent><%underscore>                                   */ DEADTRANS( L' '	,0xE563	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><v><%percent>                                                */ DEADTRANS( L'v'	,0xE560	,0x2A59	,0x0000	), // 'v' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><V><%percent>                                                */ DEADTRANS( L'V'	,0xE561	,0x2A59	,0x0000	), // 'V' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v><%percent>                                                */ DEADTRANS( 0x00A0	,0xE560	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><v><%percent>                                                */ DEADTRANS( L' '	,0xE560	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><v>                                                          */ DEADTRANS( L'.'	,0xE55D	,0x27C7	,0x0000	), // '.' ➔ "⟇" OR WITH DOT INSIDE
/*<!M><V>                                                          */ DEADTRANS( L'/'	,0xE55A	,0x2123	,0x0000	), // '/' ➔ "℣" VERSICLE
/*<!M><v>                                                          */ DEADTRANS( L'/'	,0xE55D	,0x2123	,0x0000	), // '/' ➔ "℣" VERSICLE
/*<!M><v><%underscore>                                             */ DEADTRANS( L','	,0xE564	,0x2A61	,0x0000	), // ',' ➔ "⩡" SMALL VEE WITH UNDERBAR
/*<!M><v><%underscore>                                             */ DEADTRANS( L'_'	,0xE564	,0x2A63	,0x0000	), // '_' ➔ "⩣" LOGICAL OR WITH DOUBLE UNDERBAR
/*<!M><v><%underscore>                                             */ DEADTRANS( 0x00A0	,0xE564	,0x22BB	,0x0000	), // ' ' ➔ "⊻" XOR
/*<!M><v><%underscore>                                             */ DEADTRANS( L' '	,0xE564	,0x22BB	,0x0000	), // ' ' ➔ "⊻" XOR
/*<!M><v>                                                          */ DEADTRANS( L'2'	,0xE55D	,0x221A	,0x0000	), // '2' ➔ "√" SQUARE ROOT
/*<!M><v>                                                          */ DEADTRANS( L'3'	,0xE55D	,0x221B	,0x0000	), // '3' ➔ "∛" CUBE ROOT
/*<!M><v>                                                          */ DEADTRANS( L'4'	,0xE55D	,0x221C	,0x0000	), // '4' ➔ "∜" FOURTH ROOT
/*<!M><v>                                                          */ DEADTRANS( L'a'	,0xE55D	,0x2A59	,0x0000	), // 'a' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v>                                                          */ DEADTRANS( L'A'	,0xE55D	,0x2A59	,0x0000	), // 'A' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><V>                                                          */ DEADTRANS( L'A'	,0xE55A	,0x2A59	,0x0000	), // 'A' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v><e><r>                                                    */ DEADTRANS( L's'	,0xE565	,0x2652	,0x0000	), // 's' ➔ "♒" AQUARIUS emoji
/*<!M><V><E><R>                                                    */ DEADTRANS( L'S'	,0xE566	,0x2652	,0x0000	), // 'S' ➔ "♒" AQUARIUS emoji
/*<!M><v><i><e>                                                    */ DEADTRANS( L'r'	,0xE567	,0x264D	,0x0000	), // 'r' ➔ "♍" VIRGO emoji
/*<!M><V><I><E>                                                    */ DEADTRANS( L'R'	,0xE568	,0x264D	,0x0000	), // 'R' ➔ "♍" VIRGO emoji
/*<!M><v><i><r>                                                    */ DEADTRANS( L'g'	,0xE569	,0x264D	,0x0000	), // 'g' ➔ "♍" VIRGO emoji
/*<!M><V><I><R>                                                    */ DEADTRANS( L'G'	,0xE56A	,0x264D	,0x0000	), // 'G' ➔ "♍" VIRGO emoji
/*<!M><v><n>                                                       */ DEADTRANS( L'd'	,0xE56B	,0x20AB	,0x0000	), // 'd' ➔ "₫" DONG SIGN, Dong VIET NAM
/*<!M><V><N>                                                       */ DEADTRANS( L'D'	,0xE56C	,0x20AB	,0x0000	), // 'D' ➔ "₫" DONG SIGN, Dong VIET NAM
/*<!M><v>                                                          */ DEADTRANS( L'u'	,0xE55D	,0x2A45	,0x0000	), // 'u' ➔ "⩅" UNION WITH LOGICAL OR
/*<!M><v><v>                                                       */ DEADTRANS( L'='	,0xE56D	,0x2259	,0x0000	), // '=' ➔ "≙" ESTIMATES
/*<!M><V>                                                          */ DEADTRANS( L'Y'	,0xE55A	,0xA760	,0x0000	), // 'Y' ➔ "Ꝡ" LATIN CAPITAL LETTER VY
/*<!M><V>                                                          */ DEADTRANS( L'y'	,0xE55A	,0xA760	,0x0000	), // 'y' ➔ "Ꝡ" LATIN CAPITAL LETTER VY
/*<!M><v>                                                          */ DEADTRANS( L'y'	,0xE55D	,0xA761	,0x0000	), // 'y' ➔ "ꝡ" LATIN SMALL LETTER VY
/*<!M><v>                                                          */ DEADTRANS( 0x00A0	,0xE55D	,0x2228	,0x0000	), // ' ' ➔ "∨" LOGICAL OR
/*<!M><V>                                                          */ DEADTRANS( 0x00A0	,0xE55A	,0x22C1	,0x0000	), // ' ' ➔ "⋁" N-ARY LOGICAL OR
/*<!M><v>                                                          */ DEADTRANS( L' '	,0xE55D	,0x2228	,0x0000	), // ' ' ➔ "∨" LOGICAL OR
/*<!M><V>                                                          */ DEADTRANS( L' '	,0xE55A	,0x22C1	,0x0000	), // ' ' ➔ "⋁" N-ARY LOGICAL OR
/*<!M><w>                                                          */ DEADTRANS( L'['	,0xE56E	,0x29D8	,0x0000	), // '[' ➔ "⧘" LEFT WIGGLY FENCE
/*<!M><w>                                                          */ DEADTRANS( L']'	,0xE56E	,0x29D9	,0x0000	), // ']' ➔ "⧙" RIGHT WIGGLY FENCE
/*<!M><w>                                                          */ DEADTRANS( L'='	,0xE56E	,0x20A9	,0x0000	), // '=' ➔ "₩" WON SIGN
/*<!M><W>                                                          */ DEADTRANS( L'='	,0xE56F	,0x20A9	,0x0000	), // '=' ➔ "₩" WON SIGN
/*<!M><W>                                                          */ DEADTRANS( L'%'	,0xE56F	,0x2A07	,0x0000	), // '%' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><w>                                                          */ DEADTRANS( L'%'	,0xE56E	,0x2A55	,0x0000	), // '%' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><w>                                                          */ DEADTRANS( L'l'	,0xE56E	,0x2307	,0x0000	), // 'l' ➔ "⌇" WAVY LINE
/*<!M><W>                                                          */ DEADTRANS( L'L'	,0xE56F	,0x2307	,0x0000	), // 'L' ➔ "⌇" WAVY LINE
/*<!M><w>                                                          */ DEADTRANS( L'v'	,0xE56E	,0x2AFF	,0x0000	), // 'v' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><W>                                                          */ DEADTRANS( L'V'	,0xE56F	,0x2AFF	,0x0000	), // 'V' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><w><w>                                                       */ DEADTRANS( L'['	,0xE570	,0x29DA	,0x0000	), // '[' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><w><w>                                                       */ DEADTRANS( L']'	,0xE570	,0x29DB	,0x0000	), // ']' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><w>                                                          */ DEADTRANS( L'z'	,0xE56E	,0xDD2E	,0x0000	), // High surrogate: D83C; U+1F12E 'z' ➔ "🄮" CIRCLED WZ
/*<!M><W>                                                          */ DEADTRANS( L'Z'	,0xE56F	,0xDD2E	,0x0000	), // High surrogate: D83C; U+1F12E 'Z' ➔ "🄮" CIRCLED WZ
/*<!M><W>                                                          */ DEADTRANS( 0x00A0	,0xE56F	,0x2A08	,0x0000	), // ' ' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><w>                                                          */ DEADTRANS( 0x00A0	,0xE56E	,0x2A56	,0x0000	), // ' ' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><W>                                                          */ DEADTRANS( L' '	,0xE56F	,0x2A08	,0x0000	), // ' ' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><w>                                                          */ DEADTRANS( L' '	,0xE56E	,0x2A56	,0x0000	), // ' ' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><x>                                                          */ DEADTRANS( L':'	,0xE571	,0x22C7	,0x0000	), // ':' ➔ "⋇" DIVISION TIMES
/*<!M><X>                                                          */ DEADTRANS( L'#'	,0xE572	,0x29D7	,0x0000	), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><x>                                                          */ DEADTRANS( L'-'	,0xE571	,0x2947	,0x0000	), // '-' ➔ "⥇" RIGHTWARDS ARROW THROUGH X
/*<!M><x>                                                          */ DEADTRANS( L')'	,0xE571	,0x2A35	,0x0000	), // ')' ➔ "⨵" MULTIPLICATION SIGN IN RIGHT HALF CIRCLE
/*<!M><x>                                                          */ DEADTRANS( L'.'	,0xE571	,0x22C7	,0x0000	), // '.' ➔ "⋇" DIVISION TIMES
/*<!M><X>                                                          */ DEADTRANS( L'_'	,0xE572	,0x29D6	,0x0000	), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><x>                                                          */ DEADTRANS( L'_'	,0xE571	,0x2A31	,0x0000	), // '_' ➔ "⨱" MULTIPLICATION SIGN WITH UNDERBAR
/*<!M><X>                                                          */ DEADTRANS( L'o'	,0xE572	,0x00A4	,0x0000	), // 'o' ➔ "¤" CURRENCY SIGN
/*<!M><x>                                                          */ DEADTRANS( L'O'	,0xE571	,0x00A4	,0x0000	), // 'O' ➔ "¤" CURRENCY SIGN
/*<!M><x><o>                                                       */ DEADTRANS( L'r'	,0xE573	,0x22BB	,0x0000	), // 'r' ➔ "⊻" XOR
/*<!M><X><O>                                                       */ DEADTRANS( L'R'	,0xE574	,0x22BB	,0x0000	), // 'R' ➔ "⊻" XOR
/*<!M><X>                                                          */ DEADTRANS( L'R'	,0xE572	,0x2627	,0x0000	), // 'R' ➔ "☧" CHI RHO
/*<!M><x>                                                          */ DEADTRANS( L'R'	,0xE571	,0x2627	,0x0000	), // 'R' ➔ "☧" CHI RHO
/*<!M><X>                                                          */ DEADTRANS( L'r'	,0xE572	,0x2627	,0x0000	), // 'r' ➔ "☧" CHI RHO
/*<!M><x>                                                          */ DEADTRANS( L'r'	,0xE571	,0x2627	,0x0000	), // 'r' ➔ "☧" CHI RHO
/*<!M><x><t>                                                       */ DEADTRANS( L'l'	,0xE575	,0x232B	,0x0000	), // 'l' ➔ "⌫" ERASE TO THE LEFT
/*<!M><X><T>                                                       */ DEADTRANS( L'L'	,0xE576	,0x232B	,0x0000	), // 'L' ➔ "⌫" ERASE TO THE LEFT
/*<!M><x><t>                                                       */ DEADTRANS( L'r'	,0xE575	,0x2326	,0x0000	), // 'r' ➔ "⌦" ERASE TO THE RIGHT
/*<!M><X><T>                                                       */ DEADTRANS( L'R'	,0xE576	,0x2326	,0x0000	), // 'R' ➔ "⌦" ERASE TO THE RIGHT
/*<!M><x>                                                          */ DEADTRANS( 0x00A0	,0xE571	,0x00D7	,0x0000	), // ' ' ➔ "×" MULTIPLICATION SIGN
/*<!M><X>                                                          */ DEADTRANS( 0x00A0	,0xE572	,0x2A09	,0x0000	), // ' ' ➔ "⨉" N-ARY TIMES OPERATOR
/*<!M><x>                                                          */ DEADTRANS( L' '	,0xE571	,0x00D7	,0x0000	), // ' ' ➔ "×" MULTIPLICATION SIGN
/*<!M><X>                                                          */ DEADTRANS( L' '	,0xE572	,0x2A09	,0x0000	), // ' ' ➔ "⨉" N-ARY TIMES OPERATOR
/*<!M><Y>                                                          */ DEADTRANS( L'@'	,0xE577	,0x03D2	,0x0000	), // '@' ➔ "ϒ" GREEK UPSILON WITH HOOK SYMBOL
/*<!M><y>                                                          */ DEADTRANS( L'='	,0xE578	,0x00A5	,0x0000	), // '=' ➔ "¥" YEN SIGN
/*<!M><Y>                                                          */ DEADTRANS( L'='	,0xE577	,0x00A5	,0x0000	), // '=' ➔ "¥" YEN SIGN
/*<!M><Y>                                                          */ DEADTRANS( L'!'	,0xE577	,0x297E	,0x0000	), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><y>                                                          */ DEADTRANS( L'-'	,0xE578	,0x00A5	,0x0000	), // '-' ➔ "¥" YEN SIGN
/*<!M><Y>                                                          */ DEADTRANS( L'-'	,0xE577	,0x00A5	,0x0000	), // '-' ➔ "¥" YEN SIGN
/*<!M><Y>                                                          */ DEADTRANS( L'%'	,0xE577	,0x2144	,0x0000	), // '%' ➔ "⅄" TURNED SANS-SERIF CAPITAL Y
/*<!M><y><e>                                                       */ DEADTRANS( L'r'	,0xE579	,0xFDFC	,0x0000	), // 'r' ➔ "﷼" RIAL SIGN, Yemeni Rial YEMEN
/*<!M><Y><E>                                                       */ DEADTRANS( L'R'	,0xE57A	,0xFDFC	,0x0000	), // 'R' ➔ "﷼" RIAL SIGN, Yemeni Rial YEMEN
/*<!M><z>                                                          */ DEADTRANS( L'|'	,0xE57B	,0x2A65	,0x0000	), // '|' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><Z>                                                          */ DEADTRANS( L'|'	,0xE57C	,0x2A65	,0x0000	), // '|' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><z>                                                          */ DEADTRANS( L':'	,0xE57B	,0x2982	,0x0000	), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><Z>                                                          */ DEADTRANS( L':'	,0xE57C	,0x2982	,0x0000	), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><z>                                                          */ DEADTRANS( L'!'	,0xE57B	,0x2A21	,0x0000	), // '!' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z>                                                          */ DEADTRANS( L'!'	,0xE57C	,0x2A21	,0x0000	), // '!' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><z><%greater>                                                */ DEADTRANS( L'>'	,0xE57D	,0x2A20	,0x0000	), // '>' ➔ "⨠" Z NOTATION SCHEMA PIPING
/*<!M><Z><%greater>                                                */ DEADTRANS( L'>'	,0xE57E	,0x2A20	,0x0000	), // '>' ➔ "⨠" Z NOTATION SCHEMA PIPING
/*<!M><z><%greater>                                                */ DEADTRANS( L'-'	,0xE57D	,0x2A65	,0x0000	), // '-' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><Z><%greater>                                                */ DEADTRANS( L'-'	,0xE57E	,0x2A65	,0x0000	), // '-' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><z><%greater>                                                */ DEADTRANS( 0x00A0	,0xE57D	,0x298A	,0x0000	), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z><%greater>                                                */ DEADTRANS( 0x00A0	,0xE57E	,0x298A	,0x0000	), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><z><%greater>                                                */ DEADTRANS( L' '	,0xE57D	,0x298A	,0x0000	), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z><%greater>                                                */ DEADTRANS( L' '	,0xE57E	,0x298A	,0x0000	), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z>                                                          */ DEADTRANS( L'#'	,0xE57C	,0x2128	,0x0000	), // '#' ➔ "ℨ" BLACK-LETTER CAPITAL Z
/*<!M><z><%less>                                                   */ DEADTRANS( L'-'	,0xE57F	,0x2A64	,0x0000	), // '-' ➔ "⩤" Z NOTATION DOMAIN ANTIRESTRICTION
/*<!M><Z><%less>                                                   */ DEADTRANS( L'-'	,0xE580	,0x2A64	,0x0000	), // '-' ➔ "⩤" Z NOTATION DOMAIN ANTIRESTRICTION
/*<!M><z><%less>                                                   */ DEADTRANS( 0x00A0	,0xE57F	,0x2989	,0x0000	), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><Z><%less>                                                   */ DEADTRANS( 0x00A0	,0xE580	,0x2989	,0x0000	), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><z><%less>                                                   */ DEADTRANS( L' '	,0xE57F	,0x2989	,0x0000	), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><Z><%less>                                                   */ DEADTRANS( L' '	,0xE580	,0x2989	,0x0000	), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><z>                                                          */ DEADTRANS( L'('	,0xE57B	,0x2987	,0x0000	), // '(' ➔ "⦇" Z NOTATION LEFT IMAGE BRACKET
/*<!M><Z>                                                          */ DEADTRANS( L'('	,0xE57C	,0x2987	,0x0000	), // '(' ➔ "⦇" Z NOTATION LEFT IMAGE BRACKET
/*<!M><z>                                                          */ DEADTRANS( L')'	,0xE57B	,0x2988	,0x0000	), // ')' ➔ "⦈" Z NOTATION RIGHT IMAGE BRACKET
/*<!M><Z>                                                          */ DEADTRANS( L')'	,0xE57C	,0x2988	,0x0000	), // ')' ➔ "⦈" Z NOTATION RIGHT IMAGE BRACKET
/*<!M><z>                                                          */ DEADTRANS( L'.'	,0xE57B	,0x2981	,0x0000	), // '.' ➔ "⦁" Z NOTATION SPOT
/*<!M><Z>                                                          */ DEADTRANS( L'.'	,0xE57C	,0x2981	,0x0000	), // '.' ➔ "⦁" Z NOTATION SPOT
/*<!M><z>                                                          */ DEADTRANS( L';'	,0xE57B	,0x2A1F	,0x0000	), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><Z>                                                          */ DEADTRANS( L';'	,0xE57C	,0x2A1F	,0x0000	), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><z>                                                          */ DEADTRANS( 0x00A7	,0xE57B	,0x2A1F	,0x0000	), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><Z>                                                          */ DEADTRANS( 0x00A7	,0xE57C	,0x2A1F	,0x0000	), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><z>                                                          */ DEADTRANS( L'1'	,0xE57B	,0x2A21	,0x0000	), // '1' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z>                                                          */ DEADTRANS( L'1'	,0xE57C	,0x2A21	,0x0000	), // '1' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z>                                                          */ DEADTRANS( L'2'	,0xE57C	,0x01A7	,0x0000	), // '2' ➔ "Ƨ" LATIN CAPITAL LETTER TONE TWO
/*<!M><z>                                                          */ DEADTRANS( L'2'	,0xE57B	,0x01A8	,0x0000	), // '2' ➔ "ƨ" LATIN SMALL LETTER TONE TWO
/*<!M><Z>                                                          */ DEADTRANS( L'3'	,0xE57C	,0x0417	,0x0000	), // '3' ➔ "З" CYRILLIC CAPITAL LETTER ZE
/*<!M><z>                                                          */ DEADTRANS( L'3'	,0xE57B	,0x0437	,0x0000	), // '3' ➔ "з" CYRILLIC SMALL LETTER ZE
/*<!M><Z>                                                          */ DEADTRANS( L'4'	,0xE57C	,0x0427	,0x0000	), // '4' ➔ "Ч" CYRILLIC CAPITAL LETTER CHE
/*<!M><z>                                                          */ DEADTRANS( L'4'	,0xE57B	,0x0447	,0x0000	), // '4' ➔ "ч" CYRILLIC SMALL LETTER CHE
/*<!M><Z>                                                          */ DEADTRANS( L'5'	,0xE57C	,0x01BC	,0x0000	), // '5' ➔ "Ƽ" LATIN CAPITAL LETTER TONE FIVE
/*<!M><z>                                                          */ DEADTRANS( L'5'	,0xE57B	,0x01BD	,0x0000	), // '5' ➔ "ƽ" LATIN SMALL LETTER TONE FIVE
/*<!M><Z>                                                          */ DEADTRANS( L'6'	,0xE57C	,0x0184	,0x0000	), // '6' ➔ "Ƅ" LATIN CAPITAL LETTER TONE SIX
/*<!M><z>                                                          */ DEADTRANS( L'6'	,0xE57B	,0x0185	,0x0000	), // '6' ➔ "ƅ" LATIN SMALL LETTER TONE SIX
/*<!M><z>                                                          */ DEADTRANS( L'e'	,0xE57B	,0x22FF	,0x0000	), // 'e' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z>                                                          */ DEADTRANS( L'e'	,0xE57C	,0x22FF	,0x0000	), // 'e' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><z>                                                          */ DEADTRANS( L'E'	,0xE57B	,0x22FF	,0x0000	), // 'E' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z>                                                          */ DEADTRANS( L'E'	,0xE57C	,0x22FF	,0x0000	), // 'E' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z>                                                          */ DEADTRANS( L'H'	,0xE57C	,0x01B7	,0x0000	), // 'H' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><Z>                                                          */ DEADTRANS( L'h'	,0xE57C	,0x01B7	,0x0000	), // 'h' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><z>                                                          */ DEADTRANS( L'h'	,0xE57B	,0x0292	,0x0000	), // 'h' ➔ "ʒ" LATIN SMALL LETTER EZH
/*<!M><z>                                                          */ DEADTRANS( L'w'	,0xE57B	,0xDD2E	,0x0000	), // High surrogate: D83C; U+1F12E 'w' ➔ "🄮" CIRCLED WZ
/*<!M><Z>                                                          */ DEADTRANS( L'W'	,0xE57C	,0xDD2E	,0x0000	), // High surrogate: D83C; U+1F12E 'W' ➔ "🄮" CIRCLED WZ
/*<!M><Z>                                                          */ DEADTRANS( L'Z'	,0xE57C	,0x2124	,0x0000	), // 'Z' ➔ "ℤ" DOUBLE-STRUCK CAPITAL Z
/*<!M><z>                                                          */ DEADTRANS( L'z'	,0xE57B	,0x2125	,0x0000	), // 'z' ➔ "℥" OUNCE SIGN
/*<!M><Z>                                                          */ DEADTRANS( L'z'	,0xE57C	,0x2125	,0x0000	), // 'z' ➔ "℥" OUNCE SIGN
/*<!M><z>                                                          */ DEADTRANS( L'Z'	,0xE57B	,0x2125	,0x0000	), // 'Z' ➔ "℥" OUNCE SIGN
/*<!M><~nbspace><%ampersand>                                       */ DEADTRANS( L'|'	,0xE581	,0x20D3	,0x0000	), // '|' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><~nbspace><%ampersand>                                       */ DEADTRANS( L'<'	,0xE581	,0x20EE	,0x0000	), // '<' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><~nbspace><%ampersand>                                       */ DEADTRANS( L'-'	,0xE581	,0x20EF	,0x0000	), // '-' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><~nbspace><%apostrophe>                                      */ DEADTRANS( L'='	,0xE582	,0x2AED	,0x0000	), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~nbspace><%apostrophe>                                      */ DEADTRANS( L'-'	,0xE582	,0x2A3D	,0x0000	), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~nbspace><%apostrophe>                                      */ DEADTRANS( L'+'	,0xE582	,0x22B9	,0x0000	), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%aprightsinglequotemark>                          */ DEADTRANS( L'='	,0xE583	,0x2AED	,0x0000	), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~nbspace><%aprightsinglequotemark>                          */ DEADTRANS( L'-'	,0xE583	,0x2A3D	,0x0000	), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~nbspace><%aprightsinglequotemark>                          */ DEADTRANS( L'+'	,0xE583	,0x22B9	,0x0000	), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%asterisk>                                        */ DEADTRANS( L'='	,0xE584	,0x225B	,0x0000	), // '=' ➔ "≛" STAR EQUALS
/*<!M><~nbspace><%asterisk>                                        */ DEADTRANS( 0x00A0	,0xE584	,0x2217	,0x0000	), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~nbspace><%asterisk>                                        */ DEADTRANS( L' '	,0xE584	,0x2217	,0x0000	), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L'>'	,0xE585	,0x292D	,0x0000	), // '>' ➔ "⤭" SOUTH EAST ARROW CROSSING NORTH EAST ARROW
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L'-'	,0xE585	,0x29A3	,0x0000	), // '-' ➔ "⦣" REVERSED ANGLE
/*<!M><~nbspace><%backslash><%slash>                               */ DEADTRANS( L'|'	,0xE586	,0x2A1E	,0x0000	), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~nbspace><%backslash><%slash>                               */ DEADTRANS( L'#'	,0xE586	,0x25C0	,0x0000	), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~nbspace><%backslash><%slash>                               */ DEADTRANS( L'_'	,0xE586	,0x29CD	,0x0000	), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L'c'	,0xE585	,0x27C8	,0x0000	), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( 0x00A0	,0xE585	,0x2216	,0x0000	), // ' ' ➔ "∖" SET MINUS
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L' '	,0xE585	,0x2216	,0x0000	), // ' ' ➔ "∖" SET MINUS
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L'|'	,0xE587	,0x2A1D	,0x0000	), // '|' ➔ "⨝" JOIN
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( 0x00A0	,0xE587	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L' '	,0xE587	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%bar><%bar>                                 */ DEADTRANS( L'-'	,0xE588	,0x22AA	,0x0000	), // '-' ➔ "⊪" TRIPLE VERTICAL BAR RIGHT TURNSTILE
/*<!M><~nbspace><%bar><%bar><%bar>                                 */ DEADTRANS( 0x00A0	,0xE588	,0x2AF4	,0x0000	), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><%bar><%bar><%bar>                                 */ DEADTRANS( L' '	,0xE588	,0x2AF4	,0x0000	), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><%bar><%bar>                                       */ DEADTRANS( L'-'	,0xE589	,0x22A9	,0x0000	), // '-' ➔ "⊩" FORCES
/*<!M><~nbspace><%bar><%bar>                                       */ DEADTRANS( 0x00A0	,0xE589	,0x2225	,0x0000	), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~nbspace><%bar><%bar>                                       */ DEADTRANS( L' '	,0xE589	,0x2225	,0x0000	), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'='	,0xE58A	,0x29E7	,0x0000	), // '=' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'#'	,0xE58A	,0x25B6	,0x0000	), // '#' ➔ "▶" BLACK RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'-'	,0xE58A	,0x27CA	,0x0000	), // '-' ➔ "⟊" VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L')'	,0xE58A	,0x2ADD	,0x0000	), // ')' ➔ "⫝" NONFORKING
/*<!M><~nbspace><%bar><%slash><%backslash>                         */ DEADTRANS( L'|'	,0xE58B	,0x2A1D	,0x0000	), // '|' ➔ "⨝" JOIN
/*<!M><~nbspace><%bar><%slash><%backslash>                         */ DEADTRANS( 0x00A0	,0xE58B	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%slash><%backslash>                         */ DEADTRANS( L' '	,0xE58B	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%slash>                                     */ DEADTRANS( 0x00A0	,0xE58C	,0x2A57	,0x0000	), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~nbspace><%bar><%slash>                                     */ DEADTRANS( L' '	,0xE58C	,0x2A57	,0x0000	), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L','	,0xE58D	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( 0x00A0	,0xE58D	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L' '	,0xE58D	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L','	,0xE58E	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( 0x00A0	,0xE58E	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L' '	,0xE58E	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'o'	,0xE58A	,0x2AF0	,0x0000	), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><~nbspace><%bar><p>                                          */ DEADTRANS( L','	,0xE58F	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><p>                                          */ DEADTRANS( 0x00A0	,0xE58F	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><p>                                          */ DEADTRANS( L' '	,0xE58F	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( 0x00A0	,0xE58A	,0x2223	,0x0000	), // ' ' ➔ "∣" DIVIDES
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L' '	,0xE58A	,0x2223	,0x0000	), // ' ' ➔ "∣" DIVIDES
/*<!M><~nbspace>                                                   */ DEADTRANS( L'{'	,0xE590	,0x2983	,0x0000	), // '{' ➔ "⦃" LEFT WHITE CURLY BRACKET
/*<!M><~nbspace>                                                   */ DEADTRANS( L'}'	,0xE590	,0x2984	,0x0000	), // '}' ➔ "⦄" RIGHT WHITE CURLY BRACKET
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'['	,0xE591	,0x27E6	,0x0000	), // '[' ➔ "⟦" MATHEMATICAL LEFT WHITE SQUARE BRACKET
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L']'	,0xE591	,0x25FB	,0x0000	), // ']' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'#'	,0xE591	,0x25FC	,0x0000	), // '#' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'-'	,0xE591	,0x2ACD	,0x0000	), // '-' ➔ "⫍" SQUARE LEFT OPEN BOX OPERATOR
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'_'	,0xE591	,0x298B	,0x0000	), // '_' ➔ "⦋" LEFT SQUARE BRACKET WITH UNDERBAR
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'a'	,0xE591	,0x27CE	,0x0000	), // 'a' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'o'	,0xE591	,0x29C7	,0x0000	), // 'o' ➔ "⧇" SQUARED SMALL CIRCLE
/*<!M><~nbspace><%bracketright>                                    */ DEADTRANS( L'['	,0xE592	,0x25FB	,0x0000	), // '[' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~nbspace><%bracketright>                                    */ DEADTRANS( L']'	,0xE592	,0x27E7	,0x0000	), // ']' ➔ "⟧" MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><~nbspace><%bracketright>                                    */ DEADTRANS( L'_'	,0xE592	,0x298C	,0x0000	), // '_' ➔ "⦌" RIGHT SQUARE BRACKET WITH UNDERBAR
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'^'	,0xE593	,0x22C4	,0x0000	), // '^' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'='	,0xE593	,0x2259	,0x0000	), // '=' ➔ "≙" ESTIMATES
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'_'	,0xE593	,0x25B5	,0x0000	), // '_' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'o'	,0xE593	,0x2A36	,0x0000	), // 'o' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'O'	,0xE593	,0x2A36	,0x0000	), // 'O' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( 0x00A0	,0xE593	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L' '	,0xE593	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( L':'	,0xE594	,0x2237	,0x0000	), // ':' ➔ "∷" PROPORTION
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( L'~'	,0xE594	,0x223B	,0x0000	), // '~' ➔ "∻" HOMOTHETIC
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( 0x00A0	,0xE594	,0x2236	,0x0000	), // ' ' ➔ "∶" RATIO
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( L' '	,0xE594	,0x2236	,0x0000	), // ' ' ➔ "∶" RATIO
/*<!M><~nbspace><%equal><%bar>                                     */ DEADTRANS( L'|'	,0xE595	,0x22D5	,0x0000	), // '|' ➔ "⋕" EQUAL AND PARALLEL TO
/*<!M><~nbspace><%equal><%bar>                                     */ DEADTRANS( 0x00A0	,0xE595	,0x29E7	,0x0000	), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%equal><%bar>                                     */ DEADTRANS( L' '	,0xE595	,0x29E7	,0x0000	), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%equal>                                           */ DEADTRANS( L'='	,0xE596	,0x2A75	,0x0000	), // '=' ➔ "⩵" TWO CONSECUTIVE EQUALS SIGNS
/*<!M><~nbspace><%equal>                                           */ DEADTRANS( L'>'	,0xE596	,0x2A9A	,0x0000	), // '>' ➔ "⪚" DOUBLE-LINE EQUAL TO OR GREATER-THAN
/*<!M><~nbspace><%equal><%minus>                                   */ DEADTRANS( L'>'	,0xE597	,0x2971	,0x0000	), // '>' ➔ "⥱" EQUALS SIGN ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%equal><%minus>                                   */ DEADTRANS( L'/'	,0xE597	,0x29E5	,0x0000	), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'!'	,0xE598	,0x00A1	,0x0000	), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'j'	,0xE598	,0x297F	,0x0000	), // 'j' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'J'	,0xE598	,0x297F	,0x0000	), // 'J' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'Y'	,0xE598	,0x297F	,0x0000	), // 'Y' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%greater><%greater>                               */ DEADTRANS( L'>'	,0xE599	,0x22D9	,0x0000	), // '>' ➔ "⋙" VERY MUCH GREATER-THAN
/*<!M><~nbspace><%greater><%greater>                               */ DEADTRANS( 0x00A0	,0xE599	,0x226B	,0x0000	), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~nbspace><%greater><%greater>                               */ DEADTRANS( L' '	,0xE599	,0x226B	,0x0000	), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L'<'	,0xE59A	,0x2AA4	,0x0000	), // '<' ➔ "⪤" GREATER-THAN OVERLAPPING LESS-THAN
/*<!M><~nbspace><%greater><%minus>                                 */ DEADTRANS( L'>'	,0xE59B	,0x2978	,0x0000	), // '>' ➔ "⥸" GREATER-THAN ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%greater><%minus>                                 */ DEADTRANS( 0x00A0	,0xE59B	,0x2AAB	,0x0000	), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~nbspace><%greater><%minus>                                 */ DEADTRANS( L' '	,0xE59B	,0x2AAB	,0x0000	), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L')'	,0xE59A	,0x2994	,0x0000	), // ')' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L'o'	,0xE59A	,0x2941	,0x0000	), // 'o' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( 0x00A0	,0xE59A	,0x200E	,0x0000	), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L' '	,0xE59A	,0x200E	,0x0000	), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~nbspace><%hash>                                            */ DEADTRANS( L'%'	,0xE59C	,0x2A33	,0x0000	), // '%' ➔ "⨳" SMASH PRODUCT
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'\\'	,0xE59D	,0x2932	,0x0000	), // '\' ➔ "⤲" NORTH WEST ARROW CROSSING NORTH EAST ARROW
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( L'>'	,0xE59E	,0x2A8B	,0x0000	), // '>' ➔ "⪋" LESS-THAN ABOVE DOUBLE-LINE EQUAL ABOVE GREATER-THAN
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( L'/'	,0xE59E	,0x2268	,0x0000	), // '/' ➔ "≨" LESS-THAN BUT NOT EQUAL TO
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( 0x00A0	,0xE59E	,0x2266	,0x0000	), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( L' '	,0xE59E	,0x2266	,0x0000	), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'!'	,0xE59D	,0x29BD	,0x0000	), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'>'	,0xE59D	,0x22C4	,0x0000	), // '>' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~nbspace><%less><%less>                                     */ DEADTRANS( L'<'	,0xE59F	,0x22D8	,0x0000	), // '<' ➔ "⋘" VERY MUCH LESS-THAN
/*<!M><~nbspace><%less><%less><%minus>                             */ DEADTRANS( L'|'	,0xE5A0	,0x2B36	,0x0000	), // '|' ➔ "⬶" LEFTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><~nbspace><%less><%less><%minus>                             */ DEADTRANS( 0x00A0	,0xE5A0	,0x2976	,0x0000	), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~nbspace><%less><%less><%minus>                             */ DEADTRANS( L' '	,0xE5A0	,0x2976	,0x0000	), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~nbspace><%less><%less>                                     */ DEADTRANS( 0x00A0	,0xE59F	,0x226A	,0x0000	), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~nbspace><%less><%less>                                     */ DEADTRANS( L' '	,0xE59F	,0x226A	,0x0000	), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'|'	,0xE5A1	,0x21F7	,0x0000	), // '|' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'<'	,0xE5A1	,0x2977	,0x0000	), // '<' ➔ "⥷" LEFTWARDS ARROW THROUGH LESS-THAN
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'-'	,0xE5A1	,0x27F7	,0x0000	), // '-' ➔ "⟷" LONG LEFT RIGHT ARROW
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'~'	,0xE5A1	,0x2973	,0x0000	), // '~' ➔ "⥳" LEFTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( 0x00A0	,0xE5A1	,0x2AAA	,0x0000	), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L' '	,0xE5A1	,0x2AAA	,0x0000	), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'('	,0xE59D	,0x2993	,0x0000	), // '(' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L')'	,0xE59D	,0x2AA6	,0x0000	), // ')' ➔ "⪦" LESS-THAN CLOSED BY CURVE
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'/'	,0xE59D	,0x226E	,0x0000	), // '/' ➔ "≮" NOT LESS-THAN
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( L'>'	,0xE5A2	,0x21AD	,0x0000	), // '>' ➔ "↭" LEFT RIGHT WAVE ARROW
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( L'~'	,0xE5A2	,0x21DC	,0x0000	), // '~' ➔ "⇜" LEFTWARDS SQUIGGLE ARROW
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( 0x00A0	,0xE5A2	,0x2272	,0x0000	), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( L' '	,0xE5A2	,0x2272	,0x0000	), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'3'	,0xE59D	,0x2660	,0x0000	), // '3' ➔ "♠" BLACK SPADE SUIT
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'C'	,0xE59D	,0x293E	,0x0000	), // 'C' ➔ "⤾" LOWER RIGHT SEMICIRCULAR CLOCKWISE ARROW
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'n'	,0xE59D	,0x21B6	,0x0000	), // 'n' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'o'	,0xE59D	,0x2940	,0x0000	), // 'o' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~nbspace><%less>                                            */ DEADTRANS( 0x00A0	,0xE59D	,0x200F	,0x0000	), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L' '	,0xE59D	,0x200F	,0x0000	), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~nbspace><%minus><%apostrophe>                              */ DEADTRANS( L'-'	,0xE5A3	,0x2ADF	,0x0000	), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~nbspace><%minus><%apostrophe>                              */ DEADTRANS( 0x00A0	,0xE5A3	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%apostrophe>                              */ DEADTRANS( L' '	,0xE5A3	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%aprightsinglequotemark>                  */ DEADTRANS( L'-'	,0xE5A4	,0x2ADF	,0x0000	), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~nbspace><%minus><%aprightsinglequotemark>                  */ DEADTRANS( 0x00A0	,0xE5A4	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%aprightsinglequotemark>                  */ DEADTRANS( L' '	,0xE5A4	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'|'	,0xE5A5	,0x21F8	,0x0000	), // '|' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'['	,0xE5A5	,0x27E4	,0x0000	), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~nbspace><%minus><%bracketright>                            */ DEADTRANS( L'['	,0xE5A6	,0x27E4	,0x0000	), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~nbspace><%minus><%bracketright>                            */ DEADTRANS( 0x00A0	,0xE5A6	,0x2ACE	,0x0000	), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~nbspace><%minus><%bracketright>                            */ DEADTRANS( L' '	,0xE5A6	,0x2ACE	,0x0000	), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'/'	,0xE5A5	,0x29A2	,0x0000	), // '/' ➔ "⦢" TURNED ANGLE
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'e'	,0xE5A5	,0x22F2	,0x0000	), // 'e' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'j'	,0xE5A5	,0x297D	,0x0000	), // 'j' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'J'	,0xE5A5	,0x297D	,0x0000	), // 'J' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'O'	,0xE5A5	,0x29B1	,0x0000	), // 'O' ➔ "⦱" EMPTY SET WITH OVERBAR
/*<!M><~nbspace><%minus><o>                                        */ DEADTRANS( L'-'	,0xE5A7	,0x2256	,0x0000	), // '-' ➔ "≖" RING IN EQUAL TO
/*<!M><~nbspace><%minus><o>                                        */ DEADTRANS( 0x00A0	,0xE5A7	,0x22B8	,0x0000	), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~nbspace><%minus><o>                                        */ DEADTRANS( L' '	,0xE5A7	,0x22B8	,0x0000	), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'S'	,0xE5A5	,0x2A1B	,0x0000	), // 'S' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus><s>                                        */ DEADTRANS( L'/'	,0xE5A8	,0x299E	,0x0000	), // '/' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><~nbspace><%minus><s>                                        */ DEADTRANS( 0x00A0	,0xE5A8	,0x2A1B	,0x0000	), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus><s>                                        */ DEADTRANS( L' '	,0xE5A8	,0x2A1B	,0x0000	), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'Y'	,0xE5A5	,0x297D	,0x0000	), // 'Y' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'['	,0xE5A9	,0x27EE	,0x0000	), // '[' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L']'	,0xE5A9	,0x27EE	,0x0000	), // ']' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'='	,0xE5A9	,0x224E	,0x0000	), // '=' ➔ "≎" GEOMETRICALLY EQUIVALENT TO
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'>'	,0xE5A9	,0x2AA7	,0x0000	), // '>' ➔ "⪧" GREATER-THAN CLOSED BY CURVE
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'<'	,0xE5A9	,0x2993	,0x0000	), // '<' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'('	,0xE5A9	,0x2985	,0x0000	), // '(' ➔ "⦅" LEFT WHITE PARENTHESIS
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'8'	,0xE5A9	,0x29DD	,0x0000	), // '8' ➔ "⧝" TIE OVER INFINITY
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L'['	,0xE5AA	,0x27EF	,0x0000	), // '[' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L']'	,0xE5AA	,0x27EF	,0x0000	), // ']' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L'>'	,0xE5AA	,0x2994	,0x0000	), // '>' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L')'	,0xE5AA	,0x2986	,0x0000	), // ')' ➔ "⦆" RIGHT WHITE PARENTHESIS
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'a'	,0xE5AB	,0x2A51	,0x0000	), // 'a' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'A'	,0xE5AB	,0x2A51	,0x0000	), // 'A' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'b'	,0xE5AB	,0x2AC4	,0x0000	), // 'b' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c>                                       */ DEADTRANS( L'\\'	,0xE5AC	,0x2AC4	,0x0000	), // '\' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c>                                       */ DEADTRANS( L'_'	,0xE5AC	,0x2AC3	,0x0000	), // '_' ➔ "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c>                                       */ DEADTRANS( L'c'	,0xE5AC	,0x2AC4	,0x0000	), // 'c' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'e'	,0xE5AB	,0x22F5	,0x0000	), // 'e' ➔ "⋵" ELEMENT OF WITH DOT ABOVE
/*<!M><~nbspace><%period><v>                                       */ DEADTRANS( L'v'	,0xE5AD	,0x2A51	,0x0000	), // 'v' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><V>                                       */ DEADTRANS( L'V'	,0xE5AE	,0x2A51	,0x0000	), // 'V' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><v>                                       */ DEADTRANS( 0x00A0	,0xE5AD	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><V>                                       */ DEADTRANS( 0x00A0	,0xE5AE	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><v>                                       */ DEADTRANS( L' '	,0xE5AD	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><V>                                       */ DEADTRANS( L' '	,0xE5AE	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'x'	,0xE5AB	,0x2A30	,0x0000	), // 'x' ➔ "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><~nbspace><%period>                                          */ DEADTRANS( 0x00A0	,0xE5AB	,0x22C5	,0x0000	), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L' '	,0xE5AB	,0x22C5	,0x0000	), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'\''	,0xE5AF	,0x22B9	,0x0000	), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( 0x2019	,0xE5AF	,0x22B9	,0x0000	), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'^'	,0xE5AF	,0x2A28	,0x0000	), // '^' ➔ "⨨" PLUS SIGN WITH BLACK TRIANGLE
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'+'	,0xE5AF	,0x29FA	,0x0000	), // '+' ➔ "⧺" DOUBLE PLUS
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'2'	,0xE5AF	,0x2A27	,0x0000	), // '2' ➔ "⨧" PLUS SIGN WITH SUBSCRIPT TWO
/*<!M><~nbspace>                                                   */ DEADTRANS( L';'	,0xE590	,0x2A1F	,0x0000	), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~nbspace>                                                   */ DEADTRANS( 0x00A7	,0xE590	,0x2A1F	,0x0000	), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~nbspace><%slash><%backslash>                               */ DEADTRANS( L'|'	,0xE5B0	,0x2A1E	,0x0000	), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~nbspace><%slash><%backslash>                               */ DEADTRANS( L'#'	,0xE5B0	,0x25C0	,0x0000	), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~nbspace><%slash><%backslash>                               */ DEADTRANS( L'_'	,0xE5B0	,0x29CD	,0x0000	), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~nbspace><%slash><%hash><%underscore>                       */ DEADTRANS( L'\\'	,0xE5B1	,0x25B4	,0x0000	), // '\' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%slash><%slash>                                   */ DEADTRANS( L'/'	,0xE5B2	,0x2AFB	,0x0000	), // '/' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><~nbspace><%slash><%slash>                                   */ DEADTRANS( 0x00A0	,0xE5B2	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~nbspace><%slash><%slash>                                   */ DEADTRANS( L' '	,0xE5B2	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~nbspace><%slash><%underscore>                              */ DEADTRANS( L'\\'	,0xE5B3	,0x25B5	,0x0000	), // '\' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%slash>                                           */ DEADTRANS( L'c'	,0xE5B4	,0x27C8	,0x0000	), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~nbspace><%slash>                                           */ DEADTRANS( 0x00A0	,0xE5B4	,0x2215	,0x0000	), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~nbspace><%slash>                                           */ DEADTRANS( L' '	,0xE5B4	,0x2215	,0x0000	), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L':'	,0xE5B5	,0x223B	,0x0000	), // ':' ➔ "∻" HOMOTHETIC
/*<!M><~nbspace><%tilde><%equal><%slash>                           */ DEADTRANS( L'/'	,0xE5B6	,0x29E4	,0x0000	), // '/' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><~nbspace><%tilde><%equal><%slash>                           */ DEADTRANS( 0x00A0	,0xE5B6	,0x2246	,0x0000	), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~nbspace><%tilde><%equal><%slash>                           */ DEADTRANS( L' '	,0xE5B6	,0x2246	,0x0000	), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~nbspace><%tilde><%equal>                                   */ DEADTRANS( 0x00A0	,0xE5B7	,0x2245	,0x0000	), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~nbspace><%tilde><%equal>                                   */ DEADTRANS( L' '	,0xE5B7	,0x2245	,0x0000	), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L'>'	,0xE5B5	,0x2A9E	,0x0000	), // '>' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L'-'	,0xE5B5	,0x2972	,0x0000	), // '-' ➔ "⥲" TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L'%'	,0xE5B5	,0x2240	,0x0000	), // '%' ➔ "≀" WREATH PRODUCT
/*<!M><~nbspace><%tilde><%slash>                                   */ DEADTRANS( 0x00A0	,0xE5B8	,0x2241	,0x0000	), // ' ' ➔ "≁" NOT TILDE
/*<!M><~nbspace><%tilde><%slash>                                   */ DEADTRANS( L' '	,0xE5B8	,0x2241	,0x0000	), // ' ' ➔ "≁" NOT TILDE
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( L'='	,0xE5B9	,0x2A70	,0x0000	), // '=' ➔ "⩰" APPROXIMATELY EQUAL OR EQUAL TO
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xE5B9	,0x224B	,0x0000	), // '~' ➔ "≋" TRIPLE TILDE
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( 0x00A0	,0xE5B9	,0x2248	,0x0000	), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( L' '	,0xE5B9	,0x2248	,0x0000	), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( 0x00A0	,0xE5B5	,0x223C	,0x0000	), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L' '	,0xE5B5	,0x223C	,0x0000	), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'\\'	,0xE5BA	,0x25BF	,0x0000	), // '\' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'#'	,0xE5BA	,0x25BE	,0x0000	), // '#' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore><%minus>                              */ DEADTRANS( L'\''	,0xE5BB	,0x296D	,0x0000	), // ''' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~nbspace><%underscore><%minus>                              */ DEADTRANS( 0x2019	,0xE5BB	,0x296D	,0x0000	), // '’' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~nbspace><%underscore><%minus>                              */ DEADTRANS( L'/'	,0xE5BB	,0x29A4	,0x0000	), // '/' ➔ "⦤" ANGLE WITH UNDERBAR
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'/'	,0xE5BA	,0x25BF	,0x0000	), // '/' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L'%'	,0xE5BC	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L'%'	,0xE5BD	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( 0x00A0	,0xE5BC	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( 0x00A0	,0xE5BD	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L' '	,0xE5BC	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L' '	,0xE5BD	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'a'	,0xE5BA	,0x22BC	,0x0000	), // 'a' ➔ "⊼" NAND
/*<!M><~nbspace><%underscore><e><%backslash>                       */ DEADTRANS( L','	,0xE5BE	,0x22FE	,0x0000	), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e><%backslash>                       */ DEADTRANS( 0x00A0	,0xE5BE	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e><%backslash>                       */ DEADTRANS( L' '	,0xE5BE	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e>                                   */ DEADTRANS( L','	,0xE5BF	,0x22F7	,0x0000	), // ',' ➔ "⋷" SMALL ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore><e>                                   */ DEADTRANS( 0x00A0	,0xE5BF	,0x22F6	,0x0000	), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore><e>                                   */ DEADTRANS( L' '	,0xE5BF	,0x22F6	,0x0000	), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'n'	,0xE5BA	,0x2A43	,0x0000	), // 'n' ➔ "⩃" INTERSECTION WITH OVERBAR
/*<!M><~nbspace><%underscore><p>                                   */ DEADTRANS( L','	,0xE5C0	,0x22FE	,0x0000	), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><p>                                   */ DEADTRANS( 0x00A0	,0xE5C0	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><p>                                   */ DEADTRANS( L' '	,0xE5C0	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><u>                                   */ DEADTRANS( L'#'	,0xE5C1	,0x2A50	,0x0000	), // '#' ➔ "⩐" CLOSED UNION WITH SERIFS AND SMASH PRODUCT
/*<!M><~nbspace><%underscore><u>                                   */ DEADTRANS( 0x00A0	,0xE5C1	,0x2A42	,0x0000	), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~nbspace><%underscore><u>                                   */ DEADTRANS( L' '	,0xE5C1	,0x2A42	,0x0000	), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~nbspace><%underscore><v>                                   */ DEADTRANS( L'v'	,0xE5C2	,0x22BC	,0x0000	), // 'v' ➔ "⊼" NAND
/*<!M><~nbspace><%underscore><v>                                   */ DEADTRANS( 0x00A0	,0xE5C2	,0x22BD	,0x0000	), // ' ' ➔ "⊽" NOR
/*<!M><~nbspace><%underscore><v>                                   */ DEADTRANS( L' '	,0xE5C2	,0x22BD	,0x0000	), // ' ' ➔ "⊽" NOR
/*<!M><~nbspace><%underscore><X>                                   */ DEADTRANS( L'#'	,0xE5C3	,0x29D7	,0x0000	), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><~nbspace><%underscore><X>                                   */ DEADTRANS( L'_'	,0xE5C3	,0x29D6	,0x0000	), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><~nbspace><2>                                                */ DEADTRANS( L'<'	,0xE5C4	,0x2AA3	,0x0000	), // '<' ➔ "⪣" DOUBLE NESTED LESS-THAN WITH UNDERBAR
/*<!M><~nbspace><2>                                                */ DEADTRANS( L'-'	,0xE5C4	,0x21C9	,0x0000	), // '-' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><~nbspace><3>                                                */ DEADTRANS( L'|'	,0xE5C5	,0x2AF4	,0x0000	), // '|' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><3>                                                */ DEADTRANS( L'-'	,0xE5C5	,0x21F6	,0x0000	), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><~nbspace>                                                   */ DEADTRANS( L'8'	,0xE590	,0x221D	,0x0000	), // '8' ➔ "∝" PROPORTIONAL TO
/*<!M><~nbspace><A>                                                */ DEADTRANS( L'-'	,0xE5C6	,0x2A3A	,0x0000	), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><~nbspace><A><%underscore>                                   */ DEADTRANS( L'_'	,0xE5C7	,0x2A60	,0x0000	), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><~nbspace><A><%underscore>                                   */ DEADTRANS( 0x00A0	,0xE5C7	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~nbspace><A><%underscore>                                   */ DEADTRANS( L' '	,0xE5C7	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~nbspace><A>                                                */ DEADTRANS( L'A'	,0xE5C6	,0x2A07	,0x0000	), // 'A' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><~nbspace><a>                                                */ DEADTRANS( L'a'	,0xE5C8	,0x2A55	,0x0000	), // 'a' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><~nbspace><A>                                                */ DEADTRANS( L'V'	,0xE5C6	,0x25CA	,0x0000	), // 'V' ➔ "◊" LOZENGE
/*<!M><~nbspace><a>                                                */ DEADTRANS( L'v'	,0xE5C8	,0x25CA	,0x0000	), // 'v' ➔ "◊" LOZENGE
/*<!M><~nbspace><A>                                                */ DEADTRANS( 0x00A0	,0xE5C6	,0x22C0	,0x0000	), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~nbspace><A>                                                */ DEADTRANS( L' '	,0xE5C6	,0x22C0	,0x0000	), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~nbspace><b>                                                */ DEADTRANS( L'/'	,0xE5C9	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><b>                                                */ DEADTRANS( L'c'	,0xE5C9	,0x2AD7	,0x0000	), // 'c' ➔ "⫗" SUPERSET BESIDE SUBSET
/*<!M><~nbspace><b>                                                */ DEADTRANS( L'o'	,0xE5C9	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c><%backslash>                                    */ DEADTRANS( L'/'	,0xE5CA	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><c><%backslash>                                    */ DEADTRANS( L'o'	,0xE5CA	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( L'/'	,0xE5CB	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( L'o'	,0xE5CB	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( 0x00A0	,0xE5CB	,0x2AD5	,0x0000	), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( L' '	,0xE5CB	,0x2AD5	,0x0000	), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~nbspace><c>                                                */ DEADTRANS( L'o'	,0xE5CC	,0x27C3	,0x0000	), // 'o' ➔ "⟃" OPEN SUBSET
/*<!M><~nbspace>                                                   */ DEADTRANS( L'D'	,0xE590	,0x2AD0	,0x0000	), // 'D' ➔ "⫐" CLOSED SUPERSET
/*<!M><~nbspace><e><e><%bar>                                       */ DEADTRANS( L','	,0xE5CD	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e><%bar>                                       */ DEADTRANS( 0x00A0	,0xE5CD	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e><%bar>                                       */ DEADTRANS( L' '	,0xE5CD	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L','	,0xE5CE	,0x220D	,0x0000	), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L'/'	,0xE5CE	,0x220C	,0x0000	), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( 0x00A0	,0xE5CE	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L' '	,0xE5CE	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~nbspace>                                                   */ DEADTRANS( L'G'	,0xE590	,0x27F2	,0x0000	), // 'G' ➔ "⟲" ANTICLOCKWISE GAPPED CIRCLE ARROW
/*<!M><~nbspace>                                                   */ DEADTRANS( L'I'	,0xE590	,0x2AE0	,0x0000	), // 'I' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace>                                                   */ DEADTRANS( L'K'	,0xE590	,0x212A	,0x0000	), // 'K' ➔ "K" KELVIN SIGN
/*<!M><~nbspace>                                                   */ DEADTRANS( L'k'	,0xE590	,0x212A	,0x0000	), // 'k' ➔ "K" KELVIN SIGN
/*<!M><~nbspace><n>                                                */ DEADTRANS( L'|'	,0xE5CF	,0x2ADB	,0x0000	), // '|' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'\\'	,0xE5D0	,0x29B0	,0x0000	), // '\' ➔ "⦰" REVERSED EMPTY SET
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'='	,0xE5D1	,0x229C	,0x0000	), // '=' ➔ "⊜" CIRCLED EQUALS
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'>'	,0xE5D1	,0x2A7A	,0x0000	), // '>' ➔ "⩺" GREATER-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><o><%minus>                                        */ DEADTRANS( L'>'	,0xE5D2	,0x21F4	,0x0000	), // '>' ➔ "⇴" RIGHT ARROW WITH SMALL CIRCLE
/*<!M><~nbspace><o><%minus>                                        */ DEADTRANS( 0x00A0	,0xE5D2	,0x229D	,0x0000	), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~nbspace><o><%minus>                                        */ DEADTRANS( L' '	,0xE5D2	,0x229D	,0x0000	), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'%'	,0xE5D0	,0x29BC	,0x0000	), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'%'	,0xE5D1	,0x29BC	,0x0000	), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'.'	,0xE5D0	,0x29BF	,0x0000	), // '.' ➔ "⦿" CIRCLED BULLET
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'+'	,0xE5D1	,0x2640	,0x0000	), // '+' ➔ "♀" FEMALE SIGN
/*<!M><~nbspace><o>                                                */ DEADTRANS( L';'	,0xE5D1	,0x2A3E	,0x0000	), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><o>                                                */ DEADTRANS( 0x00A7	,0xE5D1	,0x2A3E	,0x0000	), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'/'	,0xE5D1	,0x2298	,0x0000	), // '/' ➔ "⊘" CIRCLED DIVISION SLASH
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'8'	,0xE5D1	,0x2663	,0x0000	), // '8' ➔ "♣" BLACK CLUB SUIT
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'o'	,0xE5D0	,0x29BE	,0x0000	), // 'o' ➔ "⦾" CIRCLED WHITE BULLET
/*<!M><~nbspace><R>                                                */ DEADTRANS( L'/'	,0xE5D3	,0x211E	,0x0000	), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~nbspace><r>                                                */ DEADTRANS( L'/'	,0xE5D4	,0x211E	,0x0000	), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~nbspace>                                                   */ DEADTRANS( L's'	,0xE590	,0x2A0B	,0x0000	), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~nbspace><S>                                                */ DEADTRANS( L's'	,0xE5D5	,0x2A0B	,0x0000	), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~nbspace><S><S>                                             */ DEADTRANS( L'@'	,0xE5D6	,0x2140	,0x0000	), // '@' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><S><S>                                             */ DEADTRANS( 0x00A0	,0xE5D6	,0x2140	,0x0000	), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><S><S>                                             */ DEADTRANS( L' '	,0xE5D6	,0x2140	,0x0000	), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><T>                                                */ DEADTRANS( L'%'	,0xE5D7	,0x2AE0	,0x0000	), // '%' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace><T>                                                */ DEADTRANS( L'T'	,0xE5D7	,0x2AE0	,0x0000	), // 'T' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace>                                                   */ DEADTRANS( L'v'	,0xE590	,0x2A56	,0x0000	), // 'v' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><~nbspace><V>                                                */ DEADTRANS( L'V'	,0xE5D8	,0x2A08	,0x0000	), // 'V' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><~nbspace>                                                   */ DEADTRANS( L'x'	,0xE590	,0x2A2F	,0x0000	), // 'x' ➔ "⨯" VECTOR OR CROSS PRODUCT
/*<!M><~nbspace><Y>                                                */ DEADTRANS( L'-'	,0xE5D9	,0x297C	,0x0000	), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><~nbspace>                                                   */ DEADTRANS( L'z'	,0xE590	,0x2A3E	,0x0000	), // 'z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'*'	,0xE5DA	,0x22C6	,0x0000	), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~nbspace><~nbspace><%backslash>                             */ DEADTRANS( L'/'	,0xE5DB	,0x25C1	,0x0000	), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~nbspace><%backslash>                             */ DEADTRANS( 0x00A0	,0xE5DB	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~nbspace><%backslash>                             */ DEADTRANS( L' '	,0xE5DB	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~nbspace><%bar>                                   */ DEADTRANS( L'|'	,0xE5DC	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~nbspace><%bar>                                   */ DEADTRANS( 0x00A0	,0xE5DC	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><%bar>                                   */ DEADTRANS( L' '	,0xE5DC	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><%bracketleft>                           */ DEADTRANS( L']'	,0xE5DD	,0x25FD	,0x0000	), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace><%bracketleft>                           */ DEADTRANS( L'#'	,0xE5DD	,0x25FE	,0x0000	), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace><%bracketright>                          */ DEADTRANS( L'['	,0xE5DE	,0x25FD	,0x0000	), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L':'	,0xE5DA	,0x2982	,0x0000	), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~nbspace><~nbspace><%equal>                                 */ DEADTRANS( L'='	,0xE5DF	,0x2263	,0x0000	), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~nbspace><~nbspace><%greater>                               */ DEADTRANS( L'<'	,0xE5E0	,0x2AA5	,0x0000	), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~nbspace><~nbspace><%greater>                               */ DEADTRANS( L'-'	,0xE5E0	,0x2B43	,0x0000	), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'#'	,0xE5DA	,0x29E3	,0x0000	), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~nbspace><~nbspace><%less>                                  */ DEADTRANS( L'>'	,0xE5E1	,0x25C7	,0x0000	), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~nbspace><~nbspace><%less>                                  */ DEADTRANS( L'o'	,0xE5E1	,0x2A79	,0x0000	), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><~nbspace><%minus>                                 */ DEADTRANS( L'\''	,0xE5E2	,0x21C1	,0x0000	), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~nbspace><%minus>                                 */ DEADTRANS( 0x2019	,0xE5E2	,0x21C1	,0x0000	), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~nbspace><%minus>                                 */ DEADTRANS( L'/'	,0xE5E2	,0x299F	,0x0000	), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'.'	,0xE5DA	,0x2219	,0x0000	), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L';'	,0xE5DA	,0x2A3E	,0x0000	), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( 0x00A7	,0xE5DA	,0x2A3E	,0x0000	), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( L'\\'	,0xE5E3	,0x25C1	,0x0000	), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( L'-'	,0xE5E3	,0x29A7	,0x0000	), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( 0x00A0	,0xE5E3	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( L' '	,0xE5E3	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'_'	,0xE5DA	,0x2A4C	,0x0000	), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~nbspace><~nbspace><3>                                      */ DEADTRANS( L'|'	,0xE5E4	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'8'	,0xE5DA	,0x29DC	,0x0000	), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'I'	,0xE5DA	,0x27D8	,0x0000	), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( L'O'	,0xE5DA	,0x29C2	,0x0000	), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~nbspace><~nbspace><o>                                      */ DEADTRANS( L'-'	,0xE5E5	,0x27DC	,0x0000	), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~nbspace><~nbspace><o>                                      */ DEADTRANS( L'+'	,0xE5E5	,0x2A22	,0x0000	), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( L'%'	,0xE5E6	,0x27D8	,0x0000	), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( L'T'	,0xE5E6	,0x27D8	,0x0000	), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( 0x00A0	,0xE5E6	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( L' '	,0xE5E6	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk>                    */ DEADTRANS( L'#'	,0xE5E7	,0x2605	,0x0000	), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk>                    */ DEADTRANS( 0x00A0	,0xE5E7	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk>                    */ DEADTRANS( L' '	,0xE5E7	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( L'\\'	,0xE5E8	,0x27CD	,0x0000	), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( L'|'	,0xE5E8	,0x2AFF	,0x0000	), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( L'<'	,0xE5E8	,0x2662	,0x0000	), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( L'/'	,0xE5E8	,0x27CB	,0x0000	), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( L'o'	,0xE5E8	,0xDEF0	,0x0000	), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace>                     */ DEADTRANS( L'\\'	,0xE5E9	,0x29F5	,0x0000	), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace>                     */ DEADTRANS( L'/'	,0xE5E9	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~nbspace><~nbspace><~space>                       */ DEADTRANS( L'\\'	,0xE5EA	,0x29F5	,0x0000	), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~nbspace><~space>                       */ DEADTRANS( L'/'	,0xE5EA	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~nbspace><~space><%asterisk>                      */ DEADTRANS( L'#'	,0xE5EB	,0x2605	,0x0000	), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~nbspace><~space><%asterisk>                      */ DEADTRANS( 0x00A0	,0xE5EB	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~space><%asterisk>                      */ DEADTRANS( L' '	,0xE5EB	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L'\\'	,0xE5EC	,0x27CD	,0x0000	), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L'|'	,0xE5EC	,0x2AFF	,0x0000	), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L'<'	,0xE5EC	,0x2662	,0x0000	), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L'/'	,0xE5EC	,0x27CB	,0x0000	), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L'o'	,0xE5EC	,0xDEF0	,0x0000	), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~nbspace><~space><~space>                         */ DEADTRANS( L'\\'	,0xE5ED	,0x29F5	,0x0000	), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~space><~space>                         */ DEADTRANS( L'/'	,0xE5ED	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'*'	,0xE5EE	,0x22C6	,0x0000	), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~nbspace><~space><%backslash>                               */ DEADTRANS( L'/'	,0xE5EF	,0x25C1	,0x0000	), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~space><%backslash>                               */ DEADTRANS( 0x00A0	,0xE5EF	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~space><%backslash>                               */ DEADTRANS( L' '	,0xE5EF	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~space><%bar>                                     */ DEADTRANS( L'|'	,0xE5F0	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~space><%bar>                                     */ DEADTRANS( 0x00A0	,0xE5F0	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~space><%bar>                                     */ DEADTRANS( L' '	,0xE5F0	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~space><%bracketleft>                             */ DEADTRANS( L']'	,0xE5F1	,0x25FD	,0x0000	), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space><%bracketleft>                             */ DEADTRANS( L'#'	,0xE5F1	,0x25FE	,0x0000	), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space><%bracketright>                            */ DEADTRANS( L'['	,0xE5F2	,0x25FD	,0x0000	), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L':'	,0xE5EE	,0x2982	,0x0000	), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~nbspace><~space><%equal>                                   */ DEADTRANS( L'='	,0xE5F3	,0x2263	,0x0000	), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~nbspace><~space><%greater>                                 */ DEADTRANS( L'<'	,0xE5F4	,0x2AA5	,0x0000	), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~nbspace><~space><%greater>                                 */ DEADTRANS( L'-'	,0xE5F4	,0x2B43	,0x0000	), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'#'	,0xE5EE	,0x29E3	,0x0000	), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~nbspace><~space><%less>                                    */ DEADTRANS( L'>'	,0xE5F5	,0x25C7	,0x0000	), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~nbspace><~space><%less>                                    */ DEADTRANS( L'o'	,0xE5F5	,0x2A79	,0x0000	), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><~space><%minus>                                   */ DEADTRANS( L'\''	,0xE5F6	,0x21C1	,0x0000	), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~space><%minus>                                   */ DEADTRANS( 0x2019	,0xE5F6	,0x21C1	,0x0000	), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~space><%minus>                                   */ DEADTRANS( L'/'	,0xE5F6	,0x299F	,0x0000	), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'.'	,0xE5EE	,0x2219	,0x0000	), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L';'	,0xE5EE	,0x2A3E	,0x0000	), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~space>                                           */ DEADTRANS( 0x00A7	,0xE5EE	,0x2A3E	,0x0000	), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( L'\\'	,0xE5F7	,0x25C1	,0x0000	), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( L'-'	,0xE5F7	,0x29A7	,0x0000	), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( 0x00A0	,0xE5F7	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( L' '	,0xE5F7	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'_'	,0xE5EE	,0x2A4C	,0x0000	), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~nbspace><~space><3>                                        */ DEADTRANS( L'|'	,0xE5F8	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'8'	,0xE5EE	,0x29DC	,0x0000	), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'I'	,0xE5EE	,0x27D8	,0x0000	), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L'O'	,0xE5EE	,0x29C2	,0x0000	), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~nbspace><~space><o>                                        */ DEADTRANS( L'-'	,0xE5F9	,0x27DC	,0x0000	), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~nbspace><~space><o>                                        */ DEADTRANS( L'+'	,0xE5F9	,0x2A22	,0x0000	), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( L'%'	,0xE5FA	,0x27D8	,0x0000	), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( L'T'	,0xE5FA	,0x27D8	,0x0000	), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( 0x00A0	,0xE5FA	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( L' '	,0xE5FA	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~space><~space><%asterisk>                        */ DEADTRANS( L'#'	,0xE5FB	,0x2605	,0x0000	), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~space><~space><%asterisk>                        */ DEADTRANS( 0x00A0	,0xE5FB	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~space><~space><%asterisk>                        */ DEADTRANS( L' '	,0xE5FB	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L'\\'	,0xE5FC	,0x27CD	,0x0000	), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L'|'	,0xE5FC	,0x2AFF	,0x0000	), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L'<'	,0xE5FC	,0x2662	,0x0000	), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L'/'	,0xE5FC	,0x27CB	,0x0000	), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L'o'	,0xE5FC	,0xDEF0	,0x0000	), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~space><~space><~space>                           */ DEADTRANS( L'\\'	,0xE5FD	,0x29F5	,0x0000	), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~space><~space><~space>                           */ DEADTRANS( L'/'	,0xE5FD	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbthinspace>                                               */ DEADTRANS( L' '	,0xE5FE	,0x238D	,0x0000	), // ' ' ➔ "⎍" MONOSTABLE SYMBOL
/*<!M><~space><%ampersand>                                         */ DEADTRANS( L'|'	,0xE5FF	,0x20D3	,0x0000	), // '|' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><~space><%ampersand>                                         */ DEADTRANS( L'<'	,0xE5FF	,0x20EE	,0x0000	), // '<' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><~space><%ampersand>                                         */ DEADTRANS( L'-'	,0xE5FF	,0x20EF	,0x0000	), // '-' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><~space><%apostrophe>                                        */ DEADTRANS( L'='	,0xE600	,0x2AED	,0x0000	), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~space><%apostrophe>                                        */ DEADTRANS( L'-'	,0xE600	,0x2A3D	,0x0000	), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~space><%apostrophe>                                        */ DEADTRANS( L'+'	,0xE600	,0x22B9	,0x0000	), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%aprightsinglequotemark>                            */ DEADTRANS( L'='	,0xE601	,0x2AED	,0x0000	), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~space><%aprightsinglequotemark>                            */ DEADTRANS( L'-'	,0xE601	,0x2A3D	,0x0000	), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~space><%aprightsinglequotemark>                            */ DEADTRANS( L'+'	,0xE601	,0x22B9	,0x0000	), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%asterisk>                                          */ DEADTRANS( L'='	,0xE602	,0x225B	,0x0000	), // '=' ➔ "≛" STAR EQUALS
/*<!M><~space><%asterisk>                                          */ DEADTRANS( 0x00A0	,0xE602	,0x2217	,0x0000	), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~space><%asterisk>                                          */ DEADTRANS( L' '	,0xE602	,0x2217	,0x0000	), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~space><%backslash>                                         */ DEADTRANS( L'>'	,0xE603	,0x292D	,0x0000	), // '>' ➔ "⤭" SOUTH EAST ARROW CROSSING NORTH EAST ARROW
/*<!M><~space><%backslash>                                         */ DEADTRANS( L'-'	,0xE603	,0x29A3	,0x0000	), // '-' ➔ "⦣" REVERSED ANGLE
/*<!M><~space><%backslash><%slash>                                 */ DEADTRANS( L'|'	,0xE604	,0x2A1E	,0x0000	), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~space><%backslash><%slash>                                 */ DEADTRANS( L'#'	,0xE604	,0x25C0	,0x0000	), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~space><%backslash><%slash>                                 */ DEADTRANS( L'_'	,0xE604	,0x29CD	,0x0000	), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~space><%backslash>                                         */ DEADTRANS( L'c'	,0xE603	,0x27C8	,0x0000	), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~space><%backslash>                                         */ DEADTRANS( 0x00A0	,0xE603	,0x2216	,0x0000	), // ' ' ➔ "∖" SET MINUS
/*<!M><~space><%backslash>                                         */ DEADTRANS( L' '	,0xE603	,0x2216	,0x0000	), // ' ' ➔ "∖" SET MINUS
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L'|'	,0xE605	,0x2A1D	,0x0000	), // '|' ➔ "⨝" JOIN
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( 0x00A0	,0xE605	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L' '	,0xE605	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%bar><%bar>                                   */ DEADTRANS( L'-'	,0xE606	,0x22AA	,0x0000	), // '-' ➔ "⊪" TRIPLE VERTICAL BAR RIGHT TURNSTILE
/*<!M><~space><%bar><%bar><%bar>                                   */ DEADTRANS( 0x00A0	,0xE606	,0x2AF4	,0x0000	), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><%bar><%bar><%bar>                                   */ DEADTRANS( L' '	,0xE606	,0x2AF4	,0x0000	), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><%bar><%bar>                                         */ DEADTRANS( L'-'	,0xE607	,0x22A9	,0x0000	), // '-' ➔ "⊩" FORCES
/*<!M><~space><%bar><%bar>                                         */ DEADTRANS( 0x00A0	,0xE607	,0x2225	,0x0000	), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~space><%bar><%bar>                                         */ DEADTRANS( L' '	,0xE607	,0x2225	,0x0000	), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~space><%bar>                                               */ DEADTRANS( L'='	,0xE608	,0x29E7	,0x0000	), // '=' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%bar>                                               */ DEADTRANS( L'#'	,0xE608	,0x25B6	,0x0000	), // '#' ➔ "▶" BLACK RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar>                                               */ DEADTRANS( L'-'	,0xE608	,0x27CA	,0x0000	), // '-' ➔ "⟊" VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><~space><%bar>                                               */ DEADTRANS( L')'	,0xE608	,0x2ADD	,0x0000	), // ')' ➔ "⫝" NONFORKING
/*<!M><~space><%bar><%slash><%backslash>                           */ DEADTRANS( L'|'	,0xE609	,0x2A1D	,0x0000	), // '|' ➔ "⨝" JOIN
/*<!M><~space><%bar><%slash><%backslash>                           */ DEADTRANS( 0x00A0	,0xE609	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%slash><%backslash>                           */ DEADTRANS( L' '	,0xE609	,0x25B7	,0x0000	), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%slash>                                       */ DEADTRANS( 0x00A0	,0xE60A	,0x2A57	,0x0000	), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~space><%bar><%slash>                                       */ DEADTRANS( L' '	,0xE60A	,0x2A57	,0x0000	), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L','	,0xE60B	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( 0x00A0	,0xE60B	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L' '	,0xE60B	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L','	,0xE60C	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( 0x00A0	,0xE60C	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L' '	,0xE60C	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar>                                               */ DEADTRANS( L'o'	,0xE608	,0x2AF0	,0x0000	), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><~space><%bar><p>                                            */ DEADTRANS( L','	,0xE60D	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><p>                                            */ DEADTRANS( 0x00A0	,0xE60D	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><p>                                            */ DEADTRANS( L' '	,0xE60D	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar>                                               */ DEADTRANS( 0x00A0	,0xE608	,0x2223	,0x0000	), // ' ' ➔ "∣" DIVIDES
/*<!M><~space><%bar>                                               */ DEADTRANS( L' '	,0xE608	,0x2223	,0x0000	), // ' ' ➔ "∣" DIVIDES
/*<!M><~space>                                                     */ DEADTRANS( L'{'	,0xE60E	,0x2983	,0x0000	), // '{' ➔ "⦃" LEFT WHITE CURLY BRACKET
/*<!M><~space>                                                     */ DEADTRANS( L'}'	,0xE60E	,0x2984	,0x0000	), // '}' ➔ "⦄" RIGHT WHITE CURLY BRACKET
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'['	,0xE60F	,0x27E6	,0x0000	), // '[' ➔ "⟦" MATHEMATICAL LEFT WHITE SQUARE BRACKET
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L']'	,0xE60F	,0x25FB	,0x0000	), // ']' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'#'	,0xE60F	,0x25FC	,0x0000	), // '#' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'-'	,0xE60F	,0x2ACD	,0x0000	), // '-' ➔ "⫍" SQUARE LEFT OPEN BOX OPERATOR
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'_'	,0xE60F	,0x298B	,0x0000	), // '_' ➔ "⦋" LEFT SQUARE BRACKET WITH UNDERBAR
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'a'	,0xE60F	,0x27CE	,0x0000	), // 'a' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'o'	,0xE60F	,0x29C7	,0x0000	), // 'o' ➔ "⧇" SQUARED SMALL CIRCLE
/*<!M><~space><%bracketright>                                      */ DEADTRANS( L'['	,0xE610	,0x25FB	,0x0000	), // '[' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~space><%bracketright>                                      */ DEADTRANS( L']'	,0xE610	,0x27E7	,0x0000	), // ']' ➔ "⟧" MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><~space><%bracketright>                                      */ DEADTRANS( L'_'	,0xE610	,0x298C	,0x0000	), // '_' ➔ "⦌" RIGHT SQUARE BRACKET WITH UNDERBAR
/*<!M><~space><%circum>                                            */ DEADTRANS( L'^'	,0xE611	,0x22C4	,0x0000	), // '^' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~space><%circum>                                            */ DEADTRANS( L'='	,0xE611	,0x2259	,0x0000	), // '=' ➔ "≙" ESTIMATES
/*<!M><~space><%circum>                                            */ DEADTRANS( L'_'	,0xE611	,0x25B5	,0x0000	), // '_' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~space><%circum>                                            */ DEADTRANS( L'o'	,0xE611	,0x2A36	,0x0000	), // 'o' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~space><%circum>                                            */ DEADTRANS( L'O'	,0xE611	,0x2A36	,0x0000	), // 'O' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~space><%circum>                                            */ DEADTRANS( 0x00A0	,0xE611	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~space><%circum>                                            */ DEADTRANS( L' '	,0xE611	,0x2227	,0x0000	), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~space><%colon>                                             */ DEADTRANS( L':'	,0xE612	,0x2237	,0x0000	), // ':' ➔ "∷" PROPORTION
/*<!M><~space><%colon>                                             */ DEADTRANS( L'~'	,0xE612	,0x223B	,0x0000	), // '~' ➔ "∻" HOMOTHETIC
/*<!M><~space><%colon>                                             */ DEADTRANS( 0x00A0	,0xE612	,0x2236	,0x0000	), // ' ' ➔ "∶" RATIO
/*<!M><~space><%colon>                                             */ DEADTRANS( L' '	,0xE612	,0x2236	,0x0000	), // ' ' ➔ "∶" RATIO
/*<!M><~space><%equal><%bar>                                       */ DEADTRANS( L'|'	,0xE613	,0x22D5	,0x0000	), // '|' ➔ "⋕" EQUAL AND PARALLEL TO
/*<!M><~space><%equal><%bar>                                       */ DEADTRANS( 0x00A0	,0xE613	,0x29E7	,0x0000	), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%equal><%bar>                                       */ DEADTRANS( L' '	,0xE613	,0x29E7	,0x0000	), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%equal>                                             */ DEADTRANS( L'='	,0xE614	,0x2A75	,0x0000	), // '=' ➔ "⩵" TWO CONSECUTIVE EQUALS SIGNS
/*<!M><~space><%equal>                                             */ DEADTRANS( L'>'	,0xE614	,0x2A9A	,0x0000	), // '>' ➔ "⪚" DOUBLE-LINE EQUAL TO OR GREATER-THAN
/*<!M><~space><%equal><%minus>                                     */ DEADTRANS( L'>'	,0xE615	,0x2971	,0x0000	), // '>' ➔ "⥱" EQUALS SIGN ABOVE RIGHTWARDS ARROW
/*<!M><~space><%equal><%minus>                                     */ DEADTRANS( L'/'	,0xE615	,0x29E5	,0x0000	), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'!'	,0xE616	,0x00A1	,0x0000	), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'j'	,0xE616	,0x297F	,0x0000	), // 'j' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'J'	,0xE616	,0x297F	,0x0000	), // 'J' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'Y'	,0xE616	,0x297F	,0x0000	), // 'Y' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%greater><%greater>                                 */ DEADTRANS( L'>'	,0xE617	,0x22D9	,0x0000	), // '>' ➔ "⋙" VERY MUCH GREATER-THAN
/*<!M><~space><%greater><%greater>                                 */ DEADTRANS( 0x00A0	,0xE617	,0x226B	,0x0000	), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~space><%greater><%greater>                                 */ DEADTRANS( L' '	,0xE617	,0x226B	,0x0000	), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~space><%greater>                                           */ DEADTRANS( L'<'	,0xE618	,0x2AA4	,0x0000	), // '<' ➔ "⪤" GREATER-THAN OVERLAPPING LESS-THAN
/*<!M><~space><%greater><%minus>                                   */ DEADTRANS( L'>'	,0xE619	,0x2978	,0x0000	), // '>' ➔ "⥸" GREATER-THAN ABOVE RIGHTWARDS ARROW
/*<!M><~space><%greater><%minus>                                   */ DEADTRANS( 0x00A0	,0xE619	,0x2AAB	,0x0000	), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~space><%greater><%minus>                                   */ DEADTRANS( L' '	,0xE619	,0x2AAB	,0x0000	), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~space><%greater>                                           */ DEADTRANS( L')'	,0xE618	,0x2994	,0x0000	), // ')' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~space><%greater>                                           */ DEADTRANS( L'o'	,0xE618	,0x2941	,0x0000	), // 'o' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~space><%greater>                                           */ DEADTRANS( 0x00A0	,0xE618	,0x200E	,0x0000	), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~space><%greater>                                           */ DEADTRANS( L' '	,0xE618	,0x200E	,0x0000	), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~space><%hash>                                              */ DEADTRANS( L'%'	,0xE61A	,0x2A33	,0x0000	), // '%' ➔ "⨳" SMASH PRODUCT
/*<!M><~space><%hash>                                              */ DEADTRANS( 0x00A0	,0xE61A	,0x266F	,0x0000	), // ' ' ➔ "♯" MUSIC SHARP SIGN
/*<!M><~space><%hash>                                              */ DEADTRANS( L' '	,0xE61A	,0x266F	,0x0000	), // ' ' ➔ "♯" MUSIC SHARP SIGN
/*<!M><~space><%less>                                              */ DEADTRANS( L'\\'	,0xE61B	,0x2932	,0x0000	), // '\' ➔ "⤲" NORTH WEST ARROW CROSSING NORTH EAST ARROW
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( L'>'	,0xE61C	,0x2A8B	,0x0000	), // '>' ➔ "⪋" LESS-THAN ABOVE DOUBLE-LINE EQUAL ABOVE GREATER-THAN
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( L'/'	,0xE61C	,0x2268	,0x0000	), // '/' ➔ "≨" LESS-THAN BUT NOT EQUAL TO
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( 0x00A0	,0xE61C	,0x2266	,0x0000	), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( L' '	,0xE61C	,0x2266	,0x0000	), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~space><%less>                                              */ DEADTRANS( L'!'	,0xE61B	,0x29BD	,0x0000	), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><~space><%less>                                              */ DEADTRANS( L'>'	,0xE61B	,0x22C4	,0x0000	), // '>' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~space><%less><%less>                                       */ DEADTRANS( L'<'	,0xE61D	,0x22D8	,0x0000	), // '<' ➔ "⋘" VERY MUCH LESS-THAN
/*<!M><~space><%less><%less><%minus>                               */ DEADTRANS( L'|'	,0xE61E	,0x2B36	,0x0000	), // '|' ➔ "⬶" LEFTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><~space><%less><%less><%minus>                               */ DEADTRANS( 0x00A0	,0xE61E	,0x2976	,0x0000	), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~space><%less><%less><%minus>                               */ DEADTRANS( L' '	,0xE61E	,0x2976	,0x0000	), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~space><%less><%less>                                       */ DEADTRANS( 0x00A0	,0xE61D	,0x226A	,0x0000	), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~space><%less><%less>                                       */ DEADTRANS( L' '	,0xE61D	,0x226A	,0x0000	), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'|'	,0xE61F	,0x21F7	,0x0000	), // '|' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'<'	,0xE61F	,0x2977	,0x0000	), // '<' ➔ "⥷" LEFTWARDS ARROW THROUGH LESS-THAN
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'-'	,0xE61F	,0x27F7	,0x0000	), // '-' ➔ "⟷" LONG LEFT RIGHT ARROW
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'~'	,0xE61F	,0x2973	,0x0000	), // '~' ➔ "⥳" LEFTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( 0x00A0	,0xE61F	,0x2AAA	,0x0000	), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L' '	,0xE61F	,0x2AAA	,0x0000	), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~space><%less>                                              */ DEADTRANS( L'('	,0xE61B	,0x2993	,0x0000	), // '(' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~space><%less>                                              */ DEADTRANS( L')'	,0xE61B	,0x2AA6	,0x0000	), // ')' ➔ "⪦" LESS-THAN CLOSED BY CURVE
/*<!M><~space><%less>                                              */ DEADTRANS( L'/'	,0xE61B	,0x226E	,0x0000	), // '/' ➔ "≮" NOT LESS-THAN
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( L'>'	,0xE620	,0x21AD	,0x0000	), // '>' ➔ "↭" LEFT RIGHT WAVE ARROW
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( L'~'	,0xE620	,0x21DC	,0x0000	), // '~' ➔ "⇜" LEFTWARDS SQUIGGLE ARROW
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( 0x00A0	,0xE620	,0x2272	,0x0000	), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( L' '	,0xE620	,0x2272	,0x0000	), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~space><%less>                                              */ DEADTRANS( L'3'	,0xE61B	,0x2660	,0x0000	), // '3' ➔ "♠" BLACK SPADE SUIT
/*<!M><~space><%less>                                              */ DEADTRANS( L'C'	,0xE61B	,0x293E	,0x0000	), // 'C' ➔ "⤾" LOWER RIGHT SEMICIRCULAR CLOCKWISE ARROW
/*<!M><~space><%less>                                              */ DEADTRANS( L'n'	,0xE61B	,0x21B6	,0x0000	), // 'n' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><~space><%less>                                              */ DEADTRANS( L'o'	,0xE61B	,0x2940	,0x0000	), // 'o' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~space><%less>                                              */ DEADTRANS( 0x00A0	,0xE61B	,0x200F	,0x0000	), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~space><%less>                                              */ DEADTRANS( L' '	,0xE61B	,0x200F	,0x0000	), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~space><%minus><%apostrophe>                                */ DEADTRANS( L'-'	,0xE621	,0x2ADF	,0x0000	), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><%minus><%apostrophe>                                */ DEADTRANS( 0x00A0	,0xE621	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%apostrophe>                                */ DEADTRANS( L' '	,0xE621	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%aprightsinglequotemark>                    */ DEADTRANS( L'-'	,0xE622	,0x2ADF	,0x0000	), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><%minus><%aprightsinglequotemark>                    */ DEADTRANS( 0x00A0	,0xE622	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%aprightsinglequotemark>                    */ DEADTRANS( L' '	,0xE622	,0x2A3C	,0x0000	), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus>                                             */ DEADTRANS( L'|'	,0xE623	,0x21F8	,0x0000	), // '|' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~space><%minus>                                             */ DEADTRANS( L'['	,0xE623	,0x27E4	,0x0000	), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~space><%minus><%bracketright>                              */ DEADTRANS( L'['	,0xE624	,0x27E4	,0x0000	), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~space><%minus><%bracketright>                              */ DEADTRANS( 0x00A0	,0xE624	,0x2ACE	,0x0000	), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~space><%minus><%bracketright>                              */ DEADTRANS( L' '	,0xE624	,0x2ACE	,0x0000	), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~space><%minus>                                             */ DEADTRANS( L'/'	,0xE623	,0x29A2	,0x0000	), // '/' ➔ "⦢" TURNED ANGLE
/*<!M><~space><%minus>                                             */ DEADTRANS( L'e'	,0xE623	,0x22F2	,0x0000	), // 'e' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><~space><%minus>                                             */ DEADTRANS( L'j'	,0xE623	,0x297D	,0x0000	), // 'j' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus>                                             */ DEADTRANS( L'J'	,0xE623	,0x297D	,0x0000	), // 'J' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus>                                             */ DEADTRANS( L'O'	,0xE623	,0x29B1	,0x0000	), // 'O' ➔ "⦱" EMPTY SET WITH OVERBAR
/*<!M><~space><%minus><o>                                          */ DEADTRANS( L'-'	,0xE625	,0x2256	,0x0000	), // '-' ➔ "≖" RING IN EQUAL TO
/*<!M><~space><%minus><o>                                          */ DEADTRANS( 0x00A0	,0xE625	,0x22B8	,0x0000	), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~space><%minus><o>                                          */ DEADTRANS( L' '	,0xE625	,0x22B8	,0x0000	), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~space><%minus>                                             */ DEADTRANS( L'S'	,0xE623	,0x2A1B	,0x0000	), // 'S' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus><s>                                          */ DEADTRANS( L'/'	,0xE626	,0x299E	,0x0000	), // '/' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><~space><%minus><s>                                          */ DEADTRANS( 0x00A0	,0xE626	,0x2A1B	,0x0000	), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus><s>                                          */ DEADTRANS( L' '	,0xE626	,0x2A1B	,0x0000	), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus>                                             */ DEADTRANS( L'Y'	,0xE623	,0x297D	,0x0000	), // 'Y' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus>                                             */ DEADTRANS( 0x00A0	,0xE623	,0x2212	,0x0000	), // ' ' ➔ "−" MINUS SIGN
/*<!M><~space><%minus>                                             */ DEADTRANS( L' '	,0xE623	,0x2212	,0x0000	), // ' ' ➔ "−" MINUS SIGN
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'['	,0xE627	,0x27EE	,0x0000	), // '[' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L']'	,0xE627	,0x27EE	,0x0000	), // ']' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'='	,0xE627	,0x224E	,0x0000	), // '=' ➔ "≎" GEOMETRICALLY EQUIVALENT TO
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'>'	,0xE627	,0x2AA7	,0x0000	), // '>' ➔ "⪧" GREATER-THAN CLOSED BY CURVE
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'<'	,0xE627	,0x2993	,0x0000	), // '<' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'('	,0xE627	,0x2985	,0x0000	), // '(' ➔ "⦅" LEFT WHITE PARENTHESIS
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'8'	,0xE627	,0x29DD	,0x0000	), // '8' ➔ "⧝" TIE OVER INFINITY
/*<!M><~space><%parenleft>                                         */ DEADTRANS( 0x00A0	,0xE627	,0x2040	,0x0000	), // ' ' ➔ "⁀" CHARACTER TIE
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L' '	,0xE627	,0x2040	,0x0000	), // ' ' ➔ "⁀" CHARACTER TIE
/*<!M><~space><%parenright>                                        */ DEADTRANS( L'['	,0xE628	,0x27EF	,0x0000	), // '[' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~space><%parenright>                                        */ DEADTRANS( L']'	,0xE628	,0x27EF	,0x0000	), // ']' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~space><%parenright>                                        */ DEADTRANS( L'>'	,0xE628	,0x2994	,0x0000	), // '>' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~space><%parenright>                                        */ DEADTRANS( L')'	,0xE628	,0x2986	,0x0000	), // ')' ➔ "⦆" RIGHT WHITE PARENTHESIS
/*<!M><~space><%period>                                            */ DEADTRANS( L'a'	,0xE629	,0x2A51	,0x0000	), // 'a' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period>                                            */ DEADTRANS( L'A'	,0xE629	,0x2A51	,0x0000	), // 'A' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period>                                            */ DEADTRANS( L'b'	,0xE629	,0x2AC4	,0x0000	), // 'b' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c>                                         */ DEADTRANS( L'\\'	,0xE62A	,0x2AC4	,0x0000	), // '\' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c>                                         */ DEADTRANS( L'_'	,0xE62A	,0x2AC3	,0x0000	), // '_' ➔ "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c>                                         */ DEADTRANS( L'c'	,0xE62A	,0x2AC4	,0x0000	), // 'c' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period>                                            */ DEADTRANS( L'e'	,0xE629	,0x22F5	,0x0000	), // 'e' ➔ "⋵" ELEMENT OF WITH DOT ABOVE
/*<!M><~space><%period><v>                                         */ DEADTRANS( L'v'	,0xE62B	,0x2A51	,0x0000	), // 'v' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><V>                                         */ DEADTRANS( L'V'	,0xE62C	,0x2A51	,0x0000	), // 'V' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><v>                                         */ DEADTRANS( 0x00A0	,0xE62B	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><V>                                         */ DEADTRANS( 0x00A0	,0xE62C	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><v>                                         */ DEADTRANS( L' '	,0xE62B	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><V>                                         */ DEADTRANS( L' '	,0xE62C	,0x2A52	,0x0000	), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period>                                            */ DEADTRANS( L'x'	,0xE629	,0x2A30	,0x0000	), // 'x' ➔ "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><~space><%period>                                            */ DEADTRANS( 0x00A0	,0xE629	,0x22C5	,0x0000	), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~space><%period>                                            */ DEADTRANS( L' '	,0xE629	,0x22C5	,0x0000	), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~space><%plus>                                              */ DEADTRANS( L'\''	,0xE62D	,0x22B9	,0x0000	), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%plus>                                              */ DEADTRANS( 0x2019	,0xE62D	,0x22B9	,0x0000	), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%plus>                                              */ DEADTRANS( L'^'	,0xE62D	,0x2A28	,0x0000	), // '^' ➔ "⨨" PLUS SIGN WITH BLACK TRIANGLE
/*<!M><~space><%plus>                                              */ DEADTRANS( L'+'	,0xE62D	,0x29FA	,0x0000	), // '+' ➔ "⧺" DOUBLE PLUS
/*<!M><~space><%plus>                                              */ DEADTRANS( L'2'	,0xE62D	,0x2A27	,0x0000	), // '2' ➔ "⨧" PLUS SIGN WITH SUBSCRIPT TWO
/*<!M><~space>                                                     */ DEADTRANS( L';'	,0xE60E	,0x2A1F	,0x0000	), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~space>                                                     */ DEADTRANS( 0x00A7	,0xE60E	,0x2A1F	,0x0000	), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~space><%slash><%backslash>                                 */ DEADTRANS( L'|'	,0xE62E	,0x2A1E	,0x0000	), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~space><%slash><%backslash>                                 */ DEADTRANS( L'#'	,0xE62E	,0x25C0	,0x0000	), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~space><%slash><%backslash>                                 */ DEADTRANS( L'_'	,0xE62E	,0x29CD	,0x0000	), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~space><%slash><%hash><%underscore>                         */ DEADTRANS( L'\\'	,0xE62F	,0x25B4	,0x0000	), // '\' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><~space><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xE630	,0x2AFB	,0x0000	), // '/' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><~space><%slash><%slash>                                     */ DEADTRANS( 0x00A0	,0xE630	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~space><%slash><%slash>                                     */ DEADTRANS( L' '	,0xE630	,0x2AFD	,0x0000	), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~space><%slash><%underscore>                                */ DEADTRANS( L'\\'	,0xE631	,0x25B5	,0x0000	), // '\' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~space><%slash>                                             */ DEADTRANS( L'c'	,0xE632	,0x27C8	,0x0000	), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~space><%slash>                                             */ DEADTRANS( 0x00A0	,0xE632	,0x2215	,0x0000	), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~space><%slash>                                             */ DEADTRANS( L' '	,0xE632	,0x2215	,0x0000	), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~space><%tilde>                                             */ DEADTRANS( L':'	,0xE633	,0x223B	,0x0000	), // ':' ➔ "∻" HOMOTHETIC
/*<!M><~space><%tilde><%equal><%slash>                             */ DEADTRANS( L'/'	,0xE634	,0x29E4	,0x0000	), // '/' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><~space><%tilde><%equal><%slash>                             */ DEADTRANS( 0x00A0	,0xE634	,0x2246	,0x0000	), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~space><%tilde><%equal><%slash>                             */ DEADTRANS( L' '	,0xE634	,0x2246	,0x0000	), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~space><%tilde><%equal>                                     */ DEADTRANS( 0x00A0	,0xE635	,0x2245	,0x0000	), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~space><%tilde><%equal>                                     */ DEADTRANS( L' '	,0xE635	,0x2245	,0x0000	), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~space><%tilde>                                             */ DEADTRANS( L'>'	,0xE633	,0x2A9E	,0x0000	), // '>' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><~space><%tilde>                                             */ DEADTRANS( L'-'	,0xE633	,0x2972	,0x0000	), // '-' ➔ "⥲" TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><~space><%tilde>                                             */ DEADTRANS( L'%'	,0xE633	,0x2240	,0x0000	), // '%' ➔ "≀" WREATH PRODUCT
/*<!M><~space><%tilde><%slash>                                     */ DEADTRANS( 0x00A0	,0xE636	,0x2241	,0x0000	), // ' ' ➔ "≁" NOT TILDE
/*<!M><~space><%tilde><%slash>                                     */ DEADTRANS( L' '	,0xE636	,0x2241	,0x0000	), // ' ' ➔ "≁" NOT TILDE
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( L'='	,0xE637	,0x2A70	,0x0000	), // '=' ➔ "⩰" APPROXIMATELY EQUAL OR EQUAL TO
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( L'~'	,0xE637	,0x224B	,0x0000	), // '~' ➔ "≋" TRIPLE TILDE
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( 0x00A0	,0xE637	,0x2248	,0x0000	), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( L' '	,0xE637	,0x2248	,0x0000	), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~space><%tilde>                                             */ DEADTRANS( 0x00A0	,0xE633	,0x223C	,0x0000	), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~space><%tilde>                                             */ DEADTRANS( L' '	,0xE633	,0x223C	,0x0000	), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'\\'	,0xE638	,0x25BF	,0x0000	), // '\' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'#'	,0xE638	,0x25BE	,0x0000	), // '#' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore><%minus>                                */ DEADTRANS( L'\''	,0xE639	,0x296D	,0x0000	), // ''' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~space><%underscore><%minus>                                */ DEADTRANS( 0x2019	,0xE639	,0x296D	,0x0000	), // '’' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~space><%underscore><%minus>                                */ DEADTRANS( L'/'	,0xE639	,0x29A4	,0x0000	), // '/' ➔ "⦤" ANGLE WITH UNDERBAR
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'/'	,0xE638	,0x25BF	,0x0000	), // '/' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L'%'	,0xE63A	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L'%'	,0xE63B	,0x2A5E	,0x0000	), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( 0x00A0	,0xE63A	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( 0x00A0	,0xE63B	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L' '	,0xE63A	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L' '	,0xE63B	,0x2A62	,0x0000	), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'a'	,0xE638	,0x22BC	,0x0000	), // 'a' ➔ "⊼" NAND
/*<!M><~space><%underscore><e><%backslash>                         */ DEADTRANS( L','	,0xE63C	,0x22FE	,0x0000	), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e><%backslash>                         */ DEADTRANS( 0x00A0	,0xE63C	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e><%backslash>                         */ DEADTRANS( L' '	,0xE63C	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e>                                     */ DEADTRANS( L','	,0xE63D	,0x22F7	,0x0000	), // ',' ➔ "⋷" SMALL ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore><e>                                     */ DEADTRANS( 0x00A0	,0xE63D	,0x22F6	,0x0000	), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore><e>                                     */ DEADTRANS( L' '	,0xE63D	,0x22F6	,0x0000	), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'n'	,0xE638	,0x2A43	,0x0000	), // 'n' ➔ "⩃" INTERSECTION WITH OVERBAR
/*<!M><~space><%underscore><p>                                     */ DEADTRANS( L','	,0xE63E	,0x22FE	,0x0000	), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><p>                                     */ DEADTRANS( 0x00A0	,0xE63E	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><p>                                     */ DEADTRANS( L' '	,0xE63E	,0x22FD	,0x0000	), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><u>                                     */ DEADTRANS( L'#'	,0xE63F	,0x2A50	,0x0000	), // '#' ➔ "⩐" CLOSED UNION WITH SERIFS AND SMASH PRODUCT
/*<!M><~space><%underscore><u>                                     */ DEADTRANS( 0x00A0	,0xE63F	,0x2A42	,0x0000	), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~space><%underscore><u>                                     */ DEADTRANS( L' '	,0xE63F	,0x2A42	,0x0000	), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~space><%underscore><v>                                     */ DEADTRANS( L'v'	,0xE640	,0x22BC	,0x0000	), // 'v' ➔ "⊼" NAND
/*<!M><~space><%underscore><v>                                     */ DEADTRANS( 0x00A0	,0xE640	,0x22BD	,0x0000	), // ' ' ➔ "⊽" NOR
/*<!M><~space><%underscore><v>                                     */ DEADTRANS( L' '	,0xE640	,0x22BD	,0x0000	), // ' ' ➔ "⊽" NOR
/*<!M><~space><%underscore><X>                                     */ DEADTRANS( L'#'	,0xE641	,0x29D7	,0x0000	), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><~space><%underscore><X>                                     */ DEADTRANS( L'_'	,0xE641	,0x29D6	,0x0000	), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><~space><2>                                                  */ DEADTRANS( L'<'	,0xE642	,0x2AA3	,0x0000	), // '<' ➔ "⪣" DOUBLE NESTED LESS-THAN WITH UNDERBAR
/*<!M><~space><2>                                                  */ DEADTRANS( L'-'	,0xE642	,0x21C9	,0x0000	), // '-' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><~space><3>                                                  */ DEADTRANS( L'|'	,0xE643	,0x2AF4	,0x0000	), // '|' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><3>                                                  */ DEADTRANS( L'-'	,0xE643	,0x21F6	,0x0000	), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><~space>                                                     */ DEADTRANS( L'8'	,0xE60E	,0x221D	,0x0000	), // '8' ➔ "∝" PROPORTIONAL TO
/*<!M><~space><A>                                                  */ DEADTRANS( L'-'	,0xE644	,0x2A3A	,0x0000	), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><~space><A><%underscore>                                     */ DEADTRANS( L'_'	,0xE645	,0x2A60	,0x0000	), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><~space><A><%underscore>                                     */ DEADTRANS( 0x00A0	,0xE645	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~space><A><%underscore>                                     */ DEADTRANS( L' '	,0xE645	,0x2A5F	,0x0000	), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~space><A>                                                  */ DEADTRANS( L'A'	,0xE644	,0x2A07	,0x0000	), // 'A' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><~space><a>                                                  */ DEADTRANS( L'a'	,0xE646	,0x2A55	,0x0000	), // 'a' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><~space><A>                                                  */ DEADTRANS( L'V'	,0xE644	,0x25CA	,0x0000	), // 'V' ➔ "◊" LOZENGE
/*<!M><~space><a>                                                  */ DEADTRANS( L'v'	,0xE646	,0x25CA	,0x0000	), // 'v' ➔ "◊" LOZENGE
/*<!M><~space><A>                                                  */ DEADTRANS( 0x00A0	,0xE644	,0x22C0	,0x0000	), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~space><A>                                                  */ DEADTRANS( L' '	,0xE644	,0x22C0	,0x0000	), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~space><b>                                                  */ DEADTRANS( L'/'	,0xE647	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><b>                                                  */ DEADTRANS( L'c'	,0xE647	,0x2AD7	,0x0000	), // 'c' ➔ "⫗" SUPERSET BESIDE SUBSET
/*<!M><~space><b>                                                  */ DEADTRANS( L'o'	,0xE647	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><b>                                                  */ DEADTRANS( 0x00A0	,0xE647	,0x266D	,0x0000	), // ' ' ➔ "♭" MUSIC FLAT SIGN
/*<!M><~space><b>                                                  */ DEADTRANS( L' '	,0xE647	,0x266D	,0x0000	), // ' ' ➔ "♭" MUSIC FLAT SIGN
/*<!M><~space><c><%backslash>                                      */ DEADTRANS( L'/'	,0xE648	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><c><%backslash>                                      */ DEADTRANS( L'o'	,0xE648	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><c><c>                                               */ DEADTRANS( L'/'	,0xE649	,0x27C9	,0x0000	), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><c><c>                                               */ DEADTRANS( L'o'	,0xE649	,0x27C4	,0x0000	), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><c><c>                                               */ DEADTRANS( 0x00A0	,0xE649	,0x2AD5	,0x0000	), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~space><c><c>                                               */ DEADTRANS( L' '	,0xE649	,0x2AD5	,0x0000	), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~space><c>                                                  */ DEADTRANS( L'o'	,0xE64A	,0x27C3	,0x0000	), // 'o' ➔ "⟃" OPEN SUBSET
/*<!M><~space>                                                     */ DEADTRANS( L'D'	,0xE60E	,0x2AD0	,0x0000	), // 'D' ➔ "⫐" CLOSED SUPERSET
/*<!M><~space><e><e><%bar>                                         */ DEADTRANS( L','	,0xE64B	,0x22FC	,0x0000	), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e><%bar>                                         */ DEADTRANS( 0x00A0	,0xE64B	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e><%bar>                                         */ DEADTRANS( L' '	,0xE64B	,0x22FB	,0x0000	), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e>                                               */ DEADTRANS( L','	,0xE64C	,0x220D	,0x0000	), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><~space><e><e>                                               */ DEADTRANS( L'/'	,0xE64C	,0x220C	,0x0000	), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><~space><e><e>                                               */ DEADTRANS( 0x00A0	,0xE64C	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~space><e><e>                                               */ DEADTRANS( L' '	,0xE64C	,0x220B	,0x0000	), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~space>                                                     */ DEADTRANS( L'G'	,0xE60E	,0x27F2	,0x0000	), // 'G' ➔ "⟲" ANTICLOCKWISE GAPPED CIRCLE ARROW
/*<!M><~space>                                                     */ DEADTRANS( L'h'	,0xE60E	,0x266E	,0x0000	), // 'h' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><~space>                                                     */ DEADTRANS( L'I'	,0xE60E	,0x2AE0	,0x0000	), // 'I' ➔ "⫠" SHORT UP TACK
/*<!M><~space>                                                     */ DEADTRANS( L'K'	,0xE60E	,0x212A	,0x0000	), // 'K' ➔ "K" KELVIN SIGN
/*<!M><~space>                                                     */ DEADTRANS( L'k'	,0xE60E	,0x212A	,0x0000	), // 'k' ➔ "K" KELVIN SIGN
/*<!M><~space><n>                                                  */ DEADTRANS( L'|'	,0xE64D	,0x2ADB	,0x0000	), // '|' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><~space><O>                                                  */ DEADTRANS( L'\\'	,0xE64E	,0x29B0	,0x0000	), // '\' ➔ "⦰" REVERSED EMPTY SET
/*<!M><~space><o>                                                  */ DEADTRANS( L'='	,0xE64F	,0x229C	,0x0000	), // '=' ➔ "⊜" CIRCLED EQUALS
/*<!M><~space><o>                                                  */ DEADTRANS( L'>'	,0xE64F	,0x2A7A	,0x0000	), // '>' ➔ "⩺" GREATER-THAN WITH CIRCLE INSIDE
/*<!M><~space><o><%minus>                                          */ DEADTRANS( L'>'	,0xE650	,0x21F4	,0x0000	), // '>' ➔ "⇴" RIGHT ARROW WITH SMALL CIRCLE
/*<!M><~space><o><%minus>                                          */ DEADTRANS( 0x00A0	,0xE650	,0x229D	,0x0000	), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~space><o><%minus>                                          */ DEADTRANS( L' '	,0xE650	,0x229D	,0x0000	), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~space><O>                                                  */ DEADTRANS( L'%'	,0xE64E	,0x29BC	,0x0000	), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~space><o>                                                  */ DEADTRANS( L'%'	,0xE64F	,0x29BC	,0x0000	), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~space><O>                                                  */ DEADTRANS( L'.'	,0xE64E	,0x29BF	,0x0000	), // '.' ➔ "⦿" CIRCLED BULLET
/*<!M><~space><o>                                                  */ DEADTRANS( L'+'	,0xE64F	,0x2640	,0x0000	), // '+' ➔ "♀" FEMALE SIGN
/*<!M><~space><o>                                                  */ DEADTRANS( L';'	,0xE64F	,0x2A3E	,0x0000	), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><o>                                                  */ DEADTRANS( 0x00A7	,0xE64F	,0x2A3E	,0x0000	), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><o>                                                  */ DEADTRANS( L'/'	,0xE64F	,0x2298	,0x0000	), // '/' ➔ "⊘" CIRCLED DIVISION SLASH
/*<!M><~space><o>                                                  */ DEADTRANS( L'8'	,0xE64F	,0x2663	,0x0000	), // '8' ➔ "♣" BLACK CLUB SUIT
/*<!M><~space><O>                                                  */ DEADTRANS( L'o'	,0xE64E	,0x29BE	,0x0000	), // 'o' ➔ "⦾" CIRCLED WHITE BULLET
/*<!M><~space><R>                                                  */ DEADTRANS( L'/'	,0xE651	,0x211E	,0x0000	), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~space><r>                                                  */ DEADTRANS( L'/'	,0xE652	,0x211E	,0x0000	), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~space>                                                     */ DEADTRANS( L's'	,0xE60E	,0x2A0B	,0x0000	), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~space><S>                                                  */ DEADTRANS( L's'	,0xE653	,0x2A0B	,0x0000	), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~space><S><S>                                               */ DEADTRANS( L'@'	,0xE654	,0x2140	,0x0000	), // '@' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><S><S>                                               */ DEADTRANS( 0x00A0	,0xE654	,0x2140	,0x0000	), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><S><S>                                               */ DEADTRANS( L' '	,0xE654	,0x2140	,0x0000	), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><T>                                                  */ DEADTRANS( L'%'	,0xE655	,0x2AE0	,0x0000	), // '%' ➔ "⫠" SHORT UP TACK
/*<!M><~space><T>                                                  */ DEADTRANS( L'T'	,0xE655	,0x2AE0	,0x0000	), // 'T' ➔ "⫠" SHORT UP TACK
/*<!M><~space><T>                                                  */ DEADTRANS( 0x00A0	,0xE655	,0x2ADF	,0x0000	), // ' ' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><T>                                                  */ DEADTRANS( L' '	,0xE655	,0x2ADF	,0x0000	), // ' ' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space>                                                     */ DEADTRANS( L'v'	,0xE60E	,0x2A56	,0x0000	), // 'v' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><~space><V>                                                  */ DEADTRANS( L'V'	,0xE656	,0x2A08	,0x0000	), // 'V' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><~space>                                                     */ DEADTRANS( L'x'	,0xE60E	,0x2A2F	,0x0000	), // 'x' ➔ "⨯" VECTOR OR CROSS PRODUCT
/*<!M><~space><Y>                                                  */ DEADTRANS( L'-'	,0xE657	,0x297C	,0x0000	), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><~space>                                                     */ DEADTRANS( L'z'	,0xE60E	,0x2A3E	,0x0000	), // 'z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space>                                                     */ DEADTRANS( L'Z'	,0xE60E	,0x2A3E	,0x0000	), // 'Z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space>                                                     */ DEADTRANS( 0x00A0	,0xE60E	,0x237D	,0x0000	), // ' ' ➔ "⍽" SHOULDERED OPEN BOX
/*<!M><~space><~space>                                             */ DEADTRANS( L'*'	,0xE658	,0x22C6	,0x0000	), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~space><~space><%backslash>                                 */ DEADTRANS( L'/'	,0xE659	,0x25C1	,0x0000	), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~space><~space><%backslash>                                 */ DEADTRANS( 0x00A0	,0xE659	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~space><~space><%backslash>                                 */ DEADTRANS( L' '	,0xE659	,0x29F9	,0x0000	), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~space><~space><%bar>                                       */ DEADTRANS( L'|'	,0xE65A	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~space><~space><%bar>                                       */ DEADTRANS( 0x00A0	,0xE65A	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~space><~space><%bar>                                       */ DEADTRANS( L' '	,0xE65A	,0x2AFE	,0x0000	), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~space><~space><%bracketleft>                               */ DEADTRANS( L']'	,0xE65B	,0x25FD	,0x0000	), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~space><~space><%bracketleft>                               */ DEADTRANS( L'#'	,0xE65B	,0x25FE	,0x0000	), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~space><~space><%bracketright>                              */ DEADTRANS( L'['	,0xE65C	,0x25FD	,0x0000	), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~space><~space>                                             */ DEADTRANS( L':'	,0xE658	,0x2982	,0x0000	), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~space><~space><%equal>                                     */ DEADTRANS( L'='	,0xE65D	,0x2263	,0x0000	), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~space><~space><%greater>                                   */ DEADTRANS( L'<'	,0xE65E	,0x2AA5	,0x0000	), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~space><~space><%greater>                                   */ DEADTRANS( L'-'	,0xE65E	,0x2B43	,0x0000	), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~space><~space>                                             */ DEADTRANS( L'#'	,0xE658	,0x29E3	,0x0000	), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~space><~space><%less>                                      */ DEADTRANS( L'>'	,0xE65F	,0x25C7	,0x0000	), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~space><~space><%less>                                      */ DEADTRANS( L'o'	,0xE65F	,0x2A79	,0x0000	), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~space><~space><%minus>                                     */ DEADTRANS( L'\''	,0xE660	,0x21C1	,0x0000	), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~space><~space><%minus>                                     */ DEADTRANS( 0x2019	,0xE660	,0x21C1	,0x0000	), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~space><~space><%minus>                                     */ DEADTRANS( L'/'	,0xE660	,0x299F	,0x0000	), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~space><~space>                                             */ DEADTRANS( L'.'	,0xE658	,0x2219	,0x0000	), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~space><~space>                                             */ DEADTRANS( L';'	,0xE658	,0x2A3E	,0x0000	), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><~space>                                             */ DEADTRANS( 0x00A7	,0xE658	,0x2A3E	,0x0000	), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( L'\\'	,0xE661	,0x25C1	,0x0000	), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( L'-'	,0xE661	,0x29A7	,0x0000	), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( 0x00A0	,0xE661	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( L' '	,0xE661	,0x29F8	,0x0000	), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~space><~space>                                             */ DEADTRANS( L'_'	,0xE658	,0x2A4C	,0x0000	), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~space><~space><3>                                          */ DEADTRANS( L'|'	,0xE662	,0x2AFC	,0x0000	), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~space><~space>                                             */ DEADTRANS( L'8'	,0xE658	,0x29DC	,0x0000	), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~space><~space>                                             */ DEADTRANS( L'I'	,0xE658	,0x27D8	,0x0000	), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space>                                             */ DEADTRANS( L'O'	,0xE658	,0x29C2	,0x0000	), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~space><~space><o>                                          */ DEADTRANS( L'-'	,0xE663	,0x27DC	,0x0000	), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~space><~space><o>                                          */ DEADTRANS( L'+'	,0xE663	,0x2A22	,0x0000	), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~space><~space><T>                                          */ DEADTRANS( L'%'	,0xE664	,0x27D8	,0x0000	), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space><T>                                          */ DEADTRANS( L'T'	,0xE664	,0x27D8	,0x0000	), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space><T>                                          */ DEADTRANS( 0x00A0	,0xE664	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~space><~space><T>                                          */ DEADTRANS( L' '	,0xE664	,0x27D9	,0x0000	), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~space><~space><~space><%asterisk>                          */ DEADTRANS( L'#'	,0xE665	,0x2605	,0x0000	), // '#' ➔ "★" BLACK STAR
/*<!M><~space><~space><~space><%asterisk>                          */ DEADTRANS( 0x00A0	,0xE665	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~space><~space><~space><%asterisk>                          */ DEADTRANS( L' '	,0xE665	,0x2606	,0x0000	), // ' ' ➔ "☆" WHITE STAR
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L'\\'	,0xE666	,0x27CD	,0x0000	), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L'|'	,0xE666	,0x2AFF	,0x0000	), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L'<'	,0xE666	,0x2662	,0x0000	), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L'/'	,0xE666	,0x27CB	,0x0000	), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L'o'	,0xE666	,0xDEF0	,0x0000	), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~space><~space><~space><~space>                             */ DEADTRANS( L'\\'	,0xE667	,0x29F5	,0x0000	), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~space><~space><~space><~space>                             */ DEADTRANS( L'/'	,0xE667	,0x2044	,0x0000	), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><%ampersand><%apostrophe>                                    */ DEADTRANS( L'\''	,0xE200	,0xE200	,0x0001), // Multikey chain.
/*<!M><%ampersand><%aprightsinglequotemark>                        */ DEADTRANS( 0x2019	,0xE201	,0xE201	,0x0001), // Multikey chain.
/*<!M><%ampersand><%bar>                                           */ DEADTRANS( L'|'	,0xE203	,0xE203	,0x0001), // Multikey chain.
/*<!M><%ampersand><%less><%minus>                                  */ DEADTRANS( L'-'	,0xE204	,0xE204	,0x0001), // Multikey chain.
/*<!M><%ampersand><%less>                                          */ DEADTRANS( L'<'	,0xE205	,0xE205	,0x0001), // Multikey chain.
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( L'-'	,0xE206	,0xE206	,0x0001), // Multikey chain.
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L'.'	,0xE207	,0xE207	,0x0001), // Multikey chain.
/*<!M><%ampersand><%underscore>                                    */ DEADTRANS( L'_'	,0xE208	,0xE208	,0x0001), // Multikey chain.
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'a'	,0xE209	,0xE209	,0x0001), // Multikey chain.
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( L'>'	,0xE20A	,0xE20A	,0x0001), // Multikey chain.
/*<!M><%ampersand><o>                                              */ DEADTRANS( L'o'	,0xE20B	,0xE20B	,0x0001), // Multikey chain.
/*<!M><%ampersand><u>                                              */ DEADTRANS( L'u'	,0xE20C	,0xE20C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%equal>                                        */ DEADTRANS( L'='	,0xE20D	,0xE20D	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L'!'	,0xE20E	,0xE20E	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%grave>                               */ DEADTRANS( L'`'	,0xE20F	,0xE20F	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'-'	,0xE210	,0xE210	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%minus><%grave>                                */ DEADTRANS( L'`'	,0xE211	,0xE211	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'-'	,0xE212	,0xE212	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%equal>                            */ DEADTRANS( L'='	,0xE213	,0xE213	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%exclam>                           */ DEADTRANS( L'!'	,0xE214	,0xE214	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%exclam><%grave>                   */ DEADTRANS( L'`'	,0xE215	,0xE215	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%minus>                            */ DEADTRANS( L'-'	,0xE216	,0xE216	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%minus><%grave>                    */ DEADTRANS( L'`'	,0xE217	,0xE217	,0x0001), // Multikey chain.
/*<!M><%aprightsinglequotemark><%minus><%minus>                    */ DEADTRANS( L'-'	,0xE218	,0xE218	,0x0001), // Multikey chain.
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L'/'	,0xE21B	,0xE21B	,0x0001), // Multikey chain.
/*<!M><%backslash><%bar>                                           */ DEADTRANS( L'|'	,0xE21C	,0xE21C	,0x0001), // Multikey chain.
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'>'	,0xE21D	,0xE21D	,0x0001), // Multikey chain.
/*<!M><%backslash><%greater><%parenright>                          */ DEADTRANS( L')'	,0xE21E	,0xE21E	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash>                                          */ DEADTRANS( L'#'	,0xE21F	,0xE21F	,0x0001), // Multikey chain.
/*<!M><%backslash><%minus>                                         */ DEADTRANS( L'-'	,0xE220	,0xE220	,0x0001), // Multikey chain.
/*<!M><%backslash><%parenleft>                                     */ DEADTRANS( L'('	,0xE221	,0xE221	,0x0001), // Multikey chain.
/*<!M><%backslash><%parenright>                                    */ DEADTRANS( L')'	,0xE222	,0xE222	,0x0001), // Multikey chain.
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'/'	,0xE223	,0xE223	,0x0001), // Multikey chain.
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'_'	,0xE224	,0xE224	,0x0001), // Multikey chain.
/*<!M><%backslash><%underscore>                                    */ DEADTRANS( L'_'	,0xE225	,0xE225	,0x0001), // Multikey chain.
/*<!M><%bar><%apostrophe>                                          */ DEADTRANS( L'\''	,0xE226	,0xE226	,0x0001), // Multikey chain.
/*<!M><%bar><%aprightsinglequotemark>                              */ DEADTRANS( 0x2019	,0xE227	,0xE227	,0x0001), // Multikey chain.
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L'/'	,0xE228	,0xE228	,0x0001), // Multikey chain.
/*<!M><%bar><%backslash>                                           */ DEADTRANS( L'\\'	,0xE229	,0xE229	,0x0001), // Multikey chain.
/*<!M><%bar><%bar><%bar>                                           */ DEADTRANS( L'|'	,0xE22A	,0xE22A	,0x0001), // Multikey chain.
/*<!M><%bar><%bar><%equal>                                         */ DEADTRANS( L'='	,0xE22B	,0xE22B	,0x0001), // Multikey chain.
/*<!M><%bar><%bar>                                                 */ DEADTRANS( L'|'	,0xE22C	,0xE22C	,0x0001), // Multikey chain.
/*<!M><%bar><%bar><%minus>                                         */ DEADTRANS( L'-'	,0xE22D	,0xE22D	,0x0001), // Multikey chain.
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'='	,0xE22E	,0xE22E	,0x0001), // Multikey chain.
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( L'='	,0xE22F	,0xE22F	,0x0001), // Multikey chain.
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'!'	,0xE230	,0xE230	,0x0001), // Multikey chain.
/*<!M><%bar><%grave>                                               */ DEADTRANS( L'`'	,0xE231	,0xE231	,0x0001), // Multikey chain.
/*<!M><%bar><%greater>                                             */ DEADTRANS( L'>'	,0xE232	,0xE232	,0x0001), // Multikey chain.
/*<!M><%bar><%greater><%slash>                                     */ DEADTRANS( L'/'	,0xE233	,0xE233	,0x0001), // Multikey chain.
/*<!M><%bar><%greater><%underscore>                                */ DEADTRANS( L'_'	,0xE234	,0xE234	,0x0001), // Multikey chain.
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( L'/'	,0xE235	,0xE235	,0x0001), // Multikey chain.
/*<!M><%bar><%hash><%backslash>                                    */ DEADTRANS( L'\\'	,0xE236	,0xE236	,0x0001), // Multikey chain.
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( L'\\'	,0xE237	,0xE237	,0x0001), // Multikey chain.
/*<!M><%bar><%hash><%slash>                                        */ DEADTRANS( L'/'	,0xE238	,0xE238	,0x0001), // Multikey chain.
/*<!M><%bar><%hash><%underscore>                                   */ DEADTRANS( L'_'	,0xE239	,0xE239	,0x0001), // Multikey chain.
/*<!M><%bar><%less>                                                */ DEADTRANS( L'<'	,0xE23A	,0xE23A	,0x0001), // Multikey chain.
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'-'	,0xE23B	,0xE23B	,0x0001), // Multikey chain.
/*<!M><%bar><%minus><%bar>                                         */ DEADTRANS( L'|'	,0xE23C	,0xE23C	,0x0001), // Multikey chain.
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( L'>'	,0xE23D	,0xE23D	,0x0001), // Multikey chain.
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( L'-'	,0xE23E	,0xE23E	,0x0001), // Multikey chain.
/*<!M><%bar><%minus><%minus><%minus>                               */ DEADTRANS( L'-'	,0xE23F	,0xE23F	,0x0001), // Multikey chain.
/*<!M><%bar><%parenright>                                          */ DEADTRANS( L')'	,0xE241	,0xE241	,0x0001), // Multikey chain.
/*<!M><%bar><%period>                                              */ DEADTRANS( L'.'	,0xE242	,0xE242	,0x0001), // Multikey chain.
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L'\\'	,0xE243	,0xE243	,0x0001), // Multikey chain.
/*<!M><%bar><%slash>                                               */ DEADTRANS( L'/'	,0xE244	,0xE244	,0x0001), // Multikey chain.
/*<!M><%bar><%tilde>                                               */ DEADTRANS( L'~'	,0xE245	,0xE245	,0x0001), // Multikey chain.
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L'_'	,0xE246	,0xE246	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE247	,0xE247	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%backslash>                                   */ DEADTRANS( L'\\'	,0xE249	,0xE249	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%backslash><%colon>                           */ DEADTRANS( L':'	,0xE24A	,0xE24A	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%backslash><%minus>                           */ DEADTRANS( L'-'	,0xE24B	,0xE24B	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%bar>                                         */ DEADTRANS( L'|'	,0xE24C	,0xE24C	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%bracketleft>                                 */ DEADTRANS( L'['	,0xE24D	,0xE24D	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L']'	,0xE24E	,0xE24E	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%hash>                                        */ DEADTRANS( L'#'	,0xE24F	,0xE24F	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L']'	,0xE250	,0xE250	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%minus><%backslash>                           */ DEADTRANS( L'\\'	,0xE251	,0xE251	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%minus>                                       */ DEADTRANS( L'-'	,0xE252	,0xE252	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%slash>                                       */ DEADTRANS( L'/'	,0xE253	,0xE253	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%slash><%colon>                               */ DEADTRANS( L':'	,0xE254	,0xE254	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%slash><%minus>                               */ DEADTRANS( L'-'	,0xE255	,0xE255	,0x0001), // Multikey chain.
/*<!M><%bracketleft><%underscore>                                  */ DEADTRANS( L'_'	,0xE256	,0xE256	,0x0001), // Multikey chain.
/*<!M><%bracketleft><V>                                            */ DEADTRANS( L'V'	,0xE257	,0xE257	,0x0001), // Multikey chain.
/*<!M><%bracketleft><v>                                            */ DEADTRANS( L'v'	,0xE258	,0xE258	,0x0001), // Multikey chain.
/*<!M><%bracketleft><X>                                            */ DEADTRANS( L'X'	,0xE259	,0xE259	,0x0001), // Multikey chain.
/*<!M><%bracketleft><X><L>                                         */ DEADTRANS( L'L'	,0xE25A	,0xE25A	,0x0001), // Multikey chain.
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'/'	,0xE25C	,0xE25C	,0x0001), // Multikey chain.
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'['	,0xE25D	,0xE25D	,0x0001), // Multikey chain.
/*<!M><%bracketright><%bracketright>                               */ DEADTRANS( L']'	,0xE25E	,0xE25E	,0x0001), // Multikey chain.
/*<!M><%bracketright><%parenright>                                 */ DEADTRANS( L')'	,0xE25F	,0xE25F	,0x0001), // Multikey chain.
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'\\'	,0xE260	,0xE260	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><%braceleft><%braceleft>                */ DEADTRANS( L'{'	,0xE261	,0xE261	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><%braceleft>                            */ DEADTRANS( L'{'	,0xE262	,0xE262	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><%braceright>                           */ DEADTRANS( L'}'	,0xE263	,0xE263	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand>                                        */ DEADTRANS( L'&'	,0xE264	,0xE264	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><A>                                     */ DEADTRANS( L'A'	,0xE265	,0xE265	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><d>                                     */ DEADTRANS( L'd'	,0xE266	,0xE266	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><f>                                     */ DEADTRANS( L'f'	,0xE267	,0xE267	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><l>                                     */ DEADTRANS( L'l'	,0xE268	,0xE268	,0x0001), // Multikey chain.
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L't'	,0xE269	,0xE269	,0x0001), // Multikey chain.
/*<!M><%circum><%hash>                                             */ DEADTRANS( L'#'	,0xE26B	,0xE26B	,0x0001), // Multikey chain.
/*<!M><%circum><%tilde>                                            */ DEADTRANS( L'~'	,0xE26C	,0xE26C	,0x0001), // Multikey chain.
/*<!M><%colon><%colon><%equal>                                     */ DEADTRANS( L'='	,0xE26D	,0xE26D	,0x0001), // Multikey chain.
/*<!M><%colon><%minus>                                             */ DEADTRANS( L'-'	,0xE26F	,0xE26F	,0x0001), // Multikey chain.
/*<!M><%equal><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE271	,0xE271	,0x0001), // Multikey chain.
/*<!M><%equal><%aprightsinglequotemark>                            */ DEADTRANS( 0x2019	,0xE272	,0xE272	,0x0001), // Multikey chain.
/*<!M><%equal><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE273	,0xE273	,0x0001), // Multikey chain.
/*<!M><%equal><%bar>                                               */ DEADTRANS( L'|'	,0xE274	,0xE274	,0x0001), // Multikey chain.
/*<!M><%equal><%equal><%equal>                                     */ DEADTRANS( L'='	,0xE276	,0xE276	,0x0001), // Multikey chain.
/*<!M><%equal><%equal>                                             */ DEADTRANS( L'='	,0xE277	,0xE277	,0x0001), // Multikey chain.
/*<!M><%equal><%greater>                                           */ DEADTRANS( L'>'	,0xE278	,0xE278	,0x0001), // Multikey chain.
/*<!M><%equal><%less>                                              */ DEADTRANS( L'<'	,0xE279	,0xE279	,0x0001), // Multikey chain.
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE27A	,0xE27A	,0x0001), // Multikey chain.
/*<!M><%equal><%minus><%slash>                                     */ DEADTRANS( L'/'	,0xE27B	,0xE27B	,0x0001), // Multikey chain.
/*<!M><%equal><%minus>                                             */ DEADTRANS( L'-'	,0xE27C	,0xE27C	,0x0001), // Multikey chain.
/*<!M><%equal><%slash>                                             */ DEADTRANS( L'/'	,0xE27D	,0xE27D	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe>                                       */ DEADTRANS( L'\''	,0xE27E	,0xE27E	,0x0001), // Multikey chain.
/*<!M><%exclam><%aprightsinglequotemark>                           */ DEADTRANS( 0x2019	,0xE27F	,0xE27F	,0x0001), // Multikey chain.
/*<!M><%exclam><%bar>                                              */ DEADTRANS( L'|'	,0xE280	,0xE280	,0x0001), // Multikey chain.
/*<!M><%exclam><%exclam>                                           */ DEADTRANS( L'!'	,0xE282	,0xE282	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave>                                            */ DEADTRANS( L'`'	,0xE283	,0xE283	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%exclam>                                   */ DEADTRANS( L'!'	,0xE284	,0xE284	,0x0001), // Multikey chain.
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'>'	,0xE285	,0xE285	,0x0001), // Multikey chain.
/*<!M><%exclam><%greater><%greater>                                */ DEADTRANS( L'>'	,0xE286	,0xE286	,0x0001), // Multikey chain.
/*<!M><%exclam><%minus>                                            */ DEADTRANS( L'-'	,0xE287	,0xE287	,0x0001), // Multikey chain.
/*<!M><%exclam>comma><%minus>                                      */ DEADTRANS( L'-'	,0xE288	,0xE288	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L'!'	,0xE289	,0xE289	,0x0001), // Multikey chain.
/*<!M><%grave><%minus>                                             */ DEADTRANS( L'-'	,0xE28A	,0xE28A	,0x0001), // Multikey chain.
/*<!M><%grave><%minus><%minus>                                     */ DEADTRANS( L'-'	,0xE28B	,0xE28B	,0x0001), // Multikey chain.
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xE28C	,0xE28C	,0x0001), // Multikey chain.
/*<!M><%greater><%equal>                                           */ DEADTRANS( L'='	,0xE28E	,0xE28E	,0x0001), // Multikey chain.
/*<!M><%greater><%greater>                                         */ DEADTRANS( L'>'	,0xE28F	,0xE28F	,0x0001), // Multikey chain.
/*<!M><%greater><%less>                                            */ DEADTRANS( L'<'	,0xE290	,0xE290	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE291	,0xE291	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE292	,0xE292	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L'>'	,0xE293	,0xE293	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L'>'	,0xE294	,0xE294	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L'>'	,0xE295	,0xE295	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L'>'	,0xE296	,0xE296	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%greater>                                 */ DEADTRANS( L'>'	,0xE297	,0xE297	,0x0001), // Multikey chain.
/*<!M><%greater><%minus>                                           */ DEADTRANS( L'-'	,0xE298	,0xE298	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft>                                       */ DEADTRANS( L'('	,0xE299	,0xE299	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L')'	,0xE29A	,0xE29A	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft><%parenright><%equal>                  */ DEADTRANS( L'='	,0xE29B	,0xE29B	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft><%parenright><%tilde>                  */ DEADTRANS( L'~'	,0xE29C	,0xE29C	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde>          */ DEADTRANS( L'~'	,0xE29D	,0xE29D	,0x0001), // Multikey chain.
/*<!M><%greater><%parenleft><%parenright><%underscore>             */ DEADTRANS( L'_'	,0xE29E	,0xE29E	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'('	,0xE29F	,0xE29F	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft><%equal>                  */ DEADTRANS( L'='	,0xE2A0	,0xE2A0	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft><%tilde>                  */ DEADTRANS( L'~'	,0xE2A1	,0xE2A1	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde>          */ DEADTRANS( L'~'	,0xE2A2	,0xE2A2	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft><%underscore>             */ DEADTRANS( L'_'	,0xE2A3	,0xE2A3	,0x0001), // Multikey chain.
/*<!M><%greater><%period>                                          */ DEADTRANS( L'.'	,0xE2A4	,0xE2A4	,0x0001), // Multikey chain.
/*<!M><%greater><%slash>                                           */ DEADTRANS( L'/'	,0xE2A5	,0xE2A5	,0x0001), // Multikey chain.
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'~'	,0xE2A6	,0xE2A6	,0x0001), // Multikey chain.
/*<!M><%greater><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xE2A7	,0xE2A7	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L'_'	,0xE2A8	,0xE2A8	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%less>                               */ DEADTRANS( L'<'	,0xE2A9	,0xE2A9	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L')'	,0xE2AA	,0xE2AA	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L'('	,0xE2AB	,0xE2AB	,0x0001), // Multikey chain.
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'\\'	,0xE2AC	,0xE2AC	,0x0001), // Multikey chain.
/*<!M><%less><%backslash><%parenleft>                              */ DEADTRANS( L'('	,0xE2AD	,0xE2AD	,0x0001), // Multikey chain.
/*<!M><%less><%bar><%bar><%minus>                                  */ DEADTRANS( L'-'	,0xE2AE	,0xE2AE	,0x0001), // Multikey chain.
/*<!M><%less><%bar><%bar>                                          */ DEADTRANS( L'|'	,0xE2AF	,0xE2AF	,0x0001), // Multikey chain.
/*<!M><%less><%bar>                                                */ DEADTRANS( L'|'	,0xE2B0	,0xE2B0	,0x0001), // Multikey chain.
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( L'-'	,0xE2B1	,0xE2B1	,0x0001), // Multikey chain.
/*<!M><%less><%bar><%slash>                                        */ DEADTRANS( L'/'	,0xE2B2	,0xE2B2	,0x0001), // Multikey chain.
/*<!M><%less><%bar><%underscore>                                   */ DEADTRANS( L'_'	,0xE2B3	,0xE2B3	,0x0001), // Multikey chain.
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'['	,0xE2B4	,0xE2B4	,0x0001), // Multikey chain.
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L']'	,0xE2B5	,0xE2B5	,0x0001), // Multikey chain.
/*<!M><%less><%equal><%bar><%equal>                                */ DEADTRANS( L'='	,0xE2B6	,0xE2B6	,0x0001), // Multikey chain.
/*<!M><%less><%equal><%bar>                                        */ DEADTRANS( L'|'	,0xE2B7	,0xE2B7	,0x0001), // Multikey chain.
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( L'='	,0xE2B8	,0xE2B8	,0x0001), // Multikey chain.
/*<!M><%less><%equal>                                              */ DEADTRANS( L'='	,0xE2B9	,0xE2B9	,0x0001), // Multikey chain.
/*<!M><%less><%equal><%slash>                                      */ DEADTRANS( L'/'	,0xE2BA	,0xE2BA	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%bar>                                       */ DEADTRANS( L'|'	,0xE2BB	,0xE2BB	,0x0001), // Multikey chain.
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'!'	,0xE2BC	,0xE2BC	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L'>'	,0xE2BD	,0xE2BD	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%less>                                      */ DEADTRANS( L'<'	,0xE2BE	,0xE2BE	,0x0001), // Multikey chain.
/*<!M><%less><%greater>                                            */ DEADTRANS( L'>'	,0xE2BF	,0xE2BF	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L'-'	,0xE2C0	,0xE2C0	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE2C1	,0xE2C1	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE2C2	,0xE2C2	,0x0001), // Multikey chain.
/*<!M><%less><%hash><%greater>                                     */ DEADTRANS( L'>'	,0xE2C3	,0xE2C3	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L'-'	,0xE2C4	,0xE2C4	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE2C5	,0xE2C5	,0x0001), // Multikey chain.
/*<!M><%less><%less>                                               */ DEADTRANS( L'<'	,0xE2C6	,0xE2C6	,0x0001), // Multikey chain.
/*<!M><%less><%less><%exclam>                                      */ DEADTRANS( L'!'	,0xE2C7	,0xE2C7	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L'-'	,0xE2C8	,0xE2C8	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L'-'	,0xE2C9	,0xE2C9	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( L'-'	,0xE2CA	,0xE2CA	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( L'-'	,0xE2CB	,0xE2CB	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%bar><%bar>                                  */ DEADTRANS( L'|'	,0xE2CC	,0xE2CC	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%bar>                                        */ DEADTRANS( L'|'	,0xE2CD	,0xE2CD	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( L'-'	,0xE2CE	,0xE2CE	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%comma>                                      */ DEADTRANS( L','	,0xE2CF	,0xE2CF	,0x0001), // Multikey chain.
/*<!M><%less><%minus>                                              */ DEADTRANS( L'-'	,0xE2D0	,0xE2D0	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%less><%minus>                               */ DEADTRANS( L'-'	,0xE2D1	,0xE2D1	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%less>                                       */ DEADTRANS( L'<'	,0xE2D2	,0xE2D2	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( L'-'	,0xE2D3	,0xE2D3	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%slash>                                      */ DEADTRANS( L'/'	,0xE2D4	,0xE2D4	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%tilde>                                      */ DEADTRANS( L'~'	,0xE2D5	,0xE2D5	,0x0001), // Multikey chain.
/*<!M><%less><%minus><%tilde><%tilde>                              */ DEADTRANS( L'~'	,0xE2D6	,0xE2D6	,0x0001), // Multikey chain.
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L'-'	,0xE2D7	,0xE2D7	,0x0001), // Multikey chain.
/*<!M><%less><%minus><O>                                           */ DEADTRANS( L'O'	,0xE2D8	,0xE2D8	,0x0001), // Multikey chain.
/*<!M><%less><%minus><o><%minus>                                   */ DEADTRANS( L'-'	,0xE2D9	,0xE2D9	,0x0001), // Multikey chain.
/*<!M><%less><%minus><o>                                           */ DEADTRANS( L'o'	,0xE2DA	,0xE2DA	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L')'	,0xE2DB	,0xE2DB	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%parenright><%equal>                     */ DEADTRANS( L'='	,0xE2DC	,0xE2DC	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%parenright><%tilde>                     */ DEADTRANS( L'~'	,0xE2DD	,0xE2DD	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde>             */ DEADTRANS( L'~'	,0xE2DE	,0xE2DE	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%parenright><%underscore>                */ DEADTRANS( L'_'	,0xE2DF	,0xE2DF	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft>                                          */ DEADTRANS( L'('	,0xE2E0	,0xE2E0	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L'('	,0xE2E1	,0xE2E1	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%parenleft><%equal>                     */ DEADTRANS( L'='	,0xE2E2	,0xE2E2	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%parenleft><%tilde>                     */ DEADTRANS( L'~'	,0xE2E3	,0xE2E3	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde>             */ DEADTRANS( L'~'	,0xE2E4	,0xE2E4	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%parenleft><%underscore>                */ DEADTRANS( L'_'	,0xE2E5	,0xE2E5	,0x0001), // Multikey chain.
/*<!M><%less><%parenright>                                         */ DEADTRANS( L')'	,0xE2E6	,0xE2E6	,0x0001), // Multikey chain.
/*<!M><%less><%period>                                             */ DEADTRANS( L'.'	,0xE2E7	,0xE2E7	,0x0001), // Multikey chain.
/*<!M><%less><%slash>                                              */ DEADTRANS( L'/'	,0xE2E8	,0xE2E8	,0x0001), // Multikey chain.
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'~'	,0xE2E9	,0xE2E9	,0x0001), // Multikey chain.
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( L'~'	,0xE2EA	,0xE2EA	,0x0001), // Multikey chain.
/*<!M><%less><%underscore>                                         */ DEADTRANS( L'_'	,0xE2EB	,0xE2EB	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%greater>                               */ DEADTRANS( L'>'	,0xE2EC	,0xE2EC	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L')'	,0xE2ED	,0xE2ED	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L'('	,0xE2EE	,0xE2EE	,0x0001), // Multikey chain.
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE2F0	,0xE2F0	,0x0001), // Multikey chain.
/*<!M><%minus><%aprightsinglequotemark>                            */ DEADTRANS( 0x2019	,0xE2F1	,0xE2F1	,0x0001), // Multikey chain.
/*<!M><%minus><%backslash>                                         */ DEADTRANS( L'\\'	,0xE2F2	,0xE2F2	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%bar><%greater>                               */ DEADTRANS( L'>'	,0xE2F3	,0xE2F3	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%bar><%minus><%greater>                       */ DEADTRANS( L'>'	,0xE2F4	,0xE2F4	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE2F5	,0xE2F5	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE2F6	,0xE2F6	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%greater>                                     */ DEADTRANS( L'>'	,0xE2F7	,0xE2F7	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE2F8	,0xE2F8	,0x0001), // Multikey chain.
/*<!M><%minus><%bar>                                               */ DEADTRANS( L'|'	,0xE2F9	,0xE2F9	,0x0001), // Multikey chain.
/*<!M><%minus><%circum>                                            */ DEADTRANS( L'^'	,0xE2FA	,0xE2FA	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%exclam>                                    */ DEADTRANS( L'!'	,0xE2FC	,0xE2FC	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%less>                                      */ DEADTRANS( L'<'	,0xE2FD	,0xE2FD	,0x0001), // Multikey chain.
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE2FE	,0xE2FE	,0x0001), // Multikey chain.
/*<!M><%minus><%equal>                                             */ DEADTRANS( L'='	,0xE2FF	,0xE2FF	,0x0001), // Multikey chain.
/*<!M><%minus><%equal><%slash>                                     */ DEADTRANS( L'/'	,0xE300	,0xE300	,0x0001), // Multikey chain.
/*<!M><%minus><%grave>                                             */ DEADTRANS( L'`'	,0xE301	,0xE301	,0x0001), // Multikey chain.
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L'-'	,0xE302	,0xE302	,0x0001), // Multikey chain.
/*<!M><%minus><%grave><%minus>                                     */ DEADTRANS( L'-'	,0xE303	,0xE303	,0x0001), // Multikey chain.
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'>'	,0xE304	,0xE304	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%greater>                                 */ DEADTRANS( L'>'	,0xE305	,0xE305	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'<'	,0xE306	,0xE306	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L'>'	,0xE307	,0xE307	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%tilde>                                   */ DEADTRANS( L'~'	,0xE308	,0xE308	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%tilde><%tilde>                           */ DEADTRANS( L'~'	,0xE309	,0xE309	,0x0001), // Multikey chain.
/*<!M><%minus><%less>                                              */ DEADTRANS( L'<'	,0xE30A	,0xE30A	,0x0001), // Multikey chain.
/*<!M><%minus><%minus>                                             */ DEADTRANS( L'-'	,0xE30B	,0xE30B	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L'-'	,0xE30C	,0xE30C	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%greater>                                   */ DEADTRANS( L'>'	,0xE30D	,0xE30D	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%minus>                                     */ DEADTRANS( L'-'	,0xE30E	,0xE30E	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L'-'	,0xE30F	,0xE30F	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%minus><%greater>                           */ DEADTRANS( L'>'	,0xE310	,0xE310	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><v>                                          */ DEADTRANS( L'v'	,0xE311	,0xE311	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><V>                                          */ DEADTRANS( L'V'	,0xE312	,0xE312	,0x0001), // Multikey chain.
/*<!M><%minus><%parenleft>                                         */ DEADTRANS( L'('	,0xE313	,0xE313	,0x0001), // Multikey chain.
/*<!M><%minus><%parenright>                                        */ DEADTRANS( L')'	,0xE314	,0xE314	,0x0001), // Multikey chain.
/*<!M><%minus><%parenright><%slash>                                */ DEADTRANS( L'/'	,0xE315	,0xE315	,0x0001), // Multikey chain.
/*<!M><%minus><%period>                                            */ DEADTRANS( L'.'	,0xE316	,0xE316	,0x0001), // Multikey chain.
/*<!M><%minus><%slash>                                             */ DEADTRANS( L'/'	,0xE317	,0xE317	,0x0001), // Multikey chain.
/*<!M><%minus><%underscore>                                        */ DEADTRANS( L'_'	,0xE318	,0xE318	,0x0001), // Multikey chain.
/*<!M><%minus><0><%minus>                                          */ DEADTRANS( L'-'	,0xE319	,0xE319	,0x0001), // Multikey chain.
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L'>'	,0xE31A	,0xE31A	,0x0001), // Multikey chain.
/*<!M><%minus><x>                                                  */ DEADTRANS( L'x'	,0xE31B	,0xE31B	,0x0001), // Multikey chain.
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L'>'	,0xE31D	,0xE31D	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less>                                          */ DEADTRANS( L'<'	,0xE31E	,0xE31E	,0x0001), // Multikey chain.
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( L'-'	,0xE31F	,0xE31F	,0x0001), // Multikey chain.
/*<!M><%parenleft><%parenleft>                                     */ DEADTRANS( L'('	,0xE320	,0xE320	,0x0001), // Multikey chain.
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L')'	,0xE321	,0xE321	,0x0001), // Multikey chain.
/*<!M><%parenleft><%underscore>                                    */ DEADTRANS( L'_'	,0xE322	,0xE322	,0x0001), // Multikey chain.
/*<!M><%parenleft><0>                                              */ DEADTRANS( L'0'	,0xE323	,0xE323	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><0><1>                                        */ DEADTRANS( L'1'	,0xE324	,0xE324	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><1><1>                                        */ DEADTRANS( L'1'	,0xE325	,0xE325	,0x0001), // Multikey chain.
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'1'	,0xE326	,0xE326	,0x0001), // Multikey chain.
/*<!M><%parenleft><1><0>                                           */ DEADTRANS( L'0'	,0xE327	,0xE327	,0x0001), // Multikey chain.
/*<!M><%parenleft><1><0><0>                                        */ DEADTRANS( L'0'	,0xE328	,0xE328	,0x0001), // Multikey chain.
/*<!M><%parenleft><1><1>                                           */ DEADTRANS( L'1'	,0xE329	,0xE329	,0x0001), // Multikey chain.
/*<!M><%parenleft><1><1><0>                                        */ DEADTRANS( L'0'	,0xE32A	,0xE32A	,0x0001), // Multikey chain.
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'2'	,0xE32B	,0xE32B	,0x0001), // Multikey chain.
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'3'	,0xE32C	,0xE32C	,0x0001), // Multikey chain.
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'4'	,0xE32D	,0xE32D	,0x0001), // Multikey chain.
/*<!M><%parenleft><5>                                              */ DEADTRANS( L'5'	,0xE32E	,0xE32E	,0x0001), // Multikey chain.
/*<!M><%parenright><%bracketright>                                 */ DEADTRANS( L']'	,0xE32F	,0xE32F	,0x0001), // Multikey chain.
/*<!M><%parenright><%circum>                                       */ DEADTRANS( L'^'	,0xE330	,0xE330	,0x0001), // Multikey chain.
/*<!M><%parenright><%less>                                         */ DEADTRANS( L'<'	,0xE332	,0xE332	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenleft>                                    */ DEADTRANS( L'('	,0xE333	,0xE333	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright>                                   */ DEADTRANS( L')'	,0xE334	,0xE334	,0x0001), // Multikey chain.
/*<!M><%parenright><%underscore><%circum>                          */ DEADTRANS( L'^'	,0xE335	,0xE335	,0x0001), // Multikey chain.
/*<!M><%parenright><%underscore>                                   */ DEADTRANS( L'_'	,0xE336	,0xE336	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'0'	,0xE337	,0xE337	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'1'	,0xE338	,0xE338	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'2'	,0xE339	,0xE339	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'3'	,0xE33A	,0xE33A	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'0'	,0xE33B	,0xE33B	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'1'	,0xE33C	,0xE33C	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'2'	,0xE33D	,0xE33D	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'3'	,0xE33E	,0xE33E	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><0>                                       */ DEADTRANS( L'0'	,0xE33F	,0xE33F	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'1'	,0xE340	,0xE340	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'2'	,0xE341	,0xE341	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'0'	,0xE342	,0xE342	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'1'	,0xE343	,0xE343	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'3'	,0xE344	,0xE344	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'0'	,0xE345	,0xE345	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'1'	,0xE346	,0xE346	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'3'	,0xE347	,0xE347	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'0'	,0xE348	,0xE348	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'1'	,0xE349	,0xE349	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'3'	,0xE34A	,0xE34A	,0x0001), // Multikey chain.
/*<!M><%parenright><1><2><0>                                       */ DEADTRANS( L'0'	,0xE34B	,0xE34B	,0x0001), // Multikey chain.
/*<!M><%parenright><1><2><1>                                       */ DEADTRANS( L'1'	,0xE34C	,0xE34C	,0x0001), // Multikey chain.
/*<!M><%parenright><1><2>                                          */ DEADTRANS( L'2'	,0xE34D	,0xE34D	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'0'	,0xE34E	,0xE34E	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'1'	,0xE34F	,0xE34F	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'3'	,0xE350	,0xE350	,0x0001), // Multikey chain.
/*<!M><%parenright><1>                                             */ DEADTRANS( L'1'	,0xE351	,0xE351	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'0'	,0xE352	,0xE352	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'2'	,0xE353	,0xE353	,0x0001), // Multikey chain.
/*<!M><%parenright><2><1><0>                                       */ DEADTRANS( L'0'	,0xE354	,0xE354	,0x0001), // Multikey chain.
/*<!M><%parenright><2><1><2>                                       */ DEADTRANS( L'2'	,0xE355	,0xE355	,0x0001), // Multikey chain.
/*<!M><%parenright><2><1>                                          */ DEADTRANS( L'1'	,0xE356	,0xE356	,0x0001), // Multikey chain.
/*<!M><%parenright><2><2><0>                                       */ DEADTRANS( L'0'	,0xE357	,0xE357	,0x0001), // Multikey chain.
/*<!M><%parenright><2><2><2>                                       */ DEADTRANS( L'2'	,0xE358	,0xE358	,0x0001), // Multikey chain.
/*<!M><%parenright><2><2>                                          */ DEADTRANS( L'2'	,0xE359	,0xE359	,0x0001), // Multikey chain.
/*<!M><%parenright><2>                                             */ DEADTRANS( L'2'	,0xE35A	,0xE35A	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'0'	,0xE35B	,0xE35B	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'1'	,0xE35C	,0xE35C	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'3'	,0xE35D	,0xE35D	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'0'	,0xE35E	,0xE35E	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'1'	,0xE35F	,0xE35F	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'3'	,0xE360	,0xE360	,0x0001), // Multikey chain.
/*<!M><%parenright><3><3><0>                                       */ DEADTRANS( L'0'	,0xE361	,0xE361	,0x0001), // Multikey chain.
/*<!M><%parenright><3><3><1>                                       */ DEADTRANS( L'1'	,0xE362	,0xE362	,0x0001), // Multikey chain.
/*<!M><%parenright><3><3><3>                                       */ DEADTRANS( L'3'	,0xE363	,0xE363	,0x0001), // Multikey chain.
/*<!M><%parenright><3><3>                                          */ DEADTRANS( L'3'	,0xE364	,0xE364	,0x0001), // Multikey chain.
/*<!M><%parenright><3>                                             */ DEADTRANS( L'3'	,0xE365	,0xE365	,0x0001), // Multikey chain.
/*<!M><%parenright><4><4>                                          */ DEADTRANS( L'4'	,0xE366	,0xE366	,0x0001), // Multikey chain.
/*<!M><%parenright><4>                                             */ DEADTRANS( L'4'	,0xE367	,0xE367	,0x0001), // Multikey chain.
/*<!M><%period><%equal>                                            */ DEADTRANS( L'='	,0xE369	,0xE369	,0x0001), // Multikey chain.
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( L'.'	,0xE36A	,0xE36A	,0x0001), // Multikey chain.
/*<!M><%period><%greater>                                          */ DEADTRANS( L'>'	,0xE36B	,0xE36B	,0x0001), // Multikey chain.
/*<!M><%period><%minus>                                            */ DEADTRANS( L'-'	,0xE36C	,0xE36C	,0x0001), // Multikey chain.
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L'.'	,0xE36D	,0xE36D	,0x0001), // Multikey chain.
/*<!M><%period><%period>                                           */ DEADTRANS( L'.'	,0xE36E	,0xE36E	,0x0001), // Multikey chain.
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'.'	,0xE36F	,0xE36F	,0x0001), // Multikey chain.
/*<!M><%period><%slash>                                            */ DEADTRANS( L'/'	,0xE370	,0xE370	,0x0001), // Multikey chain.
/*<!M><%period><%tilde>                                            */ DEADTRANS( L'~'	,0xE371	,0xE371	,0x0001), // Multikey chain.
/*<!M><%plus><%parenleft>                                          */ DEADTRANS( L'('	,0xE373	,0xE373	,0x0001), // Multikey chain.
/*<!M><%plus><%parenright>                                         */ DEADTRANS( L')'	,0xE374	,0xE374	,0x0001), // Multikey chain.
/*<!M><%plus><%plus>                                               */ DEADTRANS( L'+'	,0xE375	,0xE375	,0x0001), // Multikey chain.
/*<!M><%plus><%tilde>                                              */ DEADTRANS( L'~'	,0xE376	,0xE376	,0x0001), // Multikey chain.
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'\\'	,0xE378	,0xE378	,0x0001), // Multikey chain.
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'_'	,0xE379	,0xE379	,0x0001), // Multikey chain.
/*<!M><%slash><%bar>                                               */ DEADTRANS( L'|'	,0xE37A	,0xE37A	,0x0001), // Multikey chain.
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'>'	,0xE37B	,0xE37B	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><%underscore>                                 */ DEADTRANS( L'_'	,0xE37C	,0xE37C	,0x0001), // Multikey chain.
/*<!M><%slash><%minus>                                             */ DEADTRANS( L'-'	,0xE37D	,0xE37D	,0x0001), // Multikey chain.
/*<!M><%slash><%slash><%backslash>                                 */ DEADTRANS( L'\\'	,0xE37F	,0xE37F	,0x0001), // Multikey chain.
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( L'\\'	,0xE380	,0xE380	,0x0001), // Multikey chain.
/*<!M><%slash><%underscore>                                        */ DEADTRANS( L'_'	,0xE381	,0xE381	,0x0001), // Multikey chain.
/*<!M><%slash><%underscore><%underscore>                           */ DEADTRANS( L'_'	,0xE382	,0xE382	,0x0001), // Multikey chain.
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L'\\'	,0xE383	,0xE383	,0x0001), // Multikey chain.
/*<!M><%tilde><%backslash><%greater>                               */ DEADTRANS( L'>'	,0xE384	,0xE384	,0x0001), // Multikey chain.
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( L'<'	,0xE385	,0xE385	,0x0001), // Multikey chain.
/*<!M><%tilde><%bar>                                               */ DEADTRANS( L'|'	,0xE386	,0xE386	,0x0001), // Multikey chain.
/*<!M><%tilde><%greater>                                           */ DEADTRANS( L'>'	,0xE387	,0xE387	,0x0001), // Multikey chain.
/*<!M><%tilde><%hash>                                              */ DEADTRANS( L'#'	,0xE388	,0xE388	,0x0001), // Multikey chain.
/*<!M><%tilde><%less>                                              */ DEADTRANS( L'<'	,0xE389	,0xE389	,0x0001), // Multikey chain.
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L'-'	,0xE38A	,0xE38A	,0x0001), // Multikey chain.
/*<!M><%tilde><%plus>                                              */ DEADTRANS( L'+'	,0xE38B	,0xE38B	,0x0001), // Multikey chain.
/*<!M><%tilde><%slash>                                             */ DEADTRANS( L'/'	,0xE38C	,0xE38C	,0x0001), // Multikey chain.
/*<!M><%tilde><%tilde>                                             */ DEADTRANS( L'~'	,0xE38D	,0xE38D	,0x0001), // Multikey chain.
/*<!M><%tilde><%tilde><%tilde>                                     */ DEADTRANS( L'~'	,0xE38E	,0xE38E	,0x0001), // Multikey chain.
/*<!M><%underscore><%backslash>                                    */ DEADTRANS( L'\\'	,0xE38F	,0xE38F	,0x0001), // Multikey chain.
/*<!M><%underscore><%backslash><%slash>                            */ DEADTRANS( L'/'	,0xE390	,0xE390	,0x0001), // Multikey chain.
/*<!M><%underscore><%bar>                                          */ DEADTRANS( L'|'	,0xE391	,0xE391	,0x0001), // Multikey chain.
/*<!M><%underscore><%greater>                                      */ DEADTRANS( L'>'	,0xE393	,0xE393	,0x0001), // Multikey chain.
/*<!M><%underscore><%greater><%parenleft>                          */ DEADTRANS( L'('	,0xE394	,0xE394	,0x0001), // Multikey chain.
/*<!M><%underscore><%greater><%parenright>                         */ DEADTRANS( L')'	,0xE395	,0xE395	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L'/'	,0xE396	,0xE396	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L'\\'	,0xE397	,0xE397	,0x0001), // Multikey chain.
/*<!M><%underscore><%less>                                         */ DEADTRANS( L'<'	,0xE398	,0xE398	,0x0001), // Multikey chain.
/*<!M><%underscore><%less><%parenleft>                             */ DEADTRANS( L'('	,0xE399	,0xE399	,0x0001), // Multikey chain.
/*<!M><%underscore><%less><%parenright>                            */ DEADTRANS( L')'	,0xE39A	,0xE39A	,0x0001), // Multikey chain.
/*<!M><%underscore><%slash><%backslash>                            */ DEADTRANS( L'\\'	,0xE39B	,0xE39B	,0x0001), // Multikey chain.
/*<!M><%underscore><%slash>                                        */ DEADTRANS( L'/'	,0xE39C	,0xE39C	,0x0001), // Multikey chain.
/*<!M><%underscore><%underscore>                                   */ DEADTRANS( L'_'	,0xE39D	,0xE39D	,0x0001), // Multikey chain.
/*<!M><1><%slash>                                                  */ DEADTRANS( L'/'	,0xE3A0	,0xE3A0	,0x0001), // Multikey chain.
/*<!M><2><%bracketleft>                                            */ DEADTRANS( L'['	,0xE3A2	,0xE3A2	,0x0001), // Multikey chain.
/*<!M><2><%bracketright>                                           */ DEADTRANS( L']'	,0xE3A3	,0xE3A3	,0x0001), // Multikey chain.
/*<!M><2><%less>                                                   */ DEADTRANS( L'<'	,0xE3A4	,0xE3A4	,0x0001), // Multikey chain.
/*<!M><2><%slash>                                                  */ DEADTRANS( L'/'	,0xE3A5	,0xE3A5	,0x0001), // Multikey chain.
/*<!M><2><c>                                                       */ DEADTRANS( L'c'	,0xE3A6	,0xE3A6	,0x0001), // Multikey chain.
/*<!M><2><n>                                                       */ DEADTRANS( L'n'	,0xE3A7	,0xE3A7	,0x0001), // Multikey chain.
/*<!M><2><s>                                                       */ DEADTRANS( L's'	,0xE3A8	,0xE3A8	,0x0001), // Multikey chain.
/*<!M><2><S>                                                       */ DEADTRANS( L'S'	,0xE3A9	,0xE3A9	,0x0001), // Multikey chain.
/*<!M><2><T>                                                       */ DEADTRANS( L'T'	,0xE3AA	,0xE3AA	,0x0001), // Multikey chain.
/*<!M><2><T><%greater>                                             */ DEADTRANS( L'>'	,0xE3AB	,0xE3AB	,0x0001), // Multikey chain.
/*<!M><2><T><2><%greater>                                          */ DEADTRANS( L'>'	,0xE3AC	,0xE3AC	,0x0001), // Multikey chain.
/*<!M><2><T><2>                                                    */ DEADTRANS( L'2'	,0xE3AD	,0xE3AD	,0x0001), // Multikey chain.
/*<!M><2><u>                                                       */ DEADTRANS( L'u'	,0xE3AE	,0xE3AE	,0x0001), // Multikey chain.
/*<!M><2><V>                                                       */ DEADTRANS( L'V'	,0xE3AF	,0xE3AF	,0x0001), // Multikey chain.
/*<!M><2><v>                                                       */ DEADTRANS( L'v'	,0xE3B0	,0xE3B0	,0x0001), // Multikey chain.
/*<!M><2><w>                                                       */ DEADTRANS( L'w'	,0xE3B1	,0xE3B1	,0x0001), // Multikey chain.
/*<!M><3><%less>                                                   */ DEADTRANS( L'<'	,0xE3B3	,0xE3B3	,0x0001), // Multikey chain.
/*<!M><3><%slash>                                                  */ DEADTRANS( L'/'	,0xE3B4	,0xE3B4	,0x0001), // Multikey chain.
/*<!M><3><s>                                                       */ DEADTRANS( L's'	,0xE3B5	,0xE3B5	,0x0001), // Multikey chain.
/*<!M><3><S>                                                       */ DEADTRANS( L'S'	,0xE3B6	,0xE3B6	,0x0001), // Multikey chain.
/*<!M><4><%slash>                                                  */ DEADTRANS( L'/'	,0xE3B8	,0xE3B8	,0x0001), // Multikey chain.
/*<!M><5><%slash>                                                  */ DEADTRANS( L'/'	,0xE3BA	,0xE3BA	,0x0001), // Multikey chain.
/*<!M><7><%circum>                                                 */ DEADTRANS( L'^'	,0xE3BD	,0xE3BD	,0x0001), // Multikey chain.
/*<!M><7><%slash>                                                  */ DEADTRANS( L'/'	,0xE3BE	,0xE3BE	,0x0001), // Multikey chain.
/*<!M><8><x>                                                       */ DEADTRANS( L'x'	,0xE3C0	,0xE3C0	,0x0001), // Multikey chain.
/*<!M><8><X>                                                       */ DEADTRANS( L'X'	,0xE3C1	,0xE3C1	,0x0001), // Multikey chain.
/*<!M><a><%minus>                                                  */ DEADTRANS( L'-'	,0xE3C5	,0xE3C5	,0x0001), // Multikey chain.
/*<!M><A><%minus>                                                  */ DEADTRANS( L'-'	,0xE3C6	,0xE3C6	,0x0001), // Multikey chain.
/*<!M><a><%parenleft>                                              */ DEADTRANS( L'('	,0xE3C7	,0xE3C7	,0x0001), // Multikey chain.
/*<!M><a><%parenright>                                             */ DEADTRANS( L')'	,0xE3C8	,0xE3C8	,0x0001), // Multikey chain.
/*<!M><a><%slash>                                                  */ DEADTRANS( L'/'	,0xE3C9	,0xE3C9	,0x0001), // Multikey chain.
/*<!M><A><E>                                                       */ DEADTRANS( L'E'	,0xE3CA	,0xE3CA	,0x0001), // Multikey chain.
/*<!M><a><e>                                                       */ DEADTRANS( L'e'	,0xE3CB	,0xE3CB	,0x0001), // Multikey chain.
/*<!M><a><f>                                                       */ DEADTRANS( L'f'	,0xE3CC	,0xE3CC	,0x0001), // Multikey chain.
/*<!M><A><F>                                                       */ DEADTRANS( L'F'	,0xE3CD	,0xE3CD	,0x0001), // Multikey chain.
/*<!M><a><l>                                                       */ DEADTRANS( L'l'	,0xE3CE	,0xE3CE	,0x0001), // Multikey chain.
/*<!M><A><L>                                                       */ DEADTRANS( L'L'	,0xE3CF	,0xE3CF	,0x0001), // Multikey chain.
/*<!M><a><m>                                                       */ DEADTRANS( L'm'	,0xE3D0	,0xE3D0	,0x0001), // Multikey chain.
/*<!M><A><M>                                                       */ DEADTRANS( L'M'	,0xE3D1	,0xE3D1	,0x0001), // Multikey chain.
/*<!M><a><n>                                                       */ DEADTRANS( L'n'	,0xE3D2	,0xE3D2	,0x0001), // Multikey chain.
/*<!M><A><N>                                                       */ DEADTRANS( L'N'	,0xE3D3	,0xE3D3	,0x0001), // Multikey chain.
/*<!M><a><q><u>                                                    */ DEADTRANS( L'u'	,0xE3D4	,0xE3D4	,0x0001), // Multikey chain.
/*<!M><a><r><i>                                                    */ DEADTRANS( L'i'	,0xE3D5	,0xE3D5	,0x0001), // Multikey chain.
/*<!M><a><w>                                                       */ DEADTRANS( L'w'	,0xE3D6	,0xE3D6	,0x0001), // Multikey chain.
/*<!M><A><W>                                                       */ DEADTRANS( L'W'	,0xE3D7	,0xE3D7	,0x0001), // Multikey chain.
/*<!M><a><z>                                                       */ DEADTRANS( L'z'	,0xE3D8	,0xE3D8	,0x0001), // Multikey chain.
/*<!M><A><Z>                                                       */ DEADTRANS( L'Z'	,0xE3D9	,0xE3D9	,0x0001), // Multikey chain.
/*<!M><b><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE3DB	,0xE3DB	,0x0001), // Multikey chain.
/*<!M><b><%aprightsinglequotemark>                                 */ DEADTRANS( 0x2019	,0xE3DC	,0xE3DC	,0x0001), // Multikey chain.
/*<!M><b><%bracketleft>                                            */ DEADTRANS( L'['	,0xE3DE	,0xE3DE	,0x0001), // Multikey chain.
/*<!M><b><%bracketleft><%underscore>                               */ DEADTRANS( L'_'	,0xE3DF	,0xE3DF	,0x0001), // Multikey chain.
/*<!M><b><%bracketright>                                           */ DEADTRANS( L']'	,0xE3E0	,0xE3E0	,0x0001), // Multikey chain.
/*<!M><b><%bracketright><%underscore>                              */ DEADTRANS( L'_'	,0xE3E1	,0xE3E1	,0x0001), // Multikey chain.
/*<!M><b><%equal>                                                  */ DEADTRANS( L'='	,0xE3E2	,0xE3E2	,0x0001), // Multikey chain.
/*<!M><b><%minus>                                                  */ DEADTRANS( L'-'	,0xE3E3	,0xE3E3	,0x0001), // Multikey chain.
/*<!M><b><%slash>                                                  */ DEADTRANS( L'/'	,0xE3E4	,0xE3E4	,0x0001), // Multikey chain.
/*<!M><b><%tilde>                                                  */ DEADTRANS( L'~'	,0xE3E5	,0xE3E5	,0x0001), // Multikey chain.
/*<!M><b><%underscore>                                             */ DEADTRANS( L'_'	,0xE3E6	,0xE3E6	,0x0001), // Multikey chain.
/*<!M><b><a><l>                                                    */ DEADTRANS( L'l'	,0xE3E7	,0xE3E7	,0x0001), // Multikey chain.
/*<!M><b><d>                                                       */ DEADTRANS( L'd'	,0xE3E8	,0xE3E8	,0x0001), // Multikey chain.
/*<!M><B><D>                                                       */ DEADTRANS( L'D'	,0xE3E9	,0xE3E9	,0x0001), // Multikey chain.
/*<!M><b><e><l>                                                    */ DEADTRANS( L'l'	,0xE3EA	,0xE3EA	,0x0001), // Multikey chain.
/*<!M><b><eacute><l>                                               */ DEADTRANS( L'l'	,0xE3EB	,0xE3EB	,0x0001), // Multikey chain.
/*<!M><B><I>                                                       */ DEADTRANS( L'I'	,0xE3EC	,0xE3EC	,0x0001), // Multikey chain.
/*<!M><b><i><p>                                                    */ DEADTRANS( L'p'	,0xE3ED	,0xE3ED	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%bracketleft>                                */ DEADTRANS( L'['	,0xE3F0	,0xE3F0	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%bracketleft><%underscore>                   */ DEADTRANS( L'_'	,0xE3F1	,0xE3F1	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%bracketright>                               */ DEADTRANS( L']'	,0xE3F2	,0xE3F2	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%bracketright><%underscore>                  */ DEADTRANS( L'_'	,0xE3F3	,0xE3F3	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%equal>                                      */ DEADTRANS( L'='	,0xE3F4	,0xE3F4	,0x0001), // Multikey chain.
/*<!M><c><%backslash>                                              */ DEADTRANS( L'\\'	,0xE3F5	,0xE3F5	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%slash>                                      */ DEADTRANS( L'/'	,0xE3F6	,0xE3F6	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%tilde>                                      */ DEADTRANS( L'~'	,0xE3F7	,0xE3F7	,0x0001), // Multikey chain.
/*<!M><c><%backslash><%underscore>                                 */ DEADTRANS( L'_'	,0xE3F8	,0xE3F8	,0x0001), // Multikey chain.
/*<!M><c><%bar>                                                    */ DEADTRANS( L'|'	,0xE3F9	,0xE3F9	,0x0001), // Multikey chain.
/*<!M><c><%bracketleft>                                            */ DEADTRANS( L'['	,0xE3FA	,0xE3FA	,0x0001), // Multikey chain.
/*<!M><c><%bracketleft><%underscore>                               */ DEADTRANS( L'_'	,0xE3FB	,0xE3FB	,0x0001), // Multikey chain.
/*<!M><c><%bracketright>                                           */ DEADTRANS( L']'	,0xE3FC	,0xE3FC	,0x0001), // Multikey chain.
/*<!M><c><%bracketright><%underscore>                              */ DEADTRANS( L'_'	,0xE3FD	,0xE3FD	,0x0001), // Multikey chain.
/*<!M><c><%equal>                                                  */ DEADTRANS( L'='	,0xE3FE	,0xE3FE	,0x0001), // Multikey chain.
/*<!M><C><%minus>                                                  */ DEADTRANS( L'-'	,0xE3FF	,0xE3FF	,0x0001), // Multikey chain.
/*<!M><c><%minus>                                                  */ DEADTRANS( L'-'	,0xE400	,0xE400	,0x0001), // Multikey chain.
/*<!M><c><%percent>                                                */ DEADTRANS( L'%'	,0xE401	,0xE401	,0x0001), // Multikey chain.
/*<!M><C><%period>                                                 */ DEADTRANS( L'.'	,0xE402	,0xE402	,0x0001), // Multikey chain.
/*<!M><c><%period>                                                 */ DEADTRANS( L'.'	,0xE403	,0xE403	,0x0001), // Multikey chain.
/*<!M><c><%slash>                                                  */ DEADTRANS( L'/'	,0xE404	,0xE404	,0x0001), // Multikey chain.
/*<!M><c><%tilde>                                                  */ DEADTRANS( L'~'	,0xE405	,0xE405	,0x0001), // Multikey chain.
/*<!M><c><%underscore>                                             */ DEADTRANS( L'_'	,0xE406	,0xE406	,0x0001), // Multikey chain.
/*<!M><c><a>                                                       */ DEADTRANS( L'a'	,0xE407	,0xE407	,0x0001), // Multikey chain.
/*<!M><C><A>                                                       */ DEADTRANS( L'A'	,0xE408	,0xE408	,0x0001), // Multikey chain.
/*<!M><C><a>                                                       */ DEADTRANS( L'a'	,0xE409	,0xE409	,0x0001), // Multikey chain.
/*<!M><c><a><p><d><o>                                              */ DEADTRANS( L'o'	,0xE40A	,0xE40A	,0x0001), // Multikey chain.
/*<!M><c><a><p>                                                    */ DEADTRANS( L'p'	,0xE40B	,0xE40B	,0x0001), // Multikey chain.
/*<!M><C><A><P>                                                    */ DEADTRANS( L'P'	,0xE40C	,0xE40C	,0x0001), // Multikey chain.
/*<!M><c><c><%bracketleft><%underscore>                            */ DEADTRANS( L'_'	,0xE40D	,0xE40D	,0x0001), // Multikey chain.
/*<!M><c><c><%bracketright><%underscore>                           */ DEADTRANS( L'_'	,0xE40E	,0xE40E	,0x0001), // Multikey chain.
/*<!M><c><c><%bracketright>                                        */ DEADTRANS( L']'	,0xE40F	,0xE40F	,0x0001), // Multikey chain.
/*<!M><c><c><%equal>                                               */ DEADTRANS( L'='	,0xE410	,0xE410	,0x0001), // Multikey chain.
/*<!M><c><c>                                                       */ DEADTRANS( L'c'	,0xE411	,0xE411	,0x0001), // Multikey chain.
/*<!M><c><c><%slash>                                               */ DEADTRANS( L'/'	,0xE412	,0xE412	,0x0001), // Multikey chain.
/*<!M><c><c><%tilde>                                               */ DEADTRANS( L'~'	,0xE413	,0xE413	,0x0001), // Multikey chain.
/*<!M><c><c><%underscore>                                          */ DEADTRANS( L'_'	,0xE414	,0xE414	,0x0001), // Multikey chain.
/*<!M><c><m>                                                       */ DEADTRANS( L'm'	,0xE415	,0xE415	,0x0001), // Multikey chain.
/*<!M><c><n>                                                       */ DEADTRANS( L'n'	,0xE416	,0xE416	,0x0001), // Multikey chain.
/*<!M><C><N>                                                       */ DEADTRANS( L'N'	,0xE417	,0xE417	,0x0001), // Multikey chain.
/*<!M><c><r>                                                       */ DEADTRANS( L'r'	,0xE418	,0xE418	,0x0001), // Multikey chain.
/*<!M><C><R>                                                       */ DEADTRANS( L'R'	,0xE419	,0xE419	,0x0001), // Multikey chain.
/*<!M><C><u>                                                       */ DEADTRANS( L'u'	,0xE41A	,0xE41A	,0x0001), // Multikey chain.
/*<!M><c><u><p><d><o>                                              */ DEADTRANS( L'o'	,0xE41B	,0xE41B	,0x0001), // Multikey chain.
/*<!M><c><u><p><p><l><u>                                           */ DEADTRANS( L'u'	,0xE41C	,0xE41C	,0x0001), // Multikey chain.
/*<!M><c><u><p>                                                    */ DEADTRANS( L'p'	,0xE41D	,0xE41D	,0x0001), // Multikey chain.
/*<!M><c><u>                                                       */ DEADTRANS( L'u'	,0xE41E	,0xE41E	,0x0001), // Multikey chain.
/*<!M><C><U>                                                       */ DEADTRANS( L'U'	,0xE41F	,0xE41F	,0x0001), // Multikey chain.
/*<!M><D><%greater>                                                */ DEADTRANS( L'>'	,0xE422	,0xE422	,0x0001), // Multikey chain.
/*<!M><d><%greater>                                                */ DEADTRANS( L'>'	,0xE423	,0xE423	,0x0001), // Multikey chain.
/*<!M><d><e>                                                       */ DEADTRANS( L'e'	,0xE424	,0xE424	,0x0001), // Multikey chain.
/*<!M><D><E>                                                       */ DEADTRANS( L'E'	,0xE425	,0xE425	,0x0001), // Multikey chain.
/*<!M><d><eacute>                                                  */ DEADTRANS( 0x00E9	,0xE426	,0xE426	,0x0001), // Multikey chain.
/*<!M><D><Eacute>                                                  */ DEADTRANS( 0x00C9	,0xE427	,0xE427	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><e>                                        */ DEADTRANS( L'e'	,0xE428	,0xE428	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><r>                                        */ DEADTRANS( L'r'	,0xE429	,0xE429	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><egrave><t><r>                                   */ DEADTRANS( L'r'	,0xE42A	,0xE42A	,0x0001), // Multikey chain.
/*<!M><d><z>                                                       */ DEADTRANS( L'z'	,0xE42B	,0xE42B	,0x0001), // Multikey chain.
/*<!M><D><Z>                                                       */ DEADTRANS( L'Z'	,0xE42C	,0xE42C	,0x0001), // Multikey chain.
/*<!M><e><%backslash>                                              */ DEADTRANS( L'\\'	,0xE431	,0xE431	,0x0001), // Multikey chain.
/*<!M><e><%backslash><%bar>                                        */ DEADTRANS( L'|'	,0xE432	,0xE432	,0x0001), // Multikey chain.
/*<!M><e><%bar>                                                    */ DEADTRANS( L'|'	,0xE433	,0xE433	,0x0001), // Multikey chain.
/*<!M><e><%percent>                                                */ DEADTRANS( L'%'	,0xE434	,0xE434	,0x0001), // Multikey chain.
/*<!M><e><m><f>                                                    */ DEADTRANS( L'f'	,0xE435	,0xE435	,0x0001), // Multikey chain.
/*<!M><E><M><F>                                                    */ DEADTRANS( L'F'	,0xE436	,0xE436	,0x0001), // Multikey chain.
/*<!M><e><m><o>                                                    */ DEADTRANS( L'o'	,0xE437	,0xE437	,0x0001), // Multikey chain.
/*<!M><E><M><O>                                                    */ DEADTRANS( L'O'	,0xE438	,0xE438	,0x0001), // Multikey chain.
/*<!M><e><m>                                                       */ DEADTRANS( L'm'	,0xE439	,0xE439	,0x0001), // Multikey chain.
/*<!M><e><n>                                                       */ DEADTRANS( L'n'	,0xE43A	,0xE43A	,0x0001), // Multikey chain.
/*<!M><E><N>                                                       */ DEADTRANS( L'N'	,0xE43B	,0xE43B	,0x0001), // Multikey chain.
/*<!M><e><n><f>                                                    */ DEADTRANS( L'f'	,0xE43C	,0xE43C	,0x0001), // Multikey chain.
/*<!M><E><N><F>                                                    */ DEADTRANS( L'F'	,0xE43D	,0xE43D	,0x0001), // Multikey chain.
/*<!M><e><n><o>                                                    */ DEADTRANS( L'o'	,0xE43E	,0xE43E	,0x0001), // Multikey chain.
/*<!M><E><N><O>                                                    */ DEADTRANS( L'O'	,0xE43F	,0xE43F	,0x0001), // Multikey chain.
/*<!M><E><n><v><e><l><o><p>                                        */ DEADTRANS( L'p'	,0xE440	,0xE440	,0x0001), // Multikey chain.
/*<!M><e><s>                                                       */ DEADTRANS( L's'	,0xE441	,0xE441	,0x0001), // Multikey chain.
/*<!M><E><S>                                                       */ DEADTRANS( L'S'	,0xE442	,0xE442	,0x0001), // Multikey chain.
/*<!M><E><U>                                                       */ DEADTRANS( L'U'	,0xE443	,0xE443	,0x0001), // Multikey chain.
/*<!M><E><u>                                                       */ DEADTRANS( L'u'	,0xE444	,0xE444	,0x0001), // Multikey chain.
/*<!M><e><u>                                                       */ DEADTRANS( L'u'	,0xE445	,0xE445	,0x0001), // Multikey chain.
/*<!M><f><e><n>                                                    */ DEADTRANS( L'n'	,0xE44A	,0xE44A	,0x0001), // Multikey chain.
/*<!M><f><l>                                                       */ DEADTRANS( L'l'	,0xE44B	,0xE44B	,0x0001), // Multikey chain.
/*<!M><F><L>                                                       */ DEADTRANS( L'L'	,0xE44C	,0xE44C	,0x0001), // Multikey chain.
/*<!M><f><n>                                                       */ DEADTRANS( L'n'	,0xE44D	,0xE44D	,0x0001), // Multikey chain.
/*<!M><f><r>                                                       */ DEADTRANS( L'r'	,0xE44E	,0xE44E	,0x0001), // Multikey chain.
/*<!M><F><R>                                                       */ DEADTRANS( L'R'	,0xE44F	,0xE44F	,0x0001), // Multikey chain.
/*<!M><f><t>                                                       */ DEADTRANS( L't'	,0xE450	,0xE450	,0x0001), // Multikey chain.
/*<!M><F><T>                                                       */ DEADTRANS( L'T'	,0xE451	,0xE451	,0x0001), // Multikey chain.
/*<!M><g><e>                                                       */ DEADTRANS( L'e'	,0xE454	,0xE454	,0x0001), // Multikey chain.
/*<!M><G><E>                                                       */ DEADTRANS( L'E'	,0xE455	,0xE455	,0x0001), // Multikey chain.
/*<!M><g><e><m>                                                    */ DEADTRANS( L'm'	,0xE456	,0xE456	,0x0001), // Multikey chain.
/*<!M><G><E><M>                                                    */ DEADTRANS( L'M'	,0xE457	,0xE457	,0x0001), // Multikey chain.
/*<!M><g><eacute><m>                                               */ DEADTRANS( L'm'	,0xE458	,0xE458	,0x0001), // Multikey chain.
/*<!M><G><Eacute><M>                                               */ DEADTRANS( L'M'	,0xE459	,0xE459	,0x0001), // Multikey chain.
/*<!M><g><g>                                                       */ DEADTRANS( L'g'	,0xE45A	,0xE45A	,0x0001), // Multikey chain.
/*<!M><G><G>                                                       */ DEADTRANS( L'G'	,0xE45B	,0xE45B	,0x0001), // Multikey chain.
/*<!M><g><h>                                                       */ DEADTRANS( L'h'	,0xE45C	,0xE45C	,0x0001), // Multikey chain.
/*<!M><G><H>                                                       */ DEADTRANS( L'H'	,0xE45D	,0xE45D	,0x0001), // Multikey chain.
/*<!M><h><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE45E	,0xE45E	,0x0001), // Multikey chain.
/*<!M><H><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE45F	,0xE45F	,0x0001), // Multikey chain.
/*<!M><h><%aprightsinglequotemark>                                 */ DEADTRANS( 0x2019	,0xE460	,0xE460	,0x0001), // Multikey chain.
/*<!M><H><%aprightsinglequotemark>                                 */ DEADTRANS( 0x2019	,0xE461	,0xE461	,0x0001), // Multikey chain.
/*<!M><h><d><p>                                                    */ DEADTRANS( L'p'	,0xE464	,0xE464	,0x0001), // Multikey chain.
/*<!M><H><D><P>                                                    */ DEADTRANS( L'P'	,0xE465	,0xE465	,0x0001), // Multikey chain.
/*<!M><h><o>                                                       */ DEADTRANS( L'o'	,0xE466	,0xE466	,0x0001), // Multikey chain.
/*<!M><H><O>                                                       */ DEADTRANS( L'O'	,0xE467	,0xE467	,0x0001), // Multikey chain.
/*<!M><i><%at>                                                     */ DEADTRANS( L'@'	,0xE468	,0xE468	,0x0001), // Multikey chain.
/*<!M><I><%bracketleft>                                            */ DEADTRANS( L'['	,0xE46A	,0xE46A	,0x0001), // Multikey chain.
/*<!M><I><%less>                                                   */ DEADTRANS( L'<'	,0xE46C	,0xE46C	,0x0001), // Multikey chain.
/*<!M><i><%percent>                                                */ DEADTRANS( L'%'	,0xE46D	,0xE46D	,0x0001), // Multikey chain.
/*<!M><I><%underscore>                                             */ DEADTRANS( L'_'	,0xE46E	,0xE46E	,0x0001), // Multikey chain.
/*<!M><i><i>                                                       */ DEADTRANS( L'i'	,0xE46F	,0xE46F	,0x0001), // Multikey chain.
/*<!M><i><l>                                                       */ DEADTRANS( L'l'	,0xE470	,0xE470	,0x0001), // Multikey chain.
/*<!M><I><L>                                                       */ DEADTRANS( L'L'	,0xE471	,0xE471	,0x0001), // Multikey chain.
/*<!M><i><n>                                                       */ DEADTRANS( L'n'	,0xE472	,0xE472	,0x0001), // Multikey chain.
/*<!M><I><N>                                                       */ DEADTRANS( L'N'	,0xE473	,0xE473	,0x0001), // Multikey chain.
/*<!M><i><n><t><e><r><s><e>                                        */ DEADTRANS( L'e'	,0xE474	,0xE474	,0x0001), // Multikey chain.
/*<!M><I><O>                                                       */ DEADTRANS( L'O'	,0xE475	,0xE475	,0x0001), // Multikey chain.
/*<!M><i><p>                                                       */ DEADTRANS( L'p'	,0xE476	,0xE476	,0x0001), // Multikey chain.
/*<!M><I><P>                                                       */ DEADTRANS( L'P'	,0xE477	,0xE477	,0x0001), // Multikey chain.
/*<!M><i><q>                                                       */ DEADTRANS( L'q'	,0xE478	,0xE478	,0x0001), // Multikey chain.
/*<!M><I><Q>                                                       */ DEADTRANS( L'Q'	,0xE479	,0xE479	,0x0001), // Multikey chain.
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'p'	,0xE47A	,0xE47A	,0x0001), // Multikey chain.
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'P'	,0xE47B	,0xE47B	,0x0001), // Multikey chain.
/*<!M><i><r>                                                       */ DEADTRANS( L'r'	,0xE47C	,0xE47C	,0x0001), // Multikey chain.
/*<!M><I><R>                                                       */ DEADTRANS( L'R'	,0xE47D	,0xE47D	,0x0001), // Multikey chain.
/*<!M><j><p>                                                       */ DEADTRANS( L'p'	,0xE480	,0xE480	,0x0001), // Multikey chain.
/*<!M><J><P>                                                       */ DEADTRANS( L'P'	,0xE481	,0xE481	,0x0001), // Multikey chain.
/*<!M><k><g>                                                       */ DEADTRANS( L'g'	,0xE484	,0xE484	,0x0001), // Multikey chain.
/*<!M><K><G>                                                       */ DEADTRANS( L'G'	,0xE485	,0xE485	,0x0001), // Multikey chain.
/*<!M><k><h>                                                       */ DEADTRANS( L'h'	,0xE486	,0xE486	,0x0001), // Multikey chain.
/*<!M><K><H>                                                       */ DEADTRANS( L'H'	,0xE487	,0xE487	,0x0001), // Multikey chain.
/*<!M><k><o>                                                       */ DEADTRANS( L'o'	,0xE488	,0xE488	,0x0001), // Multikey chain.
/*<!M><K><O>                                                       */ DEADTRANS( L'O'	,0xE489	,0xE489	,0x0001), // Multikey chain.
/*<!M><k><p>                                                       */ DEADTRANS( L'p'	,0xE48A	,0xE48A	,0x0001), // Multikey chain.
/*<!M><K><P>                                                       */ DEADTRANS( L'P'	,0xE48B	,0xE48B	,0x0001), // Multikey chain.
/*<!M><k><r>                                                       */ DEADTRANS( L'r'	,0xE48C	,0xE48C	,0x0001), // Multikey chain.
/*<!M><K><R>                                                       */ DEADTRANS( L'R'	,0xE48D	,0xE48D	,0x0001), // Multikey chain.
/*<!M><k><z>                                                       */ DEADTRANS( L'z'	,0xE48E	,0xE48E	,0x0001), // Multikey chain.
/*<!M><K><Z>                                                       */ DEADTRANS( L'Z'	,0xE48F	,0xE48F	,0x0001), // Multikey chain.
/*<!M><l><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE490	,0xE490	,0x0001), // Multikey chain.
/*<!M><L><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE491	,0xE491	,0x0001), // Multikey chain.
/*<!M><l><%aprightsinglequotemark>                                 */ DEADTRANS( 0x2019	,0xE492	,0xE492	,0x0001), // Multikey chain.
/*<!M><L><%aprightsinglequotemark>                                 */ DEADTRANS( 0x2019	,0xE493	,0xE493	,0x0001), // Multikey chain.
/*<!M><L><%backslash>                                              */ DEADTRANS( L'\\'	,0xE494	,0xE494	,0x0001), // Multikey chain.
/*<!M><L><%parenright>                                             */ DEADTRANS( L')'	,0xE497	,0xE497	,0x0001), // Multikey chain.
/*<!M><L><%percent><%percent>                                      */ DEADTRANS( L'%'	,0xE498	,0xE498	,0x0001), // Multikey chain.
/*<!M><L><%percent>                                                */ DEADTRANS( L'%'	,0xE499	,0xE499	,0x0001), // Multikey chain.
/*<!M><l><a>                                                       */ DEADTRANS( L'a'	,0xE49A	,0xE49A	,0x0001), // Multikey chain.
/*<!M><L><A>                                                       */ DEADTRANS( L'A'	,0xE49B	,0xE49B	,0x0001), // Multikey chain.
/*<!M><l><b>                                                       */ DEADTRANS( L'b'	,0xE49C	,0xE49C	,0x0001), // Multikey chain.
/*<!M><l><d><p>                                                    */ DEADTRANS( L'p'	,0xE49D	,0xE49D	,0x0001), // Multikey chain.
/*<!M><L><D><P>                                                    */ DEADTRANS( L'P'	,0xE49E	,0xE49E	,0x0001), // Multikey chain.
/*<!M><l><e>                                                       */ DEADTRANS( L'e'	,0xE49F	,0xE49F	,0x0001), // Multikey chain.
/*<!M><L><E>                                                       */ DEADTRANS( L'E'	,0xE4A0	,0xE4A0	,0x0001), // Multikey chain.
/*<!M><l><e><z>                                                    */ DEADTRANS( L'z'	,0xE4A1	,0xE4A1	,0x0001), // Multikey chain.
/*<!M><l><i><b>                                                    */ DEADTRANS( L'b'	,0xE4A2	,0xE4A2	,0x0001), // Multikey chain.
/*<!M><L><I><B>                                                    */ DEADTRANS( L'B'	,0xE4A3	,0xE4A3	,0x0001), // Multikey chain.
/*<!M><l><i><o>                                                    */ DEADTRANS( L'o'	,0xE4A4	,0xE4A4	,0x0001), // Multikey chain.
/*<!M><L><I><O>                                                    */ DEADTRANS( L'O'	,0xE4A5	,0xE4A5	,0x0001), // Multikey chain.
/*<!M><L><p><a><r><e><n><g>                                        */ DEADTRANS( L'g'	,0xE4A6	,0xE4A6	,0x0001), // Multikey chain.
/*<!M><l><r><e>                                                    */ DEADTRANS( L'e'	,0xE4A7	,0xE4A7	,0x0001), // Multikey chain.
/*<!M><L><R><E>                                                    */ DEADTRANS( L'E'	,0xE4A8	,0xE4A8	,0x0001), // Multikey chain.
/*<!M><m><n>                                                       */ DEADTRANS( L'n'	,0xE4AB	,0xE4AB	,0x0001), // Multikey chain.
/*<!M><M><N>                                                       */ DEADTRANS( L'N'	,0xE4AC	,0xE4AC	,0x0001), // Multikey chain.
/*<!M><m><u>                                                       */ DEADTRANS( L'u'	,0xE4AD	,0xE4AD	,0x0001), // Multikey chain.
/*<!M><M><U>                                                       */ DEADTRANS( L'U'	,0xE4AE	,0xE4AE	,0x0001), // Multikey chain.
/*<!M><m><v>                                                       */ DEADTRANS( L'v'	,0xE4AF	,0xE4AF	,0x0001), // Multikey chain.
/*<!M><M><V>                                                       */ DEADTRANS( L'V'	,0xE4B0	,0xE4B0	,0x0001), // Multikey chain.
/*<!M><n><%underscore>                                             */ DEADTRANS( L'_'	,0xE4B4	,0xE4B4	,0x0001), // Multikey chain.
/*<!M><n><a>                                                       */ DEADTRANS( L'a'	,0xE4B5	,0xE4B5	,0x0001), // Multikey chain.
/*<!M><n><b>                                                       */ DEADTRANS( L'b'	,0xE4B6	,0xE4B6	,0x0001), // Multikey chain.
/*<!M><N><B>                                                       */ DEADTRANS( L'B'	,0xE4B7	,0xE4B7	,0x0001), // Multikey chain.
/*<!M><n><g>                                                       */ DEADTRANS( L'g'	,0xE4B8	,0xE4B8	,0x0001), // Multikey chain.
/*<!M><N><G>                                                       */ DEADTRANS( L'G'	,0xE4B9	,0xE4B9	,0x0001), // Multikey chain.
/*<!M><n><m>                                                       */ DEADTRANS( L'm'	,0xE4BA	,0xE4BA	,0x0001), // Multikey chain.
/*<!M><N><M>                                                       */ DEADTRANS( L'M'	,0xE4BB	,0xE4BB	,0x0001), // Multikey chain.
/*<!M><n><o>                                                       */ DEADTRANS( L'o'	,0xE4BC	,0xE4BC	,0x0001), // Multikey chain.
/*<!M><N><O>                                                       */ DEADTRANS( L'O'	,0xE4BD	,0xE4BD	,0x0001), // Multikey chain.
/*<!M><n><u>                                                       */ DEADTRANS( L'u'	,0xE4BE	,0xE4BE	,0x0001), // Multikey chain.
/*<!M><o><%backslash>                                              */ DEADTRANS( L'\\'	,0xE4C1	,0xE4C1	,0x0001), // Multikey chain.
/*<!M><O><%backslash>                                              */ DEADTRANS( L'\\'	,0xE4C2	,0xE4C2	,0x0001), // Multikey chain.
/*<!M><O><%bar>                                                    */ DEADTRANS( L'|'	,0xE4C3	,0xE4C3	,0x0001), // Multikey chain.
/*<!M><o><%bar>                                                    */ DEADTRANS( L'|'	,0xE4C4	,0xE4C4	,0x0001), // Multikey chain.
/*<!M><O><%colon>                                                  */ DEADTRANS( L':'	,0xE4C5	,0xE4C5	,0x0001), // Multikey chain.
/*<!M><o><%colon>                                                  */ DEADTRANS( L':'	,0xE4C6	,0xE4C6	,0x0001), // Multikey chain.
/*<!M><O><%hash>                                                   */ DEADTRANS( L'#'	,0xE4C7	,0xE4C7	,0x0001), // Multikey chain.
/*<!M><o><%hash>                                                   */ DEADTRANS( L'#'	,0xE4C8	,0xE4C8	,0x0001), // Multikey chain.
/*<!M><O><%less>                                                   */ DEADTRANS( L'<'	,0xE4C9	,0xE4C9	,0x0001), // Multikey chain.
/*<!M><O><%minus>                                                  */ DEADTRANS( L'-'	,0xE4CA	,0xE4CA	,0x0001), // Multikey chain.
/*<!M><o><%minus>                                                  */ DEADTRANS( L'-'	,0xE4CB	,0xE4CB	,0x0001), // Multikey chain.
/*<!M><O><%percent>                                                */ DEADTRANS( L'%'	,0xE4CC	,0xE4CC	,0x0001), // Multikey chain.
/*<!M><o><%plus>                                                   */ DEADTRANS( L'+'	,0xE4CD	,0xE4CD	,0x0001), // Multikey chain.
/*<!M><O><%plus>                                                   */ DEADTRANS( L'+'	,0xE4CE	,0xE4CE	,0x0001), // Multikey chain.
/*<!M><o><%slash>                                                  */ DEADTRANS( L'/'	,0xE4CF	,0xE4CF	,0x0001), // Multikey chain.
/*<!M><o><i><n>                                                    */ DEADTRANS( L'n'	,0xE4D0	,0xE4D0	,0x0001), // Multikey chain.
/*<!M><o><i>                                                       */ DEADTRANS( L'i'	,0xE4D1	,0xE4D1	,0x0001), // Multikey chain.
/*<!M><O><o>                                                       */ DEADTRANS( L'o'	,0xE4D2	,0xE4D2	,0x0001), // Multikey chain.
/*<!M><o><p>                                                       */ DEADTRANS( L'p'	,0xE4D3	,0xE4D3	,0x0001), // Multikey chain.
/*<!M><O><P>                                                       */ DEADTRANS( L'P'	,0xE4D4	,0xE4D4	,0x0001), // Multikey chain.
/*<!M><o><s>                                                       */ DEADTRANS( L's'	,0xE4D5	,0xE4D5	,0x0001), // Multikey chain.
/*<!M><o><s><u>                                                    */ DEADTRANS( L'u'	,0xE4D6	,0xE4D6	,0x0001), // Multikey chain.
/*<!M><o><T>                                                       */ DEADTRANS( L'T'	,0xE4D7	,0xE4D7	,0x0001), // Multikey chain.
/*<!M><o><t>                                                       */ DEADTRANS( L't'	,0xE4D8	,0xE4D8	,0x0001), // Multikey chain.
/*<!M><O><T>                                                       */ DEADTRANS( L'T'	,0xE4D9	,0xE4D9	,0x0001), // Multikey chain.
/*<!M><p><%bar>                                                    */ DEADTRANS( L'|'	,0xE4DA	,0xE4DA	,0x0001), // Multikey chain.
/*<!M><p><a><c>                                                    */ DEADTRANS( L'c'	,0xE4DD	,0xE4DD	,0x0001), // Multikey chain.
/*<!M><P><A><C>                                                    */ DEADTRANS( L'C'	,0xE4DE	,0xE4DE	,0x0001), // Multikey chain.
/*<!M><p><a><r>                                                    */ DEADTRANS( L'r'	,0xE4DF	,0xE4DF	,0x0001), // Multikey chain.
/*<!M><P><A><R>                                                    */ DEADTRANS( L'R'	,0xE4E0	,0xE4E0	,0x0001), // Multikey chain.
/*<!M><p><a><t>                                                    */ DEADTRANS( L't'	,0xE4E1	,0xE4E1	,0x0001), // Multikey chain.
/*<!M><P><A><T>                                                    */ DEADTRANS( L'T'	,0xE4E2	,0xE4E2	,0x0001), // Multikey chain.
/*<!M><p><d>                                                       */ DEADTRANS( L'd'	,0xE4E3	,0xE4E3	,0x0001), // Multikey chain.
/*<!M><p><e><h>                                                    */ DEADTRANS( L'h'	,0xE4E4	,0xE4E4	,0x0001), // Multikey chain.
/*<!M><P><E><H>                                                    */ DEADTRANS( L'H'	,0xE4E5	,0xE4E5	,0x0001), // Multikey chain.
/*<!M><p><e><l>                                                    */ DEADTRANS( L'l'	,0xE4E6	,0xE4E6	,0x0001), // Multikey chain.
/*<!M><P><E><L>                                                    */ DEADTRANS( L'L'	,0xE4E7	,0xE4E7	,0x0001), // Multikey chain.
/*<!M><p><e>                                                       */ DEADTRANS( L'e'	,0xE4E8	,0xE4E8	,0x0001), // Multikey chain.
/*<!M><P><e>                                                       */ DEADTRANS( L'e'	,0xE4E9	,0xE4E9	,0x0001), // Multikey chain.
/*<!M><P><E>                                                       */ DEADTRANS( L'E'	,0xE4EA	,0xE4EA	,0x0001), // Multikey chain.
/*<!M><p><h>                                                       */ DEADTRANS( L'h'	,0xE4EB	,0xE4EB	,0x0001), // Multikey chain.
/*<!M><P><H>                                                       */ DEADTRANS( L'H'	,0xE4EC	,0xE4EC	,0x0001), // Multikey chain.
/*<!M><p><i><s>                                                    */ DEADTRANS( L's'	,0xE4ED	,0xE4ED	,0x0001), // Multikey chain.
/*<!M><P><I><S>                                                    */ DEADTRANS( L'S'	,0xE4EE	,0xE4EE	,0x0001), // Multikey chain.
/*<!M><p><i>                                                       */ DEADTRANS( L'i'	,0xE4EF	,0xE4EF	,0x0001), // Multikey chain.
/*<!M><P><L>                                                       */ DEADTRANS( L'L'	,0xE4F0	,0xE4F0	,0x0001), // Multikey chain.
/*<!M><P><l>                                                       */ DEADTRANS( L'l'	,0xE4F1	,0xE4F1	,0x0001), // Multikey chain.
/*<!M><p><l>                                                       */ DEADTRANS( L'l'	,0xE4F2	,0xE4F2	,0x0001), // Multikey chain.
/*<!M><p><o><i>                                                    */ DEADTRANS( L'i'	,0xE4F3	,0xE4F3	,0x0001), // Multikey chain.
/*<!M><P><O><I>                                                    */ DEADTRANS( L'I'	,0xE4F4	,0xE4F4	,0x0001), // Multikey chain.
/*<!M><p><p>                                                       */ DEADTRANS( L'p'	,0xE4F5	,0xE4F5	,0x0001), // Multikey chain.
/*<!M><P><P>                                                       */ DEADTRANS( L'P'	,0xE4F6	,0xE4F6	,0x0001), // Multikey chain.
/*<!M><p><p><c>                                                    */ DEADTRANS( L'c'	,0xE4F7	,0xE4F7	,0x0001), // Multikey chain.
/*<!M><P><P><C>                                                    */ DEADTRANS( L'C'	,0xE4F8	,0xE4F8	,0x0001), // Multikey chain.
/*<!M><p><p><m>                                                    */ DEADTRANS( L'm'	,0xE4F9	,0xE4F9	,0x0001), // Multikey chain.
/*<!M><P><P><M>                                                    */ DEADTRANS( L'M'	,0xE4FA	,0xE4FA	,0x0001), // Multikey chain.
/*<!M><p><p><r>                                                    */ DEADTRANS( L'r'	,0xE4FB	,0xE4FB	,0x0001), // Multikey chain.
/*<!M><P><P><R>                                                    */ DEADTRANS( L'R'	,0xE4FC	,0xE4FC	,0x0001), // Multikey chain.
/*<!M><p><p><t>                                                    */ DEADTRANS( L't'	,0xE4FD	,0xE4FD	,0x0001), // Multikey chain.
/*<!M><P><P><T>                                                    */ DEADTRANS( L'T'	,0xE4FE	,0xE4FE	,0x0001), // Multikey chain.
/*<!M><p><t>                                                       */ DEADTRANS( L't'	,0xE4FF	,0xE4FF	,0x0001), // Multikey chain.
/*<!M><P><T>                                                       */ DEADTRANS( L'T'	,0xE500	,0xE500	,0x0001), // Multikey chain.
/*<!M><p><v>                                                       */ DEADTRANS( L'v'	,0xE501	,0xE501	,0x0001), // Multikey chain.
/*<!M><P><V>                                                       */ DEADTRANS( L'V'	,0xE502	,0xE502	,0x0001), // Multikey chain.
/*<!M><p><y>                                                       */ DEADTRANS( L'y'	,0xE503	,0xE503	,0x0001), // Multikey chain.
/*<!M><P><Y>                                                       */ DEADTRANS( L'Y'	,0xE504	,0xE504	,0x0001), // Multikey chain.
/*<!M><R><C><C><C><D><D>                                           */ DEADTRANS( L'D'	,0xE509	,0xE509	,0x0001), // Multikey chain.
/*<!M><R><C><C><D>                                                 */ DEADTRANS( L'D'	,0xE50A	,0xE50A	,0x0001), // Multikey chain.
/*<!M><R><C>                                                       */ DEADTRANS( L'C'	,0xE50B	,0xE50B	,0x0001), // Multikey chain.
/*<!M><R><C><V>                                                    */ DEADTRANS( L'V'	,0xE50C	,0xE50C	,0x0001), // Multikey chain.
/*<!M><R><D><D>                                                    */ DEADTRANS( L'D'	,0xE50D	,0xE50D	,0x0001), // Multikey chain.
/*<!M><r><e><c>                                                    */ DEADTRANS( L'c'	,0xE50E	,0xE50E	,0x0001), // Multikey chain.
/*<!M><R><E><C>                                                    */ DEADTRANS( L'C'	,0xE50F	,0xE50F	,0x0001), // Multikey chain.
/*<!M><r><e>                                                       */ DEADTRANS( L'e'	,0xE510	,0xE510	,0x0001), // Multikey chain.
/*<!M><R><E>                                                       */ DEADTRANS( L'E'	,0xE511	,0xE511	,0x0001), // Multikey chain.
/*<!M><R><L>                                                       */ DEADTRANS( L'L'	,0xE512	,0xE512	,0x0001), // Multikey chain.
/*<!M><R><p><a><r><e><n><l>                                        */ DEADTRANS( L'l'	,0xE513	,0xE513	,0x0001), // Multikey chain.
/*<!M><r><u>                                                       */ DEADTRANS( L'u'	,0xE514	,0xE514	,0x0001), // Multikey chain.
/*<!M><R><U>                                                       */ DEADTRANS( L'U'	,0xE515	,0xE515	,0x0001), // Multikey chain.
/*<!M><R><u>                                                       */ DEADTRANS( L'u'	,0xE516	,0xE516	,0x0001), // Multikey chain.
/*<!M><s><%backslash>                                              */ DEADTRANS( L'\\'	,0xE517	,0xE517	,0x0001), // Multikey chain.
/*<!M><s><%bracketleft>                                            */ DEADTRANS( L'['	,0xE51A	,0xE51A	,0x0001), // Multikey chain.
/*<!M><S><%bracketleft>                                            */ DEADTRANS( L'['	,0xE51B	,0xE51B	,0x0001), // Multikey chain.
/*<!M><s><%bracketright>                                           */ DEADTRANS( L']'	,0xE51C	,0xE51C	,0x0001), // Multikey chain.
/*<!M><S><%bracketright>                                           */ DEADTRANS( L']'	,0xE51D	,0xE51D	,0x0001), // Multikey chain.
/*<!M><s><%less>                                                   */ DEADTRANS( L'<'	,0xE51E	,0xE51E	,0x0001), // Multikey chain.
/*<!M><S><%less>                                                   */ DEADTRANS( L'<'	,0xE51F	,0xE51F	,0x0001), // Multikey chain.
/*<!M><s><%percent>                                                */ DEADTRANS( L'%'	,0xE520	,0xE520	,0x0001), // Multikey chain.
/*<!M><s><%period>                                                 */ DEADTRANS( L'.'	,0xE521	,0xE521	,0x0001), // Multikey chain.
/*<!M><S><%period>                                                 */ DEADTRANS( L'.'	,0xE522	,0xE522	,0x0001), // Multikey chain.
/*<!M><s><%slash>                                                  */ DEADTRANS( L'/'	,0xE523	,0xE523	,0x0001), // Multikey chain.
/*<!M><s><a><g>                                                    */ DEADTRANS( L'g'	,0xE524	,0xE524	,0x0001), // Multikey chain.
/*<!M><S><A><G>                                                    */ DEADTRANS( L'G'	,0xE525	,0xE525	,0x0001), // Multikey chain.
/*<!M><s><a>                                                       */ DEADTRANS( L'a'	,0xE526	,0xE526	,0x0001), // Multikey chain.
/*<!M><S><a>                                                       */ DEADTRANS( L'a'	,0xE527	,0xE527	,0x0001), // Multikey chain.
/*<!M><S><A>                                                       */ DEADTRANS( L'A'	,0xE528	,0xE528	,0x0001), // Multikey chain.
/*<!M><s><c><o>                                                    */ DEADTRANS( L'o'	,0xE529	,0xE529	,0x0001), // Multikey chain.
/*<!M><S><C><O>                                                    */ DEADTRANS( L'O'	,0xE52A	,0xE52A	,0x0001), // Multikey chain.
/*<!M><s><c>                                                       */ DEADTRANS( L'c'	,0xE52B	,0xE52B	,0x0001), // Multikey chain.
/*<!M><S><c>                                                       */ DEADTRANS( L'c'	,0xE52C	,0xE52C	,0x0001), // Multikey chain.
/*<!M><S><C>                                                       */ DEADTRANS( L'C'	,0xE52D	,0xE52D	,0x0001), // Multikey chain.
/*<!M><s><e>                                                       */ DEADTRANS( L'e'	,0xE52E	,0xE52E	,0x0001), // Multikey chain.
/*<!M><S><E>                                                       */ DEADTRANS( L'E'	,0xE52F	,0xE52F	,0x0001), // Multikey chain.
/*<!M><s><e><t><m><i><n><u>                                        */ DEADTRANS( L'u'	,0xE530	,0xE530	,0x0001), // Multikey chain.
/*<!M><s><i>                                                       */ DEADTRANS( L'i'	,0xE531	,0xE531	,0x0001), // Multikey chain.
/*<!M><S><I>                                                       */ DEADTRANS( L'I'	,0xE532	,0xE532	,0x0001), // Multikey chain.
/*<!M><s><n>                                                       */ DEADTRANS( L'n'	,0xE533	,0xE533	,0x0001), // Multikey chain.
/*<!M><S><N>                                                       */ DEADTRANS( L'N'	,0xE534	,0xE534	,0x0001), // Multikey chain.
/*<!M><s><o>                                                       */ DEADTRANS( L'o'	,0xE535	,0xE535	,0x0001), // Multikey chain.
/*<!M><S><o>                                                       */ DEADTRANS( L'o'	,0xE536	,0xE536	,0x0001), // Multikey chain.
/*<!M><S><O>                                                       */ DEADTRANS( L'O'	,0xE537	,0xE537	,0x0001), // Multikey chain.
/*<!M><s><u>                                                       */ DEADTRANS( L'u'	,0xE538	,0xE538	,0x0001), // Multikey chain.
/*<!M><S><U>                                                       */ DEADTRANS( L'U'	,0xE539	,0xE539	,0x0001), // Multikey chain.
/*<!M><s><v>                                                       */ DEADTRANS( L'v'	,0xE53A	,0xE53A	,0x0001), // Multikey chain.
/*<!M><S><V>                                                       */ DEADTRANS( L'V'	,0xE53B	,0xE53B	,0x0001), // Multikey chain.
/*<!M><T><%greater>                                                */ DEADTRANS( L'>'	,0xE53E	,0xE53E	,0x0001), // Multikey chain.
/*<!M><T><%less>                                                   */ DEADTRANS( L'<'	,0xE53F	,0xE53F	,0x0001), // Multikey chain.
/*<!M><T><%percent>                                                */ DEADTRANS( L'%'	,0xE540	,0xE540	,0x0001), // Multikey chain.
/*<!M><T><2><%greater>                                             */ DEADTRANS( L'>'	,0xE541	,0xE541	,0x0001), // Multikey chain.
/*<!M><T><2><%less>                                                */ DEADTRANS( L'<'	,0xE542	,0xE542	,0x0001), // Multikey chain.
/*<!M><T><2>                                                       */ DEADTRANS( L'2'	,0xE543	,0xE543	,0x0001), // Multikey chain.
/*<!M><T><3>                                                       */ DEADTRANS( L'3'	,0xE544	,0xE544	,0x0001), // Multikey chain.
/*<!M><t><a>                                                       */ DEADTRANS( L'a'	,0xE545	,0xE545	,0x0001), // Multikey chain.
/*<!M><T><A>                                                       */ DEADTRANS( L'A'	,0xE546	,0xE546	,0x0001), // Multikey chain.
/*<!M><t><a><u>                                                    */ DEADTRANS( L'u'	,0xE547	,0xE547	,0x0001), // Multikey chain.
/*<!M><T><A><U>                                                    */ DEADTRANS( L'U'	,0xE548	,0xE548	,0x0001), // Multikey chain.
/*<!M><t><e>                                                       */ DEADTRANS( L'e'	,0xE549	,0xE549	,0x0001), // Multikey chain.
/*<!M><t><h>                                                       */ DEADTRANS( L'h'	,0xE54A	,0xE54A	,0x0001), // Multikey chain.
/*<!M><T><H>                                                       */ DEADTRANS( L'H'	,0xE54B	,0xE54B	,0x0001), // Multikey chain.
/*<!M><t><n>                                                       */ DEADTRANS( L'n'	,0xE54C	,0xE54C	,0x0001), // Multikey chain.
/*<!M><t><o>                                                       */ DEADTRANS( L'o'	,0xE54D	,0xE54D	,0x0001), // Multikey chain.
/*<!M><T><O>                                                       */ DEADTRANS( L'O'	,0xE54E	,0xE54E	,0x0001), // Multikey chain.
/*<!M><t><r>                                                       */ DEADTRANS( L'r'	,0xE54F	,0xE54F	,0x0001), // Multikey chain.
/*<!M><T><R>                                                       */ DEADTRANS( L'R'	,0xE550	,0xE550	,0x0001), // Multikey chain.
/*<!M><T><T>                                                       */ DEADTRANS( L'T'	,0xE551	,0xE551	,0x0001), // Multikey chain.
/*<!M><T><T><%percent>                                             */ DEADTRANS( L'%'	,0xE552	,0xE552	,0x0001), // Multikey chain.
/*<!M><u><%minus>                                                  */ DEADTRANS( L'-'	,0xE555	,0xE555	,0x0001), // Multikey chain.
/*<!M><u><a>                                                       */ DEADTRANS( L'a'	,0xE556	,0xE556	,0x0001), // Multikey chain.
/*<!M><U><A>                                                       */ DEADTRANS( L'A'	,0xE557	,0xE557	,0x0001), // Multikey chain.
/*<!M><u><n><i><o>                                                 */ DEADTRANS( L'o'	,0xE558	,0xE558	,0x0001), // Multikey chain.
/*<!M><u><n>                                                       */ DEADTRANS( L'n'	,0xE559	,0xE559	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenleft>                                  */ DEADTRANS( L'('	,0xE55B	,0xE55B	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenright>                                 */ DEADTRANS( L')'	,0xE55C	,0xE55C	,0x0001), // Multikey chain.
/*<!M><v><%parenleft>                                              */ DEADTRANS( L'('	,0xE55E	,0xE55E	,0x0001), // Multikey chain.
/*<!M><v><%parenright>                                             */ DEADTRANS( L')'	,0xE55F	,0xE55F	,0x0001), // Multikey chain.
/*<!M><v><%percent>                                                */ DEADTRANS( L'%'	,0xE560	,0xE560	,0x0001), // Multikey chain.
/*<!M><V><%percent>                                                */ DEADTRANS( L'%'	,0xE561	,0xE561	,0x0001), // Multikey chain.
/*<!M><v><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xE562	,0xE562	,0x0001), // Multikey chain.
/*<!M><V><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xE563	,0xE563	,0x0001), // Multikey chain.
/*<!M><v><%underscore>                                             */ DEADTRANS( L'_'	,0xE564	,0xE564	,0x0001), // Multikey chain.
/*<!M><v><e><r>                                                    */ DEADTRANS( L'r'	,0xE565	,0xE565	,0x0001), // Multikey chain.
/*<!M><V><E><R>                                                    */ DEADTRANS( L'R'	,0xE566	,0xE566	,0x0001), // Multikey chain.
/*<!M><v><i><e>                                                    */ DEADTRANS( L'e'	,0xE567	,0xE567	,0x0001), // Multikey chain.
/*<!M><V><I><E>                                                    */ DEADTRANS( L'E'	,0xE568	,0xE568	,0x0001), // Multikey chain.
/*<!M><v><i><r>                                                    */ DEADTRANS( L'r'	,0xE569	,0xE569	,0x0001), // Multikey chain.
/*<!M><V><I><R>                                                    */ DEADTRANS( L'R'	,0xE56A	,0xE56A	,0x0001), // Multikey chain.
/*<!M><v><n>                                                       */ DEADTRANS( L'n'	,0xE56B	,0xE56B	,0x0001), // Multikey chain.
/*<!M><V><N>                                                       */ DEADTRANS( L'N'	,0xE56C	,0xE56C	,0x0001), // Multikey chain.
/*<!M><v><v>                                                       */ DEADTRANS( L'v'	,0xE56D	,0xE56D	,0x0001), // Multikey chain.
/*<!M><w><w>                                                       */ DEADTRANS( L'w'	,0xE570	,0xE570	,0x0001), // Multikey chain.
/*<!M><x><o>                                                       */ DEADTRANS( L'o'	,0xE573	,0xE573	,0x0001), // Multikey chain.
/*<!M><X><O>                                                       */ DEADTRANS( L'O'	,0xE574	,0xE574	,0x0001), // Multikey chain.
/*<!M><x><t>                                                       */ DEADTRANS( L't'	,0xE575	,0xE575	,0x0001), // Multikey chain.
/*<!M><X><T>                                                       */ DEADTRANS( L'T'	,0xE576	,0xE576	,0x0001), // Multikey chain.
/*<!M><y><e>                                                       */ DEADTRANS( L'e'	,0xE579	,0xE579	,0x0001), // Multikey chain.
/*<!M><Y><E>                                                       */ DEADTRANS( L'E'	,0xE57A	,0xE57A	,0x0001), // Multikey chain.
/*<!M><z><%greater>                                                */ DEADTRANS( L'>'	,0xE57D	,0xE57D	,0x0001), // Multikey chain.
/*<!M><Z><%greater>                                                */ DEADTRANS( L'>'	,0xE57E	,0xE57E	,0x0001), // Multikey chain.
/*<!M><z><%less>                                                   */ DEADTRANS( L'<'	,0xE57F	,0xE57F	,0x0001), // Multikey chain.
/*<!M><Z><%less>                                                   */ DEADTRANS( L'<'	,0xE580	,0xE580	,0x0001), // Multikey chain.
/*<!M><~nbspace><%ampersand>                                       */ DEADTRANS( L'&'	,0xE581	,0xE581	,0x0001), // Multikey chain.
/*<!M><~nbspace><%apostrophe>                                      */ DEADTRANS( L'\''	,0xE582	,0xE582	,0x0001), // Multikey chain.
/*<!M><~nbspace><%aprightsinglequotemark>                          */ DEADTRANS( 0x2019	,0xE583	,0xE583	,0x0001), // Multikey chain.
/*<!M><~nbspace><%asterisk>                                        */ DEADTRANS( L'*'	,0xE584	,0xE584	,0x0001), // Multikey chain.
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L'\\'	,0xE585	,0xE585	,0x0001), // Multikey chain.
/*<!M><~nbspace><%backslash><%slash>                               */ DEADTRANS( L'/'	,0xE586	,0xE586	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L'/'	,0xE587	,0xE587	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE588	,0xE588	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%bar>                                       */ DEADTRANS( L'|'	,0xE589	,0xE589	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'|'	,0xE58A	,0xE58A	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%slash><%backslash>                         */ DEADTRANS( L'\\'	,0xE58B	,0xE58B	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xE58C	,0xE58C	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L'\\'	,0xE58D	,0xE58D	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L'e'	,0xE58E	,0xE58E	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><p>                                          */ DEADTRANS( L'p'	,0xE58F	,0xE58F	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'['	,0xE591	,0xE591	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bracketright>                                    */ DEADTRANS( L']'	,0xE592	,0xE592	,0x0001), // Multikey chain.
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'^'	,0xE593	,0xE593	,0x0001), // Multikey chain.
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( L':'	,0xE594	,0xE594	,0x0001), // Multikey chain.
/*<!M><~nbspace><%equal><%bar>                                     */ DEADTRANS( L'|'	,0xE595	,0xE595	,0x0001), // Multikey chain.
/*<!M><~nbspace><%equal>                                           */ DEADTRANS( L'='	,0xE596	,0xE596	,0x0001), // Multikey chain.
/*<!M><~nbspace><%equal><%minus>                                   */ DEADTRANS( L'-'	,0xE597	,0xE597	,0x0001), // Multikey chain.
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'!'	,0xE598	,0xE598	,0x0001), // Multikey chain.
/*<!M><~nbspace><%greater><%greater>                               */ DEADTRANS( L'>'	,0xE599	,0xE599	,0x0001), // Multikey chain.
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L'>'	,0xE59A	,0xE59A	,0x0001), // Multikey chain.
/*<!M><~nbspace><%greater><%minus>                                 */ DEADTRANS( L'-'	,0xE59B	,0xE59B	,0x0001), // Multikey chain.
/*<!M><~nbspace><%hash>                                            */ DEADTRANS( L'#'	,0xE59C	,0xE59C	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'<'	,0xE59D	,0xE59D	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( L'='	,0xE59E	,0xE59E	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less><%less>                                     */ DEADTRANS( L'<'	,0xE59F	,0xE59F	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less><%less><%minus>                             */ DEADTRANS( L'-'	,0xE5A0	,0xE5A0	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'-'	,0xE5A1	,0xE5A1	,0x0001), // Multikey chain.
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( L'~'	,0xE5A2	,0xE5A2	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus><%apostrophe>                              */ DEADTRANS( L'\''	,0xE5A3	,0xE5A3	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus><%aprightsinglequotemark>                  */ DEADTRANS( 0x2019	,0xE5A4	,0xE5A4	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'-'	,0xE5A5	,0xE5A5	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus><%bracketright>                            */ DEADTRANS( L']'	,0xE5A6	,0xE5A6	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus><o>                                        */ DEADTRANS( L'o'	,0xE5A7	,0xE5A7	,0x0001), // Multikey chain.
/*<!M><~nbspace><%minus><s>                                        */ DEADTRANS( L's'	,0xE5A8	,0xE5A8	,0x0001), // Multikey chain.
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'('	,0xE5A9	,0xE5A9	,0x0001), // Multikey chain.
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L')'	,0xE5AA	,0xE5AA	,0x0001), // Multikey chain.
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'.'	,0xE5AB	,0xE5AB	,0x0001), // Multikey chain.
/*<!M><~nbspace><%period><c>                                       */ DEADTRANS( L'c'	,0xE5AC	,0xE5AC	,0x0001), // Multikey chain.
/*<!M><~nbspace><%period><v>                                       */ DEADTRANS( L'v'	,0xE5AD	,0xE5AD	,0x0001), // Multikey chain.
/*<!M><~nbspace><%period><V>                                       */ DEADTRANS( L'V'	,0xE5AE	,0xE5AE	,0x0001), // Multikey chain.
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'+'	,0xE5AF	,0xE5AF	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%backslash>                               */ DEADTRANS( L'\\'	,0xE5B0	,0xE5B0	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%hash><%underscore>                       */ DEADTRANS( L'_'	,0xE5B1	,0xE5B1	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%slash>                                   */ DEADTRANS( L'/'	,0xE5B2	,0xE5B2	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%underscore>                              */ DEADTRANS( L'_'	,0xE5B3	,0xE5B3	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash>                                           */ DEADTRANS( L'/'	,0xE5B4	,0xE5B4	,0x0001), // Multikey chain.
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L'~'	,0xE5B5	,0xE5B5	,0x0001), // Multikey chain.
/*<!M><~nbspace><%tilde><%equal><%slash>                           */ DEADTRANS( L'/'	,0xE5B6	,0xE5B6	,0x0001), // Multikey chain.
/*<!M><~nbspace><%tilde><%equal>                                   */ DEADTRANS( L'='	,0xE5B7	,0xE5B7	,0x0001), // Multikey chain.
/*<!M><~nbspace><%tilde><%slash>                                   */ DEADTRANS( L'/'	,0xE5B8	,0xE5B8	,0x0001), // Multikey chain.
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xE5B9	,0xE5B9	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'_'	,0xE5BA	,0xE5BA	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%minus>                              */ DEADTRANS( L'-'	,0xE5BB	,0xE5BB	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L'v'	,0xE5BC	,0xE5BC	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L'V'	,0xE5BD	,0xE5BD	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><e><%backslash>                       */ DEADTRANS( L'\\'	,0xE5BE	,0xE5BE	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><e>                                   */ DEADTRANS( L'e'	,0xE5BF	,0xE5BF	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><p>                                   */ DEADTRANS( L'p'	,0xE5C0	,0xE5C0	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><u>                                   */ DEADTRANS( L'u'	,0xE5C1	,0xE5C1	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><v>                                   */ DEADTRANS( L'v'	,0xE5C2	,0xE5C2	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><X>                                   */ DEADTRANS( L'X'	,0xE5C3	,0xE5C3	,0x0001), // Multikey chain.
/*<!M><~nbspace><2>                                                */ DEADTRANS( L'2'	,0xE5C4	,0xE5C4	,0x0001), // Multikey chain.
/*<!M><~nbspace><3>                                                */ DEADTRANS( L'3'	,0xE5C5	,0xE5C5	,0x0001), // Multikey chain.
/*<!M><~nbspace><A>                                                */ DEADTRANS( L'A'	,0xE5C6	,0xE5C6	,0x0001), // Multikey chain.
/*<!M><~nbspace><A><%underscore>                                   */ DEADTRANS( L'_'	,0xE5C7	,0xE5C7	,0x0001), // Multikey chain.
/*<!M><~nbspace><a>                                                */ DEADTRANS( L'a'	,0xE5C8	,0xE5C8	,0x0001), // Multikey chain.
/*<!M><~nbspace><b>                                                */ DEADTRANS( L'b'	,0xE5C9	,0xE5C9	,0x0001), // Multikey chain.
/*<!M><~nbspace><c><%backslash>                                    */ DEADTRANS( L'\\'	,0xE5CA	,0xE5CA	,0x0001), // Multikey chain.
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( L'c'	,0xE5CB	,0xE5CB	,0x0001), // Multikey chain.
/*<!M><~nbspace><c>                                                */ DEADTRANS( L'c'	,0xE5CC	,0xE5CC	,0x0001), // Multikey chain.
/*<!M><~nbspace><e><e><%bar>                                       */ DEADTRANS( L'|'	,0xE5CD	,0xE5CD	,0x0001), // Multikey chain.
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L'e'	,0xE5CE	,0xE5CE	,0x0001), // Multikey chain.
/*<!M><~nbspace><n>                                                */ DEADTRANS( L'n'	,0xE5CF	,0xE5CF	,0x0001), // Multikey chain.
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'O'	,0xE5D0	,0xE5D0	,0x0001), // Multikey chain.
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'o'	,0xE5D1	,0xE5D1	,0x0001), // Multikey chain.
/*<!M><~nbspace><o><%minus>                                        */ DEADTRANS( L'-'	,0xE5D2	,0xE5D2	,0x0001), // Multikey chain.
/*<!M><~nbspace><R>                                                */ DEADTRANS( L'R'	,0xE5D3	,0xE5D3	,0x0001), // Multikey chain.
/*<!M><~nbspace><r>                                                */ DEADTRANS( L'r'	,0xE5D4	,0xE5D4	,0x0001), // Multikey chain.
/*<!M><~nbspace><S>                                                */ DEADTRANS( L'S'	,0xE5D5	,0xE5D5	,0x0001), // Multikey chain.
/*<!M><~nbspace><S><S>                                             */ DEADTRANS( L'S'	,0xE5D6	,0xE5D6	,0x0001), // Multikey chain.
/*<!M><~nbspace><T>                                                */ DEADTRANS( L'T'	,0xE5D7	,0xE5D7	,0x0001), // Multikey chain.
/*<!M><~nbspace><V>                                                */ DEADTRANS( L'V'	,0xE5D8	,0xE5D8	,0x0001), // Multikey chain.
/*<!M><~nbspace><Y>                                                */ DEADTRANS( L'Y'	,0xE5D9	,0xE5D9	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xE5DA	,0xE5DA	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%backslash>                             */ DEADTRANS( L'\\'	,0xE5DB	,0xE5DB	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%bar>                                   */ DEADTRANS( L'|'	,0xE5DC	,0xE5DC	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%bracketleft>                           */ DEADTRANS( L'['	,0xE5DD	,0xE5DD	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%bracketright>                          */ DEADTRANS( L']'	,0xE5DE	,0xE5DE	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%equal>                                 */ DEADTRANS( L'='	,0xE5DF	,0xE5DF	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%greater>                               */ DEADTRANS( L'>'	,0xE5E0	,0xE5E0	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%less>                                  */ DEADTRANS( L'<'	,0xE5E1	,0xE5E1	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%minus>                                 */ DEADTRANS( L'-'	,0xE5E2	,0xE5E2	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( L'/'	,0xE5E3	,0xE5E3	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><3>                                      */ DEADTRANS( L'3'	,0xE5E4	,0xE5E4	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><o>                                      */ DEADTRANS( L'o'	,0xE5E5	,0xE5E5	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( L'T'	,0xE5E6	,0xE5E6	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk>                    */ DEADTRANS( L'*'	,0xE5E7	,0xE5E7	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE5E8	,0xE5E8	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE5E9	,0xE5E9	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~nbspace><~space>                       */ DEADTRANS( L' '	,0xE5EA	,0xE5EA	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~space><%asterisk>                      */ DEADTRANS( L'*'	,0xE5EB	,0xE5EB	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L' '	,0xE5EC	,0xE5EC	,0x0001), // Multikey chain.
/*<!M><~nbspace><~nbspace><~space><~space>                         */ DEADTRANS( L' '	,0xE5ED	,0xE5ED	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L' '	,0xE5EE	,0xE5EE	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%backslash>                               */ DEADTRANS( L'\\'	,0xE5EF	,0xE5EF	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%bar>                                     */ DEADTRANS( L'|'	,0xE5F0	,0xE5F0	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%bracketleft>                             */ DEADTRANS( L'['	,0xE5F1	,0xE5F1	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%bracketright>                            */ DEADTRANS( L']'	,0xE5F2	,0xE5F2	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%equal>                                   */ DEADTRANS( L'='	,0xE5F3	,0xE5F3	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%greater>                                 */ DEADTRANS( L'>'	,0xE5F4	,0xE5F4	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%less>                                    */ DEADTRANS( L'<'	,0xE5F5	,0xE5F5	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%minus>                                   */ DEADTRANS( L'-'	,0xE5F6	,0xE5F6	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( L'/'	,0xE5F7	,0xE5F7	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><3>                                        */ DEADTRANS( L'3'	,0xE5F8	,0xE5F8	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><o>                                        */ DEADTRANS( L'o'	,0xE5F9	,0xE5F9	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( L'T'	,0xE5FA	,0xE5FA	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><~space><%asterisk>                        */ DEADTRANS( L'*'	,0xE5FB	,0xE5FB	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L' '	,0xE5FC	,0xE5FC	,0x0001), // Multikey chain.
/*<!M><~nbspace><~space><~space><~space>                           */ DEADTRANS( L' '	,0xE5FD	,0xE5FD	,0x0001), // Multikey chain.
/*<!M><~space><%ampersand>                                         */ DEADTRANS( L'&'	,0xE5FF	,0xE5FF	,0x0001), // Multikey chain.
/*<!M><~space><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE600	,0xE600	,0x0001), // Multikey chain.
/*<!M><~space><%aprightsinglequotemark>                            */ DEADTRANS( 0x2019	,0xE601	,0xE601	,0x0001), // Multikey chain.
/*<!M><~space><%asterisk>                                          */ DEADTRANS( L'*'	,0xE602	,0xE602	,0x0001), // Multikey chain.
/*<!M><~space><%backslash>                                         */ DEADTRANS( L'\\'	,0xE603	,0xE603	,0x0001), // Multikey chain.
/*<!M><~space><%backslash><%slash>                                 */ DEADTRANS( L'/'	,0xE604	,0xE604	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L'/'	,0xE605	,0xE605	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%bar><%bar>                                   */ DEADTRANS( L'|'	,0xE606	,0xE606	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE607	,0xE607	,0x0001), // Multikey chain.
/*<!M><~space><%bar>                                               */ DEADTRANS( L'|'	,0xE608	,0xE608	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%slash><%backslash>                           */ DEADTRANS( L'\\'	,0xE609	,0xE609	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%slash>                                       */ DEADTRANS( L'/'	,0xE60A	,0xE60A	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L'\\'	,0xE60B	,0xE60B	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L'e'	,0xE60C	,0xE60C	,0x0001), // Multikey chain.
/*<!M><~space><%bar><p>                                            */ DEADTRANS( L'p'	,0xE60D	,0xE60D	,0x0001), // Multikey chain.
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'['	,0xE60F	,0xE60F	,0x0001), // Multikey chain.
/*<!M><~space><%bracketright>                                      */ DEADTRANS( L']'	,0xE610	,0xE610	,0x0001), // Multikey chain.
/*<!M><~space><%circum>                                            */ DEADTRANS( L'^'	,0xE611	,0xE611	,0x0001), // Multikey chain.
/*<!M><~space><%colon>                                             */ DEADTRANS( L':'	,0xE612	,0xE612	,0x0001), // Multikey chain.
/*<!M><~space><%equal><%bar>                                       */ DEADTRANS( L'|'	,0xE613	,0xE613	,0x0001), // Multikey chain.
/*<!M><~space><%equal>                                             */ DEADTRANS( L'='	,0xE614	,0xE614	,0x0001), // Multikey chain.
/*<!M><~space><%equal><%minus>                                     */ DEADTRANS( L'-'	,0xE615	,0xE615	,0x0001), // Multikey chain.
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'!'	,0xE616	,0xE616	,0x0001), // Multikey chain.
/*<!M><~space><%greater><%greater>                                 */ DEADTRANS( L'>'	,0xE617	,0xE617	,0x0001), // Multikey chain.
/*<!M><~space><%greater>                                           */ DEADTRANS( L'>'	,0xE618	,0xE618	,0x0001), // Multikey chain.
/*<!M><~space><%greater><%minus>                                   */ DEADTRANS( L'-'	,0xE619	,0xE619	,0x0001), // Multikey chain.
/*<!M><~space><%hash>                                              */ DEADTRANS( L'#'	,0xE61A	,0xE61A	,0x0001), // Multikey chain.
/*<!M><~space><%less>                                              */ DEADTRANS( L'<'	,0xE61B	,0xE61B	,0x0001), // Multikey chain.
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( L'='	,0xE61C	,0xE61C	,0x0001), // Multikey chain.
/*<!M><~space><%less><%less>                                       */ DEADTRANS( L'<'	,0xE61D	,0xE61D	,0x0001), // Multikey chain.
/*<!M><~space><%less><%less><%minus>                               */ DEADTRANS( L'-'	,0xE61E	,0xE61E	,0x0001), // Multikey chain.
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'-'	,0xE61F	,0xE61F	,0x0001), // Multikey chain.
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( L'~'	,0xE620	,0xE620	,0x0001), // Multikey chain.
/*<!M><~space><%minus><%apostrophe>                                */ DEADTRANS( L'\''	,0xE621	,0xE621	,0x0001), // Multikey chain.
/*<!M><~space><%minus><%aprightsinglequotemark>                    */ DEADTRANS( 0x2019	,0xE622	,0xE622	,0x0001), // Multikey chain.
/*<!M><~space><%minus>                                             */ DEADTRANS( L'-'	,0xE623	,0xE623	,0x0001), // Multikey chain.
/*<!M><~space><%minus><%bracketright>                              */ DEADTRANS( L']'	,0xE624	,0xE624	,0x0001), // Multikey chain.
/*<!M><~space><%minus><o>                                          */ DEADTRANS( L'o'	,0xE625	,0xE625	,0x0001), // Multikey chain.
/*<!M><~space><%minus><s>                                          */ DEADTRANS( L's'	,0xE626	,0xE626	,0x0001), // Multikey chain.
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'('	,0xE627	,0xE627	,0x0001), // Multikey chain.
/*<!M><~space><%parenright>                                        */ DEADTRANS( L')'	,0xE628	,0xE628	,0x0001), // Multikey chain.
/*<!M><~space><%period>                                            */ DEADTRANS( L'.'	,0xE629	,0xE629	,0x0001), // Multikey chain.
/*<!M><~space><%period><c>                                         */ DEADTRANS( L'c'	,0xE62A	,0xE62A	,0x0001), // Multikey chain.
/*<!M><~space><%period><v>                                         */ DEADTRANS( L'v'	,0xE62B	,0xE62B	,0x0001), // Multikey chain.
/*<!M><~space><%period><V>                                         */ DEADTRANS( L'V'	,0xE62C	,0xE62C	,0x0001), // Multikey chain.
/*<!M><~space><%plus>                                              */ DEADTRANS( L'+'	,0xE62D	,0xE62D	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%backslash>                                 */ DEADTRANS( L'\\'	,0xE62E	,0xE62E	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%hash><%underscore>                         */ DEADTRANS( L'_'	,0xE62F	,0xE62F	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xE630	,0xE630	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%underscore>                                */ DEADTRANS( L'_'	,0xE631	,0xE631	,0x0001), // Multikey chain.
/*<!M><~space><%slash>                                             */ DEADTRANS( L'/'	,0xE632	,0xE632	,0x0001), // Multikey chain.
/*<!M><~space><%tilde>                                             */ DEADTRANS( L'~'	,0xE633	,0xE633	,0x0001), // Multikey chain.
/*<!M><~space><%tilde><%equal><%slash>                             */ DEADTRANS( L'/'	,0xE634	,0xE634	,0x0001), // Multikey chain.
/*<!M><~space><%tilde><%equal>                                     */ DEADTRANS( L'='	,0xE635	,0xE635	,0x0001), // Multikey chain.
/*<!M><~space><%tilde><%slash>                                     */ DEADTRANS( L'/'	,0xE636	,0xE636	,0x0001), // Multikey chain.
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( L'~'	,0xE637	,0xE637	,0x0001), // Multikey chain.
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'_'	,0xE638	,0xE638	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%minus>                                */ DEADTRANS( L'-'	,0xE639	,0xE639	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L'v'	,0xE63A	,0xE63A	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L'V'	,0xE63B	,0xE63B	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><e><%backslash>                         */ DEADTRANS( L'\\'	,0xE63C	,0xE63C	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><e>                                     */ DEADTRANS( L'e'	,0xE63D	,0xE63D	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><p>                                     */ DEADTRANS( L'p'	,0xE63E	,0xE63E	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><u>                                     */ DEADTRANS( L'u'	,0xE63F	,0xE63F	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><v>                                     */ DEADTRANS( L'v'	,0xE640	,0xE640	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><X>                                     */ DEADTRANS( L'X'	,0xE641	,0xE641	,0x0001), // Multikey chain.
/*<!M><~space><2>                                                  */ DEADTRANS( L'2'	,0xE642	,0xE642	,0x0001), // Multikey chain.
/*<!M><~space><3>                                                  */ DEADTRANS( L'3'	,0xE643	,0xE643	,0x0001), // Multikey chain.
/*<!M><~space><A>                                                  */ DEADTRANS( L'A'	,0xE644	,0xE644	,0x0001), // Multikey chain.
/*<!M><~space><A><%underscore>                                     */ DEADTRANS( L'_'	,0xE645	,0xE645	,0x0001), // Multikey chain.
/*<!M><~space><a>                                                  */ DEADTRANS( L'a'	,0xE646	,0xE646	,0x0001), // Multikey chain.
/*<!M><~space><b>                                                  */ DEADTRANS( L'b'	,0xE647	,0xE647	,0x0001), // Multikey chain.
/*<!M><~space><c><%backslash>                                      */ DEADTRANS( L'\\'	,0xE648	,0xE648	,0x0001), // Multikey chain.
/*<!M><~space><c><c>                                               */ DEADTRANS( L'c'	,0xE649	,0xE649	,0x0001), // Multikey chain.
/*<!M><~space><c>                                                  */ DEADTRANS( L'c'	,0xE64A	,0xE64A	,0x0001), // Multikey chain.
/*<!M><~space><e><e><%bar>                                         */ DEADTRANS( L'|'	,0xE64B	,0xE64B	,0x0001), // Multikey chain.
/*<!M><~space><e><e>                                               */ DEADTRANS( L'e'	,0xE64C	,0xE64C	,0x0001), // Multikey chain.
/*<!M><~space><n>                                                  */ DEADTRANS( L'n'	,0xE64D	,0xE64D	,0x0001), // Multikey chain.
/*<!M><~space><O>                                                  */ DEADTRANS( L'O'	,0xE64E	,0xE64E	,0x0001), // Multikey chain.
/*<!M><~space><o>                                                  */ DEADTRANS( L'o'	,0xE64F	,0xE64F	,0x0001), // Multikey chain.
/*<!M><~space><o><%minus>                                          */ DEADTRANS( L'-'	,0xE650	,0xE650	,0x0001), // Multikey chain.
/*<!M><~space><R>                                                  */ DEADTRANS( L'R'	,0xE651	,0xE651	,0x0001), // Multikey chain.
/*<!M><~space><r>                                                  */ DEADTRANS( L'r'	,0xE652	,0xE652	,0x0001), // Multikey chain.
/*<!M><~space><S>                                                  */ DEADTRANS( L'S'	,0xE653	,0xE653	,0x0001), // Multikey chain.
/*<!M><~space><S><S>                                               */ DEADTRANS( L'S'	,0xE654	,0xE654	,0x0001), // Multikey chain.
/*<!M><~space><T>                                                  */ DEADTRANS( L'T'	,0xE655	,0xE655	,0x0001), // Multikey chain.
/*<!M><~space><V>                                                  */ DEADTRANS( L'V'	,0xE656	,0xE656	,0x0001), // Multikey chain.
/*<!M><~space><Y>                                                  */ DEADTRANS( L'Y'	,0xE657	,0xE657	,0x0001), // Multikey chain.
/*<!M><~space><~space>                                             */ DEADTRANS( L' '	,0xE658	,0xE658	,0x0001), // Multikey chain.
/*<!M><~space><~space><%backslash>                                 */ DEADTRANS( L'\\'	,0xE659	,0xE659	,0x0001), // Multikey chain.
/*<!M><~space><~space><%bar>                                       */ DEADTRANS( L'|'	,0xE65A	,0xE65A	,0x0001), // Multikey chain.
/*<!M><~space><~space><%bracketleft>                               */ DEADTRANS( L'['	,0xE65B	,0xE65B	,0x0001), // Multikey chain.
/*<!M><~space><~space><%bracketright>                              */ DEADTRANS( L']'	,0xE65C	,0xE65C	,0x0001), // Multikey chain.
/*<!M><~space><~space><%equal>                                     */ DEADTRANS( L'='	,0xE65D	,0xE65D	,0x0001), // Multikey chain.
/*<!M><~space><~space><%greater>                                   */ DEADTRANS( L'>'	,0xE65E	,0xE65E	,0x0001), // Multikey chain.
/*<!M><~space><~space><%less>                                      */ DEADTRANS( L'<'	,0xE65F	,0xE65F	,0x0001), // Multikey chain.
/*<!M><~space><~space><%minus>                                     */ DEADTRANS( L'-'	,0xE660	,0xE660	,0x0001), // Multikey chain.
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( L'/'	,0xE661	,0xE661	,0x0001), // Multikey chain.
/*<!M><~space><~space><3>                                          */ DEADTRANS( L'3'	,0xE662	,0xE662	,0x0001), // Multikey chain.
/*<!M><~space><~space><o>                                          */ DEADTRANS( L'o'	,0xE663	,0xE663	,0x0001), // Multikey chain.
/*<!M><~space><~space><T>                                          */ DEADTRANS( L'T'	,0xE664	,0xE664	,0x0001), // Multikey chain.
/*<!M><~space><~space><~space><%asterisk>                          */ DEADTRANS( L'*'	,0xE665	,0xE665	,0x0001), // Multikey chain.
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L' '	,0xE666	,0xE666	,0x0001), // Multikey chain.
/*<!M><~space><~space><~space><~space>                             */ DEADTRANS( L' '	,0xE667	,0xE667	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%asterisk>                                     */ DEADTRANS( L'*'	,0xE669	,0xE669	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%colon>                                   */ DEADTRANS( L':'	,0xE66A	,0xE66A	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%exclam><%parenleft>                      */ DEADTRANS( L'('	,0xE66B	,0xE66B	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%exclam><%parenright>                     */ DEADTRANS( L')'	,0xE66C	,0xE66C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%exclam>                                  */ DEADTRANS( L'!'	,0xE66D	,0xE66D	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%parenleft><%exclam>                      */ DEADTRANS( L'!'	,0xE66E	,0xE66E	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%parenleft>                               */ DEADTRANS( L'('	,0xE66F	,0xE66F	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%parenright><%exclam>                     */ DEADTRANS( L'!'	,0xE670	,0xE670	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at><%parenright>                              */ DEADTRANS( L')'	,0xE671	,0xE671	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%at>                                           */ DEADTRANS( L'@'	,0xE672	,0xE672	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%bar><%grave>                                  */ DEADTRANS( L'`'	,0xE673	,0xE673	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%bar>                                          */ DEADTRANS( L'|'	,0xE674	,0xE674	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%colon><%at>                                   */ DEADTRANS( L'@'	,0xE675	,0xE675	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%colon>                                        */ DEADTRANS( L':'	,0xE676	,0xE676	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%comma>                                        */ DEADTRANS( L','	,0xE677	,0xE677	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%at><%parenleft>                      */ DEADTRANS( L'('	,0xE678	,0xE678	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%at><%parenright>                     */ DEADTRANS( L')'	,0xE679	,0xE679	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%at>                                  */ DEADTRANS( L'@'	,0xE67A	,0xE67A	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE67B	,0xE67B	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE67C	,0xE67C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%grave>                                        */ DEADTRANS( L'`'	,0xE67D	,0xE67D	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%grave><%bar>                                  */ DEADTRANS( L'|'	,0xE67E	,0xE67E	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%hash>                                         */ DEADTRANS( L'#'	,0xE67F	,0xE67F	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%hash><%hash>                                  */ DEADTRANS( L'#'	,0xE680	,0xE680	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%less>                                         */ DEADTRANS( L'<'	,0xE681	,0xE681	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%at><%exclam>                      */ DEADTRANS( L'!'	,0xE682	,0xE682	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%at>                               */ DEADTRANS( L'@'	,0xE683	,0xE683	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE684	,0xE684	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright><%at><%exclam>                     */ DEADTRANS( L'!'	,0xE685	,0xE685	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright><%at>                              */ DEADTRANS( L'@'	,0xE686	,0xE686	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE687	,0xE687	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright>                                   */ DEADTRANS( L')'	,0xE688	,0xE688	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%period><%period>                              */ DEADTRANS( L'.'	,0xE689	,0xE689	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%period>                                       */ DEADTRANS( L'.'	,0xE68A	,0xE68A	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%plus>                                         */ DEADTRANS( L'+'	,0xE68B	,0xE68B	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%slash>                                        */ DEADTRANS( L'/'	,0xE68C	,0xE68C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%tilde>                                        */ DEADTRANS( L'~'	,0xE68D	,0xE68D	,0x0001), // Multikey chain.
/*<!M><%asterisk><%apostrophe>                                     */ DEADTRANS( L'\''	,0xE68E	,0xE68E	,0x0001), // Multikey chain.
/*<!M><%asterisk><%asterisk>                                       */ DEADTRANS( L'*'	,0xE68F	,0xE68F	,0x0001), // Multikey chain.
/*<!M><%asterisk><%colon>                                          */ DEADTRANS( L':'	,0xE690	,0xE690	,0x0001), // Multikey chain.
/*<!M><%asterisk><%dollar>                                         */ DEADTRANS( L'$'	,0xE691	,0xE691	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash>                                           */ DEADTRANS( L'#'	,0xE692	,0xE692	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><%hash>                                    */ DEADTRANS( L'#'	,0xE693	,0xE693	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><%hash><%hash>                             */ DEADTRANS( L'#'	,0xE694	,0xE694	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><%hash><%hash><%hash>                      */ DEADTRANS( L'#'	,0xE695	,0xE695	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><1>                                        */ DEADTRANS( L'1'	,0xE696	,0xE696	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><2>                                        */ DEADTRANS( L'2'	,0xE697	,0xE697	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><3>                                        */ DEADTRANS( L'3'	,0xE698	,0xE698	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><4>                                        */ DEADTRANS( L'4'	,0xE699	,0xE699	,0x0001), // Multikey chain.
/*<!M><%asterisk><%hash><5>                                        */ DEADTRANS( L'5'	,0xE69A	,0xE69A	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%colon>                                   */ DEADTRANS( L':'	,0xE69B	,0xE69B	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%exclam><%parenleft>                      */ DEADTRANS( L'('	,0xE69C	,0xE69C	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%exclam><%parenright>                     */ DEADTRANS( L')'	,0xE69D	,0xE69D	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%exclam>                                  */ DEADTRANS( L'!'	,0xE69E	,0xE69E	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%parenleft><%exclam>                      */ DEADTRANS( L'!'	,0xE69F	,0xE69F	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%parenleft>                               */ DEADTRANS( L'('	,0xE6A0	,0xE6A0	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%parenright><%exclam>                     */ DEADTRANS( L'!'	,0xE6A1	,0xE6A1	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe><%parenright>                              */ DEADTRANS( L')'	,0xE6A2	,0xE6A2	,0x0001), // Multikey chain.
/*<!M><%at><%apostrophe>                                           */ DEADTRANS( L'\''	,0xE6A3	,0xE6A3	,0x0001), // Multikey chain.
/*<!M><%at><%at>                                                   */ DEADTRANS( L'@'	,0xE6A5	,0xE6A5	,0x0001), // Multikey chain.
/*<!M><%at><%backslash>                                            */ DEADTRANS( L'\\'	,0xE6A6	,0xE6A6	,0x0001), // Multikey chain.
/*<!M><%at><%backslash><%quotedbl>                                 */ DEADTRANS( L'"'	,0xE6A7	,0xE6A7	,0x0001), // Multikey chain.
/*<!M><%at><%backslash><%quotEuroSign>                             */ DEADTRANS( 0x20AC	,0xE6A8	,0xE6A8	,0x0001), // Multikey chain.
/*<!M><%at><%backslash><%tilde>                                    */ DEADTRANS( L'~'	,0xE6A9	,0xE6A9	,0x0001), // Multikey chain.
/*<!M><%at><%bar>                                                  */ DEADTRANS( L'|'	,0xE6AA	,0xE6AA	,0x0001), // Multikey chain.
/*<!M><%at><%bracketleft>                                          */ DEADTRANS( L'['	,0xE6AB	,0xE6AB	,0x0001), // Multikey chain.
/*<!M><%at><%bracketright>                                         */ DEADTRANS( L']'	,0xE6AC	,0xE6AC	,0x0001), // Multikey chain.
/*<!M><%at><%colon><%apostrophe>                                   */ DEADTRANS( L'\''	,0xE6AD	,0xE6AD	,0x0001), // Multikey chain.
/*<!M><%at><%colon><%grave>                                        */ DEADTRANS( L'`'	,0xE6AE	,0xE6AE	,0x0001), // Multikey chain.
/*<!M><%at><%colon><%less>                                         */ DEADTRANS( L'<'	,0xE6AF	,0xE6AF	,0x0001), // Multikey chain.
/*<!M><%at><%colon><%quotedbl>                                     */ DEADTRANS( L'"'	,0xE6B0	,0xE6B0	,0x0001), // Multikey chain.
/*<!M><%at><%colon><%quotEuroSign>                                 */ DEADTRANS( 0x20AC	,0xE6B1	,0xE6B1	,0x0001), // Multikey chain.
/*<!M><%at><%colon>                                                */ DEADTRANS( L':'	,0xE6B2	,0xE6B2	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%apostrophe><%parenleft>                      */ DEADTRANS( L'('	,0xE6B3	,0xE6B3	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%apostrophe><%parenright>                     */ DEADTRANS( L')'	,0xE6B4	,0xE6B4	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE6B5	,0xE6B5	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%grave><%parenleft>                           */ DEADTRANS( L'('	,0xE6B6	,0xE6B6	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%grave><%parenright>                          */ DEADTRANS( L')'	,0xE6B7	,0xE6B7	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%grave>                                       */ DEADTRANS( L'`'	,0xE6B8	,0xE6B8	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%less><%parenleft>                            */ DEADTRANS( L'('	,0xE6B9	,0xE6B9	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%less><%parenright>                           */ DEADTRANS( L')'	,0xE6BA	,0xE6BA	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%less>                                        */ DEADTRANS( L'<'	,0xE6BB	,0xE6BB	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenleft><%apostrophe>                      */ DEADTRANS( L'\''	,0xE6BC	,0xE6BC	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenleft><%grave>                           */ DEADTRANS( L'`'	,0xE6BD	,0xE6BD	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenleft><%less>                            */ DEADTRANS( L'<'	,0xE6BE	,0xE6BE	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenleft>                                   */ DEADTRANS( L'('	,0xE6BF	,0xE6BF	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenright><%apostrophe>                     */ DEADTRANS( L'\''	,0xE6C0	,0xE6C0	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenright><%grave>                          */ DEADTRANS( L'`'	,0xE6C1	,0xE6C1	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenright><%less>                           */ DEADTRANS( L'<'	,0xE6C2	,0xE6C2	,0x0001), // Multikey chain.
/*<!M><%at><%exclam><%parenright>                                  */ DEADTRANS( L')'	,0xE6C3	,0xE6C3	,0x0001), // Multikey chain.
/*<!M><%at><%exclam>                                               */ DEADTRANS( L'!'	,0xE6C4	,0xE6C4	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%colon>                                        */ DEADTRANS( L':'	,0xE6C5	,0xE6C5	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%exclam><%parenleft>                           */ DEADTRANS( L'('	,0xE6C6	,0xE6C6	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%exclam><%parenright>                          */ DEADTRANS( L')'	,0xE6C7	,0xE6C7	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%exclam>                                       */ DEADTRANS( L'!'	,0xE6C8	,0xE6C8	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%parenleft><%exclam>                           */ DEADTRANS( L'!'	,0xE6C9	,0xE6C9	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%parenleft>                                    */ DEADTRANS( L'('	,0xE6CA	,0xE6CA	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%parenright><%exclam>                          */ DEADTRANS( L'!'	,0xE6CB	,0xE6CB	,0x0001), // Multikey chain.
/*<!M><%at><%grave><%parenright>                                   */ DEADTRANS( L')'	,0xE6CC	,0xE6CC	,0x0001), // Multikey chain.
/*<!M><%at><%grave>                                                */ DEADTRANS( L'`'	,0xE6CD	,0xE6CD	,0x0001), // Multikey chain.
/*<!M><%at><%greater>                                              */ DEADTRANS( L'>'	,0xE6CE	,0xE6CE	,0x0001), // Multikey chain.
/*<!M><%at><%less><%colon>                                         */ DEADTRANS( L':'	,0xE6CF	,0xE6CF	,0x0001), // Multikey chain.
/*<!M><%at><%less><%exclam><%parenleft>                            */ DEADTRANS( L'('	,0xE6D0	,0xE6D0	,0x0001), // Multikey chain.
/*<!M><%at><%less><%exclam><%parenright>                           */ DEADTRANS( L')'	,0xE6D1	,0xE6D1	,0x0001), // Multikey chain.
/*<!M><%at><%less><%exclam>                                        */ DEADTRANS( L'!'	,0xE6D2	,0xE6D2	,0x0001), // Multikey chain.
/*<!M><%at><%less><%parenleft><%exclam>                            */ DEADTRANS( L'!'	,0xE6D3	,0xE6D3	,0x0001), // Multikey chain.
/*<!M><%at><%less><%parenleft>                                     */ DEADTRANS( L'('	,0xE6D4	,0xE6D4	,0x0001), // Multikey chain.
/*<!M><%at><%less><%parenright><%exclam>                           */ DEADTRANS( L'!'	,0xE6D5	,0xE6D5	,0x0001), // Multikey chain.
/*<!M><%at><%less><%parenright>                                    */ DEADTRANS( L')'	,0xE6D6	,0xE6D6	,0x0001), // Multikey chain.
/*<!M><%at><%less>                                                 */ DEADTRANS( L'<'	,0xE6D7	,0xE6D7	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%apostrophe><%exclam>                      */ DEADTRANS( L'!'	,0xE6D8	,0xE6D8	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%apostrophe>                               */ DEADTRANS( L'\''	,0xE6D9	,0xE6D9	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%exclam><%apostrophe>                      */ DEADTRANS( L'\''	,0xE6DA	,0xE6DA	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%exclam><%grave>                           */ DEADTRANS( L'`'	,0xE6DB	,0xE6DB	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%exclam><%less>                            */ DEADTRANS( L'<'	,0xE6DC	,0xE6DC	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%exclam>                                   */ DEADTRANS( L'!'	,0xE6DD	,0xE6DD	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%grave><%exclam>                           */ DEADTRANS( L'!'	,0xE6DE	,0xE6DE	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%grave>                                    */ DEADTRANS( L'`'	,0xE6DF	,0xE6DF	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%less><%exclam>                            */ DEADTRANS( L'!'	,0xE6E0	,0xE6E0	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft><%less>                                     */ DEADTRANS( L'<'	,0xE6E1	,0xE6E1	,0x0001), // Multikey chain.
/*<!M><%at><%parenleft>                                            */ DEADTRANS( L'('	,0xE6E2	,0xE6E2	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%apostrophe><%exclam>                     */ DEADTRANS( L'!'	,0xE6E3	,0xE6E3	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%apostrophe>                              */ DEADTRANS( L'\''	,0xE6E4	,0xE6E4	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%exclam><%apostrophe>                     */ DEADTRANS( L'\''	,0xE6E5	,0xE6E5	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%exclam><%grave>                          */ DEADTRANS( L'`'	,0xE6E6	,0xE6E6	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%exclam><%less>                           */ DEADTRANS( L'<'	,0xE6E7	,0xE6E7	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%exclam>                                  */ DEADTRANS( L'!'	,0xE6E8	,0xE6E8	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%grave><%exclam>                          */ DEADTRANS( L'!'	,0xE6E9	,0xE6E9	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%grave>                                   */ DEADTRANS( L'`'	,0xE6EA	,0xE6EA	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%less><%exclam>                           */ DEADTRANS( L'!'	,0xE6EB	,0xE6EB	,0x0001), // Multikey chain.
/*<!M><%at><%parenright><%less>                                    */ DEADTRANS( L'<'	,0xE6EC	,0xE6EC	,0x0001), // Multikey chain.
/*<!M><%at><%parenright>                                           */ DEADTRANS( L')'	,0xE6ED	,0xE6ED	,0x0001), // Multikey chain.
/*<!M><%at><%quotedbl><%backslash>                                 */ DEADTRANS( L'\\'	,0xE6EE	,0xE6EE	,0x0001), // Multikey chain.
/*<!M><%at><%quotedbl><%colon>                                     */ DEADTRANS( L':'	,0xE6EF	,0xE6EF	,0x0001), // Multikey chain.
/*<!M><%at><%quotedbl>                                             */ DEADTRANS( L'"'	,0xE6F0	,0xE6F0	,0x0001), // Multikey chain.
/*<!M><%at><%quotEuroSign><%backslash>                             */ DEADTRANS( L'\\'	,0xE6F1	,0xE6F1	,0x0001), // Multikey chain.
/*<!M><%at><%quotEuroSign><%colon>                                 */ DEADTRANS( L':'	,0xE6F2	,0xE6F2	,0x0001), // Multikey chain.
/*<!M><%at><%quotEuroSign>                                         */ DEADTRANS( 0x20AC	,0xE6F3	,0xE6F3	,0x0001), // Multikey chain.
/*<!M><%at><%tilde><%backslash>                                    */ DEADTRANS( L'\\'	,0xE6F4	,0xE6F4	,0x0001), // Multikey chain.
/*<!M><%at><%tilde>                                                */ DEADTRANS( L'~'	,0xE6F5	,0xE6F5	,0x0001), // Multikey chain.
/*<!M><%at><%underscore>                                           */ DEADTRANS( L'_'	,0xE6F6	,0xE6F6	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceleft><%hash><%hash>                       */ DEADTRANS( L'#'	,0xE6F8	,0xE6F8	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceleft><%hash>                              */ DEADTRANS( L'#'	,0xE6F9	,0xE6F9	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceleft>                                     */ DEADTRANS( L'{'	,0xE6FA	,0xE6FA	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceright><%hash><%hash>                      */ DEADTRANS( L'#'	,0xE6FB	,0xE6FB	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceright><%hash>                             */ DEADTRANS( L'#'	,0xE6FC	,0xE6FC	,0x0001), // Multikey chain.
/*<!M><%backslash><%braceright>                                    */ DEADTRANS( L'}'	,0xE6FD	,0xE6FD	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum>                                        */ DEADTRANS( L'^'	,0xE6FE	,0xE6FE	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><%hash><%hash><%hash>            */ DEADTRANS( L'#'	,0xE6FF	,0xE6FF	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><%hash><%hash>                   */ DEADTRANS( L'#'	,0xE700	,0xE700	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><%hash>                          */ DEADTRANS( L'#'	,0xE701	,0xE701	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><3>                              */ DEADTRANS( L'3'	,0xE702	,0xE702	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><4>                              */ DEADTRANS( L'4'	,0xE703	,0xE703	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash><5>                              */ DEADTRANS( L'5'	,0xE704	,0xE704	,0x0001), // Multikey chain.
/*<!M><%backslash><%circum><%hash>                                 */ DEADTRANS( L'#'	,0xE705	,0xE705	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><%hash><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE706	,0xE706	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE707	,0xE707	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><%hash>                                   */ DEADTRANS( L'#'	,0xE708	,0xE708	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><2>                                       */ DEADTRANS( L'2'	,0xE709	,0xE709	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><3>                                       */ DEADTRANS( L'3'	,0xE70A	,0xE70A	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><4>                                       */ DEADTRANS( L'4'	,0xE70B	,0xE70B	,0x0001), // Multikey chain.
/*<!M><%backslash><%hash><5>                                       */ DEADTRANS( L'5'	,0xE70C	,0xE70C	,0x0001), // Multikey chain.
/*<!M><%backslash><%quotedbl>                                      */ DEADTRANS( L'"'	,0xE70D	,0xE70D	,0x0001), // Multikey chain.
/*<!M><%backslash><%quotEuroSign>                                  */ DEADTRANS( 0x20AC	,0xE70E	,0xE70E	,0x0001), // Multikey chain.
/*<!M><%bar><%apostrophe><%grave>                                  */ DEADTRANS( L'`'	,0xE70F	,0xE70F	,0x0001), // Multikey chain.
/*<!M><%bar><%at>                                                  */ DEADTRANS( L'@'	,0xE710	,0xE710	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%circum>                                 */ DEADTRANS( L'^'	,0xE711	,0xE711	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%percent>                                */ DEADTRANS( L'%'	,0xE712	,0xE712	,0x0001), // Multikey chain.
/*<!M><%bar><%bracketleft>                                         */ DEADTRANS( L'['	,0xE713	,0xE713	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%braceright>                                 */ DEADTRANS( L'}'	,0xE714	,0xE714	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%percent>                                    */ DEADTRANS( L'%'	,0xE715	,0xE715	,0x0001), // Multikey chain.
/*<!M><%bar><%colon>                                               */ DEADTRANS( L':'	,0xE716	,0xE716	,0x0001), // Multikey chain.
/*<!M><%bar><%grave><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE717	,0xE717	,0x0001), // Multikey chain.
/*<!M><%bar><%hash>                                                */ DEADTRANS( L'#'	,0xE718	,0xE718	,0x0001), // Multikey chain.
/*<!M><%bar><%percent><%braceright>                                */ DEADTRANS( L'}'	,0xE719	,0xE719	,0x0001), // Multikey chain.
/*<!M><%bar><%percent><%circum>                                    */ DEADTRANS( L'^'	,0xE71A	,0xE71A	,0x0001), // Multikey chain.
/*<!M><%bar><%percent>                                             */ DEADTRANS( L'%'	,0xE71B	,0xE71B	,0x0001), // Multikey chain.
/*<!M><%bar><%period><%period>                                     */ DEADTRANS( L'.'	,0xE71C	,0xE71C	,0x0001), // Multikey chain.
/*<!M><%braceleft><%backslash><%hash><%hash>                       */ DEADTRANS( L'#'	,0xE71D	,0xE71D	,0x0001), // Multikey chain.
/*<!M><%braceleft><%backslash><%hash>                              */ DEADTRANS( L'#'	,0xE71E	,0xE71E	,0x0001), // Multikey chain.
/*<!M><%braceleft><%backslash>                                     */ DEADTRANS( L'\\'	,0xE71F	,0xE71F	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%braceleft>                         */ DEADTRANS( L'{'	,0xE720	,0xE720	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><%hash><%hash><%hash>*/ DEADTRANS( L'#'	,0xE721	,0xE721	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><%hash><%hash>       */ DEADTRANS( L'#'	,0xE722	,0xE722	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><%hash>              */ DEADTRANS( L'#'	,0xE723	,0xE723	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><3>                  */ DEADTRANS( L'3'	,0xE724	,0xE724	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><4>                  */ DEADTRANS( L'4'	,0xE725	,0xE725	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash><5>                  */ DEADTRANS( L'5'	,0xE726	,0xE726	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum><%hash>                     */ DEADTRANS( L'#'	,0xE727	,0xE727	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%circum>                            */ DEADTRANS( L'^'	,0xE728	,0xE728	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><%hash><%hash><%hash>         */ DEADTRANS( L'#'	,0xE729	,0xE729	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><%hash><%hash>                */ DEADTRANS( L'#'	,0xE72A	,0xE72A	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><%hash>                       */ DEADTRANS( L'#'	,0xE72B	,0xE72B	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><3>                           */ DEADTRANS( L'3'	,0xE72C	,0xE72C	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><4>                           */ DEADTRANS( L'4'	,0xE72D	,0xE72D	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash><5>                           */ DEADTRANS( L'5'	,0xE72E	,0xE72E	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%hash>                              */ DEADTRANS( L'#'	,0xE72F	,0xE72F	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%minus><%minus><%hash>              */ DEADTRANS( L'#'	,0xE730	,0xE730	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%minus><%minus>                     */ DEADTRANS( L'-'	,0xE731	,0xE731	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%minus>                             */ DEADTRANS( L'-'	,0xE732	,0xE732	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%percent><%percent>                 */ DEADTRANS( L'%'	,0xE733	,0xE733	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft><%percent>                           */ DEADTRANS( L'%'	,0xE734	,0xE734	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceleft>                                     */ DEADTRANS( L'{'	,0xE735	,0xE735	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceright><%braceright>                       */ DEADTRANS( L'}'	,0xE736	,0xE736	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceright>                                    */ DEADTRANS( L'}'	,0xE737	,0xE737	,0x0001), // Multikey chain.
/*<!M><%braceleft><%braceright><%percent>                          */ DEADTRANS( L'%'	,0xE738	,0xE738	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><%hash><%hash><%hash>*/ DEADTRANS( L'#'	,0xE739	,0xE739	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><%hash><%hash>       */ DEADTRANS( L'#'	,0xE73A	,0xE73A	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><%hash>              */ DEADTRANS( L'#'	,0xE73B	,0xE73B	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><3>                  */ DEADTRANS( L'3'	,0xE73C	,0xE73C	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><4>                  */ DEADTRANS( L'4'	,0xE73D	,0xE73D	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash><5>                  */ DEADTRANS( L'5'	,0xE73E	,0xE73E	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft><%hash>                     */ DEADTRANS( L'#'	,0xE73F	,0xE73F	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%braceleft>                            */ DEADTRANS( L'{'	,0xE740	,0xE740	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum>                                        */ DEADTRANS( L'^'	,0xE741	,0xE741	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%hash>                                 */ DEADTRANS( L'#'	,0xE742	,0xE742	,0x0001), // Multikey chain.
/*<!M><%braceleft><%circum><%percent>                              */ DEADTRANS( L'%'	,0xE743	,0xE743	,0x0001), // Multikey chain.
/*<!M><%braceleft><%hash><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE744	,0xE744	,0x0001), // Multikey chain.
/*<!M><%braceleft><%hash><%hash>                                   */ DEADTRANS( L'#'	,0xE745	,0xE745	,0x0001), // Multikey chain.
/*<!M><%braceleft><%hash><3>                                       */ DEADTRANS( L'3'	,0xE746	,0xE746	,0x0001), // Multikey chain.
/*<!M><%braceleft><%hash>                                          */ DEADTRANS( L'#'	,0xE747	,0xE747	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%braceleft><%minus><%hash>              */ DEADTRANS( L'#'	,0xE748	,0xE748	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%braceleft><%minus>                     */ DEADTRANS( L'-'	,0xE749	,0xE749	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%braceleft>                             */ DEADTRANS( L'{'	,0xE74A	,0xE74A	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%minus><%braceleft><%hash>              */ DEADTRANS( L'#'	,0xE74B	,0xE74B	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%minus><%braceleft>                     */ DEADTRANS( L'{'	,0xE74C	,0xE74C	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus><%minus>                                 */ DEADTRANS( L'-'	,0xE74D	,0xE74D	,0x0001), // Multikey chain.
/*<!M><%braceleft><%minus>                                         */ DEADTRANS( L'-'	,0xE74E	,0xE74E	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%braceleft><%percent>                 */ DEADTRANS( L'%'	,0xE74F	,0xE74F	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%braceleft>                           */ DEADTRANS( L'{'	,0xE750	,0xE750	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%braceright>                          */ DEADTRANS( L'}'	,0xE751	,0xE751	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%circum>                              */ DEADTRANS( L'^'	,0xE752	,0xE752	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%percent><%braceleft>                 */ DEADTRANS( L'{'	,0xE753	,0xE753	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent><%percent>                             */ DEADTRANS( L'%'	,0xE754	,0xE754	,0x0001), // Multikey chain.
/*<!M><%braceleft><%percent>                                       */ DEADTRANS( L'%'	,0xE755	,0xE755	,0x0001), // Multikey chain.
/*<!M><%braceleft><%tilde>                                         */ DEADTRANS( L'~'	,0xE757	,0xE757	,0x0001), // Multikey chain.
/*<!M><%braceleft><%underscore>                                    */ DEADTRANS( L'_'	,0xE758	,0xE758	,0x0001), // Multikey chain.
/*<!M><%braceright><%backslash><%hash><%hash>                      */ DEADTRANS( L'#'	,0xE759	,0xE759	,0x0001), // Multikey chain.
/*<!M><%braceright><%backslash><%hash>                             */ DEADTRANS( L'#'	,0xE75A	,0xE75A	,0x0001), // Multikey chain.
/*<!M><%braceright><%backslash>                                    */ DEADTRANS( L'\\'	,0xE75B	,0xE75B	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%circum>                                 */ DEADTRANS( L'^'	,0xE75C	,0xE75C	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%percent>                                */ DEADTRANS( L'%'	,0xE75D	,0xE75D	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceleft><%braceright>                       */ DEADTRANS( L'}'	,0xE75E	,0xE75E	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceleft>                                    */ DEADTRANS( L'{'	,0xE75F	,0xE75F	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceleft><%percent>                          */ DEADTRANS( L'%'	,0xE760	,0xE760	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%braceleft>                       */ DEADTRANS( L'{'	,0xE761	,0xE761	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%braceright>                      */ DEADTRANS( L'}'	,0xE762	,0xE762	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%circum>                          */ DEADTRANS( L'^'	,0xE763	,0xE763	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><%hash><%hash><%hash>       */ DEADTRANS( L'#'	,0xE764	,0xE764	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><%hash><%hash>              */ DEADTRANS( L'#'	,0xE765	,0xE765	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE766	,0xE766	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><3>                         */ DEADTRANS( L'3'	,0xE767	,0xE767	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><4>                         */ DEADTRANS( L'4'	,0xE768	,0xE768	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash><5>                         */ DEADTRANS( L'5'	,0xE769	,0xE769	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%hash>                            */ DEADTRANS( L'#'	,0xE76A	,0xE76A	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%parenright><%parenright>         */ DEADTRANS( L')'	,0xE76B	,0xE76B	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%parenright>                      */ DEADTRANS( L')'	,0xE76C	,0xE76C	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright><%percent>                         */ DEADTRANS( L'%'	,0xE76D	,0xE76D	,0x0001), // Multikey chain.
/*<!M><%braceright><%braceright>                                   */ DEADTRANS( L'}'	,0xE76E	,0xE76E	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%bar>                                 */ DEADTRANS( L'|'	,0xE76F	,0xE76F	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum>                                       */ DEADTRANS( L'^'	,0xE770	,0xE770	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%braceright>                          */ DEADTRANS( L'}'	,0xE771	,0xE771	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><%hash><%hash><%hash>           */ DEADTRANS( L'#'	,0xE772	,0xE772	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><%hash><%hash>                  */ DEADTRANS( L'#'	,0xE773	,0xE773	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><%hash>                         */ DEADTRANS( L'#'	,0xE774	,0xE774	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><3>                             */ DEADTRANS( L'3'	,0xE775	,0xE775	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><4>                             */ DEADTRANS( L'4'	,0xE776	,0xE776	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash><5>                             */ DEADTRANS( L'5'	,0xE777	,0xE777	,0x0001), // Multikey chain.
/*<!M><%braceright><%circum><%hash>                                */ DEADTRANS( L'#'	,0xE778	,0xE778	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><%hash><%hash><%hash>                    */ DEADTRANS( L'#'	,0xE77A	,0xE77A	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><%hash><%hash>                           */ DEADTRANS( L'#'	,0xE77B	,0xE77B	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><%hash>                                  */ DEADTRANS( L'#'	,0xE77C	,0xE77C	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><3>                                      */ DEADTRANS( L'3'	,0xE77D	,0xE77D	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><4>                                      */ DEADTRANS( L'4'	,0xE77E	,0xE77E	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash><5>                                      */ DEADTRANS( L'5'	,0xE77F	,0xE77F	,0x0001), // Multikey chain.
/*<!M><%braceright><%hash>                                         */ DEADTRANS( L'#'	,0xE780	,0xE780	,0x0001), // Multikey chain.
/*<!M><%braceright><%minus>                                        */ DEADTRANS( L'-'	,0xE781	,0xE781	,0x0001), // Multikey chain.
/*<!M><%braceright><%parenright><%braceright><%parenright>         */ DEADTRANS( L')'	,0xE782	,0xE782	,0x0001), // Multikey chain.
/*<!M><%braceright><%parenright><%braceright>                      */ DEADTRANS( L'}'	,0xE783	,0xE783	,0x0001), // Multikey chain.
/*<!M><%braceright><%parenright>                                   */ DEADTRANS( L')'	,0xE784	,0xE784	,0x0001), // Multikey chain.
/*<!M><%braceright><%parenright><%parenright><%braceright>         */ DEADTRANS( L'}'	,0xE785	,0xE785	,0x0001), // Multikey chain.
/*<!M><%braceright><%parenright><%parenright>                      */ DEADTRANS( L')'	,0xE786	,0xE786	,0x0001), // Multikey chain.
/*<!M><%braceright><%percent><%bar>                                */ DEADTRANS( L'|'	,0xE787	,0xE787	,0x0001), // Multikey chain.
/*<!M><%braceright><%percent><%braceleft>                          */ DEADTRANS( L'{'	,0xE788	,0xE788	,0x0001), // Multikey chain.
/*<!M><%braceright><%percent><%braceright>                         */ DEADTRANS( L'}'	,0xE789	,0xE789	,0x0001), // Multikey chain.
/*<!M><%braceright><%percent>                                      */ DEADTRANS( L'%'	,0xE78A	,0xE78A	,0x0001), // Multikey chain.
/*<!M><%bracketright><%at>                                         */ DEADTRANS( L'@'	,0xE78B	,0xE78B	,0x0001), // Multikey chain.
/*<!M><%bracketright><%less>                                       */ DEADTRANS( L'<'	,0xE78C	,0xE78C	,0x0001), // Multikey chain.
/*<!M><%bracketright><%plus>                                       */ DEADTRANS( L'+'	,0xE78D	,0xE78D	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash>                                        */ DEADTRANS( L'\\'	,0xE78E	,0xE78E	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><%hash><%hash><%hash>            */ DEADTRANS( L'#'	,0xE78F	,0xE78F	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><%hash><%hash>                   */ DEADTRANS( L'#'	,0xE790	,0xE790	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><%hash>                          */ DEADTRANS( L'#'	,0xE791	,0xE791	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><3>                              */ DEADTRANS( L'3'	,0xE792	,0xE792	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><4>                              */ DEADTRANS( L'4'	,0xE793	,0xE793	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash><5>                              */ DEADTRANS( L'5'	,0xE794	,0xE794	,0x0001), // Multikey chain.
/*<!M><%circum><%backslash><%hash>                                 */ DEADTRANS( L'#'	,0xE795	,0xE795	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%braceright>                                 */ DEADTRANS( L'}'	,0xE796	,0xE796	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%percent>                                    */ DEADTRANS( L'%'	,0xE797	,0xE797	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><%hash><%hash><%hash>*/ DEADTRANS( L'#'	,0xE798	,0xE798	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><%hash><%hash>       */ DEADTRANS( L'#'	,0xE799	,0xE799	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><%hash>              */ DEADTRANS( L'#'	,0xE79A	,0xE79A	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><3>                  */ DEADTRANS( L'3'	,0xE79B	,0xE79B	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><4>                  */ DEADTRANS( L'4'	,0xE79C	,0xE79C	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash><5>                  */ DEADTRANS( L'5'	,0xE79D	,0xE79D	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft><%hash>                     */ DEADTRANS( L'#'	,0xE79E	,0xE79E	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%braceleft>                            */ DEADTRANS( L'{'	,0xE79F	,0xE79F	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft>                                        */ DEADTRANS( L'{'	,0xE7A0	,0xE7A0	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%hash>                                 */ DEADTRANS( L'#'	,0xE7A1	,0xE7A1	,0x0001), // Multikey chain.
/*<!M><%circum><%braceleft><%percent>                              */ DEADTRANS( L'%'	,0xE7A2	,0xE7A2	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%bar>                                 */ DEADTRANS( L'|'	,0xE7A3	,0xE7A3	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright>                                       */ DEADTRANS( L'}'	,0xE7A4	,0xE7A4	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%braceright>                          */ DEADTRANS( L'}'	,0xE7A5	,0xE7A5	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><%hash><%hash><%hash>           */ DEADTRANS( L'#'	,0xE7A6	,0xE7A6	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><%hash><%hash>                  */ DEADTRANS( L'#'	,0xE7A7	,0xE7A7	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><%hash>                         */ DEADTRANS( L'#'	,0xE7A8	,0xE7A8	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><3>                             */ DEADTRANS( L'3'	,0xE7A9	,0xE7A9	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><4>                             */ DEADTRANS( L'4'	,0xE7AA	,0xE7AA	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash><5>                             */ DEADTRANS( L'5'	,0xE7AB	,0xE7AB	,0x0001), // Multikey chain.
/*<!M><%circum><%braceright><%hash>                                */ DEADTRANS( L'#'	,0xE7AC	,0xE7AC	,0x0001), // Multikey chain.
/*<!M><%circum><%circum>                                           */ DEADTRANS( L'^'	,0xE7AD	,0xE7AD	,0x0001), // Multikey chain.
/*<!M><%circum><%circum><%colon>                                   */ DEADTRANS( L':'	,0xE7AE	,0xE7AE	,0x0001), // Multikey chain.
/*<!M><%circum><%circum><%hash><%hash>                             */ DEADTRANS( L'#'	,0xE7AF	,0xE7AF	,0x0001), // Multikey chain.
/*<!M><%circum><%circum><%hash><2>                                 */ DEADTRANS( L'2'	,0xE7B0	,0xE7B0	,0x0001), // Multikey chain.
/*<!M><%circum><%circum><%hash>                                    */ DEADTRANS( L'#'	,0xE7B1	,0xE7B1	,0x0001), // Multikey chain.
/*<!M><%circum><%colon><%circum>                                   */ DEADTRANS( L'^'	,0xE7B2	,0xE7B2	,0x0001), // Multikey chain.
/*<!M><%circum><%colon>                                            */ DEADTRANS( L':'	,0xE7B3	,0xE7B3	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><%hash><%hash><%hash>                        */ DEADTRANS( L'#'	,0xE7B4	,0xE7B4	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><%hash><%hash>                               */ DEADTRANS( L'#'	,0xE7B5	,0xE7B5	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><%hash>                                      */ DEADTRANS( L'#'	,0xE7B6	,0xE7B6	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><3>                                          */ DEADTRANS( L'3'	,0xE7B7	,0xE7B7	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><4>                                          */ DEADTRANS( L'4'	,0xE7B8	,0xE7B8	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><5>                                          */ DEADTRANS( L'5'	,0xE7B9	,0xE7B9	,0x0001), // Multikey chain.
/*<!M><%circum><%hash><6>                                          */ DEADTRANS( L'6'	,0xE7BA	,0xE7BA	,0x0001), // Multikey chain.
/*<!M><%circum><%minus>                                            */ DEADTRANS( L'-'	,0xE7BB	,0xE7BB	,0x0001), // Multikey chain.
/*<!M><%circum><%minus><%hash>                                     */ DEADTRANS( L'#'	,0xE7BC	,0xE7BC	,0x0001), // Multikey chain.
/*<!M><%circum><%parenright>                                       */ DEADTRANS( L')'	,0xE7BD	,0xE7BD	,0x0001), // Multikey chain.
/*<!M><%circum><%parenright><%parenright>                          */ DEADTRANS( L')'	,0xE7BE	,0xE7BE	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%bar>                                    */ DEADTRANS( L'|'	,0xE7BF	,0xE7BF	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%braceleft>                              */ DEADTRANS( L'{'	,0xE7C0	,0xE7C0	,0x0001), // Multikey chain.
/*<!M><%circum><%percent>                                          */ DEADTRANS( L'%'	,0xE7C1	,0xE7C1	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%hash><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE7C2	,0xE7C2	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE7C3	,0xE7C3	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%hash><3>                                */ DEADTRANS( L'3'	,0xE7C4	,0xE7C4	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%hash>                                   */ DEADTRANS( L'#'	,0xE7C5	,0xE7C5	,0x0001), // Multikey chain.
/*<!M><%circum><%percent><%percent>                                */ DEADTRANS( L'%'	,0xE7C6	,0xE7C6	,0x0001), // Multikey chain.
/*<!M><%circum><%underscore>                                       */ DEADTRANS( L'_'	,0xE7C7	,0xE7C7	,0x0001), // Multikey chain.
/*<!M><%circum><%underscore><%hash>                                */ DEADTRANS( L'#'	,0xE7C8	,0xE7C8	,0x0001), // Multikey chain.
/*<!M><%colon><%apostrophe><%at>                                   */ DEADTRANS( L'@'	,0xE7C9	,0xE7C9	,0x0001), // Multikey chain.
/*<!M><%colon><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE7CA	,0xE7CA	,0x0001), // Multikey chain.
/*<!M><%colon><%asterisk>                                          */ DEADTRANS( L'*'	,0xE7CB	,0xE7CB	,0x0001), // Multikey chain.
/*<!M><%colon><%at><%apostrophe>                                   */ DEADTRANS( L'\''	,0xE7CC	,0xE7CC	,0x0001), // Multikey chain.
/*<!M><%colon><%at><%grave>                                        */ DEADTRANS( L'`'	,0xE7CD	,0xE7CD	,0x0001), // Multikey chain.
/*<!M><%colon><%at><%less>                                         */ DEADTRANS( L'<'	,0xE7CE	,0xE7CE	,0x0001), // Multikey chain.
/*<!M><%colon><%at><%quotedbl>                                     */ DEADTRANS( L'"'	,0xE7CF	,0xE7CF	,0x0001), // Multikey chain.
/*<!M><%colon><%at><%quotEuroSign>                                 */ DEADTRANS( 0x20AC	,0xE7D0	,0xE7D0	,0x0001), // Multikey chain.
/*<!M><%colon><%at>                                                */ DEADTRANS( L'@'	,0xE7D1	,0xE7D1	,0x0001), // Multikey chain.
/*<!M><%colon><%bar>                                               */ DEADTRANS( L'|'	,0xE7D2	,0xE7D2	,0x0001), // Multikey chain.
/*<!M><%colon><%circum><%circum>                                   */ DEADTRANS( L'^'	,0xE7D3	,0xE7D3	,0x0001), // Multikey chain.
/*<!M><%colon><%circum>                                            */ DEADTRANS( L'^'	,0xE7D4	,0xE7D4	,0x0001), // Multikey chain.
/*<!M><%colon><%colon>                                             */ DEADTRANS( L':'	,0xE7D5	,0xE7D5	,0x0001), // Multikey chain.
/*<!M><%colon><%colon><%colon>                                     */ DEADTRANS( L':'	,0xE7D6	,0xE7D6	,0x0001), // Multikey chain.
/*<!M><%colon><%grave><%at>                                        */ DEADTRANS( L'@'	,0xE7D7	,0xE7D7	,0x0001), // Multikey chain.
/*<!M><%colon><%grave>                                             */ DEADTRANS( L'`'	,0xE7D8	,0xE7D8	,0x0001), // Multikey chain.
/*<!M><%colon><%greater>                                           */ DEADTRANS( L'>'	,0xE7D9	,0xE7D9	,0x0001), // Multikey chain.
/*<!M><%colon><%hash>                                              */ DEADTRANS( L'#'	,0xE7DA	,0xE7DA	,0x0001), // Multikey chain.
/*<!M><%colon><%hash><%hash>                                       */ DEADTRANS( L'#'	,0xE7DB	,0xE7DB	,0x0001), // Multikey chain.
/*<!M><%colon><%less>                                              */ DEADTRANS( L'<'	,0xE7DC	,0xE7DC	,0x0001), // Multikey chain.
/*<!M><%colon><%less><%at>                                         */ DEADTRANS( L'@'	,0xE7DD	,0xE7DD	,0x0001), // Multikey chain.
/*<!M><%colon><%percent><%percent>                                 */ DEADTRANS( L'%'	,0xE7DE	,0xE7DE	,0x0001), // Multikey chain.
/*<!M><%colon><%percent>                                           */ DEADTRANS( L'%'	,0xE7DF	,0xE7DF	,0x0001), // Multikey chain.
/*<!M><%colon><%tilde>                                             */ DEADTRANS( L'~'	,0xE7E0	,0xE7E0	,0x0001), // Multikey chain.
/*<!M><%comma><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE7E1	,0xE7E1	,0x0001), // Multikey chain.
/*<!M><%comma><%comma>                                             */ DEADTRANS( L','	,0xE7E2	,0xE7E2	,0x0001), // Multikey chain.
/*<!M><%comma><%parenright>                                        */ DEADTRANS( L')'	,0xE7E3	,0xE7E3	,0x0001), // Multikey chain.
/*<!M><%dollar><%asterisk>                                         */ DEADTRANS( L'*'	,0xE7E4	,0xE7E4	,0x0001), // Multikey chain.
/*<!M><%dollar><%comma>                                            */ DEADTRANS( L','	,0xE7E5	,0xE7E5	,0x0001), // Multikey chain.
/*<!M><%dollar><%dollar>                                           */ DEADTRANS( L'$'	,0xE7E6	,0xE7E6	,0x0001), // Multikey chain.
/*<!M><%equal><%hash>                                              */ DEADTRANS( L'#'	,0xE7E8	,0xE7E8	,0x0001), // Multikey chain.
/*<!M><%equal><%hash><%hash>                                       */ DEADTRANS( L'#'	,0xE7E9	,0xE7E9	,0x0001), // Multikey chain.
/*<!M><%equal><%hash><%hash><%hash>                                */ DEADTRANS( L'#'	,0xE7EA	,0xE7EA	,0x0001), // Multikey chain.
/*<!M><%equal><%hash><3>                                           */ DEADTRANS( L'3'	,0xE7EB	,0xE7EB	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%at><%parenleft>                      */ DEADTRANS( L'('	,0xE7EC	,0xE7EC	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%at><%parenright>                     */ DEADTRANS( L')'	,0xE7ED	,0xE7ED	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%at>                                  */ DEADTRANS( L'@'	,0xE7EE	,0xE7EE	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE7EF	,0xE7EF	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE7F0	,0xE7F0	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%apostrophe><%parenleft>                      */ DEADTRANS( L'('	,0xE7F1	,0xE7F1	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%apostrophe><%parenright>                     */ DEADTRANS( L')'	,0xE7F2	,0xE7F2	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE7F3	,0xE7F3	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%grave><%parenleft>                           */ DEADTRANS( L'('	,0xE7F4	,0xE7F4	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%grave><%parenright>                          */ DEADTRANS( L')'	,0xE7F5	,0xE7F5	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%grave>                                       */ DEADTRANS( L'`'	,0xE7F6	,0xE7F6	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%less><%parenleft>                            */ DEADTRANS( L'('	,0xE7F7	,0xE7F7	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%less><%parenright>                           */ DEADTRANS( L')'	,0xE7F8	,0xE7F8	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%less>                                        */ DEADTRANS( L'<'	,0xE7F9	,0xE7F9	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenleft><%apostrophe>                      */ DEADTRANS( L'\''	,0xE7FA	,0xE7FA	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenleft><%grave>                           */ DEADTRANS( L'`'	,0xE7FB	,0xE7FB	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenleft><%less>                            */ DEADTRANS( L'<'	,0xE7FC	,0xE7FC	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenleft>                                   */ DEADTRANS( L'('	,0xE7FD	,0xE7FD	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenright><%apostrophe>                     */ DEADTRANS( L'\''	,0xE7FE	,0xE7FE	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenright><%grave>                          */ DEADTRANS( L'`'	,0xE7FF	,0xE7FF	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenright><%less>                           */ DEADTRANS( L'<'	,0xE800	,0xE800	,0x0001), // Multikey chain.
/*<!M><%exclam><%at><%parenright>                                  */ DEADTRANS( L')'	,0xE801	,0xE801	,0x0001), // Multikey chain.
/*<!M><%exclam><%at>                                               */ DEADTRANS( L'@'	,0xE802	,0xE802	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%at><%parenleft>                           */ DEADTRANS( L'('	,0xE803	,0xE803	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%at><%parenright>                          */ DEADTRANS( L')'	,0xE804	,0xE804	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%at>                                       */ DEADTRANS( L'@'	,0xE805	,0xE805	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE806	,0xE806	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE807	,0xE807	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%at><%parenleft>                            */ DEADTRANS( L'('	,0xE808	,0xE808	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%at><%parenright>                           */ DEADTRANS( L')'	,0xE809	,0xE809	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%at>                                        */ DEADTRANS( L'@'	,0xE80A	,0xE80A	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE80B	,0xE80B	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE80C	,0xE80C	,0x0001), // Multikey chain.
/*<!M><%exclam><%less>                                             */ DEADTRANS( L'<'	,0xE80D	,0xE80D	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE80E	,0xE80E	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at><%apostrophe>                      */ DEADTRANS( L'\''	,0xE80F	,0xE80F	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at><%grave>                           */ DEADTRANS( L'`'	,0xE810	,0xE810	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at><%less>                            */ DEADTRANS( L'<'	,0xE811	,0xE811	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at>                                   */ DEADTRANS( L'@'	,0xE812	,0xE812	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%grave><%at>                           */ DEADTRANS( L'@'	,0xE813	,0xE813	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%less><%at>                            */ DEADTRANS( L'@'	,0xE814	,0xE814	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE815	,0xE815	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%at><%apostrophe>                     */ DEADTRANS( L'\''	,0xE816	,0xE816	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%at><%grave>                          */ DEADTRANS( L'`'	,0xE817	,0xE817	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%at><%less>                           */ DEADTRANS( L'<'	,0xE818	,0xE818	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%at>                                  */ DEADTRANS( L'@'	,0xE819	,0xE819	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%grave><%at>                          */ DEADTRANS( L'@'	,0xE81A	,0xE81A	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%less><%at>                           */ DEADTRANS( L'@'	,0xE81B	,0xE81B	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright>                                       */ DEADTRANS( L')'	,0xE81C	,0xE81C	,0x0001), // Multikey chain.
/*<!M><%exclam><%period>                                           */ DEADTRANS( L'.'	,0xE81D	,0xE81D	,0x0001), // Multikey chain.
/*<!M><%exclam><%plus>                                             */ DEADTRANS( L'+'	,0xE81E	,0xE81E	,0x0001), // Multikey chain.
/*<!M><%grave><%apostrophe><%bar>                                  */ DEADTRANS( L'|'	,0xE820	,0xE820	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%colon>                                        */ DEADTRANS( L':'	,0xE821	,0xE821	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%exclam><%parenleft>                           */ DEADTRANS( L'('	,0xE822	,0xE822	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%exclam><%parenright>                          */ DEADTRANS( L')'	,0xE823	,0xE823	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%exclam>                                       */ DEADTRANS( L'!'	,0xE824	,0xE824	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%parenleft><%exclam>                           */ DEADTRANS( L'!'	,0xE825	,0xE825	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%parenleft>                                    */ DEADTRANS( L'('	,0xE826	,0xE826	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%parenright><%exclam>                          */ DEADTRANS( L'!'	,0xE827	,0xE827	,0x0001), // Multikey chain.
/*<!M><%grave><%at><%parenright>                                   */ DEADTRANS( L')'	,0xE828	,0xE828	,0x0001), // Multikey chain.
/*<!M><%grave><%at>                                                */ DEADTRANS( L'@'	,0xE829	,0xE829	,0x0001), // Multikey chain.
/*<!M><%grave><%bar><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE82A	,0xE82A	,0x0001), // Multikey chain.
/*<!M><%grave><%bar>                                               */ DEADTRANS( L'|'	,0xE82B	,0xE82B	,0x0001), // Multikey chain.
/*<!M><%grave><%colon><%at>                                        */ DEADTRANS( L'@'	,0xE82C	,0xE82C	,0x0001), // Multikey chain.
/*<!M><%grave><%colon>                                             */ DEADTRANS( L':'	,0xE82D	,0xE82D	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%at><%parenleft>                           */ DEADTRANS( L'('	,0xE82E	,0xE82E	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%at><%parenright>                          */ DEADTRANS( L')'	,0xE82F	,0xE82F	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%at>                                       */ DEADTRANS( L'@'	,0xE830	,0xE830	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE831	,0xE831	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE832	,0xE832	,0x0001), // Multikey chain.
/*<!M><%grave><%grave>                                             */ DEADTRANS( L'`'	,0xE833	,0xE833	,0x0001), // Multikey chain.
/*<!M><%grave><%less>                                              */ DEADTRANS( L'<'	,0xE834	,0xE834	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%at><%exclam>                           */ DEADTRANS( L'!'	,0xE835	,0xE835	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%at>                                    */ DEADTRANS( L'@'	,0xE836	,0xE836	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE837	,0xE837	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright><%at><%exclam>                          */ DEADTRANS( L'!'	,0xE838	,0xE838	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright><%at>                                   */ DEADTRANS( L'@'	,0xE839	,0xE839	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE83A	,0xE83A	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright>                                        */ DEADTRANS( L')'	,0xE83B	,0xE83B	,0x0001), // Multikey chain.
/*<!M><%grave><%period><%period>                                   */ DEADTRANS( L'.'	,0xE83C	,0xE83C	,0x0001), // Multikey chain.
/*<!M><%grave><%period>                                            */ DEADTRANS( L'.'	,0xE83D	,0xE83D	,0x0001), // Multikey chain.
/*<!M><%grave><%plus>                                              */ DEADTRANS( L'+'	,0xE83E	,0xE83E	,0x0001), // Multikey chain.
/*<!M><%greater><%at>                                              */ DEADTRANS( L'@'	,0xE83F	,0xE83F	,0x0001), // Multikey chain.
/*<!M><%greater><%colon>                                           */ DEADTRANS( L':'	,0xE840	,0xE840	,0x0001), // Multikey chain.
/*<!M><%greater><%hash>                                            */ DEADTRANS( L'#'	,0xE841	,0xE841	,0x0001), // Multikey chain.
/*<!M><%hash><%hash>                                               */ DEADTRANS( L'#'	,0xE843	,0xE843	,0x0001), // Multikey chain.
/*<!M><%hash><%hash><%hash>                                        */ DEADTRANS( L'#'	,0xE844	,0xE844	,0x0001), // Multikey chain.
/*<!M><%hash><%hash><%hash><%hash>                                 */ DEADTRANS( L'#'	,0xE845	,0xE845	,0x0001), // Multikey chain.
/*<!M><%hash><0>                                                   */ DEADTRANS( L'0'	,0xE846	,0xE846	,0x0001), // Multikey chain.
/*<!M><%hash><0><%comma><%period>                                  */ DEADTRANS( L'.'	,0xE847	,0xE847	,0x0001), // Multikey chain.
/*<!M><%hash><0><%comma>                                           */ DEADTRANS( L','	,0xE848	,0xE848	,0x0001), // Multikey chain.
/*<!M><%hash><0><%period><%comma>                                  */ DEADTRANS( L','	,0xE849	,0xE849	,0x0001), // Multikey chain.
/*<!M><%hash><0><%period>                                          */ DEADTRANS( L'.'	,0xE84A	,0xE84A	,0x0001), // Multikey chain.
/*<!M><%hash><1>                                                   */ DEADTRANS( L'1'	,0xE84B	,0xE84B	,0x0001), // Multikey chain.
/*<!M><%hash><2>                                                   */ DEADTRANS( L'2'	,0xE84C	,0xE84C	,0x0001), // Multikey chain.
/*<!M><%hash><3>                                                   */ DEADTRANS( L'3'	,0xE84D	,0xE84D	,0x0001), // Multikey chain.
/*<!M><%hash><4>                                                   */ DEADTRANS( L'4'	,0xE84E	,0xE84E	,0x0001), // Multikey chain.
/*<!M><%hash><5>                                                   */ DEADTRANS( L'5'	,0xE84F	,0xE84F	,0x0001), // Multikey chain.
/*<!M><%hash><6>                                                   */ DEADTRANS( L'6'	,0xE850	,0xE850	,0x0001), // Multikey chain.
/*<!M><%hash><6><%comma><%comma><%period>                          */ DEADTRANS( L'.'	,0xE851	,0xE851	,0x0001), // Multikey chain.
/*<!M><%hash><6><%comma><%comma>                                   */ DEADTRANS( L','	,0xE852	,0xE852	,0x0001), // Multikey chain.
/*<!M><%hash><6><%comma><%period><%comma>                          */ DEADTRANS( L','	,0xE853	,0xE853	,0x0001), // Multikey chain.
/*<!M><%hash><6><%comma><%period>                                  */ DEADTRANS( L'.'	,0xE854	,0xE854	,0x0001), // Multikey chain.
/*<!M><%hash><6><%comma>                                           */ DEADTRANS( L','	,0xE855	,0xE855	,0x0001), // Multikey chain.
/*<!M><%hash><6><%period><%comma><%comma>                          */ DEADTRANS( L','	,0xE856	,0xE856	,0x0001), // Multikey chain.
/*<!M><%hash><6><%period><%comma>                                  */ DEADTRANS( L','	,0xE857	,0xE857	,0x0001), // Multikey chain.
/*<!M><%hash><6><%period>                                          */ DEADTRANS( L'.'	,0xE858	,0xE858	,0x0001), // Multikey chain.
/*<!M><%hash><7>                                                   */ DEADTRANS( L'7'	,0xE859	,0xE859	,0x0001), // Multikey chain.
/*<!M><%hash><7><%comma>                                           */ DEADTRANS( L','	,0xE85A	,0xE85A	,0x0001), // Multikey chain.
/*<!M><%hash><7><%period>                                          */ DEADTRANS( L'.'	,0xE85B	,0xE85B	,0x0001), // Multikey chain.
/*<!M><%hash><8>                                                   */ DEADTRANS( L'8'	,0xE85C	,0xE85C	,0x0001), // Multikey chain.
/*<!M><%hash><8><%comma><%period>                                  */ DEADTRANS( L'.'	,0xE85D	,0xE85D	,0x0001), // Multikey chain.
/*<!M><%hash><8><%comma>                                           */ DEADTRANS( L','	,0xE85E	,0xE85E	,0x0001), // Multikey chain.
/*<!M><%hash><8><%period><%comma>                                  */ DEADTRANS( L','	,0xE85F	,0xE85F	,0x0001), // Multikey chain.
/*<!M><%hash><8><%period>                                          */ DEADTRANS( L'.'	,0xE860	,0xE860	,0x0001), // Multikey chain.
/*<!M><%hash><9>                                                   */ DEADTRANS( L'9'	,0xE861	,0xE861	,0x0001), // Multikey chain.
/*<!M><%hash><9><%comma>                                           */ DEADTRANS( L','	,0xE862	,0xE862	,0x0001), // Multikey chain.
/*<!M><%hash><9><%period>                                          */ DEADTRANS( L'.'	,0xE863	,0xE863	,0x0001), // Multikey chain.
/*<!M><%hash><ellipsis>                                            */ DEADTRANS( 0x2026	,0xE864	,0xE864	,0x0001), // Multikey chain.
/*<!M><%less><%apostrophe>                                         */ DEADTRANS( L'\''	,0xE865	,0xE865	,0x0001), // Multikey chain.
/*<!M><%less><%at><%colon>                                         */ DEADTRANS( L':'	,0xE866	,0xE866	,0x0001), // Multikey chain.
/*<!M><%less><%at><%exclam><%parenleft>                            */ DEADTRANS( L'('	,0xE867	,0xE867	,0x0001), // Multikey chain.
/*<!M><%less><%at><%exclam><%parenright>                           */ DEADTRANS( L')'	,0xE868	,0xE868	,0x0001), // Multikey chain.
/*<!M><%less><%at><%exclam>                                        */ DEADTRANS( L'!'	,0xE869	,0xE869	,0x0001), // Multikey chain.
/*<!M><%less><%at><%parenleft><%exclam>                            */ DEADTRANS( L'!'	,0xE86A	,0xE86A	,0x0001), // Multikey chain.
/*<!M><%less><%at><%parenleft>                                     */ DEADTRANS( L'('	,0xE86B	,0xE86B	,0x0001), // Multikey chain.
/*<!M><%less><%at><%parenright><%exclam>                           */ DEADTRANS( L'!'	,0xE86C	,0xE86C	,0x0001), // Multikey chain.
/*<!M><%less><%at><%parenright>                                    */ DEADTRANS( L')'	,0xE86D	,0xE86D	,0x0001), // Multikey chain.
/*<!M><%less><%at>                                                 */ DEADTRANS( L'@'	,0xE86E	,0xE86E	,0x0001), // Multikey chain.
/*<!M><%less><%colon>                                              */ DEADTRANS( L':'	,0xE86F	,0xE86F	,0x0001), // Multikey chain.
/*<!M><%less><%colon><%at>                                         */ DEADTRANS( L'@'	,0xE870	,0xE870	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%at><%parenleft>                            */ DEADTRANS( L'('	,0xE871	,0xE871	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%at><%parenright>                           */ DEADTRANS( L')'	,0xE872	,0xE872	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%at>                                        */ DEADTRANS( L'@'	,0xE873	,0xE873	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE874	,0xE874	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE875	,0xE875	,0x0001), // Multikey chain.
/*<!M><%less><%grave>                                              */ DEADTRANS( L'`'	,0xE876	,0xE876	,0x0001), // Multikey chain.
/*<!M><%less><%hash>                                               */ DEADTRANS( L'#'	,0xE877	,0xE877	,0x0001), // Multikey chain.
/*<!M><%less><%hash><%hash>                                        */ DEADTRANS( L'#'	,0xE878	,0xE878	,0x0001), // Multikey chain.
/*<!M><%less><%hash><%hash><%hash>                                 */ DEADTRANS( L'#'	,0xE879	,0xE879	,0x0001), // Multikey chain.
/*<!M><%less><%hash><%hash><%hash><%hash>                          */ DEADTRANS( L'#'	,0xE87A	,0xE87A	,0x0001), // Multikey chain.
/*<!M><%less><%hash><3>                                            */ DEADTRANS( L'3'	,0xE87B	,0xE87B	,0x0001), // Multikey chain.
/*<!M><%less><%hash><4>                                            */ DEADTRANS( L'4'	,0xE87C	,0xE87C	,0x0001), // Multikey chain.
/*<!M><%less><%hash><5>                                            */ DEADTRANS( L'5'	,0xE87D	,0xE87D	,0x0001), // Multikey chain.
/*<!M><%less><%less><%less>                                        */ DEADTRANS( L'<'	,0xE87E	,0xE87E	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%at><%exclam>                            */ DEADTRANS( L'!'	,0xE87F	,0xE87F	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%at>                                     */ DEADTRANS( L'@'	,0xE880	,0xE880	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE881	,0xE881	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%at><%exclam>                           */ DEADTRANS( L'!'	,0xE882	,0xE882	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%at>                                    */ DEADTRANS( L'@'	,0xE883	,0xE883	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE884	,0xE884	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%braceleft><%minus><%hash>              */ DEADTRANS( L'#'	,0xE885	,0xE885	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%braceleft><%minus>                     */ DEADTRANS( L'-'	,0xE886	,0xE886	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%braceleft>                             */ DEADTRANS( L'{'	,0xE887	,0xE887	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%minus><%braceleft><%hash>              */ DEADTRANS( L'#'	,0xE888	,0xE888	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%minus><%braceleft>                     */ DEADTRANS( L'{'	,0xE889	,0xE889	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft><%minus>                                 */ DEADTRANS( L'-'	,0xE88A	,0xE88A	,0x0001), // Multikey chain.
/*<!M><%minus><%braceleft>                                         */ DEADTRANS( L'{'	,0xE88B	,0xE88B	,0x0001), // Multikey chain.
/*<!M><%minus><%braceright>                                        */ DEADTRANS( L'}'	,0xE88C	,0xE88C	,0x0001), // Multikey chain.
/*<!M><%minus><%circum><%hash>                                     */ DEADTRANS( L'#'	,0xE88D	,0xE88D	,0x0001), // Multikey chain.
/*<!M><%minus><%hash>                                              */ DEADTRANS( L'#'	,0xE88E	,0xE88E	,0x0001), // Multikey chain.
/*<!M><%minus><%hash><%hash>                                       */ DEADTRANS( L'#'	,0xE88F	,0xE88F	,0x0001), // Multikey chain.
/*<!M><%minus><%hash><%hash><%hash>                                */ DEADTRANS( L'#'	,0xE890	,0xE890	,0x0001), // Multikey chain.
/*<!M><%minus><%hash><3>                                           */ DEADTRANS( L'3'	,0xE891	,0xE891	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%braceleft><%braceleft><%hash>              */ DEADTRANS( L'#'	,0xE892	,0xE892	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%braceleft><%braceleft>                     */ DEADTRANS( L'{'	,0xE893	,0xE893	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%braceleft>                                 */ DEADTRANS( L'{'	,0xE894	,0xE894	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%hash>                                      */ DEADTRANS( L'#'	,0xE895	,0xE895	,0x0001), // Multikey chain.
/*<!M><%minus><%percent><%hash>                                    */ DEADTRANS( L'#'	,0xE896	,0xE896	,0x0001), // Multikey chain.
/*<!M><%minus><%percent>                                           */ DEADTRANS( L'%'	,0xE897	,0xE897	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%at><%exclam>                      */ DEADTRANS( L'!'	,0xE898	,0xE898	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%at>                               */ DEADTRANS( L'@'	,0xE899	,0xE899	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE89A	,0xE89A	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%apostrophe><%exclam>                      */ DEADTRANS( L'!'	,0xE89B	,0xE89B	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%apostrophe>                               */ DEADTRANS( L'\''	,0xE89C	,0xE89C	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%exclam><%apostrophe>                      */ DEADTRANS( L'\''	,0xE89D	,0xE89D	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%exclam><%grave>                           */ DEADTRANS( L'`'	,0xE89E	,0xE89E	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%exclam><%less>                            */ DEADTRANS( L'<'	,0xE89F	,0xE89F	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%exclam>                                   */ DEADTRANS( L'!'	,0xE8A0	,0xE8A0	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%grave><%exclam>                           */ DEADTRANS( L'!'	,0xE8A1	,0xE8A1	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%grave>                                    */ DEADTRANS( L'`'	,0xE8A2	,0xE8A2	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%less><%exclam>                            */ DEADTRANS( L'!'	,0xE8A3	,0xE8A3	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at><%less>                                     */ DEADTRANS( L'<'	,0xE8A4	,0xE8A4	,0x0001), // Multikey chain.
/*<!M><%parenleft><%at>                                            */ DEADTRANS( L'@'	,0xE8A5	,0xE8A5	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE8A6	,0xE8A6	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at><%apostrophe>                      */ DEADTRANS( L'\''	,0xE8A7	,0xE8A7	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at><%grave>                           */ DEADTRANS( L'`'	,0xE8A8	,0xE8A8	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at><%less>                            */ DEADTRANS( L'<'	,0xE8A9	,0xE8A9	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at>                                   */ DEADTRANS( L'@'	,0xE8AA	,0xE8AA	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%grave><%at>                           */ DEADTRANS( L'@'	,0xE8AB	,0xE8AB	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%less><%at>                            */ DEADTRANS( L'@'	,0xE8AC	,0xE8AC	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%at><%exclam>                           */ DEADTRANS( L'!'	,0xE8AD	,0xE8AD	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%at>                                    */ DEADTRANS( L'@'	,0xE8AE	,0xE8AE	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8AF	,0xE8AF	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><%hash><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE8B0	,0xE8B0	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE8B1	,0xE8B1	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><%hash>                                   */ DEADTRANS( L'#'	,0xE8B2	,0xE8B2	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><1>                                       */ DEADTRANS( L'1'	,0xE8B3	,0xE8B3	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><3>                                       */ DEADTRANS( L'3'	,0xE8B4	,0xE8B4	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><4>                                       */ DEADTRANS( L'4'	,0xE8B5	,0xE8B5	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash><5>                                       */ DEADTRANS( L'5'	,0xE8B6	,0xE8B6	,0x0001), // Multikey chain.
/*<!M><%parenleft><%hash>                                          */ DEADTRANS( L'#'	,0xE8B7	,0xE8B7	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less><%at><%exclam>                            */ DEADTRANS( L'!'	,0xE8B8	,0xE8B8	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less><%at>                                     */ DEADTRANS( L'@'	,0xE8B9	,0xE8B9	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE8BA	,0xE8BA	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe><%at><%exclam>                     */ DEADTRANS( L'!'	,0xE8BB	,0xE8BB	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe><%at>                              */ DEADTRANS( L'@'	,0xE8BC	,0xE8BC	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE8BD	,0xE8BD	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe>                                   */ DEADTRANS( L'\''	,0xE8BE	,0xE8BE	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%apostrophe><%exclam>                     */ DEADTRANS( L'!'	,0xE8BF	,0xE8BF	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%apostrophe>                              */ DEADTRANS( L'\''	,0xE8C0	,0xE8C0	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%exclam><%apostrophe>                     */ DEADTRANS( L'\''	,0xE8C1	,0xE8C1	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%exclam><%grave>                          */ DEADTRANS( L'`'	,0xE8C2	,0xE8C2	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%exclam><%less>                           */ DEADTRANS( L'<'	,0xE8C3	,0xE8C3	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%exclam>                                  */ DEADTRANS( L'!'	,0xE8C4	,0xE8C4	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%grave><%exclam>                          */ DEADTRANS( L'!'	,0xE8C5	,0xE8C5	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%grave>                                   */ DEADTRANS( L'`'	,0xE8C6	,0xE8C6	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%less><%exclam>                           */ DEADTRANS( L'!'	,0xE8C7	,0xE8C7	,0x0001), // Multikey chain.
/*<!M><%parenright><%at><%less>                                    */ DEADTRANS( L'<'	,0xE8C8	,0xE8C8	,0x0001), // Multikey chain.
/*<!M><%parenright><%at>                                           */ DEADTRANS( L'@'	,0xE8C9	,0xE8C9	,0x0001), // Multikey chain.
/*<!M><%parenright><%bar>                                          */ DEADTRANS( L'|'	,0xE8CA	,0xE8CA	,0x0001), // Multikey chain.
/*<!M><%parenright><%braceright><%braceright><%parenright>         */ DEADTRANS( L')'	,0xE8CB	,0xE8CB	,0x0001), // Multikey chain.
/*<!M><%parenright><%braceright><%braceright>                      */ DEADTRANS( L'}'	,0xE8CC	,0xE8CC	,0x0001), // Multikey chain.
/*<!M><%parenright><%braceright>                                   */ DEADTRANS( L'}'	,0xE8CD	,0xE8CD	,0x0001), // Multikey chain.
/*<!M><%parenright><%braceright><%parenright><%braceright>         */ DEADTRANS( L'}'	,0xE8CE	,0xE8CE	,0x0001), // Multikey chain.
/*<!M><%parenright><%braceright><%parenright>                      */ DEADTRANS( L')'	,0xE8CF	,0xE8CF	,0x0001), // Multikey chain.
/*<!M><%parenright><%circum><%parenright>                          */ DEADTRANS( L')'	,0xE8D0	,0xE8D0	,0x0001), // Multikey chain.
/*<!M><%parenright><%comma>                                        */ DEADTRANS( L','	,0xE8D1	,0xE8D1	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE8D2	,0xE8D2	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%at><%apostrophe>                     */ DEADTRANS( L'\''	,0xE8D3	,0xE8D3	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%at><%grave>                          */ DEADTRANS( L'`'	,0xE8D4	,0xE8D4	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%at><%less>                           */ DEADTRANS( L'<'	,0xE8D5	,0xE8D5	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%at>                                  */ DEADTRANS( L'@'	,0xE8D6	,0xE8D6	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%grave><%at>                          */ DEADTRANS( L'@'	,0xE8D7	,0xE8D7	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%less><%at>                           */ DEADTRANS( L'@'	,0xE8D8	,0xE8D8	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam>                                       */ DEADTRANS( L'!'	,0xE8D9	,0xE8D9	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave><%at><%exclam>                          */ DEADTRANS( L'!'	,0xE8DA	,0xE8DA	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave><%at>                                   */ DEADTRANS( L'@'	,0xE8DB	,0xE8DB	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE8DC	,0xE8DC	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave>                                        */ DEADTRANS( L'`'	,0xE8DD	,0xE8DD	,0x0001), // Multikey chain.
/*<!M><%parenright><%less><%at><%exclam>                           */ DEADTRANS( L'!'	,0xE8DE	,0xE8DE	,0x0001), // Multikey chain.
/*<!M><%parenright><%less><%at>                                    */ DEADTRANS( L'@'	,0xE8DF	,0xE8DF	,0x0001), // Multikey chain.
/*<!M><%parenright><%less><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8E0	,0xE8E0	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright><%braceright><%braceright>         */ DEADTRANS( L'}'	,0xE8E1	,0xE8E1	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright><%braceright>                      */ DEADTRANS( L'}'	,0xE8E2	,0xE8E2	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright><%circum>                          */ DEADTRANS( L'^'	,0xE8E3	,0xE8E3	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright><%percent>                         */ DEADTRANS( L'%'	,0xE8E4	,0xE8E4	,0x0001), // Multikey chain.
/*<!M><%parenright><%parenright><%underscore>                      */ DEADTRANS( L'_'	,0xE8E5	,0xE8E5	,0x0001), // Multikey chain.
/*<!M><%parenright><%percent>                                      */ DEADTRANS( L'%'	,0xE8E6	,0xE8E6	,0x0001), // Multikey chain.
/*<!M><%parenright><%percent><%parenright>                         */ DEADTRANS( L')'	,0xE8E7	,0xE8E7	,0x0001), // Multikey chain.
/*<!M><%parenright><%period>                                       */ DEADTRANS( L'.'	,0xE8E8	,0xE8E8	,0x0001), // Multikey chain.
/*<!M><%parenright><%tilde>                                        */ DEADTRANS( L'~'	,0xE8E9	,0xE8E9	,0x0001), // Multikey chain.
/*<!M><%parenright><%underscore><%parenright>                      */ DEADTRANS( L')'	,0xE8EA	,0xE8EA	,0x0001), // Multikey chain.
/*<!M><%percent><%bar><%braceright>                                */ DEADTRANS( L'}'	,0xE8EC	,0xE8EC	,0x0001), // Multikey chain.
/*<!M><%percent><%bar><%circum>                                    */ DEADTRANS( L'^'	,0xE8ED	,0xE8ED	,0x0001), // Multikey chain.
/*<!M><%percent><%bar>                                             */ DEADTRANS( L'|'	,0xE8EE	,0xE8EE	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%braceleft><%percent>                 */ DEADTRANS( L'%'	,0xE8EF	,0xE8EF	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%braceleft>                           */ DEADTRANS( L'{'	,0xE8F0	,0xE8F0	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%braceright>                          */ DEADTRANS( L'}'	,0xE8F1	,0xE8F1	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%circum>                              */ DEADTRANS( L'^'	,0xE8F2	,0xE8F2	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%percent><%braceleft>                 */ DEADTRANS( L'{'	,0xE8F3	,0xE8F3	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft><%percent>                             */ DEADTRANS( L'%'	,0xE8F4	,0xE8F4	,0x0001), // Multikey chain.
/*<!M><%percent><%braceleft>                                       */ DEADTRANS( L'{'	,0xE8F5	,0xE8F5	,0x0001), // Multikey chain.
/*<!M><%percent><%braceright><%bar>                                */ DEADTRANS( L'|'	,0xE8F6	,0xE8F6	,0x0001), // Multikey chain.
/*<!M><%percent><%braceright><%braceleft>                          */ DEADTRANS( L'{'	,0xE8F7	,0xE8F7	,0x0001), // Multikey chain.
/*<!M><%percent><%braceright><%braceright>                         */ DEADTRANS( L'}'	,0xE8F8	,0xE8F8	,0x0001), // Multikey chain.
/*<!M><%percent><%braceright>                                      */ DEADTRANS( L'}'	,0xE8F9	,0xE8F9	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%bar>                                    */ DEADTRANS( L'|'	,0xE8FA	,0xE8FA	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%braceleft>                              */ DEADTRANS( L'{'	,0xE8FB	,0xE8FB	,0x0001), // Multikey chain.
/*<!M><%percent><%circum>                                          */ DEADTRANS( L'^'	,0xE8FC	,0xE8FC	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%hash><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE8FD	,0xE8FD	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE8FE	,0xE8FE	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%hash><3>                                */ DEADTRANS( L'3'	,0xE8FF	,0xE8FF	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%hash>                                   */ DEADTRANS( L'#'	,0xE900	,0xE900	,0x0001), // Multikey chain.
/*<!M><%percent><%circum><%percent>                                */ DEADTRANS( L'%'	,0xE901	,0xE901	,0x0001), // Multikey chain.
/*<!M><%percent><%colon><%percent>                                 */ DEADTRANS( L'%'	,0xE902	,0xE902	,0x0001), // Multikey chain.
/*<!M><%percent><%colon>                                           */ DEADTRANS( L':'	,0xE903	,0xE903	,0x0001), // Multikey chain.
/*<!M><%percent><%hash>                                            */ DEADTRANS( L'#'	,0xE904	,0xE904	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><%hash>                                     */ DEADTRANS( L'#'	,0xE905	,0xE905	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><%hash><%hash><%hash>                       */ DEADTRANS( L'#'	,0xE906	,0xE906	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><%hash><%hash>                              */ DEADTRANS( L'#'	,0xE907	,0xE907	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><1>                                         */ DEADTRANS( L'1'	,0xE908	,0xE908	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><2>                                         */ DEADTRANS( L'2'	,0xE909	,0xE909	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><3>                                         */ DEADTRANS( L'3'	,0xE90A	,0xE90A	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><4>                                         */ DEADTRANS( L'4'	,0xE90B	,0xE90B	,0x0001), // Multikey chain.
/*<!M><%percent><%hash><5>                                         */ DEADTRANS( L'5'	,0xE90C	,0xE90C	,0x0001), // Multikey chain.
/*<!M><%percent><%minus><%hash>                                    */ DEADTRANS( L'#'	,0xE90D	,0xE90D	,0x0001), // Multikey chain.
/*<!M><%percent><%minus>                                           */ DEADTRANS( L'-'	,0xE90E	,0xE90E	,0x0001), // Multikey chain.
/*<!M><%percent><%parenright>                                      */ DEADTRANS( L')'	,0xE90F	,0xE90F	,0x0001), // Multikey chain.
/*<!M><%percent><%parenright><%parenright>                         */ DEADTRANS( L')'	,0xE910	,0xE910	,0x0001), // Multikey chain.
/*<!M><%percent><%percent>                                         */ DEADTRANS( L'%'	,0xE911	,0xE911	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%braceleft><%braceleft>                 */ DEADTRANS( L'{'	,0xE912	,0xE912	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%braceleft>                             */ DEADTRANS( L'{'	,0xE913	,0xE913	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%circum>                                */ DEADTRANS( L'^'	,0xE914	,0xE914	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%colon>                                 */ DEADTRANS( L':'	,0xE915	,0xE915	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%hash><%hash><%hash>                    */ DEADTRANS( L'#'	,0xE916	,0xE916	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%hash><%hash>                           */ DEADTRANS( L'#'	,0xE917	,0xE917	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%hash><3>                               */ DEADTRANS( L'3'	,0xE918	,0xE918	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%hash>                                  */ DEADTRANS( L'#'	,0xE919	,0xE919	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%slash>                                 */ DEADTRANS( L'/'	,0xE91A	,0xE91A	,0x0001), // Multikey chain.
/*<!M><%percent><%percent><%underscore>                            */ DEADTRANS( L'_'	,0xE91B	,0xE91B	,0x0001), // Multikey chain.
/*<!M><%percent><%slash><%hash><%hash><%hash>                      */ DEADTRANS( L'#'	,0xE91C	,0xE91C	,0x0001), // Multikey chain.
/*<!M><%percent><%slash><%hash><%hash>                             */ DEADTRANS( L'#'	,0xE91D	,0xE91D	,0x0001), // Multikey chain.
/*<!M><%percent><%slash><%hash><3>                                 */ DEADTRANS( L'3'	,0xE91E	,0xE91E	,0x0001), // Multikey chain.
/*<!M><%percent><%slash><%hash>                                    */ DEADTRANS( L'#'	,0xE91F	,0xE91F	,0x0001), // Multikey chain.
/*<!M><%percent><%slash><%percent>                                 */ DEADTRANS( L'%'	,0xE920	,0xE920	,0x0001), // Multikey chain.
/*<!M><%percent><%slash>                                           */ DEADTRANS( L'/'	,0xE921	,0xE921	,0x0001), // Multikey chain.
/*<!M><%percent><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xE922	,0xE922	,0x0001), // Multikey chain.
/*<!M><%percent><%tilde>                                           */ DEADTRANS( L'~'	,0xE923	,0xE923	,0x0001), // Multikey chain.
/*<!M><%percent><%underscore><%percent>                            */ DEADTRANS( L'%'	,0xE924	,0xE924	,0x0001), // Multikey chain.
/*<!M><%percent><%underscore><%underscore>                         */ DEADTRANS( L'_'	,0xE925	,0xE925	,0x0001), // Multikey chain.
/*<!M><%percent><%underscore>                                      */ DEADTRANS( L'_'	,0xE926	,0xE926	,0x0001), // Multikey chain.
/*<!M><%period><%apostrophe><%grave>                               */ DEADTRANS( L'`'	,0xE927	,0xE927	,0x0001), // Multikey chain.
/*<!M><%period><%apostrophe>                                       */ DEADTRANS( L'\''	,0xE928	,0xE928	,0x0001), // Multikey chain.
/*<!M><%period><%bar>                                              */ DEADTRANS( L'|'	,0xE929	,0xE929	,0x0001), // Multikey chain.
/*<!M><%period><%exclam>                                           */ DEADTRANS( L'!'	,0xE92A	,0xE92A	,0x0001), // Multikey chain.
/*<!M><%period><%grave><%apostrophe>                               */ DEADTRANS( L'\''	,0xE92B	,0xE92B	,0x0001), // Multikey chain.
/*<!M><%period><%grave>                                            */ DEADTRANS( L'`'	,0xE92C	,0xE92C	,0x0001), // Multikey chain.
/*<!M><%period><%hash>                                             */ DEADTRANS( L'#'	,0xE92D	,0xE92D	,0x0001), // Multikey chain.
/*<!M><%period><%hash><%hash>                                      */ DEADTRANS( L'#'	,0xE92E	,0xE92E	,0x0001), // Multikey chain.
/*<!M><%period><%hash><%hash><%hash>                               */ DEADTRANS( L'#'	,0xE92F	,0xE92F	,0x0001), // Multikey chain.
/*<!M><%period><%hash><3>                                          */ DEADTRANS( L'3'	,0xE930	,0xE930	,0x0001), // Multikey chain.
/*<!M><%period><%parenright>                                       */ DEADTRANS( L')'	,0xE931	,0xE931	,0x0001), // Multikey chain.
/*<!M><%period><%period><%apostrophe><%grave>                      */ DEADTRANS( L'`'	,0xE932	,0xE932	,0x0001), // Multikey chain.
/*<!M><%period><%period><%apostrophe>                              */ DEADTRANS( L'\''	,0xE933	,0xE933	,0x0001), // Multikey chain.
/*<!M><%period><%period><%bar>                                     */ DEADTRANS( L'|'	,0xE934	,0xE934	,0x0001), // Multikey chain.
/*<!M><%period><%period><%grave><%apostrophe>                      */ DEADTRANS( L'\''	,0xE935	,0xE935	,0x0001), // Multikey chain.
/*<!M><%period><%period><%grave>                                   */ DEADTRANS( L'`'	,0xE936	,0xE936	,0x0001), // Multikey chain.
/*<!M><%plus><%apostrophe>                                         */ DEADTRANS( L'\''	,0xE937	,0xE937	,0x0001), // Multikey chain.
/*<!M><%plus><%bracketright>                                       */ DEADTRANS( L']'	,0xE938	,0xE938	,0x0001), // Multikey chain.
/*<!M><%plus><%exclam>                                             */ DEADTRANS( L'!'	,0xE939	,0xE939	,0x0001), // Multikey chain.
/*<!M><%plus><%grave>                                              */ DEADTRANS( L'`'	,0xE93A	,0xE93A	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%at><%colon>                                     */ DEADTRANS( L':'	,0xE93C	,0xE93C	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%at>                                             */ DEADTRANS( L'@'	,0xE93D	,0xE93D	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%backslash>                                      */ DEADTRANS( L'\\'	,0xE93E	,0xE93E	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%colon><%at>                                     */ DEADTRANS( L'@'	,0xE93F	,0xE93F	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%quotedbl>                                       */ DEADTRANS( L'"'	,0xE940	,0xE940	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%at><%colon>                                 */ DEADTRANS( L':'	,0xE942	,0xE942	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%at>                                         */ DEADTRANS( L'@'	,0xE943	,0xE943	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%backslash>                                  */ DEADTRANS( L'\\'	,0xE944	,0xE944	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%colon><%at>                                 */ DEADTRANS( L'@'	,0xE945	,0xE945	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%quotEuroSign>                               */ DEADTRANS( 0x20AC	,0xE946	,0xE946	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><%hash><%hash><%hash>                     */ DEADTRANS( L'#'	,0xE947	,0xE947	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><%hash><%hash>                            */ DEADTRANS( L'#'	,0xE948	,0xE948	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><%hash>                                   */ DEADTRANS( L'#'	,0xE949	,0xE949	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><3>                                       */ DEADTRANS( L'3'	,0xE94A	,0xE94A	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><4>                                       */ DEADTRANS( L'4'	,0xE94B	,0xE94B	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash><5>                                       */ DEADTRANS( L'5'	,0xE94C	,0xE94C	,0x0001), // Multikey chain.
/*<!M><%semicolon><%hash>                                          */ DEADTRANS( L'#'	,0xE94D	,0xE94D	,0x0001), // Multikey chain.
/*<!M><%semicolon><%semicolon>                                     */ DEADTRANS( L';'	,0xE94E	,0xE94E	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><%hash><%hash><%hash>                    */ DEADTRANS( L'#'	,0xE950	,0xE950	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><%hash><%hash>                           */ DEADTRANS( L'#'	,0xE951	,0xE951	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><%hash>                                  */ DEADTRANS( L'#'	,0xE952	,0xE952	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><3>                                      */ DEADTRANS( L'3'	,0xE953	,0xE953	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><4>                                      */ DEADTRANS( L'4'	,0xE954	,0xE954	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash><5>                                      */ DEADTRANS( L'5'	,0xE955	,0xE955	,0x0001), // Multikey chain.
/*<!M><%semsection><%hash>                                         */ DEADTRANS( L'#'	,0xE956	,0xE956	,0x0001), // Multikey chain.
/*<!M><%semsection><%semsection>                                   */ DEADTRANS( 0x00A7	,0xE957	,0xE957	,0x0001), // Multikey chain.
/*<!M><%slash><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE959	,0xE959	,0x0001), // Multikey chain.
/*<!M><%slash><%hash>                                              */ DEADTRANS( L'#'	,0xE95A	,0xE95A	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><%hash>                                       */ DEADTRANS( L'#'	,0xE95B	,0xE95B	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><%hash><%hash>                                */ DEADTRANS( L'#'	,0xE95C	,0xE95C	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><%hash><%hash><%hash>                         */ DEADTRANS( L'#'	,0xE95D	,0xE95D	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><1>                                           */ DEADTRANS( L'1'	,0xE95E	,0xE95E	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><2>                                           */ DEADTRANS( L'2'	,0xE95F	,0xE95F	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><3>                                           */ DEADTRANS( L'3'	,0xE960	,0xE960	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><4>                                           */ DEADTRANS( L'4'	,0xE961	,0xE961	,0x0001), // Multikey chain.
/*<!M><%slash><%hash><5>                                           */ DEADTRANS( L'5'	,0xE962	,0xE962	,0x0001), // Multikey chain.
/*<!M><%slash><%percent><%hash><%hash><%hash>                      */ DEADTRANS( L'#'	,0xE963	,0xE963	,0x0001), // Multikey chain.
/*<!M><%slash><%percent><%hash><%hash>                             */ DEADTRANS( L'#'	,0xE964	,0xE964	,0x0001), // Multikey chain.
/*<!M><%slash><%percent><%hash><3>                                 */ DEADTRANS( L'3'	,0xE965	,0xE965	,0x0001), // Multikey chain.
/*<!M><%slash><%percent><%hash>                                    */ DEADTRANS( L'#'	,0xE966	,0xE966	,0x0001), // Multikey chain.
/*<!M><%slash><%percent><%percent>                                 */ DEADTRANS( L'%'	,0xE967	,0xE967	,0x0001), // Multikey chain.
/*<!M><%slash><%percent>                                           */ DEADTRANS( L'%'	,0xE968	,0xE968	,0x0001), // Multikey chain.
/*<!M><%slash><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xE969	,0xE969	,0x0001), // Multikey chain.
/*<!M><%slash><%slash>                                             */ DEADTRANS( L'/'	,0xE96A	,0xE96A	,0x0001), // Multikey chain.
/*<!M><%slash><%tilde>                                             */ DEADTRANS( L'~'	,0xE96B	,0xE96B	,0x0001), // Multikey chain.
/*<!M><%tilde><%ampersand>                                         */ DEADTRANS( L'&'	,0xE96C	,0xE96C	,0x0001), // Multikey chain.
/*<!M><%tilde><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE96D	,0xE96D	,0x0001), // Multikey chain.
/*<!M><%tilde><%braceleft>                                         */ DEADTRANS( L'{'	,0xE96F	,0xE96F	,0x0001), // Multikey chain.
/*<!M><%tilde><%circum>                                            */ DEADTRANS( L'^'	,0xE970	,0xE970	,0x0001), // Multikey chain.
/*<!M><%tilde><%colon>                                             */ DEADTRANS( L':'	,0xE971	,0xE971	,0x0001), // Multikey chain.
/*<!M><%tilde><%parenright>                                        */ DEADTRANS( L')'	,0xE972	,0xE972	,0x0001), // Multikey chain.
/*<!M><%tilde><%percent><%tilde>                                   */ DEADTRANS( L'~'	,0xE973	,0xE973	,0x0001), // Multikey chain.
/*<!M><%tilde><%percent>                                           */ DEADTRANS( L'%'	,0xE974	,0xE974	,0x0001), // Multikey chain.
/*<!M><%tilde><%tilde><%percent>                                   */ DEADTRANS( L'%'	,0xE975	,0xE975	,0x0001), // Multikey chain.
/*<!M><%underscore><%at>                                           */ DEADTRANS( L'@'	,0xE976	,0xE976	,0x0001), // Multikey chain.
/*<!M><%underscore><%braceleft>                                    */ DEADTRANS( L'{'	,0xE977	,0xE977	,0x0001), // Multikey chain.
/*<!M><%underscore><%circum>                                       */ DEADTRANS( L'^'	,0xE978	,0xE978	,0x0001), // Multikey chain.
/*<!M><%underscore><%circum><%hash>                                */ DEADTRANS( L'#'	,0xE979	,0xE979	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%hash><%hash><%hash>                    */ DEADTRANS( L'#'	,0xE97A	,0xE97A	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%hash><%hash>                           */ DEADTRANS( L'#'	,0xE97B	,0xE97B	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%hash>                                  */ DEADTRANS( L'#'	,0xE97C	,0xE97C	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><3>                                      */ DEADTRANS( L'3'	,0xE97D	,0xE97D	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><4>                                      */ DEADTRANS( L'4'	,0xE97E	,0xE97E	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><6>                                      */ DEADTRANS( L'6'	,0xE97F	,0xE97F	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash>                                         */ DEADTRANS( L'#'	,0xE980	,0xE980	,0x0001), // Multikey chain.
/*<!M><%underscore><%minus>                                        */ DEADTRANS( L'-'	,0xE981	,0xE981	,0x0001), // Multikey chain.
/*<!M><%underscore><%parenright>                                   */ DEADTRANS( L')'	,0xE982	,0xE982	,0x0001), // Multikey chain.
/*<!M><%underscore><%parenright><%parenright>                      */ DEADTRANS( L')'	,0xE983	,0xE983	,0x0001), // Multikey chain.
/*<!M><%underscore><%percent><%percent>                            */ DEADTRANS( L'%'	,0xE984	,0xE984	,0x0001), // Multikey chain.
/*<!M><%underscore><%percent><%underscore>                         */ DEADTRANS( L'_'	,0xE985	,0xE985	,0x0001), // Multikey chain.
/*<!M><%underscore><%percent>                                      */ DEADTRANS( L'%'	,0xE986	,0xE986	,0x0001), // Multikey chain.
/*<!M><%underscore><%underscore><%percent>                         */ DEADTRANS( L'%'	,0xE987	,0xE987	,0x0001), // Multikey chain.
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L'.'	,0xE207	,0xE207	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE67B	,0xE67B	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE67C	,0xE67C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%at>                               */ DEADTRANS( L'@'	,0xE683	,0xE683	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE684	,0xE684	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE687	,0xE687	,0x0001), // Multikey chain.
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L'/'	,0xE21B	,0xE21B	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%circum>                                 */ DEADTRANS( L'^'	,0xE711	,0xE711	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%percent>                                */ DEADTRANS( L'%'	,0xE712	,0xE712	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%braceright>                                 */ DEADTRANS( L'}'	,0xE714	,0xE714	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%percent>                                    */ DEADTRANS( L'%'	,0xE715	,0xE715	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%circum>                                 */ DEADTRANS( L'^'	,0xE75C	,0xE75C	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%percent>                                */ DEADTRANS( L'%'	,0xE75D	,0xE75D	,0x0001), // Multikey chain.
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'/'	,0xE25C	,0xE25C	,0x0001), // Multikey chain.
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'\\'	,0xE260	,0xE260	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%braceright>                                 */ DEADTRANS( L'}'	,0xE796	,0xE796	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%percent>                                    */ DEADTRANS( L'%'	,0xE797	,0xE797	,0x0001), // Multikey chain.
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE27A	,0xE27A	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE7EF	,0xE7EF	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE7F0	,0xE7F0	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE806	,0xE806	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE807	,0xE807	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE80B	,0xE80B	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE80C	,0xE80C	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE80E	,0xE80E	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at>                                   */ DEADTRANS( L'@'	,0xE812	,0xE812	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%grave><%at>                           */ DEADTRANS( L'@'	,0xE813	,0xE813	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%less><%at>                            */ DEADTRANS( L'@'	,0xE814	,0xE814	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE815	,0xE815	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%grave><%at>                          */ DEADTRANS( L'@'	,0xE81A	,0xE81A	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%less><%at>                           */ DEADTRANS( L'@'	,0xE81B	,0xE81B	,0x0001), // Multikey chain.
/*<!M><%exclam>comma><%minus>                                      */ DEADTRANS( L'-'	,0xE288	,0xE288	,0x0001), // Multikey chain.
/*<!M><%grave><%apostrophe><%bar>                                  */ DEADTRANS( L'|'	,0xE820	,0xE820	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE831	,0xE831	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE832	,0xE832	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%at>                                    */ DEADTRANS( L'@'	,0xE836	,0xE836	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE837	,0xE837	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE83A	,0xE83A	,0x0001), // Multikey chain.
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xE28C	,0xE28C	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE291	,0xE291	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE292	,0xE292	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L'>'	,0xE293	,0xE293	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L'>'	,0xE294	,0xE294	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L'>'	,0xE295	,0xE295	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L'>'	,0xE296	,0xE296	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'('	,0xE29F	,0xE29F	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L')'	,0xE2AA	,0xE2AA	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L'('	,0xE2AB	,0xE2AB	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE874	,0xE874	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE875	,0xE875	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L'-'	,0xE2C0	,0xE2C0	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE2C1	,0xE2C1	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE2C2	,0xE2C2	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L'-'	,0xE2C4	,0xE2C4	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE2C5	,0xE2C5	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L'-'	,0xE2C8	,0xE2C8	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L'-'	,0xE2C9	,0xE2C9	,0x0001), // Multikey chain.
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L'-'	,0xE2D7	,0xE2D7	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE881	,0xE881	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE884	,0xE884	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L')'	,0xE2ED	,0xE2ED	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L'('	,0xE2EE	,0xE2EE	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE2F8	,0xE2F8	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%exclam>                                    */ DEADTRANS( L'!'	,0xE2FC	,0xE2FC	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%less>                                      */ DEADTRANS( L'<'	,0xE2FD	,0xE2FD	,0x0001), // Multikey chain.
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE2FE	,0xE2FE	,0x0001), // Multikey chain.
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L'-'	,0xE302	,0xE302	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L'>'	,0xE307	,0xE307	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L'-'	,0xE30C	,0xE30C	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L'-'	,0xE30F	,0xE30F	,0x0001), // Multikey chain.
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L'>'	,0xE31A	,0xE31A	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%at>                               */ DEADTRANS( L'@'	,0xE899	,0xE899	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE89A	,0xE89A	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE8A6	,0xE8A6	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at>                                   */ DEADTRANS( L'@'	,0xE8AA	,0xE8AA	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%grave><%at>                           */ DEADTRANS( L'@'	,0xE8AB	,0xE8AB	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%less><%at>                            */ DEADTRANS( L'@'	,0xE8AC	,0xE8AC	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%at>                                    */ DEADTRANS( L'@'	,0xE8AE	,0xE8AE	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8AF	,0xE8AF	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE8BA	,0xE8BA	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><0><1>                                        */ DEADTRANS( L'1'	,0xE324	,0xE324	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><1><1>                                        */ DEADTRANS( L'1'	,0xE325	,0xE325	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE8BD	,0xE8BD	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE8D2	,0xE8D2	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%grave><%at>                          */ DEADTRANS( L'@'	,0xE8D7	,0xE8D7	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%less><%at>                           */ DEADTRANS( L'@'	,0xE8D8	,0xE8D8	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE8DC	,0xE8DC	,0x0001), // Multikey chain.
/*<!M><%parenright><%less><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8E0	,0xE8E0	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'0'	,0xE337	,0xE337	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'1'	,0xE338	,0xE338	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'2'	,0xE339	,0xE339	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'3'	,0xE33A	,0xE33A	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'0'	,0xE33B	,0xE33B	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'1'	,0xE33C	,0xE33C	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'2'	,0xE33D	,0xE33D	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'3'	,0xE33E	,0xE33E	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><0>                                       */ DEADTRANS( L'0'	,0xE33F	,0xE33F	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'1'	,0xE340	,0xE340	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'2'	,0xE341	,0xE341	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'0'	,0xE342	,0xE342	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'1'	,0xE343	,0xE343	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'3'	,0xE344	,0xE344	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'0'	,0xE345	,0xE345	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'1'	,0xE346	,0xE346	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'3'	,0xE347	,0xE347	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'0'	,0xE348	,0xE348	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'1'	,0xE349	,0xE349	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'3'	,0xE34A	,0xE34A	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'0'	,0xE34E	,0xE34E	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'1'	,0xE34F	,0xE34F	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'3'	,0xE350	,0xE350	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'0'	,0xE352	,0xE352	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'2'	,0xE353	,0xE353	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'0'	,0xE35B	,0xE35B	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'1'	,0xE35C	,0xE35C	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'3'	,0xE35D	,0xE35D	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'0'	,0xE35E	,0xE35E	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'1'	,0xE35F	,0xE35F	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'3'	,0xE360	,0xE360	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%colon><%at>                                 */ DEADTRANS( L'@'	,0xE945	,0xE945	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%colon><%at>                                     */ DEADTRANS( L'@'	,0xE93F	,0xE93F	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L'/'	,0xE396	,0xE396	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L'\\'	,0xE397	,0xE397	,0x0001), // Multikey chain.
/*<!M><E><M><F>                                                    */ DEADTRANS( L'F'	,0xE436	,0xE436	,0x0001), // Multikey chain.
/*<!M><E><M><O>                                                    */ DEADTRANS( L'O'	,0xE438	,0xE438	,0x0001), // Multikey chain.
/*<!M><E><n><v><e><l><o><p>                                        */ DEADTRANS( L'p'	,0xE440	,0xE440	,0x0001), // Multikey chain.
/*<!M><G><Eacute><M>                                               */ DEADTRANS( L'M'	,0xE459	,0xE459	,0x0001), // Multikey chain.
/*<!M><H><D><P>                                                    */ DEADTRANS( L'P'	,0xE465	,0xE465	,0x0001), // Multikey chain.
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'P'	,0xE47B	,0xE47B	,0x0001), // Multikey chain.
/*<!M><L><D><P>                                                    */ DEADTRANS( L'P'	,0xE49E	,0xE49E	,0x0001), // Multikey chain.
/*<!M><L><I><B>                                                    */ DEADTRANS( L'B'	,0xE4A3	,0xE4A3	,0x0001), // Multikey chain.
/*<!M><L><I><O>                                                    */ DEADTRANS( L'O'	,0xE4A5	,0xE4A5	,0x0001), // Multikey chain.
/*<!M><L><R><E>                                                    */ DEADTRANS( L'E'	,0xE4A8	,0xE4A8	,0x0001), // Multikey chain.
/*<!M><L><p><a><r><e><n><g>                                        */ DEADTRANS( L'g'	,0xE4A6	,0xE4A6	,0x0001), // Multikey chain.
/*<!M><P><A><C>                                                    */ DEADTRANS( L'C'	,0xE4DE	,0xE4DE	,0x0001), // Multikey chain.
/*<!M><P><A><R>                                                    */ DEADTRANS( L'R'	,0xE4E0	,0xE4E0	,0x0001), // Multikey chain.
/*<!M><P><A><T>                                                    */ DEADTRANS( L'T'	,0xE4E2	,0xE4E2	,0x0001), // Multikey chain.
/*<!M><P><I><S>                                                    */ DEADTRANS( L'S'	,0xE4EE	,0xE4EE	,0x0001), // Multikey chain.
/*<!M><P><O><I>                                                    */ DEADTRANS( L'I'	,0xE4F4	,0xE4F4	,0x0001), // Multikey chain.
/*<!M><R><C><C><C><D><D>                                           */ DEADTRANS( L'D'	,0xE509	,0xE509	,0x0001), // Multikey chain.
/*<!M><R><C><C><D>                                                 */ DEADTRANS( L'D'	,0xE50A	,0xE50A	,0x0001), // Multikey chain.
/*<!M><R><D><D>                                                    */ DEADTRANS( L'D'	,0xE50D	,0xE50D	,0x0001), // Multikey chain.
/*<!M><R><p><a><r><e><n><l>                                        */ DEADTRANS( L'l'	,0xE513	,0xE513	,0x0001), // Multikey chain.
/*<!M><V><E><R>                                                    */ DEADTRANS( L'R'	,0xE566	,0xE566	,0x0001), // Multikey chain.
/*<!M><V><I><E>                                                    */ DEADTRANS( L'E'	,0xE568	,0xE568	,0x0001), // Multikey chain.
/*<!M><V><I><R>                                                    */ DEADTRANS( L'R'	,0xE56A	,0xE56A	,0x0001), // Multikey chain.
/*<!M><a><q><u>                                                    */ DEADTRANS( L'u'	,0xE3D4	,0xE3D4	,0x0001), // Multikey chain.
/*<!M><a><r><i>                                                    */ DEADTRANS( L'i'	,0xE3D5	,0xE3D5	,0x0001), // Multikey chain.
/*<!M><b><a><l>                                                    */ DEADTRANS( L'l'	,0xE3E7	,0xE3E7	,0x0001), // Multikey chain.
/*<!M><b><e><l>                                                    */ DEADTRANS( L'l'	,0xE3EA	,0xE3EA	,0x0001), // Multikey chain.
/*<!M><b><eacute><l>                                               */ DEADTRANS( L'l'	,0xE3EB	,0xE3EB	,0x0001), // Multikey chain.
/*<!M><b><i><p>                                                    */ DEADTRANS( L'p'	,0xE3ED	,0xE3ED	,0x0001), // Multikey chain.
/*<!M><c><a><p><d><o>                                              */ DEADTRANS( L'o'	,0xE40A	,0xE40A	,0x0001), // Multikey chain.
/*<!M><c><c><%bracketleft><%underscore>                            */ DEADTRANS( L'_'	,0xE40D	,0xE40D	,0x0001), // Multikey chain.
/*<!M><c><u><p><d><o>                                              */ DEADTRANS( L'o'	,0xE41B	,0xE41B	,0x0001), // Multikey chain.
/*<!M><c><u><p><p><l><u>                                           */ DEADTRANS( L'u'	,0xE41C	,0xE41C	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><e>                                        */ DEADTRANS( L'e'	,0xE428	,0xE428	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><r>                                        */ DEADTRANS( L'r'	,0xE429	,0xE429	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><egrave><t><r>                                   */ DEADTRANS( L'r'	,0xE42A	,0xE42A	,0x0001), // Multikey chain.
/*<!M><f><e><n>                                                    */ DEADTRANS( L'n'	,0xE44A	,0xE44A	,0x0001), // Multikey chain.
/*<!M><g><eacute><m>                                               */ DEADTRANS( L'm'	,0xE458	,0xE458	,0x0001), // Multikey chain.
/*<!M><h><d><p>                                                    */ DEADTRANS( L'p'	,0xE464	,0xE464	,0x0001), // Multikey chain.
/*<!M><i><n><t><e><r><s><e>                                        */ DEADTRANS( L'e'	,0xE474	,0xE474	,0x0001), // Multikey chain.
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'p'	,0xE47A	,0xE47A	,0x0001), // Multikey chain.
/*<!M><l><d><p>                                                    */ DEADTRANS( L'p'	,0xE49D	,0xE49D	,0x0001), // Multikey chain.
/*<!M><l><i><b>                                                    */ DEADTRANS( L'b'	,0xE4A2	,0xE4A2	,0x0001), // Multikey chain.
/*<!M><l><i><o>                                                    */ DEADTRANS( L'o'	,0xE4A4	,0xE4A4	,0x0001), // Multikey chain.
/*<!M><l><r><e>                                                    */ DEADTRANS( L'e'	,0xE4A7	,0xE4A7	,0x0001), // Multikey chain.
/*<!M><p><a><c>                                                    */ DEADTRANS( L'c'	,0xE4DD	,0xE4DD	,0x0001), // Multikey chain.
/*<!M><p><a><r>                                                    */ DEADTRANS( L'r'	,0xE4DF	,0xE4DF	,0x0001), // Multikey chain.
/*<!M><p><a><t>                                                    */ DEADTRANS( L't'	,0xE4E1	,0xE4E1	,0x0001), // Multikey chain.
/*<!M><p><o><i>                                                    */ DEADTRANS( L'i'	,0xE4F3	,0xE4F3	,0x0001), // Multikey chain.
/*<!M><s><e><t><m><i><n><u>                                        */ DEADTRANS( L'u'	,0xE530	,0xE530	,0x0001), // Multikey chain.
/*<!M><u><n><i><o>                                                 */ DEADTRANS( L'o'	,0xE558	,0xE558	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenleft>                                  */ DEADTRANS( L'('	,0xE55B	,0xE55B	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenright>                                 */ DEADTRANS( L')'	,0xE55C	,0xE55C	,0x0001), // Multikey chain.
/*<!M><v><e><r>                                                    */ DEADTRANS( L'r'	,0xE565	,0xE565	,0x0001), // Multikey chain.
/*<!M><v><i><e>                                                    */ DEADTRANS( L'e'	,0xE567	,0xE567	,0x0001), // Multikey chain.
/*<!M><v><i><r>                                                    */ DEADTRANS( L'r'	,0xE569	,0xE569	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L'/'	,0xE587	,0xE587	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L'\\'	,0xE58D	,0xE58D	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L'e'	,0xE58E	,0xE58E	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%hash><%underscore>                       */ DEADTRANS( L'_'	,0xE5B1	,0xE5B1	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L'V'	,0xE5BD	,0xE5BD	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L'v'	,0xE5BC	,0xE5BC	,0x0001), // Multikey chain.
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L'e'	,0xE5CE	,0xE5CE	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L'/'	,0xE605	,0xE605	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L'\\'	,0xE60B	,0xE60B	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L'e'	,0xE60C	,0xE60C	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%hash><%underscore>                         */ DEADTRANS( L'_'	,0xE62F	,0xE62F	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L'V'	,0xE63B	,0xE63B	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L'v'	,0xE63A	,0xE63A	,0x0001), // Multikey chain.
/*<!M><~space><e><e>                                               */ DEADTRANS( L'e'	,0xE64C	,0xE64C	,0x0001), // Multikey chain.
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L'.'	,0xE207	,0xE207	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE67B	,0xE67B	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%exclam><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE67C	,0xE67C	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%at>                               */ DEADTRANS( L'@'	,0xE683	,0xE683	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenleft><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE684	,0xE684	,0x0001), // Multikey chain.
/*<!M><%apostrophe><%parenright><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE687	,0xE687	,0x0001), // Multikey chain.
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L'/'	,0xE21B	,0xE21B	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%circum>                                 */ DEADTRANS( L'^'	,0xE711	,0xE711	,0x0001), // Multikey chain.
/*<!M><%bar><%braceright><%percent>                                */ DEADTRANS( L'%'	,0xE712	,0xE712	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%braceright>                                 */ DEADTRANS( L'}'	,0xE714	,0xE714	,0x0001), // Multikey chain.
/*<!M><%bar><%circum><%percent>                                    */ DEADTRANS( L'%'	,0xE715	,0xE715	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%circum>                                 */ DEADTRANS( L'^'	,0xE75C	,0xE75C	,0x0001), // Multikey chain.
/*<!M><%braceright><%bar><%percent>                                */ DEADTRANS( L'%'	,0xE75D	,0xE75D	,0x0001), // Multikey chain.
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'/'	,0xE25C	,0xE25C	,0x0001), // Multikey chain.
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'\\'	,0xE260	,0xE260	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%braceright>                                 */ DEADTRANS( L'}'	,0xE796	,0xE796	,0x0001), // Multikey chain.
/*<!M><%circum><%bar><%percent>                                    */ DEADTRANS( L'%'	,0xE797	,0xE797	,0x0001), // Multikey chain.
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE27A	,0xE27A	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenleft><%at>                      */ DEADTRANS( L'@'	,0xE7EF	,0xE7EF	,0x0001), // Multikey chain.
/*<!M><%exclam><%apostrophe><%parenright><%at>                     */ DEADTRANS( L'@'	,0xE7F0	,0xE7F0	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE806	,0xE806	,0x0001), // Multikey chain.
/*<!M><%exclam><%grave><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE807	,0xE807	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE80B	,0xE80B	,0x0001), // Multikey chain.
/*<!M><%exclam><%less><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE80C	,0xE80C	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE80E	,0xE80E	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%at>                                   */ DEADTRANS( L'@'	,0xE812	,0xE812	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%grave><%at>                           */ DEADTRANS( L'@'	,0xE813	,0xE813	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenleft><%less><%at>                            */ DEADTRANS( L'@'	,0xE814	,0xE814	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE815	,0xE815	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%grave><%at>                          */ DEADTRANS( L'@'	,0xE81A	,0xE81A	,0x0001), // Multikey chain.
/*<!M><%exclam><%parenright><%less><%at>                           */ DEADTRANS( L'@'	,0xE81B	,0xE81B	,0x0001), // Multikey chain.
/*<!M><%exclam>comma><%minus>                                      */ DEADTRANS( L'-'	,0xE288	,0xE288	,0x0001), // Multikey chain.
/*<!M><%grave><%apostrophe><%bar>                                  */ DEADTRANS( L'|'	,0xE820	,0xE820	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenleft><%at>                           */ DEADTRANS( L'@'	,0xE831	,0xE831	,0x0001), // Multikey chain.
/*<!M><%grave><%exclam><%parenright><%at>                          */ DEADTRANS( L'@'	,0xE832	,0xE832	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%at>                                    */ DEADTRANS( L'@'	,0xE836	,0xE836	,0x0001), // Multikey chain.
/*<!M><%grave><%parenleft><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE837	,0xE837	,0x0001), // Multikey chain.
/*<!M><%grave><%parenright><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE83A	,0xE83A	,0x0001), // Multikey chain.
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xE28C	,0xE28C	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE291	,0xE291	,0x0001), // Multikey chain.
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE292	,0xE292	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L'>'	,0xE293	,0xE293	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L'>'	,0xE294	,0xE294	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L'>'	,0xE295	,0xE295	,0x0001), // Multikey chain.
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L'>'	,0xE296	,0xE296	,0x0001), // Multikey chain.
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'('	,0xE29F	,0xE29F	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L')'	,0xE2AA	,0xE2AA	,0x0001), // Multikey chain.
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L'('	,0xE2AB	,0xE2AB	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenleft><%at>                            */ DEADTRANS( L'@'	,0xE874	,0xE874	,0x0001), // Multikey chain.
/*<!M><%less><%exclam><%parenright><%at>                           */ DEADTRANS( L'@'	,0xE875	,0xE875	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L'-'	,0xE2C0	,0xE2C0	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE2C1	,0xE2C1	,0x0001), // Multikey chain.
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE2C2	,0xE2C2	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L'-'	,0xE2C4	,0xE2C4	,0x0001), // Multikey chain.
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE2C5	,0xE2C5	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L'-'	,0xE2C8	,0xE2C8	,0x0001), // Multikey chain.
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L'-'	,0xE2C9	,0xE2C9	,0x0001), // Multikey chain.
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L'-'	,0xE2D7	,0xE2D7	,0x0001), // Multikey chain.
/*<!M><%less><%parenleft><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE881	,0xE881	,0x0001), // Multikey chain.
/*<!M><%less><%parenright><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE884	,0xE884	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L')'	,0xE2ED	,0xE2ED	,0x0001), // Multikey chain.
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L'('	,0xE2EE	,0xE2EE	,0x0001), // Multikey chain.
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE2F8	,0xE2F8	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%exclam>                                    */ DEADTRANS( L'!'	,0xE2FC	,0xE2FC	,0x0001), // Multikey chain.
/*<!M><%minus><%comma><%less>                                      */ DEADTRANS( L'<'	,0xE2FD	,0xE2FD	,0x0001), // Multikey chain.
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE2FE	,0xE2FE	,0x0001), // Multikey chain.
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L'-'	,0xE302	,0xE302	,0x0001), // Multikey chain.
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L'>'	,0xE307	,0xE307	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L'-'	,0xE30C	,0xE30C	,0x0001), // Multikey chain.
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L'-'	,0xE30F	,0xE30F	,0x0001), // Multikey chain.
/*<!M><%minus><0><%minus>                                          */ DEADTRANS( L'-'	,0xE319	,0xE319	,0x0001), // Multikey chain.
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L'>'	,0xE31A	,0xE31A	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%at>                               */ DEADTRANS( L'@'	,0xE899	,0xE899	,0x0001), // Multikey chain.
/*<!M><%parenleft><%apostrophe><%exclam><%at>                      */ DEADTRANS( L'@'	,0xE89A	,0xE89A	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%apostrophe><%at>                      */ DEADTRANS( L'@'	,0xE8A6	,0xE8A6	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%at>                                   */ DEADTRANS( L'@'	,0xE8AA	,0xE8AA	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%grave><%at>                           */ DEADTRANS( L'@'	,0xE8AB	,0xE8AB	,0x0001), // Multikey chain.
/*<!M><%parenleft><%exclam><%less><%at>                            */ DEADTRANS( L'@'	,0xE8AC	,0xE8AC	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%at>                                    */ DEADTRANS( L'@'	,0xE8AE	,0xE8AE	,0x0001), // Multikey chain.
/*<!M><%parenleft><%grave><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8AF	,0xE8AF	,0x0001), // Multikey chain.
/*<!M><%parenleft><%less><%exclam><%at>                            */ DEADTRANS( L'@'	,0xE8BA	,0xE8BA	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><0><1>                                        */ DEADTRANS( L'1'	,0xE324	,0xE324	,0x0001), // Multikey chain.
/*<!M><%parenleft><0><1><1>                                        */ DEADTRANS( L'1'	,0xE325	,0xE325	,0x0001), // Multikey chain.
/*<!M><%parenright><%apostrophe><%exclam><%at>                     */ DEADTRANS( L'@'	,0xE8BD	,0xE8BD	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%apostrophe><%at>                     */ DEADTRANS( L'@'	,0xE8D2	,0xE8D2	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%grave><%at>                          */ DEADTRANS( L'@'	,0xE8D7	,0xE8D7	,0x0001), // Multikey chain.
/*<!M><%parenright><%exclam><%less><%at>                           */ DEADTRANS( L'@'	,0xE8D8	,0xE8D8	,0x0001), // Multikey chain.
/*<!M><%parenright><%grave><%exclam><%at>                          */ DEADTRANS( L'@'	,0xE8DC	,0xE8DC	,0x0001), // Multikey chain.
/*<!M><%parenright><%less><%exclam><%at>                           */ DEADTRANS( L'@'	,0xE8E0	,0xE8E0	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'0'	,0xE337	,0xE337	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'1'	,0xE338	,0xE338	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'2'	,0xE339	,0xE339	,0x0001), // Multikey chain.
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'3'	,0xE33A	,0xE33A	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'0'	,0xE33B	,0xE33B	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'1'	,0xE33C	,0xE33C	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'2'	,0xE33D	,0xE33D	,0x0001), // Multikey chain.
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'3'	,0xE33E	,0xE33E	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><0>                                       */ DEADTRANS( L'0'	,0xE33F	,0xE33F	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'1'	,0xE340	,0xE340	,0x0001), // Multikey chain.
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'2'	,0xE341	,0xE341	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'0'	,0xE342	,0xE342	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'1'	,0xE343	,0xE343	,0x0001), // Multikey chain.
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'3'	,0xE344	,0xE344	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'0'	,0xE345	,0xE345	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'1'	,0xE346	,0xE346	,0x0001), // Multikey chain.
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'3'	,0xE347	,0xE347	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'0'	,0xE348	,0xE348	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'1'	,0xE349	,0xE349	,0x0001), // Multikey chain.
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'3'	,0xE34A	,0xE34A	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'0'	,0xE34E	,0xE34E	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'1'	,0xE34F	,0xE34F	,0x0001), // Multikey chain.
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'3'	,0xE350	,0xE350	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'0'	,0xE352	,0xE352	,0x0001), // Multikey chain.
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'2'	,0xE353	,0xE353	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'0'	,0xE35B	,0xE35B	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'1'	,0xE35C	,0xE35C	,0x0001), // Multikey chain.
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'3'	,0xE35D	,0xE35D	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'0'	,0xE35E	,0xE35E	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'1'	,0xE35F	,0xE35F	,0x0001), // Multikey chain.
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'3'	,0xE360	,0xE360	,0x0001), // Multikey chain.
/*<!M><%quotEuroSign><%colon><%at>                                 */ DEADTRANS( L'@'	,0xE945	,0xE945	,0x0001), // Multikey chain.
/*<!M><%quotedbl><%colon><%at>                                     */ DEADTRANS( L'@'	,0xE93F	,0xE93F	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L'/'	,0xE396	,0xE396	,0x0001), // Multikey chain.
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L'\\'	,0xE397	,0xE397	,0x0001), // Multikey chain.
/*<!M><E><M><F>                                                    */ DEADTRANS( L'F'	,0xE436	,0xE436	,0x0001), // Multikey chain.
/*<!M><E><M><O>                                                    */ DEADTRANS( L'O'	,0xE438	,0xE438	,0x0001), // Multikey chain.
/*<!M><E><n><v><e><l><o><p>                                        */ DEADTRANS( L'p'	,0xE440	,0xE440	,0x0001), // Multikey chain.
/*<!M><G><Eacute><M>                                               */ DEADTRANS( L'M'	,0xE459	,0xE459	,0x0001), // Multikey chain.
/*<!M><H><D><P>                                                    */ DEADTRANS( L'P'	,0xE465	,0xE465	,0x0001), // Multikey chain.
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'P'	,0xE47B	,0xE47B	,0x0001), // Multikey chain.
/*<!M><L><D><P>                                                    */ DEADTRANS( L'P'	,0xE49E	,0xE49E	,0x0001), // Multikey chain.
/*<!M><L><I><B>                                                    */ DEADTRANS( L'B'	,0xE4A3	,0xE4A3	,0x0001), // Multikey chain.
/*<!M><L><I><O>                                                    */ DEADTRANS( L'O'	,0xE4A5	,0xE4A5	,0x0001), // Multikey chain.
/*<!M><L><R><E>                                                    */ DEADTRANS( L'E'	,0xE4A8	,0xE4A8	,0x0001), // Multikey chain.
/*<!M><L><p><a><r><e><n><g>                                        */ DEADTRANS( L'g'	,0xE4A6	,0xE4A6	,0x0001), // Multikey chain.
/*<!M><P><A><C>                                                    */ DEADTRANS( L'C'	,0xE4DE	,0xE4DE	,0x0001), // Multikey chain.
/*<!M><P><A><R>                                                    */ DEADTRANS( L'R'	,0xE4E0	,0xE4E0	,0x0001), // Multikey chain.
/*<!M><P><A><T>                                                    */ DEADTRANS( L'T'	,0xE4E2	,0xE4E2	,0x0001), // Multikey chain.
/*<!M><P><I><S>                                                    */ DEADTRANS( L'S'	,0xE4EE	,0xE4EE	,0x0001), // Multikey chain.
/*<!M><P><O><I>                                                    */ DEADTRANS( L'I'	,0xE4F4	,0xE4F4	,0x0001), // Multikey chain.
/*<!M><R><C><C><C><D><D>                                           */ DEADTRANS( L'D'	,0xE509	,0xE509	,0x0001), // Multikey chain.
/*<!M><R><C><C><D>                                                 */ DEADTRANS( L'D'	,0xE50A	,0xE50A	,0x0001), // Multikey chain.
/*<!M><R><D><D>                                                    */ DEADTRANS( L'D'	,0xE50D	,0xE50D	,0x0001), // Multikey chain.
/*<!M><R><p><a><r><e><n><l>                                        */ DEADTRANS( L'l'	,0xE513	,0xE513	,0x0001), // Multikey chain.
/*<!M><V><E><R>                                                    */ DEADTRANS( L'R'	,0xE566	,0xE566	,0x0001), // Multikey chain.
/*<!M><V><I><E>                                                    */ DEADTRANS( L'E'	,0xE568	,0xE568	,0x0001), // Multikey chain.
/*<!M><V><I><R>                                                    */ DEADTRANS( L'R'	,0xE56A	,0xE56A	,0x0001), // Multikey chain.
/*<!M><a><q><u>                                                    */ DEADTRANS( L'u'	,0xE3D4	,0xE3D4	,0x0001), // Multikey chain.
/*<!M><a><r><i>                                                    */ DEADTRANS( L'i'	,0xE3D5	,0xE3D5	,0x0001), // Multikey chain.
/*<!M><b><a><l>                                                    */ DEADTRANS( L'l'	,0xE3E7	,0xE3E7	,0x0001), // Multikey chain.
/*<!M><b><e><l>                                                    */ DEADTRANS( L'l'	,0xE3EA	,0xE3EA	,0x0001), // Multikey chain.
/*<!M><b><eacute><l>                                               */ DEADTRANS( L'l'	,0xE3EB	,0xE3EB	,0x0001), // Multikey chain.
/*<!M><b><i><p>                                                    */ DEADTRANS( L'p'	,0xE3ED	,0xE3ED	,0x0001), // Multikey chain.
/*<!M><c><a><p><d><o>                                              */ DEADTRANS( L'o'	,0xE40A	,0xE40A	,0x0001), // Multikey chain.
/*<!M><c><c><%bracketleft><%underscore>                            */ DEADTRANS( L'_'	,0xE40D	,0xE40D	,0x0001), // Multikey chain.
/*<!M><c><u><p><d><o>                                              */ DEADTRANS( L'o'	,0xE41B	,0xE41B	,0x0001), // Multikey chain.
/*<!M><c><u><p><p><l><u>                                           */ DEADTRANS( L'u'	,0xE41C	,0xE41C	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><e>                                        */ DEADTRANS( L'e'	,0xE428	,0xE428	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><e><t><r>                                        */ DEADTRANS( L'r'	,0xE429	,0xE429	,0x0001), // Multikey chain.
/*<!M><d><i><a><m><egrave><t><r>                                   */ DEADTRANS( L'r'	,0xE42A	,0xE42A	,0x0001), // Multikey chain.
/*<!M><f><e><n>                                                    */ DEADTRANS( L'n'	,0xE44A	,0xE44A	,0x0001), // Multikey chain.
/*<!M><g><eacute><m>                                               */ DEADTRANS( L'm'	,0xE458	,0xE458	,0x0001), // Multikey chain.
/*<!M><h><d><p>                                                    */ DEADTRANS( L'p'	,0xE464	,0xE464	,0x0001), // Multikey chain.
/*<!M><i><n><t><e><r><s><e>                                        */ DEADTRANS( L'e'	,0xE474	,0xE474	,0x0001), // Multikey chain.
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'p'	,0xE47A	,0xE47A	,0x0001), // Multikey chain.
/*<!M><l><d><p>                                                    */ DEADTRANS( L'p'	,0xE49D	,0xE49D	,0x0001), // Multikey chain.
/*<!M><l><i><b>                                                    */ DEADTRANS( L'b'	,0xE4A2	,0xE4A2	,0x0001), // Multikey chain.
/*<!M><l><i><o>                                                    */ DEADTRANS( L'o'	,0xE4A4	,0xE4A4	,0x0001), // Multikey chain.
/*<!M><l><r><e>                                                    */ DEADTRANS( L'e'	,0xE4A7	,0xE4A7	,0x0001), // Multikey chain.
/*<!M><p><a><c>                                                    */ DEADTRANS( L'c'	,0xE4DD	,0xE4DD	,0x0001), // Multikey chain.
/*<!M><p><a><r>                                                    */ DEADTRANS( L'r'	,0xE4DF	,0xE4DF	,0x0001), // Multikey chain.
/*<!M><p><a><t>                                                    */ DEADTRANS( L't'	,0xE4E1	,0xE4E1	,0x0001), // Multikey chain.
/*<!M><p><o><i>                                                    */ DEADTRANS( L'i'	,0xE4F3	,0xE4F3	,0x0001), // Multikey chain.
/*<!M><s><e><t><m><i><n><u>                                        */ DEADTRANS( L'u'	,0xE530	,0xE530	,0x0001), // Multikey chain.
/*<!M><u><n><i><o>                                                 */ DEADTRANS( L'o'	,0xE558	,0xE558	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenleft>                                  */ DEADTRANS( L'('	,0xE55B	,0xE55B	,0x0001), // Multikey chain.
/*<!M><v><%backslash><%parenright>                                 */ DEADTRANS( L')'	,0xE55C	,0xE55C	,0x0001), // Multikey chain.
/*<!M><v><e><r>                                                    */ DEADTRANS( L'r'	,0xE565	,0xE565	,0x0001), // Multikey chain.
/*<!M><v><i><e>                                                    */ DEADTRANS( L'e'	,0xE567	,0xE567	,0x0001), // Multikey chain.
/*<!M><v><i><r>                                                    */ DEADTRANS( L'r'	,0xE569	,0xE569	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L'/'	,0xE587	,0xE587	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L'\\'	,0xE58D	,0xE58D	,0x0001), // Multikey chain.
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L'e'	,0xE58E	,0xE58E	,0x0001), // Multikey chain.
/*<!M><~nbspace><%slash><%hash><%underscore>                       */ DEADTRANS( L'_'	,0xE5B1	,0xE5B1	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L'V'	,0xE5BD	,0xE5BD	,0x0001), // Multikey chain.
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L'v'	,0xE5BC	,0xE5BC	,0x0001), // Multikey chain.
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L'e'	,0xE5CE	,0xE5CE	,0x0001), // Multikey chain.
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L'/'	,0xE605	,0xE605	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L'\\'	,0xE60B	,0xE60B	,0x0001), // Multikey chain.
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L'e'	,0xE60C	,0xE60C	,0x0001), // Multikey chain.
/*<!M><~space><%slash><%hash><%underscore>                         */ DEADTRANS( L'_'	,0xE62F	,0xE62F	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L'V'	,0xE63B	,0xE63B	,0x0001), // Multikey chain.
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L'v'	,0xE63A	,0xE63A	,0x0001), // Multikey chain.
/*<!M><~space><e><e>                                               */ DEADTRANS( L'e'	,0xE64C	,0xE64C	,0x0001), // Multikey chain.

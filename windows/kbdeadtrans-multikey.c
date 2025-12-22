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
* Debug and upgrade to 6.1.4.0             6.1.4.0.0 Sun 2025-12-21T2013+0100
* Discard as broken                        6.1.3.2.0 Fri 2025-11-14T1331+0100
* Add the content as of build 6.1.3.0      6.1.3.0.0 Fri 2025-11-14T0658+0100
* Add partial kbdeadtrans-multikey.c       6.1.3.0.0 Fri 2025-11-14T0535+0100
*
* This file is included in kbdeadtrans.c.
*
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
* Unlike the dead key IDs, these multikey IDs encompass the full sequence,
* including the input.
*
\*****************************************************************************/

/*<!M><!M>                                                         */ DEADTRANS( 0x00A6	,0x00A6	,0x00A6	,0x0000), // '¦' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><%ampersand>                                                 */ DEADTRANS( L'&'	,0x00A6	,0xE202	,0x0001), // Multikey chain
/*<!M><%ampersand><%apostrophe>                                    */ DEADTRANS( L'\''	,0xE202	,0xE203	,0x0001), // Multikey chain
/*<!M><%ampersand><%apostrophe><%minus>                            */ DEADTRANS( L'-'	,0xE203	,0x20D0	,0x0000), // '-' ➔ "⃐" COMBINING LEFT HARPOON ABOVE
/*<!M><%ampersand><%apostrophe><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE203	,0x20D3	,0x0000), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%apostrophe><~space>                            */ DEADTRANS( L' '	,0xE203	,0x20D3	,0x0000), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%aprightsingquotmark>                           */ DEADTRANS( 0x2019	,0xE202	,0xE207	,0x0001), // Multikey chain
/*<!M><%ampersand><%aprightsingquotmark><%minus>                   */ DEADTRANS( L'-'	,0xE207	,0x20D0	,0x0000), // '-' ➔ "⃐" COMBINING LEFT HARPOON ABOVE
/*<!M><%ampersand><%aprightsingquotmark><~nbspace>                 */ DEADTRANS( 0x00A0	,0xE207	,0x20D3	,0x0000), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%aprightsingquotmark><~space>                   */ DEADTRANS( L' '	,0xE207	,0x20D3	,0x0000), // ' ' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><%ampersand><%backslash>                                     */ DEADTRANS( L'\\'	,0xE202	,0x20E5	,0x0000), // '\' ➔ "⃥" COMBINING REVERSE SOLIDUS OVERLAY
/*<!M><%ampersand><%bar>                                           */ DEADTRANS( L'|'	,0xE202	,0xE20C	,0x0001), // Multikey chain
/*<!M><%ampersand><%bar><%bar>                                     */ DEADTRANS( L'|'	,0xE20C	,0x20E6	,0x0000), // '|' ➔ "⃦" COMBINING DOUBLE VERTICAL STROKE OVERLAY
/*<!M><%ampersand><%bar><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE20C	,0x20D2	,0x0000), // ' ' ➔ "⃒" COMBINING LONG VERTICAL LINE OVERLAY
/*<!M><%ampersand><%bar><~space>                                   */ DEADTRANS( L' '	,0xE20C	,0x20D2	,0x0000), // ' ' ➔ "⃒" COMBINING LONG VERTICAL LINE OVERLAY
/*<!M><%ampersand><%comma>                                         */ DEADTRANS( L','	,0xE202	,0x2063	,0x0000), // ',' ➔ "⁣" INVISIBLE SEPARATOR
/*<!M><%ampersand><%grave>                                         */ DEADTRANS( L'`'	,0xE202	,0x20ED	,0x0000), // '`' ➔ "⃭" COMBINING LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%less>                                          */ DEADTRANS( L'<'	,0xE202	,0xE212	,0x0001), // Multikey chain
/*<!M><%ampersand><%less><%minus>                                  */ DEADTRANS( L'-'	,0xE212	,0xE213	,0x0001), // Multikey chain
/*<!M><%ampersand><%less><%minus><%greater>                        */ DEADTRANS( L'>'	,0xE213	,0x20E1	,0x0000), // '>' ➔ "⃡" COMBINING LEFT RIGHT ARROW ABOVE
/*<!M><%ampersand><%less><%minus><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE213	,0x20D6	,0x0000), // ' ' ➔ "⃖" COMBINING LEFT ARROW ABOVE
/*<!M><%ampersand><%less><%minus><~space>                          */ DEADTRANS( L' '	,0xE213	,0x20D6	,0x0000), // ' ' ➔ "⃖" COMBINING LEFT ARROW ABOVE
/*<!M><%ampersand><%less><%parenleft>                              */ DEADTRANS( L'('	,0xE212	,0x20D4	,0x0000), // '(' ➔ "⃔" COMBINING ANTICLOCKWISE ARROW ABOVE
/*<!M><%ampersand><%less><%underscore>                             */ DEADTRANS( L'_'	,0xE212	,0x20EE	,0x0000), // '_' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><%ampersand><%minus>                                         */ DEADTRANS( L'-'	,0xE202	,0xE219	,0x0001), // Multikey chain
/*<!M><%ampersand><%minus><%apostrophe>                            */ DEADTRANS( L'\''	,0xE219	,0x20EC	,0x0000), // ''' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%minus><%aprightsingquotmark>                   */ DEADTRANS( 0x2019	,0xE219	,0x20EC	,0x0000), // '’' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%minus><%grave>                                 */ DEADTRANS( L'`'	,0xE219	,0x20D1	,0x0000), // '`' ➔ "⃑" COMBINING RIGHT HARPOON ABOVE
/*<!M><%ampersand><%minus><%greater>                               */ DEADTRANS( L'>'	,0xE219	,0x20D7	,0x0000), // '>' ➔ "⃗" COMBINING RIGHT ARROW ABOVE
/*<!M><%ampersand><%parenleft>                                     */ DEADTRANS( L'('	,0xE202	,0x20D5	,0x0000), // '(' ➔ "⃕" COMBINING CLOCKWISE ARROW ABOVE
/*<!M><%ampersand><%percent>                                       */ DEADTRANS( L'%'	,0xE202	,0x214B	,0x0000), // '%' ➔ "⅋" TURNED AMPERSAND
/*<!M><%ampersand><%period>                                        */ DEADTRANS( L'.'	,0xE202	,0xE220	,0x0001), // Multikey chain
/*<!M><%ampersand><%period><%period>                               */ DEADTRANS( L'.'	,0xE220	,0xE221	,0x0001), // Multikey chain
/*<!M><%ampersand><%period><%period><%period>                      */ DEADTRANS( L'.'	,0xE221	,0xE222	,0x0001), // Multikey chain
/*<!M><%ampersand><%period><%period><%period><%period>             */ DEADTRANS( L'.'	,0xE222	,0x20DC	,0x0000), // '.' ➔ "⃜" COMBINING FOUR DOTS ABOVE
/*<!M><%ampersand><%period><%period><%period><~nbspace>            */ DEADTRANS( 0x00A0	,0xE222	,0x20DB	,0x0000), // ' ' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand><%period><%period><%period><~space>              */ DEADTRANS( L' '	,0xE222	,0x20DB	,0x0000), // ' ' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand><%plus>                                          */ DEADTRANS( L'+'	,0xE202	,0x2064	,0x0000), // '+' ➔ "⁤" INVISIBLE PLUS
/*<!M><%ampersand><%slash>                                         */ DEADTRANS( L'/'	,0xE202	,0x20EB	,0x0000), // '/' ➔ "⃫" COMBINING LONG DOUBLE SOLIDUS OVERLAY
/*<!M><%ampersand><%underscore>                                    */ DEADTRANS( L'_'	,0xE202	,0xE228	,0x0001), // Multikey chain
/*<!M><%ampersand><%underscore><%apostrophe>                       */ DEADTRANS( L'\''	,0xE228	,0x20EC	,0x0000), // ''' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%underscore><%aprightsingquotmark>              */ DEADTRANS( 0x2019	,0xE228	,0x20EC	,0x0000), // '’' ➔ "⃬" COMBINING RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%ampersand><%underscore><%greater>                          */ DEADTRANS( L'>'	,0xE228	,0x20EF	,0x0000), // '>' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><%ampersand><3>                                              */ DEADTRANS( L'3'	,0xE202	,0x20DB	,0x0000), // '3' ➔ "⃛" COMBINING THREE DOTS ABOVE
/*<!M><%ampersand><4>                                              */ DEADTRANS( L'4'	,0xE202	,0x20DC	,0x0000), // '4' ➔ "⃜" COMBINING FOUR DOTS ABOVE
/*<!M><%ampersand><9>                                              */ DEADTRANS( L'9'	,0xE202	,0x1DD2	,0x0000), // '9' ➔ "᷒" COMBINING US ABOVE
/*<!M><%ampersand><a>                                              */ DEADTRANS( L'a'	,0xE202	,0xE22F	,0x0001), // Multikey chain
/*<!M><%ampersand><a><e>                                           */ DEADTRANS( L'e'	,0xE22F	,0x1DD4	,0x0000), // 'e' ➔ "ᷔ" COMBINING LATIN SMALL LETTER AE
/*<!M><%ampersand><a><o>                                           */ DEADTRANS( L'o'	,0xE22F	,0x1DD5	,0x0000), // 'o' ➔ "ᷕ" COMBINING LATIN SMALL LETTER AO
/*<!M><%ampersand><a><v>                                           */ DEADTRANS( L'v'	,0xE22F	,0x1DD6	,0x0000), // 'v' ➔ "ᷖ" COMBINING LATIN SMALL LETTER AV
/*<!M><%ampersand><a><w>                                           */ DEADTRANS( L'w'	,0xE22F	,0x1DD3	,0x0000), // 'w' ➔ "ᷓ" COMBINING LATIN SMALL LETTER FLATTENED OPEN A ABOVE
/*<!M><%ampersand><f>                                              */ DEADTRANS( L'f'	,0xE202	,0x2061	,0x0000), // 'f' ➔ "⁡" FUNCTION APPLICATION invisible
/*<!M><%ampersand><i>                                              */ DEADTRANS( L'i'	,0xE202	,0x1DD0	,0x0000), // 'i' ➔ "᷐" COMBINING IS BELOW
/*<!M><%ampersand><n>                                              */ DEADTRANS( L'n'	,0xE202	,0x0149	,0x0000), // 'n' ➔ "ŉ" LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*<!M><%ampersand><o>                                              */ DEADTRANS( L'o'	,0xE202	,0xE237	,0x0001), // Multikey chain
/*<!M><%ampersand><o><%greater>                                    */ DEADTRANS( L'>'	,0xE237	,0xE238	,0x0001), // Multikey chain
/*<!M><%ampersand><o><%greater><%backslash>                        */ DEADTRANS( L'\\'	,0xE238	,0x20DA	,0x0000), // '\' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater><%percent>                          */ DEADTRANS( L'%'	,0xE238	,0x20DA	,0x0000), // '%' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE238	,0x20D9	,0x0000), // ' ' ➔ "⃙" COMBINING CLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%greater><~space>                            */ DEADTRANS( L' '	,0xE238	,0x20D9	,0x0000), // ' ' ➔ "⃙" COMBINING CLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><%less>                                       */ DEADTRANS( L'<'	,0xE237	,0x20DA	,0x0000), // '<' ➔ "⃚" COMBINING ANTICLOCKWISE RING OVERLAY
/*<!M><%ampersand><o><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE237	,0x20D8	,0x0000), // ' ' ➔ "⃘" COMBINING RING OVERLAY
/*<!M><%ampersand><o><~space>                                      */ DEADTRANS( L' '	,0xE237	,0x20D8	,0x0000), // ' ' ➔ "⃘" COMBINING RING OVERLAY
/*<!M><%ampersand><u>                                              */ DEADTRANS( L'u'	,0xE202	,0xE240	,0x0001), // Multikey chain
/*<!M><%ampersand><u><r>                                           */ DEADTRANS( L'r'	,0xE240	,0x1DD1	,0x0000), // 'r' ➔ "᷑" COMBINING UR ABOVE
/*<!M><%ampersand><u><s>                                           */ DEADTRANS( L's'	,0xE240	,0x1DD2	,0x0000), // 's' ➔ "᷒" COMBINING US ABOVE
/*<!M><%ampersand><x>                                              */ DEADTRANS( L'x'	,0xE202	,0x2062	,0x0000), // 'x' ➔ "⁢" INVISIBLE TIMES
/*<!M><%ampersand><z>                                              */ DEADTRANS( L'z'	,0xE202	,0x1DCF	,0x0000), // 'z' ➔ "᷏" COMBINING ZIGZAG BELOW
/*<!M><%apostrophe>                                                */ DEADTRANS( L'\''	,0x00A6	,0xE245	,0x0001), // Multikey chain
/*<!M><%apostrophe><%equal>                                        */ DEADTRANS( L'='	,0xE245	,0xE246	,0x0001), // Multikey chain
/*<!M><%apostrophe><%equal><%apostrophe>                           */ DEADTRANS( L'\''	,0xE246	,0x2AE9	,0x0000), // ''' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><%apostrophe><%equal><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE246	,0x2AE8	,0x0000), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%apostrophe><%equal><~space>                                */ DEADTRANS( L' '	,0xE246	,0x2AE8	,0x0000), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%apostrophe><%exclam>                                       */ DEADTRANS( L'!'	,0xE245	,0xE24A	,0x0001), // Multikey chain
/*<!M><%apostrophe><%exclam><%apostrophe>                          */ DEADTRANS( L'\''	,0xE24A	,0x294D	,0x0000), // ''' ➔ "⥍" UP BARB LEFT DOWN BARB RIGHT HARPOON
/*<!M><%apostrophe><%exclam><%bar>                                 */ DEADTRANS( L'|'	,0xE24A	,0x2960	,0x0000), // '|' ➔ "⥠" UPWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%apostrophe><%exclam><%exclam>                              */ DEADTRANS( L'!'	,0xE24A	,0x296E	,0x0000), // '!' ➔ "⥮" UPWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%apostrophe><%exclam><%grave>                               */ DEADTRANS( L'`'	,0xE24A	,0xE24E	,0x0001), // Multikey chain
/*<!M><%apostrophe><%exclam><%grave><%exclam>                      */ DEADTRANS( L'!'	,0xE24E	,0x2963	,0x0000), // '!' ➔ "⥣" UPWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%apostrophe><%exclam><%grave><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE24E	,0x2951	,0x0000), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%apostrophe><%exclam><%grave><~space>                       */ DEADTRANS( L' '	,0xE24E	,0x2951	,0x0000), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%apostrophe><%exclam><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE24A	,0x21BF	,0x0000), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%apostrophe><%exclam><~space>                               */ DEADTRANS( L' '	,0xE24A	,0x21BF	,0x0000), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%apostrophe><%minus>                                        */ DEADTRANS( L'-'	,0xE245	,0xE254	,0x0001), // Multikey chain
/*<!M><%apostrophe><%minus><%apostrophe>                           */ DEADTRANS( L'\''	,0xE254	,0x294A	,0x0000), // ''' ➔ "⥊" LEFT BARB UP RIGHT BARB DOWN HARPOON
/*<!M><%apostrophe><%minus><%bar>                                  */ DEADTRANS( L'|'	,0xE254	,0x295A	,0x0000), // '|' ➔ "⥚" LEFTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%apostrophe><%minus><%comma>                                */ DEADTRANS( L','	,0xE254	,0xDCD5	,0x0000), // High surrogate: D83E; U+1F8D5 ',' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%grave>                                */ DEADTRANS( L'`'	,0xE254	,0xE258	,0x0001), // Multikey chain
/*<!M><%apostrophe><%minus><%grave><%minus>                        */ DEADTRANS( L'-'	,0xE258	,0x2962	,0x0000), // '-' ➔ "⥢" LEFTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%apostrophe><%minus><%grave><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE258	,0x294E	,0x0000), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%apostrophe><%minus><%grave><~space>                        */ DEADTRANS( L' '	,0xE258	,0x294E	,0x0000), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%apostrophe><%minus><%minus>                                */ DEADTRANS( L'-'	,0xE254	,0xE25C	,0x0001), // Multikey chain
/*<!M><%apostrophe><%minus><%minus><%apostrophe>                   */ DEADTRANS( L'\''	,0xE25C	,0x21CB	,0x0000), // ''' ➔ "⇋" LEFTWARDS HARPOON OVER RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus><%comma>                        */ DEADTRANS( L','	,0xE25C	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 ',' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus><%grave>                        */ DEADTRANS( L'`'	,0xE25C	,0x2966	,0x0000), // '`' ➔ "⥦" LEFTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB UP
/*<!M><%apostrophe><%minus><%minus><%minus>                        */ DEADTRANS( L'-'	,0xE25C	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 '-' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%minus><0>                             */ DEADTRANS( L'0'	,0xE25C	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 '0' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><%underscore>                           */ DEADTRANS( L'_'	,0xE254	,0x296A	,0x0000), // '_' ➔ "⥪" LEFTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%apostrophe><%minus><0>                                     */ DEADTRANS( L'0'	,0xE254	,0xDCD5	,0x0000), // High surrogate: D83E; U+1F8D5 '0' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%apostrophe><%minus><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE254	,0x21BC	,0x0000), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%apostrophe><%minus><~space>                                */ DEADTRANS( L' '	,0xE254	,0x21BC	,0x0000), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%apostrophe><%parenleft>                                    */ DEADTRANS( L'('	,0xE245	,0xE266	,0x0001), // Multikey chain
/*<!M><%apostrophe><%parenleft><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE266	,0xAB45	,0x0000), // ' ' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><%apostrophe><%parenleft><~space>                            */ DEADTRANS( L' '	,0xE266	,0xAB45	,0x0000), // ' ' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><%aprightsingquotmark>                                       */ DEADTRANS( 0x2019	,0x00A6	,0xE269	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%equal>                               */ DEADTRANS( L'='	,0xE269	,0xE26A	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%equal><%aprightsingquotmark>         */ DEADTRANS( 0x2019	,0xE26A	,0x2AE9	,0x0000), // '’' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><%aprightsingquotmark><%equal><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE26A	,0x2AE8	,0x0000), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%aprightsingquotmark><%equal><~space>                       */ DEADTRANS( L' '	,0xE26A	,0x2AE8	,0x0000), // ' ' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><%aprightsingquotmark><%exclam>                              */ DEADTRANS( L'!'	,0xE269	,0xE26E	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%exclam><%aprightsingquotmark>        */ DEADTRANS( 0x2019	,0xE26E	,0x294D	,0x0000), // '’' ➔ "⥍" UP BARB LEFT DOWN BARB RIGHT HARPOON
/*<!M><%aprightsingquotmark><%exclam><%bar>                        */ DEADTRANS( L'|'	,0xE26E	,0x2960	,0x0000), // '|' ➔ "⥠" UPWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%aprightsingquotmark><%exclam><%exclam>                     */ DEADTRANS( L'!'	,0xE26E	,0x296E	,0x0000), // '!' ➔ "⥮" UPWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%aprightsingquotmark><%exclam><%grave>                      */ DEADTRANS( L'`'	,0xE26E	,0xE272	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%exclam><%grave><%exclam>             */ DEADTRANS( L'!'	,0xE272	,0x2963	,0x0000), // '!' ➔ "⥣" UPWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%aprightsingquotmark><%exclam><%grave><~nbspace>            */ DEADTRANS( 0x00A0	,0xE272	,0x2951	,0x0000), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%aprightsingquotmark><%exclam><%grave><~space>              */ DEADTRANS( L' '	,0xE272	,0x2951	,0x0000), // ' ' ➔ "⥑" UP BARB LEFT DOWN BARB LEFT HARPOON
/*<!M><%aprightsingquotmark><%exclam><~nbspace>                    */ DEADTRANS( 0x00A0	,0xE26E	,0x21BF	,0x0000), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%aprightsingquotmark><%exclam><~space>                      */ DEADTRANS( L' '	,0xE26E	,0x21BF	,0x0000), // ' ' ➔ "↿" UPWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%aprightsingquotmark><%minus>                               */ DEADTRANS( L'-'	,0xE269	,0xE278	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%minus><%aprightsingquotmark>         */ DEADTRANS( 0x2019	,0xE278	,0x294A	,0x0000), // '’' ➔ "⥊" LEFT BARB UP RIGHT BARB DOWN HARPOON
/*<!M><%aprightsingquotmark><%minus><%bar>                         */ DEADTRANS( L'|'	,0xE278	,0x295A	,0x0000), // '|' ➔ "⥚" LEFTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%aprightsingquotmark><%minus><%comma>                       */ DEADTRANS( L','	,0xE278	,0xDCD5	,0x0000), // High surrogate: D83E; U+1F8D5 ',' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><%grave>                       */ DEADTRANS( L'`'	,0xE278	,0xE27C	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%minus><%grave><%minus>               */ DEADTRANS( L'-'	,0xE27C	,0x2962	,0x0000), // '-' ➔ "⥢" LEFTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%aprightsingquotmark><%minus><%grave><~nbspace>             */ DEADTRANS( 0x00A0	,0xE27C	,0x294E	,0x0000), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%aprightsingquotmark><%minus><%grave><~space>               */ DEADTRANS( L' '	,0xE27C	,0x294E	,0x0000), // ' ' ➔ "⥎" LEFT BARB UP RIGHT BARB UP HARPOON
/*<!M><%aprightsingquotmark><%minus><%minus>                       */ DEADTRANS( L'-'	,0xE278	,0xE280	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%minus><%minus><%aprightsingquotmark> */ DEADTRANS( 0x2019	,0xE280	,0x21CB	,0x0000), // '’' ➔ "⇋" LEFTWARDS HARPOON OVER RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><%minus><%comma>               */ DEADTRANS( L','	,0xE280	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 ',' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><%minus><%grave>               */ DEADTRANS( L'`'	,0xE280	,0x2966	,0x0000), // '`' ➔ "⥦" LEFTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB UP
/*<!M><%aprightsingquotmark><%minus><%minus><%minus>               */ DEADTRANS( L'-'	,0xE280	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 '-' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><%minus><0>                    */ DEADTRANS( L'0'	,0xE280	,0xDCD4	,0x0000), // High surrogate: D83E; U+1F8D4 '0' ➔ "🣔" LONG LEFTWARDS HARPOON ABOVE SHORT RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><%underscore>                  */ DEADTRANS( L'_'	,0xE278	,0x296A	,0x0000), // '_' ➔ "⥪" LEFTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%aprightsingquotmark><%minus><0>                            */ DEADTRANS( L'0'	,0xE278	,0xDCD5	,0x0000), // High surrogate: D83E; U+1F8D5 '0' ➔ "🣕" SHORT LEFTWARDS HARPOON ABOVE LONG RIGHTWARDS HARPOON
/*<!M><%aprightsingquotmark><%minus><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE278	,0x21BC	,0x0000), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%aprightsingquotmark><%minus><~space>                       */ DEADTRANS( L' '	,0xE278	,0x21BC	,0x0000), // ' ' ➔ "↼" LEFTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%aprightsingquotmark><%parenleft>                           */ DEADTRANS( L'('	,0xE269	,0xE28A	,0x0001), // Multikey chain
/*<!M><%aprightsingquotmark><%parenleft><~nbspace>                 */ DEADTRANS( 0x00A0	,0xE28A	,0xAB45	,0x0000), // ' ' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><%aprightsingquotmark><%parenleft><~space>                   */ DEADTRANS( L' '	,0xE28A	,0xAB45	,0x0000), // ' ' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><%aprightsingquotmark><n>                                    */ DEADTRANS( L'n'	,0xE269	,0x0149	,0x0000), // 'n' ➔ "ŉ" LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
/*<!M><%asterisk>                                                  */ DEADTRANS( L'*'	,0x00A6	,0xE28E	,0x0001), // Multikey chain
/*<!M><%asterisk><%equal>                                          */ DEADTRANS( L'='	,0xE28E	,0x2A6E	,0x0000), // '=' ➔ "⩮" EQUALS WITH ASTERISK
/*<!M><%backslash>                                                 */ DEADTRANS( L'\\'	,0x00A6	,0xE290	,0x0001), // Multikey chain
/*<!M><%backslash><%backslash>                                     */ DEADTRANS( L'\\'	,0xE290	,0xE291	,0x0001), // Multikey chain
/*<!M><%backslash><%backslash><%slash>                             */ DEADTRANS( L'/'	,0xE291	,0xE292	,0x0001), // Multikey chain
/*<!M><%backslash><%backslash><%slash><%slash>                     */ DEADTRANS( L'/'	,0xE292	,0x2A33	,0x0000), // '/' ➔ "⨳" SMASH PRODUCT
/*<!M><%backslash><%backslash><%slash><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE292	,0x22CB	,0x0000), // ' ' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%backslash><%slash><~space>                     */ DEADTRANS( L' '	,0xE292	,0x22CB	,0x0000), // ' ' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%bar>                                           */ DEADTRANS( L'|'	,0xE290	,0xE296	,0x0001), // Multikey chain
/*<!M><%backslash><%bar><%hash>                                    */ DEADTRANS( L'#'	,0xE296	,0x29E9	,0x0000), // '#' ➔ "⧩" DOWN-POINTING TRIANGLE WITH RIGHT HALF BLACK
/*<!M><%backslash><%greater>                                       */ DEADTRANS( L'>'	,0xE290	,0xE298	,0x0001), // Multikey chain
/*<!M><%backslash><%greater><%equal>                               */ DEADTRANS( L'='	,0xE298	,0x21D8	,0x0000), // '=' ➔ "⇘" SOUTH EAST DOUBLE ARROW
/*<!M><%backslash><%greater><%less>                                */ DEADTRANS( L'<'	,0xE298	,0x2929	,0x0000), // '<' ➔ "⤩" SOUTH EAST ARROW AND SOUTH WEST ARROW
/*<!M><%backslash><%greater><%parenright>                          */ DEADTRANS( L')'	,0xE298	,0xE29B	,0x0001), // Multikey chain
/*<!M><%backslash><%greater><%parenright><%minus>                  */ DEADTRANS( L'-'	,0xE29B	,0x29AA	,0x0000), // '-' ➔ "⦪" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING DOWN AND RIGHT
/*<!M><%backslash><%greater><%slash>                               */ DEADTRANS( L'/'	,0xE298	,0x2928	,0x0000), // '/' ➔ "⤨" NORTH EAST ARROW AND SOUTH EAST ARROW
/*<!M><%backslash><%greater><2>                                    */ DEADTRANS( L'2'	,0xE298	,0x21D8	,0x0000), // '2' ➔ "⇘" SOUTH EAST DOUBLE ARROW
/*<!M><%backslash><%greater><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE298	,0x2198	,0x0000), // ' ' ➔ "↘" SOUTH EAST ARROW
/*<!M><%backslash><%greater><~space>                               */ DEADTRANS( L' '	,0xE298	,0x2198	,0x0000), // ' ' ➔ "↘" SOUTH EAST ARROW
/*<!M><%backslash><%hash>                                          */ DEADTRANS( L'#'	,0xE290	,0xE2A1	,0x0001), // Multikey chain
/*<!M><%backslash><%hash><%bar>                                    */ DEADTRANS( L'|'	,0xE2A1	,0x29E8	,0x0000), // '|' ➔ "⧨" DOWN-POINTING TRIANGLE WITH LEFT HALF BLACK
/*<!M><%backslash><%minus>                                         */ DEADTRANS( L'-'	,0xE290	,0xE2A3	,0x0001), // Multikey chain
/*<!M><%backslash><%minus><%underscore>                            */ DEADTRANS( L'_'	,0xE2A3	,0x29A5	,0x0000), // '_' ➔ "⦥" REVERSED ANGLE WITH UNDERBAR
/*<!M><%backslash><%minus><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE2A3	,0x29F7	,0x0000), // ' ' ➔ "⧷" REVERSE SOLIDUS WITH HORIZONTAL STROKE
/*<!M><%backslash><%minus><~space>                                 */ DEADTRANS( L' '	,0xE2A3	,0x29F7	,0x0000), // ' ' ➔ "⧷" REVERSE SOLIDUS WITH HORIZONTAL STROKE
/*<!M><%backslash><%parenleft>                                     */ DEADTRANS( L'('	,0xE290	,0xE2A7	,0x0001), // Multikey chain
/*<!M><%backslash><%parenleft><%minus>                             */ DEADTRANS( L'-'	,0xE2A7	,0x299B	,0x0000), // '-' ➔ "⦛" MEASURED ANGLE OPENING LEFT
/*<!M><%backslash><%parenleft><%slash>                             */ DEADTRANS( L'/'	,0xE2A7	,0x29A0	,0x0000), // '/' ➔ "⦠" SPHERICAL ANGLE OPENING LEFT
/*<!M><%backslash><%parenright>                                    */ DEADTRANS( L')'	,0xE290	,0xE2AA	,0x0001), // Multikey chain
/*<!M><%backslash><%parenright><%slash>                            */ DEADTRANS( L'/'	,0xE2AA	,0x2222	,0x0000), // '/' ➔ "∢" SPHERICAL ANGLE
/*<!M><%backslash><%slash>                                         */ DEADTRANS( L'/'	,0xE290	,0xE2AC	,0x0001), // Multikey chain
/*<!M><%backslash><%slash><%backslash>                             */ DEADTRANS( L'\\'	,0xE2AC	,0x22CB	,0x0000), // '\' ➔ "⋋" LEFT SEMIDIRECT PRODUCT
/*<!M><%backslash><%slash><%bar>                                   */ DEADTRANS( L'|'	,0xE2AC	,0x22CA	,0x0000), // '|' ➔ "⋊" RIGHT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%backslash><%slash><%greater>                               */ DEADTRANS( L'>'	,0xE2AC	,0x292F	,0x0000), // '>' ➔ "⤯" FALLING DIAGONAL CROSSING NORTH EAST ARROW
/*<!M><%backslash><%slash><%hash>                                  */ DEADTRANS( L'#'	,0xE2AC	,0x29D5	,0x0000), // '#' ➔ "⧕" TIMES WITH RIGHT HALF BLACK
/*<!M><%backslash><%slash><%underscore>                            */ DEADTRANS( L'_'	,0xE2AC	,0xE2B1	,0x0001), // Multikey chain
/*<!M><%backslash><%slash><%underscore><%minus>                    */ DEADTRANS( L'-'	,0xE2B1	,0x2A3A	,0x0000), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore><%plus>                     */ DEADTRANS( L'+'	,0xE2B1	,0x2A39	,0x0000), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore><%underscore>               */ DEADTRANS( L'_'	,0xE2B1	,0x29CB	,0x0000), // '_' ➔ "⧋" TRIANGLE WITH UNDERBAR
/*<!M><%backslash><%slash><%underscore><o>                         */ DEADTRANS( L'o'	,0xE2B1	,0x27C1	,0x0000), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%backslash><%slash><%underscore><s>                         */ DEADTRANS( L's'	,0xE2B1	,0x29CC	,0x0000), // 's' ➔ "⧌" S IN TRIANGLE
/*<!M><%backslash><%slash><%underscore><x>                         */ DEADTRANS( L'x'	,0xE2B1	,0x2A3B	,0x0000), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><%backslash><%slash><%underscore><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE2B1	,0x2A32	,0x0000), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%backslash><%slash><%underscore><~space>                    */ DEADTRANS( L' '	,0xE2B1	,0x2A32	,0x0000), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%backslash><%slash><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE2AC	,0x292C	,0x0000), // ' ' ➔ "⤬" FALLING DIAGONAL CROSSING RISING DIAGONAL
/*<!M><%backslash><%slash><~space>                                 */ DEADTRANS( L' '	,0xE2AC	,0x292C	,0x0000), // ' ' ➔ "⤬" FALLING DIAGONAL CROSSING RISING DIAGONAL
/*<!M><%backslash><%underscore>                                    */ DEADTRANS( L'_'	,0xE290	,0xE2BC	,0x0001), // Multikey chain
/*<!M><%backslash><%underscore><%bar>                              */ DEADTRANS( L'|'	,0xE2BC	,0x25F9	,0x0000), // '|' ➔ "◹" UPPER RIGHT TRIANGLE
/*<!M><%backslash><%underscore><%hash>                             */ DEADTRANS( L'#'	,0xE2BC	,0x25E5	,0x0000), // '#' ➔ "◥" BLACK UPPER RIGHT TRIANGLE
/*<!M><%backslash><%underscore><%slash>                            */ DEADTRANS( L'/'	,0xE2BC	,0x2A32	,0x0000), // '/' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%bar>                                                       */ DEADTRANS( L'|'	,0x00A6	,0xE2C0	,0x0001), // Multikey chain
/*<!M><%bar><%apostrophe>                                          */ DEADTRANS( L'\''	,0xE2C0	,0xE2C1	,0x0001), // Multikey chain
/*<!M><%bar><%apostrophe><%exclam>                                 */ DEADTRANS( L'!'	,0xE2C1	,0x2958	,0x0000), // '!' ➔ "⥘" UPWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%bar><%apostrophe><%minus>                                  */ DEADTRANS( L'-'	,0xE2C1	,0x2952	,0x0000), // '-' ➔ "⥒" LEFTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%bar><%aprightsingquotmark>                                 */ DEADTRANS( 0x2019	,0xE2C0	,0xE2C4	,0x0001), // Multikey chain
/*<!M><%bar><%aprightsingquotmark><%exclam>                        */ DEADTRANS( L'!'	,0xE2C4	,0x2958	,0x0000), // '!' ➔ "⥘" UPWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%bar><%aprightsingquotmark><%minus>                         */ DEADTRANS( L'-'	,0xE2C4	,0x2952	,0x0000), // '-' ➔ "⥒" LEFTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%bar><%backslash>                                           */ DEADTRANS( L'\\'	,0xE2C0	,0xE2C7	,0x0001), // Multikey chain
/*<!M><%bar><%backslash><%slash>                                   */ DEADTRANS( L'/'	,0xE2C7	,0xE2C8	,0x0001), // Multikey chain
/*<!M><%bar><%backslash><%slash><%bar>                             */ DEADTRANS( L'|'	,0xE2C8	,0x22C8	,0x0000), // '|' ➔ "⋈" BOWTIE
/*<!M><%bar><%backslash><%slash><%bracketleft>                     */ DEADTRANS( L'['	,0xE2C8	,0x27D6	,0x0000), // '[' ➔ "⟖" RIGHT OUTER JOIN
/*<!M><%bar><%backslash><%slash><%hash>                            */ DEADTRANS( L'#'	,0xE2C8	,0x29D2	,0x0000), // '#' ➔ "⧒" BOWTIE WITH RIGHT HALF BLACK
/*<!M><%bar><%backslash><%slash><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE2C8	,0x22C9	,0x0000), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%backslash><%slash><~space>                           */ DEADTRANS( L' '	,0xE2C8	,0x22C9	,0x0000), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%backslash><%underscore>                              */ DEADTRANS( L'_'	,0xE2C7	,0x25FA	,0x0000), // '_' ➔ "◺" LOWER LEFT TRIANGLE
/*<!M><%bar><%backslash><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE2C7	,0x2AEE	,0x0000), // ' ' ➔ "⫮" DOES NOT DIVIDE WITH REVERSED NEGATION SLASH
/*<!M><%bar><%backslash><~space>                                   */ DEADTRANS( L' '	,0xE2C7	,0x2AEE	,0x0000), // ' ' ➔ "⫮" DOES NOT DIVIDE WITH REVERSED NEGATION SLASH
/*<!M><%bar><%bar>                                                 */ DEADTRANS( L'|'	,0xE2C0	,0xE2D1	,0x0001), // Multikey chain
/*<!M><%bar><%bar><%bar>                                           */ DEADTRANS( L'|'	,0xE2D1	,0xE2D2	,0x0001), // Multikey chain
/*<!M><%bar><%bar><%bar><%minus>                                   */ DEADTRANS( L'-'	,0xE2D2	,0x2AF5	,0x0000), // '-' ➔ "⫵" TRIPLE VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><%bar><%bar><%equal>                                         */ DEADTRANS( L'='	,0xE2D1	,0xE2D4	,0x0001), // Multikey chain
/*<!M><%bar><%bar><%equal><%slash>                                 */ DEADTRANS( L'/'	,0xE2D4	,0x22AF	,0x0000), // '/' ➔ "⊯" NEGATED DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar><%equal><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE2D4	,0x22AB	,0x0000), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar><%equal><~space>                                 */ DEADTRANS( L' '	,0xE2D4	,0x22AB	,0x0000), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><%bar><%bar><%greater>                                       */ DEADTRANS( L'>'	,0xE2D1	,0x29D0	,0x0000), // '>' ➔ "⧐" VERTICAL BAR BESIDE RIGHT TRIANGLE
/*<!M><%bar><%bar><%minus>                                         */ DEADTRANS( L'-'	,0xE2D1	,0xE2D9	,0x0001), // Multikey chain
/*<!M><%bar><%bar><%minus><%slash>                                 */ DEADTRANS( L'/'	,0xE2D9	,0x22AE	,0x0000), // '/' ➔ "⊮" DOES NOT FORCE
/*<!M><%bar><%bar><%minus><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE2D9	,0x2AF2	,0x0000), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%bar><%minus><~space>                                 */ DEADTRANS( L' '	,0xE2D9	,0x2AF2	,0x0000), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%bar><%slash>                                         */ DEADTRANS( L'/'	,0xE2D1	,0x2226	,0x0000), // '/' ➔ "∦" NOT PARALLEL TO
/*<!M><%bar><%bar><%tilde>                                         */ DEADTRANS( L'~'	,0xE2D1	,0x2AF3	,0x0000), // '~' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%bar><%equal>                                               */ DEADTRANS( L'='	,0xE2C0	,0xE2DF	,0x0001), // Multikey chain
/*<!M><%bar><%equal><%bar>                                         */ DEADTRANS( L'|'	,0xE2DF	,0x29E6	,0x0000), // '|' ➔ "⧦" GLEICH STARK
/*<!M><%bar><%equal><%equal>                                       */ DEADTRANS( L'='	,0xE2DF	,0xE2E1	,0x0001), // Multikey chain
/*<!M><%bar><%equal><%equal><%greater>                             */ DEADTRANS( L'>'	,0xE2E1	,0x27FE	,0x0000), // '>' ➔ "⟾" LONG RIGHTWARDS DOUBLE ARROW FROM BAR
/*<!M><%bar><%equal><%equal><%slash>                               */ DEADTRANS( L'/'	,0xE2E1	,0x22AD	,0x0000), // '/' ➔ "⊭" NOT TRUE
/*<!M><%bar><%equal><%equal><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE2E1	,0x22A8	,0x0000), // ' ' ➔ "⊨" TRUE
/*<!M><%bar><%equal><%equal><~space>                               */ DEADTRANS( L' '	,0xE2E1	,0x22A8	,0x0000), // ' ' ➔ "⊨" TRUE
/*<!M><%bar><%equal><%greater>                                     */ DEADTRANS( L'>'	,0xE2DF	,0x2907	,0x0000), // '>' ➔ "⤇" RIGHTWARDS DOUBLE ARROW FROM BAR
/*<!M><%bar><%equal><%minus>                                       */ DEADTRANS( L'-'	,0xE2DF	,0x2AE2	,0x0000), // '-' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><%bar><%equal><%slash>                                       */ DEADTRANS( L'/'	,0xE2DF	,0x22AD	,0x0000), // '/' ➔ "⊭" NOT TRUE
/*<!M><%bar><%equal><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE2DF	,0x22A7	,0x0000), // ' ' ➔ "⊧" MODELS
/*<!M><%bar><%equal><~space>                                       */ DEADTRANS( L' '	,0xE2DF	,0x22A7	,0x0000), // ' ' ➔ "⊧" MODELS
/*<!M><%bar><%exclam>                                              */ DEADTRANS( L'!'	,0xE2C0	,0xE2EB	,0x0001), // Multikey chain
/*<!M><%bar><%exclam><%apostrophe>                                 */ DEADTRANS( L'\''	,0xE2EB	,0x295D	,0x0000), // ''' ➔ "⥝" DOWNWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%bar><%exclam><%aprightsingquotmark>                        */ DEADTRANS( 0x2019	,0xE2EB	,0x295D	,0x0000), // '’' ➔ "⥝" DOWNWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%bar><%exclam><%grave>                                      */ DEADTRANS( L'`'	,0xE2EB	,0x2961	,0x0000), // '`' ➔ "⥡" DOWNWARDS HARPOON WITH BARB LEFT FROM BAR
/*<!M><%bar><%exclam><%greater>                                    */ DEADTRANS( L'>'	,0xE2EB	,0x21A7	,0x0000), // '>' ➔ "↧" DOWNWARDS ARROW FROM BAR
/*<!M><%bar><%exclam><o>                                           */ DEADTRANS( L'o'	,0xE2EB	,0x2AF1	,0x0000), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><%bar><%grave>                                               */ DEADTRANS( L'`'	,0xE2C0	,0xE2F1	,0x0001), // Multikey chain
/*<!M><%bar><%grave><%exclam>                                      */ DEADTRANS( L'!'	,0xE2F1	,0x2954	,0x0000), // '!' ➔ "⥔" UPWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%bar><%grave><%minus>                                       */ DEADTRANS( L'-'	,0xE2F1	,0x2956	,0x0000), // '-' ➔ "⥖" LEFTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%bar><%greater>                                             */ DEADTRANS( L'>'	,0xE2C0	,0xE2F4	,0x0001), // Multikey chain
/*<!M><%bar><%greater><%less>                                      */ DEADTRANS( L'<'	,0xE2F4	,0x29CE	,0x0000), // '<' ➔ "⧎" RIGHT TRIANGLE ABOVE LEFT TRIANGLE
/*<!M><%bar><%greater><%slash>                                     */ DEADTRANS( L'/'	,0xE2F4	,0xE2F6	,0x0001), // Multikey chain
/*<!M><%bar><%greater><%slash><%underscore>                        */ DEADTRANS( L'_'	,0xE2F6	,0x22ED	,0x0000), // '_' ➔ "⋭" DOES NOT CONTAIN AS NORMAL SUBGROUP OR EQUAL
/*<!M><%bar><%greater><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE2F6	,0x22EB	,0x0000), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%bar><%greater><%slash><~space>                             */ DEADTRANS( L' '	,0xE2F6	,0x22EB	,0x0000), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%bar><%greater><%underscore>                                */ DEADTRANS( L'_'	,0xE2F4	,0xE2FA	,0x0001), // Multikey chain
/*<!M><%bar><%greater><%underscore><%slash>                        */ DEADTRANS( L'/'	,0xE2FA	,0x22ED	,0x0000), // '/' ➔ "⋭" DOES NOT CONTAIN AS NORMAL SUBGROUP OR EQUAL
/*<!M><%bar><%greater><%underscore><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE2FA	,0x22B5	,0x0000), // ' ' ➔ "⊵" CONTAINS AS NORMAL SUBGROUP OR EQUAL TO
/*<!M><%bar><%greater><%underscore><~space>                        */ DEADTRANS( L' '	,0xE2FA	,0x22B5	,0x0000), // ' ' ➔ "⊵" CONTAINS AS NORMAL SUBGROUP OR EQUAL TO
/*<!M><%bar><%greater><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE2F4	,0x22B3	,0x0000), // ' ' ➔ "⊳" CONTAINS AS NORMAL SUBGROUP
/*<!M><%bar><%greater><~space>                                     */ DEADTRANS( L' '	,0xE2F4	,0x22B3	,0x0000), // ' ' ➔ "⊳" CONTAINS AS NORMAL SUBGROUP
/*<!M><%bar><%hash>                                                */ DEADTRANS( L'#'	,0xE2C0	,0xE300	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%backslash>                                    */ DEADTRANS( L'\\'	,0xE300	,0xE301	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%backslash><%slash>                            */ DEADTRANS( L'/'	,0xE301	,0xE302	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%backslash><%slash><%bar>                      */ DEADTRANS( L'|'	,0xE302	,0x29D1	,0x0000), // '|' ➔ "⧑" BOWTIE WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash><%slash><%hash>                     */ DEADTRANS( L'#'	,0xE302	,0x29D3	,0x0000), // '#' ➔ "⧓" BLACK BOWTIE
/*<!M><%bar><%hash><%backslash><%slash><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE302	,0x29D4	,0x0000), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash><%slash><~space>                    */ DEADTRANS( L' '	,0xE302	,0x29D4	,0x0000), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%backslash><%underscore>                       */ DEADTRANS( L'_'	,0xE301	,0x25E3	,0x0000), // '_' ➔ "◣" BLACK LOWER LEFT TRIANGLE
/*<!M><%bar><%hash><%slash>                                        */ DEADTRANS( L'/'	,0xE300	,0xE308	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%slash><%backslash>                            */ DEADTRANS( L'\\'	,0xE308	,0xE309	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%slash><%backslash><%bar>                      */ DEADTRANS( L'|'	,0xE309	,0x29D1	,0x0000), // '|' ➔ "⧑" BOWTIE WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash><%backslash><%hash>                     */ DEADTRANS( L'#'	,0xE309	,0x29D3	,0x0000), // '#' ➔ "⧓" BLACK BOWTIE
/*<!M><%bar><%hash><%slash><%backslash><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE309	,0x29D4	,0x0000), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash><%backslash><~space>                    */ DEADTRANS( L' '	,0xE309	,0x29D4	,0x0000), // ' ' ➔ "⧔" TIMES WITH LEFT HALF BLACK
/*<!M><%bar><%hash><%slash><%underscore>                           */ DEADTRANS( L'_'	,0xE308	,0x25E4	,0x0000), // '_' ➔ "◤" BLACK UPPER LEFT TRIANGLE
/*<!M><%bar><%hash><%underscore>                                   */ DEADTRANS( L'_'	,0xE300	,0xE30F	,0x0001), // Multikey chain
/*<!M><%bar><%hash><%underscore><%backslash>                       */ DEADTRANS( L'\\'	,0xE30F	,0x25E3	,0x0000), // '\' ➔ "◣" BLACK LOWER LEFT TRIANGLE
/*<!M><%bar><%hash><%underscore><%slash>                           */ DEADTRANS( L'/'	,0xE30F	,0x25E4	,0x0000), // '/' ➔ "◤" BLACK UPPER LEFT TRIANGLE
/*<!M><%bar><%less>                                                */ DEADTRANS( L'<'	,0xE2C0	,0xE312	,0x0001), // Multikey chain
/*<!M><%bar><%less><%exclam>                                       */ DEADTRANS( L'!'	,0xE312	,0x2912	,0x0000), // '!' ➔ "⤒" UPWARDS ARROW TO BAR
/*<!M><%bar><%less><%minus>                                        */ DEADTRANS( L'-'	,0xE312	,0x21E4	,0x0000), // '-' ➔ "⇤" LEFTWARDS ARROW TO BAR
/*<!M><%bar><%minus>                                               */ DEADTRANS( L'-'	,0xE2C0	,0xE315	,0x0001), // Multikey chain
/*<!M><%bar><%minus><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE315	,0x295F	,0x0000), // ''' ➔ "⥟" RIGHTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%bar><%minus><%aprightsingquotmark>                         */ DEADTRANS( 0x2019	,0xE315	,0x295F	,0x0000), // '’' ➔ "⥟" RIGHTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%bar><%minus><%bar>                                         */ DEADTRANS( L'|'	,0xE315	,0xE318	,0x0001), // Multikey chain
/*<!M><%bar><%minus><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE318	,0x2AE6	,0x0000), // '-' ➔ "⫦" LONG DASH FROM LEFT MEMBER OF DOUBLE VERTICAL
/*<!M><%bar><%minus><%bar><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE318	,0x2AF2	,0x0000), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%minus><%bar><~space>                                 */ DEADTRANS( L' '	,0xE318	,0x2AF2	,0x0000), // ' ' ➔ "⫲" PARALLEL WITH HORIZONTAL STROKE
/*<!M><%bar><%minus><%equal>                                       */ DEADTRANS( L'='	,0xE315	,0x2AE2	,0x0000), // '=' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><%bar><%minus><%grave>                                       */ DEADTRANS( L'`'	,0xE315	,0x295B	,0x0000), // '`' ➔ "⥛" RIGHTWARDS HARPOON WITH BARB UP FROM BAR
/*<!M><%bar><%minus><%greater>                                     */ DEADTRANS( L'>'	,0xE315	,0xE31E	,0x0001), // Multikey chain
/*<!M><%bar><%minus><%greater><%greater>                           */ DEADTRANS( L'>'	,0xE31E	,0x2905	,0x0000), // '>' ➔ "⤅" RIGHTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><%bar><%minus><%greater><%less>                              */ DEADTRANS( L'<'	,0xE31E	,0x2920	,0x0000), // '<' ➔ "⤠" RIGHTWARDS ARROW FROM BAR TO BLACK DIAMOND
/*<!M><%bar><%minus><%greater><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE31E	,0x21A6	,0x0000), // ' ' ➔ "↦" RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%greater><~space>                             */ DEADTRANS( L' '	,0xE31E	,0x21A6	,0x0000), // ' ' ➔ "↦" RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%minus>                                       */ DEADTRANS( L'-'	,0xE315	,0xE323	,0x0001), // Multikey chain
/*<!M><%bar><%minus><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE323	,0x27FC	,0x0000), // '>' ➔ "⟼" LONG RIGHTWARDS ARROW FROM BAR
/*<!M><%bar><%minus><%minus><%minus>                               */ DEADTRANS( L'-'	,0xE323	,0xE325	,0x0001), // Multikey chain
/*<!M><%bar><%minus><%minus><%minus><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE325	,0x27DD	,0x0000), // ' ' ➔ "⟝" LONG RIGHT TACK
/*<!M><%bar><%minus><%minus><%minus><~space>                       */ DEADTRANS( L' '	,0xE325	,0x27DD	,0x0000), // ' ' ➔ "⟝" LONG RIGHT TACK
/*<!M><%bar><%minus><%minus><%slash>                               */ DEADTRANS( L'/'	,0xE323	,0x22AC	,0x0000), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><%bar><%minus><%minus><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE323	,0x22A2	,0x0000), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><%bar><%minus><%minus><~space>                               */ DEADTRANS( L' '	,0xE323	,0x22A2	,0x0000), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><%bar><%minus><%slash>                                       */ DEADTRANS( L'/'	,0xE315	,0x22AC	,0x0000), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><%bar><%minus><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE315	,0x22A6	,0x0000), // ' ' ➔ "⊦" ASSERTION
/*<!M><%bar><%minus><~space>                                       */ DEADTRANS( L' '	,0xE315	,0x22A6	,0x0000), // ' ' ➔ "⊦" ASSERTION
/*<!M><%bar><%parenleft>                                           */ DEADTRANS( L'('	,0xE2C0	,0x29AD	,0x0000), // '(' ➔ "⦭" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING LEFT AND UP
/*<!M><%bar><%parenright>                                          */ DEADTRANS( L')'	,0xE2C0	,0xE32F	,0x0001), // Multikey chain
/*<!M><%bar><%parenright><%backslash>                              */ DEADTRANS( L'\\'	,0xE32F	,0x29AE	,0x0000), // '\' ➔ "⦮" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING RIGHT AND DOWN
/*<!M><%bar><%parenright><%slash>                                  */ DEADTRANS( L'/'	,0xE32F	,0x2ADC	,0x0000), // '/' ➔ "⫝̸" FORKING
/*<!M><%bar><%period>                                              */ DEADTRANS( L'.'	,0xE2C0	,0xE332	,0x0001), // Multikey chain
/*<!M><%bar><%period><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE332	,0x2999	,0x0000), // ' ' ➔ "⦙" DOTTED FENCE
/*<!M><%bar><%period><~space>                                      */ DEADTRANS( L' '	,0xE332	,0x2999	,0x0000), // ' ' ➔ "⦙" DOTTED FENCE
/*<!M><%bar><%slash>                                               */ DEADTRANS( L'/'	,0xE2C0	,0xE335	,0x0001), // Multikey chain
/*<!M><%bar><%slash><%backslash>                                   */ DEADTRANS( L'\\'	,0xE335	,0xE336	,0x0001), // Multikey chain
/*<!M><%bar><%slash><%backslash><%bar>                             */ DEADTRANS( L'|'	,0xE336	,0x22C8	,0x0000), // '|' ➔ "⋈" BOWTIE
/*<!M><%bar><%slash><%backslash><%bracketleft>                     */ DEADTRANS( L'['	,0xE336	,0x27D6	,0x0000), // '[' ➔ "⟖" RIGHT OUTER JOIN
/*<!M><%bar><%slash><%backslash><%hash>                            */ DEADTRANS( L'#'	,0xE336	,0x29D2	,0x0000), // '#' ➔ "⧒" BOWTIE WITH RIGHT HALF BLACK
/*<!M><%bar><%slash><%backslash><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE336	,0x22C9	,0x0000), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%slash><%backslash><~space>                           */ DEADTRANS( L' '	,0xE336	,0x22C9	,0x0000), // ' ' ➔ "⋉" LEFT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%bar><%slash><%underscore>                                  */ DEADTRANS( L'_'	,0xE335	,0x27C0	,0x0000), // '_' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><%bar><%slash><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE335	,0x2224	,0x0000), // ' ' ➔ "∤" DOES NOT DIVIDE
/*<!M><%bar><%slash><~space>                                       */ DEADTRANS( L' '	,0xE335	,0x2224	,0x0000), // ' ' ➔ "∤" DOES NOT DIVIDE
/*<!M><%bar><%tilde>                                               */ DEADTRANS( L'~'	,0xE2C0	,0xE33F	,0x0001), // Multikey chain
/*<!M><%bar><%tilde><%bar>                                         */ DEADTRANS( L'|'	,0xE33F	,0x2AF3	,0x0000), // '|' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%bar><%underscore>                                          */ DEADTRANS( L'_'	,0xE2C0	,0xE341	,0x0001), // Multikey chain
/*<!M><%bar><%underscore><%backslash>                              */ DEADTRANS( L'\\'	,0xE341	,0x25FA	,0x0000), // '\' ➔ "◺" LOWER LEFT TRIANGLE
/*<!M><%bar><%underscore><%slash>                                  */ DEADTRANS( L'/'	,0xE341	,0x25F8	,0x0000), // '/' ➔ "◸" UPPER LEFT TRIANGLE
/*<!M><%bar><%underscore><%underscore>                             */ DEADTRANS( L'_'	,0xE341	,0x23E2	,0x0000), // '_' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%bar><%underscore><s>                                       */ DEADTRANS( L's'	,0xE341	,0x2AE1	,0x0000), // 's' ➔ "⫡" PERPENDICULAR WITH S
/*<!M><%bar><%underscore><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE341	,0x27C2	,0x0000), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%bar><%underscore><~space>                                  */ DEADTRANS( L' '	,0xE341	,0x27C2	,0x0000), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%bar><p>                                                    */ DEADTRANS( L'p'	,0xE2C0	,0x204B	,0x0000), // 'p' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%bar><P>                                                    */ DEADTRANS( L'P'	,0xE2C0	,0x204B	,0x0000), // 'P' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%bar><w>                                                    */ DEADTRANS( L'w'	,0xE2C0	,0x299A	,0x0000), // 'w' ➔ "⦚" VERTICAL ZIGZAG LINE
/*<!M><%bracketleft>                                               */ DEADTRANS( L'['	,0x00A6	,0xE34B	,0x0001), // Multikey chain
/*<!M><%bracketleft><%apostrophe>                                  */ DEADTRANS( L'\''	,0xE34B	,0xE34C	,0x0001), // Multikey chain
/*<!M><%bracketleft><%apostrophe><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE34C	,0x298F	,0x0000), // ' ' ➔ "⦏" LEFT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketleft><%apostrophe><~space>                          */ DEADTRANS( L' '	,0xE34C	,0x298F	,0x0000), // ' ' ➔ "⦏" LEFT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketleft><%asterisk>                                    */ DEADTRANS( L'*'	,0xE34B	,0x29C6	,0x0000), // '*' ➔ "⧆" SQUARED ASTERISK
/*<!M><%bracketleft><%backslash>                                   */ DEADTRANS( L'\\'	,0xE34B	,0xE350	,0x0001), // Multikey chain
/*<!M><%bracketleft><%backslash><%bracketright>                    */ DEADTRANS( L']'	,0xE350	,0x29C5	,0x0000), // ']' ➔ "⧅" SQUARED FALLING DIAGONAL SLASH
/*<!M><%bracketleft><%backslash><%colon>                           */ DEADTRANS( L':'	,0xE350	,0xE352	,0x0001), // Multikey chain
/*<!M><%bracketleft><%backslash><%colon><%bracketright>            */ DEADTRANS( L']'	,0xE352	,0x274F	,0x0000), // ']' ➔ "❏" LOWER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%backslash><%minus>                           */ DEADTRANS( L'-'	,0xE350	,0xE354	,0x0001), // Multikey chain
/*<!M><%bracketleft><%backslash><%minus><%bracketright>            */ DEADTRANS( L']'	,0xE354	,0x2751	,0x0000), // ']' ➔ "❑" LOWER RIGHT SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%bar>                                         */ DEADTRANS( L'|'	,0xE34B	,0xE356	,0x0001), // Multikey chain
/*<!M><%bracketleft><%bar><%bracketright>                          */ DEADTRANS( L']'	,0xE356	,0x25EB	,0x0000), // ']' ➔ "◫" WHITE SQUARE WITH VERTICAL BISECTING LINE
/*<!M><%bracketleft><%bar><%hash>                                  */ DEADTRANS( L'#'	,0xE356	,0x25E8	,0x0000), // '#' ➔ "◨" SQUARE WITH RIGHT HALF BLACK
/*<!M><%bracketleft><%bracketleft>                                 */ DEADTRANS( L'['	,0xE34B	,0xE359	,0x0001), // Multikey chain
/*<!M><%bracketleft><%bracketleft><%bracketright>                  */ DEADTRANS( L']'	,0xE359	,0x29E0	,0x0000), // ']' ➔ "⧠" SQUARE WITH CONTOURED OUTLINE
/*<!M><%bracketleft><%bracketleft><w>                              */ DEADTRANS( L'w'	,0xE359	,0x29DA	,0x0000), // 'w' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><%bracketleft><%bracketright>                                */ DEADTRANS( L']'	,0xE34B	,0xE35C	,0x0001), // Multikey chain
/*<!M><%bracketleft><%bracketright><%bar>                          */ DEADTRANS( L'|'	,0xE35C	,0x25AF	,0x0000), // '|' ➔ "▯" WHITE VERTICAL RECTANGLE
/*<!M><%bracketleft><%bracketright><%minus>                        */ DEADTRANS( L'-'	,0xE35C	,0x27E5	,0x0000), // '-' ➔ "⟥" WHITE SQUARE WITH RIGHTWARDS TICK
/*<!M><%bracketleft><%bracketright><0>                             */ DEADTRANS( L'0'	,0xE35C	,0x25FD	,0x0000), // '0' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><%bracketleft><%bracketright><1>                             */ DEADTRANS( L'1'	,0xE35C	,0x25FB	,0x0000), // '1' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><%bracketleft><%bracketright><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE35C	,0x25A1	,0x0000), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketleft><%bracketright><~space>                        */ DEADTRANS( L' '	,0xE35C	,0x25A1	,0x0000), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketleft><%circum>                                      */ DEADTRANS( L'^'	,0xE34B	,0x2308	,0x0000), // '^' ➔ "⌈" LEFT CEILING
/*<!M><%bracketleft><%grave>                                       */ DEADTRANS( L'`'	,0xE34B	,0x298D	,0x0000), // '`' ➔ "⦍" LEFT SQUARE BRACKET WITH TICK IN TOP CORNER
/*<!M><%bracketleft><%hash>                                        */ DEADTRANS( L'#'	,0xE34B	,0xE365	,0x0001), // Multikey chain
/*<!M><%bracketleft><%hash><%bar>                                  */ DEADTRANS( L'|'	,0xE365	,0x25E7	,0x0000), // '|' ➔ "◧" SQUARE WITH LEFT HALF BLACK
/*<!M><%bracketleft><%hash><%bracketright>                         */ DEADTRANS( L']'	,0xE365	,0xE367	,0x0001), // Multikey chain
/*<!M><%bracketleft><%hash><%bracketright><%bar>                   */ DEADTRANS( L'|'	,0xE367	,0x25AE	,0x0000), // '|' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><%bracketleft><%hash><%bracketright><0>                      */ DEADTRANS( L'0'	,0xE367	,0x25FE	,0x0000), // '0' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><%bracketleft><%hash><%bracketright><1>                      */ DEADTRANS( L'1'	,0xE367	,0x25FC	,0x0000), // '1' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><%bracketleft><%hash><%bracketright><~nbspace>               */ DEADTRANS( 0x00A0	,0xE367	,0x25A0	,0x0000), // ' ' ➔ "■" BLACK SQUARE
/*<!M><%bracketleft><%hash><%bracketright><~space>                 */ DEADTRANS( L' '	,0xE367	,0x25A0	,0x0000), // ' ' ➔ "■" BLACK SQUARE
/*<!M><%bracketleft><%hash><%slash>                                */ DEADTRANS( L'/'	,0xE365	,0x25E9	,0x0000), // '/' ➔ "◩" SQUARE WITH UPPER LEFT DIAGONAL HALF BLACK
/*<!M><%bracketleft><%minus>                                       */ DEADTRANS( L'-'	,0xE34B	,0xE36E	,0x0001), // Multikey chain
/*<!M><%bracketleft><%minus><%backslash>                           */ DEADTRANS( L'\\'	,0xE36E	,0xE36F	,0x0001), // Multikey chain
/*<!M><%bracketleft><%minus><%backslash><%bracketright>            */ DEADTRANS( L']'	,0xE36F	,0x29E0	,0x0000), // ']' ➔ "⧠" SQUARE WITH CONTOURED OUTLINE
/*<!M><%bracketleft><%minus><%bracketright>                        */ DEADTRANS( L']'	,0xE36E	,0x229F	,0x0000), // ']' ➔ "⊟" SQUARED MINUS
/*<!M><%bracketleft><%parenleft>                                   */ DEADTRANS( L'('	,0xE34B	,0x2997	,0x0000), // '(' ➔ "⦗" LEFT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketleft><%period>                                      */ DEADTRANS( L'.'	,0xE34B	,0x22A1	,0x0000), // '.' ➔ "⊡" SQUARED DOT OPERATOR
/*<!M><%bracketleft><%plus>                                        */ DEADTRANS( L'+'	,0xE34B	,0x229E	,0x0000), // '+' ➔ "⊞" SQUARED PLUS
/*<!M><%bracketleft><%slash>                                       */ DEADTRANS( L'/'	,0xE34B	,0xE375	,0x0001), // Multikey chain
/*<!M><%bracketleft><%slash><%bracketright>                        */ DEADTRANS( L']'	,0xE375	,0x29C4	,0x0000), // ']' ➔ "⧄" SQUARED RISING DIAGONAL SLASH
/*<!M><%bracketleft><%slash><%colon>                               */ DEADTRANS( L':'	,0xE375	,0xE377	,0x0001), // Multikey chain
/*<!M><%bracketleft><%slash><%colon><%bracketright>                */ DEADTRANS( L']'	,0xE377	,0x2750	,0x0000), // ']' ➔ "❐" UPPER RIGHT DROP-SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%slash><%hash>                                */ DEADTRANS( L'#'	,0xE375	,0x25EA	,0x0000), // '#' ➔ "◪" SQUARE WITH LOWER RIGHT DIAGONAL HALF BLACK
/*<!M><%bracketleft><%slash><%minus>                               */ DEADTRANS( L'-'	,0xE375	,0xE37A	,0x0001), // Multikey chain
/*<!M><%bracketleft><%slash><%minus><%bracketright>                */ DEADTRANS( L']'	,0xE37A	,0x2752	,0x0000), // ']' ➔ "❒" UPPER RIGHT SHADOWED WHITE SQUARE
/*<!M><%bracketleft><%underscore>                                  */ DEADTRANS( L'_'	,0xE34B	,0xE37C	,0x0001), // Multikey chain
/*<!M><%bracketleft><%underscore><%bracketright>                   */ DEADTRANS( L']'	,0xE37C	,0x2610	,0x0000), // ']' ➔ "☐" BALLOT BOX
/*<!M><%bracketleft><%underscore><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE37C	,0x230A	,0x0000), // ' ' ➔ "⌊" LEFT FLOOR
/*<!M><%bracketleft><%underscore><~space>                          */ DEADTRANS( L' '	,0xE37C	,0x230A	,0x0000), // ' ' ➔ "⌊" LEFT FLOOR
/*<!M><%bracketleft><V>                                            */ DEADTRANS( L'V'	,0xE34B	,0xE380	,0x0001), // Multikey chain
/*<!M><%bracketleft><v>                                            */ DEADTRANS( L'v'	,0xE34B	,0xE381	,0x0001), // Multikey chain
/*<!M><%bracketleft><V><%bracketright>                             */ DEADTRANS( L']'	,0xE380	,0x2611	,0x0000), // ']' ➔ "☑" BALLOT BOX WITH CHECK emoji
/*<!M><%bracketleft><v><%bracketright>                             */ DEADTRANS( L']'	,0xE381	,0x27CF	,0x0000), // ']' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft><v><%percent>                                  */ DEADTRANS( L'%'	,0xE381	,0x27CE	,0x0000), // '%' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><%bracketleft><v><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE381	,0x27CF	,0x0000), // ' ' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft><v><~space>                                    */ DEADTRANS( L' '	,0xE381	,0x27CF	,0x0000), // ' ' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><%bracketleft><w>                                            */ DEADTRANS( L'w'	,0xE34B	,0x29D8	,0x0000), // 'w' ➔ "⧘" LEFT WIGGLY FENCE
/*<!M><%bracketleft><X>                                            */ DEADTRANS( L'X'	,0xE34B	,0xE389	,0x0001), // Multikey chain
/*<!M><%bracketleft><x>                                            */ DEADTRANS( L'x'	,0xE34B	,0x22A0	,0x0000), // 'x' ➔ "⊠" SQUARED TIMES
/*<!M><%bracketleft><X><%bracketright>                             */ DEADTRANS( L']'	,0xE389	,0x2612	,0x0000), // ']' ➔ "☒" BALLOT BOX WITH X
/*<!M><%bracketleft><X><L>                                         */ DEADTRANS( L'L'	,0xE389	,0xE38B	,0x0001), // Multikey chain
/*<!M><%bracketleft><X><L><%bracketright>                          */ DEADTRANS( L']'	,0xE38B	,0x2BBD	,0x0000), // ']' ➔ "⮽" BALLOT BOX WITH LIGHT X
/*<!M><%bracketright>                                              */ DEADTRANS( L']'	,0x00A6	,0xE38D	,0x0001), // Multikey chain
/*<!M><%bracketright><%apostrophe>                                 */ DEADTRANS( L'\''	,0xE38D	,0x2990	,0x0000), // ''' ➔ "⦐" RIGHT SQUARE BRACKET WITH TICK IN TOP CORNER
/*<!M><%bracketright><%backslash>                                  */ DEADTRANS( L'\\'	,0xE38D	,0xE38F	,0x0001), // Multikey chain
/*<!M><%bracketright><%backslash><%slash>                          */ DEADTRANS( L'/'	,0xE38F	,0xE390	,0x0001), // Multikey chain
/*<!M><%bracketright><%backslash><%slash><%bar>                    */ DEADTRANS( L'|'	,0xE390	,0x27D5	,0x0000), // '|' ➔ "⟕" LEFT OUTER JOIN
/*<!M><%bracketright><%backslash><%slash><%bracketleft>            */ DEADTRANS( L'['	,0xE390	,0x27D7	,0x0000), // '[' ➔ "⟗" FULL OUTER JOIN
/*<!M><%bracketright><%bracketleft>                                */ DEADTRANS( L'['	,0xE38D	,0xE393	,0x0001), // Multikey chain
/*<!M><%bracketright><%bracketleft><%bar>                          */ DEADTRANS( L'|'	,0xE393	,0x25AF	,0x0000), // '|' ➔ "▯" WHITE VERTICAL RECTANGLE
/*<!M><%bracketright><%bracketleft><%minus>                        */ DEADTRANS( L'-'	,0xE393	,0x27E5	,0x0000), // '-' ➔ "⟥" WHITE SQUARE WITH RIGHTWARDS TICK
/*<!M><%bracketright><%bracketleft><0>                             */ DEADTRANS( L'0'	,0xE393	,0x25FD	,0x0000), // '0' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><%bracketright><%bracketleft><1>                             */ DEADTRANS( L'1'	,0xE393	,0x25FB	,0x0000), // '1' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><%bracketright><%bracketleft><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE393	,0x25A1	,0x0000), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketright><%bracketleft><~space>                        */ DEADTRANS( L' '	,0xE393	,0x25A1	,0x0000), // ' ' ➔ "□" WHITE SQUARE
/*<!M><%bracketright><%bracketright>                               */ DEADTRANS( L']'	,0xE38D	,0xE39A	,0x0001), // Multikey chain
/*<!M><%bracketright><%bracketright><w>                            */ DEADTRANS( L'w'	,0xE39A	,0x29DB	,0x0000), // 'w' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><%bracketright><%circum>                                     */ DEADTRANS( L'^'	,0xE38D	,0x2309	,0x0000), // '^' ➔ "⌉" RIGHT CEILING
/*<!M><%bracketright><%grave>                                      */ DEADTRANS( L'`'	,0xE38D	,0x298E	,0x0000), // '`' ➔ "⦎" RIGHT SQUARE BRACKET WITH TICK IN BOTTOM CORNER
/*<!M><%bracketright><%parenright>                                 */ DEADTRANS( L')'	,0xE38D	,0xE39E	,0x0001), // Multikey chain
/*<!M><%bracketright><%parenright><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE39E	,0x2998	,0x0000), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketright><%parenright><~space>                         */ DEADTRANS( L' '	,0xE39E	,0x2998	,0x0000), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%bracketright><%slash>                                      */ DEADTRANS( L'/'	,0xE38D	,0xE3A1	,0x0001), // Multikey chain
/*<!M><%bracketright><%slash><%backslash>                          */ DEADTRANS( L'\\'	,0xE3A1	,0xE3A2	,0x0001), // Multikey chain
/*<!M><%bracketright><%slash><%backslash><%bar>                    */ DEADTRANS( L'|'	,0xE3A2	,0x27D5	,0x0000), // '|' ➔ "⟕" LEFT OUTER JOIN
/*<!M><%bracketright><%slash><%backslash><%bracketleft>            */ DEADTRANS( L'['	,0xE3A2	,0x27D7	,0x0000), // '[' ➔ "⟗" FULL OUTER JOIN
/*<!M><%bracketright><%underscore>                                 */ DEADTRANS( L'_'	,0xE38D	,0x230B	,0x0000), // '_' ➔ "⌋" RIGHT FLOOR
/*<!M><%bracketright><w>                                           */ DEADTRANS( L'w'	,0xE38D	,0x29D9	,0x0000), // 'w' ➔ "⧙" RIGHT WIGGLY FENCE
/*<!M><%circum>                                                    */ DEADTRANS( L'^'	,0x00A6	,0xE3A7	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand>                                        */ DEADTRANS( L'&'	,0xE3A7	,0xE3A8	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><%braceleft>                            */ DEADTRANS( L'{'	,0xE3A8	,0xE3A9	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><%braceleft><%braceleft>                */ DEADTRANS( L'{'	,0xE3A9	,0xE3AA	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><%braceleft><%braceleft><d>             */ DEADTRANS( L'd'	,0xE3AA	,0xDF89	,0x0000), // High surrogate: D801; U+10789 'd' ➔ "𐞉" MODIFIER LETTER SMALL DZ DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft><%braceleft><t>             */ DEADTRANS( L't'	,0xE3AA	,0xDFAB	,0x0000), // High surrogate: D801; U+107AB 't' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft><d>                         */ DEADTRANS( L'd'	,0xE3A9	,0xDF89	,0x0000), // High surrogate: D801; U+10789 'd' ➔ "𐞉" MODIFIER LETTER SMALL DZ DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceleft><t>                         */ DEADTRANS( L't'	,0xE3A9	,0xDFAB	,0x0000), // High surrogate: D801; U+107AB 't' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><%braceright>                           */ DEADTRANS( L'}'	,0xE3A8	,0xE3AF	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><%braceright><d>                        */ DEADTRANS( L'd'	,0xE3AF	,0xDF88	,0x0000), // High surrogate: D801; U+10788 'd' ➔ "𐞈" MODIFIER LETTER SMALL DZ DIGRAPH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand><%braceright><l>                        */ DEADTRANS( L'l'	,0xE3AF	,0xDF9F	,0x0000), // High surrogate: D801; U+1079F 'l' ➔ "𐞟" MODIFIER LETTER SMALL LEZH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand><%braceright><t>                        */ DEADTRANS( L't'	,0xE3AF	,0xDFAD	,0x0000), // High surrogate: D801; U+107AD 't' ➔ "𐞭" MODIFIER LETTER SMALL TS DIGRAPH WITH RETROFLEX HOOK
/*<!M><%circum><%ampersand><9>                                     */ DEADTRANS( L'9'	,0xE3A8	,0xA770	,0x0000), // '9' ➔ "ꝰ" MODIFIER LETTER US
/*<!M><%circum><%ampersand><A>                                     */ DEADTRANS( L'A'	,0xE3A8	,0xE3B4	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><A><A>                                  */ DEADTRANS( L'A'	,0xE3B4	,0xDF80	,0x0000), // High surrogate: D801; U+10780 'A' ➔ "𐞀" MODIFIER LETTER SMALL CAPITAL AA
/*<!M><%circum><%ampersand><d>                                     */ DEADTRANS( L'd'	,0xE3A8	,0xE3B6	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><d><3>                                  */ DEADTRANS( L'3'	,0xE3B6	,0xDF8A	,0x0000), // High surrogate: D801; U+1078A '3' ➔ "𐞊" MODIFIER LETTER SMALL DEZH DIGRAPH
/*<!M><%circum><%ampersand><d><z>                                  */ DEADTRANS( L'z'	,0xE3B6	,0xDF87	,0x0000), // High surrogate: D801; U+10787 'z' ➔ "𐞇" MODIFIER LETTER SMALL DZ DIGRAPH
/*<!M><%circum><%ampersand><f>                                     */ DEADTRANS( L'f'	,0xE3A8	,0xE3B9	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><f><g>                                  */ DEADTRANS( L'g'	,0xE3B9	,0xDF90	,0x0000), // High surrogate: D801; U+10790 'g' ➔ "𐞐" MODIFIER LETTER SMALL FENG DIGRAPH
/*<!M><%circum><%ampersand><f><n>                                  */ DEADTRANS( L'n'	,0xE3B9	,0xDF90	,0x0000), // High surrogate: D801; U+10790 'n' ➔ "𐞐" MODIFIER LETTER SMALL FENG DIGRAPH
/*<!M><%circum><%ampersand><l>                                     */ DEADTRANS( L'l'	,0xE3A8	,0xE3BC	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><l><3>                                  */ DEADTRANS( L'3'	,0xE3BC	,0xDF9E	,0x0000), // High surrogate: D801; U+1079E '3' ➔ "𐞞" MODIFIER LETTER SMALL LEZH
/*<!M><%circum><%ampersand><l><s>                                  */ DEADTRANS( L's'	,0xE3BC	,0xDF99	,0x0000), // High surrogate: D801; U+10799 's' ➔ "𐞙" MODIFIER LETTER SMALL LS DIGRAPH
/*<!M><%circum><%ampersand><l><z>                                  */ DEADTRANS( L'z'	,0xE3BC	,0xDF9A	,0x0000), // High surrogate: D801; U+1079A 'z' ➔ "𐞚" MODIFIER LETTER SMALL LZ DIGRAPH
/*<!M><%circum><%ampersand><t>                                     */ DEADTRANS( L't'	,0xE3A8	,0xE3C0	,0x0001), // Multikey chain
/*<!M><%circum><%ampersand><t><c>                                  */ DEADTRANS( L'c'	,0xE3C0	,0xDFAB	,0x0000), // High surrogate: D801; U+107AB 'c' ➔ "𐞫" MODIFIER LETTER SMALL TC DIGRAPH WITH CURL
/*<!M><%circum><%ampersand><t><e>                                  */ DEADTRANS( L'e'	,0xE3C0	,0xDFAE	,0x0000), // High surrogate: D801; U+107AE 'e' ➔ "𐞮" MODIFIER LETTER SMALL TESH DIGRAPH
/*<!M><%circum><%ampersand><t><s>                                  */ DEADTRANS( L's'	,0xE3C0	,0xDFAC	,0x0000), // High surrogate: D801; U+107AC 's' ➔ "𐞬" MODIFIER LETTER SMALL TS DIGRAPH
/*<!M><%circum><%ampersand><t><S>                                  */ DEADTRANS( L'S'	,0xE3C0	,0xDFAE	,0x0000), // High surrogate: D801; U+107AE 'S' ➔ "𐞮" MODIFIER LETTER SMALL TESH DIGRAPH
/*<!M><%circum><%ampersand><u>                                     */ DEADTRANS( L'u'	,0xE3A8	,0xA770	,0x0000), // 'u' ➔ "ꝰ" MODIFIER LETTER US
/*<!M><%circum><%bracketright>                                     */ DEADTRANS( L']'	,0xE3A7	,0x2309	,0x0000), // ']' ➔ "⌉" RIGHT CEILING
/*<!M><%circum><%hash>                                             */ DEADTRANS( L'#'	,0xE3A7	,0xE3C7	,0x0001), // Multikey chain
/*<!M><%circum><%hash><%underscore>                                */ DEADTRANS( L'_'	,0xE3C7	,0x25B4	,0x0000), // '_' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><%circum><%plus>                                             */ DEADTRANS( L'+'	,0xE3A7	,0x2A23	,0x0000), // '+' ➔ "⨣" PLUS SIGN WITH CIRCUMFLEX ACCENT ABOVE
/*<!M><%circum><%tilde>                                            */ DEADTRANS( L'~'	,0xE3A7	,0xE3CA	,0x0001), // Multikey chain
/*<!M><%circum><%tilde><%tilde>                                    */ DEADTRANS( L'~'	,0xE3CA	,0x2A6F	,0x0000), // '~' ➔ "⩯" ALMOST EQUAL TO WITH CIRCUMFLEX ACCENT
/*<!M><%colon>                                                     */ DEADTRANS( L':'	,0x00A6	,0xE3CC	,0x0001), // Multikey chain
/*<!M><%colon><%colon>                                             */ DEADTRANS( L':'	,0xE3CC	,0xE3CD	,0x0001), // Multikey chain
/*<!M><%colon><%colon><%equal>                                     */ DEADTRANS( L'='	,0xE3CD	,0xE3CE	,0x0001), // Multikey chain
/*<!M><%colon><%colon><%equal><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE3CE	,0x2A74	,0x0000), // ' ' ➔ "⩴" DOUBLE COLON EQUAL
/*<!M><%colon><%colon><%equal><~space>                             */ DEADTRANS( L' '	,0xE3CE	,0x2A74	,0x0000), // ' ' ➔ "⩴" DOUBLE COLON EQUAL
/*<!M><%colon><%equal>                                             */ DEADTRANS( L'='	,0xE3CC	,0x2254	,0x0000), // '=' ➔ "≔" COLON EQUALS
/*<!M><%colon><%minus>                                             */ DEADTRANS( L'-'	,0xE3CC	,0xE3D2	,0x0001), // Multikey chain
/*<!M><%colon><%minus><%colon>                                     */ DEADTRANS( L':'	,0xE3D2	,0x223A	,0x0000), // ':' ➔ "∺" GEOMETRIC PROPORTION
/*<!M><%colon><%minus><%greater>                                   */ DEADTRANS( L'>'	,0xE3D2	,0x29F4	,0x0000), // '>' ➔ "⧴" RULE-DELAYED
/*<!M><%colon><%minus><x>                                          */ DEADTRANS( L'x'	,0xE3D2	,0x22C7	,0x0000), // 'x' ➔ "⋇" DIVISION TIMES
/*<!M><%colon><%minus><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE3D2	,0x00F7	,0x0000), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%colon><%minus><~space>                                     */ DEADTRANS( L' '	,0xE3D2	,0x00F7	,0x0000), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%colon><%parenleft>                                         */ DEADTRANS( L'('	,0xE3CC	,0x2639	,0x0000), // '(' ➔ "☹" WHITE FROWNING FACE emoji with skin tone support
/*<!M><%colon><%parenright>                                        */ DEADTRANS( L')'	,0xE3CC	,0x263A	,0x0000), // ')' ➔ "☺" WHITE SMILING FACE emoji with skin tone support, 25th-ranking
/*<!M><%colon><%period>                                            */ DEADTRANS( L'.'	,0xE3CC	,0x2AF6	,0x0000), // '.' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><%comma>                                                     */ DEADTRANS( L','	,0x00A6	,0xE3DB	,0x0001), // Multikey chain
/*<!M><%comma><%minus>                                             */ DEADTRANS( L'-'	,0xE3DB	,0x2A29	,0x0000), // '-' ➔ "⨩" MINUS SIGN WITH COMMA ABOVE
/*<!M><%equal>                                                     */ DEADTRANS( L'='	,0x00A6	,0xE3DD	,0x0001), // Multikey chain
/*<!M><%equal><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE3DD	,0xE3DE	,0x0001), // Multikey chain
/*<!M><%equal><%apostrophe><%equal>                                */ DEADTRANS( L'='	,0xE3DE	,0x2AE7	,0x0000), // '=' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><%equal><%apostrophe><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE3DE	,0x2AEC	,0x0000), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%apostrophe><~space>                                */ DEADTRANS( L' '	,0xE3DE	,0x2AEC	,0x0000), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%aprightsingquotmark>                               */ DEADTRANS( 0x2019	,0xE3DD	,0xE3E2	,0x0001), // Multikey chain
/*<!M><%equal><%aprightsingquotmark><%equal>                       */ DEADTRANS( L'='	,0xE3E2	,0x2AE7	,0x0000), // '=' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><%equal><%aprightsingquotmark><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE3E2	,0x2AEC	,0x0000), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%aprightsingquotmark><~space>                       */ DEADTRANS( L' '	,0xE3E2	,0x2AEC	,0x0000), // ' ' ➔ "⫬" DOUBLE STROKE NOT SIGN
/*<!M><%equal><%bar>                                               */ DEADTRANS( L'|'	,0xE3DD	,0xE3E6	,0x0001), // Multikey chain
/*<!M><%equal><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE3E6	,0xE3E7	,0x0001), // Multikey chain
/*<!M><%equal><%bar><%bar><%equal>                                 */ DEADTRANS( L'='	,0xE3E7	,0x27DA	,0x0000), // '=' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><%equal><%bar><%bar><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE3E7	,0x2AE5	,0x0000), // ' ' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar><%bar><~space>                                 */ DEADTRANS( L' '	,0xE3E7	,0x2AE5	,0x0000), // ' ' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar><%equal>                                       */ DEADTRANS( L'='	,0xE3E6	,0x2903	,0x0000), // '=' ➔ "⤃" RIGHTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%equal><%bar><%greater>                                     */ DEADTRANS( L'>'	,0xE3E6	,0x2903	,0x0000), // '>' ➔ "⤃" RIGHTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%equal><%bar><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE3E6	,0x2AE4	,0x0000), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%bar><~space>                                       */ DEADTRANS( L' '	,0xE3E6	,0x2AE4	,0x0000), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><%equal><%circum>                                            */ DEADTRANS( L'^'	,0xE3DD	,0x207C	,0x0000), // '^' ➔ "⁼" SUPERSCRIPT EQUALS SIGN
/*<!M><%equal><%colon>                                             */ DEADTRANS( L':'	,0xE3DD	,0x2255	,0x0000), // ':' ➔ "≕" EQUALS COLON
/*<!M><%equal><%equal>                                             */ DEADTRANS( L'='	,0xE3DD	,0xE3F1	,0x0001), // Multikey chain
/*<!M><%equal><%equal><%equal>                                     */ DEADTRANS( L'='	,0xE3F1	,0xE3F2	,0x0001), // Multikey chain
/*<!M><%equal><%equal><%equal><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE3F2	,0x2A76	,0x0000), // ' ' ➔ "⩶" THREE CONSECUTIVE EQUALS SIGNS
/*<!M><%equal><%equal><%equal><~space>                             */ DEADTRANS( L' '	,0xE3F2	,0x2A76	,0x0000), // ' ' ➔ "⩶" THREE CONSECUTIVE EQUALS SIGNS
/*<!M><%equal><%equal><%greater>                                   */ DEADTRANS( L'>'	,0xE3F1	,0x27F9	,0x0000), // '>' ➔ "⟹" LONG RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%greater>                                           */ DEADTRANS( L'>'	,0xE3DD	,0xE3F6	,0x0001), // Multikey chain
/*<!M><%equal><%greater><%grave>                                   */ DEADTRANS( L'`'	,0xE3F6	,0x2A9C	,0x0000), // '`' ➔ "⪜" DOUBLE-LINE SLANTED EQUAL TO OR GREATER-THAN
/*<!M><%equal><%greater><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE3F6	,0x21D2	,0x0000), // ' ' ➔ "⇒" RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%greater><~space>                                   */ DEADTRANS( L' '	,0xE3F6	,0x21D2	,0x0000), // ' ' ➔ "⇒" RIGHTWARDS DOUBLE ARROW
/*<!M><%equal><%less>                                              */ DEADTRANS( L'<'	,0xE3DD	,0xE3FA	,0x0001), // Multikey chain
/*<!M><%equal><%less><%grave>                                      */ DEADTRANS( L'`'	,0xE3FA	,0x2A9B	,0x0000), // '`' ➔ "⪛" DOUBLE-LINE SLANTED EQUAL TO OR LESS-THAN
/*<!M><%equal><%less><%minus>                                      */ DEADTRANS( L'-'	,0xE3FA	,0x2B40	,0x0000), // '-' ➔ "⭀" EQUALS SIGN ABOVE LEFTWARDS ARROW
/*<!M><%equal><%less><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE3FA	,0x2A99	,0x0000), // ' ' ➔ "⪙" DOUBLE-LINE EQUAL TO OR LESS-THAN
/*<!M><%equal><%less><~space>                                      */ DEADTRANS( L' '	,0xE3FA	,0x2A99	,0x0000), // ' ' ➔ "⪙" DOUBLE-LINE EQUAL TO OR LESS-THAN
/*<!M><%equal><%minus>                                             */ DEADTRANS( L'-'	,0xE3DD	,0xE3FF	,0x0001), // Multikey chain
/*<!M><%equal><%minus><%bar>                                       */ DEADTRANS( L'|'	,0xE3FF	,0xE400	,0x0001), // Multikey chain
/*<!M><%equal><%minus><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE400	,0xE401	,0x0001), // Multikey chain
/*<!M><%equal><%minus><%bar><%bar><%bar>                           */ DEADTRANS( L'|'	,0xE401	,0x2A69	,0x0000), // '|' ➔ "⩩" TRIPLE HORIZONTAL BAR WITH TRIPLE VERTICAL STROKE
/*<!M><%equal><%minus><%bar><%bar><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE401	,0x2A68	,0x0000), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%equal><%minus><%bar><%bar><~space>                         */ DEADTRANS( L' '	,0xE401	,0x2A68	,0x0000), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%equal><%minus><%slash>                                     */ DEADTRANS( L'/'	,0xE3FF	,0xE405	,0x0001), // Multikey chain
/*<!M><%equal><%minus><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE405	,0x2262	,0x0000), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%equal><%minus><%slash><~space>                             */ DEADTRANS( L' '	,0xE405	,0x2262	,0x0000), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%equal><%minus><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE3FF	,0x2261	,0x0000), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%equal><%minus><~space>                                     */ DEADTRANS( L' '	,0xE3FF	,0x2261	,0x0000), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%equal><%parenright>                                        */ DEADTRANS( L')'	,0xE3DD	,0x2970	,0x0000), // ')' ➔ "⥰" RIGHT DOUBLE ARROW WITH ROUNDED HEAD
/*<!M><%equal><%period>                                            */ DEADTRANS( L'.'	,0xE3DD	,0x2A66	,0x0000), // '.' ➔ "⩦" EQUALS SIGN WITH DOT BELOW
/*<!M><%equal><%plus>                                              */ DEADTRANS( L'+'	,0xE3DD	,0x2A71	,0x0000), // '+' ➔ "⩱" EQUALS SIGN ABOVE PLUS SIGN
/*<!M><%equal><%slash>                                             */ DEADTRANS( L'/'	,0xE3DD	,0xE40D	,0x0001), // Multikey chain
/*<!M><%equal><%slash><%greater>                                   */ DEADTRANS( L'>'	,0xE40D	,0x21CF	,0x0000), // '>' ➔ "⇏" RIGHTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%equal><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xE40D	,0x29E3	,0x0000), // '/' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><%equal><%slash><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE40D	,0x2260	,0x0000), // ' ' ➔ "≠" NOT EQUAL TO
/*<!M><%equal><%slash><~space>                                     */ DEADTRANS( L' '	,0xE40D	,0x2260	,0x0000), // ' ' ➔ "≠" NOT EQUAL TO
/*<!M><%equal><%tilde>                                             */ DEADTRANS( L'~'	,0xE3DD	,0x2A73	,0x0000), // '~' ➔ "⩳" EQUALS SIGN ABOVE TILDE OPERATOR
/*<!M><%equal><%underscore>                                        */ DEADTRANS( L'_'	,0xE3DD	,0x208C	,0x0000), // '_' ➔ "₌" SUBSCRIPT EQUALS SIGN
/*<!M><%exclam>                                                    */ DEADTRANS( L'!'	,0x00A6	,0xE414	,0x0001), // Multikey chain
/*<!M><%exclam><%apostrophe>                                       */ DEADTRANS( L'\''	,0xE414	,0xE415	,0x0001), // Multikey chain
/*<!M><%exclam><%apostrophe><%bar>                                 */ DEADTRANS( L'|'	,0xE415	,0x2955	,0x0000), // '|' ➔ "⥕" DOWNWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%exclam><%apostrophe><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE415	,0x21C2	,0x0000), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%apostrophe><~space>                               */ DEADTRANS( L' '	,0xE415	,0x21C2	,0x0000), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%aprightsingquotmark>                              */ DEADTRANS( 0x2019	,0xE414	,0xE419	,0x0001), // Multikey chain
/*<!M><%exclam><%aprightsingquotmark><%bar>                        */ DEADTRANS( L'|'	,0xE419	,0x2955	,0x0000), // '|' ➔ "⥕" DOWNWARDS HARPOON WITH BARB RIGHT TO BAR
/*<!M><%exclam><%aprightsingquotmark><~nbspace>                    */ DEADTRANS( 0x00A0	,0xE419	,0x21C2	,0x0000), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%aprightsingquotmark><~space>                      */ DEADTRANS( L' '	,0xE419	,0x21C2	,0x0000), // ' ' ➔ "⇂" DOWNWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%exclam><%bar>                                              */ DEADTRANS( L'|'	,0xE414	,0xE41D	,0x0001), // Multikey chain
/*<!M><%exclam><%bar><%exclam>                                     */ DEADTRANS( L'!'	,0xE41D	,0x2908	,0x0000), // '!' ➔ "⤈" DOWNWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%exclam><%bar><%greater>                                    */ DEADTRANS( L'>'	,0xE41D	,0x2908	,0x0000), // '>' ➔ "⤈" DOWNWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%exclam><%circum>                                           */ DEADTRANS( L'^'	,0xE414	,0x00A6	,0x0000), // '^' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><%exclam><%comma>                                            */ DEADTRANS( L','	,0xE414	,0xE421	,0x0001), // Multikey chain
/*<!M><%exclam><%comma><%minus>                                    */ DEADTRANS( L'-'	,0xE421	,0xE422	,0x0001), // Multikey chain
/*<!M><%exclam><%comma><%minus><%greater>                          */ DEADTRANS( L'>'	,0xE422	,0x2937	,0x0000), // '>' ➔ "⤷" ARROW POINTING DOWNWARDS THEN CURVING RIGHTWARDS
/*<!M><%exclam><%exclam>                                           */ DEADTRANS( L'!'	,0xE414	,0xE424	,0x0001), // Multikey chain
/*<!M><%exclam><%exclam><%exclam>                                  */ DEADTRANS( L'!'	,0xE424	,0x00A1	,0x0000), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><%exclam><%grave>                                            */ DEADTRANS( L'`'	,0xE414	,0xE426	,0x0001), // Multikey chain
/*<!M><%exclam><%grave><%bar>                                      */ DEADTRANS( L'|'	,0xE426	,0x2959	,0x0000), // '|' ➔ "⥙" DOWNWARDS HARPOON WITH BARB LEFT TO BAR
/*<!M><%exclam><%grave><%exclam>                                   */ DEADTRANS( L'!'	,0xE426	,0xE428	,0x0001), // Multikey chain
/*<!M><%exclam><%grave><%exclam><%apostrophe>                      */ DEADTRANS( L'\''	,0xE428	,0x2965	,0x0000), // ''' ➔ "⥥" DOWNWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave><%exclam><%aprightsingquotmark>             */ DEADTRANS( 0x2019	,0xE428	,0x2965	,0x0000), // '’' ➔ "⥥" DOWNWARDS HARPOON WITH BARB LEFT BESIDE DOWNWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave><%grave>                                    */ DEADTRANS( L'`'	,0xE426	,0x296F	,0x0000), // '`' ➔ "⥯" DOWNWARDS HARPOON WITH BARB LEFT BESIDE UPWARDS HARPOON WITH BARB RIGHT
/*<!M><%exclam><%grave><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE426	,0x21C3	,0x0000), // ' ' ➔ "⇃" DOWNWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%exclam><%grave><~space>                                    */ DEADTRANS( L' '	,0xE426	,0x21C3	,0x0000), // ' ' ➔ "⇃" DOWNWARDS HARPOON WITH BARB LEFTWARDS
/*<!M><%exclam><%greater>                                          */ DEADTRANS( L'>'	,0xE414	,0xE42E	,0x0001), // Multikey chain
/*<!M><%exclam><%greater><%bar>                                    */ DEADTRANS( L'|'	,0xE42E	,0x2913	,0x0000), // '|' ➔ "⤓" DOWNWARDS ARROW TO BAR
/*<!M><%exclam><%greater><%equal>                                  */ DEADTRANS( L'='	,0xE42E	,0x21D3	,0x0000), // '=' ➔ "⇓" DOWNWARDS DOUBLE ARROW
/*<!M><%exclam><%greater><%exclam>                                 */ DEADTRANS( L'!'	,0xE42E	,0x21CA	,0x0000), // '!' ➔ "⇊" DOWNWARDS PAIRED ARROWS
/*<!M><%exclam><%greater><%greater>                                */ DEADTRANS( L'>'	,0xE42E	,0xE432	,0x0001), // Multikey chain
/*<!M><%exclam><%greater><%greater><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE432	,0x21A1	,0x0000), // ' ' ➔ "↡" DOWNWARDS TWO HEADED ARROW
/*<!M><%exclam><%greater><%greater><~space>                        */ DEADTRANS( L' '	,0xE432	,0x21A1	,0x0000), // ' ' ➔ "↡" DOWNWARDS TWO HEADED ARROW
/*<!M><%exclam><%greater><%less>                                   */ DEADTRANS( L'<'	,0xE42E	,0x21F5	,0x0000), // '<' ➔ "⇵" DOWNWARDS ARROW LEFTWARDS OF UPWARDS ARROW
/*<!M><%exclam><%greater><2>                                       */ DEADTRANS( L'2'	,0xE42E	,0x21D3	,0x0000), // '2' ➔ "⇓" DOWNWARDS DOUBLE ARROW
/*<!M><%exclam><%greater><3>                                       */ DEADTRANS( L'3'	,0xE42E	,0x290B	,0x0000), // '3' ➔ "⤋" DOWNWARDS TRIPLE ARROW
/*<!M><%exclam><%greater><4>                                       */ DEADTRANS( L'4'	,0xE42E	,0x27F1	,0x0000), // '4' ➔ "⟱" DOWNWARDS QUADRUPLE ARROW
/*<!M><%exclam><%greater><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE42E	,0x2193	,0x0000), // ' ' ➔ "↓" DOWNWARDS ARROW
/*<!M><%exclam><%greater><~space>                                  */ DEADTRANS( L' '	,0xE42E	,0x2193	,0x0000), // ' ' ➔ "↓" DOWNWARDS ARROW
/*<!M><%exclam><%minus>                                            */ DEADTRANS( L'-'	,0xE414	,0xE43B	,0x0001), // Multikey chain
/*<!M><%exclam><%minus><%greater>                                  */ DEADTRANS( L'>'	,0xE43B	,0x21B1	,0x0000), // '>' ➔ "↱" UPWARDS ARROW WITH TIP RIGHTWARDS
/*<!M><%exclam><%question>                                         */ DEADTRANS( L'?'	,0xE414	,0x2E18	,0x0000), // '?' ➔ "⸘" INVERTED INTERROBANG
/*<!M><%exclam><p>                                                 */ DEADTRANS( L'p'	,0xE414	,0x204B	,0x0000), // 'p' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%exclam><P>                                                 */ DEADTRANS( L'P'	,0xE414	,0x204B	,0x0000), // 'P' ➔ "⁋" REVERSED PILCROW SIGN
/*<!M><%grave>                                                     */ DEADTRANS( L'`'	,0x00A6	,0xE440	,0x0001), // Multikey chain
/*<!M><%grave><%exclam>                                            */ DEADTRANS( L'!'	,0xE440	,0xE441	,0x0001), // Multikey chain
/*<!M><%grave><%exclam><%apostrophe>                               */ DEADTRANS( L'\''	,0xE441	,0x294F	,0x0000), // ''' ➔ "⥏" UP BARB RIGHT DOWN BARB RIGHT HARPOON
/*<!M><%grave><%exclam><%aprightsingquotmark>                      */ DEADTRANS( 0x2019	,0xE441	,0x294F	,0x0000), // '’' ➔ "⥏" UP BARB RIGHT DOWN BARB RIGHT HARPOON
/*<!M><%grave><%exclam><%bar>                                      */ DEADTRANS( L'|'	,0xE441	,0x295C	,0x0000), // '|' ➔ "⥜" UPWARDS HARPOON WITH BARB RIGHT FROM BAR
/*<!M><%grave><%exclam><%grave>                                    */ DEADTRANS( L'`'	,0xE441	,0x294C	,0x0000), // '`' ➔ "⥌" UP BARB RIGHT DOWN BARB LEFT HARPOON
/*<!M><%grave><%exclam><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE441	,0x21BE	,0x0000), // ' ' ➔ "↾" UPWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%grave><%exclam><~space>                                    */ DEADTRANS( L' '	,0xE441	,0x21BE	,0x0000), // ' ' ➔ "↾" UPWARDS HARPOON WITH BARB RIGHTWARDS
/*<!M><%grave><%minus>                                             */ DEADTRANS( L'-'	,0xE440	,0xE448	,0x0001), // Multikey chain
/*<!M><%grave><%minus><%apostrophe>                                */ DEADTRANS( L'\''	,0xE448	,0x2950	,0x0000), // ''' ➔ "⥐" LEFT BARB DOWN RIGHT BARB DOWN HARPOON
/*<!M><%grave><%minus><%aprightsingquotmark>                       */ DEADTRANS( 0x2019	,0xE448	,0x2950	,0x0000), // '’' ➔ "⥐" LEFT BARB DOWN RIGHT BARB DOWN HARPOON
/*<!M><%grave><%minus><%bar>                                       */ DEADTRANS( L'|'	,0xE448	,0x295E	,0x0000), // '|' ➔ "⥞" LEFTWARDS HARPOON WITH BARB DOWN FROM BAR
/*<!M><%grave><%minus><%grave>                                     */ DEADTRANS( L'`'	,0xE448	,0x294B	,0x0000), // '`' ➔ "⥋" LEFT BARB DOWN RIGHT BARB UP HARPOON
/*<!M><%grave><%minus><%minus>                                     */ DEADTRANS( L'-'	,0xE448	,0xE44D	,0x0001), // Multikey chain
/*<!M><%grave><%minus><%minus><%apostrophe>                        */ DEADTRANS( L'\''	,0xE44D	,0x2967	,0x0000), // ''' ➔ "⥧" LEFTWARDS HARPOON WITH BARB DOWN ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%grave><%minus><%minus><%aprightsingquotmark>               */ DEADTRANS( 0x2019	,0xE44D	,0x2967	,0x0000), // '’' ➔ "⥧" LEFTWARDS HARPOON WITH BARB DOWN ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%grave><%minus><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE448	,0x21BD	,0x0000), // ' ' ➔ "↽" LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%grave><%minus><~space>                                     */ DEADTRANS( L' '	,0xE448	,0x21BD	,0x0000), // ' ' ➔ "↽" LEFTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><%greater>                                                   */ DEADTRANS( L'>'	,0x00A6	,0xE452	,0x0001), // Multikey chain
/*<!M><%greater><%bar>                                             */ DEADTRANS( L'|'	,0xE452	,0xE453	,0x0001), // Multikey chain
/*<!M><%greater><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xE453	,0xE454	,0x0001), // Multikey chain
/*<!M><%greater><%bar><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE454	,0x22EB	,0x0000), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%greater><%bar><%slash><~space>                             */ DEADTRANS( L' '	,0xE454	,0x22EB	,0x0000), // ' ' ➔ "⋫" DOES NOT CONTAIN AS NORMAL SUBGROUP
/*<!M><%greater><%bracketleft>                                     */ DEADTRANS( L'['	,0xE452	,0x27E9	,0x0000), // '[' ➔ "⟩" MATHEMATICAL RIGHT ANGLE BRACKET
/*<!M><%greater><%bracketright>                                    */ DEADTRANS( L']'	,0xE452	,0x27E9	,0x0000), // ']' ➔ "⟩" MATHEMATICAL RIGHT ANGLE BRACKET
/*<!M><%greater><%equal>                                           */ DEADTRANS( L'='	,0xE452	,0xE459	,0x0001), // Multikey chain
/*<!M><%greater><%equal><%grave>                                   */ DEADTRANS( L'`'	,0xE459	,0x2AFA	,0x0000), // '`' ➔ "⫺" DOUBLE-LINE SLANTED GREATER-THAN OR EQUAL TO
/*<!M><%greater><%equal><%less>                                    */ DEADTRANS( L'<'	,0xE459	,0x2A8C	,0x0000), // '<' ➔ "⪌" GREATER-THAN ABOVE DOUBLE-LINE EQUAL ABOVE LESS-THAN
/*<!M><%greater><%equal><%slash>                                   */ DEADTRANS( L'/'	,0xE459	,0x2269	,0x0000), // '/' ➔ "≩" GREATER-THAN BUT NOT EQUAL TO
/*<!M><%greater><%equal><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE459	,0x2267	,0x0000), // ' ' ➔ "≧" GREATER-THAN OVER EQUAL TO
/*<!M><%greater><%equal><~space>                                   */ DEADTRANS( L' '	,0xE459	,0x2267	,0x0000), // ' ' ➔ "≧" GREATER-THAN OVER EQUAL TO
/*<!M><%greater><%greater>                                         */ DEADTRANS( L'>'	,0xE452	,0xE45F	,0x0001), // Multikey chain
/*<!M><%greater><%greater><%bracketleft>                           */ DEADTRANS( L'['	,0xE45F	,0x27EB	,0x0000), // '[' ➔ "⟫" MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*<!M><%greater><%greater><%bracketright>                          */ DEADTRANS( L']'	,0xE45F	,0x27EB	,0x0000), // ']' ➔ "⟫" MATHEMATICAL RIGHT DOUBLE ANGLE BRACKET
/*<!M><%greater><%greater><%minus>                                 */ DEADTRANS( L'-'	,0xE45F	,0x291C	,0x0000), // '-' ➔ "⤜" RIGHTWARDS DOUBLE ARROW-TAIL
/*<!M><%greater><%greater><%parenleft>                             */ DEADTRANS( L'('	,0xE45F	,0x2ABC	,0x0000), // '(' ➔ "⪼" DOUBLE SUCCEEDS
/*<!M><%greater><%greater><%parenright>                            */ DEADTRANS( L')'	,0xE45F	,0x2ABC	,0x0000), // ')' ➔ "⪼" DOUBLE SUCCEEDS
/*<!M><%greater><%less>                                            */ DEADTRANS( L'<'	,0xE452	,0xE465	,0x0001), // Multikey chain
/*<!M><%greater><%less><%equal>                                    */ DEADTRANS( L'='	,0xE465	,0x2A92	,0x0000), // '=' ➔ "⪒" GREATER-THAN ABOVE LESS-THAN ABOVE DOUBLE-LINE EQUAL
/*<!M><%greater><%less><%parenleft>                                */ DEADTRANS( L'('	,0xE465	,0xE467	,0x0001), // Multikey chain
/*<!M><%greater><%less><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE467	,0xE468	,0x0001), // Multikey chain
/*<!M><%greater><%less><%parenleft><%parenright><%minus>           */ DEADTRANS( L'-'	,0xE468	,0x27E3	,0x0000), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%greater><%less><%parenleft><%parenright><~nbspace>         */ DEADTRANS( 0x00A0	,0xE468	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenleft><%parenright><~space>           */ DEADTRANS( L' '	,0xE468	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenright>                               */ DEADTRANS( L')'	,0xE465	,0xE46C	,0x0001), // Multikey chain
/*<!M><%greater><%less><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE46C	,0xE46D	,0x0001), // Multikey chain
/*<!M><%greater><%less><%parenright><%parenleft><%minus>           */ DEADTRANS( L'-'	,0xE46D	,0x27E3	,0x0000), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%greater><%less><%parenright><%parenleft><~nbspace>         */ DEADTRANS( 0x00A0	,0xE46D	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%parenright><%parenleft><~space>           */ DEADTRANS( L' '	,0xE46D	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%greater><%less><%slash>                                    */ DEADTRANS( L'/'	,0xE465	,0x2279	,0x0000), // '/' ➔ "≹" NEITHER GREATER-THAN NOR LESS-THAN
/*<!M><%greater><%less><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE465	,0x2277	,0x0000), // ' ' ➔ "≷" GREATER-THAN OR LESS-THAN
/*<!M><%greater><%less><~space>                                    */ DEADTRANS( L' '	,0xE465	,0x2277	,0x0000), // ' ' ➔ "≷" GREATER-THAN OR LESS-THAN
/*<!M><%greater><%minus>                                           */ DEADTRANS( L'-'	,0xE452	,0xE474	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar>                                     */ DEADTRANS( L'|'	,0xE474	,0xE475	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%bar>                               */ DEADTRANS( L'|'	,0xE475	,0xE476	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%bar><%greater>                     */ DEADTRANS( L'>'	,0xE476	,0xE477	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%bar><%greater><%greater>           */ DEADTRANS( L'>'	,0xE477	,0x2918	,0x0000), // '>' ➔ "⤘" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%greater><~nbspace>           */ DEADTRANS( 0x00A0	,0xE477	,0x2915	,0x0000), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%greater><~space>             */ DEADTRANS( L' '	,0xE477	,0x2915	,0x0000), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus>                       */ DEADTRANS( L'-'	,0xE476	,0xE47B	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater>             */ DEADTRANS( L'>'	,0xE47B	,0xE47C	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater><%greater>   */ DEADTRANS( L'>'	,0xE47C	,0x2918	,0x0000), // '>' ➔ "⤘" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater><~nbspace>   */ DEADTRANS( 0x00A0	,0xE47C	,0x2915	,0x0000), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%bar><%minus><%greater><~space>     */ DEADTRANS( L' '	,0xE47C	,0x2915	,0x0000), // ' ' ➔ "⤕" RIGHTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater>                           */ DEADTRANS( L'>'	,0xE475	,0xE480	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%greater><%greater>                 */ DEADTRANS( L'>'	,0xE480	,0x2917	,0x0000), // '>' ➔ "⤗" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater><~nbspace>                 */ DEADTRANS( 0x00A0	,0xE480	,0x2914	,0x0000), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%greater><~space>                   */ DEADTRANS( L' '	,0xE480	,0x2914	,0x0000), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus>                             */ DEADTRANS( L'-'	,0xE475	,0xE484	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%minus><%greater>                   */ DEADTRANS( L'>'	,0xE484	,0xE485	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%bar><%minus><%greater><%greater>         */ DEADTRANS( L'>'	,0xE485	,0x2917	,0x0000), // '>' ➔ "⤗" RIGHTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus><%greater><~nbspace>         */ DEADTRANS( 0x00A0	,0xE485	,0x2914	,0x0000), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%bar><%minus><%greater><~space>           */ DEADTRANS( L' '	,0xE485	,0x2914	,0x0000), // ' ' ➔ "⤔" RIGHTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%greater><%minus><%greater>                                 */ DEADTRANS( L'>'	,0xE474	,0xE489	,0x0001), // Multikey chain
/*<!M><%greater><%minus><%greater><%greater>                       */ DEADTRANS( L'>'	,0xE489	,0x2916	,0x0000), // '>' ➔ "⤖" RIGHTWARDS TWO-HEADED ARROW WITH TAIL
/*<!M><%greater><%minus><%greater><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE489	,0x21A3	,0x0000), // ' ' ➔ "↣" RIGHTWARDS ARROW WITH TAIL
/*<!M><%greater><%minus><%greater><~space>                         */ DEADTRANS( L' '	,0xE489	,0x21A3	,0x0000), // ' ' ➔ "↣" RIGHTWARDS ARROW WITH TAIL
/*<!M><%greater><%minus><%underscore>                              */ DEADTRANS( L'_'	,0xE474	,0x2AAD	,0x0000), // '_' ➔ "⪭" LARGER THAN OR EQUAL TO
/*<!M><%greater><%minus><0>                                        */ DEADTRANS( L'0'	,0xE474	,0x2910	,0x0000), // '0' ➔ "⤐" RIGHTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%greater><%minus><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE474	,0x291A	,0x0000), // ' ' ➔ "⤚" RIGHTWARDS ARROW-TAIL
/*<!M><%greater><%minus><~space>                                   */ DEADTRANS( L' '	,0xE474	,0x291A	,0x0000), // ' ' ➔ "⤚" RIGHTWARDS ARROW-TAIL
/*<!M><%greater><%parenleft>                                       */ DEADTRANS( L'('	,0xE452	,0xE491	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenleft>                           */ DEADTRANS( L'('	,0xE491	,0x2995	,0x0000), // '(' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%greater><%parenleft><%parenright>                          */ DEADTRANS( L')'	,0xE491	,0xE493	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenright><%bracketleft>            */ DEADTRANS( L'['	,0xE493	,0x29FD	,0x0000), // '[' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenleft><%parenright><%bracketright>           */ DEADTRANS( L']'	,0xE493	,0x29FD	,0x0000), // ']' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenleft><%parenright><%equal>                  */ DEADTRANS( L'='	,0xE493	,0xE496	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenright><%equal><%slash>          */ DEADTRANS( L'/'	,0xE496	,0x2AB6	,0x0000), // '/' ➔ "⪶" SUCCEEDS ABOVE NOT EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%equal><~nbspace>        */ DEADTRANS( 0x00A0	,0xE496	,0x2AB4	,0x0000), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><%equal><~space>          */ DEADTRANS( L' '	,0xE496	,0x2AB4	,0x0000), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><%slash>                  */ DEADTRANS( L'/'	,0xE493	,0x2281	,0x0000), // '/' ➔ "⊁" DOES NOT SUCCEED
/*<!M><%greater><%parenleft><%parenright><%tilde>                  */ DEADTRANS( L'~'	,0xE493	,0xE49B	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenright><%tilde><%slash>          */ DEADTRANS( L'/'	,0xE49B	,0x22E9	,0x0000), // '/' ➔ "⋩" SUCCEEDS BUT NOT EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde>          */ DEADTRANS( L'~'	,0xE49B	,0xE49D	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde><%slash>  */ DEADTRANS( L'/'	,0xE49D	,0x2ABA	,0x0000), // '/' ➔ "⪺" SUCCEEDS ABOVE NOT ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde><~nbspace>*/ DEADTRANS( 0x00A0	,0xE49D	,0x2AB8	,0x0000), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde><%tilde><~space>  */ DEADTRANS( L' '	,0xE49D	,0x2AB8	,0x0000), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%tilde><~nbspace>        */ DEADTRANS( 0x00A0	,0xE49B	,0x227F	,0x0000), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%tilde><~space>          */ DEADTRANS( L' '	,0xE49B	,0x227F	,0x0000), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenleft><%parenright><%underscore>             */ DEADTRANS( L'_'	,0xE493	,0xE4A3	,0x0001), // Multikey chain
/*<!M><%greater><%parenleft><%parenright><%underscore><%slash>     */ DEADTRANS( L'/'	,0xE4A3	,0x2AB2	,0x0000), // '/' ➔ "⪲" SUCCEEDS ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%parenleft><%parenright><%underscore><~nbspace>   */ DEADTRANS( 0x00A0	,0xE4A3	,0x2AB0	,0x0000), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><%underscore><~space>     */ DEADTRANS( L' '	,0xE4A3	,0x2AB0	,0x0000), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenleft><%parenright><~nbspace>                */ DEADTRANS( 0x00A0	,0xE493	,0x227B	,0x0000), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenleft><%parenright><~space>                  */ DEADTRANS( L' '	,0xE493	,0x227B	,0x0000), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenright>                                      */ DEADTRANS( L')'	,0xE452	,0xE4A9	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft>                          */ DEADTRANS( L'('	,0xE4A9	,0xE4AA	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft><%bracketleft>            */ DEADTRANS( L'['	,0xE4AA	,0x29FD	,0x0000), // '[' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenright><%parenleft><%bracketright>           */ DEADTRANS( L']'	,0xE4AA	,0x29FD	,0x0000), // ']' ➔ "⧽" RIGHT-POINTING CURVED ANGLE BRACKET
/*<!M><%greater><%parenright><%parenleft><%equal>                  */ DEADTRANS( L'='	,0xE4AA	,0xE4AD	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft><%equal><%slash>          */ DEADTRANS( L'/'	,0xE4AD	,0x2AB6	,0x0000), // '/' ➔ "⪶" SUCCEEDS ABOVE NOT EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%equal><~nbspace>        */ DEADTRANS( 0x00A0	,0xE4AD	,0x2AB4	,0x0000), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><%equal><~space>          */ DEADTRANS( L' '	,0xE4AD	,0x2AB4	,0x0000), // ' ' ➔ "⪴" SUCCEEDS ABOVE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><%slash>                  */ DEADTRANS( L'/'	,0xE4AA	,0x2281	,0x0000), // '/' ➔ "⊁" DOES NOT SUCCEED
/*<!M><%greater><%parenright><%parenleft><%tilde>                  */ DEADTRANS( L'~'	,0xE4AA	,0xE4B2	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft><%tilde><%slash>          */ DEADTRANS( L'/'	,0xE4B2	,0x22E9	,0x0000), // '/' ➔ "⋩" SUCCEEDS BUT NOT EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde>          */ DEADTRANS( L'~'	,0xE4B2	,0xE4B4	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde><%slash>  */ DEADTRANS( L'/'	,0xE4B4	,0x2ABA	,0x0000), // '/' ➔ "⪺" SUCCEEDS ABOVE NOT ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde><~nbspace>*/ DEADTRANS( 0x00A0	,0xE4B4	,0x2AB8	,0x0000), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde><%tilde><~space>  */ DEADTRANS( L' '	,0xE4B4	,0x2AB8	,0x0000), // ' ' ➔ "⪸" SUCCEEDS ABOVE ALMOST EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%tilde><~nbspace>        */ DEADTRANS( 0x00A0	,0xE4B2	,0x227F	,0x0000), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%tilde><~space>          */ DEADTRANS( L' '	,0xE4B2	,0x227F	,0x0000), // ' ' ➔ "≿" SUCCEEDS OR EQUIVALENT TO
/*<!M><%greater><%parenright><%parenleft><%underscore>             */ DEADTRANS( L'_'	,0xE4AA	,0xE4BA	,0x0001), // Multikey chain
/*<!M><%greater><%parenright><%parenleft><%underscore><%slash>     */ DEADTRANS( L'/'	,0xE4BA	,0x2AB2	,0x0000), // '/' ➔ "⪲" SUCCEEDS ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%parenright><%parenleft><%underscore><~nbspace>   */ DEADTRANS( 0x00A0	,0xE4BA	,0x2AB0	,0x0000), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><%underscore><~space>     */ DEADTRANS( L' '	,0xE4BA	,0x2AB0	,0x0000), // ' ' ➔ "⪰" SUCCEEDS ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%greater><%parenright><%parenleft><~nbspace>                */ DEADTRANS( 0x00A0	,0xE4AA	,0x227B	,0x0000), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%parenright><%parenleft><~space>                  */ DEADTRANS( L' '	,0xE4AA	,0x227B	,0x0000), // ' ' ➔ "≻" SUCCEEDS
/*<!M><%greater><%period>                                          */ DEADTRANS( L'.'	,0xE452	,0xE4C0	,0x0001), // Multikey chain
/*<!M><%greater><%period><%underscore>                             */ DEADTRANS( L'_'	,0xE4C0	,0x2A82	,0x0000), // '_' ➔ "⪂" GREATER-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!M><%greater><%period><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE4C0	,0x22D7	,0x0000), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%greater><%period><~space>                                  */ DEADTRANS( L' '	,0xE4C0	,0x22D7	,0x0000), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%greater><%slash>                                           */ DEADTRANS( L'/'	,0xE452	,0xE4C4	,0x0001), // Multikey chain
/*<!M><%greater><%slash><%tilde>                                   */ DEADTRANS( L'~'	,0xE4C4	,0x2275	,0x0000), // '~' ➔ "≵" NEITHER GREATER-THAN NOR EQUIVALENT TO
/*<!M><%greater><%slash><%underscore>                              */ DEADTRANS( L'_'	,0xE4C4	,0x2271	,0x0000), // '_' ➔ "≱" NEITHER GREATER-THAN NOR EQUAL TO
/*<!M><%greater><%slash><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE4C4	,0x226F	,0x0000), // ' ' ➔ "≯" NOT GREATER-THAN
/*<!M><%greater><%slash><~space>                                   */ DEADTRANS( L' '	,0xE4C4	,0x226F	,0x0000), // ' ' ➔ "≯" NOT GREATER-THAN
/*<!M><%greater><%tilde>                                           */ DEADTRANS( L'~'	,0xE452	,0xE4C9	,0x0001), // Multikey chain
/*<!M><%greater><%tilde><%less>                                    */ DEADTRANS( L'<'	,0xE4C9	,0x2A90	,0x0000), // '<' ➔ "⪐" GREATER-THAN ABOVE SIMILAR ABOVE LESS-THAN
/*<!M><%greater><%tilde><%minus>                                   */ DEADTRANS( L'-'	,0xE4C9	,0x2A8E	,0x0000), // '-' ➔ "⪎" GREATER-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%greater><%tilde><%slash>                                   */ DEADTRANS( L'/'	,0xE4C9	,0x22E7	,0x0000), // '/' ➔ "⋧" GREATER-THAN BUT NOT EQUIVALENT TO
/*<!M><%greater><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xE4C9	,0xE4CD	,0x0001), // Multikey chain
/*<!M><%greater><%tilde><%tilde><%slash>                           */ DEADTRANS( L'/'	,0xE4CD	,0x2A8A	,0x0000), // '/' ➔ "⪊" GREATER-THAN AND NOT APPROXIMATE
/*<!M><%greater><%tilde><%tilde><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE4CD	,0x2A86	,0x0000), // ' ' ➔ "⪆" GREATER-THAN OR APPROXIMATE
/*<!M><%greater><%tilde><%tilde><~space>                           */ DEADTRANS( L' '	,0xE4CD	,0x2A86	,0x0000), // ' ' ➔ "⪆" GREATER-THAN OR APPROXIMATE
/*<!M><%greater><%tilde><%underscore>                              */ DEADTRANS( L'_'	,0xE4C9	,0x2A8E	,0x0000), // '_' ➔ "⪎" GREATER-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%greater><%tilde><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE4C9	,0x2273	,0x0000), // ' ' ➔ "≳" GREATER-THAN OR EQUIVALENT TO
/*<!M><%greater><%tilde><~space>                                   */ DEADTRANS( L' '	,0xE4C9	,0x2273	,0x0000), // ' ' ➔ "≳" GREATER-THAN OR EQUIVALENT TO
/*<!M><%greater><%underscore>                                      */ DEADTRANS( L'_'	,0xE452	,0xE4D4	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%grave>                              */ DEADTRANS( L'`'	,0xE4D4	,0x2A7E	,0x0000), // '`' ➔ "⩾" GREATER-THAN OR SLANTED EQUAL TO
/*<!M><%greater><%underscore><%less>                               */ DEADTRANS( L'<'	,0xE4D4	,0xE4D6	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%less><%underscore>                  */ DEADTRANS( L'_'	,0xE4D6	,0x2A94	,0x0000), // '_' ➔ "⪔" GREATER-THAN ABOVE SLANTED EQUAL ABOVE LESS-THAN ABOVE SLANTED EQUAL
/*<!M><%greater><%underscore><%less><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE4D6	,0x22DB	,0x0000), // ' ' ➔ "⋛" GREATER-THAN EQUAL TO OR LESS-THAN
/*<!M><%greater><%underscore><%less><~space>                       */ DEADTRANS( L' '	,0xE4D6	,0x22DB	,0x0000), // ' ' ➔ "⋛" GREATER-THAN EQUAL TO OR LESS-THAN
/*<!M><%greater><%underscore><%parenleft>                          */ DEADTRANS( L'('	,0xE4D4	,0xE4DA	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%parenleft><%parenright>             */ DEADTRANS( L')'	,0xE4DA	,0xE4DB	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%parenleft><%parenright><%slash>     */ DEADTRANS( L'/'	,0xE4DB	,0x22E1	,0x0000), // '/' ➔ "⋡" DOES NOT SUCCEED OR EQUAL
/*<!M><%greater><%underscore><%parenleft><%parenright><~nbspace>   */ DEADTRANS( 0x00A0	,0xE4DB	,0x227D	,0x0000), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenleft><%parenright><~space>     */ DEADTRANS( L' '	,0xE4DB	,0x227D	,0x0000), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenright>                         */ DEADTRANS( L')'	,0xE4D4	,0xE4DF	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%parenright><%parenleft>             */ DEADTRANS( L'('	,0xE4DF	,0xE4E0	,0x0001), // Multikey chain
/*<!M><%greater><%underscore><%parenright><%parenleft><%slash>     */ DEADTRANS( L'/'	,0xE4E0	,0x22E1	,0x0000), // '/' ➔ "⋡" DOES NOT SUCCEED OR EQUAL
/*<!M><%greater><%underscore><%parenright><%parenleft><~nbspace>   */ DEADTRANS( 0x00A0	,0xE4E0	,0x227D	,0x0000), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%parenright><%parenleft><~space>     */ DEADTRANS( L' '	,0xE4E0	,0x227D	,0x0000), // ' ' ➔ "≽" SUCCEEDS OR EQUAL TO
/*<!M><%greater><%underscore><%period>                             */ DEADTRANS( L'.'	,0xE4D4	,0x2A80	,0x0000), // '.' ➔ "⪀" GREATER-THAN OR SLANTED EQUAL TO WITH DOT INSIDE
/*<!M><%greater><%underscore><%slash>                              */ DEADTRANS( L'/'	,0xE4D4	,0x2A88	,0x0000), // '/' ➔ "⪈" GREATER-THAN AND SINGLE-LINE NOT EQUAL TO
/*<!M><%greater><%underscore><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE4D4	,0x2265	,0x0000), // ' ' ➔ "≥" GREATER-THAN OR EQUAL TO
/*<!M><%greater><%underscore><~space>                              */ DEADTRANS( L' '	,0xE4D4	,0x2265	,0x0000), // ' ' ➔ "≥" GREATER-THAN OR EQUAL TO
/*<!M><%less>                                                      */ DEADTRANS( L'<'	,0x00A6	,0xE4E8	,0x0001), // Multikey chain
/*<!M><%less><%backslash>                                          */ DEADTRANS( L'\\'	,0xE4E8	,0xE4E9	,0x0001), // Multikey chain
/*<!M><%less><%backslash><%equal>                                  */ DEADTRANS( L'='	,0xE4E9	,0x21D6	,0x0000), // '=' ➔ "⇖" NORTH WEST DOUBLE ARROW
/*<!M><%less><%backslash><%greater>                                */ DEADTRANS( L'>'	,0xE4E9	,0x2921	,0x0000), // '>' ➔ "⤡" NORTH WEST AND SOUTH EAST ARROW
/*<!M><%less><%backslash><%less>                                   */ DEADTRANS( L'<'	,0xE4E9	,0x292A	,0x0000), // '<' ➔ "⤪" SOUTH WEST ARROW AND NORTH WEST ARROW
/*<!M><%less><%backslash><%parenleft>                              */ DEADTRANS( L'('	,0xE4E9	,0xE4ED	,0x0001), // Multikey chain
/*<!M><%less><%backslash><%parenleft><%minus>                      */ DEADTRANS( L'-'	,0xE4ED	,0x29A9	,0x0000), // '-' ➔ "⦩" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING UP AND LEFT
/*<!M><%less><%backslash><%parenright>                             */ DEADTRANS( L')'	,0xE4E9	,0x2923	,0x0000), // ')' ➔ "⤣" NORTH WEST ARROW WITH HOOK
/*<!M><%less><%backslash><%slash>                                  */ DEADTRANS( L'/'	,0xE4E9	,0x2927	,0x0000), // '/' ➔ "⤧" NORTH WEST ARROW AND NORTH EAST ARROW
/*<!M><%less><%backslash><2>                                       */ DEADTRANS( L'2'	,0xE4E9	,0x21D6	,0x0000), // '2' ➔ "⇖" NORTH WEST DOUBLE ARROW
/*<!M><%less><%backslash><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE4E9	,0x2196	,0x0000), // ' ' ➔ "↖" NORTH WEST ARROW
/*<!M><%less><%backslash><~space>                                  */ DEADTRANS( L' '	,0xE4E9	,0x2196	,0x0000), // ' ' ➔ "↖" NORTH WEST ARROW
/*<!M><%less><%bar>                                                */ DEADTRANS( L'|'	,0xE4E8	,0xE4F4	,0x0001), // Multikey chain
/*<!M><%less><%bar><%bar>                                          */ DEADTRANS( L'|'	,0xE4F4	,0xE4F5	,0x0001), // Multikey chain
/*<!M><%less><%bar><%bar><%minus>                                  */ DEADTRANS( L'-'	,0xE4F5	,0xE4F6	,0x0001), // Multikey chain
/*<!M><%less><%bar><%bar><%minus><%less>                           */ DEADTRANS( L'<'	,0xE4F6	,0x2B3A	,0x0000), // '<' ➔ "⬺" LEFTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar><%minus><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE4F6	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar><%minus><~space>                          */ DEADTRANS( L' '	,0xE4F6	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%bar><%bar><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE4F5	,0x29CF	,0x0000), // ' ' ➔ "⧏" LEFT TRIANGLE BESIDE VERTICAL BAR
/*<!M><%less><%bar><%bar><~space>                                  */ DEADTRANS( L' '	,0xE4F5	,0x29CF	,0x0000), // ' ' ➔ "⧏" LEFT TRIANGLE BESIDE VERTICAL BAR
/*<!M><%less><%bar><%equal>                                        */ DEADTRANS( L'='	,0xE4F4	,0x2902	,0x0000), // '=' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%bar><%exclam>                                       */ DEADTRANS( L'!'	,0xE4F4	,0x2909	,0x0000), // '!' ➔ "⤉" UPWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%less><%bar><%minus>                                        */ DEADTRANS( L'-'	,0xE4F4	,0xE4FE	,0x0001), // Multikey chain
/*<!M><%less><%bar><%minus><%bar>                                  */ DEADTRANS( L'|'	,0xE4FE	,0x21FF	,0x0000), // '|' ➔ "⇿" LEFT RIGHT OPEN-HEADED ARROW
/*<!M><%less><%bar><%minus><%less>                                 */ DEADTRANS( L'<'	,0xE4FE	,0x2B39	,0x0000), // '<' ➔ "⬹" LEFTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%bar><%minus><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE4FE	,0x21FD	,0x0000), // ' ' ➔ "⇽" LEFTWARDS OPEN-HEADED ARROW
/*<!M><%less><%bar><%minus><~space>                                */ DEADTRANS( L' '	,0xE4FE	,0x21FD	,0x0000), // ' ' ➔ "⇽" LEFTWARDS OPEN-HEADED ARROW
/*<!M><%less><%bar><%slash>                                        */ DEADTRANS( L'/'	,0xE4F4	,0xE503	,0x0001), // Multikey chain
/*<!M><%less><%bar><%slash><%underscore>                           */ DEADTRANS( L'_'	,0xE503	,0x22EC	,0x0000), // '_' ➔ "⋬" NOT NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%slash><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE503	,0x22EA	,0x0000), // ' ' ➔ "⋪" NOT NORMAL SUBGROUP OF
/*<!M><%less><%bar><%slash><~space>                                */ DEADTRANS( L' '	,0xE503	,0x22EA	,0x0000), // ' ' ➔ "⋪" NOT NORMAL SUBGROUP OF
/*<!M><%less><%bar><%underscore>                                   */ DEADTRANS( L'_'	,0xE4F4	,0xE507	,0x0001), // Multikey chain
/*<!M><%less><%bar><%underscore><%slash>                           */ DEADTRANS( L'/'	,0xE507	,0x22EC	,0x0000), // '/' ➔ "⋬" NOT NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%underscore><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE507	,0x22B4	,0x0000), // ' ' ➔ "⊴" NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><%underscore><~space>                           */ DEADTRANS( L' '	,0xE507	,0x22B4	,0x0000), // ' ' ➔ "⊴" NORMAL SUBGROUP OF OR EQUAL TO
/*<!M><%less><%bar><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xE4F4	,0x22B2	,0x0000), // ' ' ➔ "⊲" NORMAL SUBGROUP OF
/*<!M><%less><%bar><~space>                                        */ DEADTRANS( L' '	,0xE4F4	,0x22B2	,0x0000), // ' ' ➔ "⊲" NORMAL SUBGROUP OF
/*<!M><%less><%bracketleft>                                        */ DEADTRANS( L'['	,0xE4E8	,0xE50D	,0x0001), // Multikey chain
/*<!M><%less><%bracketleft><%greater>                              */ DEADTRANS( L'>'	,0xE50D	,0x25CA	,0x0000), // '>' ➔ "◊" LOZENGE
/*<!M><%less><%bracketleft><%hash>                                 */ DEADTRANS( L'#'	,0xE50D	,0x29EB	,0x0000), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><%less><%bracketleft><%minus>                                */ DEADTRANS( L'-'	,0xE50D	,0x27E0	,0x0000), // '-' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><%less><%bracketleft><%period>                               */ DEADTRANS( L'.'	,0xE50D	,0x2991	,0x0000), // '.' ➔ "⦑" LEFT ANGLE BRACKET WITH DOT
/*<!M><%less><%bracketleft><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE50D	,0x27E8	,0x0000), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketleft><~space>                                */ DEADTRANS( L' '	,0xE50D	,0x27E8	,0x0000), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketright>                                       */ DEADTRANS( L']'	,0xE4E8	,0xE514	,0x0001), // Multikey chain
/*<!M><%less><%bracketright><%greater>                             */ DEADTRANS( L'>'	,0xE514	,0x25CA	,0x0000), // '>' ➔ "◊" LOZENGE
/*<!M><%less><%bracketright><%hash>                                */ DEADTRANS( L'#'	,0xE514	,0x29EB	,0x0000), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><%less><%bracketright><%minus>                               */ DEADTRANS( L'-'	,0xE514	,0x27E0	,0x0000), // '-' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><%less><%bracketright><%period>                              */ DEADTRANS( L'.'	,0xE514	,0x2991	,0x0000), // '.' ➔ "⦑" LEFT ANGLE BRACKET WITH DOT
/*<!M><%less><%bracketright><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE514	,0x27E8	,0x0000), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%bracketright><~space>                               */ DEADTRANS( L' '	,0xE514	,0x27E8	,0x0000), // ' ' ➔ "⟨" MATHEMATICAL LEFT ANGLE BRACKET
/*<!M><%less><%equal>                                              */ DEADTRANS( L'='	,0xE4E8	,0xE51B	,0x0001), // Multikey chain
/*<!M><%less><%equal><%bar>                                        */ DEADTRANS( L'|'	,0xE51B	,0xE51C	,0x0001), // Multikey chain
/*<!M><%less><%equal><%bar><%equal>                                */ DEADTRANS( L'='	,0xE51C	,0xE51D	,0x0001), // Multikey chain
/*<!M><%less><%equal><%bar><%equal><%greater>                      */ DEADTRANS( L'>'	,0xE51D	,0x2904	,0x0000), // '>' ➔ "⤄" LEFT RIGHT DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar><%equal><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE51D	,0x2902	,0x0000), // ' ' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar><%equal><~space>                        */ DEADTRANS( L' '	,0xE51D	,0x2902	,0x0000), // ' ' ➔ "⤂" LEFTWARDS DOUBLE ARROW WITH VERTICAL STROKE
/*<!M><%less><%equal><%bar><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE51C	,0x2906	,0x0000), // ' ' ➔ "⤆" LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%bar><~space>                                */ DEADTRANS( L' '	,0xE51C	,0x2906	,0x0000), // ' ' ➔ "⤆" LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%equal>                                      */ DEADTRANS( L'='	,0xE51B	,0xE523	,0x0001), // Multikey chain
/*<!M><%less><%equal><%equal><%bar>                                */ DEADTRANS( L'|'	,0xE523	,0x27FD	,0x0000), // '|' ➔ "⟽" LONG LEFTWARDS DOUBLE ARROW FROM BAR
/*<!M><%less><%equal><%equal><%greater>                            */ DEADTRANS( L'>'	,0xE523	,0x27FA	,0x0000), // '>' ➔ "⟺" LONG LEFT RIGHT DOUBLE ARROW
/*<!M><%less><%equal><%equal><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE523	,0x27F8	,0x0000), // ' ' ➔ "⟸" LONG LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal><%equal><~space>                              */ DEADTRANS( L' '	,0xE523	,0x27F8	,0x0000), // ' ' ➔ "⟸" LONG LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal><%grave>                                      */ DEADTRANS( L'`'	,0xE51B	,0x2AF9	,0x0000), // '`' ➔ "⫹" DOUBLE-LINE SLANTED LESS-THAN OR EQUAL TO
/*<!M><%less><%equal><%greater>                                    */ DEADTRANS( L'>'	,0xE51B	,0x21D4	,0x0000), // '>' ➔ "⇔" LEFT RIGHT DOUBLE ARROW
/*<!M><%less><%equal><%slash>                                      */ DEADTRANS( L'/'	,0xE51B	,0xE52A	,0x0001), // Multikey chain
/*<!M><%less><%equal><%slash><%greater>                            */ DEADTRANS( L'>'	,0xE52A	,0x21CE	,0x0000), // '>' ➔ "⇎" LEFT RIGHT DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal><%slash><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE52A	,0x21CD	,0x0000), // ' ' ➔ "⇍" LEFTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal><%slash><~space>                              */ DEADTRANS( L' '	,0xE52A	,0x21CD	,0x0000), // ' ' ➔ "⇍" LEFTWARDS DOUBLE ARROW WITH STROKE
/*<!M><%less><%equal><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE51B	,0x21D0	,0x0000), // ' ' ➔ "⇐" LEFTWARDS DOUBLE ARROW
/*<!M><%less><%equal><~space>                                      */ DEADTRANS( L' '	,0xE51B	,0x21D0	,0x0000), // ' ' ➔ "⇐" LEFTWARDS DOUBLE ARROW
/*<!M><%less><%exclam>                                             */ DEADTRANS( L'!'	,0xE4E8	,0xE530	,0x0001), // Multikey chain
/*<!M><%less><%exclam><%bar>                                       */ DEADTRANS( L'|'	,0xE530	,0xE531	,0x0001), // Multikey chain
/*<!M><%less><%exclam><%bar><%exclam>                              */ DEADTRANS( L'!'	,0xE531	,0x2909	,0x0000), // '!' ➔ "⤉" UPWARDS ARROW WITH HORIZONTAL STROKE
/*<!M><%less><%exclam><%bar><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE531	,0x21A5	,0x0000), // ' ' ➔ "↥" UPWARDS ARROW FROM BAR
/*<!M><%less><%exclam><%bar><~space>                               */ DEADTRANS( L' '	,0xE531	,0x21A5	,0x0000), // ' ' ➔ "↥" UPWARDS ARROW FROM BAR
/*<!M><%less><%exclam><%equal>                                     */ DEADTRANS( L'='	,0xE530	,0x21D1	,0x0000), // '=' ➔ "⇑" UPWARDS DOUBLE ARROW
/*<!M><%less><%exclam><%exclam>                                    */ DEADTRANS( L'!'	,0xE530	,0x21C5	,0x0000), // '!' ➔ "⇅" UPWARDS ARROW LEFTWARDS OF DOWNWARDS ARROW
/*<!M><%less><%exclam><%greater>                                   */ DEADTRANS( L'>'	,0xE530	,0xE537	,0x0001), // Multikey chain
/*<!M><%less><%exclam><%greater><%bar>                             */ DEADTRANS( L'|'	,0xE537	,0x21A8	,0x0000), // '|' ➔ "↨" UP DOWN ARROW WITH BASE
/*<!M><%less><%exclam><%greater><%equal>                           */ DEADTRANS( L'='	,0xE537	,0x21D5	,0x0000), // '=' ➔ "⇕" UP DOWN DOUBLE ARROW
/*<!M><%less><%exclam><%greater><2>                                */ DEADTRANS( L'2'	,0xE537	,0x21D5	,0x0000), // '2' ➔ "⇕" UP DOWN DOUBLE ARROW
/*<!M><%less><%exclam><%greater><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE537	,0x2195	,0x0000), // ' ' ➔ "↕" UP DOWN ARROW
/*<!M><%less><%exclam><%greater><~space>                           */ DEADTRANS( L' '	,0xE537	,0x2195	,0x0000), // ' ' ➔ "↕" UP DOWN ARROW
/*<!M><%less><%exclam><%less>                                      */ DEADTRANS( L'<'	,0xE530	,0xE53D	,0x0001), // Multikey chain
/*<!M><%less><%exclam><%less><%exclam>                             */ DEADTRANS( L'!'	,0xE53D	,0x21C8	,0x0000), // '!' ➔ "⇈" UPWARDS PAIRED ARROWS
/*<!M><%less><%exclam><2>                                          */ DEADTRANS( L'2'	,0xE530	,0x21D1	,0x0000), // '2' ➔ "⇑" UPWARDS DOUBLE ARROW
/*<!M><%less><%exclam><3>                                          */ DEADTRANS( L'3'	,0xE530	,0x290A	,0x0000), // '3' ➔ "⤊" UPWARDS TRIPLE ARROW
/*<!M><%less><%exclam><4>                                          */ DEADTRANS( L'4'	,0xE530	,0x27F0	,0x0000), // '4' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><%less><%exclam><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE530	,0x2191	,0x0000), // ' ' ➔ "↑" UPWARDS ARROW
/*<!M><%less><%exclam><~space>                                     */ DEADTRANS( L' '	,0xE530	,0x2191	,0x0000), // ' ' ➔ "↑" UPWARDS ARROW
/*<!M><%less><%greater>                                            */ DEADTRANS( L'>'	,0xE4E8	,0xE544	,0x0001), // Multikey chain
/*<!M><%less><%greater><%equal>                                    */ DEADTRANS( L'='	,0xE544	,0x2A91	,0x0000), // '=' ➔ "⪑" LESS-THAN ABOVE GREATER-THAN ABOVE DOUBLE-LINE EQUAL
/*<!M><%less><%greater><%less>                                     */ DEADTRANS( L'<'	,0xE544	,0xE546	,0x0001), // Multikey chain
/*<!M><%less><%greater><%less><%minus>                             */ DEADTRANS( L'-'	,0xE546	,0xE547	,0x0001), // Multikey chain
/*<!M><%less><%greater><%less><%minus><%bar>                       */ DEADTRANS( L'|'	,0xE547	,0x291F	,0x0000), // '|' ➔ "⤟" LEFTWARDS ARROW FROM BAR TO BLACK DIAMOND
/*<!M><%less><%greater><%less><%minus><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE547	,0x291D	,0x0000), // ' ' ➔ "⤝" LEFTWARDS ARROW TO BLACK DIAMOND
/*<!M><%less><%greater><%less><%minus><~space>                     */ DEADTRANS( L' '	,0xE547	,0x291D	,0x0000), // ' ' ➔ "⤝" LEFTWARDS ARROW TO BLACK DIAMOND
/*<!M><%less><%greater><%parenleft>                                */ DEADTRANS( L'('	,0xE544	,0xE54B	,0x0001), // Multikey chain
/*<!M><%less><%greater><%parenleft><%parenright>                   */ DEADTRANS( L')'	,0xE54B	,0xE54C	,0x0001), // Multikey chain
/*<!M><%less><%greater><%parenleft><%parenright><%minus>           */ DEADTRANS( L'-'	,0xE54C	,0x27E3	,0x0000), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%less><%greater><%parenleft><%parenright><~nbspace>         */ DEADTRANS( 0x00A0	,0xE54C	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenleft><%parenright><~space>           */ DEADTRANS( L' '	,0xE54C	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenright>                               */ DEADTRANS( L')'	,0xE544	,0xE550	,0x0001), // Multikey chain
/*<!M><%less><%greater><%parenright><%parenleft>                   */ DEADTRANS( L'('	,0xE550	,0xE551	,0x0001), // Multikey chain
/*<!M><%less><%greater><%parenright><%parenleft><%minus>           */ DEADTRANS( L'-'	,0xE551	,0x27E3	,0x0000), // '-' ➔ "⟣" WHITE CONCAVE-SIDED DIAMOND WITH RIGHTWARDS TICK
/*<!M><%less><%greater><%parenright><%parenleft><~nbspace>         */ DEADTRANS( 0x00A0	,0xE551	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%parenright><%parenleft><~space>           */ DEADTRANS( L' '	,0xE551	,0x27E1	,0x0000), // ' ' ➔ "⟡" WHITE CONCAVE-SIDED DIAMOND
/*<!M><%less><%greater><%slash>                                    */ DEADTRANS( L'/'	,0xE544	,0x2278	,0x0000), // '/' ➔ "≸" NEITHER LESS-THAN NOR GREATER-THAN
/*<!M><%less><%greater><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE544	,0x2276	,0x0000), // ' ' ➔ "≶" LESS-THAN OR GREATER-THAN
/*<!M><%less><%greater><~space>                                    */ DEADTRANS( L' '	,0xE544	,0x2276	,0x0000), // ' ' ➔ "≶" LESS-THAN OR GREATER-THAN
/*<!M><%less><%hash>                                               */ DEADTRANS( L'#'	,0xE4E8	,0xE558	,0x0001), // Multikey chain
/*<!M><%less><%hash><%greater>                                     */ DEADTRANS( L'>'	,0xE558	,0xE559	,0x0001), // Multikey chain
/*<!M><%less><%hash><%greater><%exclam>                            */ DEADTRANS( L'!'	,0xE559	,0x29EA	,0x0000), // '!' ➔ "⧪" BLACK DIAMOND WITH DOWN ARROW
/*<!M><%less><%hash><%greater><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE559	,0x25C6	,0x0000), // ' ' ➔ "◆" BLACK DIAMOND
/*<!M><%less><%hash><%greater><~space>                             */ DEADTRANS( L' '	,0xE559	,0x25C6	,0x0000), // ' ' ➔ "◆" BLACK DIAMOND
/*<!M><%less><%less>                                               */ DEADTRANS( L'<'	,0xE4E8	,0xE55D	,0x0001), // Multikey chain
/*<!M><%less><%less><%bar>                                         */ DEADTRANS( L'|'	,0xE55D	,0xE55E	,0x0001), // Multikey chain
/*<!M><%less><%less><%bar><%bar>                                   */ DEADTRANS( L'|'	,0xE55E	,0xE55F	,0x0001), // Multikey chain
/*<!M><%less><%less><%bar><%bar><%minus>                           */ DEADTRANS( L'-'	,0xE55F	,0xE560	,0x0001), // Multikey chain
/*<!M><%less><%less><%bar><%bar><%minus><%less>                    */ DEADTRANS( L'<'	,0xE560	,0x2B3D	,0x0000), // '<' ➔ "⬽" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%bar><%minus><~nbspace>                 */ DEADTRANS( 0x00A0	,0xE560	,0x2B35	,0x0000), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%bar><%minus><~space>                   */ DEADTRANS( L' '	,0xE560	,0x2B35	,0x0000), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE55E	,0xE564	,0x0001), // Multikey chain
/*<!M><%less><%less><%bar><%minus><%less>                          */ DEADTRANS( L'<'	,0xE564	,0x2B3C	,0x0000), // '<' ➔ "⬼" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE564	,0x2B34	,0x0000), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%bar><%minus><~space>                         */ DEADTRANS( L' '	,0xE564	,0x2B34	,0x0000), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%bracketleft>                                 */ DEADTRANS( L'['	,0xE55D	,0x27EA	,0x0000), // '[' ➔ "⟪" MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*<!M><%less><%less><%bracketright>                                */ DEADTRANS( L']'	,0xE55D	,0x27EA	,0x0000), // ']' ➔ "⟪" MATHEMATICAL LEFT DOUBLE ANGLE BRACKET
/*<!M><%less><%less><%exclam>                                      */ DEADTRANS( L'!'	,0xE55D	,0xE56A	,0x0001), // Multikey chain
/*<!M><%less><%less><%exclam><o>                                   */ DEADTRANS( L'o'	,0xE56A	,0x2949	,0x0000), // 'o' ➔ "⥉" UPWARDS TWO-HEADED ARROW FROM SMALL CIRCLE
/*<!M><%less><%less><%exclam><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE56A	,0x219F	,0x0000), // ' ' ➔ "↟" UPWARDS TWO HEADED ARROW
/*<!M><%less><%less><%exclam><~space>                              */ DEADTRANS( L' '	,0xE56A	,0x219F	,0x0000), // ' ' ➔ "↟" UPWARDS TWO HEADED ARROW
/*<!M><%less><%less><%minus>                                       */ DEADTRANS( L'-'	,0xE55D	,0xE56E	,0x0001), // Multikey chain
/*<!M><%less><%less><%minus><%bar>                                 */ DEADTRANS( L'|'	,0xE56E	,0xE56F	,0x0001), // Multikey chain
/*<!M><%less><%less><%minus><%bar><%bar>                           */ DEADTRANS( L'|'	,0xE56F	,0xE570	,0x0001), // Multikey chain
/*<!M><%less><%less><%minus><%bar><%bar><%minus>                   */ DEADTRANS( L'-'	,0xE570	,0xE571	,0x0001), // Multikey chain
/*<!M><%less><%less><%minus><%bar><%bar><%minus><%less>            */ DEADTRANS( L'<'	,0xE571	,0x2B3D	,0x0000), // '<' ➔ "⬽" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%bar><%minus><~nbspace>         */ DEADTRANS( 0x00A0	,0xE571	,0x2B35	,0x0000), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%bar><%minus><~space>           */ DEADTRANS( L' '	,0xE571	,0x2B35	,0x0000), // ' ' ➔ "⬵" LEFTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus>                         */ DEADTRANS( L'-'	,0xE56F	,0xE575	,0x0001), // Multikey chain
/*<!M><%less><%less><%minus><%bar><%minus><%less>                  */ DEADTRANS( L'<'	,0xE575	,0x2B3C	,0x0000), // '<' ➔ "⬼" LEFTWARDS TWO-HEADED ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus><~nbspace>               */ DEADTRANS( 0x00A0	,0xE575	,0x2B34	,0x0000), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%minus><%bar><%minus><~space>                 */ DEADTRANS( L' '	,0xE575	,0x2B34	,0x0000), // ' ' ➔ "⬴" LEFTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%less><%less><%minus><%less>                                */ DEADTRANS( L'<'	,0xE56E	,0x2B3B	,0x0000), // '<' ➔ "⬻" LEFTWARDS TWO-HEADED ARROW WITH TAIL
/*<!M><%less><%less><%minus><0>                                    */ DEADTRANS( L'0'	,0xE56E	,0x2B37	,0x0000), // '0' ➔ "⬷" LEFTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%less><%less><%minus><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE56E	,0x219E	,0x0000), // ' ' ➔ "↞" LEFTWARDS TWO HEADED ARROW
/*<!M><%less><%less><%minus><~space>                               */ DEADTRANS( L' '	,0xE56E	,0x219E	,0x0000), // ' ' ➔ "↞" LEFTWARDS TWO HEADED ARROW
/*<!M><%less><%less><%parenleft>                                   */ DEADTRANS( L'('	,0xE55D	,0x2ABB	,0x0000), // '(' ➔ "⪻" DOUBLE PRECEDES
/*<!M><%less><%less><%parenright>                                  */ DEADTRANS( L')'	,0xE55D	,0x2ABB	,0x0000), // ')' ➔ "⪻" DOUBLE PRECEDES
/*<!M><%less><%minus>                                              */ DEADTRANS( L'-'	,0xE4E8	,0xE57F	,0x0001), // Multikey chain
/*<!M><%less><%minus><%bar>                                        */ DEADTRANS( L'|'	,0xE57F	,0xE580	,0x0001), // Multikey chain
/*<!M><%less><%minus><%bar><%bar>                                  */ DEADTRANS( L'|'	,0xE580	,0xE581	,0x0001), // Multikey chain
/*<!M><%less><%minus><%bar><%bar><%minus>                          */ DEADTRANS( L'-'	,0xE581	,0xE582	,0x0001), // Multikey chain
/*<!M><%less><%minus><%bar><%bar><%minus><%greater>                */ DEADTRANS( L'>'	,0xE582	,0x21FC	,0x0000), // '>' ➔ "⇼" LEFT RIGHT ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus><%less>                   */ DEADTRANS( L'<'	,0xE582	,0x2B3A	,0x0000), // '<' ➔ "⬺" LEFTWARDS ARROW WITH TAIL WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus><~nbspace>                */ DEADTRANS( 0x00A0	,0xE582	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><%minus><~space>                  */ DEADTRANS( L' '	,0xE582	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE581	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%bar><~space>                          */ DEADTRANS( L' '	,0xE581	,0x21FA	,0x0000), // ' ' ➔ "⇺" LEFTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%less><%minus><%bar><%greater>                              */ DEADTRANS( L'>'	,0xE580	,0x21F9	,0x0000), // '>' ➔ "⇹" LEFT RIGHT ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus>                                */ DEADTRANS( L'-'	,0xE580	,0xE58A	,0x0001), // Multikey chain
/*<!M><%less><%minus><%bar><%minus><%greater>                      */ DEADTRANS( L'>'	,0xE58A	,0x21F9	,0x0000), // '>' ➔ "⇹" LEFT RIGHT ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus><%less>                         */ DEADTRANS( L'<'	,0xE58A	,0x2B39	,0x0000), // '<' ➔ "⬹" LEFTWARDS ARROW WITH TAIL WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE58A	,0x21F7	,0x0000), // ' ' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><%minus><~space>                        */ DEADTRANS( L' '	,0xE58A	,0x21F7	,0x0000), // ' ' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%less><%minus><%bar><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE580	,0x21A4	,0x0000), // ' ' ➔ "↤" LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%bar><~space>                                */ DEADTRANS( L' '	,0xE580	,0x21A4	,0x0000), // ' ' ➔ "↤" LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%comma>                                      */ DEADTRANS( L','	,0xE57F	,0xE591	,0x0001), // Multikey chain
/*<!M><%less><%minus><%comma><%exclam>                             */ DEADTRANS( L'!'	,0xE591	,0x2936	,0x0000), // '!' ➔ "⤶" ARROW POINTING DOWNWARDS THEN CURVING LEFTWARDS
/*<!M><%less><%minus><%comma><%minus>                              */ DEADTRANS( L'-'	,0xE591	,0xDCD8	,0x0000), // High surrogate: D83E; U+1F8D8 '-' ➔ "🣘" LONG LEFT RIGHT ARROW WITH DEPENDENT LOBE
/*<!M><%less><%minus><%exclam>                                     */ DEADTRANS( L'!'	,0xE57F	,0x21B0	,0x0000), // '!' ➔ "↰" UPWARDS ARROW WITH TIP LEFTWARDS
/*<!M><%less><%minus><%greater>                                    */ DEADTRANS( L'>'	,0xE57F	,0x2194	,0x0000), // '>' ➔ "↔" LEFT RIGHT ARROW
/*<!M><%less><%minus><%less>                                       */ DEADTRANS( L'<'	,0xE57F	,0xE596	,0x0001), // Multikey chain
/*<!M><%less><%minus><%less><%minus>                               */ DEADTRANS( L'-'	,0xE596	,0xE597	,0x0001), // Multikey chain
/*<!M><%less><%minus><%less><%minus><%less>                        */ DEADTRANS( L'<'	,0xE597	,0x2B31	,0x0000), // '<' ➔ "⬱" THREE LEFTWARDS ARROWS
/*<!M><%less><%minus><%less><%minus><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE597	,0x21C7	,0x0000), // ' ' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><%less><%minus><%less><%minus><~space>                       */ DEADTRANS( L' '	,0xE597	,0x21C7	,0x0000), // ' ' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><%less><%minus><%less><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE596	,0x21A2	,0x0000), // ' ' ➔ "↢" LEFTWARDS ARROW WITH TAIL
/*<!M><%less><%minus><%less><~space>                               */ DEADTRANS( L' '	,0xE596	,0x21A2	,0x0000), // ' ' ➔ "↢" LEFTWARDS ARROW WITH TAIL
/*<!M><%less><%minus><%minus>                                      */ DEADTRANS( L'-'	,0xE57F	,0xE59D	,0x0001), // Multikey chain
/*<!M><%less><%minus><%minus><%bar>                                */ DEADTRANS( L'|'	,0xE59D	,0x27FB	,0x0000), // '|' ➔ "⟻" LONG LEFTWARDS ARROW FROM BAR
/*<!M><%less><%minus><%minus><%greater>                            */ DEADTRANS( L'>'	,0xE59D	,0x21C6	,0x0000), // '>' ➔ "⇆" LEFTWARDS ARROW OVER RIGHTWARDS ARROW
/*<!M><%less><%minus><%minus><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE59D	,0x27F5	,0x0000), // ' ' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><%less><%minus><%minus><~space>                              */ DEADTRANS( L' '	,0xE59D	,0x27F5	,0x0000), // ' ' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><%less><%minus><%parenright>                                 */ DEADTRANS( L')'	,0xE57F	,0x21A9	,0x0000), // ')' ➔ "↩" LEFTWARDS ARROW WITH HOOK
/*<!M><%less><%minus><%period>                                     */ DEADTRANS( L'.'	,0xE57F	,0x2943	,0x0000), // '.' ➔ "⥃" LEFTWARDS ARROW ABOVE SHORT RIGHTWARDS ARROW
/*<!M><%less><%minus><%plus>                                       */ DEADTRANS( L'+'	,0xE57F	,0x2946	,0x0000), // '+' ➔ "⥆" LEFTWARDS ARROW WITH PLUS BELOW
/*<!M><%less><%minus><%slash>                                      */ DEADTRANS( L'/'	,0xE57F	,0xE5A5	,0x0001), // Multikey chain
/*<!M><%less><%minus><%slash><%minus>                              */ DEADTRANS( L'-'	,0xE5A5	,0x21AE	,0x0000), // '-' ➔ "↮" LEFT RIGHT ARROW WITH STROKE
/*<!M><%less><%minus><%slash><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE5A5	,0x219A	,0x0000), // ' ' ➔ "↚" LEFTWARDS ARROW WITH STROKE
/*<!M><%less><%minus><%slash><~space>                              */ DEADTRANS( L' '	,0xE5A5	,0x219A	,0x0000), // ' ' ➔ "↚" LEFTWARDS ARROW WITH STROKE
/*<!M><%less><%minus><%tilde>                                      */ DEADTRANS( L'~'	,0xE57F	,0xE5A9	,0x0001), // Multikey chain
/*<!M><%less><%minus><%tilde><%backslash>                          */ DEADTRANS( L'\\'	,0xE5A9	,0x2B4B	,0x0000), // '\' ➔ "⭋" LEFTWARDS ARROW ABOVE REVERSE TILDE OPERATOR
/*<!M><%less><%minus><%tilde><%tilde>                              */ DEADTRANS( L'~'	,0xE5A9	,0xE5AB	,0x0001), // Multikey chain
/*<!M><%less><%minus><%tilde><%tilde><%backslash>                  */ DEADTRANS( L'\\'	,0xE5AB	,0x2B42	,0x0000), // '\' ➔ "⭂" LEFTWARDS ARROW ABOVE REVERSE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde><%tilde><~nbspace>                    */ DEADTRANS( 0x00A0	,0xE5AB	,0x2B4A	,0x0000), // ' ' ➔ "⭊" LEFTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde><%tilde><~space>                      */ DEADTRANS( L' '	,0xE5AB	,0x2B4A	,0x0000), // ' ' ➔ "⭊" LEFTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%less><%minus><%tilde><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE5A9	,0x2B3F	,0x0000), // ' ' ➔ "⬿" WAVE ARROW POINTING DIRECTLY LEFT
/*<!M><%less><%minus><%tilde><~space>                              */ DEADTRANS( L' '	,0xE5A9	,0x2B3F	,0x0000), // ' ' ➔ "⬿" WAVE ARROW POINTING DIRECTLY LEFT
/*<!M><%less><%minus><%underscore>                                 */ DEADTRANS( L'_'	,0xE57F	,0x2AAC	,0x0000), // '_' ➔ "⪬" SMALLER THAN OR EQUAL TO
/*<!M><%less><%minus><0>                                           */ DEADTRANS( L'0'	,0xE57F	,0xE5B2	,0x0001), // Multikey chain
/*<!M><%less><%minus><0><%minus>                                   */ DEADTRANS( L'-'	,0xE5B2	,0xE5B3	,0x0001), // Multikey chain
/*<!M><%less><%minus><0><%minus><0>                                */ DEADTRANS( L'0'	,0xE5B3	,0x290E	,0x0000), // '0' ➔ "⤎" LEFTWARDS TRIPLE DASH ARROW
/*<!M><%less><%minus><0><%minus><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE5B3	,0x290C	,0x0000), // ' ' ➔ "⤌" LEFTWARDS DOUBLE DASH ARROW
/*<!M><%less><%minus><0><%minus><~space>                           */ DEADTRANS( L' '	,0xE5B3	,0x290C	,0x0000), // ' ' ➔ "⤌" LEFTWARDS DOUBLE DASH ARROW
/*<!M><%less><%minus><3>                                           */ DEADTRANS( L'3'	,0xE57F	,0x21DA	,0x0000), // '3' ➔ "⇚" LEFTWARDS TRIPLE ARROW
/*<!M><%less><%minus><4>                                           */ DEADTRANS( L'4'	,0xE57F	,0x2B45	,0x0000), // '4' ➔ "⭅" LEFTWARDS QUADRUPLE ARROW
/*<!M><%less><%minus><c>                                           */ DEADTRANS( L'c'	,0xE57F	,0x297A	,0x0000), // 'c' ➔ "⥺" LEFTWARDS ARROW THROUGH SUBSET
/*<!M><%less><%minus><o>                                           */ DEADTRANS( L'o'	,0xE57F	,0xE5BA	,0x0001), // Multikey chain
/*<!M><%less><%minus><O>                                           */ DEADTRANS( L'O'	,0xE57F	,0xE5BB	,0x0001), // Multikey chain
/*<!M><%less><%minus><o><%minus>                                   */ DEADTRANS( L'-'	,0xE5BA	,0xE5BD	,0x0001), // Multikey chain
/*<!M><%less><%minus><O><%minus>                                   */ DEADTRANS( L'-'	,0xE5BB	,0xDCD8	,0x0000), // High surrogate: D83E; U+1F8D8 '-' ➔ "🣘" LONG LEFT RIGHT ARROW WITH DEPENDENT LOBE
/*<!M><%less><%minus><o><%minus><%greater>                         */ DEADTRANS( L'>'	,0xE5BD	,0x2948	,0x0000), // '>' ➔ "⥈" LEFT RIGHT ARROW THROUGH SMALL CIRCLE
/*<!M><%less><%minus><o><%minus><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE5BD	,0x2B30	,0x0000), // ' ' ➔ "⬰" LEFT ARROW WITH SMALL CIRCLE
/*<!M><%less><%minus><o><%minus><~space>                           */ DEADTRANS( L' '	,0xE5BD	,0x2B30	,0x0000), // ' ' ➔ "⬰" LEFT ARROW WITH SMALL CIRCLE
/*<!M><%less><%minus><o><%plus>                                    */ DEADTRANS( L'+'	,0xE5BA	,0x2B32	,0x0000), // '+' ➔ "⬲" LEFT ARROW WITH CIRCLED PLUS
/*<!M><%less><%minus><O><%plus>                                    */ DEADTRANS( L'+'	,0xE5BB	,0x2B32	,0x0000), // '+' ➔ "⬲" LEFT ARROW WITH CIRCLED PLUS
/*<!M><%less><%minus><O><%slash>                                   */ DEADTRANS( L'/'	,0xE5BB	,0x29B4	,0x0000), // '/' ➔ "⦴" EMPTY SET WITH LEFT ARROW ABOVE
/*<!M><%less><%minus><o><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE5BA	,0x21AB	,0x0000), // ' ' ➔ "↫" LEFTWARDS ARROW WITH LOOP
/*<!M><%less><%minus><o><~space>                                   */ DEADTRANS( L' '	,0xE5BA	,0x21AB	,0x0000), // ' ' ➔ "↫" LEFTWARDS ARROW WITH LOOP
/*<!M><%less><%minus><x>                                           */ DEADTRANS( L'x'	,0xE57F	,0x2B3E	,0x0000), // 'x' ➔ "⬾" LEFTWARDS ARROW THROUGH X
/*<!M><%less><%minus><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE57F	,0x2190	,0x0000), // ' ' ➔ "←" LEFTWARDS ARROW
/*<!M><%less><%minus><~space>                                      */ DEADTRANS( L' '	,0xE57F	,0x2190	,0x0000), // ' ' ➔ "←" LEFTWARDS ARROW
/*<!M><%less><%parenleft>                                          */ DEADTRANS( L'('	,0xE4E8	,0xE5C9	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright>                             */ DEADTRANS( L')'	,0xE5C9	,0xE5CA	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright><%bracketleft>               */ DEADTRANS( L'['	,0xE5CA	,0x29FC	,0x0000), // '[' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenleft><%parenright><%bracketright>              */ DEADTRANS( L']'	,0xE5CA	,0x29FC	,0x0000), // ']' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenleft><%parenright><%equal>                     */ DEADTRANS( L'='	,0xE5CA	,0xE5CD	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright><%equal><%slash>             */ DEADTRANS( L'/'	,0xE5CD	,0x2AB5	,0x0000), // '/' ➔ "⪵" PRECEDES ABOVE NOT EQUAL TO
/*<!M><%less><%parenleft><%parenright><%equal><~nbspace>           */ DEADTRANS( 0x00A0	,0xE5CD	,0x2AB3	,0x0000), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><%equal><~space>             */ DEADTRANS( L' '	,0xE5CD	,0x2AB3	,0x0000), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><%slash>                     */ DEADTRANS( L'/'	,0xE5CA	,0x2280	,0x0000), // '/' ➔ "⊀" DOES NOT PRECEDE
/*<!M><%less><%parenleft><%parenright><%tilde>                     */ DEADTRANS( L'~'	,0xE5CA	,0xE5D2	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright><%tilde><%slash>             */ DEADTRANS( L'/'	,0xE5D2	,0x22E8	,0x0000), // '/' ➔ "⋨" PRECEDES BUT NOT EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde>             */ DEADTRANS( L'~'	,0xE5D2	,0xE5D4	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde><%slash>     */ DEADTRANS( L'/'	,0xE5D4	,0x2AB9	,0x0000), // '/' ➔ "⪹" PRECEDES ABOVE NOT ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde><~nbspace>   */ DEADTRANS( 0x00A0	,0xE5D4	,0x2AB7	,0x0000), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde><%tilde><~space>     */ DEADTRANS( L' '	,0xE5D4	,0x2AB7	,0x0000), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenleft><%parenright><%tilde><~nbspace>           */ DEADTRANS( 0x00A0	,0xE5D2	,0x227E	,0x0000), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%tilde><~space>             */ DEADTRANS( L' '	,0xE5D2	,0x227E	,0x0000), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenleft><%parenright><%underscore>                */ DEADTRANS( L'_'	,0xE5CA	,0xE5DA	,0x0001), // Multikey chain
/*<!M><%less><%parenleft><%parenright><%underscore><%slash>        */ DEADTRANS( L'/'	,0xE5DA	,0x2AB1	,0x0000), // '/' ➔ "⪱" PRECEDES ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%parenleft><%parenright><%underscore><~nbspace>      */ DEADTRANS( 0x00A0	,0xE5DA	,0x2AAF	,0x0000), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><%underscore><~space>        */ DEADTRANS( L' '	,0xE5DA	,0x2AAF	,0x0000), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenleft><%parenright><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE5CA	,0x227A	,0x0000), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenleft><%parenright><~space>                     */ DEADTRANS( L' '	,0xE5CA	,0x227A	,0x0000), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenleft><%plus>                                   */ DEADTRANS( L'+'	,0xE5C9	,0x293D	,0x0000), // '+' ➔ "⤽" TOP ARC ANTICLOCKWISE ARROW WITH PLUS
/*<!M><%less><%parenleft><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE5C9	,0x293A	,0x0000), // ' ' ➔ "⤺" TOP ARC ANTICLOCKWISE ARROW
/*<!M><%less><%parenleft><~space>                                  */ DEADTRANS( L' '	,0xE5C9	,0x293A	,0x0000), // ' ' ➔ "⤺" TOP ARC ANTICLOCKWISE ARROW
/*<!M><%less><%parenright>                                         */ DEADTRANS( L')'	,0xE4E8	,0xE5E3	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft>                             */ DEADTRANS( L'('	,0xE5E3	,0xE5E4	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft><%bracketleft>               */ DEADTRANS( L'['	,0xE5E4	,0x29FC	,0x0000), // '[' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenright><%parenleft><%bracketright>              */ DEADTRANS( L']'	,0xE5E4	,0x29FC	,0x0000), // ']' ➔ "⧼" LEFT-POINTING CURVED ANGLE BRACKET
/*<!M><%less><%parenright><%parenleft><%equal>                     */ DEADTRANS( L'='	,0xE5E4	,0xE5E7	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft><%equal><%slash>             */ DEADTRANS( L'/'	,0xE5E7	,0x2AB5	,0x0000), // '/' ➔ "⪵" PRECEDES ABOVE NOT EQUAL TO
/*<!M><%less><%parenright><%parenleft><%equal><~nbspace>           */ DEADTRANS( 0x00A0	,0xE5E7	,0x2AB3	,0x0000), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><%equal><~space>             */ DEADTRANS( L' '	,0xE5E7	,0x2AB3	,0x0000), // ' ' ➔ "⪳" PRECEDES ABOVE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><%slash>                     */ DEADTRANS( L'/'	,0xE5E4	,0x2280	,0x0000), // '/' ➔ "⊀" DOES NOT PRECEDE
/*<!M><%less><%parenright><%parenleft><%tilde>                     */ DEADTRANS( L'~'	,0xE5E4	,0xE5EC	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft><%tilde><%slash>             */ DEADTRANS( L'/'	,0xE5EC	,0x22E8	,0x0000), // '/' ➔ "⋨" PRECEDES BUT NOT EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde>             */ DEADTRANS( L'~'	,0xE5EC	,0xE5EE	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde><%slash>     */ DEADTRANS( L'/'	,0xE5EE	,0x2AB9	,0x0000), // '/' ➔ "⪹" PRECEDES ABOVE NOT ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde><~nbspace>   */ DEADTRANS( 0x00A0	,0xE5EE	,0x2AB7	,0x0000), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde><%tilde><~space>     */ DEADTRANS( L' '	,0xE5EE	,0x2AB7	,0x0000), // ' ' ➔ "⪷" PRECEDES ABOVE ALMOST EQUAL TO
/*<!M><%less><%parenright><%parenleft><%tilde><~nbspace>           */ DEADTRANS( 0x00A0	,0xE5EC	,0x227E	,0x0000), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%tilde><~space>             */ DEADTRANS( L' '	,0xE5EC	,0x227E	,0x0000), // ' ' ➔ "≾" PRECEDES OR EQUIVALENT TO
/*<!M><%less><%parenright><%parenleft><%underscore>                */ DEADTRANS( L'_'	,0xE5E4	,0xE5F4	,0x0001), // Multikey chain
/*<!M><%less><%parenright><%parenleft><%underscore><%slash>        */ DEADTRANS( L'/'	,0xE5F4	,0x2AB1	,0x0000), // '/' ➔ "⪱" PRECEDES ABOVE SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%parenright><%parenleft><%underscore><~nbspace>      */ DEADTRANS( 0x00A0	,0xE5F4	,0x2AAF	,0x0000), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><%underscore><~space>        */ DEADTRANS( L' '	,0xE5F4	,0x2AAF	,0x0000), // ' ' ➔ "⪯" PRECEDES ABOVE SINGLE-LINE EQUALS SIGN
/*<!M><%less><%parenright><%parenleft><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE5E4	,0x227A	,0x0000), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenright><%parenleft><~space>                     */ DEADTRANS( L' '	,0xE5E4	,0x227A	,0x0000), // ' ' ➔ "≺" PRECEDES
/*<!M><%less><%parenright><%parenright>                            */ DEADTRANS( L')'	,0xE5E3	,0x2996	,0x0000), // ')' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%less><%parenright><%underscore>                            */ DEADTRANS( L'_'	,0xE5E3	,0x2AA8	,0x0000), // '_' ➔ "⪨" LESS-THAN CLOSED BY CURVE ABOVE SLANTED EQUAL
/*<!M><%less><%period>                                             */ DEADTRANS( L'.'	,0xE4E8	,0xE5FC	,0x0001), // Multikey chain
/*<!M><%less><%period><%greater>                                   */ DEADTRANS( L'>'	,0xE5FC	,0x27D0	,0x0000), // '>' ➔ "⟐" WHITE DIAMOND WITH CENTRED DOT
/*<!M><%less><%period><%period>                                    */ DEADTRANS( L'.'	,0xE5FC	,0x2B38	,0x0000), // '.' ➔ "⬸" LEFTWARDS ARROW WITH DOTTED STEM
/*<!M><%less><%period><%underscore>                                */ DEADTRANS( L'_'	,0xE5FC	,0x2A83	,0x0000), // '_' ➔ "⪃" LESS-THAN OR SLANTED EQUAL TO WITH DOT ABOVE RIGHT
/*<!M><%less><%period><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE5FC	,0x22D6	,0x0000), // ' ' ➔ "⋖" LESS-THAN WITH DOT
/*<!M><%less><%period><~space>                                     */ DEADTRANS( L' '	,0xE5FC	,0x22D6	,0x0000), // ' ' ➔ "⋖" LESS-THAN WITH DOT
/*<!M><%less><%slash>                                              */ DEADTRANS( L'/'	,0xE4E8	,0xE602	,0x0001), // Multikey chain
/*<!M><%less><%slash><%equal>                                      */ DEADTRANS( L'='	,0xE602	,0x21D9	,0x0000), // '=' ➔ "⇙" SOUTH WEST DOUBLE ARROW
/*<!M><%less><%slash><%greater>                                    */ DEADTRANS( L'>'	,0xE602	,0x2922	,0x0000), // '>' ➔ "⤢" NORTH EAST AND SOUTH WEST ARROW
/*<!M><%less><%slash><%parenleft>                                  */ DEADTRANS( L'('	,0xE602	,0x29AF	,0x0000), // '(' ➔ "⦯" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING LEFT AND DOWN
/*<!M><%less><%slash><%parenright>                                 */ DEADTRANS( L')'	,0xE602	,0x2926	,0x0000), // ')' ➔ "⤦" SOUTH WEST ARROW WITH HOOK
/*<!M><%less><%slash><%tilde>                                      */ DEADTRANS( L'~'	,0xE602	,0x2274	,0x0000), // '~' ➔ "≴" NEITHER LESS-THAN NOR EQUIVALENT TO
/*<!M><%less><%slash><%underscore>                                 */ DEADTRANS( L'_'	,0xE602	,0x2270	,0x0000), // '_' ➔ "≰" NEITHER LESS-THAN NOR EQUAL TO
/*<!M><%less><%slash><2>                                           */ DEADTRANS( L'2'	,0xE602	,0x21D9	,0x0000), // '2' ➔ "⇙" SOUTH WEST DOUBLE ARROW
/*<!M><%less><%slash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE602	,0x2199	,0x0000), // ' ' ➔ "↙" SOUTH WEST ARROW
/*<!M><%less><%slash><~space>                                      */ DEADTRANS( L' '	,0xE602	,0x2199	,0x0000), // ' ' ➔ "↙" SOUTH WEST ARROW
/*<!M><%less><%tilde>                                              */ DEADTRANS( L'~'	,0xE4E8	,0xE60C	,0x0001), // Multikey chain
/*<!M><%less><%tilde><%greater>                                    */ DEADTRANS( L'>'	,0xE60C	,0x2A8F	,0x0000), // '>' ➔ "⪏" LESS-THAN ABOVE SIMILAR ABOVE GREATER-THAN
/*<!M><%less><%tilde><%minus>                                      */ DEADTRANS( L'-'	,0xE60C	,0x2A8D	,0x0000), // '-' ➔ "⪍" LESS-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%less><%tilde><%slash>                                      */ DEADTRANS( L'/'	,0xE60C	,0x22E6	,0x0000), // '/' ➔ "⋦" LESS-THAN BUT NOT EQUIVALENT TO
/*<!M><%less><%tilde><%tilde>                                      */ DEADTRANS( L'~'	,0xE60C	,0xE610	,0x0001), // Multikey chain
/*<!M><%less><%tilde><%tilde><%slash>                              */ DEADTRANS( L'/'	,0xE610	,0x2A89	,0x0000), // '/' ➔ "⪉" LESS-THAN AND NOT APPROXIMATE
/*<!M><%less><%tilde><%tilde><%tilde>                              */ DEADTRANS( L'~'	,0xE610	,0x2B33	,0x0000), // '~' ➔ "⬳" LONG LEFTWARDS SQUIGGLE ARROW
/*<!M><%less><%tilde><%tilde><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE610	,0x2A85	,0x0000), // ' ' ➔ "⪅" LESS-THAN OR APPROXIMATE
/*<!M><%less><%tilde><%tilde><~space>                              */ DEADTRANS( L' '	,0xE610	,0x2A85	,0x0000), // ' ' ➔ "⪅" LESS-THAN OR APPROXIMATE
/*<!M><%less><%tilde><%underscore>                                 */ DEADTRANS( L'_'	,0xE60C	,0x2A8D	,0x0000), // '_' ➔ "⪍" LESS-THAN ABOVE SIMILAR OR EQUAL
/*<!M><%less><%tilde><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE60C	,0x219C	,0x0000), // ' ' ➔ "↜" LEFTWARDS WAVE ARROW
/*<!M><%less><%tilde><~space>                                      */ DEADTRANS( L' '	,0xE60C	,0x219C	,0x0000), // ' ' ➔ "↜" LEFTWARDS WAVE ARROW
/*<!M><%less><%underscore>                                         */ DEADTRANS( L'_'	,0xE4E8	,0xE618	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%grave>                                 */ DEADTRANS( L'`'	,0xE618	,0x2A7D	,0x0000), // '`' ➔ "⩽" LESS-THAN OR SLANTED EQUAL TO
/*<!M><%less><%underscore><%greater>                               */ DEADTRANS( L'>'	,0xE618	,0xE61A	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%greater><%underscore>                  */ DEADTRANS( L'_'	,0xE61A	,0x2A93	,0x0000), // '_' ➔ "⪓" LESS-THAN ABOVE SLANTED EQUAL ABOVE GREATER-THAN ABOVE SLANTED EQUAL
/*<!M><%less><%underscore><%greater><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE61A	,0x22DA	,0x0000), // ' ' ➔ "⋚" LESS-THAN EQUAL TO OR GREATER-THAN
/*<!M><%less><%underscore><%greater><~space>                       */ DEADTRANS( L' '	,0xE61A	,0x22DA	,0x0000), // ' ' ➔ "⋚" LESS-THAN EQUAL TO OR GREATER-THAN
/*<!M><%less><%underscore><%parenleft>                             */ DEADTRANS( L'('	,0xE618	,0xE61E	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%parenleft><%parenright>                */ DEADTRANS( L')'	,0xE61E	,0xE61F	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%parenleft><%parenright><%slash>        */ DEADTRANS( L'/'	,0xE61F	,0x22E0	,0x0000), // '/' ➔ "⋠" DOES NOT PRECEDE OR EQUAL
/*<!M><%less><%underscore><%parenleft><%parenright><~nbspace>      */ DEADTRANS( 0x00A0	,0xE61F	,0x227C	,0x0000), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenleft><%parenright><~space>        */ DEADTRANS( L' '	,0xE61F	,0x227C	,0x0000), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenright>                            */ DEADTRANS( L')'	,0xE618	,0xE623	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%parenright><%parenleft>                */ DEADTRANS( L'('	,0xE623	,0xE624	,0x0001), // Multikey chain
/*<!M><%less><%underscore><%parenright><%parenleft><%slash>        */ DEADTRANS( L'/'	,0xE624	,0x22E0	,0x0000), // '/' ➔ "⋠" DOES NOT PRECEDE OR EQUAL
/*<!M><%less><%underscore><%parenright><%parenleft><~nbspace>      */ DEADTRANS( 0x00A0	,0xE624	,0x227C	,0x0000), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%parenright><%parenleft><~space>        */ DEADTRANS( L' '	,0xE624	,0x227C	,0x0000), // ' ' ➔ "≼" PRECEDES OR EQUAL TO
/*<!M><%less><%underscore><%period>                                */ DEADTRANS( L'.'	,0xE618	,0x2A7F	,0x0000), // '.' ➔ "⩿" LESS-THAN OR SLANTED EQUAL TO WITH DOT INSIDE
/*<!M><%less><%underscore><%slash>                                 */ DEADTRANS( L'/'	,0xE618	,0x2A87	,0x0000), // '/' ➔ "⪇" LESS-THAN AND SINGLE-LINE NOT EQUAL TO
/*<!M><%less><%underscore><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE618	,0x2264	,0x0000), // ' ' ➔ "≤" LESS-THAN OR EQUAL TO
/*<!M><%less><%underscore><~space>                                 */ DEADTRANS( L' '	,0xE618	,0x2264	,0x0000), // ' ' ➔ "≤" LESS-THAN OR EQUAL TO
/*<!M><%less><0>                                                   */ DEADTRANS( L'0'	,0xE4E8	,0x27A3	,0x0000), // '0' ➔ "➣" THREE-D BOTTOM-LIGHTED RIGHTWARDS ARROWHEAD
/*<!M><%less><1>                                                   */ DEADTRANS( L'1'	,0xE4E8	,0x2022	,0x0000), // '1' ➔ "•" BULLET
/*<!M><%less><2>                                                   */ DEADTRANS( L'2'	,0xE4E8	,0x25E6	,0x0000), // '2' ➔ "◦" WHITE BULLET
/*<!M><%less><3>                                                   */ DEADTRANS( L'3'	,0xE4E8	,0x2764	,0x0000), // '3' ➔ "❤" HEAVY BLACK HEART emoji, red heart, most-used in France
/*<!M><%less><4>                                                   */ DEADTRANS( L'4'	,0xE4E8	,0x25AA	,0x0000), // '4' ➔ "▪" BLACK SMALL SQUARE emoji
/*<!M><%less><5>                                                   */ DEADTRANS( L'5'	,0xE4E8	,0x25AB	,0x0000), // '5' ➔ "▫" WHITE SMALL SQUARE emoji
/*<!M><%less><6>                                                   */ DEADTRANS( L'6'	,0xE4E8	,0x2023	,0x0000), // '6' ➔ "‣" TRIANGULAR BULLET
/*<!M><%less><7>                                                   */ DEADTRANS( L'7'	,0xE4E8	,0x25B9	,0x0000), // '7' ➔ "▹" WHITE RIGHT-POINTING SMALL TRIANGLE
/*<!M><%less><8>                                                   */ DEADTRANS( L'8'	,0xE4E8	,0x2665	,0x0000), // '8' ➔ "♥" BLACK HEART SUIT red emoji, 14th-ranking
/*<!M><%less><9>                                                   */ DEADTRANS( L'9'	,0xE4E8	,0x27A2	,0x0000), // '9' ➔ "➢" THREE-D TOP-LIGHTED RIGHTWARDS ARROWHEAD
/*<!M><%minus>                                                     */ DEADTRANS( L'-'	,0x00A6	,0xE636	,0x0001), // Multikey chain
/*<!M><%minus><%apostrophe>                                        */ DEADTRANS( L'\''	,0xE636	,0xE637	,0x0001), // Multikey chain
/*<!M><%minus><%apostrophe><%apostrophe>                           */ DEADTRANS( L'\''	,0xE637	,0x22B9	,0x0000), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><%minus><%apostrophe><%bar>                                  */ DEADTRANS( L'|'	,0xE637	,0x2957	,0x0000), // '|' ➔ "⥗" RIGHTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%minus><%apostrophe><%grave>                                */ DEADTRANS( L'`'	,0xE637	,0x2969	,0x0000), // '`' ➔ "⥩" RIGHTWARDS HARPOON WITH BARB DOWN ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%apostrophe><%minus>                                */ DEADTRANS( L'-'	,0xE637	,0x2AE0	,0x0000), // '-' ➔ "⫠" SHORT UP TACK
/*<!M><%minus><%apostrophe><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE637	,0x00AC	,0x0000), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%apostrophe><~space>                                */ DEADTRANS( L' '	,0xE637	,0x00AC	,0x0000), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%aprightsingquotmark>                               */ DEADTRANS( 0x2019	,0xE636	,0xE63E	,0x0001), // Multikey chain
/*<!M><%minus><%aprightsingquotmark><%aprightsingquotmark>         */ DEADTRANS( 0x2019	,0xE63E	,0x22B9	,0x0000), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><%minus><%aprightsingquotmark><%bar>                         */ DEADTRANS( L'|'	,0xE63E	,0x2957	,0x0000), // '|' ➔ "⥗" RIGHTWARDS HARPOON WITH BARB DOWN TO BAR
/*<!M><%minus><%aprightsingquotmark><%grave>                       */ DEADTRANS( L'`'	,0xE63E	,0x2969	,0x0000), // '`' ➔ "⥩" RIGHTWARDS HARPOON WITH BARB DOWN ABOVE LEFTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%aprightsingquotmark><%minus>                       */ DEADTRANS( L'-'	,0xE63E	,0x2AE0	,0x0000), // '-' ➔ "⫠" SHORT UP TACK
/*<!M><%minus><%aprightsingquotmark><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE63E	,0x00AC	,0x0000), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%aprightsingquotmark><~space>                       */ DEADTRANS( L' '	,0xE63E	,0x00AC	,0x0000), // ' ' ➔ "¬" NOT SIGN
/*<!M><%minus><%backslash>                                         */ DEADTRANS( L'\\'	,0xE636	,0xE645	,0x0001), // Multikey chain
/*<!M><%minus><%backslash><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE645	,0x29A6	,0x0000), // ' ' ➔ "⦦" OBLIQUE ANGLE OPENING UP
/*<!M><%minus><%backslash><~space>                                 */ DEADTRANS( L' '	,0xE645	,0x29A6	,0x0000), // ' ' ➔ "⦦" OBLIQUE ANGLE OPENING UP
/*<!M><%minus><%bar>                                               */ DEADTRANS( L'|'	,0xE636	,0xE648	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE648	,0xE649	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%bar><%greater>                               */ DEADTRANS( L'>'	,0xE649	,0xE64A	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%bar><%greater><%greater>                     */ DEADTRANS( L'>'	,0xE64A	,0x2901	,0x0000), // '>' ➔ "⤁" RIGHTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%greater><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE64A	,0x21FB	,0x0000), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%greater><~space>                       */ DEADTRANS( L' '	,0xE64A	,0x21FB	,0x0000), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xE649	,0xE64E	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%bar><%minus><%greater>                       */ DEADTRANS( L'>'	,0xE64E	,0xE64F	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%bar><%minus><%greater><%greater>             */ DEADTRANS( L'>'	,0xE64F	,0x2901	,0x0000), // '>' ➔ "⤁" RIGHTWARDS TWO-HEADED ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><%greater><~nbspace>             */ DEADTRANS( 0x00A0	,0xE64F	,0x21FB	,0x0000), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><%greater><~space>               */ DEADTRANS( L' '	,0xE64F	,0x21FB	,0x0000), // ' ' ➔ "⇻" RIGHTWARDS ARROW WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%bar><%bar><%minus><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE64E	,0x27DB	,0x0000), // ' ' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><%minus><%bar><%bar><%minus><~space>                         */ DEADTRANS( L' '	,0xE64E	,0x27DB	,0x0000), // ' ' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><%minus><%bar><%bar><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE649	,0x2AE3	,0x0000), // ' ' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><%minus><%bar><%bar><~space>                                 */ DEADTRANS( L' '	,0xE649	,0x2AE3	,0x0000), // ' ' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><%minus><%bar><%greater>                                     */ DEADTRANS( L'>'	,0xE648	,0xE657	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%greater><%greater>                           */ DEADTRANS( L'>'	,0xE657	,0x2900	,0x0000), // '>' ➔ "⤀" RIGHTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%greater><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE657	,0x21FE	,0x0000), // ' ' ➔ "⇾" RIGHTWARDS OPEN-HEADED ARROW
/*<!M><%minus><%bar><%greater><~space>                             */ DEADTRANS( L' '	,0xE657	,0x21FE	,0x0000), // ' ' ➔ "⇾" RIGHTWARDS OPEN-HEADED ARROW
/*<!M><%minus><%bar><%minus>                                       */ DEADTRANS( L'-'	,0xE648	,0xE65B	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%minus><%greater>                             */ DEADTRANS( L'>'	,0xE65B	,0xE65C	,0x0001), // Multikey chain
/*<!M><%minus><%bar><%minus><%greater><%greater>                   */ DEADTRANS( L'>'	,0xE65C	,0x2900	,0x0000), // '>' ➔ "⤀" RIGHTWARDS TWO-HEADED ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%minus><%greater><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE65C	,0x21F8	,0x0000), // ' ' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><%minus><%greater><~space>                     */ DEADTRANS( L' '	,0xE65C	,0x21F8	,0x0000), // ' ' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><%minus><%bar><o>                                            */ DEADTRANS( L'o'	,0xE648	,0x2AF1	,0x0000), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><%minus><%bar><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE648	,0x2ADE	,0x0000), // ' ' ➔ "⫞" SHORT LEFT TACK
/*<!M><%minus><%bar><~space>                                       */ DEADTRANS( L' '	,0xE648	,0x2ADE	,0x0000), // ' ' ➔ "⫞" SHORT LEFT TACK
/*<!M><%minus><%circum>                                            */ DEADTRANS( L'^'	,0xE636	,0xE663	,0x0001), // Multikey chain
/*<!M><%minus><%circum><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE663	,0x207B	,0x0000), // ' ' ➔ "⁻" SUPERSCRIPT MINUS
/*<!M><%minus><%circum><~space>                                    */ DEADTRANS( L' '	,0xE663	,0x207B	,0x0000), // ' ' ➔ "⁻" SUPERSCRIPT MINUS
/*<!M><%minus><%colon>                                             */ DEADTRANS( L':'	,0xE636	,0x2239	,0x0000), // ':' ➔ "∹" EXCESS
/*<!M><%minus><%comma>                                             */ DEADTRANS( L','	,0xE636	,0xE667	,0x0001), // Multikey chain
/*<!M><%minus><%comma><%exclam>                                    */ DEADTRANS( L'!'	,0xE667	,0xE668	,0x0001), // Multikey chain
/*<!M><%minus><%comma><%exclam><%greater>                          */ DEADTRANS( L'>'	,0xE668	,0x2935	,0x0000), // '>' ➔ "⤵" ARROW POINTING RIGHTWARDS THEN CURVING DOWNWARDS
/*<!M><%minus><%comma><%less>                                      */ DEADTRANS( L'<'	,0xE667	,0xE66A	,0x0001), // Multikey chain
/*<!M><%minus><%comma><%less><%exclam>                             */ DEADTRANS( L'!'	,0xE66A	,0x2934	,0x0000), // '!' ➔ "⤴" ARROW POINTING RIGHTWARDS THEN CURVING UPWARDS
/*<!M><%minus><%equal>                                             */ DEADTRANS( L'='	,0xE636	,0xE66C	,0x0001), // Multikey chain
/*<!M><%minus><%equal><%bar>                                       */ DEADTRANS( L'|'	,0xE66C	,0xE66D	,0x0001), // Multikey chain
/*<!M><%minus><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xE66D	,0xE66E	,0x0001), // Multikey chain
/*<!M><%minus><%equal><%bar><%bar><%bar>                           */ DEADTRANS( L'|'	,0xE66E	,0x2A69	,0x0000), // '|' ➔ "⩩" TRIPLE HORIZONTAL BAR WITH TRIPLE VERTICAL STROKE
/*<!M><%minus><%equal><%bar><%bar><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE66E	,0x2A68	,0x0000), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%equal><%bar><%bar><~space>                         */ DEADTRANS( L' '	,0xE66E	,0x2A68	,0x0000), // ' ' ➔ "⩨" TRIPLE HORIZONTAL BAR WITH DOUBLE VERTICAL STROKE
/*<!M><%minus><%equal><%minus>                                     */ DEADTRANS( L'-'	,0xE66C	,0x2263	,0x0000), // '-' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><%minus><%equal><%slash>                                     */ DEADTRANS( L'/'	,0xE66C	,0xE673	,0x0001), // Multikey chain
/*<!M><%minus><%equal><%slash><%slash>                             */ DEADTRANS( L'/'	,0xE673	,0x29E5	,0x0000), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><%minus><%equal><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xE673	,0x2262	,0x0000), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%minus><%equal><%slash><~space>                             */ DEADTRANS( L' '	,0xE673	,0x2262	,0x0000), // ' ' ➔ "≢" NOT IDENTICAL TO
/*<!M><%minus><%equal><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE66C	,0x2261	,0x0000), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%minus><%equal><~space>                                     */ DEADTRANS( L' '	,0xE66C	,0x2261	,0x0000), // ' ' ➔ "≡" IDENTICAL TO
/*<!M><%minus><%grave>                                             */ DEADTRANS( L'`'	,0xE636	,0xE679	,0x0001), // Multikey chain
/*<!M><%minus><%grave><%apostrophe>                                */ DEADTRANS( L'\''	,0xE679	,0x2968	,0x0000), // ''' ➔ "⥨" RIGHTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB UP
/*<!M><%minus><%grave><%aprightsingquotmark>                       */ DEADTRANS( 0x2019	,0xE679	,0x2968	,0x0000), // '’' ➔ "⥨" RIGHTWARDS HARPOON WITH BARB UP ABOVE LEFTWARDS HARPOON WITH BARB UP
/*<!M><%minus><%grave><%bar>                                       */ DEADTRANS( L'|'	,0xE679	,0x2953	,0x0000), // '|' ➔ "⥓" RIGHTWARDS HARPOON WITH BARB UP TO BAR
/*<!M><%minus><%grave><%grave>                                     */ DEADTRANS( L'`'	,0xE679	,0xE67D	,0x0001), // Multikey chain
/*<!M><%minus><%grave><%grave><%minus>                             */ DEADTRANS( L'-'	,0xE67D	,0xE67E	,0x0001), // Multikey chain
/*<!M><%minus><%grave><%grave><%minus><%minus>                     */ DEADTRANS( L'-'	,0xE67E	,0xDCD3	,0x0000), // High surrogate: D83E; U+1F8D3 '-' ➔ "🣓" SHORT RIGHTWARDS HARPOON ABOVE LONG LEFTWARDS HARPOON
/*<!M><%minus><%grave><%grave><%minus><~nbspace>                   */ DEADTRANS( 0x00A0	,0xE67E	,0x21CC	,0x0000), // ' ' ➔ "⇌" RIGHTWARDS HARPOON OVER LEFTWARDS HARPOON
/*<!M><%minus><%grave><%grave><%minus><~space>                     */ DEADTRANS( L' '	,0xE67E	,0x21CC	,0x0000), // ' ' ➔ "⇌" RIGHTWARDS HARPOON OVER LEFTWARDS HARPOON
/*<!M><%minus><%grave><%minus>                                     */ DEADTRANS( L'-'	,0xE679	,0xE682	,0x0001), // Multikey chain
/*<!M><%minus><%grave><%minus><%apostrophe>                        */ DEADTRANS( L'\''	,0xE682	,0x2964	,0x0000), // ''' ➔ "⥤" RIGHTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%grave><%minus><%aprightsingquotmark>               */ DEADTRANS( 0x2019	,0xE682	,0x2964	,0x0000), // '’' ➔ "⥤" RIGHTWARDS HARPOON WITH BARB UP ABOVE RIGHTWARDS HARPOON WITH BARB DOWN
/*<!M><%minus><%grave><%underscore>                                */ DEADTRANS( L'_'	,0xE679	,0x296C	,0x0000), // '_' ➔ "⥬" RIGHTWARDS HARPOON WITH BARB UP ABOVE LONG DASH
/*<!M><%minus><%grave><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE679	,0x21C0	,0x0000), // ' ' ➔ "⇀" RIGHTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%minus><%grave><~space>                                     */ DEADTRANS( L' '	,0xE679	,0x21C0	,0x0000), // ' ' ➔ "⇀" RIGHTWARDS HARPOON WITH BARB UPWARDS
/*<!M><%minus><%greater>                                           */ DEADTRANS( L'>'	,0xE636	,0xE688	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%bar>                                     */ DEADTRANS( L'|'	,0xE688	,0x21E5	,0x0000), // '|' ➔ "⇥" RIGHTWARDS ARROW TO BAR
/*<!M><%minus><%greater><%greater>                                 */ DEADTRANS( L'>'	,0xE688	,0xE68A	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%greater><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE68A	,0x21A0	,0x0000), // ' ' ➔ "↠" RIGHTWARDS TWO HEADED ARROW
/*<!M><%minus><%greater><%greater><~space>                         */ DEADTRANS( L' '	,0xE68A	,0x21A0	,0x0000), // ' ' ➔ "↠" RIGHTWARDS TWO HEADED ARROW
/*<!M><%minus><%greater><%less>                                    */ DEADTRANS( L'<'	,0xE688	,0xE68D	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%less><%greater>                          */ DEADTRANS( L'>'	,0xE68D	,0x291E	,0x0000), // '>' ➔ "⤞" RIGHTWARDS ARROW TO BLACK DIAMOND
/*<!M><%minus><%greater><%less><%minus>                            */ DEADTRANS( L'-'	,0xE68D	,0x21C4	,0x0000), // '-' ➔ "⇄" RIGHTWARDS ARROW OVER LEFTWARDS ARROW
/*<!M><%minus><%greater><%less><%parenleft>                        */ DEADTRANS( L'('	,0xE68D	,0x27E2	,0x0000), // '(' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%greater><%less><%parenright>                       */ DEADTRANS( L')'	,0xE68D	,0x27E2	,0x0000), // ')' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%greater><%less><%period>                           */ DEADTRANS( L'.'	,0xE68D	,0x2942	,0x0000), // '.' ➔ "⥂" RIGHTWARDS ARROW ABOVE SHORT LEFTWARDS ARROW
/*<!M><%minus><%greater><%minus>                                   */ DEADTRANS( L'-'	,0xE688	,0xE693	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%minus><%greater>                         */ DEADTRANS( L'>'	,0xE693	,0xE694	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%minus><%greater><%minus>                 */ DEADTRANS( L'-'	,0xE694	,0x21F6	,0x0000), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><%minus><%greater><%minus><%greater><~nbspace>               */ DEADTRANS( 0x00A0	,0xE694	,0x21C9	,0x0000), // ' ' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><%minus><%greater><%minus><%greater><~space>                 */ DEADTRANS( L' '	,0xE694	,0x21C9	,0x0000), // ' ' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><%minus><%greater><%plus>                                    */ DEADTRANS( L'+'	,0xE688	,0x2945	,0x0000), // '+' ➔ "⥅" RIGHTWARDS ARROW WITH PLUS BELOW
/*<!M><%minus><%greater><%tilde>                                   */ DEADTRANS( L'~'	,0xE688	,0xE699	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%tilde><%backslash>                       */ DEADTRANS( L'\\'	,0xE699	,0x2B4C	,0x0000), // '\' ➔ "⭌" RIGHTWARDS ARROW ABOVE REVERSE TILDE OPERATOR
/*<!M><%minus><%greater><%tilde><%tilde>                           */ DEADTRANS( L'~'	,0xE699	,0xE69B	,0x0001), // Multikey chain
/*<!M><%minus><%greater><%tilde><%tilde><%backslash>               */ DEADTRANS( L'\\'	,0xE69B	,0x2B48	,0x0000), // '\' ➔ "⭈" RIGHTWARDS ARROW ABOVE REVERSE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde><%tilde><~nbspace>                 */ DEADTRANS( 0x00A0	,0xE69B	,0x2975	,0x0000), // ' ' ➔ "⥵" RIGHTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde><%tilde><~space>                   */ DEADTRANS( L' '	,0xE69B	,0x2975	,0x0000), // ' ' ➔ "⥵" RIGHTWARDS ARROW ABOVE ALMOST EQUAL TO
/*<!M><%minus><%greater><%tilde><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE699	,0x2974	,0x0000), // ' ' ➔ "⥴" RIGHTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><%minus><%greater><%tilde><~space>                           */ DEADTRANS( L' '	,0xE699	,0x2974	,0x0000), // ' ' ➔ "⥴" RIGHTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><%minus><%greater><3>                                        */ DEADTRANS( L'3'	,0xE688	,0x21DB	,0x0000), // '3' ➔ "⇛" RIGHTWARDS TRIPLE ARROW
/*<!M><%minus><%greater><4>                                        */ DEADTRANS( L'4'	,0xE688	,0x2B46	,0x0000), // '4' ➔ "⭆" RIGHTWARDS QUADRUPLE ARROW
/*<!M><%minus><%greater><O>                                        */ DEADTRANS( L'O'	,0xE688	,0x29B3	,0x0000), // 'O' ➔ "⦳" EMPTY SET WITH RIGHT ARROW ABOVE
/*<!M><%minus><%greater><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE688	,0x2192	,0x0000), // ' ' ➔ "→" RIGHTWARDS ARROW
/*<!M><%minus><%greater><~space>                                   */ DEADTRANS( L' '	,0xE688	,0x2192	,0x0000), // ' ' ➔ "→" RIGHTWARDS ARROW
/*<!M><%minus><%less>                                              */ DEADTRANS( L'<'	,0xE636	,0xE6A6	,0x0001), // Multikey chain
/*<!M><%minus><%less><%greater>                                    */ DEADTRANS( L'>'	,0xE6A6	,0x27E2	,0x0000), // '>' ➔ "⟢" WHITE CONCAVE-SIDED DIAMOND WITH LEFTWARDS TICK
/*<!M><%minus><%less><%less>                                       */ DEADTRANS( L'<'	,0xE6A6	,0x291B	,0x0000), // '<' ➔ "⤛" LEFTWARDS DOUBLE ARROW-TAIL
/*<!M><%minus><%less><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE6A6	,0x2919	,0x0000), // ' ' ➔ "⤙" LEFTWARDS ARROW-TAIL
/*<!M><%minus><%less><~space>                                      */ DEADTRANS( L' '	,0xE6A6	,0x2919	,0x0000), // ' ' ➔ "⤙" LEFTWARDS ARROW-TAIL
/*<!M><%minus><%minus>                                             */ DEADTRANS( L'-'	,0xE636	,0xE6AB	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%bar>                                       */ DEADTRANS( L'|'	,0xE6AB	,0x22A3	,0x0000), // '|' ➔ "⊣" LEFT TACK
/*<!M><%minus><%minus><%grave>                                     */ DEADTRANS( L'`'	,0xE6AB	,0xE6AD	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%grave><%grave>                             */ DEADTRANS( L'`'	,0xE6AD	,0xE6AE	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%grave><%grave><%minus>                     */ DEADTRANS( L'-'	,0xE6AE	,0xE6AF	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%grave><%grave><%minus><%minus>             */ DEADTRANS( L'-'	,0xE6AF	,0xDCD1	,0x0000), // High surrogate: D83E; U+1F8D1 '-' ➔ "🣑" LONG RIGHTWARDS HARPOON OVER LONG LEFTWARDS HARPOON
/*<!M><%minus><%minus><%grave><%grave><%minus><~nbspace>           */ DEADTRANS( 0x00A0	,0xE6AF	,0xDCD2	,0x0000), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%grave><%grave><%minus><~space>             */ DEADTRANS( L' '	,0xE6AF	,0xDCD2	,0x0000), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%greater>                                   */ DEADTRANS( L'>'	,0xE6AB	,0xE6B3	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%greater><%less>                            */ DEADTRANS( L'<'	,0xE6B3	,0xDCD0	,0x0000), // High surrogate: D83E; U+1F8D0 '<' ➔ "🣐" LONG RIGHTWARDS ARROW OVER LONG LEFTWARDS ARROW
/*<!M><%minus><%minus><%greater><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE6B3	,0x27F6	,0x0000), // ' ' ➔ "⟶" LONG RIGHTWARDS ARROW
/*<!M><%minus><%minus><%greater><~space>                           */ DEADTRANS( L' '	,0xE6B3	,0x27F6	,0x0000), // ' ' ➔ "⟶" LONG RIGHTWARDS ARROW
/*<!M><%minus><%minus><%minus>                                     */ DEADTRANS( L'-'	,0xE6AB	,0xE6B7	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%minus><%bar>                               */ DEADTRANS( L'|'	,0xE6B7	,0x27DE	,0x0000), // '|' ➔ "⟞" LONG LEFT TACK
/*<!M><%minus><%minus><%minus><%grave>                             */ DEADTRANS( L'`'	,0xE6B7	,0xE6B9	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%minus><%grave><%grave>                     */ DEADTRANS( L'`'	,0xE6B9	,0xE6BA	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus>             */ DEADTRANS( L'-'	,0xE6BA	,0xE6BB	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus><%minus>     */ DEADTRANS( L'-'	,0xE6BB	,0xDCD1	,0x0000), // High surrogate: D83E; U+1F8D1 '-' ➔ "🣑" LONG RIGHTWARDS HARPOON OVER LONG LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus><~nbspace>   */ DEADTRANS( 0x00A0	,0xE6BB	,0xDCD2	,0x0000), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%grave><%grave><%minus><~space>     */ DEADTRANS( L' '	,0xE6BB	,0xDCD2	,0x0000), // High surrogate: D83E; U+1F8D2 ' ' ➔ "🣒" LONG RIGHTWARDS HARPOON ABOVE SHORT LEFTWARDS HARPOON
/*<!M><%minus><%minus><%minus><%greater>                           */ DEADTRANS( L'>'	,0xE6B7	,0xE6BF	,0x0001), // Multikey chain
/*<!M><%minus><%minus><%minus><%greater><%less>                    */ DEADTRANS( L'<'	,0xE6BF	,0xDCD0	,0x0000), // High surrogate: D83E; U+1F8D0 '<' ➔ "🣐" LONG RIGHTWARDS ARROW OVER LONG LEFTWARDS ARROW
/*<!M><%minus><%minus><%minus><%minus>                             */ DEADTRANS( L'-'	,0xE6B7	,0x2014	,0x0000), // '-' ➔ "—" EM DASH
/*<!M><%minus><%minus><A>                                          */ DEADTRANS( L'A'	,0xE6AB	,0x2A5E	,0x0000), // 'A' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><a>                                          */ DEADTRANS( L'a'	,0xE6AB	,0x2A5E	,0x0000), // 'a' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v>                                          */ DEADTRANS( L'v'	,0xE6AB	,0xE6C4	,0x0001), // Multikey chain
/*<!M><%minus><%minus><V>                                          */ DEADTRANS( L'V'	,0xE6AB	,0xE6C5	,0x0001), // Multikey chain
/*<!M><%minus><%minus><v><%percent>                                */ DEADTRANS( L'%'	,0xE6C4	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V><%percent>                                */ DEADTRANS( L'%'	,0xE6C5	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE6C4	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE6C5	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><v><~space>                                  */ DEADTRANS( L' '	,0xE6C4	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%minus><V><~space>                                  */ DEADTRANS( L' '	,0xE6C5	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><%minus><%parenleft>                                         */ DEADTRANS( L'('	,0xE636	,0xE6CC	,0x0001), // Multikey chain
/*<!M><%minus><%parenleft><%less>                                  */ DEADTRANS( L'<'	,0xE6CC	,0x29AB	,0x0000), // '<' ➔ "⦫" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING DOWN AND LEFT
/*<!M><%minus><%parenleft><%parenright>                            */ DEADTRANS( L')'	,0xE6CC	,0x29FF	,0x0000), // ')' ➔ "⧿" MINY
/*<!M><%minus><%parenright>                                        */ DEADTRANS( L')'	,0xE636	,0xE6CF	,0x0001), // Multikey chain
/*<!M><%minus><%parenright><%parenleft>                            */ DEADTRANS( L'('	,0xE6CF	,0x29FF	,0x0000), // '(' ➔ "⧿" MINY
/*<!M><%minus><%parenright><%slash>                                */ DEADTRANS( L'/'	,0xE6CF	,0xE6D1	,0x0001), // Multikey chain
/*<!M><%minus><%parenright><%slash><%greater>                      */ DEADTRANS( L'>'	,0xE6D1	,0x29A8	,0x0000), // '>' ➔ "⦨" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING UP AND RIGHT
/*<!M><%minus><%parenright><%slash><~nbspace>                      */ DEADTRANS( 0x00A0	,0xE6D1	,0x2221	,0x0000), // ' ' ➔ "∡" MEASURED ANGLE
/*<!M><%minus><%parenright><%slash><~space>                        */ DEADTRANS( L' '	,0xE6D1	,0x2221	,0x0000), // ' ' ➔ "∡" MEASURED ANGLE
/*<!M><%minus><%period>                                            */ DEADTRANS( L'.'	,0xE636	,0xE6D5	,0x0001), // Multikey chain
/*<!M><%minus><%period><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE6D5	,0x2A2A	,0x0000), // ' ' ➔ "⨪" MINUS SIGN WITH DOT BELOW
/*<!M><%minus><%period><~space>                                    */ DEADTRANS( L' '	,0xE6D5	,0x2A2A	,0x0000), // ' ' ➔ "⨪" MINUS SIGN WITH DOT BELOW
/*<!M><%minus><%plus>                                              */ DEADTRANS( L'+'	,0xE636	,0x2213	,0x0000), // '+' ➔ "∓" MINUS-OR-PLUS SIGN
/*<!M><%minus><%slash>                                             */ DEADTRANS( L'/'	,0xE636	,0xE6D9	,0x0001), // Multikey chain
/*<!M><%minus><%slash><%bar>                                       */ DEADTRANS( L'|'	,0xE6D9	,0x27C0	,0x0000), // '|' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><%minus><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xE6D9	,0xDCD7	,0x0000), // High surrogate: D83E; U+1F8D7 '/' ➔ "🣗" LONG RIGHTWARDS ARROW WITH DOUBLE SLASH
/*<!M><%minus><%slash><s>                                          */ DEADTRANS( L's'	,0xE6D9	,0x299E	,0x0000), // 's' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><%minus><%slash><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE6D9	,0x2220	,0x0000), // ' ' ➔ "∠" ANGLE
/*<!M><%minus><%slash><~space>                                     */ DEADTRANS( L' '	,0xE6D9	,0x2220	,0x0000), // ' ' ➔ "∠" ANGLE
/*<!M><%minus><%tilde>                                             */ DEADTRANS( L'~'	,0xE636	,0x2242	,0x0000), // '~' ➔ "≂" MINUS TILDE
/*<!M><%minus><%underscore>                                        */ DEADTRANS( L'_'	,0xE636	,0xE6E0	,0x0001), // Multikey chain
/*<!M><%minus><%underscore><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE6E0	,0x208B	,0x0000), // ' ' ➔ "₋" SUBSCRIPT MINUS
/*<!M><%minus><%underscore><~space>                                */ DEADTRANS( L' '	,0xE6E0	,0x208B	,0x0000), // ' ' ➔ "₋" SUBSCRIPT MINUS
/*<!M><%minus><0>                                                  */ DEADTRANS( L'0'	,0xE636	,0xE6E3	,0x0001), // Multikey chain
/*<!M><%minus><0><%minus>                                          */ DEADTRANS( L'-'	,0xE6E3	,0xE6E4	,0x0001), // Multikey chain
/*<!M><%minus><0><%minus><%greater>                                */ DEADTRANS( L'>'	,0xE6E4	,0x290D	,0x0000), // '>' ➔ "⤍" RIGHTWARDS DOUBLE DASH ARROW
/*<!M><%minus><0><%minus><0>                                       */ DEADTRANS( L'0'	,0xE6E4	,0xE6E6	,0x0001), // Multikey chain
/*<!M><%minus><0><%minus><0><%minus>                               */ DEADTRANS( L'-'	,0xE6E6	,0xE6E7	,0x0001), // Multikey chain
/*<!M><%minus><0><%minus><0><%minus><%greater>                     */ DEADTRANS( L'>'	,0xE6E7	,0xE6E8	,0x0001), // Multikey chain
/*<!M><%minus><0><%minus><0><%minus><%greater><%greater>           */ DEADTRANS( L'>'	,0xE6E8	,0x2910	,0x0000), // '>' ➔ "⤐" RIGHTWARDS TWO-HEADED TRIPLE DASH ARROW
/*<!M><%minus><0><%minus><0><%minus><%greater><~nbspace>           */ DEADTRANS( 0x00A0	,0xE6E8	,0x290F	,0x0000), // ' ' ➔ "⤏" RIGHTWARDS TRIPLE DASH ARROW
/*<!M><%minus><0><%minus><0><%minus><%greater><~space>             */ DEADTRANS( L' '	,0xE6E8	,0x290F	,0x0000), // ' ' ➔ "⤏" RIGHTWARDS TRIPLE DASH ARROW
/*<!M><%minus><x>                                                  */ DEADTRANS( L'x'	,0xE636	,0xE6EC	,0x0001), // Multikey chain
/*<!M><%minus><x><%colon>                                          */ DEADTRANS( L':'	,0xE6EC	,0x22C7	,0x0000), // ':' ➔ "⋇" DIVISION TIMES
/*<!M><%minus><x><%minus>                                          */ DEADTRANS( L'-'	,0xE6EC	,0xDCD6	,0x0000), // High surrogate: D83E; U+1F8D6 '-' ➔ "🣖" LONG RIGHTWARDS ARROW THROUGH X
/*<!M><%parenleft>                                                 */ DEADTRANS( L'('	,0x00A6	,0xE6EF	,0x0001), // Multikey chain
/*<!M><%parenleft><%backslash>                                     */ DEADTRANS( L'\\'	,0xE6EF	,0x2925	,0x0000), // '\' ➔ "⤥" SOUTH EAST ARROW WITH HOOK
/*<!M><%parenleft><%bracketleft>                                   */ DEADTRANS( L'['	,0xE6EF	,0x2997	,0x0000), // '[' ➔ "⦗" LEFT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenleft><%circum>                                        */ DEADTRANS( L'^'	,0xE6EF	,0x207D	,0x0000), // '^' ➔ "⁽" SUPERSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft><%equal>                                         */ DEADTRANS( L'='	,0xE6EF	,0x2258	,0x0000), // '=' ➔ "≘" CORRESPONDS TO
/*<!M><%parenleft><%greater>                                       */ DEADTRANS( L'>'	,0xE6EF	,0xE6F4	,0x0001), // Multikey chain
/*<!M><%parenleft><%greater><%minus>                               */ DEADTRANS( L'-'	,0xE6F4	,0x293C	,0x0000), // '-' ➔ "⤼" TOP ARC CLOCKWISE ARROW WITH MINUS
/*<!M><%parenleft><%greater><%parenleft>                           */ DEADTRANS( L'('	,0xE6F4	,0x2995	,0x0000), // '(' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%parenleft><%greater><%underscore>                          */ DEADTRANS( L'_'	,0xE6F4	,0x2AA9	,0x0000), // '_' ➔ "⪩" GREATER-THAN CLOSED BY CURVE ABOVE SLANTED EQUAL
/*<!M><%parenleft><%greater><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE6F4	,0x2939	,0x0000), // ' ' ➔ "⤹" LEFT-SIDE ARC ANTICLOCKWISE ARROW
/*<!M><%parenleft><%greater><~space>                               */ DEADTRANS( L' '	,0xE6F4	,0x2939	,0x0000), // ' ' ➔ "⤹" LEFT-SIDE ARC ANTICLOCKWISE ARROW
/*<!M><%parenleft><%less>                                          */ DEADTRANS( L'<'	,0xE6EF	,0xE6FA	,0x0001), // Multikey chain
/*<!M><%parenleft><%less><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE6FA	,0x2993	,0x0000), // ' ' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><%parenleft><%less><~space>                                  */ DEADTRANS( L' '	,0xE6FA	,0x2993	,0x0000), // ' ' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><%parenleft><%minus>                                         */ DEADTRANS( L'-'	,0xE6EF	,0xE6FD	,0x0001), // Multikey chain
/*<!M><%parenleft><%minus><%equal>                                 */ DEADTRANS( L'='	,0xE6FD	,0x2AAE	,0x0000), // '=' ➔ "⪮" EQUALS SIGN WITH BUMPY ABOVE
/*<!M><%parenleft><%minus><%greater>                               */ DEADTRANS( L'>'	,0xE6FD	,0x21AA	,0x0000), // '>' ➔ "↪" RIGHTWARDS ARROW WITH HOOK
/*<!M><%parenleft><%minus><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE6FD	,0x224F	,0x0000), // ' ' ➔ "≏" DIFFERENCE BETWEEN
/*<!M><%parenleft><%minus><~space>                                 */ DEADTRANS( L' '	,0xE6FD	,0x224F	,0x0000), // ' ' ➔ "≏" DIFFERENCE BETWEEN
/*<!M><%parenleft><%parenleft>                                     */ DEADTRANS( L'('	,0xE6EF	,0xE702	,0x0001), // Multikey chain
/*<!M><%parenleft><%parenleft><%bracketleft>                       */ DEADTRANS( L'['	,0xE702	,0x27EC	,0x0000), // '[' ➔ "⟬" MATHEMATICAL LEFT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenleft><%parenleft><%bracketright>                      */ DEADTRANS( L']'	,0xE702	,0x27EC	,0x0000), // ']' ➔ "⟬" MATHEMATICAL LEFT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenleft><%parenleft><%greater>                           */ DEADTRANS( L'>'	,0xE702	,0x2995	,0x0000), // '>' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET
/*<!M><%parenleft><%parenright>                                    */ DEADTRANS( L')'	,0xE6EF	,0xE706	,0x0001), // Multikey chain
/*<!M><%parenleft><%parenright><%minus>                            */ DEADTRANS( L'-'	,0xE706	,0x2050	,0x0000), // '-' ➔ "⁐" CLOSE UP
/*<!M><%parenleft><%parenright><%slash>                            */ DEADTRANS( L'/'	,0xE706	,0x226D	,0x0000), // '/' ➔ "≭" NOT EQUIVALENT TO
/*<!M><%parenleft><%parenright><c>                                 */ DEADTRANS( L'c'	,0xE706	,0x00A9	,0x0000), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><%parenleft><%parenright><C>                                 */ DEADTRANS( L'C'	,0xE706	,0x00A9	,0x0000), // 'C' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><%parenleft><%parenright><p>                                 */ DEADTRANS( L'p'	,0xE706	,0x2117	,0x0000), // 'p' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><%parenleft><%parenright><P>                                 */ DEADTRANS( L'P'	,0xE706	,0x2117	,0x0000), // 'P' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><%parenleft><%parenright><r>                                 */ DEADTRANS( L'r'	,0xE706	,0x00AE	,0x0000), // 'r' ➔ "®" REGISTERED SIGN emoji
/*<!M><%parenleft><%parenright><R>                                 */ DEADTRANS( L'R'	,0xE706	,0x00AE	,0x0000), // 'R' ➔ "®" REGISTERED SIGN emoji
/*<!M><%parenleft><%parenright><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE706	,0x226C	,0x0000), // ' ' ➔ "≬" BETWEEN
/*<!M><%parenleft><%parenright><~space>                            */ DEADTRANS( L' '	,0xE706	,0x226C	,0x0000), // ' ' ➔ "≬" BETWEEN
/*<!M><%parenleft><%plus>                                          */ DEADTRANS( L'+'	,0xE6EF	,0x2A2D	,0x0000), // '+' ➔ "⨭" PLUS SIGN IN LEFT HALF CIRCLE
/*<!M><%parenleft><%slash>                                         */ DEADTRANS( L'/'	,0xE6EF	,0x2924	,0x0000), // '/' ➔ "⤤" NORTH EAST ARROW WITH HOOK
/*<!M><%parenleft><%underscore>                                    */ DEADTRANS( L'_'	,0xE6EF	,0xE713	,0x0001), // Multikey chain
/*<!M><%parenleft><%underscore><%parenright>                       */ DEADTRANS( L')'	,0xE713	,0x274D	,0x0000), // ')' ➔ "❍" SHADOWED WHITE CIRCLE
/*<!M><%parenleft><%underscore><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE713	,0x208D	,0x0000), // ' ' ➔ "₍" SUBSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft><%underscore><~space>                            */ DEADTRANS( L' '	,0xE713	,0x208D	,0x0000), // ' ' ➔ "₍" SUBSCRIPT LEFT PARENTHESIS
/*<!M><%parenleft><0>                                              */ DEADTRANS( L'0'	,0xE6EF	,0xE717	,0x0001), // Multikey chain
/*<!M><%parenleft><0><%parenright>                                 */ DEADTRANS( L')'	,0xE717	,0x24EA	,0x0000), // ')' ➔ "⓪" CIRCLED DIGIT ZERO
/*<!M><%parenleft><0><0>                                           */ DEADTRANS( L'0'	,0xE717	,0xE719	,0x0001), // Multikey chain
/*<!M><%parenleft><0><0><1>                                        */ DEADTRANS( L'1'	,0xE719	,0xE71A	,0x0001), // Multikey chain
/*<!M><%parenleft><0><0><1><1>                                     */ DEADTRANS( L'1'	,0xE71A	,0x256F	,0x0000), // '1' ➔ "╯" BOX DRAWINGS LIGHT ARC UP AND LEFT
/*<!M><%parenleft><0><1>                                           */ DEADTRANS( L'1'	,0xE717	,0xE71C	,0x0001), // Multikey chain
/*<!M><%parenleft><0><1><1>                                        */ DEADTRANS( L'1'	,0xE71C	,0xE71D	,0x0001), // Multikey chain
/*<!M><%parenleft><0><1><1><0>                                     */ DEADTRANS( L'0'	,0xE71D	,0x256E	,0x0000), // '0' ➔ "╮" BOX DRAWINGS LIGHT ARC DOWN AND LEFT
/*<!M><%parenleft><1>                                              */ DEADTRANS( L'1'	,0xE6EF	,0xE71F	,0x0001), // Multikey chain
/*<!M><%parenleft><1><%parenright>                                 */ DEADTRANS( L')'	,0xE71F	,0x2460	,0x0000), // ')' ➔ "①" CIRCLED DIGIT ONE
/*<!M><%parenleft><1><0>                                           */ DEADTRANS( L'0'	,0xE71F	,0xE721	,0x0001), // Multikey chain
/*<!M><%parenleft><1><0><%parenright>                              */ DEADTRANS( L')'	,0xE721	,0x2469	,0x0000), // ')' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><%parenleft><1><0><0>                                        */ DEADTRANS( L'0'	,0xE721	,0xE723	,0x0001), // Multikey chain
/*<!M><%parenleft><1><0><0><1>                                     */ DEADTRANS( L'1'	,0xE723	,0x2570	,0x0000), // '1' ➔ "╰" BOX DRAWINGS LIGHT ARC UP AND RIGHT
/*<!M><%parenleft><1><1>                                           */ DEADTRANS( L'1'	,0xE71F	,0xE725	,0x0001), // Multikey chain
/*<!M><%parenleft><1><1><%parenright>                              */ DEADTRANS( L')'	,0xE725	,0x246A	,0x0000), // ')' ➔ "⑪" CIRCLED NUMBER ELEVEN
/*<!M><%parenleft><1><1><0>                                        */ DEADTRANS( L'0'	,0xE725	,0xE727	,0x0001), // Multikey chain
/*<!M><%parenleft><1><1><0><0>                                     */ DEADTRANS( L'0'	,0xE727	,0x256D	,0x0000), // '0' ➔ "╭" BOX DRAWINGS LIGHT ARC DOWN AND RIGHT
/*<!M><%parenleft><1><2>                                           */ DEADTRANS( L'2'	,0xE71F	,0x246B	,0x0000), // '2' ➔ "⑫" CIRCLED NUMBER TWELVE
/*<!M><%parenleft><1><3>                                           */ DEADTRANS( L'3'	,0xE71F	,0x246C	,0x0000), // '3' ➔ "⑬" CIRCLED NUMBER THIRTEEN
/*<!M><%parenleft><1><4>                                           */ DEADTRANS( L'4'	,0xE71F	,0x246D	,0x0000), // '4' ➔ "⑭" CIRCLED NUMBER FOURTEEN
/*<!M><%parenleft><1><5>                                           */ DEADTRANS( L'5'	,0xE71F	,0x246E	,0x0000), // '5' ➔ "⑮" CIRCLED NUMBER FIFTEEN
/*<!M><%parenleft><1><6>                                           */ DEADTRANS( L'6'	,0xE71F	,0x246F	,0x0000), // '6' ➔ "⑯" CIRCLED NUMBER SIXTEEN
/*<!M><%parenleft><1><7>                                           */ DEADTRANS( L'7'	,0xE71F	,0x2470	,0x0000), // '7' ➔ "⑰" CIRCLED NUMBER SEVENTEEN
/*<!M><%parenleft><1><8>                                           */ DEADTRANS( L'8'	,0xE71F	,0x2471	,0x0000), // '8' ➔ "⑱" CIRCLED NUMBER EIGHTEEN
/*<!M><%parenleft><1><9>                                           */ DEADTRANS( L'9'	,0xE71F	,0x2472	,0x0000), // '9' ➔ "⑲" CIRCLED NUMBER NINETEEN
/*<!M><%parenleft><2>                                              */ DEADTRANS( L'2'	,0xE6EF	,0xE731	,0x0001), // Multikey chain
/*<!M><%parenleft><2><%parenright>                                 */ DEADTRANS( L')'	,0xE731	,0x2461	,0x0000), // ')' ➔ "②" CIRCLED DIGIT TWO
/*<!M><%parenleft><2><0>                                           */ DEADTRANS( L'0'	,0xE731	,0x2473	,0x0000), // '0' ➔ "⑳" CIRCLED NUMBER TWENTY
/*<!M><%parenleft><2><1>                                           */ DEADTRANS( L'1'	,0xE731	,0x3251	,0x0000), // '1' ➔ "㉑" CIRCLED NUMBER TWENTY ONE
/*<!M><%parenleft><2><2>                                           */ DEADTRANS( L'2'	,0xE731	,0x3252	,0x0000), // '2' ➔ "㉒" CIRCLED NUMBER TWENTY TWO
/*<!M><%parenleft><2><3>                                           */ DEADTRANS( L'3'	,0xE731	,0x3253	,0x0000), // '3' ➔ "㉓" CIRCLED NUMBER TWENTY THREE
/*<!M><%parenleft><2><4>                                           */ DEADTRANS( L'4'	,0xE731	,0x3254	,0x0000), // '4' ➔ "㉔" CIRCLED NUMBER TWENTY FOUR
/*<!M><%parenleft><2><5>                                           */ DEADTRANS( L'5'	,0xE731	,0x3255	,0x0000), // '5' ➔ "㉕" CIRCLED NUMBER TWENTY FIVE
/*<!M><%parenleft><2><6>                                           */ DEADTRANS( L'6'	,0xE731	,0x3256	,0x0000), // '6' ➔ "㉖" CIRCLED NUMBER TWENTY SIX
/*<!M><%parenleft><2><7>                                           */ DEADTRANS( L'7'	,0xE731	,0x3257	,0x0000), // '7' ➔ "㉗" CIRCLED NUMBER TWENTY SEVEN
/*<!M><%parenleft><2><8>                                           */ DEADTRANS( L'8'	,0xE731	,0x3258	,0x0000), // '8' ➔ "㉘" CIRCLED NUMBER TWENTY EIGHT
/*<!M><%parenleft><2><9>                                           */ DEADTRANS( L'9'	,0xE731	,0x3259	,0x0000), // '9' ➔ "㉙" CIRCLED NUMBER TWENTY NINE
/*<!M><%parenleft><3>                                              */ DEADTRANS( L'3'	,0xE6EF	,0xE73D	,0x0001), // Multikey chain
/*<!M><%parenleft><3><%parenright>                                 */ DEADTRANS( L')'	,0xE73D	,0x2462	,0x0000), // ')' ➔ "③" CIRCLED DIGIT THREE
/*<!M><%parenleft><3><0>                                           */ DEADTRANS( L'0'	,0xE73D	,0x325A	,0x0000), // '0' ➔ "㉚" CIRCLED NUMBER THIRTY
/*<!M><%parenleft><3><1>                                           */ DEADTRANS( L'1'	,0xE73D	,0x325B	,0x0000), // '1' ➔ "㉛" CIRCLED NUMBER THIRTY ONE
/*<!M><%parenleft><3><2>                                           */ DEADTRANS( L'2'	,0xE73D	,0x325C	,0x0000), // '2' ➔ "㉜" CIRCLED NUMBER THIRTY TWO
/*<!M><%parenleft><3><3>                                           */ DEADTRANS( L'3'	,0xE73D	,0x325D	,0x0000), // '3' ➔ "㉝" CIRCLED NUMBER THIRTY THREE
/*<!M><%parenleft><3><4>                                           */ DEADTRANS( L'4'	,0xE73D	,0x325E	,0x0000), // '4' ➔ "㉞" CIRCLED NUMBER THIRTY FOUR
/*<!M><%parenleft><3><5>                                           */ DEADTRANS( L'5'	,0xE73D	,0x325F	,0x0000), // '5' ➔ "㉟" CIRCLED NUMBER THIRTY FIVE
/*<!M><%parenleft><3><6>                                           */ DEADTRANS( L'6'	,0xE73D	,0x32B1	,0x0000), // '6' ➔ "㊱" CIRCLED NUMBER THIRTY SIX
/*<!M><%parenleft><3><7>                                           */ DEADTRANS( L'7'	,0xE73D	,0x32B2	,0x0000), // '7' ➔ "㊲" CIRCLED NUMBER THIRTY SEVEN
/*<!M><%parenleft><3><8>                                           */ DEADTRANS( L'8'	,0xE73D	,0x32B3	,0x0000), // '8' ➔ "㊳" CIRCLED NUMBER THIRTY EIGHT
/*<!M><%parenleft><3><9>                                           */ DEADTRANS( L'9'	,0xE73D	,0x32B4	,0x0000), // '9' ➔ "㊴" CIRCLED NUMBER THIRTY NINE
/*<!M><%parenleft><4>                                              */ DEADTRANS( L'4'	,0xE6EF	,0xE749	,0x0001), // Multikey chain
/*<!M><%parenleft><4><%parenright>                                 */ DEADTRANS( L')'	,0xE749	,0x2463	,0x0000), // ')' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><%parenleft><4><0>                                           */ DEADTRANS( L'0'	,0xE749	,0x32B5	,0x0000), // '0' ➔ "㊵" CIRCLED NUMBER FORTY
/*<!M><%parenleft><4><1>                                           */ DEADTRANS( L'1'	,0xE749	,0x32B6	,0x0000), // '1' ➔ "㊶" CIRCLED NUMBER FORTY ONE
/*<!M><%parenleft><4><2>                                           */ DEADTRANS( L'2'	,0xE749	,0x32B7	,0x0000), // '2' ➔ "㊷" CIRCLED NUMBER FORTY TWO
/*<!M><%parenleft><4><3>                                           */ DEADTRANS( L'3'	,0xE749	,0x32B8	,0x0000), // '3' ➔ "㊸" CIRCLED NUMBER FORTY THREE
/*<!M><%parenleft><4><4>                                           */ DEADTRANS( L'4'	,0xE749	,0x32B9	,0x0000), // '4' ➔ "㊹" CIRCLED NUMBER FORTY FOUR
/*<!M><%parenleft><4><5>                                           */ DEADTRANS( L'5'	,0xE749	,0x32BA	,0x0000), // '5' ➔ "㊺" CIRCLED NUMBER FORTY FIVE
/*<!M><%parenleft><4><6>                                           */ DEADTRANS( L'6'	,0xE749	,0x32BB	,0x0000), // '6' ➔ "㊻" CIRCLED NUMBER FORTY SIX
/*<!M><%parenleft><4><7>                                           */ DEADTRANS( L'7'	,0xE749	,0x32BC	,0x0000), // '7' ➔ "㊼" CIRCLED NUMBER FORTY SEVEN
/*<!M><%parenleft><4><8>                                           */ DEADTRANS( L'8'	,0xE749	,0x32BD	,0x0000), // '8' ➔ "㊽" CIRCLED NUMBER FORTY EIGHT
/*<!M><%parenleft><4><9>                                           */ DEADTRANS( L'9'	,0xE749	,0x32BE	,0x0000), // '9' ➔ "㊾" CIRCLED NUMBER FORTY NINE
/*<!M><%parenleft><5>                                              */ DEADTRANS( L'5'	,0xE6EF	,0xE755	,0x0001), // Multikey chain
/*<!M><%parenleft><5><%parenright>                                 */ DEADTRANS( L')'	,0xE755	,0x2464	,0x0000), // ')' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><%parenleft><5><0>                                           */ DEADTRANS( L'0'	,0xE755	,0x32BF	,0x0000), // '0' ➔ "㊿" CIRCLED NUMBER FIFTY
/*<!M><%parenleft><6>                                              */ DEADTRANS( L'6'	,0xE6EF	,0x2465	,0x0000), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><%parenleft><7>                                              */ DEADTRANS( L'7'	,0xE6EF	,0x2466	,0x0000), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><%parenleft><8>                                              */ DEADTRANS( L'8'	,0xE6EF	,0x2467	,0x0000), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><%parenleft><9>                                              */ DEADTRANS( L'9'	,0xE6EF	,0x2468	,0x0000), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><%parenleft><x>                                              */ DEADTRANS( L'x'	,0xE6EF	,0x2A34	,0x0000), // 'x' ➔ "⨴" MULTIPLICATION SIGN IN LEFT HALF CIRCLE
/*<!M><%parenright>                                                */ DEADTRANS( L')'	,0x00A6	,0xE75D	,0x0001), // Multikey chain
/*<!M><%parenright><%bracketright>                                 */ DEADTRANS( L']'	,0xE75D	,0xE75E	,0x0001), // Multikey chain
/*<!M><%parenright><%bracketright><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE75E	,0x2998	,0x0000), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenright><%bracketright><~space>                         */ DEADTRANS( L' '	,0xE75E	,0x2998	,0x0000), // ' ' ➔ "⦘" RIGHT BLACK TORTOISE SHELL BRACKET
/*<!M><%parenright><%circum>                                       */ DEADTRANS( L'^'	,0xE75D	,0xE761	,0x0001), // Multikey chain
/*<!M><%parenright><%circum><~nbspace>                             */ DEADTRANS( 0x00A0	,0xE761	,0x207E	,0x0000), // ' ' ➔ "⁾" SUPERSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><%circum><~space>                               */ DEADTRANS( L' '	,0xE761	,0x207E	,0x0000), // ' ' ➔ "⁾" SUPERSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><%greater>                                      */ DEADTRANS( L'>'	,0xE75D	,0x293B	,0x0000), // '>' ➔ "⤻" BOTTOM ARC ANTICLOCKWISE ARROW
/*<!M><%parenright><%less>                                         */ DEADTRANS( L'<'	,0xE75D	,0xE765	,0x0001), // Multikey chain
/*<!M><%parenright><%less><%parenright>                            */ DEADTRANS( L')'	,0xE765	,0x2996	,0x0000), // ')' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%parenright><%less><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE765	,0x2938	,0x0000), // ' ' ➔ "⤸" RIGHT-SIDE ARC CLOCKWISE ARROW
/*<!M><%parenright><%less><~space>                                 */ DEADTRANS( L' '	,0xE765	,0x2938	,0x0000), // ' ' ➔ "⤸" RIGHT-SIDE ARC CLOCKWISE ARROW
/*<!M><%parenright><%parenleft>                                    */ DEADTRANS( L'('	,0xE75D	,0xE769	,0x0001), // Multikey chain
/*<!M><%parenright><%parenleft><%slash>                            */ DEADTRANS( L'/'	,0xE769	,0x226D	,0x0000), // '/' ➔ "≭" NOT EQUIVALENT TO
/*<!M><%parenright><%parenleft><~nbspace>                          */ DEADTRANS( 0x00A0	,0xE769	,0x224D	,0x0000), // ' ' ➔ "≍" EQUIVALENT TO
/*<!M><%parenright><%parenleft><~space>                            */ DEADTRANS( L' '	,0xE769	,0x224D	,0x0000), // ' ' ➔ "≍" EQUIVALENT TO
/*<!M><%parenright><%parenright>                                   */ DEADTRANS( L')'	,0xE75D	,0xE76D	,0x0001), // Multikey chain
/*<!M><%parenright><%parenright><%bracketleft>                     */ DEADTRANS( L'['	,0xE76D	,0x27ED	,0x0000), // '[' ➔ "⟭" MATHEMATICAL RIGHT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenright><%parenright><%bracketright>                    */ DEADTRANS( L']'	,0xE76D	,0x27ED	,0x0000), // ']' ➔ "⟭" MATHEMATICAL RIGHT WHITE TORTOISE SHELL BRACKET
/*<!M><%parenright><%parenright><%less>                            */ DEADTRANS( L'<'	,0xE76D	,0x2996	,0x0000), // '<' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET
/*<!M><%parenright><%underscore>                                   */ DEADTRANS( L'_'	,0xE75D	,0xE771	,0x0001), // Multikey chain
/*<!M><%parenright><%underscore><%circum>                          */ DEADTRANS( L'^'	,0xE771	,0xE772	,0x0001), // Multikey chain
/*<!M><%parenright><%underscore><%circum><~nbspace>                */ DEADTRANS( 0x00A0	,0xE772	,0x27CC	,0x0000), // ' ' ➔ "⟌" LONG DIVISION
/*<!M><%parenright><%underscore><%circum><~space>                  */ DEADTRANS( L' '	,0xE772	,0x27CC	,0x0000), // ' ' ➔ "⟌" LONG DIVISION
/*<!M><%parenright><%underscore><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE771	,0x208E	,0x0000), // ' ' ➔ "₎" SUBSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><%underscore><~space>                           */ DEADTRANS( L' '	,0xE771	,0x208E	,0x0000), // ' ' ➔ "₎" SUBSCRIPT RIGHT PARENTHESIS
/*<!M><%parenright><0>                                             */ DEADTRANS( L'0'	,0xE75D	,0xE777	,0x0001), // Multikey chain
/*<!M><%parenright><0><0>                                          */ DEADTRANS( L'0'	,0xE777	,0xE778	,0x0001), // Multikey chain
/*<!M><%parenright><0><0><0>                                       */ DEADTRANS( L'0'	,0xE778	,0xE779	,0x0001), // Multikey chain
/*<!M><%parenright><0><0><0><1>                                    */ DEADTRANS( L'1'	,0xE779	,0x2575	,0x0000), // '1' ➔ "╵" BOX DRAWINGS LIGHT UP
/*<!M><%parenright><0><0><0><3>                                    */ DEADTRANS( L'3'	,0xE779	,0x2579	,0x0000), // '3' ➔ "╹" BOX DRAWINGS HEAVY UP
/*<!M><%parenright><0><0><1>                                       */ DEADTRANS( L'1'	,0xE778	,0xE77C	,0x0001), // Multikey chain
/*<!M><%parenright><0><0><1><0>                                    */ DEADTRANS( L'0'	,0xE77C	,0x2574	,0x0000), // '0' ➔ "╴" BOX DRAWINGS LIGHT LEFT
/*<!M><%parenright><0><0><1><1>                                    */ DEADTRANS( L'1'	,0xE77C	,0x2518	,0x0000), // '1' ➔ "┘" BOX DRAWINGS LIGHT UP AND LEFT
/*<!M><%parenright><0><0><1><2>                                    */ DEADTRANS( L'2'	,0xE77C	,0x255C	,0x0000), // '2' ➔ "╜" BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><0><1><3>                                    */ DEADTRANS( L'3'	,0xE77C	,0x251A	,0x0000), // '3' ➔ "┚" BOX DRAWINGS UP HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><0><2>                                       */ DEADTRANS( L'2'	,0xE778	,0xE781	,0x0001), // Multikey chain
/*<!M><%parenright><0><0><2><1>                                    */ DEADTRANS( L'1'	,0xE781	,0x255B	,0x0000), // '1' ➔ "╛" BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><0><2><2>                                    */ DEADTRANS( L'2'	,0xE781	,0x255D	,0x0000), // '2' ➔ "╝" BOX DRAWINGS DOUBLE UP AND LEFT
/*<!M><%parenright><0><0><3>                                       */ DEADTRANS( L'3'	,0xE778	,0xE784	,0x0001), // Multikey chain
/*<!M><%parenright><0><0><3><0>                                    */ DEADTRANS( L'0'	,0xE784	,0x2578	,0x0000), // '0' ➔ "╸" BOX DRAWINGS HEAVY LEFT
/*<!M><%parenright><0><0><3><1>                                    */ DEADTRANS( L'1'	,0xE784	,0x2519	,0x0000), // '1' ➔ "┙" BOX DRAWINGS UP LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><0><3><3>                                    */ DEADTRANS( L'3'	,0xE784	,0x251B	,0x0000), // '3' ➔ "┛" BOX DRAWINGS HEAVY UP AND LEFT
/*<!M><%parenright><0><1>                                          */ DEADTRANS( L'1'	,0xE777	,0xE788	,0x0001), // Multikey chain
/*<!M><%parenright><0><1><0>                                       */ DEADTRANS( L'0'	,0xE788	,0xE789	,0x0001), // Multikey chain
/*<!M><%parenright><0><1><0><0>                                    */ DEADTRANS( L'0'	,0xE789	,0x2577	,0x0000), // '0' ➔ "╷" BOX DRAWINGS LIGHT DOWN
/*<!M><%parenright><0><1><0><1>                                    */ DEADTRANS( L'1'	,0xE789	,0x2502	,0x0000), // '1' ➔ "│" BOX DRAWINGS LIGHT VERTICAL
/*<!M><%parenright><0><1><0><3>                                    */ DEADTRANS( L'3'	,0xE789	,0x257F	,0x0000), // '3' ➔ "╿" BOX DRAWINGS HEAVY UP AND LIGHT DOWN
/*<!M><%parenright><0><1><1>                                       */ DEADTRANS( L'1'	,0xE788	,0xE78D	,0x0001), // Multikey chain
/*<!M><%parenright><0><1><1><0>                                    */ DEADTRANS( L'0'	,0xE78D	,0x2510	,0x0000), // '0' ➔ "┐" BOX DRAWINGS LIGHT DOWN AND LEFT
/*<!M><%parenright><0><1><1><1>                                    */ DEADTRANS( L'1'	,0xE78D	,0x2524	,0x0000), // '1' ➔ "┤" BOX DRAWINGS LIGHT VERTICAL AND LEFT
/*<!M><%parenright><0><1><1><3>                                    */ DEADTRANS( L'3'	,0xE78D	,0x2526	,0x0000), // '3' ➔ "┦" BOX DRAWINGS UP HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><0><1><2>                                       */ DEADTRANS( L'2'	,0xE788	,0xE791	,0x0001), // Multikey chain
/*<!M><%parenright><0><1><2><0>                                    */ DEADTRANS( L'0'	,0xE791	,0x2555	,0x0000), // '0' ➔ "╕" BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><1><2><1>                                    */ DEADTRANS( L'1'	,0xE791	,0x2561	,0x0000), // '1' ➔ "╡" BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
/*<!M><%parenright><0><1><3>                                       */ DEADTRANS( L'3'	,0xE788	,0xE794	,0x0001), // Multikey chain
/*<!M><%parenright><0><1><3><0>                                    */ DEADTRANS( L'0'	,0xE794	,0x2511	,0x0000), // '0' ➔ "┑" BOX DRAWINGS DOWN LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><1><3><1>                                    */ DEADTRANS( L'1'	,0xE794	,0x2525	,0x0000), // '1' ➔ "┥" BOX DRAWINGS VERTICAL LIGHT AND LEFT HEAVY
/*<!M><%parenright><0><1><3><3>                                    */ DEADTRANS( L'3'	,0xE794	,0x2529	,0x0000), // '3' ➔ "┩" BOX DRAWINGS DOWN LIGHT AND LEFT UP HEAVY
/*<!M><%parenright><0><2>                                          */ DEADTRANS( L'2'	,0xE777	,0xE798	,0x0001), // Multikey chain
/*<!M><%parenright><0><2><0>                                       */ DEADTRANS( L'0'	,0xE798	,0xE799	,0x0001), // Multikey chain
/*<!M><%parenright><0><2><0><2>                                    */ DEADTRANS( L'2'	,0xE799	,0x2551	,0x0000), // '2' ➔ "║" BOX DRAWINGS DOUBLE VERTICAL
/*<!M><%parenright><0><2><1>                                       */ DEADTRANS( L'1'	,0xE798	,0xE79B	,0x0001), // Multikey chain
/*<!M><%parenright><0><2><1><0>                                    */ DEADTRANS( L'0'	,0xE79B	,0x2556	,0x0000), // '0' ➔ "╖" BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><2><1><2>                                    */ DEADTRANS( L'2'	,0xE79B	,0x2562	,0x0000), // '2' ➔ "╢" BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
/*<!M><%parenright><0><2><2>                                       */ DEADTRANS( L'2'	,0xE798	,0xE79E	,0x0001), // Multikey chain
/*<!M><%parenright><0><2><2><0>                                    */ DEADTRANS( L'0'	,0xE79E	,0x2557	,0x0000), // '0' ➔ "╗" BOX DRAWINGS DOUBLE DOWN AND LEFT
/*<!M><%parenright><0><2><2><2>                                    */ DEADTRANS( L'2'	,0xE79E	,0x2563	,0x0000), // '2' ➔ "╣" BOX DRAWINGS DOUBLE VERTICAL AND LEFT
/*<!M><%parenright><0><3>                                          */ DEADTRANS( L'3'	,0xE777	,0xE7A1	,0x0001), // Multikey chain
/*<!M><%parenright><0><3><0>                                       */ DEADTRANS( L'0'	,0xE7A1	,0xE7A2	,0x0001), // Multikey chain
/*<!M><%parenright><0><3><0><0>                                    */ DEADTRANS( L'0'	,0xE7A2	,0x257B	,0x0000), // '0' ➔ "╻" BOX DRAWINGS HEAVY DOWN
/*<!M><%parenright><0><3><0><1>                                    */ DEADTRANS( L'1'	,0xE7A2	,0x257D	,0x0000), // '1' ➔ "╽" BOX DRAWINGS LIGHT UP AND HEAVY DOWN
/*<!M><%parenright><0><3><0><3>                                    */ DEADTRANS( L'3'	,0xE7A2	,0x2503	,0x0000), // '3' ➔ "┃" BOX DRAWINGS HEAVY VERTICAL
/*<!M><%parenright><0><3><1>                                       */ DEADTRANS( L'1'	,0xE7A1	,0xE7A6	,0x0001), // Multikey chain
/*<!M><%parenright><0><3><1><0>                                    */ DEADTRANS( L'0'	,0xE7A6	,0x2512	,0x0000), // '0' ➔ "┒" BOX DRAWINGS DOWN HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><3><1><1>                                    */ DEADTRANS( L'1'	,0xE7A6	,0x2527	,0x0000), // '1' ➔ "┧" BOX DRAWINGS DOWN HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><0><3><1><3>                                    */ DEADTRANS( L'3'	,0xE7A6	,0x2528	,0x0000), // '3' ➔ "┨" BOX DRAWINGS VERTICAL HEAVY AND LEFT LIGHT
/*<!M><%parenright><0><3><3>                                       */ DEADTRANS( L'3'	,0xE7A1	,0xE7AA	,0x0001), // Multikey chain
/*<!M><%parenright><0><3><3><0>                                    */ DEADTRANS( L'0'	,0xE7AA	,0x2513	,0x0000), // '0' ➔ "┓" BOX DRAWINGS HEAVY DOWN AND LEFT
/*<!M><%parenright><0><3><3><1>                                    */ DEADTRANS( L'1'	,0xE7AA	,0x252A	,0x0000), // '1' ➔ "┪" BOX DRAWINGS UP LIGHT AND LEFT DOWN HEAVY
/*<!M><%parenright><0><3><3><3>                                    */ DEADTRANS( L'3'	,0xE7AA	,0x252B	,0x0000), // '3' ➔ "┫" BOX DRAWINGS HEAVY VERTICAL AND LEFT
/*<!M><%parenright><1>                                             */ DEADTRANS( L'1'	,0xE75D	,0xE7AE	,0x0001), // Multikey chain
/*<!M><%parenright><1><0>                                          */ DEADTRANS( L'0'	,0xE7AE	,0xE7AF	,0x0001), // Multikey chain
/*<!M><%parenright><1><0><0>                                       */ DEADTRANS( L'0'	,0xE7AF	,0xE7B0	,0x0001), // Multikey chain
/*<!M><%parenright><1><0><0><0>                                    */ DEADTRANS( L'0'	,0xE7B0	,0x2576	,0x0000), // '0' ➔ "╶" BOX DRAWINGS LIGHT RIGHT
/*<!M><%parenright><1><0><0><1>                                    */ DEADTRANS( L'1'	,0xE7B0	,0x2514	,0x0000), // '1' ➔ "└" BOX DRAWINGS LIGHT UP AND RIGHT
/*<!M><%parenright><1><0><0><2>                                    */ DEADTRANS( L'2'	,0xE7B0	,0x2559	,0x0000), // '2' ➔ "╙" BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><0><0><3>                                    */ DEADTRANS( L'3'	,0xE7B0	,0x2516	,0x0000), // '3' ➔ "┖" BOX DRAWINGS UP HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><0><1>                                       */ DEADTRANS( L'1'	,0xE7AF	,0xE7B5	,0x0001), // Multikey chain
/*<!M><%parenright><1><0><1><0>                                    */ DEADTRANS( L'0'	,0xE7B5	,0x2500	,0x0000), // '0' ➔ "─" BOX DRAWINGS LIGHT HORIZONTAL
/*<!M><%parenright><1><0><1><1>                                    */ DEADTRANS( L'1'	,0xE7B5	,0x2534	,0x0000), // '1' ➔ "┴" BOX DRAWINGS LIGHT UP AND HORIZONTAL
/*<!M><%parenright><1><0><1><2>                                    */ DEADTRANS( L'2'	,0xE7B5	,0x2568	,0x0000), // '2' ➔ "╨" BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><0><1><3>                                    */ DEADTRANS( L'3'	,0xE7B5	,0x2538	,0x0000), // '3' ➔ "┸" BOX DRAWINGS UP HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><0><3>                                       */ DEADTRANS( L'3'	,0xE7AF	,0xE7BA	,0x0001), // Multikey chain
/*<!M><%parenright><1><0><3><0>                                    */ DEADTRANS( L'0'	,0xE7BA	,0x257E	,0x0000), // '0' ➔ "╾" BOX DRAWINGS HEAVY LEFT AND LIGHT RIGHT
/*<!M><%parenright><1><0><3><1>                                    */ DEADTRANS( L'1'	,0xE7BA	,0x2535	,0x0000), // '1' ➔ "┵" BOX DRAWINGS LEFT HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><0><3><3>                                    */ DEADTRANS( L'3'	,0xE7BA	,0x2539	,0x0000), // '3' ➔ "┹" BOX DRAWINGS RIGHT LIGHT AND LEFT UP HEAVY
/*<!M><%parenright><1><1>                                          */ DEADTRANS( L'1'	,0xE7AE	,0xE7BE	,0x0001), // Multikey chain
/*<!M><%parenright><1><1><0>                                       */ DEADTRANS( L'0'	,0xE7BE	,0xE7BF	,0x0001), // Multikey chain
/*<!M><%parenright><1><1><0><0>                                    */ DEADTRANS( L'0'	,0xE7BF	,0x250C	,0x0000), // '0' ➔ "┌" BOX DRAWINGS LIGHT DOWN AND RIGHT
/*<!M><%parenright><1><1><0><1>                                    */ DEADTRANS( L'1'	,0xE7BF	,0x251C	,0x0000), // '1' ➔ "├" BOX DRAWINGS LIGHT VERTICAL AND RIGHT
/*<!M><%parenright><1><1><0><3>                                    */ DEADTRANS( L'3'	,0xE7BF	,0x251E	,0x0000), // '3' ➔ "┞" BOX DRAWINGS UP HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><1><1>                                       */ DEADTRANS( L'1'	,0xE7BE	,0xE7C3	,0x0001), // Multikey chain
/*<!M><%parenright><1><1><1><0>                                    */ DEADTRANS( L'0'	,0xE7C3	,0x252C	,0x0000), // '0' ➔ "┬" BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
/*<!M><%parenright><1><1><1><1>                                    */ DEADTRANS( L'1'	,0xE7C3	,0x253C	,0x0000), // '1' ➔ "┼" BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
/*<!M><%parenright><1><1><1><3>                                    */ DEADTRANS( L'3'	,0xE7C3	,0x2540	,0x0000), // '3' ➔ "╀" BOX DRAWINGS UP HEAVY AND DOWN HORIZONTAL LIGHT
/*<!M><%parenright><1><1><3>                                       */ DEADTRANS( L'3'	,0xE7BE	,0xE7C7	,0x0001), // Multikey chain
/*<!M><%parenright><1><1><3><0>                                    */ DEADTRANS( L'0'	,0xE7C7	,0x252D	,0x0000), // '0' ➔ "┭" BOX DRAWINGS LEFT HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><1><3><1>                                    */ DEADTRANS( L'1'	,0xE7C7	,0x253D	,0x0000), // '1' ➔ "┽" BOX DRAWINGS LEFT HEAVY AND RIGHT VERTICAL LIGHT
/*<!M><%parenright><1><1><3><3>                                    */ DEADTRANS( L'3'	,0xE7C7	,0x2543	,0x0000), // '3' ➔ "╃" BOX DRAWINGS LEFT UP HEAVY AND RIGHT DOWN LIGHT
/*<!M><%parenright><1><2>                                          */ DEADTRANS( L'2'	,0xE7AE	,0xE7CB	,0x0001), // Multikey chain
/*<!M><%parenright><1><2><0>                                       */ DEADTRANS( L'0'	,0xE7CB	,0xE7CC	,0x0001), // Multikey chain
/*<!M><%parenright><1><2><0><0>                                    */ DEADTRANS( L'0'	,0xE7CC	,0x2553	,0x0000), // '0' ➔ "╓" BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><2><0><2>                                    */ DEADTRANS( L'2'	,0xE7CC	,0x255F	,0x0000), // '2' ➔ "╟" BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
/*<!M><%parenright><1><2><1>                                       */ DEADTRANS( L'1'	,0xE7CB	,0xE7CF	,0x0001), // Multikey chain
/*<!M><%parenright><1><2><1><0>                                    */ DEADTRANS( L'0'	,0xE7CF	,0x2565	,0x0000), // '0' ➔ "╥" BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><2><1><2>                                    */ DEADTRANS( L'2'	,0xE7CF	,0x256B	,0x0000), // '2' ➔ "╫" BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
/*<!M><%parenright><1><2><d>                                       */ DEADTRANS( L'd'	,0xE7CB	,0x2573	,0x0000), // 'd' ➔ "╳" BOX DRAWINGS LIGHT DIAGONAL CROSS
/*<!M><%parenright><1><3>                                          */ DEADTRANS( L'3'	,0xE7AE	,0xE7D3	,0x0001), // Multikey chain
/*<!M><%parenright><1><3><0>                                       */ DEADTRANS( L'0'	,0xE7D3	,0xE7D4	,0x0001), // Multikey chain
/*<!M><%parenright><1><3><0><0>                                    */ DEADTRANS( L'0'	,0xE7D4	,0x250E	,0x0000), // '0' ➔ "┎" BOX DRAWINGS DOWN HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><3><0><1>                                    */ DEADTRANS( L'1'	,0xE7D4	,0x251F	,0x0000), // '1' ➔ "┟" BOX DRAWINGS DOWN HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><3><0><3>                                    */ DEADTRANS( L'3'	,0xE7D4	,0x2520	,0x0000), // '3' ➔ "┠" BOX DRAWINGS VERTICAL HEAVY AND RIGHT LIGHT
/*<!M><%parenright><1><3><1>                                       */ DEADTRANS( L'1'	,0xE7D3	,0xE7D8	,0x0001), // Multikey chain
/*<!M><%parenright><1><3><1><0>                                    */ DEADTRANS( L'0'	,0xE7D8	,0x2530	,0x0000), // '0' ➔ "┰" BOX DRAWINGS DOWN HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><3><1><1>                                    */ DEADTRANS( L'1'	,0xE7D8	,0x2541	,0x0000), // '1' ➔ "╁" BOX DRAWINGS DOWN HEAVY AND UP HORIZONTAL LIGHT
/*<!M><%parenright><1><3><1><3>                                    */ DEADTRANS( L'3'	,0xE7D8	,0x2542	,0x0000), // '3' ➔ "╂" BOX DRAWINGS VERTICAL HEAVY AND HORIZONTAL LIGHT
/*<!M><%parenright><1><3><3>                                       */ DEADTRANS( L'3'	,0xE7D3	,0xE7DC	,0x0001), // Multikey chain
/*<!M><%parenright><1><3><3><0>                                    */ DEADTRANS( L'0'	,0xE7DC	,0x2531	,0x0000), // '0' ➔ "┱" BOX DRAWINGS RIGHT LIGHT AND LEFT DOWN HEAVY
/*<!M><%parenright><1><3><3><1>                                    */ DEADTRANS( L'1'	,0xE7DC	,0x2545	,0x0000), // '1' ➔ "╅" BOX DRAWINGS LEFT DOWN HEAVY AND RIGHT UP LIGHT
/*<!M><%parenright><1><3><3><3>                                    */ DEADTRANS( L'3'	,0xE7DC	,0x2549	,0x0000), // '3' ➔ "╉" BOX DRAWINGS RIGHT LIGHT AND LEFT VERTICAL HEAVY
/*<!M><%parenright><1><d>                                          */ DEADTRANS( L'd'	,0xE7AE	,0x2571	,0x0000), // 'd' ➔ "╱" BOX DRAWINGS LIGHT DIAGONAL UPPER RIGHT TO LOWER LEFT
/*<!M><%parenright><2>                                             */ DEADTRANS( L'2'	,0xE75D	,0xE7E1	,0x0001), // Multikey chain
/*<!M><%parenright><2><0>                                          */ DEADTRANS( L'0'	,0xE7E1	,0xE7E2	,0x0001), // Multikey chain
/*<!M><%parenright><2><0><0>                                       */ DEADTRANS( L'0'	,0xE7E2	,0xE7E3	,0x0001), // Multikey chain
/*<!M><%parenright><2><0><0><1>                                    */ DEADTRANS( L'1'	,0xE7E3	,0x2558	,0x0000), // '1' ➔ "╘" BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><0><0><2>                                    */ DEADTRANS( L'2'	,0xE7E3	,0x255A	,0x0000), // '2' ➔ "╚" BOX DRAWINGS DOUBLE UP AND RIGHT
/*<!M><%parenright><2><0><2>                                       */ DEADTRANS( L'2'	,0xE7E2	,0xE7E6	,0x0001), // Multikey chain
/*<!M><%parenright><2><0><2><0>                                    */ DEADTRANS( L'0'	,0xE7E6	,0x2550	,0x0000), // '0' ➔ "═" BOX DRAWINGS DOUBLE HORIZONTAL
/*<!M><%parenright><2><0><2><1>                                    */ DEADTRANS( L'1'	,0xE7E6	,0x2567	,0x0000), // '1' ➔ "╧" BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><0><2><2>                                    */ DEADTRANS( L'2'	,0xE7E6	,0x2569	,0x0000), // '2' ➔ "╩" BOX DRAWINGS DOUBLE UP AND HORIZONTAL
/*<!M><%parenright><2><1>                                          */ DEADTRANS( L'1'	,0xE7E1	,0xE7EA	,0x0001), // Multikey chain
/*<!M><%parenright><2><1><0>                                       */ DEADTRANS( L'0'	,0xE7EA	,0xE7EB	,0x0001), // Multikey chain
/*<!M><%parenright><2><1><0><0>                                    */ DEADTRANS( L'0'	,0xE7EB	,0x2552	,0x0000), // '0' ➔ "╒" BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><1><0><1>                                    */ DEADTRANS( L'1'	,0xE7EB	,0x255E	,0x0000), // '1' ➔ "╞" BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
/*<!M><%parenright><2><1><2>                                       */ DEADTRANS( L'2'	,0xE7EA	,0xE7EE	,0x0001), // Multikey chain
/*<!M><%parenright><2><1><2><0>                                    */ DEADTRANS( L'0'	,0xE7EE	,0x2564	,0x0000), // '0' ➔ "╤" BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><1><2><1>                                    */ DEADTRANS( L'1'	,0xE7EE	,0x256A	,0x0000), // '1' ➔ "╪" BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
/*<!M><%parenright><2><1><d>                                       */ DEADTRANS( L'd'	,0xE7EA	,0x2573	,0x0000), // 'd' ➔ "╳" BOX DRAWINGS LIGHT DIAGONAL CROSS
/*<!M><%parenright><2><2>                                          */ DEADTRANS( L'2'	,0xE7E1	,0xE7F2	,0x0001), // Multikey chain
/*<!M><%parenright><2><2><0>                                       */ DEADTRANS( L'0'	,0xE7F2	,0xE7F3	,0x0001), // Multikey chain
/*<!M><%parenright><2><2><0><0>                                    */ DEADTRANS( L'0'	,0xE7F3	,0x2554	,0x0000), // '0' ➔ "╔" BOX DRAWINGS DOUBLE DOWN AND RIGHT
/*<!M><%parenright><2><2><0><2>                                    */ DEADTRANS( L'2'	,0xE7F3	,0x2560	,0x0000), // '2' ➔ "╠" BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
/*<!M><%parenright><2><2><2>                                       */ DEADTRANS( L'2'	,0xE7F2	,0xE7F6	,0x0001), // Multikey chain
/*<!M><%parenright><2><2><2><0>                                    */ DEADTRANS( L'0'	,0xE7F6	,0x2566	,0x0000), // '0' ➔ "╦" BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
/*<!M><%parenright><2><2><2><2>                                    */ DEADTRANS( L'2'	,0xE7F6	,0x256C	,0x0000), // '2' ➔ "╬" BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
/*<!M><%parenright><2><2><h>                                       */ DEADTRANS( L'h'	,0xE7F2	,0x254D	,0x0000), // 'h' ➔ "╍" BOX DRAWINGS HEAVY DOUBLE DASH HORIZONTAL
/*<!M><%parenright><2><2><v>                                       */ DEADTRANS( L'v'	,0xE7F2	,0x254F	,0x0000), // 'v' ➔ "╏" BOX DRAWINGS HEAVY DOUBLE DASH VERTICAL
/*<!M><%parenright><2><d>                                          */ DEADTRANS( L'd'	,0xE7E1	,0x2572	,0x0000), // 'd' ➔ "╲" BOX DRAWINGS LIGHT DIAGONAL UPPER LEFT TO LOWER RIGHT
/*<!M><%parenright><2><h>                                          */ DEADTRANS( L'h'	,0xE7E1	,0x254C	,0x0000), // 'h' ➔ "╌" BOX DRAWINGS LIGHT DOUBLE DASH HORIZONTAL
/*<!M><%parenright><2><v>                                          */ DEADTRANS( L'v'	,0xE7E1	,0x254E	,0x0000), // 'v' ➔ "╎" BOX DRAWINGS LIGHT DOUBLE DASH VERTICAL
/*<!M><%parenright><3>                                             */ DEADTRANS( L'3'	,0xE75D	,0xE7FE	,0x0001), // Multikey chain
/*<!M><%parenright><3><0>                                          */ DEADTRANS( L'0'	,0xE7FE	,0xE7FF	,0x0001), // Multikey chain
/*<!M><%parenright><3><0><0>                                       */ DEADTRANS( L'0'	,0xE7FF	,0xE800	,0x0001), // Multikey chain
/*<!M><%parenright><3><0><0><0>                                    */ DEADTRANS( L'0'	,0xE800	,0x257A	,0x0000), // '0' ➔ "╺" BOX DRAWINGS HEAVY RIGHT
/*<!M><%parenright><3><0><0><1>                                    */ DEADTRANS( L'1'	,0xE800	,0x2515	,0x0000), // '1' ➔ "┕" BOX DRAWINGS UP LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><0><0><3>                                    */ DEADTRANS( L'3'	,0xE800	,0x2517	,0x0000), // '3' ➔ "┗" BOX DRAWINGS HEAVY UP AND RIGHT
/*<!M><%parenright><3><0><1>                                       */ DEADTRANS( L'1'	,0xE7FF	,0xE804	,0x0001), // Multikey chain
/*<!M><%parenright><3><0><1><0>                                    */ DEADTRANS( L'0'	,0xE804	,0x257C	,0x0000), // '0' ➔ "╼" BOX DRAWINGS LIGHT LEFT AND HEAVY RIGHT
/*<!M><%parenright><3><0><1><1>                                    */ DEADTRANS( L'1'	,0xE804	,0x2536	,0x0000), // '1' ➔ "┶" BOX DRAWINGS RIGHT HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><3><0><1><3>                                    */ DEADTRANS( L'3'	,0xE804	,0x253A	,0x0000), // '3' ➔ "┺" BOX DRAWINGS LEFT LIGHT AND RIGHT UP HEAVY
/*<!M><%parenright><3><0><3>                                       */ DEADTRANS( L'3'	,0xE7FF	,0xE808	,0x0001), // Multikey chain
/*<!M><%parenright><3><0><3><0>                                    */ DEADTRANS( L'0'	,0xE808	,0x2501	,0x0000), // '0' ➔ "━" BOX DRAWINGS HEAVY HORIZONTAL
/*<!M><%parenright><3><0><3><1>                                    */ DEADTRANS( L'1'	,0xE808	,0x2537	,0x0000), // '1' ➔ "┷" BOX DRAWINGS UP LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><0><3><3>                                    */ DEADTRANS( L'3'	,0xE808	,0x253B	,0x0000), // '3' ➔ "┻" BOX DRAWINGS HEAVY UP AND HORIZONTAL
/*<!M><%parenright><3><1>                                          */ DEADTRANS( L'1'	,0xE7FE	,0xE80C	,0x0001), // Multikey chain
/*<!M><%parenright><3><1><0>                                       */ DEADTRANS( L'0'	,0xE80C	,0xE80D	,0x0001), // Multikey chain
/*<!M><%parenright><3><1><0><0>                                    */ DEADTRANS( L'0'	,0xE80D	,0x250D	,0x0000), // '0' ➔ "┍" BOX DRAWINGS DOWN LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><1><0><1>                                    */ DEADTRANS( L'1'	,0xE80D	,0x251D	,0x0000), // '1' ➔ "┝" BOX DRAWINGS VERTICAL LIGHT AND RIGHT HEAVY
/*<!M><%parenright><3><1><0><3>                                    */ DEADTRANS( L'3'	,0xE80D	,0x2521	,0x0000), // '3' ➔ "┡" BOX DRAWINGS DOWN LIGHT AND RIGHT UP HEAVY
/*<!M><%parenright><3><1><1>                                       */ DEADTRANS( L'1'	,0xE80C	,0xE811	,0x0001), // Multikey chain
/*<!M><%parenright><3><1><1><0>                                    */ DEADTRANS( L'0'	,0xE811	,0x252E	,0x0000), // '0' ➔ "┮" BOX DRAWINGS RIGHT HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><3><1><1><1>                                    */ DEADTRANS( L'1'	,0xE811	,0x253E	,0x0000), // '1' ➔ "┾" BOX DRAWINGS RIGHT HEAVY AND LEFT VERTICAL LIGHT
/*<!M><%parenright><3><1><1><3>                                    */ DEADTRANS( L'3'	,0xE811	,0x2544	,0x0000), // '3' ➔ "╄" BOX DRAWINGS RIGHT UP HEAVY AND LEFT DOWN LIGHT
/*<!M><%parenright><3><1><3>                                       */ DEADTRANS( L'3'	,0xE80C	,0xE815	,0x0001), // Multikey chain
/*<!M><%parenright><3><1><3><0>                                    */ DEADTRANS( L'0'	,0xE815	,0x252F	,0x0000), // '0' ➔ "┯" BOX DRAWINGS DOWN LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><1><3><1>                                    */ DEADTRANS( L'1'	,0xE815	,0x253F	,0x0000), // '1' ➔ "┿" BOX DRAWINGS VERTICAL LIGHT AND HORIZONTAL HEAVY
/*<!M><%parenright><3><1><3><3>                                    */ DEADTRANS( L'3'	,0xE815	,0x2547	,0x0000), // '3' ➔ "╇" BOX DRAWINGS DOWN LIGHT AND UP HORIZONTAL HEAVY
/*<!M><%parenright><3><3>                                          */ DEADTRANS( L'3'	,0xE7FE	,0xE819	,0x0001), // Multikey chain
/*<!M><%parenright><3><3><0>                                       */ DEADTRANS( L'0'	,0xE819	,0xE81A	,0x0001), // Multikey chain
/*<!M><%parenright><3><3><0><0>                                    */ DEADTRANS( L'0'	,0xE81A	,0x250F	,0x0000), // '0' ➔ "┏" BOX DRAWINGS HEAVY DOWN AND RIGHT
/*<!M><%parenright><3><3><0><1>                                    */ DEADTRANS( L'1'	,0xE81A	,0x2522	,0x0000), // '1' ➔ "┢" BOX DRAWINGS UP LIGHT AND RIGHT DOWN HEAVY
/*<!M><%parenright><3><3><0><3>                                    */ DEADTRANS( L'3'	,0xE81A	,0x2523	,0x0000), // '3' ➔ "┣" BOX DRAWINGS HEAVY VERTICAL AND RIGHT
/*<!M><%parenright><3><3><1>                                       */ DEADTRANS( L'1'	,0xE819	,0xE81E	,0x0001), // Multikey chain
/*<!M><%parenright><3><3><1><0>                                    */ DEADTRANS( L'0'	,0xE81E	,0x2532	,0x0000), // '0' ➔ "┲" BOX DRAWINGS LEFT LIGHT AND RIGHT DOWN HEAVY
/*<!M><%parenright><3><3><1><1>                                    */ DEADTRANS( L'1'	,0xE81E	,0x2546	,0x0000), // '1' ➔ "╆" BOX DRAWINGS RIGHT DOWN HEAVY AND LEFT UP LIGHT
/*<!M><%parenright><3><3><1><3>                                    */ DEADTRANS( L'3'	,0xE81E	,0x254A	,0x0000), // '3' ➔ "╊" BOX DRAWINGS LEFT LIGHT AND RIGHT VERTICAL HEAVY
/*<!M><%parenright><3><3><3>                                       */ DEADTRANS( L'3'	,0xE819	,0xE822	,0x0001), // Multikey chain
/*<!M><%parenright><3><3><3><0>                                    */ DEADTRANS( L'0'	,0xE822	,0x2533	,0x0000), // '0' ➔ "┳" BOX DRAWINGS HEAVY DOWN AND HORIZONTAL
/*<!M><%parenright><3><3><3><1>                                    */ DEADTRANS( L'1'	,0xE822	,0x2548	,0x0000), // '1' ➔ "╈" BOX DRAWINGS UP LIGHT AND DOWN HORIZONTAL HEAVY
/*<!M><%parenright><3><3><3><3>                                    */ DEADTRANS( L'3'	,0xE822	,0x254B	,0x0000), // '3' ➔ "╋" BOX DRAWINGS HEAVY VERTICAL AND HORIZONTAL
/*<!M><%parenright><3><3><h>                                       */ DEADTRANS( L'h'	,0xE819	,0x2505	,0x0000), // 'h' ➔ "┅" BOX DRAWINGS HEAVY TRIPLE DASH HORIZONTAL
/*<!M><%parenright><3><3><v>                                       */ DEADTRANS( L'v'	,0xE819	,0x2507	,0x0000), // 'v' ➔ "┇" BOX DRAWINGS HEAVY TRIPLE DASH VERTICAL
/*<!M><%parenright><3><h>                                          */ DEADTRANS( L'h'	,0xE7FE	,0x2504	,0x0000), // 'h' ➔ "┄" BOX DRAWINGS LIGHT TRIPLE DASH HORIZONTAL
/*<!M><%parenright><3><v>                                          */ DEADTRANS( L'v'	,0xE7FE	,0x2506	,0x0000), // 'v' ➔ "┆" BOX DRAWINGS LIGHT TRIPLE DASH VERTICAL
/*<!M><%parenright><4>                                             */ DEADTRANS( L'4'	,0xE75D	,0xE82A	,0x0001), // Multikey chain
/*<!M><%parenright><4><4>                                          */ DEADTRANS( L'4'	,0xE82A	,0xE82B	,0x0001), // Multikey chain
/*<!M><%parenright><4><4><h>                                       */ DEADTRANS( L'h'	,0xE82B	,0x2509	,0x0000), // 'h' ➔ "┉" BOX DRAWINGS HEAVY QUADRUPLE DASH HORIZONTAL
/*<!M><%parenright><4><4><v>                                       */ DEADTRANS( L'v'	,0xE82B	,0x250B	,0x0000), // 'v' ➔ "┋" BOX DRAWINGS HEAVY QUADRUPLE DASH VERTICAL
/*<!M><%parenright><4><h>                                          */ DEADTRANS( L'h'	,0xE82A	,0x2508	,0x0000), // 'h' ➔ "┈" BOX DRAWINGS LIGHT QUADRUPLE DASH HORIZONTAL
/*<!M><%parenright><4><v>                                          */ DEADTRANS( L'v'	,0xE82A	,0x250A	,0x0000), // 'v' ➔ "┊" BOX DRAWINGS LIGHT QUADRUPLE DASH VERTICAL
/*<!M><%period>                                                    */ DEADTRANS( L'.'	,0x00A6	,0xE830	,0x0001), // Multikey chain
/*<!M><%period><%backslash>                                        */ DEADTRANS( L'\\'	,0xE830	,0x29CA	,0x0000), // '\' ➔ "⧊" TRIANGLE WITH DOT ABOVE
/*<!M><%period><%circum>                                           */ DEADTRANS( L'^'	,0xE830	,0x00B7	,0x0000), // '^' ➔ "·" MIDDLE DOT
/*<!M><%period><%colon>                                            */ DEADTRANS( L':'	,0xE830	,0x2AF6	,0x0000), // ':' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><%period><%equal>                                            */ DEADTRANS( L'='	,0xE830	,0xE834	,0x0001), // Multikey chain
/*<!M><%period><%equal><%minus>                                    */ DEADTRANS( L'-'	,0xE834	,0x2A67	,0x0000), // '-' ➔ "⩧" IDENTICAL WITH DOT ABOVE
/*<!M><%period><%equal><%period>                                   */ DEADTRANS( L'.'	,0xE834	,0xE836	,0x0001), // Multikey chain
/*<!M><%period><%equal><%period><%backslash>                       */ DEADTRANS( L'\\'	,0xE836	,0x2252	,0x0000), // '\' ➔ "≒" APPROXIMATELY EQUAL TO OR THE IMAGE OF
/*<!M><%period><%equal><%period><%slash>                           */ DEADTRANS( L'/'	,0xE836	,0x2253	,0x0000), // '/' ➔ "≓" IMAGE OF OR APPROXIMATELY EQUAL TO
/*<!M><%period><%equal><%period><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE836	,0x2251	,0x0000), // ' ' ➔ "≑" GEOMETRICALLY EQUAL TO
/*<!M><%period><%equal><%period><~space>                           */ DEADTRANS( L' '	,0xE836	,0x2251	,0x0000), // ' ' ➔ "≑" GEOMETRICALLY EQUAL TO
/*<!M><%period><%equal><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE834	,0x2250	,0x0000), // ' ' ➔ "≐" APPROACHES THE LIMIT
/*<!M><%period><%equal><~space>                                    */ DEADTRANS( L' '	,0xE834	,0x2250	,0x0000), // ' ' ➔ "≐" APPROACHES THE LIMIT
/*<!M><%period><%greater>                                          */ DEADTRANS( L'>'	,0xE830	,0xE83D	,0x0001), // Multikey chain
/*<!M><%period><%greater><%bracketleft>                            */ DEADTRANS( L'['	,0xE83D	,0x2992	,0x0000), // '[' ➔ "⦒" RIGHT ANGLE BRACKET WITH DOT
/*<!M><%period><%greater><%bracketright>                           */ DEADTRANS( L']'	,0xE83D	,0x2992	,0x0000), // ']' ➔ "⦒" RIGHT ANGLE BRACKET WITH DOT
/*<!M><%period><%greater><%less>                                   */ DEADTRANS( L'<'	,0xE83D	,0x2944	,0x0000), // '<' ➔ "⥄" SHORT RIGHTWARDS ARROW ABOVE LEFTWARDS ARROW
/*<!M><%period><%greater><%underscore>                             */ DEADTRANS( L'_'	,0xE83D	,0x2A84	,0x0000), // '_' ➔ "⪄" GREATER-THAN OR SLANTED EQUAL TO WITH DOT ABOVE LEFT
/*<!M><%period><%greater><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE83D	,0x22D7	,0x0000), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%period><%greater><~space>                                  */ DEADTRANS( L' '	,0xE83D	,0x22D7	,0x0000), // ' ' ➔ "⋗" GREATER-THAN WITH DOT
/*<!M><%period><%less>                                             */ DEADTRANS( L'<'	,0xE830	,0x2A81	,0x0000), // '<' ➔ "⪁" LESS-THAN OR SLANTED EQUAL TO WITH DOT ABOVE
/*<!M><%period><%minus>                                            */ DEADTRANS( L'-'	,0xE830	,0xE845	,0x0001), // Multikey chain
/*<!M><%period><%minus><%equal>                                    */ DEADTRANS( L'='	,0xE845	,0x2A67	,0x0000), // '=' ➔ "⩧" IDENTICAL WITH DOT ABOVE
/*<!M><%period><%minus><%period>                                   */ DEADTRANS( L'.'	,0xE845	,0xE847	,0x0001), // Multikey chain
/*<!M><%period><%minus><%period><%backslash>                       */ DEADTRANS( L'\\'	,0xE847	,0x2A2B	,0x0000), // '\' ➔ "⨫" MINUS SIGN WITH FALLING DOTS
/*<!M><%period><%minus><%period><%slash>                           */ DEADTRANS( L'/'	,0xE847	,0x2A2C	,0x0000), // '/' ➔ "⨬" MINUS SIGN WITH RISING DOTS
/*<!M><%period><%minus><%period><x>                                */ DEADTRANS( L'x'	,0xE847	,0x22C7	,0x0000), // 'x' ➔ "⋇" DIVISION TIMES
/*<!M><%period><%minus><%period><~nbspace>                         */ DEADTRANS( 0x00A0	,0xE847	,0x00F7	,0x0000), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%period><%minus><%period><~space>                           */ DEADTRANS( L' '	,0xE847	,0x00F7	,0x0000), // ' ' ➔ "÷" DIVISION SIGN
/*<!M><%period><%minus><o>                                         */ DEADTRANS( L'o'	,0xE845	,0x22B7	,0x0000), // 'o' ➔ "⊷" IMAGE OF
/*<!M><%period><%minus><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE845	,0x2238	,0x0000), // ' ' ➔ "∸" DOT MINUS
/*<!M><%period><%minus><~space>                                    */ DEADTRANS( L' '	,0xE845	,0x2238	,0x0000), // ' ' ➔ "∸" DOT MINUS
/*<!M><%period><%period>                                           */ DEADTRANS( L'.'	,0xE830	,0xE850	,0x0001), // Multikey chain
/*<!M><%period><%period><%equal>                                   */ DEADTRANS( L'='	,0xE850	,0x2A77	,0x0000), // '=' ➔ "⩷" EQUALS SIGN WITH TWO DOTS ABOVE AND TWO DOTS BELOW
/*<!M><%period><%period><%greater>                                 */ DEADTRANS( L'>'	,0xE850	,0x2911	,0x0000), // '>' ➔ "⤑" RIGHTWARDS ARROW WITH DOTTED STEM
/*<!M><%period><%period><%period>                                  */ DEADTRANS( L'.'	,0xE850	,0xE853	,0x0001), // Multikey chain
/*<!M><%period><%period><%period><%backslash>                      */ DEADTRANS( L'\\'	,0xE853	,0x22F1	,0x0000), // '\' ➔ "⋱" DOWN RIGHT DIAGONAL ELLIPSIS
/*<!M><%period><%period><%period><%bar>                            */ DEADTRANS( L'|'	,0xE853	,0x22EE	,0x0000), // '|' ➔ "⋮" VERTICAL ELLIPSIS
/*<!M><%period><%period><%period><%exclam>                         */ DEADTRANS( L'!'	,0xE853	,0x22EE	,0x0000), // '!' ➔ "⋮" VERTICAL ELLIPSIS
/*<!M><%period><%period><%period><%greater>                        */ DEADTRANS( L'>'	,0xE853	,0x2911	,0x0000), // '>' ➔ "⤑" RIGHTWARDS ARROW WITH DOTTED STEM
/*<!M><%period><%period><%period><%minus>                          */ DEADTRANS( L'-'	,0xE853	,0x22EF	,0x0000), // '-' ➔ "⋯" MIDLINE HORIZONTAL ELLIPSIS
/*<!M><%period><%period><%period><%period>                         */ DEADTRANS( L'.'	,0xE853	,0x2A78	,0x0000), // '.' ➔ "⩸" EQUIVALENT WITH FOUR DOTS ABOVE
/*<!M><%period><%period><%period><%slash>                          */ DEADTRANS( L'/'	,0xE853	,0x22F0	,0x0000), // '/' ➔ "⋰" UP RIGHT DIAGONAL ELLIPSIS
/*<!M><%period><%period><%period><%underscore>                     */ DEADTRANS( L'_'	,0xE853	,0x2026	,0x0000), // '_' ➔ "…" HORIZONTAL ELLIPSIS
/*<!M><%period><%period><%period><a>                               */ DEADTRANS( L'a'	,0xE853	,0x2234	,0x0000), // 'a' ➔ "∴" THEREFORE
/*<!M><%period><%period><%period><A>                               */ DEADTRANS( L'A'	,0xE853	,0x2234	,0x0000), // 'A' ➔ "∴" THEREFORE
/*<!M><%period><%period><%period><v>                               */ DEADTRANS( L'v'	,0xE853	,0x2235	,0x0000), // 'v' ➔ "∵" BECAUSE
/*<!M><%period><%period><%period><V>                               */ DEADTRANS( L'V'	,0xE853	,0x2235	,0x0000), // 'V' ➔ "∵" BECAUSE
/*<!M><%period><%period><%underscore>                              */ DEADTRANS( L'_'	,0xE850	,0x2025	,0x0000), // '_' ➔ "‥" TWO DOT LEADER
/*<!M><%period><%plus>                                             */ DEADTRANS( L'+'	,0xE830	,0x2214	,0x0000), // '+' ➔ "∔" DOT PLUS
/*<!M><%period><%slash>                                            */ DEADTRANS( L'/'	,0xE830	,0xE862	,0x0001), // Multikey chain
/*<!M><%period><%slash><%backslash>                                */ DEADTRANS( L'\\'	,0xE862	,0x29CA	,0x0000), // '\' ➔ "⧊" TRIANGLE WITH DOT ABOVE
/*<!M><%period><%slash><%period>                                   */ DEADTRANS( L'.'	,0xE862	,0x2052	,0x0000), // '.' ➔ "⁒" COMMERCIAL MINUS SIGN
/*<!M><%period><%tilde>                                            */ DEADTRANS( L'~'	,0xE830	,0xE865	,0x0001), // Multikey chain
/*<!M><%period><%tilde><%equal>                                    */ DEADTRANS( L'='	,0xE865	,0x2A6D	,0x0000), // '=' ➔ "⩭" CONGRUENT WITH DOT ABOVE
/*<!M><%period><%tilde><%period>                                   */ DEADTRANS( L'.'	,0xE865	,0x2A6B	,0x0000), // '.' ➔ "⩫" TILDE OPERATOR WITH RISING DOTS
/*<!M><%period><%tilde><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xE865	,0x2A6A	,0x0000), // ' ' ➔ "⩪" TILDE OPERATOR WITH DOT ABOVE
/*<!M><%period><%tilde><~space>                                    */ DEADTRANS( L' '	,0xE865	,0x2A6A	,0x0000), // ' ' ➔ "⩪" TILDE OPERATOR WITH DOT ABOVE
/*<!M><%period><%underscore>                                       */ DEADTRANS( L'_'	,0xE830	,0x2024	,0x0000), // '_' ➔ "․" ONE DOT LEADER
/*<!M><%plus>                                                      */ DEADTRANS( L'+'	,0x00A6	,0xE86B	,0x0001), // Multikey chain
/*<!M><%plus><%asterisk>                                           */ DEADTRANS( L'*'	,0xE86B	,0x2A22	,0x0000), // '*' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><%plus><%backslash>                                          */ DEADTRANS( L'\\'	,0xE86B	,0xFB29	,0x0000), // '\' ➔ "﬩" HEBREW LETTER ALTERNATIVE PLUS SIGN
/*<!M><%plus><%circum>                                             */ DEADTRANS( L'^'	,0xE86B	,0x207A	,0x0000), // '^' ➔ "⁺" SUPERSCRIPT PLUS SIGN
/*<!M><%plus><%equal>                                              */ DEADTRANS( L'='	,0xE86B	,0x2A72	,0x0000), // '=' ➔ "⩲" PLUS SIGN ABOVE EQUALS SIGN
/*<!M><%plus><%minus>                                              */ DEADTRANS( L'-'	,0xE86B	,0x00B1	,0x0000), // '-' ➔ "±" PLUS-MINUS SIGN
/*<!M><%plus><%parenleft>                                          */ DEADTRANS( L'('	,0xE86B	,0xE871	,0x0001), // Multikey chain
/*<!M><%plus><%parenleft><%parenright>                             */ DEADTRANS( L')'	,0xE871	,0x29FE	,0x0000), // ')' ➔ "⧾" TINY
/*<!M><%plus><%parenright>                                         */ DEADTRANS( L')'	,0xE86B	,0xE873	,0x0001), // Multikey chain
/*<!M><%plus><%parenright><%parenleft>                             */ DEADTRANS( L'('	,0xE873	,0x29FE	,0x0000), // '(' ➔ "⧾" TINY
/*<!M><%plus><%parenright><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE873	,0x2A2E	,0x0000), // ' ' ➔ "⨮" PLUS SIGN IN RIGHT HALF CIRCLE
/*<!M><%plus><%parenright><~space>                                 */ DEADTRANS( L' '	,0xE873	,0x2A2E	,0x0000), // ' ' ➔ "⨮" PLUS SIGN IN RIGHT HALF CIRCLE
/*<!M><%plus><%period>                                             */ DEADTRANS( L'.'	,0xE86B	,0x2A25	,0x0000), // '.' ➔ "⨥" PLUS SIGN WITH DOT BELOW
/*<!M><%plus><%plus>                                               */ DEADTRANS( L'+'	,0xE86B	,0xE878	,0x0001), // Multikey chain
/*<!M><%plus><%plus><%plus>                                        */ DEADTRANS( L'+'	,0xE878	,0x29FB	,0x0000), // '+' ➔ "⧻" TRIPLE PLUS
/*<!M><%plus><%tilde>                                              */ DEADTRANS( L'~'	,0xE86B	,0xE87A	,0x0001), // Multikey chain
/*<!M><%plus><%tilde><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE87A	,0x2A26	,0x0000), // ' ' ➔ "⨦" PLUS SIGN WITH TILDE BELOW
/*<!M><%plus><%tilde><~space>                                      */ DEADTRANS( L' '	,0xE87A	,0x2A26	,0x0000), // ' ' ➔ "⨦" PLUS SIGN WITH TILDE BELOW
/*<!M><%plus><%underscore>                                         */ DEADTRANS( L'_'	,0xE86B	,0x208A	,0x0000), // '_' ➔ "₊" SUBSCRIPT PLUS SIGN
/*<!M><%question>                                                  */ DEADTRANS( L'?'	,0x00A6	,0xE87E	,0x0001), // Multikey chain
/*<!M><%question><%equal>                                          */ DEADTRANS( L'='	,0xE87E	,0x225F	,0x0000), // '=' ➔ "≟" QUESTIONED EQUAL TO
/*<!M><%question><%exclam>                                         */ DEADTRANS( L'!'	,0xE87E	,0x203D	,0x0000), // '!' ➔ "‽" INTERROBANG
/*<!M><%question><%greater>                                        */ DEADTRANS( L'>'	,0xE87E	,0x2A7C	,0x0000), // '>' ➔ "⩼" GREATER-THAN WITH QUESTION MARK ABOVE
/*<!M><%question><%less>                                           */ DEADTRANS( L'<'	,0xE87E	,0x2A7B	,0x0000), // '<' ➔ "⩻" LESS-THAN WITH QUESTION MARK ABOVE
/*<!M><%question><%question>                                       */ DEADTRANS( L'?'	,0xE87E	,0x00BF	,0x0000), // '?' ➔ "¿" INVERTED QUESTION MARK
/*<!M><%slash>                                                     */ DEADTRANS( L'/'	,0x00A6	,0xE884	,0x0001), // Multikey chain
/*<!M><%slash><%backslash>                                         */ DEADTRANS( L'\\'	,0xE884	,0xE885	,0x0001), // Multikey chain
/*<!M><%slash><%backslash><%bar>                                   */ DEADTRANS( L'|'	,0xE885	,0x22CA	,0x0000), // '|' ➔ "⋊" RIGHT NORMAL FACTOR SEMIDIRECT PRODUCT
/*<!M><%slash><%backslash><%greater>                               */ DEADTRANS( L'>'	,0xE885	,0x2930	,0x0000), // '>' ➔ "⤰" RISING DIAGONAL CROSSING SOUTH EAST ARROW
/*<!M><%slash><%backslash><%hash>                                  */ DEADTRANS( L'#'	,0xE885	,0x29D5	,0x0000), // '#' ➔ "⧕" TIMES WITH RIGHT HALF BLACK
/*<!M><%slash><%backslash><%slash>                                 */ DEADTRANS( L'/'	,0xE885	,0x22CC	,0x0000), // '/' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%backslash><%underscore>                            */ DEADTRANS( L'_'	,0xE885	,0xE88A	,0x0001), // Multikey chain
/*<!M><%slash><%backslash><%underscore><%minus>                    */ DEADTRANS( L'-'	,0xE88A	,0x2A3A	,0x0000), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore><%plus>                     */ DEADTRANS( L'+'	,0xE88A	,0x2A39	,0x0000), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore><%underscore>               */ DEADTRANS( L'_'	,0xE88A	,0x29CB	,0x0000), // '_' ➔ "⧋" TRIANGLE WITH UNDERBAR
/*<!M><%slash><%backslash><%underscore><o>                         */ DEADTRANS( L'o'	,0xE88A	,0x27C1	,0x0000), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%slash><%backslash><%underscore><s>                         */ DEADTRANS( L's'	,0xE88A	,0x29CC	,0x0000), // 's' ➔ "⧌" S IN TRIANGLE
/*<!M><%slash><%backslash><%underscore><x>                         */ DEADTRANS( L'x'	,0xE88A	,0x2A3B	,0x0000), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><%slash><%backslash><%underscore><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE88A	,0x2A32	,0x0000), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%slash><%backslash><%underscore><~space>                    */ DEADTRANS( L' '	,0xE88A	,0x2A32	,0x0000), // ' ' ➔ "⨲" SEMIDIRECT PRODUCT WITH BOTTOM CLOSED
/*<!M><%slash><%backslash><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE885	,0x292B	,0x0000), // ' ' ➔ "⤫" RISING DIAGONAL CROSSING FALLING DIAGONAL
/*<!M><%slash><%backslash><~space>                                 */ DEADTRANS( L' '	,0xE885	,0x292B	,0x0000), // ' ' ➔ "⤫" RISING DIAGONAL CROSSING FALLING DIAGONAL
/*<!M><%slash><%bar>                                               */ DEADTRANS( L'|'	,0xE884	,0xE895	,0x0001), // Multikey chain
/*<!M><%slash><%bar><%underscore>                                  */ DEADTRANS( L'_'	,0xE895	,0x29E1	,0x0000), // '_' ➔ "⧡" INCREASES AS
/*<!M><%slash><%bar><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xE895	,0x2A58	,0x0000), // ' ' ➔ "⩘" SLOPING LARGE AND
/*<!M><%slash><%bar><~space>                                       */ DEADTRANS( L' '	,0xE895	,0x2A58	,0x0000), // ' ' ➔ "⩘" SLOPING LARGE AND
/*<!M><%slash><%greater>                                           */ DEADTRANS( L'>'	,0xE884	,0xE899	,0x0001), // Multikey chain
/*<!M><%slash><%greater><%backslash>                               */ DEADTRANS( L'\\'	,0xE899	,0x292E	,0x0000), // '\' ➔ "⤮" NORTH EAST ARROW CROSSING SOUTH EAST ARROW
/*<!M><%slash><%greater><%equal>                                   */ DEADTRANS( L'='	,0xE899	,0x21D7	,0x0000), // '=' ➔ "⇗" NORTH EAST DOUBLE ARROW
/*<!M><%slash><%greater><%less>                                    */ DEADTRANS( L'<'	,0xE899	,0x2931	,0x0000), // '<' ➔ "⤱" NORTH EAST ARROW CROSSING NORTH WEST ARROW
/*<!M><%slash><%greater><%parenright>                              */ DEADTRANS( L')'	,0xE899	,0x29AC	,0x0000), // ')' ➔ "⦬" MEASURED ANGLE WITH OPEN ARM ENDING IN ARROW POINTING RIGHT AND UP
/*<!M><%slash><%greater><2>                                        */ DEADTRANS( L'2'	,0xE899	,0x21D7	,0x0000), // '2' ➔ "⇗" NORTH EAST DOUBLE ARROW
/*<!M><%slash><%greater><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE899	,0x2197	,0x0000), // ' ' ➔ "↗" NORTH EAST ARROW
/*<!M><%slash><%greater><~space>                                   */ DEADTRANS( L' '	,0xE899	,0x2197	,0x0000), // ' ' ➔ "↗" NORTH EAST ARROW
/*<!M><%slash><%hash>                                              */ DEADTRANS( L'#'	,0xE884	,0xE8A1	,0x0001), // Multikey chain
/*<!M><%slash><%hash><%underscore>                                 */ DEADTRANS( L'_'	,0xE8A1	,0xE8A2	,0x0001), // Multikey chain
/*<!M><%slash><%hash><%underscore><%backslash>                     */ DEADTRANS( L'\\'	,0xE8A2	,0x25B2	,0x0000), // '\' ➔ "▲" BLACK UP-POINTING TRIANGLE
/*<!M><%slash><%hash><%underscore><%slash>                         */ DEADTRANS( L'/'	,0xE8A2	,0x25B0	,0x0000), // '/' ➔ "▰" BLACK PARALLELOGRAM
/*<!M><%slash><%minus>                                             */ DEADTRANS( L'-'	,0xE884	,0xE8A5	,0x0001), // Multikey chain
/*<!M><%slash><%minus><%bar>                                       */ DEADTRANS( L'|'	,0xE8A5	,0x22BF	,0x0000), // '|' ➔ "⊿" RIGHT TRIANGLE
/*<!M><%slash><%minus><%greater>                                   */ DEADTRANS( L'>'	,0xE8A5	,0x219B	,0x0000), // '>' ➔ "↛" RIGHTWARDS ARROW WITH STROKE
/*<!M><%slash><%parenleft>                                         */ DEADTRANS( L'('	,0xE884	,0x29A1	,0x0000), // '(' ➔ "⦡" SPHERICAL ANGLE OPENING UP
/*<!M><%slash><%period>                                            */ DEADTRANS( L'.'	,0xE884	,0x25EC	,0x0000), // '.' ➔ "◬" WHITE UP-POINTING TRIANGLE WITH DOT
/*<!M><%slash><%slash>                                             */ DEADTRANS( L'/'	,0xE884	,0xE8AA	,0x0001), // Multikey chain
/*<!M><%slash><%slash><%backslash>                                 */ DEADTRANS( L'\\'	,0xE8AA	,0xE8AB	,0x0001), // Multikey chain
/*<!M><%slash><%slash><%backslash><%backslash>                     */ DEADTRANS( L'\\'	,0xE8AB	,0x2A33	,0x0000), // '\' ➔ "⨳" SMASH PRODUCT
/*<!M><%slash><%slash><%backslash><~nbspace>                       */ DEADTRANS( 0x00A0	,0xE8AB	,0x22CC	,0x0000), // ' ' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%slash><%backslash><~space>                         */ DEADTRANS( L' '	,0xE8AB	,0x22CC	,0x0000), // ' ' ➔ "⋌" RIGHT SEMIDIRECT PRODUCT
/*<!M><%slash><%underscore>                                        */ DEADTRANS( L'_'	,0xE884	,0xE8AF	,0x0001), // Multikey chain
/*<!M><%slash><%underscore><%backslash>                            */ DEADTRANS( L'\\'	,0xE8AF	,0xE8B0	,0x0001), // Multikey chain
/*<!M><%slash><%underscore><%backslash><%underscore>               */ DEADTRANS( L'_'	,0xE8B0	,0x23E2	,0x0000), // '_' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%slash><%underscore><%backslash><o>                         */ DEADTRANS( L'o'	,0xE8B0	,0x27C1	,0x0000), // 'o' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><%slash><%underscore><%backslash><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE8B0	,0x25B3	,0x0000), // ' ' ➔ "△" WHITE UP-POINTING TRIANGLE
/*<!M><%slash><%underscore><%backslash><~space>                    */ DEADTRANS( L' '	,0xE8B0	,0x25B3	,0x0000), // ' ' ➔ "△" WHITE UP-POINTING TRIANGLE
/*<!M><%slash><%underscore><%bar>                                  */ DEADTRANS( L'|'	,0xE8AF	,0x25FF	,0x0000), // '|' ➔ "◿" LOWER RIGHT TRIANGLE
/*<!M><%slash><%underscore><%hash>                                 */ DEADTRANS( L'#'	,0xE8AF	,0x25E2	,0x0000), // '#' ➔ "◢" BLACK LOWER RIGHT TRIANGLE
/*<!M><%slash><%underscore><%slash>                                */ DEADTRANS( L'/'	,0xE8AF	,0x25B1	,0x0000), // '/' ➔ "▱" WHITE PARALLELOGRAM
/*<!M><%slash><%underscore><%underscore>                           */ DEADTRANS( L'_'	,0xE8AF	,0xE8B8	,0x0001), // Multikey chain
/*<!M><%slash><%underscore><%underscore><%backslash>               */ DEADTRANS( L'\\'	,0xE8B8	,0x23E2	,0x0000), // '\' ➔ "⏢" WHITE TRAPEZIUM
/*<!M><%slash><%underscore><%underscore><%bar>                     */ DEADTRANS( L'|'	,0xE8B8	,0x29E1	,0x0000), // '|' ➔ "⧡" INCREASES AS
/*<!M><%tilde>                                                     */ DEADTRANS( L'~'	,0x00A6	,0xE8BB	,0x0001), // Multikey chain
/*<!M><%tilde><%backslash>                                         */ DEADTRANS( L'\\'	,0xE8BB	,0xE8BC	,0x0001), // Multikey chain
/*<!M><%tilde><%backslash><%equal>                                 */ DEADTRANS( L'='	,0xE8BC	,0x224C	,0x0000), // '=' ➔ "≌" ALL EQUAL TO
/*<!M><%tilde><%backslash><%greater>                               */ DEADTRANS( L'>'	,0xE8BC	,0xE8BE	,0x0001), // Multikey chain
/*<!M><%tilde><%backslash><%greater><%equal>                       */ DEADTRANS( L'='	,0xE8BE	,0x2AA0	,0x0000), // '=' ➔ "⪠" SIMILAR ABOVE GREATER-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%backslash><%greater><~nbspace>                     */ DEADTRANS( 0x00A0	,0xE8BE	,0x2A9E	,0x0000), // ' ' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><%tilde><%backslash><%greater><~space>                       */ DEADTRANS( L' '	,0xE8BE	,0x2A9E	,0x0000), // ' ' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><%tilde><%backslash><%less>                                  */ DEADTRANS( L'<'	,0xE8BC	,0xE8C2	,0x0001), // Multikey chain
/*<!M><%tilde><%backslash><%less><%equal>                          */ DEADTRANS( L'='	,0xE8C2	,0x2A9F	,0x0000), // '=' ➔ "⪟" SIMILAR ABOVE LESS-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%backslash><%less><%minus>                          */ DEADTRANS( L'-'	,0xE8C2	,0x2B41	,0x0000), // '-' ➔ "⭁" REVERSE TILDE OPERATOR ABOVE LEFTWARDS ARROW
/*<!M><%tilde><%backslash><%less><~nbspace>                        */ DEADTRANS( 0x00A0	,0xE8C2	,0x2A9D	,0x0000), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%backslash><%less><~space>                          */ DEADTRANS( L' '	,0xE8C2	,0x2A9D	,0x0000), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%backslash><%minus>                                 */ DEADTRANS( L'-'	,0xE8BC	,0x2B47	,0x0000), // '-' ➔ "⭇" REVERSE TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><%tilde><%backslash><%underscore>                            */ DEADTRANS( L'_'	,0xE8BC	,0x22CD	,0x0000), // '_' ➔ "⋍" REVERSED TILDE EQUALS
/*<!M><%tilde><%backslash><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE8BC	,0x223D	,0x0000), // ' ' ➔ "∽" REVERSED TILDE
/*<!M><%tilde><%backslash><~space>                                 */ DEADTRANS( L' '	,0xE8BC	,0x223D	,0x0000), // ' ' ➔ "∽" REVERSED TILDE
/*<!M><%tilde><%bar>                                               */ DEADTRANS( L'|'	,0xE8BB	,0xE8CB	,0x0001), // Multikey chain
/*<!M><%tilde><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xE8CB	,0x2AF3	,0x0000), // '|' ➔ "⫳" PARALLEL WITH TILDE OPERATOR
/*<!M><%tilde><%greater>                                           */ DEADTRANS( L'>'	,0xE8BB	,0xE8CD	,0x0001), // Multikey chain
/*<!M><%tilde><%greater><%equal>                                   */ DEADTRANS( L'='	,0xE8CD	,0x2AA0	,0x0000), // '=' ➔ "⪠" SIMILAR ABOVE GREATER-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%greater><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xE8CD	,0x219D	,0x0000), // ' ' ➔ "↝" RIGHTWARDS WAVE ARROW
/*<!M><%tilde><%greater><~space>                                   */ DEADTRANS( L' '	,0xE8CD	,0x219D	,0x0000), // ' ' ➔ "↝" RIGHTWARDS WAVE ARROW
/*<!M><%tilde><%hash>                                              */ DEADTRANS( L'#'	,0xE8BB	,0xE8D1	,0x0001), // Multikey chain
/*<!M><%tilde><%hash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE8D1	,0x29E4	,0x0000), // ' ' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><%tilde><%hash><~space>                                      */ DEADTRANS( L' '	,0xE8D1	,0x29E4	,0x0000), // ' ' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><%tilde><%less>                                              */ DEADTRANS( L'<'	,0xE8BB	,0xE8D4	,0x0001), // Multikey chain
/*<!M><%tilde><%less><%equal>                                      */ DEADTRANS( L'='	,0xE8D4	,0x2A9F	,0x0000), // '=' ➔ "⪟" SIMILAR ABOVE LESS-THAN ABOVE EQUALS SIGN
/*<!M><%tilde><%less><%minus>                                      */ DEADTRANS( L'-'	,0xE8D4	,0x2B49	,0x0000), // '-' ➔ "⭉" TILDE OPERATOR ABOVE LEFTWARDS ARROW
/*<!M><%tilde><%less><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE8D4	,0x2A9D	,0x0000), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%less><~space>                                      */ DEADTRANS( L' '	,0xE8D4	,0x2A9D	,0x0000), // ' ' ➔ "⪝" SIMILAR OR LESS-THAN
/*<!M><%tilde><%minus>                                             */ DEADTRANS( L'-'	,0xE8BB	,0xE8D9	,0x0001), // Multikey chain
/*<!M><%tilde><%minus><%greater>                                   */ DEADTRANS( L'>'	,0xE8D9	,0x2933	,0x0000), // '>' ➔ "⤳" WAVE ARROW POINTING DIRECTLY RIGHT
/*<!M><%tilde><%minus><%slash>                                     */ DEADTRANS( L'/'	,0xE8D9	,0x2244	,0x0000), // '/' ➔ "≄" NOT ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%minus><%tilde>                                     */ DEADTRANS( L'~'	,0xE8D9	,0x2A6C	,0x0000), // '~' ➔ "⩬" SIMILAR MINUS SIMILAR
/*<!M><%tilde><%minus><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE8D9	,0x2243	,0x0000), // ' ' ➔ "≃" ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%minus><~space>                                     */ DEADTRANS( L' '	,0xE8D9	,0x2243	,0x0000), // ' ' ➔ "≃" ASYMPTOTICALLY EQUAL TO
/*<!M><%tilde><%plus>                                              */ DEADTRANS( L'+'	,0xE8BB	,0xE8DF	,0x0001), // Multikey chain
/*<!M><%tilde><%plus><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xE8DF	,0x2A24	,0x0000), // ' ' ➔ "⨤" PLUS SIGN WITH TILDE ABOVE
/*<!M><%tilde><%plus><~space>                                      */ DEADTRANS( L' '	,0xE8DF	,0x2A24	,0x0000), // ' ' ➔ "⨤" PLUS SIGN WITH TILDE ABOVE
/*<!M><%tilde><%slash>                                             */ DEADTRANS( L'/'	,0xE8BB	,0xE8E2	,0x0001), // Multikey chain
/*<!M><%tilde><%slash><%equal>                                     */ DEADTRANS( L'='	,0xE8E2	,0x2247	,0x0000), // '=' ➔ "≇" NEITHER APPROXIMATELY NOR ACTUALLY EQUAL TO
/*<!M><%tilde><%tilde>                                             */ DEADTRANS( L'~'	,0xE8BB	,0xE8E4	,0x0001), // Multikey chain
/*<!M><%tilde><%tilde><%greater>                                   */ DEADTRANS( L'>'	,0xE8E4	,0x21DD	,0x0000), // '>' ➔ "⇝" RIGHTWARDS SQUIGGLE ARROW
/*<!M><%tilde><%tilde><%minus>                                     */ DEADTRANS( L'-'	,0xE8E4	,0x224A	,0x0000), // '-' ➔ "≊" ALMOST EQUAL OR EQUAL TO
/*<!M><%tilde><%tilde><%slash>                                     */ DEADTRANS( L'/'	,0xE8E4	,0x2249	,0x0000), // '/' ➔ "≉" NOT ALMOST EQUAL TO
/*<!M><%tilde><%tilde><%tilde>                                     */ DEADTRANS( L'~'	,0xE8E4	,0xE8E8	,0x0001), // Multikey chain
/*<!M><%tilde><%tilde><%tilde><%greater>                           */ DEADTRANS( L'>'	,0xE8E8	,0x27FF	,0x0000), // '>' ➔ "⟿" LONG RIGHTWARDS SQUIGGLE ARROW
/*<!M><%underscore>                                                */ DEADTRANS( L'_'	,0x00A6	,0xE8EA	,0x0001), // Multikey chain
/*<!M><%underscore><%backslash>                                    */ DEADTRANS( L'\\'	,0xE8EA	,0xE8EB	,0x0001), // Multikey chain
/*<!M><%underscore><%backslash><%bar>                              */ DEADTRANS( L'|'	,0xE8EB	,0x25F9	,0x0000), // '|' ➔ "◹" UPPER RIGHT TRIANGLE
/*<!M><%underscore><%backslash><%hash>                             */ DEADTRANS( L'#'	,0xE8EB	,0x25E5	,0x0000), // '#' ➔ "◥" BLACK UPPER RIGHT TRIANGLE
/*<!M><%underscore><%backslash><%slash>                            */ DEADTRANS( L'/'	,0xE8EB	,0xE8EE	,0x0001), // Multikey chain
/*<!M><%underscore><%backslash><%slash><0>                         */ DEADTRANS( L'0'	,0xE8EE	,0x25BF	,0x0000), // '0' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%backslash><%slash><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE8EE	,0x25BD	,0x0000), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%backslash><%slash><~space>                    */ DEADTRANS( L' '	,0xE8EE	,0x25BD	,0x0000), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%bar>                                          */ DEADTRANS( L'|'	,0xE8EA	,0xE8F2	,0x0001), // Multikey chain
/*<!M><%underscore><%bar><s>                                       */ DEADTRANS( L's'	,0xE8F2	,0x2AE1	,0x0000), // 's' ➔ "⫡" PERPENDICULAR WITH S
/*<!M><%underscore><%bar><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE8F2	,0x27C2	,0x0000), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%underscore><%bar><~space>                                  */ DEADTRANS( L' '	,0xE8F2	,0x27C2	,0x0000), // ' ' ➔ "⟂" PERPENDICULAR
/*<!M><%underscore><%bracketright>                                 */ DEADTRANS( L']'	,0xE8EA	,0x230B	,0x0000), // ']' ➔ "⌋" RIGHT FLOOR
/*<!M><%underscore><%grave>                                        */ DEADTRANS( L'`'	,0xE8EA	,0x296B	,0x0000), // '`' ➔ "⥫" LEFTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><%underscore><%greater>                                      */ DEADTRANS( L'>'	,0xE8EA	,0xE8F8	,0x0001), // Multikey chain
/*<!M><%underscore><%greater><%grave>                              */ DEADTRANS( L'`'	,0xE8F8	,0x2A96	,0x0000), // '`' ➔ "⪖" SLANTED EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%greater><%parenleft>                          */ DEADTRANS( L'('	,0xE8F8	,0xE8FA	,0x0001), // Multikey chain
/*<!M><%underscore><%greater><%parenleft><%parenright>             */ DEADTRANS( L')'	,0xE8FA	,0x22DF	,0x0000), // ')' ➔ "⋟" EQUAL TO OR SUCCEEDS
/*<!M><%underscore><%greater><%parenright>                         */ DEADTRANS( L')'	,0xE8F8	,0xE8FC	,0x0001), // Multikey chain
/*<!M><%underscore><%greater><%parenright><%parenleft>             */ DEADTRANS( L'('	,0xE8FC	,0x22DF	,0x0000), // '(' ➔ "⋟" EQUAL TO OR SUCCEEDS
/*<!M><%underscore><%greater><%period>                             */ DEADTRANS( L'.'	,0xE8F8	,0x2A98	,0x0000), // '.' ➔ "⪘" SLANTED EQUAL TO OR GREATER-THAN WITH DOT INSIDE
/*<!M><%underscore><%greater><~nbspace>                            */ DEADTRANS( 0x00A0	,0xE8F8	,0x22DD	,0x0000), // ' ' ➔ "⋝" EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%greater><~space>                              */ DEADTRANS( L' '	,0xE8F8	,0x22DD	,0x0000), // ' ' ➔ "⋝" EQUAL TO OR GREATER-THAN
/*<!M><%underscore><%hash>                                         */ DEADTRANS( L'#'	,0xE8EA	,0xE901	,0x0001), // Multikey chain
/*<!M><%underscore><%hash><%backslash>                             */ DEADTRANS( L'\\'	,0xE901	,0xE902	,0x0001), // Multikey chain
/*<!M><%underscore><%hash><%backslash><%slash>                     */ DEADTRANS( L'/'	,0xE902	,0xE903	,0x0001), // Multikey chain
/*<!M><%underscore><%hash><%backslash><%slash><0>                  */ DEADTRANS( L'0'	,0xE903	,0x25BE	,0x0000), // '0' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%hash><%backslash><%slash><~nbspace>           */ DEADTRANS( 0x00A0	,0xE903	,0x25BC	,0x0000), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%backslash><%slash><~space>             */ DEADTRANS( L' '	,0xE903	,0x25BC	,0x0000), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%slash>                                 */ DEADTRANS( L'/'	,0xE901	,0xE907	,0x0001), // Multikey chain
/*<!M><%underscore><%hash><%slash><%backslash>                     */ DEADTRANS( L'\\'	,0xE907	,0xE908	,0x0001), // Multikey chain
/*<!M><%underscore><%hash><%slash><%backslash><0>                  */ DEADTRANS( L'0'	,0xE908	,0x25BE	,0x0000), // '0' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%hash><%slash><%backslash><~nbspace>           */ DEADTRANS( 0x00A0	,0xE908	,0x25BC	,0x0000), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%hash><%slash><%backslash><~space>             */ DEADTRANS( L' '	,0xE908	,0x25BC	,0x0000), // ' ' ➔ "▼" BLACK DOWN-POINTING TRIANGLE
/*<!M><%underscore><%less>                                         */ DEADTRANS( L'<'	,0xE8EA	,0xE90C	,0x0001), // Multikey chain
/*<!M><%underscore><%less><%grave>                                 */ DEADTRANS( L'`'	,0xE90C	,0x2A95	,0x0000), // '`' ➔ "⪕" SLANTED EQUAL TO OR LESS-THAN
/*<!M><%underscore><%less><%parenleft>                             */ DEADTRANS( L'('	,0xE90C	,0xE90E	,0x0001), // Multikey chain
/*<!M><%underscore><%less><%parenleft><%parenright>                */ DEADTRANS( L')'	,0xE90E	,0x22DE	,0x0000), // ')' ➔ "⋞" EQUAL TO OR PRECEDES
/*<!M><%underscore><%less><%parenright>                            */ DEADTRANS( L')'	,0xE90C	,0xE910	,0x0001), // Multikey chain
/*<!M><%underscore><%less><%parenright><%parenleft>                */ DEADTRANS( L'('	,0xE910	,0x22DE	,0x0000), // '(' ➔ "⋞" EQUAL TO OR PRECEDES
/*<!M><%underscore><%less><%period>                                */ DEADTRANS( L'.'	,0xE90C	,0x2A97	,0x0000), // '.' ➔ "⪗" SLANTED EQUAL TO OR LESS-THAN WITH DOT INSIDE
/*<!M><%underscore><%less><~nbspace>                               */ DEADTRANS( 0x00A0	,0xE90C	,0x22DC	,0x0000), // ' ' ➔ "⋜" EQUAL TO OR LESS-THAN
/*<!M><%underscore><%less><~space>                                 */ DEADTRANS( L' '	,0xE90C	,0x22DC	,0x0000), // ' ' ➔ "⋜" EQUAL TO OR LESS-THAN
/*<!M><%underscore><%slash>                                        */ DEADTRANS( L'/'	,0xE8EA	,0xE915	,0x0001), // Multikey chain
/*<!M><%underscore><%slash><%backslash>                            */ DEADTRANS( L'\\'	,0xE915	,0xE916	,0x0001), // Multikey chain
/*<!M><%underscore><%slash><%backslash><0>                         */ DEADTRANS( L'0'	,0xE916	,0x25BF	,0x0000), // '0' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><%underscore><%slash><%backslash><~nbspace>                  */ DEADTRANS( 0x00A0	,0xE916	,0x25BD	,0x0000), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%slash><%backslash><~space>                    */ DEADTRANS( L' '	,0xE916	,0x25BD	,0x0000), // ' ' ➔ "▽" WHITE DOWN-POINTING TRIANGLE
/*<!M><%underscore><%slash><%bar>                                  */ DEADTRANS( L'|'	,0xE915	,0x25FF	,0x0000), // '|' ➔ "◿" LOWER RIGHT TRIANGLE
/*<!M><%underscore><%slash><%hash>                                 */ DEADTRANS( L'#'	,0xE915	,0x25E2	,0x0000), // '#' ➔ "◢" BLACK LOWER RIGHT TRIANGLE
/*<!M><%underscore><%slash><~nbspace>                              */ DEADTRANS( 0x00A0	,0xE915	,0x29F6	,0x0000), // ' ' ➔ "⧶" SOLIDUS WITH OVERBAR
/*<!M><%underscore><%slash><~space>                                */ DEADTRANS( L' '	,0xE915	,0x29F6	,0x0000), // ' ' ➔ "⧶" SOLIDUS WITH OVERBAR
/*<!M><%underscore><%underscore>                                   */ DEADTRANS( L'_'	,0xE8EA	,0xE91E	,0x0001), // Multikey chain
/*<!M><%underscore><%underscore><A>                                */ DEADTRANS( L'A'	,0xE91E	,0x2A5E	,0x0000), // 'A' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><%underscore><%underscore><a>                                */ DEADTRANS( L'a'	,0xE91E	,0x2A5E	,0x0000), // 'a' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><0>                                                          */ DEADTRANS( L'0'	,0x00A6	,0xE921	,0x0001), // Multikey chain
/*<!M><0><%asterisk>                                               */ DEADTRANS( L'*'	,0xE921	,0x00B0	,0x0000), // '*' ➔ "°" DEGREE SIGN
/*<!M><0><%hash>                                                   */ DEADTRANS( L'#'	,0xE921	,0x266E	,0x0000), // '#' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><0><%minus>                                                  */ DEADTRANS( L'-'	,0xE921	,0x00AD	,0x0000), // '-' ➔ "­" SOFT HYPHEN
/*<!M><0><%percent>                                                */ DEADTRANS( L'%'	,0xE921	,0x2030	,0x0000), // '%' ➔ "‰" PER MILLE SIGN
/*<!M><0><%slash>                                                  */ DEADTRANS( L'/'	,0xE921	,0x2189	,0x0000), // '/' ➔ "↉" VULGAR FRACTION ZERO THIRDS
/*<!M><0><0>                                                       */ DEADTRANS( L'0'	,0xE921	,0x2031	,0x0000), // '0' ➔ "‱" PER TEN THOUSAND SIGN
/*<!M><0><3>                                                       */ DEADTRANS( L'3'	,0xE921	,0x2189	,0x0000), // '3' ➔ "↉" VULGAR FRACTION ZERO THIRDS
/*<!M><1>                                                          */ DEADTRANS( L'1'	,0x00A6	,0xE929	,0x0001), // Multikey chain
/*<!M><1><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE929	,0x2032	,0x0000), // ''' ➔ "′" PRIME
/*<!M><1><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xE929	,0x2032	,0x0000), // '’' ➔ "′" PRIME
/*<!M><1><%asterisk>                                               */ DEADTRANS( L'*'	,0xE929	,0x2648	,0x0000), // '*' ➔ "♈" ARIES emoji
/*<!M><1><%grave>                                                  */ DEADTRANS( L'`'	,0xE929	,0x2035	,0x0000), // '`' ➔ "‵" REVERSED PRIME
/*<!M><1><%hash>                                                   */ DEADTRANS( L'#'	,0xE929	,0x25AA	,0x0000), // '#' ➔ "▪" BLACK SMALL SQUARE emoji
/*<!M><1><%minus>                                                  */ DEADTRANS( L'-'	,0xE929	,0x2014	,0x0000), // '-' ➔ "—" EM DASH
/*<!M><1><%slash>                                                  */ DEADTRANS( L'/'	,0xE929	,0xE930	,0x0001), // Multikey chain
/*<!M><1><%slash><0>                                               */ DEADTRANS( L'0'	,0xE930	,0x2152	,0x0000), // '0' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><%slash><1>                                               */ DEADTRANS( L'1'	,0xE930	,0x2152	,0x0000), // '1' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><%slash><2>                                               */ DEADTRANS( L'2'	,0xE930	,0x00BD	,0x0000), // '2' ➔ "½" VULGAR FRACTION ONE HALF
/*<!M><1><%slash><3>                                               */ DEADTRANS( L'3'	,0xE930	,0x2153	,0x0000), // '3' ➔ "⅓" VULGAR FRACTION ONE THIRD
/*<!M><1><%slash><4>                                               */ DEADTRANS( L'4'	,0xE930	,0x00BC	,0x0000), // '4' ➔ "¼" VULGAR FRACTION ONE QUARTER
/*<!M><1><%slash><5>                                               */ DEADTRANS( L'5'	,0xE930	,0x2155	,0x0000), // '5' ➔ "⅕" VULGAR FRACTION ONE FIFTH
/*<!M><1><%slash><6>                                               */ DEADTRANS( L'6'	,0xE930	,0x2159	,0x0000), // '6' ➔ "⅙" VULGAR FRACTION ONE SIXTH
/*<!M><1><%slash><7>                                               */ DEADTRANS( L'7'	,0xE930	,0x2150	,0x0000), // '7' ➔ "⅐" VULGAR FRACTION ONE SEVENTH
/*<!M><1><%slash><8>                                               */ DEADTRANS( L'8'	,0xE930	,0x215B	,0x0000), // '8' ➔ "⅛" VULGAR FRACTION ONE EIGHTH
/*<!M><1><%slash><9>                                               */ DEADTRANS( L'9'	,0xE930	,0x2151	,0x0000), // '9' ➔ "⅑" VULGAR FRACTION ONE NINTH
/*<!M><1><%slash><~space>                                          */ DEADTRANS( L' '	,0xE930	,0x215F	,0x0000), // ' ' ➔ "⅟" FRACTION NUMERATOR ONE
/*<!M><1><%underscore>                                             */ DEADTRANS( L'_'	,0xE929	,0x25AB	,0x0000), // '_' ➔ "▫" WHITE SMALL SQUARE emoji
/*<!M><1><0>                                                       */ DEADTRANS( L'0'	,0xE929	,0x2152	,0x0000), // '0' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><1>                                                       */ DEADTRANS( L'1'	,0xE929	,0x2152	,0x0000), // '1' ➔ "⅒" VULGAR FRACTION ONE TENTH
/*<!M><1><2>                                                       */ DEADTRANS( L'2'	,0xE929	,0x00BD	,0x0000), // '2' ➔ "½" VULGAR FRACTION ONE HALF
/*<!M><1><3>                                                       */ DEADTRANS( L'3'	,0xE929	,0x2153	,0x0000), // '3' ➔ "⅓" VULGAR FRACTION ONE THIRD
/*<!M><1><4>                                                       */ DEADTRANS( L'4'	,0xE929	,0x00BC	,0x0000), // '4' ➔ "¼" VULGAR FRACTION ONE QUARTER
/*<!M><1><5>                                                       */ DEADTRANS( L'5'	,0xE929	,0x2155	,0x0000), // '5' ➔ "⅕" VULGAR FRACTION ONE FIFTH
/*<!M><1><6>                                                       */ DEADTRANS( L'6'	,0xE929	,0x2159	,0x0000), // '6' ➔ "⅙" VULGAR FRACTION ONE SIXTH
/*<!M><1><7>                                                       */ DEADTRANS( L'7'	,0xE929	,0x2150	,0x0000), // '7' ➔ "⅐" VULGAR FRACTION ONE SEVENTH
/*<!M><1><8>                                                       */ DEADTRANS( L'8'	,0xE929	,0x215B	,0x0000), // '8' ➔ "⅛" VULGAR FRACTION ONE EIGHTH
/*<!M><1><9>                                                       */ DEADTRANS( L'9'	,0xE929	,0x2151	,0x0000), // '9' ➔ "⅑" VULGAR FRACTION ONE NINTH
/*<!M><1><i>                                                       */ DEADTRANS( L'i'	,0xE929	,0xA70C	,0x0000), // 'i' ➔ "꜌" MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*<!M><1><I>                                                       */ DEADTRANS( L'I'	,0xE929	,0xA70C	,0x0000), // 'I' ➔ "꜌" MODIFIER LETTER EXTRA-LOW DOTTED TONE BAR
/*<!M><1><t>                                                       */ DEADTRANS( L't'	,0xE929	,0x02E9	,0x0000), // 't' ➔ "˩" MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!M><1><T>                                                       */ DEADTRANS( L'T'	,0xE929	,0x02E9	,0x0000), // 'T' ➔ "˩" MODIFIER LETTER EXTRA-LOW TONE BAR
/*<!M><1><~space>                                                  */ DEADTRANS( L' '	,0xE929	,0x215F	,0x0000), // ' ' ➔ "⅟" FRACTION NUMERATOR ONE
/*<!M><2>                                                          */ DEADTRANS( L'2'	,0x00A6	,0xE94C	,0x0001), // Multikey chain
/*<!M><2><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE94C	,0x2033	,0x0000), // ''' ➔ "″" DOUBLE PRIME
/*<!M><2><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xE94C	,0x2033	,0x0000), // '’' ➔ "″" DOUBLE PRIME
/*<!M><2><%asterisk>                                               */ DEADTRANS( L'*'	,0xE94C	,0x2649	,0x0000), // '*' ➔ "♉" TAURUS emoji
/*<!M><2><%backslash>                                              */ DEADTRANS( L'\\'	,0xE94C	,0x27C1	,0x0000), // '\' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><2><%bar>                                                    */ DEADTRANS( L'|'	,0xE94C	,0x2016	,0x0000), // '|' ➔ "‖" DOUBLE VERTICAL LINE
/*<!M><2><%bracketleft>                                            */ DEADTRANS( L'['	,0xE94C	,0xE952	,0x0001), // Multikey chain
/*<!M><2><%bracketleft><%bracketright>                             */ DEADTRANS( L']'	,0xE952	,0x29C8	,0x0000), // ']' ➔ "⧈" SQUARED SQUARE
/*<!M><2><%bracketleft><w>                                         */ DEADTRANS( L'w'	,0xE952	,0x29DA	,0x0000), // 'w' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><2><%bracketright>                                           */ DEADTRANS( L']'	,0xE94C	,0xE955	,0x0001), // Multikey chain
/*<!M><2><%bracketright><w>                                        */ DEADTRANS( L'w'	,0xE955	,0x29DB	,0x0000), // 'w' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><2><%exclam>                                                 */ DEADTRANS( L'!'	,0xE94C	,0x21CA	,0x0000), // '!' ➔ "⇊" DOWNWARDS PAIRED ARROWS
/*<!M><2><%grave>                                                  */ DEADTRANS( L'`'	,0xE94C	,0x2036	,0x0000), // '`' ➔ "‶" REVERSED DOUBLE PRIME
/*<!M><2><%greater>                                                */ DEADTRANS( L'>'	,0xE94C	,0x2AA2	,0x0000), // '>' ➔ "⪢" DOUBLE NESTED GREATER-THAN
/*<!M><2><%hash>                                                   */ DEADTRANS( L'#'	,0xE94C	,0x25FE	,0x0000), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE emoji
/*<!M><2><%less>                                                   */ DEADTRANS( L'<'	,0xE94C	,0xE95B	,0x0001), // Multikey chain
/*<!M><2><%less><%exclam>                                          */ DEADTRANS( L'!'	,0xE95B	,0x21C8	,0x0000), // '!' ➔ "⇈" UPWARDS PAIRED ARROWS
/*<!M><2><%less><%minus>                                           */ DEADTRANS( L'-'	,0xE95B	,0x21C7	,0x0000), // '-' ➔ "⇇" LEFTWARDS PAIRED ARROWS
/*<!M><2><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xE95B	,0x2AA1	,0x0000), // ' ' ➔ "⪡" DOUBLE NESTED LESS-THAN
/*<!M><2><%less><~space>                                           */ DEADTRANS( L' '	,0xE95B	,0x2AA1	,0x0000), // ' ' ➔ "⪡" DOUBLE NESTED LESS-THAN
/*<!M><2><%minus>                                                  */ DEADTRANS( L'-'	,0xE94C	,0x2E3A	,0x0000), // '-' ➔ "⸺" TWO-EM DASH
/*<!M><2><%slash>                                                  */ DEADTRANS( L'/'	,0xE94C	,0xE961	,0x0001), // Multikey chain
/*<!M><2><%slash><%backslash>                                      */ DEADTRANS( L'\\'	,0xE961	,0x27C1	,0x0000), // '\' ➔ "⟁" WHITE TRIANGLE CONTAINING SMALL WHITE TRIANGLE
/*<!M><2><%slash><3>                                               */ DEADTRANS( L'3'	,0xE961	,0x2154	,0x0000), // '3' ➔ "⅔" VULGAR FRACTION TWO THIRDS
/*<!M><2><%slash><5>                                               */ DEADTRANS( L'5'	,0xE961	,0x2156	,0x0000), // '5' ➔ "⅖" VULGAR FRACTION TWO FIFTHS
/*<!M><2><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xE961	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><2><%slash><~space>                                          */ DEADTRANS( L' '	,0xE961	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><2><%underscore>                                             */ DEADTRANS( L'_'	,0xE94C	,0x25FD	,0x0000), // '_' ➔ "◽" WHITE MEDIUM SMALL SQUARE emoji
/*<!M><2><3>                                                       */ DEADTRANS( L'3'	,0xE94C	,0x2154	,0x0000), // '3' ➔ "⅔" VULGAR FRACTION TWO THIRDS
/*<!M><2><5>                                                       */ DEADTRANS( L'5'	,0xE94C	,0x2156	,0x0000), // '5' ➔ "⅖" VULGAR FRACTION TWO FIFTHS
/*<!M><2><A>                                                       */ DEADTRANS( L'A'	,0xE94C	,0x2A53	,0x0000), // 'A' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><a>                                                       */ DEADTRANS( L'a'	,0xE94C	,0x2A53	,0x0000), // 'a' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><b>                                                       */ DEADTRANS( L'b'	,0xE94C	,0x22D1	,0x0000), // 'b' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c>                                                       */ DEADTRANS( L'c'	,0xE94C	,0xE96D	,0x0001), // Multikey chain
/*<!M><2><c><%backslash>                                           */ DEADTRANS( L'\\'	,0xE96D	,0x22D1	,0x0000), // '\' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c><c>                                                    */ DEADTRANS( L'c'	,0xE96D	,0x22D1	,0x0000), // 'c' ➔ "⋑" DOUBLE SUPERSET
/*<!M><2><c><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE96D	,0x22D0	,0x0000), // ' ' ➔ "⋐" DOUBLE SUBSET
/*<!M><2><c><~space>                                               */ DEADTRANS( L' '	,0xE96D	,0x22D0	,0x0000), // ' ' ➔ "⋐" DOUBLE SUBSET
/*<!M><2><d>                                                       */ DEADTRANS( L'd'	,0xE94C	,0x2B76	,0x0000), // 'd' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2><D>                                                       */ DEADTRANS( L'D'	,0xE94C	,0x2B76	,0x0000), // 'D' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2><h>                                                       */ DEADTRANS( L'h'	,0xE94C	,0x2B76	,0x0000), // 'h' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2><H>                                                       */ DEADTRANS( L'H'	,0xE94C	,0x2B76	,0x0000), // 'H' ➔ "⭶" NORTH WEST TRIANGLE-HEADED ARROW TO BAR
/*<!M><2><i>                                                       */ DEADTRANS( L'i'	,0xE94C	,0xA70B	,0x0000), // 'i' ➔ "꜋" MODIFIER LETTER LOW DOTTED TONE BAR
/*<!M><2><I>                                                       */ DEADTRANS( L'I'	,0xE94C	,0xA70B	,0x0000), // 'I' ➔ "꜋" MODIFIER LETTER LOW DOTTED TONE BAR
/*<!M><2><n>                                                       */ DEADTRANS( L'n'	,0xE94C	,0xE978	,0x0001), // Multikey chain
/*<!M><2><n><%bracketleft>                                         */ DEADTRANS( L'['	,0xE978	,0x2A4E	,0x0000), // '[' ➔ "⩎" DOUBLE SQUARE INTERSECTION
/*<!M><2><n><%bracketright>                                        */ DEADTRANS( L']'	,0xE978	,0x2A4E	,0x0000), // ']' ➔ "⩎" DOUBLE SQUARE INTERSECTION
/*<!M><2><n><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE978	,0x22D2	,0x0000), // ' ' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><2><n><~space>                                               */ DEADTRANS( L' '	,0xE978	,0x22D2	,0x0000), // ' ' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><2><s>                                                       */ DEADTRANS( L's'	,0xE94C	,0xE97D	,0x0001), // Multikey chain
/*<!M><2><S>                                                       */ DEADTRANS( L'S'	,0xE94C	,0xE97E	,0x0001), // Multikey chain
/*<!M><2><s><o>                                                    */ DEADTRANS( L'o'	,0xE97D	,0x222F	,0x0000), // 'o' ➔ "∯" SURFACE INTEGRAL
/*<!M><2><S><o>                                                    */ DEADTRANS( L'o'	,0xE97E	,0x222F	,0x0000), // 'o' ➔ "∯" SURFACE INTEGRAL
/*<!M><2><s><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE97D	,0x222C	,0x0000), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><S><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE97E	,0x222C	,0x0000), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><s><~space>                                               */ DEADTRANS( L' '	,0xE97D	,0x222C	,0x0000), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><S><~space>                                               */ DEADTRANS( L' '	,0xE97E	,0x222C	,0x0000), // ' ' ➔ "∬" DOUBLE INTEGRAL
/*<!M><2><T>                                                       */ DEADTRANS( L'T'	,0xE94C	,0xE986	,0x0001), // Multikey chain
/*<!M><2><t>                                                       */ DEADTRANS( L't'	,0xE94C	,0x02E8	,0x0000), // 't' ➔ "˨" MODIFIER LETTER LOW TONE BAR
/*<!M><2><T><%apostrophe>                                          */ DEADTRANS( L'\''	,0xE986	,0x2AE7	,0x0000), // ''' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><2><T><%aprightsingquotmark>                                 */ DEADTRANS( 0x2019	,0xE986	,0x2AE7	,0x0000), // '’' ➔ "⫧" SHORT DOWN TACK WITH OVERBAR
/*<!M><2><T><%greater>                                             */ DEADTRANS( L'>'	,0xE986	,0xE989	,0x0001), // Multikey chain
/*<!M><2><T><%greater><%slash>                                     */ DEADTRANS( L'/'	,0xE989	,0x22AE	,0x0000), // '/' ➔ "⊮" DOES NOT FORCE
/*<!M><2><T><%greater><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xE989	,0x22A9	,0x0000), // ' ' ➔ "⊩" FORCES
/*<!M><2><T><%greater><~space>                                     */ DEADTRANS( L' '	,0xE989	,0x22A9	,0x0000), // ' ' ➔ "⊩" FORCES
/*<!M><2><T><%less>                                                */ DEADTRANS( L'<'	,0xE986	,0x2AE3	,0x0000), // '<' ➔ "⫣" DOUBLE VERTICAL BAR LEFT TURNSTILE
/*<!M><2><T><%percent>                                             */ DEADTRANS( L'%'	,0xE986	,0x2AE8	,0x0000), // '%' ➔ "⫨" SHORT UP TACK WITH UNDERBAR
/*<!M><2><T><2>                                                    */ DEADTRANS( L'2'	,0xE986	,0xE98F	,0x0001), // Multikey chain
/*<!M><2><T><2><%greater>                                          */ DEADTRANS( L'>'	,0xE98F	,0xE990	,0x0001), // Multikey chain
/*<!M><2><T><2><%greater><%slash>                                  */ DEADTRANS( L'/'	,0xE990	,0x22AF	,0x0000), // '/' ➔ "⊯" NEGATED DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2><%greater><~nbspace>                                */ DEADTRANS( 0x00A0	,0xE990	,0x22AB	,0x0000), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2><%greater><~space>                                  */ DEADTRANS( L' '	,0xE990	,0x22AB	,0x0000), // ' ' ➔ "⊫" DOUBLE VERTICAL BAR DOUBLE RIGHT TURNSTILE
/*<!M><2><T><2><%less>                                             */ DEADTRANS( L'<'	,0xE98F	,0x2AE5	,0x0000), // '<' ➔ "⫥" DOUBLE VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><2><u>                                                       */ DEADTRANS( L'u'	,0xE94C	,0xE995	,0x0001), // Multikey chain
/*<!M><2><u><%bracketleft>                                         */ DEADTRANS( L'['	,0xE995	,0x2A4F	,0x0000), // '[' ➔ "⩏" DOUBLE SQUARE UNION
/*<!M><2><u><%bracketright>                                        */ DEADTRANS( L']'	,0xE995	,0x2A4F	,0x0000), // ']' ➔ "⩏" DOUBLE SQUARE UNION
/*<!M><2><u><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE995	,0x22D3	,0x0000), // ' ' ➔ "⋓" DOUBLE UNION
/*<!M><2><u><~space>                                               */ DEADTRANS( L' '	,0xE995	,0x22D3	,0x0000), // ' ' ➔ "⋓" DOUBLE UNION
/*<!M><2><v>                                                       */ DEADTRANS( L'v'	,0xE94C	,0xE99A	,0x0001), // Multikey chain
/*<!M><2><V>                                                       */ DEADTRANS( L'V'	,0xE94C	,0xE99B	,0x0001), // Multikey chain
/*<!M><2><V><V>                                                    */ DEADTRANS( L'V'	,0xE99B	,0x2A53	,0x0000), // 'V' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><v><v>                                                    */ DEADTRANS( L'v'	,0xE99A	,0x2A53	,0x0000), // 'v' ➔ "⩓" DOUBLE LOGICAL AND
/*<!M><2><v><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE99A	,0x221A	,0x0000), // ' ' ➔ "√" SQUARE ROOT
/*<!M><2><V><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE99B	,0x2A54	,0x0000), // ' ' ➔ "⩔" DOUBLE LOGICAL OR
/*<!M><2><v><~space>                                               */ DEADTRANS( L' '	,0xE99A	,0x221A	,0x0000), // ' ' ➔ "√" SQUARE ROOT
/*<!M><2><V><~space>                                               */ DEADTRANS( L' '	,0xE99B	,0x2A54	,0x0000), // ' ' ➔ "⩔" DOUBLE LOGICAL OR
/*<!M><2><w>                                                       */ DEADTRANS( L'w'	,0xE94C	,0xE9A2	,0x0001), // Multikey chain
/*<!M><2><w><%bracketleft>                                         */ DEADTRANS( L'['	,0xE9A2	,0x29DA	,0x0000), // '[' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><2><w><%bracketright>                                        */ DEADTRANS( L']'	,0xE9A2	,0x29DB	,0x0000), // ']' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><2><Z>                                                       */ DEADTRANS( L'Z'	,0xE94C	,0x01A7	,0x0000), // 'Z' ➔ "Ƨ" LATIN CAPITAL LETTER TONE TWO
/*<!M><2><z>                                                       */ DEADTRANS( L'z'	,0xE94C	,0x01A8	,0x0000), // 'z' ➔ "ƨ" LATIN SMALL LETTER TONE TWO
/*<!M><2><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xE94C	,0x29C9	,0x0000), // ' ' ➔ "⧉" TWO JOINED SQUARES
/*<!M><2><~space>                                                  */ DEADTRANS( L' '	,0xE94C	,0x29C9	,0x0000), // ' ' ➔ "⧉" TWO JOINED SQUARES
/*<!M><3>                                                          */ DEADTRANS( L'3'	,0x00A6	,0xE9A9	,0x0001), // Multikey chain
/*<!M><3><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE9A9	,0x2034	,0x0000), // ''' ➔ "‴" TRIPLE PRIME
/*<!M><3><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xE9A9	,0x2034	,0x0000), // '’' ➔ "‴" TRIPLE PRIME
/*<!M><3><%asterisk>                                               */ DEADTRANS( L'*'	,0xE9A9	,0x264A	,0x0000), // '*' ➔ "♊" GEMINI emoji
/*<!M><3><%bar>                                                    */ DEADTRANS( L'|'	,0xE9A9	,0x2980	,0x0000), // '|' ➔ "⦀" TRIPLE VERTICAL BAR DELIMITER
/*<!M><3><%bracketleft>                                            */ DEADTRANS( L'['	,0xE9A9	,0x29C9	,0x0000), // '[' ➔ "⧉" TWO JOINED SQUARES
/*<!M><3><%colon>                                                  */ DEADTRANS( L':'	,0xE9A9	,0x2AF6	,0x0000), // ':' ➔ "⫶" TRIPLE COLON OPERATOR
/*<!M><3><%grave>                                                  */ DEADTRANS( L'`'	,0xE9A9	,0x2037	,0x0000), // '`' ➔ "‷" REVERSED TRIPLE PRIME
/*<!M><3><%greater>                                                */ DEADTRANS( L'>'	,0xE9A9	,0x2AF8	,0x0000), // '>' ➔ "⫸" TRIPLE NESTED GREATER-THAN
/*<!M><3><%hash>                                                   */ DEADTRANS( L'#'	,0xE9A9	,0x25FC	,0x0000), // '#' ➔ "◼" BLACK MEDIUM SQUARE emoji
/*<!M><3><%less>                                                   */ DEADTRANS( L'<'	,0xE9A9	,0xE9B3	,0x0001), // Multikey chain
/*<!M><3><%less><%minus>                                           */ DEADTRANS( L'-'	,0xE9B3	,0x2B31	,0x0000), // '-' ➔ "⬱" THREE LEFTWARDS ARROWS
/*<!M><3><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xE9B3	,0x2AF7	,0x0000), // ' ' ➔ "⫷" TRIPLE NESTED LESS-THAN
/*<!M><3><%less><~space>                                           */ DEADTRANS( L' '	,0xE9B3	,0x2AF7	,0x0000), // ' ' ➔ "⫷" TRIPLE NESTED LESS-THAN
/*<!M><3><%minus>                                                  */ DEADTRANS( L'-'	,0xE9A9	,0x2E3B	,0x0000), // '-' ➔ "⸻" THREE-EM DASH
/*<!M><3><%plus>                                                   */ DEADTRANS( L'+'	,0xE9A9	,0x29FB	,0x0000), // '+' ➔ "⧻" TRIPLE PLUS
/*<!M><3><%slash>                                                  */ DEADTRANS( L'/'	,0xE9A9	,0xE9B9	,0x0001), // Multikey chain
/*<!M><3><%slash><4>                                               */ DEADTRANS( L'4'	,0xE9B9	,0x00BE	,0x0000), // '4' ➔ "¾" VULGAR FRACTION THREE QUARTERS
/*<!M><3><%slash><5>                                               */ DEADTRANS( L'5'	,0xE9B9	,0x2157	,0x0000), // '5' ➔ "⅗" VULGAR FRACTION THREE FIFTHS
/*<!M><3><%slash><8>                                               */ DEADTRANS( L'8'	,0xE9B9	,0x215C	,0x0000), // '8' ➔ "⅜" VULGAR FRACTION THREE EIGHTHS
/*<!M><3><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xE9B9	,0x2AFB	,0x0000), // ' ' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><3><%slash><~space>                                          */ DEADTRANS( L' '	,0xE9B9	,0x2AFB	,0x0000), // ' ' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><3><%underscore>                                             */ DEADTRANS( L'_'	,0xE9A9	,0x25FB	,0x0000), // '_' ➔ "◻" WHITE MEDIUM SQUARE emoji
/*<!M><3><4>                                                       */ DEADTRANS( L'4'	,0xE9A9	,0x00BE	,0x0000), // '4' ➔ "¾" VULGAR FRACTION THREE QUARTERS
/*<!M><3><5>                                                       */ DEADTRANS( L'5'	,0xE9A9	,0x2157	,0x0000), // '5' ➔ "⅗" VULGAR FRACTION THREE FIFTHS
/*<!M><3><8>                                                       */ DEADTRANS( L'8'	,0xE9A9	,0x215C	,0x0000), // '8' ➔ "⅜" VULGAR FRACTION THREE EIGHTHS
/*<!M><3><d>                                                       */ DEADTRANS( L'd'	,0xE9A9	,0x21B8	,0x0000), // 'd' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3><D>                                                       */ DEADTRANS( L'D'	,0xE9A9	,0x21B8	,0x0000), // 'D' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3><h>                                                       */ DEADTRANS( L'h'	,0xE9A9	,0x21B8	,0x0000), // 'h' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3><H>                                                       */ DEADTRANS( L'H'	,0xE9A9	,0x21B8	,0x0000), // 'H' ➔ "↸" NORTH WEST ARROW TO LONG BAR
/*<!M><3><i>                                                       */ DEADTRANS( L'i'	,0xE9A9	,0xA70A	,0x0000), // 'i' ➔ "꜊" MODIFIER LETTER MID DOTTED TONE BAR
/*<!M><3><I>                                                       */ DEADTRANS( L'I'	,0xE9A9	,0xA70A	,0x0000), // 'I' ➔ "꜊" MODIFIER LETTER MID DOTTED TONE BAR
/*<!M><3><s>                                                       */ DEADTRANS( L's'	,0xE9A9	,0xE9C9	,0x0001), // Multikey chain
/*<!M><3><S>                                                       */ DEADTRANS( L'S'	,0xE9A9	,0xE9CA	,0x0001), // Multikey chain
/*<!M><3><s><o>                                                    */ DEADTRANS( L'o'	,0xE9C9	,0x2230	,0x0000), // 'o' ➔ "∰" VOLUME INTEGRAL
/*<!M><3><S><o>                                                    */ DEADTRANS( L'o'	,0xE9CA	,0x2230	,0x0000), // 'o' ➔ "∰" VOLUME INTEGRAL
/*<!M><3><s><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE9C9	,0x222D	,0x0000), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><S><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xE9CA	,0x222D	,0x0000), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><s><~space>                                               */ DEADTRANS( L' '	,0xE9C9	,0x222D	,0x0000), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><S><~space>                                               */ DEADTRANS( L' '	,0xE9CA	,0x222D	,0x0000), // ' ' ➔ "∭" TRIPLE INTEGRAL
/*<!M><3><t>                                                       */ DEADTRANS( L't'	,0xE9A9	,0x02E7	,0x0000), // 't' ➔ "˧" MODIFIER LETTER MID TONE BAR
/*<!M><3><v>                                                       */ DEADTRANS( L'v'	,0xE9A9	,0x221B	,0x0000), // 'v' ➔ "∛" CUBE ROOT
/*<!M><3><Z>                                                       */ DEADTRANS( L'Z'	,0xE9A9	,0x0417	,0x0000), // 'Z' ➔ "З" CYRILLIC CAPITAL LETTER ZE
/*<!M><3><z>                                                       */ DEADTRANS( L'z'	,0xE9A9	,0x0437	,0x0000), // 'z' ➔ "з" CYRILLIC SMALL LETTER ZE
/*<!M><4>                                                          */ DEADTRANS( L'4'	,0x00A6	,0xE9D5	,0x0001), // Multikey chain
/*<!M><4><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE9D5	,0x2057	,0x0000), // ''' ➔ "⁗" QUADRUPLE PRIME
/*<!M><4><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xE9D5	,0x2057	,0x0000), // '’' ➔ "⁗" QUADRUPLE PRIME
/*<!M><4><%asterisk>                                               */ DEADTRANS( L'*'	,0xE9D5	,0x264B	,0x0000), // '*' ➔ "♋" CANCER emoji
/*<!M><4><%hash>                                                   */ DEADTRANS( L'#'	,0xE9D5	,0x2B1B	,0x0000), // '#' ➔ "⬛" BLACK LARGE SQUARE emoji
/*<!M><4><%minus>                                                  */ DEADTRANS( L'-'	,0xE9D5	,0x2010	,0x0000), // '-' ➔ "‐" HYPHEN
/*<!M><4><%slash>                                                  */ DEADTRANS( L'/'	,0xE9D5	,0xE9DB	,0x0001), // Multikey chain
/*<!M><4><%slash><5>                                               */ DEADTRANS( L'5'	,0xE9DB	,0x2158	,0x0000), // '5' ➔ "⅘" VULGAR FRACTION FOUR FIFTHS
/*<!M><4><%underscore>                                             */ DEADTRANS( L'_'	,0xE9D5	,0x2B1C	,0x0000), // '_' ➔ "⬜" WHITE LARGE SQUARE emoji
/*<!M><4><5>                                                       */ DEADTRANS( L'5'	,0xE9D5	,0x2158	,0x0000), // '5' ➔ "⅘" VULGAR FRACTION FOUR FIFTHS
/*<!M><4><i>                                                       */ DEADTRANS( L'i'	,0xE9D5	,0xA709	,0x0000), // 'i' ➔ "꜉" MODIFIER LETTER HIGH DOTTED TONE BAR
/*<!M><4><I>                                                       */ DEADTRANS( L'I'	,0xE9D5	,0xA709	,0x0000), // 'I' ➔ "꜉" MODIFIER LETTER HIGH DOTTED TONE BAR
/*<!M><4><s>                                                       */ DEADTRANS( L's'	,0xE9D5	,0x2A0C	,0x0000), // 's' ➔ "⨌" QUADRUPLE INTEGRAL OPERATOR
/*<!M><4><S>                                                       */ DEADTRANS( L'S'	,0xE9D5	,0x2A0C	,0x0000), // 'S' ➔ "⨌" QUADRUPLE INTEGRAL OPERATOR
/*<!M><4><t>                                                       */ DEADTRANS( L't'	,0xE9D5	,0x02E6	,0x0000), // 't' ➔ "˦" MODIFIER LETTER HIGH TONE BAR
/*<!M><4><T>                                                       */ DEADTRANS( L'T'	,0xE9D5	,0x02E6	,0x0000), // 'T' ➔ "˦" MODIFIER LETTER HIGH TONE BAR
/*<!M><4><v>                                                       */ DEADTRANS( L'v'	,0xE9D5	,0x221C	,0x0000), // 'v' ➔ "∜" FOURTH ROOT
/*<!M><4><Z>                                                       */ DEADTRANS( L'Z'	,0xE9D5	,0x0427	,0x0000), // 'Z' ➔ "Ч" CYRILLIC CAPITAL LETTER CHE
/*<!M><4><z>                                                       */ DEADTRANS( L'z'	,0xE9D5	,0x0447	,0x0000), // 'z' ➔ "ч" CYRILLIC SMALL LETTER CHE
/*<!M><5>                                                          */ DEADTRANS( L'5'	,0x00A6	,0xE9E8	,0x0001), // Multikey chain
/*<!M><5><%asterisk>                                               */ DEADTRANS( L'*'	,0xE9E8	,0x264C	,0x0000), // '*' ➔ "♌" LEO emoji
/*<!M><5><%minus>                                                  */ DEADTRANS( L'-'	,0xE9E8	,0x2013	,0x0000), // '-' ➔ "–" EN DASH
/*<!M><5><%slash>                                                  */ DEADTRANS( L'/'	,0xE9E8	,0xE9EB	,0x0001), // Multikey chain
/*<!M><5><%slash><6>                                               */ DEADTRANS( L'6'	,0xE9EB	,0x215A	,0x0000), // '6' ➔ "⅚" VULGAR FRACTION FIVE SIXTHS
/*<!M><5><%slash><8>                                               */ DEADTRANS( L'8'	,0xE9EB	,0x215D	,0x0000), // '8' ➔ "⅝" VULGAR FRACTION FIVE EIGHTHS
/*<!M><5><6>                                                       */ DEADTRANS( L'6'	,0xE9E8	,0x215A	,0x0000), // '6' ➔ "⅚" VULGAR FRACTION FIVE SIXTHS
/*<!M><5><8>                                                       */ DEADTRANS( L'8'	,0xE9E8	,0x215D	,0x0000), // '8' ➔ "⅝" VULGAR FRACTION FIVE EIGHTHS
/*<!M><5><i>                                                       */ DEADTRANS( L'i'	,0xE9E8	,0xA708	,0x0000), // 'i' ➔ "꜈" MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*<!M><5><I>                                                       */ DEADTRANS( L'I'	,0xE9E8	,0xA708	,0x0000), // 'I' ➔ "꜈" MODIFIER LETTER EXTRA-HIGH DOTTED TONE BAR
/*<!M><5><t>                                                       */ DEADTRANS( L't'	,0xE9E8	,0x02E5	,0x0000), // 't' ➔ "˥" MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!M><5><T>                                                       */ DEADTRANS( L'T'	,0xE9E8	,0x02E5	,0x0000), // 'T' ➔ "˥" MODIFIER LETTER EXTRA-HIGH TONE BAR
/*<!M><5><Z>                                                       */ DEADTRANS( L'Z'	,0xE9E8	,0x01BC	,0x0000), // 'Z' ➔ "Ƽ" LATIN CAPITAL LETTER TONE FIVE
/*<!M><5><z>                                                       */ DEADTRANS( L'z'	,0xE9E8	,0x01BD	,0x0000), // 'z' ➔ "ƽ" LATIN SMALL LETTER TONE FIVE
/*<!M><6>                                                          */ DEADTRANS( L'6'	,0x00A6	,0xE9F6	,0x0001), // Multikey chain
/*<!M><6><%apostrophe>                                             */ DEADTRANS( L'\''	,0xE9F6	,0x2018	,0x0000), // ''' ➔ "‘" LEFT SINGLE QUOTATION MARK
/*<!M><6><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xE9F6	,0x2018	,0x0000), // '’' ➔ "‘" LEFT SINGLE QUOTATION MARK
/*<!M><6><%asterisk>                                               */ DEADTRANS( L'*'	,0xE9F6	,0x264D	,0x0000), // '*' ➔ "♍" VIRGO emoji
/*<!M><6><%minus>                                                  */ DEADTRANS( L'-'	,0xE9F6	,0x2011	,0x0000), // '-' ➔ "‑" NON-BREAKING HYPHEN
/*<!M><6><%quotedbl>                                               */ DEADTRANS( L'"'	,0xE9F6	,0x201C	,0x0000), // '"' ➔ "“" LEFT DOUBLE QUOTATION MARK
/*<!M><6><%quotEuroSign>                                           */ DEADTRANS( 0x20AC	,0xE9F6	,0x201C	,0x0000), // '€' ➔ "“" LEFT DOUBLE QUOTATION MARK
/*<!M><6><Z>                                                       */ DEADTRANS( L'Z'	,0xE9F6	,0x0184	,0x0000), // 'Z' ➔ "Ƅ" LATIN CAPITAL LETTER TONE SIX
/*<!M><6><z>                                                       */ DEADTRANS( L'z'	,0xE9F6	,0x0185	,0x0000), // 'z' ➔ "ƅ" LATIN SMALL LETTER TONE SIX
/*<!M><7>                                                          */ DEADTRANS( L'7'	,0x00A6	,0xE9FF	,0x0001), // Multikey chain
/*<!M><7><%asterisk>                                               */ DEADTRANS( L'*'	,0xE9FF	,0x264E	,0x0000), // '*' ➔ "♎" LIBRA emoji
/*<!M><7><%circum>                                                 */ DEADTRANS( L'^'	,0xE9FF	,0xEA01	,0x0001), // Multikey chain
/*<!M><7><%circum><r>                                              */ DEADTRANS( L'r'	,0xEA01	,0x02C1	,0x0000), // 'r' ➔ "ˁ" MODIFIER LETTER REVERSED GLOTTAL STOP
/*<!M><7><%circum><R>                                              */ DEADTRANS( L'R'	,0xEA01	,0xDFB4	,0x0000), // High surrogate: D801; U+107B4 'R' ➔ "𐞴" MODIFIER LETTER REVERSED GLOTTAL STOP WITH STROKE
/*<!M><7><%circum><s>                                              */ DEADTRANS( L's'	,0xEA01	,0x02E4	,0x0000), // 's' ➔ "ˤ" MODIFIER LETTER SMALL REVERSED GLOTTAL STOP
/*<!M><7><%circum><u>                                              */ DEADTRANS( L'u'	,0xEA01	,0x02C0	,0x0000), // 'u' ➔ "ˀ" MODIFIER LETTER GLOTTAL STOP
/*<!M><7><%circum><U>                                              */ DEADTRANS( L'U'	,0xEA01	,0xDFB3	,0x0000), // High surrogate: D801; U+107B3 'U' ➔ "𐞳" MODIFIER LETTER GLOTTAL STOP WITH STROKE
/*<!M><7><%minus>                                                  */ DEADTRANS( L'-'	,0xE9FF	,0x2015	,0x0000), // '-' ➔ "―" HORIZONTAL BAR
/*<!M><7><%slash>                                                  */ DEADTRANS( L'/'	,0xE9FF	,0xEA08	,0x0001), // Multikey chain
/*<!M><7><%slash><8>                                               */ DEADTRANS( L'8'	,0xEA08	,0x215E	,0x0000), // '8' ➔ "⅞" VULGAR FRACTION SEVEN EIGHTHS
/*<!M><7><7>                                                       */ DEADTRANS( L'7'	,0xE9FF	,0x0294	,0x0000), // '7' ➔ "ʔ" LATIN LETTER GLOTTAL STOP
/*<!M><7><8>                                                       */ DEADTRANS( L'8'	,0xE9FF	,0x215E	,0x0000), // '8' ➔ "⅞" VULGAR FRACTION SEVEN EIGHTHS
/*<!M><7><c>                                                       */ DEADTRANS( L'c'	,0xE9FF	,0x0241	,0x0000), // 'c' ➔ "Ɂ" LATIN CAPITAL LETTER GLOTTAL STOP
/*<!M><7><C>                                                       */ DEADTRANS( L'C'	,0xE9FF	,0xDF0E	,0x0000), // High surrogate: D837; U+1DF0E 'C' ➔ "𝼎" LATIN LETTER INVERTED GLOTTAL STOP WITH CURL
/*<!M><7><I>                                                       */ DEADTRANS( L'I'	,0xE9FF	,0x01BE	,0x0000), // 'I' ➔ "ƾ" LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
/*<!M><7><i>                                                       */ DEADTRANS( L'i'	,0xE9FF	,0x0296	,0x0000), // 'i' ➔ "ʖ" LATIN LETTER INVERTED GLOTTAL STOP
/*<!M><7><M>                                                       */ DEADTRANS( L'M'	,0xE9FF	,0x0241	,0x0000), // 'M' ➔ "Ɂ" LATIN CAPITAL LETTER GLOTTAL STOP
/*<!M><7><m>                                                       */ DEADTRANS( L'm'	,0xE9FF	,0x0242	,0x0000), // 'm' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7><r>                                                       */ DEADTRANS( L'r'	,0xE9FF	,0x0295	,0x0000), // 'r' ➔ "ʕ" LATIN LETTER PHARYNGEAL VOICED FRICATIVE
/*<!M><7><R>                                                       */ DEADTRANS( L'R'	,0xE9FF	,0x02A2	,0x0000), // 'R' ➔ "ʢ" LATIN LETTER REVERSED GLOTTAL STOP WITH STROKE
/*<!M><7><S>                                                       */ DEADTRANS( L'S'	,0xE9FF	,0x0242	,0x0000), // 'S' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7><s>                                                       */ DEADTRANS( L's'	,0xE9FF	,0x0242	,0x0000), // 's' ➔ "ɂ" LATIN SMALL LETTER GLOTTAL STOP
/*<!M><7><u>                                                       */ DEADTRANS( L'u'	,0xE9FF	,0x0294	,0x0000), // 'u' ➔ "ʔ" LATIN LETTER GLOTTAL STOP
/*<!M><7><U>                                                       */ DEADTRANS( L'U'	,0xE9FF	,0x02A1	,0x0000), // 'U' ➔ "ʡ" LATIN LETTER GLOTTAL STOP WITH STROKE
/*<!M><8>                                                          */ DEADTRANS( L'8'	,0x00A6	,0xEA18	,0x0001), // Multikey chain
/*<!M><8><%asterisk>                                               */ DEADTRANS( L'*'	,0xEA18	,0x264F	,0x0000), // '*' ➔ "♏" SCORPIUS emoji
/*<!M><8><%backslash>                                              */ DEADTRANS( L'\\'	,0xEA18	,0x221D	,0x0000), // '\' ➔ "∝" PROPORTIONAL TO
/*<!M><8><%bar>                                                    */ DEADTRANS( L'|'	,0xEA18	,0x29DE	,0x0000), // '|' ➔ "⧞" INFINITY NEGATED WITH VERTICAL BAR
/*<!M><8><%greater>                                                */ DEADTRANS( L'>'	,0xEA18	,0x2661	,0x0000), // '>' ➔ "♡" WHITE HEART SUIT
/*<!M><8><%minus>                                                  */ DEADTRANS( L'-'	,0xEA18	,0x2E40	,0x0000), // '-' ➔ "⹀" DOUBLE HYPHEN
/*<!M><8><x>                                                       */ DEADTRANS( L'x'	,0xEA18	,0xEA1E	,0x0001), // Multikey chain
/*<!M><8><X>                                                       */ DEADTRANS( L'X'	,0xEA18	,0xEA1F	,0x0001), // Multikey chain
/*<!M><8><x><a>                                                    */ DEADTRANS( L'a'	,0xEA1E	,0x2704	,0x0000), // 'a' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X><A>                                                    */ DEADTRANS( L'A'	,0xEA1F	,0x2704	,0x0000), // 'A' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x><b>                                                    */ DEADTRANS( L'b'	,0xEA1E	,0x2703	,0x0000), // 'b' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><X><B>                                                    */ DEADTRANS( L'B'	,0xEA1F	,0x2703	,0x0000), // 'B' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><x><c>                                                    */ DEADTRANS( L'c'	,0xEA1E	,0x2704	,0x0000), // 'c' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X><C>                                                    */ DEADTRANS( L'C'	,0xEA1F	,0x2704	,0x0000), // 'C' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x><h>                                                    */ DEADTRANS( L'h'	,0xEA1E	,0x2701	,0x0000), // 'h' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><X><H>                                                    */ DEADTRANS( L'H'	,0xEA1F	,0x2701	,0x0000), // 'H' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><x><l>                                                    */ DEADTRANS( L'l'	,0xEA1E	,0x2703	,0x0000), // 'l' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><X><L>                                                    */ DEADTRANS( L'L'	,0xEA1F	,0x2703	,0x0000), // 'L' ➔ "✃" LOWER BLADE SCISSORS
/*<!M><8><x><o>                                                    */ DEADTRANS( L'o'	,0xEA1E	,0x2704	,0x0000), // 'o' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><X><O>                                                    */ DEADTRANS( L'O'	,0xEA1F	,0x2704	,0x0000), // 'O' ➔ "✄" WHITE SCISSORS, outline scissors
/*<!M><8><x><p>                                                    */ DEADTRANS( L'p'	,0xEA1E	,0x2702	,0x0000), // 'p' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><X><P>                                                    */ DEADTRANS( L'P'	,0xEA1F	,0x2702	,0x0000), // 'P' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><x><s>                                                    */ DEADTRANS( L's'	,0xEA1E	,0x2700	,0x0000), // 's' ➔ "✀" BLACK SAFETY SCISSORS
/*<!M><8><X><S>                                                    */ DEADTRANS( L'S'	,0xEA1F	,0x2700	,0x0000), // 'S' ➔ "✀" BLACK SAFETY SCISSORS
/*<!M><8><x><u>                                                    */ DEADTRANS( L'u'	,0xEA1E	,0x2701	,0x0000), // 'u' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><X><U>                                                    */ DEADTRANS( L'U'	,0xEA1F	,0x2701	,0x0000), // 'U' ➔ "✁" UPPER BLADE SCISSORS
/*<!M><8><x><~space>                                               */ DEADTRANS( L' '	,0xEA1E	,0x2702	,0x0000), // ' ' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><X><~space>                                               */ DEADTRANS( L' '	,0xEA1F	,0x2702	,0x0000), // ' ' ➔ "✂" BLACK SCISSORS emoji
/*<!M><8><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEA18	,0x221E	,0x0000), // ' ' ➔ "∞" INFINITY
/*<!M><8><~space>                                                  */ DEADTRANS( L' '	,0xEA18	,0x221E	,0x0000), // ' ' ➔ "∞" INFINITY
/*<!M><9>                                                          */ DEADTRANS( L'9'	,0x00A6	,0xEA36	,0x0001), // Multikey chain
/*<!M><9><%apostrophe>                                             */ DEADTRANS( L'\''	,0xEA36	,0x2019	,0x0000), // ''' ➔ "’" RIGHT SINGLE QUOTATION MARK
/*<!M><9><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xEA36	,0x2019	,0x0000), // '’' ➔ "’" RIGHT SINGLE QUOTATION MARK
/*<!M><9><%asterisk>                                               */ DEADTRANS( L'*'	,0xEA36	,0x2650	,0x0000), // '*' ➔ "♐" SAGITTARIUS emoji
/*<!M><9><%comma>                                                  */ DEADTRANS( L','	,0xEA36	,0x201A	,0x0000), // ',' ➔ "‚" SINGLE LOW-9 QUOTATION MARK
/*<!M><9><%minus>                                                  */ DEADTRANS( L'-'	,0xEA36	,0x2012	,0x0000), // '-' ➔ "‒" FIGURE DASH
/*<!M><9><%quotedbl>                                               */ DEADTRANS( L'"'	,0xEA36	,0x201D	,0x0000), // '"' ➔ "”" RIGHT DOUBLE QUOTATION MARK
/*<!M><9><%quotEuroSign>                                           */ DEADTRANS( 0x20AC	,0xEA36	,0x201D	,0x0000), // '€' ➔ "”" RIGHT DOUBLE QUOTATION MARK
/*<!M><9><%underscore>                                             */ DEADTRANS( L'_'	,0xEA36	,0x201E	,0x0000), // '_' ➔ "„" DOUBLE LOW-9 QUOTATION MARK
/*<!M><9><C>                                                       */ DEADTRANS( L'C'	,0xEA36	,0xA76E	,0x0000), // 'C' ➔ "Ꝯ" LATIN CAPITAL LETTER CON
/*<!M><9><c>                                                       */ DEADTRANS( L'c'	,0xEA36	,0xA76F	,0x0000), // 'c' ➔ "ꝯ" LATIN SMALL LETTER CON
/*<!M><a>                                                          */ DEADTRANS( L'a'	,0x00A6	,0xEA41	,0x0001), // Multikey chain
/*<!M><A>                                                          */ DEADTRANS( L'A'	,0x00A6	,0xEA42	,0x0001), // Multikey chain
/*<!M><A><%asterisk>                                               */ DEADTRANS( L'*'	,0xEA42	,0x2651	,0x0000), // '*' ➔ "♑" CAPRICORN emoji
/*<!M><a><%asterisk>                                               */ DEADTRANS( L'*'	,0xEA41	,0x2651	,0x0000), // '*' ➔ "♑" CAPRICORN emoji
/*<!M><a><%backslash>                                              */ DEADTRANS( L'\\'	,0xEA41	,0x2135	,0x0000), // '\' ➔ "ℵ" ALEF SYMBOL
/*<!M><A><%backslash>                                              */ DEADTRANS( L'\\'	,0xEA42	,0x2135	,0x0000), // '\' ➔ "ℵ" ALEF SYMBOL
/*<!M><a><%bar>                                                    */ DEADTRANS( L'|'	,0xEA41	,0x2A5A	,0x0000), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><A><%bar>                                                    */ DEADTRANS( L'|'	,0xEA42	,0x2A5A	,0x0000), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><a><%bracketright>                                           */ DEADTRANS( L']'	,0xEA41	,0x27CE	,0x0000), // ']' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><A><%equal>                                                  */ DEADTRANS( L'='	,0xEA42	,0x20B3	,0x0000), // '=' ➔ "₳" AUSTRAL SIGN
/*<!M><a><%equal>                                                  */ DEADTRANS( L'='	,0xEA41	,0x2259	,0x0000), // '=' ➔ "≙" ESTIMATES
/*<!M><a><%hash>                                                   */ DEADTRANS( L'#'	,0xEA41	,0x29EB	,0x0000), // '#' ➔ "⧫" BLACK LOZENGE
/*<!M><A><%minus>                                                  */ DEADTRANS( L'-'	,0xEA42	,0xEA4D	,0x0001), // Multikey chain
/*<!M><a><%minus>                                                  */ DEADTRANS( L'-'	,0xEA41	,0xEA4E	,0x0001), // Multikey chain
/*<!M><A><%minus><V>                                               */ DEADTRANS( L'V'	,0xEA4D	,0xEA4F	,0x0001), // Multikey chain
/*<!M><A><%minus><v>                                               */ DEADTRANS( L'v'	,0xEA4D	,0xEA50	,0x0001), // Multikey chain
/*<!M><a><%minus><v>                                               */ DEADTRANS( L'v'	,0xEA4E	,0xEA51	,0x0001), // Multikey chain
/*<!M><A><%minus><V><%minus>                                       */ DEADTRANS( L'-'	,0xEA4F	,0xA73A	,0x0000), // '-' ➔ "Ꜻ" LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*<!M><A><%minus><v><%minus>                                       */ DEADTRANS( L'-'	,0xEA50	,0xA73A	,0x0000), // '-' ➔ "Ꜻ" LATIN CAPITAL LETTER AV WITH HORIZONTAL BAR
/*<!M><a><%minus><v><%minus>                                       */ DEADTRANS( L'-'	,0xEA51	,0xA73B	,0x0000), // '-' ➔ "ꜻ" LATIN SMALL LETTER AV WITH HORIZONTAL BAR
/*<!M><a><%minus><v><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEA51	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus><v><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEA50	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus><V><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEA4F	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><a><%minus><v><~space>                                       */ DEADTRANS( L' '	,0xEA51	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus><v><~space>                                       */ DEADTRANS( L' '	,0xEA50	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus><V><~space>                                       */ DEADTRANS( L' '	,0xEA4F	,0x27E0	,0x0000), // ' ' ➔ "⟠" LOZENGE DIVIDED BY HORIZONTAL RULE
/*<!M><A><%minus><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEA4D	,0x2A5C	,0x0000), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%minus><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEA4E	,0x2A5C	,0x0000), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><A><%minus><~space>                                          */ DEADTRANS( L' '	,0xEA4D	,0x2A5C	,0x0000), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%minus><~space>                                          */ DEADTRANS( L' '	,0xEA4E	,0x2A5C	,0x0000), // ' ' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><a><%parenleft>                                              */ DEADTRANS( L'('	,0xEA41	,0xEA5F	,0x0001), // Multikey chain
/*<!M><a><%parenleft><%parenright>                                 */ DEADTRANS( L')'	,0xEA5F	,0x22CF	,0x0000), // ')' ➔ "⋏" CURLY LOGICAL AND
/*<!M><a><%parenright>                                             */ DEADTRANS( L')'	,0xEA41	,0xEA61	,0x0001), // Multikey chain
/*<!M><a><%parenright><%parenleft>                                 */ DEADTRANS( L'('	,0xEA61	,0x22CF	,0x0000), // '(' ➔ "⋏" CURLY LOGICAL AND
/*<!M><a><%period>                                                 */ DEADTRANS( L'.'	,0xEA41	,0x27D1	,0x0000), // '.' ➔ "⟑" AND WITH DOT
/*<!M><A><%plus>                                                   */ DEADTRANS( L'+'	,0xEA42	,0x2A39	,0x0000), // '+' ➔ "⨹" PLUS SIGN IN TRIANGLE
/*<!M><a><%slash>                                                  */ DEADTRANS( L'/'	,0xEA41	,0xEA66	,0x0001), // Multikey chain
/*<!M><A><%slash>                                                  */ DEADTRANS( L'/'	,0xEA42	,0x214D	,0x0000), // '/' ➔ "⅍" AKTIESELSKAB
/*<!M><a><%slash><c>                                               */ DEADTRANS( L'c'	,0xEA66	,0x2100	,0x0000), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><a><%slash><s>                                               */ DEADTRANS( L's'	,0xEA66	,0x2101	,0x0000), // 's' ➔ "℁" ADDRESSED TO THE SUBJECT
/*<!M><a><%underscore>                                             */ DEADTRANS( L'_'	,0xEA41	,0x00AA	,0x0000), // '_' ➔ "ª" FEMININE ORDINAL INDICATOR
/*<!M><A><%underscore>                                             */ DEADTRANS( L'_'	,0xEA42	,0x00AA	,0x0000), // '_' ➔ "ª" FEMININE ORDINAL INDICATOR
/*<!M><A><A>                                                       */ DEADTRANS( L'A'	,0xEA42	,0xA732	,0x0000), // 'A' ➔ "Ꜳ" LATIN CAPITAL LETTER AA
/*<!M><A><a>                                                       */ DEADTRANS( L'a'	,0xEA42	,0xA732	,0x0000), // 'a' ➔ "Ꜳ" LATIN CAPITAL LETTER AA
/*<!M><a><a>                                                       */ DEADTRANS( L'a'	,0xEA41	,0xA733	,0x0000), // 'a' ➔ "ꜳ" LATIN SMALL LETTER AA
/*<!M><a><c>                                                       */ DEADTRANS( L'c'	,0xEA41	,0x2100	,0x0000), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><a><C>                                                       */ DEADTRANS( L'C'	,0xEA41	,0x2100	,0x0000), // 'C' ➔ "℀" ACCOUNT OF
/*<!M><A><C>                                                       */ DEADTRANS( L'C'	,0xEA42	,0x2100	,0x0000), // 'C' ➔ "℀" ACCOUNT OF
/*<!M><A><c>                                                       */ DEADTRANS( L'c'	,0xEA42	,0x2100	,0x0000), // 'c' ➔ "℀" ACCOUNT OF
/*<!M><A><E>                                                       */ DEADTRANS( L'E'	,0xEA42	,0xEA73	,0x0001), // Multikey chain
/*<!M><a><e>                                                       */ DEADTRANS( L'e'	,0xEA41	,0xEA74	,0x0001), // Multikey chain
/*<!M><A><e>                                                       */ DEADTRANS( L'e'	,0xEA42	,0x00C6	,0x0000), // 'e' ➔ "Æ" LATIN CAPITAL LETTER AE
/*<!M><A><E><~space>                                               */ DEADTRANS( L' '	,0xEA73	,0x00C6	,0x0000), // ' ' ➔ "Æ" LATIN CAPITAL LETTER AE
/*<!M><a><e><~space>                                               */ DEADTRANS( L' '	,0xEA74	,0x00E6	,0x0000), // ' ' ➔ "æ" LATIN SMALL LETTER AE
/*<!M><a><f>                                                       */ DEADTRANS( L'f'	,0xEA41	,0xEA79	,0x0001), // Multikey chain
/*<!M><A><F>                                                       */ DEADTRANS( L'F'	,0xEA42	,0xEA7A	,0x0001), // Multikey chain
/*<!M><a><f><n>                                                    */ DEADTRANS( L'n'	,0xEA79	,0x060B	,0x0000), // 'n' ➔ "؋" AFGHANI SIGN, Afghani AFGHANISTAN
/*<!M><A><F><N>                                                    */ DEADTRANS( L'N'	,0xEA7A	,0x060B	,0x0000), // 'N' ➔ "؋" AFGHANI SIGN, Afghani AFGHANISTAN
/*<!M><a><l>                                                       */ DEADTRANS( L'l'	,0xEA41	,0xEA7D	,0x0001), // Multikey chain
/*<!M><A><L>                                                       */ DEADTRANS( L'L'	,0xEA42	,0xEA7E	,0x0001), // Multikey chain
/*<!M><a><l><t>                                                    */ DEADTRANS( L't'	,0xEA7D	,0x2387	,0x0000), // 't' ➔ "⎇" ALTERNATIVE KEY SYMBOL
/*<!M><A><L><T>                                                    */ DEADTRANS( L'T'	,0xEA7E	,0x2387	,0x0000), // 'T' ➔ "⎇" ALTERNATIVE KEY SYMBOL
/*<!M><a><m>                                                       */ DEADTRANS( L'm'	,0xEA41	,0xEA81	,0x0001), // Multikey chain
/*<!M><A><M>                                                       */ DEADTRANS( L'M'	,0xEA42	,0xEA82	,0x0001), // Multikey chain
/*<!M><a><m><d>                                                    */ DEADTRANS( L'd'	,0xEA81	,0x058F	,0x0000), // 'd' ➔ "֏" ARMENIAN DRAM SIGN, Armenian Dram ARMENIA
/*<!M><A><M><D>                                                    */ DEADTRANS( L'D'	,0xEA82	,0x058F	,0x0000), // 'D' ➔ "֏" ARMENIAN DRAM SIGN, Armenian Dram ARMENIA
/*<!M><a><n>                                                       */ DEADTRANS( L'n'	,0xEA41	,0xEA85	,0x0001), // Multikey chain
/*<!M><A><N>                                                       */ DEADTRANS( L'N'	,0xEA42	,0xEA86	,0x0001), // Multikey chain
/*<!M><a><n><d>                                                    */ DEADTRANS( L'd'	,0xEA85	,0x2227	,0x0000), // 'd' ➔ "∧" LOGICAL AND
/*<!M><A><N><D>                                                    */ DEADTRANS( L'D'	,0xEA86	,0x2227	,0x0000), // 'D' ➔ "∧" LOGICAL AND
/*<!M><a><n><g>                                                    */ DEADTRANS( L'g'	,0xEA85	,0x0192	,0x0000), // 'g' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Netherlands Antillean Guilder CURAÇAO, SINT MAARTEN (DUTCH PART)
/*<!M><A><N><G>                                                    */ DEADTRANS( L'G'	,0xEA86	,0x0192	,0x0000), // 'G' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Netherlands Antillean Guilder CURAÇAO, SINT MAARTEN (DUTCH PART)
/*<!M><A><O>                                                       */ DEADTRANS( L'O'	,0xEA42	,0xA734	,0x0000), // 'O' ➔ "Ꜵ" LATIN CAPITAL LETTER AO
/*<!M><A><o>                                                       */ DEADTRANS( L'o'	,0xEA42	,0xA734	,0x0000), // 'o' ➔ "Ꜵ" LATIN CAPITAL LETTER AO
/*<!M><a><o>                                                       */ DEADTRANS( L'o'	,0xEA41	,0xA735	,0x0000), // 'o' ➔ "ꜵ" LATIN SMALL LETTER AO
/*<!M><a><q>                                                       */ DEADTRANS( L'q'	,0xEA41	,0xEA8F	,0x0001), // Multikey chain
/*<!M><A><Q>                                                       */ DEADTRANS( L'Q'	,0xEA42	,0x2652	,0x0000), // 'Q' ➔ "♒" AQUARIUS emoji
/*<!M><a><q><u>                                                    */ DEADTRANS( L'u'	,0xEA8F	,0xEA90	,0x0001), // Multikey chain
/*<!M><a><q><u><a>                                                 */ DEADTRANS( L'a'	,0xEA90	,0x2652	,0x0000), // 'a' ➔ "♒" AQUARIUS emoji
/*<!M><a><r>                                                       */ DEADTRANS( L'r'	,0xEA41	,0xEA93	,0x0001), // Multikey chain
/*<!M><A><R>                                                       */ DEADTRANS( L'R'	,0xEA42	,0x2648	,0x0000), // 'R' ➔ "♈" ARIES emoji
/*<!M><a><r><i>                                                    */ DEADTRANS( L'i'	,0xEA93	,0xEA94	,0x0001), // Multikey chain
/*<!M><a><r><i><e>                                                 */ DEADTRANS( L'e'	,0xEA94	,0x2648	,0x0000), // 'e' ➔ "♈" ARIES emoji
/*<!M><a><s>                                                       */ DEADTRANS( L's'	,0xEA41	,0x2101	,0x0000), // 's' ➔ "℁" ADDRESSED TO THE SUBJECT
/*<!M><A><S>                                                       */ DEADTRANS( L'S'	,0xEA42	,0x214D	,0x0000), // 'S' ➔ "⅍" AKTIESELSKAB
/*<!M><A><U>                                                       */ DEADTRANS( L'U'	,0xEA42	,0xA736	,0x0000), // 'U' ➔ "Ꜷ" LATIN CAPITAL LETTER AU
/*<!M><A><u>                                                       */ DEADTRANS( L'u'	,0xEA42	,0xA736	,0x0000), // 'u' ➔ "Ꜷ" LATIN CAPITAL LETTER AU
/*<!M><a><u>                                                       */ DEADTRANS( L'u'	,0xEA41	,0xA737	,0x0000), // 'u' ➔ "ꜷ" LATIN SMALL LETTER AU
/*<!M><A><V>                                                       */ DEADTRANS( L'V'	,0xEA42	,0xA738	,0x0000), // 'V' ➔ "Ꜹ" LATIN CAPITAL LETTER AV
/*<!M><A><v>                                                       */ DEADTRANS( L'v'	,0xEA42	,0xA738	,0x0000), // 'v' ➔ "Ꜹ" LATIN CAPITAL LETTER AV
/*<!M><a><v>                                                       */ DEADTRANS( L'v'	,0xEA41	,0xA739	,0x0000), // 'v' ➔ "ꜹ" LATIN SMALL LETTER AV
/*<!M><a><w>                                                       */ DEADTRANS( L'w'	,0xEA41	,0xEA9E	,0x0001), // Multikey chain
/*<!M><A><W>                                                       */ DEADTRANS( L'W'	,0xEA42	,0xEA9F	,0x0001), // Multikey chain
/*<!M><a><w><g>                                                    */ DEADTRANS( L'g'	,0xEA9E	,0x0192	,0x0000), // 'g' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Aruban Florin ARUBA
/*<!M><A><W><G>                                                    */ DEADTRANS( L'G'	,0xEA9F	,0x0192	,0x0000), // 'G' ➔ "ƒ" LATIN SMALL LETTER F WITH HOOK, Aruban Florin ARUBA
/*<!M><A><x>                                                       */ DEADTRANS( L'x'	,0xEA42	,0x2A3B	,0x0000), // 'x' ➔ "⨻" MULTIPLICATION SIGN IN TRIANGLE
/*<!M><A><Y>                                                       */ DEADTRANS( L'Y'	,0xEA42	,0xA73C	,0x0000), // 'Y' ➔ "Ꜽ" LATIN CAPITAL LETTER AY
/*<!M><A><y>                                                       */ DEADTRANS( L'y'	,0xEA42	,0xA73C	,0x0000), // 'y' ➔ "Ꜽ" LATIN CAPITAL LETTER AY
/*<!M><a><y>                                                       */ DEADTRANS( L'y'	,0xEA41	,0xA73D	,0x0000), // 'y' ➔ "ꜽ" LATIN SMALL LETTER AY
/*<!M><a><z>                                                       */ DEADTRANS( L'z'	,0xEA41	,0xEAA6	,0x0001), // Multikey chain
/*<!M><A><Z>                                                       */ DEADTRANS( L'Z'	,0xEA42	,0xEAA7	,0x0001), // Multikey chain
/*<!M><a><z><n>                                                    */ DEADTRANS( L'n'	,0xEAA6	,0x20BC	,0x0000), // 'n' ➔ "₼" MANAT SIGN, Azerbaijan Manat AZERBAIJAN
/*<!M><A><Z><N>                                                    */ DEADTRANS( L'N'	,0xEAA7	,0x20BC	,0x0000), // 'N' ➔ "₼" MANAT SIGN, Azerbaijan Manat AZERBAIJAN
/*<!M><A><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEA42	,0x2200	,0x0000), // ' ' ➔ "∀" FOR ALL
/*<!M><a><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEA41	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><A><~space>                                                  */ DEADTRANS( L' '	,0xEA42	,0x2200	,0x0000), // ' ' ➔ "∀" FOR ALL
/*<!M><a><~space>                                                  */ DEADTRANS( L' '	,0xEA41	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><b>                                                          */ DEADTRANS( L'b'	,0x00A6	,0xEAAE	,0x0001), // Multikey chain
/*<!M><B>                                                          */ DEADTRANS( L'B'	,0x00A6	,0xEAAF	,0x0001), // Multikey chain
/*<!M><b><%apostrophe>                                             */ DEADTRANS( L'\''	,0xEAAE	,0xEAB1	,0x0001), // Multikey chain
/*<!M><B><%apostrophe>                                             */ DEADTRANS( L'\''	,0xEAAF	,0xA721	,0x0000), // ''' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><b><%apostrophe><%parenleft>                                 */ DEADTRANS( L'('	,0xEAB1	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><b><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xEAAE	,0xEAB4	,0x0001), // Multikey chain
/*<!M><B><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xEAAF	,0xA721	,0x0000), // '’' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><b><%aprightsingquotmark><%parenleft>                        */ DEADTRANS( L'('	,0xEAB4	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><B><%asterisk>                                               */ DEADTRANS( L'*'	,0xEAAF	,0x2652	,0x0000), // '*' ➔ "♒" AQUARIUS emoji
/*<!M><b><%asterisk>                                               */ DEADTRANS( L'*'	,0xEAAE	,0x2652	,0x0000), // '*' ➔ "♒" AQUARIUS emoji
/*<!M><b><%at>                                                     */ DEADTRANS( L'@'	,0xEAAE	,0x03D0	,0x0000), // '@' ➔ "ϐ" GREEK BETA SYMBOL
/*<!M><b><%backslash>                                              */ DEADTRANS( L'\\'	,0xEAAE	,0x2136	,0x0000), // '\' ➔ "ℶ" BET SYMBOL
/*<!M><B><%backslash>                                              */ DEADTRANS( L'\\'	,0xEAAF	,0x2136	,0x0000), // '\' ➔ "ℶ" BET SYMBOL
/*<!M><b><%bracketleft>                                            */ DEADTRANS( L'['	,0xEAAE	,0xEABB	,0x0001), // Multikey chain
/*<!M><b><%bracketleft><%slash>                                    */ DEADTRANS( L'/'	,0xEABB	,0x22E3	,0x0000), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketleft><%underscore>                               */ DEADTRANS( L'_'	,0xEABB	,0xEABD	,0x0001), // Multikey chain
/*<!M><b><%bracketleft><%underscore><%slash>                       */ DEADTRANS( L'/'	,0xEABD	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><b><%bracketright>                                           */ DEADTRANS( L']'	,0xEAAE	,0xEABF	,0x0001), // Multikey chain
/*<!M><b><%bracketright><%slash>                                   */ DEADTRANS( L'/'	,0xEABF	,0x22E3	,0x0000), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright><%underscore>                              */ DEADTRANS( L'_'	,0xEABF	,0xEAC1	,0x0001), // Multikey chain
/*<!M><b><%bracketright><%underscore><%slash>                      */ DEADTRANS( L'/'	,0xEAC1	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><b><%bracketright><%underscore><~nbspace>                    */ DEADTRANS( 0x00A0	,0xEAC1	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright><%underscore><~space>                      */ DEADTRANS( L' '	,0xEAC1	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><b><%bracketright><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xEABF	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><b><%bracketright><~space>                                   */ DEADTRANS( L' '	,0xEABF	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><b><%equal>                                                  */ DEADTRANS( L'='	,0xEAAE	,0xEAC7	,0x0001), // Multikey chain
/*<!M><b><%equal><%slash>                                          */ DEADTRANS( L'/'	,0xEAC7	,0x2ACC	,0x0000), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><b><%equal><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEAC7	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><b><%equal><~space>                                          */ DEADTRANS( L' '	,0xEAC7	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><b><%hash>                                                   */ DEADTRANS( L'#'	,0xEAAE	,0x266D	,0x0000), // '#' ➔ "♭" MUSIC FLAT SIGN
/*<!M><b><%less>                                                   */ DEADTRANS( L'<'	,0xEAAE	,0x297B	,0x0000), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><b><%minus>                                                  */ DEADTRANS( L'-'	,0xEAAE	,0xEACD	,0x0001), // Multikey chain
/*<!M><b><%minus><%greater>                                        */ DEADTRANS( L'>'	,0xEACD	,0x2B44	,0x0000), // '>' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><b><%minus><c>                                               */ DEADTRANS( L'c'	,0xEACD	,0x2AD8	,0x0000), // 'c' ➔ "⫘" SUPERSET BESIDE AND JOINED BY DASH WITH SUBSET
/*<!M><b><%parenleft>                                              */ DEADTRANS( L'('	,0xEAAE	,0x02FB	,0x0000), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><B><%parenleft>                                              */ DEADTRANS( L'('	,0xEAAF	,0x02FB	,0x0000), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><b><%parenright>                                             */ DEADTRANS( L')'	,0xEAAE	,0x02FC	,0x0000), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><B><%parenright>                                             */ DEADTRANS( L')'	,0xEAAF	,0x02FC	,0x0000), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><b><%period>                                                 */ DEADTRANS( L'.'	,0xEAAE	,0x2ABE	,0x0000), // '.' ➔ "⪾" SUPERSET WITH DOT
/*<!M><b><%plus>                                                   */ DEADTRANS( L'+'	,0xEAAE	,0x2AC0	,0x0000), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><b><%slash>                                                  */ DEADTRANS( L'/'	,0xEAAE	,0xEAD6	,0x0001), // Multikey chain
/*<!M><b><%slash><%underscore>                                     */ DEADTRANS( L'_'	,0xEAD6	,0x2289	,0x0000), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><b><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEAD6	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><b><%slash><~space>                                          */ DEADTRANS( L' '	,0xEAD6	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><b><%tilde>                                                  */ DEADTRANS( L'~'	,0xEAAE	,0xEADB	,0x0001), // Multikey chain
/*<!M><B><%tilde>                                                  */ DEADTRANS( L'~'	,0xEAAF	,0x212C	,0x0000), // '~' ➔ "ℬ" SCRIPT CAPITAL B
/*<!M><b><%tilde><%tilde>                                          */ DEADTRANS( L'~'	,0xEADB	,0x2ACA	,0x0000), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><b><%tilde><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEADB	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><b><%tilde><~space>                                          */ DEADTRANS( L' '	,0xEADB	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><b><%underscore>                                             */ DEADTRANS( L'_'	,0xEAAE	,0xEADF	,0x0001), // Multikey chain
/*<!M><b><%underscore><%slash>                                     */ DEADTRANS( L'/'	,0xEADF	,0x228B	,0x0000), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><b><%underscore><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xEADF	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><b><%underscore><~space>                                     */ DEADTRANS( L' '	,0xEADF	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><b><a>                                                       */ DEADTRANS( L'a'	,0xEAAE	,0xEAE4	,0x0001), // Multikey chain
/*<!M><B><A>                                                       */ DEADTRANS( L'A'	,0xEAAF	,0x264E	,0x0000), // 'A' ➔ "♎" LIBRA emoji
/*<!M><b><a><l>                                                    */ DEADTRANS( L'l'	,0xEAE4	,0xEAE5	,0x0001), // Multikey chain
/*<!M><b><a><l><a>                                                 */ DEADTRANS( L'a'	,0xEAE5	,0x264E	,0x0000), // 'a' ➔ "♎" LIBRA emoji
/*<!M><b><b>                                                       */ DEADTRANS( L'b'	,0xEAAE	,0x2AD6	,0x0000), // 'b' ➔ "⫖" SUPERSET ABOVE SUPERSET
/*<!M><b><c>                                                       */ DEADTRANS( L'c'	,0xEAAE	,0x2AD4	,0x0000), // 'c' ➔ "⫔" SUPERSET ABOVE SUBSET
/*<!M><b><d>                                                       */ DEADTRANS( L'd'	,0xEAAE	,0xEAE9	,0x0001), // Multikey chain
/*<!M><B><D>                                                       */ DEADTRANS( L'D'	,0xEAAF	,0xEAEA	,0x0001), // Multikey chain
/*<!M><b><d><t>                                                    */ DEADTRANS( L't'	,0xEAE9	,0x09F3	,0x0000), // 't' ➔ "৳" BENGALI RUPEE SIGN, Taka BANGLADESH
/*<!M><B><D><T>                                                    */ DEADTRANS( L'T'	,0xEAEA	,0x09F3	,0x0000), // 'T' ➔ "৳" BENGALI RUPEE SIGN, Taka BANGLADESH
/*<!M><b><e>                                                       */ DEADTRANS( L'e'	,0xEAAE	,0xEAEE	,0x0001), // Multikey chain
/*<!M><B><E>                                                       */ DEADTRANS( L'E'	,0xEAAF	,0x2648	,0x0000), // 'E' ➔ "♈" ARIES emoji
/*<!M><b><e><l>                                                    */ DEADTRANS( L'l'	,0xEAEE	,0xEAEF	,0x0001), // Multikey chain
/*<!M><b><e><l><i>                                                 */ DEADTRANS( L'i'	,0xEAEF	,0x2648	,0x0000), // 'i' ➔ "♈" ARIES emoji
/*<!M><b><eacute>                                                  */ DEADTRANS( 0x00E9	,0xEAAE	,0xEAF2	,0x0001), // Multikey chain
/*<!M><B><Eacute>                                                  */ DEADTRANS( 0x00C9	,0xEAAF	,0x2648	,0x0000), // 'É' ➔ "♈" ARIES emoji
/*<!M><b><eacute><l>                                               */ DEADTRANS( L'l'	,0xEAF2	,0xEAF3	,0x0001), // Multikey chain
/*<!M><b><eacute><l><i>                                            */ DEADTRANS( L'i'	,0xEAF3	,0x2648	,0x0000), // 'i' ➔ "♈" ARIES emoji
/*<!M><b><g>                                                       */ DEADTRANS( L'g'	,0xEAAE	,0xEAF5	,0x0001), // Multikey chain
/*<!M><B><G>                                                       */ DEADTRANS( L'G'	,0xEAAF	,0xEAF6	,0x0001), // Multikey chain
/*<!M><b><h>                                                       */ DEADTRANS( L'h'	,0xEAAE	,0xEAF9	,0x0001), // Multikey chain
/*<!M><B><H>                                                       */ DEADTRANS( L'H'	,0xEAAF	,0xEAFA	,0x0001), // Multikey chain
/*<!M><b><i>                                                       */ DEADTRANS( L'i'	,0xEAAE	,0xEAFD	,0x0001), // Multikey chain
/*<!M><B><I>                                                       */ DEADTRANS( L'I'	,0xEAAF	,0xEAFE	,0x0001), // Multikey chain
/*<!M><B><I><L>                                                    */ DEADTRANS( L'L'	,0xEAFE	,0xDC48	,0x0000), // High surrogate: D83D; U+1F448 'L' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><b><i><p>                                                    */ DEADTRANS( L'p'	,0xEAFD	,0xEB00	,0x0001), // Multikey chain
/*<!M><b><i><p><l>                                                 */ DEADTRANS( L'l'	,0xEB00	,0xDC48	,0x0000), // High surrogate: D83D; U+1F448 'l' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><b><i><p><r>                                                 */ DEADTRANS( L'r'	,0xEB00	,0xDC49	,0x0000), // High surrogate: D83D; U+1F449 'r' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><B><I><R>                                                    */ DEADTRANS( L'R'	,0xEAFE	,0xDC49	,0x0000), // High surrogate: D83D; U+1F449 'R' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><b><k>                                                       */ DEADTRANS( L'k'	,0xEAAE	,0x27F5	,0x0000), // 'k' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><B><K>                                                       */ DEADTRANS( L'K'	,0xEAAF	,0x27F5	,0x0000), // 'K' ➔ "⟵" LONG LEFTWARDS ARROW
/*<!M><b><m>                                                       */ DEADTRANS( L'm'	,0xEAAE	,0x266D	,0x0000), // 'm' ➔ "♭" MUSIC FLAT SIGN
/*<!M><b><o>                                                       */ DEADTRANS( L'o'	,0xEAAE	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><b><x>                                                       */ DEADTRANS( L'x'	,0xEAAE	,0x2AC2	,0x0000), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><b><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEAAE	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><b><~space>                                                  */ DEADTRANS( L' '	,0xEAAE	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c>                                                          */ DEADTRANS( L'c'	,0x00A6	,0xEB0B	,0x0001), // Multikey chain
/*<!M><C>                                                          */ DEADTRANS( L'C'	,0x00A6	,0xEB0C	,0x0001), // Multikey chain
/*<!M><C><%asterisk>                                               */ DEADTRANS( L'*'	,0xEB0C	,0x2653	,0x0000), // '*' ➔ "♓" PISCES emoji
/*<!M><c><%asterisk>                                               */ DEADTRANS( L'*'	,0xEB0B	,0x2653	,0x0000), // '*' ➔ "♓" PISCES emoji
/*<!M><c><%backslash>                                              */ DEADTRANS( L'\\'	,0xEB0B	,0xEB0F	,0x0001), // Multikey chain
/*<!M><c><%backslash><%bracketleft>                                */ DEADTRANS( L'['	,0xEB0F	,0xEB10	,0x0001), // Multikey chain
/*<!M><c><%backslash><%bracketleft><%slash>                        */ DEADTRANS( L'/'	,0xEB10	,0x22E3	,0x0000), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketleft><%underscore>                   */ DEADTRANS( L'_'	,0xEB10	,0xEB12	,0x0001), // Multikey chain
/*<!M><c><%backslash><%bracketleft><%underscore><%slash>           */ DEADTRANS( L'/'	,0xEB12	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><%backslash><%bracketright>                               */ DEADTRANS( L']'	,0xEB0F	,0xEB14	,0x0001), // Multikey chain
/*<!M><c><%backslash><%bracketright><%slash>                       */ DEADTRANS( L'/'	,0xEB14	,0x22E3	,0x0000), // '/' ➔ "⋣" NOT SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore>                  */ DEADTRANS( L'_'	,0xEB14	,0xEB16	,0x0001), // Multikey chain
/*<!M><c><%backslash><%bracketright><%underscore><%slash>          */ DEADTRANS( L'/'	,0xEB16	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore><~nbspace>        */ DEADTRANS( 0x00A0	,0xEB16	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright><%underscore><~space>          */ DEADTRANS( L' '	,0xEB16	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><%backslash><%bracketright><~nbspace>                     */ DEADTRANS( 0x00A0	,0xEB14	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><%backslash><%bracketright><~space>                       */ DEADTRANS( L' '	,0xEB14	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><%backslash><%equal>                                      */ DEADTRANS( L'='	,0xEB0F	,0xEB1C	,0x0001), // Multikey chain
/*<!M><c><%backslash><%equal><%slash>                              */ DEADTRANS( L'/'	,0xEB1C	,0x2ACC	,0x0000), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><c><%backslash><%equal><~nbspace>                            */ DEADTRANS( 0x00A0	,0xEB1C	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><%backslash><%equal><~space>                              */ DEADTRANS( L' '	,0xEB1C	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><%backslash><%less>                                       */ DEADTRANS( L'<'	,0xEB0F	,0x297B	,0x0000), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><c><%backslash><%minus>                                      */ DEADTRANS( L'-'	,0xEB0F	,0x2B44	,0x0000), // '-' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><c><%backslash><%period>                                     */ DEADTRANS( L'.'	,0xEB0F	,0x2ABE	,0x0000), // '.' ➔ "⪾" SUPERSET WITH DOT
/*<!M><c><%backslash><%plus>                                       */ DEADTRANS( L'+'	,0xEB0F	,0x2AC0	,0x0000), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><c><%backslash><%slash>                                      */ DEADTRANS( L'/'	,0xEB0F	,0xEB24	,0x0001), // Multikey chain
/*<!M><c><%backslash><%slash><%underscore>                         */ DEADTRANS( L'_'	,0xEB24	,0x2289	,0x0000), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><c><%backslash><%slash><~nbspace>                            */ DEADTRANS( 0x00A0	,0xEB24	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><%backslash><%slash><~space>                              */ DEADTRANS( L' '	,0xEB24	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><%backslash><%tilde>                                      */ DEADTRANS( L'~'	,0xEB0F	,0xEB28	,0x0001), // Multikey chain
/*<!M><c><%backslash><%tilde><%tilde>                              */ DEADTRANS( L'~'	,0xEB28	,0x2ACA	,0x0000), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><%backslash><%tilde><~nbspace>                            */ DEADTRANS( 0x00A0	,0xEB28	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><%backslash><%tilde><~space>                              */ DEADTRANS( L' '	,0xEB28	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><%backslash><%underscore>                                 */ DEADTRANS( L'_'	,0xEB0F	,0xEB2C	,0x0001), // Multikey chain
/*<!M><c><%backslash><%underscore><%slash>                         */ DEADTRANS( L'/'	,0xEB2C	,0x228B	,0x0000), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><c><%backslash><%underscore><~nbspace>                       */ DEADTRANS( 0x00A0	,0xEB2C	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><%backslash><%underscore><~space>                         */ DEADTRANS( L' '	,0xEB2C	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><%backslash><o>                                           */ DEADTRANS( L'o'	,0xEB0F	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><c><%backslash><x>                                           */ DEADTRANS( L'x'	,0xEB0F	,0x2AC2	,0x0000), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><c><%backslash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xEB0F	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><%backslash><~space>                                      */ DEADTRANS( L' '	,0xEB0F	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><%bar>                                                    */ DEADTRANS( L'|'	,0xEB0B	,0xEB35	,0x0001), // Multikey chain
/*<!M><C><%bar>                                                    */ DEADTRANS( L'|'	,0xEB0C	,0x20B5	,0x0000), // '|' ➔ "₵" CEDI SIGN
/*<!M><c><%bar><%period>                                           */ DEADTRANS( L'.'	,0xEB35	,0xA717	,0x0000), // '.' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><c><%bar><%underscore>                                       */ DEADTRANS( L'_'	,0xEB35	,0x2AD1	,0x0000), // '_' ➔ "⫑" CLOSED SUBSET OR EQUAL TO
/*<!M><c><%bar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEB35	,0x2ACF	,0x0000), // ' ' ➔ "⫏" CLOSED SUBSET
/*<!M><c><%bar><~space>                                            */ DEADTRANS( L' '	,0xEB35	,0x2ACF	,0x0000), // ' ' ➔ "⫏" CLOSED SUBSET
/*<!M><c><%bracketleft>                                            */ DEADTRANS( L'['	,0xEB0B	,0xEB3A	,0x0001), // Multikey chain
/*<!M><c><%bracketleft><%slash>                                    */ DEADTRANS( L'/'	,0xEB3A	,0x22E2	,0x0000), // '/' ➔ "⋢" NOT SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft><%underscore>                               */ DEADTRANS( L'_'	,0xEB3A	,0xEB3C	,0x0001), // Multikey chain
/*<!M><c><%bracketleft><%underscore><%slash>                       */ DEADTRANS( L'/'	,0xEB3C	,0x22E4	,0x0000), // '/' ➔ "⋤" SQUARE IMAGE OF OR NOT EQUAL TO
/*<!M><c><%bracketleft><%underscore><~nbspace>                     */ DEADTRANS( 0x00A0	,0xEB3C	,0x2291	,0x0000), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft><%underscore><~space>                       */ DEADTRANS( L' '	,0xEB3C	,0x2291	,0x0000), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketleft><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xEB3A	,0x228F	,0x0000), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketleft><~space>                                    */ DEADTRANS( L' '	,0xEB3A	,0x228F	,0x0000), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketright>                                           */ DEADTRANS( L']'	,0xEB0B	,0xEB42	,0x0001), // Multikey chain
/*<!M><c><%bracketright><%slash>                                   */ DEADTRANS( L'/'	,0xEB42	,0x22E2	,0x0000), // '/' ➔ "⋢" NOT SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright><%underscore>                              */ DEADTRANS( L'_'	,0xEB42	,0xEB44	,0x0001), // Multikey chain
/*<!M><c><%bracketright><%underscore><%slash>                      */ DEADTRANS( L'/'	,0xEB44	,0x22E4	,0x0000), // '/' ➔ "⋤" SQUARE IMAGE OF OR NOT EQUAL TO
/*<!M><c><%bracketright><%underscore><~nbspace>                    */ DEADTRANS( 0x00A0	,0xEB44	,0x2291	,0x0000), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright><%underscore><~space>                      */ DEADTRANS( L' '	,0xEB44	,0x2291	,0x0000), // ' ' ➔ "⊑" SQUARE IMAGE OF OR EQUAL TO
/*<!M><c><%bracketright><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xEB42	,0x228F	,0x0000), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%bracketright><~space>                                   */ DEADTRANS( L' '	,0xEB42	,0x228F	,0x0000), // ' ' ➔ "⊏" SQUARE IMAGE OF
/*<!M><c><%equal>                                                  */ DEADTRANS( L'='	,0xEB0B	,0xEB4B	,0x0001), // Multikey chain
/*<!M><C><%equal>                                                  */ DEADTRANS( L'='	,0xEB0C	,0x20AC	,0x0000), // '=' ➔ "€" EURO SIGN
/*<!M><c><%equal><%slash>                                          */ DEADTRANS( L'/'	,0xEB4B	,0x2ACB	,0x0000), // '/' ➔ "⫋" SUBSET OF ABOVE NOT EQUAL TO
/*<!M><c><%equal><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEB4B	,0x2AC5	,0x0000), // ' ' ➔ "⫅" SUBSET OF ABOVE EQUALS SIGN
/*<!M><c><%equal><~space>                                          */ DEADTRANS( L' '	,0xEB4B	,0x2AC5	,0x0000), // ' ' ➔ "⫅" SUBSET OF ABOVE EQUALS SIGN
/*<!M><C><%greater>                                                */ DEADTRANS( L'>'	,0xEB0C	,0x293F	,0x0000), // '>' ➔ "⤿" LOWER LEFT SEMICIRCULAR ANTICLOCKWISE ARROW
/*<!M><C><%hash>                                                   */ DEADTRANS( L'#'	,0xEB0C	,0x212D	,0x0000), // '#' ➔ "ℭ" BLACK-LETTER CAPITAL C
/*<!M><C><%minus>                                                  */ DEADTRANS( L'-'	,0xEB0C	,0xEB51	,0x0001), // Multikey chain
/*<!M><c><%minus>                                                  */ DEADTRANS( L'-'	,0xEB0B	,0xEB52	,0x0001), // Multikey chain
/*<!M><C><%minus><%bar>                                            */ DEADTRANS( L'|'	,0xEB51	,0xA71A	,0x0000), // '|' ➔ "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><c><%minus><%bar>                                            */ DEADTRANS( L'|'	,0xEB52	,0xA71A	,0x0000), // '|' ➔ "ꜚ" MODIFIER LETTER LOWER RIGHT CORNER ANGLE
/*<!M><c><%minus><%greater>                                        */ DEADTRANS( L'>'	,0xEB52	,0x2979	,0x0000), // '>' ➔ "⥹" SUBSET ABOVE RIGHTWARDS ARROW
/*<!M><C><%minus><%period>                                         */ DEADTRANS( L'.'	,0xEB51	,0xA719	,0x0000), // '.' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%minus><%period>                                         */ DEADTRANS( L'.'	,0xEB52	,0xA719	,0x0000), // '.' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%percent>                                                */ DEADTRANS( L'%'	,0xEB0B	,0xEB58	,0x0001), // Multikey chain
/*<!M><c><%percent><e>                                             */ DEADTRANS( L'e'	,0xEB58	,0xAB62	,0x0000), // 'e' ➔ "ꭢ" LATIN SMALL LETTER OPEN OE
/*<!M><C><%period>                                                 */ DEADTRANS( L'.'	,0xEB0C	,0xEB5A	,0x0001), // Multikey chain
/*<!M><c><%period>                                                 */ DEADTRANS( L'.'	,0xEB0B	,0xEB5B	,0x0001), // Multikey chain
/*<!M><C><%period><%bar>                                           */ DEADTRANS( L'|'	,0xEB5A	,0xA717	,0x0000), // '|' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><c><%period><%bar>                                           */ DEADTRANS( L'|'	,0xEB5B	,0xA717	,0x0000), // '|' ➔ "ꜗ" MODIFIER LETTER DOT VERTICAL BAR
/*<!M><C><%period><%minus>                                         */ DEADTRANS( L'-'	,0xEB5A	,0xA719	,0x0000), // '-' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><c><%period><%minus>                                         */ DEADTRANS( L'-'	,0xEB5B	,0xA719	,0x0000), // '-' ➔ "ꜙ" MODIFIER LETTER DOT HORIZONTAL BAR
/*<!M><C><%period><%slash>                                         */ DEADTRANS( L'/'	,0xEB5A	,0xA718	,0x0000), // '/' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%period><%slash>                                         */ DEADTRANS( L'/'	,0xEB5B	,0xA718	,0x0000), // '/' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%period><~nbspace>                                       */ DEADTRANS( 0x00A0	,0xEB5B	,0x2ABD	,0x0000), // ' ' ➔ "⪽" SUBSET WITH DOT
/*<!M><c><%period><~space>                                         */ DEADTRANS( L' '	,0xEB5B	,0x2ABD	,0x0000), // ' ' ➔ "⪽" SUBSET WITH DOT
/*<!M><c><%plus>                                                   */ DEADTRANS( L'+'	,0xEB0B	,0x2ABF	,0x0000), // '+' ➔ "⪿" SUBSET WITH PLUS SIGN BELOW
/*<!M><c><%slash>                                                  */ DEADTRANS( L'/'	,0xEB0B	,0xEB66	,0x0001), // Multikey chain
/*<!M><C><%slash>                                                  */ DEADTRANS( L'/'	,0xEB0C	,0x20A1	,0x0000), // '/' ➔ "₡" COLON SIGN
/*<!M><c><%slash><%period>                                         */ DEADTRANS( L'.'	,0xEB66	,0xA718	,0x0000), // '.' ➔ "ꜘ" MODIFIER LETTER DOT SLASH
/*<!M><c><%slash><%underscore>                                     */ DEADTRANS( L'_'	,0xEB66	,0x2288	,0x0000), // '_' ➔ "⊈" NEITHER A SUBSET OF NOR EQUAL TO
/*<!M><c><%slash><o>                                               */ DEADTRANS( L'o'	,0xEB66	,0x2105	,0x0000), // 'o' ➔ "℅" CARE OF
/*<!M><c><%slash><u>                                               */ DEADTRANS( L'u'	,0xEB66	,0x2106	,0x0000), // 'u' ➔ "℆" CADA UNA
/*<!M><c><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEB66	,0x2284	,0x0000), // ' ' ➔ "⊄" NOT A SUBSET OF
/*<!M><c><%slash><~space>                                          */ DEADTRANS( L' '	,0xEB66	,0x2284	,0x0000), // ' ' ➔ "⊄" NOT A SUBSET OF
/*<!M><c><%tilde>                                                  */ DEADTRANS( L'~'	,0xEB0B	,0xEB6D	,0x0001), // Multikey chain
/*<!M><c><%tilde><%tilde>                                          */ DEADTRANS( L'~'	,0xEB6D	,0x2AC9	,0x0000), // '~' ➔ "⫉" SUBSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><%tilde><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEB6D	,0x2AC7	,0x0000), // ' ' ➔ "⫇" SUBSET OF ABOVE TILDE OPERATOR
/*<!M><c><%tilde><~space>                                          */ DEADTRANS( L' '	,0xEB6D	,0x2AC7	,0x0000), // ' ' ➔ "⫇" SUBSET OF ABOVE TILDE OPERATOR
/*<!M><c><%underscore>                                             */ DEADTRANS( L'_'	,0xEB0B	,0xEB71	,0x0001), // Multikey chain
/*<!M><c><%underscore><%slash>                                     */ DEADTRANS( L'/'	,0xEB71	,0x228A	,0x0000), // '/' ➔ "⊊" SUBSET OF WITH NOT EQUAL TO
/*<!M><c><%underscore><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xEB71	,0x2286	,0x0000), // ' ' ➔ "⊆" SUBSET OF OR EQUAL TO
/*<!M><c><%underscore><~space>                                     */ DEADTRANS( L' '	,0xEB71	,0x2286	,0x0000), // ' ' ➔ "⊆" SUBSET OF OR EQUAL TO
/*<!M><C><9>                                                       */ DEADTRANS( L'9'	,0xEB0C	,0xA76E	,0x0000), // '9' ➔ "Ꝯ" LATIN CAPITAL LETTER CON
/*<!M><c><9>                                                       */ DEADTRANS( L'9'	,0xEB0B	,0xA76F	,0x0000), // '9' ➔ "ꝯ" LATIN SMALL LETTER CON
/*<!M><c><a>                                                       */ DEADTRANS( L'a'	,0xEB0B	,0xEB77	,0x0001), // Multikey chain
/*<!M><C><A>                                                       */ DEADTRANS( L'A'	,0xEB0C	,0xEB78	,0x0001), // Multikey chain
/*<!M><C><a>                                                       */ DEADTRANS( L'a'	,0xEB0C	,0xEB79	,0x0001), // Multikey chain
/*<!M><c><a><n>                                                    */ DEADTRANS( L'n'	,0xEB77	,0x264B	,0x0000), // 'n' ➔ "♋" CANCER emoji
/*<!M><C><A><N>                                                    */ DEADTRANS( L'N'	,0xEB78	,0x264B	,0x0000), // 'N' ➔ "♋" CANCER emoji
/*<!M><c><a><p>                                                    */ DEADTRANS( L'p'	,0xEB77	,0xEB7D	,0x0001), // Multikey chain
/*<!M><C><A><P>                                                    */ DEADTRANS( L'P'	,0xEB78	,0xEB7E	,0x0001), // Multikey chain
/*<!M><C><a><p>                                                    */ DEADTRANS( L'p'	,0xEB79	,0x22D2	,0x0000), // 'p' ➔ "⋒" DOUBLE INTERSECTION
/*<!M><c><a><p><d>                                                 */ DEADTRANS( L'd'	,0xEB7D	,0xEB7F	,0x0001), // Multikey chain
/*<!M><c><a><p><d><o>                                              */ DEADTRANS( L'o'	,0xEB7F	,0xEB80	,0x0001), // Multikey chain
/*<!M><c><a><p><d><o><t>                                           */ DEADTRANS( L't'	,0xEB80	,0x2A40	,0x0000), // 't' ➔ "⩀" INTERSECTION WITH DOT
/*<!M><c><a><p><l>                                                 */ DEADTRANS( L'l'	,0xEB7D	,0x21EC	,0x0000), // 'l' ➔ "⇬" UPWARDS WHITE ARROW ON PEDESTAL WITH HORIZONTAL BAR, capitals lock
/*<!M><C><A><P><L>                                                 */ DEADTRANS( L'L'	,0xEB7E	,0x21EC	,0x0000), // 'L' ➔ "⇬" UPWARDS WHITE ARROW ON PEDESTAL WITH HORIZONTAL BAR, capitals lock
/*<!M><c><a><p><r>                                                 */ DEADTRANS( L'r'	,0xEB7D	,0x2651	,0x0000), // 'r' ➔ "♑" CAPRICORN emoji
/*<!M><C><A><P><R>                                                 */ DEADTRANS( L'R'	,0xEB7E	,0x2651	,0x0000), // 'R' ➔ "♑" CAPRICORN emoji
/*<!M><c><a><p><s>                                                 */ DEADTRANS( L's'	,0xEB7D	,0x21EA	,0x0000), // 's' ➔ "⇪" UPWARDS WHITE ARROW FROM BAR, capitals lock
/*<!M><C><A><P><S>                                                 */ DEADTRANS( L'S'	,0xEB7E	,0x2BB8	,0x0000), // 'S' ➔ "⇪" UPWARDS WHITE ARROW FROM BAR WITH HORIZONTAL BAR, capitals lock
/*<!M><c><a><p><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEB7D	,0x2229	,0x0000), // ' ' ➔ "∩" INTERSECTION
/*<!M><c><a><p><~space>                                            */ DEADTRANS( L' '	,0xEB7D	,0x2229	,0x0000), // ' ' ➔ "∩" INTERSECTION
/*<!M><c><b>                                                       */ DEADTRANS( L'b'	,0xEB0B	,0x2AD3	,0x0000), // 'b' ➔ "⫓" SUBSET ABOVE SUPERSET
/*<!M><c><c>                                                       */ DEADTRANS( L'c'	,0xEB0B	,0xEB8C	,0x0001), // Multikey chain
/*<!M><C><C>                                                       */ DEADTRANS( L'C'	,0xEB0C	,0x2102	,0x0000), // 'C' ➔ "ℂ" DOUBLE-STRUCK CAPITAL C
/*<!M><c><c><%bracketleft>                                         */ DEADTRANS( L'['	,0xEB8C	,0xEB8D	,0x0001), // Multikey chain
/*<!M><c><c><%bracketleft><%underscore>                            */ DEADTRANS( L'_'	,0xEB8D	,0xEB8E	,0x0001), // Multikey chain
/*<!M><c><c><%bracketleft><%underscore><%slash>                    */ DEADTRANS( L'/'	,0xEB8E	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><c><%bracketright>                                        */ DEADTRANS( L']'	,0xEB8C	,0xEB90	,0x0001), // Multikey chain
/*<!M><c><c><%bracketright><%underscore>                           */ DEADTRANS( L'_'	,0xEB90	,0xEB91	,0x0001), // Multikey chain
/*<!M><c><c><%bracketright><%underscore><%slash>                   */ DEADTRANS( L'/'	,0xEB91	,0x22E5	,0x0000), // '/' ➔ "⋥" SQUARE ORIGINAL OF OR NOT EQUAL TO
/*<!M><c><c><%bracketright><%underscore><~nbspace>                 */ DEADTRANS( 0x00A0	,0xEB91	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><c><%bracketright><%underscore><~space>                   */ DEADTRANS( L' '	,0xEB91	,0x2292	,0x0000), // ' ' ➔ "⊒" SQUARE ORIGINAL OF OR EQUAL TO
/*<!M><c><c><%bracketright><~nbspace>                              */ DEADTRANS( 0x00A0	,0xEB90	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><c><%bracketright><~space>                                */ DEADTRANS( L' '	,0xEB90	,0x2290	,0x0000), // ' ' ➔ "⊐" SQUARE ORIGINAL OF
/*<!M><c><c><%equal>                                               */ DEADTRANS( L'='	,0xEB8C	,0xEB97	,0x0001), // Multikey chain
/*<!M><c><c><%equal><%slash>                                       */ DEADTRANS( L'/'	,0xEB97	,0x2ACC	,0x0000), // '/' ➔ "⫌" SUPERSET OF ABOVE NOT EQUAL TO
/*<!M><c><c><%equal><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEB97	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><c><%equal><~space>                                       */ DEADTRANS( L' '	,0xEB97	,0x2AC6	,0x0000), // ' ' ➔ "⫆" SUPERSET OF ABOVE EQUALS SIGN
/*<!M><c><c><%less>                                                */ DEADTRANS( L'<'	,0xEB8C	,0x297B	,0x0000), // '<' ➔ "⥻" SUPERSET ABOVE LEFTWARDS ARROW
/*<!M><c><c><%minus>                                               */ DEADTRANS( L'-'	,0xEB8C	,0x2B44	,0x0000), // '-' ➔ "⭄" RIGHTWARDS ARROW THROUGH SUPERSET
/*<!M><c><c><%plus>                                                */ DEADTRANS( L'+'	,0xEB8C	,0x2AC0	,0x0000), // '+' ➔ "⫀" SUPERSET WITH PLUS SIGN BELOW
/*<!M><c><c><%slash>                                               */ DEADTRANS( L'/'	,0xEB8C	,0xEB9E	,0x0001), // Multikey chain
/*<!M><c><c><%slash><%underscore>                                  */ DEADTRANS( L'_'	,0xEB9E	,0x2289	,0x0000), // '_' ➔ "⊉" NEITHER A SUPERSET OF NOR EQUAL TO
/*<!M><c><c><%slash><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEB9E	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><c><%slash><~space>                                       */ DEADTRANS( L' '	,0xEB9E	,0x2285	,0x0000), // ' ' ➔ "⊅" NOT A SUPERSET OF
/*<!M><c><c><%tilde>                                               */ DEADTRANS( L'~'	,0xEB8C	,0xEBA2	,0x0001), // Multikey chain
/*<!M><c><c><%tilde><%tilde>                                       */ DEADTRANS( L'~'	,0xEBA2	,0x2ACA	,0x0000), // '~' ➔ "⫊" SUPERSET OF ABOVE ALMOST EQUAL TO
/*<!M><c><c><%tilde><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xEBA2	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><c><%tilde><~space>                                       */ DEADTRANS( L' '	,0xEBA2	,0x2AC8	,0x0000), // ' ' ➔ "⫈" SUPERSET OF ABOVE TILDE OPERATOR
/*<!M><c><c><%underscore>                                          */ DEADTRANS( L'_'	,0xEB8C	,0xEBA6	,0x0001), // Multikey chain
/*<!M><c><c><%underscore><%slash>                                  */ DEADTRANS( L'/'	,0xEBA6	,0x228B	,0x0000), // '/' ➔ "⊋" SUPERSET OF WITH NOT EQUAL TO
/*<!M><c><c><%underscore><~nbspace>                                */ DEADTRANS( 0x00A0	,0xEBA6	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><c><%underscore><~space>                                  */ DEADTRANS( L' '	,0xEBA6	,0x2287	,0x0000), // ' ' ➔ "⊇" SUPERSET OF OR EQUAL TO
/*<!M><c><c><o>                                                    */ DEADTRANS( L'o'	,0xEB8C	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><c><c><x>                                                    */ DEADTRANS( L'x'	,0xEB8C	,0x2AC2	,0x0000), // 'x' ➔ "⫂" SUPERSET WITH MULTIPLICATION SIGN BELOW
/*<!M><c><c><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEB8C	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><c><~space>                                               */ DEADTRANS( L' '	,0xEB8C	,0x2283	,0x0000), // ' ' ➔ "⊃" SUPERSET OF
/*<!M><c><e>                                                       */ DEADTRANS( L'e'	,0xEB0B	,0x20A0	,0x0000), // 'e' ➔ "₠" EURO-CURRENCY SIGN
/*<!M><C><E>                                                       */ DEADTRANS( L'E'	,0xEB0C	,0x20A0	,0x0000), // 'E' ➔ "₠" EURO-CURRENCY SIGN
/*<!M><C><L>                                                       */ DEADTRANS( L'L'	,0xEB0C	,0x2104	,0x0000), // 'L' ➔ "℄" CENTRE LINE SYMBOL
/*<!M><c><l>                                                       */ DEADTRANS( L'l'	,0xEB0B	,0xDD2F	,0x0000), // High surrogate: D83C; U+1F12F 'l' ➔ "🄯" COPYLEFT SYMBOL
/*<!M><c><m>                                                       */ DEADTRANS( L'm'	,0xEB0B	,0xEBB3	,0x0001), // Multikey chain
/*<!M><C><M>                                                       */ DEADTRANS( L'M'	,0xEB0C	,0x2384	,0x0000), // 'M' ➔ "⎄" COMPOSITION SYMBOL
/*<!M><c><m><p>                                                    */ DEADTRANS( L'p'	,0xEBB3	,0x2384	,0x0000), // 'p' ➔ "⎄" COMPOSITION SYMBOL
/*<!M><c><n>                                                       */ DEADTRANS( L'n'	,0xEB0B	,0xEBB5	,0x0001), // Multikey chain
/*<!M><C><N>                                                       */ DEADTRANS( L'N'	,0xEB0C	,0xEBB6	,0x0001), // Multikey chain
/*<!M><c><n><y>                                                    */ DEADTRANS( L'y'	,0xEBB5	,0x00A5	,0x0000), // 'y' ➔ "¥" YEN SIGN, Yuan Renminbi CHINA
/*<!M><C><N><Y>                                                    */ DEADTRANS( L'Y'	,0xEBB6	,0x00A5	,0x0000), // 'Y' ➔ "¥" YEN SIGN, Yuan Renminbi CHINA
/*<!M><c><o>                                                       */ DEADTRANS( L'o'	,0xEB0B	,0x2105	,0x0000), // 'o' ➔ "℅" CARE OF
/*<!M><c><O>                                                       */ DEADTRANS( L'O'	,0xEB0B	,0x2105	,0x0000), // 'O' ➔ "℅" CARE OF
/*<!M><C><O>                                                       */ DEADTRANS( L'O'	,0xEB0C	,0x2105	,0x0000), // 'O' ➔ "℅" CARE OF
/*<!M><C><o>                                                       */ DEADTRANS( L'o'	,0xEB0C	,0x2105	,0x0000), // 'o' ➔ "℅" CARE OF
/*<!M><C><P>                                                       */ DEADTRANS( L'P'	,0xEB0C	,0x2210	,0x0000), // 'P' ➔ "∐" N-ARY COPRODUCT
/*<!M><c><p>                                                       */ DEADTRANS( L'p'	,0xEB0B	,0x2A3F	,0x0000), // 'p' ➔ "⨿" AMALGAMATION OR COPRODUCT
/*<!M><c><q>                                                       */ DEADTRANS( L'q'	,0xEB0B	,0x220E	,0x0000), // 'q' ➔ "∎" END OF PROOF
/*<!M><C><Q>                                                       */ DEADTRANS( L'Q'	,0xEB0C	,0x220E	,0x0000), // 'Q' ➔ "∎" END OF PROOF
/*<!M><c><r>                                                       */ DEADTRANS( L'r'	,0xEB0B	,0xEBC2	,0x0001), // Multikey chain
/*<!M><C><R>                                                       */ DEADTRANS( L'R'	,0xEB0C	,0xEBC3	,0x0001), // Multikey chain
/*<!M><C><r>                                                       */ DEADTRANS( L'r'	,0xEB0C	,0x20A2	,0x0000), // 'r' ➔ "₢" CRUZEIRO SIGN
/*<!M><c><r><c>                                                    */ DEADTRANS( L'c'	,0xEBC2	,0x20A1	,0x0000), // 'c' ➔ "₡" COLON SIGN, Costa Rican Colon COSTA RICA
/*<!M><C><R><C>                                                    */ DEADTRANS( L'C'	,0xEBC3	,0x20A1	,0x0000), // 'C' ➔ "₡" COLON SIGN, Costa Rican Colon COSTA RICA
/*<!M><c><t>                                                       */ DEADTRANS( L't'	,0xEB0B	,0x2388	,0x0000), // 't' ➔ "⎈" HELM SYMBOL, Control key ISO symbol
/*<!M><C><T>                                                       */ DEADTRANS( L'T'	,0xEB0C	,0x2388	,0x0000), // 'T' ➔ "⎈" HELM SYMBOL, Control key ISO symbol
/*<!M><c><u>                                                       */ DEADTRANS( L'u'	,0xEB0B	,0xEBC8	,0x0001), // Multikey chain
/*<!M><C><U>                                                       */ DEADTRANS( L'U'	,0xEB0C	,0xEBC9	,0x0001), // Multikey chain
/*<!M><C><u>                                                       */ DEADTRANS( L'u'	,0xEB0C	,0xEBCA	,0x0001), // Multikey chain
/*<!M><c><u><p>                                                    */ DEADTRANS( L'p'	,0xEBC8	,0xEBCC	,0x0001), // Multikey chain
/*<!M><C><u><p>                                                    */ DEADTRANS( L'p'	,0xEBCA	,0x22D3	,0x0000), // 'p' ➔ "⋓" DOUBLE UNION
/*<!M><c><u><p><d>                                                 */ DEADTRANS( L'd'	,0xEBCC	,0xEBCD	,0x0001), // Multikey chain
/*<!M><c><u><p><d><o>                                              */ DEADTRANS( L'o'	,0xEBCD	,0xEBCE	,0x0001), // Multikey chain
/*<!M><c><u><p><d><o><t>                                           */ DEADTRANS( L't'	,0xEBCE	,0x228D	,0x0000), // 't' ➔ "⊍" MULTISET MULTIPLICATION
/*<!M><c><u><p><p>                                                 */ DEADTRANS( L'p'	,0xEBCC	,0xEBD0	,0x0001), // Multikey chain
/*<!M><c><u><p><p><l>                                              */ DEADTRANS( L'l'	,0xEBD0	,0xEBD1	,0x0001), // Multikey chain
/*<!M><c><u><p><p><l><u>                                           */ DEADTRANS( L'u'	,0xEBD1	,0xEBD2	,0x0001), // Multikey chain
/*<!M><c><u><p><p><l><u><s>                                        */ DEADTRANS( L's'	,0xEBD2	,0x228E	,0x0000), // 's' ➔ "⊎" MULTISET UNION
/*<!M><c><u><p><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEBCC	,0x222A	,0x0000), // ' ' ➔ "∪" UNION
/*<!M><c><u><p><~space>                                            */ DEADTRANS( L' '	,0xEBCC	,0x222A	,0x0000), // ' ' ➔ "∪" UNION
/*<!M><c><u><~space>                                               */ DEADTRANS( L' '	,0xEBC8	,0x2106	,0x0000), // ' ' ➔ "℆" CADA UNA
/*<!M><C><U><~space>                                               */ DEADTRANS( L' '	,0xEBC9	,0x2106	,0x0000), // ' ' ➔ "℆" CADA UNA
/*<!M><c><x>                                                       */ DEADTRANS( L'x'	,0xEB0B	,0x2AC1	,0x0000), // 'x' ➔ "⫁" SUBSET WITH MULTIPLICATION SIGN BELOW
/*<!M><c><z>                                                       */ DEADTRANS( L'z'	,0xEB0B	,0xEBD9	,0x0001), // Multikey chain
/*<!M><C><Z>                                                       */ DEADTRANS( L'Z'	,0xEB0C	,0xEBDA	,0x0001), // Multikey chain
/*<!M><C><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEB0C	,0x2201	,0x0000), // ' ' ➔ "∁" COMPLEMENT
/*<!M><c><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEB0B	,0x2282	,0x0000), // ' ' ➔ "⊂" SUBSET OF
/*<!M><C><~space>                                                  */ DEADTRANS( L' '	,0xEB0C	,0x2201	,0x0000), // ' ' ➔ "∁" COMPLEMENT
/*<!M><c><~space>                                                  */ DEADTRANS( L' '	,0xEB0B	,0x2282	,0x0000), // ' ' ➔ "⊂" SUBSET OF
/*<!M><d>                                                          */ DEADTRANS( L'd'	,0x00A6	,0xEBE1	,0x0001), // Multikey chain
/*<!M><D>                                                          */ DEADTRANS( L'D'	,0x00A6	,0xEBE2	,0x0001), // Multikey chain
/*<!M><D><%asterisk>                                               */ DEADTRANS( L'*'	,0xEBE2	,0x26CE	,0x0000), // '*' ➔ "⛎" OPHIUCHUS emoji
/*<!M><d><%asterisk>                                               */ DEADTRANS( L'*'	,0xEBE1	,0x26CE	,0x0000), // '*' ➔ "⛎" OPHIUCHUS emoji
/*<!M><d><%backslash>                                              */ DEADTRANS( L'\\'	,0xEBE1	,0x2138	,0x0000), // '\' ➔ "ℸ" DALET SYMBOL
/*<!M><D><%backslash>                                              */ DEADTRANS( L'\\'	,0xEBE2	,0x2138	,0x0000), // '\' ➔ "ℸ" DALET SYMBOL
/*<!M><d><%bar>                                                    */ DEADTRANS( L'|'	,0xEBE1	,0x202C	,0x0000), // '|' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><d><%equal>                                                  */ DEADTRANS( L'='	,0xEBE1	,0x20AB	,0x0000), // '=' ➔ "₫" DONG SIGN
/*<!M><D><%equal>                                                  */ DEADTRANS( L'='	,0xEBE2	,0x225C	,0x0000), // '=' ➔ "≜" DELTA EQUAL TO
/*<!M><D><%greater>                                                */ DEADTRANS( L'>'	,0xEBE2	,0xEBEA	,0x0001), // Multikey chain
/*<!M><d><%greater>                                                */ DEADTRANS( L'>'	,0xEBE1	,0xEBEB	,0x0001), // Multikey chain
/*<!M><D><%greater><Z>                                             */ DEADTRANS( L'Z'	,0xEBEA	,0x01C4	,0x0000), // 'Z' ➔ "Ǆ" LATIN CAPITAL LETTER DZ WITH CARON
/*<!M><D><%greater><z>                                             */ DEADTRANS( L'z'	,0xEBEA	,0x01C5	,0x0000), // 'z' ➔ "ǅ" LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
/*<!M><d><%greater><z>                                             */ DEADTRANS( L'z'	,0xEBEB	,0x01C6	,0x0000), // 'z' ➔ "ǆ" LATIN SMALL LETTER DZ WITH CARON
/*<!M><d><%hash>                                                   */ DEADTRANS( L'#'	,0xEBE1	,0x266F	,0x0000), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><D><%hash>                                                   */ DEADTRANS( L'#'	,0xEBE2	,0x266F	,0x0000), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><d><%less>                                                   */ DEADTRANS( L'<'	,0xEBE1	,0x202C	,0x0000), // '<' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><D><%percent>                                                */ DEADTRANS( L'%'	,0xEBE2	,0x2207	,0x0000), // '%' ➔ "∇" NABLA
/*<!M><D><%underscore>                                             */ DEADTRANS( L'_'	,0xEBE2	,0x2AD2	,0x0000), // '_' ➔ "⫒" CLOSED SUPERSET OR EQUAL TO
/*<!M><d><b>                                                       */ DEADTRANS( L'b'	,0xEBE1	,0x0238	,0x0000), // 'b' ➔ "ȸ" LATIN SMALL LETTER DB DIGRAPH
/*<!M><D><D>                                                       */ DEADTRANS( L'D'	,0xEBE2	,0x2145	,0x0000), // 'D' ➔ "ⅅ" DOUBLE-STRUCK ITALIC CAPITAL D
/*<!M><d><d>                                                       */ DEADTRANS( L'd'	,0xEBE1	,0x2146	,0x0000), // 'd' ➔ "ⅆ" DOUBLE-STRUCK ITALIC SMALL D
/*<!M><d><e>                                                       */ DEADTRANS( L'e'	,0xEBE1	,0xEBF7	,0x0001), // Multikey chain
/*<!M><D><E>                                                       */ DEADTRANS( L'E'	,0xEBE2	,0xEBF8	,0x0001), // Multikey chain
/*<!M><d><e><b>                                                    */ DEADTRANS( L'b'	,0xEBF7	,0x21F1	,0x0000), // 'b' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D><E><B>                                                    */ DEADTRANS( L'B'	,0xEBF8	,0x21F1	,0x0000), // 'B' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><d><e><f>                                                    */ DEADTRANS( L'f'	,0xEBF7	,0x225D	,0x0000), // 'f' ➔ "≝" EQUAL TO BY DEFINITION
/*<!M><d><e><l>                                                    */ DEADTRANS( L'l'	,0xEBF7	,0x2327	,0x0000), // 'l' ➔ "⌧" X IN A RECTANGLE BOX
/*<!M><D><E><L>                                                    */ DEADTRANS( L'L'	,0xEBF8	,0x2327	,0x0000), // 'L' ➔ "⌧" X IN A RECTANGLE BOX
/*<!M><d><e><z>                                                    */ DEADTRANS( L'z'	,0xEBF7	,0x02A4	,0x0000), // 'z' ➔ "ʤ" LATIN SMALL LETTER DEZH DIGRAPH
/*<!M><d><eacute>                                                  */ DEADTRANS( 0x00E9	,0xEBE1	,0xEBFF	,0x0001), // Multikey chain
/*<!M><D><Eacute>                                                  */ DEADTRANS( 0x00C9	,0xEBE2	,0xEC00	,0x0001), // Multikey chain
/*<!M><d><eacute><b>                                               */ DEADTRANS( L'b'	,0xEBFF	,0x21F1	,0x0000), // 'b' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D><Eacute><B>                                               */ DEADTRANS( L'B'	,0xEC00	,0x21F1	,0x0000), // 'B' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><D><H>                                                       */ DEADTRANS( L'H'	,0xEBE2	,0x00D0	,0x0000), // 'H' ➔ "Ð" LATIN CAPITAL LETTER ETH
/*<!M><D><h>                                                       */ DEADTRANS( L'h'	,0xEBE2	,0x00D0	,0x0000), // 'h' ➔ "Ð" LATIN CAPITAL LETTER ETH
/*<!M><d><h>                                                       */ DEADTRANS( L'h'	,0xEBE1	,0x00F0	,0x0000), // 'h' ➔ "ð" LATIN SMALL LETTER ETH
/*<!M><d><i>                                                       */ DEADTRANS( L'i'	,0xEBE1	,0xEC06	,0x0001), // Multikey chain
/*<!M><d><i><a>                                                    */ DEADTRANS( L'a'	,0xEC06	,0xEC07	,0x0001), // Multikey chain
/*<!M><d><i><a><m>                                                 */ DEADTRANS( L'm'	,0xEC07	,0xEC08	,0x0001), // Multikey chain
/*<!M><d><i><a><m><e>                                              */ DEADTRANS( L'e'	,0xEC08	,0xEC09	,0x0001), // Multikey chain
/*<!M><d><i><a><m><e><t>                                           */ DEADTRANS( L't'	,0xEC09	,0xEC0A	,0x0001), // Multikey chain
/*<!M><d><i><a><m><e><t><e>                                        */ DEADTRANS( L'e'	,0xEC0A	,0xEC0B	,0x0001), // Multikey chain
/*<!M><d><i><a><m><e><t><e><r>                                     */ DEADTRANS( L'r'	,0xEC0B	,0x2300	,0x0000), // 'r' ➔ "⌀" DIAMETER SIGN
/*<!M><d><i><a><m><e><t><r>                                        */ DEADTRANS( L'r'	,0xEC0A	,0xEC0D	,0x0001), // Multikey chain
/*<!M><d><i><a><m><e><t><r><e>                                     */ DEADTRANS( L'e'	,0xEC0D	,0x2300	,0x0000), // 'e' ➔ "⌀" DIAMETER SIGN simplified French
/*<!M><d><i><a><m><egrave>                                         */ DEADTRANS( 0x00E8	,0xEC08	,0xEC0F	,0x0001), // Multikey chain
/*<!M><d><i><a><m><egrave><t>                                      */ DEADTRANS( L't'	,0xEC0F	,0xEC10	,0x0001), // Multikey chain
/*<!M><d><i><a><m><egrave><t><r>                                   */ DEADTRANS( L'r'	,0xEC10	,0xEC11	,0x0001), // Multikey chain
/*<!M><d><i><a><m><egrave><t><r><e>                                */ DEADTRANS( L'e'	,0xEC11	,0x2300	,0x0000), // 'e' ➔ "⌀" DIAMETER SIGN French
/*<!M><d><m>                                                       */ DEADTRANS( L'm'	,0xEBE1	,0xDD6B	,0x0000), // High surrogate: D83C; U+1F16B 'm' ➔ "🅫" RAISED MD SIGN
/*<!M><D><M>                                                       */ DEADTRANS( L'M'	,0xEBE2	,0xDD6B	,0x0000), // High surrogate: D83C; U+1F16B 'M' ➔ "🅫" RAISED MD SIGN
/*<!M><D><r>                                                       */ DEADTRANS( L'r'	,0xEBE2	,0x20AF	,0x0000), // 'r' ➔ "₯" DRACHMA SIGN
/*<!M><D><t>                                                       */ DEADTRANS( L't'	,0xEBE2	,0x0398	,0x0000), // 't' ➔ "Θ" GREEK CAPITAL LETTER THETA for use in Rromani
/*<!M><D><T>                                                       */ DEADTRANS( L'T'	,0xEBE2	,0x0398	,0x0000), // 'T' ➔ "Θ" GREEK CAPITAL LETTER THETA for use in Rromani
/*<!M><d><t>                                                       */ DEADTRANS( L't'	,0xEBE1	,0x03B8	,0x0000), // 't' ➔ "θ" GREEK SMALL LETTER THETA for use in Rromani
/*<!M><d><u>                                                       */ DEADTRANS( L'u'	,0xEBE1	,0xA771	,0x0000), // 'u' ➔ "ꝱ" LATIN SMALL LETTER DUM
/*<!M><D><Z>                                                       */ DEADTRANS( L'Z'	,0xEBE2	,0xEC1B	,0x0001), // Multikey chain
/*<!M><d><z>                                                       */ DEADTRANS( L'z'	,0xEBE1	,0xEC1C	,0x0001), // Multikey chain
/*<!M><D><z>                                                       */ DEADTRANS( L'z'	,0xEBE2	,0x01F2	,0x0000), // 'z' ➔ "ǲ" LATIN CAPITAL LETTER D WITH SMALL LETTER Z
/*<!M><d><z><%period>                                              */ DEADTRANS( L'.'	,0xEC1C	,0x01F3	,0x0000), // '.' ➔ "ǳ" LATIN SMALL LETTER DZ
/*<!M><D><Z><~space>                                               */ DEADTRANS( L' '	,0xEC1B	,0x01F1	,0x0000), // ' ' ➔ "Ǳ" LATIN CAPITAL LETTER DZ
/*<!M><d><z><~space>                                               */ DEADTRANS( L' '	,0xEC1C	,0x02A3	,0x0000), // ' ' ➔ "ʣ" LATIN SMALL LETTER DZ DIGRAPH
/*<!M><d><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEBE1	,0x2202	,0x0000), // ' ' ➔ "∂" PARTIAL DIFFERENTIAL
/*<!M><D><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEBE2	,0x2206	,0x0000), // ' ' ➔ "∆" INCREMENT
/*<!M><d><~space>                                                  */ DEADTRANS( L' '	,0xEBE1	,0x2202	,0x0000), // ' ' ➔ "∂" PARTIAL DIFFERENTIAL
/*<!M><D><~space>                                                  */ DEADTRANS( L' '	,0xEBE2	,0x2206	,0x0000), // ' ' ➔ "∆" INCREMENT
/*<!M><degree>                                                     */ DEADTRANS( 0x00B0	,0x00A6	,0xEC26	,0x0001), // Multikey chain
/*<!M><degree><C>                                                  */ DEADTRANS( L'C'	,0xEC26	,0x2103	,0x0000), // 'C' ➔ "℃" DEGREE CELSIUS
/*<!M><degree><c>                                                  */ DEADTRANS( L'c'	,0xEC26	,0x2103	,0x0000), // 'c' ➔ "℃" DEGREE CELSIUS
/*<!M><degree><F>                                                  */ DEADTRANS( L'F'	,0xEC26	,0x2109	,0x0000), // 'F' ➔ "℉" DEGREE FAHRENHEIT
/*<!M><degree><f>                                                  */ DEADTRANS( L'f'	,0xEC26	,0x2109	,0x0000), // 'f' ➔ "℉" DEGREE FAHRENHEIT
/*<!M><division>                                                   */ DEADTRANS( 0x00F7	,0x00A6	,0xEC2B	,0x0001), // Multikey chain
/*<!M><division><multiply>                                         */ DEADTRANS( 0x00D7	,0xEC2B	,0x22C7	,0x0000), // '×' ➔ "⋇" DIVISION TIMES
/*<!M><E>                                                          */ DEADTRANS( L'E'	,0x00A6	,0xEC2D	,0x0001), // Multikey chain
/*<!M><e>                                                          */ DEADTRANS( L'e'	,0x00A6	,0xEC2E	,0x0001), // Multikey chain
/*<!M><e><%at>                                                     */ DEADTRANS( L'@'	,0xEC2E	,0x03F5	,0x0000), // '@' ➔ "ϵ" GREEK LUNATE EPSILON SYMBOL
/*<!M><E><%at>                                                     */ DEADTRANS( L'@'	,0xEC2D	,0x03F6	,0x0000), // '@' ➔ "϶" GREEK REVERSED LUNATE EPSILON SYMBOL
/*<!M><e><%backslash>                                              */ DEADTRANS( L'\\'	,0xEC2E	,0xEC31	,0x0001), // Multikey chain
/*<!M><e><%backslash><%at>                                         */ DEADTRANS( L'@'	,0xEC31	,0x03F6	,0x0000), // '@' ➔ "϶" GREEK REVERSED LUNATE EPSILON SYMBOL
/*<!M><e><%backslash><%bar>                                        */ DEADTRANS( L'|'	,0xEC31	,0xEC33	,0x0001), // Multikey chain
/*<!M><e><%backslash><%bar><%comma>                                */ DEADTRANS( L','	,0xEC33	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash><%bar><~nbspace>                              */ DEADTRANS( 0x00A0	,0xEC33	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash><%bar><~space>                                */ DEADTRANS( L' '	,0xEC33	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%backslash><%comma>                                      */ DEADTRANS( L','	,0xEC31	,0x220D	,0x0000), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><e><%backslash><%minus>                                      */ DEADTRANS( L'-'	,0xEC31	,0x22FA	,0x0000), // '-' ➔ "⋺" CONTAINS WITH LONG HORIZONTAL STROKE
/*<!M><e><%backslash><%slash>                                      */ DEADTRANS( L'/'	,0xEC31	,0x220C	,0x0000), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><e><%backslash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xEC31	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><e><%backslash><~space>                                      */ DEADTRANS( L' '	,0xEC31	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><e><%bar>                                                    */ DEADTRANS( L'|'	,0xEC2E	,0xEC3C	,0x0001), // Multikey chain
/*<!M><e><%bar><%comma>                                            */ DEADTRANS( L','	,0xEC3C	,0x22F4	,0x0000), // ',' ➔ "⋴" SMALL ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%bar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEC3C	,0x22F3	,0x0000), // ' ' ➔ "⋳" ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%bar><~space>                                            */ DEADTRANS( L' '	,0xEC3C	,0x22F3	,0x0000), // ' ' ➔ "⋳" ELEMENT OF WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><e><%bracketleft>                                            */ DEADTRANS( L'['	,0xEC2E	,0x22FF	,0x0000), // '[' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><e><%bracketright>                                           */ DEADTRANS( L']'	,0xEC2E	,0x22FF	,0x0000), // ']' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><e><%comma>                                                  */ DEADTRANS( L','	,0xEC2E	,0x220A	,0x0000), // ',' ➔ "∊" SMALL ELEMENT OF
/*<!M><E><%equal>                                                  */ DEADTRANS( L'='	,0xEC2D	,0x20AC	,0x0000), // '=' ➔ "€" EURO SIGN
/*<!M><e><%equal>                                                  */ DEADTRANS( L'='	,0xEC2E	,0x22F9	,0x0000), // '=' ➔ "⋹" ELEMENT OF WITH TWO HORIZONTAL STROKES
/*<!M><e><%greater>                                                */ DEADTRANS( L'>'	,0xEC2E	,0x202A	,0x0000), // '>' ➔ "‪" LEFT-TO-RIGHT EMBEDDING
/*<!M><e><%hash>                                                   */ DEADTRANS( L'#'	,0xEC2E	,0x266A	,0x0000), // '#' ➔ "♪" EIGHTH NOTE
/*<!M><E><%hash>                                                   */ DEADTRANS( L'#'	,0xEC2D	,0x266B	,0x0000), // '#' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><e><%less>                                                   */ DEADTRANS( L'<'	,0xEC2E	,0x202B	,0x0000), // '<' ➔ "‫" RIGHT-TO-LEFT EMBEDDING
/*<!M><e><%minus>                                                  */ DEADTRANS( L'-'	,0xEC2E	,0x22F2	,0x0000), // '-' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><e><%percent>                                                */ DEADTRANS( L'%'	,0xEC2E	,0xEC4B	,0x0001), // Multikey chain
/*<!M><E><%percent>                                                */ DEADTRANS( L'%'	,0xEC2D	,0x2108	,0x0000), // '%' ➔ "℈" SCRUPLE
/*<!M><e><%percent><%percent>                                      */ DEADTRANS( L'%'	,0xEC4B	,0x2AD9	,0x0000), // '%' ➔ "⫙" ELEMENT OF OPENING DOWNWARDS
/*<!M><e><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xEC4B	,0x27D2	,0x0000), // ' ' ➔ "⟒" ELEMENT OF OPENING UPWARDS
/*<!M><e><%percent><~space>                                        */ DEADTRANS( L' '	,0xEC4B	,0x27D2	,0x0000), // ' ' ➔ "⟒" ELEMENT OF OPENING UPWARDS
/*<!M><E><%slash>                                                  */ DEADTRANS( L'/'	,0xEC2D	,0x2204	,0x0000), // '/' ➔ "∄" THERE DOES NOT EXIST
/*<!M><e><%slash>                                                  */ DEADTRANS( L'/'	,0xEC2E	,0x2209	,0x0000), // '/' ➔ "∉" NOT AN ELEMENT OF
/*<!M><e><%tilde>                                                  */ DEADTRANS( L'~'	,0xEC2E	,0x212F	,0x0000), // '~' ➔ "ℯ" SCRIPT SMALL E
/*<!M><E><%tilde>                                                  */ DEADTRANS( L'~'	,0xEC2D	,0x2130	,0x0000), // '~' ➔ "ℰ" SCRIPT CAPITAL E
/*<!M><e><%underscore>                                             */ DEADTRANS( L'_'	,0xEC2E	,0x22F8	,0x0000), // '_' ➔ "⋸" ELEMENT OF WITH UNDERBAR
/*<!M><e><a>                                                       */ DEADTRANS( L'a'	,0xEC2E	,0x2606	,0x0000), // 'a' ➔ "☆" WHITE STAR
/*<!M><E><A>                                                       */ DEADTRANS( L'A'	,0xEC2D	,0x2606	,0x0000), // 'A' ➔ "☆" WHITE STAR
/*<!M><e><e>                                                       */ DEADTRANS( L'e'	,0xEC2E	,0x2147	,0x0000), // 'e' ➔ "ⅇ" DOUBLE-STRUCK ITALIC SMALL E
/*<!M><e><m>                                                       */ DEADTRANS( L'm'	,0xEC2E	,0xEC57	,0x0001), // Multikey chain
/*<!M><E><M>                                                       */ DEADTRANS( L'M'	,0xEC2D	,0xEC58	,0x0001), // Multikey chain
/*<!M><e><m><f>                                                    */ DEADTRANS( L'f'	,0xEC57	,0xEC59	,0x0001), // Multikey chain
/*<!M><E><M><F>                                                    */ DEADTRANS( L'F'	,0xEC58	,0xEC5A	,0x0001), // Multikey chain
/*<!M><e><m><f><c>                                                 */ DEADTRANS( L'c'	,0xEC59	,0x25CF	,0x0000), // 'c' ➔ "●" BLACK CIRCLE
/*<!M><E><M><F><C>                                                 */ DEADTRANS( L'C'	,0xEC5A	,0x25CF	,0x0000), // 'C' ➔ "●" BLACK CIRCLE
/*<!M><e><m><f><r>                                                 */ DEADTRANS( L'r'	,0xEC59	,0x25AC	,0x0000), // 'r' ➔ "▬" BLACK RECTANGLE
/*<!M><E><M><F><R>                                                 */ DEADTRANS( L'R'	,0xEC5A	,0x25AC	,0x0000), // 'R' ➔ "▬" BLACK RECTANGLE
/*<!M><e><m><o>                                                    */ DEADTRANS( L'o'	,0xEC57	,0xEC5F	,0x0001), // Multikey chain
/*<!M><E><M><O>                                                    */ DEADTRANS( L'O'	,0xEC58	,0xEC60	,0x0001), // Multikey chain
/*<!M><e><m><o><r>                                                 */ DEADTRANS( L'r'	,0xEC5F	,0x25AD	,0x0000), // 'r' ➔ "▭" WHITE RECTANGLE
/*<!M><E><M><O><R>                                                 */ DEADTRANS( L'R'	,0xEC60	,0x25AD	,0x0000), // 'R' ➔ "▭" WHITE RECTANGLE
/*<!M><e><m><p>                                                    */ DEADTRANS( L'p'	,0xEC57	,0x2205	,0x0000), // 'p' ➔ "∅" EMPTY SET
/*<!M><e><n>                                                       */ DEADTRANS( L'n'	,0xEC2E	,0xEC64	,0x0001), // Multikey chain
/*<!M><E><N>                                                       */ DEADTRANS( L'N'	,0xEC2D	,0xEC65	,0x0001), // Multikey chain
/*<!M><E><n>                                                       */ DEADTRANS( L'n'	,0xEC2D	,0xEC66	,0x0001), // Multikey chain
/*<!M><e><n><d>                                                    */ DEADTRANS( L'd'	,0xEC64	,0x21F2	,0x0000), // 'd' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><E><N><D>                                                    */ DEADTRANS( L'D'	,0xEC65	,0x21F2	,0x0000), // 'D' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><e><n><f>                                                    */ DEADTRANS( L'f'	,0xEC64	,0xEC69	,0x0001), // Multikey chain
/*<!M><E><N><F>                                                    */ DEADTRANS( L'F'	,0xEC65	,0xEC6A	,0x0001), // Multikey chain
/*<!M><e><n><f><c>                                                 */ DEADTRANS( L'c'	,0xEC69	,0x2022	,0x0000), // 'c' ➔ "•" BULLET
/*<!M><E><N><F><C>                                                 */ DEADTRANS( L'C'	,0xEC6A	,0x2022	,0x0000), // 'C' ➔ "•" BULLET
/*<!M><e><n><f><r>                                                 */ DEADTRANS( L'r'	,0xEC69	,0x25AE	,0x0000), // 'r' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><E><N><F><R>                                                 */ DEADTRANS( L'R'	,0xEC6A	,0x25AE	,0x0000), // 'R' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><e><n><f><s>                                                 */ DEADTRANS( L's'	,0xEC69	,0x25AA	,0x0000), // 's' ➔ "▪" BLACK SMALL SQUARE
/*<!M><E><N><F><S>                                                 */ DEADTRANS( L'S'	,0xEC6A	,0x25AA	,0x0000), // 'S' ➔ "▪" BLACK SMALL SQUARE
/*<!M><e><n><o>                                                    */ DEADTRANS( L'o'	,0xEC64	,0xEC71	,0x0001), // Multikey chain
/*<!M><E><N><O>                                                    */ DEADTRANS( L'O'	,0xEC65	,0xEC72	,0x0001), // Multikey chain
/*<!M><e><n><o><c>                                                 */ DEADTRANS( L'c'	,0xEC71	,0x25E6	,0x0000), // 'c' ➔ "◦" WHITE BULLET
/*<!M><E><N><O><C>                                                 */ DEADTRANS( L'C'	,0xEC72	,0x25E6	,0x0000), // 'C' ➔ "◦" WHITE BULLET
/*<!M><e><n><o><s>                                                 */ DEADTRANS( L's'	,0xEC71	,0x25AB	,0x0000), // 's' ➔ "▫" WHITE SMALL SQUARE
/*<!M><E><N><O><S>                                                 */ DEADTRANS( L'S'	,0xEC72	,0x25AB	,0x0000), // 'S' ➔ "▫" WHITE SMALL SQUARE
/*<!M><e><n><s>                                                    */ DEADTRANS( L's'	,0xEC64	,0x2205	,0x0000), // 's' ➔ "∅" EMPTY SET French shortened name
/*<!M><e><n><t>                                                    */ DEADTRANS( L't'	,0xEC64	,0x2324	,0x0000), // 't' ➔ "⌤" UP ARROWHEAD BETWEEN TWO HORIZONTAL BARS
/*<!M><E><N><T>                                                    */ DEADTRANS( L'T'	,0xEC65	,0x2386	,0x0000), // 'T' ➔ "⎆" ENTER SYMBOL
/*<!M><e><n><u>                                                    */ DEADTRANS( L'u'	,0xEC64	,0xEC7A	,0x0001), // Multikey chain
/*<!M><E><n><v>                                                    */ DEADTRANS( L'v'	,0xEC66	,0xEC7D	,0x0001), // Multikey chain
/*<!M><e><n><v>                                                    */ DEADTRANS( L'v'	,0xEC64	,0x2709	,0x0000), // 'v' ➔ "✉" ENVELOPE
/*<!M><E><n><v><e>                                                 */ DEADTRANS( L'e'	,0xEC7D	,0xEC7E	,0x0001), // Multikey chain
/*<!M><E><n><v><e><l>                                              */ DEADTRANS( L'l'	,0xEC7E	,0xEC7F	,0x0001), // Multikey chain
/*<!M><E><n><v><e><l><o>                                           */ DEADTRANS( L'o'	,0xEC7F	,0xEC80	,0x0001), // Multikey chain
/*<!M><E><n><v><e><l><o><p>                                        */ DEADTRANS( L'p'	,0xEC80	,0xEC81	,0x0001), // Multikey chain
/*<!M><E><n><v><e><l><o><p><e>                                     */ DEADTRANS( L'e'	,0xEC81	,0x2709	,0x0000), // 'e' ➔ "✉" ENVELOPE TeX control has title case
/*<!M><e><o>                                                       */ DEADTRANS( L'o'	,0xEC2E	,0x220E	,0x0000), // 'o' ➔ "∎" END OF PROOF
/*<!M><E><O>                                                       */ DEADTRANS( L'O'	,0xEC2D	,0x220E	,0x0000), // 'O' ➔ "∎" END OF PROOF
/*<!M><e><s>                                                       */ DEADTRANS( L's'	,0xEC2E	,0xEC85	,0x0001), // Multikey chain
/*<!M><E><S>                                                       */ DEADTRANS( L'S'	,0xEC2D	,0xEC86	,0x0001), // Multikey chain
/*<!M><e><s><c>                                                    */ DEADTRANS( L'c'	,0xEC85	,0x238B	,0x0000), // 'c' ➔ "⎋" BROKEN CIRCLE WITH NORTHWEST ARROW
/*<!M><E><S><C>                                                    */ DEADTRANS( L'C'	,0xEC86	,0x238B	,0x0000), // 'C' ➔ "⎋" BROKEN CIRCLE WITH NORTHWEST ARROW
/*<!M><e><s><t>                                                    */ DEADTRANS( L't'	,0xEC85	,0x212E	,0x0000), // 't' ➔ "℮" ESTIMATED SYMBOL
/*<!M><E><S><T>                                                    */ DEADTRANS( L'T'	,0xEC86	,0x212E	,0x0000), // 'T' ➔ "℮" ESTIMATED SYMBOL
/*<!M><e><t>                                                       */ DEADTRANS( L't'	,0xEC2E	,0xA76B	,0x0000), // 't' ➔ "ꝫ" LATIN SMALL LETTER ET
/*<!M><e><u>                                                       */ DEADTRANS( L'u'	,0xEC2E	,0xEC8C	,0x0001), // Multikey chain
/*<!M><E><U>                                                       */ DEADTRANS( L'U'	,0xEC2D	,0xEC8D	,0x0001), // Multikey chain
/*<!M><E><u>                                                       */ DEADTRANS( L'u'	,0xEC2D	,0xEC8E	,0x0001), // Multikey chain
/*<!M><E><U><L>                                                    */ DEADTRANS( L'L'	,0xEC8D	,0x2107	,0x0000), // 'L' ➔ "ℇ" EULER CONSTANT
/*<!M><E><u><l>                                                    */ DEADTRANS( L'l'	,0xEC8E	,0x2107	,0x0000), // 'l' ➔ "ℇ" EULER CONSTANT
/*<!M><e><u><l>                                                    */ DEADTRANS( L'l'	,0xEC8C	,0x2107	,0x0000), // 'l' ➔ "ℇ" EULER CONSTANT
/*<!M><e><u><r>                                                    */ DEADTRANS( L'r'	,0xEC8C	,0x20AC	,0x0000), // 'r' ➔ "€" EURO SIGN, Euro EUROPEAN UNION
/*<!M><E><U><R>                                                    */ DEADTRANS( L'R'	,0xEC8D	,0x20AC	,0x0000), // 'R' ➔ "€" EURO SIGN, Euro EUROPEAN UNION
/*<!M><E><Z>                                                       */ DEADTRANS( L'Z'	,0xEC2D	,0x01B7	,0x0000), // 'Z' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><E><z>                                                       */ DEADTRANS( L'z'	,0xEC2D	,0x01B7	,0x0000), // 'z' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><e><z>                                                       */ DEADTRANS( L'z'	,0xEC2E	,0x0292	,0x0000), // 'z' ➔ "ʒ" LATIN SMALL LETTER EZH
/*<!M><E><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEC2D	,0x2203	,0x0000), // ' ' ➔ "∃" THERE EXISTS
/*<!M><e><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEC2E	,0x2208	,0x0000), // ' ' ➔ "∈" ELEMENT OF
/*<!M><E><~space>                                                  */ DEADTRANS( L' '	,0xEC2D	,0x2203	,0x0000), // ' ' ➔ "∃" THERE EXISTS
/*<!M><e><~space>                                                  */ DEADTRANS( L' '	,0xEC2E	,0x2208	,0x0000), // ' ' ➔ "∈" ELEMENT OF
/*<!M><eacute>                                                     */ DEADTRANS( 0x00E9	,0x00A6	,0xEC9B	,0x0001), // Multikey chain
/*<!M><Eacute>                                                     */ DEADTRANS( 0x00C9	,0x00A6	,0xEC9C	,0x0001), // Multikey chain
/*<!M><eacute><a>                                                  */ DEADTRANS( L'a'	,0xEC9B	,0x2606	,0x0000), // 'a' ➔ "☆" WHITE STAR
/*<!M><Eacute><a>                                                  */ DEADTRANS( L'a'	,0xEC9C	,0x2606	,0x0000), // 'a' ➔ "☆" WHITE STAR
/*<!M><f>                                                          */ DEADTRANS( L'f'	,0x00A6	,0xEC9F	,0x0001), // Multikey chain
/*<!M><F>                                                          */ DEADTRANS( L'F'	,0x00A6	,0xECA0	,0x0001), // Multikey chain
/*<!M><f><%at>                                                     */ DEADTRANS( L'@'	,0xEC9F	,0x03D5	,0x0000), // '@' ➔ "ϕ" GREEK PHI SYMBOL
/*<!M><f><%greater>                                                */ DEADTRANS( L'>'	,0xEC9F	,0x202D	,0x0000), // '>' ➔ "‭" LEFT-TO-RIGHT OVERRIDE
/*<!M><f><%hash>                                                   */ DEADTRANS( L'#'	,0xEC9F	,0x266D	,0x0000), // '#' ➔ "♭" MUSIC FLAT SIGN
/*<!M><f><%less>                                                   */ DEADTRANS( L'<'	,0xEC9F	,0x202E	,0x0000), // '<' ➔ "‮" RIGHT-TO-LEFT OVERRIDE
/*<!M><f><%slash>                                                  */ DEADTRANS( L'/'	,0xEC9F	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><F><%slash>                                                  */ DEADTRANS( L'/'	,0xECA0	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><F><%tilde>                                                  */ DEADTRANS( L'~'	,0xECA0	,0x2131	,0x0000), // '~' ➔ "ℱ" SCRIPT CAPITAL F
/*<!M><f><a>                                                       */ DEADTRANS( L'a'	,0xEC9F	,0x213B	,0x0000), // 'a' ➔ "℻" FACSIMILE SIGN
/*<!M><F><a>                                                       */ DEADTRANS( L'a'	,0xECA0	,0x213B	,0x0000), // 'a' ➔ "℻" FACSIMILE SIGN
/*<!M><F><A>                                                       */ DEADTRANS( L'A'	,0xECA0	,0x213B	,0x0000), // 'A' ➔ "℻" FACSIMILE SIGN
/*<!M><f><e>                                                       */ DEADTRANS( L'e'	,0xEC9F	,0xECAB	,0x0001), // Multikey chain
/*<!M><f><e><n>                                                    */ DEADTRANS( L'n'	,0xECAB	,0xECAC	,0x0001), // Multikey chain
/*<!M><f><e><n><g>                                                 */ DEADTRANS( L'g'	,0xECAC	,0x02A9	,0x0000), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><F><F>                                                       */ DEADTRANS( L'F'	,0xECA0	,0x20A3	,0x0000), // 'F' ➔ "₣" FRENCH FRANC SIGN
/*<!M><F><f>                                                       */ DEADTRANS( L'f'	,0xECA0	,0x20A3	,0x0000), // 'f' ➔ "₣" FRENCH FRANC SIGN
/*<!M><f><f>                                                       */ DEADTRANS( L'f'	,0xEC9F	,0x20A3	,0x0000), // 'f' ➔ "₣" FRENCH FRANC SIGN
/*<!M><f><g>                                                       */ DEADTRANS( L'g'	,0xEC9F	,0x02A9	,0x0000), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><f><i>                                                       */ DEADTRANS( L'i'	,0xEC9F	,0x21F2	,0x0000), // 'i' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><F><I>                                                       */ DEADTRANS( L'I'	,0xECA0	,0x21F2	,0x0000), // 'I' ➔ "⇲" SOUTH EAST ARROW TO CORNER
/*<!M><f><l>                                                       */ DEADTRANS( L'l'	,0xEC9F	,0xECB4	,0x0001), // Multikey chain
/*<!M><F><L>                                                       */ DEADTRANS( L'L'	,0xECA0	,0xECB5	,0x0001), // Multikey chain
/*<!M><f><l><i>                                                    */ DEADTRANS( L'i'	,0xECB4	,0x261A	,0x0000), // 'i' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><F><L><I>                                                    */ DEADTRANS( L'I'	,0xECB5	,0x261A	,0x0000), // 'I' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><f><l><p>                                                    */ DEADTRANS( L'p'	,0xECB4	,0x204C	,0x0000), // 'p' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><F><L><P>                                                    */ DEADTRANS( L'P'	,0xECB5	,0x204C	,0x0000), // 'P' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><f><l><t>                                                    */ DEADTRANS( L't'	,0xECB4	,0x25C2	,0x0000), // 't' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><F><L><T>                                                    */ DEADTRANS( L'T'	,0xECB5	,0x25C2	,0x0000), // 'T' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><f><n>                                                       */ DEADTRANS( L'n'	,0xEC9F	,0xECBC	,0x0001), // Multikey chain
/*<!M><f><n><g>                                                    */ DEADTRANS( L'g'	,0xECBC	,0x02A9	,0x0000), // 'g' ➔ "ʩ" LATIN SMALL LETTER FENG DIGRAPH
/*<!M><f><r>                                                       */ DEADTRANS( L'r'	,0xEC9F	,0xECBE	,0x0001), // Multikey chain
/*<!M><F><R>                                                       */ DEADTRANS( L'R'	,0xECA0	,0xECBF	,0x0001), // Multikey chain
/*<!M><f><r><b>                                                    */ DEADTRANS( L'b'	,0xECBE	,0x220E	,0x0000), // 'b' ➔ "∎" END OF PROOF
/*<!M><F><R><B>                                                    */ DEADTRANS( L'B'	,0xECBF	,0x220E	,0x0000), // 'B' ➔ "∎" END OF PROOF
/*<!M><f><r><i>                                                    */ DEADTRANS( L'i'	,0xECBE	,0x261B	,0x0000), // 'i' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><F><R><I>                                                    */ DEADTRANS( L'I'	,0xECBF	,0x261B	,0x0000), // 'I' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><f><r><p>                                                    */ DEADTRANS( L'p'	,0xECBE	,0x204D	,0x0000), // 'p' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><F><R><P>                                                    */ DEADTRANS( L'P'	,0xECBF	,0x204D	,0x0000), // 'P' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><f><r><t>                                                    */ DEADTRANS( L't'	,0xECBE	,0x2023	,0x0000), // 't' ➔ "‣" TRIANGULAR BULLET
/*<!M><F><R><T>                                                    */ DEADTRANS( L'T'	,0xECBF	,0x2023	,0x0000), // 'T' ➔ "‣" TRIANGULAR BULLET
/*<!M><f><s>                                                       */ DEADTRANS( L's'	,0xEC9F	,0x017F	,0x0000), // 's' ➔ "ſ" LATIN SMALL LETTER LONG S
/*<!M><f><t>                                                       */ DEADTRANS( L't'	,0xEC9F	,0xECC9	,0x0001), // Multikey chain
/*<!M><F><T>                                                       */ DEADTRANS( L'T'	,0xECA0	,0xECCA	,0x0001), // Multikey chain
/*<!M><f><t><d>                                                    */ DEADTRANS( L'd'	,0xECC9	,0x25BE	,0x0000), // 'd' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><F><T><D>                                                    */ DEADTRANS( L'D'	,0xECCA	,0x25BE	,0x0000), // 'D' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><f><t><u>                                                    */ DEADTRANS( L'u'	,0xECC9	,0x25B4	,0x0000), // 'u' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><F><T><U>                                                    */ DEADTRANS( L'U'	,0xECCA	,0x25B4	,0x0000), // 'U' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><g>                                                          */ DEADTRANS( L'g'	,0x00A6	,0xECCF	,0x0001), // Multikey chain
/*<!M><G>                                                          */ DEADTRANS( L'G'	,0x00A6	,0xECD0	,0x0001), // Multikey chain
/*<!M><g><%backslash>                                              */ DEADTRANS( L'\\'	,0xECCF	,0x2137	,0x0000), // '\' ➔ "ℷ" GIMEL SYMBOL
/*<!M><G><%backslash>                                              */ DEADTRANS( L'\\'	,0xECD0	,0x2137	,0x0000), // '\' ➔ "ℷ" GIMEL SYMBOL
/*<!M><g><%bar>                                                    */ DEADTRANS( L'|'	,0xECCF	,0x20B2	,0x0000), // '|' ➔ "₲" GUARANI SIGN
/*<!M><G><%bar>                                                    */ DEADTRANS( L'|'	,0xECD0	,0x20B2	,0x0000), // '|' ➔ "₲" GUARANI SIGN
/*<!M><G><%percent>                                                */ DEADTRANS( L'%'	,0xECD0	,0x2141	,0x0000), // '%' ➔ "⅁" TURNED SANS-SERIF CAPITAL G
/*<!M><G><%slash>                                                  */ DEADTRANS( L'/'	,0xECD0	,0x20B2	,0x0000), // '/' ➔ "₲" GUARANI SIGN
/*<!M><g><%tilde>                                                  */ DEADTRANS( L'~'	,0xECCF	,0x210A	,0x0000), // '~' ➔ "ℊ" SCRIPT SMALL G
/*<!M><g><e>                                                       */ DEADTRANS( L'e'	,0xECCF	,0xECD8	,0x0001), // Multikey chain
/*<!M><G><E>                                                       */ DEADTRANS( L'E'	,0xECD0	,0xECD9	,0x0001), // Multikey chain
/*<!M><g><e><l>                                                    */ DEADTRANS( L'l'	,0xECD8	,0x20BE	,0x0000), // 'l' ➔ "₾" LARI SIGN, Lari GEORGIA
/*<!M><G><E><L>                                                    */ DEADTRANS( L'L'	,0xECD9	,0x20BE	,0x0000), // 'L' ➔ "₾" LARI SIGN, Lari GEORGIA
/*<!M><g><e><m>                                                    */ DEADTRANS( L'm'	,0xECD8	,0xECDC	,0x0001), // Multikey chain
/*<!M><G><E><M>                                                    */ DEADTRANS( L'M'	,0xECD9	,0xECDD	,0x0001), // Multikey chain
/*<!M><g><e><m><e>                                                 */ DEADTRANS( L'e'	,0xECDC	,0x264A	,0x0000), // 'e' ➔ "♊" GEMINI emoji
/*<!M><G><E><M><E>                                                 */ DEADTRANS( L'E'	,0xECDD	,0x264A	,0x0000), // 'E' ➔ "♊" GEMINI emoji
/*<!M><g><e><m><i>                                                 */ DEADTRANS( L'i'	,0xECDC	,0x264A	,0x0000), // 'i' ➔ "♊" GEMINI emoji
/*<!M><G><E><M><I>                                                 */ DEADTRANS( L'I'	,0xECDD	,0x264A	,0x0000), // 'I' ➔ "♊" GEMINI emoji
/*<!M><g><e><n>                                                    */ DEADTRANS( L'n'	,0xECD8	,0x267A	,0x0000), // 'n' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><G><E><N>                                                    */ DEADTRANS( L'N'	,0xECD9	,0x267A	,0x0000), // 'N' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><g><eacute>                                                  */ DEADTRANS( 0x00E9	,0xECCF	,0xECE4	,0x0001), // Multikey chain
/*<!M><G><Eacute>                                                  */ DEADTRANS( 0x00C9	,0xECD0	,0xECE5	,0x0001), // Multikey chain
/*<!M><g><eacute><m>                                               */ DEADTRANS( L'm'	,0xECE4	,0xECE6	,0x0001), // Multikey chain
/*<!M><G><Eacute><M>                                               */ DEADTRANS( L'M'	,0xECE5	,0xECE7	,0x0001), // Multikey chain
/*<!M><g><eacute><m><e>                                            */ DEADTRANS( L'e'	,0xECE6	,0x264A	,0x0000), // 'e' ➔ "♊" GEMINI emoji
/*<!M><G><Eacute><M><E>                                            */ DEADTRANS( L'E'	,0xECE7	,0x264A	,0x0000), // 'E' ➔ "♊" GEMINI emoji
/*<!M><g><g>                                                       */ DEADTRANS( L'g'	,0xECCF	,0xECEA	,0x0001), // Multikey chain
/*<!M><G><G>                                                       */ DEADTRANS( L'G'	,0xECD0	,0xECEB	,0x0001), // Multikey chain
/*<!M><g><g><%at>                                                  */ DEADTRANS( L'@'	,0xECEA	,0x213D	,0x0000), // '@' ➔ "ℽ" DOUBLE-STRUCK SMALL GAMMA
/*<!M><G><G><%at>                                                  */ DEADTRANS( L'@'	,0xECEB	,0x213E	,0x0000), // '@' ➔ "ℾ" DOUBLE-STRUCK CAPITAL GAMMA
/*<!M><G><H>                                                       */ DEADTRANS( L'H'	,0xECD0	,0xECEF	,0x0001), // Multikey chain
/*<!M><g><h>                                                       */ DEADTRANS( L'h'	,0xECCF	,0xECF0	,0x0001), // Multikey chain
/*<!M><G><h>                                                       */ DEADTRANS( L'h'	,0xECD0	,0x01A2	,0x0000), // 'h' ➔ "Ƣ" LATIN CAPITAL LETTER OI, LATIN CAPITAL LETTER GHA
/*<!M><g><h><s>                                                    */ DEADTRANS( L's'	,0xECF0	,0x20B5	,0x0000), // 's' ➔ "₵" CEDI SIGN, Ghana Cedi GHANA
/*<!M><G><H><S>                                                    */ DEADTRANS( L'S'	,0xECEF	,0x20B5	,0x0000), // 'S' ➔ "₵" CEDI SIGN, Ghana Cedi GHANA
/*<!M><G><H><~space>                                               */ DEADTRANS( L' '	,0xECEF	,0x01A2	,0x0000), // ' ' ➔ "Ƣ" LATIN CAPITAL LETTER OI, LATIN CAPITAL LETTER GHA
/*<!M><g><h><~space>                                               */ DEADTRANS( L' '	,0xECF0	,0x01A3	,0x0000), // ' ' ➔ "ƣ" LATIN SMALL LETTER OI, LATIN SMALL LETTER GHA
/*<!M><G><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xECD0	,0x27F3	,0x0000), // ' ' ➔ "⟳" CLOCKWISE GAPPED CIRCLE ARROW
/*<!M><G><~space>                                                  */ DEADTRANS( L' '	,0xECD0	,0x27F3	,0x0000), // ' ' ➔ "⟳" CLOCKWISE GAPPED CIRCLE ARROW
/*<!M><h>                                                          */ DEADTRANS( L'h'	,0x00A6	,0xECF7	,0x0001), // Multikey chain
/*<!M><H>                                                          */ DEADTRANS( L'H'	,0x00A6	,0xECF8	,0x0001), // Multikey chain
/*<!M><h><%apostrophe>                                             */ DEADTRANS( L'\''	,0xECF7	,0xECF9	,0x0001), // Multikey chain
/*<!M><H><%apostrophe>                                             */ DEADTRANS( L'\''	,0xECF8	,0xECFA	,0x0001), // Multikey chain
/*<!M><h><%apostrophe><%parenleft>                                 */ DEADTRANS( L'('	,0xECF9	,0xA720	,0x0000), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H><%apostrophe><%parenleft>                                 */ DEADTRANS( L'('	,0xECFA	,0xA720	,0x0000), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><h><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xECF7	,0xECFD	,0x0001), // Multikey chain
/*<!M><H><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xECF8	,0xECFE	,0x0001), // Multikey chain
/*<!M><h><%aprightsingquotmark><%parenleft>                        */ DEADTRANS( L'('	,0xECFD	,0xA720	,0x0000), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H><%aprightsingquotmark><%parenleft>                        */ DEADTRANS( L'('	,0xECFE	,0xA720	,0x0000), // '(' ➔ "꜠" MODIFIER LETTER STRESS AND HIGH TONE
/*<!M><H><%hash>                                                   */ DEADTRANS( L'#'	,0xECF8	,0x210C	,0x0000), // '#' ➔ "ℌ" BLACK-LETTER CAPITAL H
/*<!M><h><%hash>                                                   */ DEADTRANS( L'#'	,0xECF7	,0x266A	,0x0000), // '#' ➔ "♪" EIGHTH NOTE
/*<!M><h><%minus>                                                  */ DEADTRANS( L'-'	,0xECF7	,0x266B	,0x0000), // '-' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><H><%minus>                                                  */ DEADTRANS( L'-'	,0xECF8	,0x266B	,0x0000), // '-' ➔ "♫" BEAMED EIGHTH NOTES
/*<!M><h><%parenleft>                                              */ DEADTRANS( L'('	,0xECF7	,0x02F9	,0x0000), // '(' ➔ "˹" MODIFIER LETTER BEGIN HIGH TONE
/*<!M><H><%parenleft>                                              */ DEADTRANS( L'('	,0xECF8	,0x02F9	,0x0000), // '(' ➔ "˹" MODIFIER LETTER BEGIN HIGH TONE
/*<!M><h><%parenright>                                             */ DEADTRANS( L')'	,0xECF7	,0x02FA	,0x0000), // ')' ➔ "˺" MODIFIER LETTER END HIGH TONE
/*<!M><H><%parenright>                                             */ DEADTRANS( L')'	,0xECF8	,0x02FA	,0x0000), // ')' ➔ "˺" MODIFIER LETTER END HIGH TONE
/*<!M><h><%slash>                                                  */ DEADTRANS( L'/'	,0xECF7	,0xED09	,0x0001), // Multikey chain
/*<!M><h><%slash><%slash>                                          */ DEADTRANS( L'/'	,0xED09	,0x210F	,0x0000), // '/' ➔ "ℏ" PLANCK CONSTANT OVER TWO PI
/*<!M><h><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xED09	,0x210E	,0x0000), // ' ' ➔ "ℎ" PLANCK CONSTANT
/*<!M><h><%slash><~space>                                          */ DEADTRANS( L' '	,0xED09	,0x210E	,0x0000), // ' ' ➔ "ℎ" PLANCK CONSTANT
/*<!M><H><%tilde>                                                  */ DEADTRANS( L'~'	,0xECF8	,0x210B	,0x0000), // '~' ➔ "ℋ" SCRIPT CAPITAL H
/*<!M><h><d>                                                       */ DEADTRANS( L'd'	,0xECF7	,0xED0E	,0x0001), // Multikey chain
/*<!M><H><D>                                                       */ DEADTRANS( L'D'	,0xECF8	,0xED0F	,0x0001), // Multikey chain
/*<!M><h><d><p>                                                    */ DEADTRANS( L'p'	,0xED0E	,0xED10	,0x0001), // Multikey chain
/*<!M><H><D><P>                                                    */ DEADTRANS( L'P'	,0xED0F	,0xED11	,0x0001), // Multikey chain
/*<!M><h><d><p><e>                                                 */ DEADTRANS( L'e'	,0xED10	,0x2674	,0x0000), // 'e' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><H><D><P><E>                                                 */ DEADTRANS( L'E'	,0xED11	,0x2674	,0x0000), // 'E' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><H><H>                                                       */ DEADTRANS( L'H'	,0xECF8	,0x210D	,0x0000), // 'H' ➔ "ℍ" DOUBLE-STRUCK CAPITAL H
/*<!M><H><N>                                                       */ DEADTRANS( L'N'	,0xECF8	,0xA726	,0x0000), // 'N' ➔ "Ꜧ" LATIN CAPITAL LETTER HENG
/*<!M><H><n>                                                       */ DEADTRANS( L'n'	,0xECF8	,0xA726	,0x0000), // 'n' ➔ "Ꜧ" LATIN CAPITAL LETTER HENG
/*<!M><h><n>                                                       */ DEADTRANS( L'n'	,0xECF7	,0xA727	,0x0000), // 'n' ➔ "ꜧ" LATIN SMALL LETTER HENG
/*<!M><h><o>                                                       */ DEADTRANS( L'o'	,0xECF7	,0xED18	,0x0001), // Multikey chain
/*<!M><H><O>                                                       */ DEADTRANS( L'O'	,0xECF8	,0xED19	,0x0001), // Multikey chain
/*<!M><h><o><m>                                                    */ DEADTRANS( L'm'	,0xED18	,0x21F1	,0x0000), // 'm' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><H><O><M>                                                    */ DEADTRANS( L'M'	,0xED19	,0x21F1	,0x0000), // 'M' ➔ "⇱" NORTH WEST ARROW TO CORNER
/*<!M><h><v>                                                       */ DEADTRANS( L'v'	,0xECF7	,0x0195	,0x0000), // 'v' ➔ "ƕ" LATIN SMALL LETTER HV
/*<!M><H><V>                                                       */ DEADTRANS( L'V'	,0xECF8	,0x01F6	,0x0000), // 'V' ➔ "Ƕ" LATIN CAPITAL LETTER HWAIR
/*<!M><H><v>                                                       */ DEADTRANS( L'v'	,0xECF8	,0x01F6	,0x0000), // 'v' ➔ "Ƕ" LATIN CAPITAL LETTER HWAIR
/*<!M><H><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xECF8	,0x2207	,0x0000), // ' ' ➔ "∇" NABLA
/*<!M><H><~space>                                                  */ DEADTRANS( L' '	,0xECF8	,0x2207	,0x0000), // ' ' ➔ "∇" NABLA
/*<!M><i>                                                          */ DEADTRANS( L'i'	,0x00A6	,0xED21	,0x0001), // Multikey chain
/*<!M><I>                                                          */ DEADTRANS( L'I'	,0x00A6	,0xED22	,0x0001), // Multikey chain
/*<!M><i><%at>                                                     */ DEADTRANS( L'@'	,0xED21	,0xED23	,0x0001), // Multikey chain
/*<!M><i><%at><%percent>                                           */ DEADTRANS( L'%'	,0xED23	,0x2129	,0x0000), // '%' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%at><~nbspace>                                           */ DEADTRANS( 0x00A0	,0xED23	,0x2129	,0x0000), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%at><~space>                                             */ DEADTRANS( L' '	,0xED23	,0x2129	,0x0000), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%bar>                                                    */ DEADTRANS( L'|'	,0xED21	,0x2068	,0x0000), // '|' ➔ "⁨" FIRST STRONG ISOLATE
/*<!M><I><%bracketleft>                                            */ DEADTRANS( L'['	,0xED22	,0xED28	,0x0001), // Multikey chain
/*<!M><I><%bracketleft><%bracketright>                             */ DEADTRANS( L']'	,0xED28	,0x29EE	,0x0000), // ']' ➔ "⧮" ERROR-BARRED WHITE SQUARE
/*<!M><I><%bracketleft><%hash>                                     */ DEADTRANS( L'#'	,0xED28	,0x29EF	,0x0000), // '#' ➔ "⧯" ERROR-BARRED BLACK SQUARE
/*<!M><I><%bracketright>                                           */ DEADTRANS( L']'	,0xED22	,0x29EE	,0x0000), // ']' ➔ "⧮" ERROR-BARRED WHITE SQUARE
/*<!M><i><%equal>                                                  */ DEADTRANS( L'='	,0xED21	,0x2069	,0x0000), // '=' ➔ "⁩" POP DIRECTIONAL ISOLATE
/*<!M><i><%greater>                                                */ DEADTRANS( L'>'	,0xED21	,0x2066	,0x0000), // '>' ➔ "⁦" LEFT-TO-RIGHT ISOLATE
/*<!M><I><%greater>                                                */ DEADTRANS( L'>'	,0xED22	,0x29F0	,0x0000), // '>' ➔ "⧰" ERROR-BARRED WHITE DIAMOND
/*<!M><I><%hash>                                                   */ DEADTRANS( L'#'	,0xED22	,0x2111	,0x0000), // '#' ➔ "ℑ" BLACK-LETTER CAPITAL I
/*<!M><I><%less>                                                   */ DEADTRANS( L'<'	,0xED22	,0xED31	,0x0001), // Multikey chain
/*<!M><i><%less>                                                   */ DEADTRANS( L'<'	,0xED21	,0x2067	,0x0000), // '<' ➔ "⁧" RIGHT-TO-LEFT ISOLATE
/*<!M><I><%less><%greater>                                         */ DEADTRANS( L'>'	,0xED31	,0x29F0	,0x0000), // '>' ➔ "⧰" ERROR-BARRED WHITE DIAMOND
/*<!M><I><%less><%hash>                                            */ DEADTRANS( L'#'	,0xED31	,0x29F1	,0x0000), // '#' ➔ "⧱" ERROR-BARRED BLACK DIAMOND
/*<!M><i><%percent>                                                */ DEADTRANS( L'%'	,0xED21	,0xED34	,0x0001), // Multikey chain
/*<!M><i><%percent><%at>                                           */ DEADTRANS( L'@'	,0xED34	,0x2129	,0x0000), // '@' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xED34	,0x2129	,0x0000), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><i><%percent><~space>                                        */ DEADTRANS( L' '	,0xED34	,0x2129	,0x0000), // ' ' ➔ "℩" TURNED GREEK SMALL LETTER IOTA
/*<!M><I><%tilde>                                                  */ DEADTRANS( L'~'	,0xED22	,0x2110	,0x0000), // '~' ➔ "ℐ" SCRIPT CAPITAL I
/*<!M><I><%underscore>                                             */ DEADTRANS( L'_'	,0xED22	,0xED39	,0x0001), // Multikey chain
/*<!M><I><%underscore><%apostrophe>                                */ DEADTRANS( L'\''	,0xED39	,0x2AE0	,0x0000), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><I><%underscore><%bar>                                       */ DEADTRANS( L'|'	,0xED39	,0x27D8	,0x0000), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><I><%underscore><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xED39	,0x22A5	,0x0000), // ' ' ➔ "⊥" UP TACK
/*<!M><I><%underscore><~space>                                     */ DEADTRANS( L' '	,0xED39	,0x22A5	,0x0000), // ' ' ➔ "⊥" UP TACK
/*<!M><i><1>                                                       */ DEADTRANS( L'1'	,0xED21	,0xA70D	,0x0000), // '1' ➔ "꜍" MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><I><1>                                                       */ DEADTRANS( L'1'	,0xED22	,0xA70D	,0x0000), // '1' ➔ "꜍" MODIFIER LETTER EXTRA-HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><i><2>                                                       */ DEADTRANS( L'2'	,0xED21	,0xA70E	,0x0000), // '2' ➔ "꜎" MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><I><2>                                                       */ DEADTRANS( L'2'	,0xED22	,0xA70E	,0x0000), // '2' ➔ "꜎" MODIFIER LETTER HIGH DOTTED LEFT-STEM TONE BAR
/*<!M><i><3>                                                       */ DEADTRANS( L'3'	,0xED21	,0xA70F	,0x0000), // '3' ➔ "꜏" MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*<!M><I><3>                                                       */ DEADTRANS( L'3'	,0xED22	,0xA70F	,0x0000), // '3' ➔ "꜏" MODIFIER LETTER MID DOTTED LEFT-STEM TONE BAR
/*<!M><i><4>                                                       */ DEADTRANS( L'4'	,0xED21	,0xA710	,0x0000), // '4' ➔ "꜐" MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*<!M><I><4>                                                       */ DEADTRANS( L'4'	,0xED22	,0xA710	,0x0000), // '4' ➔ "꜐" MODIFIER LETTER LOW DOTTED LEFT-STEM TONE BAR
/*<!M><i><5>                                                       */ DEADTRANS( L'5'	,0xED21	,0xA711	,0x0000), // '5' ➔ "꜑" MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*<!M><I><5>                                                       */ DEADTRANS( L'5'	,0xED22	,0xA711	,0x0000), // '5' ➔ "꜑" MODIFIER LETTER EXTRA-LOW DOTTED LEFT-STEM TONE BAR
/*<!M><i><e>                                                       */ DEADTRANS( L'e'	,0xED21	,0xAB61	,0x0000), // 'e' ➔ "ꭡ" LATIN SMALL LETTER IOTIFIED E
/*<!M><i><i>                                                       */ DEADTRANS( L'i'	,0xED21	,0xED4A	,0x0001), // Multikey chain
/*<!M><I><I>                                                       */ DEADTRANS( L'I'	,0xED22	,0x2AFF	,0x0000), // 'I' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><i><i><%slash>                                               */ DEADTRANS( L'/'	,0xED4A	,0x2148	,0x0000), // '/' ➔ "ⅈ" DOUBLE-STRUCK ITALIC SMALL I
/*<!M><i><i><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xED4A	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><i><i><~space>                                               */ DEADTRANS( L' '	,0xED4A	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><I><J>                                                       */ DEADTRANS( L'J'	,0xED22	,0x0132	,0x0000), // 'J' ➔ "Ĳ" LATIN CAPITAL LIGATURE IJ
/*<!M><I><j>                                                       */ DEADTRANS( L'j'	,0xED22	,0x0132	,0x0000), // 'j' ➔ "Ĳ" LATIN CAPITAL LIGATURE IJ
/*<!M><i><j>                                                       */ DEADTRANS( L'j'	,0xED21	,0x0133	,0x0000), // 'j' ➔ "ĳ" LATIN SMALL LIGATURE IJ
/*<!M><i><l>                                                       */ DEADTRANS( L'l'	,0xED21	,0xED51	,0x0001), // Multikey chain
/*<!M><I><L>                                                       */ DEADTRANS( L'L'	,0xED22	,0xED52	,0x0001), // Multikey chain
/*<!M><i><l><s>                                                    */ DEADTRANS( L's'	,0xED51	,0x20AA	,0x0000), // 's' ➔ "₪" NEW SHEQEL SIGN, New Israeli Sheqel ISRAEL
/*<!M><I><L><S>                                                    */ DEADTRANS( L'S'	,0xED52	,0x20AA	,0x0000), // 'S' ➔ "₪" NEW SHEQEL SIGN, New Israeli Sheqel ISRAEL
/*<!M><i><n>                                                       */ DEADTRANS( L'n'	,0xED21	,0xED55	,0x0001), // Multikey chain
/*<!M><I><N>                                                       */ DEADTRANS( L'N'	,0xED22	,0xED56	,0x0001), // Multikey chain
/*<!M><i><n><r>                                                    */ DEADTRANS( L'r'	,0xED55	,0x20B9	,0x0000), // 'r' ➔ "₹" INDIAN RUPEE SIGN, Indian Rupee INDIA, BHUTAN
/*<!M><I><N><R>                                                    */ DEADTRANS( L'R'	,0xED56	,0x20B9	,0x0000), // 'R' ➔ "₹" INDIAN RUPEE SIGN, Indian Rupee INDIA, BHUTAN
/*<!M><i><n><t>                                                    */ DEADTRANS( L't'	,0xED55	,0xED59	,0x0001), // Multikey chain
/*<!M><i><n><t><e>                                                 */ DEADTRANS( L'e'	,0xED59	,0xED5A	,0x0001), // Multikey chain
/*<!M><i><n><t><e><r>                                              */ DEADTRANS( L'r'	,0xED5A	,0xED5B	,0x0001), // Multikey chain
/*<!M><i><n><t><e><r><s>                                           */ DEADTRANS( L's'	,0xED5B	,0xED5C	,0x0001), // Multikey chain
/*<!M><i><n><t><e><r><s><e>                                        */ DEADTRANS( L'e'	,0xED5C	,0xED5D	,0x0001), // Multikey chain
/*<!M><i><n><t><e><r><s><e><c>                                     */ DEADTRANS( L'c'	,0xED5D	,0x2229	,0x0000), // 'c' ➔ "∩" INTERSECTION French truncated name
/*<!M><I><O>                                                       */ DEADTRANS( L'O'	,0xED22	,0xED61	,0x0001), // Multikey chain
/*<!M><i><o>                                                       */ DEADTRANS( L'o'	,0xED21	,0x2AF0	,0x0000), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><I><o>                                                       */ DEADTRANS( L'o'	,0xED22	,0x2AF0	,0x0000), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><I><O><%hash>                                                */ DEADTRANS( L'#'	,0xED61	,0x29F3	,0x0000), // '#' ➔ "⧳" ERROR-BARRED BLACK CIRCLE
/*<!M><I><O><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xED61	,0x29F2	,0x0000), // ' ' ➔ "⧲" ERROR-BARRED WHITE CIRCLE
/*<!M><I><O><~space>                                               */ DEADTRANS( L' '	,0xED61	,0x29F2	,0x0000), // ' ' ➔ "⧲" ERROR-BARRED WHITE CIRCLE
/*<!M><i><p>                                                       */ DEADTRANS( L'p'	,0xED21	,0xED65	,0x0001), // Multikey chain
/*<!M><I><P>                                                       */ DEADTRANS( L'P'	,0xED22	,0xED66	,0x0001), // Multikey chain
/*<!M><i><p><d>                                                    */ DEADTRANS( L'd'	,0xED65	,0x261B	,0x0000), // 'd' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><I><P><D>                                                    */ DEADTRANS( L'D'	,0xED66	,0x261B	,0x0000), // 'D' ➔ "☛" BLACK RIGHT POINTING INDEX, rightpointer, not U261E WHITE RIGHT POINTING INDEX
/*<!M><i><p><g>                                                    */ DEADTRANS( L'g'	,0xED65	,0x261A	,0x0000), // 'g' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><I><P><G>                                                    */ DEADTRANS( L'G'	,0xED66	,0x261A	,0x0000), // 'G' ➔ "☚" BLACK LEFT POINTING INDEX, leftpointer, not U261C WHITE LEFT POINTING INDEX
/*<!M><i><q>                                                       */ DEADTRANS( L'q'	,0xED21	,0xED6B	,0x0001), // Multikey chain
/*<!M><I><Q>                                                       */ DEADTRANS( L'Q'	,0xED22	,0xED6C	,0x0001), // Multikey chain
/*<!M><i><q><d>                                                    */ DEADTRANS( L'd'	,0xED6B	,0x0639	,0x0000), // 'd' ➔ "ع" ARABIC LETTER AIN, Iraqi Dinar IRAQ
/*<!M><I><Q><D>                                                    */ DEADTRANS( L'D'	,0xED6C	,0x0639	,0x0000), // 'D' ➔ "ع" ARABIC LETTER AIN, Iraqi Dinar IRAQ
/*<!M><i><r>                                                       */ DEADTRANS( L'r'	,0xED21	,0xED6F	,0x0001), // Multikey chain
/*<!M><I><R>                                                       */ DEADTRANS( L'R'	,0xED22	,0xED70	,0x0001), // Multikey chain
/*<!M><i><r><m>                                                    */ DEADTRANS( L'm'	,0xED6F	,0xED71	,0x0001), // Multikey chain
/*<!M><I><R><M>                                                    */ DEADTRANS( L'M'	,0xED70	,0xED72	,0x0001), // Multikey chain
/*<!M><i><r><m><p>                                                 */ DEADTRANS( L'p'	,0xED71	,0xED73	,0x0001), // Multikey chain
/*<!M><I><R><M><P>                                                 */ DEADTRANS( L'P'	,0xED72	,0xED74	,0x0001), // Multikey chain
/*<!M><i><r><m><p><d>                                              */ DEADTRANS( L'd'	,0xED73	,0xDC49	,0x0000), // High surrogate: D83D; U+1F449 'd' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><I><R><M><P><D>                                              */ DEADTRANS( L'D'	,0xED74	,0xDC49	,0x0000), // High surrogate: D83D; U+1F449 'D' ➔ "👉" WHITE RIGHT POINTING BACKHAND INDEX
/*<!M><i><r><m><p><g>                                              */ DEADTRANS( L'g'	,0xED73	,0xDC48	,0x0000), // High surrogate: D83D; U+1F448 'g' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><I><R><M><P><G>                                              */ DEADTRANS( L'G'	,0xED74	,0xDC48	,0x0000), // High surrogate: D83D; U+1F448 'G' ➔ "👈" WHITE LEFT POINTING BACKHAND INDEX
/*<!M><i><r><r>                                                    */ DEADTRANS( L'r'	,0xED6F	,0xFDFC	,0x0000), // 'r' ➔ "﷼" RIAL SIGN, Iranian Rial ISLAMIC REPUBLIC OF IRAN
/*<!M><I><R><R>                                                    */ DEADTRANS( L'R'	,0xED70	,0xFDFC	,0x0000), // 'R' ➔ "﷼" RIAL SIGN, Iranian Rial ISLAMIC REPUBLIC OF IRAN
/*<!M><I><S>                                                       */ DEADTRANS( L'S'	,0xED22	,0xA76C	,0x0000), // 'S' ➔ "Ꝭ" LATIN CAPITAL LETTER IS
/*<!M><I><s>                                                       */ DEADTRANS( L's'	,0xED22	,0xA76C	,0x0000), // 's' ➔ "Ꝭ" LATIN CAPITAL LETTER IS
/*<!M><i><s>                                                       */ DEADTRANS( L's'	,0xED21	,0xA76D	,0x0000), // 's' ➔ "ꝭ" LATIN SMALL LETTER IS
/*<!M><j>                                                          */ DEADTRANS( L'j'	,0x00A6	,0xED7E	,0x0001), // Multikey chain
/*<!M><J>                                                          */ DEADTRANS( L'J'	,0x00A6	,0xED7F	,0x0001), // Multikey chain
/*<!M><j><%exclam>                                                 */ DEADTRANS( L'!'	,0xED7E	,0x297E	,0x0000), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><J><%exclam>                                                 */ DEADTRANS( L'!'	,0xED7F	,0x297E	,0x0000), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><j><%greater>                                                */ DEADTRANS( L'>'	,0xED7E	,0x22B1	,0x0000), // '>' ➔ "⊱" SUCCEEDS UNDER RELATION
/*<!M><j><%less>                                                   */ DEADTRANS( L'<'	,0xED7E	,0x22B0	,0x0000), // '<' ➔ "⊰" PRECEDES UNDER RELATION
/*<!M><j><%minus>                                                  */ DEADTRANS( L'-'	,0xED7E	,0x297C	,0x0000), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><J><%minus>                                                  */ DEADTRANS( L'-'	,0xED7F	,0x297C	,0x0000), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><j><a>                                                       */ DEADTRANS( L'a'	,0xED7E	,0xAB60	,0x0000), // 'a' ➔ "ꭠ" LATIN SMALL LETTER SAKHA YAT
/*<!M><j><j>                                                       */ DEADTRANS( L'j'	,0xED7E	,0x2149	,0x0000), // 'j' ➔ "ⅉ" DOUBLE-STRUCK ITALIC SMALL J
/*<!M><j><o>                                                       */ DEADTRANS( L'o'	,0xED7E	,0xED88	,0x0001), // Multikey chain
/*<!M><J><O>                                                       */ DEADTRANS( L'O'	,0xED7F	,0xED89	,0x0001), // Multikey chain
/*<!M><j><p>                                                       */ DEADTRANS( L'p'	,0xED7E	,0xED8C	,0x0001), // Multikey chain
/*<!M><J><P>                                                       */ DEADTRANS( L'P'	,0xED7F	,0xED8D	,0x0001), // Multikey chain
/*<!M><j><p><y>                                                    */ DEADTRANS( L'y'	,0xED8C	,0x00A5	,0x0000), // 'y' ➔ "¥" YEN SIGN, Yen JAPAN
/*<!M><J><P><Y>                                                    */ DEADTRANS( L'Y'	,0xED8D	,0x00A5	,0x0000), // 'Y' ➔ "¥" YEN SIGN, Yen JAPAN
/*<!M><k>                                                          */ DEADTRANS( L'k'	,0x00A6	,0xED90	,0x0001), // Multikey chain
/*<!M><K>                                                          */ DEADTRANS( L'K'	,0x00A6	,0xED91	,0x0001), // Multikey chain
/*<!M><k><%at>                                                     */ DEADTRANS( L'@'	,0xED90	,0x03F0	,0x0000), // '@' ➔ "ϰ" GREEK KAPPA SYMBOL
/*<!M><k><%equal>                                                  */ DEADTRANS( L'='	,0xED90	,0x20AD	,0x0000), // '=' ➔ "₭" KIP SIGN
/*<!M><K><%equal>                                                  */ DEADTRANS( L'='	,0xED91	,0x20AD	,0x0000), // '=' ➔ "₭" KIP SIGN
/*<!M><k><%minus>                                                  */ DEADTRANS( L'-'	,0xED90	,0x20AD	,0x0000), // '-' ➔ "₭" KIP SIGN
/*<!M><K><%minus>                                                  */ DEADTRANS( L'-'	,0xED91	,0x20AD	,0x0000), // '-' ➔ "₭" KIP SIGN
/*<!M><k><d>                                                       */ DEADTRANS( L'd'	,0xED90	,0x23F7	,0x0000), // 'd' ➔ "⏷" BLACK MEDIUM DOWN-POINTING TRIANGLE
/*<!M><K><D>                                                       */ DEADTRANS( L'D'	,0xED91	,0x23F7	,0x0000), // 'D' ➔ "⏷" BLACK MEDIUM DOWN-POINTING TRIANGLE
/*<!M><k><g>                                                       */ DEADTRANS( L'g'	,0xED90	,0xED99	,0x0001), // Multikey chain
/*<!M><K><G>                                                       */ DEADTRANS( L'G'	,0xED91	,0xED9A	,0x0001), // Multikey chain
/*<!M><k><g><s>                                                    */ DEADTRANS( L's'	,0xED99	,0x20C0	,0x0000), // 's' ➔ "⃀" SOM SIGN, Som KYRGYZSTAN
/*<!M><K><G><S>                                                    */ DEADTRANS( L'S'	,0xED9A	,0x20C0	,0x0000), // 'S' ➔ "⃀" SOM SIGN, Som KYRGYZSTAN
/*<!M><k><h>                                                       */ DEADTRANS( L'h'	,0xED90	,0xED9D	,0x0001), // Multikey chain
/*<!M><K><H>                                                       */ DEADTRANS( L'H'	,0xED91	,0xED9E	,0x0001), // Multikey chain
/*<!M><k><h><r>                                                    */ DEADTRANS( L'r'	,0xED9D	,0x17DB	,0x0000), // 'r' ➔ "៛" KHMER CURRENCY SYMBOL RIEL, Riel CAMBODIA
/*<!M><K><H><R>                                                    */ DEADTRANS( L'R'	,0xED9E	,0x17DB	,0x0000), // 'R' ➔ "៛" KHMER CURRENCY SYMBOL RIEL, Riel CAMBODIA
/*<!M><k><o>                                                       */ DEADTRANS( L'o'	,0xED90	,0xEDA1	,0x0001), // Multikey chain
/*<!M><K><O>                                                       */ DEADTRANS( L'O'	,0xED91	,0xEDA2	,0x0001), // Multikey chain
/*<!M><k><o><m>                                                    */ DEADTRANS( L'm'	,0xEDA1	,0x203B	,0x0000), // 'm' ➔ "※" REFERENCE MARK, Japanese kome
/*<!M><K><O><M>                                                    */ DEADTRANS( L'M'	,0xEDA2	,0x203B	,0x0000), // 'M' ➔ "※" REFERENCE MARK, Japanese kome
/*<!M><k><p>                                                       */ DEADTRANS( L'p'	,0xED90	,0xEDA5	,0x0001), // Multikey chain
/*<!M><K><P>                                                       */ DEADTRANS( L'P'	,0xED91	,0xEDA6	,0x0001), // Multikey chain
/*<!M><k><p><w>                                                    */ DEADTRANS( L'w'	,0xEDA5	,0x20A9	,0x0000), // 'w' ➔ "₩" WON SIGN, North Korean Won THE DEMOCRATIC PEOPLE’S REPUBLIC OF KOREA
/*<!M><K><P><W>                                                    */ DEADTRANS( L'W'	,0xEDA6	,0x20A9	,0x0000), // 'W' ➔ "₩" WON SIGN, North Korean Won THE DEMOCRATIC PEOPLE’S REPUBLIC OF KOREA
/*<!M><k><r>                                                       */ DEADTRANS( L'r'	,0xED90	,0xEDA9	,0x0001), // Multikey chain
/*<!M><K><R>                                                       */ DEADTRANS( L'R'	,0xED91	,0xEDAA	,0x0001), // Multikey chain
/*<!M><k><r><w>                                                    */ DEADTRANS( L'w'	,0xEDA9	,0x20A9	,0x0000), // 'w' ➔ "₩" WON SIGN, Won KOREA (THE REPUBLIC OF)
/*<!M><K><R><W>                                                    */ DEADTRANS( L'W'	,0xEDAA	,0x20A9	,0x0000), // 'W' ➔ "₩" WON SIGN, Won KOREA (THE REPUBLIC OF)
/*<!M><k><u>                                                       */ DEADTRANS( L'u'	,0xED90	,0x23F6	,0x0000), // 'u' ➔ "⏶" BLACK MEDIUM UP-POINTING TRIANGLE
/*<!M><K><U>                                                       */ DEADTRANS( L'U'	,0xED91	,0x23F6	,0x0000), // 'U' ➔ "⏶" BLACK MEDIUM UP-POINTING TRIANGLE
/*<!M><k><w>                                                       */ DEADTRANS( L'w'	,0xED90	,0xEDAF	,0x0001), // Multikey chain
/*<!M><K><W>                                                       */ DEADTRANS( L'W'	,0xED91	,0xEDB0	,0x0001), // Multikey chain
/*<!M><k><z>                                                       */ DEADTRANS( L'z'	,0xED90	,0xEDB3	,0x0001), // Multikey chain
/*<!M><K><Z>                                                       */ DEADTRANS( L'Z'	,0xED91	,0xEDB4	,0x0001), // Multikey chain
/*<!M><k><z><t>                                                    */ DEADTRANS( L't'	,0xEDB3	,0x20B8	,0x0000), // 't' ➔ "₸" TENGE SIGN, Tenge KAZAKHSTAN
/*<!M><K><Z><T>                                                    */ DEADTRANS( L'T'	,0xEDB4	,0x20B8	,0x0000), // 'T' ➔ "₸" TENGE SIGN, Tenge KAZAKHSTAN
/*<!M><l>                                                          */ DEADTRANS( L'l'	,0x00A6	,0xEDB7	,0x0001), // Multikey chain
/*<!M><L>                                                          */ DEADTRANS( L'L'	,0x00A6	,0xEDB8	,0x0001), // Multikey chain
/*<!M><l><%apostrophe>                                             */ DEADTRANS( L'\''	,0xEDB7	,0xEDB9	,0x0001), // Multikey chain
/*<!M><L><%apostrophe>                                             */ DEADTRANS( L'\''	,0xEDB8	,0xEDBA	,0x0001), // Multikey chain
/*<!M><l><%apostrophe><%parenleft>                                 */ DEADTRANS( L'('	,0xEDB9	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%apostrophe><%parenleft>                                 */ DEADTRANS( L'('	,0xEDBA	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><l><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xEDB7	,0xEDBD	,0x0001), // Multikey chain
/*<!M><L><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xEDB8	,0xEDBE	,0x0001), // Multikey chain
/*<!M><l><%aprightsingquotmark><%parenleft>                        */ DEADTRANS( L'('	,0xEDBD	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%aprightsingquotmark><%parenleft>                        */ DEADTRANS( L'('	,0xEDBE	,0xA721	,0x0000), // '(' ➔ "꜡" MODIFIER LETTER STRESS AND LOW TONE
/*<!M><L><%backslash>                                              */ DEADTRANS( L'\\'	,0xEDB8	,0xEDC1	,0x0001), // Multikey chain
/*<!M><L><%backslash><%period>                                     */ DEADTRANS( L'.'	,0xEDC1	,0x27D3	,0x0000), // '.' ➔ "⟓" LOWER RIGHT CORNER WITH DOT
/*<!M><L><%backslash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xEDC1	,0x2143	,0x0000), // ' ' ➔ "⅃" REVERSED SANS-SERIF CAPITAL L
/*<!M><L><%backslash><~space>                                      */ DEADTRANS( L' '	,0xEDC1	,0x2143	,0x0000), // ' ' ➔ "⅃" REVERSED SANS-SERIF CAPITAL L
/*<!M><L><%bracketright>                                           */ DEADTRANS( L']'	,0xEDB8	,0x299C	,0x0000), // ']' ➔ "⦜" RIGHT ANGLE VARIANT WITH SQUARE
/*<!M><L><%equal>                                                  */ DEADTRANS( L'='	,0xEDB8	,0x20A4	,0x0000), // '=' ➔ "₤" LIRA SIGN
/*<!M><l><%minus>                                                  */ DEADTRANS( L'-'	,0xEDB7	,0x00A3	,0x0000), // '-' ➔ "£" POUND SIGN
/*<!M><L><%minus>                                                  */ DEADTRANS( L'-'	,0xEDB8	,0x00A3	,0x0000), // '-' ➔ "£" POUND SIGN
/*<!M><l><%parenleft>                                              */ DEADTRANS( L'('	,0xEDB7	,0x02FB	,0x0000), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><L><%parenleft>                                              */ DEADTRANS( L'('	,0xEDB8	,0x02FB	,0x0000), // '(' ➔ "˻" MODIFIER LETTER BEGIN LOW TONE
/*<!M><L><%parenright>                                             */ DEADTRANS( L')'	,0xEDB8	,0xEDCC	,0x0001), // Multikey chain
/*<!M><l><%parenright>                                             */ DEADTRANS( L')'	,0xEDB7	,0x02FC	,0x0000), // ')' ➔ "˼" MODIFIER LETTER END LOW TONE
/*<!M><L><%parenright><%period>                                    */ DEADTRANS( L'.'	,0xEDCC	,0x299D	,0x0000), // '.' ➔ "⦝" MEASURED RIGHT ANGLE WITH DOT
/*<!M><L><%parenright><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xEDCC	,0x22BE	,0x0000), // ' ' ➔ "⊾" RIGHT ANGLE WITH ARC
/*<!M><L><%parenright><~space>                                     */ DEADTRANS( L' '	,0xEDCC	,0x22BE	,0x0000), // ' ' ➔ "⊾" RIGHT ANGLE WITH ARC
/*<!M><L><%percent>                                                */ DEADTRANS( L'%'	,0xEDB8	,0xEDD0	,0x0001), // Multikey chain
/*<!M><L><%percent><%percent>                                      */ DEADTRANS( L'%'	,0xEDD0	,0xEDD1	,0x0001), // Multikey chain
/*<!M><L><%percent><%percent><%period>                             */ DEADTRANS( L'.'	,0xEDD1	,0x27D4	,0x0000), // '.' ➔ "⟔" UPPER LEFT CORNER WITH DOT
/*<!M><L><%percent><%period>                                       */ DEADTRANS( L'.'	,0xEDD0	,0x27D4	,0x0000), // '.' ➔ "⟔" UPPER LEFT CORNER WITH DOT
/*<!M><L><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xEDD0	,0x2142	,0x0000), // ' ' ➔ "⅂" TURNED SANS-SERIF CAPITAL L
/*<!M><L><%percent><~space>                                        */ DEADTRANS( L' '	,0xEDD0	,0x2142	,0x0000), // ' ' ➔ "⅂" TURNED SANS-SERIF CAPITAL L
/*<!M><L><%period>                                                 */ DEADTRANS( L'.'	,0xEDB8	,0x013F	,0x0000), // '.' ➔ "Ŀ" LATIN CAPITAL LETTER L WITH MIDDLE DOT
/*<!M><l><%period>                                                 */ DEADTRANS( L'.'	,0xEDB7	,0x0140	,0x0000), // '.' ➔ "ŀ" LATIN SMALL LETTER L WITH MIDDLE DOT
/*<!M><L><%slash>                                                  */ DEADTRANS( L'/'	,0xEDB8	,0x27C0	,0x0000), // '/' ➔ "⟀" THREE DIMENSIONAL ANGLE
/*<!M><L><%tilde>                                                  */ DEADTRANS( L'~'	,0xEDB8	,0x2112	,0x0000), // '~' ➔ "ℒ" SCRIPT CAPITAL L
/*<!M><l><%tilde>                                                  */ DEADTRANS( L'~'	,0xEDB7	,0x2113	,0x0000), // '~' ➔ "ℓ" SCRIPT SMALL L
/*<!M><l><2>                                                       */ DEADTRANS( L'2'	,0xEDB7	,0x21E7	,0x0000), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><L><2>                                                       */ DEADTRANS( L'2'	,0xEDB8	,0x21E7	,0x0000), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><l><3>                                                       */ DEADTRANS( L'3'	,0xEDB7	,0x026E	,0x0000), // '3' ➔ "ɮ" LATIN SMALL LETTER LEZH
/*<!M><L><3>                                                       */ DEADTRANS( L'3'	,0xEDB8	,0x21EE	,0x0000), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><l><5>                                                       */ DEADTRANS( L'5'	,0xEDB7	,0x27F0	,0x0000), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><L><5>                                                       */ DEADTRANS( L'5'	,0xEDB8	,0x27F0	,0x0000), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><l><a>                                                       */ DEADTRANS( L'a'	,0xEDB7	,0xEDE1	,0x0001), // Multikey chain
/*<!M><L><A>                                                       */ DEADTRANS( L'A'	,0xEDB8	,0xEDE2	,0x0001), // Multikey chain
/*<!M><l><a><k>                                                    */ DEADTRANS( L'k'	,0xEDE1	,0x20AD	,0x0000), // 'k' ➔ "₭" KIP SIGN, Lao Kip THE LAO PEOPLE’S DEMOCRATIC REPUBLIC
/*<!M><L><A><K>                                                    */ DEADTRANS( L'K'	,0xEDE2	,0x20AD	,0x0000), // 'K' ➔ "₭" KIP SIGN, Lao Kip THE LAO PEOPLE’S DEMOCRATIC REPUBLIC
/*<!M><l><b>                                                       */ DEADTRANS( L'b'	,0xEDB7	,0xEDE5	,0x0001), // Multikey chain
/*<!M><L><B>                                                       */ DEADTRANS( L'B'	,0xEDB8	,0xEDE6	,0x0001), // Multikey chain
/*<!M><l><b><%minus>                                               */ DEADTRANS( L'-'	,0xEDE5	,0x2114	,0x0000), // '-' ➔ "℔" L B BAR SYMBOL
/*<!M><l><d>                                                       */ DEADTRANS( L'd'	,0xEDB7	,0xEDEA	,0x0001), // Multikey chain
/*<!M><L><D>                                                       */ DEADTRANS( L'D'	,0xEDB8	,0xEDEB	,0x0001), // Multikey chain
/*<!M><l><d><p>                                                    */ DEADTRANS( L'p'	,0xEDEA	,0xEDEC	,0x0001), // Multikey chain
/*<!M><L><D><P>                                                    */ DEADTRANS( L'P'	,0xEDEB	,0xEDED	,0x0001), // Multikey chain
/*<!M><l><d><p><e>                                                 */ DEADTRANS( L'e'	,0xEDEC	,0x2676	,0x0000), // 'e' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><L><D><P><E>                                                 */ DEADTRANS( L'E'	,0xEDED	,0x2676	,0x0000), // 'E' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><l><e>                                                       */ DEADTRANS( L'e'	,0xEDB7	,0xEDF0	,0x0001), // Multikey chain
/*<!M><L><E>                                                       */ DEADTRANS( L'E'	,0xEDB8	,0xEDF1	,0x0001), // Multikey chain
/*<!M><l><e><o>                                                    */ DEADTRANS( L'o'	,0xEDF0	,0x264C	,0x0000), // 'o' ➔ "♌" LEO emoji
/*<!M><L><E><O>                                                    */ DEADTRANS( L'O'	,0xEDF1	,0x264C	,0x0000), // 'O' ➔ "♌" LEO emoji
/*<!M><l><e><z>                                                    */ DEADTRANS( L'z'	,0xEDF0	,0xEDF4	,0x0001), // Multikey chain
/*<!M><l><e><z><h>                                                 */ DEADTRANS( L'h'	,0xEDF4	,0x026E	,0x0000), // 'h' ➔ "ɮ" LATIN SMALL LETTER LEZH
/*<!M><l><f>                                                       */ DEADTRANS( L'f'	,0xEDB7	,0x21B4	,0x0000), // 'f' ➔ "↴" RIGHTWARDS ARROW WITH CORNER DOWNWARDS
/*<!M><L><F>                                                       */ DEADTRANS( L'F'	,0xEDB8	,0x21B4	,0x0000), // 'F' ➔ "↴" RIGHTWARDS ARROW WITH CORNER DOWNWARDS
/*<!M><l><i>                                                       */ DEADTRANS( L'i'	,0xEDB7	,0xEDF8	,0x0001), // Multikey chain
/*<!M><L><I>                                                       */ DEADTRANS( L'I'	,0xEDB8	,0xEDF9	,0x0001), // Multikey chain
/*<!M><l><i><b>                                                    */ DEADTRANS( L'b'	,0xEDF8	,0xEDFA	,0x0001), // Multikey chain
/*<!M><L><I><B>                                                    */ DEADTRANS( L'B'	,0xEDF9	,0xEDFB	,0x0001), // Multikey chain
/*<!M><l><i><b><r>                                                 */ DEADTRANS( L'r'	,0xEDFA	,0x264E	,0x0000), // 'r' ➔ "♎" LIBRA emoji
/*<!M><L><I><B><R>                                                 */ DEADTRANS( L'R'	,0xEDFB	,0x264E	,0x0000), // 'R' ➔ "♎" LIBRA emoji
/*<!M><l><i><o>                                                    */ DEADTRANS( L'o'	,0xEDF8	,0xEDFE	,0x0001), // Multikey chain
/*<!M><L><I><O>                                                    */ DEADTRANS( L'O'	,0xEDF9	,0xEDFF	,0x0001), // Multikey chain
/*<!M><l><i><o><n>                                                 */ DEADTRANS( L'n'	,0xEDFE	,0x264C	,0x0000), // 'n' ➔ "♌" LEO emoji
/*<!M><L><I><O><N>                                                 */ DEADTRANS( L'N'	,0xEDFF	,0x264C	,0x0000), // 'N' ➔ "♌" LEO emoji
/*<!M><L><J>                                                       */ DEADTRANS( L'J'	,0xEDB8	,0x01C7	,0x0000), // 'J' ➔ "Ǉ" LATIN CAPITAL LETTER LJ
/*<!M><L><j>                                                       */ DEADTRANS( L'j'	,0xEDB8	,0x01C8	,0x0000), // 'j' ➔ "ǈ" LATIN CAPITAL LETTER L WITH SMALL LETTER J
/*<!M><l><j>                                                       */ DEADTRANS( L'j'	,0xEDB7	,0x01C9	,0x0000), // 'j' ➔ "ǉ" LATIN SMALL LETTER LJ
/*<!M><L><L>                                                       */ DEADTRANS( L'L'	,0xEDB8	,0x1EFA	,0x0000), // 'L' ➔ "Ỻ" LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*<!M><L><l>                                                       */ DEADTRANS( L'l'	,0xEDB8	,0x1EFA	,0x0000), // 'l' ➔ "Ỻ" LATIN CAPITAL LETTER MIDDLE-WELSH LL
/*<!M><l><l>                                                       */ DEADTRANS( L'l'	,0xEDB7	,0x1EFB	,0x0000), // 'l' ➔ "ỻ" LATIN SMALL LETTER MIDDLE-WELSH LL
/*<!M><L><N>                                                       */ DEADTRANS( L'N'	,0xEDB8	,0x237C	,0x0000), // 'N' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L><p>                                                       */ DEADTRANS( L'p'	,0xEDB8	,0xEE0B	,0x0001), // Multikey chain
/*<!M><L><P>                                                       */ DEADTRANS( L'P'	,0xEDB8	,0x214A	,0x0000), // 'P' ➔ "⅊" PROPERTY LINE
/*<!M><l><p>                                                       */ DEADTRANS( L'p'	,0xEDB7	,0x214A	,0x0000), // 'p' ➔ "⅊" PROPERTY LINE
/*<!M><L><p><a>                                                    */ DEADTRANS( L'a'	,0xEE0B	,0xEE0C	,0x0001), // Multikey chain
/*<!M><L><p><a><r>                                                 */ DEADTRANS( L'r'	,0xEE0C	,0xEE0D	,0x0001), // Multikey chain
/*<!M><L><p><a><r><e>                                              */ DEADTRANS( L'e'	,0xEE0D	,0xEE0E	,0x0001), // Multikey chain
/*<!M><L><p><a><r><e><n>                                           */ DEADTRANS( L'n'	,0xEE0E	,0xEE0F	,0x0001), // Multikey chain
/*<!M><L><p><a><r><e><n><g>                                        */ DEADTRANS( L'g'	,0xEE0F	,0xEE10	,0x0001), // Multikey chain
/*<!M><L><p><a><r><e><n><g><t>                                     */ DEADTRANS( L't'	,0xEE10	,0x2995	,0x0000), // 't' ➔ "⦕" DOUBLE LEFT ARC GREATER-THAN BRACKET TeX + HTML under max 9 keysym constraint
/*<!M><l><r>                                                       */ DEADTRANS( L'r'	,0xEDB7	,0xEE12	,0x0001), // Multikey chain
/*<!M><L><R>                                                       */ DEADTRANS( L'R'	,0xEDB8	,0xEE13	,0x0001), // Multikey chain
/*<!M><l><r><e>                                                    */ DEADTRANS( L'e'	,0xEE12	,0xEE14	,0x0001), // Multikey chain
/*<!M><L><R><E>                                                    */ DEADTRANS( L'E'	,0xEE13	,0xEE15	,0x0001), // Multikey chain
/*<!M><l><r><e><t>                                                 */ DEADTRANS( L't'	,0xEE14	,0x2BA0	,0x0000), // 't' ➔ "⮠" DOWNWARDS TRIANGLE-HEADED ARROW WITH LONG TIP LEFTWARDS
/*<!M><L><R><E><T>                                                 */ DEADTRANS( L'T'	,0xEE15	,0x2BA0	,0x0000), // 'T' ➔ "⮠" DOWNWARDS TRIANGLE-HEADED ARROW WITH LONG TIP LEFTWARDS
/*<!M><l><s>                                                       */ DEADTRANS( L's'	,0xEDB7	,0x02AA	,0x0000), // 's' ➔ "ʪ" LATIN SMALL LETTER LS DIGRAPH
/*<!M><l><u>                                                       */ DEADTRANS( L'u'	,0xEDB7	,0xA772	,0x0000), // 'u' ➔ "ꝲ" LATIN SMALL LETTER LUM
/*<!M><l><z>                                                       */ DEADTRANS( L'z'	,0xEDB7	,0x02AB	,0x0000), // 'z' ➔ "ʫ" LATIN SMALL LETTER LZ DIGRAPH
/*<!M><L><Z>                                                       */ DEADTRANS( L'Z'	,0xEDB8	,0x237C	,0x0000), // 'Z' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L><z>                                                       */ DEADTRANS( L'z'	,0xEDB8	,0x237C	,0x0000), // 'z' ➔ "⍼" RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW
/*<!M><L><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEDB8	,0x221F	,0x0000), // ' ' ➔ "∟" RIGHT ANGLE
/*<!M><L><~space>                                                  */ DEADTRANS( L' '	,0xEDB8	,0x221F	,0x0000), // ' ' ➔ "∟" RIGHT ANGLE
/*<!M><m>                                                          */ DEADTRANS( L'm'	,0x00A6	,0xEE1F	,0x0001), // Multikey chain
/*<!M><M>                                                          */ DEADTRANS( L'M'	,0x00A6	,0xEE20	,0x0001), // Multikey chain
/*<!M><m><%equal>                                                  */ DEADTRANS( L'='	,0xEE1F	,0x225E	,0x0000), // '=' ➔ "≞" MEASURED BY
/*<!M><m><%greater>                                                */ DEADTRANS( L'>'	,0xEE1F	,0x200E	,0x0000), // '>' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><m><%less>                                                   */ DEADTRANS( L'<'	,0xEE1F	,0x200F	,0x0000), // '<' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><m><%percent>                                                */ DEADTRANS( L'%'	,0xEE1F	,0x29E2	,0x0000), // '%' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><m><%slash>                                                  */ DEADTRANS( L'/'	,0xEE1F	,0x20A5	,0x0000), // '/' ➔ "₥" MILL SIGN
/*<!M><M><%tilde>                                                  */ DEADTRANS( L'~'	,0xEE20	,0x2133	,0x0000), // '~' ➔ "ℳ" SCRIPT CAPITAL M
/*<!M><m><c>                                                       */ DEADTRANS( L'c'	,0xEE1F	,0xDD6A	,0x0000), // High surrogate: D83C; U+1F16A 'c' ➔ "🅪" RAISED MC SIGN
/*<!M><M><C>                                                       */ DEADTRANS( L'C'	,0xEE20	,0xDD6A	,0x0000), // High surrogate: D83C; U+1F16A 'C' ➔ "🅪" RAISED MC SIGN
/*<!M><m><d>                                                       */ DEADTRANS( L'd'	,0xEE1F	,0xDD6B	,0x0000), // High surrogate: D83C; U+1F16B 'd' ➔ "🅫" RAISED MD SIGN
/*<!M><M><D>                                                       */ DEADTRANS( L'D'	,0xEE20	,0xDD6B	,0x0000), // High surrogate: D83C; U+1F16B 'D' ➔ "🅫" RAISED MD SIGN
/*<!M><m><h>                                                       */ DEADTRANS( L'h'	,0xEE1F	,0x2127	,0x0000), // 'h' ➔ "℧" INVERTED OHM SIGN
/*<!M><M><h>                                                       */ DEADTRANS( L'h'	,0xEE20	,0x2127	,0x0000), // 'h' ➔ "℧" INVERTED OHM SIGN
/*<!M><M><H>                                                       */ DEADTRANS( L'H'	,0xEE20	,0x2127	,0x0000), // 'H' ➔ "℧" INVERTED OHM SIGN
/*<!M><m><k>                                                       */ DEADTRANS( L'k'	,0xEE1F	,0xEE2E	,0x0001), // Multikey chain
/*<!M><M><K>                                                       */ DEADTRANS( L'K'	,0xEE20	,0xEE2F	,0x0001), // Multikey chain
/*<!M><m><n>                                                       */ DEADTRANS( L'n'	,0xEE1F	,0xEE32	,0x0001), // Multikey chain
/*<!M><M><N>                                                       */ DEADTRANS( L'N'	,0xEE20	,0xEE33	,0x0001), // Multikey chain
/*<!M><m><n><t>                                                    */ DEADTRANS( L't'	,0xEE32	,0x20AE	,0x0000), // 't' ➔ "₮" TUGRIK SIGN, Tugrik MONGOLIA
/*<!M><M><N><T>                                                    */ DEADTRANS( L'T'	,0xEE33	,0x20AE	,0x0000), // 'T' ➔ "₮" TUGRIK SIGN, Tugrik MONGOLIA
/*<!M><m><r>                                                       */ DEADTRANS( L'r'	,0xEE1F	,0xDD6C	,0x0000), // High surrogate: D83C; U+1F16C 'r' ➔ "🅬" RAISED MR SIGN
/*<!M><M><R>                                                       */ DEADTRANS( L'R'	,0xEE20	,0xDD6C	,0x0000), // High surrogate: D83C; U+1F16C 'R' ➔ "🅬" RAISED MR SIGN
/*<!M><m><s>                                                       */ DEADTRANS( L's'	,0xEE1F	,0x2120	,0x0000), // 's' ➔ "℠" SERVICE MARK
/*<!M><M><S>                                                       */ DEADTRANS( L'S'	,0xEE20	,0x2120	,0x0000), // 'S' ➔ "℠" SERVICE MARK
/*<!M><m><t>                                                       */ DEADTRANS( L't'	,0xEE1F	,0x2122	,0x0000), // 't' ➔ "™" TRADE MARK SIGN emoji
/*<!M><M><T>                                                       */ DEADTRANS( L'T'	,0xEE20	,0x2122	,0x0000), // 'T' ➔ "™" TRADE MARK SIGN emoji
/*<!M><m><u>                                                       */ DEADTRANS( L'u'	,0xEE1F	,0xEE3C	,0x0001), // Multikey chain
/*<!M><M><U>                                                       */ DEADTRANS( L'U'	,0xEE20	,0xEE3D	,0x0001), // Multikey chain
/*<!M><m><u><l>                                                    */ DEADTRANS( L'l'	,0xEE3C	,0x00A6	,0x0000), // 'l' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><M><U><L>                                                    */ DEADTRANS( L'L'	,0xEE3D	,0x00A6	,0x0000), // 'L' ➔ "¦" BROKEN BAR repurposed as multikey symbol
/*<!M><m><u><r>                                                    */ DEADTRANS( L'r'	,0xEE3C	,0x20A8	,0x0000), // 'r' ➔ "₨" RUPEE SIGN, Mauritius Rupee MAURITIUS
/*<!M><M><U><R>                                                    */ DEADTRANS( L'R'	,0xEE3D	,0x20A8	,0x0000), // 'R' ➔ "₨" RUPEE SIGN, Mauritius Rupee MAURITIUS
/*<!M><m><u><~space>                                               */ DEADTRANS( L' '	,0xEE3C	,0xA773	,0x0000), // ' ' ➔ "ꝳ" LATIN SMALL LETTER MUM
/*<!M><m><v>                                                       */ DEADTRANS( L'v'	,0xEE1F	,0xEE43	,0x0001), // Multikey chain
/*<!M><M><V>                                                       */ DEADTRANS( L'V'	,0xEE20	,0xEE44	,0x0001), // Multikey chain
/*<!M><m><v><r>                                                    */ DEADTRANS( L'r'	,0xEE43	,0x0783	,0x0000), // 'r' ➔ "ރ" THAANA LETTER RAA, Rufiyaa MALDIVES
/*<!M><M><V><R>                                                    */ DEADTRANS( L'R'	,0xEE44	,0x0783	,0x0000), // 'R' ➔ "ރ" THAANA LETTER RAA, Rufiyaa MALDIVES
/*<!M><m><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEE1F	,0x29E2	,0x0000), // ' ' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><m><~space>                                                  */ DEADTRANS( L' '	,0xEE1F	,0x29E2	,0x0000), // ' ' ➔ "⧢" SHUFFLE PRODUCT
/*<!M><multiply>                                                   */ DEADTRANS( 0x00D7	,0x00A6	,0xEE49	,0x0001), // Multikey chain
/*<!M><multiply><division>                                         */ DEADTRANS( 0x00F7	,0xEE49	,0x22C7	,0x0000), // '÷' ➔ "⋇" DIVISION TIMES
/*<!M><N>                                                          */ DEADTRANS( L'N'	,0x00A6	,0xEE4B	,0x0001), // Multikey chain
/*<!M><n>                                                          */ DEADTRANS( L'n'	,0x00A6	,0xEE4C	,0x0001), // Multikey chain
/*<!M><n><%bar>                                                    */ DEADTRANS( L'|'	,0xEE4C	,0x22D4	,0x0000), // '|' ➔ "⋔" PITCHFORK
/*<!M><n><%bracketleft>                                            */ DEADTRANS( L'['	,0xEE4C	,0x2293	,0x0000), // '[' ➔ "⊓" SQUARE CAP
/*<!M><N><%bracketleft>                                            */ DEADTRANS( L'['	,0xEE4B	,0x2A05	,0x0000), // '[' ➔ "⨅" N-ARY SQUARE INTERSECTION OPERATOR
/*<!M><n><%bracketright>                                           */ DEADTRANS( L']'	,0xEE4C	,0x2293	,0x0000), // ']' ➔ "⊓" SQUARE CAP
/*<!M><N><%bracketright>                                           */ DEADTRANS( L']'	,0xEE4B	,0x2A05	,0x0000), // ']' ➔ "⨅" N-ARY SQUARE INTERSECTION OPERATOR
/*<!M><n><%circum>                                                 */ DEADTRANS( L'^'	,0xEE4C	,0x2A44	,0x0000), // '^' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><N><%equal>                                                  */ DEADTRANS( L'='	,0xEE4B	,0x20A6	,0x0000), // '=' ➔ "₦" NAIRA SIGN
/*<!M><n><%equal>                                                  */ DEADTRANS( L'='	,0xEE4C	,0x266C	,0x0000), // '=' ➔ "♬" BEAMED SIXTEENTH NOTES
/*<!M><N><%greater>                                                */ DEADTRANS( L'>'	,0xEE4B	,0x21AF	,0x0000), // '>' ➔ "↯" DOWNWARDS ZIGZAG ARROW
/*<!M><n><%greater>                                                */ DEADTRANS( L'>'	,0xEE4C	,0x21B7	,0x0000), // '>' ➔ "↷" CLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><n><%hash>                                                   */ DEADTRANS( L'#'	,0xEE4C	,0x266E	,0x0000), // '#' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><n><%less>                                                   */ DEADTRANS( L'<'	,0xEE4C	,0x21B6	,0x0000), // '<' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><n><%period>                                                 */ DEADTRANS( L'.'	,0xEE4C	,0x2A40	,0x0000), // '.' ➔ "⩀" INTERSECTION WITH DOT
/*<!M><n><%underscore>                                             */ DEADTRANS( L'_'	,0xEE4C	,0xEE5A	,0x0001), // Multikey chain
/*<!M><n><%underscore><u>                                          */ DEADTRANS( L'u'	,0xEE5A	,0x2A49	,0x0000), // 'u' ➔ "⩉" INTERSECTION ABOVE BAR ABOVE UNION
/*<!M><n><%underscore><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xEE5A	,0x2A4D	,0x0000), // ' ' ➔ "⩍" CLOSED INTERSECTION WITH SERIFS
/*<!M><n><%underscore><~space>                                     */ DEADTRANS( L' '	,0xEE5A	,0x2A4D	,0x0000), // ' ' ➔ "⩍" CLOSED INTERSECTION WITH SERIFS
/*<!M><n><2>                                                       */ DEADTRANS( L'2'	,0xEE4C	,0x21E7	,0x0000), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><N><2>                                                       */ DEADTRANS( L'2'	,0xEE4B	,0x21E7	,0x0000), // '2' ➔ "⇧" UPWARDS WHITE ARROW, shift
/*<!M><n><3>                                                       */ DEADTRANS( L'3'	,0xEE4C	,0x21EE	,0x0000), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><N><3>                                                       */ DEADTRANS( L'3'	,0xEE4B	,0x21EE	,0x0000), // '3' ➔ "⇮" UPWARDS WHITE DOUBLE ARROW, level-3 select
/*<!M><n><4>                                                       */ DEADTRANS( L'4'	,0xEE4C	,0x2669	,0x0000), // '4' ➔ "♩" QUARTER NOTE
/*<!M><N><4>                                                       */ DEADTRANS( L'4'	,0xEE4B	,0x2669	,0x0000), // '4' ➔ "♩" QUARTER NOTE
/*<!M><n><5>                                                       */ DEADTRANS( L'5'	,0xEE4C	,0x27F0	,0x0000), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><N><5>                                                       */ DEADTRANS( L'5'	,0xEE4B	,0x27F0	,0x0000), // '5' ➔ "⟰" UPWARDS QUADRUPLE ARROW
/*<!M><n><8>                                                       */ DEADTRANS( L'8'	,0xEE4C	,0x266A	,0x0000), // '8' ➔ "♪" EIGHTH NOTE
/*<!M><N><8>                                                       */ DEADTRANS( L'8'	,0xEE4B	,0x266A	,0x0000), // '8' ➔ "♪" EIGHTH NOTE
/*<!M><n><a>                                                       */ DEADTRANS( L'a'	,0xEE4C	,0xEE69	,0x0001), // Multikey chain
/*<!M><N><A>                                                       */ DEADTRANS( L'A'	,0xEE4B	,0x22BC	,0x0000), // 'A' ➔ "⊼" NAND
/*<!M><n><a><n>                                                    */ DEADTRANS( L'n'	,0xEE69	,0x22BC	,0x0000), // 'n' ➔ "⊼" NAND
/*<!M><n><a><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEE69	,0x2A44	,0x0000), // ' ' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><n><a><~space>                                               */ DEADTRANS( L' '	,0xEE69	,0x2A44	,0x0000), // ' ' ➔ "⩄" INTERSECTION WITH LOGICAL AND
/*<!M><n><b>                                                       */ DEADTRANS( L'b'	,0xEE4C	,0xEE6D	,0x0001), // Multikey chain
/*<!M><N><B>                                                       */ DEADTRANS( L'B'	,0xEE4B	,0xEE6E	,0x0001), // Multikey chain
/*<!M><n><b><s>                                                    */ DEADTRANS( L's'	,0xEE6D	,0x25BF	,0x0000), // 's' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><N><B><S>                                                    */ DEADTRANS( L'S'	,0xEE6E	,0x25BF	,0x0000), // 'S' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><n><b><t>                                                    */ DEADTRANS( L't'	,0xEE6D	,0x25BE	,0x0000), // 't' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><N><B><T>                                                    */ DEADTRANS( L'T'	,0xEE6E	,0x25BE	,0x0000), // 'T' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><n><e>                                                       */ DEADTRANS( L'e'	,0xEE4C	,0x2744	,0x0000), // 'e' ➔ "❄" SNOWFLAKE emoji
/*<!M><N><E>                                                       */ DEADTRANS( L'E'	,0xEE4B	,0x2744	,0x0000), // 'E' ➔ "❄" SNOWFLAKE emoji
/*<!M><N><G>                                                       */ DEADTRANS( L'G'	,0xEE4B	,0xEE76	,0x0001), // Multikey chain
/*<!M><n><g>                                                       */ DEADTRANS( L'g'	,0xEE4C	,0xEE77	,0x0001), // Multikey chain
/*<!M><N><g>                                                       */ DEADTRANS( L'g'	,0xEE4B	,0x014A	,0x0000), // 'g' ➔ "Ŋ" LATIN CAPITAL LETTER ENG
/*<!M><n><g><n>                                                    */ DEADTRANS( L'n'	,0xEE77	,0x20A6	,0x0000), // 'n' ➔ "₦" NAIRA SIGN, Naira NIGERIA
/*<!M><N><G><N>                                                    */ DEADTRANS( L'N'	,0xEE76	,0x20A6	,0x0000), // 'N' ➔ "₦" NAIRA SIGN, Naira NIGERIA
/*<!M><N><G><~space>                                               */ DEADTRANS( L' '	,0xEE76	,0x014A	,0x0000), // ' ' ➔ "Ŋ" LATIN CAPITAL LETTER ENG
/*<!M><n><g><~space>                                               */ DEADTRANS( L' '	,0xEE77	,0x014B	,0x0000), // ' ' ➔ "ŋ" LATIN SMALL LETTER ENG
/*<!M><n><I>                                                       */ DEADTRANS( L'I'	,0xEE4C	,0x2ADB	,0x0000), // 'I' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><N><J>                                                       */ DEADTRANS( L'J'	,0xEE4B	,0x01CA	,0x0000), // 'J' ➔ "Ǌ" LATIN CAPITAL LETTER NJ
/*<!M><N><j>                                                       */ DEADTRANS( L'j'	,0xEE4B	,0x01CB	,0x0000), // 'j' ➔ "ǋ" LATIN CAPITAL LETTER N WITH SMALL LETTER J
/*<!M><n><j>                                                       */ DEADTRANS( L'j'	,0xEE4C	,0x01CC	,0x0000), // 'j' ➔ "ǌ" LATIN SMALL LETTER NJ
/*<!M><n><m>                                                       */ DEADTRANS( L'm'	,0xEE4C	,0xEE80	,0x0001), // Multikey chain
/*<!M><N><M>                                                       */ DEADTRANS( L'M'	,0xEE4B	,0xEE81	,0x0001), // Multikey chain
/*<!M><n><m><l>                                                    */ DEADTRANS( L'l'	,0xEE80	,0x21ED	,0x0000), // 'l' ➔ "⇭" UPWARDS WHITE ARROW ON PEDESTAL WITH VERTICAL BAR, numeric lock
/*<!M><N><M><L>                                                    */ DEADTRANS( L'L'	,0xEE81	,0x21ED	,0x0000), // 'L' ➔ "⇭" UPWARDS WHITE ARROW ON PEDESTAL WITH VERTICAL BAR, numeric lock
/*<!M><N><N>                                                       */ DEADTRANS( L'N'	,0xEE4B	,0x2115	,0x0000), // 'N' ➔ "ℕ" DOUBLE-STRUCK CAPITAL N
/*<!M><n><n>                                                       */ DEADTRANS( L'n'	,0xEE4C	,0x2A4B	,0x0000), // 'n' ➔ "⩋" INTERSECTION BESIDE AND JOINED WITH INTERSECTION
/*<!M><n><o>                                                       */ DEADTRANS( L'o'	,0xEE4C	,0xEE88	,0x0001), // Multikey chain
/*<!M><N><O>                                                       */ DEADTRANS( L'O'	,0xEE4B	,0xEE89	,0x0001), // Multikey chain
/*<!M><N><o>                                                       */ DEADTRANS( L'o'	,0xEE4B	,0x2116	,0x0000), // 'o' ➔ "№" NUMERO SIGN
/*<!M><n><O>                                                       */ DEADTRANS( L'O'	,0xEE4C	,0x2116	,0x0000), // 'O' ➔ "№" NUMERO SIGN
/*<!M><n><o><%underscore>                                          */ DEADTRANS( L'_'	,0xEE88	,0x2116	,0x0000), // '_' ➔ "№" NUMERO SIGN
/*<!M><N><O><%underscore>                                          */ DEADTRANS( L'_'	,0xEE89	,0x2116	,0x0000), // '_' ➔ "№" NUMERO SIGN
/*<!M><n><o><r>                                                    */ DEADTRANS( L'r'	,0xEE88	,0x22BD	,0x0000), // 'r' ➔ "⊽" NOR
/*<!M><N><O><R>                                                    */ DEADTRANS( L'R'	,0xEE89	,0x22BD	,0x0000), // 'R' ➔ "⊽" NOR
/*<!M><n><p>                                                       */ DEADTRANS( L'p'	,0xEE4C	,0xEE8E	,0x0001), // Multikey chain
/*<!M><N><P>                                                       */ DEADTRANS( L'P'	,0xEE4B	,0xEE8F	,0x0001), // Multikey chain
/*<!M><n><s>                                                       */ DEADTRANS( L's'	,0xEE4C	,0x20AA	,0x0000), // 's' ➔ "₪" NEW SHEQEL SIGN
/*<!M><N><S>                                                       */ DEADTRANS( L'S'	,0xEE4B	,0x20AA	,0x0000), // 'S' ➔ "₪" NEW SHEQEL SIGN
/*<!M><n><u>                                                       */ DEADTRANS( L'u'	,0xEE4C	,0xEE94	,0x0001), // Multikey chain
/*<!M><n><u><m>                                                    */ DEADTRANS( L'm'	,0xEE94	,0xA774	,0x0000), // 'm' ➔ "ꝴ" LATIN SMALL LETTER NUM
/*<!M><n><u><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEE94	,0x2A47	,0x0000), // ' ' ➔ "⩇" INTERSECTION ABOVE UNION
/*<!M><n><u><~space>                                               */ DEADTRANS( L' '	,0xEE94	,0x2A47	,0x0000), // ' ' ➔ "⩇" INTERSECTION ABOVE UNION
/*<!M><n><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEE4C	,0x2229	,0x0000), // ' ' ➔ "∩" INTERSECTION
/*<!M><N><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEE4B	,0x22C2	,0x0000), // ' ' ➔ "⋂" N-ARY INTERSECTION
/*<!M><n><~space>                                                  */ DEADTRANS( L' '	,0xEE4C	,0x2229	,0x0000), // ' ' ➔ "∩" INTERSECTION
/*<!M><N><~space>                                                  */ DEADTRANS( L' '	,0xEE4B	,0x22C2	,0x0000), // ' ' ➔ "⋂" N-ARY INTERSECTION
/*<!M><o>                                                          */ DEADTRANS( L'o'	,0x00A6	,0xEE9C	,0x0001), // Multikey chain
/*<!M><O>                                                          */ DEADTRANS( L'O'	,0x00A6	,0xEE9D	,0x0001), // Multikey chain
/*<!M><o><%asterisk>                                               */ DEADTRANS( L'*'	,0xEE9C	,0x229B	,0x0000), // '*' ➔ "⊛" CIRCLED ASTERISK OPERATOR
/*<!M><O><%asterisk>                                               */ DEADTRANS( L'*'	,0xEE9D	,0x229B	,0x0000), // '*' ➔ "⊛" CIRCLED ASTERISK OPERATOR
/*<!M><o><%backslash>                                              */ DEADTRANS( L'\\'	,0xEE9C	,0xEEA0	,0x0001), // Multikey chain
/*<!M><O><%backslash>                                              */ DEADTRANS( L'\\'	,0xEE9D	,0xEEA1	,0x0001), // Multikey chain
/*<!M><o><%backslash><c>                                           */ DEADTRANS( L'c'	,0xEEA0	,0xDD6E	,0x0000), // High surrogate: D83C; U+1F16E 'c' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><o><%backslash><C>                                           */ DEADTRANS( L'C'	,0xEEA0	,0xDD6E	,0x0000), // High surrogate: D83C; U+1F16E 'C' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash><C>                                           */ DEADTRANS( L'C'	,0xEEA1	,0xDD6E	,0x0000), // High surrogate: D83C; U+1F16E 'C' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash><c>                                           */ DEADTRANS( L'c'	,0xEEA1	,0xDD6E	,0x0000), // High surrogate: D83C; U+1F16E 'c' ➔ "🅮" CIRCLED C WITH OVERLAID BACKSLASH
/*<!M><O><%backslash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xEEA1	,0x29B8	,0x0000), // ' ' ➔ "⦸" CIRCLED REVERSE SOLIDUS
/*<!M><o><%backslash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xEEA0	,0x29F5	,0x0000), // ' ' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><O><%backslash><~space>                                      */ DEADTRANS( L' '	,0xEEA1	,0x29B8	,0x0000), // ' ' ➔ "⦸" CIRCLED REVERSE SOLIDUS
/*<!M><o><%backslash><~space>                                      */ DEADTRANS( L' '	,0xEEA0	,0x29F5	,0x0000), // ' ' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><O><%bar>                                                    */ DEADTRANS( L'|'	,0xEE9D	,0xEEAA	,0x0001), // Multikey chain
/*<!M><o><%bar>                                                    */ DEADTRANS( L'|'	,0xEE9C	,0xEEAB	,0x0001), // Multikey chain
/*<!M><O><%bar><%bar>                                              */ DEADTRANS( L'|'	,0xEEAA	,0x29B7	,0x0000), // '|' ➔ "⦷" CIRCLED PARALLEL
/*<!M><O><%bar><%hash>                                             */ DEADTRANS( L'#'	,0xEEAA	,0x25D1	,0x0000), // '#' ➔ "◑" CIRCLE WITH RIGHT HALF BLACK
/*<!M><o><%bar><%underscore>                                       */ DEADTRANS( L'_'	,0xEEAB	,0x27DF	,0x0000), // '_' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><O><%bar><%underscore>                                       */ DEADTRANS( L'_'	,0xEEAA	,0x29B9	,0x0000), // '_' ➔ "⦹" CIRCLED PERPENDICULAR
/*<!M><O><%bar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEEAA	,0x29B6	,0x0000), // ' ' ➔ "⦶" CIRCLED VERTICAL BAR
/*<!M><o><%bar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEEAB	,0x2AEF	,0x0000), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><O><%bar><~space>                                            */ DEADTRANS( L' '	,0xEEAA	,0x29B6	,0x0000), // ' ' ➔ "⦶" CIRCLED VERTICAL BAR
/*<!M><o><%bar><~space>                                            */ DEADTRANS( L' '	,0xEEAB	,0x2AEF	,0x0000), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><%circum>                                                 */ DEADTRANS( L'^'	,0xEE9C	,0x2A22	,0x0000), // '^' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><o><%colon>                                                  */ DEADTRANS( L':'	,0xEE9C	,0xEEB5	,0x0001), // Multikey chain
/*<!M><O><%colon>                                                  */ DEADTRANS( L':'	,0xEE9D	,0xEEB6	,0x0001), // Multikey chain
/*<!M><O><%colon><%minus>                                          */ DEADTRANS( L'-'	,0xEEB6	,0x2A38	,0x0000), // '-' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%colon><%minus>                                          */ DEADTRANS( L'-'	,0xEEB5	,0x2A38	,0x0000), // '-' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><O><%colon><%slash>                                          */ DEADTRANS( L'/'	,0xEEB6	,0x29BC	,0x0000), // '/' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><o><%colon><%slash>                                          */ DEADTRANS( L'/'	,0xEEB5	,0x29BC	,0x0000), // '/' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><o><%colon><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEEB5	,0x2982	,0x0000), // ' ' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><o><%colon><~space>                                          */ DEADTRANS( L' '	,0xEEB5	,0x2982	,0x0000), // ' ' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><o><%equal>                                                  */ DEADTRANS( L'='	,0xEE9C	,0x2257	,0x0000), // '=' ➔ "≗" RING EQUAL TO
/*<!M><O><%equal>                                                  */ DEADTRANS( L'='	,0xEE9D	,0x29C3	,0x0000), // '=' ➔ "⧃" CIRCLE WITH TWO HORIZONTAL STROKES TO THE RIGHT
/*<!M><O><%exclam>                                                 */ DEADTRANS( L'!'	,0xEE9D	,0x29EC	,0x0000), // '!' ➔ "⧬" WHITE CIRCLE WITH DOWN ARROW
/*<!M><o><%greater>                                                */ DEADTRANS( L'>'	,0xEE9C	,0x2941	,0x0000), // '>' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><O><%greater>                                                */ DEADTRANS( L'>'	,0xEE9D	,0x29C1	,0x0000), // '>' ➔ "⧁" CIRCLED GREATER-THAN
/*<!M><o><%hash>                                                   */ DEADTRANS( L'#'	,0xEE9C	,0xEEC2	,0x0001), // Multikey chain
/*<!M><O><%hash>                                                   */ DEADTRANS( L'#'	,0xEE9D	,0xEEC3	,0x0001), // Multikey chain
/*<!M><O><%hash><%bar>                                             */ DEADTRANS( L'|'	,0xEEC3	,0x25D0	,0x0000), // '|' ➔ "◐" CIRCLE WITH LEFT HALF BLACK
/*<!M><O><%hash><%exclam>                                          */ DEADTRANS( L'!'	,0xEEC3	,0x29ED	,0x0000), // '!' ➔ "⧭" BLACK CIRCLE WITH DOWN ARROW
/*<!M><O><%hash><%minus>                                           */ DEADTRANS( L'-'	,0xEEC3	,0x25D3	,0x0000), // '-' ➔ "◓" CIRCLE WITH UPPER HALF BLACK
/*<!M><o><%hash><e>                                                */ DEADTRANS( L'e'	,0xEEC2	,0xAB62	,0x0000), // 'e' ➔ "ꭢ" LATIN SMALL LETTER OPEN OE
/*<!M><O><%hash><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xEEC3	,0x25CF	,0x0000), // ' ' ➔ "●" BLACK CIRCLE
/*<!M><O><%hash><~space>                                           */ DEADTRANS( L' '	,0xEEC3	,0x25CF	,0x0000), // ' ' ➔ "●" BLACK CIRCLE
/*<!M><O><%less>                                                   */ DEADTRANS( L'<'	,0xEE9D	,0xEECB	,0x0001), // Multikey chain
/*<!M><o><%less>                                                   */ DEADTRANS( L'<'	,0xEE9C	,0x2940	,0x0000), // '<' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><O><%less><%exclam>                                          */ DEADTRANS( L'!'	,0xEECB	,0x29BD	,0x0000), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><O><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xEECB	,0x29C0	,0x0000), // ' ' ➔ "⧀" CIRCLED LESS-THAN
/*<!M><O><%less><~space>                                           */ DEADTRANS( L' '	,0xEECB	,0x29C0	,0x0000), // ' ' ➔ "⧀" CIRCLED LESS-THAN
/*<!M><o><%minus>                                                  */ DEADTRANS( L'-'	,0xEE9C	,0xEECF	,0x0001), // Multikey chain
/*<!M><O><%minus>                                                  */ DEADTRANS( L'-'	,0xEE9D	,0xEED0	,0x0001), // Multikey chain
/*<!M><O><%minus><%bar>                                            */ DEADTRANS( L'|'	,0xEED0	,0x29BA	,0x0000), // '|' ➔ "⦺" CIRCLE DIVIDED BY HORIZONTAL BAR AND TOP HALF DIVIDED BY VERTICAL BAR
/*<!M><O><%minus><%colon>                                          */ DEADTRANS( L':'	,0xEED0	,0x2A38	,0x0000), // ':' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%minus><%colon>                                          */ DEADTRANS( L':'	,0xEECF	,0x2A38	,0x0000), // ':' ➔ "⨸" CIRCLED DIVISION SIGN
/*<!M><o><%minus><%greater>                                        */ DEADTRANS( L'>'	,0xEECF	,0x21AC	,0x0000), // '>' ➔ "↬" RIGHTWARDS ARROW WITH LOOP
/*<!M><O><%minus><%hash>                                           */ DEADTRANS( L'#'	,0xEED0	,0x25D2	,0x0000), // '#' ➔ "◒" CIRCLE WITH LOWER HALF BLACK
/*<!M><o><%minus><%minus>                                          */ DEADTRANS( L'-'	,0xEECF	,0x229D	,0x0000), // '-' ➔ "⊝" CIRCLED DASH
/*<!M><o><%minus><%period>                                         */ DEADTRANS( L'.'	,0xEECF	,0x22B6	,0x0000), // '.' ➔ "⊶" ORIGINAL OF
/*<!M><o><%minus><o>                                               */ DEADTRANS( L'o'	,0xEECF	,0x29DF	,0x0000), // 'o' ➔ "⧟" DOUBLE-ENDED MULTIMAP
/*<!M><o><%minus><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEECF	,0x2296	,0x0000), // ' ' ➔ "⊖" CIRCLED MINUS
/*<!M><O><%minus><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEED0	,0x29B5	,0x0000), // ' ' ➔ "⦵" CIRCLE WITH HORIZONTAL BAR
/*<!M><o><%minus><~space>                                          */ DEADTRANS( L' '	,0xEECF	,0x2296	,0x0000), // ' ' ➔ "⊖" CIRCLED MINUS
/*<!M><O><%minus><~space>                                          */ DEADTRANS( L' '	,0xEED0	,0x29B5	,0x0000), // ' ' ➔ "⦵" CIRCLE WITH HORIZONTAL BAR
/*<!M><o><%parenright>                                             */ DEADTRANS( L')'	,0xEE9C	,0x29DC	,0x0000), // ')' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><O><%percent>                                                */ DEADTRANS( L'%'	,0xEE9D	,0xEEDF	,0x0001), // Multikey chain
/*<!M><o><%percent>                                                */ DEADTRANS( L'%'	,0xEE9C	,0x2127	,0x0000), // '%' ➔ "℧" INVERTED OHM SIGN
/*<!M><O><%percent><C>                                             */ DEADTRANS( L'C'	,0xEEDF	,0xDD2F	,0x0000), // High surrogate: D83C; U+1F12F 'C' ➔ "🄯" COPYLEFT SYMBOL
/*<!M><O><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xEEDF	,0x2127	,0x0000), // ' ' ➔ "℧" INVERTED OHM SIGN
/*<!M><O><%percent><~space>                                        */ DEADTRANS( L' '	,0xEEDF	,0x2127	,0x0000), // ' ' ➔ "℧" INVERTED OHM SIGN
/*<!M><o><%period>                                                 */ DEADTRANS( L'.'	,0xEE9C	,0x2299	,0x0000), // '.' ➔ "⊙" CIRCLED DOT OPERATOR
/*<!M><O><%period>                                                 */ DEADTRANS( L'.'	,0xEE9D	,0x2A00	,0x0000), // '.' ➔ "⨀" N-ARY CIRCLED DOT OPERATOR
/*<!M><o><%plus>                                                   */ DEADTRANS( L'+'	,0xEE9C	,0xEEE5	,0x0001), // Multikey chain
/*<!M><O><%plus>                                                   */ DEADTRANS( L'+'	,0xEE9D	,0xEEE6	,0x0001), // Multikey chain
/*<!M><o><%plus><%minus>                                           */ DEADTRANS( L'-'	,0xEEE5	,0x27F4	,0x0000), // '-' ➔ "⟴" RIGHT ARROW WITH CIRCLED PLUS
/*<!M><O><%plus><%minus>                                           */ DEADTRANS( L'-'	,0xEEE6	,0x27F4	,0x0000), // '-' ➔ "⟴" RIGHT ARROW WITH CIRCLED PLUS
/*<!M><o><%plus><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xEEE5	,0x2295	,0x0000), // ' ' ➔ "⊕" CIRCLED PLUS
/*<!M><O><%plus><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xEEE6	,0x2A01	,0x0000), // ' ' ➔ "⨁" N-ARY CIRCLED PLUS OPERATOR
/*<!M><o><%plus><~space>                                           */ DEADTRANS( L' '	,0xEEE5	,0x2295	,0x0000), // ' ' ➔ "⊕" CIRCLED PLUS
/*<!M><O><%plus><~space>                                           */ DEADTRANS( L' '	,0xEEE6	,0x2A01	,0x0000), // ' ' ➔ "⨁" N-ARY CIRCLED PLUS OPERATOR
/*<!M><o><%semicolon>                                              */ DEADTRANS( L';'	,0xEE9C	,0x2A1F	,0x0000), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><o><%semsection>                                             */ DEADTRANS( 0x00A7	,0xEE9C	,0x2A1F	,0x0000), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><o><%slash>                                                  */ DEADTRANS( L'/'	,0xEE9C	,0xEEF0	,0x0001), // Multikey chain
/*<!M><O><%slash>                                                  */ DEADTRANS( L'/'	,0xEE9D	,0x2205	,0x0000), // '/' ➔ "∅" EMPTY SET
/*<!M><o><%slash><%greater>                                        */ DEADTRANS( L'>'	,0xEEF0	,0x2642	,0x0000), // '>' ➔ "♂" MALE SIGN
/*<!M><o><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xEEF0	,0x2300	,0x0000), // ' ' ➔ "⌀" DIAMETER SIGN
/*<!M><o><%slash><~space>                                          */ DEADTRANS( L' '	,0xEEF0	,0x2300	,0x0000), // ' ' ➔ "⌀" DIAMETER SIGN
/*<!M><o><%tilde>                                                  */ DEADTRANS( L'~'	,0xEE9C	,0x2134	,0x0000), // '~' ➔ "ℴ" SCRIPT SMALL O
/*<!M><o><%underscore>                                             */ DEADTRANS( L'_'	,0xEE9C	,0x00BA	,0x0000), // '_' ➔ "º" MASCULINE ORDINAL INDICATOR
/*<!M><O><%underscore>                                             */ DEADTRANS( L'_'	,0xEE9D	,0x00BA	,0x0000), // '_' ➔ "º" MASCULINE ORDINAL INDICATOR
/*<!M><o><0>                                                       */ DEADTRANS( L'0'	,0xEE9C	,0x2469	,0x0000), // '0' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><O><0>                                                       */ DEADTRANS( L'0'	,0xEE9D	,0x2469	,0x0000), // '0' ➔ "⑩" CIRCLED NUMBER TEN
/*<!M><o><1>                                                       */ DEADTRANS( L'1'	,0xEE9C	,0x2460	,0x0000), // '1' ➔ "①" CIRCLED DIGIT ONE
/*<!M><O><1>                                                       */ DEADTRANS( L'1'	,0xEE9D	,0x2460	,0x0000), // '1' ➔ "①" CIRCLED DIGIT ONE
/*<!M><o><2>                                                       */ DEADTRANS( L'2'	,0xEE9C	,0x2461	,0x0000), // '2' ➔ "②" CIRCLED DIGIT TWO
/*<!M><O><2>                                                       */ DEADTRANS( L'2'	,0xEE9D	,0x2461	,0x0000), // '2' ➔ "②" CIRCLED DIGIT TWO
/*<!M><o><3>                                                       */ DEADTRANS( L'3'	,0xEE9C	,0x2462	,0x0000), // '3' ➔ "③" CIRCLED DIGIT THREE
/*<!M><O><3>                                                       */ DEADTRANS( L'3'	,0xEE9D	,0x2462	,0x0000), // '3' ➔ "③" CIRCLED DIGIT THREE
/*<!M><o><4>                                                       */ DEADTRANS( L'4'	,0xEE9C	,0x2463	,0x0000), // '4' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><O><4>                                                       */ DEADTRANS( L'4'	,0xEE9D	,0x2463	,0x0000), // '4' ➔ "④" CIRCLED DIGIT FOUR
/*<!M><o><5>                                                       */ DEADTRANS( L'5'	,0xEE9C	,0x2464	,0x0000), // '5' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><O><5>                                                       */ DEADTRANS( L'5'	,0xEE9D	,0x2464	,0x0000), // '5' ➔ "⑤" CIRCLED DIGIT FIVE
/*<!M><o><6>                                                       */ DEADTRANS( L'6'	,0xEE9C	,0x2465	,0x0000), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><O><6>                                                       */ DEADTRANS( L'6'	,0xEE9D	,0x2465	,0x0000), // '6' ➔ "⑥" CIRCLED DIGIT SIX
/*<!M><o><7>                                                       */ DEADTRANS( L'7'	,0xEE9C	,0x2466	,0x0000), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><O><7>                                                       */ DEADTRANS( L'7'	,0xEE9D	,0x2466	,0x0000), // '7' ➔ "⑦" CIRCLED DIGIT SEVEN
/*<!M><o><8>                                                       */ DEADTRANS( L'8'	,0xEE9C	,0x2467	,0x0000), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><O><8>                                                       */ DEADTRANS( L'8'	,0xEE9D	,0x2467	,0x0000), // '8' ➔ "⑧" CIRCLED DIGIT EIGHT
/*<!M><o><9>                                                       */ DEADTRANS( L'9'	,0xEE9C	,0x2468	,0x0000), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><O><9>                                                       */ DEADTRANS( L'9'	,0xEE9D	,0x2468	,0x0000), // '9' ➔ "⑨" CIRCLED DIGIT NINE
/*<!M><o><A>                                                       */ DEADTRANS( L'A'	,0xEE9C	,0x212B	,0x0000), // 'A' ➔ "Å" ANGSTROM SIGN
/*<!M><o><a>                                                       */ DEADTRANS( L'a'	,0xEE9C	,0x212B	,0x0000), // 'a' ➔ "Å" ANGSTROM SIGN
/*<!M><O><A>                                                       */ DEADTRANS( L'A'	,0xEE9D	,0x212B	,0x0000), // 'A' ➔ "Å" ANGSTROM SIGN
/*<!M><O><a>                                                       */ DEADTRANS( L'a'	,0xEE9D	,0x212B	,0x0000), // 'a' ➔ "Å" ANGSTROM SIGN
/*<!M><o><b>                                                       */ DEADTRANS( L'b'	,0xEE9C	,0xDD6F	,0x0000), // High surrogate: D83C; U+1F16F 'b' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><O><b>                                                       */ DEADTRANS( L'b'	,0xEE9D	,0xDD6F	,0x0000), // High surrogate: D83C; U+1F16F 'b' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><O><B>                                                       */ DEADTRANS( L'B'	,0xEE9D	,0xDD6F	,0x0000), // High surrogate: D83C; U+1F16F 'B' ➔ "🅯" CIRCLED HUMAN FIGURE
/*<!M><o><c>                                                       */ DEADTRANS( L'c'	,0xEE9C	,0x00A9	,0x0000), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><O><c>                                                       */ DEADTRANS( L'c'	,0xEE9D	,0x00A9	,0x0000), // 'c' ➔ "©" COPYRIGHT SIGN emoji
/*<!M><o><C>                                                       */ DEADTRANS( L'C'	,0xEE9C	,0xDD6D	,0x0000), // High surrogate: D83C; U+1F16D 'C' ➔ "🅭" CIRCLED CC
/*<!M><O><C>                                                       */ DEADTRANS( L'C'	,0xEE9D	,0xDD6D	,0x0000), // High surrogate: D83C; U+1F16D 'C' ➔ "🅭" CIRCLED CC
/*<!M><O><E>                                                       */ DEADTRANS( L'E'	,0xEE9D	,0x0152	,0x0000), // 'E' ➔ "Œ" LATIN CAPITAL LIGATURE OE
/*<!M><O><e>                                                       */ DEADTRANS( L'e'	,0xEE9D	,0x0152	,0x0000), // 'e' ➔ "Œ" LATIN CAPITAL LIGATURE OE
/*<!M><o><e>                                                       */ DEADTRANS( L'e'	,0xEE9C	,0x0153	,0x0000), // 'e' ➔ "œ" LATIN SMALL LIGATURE OE
/*<!M><o><h>                                                       */ DEADTRANS( L'h'	,0xEE9C	,0x2126	,0x0000), // 'h' ➔ "Ω" OHM SIGN
/*<!M><O><h>                                                       */ DEADTRANS( L'h'	,0xEE9D	,0x2126	,0x0000), // 'h' ➔ "Ω" OHM SIGN
/*<!M><O><H>                                                       */ DEADTRANS( L'H'	,0xEE9D	,0x2126	,0x0000), // 'H' ➔ "Ω" OHM SIGN
/*<!M><o><i>                                                       */ DEADTRANS( L'i'	,0xEE9C	,0xEF1E	,0x0001), // Multikey chain
/*<!M><O><I>                                                       */ DEADTRANS( L'I'	,0xEE9D	,0x23FB	,0x0000), // 'I' ➔ "⏻" POWER SYMBOL
/*<!M><o><I>                                                       */ DEADTRANS( L'I'	,0xEE9C	,0x2AEF	,0x0000), // 'I' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><i><n>                                                    */ DEADTRANS( L'n'	,0xEF1E	,0xEF1F	,0x0001), // Multikey chain
/*<!M><o><i><n><f>                                                 */ DEADTRANS( L'f'	,0xEF1F	,0x1D17	,0x0000), // 'f' ➔ "ᴗ" LATIN SMALL LETTER BOTTOM HALF O
/*<!M><o><i><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEF1E	,0x2AEF	,0x0000), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><i><~space>                                               */ DEADTRANS( L' '	,0xEF1E	,0x2AEF	,0x0000), // ' ' ➔ "⫯" VERTICAL LINE WITH CIRCLE ABOVE
/*<!M><o><m>                                                       */ DEADTRANS( L'm'	,0xEE9C	,0xEF23	,0x0001), // Multikey chain
/*<!M><O><M>                                                       */ DEADTRANS( L'M'	,0xEE9D	,0xEF24	,0x0001), // Multikey chain
/*<!M><O><o>                                                       */ DEADTRANS( L'o'	,0xEE9D	,0xEF2A	,0x0001), // Multikey chain
/*<!M><o><O>                                                       */ DEADTRANS( L'O'	,0xEE9C	,0x29B2	,0x0000), // 'O' ➔ "⦲" EMPTY SET WITH SMALL CIRCLE ABOVE
/*<!M><O><O>                                                       */ DEADTRANS( L'O'	,0xEE9D	,0xA74E	,0x0000), // 'O' ➔ "Ꝏ" LATIN CAPITAL LETTER OO
/*<!M><o><o>                                                       */ DEADTRANS( L'o'	,0xEE9C	,0xA74F	,0x0000), // 'o' ➔ "ꝏ" LATIN SMALL LETTER OO
/*<!M><O><o><x>                                                    */ DEADTRANS( L'x'	,0xEF2A	,0x2A37	,0x0000), // 'x' ➔ "⨷" MULTIPLICATION SIGN IN DOUBLE CIRCLE
/*<!M><O><o><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEF2A	,0x229A	,0x0000), // ' ' ➔ "⊚" CIRCLED RING OPERATOR
/*<!M><O><o><~space>                                               */ DEADTRANS( L' '	,0xEF2A	,0x229A	,0x0000), // ' ' ➔ "⊚" CIRCLED RING OPERATOR
/*<!M><o><p>                                                       */ DEADTRANS( L'p'	,0xEE9C	,0xEF30	,0x0001), // Multikey chain
/*<!M><O><P>                                                       */ DEADTRANS( L'P'	,0xEE9D	,0xEF31	,0x0001), // Multikey chain
/*<!M><o><P>                                                       */ DEADTRANS( L'P'	,0xEE9C	,0x2117	,0x0000), // 'P' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><O><p>                                                       */ DEADTRANS( L'p'	,0xEE9D	,0x2117	,0x0000), // 'p' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><o><p><h>                                                    */ DEADTRANS( L'h'	,0xEF30	,0x26CE	,0x0000), // 'h' ➔ "⛎" OPHIUCHUS emoji
/*<!M><O><P><H>                                                    */ DEADTRANS( L'H'	,0xEF31	,0x26CE	,0x0000), // 'H' ➔ "⛎" OPHIUCHUS emoji
/*<!M><o><p><t>                                                    */ DEADTRANS( L't'	,0xEF30	,0x2325	,0x0000), // 't' ➔ "⌥" OPTION KEY
/*<!M><O><P><T>                                                    */ DEADTRANS( L'T'	,0xEF31	,0x2325	,0x0000), // 'T' ➔ "⌥" OPTION KEY
/*<!M><o><R>                                                       */ DEADTRANS( L'R'	,0xEE9C	,0x00AE	,0x0000), // 'R' ➔ "®" REGISTERED SIGN emoji
/*<!M><O><r>                                                       */ DEADTRANS( L'r'	,0xEE9D	,0x00AE	,0x0000), // 'r' ➔ "®" REGISTERED SIGN emoji
/*<!M><o><r>                                                       */ DEADTRANS( L'r'	,0xEE9C	,0x2228	,0x0000), // 'r' ➔ "∨" LOGICAL OR
/*<!M><O><R>                                                       */ DEADTRANS( L'R'	,0xEE9D	,0x2228	,0x0000), // 'R' ➔ "∨" LOGICAL OR
/*<!M><o><s>                                                       */ DEADTRANS( L's'	,0xEE9C	,0xEF3C	,0x0001), // Multikey chain
/*<!M><O><S>                                                       */ DEADTRANS( L'S'	,0xEE9D	,0x2606	,0x0000), // 'S' ➔ "☆" WHITE STAR
/*<!M><o><S>                                                       */ DEADTRANS( L'S'	,0xEE9C	,0x2A0A	,0x0000), // 'S' ➔ "⨊" MODULO TWO SUM
/*<!M><o><s><t>                                                    */ DEADTRANS( L't'	,0xEF3C	,0x2606	,0x0000), // 't' ➔ "☆" WHITE STAR
/*<!M><o><s><u>                                                    */ DEADTRANS( L'u'	,0xEF3C	,0xEF3E	,0x0001), // Multikey chain
/*<!M><o><s><u><p>                                                 */ DEADTRANS( L'p'	,0xEF3E	,0x1D16	,0x0000), // 'p' ➔ "ᴖ" LATIN SMALL LETTER TOP HALF O
/*<!M><o><t>                                                       */ DEADTRANS( L't'	,0xEE9C	,0xEF40	,0x0001), // Multikey chain
/*<!M><O><T>                                                       */ DEADTRANS( L'T'	,0xEE9D	,0xEF41	,0x0001), // Multikey chain
/*<!M><o><T>                                                       */ DEADTRANS( L'T'	,0xEE9C	,0xEF42	,0x0001), // Multikey chain
/*<!M><o><T><%percent>                                             */ DEADTRANS( L'%'	,0xEF42	,0x27DF	,0x0000), // '%' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><o><t><d>                                                    */ DEADTRANS( L'd'	,0xEF40	,0x25BF	,0x0000), // 'd' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><O><T><D>                                                    */ DEADTRANS( L'D'	,0xEF41	,0x25BF	,0x0000), // 'D' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><o><t><h>                                                    */ DEADTRANS( L'h'	,0xEF40	,0x2679	,0x0000), // 'h' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><O><T><H>                                                    */ DEADTRANS( L'H'	,0xEF41	,0x2679	,0x0000), // 'H' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><o><t><r>                                                    */ DEADTRANS( L'r'	,0xEF40	,0x2679	,0x0000), // 'r' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><O><T><R>                                                    */ DEADTRANS( L'R'	,0xEF41	,0x2679	,0x0000), // 'R' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><o><T><T>                                                    */ DEADTRANS( L'T'	,0xEF42	,0x27DF	,0x0000), // 'T' ➔ "⟟" UP TACK WITH CIRCLE ABOVE
/*<!M><o><t><u>                                                    */ DEADTRANS( L'u'	,0xEF40	,0x25B5	,0x0000), // 'u' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><O><T><U>                                                    */ DEADTRANS( L'U'	,0xEF41	,0x25B5	,0x0000), // 'U' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><O><U>                                                       */ DEADTRANS( L'U'	,0xEE9D	,0x0222	,0x0000), // 'U' ➔ "Ȣ" LATIN CAPITAL LETTER OU
/*<!M><O><u>                                                       */ DEADTRANS( L'u'	,0xEE9D	,0x0222	,0x0000), // 'u' ➔ "Ȣ" LATIN CAPITAL LETTER OU
/*<!M><o><u>                                                       */ DEADTRANS( L'u'	,0xEE9C	,0x0223	,0x0000), // 'u' ➔ "ȣ" LATIN SMALL LETTER OU
/*<!M><o><x>                                                       */ DEADTRANS( L'x'	,0xEE9C	,0x2297	,0x0000), // 'x' ➔ "⊗" CIRCLED TIMES
/*<!M><O><X>                                                       */ DEADTRANS( L'X'	,0xEE9D	,0x29BB	,0x0000), // 'X' ➔ "⦻" CIRCLE WITH SUPERIMPOSED X
/*<!M><O><x>                                                       */ DEADTRANS( L'x'	,0xEE9D	,0x2A02	,0x0000), // 'x' ➔ "⨂" N-ARY CIRCLED TIMES OPERATOR
/*<!M><o><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEE9C	,0x2218	,0x0000), // ' ' ➔ "∘" RING OPERATOR
/*<!M><O><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEE9D	,0x25CB	,0x0000), // ' ' ➔ "○" WHITE CIRCLE
/*<!M><o><~space>                                                  */ DEADTRANS( L' '	,0xEE9C	,0x2218	,0x0000), // ' ' ➔ "∘" RING OPERATOR
/*<!M><O><~space>                                                  */ DEADTRANS( L' '	,0xEE9D	,0x25CB	,0x0000), // ' ' ➔ "○" WHITE CIRCLE
/*<!M><p>                                                          */ DEADTRANS( L'p'	,0x00A6	,0xEF57	,0x0001), // Multikey chain
/*<!M><P>                                                          */ DEADTRANS( L'P'	,0x00A6	,0xEF58	,0x0001), // Multikey chain
/*<!M><p><%bar>                                                    */ DEADTRANS( L'|'	,0xEF57	,0xEF59	,0x0001), // Multikey chain
/*<!M><p><%bar><%comma>                                            */ DEADTRANS( L','	,0xEF59	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p><%bar><~nbspace>                                          */ DEADTRANS( 0x00A0	,0xEF59	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p><%bar><~space>                                            */ DEADTRANS( L' '	,0xEF59	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><p><%comma>                                                  */ DEADTRANS( L','	,0xEF57	,0x220D	,0x0000), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><p><%equal>                                                  */ DEADTRANS( L'='	,0xEF57	,0x20B1	,0x0000), // '=' ➔ "₱" PESO SIGN
/*<!M><P><%equal>                                                  */ DEADTRANS( L'='	,0xEF58	,0x20B1	,0x0000), // '=' ➔ "₱" PESO SIGN
/*<!M><p><%exclam>                                                 */ DEADTRANS( L'!'	,0xEF57	,0x00B6	,0x0000), // '!' ➔ "¶" PILCROW SIGN
/*<!M><P><%exclam>                                                 */ DEADTRANS( L'!'	,0xEF58	,0x00B6	,0x0000), // '!' ➔ "¶" PILCROW SIGN
/*<!M><p><%greater>                                                */ DEADTRANS( L'>'	,0xEF57	,0x202C	,0x0000), // '>' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><p><%less>                                                   */ DEADTRANS( L'<'	,0xEF57	,0x202C	,0x0000), // '<' ➔ "‬" POP DIRECTIONAL FORMATTING
/*<!M><P><%minus>                                                  */ DEADTRANS( L'-'	,0xEF58	,0x20B1	,0x0000), // '-' ➔ "₱" PESO SIGN
/*<!M><p><%minus>                                                  */ DEADTRANS( L'-'	,0xEF57	,0x22FA	,0x0000), // '-' ➔ "⋺" CONTAINS WITH LONG HORIZONTAL STROKE
/*<!M><P><%percent>                                                */ DEADTRANS( L'%'	,0xEF58	,0x2210	,0x0000), // '%' ➔ "∐" N-ARY COPRODUCT
/*<!M><p><%percent>                                                */ DEADTRANS( L'%'	,0xEF57	,0x2A3F	,0x0000), // '%' ➔ "⨿" AMALGAMATION OR COPRODUCT
/*<!M><p><%slash>                                                  */ DEADTRANS( L'/'	,0xEF57	,0x220C	,0x0000), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><P><%tilde>                                                  */ DEADTRANS( L'~'	,0xEF58	,0x2118	,0x0000), // '~' ➔ "℘" SCRIPT CAPITAL P
/*<!M><P><2>                                                       */ DEADTRANS( L'2'	,0xEF58	,0x210F	,0x0000), // '2' ➔ "ℏ" PLANCK CONSTANT OVER TWO PI
/*<!M><p><2>                                                       */ DEADTRANS( L'2'	,0xEF57	,0x210F	,0x0000), // '2' ➔ "ℏ" PLANCK CONSTANT OVER TWO PI
/*<!M><p><a>                                                       */ DEADTRANS( L'a'	,0xEF57	,0xEF6C	,0x0001), // Multikey chain
/*<!M><P><A>                                                       */ DEADTRANS( L'A'	,0xEF58	,0xEF6D	,0x0001), // Multikey chain
/*<!M><p><a><c>                                                    */ DEADTRANS( L'c'	,0xEF6C	,0xEF6E	,0x0001), // Multikey chain
/*<!M><P><A><C>                                                    */ DEADTRANS( L'C'	,0xEF6D	,0xEF6F	,0x0001), // Multikey chain
/*<!M><p><a><c><a>                                                 */ DEADTRANS( L'a'	,0xEF6E	,0x25AB	,0x0000), // 'a' ➔ "▫" WHITE SMALL SQUARE
/*<!M><P><A><C><A>                                                 */ DEADTRANS( L'A'	,0xEF6F	,0x25AB	,0x0000), // 'A' ➔ "▫" WHITE SMALL SQUARE
/*<!M><p><a><c><d>                                                 */ DEADTRANS( L'd'	,0xEF6E	,0x25E6	,0x0000), // 'd' ➔ "◦" WHITE BULLET
/*<!M><P><A><C><D>                                                 */ DEADTRANS( L'D'	,0xEF6F	,0x25E6	,0x0000), // 'D' ➔ "◦" WHITE BULLET
/*<!M><p><a><r>                                                    */ DEADTRANS( L'r'	,0xEF6C	,0xEF74	,0x0001), // Multikey chain
/*<!M><P><A><R>                                                    */ DEADTRANS( L'R'	,0xEF6D	,0xEF75	,0x0001), // Multikey chain
/*<!M><p><a><r><c>                                                 */ DEADTRANS( L'c'	,0xEF74	,0x25AD	,0x0000), // 'c' ➔ "▭" WHITE RECTANGLE
/*<!M><P><A><R><C>                                                 */ DEADTRANS( L'C'	,0xEF75	,0x25AD	,0x0000), // 'C' ➔ "▭" WHITE RECTANGLE
/*<!M><p><a><r><o>                                                 */ DEADTRANS( L'o'	,0xEF74	,0x25E6	,0x0000), // 'o' ➔ "◦" WHITE BULLET
/*<!M><P><A><R><O>                                                 */ DEADTRANS( L'O'	,0xEF75	,0x25E6	,0x0000), // 'O' ➔ "◦" WHITE BULLET
/*<!M><p><a><t>                                                    */ DEADTRANS( L't'	,0xEF6C	,0xEF7A	,0x0001), // Multikey chain
/*<!M><P><A><T>                                                    */ DEADTRANS( L'T'	,0xEF6D	,0xEF7B	,0x0001), // Multikey chain
/*<!M><p><a><t><b>                                                 */ DEADTRANS( L'b'	,0xEF7A	,0x25BF	,0x0000), // 'b' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><P><A><T><B>                                                 */ DEADTRANS( L'B'	,0xEF7B	,0x25BF	,0x0000), // 'B' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><p><a><t><h>                                                 */ DEADTRANS( L'h'	,0xEF7A	,0x25B5	,0x0000), // 'h' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><P><A><T><H>                                                 */ DEADTRANS( L'H'	,0xEF7B	,0x25B5	,0x0000), // 'H' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><p><d>                                                       */ DEADTRANS( L'd'	,0xEF57	,0xEF80	,0x0001), // Multikey chain
/*<!M><p><d><i>                                                    */ DEADTRANS( L'i'	,0xEF80	,0x2069	,0x0000), // 'i' ➔ "⁩" POP DIRECTIONAL ISOLATE
/*<!M><p><e>                                                       */ DEADTRANS( L'e'	,0xEF57	,0xEF82	,0x0001), // Multikey chain
/*<!M><P><e>                                                       */ DEADTRANS( L'e'	,0xEF58	,0xEF83	,0x0001), // Multikey chain
/*<!M><P><E>                                                       */ DEADTRANS( L'E'	,0xEF58	,0xEF84	,0x0001), // Multikey chain
/*<!M><p><e><h>                                                    */ DEADTRANS( L'h'	,0xEF82	,0xEF85	,0x0001), // Multikey chain
/*<!M><P><E><H>                                                    */ DEADTRANS( L'H'	,0xEF84	,0xEF86	,0x0001), // Multikey chain
/*<!M><p><e><h><d>                                                 */ DEADTRANS( L'd'	,0xEF85	,0x2674	,0x0000), // 'd' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><P><E><H><D>                                                 */ DEADTRANS( L'D'	,0xEF86	,0x2674	,0x0000), // 'D' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><p><e><l>                                                    */ DEADTRANS( L'l'	,0xEF82	,0xEF89	,0x0001), // Multikey chain
/*<!M><P><E><L>                                                    */ DEADTRANS( L'L'	,0xEF84	,0xEF8A	,0x0001), // Multikey chain
/*<!M><p><e><l><d>                                                 */ DEADTRANS( L'd'	,0xEF89	,0x2676	,0x0000), // 'd' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><P><E><L><D>                                                 */ DEADTRANS( L'D'	,0xEF8A	,0x2676	,0x0000), // 'D' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><p><e><r>                                                    */ DEADTRANS( L'r'	,0xEF82	,0x214C	,0x0000), // 'r' ➔ "⅌" PER SIGN
/*<!M><P><e><r>                                                    */ DEADTRANS( L'r'	,0xEF83	,0x214C	,0x0000), // 'r' ➔ "⅌" PER SIGN
/*<!M><P><E><R>                                                    */ DEADTRANS( L'R'	,0xEF84	,0x214C	,0x0000), // 'R' ➔ "⅌" PER SIGN
/*<!M><p><e><t>                                                    */ DEADTRANS( L't'	,0xEF82	,0x2673	,0x0000), // 't' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P><E><T>                                                    */ DEADTRANS( L'T'	,0xEF84	,0x2673	,0x0000), // 'T' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P><f>                                                       */ DEADTRANS( L'f'	,0xEF58	,0x20B0	,0x0000), // 'f' ➔ "₰" GERMAN PENNY SIGN
/*<!M><p><h>                                                       */ DEADTRANS( L'h'	,0xEF57	,0xEF93	,0x0001), // Multikey chain
/*<!M><P><H>                                                       */ DEADTRANS( L'H'	,0xEF58	,0xEF94	,0x0001), // Multikey chain
/*<!M><p><h><p>                                                    */ DEADTRANS( L'p'	,0xEF93	,0x20B1	,0x0000), // 'p' ➔ "₱" PESO SIGN, Philippine Peso THE PHILIPPINES
/*<!M><P><H><P>                                                    */ DEADTRANS( L'P'	,0xEF94	,0x20B1	,0x0000), // 'P' ➔ "₱" PESO SIGN, Philippine Peso THE PHILIPPINES
/*<!M><p><i>                                                       */ DEADTRANS( L'i'	,0xEF57	,0xEF97	,0x0001), // Multikey chain
/*<!M><P><I>                                                       */ DEADTRANS( L'I'	,0xEF58	,0xEF98	,0x0001), // Multikey chain
/*<!M><p><i><s>                                                    */ DEADTRANS( L's'	,0xEF97	,0xEF99	,0x0001), // Multikey chain
/*<!M><P><I><S>                                                    */ DEADTRANS( L'S'	,0xEF98	,0xEF9A	,0x0001), // Multikey chain
/*<!M><p><i><s><c>                                                 */ DEADTRANS( L'c'	,0xEF99	,0x2653	,0x0000), // 'c' ➔ "♓" PISCES emoji
/*<!M><P><I><S><C>                                                 */ DEADTRANS( L'C'	,0xEF9A	,0x2653	,0x0000), // 'C' ➔ "♓" PISCES emoji
/*<!M><p><i><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEF97	,0x03C0	,0x0000), // ' ' ➔ "π" GREEK SMALL LETTER PI
/*<!M><p><i><~space>                                               */ DEADTRANS( L' '	,0xEF97	,0x03C0	,0x0000), // ' ' ➔ "π" GREEK SMALL LETTER PI
/*<!M><p><l>                                                       */ DEADTRANS( L'l'	,0xEF57	,0xEF9F	,0x0001), // Multikey chain
/*<!M><P><L>                                                       */ DEADTRANS( L'L'	,0xEF58	,0xEFA0	,0x0001), // Multikey chain
/*<!M><P><l>                                                       */ DEADTRANS( L'l'	,0xEF58	,0xEFA1	,0x0001), // Multikey chain
/*<!M><P><L><A>                                                    */ DEADTRANS( L'A'	,0xEFA0	,0x210E	,0x0000), // 'A' ➔ "ℎ" PLANCK CONSTANT
/*<!M><P><l><a>                                                    */ DEADTRANS( L'a'	,0xEFA1	,0x210E	,0x0000), // 'a' ➔ "ℎ" PLANCK CONSTANT
/*<!M><p><l><a>                                                    */ DEADTRANS( L'a'	,0xEF9F	,0x210E	,0x0000), // 'a' ➔ "ℎ" PLANCK CONSTANT
/*<!M><p><o>                                                       */ DEADTRANS( L'o'	,0xEF57	,0xEFA9	,0x0001), // Multikey chain
/*<!M><P><O>                                                       */ DEADTRANS( L'O'	,0xEF58	,0xEFAA	,0x0001), // Multikey chain
/*<!M><P><o>                                                       */ DEADTRANS( L'o'	,0xEF58	,0x2117	,0x0000), // 'o' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><p><O>                                                       */ DEADTRANS( L'O'	,0xEF57	,0x2117	,0x0000), // 'O' ➔ "℗" SOUND RECORDING COPYRIGHT
/*<!M><p><o><i>                                                    */ DEADTRANS( L'i'	,0xEFA9	,0xEFAB	,0x0001), // Multikey chain
/*<!M><P><O><I>                                                    */ DEADTRANS( L'I'	,0xEFAA	,0xEFAC	,0x0001), // Multikey chain
/*<!M><p><o><i><s>                                                 */ DEADTRANS( L's'	,0xEFAB	,0x2653	,0x0000), // 's' ➔ "♓" PISCES emoji
/*<!M><P><O><I><S>                                                 */ DEADTRANS( L'S'	,0xEFAC	,0x2653	,0x0000), // 'S' ➔ "♓" PISCES emoji
/*<!M><p><p>                                                       */ DEADTRANS( L'p'	,0xEF57	,0xEFAF	,0x0001), // Multikey chain
/*<!M><P><P>                                                       */ DEADTRANS( L'P'	,0xEF58	,0xEFB0	,0x0001), // Multikey chain
/*<!M><p><p><%at>                                                  */ DEADTRANS( L'@'	,0xEFAF	,0x213C	,0x0000), // '@' ➔ "ℼ" DOUBLE-STRUCK SMALL PI
/*<!M><P><P><%at>                                                  */ DEADTRANS( L'@'	,0xEFB0	,0x213F	,0x0000), // '@' ➔ "ℿ" DOUBLE-STRUCK CAPITAL PI
/*<!M><p><p><c>                                                    */ DEADTRANS( L'c'	,0xEFAF	,0xEFB3	,0x0001), // Multikey chain
/*<!M><P><P><C>                                                    */ DEADTRANS( L'C'	,0xEFB0	,0xEFB4	,0x0001), // Multikey chain
/*<!M><p><p><c><a>                                                 */ DEADTRANS( L'a'	,0xEFB3	,0x25AA	,0x0000), // 'a' ➔ "▪" BLACK SMALL SQUARE
/*<!M><P><P><C><A>                                                 */ DEADTRANS( L'A'	,0xEFB4	,0x25AA	,0x0000), // 'A' ➔ "▪" BLACK SMALL SQUARE
/*<!M><p><p><c><c>                                                 */ DEADTRANS( L'c'	,0xEFB3	,0x25CF	,0x0000), // 'c' ➔ "●" BLACK CIRCLE
/*<!M><P><P><C><C>                                                 */ DEADTRANS( L'C'	,0xEFB4	,0x25CF	,0x0000), // 'C' ➔ "●" BLACK CIRCLE
/*<!M><p><p><c><d>                                                 */ DEADTRANS( L'd'	,0xEFB3	,0x2022	,0x0000), // 'd' ➔ "•" BULLET
/*<!M><P><P><C><D>                                                 */ DEADTRANS( L'D'	,0xEFB4	,0x2022	,0x0000), // 'D' ➔ "•" BULLET
/*<!M><p><p><m>                                                    */ DEADTRANS( L'm'	,0xEFAF	,0xEFBB	,0x0001), // Multikey chain
/*<!M><P><P><M>                                                    */ DEADTRANS( L'M'	,0xEFB0	,0xEFBC	,0x0001), // Multikey chain
/*<!M><p><p><m><d>                                                 */ DEADTRANS( L'd'	,0xEFBB	,0x204D	,0x0000), // 'd' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><P><P><M><D>                                                 */ DEADTRANS( L'D'	,0xEFBC	,0x204D	,0x0000), // 'D' ➔ "⁍" BLACK RIGHTWARDS BULLET
/*<!M><p><p><m><g>                                                 */ DEADTRANS( L'g'	,0xEFBB	,0x204C	,0x0000), // 'g' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><P><P><M><G>                                                 */ DEADTRANS( L'G'	,0xEFBC	,0x204C	,0x0000), // 'G' ➔ "⁌" BLACK LEFTWARDS BULLET
/*<!M><p><p><p>                                                    */ DEADTRANS( L'p'	,0xEFAF	,0x2677	,0x0000), // 'p' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><P><P><P>                                                    */ DEADTRANS( L'P'	,0xEFB0	,0x2677	,0x0000), // 'P' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><p><p><r>                                                    */ DEADTRANS( L'r'	,0xEFAF	,0xEFC3	,0x0001), // Multikey chain
/*<!M><P><P><R>                                                    */ DEADTRANS( L'R'	,0xEFB0	,0xEFC4	,0x0001), // Multikey chain
/*<!M><p><p><r><c>                                                 */ DEADTRANS( L'c'	,0xEFC3	,0x25AC	,0x0000), // 'c' ➔ "▬" BLACK RECTANGLE
/*<!M><P><P><R><C>                                                 */ DEADTRANS( L'C'	,0xEFC4	,0x25AC	,0x0000), // 'C' ➔ "▬" BLACK RECTANGLE
/*<!M><p><p><r><d>                                                 */ DEADTRANS( L'd'	,0xEFC3	,0x25AE	,0x0000), // 'd' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><P><P><R><D>                                                 */ DEADTRANS( L'D'	,0xEFC4	,0x25AE	,0x0000), // 'D' ➔ "▮" BLACK VERTICAL RECTANGLE
/*<!M><p><p><r><e>                                                 */ DEADTRANS( L'e'	,0xEFC3	,0x220E	,0x0000), // 'e' ➔ "∎" END OF PROOF
/*<!M><P><P><R><E>                                                 */ DEADTRANS( L'E'	,0xEFC4	,0x220E	,0x0000), // 'E' ➔ "∎" END OF PROOF
/*<!M><p><p><r><o>                                                 */ DEADTRANS( L'o'	,0xEFC3	,0x2022	,0x0000), // 'o' ➔ "•" BULLET
/*<!M><P><P><R><O>                                                 */ DEADTRANS( L'O'	,0xEFC4	,0x2022	,0x0000), // 'O' ➔ "•" BULLET
/*<!M><p><p><t>                                                    */ DEADTRANS( L't'	,0xEFAF	,0xEFCD	,0x0001), // Multikey chain
/*<!M><P><P><T>                                                    */ DEADTRANS( L'T'	,0xEFB0	,0xEFCE	,0x0001), // Multikey chain
/*<!M><p><p><t><b>                                                 */ DEADTRANS( L'b'	,0xEFCD	,0x25BE	,0x0000), // 'b' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><P><P><T><B>                                                 */ DEADTRANS( L'B'	,0xEFCE	,0x25BE	,0x0000), // 'B' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><p><p><t><d>                                                 */ DEADTRANS( L'd'	,0xEFCD	,0x2023	,0x0000), // 'd' ➔ "‣" TRIANGULAR BULLET
/*<!M><P><P><T><D>                                                 */ DEADTRANS( L'D'	,0xEFCE	,0x2023	,0x0000), // 'D' ➔ "‣" TRIANGULAR BULLET
/*<!M><p><p><t><g>                                                 */ DEADTRANS( L'g'	,0xEFCD	,0x25C2	,0x0000), // 'g' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><P><P><T><G>                                                 */ DEADTRANS( L'G'	,0xEFCE	,0x25C2	,0x0000), // 'G' ➔ "◂" BLACK LEFT-POINTING SMALL TRIANGLE
/*<!M><p><p><t><h>                                                 */ DEADTRANS( L'h'	,0xEFCD	,0x25B4	,0x0000), // 'h' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><P><P><T><H>                                                 */ DEADTRANS( L'H'	,0xEFCE	,0x25B4	,0x0000), // 'H' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><P><P><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xEFB0	,0x2119	,0x0000), // ' ' ➔ "ℙ" DOUBLE-STRUCK CAPITAL P
/*<!M><P><P><~space>                                               */ DEADTRANS( L' '	,0xEFB0	,0x2119	,0x0000), // ' ' ➔ "ℙ" DOUBLE-STRUCK CAPITAL P
/*<!M><p><s>                                                       */ DEADTRANS( L's'	,0xEF57	,0x2678	,0x0000), // 's' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><P><S>                                                       */ DEADTRANS( L'S'	,0xEF58	,0x2678	,0x0000), // 'S' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><p><t>                                                       */ DEADTRANS( L't'	,0xEF57	,0xEFDC	,0x0001), // Multikey chain
/*<!M><P><T>                                                       */ DEADTRANS( L'T'	,0xEF58	,0xEFDD	,0x0001), // Multikey chain
/*<!M><P><t>                                                       */ DEADTRANS( L't'	,0xEF58	,0x20A7	,0x0000), // 't' ➔ "₧" PESETA SIGN
/*<!M><p><t><0>                                                    */ DEADTRANS( L'0'	,0xEFDC	,0x2672	,0x0000), // '0' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><P><T><0>                                                    */ DEADTRANS( L'0'	,0xEFDD	,0x2672	,0x0000), // '0' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><p><t><1>                                                    */ DEADTRANS( L'1'	,0xEFDC	,0x2673	,0x0000), // '1' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><P><T><1>                                                    */ DEADTRANS( L'1'	,0xEFDD	,0x2673	,0x0000), // '1' ➔ "♳" RECYCLING SYMBOL FOR TYPE-1 PLASTICS
/*<!M><p><t><2>                                                    */ DEADTRANS( L'2'	,0xEFDC	,0x2674	,0x0000), // '2' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><P><T><2>                                                    */ DEADTRANS( L'2'	,0xEFDD	,0x2674	,0x0000), // '2' ➔ "♴" RECYCLING SYMBOL FOR TYPE-2 PLASTICS
/*<!M><p><t><3>                                                    */ DEADTRANS( L'3'	,0xEFDC	,0x2675	,0x0000), // '3' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><P><T><3>                                                    */ DEADTRANS( L'3'	,0xEFDD	,0x2675	,0x0000), // '3' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><p><t><4>                                                    */ DEADTRANS( L'4'	,0xEFDC	,0x2676	,0x0000), // '4' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><P><T><4>                                                    */ DEADTRANS( L'4'	,0xEFDD	,0x2676	,0x0000), // '4' ➔ "♶" RECYCLING SYMBOL FOR TYPE-4 PLASTICS
/*<!M><p><t><5>                                                    */ DEADTRANS( L'5'	,0xEFDC	,0x2677	,0x0000), // '5' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><P><T><5>                                                    */ DEADTRANS( L'5'	,0xEFDD	,0x2677	,0x0000), // '5' ➔ "♷" RECYCLING SYMBOL FOR TYPE-5 PLASTICS
/*<!M><p><t><6>                                                    */ DEADTRANS( L'6'	,0xEFDC	,0x2678	,0x0000), // '6' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><P><T><6>                                                    */ DEADTRANS( L'6'	,0xEFDD	,0x2678	,0x0000), // '6' ➔ "♸" RECYCLING SYMBOL FOR TYPE-6 PLASTICS
/*<!M><p><t><7>                                                    */ DEADTRANS( L'7'	,0xEFDC	,0x2679	,0x0000), // '7' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><P><T><7>                                                    */ DEADTRANS( L'7'	,0xEFDD	,0x2679	,0x0000), // '7' ➔ "♹" RECYCLING SYMBOL FOR TYPE-7 PLASTICS
/*<!M><p><t><8>                                                    */ DEADTRANS( L'8'	,0xEFDC	,0x267A	,0x0000), // '8' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><P><T><8>                                                    */ DEADTRANS( L'8'	,0xEFDD	,0x267A	,0x0000), // '8' ➔ "♺" RECYCLING SYMBOL FOR GENERIC MATERIALS
/*<!M><p><t><9>                                                    */ DEADTRANS( L'9'	,0xEFDC	,0x267B	,0x0000), // '9' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><P><T><9>                                                    */ DEADTRANS( L'9'	,0xEFDD	,0x267B	,0x0000), // '9' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><p><v>                                                       */ DEADTRANS( L'v'	,0xEF57	,0xEFF2	,0x0001), // Multikey chain
/*<!M><P><V>                                                       */ DEADTRANS( L'V'	,0xEF58	,0xEFF3	,0x0001), // Multikey chain
/*<!M><p><v><c>                                                    */ DEADTRANS( L'c'	,0xEFF2	,0x2675	,0x0000), // 'c' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><P><V><C>                                                    */ DEADTRANS( L'C'	,0xEFF3	,0x2675	,0x0000), // 'C' ➔ "♵" RECYCLING SYMBOL FOR TYPE-3 PLASTICS
/*<!M><p><y>                                                       */ DEADTRANS( L'y'	,0xEF57	,0xEFF6	,0x0001), // Multikey chain
/*<!M><P><Y>                                                       */ DEADTRANS( L'Y'	,0xEF58	,0xEFF7	,0x0001), // Multikey chain
/*<!M><p><y><g>                                                    */ DEADTRANS( L'g'	,0xEFF6	,0x20B2	,0x0000), // 'g' ➔ "₲" GUARANI SIGN, Guarani PARAGUAY
/*<!M><P><Y><G>                                                    */ DEADTRANS( L'G'	,0xEFF7	,0x20B2	,0x0000), // 'G' ➔ "₲" GUARANI SIGN, Guarani PARAGUAY
/*<!M><p><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEF57	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><P><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xEF58	,0x220F	,0x0000), // ' ' ➔ "∏" N-ARY PRODUCT
/*<!M><p><~space>                                                  */ DEADTRANS( L' '	,0xEF57	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><P><~space>                                                  */ DEADTRANS( L' '	,0xEF58	,0x220F	,0x0000), // ' ' ➔ "∏" N-ARY PRODUCT
/*<!M><q>                                                          */ DEADTRANS( L'q'	,0x00A6	,0xEFFE	,0x0001), // Multikey chain
/*<!M><Q>                                                          */ DEADTRANS( L'Q'	,0x00A6	,0xEFFF	,0x0001), // Multikey chain
/*<!M><q><%hash>                                                   */ DEADTRANS( L'#'	,0xEFFE	,0x2669	,0x0000), // '#' ➔ "♩" QUARTER NOTE
/*<!M><Q><%hash>                                                   */ DEADTRANS( L'#'	,0xEFFF	,0x2669	,0x0000), // '#' ➔ "♩" QUARTER NOTE
/*<!M><Q><0>                                                       */ DEADTRANS( L'0'	,0xEFFF	,0x25CB	,0x0000), // '0' ➔ "○" WHITE CIRCLE
/*<!M><q><0>                                                       */ DEADTRANS( L'0'	,0xEFFE	,0x25CB	,0x0000), // '0' ➔ "○" WHITE CIRCLE
/*<!M><Q><1>                                                       */ DEADTRANS( L'1'	,0xEFFF	,0x25D4	,0x0000), // '1' ➔ "◔" CIRCLE WITH UPPER RIGHT QUADRANT BLACK
/*<!M><q><1>                                                       */ DEADTRANS( L'1'	,0xEFFE	,0x25F7	,0x0000), // '1' ➔ "◷" WHITE CIRCLE WITH UPPER RIGHT QUADRANT
/*<!M><Q><2>                                                       */ DEADTRANS( L'2'	,0xEFFF	,0x25D1	,0x0000), // '2' ➔ "◑" CIRCLE WITH RIGHT HALF BLACK
/*<!M><q><2>                                                       */ DEADTRANS( L'2'	,0xEFFE	,0x25F6	,0x0000), // '2' ➔ "◶" WHITE CIRCLE WITH LOWER RIGHT QUADRANT
/*<!M><Q><3>                                                       */ DEADTRANS( L'3'	,0xEFFF	,0x25D5	,0x0000), // '3' ➔ "◕" CIRCLE WITH ALL BUT UPPER LEFT QUADRANT BLACK
/*<!M><q><3>                                                       */ DEADTRANS( L'3'	,0xEFFE	,0x25F5	,0x0000), // '3' ➔ "◵" WHITE CIRCLE WITH LOWER LEFT QUADRANT
/*<!M><Q><4>                                                       */ DEADTRANS( L'4'	,0xEFFF	,0x25CF	,0x0000), // '4' ➔ "●" BLACK CIRCLE
/*<!M><q><4>                                                       */ DEADTRANS( L'4'	,0xEFFE	,0x25F4	,0x0000), // '4' ➔ "◴" WHITE CIRCLE WITH UPPER LEFT QUADRANT
/*<!M><q><a>                                                       */ DEADTRANS( L'a'	,0xEFFE	,0xF00C	,0x0001), // Multikey chain
/*<!M><Q><A>                                                       */ DEADTRANS( L'A'	,0xEFFF	,0xF00D	,0x0001), // Multikey chain
/*<!M><q><e>                                                       */ DEADTRANS( L'e'	,0xEFFE	,0x220E	,0x0000), // 'e' ➔ "∎" END OF PROOF
/*<!M><Q><E>                                                       */ DEADTRANS( L'E'	,0xEFFF	,0x220E	,0x0000), // 'E' ➔ "∎" END OF PROOF
/*<!M><q><p>                                                       */ DEADTRANS( L'p'	,0xEFFE	,0x0239	,0x0000), // 'p' ➔ "ȹ" LATIN SMALL LETTER QP DIGRAPH
/*<!M><Q><Q>                                                       */ DEADTRANS( L'Q'	,0xEFFF	,0x211A	,0x0000), // 'Q' ➔ "ℚ" DOUBLE-STRUCK CAPITAL Q
/*<!M><r>                                                          */ DEADTRANS( L'r'	,0x00A6	,0xF014	,0x0001), // Multikey chain
/*<!M><R>                                                          */ DEADTRANS( L'R'	,0x00A6	,0xF015	,0x0001), // Multikey chain
/*<!M><r><%at>                                                     */ DEADTRANS( L'@'	,0xF014	,0x03F1	,0x0000), // '@' ➔ "ϱ" GREEK RHO SYMBOL
/*<!M><r><%equal>                                                  */ DEADTRANS( L'='	,0xF014	,0x20B9	,0x0000), // '=' ➔ "₹" INDIAN RUPEE SIGN
/*<!M><R><%equal>                                                  */ DEADTRANS( L'='	,0xF015	,0x20B9	,0x0000), // '=' ➔ "₹" INDIAN RUPEE SIGN
/*<!M><R><%hash>                                                   */ DEADTRANS( L'#'	,0xF015	,0x211C	,0x0000), // '#' ➔ "ℜ" BLACK-LETTER CAPITAL R
/*<!M><R><%minus>                                                  */ DEADTRANS( L'-'	,0xF015	,0x211E	,0x0000), // '-' ➔ "℞" PRESCRIPTION TAKE
/*<!M><r><%minus>                                                  */ DEADTRANS( L'-'	,0xF014	,0x211E	,0x0000), // '-' ➔ "℞" PRESCRIPTION TAKE
/*<!M><r><%parenleft>                                              */ DEADTRANS( L'('	,0xF014	,0xAB45	,0x0000), // '(' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><R><%parenleft>                                              */ DEADTRANS( L'('	,0xF015	,0xAB45	,0x0000), // '(' ➔ "ꭅ" LATIN SMALL LETTER STIRRUP R
/*<!M><R><%slash>                                                  */ DEADTRANS( L'/'	,0xF015	,0x211F	,0x0000), // '/' ➔ "℟" RESPONSE
/*<!M><r><%slash>                                                  */ DEADTRANS( L'/'	,0xF014	,0x211F	,0x0000), // '/' ➔ "℟" RESPONSE
/*<!M><R><%tilde>                                                  */ DEADTRANS( L'~'	,0xF015	,0x211B	,0x0000), // '~' ➔ "ℛ" SCRIPT CAPITAL R
/*<!M><R><C>                                                       */ DEADTRANS( L'C'	,0xF015	,0xF021	,0x0001), // Multikey chain
/*<!M><R><C><C>                                                    */ DEADTRANS( L'C'	,0xF021	,0xF022	,0x0001), // Multikey chain
/*<!M><R><C><C><C>                                                 */ DEADTRANS( L'C'	,0xF022	,0xF023	,0x0001), // Multikey chain
/*<!M><R><C><C><C><D>                                              */ DEADTRANS( L'D'	,0xF023	,0xF024	,0x0001), // Multikey chain
/*<!M><R><C><C><C><D><D>                                           */ DEADTRANS( L'D'	,0xF024	,0xF025	,0x0001), // Multikey chain
/*<!M><R><C><C><C><D><D><D>                                        */ DEADTRANS( L'D'	,0xF025	,0x2188	,0x0000), // 'D' ➔ "ↈ" ROMAN NUMERAL ONE HUNDRED THOUSAND
/*<!M><R><C><C><D>                                                 */ DEADTRANS( L'D'	,0xF022	,0xF027	,0x0001), // Multikey chain
/*<!M><R><C><C><D><D>                                              */ DEADTRANS( L'D'	,0xF027	,0x2182	,0x0000), // 'D' ➔ "ↂ" ROMAN NUMERAL TEN THOUSAND
/*<!M><R><C><D>                                                    */ DEADTRANS( L'D'	,0xF021	,0x2180	,0x0000), // 'D' ➔ "ↀ" ROMAN NUMERAL ONE THOUSAND C D
/*<!M><R><C><V>                                                    */ DEADTRANS( L'V'	,0xF021	,0xF02A	,0x0001), // Multikey chain
/*<!M><R><C><V><I>                                                 */ DEADTRANS( L'I'	,0xF02A	,0x2185	,0x0000), // 'I' ➔ "ↅ" ROMAN NUMERAL SIX LATE FORM
/*<!M><R><D>                                                       */ DEADTRANS( L'D'	,0xF015	,0xF02C	,0x0001), // Multikey chain
/*<!M><R><D><D>                                                    */ DEADTRANS( L'D'	,0xF02C	,0xF02D	,0x0001), // Multikey chain
/*<!M><R><D><D><D>                                                 */ DEADTRANS( L'D'	,0xF02D	,0x2187	,0x0000), // 'D' ➔ "ↇ" ROMAN NUMERAL FIFTY THOUSAND
/*<!M><R><D><D><~space>                                            */ DEADTRANS( L' '	,0xF02D	,0x2181	,0x0000), // ' ' ➔ "ↁ" ROMAN NUMERAL FIVE THOUSAND
/*<!M><r><e>                                                       */ DEADTRANS( L'e'	,0xF014	,0xF030	,0x0001), // Multikey chain
/*<!M><R><E>                                                       */ DEADTRANS( L'E'	,0xF015	,0xF031	,0x0001), // Multikey chain
/*<!M><r><e><c>                                                    */ DEADTRANS( L'c'	,0xF030	,0xF032	,0x0001), // Multikey chain
/*<!M><R><E><C>                                                    */ DEADTRANS( L'C'	,0xF031	,0xF033	,0x0001), // Multikey chain
/*<!M><r><e><c><a>                                                 */ DEADTRANS( L'a'	,0xF032	,0x2672	,0x0000), // 'a' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C><A>                                                 */ DEADTRANS( L'A'	,0xF033	,0x2672	,0x0000), // 'A' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c><e>                                                 */ DEADTRANS( L'e'	,0xF032	,0x2672	,0x0000), // 'e' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C><E>                                                 */ DEADTRANS( L'E'	,0xF033	,0x2672	,0x0000), // 'E' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c><f>                                                 */ DEADTRANS( L'f'	,0xF032	,0x267B	,0x0000), // 'f' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C><F>                                                 */ DEADTRANS( L'F'	,0xF033	,0x267B	,0x0000), // 'F' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c><g>                                                 */ DEADTRANS( L'g'	,0xF032	,0x267B	,0x0000), // 'g' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C><G>                                                 */ DEADTRANS( L'G'	,0xF033	,0x267B	,0x0000), // 'G' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c><i>                                                 */ DEADTRANS( L'i'	,0xF032	,0x267B	,0x0000), // 'i' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C><I>                                                 */ DEADTRANS( L'I'	,0xF033	,0x267B	,0x0000), // 'I' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c><o>                                                 */ DEADTRANS( L'o'	,0xF032	,0x2672	,0x0000), // 'o' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C><O>                                                 */ DEADTRANS( L'O'	,0xF033	,0x2672	,0x0000), // 'O' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c><p>                                                 */ DEADTRANS( L'p'	,0xF032	,0x267B	,0x0000), // 'p' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C><P>                                                 */ DEADTRANS( L'P'	,0xF033	,0x267B	,0x0000), // 'P' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><c><u>                                                 */ DEADTRANS( L'u'	,0xF032	,0x2672	,0x0000), // 'u' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><R><E><C><U>                                                 */ DEADTRANS( L'U'	,0xF033	,0x2672	,0x0000), // 'U' ➔ "♲" UNIVERSAL RECYCLING SYMBOL
/*<!M><r><e><c><v>                                                 */ DEADTRANS( L'v'	,0xF032	,0x267B	,0x0000), // 'v' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><R><E><C><V>                                                 */ DEADTRANS( L'V'	,0xF033	,0x267B	,0x0000), // 'V' ➔ "♻" BLACK UNIVERSAL RECYCLING SYMBOL emoji
/*<!M><r><e><t>                                                    */ DEADTRANS( L't'	,0xF030	,0x21B5	,0x0000), // 't' ➔ "↵" DOWNWARDS ARROW WITH CORNER LEFTWARDS
/*<!M><R><E><T>                                                    */ DEADTRANS( L'T'	,0xF031	,0x23CE	,0x0000), // 'T' ➔ "⏎" RETURN SYMBOL
/*<!M><R><L>                                                       */ DEADTRANS( L'L'	,0xF015	,0xF048	,0x0001), // Multikey chain
/*<!M><R><L><L>                                                    */ DEADTRANS( L'L'	,0xF048	,0x2186	,0x0000), // 'L' ➔ "ↆ" ROMAN NUMERAL FIFTY EARLY FORM
/*<!M><r><m>                                                       */ DEADTRANS( L'm'	,0xF014	,0xDD6C	,0x0000), // High surrogate: D83C; U+1F16C 'm' ➔ "🅬" RAISED MR SIGN
/*<!M><R><M>                                                       */ DEADTRANS( L'M'	,0xF015	,0xDD6C	,0x0000), // High surrogate: D83C; U+1F16C 'M' ➔ "🅬" RAISED MR SIGN
/*<!M><r><o>                                                       */ DEADTRANS( L'o'	,0xF014	,0x00AE	,0x0000), // 'o' ➔ "®" REGISTERED SIGN emoji
/*<!M><R><O>                                                       */ DEADTRANS( L'O'	,0xF015	,0x00AE	,0x0000), // 'O' ➔ "®" REGISTERED SIGN emoji
/*<!M><R><p>                                                       */ DEADTRANS( L'p'	,0xF015	,0xF04E	,0x0001), // Multikey chain
/*<!M><R><p><a>                                                    */ DEADTRANS( L'a'	,0xF04E	,0xF04F	,0x0001), // Multikey chain
/*<!M><R><p><a><r>                                                 */ DEADTRANS( L'r'	,0xF04F	,0xF050	,0x0001), // Multikey chain
/*<!M><R><p><a><r><e>                                              */ DEADTRANS( L'e'	,0xF050	,0xF051	,0x0001), // Multikey chain
/*<!M><R><p><a><r><e><n>                                           */ DEADTRANS( L'n'	,0xF051	,0xF052	,0x0001), // Multikey chain
/*<!M><R><p><a><r><e><n><l>                                        */ DEADTRANS( L'l'	,0xF052	,0xF053	,0x0001), // Multikey chain
/*<!M><R><p><a><r><e><n><l><t>                                     */ DEADTRANS( L't'	,0xF053	,0x2996	,0x0000), // 't' ➔ "⦖" DOUBLE RIGHT ARC LESS-THAN BRACKET TeX + HTML under max 9 keysym constraint
/*<!M><R><R>                                                       */ DEADTRANS( L'R'	,0xF015	,0x211D	,0x0000), // 'R' ➔ "ℝ" DOUBLE-STRUCK CAPITAL R
/*<!M><r><r>                                                       */ DEADTRANS( L'r'	,0xF014	,0xAB48	,0x0000), // 'r' ➔ "ꭈ" LATIN SMALL LETTER DOUBLE R
/*<!M><R><s>                                                       */ DEADTRANS( L's'	,0xF015	,0x20A8	,0x0000), // 's' ➔ "₨" RUPEE SIGN
/*<!M><R><U>                                                       */ DEADTRANS( L'U'	,0xF015	,0xF058	,0x0001), // Multikey chain
/*<!M><R><u>                                                       */ DEADTRANS( L'u'	,0xF015	,0xF059	,0x0001), // Multikey chain
/*<!M><r><u>                                                       */ DEADTRANS( L'u'	,0xF014	,0xF05A	,0x0001), // Multikey chain
/*<!M><r><u><b>                                                    */ DEADTRANS( L'b'	,0xF05A	,0x20BD	,0x0000), // 'b' ➔ "₽" RUBLE SIGN, Russian Ruble THE RUSSIAN FEDERATION
/*<!M><R><U><B>                                                    */ DEADTRANS( L'B'	,0xF058	,0x20BD	,0x0000), // 'B' ➔ "₽" RUBLE SIGN, Russian Ruble THE RUSSIAN FEDERATION
/*<!M><r><u><m>                                                    */ DEADTRANS( L'm'	,0xF05A	,0xA775	,0x0000), // 'm' ➔ "ꝵ" LATIN SMALL LETTER RUM
/*<!M><R><U><M>                                                    */ DEADTRANS( L'M'	,0xF058	,0xA776	,0x0000), // 'M' ➔ "ꝶ" LATIN LETTER SMALL CAPITAL RUM
/*<!M><R><u><m>                                                    */ DEADTRANS( L'm'	,0xF059	,0xA776	,0x0000), // 'm' ➔ "ꝶ" LATIN LETTER SMALL CAPITAL RUM
/*<!M><R><U><R>                                                    */ DEADTRANS( L'R'	,0xF058	,0xA75C	,0x0000), // 'R' ➔ "Ꝝ" LATIN CAPITAL LETTER RUM ROTUNDA
/*<!M><R><u><r>                                                    */ DEADTRANS( L'r'	,0xF059	,0xA75C	,0x0000), // 'r' ➔ "Ꝝ" LATIN CAPITAL LETTER RUM ROTUNDA
/*<!M><r><u><r>                                                    */ DEADTRANS( L'r'	,0xF05A	,0xA75D	,0x0000), // 'r' ➔ "ꝝ" LATIN SMALL LETTER RUM ROTUNDA
/*<!M><s>                                                          */ DEADTRANS( L's'	,0x00A6	,0xF063	,0x0001), // Multikey chain
/*<!M><S>                                                          */ DEADTRANS( L'S'	,0x00A6	,0xF064	,0x0001), // Multikey chain
/*<!M><s><%backslash>                                              */ DEADTRANS( L'\\'	,0xF063	,0xF065	,0x0001), // Multikey chain
/*<!M><s><%backslash><%percent>                                    */ DEADTRANS( L'%'	,0xF065	,0x223E	,0x0000), // '%' ➔ "∾" INVERTED LAZY S
/*<!M><s><%backslash><%slash>                                      */ DEADTRANS( L'/'	,0xF065	,0x29CC	,0x0000), // '/' ➔ "⧌" S IN TRIANGLE
/*<!M><s><%braceleft>                                              */ DEADTRANS( L'{'	,0xF063	,0x27C5	,0x0000), // '{' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S><%braceleft>                                              */ DEADTRANS( L'{'	,0xF064	,0x27C5	,0x0000), // '{' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s><%braceright>                                             */ DEADTRANS( L'}'	,0xF063	,0x27C6	,0x0000), // '}' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%braceright>                                             */ DEADTRANS( L'}'	,0xF064	,0x27C6	,0x0000), // '}' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketleft>                                            */ DEADTRANS( L'['	,0xF063	,0xF06C	,0x0001), // Multikey chain
/*<!M><S><%bracketleft>                                            */ DEADTRANS( L'['	,0xF064	,0xF06D	,0x0001), // Multikey chain
/*<!M><s><%bracketleft><%bracketright>                             */ DEADTRANS( L']'	,0xF06C	,0x2A16	,0x0000), // ']' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><S><%bracketleft><%bracketright>                             */ DEADTRANS( L']'	,0xF06D	,0x2A16	,0x0000), // ']' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><s><%bracketleft><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF06C	,0x27C5	,0x0000), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketleft><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF06D	,0x27C5	,0x0000), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketleft><~space>                                    */ DEADTRANS( L' '	,0xF06C	,0x27C5	,0x0000), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketleft><~space>                                    */ DEADTRANS( L' '	,0xF06D	,0x27C5	,0x0000), // ' ' ➔ "⟅" LEFT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketright>                                           */ DEADTRANS( L']'	,0xF063	,0xF074	,0x0001), // Multikey chain
/*<!M><S><%bracketright>                                           */ DEADTRANS( L']'	,0xF064	,0xF075	,0x0001), // Multikey chain
/*<!M><s><%bracketright><%bracketleft>                             */ DEADTRANS( L'['	,0xF074	,0x2A16	,0x0000), // '[' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><S><%bracketright><%bracketleft>                             */ DEADTRANS( L'['	,0xF075	,0x2A16	,0x0000), // '[' ➔ "⨖" QUATERNION INTEGRAL OPERATOR
/*<!M><s><%bracketright><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF074	,0x27C6	,0x0000), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketright><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF075	,0x27C6	,0x0000), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><s><%bracketright><~space>                                   */ DEADTRANS( L' '	,0xF074	,0x27C6	,0x0000), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%bracketright><~space>                                   */ DEADTRANS( L' '	,0xF075	,0x27C6	,0x0000), // ' ' ➔ "⟆" RIGHT S-SHAPED BAG DELIMITER
/*<!M><S><%equal>                                                  */ DEADTRANS( L'='	,0xF064	,0x20B4	,0x0000), // '=' ➔ "₴" HRYVNIA SIGN
/*<!M><s><%equal>                                                  */ DEADTRANS( L'='	,0xF063	,0x2A0E	,0x0000), // '=' ➔ "⨎" INTEGRAL WITH DOUBLE STROKE
/*<!M><s><%exclam>                                                 */ DEADTRANS( L'!'	,0xF063	,0x00A7	,0x0000), // '!' ➔ "§" SECTION SIGN
/*<!M><S><%exclam>                                                 */ DEADTRANS( L'!'	,0xF064	,0x00A7	,0x0000), // '!' ➔ "§" SECTION SIGN
/*<!M><S><%hash>                                                   */ DEADTRANS( L'#'	,0xF064	,0x266C	,0x0000), // '#' ➔ "♬" BEAMED SIXTEENTH NOTES
/*<!M><s><%hash>                                                   */ DEADTRANS( L'#'	,0xF063	,0x266F	,0x0000), // '#' ➔ "♯" MUSIC SHARP SIGN
/*<!M><s><%less>                                                   */ DEADTRANS( L'<'	,0xF063	,0xF082	,0x0001), // Multikey chain
/*<!M><S><%less>                                                   */ DEADTRANS( L'<'	,0xF064	,0xF083	,0x0001), // Multikey chain
/*<!M><s><%less><%minus>                                           */ DEADTRANS( L'-'	,0xF082	,0x2A17	,0x0000), // '-' ➔ "⨗" INTEGRAL WITH LEFTWARDS ARROW WITH HOOK
/*<!M><S><%less><%minus>                                           */ DEADTRANS( L'-'	,0xF083	,0x2A17	,0x0000), // '-' ➔ "⨗" INTEGRAL WITH LEFTWARDS ARROW WITH HOOK
/*<!M><S><%minus>                                                  */ DEADTRANS( L'-'	,0xF064	,0x20B4	,0x0000), // '-' ➔ "₴" HRYVNIA SIGN
/*<!M><s><%minus>                                                  */ DEADTRANS( L'-'	,0xF063	,0x2A0D	,0x0000), // '-' ➔ "⨍" FINITE PART INTEGRAL
/*<!M><s><%parenleft>                                              */ DEADTRANS( L'('	,0xF063	,0x2231	,0x0000), // '(' ➔ "∱" CLOCKWISE INTEGRAL
/*<!M><S><%parenleft>                                              */ DEADTRANS( L'('	,0xF064	,0x2231	,0x0000), // '(' ➔ "∱" CLOCKWISE INTEGRAL
/*<!M><s><%parenright>                                             */ DEADTRANS( L')'	,0xF063	,0x2A11	,0x0000), // ')' ➔ "⨑" ANTICLOCKWISE INTEGRATION
/*<!M><S><%parenright>                                             */ DEADTRANS( L')'	,0xF064	,0x2A11	,0x0000), // ')' ➔ "⨑" ANTICLOCKWISE INTEGRATION
/*<!M><s><%percent>                                                */ DEADTRANS( L'%'	,0xF063	,0xF08C	,0x0001), // Multikey chain
/*<!M><s><%percent><%backslash>                                    */ DEADTRANS( L'\\'	,0xF08C	,0x223E	,0x0000), // '\' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent><%percent>                                      */ DEADTRANS( L'%'	,0xF08C	,0x223E	,0x0000), // '%' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF08C	,0x223E	,0x0000), // ' ' ➔ "∾" INVERTED LAZY S
/*<!M><s><%percent><~space>                                        */ DEADTRANS( L' '	,0xF08C	,0x223E	,0x0000), // ' ' ➔ "∾" INVERTED LAZY S
/*<!M><s><%period>                                                 */ DEADTRANS( L'.'	,0xF063	,0xF091	,0x0001), // Multikey chain
/*<!M><S><%period>                                                 */ DEADTRANS( L'.'	,0xF064	,0xF092	,0x0001), // Multikey chain
/*<!M><s><%period><%bracketright>                                  */ DEADTRANS( L']'	,0xF091	,0x2A12	,0x0000), // ']' ➔ "⨒" LINE INTEGRATION WITH RECTANGULAR PATH AROUND POLE
/*<!M><S><%period><%bracketright>                                  */ DEADTRANS( L']'	,0xF092	,0x2A12	,0x0000), // ']' ➔ "⨒" LINE INTEGRATION WITH RECTANGULAR PATH AROUND POLE
/*<!M><s><%period><%parenright>                                    */ DEADTRANS( L')'	,0xF091	,0x2A13	,0x0000), // ')' ➔ "⨓" LINE INTEGRATION WITH SEMICIRCULAR PATH AROUND POLE
/*<!M><S><%period><%parenright>                                    */ DEADTRANS( L')'	,0xF092	,0x2A13	,0x0000), // ')' ➔ "⨓" LINE INTEGRATION WITH SEMICIRCULAR PATH AROUND POLE
/*<!M><s><%period><o>                                              */ DEADTRANS( L'o'	,0xF091	,0x2A14	,0x0000), // 'o' ➔ "⨔" LINE INTEGRATION NOT INCLUDING THE POLE
/*<!M><S><%period><o>                                              */ DEADTRANS( L'o'	,0xF092	,0x2A14	,0x0000), // 'o' ➔ "⨔" LINE INTEGRATION NOT INCLUDING THE POLE
/*<!M><s><%slash>                                                  */ DEADTRANS( L'/'	,0xF063	,0xF09A	,0x0001), // Multikey chain
/*<!M><S><%slash>                                                  */ DEADTRANS( L'/'	,0xF064	,0x2A0F	,0x0000), // '/' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s><%slash><%backslash>                                      */ DEADTRANS( L'\\'	,0xF09A	,0x29CC	,0x0000), // '\' ➔ "⧌" S IN TRIANGLE
/*<!M><s><%slash><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xF09A	,0x2A0F	,0x0000), // ' ' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s><%slash><~space>                                          */ DEADTRANS( L' '	,0xF09A	,0x2A0F	,0x0000), // ' ' ➔ "⨏" INTEGRAL AVERAGE WITH SLASH
/*<!M><s><%underscore>                                             */ DEADTRANS( L'_'	,0xF063	,0x2A1C	,0x0000), // '_' ➔ "⨜" INTEGRAL WITH UNDERBAR
/*<!M><S><%underscore>                                             */ DEADTRANS( L'_'	,0xF064	,0x2A1C	,0x0000), // '_' ➔ "⨜" INTEGRAL WITH UNDERBAR
/*<!M><s><a>                                                       */ DEADTRANS( L'a'	,0xF063	,0xF0A0	,0x0001), // Multikey chain
/*<!M><S><a>                                                       */ DEADTRANS( L'a'	,0xF064	,0xF0A1	,0x0001), // Multikey chain
/*<!M><S><A>                                                       */ DEADTRANS( L'A'	,0xF064	,0xF0A2	,0x0001), // Multikey chain
/*<!M><s><a><g>                                                    */ DEADTRANS( L'g'	,0xF0A0	,0xF0A3	,0x0001), // Multikey chain
/*<!M><S><A><G>                                                    */ DEADTRANS( L'G'	,0xF0A2	,0xF0A4	,0x0001), // Multikey chain
/*<!M><s><a><g><i>                                                 */ DEADTRANS( L'i'	,0xF0A3	,0x2650	,0x0000), // 'i' ➔ "♐" SAGITTARIUS emoji
/*<!M><S><A><G><I>                                                 */ DEADTRANS( L'I'	,0xF0A4	,0x2650	,0x0000), // 'I' ➔ "♐" SAGITTARIUS emoji
/*<!M><s><a><m>                                                    */ DEADTRANS( L'm'	,0xF0A0	,0x214F	,0x0000), // 'm' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><S><a><m>                                                    */ DEADTRANS( L'm'	,0xF0A1	,0x214F	,0x0000), // 'm' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><S><A><M>                                                    */ DEADTRANS( L'M'	,0xF0A2	,0x214F	,0x0000), // 'M' ➔ "⅏" SYMBOL FOR SAMARITAN SOURCE
/*<!M><s><c>                                                       */ DEADTRANS( L'c'	,0xF063	,0xF0AC	,0x0001), // Multikey chain
/*<!M><S><c>                                                       */ DEADTRANS( L'c'	,0xF064	,0xF0AD	,0x0001), // Multikey chain
/*<!M><S><C>                                                       */ DEADTRANS( L'C'	,0xF064	,0xF0AE	,0x0001), // Multikey chain
/*<!M><s><c><o>                                                    */ DEADTRANS( L'o'	,0xF0AC	,0xF0AF	,0x0001), // Multikey chain
/*<!M><S><C><O>                                                    */ DEADTRANS( L'O'	,0xF0AE	,0xF0B0	,0x0001), // Multikey chain
/*<!M><s><c><o><r>                                                 */ DEADTRANS( L'r'	,0xF0AF	,0x264F	,0x0000), // 'r' ➔ "♏" SCORPIUS emoji
/*<!M><S><C><O><R>                                                 */ DEADTRANS( L'R'	,0xF0B0	,0x264F	,0x0000), // 'R' ➔ "♏" SCORPIUS emoji
/*<!M><s><c><r>                                                    */ DEADTRANS( L'r'	,0xF0AC	,0x2108	,0x0000), // 'r' ➔ "℈" SCRUPLE
/*<!M><S><c><r>                                                    */ DEADTRANS( L'r'	,0xF0AD	,0x2108	,0x0000), // 'r' ➔ "℈" SCRUPLE
/*<!M><S><C><R>                                                    */ DEADTRANS( L'R'	,0xF0AE	,0x2108	,0x0000), // 'R' ➔ "℈" SCRUPLE
/*<!M><s><c><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0AC	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><c><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0AD	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><C><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0AE	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><s><c><~space>                                               */ DEADTRANS( L' '	,0xF0AC	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><c><~space>                                               */ DEADTRANS( L' '	,0xF0AD	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><S><C><~space>                                               */ DEADTRANS( L' '	,0xF0AE	,0x2A10	,0x0000), // ' ' ➔ "⨐" CIRCULATION FUNCTION
/*<!M><s><d>                                                       */ DEADTRANS( L'd'	,0xF063	,0xF0BC	,0x0001), // Multikey chain
/*<!M><S><D>                                                       */ DEADTRANS( L'D'	,0xF064	,0xF0BD	,0x0001), // Multikey chain
/*<!M><s><e>                                                       */ DEADTRANS( L'e'	,0xF063	,0xF0C0	,0x0001), // Multikey chain
/*<!M><S><E>                                                       */ DEADTRANS( L'E'	,0xF064	,0xF0C1	,0x0001), // Multikey chain
/*<!M><s><e><r>                                                    */ DEADTRANS( L'r'	,0xF0C0	,0x26CE	,0x0000), // 'r' ➔ "⛎" OPHIUCHUS emoji
/*<!M><S><E><R>                                                    */ DEADTRANS( L'R'	,0xF0C1	,0x26CE	,0x0000), // 'R' ➔ "⛎" OPHIUCHUS emoji
/*<!M><s><e><t>                                                    */ DEADTRANS( L't'	,0xF0C0	,0xF0C4	,0x0001), // Multikey chain
/*<!M><s><e><t><m>                                                 */ DEADTRANS( L'm'	,0xF0C4	,0xF0C5	,0x0001), // Multikey chain
/*<!M><s><e><t><m><i>                                              */ DEADTRANS( L'i'	,0xF0C5	,0xF0C6	,0x0001), // Multikey chain
/*<!M><s><e><t><m><i><n>                                           */ DEADTRANS( L'n'	,0xF0C6	,0xF0C7	,0x0001), // Multikey chain
/*<!M><s><e><t><m><i><n><u>                                        */ DEADTRANS( L'u'	,0xF0C7	,0xF0C8	,0x0001), // Multikey chain
/*<!M><s><e><t><m><i><n><u><s>                                     */ DEADTRANS( L's'	,0xF0C8	,0x2216	,0x0000), // 's' ➔ "∖" SET MINUS
/*<!M><S><H>                                                       */ DEADTRANS( L'H'	,0xF064	,0x01A9	,0x0000), // 'H' ➔ "Ʃ" LATIN CAPITAL LETTER ESH
/*<!M><S><h>                                                       */ DEADTRANS( L'h'	,0xF064	,0x01A9	,0x0000), // 'h' ➔ "Ʃ" LATIN CAPITAL LETTER ESH
/*<!M><s><h>                                                       */ DEADTRANS( L'h'	,0xF063	,0x0283	,0x0000), // 'h' ➔ "ʃ" LATIN SMALL LETTER ESH
/*<!M><s><i>                                                       */ DEADTRANS( L'i'	,0xF063	,0xF0CD	,0x0001), // Multikey chain
/*<!M><S><I>                                                       */ DEADTRANS( L'I'	,0xF064	,0xF0CE	,0x0001), // Multikey chain
/*<!M><s><i><n>                                                    */ DEADTRANS( L'n'	,0xF0CD	,0x223F	,0x0000), // 'n' ➔ "∿" SINE WAVE
/*<!M><S><I><N>                                                    */ DEADTRANS( L'N'	,0xF0CE	,0x223F	,0x0000), // 'N' ➔ "∿" SINE WAVE
/*<!M><s><l>                                                       */ DEADTRANS( L'l'	,0xF063	,0x017F	,0x0000), // 'l' ➔ "ſ" LATIN SMALL LETTER LONG S
/*<!M><s><m>                                                       */ DEADTRANS( L'm'	,0xF063	,0x2120	,0x0000), // 'm' ➔ "℠" SERVICE MARK
/*<!M><S><M>                                                       */ DEADTRANS( L'M'	,0xF064	,0x2120	,0x0000), // 'M' ➔ "℠" SERVICE MARK
/*<!M><s><n>                                                       */ DEADTRANS( L'n'	,0xF063	,0xF0D5	,0x0001), // Multikey chain
/*<!M><S><N>                                                       */ DEADTRANS( L'N'	,0xF064	,0xF0D6	,0x0001), // Multikey chain
/*<!M><S><n>                                                       */ DEADTRANS( L'n'	,0xF064	,0x2A19	,0x0000), // 'n' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><n><o>                                                    */ DEADTRANS( L'o'	,0xF0D5	,0x2744	,0x0000), // 'o' ➔ "❄" SNOWFLAKE emoji
/*<!M><S><N><O>                                                    */ DEADTRANS( L'O'	,0xF0D6	,0x2744	,0x0000), // 'O' ➔ "❄" SNOWFLAKE emoji
/*<!M><s><n><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0D5	,0x2A19	,0x0000), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><S><N><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0D6	,0x2A19	,0x0000), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><n><~space>                                               */ DEADTRANS( L' '	,0xF0D5	,0x2A19	,0x0000), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><S><N><~space>                                               */ DEADTRANS( L' '	,0xF0D6	,0x2A19	,0x0000), // ' ' ➔ "⨙" INTEGRAL WITH INTERSECTION
/*<!M><s><o>                                                       */ DEADTRANS( L'o'	,0xF063	,0xF0DD	,0x0001), // Multikey chain
/*<!M><S><O>                                                       */ DEADTRANS( L'O'	,0xF064	,0xF0DE	,0x0001), // Multikey chain
/*<!M><S><o>                                                       */ DEADTRANS( L'o'	,0xF064	,0xF0DF	,0x0001), // Multikey chain
/*<!M><s><o><%greater>                                             */ DEADTRANS( L'>'	,0xF0DD	,0x2232	,0x0000), // '>' ➔ "∲" CLOCKWISE CONTOUR INTEGRAL
/*<!M><S><o><%greater>                                             */ DEADTRANS( L'>'	,0xF0DF	,0x2232	,0x0000), // '>' ➔ "∲" CLOCKWISE CONTOUR INTEGRAL
/*<!M><s><o><%less>                                                */ DEADTRANS( L'<'	,0xF0DD	,0x2233	,0x0000), // '<' ➔ "∳" ANTICLOCKWISE CONTOUR INTEGRAL
/*<!M><S><o><%less>                                                */ DEADTRANS( L'<'	,0xF0DF	,0x2233	,0x0000), // '<' ➔ "∳" ANTICLOCKWISE CONTOUR INTEGRAL
/*<!M><s><o><%period>                                              */ DEADTRANS( L'.'	,0xF0DD	,0x2A15	,0x0000), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><S><o><%period>                                              */ DEADTRANS( L'.'	,0xF0DF	,0x2A15	,0x0000), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><S><O><%period>                                              */ DEADTRANS( L'.'	,0xF0DE	,0x2A15	,0x0000), // '.' ➔ "⨕" INTEGRAL AROUND A POINT OPERATOR
/*<!M><s><o><l>                                                    */ DEADTRANS( L'l'	,0xF0DD	,0x2600	,0x0000), // 'l' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><S><O><L>                                                    */ DEADTRANS( L'L'	,0xF0DE	,0x2600	,0x0000), // 'L' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><s><o><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0DD	,0x222E	,0x0000), // ' ' ➔ "∮" CONTOUR INTEGRAL
/*<!M><S><o><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0DF	,0x2A0A	,0x0000), // ' ' ➔ "⨊" MODULO TWO SUM
/*<!M><s><o><~space>                                               */ DEADTRANS( L' '	,0xF0DD	,0x222E	,0x0000), // ' ' ➔ "∮" CONTOUR INTEGRAL
/*<!M><S><o><~space>                                               */ DEADTRANS( L' '	,0xF0DF	,0x2A0A	,0x0000), // ' ' ➔ "⨊" MODULO TWO SUM
/*<!M><s><p>                                                       */ DEADTRANS( L'p'	,0xF063	,0x2423	,0x0000), // 'p' ➔ "␣" OPEN BOX
/*<!M><S><P>                                                       */ DEADTRANS( L'P'	,0xF064	,0x2423	,0x0000), // 'P' ➔ "␣" OPEN BOX
/*<!M><s><S>                                                       */ DEADTRANS( L'S'	,0xF063	,0x00A7	,0x0000), // 'S' ➔ "§" SECTION SIGN
/*<!M><s><s>                                                       */ DEADTRANS( L's'	,0xF063	,0x00DF	,0x0000), // 's' ➔ "ß" LATIN SMALL LETTER SHARP S
/*<!M><S><S>                                                       */ DEADTRANS( L'S'	,0xF064	,0x1E9E	,0x0000), // 'S' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S><s>                                                       */ DEADTRANS( L's'	,0xF064	,0x1E9E	,0x0000), // 's' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><s><u>                                                       */ DEADTRANS( L'u'	,0xF063	,0xF0F4	,0x0001), // Multikey chain
/*<!M><S><U>                                                       */ DEADTRANS( L'U'	,0xF064	,0xF0F5	,0x0001), // Multikey chain
/*<!M><S><u>                                                       */ DEADTRANS( L'u'	,0xF064	,0x2A1A	,0x0000), // 'u' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><u><n>                                                    */ DEADTRANS( L'n'	,0xF0F4	,0x2600	,0x0000), // 'n' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><S><U><N>                                                    */ DEADTRANS( L'N'	,0xF0F5	,0x2600	,0x0000), // 'N' ➔ "☀" BLACK SUN WITH RAYS emoji
/*<!M><s><u><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0F4	,0x2A1A	,0x0000), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><S><U><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF0F5	,0x2A1A	,0x0000), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><u><~space>                                               */ DEADTRANS( L' '	,0xF0F4	,0x2A1A	,0x0000), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><S><U><~space>                                               */ DEADTRANS( L' '	,0xF0F5	,0x2A1A	,0x0000), // ' ' ➔ "⨚" INTEGRAL WITH UNION
/*<!M><s><v>                                                       */ DEADTRANS( L'v'	,0xF063	,0xF0FC	,0x0001), // Multikey chain
/*<!M><S><V>                                                       */ DEADTRANS( L'V'	,0xF064	,0xF0FD	,0x0001), // Multikey chain
/*<!M><s><v><c>                                                    */ DEADTRANS( L'c'	,0xF0FC	,0x20A1	,0x0000), // 'c' ➔ "₡" COLON SIGN, El Salvador Colon EL SALVADOR
/*<!M><S><V><C>                                                    */ DEADTRANS( L'C'	,0xF0FD	,0x20A1	,0x0000), // 'C' ➔ "₡" COLON SIGN, El Salvador Colon EL SALVADOR
/*<!M><s><x>                                                       */ DEADTRANS( L'x'	,0xF063	,0x2A18	,0x0000), // 'x' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><S><x>                                                       */ DEADTRANS( L'x'	,0xF064	,0x2A18	,0x0000), // 'x' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><S><X>                                                       */ DEADTRANS( L'X'	,0xF064	,0x2A18	,0x0000), // 'X' ➔ "⨘" INTEGRAL WITH TIMES SIGN
/*<!M><s><z>                                                       */ DEADTRANS( L'z'	,0xF063	,0x00DF	,0x0000), // 'z' ➔ "ß" LATIN SMALL LETTER SHARP S
/*<!M><S><Z>                                                       */ DEADTRANS( L'Z'	,0xF064	,0x1E9E	,0x0000), // 'Z' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S><z>                                                       */ DEADTRANS( L'z'	,0xF064	,0x1E9E	,0x0000), // 'z' ➔ "ẞ" LATIN CAPITAL LETTER SHARP S
/*<!M><S><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF064	,0x2211	,0x0000), // ' ' ➔ "∑" N-ARY SUMMATION
/*<!M><s><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF063	,0x222B	,0x0000), // ' ' ➔ "∫" INTEGRAL
/*<!M><S><~space>                                                  */ DEADTRANS( L' '	,0xF064	,0x2211	,0x0000), // ' ' ➔ "∑" N-ARY SUMMATION
/*<!M><s><~space>                                                  */ DEADTRANS( L' '	,0xF063	,0x222B	,0x0000), // ' ' ➔ "∫" INTEGRAL
/*<!M><T>                                                          */ DEADTRANS( L'T'	,0x00A6	,0xF10A	,0x0001), // Multikey chain
/*<!M><t>                                                          */ DEADTRANS( L't'	,0x00A6	,0xF10B	,0x0001), // Multikey chain
/*<!M><T><%apostrophe>                                             */ DEADTRANS( L'\''	,0xF10A	,0x2ADF	,0x0000), // ''' ➔ "⫟" SHORT DOWN TACK
/*<!M><T><%aprightsingquotmark>                                    */ DEADTRANS( 0x2019	,0xF10A	,0x2ADF	,0x0000), // '’' ➔ "⫟" SHORT DOWN TACK
/*<!M><T><%at>                                                     */ DEADTRANS( L'@'	,0xF10A	,0x03F4	,0x0000), // '@' ➔ "ϴ" GREEK CAPITAL THETA SYMBOL
/*<!M><t><%at>                                                     */ DEADTRANS( L'@'	,0xF10B	,0x03D1	,0x0000), // '@' ➔ "ϑ" GREEK THETA SYMBOL
/*<!M><T><%bar>                                                    */ DEADTRANS( L'|'	,0xF10A	,0x27D9	,0x0000), // '|' ➔ "⟙" LARGE DOWN TACK
/*<!M><t><%equal>                                                  */ DEADTRANS( L'='	,0xF10B	,0x20AE	,0x0000), // '=' ➔ "₮" TUGRIK SIGN
/*<!M><T><%equal>                                                  */ DEADTRANS( L'='	,0xF10A	,0x20AE	,0x0000), // '=' ➔ "₮" TUGRIK SIGN
/*<!M><T><%greater>                                                */ DEADTRANS( L'>'	,0xF10A	,0xF113	,0x0001), // Multikey chain
/*<!M><T><%greater><%apostrophe>                                   */ DEADTRANS( L'\''	,0xF113	,0x22A6	,0x0000), // ''' ➔ "⊦" ASSERTION
/*<!M><T><%greater><%aprightsingquotmark>                          */ DEADTRANS( 0x2019	,0xF113	,0x22A6	,0x0000), // '’' ➔ "⊦" ASSERTION
/*<!M><T><%greater><%bar>                                          */ DEADTRANS( L'|'	,0xF113	,0x27DD	,0x0000), // '|' ➔ "⟝" LONG RIGHT TACK
/*<!M><T><%greater><%less>                                         */ DEADTRANS( L'<'	,0xF113	,0x27DB	,0x0000), // '<' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><T><%greater><%slash>                                        */ DEADTRANS( L'/'	,0xF113	,0x22AC	,0x0000), // '/' ➔ "⊬" DOES NOT PROVE
/*<!M><T><%greater><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF113	,0x22A2	,0x0000), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><T><%greater><~space>                                        */ DEADTRANS( L' '	,0xF113	,0x22A2	,0x0000), // ' ' ➔ "⊢" RIGHT TACK
/*<!M><T><%less>                                                   */ DEADTRANS( L'<'	,0xF10A	,0xF11B	,0x0001), // Multikey chain
/*<!M><T><%less><%apostrophe>                                      */ DEADTRANS( L'\''	,0xF11B	,0x2ADE	,0x0000), // ''' ➔ "⫞" SHORT LEFT TACK
/*<!M><T><%less><%aprightsingquotmark>                             */ DEADTRANS( 0x2019	,0xF11B	,0x2ADE	,0x0000), // '’' ➔ "⫞" SHORT LEFT TACK
/*<!M><T><%less><%bar>                                             */ DEADTRANS( L'|'	,0xF11B	,0x27DE	,0x0000), // '|' ➔ "⟞" LONG LEFT TACK
/*<!M><T><%less><%greater>                                         */ DEADTRANS( L'>'	,0xF11B	,0x27DB	,0x0000), // '>' ➔ "⟛" LEFT AND RIGHT TACK
/*<!M><T><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xF11B	,0x22A3	,0x0000), // ' ' ➔ "⊣" LEFT TACK
/*<!M><T><%less><~space>                                           */ DEADTRANS( L' '	,0xF11B	,0x22A3	,0x0000), // ' ' ➔ "⊣" LEFT TACK
/*<!M><t><%minus>                                                  */ DEADTRANS( L'-'	,0xF10B	,0x20AE	,0x0000), // '-' ➔ "₮" TUGRIK SIGN
/*<!M><T><%minus>                                                  */ DEADTRANS( L'-'	,0xF10A	,0x20AE	,0x0000), // '-' ➔ "₮" TUGRIK SIGN
/*<!M><T><%percent>                                                */ DEADTRANS( L'%'	,0xF10A	,0xF124	,0x0001), // Multikey chain
/*<!M><T><%percent><%apostrophe>                                   */ DEADTRANS( L'\''	,0xF124	,0x2AE0	,0x0000), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><T><%percent><%bar>                                          */ DEADTRANS( L'|'	,0xF124	,0x27D8	,0x0000), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><T><%percent><%percent>                                      */ DEADTRANS( L'%'	,0xF124	,0x2AE9	,0x0000), // '%' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF124	,0x22A5	,0x0000), // ' ' ➔ "⊥" UP TACK
/*<!M><T><%percent><~space>                                        */ DEADTRANS( L' '	,0xF124	,0x22A5	,0x0000), // ' ' ➔ "⊥" UP TACK
/*<!M><t><1>                                                       */ DEADTRANS( L'1'	,0xF10B	,0xA716	,0x0000), // '1' ➔ "꜖" MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*<!M><T><1>                                                       */ DEADTRANS( L'1'	,0xF10A	,0xA716	,0x0000), // '1' ➔ "꜖" MODIFIER LETTER EXTRA-LOW LEFT-STEM TONE BAR
/*<!M><T><2>                                                       */ DEADTRANS( L'2'	,0xF10A	,0xF12D	,0x0001), // Multikey chain
/*<!M><t><2>                                                       */ DEADTRANS( L'2'	,0xF10B	,0xA715	,0x0000), // '2' ➔ "꜕" MODIFIER LETTER LOW LEFT-STEM TONE BAR
/*<!M><T><2><%greater>                                             */ DEADTRANS( L'>'	,0xF12D	,0xF12E	,0x0001), // Multikey chain
/*<!M><T><2><%greater><%apostrophe>                                */ DEADTRANS( L'\''	,0xF12E	,0x22A7	,0x0000), // ''' ➔ "⊧" MODELS
/*<!M><T><2><%greater><%aprightsingquotmark>                       */ DEADTRANS( 0x2019	,0xF12E	,0x22A7	,0x0000), // '’' ➔ "⊧" MODELS
/*<!M><T><2><%greater><%less>                                      */ DEADTRANS( L'<'	,0xF12E	,0x27DA	,0x0000), // '<' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><T><2><%greater><%slash>                                     */ DEADTRANS( L'/'	,0xF12E	,0x22AD	,0x0000), // '/' ➔ "⊭" NOT TRUE
/*<!M><T><2><%greater><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF12E	,0x22A8	,0x0000), // ' ' ➔ "⊨" TRUE
/*<!M><T><2><%greater><~space>                                     */ DEADTRANS( L' '	,0xF12E	,0x22A8	,0x0000), // ' ' ➔ "⊨" TRUE
/*<!M><T><2><%less>                                                */ DEADTRANS( L'<'	,0xF12D	,0xF135	,0x0001), // Multikey chain
/*<!M><T><2><%less><%greater>                                      */ DEADTRANS( L'>'	,0xF135	,0x27DA	,0x0000), // '>' ➔ "⟚" LEFT AND RIGHT DOUBLE TURNSTILE
/*<!M><T><2><%less><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF135	,0x2AE4	,0x0000), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><T><2><%less><~space>                                        */ DEADTRANS( L' '	,0xF135	,0x2AE4	,0x0000), // ' ' ➔ "⫤" VERTICAL BAR DOUBLE LEFT TURNSTILE
/*<!M><T><2><%percent>                                             */ DEADTRANS( L'%'	,0xF12D	,0x2AEB	,0x0000), // '%' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><2><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF12D	,0x2AEA	,0x0000), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><T><2><~space>                                               */ DEADTRANS( L' '	,0xF12D	,0x2AEA	,0x0000), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><T><3>                                                       */ DEADTRANS( L'3'	,0xF10A	,0xF13D	,0x0001), // Multikey chain
/*<!M><t><3>                                                       */ DEADTRANS( L'3'	,0xF10B	,0xA714	,0x0000), // '3' ➔ "꜔" MODIFIER LETTER MID LEFT-STEM TONE BAR
/*<!M><T><3><%greater>                                             */ DEADTRANS( L'>'	,0xF13D	,0x2AE2	,0x0000), // '>' ➔ "⫢" VERTICAL BAR TRIPLE RIGHT TURNSTILE
/*<!M><t><4>                                                       */ DEADTRANS( L'4'	,0xF10B	,0xA713	,0x0000), // '4' ➔ "꜓" MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*<!M><T><4>                                                       */ DEADTRANS( L'4'	,0xF10A	,0xA713	,0x0000), // '4' ➔ "꜓" MODIFIER LETTER HIGH LEFT-STEM TONE BAR
/*<!M><t><5>                                                       */ DEADTRANS( L'5'	,0xF10B	,0xA712	,0x0000), // '5' ➔ "꜒" MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*<!M><T><5>                                                       */ DEADTRANS( L'5'	,0xF10A	,0xA712	,0x0000), // '5' ➔ "꜒" MODIFIER LETTER EXTRA-HIGH LEFT-STEM TONE BAR
/*<!M><t><a>                                                       */ DEADTRANS( L'a'	,0xF10B	,0xF143	,0x0001), // Multikey chain
/*<!M><T><A>                                                       */ DEADTRANS( L'A'	,0xF10A	,0xF144	,0x0001), // Multikey chain
/*<!M><t><a><b>                                                    */ DEADTRANS( L'b'	,0xF143	,0x21B9	,0x0000), // 'b' ➔ "↹" LEFTWARDS ARROW TO BAR OVER RIGHTWARDS ARROW TO BAR, tab with shift tab
/*<!M><T><A><B>                                                    */ DEADTRANS( L'B'	,0xF144	,0x2B7E	,0x0000), // 'B' ➔ "⭾" HORIZONTAL TAB KEY
/*<!M><t><a><i>                                                    */ DEADTRANS( L'i'	,0xF143	,0x25C9	,0x0000), // 'i' ➔ "◉" FISHEYE, Japanese tainome, bullet
/*<!M><T><A><I>                                                    */ DEADTRANS( L'I'	,0xF144	,0x25C9	,0x0000), // 'I' ➔ "◉" FISHEYE, Japanese tainome, bullet
/*<!M><t><a><u>                                                    */ DEADTRANS( L'u'	,0xF143	,0xF149	,0x0001), // Multikey chain
/*<!M><T><A><U>                                                    */ DEADTRANS( L'U'	,0xF144	,0xF14A	,0x0001), // Multikey chain
/*<!M><t><a><u><r>                                                 */ DEADTRANS( L'r'	,0xF149	,0x2649	,0x0000), // 'r' ➔ "♉" TAURUS emoji
/*<!M><T><A><U><R>                                                 */ DEADTRANS( L'R'	,0xF14A	,0x2649	,0x0000), // 'R' ➔ "♉" TAURUS emoji
/*<!M><t><c>                                                       */ DEADTRANS( L'c'	,0xF10B	,0x02A8	,0x0000), // 'c' ➔ "ʨ" LATIN SMALL LETTER TC DIGRAPH WITH CURL
/*<!M><t><e>                                                       */ DEADTRANS( L'e'	,0xF10B	,0xF150	,0x0001), // Multikey chain
/*<!M><T><E>                                                       */ DEADTRANS( L'E'	,0xF10A	,0x2121	,0x0000), // 'E' ➔ "℡" TELEPHONE SIGN
/*<!M><T><e>                                                       */ DEADTRANS( L'e'	,0xF10A	,0x2121	,0x0000), // 'e' ➔ "℡" TELEPHONE SIGN
/*<!M><t><e><c>                                                    */ DEADTRANS( L'c'	,0xF150	,0x02A7	,0x0000), // 'c' ➔ "ʧ" LATIN SMALL LETTER TESH DIGRAPH
/*<!M><t><e><l>                                                    */ DEADTRANS( L'l'	,0xF150	,0x2121	,0x0000), // 'l' ➔ "℡" TELEPHONE SIGN
/*<!M><t><e><s>                                                    */ DEADTRANS( L's'	,0xF150	,0x02A7	,0x0000), // 's' ➔ "ʧ" LATIN SMALL LETTER TESH DIGRAPH
/*<!M><T><H>                                                       */ DEADTRANS( L'H'	,0xF10A	,0xF155	,0x0001), // Multikey chain
/*<!M><t><h>                                                       */ DEADTRANS( L'h'	,0xF10B	,0xF156	,0x0001), // Multikey chain
/*<!M><T><h>                                                       */ DEADTRANS( L'h'	,0xF10A	,0x00DE	,0x0000), // 'h' ➔ "Þ" LATIN CAPITAL LETTER THORN
/*<!M><t><h><%slash>                                               */ DEADTRANS( L'/'	,0xF156	,0x1D7A	,0x0000), // '/' ➔ "ᵺ" LATIN SMALL LETTER TH WITH STRIKETHROUGH
/*<!M><t><h><b>                                                    */ DEADTRANS( L'b'	,0xF156	,0x0E3F	,0x0000), // 'b' ➔ "฿" THAI CURRENCY SYMBOL BAHT, Baht THAILAND
/*<!M><T><H><B>                                                    */ DEADTRANS( L'B'	,0xF155	,0x0E3F	,0x0000), // 'B' ➔ "฿" THAI CURRENCY SYMBOL BAHT, Baht THAILAND
/*<!M><T><H><~space>                                               */ DEADTRANS( L' '	,0xF155	,0x00DE	,0x0000), // ' ' ➔ "Þ" LATIN CAPITAL LETTER THORN
/*<!M><t><h><~space>                                               */ DEADTRANS( L' '	,0xF156	,0x00FE	,0x0000), // ' ' ➔ "þ" LATIN SMALL LETTER THORN
/*<!M><t><m>                                                       */ DEADTRANS( L'm'	,0xF10B	,0x2122	,0x0000), // 'm' ➔ "™" TRADE MARK SIGN emoji
/*<!M><T><M>                                                       */ DEADTRANS( L'M'	,0xF10A	,0x2122	,0x0000), // 'M' ➔ "™" TRADE MARK SIGN emoji
/*<!M><t><n>                                                       */ DEADTRANS( L'n'	,0xF10B	,0xF15F	,0x0001), // Multikey chain
/*<!M><T><N>                                                       */ DEADTRANS( L'N'	,0xF10A	,0xF160	,0x0001), // Multikey chain
/*<!M><T><n>                                                       */ DEADTRANS( L'n'	,0xF10A	,0x2ADA	,0x0000), // 'n' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><t><n><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF15F	,0x2ADA	,0x0000), // ' ' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><t><n><~space>                                               */ DEADTRANS( L' '	,0xF15F	,0x2ADA	,0x0000), // ' ' ➔ "⫚" PITCHFORK WITH TEE TOP
/*<!M><t><o>                                                       */ DEADTRANS( L'o'	,0xF10B	,0xF166	,0x0001), // Multikey chain
/*<!M><T><O>                                                       */ DEADTRANS( L'O'	,0xF10A	,0xF167	,0x0001), // Multikey chain
/*<!M><T><o>                                                       */ DEADTRANS( L'o'	,0xF10A	,0x2AF1	,0x0000), // 'o' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><o><x>                                                    */ DEADTRANS( L'x'	,0xF166	,0x2620	,0x0000), // 'x' ➔ "☠" SKULL AND CROSSBONES emoji
/*<!M><T><O><X>                                                    */ DEADTRANS( L'X'	,0xF167	,0x2620	,0x0000), // 'X' ➔ "☠" SKULL AND CROSSBONES emoji
/*<!M><t><o><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF166	,0x2AF1	,0x0000), // ' ' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><o><~space>                                               */ DEADTRANS( L' '	,0xF166	,0x2AF1	,0x0000), // ' ' ➔ "⫱" DOWN TACK WITH CIRCLE BELOW
/*<!M><t><r>                                                       */ DEADTRANS( L'r'	,0xF10B	,0xF16E	,0x0001), // Multikey chain
/*<!M><T><R>                                                       */ DEADTRANS( L'R'	,0xF10A	,0xF16F	,0x0001), // Multikey chain
/*<!M><t><r><y>                                                    */ DEADTRANS( L'y'	,0xF16E	,0x20BA	,0x0000), // 'y' ➔ "₺" TURKISH LIRA SIGN, Turkish Lira TÜRKİYE
/*<!M><T><R><Y>                                                    */ DEADTRANS( L'Y'	,0xF16F	,0x20BA	,0x0000), // 'Y' ➔ "₺" TURKISH LIRA SIGN, Turkish Lira TÜRKİYE
/*<!M><t><s>                                                       */ DEADTRANS( L's'	,0xF10B	,0x02A6	,0x0000), // 's' ➔ "ʦ" LATIN SMALL LETTER TS DIGRAPH
/*<!M><T><T>                                                       */ DEADTRANS( L'T'	,0xF10A	,0xF173	,0x0001), // Multikey chain
/*<!M><T><T><%apostrophe>                                          */ DEADTRANS( L'\''	,0xF173	,0x2AE0	,0x0000), // ''' ➔ "⫠" SHORT UP TACK
/*<!M><T><T><%bar>                                                 */ DEADTRANS( L'|'	,0xF173	,0x27D8	,0x0000), // '|' ➔ "⟘" LARGE UP TACK
/*<!M><T><T><%percent>                                             */ DEADTRANS( L'%'	,0xF173	,0xF176	,0x0001), // Multikey chain
/*<!M><T><T><%percent><%apostrophe>                                */ DEADTRANS( L'\''	,0xF176	,0x2AE9	,0x0000), // ''' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><T><%percent><%aprightsingquotmark>                       */ DEADTRANS( 0x2019	,0xF176	,0x2AE9	,0x0000), // '’' ➔ "⫩" SHORT UP TACK ABOVE SHORT DOWN TACK
/*<!M><T><T><%percent><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF176	,0x2AEB	,0x0000), // ' ' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><T><%percent><~space>                                     */ DEADTRANS( L' '	,0xF176	,0x2AEB	,0x0000), // ' ' ➔ "⫫" DOUBLE UP TACK
/*<!M><T><T><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF173	,0x2AEA	,0x0000), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><T><T><~space>                                               */ DEADTRANS( L' '	,0xF173	,0x2AEA	,0x0000), // ' ' ➔ "⫪" DOUBLE DOWN TACK
/*<!M><t><u>                                                       */ DEADTRANS( L'u'	,0xF10B	,0xA777	,0x0000), // 'u' ➔ "ꝷ" LATIN SMALL LETTER TUM
/*<!M><T><Z>                                                       */ DEADTRANS( L'Z'	,0xF10A	,0xA728	,0x0000), // 'Z' ➔ "Ꜩ" LATIN CAPITAL LETTER TZ
/*<!M><T><z>                                                       */ DEADTRANS( L'z'	,0xF10A	,0xA728	,0x0000), // 'z' ➔ "Ꜩ" LATIN CAPITAL LETTER TZ
/*<!M><t><z>                                                       */ DEADTRANS( L'z'	,0xF10B	,0xA729	,0x0000), // 'z' ➔ "ꜩ" LATIN SMALL LETTER TZ
/*<!M><T><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF10A	,0x22A4	,0x0000), // ' ' ➔ "⊤" DOWN TACK
/*<!M><t><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF10B	,0x22BA	,0x0000), // ' ' ➔ "⊺" INTERCALATE
/*<!M><T><~space>                                                  */ DEADTRANS( L' '	,0xF10A	,0x22A4	,0x0000), // ' ' ➔ "⊤" DOWN TACK
/*<!M><t><~space>                                                  */ DEADTRANS( L' '	,0xF10B	,0x22BA	,0x0000), // ' ' ➔ "⊺" INTERCALATE
/*<!M><u>                                                          */ DEADTRANS( L'u'	,0x00A6	,0xF185	,0x0001), // Multikey chain
/*<!M><U>                                                          */ DEADTRANS( L'U'	,0x00A6	,0xF186	,0x0001), // Multikey chain
/*<!M><U><%at>                                                     */ DEADTRANS( L'@'	,0xF186	,0x03F4	,0x0000), // '@' ➔ "ϴ" GREEK CAPITAL THETA SYMBOL
/*<!M><u><%at>                                                     */ DEADTRANS( L'@'	,0xF185	,0x03D1	,0x0000), // '@' ➔ "ϑ" GREEK THETA SYMBOL
/*<!M><u><%bracketleft>                                            */ DEADTRANS( L'['	,0xF185	,0x2294	,0x0000), // '[' ➔ "⊔" SQUARE CUP
/*<!M><U><%bracketleft>                                            */ DEADTRANS( L'['	,0xF186	,0x2A06	,0x0000), // '[' ➔ "⨆" N-ARY SQUARE UNION OPERATOR
/*<!M><u><%bracketright>                                           */ DEADTRANS( L']'	,0xF185	,0x2294	,0x0000), // ']' ➔ "⊔" SQUARE CUP
/*<!M><U><%bracketright>                                           */ DEADTRANS( L']'	,0xF186	,0x2A06	,0x0000), // ']' ➔ "⨆" N-ARY SQUARE UNION OPERATOR
/*<!M><u><%less>                                                   */ DEADTRANS( L'<'	,0xF185	,0x228C	,0x0000), // '<' ➔ "⊌" MULTISET
/*<!M><u><%minus>                                                  */ DEADTRANS( L'-'	,0xF185	,0xF18E	,0x0001), // Multikey chain
/*<!M><u><%minus><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xF18E	,0x2A41	,0x0000), // ' ' ➔ "⩁" UNION WITH MINUS SIGN
/*<!M><u><%minus><~space>                                          */ DEADTRANS( L' '	,0xF18E	,0x2A41	,0x0000), // ' ' ➔ "⩁" UNION WITH MINUS SIGN
/*<!M><u><%period>                                                 */ DEADTRANS( L'.'	,0xF185	,0x228D	,0x0000), // '.' ➔ "⊍" MULTISET MULTIPLICATION
/*<!M><U><%period>                                                 */ DEADTRANS( L'.'	,0xF186	,0x2A03	,0x0000), // '.' ➔ "⨃" N-ARY UNION OPERATOR WITH DOT
/*<!M><u><%plus>                                                   */ DEADTRANS( L'+'	,0xF185	,0x228E	,0x0000), // '+' ➔ "⊎" MULTISET UNION
/*<!M><U><%plus>                                                   */ DEADTRANS( L'+'	,0xF186	,0x2A04	,0x0000), // '+' ➔ "⨄" N-ARY UNION OPERATOR WITH PLUS
/*<!M><u><%underscore>                                             */ DEADTRANS( L'_'	,0xF185	,0x2A48	,0x0000), // '_' ➔ "⩈" UNION ABOVE BAR ABOVE INTERSECTION
/*<!M><u><a>                                                       */ DEADTRANS( L'a'	,0xF185	,0xF196	,0x0001), // Multikey chain
/*<!M><U><A>                                                       */ DEADTRANS( L'A'	,0xF186	,0xF197	,0x0001), // Multikey chain
/*<!M><u><a><h>                                                    */ DEADTRANS( L'h'	,0xF196	,0x20B4	,0x0000), // 'h' ➔ "₴" HRYVNIA SIGN, Hryvnia UKRAINE
/*<!M><U><A><H>                                                    */ DEADTRANS( L'H'	,0xF197	,0x20B4	,0x0000), // 'H' ➔ "₴" HRYVNIA SIGN, Hryvnia UKRAINE
/*<!M><u><e>                                                       */ DEADTRANS( L'e'	,0xF185	,0x1D6B	,0x0000), // 'e' ➔ "ᵫ" LATIN SMALL LETTER UE
/*<!M><u><i>                                                       */ DEADTRANS( L'i'	,0xF185	,0xAB50	,0x0000), // 'i' ➔ "ꭐ" LATIN SMALL LETTER UI
/*<!M><u><m>                                                       */ DEADTRANS( L'm'	,0xF185	,0xA778	,0x0000), // 'm' ➔ "ꝸ" LATIN SMALL LETTER UM
/*<!M><u><n>                                                       */ DEADTRANS( L'n'	,0xF185	,0xF19D	,0x0001), // Multikey chain
/*<!M><u><n><i>                                                    */ DEADTRANS( L'i'	,0xF19D	,0xF19E	,0x0001), // Multikey chain
/*<!M><u><n><i><o>                                                 */ DEADTRANS( L'o'	,0xF19E	,0xF19F	,0x0001), // Multikey chain
/*<!M><u><n><i><o><n>                                              */ DEADTRANS( L'n'	,0xF19F	,0x222A	,0x0000), // 'n' ➔ "∪" UNION French name
/*<!M><u><n><~nbspace>                                             */ DEADTRANS( 0x00A0	,0xF19D	,0x2A46	,0x0000), // ' ' ➔ "⩆" UNION ABOVE INTERSECTION
/*<!M><u><n><~space>                                               */ DEADTRANS( L' '	,0xF19D	,0x2A46	,0x0000), // ' ' ➔ "⩆" UNION ABOVE INTERSECTION
/*<!M><u><o>                                                       */ DEADTRANS( L'o'	,0xF185	,0xAB63	,0x0000), // 'o' ➔ "ꭣ" LATIN SMALL LETTER UO
/*<!M><u><u>                                                       */ DEADTRANS( L'u'	,0xF185	,0x2A4A	,0x0000), // 'u' ➔ "⩊" UNION BESIDE AND JOINED WITH UNION
/*<!M><u><v>                                                       */ DEADTRANS( L'v'	,0xF185	,0x2A45	,0x0000), // 'v' ➔ "⩅" UNION WITH LOGICAL OR
/*<!M><u><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF185	,0x222A	,0x0000), // ' ' ➔ "∪" UNION
/*<!M><U><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF186	,0x22C3	,0x0000), // ' ' ➔ "⋃" N-ARY UNION
/*<!M><u><~space>                                                  */ DEADTRANS( L' '	,0xF185	,0x222A	,0x0000), // ' ' ➔ "∪" UNION
/*<!M><U><~space>                                                  */ DEADTRANS( L' '	,0xF186	,0x22C3	,0x0000), // ' ' ➔ "⋃" N-ARY UNION
/*<!M><V>                                                          */ DEADTRANS( L'V'	,0x00A6	,0xF1AA	,0x0001), // Multikey chain
/*<!M><v>                                                          */ DEADTRANS( L'v'	,0x00A6	,0xF1AB	,0x0001), // Multikey chain
/*<!M><v><%backslash>                                              */ DEADTRANS( L'\\'	,0xF1AB	,0xF1AD	,0x0001), // Multikey chain
/*<!M><V><%backslash>                                              */ DEADTRANS( L'\\'	,0xF1AA	,0x22C0	,0x0000), // '\' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><v><%backslash><%parenleft>                                  */ DEADTRANS( L'('	,0xF1AD	,0xF1AE	,0x0001), // Multikey chain
/*<!M><v><%backslash><%parenleft><%parenright>                     */ DEADTRANS( L')'	,0xF1AE	,0x22CF	,0x0000), // ')' ➔ "⋏" CURLY LOGICAL AND
/*<!M><v><%backslash><%parenright>                                 */ DEADTRANS( L')'	,0xF1AD	,0xF1B0	,0x0001), // Multikey chain
/*<!M><v><%backslash><%parenright><%parenleft>                     */ DEADTRANS( L'('	,0xF1B0	,0x22CF	,0x0000), // '(' ➔ "⋏" CURLY LOGICAL AND
/*<!M><v><%bar>                                                    */ DEADTRANS( L'|'	,0xF1AB	,0x2A5B	,0x0000), // '|' ➔ "⩛" LOGICAL OR WITH MIDDLE STEM
/*<!M><V><%bar>                                                    */ DEADTRANS( L'|'	,0xF1AA	,0x2A5B	,0x0000), // '|' ➔ "⩛" LOGICAL OR WITH MIDDLE STEM
/*<!M><v><%bracketright>                                           */ DEADTRANS( L']'	,0xF1AB	,0x27CF	,0x0000), // ']' ➔ "⟏" SQUARED LOGICAL OR
/*<!M><v><%equal>                                                  */ DEADTRANS( L'='	,0xF1AB	,0x225A	,0x0000), // '=' ➔ "≚" EQUIANGULAR TO
/*<!M><v><%minus>                                                  */ DEADTRANS( L'-'	,0xF1AB	,0x2A5D	,0x0000), // '-' ➔ "⩝" LOGICAL OR WITH HORIZONTAL DASH
/*<!M><V><%minus>                                                  */ DEADTRANS( L'-'	,0xF1AA	,0x2A5D	,0x0000), // '-' ➔ "⩝" LOGICAL OR WITH HORIZONTAL DASH
/*<!M><v><%parenleft>                                              */ DEADTRANS( L'('	,0xF1AB	,0xF1B8	,0x0001), // Multikey chain
/*<!M><v><%parenleft><%parenright>                                 */ DEADTRANS( L')'	,0xF1B8	,0x22CE	,0x0000), // ')' ➔ "⋎" CURLY LOGICAL OR
/*<!M><v><%parenright>                                             */ DEADTRANS( L')'	,0xF1AB	,0xF1BA	,0x0001), // Multikey chain
/*<!M><v><%parenright><%parenleft>                                 */ DEADTRANS( L'('	,0xF1BA	,0x22CE	,0x0000), // '(' ➔ "⋎" CURLY LOGICAL OR
/*<!M><v><%percent>                                                */ DEADTRANS( L'%'	,0xF1AB	,0xF1BC	,0x0001), // Multikey chain
/*<!M><V><%percent>                                                */ DEADTRANS( L'%'	,0xF1AA	,0xF1BD	,0x0001), // Multikey chain
/*<!M><v><%percent><%bar>                                          */ DEADTRANS( L'|'	,0xF1BC	,0x2A5A	,0x0000), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><V><%percent><%bar>                                          */ DEADTRANS( L'|'	,0xF1BD	,0x2A5A	,0x0000), // '|' ➔ "⩚" LOGICAL AND WITH MIDDLE STEM
/*<!M><v><%percent><%bracketright>                                 */ DEADTRANS( L']'	,0xF1BC	,0x27CE	,0x0000), // ']' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><v><%percent><%minus>                                        */ DEADTRANS( L'-'	,0xF1BC	,0x2A5C	,0x0000), // '-' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><V><%percent><%minus>                                        */ DEADTRANS( L'-'	,0xF1BD	,0x2A5C	,0x0000), // '-' ➔ "⩜" LOGICAL AND WITH HORIZONTAL DASH
/*<!M><v><%percent><%period>                                       */ DEADTRANS( L'.'	,0xF1BC	,0x27D1	,0x0000), // '.' ➔ "⟑" AND WITH DOT
/*<!M><v><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xF1BC	,0xF1C4	,0x0001), // Multikey chain
/*<!M><V><%percent><%underscore>                                   */ DEADTRANS( L'_'	,0xF1BD	,0xF1C5	,0x0001), // Multikey chain
/*<!M><v><%percent><%underscore><%underscore>                      */ DEADTRANS( L'_'	,0xF1C4	,0x2A60	,0x0000), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><V><%percent><%underscore><%underscore>                      */ DEADTRANS( L'_'	,0xF1C5	,0x2A60	,0x0000), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><v><%percent><%underscore><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF1C4	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><V><%percent><%underscore><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF1C5	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><v><%percent><%underscore><~space>                           */ DEADTRANS( L' '	,0xF1C4	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><V><%percent><%underscore><~space>                           */ DEADTRANS( L' '	,0xF1C5	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><v><%percent><v>                                             */ DEADTRANS( L'v'	,0xF1BC	,0x2A59	,0x0000), // 'v' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><V><%percent><V>                                             */ DEADTRANS( L'V'	,0xF1BD	,0x2A59	,0x0000), // 'V' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v><%percent><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF1BC	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><v><%percent><~space>                                        */ DEADTRANS( L' '	,0xF1BC	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><v><%period>                                                 */ DEADTRANS( L'.'	,0xF1AB	,0x27C7	,0x0000), // '.' ➔ "⟇" OR WITH DOT INSIDE
/*<!M><V><%slash>                                                  */ DEADTRANS( L'/'	,0xF1AA	,0x2123	,0x0000), // '/' ➔ "℣" VERSICLE
/*<!M><v><%slash>                                                  */ DEADTRANS( L'/'	,0xF1AB	,0x2123	,0x0000), // '/' ➔ "℣" VERSICLE
/*<!M><v><%underscore>                                             */ DEADTRANS( L'_'	,0xF1AB	,0xF1D3	,0x0001), // Multikey chain
/*<!M><v><%underscore><%comma>                                     */ DEADTRANS( L','	,0xF1D3	,0x2A61	,0x0000), // ',' ➔ "⩡" SMALL VEE WITH UNDERBAR
/*<!M><v><%underscore><%underscore>                                */ DEADTRANS( L'_'	,0xF1D3	,0x2A63	,0x0000), // '_' ➔ "⩣" LOGICAL OR WITH DOUBLE UNDERBAR
/*<!M><v><%underscore><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF1D3	,0x22BB	,0x0000), // ' ' ➔ "⊻" XOR
/*<!M><v><%underscore><~space>                                     */ DEADTRANS( L' '	,0xF1D3	,0x22BB	,0x0000), // ' ' ➔ "⊻" XOR
/*<!M><v><2>                                                       */ DEADTRANS( L'2'	,0xF1AB	,0x221A	,0x0000), // '2' ➔ "√" SQUARE ROOT
/*<!M><v><3>                                                       */ DEADTRANS( L'3'	,0xF1AB	,0x221B	,0x0000), // '3' ➔ "∛" CUBE ROOT
/*<!M><v><4>                                                       */ DEADTRANS( L'4'	,0xF1AB	,0x221C	,0x0000), // '4' ➔ "∜" FOURTH ROOT
/*<!M><v><a>                                                       */ DEADTRANS( L'a'	,0xF1AB	,0x2A59	,0x0000), // 'a' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v><A>                                                       */ DEADTRANS( L'A'	,0xF1AB	,0x2A59	,0x0000), // 'A' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><V><A>                                                       */ DEADTRANS( L'A'	,0xF1AA	,0x2A59	,0x0000), // 'A' ➔ "⩙" LOGICAL OR OVERLAPPING LOGICAL AND
/*<!M><v><e>                                                       */ DEADTRANS( L'e'	,0xF1AB	,0xF1DE	,0x0001), // Multikey chain
/*<!M><V><E>                                                       */ DEADTRANS( L'E'	,0xF1AA	,0xF1DF	,0x0001), // Multikey chain
/*<!M><v><e><r>                                                    */ DEADTRANS( L'r'	,0xF1DE	,0xF1E0	,0x0001), // Multikey chain
/*<!M><V><E><R>                                                    */ DEADTRANS( L'R'	,0xF1DF	,0xF1E1	,0x0001), // Multikey chain
/*<!M><v><e><r><s>                                                 */ DEADTRANS( L's'	,0xF1E0	,0x2652	,0x0000), // 's' ➔ "♒" AQUARIUS emoji
/*<!M><V><E><R><S>                                                 */ DEADTRANS( L'S'	,0xF1E1	,0x2652	,0x0000), // 'S' ➔ "♒" AQUARIUS emoji
/*<!M><v><i>                                                       */ DEADTRANS( L'i'	,0xF1AB	,0xF1E4	,0x0001), // Multikey chain
/*<!M><V><I>                                                       */ DEADTRANS( L'I'	,0xF1AA	,0xF1E5	,0x0001), // Multikey chain
/*<!M><v><i><e>                                                    */ DEADTRANS( L'e'	,0xF1E4	,0xF1E6	,0x0001), // Multikey chain
/*<!M><V><I><E>                                                    */ DEADTRANS( L'E'	,0xF1E5	,0xF1E7	,0x0001), // Multikey chain
/*<!M><v><i><e><r>                                                 */ DEADTRANS( L'r'	,0xF1E6	,0x264D	,0x0000), // 'r' ➔ "♍" VIRGO emoji
/*<!M><V><I><E><R>                                                 */ DEADTRANS( L'R'	,0xF1E7	,0x264D	,0x0000), // 'R' ➔ "♍" VIRGO emoji
/*<!M><v><i><r>                                                    */ DEADTRANS( L'r'	,0xF1E4	,0xF1EA	,0x0001), // Multikey chain
/*<!M><V><I><R>                                                    */ DEADTRANS( L'R'	,0xF1E5	,0xF1EB	,0x0001), // Multikey chain
/*<!M><v><i><r><g>                                                 */ DEADTRANS( L'g'	,0xF1EA	,0x264D	,0x0000), // 'g' ➔ "♍" VIRGO emoji
/*<!M><V><I><R><G>                                                 */ DEADTRANS( L'G'	,0xF1EB	,0x264D	,0x0000), // 'G' ➔ "♍" VIRGO emoji
/*<!M><v><n>                                                       */ DEADTRANS( L'n'	,0xF1AB	,0xF1EE	,0x0001), // Multikey chain
/*<!M><V><N>                                                       */ DEADTRANS( L'N'	,0xF1AA	,0xF1EF	,0x0001), // Multikey chain
/*<!M><v><n><d>                                                    */ DEADTRANS( L'd'	,0xF1EE	,0x20AB	,0x0000), // 'd' ➔ "₫" DONG SIGN, Dong VIET NAM
/*<!M><V><N><D>                                                    */ DEADTRANS( L'D'	,0xF1EF	,0x20AB	,0x0000), // 'D' ➔ "₫" DONG SIGN, Dong VIET NAM
/*<!M><v><u>                                                       */ DEADTRANS( L'u'	,0xF1AB	,0x2A45	,0x0000), // 'u' ➔ "⩅" UNION WITH LOGICAL OR
/*<!M><v><v>                                                       */ DEADTRANS( L'v'	,0xF1AB	,0xF1F3	,0x0001), // Multikey chain
/*<!M><v><v><%equal>                                               */ DEADTRANS( L'='	,0xF1F3	,0x2259	,0x0000), // '=' ➔ "≙" ESTIMATES
/*<!M><V><Y>                                                       */ DEADTRANS( L'Y'	,0xF1AA	,0xA760	,0x0000), // 'Y' ➔ "Ꝡ" LATIN CAPITAL LETTER VY
/*<!M><V><y>                                                       */ DEADTRANS( L'y'	,0xF1AA	,0xA760	,0x0000), // 'y' ➔ "Ꝡ" LATIN CAPITAL LETTER VY
/*<!M><v><y>                                                       */ DEADTRANS( L'y'	,0xF1AB	,0xA761	,0x0000), // 'y' ➔ "ꝡ" LATIN SMALL LETTER VY
/*<!M><v><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF1AB	,0x2228	,0x0000), // ' ' ➔ "∨" LOGICAL OR
/*<!M><V><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF1AA	,0x22C1	,0x0000), // ' ' ➔ "⋁" N-ARY LOGICAL OR
/*<!M><v><~space>                                                  */ DEADTRANS( L' '	,0xF1AB	,0x2228	,0x0000), // ' ' ➔ "∨" LOGICAL OR
/*<!M><V><~space>                                                  */ DEADTRANS( L' '	,0xF1AA	,0x22C1	,0x0000), // ' ' ➔ "⋁" N-ARY LOGICAL OR
/*<!M><w>                                                          */ DEADTRANS( L'w'	,0x00A6	,0xF1FC	,0x0001), // Multikey chain
/*<!M><W>                                                          */ DEADTRANS( L'W'	,0x00A6	,0xF1FD	,0x0001), // Multikey chain
/*<!M><w><%bracketleft>                                            */ DEADTRANS( L'['	,0xF1FC	,0x29D8	,0x0000), // '[' ➔ "⧘" LEFT WIGGLY FENCE
/*<!M><w><%bracketright>                                           */ DEADTRANS( L']'	,0xF1FC	,0x29D9	,0x0000), // ']' ➔ "⧙" RIGHT WIGGLY FENCE
/*<!M><w><%equal>                                                  */ DEADTRANS( L'='	,0xF1FC	,0x20A9	,0x0000), // '=' ➔ "₩" WON SIGN
/*<!M><W><%equal>                                                  */ DEADTRANS( L'='	,0xF1FD	,0x20A9	,0x0000), // '=' ➔ "₩" WON SIGN
/*<!M><W><%percent>                                                */ DEADTRANS( L'%'	,0xF1FD	,0x2A07	,0x0000), // '%' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><w><%percent>                                                */ DEADTRANS( L'%'	,0xF1FC	,0x2A55	,0x0000), // '%' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><w><l>                                                       */ DEADTRANS( L'l'	,0xF1FC	,0x2307	,0x0000), // 'l' ➔ "⌇" WAVY LINE
/*<!M><W><L>                                                       */ DEADTRANS( L'L'	,0xF1FD	,0x2307	,0x0000), // 'L' ➔ "⌇" WAVY LINE
/*<!M><w><v>                                                       */ DEADTRANS( L'v'	,0xF1FC	,0x2AFF	,0x0000), // 'v' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><W><V>                                                       */ DEADTRANS( L'V'	,0xF1FD	,0x2AFF	,0x0000), // 'V' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><w><w>                                                       */ DEADTRANS( L'w'	,0xF1FC	,0xF208	,0x0001), // Multikey chain
/*<!M><w><w><%bracketleft>                                         */ DEADTRANS( L'['	,0xF208	,0x29DA	,0x0000), // '[' ➔ "⧚" LEFT DOUBLE WIGGLY FENCE
/*<!M><w><w><%bracketright>                                        */ DEADTRANS( L']'	,0xF208	,0x29DB	,0x0000), // ']' ➔ "⧛" RIGHT DOUBLE WIGGLY FENCE
/*<!M><w><z>                                                       */ DEADTRANS( L'z'	,0xF1FC	,0xDD2E	,0x0000), // High surrogate: D83C; U+1F12E 'z' ➔ "🄮" CIRCLED WZ
/*<!M><W><Z>                                                       */ DEADTRANS( L'Z'	,0xF1FD	,0xDD2E	,0x0000), // High surrogate: D83C; U+1F12E 'Z' ➔ "🄮" CIRCLED WZ
/*<!M><W><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF1FD	,0x2A08	,0x0000), // ' ' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><w><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF1FC	,0x2A56	,0x0000), // ' ' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><W><~space>                                                  */ DEADTRANS( L' '	,0xF1FD	,0x2A08	,0x0000), // ' ' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><w><~space>                                                  */ DEADTRANS( L' '	,0xF1FC	,0x2A56	,0x0000), // ' ' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><X>                                                          */ DEADTRANS( L'X'	,0x00A6	,0xF211	,0x0001), // Multikey chain
/*<!M><x>                                                          */ DEADTRANS( L'x'	,0x00A6	,0xF212	,0x0001), // Multikey chain
/*<!M><x><%colon>                                                  */ DEADTRANS( L':'	,0xF212	,0x22C7	,0x0000), // ':' ➔ "⋇" DIVISION TIMES
/*<!M><X><%hash>                                                   */ DEADTRANS( L'#'	,0xF211	,0x29D7	,0x0000), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><x><%minus>                                                  */ DEADTRANS( L'-'	,0xF212	,0x2947	,0x0000), // '-' ➔ "⥇" RIGHTWARDS ARROW THROUGH X
/*<!M><x><%parenright>                                             */ DEADTRANS( L')'	,0xF212	,0x2A35	,0x0000), // ')' ➔ "⨵" MULTIPLICATION SIGN IN RIGHT HALF CIRCLE
/*<!M><x><%period>                                                 */ DEADTRANS( L'.'	,0xF212	,0x22C7	,0x0000), // '.' ➔ "⋇" DIVISION TIMES
/*<!M><X><%underscore>                                             */ DEADTRANS( L'_'	,0xF211	,0x29D6	,0x0000), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><x><%underscore>                                             */ DEADTRANS( L'_'	,0xF212	,0x2A31	,0x0000), // '_' ➔ "⨱" MULTIPLICATION SIGN WITH UNDERBAR
/*<!M><x><o>                                                       */ DEADTRANS( L'o'	,0xF212	,0xF21C	,0x0001), // Multikey chain
/*<!M><X><O>                                                       */ DEADTRANS( L'O'	,0xF211	,0xF21D	,0x0001), // Multikey chain
/*<!M><X><o>                                                       */ DEADTRANS( L'o'	,0xF211	,0x00A4	,0x0000), // 'o' ➔ "¤" CURRENCY SIGN
/*<!M><x><O>                                                       */ DEADTRANS( L'O'	,0xF212	,0x00A4	,0x0000), // 'O' ➔ "¤" CURRENCY SIGN
/*<!M><x><o><r>                                                    */ DEADTRANS( L'r'	,0xF21C	,0x22BB	,0x0000), // 'r' ➔ "⊻" XOR
/*<!M><X><O><R>                                                    */ DEADTRANS( L'R'	,0xF21D	,0x22BB	,0x0000), // 'R' ➔ "⊻" XOR
/*<!M><X><R>                                                       */ DEADTRANS( L'R'	,0xF211	,0x2627	,0x0000), // 'R' ➔ "☧" CHI RHO
/*<!M><x><R>                                                       */ DEADTRANS( L'R'	,0xF212	,0x2627	,0x0000), // 'R' ➔ "☧" CHI RHO
/*<!M><X><r>                                                       */ DEADTRANS( L'r'	,0xF211	,0x2627	,0x0000), // 'r' ➔ "☧" CHI RHO
/*<!M><x><r>                                                       */ DEADTRANS( L'r'	,0xF212	,0x2627	,0x0000), // 'r' ➔ "☧" CHI RHO
/*<!M><x><t>                                                       */ DEADTRANS( L't'	,0xF212	,0xF224	,0x0001), // Multikey chain
/*<!M><X><T>                                                       */ DEADTRANS( L'T'	,0xF211	,0xF225	,0x0001), // Multikey chain
/*<!M><x><t><l>                                                    */ DEADTRANS( L'l'	,0xF224	,0x232B	,0x0000), // 'l' ➔ "⌫" ERASE TO THE LEFT
/*<!M><X><T><L>                                                    */ DEADTRANS( L'L'	,0xF225	,0x232B	,0x0000), // 'L' ➔ "⌫" ERASE TO THE LEFT
/*<!M><x><t><r>                                                    */ DEADTRANS( L'r'	,0xF224	,0x2326	,0x0000), // 'r' ➔ "⌦" ERASE TO THE RIGHT
/*<!M><X><T><R>                                                    */ DEADTRANS( L'R'	,0xF225	,0x2326	,0x0000), // 'R' ➔ "⌦" ERASE TO THE RIGHT
/*<!M><x><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF212	,0x00D7	,0x0000), // ' ' ➔ "×" MULTIPLICATION SIGN
/*<!M><X><~nbspace>                                                */ DEADTRANS( 0x00A0	,0xF211	,0x2A09	,0x0000), // ' ' ➔ "⨉" N-ARY TIMES OPERATOR
/*<!M><x><~space>                                                  */ DEADTRANS( L' '	,0xF212	,0x00D7	,0x0000), // ' ' ➔ "×" MULTIPLICATION SIGN
/*<!M><X><~space>                                                  */ DEADTRANS( L' '	,0xF211	,0x2A09	,0x0000), // ' ' ➔ "⨉" N-ARY TIMES OPERATOR
/*<!M><y>                                                          */ DEADTRANS( L'y'	,0x00A6	,0xF22E	,0x0001), // Multikey chain
/*<!M><Y>                                                          */ DEADTRANS( L'Y'	,0x00A6	,0xF22F	,0x0001), // Multikey chain
/*<!M><Y><%at>                                                     */ DEADTRANS( L'@'	,0xF22F	,0x03D2	,0x0000), // '@' ➔ "ϒ" GREEK UPSILON WITH HOOK SYMBOL
/*<!M><y><%equal>                                                  */ DEADTRANS( L'='	,0xF22E	,0x00A5	,0x0000), // '=' ➔ "¥" YEN SIGN
/*<!M><Y><%equal>                                                  */ DEADTRANS( L'='	,0xF22F	,0x00A5	,0x0000), // '=' ➔ "¥" YEN SIGN
/*<!M><Y><%exclam>                                                 */ DEADTRANS( L'!'	,0xF22F	,0x297E	,0x0000), // '!' ➔ "⥾" UP FISH TAIL
/*<!M><y><%minus>                                                  */ DEADTRANS( L'-'	,0xF22E	,0x00A5	,0x0000), // '-' ➔ "¥" YEN SIGN
/*<!M><Y><%minus>                                                  */ DEADTRANS( L'-'	,0xF22F	,0x00A5	,0x0000), // '-' ➔ "¥" YEN SIGN
/*<!M><Y><%percent>                                                */ DEADTRANS( L'%'	,0xF22F	,0x2144	,0x0000), // '%' ➔ "⅄" TURNED SANS-SERIF CAPITAL Y
/*<!M><y><e>                                                       */ DEADTRANS( L'e'	,0xF22E	,0xF237	,0x0001), // Multikey chain
/*<!M><Y><E>                                                       */ DEADTRANS( L'E'	,0xF22F	,0xF238	,0x0001), // Multikey chain
/*<!M><y><e><r>                                                    */ DEADTRANS( L'r'	,0xF237	,0xFDFC	,0x0000), // 'r' ➔ "﷼" RIAL SIGN, Yemeni Rial YEMEN
/*<!M><Y><E><R>                                                    */ DEADTRANS( L'R'	,0xF238	,0xFDFC	,0x0000), // 'R' ➔ "﷼" RIAL SIGN, Yemeni Rial YEMEN
/*<!M><z>                                                          */ DEADTRANS( L'z'	,0x00A6	,0xF23B	,0x0001), // Multikey chain
/*<!M><Z>                                                          */ DEADTRANS( L'Z'	,0x00A6	,0xF23C	,0x0001), // Multikey chain
/*<!M><z><%bar>                                                    */ DEADTRANS( L'|'	,0xF23B	,0x2A65	,0x0000), // '|' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><Z><%bar>                                                    */ DEADTRANS( L'|'	,0xF23C	,0x2A65	,0x0000), // '|' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><z><%colon>                                                  */ DEADTRANS( L':'	,0xF23B	,0x2982	,0x0000), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><Z><%colon>                                                  */ DEADTRANS( L':'	,0xF23C	,0x2982	,0x0000), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><z><%exclam>                                                 */ DEADTRANS( L'!'	,0xF23B	,0x2A21	,0x0000), // '!' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z><%exclam>                                                 */ DEADTRANS( L'!'	,0xF23C	,0x2A21	,0x0000), // '!' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><z><%greater>                                                */ DEADTRANS( L'>'	,0xF23B	,0xF243	,0x0001), // Multikey chain
/*<!M><Z><%greater>                                                */ DEADTRANS( L'>'	,0xF23C	,0xF244	,0x0001), // Multikey chain
/*<!M><z><%greater><%greater>                                      */ DEADTRANS( L'>'	,0xF243	,0x2A20	,0x0000), // '>' ➔ "⨠" Z NOTATION SCHEMA PIPING
/*<!M><Z><%greater><%greater>                                      */ DEADTRANS( L'>'	,0xF244	,0x2A20	,0x0000), // '>' ➔ "⨠" Z NOTATION SCHEMA PIPING
/*<!M><z><%greater><%minus>                                        */ DEADTRANS( L'-'	,0xF243	,0x2A65	,0x0000), // '-' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><Z><%greater><%minus>                                        */ DEADTRANS( L'-'	,0xF244	,0x2A65	,0x0000), // '-' ➔ "⩥" Z NOTATION RANGE ANTIRESTRICTION
/*<!M><z><%greater><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF243	,0x298A	,0x0000), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z><%greater><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF244	,0x298A	,0x0000), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><z><%greater><~space>                                        */ DEADTRANS( L' '	,0xF243	,0x298A	,0x0000), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z><%greater><~space>                                        */ DEADTRANS( L' '	,0xF244	,0x298A	,0x0000), // ' ' ➔ "⦊" Z NOTATION RIGHT BINDING BRACKET
/*<!M><Z><%hash>                                                   */ DEADTRANS( L'#'	,0xF23C	,0x2128	,0x0000), // '#' ➔ "ℨ" BLACK-LETTER CAPITAL Z
/*<!M><z><%less>                                                   */ DEADTRANS( L'<'	,0xF23B	,0xF24E	,0x0001), // Multikey chain
/*<!M><Z><%less>                                                   */ DEADTRANS( L'<'	,0xF23C	,0xF24F	,0x0001), // Multikey chain
/*<!M><z><%less><%minus>                                           */ DEADTRANS( L'-'	,0xF24E	,0x2A64	,0x0000), // '-' ➔ "⩤" Z NOTATION DOMAIN ANTIRESTRICTION
/*<!M><Z><%less><%minus>                                           */ DEADTRANS( L'-'	,0xF24F	,0x2A64	,0x0000), // '-' ➔ "⩤" Z NOTATION DOMAIN ANTIRESTRICTION
/*<!M><z><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xF24E	,0x2989	,0x0000), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><Z><%less><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xF24F	,0x2989	,0x0000), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><z><%less><~space>                                           */ DEADTRANS( L' '	,0xF24E	,0x2989	,0x0000), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><Z><%less><~space>                                           */ DEADTRANS( L' '	,0xF24F	,0x2989	,0x0000), // ' ' ➔ "⦉" Z NOTATION LEFT BINDING BRACKET
/*<!M><z><%parenleft>                                              */ DEADTRANS( L'('	,0xF23B	,0x2987	,0x0000), // '(' ➔ "⦇" Z NOTATION LEFT IMAGE BRACKET
/*<!M><Z><%parenleft>                                              */ DEADTRANS( L'('	,0xF23C	,0x2987	,0x0000), // '(' ➔ "⦇" Z NOTATION LEFT IMAGE BRACKET
/*<!M><z><%parenright>                                             */ DEADTRANS( L')'	,0xF23B	,0x2988	,0x0000), // ')' ➔ "⦈" Z NOTATION RIGHT IMAGE BRACKET
/*<!M><Z><%parenright>                                             */ DEADTRANS( L')'	,0xF23C	,0x2988	,0x0000), // ')' ➔ "⦈" Z NOTATION RIGHT IMAGE BRACKET
/*<!M><z><%period>                                                 */ DEADTRANS( L'.'	,0xF23B	,0x2981	,0x0000), // '.' ➔ "⦁" Z NOTATION SPOT
/*<!M><Z><%period>                                                 */ DEADTRANS( L'.'	,0xF23C	,0x2981	,0x0000), // '.' ➔ "⦁" Z NOTATION SPOT
/*<!M><z><%semicolon>                                              */ DEADTRANS( L';'	,0xF23B	,0x2A1F	,0x0000), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><Z><%semicolon>                                              */ DEADTRANS( L';'	,0xF23C	,0x2A1F	,0x0000), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><z><%semsection>                                             */ DEADTRANS( 0x00A7	,0xF23B	,0x2A1F	,0x0000), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><Z><%semsection>                                             */ DEADTRANS( 0x00A7	,0xF23C	,0x2A1F	,0x0000), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><z><1>                                                       */ DEADTRANS( L'1'	,0xF23B	,0x2A21	,0x0000), // '1' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z><1>                                                       */ DEADTRANS( L'1'	,0xF23C	,0x2A21	,0x0000), // '1' ➔ "⨡" Z NOTATION SCHEMA PROJECTION
/*<!M><Z><2>                                                       */ DEADTRANS( L'2'	,0xF23C	,0x01A7	,0x0000), // '2' ➔ "Ƨ" LATIN CAPITAL LETTER TONE TWO
/*<!M><z><2>                                                       */ DEADTRANS( L'2'	,0xF23B	,0x01A8	,0x0000), // '2' ➔ "ƨ" LATIN SMALL LETTER TONE TWO
/*<!M><Z><3>                                                       */ DEADTRANS( L'3'	,0xF23C	,0x0417	,0x0000), // '3' ➔ "З" CYRILLIC CAPITAL LETTER ZE
/*<!M><z><3>                                                       */ DEADTRANS( L'3'	,0xF23B	,0x0437	,0x0000), // '3' ➔ "з" CYRILLIC SMALL LETTER ZE
/*<!M><Z><4>                                                       */ DEADTRANS( L'4'	,0xF23C	,0x0427	,0x0000), // '4' ➔ "Ч" CYRILLIC CAPITAL LETTER CHE
/*<!M><z><4>                                                       */ DEADTRANS( L'4'	,0xF23B	,0x0447	,0x0000), // '4' ➔ "ч" CYRILLIC SMALL LETTER CHE
/*<!M><Z><5>                                                       */ DEADTRANS( L'5'	,0xF23C	,0x01BC	,0x0000), // '5' ➔ "Ƽ" LATIN CAPITAL LETTER TONE FIVE
/*<!M><z><5>                                                       */ DEADTRANS( L'5'	,0xF23B	,0x01BD	,0x0000), // '5' ➔ "ƽ" LATIN SMALL LETTER TONE FIVE
/*<!M><Z><6>                                                       */ DEADTRANS( L'6'	,0xF23C	,0x0184	,0x0000), // '6' ➔ "Ƅ" LATIN CAPITAL LETTER TONE SIX
/*<!M><z><6>                                                       */ DEADTRANS( L'6'	,0xF23B	,0x0185	,0x0000), // '6' ➔ "ƅ" LATIN SMALL LETTER TONE SIX
/*<!M><z><e>                                                       */ DEADTRANS( L'e'	,0xF23B	,0x22FF	,0x0000), // 'e' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z><e>                                                       */ DEADTRANS( L'e'	,0xF23C	,0x22FF	,0x0000), // 'e' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><z><E>                                                       */ DEADTRANS( L'E'	,0xF23B	,0x22FF	,0x0000), // 'E' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z><E>                                                       */ DEADTRANS( L'E'	,0xF23C	,0x22FF	,0x0000), // 'E' ➔ "⋿" Z NOTATION BAG MEMBERSHIP
/*<!M><Z><H>                                                       */ DEADTRANS( L'H'	,0xF23C	,0x01B7	,0x0000), // 'H' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><Z><h>                                                       */ DEADTRANS( L'h'	,0xF23C	,0x01B7	,0x0000), // 'h' ➔ "Ʒ" LATIN CAPITAL LETTER EZH
/*<!M><z><h>                                                       */ DEADTRANS( L'h'	,0xF23B	,0x0292	,0x0000), // 'h' ➔ "ʒ" LATIN SMALL LETTER EZH
/*<!M><z><w>                                                       */ DEADTRANS( L'w'	,0xF23B	,0xDD2E	,0x0000), // High surrogate: D83C; U+1F12E 'w' ➔ "🄮" CIRCLED WZ
/*<!M><Z><W>                                                       */ DEADTRANS( L'W'	,0xF23C	,0xDD2E	,0x0000), // High surrogate: D83C; U+1F12E 'W' ➔ "🄮" CIRCLED WZ
/*<!M><Z><Z>                                                       */ DEADTRANS( L'Z'	,0xF23C	,0x2124	,0x0000), // 'Z' ➔ "ℤ" DOUBLE-STRUCK CAPITAL Z
/*<!M><z><z>                                                       */ DEADTRANS( L'z'	,0xF23B	,0x2125	,0x0000), // 'z' ➔ "℥" OUNCE SIGN
/*<!M><Z><z>                                                       */ DEADTRANS( L'z'	,0xF23C	,0x2125	,0x0000), // 'z' ➔ "℥" OUNCE SIGN
/*<!M><z><Z>                                                       */ DEADTRANS( L'Z'	,0xF23B	,0x2125	,0x0000), // 'Z' ➔ "℥" OUNCE SIGN
/*<!M><~nbspace>                                                   */ DEADTRANS( 0x00A0	,0x00A6	,0xF279	,0x0001), // Multikey chain
/*<!M><~nbspace><%ampersand>                                       */ DEADTRANS( L'&'	,0xF279	,0xF27A	,0x0001), // Multikey chain
/*<!M><~nbspace><%ampersand><%bar>                                 */ DEADTRANS( L'|'	,0xF27A	,0x20D3	,0x0000), // '|' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><~nbspace><%ampersand><%less>                                */ DEADTRANS( L'<'	,0xF27A	,0x20EE	,0x0000), // '<' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><~nbspace><%ampersand><%minus>                               */ DEADTRANS( L'-'	,0xF27A	,0x20EF	,0x0000), // '-' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><~nbspace><%apostrophe>                                      */ DEADTRANS( L'\''	,0xF279	,0xF27E	,0x0001), // Multikey chain
/*<!M><~nbspace><%apostrophe><%equal>                              */ DEADTRANS( L'='	,0xF27E	,0x2AED	,0x0000), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~nbspace><%apostrophe><%minus>                              */ DEADTRANS( L'-'	,0xF27E	,0x2A3D	,0x0000), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~nbspace><%apostrophe><%plus>                               */ DEADTRANS( L'+'	,0xF27E	,0x22B9	,0x0000), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%aprightsingquotmark>                             */ DEADTRANS( 0x2019	,0xF279	,0xF282	,0x0001), // Multikey chain
/*<!M><~nbspace><%aprightsingquotmark><%equal>                     */ DEADTRANS( L'='	,0xF282	,0x2AED	,0x0000), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~nbspace><%aprightsingquotmark><%minus>                     */ DEADTRANS( L'-'	,0xF282	,0x2A3D	,0x0000), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~nbspace><%aprightsingquotmark><%plus>                      */ DEADTRANS( L'+'	,0xF282	,0x22B9	,0x0000), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%asterisk>                                        */ DEADTRANS( L'*'	,0xF279	,0xF286	,0x0001), // Multikey chain
/*<!M><~nbspace><%asterisk><%equal>                                */ DEADTRANS( L'='	,0xF286	,0x225B	,0x0000), // '=' ➔ "≛" STAR EQUALS
/*<!M><~nbspace><%asterisk><~nbspace>                              */ DEADTRANS( 0x00A0	,0xF286	,0x2217	,0x0000), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~nbspace><%asterisk><~space>                                */ DEADTRANS( L' '	,0xF286	,0x2217	,0x0000), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~nbspace><%backslash>                                       */ DEADTRANS( L'\\'	,0xF279	,0xF28A	,0x0001), // Multikey chain
/*<!M><~nbspace><%backslash><%greater>                             */ DEADTRANS( L'>'	,0xF28A	,0x292D	,0x0000), // '>' ➔ "⤭" SOUTH EAST ARROW CROSSING NORTH EAST ARROW
/*<!M><~nbspace><%backslash><%minus>                               */ DEADTRANS( L'-'	,0xF28A	,0x29A3	,0x0000), // '-' ➔ "⦣" REVERSED ANGLE
/*<!M><~nbspace><%backslash><%slash>                               */ DEADTRANS( L'/'	,0xF28A	,0xF28D	,0x0001), // Multikey chain
/*<!M><~nbspace><%backslash><%slash><%bar>                         */ DEADTRANS( L'|'	,0xF28D	,0x2A1E	,0x0000), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~nbspace><%backslash><%slash><%hash>                        */ DEADTRANS( L'#'	,0xF28D	,0x25C0	,0x0000), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~nbspace><%backslash><%slash><%underscore>                  */ DEADTRANS( L'_'	,0xF28D	,0x29CD	,0x0000), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~nbspace><%backslash><c>                                    */ DEADTRANS( L'c'	,0xF28A	,0x27C8	,0x0000), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~nbspace><%backslash><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF28A	,0x2216	,0x0000), // ' ' ➔ "∖" SET MINUS
/*<!M><~nbspace><%backslash><~space>                               */ DEADTRANS( L' '	,0xF28A	,0x2216	,0x0000), // ' ' ➔ "∖" SET MINUS
/*<!M><~nbspace><%bar>                                             */ DEADTRANS( L'|'	,0xF279	,0xF294	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%backslash>                                 */ DEADTRANS( L'\\'	,0xF294	,0xF295	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%backslash><%slash>                         */ DEADTRANS( L'/'	,0xF295	,0xF296	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%backslash><%slash><%bar>                   */ DEADTRANS( L'|'	,0xF296	,0x2A1D	,0x0000), // '|' ➔ "⨝" JOIN
/*<!M><~nbspace><%bar><%backslash><%slash><~nbspace>               */ DEADTRANS( 0x00A0	,0xF296	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%backslash><%slash><~space>                 */ DEADTRANS( L' '	,0xF296	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%bar>                                       */ DEADTRANS( L'|'	,0xF294	,0xF29A	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xF29A	,0xF29B	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%bar><%bar><%minus>                         */ DEADTRANS( L'-'	,0xF29B	,0x22AA	,0x0000), // '-' ➔ "⊪" TRIPLE VERTICAL BAR RIGHT TURNSTILE
/*<!M><~nbspace><%bar><%bar><%bar><~nbspace>                       */ DEADTRANS( 0x00A0	,0xF29B	,0x2AF4	,0x0000), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><%bar><%bar><%bar><~space>                         */ DEADTRANS( L' '	,0xF29B	,0x2AF4	,0x0000), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><%bar><%bar><%minus>                               */ DEADTRANS( L'-'	,0xF29A	,0x22A9	,0x0000), // '-' ➔ "⊩" FORCES
/*<!M><~nbspace><%bar><%bar><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF29A	,0x2225	,0x0000), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~nbspace><%bar><%bar><~space>                               */ DEADTRANS( L' '	,0xF29A	,0x2225	,0x0000), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~nbspace><%bar><%equal>                                     */ DEADTRANS( L'='	,0xF294	,0x29E7	,0x0000), // '=' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%bar><%hash>                                      */ DEADTRANS( L'#'	,0xF294	,0x25B6	,0x0000), // '#' ➔ "▶" BLACK RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%minus>                                     */ DEADTRANS( L'-'	,0xF294	,0x27CA	,0x0000), // '-' ➔ "⟊" VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><~nbspace><%bar><%parenright>                                */ DEADTRANS( L')'	,0xF294	,0x2ADD	,0x0000), // ')' ➔ "⫝" NONFORKING
/*<!M><~nbspace><%bar><%slash>                                     */ DEADTRANS( L'/'	,0xF294	,0xF2A6	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%slash><%backslash>                         */ DEADTRANS( L'\\'	,0xF2A6	,0xF2A7	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><%slash><%backslash><%bar>                   */ DEADTRANS( L'|'	,0xF2A7	,0x2A1D	,0x0000), // '|' ➔ "⨝" JOIN
/*<!M><~nbspace><%bar><%slash><%backslash><~nbspace>               */ DEADTRANS( 0x00A0	,0xF2A7	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%slash><%backslash><~space>                 */ DEADTRANS( L' '	,0xF2A7	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~nbspace><%bar><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF2A6	,0x2A57	,0x0000), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~nbspace><%bar><%slash><~space>                             */ DEADTRANS( L' '	,0xF2A6	,0x2A57	,0x0000), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~nbspace><%bar><e>                                          */ DEADTRANS( L'e'	,0xF294	,0xF2AD	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><e><%backslash>                              */ DEADTRANS( L'\\'	,0xF2AD	,0xF2AE	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><e><%backslash><%comma>                      */ DEADTRANS( L','	,0xF2AE	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><%backslash><~nbspace>                    */ DEADTRANS( 0x00A0	,0xF2AE	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><%backslash><~space>                      */ DEADTRANS( L' '	,0xF2AE	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e>                                       */ DEADTRANS( L'e'	,0xF2AD	,0xF2B2	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><e><e><%comma>                               */ DEADTRANS( L','	,0xF2B2	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF2B2	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><e><e><~space>                               */ DEADTRANS( L' '	,0xF2B2	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><o>                                          */ DEADTRANS( L'o'	,0xF294	,0x2AF0	,0x0000), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><~nbspace><%bar><p>                                          */ DEADTRANS( L'p'	,0xF294	,0xF2B7	,0x0001), // Multikey chain
/*<!M><~nbspace><%bar><p><%comma>                                  */ DEADTRANS( L','	,0xF2B7	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><p><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF2B7	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><p><~space>                                  */ DEADTRANS( L' '	,0xF2B7	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><%bar><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF294	,0x2223	,0x0000), // ' ' ➔ "∣" DIVIDES
/*<!M><~nbspace><%bar><~space>                                     */ DEADTRANS( L' '	,0xF294	,0x2223	,0x0000), // ' ' ➔ "∣" DIVIDES
/*<!M><~nbspace><%braceleft>                                       */ DEADTRANS( L'{'	,0xF279	,0x2983	,0x0000), // '{' ➔ "⦃" LEFT WHITE CURLY BRACKET
/*<!M><~nbspace><%braceright>                                      */ DEADTRANS( L'}'	,0xF279	,0x2984	,0x0000), // '}' ➔ "⦄" RIGHT WHITE CURLY BRACKET
/*<!M><~nbspace><%bracketleft>                                     */ DEADTRANS( L'['	,0xF279	,0xF2BF	,0x0001), // Multikey chain
/*<!M><~nbspace><%bracketleft><%bracketleft>                       */ DEADTRANS( L'['	,0xF2BF	,0x27E6	,0x0000), // '[' ➔ "⟦" MATHEMATICAL LEFT WHITE SQUARE BRACKET
/*<!M><~nbspace><%bracketleft><%bracketright>                      */ DEADTRANS( L']'	,0xF2BF	,0x25FB	,0x0000), // ']' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~nbspace><%bracketleft><%hash>                              */ DEADTRANS( L'#'	,0xF2BF	,0x25FC	,0x0000), // '#' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><~nbspace><%bracketleft><%minus>                             */ DEADTRANS( L'-'	,0xF2BF	,0x2ACD	,0x0000), // '-' ➔ "⫍" SQUARE LEFT OPEN BOX OPERATOR
/*<!M><~nbspace><%bracketleft><%underscore>                        */ DEADTRANS( L'_'	,0xF2BF	,0x298B	,0x0000), // '_' ➔ "⦋" LEFT SQUARE BRACKET WITH UNDERBAR
/*<!M><~nbspace><%bracketleft><a>                                  */ DEADTRANS( L'a'	,0xF2BF	,0x27CE	,0x0000), // 'a' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><~nbspace><%bracketleft><o>                                  */ DEADTRANS( L'o'	,0xF2BF	,0x29C7	,0x0000), // 'o' ➔ "⧇" SQUARED SMALL CIRCLE
/*<!M><~nbspace><%bracketright>                                    */ DEADTRANS( L']'	,0xF279	,0xF2C7	,0x0001), // Multikey chain
/*<!M><~nbspace><%bracketright><%bracketleft>                      */ DEADTRANS( L'['	,0xF2C7	,0x25FB	,0x0000), // '[' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~nbspace><%bracketright><%bracketright>                     */ DEADTRANS( L']'	,0xF2C7	,0x27E7	,0x0000), // ']' ➔ "⟧" MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><~nbspace><%bracketright><%underscore>                       */ DEADTRANS( L'_'	,0xF2C7	,0x298C	,0x0000), // '_' ➔ "⦌" RIGHT SQUARE BRACKET WITH UNDERBAR
/*<!M><~nbspace><%circum>                                          */ DEADTRANS( L'^'	,0xF279	,0xF2CB	,0x0001), // Multikey chain
/*<!M><~nbspace><%circum><%circum>                                 */ DEADTRANS( L'^'	,0xF2CB	,0x22C4	,0x0000), // '^' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~nbspace><%circum><%equal>                                  */ DEADTRANS( L'='	,0xF2CB	,0x2259	,0x0000), // '=' ➔ "≙" ESTIMATES
/*<!M><~nbspace><%circum><%underscore>                             */ DEADTRANS( L'_'	,0xF2CB	,0x25B5	,0x0000), // '_' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%circum><o>                                       */ DEADTRANS( L'o'	,0xF2CB	,0x2A36	,0x0000), // 'o' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~nbspace><%circum><O>                                       */ DEADTRANS( L'O'	,0xF2CB	,0x2A36	,0x0000), // 'O' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~nbspace><%circum><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF2CB	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~nbspace><%circum><~space>                                  */ DEADTRANS( L' '	,0xF2CB	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~nbspace><%colon>                                           */ DEADTRANS( L':'	,0xF279	,0xF2D3	,0x0001), // Multikey chain
/*<!M><~nbspace><%colon><%colon>                                   */ DEADTRANS( L':'	,0xF2D3	,0x2237	,0x0000), // ':' ➔ "∷" PROPORTION
/*<!M><~nbspace><%colon><%tilde>                                   */ DEADTRANS( L'~'	,0xF2D3	,0x223B	,0x0000), // '~' ➔ "∻" HOMOTHETIC
/*<!M><~nbspace><%colon><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF2D3	,0x2236	,0x0000), // ' ' ➔ "∶" RATIO
/*<!M><~nbspace><%colon><~space>                                   */ DEADTRANS( L' '	,0xF2D3	,0x2236	,0x0000), // ' ' ➔ "∶" RATIO
/*<!M><~nbspace><%equal>                                           */ DEADTRANS( L'='	,0xF279	,0xF2D8	,0x0001), // Multikey chain
/*<!M><~nbspace><%equal><%bar>                                     */ DEADTRANS( L'|'	,0xF2D8	,0xF2D9	,0x0001), // Multikey chain
/*<!M><~nbspace><%equal><%bar><%bar>                               */ DEADTRANS( L'|'	,0xF2D9	,0x22D5	,0x0000), // '|' ➔ "⋕" EQUAL AND PARALLEL TO
/*<!M><~nbspace><%equal><%bar><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF2D9	,0x29E7	,0x0000), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%equal><%bar><~space>                             */ DEADTRANS( L' '	,0xF2D9	,0x29E7	,0x0000), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~nbspace><%equal><%equal>                                   */ DEADTRANS( L'='	,0xF2D8	,0x2A75	,0x0000), // '=' ➔ "⩵" TWO CONSECUTIVE EQUALS SIGNS
/*<!M><~nbspace><%equal><%greater>                                 */ DEADTRANS( L'>'	,0xF2D8	,0x2A9A	,0x0000), // '>' ➔ "⪚" DOUBLE-LINE EQUAL TO OR GREATER-THAN
/*<!M><~nbspace><%equal><%minus>                                   */ DEADTRANS( L'-'	,0xF2D8	,0xF2DF	,0x0001), // Multikey chain
/*<!M><~nbspace><%equal><%minus><%greater>                         */ DEADTRANS( L'>'	,0xF2DF	,0x2971	,0x0000), // '>' ➔ "⥱" EQUALS SIGN ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%equal><%minus><%slash>                           */ DEADTRANS( L'/'	,0xF2DF	,0x29E5	,0x0000), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><~nbspace><%exclam>                                          */ DEADTRANS( L'!'	,0xF279	,0xF2E2	,0x0001), // Multikey chain
/*<!M><~nbspace><%exclam><%exclam>                                 */ DEADTRANS( L'!'	,0xF2E2	,0x00A1	,0x0000), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><~nbspace><%exclam><j>                                       */ DEADTRANS( L'j'	,0xF2E2	,0x297F	,0x0000), // 'j' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%exclam><J>                                       */ DEADTRANS( L'J'	,0xF2E2	,0x297F	,0x0000), // 'J' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%exclam><Y>                                       */ DEADTRANS( L'Y'	,0xF2E2	,0x297F	,0x0000), // 'Y' ➔ "⥿" DOWN FISH TAIL
/*<!M><~nbspace><%greater>                                         */ DEADTRANS( L'>'	,0xF279	,0xF2E7	,0x0001), // Multikey chain
/*<!M><~nbspace><%greater><%greater>                               */ DEADTRANS( L'>'	,0xF2E7	,0xF2E8	,0x0001), // Multikey chain
/*<!M><~nbspace><%greater><%greater><%greater>                     */ DEADTRANS( L'>'	,0xF2E8	,0x22D9	,0x0000), // '>' ➔ "⋙" VERY MUCH GREATER-THAN
/*<!M><~nbspace><%greater><%greater><~nbspace>                     */ DEADTRANS( 0x00A0	,0xF2E8	,0x226B	,0x0000), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~nbspace><%greater><%greater><~space>                       */ DEADTRANS( L' '	,0xF2E8	,0x226B	,0x0000), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~nbspace><%greater><%less>                                  */ DEADTRANS( L'<'	,0xF2E7	,0x2AA4	,0x0000), // '<' ➔ "⪤" GREATER-THAN OVERLAPPING LESS-THAN
/*<!M><~nbspace><%greater><%minus>                                 */ DEADTRANS( L'-'	,0xF2E7	,0xF2ED	,0x0001), // Multikey chain
/*<!M><~nbspace><%greater><%minus><%greater>                       */ DEADTRANS( L'>'	,0xF2ED	,0x2978	,0x0000), // '>' ➔ "⥸" GREATER-THAN ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%greater><%minus><~nbspace>                       */ DEADTRANS( 0x00A0	,0xF2ED	,0x2AAB	,0x0000), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~nbspace><%greater><%minus><~space>                         */ DEADTRANS( L' '	,0xF2ED	,0x2AAB	,0x0000), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~nbspace><%greater><%parenright>                            */ DEADTRANS( L')'	,0xF2E7	,0x2994	,0x0000), // ')' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~nbspace><%greater><o>                                      */ DEADTRANS( L'o'	,0xF2E7	,0x2941	,0x0000), // 'o' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~nbspace><%greater><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF2E7	,0x200E	,0x0000), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~nbspace><%greater><~space>                                 */ DEADTRANS( L' '	,0xF2E7	,0x200E	,0x0000), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~nbspace><%hash>                                            */ DEADTRANS( L'#'	,0xF279	,0xF2F5	,0x0001), // Multikey chain
/*<!M><~nbspace><%hash><%percent>                                  */ DEADTRANS( L'%'	,0xF2F5	,0x2A33	,0x0000), // '%' ➔ "⨳" SMASH PRODUCT
/*<!M><~nbspace><%less>                                            */ DEADTRANS( L'<'	,0xF279	,0xF2F7	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%backslash>                                */ DEADTRANS( L'\\'	,0xF2F7	,0x2932	,0x0000), // '\' ➔ "⤲" NORTH WEST ARROW CROSSING NORTH EAST ARROW
/*<!M><~nbspace><%less><%equal>                                    */ DEADTRANS( L'='	,0xF2F7	,0xF2F9	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%equal><%greater>                          */ DEADTRANS( L'>'	,0xF2F9	,0x2A8B	,0x0000), // '>' ➔ "⪋" LESS-THAN ABOVE DOUBLE-LINE EQUAL ABOVE GREATER-THAN
/*<!M><~nbspace><%less><%equal><%slash>                            */ DEADTRANS( L'/'	,0xF2F9	,0x2268	,0x0000), // '/' ➔ "≨" LESS-THAN BUT NOT EQUAL TO
/*<!M><~nbspace><%less><%equal><~nbspace>                          */ DEADTRANS( 0x00A0	,0xF2F9	,0x2266	,0x0000), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~nbspace><%less><%equal><~space>                            */ DEADTRANS( L' '	,0xF2F9	,0x2266	,0x0000), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~nbspace><%less><%exclam>                                   */ DEADTRANS( L'!'	,0xF2F7	,0x29BD	,0x0000), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><~nbspace><%less><%greater>                                  */ DEADTRANS( L'>'	,0xF2F7	,0x22C4	,0x0000), // '>' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~nbspace><%less><%less>                                     */ DEADTRANS( L'<'	,0xF2F7	,0xF300	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%less><%less>                              */ DEADTRANS( L'<'	,0xF300	,0x22D8	,0x0000), // '<' ➔ "⋘" VERY MUCH LESS-THAN
/*<!M><~nbspace><%less><%less><%minus>                             */ DEADTRANS( L'-'	,0xF300	,0xF302	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%less><%minus><%bar>                       */ DEADTRANS( L'|'	,0xF302	,0x2B36	,0x0000), // '|' ➔ "⬶" LEFTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><~nbspace><%less><%less><%minus><~nbspace>                   */ DEADTRANS( 0x00A0	,0xF302	,0x2976	,0x0000), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~nbspace><%less><%less><%minus><~space>                     */ DEADTRANS( L' '	,0xF302	,0x2976	,0x0000), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~nbspace><%less><%less><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF300	,0x226A	,0x0000), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~nbspace><%less><%less><~space>                             */ DEADTRANS( L' '	,0xF300	,0x226A	,0x0000), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~nbspace><%less><%minus>                                    */ DEADTRANS( L'-'	,0xF2F7	,0xF308	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%minus><%bar>                              */ DEADTRANS( L'|'	,0xF308	,0x21F7	,0x0000), // '|' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~nbspace><%less><%minus><%less>                             */ DEADTRANS( L'<'	,0xF308	,0x2977	,0x0000), // '<' ➔ "⥷" LEFTWARDS ARROW THROUGH LESS-THAN
/*<!M><~nbspace><%less><%minus><%minus>                            */ DEADTRANS( L'-'	,0xF308	,0x27F7	,0x0000), // '-' ➔ "⟷" LONG LEFT RIGHT ARROW
/*<!M><~nbspace><%less><%minus><%tilde>                            */ DEADTRANS( L'~'	,0xF308	,0x2973	,0x0000), // '~' ➔ "⥳" LEFTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><~nbspace><%less><%minus><~nbspace>                          */ DEADTRANS( 0x00A0	,0xF308	,0x2AAA	,0x0000), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~nbspace><%less><%minus><~space>                            */ DEADTRANS( L' '	,0xF308	,0x2AAA	,0x0000), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~nbspace><%less><%parenleft>                                */ DEADTRANS( L'('	,0xF2F7	,0x2993	,0x0000), // '(' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~nbspace><%less><%parenright>                               */ DEADTRANS( L')'	,0xF2F7	,0x2AA6	,0x0000), // ')' ➔ "⪦" LESS-THAN CLOSED BY CURVE
/*<!M><~nbspace><%less><%slash>                                    */ DEADTRANS( L'/'	,0xF2F7	,0x226E	,0x0000), // '/' ➔ "≮" NOT LESS-THAN
/*<!M><~nbspace><%less><%tilde>                                    */ DEADTRANS( L'~'	,0xF2F7	,0xF312	,0x0001), // Multikey chain
/*<!M><~nbspace><%less><%tilde><%greater>                          */ DEADTRANS( L'>'	,0xF312	,0x21AD	,0x0000), // '>' ➔ "↭" LEFT RIGHT WAVE ARROW
/*<!M><~nbspace><%less><%tilde><%tilde>                            */ DEADTRANS( L'~'	,0xF312	,0x21DC	,0x0000), // '~' ➔ "⇜" LEFTWARDS SQUIGGLE ARROW
/*<!M><~nbspace><%less><%tilde><~nbspace>                          */ DEADTRANS( 0x00A0	,0xF312	,0x2272	,0x0000), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~nbspace><%less><%tilde><~space>                            */ DEADTRANS( L' '	,0xF312	,0x2272	,0x0000), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~nbspace><%less><3>                                         */ DEADTRANS( L'3'	,0xF2F7	,0x2660	,0x0000), // '3' ➔ "♠" BLACK SPADE SUIT
/*<!M><~nbspace><%less><C>                                         */ DEADTRANS( L'C'	,0xF2F7	,0x293E	,0x0000), // 'C' ➔ "⤾" LOWER RIGHT SEMICIRCULAR CLOCKWISE ARROW
/*<!M><~nbspace><%less><n>                                         */ DEADTRANS( L'n'	,0xF2F7	,0x21B6	,0x0000), // 'n' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><~nbspace><%less><o>                                         */ DEADTRANS( L'o'	,0xF2F7	,0x2940	,0x0000), // 'o' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~nbspace><%less><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF2F7	,0x200F	,0x0000), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~nbspace><%less><~space>                                    */ DEADTRANS( L' '	,0xF2F7	,0x200F	,0x0000), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~nbspace><%minus>                                           */ DEADTRANS( L'-'	,0xF279	,0xF31D	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><%apostrophe>                              */ DEADTRANS( L'\''	,0xF31D	,0xF31E	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><%apostrophe><%minus>                      */ DEADTRANS( L'-'	,0xF31E	,0x2ADF	,0x0000), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~nbspace><%minus><%apostrophe><~nbspace>                    */ DEADTRANS( 0x00A0	,0xF31E	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%apostrophe><~space>                      */ DEADTRANS( L' '	,0xF31E	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%aprightsingquotmark>                     */ DEADTRANS( 0x2019	,0xF31D	,0xF322	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><%aprightsingquotmark><%minus>             */ DEADTRANS( L'-'	,0xF322	,0x2ADF	,0x0000), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~nbspace><%minus><%aprightsingquotmark><~nbspace>           */ DEADTRANS( 0x00A0	,0xF322	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%aprightsingquotmark><~space>             */ DEADTRANS( L' '	,0xF322	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~nbspace><%minus><%bar>                                     */ DEADTRANS( L'|'	,0xF31D	,0x21F8	,0x0000), // '|' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~nbspace><%minus><%bracketleft>                             */ DEADTRANS( L'['	,0xF31D	,0x27E4	,0x0000), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~nbspace><%minus><%bracketright>                            */ DEADTRANS( L']'	,0xF31D	,0xF328	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><%bracketright><%bracketleft>              */ DEADTRANS( L'['	,0xF328	,0x27E4	,0x0000), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~nbspace><%minus><%bracketright><~nbspace>                  */ DEADTRANS( 0x00A0	,0xF328	,0x2ACE	,0x0000), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~nbspace><%minus><%bracketright><~space>                    */ DEADTRANS( L' '	,0xF328	,0x2ACE	,0x0000), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~nbspace><%minus><%slash>                                   */ DEADTRANS( L'/'	,0xF31D	,0x29A2	,0x0000), // '/' ➔ "⦢" TURNED ANGLE
/*<!M><~nbspace><%minus><e>                                        */ DEADTRANS( L'e'	,0xF31D	,0x22F2	,0x0000), // 'e' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><~nbspace><%minus><j>                                        */ DEADTRANS( L'j'	,0xF31D	,0x297D	,0x0000), // 'j' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%minus><J>                                        */ DEADTRANS( L'J'	,0xF31D	,0x297D	,0x0000), // 'J' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%minus><o>                                        */ DEADTRANS( L'o'	,0xF31D	,0xF331	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><O>                                        */ DEADTRANS( L'O'	,0xF31D	,0x29B1	,0x0000), // 'O' ➔ "⦱" EMPTY SET WITH OVERBAR
/*<!M><~nbspace><%minus><o><%minus>                                */ DEADTRANS( L'-'	,0xF331	,0x2256	,0x0000), // '-' ➔ "≖" RING IN EQUAL TO
/*<!M><~nbspace><%minus><o><~nbspace>                              */ DEADTRANS( 0x00A0	,0xF331	,0x22B8	,0x0000), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~nbspace><%minus><o><~space>                                */ DEADTRANS( L' '	,0xF331	,0x22B8	,0x0000), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~nbspace><%minus><s>                                        */ DEADTRANS( L's'	,0xF31D	,0xF336	,0x0001), // Multikey chain
/*<!M><~nbspace><%minus><S>                                        */ DEADTRANS( L'S'	,0xF31D	,0x2A1B	,0x0000), // 'S' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus><s><%slash>                                */ DEADTRANS( L'/'	,0xF336	,0x299E	,0x0000), // '/' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><~nbspace><%minus><s><~nbspace>                              */ DEADTRANS( 0x00A0	,0xF336	,0x2A1B	,0x0000), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus><s><~space>                                */ DEADTRANS( L' '	,0xF336	,0x2A1B	,0x0000), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~nbspace><%minus><Y>                                        */ DEADTRANS( L'Y'	,0xF31D	,0x297D	,0x0000), // 'Y' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~nbspace><%parenleft>                                       */ DEADTRANS( L'('	,0xF279	,0xF33B	,0x0001), // Multikey chain
/*<!M><~nbspace><%parenleft><%bracketleft>                         */ DEADTRANS( L'['	,0xF33B	,0x27EE	,0x0000), // '[' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenleft><%bracketright>                        */ DEADTRANS( L']'	,0xF33B	,0x27EE	,0x0000), // ']' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenleft><%equal>                               */ DEADTRANS( L'='	,0xF33B	,0x224E	,0x0000), // '=' ➔ "≎" GEOMETRICALLY EQUIVALENT TO
/*<!M><~nbspace><%parenleft><%greater>                             */ DEADTRANS( L'>'	,0xF33B	,0x2AA7	,0x0000), // '>' ➔ "⪧" GREATER-THAN CLOSED BY CURVE
/*<!M><~nbspace><%parenleft><%less>                                */ DEADTRANS( L'<'	,0xF33B	,0x2993	,0x0000), // '<' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~nbspace><%parenleft><%parenleft>                           */ DEADTRANS( L'('	,0xF33B	,0x2985	,0x0000), // '(' ➔ "⦅" LEFT WHITE PARENTHESIS
/*<!M><~nbspace><%parenleft><8>                                    */ DEADTRANS( L'8'	,0xF33B	,0x29DD	,0x0000), // '8' ➔ "⧝" TIE OVER INFINITY
/*<!M><~nbspace><%parenright>                                      */ DEADTRANS( L')'	,0xF279	,0xF343	,0x0001), // Multikey chain
/*<!M><~nbspace><%parenright><%bracketleft>                        */ DEADTRANS( L'['	,0xF343	,0x27EF	,0x0000), // '[' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenright><%bracketright>                       */ DEADTRANS( L']'	,0xF343	,0x27EF	,0x0000), // ']' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~nbspace><%parenright><%greater>                            */ DEADTRANS( L'>'	,0xF343	,0x2994	,0x0000), // '>' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~nbspace><%parenright><%parenright>                         */ DEADTRANS( L')'	,0xF343	,0x2986	,0x0000), // ')' ➔ "⦆" RIGHT WHITE PARENTHESIS
/*<!M><~nbspace><%period>                                          */ DEADTRANS( L'.'	,0xF279	,0xF348	,0x0001), // Multikey chain
/*<!M><~nbspace><%period><a>                                       */ DEADTRANS( L'a'	,0xF348	,0x2A51	,0x0000), // 'a' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><A>                                       */ DEADTRANS( L'A'	,0xF348	,0x2A51	,0x0000), // 'A' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><b>                                       */ DEADTRANS( L'b'	,0xF348	,0x2AC4	,0x0000), // 'b' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c>                                       */ DEADTRANS( L'c'	,0xF348	,0xF34C	,0x0001), // Multikey chain
/*<!M><~nbspace><%period><c><%backslash>                           */ DEADTRANS( L'\\'	,0xF34C	,0x2AC4	,0x0000), // '\' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c><%underscore>                          */ DEADTRANS( L'_'	,0xF34C	,0x2AC3	,0x0000), // '_' ➔ "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><c><c>                                    */ DEADTRANS( L'c'	,0xF34C	,0x2AC4	,0x0000), // 'c' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~nbspace><%period><e>                                       */ DEADTRANS( L'e'	,0xF348	,0x22F5	,0x0000), // 'e' ➔ "⋵" ELEMENT OF WITH DOT ABOVE
/*<!M><~nbspace><%period><v>                                       */ DEADTRANS( L'v'	,0xF348	,0xF351	,0x0001), // Multikey chain
/*<!M><~nbspace><%period><V>                                       */ DEADTRANS( L'V'	,0xF348	,0xF352	,0x0001), // Multikey chain
/*<!M><~nbspace><%period><v><v>                                    */ DEADTRANS( L'v'	,0xF351	,0x2A51	,0x0000), // 'v' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><V><V>                                    */ DEADTRANS( L'V'	,0xF352	,0x2A51	,0x0000), // 'V' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~nbspace><%period><v><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF351	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><V><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF352	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><v><~space>                               */ DEADTRANS( L' '	,0xF351	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><V><~space>                               */ DEADTRANS( L' '	,0xF352	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~nbspace><%period><x>                                       */ DEADTRANS( L'x'	,0xF348	,0x2A30	,0x0000), // 'x' ➔ "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><~nbspace><%period><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF348	,0x22C5	,0x0000), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~nbspace><%period><~space>                                  */ DEADTRANS( L' '	,0xF348	,0x22C5	,0x0000), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~nbspace><%plus>                                            */ DEADTRANS( L'+'	,0xF279	,0xF35C	,0x0001), // Multikey chain
/*<!M><~nbspace><%plus><%apostrophe>                               */ DEADTRANS( L'\''	,0xF35C	,0x22B9	,0x0000), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%plus><%aprightsingquotmark>                      */ DEADTRANS( 0x2019	,0xF35C	,0x22B9	,0x0000), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~nbspace><%plus><%circum>                                   */ DEADTRANS( L'^'	,0xF35C	,0x2A28	,0x0000), // '^' ➔ "⨨" PLUS SIGN WITH BLACK TRIANGLE
/*<!M><~nbspace><%plus><%plus>                                     */ DEADTRANS( L'+'	,0xF35C	,0x29FA	,0x0000), // '+' ➔ "⧺" DOUBLE PLUS
/*<!M><~nbspace><%plus><2>                                         */ DEADTRANS( L'2'	,0xF35C	,0x2A27	,0x0000), // '2' ➔ "⨧" PLUS SIGN WITH SUBSCRIPT TWO
/*<!M><~nbspace><%semicolon>                                       */ DEADTRANS( L';'	,0xF279	,0x2A1F	,0x0000), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~nbspace><%semsection>                                      */ DEADTRANS( 0x00A7	,0xF279	,0x2A1F	,0x0000), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~nbspace><%slash>                                           */ DEADTRANS( L'/'	,0xF279	,0xF364	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%backslash>                               */ DEADTRANS( L'\\'	,0xF364	,0xF365	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%backslash><%bar>                         */ DEADTRANS( L'|'	,0xF365	,0x2A1E	,0x0000), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~nbspace><%slash><%backslash><%hash>                        */ DEADTRANS( L'#'	,0xF365	,0x25C0	,0x0000), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~nbspace><%slash><%backslash><%underscore>                  */ DEADTRANS( L'_'	,0xF365	,0x29CD	,0x0000), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~nbspace><%slash><%hash>                                    */ DEADTRANS( L'#'	,0xF364	,0xF369	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%hash><%underscore>                       */ DEADTRANS( L'_'	,0xF369	,0xF36A	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%hash><%underscore><%backslash>           */ DEADTRANS( L'\\'	,0xF36A	,0x25B4	,0x0000), // '\' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%slash><%slash>                                   */ DEADTRANS( L'/'	,0xF364	,0xF36C	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%slash><%slash>                           */ DEADTRANS( L'/'	,0xF36C	,0x2AFB	,0x0000), // '/' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><~nbspace><%slash><%slash><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF36C	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~nbspace><%slash><%slash><~space>                           */ DEADTRANS( L' '	,0xF36C	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~nbspace><%slash><%underscore>                              */ DEADTRANS( L'_'	,0xF364	,0xF370	,0x0001), // Multikey chain
/*<!M><~nbspace><%slash><%underscore><%backslash>                  */ DEADTRANS( L'\\'	,0xF370	,0x25B5	,0x0000), // '\' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%slash><c>                                        */ DEADTRANS( L'c'	,0xF364	,0x27C8	,0x0000), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~nbspace><%slash><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF364	,0x2215	,0x0000), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~nbspace><%slash><~space>                                   */ DEADTRANS( L' '	,0xF364	,0x2215	,0x0000), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~nbspace><%tilde>                                           */ DEADTRANS( L'~'	,0xF279	,0xF375	,0x0001), // Multikey chain
/*<!M><~nbspace><%tilde><%colon>                                   */ DEADTRANS( L':'	,0xF375	,0x223B	,0x0000), // ':' ➔ "∻" HOMOTHETIC
/*<!M><~nbspace><%tilde><%equal>                                   */ DEADTRANS( L'='	,0xF375	,0xF377	,0x0001), // Multikey chain
/*<!M><~nbspace><%tilde><%equal><%slash>                           */ DEADTRANS( L'/'	,0xF377	,0xF378	,0x0001), // Multikey chain
/*<!M><~nbspace><%tilde><%equal><%slash><%slash>                   */ DEADTRANS( L'/'	,0xF378	,0x29E4	,0x0000), // '/' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><~nbspace><%tilde><%equal><%slash><~nbspace>                 */ DEADTRANS( 0x00A0	,0xF378	,0x2246	,0x0000), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~nbspace><%tilde><%equal><%slash><~space>                   */ DEADTRANS( L' '	,0xF378	,0x2246	,0x0000), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~nbspace><%tilde><%equal><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF377	,0x2245	,0x0000), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~nbspace><%tilde><%equal><~space>                           */ DEADTRANS( L' '	,0xF377	,0x2245	,0x0000), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~nbspace><%tilde><%greater>                                 */ DEADTRANS( L'>'	,0xF375	,0x2A9E	,0x0000), // '>' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><~nbspace><%tilde><%minus>                                   */ DEADTRANS( L'-'	,0xF375	,0x2972	,0x0000), // '-' ➔ "⥲" TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><~nbspace><%tilde><%percent>                                 */ DEADTRANS( L'%'	,0xF375	,0x2240	,0x0000), // '%' ➔ "≀" WREATH PRODUCT
/*<!M><~nbspace><%tilde><%slash>                                   */ DEADTRANS( L'/'	,0xF375	,0xF381	,0x0001), // Multikey chain
/*<!M><~nbspace><%tilde><%slash><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF381	,0x2241	,0x0000), // ' ' ➔ "≁" NOT TILDE
/*<!M><~nbspace><%tilde><%slash><~space>                           */ DEADTRANS( L' '	,0xF381	,0x2241	,0x0000), // ' ' ➔ "≁" NOT TILDE
/*<!M><~nbspace><%tilde><%tilde>                                   */ DEADTRANS( L'~'	,0xF375	,0xF384	,0x0001), // Multikey chain
/*<!M><~nbspace><%tilde><%tilde><%equal>                           */ DEADTRANS( L'='	,0xF384	,0x2A70	,0x0000), // '=' ➔ "⩰" APPROXIMATELY EQUAL OR EQUAL TO
/*<!M><~nbspace><%tilde><%tilde><%tilde>                           */ DEADTRANS( L'~'	,0xF384	,0x224B	,0x0000), // '~' ➔ "≋" TRIPLE TILDE
/*<!M><~nbspace><%tilde><%tilde><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF384	,0x2248	,0x0000), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~nbspace><%tilde><%tilde><~space>                           */ DEADTRANS( L' '	,0xF384	,0x2248	,0x0000), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~nbspace><%tilde><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF375	,0x223C	,0x0000), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~nbspace><%tilde><~space>                                   */ DEADTRANS( L' '	,0xF375	,0x223C	,0x0000), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~nbspace><%underscore>                                      */ DEADTRANS( L'_'	,0xF279	,0xF38B	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><%backslash>                          */ DEADTRANS( L'\\'	,0xF38B	,0x25BF	,0x0000), // '\' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore><%hash>                               */ DEADTRANS( L'#'	,0xF38B	,0x25BE	,0x0000), // '#' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore><%minus>                              */ DEADTRANS( L'-'	,0xF38B	,0xF38E	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><%minus><%apostrophe>                 */ DEADTRANS( L'\''	,0xF38E	,0x296D	,0x0000), // ''' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~nbspace><%underscore><%minus><%aprightsingquotmark>        */ DEADTRANS( 0x2019	,0xF38E	,0x296D	,0x0000), // '’' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~nbspace><%underscore><%minus><%slash>                      */ DEADTRANS( L'/'	,0xF38E	,0x29A4	,0x0000), // '/' ➔ "⦤" ANGLE WITH UNDERBAR
/*<!M><~nbspace><%underscore><%slash>                              */ DEADTRANS( L'/'	,0xF38B	,0x25BF	,0x0000), // '/' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~nbspace><%underscore><%underscore>                         */ DEADTRANS( L'_'	,0xF38B	,0xF393	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><%underscore><v>                      */ DEADTRANS( L'v'	,0xF393	,0xF394	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><%underscore><V>                      */ DEADTRANS( L'V'	,0xF393	,0xF395	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><%underscore><v><%percent>            */ DEADTRANS( L'%'	,0xF394	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V><%percent>            */ DEADTRANS( L'%'	,0xF395	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><v><~nbspace>            */ DEADTRANS( 0x00A0	,0xF394	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V><~nbspace>            */ DEADTRANS( 0x00A0	,0xF395	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><v><~space>              */ DEADTRANS( L' '	,0xF394	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><%underscore><V><~space>              */ DEADTRANS( L' '	,0xF395	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~nbspace><%underscore><a>                                   */ DEADTRANS( L'a'	,0xF38B	,0x22BC	,0x0000), // 'a' ➔ "⊼" NAND
/*<!M><~nbspace><%underscore><e>                                   */ DEADTRANS( L'e'	,0xF38B	,0xF39D	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><e><%backslash>                       */ DEADTRANS( L'\\'	,0xF39D	,0xF39E	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><e><%backslash><%comma>               */ DEADTRANS( L','	,0xF39E	,0x22FE	,0x0000), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e><%backslash><~nbspace>             */ DEADTRANS( 0x00A0	,0xF39E	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e><%backslash><~space>               */ DEADTRANS( L' '	,0xF39E	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><e><%comma>                           */ DEADTRANS( L','	,0xF39D	,0x22F7	,0x0000), // ',' ➔ "⋷" SMALL ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore><e><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF39D	,0x22F6	,0x0000), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore><e><~space>                           */ DEADTRANS( L' '	,0xF39D	,0x22F6	,0x0000), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~nbspace><%underscore><n>                                   */ DEADTRANS( L'n'	,0xF38B	,0x2A43	,0x0000), // 'n' ➔ "⩃" INTERSECTION WITH OVERBAR
/*<!M><~nbspace><%underscore><p>                                   */ DEADTRANS( L'p'	,0xF38B	,0xF3A6	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><p><%comma>                           */ DEADTRANS( L','	,0xF3A6	,0x22FE	,0x0000), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><p><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF3A6	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><p><~space>                           */ DEADTRANS( L' '	,0xF3A6	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~nbspace><%underscore><u>                                   */ DEADTRANS( L'u'	,0xF38B	,0xF3AA	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><u><%hash>                            */ DEADTRANS( L'#'	,0xF3AA	,0x2A50	,0x0000), // '#' ➔ "⩐" CLOSED UNION WITH SERIFS AND SMASH PRODUCT
/*<!M><~nbspace><%underscore><u><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF3AA	,0x2A42	,0x0000), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~nbspace><%underscore><u><~space>                           */ DEADTRANS( L' '	,0xF3AA	,0x2A42	,0x0000), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~nbspace><%underscore><v>                                   */ DEADTRANS( L'v'	,0xF38B	,0xF3AE	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><v><v>                                */ DEADTRANS( L'v'	,0xF3AE	,0x22BC	,0x0000), // 'v' ➔ "⊼" NAND
/*<!M><~nbspace><%underscore><v><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF3AE	,0x22BD	,0x0000), // ' ' ➔ "⊽" NOR
/*<!M><~nbspace><%underscore><v><~space>                           */ DEADTRANS( L' '	,0xF3AE	,0x22BD	,0x0000), // ' ' ➔ "⊽" NOR
/*<!M><~nbspace><%underscore><X>                                   */ DEADTRANS( L'X'	,0xF38B	,0xF3B2	,0x0001), // Multikey chain
/*<!M><~nbspace><%underscore><X><%hash>                            */ DEADTRANS( L'#'	,0xF3B2	,0x29D7	,0x0000), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><~nbspace><%underscore><X><%underscore>                      */ DEADTRANS( L'_'	,0xF3B2	,0x29D6	,0x0000), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><~nbspace><2>                                                */ DEADTRANS( L'2'	,0xF279	,0xF3B5	,0x0001), // Multikey chain
/*<!M><~nbspace><2><%less>                                         */ DEADTRANS( L'<'	,0xF3B5	,0x2AA3	,0x0000), // '<' ➔ "⪣" DOUBLE NESTED LESS-THAN WITH UNDERBAR
/*<!M><~nbspace><2><%minus>                                        */ DEADTRANS( L'-'	,0xF3B5	,0x21C9	,0x0000), // '-' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><~nbspace><3>                                                */ DEADTRANS( L'3'	,0xF279	,0xF3B8	,0x0001), // Multikey chain
/*<!M><~nbspace><3><%bar>                                          */ DEADTRANS( L'|'	,0xF3B8	,0x2AF4	,0x0000), // '|' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~nbspace><3><%minus>                                        */ DEADTRANS( L'-'	,0xF3B8	,0x21F6	,0x0000), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><~nbspace><8>                                                */ DEADTRANS( L'8'	,0xF279	,0x221D	,0x0000), // '8' ➔ "∝" PROPORTIONAL TO
/*<!M><~nbspace><A>                                                */ DEADTRANS( L'A'	,0xF279	,0xF3BC	,0x0001), // Multikey chain
/*<!M><~nbspace><a>                                                */ DEADTRANS( L'a'	,0xF279	,0xF3BD	,0x0001), // Multikey chain
/*<!M><~nbspace><A><%minus>                                        */ DEADTRANS( L'-'	,0xF3BC	,0x2A3A	,0x0000), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><~nbspace><A><%underscore>                                   */ DEADTRANS( L'_'	,0xF3BC	,0xF3BF	,0x0001), // Multikey chain
/*<!M><~nbspace><A><%underscore><%underscore>                      */ DEADTRANS( L'_'	,0xF3BF	,0x2A60	,0x0000), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><~nbspace><A><%underscore><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF3BF	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~nbspace><A><%underscore><~space>                           */ DEADTRANS( L' '	,0xF3BF	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~nbspace><A><A>                                             */ DEADTRANS( L'A'	,0xF3BC	,0x2A07	,0x0000), // 'A' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><~nbspace><a><a>                                             */ DEADTRANS( L'a'	,0xF3BD	,0x2A55	,0x0000), // 'a' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><~nbspace><A><V>                                             */ DEADTRANS( L'V'	,0xF3BC	,0x25CA	,0x0000), // 'V' ➔ "◊" LOZENGE
/*<!M><~nbspace><a><v>                                             */ DEADTRANS( L'v'	,0xF3BD	,0x25CA	,0x0000), // 'v' ➔ "◊" LOZENGE
/*<!M><~nbspace><A><~nbspace>                                      */ DEADTRANS( 0x00A0	,0xF3BC	,0x22C0	,0x0000), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~nbspace><A><~space>                                        */ DEADTRANS( L' '	,0xF3BC	,0x22C0	,0x0000), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~nbspace><b>                                                */ DEADTRANS( L'b'	,0xF279	,0xF3C9	,0x0001), // Multikey chain
/*<!M><~nbspace><b><%slash>                                        */ DEADTRANS( L'/'	,0xF3C9	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><b><c>                                             */ DEADTRANS( L'c'	,0xF3C9	,0x2AD7	,0x0000), // 'c' ➔ "⫗" SUPERSET BESIDE SUBSET
/*<!M><~nbspace><b><o>                                             */ DEADTRANS( L'o'	,0xF3C9	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c>                                                */ DEADTRANS( L'c'	,0xF279	,0xF3CD	,0x0001), // Multikey chain
/*<!M><~nbspace><c><%backslash>                                    */ DEADTRANS( L'\\'	,0xF3CD	,0xF3CE	,0x0001), // Multikey chain
/*<!M><~nbspace><c><%backslash><%slash>                            */ DEADTRANS( L'/'	,0xF3CE	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><c><%backslash><o>                                 */ DEADTRANS( L'o'	,0xF3CE	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c><c>                                             */ DEADTRANS( L'c'	,0xF3CD	,0xF3D1	,0x0001), // Multikey chain
/*<!M><~nbspace><c><c><%slash>                                     */ DEADTRANS( L'/'	,0xF3D1	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~nbspace><c><c><o>                                          */ DEADTRANS( L'o'	,0xF3D1	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~nbspace><c><c><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF3D1	,0x2AD5	,0x0000), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~nbspace><c><c><~space>                                     */ DEADTRANS( L' '	,0xF3D1	,0x2AD5	,0x0000), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~nbspace><c><o>                                             */ DEADTRANS( L'o'	,0xF3CD	,0x27C3	,0x0000), // 'o' ➔ "⟃" OPEN SUBSET
/*<!M><~nbspace><D>                                                */ DEADTRANS( L'D'	,0xF279	,0x2AD0	,0x0000), // 'D' ➔ "⫐" CLOSED SUPERSET
/*<!M><~nbspace><e>                                                */ DEADTRANS( L'e'	,0xF279	,0xF3D8	,0x0001), // Multikey chain
/*<!M><~nbspace><e><e>                                             */ DEADTRANS( L'e'	,0xF3D8	,0xF3D9	,0x0001), // Multikey chain
/*<!M><~nbspace><e><e><%bar>                                       */ DEADTRANS( L'|'	,0xF3D9	,0xF3DA	,0x0001), // Multikey chain
/*<!M><~nbspace><e><e><%bar><%comma>                               */ DEADTRANS( L','	,0xF3DA	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e><%bar><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF3DA	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e><%bar><~space>                               */ DEADTRANS( L' '	,0xF3DA	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~nbspace><e><e><%comma>                                     */ DEADTRANS( L','	,0xF3D9	,0x220D	,0x0000), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><~nbspace><e><e><%slash>                                     */ DEADTRANS( L'/'	,0xF3D9	,0x220C	,0x0000), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><~nbspace><e><e><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF3D9	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~nbspace><e><e><~space>                                     */ DEADTRANS( L' '	,0xF3D9	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~nbspace><G>                                                */ DEADTRANS( L'G'	,0xF279	,0x27F2	,0x0000), // 'G' ➔ "⟲" ANTICLOCKWISE GAPPED CIRCLE ARROW
/*<!M><~nbspace><I>                                                */ DEADTRANS( L'I'	,0xF279	,0x2AE0	,0x0000), // 'I' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace><K>                                                */ DEADTRANS( L'K'	,0xF279	,0x212A	,0x0000), // 'K' ➔ "K" KELVIN SIGN
/*<!M><~nbspace><k>                                                */ DEADTRANS( L'k'	,0xF279	,0x212A	,0x0000), // 'k' ➔ "K" KELVIN SIGN
/*<!M><~nbspace><n>                                                */ DEADTRANS( L'n'	,0xF279	,0xF3E6	,0x0001), // Multikey chain
/*<!M><~nbspace><n><%bar>                                          */ DEADTRANS( L'|'	,0xF3E6	,0x2ADB	,0x0000), // '|' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><~nbspace><o>                                                */ DEADTRANS( L'o'	,0xF279	,0xF3E8	,0x0001), // Multikey chain
/*<!M><~nbspace><O>                                                */ DEADTRANS( L'O'	,0xF279	,0xF3E9	,0x0001), // Multikey chain
/*<!M><~nbspace><O><%backslash>                                    */ DEADTRANS( L'\\'	,0xF3E9	,0x29B0	,0x0000), // '\' ➔ "⦰" REVERSED EMPTY SET
/*<!M><~nbspace><o><%equal>                                        */ DEADTRANS( L'='	,0xF3E8	,0x229C	,0x0000), // '=' ➔ "⊜" CIRCLED EQUALS
/*<!M><~nbspace><o><%greater>                                      */ DEADTRANS( L'>'	,0xF3E8	,0x2A7A	,0x0000), // '>' ➔ "⩺" GREATER-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><o><%minus>                                        */ DEADTRANS( L'-'	,0xF3E8	,0xF3ED	,0x0001), // Multikey chain
/*<!M><~nbspace><o><%minus><%greater>                              */ DEADTRANS( L'>'	,0xF3ED	,0x21F4	,0x0000), // '>' ➔ "⇴" RIGHT ARROW WITH SMALL CIRCLE
/*<!M><~nbspace><o><%minus><~nbspace>                              */ DEADTRANS( 0x00A0	,0xF3ED	,0x229D	,0x0000), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~nbspace><o><%minus><~space>                                */ DEADTRANS( L' '	,0xF3ED	,0x229D	,0x0000), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~nbspace><O><%percent>                                      */ DEADTRANS( L'%'	,0xF3E9	,0x29BC	,0x0000), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~nbspace><o><%percent>                                      */ DEADTRANS( L'%'	,0xF3E8	,0x29BC	,0x0000), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~nbspace><O><%period>                                       */ DEADTRANS( L'.'	,0xF3E9	,0x29BF	,0x0000), // '.' ➔ "⦿" CIRCLED BULLET
/*<!M><~nbspace><o><%plus>                                         */ DEADTRANS( L'+'	,0xF3E8	,0x2640	,0x0000), // '+' ➔ "♀" FEMALE SIGN
/*<!M><~nbspace><o><%semicolon>                                    */ DEADTRANS( L';'	,0xF3E8	,0x2A3E	,0x0000), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><o><%semsection>                                   */ DEADTRANS( 0x00A7	,0xF3E8	,0x2A3E	,0x0000), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><o><%slash>                                        */ DEADTRANS( L'/'	,0xF3E8	,0x2298	,0x0000), // '/' ➔ "⊘" CIRCLED DIVISION SLASH
/*<!M><~nbspace><o><8>                                             */ DEADTRANS( L'8'	,0xF3E8	,0x2663	,0x0000), // '8' ➔ "♣" BLACK CLUB SUIT
/*<!M><~nbspace><O><o>                                             */ DEADTRANS( L'o'	,0xF3E9	,0x29BE	,0x0000), // 'o' ➔ "⦾" CIRCLED WHITE BULLET
/*<!M><~nbspace><R>                                                */ DEADTRANS( L'R'	,0xF279	,0xF3FA	,0x0001), // Multikey chain
/*<!M><~nbspace><r>                                                */ DEADTRANS( L'r'	,0xF279	,0xF3FB	,0x0001), // Multikey chain
/*<!M><~nbspace><R><%slash>                                        */ DEADTRANS( L'/'	,0xF3FA	,0x211E	,0x0000), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~nbspace><r><%slash>                                        */ DEADTRANS( L'/'	,0xF3FB	,0x211E	,0x0000), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~nbspace><S>                                                */ DEADTRANS( L'S'	,0xF279	,0xF3FF	,0x0001), // Multikey chain
/*<!M><~nbspace><s>                                                */ DEADTRANS( L's'	,0xF279	,0x2A0B	,0x0000), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~nbspace><S><S>                                             */ DEADTRANS( L'S'	,0xF3FF	,0xF401	,0x0001), // Multikey chain
/*<!M><~nbspace><S><s>                                             */ DEADTRANS( L's'	,0xF3FF	,0x2A0B	,0x0000), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~nbspace><S><S><%at>                                        */ DEADTRANS( L'@'	,0xF401	,0x2140	,0x0000), // '@' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><S><S><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF401	,0x2140	,0x0000), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><S><S><~space>                                     */ DEADTRANS( L' '	,0xF401	,0x2140	,0x0000), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~nbspace><T>                                                */ DEADTRANS( L'T'	,0xF279	,0xF405	,0x0001), // Multikey chain
/*<!M><~nbspace><T><%percent>                                      */ DEADTRANS( L'%'	,0xF405	,0x2AE0	,0x0000), // '%' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace><T><T>                                             */ DEADTRANS( L'T'	,0xF405	,0x2AE0	,0x0000), // 'T' ➔ "⫠" SHORT UP TACK
/*<!M><~nbspace><V>                                                */ DEADTRANS( L'V'	,0xF279	,0xF409	,0x0001), // Multikey chain
/*<!M><~nbspace><v>                                                */ DEADTRANS( L'v'	,0xF279	,0x2A56	,0x0000), // 'v' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><~nbspace><V><V>                                             */ DEADTRANS( L'V'	,0xF409	,0x2A08	,0x0000), // 'V' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><~nbspace><x>                                                */ DEADTRANS( L'x'	,0xF279	,0x2A2F	,0x0000), // 'x' ➔ "⨯" VECTOR OR CROSS PRODUCT
/*<!M><~nbspace><Y>                                                */ DEADTRANS( L'Y'	,0xF279	,0xF40C	,0x0001), // Multikey chain
/*<!M><~nbspace><Y><%minus>                                        */ DEADTRANS( L'-'	,0xF40C	,0x297C	,0x0000), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><~nbspace><z>                                                */ DEADTRANS( L'z'	,0xF279	,0x2A3E	,0x0000), // 'z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace>                                         */ DEADTRANS( 0x00A0	,0xF279	,0xF40F	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%asterisk>                              */ DEADTRANS( L'*'	,0xF40F	,0x22C6	,0x0000), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~nbspace><~nbspace><%backslash>                             */ DEADTRANS( L'\\'	,0xF40F	,0xF411	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%backslash><%slash>                     */ DEADTRANS( L'/'	,0xF411	,0x25C1	,0x0000), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~nbspace><%backslash><~nbspace>                   */ DEADTRANS( 0x00A0	,0xF411	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~nbspace><%backslash><~space>                     */ DEADTRANS( L' '	,0xF411	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~nbspace><%bar>                                   */ DEADTRANS( L'|'	,0xF40F	,0xF415	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%bar><%bar>                             */ DEADTRANS( L'|'	,0xF415	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~nbspace><%bar><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF415	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><%bar><~space>                           */ DEADTRANS( L' '	,0xF415	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><%bracketleft>                           */ DEADTRANS( L'['	,0xF40F	,0xF419	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%bracketleft><%bracketright>            */ DEADTRANS( L']'	,0xF419	,0x25FD	,0x0000), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace><%bracketleft><%hash>                    */ DEADTRANS( L'#'	,0xF419	,0x25FE	,0x0000), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace><%bracketright>                          */ DEADTRANS( L']'	,0xF40F	,0xF41C	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%bracketright><%bracketleft>            */ DEADTRANS( L'['	,0xF41C	,0x25FD	,0x0000), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~nbspace><%colon>                                 */ DEADTRANS( L':'	,0xF40F	,0x2982	,0x0000), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~nbspace><~nbspace><%equal>                                 */ DEADTRANS( L'='	,0xF40F	,0xF41F	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%equal><%equal>                         */ DEADTRANS( L'='	,0xF41F	,0x2263	,0x0000), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~nbspace><~nbspace><%greater>                               */ DEADTRANS( L'>'	,0xF40F	,0xF421	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%greater><%less>                        */ DEADTRANS( L'<'	,0xF421	,0x2AA5	,0x0000), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~nbspace><~nbspace><%greater><%minus>                       */ DEADTRANS( L'-'	,0xF421	,0x2B43	,0x0000), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~nbspace><~nbspace><%hash>                                  */ DEADTRANS( L'#'	,0xF40F	,0x29E3	,0x0000), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~nbspace><~nbspace><%less>                                  */ DEADTRANS( L'<'	,0xF40F	,0xF425	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%less><%greater>                        */ DEADTRANS( L'>'	,0xF425	,0x25C7	,0x0000), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~nbspace><~nbspace><%less><o>                               */ DEADTRANS( L'o'	,0xF425	,0x2A79	,0x0000), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><~nbspace><%minus>                                 */ DEADTRANS( L'-'	,0xF40F	,0xF428	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%minus><%apostrophe>                    */ DEADTRANS( L'\''	,0xF428	,0x21C1	,0x0000), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~nbspace><%minus><%aprightsingquotmark>           */ DEADTRANS( 0x2019	,0xF428	,0x21C1	,0x0000), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~nbspace><%minus><%slash>                         */ DEADTRANS( L'/'	,0xF428	,0x299F	,0x0000), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~nbspace><~nbspace><%period>                                */ DEADTRANS( L'.'	,0xF40F	,0x2219	,0x0000), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~nbspace><~nbspace><%semicolon>                             */ DEADTRANS( L';'	,0xF40F	,0x2A3E	,0x0000), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace><%semsection>                            */ DEADTRANS( 0x00A7	,0xF40F	,0x2A3E	,0x0000), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~nbspace><%slash>                                 */ DEADTRANS( L'/'	,0xF40F	,0xF42F	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><%slash><%backslash>                     */ DEADTRANS( L'\\'	,0xF42F	,0x25C1	,0x0000), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~nbspace><%slash><%minus>                         */ DEADTRANS( L'-'	,0xF42F	,0x29A7	,0x0000), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~nbspace><~nbspace><%slash><~nbspace>                       */ DEADTRANS( 0x00A0	,0xF42F	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~nbspace><%slash><~space>                         */ DEADTRANS( L' '	,0xF42F	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~nbspace><%underscore>                            */ DEADTRANS( L'_'	,0xF40F	,0x2A4C	,0x0000), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~nbspace><~nbspace><3>                                      */ DEADTRANS( L'3'	,0xF40F	,0xF435	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><3><%bar>                                */ DEADTRANS( L'|'	,0xF435	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~nbspace><8>                                      */ DEADTRANS( L'8'	,0xF40F	,0x29DC	,0x0000), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~nbspace><~nbspace><I>                                      */ DEADTRANS( L'I'	,0xF40F	,0x27D8	,0x0000), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace><o>                                      */ DEADTRANS( L'o'	,0xF40F	,0xF43A	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><O>                                      */ DEADTRANS( L'O'	,0xF40F	,0x29C2	,0x0000), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~nbspace><~nbspace><o><%minus>                              */ DEADTRANS( L'-'	,0xF43A	,0x27DC	,0x0000), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~nbspace><~nbspace><o><%plus>                               */ DEADTRANS( L'+'	,0xF43A	,0x2A22	,0x0000), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~nbspace><~nbspace><T>                                      */ DEADTRANS( L'T'	,0xF40F	,0xF43D	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><T><%percent>                            */ DEADTRANS( L'%'	,0xF43D	,0x27D8	,0x0000), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace><T><T>                                   */ DEADTRANS( L'T'	,0xF43D	,0x27D8	,0x0000), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~nbspace><T><~nbspace>                            */ DEADTRANS( 0x00A0	,0xF43D	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~nbspace><T><~space>                              */ DEADTRANS( L' '	,0xF43D	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~nbspace><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF40F	,0xF442	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk>                    */ DEADTRANS( L'*'	,0xF442	,0xF443	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk><%hash>             */ DEADTRANS( L'#'	,0xF443	,0x2605	,0x0000), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk><~nbspace>          */ DEADTRANS( 0x00A0	,0xF443	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~nbspace><%asterisk><~space>            */ DEADTRANS( L' '	,0xF443	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~nbspace><%backslash>                   */ DEADTRANS( L'\\'	,0xF442	,0x27CD	,0x0000), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~nbspace><~nbspace><%bar>                         */ DEADTRANS( L'|'	,0xF442	,0x2AFF	,0x0000), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><~nbspace><%less>                        */ DEADTRANS( L'<'	,0xF442	,0x2662	,0x0000), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~nbspace><~nbspace><%slash>                       */ DEADTRANS( L'/'	,0xF442	,0x27CB	,0x0000), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~nbspace><~nbspace><o>                            */ DEADTRANS( L'o'	,0xF442	,0xDEF0	,0x0000), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace>                     */ DEADTRANS( 0x00A0	,0xF442	,0xF44C	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace><%backslash>         */ DEADTRANS( L'\\'	,0xF44C	,0x29F5	,0x0000), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~nbspace><~nbspace><%slash>             */ DEADTRANS( L'/'	,0xF44C	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~nbspace><~nbspace><~space>                       */ DEADTRANS( L' '	,0xF442	,0xF44F	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~nbspace><~space><%backslash>           */ DEADTRANS( L'\\'	,0xF44F	,0x29F5	,0x0000), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~nbspace><~space><%slash>               */ DEADTRANS( L'/'	,0xF44F	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~nbspace><~space>                                 */ DEADTRANS( L' '	,0xF40F	,0xF452	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~space><%asterisk>                      */ DEADTRANS( L'*'	,0xF452	,0xF453	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~space><%asterisk><%hash>               */ DEADTRANS( L'#'	,0xF453	,0x2605	,0x0000), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~nbspace><~space><%asterisk><~nbspace>            */ DEADTRANS( 0x00A0	,0xF453	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~space><%asterisk><~space>              */ DEADTRANS( L' '	,0xF453	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~nbspace><~space><%backslash>                     */ DEADTRANS( L'\\'	,0xF452	,0x27CD	,0x0000), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~nbspace><~space><%bar>                           */ DEADTRANS( L'|'	,0xF452	,0x2AFF	,0x0000), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~nbspace><~space><%less>                          */ DEADTRANS( L'<'	,0xF452	,0x2662	,0x0000), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~nbspace><~space><%slash>                         */ DEADTRANS( L'/'	,0xF452	,0x27CB	,0x0000), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~nbspace><~space><o>                              */ DEADTRANS( L'o'	,0xF452	,0xDEF0	,0x0000), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~nbspace><~space><~space>                         */ DEADTRANS( L' '	,0xF452	,0xF45C	,0x0001), // Multikey chain
/*<!M><~nbspace><~nbspace><~space><~space><%backslash>             */ DEADTRANS( L'\\'	,0xF45C	,0x29F5	,0x0000), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~nbspace><~space><~space><%slash>                 */ DEADTRANS( L'/'	,0xF45C	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbspace><~space>                                           */ DEADTRANS( L' '	,0xF279	,0xF45F	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%asterisk>                                */ DEADTRANS( L'*'	,0xF45F	,0x22C6	,0x0000), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~nbspace><~space><%backslash>                               */ DEADTRANS( L'\\'	,0xF45F	,0xF461	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%backslash><%slash>                       */ DEADTRANS( L'/'	,0xF461	,0x25C1	,0x0000), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~space><%backslash><~nbspace>                     */ DEADTRANS( 0x00A0	,0xF461	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~space><%backslash><~space>                       */ DEADTRANS( L' '	,0xF461	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~nbspace><~space><%bar>                                     */ DEADTRANS( L'|'	,0xF45F	,0xF465	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%bar><%bar>                               */ DEADTRANS( L'|'	,0xF465	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~space><%bar><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF465	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~space><%bar><~space>                             */ DEADTRANS( L' '	,0xF465	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~nbspace><~space><%bracketleft>                             */ DEADTRANS( L'['	,0xF45F	,0xF469	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%bracketleft><%bracketright>              */ DEADTRANS( L']'	,0xF469	,0x25FD	,0x0000), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space><%bracketleft><%hash>                      */ DEADTRANS( L'#'	,0xF469	,0x25FE	,0x0000), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space><%bracketright>                            */ DEADTRANS( L']'	,0xF45F	,0xF46C	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%bracketright><%bracketleft>              */ DEADTRANS( L'['	,0xF46C	,0x25FD	,0x0000), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~nbspace><~space><%colon>                                   */ DEADTRANS( L':'	,0xF45F	,0x2982	,0x0000), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~nbspace><~space><%equal>                                   */ DEADTRANS( L'='	,0xF45F	,0xF46F	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%equal><%equal>                           */ DEADTRANS( L'='	,0xF46F	,0x2263	,0x0000), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~nbspace><~space><%greater>                                 */ DEADTRANS( L'>'	,0xF45F	,0xF471	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%greater><%less>                          */ DEADTRANS( L'<'	,0xF471	,0x2AA5	,0x0000), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~nbspace><~space><%greater><%minus>                         */ DEADTRANS( L'-'	,0xF471	,0x2B43	,0x0000), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~nbspace><~space><%hash>                                    */ DEADTRANS( L'#'	,0xF45F	,0x29E3	,0x0000), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~nbspace><~space><%less>                                    */ DEADTRANS( L'<'	,0xF45F	,0xF475	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%less><%greater>                          */ DEADTRANS( L'>'	,0xF475	,0x25C7	,0x0000), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~nbspace><~space><%less><o>                                 */ DEADTRANS( L'o'	,0xF475	,0x2A79	,0x0000), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~nbspace><~space><%minus>                                   */ DEADTRANS( L'-'	,0xF45F	,0xF478	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%minus><%apostrophe>                      */ DEADTRANS( L'\''	,0xF478	,0x21C1	,0x0000), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~space><%minus><%aprightsingquotmark>             */ DEADTRANS( 0x2019	,0xF478	,0x21C1	,0x0000), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~nbspace><~space><%minus><%slash>                           */ DEADTRANS( L'/'	,0xF478	,0x299F	,0x0000), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~nbspace><~space><%period>                                  */ DEADTRANS( L'.'	,0xF45F	,0x2219	,0x0000), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~nbspace><~space><%semicolon>                               */ DEADTRANS( L';'	,0xF45F	,0x2A3E	,0x0000), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~space><%semsection>                              */ DEADTRANS( 0x00A7	,0xF45F	,0x2A3E	,0x0000), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~nbspace><~space><%slash>                                   */ DEADTRANS( L'/'	,0xF45F	,0xF47F	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><%slash><%backslash>                       */ DEADTRANS( L'\\'	,0xF47F	,0x25C1	,0x0000), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~nbspace><~space><%slash><%minus>                           */ DEADTRANS( L'-'	,0xF47F	,0x29A7	,0x0000), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~nbspace><~space><%slash><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF47F	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~space><%slash><~space>                           */ DEADTRANS( L' '	,0xF47F	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~nbspace><~space><%underscore>                              */ DEADTRANS( L'_'	,0xF45F	,0x2A4C	,0x0000), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~nbspace><~space><3>                                        */ DEADTRANS( L'3'	,0xF45F	,0xF485	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><3><%bar>                                  */ DEADTRANS( L'|'	,0xF485	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~nbspace><~space><8>                                        */ DEADTRANS( L'8'	,0xF45F	,0x29DC	,0x0000), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~nbspace><~space><I>                                        */ DEADTRANS( L'I'	,0xF45F	,0x27D8	,0x0000), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space><o>                                        */ DEADTRANS( L'o'	,0xF45F	,0xF48A	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><O>                                        */ DEADTRANS( L'O'	,0xF45F	,0x29C2	,0x0000), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~nbspace><~space><o><%minus>                                */ DEADTRANS( L'-'	,0xF48A	,0x27DC	,0x0000), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~nbspace><~space><o><%plus>                                 */ DEADTRANS( L'+'	,0xF48A	,0x2A22	,0x0000), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~nbspace><~space><T>                                        */ DEADTRANS( L'T'	,0xF45F	,0xF48D	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><T><%percent>                              */ DEADTRANS( L'%'	,0xF48D	,0x27D8	,0x0000), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space><T><T>                                     */ DEADTRANS( L'T'	,0xF48D	,0x27D8	,0x0000), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~nbspace><~space><T><~nbspace>                              */ DEADTRANS( 0x00A0	,0xF48D	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~space><T><~space>                                */ DEADTRANS( L' '	,0xF48D	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~nbspace><~space><~space>                                   */ DEADTRANS( L' '	,0xF45F	,0xF492	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><~space><%asterisk>                        */ DEADTRANS( L'*'	,0xF492	,0xF493	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><~space><%asterisk><%hash>                 */ DEADTRANS( L'#'	,0xF493	,0x2605	,0x0000), // '#' ➔ "★" BLACK STAR
/*<!M><~nbspace><~space><~space><%asterisk><~nbspace>              */ DEADTRANS( 0x00A0	,0xF493	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~space><~space><%asterisk><~space>                */ DEADTRANS( L' '	,0xF493	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~nbspace><~space><~space><%backslash>                       */ DEADTRANS( L'\\'	,0xF492	,0x27CD	,0x0000), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~nbspace><~space><~space><%bar>                             */ DEADTRANS( L'|'	,0xF492	,0x2AFF	,0x0000), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~nbspace><~space><~space><%less>                            */ DEADTRANS( L'<'	,0xF492	,0x2662	,0x0000), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~nbspace><~space><~space><%slash>                           */ DEADTRANS( L'/'	,0xF492	,0x27CB	,0x0000), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~nbspace><~space><~space><o>                                */ DEADTRANS( L'o'	,0xF492	,0xDEF0	,0x0000), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~nbspace><~space><~space><~space>                           */ DEADTRANS( L' '	,0xF492	,0xF49C	,0x0001), // Multikey chain
/*<!M><~nbspace><~space><~space><~space><%backslash>               */ DEADTRANS( L'\\'	,0xF49C	,0x29F5	,0x0000), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~nbspace><~space><~space><~space><%slash>                   */ DEADTRANS( L'/'	,0xF49C	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH
/*<!M><~nbthinspace>                                               */ DEADTRANS( 0x202F	,0x00A6	,0xF49F	,0x0001), // Multikey chain
/*<!M><~nbthinspace><~space>                                       */ DEADTRANS( L' '	,0xF49F	,0x238D	,0x0000), // ' ' ➔ "⎍" MONOSTABLE SYMBOL
/*<!M><~space>                                                     */ DEADTRANS( L' '	,0x00A6	,0xF4A1	,0x0001), // Multikey chain
/*<!M><~space><%ampersand>                                         */ DEADTRANS( L'&'	,0xF4A1	,0xF4A2	,0x0001), // Multikey chain
/*<!M><~space><%ampersand><%bar>                                   */ DEADTRANS( L'|'	,0xF4A2	,0x20D3	,0x0000), // '|' ➔ "⃓" COMBINING SHORT VERTICAL LINE OVERLAY
/*<!M><~space><%ampersand><%less>                                  */ DEADTRANS( L'<'	,0xF4A2	,0x20EE	,0x0000), // '<' ➔ "⃮" COMBINING LEFT ARROW BELOW
/*<!M><~space><%ampersand><%minus>                                 */ DEADTRANS( L'-'	,0xF4A2	,0x20EF	,0x0000), // '-' ➔ "⃯" COMBINING RIGHT ARROW BELOW
/*<!M><~space><%apostrophe>                                        */ DEADTRANS( L'\''	,0xF4A1	,0xF4A6	,0x0001), // Multikey chain
/*<!M><~space><%apostrophe><%equal>                                */ DEADTRANS( L'='	,0xF4A6	,0x2AED	,0x0000), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~space><%apostrophe><%minus>                                */ DEADTRANS( L'-'	,0xF4A6	,0x2A3D	,0x0000), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~space><%apostrophe><%plus>                                 */ DEADTRANS( L'+'	,0xF4A6	,0x22B9	,0x0000), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%aprightsingquotmark>                               */ DEADTRANS( 0x2019	,0xF4A1	,0xF4AA	,0x0001), // Multikey chain
/*<!M><~space><%aprightsingquotmark><%equal>                       */ DEADTRANS( L'='	,0xF4AA	,0x2AED	,0x0000), // '=' ➔ "⫭" REVERSED DOUBLE STROKE NOT SIGN
/*<!M><~space><%aprightsingquotmark><%minus>                       */ DEADTRANS( L'-'	,0xF4AA	,0x2A3D	,0x0000), // '-' ➔ "⨽" RIGHTHAND INTERIOR PRODUCT
/*<!M><~space><%aprightsingquotmark><%plus>                        */ DEADTRANS( L'+'	,0xF4AA	,0x22B9	,0x0000), // '+' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%asterisk>                                          */ DEADTRANS( L'*'	,0xF4A1	,0xF4AE	,0x0001), // Multikey chain
/*<!M><~space><%asterisk><%equal>                                  */ DEADTRANS( L'='	,0xF4AE	,0x225B	,0x0000), // '=' ➔ "≛" STAR EQUALS
/*<!M><~space><%asterisk><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF4AE	,0x2217	,0x0000), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~space><%asterisk><~space>                                  */ DEADTRANS( L' '	,0xF4AE	,0x2217	,0x0000), // ' ' ➔ "∗" ASTERISK OPERATOR
/*<!M><~space><%backslash>                                         */ DEADTRANS( L'\\'	,0xF4A1	,0xF4B2	,0x0001), // Multikey chain
/*<!M><~space><%backslash><%greater>                               */ DEADTRANS( L'>'	,0xF4B2	,0x292D	,0x0000), // '>' ➔ "⤭" SOUTH EAST ARROW CROSSING NORTH EAST ARROW
/*<!M><~space><%backslash><%minus>                                 */ DEADTRANS( L'-'	,0xF4B2	,0x29A3	,0x0000), // '-' ➔ "⦣" REVERSED ANGLE
/*<!M><~space><%backslash><%slash>                                 */ DEADTRANS( L'/'	,0xF4B2	,0xF4B5	,0x0001), // Multikey chain
/*<!M><~space><%backslash><%slash><%bar>                           */ DEADTRANS( L'|'	,0xF4B5	,0x2A1E	,0x0000), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~space><%backslash><%slash><%hash>                          */ DEADTRANS( L'#'	,0xF4B5	,0x25C0	,0x0000), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~space><%backslash><%slash><%underscore>                    */ DEADTRANS( L'_'	,0xF4B5	,0x29CD	,0x0000), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~space><%backslash><c>                                      */ DEADTRANS( L'c'	,0xF4B2	,0x27C8	,0x0000), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~space><%backslash><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF4B2	,0x2216	,0x0000), // ' ' ➔ "∖" SET MINUS
/*<!M><~space><%backslash><~space>                                 */ DEADTRANS( L' '	,0xF4B2	,0x2216	,0x0000), // ' ' ➔ "∖" SET MINUS
/*<!M><~space><%bar>                                               */ DEADTRANS( L'|'	,0xF4A1	,0xF4BC	,0x0001), // Multikey chain
/*<!M><~space><%bar><%backslash>                                   */ DEADTRANS( L'\\'	,0xF4BC	,0xF4BD	,0x0001), // Multikey chain
/*<!M><~space><%bar><%backslash><%slash>                           */ DEADTRANS( L'/'	,0xF4BD	,0xF4BE	,0x0001), // Multikey chain
/*<!M><~space><%bar><%backslash><%slash><%bar>                     */ DEADTRANS( L'|'	,0xF4BE	,0x2A1D	,0x0000), // '|' ➔ "⨝" JOIN
/*<!M><~space><%bar><%backslash><%slash><~nbspace>                 */ DEADTRANS( 0x00A0	,0xF4BE	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%backslash><%slash><~space>                   */ DEADTRANS( L' '	,0xF4BE	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%bar>                                         */ DEADTRANS( L'|'	,0xF4BC	,0xF4C2	,0x0001), // Multikey chain
/*<!M><~space><%bar><%bar><%bar>                                   */ DEADTRANS( L'|'	,0xF4C2	,0xF4C3	,0x0001), // Multikey chain
/*<!M><~space><%bar><%bar><%bar><%minus>                           */ DEADTRANS( L'-'	,0xF4C3	,0x22AA	,0x0000), // '-' ➔ "⊪" TRIPLE VERTICAL BAR RIGHT TURNSTILE
/*<!M><~space><%bar><%bar><%bar><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF4C3	,0x2AF4	,0x0000), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><%bar><%bar><%bar><~space>                           */ DEADTRANS( L' '	,0xF4C3	,0x2AF4	,0x0000), // ' ' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><%bar><%bar><%minus>                                 */ DEADTRANS( L'-'	,0xF4C2	,0x22A9	,0x0000), // '-' ➔ "⊩" FORCES
/*<!M><~space><%bar><%bar><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF4C2	,0x2225	,0x0000), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~space><%bar><%bar><~space>                                 */ DEADTRANS( L' '	,0xF4C2	,0x2225	,0x0000), // ' ' ➔ "∥" PARALLEL TO
/*<!M><~space><%bar><%equal>                                       */ DEADTRANS( L'='	,0xF4BC	,0x29E7	,0x0000), // '=' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%bar><%hash>                                        */ DEADTRANS( L'#'	,0xF4BC	,0x25B6	,0x0000), // '#' ➔ "▶" BLACK RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%minus>                                       */ DEADTRANS( L'-'	,0xF4BC	,0x27CA	,0x0000), // '-' ➔ "⟊" VERTICAL BAR WITH HORIZONTAL STROKE
/*<!M><~space><%bar><%parenright>                                  */ DEADTRANS( L')'	,0xF4BC	,0x2ADD	,0x0000), // ')' ➔ "⫝" NONFORKING
/*<!M><~space><%bar><%slash>                                       */ DEADTRANS( L'/'	,0xF4BC	,0xF4CE	,0x0001), // Multikey chain
/*<!M><~space><%bar><%slash><%backslash>                           */ DEADTRANS( L'\\'	,0xF4CE	,0xF4CF	,0x0001), // Multikey chain
/*<!M><~space><%bar><%slash><%backslash><%bar>                     */ DEADTRANS( L'|'	,0xF4CF	,0x2A1D	,0x0000), // '|' ➔ "⨝" JOIN
/*<!M><~space><%bar><%slash><%backslash><~nbspace>                 */ DEADTRANS( 0x00A0	,0xF4CF	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%slash><%backslash><~space>                   */ DEADTRANS( L' '	,0xF4CF	,0x25B7	,0x0000), // ' ' ➔ "▷" WHITE RIGHT-POINTING TRIANGLE
/*<!M><~space><%bar><%slash><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF4CE	,0x2A57	,0x0000), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~space><%bar><%slash><~space>                               */ DEADTRANS( L' '	,0xF4CE	,0x2A57	,0x0000), // ' ' ➔ "⩗" SLOPING LARGE OR
/*<!M><~space><%bar><e>                                            */ DEADTRANS( L'e'	,0xF4BC	,0xF4D5	,0x0001), // Multikey chain
/*<!M><~space><%bar><e><%backslash>                                */ DEADTRANS( L'\\'	,0xF4D5	,0xF4D6	,0x0001), // Multikey chain
/*<!M><~space><%bar><e><%backslash><%comma>                        */ DEADTRANS( L','	,0xF4D6	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><%backslash><~nbspace>                      */ DEADTRANS( 0x00A0	,0xF4D6	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><%backslash><~space>                        */ DEADTRANS( L' '	,0xF4D6	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e>                                         */ DEADTRANS( L'e'	,0xF4D5	,0xF4DA	,0x0001), // Multikey chain
/*<!M><~space><%bar><e><e><%comma>                                 */ DEADTRANS( L','	,0xF4DA	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF4DA	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><e><e><~space>                                 */ DEADTRANS( L' '	,0xF4DA	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><o>                                            */ DEADTRANS( L'o'	,0xF4BC	,0x2AF0	,0x0000), // 'o' ➔ "⫰" VERTICAL LINE WITH CIRCLE BELOW
/*<!M><~space><%bar><p>                                            */ DEADTRANS( L'p'	,0xF4BC	,0xF4DF	,0x0001), // Multikey chain
/*<!M><~space><%bar><p><%comma>                                    */ DEADTRANS( L','	,0xF4DF	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><p><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF4DF	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><p><~space>                                    */ DEADTRANS( L' '	,0xF4DF	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><%bar><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xF4BC	,0x2223	,0x0000), // ' ' ➔ "∣" DIVIDES
/*<!M><~space><%bar><~space>                                       */ DEADTRANS( L' '	,0xF4BC	,0x2223	,0x0000), // ' ' ➔ "∣" DIVIDES
/*<!M><~space><%braceleft>                                         */ DEADTRANS( L'{'	,0xF4A1	,0x2983	,0x0000), // '{' ➔ "⦃" LEFT WHITE CURLY BRACKET
/*<!M><~space><%braceright>                                        */ DEADTRANS( L'}'	,0xF4A1	,0x2984	,0x0000), // '}' ➔ "⦄" RIGHT WHITE CURLY BRACKET
/*<!M><~space><%bracketleft>                                       */ DEADTRANS( L'['	,0xF4A1	,0xF4E7	,0x0001), // Multikey chain
/*<!M><~space><%bracketleft><%bracketleft>                         */ DEADTRANS( L'['	,0xF4E7	,0x27E6	,0x0000), // '[' ➔ "⟦" MATHEMATICAL LEFT WHITE SQUARE BRACKET
/*<!M><~space><%bracketleft><%bracketright>                        */ DEADTRANS( L']'	,0xF4E7	,0x25FB	,0x0000), // ']' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~space><%bracketleft><%hash>                                */ DEADTRANS( L'#'	,0xF4E7	,0x25FC	,0x0000), // '#' ➔ "◼" BLACK MEDIUM SQUARE
/*<!M><~space><%bracketleft><%minus>                               */ DEADTRANS( L'-'	,0xF4E7	,0x2ACD	,0x0000), // '-' ➔ "⫍" SQUARE LEFT OPEN BOX OPERATOR
/*<!M><~space><%bracketleft><%underscore>                          */ DEADTRANS( L'_'	,0xF4E7	,0x298B	,0x0000), // '_' ➔ "⦋" LEFT SQUARE BRACKET WITH UNDERBAR
/*<!M><~space><%bracketleft><a>                                    */ DEADTRANS( L'a'	,0xF4E7	,0x27CE	,0x0000), // 'a' ➔ "⟎" SQUARED LOGICAL AND
/*<!M><~space><%bracketleft><o>                                    */ DEADTRANS( L'o'	,0xF4E7	,0x29C7	,0x0000), // 'o' ➔ "⧇" SQUARED SMALL CIRCLE
/*<!M><~space><%bracketright>                                      */ DEADTRANS( L']'	,0xF4A1	,0xF4EF	,0x0001), // Multikey chain
/*<!M><~space><%bracketright><%bracketleft>                        */ DEADTRANS( L'['	,0xF4EF	,0x25FB	,0x0000), // '[' ➔ "◻" WHITE MEDIUM SQUARE
/*<!M><~space><%bracketright><%bracketright>                       */ DEADTRANS( L']'	,0xF4EF	,0x27E7	,0x0000), // ']' ➔ "⟧" MATHEMATICAL RIGHT WHITE SQUARE BRACKET
/*<!M><~space><%bracketright><%underscore>                         */ DEADTRANS( L'_'	,0xF4EF	,0x298C	,0x0000), // '_' ➔ "⦌" RIGHT SQUARE BRACKET WITH UNDERBAR
/*<!M><~space><%circum>                                            */ DEADTRANS( L'^'	,0xF4A1	,0xF4F3	,0x0001), // Multikey chain
/*<!M><~space><%circum><%circum>                                   */ DEADTRANS( L'^'	,0xF4F3	,0x22C4	,0x0000), // '^' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~space><%circum><%equal>                                    */ DEADTRANS( L'='	,0xF4F3	,0x2259	,0x0000), // '=' ➔ "≙" ESTIMATES
/*<!M><~space><%circum><%underscore>                               */ DEADTRANS( L'_'	,0xF4F3	,0x25B5	,0x0000), // '_' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~space><%circum><o>                                         */ DEADTRANS( L'o'	,0xF4F3	,0x2A36	,0x0000), // 'o' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~space><%circum><O>                                         */ DEADTRANS( L'O'	,0xF4F3	,0x2A36	,0x0000), // 'O' ➔ "⨶" CIRCLED MULTIPLICATION SIGN WITH CIRCUMFLEX ACCENT
/*<!M><~space><%circum><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF4F3	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~space><%circum><~space>                                    */ DEADTRANS( L' '	,0xF4F3	,0x2227	,0x0000), // ' ' ➔ "∧" LOGICAL AND
/*<!M><~space><%colon>                                             */ DEADTRANS( L':'	,0xF4A1	,0xF4FB	,0x0001), // Multikey chain
/*<!M><~space><%colon><%colon>                                     */ DEADTRANS( L':'	,0xF4FB	,0x2237	,0x0000), // ':' ➔ "∷" PROPORTION
/*<!M><~space><%colon><%tilde>                                     */ DEADTRANS( L'~'	,0xF4FB	,0x223B	,0x0000), // '~' ➔ "∻" HOMOTHETIC
/*<!M><~space><%colon><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF4FB	,0x2236	,0x0000), // ' ' ➔ "∶" RATIO
/*<!M><~space><%colon><~space>                                     */ DEADTRANS( L' '	,0xF4FB	,0x2236	,0x0000), // ' ' ➔ "∶" RATIO
/*<!M><~space><%equal>                                             */ DEADTRANS( L'='	,0xF4A1	,0xF500	,0x0001), // Multikey chain
/*<!M><~space><%equal><%bar>                                       */ DEADTRANS( L'|'	,0xF500	,0xF501	,0x0001), // Multikey chain
/*<!M><~space><%equal><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xF501	,0x22D5	,0x0000), // '|' ➔ "⋕" EQUAL AND PARALLEL TO
/*<!M><~space><%equal><%bar><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF501	,0x29E7	,0x0000), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%equal><%bar><~space>                               */ DEADTRANS( L' '	,0xF501	,0x29E7	,0x0000), // ' ' ➔ "⧧" THERMODYNAMIC
/*<!M><~space><%equal><%equal>                                     */ DEADTRANS( L'='	,0xF500	,0x2A75	,0x0000), // '=' ➔ "⩵" TWO CONSECUTIVE EQUALS SIGNS
/*<!M><~space><%equal><%greater>                                   */ DEADTRANS( L'>'	,0xF500	,0x2A9A	,0x0000), // '>' ➔ "⪚" DOUBLE-LINE EQUAL TO OR GREATER-THAN
/*<!M><~space><%equal><%minus>                                     */ DEADTRANS( L'-'	,0xF500	,0xF507	,0x0001), // Multikey chain
/*<!M><~space><%equal><%minus><%greater>                           */ DEADTRANS( L'>'	,0xF507	,0x2971	,0x0000), // '>' ➔ "⥱" EQUALS SIGN ABOVE RIGHTWARDS ARROW
/*<!M><~space><%equal><%minus><%slash>                             */ DEADTRANS( L'/'	,0xF507	,0x29E5	,0x0000), // '/' ➔ "⧥" IDENTICAL TO AND SLANTED PARALLEL
/*<!M><~space><%exclam>                                            */ DEADTRANS( L'!'	,0xF4A1	,0xF50A	,0x0001), // Multikey chain
/*<!M><~space><%exclam><%exclam>                                   */ DEADTRANS( L'!'	,0xF50A	,0x00A1	,0x0000), // '!' ➔ "¡" INVERTED EXCLAMATION MARK
/*<!M><~space><%exclam><j>                                         */ DEADTRANS( L'j'	,0xF50A	,0x297F	,0x0000), // 'j' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%exclam><J>                                         */ DEADTRANS( L'J'	,0xF50A	,0x297F	,0x0000), // 'J' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%exclam><Y>                                         */ DEADTRANS( L'Y'	,0xF50A	,0x297F	,0x0000), // 'Y' ➔ "⥿" DOWN FISH TAIL
/*<!M><~space><%greater>                                           */ DEADTRANS( L'>'	,0xF4A1	,0xF50F	,0x0001), // Multikey chain
/*<!M><~space><%greater><%greater>                                 */ DEADTRANS( L'>'	,0xF50F	,0xF510	,0x0001), // Multikey chain
/*<!M><~space><%greater><%greater><%greater>                       */ DEADTRANS( L'>'	,0xF510	,0x22D9	,0x0000), // '>' ➔ "⋙" VERY MUCH GREATER-THAN
/*<!M><~space><%greater><%greater><~nbspace>                       */ DEADTRANS( 0x00A0	,0xF510	,0x226B	,0x0000), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~space><%greater><%greater><~space>                         */ DEADTRANS( L' '	,0xF510	,0x226B	,0x0000), // ' ' ➔ "≫" MUCH GREATER-THAN
/*<!M><~space><%greater><%less>                                    */ DEADTRANS( L'<'	,0xF50F	,0x2AA4	,0x0000), // '<' ➔ "⪤" GREATER-THAN OVERLAPPING LESS-THAN
/*<!M><~space><%greater><%minus>                                   */ DEADTRANS( L'-'	,0xF50F	,0xF515	,0x0001), // Multikey chain
/*<!M><~space><%greater><%minus><%greater>                         */ DEADTRANS( L'>'	,0xF515	,0x2978	,0x0000), // '>' ➔ "⥸" GREATER-THAN ABOVE RIGHTWARDS ARROW
/*<!M><~space><%greater><%minus><~nbspace>                         */ DEADTRANS( 0x00A0	,0xF515	,0x2AAB	,0x0000), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~space><%greater><%minus><~space>                           */ DEADTRANS( L' '	,0xF515	,0x2AAB	,0x0000), // ' ' ➔ "⪫" LARGER THAN
/*<!M><~space><%greater><%parenright>                              */ DEADTRANS( L')'	,0xF50F	,0x2994	,0x0000), // ')' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~space><%greater><o>                                        */ DEADTRANS( L'o'	,0xF50F	,0x2941	,0x0000), // 'o' ➔ "⥁" CLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~space><%greater><~nbspace>                                 */ DEADTRANS( 0x00A0	,0xF50F	,0x200E	,0x0000), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~space><%greater><~space>                                   */ DEADTRANS( L' '	,0xF50F	,0x200E	,0x0000), // ' ' ➔ "‎" LEFT-TO-RIGHT MARK
/*<!M><~space><%hash>                                              */ DEADTRANS( L'#'	,0xF4A1	,0xF51D	,0x0001), // Multikey chain
/*<!M><~space><%hash><%percent>                                    */ DEADTRANS( L'%'	,0xF51D	,0x2A33	,0x0000), // '%' ➔ "⨳" SMASH PRODUCT
/*<!M><~space><%hash><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xF51D	,0x266F	,0x0000), // ' ' ➔ "♯" MUSIC SHARP SIGN
/*<!M><~space><%hash><~space>                                      */ DEADTRANS( L' '	,0xF51D	,0x266F	,0x0000), // ' ' ➔ "♯" MUSIC SHARP SIGN
/*<!M><~space><%less>                                              */ DEADTRANS( L'<'	,0xF4A1	,0xF521	,0x0001), // Multikey chain
/*<!M><~space><%less><%backslash>                                  */ DEADTRANS( L'\\'	,0xF521	,0x2932	,0x0000), // '\' ➔ "⤲" NORTH WEST ARROW CROSSING NORTH EAST ARROW
/*<!M><~space><%less><%equal>                                      */ DEADTRANS( L'='	,0xF521	,0xF523	,0x0001), // Multikey chain
/*<!M><~space><%less><%equal><%greater>                            */ DEADTRANS( L'>'	,0xF523	,0x2A8B	,0x0000), // '>' ➔ "⪋" LESS-THAN ABOVE DOUBLE-LINE EQUAL ABOVE GREATER-THAN
/*<!M><~space><%less><%equal><%slash>                              */ DEADTRANS( L'/'	,0xF523	,0x2268	,0x0000), // '/' ➔ "≨" LESS-THAN BUT NOT EQUAL TO
/*<!M><~space><%less><%equal><~nbspace>                            */ DEADTRANS( 0x00A0	,0xF523	,0x2266	,0x0000), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~space><%less><%equal><~space>                              */ DEADTRANS( L' '	,0xF523	,0x2266	,0x0000), // ' ' ➔ "≦" LESS-THAN OVER EQUAL TO
/*<!M><~space><%less><%exclam>                                     */ DEADTRANS( L'!'	,0xF521	,0x29BD	,0x0000), // '!' ➔ "⦽" UP ARROW THROUGH CIRCLE
/*<!M><~space><%less><%greater>                                    */ DEADTRANS( L'>'	,0xF521	,0x22C4	,0x0000), // '>' ➔ "⋄" DIAMOND OPERATOR
/*<!M><~space><%less><%less>                                       */ DEADTRANS( L'<'	,0xF521	,0xF52A	,0x0001), // Multikey chain
/*<!M><~space><%less><%less><%less>                                */ DEADTRANS( L'<'	,0xF52A	,0x22D8	,0x0000), // '<' ➔ "⋘" VERY MUCH LESS-THAN
/*<!M><~space><%less><%less><%minus>                               */ DEADTRANS( L'-'	,0xF52A	,0xF52C	,0x0001), // Multikey chain
/*<!M><~space><%less><%less><%minus><%bar>                         */ DEADTRANS( L'|'	,0xF52C	,0x2B36	,0x0000), // '|' ➔ "⬶" LEFTWARDS TWO-HEADED ARROW FROM BAR
/*<!M><~space><%less><%less><%minus><~nbspace>                     */ DEADTRANS( 0x00A0	,0xF52C	,0x2976	,0x0000), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~space><%less><%less><%minus><~space>                       */ DEADTRANS( L' '	,0xF52C	,0x2976	,0x0000), // ' ' ➔ "⥶" LESS-THAN ABOVE LEFTWARDS ARROW
/*<!M><~space><%less><%less><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF52A	,0x226A	,0x0000), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~space><%less><%less><~space>                               */ DEADTRANS( L' '	,0xF52A	,0x226A	,0x0000), // ' ' ➔ "≪" MUCH LESS-THAN
/*<!M><~space><%less><%minus>                                      */ DEADTRANS( L'-'	,0xF521	,0xF532	,0x0001), // Multikey chain
/*<!M><~space><%less><%minus><%bar>                                */ DEADTRANS( L'|'	,0xF532	,0x21F7	,0x0000), // '|' ➔ "⇷" LEFTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~space><%less><%minus><%less>                               */ DEADTRANS( L'<'	,0xF532	,0x2977	,0x0000), // '<' ➔ "⥷" LEFTWARDS ARROW THROUGH LESS-THAN
/*<!M><~space><%less><%minus><%minus>                              */ DEADTRANS( L'-'	,0xF532	,0x27F7	,0x0000), // '-' ➔ "⟷" LONG LEFT RIGHT ARROW
/*<!M><~space><%less><%minus><%tilde>                              */ DEADTRANS( L'~'	,0xF532	,0x2973	,0x0000), // '~' ➔ "⥳" LEFTWARDS ARROW ABOVE TILDE OPERATOR
/*<!M><~space><%less><%minus><~nbspace>                            */ DEADTRANS( 0x00A0	,0xF532	,0x2AAA	,0x0000), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~space><%less><%minus><~space>                              */ DEADTRANS( L' '	,0xF532	,0x2AAA	,0x0000), // ' ' ➔ "⪪" SMALLER THAN
/*<!M><~space><%less><%parenleft>                                  */ DEADTRANS( L'('	,0xF521	,0x2993	,0x0000), // '(' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~space><%less><%parenright>                                 */ DEADTRANS( L')'	,0xF521	,0x2AA6	,0x0000), // ')' ➔ "⪦" LESS-THAN CLOSED BY CURVE
/*<!M><~space><%less><%slash>                                      */ DEADTRANS( L'/'	,0xF521	,0x226E	,0x0000), // '/' ➔ "≮" NOT LESS-THAN
/*<!M><~space><%less><%tilde>                                      */ DEADTRANS( L'~'	,0xF521	,0xF53C	,0x0001), // Multikey chain
/*<!M><~space><%less><%tilde><%greater>                            */ DEADTRANS( L'>'	,0xF53C	,0x21AD	,0x0000), // '>' ➔ "↭" LEFT RIGHT WAVE ARROW
/*<!M><~space><%less><%tilde><%tilde>                              */ DEADTRANS( L'~'	,0xF53C	,0x21DC	,0x0000), // '~' ➔ "⇜" LEFTWARDS SQUIGGLE ARROW
/*<!M><~space><%less><%tilde><~nbspace>                            */ DEADTRANS( 0x00A0	,0xF53C	,0x2272	,0x0000), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~space><%less><%tilde><~space>                              */ DEADTRANS( L' '	,0xF53C	,0x2272	,0x0000), // ' ' ➔ "≲" LESS-THAN OR EQUIVALENT TO
/*<!M><~space><%less><3>                                           */ DEADTRANS( L'3'	,0xF521	,0x2660	,0x0000), // '3' ➔ "♠" BLACK SPADE SUIT
/*<!M><~space><%less><C>                                           */ DEADTRANS( L'C'	,0xF521	,0x293E	,0x0000), // 'C' ➔ "⤾" LOWER RIGHT SEMICIRCULAR CLOCKWISE ARROW
/*<!M><~space><%less><n>                                           */ DEADTRANS( L'n'	,0xF521	,0x21B6	,0x0000), // 'n' ➔ "↶" ANTICLOCKWISE TOP SEMICIRCLE ARROW
/*<!M><~space><%less><o>                                           */ DEADTRANS( L'o'	,0xF521	,0x2940	,0x0000), // 'o' ➔ "⥀" ANTICLOCKWISE CLOSED CIRCLE ARROW
/*<!M><~space><%less><~nbspace>                                    */ DEADTRANS( 0x00A0	,0xF521	,0x200F	,0x0000), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~space><%less><~space>                                      */ DEADTRANS( L' '	,0xF521	,0x200F	,0x0000), // ' ' ➔ "‏" RIGHT-TO-LEFT MARK
/*<!M><~space><%minus>                                             */ DEADTRANS( L'-'	,0xF4A1	,0xF547	,0x0001), // Multikey chain
/*<!M><~space><%minus><%apostrophe>                                */ DEADTRANS( L'\''	,0xF547	,0xF548	,0x0001), // Multikey chain
/*<!M><~space><%minus><%apostrophe><%minus>                        */ DEADTRANS( L'-'	,0xF548	,0x2ADF	,0x0000), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><%minus><%apostrophe><~nbspace>                      */ DEADTRANS( 0x00A0	,0xF548	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%apostrophe><~space>                        */ DEADTRANS( L' '	,0xF548	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%aprightsingquotmark>                       */ DEADTRANS( 0x2019	,0xF547	,0xF54C	,0x0001), // Multikey chain
/*<!M><~space><%minus><%aprightsingquotmark><%minus>               */ DEADTRANS( L'-'	,0xF54C	,0x2ADF	,0x0000), // '-' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><%minus><%aprightsingquotmark><~nbspace>             */ DEADTRANS( 0x00A0	,0xF54C	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%aprightsingquotmark><~space>               */ DEADTRANS( L' '	,0xF54C	,0x2A3C	,0x0000), // ' ' ➔ "⨼" INTERIOR PRODUCT
/*<!M><~space><%minus><%bar>                                       */ DEADTRANS( L'|'	,0xF547	,0x21F8	,0x0000), // '|' ➔ "⇸" RIGHTWARDS ARROW WITH VERTICAL STROKE
/*<!M><~space><%minus><%bracketleft>                               */ DEADTRANS( L'['	,0xF547	,0x27E4	,0x0000), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~space><%minus><%bracketright>                              */ DEADTRANS( L']'	,0xF547	,0xF552	,0x0001), // Multikey chain
/*<!M><~space><%minus><%bracketright><%bracketleft>                */ DEADTRANS( L'['	,0xF552	,0x27E4	,0x0000), // '[' ➔ "⟤" WHITE SQUARE WITH LEFTWARDS TICK
/*<!M><~space><%minus><%bracketright><~nbspace>                    */ DEADTRANS( 0x00A0	,0xF552	,0x2ACE	,0x0000), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~space><%minus><%bracketright><~space>                      */ DEADTRANS( L' '	,0xF552	,0x2ACE	,0x0000), // ' ' ➔ "⫎" SQUARE RIGHT OPEN BOX OPERATOR
/*<!M><~space><%minus><%slash>                                     */ DEADTRANS( L'/'	,0xF547	,0x29A2	,0x0000), // '/' ➔ "⦢" TURNED ANGLE
/*<!M><~space><%minus><e>                                          */ DEADTRANS( L'e'	,0xF547	,0x22F2	,0x0000), // 'e' ➔ "⋲" ELEMENT OF WITH LONG HORIZONTAL STROKE
/*<!M><~space><%minus><j>                                          */ DEADTRANS( L'j'	,0xF547	,0x297D	,0x0000), // 'j' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus><J>                                          */ DEADTRANS( L'J'	,0xF547	,0x297D	,0x0000), // 'J' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus><o>                                          */ DEADTRANS( L'o'	,0xF547	,0xF55B	,0x0001), // Multikey chain
/*<!M><~space><%minus><O>                                          */ DEADTRANS( L'O'	,0xF547	,0x29B1	,0x0000), // 'O' ➔ "⦱" EMPTY SET WITH OVERBAR
/*<!M><~space><%minus><o><%minus>                                  */ DEADTRANS( L'-'	,0xF55B	,0x2256	,0x0000), // '-' ➔ "≖" RING IN EQUAL TO
/*<!M><~space><%minus><o><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF55B	,0x22B8	,0x0000), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~space><%minus><o><~space>                                  */ DEADTRANS( L' '	,0xF55B	,0x22B8	,0x0000), // ' ' ➔ "⊸" MULTIMAP
/*<!M><~space><%minus><s>                                          */ DEADTRANS( L's'	,0xF547	,0xF560	,0x0001), // Multikey chain
/*<!M><~space><%minus><S>                                          */ DEADTRANS( L'S'	,0xF547	,0x2A1B	,0x0000), // 'S' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus><s><%slash>                                  */ DEADTRANS( L'/'	,0xF560	,0x299E	,0x0000), // '/' ➔ "⦞" ANGLE WITH S INSIDE
/*<!M><~space><%minus><s><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF560	,0x2A1B	,0x0000), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus><s><~space>                                  */ DEADTRANS( L' '	,0xF560	,0x2A1B	,0x0000), // ' ' ➔ "⨛" INTEGRAL WITH OVERBAR
/*<!M><~space><%minus><Y>                                          */ DEADTRANS( L'Y'	,0xF547	,0x297D	,0x0000), // 'Y' ➔ "⥽" RIGHT FISH TAIL
/*<!M><~space><%minus><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF547	,0x2212	,0x0000), // ' ' ➔ "−" MINUS SIGN
/*<!M><~space><%minus><~space>                                     */ DEADTRANS( L' '	,0xF547	,0x2212	,0x0000), // ' ' ➔ "−" MINUS SIGN
/*<!M><~space><%parenleft>                                         */ DEADTRANS( L'('	,0xF4A1	,0xF567	,0x0001), // Multikey chain
/*<!M><~space><%parenleft><%bracketleft>                           */ DEADTRANS( L'['	,0xF567	,0x27EE	,0x0000), // '[' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~space><%parenleft><%bracketright>                          */ DEADTRANS( L']'	,0xF567	,0x27EE	,0x0000), // ']' ➔ "⟮" MATHEMATICAL LEFT FLATTENED PARENTHESIS
/*<!M><~space><%parenleft><%equal>                                 */ DEADTRANS( L'='	,0xF567	,0x224E	,0x0000), // '=' ➔ "≎" GEOMETRICALLY EQUIVALENT TO
/*<!M><~space><%parenleft><%greater>                               */ DEADTRANS( L'>'	,0xF567	,0x2AA7	,0x0000), // '>' ➔ "⪧" GREATER-THAN CLOSED BY CURVE
/*<!M><~space><%parenleft><%less>                                  */ DEADTRANS( L'<'	,0xF567	,0x2993	,0x0000), // '<' ➔ "⦓" LEFT ARC LESS-THAN BRACKET
/*<!M><~space><%parenleft><%parenleft>                             */ DEADTRANS( L'('	,0xF567	,0x2985	,0x0000), // '(' ➔ "⦅" LEFT WHITE PARENTHESIS
/*<!M><~space><%parenleft><8>                                      */ DEADTRANS( L'8'	,0xF567	,0x29DD	,0x0000), // '8' ➔ "⧝" TIE OVER INFINITY
/*<!M><~space><%parenleft><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF567	,0x2040	,0x0000), // ' ' ➔ "⁀" CHARACTER TIE
/*<!M><~space><%parenleft><~space>                                 */ DEADTRANS( L' '	,0xF567	,0x2040	,0x0000), // ' ' ➔ "⁀" CHARACTER TIE
/*<!M><~space><%parenright>                                        */ DEADTRANS( L')'	,0xF4A1	,0xF571	,0x0001), // Multikey chain
/*<!M><~space><%parenright><%bracketleft>                          */ DEADTRANS( L'['	,0xF571	,0x27EF	,0x0000), // '[' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~space><%parenright><%bracketright>                         */ DEADTRANS( L']'	,0xF571	,0x27EF	,0x0000), // ']' ➔ "⟯" MATHEMATICAL RIGHT FLATTENED PARENTHESIS
/*<!M><~space><%parenright><%greater>                              */ DEADTRANS( L'>'	,0xF571	,0x2994	,0x0000), // '>' ➔ "⦔" RIGHT ARC GREATER-THAN BRACKET
/*<!M><~space><%parenright><%parenright>                           */ DEADTRANS( L')'	,0xF571	,0x2986	,0x0000), // ')' ➔ "⦆" RIGHT WHITE PARENTHESIS
/*<!M><~space><%period>                                            */ DEADTRANS( L'.'	,0xF4A1	,0xF576	,0x0001), // Multikey chain
/*<!M><~space><%period><a>                                         */ DEADTRANS( L'a'	,0xF576	,0x2A51	,0x0000), // 'a' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><A>                                         */ DEADTRANS( L'A'	,0xF576	,0x2A51	,0x0000), // 'A' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><b>                                         */ DEADTRANS( L'b'	,0xF576	,0x2AC4	,0x0000), // 'b' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c>                                         */ DEADTRANS( L'c'	,0xF576	,0xF57A	,0x0001), // Multikey chain
/*<!M><~space><%period><c><%backslash>                             */ DEADTRANS( L'\\'	,0xF57A	,0x2AC4	,0x0000), // '\' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c><%underscore>                            */ DEADTRANS( L'_'	,0xF57A	,0x2AC3	,0x0000), // '_' ➔ "⫃" SUBSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><c><c>                                      */ DEADTRANS( L'c'	,0xF57A	,0x2AC4	,0x0000), // 'c' ➔ "⫄" SUPERSET OF OR EQUAL TO WITH DOT ABOVE
/*<!M><~space><%period><e>                                         */ DEADTRANS( L'e'	,0xF576	,0x22F5	,0x0000), // 'e' ➔ "⋵" ELEMENT OF WITH DOT ABOVE
/*<!M><~space><%period><v>                                         */ DEADTRANS( L'v'	,0xF576	,0xF57F	,0x0001), // Multikey chain
/*<!M><~space><%period><V>                                         */ DEADTRANS( L'V'	,0xF576	,0xF580	,0x0001), // Multikey chain
/*<!M><~space><%period><v><v>                                      */ DEADTRANS( L'v'	,0xF57F	,0x2A51	,0x0000), // 'v' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><V><V>                                      */ DEADTRANS( L'V'	,0xF580	,0x2A51	,0x0000), // 'V' ➔ "⩑" LOGICAL AND WITH DOT ABOVE
/*<!M><~space><%period><v><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF57F	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><V><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF580	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><v><~space>                                 */ DEADTRANS( L' '	,0xF57F	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><V><~space>                                 */ DEADTRANS( L' '	,0xF580	,0x2A52	,0x0000), // ' ' ➔ "⩒" LOGICAL OR WITH DOT ABOVE
/*<!M><~space><%period><x>                                         */ DEADTRANS( L'x'	,0xF576	,0x2A30	,0x0000), // 'x' ➔ "⨰" MULTIPLICATION SIGN WITH DOT ABOVE
/*<!M><~space><%period><~nbspace>                                  */ DEADTRANS( 0x00A0	,0xF576	,0x22C5	,0x0000), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~space><%period><~space>                                    */ DEADTRANS( L' '	,0xF576	,0x22C5	,0x0000), // ' ' ➔ "⋅" DOT OPERATOR
/*<!M><~space><%plus>                                              */ DEADTRANS( L'+'	,0xF4A1	,0xF58A	,0x0001), // Multikey chain
/*<!M><~space><%plus><%apostrophe>                                 */ DEADTRANS( L'\''	,0xF58A	,0x22B9	,0x0000), // ''' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%plus><%aprightsingquotmark>                        */ DEADTRANS( 0x2019	,0xF58A	,0x22B9	,0x0000), // '’' ➔ "⊹" HERMITIAN CONJUGATE MATRIX
/*<!M><~space><%plus><%circum>                                     */ DEADTRANS( L'^'	,0xF58A	,0x2A28	,0x0000), // '^' ➔ "⨨" PLUS SIGN WITH BLACK TRIANGLE
/*<!M><~space><%plus><%plus>                                       */ DEADTRANS( L'+'	,0xF58A	,0x29FA	,0x0000), // '+' ➔ "⧺" DOUBLE PLUS
/*<!M><~space><%plus><2>                                           */ DEADTRANS( L'2'	,0xF58A	,0x2A27	,0x0000), // '2' ➔ "⨧" PLUS SIGN WITH SUBSCRIPT TWO
/*<!M><~space><%semicolon>                                         */ DEADTRANS( L';'	,0xF4A1	,0x2A1F	,0x0000), // ';' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~space><%semsection>                                        */ DEADTRANS( 0x00A7	,0xF4A1	,0x2A1F	,0x0000), // '§' ➔ "⨟" Z NOTATION SCHEMA COMPOSITION
/*<!M><~space><%slash>                                             */ DEADTRANS( L'/'	,0xF4A1	,0xF592	,0x0001), // Multikey chain
/*<!M><~space><%slash><%backslash>                                 */ DEADTRANS( L'\\'	,0xF592	,0xF593	,0x0001), // Multikey chain
/*<!M><~space><%slash><%backslash><%bar>                           */ DEADTRANS( L'|'	,0xF593	,0x2A1E	,0x0000), // '|' ➔ "⨞" LARGE LEFT TRIANGLE OPERATOR
/*<!M><~space><%slash><%backslash><%hash>                          */ DEADTRANS( L'#'	,0xF593	,0x25C0	,0x0000), // '#' ➔ "◀" BLACK LEFT-POINTING TRIANGLE
/*<!M><~space><%slash><%backslash><%underscore>                    */ DEADTRANS( L'_'	,0xF593	,0x29CD	,0x0000), // '_' ➔ "⧍" TRIANGLE WITH SERIFS AT BOTTOM
/*<!M><~space><%slash><%hash>                                      */ DEADTRANS( L'#'	,0xF592	,0xF597	,0x0001), // Multikey chain
/*<!M><~space><%slash><%hash><%underscore>                         */ DEADTRANS( L'_'	,0xF597	,0xF598	,0x0001), // Multikey chain
/*<!M><~space><%slash><%hash><%underscore><%backslash>             */ DEADTRANS( L'\\'	,0xF598	,0x25B4	,0x0000), // '\' ➔ "▴" BLACK UP-POINTING SMALL TRIANGLE
/*<!M><~space><%slash><%slash>                                     */ DEADTRANS( L'/'	,0xF592	,0xF59A	,0x0001), // Multikey chain
/*<!M><~space><%slash><%slash><%slash>                             */ DEADTRANS( L'/'	,0xF59A	,0x2AFB	,0x0000), // '/' ➔ "⫻" TRIPLE SOLIDUS BINARY RELATION
/*<!M><~space><%slash><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF59A	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~space><%slash><%slash><~space>                             */ DEADTRANS( L' '	,0xF59A	,0x2AFD	,0x0000), // ' ' ➔ "⫽" DOUBLE SOLIDUS OPERATOR
/*<!M><~space><%slash><%underscore>                                */ DEADTRANS( L'_'	,0xF592	,0xF59E	,0x0001), // Multikey chain
/*<!M><~space><%slash><%underscore><%backslash>                    */ DEADTRANS( L'\\'	,0xF59E	,0x25B5	,0x0000), // '\' ➔ "▵" WHITE UP-POINTING SMALL TRIANGLE
/*<!M><~space><%slash><c>                                          */ DEADTRANS( L'c'	,0xF592	,0x27C8	,0x0000), // 'c' ➔ "⟈" REVERSE SOLIDUS PRECEDING SUBSET
/*<!M><~space><%slash><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF592	,0x2215	,0x0000), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~space><%slash><~space>                                     */ DEADTRANS( L' '	,0xF592	,0x2215	,0x0000), // ' ' ➔ "∕" DIVISION SLASH
/*<!M><~space><%tilde>                                             */ DEADTRANS( L'~'	,0xF4A1	,0xF5A3	,0x0001), // Multikey chain
/*<!M><~space><%tilde><%colon>                                     */ DEADTRANS( L':'	,0xF5A3	,0x223B	,0x0000), // ':' ➔ "∻" HOMOTHETIC
/*<!M><~space><%tilde><%equal>                                     */ DEADTRANS( L'='	,0xF5A3	,0xF5A5	,0x0001), // Multikey chain
/*<!M><~space><%tilde><%equal><%slash>                             */ DEADTRANS( L'/'	,0xF5A5	,0xF5A6	,0x0001), // Multikey chain
/*<!M><~space><%tilde><%equal><%slash><%slash>                     */ DEADTRANS( L'/'	,0xF5A6	,0x29E4	,0x0000), // '/' ➔ "⧤" EQUALS SIGN AND SLANTED PARALLEL WITH TILDE ABOVE
/*<!M><~space><%tilde><%equal><%slash><~nbspace>                   */ DEADTRANS( 0x00A0	,0xF5A6	,0x2246	,0x0000), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~space><%tilde><%equal><%slash><~space>                     */ DEADTRANS( L' '	,0xF5A6	,0x2246	,0x0000), // ' ' ➔ "≆" APPROXIMATELY BUT NOT ACTUALLY EQUAL TO
/*<!M><~space><%tilde><%equal><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5A5	,0x2245	,0x0000), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~space><%tilde><%equal><~space>                             */ DEADTRANS( L' '	,0xF5A5	,0x2245	,0x0000), // ' ' ➔ "≅" APPROXIMATELY EQUAL TO
/*<!M><~space><%tilde><%greater>                                   */ DEADTRANS( L'>'	,0xF5A3	,0x2A9E	,0x0000), // '>' ➔ "⪞" SIMILAR OR GREATER-THAN
/*<!M><~space><%tilde><%minus>                                     */ DEADTRANS( L'-'	,0xF5A3	,0x2972	,0x0000), // '-' ➔ "⥲" TILDE OPERATOR ABOVE RIGHTWARDS ARROW
/*<!M><~space><%tilde><%percent>                                   */ DEADTRANS( L'%'	,0xF5A3	,0x2240	,0x0000), // '%' ➔ "≀" WREATH PRODUCT
/*<!M><~space><%tilde><%slash>                                     */ DEADTRANS( L'/'	,0xF5A3	,0xF5AF	,0x0001), // Multikey chain
/*<!M><~space><%tilde><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5AF	,0x2241	,0x0000), // ' ' ➔ "≁" NOT TILDE
/*<!M><~space><%tilde><%slash><~space>                             */ DEADTRANS( L' '	,0xF5AF	,0x2241	,0x0000), // ' ' ➔ "≁" NOT TILDE
/*<!M><~space><%tilde><%tilde>                                     */ DEADTRANS( L'~'	,0xF5A3	,0xF5B2	,0x0001), // Multikey chain
/*<!M><~space><%tilde><%tilde><%equal>                             */ DEADTRANS( L'='	,0xF5B2	,0x2A70	,0x0000), // '=' ➔ "⩰" APPROXIMATELY EQUAL OR EQUAL TO
/*<!M><~space><%tilde><%tilde><%tilde>                             */ DEADTRANS( L'~'	,0xF5B2	,0x224B	,0x0000), // '~' ➔ "≋" TRIPLE TILDE
/*<!M><~space><%tilde><%tilde><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5B2	,0x2248	,0x0000), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~space><%tilde><%tilde><~space>                             */ DEADTRANS( L' '	,0xF5B2	,0x2248	,0x0000), // ' ' ➔ "≈" ALMOST EQUAL TO
/*<!M><~space><%tilde><~nbspace>                                   */ DEADTRANS( 0x00A0	,0xF5A3	,0x223C	,0x0000), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~space><%tilde><~space>                                     */ DEADTRANS( L' '	,0xF5A3	,0x223C	,0x0000), // ' ' ➔ "∼" TILDE OPERATOR
/*<!M><~space><%underscore>                                        */ DEADTRANS( L'_'	,0xF4A1	,0xF5B9	,0x0001), // Multikey chain
/*<!M><~space><%underscore><%backslash>                            */ DEADTRANS( L'\\'	,0xF5B9	,0x25BF	,0x0000), // '\' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore><%hash>                                 */ DEADTRANS( L'#'	,0xF5B9	,0x25BE	,0x0000), // '#' ➔ "▾" BLACK DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore><%minus>                                */ DEADTRANS( L'-'	,0xF5B9	,0xF5BC	,0x0001), // Multikey chain
/*<!M><~space><%underscore><%minus><%apostrophe>                   */ DEADTRANS( L'\''	,0xF5BC	,0x296D	,0x0000), // ''' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~space><%underscore><%minus><%aprightsingquotmark>          */ DEADTRANS( 0x2019	,0xF5BC	,0x296D	,0x0000), // '’' ➔ "⥭" RIGHTWARDS HARPOON WITH BARB DOWN BELOW LONG DASH
/*<!M><~space><%underscore><%minus><%slash>                        */ DEADTRANS( L'/'	,0xF5BC	,0x29A4	,0x0000), // '/' ➔ "⦤" ANGLE WITH UNDERBAR
/*<!M><~space><%underscore><%slash>                                */ DEADTRANS( L'/'	,0xF5B9	,0x25BF	,0x0000), // '/' ➔ "▿" WHITE DOWN-POINTING SMALL TRIANGLE
/*<!M><~space><%underscore><%underscore>                           */ DEADTRANS( L'_'	,0xF5B9	,0xF5C1	,0x0001), // Multikey chain
/*<!M><~space><%underscore><%underscore><v>                        */ DEADTRANS( L'v'	,0xF5C1	,0xF5C2	,0x0001), // Multikey chain
/*<!M><~space><%underscore><%underscore><V>                        */ DEADTRANS( L'V'	,0xF5C1	,0xF5C3	,0x0001), // Multikey chain
/*<!M><~space><%underscore><%underscore><v><%percent>              */ DEADTRANS( L'%'	,0xF5C2	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V><%percent>              */ DEADTRANS( L'%'	,0xF5C3	,0x2A5E	,0x0000), // '%' ➔ "⩞" LOGICAL AND WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><v><~nbspace>              */ DEADTRANS( 0x00A0	,0xF5C2	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V><~nbspace>              */ DEADTRANS( 0x00A0	,0xF5C3	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><v><~space>                */ DEADTRANS( L' '	,0xF5C2	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><%underscore><V><~space>                */ DEADTRANS( L' '	,0xF5C3	,0x2A62	,0x0000), // ' ' ➔ "⩢" LOGICAL OR WITH DOUBLE OVERBAR
/*<!M><~space><%underscore><a>                                     */ DEADTRANS( L'a'	,0xF5B9	,0x22BC	,0x0000), // 'a' ➔ "⊼" NAND
/*<!M><~space><%underscore><e>                                     */ DEADTRANS( L'e'	,0xF5B9	,0xF5CB	,0x0001), // Multikey chain
/*<!M><~space><%underscore><e><%backslash>                         */ DEADTRANS( L'\\'	,0xF5CB	,0xF5CC	,0x0001), // Multikey chain
/*<!M><~space><%underscore><e><%backslash><%comma>                 */ DEADTRANS( L','	,0xF5CC	,0x22FE	,0x0000), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e><%backslash><~nbspace>               */ DEADTRANS( 0x00A0	,0xF5CC	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e><%backslash><~space>                 */ DEADTRANS( L' '	,0xF5CC	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><e><%comma>                             */ DEADTRANS( L','	,0xF5CB	,0x22F7	,0x0000), // ',' ➔ "⋷" SMALL ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore><e><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5CB	,0x22F6	,0x0000), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore><e><~space>                             */ DEADTRANS( L' '	,0xF5CB	,0x22F6	,0x0000), // ' ' ➔ "⋶" ELEMENT OF WITH OVERBAR
/*<!M><~space><%underscore><n>                                     */ DEADTRANS( L'n'	,0xF5B9	,0x2A43	,0x0000), // 'n' ➔ "⩃" INTERSECTION WITH OVERBAR
/*<!M><~space><%underscore><p>                                     */ DEADTRANS( L'p'	,0xF5B9	,0xF5D4	,0x0001), // Multikey chain
/*<!M><~space><%underscore><p><%comma>                             */ DEADTRANS( L','	,0xF5D4	,0x22FE	,0x0000), // ',' ➔ "⋾" SMALL CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><p><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5D4	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><p><~space>                             */ DEADTRANS( L' '	,0xF5D4	,0x22FD	,0x0000), // ' ' ➔ "⋽" CONTAINS WITH OVERBAR
/*<!M><~space><%underscore><u>                                     */ DEADTRANS( L'u'	,0xF5B9	,0xF5D8	,0x0001), // Multikey chain
/*<!M><~space><%underscore><u><%hash>                              */ DEADTRANS( L'#'	,0xF5D8	,0x2A50	,0x0000), // '#' ➔ "⩐" CLOSED UNION WITH SERIFS AND SMASH PRODUCT
/*<!M><~space><%underscore><u><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5D8	,0x2A42	,0x0000), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~space><%underscore><u><~space>                             */ DEADTRANS( L' '	,0xF5D8	,0x2A42	,0x0000), // ' ' ➔ "⩂" UNION WITH OVERBAR
/*<!M><~space><%underscore><v>                                     */ DEADTRANS( L'v'	,0xF5B9	,0xF5DC	,0x0001), // Multikey chain
/*<!M><~space><%underscore><v><v>                                  */ DEADTRANS( L'v'	,0xF5DC	,0x22BC	,0x0000), // 'v' ➔ "⊼" NAND
/*<!M><~space><%underscore><v><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5DC	,0x22BD	,0x0000), // ' ' ➔ "⊽" NOR
/*<!M><~space><%underscore><v><~space>                             */ DEADTRANS( L' '	,0xF5DC	,0x22BD	,0x0000), // ' ' ➔ "⊽" NOR
/*<!M><~space><%underscore><X>                                     */ DEADTRANS( L'X'	,0xF5B9	,0xF5E0	,0x0001), // Multikey chain
/*<!M><~space><%underscore><X><%hash>                              */ DEADTRANS( L'#'	,0xF5E0	,0x29D7	,0x0000), // '#' ➔ "⧗" BLACK HOURGLASS
/*<!M><~space><%underscore><X><%underscore>                        */ DEADTRANS( L'_'	,0xF5E0	,0x29D6	,0x0000), // '_' ➔ "⧖" WHITE HOURGLASS
/*<!M><~space><2>                                                  */ DEADTRANS( L'2'	,0xF4A1	,0xF5E3	,0x0001), // Multikey chain
/*<!M><~space><2><%less>                                           */ DEADTRANS( L'<'	,0xF5E3	,0x2AA3	,0x0000), // '<' ➔ "⪣" DOUBLE NESTED LESS-THAN WITH UNDERBAR
/*<!M><~space><2><%minus>                                          */ DEADTRANS( L'-'	,0xF5E3	,0x21C9	,0x0000), // '-' ➔ "⇉" RIGHTWARDS PAIRED ARROWS
/*<!M><~space><3>                                                  */ DEADTRANS( L'3'	,0xF4A1	,0xF5E6	,0x0001), // Multikey chain
/*<!M><~space><3><%bar>                                            */ DEADTRANS( L'|'	,0xF5E6	,0x2AF4	,0x0000), // '|' ➔ "⫴" TRIPLE VERTICAL BAR BINARY RELATION
/*<!M><~space><3><%minus>                                          */ DEADTRANS( L'-'	,0xF5E6	,0x21F6	,0x0000), // '-' ➔ "⇶" THREE RIGHTWARDS ARROWS
/*<!M><~space><8>                                                  */ DEADTRANS( L'8'	,0xF4A1	,0x221D	,0x0000), // '8' ➔ "∝" PROPORTIONAL TO
/*<!M><~space><A>                                                  */ DEADTRANS( L'A'	,0xF4A1	,0xF5EA	,0x0001), // Multikey chain
/*<!M><~space><a>                                                  */ DEADTRANS( L'a'	,0xF4A1	,0xF5EB	,0x0001), // Multikey chain
/*<!M><~space><A><%minus>                                          */ DEADTRANS( L'-'	,0xF5EA	,0x2A3A	,0x0000), // '-' ➔ "⨺" MINUS SIGN IN TRIANGLE
/*<!M><~space><A><%underscore>                                     */ DEADTRANS( L'_'	,0xF5EA	,0xF5ED	,0x0001), // Multikey chain
/*<!M><~space><A><%underscore><%underscore>                        */ DEADTRANS( L'_'	,0xF5ED	,0x2A60	,0x0000), // '_' ➔ "⩠" LOGICAL AND WITH DOUBLE UNDERBAR
/*<!M><~space><A><%underscore><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF5ED	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~space><A><%underscore><~space>                             */ DEADTRANS( L' '	,0xF5ED	,0x2A5F	,0x0000), // ' ' ➔ "⩟" LOGICAL AND WITH UNDERBAR
/*<!M><~space><A><A>                                               */ DEADTRANS( L'A'	,0xF5EA	,0x2A07	,0x0000), // 'A' ➔ "⨇" TWO LOGICAL AND OPERATOR
/*<!M><~space><a><a>                                               */ DEADTRANS( L'a'	,0xF5EB	,0x2A55	,0x0000), // 'a' ➔ "⩕" TWO INTERSECTING LOGICAL AND
/*<!M><~space><A><V>                                               */ DEADTRANS( L'V'	,0xF5EA	,0x25CA	,0x0000), // 'V' ➔ "◊" LOZENGE
/*<!M><~space><a><v>                                               */ DEADTRANS( L'v'	,0xF5EB	,0x25CA	,0x0000), // 'v' ➔ "◊" LOZENGE
/*<!M><~space><A><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xF5EA	,0x22C0	,0x0000), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~space><A><~space>                                          */ DEADTRANS( L' '	,0xF5EA	,0x22C0	,0x0000), // ' ' ➔ "⋀" N-ARY LOGICAL AND
/*<!M><~space><b>                                                  */ DEADTRANS( L'b'	,0xF4A1	,0xF5F7	,0x0001), // Multikey chain
/*<!M><~space><b><%slash>                                          */ DEADTRANS( L'/'	,0xF5F7	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><b><c>                                               */ DEADTRANS( L'c'	,0xF5F7	,0x2AD7	,0x0000), // 'c' ➔ "⫗" SUPERSET BESIDE SUBSET
/*<!M><~space><b><o>                                               */ DEADTRANS( L'o'	,0xF5F7	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><b><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xF5F7	,0x266D	,0x0000), // ' ' ➔ "♭" MUSIC FLAT SIGN
/*<!M><~space><b><~space>                                          */ DEADTRANS( L' '	,0xF5F7	,0x266D	,0x0000), // ' ' ➔ "♭" MUSIC FLAT SIGN
/*<!M><~space><c>                                                  */ DEADTRANS( L'c'	,0xF4A1	,0xF5FD	,0x0001), // Multikey chain
/*<!M><~space><c><%backslash>                                      */ DEADTRANS( L'\\'	,0xF5FD	,0xF5FE	,0x0001), // Multikey chain
/*<!M><~space><c><%backslash><%slash>                              */ DEADTRANS( L'/'	,0xF5FE	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><c><%backslash><o>                                   */ DEADTRANS( L'o'	,0xF5FE	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><c><c>                                               */ DEADTRANS( L'c'	,0xF5FD	,0xF601	,0x0001), // Multikey chain
/*<!M><~space><c><c><%slash>                                       */ DEADTRANS( L'/'	,0xF601	,0x27C9	,0x0000), // '/' ➔ "⟉" SUPERSET PRECEDING SOLIDUS
/*<!M><~space><c><c><o>                                            */ DEADTRANS( L'o'	,0xF601	,0x27C4	,0x0000), // 'o' ➔ "⟄" OPEN SUPERSET
/*<!M><~space><c><c><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xF601	,0x2AD5	,0x0000), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~space><c><c><~space>                                       */ DEADTRANS( L' '	,0xF601	,0x2AD5	,0x0000), // ' ' ➔ "⫕" SUBSET ABOVE SUBSET
/*<!M><~space><c><o>                                               */ DEADTRANS( L'o'	,0xF5FD	,0x27C3	,0x0000), // 'o' ➔ "⟃" OPEN SUBSET
/*<!M><~space><D>                                                  */ DEADTRANS( L'D'	,0xF4A1	,0x2AD0	,0x0000), // 'D' ➔ "⫐" CLOSED SUPERSET
/*<!M><~space><e>                                                  */ DEADTRANS( L'e'	,0xF4A1	,0xF608	,0x0001), // Multikey chain
/*<!M><~space><e><e>                                               */ DEADTRANS( L'e'	,0xF608	,0xF609	,0x0001), // Multikey chain
/*<!M><~space><e><e><%bar>                                         */ DEADTRANS( L'|'	,0xF609	,0xF60A	,0x0001), // Multikey chain
/*<!M><~space><e><e><%bar><%comma>                                 */ DEADTRANS( L','	,0xF60A	,0x22FC	,0x0000), // ',' ➔ "⋼" SMALL CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e><%bar><~nbspace>                               */ DEADTRANS( 0x00A0	,0xF60A	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e><%bar><~space>                                 */ DEADTRANS( L' '	,0xF60A	,0x22FB	,0x0000), // ' ' ➔ "⋻" CONTAINS WITH VERTICAL BAR AT END OF HORIZONTAL STROKE
/*<!M><~space><e><e><%comma>                                       */ DEADTRANS( L','	,0xF609	,0x220D	,0x0000), // ',' ➔ "∍" SMALL CONTAINS AS MEMBER
/*<!M><~space><e><e><%slash>                                       */ DEADTRANS( L'/'	,0xF609	,0x220C	,0x0000), // '/' ➔ "∌" DOES NOT CONTAIN AS MEMBER
/*<!M><~space><e><e><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xF609	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~space><e><e><~space>                                       */ DEADTRANS( L' '	,0xF609	,0x220B	,0x0000), // ' ' ➔ "∋" CONTAINS AS MEMBER
/*<!M><~space><G>                                                  */ DEADTRANS( L'G'	,0xF4A1	,0x27F2	,0x0000), // 'G' ➔ "⟲" ANTICLOCKWISE GAPPED CIRCLE ARROW
/*<!M><~space><h>                                                  */ DEADTRANS( L'h'	,0xF4A1	,0x266E	,0x0000), // 'h' ➔ "♮" MUSIC NATURAL SIGN
/*<!M><~space><I>                                                  */ DEADTRANS( L'I'	,0xF4A1	,0x2AE0	,0x0000), // 'I' ➔ "⫠" SHORT UP TACK
/*<!M><~space><K>                                                  */ DEADTRANS( L'K'	,0xF4A1	,0x212A	,0x0000), // 'K' ➔ "K" KELVIN SIGN
/*<!M><~space><k>                                                  */ DEADTRANS( L'k'	,0xF4A1	,0x212A	,0x0000), // 'k' ➔ "K" KELVIN SIGN
/*<!M><~space><n>                                                  */ DEADTRANS( L'n'	,0xF4A1	,0xF617	,0x0001), // Multikey chain
/*<!M><~space><n><%bar>                                            */ DEADTRANS( L'|'	,0xF617	,0x2ADB	,0x0000), // '|' ➔ "⫛" TRANSVERSAL INTERSECTION
/*<!M><~space><o>                                                  */ DEADTRANS( L'o'	,0xF4A1	,0xF619	,0x0001), // Multikey chain
/*<!M><~space><O>                                                  */ DEADTRANS( L'O'	,0xF4A1	,0xF61A	,0x0001), // Multikey chain
/*<!M><~space><O><%backslash>                                      */ DEADTRANS( L'\\'	,0xF61A	,0x29B0	,0x0000), // '\' ➔ "⦰" REVERSED EMPTY SET
/*<!M><~space><o><%equal>                                          */ DEADTRANS( L'='	,0xF619	,0x229C	,0x0000), // '=' ➔ "⊜" CIRCLED EQUALS
/*<!M><~space><o><%greater>                                        */ DEADTRANS( L'>'	,0xF619	,0x2A7A	,0x0000), // '>' ➔ "⩺" GREATER-THAN WITH CIRCLE INSIDE
/*<!M><~space><o><%minus>                                          */ DEADTRANS( L'-'	,0xF619	,0xF61E	,0x0001), // Multikey chain
/*<!M><~space><o><%minus><%greater>                                */ DEADTRANS( L'>'	,0xF61E	,0x21F4	,0x0000), // '>' ➔ "⇴" RIGHT ARROW WITH SMALL CIRCLE
/*<!M><~space><o><%minus><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF61E	,0x229D	,0x0000), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~space><o><%minus><~space>                                  */ DEADTRANS( L' '	,0xF61E	,0x229D	,0x0000), // ' ' ➔ "⊝" CIRCLED DASH
/*<!M><~space><O><%percent>                                        */ DEADTRANS( L'%'	,0xF61A	,0x29BC	,0x0000), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~space><o><%percent>                                        */ DEADTRANS( L'%'	,0xF619	,0x29BC	,0x0000), // '%' ➔ "⦼" CIRCLED ANTICLOCKWISE-ROTATED DIVISION SIGN
/*<!M><~space><O><%period>                                         */ DEADTRANS( L'.'	,0xF61A	,0x29BF	,0x0000), // '.' ➔ "⦿" CIRCLED BULLET
/*<!M><~space><o><%plus>                                           */ DEADTRANS( L'+'	,0xF619	,0x2640	,0x0000), // '+' ➔ "♀" FEMALE SIGN
/*<!M><~space><o><%semicolon>                                      */ DEADTRANS( L';'	,0xF619	,0x2A3E	,0x0000), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><o><%semsection>                                     */ DEADTRANS( 0x00A7	,0xF619	,0x2A3E	,0x0000), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><o><%slash>                                          */ DEADTRANS( L'/'	,0xF619	,0x2298	,0x0000), // '/' ➔ "⊘" CIRCLED DIVISION SLASH
/*<!M><~space><o><8>                                               */ DEADTRANS( L'8'	,0xF619	,0x2663	,0x0000), // '8' ➔ "♣" BLACK CLUB SUIT
/*<!M><~space><O><o>                                               */ DEADTRANS( L'o'	,0xF61A	,0x29BE	,0x0000), // 'o' ➔ "⦾" CIRCLED WHITE BULLET
/*<!M><~space><R>                                                  */ DEADTRANS( L'R'	,0xF4A1	,0xF62B	,0x0001), // Multikey chain
/*<!M><~space><r>                                                  */ DEADTRANS( L'r'	,0xF4A1	,0xF62C	,0x0001), // Multikey chain
/*<!M><~space><R><%slash>                                          */ DEADTRANS( L'/'	,0xF62B	,0x211E	,0x0000), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~space><r><%slash>                                          */ DEADTRANS( L'/'	,0xF62C	,0x211E	,0x0000), // '/' ➔ "℞" PRESCRIPTION TAKE
/*<!M><~space><S>                                                  */ DEADTRANS( L'S'	,0xF4A1	,0xF630	,0x0001), // Multikey chain
/*<!M><~space><s>                                                  */ DEADTRANS( L's'	,0xF4A1	,0x2A0B	,0x0000), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~space><S><S>                                               */ DEADTRANS( L'S'	,0xF630	,0xF632	,0x0001), // Multikey chain
/*<!M><~space><S><s>                                               */ DEADTRANS( L's'	,0xF630	,0x2A0B	,0x0000), // 's' ➔ "⨋" SUMMATION WITH INTEGRAL
/*<!M><~space><S><S><%at>                                          */ DEADTRANS( L'@'	,0xF632	,0x2140	,0x0000), // '@' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><S><S><~nbspace>                                     */ DEADTRANS( 0x00A0	,0xF632	,0x2140	,0x0000), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><S><S><~space>                                       */ DEADTRANS( L' '	,0xF632	,0x2140	,0x0000), // ' ' ➔ "⅀" DOUBLE-STRUCK N-ARY SUMMATION
/*<!M><~space><T>                                                  */ DEADTRANS( L'T'	,0xF4A1	,0xF636	,0x0001), // Multikey chain
/*<!M><~space><T><%percent>                                        */ DEADTRANS( L'%'	,0xF636	,0x2AE0	,0x0000), // '%' ➔ "⫠" SHORT UP TACK
/*<!M><~space><T><T>                                               */ DEADTRANS( L'T'	,0xF636	,0x2AE0	,0x0000), // 'T' ➔ "⫠" SHORT UP TACK
/*<!M><~space><T><~nbspace>                                        */ DEADTRANS( 0x00A0	,0xF636	,0x2ADF	,0x0000), // ' ' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><T><~space>                                          */ DEADTRANS( L' '	,0xF636	,0x2ADF	,0x0000), // ' ' ➔ "⫟" SHORT DOWN TACK
/*<!M><~space><V>                                                  */ DEADTRANS( L'V'	,0xF4A1	,0xF63C	,0x0001), // Multikey chain
/*<!M><~space><v>                                                  */ DEADTRANS( L'v'	,0xF4A1	,0x2A56	,0x0000), // 'v' ➔ "⩖" TWO INTERSECTING LOGICAL OR
/*<!M><~space><V><V>                                               */ DEADTRANS( L'V'	,0xF63C	,0x2A08	,0x0000), // 'V' ➔ "⨈" TWO LOGICAL OR OPERATOR
/*<!M><~space><x>                                                  */ DEADTRANS( L'x'	,0xF4A1	,0x2A2F	,0x0000), // 'x' ➔ "⨯" VECTOR OR CROSS PRODUCT
/*<!M><~space><Y>                                                  */ DEADTRANS( L'Y'	,0xF4A1	,0xF63F	,0x0001), // Multikey chain
/*<!M><~space><Y><%minus>                                          */ DEADTRANS( L'-'	,0xF63F	,0x297C	,0x0000), // '-' ➔ "⥼" LEFT FISH TAIL
/*<!M><~space><z>                                                  */ DEADTRANS( L'z'	,0xF4A1	,0x2A3E	,0x0000), // 'z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><Z>                                                  */ DEADTRANS( L'Z'	,0xF4A1	,0x2A3E	,0x0000), // 'Z' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><~nbspace>                                           */ DEADTRANS( 0x00A0	,0xF4A1	,0x237D	,0x0000), // ' ' ➔ "⍽" SHOULDERED OPEN BOX
/*<!M><~space><~space>                                             */ DEADTRANS( L' '	,0xF4A1	,0xF644	,0x0001), // Multikey chain
/*<!M><~space><~space><%asterisk>                                  */ DEADTRANS( L'*'	,0xF644	,0x22C6	,0x0000), // '*' ➔ "⋆" STAR OPERATOR
/*<!M><~space><~space><%backslash>                                 */ DEADTRANS( L'\\'	,0xF644	,0xF646	,0x0001), // Multikey chain
/*<!M><~space><~space><%backslash><%slash>                         */ DEADTRANS( L'/'	,0xF646	,0x25C1	,0x0000), // '/' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~space><~space><%backslash><~nbspace>                       */ DEADTRANS( 0x00A0	,0xF646	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~space><~space><%backslash><~space>                         */ DEADTRANS( L' '	,0xF646	,0x29F9	,0x0000), // ' ' ➔ "⧹" BIG REVERSE SOLIDUS
/*<!M><~space><~space><%bar>                                       */ DEADTRANS( L'|'	,0xF644	,0xF64A	,0x0001), // Multikey chain
/*<!M><~space><~space><%bar><%bar>                                 */ DEADTRANS( L'|'	,0xF64A	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~space><~space><%bar><~nbspace>                             */ DEADTRANS( 0x00A0	,0xF64A	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~space><~space><%bar><~space>                               */ DEADTRANS( L' '	,0xF64A	,0x2AFE	,0x0000), // ' ' ➔ "⫾" WHITE VERTICAL BAR
/*<!M><~space><~space><%bracketleft>                               */ DEADTRANS( L'['	,0xF644	,0xF64E	,0x0001), // Multikey chain
/*<!M><~space><~space><%bracketleft><%bracketright>                */ DEADTRANS( L']'	,0xF64E	,0x25FD	,0x0000), // ']' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~space><~space><%bracketleft><%hash>                        */ DEADTRANS( L'#'	,0xF64E	,0x25FE	,0x0000), // '#' ➔ "◾" BLACK MEDIUM SMALL SQUARE
/*<!M><~space><~space><%bracketright>                              */ DEADTRANS( L']'	,0xF644	,0xF651	,0x0001), // Multikey chain
/*<!M><~space><~space><%bracketright><%bracketleft>                */ DEADTRANS( L'['	,0xF651	,0x25FD	,0x0000), // '[' ➔ "◽" WHITE MEDIUM SMALL SQUARE
/*<!M><~space><~space><%colon>                                     */ DEADTRANS( L':'	,0xF644	,0x2982	,0x0000), // ':' ➔ "⦂" Z NOTATION TYPE COLON
/*<!M><~space><~space><%equal>                                     */ DEADTRANS( L'='	,0xF644	,0xF654	,0x0001), // Multikey chain
/*<!M><~space><~space><%equal><%equal>                             */ DEADTRANS( L'='	,0xF654	,0x2263	,0x0000), // '=' ➔ "≣" STRICTLY EQUIVALENT TO
/*<!M><~space><~space><%greater>                                   */ DEADTRANS( L'>'	,0xF644	,0xF656	,0x0001), // Multikey chain
/*<!M><~space><~space><%greater><%less>                            */ DEADTRANS( L'<'	,0xF656	,0x2AA5	,0x0000), // '<' ➔ "⪥" GREATER-THAN BESIDE LESS-THAN
/*<!M><~space><~space><%greater><%minus>                           */ DEADTRANS( L'-'	,0xF656	,0x2B43	,0x0000), // '-' ➔ "⭃" RIGHTWARDS ARROW THROUGH GREATER-THAN
/*<!M><~space><~space><%hash>                                      */ DEADTRANS( L'#'	,0xF644	,0x29E3	,0x0000), // '#' ➔ "⧣" EQUALS SIGN AND SLANTED PARALLEL
/*<!M><~space><~space><%less>                                      */ DEADTRANS( L'<'	,0xF644	,0xF65A	,0x0001), // Multikey chain
/*<!M><~space><~space><%less><%greater>                            */ DEADTRANS( L'>'	,0xF65A	,0x25C7	,0x0000), // '>' ➔ "◇" WHITE DIAMOND
/*<!M><~space><~space><%less><o>                                   */ DEADTRANS( L'o'	,0xF65A	,0x2A79	,0x0000), // 'o' ➔ "⩹" LESS-THAN WITH CIRCLE INSIDE
/*<!M><~space><~space><%minus>                                     */ DEADTRANS( L'-'	,0xF644	,0xF65D	,0x0001), // Multikey chain
/*<!M><~space><~space><%minus><%apostrophe>                        */ DEADTRANS( L'\''	,0xF65D	,0x21C1	,0x0000), // ''' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~space><~space><%minus><%aprightsingquotmark>               */ DEADTRANS( 0x2019	,0xF65D	,0x21C1	,0x0000), // '’' ➔ "⇁" RIGHTWARDS HARPOON WITH BARB DOWNWARDS
/*<!M><~space><~space><%minus><%slash>                             */ DEADTRANS( L'/'	,0xF65D	,0x299F	,0x0000), // '/' ➔ "⦟" ACUTE ANGLE
/*<!M><~space><~space><%period>                                    */ DEADTRANS( L'.'	,0xF644	,0x2219	,0x0000), // '.' ➔ "∙" BULLET OPERATOR
/*<!M><~space><~space><%semicolon>                                 */ DEADTRANS( L';'	,0xF644	,0x2A3E	,0x0000), // ';' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><~space><%semsection>                                */ DEADTRANS( 0x00A7	,0xF644	,0x2A3E	,0x0000), // '§' ➔ "⨾" Z NOTATION RELATIONAL COMPOSITION
/*<!M><~space><~space><%slash>                                     */ DEADTRANS( L'/'	,0xF644	,0xF664	,0x0001), // Multikey chain
/*<!M><~space><~space><%slash><%backslash>                         */ DEADTRANS( L'\\'	,0xF664	,0x25C1	,0x0000), // '\' ➔ "◁" WHITE LEFT-POINTING TRIANGLE
/*<!M><~space><~space><%slash><%minus>                             */ DEADTRANS( L'-'	,0xF664	,0x29A7	,0x0000), // '-' ➔ "⦧" OBLIQUE ANGLE OPENING DOWN
/*<!M><~space><~space><%slash><~nbspace>                           */ DEADTRANS( 0x00A0	,0xF664	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~space><~space><%slash><~space>                             */ DEADTRANS( L' '	,0xF664	,0x29F8	,0x0000), // ' ' ➔ "⧸" BIG SOLIDUS
/*<!M><~space><~space><%underscore>                                */ DEADTRANS( L'_'	,0xF644	,0x2A4C	,0x0000), // '_' ➔ "⩌" CLOSED UNION WITH SERIFS
/*<!M><~space><~space><3>                                          */ DEADTRANS( L'3'	,0xF644	,0xF66A	,0x0001), // Multikey chain
/*<!M><~space><~space><3><%bar>                                    */ DEADTRANS( L'|'	,0xF66A	,0x2AFC	,0x0000), // '|' ➔ "⫼" LARGE TRIPLE VERTICAL BAR OPERATOR
/*<!M><~space><~space><8>                                          */ DEADTRANS( L'8'	,0xF644	,0x29DC	,0x0000), // '8' ➔ "⧜" INCOMPLETE INFINITY
/*<!M><~space><~space><I>                                          */ DEADTRANS( L'I'	,0xF644	,0x27D8	,0x0000), // 'I' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space><o>                                          */ DEADTRANS( L'o'	,0xF644	,0xF66F	,0x0001), // Multikey chain
/*<!M><~space><~space><O>                                          */ DEADTRANS( L'O'	,0xF644	,0x29C2	,0x0000), // 'O' ➔ "⧂" CIRCLE WITH SMALL CIRCLE TO THE RIGHT
/*<!M><~space><~space><o><%minus>                                  */ DEADTRANS( L'-'	,0xF66F	,0x27DC	,0x0000), // '-' ➔ "⟜" LEFT MULTIMAP
/*<!M><~space><~space><o><%plus>                                   */ DEADTRANS( L'+'	,0xF66F	,0x2A22	,0x0000), // '+' ➔ "⨢" PLUS SIGN WITH SMALL CIRCLE ABOVE
/*<!M><~space><~space><T>                                          */ DEADTRANS( L'T'	,0xF644	,0xF672	,0x0001), // Multikey chain
/*<!M><~space><~space><T><%percent>                                */ DEADTRANS( L'%'	,0xF672	,0x27D8	,0x0000), // '%' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space><T><T>                                       */ DEADTRANS( L'T'	,0xF672	,0x27D8	,0x0000), // 'T' ➔ "⟘" LARGE UP TACK
/*<!M><~space><~space><T><~nbspace>                                */ DEADTRANS( 0x00A0	,0xF672	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~space><~space><T><~space>                                  */ DEADTRANS( L' '	,0xF672	,0x27D9	,0x0000), // ' ' ➔ "⟙" LARGE DOWN TACK
/*<!M><~space><~space><~space>                                     */ DEADTRANS( L' '	,0xF644	,0xF677	,0x0001), // Multikey chain
/*<!M><~space><~space><~space><%asterisk>                          */ DEADTRANS( L'*'	,0xF677	,0xF678	,0x0001), // Multikey chain
/*<!M><~space><~space><~space><%asterisk><%hash>                   */ DEADTRANS( L'#'	,0xF678	,0x2605	,0x0000), // '#' ➔ "★" BLACK STAR
/*<!M><~space><~space><~space><%asterisk><~nbspace>                */ DEADTRANS( 0x00A0	,0xF678	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~space><~space><~space><%asterisk><~space>                  */ DEADTRANS( L' '	,0xF678	,0x2606	,0x0000), // ' ' ➔ "☆" WHITE STAR
/*<!M><~space><~space><~space><%backslash>                         */ DEADTRANS( L'\\'	,0xF677	,0x27CD	,0x0000), // '\' ➔ "⟍" MATHEMATICAL FALLING DIAGONAL
/*<!M><~space><~space><~space><%bar>                               */ DEADTRANS( L'|'	,0xF677	,0x2AFF	,0x0000), // '|' ➔ "⫿" N-ARY WHITE VERTICAL BAR
/*<!M><~space><~space><~space><%less>                              */ DEADTRANS( L'<'	,0xF677	,0x2662	,0x0000), // '<' ➔ "♢" WHITE DIAMOND SUIT
/*<!M><~space><~space><~space><%slash>                             */ DEADTRANS( L'/'	,0xF677	,0x27CB	,0x0000), // '/' ➔ "⟋" MATHEMATICAL RISING DIAGONAL
/*<!M><~space><~space><~space><o>                                  */ DEADTRANS( L'o'	,0xF677	,0xDEF0	,0x0000), // High surrogate: D833; U+1CEF0 'o' ➔ "𜻰" MEDIUM SMALL WHITE CIRCLE WITH HORIZONTAL BAR
/*<!M><~space><~space><~space><~space>                             */ DEADTRANS( L' '	,0xF677	,0xF681	,0x0001), // Multikey chain
/*<!M><~space><~space><~space><~space><%backslash>                 */ DEADTRANS( L'\\'	,0xF681	,0x29F5	,0x0000), // '\' ➔ "⧵" REVERSE SOLIDUS OPERATOR
/*<!M><~space><~space><~space><~space><%slash>                     */ DEADTRANS( L'/'	,0xF681	,0x2044	,0x0000), // '/' ➔ "⁄" FRACTION SLASH

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
* Remove separate multikey equivalents     6.2.4.1.0 Tue 2026-03-03T1435+0100
* Update                                   6.2.3.1.0 Mon 2026-02-23T0712+0100
* Update                                   6.2.3.0.0 Sun 2026-02-22T2243+0100
* Update                                   6.2.2.0.0 Sun 2026-02-08T1924+0100
* Update                                   6.2.1.0.0 Sun 2026-02-01T0218+0100
* Update                                   6.2.0.0.0 Mon 2026-01-26T0658+0100
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

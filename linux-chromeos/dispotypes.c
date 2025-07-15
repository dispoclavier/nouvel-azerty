//                       Date: 2025-07-15T0727+0200
//        Operating file name: dispotypes
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//     Syntactic highlighting: C
//                Description: XKB key type definitions
//                   Platform: XKB with XCompose using OSes Linux and ChromeOS*
//
//               Project name: Dispoclavier
//                Project URL: https://dispoclavier.com
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev[arobase]dispoclavier.com
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, Linux is supported alongside ChromeOS, or through ChromeOS.
//
//               Installation: 1. Add this file in /usr/share/X11/xkb/types/dispotypes
//                             2. In /usr/share/X11/xkb/types/complete
//                                add the line
//                                    include "dispotypes"
//                                before the closing brace.
//
//                             The changes take effect when reopening a session.
//
//             Uninstallation: Delete that line, remove the file.
//
//
// ##   Mapping application shortcuts in keyboard layouts
//
// If key types contain mappings for `Control`, the default behavior based on
// graphics mapped on Base level and Shift level can be overridden.
//
// Mappings including Control are added for completeness on some keys, while
// technically not mandatory for unremapped alphabetic types in the Latin
// base alphabet.
//
// Shortcuts should be defined by the index of Base level only.
// But on alphabetic keys they do also work with uppercase, that
// in some applications is mandatory for Control + Shift shortcuts.
// LibreOffice does not recognize punctuation and symbols on Shift level
// for keyboard shortcuts, even if mapped according to US-QWERTY.
//
// Breaking down by Shift and all enabled toggles is mandatory.
// Control mappings need to be preserved because else, shortcuts
// would be output as graphics.
// Shift needs to be preserved for further processing shortcuts.
//
//
// ## Shift cancels Lock
//
// Except on key C11, this layout features 'Shift cancels Lock'.
// Hence Lock is not preserved, given preserving Lock would enable
// internal capitalization overriding layout definitions when
// input is postprocessed. Hence this code is used only on C11:
//
//  preserve[             Lock                                            ] = Lock;
//  preserve[             Lock                                    + Shift ] = Lock;
//  preserve[             Lock                       + LevelThree         ] = Lock;
//  preserve[             Lock                       + LevelThree + Shift ] = Lock;
//  preserve[             Lock           + LevelFive                      ] = Lock;
//  preserve[             Lock           + LevelFive              + Shift ] = Lock;
//  preserve[             Lock           + LevelFive + LevelThree         ] = Lock;
//  preserve[             Lock           + LevelFive + LevelThree + Shift ] = Lock;
//
//
// ## Examples
//
// <NBTSP> is the no-break thin space U202F NARROW NO-BREAK SPACE.
// See dispocla.cpp ## French-style punctuation spacing
// See Compose.yml ### Multicharacter strings for live keys
//
// Dead keys are noted with a dead character in pointy brackets.
//

default partial xkb_types "dispocla" {

	virtual_modifiers LevelThree, LevelFive;

	type "EIGHT_LEVELS_BASIC" {
		// Used on the numpad, TLDE (ModLock), RALT.
		// Based on "EIGHT_LEVEL" in xkb/types/level5:8.
		// This type is required for the sake of level names, where "X" is "AltFr".

		modifiers =                            LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1;
		map[                                                            Shift ] = Level2;
		map[                                               LevelThree         ] = Level3;
		map[                                               LevelThree + Shift ] = Level4;
		map[                                   LevelFive                      ] = Level5;
		map[                                   LevelFive              + Shift ] = Level6;
		map[                                   LevelFive + LevelThree         ] = Level7;
		map[                                   LevelFive + LevelThree + Shift ] = Level8;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_LEVEL1_CONTROL" {
		// Used on AB07, AB08 and SPCE.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // ,
		map[                                                            Shift ] = Level2; // <NBTSP>?
		map[                                               LevelThree         ] = Level3; // ?
		map[                                               LevelThree + Shift ] = Level5; // <ç>
		map[                                   LevelFive                      ] = Level4; // ?
		map[                                   LevelFive              + Shift ] = Level6; // ?
		map[                                   LevelFive + LevelThree         ] = Level7; // 😒
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 💙
		map[                         Control                                  ] = Level1; // ,
		map[                         Control                          + Shift ] = Level1; // ,
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_LEVEL8_CONTROL" {
		// Used on AD11, AD12, BKSL (AC12) and AC11 (pro parte).
		// Based on EIGHT_LEVELS_LEVEL1_CONTROL.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;           // group1
		map[ None                                                             ] = Level1; // <①>
		map[                                                            Shift ] = Level2; // <NBTSP>»
		map[                                               LevelThree         ] = Level3; // <①>
		map[                                               LevelThree + Shift ] = Level5; // *
		map[                                   LevelFive                      ] = Level4; // »
		map[                                   LevelFive              + Shift ] = Level6; // µ
		map[                                   LevelFive + LevelThree         ] = Level7; // B
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // ;
		map[                         Control                                  ] = Level8; // ;
		map[                         Control                          + Shift ] = Level8; // ;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL" {
		// Used on AC11.
		// A casing letter on level 1, if any, is passed on to internal capitalization.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;           // group1
		map[ None                                                             ] = Level1; // ù
		map[                                                            Shift ] = Level2; // «<NBTSP>
		map[                                               LevelThree         ] = Level3; // …
		map[                                               LevelThree + Shift ] = Level5; // %
		map[                                   LevelFive                      ] = Level4; // «
		map[                                   LevelFive              + Shift ] = Level6; // %
		map[                                   LevelFive + LevelThree         ] = Level7; // A
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // '
		map[                         Control                                  ] = Level8; // '
		map[                         Control                          + Shift ] = Level8; // '
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                            ] = Lock;
		preserve[             Lock                                    + Shift ] = Lock;
		preserve[             Lock                       + LevelThree         ] = Lock;
		preserve[             Lock                       + LevelThree + Shift ] = Lock;
		preserve[             Lock           + LevelFive                      ] = Lock;
		preserve[             Lock           + LevelFive              + Shift ] = Lock;
		preserve[             Lock           + LevelFive + LevelThree         ] = Lock;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Lock;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "AltFr";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_FIRSTALPHABETIC" {
		// Based on EIGHT_LEVEL_SEMIALPHABETIC.
		// All variants use this on keys D02..D10, C01..C10, B01..B05.
		// CapsLock affects indices 1..2.
		// Group 2 is identical to group 1 for cross platform compatibility.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // b
		map[                                                            Shift ] = Level2; // B
		map[                                               LevelThree         ] = Level3; // =
		map[                                               LevelThree + Shift ] = Level5; // <⚐>
		map[                                   LevelFive                      ] = Level4; // 00
		map[                                   LevelFive              + Shift ] = Level6; // ᵇ
		map[                                   LevelFive + LevelThree         ] = Level7; // 😘
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 💕
		map[                  Lock                                            ] = Level2; // B
		map[                  Lock                                    + Shift ] = Level1; // b
		map[                  Lock                       + LevelThree         ] = Level3; // =
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <⚐>
		map[                  Lock           + LevelFive                      ] = Level4; // 00
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ᵇ
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 😘
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 💕
		map[                         Control                                  ] = Level1; // b
		map[                         Control                          + Shift ] = Level2; // B
		map[                  Lock + Control                                  ] = Level1; // b
		map[                  Lock + Control                          + Shift ] = Level2; // B
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AB06.
		// This key type is not cross platform compatible.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // n
		map[                                                            Shift ] = Level2; // N
		map[                                               LevelThree         ] = Level3; // `
		map[                                               LevelThree + Shift ] = Level5; // <ò>
		map[                                   LevelFive                      ] = Level4; // 0
		map[                                   LevelFive              + Shift ] = Level6; // ⁿ
		map[                                   LevelFive + LevelThree         ] = Level7; // <nᵒ >
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // <Nᵒ >
		map[                  Lock                                            ] = Level2; // N
		map[                  Lock                                    + Shift ] = Level1; // n
		map[                  Lock                       + LevelThree         ] = Level3; // `
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <ò>
		map[                  Lock           + LevelFive                      ] = Level4; // 0
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ⁿ
		map[                  Lock           + LevelFive + LevelThree         ] = Level8; // <Nᵒ >
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // <nᵒ >
		map[                         Control                                  ] = Level1; // n
		map[                         Control                          + Shift ] = Level2; // N
		map[                  Lock + Control                                  ] = Level1; // n
		map[                  Lock + Control                          + Shift ] = Level2; // N
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr (majuscules verrouillées)";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AD01 with respect to the Breton trigraph.
		// This key type is not cross platform compatible.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // a
		map[                                                            Shift ] = Level2; // A
		map[                                               LevelThree         ] = Level3; // ^
		map[                                               LevelThree + Shift ] = Level5; // <^>
		map[                                   LevelFive                      ] = Level3; // ^
		map[                                   LevelFive              + Shift ] = Level6; // ᵃ
		map[                                   LevelFive + LevelThree         ] = Level4; // cʼh
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // Cʼh
		map[                  Lock                                            ] = Level2; // A
		map[                  Lock                                    + Shift ] = Level1; // a
		map[                  Lock                       + LevelThree         ] = Level3; // ^
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <^>
		map[                  Lock           + LevelFive                      ] = Level3; // ^
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ᵃ
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // CʼH
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level4; // cʼh
		map[                         Control                                  ] = Level1; // a
		map[                         Control                          + Shift ] = Level2; // A
		map[                  Lock + Control                                  ] = Level1; // a
		map[                  Lock + Control                          + Shift ] = Level2; // A
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr (majuscules verrouillées)";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_LEVEL3_CONTROL" {
		// Used on non-alphabetic digit keys except AE01.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;           // g1 // g2
		map[ None                                                             ] = Level1; // "  // 3
		map[                                                            Shift ] = Level2; // –  // 3
		map[                                               LevelThree         ] = Level3; // 3  // 3
		map[                                               LevelThree + Shift ] = Level4; // #  // ₃
		map[                                   LevelFive                      ] = Level5; // 3  // 3
		map[                                   LevelFive              + Shift ] = Level6; // ³  // ³
		map[                                   LevelFive + LevelThree         ] = Level7; // 3️⃣  // ₃
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 3️⃣  // 3️⃣
		map[                         Control                                  ] = Level3; // 3  // 3
		map[                         Control                          + Shift ] = Level3; // 3  // 3
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_SUPERSCRIPT_SUBSCRIPT_LEVEL3_CONTROL" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used in French mode on AE01.
		// See dispocla.cpp ## Keysyms: maximum number

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // ²
		map[                                                            Shift ] = Level2; // ³
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level5; // ¹
		map[                                   LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level6; // ₂
		map[                  Lock                                    + Shift ] = Level7; // ₃
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on alphabetic digit keys except AE10.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;           // g1  // g2
		map[ None                                                             ] = Level1; // é   // 2
		map[                                                            Shift ] = Level2; // É   // 2
		map[                                               LevelThree         ] = Level3; // 2   // 2
		map[                                               LevelThree + Shift ] = Level4; // <~> // ²
		map[                                   LevelFive                      ] = Level5; // 2   // 2
		map[                                   LevelFive              + Shift ] = Level6; // ²   // ²
		map[                                   LevelFive + LevelThree         ] = Level7; // 2️⃣  // ₂
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 2️⃣  // 2️⃣
		map[                  Lock                                            ] = Level2; // É   // 2
		map[                  Lock                                    + Shift ] = Level1; // é   // 2
		map[                  Lock                       + LevelThree         ] = Level3; // 2   // 2
		map[                  Lock                       + LevelThree + Shift ] = Level4; // <~> // ²
		map[                  Lock           + LevelFive                      ] = Level5; // 2   // 2
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ²   // ²
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 2️⃣   // ₂
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 2️⃣   // 2️⃣
		map[                         Control                                  ] = Level3; // 2   // 2
		map[                         Control                          + Shift ] = Level3; // 2   // 2
		map[                  Lock + Control                                  ] = Level3; // 2   // 2
		map[                  Lock + Control                          + Shift ] = Level3; // 2   // 2
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_AE01_FIRSTALPHABETIC_LEVEL3_CONTROL" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on AE01 of Francophone African variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // ɛ
		map[                                                            Shift ] = Level2; // Ɛ
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level5; // ¹
		map[                                   LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level2; // Ɛ
		map[                  Lock                                    + Shift ] = Level1; // ɛ
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_FIRSTALPHABETIC_TITLECASE_LEVEL3_CONTROL" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AE01 of Breton variants.
		// Supports Breton with an extra uppercase string on index 6.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // cʼh
		map[                                                            Shift ] = Level2; // Cʼh
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level5; // ¹
		map[                                   LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level6; // CʼH
		map[                  Lock                                    + Shift ] = Level1; // cʼh
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree         ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_CAPITAL_LEVEL3_CONTROL" {
		// Used on AE06 (pro parte).
		// A casing letter on level 1, if any, is passed on to internal capitalization.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;           // g1 // g2
		map[ None                                                             ] = Level1; // ù  // 6
		map[                                                            Shift ] = Level2; // ‑  // 6
		map[                                               LevelThree         ] = Level3; // 6  // 6
		map[                                               LevelThree + Shift ] = Level4; // |  // ⁶
		map[                                   LevelFive                      ] = Level5; // 6  // 6
		map[                                   LevelFive              + Shift ] = Level6; // ⁶  // ⁶
		map[                                   LevelFive + LevelThree         ] = Level7; // 6️⃣  // ₆
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 6️⃣  // 6️⃣
		map[                         Control                                  ] = Level3; // 6  // 6
		map[                         Control                          + Shift ] = Level3; // 6  // 6
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                            ] = Lock;
		preserve[             Lock                                    + Shift ] = Lock;
		preserve[             Lock                       + LevelThree         ] = Lock;
		preserve[             Lock                       + LevelThree + Shift ] = Lock;
		preserve[             Lock           + LevelFive                      ] = Lock;
		preserve[             Lock           + LevelFive              + Shift ] = Lock;
		preserve[             Lock           + LevelFive + LevelThree         ] = Lock;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Lock;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_AE10_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on Canadian variants.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level1; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule";

	};

	type "EIGHT_LEVELS_AE10_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on Canadian variants.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level8; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level1; // 
		map[                                   LevelFive                      ] = Level1; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level3; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_MINUS_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL8_CONTROL.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level3; // ᵉ
		map[                                               LevelThree + Shift ] = Level4; // ]
		map[                                   LevelFive                      ] = Level2; // °
		map[                                   LevelFive              + Shift ] = Level5; // ⁻
		map[                                   LevelFive + LevelThree         ] = Level6; // E
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // *️⃣
		map[                         Control                                  ] = Level8; // -
		map[                         Control                          + Shift ] = Level8; // -
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Base (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_MINUS_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL8_CONTROL.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level3; // -
		map[                                               LevelThree + Shift ] = Level4; // ₋
		map[                                   LevelFive                      ] = Level5; // E
		map[                                   LevelFive              + Shift ] = Level6; // ⁻
		map[                                   LevelFive + LevelThree         ] = Level4; // ₋
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // *️⃣
		map[                         Control                                  ] = Level8; // -
		map[                         Control                          + Shift ] = Level8; // -
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Base (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_MINUS_CH_GROUP1" {
		// Based on EIGHT_LEVELS_MINUS_GROUP1.
		// Used on Swiss variants.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level2; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "aucun";

	};

	type "EIGHT_LEVELS_MINUS_CH_GROUP2" {
		// Based on EIGHT_LEVELS_MINUS_GROUP1.
		// Used on Swiss variants.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level4; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level7; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level2; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "aucun";

	};

	type "EIGHT_LEVELS_PLUS_GROUP1" {
		// Based on EIGHT_LEVELS_MINUS_GROUP1.
		// The Control value <equal> is based on the US-QWERTY base level,
		// expected to be supported by most applications, as opposed to <plus>.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // '
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level3; // <¦>
		map[                                               LevelThree + Shift ] = Level4; // }
		map[                                   LevelFive                      ] = Level5; // =
		map[                                   LevelFive              + Shift ] = Level6; // ⁺
		map[                                   LevelFive + LevelThree         ] = Level7; // F
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // #️⃣
		map[                         Control                                  ] = Level5; // =
		map[                         Control                          + Shift ] = Level5; // =
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "(aucun)";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PLUS_GROUP2" {
		// Based on EIGHT_LEVELS_MINUS_GROUP1.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // =
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level3; // <¦>
		map[                                               LevelThree + Shift ] = Level4; // ₊
		map[                                   LevelFive                      ] = Level5; // F
		map[                                   LevelFive              + Shift ] = Level6; // ⁺
		map[                                   LevelFive + LevelThree         ] = Level4; // ₊
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // #️⃣
		map[                         Control                                  ] = Level8; // =
		map[                         Control                          + Shift ] = Level8; // =
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltFr";
		level_name[ Level5 ] = "Majuscule + AltGr";
		level_name[ Level6 ] = "AltFr";
		level_name[ Level7 ] = "(aucun)";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_PLUS.
		// Used on Swiss variant.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level3; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level4; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level7; // 
		map[                         Control                          + Shift ] = Level8; // 
		map[                  Lock + Control                                  ] = Level7; // 
		map[                  Lock + Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "(aucun)";

	};

	type "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_PLUS.
		// Used on Swiss variant.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level7; // 
		map[                                                            Shift ] = Level8; // 
		map[                                               LevelThree         ] = Level2; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                  Lock                                            ] = Level7; // 
		map[                  Lock                                    + Shift ] = Level8; // 
		map[                  Lock                       + LevelThree         ] = Level2; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level4; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level7; // 
		map[                         Control                          + Shift ] = Level8; // 
		map[                  Lock + Control                                  ] = Level7; // 
		map[                  Lock + Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_PUNCTUATION_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL1_CONTROL.
		// Used on AB09 and AB10.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // /
		map[                                                            Shift ] = Level2; // <NBTSP>:
		map[                                               LevelThree         ] = Level3; // :
		map[                                               LevelThree + Shift ] = Level5; // <ë>
		map[                                   LevelFive                      ] = Level4; // :
		map[                                   LevelFive              + Shift ] = Level4; // :
		map[                                   LevelFive + LevelThree         ] = Level6; // ⁄
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 😃
		map[                         Control                                  ] = Level8; // /
		map[                         Control                          + Shift ] = Level8; // /
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "AltFr";
		level_name[ Level3 ] = "Majuscule";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Contrôle";

	};

	type "EIGHT_LEVELS_PUNCTUATION_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL1_CONTROL.
		// Used on AB09 and AB10.
		// On 7 graphic indices and 1 control index, group 2 cannot be merged with
		// group 1.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // :
		map[                                                            Shift ] = Level2; // /
		map[                                               LevelThree         ] = Level3; // :
		map[                                               LevelThree + Shift ] = Level5; // <ë>
		map[                                   LevelFive                      ] = Level4; // :
		map[                                   LevelFive              + Shift ] = Level6; // ⁄
		map[                                   LevelFive + LevelThree         ] = Level6; // ⁄
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 😕
		map[                         Control                                  ] = Level8; // /
		map[                         Control                          + Shift ] = Level8; // /
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "AltFr";
		level_name[ Level3 ] = "Majuscule";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Contrôle";

	};

	type "EIGHT_LEVELS_PUNCTUATION_CA_GROUP1" {
		// Based on EIGHT_LEVELS_PUNCTUATION_THREE.
		// Used on Canadian French on AC10.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level5; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PUNCTUATION_CA_GROUP2" {
		// Based on EIGHT_LEVELS_PUNCTUATION_THREE.
		// Used on Canadian French on AC10.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level8; // 
		map[                                                            Shift ] = Level7; // 
		map[                                               LevelThree         ] = Level7; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level5; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on Canadian variants on AB10.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level5; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level6; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level3; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level5; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
		map[                  Lock + Control                                  ] = Level8; // 
		map[                  Lock + Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on Canadian variants on AB10.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level8; // 
		map[                                                            Shift ] = Level7; // 
		map[                                               LevelThree         ] = Level6; // 
		map[                                               LevelThree + Shift ] = Level5; // 
		map[                                   LevelFive                      ] = Level5; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level6; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level8; // 
		map[                  Lock                                    + Shift ] = Level7; // 
		map[                  Lock                       + LevelThree         ] = Level6; // 
		map[                  Lock                       + LevelThree + Shift ] = Level5; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level5; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
		map[                  Lock + Control                                  ] = Level8; // 
		map[                  Lock + Control                          + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_NUMPAD_SEPARATOR" {
		// CapsLock affects levels 1 and 2 for toggling dot and comma.

		modifiers =           Lock           + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level5; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level3; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

};

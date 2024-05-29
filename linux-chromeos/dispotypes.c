//                       Date: 2024-05-30T0123+0200
//        Operating file name: dispotypes
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: XKB key type definitions
//                   Platform: XKB with XCompose using OSes Linux and ChromeOS*
//
//               Project name: Dispoclavier
//                Project URL: https://dispoclavier.com
//                      Maxim: Simplify typewriting, not French.
//                    Maxime : Simplifier la dactylographie, pas le français.
//        English description: Keyboard layouts fit for national, regional and neighbor languages of Francophonie.
//     Description française : Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.
//              Target public: General public and developers, journalists, scientists, secretaries, translators, typographers and writers
//             Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev@dispoclavier.net
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, *Linux* is supported alongside *ChromeOS*, or through ChromeOS.
//
//               Installation: 1. Add this file in /usr/share/X11/xkb/types/dispotypes
//                             2. In /usr/share/X11/xkb/types/complete
//                                add the line
//                                    include "dispotypes"
//                                before the closing brace.
//
//                             The change takes effect when reopening a session.
//
//             Uninstallation: Delete that line, remove the file.
//
//
// ##   Mapping application shortcuts in keyboard layouts
//
// If key types contain mappings for Control, the default behavior based on
// graphics mapped on Base level and Shift level can be overridden.
//
// Mappings including Control are added for completeness on some keys,
// while technically not mandatory for unremapped alphabetic types in
// the Latin base alphabet.
//
// Shortcuts should be defined by the index of Base level only.
// But on alphabetic keys they do also wprk with uppercase, that
// in some applications is mandatory for Control + Shift shortcuts.
// LibreOffice does not recognize punctuation and symbols on Shift level
// for keyboard shortcuts, even if mapped according to US-QWERTY.
//
// Breaking down by Shift and all enabled toggles is mandatory.
// Control mappings need to be preserved because else, shortcuts
// would be output as graphics.
// Shift needs to be preserved for further processing shortcuts.
//
// For Nautilus, shortcut problems can be fixed by editing a
// configuration file located at `~/.config/nautilus/accels`.
// Video tutorial: https://www.youtube.com/watch?v=2Birudyo3fs
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

default partial xkb_types "dispocla" {

	virtual_modifiers LevelThree, LevelFive;

	// The following types are found in /usr/share/X11/xkb/types/level5
	// on Ubuntu 16.04 LTS.

	// type "EIGHT_LEVEL" {...} see in xkb/types/level5(8).
		// Does not force effect of Caps Lock on any index pair.
		// Relies on internal capitalization rules.

	// type "EIGHT_LEVEL_ALPHABETIC" {...} see in xkb/types/level5(28).
		// CapsLock affects indices 1-2, 3-4, 5-6 and 7-8.

	// type "EIGHT_LEVEL_SEMIALPHABETIC" {...} see in xkb/types/level5(178).
		// CapsLock affects indices 1..2 and 5..6.
		// This type does not feature "Shift cancels Lock" on levels 5..6. and
		// hence does not match the specifications used in symbols/dispocla.

		// These types are commented out in the original file as of Ubuntu 16.04:
	// type "EIGHT_LEVEL_LEVEL_FIVE_LOCK" {...} see in xkb/types/level5(56).
	// type "EIGHT_LEVEL_ALPHABETIC_LEVEL_FIVE_LOCK" {...} see in xkb/types/level5(118).

	type "EIGHT_LEVELS_LEVEL1_CONTROL" {
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1;
		map[                                                            Shift ] = Level2;
		map[                                               LevelThree         ] = Level3;
		map[                                               LevelThree + Shift ] = Level5;
		map[                                   LevelFive                      ] = Level4;
		map[                                   LevelFive              + Shift ] = Level6;
		map[                                   LevelFive + LevelThree         ] = Level7;
		map[                                   LevelFive + LevelThree + Shift ] = Level8;
		map[                         Control                                  ] = Level1;
		map[                         Control                          + Shift ] = Level1;
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
		// Based on EIGHT_LEVELS_LEVEL1_CONTROL.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1; // <①>
		map[                                                            Shift ] = Level2; // »
		map[                                               LevelThree         ] = Level3; // <①>
		map[                                               LevelThree + Shift ] = Level5; // *
		map[                                   LevelFive                      ] = Level4; // < »>
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
		// A casing letter on level 1, if any, is passed on to internal capitalization.
		// Index 4 (Level4) is level 5 (LevelFive) for the sake of keyboard views,
		// where most alphabetic keys show the level 5 character in the traditional
		// level 4 position.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // ù
		map[                                                            Shift ] = Level2; // «
		map[                                               LevelThree         ] = Level3; // …
		map[                                               LevelThree + Shift ] = Level5; // %
		map[                                   LevelFive                      ] = Level4; // <« > 
		map[                                   LevelFive              + Shift ] = Level6; // %
		map[                                   LevelFive + LevelThree         ] = Level7; // A
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // '
		map[                         Control                                  ] = Level8; // '
		map[                         Control                          + Shift ] = Level8; // '
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
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

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // b
		map[                                                            Shift ] = Level2; // B
		map[                                               LevelThree         ] = Level3; // =
		map[                                               LevelThree + Shift ] = Level5; // <⚐>
		map[                                   LevelFive                      ] = Level4; // 00
		map[                                   LevelFive              + Shift ] = Level7; // 😘
		map[                                   LevelFive + LevelThree         ] = Level6; // ᵇ
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 💕
		map[                  Lock                                            ] = Level2; // B
		map[                  Lock                                    + Shift ] = Level1; // b
		map[                  Lock                       + LevelThree         ] = Level3; // =
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <⚐>
		map[                  Lock           + LevelFive                      ] = Level4; // 00
		map[                  Lock           + LevelFive              + Shift ] = Level7; // 😘
		map[                  Lock           + LevelFive + LevelThree         ] = Level6; // ᵇ
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 💕
		map[                         Control                                  ] = Level1; // b
		map[                         Control                          + Shift ] = Level2; // B
		map[                  Lock + Control                                  ] = Level1; // b
		map[                  Lock + Control                          + Shift ] = Level2; // B
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // n
		map[                                                            Shift ] = Level2; // N
		map[                                               LevelThree         ] = Level3; // `
		map[                                               LevelThree + Shift ] = Level5; // <ò>
		map[                                   LevelFive                      ] = Level4; // 0
		map[                                   LevelFive              + Shift ] = Level7; // <nᵒ >
		map[                                   LevelFive + LevelThree         ] = Level6; // ⁿ
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // <Nᵒ >
		map[                  Lock                                            ] = Level2; // N
		map[                  Lock                                    + Shift ] = Level1; // n
		map[                  Lock                       + LevelThree         ] = Level3; // `
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <ò>
		map[                  Lock           + LevelFive                      ] = Level4; // 0
		map[                  Lock           + LevelFive              + Shift ] = Level8; // <Nᵒ >
		map[                  Lock           + LevelFive + LevelThree         ] = Level6; // ⁿ
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // <nᵒ >
		map[                         Control                                  ] = Level1; // n
		map[                         Control                          + Shift ] = Level2; // N
		map[                  Lock + Control                                  ] = Level1; // n
		map[                  Lock + Control                          + Shift ] = Level2; // N
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

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
		// Used on AD02.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // a
		map[                                                            Shift ] = Level2; // A
		map[                                               LevelThree         ] = Level3; // ^
		map[                                               LevelThree + Shift ] = Level5; // <^>
		map[                                   LevelFive                      ] = Level3; // ^
		map[                                   LevelFive              + Shift ] = Level4; // cʼh
		map[                                   LevelFive + LevelThree         ] = Level6; // ᵃ
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // Cʼh
		map[                  Lock                                            ] = Level2; // A
		map[                  Lock                                    + Shift ] = Level1; // a
		map[                  Lock                       + LevelThree         ] = Level3; // ^
		map[                  Lock                       + LevelThree + Shift ] = Level5; // <^>
		map[                  Lock           + LevelFive                      ] = Level3; // ^
		map[                  Lock           + LevelFive              + Shift ] = Level7; // CʼH
		map[                  Lock           + LevelFive + LevelThree         ] = Level6; // ᵃ
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level4; // cʼh
		map[                         Control                                  ] = Level1; // a
		map[                         Control                          + Shift ] = Level2; // A
		map[                  Lock + Control                                  ] = Level1; // a
		map[                  Lock + Control                          + Shift ] = Level2; // A
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;  //      group1 // group2
		map[ None                                                             ] = Level1; // " // 3
		map[                                                            Shift ] = Level2; // – // 3
		map[                                               LevelThree         ] = Level3; // 3 // 3
		map[                                               LevelThree + Shift ] = Level4; // # // ³
		map[                                   LevelFive                      ] = Level5; // 3 // 3
		map[                                   LevelFive              + Shift ] = Level6; // 3️⃣ // ₃
		map[                                   LevelFive + LevelThree         ] = Level7; // ³ // ³
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 3️⃣ // 3️⃣
		map[                         Control                                  ] = Level3; // 3 // 3
		map[                         Control                          + Shift ] = Level3; // 3 // 3
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
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

	type "EIGHT_LEVELS_SUPERSCRIPT_SUBSCRIPT" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AE01.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // ²
		map[                                                            Shift ] = Level2; // ³
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level6; // ₂
		map[                  Lock                                    + Shift ] = Level7; // ₃
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;  //        group1 // group2
		map[ None                                                             ] = Level1; // é   // 2
		map[                                                            Shift ] = Level2; // É   // 2
		map[                                               LevelThree         ] = Level3; // 2   // 2
		map[                                               LevelThree + Shift ] = Level4; // <~> // ²
		map[                                   LevelFive                      ] = Level5; // 2   // 2
		map[                                   LevelFive              + Shift ] = Level6; // 2️⃣  // ₂
		map[                                   LevelFive + LevelThree         ] = Level7; // ²   // ²
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 2️⃣  // 2️⃣
		map[                  Lock                                            ] = Level2; // É   // 2
		map[                  Lock                                    + Shift ] = Level1; // é   // 2
		map[                  Lock                       + LevelThree         ] = Level3; // 2   // 2
		map[                  Lock                       + LevelThree + Shift ] = Level4; // <~> // ²
		map[                  Lock           + LevelFive                      ] = Level5; // 2   // 2
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 2️⃣   // ₂
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // ²   // ²
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 2️⃣   // 2️⃣
		map[                         Control                                  ] = Level3; // 2   // 2
		map[                         Control                          + Shift ] = Level3; // 2   // 2
		map[                  Lock + Control                                  ] = Level3; // 2   // 2
		map[                  Lock + Control                          + Shift ] = Level3; // 2   // 2
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_SUPERSUB_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on AE01 of Francophone African variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // ɛ
		map[                                                            Shift ] = Level2; // Ɛ
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level2; // Ɛ
		map[                  Lock                                    + Shift ] = Level1; // ɛ
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_SUPERSUB_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on AE01 of Francophone African variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level3; // 1
		map[                                                            Shift ] = Level3; // 1
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level5; // ¹
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level6; // ₁
		map[                                   LevelFive + LevelThree         ] = Level5; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level3; // 1
		map[                  Lock                                    + Shift ] = Level3; // 1
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level5; // ¹
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ₁
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP1" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AE01 of Breton variants.
		// Supports Breton with an extra uppercase string on index 6.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // cʼh
		map[                                                            Shift ] = Level2; // Cʼh
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level4; // &
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level8; // 1️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level6; // CʼH
		map[                  Lock                                    + Shift ] = Level1; // cʼh
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // &
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP2" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AE01 of Breton variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level3; // 1
		map[                                                            Shift ] = Level3; // 1
		map[                                               LevelThree         ] = Level3; // 1
		map[                                               LevelThree + Shift ] = Level5; // ¹
		map[                                   LevelFive                      ] = Level3; // 1
		map[                                   LevelFive              + Shift ] = Level6; // ₁
		map[                                   LevelFive + LevelThree         ] = Level5; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                  Lock                                            ] = Level3; // 1
		map[                  Lock                                    + Shift ] = Level3; // 1
		map[                  Lock                       + LevelThree         ] = Level3; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level5; // ¹
		map[                  Lock           + LevelFive                      ] = Level3; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level6; // ₁
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 1️⃣
		map[                         Control                                  ] = Level3; // 1
		map[                         Control                          + Shift ] = Level3; // 1
		map[                  Lock + Control                                  ] = Level3; // 1
		map[                  Lock + Control                          + Shift ] = Level3; // 1
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_AE10_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL3_CONTROL.
		// Used on Canadian variants.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_AE10_FIRSTALPHABETIC" {
		// Based on EIGHT_LEVELS_AE10.
		// Used on variants other than Canadian.
		// Designed to support both U1F51F 🔟 KEYCAP TEN emoji and UEFC0 0️⃣ keycap 0 emoji.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // à
		map[                                                            Shift ] = Level2; // À
		map[                                               LevelThree         ] = Level3; // 0
		map[                                               LevelThree + Shift ] = Level4; // )
		map[                                   LevelFive                      ] = Level3; // 0
		map[                                   LevelFive              + Shift ] = Level8; // 0️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // ⁰
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 🔟
		map[                  Lock                                            ] = Level2; // À
		map[                  Lock                                    + Shift ] = Level1; // à
		map[                  Lock                       + LevelThree         ] = Level3; // 0
		map[                  Lock                       + LevelThree + Shift ] = Level4; // )
		map[                  Lock           + LevelFive                      ] = Level3; // 0
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 0️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level5; // ⁰
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 🔟
		map[                         Control                                  ] = Level3; // 3
		map[                         Control                          + Shift ] = Level3; // 3
		map[                  Lock + Control                                  ] = Level3; // 3
		map[                  Lock + Control                          + Shift ] = Level3; // 3
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltGr (chiffres verrouillés)";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_MINUS_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL8_CONTROL.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level3; // ᵉ
		map[                                               LevelThree + Shift ] = Level4; // ]
		map[                                   LevelFive                      ] = Level2; // °
		map[                                   LevelFive              + Shift ] = Level8; // *️⃣
		map[                                   LevelFive + LevelThree         ] = Level6; // E
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // *️⃣
		map[                         Control                                  ] = Level7; // -
		map[                         Control                          + Shift ] = Level7; // -
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level2; // °
		map[                                               LevelThree + Shift ] = Level5; // ⁻
		map[                                   LevelFive                      ] = Level6; // E
		map[                                   LevelFive              + Shift ] = Level3; // ₋
		map[                                   LevelFive + LevelThree         ] = Level5; // ⁻
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // *️⃣
		map[                         Control                                  ] = Level7; // -
		map[                         Control                          + Shift ] = Level7; // -
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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
		// The Control value <plus> is expected to be more generally supported,
		// as opposed to its US-QWERTY variant <equal>.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // <ë>
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level3; // <¦>
		map[                                               LevelThree + Shift ] = Level4; // }
		map[                                   LevelFive                      ] = Level7; // =
		map[                                   LevelFive              + Shift ] = Level8; // #️⃣
		map[                                   LevelFive + LevelThree         ] = Level6; // F
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // #️⃣
		map[                         Control                                  ] = Level2; // +
		map[                         Control                          + Shift ] = Level2; // +
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "AltFr";

	};

	type "EIGHT_LEVELS_PLUS_GROUP2" {
		// Based on EIGHT_LEVELS_MINUS_GROUP1.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level7; // =
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level1; // <¦>
		map[                                               LevelThree + Shift ] = Level5; // ⁺
		map[                                   LevelFive                      ] = Level6; // F
		map[                                   LevelFive              + Shift ] = Level3; // ₊
		map[                                   LevelFive + LevelThree         ] = Level5; // ⁺
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // #️⃣
		map[                         Control                                  ] = Level2; // +
		map[                         Control                          + Shift ] = Level2; // +
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "AltFr";

	};

	type "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_PLUS.
		// Used on Swiss variant.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr + AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_PLUS_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_PLUS.
		// Used on Swiss variant.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // /
		map[                                                            Shift ] = Level2; // :
		map[                                               LevelThree         ] = Level3; // :
		map[                                               LevelThree + Shift ] = Level5; // <ë>
		map[                                   LevelFive                      ] = Level4; // < :>
		map[                                   LevelFive              + Shift ] = Level2; // :
		map[                                   LevelFive + LevelThree         ] = Level6; // ⁄
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 😃
		map[                         Control                                  ] = Level8; // /
		map[                         Control                          + Shift ] = Level8; // /
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

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

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
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

	type "EIGHT_LEVELS_PUNCTUATION_CA_GROUP2" {
		// Based on EIGHT_LEVELS_PUNCTUATION_THREE.
		// Used on Canadian French on AC10.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
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

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on Canadian variants on AB10.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on Canadian variants on AB10.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
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
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[             Lock + Control                                  ] = Control;
		preserve[             Lock + Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;
		preserve[             Lock           + LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	// type "EIGHT_LEVELS_NUMPAD_DIGIT" is replaced with the two following.

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1" {
		// For keys 2 4 6 8, where emoji arrows are black arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed first, the Function key last.
		// On desktop keyboards, the combos involving both LevelThree and
		// LevelFive are almost unusable, but on laptops these are useful.
		//
		//                       LevelFive  simple arrows          ↕↙↓↘←↔→↖↑↗
		//  Shift +              LevelFive  double arrows          ⇕⇙⇓⇘⇐⇔⇒⇖⇑⇗
		//          LevelThree              emoji arrows           ↕↙⬇↘⬅↔➡↖⬆↗
		//  Shift + LevelThree              uniform black arrows   ⬍⬋⬇⬊⬅⬌➡⬉⬆⬈
		//          LevelThree + LevelFive  triangle-headed arrows ⭥⭩⭣⭨⭠⭤⭢⭦⭡⭧
		//  Shift + LevelThree + LevelFive  white arrows           ⇳⬃⇩⬂⇦⬄⇨⬁⇧⬀
		//
		// Emoji arrows require a mixed palette for a consistent UX since the
		// 4 main arrows had been picked from black arrows as the simple ones
		// were used for keyboard arrows. The oblique and double-headed ones
		// have later been inconsistently picked from the simple arrow range.
		// See https://unicode-org.atlassian.net/browse/CLDR-11748
		// This layout addresses that problem by giving the emoji palette easy
		// access when  LevelThree  is held down, while uniform black arrows are
		// on Shift +  LevelThree . Initially, the palette was mixed on index 7.
		//
		// When the DigitsLock toggle is on, the layout is in Programmer mode.
		// The numpad offers the opportunity to switch hex letters (on Shift)
		// to lowercase, and output 0x, \u{, \x{ rather than 000, U, <NNBSP>.
		//
		// Initially, the AltGr + AltFr modifier combination was not used, as
		// these are hardly held down simultaneously while using the numpad.
		// However, overlay numpads on laptops can actually be used that way.
		// Therefore, two extra sets of arrows have been added in July 2021.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level6; // 
		map[                                               LevelThree + Shift ] = Level6; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level4 ] = "AltFr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	// type "EIGHT_LEVELS_NUMPAD_DIGIT" is replaced with the two following.

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2" {
		// For keys 2 4 6 8, where emoji arrows are black arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed first, the Function key last.
		//
		//  LevelFive  yields simple ↕↙↓↘←↔→↖↑↗ arrows.
		//  LevelFive +Shift yields double ⇕⇙⇓⇘⇐⇔⇒⇖⇑⇗ arrows.
		//  LevelThree +Shift yields uniform black ⬋⬇⬊⬅⬌➡⬉⬆⬈ arrows.
		// Emoji arrows ↙⬇↘⬅↔➡↖⬆↗ are output with  LevelThree  (only) pressed.
		//
		// Emoji arrows require a mixed palette for a consistent UX since the
		// 4 main arrows had been picked from black arrows as the simple ones
		// were used for keyboard arrows. The oblique and double-headed ones
		// have later been inconsistently picked from the simple arrow range.
		// See https://unicode-org.atlassian.net/browse/CLDR-11748
		// This layout addresses that problem by giving the emoji palette easy
		// access when  LevelThree  is held down, while uniform black arrows are
		// on Shift +  LevelThree . Initially, the palette was mixed on index 7.
		//
		// When the DigitsLock toggle is on, the layout is in Programmer mode.
		// The numpad offers the opportunity to switch hex letters (on Shift)
		// to lowercase, and output 0x, \u{, \x{ rather than 000, U, <NNBSP>.
		//
		// Initially, the AltGr + AltFr modifier combination was not used, as
		// these are hardly held down simultaneously while using the numpad.
		// However, overlay numpads on laptops can actually be used that way.
		// Therefore, two extra sets of arrows have been added in July 2021.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level6; // 
		map[                                               LevelThree + Shift ] = Level6; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level4 ] = "AltFr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "AltGr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1" {
		// For keys 0 1 3 5 7 9, where emoji arrows are simple arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed first, the Function key last.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level4; // 
		map[                                               LevelThree + Shift ] = Level6; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level4 ] = "AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2" {
		// For keys 0 1 3 5 7 9, where emoji arrows are simple arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed first, the Function key last.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level4; // 
		map[                                               LevelThree + Shift ] = Level6; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[                              LevelFive + LevelThree + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level4 ] = "AltGr";
		level_name[ Level5 ] = "Majuscule + AltFr";
		level_name[ Level6 ] = "Majuscule + AltGr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP1" {
		//  LevelThree  (impractical) and  LevelFive  (recommended) have same effect.
		// Both default mode and Programmer mode have a full set of 4 dedicated indices,
		// but level 1 of Programmer mode is mapped to index 1 for compatibility.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level4; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "aucun";
		level_name[ Level6 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level7 ] = "AltFr (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltFr (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_NUMPAD_OPERATOR_GROUP2" {
		//  LevelThree  (impractical) and  LevelFive  (recommended) have same effect.
		// Both default mode and Programmer mode have a full set of 4 dedicated indices,
		// but level 1 of Programmer mode is mapped to index 1 for compatibility.

		modifiers =                            LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level6; // 
		map[                                               LevelThree         ] = Level7; // 
		map[                                               LevelThree + Shift ] = Level8; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "aucun";
		level_name[ Level6 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level7 ] = "AltFr (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltFr (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP1" {
		// Based on EIGHT_LEVELS_NUMPAD_DIGIT.
		// Used on the decimal separator key(s).
		// CapsLock affects indices 1..2 and 5..6.

		modifiers =           Lock           + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level4; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level3; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level3; // 
		map[                  Lock           + LevelFive              + Shift ] = Level4; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "aucun";
		level_name[ Level6 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level7 ] = "AltFr (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltFr (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_NUMPAD_DECIMAL_SEPARATOR_GROUP2" {
		// Based on EIGHT_LEVELS_NUMPAD_DIGIT.
		// Used on the decimal separator key(s).
		// CapsLock affects indices 1..2 and 5..6.

		modifiers =           Lock           + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level6; // 
		map[                                               LevelThree         ] = Level7; // 
		map[                                               LevelThree + Shift ] = Level8; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level6; // 
		map[                  Lock                                    + Shift ] = Level5; // 
		map[                  Lock                       + LevelThree         ] = Level7; // 
		map[                  Lock                       + LevelThree + Shift ] = Level8; // 
		map[                  Lock           + LevelFive                      ] = Level7; // 
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;
		preserve[                              LevelFive              + Shift ] = Shift;
		preserve[             Lock                                    + Shift ] = Shift;
		preserve[             Lock                       + LevelThree + Shift ] = Shift;
		preserve[             Lock           + LevelFive              + Shift ] = Shift;

		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "Majuscule";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "aucun";
		level_name[ Level6 ] = "Majuscule (chiffres verrouillés)";
		level_name[ Level7 ] = "AltFr (chiffres verrouillés)";
		level_name[ Level8 ] = "Majuscule + AltFr (chiffres verrouillés)";

	};

	type "EIGHT_LEVELS_EDIT_GROUP1" {
		// Both Base and Shift levels are mapped to index 1 for compatibility.
		// Level Five is UX-disturbances-prone, and is therefore not used.
		// Output symbols depend on Programmer toggle state.

		modifiers =                  Control             + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level1; // Shift is handled on application side.
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;


		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "aucun";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr (chiffres verrouillés)";
		level_name[ Level6 ] = "Majuscule + AltGr (chiffres verrouillés)";
		level_name[ Level7 ] = "aucun";
		level_name[ Level8 ] = "aucun";

	};

	type "EIGHT_LEVELS_EDIT_GROUP2" {
		// Both Base and Shift levels are mapped to index 1 for compatibility.
		// Level Five is UX-disturbances-prone, and is therefore not used.
		// Output symbols depend on Programmer toggle state.

		modifiers =                  Control             + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level1; // 
		map[                                               LevelThree         ] = Level5; // 
		map[                                               LevelThree + Shift ] = Level6; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		preserve[                    Control                                  ] = Control;
		preserve[                    Control                          + Shift ] = Control + Shift;
		preserve[                                                       Shift ] = Shift;
		preserve[                                          LevelThree + Shift ] = Shift;


		level_name[ Level1 ] = "Base";
		level_name[ Level2 ] = "aucun";
		level_name[ Level3 ] = "AltGr";
		level_name[ Level4 ] = "Majuscule + AltGr";
		level_name[ Level5 ] = "AltGr (chiffres verrouillés)";
		level_name[ Level6 ] = "Majuscule + AltGr (chiffres verrouillés)";
		level_name[ Level7 ] = "aucun";
		level_name[ Level8 ] = "aucun";

	};

};

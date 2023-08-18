//                       Date: 2023-08-18T0326+0200
//              Last revision: 2023-08-17T1202+0200
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
//              Regular names: kb(brFRs|fr(AFs|BEs|CA(ms|s)|CHs|FR(h(w|z|y)|r|s)|PFs))
//   Full names, descriptions: kbbrFRs  Breton and French France semiautomatic keyboard layout
//                             kbfrAFs  Francophone Africa semiautomatic keyboard layout
//                             kbfrBEs  French Belgium semiautomatic keyboard layout
//                 (oncoming)  kbfrCAms French Canada multilingual semiautomatic keyboard layout
//                 (oncoming)  kbfrCAs  French Canada semiautomatic keyboard layout
//                 (oncoming)  kbfrCHs  French Switzerland semiautomatic keyboard layout
//                             kbfrFRr  French France remapped semiautomatic keyboard layout
//                             kbfrFRs  French France semiautomatic keyboard layout
//                             kbfrPFs  French Polynesia semiautomatic keyboard layout
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev@dispoclavier.net
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, *Linux* is supported alongside *ChromeOS*, or through ChromeOS.
//
//               Installation: 1. Add this file in /usr/share/X11/xkb/types/
//                             2. In /usr/share/X11/xkb/types/complete
//                                add the line
//                                    include "dispotypes"
//                                before the closing brace.
//                             The change takes effect when reopening a session.
//
//             Uninstallation: Delete that line prior to removing the file.
//
//
// ##   Mapping application shortcuts in keyboard layouts
//
// In XKB, applications take graphics mapped on Base level and Shift level
// as input for processing keyboard shortcuts with Control, recognizing the
// characters if matching those of US-QWERTY.
//
// That behavior can be overridden if key types contain mappings for Control.
//
// Mappings including Control are added for completeness on some keys,
// while technically not mandatory for unremapped alphabetic types in
// the Latin base alphabet.
//
// Shortcuts should be defined by the index of Base level only.
// But on alphabetic keys they do also wprk with uppercase, that
// in some applications is mandatory for Control + Shift shortcuts.
// Some important applications like LibreOffice do not recognize
// punctuation and symbols on Shift level for keyboard shortcuts,
// even if mapped according to US-QWERTY.
//
// Control for application shortcuts is mostly mapped to index 8.
// This scheme allows to have variants with graphics remapped while
// shortcuts remain the legacy way, without loss of graphics compared
// to unremapped variants, but with Ctrl + Shift + <letter> shortcuts
// not working in some applications, e.g. Nautilus, that has some of
// them. LibreOffice handles only Base level graphics for application
// shortcuts, with a tolerance on uppercase letters.
//
// Breaking down by Shift and all enabled toggles is mandatory.
// Control mappings need to be preserved because else, shortcuts
// would be output as graphics.
// Shift needs to be preserved for further processing shortcuts.
//
// Remapping letter shortcuts reduces the number of indices that can
// be used for graphics to 7 instead of 8 per key. Then, UX level 8
// is used to be able to check the content of index 8 as a graphic.
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

	type "EIGHT_LEVELS_TWO_GROUPS_FIRSTCONTROL" {
		// Based on EIGHT_LEVELS_SPACEBAR_GROUP1.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1;
		map[                                                            Shift ] = Level2;
		map[                                               LevelThree         ] = Level3;
		map[                                               LevelThree + Shift ] = Level4;
		map[                                   LevelFive                      ] = Level5;
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

	type "EIGHT_LEVELS_TWO_GROUPS_LASTCONTROL" {
		// Based on EIGHT_LEVELS_TWO_GROUPS_FIRSTCONTROL.

		modifiers =                  Control + LevelFive + LevelThree + Shift ;
		map[ None                                                             ] = Level1;
		map[                                                            Shift ] = Level2;
		map[                                               LevelThree         ] = Level3;
		map[                                               LevelThree + Shift ] = Level4;
		map[                                   LevelFive                      ] = Level5;
		map[                                   LevelFive              + Shift ] = Level6;
		map[                                   LevelFive + LevelThree         ] = Level7;
		map[                                   LevelFive + LevelThree + Shift ] = Level8;
		map[                         Control                                  ] = Level8;
		map[                         Control                          + Shift ] = Level8;
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

	type "EIGHT_LEVELS_TWO_GROUPS_CAPITAL_LASTCONTROL" {
		// Based on EIGHT_LEVELS_AC11_GROUP1.
		// A casing letter on level 1, if any, is passed on to internal capitalization.

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
		// Based on EIGHT_LEVEL_SEMIALPHABETIC (not EIGHT_LEVELS_SEMIALPHABETIC).
		// All variants use this on keys B01..B05.
		// Used on almost all other base letter keys in variants that have
		// graphic letters and shortcut letters mapped consistently throughout.
		//
		// CapsLock affects indices 1..2.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level4; // 
		map[                                               LevelThree + Shift ] = Level5; // 
		map[                                   LevelFive                      ] = Level6; // 
		map[                                   LevelFive              + Shift ] = Level7; // 
		map[                                   LevelFive + LevelThree         ] = Level3; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level4; // 
		map[                  Lock                       + LevelThree + Shift ] = Level5; // 
		map[                  Lock           + LevelFive                      ] = Level6; // 
		map[                  Lock           + LevelFive              + Shift ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level3; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level2; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level2; // 
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

	type "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SIX_TITLECASE" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AD02.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level4; // 
		map[                                               LevelThree + Shift ] = Level5; // 
		map[                                   LevelFive                      ] = Level4; // 
		map[                                   LevelFive              + Shift ] = Level7; // 
		map[                                   LevelFive + LevelThree         ] = Level3; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level4; // 
		map[                  Lock                       + LevelThree + Shift ] = Level5; // 
		map[                  Lock           + LevelFive                      ] = Level4; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level3; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level1;
		map[                         Control                          + Shift ] = Level2;
		map[                  Lock + Control                                  ] = Level1;
		map[                  Lock + Control                          + Shift ] = Level2;
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

	type "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL_SEVEN_ALPHABETIC" {
		// Based on EIGHT_LEVELS_FIRSTALPHABETIC.
		// Used on AD02.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level2; // 
		map[                                               LevelThree         ] = Level4; // 
		map[                                               LevelThree + Shift ] = Level5; // 
		map[                                   LevelFive                      ] = Level6; // 
		map[                                   LevelFive              + Shift ] = Level7; // 
		map[                                   LevelFive + LevelThree         ] = Level3; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level2; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level4; // 
		map[                  Lock                       + LevelThree + Shift ] = Level5; // 
		map[                  Lock           + LevelFive                      ] = Level6; // 
		map[                  Lock           + LevelFive              + Shift ] = Level8; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level3; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level1;
		map[                         Control                          + Shift ] = Level2;
		map[                  Lock + Control                                  ] = Level1;
		map[                  Lock + Control                          + Shift ] = Level2;
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP1" {
		// Based on EIGHT_LEVELS_DIGIT.
		// Used on keys AE01, AE03..AE06.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // "
		map[                                                            Shift ] = Level3; // –
		map[                                               LevelThree         ] = Level1; // 3
		map[                                               LevelThree + Shift ] = Level8; // #
		map[                                   LevelFive                      ] = Level6; // 3
		map[                                   LevelFive              + Shift ] = Level7; // 3️⃣
		map[                                   LevelFive + LevelThree         ] = Level4; // ³
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 3️⃣
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
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
		// Used on AE01.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // ²
		map[                                                            Shift ] = Level3; // ³
		map[                                               LevelThree         ] = Level1; // 1
		map[                                               LevelThree + Shift ] = Level8; // &
		map[                                   LevelFive                      ] = Level1; // 1
		map[                                   LevelFive              + Shift ] = Level7; // 1️⃣
		map[                                   LevelFive + LevelThree         ] = Level4; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 1️⃣
		map[                  Lock                                            ] = Level6; // ₂
		map[                  Lock                                    + Shift ] = Level5; // ₃
		map[                  Lock                       + LevelThree         ] = Level1; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level8; // &
		map[                  Lock           + LevelFive                      ] = Level1; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level7; // 1️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level4; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 1️⃣
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
		// Used on AE02, AE07, AE09.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // é
		map[                                                            Shift ] = Level3; // É
		map[                                               LevelThree         ] = Level1; // 2
		map[                                               LevelThree + Shift ] = Level8; // <~>
		map[                                   LevelFive                      ] = Level1; // 2
		map[                                   LevelFive              + Shift ] = Level7; //  2️⃣
		map[                                   LevelFive + LevelThree         ] = Level4; // ²
		map[                                   LevelFive + LevelThree + Shift ] = Level7; //  2️⃣
		map[                  Lock                                            ] = Level3; // É
		map[                  Lock                                    + Shift ] = Level2; // é
		map[                  Lock                       + LevelThree         ] = Level1; // 2
		map[                  Lock                       + LevelThree + Shift ] = Level8; // <~>
		map[                  Lock           + LevelFive                      ] = Level1; // 2
		map[                  Lock           + LevelFive              + Shift ] = Level7; //  2️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level4; // ²
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; //  2️⃣
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
		// Used on AE01 of Breton and Francophone Africa variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level1; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level3; // 
		map[                  Lock                                    + Shift ] = Level2; // 
		map[                  Lock                       + LevelThree         ] = Level1; // 
		map[                  Lock                       + LevelThree + Shift ] = Level4; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
		// Used on AE01 of kbbrFRs.
		// Supports Breton with an extra uppercase string on index 4.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level1; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level4; // 
		map[                  Lock                                    + Shift ] = Level2; // 
		map[                  Lock                       + LevelThree         ] = Level1; // 
		map[                  Lock                       + LevelThree + Shift ] = Level3; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
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

	type "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_AE10.
		// Used on variants other than Canadian.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level2; // à
		map[                                                            Shift ] = Level3; // À
		map[                                               LevelThree         ] = Level1; // 0
		map[                                               LevelThree + Shift ] = Level8; // )
		map[                                   LevelFive                      ] = Level1; // 0
		map[                                   LevelFive              + Shift ] = Level7; // 0️⃣
		map[                                   LevelFive + LevelThree         ] = Level4; // ⁰
		map[                                   LevelFive + LevelThree + Shift ] = Level6; // 🔟
		map[                  Lock                                            ] = Level3; // À
		map[                  Lock                                    + Shift ] = Level2; // à
		map[                  Lock                       + LevelThree         ] = Level1; // 0
		map[                  Lock                       + LevelThree + Shift ] = Level8; // )
		map[                  Lock           + LevelFive                      ] = Level1; // 0
		map[                  Lock           + LevelFive              + Shift ] = Level7; // 0️⃣
		map[                  Lock           + LevelFive + LevelThree         ] = Level4; // ⁰
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level6; // 🔟
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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
		// Based on EIGHT_LEVELS_AD11.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level3; // ᵉ
		map[                                               LevelThree + Shift ] = Level8; // ]
		map[                                   LevelFive                      ] = Level2; // °
		map[                                   LevelFive              + Shift ] = Level7; // *️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // E
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // *️⃣
		map[                         Control                                  ] = Level6; // -
		map[                         Control                          + Shift ] = Level6; // -
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
		// Based on EIGHT_LEVELS_MINUS.
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

	type "EIGHT_LEVELS_PLUS_GROUP1" {
		// Based on EIGHT_LEVELS_MINUS.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // <ò>
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level3; // ʳ
		map[                                               LevelThree + Shift ] = Level8; // }
		map[                                   LevelFive                      ] = Level6; // =
		map[                                   LevelFive              + Shift ] = Level7; // #️⃣
		map[                                   LevelFive + LevelThree         ] = Level5; // F
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // #️⃣
		map[                         Control                                  ] = Level6; // =
		map[                         Control                          + Shift ] = Level6; // =
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

	type "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP1" {
		// Based on EIGHT_LEVELS_PUNCTUATION_ONE.
		// Used on AB09.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level2; // 
		map[                                   LevelFive              + Shift ] = Level3; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level6; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
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

	type "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP1" {
		// Based on EIGHT_LEVELS_PUNCTUATION_THREE.
		// Used on AB10.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level3; // 
		map[                                               LevelThree         ] = Level5; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level2; // 
		map[                                   LevelFive              + Shift ] = Level3; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level6; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
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
		level_name[ Level5 ] = "AltGr";
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

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP1" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
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

	// type "EIGHT_LEVELS_NUMPAD_DIGIT" is replaced with the two following.

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP1" {
		// For keys 2 4 6 8, where emoji arrows are black arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed FIRST, the Function key LAST.
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

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP1" {
		// For keys 0 1 3 5 7 9, where emoji arrows are simple arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed FIRST, the Function key LAST.

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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_GROUP2" {
		// Based on EIGHT_LEVELS_DIGIT.
		// Used on keys AE01, AE03..AE06.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 3
		map[                                                            Shift ] = Level1; // 3
		map[                                               LevelThree         ] = Level1; // 3
		map[                                               LevelThree + Shift ] = Level4; // ³
		map[                                   LevelFive                      ] = Level6; // 3
		map[                                   LevelFive              + Shift ] = Level5; // ₃
		map[                                   LevelFive + LevelThree         ] = Level4; // ³
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 3️⃣
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
		level_name[ Level5 ] = "AltFr";
		level_name[ Level6 ] = "Majuscule + AltFr";
		level_name[ Level7 ] = "AltGr + AltFr";
		level_name[ Level8 ] = "Majuscule + AltGr + AltFr";

	};

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
		// Used on AE01.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 1
		map[                                                            Shift ] = Level1; // 1
		map[                                               LevelThree         ] = Level1; // 1
		map[                                               LevelThree + Shift ] = Level4; // ¹
		map[                                   LevelFive                      ] = Level1; // 1
		map[                                   LevelFive              + Shift ] = Level5; // ₁
		map[                                   LevelFive + LevelThree         ] = Level4; // ¹
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 1️⃣
		map[                  Lock                                            ] = Level1; // 1
		map[                  Lock                                    + Shift ] = Level1; // 1
		map[                  Lock                       + LevelThree         ] = Level1; // 1
		map[                  Lock                       + LevelThree + Shift ] = Level4; // ¹
		map[                  Lock           + LevelFive                      ] = Level1; // 1
		map[                  Lock           + LevelFive              + Shift ] = Level5; // ₁
		map[                  Lock           + LevelFive + LevelThree         ] = Level4; // ¹
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 1️⃣
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
		// Used on AE02, AE07, AE09.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 2
		map[                                                            Shift ] = Level1; // 2
		map[                                               LevelThree         ] = Level1; // 2
		map[                                               LevelThree + Shift ] = Level4; // ²
		map[                                   LevelFive                      ] = Level1; // 2
		map[                                   LevelFive              + Shift ] = Level5; // ₂
		map[                                   LevelFive + LevelThree         ] = Level4; // ²
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 2️⃣
		map[                  Lock                                            ] = Level1; // 2
		map[                  Lock                                    + Shift ] = Level1; // 2
		map[                  Lock                       + LevelThree         ] = Level1; // 2
		map[                  Lock                       + LevelThree + Shift ] = Level7; // 2️⃣
		map[                  Lock           + LevelFive                      ] = Level6; // 2
		map[                  Lock           + LevelFive              + Shift ] = Level8; // ~
		map[                  Lock           + LevelFive + LevelThree         ] = Level8; // ~
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 2️⃣
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
		// Used on AE01 of Breton and Francophone Africa variants.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level1; // 
		map[                                               LevelThree         ] = Level1; // 
		map[                                               LevelThree + Shift ] = Level8; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level1; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level1; // 
		map[                  Lock                       + LevelThree + Shift ] = Level8; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_LEVEL_ONE_LOCK_SUPERSUB_FIRSTALPHABETIC_TITLECASE_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
		// Used on AE01 of kbbrFRs.
		// Supports Breton with an extra uppercase string on index 4.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 
		map[                                                            Shift ] = Level1; // 
		map[                                               LevelThree         ] = Level1; // 
		map[                                               LevelThree + Shift ] = Level8; // 
		map[                                   LevelFive                      ] = Level7; // 
		map[                                   LevelFive              + Shift ] = Level6; // 
		map[                                   LevelFive + LevelThree         ] = Level7; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level8; // 
		map[                  Lock                                            ] = Level1; // 
		map[                  Lock                                    + Shift ] = Level1; // 
		map[                  Lock                       + LevelThree         ] = Level1; // 
		map[                  Lock                       + LevelThree + Shift ] = Level8; // 
		map[                  Lock           + LevelFive                      ] = Level5; // 
		map[                  Lock           + LevelFive              + Shift ] = Level6; // 
		map[                  Lock           + LevelFive + LevelThree         ] = Level7; // 
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level8; // 
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_AE10_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK.
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

	type "EIGHT_LEVELS_AE10_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_AE10.
		// Used on variants other than Canadian.

		modifiers =           Lock + Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // 0
		map[                                                            Shift ] = Level1; // 0
		map[                                               LevelThree         ] = Level1; // 0
		map[                                               LevelThree + Shift ] = Level4; // ⁰
		map[                                   LevelFive                      ] = Level1; // 0
		map[                                   LevelFive              + Shift ] = Level5; // ₀
		map[                                   LevelFive + LevelThree         ] = Level4; // ⁰
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 0️⃣
		map[                  Lock                                            ] = Level1; // 0
		map[                  Lock                                    + Shift ] = Level1; // 0
		map[                  Lock                       + LevelThree         ] = Level1; // 0
		map[                  Lock                       + LevelThree + Shift ] = Level4; // ⁰
		map[                  Lock           + LevelFive                      ] = Level1; // 0
		map[                  Lock           + LevelFive              + Shift ] = Level5; // ₀
		map[                  Lock           + LevelFive + LevelThree         ] = Level4; // ⁰
		map[                  Lock           + LevelFive + LevelThree + Shift ] = Level7; // 0️⃣
		map[                         Control                                  ] = Level1; // 
		map[                         Control                          + Shift ] = Level1; // 
		map[                  Lock + Control                                  ] = Level1; // 
		map[                  Lock + Control                          + Shift ] = Level1; // 
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

	type "EIGHT_LEVELS_MINUS_GROUP2" {
		// Based on EIGHT_LEVELS_AD11.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level1; // @
		map[                                                            Shift ] = Level2; // °
		map[                                               LevelThree         ] = Level2; // °
		map[                                               LevelThree + Shift ] = Level4; // ⁻
		map[                                   LevelFive                      ] = Level5; // E
		map[                                   LevelFive              + Shift ] = Level3; // ₋
		map[                                   LevelFive + LevelThree         ] = Level4; // ⁻
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // *️⃣
		map[                         Control                                  ] = Level6; // -
		map[                         Control                          + Shift ] = Level6; // -
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

	type "EIGHT_LEVELS_MINUS_CH_GROUP2" {
		// Based on EIGHT_LEVELS_MINUS.
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

	type "EIGHT_LEVELS_PLUS_GROUP2" {
		// Based on EIGHT_LEVELS_MINUS.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level6; // =
		map[                                                            Shift ] = Level2; // +
		map[                                               LevelThree         ] = Level2; // +
		map[                                               LevelThree + Shift ] = Level4; // ⁺
		map[                                   LevelFive                      ] = Level5; // F
		map[                                   LevelFive              + Shift ] = Level3; // ₊
		map[                                   LevelFive + LevelThree         ] = Level4; // ⁺
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // #️⃣
		map[                         Control                                  ] = Level6; // =
		map[                         Control                          + Shift ] = Level6; // =
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

	type "EIGHT_LEVELS_PUNCTUATION_THREE_GROUP2" {
		// Based on EIGHT_LEVELS_PUNCTUATION_ONE.
		// Used on AB09.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level3; // 
		map[                                                            Shift ] = Level1; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
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

	type "EIGHT_LEVELS_PUNCTUATION_FOUR_GROUP2" {
		// Based on EIGHT_LEVELS_PUNCTUATION_THREE.
		// Used on AB10.

		modifiers =                  Control + LevelFive + LevelThree + Shift;
		map[ None                                                             ] = Level3; // 
		map[                                                            Shift ] = Level1; // 
		map[                                               LevelThree         ] = Level3; // 
		map[                                               LevelThree + Shift ] = Level4; // 
		map[                                   LevelFive                      ] = Level3; // 
		map[                                   LevelFive              + Shift ] = Level5; // 
		map[                                   LevelFive + LevelThree         ] = Level5; // 
		map[                                   LevelFive + LevelThree + Shift ] = Level7; // 
		map[                         Control                                  ] = Level8; // 
		map[                         Control                          + Shift ] = Level8; // 
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
		level_name[ Level5 ] = "AltGr";
		level_name[ Level6 ] = "AltGr + AltFr";
		level_name[ Level7 ] = "Majuscule + AltGr + AltFr";
		level_name[ Level8 ] = "Contrôle";

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

	type "EIGHT_LEVELS_PUNCTUATION_FIRSTALPHABETIC_GROUP2" {
		// Based on EIGHT_LEVELS_LEVEL_ONE_LOCK_FIRSTALPHABETIC.
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

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_BLACK_GROUP2" {
		// For keys 2 4 6 8, where emoji arrows are black arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed FIRST, the Function key LAST.
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

	type "EIGHT_LEVELS_NUMPAD_DIGIT_EMOJI_SIMPLE_GROUP2" {
		// For keys 0 1 3 5 7 9, where emoji arrows are simple arrows.
		//
		// DISCLAIMER: For this to work on laptops with an overlay numpad,
		// the modifiers may need to be pressed FIRST, the Function key LAST.

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

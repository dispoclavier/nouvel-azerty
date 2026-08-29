//                      Date : 2026-08-29T1325+0200
//      Nom de fichier final : dispocla_perso
//                  Encodage : UTF-8
//                      Type : texte/configuration XKB
//     Coloration syntaxique : C
//               Description : tables d’allocation de touches XKB
//                Plateforme : systèmes d’exploitation Linux et ChromeOS* utilisant XKB avec XCompose
//
//             Nom du projet : Dispoclavier
//             URL du projet : https://dispoclavier.com
//              Licence code : Apache 2.0
//          URL licence code : https://www.apache.org/licenses/LICENSE-2.0
//          Licence non-code : CC-BY 4.0
//      URL licence non-code : https://creativecommons.org/licenses/by/4.0/deed.fr
//              Adresse mail : dev[arobase]dispoclavier.com
//
//   * Au CLDR d’Unicode, cette plateforme s’appelle ChromeOS, avec comme explication
//     qu’au CLDR, Linux est pris en charge au travers de ChromeOS.
//
//              Installation : Ce fichier doit être installé en premier dans
//
//                                 /usr/share/X11/xkb/symbols/dispocla_perso
//
//                             manuellement ou par le script d’installation installer.sh
//                             inclus dans le paquetage téléchargeable depuis son dépôt
//                             GitHub à l’adresse suivante :
//
//                                 https://github.com/dispoclavier/nouvel-azerty/releases/latest
//
//                             Car il est inclus dans toutes les dispositions de clavier
//                             configurées dans /usr/share/X11/xkb/symbols/dispocla
//
//                             Les personnalisations peuvent se mettre à la place de toute
//                             instance de NoSymbol, qui signifie « rien d’autre ».
//
// ## Avertissement
//
// Les mises à jour de Linux effacent les fichiers ajoutés dans /usr/share/X11/
// et nécessitent la réinstallation des dispositions de clavier utilisées.
// C’est pourquoi les personnalisations faites dans /usr/share/X11/
// doivent être sauvegardées, par exemple en désinstallant ces dispositions.
//
// Les personnalisations ne sont pas affectées par les mises à jour vers une
// nouvelle version de ces dispositions de clavier. Lors de la désinstallation,
// elles sont sauvegardées.
//
// Les nouvelles personnalisations deviennent effectives à partir de la
// prochaine session.
//
//
// ## Exemple 1
//
// Le point médian "·" U00B7 est au niveau 1 de la touche B10, en synergie
// avec les minuscules ou les capitales selon l’état de la bascule VerrCap,
// sauf sur les variantes redisposées qui, elles, y ont la contre-oblique.
//
//	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
//	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
//	key <AB10> {
//		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[      periodcentered,               UEF60,             section,              exclam,     dead_belowcomma,             section,              U1F494,           backslash ],
//		[           semicolon,              exclam,           semicolon,              exclam,     dead_belowcomma,             section,              U1F609,           backslash ]
//	}; // UEF60 ' !' spaced out with NNBSP; U1F494 💔 BROKEN HEART 16th-ranking emoji; U1F609 😉 WINKING FACE 24th-ranking emoji
//
// Pour y avoir la contre-oblique aussi sur les AZERTY, à cause de son usage en
// TeX et LaTeX, sachant que le point médian est aussi dans le groupe 1 de p/P,
// il faut mettre "backslash" à la place de "NoSymbol" à l’index 1 du groupe 1
// de la touche "AB10".
//
//	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
//	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
//	key <AB10> {
//		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[           backslash,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
//		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
//	};
//
// Pour y mettre plutôt le trait d’union Unicode U2010, à cause de son glyphe
// (et de celui du trait d’union ASCII U002D) dans Lucida Sans Unicode :
//
//	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
//	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
//	key <AB10> {
//		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[               U2010,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
//		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
//	};
//
//
// ## Exemple 2
//
// À gauche de ⟦1&⟧, la touche E00, TLDE, utilisée pour la bascule Verrouillage
// en mode ASCII peut être redisposée, car le verrouillage en mode ASCII est en
// Majuscule, en AltGr et en AltFr sur la touche de verrouillage des capitales.
//
// L’essentiel pour commencer est de rétablir les raccourcis clavier de cette
// touche, où l’US-QWERTY a le grave (et aussi l’asciitilde en Majuscule).
//
// On peut prendre le type de touche qui a le raccourci clavier au niveau 8,
// puis disposer les autres niveaux en mode français [Group1] et en mode ASCII.
//
//	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
//	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
//	key <TLDE> {
//		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[            asterisk,                  mu,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               grave ],
//		[              dollar,            sterling,            currency,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,               grave ]
//	};
//

default partial alphanumeric_keys keypad_keys
xkb_symbols "perso" {

	name[Group1] = "Personnalisations";
	name[Group2] = "Personnalisations, mode ASCII";

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <TLDE> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_SUPERSCRIPT_SUBSCRIPT_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE02> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE03> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE04> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE10> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE12> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC_TITLECASE";
	key <AD01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AD02> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD03> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD04> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD07> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD08> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD10> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD12> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AC01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC02> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC03> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC04> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC07> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC08> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC10> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key <AC11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <BKSL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC";
	key <AB01> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB02> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB03> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB04> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key.type[Group2] = "EIGHT_LEVELS_FIRSTALPHABETIC_LASTALPHABETIC";
	key <AB06> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <AB07> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB08> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PUNCTUATION_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PUNCTUATION_GROUP2";
	key <AB09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB10> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <SPCE> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Pavé numérique
	//
	// Sur un pavé numérique superposé avec l’appui sur Fn, il faut appuyer sur la modificatrice AltFr
	// avant d’appuyer sur la touche Fn.
	//

	key.type[Group1]= "ONE_LEVEL";
	key.type[Group2]= "ONE_LEVEL";
	key <KPEQ> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Touches d’opérateurs
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <KPDV> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KPMU> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KPSU> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KPAD> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Touches de chiffres
	//
	// Les fonctionnalités d’édition sur le pavé numérique sont désactivées comme
	// dépassées et redondantes. À la place, le niveau 2 est réaffecté à la saisie.
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <KP0>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP1>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP2>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP3>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP4>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP5>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP6>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP7>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP8>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP9>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Touches du séparateur décimal
	//
	// Les claviers ABNT-2 ont une touche point au-dessus d’Entrée, tandis que
	// la touche du séparateur décimal à côté d’Entrée insère la virgule.
	// https://bugzilla.redhat.com/show_bug.cgi?id=470153
	// https://bugs.launchpad.net/ubuntu/+source/xkeyboard-config/+bug/272606
	//

	key.type[Group1] = "EIGHT_LEVELS_NUMPAD_SEPARATOR";
	key.type[Group2] = "EIGHT_LEVELS_NUMPAD_SEPARATOR";
	key <KPDL> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KPPT> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Touche AB11 pour claviers ABNT-2
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <AB11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

};

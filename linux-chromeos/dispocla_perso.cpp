//                      Date : 2025-07-22T1107+0200
//      Nom de fichier final : dispocla_perso
//                  Encodage : UTF-8
//                      Type : texte/configuration XKB
//     Coloration syntaxique : C
//               Description : tables d’allocation de touches XKB
//                Plateforme : systèmes d’exploitation Linux et ChromeOS* utilisant XKB avec XCompose
//
//   * Au CLDR d’Unicode, cette plateforme s’appelle ChromeOS, avec comme explication
//     qu’au CLDR, Linux est pris en charge aux côtés de ChromeOS, ou par ChromeOS.
//
//              Installation : Ce fichier doit être installé en premier dans
//                             /usr/share/X11/xkb/symbols/dispocla_perso
//                             car il est inclus dans toutes les dispositions de clavier
//                             configurées dans /usr/share/X11/xkb/symbols/dispocla dès lors
//                             que ce nouvel AZERTY a été installé, manuellement ou par le
//                             script d’installation installer.sh inclus dans le paquetage
//                             téléchargeable depuis son dépôt GitHub à l’adresse suivante :
//
//                                 https://github.com/dispoclavier/nouvel-azerty/releases/latest
//
//                             Les personnalisations peuvent se mettre à la place de toute
//                             instance de NoSymbol, qui signifie « rien d’autre ».
//
//
// # Exemple
//
// L’indicateur ordinal "ᵉ" U1D49 est au niveau 3 de la touche E11, en synergie
// avec l’espace insécable U00A0, dans dispocla.cpp :
//
//	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
//	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
//	key <AE11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[                  at,              degree,               U1D49,        bracketright,               U207B,                   E,               UEFCA,               minus ],
//		[                  at,              degree,               minus,               U208B,                   E,               U207B,               UEFCA,               minus ]
//	}; // U1D49 ᵉ MODIFIER LETTER SMALL E; U207B ⁻ SUPERSCRIPT MINUS; U208B ₋ SUBSCRIPT MINUS; UEFCA *️⃣ keycap star emoji
//
// Pour lui ajouter une espace fine insécable comme l’espace fine insécable des
// guillemets ouvrants en Majuscule, la séquence UEF6C dans Compose.yml :
//
//     <UEF6C> : "ᵉ " # U1D49 U202F
//
// va dans key <AE11> en mode français dans dispocla_perso.cpp :
//
//	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
//	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
//	key <AE11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
//		[            NoSymbol,            NoSymbol,               UEF6C,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
//		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
//	};
//
// Les nouvelles personnalisations deviennent effectives à partir de la
// prochaine session. Les personnalisations ne sont pas affectées par les mises
// à jour vers les nouvelles versions. Lors de la désinstallation, elles sont
// sauvegardées.
//

default partial alphanumeric_keys keypad_keys
xkb_symbols "perso" {

	name[Group1] = "Personnalisations";
	name[Group2] = "Personnalisations, mode ASCII";

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

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
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

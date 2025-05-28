//                      Date : 2025-05-28T0428+0200
//      Nom de fichier final : dispocla_perso
//                  Encodage : UTF-8
//                      Type : texte/configuration XKB
//                   Langage : comme du C
//               Description : tables d’allocation de touches XKB
//                Plateforme : systèmes d’exploitation Linux et ChromeOS* utilisant XKB avec XCompose
//
//   * Au CLDR d’Unicode, cette plateforme s’appelle ChromeOS, avec comme explication
//     qu’au CLDR, *Linux* est pris en charge aux côtés de *ChromeOS*, ou par ChromeOS.
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
//                             instance de NoSymbol (qui signifie « rien d’autre »).
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE03> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE04> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AE06> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_FIRSTALPHABETIC_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE07> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL3_CONTROL";
	key <AE08> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_MINUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_MINUS_GROUP2";
	key <AE11> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_PLUS_GROUP1";
	key.type[Group2] = "EIGHT_LEVELS_PLUS_GROUP2";
	key <AE12> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD03> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD04> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD06> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD07> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD08> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD10> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <AD11> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AD12> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC03> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC04> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC05> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC06> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC07> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC08> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC09> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AC10> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_CAPITAL_LEVEL8_CONTROL";
	key <AC11> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL8_CONTROL";
	key <BKSL> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB03> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB04> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <AB07> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <AB08> {
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key.type[Group1] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key.type[Group2] = "EIGHT_LEVELS_LEVEL1_CONTROL";
	key <SPCE> {
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
		[            KP_Equal ],
		[            KP_Equal ]
	};

	//
	// Touches d’opérateurs
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <KPDV> {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		[           KP_Divide,            division,             radical,           parenleft,             radical,           parenleft ],
		[           KP_Divide,           parenleft,         bracketleft,               UEF7E,         bracketleft,               UEF7E ]
	};

	key <KPMU> {
		[         KP_Multiply,            multiply,         asciicircum,          parenright,         asciicircum,          parenright ],
		[         KP_Multiply,          parenright,        bracketright,               UEF7F,        bracketright,               UEF7F ]
	};

	key <KPSU> {
		[         KP_Subtract,               U2212,               equal,               U2243,               equal,               U2243 ],
		[         KP_Subtract,         asciicircum,               equal,          braceright,               equal,          braceright ]
	};

	key <KPAD> {
		[              KP_Add,               colon,           plusminus,               U2248,           plusminus,               U2248 ],
		[              KP_Add,               colon,           plusminus,               UEF7C,           plusminus,               UEF7C ]
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
		// Category:    digit,            sequence,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit,            sequence,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP1>  {
		// Category:    digit,            sequence,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit,            sequence,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP2>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP3>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP4>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category:    digit,              prefix,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit,              prefix,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP5>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP6>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP7>  {
		// Category:    digit,      fraction slash,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit,    escape character,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP8>  {
		// Index:           1,                   2,                   3,                   4,                   5,                   6,                   7,                   8
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji filled arrow,        filled arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	key <KP9>  {
		// Category:    digit, uppercase hex digit,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow,     triangle-headed,       outline arrow
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		// Category:    digit, lowercase hex digit,     triangle-headed,       outline arrow,        simple arrow,        double arrow,  emoji simple arrow,        filled arrow
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
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

	//
	// Touche AB11 pour claviers ABNT-2
	//

	key.type[Group1] = "EIGHT_LEVELS_BASIC";
	key.type[Group2] = "EIGHT_LEVELS_BASIC";
	key <AB11> {
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ],
		[            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol,            NoSymbol ]
	};

};

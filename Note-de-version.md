# 5.3.0 (prépublication)

|Tant que les modes d’emploi ne sont pas à jour, la version 5.3.0 reste en prépublication.|
|:-:|

Rectification du groupe 10 des symboles.

Prise en charge des drapeaux et des émojis lettres sur touches vives sous Windows.

Prise en charge par touche morte sous Linux, des 3 drapeaux régionaux sur touche vive sous Windows.

Mise à niveau du pavé numérique sous Windows selon le pavé numérique complet sous Linux.

Prise en charge de 5 alphabets mathématiques préformatés sur touches vives sous Windows.

Prise en charge sous Windows des redispositions basées sur les sous-variantes sous Linux.

Aide à la production autonome de pilotes personnalisés et d’installateurs sous Windows.

## Modifications

* Disposition :
	* Pavé numérique :
		* Mettre à niveau sous Windows selon le pavé numérique pour Linux. kbcommon.H [eda6c76](https://github.com/dispoclavier/nouvel-azerty/commit/eda6c7662762cf75a58c5c6cd1db3762485b0305), kbfrFRs.C [1363945](https://github.com/dispoclavier/nouvel-azerty/commit/136394566f4e27d3f29b3673c125ea38856af442), [f14901b](https://github.com/dispoclavier/nouvel-azerty/commit/f14901b7302bcd8cc61c55ca832c53633fcbcb03), kbfredis.C [5bc3ad8](https://github.com/dispoclavier/nouvel-azerty/commit/5bc3ad89888cd0dd9c3be10230597447a7b902ec)
		* Remplir les positions vides. dispocla.cpp [4517a6d](https://github.com/dispoclavier/nouvel-azerty/commit/4517a6db7a9f8be2511b0b0f5d9402bebeda7296), kbfrFRs.C [f14901b](https://github.com/dispoclavier/nouvel-azerty/commit/f14901b7302bcd8cc61c55ca832c53633fcbcb03), kbfredis.C [5ea4c28](https://github.com/dispoclavier/nouvel-azerty/commit/5ea4c28f2ef48eb2315c231564cad4403b9d50aa)
	* Bloc alphanumérique sous Windows :
		* Niveau 9 :
			* Redonder les émojis lettres indicateurs régionaux "🇦" U+1F1E6 .. "🇿" U+1F1FF sur les touches alphabétiques. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
			* Redonder les émojis chiffres "0️⃣".."9️⃣" et l’émoji touche de téléphone "*️⃣" sur les premières touches de la rangée E. ibidem
			* Ajouter "🟰" U+1F7F0 sur la touche "=" E12. ibidem
			* Ajouter "💲" U+1F4B2 sur la touche "$" D12. ibidem
			* Redonder "*️⃣" sur la touche "\*" C12. ibidem
			* Redonder "#️⃣" sur la touche C11 pour compléter. ibidem
			* Redonder "⚠" U+26A0 sur la touche "^" D11. kbfrFRs.C [6bf10f9](https://github.com/dispoclavier/nouvel-azerty/commit/6bf10f9b903831985b42a24784c9020bc0446647), kbfredis.C [1d3cb07](https://github.com/dispoclavier/nouvel-azerty/commit/1d3cb075796c999ee24b56b6fa52df73cab3d924)
			* Redonder "❓" U+2753 sur la touche "?" B07. ibidem
			* Redonder "❗" U+2757 sur la touche "!" B08. ibidem
			* Ajouter "🏳" U+1F3F3 sur la touche "/" B09. kbfrFRs.C [3299c32](https://github.com/dispoclavier/nouvel-azerty/commit/3299c322f1a2432bbb8d308e496ab89e325af2af), [0f620d6](https://github.com/dispoclavier/nouvel-azerty/commit/0f620d6ee3870983706080ffaddd01c4628ba322), kbfredis.C [7bd66c5](https://github.com/dispoclavier/nouvel-azerty/commit/7bd66c5ca3854bcadc7365ad2c9d359603da0400)
			* Redonder "🏴" U+1F3F4 sur la touche "\" B10. ibidem
			* Redonder le gluon "⁠" U+2060 sur la barre d’espace pour écrire en émojis lettres. kbfrFRs.C [f04d39c](https://github.com/dispoclavier/nouvel-azerty/commit/f04d39c0525359698b613ea2d00ac308bcdaab83), kbfredis.C [9d7c86e](https://github.com/dispoclavier/nouvel-azerty/commit/9d7c86ef5c0383ddb97f085b8d284c87b2e1c6ad)
		* Niveau 10 :
			* Redonder les émojis lettres avec gluon "⁠" U+2060 pour écrire en émojis lettres, plutôt que les étiquettes minuscules pour composer des drapeaux régionaux. ibidem
			* Ajouter les 3 seuls drapeaux régionaux "🏴󠁧󠁢󠁷󠁬󠁳󠁿" sur C12, "🏴󠁧󠁢󠁥󠁮󠁧󠁿" sur D12, "🏴󠁧󠁢󠁳󠁣󠁴󠁿" sur E12. ibidem
			* Redonder sur la barre d’espace l’espace normale pour écrire en émojis. ibidem
			* Pallier le bogue de la colonne 02 en redondant dans la colonne 11, ou sur la touche après "N", les émojis lettres ou chiffre disposés sur les touches B02 (🇽⁠), C02 (🇸⁠), D02 (🇿⁠), E02 (2️⃣⁠). ibidem
			* Redonder les drapeaux de la France, de l’Union Européenne et des Nations Unies sur les touches B08, B09 et B10. kbfrFRs.C [5ed3aee](https://github.com/dispoclavier/nouvel-azerty/commit/5ed3aeee1011ce38fd23615533bbcc7fdf4072fa), kbfrFRsr.C [6a43fc4](https://github.com/dispoclavier/nouvel-azerty/commit/6a43fc48eba83f4ab22d3ef65e750017fd9ae837)
		* Niveaux (Maj +) AltQr : Redonder "𝐴" U+1D434.."𝑧" U+1D467, "𝟢" U+1D7E2.."𝟫" U+1D7EB. kbfrFRs.C [730f762](https://github.com/dispoclavier/nouvel-azerty/commit/730f76215002565795d3198c2ebf7e6bbb545581), kbfredis.C [0c097c4](https://github.com/dispoclavier/nouvel-azerty/commit/0c097c40e79a41834d804140b7030b331101d375)
		* Niveaux (Maj +) AltGr + AltQr : Redonder "𝔸" U+1D538.."𝕫" U+1D56B, "𝟘" U+1D7D8.."𝟡" U+1D7E1. ibidem
		* Niveaux (Maj +) AltFr + AltQr : Redonder "𝓐" U+1D4D0.."𝔃" U+1D503, "𝟶" U+1D7F6.."𝟿" U+1D7FF. ibidem
		* Niveaux (Maj +) AltGr + AltFr + AltQr : Redonder "𝗔" U+1D5D4.."𝘇" U+1D607, "𝟬" U+1D7EC.."𝟵" U+1D7F5. ibidem
		* Niveaux (AltGr +) AltEl + AltQr : Redonder "𝒜" U+1D49C.."𝓏" U+1D4CF, "𝟎" U+1D7CE.."𝟗" U+1D7D7. kbfrFRs.C [1363945](https://github.com/dispoclavier/nouvel-azerty/commit/136394566f4e27d3f29b3673c125ea38856af442), kbfredis.C [5bc3ad8](https://github.com/dispoclavier/nouvel-azerty/commit/5bc3ad89888cd0dd9c3be10230597447a7b902ec)
		* Niveaux au-dessus de 10 : Préparer pour la prise en charge d’émojis additionnels sur touches vives. kbfrFRs.C [5f0349e](https://github.com/dispoclavier/nouvel-azerty/commit/5f0349e1a347984578a7591ec741521ab1760eb5), kbfredis.C [762a7a7](https://github.com/dispoclavier/nouvel-azerty/commit/762a7a7be03980880e28b1c0f241af70404f32c1)
		* Touche échappement :
			* Niveau 5 : Ajouter le nom de la variante. kbfrFRs.C [f17bf4f](https://github.com/dispoclavier/nouvel-azerty/commit/f17bf4f0055aa836832c214e4c1e122c7c669a22), kbfredis.C [9b675ce](https://github.com/dispoclavier/nouvel-azerty/commit/9b675ce2710b45fd31add8f8996e1a9abe047c8a)
			* Niveau 6 : Ajouter le numéro de version. ibidem
* Composition : Ajouter « ¦d| » pour "‬" U+202C. compose-1.yml [e1e7e69](https://github.com/dispoclavier/nouvel-azerty/commit/e1e7e6933d618630cb0a6bf010500e2e92fabd18)
* Transformations :
	* Double accent aigu > Emojis rapides : Préparer pour la prise en charge d’émojis additionnels par touche morte. compose-2.yml [00222c4](https://github.com/dispoclavier/nouvel-azerty/commit/00222c4150cb16103a15344123e59479ff477c33), [b10174f](https://github.com/dispoclavier/nouvel-azerty/commit/b10174f270774e29970340cf3b42f8a14dbc2991), compose-3.yml [a907d8b](https://github.com/dispoclavier/nouvel-azerty/commit/a907d8b52e2b8028e56fb93763e9f80bd91afa2b), [dd1017c](https://github.com/dispoclavier/nouvel-azerty/commit/dd1017c76d2111c9baf4ff92dee0679c1821937a)
	* Drapeau :
		* Remplacer l’antiliant "‌" U+200C par le gluon "⁠" U+2060 derrière les lettres émojis. compose-2.yml [4d09722](https://github.com/dispoclavier/nouvel-azerty/commit/4d09722041e6559c0f548a125a7bb6a11e3df8fe)
		* Adapter à Windows la touche morte simple pour émettre les émojis lettres indicateurs régionaux sans gluon "⁠" U+2060. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
	* Drapeau > Étiquettes :
		* Ajouter les étiquettes minuscules U+E0061..U+E007A à la place de caractères d’usage privé sur les touches alphabétiques pour les drapeaux de subdivisions. compose-2.yml [3f11897](https://github.com/dispoclavier/nouvel-azerty/commit/3f11897053f470d1d01eb44c2ee732e79925b076)
		* Ajouter l’étiquette d’annulation U+E007F pour les drapeaux de subdivisions. ibidem
		* Ajouter les étiquettes capitales U+E0041..U+E005A et les étiquettes chiffres U+E0030..U+E0039 à la place de caractères d’usage privé sur les touches alphabétiques. ibidem
		* Compléter les étiquettes par l’étiquette espace U+E0020 et les étiquettes symboles et ponctuations. en synergie sur la barre d’espace. ibidem
		* Limiter la virgule aux équivalents en composition, et utiliser plutôt la césure conditionnelle en synergie sur la barre d’espace. ibidem
	* Drapeau > Émojis nationaux :
		* Ajouter "🏳" U+1F3F3 par "/". ibidem
		* Ajouter les drapeaux de l’Angleterre, de l’Écosse et du Pays de Galles. compose-2.yml [7551293](https://github.com/dispoclavier/nouvel-azerty/commit/755129326d948956a6ef324e98450d53bb2f14e3), [2e50ed6](https://github.com/dispoclavier/nouvel-azerty/commit/2e50ed6737904d319443342dccebb58a7a10b7b4)
	* Groupes des symboles : Groupes de "$" : Redonder "§" U+00A7 dans le groupe 10 à la place du saut de page U+000C FORM FEED, qui va dans le groupe 10 de "`" à la place de "‬" U+202C, qui est en composition. compose-3.yml [f2bf3f6](https://github.com/dispoclavier/nouvel-azerty/commit/f2bf3f68eb3161235a9a81be61c226855b49ea52)
* Variantes de disposition :
	* Variante redisposée de base : Aligner les noms de fichier sur les noms établis.
		* kbfredis.C devient kbfrFRsr.C. [730f0f9](https://github.com/dispoclavier/nouvel-azerty/commit/730f0f9d4889c363f30c6375347c4308b7c6fda8)
		* kbfredis.DEF devient kbfrFRsr.DEF. [e2dea1b](https://github.com/dispoclavier/nouvel-azerty/commit/e2dea1b3f8264a3c2741453957576c39c4f78a81)
		* kbfredis.H devient kbfrFRsr.H. [c685d07](https://github.com/dispoclavier/nouvel-azerty/commit/c685d073a528f02dcfca8403bc28f3c952da353b)
		* kbfredis.RC devient kbfrFRsr.RC. [84a648a](https://github.com/dispoclavier/nouvel-azerty/commit/84a648ac537988bae50f132c1f5e1bfc079a5f8d)
		* kbfredis.klc devient kbfrFRsr.klc. [a2da410](https://github.com/dispoclavier/nouvel-azerty/commit/a2da41057cd5ee795b41478bd1a92f04d484c1a5)
	* Sous-variantes :
		* Corriger les fichiers pour Linux et les mettre en ligne. evdev.c [20f6df1](https://github.com/dispoclavier/nouvel-azerty/commit/20f6df1504136fa544a60a9c2a2dce5fcf1c53c2), linux/chromeos/redispositions/evdev-ansi.c, evdev-ansi-menu.c, evdev-ansi-menu-sans.c, evdev-ansi-pur.c, evdev-ctrl.c, evdev-menu.c, evdev-menu-sans.c, evdev-win.c, evdev-win-sans.c [19b2ece](https://github.com/dispoclavier/nouvel-azerty/commit/19b2ece949e1de96cc2bd9f5c6191cf126ef71be), [5bc557e](https://github.com/dispoclavier/nouvel-azerty/commit/5bc557ef5a4ad8091a9072f6e5506690d59e232a), [9098687](https://github.com/dispoclavier/nouvel-azerty/commit/9098687b4bee70cf6029f59b7de3a68225075b20), [6865ae0](https://github.com/dispoclavier/nouvel-azerty/commit/6865ae028ea303b7ee0fa416b434e6105acdfe39)
		* Ajouter l’équivalent pour Windows. windows/redispositions/readme.md alias _Scancode_Map.txt [859528e](https://github.com/dispoclavier/nouvel-azerty/commit/859528eca5a6d43b5f828f6f315375162f76bd11), [7ca3436](https://github.com/dispoclavier/nouvel-azerty/commit/7ca3436c120f6d60ff84461c55831190ee3037bc), [40bea50](https://github.com/dispoclavier/nouvel-azerty/commit/40bea506488a325a7b789cfc55bfa6f3cd79c6eb), [6b2d0d4](https://github.com/dispoclavier/nouvel-azerty/commit/6b2d0d458f36338dc00dac75447e65928eec26de), [eeb4811](https://github.com/dispoclavier/nouvel-azerty/commit/eeb4811589389e8ca846ef8bb350a23f14eefd13), [964feb7](https://github.com/dispoclavier/nouvel-azerty/commit/964feb7fea816929436b39195e2875bbd0226350), [923d88a](https://github.com/dispoclavier/nouvel-azerty/commit/923d88a599b74229b95ff0135d6c94eb6c623924), [6dffbaf](https://github.com/dispoclavier/nouvel-azerty/commit/6dffbaf9c7796bbd0d2c80f450c1925b45b14364), [b1f81ad](https://github.com/dispoclavier/nouvel-azerty/commit/b1f81ad57704c481b045e403ba1d4644ff72dbcf), [8c03400](https://github.com/dispoclavier/nouvel-azerty/commit/8c03400541bc7bb78b822fbe1533920ce48b0343), windows/redispositions/annulation.reg, ansi-iso.reg, ansi-iso_menu=ret-arr_sans-menu.reg, ansi-iso_menu=x=ret-arr.reg, ansi-pur.reg, ctrl-dr=x=ret-arr.reg, menu=ret-arr_sans-menu.reg, menu=x=ret-arr.reg, win-dr=ret-arr.reg, win-dr=ret-arr_sans-menu.reg [1a46fc8](https://github.com/dispoclavier/nouvel-azerty/commit/1a46fc852dee5659bec5378a6622d6b2a25d96ae), [b3865f1](https://github.com/dispoclavier/nouvel-azerty/commit/b3865f1d63343884e744db3c78392bf5fc810e0a), [6a4c947](https://github.com/dispoclavier/nouvel-azerty/commit/6a4c947006073ef9888a99d1b14134b548cdbda3), [ed21663](https://github.com/dispoclavier/nouvel-azerty/commit/ed2166302fc7b33fe56bd06b70c7d4766469ad2d), [f58bb25](https://github.com/dispoclavier/nouvel-azerty/commit/f58bb25c905adde87a930f7e825612b903d2e594), [b84b94f](https://github.com/dispoclavier/nouvel-azerty/commit/b84b94f143e5ee8c67b9f6765fd5961c44fb69e5), [d9932ab](https://github.com/dispoclavier/nouvel-azerty/commit/d9932ab9621a4830ca11202689648de53164ed0a)
* Installation sous Windows :
	* Fichiers .klc :
		* Déboguer pour le Microsoft Keyboard Layout Creator (MSKLC). kbfrFRs.klc. [93980ca](https://github.com/dispoclavier/nouvel-azerty/commit/93980ca84d340f5b65749388f919e0fd5cda0893), kbfrFRsr.klc. [a2da410](https://github.com/dispoclavier/nouvel-azerty/commit/a2da41057cd5ee795b41478bd1a92f04d484c1a5)
		* Mettre à jour les dispositions de clavier dans le cadre pris en charge par le MSKLC. kbfrFRs.klc [7a85b5b](https://github.com/dispoclavier/nouvel-azerty/commit/7a85b5bbe45939618b57377080190748d20857d4), [9acf0bd](https://github.com/dispoclavier/nouvel-azerty/commit/9acf0bd48688ecb688d87ce5f141b52894a1bf44), [699e523](https://github.com/dispoclavier/nouvel-azerty/commit/699e523e57bc01ce00441a0375b345e904ba2c57), [2892264](https://github.com/dispoclavier/nouvel-azerty/commit/28922649df57a883e69f6bd5cbafc3e7fc8fb604), kbfrFRsr.klc [da98d04](https://github.com/dispoclavier/nouvel-azerty/commit/da98d042324b39e9008132f78845ba77f1af8ece), [09079d3](https://github.com/dispoclavier/nouvel-azerty/commit/09079d3543e22e9d8417bfc0dfec76a31a31b534), [9032142](https://github.com/dispoclavier/nouvel-azerty/commit/903214254b1ea9d4ffe337c272cf9fd21dbfce62), [ca9f9be](https://github.com/dispoclavier/nouvel-azerty/commit/ca9f9be9c09ca64b06c9e810a787e18e31814800)
		* Fournir la liste de noms français utilisée. ressource/MSKLC/readme.md [f5d1372](https://github.com/dispoclavier/nouvel-azerty/commit/f5d1372c6f553182e5ed9ee97c01bd97748ef867), nameslist.txt [3bf174c](https://github.com/dispoclavier/nouvel-azerty/commit/3bf174c31d42aef920a3152f774f3894b396def2)
* Personnalisation sous Windows :
	* Mettre en ligne le script de compilation revu, corrigé, mis à jour et désormais en UTF-8. windows/outils/creadispo.cmd [416474a](https://github.com/dispoclavier/nouvel-azerty/commit/416474acf550216599ac44445c612f0338304974)
	* Corriger le script. creadispo.cmd [e922a72](https://github.com/dispoclavier/nouvel-azerty/commit/e922a72afce2d9982fc90d1364159cef3bc99a9d), [31f44c7](https://github.com/dispoclavier/nouvel-azerty/commit/31f44c747ad3d640f904aec1cf43d751ef2a44b2), [dfdc733](https://github.com/dispoclavier/nouvel-azerty/commit/dfdc733a753bf98f8fe8c1b33586a8ee423ff2aa)
	* Ajouter l’indicateur d’ordre des octets par téléversement. creadispo.cmd [11138e8](https://github.com/dispoclavier/nouvel-azerty/commit/11138e81282c01f7eeaebaa2d4422c5d33068a94), [a3bb72c](https://github.com/dispoclavier/nouvel-azerty/commit/a3bb72cf65718a24922fc4b8ccda8be55b71660f)
	* Mettre à jour les informations sur la ListeNoms.txt. creadispo.cmd [410128a](https://github.com/dispoclavier/nouvel-azerty/commit/410128acfec9b75a0ce27255a4422b48f903f30f)
* Documentation :
	* Modes d’emploi :
		* Ultra-condensé : Sous Windows : Ajouter. windows/Démarrage-rapide.txt [6143fe0](https://github.com/dispoclavier/nouvel-azerty/commit/6143fe060f5c6beac7b41eb7d8695efd4959a254), [61ff63f](https://github.com/dispoclavier/nouvel-azerty/commit/61ff63ff4298998de34178678bfecddb0f4e6436)
		* Condensés :
			* Sous Linux : Mettre à jour. linux-chromeos/Lisez-moi-svp.txt [6cade34](https://github.com/dispoclavier/nouvel-azerty/commit/6cade34234e2190a2edcccb45459c5bdf1c8ab52), [f40b5f7](https://github.com/dispoclavier/nouvel-azerty/commit/f40b5f7b9855704e96ce65cf2be0468a8e3a4300), [396799d](https://github.com/dispoclavier/nouvel-azerty/commit/396799de0c3fcf75cd573b5069fa5ac2ba524cd2), [e7954fc](https://github.com/dispoclavier/nouvel-azerty/commit/e7954fc79d363958b96724f604bc1960684be3ea), [6a5b0b0](https://github.com/dispoclavier/nouvel-azerty/commit/6a5b0b0c79b5b14e8d619bd5bb3b4da7fc35dc05)
			* Sous Windows : Ajouter. windows/Lisez-moi-svp.txt [d99e2b5](https://github.com/dispoclavier/nouvel-azerty/commit/d99e2b59e766f4378371488dc29551f5a967931f), [b6ae8b9](https://github.com/dispoclavier/nouvel-azerty/commit/b6ae8b9eb37de8352bda885bb23ef1716321cb9f), [e5a9e90](https://github.com/dispoclavier/nouvel-azerty/commit/e5a9e9062918ac96cb16de575d80149792770961), [7f95b0e](https://github.com/dispoclavier/nouvel-azerty/commit/7f95b0e0516b8b332669271f3aa69a84af7be824), [add3647](https://github.com/dispoclavier/nouvel-azerty/commit/add364718fb6c50865e674393b879512cce74469), [aacf24d](https://github.com/dispoclavier/nouvel-azerty/commit/aacf24d2b1277dd67d929d5ce187bfaf07f7d35a), [61ff63f](https://github.com/dispoclavier/nouvel-azerty/commit/61ff63ff4298998de34178678bfecddb0f4e6436)
		* Détaillés :
			* Commun : readme.md alias Mode-d-emploi-commun.md [66bc697](https://github.com/dispoclavier/nouvel-azerty/commit/66bc697465aaf70fcd1d17944371d1b13064507b), [ccbaca1](https://github.com/dispoclavier/nouvel-azerty/commit/ccbaca16d9cf775d547d99652b772a88a1ef05e9)
			* Sous Linux : linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [2b43aaa](https://github.com/dispoclavier/nouvel-azerty/commit/2b43aaa8e0e21e8ea77219a8264da81d18fc0c45)
			* Sous Windows : windows/readme.md alias Mode-d-emploi-sous-Windows.md [4a8545f](https://github.com/dispoclavier/nouvel-azerty/commit/4a8545f672fb06df79465c1ac20170be1b94b3e7)
	* Corriger, compléter ou mettre à jour des annotations. compose-1.yml [e081f7a](https://github.com/dispoclavier/nouvel-azerty/commit/e081f7ad67386e2a1fc21c663a8f6f0ae7c6ebb1), compose-2.yml [1bf7c4e](https://github.com/dispoclavier/nouvel-azerty/commit/1bf7c4e344f333f30bd2848993aa91b028b5ec6d), compose-3.yml [d9eed3f](https://github.com/dispoclavier/nouvel-azerty/commit/d9eed3ff745cba72eb3c4f73b429dd4e6c864cfd), generate-deadkey-tables.pl [534188e](https://github.com/dispoclavier/nouvel-azerty/commit/534188e52c03eef6063c9bad60e583e0a26f1236), kbfrFRs.C [f04d39c](https://github.com/dispoclavier/nouvel-azerty/commit/f04d39c0525359698b613ea2d00ac308bcdaab83), kbfredis.C [9d7c86e](https://github.com/dispoclavier/nouvel-azerty/commit/9d7c86ef5c0383ddb97f085b8d284c87b2e1c6ad) ; kbfrFRs.C [6bf10f9](https://github.com/dispoclavier/nouvel-azerty/commit/6bf10f9b903831985b42a24784c9020bc0446647), kbfredis.C [1d3cb07](https://github.com/dispoclavier/nouvel-azerty/commit/1d3cb075796c999ee24b56b6fa52df73cab3d924) ; dead-key-convert.pl [9054983](https://github.com/dispoclavier/nouvel-azerty/commit/90549832378a5d28e8dbc8aa5ec621c9af6ff997), compose-1.yml [a24ba28](https://github.com/dispoclavier/nouvel-azerty/commit/a24ba28550bae595e179320e876a36f3d23a7767), compose-2.yml [abdc7f4](https://github.com/dispoclavier/nouvel-azerty/commit/abdc7f41a8f8fe2c04a6f99a84552b0bdb9ee2e0), compose-3.yml [d9cb5d5](https://github.com/dispoclavier/nouvel-azerty/commit/d9cb5d54eb3b825035197afeeb2389bc630a9cbc) ; compose-1.yml [513d3ea](https://github.com/dispoclavier/nouvel-azerty/commit/513d3ea43b4b4004d2cea4dbf34f48a5592e95e8), compose-2.yml [08f218f](https://github.com/dispoclavier/nouvel-azerty/commit/08f218fa4deec32cb2963dcbc4efe12da16ac7f8), compose-3.yml [5f86d61](https://github.com/dispoclavier/nouvel-azerty/commit/5f86d61a82d85bba51d2c049bd055062e20ebdb8) ; compose-1.yml [989cad9](https://github.com/dispoclavier/nouvel-azerty/commit/989cad914395318312d4ce8a13d90822673e49b2), [331bd5b](https://github.com/dispoclavier/nouvel-azerty/commit/331bd5b78161192669af669d5f88204397a413fb), compose-2.yml [12e052f](https://github.com/dispoclavier/nouvel-azerty/commit/12e052f948bb29b704c1458b72f0f5b8e5c03442), [90b0dc7](https://github.com/dispoclavier/nouvel-azerty/commit/90b0dc73ed5de34bf5755888c5ec0c4d5761aac5), compose-3.yml [a362a62](https://github.com/dispoclavier/nouvel-azerty/commit/a362a62453b577d13bb20b75e527f10d7caa89b1) ; evdev.c [6c1a939](https://github.com/dispoclavier/nouvel-azerty/commit/6c1a9394e0e2fa7d80e2261c43e05eb8bbe13795), kbfrFRs.C [4934f1d](https://github.com/dispoclavier/nouvel-azerty/commit/4934f1d21f6c9895a6e52843de545aeb0df6e38e), kbfredis.C [0068f28](https://github.com/dispoclavier/nouvel-azerty/commit/0068f2843dc9cb4d76e6d84f67c958fc6cb5108e), kbfrFRs.klc [7d2f79f](https://github.com/dispoclavier/nouvel-azerty/commit/7d2f79f423403852240c3d0dccceac2883e2a5b9), kbfredis.klc [446d89d](https://github.com/dispoclavier/nouvel-azerty/commit/446d89df4a835d98493a2317be7d90cd50624f9a) ; kbfrFRs.C [a24e8fe](https://github.com/dispoclavier/nouvel-azerty/commit/a24e8feb9d9ff084e8a1c401a1fd7168e1d37762), kbfredis.C [393e334](https://github.com/dispoclavier/nouvel-azerty/commit/393e33490287fc3485be98069983c4b35554e6a0)
	* Simplifier les annotations. dead-key-convert.pl [e0d0479](https://github.com/dispoclavier/nouvel-azerty/commit/e0d047907061bbbd509a4f724d6ac4f2d7dae303), kbfrFRs.C [3689891](https://github.com/dispoclavier/nouvel-azerty/commit/36898916c864988b53035ef0f344b370a9a570bf), kbfredis.C [5e90ac4](https://github.com/dispoclavier/nouvel-azerty/commit/5e90ac4c49895eab430bbc6021184bed08601a62)
	* Améliorer la présentation du contenu des touches mortes. dead-key-convert.pl [99ab07b](https://github.com/dispoclavier/nouvel-azerty/commit/99ab07b1ca6ea0d638b9955ae228ce6f10ae5912), [d5585fe](https://github.com/dispoclavier/nouvel-azerty/commit/d5585fea0cfea5fc9b1722d6f9498496429661cd), kbfrFRs.C [85240b2](https://github.com/dispoclavier/nouvel-azerty/commit/85240b2d66ca768e8a91183c1874483c015e1e18), [a5f285a](https://github.com/dispoclavier/nouvel-azerty/commit/a5f285a873d1d663938692971517727358a62dc2), kbfredis.C [b0b4cd7](https://github.com/dispoclavier/nouvel-azerty/commit/b0b4cd79e5f5125e58c5ccef567f5655c2b088eb), [96196a7](https://github.com/dispoclavier/nouvel-azerty/commit/96196a75b487286974e7c4705691bebc36a27dd4)
	* Corriger des fautes de vocabulaire et des non-transpilations écrasées. kbcommon.H [689f5d2](https://github.com/dispoclavier/nouvel-azerty/commit/689f5d20632cbfcf42ea3cc78aa7eb447d2b2111), kbfrFRs.H [8202bdd](https://github.com/dispoclavier/nouvel-azerty/commit/8202bddcee202484a2547f243255a026b1022406), kbfrFRsr.H [da04c6c](https://github.com/dispoclavier/nouvel-azerty/commit/da04c6ced5916138c0dbf6c7560f4ba3e6eef08c)
	* Compléter les métadonnées. kbfrFRs.RC [a658ab4](https://github.com/dispoclavier/nouvel-azerty/commit/a658ab4569b06b51340ce271c805e9617e30a020), kbfrFRsr.RC [9edf2cd](https://github.com/dispoclavier/nouvel-azerty/commit/9edf2cdea23c5ecc12010bb55ebc53b396215698)
	* Ajouter une note légale. NOTICE.txt [447faee](https://github.com/dispoclavier/nouvel-azerty/commit/447faeeb9a02556402b4aaf039ced63706a129da), [a5e2933](https://github.com/dispoclavier/nouvel-azerty/commit/a5e29331068602d67a362463d52206174c5be566)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai.

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des touches mortes enchaînées et de la touche de composition est basé sur la précédente implémentation.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/5.3.0/Un-nouvel-AZERTY-Windows-5.3.0.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « Démarrage-rapide.txt » ou dans « Lisez-moi-svp.txt ».

### Linux

Dans les dernières versions de Linux, il faut s’attendre à ce que le commutateur de dispositions de clavier est bogué ; mais en n’utilisant qu’une seule disposition, il n’y a pas de problème, comme expliqué dans le [mode d’emploi sous Linux sous le titre « Installation »](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation).

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/5.3.0/Un-nouvel-AZERTY-Linux-5.3.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/5.3.0/Un-nouvel-AZERTY-Linux-5.3.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

Puis fermer la session et en rouvrir une. 

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier « Français (France) » sous le nom « Français France disposition de clavier semi-automatique » et peut être ajouté aux dispositions actives. Afin de l’activer, il est devenu nécessaire de désactiver l’autre disposition.

Les variantes AZERTY s’appellent :

* Breton et français disposition de clavier semi-automatique
* Polynésie Française disposition de clavier semi-automatique
* Afrique francophone disposition de clavier semi-automatique
* Français Belgique disposition de clavier semi-automatique

Les variantes redisposées QZJFGY s’appellent :

* Français France disposition de clavier semi-automatique redisposée
* Breton et français disposition de clavier semi-automatique redisposée
* Polynésie française disposition de clavier semi-automatique redisposée
* Afrique francophone disposition de clavier semi-automatique redisposée

La variante belge ne se décline pas en variante redisposée parce que l’intérêt d’avoir une variante belge, c’est une assez bonne rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

Les vues de disposition se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues. Les rectangles avec un code sont des touches mortes ou des séquences, définies dans le répertoire des touches mortes et des séquences Compose(.yml).

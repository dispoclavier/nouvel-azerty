# Journal des modifications

Pour assurer l’affichage d’un maximum de caractères, il est nécessaire d’avoir [installé des polices complètes](https://support.microsoft.com/fr-fr/office/ajouter-une-police-b7c5f17c-4426-4b53-967f-455339c564c1) : [BabelStone Han](https://www.babelstone.co.uk/Fonts/Han.html), [Code2000](https://en.wikipedia.org/wiki/Code2000), [DejaVu](https://en.wikipedia.org/wiki/DejaVu_fonts) ([Font Squirrel](https://www.fontsquirrel.com/fonts/dejavu-sans)), Kelvinch (mise à jour 2017 ; [1001 Fonts](https://www.1001fonts.com/kelvinch-font.html)), Nishiki-teki (mise à jour 2022 ; [Fontspace](https://www.fontspace.com/nishiki-teki-font-f86893)).

Le deux-barrettes "¦" U00A6 (barre brisée, barre discontinue, barre déjointe, barre à trou) représente la touche de composition "⎄" U2384. Les séquences de composition sont entre guillemets français pour la lisibilité : « ¦mul », « ¦MUL », « ¦!^ », « ¦:\ », « ¦#1: », « ¦¦ ».

## 5.5.0 (projet)

Mise à jour sous macOS des dispositions émulées selon Linux.

## 5.4.0 (projet)

Reconception, rectification et simplification des séquences de composition. [compose-1.yml [b0e5711](https://github.com/dispoclavier/nouvel-azerty/commit/b0e57112d96f30bdeb5bea8cbcb9258955106059)]

Réimplémentation des touches mortes enchaînées diacritiques ou transformationnelles sous Windows sur le modèle finalisé sous Linux.

Réimplémentation de la touche de composition sous Windows sur le modèle finalisé sous Linux.

## 5.3.0 (projet)

Prise en charge des drapeaux et des émojis lettres sur touches vives sous Windows.

Débogage de la touche morte drapeau sous Windows.

Prise en charge de tous les drapeaux régionaux par une touche morte dédiée sous Linux et au niveau 10 sous Windows.

* Disposition :
	* Niveau 9 :
		* Redonder les émojis lettres indicateurs régionaux "🇦" U1F1E6 .. "🇿" U1F1FF sur les touches alphabétiques. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
		* Redonder les émojis chiffres "0️⃣".."9️⃣" et l’émoji touche de téléphone "*️⃣" sur les premières touches de la rangée E. ibidem
		* Ajouter "🟰" U1F7F0 sur E12 où il est imprimé. ibidem
		* Ajouter "💲" U1F4B2 sur D12 où il est imprimé. ibidem
		* Redonder "*️⃣" sur C12 où il est imprimé. ibidem
		* Redonder "#️⃣" sur C11 pour compléter la nouvelle dispositon des émojis touches de téléphone. ibidem
		* Ajouter "🏳" U1F3F3 sur la touche "/" B09. kbfrFRs.C [3299c32](https://github.com/dispoclavier/nouvel-azerty/commit/3299c322f1a2432bbb8d308e496ab89e325af2af), [0f620d6](https://github.com/dispoclavier/nouvel-azerty/commit/0f620d6ee3870983706080ffaddd01c4628ba322), kbfredis.C [7bd66c5](https://github.com/dispoclavier/nouvel-azerty/commit/7bd66c5ca3854bcadc7365ad2c9d359603da0400)
		* Redonder "🏴" U1F3F4 sur la touche "\" B10. ibidem
		* Redonder le gluon "⁠" U2060 sur la barre d’espace pour écrire en émojis lettres. kbfrFRs.C [f04d39c](https://github.com/dispoclavier/nouvel-azerty/commit/f04d39c0525359698b613ea2d00ac308bcdaab83), kbfredis.C [9d7c86e](https://github.com/dispoclavier/nouvel-azerty/commit/9d7c86ef5c0383ddb97f085b8d284c87b2e1c6ad)
	* Niveau 10 :
		* Redonder les émojis lettres avec gluon pour écrire en émojis, plutôt que les étiquettes minuscules pour composer des drapeaux régionaux (dont les 3 seuls sont sur (C..E)12). ibidem
		* Redonder sur la barre d’espace l’espace normale pour écrire en émojis. ibidem
		* Pallier le bogue de la colonne 02 en redondant dans la colonne 11 ou sur les touches après "N" les émojis lettres ou chiffre disposés sur les touches B02 (🇽⁠), C02 (🇸⁠), D02 (🇿⁠), E02 (2️⃣⁠). ibidem
* Transformations :
	* Drapeau : Adapter à Windows la touche morte simple pour émettre les émojis lettres indicateurs régionaux sans antiliant. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
	* Drapeau > Étiquettes :
		* Ajouter les étiquettes minuscules UE0061..UE007A à la place de caractères d’usage privé sur les touches alphabétiques pour les drapeaux de subdivisions. compose-2.yml [3f11897](https://github.com/dispoclavier/nouvel-azerty/commit/3f11897053f470d1d01eb44c2ee732e79925b076)
		* Ajouter l’étiquette d’annulation UE007F pour les drapeaux de subdivisions. ibidem
		* Ajouter les étiquettes capitales UE0041..UE005A et les étiquettes chiffres UE0030..UE0039 à la place de caractères d’usage privé sur les touches alphabétiques. ibidem
		* Compléter les étiquettes par l’étiquette espace UE0020 et les étiquettes symboles et ponctuations. en synergie sur la barre d’espace. ibidem
		* Limiter la virgule aux équivalents en composition, et utiliser plutôt la césure conditionnelle en synergie sur la barre d’espace. ibidem
	* Drapeau > Émojis nationaux :
		* Ajouter "🏳" U1F3F3 par "/". ibidem
		* Ajouter les drapeaux de l’Angleterre, de l’Écosse et du Pays de Galles. compose-2.yml [7551293](https://github.com/dispoclavier/nouvel-azerty/commit/755129326d948956a6ef324e98450d53bb2f14e3)
* Documentation : Corriger ou compléter des annotations. ibidem, compose-1.yml [e081f7a](https://github.com/dispoclavier/nouvel-azerty/commit/e081f7ad67386e2a1fc21c663a8f6f0ae7c6ebb1), compose-2.yml [1bf7c4e](https://github.com/dispoclavier/nouvel-azerty/commit/1bf7c4e344f333f30bd2848993aa91b028b5ec6d), compose-3.yml [d9eed3f](https://github.com/dispoclavier/nouvel-azerty/commit/d9eed3ff745cba72eb3c4f73b429dd4e6c864cfd), generate-deadkey-tables.pl [534188e](https://github.com/dispoclavier/nouvel-azerty/commit/534188e52c03eef6063c9bad60e583e0a26f1236), kbfrFRs.C [f04d39c](https://github.com/dispoclavier/nouvel-azerty/commit/f04d39c0525359698b613ea2d00ac308bcdaab83), kbfredis.C [9d7c86e](https://github.com/dispoclavier/nouvel-azerty/commit/9d7c86ef5c0383ddb97f085b8d284c87b2e1c6ad)

## 5.2.0 (2025-06-15)

Réimplémentation des touches mortes simples diacritiques ou transformationnelles sous Windows sur le modèle finalisé sous Linux.

Meilleure prise en charge des demi-codets hauts.

Simplification et complétion des touches mortes sous Linux.

Prise en charge d’un émoji supplémentaire sur touche vive.

* Disposition :
	* Ajouter "🙂" U1F642 sur AltGr + AltFr + S à la place de "§" U00A7, qui est sur sa touche historique B10. dispocla.cpp [8109e39](https://github.com/dispoclavier/nouvel-azerty/commit/8109e3963de158c46d85221115c85cef740a5106), kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), kbfredis.klc [1053c20](https://github.com/dispoclavier/nouvel-azerty/commit/1053c201fe9799b122c0e7c0bacb4e1eba4e2fe6), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), nouvel-azerty.json [8a5bc2b](https://github.com/dispoclavier/nouvel-azerty/commit/8a5bc2b3daecaf1603fd9cc3977c2baa1c5b83d4), [da1531d](https://github.com/dispoclavier/nouvel-azerty/commit/da1531d797674e522fc2591443523a69ddebdae6), nouvel-azerty-verrcap.json [8267eee](https://github.com/dispoclavier/nouvel-azerty/commit/8267eee327bd4223f220771f7d10db6cfb0785e0), [f0acf71](https://github.com/dispoclavier/nouvel-azerty/commit/f0acf718993293dc7a90c2e22402882c2d6142c6), nouvel-azerty-verrmod.json [155b470](https://github.com/dispoclavier/nouvel-azerty/commit/155b4700633c6d34b6fd7291aa42cbb66ab156a1), [272e1b1](https://github.com/dispoclavier/nouvel-azerty/commit/272e1b1e88d053a1344f968d691ee4addb696ede), nouvel-azerty-verrmod-verrcap.json [0362a5a](https://github.com/dispoclavier/nouvel-azerty/commit/0362a5a822f37001fa5d8e5e086eb0d290778f23), [37a385e](https://github.com/dispoclavier/nouvel-azerty/commit/37a385e38f651620d9bdbc5675f5997c141dff42)
	* Changer le caractère mort de la touche morte groupe de "²" U00B2 en "①" U2460. kbfredis.klc [13e3cd6](https://github.com/dispoclavier/nouvel-azerty/commit/13e3cd6c9b034d914dfa24768c1221c90b9b8465), kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95)
	* Changer le caractère mort de la touche morte cédille de "ȩ" U0229 en "ç" U00E7. kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), kbfredis.klc [1053c20](https://github.com/dispoclavier/nouvel-azerty/commit/1053c201fe9799b122c0e7c0bacb4e1eba4e2fe6), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), dead-key-convert.pl [bc8d230](https://github.com/dispoclavier/nouvel-azerty/commit/bc8d2303cf88146c294391de05cd8aa9081b1140)
* Transformations :
	* Émulation de touche "Ê" : Compléter le digramme "êq" en trigramme "êqu". compose-2.yml [bd2cbcb](https://github.com/dispoclavier/nouvel-azerty/commit/bd2cbcbfc7c2d8f7c996e30f60bf7c935e6c664e)
	* Atténuer la disruption de l’expérience utilisateur entre Linux/macOS et Windows en matière d’émulation de touches "Ê" et "Ç". kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), [97701e0](https://github.com/dispoclavier/nouvel-azerty/commit/97701e0eb410ca910fd485db3b0163fdc3add50c), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), [75ab534](https://github.com/dispoclavier/nouvel-azerty/commit/75ab53455834b4342c7035f3df3b394a1e04e528)
	* Convertir les touches mortes simples d’XCompose en C. dead-key-convert.pl [58d3c22](https://github.com/dispoclavier/nouvel-azerty/commit/58d3c2294dead063d317747af194fb67d0ae01ed), kbfredis.C [e2062be](https://github.com/dispoclavier/nouvel-azerty/commit/e2062be76f506149c71f61197e810e791da730dc), kbfrFRs.C [0563872](https://github.com/dispoclavier/nouvel-azerty/commit/05638729cb98e370a4d54b4df30d2dd425069011)
	* Prendre en charge les demi-codets hauts. dead-key-convert.pl [228e8de](https://github.com/dispoclavier/nouvel-azerty/commit/228e8de2dfd811d20843709cd7a4f6dd656608e6), [ad8fcb3](https://github.com/dispoclavier/nouvel-azerty/commit/ad8fcb3e1c7c8b3f7cf140fa51afc9e7bb1b8986), [28b1f18](https://github.com/dispoclavier/nouvel-azerty/commit/28b1f18fea37267e3300b5528c9d6a014c8701a2), [1337c45](https://github.com/dispoclavier/nouvel-azerty/commit/1337c45f970d465ed5357053dbbd13fd98fd8333), [7dc449d](https://github.com/dispoclavier/nouvel-azerty/commit/7dc449d71fa63a9f6cab651b1f653cdab5709f87), [5dabd2a](https://github.com/dispoclavier/nouvel-azerty/commit/5dabd2a39e8847c89f3ac38514e162ba16482fcf), kbfredis.C [c7f17d4](https://github.com/dispoclavier/nouvel-azerty/commit/c7f17d407333cab18f59d9b7ccd4a90ea1f01fe1), [bce4e8f](https://github.com/dispoclavier/nouvel-azerty/commit/bce4e8ff153c2e142c3a313a4821fe509768ad5a), [6b3445a](https://github.com/dispoclavier/nouvel-azerty/commit/6b3445a8dcf48b057b9c16927f1fa885821f0697), [5ddca95](https://github.com/dispoclavier/nouvel-azerty/commit/5ddca95c07f2a6f6ca06066a1805f8314f230c6c), kbfrFRs.C [0563872](https://github.com/dispoclavier/nouvel-azerty/commit/05638729cb98e370a4d54b4df30d2dd425069011), [dcc9e7b](https://github.com/dispoclavier/nouvel-azerty/commit/dcc9e7b6926ef3a412333f8c82163f78f75c6bfe), [7fcc8e1](https://github.com/dispoclavier/nouvel-azerty/commit/7fcc8e14be3892752be14afb7825720c18b3c6ac)
	* Simplifier la saisie de "𐞍" U1078D, "𐞔" U10794, "𐞜" U1079C, "𐞝" U1079D, "𐞡" U107A1, "𐞢" U107A2, "𐞧" U107A7, "𐞴" U107B4. compose-2.yml [f65ce6e](https://github.com/dispoclavier/nouvel-azerty/commit/f65ce6e0983576c1489a2df9af72323b6367105c)
	* Accent circonflexe groupe 2 : Prendre en charge "🙶" U1F676. ibidem
	* Accent aigu groupe 2 : Prendre en charge "🙷" U1F677. ibidem
	* Tréma : 
		* Groupe 2 : Prendre en charge "🙸" U1F678. ibidem
		* Supprimer le demi-codet haut UD835 des symboles mathématiques alphanumériques. ibidem
	* Drapeau : Supprimer le demi-codet haut UD835 des symboles mathématiques alphanumériques. ibidem
	* Groupes 11 et 12 : Améliorer la prise en charge du demi-codet haut UD83E des flèches. ibidem
* Documentation :
	* Corriger et compléter les modes d’emploi. readme.md alias Mode-d-emploi-commun.md [bdc4fb2](https://github.com/dispoclavier/nouvel-azerty/commit/bdc4fb2a3154765ce199a13ecb8ad06a1954184d), [bba3dfb](https://github.com/dispoclavier/nouvel-azerty/commit/bba3dfbd8af043d7f89c9857ba5a2a8e47844762), [f69bb7e](https://github.com/dispoclavier/nouvel-azerty/commit/f69bb7e8a6d29f9bfea080be5946e42b20918bf6), [4193fae](https://github.com/dispoclavier/nouvel-azerty/commit/4193faed977af52630c8a2381455c45b6c2b8f9f), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [efc166f](https://github.com/dispoclavier/nouvel-azerty/commit/efc166f66eb0370739b37d58ee253266b28030ba), [dc88756](https://github.com/dispoclavier/nouvel-azerty/commit/dc88756ff6bb08399fb7e45a19fe169d1bd7225c), [9ba26bb](https://github.com/dispoclavier/nouvel-azerty/commit/9ba26bb204933c3ee79cb6274e179b899cc95011), windows/readme.md alias Mode-d-emploi-sous-Windows.md [dcf4231](https://github.com/dispoclavier/nouvel-azerty/commit/dcf423167fa52a6ae0b1875bf68b846817e2ae46), [26b72c1](https://github.com/dispoclavier/nouvel-azerty/commit/26b72c16effdfa745cf4130f787845bb3c360425), [4d33148](https://github.com/dispoclavier/nouvel-azerty/commit/4d33148d594dec3d1a5365e4088a4d2b36f61a9e), [ed4c8af](https://github.com/dispoclavier/nouvel-azerty/commit/ed4c8af3f0e9d0a65e96c09b18e0fe00b8b11a0b), [d0ee7a6](https://github.com/dispoclavier/nouvel-azerty/commit/d0ee7a6833497a2d4880f53c3671dd51b3f3a76f)
	* Documenter le bogue de la touche C11 de l’AZERTY. windows/readme.md alias Mode-d-emploi-sous-Windows.md [26b72c1](https://github.com/dispoclavier/nouvel-azerty/commit/26b72c16effdfa745cf4130f787845bb3c360425), kbfrFRs.C [c22acd3](https://github.com/dispoclavier/nouvel-azerty/commit/c22acd3fab99782947ef3e14e8893476935325b4)
	* Corriger, ajouter ou supprimer des annotations. compose-2.yml [f65ce6e](https://github.com/dispoclavier/nouvel-azerty/commit/f65ce6e0983576c1489a2df9af72323b6367105c), compose-3.yml [c09300d](https://github.com/dispoclavier/nouvel-azerty/commit/c09300d79e9406cb9bed8bf72ec1119e7c90453c) ; compose-2.yml [f4eb2bc](https://github.com/dispoclavier/nouvel-azerty/commit/f4eb2bc4e0828917eafe871d824c3bd42bad66d1), dead-key-convert.pl [8d0987c](https://github.com/dispoclavier/nouvel-azerty/commit/8d0987c33a7dc36237092fb1e1737dc8c300bef5) ; compose-1.yml [afeb2ce](https://github.com/dispoclavier/nouvel-azerty/commit/afeb2ce1b2c2065174cfc6e89dae479296491460), compose-2.yml [c2f05e7](https://github.com/dispoclavier/nouvel-azerty/commit/c2f05e7da4370487b2a050b44a8755e9813f914d), dispocla.cpp [4570f8f](https://github.com/dispoclavier/nouvel-azerty/commit/4570f8fae107ea293c7f15aa57adb6335a9cdbf6) ; compose-1.yml [0bb900d](https://github.com/dispoclavier/nouvel-azerty/commit/0bb900d75abab74dfd6cad47f5a9a19b9e71207e), compose-2.yml [172f57e](https://github.com/dispoclavier/nouvel-azerty/commit/172f57e4f59c54a6065739529c973c2f806feb71)
	* Améliorer le tri. compose-1.yml [caf2515](https://github.com/dispoclavier/nouvel-azerty/commit/caf25150addfc74c11cb4696d3ac824fa14f6725) ; (Éviter de changer les keysyms d’XKB.) compose-1.yml [8755bd8](https://github.com/dispoclavier/nouvel-azerty/commit/8755bd8fb3a5558cfa491acd49b8fc5d33a69e60)

## 5.1.0 (2025-05-29)

Mise à jour de la prise en charge des émojis suite à la mise à jour de la [page d’Unicode sur les fréquences](https://home.unicode.org/emoji/emoji-frequency/).

Rétablissement de la symétrie des enchaînements de touches mortes suite à la dissociation de celles-ci avec leur équivalent en composition.

Complétion des touches mortes grâce à cet allègement des contraintes.

Rectification et amélioration des groupes des symboles.

Reconception, rectification et simplification de séquences de composition.

* Disposition :
	* Prendre en charge "🥰" U1F970 sur B05 "B", niveau 8, à la place de "💕" U1F495. dispocla.cpp [88719a8](https://github.com/dispoclavier/nouvel-azerty/commit/88719a8cb290420dc871370eb3fa144d8c2087c8), kbfrFRs.klc [96950df](https://github.com/dispoclavier/nouvel-azerty/commit/96950dfbd1209398d6c02688b381c1461179f712), kbfrFRs.C [0c294ff](https://github.com/dispoclavier/nouvel-azerty/commit/0c294ff80c6591b9288255121bd84155229ca127), kbfredis.klc [5f45c24](https://github.com/dispoclavier/nouvel-azerty/commit/5f45c24d25c41d38379078a38cce830a3a34efc8), kbfredis.C [77e3126](https://github.com/dispoclavier/nouvel-azerty/commit/77e312667408bae9d2a8194f19a0d9348ff3f863)
	* Windows : Rectifier la touche D07, niveau 3, en redondant l’apostrophe "'" au lieu de la touche de composition. kbfrFRs.klc [e16f4bb](https://github.com/dispoclavier/nouvel-azerty/commit/e16f4bb5bad199136d7855ec46b02ececfde29b6), kbfrFRs.C [42d2fb2](https://github.com/dispoclavier/nouvel-azerty/commit/42d2fb21885b67775c19db38285609d0dffb0736), kbfredis.klc [c6e29fe](https://github.com/dispoclavier/nouvel-azerty/commit/c6e29fe9b7accb1382276f1e29208e453a534f66), kbfredis.C [5a234ba](https://github.com/dispoclavier/nouvel-azerty/commit/5a234bac99b16623547ca2e33a00265c95e56be1)
* Composition :
	* Prendre en charge les filets "─" U2500.."╿" U257F. compose-1.yml [2d9fe01](https://github.com/dispoclavier/nouvel-azerty/commit/2d9fe018da074d60c5f40d6a57798d0df83650cd), [184dcaa](https://github.com/dispoclavier/nouvel-azerty/commit/184dcaae7988e1816792983ec2b0dd4caa61e265)
	* Prendre en charge "ꜗ" UA717, "ꜘ" UA718, "ꜙ" UA719, "ꜚ" UA71A, qui sont dans point en chef (sans composition) et dans cornu. compose-1.yml [20cfb06](https://github.com/dispoclavier/nouvel-azerty/commit/20cfb0651da809faed004af544be7ff89999572a)
	* Redonder les guillemets "‘" U2018, "’" U2019, "‚" U201A, "“" U201C, "”" U201D, "„" U201E. compose-1.yml [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18)
	* Redonder le point médian "·" U00B7, qui était dans point en chef. ibidem
	* Rectifier les séquences de "⫡" U2AE1. ibidem
	* Améliorer la prise en charge de "⨣" U2A23. compose-1.yml [986a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/986a2e86a3d87150ea7d30af36409eaef4db8748)
	* Redonder "¦" U00A6 par double frappe de la touche de composition. ibidem
	* Simplifier les séquences de "⪁" U2A81, "⪂" U2A82. compose-1.yml [0f40ccf](https://github.com/dispoclavier/nouvel-azerty/commit/0f40ccf4ac4f8ab9e5bc3cd7fcad35b1497eba80)
	* Simplifier, améliorer ou corriger les séquences de "↨" U21A8, "↩" U21A9, "↪" U21AA, "↬" U21AC, "↭" U21AD, "↮" U21AE, "↯" U21AF, "↰" U21B0, "↶" U21B6, "↷" U21B7, "↽" U21BD, "↾" U21BE, "↿" U21BF, "⇀" U21C0, "⇁" U21C1, "⇂" U21C2, "⇃" U21C3, "⇄" U21C4, "⇅" U21C5, "⇆" U21C6, "⇇" U21C7, "⇈" U21C8, "⇉" U21C9, "⇊" U21CA, "⇋" U21CB, "⇌" U21CC, "⇎" U21CE, "⇏" U21CF, "⇚" U21DA, "⇥" U21E5, "⇵" U21F5, "⇶" U21F6, "⇷" U21F7, "⇸" U21F8, "⇹" U21F9, "⇺" U21FA, "⇼" U21FC, "⇿" U21FF. compose-1.yml [c856506](https://github.com/dispoclavier/nouvel-azerty/commit/c856506ff3f3e740949ee6b03413d2354dafc272), compose-2.yml [b72a8e5](https://github.com/dispoclavier/nouvel-azerty/commit/b72a8e5752e39e1c82c920dacdd54b93ca145ef7)
	* Prendre en charge "﬩" UFB29 en tant que symbole mathématique. ibidem
	* Compléter ou rectifier les séquences de "¡" U00A1, "•" U2022, "‣" U2023, "∎" U220E, "▪" U25AA, "▮" U25AE, "▴" U25B4, "▵" U25B5, "▾" U25BE, "▿" U25BF, "◂" U25C2, "◦" U25E6, "☆" U2606. compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7)
	* Simplifier, améliorer ou corriger les séquences de "∉" U2209, "∊" U220A, "∌" U220C, "∍" U220D, "∙" U2219, "√" U221A, "∛" U221B, "∜" U221C, "∝" U221D. ibidem
* Transformations :
	* Rétablir la symétrie des enchaînements de touches mortes, suite à la dissociation des équivalents en composition. compose-2.yml [c32ffcc](https://github.com/dispoclavier/nouvel-azerty/commit/c32ffcc62ad3ff8ae66897924d31ab01730d9e91), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Accent circonflexe et accent aigu : Idem. compose-2.yml [63745d3](https://github.com/dispoclavier/nouvel-azerty/commit/63745d31059ee53796f7f93a7515f14a08729b95), [d2a4a05](https://github.com/dispoclavier/nouvel-azerty/commit/d2a4a059bd8e421dc473ca835838ed331f66ab7a), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Tréma et accent aigu : Idem. ibidem
		* Grec-ou-cerclé et tréma et accent aigu : Idem. compose-1.yml [1230ef2](https://github.com/dispoclavier/nouvel-azerty/commit/1230ef2da60b5ffcb573bbd8b56678122554cbb6), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18)
		* Grec-ou-cerclé et tréma et tonos : Idem. ibidem
		* Exposant et tourné et brève : Idem. compose-2.yml [19b1f60](https://github.com/dispoclavier/nouvel-azerty/commit/19b1f603bbe7e0f0f88e0a94063d1bbfe967f216), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Exposant et réfléchi et rayé : Idem. ibidem
		* Exposant et crochet rétroflexe et brève : Idem. ibidem
		* Exposant et brève : Idem. ibidem
		* Exposant et rayé : Idem. ibidem
		* Exposant et petite capitale et brève : Idem. ibidem
		* Exposant et petite capitale et rayé : Idem. ibidem
		* Indice et brève : Idem. ibidem
		* Indice et rayé : Idem. ibidem
	* Exposant : Désactiver l’équivalent en composition de "⁺" U207A, "⁻" U207B, "⁾" U207E, en composition en tant que symboles mathématiques. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89), [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
	* Tourné : Améliorer la prise en charge de "⸸" U2E38. compose-2.yml [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416)
	* Réfléchi :
		* Prendre en charge "⮈" U2B88 par "_" dans les groupes 0, 1 et 12, par rapport à "⮊" U2B8A dans le groupe 12 de "\_". compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "⦰" U29B0 par "}". compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Tilde :
		* Redonder "⧤" U29E4. ibidem
		* Caractère de base ASCII de "͠" U0360 : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Grec-ou-cerclé :
		* Redonder "⊚" U229A, "⊝" U229D, "⦶" U29B6, "⧀" U29C0, "⧁" U29C1, "⨸" U2A38 sans les équivalents en composition. compose-2.yml [5a00d53](https://github.com/dispoclavier/nouvel-azerty/commit/5a00d539548302c022f9277a0a989bfc5863ce8c), [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00), [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Ajuster la prise en charge de "⊗" U2297. compose-2.yml [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00)
		* Ajuster la prise en charge du chiffre zéro "⓪" U24EA, "⓿" U24FF, "🄋" U1F10B, "🄌" U1F10C. compose-2.yml [fa15571](https://github.com/dispoclavier/nouvel-azerty/commit/fa15571a7e0dfe12fa467fbd4955b8082f004984), [c0d9932](https://github.com/dispoclavier/nouvel-azerty/commit/c0d9932181bfc7c1875f77577f387710bae4e173), [7f1e8e5](https://github.com/dispoclavier/nouvel-azerty/commit/7f1e8e5733dd6517d63bf705d5df9cde7d4ac156), [fe9fa01](https://github.com/dispoclavier/nouvel-azerty/commit/fe9fa017586b55c94fdfbd2a2995fedf4685f391)
		* Cerclé : Redonder "⦸" U29B8. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
		* Couleur inversée :
			* Permuter les lettres cerclées, désormais par minuscule, et encadrées, désormais par capitale. compose-2.yml [c4d9ef4](https://github.com/dispoclavier/nouvel-azerty/commit/c4d9ef462a88137b9a99aaa2719c48c34cd09c00)
			* Simplifier la prise en charge des nombres "⓫" U24EB.."⓴" U24F4. compose-2.yml [8eb991a](https://github.com/dispoclavier/nouvel-azerty/commit/8eb991aaa243edeefcb8fff07ae622d3ef050f28)
		* Nombre cerclé : Limiter aux nombres de 11 à 20 et supprimer "㉑" U3251.."㊿" U32BF, qui sont en composition. compose-2.yml [c862b14](https://github.com/dispoclavier/nouvel-azerty/commit/c862b145f8eb02890a5f2b341e75822c236e7c1b), [4dd4ec3](https://github.com/dispoclavier/nouvel-azerty/commit/4dd4ec3c8e190e5e5453f826b4537588037ff775), compose-1.yml [91eac71](https://github.com/dispoclavier/nouvel-azerty/commit/91eac71bd5f0dc0c536c4fb58c3ed756cc9e4759)
	* Crosse : Diacritique espaçant : Redonder "˞" U02DE à la place de "˽" U02FD, qui est dans crochet rétroflexe > crochet palatal. compose-2.yml [6214504](https://github.com/dispoclavier/nouvel-azerty/commit/621450437fd27b9f46410119752e0f9dc273ba6c)
	* Point en chef :
		* Prendre en charge "ꜗ" UA717, qui était dans macron. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4), 
		* Prendre en charge "ꜘ" UA718, qui était dans barré. ibidem
		* Prendre en charge "ꜙ" UA719, qui était dans rayé. ibidem et compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "∔" U2214, "∸" U2238. compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "⩑" U2A51, "⩒" U2A52. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
		* Redonder "≐" U2250, "⋵" U22F5, "⧊" U29CA, "⨰" U2A30. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Supprimer "·" U00B7, qui va en composition. ibidem
		* Redonder "⩧" U2A67, "⩪" U2A6A, "⩭" U2A6D, "⪁" U2A81, "⪂" U2A82, "⫃" U2AC3, "⫄" U2AC4. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Brève inversée :
		* Supprimer les filets "╭" U256D.."╰" U2570, qui vont en composition. compose-2.yml [dce207f](https://github.com/dispoclavier/nouvel-azerty/commit/dce207faecef896a03c010d6d4fe8afc4f8ba10b)
		* Caractère de base ASCII de "͡" U0361 : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Brève inversée souscrite : Caractère de base ASCII de "᷼" U1DFC : Changer de "?" en "=". ibidem
	* Brève :
		* Supprimer les filets "─" U2500.."╬" U256C, "╱" U2571.."╿" U257F, qui vont en composition. compose-2.yml [dce207f](https://github.com/dispoclavier/nouvel-azerty/commit/dce207faecef896a03c010d6d4fe8afc4f8ba10b)
		* Caractère de base ASCII de "͝" U035D : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Brève souscrite : Caractère de base ASCII de "͜" U035C : Changer de "?" en "=". ibidem
	* Rayé :
		* Redonder "⦵" U29B5 par "}". compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Supprimer "ꜙ" UA719, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
	* Cornu : Redonder "⥆" U2946, "⥅" U2945. compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
	* Indice : Désactiver l’équivalent en composition de "₋" U208B, "₎" U208E, en composition en tant que symboles mathématiques. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Macron :
		* Redonder "⧶" U29F6, "⨛" U2A1B. ibidem
		* Redonder "⦱" U29B1 par "}". ibidem
		* Redonder "⊼" U22BC, "⊽" U22BD. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Caractère de base ASCII de "͞" U035E : Changer de "?" en "=". ibidem
		* Supprimer "ꜗ" UA717, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
		* Redonder "⋶" U22F6 par "L", "⋷" U22F7 par "l". compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Redonder "⋽" U22FD par "M", "⋾" U22FE par "m". ibidem
		* Redonder "⩂" U2A42 par "'", "⩃" U2A43 par "{". ibidem
		* Redonder "⫧" U2AE7. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Macron souscrit :
			* Redonder "⊻" U22BB. ibidem
			* Redonder "⦋" U298B, "⦌" U298C, "⦥" U29A5, "⧋" U29CB, "⨜" U2A1C, "⨱" U2A31. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
			* Redonder "⦤" U29A4. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89), [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
			* Redonder "⩟" U2A5F. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
			* Redonder "⫨" U2AE8. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
			* Caractères de base de "͟" U+035F :
				* Changer de "?" en "=". ibidem
				* Supprimer "\"" et "€". ibidem
		* Ligne souscrite : Redonder "⩠" U2A60, "⩣" U2A63. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c), [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Barré :
		* Redonder "≢" U2262 dans le groupe 1 à la place de "≠" U2260, qui va dans le groupe 0. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Redonder "≰" U2270 et "≱" U2271 dans les groupes 1 et 2 à la place de "≮" U226E et "≯" U226F, qui vont dans le groupe 0. ibidem
		* Redonder "∤" U2224 dans le groupe 0 sans équivalent en composition. compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "∦" U2226 dans le groupe 1 à la place de "∤" U2224, qui va dans le groupe 0. ibidem
		* Supprimer "ꜘ" UA718, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
	* Rond en chef :
		* Redonder "ꭘ" UAB58 par "X", "ꭔ" UAB54 par "q". compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "°" U00B0 par "8" à la place de "∗" U2217, qui est par "5". ibidem
		* Redonder "⟟" U27DF par "T" et "t". compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Redonder "⦲" U29B2 par "}". ibidem
		* Redonder "⫯" U2AEF. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Rond souscrit : Redonder "⫰" U2AF0, "⫱" U2AF1. ibidem
	* Accent circonflexe :
		* Caractère de base ASCII de "᷍" U1DCD : Changer de "?" en "=". ibidem
		* Changer le caractère de base de "᪰" U1AB0 de "^" en "d" ou "D". ibidem
		* Supprimer la redondance par "d" ou "D" de "⌀" U2300, qui est sur touche vive, dans le groupe 1 de "(" et en composition. ibidem
		* Redonder "⩯" U2A6F. ibidem
		* Désactiver l’équivalent en composition de "‘" U2018. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Améliorer la prise en charge de "⸶" U2E36. compose-2.yml [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416)
	* Hatchek :
		* Améliorer la prise en charge de "⸷" U2E37. ibidem
	* Point souscrit : Redonder "⩦" U2A66. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Point souscrit et point en chef :
		* Renommer de « point en chef et point souscrit ». ibidem
		* Redonder "≑" U2251. ibidem
	* Tréma : Désactiver l’équivalent en composition de "‚" U201A. ibidem
	* Groupes des symboles :
		* Groupes de "'" : Prendre en charge l’apostrophe typographique comme caractère de base. compose-3.yml [075700b](https://github.com/dispoclavier/nouvel-azerty/commit/075700be17fb3e6b12aa4be9af7111efd09ee72d)
		* Groupes de "*" : Mettre "∗" U2217 dans le groupe 12 à la place de "※" U203B, qui prend la place laissée par "∗" U2217 dans le groupe 11. compose-3.yml [b3df10f](https://github.com/dispoclavier/nouvel-azerty/commit/b3df10fe04964c901f601a9c63112322386f7012)
		* Groupes de "+" :
			* Mettre "⁜" U205C dans le groupe 11 à la place de "✜" U271C. ibidem
			* Prendre en charge "﬩" UFB29 à la place laissée par "⁜" U205C dans le groupe 12. ibidem
		* Groupes de "=" : Mettre "⚖" U2696 du groupe 9 dans le groupe 5 à la place de "☕" U2615, qui va dans le groupe 9 à la place laissée par "⚖" U2696. compose-3.yml [74a4686](https://github.com/dispoclavier/nouvel-azerty/commit/74a468640eb9fc578ba25a5f3017514137ecffe2)
		* Groupes de "#" : Mettre "▪" U25AA du groupe 5 dans le groupe 4 à la place de "⏹" U23F9, qui va dans le groupe 10 à la place de "⮽" U2BBD, qui va dans le groupe 8 à la place de "⬛" U2B1B, qui va dans le groupe 7 à la place de "◼" U25FC, qui va dans le groupe 6 à la place de "◾" U25FE, qui va dans le groupe 5 à la place laissée par "▪" U25AA. ibidem
		* Groupes de "/" : Mettre "▫" U25AB du groupe 5 dans le groupe 4 à la place de "⛆" U26C6, qui va dans le groupe 8 à la place de "⬜" U2B1C, qui va dans le groupe 7 à la place de "◻" U25FB, qui va dans le groupe 6 à la place de "◽" U25FD, qui va dans le groupe 5 à la place laissée par "▫" U25AB. ibidem
		* Groupes de "@" :
			* Mettre "⏺" U23FA du groupe 4 dans le groupe 10 à la place de "❍" U274D, qui va dans le groupe 6 à la place de "○" U25CB, qui va dans le groupe 5 à la place de "●" U25CF, qui va dans le groupe 4 à la place laissée par "⏺" U23FA. ibidem
			* Mettre "⚫" U26AB du groupe 3 dans le groupe 2 à la place de "⚪" U26AA, qui va dans le groupe 3 à la place laissée par "⚫" U26AB. ibidem
		* Groupes de "<" : Mettre "⏪" U23EA du groupe 6 dans le groupe 10 à la place de "▲" U25B2, qui va dans le groupe 6 à la place laissée par "⏪" U23EA. ibidem
		* Groupes de ">" : Mettre "⏩" U23E9 du groupe 6 dans le groupe 10 à la place de "▼" U25BC, qui va dans le groupe 6 à la place laissée par "⏩" U23E9. ibidem
		* Groupes de "|" : Mettre "⏯" U23EF du groupe 6 dans le groupe 7 à la place de "⏸" U23F8, qui va dans le groupe 10 à la place de "Ⓜ" U24C2, qui va dans le groupe 6 à la place laissée par "⏯" U23EF. ibidem
		* Groupes de "_" : Ajouter "⬝" U2B1D à la place de "♚" U265A, qui prend la place de "♛" U265B, qui prend la place de "♜" U265C, qui prend la place de "♝" U265D, qui prend la place de "♞" U265E, qui prend la place de "♟" U265F, qui prend la place de "⮈" U2B88, qui va dans réfléchi. ibidem et compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda)
		* Groupes de "[" : Mettre "⟦" U27E6 du groupe 10 dans le groupe 4 à la place de "♔" U2654, qui prend la place de "♕" U2655, qui prend la place de "♖" U2656, qui prend la place de "♗" U2657, qui prend la place de "♘" U2658, qui prend la place de "♙" U2659, qui prend la place laissée par "⟦" U27E6. compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda)
		* Groupes de "]" : Mettre "⟧" U27E7 du groupe 10 dans le groupe 4 à la place de "◊" U25CA, qui prend la place laissée par "⟧" U27E7. ibidem
	* Groupes des lettres : Remplir les places vides avec le numéro du groupe. compose-3.yml [c3fc88d](https://github.com/dispoclavier/nouvel-azerty/commit/c3fc88d3824d63fd1bda1c1c6d34c7e2d8131759), [cea6029](https://github.com/dispoclavier/nouvel-azerty/commit/cea6029db089f23c7761edf9b830b15bcb9fd8a8), generate-deadkey-tables.pl [858df5a](https://github.com/dispoclavier/nouvel-azerty/commit/858df5aa869acebf5f1479db14a14700793dc53f), [d7c45fe](https://github.com/dispoclavier/nouvel-azerty/commit/d7c45fe59b8d1ea6906bfe15f1ee76d72201c02b)
* Installation, activation :
	* Rectifier les mots-clés balises au début et à la fin du fichier Compose.yml. compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda), installer.sh [0defb75](https://github.com/dispoclavier/nouvel-azerty/commit/0defb7509be305fc463c6c17e80fbb9428541884), activer.sh [ee8fbfa](https://github.com/dispoclavier/nouvel-azerty/commit/ee8fbfa504dcb77fc5df52f299b2f7cfb3a145b1)
	* Confirmer le nom de fichier Compose.yml. installer.sh [0defb75](https://github.com/dispoclavier/nouvel-azerty/commit/0defb7509be305fc463c6c17e80fbb9428541884), [8783c09](https://github.com/dispoclavier/nouvel-azerty/commit/8783c09bbf4c245f2d7048e1c1fed55d9c165a26), activer.sh [ee8fbfa](https://github.com/dispoclavier/nouvel-azerty/commit/ee8fbfa504dcb77fc5df52f299b2f7cfb3a145b1), [7b88b38](https://github.com/dispoclavier/nouvel-azerty/commit/7b88b38c6bdfec2ace1ddd02ec74df279eec9c72), compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), [bb0a703](https://github.com/dispoclavier/nouvel-azerty/commit/bb0a703572d86236efa39c58e71d3b8f0a12bc97)
* Documentation :
	* Fusionner l’introduction et les deux modes d’emploi, et répartir le contenu sur trois modes d’emploi. readme.md alias Mode-d-emploi-commun.md [3483ed3](https://github.com/dispoclavier/nouvel-azerty/commit/3483ed3a70f3803d9d657a141c6d05a27004381d), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [5f2387c](https://github.com/dispoclavier/nouvel-azerty/commit/5f2387c05b1cec8a6c93b2216b6d780ea1962ba7), windows/readme.md alias Mode-d-emploi-sous-Windows.md [370efda](https://github.com/dispoclavier/nouvel-azerty/commit/370efdac4c75bce77c006adc5f2b93c0e98f3c53)
	* Améliorer le tri. compose-1.yml [90ec2e0](https://github.com/dispoclavier/nouvel-azerty/commit/90ec2e0ad57e8bc16d14b6bfcf8ad24312e27b75), [2e00217](https://github.com/dispoclavier/nouvel-azerty/commit/2e00217606c0cdde8a8e6c23e0b888fdb0cad5ab), [a5e998d](https://github.com/dispoclavier/nouvel-azerty/commit/a5e998da7547ff2ded9a28c1d505aa240cdb054a)
	* Améliorer la symétrisation des enchaînements de touches mortes. compose-1.yml [8d799a3](https://github.com/dispoclavier/nouvel-azerty/commit/8d799a3374fc7bb9679c45fea99d2deff6ccd3c6), [8b41337](https://github.com/dispoclavier/nouvel-azerty/commit/8b41337013b233365373cf59c089718629fddd31)
	* Améliorer l’intertitrage. compose-1.yml [2ab9521](https://github.com/dispoclavier/nouvel-azerty/commit/2ab9521d1730b4a149c61f9bf8816db1e4f2d8f9)
	* Annoter l’ordre des caractères de base. compose-2.yml [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00), [8b4bc7a](https://github.com/dispoclavier/nouvel-azerty/commit/8b4bc7a0a788c4f6bc7044d2c430f1974784f94a)
	* Préciser des renvois. compose-2.yml [19b1f60](https://github.com/dispoclavier/nouvel-azerty/commit/19b1f603bbe7e0f0f88e0a94063d1bbfe967f216)
	* Corriger des renvois et en ajouter. compose-1.yml [fa0dc2e](https://github.com/dispoclavier/nouvel-azerty/commit/fa0dc2ed98cb0757d3030c9fa1a221dabc4fef0f), compose-2.yml [d2a4a05](https://github.com/dispoclavier/nouvel-azerty/commit/d2a4a059bd8e421dc473ca835838ed331f66ab7a)
	* Corriger des annotations. compose-1.yml [184dcaa](https://github.com/dispoclavier/nouvel-azerty/commit/184dcaae7988e1816792983ec2b0dd4caa61e265), [957f1cf](https://github.com/dispoclavier/nouvel-azerty/commit/957f1cfa73f977f4845a4efd60f92aac10eb4d18), compose-2.yml [15d00ee](https://github.com/dispoclavier/nouvel-azerty/commit/15d00ee4075c1288f7d6d90053f36e2d9bea7668https://github.com/dispoclavier/nouvel-azerty/commit/15d00ee4075c1288f7d6d90053f36e2d9bea7668)
	* Corriger et compléter des annotations. compose-1.yml [7a11210](https://github.com/dispoclavier/nouvel-azerty/commit/7a11210edd599fd205bdc112dddd9143e568ed4a), compose-2.yml [3d2dbed](https://github.com/dispoclavier/nouvel-azerty/commit/3d2dbedfc997570ad38ae7f1e909bd4ddde3390a), [9a22577](https://github.com/dispoclavier/nouvel-azerty/commit/9a22577ea15dc8cf5ffbff1742f06ee48dc190cf), dispocla.cpp [4716ff2](https://github.com/dispoclavier/nouvel-azerty/commit/4716ff265ad7b99acaed75b9b17f2893c9695d47) ; compose-1.yml [986a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/986a2e86a3d87150ea7d30af36409eaef4db8748). compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59), compose-3.yml [075700b](https://github.com/dispoclavier/nouvel-azerty/commit/075700be17fb3e6b12aa4be9af7111efd09ee72d)
	* Corriger, ajouter ou supprimer des annotations. compose-1.yml [20cfb06](https://github.com/dispoclavier/nouvel-azerty/commit/20cfb0651da809faed004af544be7ff89999572a), compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c), [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4) ; compose-1.yml [f6a48ca](https://github.com/dispoclavier/nouvel-azerty/commit/f6a48ca0edfffc1833271cde3e71a5241801cd28), compose-2.yml [6214504](https://github.com/dispoclavier/nouvel-azerty/commit/621450437fd27b9f46410119752e0f9dc273ba6c), compose-3.yml [e307dc8](https://github.com/dispoclavier/nouvel-azerty/commit/e307dc8f743d9e39abafde930f498eb74b35ea2f) ; compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f), compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda), dispocla.cpp [1f6ad90](https://github.com/dispoclavier/nouvel-azerty/commit/1f6ad9015dbcf31abe5d553b4a5baeb446d13358) ; compose-1.yml [bb0a703](https://github.com/dispoclavier/nouvel-azerty/commit/bb0a703572d86236efa39c58e71d3b8f0a12bc97), compose-2.yml [29c78c1](https://github.com/dispoclavier/nouvel-azerty/commit/29c78c1c6601a3f8d0f1a67d1f9760c63142e011), compose-3.yml [74a4686](https://github.com/dispoclavier/nouvel-azerty/commit/74a468640eb9fc578ba25a5f3017514137ecffe2) ; compose-1.yml [532df9c](https://github.com/dispoclavier/nouvel-azerty/commit/532df9cf266f0c119a18605d8799271504df7f28), compose-2.yml [e224a20](https://github.com/dispoclavier/nouvel-azerty/commit/e224a2098f91ffca46d43501ea59affeda972aef), compose-3.yml [c3fc88d](https://github.com/dispoclavier/nouvel-azerty/commit/c3fc88d3824d63fd1bda1c1c6d34c7e2d8131759) ; compose-1.yml [283f286](https://github.com/dispoclavier/nouvel-azerty/commit/283f2869fb27a95ff70688fa523d9f35b68e3514), [9ea3974](https://github.com/dispoclavier/nouvel-azerty/commit/9ea3974daa8a9742efd658f26e943b21ea98a8df), compose-2.yml [272ea17](https://github.com/dispoclavier/nouvel-azerty/commit/272ea17b45d76c445911fb466d54850519fe813c), compose-3.yml [937f581](https://github.com/dispoclavier/nouvel-azerty/commit/937f581c065e91a08128c44f6f6f143833874349), dispocla_perso.cpp [d17c4a1](https://github.com/dispoclavier/nouvel-azerty/commit/d17c4a14b6ce3b4c3ab657120d3d0c37f1643942), [002b724](https://github.com/dispoclavier/nouvel-azerty/commit/002b7240451ce026c0214b5d393763839cb1c175)
	* Corriger une annotation avant déplacement. compose-1.yml [24bb803](https://github.com/dispoclavier/nouvel-azerty/commit/24bb8035745d776af9fc13e8ddab1e4fcfff886c)
	* Mieux regrouper et titrer les annotations. compose-2.yml [9e228d6](https://github.com/dispoclavier/nouvel-azerty/commit/9e228d6709040837da41ed42b6ec3c367339cdff), compose-1.yml [8a2644a](https://github.com/dispoclavier/nouvel-azerty/commit/8a2644a4d96fa60a9e115daacbb6343bf12559df)
	* Rectifier ou mettre à jour des annotations. compose-1.yml [a9308e8](https://github.com/dispoclavier/nouvel-azerty/commit/a9308e80b970de8c0d3e6edafcac7a52d14e6196), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18), [0c6da50](https://github.com/dispoclavier/nouvel-azerty/commit/0c6da5070b12c1ad9ffcef17197603f62d08779a), compose-2.yml [c04e68c](https://github.com/dispoclavier/nouvel-azerty/commit/c04e68cb7be8be8911d379a080d3345e579807d8), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Clarifier ou compléter des annotations. compose-3.yml [f4fb201](https://github.com/dispoclavier/nouvel-azerty/commit/f4fb201fa970113e1f9529f5c36930d2a1a92524)
	* Ajouter, améliorer, mettre à jour ou corriger des annotations. compose-1.yml [0f40ccf](https://github.com/dispoclavier/nouvel-azerty/commit/0f40ccf4ac4f8ab9e5bc3cd7fcad35b1497eba80), compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc), [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416), [fe803a1](https://github.com/dispoclavier/nouvel-azerty/commit/fe803a1d3c4dd599a406feb52c29bcc14e7d64ee)
	* Corriger le journal des modifications. CHANGELOG.md [e9f7eff](https://github.com/dispoclavier/nouvel-azerty/commit/e9f7eff4aa64d6f9c84c2535fd54e5607c971453)

## 5.0.0 (2025-04-15)

Amélioration de l’utilisabilité de la modificatrice AltFr et des touches B07 et B08 en mode ASCII par la stabilité des points d’interrogation et d’exclamation.

Complétion des touches mortes au-delà du contenu pris en charge par équivalence en composition, grâce à la dissociation des touches mortes et des équivalents en composition.

Amélioration des groupes des symboles :

* gain de trois places dans les premiers groupes du croisillon grâce à la dissociation des touches mortes et de leur équivalent en composition ;
* retour des cases à cocher sur "#" ;
* intégration des obèles les plus fréquents et de l’astérisme très populaire.

Amélioration des groupes des lettres :

* les lettres grecques latines passent du groupe 3 au groupe 2 ;
* le v de ronde est doté d’un raccourci dans le groupe 1 ;
* l’upsilon latin regagne sa place dans le groupe 1 de l’i grec.

Correction de la prise en charge de l’émoji "❄" U2744, arrêt de celle de "😃" U1F603.

Prise en charge sur touche vive du séparateur invisible "⁣" U2063, comme du signe plus invisible "⁤" U2064 pour les fractions ordinaires (depuis la version 4.14), améliorant la résilience des écritures bicamérales.

Rectification ou simplification de certaines séquences de composition.

* Disposition :
	* Mode ASCII : AltFr :
		* B07 : Redonder le point d’interrogation (aussi en Maj) à la place de la virgule, qui est sur C10. dispocla.cpp [1b7a98a](https://github.com/dispoclavier/nouvel-azerty/commit/1b7a98ac2f886804dded572df08529d689df77ce), kbfrFRs.klc [f835de6](https://github.com/dispoclavier/nouvel-azerty/commit/f835de68f40d2736936d8a0d3feb767d201d3468), kbfrFRs.C [a778bb5](https://github.com/dispoclavier/nouvel-azerty/commit/a778bb52b745b4e4fbb25f23324d50b649669069), kbfredis.klc [b436621](https://github.com/dispoclavier/nouvel-azerty/commit/b4366215cb044a0f65dc399a94cc64d4f478a866), kbfredis.C [bcd0465](https://github.com/dispoclavier/nouvel-azerty/commit/bcd0465eff0029e2a19de1a4a87ec93f1bc62e74), linux-chromeos/readme.md [7546107](https://github.com/dispoclavier/nouvel-azerty/commit/7546107da66076f5fc712893c153e2846a749915), windows/readme.md [db18230](https://github.com/dispoclavier/nouvel-azerty/commit/db1823061903937f073744f2b863bebf192a1cad)
		* B08 : Redonder le point d’exclamation (aussi en Maj) à la place du point, qui est sur D10. ibidem
		* B09 : Accueillir "😒" U1F612 à la place de "😃" U1F603, qui n’est pas très fréquent. dispocla.cpp [67628de](https://github.com/dispoclavier/nouvel-azerty/commit/67628dee23300fb985b258b346116f626b1a0a8a), [da79a94](https://github.com/dispoclavier/nouvel-azerty/commit/da79a9495e70559f0a42443e18dc8ea397d542f5), nouvel-azerty.json [3f4d68c](https://github.com/dispoclavier/nouvel-azerty/commit/3f4d68cd2b21d550f0078ec7ff480b054aa67c88), nouvel-azerty-verrcap.json [5fac7cc](https://github.com/dispoclavier/nouvel-azerty/commit/5fac7cc00d8ce7b4b9ded019a553c2b94137c4f2), nouvel-azerty-verrmod.json [170ae79](https://github.com/dispoclavier/nouvel-azerty/commit/170ae79cbd68d8a009e2627ed909dc1fe0ab4260), nouvel-azerty-verrmod-verrcap.json [f50688a](https://github.com/dispoclavier/nouvel-azerty/commit/f50688a1dd324050376c8b91d75056e3f14cd195), ibidem
	* Mode français : B07 : Redonder sur touche vive le séparateur invisible "⁣" U2063 à la place de "😒" U1F612, qui va sur B09. ibidem
	* Windows : Déboguer la touche "moins" (E11). ibidem, kbfrFRs.H [0445df6](https://github.com/dispoclavier/nouvel-azerty/commit/0445df6d054dfec850526d8bebd91d457540cd4d), kbfredis.H [74eda28](https://github.com/dispoclavier/nouvel-azerty/commit/74eda28e7e4bb186dfee878a5d3adde763a2cfdd)
* Composition :
	* Déboguer les séquences de "⋽" U22FD en annulant une [suppression faite par accident](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086#diff-6ae5ae8eee6e3533cc8889ce0f10b2d6db4de1acaf99d4ddb60920440b879f2dR5675) en amont de la version 4.25.0. compose-1.yml [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08)
	* Rectifier la séquence de "⦬" U29AC après la version 4.25.0. compose-1.yml [ac148a1](https://github.com/dispoclavier/nouvel-azerty/commit/ac148a1ba51cf8ef443309ab554879f59be3f35a)
	* Prendre en charge "❄" U2744. compose-1.yml [6f73de7](https://github.com/dispoclavier/nouvel-azerty/commit/6f73de7717b799e3776e4b5a575403a123cfc496), [749b224](https://github.com/dispoclavier/nouvel-azerty/commit/749b2243b936372dcb154c6b8ec4ad56caa7b5e4), compose-3.yml [4f9dd88](https://github.com/dispoclavier/nouvel-azerty/commit/4f9dd885cbc434c7f331abfa4d028d906461646f), [be999dc](https://github.com/dispoclavier/nouvel-azerty/commit/be999dc7693ee4010ac0b65e6e628654acac9b0b)
	* Simplifier les séquences de "☀" U2600. ibidem
	* Prendre en charge "❤" U2764, "♥" U2665 séparément suite au réaménagement de la touche morte accent circonflexe. compose-1.yml [642cd00](https://github.com/dispoclavier/nouvel-azerty/commit/642cd0052bf3940b2438aa3458b501e1c205a7b6)
	* Prendre en charge "•" U2022, "‣" U2023, "▪" U25AA, "▫" U25AB, "▹" U25B9, "◦" U25E6, "➢" U27A2, "➣" U27A3 pour compléter les séquences avec "<" et un chiffre. ibidem
	* Compléter les séquences de "⃮" U20EE, "⃯" U20EF, "⋑" U22D1, "⋮" U22EE, "▴" U25B4, "▵" U25B5. ibidem
	* Supprimer les séquences redondantes erronées de "⋭" U22ED. ibidem
	* Rectifier les séquences de "⇓" U21D3, "∯" U222F, "♠" U2660, "♣" U2663. ibidem et [90bc457](https://github.com/dispoclavier/nouvel-azerty/commit/90bc457cdc7b604d4a8d6faf94ea49ed612a4538)
	* Simplifier et documenter les séquences de "⤄" U2904, "⤅" U2905, "⤊" U290A, "⤋" U290B, "⤐" U2910, "⤑" U2911, "⤖" U2916, "⤞" U291E, "⤟" U291F, "⤠" U2920, "⤤" U2924, "⤥" U2925, "⤧" U2927, "⤪" U292A, "⤭" U292D, "⤮" U292E, "⤰" U2930, "⤱" U2931, "⤲" U2932. compose-1.yml [006c816](https://github.com/dispoclavier/nouvel-azerty/commit/006c816e3241aaff1b6dd42b10c0cf5f2b6fd4bd)
	* Mettre à jour et documenter la séquence de "⦽" U29BD ; adapter celles de "⧀" U29C0. compose-1.yml [4c4e436](https://github.com/dispoclavier/nouvel-azerty/commit/4c4e436f1315d25e37ef3b995277f65e76021abb), [b9b806d](https://github.com/dispoclavier/nouvel-azerty/commit/b9b806dadd4ad35b3404e33c4d1996d6ef6b5e08), [c40e9e1](https://github.com/dispoclavier/nouvel-azerty/commit/c40e9e1c6ae02691a0d247fbdc26c26220ebb79c)
	* Mettre à jour et simplifier les séquences de "⧪" U29EA, "⧬" U29EC, "⧭" U29ED. compose-1.yml [2a7c850](https://github.com/dispoclavier/nouvel-azerty/commit/2a7c850d52db6defd80ad24f506d0b2fcc6ef6dc)
	* Simplifier et annoter les séquences de "⨝" U2A1D ; annoter celles de "⋈" U22C8. compose-1.yml [b78b3fd](https://github.com/dispoclavier/nouvel-azerty/commit/b78b3fd58cd68ea1362bba084e94c4db01e84fb4), [d0656a5](https://github.com/dispoclavier/nouvel-azerty/commit/d0656a56832868b2ef1468b5477c683d3c7772ef), [bac64f2](https://github.com/dispoclavier/nouvel-azerty/commit/bac64f2c88345c8375285e83ae3ccfd0f767e6a5)
	* Ajouter les séquences simplifiées optionnelles de "⬴" U2B34, "⬵" U2B35, "⬹" U2B39, "⬺" U2B3A, "⬼" U2B3C, "⬽" U2B3D ; adapter celles de "⇺" U21FA. compose-1.yml [04eb081](https://github.com/dispoclavier/nouvel-azerty/commit/04eb0815a400ae835eadbafd5aa800fcf00fc36c)
	* Harmoniser les séquences de "⬿" U2B3F avec celles de "⤳" U2933, rectifiées ; adapter et simplifier celles de "⥲" U2972, "⥳" U2973. compose-1.yml [32bfd85](https://github.com/dispoclavier/nouvel-azerty/commit/32bfd85d1611ced2805a760b3cbf9d674574535d)
	* Rectifier, simplifier et annoter les séquences de "⥂" U2942, "⥃" U2943, "⥄" U2944. compose-1.yml [b1ea7bf](https://github.com/dispoclavier/nouvel-azerty/commit/b1ea7bf3abc052f7b01495cb32ce8303aff13970)
	* Adapter les séquences de "▵" U25B5 suite à l’amélioration de la prise en charge de "⁄" U2044. compose-1.yml [fd89859](https://github.com/dispoclavier/nouvel-azerty/commit/fd8985931d1a7fa5cc172f12800b512d42db8422)
	* Rectifier les séquences de "⥷" U2977, "⭃" U2B43, "⥺" U297A, "⭄" U2B44, "⥇" U2947, "⬾" U2B3E. compose-1.yml [7ac242b](https://github.com/dispoclavier/nouvel-azerty/commit/7ac242b3af8e34a893223d4dd8c1e24b37736c4a)
	* Rectifier la séquence de "⤾" U293E. compose-1.yml [c0c63bc](https://github.com/dispoclavier/nouvel-azerty/commit/c0c63bc806b8280b9a93c02cf0a25e0ae0f0b3a7)
	* Mettre à jour les séquences de "⥐" U2950. compose-1.yml [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c)
	* Compléter les séquences de "⥀" U2940, "⥁" U2941, "⥏" U294F. ibidem
	* Adapter les séquences de "⩹" U2A79, "⩺" U2A7A. ibidem
	* Rectifier ou compléter les séquences de "⦞" U299E, "⦡" U29A1, "⧖" U29D6, "⧗" U29D7. compose-1.yml [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [67e64f1](https://github.com/dispoclavier/nouvel-azerty/commit/67e64f1c8581be72cb96538e375a8ad1832e5713)
	* Rectifier les séquences de "⧚" U29DA, "⧛" U29DB. compose-1.yml [f9140f5](https://github.com/dispoclavier/nouvel-azerty/commit/f9140f58a7759f51e30d46040c79539ef44ba8ca), [a7f5913](https://github.com/dispoclavier/nouvel-azerty/commit/a7f5913d64859d600bbf86017735639d4976b070)
	* Simplifier les séquences de "⑥" U2465, "⑦" U2466, "⑧" U2467, "⑨" U2468, "⧘" U29D8, "⧙" U29D9. ibidem
	* Compléter les séquences de "⨢" U2A22, "⨣" U2A23. compose-1.yml [8e15584](https://github.com/dispoclavier/nouvel-azerty/commit/8e15584c36144da1f4b7fed6b7b4acf2487ed8a3), [6ed0e90](https://github.com/dispoclavier/nouvel-azerty/commit/6ed0e9048a44f1b899c170214d1720f40cf47b15)
	* Rectifier les séquences de "⃮" U20EE, "⃯" U20EF. compose-1.yml [45d10e1](https://github.com/dispoclavier/nouvel-azerty/commit/45d10e18f513ae00b44455ff9f0cabd4f8b5ddf1)
	* Simplifier les séquences de "ϐ" U03D0, "ϑ" U03D1, "ϑ" U03D1, "ϒ" U03D2, "ϕ" U03D5, "ϰ" U03F0, "ϱ" U03F1, "ϴ" U03F4, "ϴ" U03F4, "ϵ" U03F5, "϶" U03F6, "‖" U2016, "⁺" U207A, "⁼" U207C, "⁽" U207D, "₊" U208A, "₌" U208C, "⃓" U20D3, "⃮" U20EE, "⃯" U20EF, "ℇ" U2107, "ℊ" U210A, "ℌ" U210C, "ℍ" U210D, "ℎ" U210E, "ℏ" U210F, "ℑ" U2111, "ℓ" U2113, "ℕ" U2115, "ℚ" U211A, "ℜ" U211C, "ℝ" U211D, "ℤ" U2124, "ℨ" U2128, "℩" U2129, "ℯ" U212F, "ℷ" U2137, "ℼ" U213C, "ℽ" U213D, "ℾ" U213E, "ℿ" U213F, "⅀" U2140, "⅁" U2141, "⅄" U2144, "ⅆ" U2146, "ⅇ" U2147, "ⅈ" U2148, "ⅉ" U2149. ibidem et compose-1.yml [1dccbfb](https://github.com/dispoclavier/nouvel-azerty/commit/1dccbfbb98813746f824e76dc1f26aaddfbbfb4d), [48350a3](https://github.com/dispoclavier/nouvel-azerty/commit/48350a344bca00bb80c48c8a94b2e82f6497ff4f), [6c1ca09](https://github.com/dispoclavier/nouvel-azerty/commit/6c1ca09f77b5f1d79d23234c8bfb687ebcaddca4)
	* Corriger une séquence de "⨣" U2A23. compose-1.yml [439fa55](https://github.com/dispoclavier/nouvel-azerty/commit/439fa5538931f0f777be44a6969492599066a033)
	* Compléter les séquences de "⨢" U2A22. compose-1.yml [81c31c7](https://github.com/dispoclavier/nouvel-azerty/commit/81c31c7690af71b2cedc374d2c6c7eadfbe0791b)
	* Compléter, simplifier et mettre à jour les séquences de "⇆" U21C6, "⟵" U27F5, "⟶" U27F6, "⟷" U27F7, "⟸" U27F8, "⟹" U27F9, "⟺" U27FA, "⟻" U27FB, "⟼" U27FC, "⟽" U27FD, "⟾" U27FE. compose-1.yml [bb3410c](https://github.com/dispoclavier/nouvel-azerty/commit/bb3410c6ec6234150fe6d180652ac016b14a728a), [1562be3](https://github.com/dispoclavier/nouvel-azerty/commit/1562be3e51b8fceadab03b396a534c385b09c698)
	* Rectifier les séquences de "↱" U21B1. compose-1.yml [c704e9c](https://github.com/dispoclavier/nouvel-azerty/commit/c704e9c50416c21c25aa9f399bebb6e3fc3ce2f4)
	* Simplifier les séquences de "⨥" U2A25, "⨧" U2A27, "⨨" U2A28, "⨩" U2A29, "⨫" U2A2B, "⨬" U2A2C, "⨭" U2A2D. ibidem
	* Rectifier les séquences de "≮" U226E. compose-1.yml [ce651e2](https://github.com/dispoclavier/nouvel-azerty/commit/ce651e2da42b228cc5cfb6772feaca61ecda5120)
	* Simplifier les séquences de "↔" U2194. ibidem
	* Adapter les séquences de "⧺" U29FA. compose-1.yml [47e4f66](https://github.com/dispoclavier/nouvel-azerty/commit/47e4f66bf5d85172c24d58068dc549ca8c3facb4)
	* Simplifier les séquences de "↛" U219B. compose-1.yml [7555ff0](https://github.com/dispoclavier/nouvel-azerty/commit/7555ff0d80afe1c2c414bc69385bd910d473906a)
* Transformations :
	* Groupes des lettres :
		* Groupes de "B" : Mettre "Ꞵ" UA7B4, "ꞵ" UA7B5 dans le groupe 2 aux places de "Ɓ" U0181, "ɓ" U0253, qui prennent les places laissées par "Ꞵ" UA7B4, "ꞵ" UA7B5 dans le groupe 3. compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "E" :
			* Mettre "Ɛ" U0190, "ɛ" U025B dans le groupe 2 aux places de "Ə" U018F, "ə" U0259, qui prennent les places laissées par "Ɛ" U0190, "ɛ" U025B dans le groupe 3. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2), [aed31c6](https://github.com/dispoclavier/nouvel-azerty/commit/aed31c60cb69df2a81d2e2ca49125247106850f2)
			* Mettre "ʚ" U029A du groupe 5 de "E" dans le groupe 5 de "e" à la place de "ɞ" U025E, qui prend la place du doublon de "ə" U0259 dans le groupe 4. ibidem
			* Supprimer le doublon de "Ə" U018F dans le groupe 4. ibidem
		* Groupes de "F" :
			* Minuscule : Mettre "ɸ" U0278 dans le groupe 2 à la place de "ꬵ" UAB35, qui prend la place laissée par "ɸ" U0278 dans le groupe 3. ibidem
			* Majuscule : Mettre "ⱷ" U2C77 dans le groupe 2 à la place de "ʩ" U02A9, qui prend la place laissée par "ⱷ" U2C77 dans le groupe 3. ibidem
		* Groupes de "G" : Mettre "Ɣ" U0194, "ɣ" U0263 dans le groupe 2 aux places de "Ȝ" U021C, "ȝ" U021D, qui vont dans le groupe 4 aux places de "Ɤ" UA7CB, "ɤ" U0264, qui prennent les places laissées par "Ɣ" U0194, "ɣ" U0263 dans le groupe 3. compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "H" : Mettre "Ɥ" UA78D, "ɥ" U0265 dans le groupe 2 aux places de "Ꜧ" UA726, "ꜧ" UA727, qui prennent les places laissées par "Ɥ" UA78D, "ɥ" U0265 dans le groupe 4. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2)
		* Groupes de "I" :
			* Sortir "ℹ" U2139, qui est aussi dans le groupe 8 de "{" sur "I", du groupe 12 et le mettre dans le groupe 4 à la place de "Ꞽ" UA7BC, "ꞽ" UA7BD, qui vont dans le groupe 3 à la place de "Ɩ" U0196, "ɩ" U0269, qui sont dans le groupe 1. ibidem
			* Propager "ꟾ" UA7FE de la majuscule à la minuscule du groupe 12 de "I", "i". ibidem
		* Groupes de "L" : Mettre "Ꟛ" UA7DA, "ꟛ" UA7DB dans le groupe 2 aux places de "Ꝇ" UA746, "ꝇ" UA747, qui prennent les places laissées par "Ꟛ" UA7DA, "ꟛ" UA7DB dans le groupe 3. ibidem
		* Groupes de "M" : Mettre "Ɯ" U019C, "ɯ" U026F dans le groupe 2 aux places de "Ɱ" U2C6E, "ɱ" U0271, qui prennent les places laissées par "Ɯ" U019C, "ɯ" U026F dans le groupe 4. ibidem
		* Groupes de "O" : Mettre "Ɔ" U0186, "ɔ" U0254 dans le groupe 2 aux places de "Ȣ" U0222, "ȣ" U0223, qui prennent les places laissées par "Ɔ" U0186, "ɔ" U0254 dans le groupe 3. ibidem
		* Groupes de "U" : Redonder "Ʋ" U01B2, "ʋ" U028B dans le groupe 1 aux places de "Ʊ" U01B1, "ʊ" U028A, qui vont dans le groupe 1 de "Y", "y". compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "V" : Mettre "Ꞷ" UA7B6, "ꞷ" UA7B7 dans le groupe 2 aux places de "Ʋ" U01B2, "ʋ" U028B, qui prennent les places laissées par "Ꞷ" UA7B6, "ꞷ" UA7B7 dans le groupe 3. compose-3.yml [47e1f03](https://github.com/dispoclavier/nouvel-azerty/commit/47e1f034d678e830aac8034050e4138ef4e8f2b3)
		* Groupes de "X" : Mettre "Ꭓ" UA7B3, "ꭓ" UAB53 dans le groupe 2 aux places de "ꭘ" UAB58, "ꭖ" UAB56, qui prennent les places laissées par "Ꭓ" UA7B3, "ꭓ" UAB53 dans le groupe 3. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2)
		* Groupes de "Y" : Redonder "Ȝ" U021C, "ȝ" U021D dans le groupe 3 aux places de "Ʊ" U01B1, "ʊ" U028A, qui vont dans le groupe 1 aux places de "Ɣ" U0194, "ɣ" U0263, qui sont dans le groupe 2 de "G", "g". compose-3.yml [4e03419](https://github.com/dispoclavier/nouvel-azerty/commit/4e03419204df620598e49a5d2a926c0272e76e8b), [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
	* Lettres composées pour les langues du Togo : Prendre en charge les voyelles des groupes 2 et 3. compose-2.yml [a6d06d7](https://github.com/dispoclavier/nouvel-azerty/commit/a6d06d7a4d7aa351bccb4a2aa3986d36f8b669b4), [2c2d952](https://github.com/dispoclavier/nouvel-azerty/commit/2c2d952df5f95ac8c7929fd439eb0b09d05f986f), [fc60404](https://github.com/dispoclavier/nouvel-azerty/commit/fc60404a53064e8deaaf1ba5f327f1f67649b5f2), [27cf612](https://github.com/dispoclavier/nouvel-azerty/commit/27cf61243426ef4fd6c5644847d45222ee42b7a7), [e756e0f](https://github.com/dispoclavier/nouvel-azerty/commit/e756e0f330500b63c7f004d6512514d50b37f381), [9a2656e](https://github.com/dispoclavier/nouvel-azerty/commit/9a2656e84c2928c5138eac0f476917bae9490b30)
	* Groupes des symboles :
		* Groupes de "|" : Redonder l’obèle "†" U2020 dans le groupe 1, le double obèle "‡" U2021 dans le groupe 2, l’astérisme "⁂" U2042 dans le groupe 3, à la place des cases à cocher "☐" U2610, "☑" U2611, "☒" U2612, qui vont dans les trois premiers groupes de "#" et qui sont en composition. compose-3.yml [8e13367](https://github.com/dispoclavier/nouvel-azerty/commit/8e13367631c66f561fc5b348a3d90128cc744b3d)
		* Groupes de "#" : Remettre les cases à cocher "☐" U2610, "☑" U2611, "☒" U2612 dans les trois premiers groupes, malgré la panne des équivalents en composition. ibidem
		* Groupes de "`" : Mettre "❆" U2746 à la place de "❄" U2744, qui va dans le groupe 1 bis et en composition. compose-3.yml [b701895](https://github.com/dispoclavier/nouvel-azerty/commit/b7018954a1abd8352ac9f57b773555dd8c944c14)
	* Exposant : Exposant et indice (petite capitale) : Améliorer la prise en charge de la barre de fraction "⁄" U2044. compose-2.yml [962cce4](https://github.com/dispoclavier/nouvel-azerty/commit/962cce42aba2c3b20b24c939ec3f12939691b647), compose-1.yml [1d68090](https://github.com/dispoclavier/nouvel-azerty/commit/1d68090cad95777f33cc58b8766e2249c49cb942)
	* Tourné : Redonder "‿" U203F sans équivalent en composition. compose-2.yml [953f79d](https://github.com/dispoclavier/nouvel-azerty/commit/953f79d565d2fd10020cc98e5dcddc4f8e8548aa)
	* Réfléchi :
		* Améliorer la prise en charge de "⁌" U204C, "⁍" U204D. compose-2.yml [933fc16](https://github.com/dispoclavier/nouvel-azerty/commit/933fc165dd53c6d6724e0b51c289e0b366db7892)
		* Supprimer "Ɜ" UA7AB, "ɜ" U025C dans les groupes 3 à 5 suite au réaménagement des groupes des lettres. compose-2.yml [0e64944](https://github.com/dispoclavier/nouvel-azerty/commit/0e6494436e1f5e65e613e261d6da73c849716f46)
		* Réfléchi et crochet :
			* Remplacer "ᵆ" U1D46, "ᶛ" U1D9B par "ɝ" U025D. ibidem
			* Supprimer "ɝ" U025D dans les groupes 3 à 5 suite au réaménagement des groupes des lettres. ibidem
		* Réfléchi et crochet rétroflexe : Supprimer "ᶔ" U1D94 dans le groupe 3 suite au réaménagement des groupes des lettres. ibidem
	* Tilde :
		* Redonder "⨤" U2A24 sans équivalent en composition. compose-2.yml [d723e98](https://github.com/dispoclavier/nouvel-azerty/commit/d723e985d995d45f08c5ef68e9e907cece1a152a), compose-1.yml [6dbb70b](https://github.com/dispoclavier/nouvel-azerty/commit/6dbb70b8aaec1fc54a91c022baa2d86c046322ed)
		* Améliorer la prise en charge de "⁓" U2053. ibidem
		* Tilde médian ou souscrit : Redonder "⨦" U2A26. compose-2.yml [677d02c](https://github.com/dispoclavier/nouvel-azerty/commit/677d02c0779cd82ace91a5cef816fb2af096d5b0)
	* Point souscrit : Redonder "⨪" U2A2A. compose-2.yml [ac885cc](https://github.com/dispoclavier/nouvel-azerty/commit/ac885ccaa8755f39445de3c78111c2c50ac5ebfd)
	* Ogonek : Désactiver l’équivalent en composition de "⃣" U20E3. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
	* Crochet en chef : Désactiver l’équivalent en composition de "⃣" U20E3. ibidem
	* Barré : Redonder "≮" U226E, "≯" U226F dans le groupe 0, sans impliquer la touche morte groupe. compose-2.yml [5fe63b1](https://github.com/dispoclavier/nouvel-azerty/commit/5fe63b12b08fd0e6c71e60d448d31d285095dee6)
	* Rond en chef :
		* Redonder "⨢" U2A22. compose-2.yml [d2bc8dc](https://github.com/dispoclavier/nouvel-azerty/commit/d2bc8dcad83d114bd6961301ab1802f9a520d2b4)
		* Redonder "K" U212A. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
	* Accent circonflexe :
		* Redonder "⨣" U2A23. compose-2.yml [d2bc8dc](https://github.com/dispoclavier/nouvel-azerty/commit/d2bc8dcad83d114bd6961301ab1802f9a520d2b4)
		* Redonder les chiffres en exposant "⁰" U2070, "¹" U00B9, "²" U00B2, "³" U00B3, "⁴" U2074, "⁵" U2075, "⁶" U2076, "⁷" U2077, "⁸" U2078, "⁹" U2079 sans équivalents en composition. compose-2.yml [4413a1b](https://github.com/dispoclavier/nouvel-azerty/commit/4413a1b514d28bda78eacce4db21f52effda99f0)
		* Adapter la prise en charge de "᪰" U1AB0, désormais par "^". ibidem
		* Redonder "⁂" U2042 par "*". compose-2.yml [b2f5789](https://github.com/dispoclavier/nouvel-azerty/commit/b2f57893e94413cbb54fac7993136cc522b915fb)
		* Accent circonflexe souscrit : Adapter le raccourci, désormais en double frappe de cornu. ibidem
	* Drapeau :
		* Désactiver les équivalents en composition de "‌" U200C, "⁠" U2060. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
		* Corriger l’équivalent en composition du demi-codet haut UD83C. ibidem
	* Point souscrit : Redonder "⨥" U2A25. compose-2.yml [e5fa902](https://github.com/dispoclavier/nouvel-azerty/commit/e5fa90243a958d5d8e862fd6f61bb77d8122de11), compose-1.yml [f6fb44f](https://github.com/dispoclavier/nouvel-azerty/commit/f6fb44fd13c3b8f80af0e01892e8fcfcf536de68)
	* Tréma :
		* Redonder "⁑" U2051 par "*" sans équivalent en composition. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc), [43fa20e](https://github.com/dispoclavier/nouvel-azerty/commit/43fa20e8ef2aa3a316dc28048765cb69c54bf20e)
		* Supprimer "⸺" U2E3A, "⸻" U2E3B, qui sont dans les groupes 1..3 et en composition. compose-2.yml [8de617f](https://github.com/dispoclavier/nouvel-azerty/commit/8de617f5001bafa3627b8371c1b07d0c3f7aef0a)
* Documentation :
	* Ajouter un PDF documentant la touche morte groupe. linux-chromeos/readme.md [b70c9b7](https://github.com/dispoclavier/nouvel-azerty/commit/b70c9b7c26ca633276b98a19084d50a67ecfeaa1), windows/readme.md [0f70813](https://github.com/dispoclavier/nouvel-azerty/commit/0f708130443e4904770b614906f3e8614f57157a)
	* Mettre à jour les annotations suite à la version 4.25.0. compose-1.yml [26c6ea2](https://github.com/dispoclavier/nouvel-azerty/commit/26c6ea29b1aa65eb4176b267b29987ff3650f526), compose-3.yml [5899287](https://github.com/dispoclavier/nouvel-azerty/commit/5899287a877749eeaf9f463cde9d714ad4928b1d)
	* Mettre à jour les annotations suite à la divergence des touches mortes avec les équivalents en composition. compose-1.yml [ce651e2](https://github.com/dispoclavier/nouvel-azerty/commit/ce651e2da42b228cc5cfb6772feaca61ecda5120), [48745fb](https://github.com/dispoclavier/nouvel-azerty/commit/48745fb8b417239f979cb1d4cb463ee7861fd7ea), compose-2.yml [cb13225](https://github.com/dispoclavier/nouvel-azerty/commit/cb13225a0dacad95527cf853d667d0b197b8a4ec), [9b8e6e5](https://github.com/dispoclavier/nouvel-azerty/commit/9b8e6e5700127ded600d8fdaf32735fff445dc72)
	* Documenter les séquences tronquées en deçà de l’espace finale, pour faciliter leur éventuelle rallongation : Rajouter en commentaire les séquences tronquées jusque-là. compose-1.yml [7646b53](https://github.com/dispoclavier/nouvel-azerty/commit/7646b53b18ffc5a3c47374dd4303b008424d6fe7), [7b22e30](https://github.com/dispoclavier/nouvel-azerty/commit/7b22e30b71907f44b0fdcbff14bb7c4de0e0f3a4), [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08), [7e20c8f](https://github.com/dispoclavier/nouvel-azerty/commit/7e20c8f96e69c66aeed32db6e078b6a9f96e3998), [c0c63bc](https://github.com/dispoclavier/nouvel-azerty/commit/c0c63bc806b8280b9a93c02cf0a25e0ae0f0b3a7), [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c), [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [8e15584](https://github.com/dispoclavier/nouvel-azerty/commit/8e15584c36144da1f4b7fed6b7b4acf2487ed8a3), [752989e](https://github.com/dispoclavier/nouvel-azerty/commit/752989e704b5430af8d72b0ab7a64be50dfc5806), [dabd6c0](https://github.com/dispoclavier/nouvel-azerty/commit/dabd6c09dde6eeb2f187e265e1549bfbc3894f1d), [48745fb](https://github.com/dispoclavier/nouvel-azerty/commit/48745fb8b417239f979cb1d4cb463ee7861fd7ea)
	* Ajouter des annotations. compose-1.yml [73aa053](https://github.com/dispoclavier/nouvel-azerty/commit/73aa0530113510e8ab47194f603f159213679d0f), compose-2.yml [36bf48d](https://github.com/dispoclavier/nouvel-azerty/commit/36bf48d3c92f384b51f4d8710d1b9872734f8115)
	* Simplifier et émonder les annotations. compose-1.yml [1e68bae](https://github.com/dispoclavier/nouvel-azerty/commit/1e68baebff07069616dd97fc6153fe687532e82f), compose-2.yml [75751f0](https://github.com/dispoclavier/nouvel-azerty/commit/75751f0c60bf300a723aef54b32f29f295fec687), compose-3.yml [6256d8c](https://github.com/dispoclavier/nouvel-azerty/commit/6256d8c46cccd93a7e5eb910183b2d85dea47e90)
	* Corriger des annotations. compose-1.yml [dbc5212](https://github.com/dispoclavier/nouvel-azerty/commit/dbc52127f449863ee90888de8e6854f338dbeebd), compose-2.yml [2a55640](https://github.com/dispoclavier/nouvel-azerty/commit/2a5564030f4e290fe2fb5166f9bc4ddac53d1590), [43fa20e](https://github.com/dispoclavier/nouvel-azerty/commit/43fa20e8ef2aa3a316dc28048765cb69c54bf20e)
	* Mettre à jour des annotations. compose-1.yml [3566dba](https://github.com/dispoclavier/nouvel-azerty/commit/3566dba8c32f16b5499ee9a76ad2de46121d0a35), [95a2755](https://github.com/dispoclavier/nouvel-azerty/commit/95a2755129e3ae0ec03bc6c20c43ad3d3bc04ee0), compose-2.yml [62eea71](https://github.com/dispoclavier/nouvel-azerty/commit/62eea7124de4e87672959a9469d3f7e2eabd5a78), compose-3.yml [35881d2](https://github.com/dispoclavier/nouvel-azerty/commit/35881d2beab6e4bf663b73ca27db460e31c6b63c)¨; compose-2.yml [ed400b4](https://github.com/dispoclavier/nouvel-azerty/commit/ed400b481d7731782a577791d8d3a3e36ccab981), compose-3.yml [dd9a3f4](https://github.com/dispoclavier/nouvel-azerty/commit/dd9a3f4089db58ad4d5743d534fc849764deb22c) ; compose-1.yml [001ea1f](https://github.com/dispoclavier/nouvel-azerty/commit/001ea1f864826e24ed8566af066fe584f4b161db), compose-2.yml [5fe63b1](https://github.com/dispoclavier/nouvel-azerty/commit/5fe63b12b08fd0e6c71e60d448d31d285095dee6)
	* Mettre à jour, corriger et compléter des annotations. compose-1.yml [6dbb70b](https://github.com/dispoclavier/nouvel-azerty/commit/6dbb70b8aaec1fc54a91c022baa2d86c046322ed), [079f1fa](https://github.com/dispoclavier/nouvel-azerty/commit/079f1fa8ff5077b5efd219642b51097816aead8e), [6701124](https://github.com/dispoclavier/nouvel-azerty/commit/670112456fcf6510f326cf99f2e4e9243a17406d), compose-2.yml [953f79d](https://github.com/dispoclavier/nouvel-azerty/commit/953f79d565d2fd10020cc98e5dcddc4f8e8548aa), [933fc16](https://github.com/dispoclavier/nouvel-azerty/commit/933fc165dd53c6d6724e0b51c289e0b366db7892), [0e64944](https://github.com/dispoclavier/nouvel-azerty/commit/0e6494436e1f5e65e613e261d6da73c849716f46), [93e7599](https://github.com/dispoclavier/nouvel-azerty/commit/93e759962e2a1a86c42e886cd36d5522b43969c0), [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc), [8de617f](https://github.com/dispoclavier/nouvel-azerty/commit/8de617f5001bafa3627b8371c1b07d0c3f7aef0a), compose-3.yml [8ed9dc8](https://github.com/dispoclavier/nouvel-azerty/commit/8ed9dc8dff6ea2ad6c0ee3d2261c62407080f0d2)
	* Mettre à jour, corriger et compléter des annotations, améliorer la lisibilité. compose-1.yml [d648e75](https://github.com/dispoclavier/nouvel-azerty/commit/d648e752f362bc9e7cb92a78df2fad36aab00c0f), compose-2.yml [c072d9c](https://github.com/dispoclavier/nouvel-azerty/commit/c072d9c5d811d5bd0824e1c0b68cb1a52ddff0f3), compose-3.yml [bf0e9d3](https://github.com/dispoclavier/nouvel-azerty/commit/bf0e9d398211bd8700c26ba3999f9b4bc5a224ed)
	* Ajouter, compléter, corriger, mettre à jour ou supprimer des annotations. dispocla.cpp [1b7a98a](https://github.com/dispoclavier/nouvel-azerty/commit/1b7a98ac2f886804dded572df08529d689df77ce), [9e28652](https://github.com/dispoclavier/nouvel-azerty/commit/9e2865293ecc89d1dbafc38b5d3e73107a1e17be), compose-1.yml [d3bb0a6](https://github.com/dispoclavier/nouvel-azerty/commit/d3bb0a659bbf8e6b8cc7b2f952a2584f41c14ee5), [75c4a7e](https://github.com/dispoclavier/nouvel-azerty/commit/75c4a7e3b1542f49a3a3ee2bbdf5f577c8026b62), [006c816](https://github.com/dispoclavier/nouvel-azerty/commit/006c816e3241aaff1b6dd42b10c0cf5f2b6fd4bd), [d0656a5](https://github.com/dispoclavier/nouvel-azerty/commit/d0656a56832868b2ef1468b5477c683d3c7772ef), [b78b3fd](https://github.com/dispoclavier/nouvel-azerty/commit/b78b3fd58cd68ea1362bba084e94c4db01e84fb4), [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08), [90bc457](https://github.com/dispoclavier/nouvel-azerty/commit/90bc457cdc7b604d4a8d6faf94ea49ed612a4538), [eb06a29](https://github.com/dispoclavier/nouvel-azerty/commit/eb06a29e76448c719524d34f3248afffb0a8c629), [7e20c8f](https://github.com/dispoclavier/nouvel-azerty/commit/7e20c8f96e69c66aeed32db6e078b6a9f96e3998), [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c), [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [67e64f1](https://github.com/dispoclavier/nouvel-azerty/commit/67e64f1c8581be72cb96538e375a8ad1832e5713), [f9140f5](https://github.com/dispoclavier/nouvel-azerty/commit/f9140f58a7759f51e30d46040c79539ef44ba8ca), [44305b8](https://github.com/dispoclavier/nouvel-azerty/commit/44305b858cf4aaf9603e147f4e6038eb6fc1f791), [dff12bf](https://github.com/dispoclavier/nouvel-azerty/commit/dff12bf358ba212598d291ce15e3ad3efa173c38), [7b22e30](https://github.com/dispoclavier/nouvel-azerty/commit/7b22e30b71907f44b0fdcbff14bb7c4de0e0f3a4), [caa1e80](https://github.com/dispoclavier/nouvel-azerty/commit/caa1e80dad5fbc6f7ff02a7768ef39ca4d5eee67), [da25235](https://github.com/dispoclavier/nouvel-azerty/commit/da25235d1c1a8dc56caf23d12b0fbff4b0b56350), [dd9f997](https://github.com/dispoclavier/nouvel-azerty/commit/dd9f99709ff6010f0c5e917154819964cb924e12), [981862d](https://github.com/dispoclavier/nouvel-azerty/commit/981862dde5afdb1497e51db926e9e369dabe4631), [c68c2a3](https://github.com/dispoclavier/nouvel-azerty/commit/c68c2a3f6515e7f6a4a2252f496fa15d262e0536), [cec1df2](https://github.com/dispoclavier/nouvel-azerty/commit/cec1df2339ad9f71efd55d710c4b9dbfb171ab75), [439fa55](https://github.com/dispoclavier/nouvel-azerty/commit/439fa5538931f0f777be44a6969492599066a033), [86b4314](https://github.com/dispoclavier/nouvel-azerty/commit/86b4314f3f882aa9b7e302b34f18ee25d11fe4d4), [81c31c7](https://github.com/dispoclavier/nouvel-azerty/commit/81c31c7690af71b2cedc374d2c6c7eadfbe0791b), [a050c53](https://github.com/dispoclavier/nouvel-azerty/commit/a050c53294c8740c11ede2e8d27e546831a11ccd), [bb3410c](https://github.com/dispoclavier/nouvel-azerty/commit/bb3410c6ec6234150fe6d180652ac016b14a728a), [fa4d848](https://github.com/dispoclavier/nouvel-azerty/commit/fa4d848ed07dc45a0015cd82ecb558617a23c935) [7fc4e8e](https://github.com/dispoclavier/nouvel-azerty/commit/7fc4e8e73f94fa102e5510140df61ec0246a311d), compose-2.yml [f478020](https://github.com/dispoclavier/nouvel-azerty/commit/f47802067198ddd420fd7911e99945a96b3c7c85), [527a77d](https://github.com/dispoclavier/nouvel-azerty/commit/527a77df0e8e9126d955160edf26e1e690cf260d), [b2294aa](https://github.com/dispoclavier/nouvel-azerty/commit/b2294aa31e874653f7cb9b2c95a32b845731a7eb), [79f3356](https://github.com/dispoclavier/nouvel-azerty/commit/79f3356d231c6ceffc128677e3e3394f9cf12421)
	* Améliorer la lisibilité des annotations. compose-1.yml [eb06a29](https://github.com/dispoclavier/nouvel-azerty/commit/eb06a29e76448c719524d34f3248afffb0a8c629)
	* Mettre à jour les termes. kbcommon.h [3572a9f](https://github.com/dispoclavier/nouvel-azerty/commit/3572a9f3f175df501ce3c4c37fd597d6a6b583a2)
	* Mettre à jour le numéro de version. kbfrFRs.RC [4d87273](https://github.com/dispoclavier/nouvel-azerty/commit/4d872731726851e149a3bd51cd4dc4c602be13ee), kbfredis.RC [a6b183e](https://github.com/dispoclavier/nouvel-azerty/commit/a6b183e51dfa951e88f2d8311f7f62b7cc10a3a4)

## 4.25.0 (2025-03-15)

Correction des groupes des symboles pour plus d’utilité.

Rectification et simplification de séquences de composition.

Complétion de la touche morte réfléchi.

Introduction du concept de « groupe 1 bis ».

* Composition :
	* Corriger les séquences de "⧤" U29E4, "⧥" U29E5. compose-1.yml [d093206](https://github.com/dispoclavier/nouvel-azerty/commit/d0932063616f358c2411ab3fc09cf235565850e1)
	* Corriger ou simplifier les séquences de "⋍" U22CD, "⭇" U2B47. compose-1.yml [5b02559](https://github.com/dispoclavier/nouvel-azerty/commit/5b0255949897d65ec7e712a76593207ddaa886fe)
	* Corriger les séquences de "⇴" U21F4, "⇽" U21FD, "⇾" U21FE, "⋮" U22EE, "⌀" U2300, "♂" U2642, "⤒" U2912, "⤓" U2913, "⥡" U2961. compose-1.yml [eca3b50](https://github.com/dispoclavier/nouvel-azerty/commit/eca3b5040d2f139ccb1174431048cb52252418c5), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Simplifier les séquences de "↧" U21A7, "⇑" U21D1, "⇓" U21D3, "⇔" U21D4, "⇕" U21D5, "⇖" U21D6, "⇗" U21D7, "⇘" U21D8, "⇙" U21D9, "⇤" U21E4, "⋭" U22ED, "⤒" U2912. ibidem
	* Corriger les séquences de "⋴" U22F4, "⩡" U2A61. compose-1.yml [b7717d7](https://github.com/dispoclavier/nouvel-azerty/commit/b7717d71e2123af8ca5a74753b222f1f0df8444f), [c16967c](https://github.com/dispoclavier/nouvel-azerty/commit/c16967c1b8ac6bf3982dd2da71de363b265b937a), [deec65c](https://github.com/dispoclavier/nouvel-azerty/commit/deec65cd343442b41ce90108888371057f58ecd3), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Mettre à jour les séquences de "⊼" U22BC, "⊽" U22BD, "⋶" U22F6, "⋷" U22F7, "⋽" U22FD, "⋾" U22FE. compose-1.yml [7dbc74b](https://github.com/dispoclavier/nouvel-azerty/commit/7dbc74bc447fc5c713477c3de1d5bd12dfeff53d), [5318554](https://github.com/dispoclavier/nouvel-azerty/commit/5318554c48fadd9d797a0422403d750783c73758), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Rectifier, compléter ou simplifier les séquences de "⤈" U2908, "⤉" U2909, "⤌" U290C, "⤍" U290D, "⤎" U290E, "⤏" U290F, "⤐" U2910, "⤙" U2919, "⤚" U291A, "⤛" U291B, "⤜" U291C, "⤡" U2921, "⤢" U2922, "⤣" U2923, "⤤" U2924, "⤥" U2925, "⤦" U2926, "⤳" U2933, "⤴" U2934, "⤵" U2935, "⤶" U2936, "⤷" U2937, "⥅" U2945, "⥆" U2946, "⥉" U2949. compose-1.yml [2078900](https://github.com/dispoclavier/nouvel-azerty/commit/2078900a0fbd8a522269e04860fb64b00342494f), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Rectifier, compléter ou simplifier les séquences de "⥌" U294C, "⥍" U294D, "⥏" U294F, "⥑" U2951, "⥒" U2952, "⥓" U2953, "⥔" U2954, "⥕" U2955, "⥖" U2956, "⥗" U2957, "⥘" U2958, "⥙" U2959, "⥛" U295B, "⥜" U295C, "⥝" U295D, "⥞" U295E, "⥟" U295F, "⥠" U2960, "⥡" U2961, "⥣" U2963, "⥤" U2964, "⥥" U2965, "⥧" U2967, "⥨" U2968, "⥩" U2969, "⥫" U296B, "⥬" U296C, "⥭" U296D, "⥮" U296E, "⥯" U296F. compose-1.yml [8e818d9](https://github.com/dispoclavier/nouvel-azerty/commit/8e818d91c3c4745c92a96049d358070eafd5ddaa), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Mettre à jour et compléter les séquences de "⥼" U297C, "⥽" U297D, "⥾" U297E, "⥿" U297F. compose-1.yml [d20979e](https://github.com/dispoclavier/nouvel-azerty/commit/d20979e3405d40baa3dc413753cd1041dec03b77), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086), [568ca7f](https://github.com/dispoclavier/nouvel-azerty/commit/568ca7fce6bac8ec9e4d7b6e58c62c2537cd1da8), [51ec882](https://github.com/dispoclavier/nouvel-azerty/commit/51ec882589a6c0e3b6c5b653d8bfe253ebc1c396)
	* Ajouter des séquences simplifiées optionnelles pour "⇺" U21FA, "⇻" U21FB, "⤈" U2908, "⤉" U2909. compose-1.yml [27caa25](https://github.com/dispoclavier/nouvel-azerty/commit/27caa25d6f8cbdde8e327339231e85c92484c923), [4fe1f28](https://github.com/dispoclavier/nouvel-azerty/commit/4fe1f280e5b143cbc0d0db6151a9ac514ef83cc5), [b5f6783](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086)
	* Ajouter des séquences simplifiées optionnelles pour "⤀" U2900, "⤁" U2901, "⤂" U2902, "⤃" U2903 et simplifier au maximum les séquences de ces symboles. compose-1.yml [29986b0](https://github.com/dispoclavier/nouvel-azerty/commit/29986b0ff6e7189575e27b8e923196e75144c5ef)
	* Ajouter des séquences simplifiées optionnelles pour "⤔" U2914, "⤕" U2915, "⤗" U2917, "⤘" U2918. compose-1.yml [478a03d](https://github.com/dispoclavier/nouvel-azerty/commit/478a03da3a213978c5c55c21fd58b41722d143a3)
	* Rectifier, simplifier et documenter les séquences de "⦨" U29A8, "⦩" U29A9, "⦪" U29AA, "⦫" U29AB, "⦬" U29AC, "⦭" U29AD, "⦮" U29AE, "⦯" U29AF. compose-1.yml [7e56a58](https://github.com/dispoclavier/nouvel-azerty/commit/7e56a58b320fb4db3b312510f0f079178133f35d), [9177f1d](https://github.com/dispoclavier/nouvel-azerty/commit/9177f1de6d45cb01aab6e6755fcc1b1513de904e), [cca4a7d](https://github.com/dispoclavier/nouvel-azerty/commit/cca4a7d5559e10f26b438a110a43817446b2c711)
	* Mettre à jour, simplifier et documenter les séquences de "∠" U2220, "∡" U2221, "∢" U2222, "⊿" U22BF, "⟀" U27C0, "⦛" U299B, "⦞" U299E, "⦟" U299F, "⦠" U29A0, "⦡" U29A1, "⦢" U29A2, "⦣" U29A3, "⦤" U29A4, "⦦" U29A6, "⧶" U29F6. compose-1.yml [7b6073d](https://github.com/dispoclavier/nouvel-azerty/commit/7b6073d767c348135a27c9f54e709c316420e628), [b3e061d](https://github.com/dispoclavier/nouvel-azerty/commit/b3e061dc0910f7edd8904ab7bd6cc8888013883e), [4aa5cce](https://github.com/dispoclavier/nouvel-azerty/commit/4aa5cce8f0e88a642e451fb9ecb5678cedb40788)
	* Rectifier et documenter les séquences de "↜" U219C, "↝" U219D, "⇜" U21DC, "⇝" U21DD, "≲" U2272, "⟿" U27FF, "⪅" U2A85, "⪞" U2A9E, "⬳" U2B33. compose-1.yml [3f3950d](https://github.com/dispoclavier/nouvel-azerty/commit/3f3950d8b51327e5f22f1ea9adfae9e74597a733)
* Transformations :
	* Groupes des symboles :
		* Redonder "†" U2020 dans le groupe 8 de "%" à la place de "⛯" U26EF, qui va dans le groupe 8 de "\\" à la place de "♽" U267D, qui va dans le groupe 7 à la place de "♼" U267C, qui va dans le groupe 6 à la place de "♻" U267B, qui va dans le groupe 4 à la place de "∜" U221C, qui va dans le groupe 3 à la place de "∛" U221B, qui va dans le groupe 2 à la place de "√" U221A, qui va dans le groupe 1 à la place de "☆" U2606, qui va dans le groupe 1 de "%" à la place de "‰" U2030, qui va dans le groupe 11 à la place de "⏫" U23EB, qui va dans le groupe 10 de "'" à la place de "⤴" U2934, qui va dans le groupe 6 à la place de "➿" U27BF, qui va dans le groupe 10 de "/" à la place de "⋈" U22C8, qui va dans le groupe 12 de ">" à la place de "⛛" U26DB, qui va dans le groupe 11 à la place de "▼" U25BC, qui va dans le groupe 10 à la place de "☛" U261B, qui est en composition par « ¦ipd » ou « ¦fri » mais n’est pas d’émoji et n’est pas recommandé. compose-3.yml [c0fc525](https://github.com/dispoclavier/nouvel-azerty/commit/c0fc525d8602b46114979d8091e8202a4893156b), [ed8d3c2](https://github.com/dispoclavier/nouvel-azerty/commit/ed8d3c298a43a7ba832dca2de4d097fd39bbf4a1)
		* Redonder "∄" U2204 dans le groupe 4 de "%" à la place de "↯" U21AF, qui va dans le groupe 3 à la place de "⚡" U26A1, qui va dans le groupe 2 à la place de "‱" U2031, qui va dans le groupe 12 à la place de "⏬" U23EC, qui va dans le groupe 10 de "}" à la place de "⤵" U2935, qui va dans le groupe 5 de "'" à la place de "➰" U27B0, qui va dans le groupe 11 de "/" à la place de "▲" U25B2, qui va dans le groupe 10 de "<" à la place de "☚" U261A, qui est en composition par « ¦ipg » ou « ¦fli » mais n’est pas d’émoji et n’est pas recommandé. ibidem
	* Réfléchi : Prendre en charge "∽" U223D, qui est aussi en composition par « ¦~\ ». compose-2.yml [9ef34fc](https://github.com/dispoclavier/nouvel-azerty/commit/9ef34fc4f96ad6b6bd965bb649679a517a036f5b), compose-1.yml [5b02559](https://github.com/dispoclavier/nouvel-azerty/commit/5b0255949897d65ec7e712a76593207ddaa886fe)
* Documentation :
	* Renommer le « groupe extra » en « groupe 1 bis ». compose-3.yml [8c2c0fd](https://github.com/dispoclavier/nouvel-azerty/commit/8c2c0fd72bef520195db45c6b8d9a9ad154eff88)
	* Corriger ou ajouter des annotations. compose-1.yml [0c30e4a](https://github.com/dispoclavier/nouvel-azerty/commit/0c30e4ae988e7f43704c5eccc0bdefe55216300b), [5b02559](https://github.com/dispoclavier/nouvel-azerty/commit/5b0255949897d65ec7e712a76593207ddaa886fe), [e565f40](https://github.com/dispoclavier/nouvel-azerty/commit/e565f40ecfa19dbd417137238e5ae28a58818dd8), [85f0935](https://github.com/dispoclavier/nouvel-azerty/commit/85f09351973d3b5d36784448452773205b628a9c), [eca3b50](https://github.com/dispoclavier/nouvel-azerty/commit/eca3b5040d2f139ccb1174431048cb52252418c5), [7dbc74b](https://github.com/dispoclavier/nouvel-azerty/commit/7dbc74bc447fc5c713477c3de1d5bd12dfeff53d), [47e1c2b](https://github.com/dispoclavier/nouvel-azerty/commit/47e1c2bf8ed3353f861a774f86c27e62c07d616d), [d20979e](https://github.com/dispoclavier/nouvel-azerty/commit/d20979e3405d40baa3dc413753cd1041dec03b77), [bbbdf54](https://github.com/dispoclavier/nouvel-azerty/commit/bbbdf5411493384a39100172479ccfd9e855c295), [e4ce25d](https://github.com/dispoclavier/nouvel-azerty/commit/e4ce25d2cd2b1390bff5305f5ee0bf8bc47241ab), [27caa25](https://github.com/dispoclavier/nouvel-azerty/commit/27caa25d6f8cbdde8e327339231e85c92484c923), [4fe1f28](https://github.com/dispoclavier/nouvel-azerty/commit/4fe1f280e5b143cbc0d0db6151a9ac514ef83cc5), [cca4a7d](https://github.com/dispoclavier/nouvel-azerty/commit/cca4a7d5559e10f26b438a110a43817446b2c711), [4aa5cce](https://github.com/dispoclavier/nouvel-azerty/commit/4aa5cce8f0e88a642e451fb9ecb5678cedb40788), [a1f8b75](https://github.com/dispoclavier/nouvel-azerty/commit/a1f8b75ec4d9f710f10fece4164839e8da003c76), [d66fc03](https://github.com/dispoclavier/nouvel-azerty/commit/d66fc032233e10299e794fe0bbff68157a3d8bf2), compose-2.yml [c557cce](https://github.com/dispoclavier/nouvel-azerty/commit/c557cce828c1e5fbf4ef76b97a417f6400a4a220)
	* Améliorer la lisibilité des annotations. compose-1.yml [799074f](https://github.com/dispoclavier/nouvel-azerty/commit/799074f785c91dc41dc85de32c4d3b46912c85be)
	* Compléter le journal des modifications : Ajouter des liens pour les polices. CHANGELOG,md [f5d8dd9](https://github.com/dispoclavier/nouvel-azerty/commit/f5d8dd993ffdc770c72890d24925e28e61ce986c), [ffe7a7e](https://github.com/dispoclavier/nouvel-azerty/commit/ffe7a7e59825ed4a75236878b43878ae6adc04f4)
	* Ajouter un PDF documentant la touche morte groupe.

## 4.24.0 (2025-03-04)

Correction de la prise en charge des émojis "☀" U2600 et "☠" U2620.

Rectification de la touche morte exposant.

* Composition :
	* Prendre en charge l’émoji "☀" U2600 par « ¦sol », « ¦SOL », « ¦sun », « ¦SUN ». compose-1.yml [c4923d0](https://github.com/dispoclavier/nouvel-azerty/commit/c4923d0ab7f738e911a7552de60b6c3877891b52)
	* Prendre en charge l’émoji "☠" U2620 par « ¦tox », « ¦TOX ». ibidem
* Transformations :
	* Groupes des symboles :
		* Groupes de "$" :
			* Ajouter "☼" U263C dans le groupe 4 à la place de l’émoji "☀" U2600, qui va dans un groupe extra et en composition. compose-3.yml [01d15e9](https://github.com/dispoclavier/nouvel-azerty/commit/01d15e93e1ab22206a075a9927fb191c5003d215), [c363b25](https://github.com/dispoclavier/nouvel-azerty/commit/c363b256878da34a2baf6e7d86e3430ddf1976c4), [14ff1e4](https://github.com/dispoclavier/nouvel-azerty/commit/14ff1e4372ea62a721aa3f3284b409511ae438e9), [35a0eae](https://github.com/dispoclavier/nouvel-azerty/commit/35a0eaed2eed6107e944e1833107ea5904904b01)
			* Ajouter un groupe extra pour l’émoji "☀" U2600. ibidem
		* Groupes de "~" :
			* Ajouter "☥" U2625 dans le groupe 5 à la place de l’émoji "☠" U2620, qui va dans un groupe extra et en composition. ibidem
			* Ajouter un groupe extra pour l’émoji "☠" U2620. ibidem
	* Exposant groupe 1 par "u" : Mettre "ᶷ" U1DB7 à la place de "ᶿ" U1DBF, qui est par "t". compose-2.yml [7a216e6](https://github.com/dispoclavier/nouvel-azerty/commit/7a216e61d3c65f7ac8aeee54e923c22d935f7095)
	* Exposant groupe 2 par "u" : Redonder "ᶿ" U1DBF à la place de "ᶷ" U1DB7, qui est dans exposant groupe 1. ibidem
	* Exposant et crochet rétroflexe : Rectifier la prise en charge de "𐞹" U107B9, par "k" et "!" au lieu de "m". compose-2.yml [56ae33e](https://github.com/dispoclavier/nouvel-azerty/commit/56ae33eae52518643340c42a3a0314ecab84b42a)
* Documentation :
	* Corriger et compléter des annotations. compose-2.yml [d717a87](https://github.com/dispoclavier/nouvel-azerty/commit/d717a8770f1bf3f70ee0ad01e21ec6573a56bc9e), [21ccde6](https://github.com/dispoclavier/nouvel-azerty/commit/21ccde69698f9cb501bfbc3ae30fbdf8728cac14), compose-3.yml [9385cd1](https://github.com/dispoclavier/nouvel-azerty/commit/9385cd106731dadaf9d0ec6936b7a4a49dec3fa8), [35a0eae](https://github.com/dispoclavier/nouvel-azerty/commit/35a0eaed2eed6107e944e1833107ea5904904b01), dispocla.cpp [2849192](https://github.com/dispoclavier/nouvel-azerty/commit/28491921e564bc4d3f3376a90960dc920b3f0dd9)
	* Corriger le journal des modifications. CHANGELOG.md [b75f30a](https://github.com/dispoclavier/nouvel-azerty/commit/b75f30a241329b7ebe8c9630c28c46a8bbe4108f)

## 4.23.0 (2025-02-23)

Rectification de touches mortes.

* Composition : Corriger les séquences de "⫨" U2AE8, "⫭" U2AED. compose-1.yml [9ffa049](https://github.com/dispoclavier/nouvel-azerty/commit/9ffa049ec9c978ecad7348db76cb7df251fff29d)
* Transformations : Exposant et crochet rétroflexe, groupes 1–5 : Rectifier "𐞟" U1079F. compose-2.yml [4032c88](https://github.com/dispoclavier/nouvel-azerty/commit/4032c886ce318fd209cebbe744ec4e698df597ca)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [ae2965f](https://github.com/dispoclavier/nouvel-azerty/commit/ae2965f626abf1185a0e89e5259c98c36b67630c), [9ffa049](https://github.com/dispoclavier/nouvel-azerty/commit/9ffa049ec9c978ecad7348db76cb7df251fff29d), compose-2.yml [4032c88](https://github.com/dispoclavier/nouvel-azerty/commit/4032c886ce318fd209cebbe744ec4e698df597ca), [71a17aa](https://github.com/dispoclavier/nouvel-azerty/commit/71a17aae237c1f1148c6edf161be49083d9d822f), compose-3.yml [76c7046](https://github.com/dispoclavier/nouvel-azerty/commit/76c7046aef59b07621ee3829ff090a41b759ad45)
	* Rectifier le journal des modifications. CHANGELOG.md [f734ec7](https://github.com/dispoclavier/nouvel-azerty/commit/f734ec792c0bfdde0ebb9a4086689c219aed9294), [e433b6d](https://github.com/dispoclavier/nouvel-azerty/commit/e433b6dabf39d6a0219349db933013ba60f3c0bd)
	* Rectifier la note de version. Note-de-version.md [185c875](https://github.com/dispoclavier/nouvel-azerty/commit/185c875fdb105c587f9a4ec8d65676b7c51ae054)

## 4.22.0 (2025-02-19)

Rectification et simplification de la séquence de composition de la lettre "ȹ" U0239.

* Composition : Rectifier et simplifier "ȹ" U0239. compose-1.yml [17e32ec](https://github.com/dispoclavier/nouvel-azerty/commit/17e32ec85b5389b781cb05b1eac410eed46d9245)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [17e32ec](https://github.com/dispoclavier/nouvel-azerty/commit/17e32ec85b5389b781cb05b1eac410eed46d9245), [6a04730](https://github.com/dispoclavier/nouvel-azerty/commit/6a04730b325408bf94dc83bc1966625796543388)
	* Rectifier la note de version. Note-de-version.md [6b26aad](https://github.com/dispoclavier/nouvel-azerty/commit/6b26aadbe35e624463e7b1a44137c4525a5a1083)

## 4.21.0 (2025-02-16)

Reconception des séquences de composition de nombreux symboles mathématiques.

* Composition :
	* Simplifier ou corriger les séquences de "←" U2190, "↑" U2191, "→" U2192, "↓" U2193, "↔" U2194, "↕" U2195, "↖" U2196, "↗" U2197, "↘" U2198, "↙" U2199, "↚" U219A, "↛" U219B, "↟" U219F, "↡" U21A1 , "↥" U21A5, "↧" U21A7, "↨" U21A8, "⇐" U21D0, "⇑" U21D1, "⇒" U21D2, "⇓" U21D3, "⇔" U21D4, "⇕" U21D5, "⇖" U21D6, "⇗" U21D7, "⇘" U21D8, "⇙" U21D9, "⇚" U21DA, "⇛" U21DB, "∊" U220A, "∍" U220D, "∦" U2226, "≤" U2264, "≥" U2265, "≦" U2266, "≨" U2268, "≮" U226E, "≰" U2270, "≱" U2271, "⊆" U2286, "⊇" U2287, "⊈" U2288, "⊉" U2289, "⊊" U228A, "⊋" U228B, "⊑" U2291, "⊒" U2292, "⊭" U22AD, "⊮" U22AE, "⊯" U22AF, "⊴" U22B4, "⊵" U22B5, "⋈" U22C8, "⋍" U22CD, "⋚" U22DA, "⋛" U22DB, "⋜" U22DC, "⋝" U22DD, "⋢" U22E2, "⋣" U22E3, "⋤" U22E4, "⋥" U22E5, "⋬" U22EC, "⋭" U22ED, "⋴" U22F4, "⋷" U22F7, "⋸" U22F8, "⋼" U22FC, "⋾" U22FE, "◺" U25FA, "⟖" U27D6, "⟾" U27FE, "⤇" U2907, "⤊" U290A, "⤋" U290B, "⥒" U2952, "⥖" U2956, "⥘" U2958, "⧐" U29D0, "⧒" U29D2, "⧡" U29E1, "⧦" U29E6, "⩽" U2A7D, "⩾" U2A7E, "⩿" U2A7F, "⪀" U2A80, "⪃" U2A83, "⪄" U2A84, "⪇" U2A87, "⪈" U2A88, "⪋" U2A8B, "⪕" U2A95, "⪖" U2A96, "⪚" U2A9A, "⪛" U2A9B, "⪜" U2A9C, "⪬" U2AAC, "⪭" U2AAD, "⪯" U2AAF, "⪰" U2AB0, "⪱" U2AB1, "⪲" U2AB2, "⫃" U2AC3, "⫄" U2AC4, "⫢" U2AE2, "⫵" U2AF5, "⫹" U2AF9, "⫺" U2AFA, "⭅" U2B45, "⭆" U2B46. compose-1.yml [d845f0a](https://github.com/dispoclavier/nouvel-azerty/commit/d845f0aa6133d8ed974a2eb45029ee4e77453937), [cd14b40](https://github.com/dispoclavier/nouvel-azerty/commit/cd14b4079507173f27aef8f23a3f5e9339f7c145)
	* Simplifier ou corriger les séquences de "↑" U2191, "↕" U2195, "↞" U219E, "↟" U219F, "↠" U21A0, "↡" U21A1, "↤" U21A4, "↥" U21A5, "↦" U21A6, "↧" U21A7, "↨" U21A8, "↰" U21B0, "↱" U21B1, "↾" U21BE, "↿" U21BF, "⇂" U21C2, "⇃" U21C3, "⇅" U21C5, "⇈" U21C8, "⇊" U21CA, "⇤" U21E4, "⇥" U21E5, "⇵" U21F5, "⥶" U2976. compose-1.yml [e2a8a34](https://github.com/dispoclavier/nouvel-azerty/commit/e2a8a34010f6294cb66f8b0c4375f001c545f9d3)
	* Simplifier ou corriger les séquences de "⃡" U20E1, "⇆" U21C6, "⇍" U21CD, "⇏" U21CF, "⇑" U21D1, "⇕" U21D5, "⇖" U21D6, "⇗" U21D7, "⇘" U21D8, "⇙" U21D9, "⇚" U21DA, "⇛" U21DB, "⟰" U27F0, "⟱" U27F1, "⟵" U27F5, "⟶" U27F6, "⟷" U27F7, "⟸" U27F8, "⟸" U27F8, "⟹" U27F9, "⟹" U27F9, "⟺" U27FA, "⟺" U27FA, "⟻" U27FB, "⟻" U27FB, "⟼" U27FC, "⟼" U27FC, "⟽" U27FD, "⟽" U27FD, "⟾" U27FE, "⟾" U27FE, "⟿" U27FF, "⤊" U290A, "⤋" U290B, "⭅" U2B45, "⭆" U2B46. compose-1.yml [4d101ad](https://github.com/dispoclavier/nouvel-azerty/commit/4d101adcaea963e102870e5286c3781a991a99a0)
* Transformations : Barré et drapeau : Supprimer ("≰" U2270, "≱" U2271, "⊊" U228A, "⊋" U228B). compose-2.yml [965a45a](https://github.com/dispoclavier/nouvel-azerty/commit/965a45a1e4d7f04c730ef86c501ec69996a14d80)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [d845f0a](https://github.com/dispoclavier/nouvel-azerty/commit/d845f0aa6133d8ed974a2eb45029ee4e77453937), [cd14b40](https://github.com/dispoclavier/nouvel-azerty/commit/cd14b4079507173f27aef8f23a3f5e9339f7c145), [e2a8a34](https://github.com/dispoclavier/nouvel-azerty/commit/e2a8a34010f6294cb66f8b0c4375f001c545f9d3), [4d101ad](https://github.com/dispoclavier/nouvel-azerty/commit/4d101adcaea963e102870e5286c3781a991a99a0), [ac2ace0](https://github.com/dispoclavier/nouvel-azerty/commit/ac2ace0d1396bbbf9a97d67d66e721599a9bb778), [1d96b0f](https://github.com/dispoclavier/nouvel-azerty/commit/1d96b0f3ddd29263a0450d72c97fd3a1b07f4b37), [284f27c](https://github.com/dispoclavier/nouvel-azerty/commit/284f27c3149039d92487fcdc1f222439d68aed24), compose-2.yml [f49270f](https://github.com/dispoclavier/nouvel-azerty/commit/f49270f6243c20970ebf0c8ae37af320f23ec1c8)
	* Améliorer l’intertitrage. compose-1.yml [1d96b0f](https://github.com/dispoclavier/nouvel-azerty/commit/1d96b0f3ddd29263a0450d72c97fd3a1b07f4b37), [284f27c](https://github.com/dispoclavier/nouvel-azerty/commit/284f27c3149039d92487fcdc1f222439d68aed24), compose-2.yml [b912a57](https://github.com/dispoclavier/nouvel-azerty/commit/b912a57175737197db510e5e1231849c5c638a90)

## 4.20.0 (2025-02-02)

Amélioration de l’utilité de la touche morte accent circonflexe par l’hatchek en double frappe.

Simplification ou correction de plusieurs séquences de composition.

* Composition :
	* Simplifier ou corriger les séquences de "⇝" U21DD, "≄" U2244, "≇" U2247, "≉" U2249, "≊" U224A, "≌" U224C, "⋍" U22CD, "⌉" U2309, "▴" U25B4, "⟿" U27FF, "⤨" U2928, "⤩" U2929, "⥲" U2972, "⦭" U29AD, "⦮" U29AE, "⧩" U29E9, "⨳" U2A33, "⩡" U2A61, "⩬" U2A6C, "⩮" U2A6E, "⪟" U2A9F, "⪠" U2AA0, "⫳" U2AF3, "⭁" U2B41, "⭇" U2B47, "⭉" U2B49. compose-1.yml [5f99d7a](https://github.com/dispoclavier/nouvel-azerty/commit/5f99d7a6eca6d996c7319866173f5e918ea3390b)
	* Simplifier ou corriger les séquences de "⋊" U22CA, "◥" U25E5, "◹" U25F9, "⟁" U27C1, "⤯" U292F, "⥔" U2954, "⦠" U29A0, "⦡" U29A1, "⦥" U29A5, "⦩" U29A9, "⦪" U29AA, "⧋" U29CB, "⧌" U29CC, "⧕" U29D5, "⧨" U29E8, "⨲" U2A32, "⨹" U2A39, "⨺" U2A3A, "⨻" U2A3B. compose-1.yml [29fd230](https://github.com/dispoclavier/nouvel-azerty/commit/29fd2309db10dc20f63469c2696a209dbb53b1d4)
* Transformations :
	* Exposant :
		* Reprendre "⁂" U2042, qui était dans accent circonflexe. compose-2.yml [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed)
		* Exposant et indice (petite capitale) et rayé : Abréger la saisie de "ᶧ" U1DA7. compose-2.yml [9f856a8](https://github.com/dispoclavier/nouvel-azerty/commit/9f856a82e1dd8b0c18d61ef15027827c81a3f12b)
		* Combinant en chef et cédille : Abréger la saisie de "ᷗ" U1DD7. ibidem
	* Tilde et perluète : Redonder "△" U25B3 à la place de "ǃ" U01C3 comme caractère espaçant vedette, pour la cohérence avec "⃤" U20E4 et la silhouette de la perluète. compose-2.yml [e2916a6](https://github.com/dispoclavier/nouvel-azerty/commit/e2916a6cad4db68b44a89ea35cf8c7f973d0a374)
	* Accent circonflexe : Supprimer "⁂" U2042, qui va dans exposant. compose-2.yml [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed)
	* Hatchek : Simplifier le raccourci par accent circonflexe en remplaçant par la double frappe la triple frappe, désormais utilisée pour l’accent circonflexe souscrit, augmenté d’une facilité par l’accord accent circonflexe et rond en chef. ibidem
* Documentation : Corriger et compléter des annotations. compose-1.yml [5f99d7a](https://github.com/dispoclavier/nouvel-azerty/commit/5f99d7a6eca6d996c7319866173f5e918ea3390b), [fbd6680](https://github.com/dispoclavier/nouvel-azerty/commit/fbd6680fe8c9f79ebf08b55899cf8d19f9db9530), [1bb5e82](https://github.com/dispoclavier/nouvel-azerty/commit/1bb5e82ef535715cfcc3dd31eafb49cb2edc67b9), compose-2.yml [e2916a6](https://github.com/dispoclavier/nouvel-azerty/commit/e2916a6cad4db68b44a89ea35cf8c7f973d0a374), [9f856a8](https://github.com/dispoclavier/nouvel-azerty/commit/9f856a82e1dd8b0c18d61ef15027827c81a3f12b), [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed), compose-3.yml [a7f700b](https://github.com/dispoclavier/nouvel-azerty/commit/a7f700b7397ba7c4ca412769291d25f8a93c71c0)

## 4.19.0 (2025-01-26)

Amélioration du groupe 1 des lettres pour plus d’intuitivité et de sûreté et moins de redondances.

Débogage, simplification ou correction de plusieurs séquences de composition.

* Composition :
	* Déboguer "⫊" U2ACA. compose-1.yml [c54f712](https://github.com/dispoclavier/nouvel-azerty/commit/c54f7127f27bb73ec533caca54bf656682415d06)
	* Simplifier ou corriger les séquences de "⁄" U2044, "ℋ" U210B, "ℐ" U2110, "ℒ" U2112, "ℛ" U211B, "ℱ" U2131, "ℴ" U2134, "⌀" U2300, "⨢" U2A22, "⫂" U2AC2, "⫉" U2AC9, "⫊" U2ACA, "⫓" U2AD3, "⫖" U2AD6, "⫗" U2AD7. ibidem
* Transformations :
	* Simplifier les lettres composées pour les langues du Togo. compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df)
	* Groupes des lettres :
		* Groupe 1 :
			* Mettre "ʿ" U02BF par "l" U006C au lieu de "K", à la place de "ℓ" U2113 qui est par "L". compose-3.yml [8df19c1](https://github.com/dispoclavier/nouvel-azerty/commit/8df19c1e1fc6d85cb080720eaf5eeeacfca265d6)
			* Mettre "ʾ" U02BE par "m" au lieu de "k", à la place de "ɩ" U0269. ibidem
			* Redonder "ʔ" U0294 par "M" à la place de "Ɩ" U0196. ibidem
			* Mettre "Ɩ" U0196, "ɩ" U0269 par "I", "i" à la place de "Ĳ" U0132, "ĳ" U0133, qui vont par "J", "j" à la place de "Ɲ" U019D, "ɲ" U0272, qui vont par "N", "n" à la place de "Ŋ" U014A, "ŋ" U014B, qui vont par "G", "g" à la place de "Ə" U018F, "ə" U0259, qui vont par "H", "h" à la place de "Ǝ" U018E, "ǝ" U01DD, qui vont par "E", "e" à la place de "€" U20AC, qui est sur AltGr + E et sur AltFr + E. ibidem
			* Redonder "Ɑ" U2C6D, "ɑ" U0251 par "K", "k" aux places laissées par "ʿ" U02BF, "ʾ" U02BE. ibidem
		* Groupe 2 :
			* Mettre "Ə" U018F, "ə" U0259 à la place de "Ǝ" U018E, "ǝ" U01DD, qui sont dans le groupe 1. ibidem
			* Mettre "Ŋ" U014A, "ŋ" à la place de "Ɲ" U019D, "ɲ", qui sont dans le groupe 1. ibidem
	* Macron :
		* Supprimer "ꭗ" UAB57, qui est dans le groupe 5. compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df)
		* Supprimer "ꭙ" UAB59, qui est dans le groupe 11. ibidem
	* Accent grave : Utiliser "*" au lieu de "x" comme caractère de base de "˟" U02DF. ibidem
* Documentation : Corriger et compléter des annotations. compose-1.yml [c54f712](https://github.com/dispoclavier/nouvel-azerty/commit/c54f7127f27bb73ec533caca54bf656682415d06), compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df), compose-3.yml [8df19c1](https://github.com/dispoclavier/nouvel-azerty/commit/8df19c1e1fc6d85cb080720eaf5eeeacfca265d6)

## 4.18.0 (2025-01-21)

Débogage des lettres composées pour les langues du Togo.

* Composition :
	* Simplifier ou corriger les séquences de "𐞉" U10789, "𐞫" U107AB. compose-1.yml [f247651](https://github.com/dispoclavier/nouvel-azerty/commit/f24765119811302e5f854adc3300ba4488ebad1f)
	* Simplifier ou corriger les séquences de "⃛" U20DB, "⃜" U20DC. compose-1.yml [1dced0c](https://github.com/dispoclavier/nouvel-azerty/commit/1dced0c7f79ff9a845e56d5c332eed32e4d65b7e)
* Transformations : Déboguer "Ǝ" U018E, "ǝ" U01DD dans les lettres composées pour les langues du Togo. compose-2.yml [b2a40bb](https://github.com/dispoclavier/nouvel-azerty/commit/b2a40bbaeb1ad9e91ac0b8ab7ccd71287664e2c1)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [1dced0c](https://github.com/dispoclavier/nouvel-azerty/commit/1dced0c7f79ff9a845e56d5c332eed32e4d65b7e), compose-2.yml [b2a40bb](https://github.com/dispoclavier/nouvel-azerty/commit/b2a40bbaeb1ad9e91ac0b8ab7ccd71287664e2c1)
	* Améliorer le tri. compose-1.yml [f247651](https://github.com/dispoclavier/nouvel-azerty/commit/f24765119811302e5f854adc3300ba4488ebad1f)

## 4.17.0 (2025-01-19)

Simplification des nombres cerclés et de nombreuses séquences de composition.

Amélioration de la prise en charge des symboles de recyclage.

* Composition :
	* Déboguer "ℊ" U210A, "ℋ" U210B, "ℐ" U2110, "ℒ" U2112, "ℓ" U2113, "℘" U2118, "ℛ" U211B, "ℬ" U212C, "ℯ" U212F, "ℰ" U2130, "ℱ" U2131, "ℳ" U2133, "ℴ" U2134. compose-1.yml [74fec91](https://github.com/dispoclavier/nouvel-azerty/commit/74fec9174c2db2b021320e5cc0cae29e254bd8f7)
	* Prendre en charge les nombres cerclés à la place de la touche morte Brève inversée. compose-1.yml [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8)
	* Simplifier les séquences des nombres cerclés. ibidem, compose-1.yml [7a5cb48](https://github.com/dispoclavier/nouvel-azerty/commit/7a5cb485b7065b34ea5325e234f728b7dc5a23a7)
	* Redonder les symboles de recyclage "♲" U2672, "♳" U2673, "♴" U2674, "♵" U2675, "♶" U2676, "♷" U2677, "♸" U2678, "♹" U2679, "♺" U267A, "♻" U267B par des sigles. compose-1.yml [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [f6383f4](https://github.com/dispoclavier/nouvel-azerty/commit/f6383f4e84ab90e1f04f3c2034dc831f403cf69e), [6f8ceeb](https://github.com/dispoclavier/nouvel-azerty/commit/6f8ceebb64353638181c8ea1aa51e49adb900944), [90ee438](https://github.com/dispoclavier/nouvel-azerty/commit/90ee438b4f7443052c501f6c39146fe67f1b3219), [09dcc1c](https://github.com/dispoclavier/nouvel-azerty/commit/09dcc1c1efb3e982ea25302da7b5ee4866dc4288), compose-2.yml [02a50f2](https://github.com/dispoclavier/nouvel-azerty/commit/02a50f2d473f340d2fdf449d3e5834620abb0ab8), compose-3.yml [e2d8f8f](https://github.com/dispoclavier/nouvel-azerty/commit/e2d8f8fa90cec54e93b2120394536d53b3bbde39)
	* Simplifier la séquence « ¦0/3 » de "↉" U2189 en « ¦0/ ». compose-1.yml [b9351a4](https://github.com/dispoclavier/nouvel-azerty/commit/b9351a4b4a5cf16439dab59c5cdf69cd9777a0b8)
	* Supprimer les caractères non critiques à la fin des séquences de "⇇" U21C7, "⇈" U21C8, "⇊" U21CA, "∯" U222F, "⋑" U22D1, "⟁" U27C1, "⦀" U2980, "⧈" U29C8, "⩎" U2A4E, "⩏" U2A4F, "⩓" U2A53, "⪢" U2AA2. compose-1.yml [7a5cb48](https://github.com/dispoclavier/nouvel-azerty/commit/7a5cb485b7065b34ea5325e234f728b7dc5a23a7)
	* Simplifier ou corriger les séquences de "⧉" U29C9. ibidem, compose-1.yml [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212)
	* Simplifier ou corriger les séquences de "ℬ" U212C, "ℵ" U2135, "ℶ" U2136, "∛" U221B, "∜" U221C, "∰" U2230, "♈" U2648, "♎" U264E, "♒" U2652, "♠" U2660, "♣" U2663, "⟠" U27E0, "⟵" U27F5, "⧞" U29DE, "⧻" U29FB, "⨌" U2A0C, "⨹" U2A39, "⨻" U2A3B, "⩘" U2A58, "⩚" U2A5A, "⫸" U2AF8, "⬱" U2B31, "꜡" UA721, "👈" U1F448, "👉" U1F449. compose-1.yml [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212)
	* Simplifier ou corriger les séquences de "϶" U03F6, "•" U2022, "ℂ" U2102, "ℭ" U212D, "ℰ" U2130, "ℸ" U2138, "ⅅ" U2145, "∄" U2204, "∇" U2207, "∐" U2210, "≜" U225C, "⋒" U22D2, "⋓" U22D3, "⌧" U2327, "⎄" U2384, "⎈" U2388, "⎋" U238B, "▪" U25AA, "▫" U25AB, "◦" U25E6, "♋" U264B, "✉" U2709, "⤾" U293E, "⫒" U2AD2. compose-1.yml [25d7ca8](https://github.com/dispoclavier/nouvel-azerty/commit/25d7ca85d883a34b0919af308b878cc0167a7567)
	* Simplifier ou corriger les séquences de "‣" U2023, "⁌" U204C, "⁍" U204D, "ℇ" U2107, "Ω" U2126, "℧" U2127, "∅" U2205, "∎" U220E, "⊛" U229B, "⌧" U2327, "▫" U25AB, "▴" U25B4, "▵" U25B5, "▾" U25BE, "▿" U25BF, "◂" U25C2, "◑" U25D1, "◒" U25D2, "◓" U25D3, "◦" U25E6, "☆" U2606, "☚" U261A, "☛" U261B, "⛎" U26CE, "⟴" U27F4, "⦷" U29B7, "⦹" U29B9, "⦺" U29BA, "⦻" U29BB, "⦼" U29BC, "⦽" U29BD, "⧀" U29C0, "⧁" U29C1, "⧬" U29EC, "⧭" U29ED, "⨀" U2A00, "🅭" U1F16D, "🅯" U1F16F. compose-1.yml [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb)
	* Simplifier ou corriger les séquences de "᷉" U1DC9, "᷏" U1DCF, "᷐" U1DD0, "᷒" U1DD2, "⁡" U2061, "⁢" U2062, "⁣" U2063, "⁤" U2064, "⃐" U20D0, "⃑" U20D1, "⃔" U20D4, "⃕" U20D5, "⃖" U20D6, "⃗" U20D7, "⃚" U20DA, "⃜" U20DC, "⃡" U20E1, "⃥" U20E5, "⃦" U20E6, "⃫" U20EB, "⃬" U20EC, "⃭" U20ED, "⃮" U20EE, "⃯" U20EF, "⅋" U214B, "↼" U21BC, "⥊" U294A, "⥌" U294C, "⥎" U294E, "⥏" U294F, "⥚" U295A, "⥜" U295C, "⥢" U2962, "⥣" U2963, "⥦" U2966, "⥪" U296A, "⥯" U296F, "⩯" U2A6F, "⫨" U2AE8, "⫩" U2AE9, "ꝰ" UA770, "𐞈" U10788, "𐞉" U10789, "𐞊" U1078A, "𐞐" U10790, "𐞞" U1079E, "𐞟" U1079F, "𐞫" U107AB, "𐞭" U107AD, "𐞮" U107AE. compose-1.yml [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db)
* Transformations :
	* Lettres composées pour les langues du Togo : Flexibiliser la sélection de groupe. compose-2.yml [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
	* Exposant et crosse : Dupliquer la plupart des lettres d’exposant et boucle. ibidem
	* Suscrit :
		* Suscrit et cédille : Ajouter pour redonder "ᷗ" U1DD7. ibidem
		* Suscrit et tréma : Ajouter pour redonder "ᷲ" U1DF2, "ᷳ" U1DF3, "ᷴ" U1DF4. ibidem
	* Grec-ou-cerclé :
		* Prendre en charge les nombres cerclés. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
		* Redonder "⨸" U2A38. compose-2.yml [6d79c07](https://github.com/dispoclavier/nouvel-azerty/commit/6d79c07750106186bb7172ac933c28388a870eff)
		* Cerclé :
			* Prendre en charge les nombres double-cerclés. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
			* Redonder "⧀" U29C0, "⧁" U29C1, "⨷" U2A37, "⨸" U2A38. compose-2.yml [6d79c07](https://github.com/dispoclavier/nouvel-azerty/commit/6d79c07750106186bb7172ac933c28388a870eff)
		* Double-cerclé : Supprimer. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
	* Brève inversée : Supprimer les nombres cerclés. ibidem
	* Accent aigu : Accent aigu et accent grave et accent aigu : Simplifier en supprimant les caractères de base. compose-2.yml [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
* Documentation :
	* Intégrer l’article indéfini dans les noms des dossiers téléchargeables et dans les noms de fichier de la documentation en PDF. Lisez-moi-svp.txt [69f833c](https://github.com/dispoclavier/nouvel-azerty/commit/69f833cbd7b26f4bfdfae2a9039924286a02a67a), linux-chromeos/readme.md [5eac510](https://github.com/dispoclavier/nouvel-azerty/commit/5eac51051dcb1921dc357bd60826b4503e7de87c), windows/readme.md [0fac9aa](https://github.com/dispoclavier/nouvel-azerty/commit/0fac9aa9d6f5a87651170aacb91e9513e6e7461c), Note-de-version.md [29c9fca](https://github.com/dispoclavier/nouvel-azerty/commit/29c9fca067f536144ee4863de0529117e6efc9a6)
	* Pour la saisie, utiliser des noms de caractères spécifiques dans la mesure du possible. compose-2.yml [7d8c415](https://github.com/dispoclavier/nouvel-azerty/commit/7d8c41567ec0beddeb9a6ca5b543d99eb0da52db)
	* Corriger et compléter des annotations. compose-1.yml [212dee8](https://github.com/dispoclavier/nouvel-azerty/commit/212dee873e557c61e3a8df21be470edbf7ff1ad2), [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8), [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212), [74fec91](https://github.com/dispoclavier/nouvel-azerty/commit/74fec9174c2db2b021320e5cc0cae29e254bd8f7), [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [db5f40d](https://github.com/dispoclavier/nouvel-azerty/commit/db5f40d792b5229916a39730189f6dc788f190a1), [0f0d86a](https://github.com/dispoclavier/nouvel-azerty/commit/0f0d86a66ac1d710cbcca26fce4b477d4b9f067c), [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db), compose-2.yml [41be644](https://github.com/dispoclavier/nouvel-azerty/commit/41be64425c8506414374d48d22677329c0ea5a5f), [01dc79b](https://github.com/dispoclavier/nouvel-azerty/commit/01dc79bdba68aeee891838eb31915e3004d0a58e), [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
	* Ajouter le code des vues. nouvel-azerty.json, nouvel-azerty-verrcap.json, nouvel-azerty-verrmod.json, nouvel-azerty-verrmod-verrcap.json, qzjfgy.json [44b72f3](https://github.com/dispoclavier/nouvel-azerty/commit/44b72f3e2597a9949010f157471012db3af8163e), readme.md [af1bd30](https://github.com/dispoclavier/nouvel-azerty/commit/af1bd3065f1941f77e4f61000278ac5efc94857a)
	* Afficher la vue redisposée. windows/qzjfgy/readme.md [7d67c86](https://github.com/dispoclavier/nouvel-azerty/commit/7d67c869a93e66e474600f09f056c33d5ea9c02c)
	* Améliorer le tri. compose-1.yml [212dee8](https://github.com/dispoclavier/nouvel-azerty/commit/212dee873e557c61e3a8df21be470edbf7ff1ad2), [b9351a4](https://github.com/dispoclavier/nouvel-azerty/commit/b9351a4b4a5cf16439dab59c5cdf69cd9777a0b8), [599d3dd](https://github.com/dispoclavier/nouvel-azerty/commit/599d3dd09b969e0ea6ab84a7fa8b4c71f4cf00ae), [01ffad1](https://github.com/dispoclavier/nouvel-azerty/commit/01ffad1ae691d6c5888e9be3447daefa0a2df2bd), [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8), [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [db5f40d](https://github.com/dispoclavier/nouvel-azerty/commit/db5f40d792b5229916a39730189f6dc788f190a1), [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db)

## 4.16.0 (2024-12-30)

Amélioration de l’ergonomie des variantes redisposées en mode français par la permutation de la touche morte tréma et du guillemet double générique.

* Implémentation : Réimplémenter ce nouvel AZERTY sous Windows :
	* Convertir en AZERTY la variante redisposée. kbfrFRs.klc [df66c78](https://github.com/dispoclavier/nouvel-azerty/commit/df66c7826f6f7d8e83cf325b8d9e1fbf6c498a9a), kbcommon.h [48bb029](https://github.com/dispoclavier/nouvel-azerty/commit/48bb029946c17ba27c741c3921f0a2d9007aa33b), kbfrFRs.C [44ab692](https://github.com/dispoclavier/nouvel-azerty/commit/44ab692a30f868ae0aa16b0bea2a6f768a5599eb), kbfrFRs.H ibidem, kbfrFRs.DEF ibidem, kbfrFRs.RC [c38441a](https://github.com/dispoclavier/nouvel-azerty/commit/c38441a2b8c14fb6da73b8a10ccf6bbc986baaea)
	* Mettre en ligne la variante redisposée. kbfredis.klc [6728979](https://github.com/dispoclavier/nouvel-azerty/commit/67289790dda2b79e8f63bb25e63173276429e9aa), kbfredis.C [d01b210](https://github.com/dispoclavier/nouvel-azerty/commit/d01b2102f2355738d5d9465dca3f6221beaf24fd), kbfredis.H ibidem, kbfredis.DEF ibidem, kbfredis.RC [98a7b66](https://github.com/dispoclavier/nouvel-azerty/commit/98a7b66bf0f481f55ad4d8101367e937d295bc6a)
* Disposition : Variantes redisposées : Mode français : Permuter "\\"" U0022 sur E03 et la touche morte tréma sur E05. dispocla.cpp [ac53b5e](https://github.com/dispoclavier/nouvel-azerty/commit/ac53b5e88670a7dca3436ce69997858d571eff68), kbfredis.klc [f1cb9ac](https://github.com/dispoclavier/nouvel-azerty/commit/f1cb9ac6f5d0aacdcf3726a4efe4a25c1bbdb812), kbfredis.C [ea24800](https://github.com/dispoclavier/nouvel-azerty/commit/ea24800c52ef2c355aa10e228f5db07ff2400efa)
* Composition :
	* Simplifier la séquence « ¦00% » de "‱" U2031 en « ¦00 ». compose-1.yml [e3b30fb](https://github.com/dispoclavier/nouvel-azerty/commit/e3b30fb2e61a6d9719d211df1662374e98410692)
	* Supprimer les séquences de "ẛ" U1E9B basées sur « ¦fs ». compose-1.yml [dc470a2](https://github.com/dispoclavier/nouvel-azerty/commit/dc470a21de993fc77ed063110098f589ef1dd310)
* Transformations :
	* Grec-ou-cerclé et crochet en chef : Déboguer tout. ibidem
	* Point en chef :
		* Déboguer "ė" U0117. compose-2.yml [f6fac7a](https://github.com/dispoclavier/nouvel-azerty/commit/f6fac7a492318eaab3e5a596b6bc2c9873ea9540)
		* Ajouter "ẛ" U1E9B dans les groupes 1 à 3. compose-2.yml [89b51d5](https://github.com/dispoclavier/nouvel-azerty/commit/89b51d5741f5d0cc34e2d1d2e9659e1b9c91b697)
	* Tilde : Redonder "⁑" U2051. ibidem
	* Tréma et rond en chef : Déboguer tout ("᪱" U1AB1). ibidem
	* Tréma : Supprimer "⁑" U2051 pour les déboguer suite au conflit avec "᪱" U1AB1. ibidem
* Documentation :
	* Ajouter le mode d’emploi de ce nouvel AZERTY sous Windows. windows/readme.md [73bfc8b](https://github.com/dispoclavier/nouvel-azerty/commit/73bfc8b91e35ed676fc52e1fa4d5240771e1aab7)
	* Mettre à jour le mode d’emploi de ce nouvel AZERTY sous Linux. linux-chromeos/readme.md [63d9617](https://github.com/dispoclavier/nouvel-azerty/commit/63d9617c97263eae5c312e21737bc3c529d64ff9)
	* Méthode d’entrée des surrogats hauts par touches mortes. compose-2.yml [4135b4d](https://github.com/dispoclavier/nouvel-azerty/commit/4135b4d3c55dab89f75fedc063640e140ec58981)
	* Corriger et compléter des annotations. compose-1.yml [79051e7](https://github.com/dispoclavier/nouvel-azerty/commit/79051e74f5810d87d32455c0ef4cce9da6581f66), [b7ae462](https://github.com/dispoclavier/nouvel-azerty/commit/b7ae462a3913090ace53117d8831dab825eea053), compose-2.yml [75bc2ac](https://github.com/dispoclavier/nouvel-azerty/commit/75bc2ac2f511d0d6c078ca7f733793f85a7dec65), kbfrFRs.klc [895d2d8](https://github.com/dispoclavier/nouvel-azerty/commit/895d2d8078178da7061a4a7842be07fc9b429a2f), [c3b002b](https://github.com/dispoclavier/nouvel-azerty/commit/c3b002bcc858584913fd3edf3aa80e5581c71c82), [17f1f87](https://github.com/dispoclavier/nouvel-azerty/commit/17f1f87229fb48630df0d6322d24335a0df88c20), kbfredis.klc [e2f7e23](https://github.com/dispoclavier/nouvel-azerty/commit/e2f7e230946ceb82a6efcf6e3daeb2498df6d32b), [b918357](https://github.com/dispoclavier/nouvel-azerty/commit/b91835726c88a571b038eed84b13dafb29e2e567)
	* Corriger le journal des modifications. CHANGELOG.md [fb9c6b3](https://github.com/dispoclavier/nouvel-azerty/commit/fb9c6b3364574d39b30fe7473076a6085ad8490b), [1fadc25](https://github.com/dispoclavier/nouvel-azerty/commit/1fadc250efe2e9895b2c68a2f67dfee2dfa13eb3)

## 4.15.0 (2024-12-18)

Facilitation de la saisie des indices et adaptation à l’implémentation boguée sous Windows.

* Disposition : Mode ASCII : Maj + AltGr :
	* Redonder les chiffres et signes en indice à la place des chiffres et signes en exposant, qui sont en Maj + AltFr. dispoocla.cpp [8c195a3](https://github.com/dispoclavier/nouvel-azerty/commit/8c195a30b0ac950798165939cb5b344fdc69c966), dispotypes.c [a70b9a7](https://github.com/dispoclavier/nouvel-azerty/commit/a70b9a7675d5553cdd193e541c6dfe1172a2fab5)
	* Redonder "_" sur D11 à la place de "^", qui y est en AltGr, et en Maj + AltGr en mode français. ibidem
	* Redonder "₌" U208C sur D12 à la place de "$", qui y est en Maj + AltGr en mode français. ibidem
	* Redonder "₍" U208D et "₎" U208E sur C11 et C12 à la place de "%" et "*", qui y sont en Maj. ibidem
* Composition :
	* Redonder "¦" U00A6 par « ¦!^ » pour la compatibilité latérale avec les séquences de composition françaises traditionnelles selon en_US.UTF-8/Compose. compose-1.yml [00f4777](https://github.com/dispoclavier/nouvel-azerty/commit/00f4777674b173d8881556a670e57906d53b2d77)
	* Redonder "⁋" U204B par « ¦!p » et « ¦!P ». ibidem
* Documentation :
	* Mettre à jour le mode d’emploi. linux-chromeos/readme.md [58c7837](https://github.com/dispoclavier/nouvel-azerty/commit/58c78378ba7a6017e52d2065c6480dec17d93b09)
	* Corriger le journal des modifications. CHANGELOG.md [8894a3a](https://github.com/dispoclavier/nouvel-azerty/commit/8894a3abf5d812f2cbe58bcc68aecb7760441828), [d8a7fbd](https://github.com/dispoclavier/nouvel-azerty/commit/d8a7fbd0932cf65cf5ef7b6ba62fdf7f1bcad9d6), [a0eab99](https://github.com/dispoclavier/nouvel-azerty/commit/a0eab99f4efe236cc0cfdcde16ead1c433783215)
	* Corriger des annotations. dispocla.cpp [908e70f](https://github.com/dispoclavier/nouvel-azerty/commit/908e70f9ccca56ea77933c2b68b54876640e8f1a), compose-1.yml [a0aa719](https://github.com/dispoclavier/nouvel-azerty/commit/a0aa719ab8a9e55ddfba931c88680c5f9fdaa874), [00f4777](https://github.com/dispoclavier/nouvel-azerty/commit/00f4777674b173d8881556a670e57906d53b2d77), compose-2.yml [884f054](https://github.com/dispoclavier/nouvel-azerty/commit/884f054dd0c774f9c817bcaea01be47bba9e2847)

## 4.14.0 (2024-12-10)

Meilleure utilité et pertinence accrue grâce au remplacement du gluon par le signe plus invisible.

Amélioration de l’ergonomie du tiret demi-cadratin en notation d’intervalles.

Meilleure prise en charge des deux flèches les plus courantes.

* Disposition :
	* Redonder le signe plus invisible "⁤" U2064 sur AltGr + AltFr + H à la place du gluon "⁠" U2060, qui est dans le groupe 10 du trait d’union ASCII ainsi qu’en séquence avec l’espace sur Maj + AltFr + Espace, et qui n’est pas d’usage courant en écriture latine. dispocla.cpp [43d829c](https://github.com/dispoclavier/nouvel-azerty/commit/43d829c742478248b5e6c71156102dc205d6591d)
	* Redonder "→" U2192 sur AltGr + AltFr + G à la place de "–" U2013, qui prend la place de "⁄" U2044 sur AltGr + AltFr + F, qui est au même niveau sur la touche de l’oblique B09. ibidem
	* Redonder "⇒" U21D2 sur Maj + AltGr + AltFr + G à la place de "👏" U1F44F, qui prend la place de "😐" U1F610 (sur C01), qui n’est pas des plus utilisés et dont l’usage plus technique ne justifie pas une place sur touche vive. ibidem
* Documentation :
	* Mettre à jour le mode d’emploi. linux-chromeos/readme.md [6b9454c](https://github.com/dispoclavier/nouvel-azerty/commit/6b9454cce93f83309974f2bb4ae90838fd213608)
	* Corriger des annotations. dispocla.cpp [8b2e6be](https://github.com/dispoclavier/nouvel-azerty/commit/8b2e6bedf634a7a0441098a641bc08bc3ac88fec)

## 4.13.0 (2024-12-08)

Amélioration de la compatibilité ascendante par la prise en charge sur touche vive du symbole monétaire générique de l’AZERTY traditionnel, utilisé en autocorrection.

* Disposition : Redonder "¤" U00A4 sur Maj + AltGr + C11 à la place de "%" U0025, qui y est en Maj + AltFr et qui est sur AltGr + Z. dispocla.cpp [eebfe08](https://github.com/dispoclavier/nouvel-azerty/commit/eebfe08878e60eefab6ff74003d23fdc90e39365), [2ffbd4d](https://github.com/dispoclavier/nouvel-azerty/commit/2ffbd4d03612af6272ad12d8564089aa5c3f103a)
* Documentation : Corriger des annotations. dispocla.cpp [a51e124](https://github.com/dispoclavier/nouvel-azerty/commit/a51e124b904ec62b29645893767d377f8982e2f3), compose-1.yml [accd312](https://github.com/dispoclavier/nouvel-azerty/commit/accd31212b2f7d148ef4ae942433c9cef613c1ee)

## 4.12.0 (2024-12-01)

Amélioration de l’ergonomie par la correction d’erreurs au niveau 7 provenant de la version 3.1.0, selon le principe que la mnémonique ne doit pas primer sur l’ergonomie.

Facilitation de la personnalisation de la disposition utilisée.

* Disposition : Niveau 7 : Mettre le tiret demi-cadratin "–" U2013 sur C05 à la place du gluon "⁠" U2060, qui prend la place du symbole plus ou moins "±" U00B1 sur C06, qui prend la place laissée par le tiret demi-cadratin sur D05. dispocla.cpp [a539f12](https://github.com/dispoclavier/nouvel-azerty/commit/a539f12454a6b63fbf33ba2e0479108cfffc8a3a), [ad71ea7](https://github.com/dispoclavier/nouvel-azerty/commit/ad71ea7ada905630c00a3649c71f76a649038373)
* Personnalisation : Fournir et inclure un tableau d’allocation générique. dispocla_perso.cpp [3c04e45](https://github.com/dispoclavier/nouvel-azerty/commit/3c04e454170ca1d3c59cef1698dbea099235d911), [78a2156](https://github.com/dispoclavier/nouvel-azerty/commit/78a215628e89af3255f72c45785656cc850e3812), [9bfabf1](https://github.com/dispoclavier/nouvel-azerty/commit/9bfabf1728d098ecf4a6406b1abfa9eed19bc418), [8f93229](https://github.com/dispoclavier/nouvel-azerty/commit/8f93229df0fad05c3def54697bfdc107250e4986), dispocla.cpp [f16807e](https://github.com/dispoclavier/nouvel-azerty/commit/f16807e08d88aa5fc52a835570362858a331d9da), [dc31ecd](https://github.com/dispoclavier/nouvel-azerty/commit/dc31ecdaa2075aa7107e3559e58c95799283819d), [945929e](https://github.com/dispoclavier/nouvel-azerty/commit/945929ef657b4dc9a9086f8c3199a0be38b9a28e), installer.sh [a0e7691](https://github.com/dispoclavier/nouvel-azerty/commit/a0e7691541d0dd2cda550aa0b7693f0aa8fabcb3), [23b9ecf](https://github.com/dispoclavier/nouvel-azerty/commit/23b9ecf714eee621fc2d31e19bbc07a63dc7c622), [9004a4d](https://github.com/dispoclavier/nouvel-azerty/commit/9004a4dd8143426009cffd72c8f30a635713320f), [e3f6923](https://github.com/dispoclavier/nouvel-azerty/commit/e3f69236295277aaee8cbb2412e038981a22d3fa), linux-chromeos/readme.md [c33de30](https://github.com/dispoclavier/nouvel-azerty/commit/c33de307ba7da3d755843fc7119a9805c8e8b992), [12f535b](https://github.com/dispoclavier/nouvel-azerty/commit/12f535bddb3a243ba5149d5c128f8c8aff8b1850)
* Documentation : Corriger des annotations. compose-1.yml [f7d09dd](https://github.com/dispoclavier/nouvel-azerty/commit/f7d09dd29fbe51aa33a68e7f813a7b9ac8923c4a), compose-3.yml [a6bba5d](https://github.com/dispoclavier/nouvel-azerty/commit/a6bba5d9b57ab3178f6cba9bfc937eb5745d9da8)

## 4.11.0 (2024-11-09)

Amélioration de l’utilité des groupes des symboles grâce à l’assurance de la prise en charge des touches vives sous Windows sans déclencher le malware de Microsoft.

* Composition : Ajouter "↴" U21B4, "↸" U21B8. compose-1.yml [1ed0bed](https://github.com/dispoclavier/nouvel-azerty/commit/1ed0bedb0e12e5fa45322881f140b3684859f2da)
* Transformations : Groupes des symboles :
	* Permuter "∓" U2213 et "➕" U2795, "×" U00D7 et "✖" U2716, "÷" U00F7 et "➗" U2797. ibidem, compose-3.yml [717e162](https://github.com/dispoclavier/nouvel-azerty/commit/717e162ba294440f4000370d4f266e7f4bac2c2c)
	* Mettre "➖" U2796 dans le groupe 2 à la place de "⁃" U2043, qui prend la place de "−" U2212, qui prend la place laissée par "➖" U2796, ibidem
	* Redonder "≠" U2260 à la place de "≡" U2261, qui prend la place du trait d’union insécable "‑" U2011, qui est sur touche vive. ibidem
* Documentation : Corriger et compléter des annotations. dispocla.cpp [af33434](https://github.com/dispoclavier/nouvel-azerty/commit/af33434952283d7d62a5f83c5dbe9f78fb2d8df9), [20e4bf1](https://github.com/dispoclavier/nouvel-azerty/commit/20e4bf14c0ee49635dd2d7748a140455274fae6b), compose-2.yml [ca98c7d](https://github.com/dispoclavier/nouvel-azerty/commit/ca98c7d96dcde5ad08a3dbb8ffcbcf8b7337b69b)

## 4.10.0 (2024-10-28)

Amélioration de l’ergonomie des variantes redisposées.

* Disposition : Variantes redisposées :
	* Égaliser la touche morte accent grave avec les variantes non redisposées en la mettant en AltGr, sur C12 à la place du tiret bas, qui prend la place du guillemet simple générique sur E12, qui prend la place laissée par la touche morte accent grave sur E07. dispocla.cpp [474fcec](https://github.com/dispoclavier/nouvel-azerty/commit/474fcec8ec797be2c2a9f36011fe34fdf41dc7ef)
	* Variantes régionales : Laisser le guillemet simple générique sur E12 à la place du tiret bas, qui est sur AltGr + C07. ibidem
* Transformations : Groupe 1 : Supprimer les alternatives obsolètes pour "‑" U2011, "―" U2015. compose-2.yml [e5d8048](https://github.com/dispoclavier/nouvel-azerty/commit/e5d8048a79de7a1c154e1d33805621d7c181c55f)
* Documentation : Tableaux des touches mortes : Mettre à jour la place de la touche morte tréma, sur E05. generate-deadkey-tables.pl [b5caeaf](https://github.com/dispoclavier/nouvel-azerty/commit/b5caeafc4e620a971e993d9362f80e9eca9ce0de), generate-multikey-tables.pl [fc232fd](https://github.com/dispoclavier/nouvel-azerty/commit/fc232fd5715d6bd7286f370a9ea415fe543da85e)

## 4.9.0 (2024-10-27)

Correction des touches E11 et E12, et C11, C12, D11, D12.

* Disposition :
	* Redonder "⁻" U207B sur Maj + AltFr + E11 à la place de "E", qui va sur AltGr + AltFr à la place de "*️⃣", qui est sur Maj + AltGr + AltFr. dispocla.cpp [699fead](https://github.com/dispoclavier/nouvel-azerty/commit/699feadefd59f1b557d0dd76773190d8a5d7fa49), dispotypes.c [e3e99d8](https://github.com/dispoclavier/nouvel-azerty/commit/e3e99d82624cbdd16993fa0de99bf5573fa3c99c)
	* Redonder "⁺" U207A sur Maj + AltFr + E12 à la place de "F", qui va sur AltGr + AltFr à la place de "#️⃣", qui est sur Maj + AltGr + AltFr. ibidem
	* Permuter "C" et l’alias rétrocompatible de la touche morte tréma sur D11. ibidem
	* Permuter "D" et "£" U00A3 sur D12. ibidem
	* Permuter "A" et "%" sur C11. ibidem
	* Permuter "B" et "µ" U00B5 sur C12. ibidem

## 4.8.0 (2024-10-25)

Amélioration de l’ergonomie de la touche morte tréma.

Simplification de séquences de composition.

* Disposition :
	* Permuter la touche morte tréma, qui va sur E05, et le guillemet simple générique, qui prend la place laissée par la touche morte tréma sur E12. dispocla.cpp [7a46213](https://github.com/dispoclavier/nouvel-azerty/commit/7a4621354858142eeadf7294ed6783a73e8ae1f5)
	* Variantes redisposées :
		* Mettre la touche morte tréma sur E05 à la place du guillemet simple générique "'" U0027, qui va sur E12 à la place du trait d’union insécable "‑" U2011, qui est sur Maj + E06. dispocla.cpp [a6470bc](https://github.com/dispoclavier/nouvel-azerty/commit/a6470bc6fca79af95412a386fcfea05a463d8b21), [7a46213](https://github.com/dispoclavier/nouvel-azerty/commit/7a4621354858142eeadf7294ed6783a73e8ae1f5)
		* Redonder "_" U005F sur la place laissée par la touche morte tréma en AltGr de C12, la touche du tiret. ibidem
* Composition :
	* Lettres-symboles cursives mathématiques comme "ℛ" U211B : Simplifier les séquences de « ¦R//␣ » en « ¦R~␣ ». compose-1.yml [2189b98](https://github.com/dispoclavier/nouvel-azerty/commit/2189b98287add7c019e27f0f95fdd4f1939ab5b1)
	* Lettres-symboles italiques ajourées mathématiques comme "ⅅ" U2145 : Simplifier les séquences de « ¦DD//␣ » en « ¦DD/␣ ». ibidem
	* Symbole Répons "℟" U211F : Simplifier la séquence « ¦R/␣ » en « ¦R/ ». ibidem
* Documentation : Corriger des annotations. ibidem, [02e284f](https://github.com/dispoclavier/nouvel-azerty/commit/02e284f8ab38b0f37c6d6b1452059c61024d3402)

## 4.7.0 (2024-10-20)

Meilleure compatibilité multiplateforme grâce à la suppression des trois premiers groupes du croisillon.

Prise en charge des lettres grecques polytoniques, par respect pour les utilisateurs et pour le grec.

Facilitation de la saisie du symbole micro "µ" U00B5, désormais aussi sur AltFr + Y.

Amélioration de la versatilité de la disposition de base et des variantes redisposées.

Robustesse des scripts d’installation et d’activation.

* Disposition :
	* Redonder le symbole micro "µ" U00B5 sur AltFr + Y à la place de "¥" U00A5, qui va en AltGr + AltFr + Y à la place de la lettre "Ω" U03A9, qui va sur O à la place du symbole "Ω" U2126, qui est dans les groupes 4 et 12 du O, et en composition par « ¦ohm ». dispocla.cpp [ae82bc3](https://github.com/dispoclavier/nouvel-azerty/commit/ae82bc362da6a778441668fe58eddc1df9b158ee)
	* Variantes redisposées : Redonder le trait d’union insécable "‑" U2011 sur Maj + E06 à la place de "Ù", qui est en Verrouillage Capitales. dispotypes.c [cb06597](https://github.com/dispoclavier/nouvel-azerty/commit/cb0659700d0591c4877274dc4c4563bf4fcbb097), dispocla.cpp [0d88beb](https://github.com/dispoclavier/nouvel-azerty/commit/0d88beb8f3d64d7b15a65625964ef86c16c799b3)
* Composition : Redonder "⮽" U2BBD par « ¦[XL] ». compose-1.yml [8f3df49](https://github.com/dispoclavier/nouvel-azerty/commit/8f3df4982258ad5df65b97761d762c15fd04e02f), [021b40d](https://github.com/dispoclavier/nouvel-azerty/commit/021b40df65b6f797e779a5fe5448f21b228f8f99)
* Transformations :
	* Groupe 1 :
		* Redonder le symbole micro "µ" U00B5 par le guillemet "»" U00BB pour la rétrocompatibilité. compose-2.yml [70bee3f](https://github.com/dispoclavier/nouvel-azerty/commit/70bee3f365ab0135a870b4ee3e1e19ad5aea489e), [fb6c67d](https://github.com/dispoclavier/nouvel-azerty/commit/fb6c67dba124bbd95be8e7372cee252e534ae142), [aefcc83](https://github.com/dispoclavier/nouvel-azerty/commit/aefcc83781f3e8d9c334780f7c59a1abfdbea6f3)
		* Redonder le "%" par le guillemet "«" U00AB pour la symétrie. ibidem
		* Redonder le symbole livre "£" U00A3 par le guillemet "›" U203A pour la rétrocompatibilité à la place de "❯" U276F, qui est dans le groupe 3 de "]". compose-2.yml [22c3e17](https://github.com/dispoclavier/nouvel-azerty/commit/22c3e17e75e747a0ec807dfdc4b52bb38331fee2)
		* Redonder le "¨" U00A8 par le guillemet "‹" U2039 pour la symétrie à la place de "❮" U276E, qui est par "[". ibidem
		* Redonder les "$" U0024, "¤" U00A4, "^" U005E et "=" U003D dans le groupe 1 des touches mortes accent aigu, accent grave, accent circonflexe et tréma qui y sont disposées en mode français sur la disposition de base, pour la rétrocompatibilité et la cohérence. compose-2.yml [bdab051](https://github.com/dispoclavier/nouvel-azerty/commit/bdab05193d4f1996e1c6881c4964d5b0b860d239)
		* Redonder le "&" dans le groupe 1 de l’exposant deux pour la rétrocompatibilité. ibidem
	* Groupes des symboles :
		* Groupes de "#" :
			* Réserver la place de "☐" U2610, qui va dans le groupe 1 de "|" à la place de "∣" U2223, qui va dans le groupe 11 à la place de "µ" U00B5, qui est sur touche vive et va dans le groupe 1 de "»" U00BB. compose-3.yml [ad2162a](https://github.com/dispoclavier/nouvel-azerty/commit/ad2162a03398cb8e2a4e97b92cd34ed564f6b1be), [f44a7d4](https://github.com/dispoclavier/nouvel-azerty/commit/f44a7d47e151ff8d7da93ac19c2aedd53dfc45d5), [8aed8ef](https://github.com/dispoclavier/nouvel-azerty/commit/8aed8efaac1b0470c6635b058b83986776ae90d2)
			* Réserver la place de "☑" U2611, qui va dans le groupe 2 de "|" à la place de "‖" U2016, qui va dans le groupe 12 de ":" à la place de "※" U203B, qui va dans le groupe 12 de "*" à la place de "❖" U2756, qui va dans le groupe 12 de "@" à la place de "❍" U274D, qui va dans le groupe 10 à la place de l’antiliant "‌" U200C, qui est dans le groupe 10 de "^". ibidem
			* Réserver la place de "☒" U2612, qui va dans le groupe 3 de "|" à la place de "∥" U2225, qui va dans le groupe 12 à la place de "¦" U00A6, qui va dans le groupe 11 de ":" à la place de "⁝" U205D, qui retourne dans point souscrit par "3" à la place de "⃨" U20E8, qui change de saisie par "_", et qui devient redondé dans indice par "…" U2026. ibidem
		* Groupes de "}" : Redonder "Ω" U03A9 à la place de "Ω" U2126, qui est dans les groupes 4 et 12 du O, et en composition par « ¦ohm ». compose-3.yml [333b30d](https://github.com/dispoclavier/nouvel-azerty/commit/333b30d6869eeda14a3fe2e8aed73f987a83e97d)
	* Grec-ou-cerclé :
		* Ajouter les lettres et diacritiques grecs polytoniques en combinaison avec accent aigu, accent grave, accent circonflexe, tréma, hatchek, macron, crochet en chef, brève inversée, brève, point souscrit. compose-1.yml [899995b](https://github.com/dispoclavier/nouvel-azerty/commit/899995b1418616c872158a02179d468a1178fc90)
		* Redonder "ι" U1FBE par espace insécable à la place de "ι" U03B9, qui est par "i". compose-2.yml [70bee3f](https://github.com/dispoclavier/nouvel-azerty/commit/70bee3f365ab0135a870b4ee3e1e19ad5aea489e)
		* Supprimer "⊗" U2297 (sauf par "×" U00D7), "⊙" U2299, "⊚" U229A (sauf par "°" U00B0), qui sont dans cerclé. ibidem
	* Point souscrit : Rajouter "⁝" U205D par "3" à la place de "⃨" U20E8, qui change de saisie par "_". compose-2.yml [de89aba](https://github.com/dispoclavier/nouvel-azerty/commit/de89aba8279e2747b82aff3ed7a3c21d9f1a6899)
	* Indice : Redonder "⃨" U20E8 par "…" U2026. ibidem
	* Barré : Redonder "∤" U2224 dans le groupe 11, "∦" U2226 dans le groupe 12. ibidem, compose-2.yml [de89aba](https://github.com/dispoclavier/nouvel-azerty/commit/de89aba8279e2747b82aff3ed7a3c21d9f1a6899), [ad9acb8](https://github.com/dispoclavier/nouvel-azerty/commit/ad9acb8603da8092d2222bedde9d935811f6300f)
	* Tréma : Remplacer les caractères de base du tiret double cadratin "⸺" U2E3A, par "°" U00B0 au lieu de "–" U2013, et du tiret triple cadratin "⸻" U2E3B, par "+" U002B au lieu de "—" U2014. compose-2.yml [70bee3f](https://github.com/dispoclavier/nouvel-azerty/commit/70bee3f365ab0135a870b4ee3e1e19ad5aea489e)
* Activation : Assurer la compatibilité multiplateforme du script en remplaçant la valeur ":0" d’une variable d’environnement par son nom "$DISPLAY". activer.sh [015f9e5](https://github.com/dispoclavier/nouvel-azerty/commit/fe015f9e592db39d03407a36ca72daba23952205)
* Installation :
	* Adapter le script au lancement par clic. installer.sh [ee26432](https://github.com/dispoclavier/nouvel-azerty/commit/ee264323102a6cd217198f1e08117ecf3d7b954e)
	* Corriger des messages. ibidem, [0f150fe](https://github.com/dispoclavier/nouvel-azerty/commit/0f150fef4301cb453553ec687efbdcd266cf8a81), [dc6056e](https://github.com/dispoclavier/nouvel-azerty/commit/dc6056ed43e16972bbc2d95a63c672766d1d6032)
* Documentation :
	* Corriger les informations sur l’installation. compose-1.yml [8f3df49](https://github.com/dispoclavier/nouvel-azerty/commit/8f3df4982258ad5df65b97761d762c15fd04e02f), [4f90f74](https://github.com/dispoclavier/nouvel-azerty/commit/4f90f742919440d99f04d2a7129ac8c3e129b4ce)
	* Corriger des annotations. dispocla.cpp [ff6db0d](https://github.com/dispoclavier/nouvel-azerty/commit/ff6db0d8783a360245ffb2e0d51f97ef7d28d242), dispotypes.c [dd6abe0](https://github.com/dispoclavier/nouvel-azerty/commit/dd6abe0e5424b29d2555786d2412c191379295b7), compose-1.yml [899995b](https://github.com/dispoclavier/nouvel-azerty/commit/899995b1418616c872158a02179d468a1178fc90), [8f3df49](https://github.com/dispoclavier/nouvel-azerty/commit/8f3df4982258ad5df65b97761d762c15fd04e02f), [021b40d](https://github.com/dispoclavier/nouvel-azerty/commit/021b40df65b6f797e779a5fe5448f21b228f8f99), [fe56e4f](https://github.com/dispoclavier/nouvel-azerty/commit/fe56e4fa16005c18287e9dacc1e5f0c32c90fad3), compose-2.yml [70bee3f](https://github.com/dispoclavier/nouvel-azerty/commit/70bee3f365ab0135a870b4ee3e1e19ad5aea489e), [de89aba](https://github.com/dispoclavier/nouvel-azerty/commit/de89aba8279e2747b82aff3ed7a3c21d9f1a6899), [4227850](https://github.com/dispoclavier/nouvel-azerty/commit/42278508030f2a1594446c1db86b213b4a208ff0), [2cf837f](https://github.com/dispoclavier/nouvel-azerty/commit/2cf837f890aa0907c9d8fd4269b16145dc287eb8), compose-3.yml [1ecb108](https://github.com/dispoclavier/nouvel-azerty/commit/1ecb1083d6b62b217b40779c48949172039d1943), [333b30d](https://github.com/dispoclavier/nouvel-azerty/commit/333b30d6869eeda14a3fe2e8aed73f987a83e97d)
	* Rectifier les métadonnées. compose-1.yml [fe56e4f](https://github.com/dispoclavier/nouvel-azerty/commit/fe56e4fa16005c18287e9dacc1e5f0c32c90fad3), compose-2.yml [4227850](https://github.com/dispoclavier/nouvel-azerty/commit/42278508030f2a1594446c1db86b213b4a208ff0), [00d9e99](https://github.com/dispoclavier/nouvel-azerty/commit/00d9e9975d3a77e1df29167f92da9b0bdd42c5e1), compose-3.yml [7f68a73](https://github.com/dispoclavier/nouvel-azerty/commit/7f68a730d80435b5433cf5ba6d855525770c8b18), [d9fd293](https://github.com/dispoclavier/nouvel-azerty/commit/d9fd2933ed85620ff6cd4f149ae523712e64faf7)
	* Unifier la syntaxe. compose-1.yml [fe56e4f](https://github.com/dispoclavier/nouvel-azerty/commit/fe56e4fa16005c18287e9dacc1e5f0c32c90fad3), compose-2.yml [4227850](https://github.com/dispoclavier/nouvel-azerty/commit/42278508030f2a1594446c1db86b213b4a208ff0), compose-3.yml [0ad96be](https://github.com/dispoclavier/nouvel-azerty/commit/0ad96bed9937cc8060a4f1cf6b063f98a4423ac2)
	* Corriger l’orthographe. generate-math-table.pl [52ad340](https://github.com/dispoclavier/nouvel-azerty/commit/52ad3408759a49092399ae8ae00d71d8bf68e888), generate-multikey-tables.pl [33ac941](https://github.com/dispoclavier/nouvel-azerty/commit/33ac941b2b09fb6c54a5f0cb69e46349bc9bb469)
	* Supprimer des liens publicitaires. generate-deadkey-tables.pl [57cda0b](https://github.com/dispoclavier/nouvel-azerty/commit/57cda0bbc24171fb40bf6ccfa6c2905d9de3bc35)

## 4.6.0 (2024-10-06)

Correction des variantes redisposées pour une meilleure ergonomie.

* Disposition : Variantes redisposées : Mettre la touche morte tréma sur AltGr + C12 à la place de la touche morte accent grave, qui prend la place du trait d’union insécable "‑" U2011 sur E07, qui prend la place laissée par la touche morte tréma sur E12. dispocla.cpp [53b3f20](https://github.com/dispoclavier/nouvel-azerty/commit/53b3f2055091f79e1f56e4f6d4293c77875f8887)
* Documentation :
	* Ajouter une note sur les normes. dispocla.cpp [625988d](https://github.com/dispoclavier/nouvel-azerty/commit/625988d99e36aaf2f9f46db131ab678358c43b57)
	* Corriger des annotations. dispocla.cpp [55fbd27](https://github.com/dispoclavier/nouvel-azerty/commit/55fbd276f1d19df764ffe8225202a20927c43d23)

## 4.5.0 (2024-10-05)

Correction du mode ASCII suite à la version 2.

* Disposition : Mode ASCII : Accolades à la place des crochets en Majuscule de D11, D12. dispocla.cpp [8b89a50](https://github.com/dispoclavier/nouvel-azerty/commit/8b89a502ba4e0716a16347f270432cd3b0b49c05)
* Documentation : Corriger des annotations. dispocla.cpp [4c1aebc](https://github.com/dispoclavier/nouvel-azerty/commit/4c1aebcf624a4174e0d4e0cf01c79874e5f2c48c), compose-1.yml [5f18c63](https://github.com/dispoclavier/nouvel-azerty/commit/5f18c6384404cb722bd0c5be26adf493551ab3e1)

## 4.4.6 (2024-10-02)

* Composition : Supprimer "ʼN" U02BC U004E. compose-1.yml [24b2f6b](https://github.com/dispoclavier/nouvel-azerty/commit/24b2f6bf215e1132ccfe135a5c14da97fcde61b3)
* Documentation : Corriger des annotations. dispocla.cpp [b9ca449](https://github.com/dispoclavier/nouvel-azerty/commit/b9ca449e93678f4ab94e23f323f2fa098d8c2bb7), compose-1.yml [24b2f6b](https://github.com/dispoclavier/nouvel-azerty/commit/24b2f6bf215e1132ccfe135a5c14da97fcde61b3), [ceffb2a](https://github.com/dispoclavier/nouvel-azerty/commit/ceffb2a5ea86d1ba50437ec913ee0c520bd3ec30), compose-2.yml [d72e791](https://github.com/dispoclavier/nouvel-azerty/commit/d72e791471c412d75dbab07ae709d69ef4b352d8), [2f12a33](https://github.com/dispoclavier/nouvel-azerty/commit/2f12a3398796c734d9ec5ee27d823b1d6ec778a1), compose-3.yml [07c7bee](https://github.com/dispoclavier/nouvel-azerty/commit/07c7bee6887a227028131bebfb7e318bc5c33c96)

## 4.4.5 (2024-09-30)

* Documentation : Corriger des annotations. compose-1.yml [e1ff957](https://github.com/dispoclavier/nouvel-azerty/commit/e1ff957eaf396e7d19ce20c4d332e4cc3afe5494)

## 4.4.4 (2024-09-30)

* Documentation : Corriger des annotations. compose-1.yml [1690492](https://github.com/dispoclavier/nouvel-azerty/commit/1690492790286bb4c6043e7202783d975cc20429)

## 4.4.3 (2024-09-29)

* Documentation : Corriger des annotations. compose-1.yml [154f6a5](https://github.com/dispoclavier/nouvel-azerty/commit/154f6a51ac081b8e88fe9413c3337c9c8d7ce6b3)
	
## 4.4.2 (2024-09-29)

* Documentation : Corriger des annotations. compose-1.yml [20c53d0](https://github.com/dispoclavier/nouvel-azerty/commit/20c53d0d5f5e8f240d77550c6e7eb27f9ab8cde9), compose-2.yml [8cc6866](https://github.com/dispoclavier/nouvel-azerty/commit/8cc6866e2f52ade8224ca12b636cc08956ce6e84)

## 4.4.1 (2024-09-27)

* Documentation : Corriger des annotations. compose-1.yml [52fb86d](https://github.com/dispoclavier/nouvel-azerty/commit/52fb86d165d3db5f392da3a259aaa69dfdd26645)

## 4.4.0 (2024-09-26)

Redisposition des trois premiers groupes du tiret bas.

* Composition : Classer les puces. compose-1.yml [f57e338](https://github.com/dispoclavier/nouvel-azerty/commit/f57e3380a1d6ddd40c86891a0a7cc0bd630bcf75)
* Transformations :
	* Groupes des symboles : Redonder "‣" U2023 à la place de "◦" U25E6, qui prend la place de "•" U2022, qui prend la place de "―" U2015, qui est sur touche vive ou dans le groupe 1 de "ɔ" U0254, "Ɔ" U0186, "ñ" U00F1, "Ñ" U00D1, "ʻ" U02BB, "‑" U2011, dans raie haute et en composition par « ¦8- ». compose-3.yml [d93a4d9](https://github.com/dispoclavier/nouvel-azerty/commit/d93a4d994914a50073429b5e6aade265eec61281)
	* Accent aigu : Supprimer "ʻ" U02BB (par ","), qui est dans le groupe 1 de "`" et va dans accent circonflexe (par ","). compose-2.yml [6994434](https://github.com/dispoclavier/nouvel-azerty/commit/6994434b505b5808e887099048acbd26c1da451d)
	* Accent circonflexe : Redonder "ʻ" U02BB (par ",") à la place de "ʼ" U02BC, qui est dans le groupe 1 de "'" et "’". ibidem
	* Accent grave : Supprimer "ʻ" U02BB (par ","), qui est dans le groupe 1 de "`" et va dans accent circonflexe (par ","). ibidem
	* Cédille et accent aigu : Rétablir la symétrie des séquences. ibidem
* Documentation :
	* Améliorer la lisibilité des intertitres des groupes des symboles. compose-3.yml [d93a4d9](https://github.com/dispoclavier/nouvel-azerty/commit/d93a4d994914a50073429b5e6aade265eec61281), compose-1.yml [f57e338](https://github.com/dispoclavier/nouvel-azerty/commit/f57e3380a1d6ddd40c86891a0a7cc0bd630bcf75), compose-2.yml [6994434](https://github.com/dispoclavier/nouvel-azerty/commit/6994434b505b5808e887099048acbd26c1da451d)
	* Corriger des annotations. ibidem

## 4.3.1 (2024-09-22)

Débogage par résolution de 34 conflits suite à l’amélioration de la méthode de test.

* Composition :
	* Adapter les séquences de "🅭" U1F16D par « ¦OCC », "©" U00A9 par « ¦oc », « ¦()c », pour déboguer "©" U00A9. compose-1.yml [cf47ccf](https://github.com/dispoclavier/nouvel-azerty/commit/cf47ccf1703b54cd0c7b116363632eef6964a769)
	* Déboguer "№" U2116 par « ¦no_ », « ¦NO_ », « ¦No_ », « ¦nO_ ». ibidem
	* Déboguer "▾" U25BE par « ¦nbt ». ibidem
	* Déboguer "▿" U25BF par « ¦nbs ». ibidem
	* Déboguer "‰" U2030 par « ¦0% ». ibidem
	* Déboguer "₱" U20B1 par « ¦p= », « ¦P- ». ibidem
	* Déboguer "₴" U20B4 par « ¦S= », « ¦S- ». ibidem
	* Déboguer "¤" U00A4 par « ¦Xo », « ¦xO ». ibidem
	* Déboguer "⇪" U21EA par « ¦caps ». ibidem
	* Déboguer "⇪" U2BB8 par « ¦CAPS ». ibidem
	* Déboguer "‬" U202C par « ¦d< », « ¦p< », « ¦p> ». ibidem
	* Déboguer "€" U20AC par « ¦C= », « ¦E= ». ibidem
	* Déboguer "℈" U2108 par « ¦E% », « ¦scr ». ibidem
	* Déboguer "♫" U266B par « ¦h- », « ¦E# ». ibidem
	* Améliorer les séquences de "⇭" U21ED par « ¦nml », « ¦NML » pour l’intuitivité. ibidem
	* Ajuster les séquences de "⎄" U2384 par « ¦cmp », « ¦CMP » pour déboguer "℅" U2105. ibidem
	* Ajuster les séquences de "⟲" U27F2 par « ¦␣G\␣ » pour déboguer "ℷ" U2137. ibidem
	* Ajuster les séquences de "♮" U266E par « ¦n# », « ¦0# » pour déboguer "♪" U266A. ibidem
	* Ajuster les séquences de "⫛" U2ADB par « ¦nI␣ » pour déboguer "⫙" U2AD9. ibidem
	* Ajuster les séquences de "⧵" U29F5 par « ¦o\ », « ¦␣␣␣␣\ » pour déboguer "⦰" U29B0. ibidem
	* Ajuster les séquences de "♣" U2663 par « ¦8o# » pour déboguer "⑧" U2467. ibidem
* Transformations :
	* Rond en chef : Redonder "°" U00B0 par "0" à la place de "∗" U2217, qui est par "5" et par "8" et en composition. compose-2.yml [f1d465e](https://github.com/dispoclavier/nouvel-azerty/commit/f1d465e92b885ae0659bfaa5d3d418f18b7f2b13)
	* Tilde et perluète : Redonder "⃤" U20E4 par espace, "ǃ" U01C3 par espace insécable. compose-2.yml [200f140](https://github.com/dispoclavier/nouvel-azerty/commit/200f140f51a74d099094538508884a94f12e4dbf)
* Documentation :
	* Annoter les symboles verset et répons "℣" U2123, "℟" U211F. compose-3.yml [922c0cd](https://github.com/dispoclavier/nouvel-azerty/commit/922c0cd65df9b747ad51aaf3125deb9fe6ff5486)
	* Annoter le lambda latin "Ꟛ" UA7DA, "ꟛ" UA7DB nouveau dans Unicode 16.0. compose-3.yml [0a09f16](https://github.com/dispoclavier/nouvel-azerty/commit/0a09f168552723f476ad8fc6acfdad6c715037da)
	* Annoter l’histoire tourmentée de l’espace fine insécable " " U202F. compose-1.yml [1760222](https://github.com/dispoclavier/nouvel-azerty/commit/1760222baa5718774890688739d38ffbaf62821d), [065cc9a](https://github.com/dispoclavier/nouvel-azerty/commit/065cc9ad20fd16e144d7c9c498e4e29a7f4d15d5)
	* Mettre à jour le dump de la feuille de calcul des groupes des lettres. compose-3.yml [2be2cb3](https://github.com/dispoclavier/nouvel-azerty/commit/2be2cb3a680f9fd36634d5a5be63764843b3c961)
	* Vérifier et déboguer les tableaux de touches mortes. generate-deadkey-tables.pl [4ae76f8](https://github.com/dispoclavier/nouvel-azerty/commit/4ae76f8964d06ff27d4d7e71eaea3d3455421088), [f2cccfa](https://github.com/dispoclavier/nouvel-azerty/commit/f2cccfa397e8868b3b1772aa1249a13e8ad7785d), generate-math-table.pl [14d4fee](https://github.com/dispoclavier/nouvel-azerty/commit/14d4feeeca766cb1a5ec3d4248c68cfba1833b28), [6928407](https://github.com/dispoclavier/nouvel-azerty/commit/6928407c1d24fc3723c1aa67e11c214a47b3b6b3), [4990388](https://github.com/dispoclavier/nouvel-azerty/commit/49903883bfb3ebf0676a56ea4c36e51fde4225cd), generate-multikey-tables.pl [fb2a13b](https://github.com/dispoclavier/nouvel-azerty/commit/fb2a13b6d0911ac898fc88bf3d67a84da1479c7a), [8daf19a](https://github.com/dispoclavier/nouvel-azerty/commit/8daf19ae6a320071325fb8f73538a368879b07a1)

## 4.3.0 (2024-09-15)

Mise à jour vers Unicode 16.0, bouclage de la prise en charge de l’écriture latine.

Permutation du liant et de l’antiliant, plus fréquent et désormais plus facile à saisir sur AltGr + AltFr + W.

* Disposition :
	* Permuter l’antiliant "‌" U200C et le liant "‍" U200D afin que l’antiliant soit sur AltGr + AltFr + W, et le liant sur AltGr + AltFr + Q. dispocla.cpp [b10b147](https://github.com/dispoclavier/nouvel-azerty/commit/b10b147daa058e2737e68176acae3debae34c259), linux-chromeos/readme.md [58dcaf0](https://github.com/dispoclavier/nouvel-azerty/commit/58dcaf0423496cd23fc763083d2ccd82c1c3bf37)
	* Annoter les apostrophes. dispocla.cpp [fc81a5e](https://github.com/dispoclavier/nouvel-azerty/commit/fc81a5e1e38d6226f136b979783dd4a5f020ba76)
* Composition :
	* Ajouter "˹" U02F9 par « ¦h( », "˺" U02FA par « ¦h) », "˻" U02FB par « ¦b( », "˼" U02FC par « ¦b) », "꜠" UA720 par « ¦h'( », "꜡" UA721 par « ¦b'( » et alternatives. compose-1.yml [087907a](https://github.com/dispoclavier/nouvel-azerty/commit/087907a93adceaefdab7e3a5083190fed269a4cc), [cb0c2fe](https://github.com/dispoclavier/nouvel-azerty/commit/cb0c2fe6d6c9e4fb8a3ada2db3d71666e05e60b2), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Redonder "—" U2014 par « ¦---- ». compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
	* Redonder "ᴖ" U1D16 par « ¦osup », "ᴗ" U1D17 par « ¦oinf ». compose-1.yml [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Compléter les séquences de "ª" U00AA par « ¦A_ », "º" U00BA par « ¦O_ ». compose-1.yml [5f16588](https://github.com/dispoclavier/nouvel-azerty/commit/5f16588846b8755832fc67dec60a1f578c0bf792)
	* Adapter les séquences de "⩵" U2A75, "⩟" U2A5F, "⩠" U2A60. compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Supprimer "‘" U2018, "’" U2019, "‚" U201A, "“" U201C, "”" U201D, "„" U201E, qui sont dans accent circonflexe, dans accent aigu ou dans tréma. compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
	* Annoter les symboles "⎄" U2384 et "¦" U00A6. compose-1.yml [1ce8524](https://github.com/dispoclavier/nouvel-azerty/commit/1ce852455e81374dd67cf9ce7acec0be6c737179)
	* Corriger et mettre à jour. compose-1.yml [9fca357](https://github.com/dispoclavier/nouvel-azerty/commit/9fca35712d6873f5fceda410ab1b8ab578f99993)
* Transformations :
	* Déboguer "͚" U035A, "͜" U035C, "͝" U035D, "͞" U035E, "͟" U035F, "∄" U2204, "∉" U2209, "∌" U220C. compose-2.yml [22b3da4](https://github.com/dispoclavier/nouvel-azerty/commit/22b3da4dd3e2e0b5c9ef62794c15296584414a17)
	* Groupes des lettres :
		* Groupe 3 :
			* Ajouter "Ꟛ" UA7DA à la place de "ꬷ" UAB37, qui va dans le groupe 11 à la place de "℄" U2104, qui est en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Ajouter "ꟛ" UA7DB à la place de "ƛ" U019B, qui va dans barré groupes 1 à 3. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Groupe 4 :
			* Ajouter "Ɤ" UA7CB. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Redonder "ⱷ" U2C77 à la place de "ᴗ" U1D17, qui est dans brève souscrite et va en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Redonder "Ω" U2126 à la place de "ᴖ" U1D16, qui est dans brève inversée souscrite et va en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Supprimer "℃" U2103, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Groupe 11 :
			* Redonder "ʩ" U02A9 à la place de "℉" U2109, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Supprimer "℉" U2109, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
	* Groupes des symboles : Redonder "⁀" U2040 et "‿" U203F à la place de "❨" U2768 et "❩" U2769. compose-3.yml [d93e3f1](https://github.com/dispoclavier/nouvel-azerty/commit/d93e3f135ec7a44bd6e108311393c4ddf945383d), [7b5984c](https://github.com/dispoclavier/nouvel-azerty/commit/7b5984c6792f47ebbda409340f60d9e948aaff63), [e154597](https://github.com/dispoclavier/nouvel-azerty/commit/e1545979d2487809abe4ffd87048beb2f463335b), compose-2.yml [9598dbd](https://github.com/dispoclavier/nouvel-azerty/commit/9598dbd0530f1860d1df1adef0f2b5dad011bb2c)
	* Exposant : Ajouter "ꜛ" UA71B par "<", "ꜜ" UA71C par ">". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Exposant groupe 1 : Ajouter "ᵸ" U1D78. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Exposant : Suscrit :
		* Ajouter "᪻" U1ABB par "(", "᪼" U1ABC par ")", "⃰" U20F0 par "*". compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
		* Ajouter "᷾" U1DFE par "<", "͐" U0350 par ">". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Groupe 1 : Ajouter "᫆" U1AC6 par espace. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Tilde :
		* Corriger les séquences de "⁓" U2053, "͠" U0360. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "︢" UFE22, "︣" UFE23. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Supprimer "¡" U00A1, "¿" U00BF, qui sont dans le groupe 1 de "!" et "?". compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Tilde et barré : Rajouter "≁" U2241. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Tilde et perluète :
		* Ajouter pour "᪾" U1ABE, "⃞" U20DE, "⃟" U20DF, "⃠" U20E0, "⃢" U20E2, "⃣" U20E3, "⃤" U20E4, "⃧" U20E7, "⃪" U20EA. compose-2.yml [bbbe67d](https://github.com/dispoclavier/nouvel-azerty/commit/bbbe67d92836a2a2ba864d9ff65115f0d0e10b21)
		* Ajouter "᫁" U1AC1, "᫂" U1AC2, "᫃" U1AC3, "᫄" U1AC4, "᫇" U1AC7, "᷹" U1DF9, "︠" UFE20, "︡" UFE21, "︢" UFE22, "︣" UFE23, "︤" UFE24, "︥" UFE25, "︧" UFE27, "︨" UFE28, "︩" UFE29, "︪" UFE2A, "︫" UFE2B, "︬" UFE2C. compose-2.yml [f8e7710](https://github.com/dispoclavier/nouvel-azerty/commit/f8e7710f1bc622957a7429b8291c0090ddfe2d03), [61f95d9](https://github.com/dispoclavier/nouvel-azerty/commit/61f95d914c377c61b22d4f12d34750c66aad5c04), [4824efc](https://github.com/dispoclavier/nouvel-azerty/commit/4824efce2c60d3b7915bd0e9587a4529051e0406), [47251d6](https://github.com/dispoclavier/nouvel-azerty/commit/47251d6f660f6809e32c131442ce88cbfdac3372), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ǀ" U01C0, "ǁ" U01C1, "ǂ" U01C2, "ǃ" U01C3, "𐞹" U107B9, "ʘ" U0298. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Tilde : Tilde médian : Redonder "︩" UFE29, "︪" UFE2A. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Point en chef :
		* Redonder "·" U00B7 pour la compatibilité ascendante avec la composition héritée. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
		* Redonder "ȷ" U0237 en Majuscule. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Brève inversée :
		* Corriger les séquences de "͡" U0361, "⁐" U2050, "𝼀" U1DF00. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "̯" U032F (par "&"), qui est dans brève inversée souscrite par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Brève inversée souscrite : Corriger les séquences de "᷼" U1DFC. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Brève :
		* Corriger les séquences de "͝" U035D. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "̮" U032E (par "&"), qui est dans brève souscrite par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Brève souscrite :
			* Redonder "Ḫ" U1E2A, "ḫ" U1E2B. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
			* Corriger les séquences de "͜" U035C. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Rayé : Redonder "ꜙ" UA719. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Double raie : Redonder "–" U2013 pour la compatibilité ascendante avec la composition héritée. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
		* Raie haute : Redonder "―" U2015. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Cornu :
		* Ajouter "᫉" U1AC9, "᫊" U1ACA. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b), [b69f110](https://github.com/dispoclavier/nouvel-azerty/commit/b69f110ec20787cda555e6c7bd558f17b565c8b9)
		* Ajouter "ꜚ" UA71A à la place de "˖" U02D6, qui va sur "p" et "P" et toutes les lettres inutilisées. compose-2.yml [30bb5de](https://github.com/dispoclavier/nouvel-azerty/commit/30bb5de97e8e1677a92f31ea1e34cd3b97a2a575)
	* Indice : Souscrit :
		* Ajouter "͎" U034E et "͍" U034D par "1" et "2". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter "᪸" U1AB8 par "J". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter ""͢" U0362 par "_". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter "᪽" U1ABD à la place de "̜" U031C et "̹" U0339, qui sont dans le groupe 5 de D et F. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
	* Macron :
		* Corriger les séquences de "͞" U035E. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ꜗ" UA717 à la place de "͞" U035E, qui sort par tiret cadratin et par arobase. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "ǀ" U01C0 par "5" à la place de "¦" U00A6, qui est dans le groupe 12 de "|", dans tréma et en composition. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ǁ" U01C1 par "8" à la place de "⏸" U23F8, qui est dans le groupe 7 de "|". compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "︤" UFE24, "︥" UFE25. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "¢" U00A2 par "c". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "ɺ" U027A par "R". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Macron souscrit :
			* Corriger les séquences de "͟" U035F. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Redonder "︫" UFE2B, "︬" UFE2C. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Barré :
		* Ajouter "Ꝃ" UA742, "ꝃ" UA743 à la place de "Ꞣ" UA7A2, "ꞣ" UA7A3, qui vont dans barre inclinée. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Ajouter "Ꟍ" UA7CC, "ꟍ" UA7CD à la place de "Ꞩ" UA7A8, "ꞩ" UA7A9, qui vont dans barre inclinée. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ꜘ" UA718 à la place de "∉" U2209, qui est dans le groupe 2 et en composition. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Redonder "∕" U2215 à la place de "ꜘ" UA718, qui sort par "€" U20AC et (ou) par "\\"". compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Supprimer "≁" U2241, qui va dans tilde et barré pour être débogué. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
		* Groupe 1 à 3 : Ajouter "Ƛ" UA7DC, "ƛ" U019B. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Barre inclinée :
			* Renommer de « barre courte » en « barre inclinée ». compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Ajouter "Ꞣ" UA7A2, "ꞣ" UA7A3 à la place de "Ꝃ" UA742, "ꝃ" UA743, qui vont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Ajouter "Ꞡ" UA7A0, "ꞡ" UA7A1, "Ꞥ" UA7A4, "ꞥ" UA7A5, "Ꞧ" UA7A6, "ꞧ" UA7A7, "Ꞩ" UA7A8, "ꞩ" UA7A9. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Supprimer "Ꝃ" UA742, "ꝃ" UA743, qui vont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Supprimer "Ꝙ" UA758, "ꝙ" UA759, qui sont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
			* Redonder "⟋" U27CB à la place de "ꜗ" UA717, qui va dans macron. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Triple barre :
			* Renommer et ajouter "᷻" U1DFB à la place de "⃫" U20EB, qui est en composition. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
			* Ajouter "␥" U2425 à la place de "ꜙ" UA719, qui va dans rayé. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Rond en chef : Redonder "ʾ" U02BE, "ʿ" U02BF, "˒" U02D2, "˓" U02D3, "∗" U2217. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Accent circonflexe :
		* Corriger les séquences de "᪰" U1AB0, "᷍" U1DCD. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "•" U2022. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Supprimer "̭" U032D (par "&"), qui est dans accent circonflexe souscrit par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Accent circonflexe souscrit :
			* Redonder "ꞈ" UA788 à la place de "‸" U2038, qui est dans le groupe 11 de "^". compose-2.yml [7b1ceef](https://github.com/dispoclavier/nouvel-azerty/commit/7b1ceef466ad3adcefa214ee7ccbb3575e25e20a)
			* Ajouter "˿" U02FF par "\\"" ou "€". compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc), [b69f110](https://github.com/dispoclavier/nouvel-azerty/commit/b69f110ec20787cda555e6c7bd558f17b565c8b9), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Hatchek : Supprimer "̬" U032C (par "&"), qui est dans hatchek souscrit par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Hatchek souscrit : Ajouter "ˬ" U02EC par espace insécable ou espace fine insécable à la place de "˯" U02EF, qui sort par "v" ou "V". compose-2.yml [e64dc0c](https://github.com/dispoclavier/nouvel-azerty/commit/e64dc0cd464f3b590aa32f4bba10adf2859b64ea)
	* Drapeau : Ajouter "˭" U02ED à la place de "⚑" U2691 et "⚐" U2690, qui vont en double frappe, suivis par "🏴" U1F3F4. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
		* Double drapeau : Redonder "͌" U034C, rajouter "⚑" U2691, "⚐" U2690, "🏴" U1F3F4. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
* Documentation :
	* Chaînes de caractères pour touches vives et contenu des touches mortes :
		* Corriger la description dans l’en-tête. compose-1.yml [823ba32](https://github.com/dispoclavier/nouvel-azerty/commit/823ba3231c7672af253778796ab3864802e91f7f), [ff713ff](https://github.com/dispoclavier/nouvel-azerty/commit/ff713ff537b12f08f25b898fb7c2e1f79528057b), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43), compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c), compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Corriger les notes à propos des tableaux. compose-1.yml [ff713ff](https://github.com/dispoclavier/nouvel-azerty/commit/ff713ff537b12f08f25b898fb7c2e1f79528057b), [8647ed0](https://github.com/dispoclavier/nouvel-azerty/commit/8647ed07e214334df54f6048c365461efcdfe889), [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
		* Ajouter le script utilisé pour formater UnicodeData.txt. format-UnicodeData-txt.pl [2ebca95](https://github.com/dispoclavier/nouvel-azerty/commit/2ebca9540230879bfb8a8d8743c0850c0a0215b6)
	* Arrêt de "∼" U223C dans le groupe 1 (4.1.0) : Compléter l’annotation. compose-3.yml [6a129d8](https://github.com/dispoclavier/nouvel-azerty/commit/6a129d823e3ded94273e08be43c5fe855f86822f)
	* Journal des modifications :
		* Uniformiser l’ordre des entrées. CHANGELOG.md [018acd1](https://github.com/dispoclavier/nouvel-azerty/commit/018acd112a6808fed563582996b6aea7fb044f2b)
		* Supprimer les parenthèses autour des fichiers modifiés. CHANGELOG.md [882c246](https://github.com/dispoclavier/nouvel-azerty/commit/882c2461834633c76f6a31a05584850c36fd1077)
		* Corriger la désignation des sources de disposition fusionnées. CHANGELOG.md [c391350](https://github.com/dispoclavier/nouvel-azerty/commit/c391350e0e4399144e43b4ad62c1daaadb9c7058)
		* Copier dans les notes de version les résumés omis dans le journal des modifications. CHANGELOG.md [de3e0fe](https://github.com/dispoclavier/nouvel-azerty/commit/de3e0fe658bd43ee919ac8dbea8f92528d322615)
		* Corriger la notation des séquences de composition. CHANGELOG.md [a32211b](https://github.com/dispoclavier/nouvel-azerty/commit/a32211baf420d2b1d568eed504d00699209e2aff)
		* Corriger la notation des caractères de base. CHANGELOG.md [f5e86ed](https://github.com/dispoclavier/nouvel-azerty/commit/f5e86ed338ddd6f642f99cef00c2ed0ff1ca3719), [78b5ad8](https://github.com/dispoclavier/nouvel-azerty/commit/78b5ad8ab9f70f489e53093d12f24f67ee377e22)
		* Ajouter la légende de la touche de composition. CHANGELOG.md [97e4faa](https://github.com/dispoclavier/nouvel-azerty/commit/97e4faa49733ee698881a67e62372e5197bca4df), [e866674](https://github.com/dispoclavier/nouvel-azerty/commit/e8666740a1db17f7abe2ce95bbd7e24016199007), [daf5c44](https://github.com/dispoclavier/nouvel-azerty/commit/daf5c4461d97478c84e3a1874cc5db0c294d3764)

## 4.2.1 (2024-08-30)

* Activation : Protéger un fichier .XCompose préexistant. activer.sh [5294412](https://github.com/dispoclavier/nouvel-azerty/commit/52944122d4387903e7dcab78e086da68f9a79c39), linux-chromeos/readme.md [7507ed6](https://github.com/dispoclavier/nouvel-azerty/commit/7507ed68e69df11aa2fc4d7d33c7b95b6c164a07), Lisez-moi-svp.txt [f4941b0](https://github.com/dispoclavier/nouvel-azerty/commit/f4941b0d91da34069404fe9024dc59108992ac38)

## 4.2.0 (2024-08-30)

Facilitation des mises à jour par le script d’installation.

Simplification et automatisation de l’activation sans droits d’administrateur par le nouveau script d’activation.

* Installation : Faciliter les mises à jour. installer.sh [0c93aaa](https://github.com/dispoclavier/nouvel-azerty/commit/0c93aaa8bb2aca60787791bf497a292ba0d45a91), [172f1a2](https://github.com/dispoclavier/nouvel-azerty/commit/172f1a2773bc49e2b9952208492cff5598c65777), [cd024ef](https://github.com/dispoclavier/nouvel-azerty/commit/cd024ef57cf461fa586cb52215754b690a006f88), linux-chromeos/readme.md [1145307](https://github.com/dispoclavier/nouvel-azerty/commit/114530720e83ca1b7325c69fd4c6eab8cf01fad0)
* Activation :
	* Fournir un script pour faciliter l’activation. activer.sh [5fb5636](https://github.com/dispoclavier/nouvel-azerty/commit/5fb563605062fa49667bcb1f468a75074fc5fb2c), [06f0482](https://github.com/dispoclavier/nouvel-azerty/commit/06f04828103e593619a0de7886b18627d0e81fd0), [638dc31](https://github.com/dispoclavier/nouvel-azerty/commit/638dc31e6ba514de87b5cb394ee4e7f183747913), [062df8e](https://github.com/dispoclavier/nouvel-azerty/commit/062df8e46f5c6a8a46980b90ba4373e85d7e25f1), [26e0bee](https://github.com/dispoclavier/nouvel-azerty/commit/26e0beed9d211c07c9fcbb09bd59cf7df32a2d46) (aussi [10536e7](https://github.com/dispoclavier/nouvel-azerty/commit/10536e7e3d557e2e720a8533316cf1f6873d33ef), [064156b](https://github.com/dispoclavier/nouvel-azerty/commit/064156b60533a10360f8ddc2e45d218b89ce05df), [760efce](https://github.com/dispoclavier/nouvel-azerty/commit/760efcea392533981c3d52a1c749a0c40fc94756)), Lisez-moi-svp.txt [10b5b33](https://github.com/dispoclavier/nouvel-azerty/commit/10b5b330fa037cd0d6d45dbb12dbd3cff9b09092), linux-chromeos/readme.md [6dd8aec](https://github.com/dispoclavier/nouvel-azerty/commit/6dd8aeca92bde97bc35254db43adec7209626230), [3f6716d](https://github.com/dispoclavier/nouvel-azerty/commit/3f6716da00c70d9e1802070b4b29b35b98d48ed1)
	* Proposer d’automatiser l’activation au démarrage. activer.sh [46e54f8](https://github.com/dispoclavier/nouvel-azerty/commit/46e54f8ba7ce6c846bfece16a958269ef11d07ed), [4626000](https://github.com/dispoclavier/nouvel-azerty/commit/46260003e27d8c47b9108be75e52dad69de154c5), [76df7f0](https://github.com/dispoclavier/nouvel-azerty/commit/76df7f091b6b87df14047e0d290ba6db63b95545), [2352530](https://github.com/dispoclavier/nouvel-azerty/commit/2352530cdf4412656f9c1718c5f92d26e8894250), [db1b73e](https://github.com/dispoclavier/nouvel-azerty/commit/db1b73e71ec15ca162c406587e35e30426e3d43b), linux-chromeos/readme.md [6dd8aec](https://github.com/dispoclavier/nouvel-azerty/commit/6dd8aeca92bde97bc35254db43adec7209626230), [3f6716d](https://github.com/dispoclavier/nouvel-azerty/commit/3f6716da00c70d9e1802070b4b29b35b98d48ed1)
	* Prévoir la fourniture de dispositions compilées comme une alternative aux sources de disposition fusionnées. comp.sh [e63e247](https://github.com/dispoclavier/nouvel-azerty/commit/e63e24766508f87fb72af37802f64e8d98e6773e), [6229021](https://github.com/dispoclavier/nouvel-azerty/commit/622902160670f9539eda3068af419a765f282dd5), [bbd0f42](https://github.com/dispoclavier/nouvel-azerty/commit/bbd0f42b44a516ca740c647c57106e0f0007e128)

## 4.1.0 (2024-08-23)

Le symbole racine cède sa place sur touche vive au symbole rapport, plus utile seul.

* Disposition : Redonder "∶" U2236 sur AltGr + AltFr + R à la place de "√" U221A, qui est dans le groupe 2 de "\\" avec "∛" U221B dans le groupe 3 et "∜" U221C dans le groupe 4. dispocla.cpp [173f7b0](https://github.com/dispoclavier/nouvel-azerty/commit/173f7b0b728821c322c241cba5e306a26f232dc8)
* Composition : Adapter les séquences de "∻" U223B, "≀" U2240, "≁" U2241, "⟦" U27E6, "⩳" U2A73, "⫝" U2ADD. compose-1.yml [6c30d09](https://github.com/dispoclavier/nouvel-azerty/commit/6c30d09f968239d96b81d904070d01b2fcdc45a6)
* Transformations:
	* Groupes des symboles :
		* Groupes 1 et 2 de "\~" : Redonder "≈" U2248 à la place de "≃" U2243, qui prend la place de "∼" U223C, (un doublon de "\~") qui est en composition. compose-3.yml [26ccb63](https://github.com/dispoclavier/nouvel-azerty/commit/26ccb63af7e56d1a72acc6279f79e76e759bc5d7), [ec2dcd4](https://github.com/dispoclavier/nouvel-azerty/commit/ec2dcd43ad42ef16baae966a75f30592ad02d60f), compose-1.yml [544cb51](https://github.com/dispoclavier/nouvel-azerty/commit/544cb516d2a2d705313f76855b5a60ba4a6e5ae3)
		* Groupe 11 de "!" : Ajouter "⸙" U2E19 à la place de "∎" U220E, qui est en composition. compose-3.yml [4d31de6](https://github.com/dispoclavier/nouvel-azerty/commit/4d31de65dd1cb263f10b6eb65a9d7f43d0b434ca), compose-1.yml [98c1039](https://github.com/dispoclavier/nouvel-azerty/commit/98c103904a989a6a58dd5fa50aabd7f3399c3dd8)
		* Groupe 11 de ":" : Mettre "⁝" U205D à la place de "⁚" U205A, qui est dans point souscrit. compose-3.yml [4d31de6](https://github.com/dispoclavier/nouvel-azerty/commit/4d31de65dd1cb263f10b6eb65a9d7f43d0b434ca)
		* Ajouter l’étiquette « math ». compose-3.yml [7e943f5](https://github.com/dispoclavier/nouvel-azerty/commit/7e943f55e1d8fdeb76ece7275469944cdd16d3b7)
	* Exposant :
		* Ajouter "˸" U02F8, qui était dans tréma souscrit. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Ajouter "ꜝ" UA71D. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Exposant et groupe 1 : Ajouter "𐞁" U10781, "𐞂" U10782. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Exposant > suscrit et groupe 1 :
		* Ajouter "ᫌ" U1ACC, "ᫍ" U1ACD, "ᫎ" U1ACE. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
		* Supprimer "ᷣ" U1DE3, qui va dans le groupe 2. ibidem
	* Exposant > suscrit et groupe 2 : Ajouter pour "ᷣ" U1DE3. ibidem
	* Exposant > suscrit et groupe 12 : Ajouter "ᫌ" U1ACC, "ᫍ" U1ACD, "ᫎ" U1ACE. ibidem
	* Double accent aigu : Adapter les séquences de "̎" U030E. compose-2.yml [5fee200](https://github.com/dispoclavier/nouvel-azerty/commit/5fee20031626452970da5f23e1fc52e624abc4b9)
	* Double accent aigu > triple accent aigu : Ajouter pour  "᫋" U1ACB. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Tilde :
		* Ajouter "˔" U02D4, "˕" U02D5, "꭪" UAB6A, "꭫" UAB6B. compose-2.yml [67b2c87](https://github.com/dispoclavier/nouvel-azerty/commit/67b2c87366708c633f0f740b721d79c84e0469d1)
		* Ajouter "͠" U0360 à la place de "”" U201D, qui est dans accent aigu. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Compléter les séquences de "⁓" U2053. ibidem
		* Redonder "͌" U034C à la place de "≃" U2243, qui est en composition et va dans le groupe 1 de "\~" (et y était dans le groupe 2). compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
		* Supprimer "̰" U0330, qui est dans tilde médian. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Supprimer "̴" U0334, qui va dans tilde médian. ibidem
	* Tilde et tourné : Ajouter pour "̾" U033E, "ⸯ" U2E2F. ibidem
	* Tilde et barré : Ajouter pour "͊" U034A. ibidem
	* Tilde et tréma : Ajouter "͋" U034B. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Tilde > tilde médian :
		* Rajouter "̴" U0334. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Ajouter "᷽" U1DFD à la place de "≈" U2248, qui est en composition et va dans le groupe 2 de "\~". compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Grec-ou-cerclé et indice : Ajouter "ᴦ" U1D26, "ᴧ" U1D27, "ᴨ" U1D28, "ᴩ" U1D29, "ᴪ" U1D2A, "ᵦ" U1D66, "ᵧ" U1D67, "ᵨ" U1D68, "ᵩ" U1D69, "ᵪ" U1D6A. ibidem
	* Point en chef : Ajouter "͒" U0352, "͘" U0358, "᪴" U1AB4, "᷸" U1DF8, "᷺" U1DFA. compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
	* Point en chef et accent aigu : Ajouter "᷁" U1DC1. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Point en chef et accent grave : Ajouter "᷀" U1DC0. ibidem
	* Brève : Corriger les séquences de "͝" U035D. ibidem
	* Brève et macron : Ajouter pour "᷋" U1DCB. ibidem
	* Brève et point en chef : Ajouter pour "̐" U0310. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Brève > brève souscrite : Corriger les séquences de "͜" U035C (compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d))
	* Ogonek > ogonek en chef : Ajouter pour "᷎" U1DCE. ibidem
	* Indice : Ajouter "ᴦ" U1D26, "ᴧ" U1D27, "ᴨ" U1D28, "ᴩ" U1D29, "ᴪ" U1D2A, "ᵦ" U1D66, "ᵧ" U1D67, "ᵨ" U1D68, "ᵩ" U1D69, "ᵪ" U1D6A. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Indice et groupe 6 : Ajouter pour "ᴦ" U1D26, "ᴧ" U1D27, "ᴨ" U1D28, "ᴩ" U1D29, "ᴪ" U1D2A, "ᵦ" U1D66, "ᵧ" U1D67, "ᵨ" U1D68, "ᵩ" U1D69, "ᵪ" U1D6A. ibidem
	* Indice > souscrit :
		* Ajouter "ᪿ" U1ABF à la place de "̫" U032B, qui est dans le groupe 12 de m. compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
		* Ajouter "᪵" U1AB5. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Indice > souscrit et tourné : Ajouter pour "ᫀ" U1AC0. ibidem
	* Macron : Ajouter "͞" U035E, "︦" UFE26. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Macron et brève : Ajouter pour "᷌" U1DCC. ibidem
	* Macron > macron souscrit : Ajouter "͟" U035F, "︭" UFE2D. ibidem
	* Barré et tilde : Supprimer avec "≄" U2244. compose-2.yml [5fee200](https://github.com/dispoclavier/nouvel-azerty/commit/5fee20031626452970da5f23e1fc52e624abc4b9)
	* Barré et tilde médian : Supprimer avec "≉" U2249. ibidem
	* Rond en chef > rond souscrit : Redonder "͚" U035A. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Accent circonflexe :
		* Ajouter "᪰" U1AB0 à la place de "•" U2022, qui est dans le groupe 2 de "_". ibidem
		* Ajouter "᷍" U1DCD à la place de "◦" U25E6, qui est dans le groupe 3 de "_". ibidem
	* Drapeau : Ajouter "͇" U0347 à la place de "⚐" U2690, qui prend la place de "⚑" U2691 par l’espace fine insécable. ibidem
	* Point souscrit : Ajouter "⃨" U20E8 à la place de "⁝" U205D, qui va dans le groupe 11 de ":". compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
	* Tréma et rond en chef : Ajouter pour "᪱" U1AB1. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Tréma > tréma souscrit : Redonder "‥" U2025 à la place de "˸" U02F8, qui va dans exposant. ibidem
* Documentation :
	* Mettre à jour le nom anglais de l’espace fine insécable ­" " U202F. compose-1.yml [386fa78](https://github.com/dispoclavier/nouvel-azerty/commit/386fa78123de7ef4a18af4a55603a43e1af3bce9), [9241b1a](https://github.com/dispoclavier/nouvel-azerty/commit/9241b1a2e3553150261c7fdb6031416a801af3e4), [1462c6a](https://github.com/dispoclavier/nouvel-azerty/commit/1462c6a62467e5ff96069499b6b9b40e1f7ebf4c), compose-2.yml [7d92df0](https://github.com/dispoclavier/nouvel-azerty/commit/7d92df027cb5b73ef4794480c4f8a2eb5c68a359)
	* Corriger l’abréviation de l’espace fine " " U2009 et autres. ibidem, compose-3.yml [fce1ab7](https://github.com/dispoclavier/nouvel-azerty/commit/fce1ab7fdc020921f9558010170516dbdae27710)
	* Mettre à jour les commentaires. compose-1.yml [6c30d09](https://github.com/dispoclavier/nouvel-azerty/commit/6c30d09f968239d96b81d904070d01b2fcdc45a6), compose-2.yml [79578fa](https://github.com/dispoclavier/nouvel-azerty/commit/79578fa0ad3fc9300e5379f08472c54a55520d4f), compose-3.yml [7e943f5](https://github.com/dispoclavier/nouvel-azerty/commit/7e943f55e1d8fdeb76ece7275469944cdd16d3b7)
	* Corriger le mode d’emploi. linux-chromeos/readme.md [7e9a5ab](https://github.com/dispoclavier/nouvel-azerty/commit/7e9a5abc88c3378946db1732998e926f227f9a3c), [4a08530](https://github.com/dispoclavier/nouvel-azerty/commit/4a08530899d595c3c9402cdd94ac6cd31a4ea8c0), [da0daaf](https://github.com/dispoclavier/nouvel-azerty/commit/da0daaf7873c444db994d52ac07e4fb7b812a84e)
	* Orthographe. compose-1.yml [3746f5e](https://github.com/dispoclavier/nouvel-azerty/commit/3746f5e053db16f0e93514714b88ae1bd01226b4), compose-2.yml [67b2c87](https://github.com/dispoclavier/nouvel-azerty/commit/67b2c87366708c633f0f740b721d79c84e0469d1), compose-3.yml [92a0ade](https://github.com/dispoclavier/nouvel-azerty/commit/92a0ade87078b18982e09104b8e625b2a6e64aee)

## 4.0.0 (2024-08-11)

Permutation des ponctuations espacées et non espacées sur AltFr et Maj.

* Disposition :
	* Mettre les ponctuations espacées à la place des ponctuations non espacées en Maj, qui prennent les places en AltFr laissées par les ponctuations espacées. dispocla.cpp [ba9f321](https://github.com/dispoclavier/nouvel-azerty/commit/ba9f321504bc8042429bf931eb6f47d403d7fe13), dispotypes [e41b05b](https://github.com/dispoclavier/nouvel-azerty/commit/e41b05b03fa268244027b9a8ca2caba8035889e2)
	* Redonder l’opérateur point "⋅" U22C5 sur AltGr + AltFr + X à la place du liant "‍" U200D, qui prend la place de l’antiliant "‌" U200C sur AltGr + AltFr + W, qui prend la place du ":" sur AltGr + AltFr + Q, qui est sur AltFr + la touche du deux-points.
* Documentation :
	* Mettre à jour le mode d’emploi. linux-chromeos/readme.md [3ab3d33](https://github.com/dispoclavier/nouvel-azerty/commit/3ab3d3331d0a3196936feb33a66bcba6e22cd8ff)
	* Mettre à jour le code source. compose-1.yml [0e1aedf](https://github.com/dispoclavier/nouvel-azerty/commit/0e1aedfb0b6646f672fa511567adf3141b071532), compose-2.yml [eaf2807](https://github.com/dispoclavier/nouvel-azerty/commit/eaf2807c711908fa26273a72ee573fc2c3c88f24)

## 3.5.1 (2024-08-10)

Prise en charge des barres de ton manquantes.

* Composition :
	* Ajouter les barres de ton additionnelles "꜈" UA708, "꜉" UA709, "꜊" UA70A, "꜋" UA70B, "꜌" UA70C, "꜍" UA70D, "꜎" UA70E, "꜏" UA70F, "꜐" UA710, "꜑" UA711, "꜒" UA712, "꜓" UA713, "꜔" UA714, "꜕" UA715, "꜖" UA716. compose-1.yml [d8d4de5](https://github.com/dispoclavier/nouvel-azerty/commit/d8d4de52fb8ad1448957d5b7c022eae17bc5291e)
	* Adapter la séquence de "⁨" U2068. ibidem
* Documentation. linux-chromeos/readme.md [8d712f9](https://github.com/dispoclavier/nouvel-azerty/commit/8d712f9d7129d5c46e4d1ca31ae65a7ba7360a83), compose-2.yml [e19e126](https://github.com/dispoclavier/nouvel-azerty/commit/e19e126dbfd8556c815c431353a5494e0c12633b), compose-3.yml [02651af](https://github.com/dispoclavier/nouvel-azerty/commit/02651afcc59bd886f0d4d8b2464b7ed57ca17948), dispocla.cpp [f281e69](https://github.com/dispoclavier/nouvel-azerty/commit/f281e69890dad1ae7bee4d234cf91cead365f0b8), [1b293ba](https://github.com/dispoclavier/nouvel-azerty/commit/1b293ba200c30f1dc02010e04c30a02be76d2588), [69e64f5](https://github.com/dispoclavier/nouvel-azerty/commit/69e64f587b8a88f6097af357d062ddbe6ba17108)

## 3.5.0 (2024-08-08)

* Composition :
	* Redonder "⁌" U204C, "⁍" U204D. compose-1.yml [9b7b785](https://github.com/dispoclavier/nouvel-azerty/commit/9b7b785d697158546d5edd532688941c0e359da8), [817b5d8](https://github.com/dispoclavier/nouvel-azerty/commit/817b5d8439cbd175ddaf714a14bc9884fd8e7b49)
	* Compléter les séquences de "∎" U220E, "◂" U25C2, "‣" U2023, "●" U25CF, "▬" U25AC, "◦" U25E6, "▫" U25AB, "▮" U25AE, "▭" U25AD, "▵" U25B5, "▿" U25BF, "☆" U2606, "•" U2022, "▪" U25AA, "▴" U25B4, "▾" U25BE. ibidem
	* Corriger les séquences de "☚" U261A, "☛" U261B. ibidem
	* Ajouter "👈" U1F448, "👉" U1F449. compose-1.yml [817b5d8](https://github.com/dispoclavier/nouvel-azerty/commit/817b5d8439cbd175ddaf714a14bc9884fd8e7b49)
* Transformations :
	* Groupes des symboles : (compose-3.yml [80afd99](https://github.com/dispoclavier/nouvel-azerty/commit/80afd99bc85cc719bf6b935c863533feb1921347))
		* Ajouter "⸿" U2E3F à la place de "⁖" U2056, qui prend la place de "⚐" U2690, qui prend la place de "⁌" U204C, qui va en composition avec les autres puces spécialisées, où elle est suivie par "⁍" U204D. compose-3.yml [80d680b](https://github.com/dispoclavier/nouvel-azerty/commit/80d680bfcfb87809e6466ab6f5eb2857ecc5964d)
		* Redonder "⁘" U2058 à l’ancienne place de "⁍" U204D. ibidem
		* Permuter "⌘" U2318 et "∎" U220E. ibidem
		* Arrêter la prise en charge des diacritiques phototypes "🏻" U1F3FB, "🏼" U1F3FC, "🏽" U1F3FD, "🏾" U1F3FE, "🏿" U1F3FF, inappropriée sur une disposition de clavier sans prise en charge extensive des émojis. compose-3.yml [7f517cc](https://github.com/dispoclavier/nouvel-azerty/commit/7f517cc69e6ef3d04350148c0e103fe5abec98f3)
		* Redonder "☚" U261A à la place de "⸿" U2E3F, qui prend la place laissée par "🏿" U1F3FF. ibidem
		* Redonder "☛" U261B à la place de "►" U25BA, qui prend la place de "✀" U2700, qui prend la place de "✂" U2702, qui prend la place de "∐" U2210, qui prend la place de "¶" U00B6, qui prend la place de "℗" U2117, qui est en composition. ibidem
		* Permuter "○" U25CB et "●" U25CF, "▢" U25A2 et "⯀" U2BC0. ibidem
		* Ajouter "⛯" U26EF à la place de "⚯" U26AF, qui prend la place de "⚮" U26AE, qui prend la place de "∝" U221D, qui prend la place laissée par "🏽" U1F3FD. ibidem
		* Mettre "⤴" U2934 à la place laissée par "🏼" U1F3FC. ibidem
		* Mettre "⤵" U2935 à la place laissée par "🏾" U1F3FE. ibidem
		* Redonder "⁚" U205A à la place laissée par "⤴" U2934. ibidem
		* Redonder l’antiliant "‌" U200C pour la mnémonique graphique à la place laissée par "🏻" U1F3FB. ibidem
		* Redonder "⟰" U27F0 à la place laissée par "⤵" U2935. ibidem
	* Réfléchi :
		* Ajouter "⌐" U2310. compose-2.yml [1422800](https://github.com/dispoclavier/nouvel-azerty/commit/14228002156f979d83c02316b08580df7c3966b6)
		* Compléter les séquences de "⁋" U204B. ibidem
		* Redonder "⁌" U204C, "⁍" U204D. ibidem
	* Réfléchi et groupe 1 : Redonder "Ƹ" U01B8, "ƹ" U01B9. ibidem
	* Grec-ou-cerclé : Adapter les séquences de "⊗" U2297. ibidem
	* Grec-ou-cerclé inversé :
		* Utiliser réfléchi au lieu de tourné. ibidem
		* Ajouter "🅐" U1F150.."🅩" U1F169, "🅰" U1F170.."🆉" U1F189. ibidem
	* Grec-ou-cerclé et tilde : Ajouter comme touche morte carré avec "🄰" U1F130.."🅉" U1F149. ibidem

## 3.4.3 (2024-07-31)

Prise en charge de lettres manquantes.

* Transformations :
	* Exposant et tourné : Ajouter "ꭩ" UAB69. compose-2.yml [6962d96](https://github.com/dispoclavier/nouvel-azerty/commit/6962d966f780f4d8109fa431e68e69b8efb65ed8)
	* Tourné et tilde : Ajouter "ꭨ" UAB68. ibidem
	* Grec-ou-cerclé et indice : Ajouter "ꭥ" UAB65. ibidem
	* Tourné : Supprimer "ⸯ" U2E2F. compose-2.yml [57cc11e](https://github.com/dispoclavier/nouvel-azerty/commit/57cc11eb43515cb98c12c6ac2f7a6657032c85bc)
	* Grec-ou-cerclé : Supprimer "⊝" U229D par "_". ibidem

## 3.4.2 (2024-07-31)

Rajout d’un symbole mathématique perdu dans la version 1.7.3.

Prise en charge de lettres manquantes.

* Composition :
	* Restaurer "⋊" U22CA, perdu dans la version 1.7.3. compose-1.yml [181f80f](https://github.com/dispoclavier/nouvel-azerty/commit/181f80f696d182232b23792169a111cbc6fe45a2)
	* Mettre "Ƣ" U01A2, "ƣ" U01A3 à la place de "Ȝ" U021C, "ȝ" U021D, qui est dans le groupe 2. ibidem
	* Ajouter "ꝰ" UA770. ibidem
* Transformations :
	* Exposant et groupe 1 : Ajouter "ꟹ" UA7F9. compose-2.yml [ac18a8c](https://github.com/dispoclavier/nouvel-azerty/commit/ac18a8c59b721a2e105bd62c218a36f7a992f25f)
	* Exposant et rayé : Ajouter "ꟸ" UA7F8. ibidem
	* Réfléchi : Ajouter "Ꟶ" UA7F5, "ꟶ" UA7F6. ibidem
	* Rayé, double raie : Ajouter "Ꟈ" UA7C7, "ꟈ" UA7C8, "Ꟊ" UA7C9, "ꟊ" UA7CA. ibidem
	* Groupes des lettres :
		* Groupe 4 :
			* Ajouter "Ꟗ" UA7D6 à la place de "℈" U2108, qui est en composition. compose-3.yml [9633960](https://github.com/dispoclavier/nouvel-azerty/commit/96339608a6cf13d6900e72770a237d5c61d20465)
			* Ajouter "ꟗ" UA7D7 à la place de "ʆ" U0286, qui est en bouclé. ibidem
		* Groupe 5 : Ajouter "Ꟁ" UA7C0, "ꟁ" UA7C1 à la place de "ʘ" U0298 par "O", qui est dans le groupe 5 par "B". ibidem
		* Groupe 11 :
			* Ajouter "Ꟑ" UA7D0, "ꟑ" UA7D1 à la place de "Ƣ" U01A2, "ƣ" U01A3, qui va en composition. ibidem
			* Ajouter "Ꟙ" UA7D8, "ꟙ" UA7D9 à la place de "Ƨ" U01A7, "ƨ" U01A8, qui est en composition. ibidem
			* Ajouter "ꟓ" UA7D3 et "ꟕ" UA7D5. ibidem

## 3.4.1 (2024-07-30)

Prise en charge du symbole som pour le Kirghizistan.

Débogages.

* Composition :
	* Mettre à jour le symbole monétaire par code ISO "Лв" U041B U0432 Som KYRGYZSTAN vers "⃀" U20C0 SOM SIGN. compose-1.yml [9ea34e0](https://github.com/dispoclavier/nouvel-azerty/commit/9ea34e023b55c39301a7bb5bdd808fb065e2346b)
	* Corriger les séquences de "⟎" U27CE pour déboguer "ą" U0105. ibidem
	* Corriger les séquences de "⩗" U2A57 pour déboguer "℣" U2123. ibidem
	* Supprimer des doublons pour "⋀" U22C0. ibidem
* Transformations : Indice et réfléchi : Corriger les séquences de "ᴙ" U1D19 pour déboguer "ᴎ" U1D0E et "ᴙ" U1D19. compose-2.yml [9b4a4c0](https://github.com/dispoclavier/nouvel-azerty/commit/9b4a4c0efdc8000b8abb604fcf7368013b255261)

## 3.4.0 (2024-07-30)

Prise en charge du symbole som pour le Kirghizistan.

Remise à plat de nombreuses séquences de composition de symboles mathématiques.

Poursuite de l’amélioration de la prise en charge de l’écriture latine.

* Composition :
	* Corriger les séquences de "⁡" U2061, "⁢" U2062, "⁣" U2063, "⁤" U2064, "∇" U2207, "∋" U220B, "∌" U220C, "∍" U220D, "∐" U2210, "∧" U2227, "⊃" U2283, "⊅" U2285, "⊇" U2287, "⊉" U2289, "⊋" U228B, "⊐" U2290, "⊒" U2292, "⊥" U22A5, "⋀" U22C0, "⋄" U22C4, "⋏" U22CF, "⋑" U22D1, "⋣" U22E3, "⋥" U22E5, "⋺" U22FA, "⋻" U22FB, "⋼" U22FC, "⋽" U22FD, "⋾" U22FE, "⟎" U27CE, "⟏" U27CF, "⟑" U27D1, "⧘" U29D8, "⧙" U29D9, "⧚" U29DA, "⧛" U29DB, "⨇" U2A07, "⨯" U2A2F, "⨿" U2A3F, "⩕" U2A55, "⩗" U2A57, "⩘" U2A58, "⩙" U2A59, "⩚" U2A5A, "⩜" U2A5C, "⩞" U2A5E, "⩟" U2A5F, "⩠" U2A60, "⪃" U2A83, "⪄" U2A84, "⪾" U2ABE, "⫀" U2AC0, "⫂" U2AC2, "⫄" U2AC4, "⫆" U2AC6, "⫈" U2AC8, "⫊" U2ACA, "⫌" U2ACC, "⫐" U2AD0, "⫑" U2AD1, "⫒" U2AD2, "⫓" U2AD3, "⫖" U2AD6, "⫘" U2AD8, "⫪" U2AEA, "⫫" U2AEB, "⫾" U2AFE. compose-1.yml [97ca5cb](https://github.com/dispoclavier/nouvel-azerty/commit/97ca5cb715405f1b28ce988c050921c7105dd1b3)
	* Ajouter "⁐" U2050. ibidem
	* Redonder "⧠" U29E0 et adapter les séquences de "❒" U2752, "❑" U2751, "❐" U2750, "❏" U274F. ibidem
* Transformations :
	* Groupes des symboles :
		* Ajouter "‸" U2038 à la place de "✈" U2708, qui prend la place de "∡" U2221, qui est en composition. compose-3.yml [137dc95](https://github.com/dispoclavier/nouvel-azerty/commit/137dc958d8624d619e2d687ad6aebf65dc17ad46)
		* Ajouter "⁃" U2043 à la place de "⹀" U2E40, qui est dans plusieurs touches mortes et en composition. ibidem
		* Ajouter "⁖" U2056 à la place de "‏" U200F, qui est en composition. ibidem
		* Redonder "✀" U2700 à la place de "►" U25BA, qui prend la place de "‎" U200E, qui est en composition. ibidem
	* Tilde : Ajouter "⁓" U2053. compose-2.yml [b4470e1](https://github.com/dispoclavier/nouvel-azerty/commit/b4470e18c39451256e6020b3d51f18506905822d)
	* Symbole monétaire : Ajouter "⃀" U20C0 à la place de "$", qui est sur touche vive. ibidem
	* Brève inversée : Redonder "⁐" U2050. ibidem
	* Indice : Ajouter "ₜ" U209C. ibidem
	* Accent circonflexe > accent circonflexe souscrit : Redonder "‸" U2038 à la place de "ꞈ" UA788, qui est avec le caractère de base espace fine insécable. ibidem

## 3.3.0 (2024-07-26)

Amélioration de la prise en charge de l’écriture latine.

* Composition :
	* Paléographie médiévale :
		* Ajouter "ᷓ" U1DD3, "ᷔ" U1DD4, "ᷕ" U1DD5, "ᷖ" U1DD6. compose-1.yml [17d8731](https://github.com/dispoclavier/nouvel-azerty/commit/17d8731adc64bb15ea3b6aa8bb66e88ceab9c451)
		* Redonder "᷏" U1DCF, "᷐" U1DD0, "᷑" U1DD1, "᷒" U1DD2. ibidem
	* Chiffres romains non décomposables :
		* Ajouter "ↀ" U2180, "ↂ" U2182, "ↈ" U2188, "ↁ" U2181, "ↇ" U2187, "ↅ" U2185, "ↆ" U2186. ibidem
	* Symboles de touches modificatrices :
		* Mettre "⟰" U27F0 à la place de "⬆" U2B06. ibidem
		* Simplifier les séquences. ibidem
	* Symboles de touche de composition :
		* Prendre en charge "¦" U00A6. ibidem
		* Corriger la séquence de "⎄" U2384. ibidem
* Transformations :
	* Exposant et groupe 1 :
		* Ajouter "ˀ" U02C0. compose-2.yml [32f4db9](https://github.com/dispoclavier/nouvel-azerty/commit/32f4db95799bdfb438dcb58efebb243c58e7745a)
		* Ajouter "ᵞ" U1D5E en Majuscule. ibidem
		* Redonder "ᵠ" U1D60. ibidem
	* Indice ou petite capitale et réfléchi :
		* Ajouter "ᴎ" U1D0E, "ᴙ" U1D19. ibidem
	* Réfléchi :
		* Redonder "ᴎ" U1D0E, "ᴙ" U1D19. ibidem
	* Exposant > suscrit et groupe 1 :
		* Ajouter "ᷘ" U1DD8, "ᷙ" U1DD9, "ᷣ" U1DE3, "ᷥ" U1DE5, "ᷧ" U1DE7, "ᷩ" U1DE9, "ᷪ" U1DEA, "ᷬ" U1DEC, "ᷭ" U1DED, "ᷯ" U1DEF, "ᷰ" U1DF0. ibidem
		* Redonder "ᷓ" U1DD3. ibidem
	* Exposant > suscrit et groupe 12 :
		* Redonder "ᷘ" U1DD8. ibidem
	* Tourné : Redonder "ɟ" U025F à la place de "ⅎ" U214E, qui passe en double pression. Permuter "Ⅎ" U2132 et "ꓞ" UA4DE. ibidem
* Documentation :
	* Corriger. compose-1.yml [17d8731](https://github.com/dispoclavier/nouvel-azerty/commit/17d8731adc64bb15ea3b6aa8bb66e88ceab9c451), compose-2.yml [32f4db9](https://github.com/dispoclavier/nouvel-azerty/commit/32f4db95799bdfb438dcb58efebb243c58e7745a), compose-3.yml [6b97818](https://github.com/dispoclavier/nouvel-azerty/commit/6b97818f83578fca6bf66b88b527e2ca79ac2745)
	* Déboguer linux-chromeos/readme.md. [31e6af7](https://github.com/dispoclavier/nouvel-azerty/commit/31e6af71d04aed655f64cfbbab1a8b7f7e5038ce)

## 3.2.2 (2024-07-25)

Débogage des fichiers servant à activer une disposition de clavier par xkbcomp.

* Activation : Déboguer les sources de disposition fusionnées en réactivant deux types de touches non utilisés et désactivés dans les distributions Linux de 2016. dispocla.cpp [6e6da51](https://github.com/dispoclavier/nouvel-azerty/commit/6e6da518aef27fac611ba90b6873328bf40d75c8), comp.sh [c0eecf0](https://github.com/dispoclavier/nouvel-azerty/commit/c0eecf0f0d8ca357b63c989d0ff3cd50daafa2e8)
* Documentation :
	* Point du pavé numérique : Corriger la référence du modèle cité, `kpdl(kposs)`, non `kpdl(dotoss)`. dispocla.cpp [3175e51](https://github.com/dispoclavier/nouvel-azerty/commit/3175e51073dfba773b12996fcc648dc55ba4558e)
	* Bogues des systèmes d’exploitation :
		* Documenter le recours à xkbcomp sous Linux Mint. comp.sh [bb82c93](https://github.com/dispoclavier/nouvel-azerty/commit/bb82c935ab22b17fa4eb235a5eab60cf203bc1f0), [5a71641](https://github.com/dispoclavier/nouvel-azerty/commit/5a71641554775d50bbb0d8cac15de0509444a7b2), Lisez-moi-svp.txt [258e86a](https://github.com/dispoclavier/nouvel-azerty/commit/258e86a720a3cbc9a6220d7bc3b60894fc9c26b2), [ed1664c](https://github.com/dispoclavier/nouvel-azerty/commit/ed1664c953631bfe3e0de94d11352d3b29a292cb), linux-chromeos/readme.md [8d4e19e](https://github.com/dispoclavier/nouvel-azerty/commit/8d4e19ea219b1ec9cd9646a6cbb3594a2507e371), [67d85af](https://github.com/dispoclavier/nouvel-azerty/commit/67d85afeaacf5cd8103d10fa15a7de38b84d84fd)
		* Préciser les bogues sous Linux Mint et sous ChromeOS. linux-chromeos/readme.md [2d1fc45](https://github.com/dispoclavier/nouvel-azerty/commit/2d1fc451e3463368481ebd8ff81e8c3e58425f59)
		* Préciser le bogue sous ChromeOS. linux-chromeos/readme.md [d235040](https://github.com/dispoclavier/nouvel-azerty/commit/d2350409ea06cb0acf657333def517bf2d9a9dae)
	* Personnalisation : Attirer l’attention sur la possibilité. Lisez-moi-svp.txt [711ee78](https://github.com/dispoclavier/nouvel-azerty/commit/711ee782775e7883b166d827da61ae189f8a1e5d)

## 3.2.1 (2024-07-14)

Rectification du carré plein centré et de la marque de répétition.

* Composition : Supprimer "⯀" U2BC0. compose-1.yml [d746dbb](https://github.com/dispoclavier/nouvel-azerty/commit/d746dbb2a07cb2273a413f8b16570ea0b2a1a4f3)
* Transformations : Groupes des symboles : Rajouter "⯀" U2BC0 dans le groupe 6 à la place de "〃" U3003, qui est dans le groupe 12. compose-3.yml [7629ef3](https://github.com/dispoclavier/nouvel-azerty/commit/7629ef3b3a9039aa0f0fc49b92d7d73db0103da4)

## 3.2.0 (2024-07-09)

Meilleure prise en charge des émojis.

* Disposition : Permuter "😭" U1F62D et "😱" U1F631 pour la mnémonique. dispocla.cpp [35f423f](https://github.com/dispoclavier/nouvel-azerty/commit/35f423f998a9af26189352f6d4eb8ed5bb376860)
* Composition : Ajouter "⯀" U2BC0 au nombre des puces. compose-1.yml [d9f67b1](https://github.com/dispoclavier/nouvel-azerty/commit/d9f67b10ebbf30578fa3df535076dc3410961392)
* Transformations : Groupes des symboles :
	* Redonder "▪" U25AA dans le groupe 5 de "#" à la place de "☐" U2610, qui est dans le groupe 1 et en composition. compose-3.yml [1218076](https://github.com/dispoclavier/nouvel-azerty/commit/121807642941fe311b5e4455c4217e101c756517)
	* Redonder "◾" U25FE dans le groupe 6 de "#" à la place de "☑" U2611, qui est dans le groupe 2 et en composition. ibidem
	* Redonder "◼" U25FC dans le groupe 7 de "#" à la place de "☒" U2612, qui est dans le groupe 3 et en composition. ibidem
	* Redonder "⬛" U2B1B dans le groupe 8 de "#" à la place de "⯀" U2BC0, qui est en composition. ibidem
	* Redonder "▫" U25AB dans le groupe 5 de "/" à la place de "⛆" U26C6, qui prend la place de "〰" U3030, qui prend la place de "⊤" U22A4, qui est en composition. ibidem
	* Redonder "◽" U25FD dans le groupe 6 de "/" à la place de "⊢" U22A2, qui est en composition. ibidem
	* Redonder "◻" U25FB dans le groupe 7 de "/" à la place de "⊣" U22A3, qui est en composition. ibidem
	* Redonder "⬜" U2B1C dans le groupe 8 de "/" à la place de "⊥" U22A5, qui est en composition. ibidem
* Documentation. linux-chromeos/readme.md [e96eda7](https://github.com/dispoclavier/nouvel-azerty/commit/e96eda7fac758277190d7e41251ed60a263c1969), dispocla.cpp [35f423f](https://github.com/dispoclavier/nouvel-azerty/commit/35f423f998a9af26189352f6d4eb8ed5bb376860), compose-2.yml [a119d4b](https://github.com/dispoclavier/nouvel-azerty/commit/a119d4b856f60bb01bcf44fb5c25a1c332e4cd18)

## 3.1.0 (2024-07-07)

Plusieurs caractères sont redisposés.

* Disposition :
	* Mettre le liant "‍" U200D à la place de l’antiliant "‌" U200C sur AltGr + AltFr + X, qui prend la place du deux-points sur AltGr + AltFr + W, qui prend la place de la barre de fraction "⁄" U2044 sur (Maj puis) AltGr + AltFr + Q (depuis 1.0.9), qui prend la place du symbole micro "µ" U00B5 sur AltGr + AltFr + F, qui est sur AltGr + AltFr + M. dispocla.cpp [157d828](https://github.com/dispoclavier/nouvel-azerty/commit/157d828f913b15f50666cc6d71e2124765c6390c)
	* Prendre en charge le gluon "⁠" U2060 par touche vive sur AltGr + AltFr + G à la place du tiret demi-cadratin "–" U2013, qui prend la place du tiret tabulaire "‒" U2012 sur AltGr + AltFr + T, qui est dans le groupe 1 du signe moins "−" U2212, et qui ne doit pas être sur touche vive. dispocla.cpp [2b0786b](https://github.com/dispoclavier/nouvel-azerty/commit/2b0786bff734f6ea883a67e542373a2bbdd36a27)
* Installation : Ajouter des messages affichés pendant le diagnostic. installer.sh [38cd80b](https://github.com/dispoclavier/nouvel-azerty/commit/38cd80b1ce9b9931f57fb1e5f81901c037f2abd3)
* Documentation :
	* Mode d’emploi :
		* Mettre à jour. linux-chromeos/readme.md [ecb2560](https://github.com/dispoclavier/nouvel-azerty/commit/ecb256088c841239f345fb9ed78bed970bf1ef4f)
		* Améliorer. linux-chromeos/readme.md [0d21efa](https://github.com/dispoclavier/nouvel-azerty/commit/0d21efa6e4f9a53804b8c59bb1a391839a8a5617)
		* Compléter. linux-chromeos/readme.md [b2012f1](https://github.com/dispoclavier/nouvel-azerty/commit/b2012f16d4946f2053e1288e1fa87fbcbe6c9fd9)
	* Corriger, compléter. compose-1.yml [8bd49b1](https://github.com/dispoclavier/nouvel-azerty/commit/8bd49b1d5bbd93e01e8622c8621274b8472a35b9), compose-2.yml [22b8333](https://github.com/dispoclavier/nouvel-azerty/commit/22b83333eb44737f444e5abc7b603e4beaae18b5), compose-3.yml [9a3cb00](https://github.com/dispoclavier/nouvel-azerty/commit/9a3cb0042658aaa48f7b8d0a55b452a73272e418)
	* Ajouter et mettre à jour des infobulles. generate-deadkey-tables.pl [998c71d](https://github.com/dispoclavier/nouvel-azerty/commit/998c71db225a5bf180a1fd2fcc85b71726d18cab), generate-math-table.pl [6a4d1c9](https://github.com/dispoclavier/nouvel-azerty/commit/6a4d1c9b3ac6ff4e6583b9f4bca86500c10402e0), generate-multikey-tables.pl [c3af782](https://github.com/dispoclavier/nouvel-azerty/commit/c3af782d1cc9143b8ad2aa98d5103827e57cb377)

## 3.0.0 (2024-07-04)

Les exposants changent de niveau, d’AltGr + AltFr à Maj + AltFr, afin que la majuscule de l’abréviation Numéro (avec le o en exposant) puisse être saisie en ajoutant Maj, non en ajoutant AltGr, sur Maj + AltGr + AltFr + N, et afin que le trigramme breton (avec la lettre apostrophe) bénéficie de la même logique sur A, ainsi que pour faciliter la saisie des minuscules en exposant (comme indicateurs d’abréviation, indicateurs ordinaux), en Maj + AltFr, non en AltGr + AltFr. Permutation des niveaux 6 et 7 sur la plupart des touches.

* Permuter les niveaux 6 et 7. dispocla.cpp [eda4dd1](https://github.com/dispoclavier/nouvel-azerty/commit/eda4dd14bcca8f876eccbb5e68e9fccadcf130ee), [c74e5a8](https://github.com/dispoclavier/nouvel-azerty/commit/c74e5a82814311b1716389dae0ab351c1e3b2068), [e3924aa](https://github.com/dispoclavier/nouvel-azerty/commit/e3924aae79e0ebc30a08b21da8cd2e6fc47c92ed), [17f0984](https://github.com/dispoclavier/nouvel-azerty/commit/17f0984949b62b5fcd9825e618e7341ce596d9f6), dispotypes.c [fc8683b](https://github.com/dispoclavier/nouvel-azerty/commit/fc8683be9e555c4d5b86a9a4d6e55ea79502153f), [accfc83](https://github.com/dispoclavier/nouvel-azerty/commit/accfc83f04a40d4deb8f2511f8fcd41a274ac9cc)
* Remettre "=" comme caractère en Contrôle plutôt que "+". dispotypes.c [accfc83](https://github.com/dispoclavier/nouvel-azerty/commit/accfc83f04a40d4deb8f2511f8fcd41a274ac9cc)
* Ajouter les options manquantes. dispocla.cpp [18f13bd](https://github.com/dispoclavier/nouvel-azerty/commit/18f13bd5e82596554c21bf8877926015dae7b5e1)
* Différencier les descripteurs du deuxième groupe de disposition. dispocla.cpp [0923f88](https://github.com/dispoclavier/nouvel-azerty/commit/0923f88245b0747d29ce96600621d1c1ff4795a6)
* Supprimer la prise en charge du digramme breton, non disposé. compose-1.yml [1d21d06](https://github.com/dispoclavier/nouvel-azerty/commit/1d21d0677c1b3e49a532111d83660bb646fed1b7)
* Rectifier et compléter la documentation. ibidem, compose-1.yml [1f3776e](https://github.com/dispoclavier/nouvel-azerty/commit/1f3776e536fbe430d3ecd064c237eb1a47dc4816), [06deaac](https://github.com/dispoclavier/nouvel-azerty/commit/06deaacdff00d8c9486bff786924751d60d6052f), dispocla.cpp [7cf2831](https://github.com/dispoclavier/nouvel-azerty/commit/7cf2831394f9e7df65484b630010abde0aa1c6ac), [6feb19d](https://github.com/dispoclavier/nouvel-azerty/commit/6feb19ddad97d4f6f34bfd77263e58dc1baa81ab)
* Mode d’emploi :
	* Mettre à jour. linux-chromeos/readme.md [b1e3cb9](https://github.com/dispoclavier/nouvel-azerty/commit/b1e3cb9fe1f399c03633553a350aea8d31baeead), [103add8](https://github.com/dispoclavier/nouvel-azerty/commit/103add83fb6129d1642bde54385fc696079ed1cb), [785c7ca](https://github.com/dispoclavier/nouvel-azerty/commit/785c7caa8220a52909d854ac4f2a8cf9dc27fff1)
	* Améliorer et compléter. linux-chromeos/readme.md [95bc470](https://github.com/dispoclavier/nouvel-azerty/commit/95bc47000498f18bced4126714b44e7b906fc436), [305b322](https://github.com/dispoclavier/nouvel-azerty/commit/305b322ef276e17f274dd2859f7b552707e29a4e), [d78e4c2](https://github.com/dispoclavier/nouvel-azerty/commit/d78e4c28f39183fca9f6724fab71f6945aca70e3), [0a0e506](https://github.com/dispoclavier/nouvel-azerty/commit/0a0e506b0e0c5207b10ef423eae84dad8f6be830)

## 2.3.7 (2024-06-30)

* Installation :
	* Corriger les conditions du script. installer.sh [d523755](https://github.com/dispoclavier/nouvel-azerty/commit/d5237552c515ba2441574ec7eff110e1507fb3f5)
	* Clarifier et compléter des messages du script. ibidem
	* Harmoniser les retraits de début de ligne des messages du script. ibidem
* Documentation :
	* Mode d’emploi : Améliorer et compléter. linux-chromeos/readme.md [5aee580](https://github.com/dispoclavier/nouvel-azerty/commit/5aee5804715e314faf18409ba726e380a91a7fe1), [1dffe31](https://github.com/dispoclavier/nouvel-azerty/commit/1dffe3190810907c466282964baa0bd0ec60c5dc), [be7dc68](https://github.com/dispoclavier/nouvel-azerty/commit/be7dc6820c16f4594bd2b2e3f18d0c561544221f), [f609e19](https://github.com/dispoclavier/nouvel-azerty/commit/f609e19c15a6d73ae49fd988120a3b2cbd4e2862), [0e9742a](https://github.com/dispoclavier/nouvel-azerty/commit/0e9742afdf4737520ffd38a7c775b97e23a29945), [54ab01c](https://github.com/dispoclavier/nouvel-azerty/commit/54ab01c8c5c6fb7385cd8c7ddce33904aae1d1ba), [7cb6d32](https://github.com/dispoclavier/nouvel-azerty/commit/7cb6d32fc8e7755308a4c86fc9a218afb09da42d), [a5e76da](https://github.com/dispoclavier/nouvel-azerty/commit/a5e76da2847ca456b3066d75b92527e50b4bfa80), [81d6e16](https://github.com/dispoclavier/nouvel-azerty/commit/81d6e16b2f805a6dcb66666f986ab302760e7fde)
	* Alerter sur Linux Mint. linux-chromeos/readme.md [428dd59](https://github.com/dispoclavier/nouvel-azerty/commit/428dd59d1be592abde77b0a6286453362040bfe3), [e10dfc1](https://github.com/dispoclavier/nouvel-azerty/commit/e10dfc1932d5f2ae9c1ce2a30f5490caa9fad3c0), [823bba6](https://github.com/dispoclavier/nouvel-azerty/commit/823bba6fe9ea1cb6029b4c1b25160a001c500d15), [a74b9d6](https://github.com/dispoclavier/nouvel-azerty/commit/a74b9d6e0ba35cfdb1789d90991dabb79ac1abda), [5b7b147](https://github.com/dispoclavier/nouvel-azerty/commit/5b7b1475dec9c3a1d9c538d72938dd059e85d9fd), [d360eef](https://github.com/dispoclavier/nouvel-azerty/commit/d360eeff4a662da20179efa3530d7abf9aea68a0), [388d38e](https://github.com/dispoclavier/nouvel-azerty/commit/388d38e87dbe1878fc9c8f5984cc5a2b8e36dcdf), [17347e7](https://github.com/dispoclavier/nouvel-azerty/commit/17347e7eca3bfc1dbf6ba99e7281d4fded8a5b56)
	* Récrire des annotations. compose-3.yml [c7c3d72](https://github.com/dispoclavier/nouvel-azerty/commit/c7c3d723c188629501290f910220f6b13e15dc60)

## 2.3.6 (2024-06-23)

* Installation :
	* Corriger des messages du script. installer.sh [6630958](https://github.com/dispoclavier/nouvel-azerty/commit/6630958a206e5077693a12a1d4e78edf0d87885c)
	* Clarifier des messages du script. ibidem
	* Harmoniser les retraits de début de ligne des messages du script. ibidem et installer.sh [07a3f1c](https://github.com/dispoclavier/nouvel-azerty/commit/07a3f1c3883b6ad9cb747c62baf36dd333e5300d)
* Documentation. compose-1.yml [0fac783](https://github.com/dispoclavier/nouvel-azerty/commit/0fac7837f998d0ce20ca9da83ebc1c76a74a7d86), compose-2.yml [0c9738a](https://github.com/dispoclavier/nouvel-azerty/commit/0c9738aa8f835ec9cc90fa4c8b9636031f00ae51), compose-3.yml [b518c7e](https://github.com/dispoclavier/nouvel-azerty/commit/b518c7e650eeacc6a0990dafc7049e683f6f3065), [359c1e1](https://github.com/dispoclavier/nouvel-azerty/commit/359c1e174374664d22cc6b4a64f9f46ecbd3b59c)

## 2.3.5 (2024-06-19)

* Installation : Déboguer le script. installer.sh [22b0887](https://github.com/dispoclavier/nouvel-azerty/commit/22b08870a5fe325ab6eabd947a2220cddf07f3db)

## 2.3.4 (2024-06-19)

Script d’installation qui prend en charge aussi les redispositions des sous-variantes.

* Sous-variantes :
	* Prendre en charge aussi les agencements ANSI purs. evdev.c [d98b5de](https://github.com/dispoclavier/nouvel-azerty/commit/d98b5de4daa2c29fb690f2d175b41a6301996deb)
	* Restaurer les touches de fonction 19 et 24 (désactivées pour la version 1.1.1). ibidem
	* Fournir un fichier `evdev.c` redisposé pour chaque catégorie de sous-variantes.
* Installation :
	* Gérer les redispositions de touches des sous-variantes pendant l’installation. installer.sh [bc51116](https://github.com/dispoclavier/nouvel-azerty/commit/bc51116238f53b2be4f7f28b31ab950a59078dd6), [df8aac7](https://github.com/dispoclavier/nouvel-azerty/commit/df8aac7e8389ec85af0a13c035c9aa6852f7448d)
	* Déverrouiller les fichiers sauvegardés pendant la désinstallation. ibidem
	* Améliorer la robustesse du script. ibidem
	* Améliorer l’intelligibilité des messages du script. installer.sh [3a56c32](https://github.com/dispoclavier/nouvel-azerty/commit/3a56c32fe8e10b186e1c69156222c269901889be)
* Documentation. compose-1.yml [c44a9d8](https://github.com/dispoclavier/nouvel-azerty/commit/c44a9d86810711b6ac1c1be019ded28bb9132bfb)

## 2.3.3 (2024-06-16)

Script d’installation amélioré.

* Installation :
	* Sortir le script du sous-dossier `outils/`. installer.sh [b48cd4a](https://github.com/dispoclavier/nouvel-azerty/commit/b48cd4a59b3a56354b3dae710e5e134488a268da)
	* Améliorer l’expérience utilisateur. installer.sh [013dd59](https://github.com/dispoclavier/nouvel-azerty/commit/013dd59b15a467bd3c18a2a4e8fe861961ded582)
	* Mettre à jour la documentation. compose-1.yml [bc45134](https://github.com/dispoclavier/nouvel-azerty/commit/bc45134f03e377b2cb6eb3849d3e32cc8971998d), readme.md [e9eccec](https://github.com/dispoclavier/nouvel-azerty/commit/e9eccec9195f8f5986bcc71c74fd1960b59b00c2), [fa1644e](https://github.com/dispoclavier/nouvel-azerty/commit/fa1644e84ceab8ad426c5899ac8b60e77e6c62a2), [369d48f](https://github.com/dispoclavier/nouvel-azerty/commit/369d48f7d106132f5f82f86e21bb905b327b50ff)

## 2.3.2 (2024-06-15)

* Installation : Fournir un script pour automatiser l’installation. installer.sh [4dc1b1b](https://github.com/dispoclavier/nouvel-azerty/commit/4dc1b1b3a0c1ab4d5ac3fd9735cb309cbc6793f6)
* Documentation. evdev-additions.xml [37d393b](https://github.com/dispoclavier/nouvel-azerty/commit/37d393bf5a171f1f8e3733431236de0615799ae8), compose-1.yml [0c06057](https://github.com/dispoclavier/nouvel-azerty/commit/0c060578cb1276f95ed4b5cc297d2ab37fdfeb28), [ea8660d](https://github.com/dispoclavier/nouvel-azerty/commit/ea8660d076fe28eb9e84309508520a434c4fa650), [a2f1a7f](https://github.com/dispoclavier/nouvel-azerty/commit/a2f1a7f00c88c54129fd3cbd98a6824770afc0e2), compose-3.yml [e92cfb9](https://github.com/dispoclavier/nouvel-azerty/commit/e92cfb960be614513c6c94ee3caa14f9440a979b), [78d5438](https://github.com/dispoclavier/nouvel-azerty/commit/78d5438a5dd122ebf2b6dda38d8a20cbadd03729)

## 2.3.1 (2024-06-12)

* Variantes redisposées : Disposition : Restaurer la touche morte accent grave, perdue dès la version 2.0.0. dispocla.cpp [3447c5d](https://github.com/dispoclavier/nouvel-azerty/commit/3447c5dd892925f994af6e36f249f137b0a57e5f)
* Documentation. dispocla.cpp [ff2ae89](https://github.com/dispoclavier/nouvel-azerty/commit/ff2ae89b787340d93e2956e1561ef18e5cdbaca9), [a765295](https://github.com/dispoclavier/nouvel-azerty/commit/a765295c5159be22d6a8c4084850542870b8a25e), [abad9ea](https://github.com/dispoclavier/nouvel-azerty/commit/abad9ea974e0f2e65584a9f6262e6c3ebd017740), [3447c5d](https://github.com/dispoclavier/nouvel-azerty/commit/3447c5dd892925f994af6e36f249f137b0a57e5f), compose-1.yml [479e3fa](https://github.com/dispoclavier/nouvel-azerty/commit/479e3fa96252ef1396c917695fff971cb4a9ab20), [7b1dc2b](https://github.com/dispoclavier/nouvel-azerty/commit/7b1dc2ba2994e69c0b36f3dc345d1bb99e3f76ff), compose-2.yml [ca21e7b](https://github.com/dispoclavier/nouvel-azerty/commit/ca21e7b84d88fbfe062d0d7e26f812a7476e9ed0), compose-3.yml [41fd139](https://github.com/dispoclavier/nouvel-azerty/commit/41fd139c247d8c45cc70c0a208acd76f1a672ec4)

## 2.3.0 (2024-06-08)

* Disposition du pavé numérique :
	* Chiffres :
		* Mode français :
			* Majuscule :
				* Touche 4 : Mettre le préfixe Unicode complet "U+" à la place de "U" U0055. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d)
				* Touche 7 : Mettre la barre de fraction "⁄" U2044 à la place de l’espace fine insécable " " U202F. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), [4c9e353](https://github.com/dispoclavier/nouvel-azerty/commit/4c9e353764d19bad4ecb48f583b96b2e45bbfbe6)
			* Permuter les flèches simples et les flèches émojis ; permuter les flèches doubles et les flèches pleines. dispocla.cpp [e3bf0c6](https://github.com/dispoclavier/nouvel-azerty/commit/e3bf0c60e26641106c106c4acda1dde9d32a34a8), compose-2.yml [5545ce0](https://github.com/dispoclavier/nouvel-azerty/commit/5545ce01c3ad79853b4db27f13acf4063798068b)
		* Mode ASCII :
			* Mettre "000" à la place de "0x", "#" à la place de "\\u{", "\\" U005C à la place de "\\x{". dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d)
			* Permuter les flèches émojis et les flèches à tête triangulaire ; permuter les flèches pleines et les flèches ajourées. dispocla.cpp [e3bf0c6](https://github.com/dispoclavier/nouvel-azerty/commit/e3bf0c60e26641106c106c4acda1dde9d32a34a8), compose-2.yml [5545ce0](https://github.com/dispoclavier/nouvel-azerty/commit/5545ce01c3ad79853b4db27f13acf4063798068b)
	* Opérateurs :
		* Plus :
			* Majuscule : Redonder ":" à la place de "+". dispocla.cpp [f3bdb52](https://github.com/dispoclavier/nouvel-azerty/commit/f3bdb52d165f418ad11315bf662ef4e80ef47e6d), [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), dispotypes.c [4eef10d](https://github.com/dispoclavier/nouvel-azerty/commit/4eef10d6fc4f76bfd98c8b8ba33d9e87958b21e1), [90d5a43](https://github.com/dispoclavier/nouvel-azerty/commit/90d5a43d2e09c83433c18160a9ec01a4ab11ce43)
			* Mode ASCII : Rajouter "0x". ibidem
		* Moins : Mode ASCII : Mettre "=" à la place de "#". Rajouter "\\x{". ibidem
		* Multiplier : Mode ASCII : Redonder "}". ibidem
		* Diviser : Mode ASCII : Mettre "\\u{" à la place de la barre de fraction "⁄" U2044. ibidem
	* Point :
		* Mode ASCII : Mettre l’espace fine insécable " " U202F à la place de l’espace " " U0020. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), [4109119](https://github.com/dispoclavier/nouvel-azerty/commit/41091193b9bb027145bd41b1561164bdf4ba727f)
		* Rectifier le code et la documentation. dispocla.cpp [e1803c3](https://github.com/dispoclavier/nouvel-azerty/commit/e1803c3f3bb56cf01d6063087fc8f22eb09e715e), [959b970](https://github.com/dispoclavier/nouvel-azerty/commit/959b9707531e0768d77a8b29ddb39f169c065efe), [3f12966](https://github.com/dispoclavier/nouvel-azerty/commit/3f12966eb664f25c5f0d24cb6b253cd61eb339c6)
	* Déboguer la touche virgule des claviers brésiliens. dispocla.cpp [e1803c3](https://github.com/dispoclavier/nouvel-azerty/commit/e1803c3f3bb56cf01d6063087fc8f22eb09e715e)
	* Prendre en charge aussi la touche B11 des claviers brésiliens. dispocla.cpp [339fed4](https://github.com/dispoclavier/nouvel-azerty/commit/339fed4643ab4e4f44d01409793b78b1f9d18929), [8f5ebba](https://github.com/dispoclavier/nouvel-azerty/commit/8f5ebba8383c90b2986994bcdad4202c30eddf55)

## 2.2.1 (2024-06-03)

* Sortie multi-caractères : Déboguer "&#" et "&#x". compose-1.yml [456f97e](https://github.com/dispoclavier/nouvel-azerty/commit/456f97e489a250088bb181f72eb3c199a92e579a)

## 2.2.0 (2024-06-02)

* Disposition : Mode ASCII : Touches C11, C12, D11, D12 en Maj + AltGr/Option et en AltFr + AltGr/Option : Mettre "⁽" U207D à la place de "%" ou de "A" U0041, "⁾" U207E à la place de "*" ou de "B" U0042, "^" à la place de "C" U0043, "⁼" U207C à la place de "$" ou de "D" U0044 ; en Maj + AltFr : Mettre "_" à la place de la touche morte tréma, "₌" U208C à la place de "£" U00A3, "₍" U208D à la place de "%", "₎" U208E à la place de "µ" U00B5. dispocla.cpp [78281d0](https://github.com/dispoclavier/nouvel-azerty/commit/78281d0d195d5b5497eb7c86c632e1121e0fb048), [4fd1c54](https://github.com/dispoclavier/nouvel-azerty/commit/4fd1c54304db7fbf2cfaad628e7444d411a6681f), [bfd180c](https://github.com/dispoclavier/nouvel-azerty/commit/bfd180c48541a316185d747ba7cdece768088cfe)
* Personnalisation :
	* Simplifier le code de la touche 1 des variantes pour le breton et pour l’Afrique francophone. dispocla.cpp [5d77c5e](https://github.com/dispoclavier/nouvel-azerty/commit/5d77c5e35c309b7af9a17351bb550e750bbd7a72), dispotypes.c [982d5d6](https://github.com/dispoclavier/nouvel-azerty/commit/982d5d62ab5b76d04b2fe594b2003d607447bea1)
	* Compacter le code pour faciliter la maintenance. dispocla.cpp [aba7eb0](https://github.com/dispoclavier/nouvel-azerty/commit/aba7eb063e7e121cbf2f86e7e8bb35efcc81e57c)
* Documentation. dispocla.cpp [8df14fd](https://github.com/dispoclavier/nouvel-azerty/commit/8df14fd2cde91256cad5c7ad4ba41fa9cf5e7702), dispotypes.c [bc83d02](https://github.com/dispoclavier/nouvel-azerty/commit/bc83d0210b7533e077baefde6038c56450cc1070)

## 2.1.0 (2024-05-31)

* Disposition :
	* Déboguer la touche 8 de la variante belge. dispocla.cpp [a2fa910](https://github.com/dispoclavier/nouvel-azerty/commit/a2fa910f037fc7ba63f2d1e52aaa9ac26239da5e)
	* Mode ASCII : Touche E11 en AltGr/Option : Mettre "-" U002D à la place de "°" U00B0. dispotypes.c [1372a36](https://github.com/dispoclavier/nouvel-azerty/commit/1372a366ff1b71065719d29e4aab58cf10d9a810), dispocla.cpp [a2fa910](https://github.com/dispoclavier/nouvel-azerty/commit/a2fa910f037fc7ba63f2d1e52aaa9ac26239da5e)

## 2.0.6 (2024-05-30)

* Disposition :
	* Déboguer "′" U2032 sur la touche D02. dispotypes.c [a1d471a](https://github.com/dispoclavier/nouvel-azerty/commit/a1d471a49c216dd940c81e0d695957e93baf3614), dispocla.cpp [91aa602](https://github.com/dispoclavier/nouvel-azerty/commit/91aa602d43a1756e9cd053b0c817dae459869588)
	* Déboguer la touche D01 des variantes redisposées. ibidem
* Personnalisation : Améliorer la maintenabilité du code. dispotypes.c [a1d471a](https://github.com/dispoclavier/nouvel-azerty/commit/a1d471a49c216dd940c81e0d695957e93baf3614), [b7f2ae8](https://github.com/dispoclavier/nouvel-azerty/commit/b7f2ae8ed5d9e5aff78392c5720a352be3376c0c), [c98825a](https://github.com/dispoclavier/nouvel-azerty/commit/c98825a9c4119d45a0935bdea732d7310ab92f5e), dispocla.cpp [91aa602](https://github.com/dispoclavier/nouvel-azerty/commit/91aa602d43a1756e9cd053b0c817dae459869588), [b8c19bf](https://github.com/dispoclavier/nouvel-azerty/commit/b8c19bf8378b37d9c617326c8666a2d2aef8e978), [21780af](https://github.com/dispoclavier/nouvel-azerty/commit/21780af35e9a2ba556e34614156b599c0e3cbeb4)

## 2.0.5 (2024-05-28)

* Disposition : Déboguer la touche B06. dispotypes.c [e6fa645](https://github.com/dispoclavier/nouvel-azerty/commit/e6fa6456530e1d2b4d4d31056b57d01acf597e24)

## 2.0.4 (2024-05-27)

* Disposition :
	* Déboguer les touches 2, 7, 9 en mode ASCII. dispotypes.c [6eb5ada](https://github.com/dispoclavier/nouvel-azerty/commit/6eb5ada1baafa5e1a3ad9ad65ccdef221c0edfab)
	* Déboguer la touche 1 des variantes pour le breton. dispocla.cpp [5e36f73](https://github.com/dispoclavier/nouvel-azerty/commit/5e36f731ad7327582e8c298e18a49321933caa8a), dispotypes ibidem
* Vues de disposition : Optimiser pour un rendu intelligible. ibidem
* Commutateur : Documentation. evdev-additions.xml [e983458](https://github.com/dispoclavier/nouvel-azerty/commit/e983458faf769aeeb30da32b6fd9a88c332cb945), [9447c03](https://github.com/dispoclavier/nouvel-azerty/commit/9447c031b59d82360d041a27e962a94187aa8b6c)
* Sous-variantes : Documentation. evdev.c [ca470f1](https://github.com/dispoclavier/nouvel-azerty/commit/ca470f166bb947ece0ba07354ec10b03202ddf3e)

## 2.0.3 (2024-05-25)

* Commutateur : Mettre à jour par l’ajout des codes de pays. evdev-additions.xml [1d5bdf7](https://github.com/dispoclavier/nouvel-azerty/commit/1d5bdf770e3cb68a633748107e569bd36443b9e0)

## 2.0.2 (2024-05-23)

* Transformations : Documentation. compose-2.yml [d5274a3](https://github.com/dispoclavier/nouvel-azerty/commit/d5274a393d8c77e9063e7d11da962c48c6394c7f), [6242a03](https://github.com/dispoclavier/nouvel-azerty/commit/6242a039772829d27b53381994809623d5a518fe), [450eac7](https://github.com/dispoclavier/nouvel-azerty/commit/450eac78b64940e119aa68cd4c66850392e8a448)

## 2.0.1 (2024-05-22)

* Transformations : Déboguer les dispositions pour les systèmes postérieurs à octobre 2023 suite à la suppression du nom XKB de la touche morte barré. dispocla.cpp [9ec9fc2](https://github.com/dispoclavier/nouvel-azerty/commit/9ec9fc26ce3b3a31b60fa4e78ea456280ba0a4d7), compose-2.yml [6de07bb](https://github.com/dispoclavier/nouvel-azerty/commit/6de07bb4ae228c8c3e2277fbed21b8bf01ee1045), compose-1.yml [882ca8a](https://github.com/dispoclavier/nouvel-azerty/commit/882ca8a19e47b2fe544aa4f351cf49fa56613f6b)

## 2.0.0 (2024-05-20)

Version 2.0 due à la nécessité de redonder en AltGr le symbole euro, de redisposer 30 % des symboles ASCII, et de disposer en Minuscule, en mode français, l’apostrophe ASCII à côté de l’apostrophe française. compose-1.yml [8b62065](https://github.com/dispoclavier/nouvel-azerty/commit/8b6206594ebf9b02e36d94466f253d8fb0a18030)

* Disposition :
	* Redonder le symbole "€" U20AC en AltGr/Option à la place de "{". dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [d7e798a](https://github.com/dispoclavier/nouvel-azerty/commit/d7e798a2ad558a15bb1808bf022a510150a26ffe), [f7d237b](https://github.com/dispoclavier/nouvel-azerty/commit/f7d237bd0cb41ae8a89c9c6318ff2ed8174ac8a5)
	* Redonder l’apostrophe ASCII "'" sur la touche 5 à la place de la touche morte accent grave, qui prend la place de la touche de composition, qui prend la place de "ʳ" U02B3 sur AltGr/Option + +=, qui est sur AltGr/Option + AltFr + R et dans la touche morte exposant. En mode ASCII, redonder la touche de composition à son ancienne place, la nouvelle place d’accent grave. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [7a48fec](https://github.com/dispoclavier/nouvel-azerty/commit/7a48fec7cc58116bb2ebf58e5b16337eca67064f), dispotypes.c [073788e](https://github.com/dispoclavier/nouvel-azerty/commit/073788e985a58998b309ce5920e19611a600e72c)
	* Symboles ASCII :
		* Mettre "{" à la place de "'", qui prend la place de "\\"" U0022, qui est sur la touche du 3 en mode français et sur la touche de l’accent circonflexe en mode ASCII, et qui est remplacé par "€" U20AC à la place laissée par "{". dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Mettre "}" à la place de "`", qui prend la place de "\\" U005C, qui prend la place laissée par "}". ibidem
		* Mettre "[" en dessous de "{" à la place de "]", qui prend la place de "_", qui prend la place laissée par "[". ibidem
		* Raccourcis contrôle : Déboguer Ctrl + "+" pour les applications ne fonctionnant pas avec Ctrl + "=". dispotypes.c [073788e](https://github.com/dispoclavier/nouvel-azerty/commit/073788e985a58998b309ce5920e19611a600e72c)
	* Touches mortes en Maj + AltGr/Option :
		* Faire suivre crosse ou crochet à la place d’accent aigu, qui prend la place de double accent aigu, qui prend la place laissée par crosse ou crochet. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [d908a99](https://github.com/dispoclavier/nouvel-azerty/commit/d908a997202108277a749a45d432dda0dbde25b2)
		* Faire suivre crochet rétroflexe à la place d’accent grave, qui prend la place de réfléchi, qui prend la place laissée par crochet rétroflexe. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Faire suivre ogonek à la place de crochet en chef, qui prend la place d’indice, qui prend la place laissée par ogonek. ibidem
	* Symboles en Maj + AltFr :
		* Permuter "″" U2033 et "U+", qui passe de la touche E à la touche U. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Ajouter "\\u{" à la place de "′" U2032 (touche I, nouvelle touche de "{"), qui prend la place de "‰" U2030 (touche Z, à côté de "″" U2033), qui est dans le groupe 1 de "%" et est tombé en désuétude. ibidem
		* Faire suivre "‾" U203E de Maj + AltGr/Option + AltFr + L sur Maj + AltFr + J, la nouvelle touche de "_", à la place de "⟨" U27E8, qui est dans le groupe 1 de "[". Redonder "&#x" sur K à la place de "⟩" U27E9, qui est dans le groupe 1 de "]". ibidem
	* Séquences et émojis en Maj + AltGr/Option + AltFr :
		* Faire suivre "&amp;quot;" de la touche U sur la touche E à la place de "😁" U1F601, qui prend la place de "🙏" U1F64F sur la touche O, qui prend la place de "&amp;apos;" sur la touche I, qui prend la place laissée par "&amp;quot;" sur la touche U. ibidem
		* Ajouter "🤣" U1F923, 4ᵉ émoji le plus utilisé du monde, à la place laissée par "‾" U203E. dispocla.cpp [b0c9790](https://github.com/dispoclavier/nouvel-azerty/commit/b0c97906ee69331484dea6f3076a756bcd7ff0b5)
* Sortie multi-caractères : Déboguer pour les compilateurs défectueux qui ont besoin de commentaires de fin de ligne pour lire les séquences de composition (malgré ce qui est [spécifié](https://linux.die.net/man/3/xcompose) sous « File Format »). compose-1.yml [11eab8e](https://github.com/dispoclavier/nouvel-azerty/commit/11eab8eee4d86e79ca9175f4e04c12411fe40c72), [2e4fa01](https://github.com/dispoclavier/nouvel-azerty/commit/2e4fa0154d9a6ee4032d588153d2bfdee8bb3236)
* Composition :
	* Dupliquer "\\"" U0022 par "€" U20AC. compose-1.yml [223b3ec](https://github.com/dispoclavier/nouvel-azerty/commit/223b3ec15f4597cea59eda0d4ef95ec8cc037636)
	* Dupliquer ";" par "§" U00A7. compose-1.yml [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Compléter les séquences de "∧" U2227, "∨" U2228, "⊻" U22BB, "⊼" U22BC, "⊽" U22BD. Restreindre les séquences de "®" U00AE. Diversifier les séquences de "©" U00A9, "℗" U2117, "®" U00AE. compose-1.yml [3f1569e](https://github.com/dispoclavier/nouvel-azerty/commit/3f1569e94ae285d80b3a0a54f397565de36902bc)
	* Simplifier la séquence de "⁒" U2052. compose-1.yml [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Mettre à jour les renvois. compose-1.yml [b40afd1](https://github.com/dispoclavier/nouvel-azerty/commit/b40afd1141823e5f65653ff9a3a753d98ad39f6c), [7f9d628](https://github.com/dispoclavier/nouvel-azerty/commit/7f9d628ed127a3e94d0e1a0558b5f3a0e567600a), [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Simplifier le fichier. compose-1.yml [731afa0](https://github.com/dispoclavier/nouvel-azerty/commit/731afa0d2fa108b55d76a8ecca8308af63399e17)
* Transformations :
	* Groupes des symboles :
		* Prendre en charge "€" U20AC comme caractère de base aux côtés de "\\"" U0022. compose-3.yml [4137c0d](https://github.com/dispoclavier/nouvel-azerty/commit/4137c0dc378711bd7ace334dd555f87619063418)
		* Mettre à jour les symboles de base. ibidem
		* Faire suivre "―" U2015 à la place de "⟨" U27E8, qui prend la place de "⟩" U27E9, qui prend la place laissée par "―" U2015. compose-3.yml [d535c12](https://github.com/dispoclavier/nouvel-azerty/commit/d535c12126bbee9d9fd9cd806b927a097b35e505)
		* Faire suivre "❰" U2770 à la place de "❱" U2771, qui prend la place de "•" U2022, qui prend la place laissée par "❰" U2770. ibidem
		* Faire suivre "❮" U276E à la place de "❯" U276F, qui prend la place de "◦" U25E6, qui prend la place laissée par "❮" U276E. ibidem
		* Faire suivre "❑" U2751 à la place de "❏" U274F, qui prend la place de "⮊" U2B8A, qui prend la place laissée par "❑" U2751. ibidem
		* Regrouper "❒" U2752 à la place de "⟧" U27E7, qui prend la place de "◊" U25CA, qui prend la place de "➢" U27A2, qui est dans accent circonflexe, où se trouve aussi "➣" U27A3. ibidem
		* Regrouper "❐" U2750 à la place de "➲" U27B2, qui prend la place de "⟦" U27E6, qui prend la place de "‪" U202A, qui est en composition. Ajouter "⮈" U2B88 à la place de l’enchâssement droite-à-gauche U202B, qui est en composition. ibidem
		* Faire suivre "ʻ" U02BB à la place de "✅" U2705, qui prend la place de "▻" U25BB, qui n’est pris en charge que dans les versions 1.7.3 et 1.7.4. ibidem
		* Permuter "ʼ" U02BC et "〃" U3003. ibidem
		* Mettre "∅" U2205 à la place de "Ω" U2126, qui prend la place laissée par "ʻ" U02BB. À la place laissée par "∅" U2205, redonder "¶" U00B6, normalement sur touche vive sur la touche du P. ibidem
		* Mettre "⏳" U23F3 à la place de "⊲" U22B2, qui prend la place laissée par "❐" U2750. Mettre "⌛" U231B à la place de "⊳" U22B3, qui prend la place laissée par "❒" U2752. Ajouter "⧖" U29D6 à la place laissée par "⏳" U23F3. Ajouter "⧗" U29D7 à la place laissée par "⌛" U231B. ibidem
		* Permuter "♦" U2666 et "♣" U2663 pour la mnémonique. ibidem
		* Mettre "†" U2020 à la place de "µ" U00B5, qui est normalement sur touche vive et qui prend la place de "∣" U2223, qui est dans macron 1 et dans composition. Mettre "‡" U2021 à la place de "∥" U2225, qui est dans macron 4 et dans composition. Mettre "⹋" U2E4B à la place de "‖" U2016, qui est dans macron 2 et dans composition. compose-3.yml [46bf78c](https://github.com/dispoclavier/nouvel-azerty/commit/46bf78c15f1899121c2b306e72510701f7bbf648), [14f8844](https://github.com/dispoclavier/nouvel-azerty/commit/14f88440592521e180c14ab475af44be966c7620)
		* Mettre "∣" U2223 à la place de "†" U2020, qui est dans tilde 1. Mettre "‖" U2016 à la place de "‡" U2021, qui est dans tilde 2. Mettre "∥" U2225 à la place de "⹋" U2E4B, qui est dans tilde 3, avec "⸶" U2E36 dans tilde 4, "⸸" U2E38 dans tilde 5, et "⸷" U2E37 dans tilde 6. compose-3.yml [c96516e](https://github.com/dispoclavier/nouvel-azerty/commit/c96516ecc88a40c2b6d538b5bda6a1ea3fb626a2), [6367a5a](https://github.com/dispoclavier/nouvel-azerty/commit/6367a5a76e794eeeb24a4dc8bd2ee54e7647368e), [f91879e](https://github.com/dispoclavier/nouvel-azerty/commit/f91879ecf13c591d9bdd4d6d9ed4b9a80af4b58d), compose-2.yml [4fa70b9](https://github.com/dispoclavier/nouvel-azerty/commit/4fa70b903241008b75d894271604ca07ccbfdf42)
		* Permuter "ˑ" U02D1 et "ː" U02D0. compose-3.yml [80fb096](https://github.com/dispoclavier/nouvel-azerty/commit/80fb0969cc0c0b465357b8e6ee9552eca3b21074)
		* Mettre "⤴" U2934 et "⤵" U2935 aux places de "※" U203B et "⌨" U2328, qui prennent les places de "⊲" U22B2 et "⊳" U22B3, qui sont dans composition. Mettre "∖" U2216 à la place laissée par "⤵" U2935. Permuter "∕" U2215 et "▲" U25B2, "⛛" U26DB et "▼" U25BC. Redonder "♮" U266E à la place laissée par "∖" U2216. Redonder "〃" U3003 à la place laissée par "⤴" U2934. compose-3.yml [4eea50a](https://github.com/dispoclavier/nouvel-azerty/commit/4eea50af7ba3c9cf85617669dfcb342b28e373be)
		* Ajouter "∡" U2221 à la place de "⦜" U299C, qui prend la place de "▪" U25AA, qui est dans circonflexe 4. Ajouter "∟" U221F à la place de "‣" U2023, qui est dans circonflexe 6. ibidem
		* Dupliquer "@" par la touche morte grec ou cerclé. Nécessaire depuis la version 1.7.0.) (ibidem
		* Mettre "∟" U221F à la place de "⦜" U299C, qui prend la place de "◊" U25CA, qui prend la place laissée par "∟" U221F. Mettre "∠" U2220 à la place de "⚛" U269B, qui prend la place de "∡" U2221, qui prend la place de "⚓" U2693, qui prend la place de "♿" U267F, qui prend la place laissée par "∠" U2220. Permuter "⛵" U26F5 et "⛷" U26F7. Permuter "⛴" U26F4 et "⚽" U26BD. compose-3.yml [075cf20](https://github.com/dispoclavier/nouvel-azerty/commit/075cf20a74214ad255ffffb38c8c3e029017ffa4)
		* Permuter "⧖" U29D6 et "⧗" U29D7. compose-3.yml [0d80301](https://github.com/dispoclavier/nouvel-azerty/commit/0d803019a6173d4eabbc76a805648e56f0a17bc0)
		* Mettre "∧" U2227 à la place de "¬" U00AC, qui prend la place de "∨" U2228, qui prend la place laissée par "¬" U00AC. compose-3.yml [96c5653](https://github.com/dispoclavier/nouvel-azerty/commit/96c5653869fe9fc3c407623f19a49a8df9ba3d7d)
		* Permuter "⛆" U26C6 et "〰" U3030 pour que la pluie soit dans le même groupe que "☔" U2614. ibidem
		* Mettre "∫" U222B à la place de "〃" U3003, qui est dans le groupe 12 de "€" U20AC et "\\"" U0022 et prend la place de "∬" U222C, qui prend la place de "ˌ" U02CC, qui prend la place de "⚧" U26A7, qui prend la place de "⮽" U2BBD, qui prend la place de "▢" U25A2, qui prend la place laissée par "∫" U222B. Mettre "∭" U222D à la place de "ˈ" U02C8, qui prend la place de "∝" U221D, qui prend la place laissée par "∭" U222D. ibidem et compose-2.yml [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
	* Dupliquer "\\"" U0022 par "€" U20AC. compose-2.yml [cbd46d7](https://github.com/dispoclavier/nouvel-azerty/commit/cbd46d7566a9a70801a536c050e665a6082260c4)
	* Mettre à jour l’ordre des répertoires de touches mortes. compose-2.yml [79bc1ba](https://github.com/dispoclavier/nouvel-azerty/commit/79bc1ba9d80262d0b5564eefae30b4b1e4b4deb9)
	* Mettre à jour les symboles de base. compose-2.yml [6603624](https://github.com/dispoclavier/nouvel-azerty/commit/660362419d1d97088c6da803853a43d9f6b0fef7), [e491173](https://github.com/dispoclavier/nouvel-azerty/commit/e49117376c902d4c21acce6e0ea66def18e54ee0), [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
	* Dupliquer ";" par "§" U00A7. compose-2.yml [e491173](https://github.com/dispoclavier/nouvel-azerty/commit/e49117376c902d4c21acce6e0ea66def18e54ee0)
	* Grec-ou-cerclé : Compléter les séquences de "⊗" U2297. compose-2.yml [4fa70b9](https://github.com/dispoclavier/nouvel-azerty/commit/4fa70b903241008b75d894271604ca07ccbfdf42)
	* Double accent aigu : Dupliquer "\\"" U0022 par "€" U20AC. compose-2.yml [559f988](https://github.com/dispoclavier/nouvel-azerty/commit/559f9880394d3724b67f06ba4e717c6e219817a3)
	* Tourné : Redonder "⁀" U2040, "‿" U203F. Inversé : Déplacer "⁔" U2054 de la parenthèse fermante à la parenthèse ouvrante. Redonder "‿" U203F par la parenthèse fermante. ibidem et compose-3.yml [12dd14a](https://github.com/dispoclavier/nouvel-azerty/commit/12dd14a90dcb04c72845e64dc5fc5e45f1149751)
	* Rond en chef : Redonder "∗" U2217 par "0" et par "4". compose-2.yml [1510bb0](https://github.com/dispoclavier/nouvel-azerty/commit/1510bb04a2e041e24f0862ed64d34c606731bb4f)
	* Accent circonflexe :
		* Redonder "•" U2022 par "1" U0031 à la place de "♤" U2664, "◦" U25E6 par "2" U0032 à la place de "♢" U2662, "▪" U25AA par "4" U0034 à la place de "♡" U2661, "▫" U25AB par "5" U0035 à la place de "♧" U2667, "‣" U2023 par "6" U0036 à la place de "♠" U2660. Ajouter "▹" U25B9 par "7" U0037 à la place de "♦" U2666. Redonder "➢" U27A2 par "9" U0039 à la place de "♣" U2663. Ajouter "➣" U27A3 par "0" U0030. Redonder "′" U2032 par "²" U00B2, "″" U2033 par "³" U00B3. compose-2.yml [6603624](https://github.com/dispoclavier/nouvel-azerty/commit/660362419d1d97088c6da803853a43d9f6b0fef7)
		* Mettre à jour le caractère de base et l’ordre de "♡" U2661, "♧" U2667, "♢" U2662, "♤" U2664, (ibidem)
	* Accent grave : Supprimer "(" et ")". ibidem
	* Tilde :
		* Permuter "⸷" U2E37 et "⸸" U2E38. ibidem
		* Compléter les séquences de "”" U201D et "’" U2019. compose-2.yml [368d4aa](https://github.com/dispoclavier/nouvel-azerty/commit/368d4aa29927567a004b9c1a22fa1175104db332)
	* Barré : Barre courte : Redonder "Ꝙ" UA758, "ꝙ" UA759. compose-2.yml [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
* Commutateur : Variante Breton et français redisposée : Ajouter l’icône « br » manquante. evdev-additions.xml [4d148fe](https://github.com/dispoclavier/nouvel-azerty/commit/4d148fe24cae47953da873f6b3a9997330923b1b)

## 1.7.4 (2024-03-28)

* Composition :
	* Ajouter "☧" U2627. compose-1.yml [9818410](https://github.com/dispoclavier/nouvel-azerty/commit/9818410af3054c84ab44dd700cbee88120c95921)
	* Compléter les séquences de "℀" U2100, "⅍" U214D, "℁" U2101, "℅" U2105, "℆" U2106, "♩" U2669, "♪" U266A, "♫" U266B, "♬" U266C, "♭" U266D, "♮" U266E. Adapter les séquences de "₦" U20A6, "⫓" U2AD3, "⫔" U2AD4, "⫖" U2AD6. ibidem
* Transformations :
	* Groupes des symboles :
		* Remplacer "Ω" U03A9 par "⚘" U2698. compose-3.yml [b532280](https://github.com/dispoclavier/nouvel-azerty/commit/b532280a25cd0ecfa00341d44ae182403b2dda82)
		* Permuter "✈" U2708 et "ª" U00AA. Permuter "⚒" U2692 et "º" U00BA. ibidem
		* Mettre "⹀" U2E40 à la place de "‐" U2010, qui prend la place de "➟" U279F, qui prend la place laissée par "⹀" U2E40. ibidem
		* Permuter "➖" U2796 et "⹀" U2E40. Redonder "∓" U2213 à la place de "➕" U2795, qui prend la place de "+", qui est sur touches vives. compose-3.yml [acc6735](https://github.com/dispoclavier/nouvel-azerty/commit/acc6735b2da465dccd07db81983eb6b01a787704)
	* Crosse ou crochet : Corriger les séquences de "⁕" U2055. compose-2.yml [e9bdab5](https://github.com/dispoclavier/nouvel-azerty/commit/e9bdab524a700ba870f0c12506ebba37bf2cc63e)
* Documentation : Procédure de vérification d’absence de conflits entre touches mortes. compose-1.yml [0112702](https://github.com/dispoclavier/nouvel-azerty/commit/01127020fa74acf1f31feb2b4055f96d26242878)

## 1.7.3 (2024-03-24)

* Composition :
	* Déboguer "℧" U2127, "℥" U2125. compose-1.yml [cf7f487](https://github.com/dispoclavier/nouvel-azerty/commit/cf7f487e4bb31ff85ecd1de94fccac3ccadb320f)
	* Corriger les séquences de "⋊" U22CA. Adapter les séquences de "⨞" U2A1E. ibidem
	* Ajouter "ª" U00AA, "º" U00BA. Limiter les séquences de "₳" U20B3. Corriger les séquences de "⟠" U27E0, "⩜" U2A5C, "⩟" U2A5F, "⩠" U2A60, "⩝" U2A5D, "⩞" U2A5E, "⩚" U2A5A, "⩙" U2A59, "⊝" U229D. Compléter les séquences de "⩢" U2A62, "⩛" U2A5B. ibidem
	* Tirets : Mettre "‑" U2011 à la place de "‒" U2012, qui prend la place de "―" U2015, qui prend la place de "⹀" U2E40, qui prend la place laissée par "‑" U2011. ibidem
	* Redonder "❏" U274F, "❐" U2750, "❑" U2751, "❒" U2752. ibidem
* Transformations :
	* Groupes des symboles :
		* Permuter "⋅" U22C5 et "‧" U2027. Redonder "⋅" U22C5 à la place de "ˑ" U02D1, qui prend la place de "꞉" UA789 sur B10, qui prend la place de "ː" U02D0, qui prend la place de "⊢" U22A2, qui prend la place de "⋌" U22CC, qui est en composition. compose-3.yml [58ba0da](https://github.com/dispoclavier/nouvel-azerty/commit/58ba0da5aee3909c5ed375419708c053a95f1a41)
		* Redonder "−" U2212 à la place de "‐" U2010, qui prend la place de "⊖" U2296, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "+" à la place de "⊕" U2295, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "×" U00D7 à la place de "❖" U2756, qui prend la place de "✂" U2702, qui prend la place de "✖" U2716, qui prend la place de "⊗" U2297, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "÷" U00F7 à la place de "♥" U2665 sur B01, qui prend la place de "❤" U2764, qui prend la place de "‧" U2027 sur la même touche B07, qui devient redondant. ibidem
		* Mettre "✅" U2705 à la place de "✔" U2714, qui prend la place de "✓" U2713, qui prend la place de "✘" U2718, qui prend la place de "⚠" U26A0 sur B01, qui prend la place de "ª" U00AA, qui passe en composition et prend la place de "✈" U2708, qui prend la place de "※" U203B, qui prend la place de "꞉" UA789 sur B09 dans le groupe 11, qui devient redondant. ibidem
		* Mettre "ʻ" U02BB à la place de "º" U00BA, qui passe en composition et prend la place de "⛔" U26D4, qui prend la place de "〰" U3030, qui prend la place de "♠" U2660, qui prend la place de "⛆" U26C6, qui prend la place de "♣" U2663, qui prend la place de "⁛" U205B, qui prend la place de "⊥" U22A5, qui prend la place de "⋊" U22CA, qui est en composition. ibidem
		* Mettre "⭕" U2B55 à la place de "∅" U2205, qui prend la place de "Ω" U2126, qui prend la place laissée par "ʻ" U02BB. ibidem
		* Mettre "❌" U274C à la place de "∗" U2217, qui prend la place de "❎" U274E, qui prend la place de "✴" U2734, qui prend la place de "✳" U2733, qui prend la place de "✨" U2728, qui prend la place laissée par "❌" U274C. ibidem
		* Ajouter "▻" U25BB à la place de "►" U25BA, qui prend la place de "➗" U2797, qui prend la place de "♦" U2666, qui prend la place de "♥" U2665 sur B07 dans le groupe 3, qui devient redondant. ibidem
		* Redonder "⸫" U2E2B à la place de "⊣" U22A3, qui prend la place de "⋋" U22CB, qui est en composition. ibidem
		* Redonder "⸪" U2E2A à la place de "⊤" U22A4, qui prend la place de "⋉" U22C9, qui est en composition. ibidem
		* Redonder "⹀" U2E40 à la place de "➸" U27B8, qui prend la place laissée par "✅" U2705. ibidem
		* Redonder "Ω" U03A9 à la place laissée par "⭕" U2B55. ibidem
	* Exposant : Déboguer "⁄" U2044. compose-2.yml [ecc5889](https://github.com/dispoclavier/nouvel-azerty/commit/ecc5889cb8c2b741878468796abf9479668391d7)
	* Indice : Déboguer "⁄" U2044. ibidem
	* Accent aigu : Supprimer "‐" U2010. ibidem
	* Accent circonflexe : Supprimer "‌" U200C. ibidem
	* Tilde : Supprimer "’" U2019 par "'". ibidem
	* Tréma : Supprimer "‑" U2011. ibidem

## 1.7.2 (2024-03-15)

* Composition : Déboguer "‬" U202C. compose-1.yml [df24b01](https://github.com/dispoclavier/nouvel-azerty/commit/df24b01bd6e9e9220642158a8937810128f68bc9)
* Transformations : Groupes des symboles :
	* Redonder "±" U00B1 dans le groupe 1 de + sur H à la place de "⚠" U26A0, qui prend la place de "∕" U2215, qui prend la place de "▲" U25B2, qui prend la place de "▼" U25BC, qui prend la place de "⛛" U26DB, qui prend la place de "◊" U25CA, qui prend la place de "➢" U27A2, qui prend la place de "❖" U2756, qui prend la place de "∘" U2218, qui est en composition. compose-3.yml [e976bdb](https://github.com/dispoclavier/nouvel-azerty/commit/e976bdbe70e82c57a1df45ffa21b0bb1f6e2299e)
	* Permuter "Ⓜ" U24C2 et "∣" U2223. ibidem
	* Mettre "⛄" U26C4 à la place de "¬" U00AC, qui prend la place de "∖" U2216, qui prend la place de "♮" U266E, qui prend la place de "‬" U202C, qui prend la place laissée par "⛄" U26C4. ibidem
	* Mettre "☃" U2603 à la place de "⛅" U26C5, qui prend la place de "❄" U2744, qui prend la place de "☁" U2601, qui prend la place laissée par "☃" U2603. ibidem
	* Ajouter "☏" U260F à la place de "☎" U260E, qui prend la place de "⌨" U2328, qui prend la place de "❒" U2752, qui prend la place de "❑" U2751, qui prend la place de "⤴" U2934, qui prend la place de "⁜" U205C, qui prend la place de "˖" U02D6, qui est dans cornu. ibidem
	* Redonder "⁞" U205E à la place de "⋯" U22EF, qui prend la place de "꞉" UA789, qui prend la place de "❐" U2750, qui prend la place de "❏" U274F, qui prend la place de "⤵" U2935, qui prend la place de "⏎" U23CE, qui est en composition. ibidem
* Documentation : Touches mortes : Simplifier les identifiants. compose-2.yml [df24b01](https://github.com/dispoclavier/nouvel-azerty/commit/df24b01bd6e9e9220642158a8937810128f68bc9)


## 1.7.1 (2024-03-12)

* Transformations :
	* Groupes des symboles : Mettre "µ" U00B5 à la place de "∣" U2223, qui prend la place de "⌘" U2318, qui prend la place de "◊" U25CA, qui prend la place de "►" U25BA, qui prend la place de "≻" U227B. Redonder "Ω" U2126 à la place de "∅" U2205, qui prend la place de "⛱" U26F1, qui prend la place de "∐" U2210, qui prend la place de "≺" U227A. compose-3.yml [b1e366d](https://github.com/dispoclavier/nouvel-azerty/commit/b1e366d53c5ab67ba91ca5e752b504ca5705cd7f)
	* Exposant :
		* Redonder "”" U201D, "’" U2019. 1.7.2 ; répercuter dans compose-2.yml [66de15c](https://github.com/dispoclavier/nouvel-azerty/commit/66de15cc74d44ea26a3742bd394b71d31345dad3)
		* Redonder "⁄" U2044. compose-2.yml [72ec518](https://github.com/dispoclavier/nouvel-azerty/commit/72ec5183dabcd2be4cb289bd892b04c6f7094c65)
	* Indice : Redonder "⁄" U2044. ibidem
	* Drapeau : Compatibilité. ibidem

## 1.7.0 (2024-03-02)

* Disposition : Redonder la touche morte grec ou cerclé à la place de "@" sur D06. dispocla.cpp [2b62fcd](https://github.com/dispoclavier/nouvel-azerty/commit/2b62fcd03c1403fa8ee37e2accaf5be25c53a034)
* Transformations : Tilde : Redonder les guillemets comme dans Accent aigu. compose-2.yml [b9a8c63](https://github.com/dispoclavier/nouvel-azerty/commit/b9a8c635e1cd079dfd625d7bc1af3f4bc56b16c5), [9d84d8f](https://github.com/dispoclavier/nouvel-azerty/commit/9d84d8f797d0687367d84de63b4c7dfc67191f98)
* Distribution : Ranger les sources de disposition fusionnées par variante dans 9 dossiers. comp.sh [28d932b](https://github.com/dispoclavier/nouvel-azerty/commit/28d932b0f03eb04368e73aa7091596c25c4b909e)
* Documentation : Restaurer l’historique des versions du répertoire des touches mortes. Compose.yml de [c6c939f](https://github.com/dispoclavier/nouvel-azerty/commit/c6c939f1ec1a84dc4a1ec4aaf49df552b887e5dd) à [bebf6f8](https://github.com/dispoclavier/nouvel-azerty/commit/bebf6f8e44270b5623bf4eae95454b8b657497e2)

## 1.6.0 (2024-02-09)

* Composition :
	* Ajouter "℣" U2123, "℟" U211F, "ꭈ" UAB48. compose-1.yml [5de859b](https://github.com/dispoclavier/nouvel-azerty/commit/5de859b516c4eacd3c57c36f6b5da89ceacb0fb3), [bdf672e](https://github.com/dispoclavier/nouvel-azerty/commit/bdf672eed9f5279f37032658b624c993880ddc0b), [66d2d69](https://github.com/dispoclavier/nouvel-azerty/commit/66d2d69a5656bc06cd31c8d0a903e79a12279ffd), [f7b6b07](https://github.com/dispoclavier/nouvel-azerty/commit/f7b6b07e4104bc260d09c4881b76a3df6bd02da1), [37b670f](https://github.com/dispoclavier/nouvel-azerty/commit/37b670fc15f3df846e1f10f1e625a8e6908745ed)
	* Ajouter "℄" U2104. Redonder "℃" U2103, "℉" U2109. Compléter les séquences de "℀" U2100, "℅" U2105, "©" U00A9, "®" U00AE. compose-1.yml [4d57287](https://github.com/dispoclavier/nouvel-azerty/commit/4d57287c33ddf1700da9269c7932bb23d8cf9d91)
	* Changer les séquences de "☚" U261A, "☛" U261B. Ajouter "℈" U2108, "℔" U2114, "⅊" U214A, "℞" U211E, "℥" U2125, "℧" U2127, "⅌" U214C, "⅏" U214F, "℠" U2120, "℡" U2121, "℻" U213B, "Å" U212B, "K" U212A. Redonder "Ω" U2126, "℗" U2117. compose-1.yml [37b670f](https://github.com/dispoclavier/nouvel-azerty/commit/37b670fc15f3df846e1f10f1e625a8e6908745ed), [18f59a5](https://github.com/dispoclavier/nouvel-azerty/commit/18f59a55f4b71aa793716c56dab3199e1fcc71b7)
* Transformations :
	* Groupes des lettres :
		* Groupe 1 : Remplacer "Ǝ" U018E et "ǝ" U01DD par "℣" U2123, "Ɲ" U019D et "ɲ" U0272 par "℟" U211F. compose-3.yml [b97308c](https://github.com/dispoclavier/nouvel-azerty/commit/b97308ccd60a189e7b7eea5bf03900eddfb6eee6), compose-1.yml [920240d](https://github.com/dispoclavier/nouvel-azerty/commit/920240dade55b57e1aec45af08f4b551f2e9a09f), [0a432bf](https://github.com/dispoclavier/nouvel-azerty/commit/0a432bfd6249bca8a93486c86dcfc8f926a61c90)
		* Groupe 4 : Redonder "℣" U2123, "℟" U211F. Supprimer "ꭈ" UAB48. Groupes 4, 5, 11, 12 : Permuter "ɷ" U0277, "ʍ" U028D, "Ꝩ" UA768, "ꝩ" UA769, "Ƿ" U01F7, "ƿ" U01BF, "ꭗ" UAB57, "ꭙ" UAB59, "ʭ" U02AD, "̍" U030D, "̩" U0329, "̽" U033D, "͓" U0353. compose-3.yml [66965ea](https://github.com/dispoclavier/nouvel-azerty/commit/66965ea31611752be983205dffa2414eaf5df751)
		* Groupe 5 : Supprimer le doublon de "ꬷ" UAB37 et cette prise en charge de "ʪ" U02AA. Déplacer "ǁ" U01C1 de H à L. Groupes 1–5 : Incrémenter "Ꜧ" UA726 et "ꜧ" UA727, "Ɦ" UA7AA et "ɦ" U0266, "Ɥ" UA78D et "ɥ" U0265, "Ⱶ" U2C75 et "ⱶ" U2C76. Groupe 12 : Mettre "˓" U02D3 sur E, "˒" U02D2 sur O. Groupe 1 : Regrouper "ʾ" U02BE et "ʿ" U02BF sur K. Redonder "Ɲ" U019D et "ɲ" U0272 sur J, "Ǝ" U018E et "ǝ" U01DD sur H. compose-3.yml [768915e](https://github.com/dispoclavier/nouvel-azerty/commit/768915e180bae47c1947ace1d21016d4296bb28e)
		* Remplacer "ʐ" U0290 par Ⱬ" U2C6B, ⱬ" U2C6C, remplacés par "ʓ" U0293, "ʑ" U0291, remplacés par "Ɀ" U2C7F, "ɀ" U0240, remplacés par "℥" U2125. Groupe 4 de S : Remplacer "ʲ" U02B2 par "℈" U2108. Groupe 12 de E : Redonder "℈" U2108. compose-3.yml [cdb706c](https://github.com/dispoclavier/nouvel-azerty/commit/cdb706c42934ddacd567c6969f6f3d41b59e05f8)
		* Groupe 2 : Remplacer la redondance de "ſ" U017F et "ẛ" U1E9B par "ꬵ" UAB35 et "ʩ" U02A9 du groupe 4, remplacés par "ʾ" U02BE et "͗" U0357 du groupe 5, remplacés par "˒" U02D2 et "̹" U0339 du groupe 11. Groupe 4 : Remplacer cette prise en charge de "ʣ" U02A3 et "ʤ" U02A4 par "ʿ" U02BF et "͑" U0351 du groupe 5, remplacés par "̜" U031C et "˓" U02D3 des groupes 11 et 12. compose-3.yml [59759f4](https://github.com/dispoclavier/nouvel-azerty/commit/59759f4077089ba07a79d3aaf15d367d3f5875fc)
		* Groupe 3 : Redonder "Kʼ" U004B U02BC. Groupe 4 : Redonder "℃" U2103. Groupe 11 : Redonder "℉" U2109, "℄" U2104. compose-3.yml [0e887c3](https://github.com/dispoclavier/nouvel-azerty/commit/0e887c34299ce2ace6443ba9c2cc94092d41ce15)
		* Groupe 12: Remplacer "ŉ" U0149 par "Ꞑ" UA790, "ꞑ" UA791. Redonder "ℹ" U2139, "Ω" U2126. compose-3.yml [121256f](https://github.com/dispoclavier/nouvel-azerty/commit/121256f82fcb134892ecd8d8e5e36f6fcc323d17)
	* Tourné : Ajouter "℺" U213A. compose-2.yml [a551b26](https://github.com/dispoclavier/nouvel-azerty/commit/a551b26f19930eb7f7840fa1c07eb305aabcae60)
	* Accent grave : Ajouter "(", ")" (prévu pour la version 1.5.0). compose-2.yml [0750b87](https://github.com/dispoclavier/nouvel-azerty/commit/0750b87a74978085e2ad0e5d63cf357fd2381ed8)
* Documentation :
	* Disposition : Symboles ASCII en AltGr/Option : Permuter l’accent grave et le guillemet double générique (1.2.0). compose-3.yml [81dbf30](https://github.com/dispoclavier/nouvel-azerty/commit/81dbf306d59a5e7887558d3129c04d5672c8a972), [d316791](https://github.com/dispoclavier/nouvel-azerty/commit/d316791df17e563b6630c66f5f09abc3c375bf7c), [9c79996](https://github.com/dispoclavier/nouvel-azerty/commit/9c7999602653aaf0c848bca9fab09389551b42f3)
	* Transformations : Groupes des lettres : Groupe 11 : "Ꞛ" UA79A, "ꞛ" UA79B, "Ꞝ" UA79C, "ꞝ" UA79D, "Ꞟ" UA79E, "ꞟ" UA79F. compose-3.yml [e5e02cd](https://github.com/dispoclavier/nouvel-azerty/commit/e5e02cde11131e7131b59e3085bf141057b894eb)

## 1.5.0 (2023-12-27)

* Disposition : Permuter les touches mortes tréma sur E05 et accent grave sur E12. dispocla.cpp [51701f8](https://github.com/dispoclavier/nouvel-azerty/commit/51701f8ac1f15c71bd2b013b0fca918242a38a16)
* Transformations : Accent grave : Ajouter "(", ")" (prévu pour la version 1.5.0). compose-2.yml [0750b87](https://github.com/dispoclavier/nouvel-azerty/commit/0750b87a74978085e2ad0e5d63cf357fd2381ed8)

## 1.4.0 (2023-12-06)

* Variantes : Polynésie :
	* Restaurer la touche morte accent grave. dispocla.cpp [dc8c459](https://github.com/dispoclavier/nouvel-azerty/commit/dc8c459efc700caa76344415f461a6d68f29efe6), [66de23c](https://github.com/dispoclavier/nouvel-azerty/commit/66de23c18921158c464c915a8baa7f117e826671)
	* Utiliser la touche E08 (ou E07 sur la variante redisposée) pour la touche morte macron et pour le ʻeta polynésien afin de l’avoir sur touche vive. ibidem
* Transformations : Groupes des symboles : Redonder "―" U2015 et "‑" U2011 par "ʻ" U02BB et la touche morte macron sur E08 ou E07 des variantes pour la Polynésie. compose-2.yml [5506742](https://github.com/dispoclavier/nouvel-azerty/commit/55067425c798e52db60680c8ed445d86917392a2), dispocla.cpp [ff3a66d](https://github.com/dispoclavier/nouvel-azerty/commit/ff3a66d129082374dc9d814fa20b16ae11448ba3)
* Documentation. dispocla.cpp [9959c6c](https://github.com/dispoclavier/nouvel-azerty/commit/9959c6c9ec4961f59085ad5e3c53d83ff7f526b3), [d523e98](https://github.com/dispoclavier/nouvel-azerty/commit/d523e982523ad0b94aba1d74764c2cb4d0756641), [d5f1aef](https://github.com/dispoclavier/nouvel-azerty/commit/d5f1aef6c1cd367d09f4168269386836e259797b), compose-2.yml [98fd57a](https://github.com/dispoclavier/nouvel-azerty/commit/98fd57a526fd6418560a292a53ba2071d375a1c9), compose-3.yml [38b12b0](https://github.com/dispoclavier/nouvel-azerty/commit/38b12b0763755b030210de705fbc34caaa2c236a)

## 1.3.0 (2023-12-03)

* Variantes : Ajouter des variantes redisposées :
	* Breton et français disposition de clavier semi-automatique redisposée. dispocla.cpp [df98b31](https://github.com/dispoclavier/nouvel-azerty/commit/df98b3125d4f39de7e60a5c81333daa32e6063b9), [ef0eba1](https://github.com/dispoclavier/nouvel-azerty/commit/ef0eba1031c37950960ccfe59297cc638b4d485e), compose-1.yml [edd54e1](https://github.com/dispoclavier/nouvel-azerty/commit/edd54e1af53ff129c4ee63050ad0b221e338d88f), [259a61d](https://github.com/dispoclavier/nouvel-azerty/commit/259a61da12da22541050ae6faa2b9c9e10015c3e), evdev-additions.xml [b2317cd](https://github.com/dispoclavier/nouvel-azerty/commit/b2317cdfe18dadd19f5805fb4e6774d5662e3809), dispotypes.c [e6c157b](https://github.com/dispoclavier/nouvel-azerty/commit/e6c157b7bb4a235ee3641af0387dbe9b82c9c390), dispoled.c [69ab89f](https://github.com/dispoclavier/nouvel-azerty/commit/69ab89fbd6f88a1df2111c3e89ff8057b32a8c1e)
	* Polynésie française disposition de clavier semi-automatique redisposée. ibidem
	* Afrique francophone disposition de clavier semi-automatique redisposée. ibidem
* Composition : Adapter les séquences de "⋘" U22D8 et "⋙" U22D9. compose-1.yml [1f22bd3](https://github.com/dispoclavier/nouvel-azerty/commit/1f22bd396686d6c7d6924fbb493590547f6cd172)
* Transformations :
	* Groupes des symboles :
		* Ajouter le trait d’union insécable "‑" U2011 dans le groupe 1 d’égal à la place de "✔" U2714, qui prend la place de "∖" U2216, qui prend la place de "∧" U2227, qui prend la place de "∨" U2228, qui prend la place de "∇" U2207, qui prend la place de "⚠" U26A0 redondé sur D/parenthèse ouvrante. compose-1.yml [595303e](https://github.com/dispoclavier/nouvel-azerty/commit/595303ed3bf46819c8792c155d8df28c2c423bc1), compose-2.yml [f78cf66](https://github.com/dispoclavier/nouvel-azerty/commit/f78cf6656ea32788a3471deba3d7270498b50606), compose-3.yml [b2c8c37](https://github.com/dispoclavier/nouvel-azerty/commit/b2c8c3776afe59e8b00c671c6af07ee6021356f6)
		* Groupe 1 du trait d’union insécable : Remplacer "‐" U2010 par "―" U2015. compose-1.yml [99f965c](https://github.com/dispoclavier/nouvel-azerty/commit/99f965cfe7e879f4cf91c89225c90f5880b3fc6e), compose-2.yml [651e8c0](https://github.com/dispoclavier/nouvel-azerty/commit/651e8c0f403b76f0f556ece375f4217c3fd54ae9), compose-3.yml [fc16dc6](https://github.com/dispoclavier/nouvel-azerty/commit/fc16dc6a06e36e68cfec4272b6c8c845e4afe0e6)
	* Tréma : Redonder "‑" U2011 au lieu de "‐" U2010. compose-2.yml [f78cf66](https://github.com/dispoclavier/nouvel-azerty/commit/f78cf6656ea32788a3471deba3d7270498b50606)
	* Accent aigu : Redonder "‐" U2010. compose-1.yml [7cd3b81](https://github.com/dispoclavier/nouvel-azerty/commit/7cd3b81d5b9a190685497ebecc97d1f8a554093e), [bf3eebe](https://github.com/dispoclavier/nouvel-azerty/commit/bf3eebe3de583f174f23edd62bd46e259c59be14), [87bcf36](https://github.com/dispoclavier/nouvel-azerty/commit/87bcf362d9ed82ac1b7f7a617ce0d501c54e57ae), [compose-2.yml [c93e8bf](https://github.com/dispoclavier/nouvel-azerty/commit/c93e8bf5832e199d1312fc77b37f8f7ae1409902), [4cc2b0f](https://github.com/dispoclavier/nouvel-azerty/commit/4cc2b0f272bf91f2610f3fa6ee869e24366e24d7), [78c6e15](https://github.com/dispoclavier/nouvel-azerty/commit/78c6e155a207c2ed93ba24d440c6945cbea25a0e)
	* Hatchek : Compléter l’accès par triple circonflexe. Supprimer l’accès par aigu & grave. compose-2.yml [979ccce](https://github.com/dispoclavier/nouvel-azerty/commit/979cccee963ac67a30ba4cb8a19feefad7dea1d1)
	* Corriger la sortie de substitution des surrogats hauts. compose-2.yml [c19705f](https://github.com/dispoclavier/nouvel-azerty/commit/c19705f9a7ecf799a3e144e210821f1bb98a6080), [efba5c0](https://github.com/dispoclavier/nouvel-azerty/commit/efba5c099f12af142eca83677f25bc5d9eec75f3)
* Documentation. compose-1.yml [724b285](https://github.com/dispoclavier/nouvel-azerty/commit/724b285d5c8c563ac2952eb9675fea24eeda1c0a), [76158ee](https://github.com/dispoclavier/nouvel-azerty/commit/76158eeef170093d4c4a3c6daa7e584ea2d087b4), [af5ee65](https://github.com/dispoclavier/nouvel-azerty/commit/af5ee65eef301805eb3c4a1a821a805de3f8aa7e), [e0f085c](https://github.com/dispoclavier/nouvel-azerty/commit/e0f085ccd8d0273b8807e260e34763ab1b78a572), compose-2.yml [698ebfc](https://github.com/dispoclavier/nouvel-azerty/commit/698ebfc32c7800fb04acaedd2a7b26aa3ce4d737), [2249134](https://github.com/dispoclavier/nouvel-azerty/commit/2249134782683f48aeb038737e0eb532bb49531a), [507e6aa](https://github.com/dispoclavier/nouvel-azerty/commit/507e6aa9606b2107e931798ab9ddc0c227a55bff), [f91efa7](https://github.com/dispoclavier/nouvel-azerty/commit/f91efa783594295cc0540101e5d43d7a9a9c3205), compose-3.yml [15df2c4](https://github.com/dispoclavier/nouvel-azerty/commit/15df2c48a5fcb07107401aa6e908103bc0f9ace0), dispocla.cpp [5e69dfe](https://github.com/dispoclavier/nouvel-azerty/commit/5e69dfea9bd7f3f3e7f2048702f621b992ed364f), evdev.c [504a113](https://github.com/dispoclavier/nouvel-azerty/commit/504a11346d86f3d0265e6c65aae1371c78eb9f87)

## 1.2.1 (2023-11-27)

* Disposition : Touches d’édition : Déboguer en supprimant la prise en charge dédiée. dispocla.cpp [636715c](https://github.com/dispoclavier/nouvel-azerty/commit/636715cccf34da2a46a448ab5651ae03e31c288c)
* Transformations :
	* Exposant : Redonder "ʼ" U02BC. compose-2.yml [9e82a33](https://github.com/dispoclavier/nouvel-azerty/commit/9e82a33c55b5047c85ac0f36ba2f72568de5b719)
	* Accent aigu : Redonder "ʻ" U02BB. ibidem
	* Accent grave : Redonder "ʻ" U02BB. ibidem
	* Accent circonflexe : Redonder "ʼ" U02BC. ibidem
	* Cédille & accent aigu : Supprimer l’autre sens. ibidem
* Documentation :
	* Mettre à jour l’ordre. compose-2.yml [5ddffe3](https://github.com/dispoclavier/nouvel-azerty/commit/5ddffe388e8be20d81bbd81da861ef6120d53f03)
	* Groupes des symboles. compose-3.yml [276e31b](https://github.com/dispoclavier/nouvel-azerty/commit/276e31bd42001ef8a81ad0b6c447b62fb2f6fee3), [20d4eb1](https://github.com/dispoclavier/nouvel-azerty/commit/20d4eb19bc94f0ffdac5bcf33dda98ce59733b13)
	* Raccourcis divers. compose-2.yml [392c4c2](https://github.com/dispoclavier/nouvel-azerty/commit/392c4c2799eb7a63fe05a90f9c85c5268585de6d), [9d176f4](https://github.com/dispoclavier/nouvel-azerty/commit/9d176f495b6a2bde64327a75a1e8902c233361fc), [cf4a229](https://github.com/dispoclavier/nouvel-azerty/commit/cf4a229f505a364b34d61460662b5f5b2d6816ee)

## 1.2.0 (2023-11-24)

* Disposition : Symboles ASCII : Permuter l’accent grave et le guillemet double générique. Faire suivre les touches mortes accent grave et double accent aigu, les symboles Ohm "Ω" U2126 et seconde "″" U2033, l’émoji "🙏" U1F64F et la séquence "`&quot;`". dispocla.cpp [ae49244](https://github.com/dispoclavier/nouvel-azerty/commit/ae49244e89327c83d7b378263b497c25861a05b1), compose-2.yml [5744ed5](https://github.com/dispoclavier/nouvel-azerty/commit/5744ed5be30e0d99877f40ed568b37ba205164bc)
* Transformations :
	* Groupes des symboles : Mettre "〃" U3003 à la place de "ʻ" U02BB, qui prend la place de "∅" U2205, qui prend la place de "∐" U2210, qui prend la place de "⛱" U26F1, qui prend la place de "〃" U3003. compose-3.yml [3ba78ba](https://github.com/dispoclavier/nouvel-azerty/commit/3ba78baf08ddefad0ee43bc3f43aedcf7605ce2a)
	* Exposant & tourné & crosse : Ajouter "ʵ" U02B5. compose-2.yml [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f)
	* Exposant & tourné & crochet rétroflexe : Supprimer "ʵ" U02B5. Ajouter "𐞧" U107A7, "ᶭ" U1DAD. compose-2.yml [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f), [8352e4c](https://github.com/dispoclavier/nouvel-azerty/commit/8352e4cd28029bd24acaa748f65065b591f4c73f), [92cb3f3](https://github.com/dispoclavier/nouvel-azerty/commit/92cb3f321681ebb80beab86e353b203b6a4070af)
	* Ajouter des caractères morts. compose-2.yml [a1b26c5](https://github.com/dispoclavier/nouvel-azerty/commit/a1b26c57721bf2f38fbbef6e8eb0c1db01d7db14), [94d376f](https://github.com/dispoclavier/nouvel-azerty/commit/94d376f4000d1e3dae85ae1e0bf8c589db4a5b1b), [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f), [92cb3f3](https://github.com/dispoclavier/nouvel-azerty/commit/92cb3f321681ebb80beab86e353b203b6a4070af), [9d33559](https://github.com/dispoclavier/nouvel-azerty/commit/9d33559452dc9e8d114815f10990af47b60af000)
* Documentation :
	* Remplacer “mode numérique” par “mode ASCII”. compose-1.yml [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5), [2848aef](https://github.com/dispoclavier/nouvel-azerty/commit/2848aef41086e87be67b96d8a37b9da650ec2b8c), dispocla.cpp [636715c](https://github.com/dispoclavier/nouvel-azerty/commit/636715cccf34da2a46a448ab5651ae03e31c288c)
	* Réunir la composition nouvelle école. compose-1.yml [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5)
	* Variantes :
		* Expliciter les noms. dispocla.cpp [4f09162](https://github.com/dispoclavier/nouvel-azerty/commit/4f091624c6e6f197f53f67dafef56926edf893b1)
		* Redisposée :
			* Renommer de “Français redisposé disposition de clavier semi-automatique” en “Français France disposition de clavier semi-automatique redisposée”. evdev-additions.xml [a381f32](https://github.com/dispoclavier/nouvel-azerty/commit/a381f325a2b68bda0de3fec47610c99358623d8b), Lisez-moi-svp.txt [d7c5421](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5421fd76df47e17dd215da8ad0c0b237b8e60)
			* Changer l’identifiant de “kbfrFRr” en “kbfrFRsr”. dispocla.cpp [4f09162](https://github.com/dispoclavier/nouvel-azerty/commit/4f091624c6e6f197f53f67dafef56926edf893b1), evdev-additions.xml [a381f32](https://github.com/dispoclavier/nouvel-azerty/commit/a381f325a2b68bda0de3fec47610c99358623d8b), Lisez-moi-svp.txt [d7c5421](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5421fd76df47e17dd215da8ad0c0b237b8e60), et en rattrapage (1.3.0) compose-1.yml [edd54e1](https://github.com/dispoclavier/nouvel-azerty/commit/edd54e1af53ff129c4ee63050ad0b221e338d88f)
	* Transformations : Groupes des lettres. compose-3.yml [54c7301](https://github.com/dispoclavier/nouvel-azerty/commit/54c7301aa6c1fe864a81734e2cfb3f2ee7697082)
	* Divers. compose-1.yml [9f21e47](https://github.com/dispoclavier/nouvel-azerty/commit/9f21e47bda5d15596f3ed503c716ee838210424d), [cbc5a07](https://github.com/dispoclavier/nouvel-azerty/commit/cbc5a07f5f5bb54e16e428bde4b2a60fff084fbb), [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5), [25fc451](https://github.com/dispoclavier/nouvel-azerty/commit/25fc451de7888e27e0122c815803d8c98b7a1355), compose-2.yml [37332a7](https://github.com/dispoclavier/nouvel-azerty/commit/37332a79b4ace3028d142391dcf054040a777a2f)

## 1.1.7 (2023-11-05)

Nouvelle répartition pour rester en dessous de 2 Mo par fichier. compose-1.yml [71a5e2d](https://github.com/dispoclavier/nouvel-azerty/commit/71a5e2d0c91c4359ad2e3d4fb4a35a6e1fbe62b4), compose-2.yml [8a64209](https://github.com/dispoclavier/nouvel-azerty/commit/8a64209bb0c0c63b70661b8b3ba11885af366bc7), compose-3.yml [60d1889](https://github.com/dispoclavier/nouvel-azerty/commit/60d1889ac60af7ce367b377b441a6dd97e97b82d)
* Composition :
	* Déboguer "⫴" U2AF4, "⟧" U27E7, "⋘" U22D8. compose-1.yml [7d54a6f](https://github.com/dispoclavier/nouvel-azerty/commit/7d54a6f5cae08b862526e5b722282aa82980bc72) (aussi [1b197a0](https://github.com/dispoclavier/nouvel-azerty/commit/1b197a039e765268c3b80d609a3a3194c8698e88))
	* Ajouter la termination par espace insécable pour tous les symboles terminés par espace. ibidem
* Transformations : Hatchek > hatchek souscrit : Ajouter "˰" U02F0, "˱" U02F1, "˲" U02F2. compose-2.yml [c267636](https://github.com/dispoclavier/nouvel-azerty/commit/c267636c75deb04aef6efe56f1175dd17269dab9) (aussi [e29ce4d](https://github.com/dispoclavier/nouvel-azerty/commit/e29ce4d2b18f50002cdbaec02b08b6226f2a6f3d))

## 1.1.6 (2023-11-04)

* Transformations :
	* Exposant & crochet rétroflexe & sanglé : Dupliquer "𐞝" U1079D depuis Exposant & crochet rétroflexe & brève. compose-1.yml [18ee048](https://github.com/dispoclavier/nouvel-azerty/commit/18ee0489ab9b4e355702b29b75a3871af9fa458d)
	* Crochet rétroflexe & groupe 4 : Supprimer "ꞎ" UA78E. ibidem
	* Crochet rétroflexe & sanglé : Dupliquer "ꞎ" UA78E depuis Crochet rétroflexe & brève. ibidem
	* Brève > sanglé : Remplacer "‿" U203F par "⏑" U23D1. ibidem
	* Brève > sanglé & crochet palatal : Dupliquer "𝼓" U1DF13 depuis Brève & crochet palatal. ibidem
	* Rayé > raie haute : Ajouter "͆" U0346, "˂" U02C2, "˃" U02C3, "˄" U02C4, "˅" U02C5. ibidem
	* Crochet en chef > glottal : Ajouter "҆" U0486, "᾿" U1FBF. ibidem
	* Macron > ligne souscrite : Déplacer ici depuis Indice > ligne souscrite. ibidem
	* Barré > barre courte, Double barre : Permuter les identifiants et les diacritiques. ibidem
	* Hatchek > hatchek souscrit : Ajouter "˯" U02EF. compose-2.yml [55e43b0](https://github.com/dispoclavier/nouvel-azerty/commit/55e43b09032bedfd58393d985a58a3ee8a0024e0)
	* Cédille > cédille en chef : Ajouter "ʻ" U02BB. ibidem
	* Tréma > tréma souscrit : Ajouter "˸" U02F8. ibidem
	* Virgule souscrite, Virgule souscrite > virgule en chef : Redonder "Ꞻ" UA7BA, "ꞻ" UA7BB, "Ꞽ" UA7BC, "ꞽ" UA7BD, "Ꞿ" UA7BE, "ꞿ" UA7BF. ibidem

## 1.1.5 (2023-11-02)

* Sous-variantes : Verrouillage capitales : Remettre sur la touche traditionnelle par défaut, corriger l’erreur de la v1.1.2. evdev.c [d9a7bc0](https://github.com/dispoclavier/nouvel-azerty/commit/d9a7bc0bb805d0e1b1f736b2f2799f63bf48d56f)
* Composition : Déboguer "⦄" U2984, "⫻" U2AFB. compose-1.yml [3714679](https://github.com/dispoclavier/nouvel-azerty/commit/3714679605da4b54b7c5d0135b54beea2163aea2)
* Transformations :
	* Crochet rétroflexe > crochet palatal : Déboguer "˽" U02FD. ibidem
	* Barré > double barré : Remplacer "̷" U0337 par "⃫" U20EB. compose-1.yml [b8b45a7](https://github.com/dispoclavier/nouvel-azerty/commit/b8b45a79f9065549de0d40fce143ef5df62c6acf) ; associé : compose-2.yml [2d52334](https://github.com/dispoclavier/nouvel-azerty/commit/2d52334a4f816b6c987dff9d786abf5141f7d6a3)
	* Ajouter Courte barre avec "̷" U0337 et "ꜙ" UA719. ibidem
* Transformations :
	* Crosse > bouclé : Ajouter "͚" U035A, "˓" U02D3, "˒" U02D2. compose-1.yml [9f8d263](https://github.com/dispoclavier/nouvel-azerty/commit/9f8d26396908e33a41594afffbfcb88ea958a64e)
	* Crosse > fioriture : Ajouter "͚" U035A, "˓" U02D3, "˒" U02D2. ibidem
	* Crochet rétroflexe > paraphe : Ajouter "͜" U035C, "‿" U203F. ibidem
* Documentation. compose-1.yml [9f8d263](https://github.com/dispoclavier/nouvel-azerty/commit/9f8d26396908e33a41594afffbfcb88ea958a64e), compose-2.yml [b911cae](https://github.com/dispoclavier/nouvel-azerty/commit/b911caebaeeae8c72710626314cf4ed764ba269b)

## 1.1.4 (2023-11-01)

* Transformations :
	* Permuter les séquences avec espace fine insécable et espace insécable pour corriger l’affichage des tableaux. compose-1.yml [6bfb758](https://github.com/dispoclavier/nouvel-azerty/commit/6bfb7585f90d7bb66a4d4639f7c73a437e7f97bd), compose-2.yml [77ca45c](https://github.com/dispoclavier/nouvel-azerty/commit/77ca45c867df4309ca182dae5bdbce9a4ce6d999)
	* Tourné : Remplacer "≀" U2240 par "ⸯ" U2E2F. ibidem
	* Point en chef : Ajouter "˙" U02D9 par espace insécable. ibidem
	* Rond en chef : Ajouter "⸰" U2E30 par ".". ibidem
	* Point souscrit : Ajouter "⸳" U2E33 par espace insécable et espace fine insécable. ibidem
	* Virgule souscrite : Ajouter "⸴" U2E34 par espace insécable et espace fine insécable. ibidem
	* Drapeau :
		* Remplacer "‌" U200C par "⚐" U2690 avec les caractères de base espace ou césure conditionnelle. compose-2.yml [581516e](https://github.com/dispoclavier/nouvel-azerty/commit/581516edbf0de795d92989216ef7900222560427)
		* Ajouter "⚑" U2691 et "🏴" U1F3F4. ibidem
		* Corriger la casse. ibidem
* Transformations :
	* Exposant : Ajouter "‾" U203E. compose-1.yml [f3e6573](https://github.com/dispoclavier/nouvel-azerty/commit/f3e65739016c562854b0644bc9a9d1ac95e049bf)
	* Exposant > suscrit :
		* Remplacer "̎" U030E par "̿" U033F. ibidem
		* Ajouter "﹌" UFE4C, "﹋" UFE4B. ibidem
	* Tourné : Ajouter "ʻ" U02BB. ibidem
	* Tourné > inversé : Ajouter "̕" U0315, "ʼ" U02BC. ibidem
	* Crosse : Ajouter "˽" U02FD. ibidem
	* Crochet rétroflexe : Ajouter "˾" U02FE. ibidem
	* Crochet palatal : Ajouter "˽" U02FD. ibidem
	* Tilde > double tilde médian : Ajouter "\~" U007E pour la cohérence. ibidem
	* Grec-ou-cerclé : Ajouter "ι" U03B9 par espace insécable ou espace fine insécable. ibidem
	* Grec-ou-cerclé > cerclé : Ajouter  "⃝" U20DD, "⚪" U26AA. ibidem
	* Point en chef > ligne verticale en chef : Ajouter "̎" U030E, "ˈ" U02C8. ibidem
	* Brève inversée > brève inversée souscrite : Ajouter "⁔" U2054. ibidem
	* Brève > brève souscrite : Ajouter "‿" U203F. ibidem
	* Rayé > double raie : Ajouter "꞊" UA78A. ibidem
	* Cornu > double cornu : Supprimer "᫉" U1AC9, "᫊" U1ACA. ibidem
	* Crochet en chef : Ajouter "ʾ" U02BE, "ʿ" U02BF. ibidem
	* Réfléchi : Ajouter "ʽ" U02BD. compose-2.yml [5cd31ad](https://github.com/dispoclavier/nouvel-azerty/commit/5cd31ad2cdfa4d1988dc42dd50372a9c5d729cab)
	* Virgule souscrite > virgule en chef : Ajouter "ʼ" U02BC. ibidem

## 1.1.3 (2023-10-31)

* Transformations :
	* Grec-ou-cerclé : Ajouter le iota souscrit avec les caractères de base espace ou césure conditionnelle. compose-1.yml [c54e67a](https://github.com/dispoclavier/nouvel-azerty/commit/c54e67aedb7fa430a9fbf532734412a4b287af4e)
	* Drapeau : Doubler l’antiliant "‌" U200C avec les caractères de base espace ou césure conditionnelle. compose-2.yml [5621bee](https://github.com/dispoclavier/nouvel-azerty/commit/5621bee680e37b31f1752497cf1e6007cdd5bb9d)
* Documentation. compose-1.yml [c54e67a](https://github.com/dispoclavier/nouvel-azerty/commit/c54e67aedb7fa430a9fbf532734412a4b287af4e), [9238b44](https://github.com/dispoclavier/nouvel-azerty/commit/9238b44d970de629389f5b21cb0b8c4011e6233e), compose-2.yml [9905833](https://github.com/dispoclavier/nouvel-azerty/commit/99058337ad8a2b2872b44ae380a6a7258cf07717)

## 1.1.2 (2023-10-29)

* Transformations :
	* Tourné barré groupe 3 : Déboguer "ꭄ" UAB44. compose-1.yml [2d88a4a](https://github.com/dispoclavier/nouvel-azerty/commit/2d88a4a349f9f36fa38520e9e6ccfba219fbaa1a)
* Transformations :
	* Point en chef > ligne verticale en chef : Ajouter le diacritique "̍" U030D. compose-1.yml [fba48cd](https://github.com/dispoclavier/nouvel-azerty/commit/fba48cd1cb74cb3d6806ed17003e67bcb701d418)
	* Virgule souscrite > virgule en chef : Remplacer "̔" U0314 par "̕" U0315. compose-2.yml [f683794](https://github.com/dispoclavier/nouvel-azerty/commit/f683794097e02e2df794f6d179af2b7b93c496b1)
* Sous-variantes :
	* Rajouter les sous-variantes avec Effacement arrière sur Menu sans permutation. evdev.c [668cd26](https://github.com/dispoclavier/nouvel-azerty/commit/668cd264f8cbdac7fb3b09752c7b063ec1a36c75), comp.sh [886a1f2](https://github.com/dispoclavier/nouvel-azerty/commit/886a1f21bda5d9dac6a2ba67459b92efcd95d910)
	* Ajouter des sous-variantes avec VerrCap et touche ISO permutées et avec Effacement arrière sur Menu sans permutation. evdev.c [b57016c](https://github.com/dispoclavier/nouvel-azerty/commit/b57016c6c0d14aef8275f8b2619eac73fef99224), comp.sh [76bca78](https://github.com/dispoclavier/nouvel-azerty/commit/76bca78b35213b2a75efbd42493b3ba5ac47459e)

## 1.1.1 (2023-10-27)

* Transformations : Corriger la répartition des diacritiques combinants. compose-1.yml [c279c4e](https://github.com/dispoclavier/nouvel-azerty/commit/c279c4e671677025e2381d9f92478b9239d6b29c), compose-2.yml [403ceca](https://github.com/dispoclavier/nouvel-azerty/commit/403ceca95b46d3559d6fb1b0f7039c61a0b73fc2)
	* Exposant : Remplacer "̍" U030D par "̅" U0305. ibidem
	* Tourné : Remplacer "̅" U0305 par "̒" U0312. ibidem
	* Réfléchi : Ajouter "̔" U0314. ibidem
* Sources de disposition fusionnées : Limiter les touches sans symboles à AB11 et AE13. evdev.c [fcdee06](https://github.com/dispoclavier/nouvel-azerty/commit/fcdee06e45540fc039bca322aeb581d7206e7a8c)
* Sous-variantes : Permuter correctement la touche d’Effacement arrière. evdev.c [d5068d3](https://github.com/dispoclavier/nouvel-azerty/commit/d5068d3580a84fce5b5e5a8c258e69305fa8c524)

## 1.1.0 (2023-10-24)

* Sous-variantes :
	* Ajouter des sous-variantes avec Effacement arrière sur Menu ou sur Contrôle droite. evdev.c [e62f925](https://github.com/dispoclavier/nouvel-azerty/commit/e62f925935d81418d2642e5adfd4d37debafdc29), [0f8e732](https://github.com/dispoclavier/nouvel-azerty/commit/0f8e7327dcf48e8561580cd0d21ea03a37bdc1df), [cae8105](https://github.com/dispoclavier/nouvel-azerty/commit/cae8105b2e3655b6f959861816cf04325d34b332)
	* Ajouter des sous-variantes avec Effacement arrière sur Menu pour claviers ANSI en AZERTY. ibidem
	* Améliorer les suffixes. ibidem
* Transformations :
	* Crochet palatal : Ajouter le diacritique combinant "̡" U0321. compose-1.yml [57644a5](https://github.com/dispoclavier/nouvel-azerty/commit/57644a5f6bebe6e0e5797df9ef3a9e7260361751)
	* Tourné : Ajouter "ꓭ" UA4ED, "ꓷ" UA4F7, "ꓩ" UA4E9, "ꓠ" UA4E0, "ꓳ" UA4F3, "ꓒ" UA4D2, "ꓤ" UA4E4, "ꓢ" UA4E2, "ꓵ" UA4F5, "ꓫ" UA4EB, "ꓜ" UA4DC. ibidem
	* Inversé :
		* Ajouter "ꓯ" UA4EF, "ꓭ" UA4ED, "ꓛ" UA4DB, "ꓷ" UA4F7, "ꓱ" UA4F1, "ꓞ" UA4DE, "ꓨ" UA4E8, "ꓧ" UA4E7, "ꓲ" UA4F2, "ꓩ" UA4E9, "ꓘ" UA4D8, "ꓶ" UA4F6, "ꓠ" UA4E0, "ꓳ" UA4F3, "ꓒ" UA4D2, "ꓤ" UA4E4, "ꓢ" UA4E2, "ꓕ" UA4D5, "ꓵ" UA4F5, "ꓥ" UA4E5, "ꓫ" UA4EB, "𑾰" U11FB0, "ꓜ" UA4DC. ibidem
		* Supprimer "Ɐ" U2C6F, "ꟷ" UA7F7, "ʁ" U0281. ibidem
	* Tréma : Redonder "Ø" U00D8, "ø" U00F8. compose-2.yml [3068d68](https://github.com/dispoclavier/nouvel-azerty/commit/3068d686bf5ecfc2c7dc153da98f7bd5812c4f3e)
* Documentation. compose-1.yml [57644a5](https://github.com/dispoclavier/nouvel-azerty/commit/57644a5f6bebe6e0e5797df9ef3a9e7260361751), [40b9b8f](https://github.com/dispoclavier/nouvel-azerty/commit/40b9b8fef20fa0c0d615fb68d3433994d2f90442), compose-2.yml [419310d](https://github.com/dispoclavier/nouvel-azerty/commit/419310d3cc5aefaf16584f1c3bee10677f94ff57)

## 1.0.14 (2023-09-29)

* Sous-variantes : Effacement arrière : Remettre sur la touche traditionnelle. evdev.c [375b83a](https://github.com/dispoclavier/nouvel-azerty/commit/375b83a11353f6135d39b65a2eca085400de34ee), annule [0559e8f](https://github.com/dispoclavier/nouvel-azerty/commit/0559e8ff5b8b34ce91f775624f6293e0a8f98973)
* Documentation : Mettre en sourdine la prise en charge de ChromeOS.

## 1.0.13 (2023-09-27)

* Composition :
	* Déboguer "ſ" U017F, "ȸ" U0238, "₳" U20B3, "❜" U275C. "⸺" U2E3A, "⸻" U2E3B. compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Déboguer "↉" U2189. compose-1.yml [dc23892](https://github.com/dispoclavier/nouvel-azerty/commit/dc23892ccbd2b0fd6e51daf7cf1bca44cd4095c2)
	* Corriger "○" U25CB, "●" U25CF, "◑" U25D1, "◔" U25D4, "◕" U25D5, "◴" U25F4, "◵" U25F5, "◶" U25F6, "◷" U25F7. ibidem
	* Adapter "⇉" U21C9, "⇶" U21F6, "≅" U2245, "≆" U2246, "⤐" U2910, "⤳" U2933, "⥱" U2971. "⧇" U29C7, "⨣" U2A23, "⨺" U2A3A, "⩰" U2A70, "⫐" U2AD0, "⫒" U2AD2. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0)
	* Supprimer "⁨" U2068 par « ¦fsi », "₫" U20AB par « ¦D= » (maintenu par « ¦d= »), "⋒" U22D2 par « ¦dblcap », "⋓" U22D3 par « ¦dblcup ». ibidem
	* Supprimer "¦" U00A6 par « ¦|: » et par « ¦:| ». compose-1.yml [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df)
	* Déboguer "⊼" U22BC, "⍽" U237D. compose-1.yml [c8eb228](https://github.com/dispoclavier/nouvel-azerty/commit/c8eb2280b056d964ad08ef28681c19487db958ad)
	* Adapter "⇭" U21ED, "⊼" U22BC, "♠" U2660, "⟤" U27E4, "⪤" U2AA4, "⪥" U2AA5, "⭄" U2B44. ibidem
	* Supprimer "♭" U266D par « ¦-# », "♯" U266F par « ¦+# ». ibidem
	* Déboguer "♥" U2665, "ꝴ" UA774. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8), [5975c24](https://github.com/dispoclavier/nouvel-azerty/commit/5975c24f4c36c04838752189b746bc9b0843f3d6)
	* Adapter "♧" U2667. ibidem
	* Déboguer "ꝴ" UA774. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
	* Adapter "⪛" U2A9B, "⪜" U2A9C, "⫍" U2ACD, "⫎" U2ACE. ibidem
	* Supprimer " " U00A0 par « ¦␣␣ », "␣" U2423 par « ¦␣⍽ », " " U202F par « ¦␣ ». à cause de conflits. ibidem
	* Adapter "≎" U224E, "⨧" U2A27. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
	* Supprimer "‭" U202D par « ¦o> », U202E par « ¦o< », "🄯" U1F12F par « ¦%oc » (maintenu par « ¦%OC »). compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
	* Supprimer la termination par espace pour les séquences les plus longues. compose-1.yml [be9366c](https://github.com/dispoclavier/nouvel-azerty/commit/be9366ce76362789212a21f5df80d4856c0c9b5a)
* Transformations : Supprimer l’affichage des caractères morts. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b), compose-2.yml [eb82120](https://github.com/dispoclavier/nouvel-azerty/commit/eb82120550714a3344f22305821e6a409b62e891)
	* Groupes des symboles :
		* Supprimer "" U000B, y déplacer "▢" U25A2. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Déredonder "□" U25A1 et "■" U25A0, y redonder "☐" U2610, "☑" U2611, "☒" U2612. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Déboguer "ʼ" U02BC par « ¦#' », "∼" U223C par « ¦#~ », "ˑ" U02D1 par « ¦#: », "ʻ" U02BB par « ¦#` », "✘" U2718 par « ¦#< ». compose-1.yml [dc0a154](https://github.com/dispoclavier/nouvel-azerty/commit/dc0a15485cc60e631a9f03e515c6a5aca5bc3218), compose-2.yml [e3af08f](https://github.com/dispoclavier/nouvel-azerty/commit/e3af08fbc8f2415e9661b14eab326e074f2269d1)
		* Supprimer les accès rapides par touche morte diacritique. ibidem
	* Exposant :
		* Ajouter "᫈" U1AC8. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Déboguer "⁺" U207A, "⁻" U207B, "⁾" U207E. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Tourné : Déboguer "ᴑ" U1D11.
	* Réfléchi :
		* Supprimer "∽" U223D et les "❶" U2776 à "❿" U277F redondés. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Déplacer ici "∖" U2216, "⟍" U27CD, "⧵" U29F5. "⧹" U29F9, (ibidem)
	* Tilde :
		* Déboguer "≃" U2243, "≈" U2248. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "̰" U0330, "̴" U0334. ibidem
	* Grec-ou-cerclé :
		* Déboguer "⊖" U2296. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "❶" U2776 à "❿" U277F. ibidem
	* Accent aigu : Adapter "˶" U02F6. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Brève inversée :
		* Déboguer "˓" U02D3, "͡" U0361. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Supprimer "˒" U02D2. ibidem
		* Déboguer "͡" U0361. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
		* Adapter "᷼" U1DFC. ibidem
	* Brève :
		* Déboguer "˒" U02D2. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Supprimer "˓" U02D3. ibidem
		* Adapter "͝" U035D, "͜" U035C. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
	* Rayé:
		* Déboguer "⁅" U2045, "⁆" U2046, "ꜻ" UA73B, "ꞓ" UA793. compose-1.yml [c8eb228](https://github.com/dispoclavier/nouvel-azerty/commit/c8eb2280b056d964ad08ef28681c19487db958ad)
		* Supprimer "⊼" U22BC dans le groupe 0. ibidem
		* Déboguer "⁆" U2046.
	* Cornu/cranté/cramponné :
		* Supprimer "̟" U031F, "᫈" U1AC8. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Déboguer "↓" U2193.
	* Indice : Déboguer "͔" U0354, "͕" U0355, "₋" U208B, "₎" U208E.
	* Ogonek : Déboguer "ǫ" U01EB. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Macron : Déboguer "ƃ" U0183. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Barré :
		* Supprimer "∤" U2224 et "≁" U2241 dans le groupe 0. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
		* Déplacer "≠" U2260, "≮" U226E et "≯" U226F dans le groupe 1. ibidem
		* Supprimer les flèches émojis redondées. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Déplacer ici "⁄" U2044. "∕" U2215, "⟋" U27CB, "⧸" U29F8, (ibidem)
	* Rond en chef : Déboguer "∮" U222E. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Accent circonflexe :
		* Déboguer "❛" U275B. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Supprimer "‌" U200C par ".". ibidem
	* Hatchek : Déboguer "̬" U032C. ibidem
	* Hatchek : Déboguer "₀" U2080. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Drapeau : Déboguer "⹀" U2E40. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Accent grave :
		* Déboguer "˴" U02F4. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "˵" U02F5. ibidem
	* Tréma : Supprimer "≤" U2264."≥" U2265, "⊆" U2286. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Améliorer le rendu des surrogats hauts sous les systèmes ne les utilisant pas. compose-1.yml [fb60dfb](https://github.com/dispoclavier/nouvel-azerty/commit/fb60dfb6edac409a1309a97cdc0f54cebc0f5862), compose-2.yml [80d347c](https://github.com/dispoclavier/nouvel-azerty/commit/80d347cf92bd6913981506e7f2879603921258e9)
* Documentation : Ajouter des caractères morts. compose-1.yml [be9366c](https://github.com/dispoclavier/nouvel-azerty/commit/be9366ce76362789212a21f5df80d4856c0c9b5a)

## 1.0.12 (2023-09-23)

* Composition :
	* Déboguer "¢" U00A2. compose-1.yml [43ee671](https://github.com/dispoclavier/nouvel-azerty/commit/43ee671a295299b8d2c6dea90cf3bd7aa5c59a4f), compose-2.yml [addb73e](https://github.com/dispoclavier/nouvel-azerty/commit/addb73ef888be119bbfa9063147a81b1a78f0d8d)
	* Déboguer "⟮" U27EE, "⟯" U27EF, "‬" U202C, "≛" U225B, "⋊" U22CA, "◁" U25C1, "⟜" U27DC, "⦧" U29A7. ibidem
* Transformations :
	* Exposant : Déboguer "̽" U033D. ibidem
	* Grec-ou-cerclé : Supprimer l’accord rayé-crochet rétroflexe. ibidem
	* Groupe : Déboguer les caractères morts "①" U2460 à "⑫" U246B. ibidem
	* Point souscrit : Déboguer "̍" U030D. ibidem
	* Tréma : Supprimer "‖" U2016 par "|". ibidem

## 1.0.11 (2023-09-19)

* Transformations :
	* Double accent aigu : Redonder "⓵" U24F5 à "⓾" U24FE. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Réfléchi : Redonder "❶" U2776 à "❿" U277F. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Brève inversée : Déboguer "͡" U0361. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Brève inversée souscrite : Ajouter "᷼" U1DFC. ibidem
	* Brève : Adapter "͝" U035D. ibidem
	* Brève souscrite : Adapter "͜" U035C. ibidem
	* Rayé : Corriger les séquences avec chiffre du pavé numérique. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Cornu/cranté/cramponné : Redonder "←" U2190 à "↙" U2199. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Cornu/cranté/cramponné : Corriger les séquences avec chiffre du pavé numérique. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Ogonek : Redonder "➀" U2780 à "➉" U2789. ibidem
	* Crochet en chef : Redonder "➊" U278A à "➓" U2793. ibidem
	* Macron : Redonder "⫾" U2AFE, "∣" U2223, "‖" U2016, "⦀" U2980, "∥" U2225, "¦" U00A6, "⫴" U2AF4, "⫿" U2AFF, "⏸" U23F8, "⫼" U2AFC. ibidem
	* Barré : Redonder les émojis flèches "↕" U2195, "↙" U2199, "⬇" U2B07, "↘" U2198, "⬅" U2B05, "↔" U2194, "➡" U27A1, "↖" U2196, "⬆" U2B06, "↗" U2197. ibidem
	* Rond en chef : Corriger les séquences avec chiffre du pavé numérique. ibidem
	* Accent circonflexe : Redonder "❤" U2764 et "♠" U2660 à "♧" U2667. ibidem
	* Drapeau : Redonder "⇐" U21D0 à "⇙" U21D9. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Cédille : Ajouter "⒈" U2488 à "⒑" U2491. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Virgule souscrite : Ajouter "⒒" U2492 à "⒛" U249B. ibidem
* Documentation : Corriger et déployer l’information sur la configuration de la disposition de clavier de login. dispocla.cpp [66f0650](https://github.com/dispoclavier/nouvel-azerty/commit/66f065004e61d650dac7481400a1054cda27d99b), [7e12e97](https://github.com/dispoclavier/nouvel-azerty/commit/7e12e9739dfc10dd36b65350a1396a8d4bf58808) ; [7e12e97](https://github.com/dispoclavier/nouvel-azerty/commit/7e12e9739dfc10dd36b65350a1396a8d4bf58808) (1.7.1)

## 1.0.10 (2023-09-07)

* Transformations : Groupes des symboles :
	* Ajouter "―" U2015 dans le groupe 1 du tiret bas. compose-1.yml [dab5b38](https://github.com/dispoclavier/nouvel-azerty/commit/dab5b38dfd2792fc739926bbcb7b00682b123de0), [05e88f5](https://github.com/dispoclavier/nouvel-azerty/commit/05e88f5ba6f33b0cbad3d0a80f906a626e928f53), compose-2.yml [585d0de](https://github.com/dispoclavier/nouvel-azerty/commit/585d0dee67043d97c4ef7b23f8afdb375bacc95a)
	* Supprimer les séparateurs de ligne " " U2028 et de paragraphe " " U2029. ibidem
	* Déplacer "➢" U27A2, "➲" U27B2, "▪" U25AA, "‣" U2023, "◦" U25E6, "•" U2022, "❖" U2756, "⮊" U2B8A, "¦" U00A6, "⛰" U26F0, "⏯" U23EF, "✅" U2705, "⛛" U26DB, "⌘" U2318 l’un à la place de l’autre. ibidem
	* Supprimer "±" U00B1, "∓" U2213, "₊" U208A, "₋" U208B. ibidem
	* Déplacer "˖" U02D6. ibidem
	* Ajouter "✚" U271A, "✙" U2719, "✜" U271C, "➸" U27B8, "➟" U279F. ibidem
* Documentation. ibidem, dispocla.cpp [e2a5f4a](https://github.com/dispoclavier/nouvel-azerty/commit/e2a5f4a7c50836b19c106d1013eac6ced86d34a7)

## 1.0.9 (2023-08-31)

* Disposition :
	* Redonder "§" U00A7 sur Maj + AltFr + S. Déplacer "😒" U1F612 de là sur AltGr + AltFr + B07 en mode français, "💙" U1F499 de là sur Maj + AltGr + AltFr + B07 en mode français. dispocla.cpp [a7fc71a](https://github.com/dispoclavier/nouvel-azerty/commit/a7fc71a1d1437f2fc70b6892acac377c9f1f6af3), [93162ea](https://github.com/dispoclavier/nouvel-azerty/commit/93162ea09f509de0d3fc4bb9978ad31c4bf924a6)
	* Ajouter l’antiliant "‌" U200C (seulement par touche morte jusqu’alors) sur Maj + AltFr + X. Déplacer le deux-points isolé redondé de là sur Maj + AltFr + W, "😢" U1F622 de là sur Maj + AltGr + AltFr + W, "😭" U1F62D de là sur AltGr + AltFr + B08 en mode français, "📢" U1F4E2 de là sur Maj + AltGr + AltFr + B08 en mode numérique. Y supprimer "📣" U1F4E3 (reste en mode français). dispocla.cpp [2cfd78d](https://github.com/dispoclavier/nouvel-azerty/commit/2cfd78d8032af18c8cd8b5cb62da647a4b034d11)
	* Redonder "⁄" U2044 sur Maj + AltFr + Q. Déplacer "😐" U1F610 de là sur Maj + AltGr + AltFr + Q. Y supprimer "😑" U1F611. ibidem
* Transformations :
	* Tréma : Ajouter "‐" U2010, "⸺" U2E3A et "⸻" U2E3B. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)
	* Groupe :
		* Ajouter "⸺" U2E3A et "⸻" U2E3B. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)
		* Déboguer "⸺" U2E3A et "⸻" U2E3B. compose-1.yml [c6f07b4](https://github.com/dispoclavier/nouvel-azerty/commit/c6f07b4569493d0b61077b5dc26084abcf28b3d5), [30057ba](https://github.com/dispoclavier/nouvel-azerty/commit/30057baa78f59f138c37354dae50055d0300e6e3), [ac69cd2](https://github.com/dispoclavier/nouvel-azerty/commit/ac69cd2e83e76df89d7727dbced63cddf23ac077)
		* Ajouter les jeux de flèches "⭰" U2B70.."⭹" U2B79 avec "⭾" U2B7E et "⭿" U2B7F, "🡠" U1F860.."🡧" U1F867 et "🢀" U1F880.."🢇" U1F887. compose-1.yml [910f538](https://github.com/dispoclavier/nouvel-azerty/commit/910f53879f91627ebb33def3cf7b4127b2da6647)
	* Déboguer les surrogats hauts. compose-2.yml [02ef351](https://github.com/dispoclavier/nouvel-azerty/commit/02ef3514ec2ccfb4efff8070cc1dbf58d4e4439f)
* Documentation : Corriger les commentaires (aussi pour les tableaux), équilibrer le contenu de la sélectrice de groupe. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), [c6f07b4](https://github.com/dispoclavier/nouvel-azerty/commit/c6f07b4569493d0b61077b5dc26084abcf28b3d5), [30057ba](https://github.com/dispoclavier/nouvel-azerty/commit/30057baa78f59f138c37354dae50055d0300e6e3), [ac69cd2](https://github.com/dispoclavier/nouvel-azerty/commit/ac69cd2e83e76df89d7727dbced63cddf23ac077), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)

## 1.0.8 (2023-08-27)

* Transformations :
	* Supprimer la prise en charge du point d’interrogation comme caractère de base pour la saisie des guillemets apostrophes dans leurs touches mortes. compose-1.yml [d73a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/d73a2e877787e841b733fedaf9c1de5cd1b44ebc), compose-2.yml [beaf6c5](https://github.com/dispoclavier/nouvel-azerty/commit/beaf6c58d307920314aad8768a409f25937161b3)
	* Tourné : Déboguer "⸸" U2E38. compose-1.yml [80a6a10](https://github.com/dispoclavier/nouvel-azerty/commit/80a6a10be101dd59b093ba250fdb18a6e6465e3e)
	* Grec-ou-cerclé : Compléter les séquences. compose-1.yml [fc72f73](https://github.com/dispoclavier/nouvel-azerty/commit/fc72f73bb3683afa7e5984eb8181272e200b2ea5)
	* Crochet en chef : Ajouter  "⃣" U20E3 en symétrie avec l’ogonek. compose-1.yml [57a3afb](https://github.com/dispoclavier/nouvel-azerty/commit/57a3afb33bdde161de0c0afd8fad558a65646053)
	* Barré : Redonder plus de lettres rayées dans les lacunes. compose-1.yml [8908dae](https://github.com/dispoclavier/nouvel-azerty/commit/8908daec75443b66846db6eec7c2d468476ad438)
	* Accent grave : Déboguer "‛" U201B. compose-1.yml [76eb4ff](https://github.com/dispoclavier/nouvel-azerty/commit/76eb4ffc3965b091d5ae5100d810ba02377efcc5)
	* Accent grave > double accent grave : Ajouter "⹂" U2E42. compose-1.yml [fc72f73](https://github.com/dispoclavier/nouvel-azerty/commit/fc72f73bb3683afa7e5984eb8181272e200b2ea5)
	* Tréma + accent grave : Ajouter "⹂" U2E42. compose-1.yml [462dd44](https://github.com/dispoclavier/nouvel-azerty/commit/462dd44d86069fdf2a9789d6eb7a4968a9f805c2), compose-2.yml [5b46c26](https://github.com/dispoclavier/nouvel-azerty/commit/5b46c2650afa1f96474fc61b56ef15755b37e991)
* Documentation :
	* Ranger guillemets et raccourcis. compose-1.yml [d73a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/d73a2e877787e841b733fedaf9c1de5cd1b44ebc), compose-2.yml [beaf6c5](https://github.com/dispoclavier/nouvel-azerty/commit/beaf6c58d307920314aad8768a409f25937161b3)
	* Corriger l’ordre des caractères de base. compose-1.yml [462dd44](https://github.com/dispoclavier/nouvel-azerty/commit/462dd44d86069fdf2a9789d6eb7a4968a9f805c2), compose-2.yml [5b46c26](https://github.com/dispoclavier/nouvel-azerty/commit/5b46c2650afa1f96474fc61b56ef15755b37e991)
	* Transformations : Accent aigu + tréma, Cornu/cranté/cramponné : Supprimer 14 doublons. compose-1.yml [48f9e00](https://github.com/dispoclavier/nouvel-azerty/commit/48f9e00d106648f5e9167a22587ed2520fcfe1d0)

## 1.0.7 (2023-08-19)

* Composition :
	* Déboguer la saisie de "⎋" U238B. compose-1.yml [5d3f7a6](https://github.com/dispoclavier/nouvel-azerty/commit/5d3f7a618c77f2e01d23def1d93efeac0722a7ec)
	* Ajouter le caractère de "▮" U25AE (openrectbullet). compose-1.yml [c1d9ec1](https://github.com/dispoclavier/nouvel-azerty/commit/c1d9ec15431e67f09f93d1b81f52ffa866207b7c)
	* Ajouter les contrôles bidirectionnels manquants. compose-1.yml [b253e1f](https://github.com/dispoclavier/nouvel-azerty/commit/b253e1f1a02f88667875ac9ee50832f1150c4005)
	* Ajouter la séquence `en_US.UTF-8/Compose`. ibidem
* Transformations : Point souscrit : Alerter sur la confusion des glyphes entre "⸪" U2E2A, "⸫" U2E2B, "⸬" U2E2C. compose-2.yml [1782bca](https://github.com/dispoclavier/nouvel-azerty/commit/1782bcaa2011deaa6f039302de3b2fa4f4b518c9)
* Personnalisation :
	* Simplifier le code de la barre d’espace. dispocla.cpp [4c4a106](https://github.com/dispoclavier/nouvel-azerty/commit/4c4a106ff4921c1adae901f0e5e3b6e54a076c47), dispotypes.c [763d8b0](https://github.com/dispoclavier/nouvel-azerty/commit/763d8b0dc11221c335c1375e59f3f28960901cee)
	* Simplifier le code des touches B07..B10. dispocla.cpp [84d81db](https://github.com/dispoclavier/nouvel-azerty/commit/84d81dbf7fd34ac78fbab69db294cbd344e4018f), [08a425e](https://github.com/dispoclavier/nouvel-azerty/commit/08a425e4646dda045406b199198c6484b9d4a3ed), dispotypes.c [5acd8f8](https://github.com/dispoclavier/nouvel-azerty/commit/5acd8f8bdaaca2543f1a07b65954f3490d04b4e6), [074154a](https://github.com/dispoclavier/nouvel-azerty/commit/074154a4411c635d4d7f0eabe53ac3d412766e84), [3537120](https://github.com/dispoclavier/nouvel-azerty/commit/3537120e6583430f167af227d775ff835dac995a), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0)
	* Simplifier le code des touches B01..B06, C01..D12. dispocla.cpp [9485620](https://github.com/dispoclavier/nouvel-azerty/commit/9485620a726089ad6268f93cb6bbf2e315d3af7a), [6198799](https://github.com/dispoclavier/nouvel-azerty/commit/6198799c997d10faaf65eedac93ca94c7a5b1b13), [907ff0e](https://github.com/dispoclavier/nouvel-azerty/commit/907ff0e6517603c96667415223bdde3d2b33802c), dispotypes.c [1246e6d](https://github.com/dispoclavier/nouvel-azerty/commit/1246e6d4cbb109329649f9740a2a22131e0054c0), [89f1d98](https://github.com/dispoclavier/nouvel-azerty/commit/89f1d9823390ef2b6548e234b410308b07eb36f5), [cb5ab2a](https://github.com/dispoclavier/nouvel-azerty/commit/cb5ab2af0e965736278c55d6d72b0751c4b4802f), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0)
* Variantes :
	* Supprimer provisoirement les 2 variantes pour le Canada et la variante pour la Suisse pour faciliter la maintenance. dispocla.cpp [bd73f72](https://github.com/dispoclavier/nouvel-azerty/commit/bd73f72760988046ca1c9fcdaeba0ff59e577408)
	* Supprimer définitivement les 3 variantes hybrides. dispocla.cpp [31919ac](https://github.com/dispoclavier/nouvel-azerty/commit/31919ac3fa37cfb3114762809c6ecd39f0f0d3b3)
* Sous-variantes : Effacement arrière : Déplacer sur Windows droite par erreur. evdev.c [0559e8f](https://github.com/dispoclavier/nouvel-azerty/commit/0559e8ff5b8b34ce91f775624f6293e0a8f98973)

## 1.0.6 (2023-08-15)

* Composition : Compléter les séquences de "♥" U2665. compose-1.yml [26166c2](https://github.com/dispoclavier/nouvel-azerty/commit/26166c2b5740016b4265cce3db5e80aa7b130e49)
* Transformations :
	* Accent circonflexe : Désactiver les chiffres en exposant. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
	* Hatchek : Ajouter l’équivalent en composition des chiffres en indice. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
	* Point souscrit : Ajouter ces ponctuations et les compléter. compose-2.yml [310cbde](https://github.com/dispoclavier/nouvel-azerty/commit/310cbde97cd94aecaae1d39d8b8936cafd001f5b)
	* Tréma :
		* Ajouter les chiffres en exposant. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
		* Supprimer les ponctuations à base de chiffres. compose-2.yml [310cbde](https://github.com/dispoclavier/nouvel-azerty/commit/310cbde97cd94aecaae1d39d8b8936cafd001f5b)
		* Supprimer "≔" U2254, "⹀" U2E40. compose-2.yml [c231922](https://github.com/dispoclavier/nouvel-azerty/commit/c231922e1e83a7c3073496fdf7ba50a0cb5c4bce)
	* Ajouter l’équivalent en composition partout où il manquait. Supprimer ou déplacer les séquences en conflit. compose-1.yml [45a1a5d](https://github.com/dispoclavier/nouvel-azerty/commit/45a1a5d2d0fc4b2efeaf3b8bd5d1cf6618bb015c), compose-2.yml [8a8db25](https://github.com/dispoclavier/nouvel-azerty/commit/8a8db25f6c2f20fc141dbd946d3a8059406f6bdc)
* Prendre en charge le pavé numérique dans les séquences de composition et de touches mortes. compose-1.yml [a45dd68](https://github.com/dispoclavier/nouvel-azerty/commit/a45dd684b7fe473a1a5ccd9a9c983691bf9970e3), compose-2.yml [4e15ea0](https://github.com/dispoclavier/nouvel-azerty/commit/4e15ea0ed390df4b30d15cf36c9912c832043989)

## 1.0.5 (2023-08-11)

* Composition :
	* Corriger les séquences de "⋶" U22F6, "⋷" U22F7, "⋽" U22FD, "⋾" U22FE. compose-1.yml [4bd82a7](https://github.com/dispoclavier/nouvel-azerty/commit/4bd82a7cba326cca12e43042fb9977488d522d00)
	* Résoudre les conflits de "Ƨ" U01A7 à "ƅ" U0185 avec "˩" U02E9 à "˥" U02E5. compose-1.yml [57c4a09](https://github.com/dispoclavier/nouvel-azerty/commit/57c4a09e0775f80f8c377131c1d3e928e27808a4)
	* Compléter les séquences de "˩" U02E9 à "˥" U02E5. ibidem
	* Résoudre le conflit de "🅭" U1F16D avec "©" U00A9. ibidem
	* Compléter les séquences de "🅯" U1F16F. compose-1.yml [4dab06f](https://github.com/dispoclavier/nouvel-azerty/commit/4dab06f19342b00324d8a92aa1fba4348e31169c)
	* Compléter les séquences de "✀" U2700 à "✄" U2704. ibidem
	* Corriger la séquence de "♥️" U2665. compose-1.yml [b9922dd](https://github.com/dispoclavier/nouvel-azerty/commit/b9922dd39253485c707e4047eb088987e505fea4)
	* Ôter le sélecteur de variante style émoji de la sortie de "♥" U2665, "⚡" U26A1 et "✴" U2734. compose-1.yml [13eefac](https://github.com/dispoclavier/nouvel-azerty/commit/13eefacd48cf9e73fa36cde0d6e64ce5e32ff667), compose-2.yml [5c9eec9](https://github.com/dispoclavier/nouvel-azerty/commit/5c9eec960f100518f62b3c62e2a094473719fae1), [48372c5](https://github.com/dispoclavier/nouvel-azerty/commit/48372c506def69f974704d75084bcbdf6f3163bb)
	* Corriger les séquences de "‖" U2016, "⃛" U20DB, "⃜" U20DC, "⇇" U21C7, "⇇" U21C7, "⇈" U21C8, "⇉" U21C9, "⇊" U21CA, "⇶" U21F6, "√" U221A, "∛" U221B, "∜" U221C, "∬" U222C, "∭" U222D, "∯" U222F, "∰" U2230, "⋐" U22D0, "⋑" U22D1, "⋒" U22D2, "⋓" U22D3, "♠" U2660, "♡" U2661, "⟁" U27C1, "⦀" U2980, "⧈" U29C8, "⧉" U29C9, "⧻" U29FB, "⨌" U2A0C, "⩎" U2A4E, "⩏" U2A4F, "⩓" U2A53, "⩔" U2A54, "⪡" U2AA1, "⪢" U2AA2, "⪣" U2AA3, "⫷" U2AF7, "⫸" U2AF8, "⬱" U2B31. compose-1.yml [0ef0194](https://github.com/dispoclavier/nouvel-azerty/commit/0ef019419172a2b22b343a75241cda914335eca4)
	* Compléter les séquences de "★" U2605, "☆" U2606, "♀" U2640, "♂" U2642. ibidem
	* Corriger les séquences de  "⃮" U20EE, "⃯" U20EF, "ℏ" U210F, "ℼ" U213C, "ℽ" U213D, "ℾ" U213E, "ℿ" U213F, "⨋" U2A0B. compose-1.yml [ce4c440](https://github.com/dispoclavier/nouvel-azerty/commit/ce4c440827307ba04b20e9e75b14b5a288bc2eda)
	* Compléter les séquences de "⃓" U20D3, "⃚" U20DA, "⃬" U20EC, "⃭" U20ED, "℩" U2129, "⅀" U2140. ibidem
	* Compléter la séquence de "ẞ" U1E9E par "S" majuscule suivi du "s" minuscule. ibidem
	* Corriger les séquences de "↯" U21AF, "↶" U21B6, "↷" U21B7, "⤸" U2938, "⤻" U293B, "⦔" U2994. compose-1.yml [196fa3b](https://github.com/dispoclavier/nouvel-azerty/commit/196fa3bc630eb9f1e587a654a653970944516dc6)
	* Compléter la séquence de "⦓" U2993. ibidem
* Transformations :
	* Accent circonflexe : Désactiver l’équivalent en composition des chiffres en exposant à cause du conflit entre "³" U00B3 et "❤" U2764. compose-2.yml [3cf1d35](https://github.com/dispoclavier/nouvel-azerty/commit/3cf1d35f46b3c380e05deb33fdd0078545931bb0), [7e0b9ce](https://github.com/dispoclavier/nouvel-azerty/commit/7e0b9ce9db86588ebe67c9056a5f33dc302d7004)
	* Hatchek : Désactiver l’équivalent en composition des chiffres en indice à cause du conflit entre "³" U00B3 et "❤" U2764, pour la cohérence avec la touche morte accent circonflexe. ibidem

## 1.0.4 (2023-07-30)

* Composition : Corriger les séquences de "⨼" U2A3C et "⨽" U2A3D. compose-1.yml [7f7615a](https://github.com/dispoclavier/nouvel-azerty/commit/7f7615ad97212712585262e528a2cd253c1315e2)
* Transformations :
	* Ajouter la prise en charge de l’apostrophe ASCII comme caractère de base pour la saisie des guillemets apostrophes. compose-2.yml [2ec9a02](https://github.com/dispoclavier/nouvel-azerty/commit/2ec9a02eb735ad7aa352b5c4a8a8121502eba41d), compose-1.yml [2c5626f](https://github.com/dispoclavier/nouvel-azerty/commit/2c5626f24ea1bce7e1e46525df968ecc839a8df9)
	* Groupes des symboles :
		* Permuter les symboles "⊳" U22B3 et "⊲" U22B2 ainsi que "⊢" U22A2 et "⊣" U22A3. compose-2.yml [aa77809](https://github.com/dispoclavier/nouvel-azerty/commit/aa77809a03a69eb462cec0d540f6d4dd76b79ab0)
		* Remplacer "∁" U2201 par "⟂" U27C2. compose-2.yml [13c46b3](https://github.com/dispoclavier/nouvel-azerty/commit/13c46b3783638c6ad6d7c1c62cf3606b071e29cc), [77a281f](https://github.com/dispoclavier/nouvel-azerty/commit/77a281f994ad25cd1e9bb8928eae881596702292), [cae6903](https://github.com/dispoclavier/nouvel-azerty/commit/cae6903280ed2105c27422d9c6524ade4c229cbd)
		* Permuter "ː" U02D0 et "ˑ" U02D1. ibidem
		* Réarranger "⊢" U22A2, "⊣" U22A3, "⊥" U22A5, "⊤" U22A4. ibidem
		* Déplacer "⋱" U22F1, "⋰" U22F0. ibidem
		* Dupliquer "꞉" UA789. ibidem
	* Double accent aigu : Supprimer la touche morte virtuelle en double frappe. compose-1.yml [7c66f9e](https://github.com/dispoclavier/nouvel-azerty/commit/7c66f9eb00175be161f15b57997652efaa9c2b02)
	* Tilde : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent aigu :
		* Supprimer la touche morte virtuelle en double frappe. compose-1.yml [90ca4fe](https://github.com/dispoclavier/nouvel-azerty/commit/90ca4fed7741528d890334352e807042e3e5798f)
		* Déplacer sur la perluète le diacritique combinant supplémentaire. compose-1.yml [f4c1ef6](https://github.com/dispoclavier/nouvel-azerty/commit/f4c1ef6fc90d712606d9ed9b6cd6771b5def6ef0)
	* Brève inversée : Redonder sur la perluète le diacritique combinant souscrit. compose-1.yml [7c66f9e](https://github.com/dispoclavier/nouvel-azerty/commit/7c66f9eb00175be161f15b57997652efaa9c2b02)
	* Brève : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent circonflexe : Redonder sur la perluète le diacritique combinant souscrit. compose-2.yml [0e3eee2](https://github.com/dispoclavier/nouvel-azerty/commit/0e3eee23ef25fa529643e8a8c64ec360e4777bc7)
	* Hatchek : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent grave :
		* Supprimer les touches mortes virtuelles à partir de la triple frappe. compose-1.yml [bef37b4](https://github.com/dispoclavier/nouvel-azerty/commit/bef37b451007ca6ea93b4961eb8eebf7901ba7b7)
		* Déplacer sur la perluète le diacritique combinant supplémentaire. compose-1.yml [f4c1ef6](https://github.com/dispoclavier/nouvel-azerty/commit/f4c1ef6fc90d712606d9ed9b6cd6771b5def6ef0)

## 1.0.3 (2023-07-22)

* Composition :
	* Corriger les séquences des opérateurs invisibles. compose-1.yml [5a7d1c8](https://github.com/dispoclavier/nouvel-azerty/commit/5a7d1c847cb2c9091037bf2684d85bbbd4f4d2aa)
	* Dupliquer avec guillemet apostrophe les séquences avec apostrophe ASCII autres que les primes. compose-1.yml [c4bebdc](https://github.com/dispoclavier/nouvel-azerty/commit/c4bebdc9ad993dc1cc2b452934f9c8f7fa617020)
	* Dupliquer avec majuscule les séquences des constantes d’Euler, de Planck et de Planck sur 2π. compose-1.yml [04ff35f](https://github.com/dispoclavier/nouvel-azerty/commit/04ff35fd21c77219e41459df60dcc1ca16c9006f)
	* Ajouter des séquences basées sur commandes TeX. compose-1.yml [d46e07a](https://github.com/dispoclavier/nouvel-azerty/commit/d46e07a25f0c5d6e62729c1a81ac67a9eecc30ec)
	* Symbole diamètre : Ajouter des séquences française et française simplifiée. compose-1.yml [be410ee](https://github.com/dispoclavier/nouvel-azerty/commit/be410ee29032427ea5bef8ea427026f9ad3a4f29)

## v1.0.2 (2023-07-14)

* Ajouter le correctif à faire dans rules/evdev. dispocla.cpp [afb2e77](https://github.com/dispoclavier/nouvel-azerty/commit/afb2e7707351092a70483116c64be9c8a05b5044)

## v1.0.1 (2023-07-14)

* Sous-variantes : Effacement arrière : Remettre sur la touche traditionnelle. evdev.c [616da80](https://github.com/dispoclavier/nouvel-azerty/commit/616da804a22914e68665f32d522c7c3c074fc55d)

## v1.0.0 (2023-07-14)

* Publication initiale.

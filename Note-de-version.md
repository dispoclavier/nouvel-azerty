# 5.3.0 (prépublication)

Prise en charge des drapeaux et des émojis lettres sur touches vives sous Windows.

Prise en charge des 3 drapeaux régionaux par touche morte sous Linux.

Prise en charge sur touches vives sous Windows de 5 alphabets mathématiques préformatés.

Mise à niveau du pavé numérique sous Windows.

## Modifications

* Disposition :
	* Pavé numérique :
		* Mettre à niveau sous Windows selon le pavé numérique pour Linux. kbcommon.H [eda6c76](https://github.com/dispoclavier/nouvel-azerty/commit/eda6c7662762cf75a58c5c6cd1db3762485b0305), kbfrFRs.C [1363945](https://github.com/dispoclavier/nouvel-azerty/commit/136394566f4e27d3f29b3673c125ea38856af442), [f14901b](https://github.com/dispoclavier/nouvel-azerty/commit/f14901b7302bcd8cc61c55ca832c53633fcbcb03), kbfredis.C [5bc3ad8](https://github.com/dispoclavier/nouvel-azerty/commit/5bc3ad89888cd0dd9c3be10230597447a7b902ec)
		* Remplir les positions vides. dispocla.cpp [4517a6d](https://github.com/dispoclavier/nouvel-azerty/commit/4517a6db7a9f8be2511b0b0f5d9402bebeda7296), kbfrFRs.C [f14901b](https://github.com/dispoclavier/nouvel-azerty/commit/f14901b7302bcd8cc61c55ca832c53633fcbcb03), kbfredis.C [5ea4c28](https://github.com/dispoclavier/nouvel-azerty/commit/5ea4c28f2ef48eb2315c231564cad4403b9d50aa)
	* Niveau 9 :
		* Redonder les émojis lettres indicateurs régionaux "🇦" U+1F1E6 .. "🇿" U+1F1FF sur les touches alphabétiques. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
		* Redonder les émojis chiffres "0️⃣".."9️⃣" et l’émoji touche de téléphone "*️⃣" sur les premières touches de la rangée E. ibidem
		* Ajouter "🟰" U+1F7F0 sur E12 où il est imprimé. ibidem
		* Ajouter "💲" U+1F4B2 sur D12 où il est imprimé. ibidem
		* Redonder "*️⃣" sur C12 où il est imprimé. ibidem
		* Redonder "#️⃣" sur C11 pour compléter la nouvelle dispositon des émojis touches de téléphone. ibidem
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
		* Pallier le bogue de la colonne 02 en redondant dans la colonne 11, ou sur les touches après "N", les émojis lettres ou chiffre disposés sur les touches B02 (🇽⁠), C02 (🇸⁠), D02 (🇿⁠), E02 (2️⃣⁠). ibidem
	* Niveaux (Maj +) AltQr : Redonder "𝐴" U+1D434.."𝑧" U+1D467, "𝟢" U+1D7E2.."𝟫" U+1D7EB. kbfrFRs.C [730f762](https://github.com/dispoclavier/nouvel-azerty/commit/730f76215002565795d3198c2ebf7e6bbb545581), kbfredis.C [0c097c4](https://github.com/dispoclavier/nouvel-azerty/commit/0c097c40e79a41834d804140b7030b331101d375)
	* Niveaux (Maj +) AltGr + AltQr : Redonder "𝔸" U+1D538.."𝕫" U+1D56B, "𝟘" U+1D7D8.."𝟡" U+1D7E1. ibidem
	* Niveaux (Maj +) AltFr + AltQr : Redonder "𝓐" U+1D4D0.."𝔃" U+1D503, "𝟶" U+1D7F6.."𝟿" U+1D7FF. ibidem
	* Niveaux (Maj +) AltGr + AltFr + AltQr : Redonder "𝗔" U+1D5D4.."𝘇" U+1D607, "𝟬" U+1D7EC.."𝟵" U+1D7F5. ibidem
	* Niveaux (AltGr +) AltDr + AltQr : Redonder "𝒜" U+1D49C.."𝓏" U+1D4CF, "𝟎" U+1D7CE.."𝟗" U+1D7D7. kbfrFRs.C [1363945](https://github.com/dispoclavier/nouvel-azerty/commit/136394566f4e27d3f29b3673c125ea38856af442), kbfredis.C [5bc3ad8](https://github.com/dispoclavier/nouvel-azerty/commit/5bc3ad89888cd0dd9c3be10230597447a7b902ec)
	* Niveaux au-dessus de 10 : Préparer pour la prise en charge d’émojis additionnels sur touches vives. kbfrFRs.C [5f0349e](https://github.com/dispoclavier/nouvel-azerty/commit/5f0349e1a347984578a7591ec741521ab1760eb5), kbfredis.C [762a7a7](https://github.com/dispoclavier/nouvel-azerty/commit/762a7a7be03980880e28b1c0f241af70404f32c1)
* Transformations :
	* Double accent aigu > Emojis rapides : Préparer pour la prise en charge d’émojis additionnels sur touche morte. compose-2.yml [00222c4](https://github.com/dispoclavier/nouvel-azerty/commit/00222c4150cb16103a15344123e59479ff477c33), [b10174f](https://github.com/dispoclavier/nouvel-azerty/commit/b10174f270774e29970340cf3b42f8a14dbc2991), compose-3.yml [a907d8b](https://github.com/dispoclavier/nouvel-azerty/commit/a907d8b52e2b8028e56fb93763e9f80bd91afa2b), [dd1017c](https://github.com/dispoclavier/nouvel-azerty/commit/dd1017c76d2111c9baf4ff92dee0679c1821937a)
	* Drapeau :
		* Ajouter le gluon "⁠" U+2060 à la place de l’antiliant "‌" U+200C. compose-2.yml [4d09722](https://github.com/dispoclavier/nouvel-azerty/commit/4d09722041e6559c0f548a125a7bb6a11e3df8fe)
		* Adapter à Windows la touche morte simple pour émettre les émojis lettres indicateurs régionaux sans gluon "⁠" U+2060. kbfrFRs.C [7822970](https://github.com/dispoclavier/nouvel-azerty/commit/78229701e973a3d94f6c06ca222cddfde37adda6), kbfredis.C [70c6263](https://github.com/dispoclavier/nouvel-azerty/commit/70c62635d0c0d79fd250903e181889c0b8596212)
	* Drapeau > Étiquettes :
		* Ajouter les étiquettes minuscules U+E0061..U+E007A à la place de caractères d’usage privé sur les touches alphabétiques pour les drapeaux de subdivisions. compose-2.yml [3f11897](https://github.com/dispoclavier/nouvel-azerty/commit/3f11897053f470d1d01eb44c2ee732e79925b076)
		* Ajouter l’étiquette d’annulation U+E007F pour les drapeaux de subdivisions. ibidem
		* Ajouter les étiquettes capitales U+E0041..U+E005A et les étiquettes chiffres U+E0030..U+E0039 à la place de caractères d’usage privé sur les touches alphabétiques. ibidem
		* Compléter les étiquettes par l’étiquette espace U+E0020 et les étiquettes symboles et ponctuations. en synergie sur la barre d’espace. ibidem
		* Limiter la virgule aux équivalents en composition, et utiliser plutôt la césure conditionnelle en synergie sur la barre d’espace. ibidem
	* Drapeau > Émojis nationaux :
		* Ajouter "🏳" U+1F3F3 par "/". ibidem
		* Ajouter les drapeaux de l’Angleterre, de l’Écosse et du Pays de Galles. compose-2.yml [7551293](https://github.com/dispoclavier/nouvel-azerty/commit/755129326d948956a6ef324e98450d53bb2f14e3)
* Personnalisation : Mettre en ligne le script de compilation utilisé, revu, corrigé, mis à jour et désormais en UTF-8. windows/outils/creadispo.cmd [416474a](https://github.com/dispoclavier/nouvel-azerty/commit/416474acf550216599ac44445c612f0338304974), [e922a72](https://github.com/dispoclavier/nouvel-azerty/commit/e922a72afce2d9982fc90d1364159cef3bc99a9d), [31f44c7](https://github.com/dispoclavier/nouvel-azerty/commit/31f44c747ad3d640f904aec1cf43d751ef2a44b2)
* Documentation :
	* Mettre à jour les modes d’emploi. readme.md alias Mode-d-emploi-commun.md [66bc697](https://github.com/dispoclavier/nouvel-azerty/commit/66bc697465aaf70fcd1d17944371d1b13064507b), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [2b43aaa](https://github.com/dispoclavier/nouvel-azerty/commit/2b43aaa8e0e21e8ea77219a8264da81d18fc0c45), windows/readme.md alias Mode-d-emploi-sous-Windows.md [4a8545f](https://github.com/dispoclavier/nouvel-azerty/commit/4a8545f672fb06df79465c1ac20170be1b94b3e7)
	* Corriger ou compléter des annotations. ibidem, compose-1.yml [e081f7a](https://github.com/dispoclavier/nouvel-azerty/commit/e081f7ad67386e2a1fc21c663a8f6f0ae7c6ebb1), compose-2.yml [1bf7c4e](https://github.com/dispoclavier/nouvel-azerty/commit/1bf7c4e344f333f30bd2848993aa91b028b5ec6d), compose-3.yml [d9eed3f](https://github.com/dispoclavier/nouvel-azerty/commit/d9eed3ff745cba72eb3c4f73b429dd4e6c864cfd), generate-deadkey-tables.pl [534188e](https://github.com/dispoclavier/nouvel-azerty/commit/534188e52c03eef6063c9bad60e583e0a26f1236), kbfrFRs.C [f04d39c](https://github.com/dispoclavier/nouvel-azerty/commit/f04d39c0525359698b613ea2d00ac308bcdaab83), kbfredis.C [9d7c86e](https://github.com/dispoclavier/nouvel-azerty/commit/9d7c86ef5c0383ddb97f085b8d284c87b2e1c6ad) ; kbfrFRs.C [6bf10f9](https://github.com/dispoclavier/nouvel-azerty/commit/6bf10f9b903831985b42a24784c9020bc0446647), kbfredis.C [1d3cb07](https://github.com/dispoclavier/nouvel-azerty/commit/1d3cb075796c999ee24b56b6fa52df73cab3d924) ; dead-key-convert.pl [9054983](https://github.com/dispoclavier/nouvel-azerty/commit/90549832378a5d28e8dbc8aa5ec621c9af6ff997), compose-1.yml [a24ba28](https://github.com/dispoclavier/nouvel-azerty/commit/a24ba28550bae595e179320e876a36f3d23a7767), compose-2.yml [abdc7f4](https://github.com/dispoclavier/nouvel-azerty/commit/abdc7f41a8f8fe2c04a6f99a84552b0bdb9ee2e0), compose-3.yml [d9cb5d5](https://github.com/dispoclavier/nouvel-azerty/commit/d9cb5d54eb3b825035197afeeb2389bc630a9cbc) ; compose-1.yml [513d3ea](https://github.com/dispoclavier/nouvel-azerty/commit/513d3ea43b4b4004d2cea4dbf34f48a5592e95e8), compose-2.yml [08f218f](https://github.com/dispoclavier/nouvel-azerty/commit/08f218fa4deec32cb2963dcbc4efe12da16ac7f8), compose-3.yml [5f86d61](https://github.com/dispoclavier/nouvel-azerty/commit/5f86d61a82d85bba51d2c049bd055062e20ebdb8), kbfrFRs.C [4934f1d](https://github.com/dispoclavier/nouvel-azerty/commit/4934f1d21f6c9895a6e52843de545aeb0df6e38e), kbfredis.C [0068f28](https://github.com/dispoclavier/nouvel-azerty/commit/0068f2843dc9cb4d76e6d84f67c958fc6cb5108e)
	* Simplifier les annotations. dead-key-convert.pl [e0d0479](https://github.com/dispoclavier/nouvel-azerty/commit/e0d047907061bbbd509a4f724d6ac4f2d7dae303), kbfrFRs.C [3689891](https://github.com/dispoclavier/nouvel-azerty/commit/36898916c864988b53035ef0f344b370a9a570bf), kbfredis.C [5e90ac4](https://github.com/dispoclavier/nouvel-azerty/commit/5e90ac4c49895eab430bbc6021184bed08601a62)
	* Améliorer la présentation du contenu des touches mortes. dead-key-convert.pl [99ab07b](https://github.com/dispoclavier/nouvel-azerty/commit/99ab07b1ca6ea0d638b9955ae228ce6f10ae5912), [d5585fe](https://github.com/dispoclavier/nouvel-azerty/commit/d5585fea0cfea5fc9b1722d6f9498496429661cd), kbfrFRs.C [85240b2](https://github.com/dispoclavier/nouvel-azerty/commit/85240b2d66ca768e8a91183c1874483c015e1e18), [a5f285a](https://github.com/dispoclavier/nouvel-azerty/commit/a5f285a873d1d663938692971517727358a62dc2), kbfredis.C [b0b4cd7](https://github.com/dispoclavier/nouvel-azerty/commit/b0b4cd79e5f5125e58c5ccef567f5655c2b088eb), [96196a7](https://github.com/dispoclavier/nouvel-azerty/commit/96196a75b487286974e7c4705691bebc36a27dd4)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-5.3.0.zip).

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des touches mortes enchaînées et de la touche de composition est basé sur la précédente implémentation.

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-5.3.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v5.3.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.3.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.3.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.3.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

Puis fermer la session et en rouvrir une. 

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier `Français (France)` sous le nom `Français France disposition de clavier semi-automatique` et peut être ajouté aux dispositions actives. Afin de l’activer, il est devenu nécessaire de désactiver l’autre disposition.

Les variantes AZERTY s’appellent :

* `Breton et français disposition de clavier semi-automatique` ;
* `Polynésie Française disposition de clavier semi-automatique` ;
* `Afrique francophone disposition de clavier semi-automatique` ;
* `Français Belgique disposition de clavier semi-automatique`.

Les variantes redisposées QZJFGY s’appellent :

* `Français France disposition de clavier semi-automatique redisposée` ;
* `Breton et français disposition de clavier semi-automatique redisposée` ;
* `Polynésie française disposition de clavier semi-automatique redisposée` ;
* `Afrique francophone disposition de clavier semi-automatique redisposée`.

La variante belge ne se décline pas en variante redisposée parce que l’intérêt d’avoir une variante belge, c’est une assez bonne rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

Les vues de disposition se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues. Les rectangles avec un code sont des touches mortes ou des séquences définies dans le répertoire des touches mortes et des séquences Compose(.yml).

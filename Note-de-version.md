# 6.1.3 (2025-11-30)

Prise en charge des personnalisations lors de la réinstallation sous Linux.

Prise en charge de séquences de touche morte spécifiques à Windows.

Portage sous Linux de raccourcis à touche morte développés sous Windows avant 2018.

Réduction de la taille de fichier des paquets téléchargeables pour Windows.

Complétion du contenu des touches mortes et des séquences de composition.

## Modifications

* Composition :
	* Ajouter "⭶" U+2B76, "↸" U+21B8, autres symboles de la touche début. compose-1.yml [ec94770](https://github.com/dispoclavier/nouvel-azerty/commit/ec947701e8dbe712d1f1f13de78e589f09ef645c)
	* Compléter les séquences de "⇱" U+21F1, "⇲" U+21F2. ibidem
	* Réaffecter la séquence « ¦0* » de "♑" U+2651 à "°" U+00B0. ibidem, [ddcd1b1](https://github.com/dispoclavier/nouvel-azerty/commit/ddcd1b124c58b9e91b2d86870d2860057e8eba1e)
	* Redonder "ꭅ" U+AB45 par « ¦r( » et « ¦'(␣ » et similaires. compose-1.yml [dd10547](https://github.com/dispoclavier/nouvel-azerty/commit/dd10547ed386de5c1a540be7e0d115a3e077a217)
	* Redonder "Ꜻ" U+A73A, "ꜻ" U+A73B par « ¦A-V- », « ¦a-v- ». compose-1.yml [aa2c629](https://github.com/dispoclavier/nouvel-azerty/commit/aa2c62910a37d68f2b70b29fc07531c17d2fe1e2), [fa9a58b](https://github.com/dispoclavier/nouvel-azerty/commit/fa9a58bfb5f29e7be92d1b9ce67833d757bd7c80)
	* Redonder "ſ" U+017F par « ¦sl ». compose-1.yml [63e7db5](https://github.com/dispoclavier/nouvel-azerty/commit/63e7db54efd00f34e2ab123ed9d5d8b77c0cf0ff)
	* Transpiler pour Windows. dead-key-convert.pl [747a840](https://github.com/dispoclavier/nouvel-azerty/commit/747a840b2163a4b04d328cd0638e174a83cc6516), kbdeadtrans.c, kbdeadtrans-deadkeys.c, kbdeadtrans-multikey.c, kbdeadtrans-multikey-equivalents.c [59cc6ac](https://github.com/dispoclavier/nouvel-azerty/commit/59cc6ac3643651e4c2d43ddff8078410d3d7930e)
		* Exclure les équivalents en composition des touches mortes pour réduire la taille de fichier des pilotes. kbdeadtrans.c [ab1190f](https://github.com/dispoclavier/nouvel-azerty/commit/ab1190fca2d73deb3928e659e9aee19aa0f5f5a8), [ab6dcc4](https://github.com/dispoclavier/nouvel-azerty/commit/ab6dcc4b51fd3e0a484d533297411942fa5c0a22)
		* Exclure les séquences de composition dédiées tant que le transpilateur n’est pas débogué. kbdeadtrans.c [e698ca6](https://github.com/dispoclavier/nouvel-azerty/commit/e698ca618ed6a351c6bb2036dd63598ae5f9d47a), dead-key-convert.pl [04d0bfe](https://github.com/dispoclavier/nouvel-azerty/commit/04d0bfec422b0c062e7ef99aaf9b2ea56581851a)
* Transformations :
	* Prendre en charge des séquences spécifiques à Windows pour compenser les touches mortes défectueuses de Windows. compose-1.yml [a7e6584](https://github.com/dispoclavier/nouvel-azerty/commit/a7e6584e0493feee47139f042e5f17e44dfcbe63), dead-key-convert.pl, generate-deadkey-tables.pl [aeafec7](https://github.com/dispoclavier/nouvel-azerty/commit/aeafec7385c71c5cb34a79f1b95b05cdff270e75), [5fdd3ae](https://github.com/dispoclavier/nouvel-azerty/commit/5fdd3aea61a49bd8e851cb346a3636e1223a23d9), [1e59c80](https://github.com/dispoclavier/nouvel-azerty/commit/1e59c80bf249efc9f8a6a4f9478da0ef05647533)
		* Accent aigu (touche morte en Minuscule) :
			* Redonder "Ñ" U+00D1 par "B", "ñ" U+00F1 par "b" pour le breton. compose-2.yml [935cab1](https://github.com/dispoclavier/nouvel-azerty/commit/935cab1bf41f45793da30f46044a47378912e012)
			* Redonder "Ɖ" U+0189 par "D", "ɖ" U+0256 par "d" pour les langues africaines. compose-2.yml [8d77433](https://github.com/dispoclavier/nouvel-azerty/commit/8d7743351b6bfb2d3443fe64e7358d7f85f58489)
			* Redonder "Ǝ" U+018E par "F", "ǝ" U+01DD par "f" pour les langues africaines. ibidem
			* Redonder "Ḥ" U+1E24 par "H", "ḥ" U+1E25 psr "h" pour la transcription de l’arabe, du syriaque et de l’hébreu. ibidem
			* Redonder "Ɲ" U+019D par "J", "ɲ" U+0272 par "j" pour les langues africaines. ibidem
			* Redonder "¦" U+00A6 par "q", "Q" comme symbole de la touche de composition. ibidem
			* Redonder "Ṭ" U+1E6C par "T", "ṭ" U+1E6D par "t" pour des transcriptions et romanisations. ibidem
			* Redonder "Ʌ" U+0245 par "V", "ʌ" U+028C par "v" pour la phonétique. ibidem
			* Redonder "Ŋ" U+014A par "X", "ŋ" U+014B par "x". ibidem
	* Tilde : Redonder "❰" U+2770, "❱" U+2771 par "<", ">". compose-2.yml [5f4de75](https://github.com/dispoclavier/nouvel-azerty/commit/5f4de7591985e160b4737b70efc74b3671748d93), [8efaac3](https://github.com/dispoclavier/nouvel-azerty/commit/8efaac3ca70170af4bc824993ec271c0c57d318c)
	* Grec ou cerclé : Ajouter "◎" U+25CE par ")" ou "°" à la place de "⊚" U+229A, qui est dans cerclé. compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
		* Grec ou cerclé > cerclé : Ajouter "◯" U+25EF comme clone espaçant du diacritique  "⃝" U+20DD à la place de "⚪" U+26AA, qui est dans le groupe 3 de "@". ibidem
	* Accent aigu :
		* Redonder "†" U+2020 par "!", "‡" U+2021 par "?", "‱" U+2031 par "%". compose-2.yml [83dfcd1](https://github.com/dispoclavier/nouvel-azerty/commit/83dfcd1a3f8fd916a18eb8a64c85852fa02ea7ff), [bcd5b17](https://github.com/dispoclavier/nouvel-azerty/commit/bcd5b179ed907ebf6c22ddef574d066ec142144e), kbdeadtrans.c [3fa6ce1](https://github.com/dispoclavier/nouvel-azerty/commit/3fa6ce188f231153816a5b5ce90b89ef46c4663d)
		* Redonder "ʔ" U+0294 par "7", "ʕ" U+0295 par "`", "ꭅ" U+AB45 par "(", "•" U+2022 par "*", "±" U+00B1 par "+", "–" U+2013 par "-", "≠" U+2260 par "=", "‣" U+2023 par "^", "❒" U+2752 par "[", "❐" U+2750 par "]". compose-2.yml [d291088](https://github.com/dispoclavier/nouvel-azerty/commit/d29108854335a2ebf63dcc5dbdf447f4c0dde784), [71f226f](https://github.com/dispoclavier/nouvel-azerty/commit/71f226f82a56d62912f4ed6789398693f493031f)
		* Accent aigu et accent grave : Supprimer avec "᷈" U+1DC8, qui va dans accent grave et accent aigu et accent grave. compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
		* Accent aigu > double accent aigu : Redonder "Ő" U+0150, "ő" U+0151, "Ű" U+0170, "ű" U+0171, "˝" U+02DD, "̋" U+030B sans équivalents en composition. compose-2.yml [8843f14](https://github.com/dispoclavier/nouvel-azerty/commit/8843f148e416027779377545603cc00c21296e81), [66945f1](https://github.com/dispoclavier/nouvel-azerty/commit/66945f1726bd099ddc08fa578c7dbe9e156bf779), dead-key-convert.pl [7d63cac](https://github.com/dispoclavier/nouvel-azerty/commit/7d63cac23d21880f5fa712c719e02181631f7b52)
	* Brève :
		* Redonder "ꭇ" U+AB47 par "r", "ꭎ" U+AB4E par "v", "ꭏ" U+AB4F par "V". compose-2.yml [aa2c629](https://github.com/dispoclavier/nouvel-azerty/commit/aa2c62910a37d68f2b70b29fc07531c17d2fe1e2)
		* Redonder "̐" U+0310 par ".". compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
		* Brève et point en chef : Simplifier la saisie de "̐" U+0310. compose-2.yml [6ca08d8](https://github.com/dispoclavier/nouvel-azerty/commit/6ca08d87f027b801b49af1e45ac1a2a8d666c48e)
		* Brève et brève inversée : Ajouter pour redonder "꭛" U+AB5B. compose-2.yml [fa9a58b](https://github.com/dispoclavier/nouvel-azerty/commit/fa9a58bfb5f29e7be92d1b9ce67833d757bd7c80), ibidem
		* Brève et macron : Simplifier la saisie de "᷋" U+1DCB. compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
	* Rayé :
		* Corriger le groupe 1 de "ʉ" U+0289 en y mettant "ꭏ" U+AB4F à la place de "ᵿ" U+1D7F, qui va par "y" comme sans raie. compose-2.yml [aa2c629](https://github.com/dispoclavier/nouvel-azerty/commit/aa2c62910a37d68f2b70b29fc07531c17d2fe1e2)
		* Redonder "†" U+2020 par "|". compose-2.yml [83dfcd1](https://github.com/dispoclavier/nouvel-azerty/commit/83dfcd1a3f8fd916a18eb8a64c85852fa02ea7ff), kbdeadtrans.c ibidem
		* Redonder "ʡ" U+02A1 par "?" et par "'", "ʢ" U+02A2 par "\\", "‡" U+2021 par "+". compose-2.yml [d291088](https://github.com/dispoclavier/nouvel-azerty/commit/d29108854335a2ebf63dcc5dbdf447f4c0dde784), [a72dce6](https://github.com/dispoclavier/nouvel-azerty/commit/a72dce67eea9f7f879896c77a33801f09c9b41fe), [71f226f](https://github.com/dispoclavier/nouvel-azerty/commit/71f226f82a56d62912f4ed6789398693f493031f), kbdeadtrans.c [33db604](https://github.com/dispoclavier/nouvel-azerty/commit/33db604a6ba6e1cb0ec126805ba3b0dce6fae7f0)
		* Redonder "ƾ" U+01BE par "%" et par "Q" à la place de "ʡ" U+02A1, qui est par "q". ibidem (1)
		* Redonder "¬" U+00AC par ",", "÷" U+00F7 par ":", "←" U+2190 par "<", "→" U+2192 par ">", "−" U+2212 par "-", "➔" U+2794 par "=", "➜" U+279C par ")". ibidem (2)
		* Double raie : Redonder "‡" U+2021 par "|". compose-2.yml [83dfcd1](https://github.com/dispoclavier/nouvel-azerty/commit/83dfcd1a3f8fd916a18eb8a64c85852fa02ea7ff), kbdeadtrans.c ibidem
	* Macron :
		* Redonder "†" U+2020 par "+", "‡" U+2021 par "=". ibidem
		* Redonder "ꭗ" U+AB57 par "x", "ꭘ" U+AB58 par "X". compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100), [8efaac3](https://github.com/dispoclavier/nouvel-azerty/commit/8efaac3ca70170af4bc824993ec271c0c57d318c)
		* Macron groupe 2 : Redonder "ʗ" U+0297 par "c" et "C". compose-2.yml [d291088](https://github.com/dispoclavier/nouvel-azerty/commit/d29108854335a2ebf63dcc5dbdf447f4c0dde784), [71f226f](https://github.com/dispoclavier/nouvel-azerty/commit/71f226f82a56d62912f4ed6789398693f493031f)
		* Macron souscrit : Redonder "ʗ" U+0297 par "c" et "C". compose-2.yml [83dfcd1](https://github.com/dispoclavier/nouvel-azerty/commit/83dfcd1a3f8fd916a18eb8a64c85852fa02ea7ff)
		* Macron et brève : Simplifier la saisie de "᷌" U+1DCC. compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
	* Rond en chef :
		* Redonder "ꭔ" U+AB54 par "X" à la place de "ꭘ" U+AB58, qui va dans macron par "X". ibidem
		* Supprimer "ꭔ" U+AB54 par "q". ibidem
	* Accent circonflexe :
		* Ajouter "❬" U+276C par "[" ou "<", et "❭" U+276D par "]" ou ">". compose-2.yml [5f4de75](https://github.com/dispoclavier/nouvel-azerty/commit/5f4de7591985e160b4737b70efc74b3671748d93), [8efaac3](https://github.com/dispoclavier/nouvel-azerty/commit/8efaac3ca70170af4bc824993ec271c0c57d318c)
		* Redonder "‰" U+2030 par "%". compose-2.yml [8efaac3](https://github.com/dispoclavier/nouvel-azerty/commit/8efaac3ca70170af4bc824993ec271c0c57d318c)
		* Redonder "—" U+2014 par "-". compose-2.yml [d291088](https://github.com/dispoclavier/nouvel-azerty/commit/d29108854335a2ebf63dcc5dbdf447f4c0dde784), [71f226f](https://github.com/dispoclavier/nouvel-azerty/commit/71f226f82a56d62912f4ed6789398693f493031f)
		* Redonder "·" U+00B7 par ".", "⁄" U+2044 par "/". compose-2.yml [bcd5b17](https://github.com/dispoclavier/nouvel-azerty/commit/bcd5b179ed907ebf6c22ddef574d066ec142144e)
		* Redonder "ʼ" U+02BC par "," à la place de "ʻ" U+02BB, qui va en double frappe dans hatchek. ibidem
	* Hatchek : Redonder "ʻ" U+02BB par ",". ibidem
	* Accent grave :
		* Redonder "❑" U+2751 par "[", "❏" U+274F par "]". ibidem
		* Accent grave et accent aigu et accent grave : Ajouter pour "᷈" U+1DC8. compose-2.yml [28a3e82](https://github.com/dispoclavier/nouvel-azerty/commit/28a3e8274e740d7bdc20cabba47950545543b100)
	* Cédille : Redonder "ꭕ" U+AB55 par "x", "ꭙ" U+AB59 par "X". ibidem
	* Tréma :
		* Redonder "‰" U+2030 par "%". compose-2.yml [83dfcd1](https://github.com/dispoclavier/nouvel-azerty/commit/83dfcd1a3f8fd916a18eb8a64c85852fa02ea7ff), [bcd5b17](https://github.com/dispoclavier/nouvel-azerty/commit/bcd5b179ed907ebf6c22ddef574d066ec142144e)
		* Redonder "ſ" U+017F par "s". compose-2.yml [bcd5b17](https://github.com/dispoclavier/nouvel-azerty/commit/bcd5b179ed907ebf6c22ddef574d066ec142144e)
* Installation :
	* Sous Linux : Réinstaller les personnalisations de disposition sauvegardées. installer.sh [1d31944](https://github.com/dispoclavier/nouvel-azerty/commit/1d31944908545e090f2cacd13c17dfa386907431)
	* Sous Windows : Réduire la taille du paquet téléchargeable en mettant les variantes à part. windows/Lisez-moi-svp.md [45304f7](https://github.com/dispoclavier/nouvel-azerty/commit/45304f7f4c1ba64a34348b4e5d7d0bfdb5083f76)
* Personnalisation : Sous Linux : Corriger l’exemple 2. dispocla_perso.cpp [36511cc](https://github.com/dispoclavier/nouvel-azerty/commit/36511cc402a584a575e2ae85956aaed37cb0c85c)
* Documentation :
	* Compléter le mode d’emploi. readme.md alias Mode-d-emploi-commun.md [492e009](https://github.com/dispoclavier/nouvel-azerty/commit/492e009459fcc667bf53687221783b3ac60dc416), [e75bb74](https://github.com/dispoclavier/nouvel-azerty/commit/e75bb741c0be7f18eab59a3863350f9ceda3a89f), [79d5342](https://github.com/dispoclavier/nouvel-azerty/commit/79d5342d40196e5d5be2d2d96ff716d16b6b9e4c)
	* Mettre à jour les autres modes d’emploi. linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [87b2fa5](https://github.com/dispoclavier/nouvel-azerty/commit/87b2fa5ec5b186652d2e8bc5221772eb3be8cd59), linux-chromeos/Lisez-moi-svp.md [6451574](https://github.com/dispoclavier/nouvel-azerty/commit/6451574290636026fcbda8d9ad53ec43e3e2219a)
	* Corriger les tableaux de touches mortes après le remplacement de "?" par "=" (5.1.0) puis par "$" (6.0.4) comme caractère de base des doubles diacritiques. compose-2.yml [c50d95c](https://github.com/dispoclavier/nouvel-azerty/commit/c50d95cdf622e13ef0591ea6f716faa040acde91)
	* Corriger et mettre à jour le mode d’emploi de Compose.yml. linux-chromeos/compose/readme.md [63e7db5](https://github.com/dispoclavier/nouvel-azerty/commit/63e7db54efd00f34e2ab123ed9d5d8b77c0cf0ff), [c404e1e](https://github.com/dispoclavier/nouvel-azerty/commit/c404e1ed9d57f5429adeb30f498ebd475204e5c3)
	* Corriger des annotations. compose-2.yml [8843f14](https://github.com/dispoclavier/nouvel-azerty/commit/8843f148e416027779377545603cc00c21296e81), dead-key-convert.pl [7d63cac](https://github.com/dispoclavier/nouvel-azerty/commit/7d63cac23d21880f5fa712c719e02181631f7b52)
	* Corriger ou mettre à jour des annotations. compose-1.yml, compose-2.yml, compose-3.yml [ec94770](https://github.com/dispoclavier/nouvel-azerty/commit/ec947701e8dbe712d1f1f13de78e589f09ef645c), kbdeadtrans.c [dc08bbf](https://github.com/dispoclavier/nouvel-azerty/commit/dc08bbf716f9a15b9f583838d6e13b32e4e6b0e7)
	* Clarifier et compléter des annotations. compose-2.yml [37e6026](https://github.com/dispoclavier/nouvel-azerty/commit/37e6026e3feaa1ccc3195ba9828c7dd4d03402e2)
	* Mettre à jour des annotations. compose-1.yml, compose-2.yml, compose-3.yml [b6e63c6](https://github.com/dispoclavier/nouvel-azerty/commit/b6e63c612d7a08362f84f332145836c3d3beabdc)
	* Corriger "Multi_key:" en "Multikey:" pour l’accorder avec le reste des annotations. compose-2.yml [37d4607](https://github.com/dispoclavier/nouvel-azerty/commit/37d46075872d0a02987523d0311e13e53c05339e)
	* Corriger le journal des modifications. CHANGELOG.md [781e6eb](https://github.com/dispoclavier/nouvel-azerty/commit/781e6eb2ba1b391a86fcf19bd1702c62287bf0ef)
* Builds :
	* 6.1.3.0 [59cc6ac](https://github.com/dispoclavier/nouvel-azerty/commit/59cc6ac3643651e4c2d43ddff8078410d3d7930e)
	* 6.1.3.1 [ab1190f](https://github.com/dispoclavier/nouvel-azerty/commit/ab1190fca2d73deb3928e659e9aee19aa0f5f5a8)
	* 6.1.3.2 [6c097e4](https://github.com/dispoclavier/nouvel-azerty/commit/6c097e4913d96770e19caa9cd373bf1f3dafa5f3), [bcd5b17](https://github.com/dispoclavier/nouvel-azerty/commit/bcd5b179ed907ebf6c22ddef574d066ec142144e)

## Pour Windows

Les touches vives et les touches mortes de la version pour Windows sont à jour sauf la touche de composition, encore à l’état de 2018. Le reste du fichier « Compose.yml » est transpilé en C pour Windows.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.3/Un-nouvel-AZERTY-Windows-6.1.3.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.3/Un-nouvel-AZERTY-Windows-variantes-6.1.3.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.3/Un-nouvel-AZERTY-Linux-6.1.3.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-11-30 |
|-|

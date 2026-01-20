# 6.1.7 (2026-01-20)

Correction du contenu des touches mortes.

Simplification de la saisie des symboles mathématiques.

Portage sous Linux de raccourcis à touche morte développés sous Windows.

## Modifications

* Composition :
	* Corriger des séquences de "🣘" U+1F8D8. compose-1.yml [ec2586a](https://github.com/dispoclavier/nouvel-azerty/commit/ec2586ad2757336f4ceb1367da68da88366d0e5d), [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460)
	* Simplifier la saisie des séquences de "®" U+00AE, "⟒" U+27D2, "⩕" U+2A55, "⩙" U+2A59, "⩚" U+2A5A, "⩜" U+2A5C, "⩞" U+2A5E, "⩟" U+2A5F, "⩠" U+2A60, "⩹" U+2A79, "⩺" U+2A7A, "⫙" U+2AD9, "⫞" U+2ADE, "⫟" U+2ADF, "⫠" U+2AE0, "⫨" U+2AE8, "⫩" U+2AE9, "⫫" U+2AEB, "⫰" U+2AF0, "⫱" U+2AF1, "⬾" U+2B3E, "𜻰" U+1CEF0, "🣖" U+1F8D6. ibidem
* Transformations :
	* Pour Windows :
		* Compléter les demi-codets hauts par U+D833 dans Brève sur "F" pour la nouvelle flèche mathématique "𜻰" U+1CEF0. kbdeadtrans.c [e532b8f](https://github.com/dispoclavier/nouvel-azerty/commit/e532b8fd422729b3bd13526f769dd8b4d7471e6c)
		* Simplifier le transpilateur. dead-key-convert.pl [79f87b9](https://github.com/dispoclavier/nouvel-azerty/commit/79f87b9d9f11c30e43045b5c658aeb639f6279dd), [ffe5563](https://github.com/dispoclavier/nouvel-azerty/commit/ffe5563b5c5bfb74817069b4cb2339097bf24906), [26276ae](https://github.com/dispoclavier/nouvel-azerty/commit/26276ae4c59fa55732d5cc90ff556c5d1c9f9575), kbdeadtrans.c, kbdeadtrans-deadkeys.c, kbdeadtrans-multikey.c, kbdeadtrans-multikey-equivalents.c [a424b2f](https://github.com/dispoclavier/nouvel-azerty/commit/a424b2fb91424fcaa751dbf2457d4eaa1b38d9b8)
	* Exposant :
		* Redonder "̽" U+033D par "×" U+00D7. compose-2.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460)
		* Redonder "ˈ" U+02C8 par "'" à la place de "’" U+2019, qui est par accent aigu. ibidem
		* Redonder "ˮ" U+02EE par "\"" à la place de "”" U+201D, qui est par accent aigu. ibidem
		* Redonder "‾" U+203E par "_". compose-2.yml [0713be1](https://github.com/dispoclavier/nouvel-azerty/commit/0713be1119b9a6ad9fa60ecb132bbce271cb4b0a)
		* Redonder "﹋" U+FE4B par "~". ibidem
		* Suscrit :
			* Redonder "̇" U+0307 par ".". compose-2.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460)
			* Redonder "̍" U+030D par "'" et "’" U+2019. ibidem
			* Redonder "̎" U+030E par "\"" et "€" U+20AC. ibidem
			* Redonder "̓" U+0313 par ",", et "̕" U+0315 par ";". ibidem
			* Redonder "̚" U+031A par "]" à la place des "᫅" U+1AC5, qui sont par "[". ibidem
			* Redonder "̽" U+033D par "×" U+00D7. ibidem
			* Redonder "̿" U+033F par "=". ibidem
			* Redonder "͆" U+0346 par "P". ibidem
			* Redonder "͘" U+0358 par ":". ibidem
			* Redonder "᫢" U+1AE2 par "-". ibidem
			* Redonder "᫨" U+1AE8 par "=" à la place de "̿" U+033F, qui est par espace. ibidem
			* Redonder "ᷭ" U+1DED par "/". ibidem
			* Redonder "᷸" U+1DF8 par "!". ibidem
			* Rendre la saisie de "ᷗ" U+1DD7, "ᷲ" U+1DF2, "ᷳ" U+1DF3, "ᷴ" U+1DF4 insensible à la casse et à la langue. ibidem
			* Redonder "᫁" U+1AC1 par "(" à la place de "᪻" U+1ABB, qui va par "|" et par "1". compose-2.yml [0713be1](https://github.com/dispoclavier/nouvel-azerty/commit/0713be1119b9a6ad9fa60ecb132bbce271cb4b0a)
			* Redonder "᫂" U+1AC2 par ")" à la place de "᪼" U+1ABC, qui va par "$", et par "2" à la place de "᪳" U+1AB3, qui va par "^", et par "W" à la place de "ᷱ" U+1DF1, qui est par "w". ibidem
			* Redonder "̅" U+0305 par "_" à la place de "﹋" U+FE4B, qui vadans Exposant par "~". ibidem
			* Redonder "͑" U+0351 par "D" à la place de "᫙" U+1AD9, qui est par "#". compose-2.yml [b2f2b6a](https://github.com/dispoclavier/nouvel-azerty/commit/b2f2b6a09af6deea6f4105358ef3b660ffece713)
			* Redonder "͗" U+0357 par "F" à la place de "᫫" U+1AEB, qui va par "%". ibidem
			* Groupe 1 : Redonder "᫩" U+1AE9 par "[" et "]". compose-2.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460)
	* Tilde : Redonder "❬" U+276C, "❭" U+276D par "[", "]" à la place de "❰" U+2770, "❱" U+2771, qui sont par "<", ">" et par "{", "}". ibidem
	* Accent aigu :
		* Redonder "᷁" U+1DC1 par ".". ibidem
		* Double accent aigu :
			* Redonder "ʹ" U+02B9 par "1". ibidem
			* Redonder "ʺ" U+02BA par "2". ibidem
			* Redonder "ʼ" U+02BC par "'" et "’" U+2019. ibidem
			* Redonder "ˮ" U+02EE par "\"" et "€" U+20AC. ibidem
	* Indice > Souscrit :
		* Redonder "͉" U+0349 par "[" et "]" et par "l", "a" et "A". ibidem, compose-2.yml [0713be1](https://github.com/dispoclavier/nouvel-azerty/commit/0713be1119b9a6ad9fa60ecb132bbce271cb4b0a)
		* Redonder "͍" U+034D par "5". compose-2.yml [0713be1](https://github.com/dispoclavier/nouvel-azerty/commit/0713be1119b9a6ad9fa60ecb132bbce271cb4b0a)
		* Redonder "᪷" U+1AB7 par "o". ibidem
		* Redonder "᪸" U+1AB8 par "O". ibidem
		* Redonder "᫃" U+1AC3 par "(" à la place de "᪽" U+1ABD, qui va par "|" et par "$", et par "1" à la place de "͎" U+034E, qui va par "9". ibidem
		* Redonder "᫄" U+1AC4 par ")" à la place de "᪽" U+1ABD. ibidem
		* Redonder "᷂" U+1DC2 par "S". ibidem
		* Redonder "᷐" U+1DD0 par "I". ibidem
		* Redonder "̞" U+031E par "2" et par "t". compose-2.yml [b2f2b6a](https://github.com/dispoclavier/nouvel-azerty/commit/b2f2b6a09af6deea6f4105358ef3b660ffece713)
		* Redonder "̘" U+0318 par "4". ibidem
		* Redonder "̙" U+0319 par "6". ibidem
		* Redonder "̝" U+031D par "7" et par "T". ibidem
		* Redonder "̜" U+031C par "d" et "D". ibidem
		* Redonder "̹" U+0339 par "f" et "F". ibidem
		* Redonder "̲" U+0332 par "_" à la place de "͢" U+0362, qui va par "%". ibidem, [d467621](https://github.com/dispoclavier/nouvel-azerty/commit/d4676215228e9c6fd03d03e1cfcfbea50f79018c)
	* Ogonek : Redonder "᷎" U+1DCE par "'". compose-2.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460)
	* Accent circonflexe :
		* Redonder "‧" U+2027 par ";". ibidem
		* Redonder "…" U+2026 par ":". ibidem
		* Redonder "‽" U+203D par "?". ibidem
		* Redonder "⩽" U+2A7D, "⩾" U+2A7E par "<", ">". ibidem
		* Redonder "≦" U+2266 par "=". ibidem
	* Hatchek : Redonder "≧" U+2267 par "=". ibidem
	* Accent grave : Redonder "᷀" U+1DC0 par ".". ibidem
* Documentation :
	* Corriger ou ajouter des annotations. compose-1.yml [ec2586a](https://github.com/dispoclavier/nouvel-azerty/commit/ec2586ad2757336f4ceb1367da68da88366d0e5d)
	* Corriger, ajouter ou supprimer des annotations. compose-1.yml, compose-2.yml, compose-3.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460), dispocla.cpp [de47c9b](https://github.com/dispoclavier/nouvel-azerty/commit/de47c9b6f734a89aa9da14b3c85c4f9410425314)
	* Corriger le journal des modifications. CHANGELOG.md [8b9b866](https://github.com/dispoclavier/nouvel-azerty/commit/8b9b8667e51ae727fbb4b910b7297dc2d7aee70a)
	* Maîtriser la taille des fichiers. compose-2.yml, compose-3.yml [a804301](https://github.com/dispoclavier/nouvel-azerty/commit/a80430158606b9407183edd38f89805112b63460), generate-deadkey-tables.pl [c3b577a](https://github.com/dispoclavier/nouvel-azerty/commit/c3b577a37cf8f059bd0a7f9f180f50e2ba199ca4)
* Builds :
	* 6.1.7.0 [a424b2f](https://github.com/dispoclavier/nouvel-azerty/commit/a424b2fb91424fcaa751dbf2457d4eaa1b38d9b8)
	* 6.1.7.1 [e532b8f](https://github.com/dispoclavier/nouvel-azerty/commit/e532b8fd422729b3bd13526f769dd8b4d7471e6c)
	* 6.1.7.2 [bfb38b5](https://github.com/dispoclavier/nouvel-azerty/commit/bfb38b5bee560b9a9f94c0a7a0e962d875b4179d)
	* 6.1.7.3 [76d47db](https://github.com/dispoclavier/nouvel-azerty/commit/76d47db4dae22f2d7999a4012154d539ba70a0b8)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.7/Un-nouvel-AZERTY-Windows-6.1.7.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.7/Un-nouvel-AZERTY-Windows-variantes-6.1.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.7/Un-nouvel-AZERTY-Linux-6.1.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-01-20 |
|-|

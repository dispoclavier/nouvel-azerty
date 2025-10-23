# 6.1.0 (2025-10-23)

Rectification des groupes des symboles.

Correction des enchaînements de touches mortes.

Transpilation pour Windows des enchaînements de touches mortes.

## Modifications

* Transformations :
	* Enchaînements de touches mortes : Porter sous Windows. dead-key-convert.pl [767b448](https://github.com/dispoclavier/nouvel-azerty/commit/767b448206fc157b9481c873526865fcc7a363b4), [f8086f7](https://github.com/dispoclavier/nouvel-azerty/commit/f8086f736fe1a37ae772b9123e06daa215ee5f41), [4a32f70](https://github.com/dispoclavier/nouvel-azerty/commit/4a32f7017c7d38ba9913fca7c3e8df5f5c264cbd), kbdeadtrans.c [3879914](https://github.com/dispoclavier/nouvel-azerty/commit/3879914249c6c09deea33655c043a85494fee431), [286020b](https://github.com/dispoclavier/nouvel-azerty/commit/286020b83706fe10348a6f07f7d76bd9f0a29276), [98ed3b1](https://github.com/dispoclavier/nouvel-azerty/commit/98ed3b14ca26120eb24a34c8e907d59497580bf9)
	* Groupes des symboles :
		* Groupe 10 de "^" : Redonder "⎋" U+238B à la place de l’antiliant "‌" U+200C, qui est sur touche vive B01. compose-2.yml, compose-3.yml [8475d51](https://github.com/dispoclavier/nouvel-azerty/commit/8475d51a63622a40ac32b611a802d2317fb8406d)
		* Groupe 10 de "%" : Ajouter "�" U+FFFD à la place du liant "‍" U+200D, qui est sur touche vive C01. ibidem
		* Groupe 10 de "€" : Redonder "⌦" U+2326 à la place du sélecteur de variante style émoji "️" U+FE0F, qui va dans tilde. ibidem
		* Groupe 10 de "\\" : Redonder "⌫" U+232B à la place du sélecteur de variante nᵒ 1 "︀" U+FE00, qui va dans tilde. ibidem
		* Groupe 10 de "~" : Redonder "☧" U+2627 à la place du sélecteur de variante style texte "︎" U+FE0E, qui va dans tilde. ibidem
		* Groupe 10 de "(" : Ajouter "⚚" U+269A à la place du diacritique invisible bloquant "͏" U+034F, qui va dans tilde. ibidem
		* Groupe 10 de ")" : Redonder "⎍" U+238D à la place de l’espace nulle insécable "﻿" U+FEFF, qui va dans tilde. ibidem
		* Groupe 3 de "-" : Ajouter "☻" U+263B à la place du signe moins "−" U+2212, qui est sur touche vive D05 et qui va dans le groupe 10 à la place du gluon "⁠" U+2060, qui va dans tilde. ibidem
		* Groupe 10 de "`" :
			* Redonder "⛎" U+26CE à la place du saut de page "" U+000C, qui va dans tilde. ibidem
			* Corriger le décompte des émojis suite à la prise en charge de "⛎" U+26CE dans les groupes des symboles. ibidem
		* Groupe 7 de "@" : Ajouter "❂" U+2742 à la place de "⚬" U+26AC, qui va dans le groupe 7 de "{" à la place de "⚮" U+26AE, qui prend la place de "⚯" U+26AF dans le groupe 7 de "%". ibidem
	* Tourné > Inversé : Compléter les séquences de "ᴓ" U+1D13, "ᴞ" U+1D1E. ibidem
	* Tilde :
		* Ajouter le sélecteur de variante style émoji "️" U+FE0F par "€" à la place du guillemet "”" U+201D, qui est dans accent aigu. ibidem
		* Ajouter le sélecteur de variante nᵒ 1 "︀" U+FE00 par "\\" sur "R". ibidem
		* Ajouter le sélecteur de variante style texte "︎" U+FE0E par "~" sur "T". ibidem
		* Ajouter le diacritique invisible bloquant "͏" U+034F par "(" sur "D". ibidem
		* Ajouter l’espace nulle insécable "﻿" U+FEFF par ")" sur "F". ibidem
		* Ajouter le gluon "⁠" U+2060 par "-" sur "G". ibidem
		* Ajouter le saut de page "" U+000C par "`" sur "N". ibidem
	* Suscrit et tréma : Compléter les séquences de "ᷲ" U+1DF2, "ᷳ" U+1DF3, "ᷴ" U+1DF4. compose-2.yml [468f279](https://github.com/dispoclavier/nouvel-azerty/commit/468f2796c02050550e8559457d7c1335238df271), dead-key-convert.pl [b87cdcb](https://github.com/dispoclavier/nouvel-azerty/commit/b87cdcb4411a841a03c06d4de46faa6741d0dbf5)
	* Brève inversée : Compléter les séquences de "𝼀" U+1DF00. compose-2.yml [5fb7ac4](https://github.com/dispoclavier/nouvel-azerty/commit/5fb7ac46c6293796359390927c36b008851891af), ibidem
	* Souscrit et tourné : Compléter les séquences de "ᫀ" U+1AC0. compose-2.yml [9cf94ec](https://github.com/dispoclavier/nouvel-azerty/commit/9cf94ec01bb853b17748bde717c2029d8cf81f68), ibidem
	* Souscrit et inversé : Compléter les séquences de "ʁ" U+0281, "ꜟ" U+A71F. ibidem
	* Barré groupe 2 : Redonder "≇" U+2247. ibidem
	* Barré > barré oblique groupes : Supprimer. ibidem
	* Barré > barré et drapeau : Supprimer. ibidem
	* Drapeau > Étiquettes : Limiter la prise en charge aux séquences des drapeaux de l’Angleterre, de l’Écosse et du Pays de Galles, prises en charge depuis la version 6.0.0. compose-2.yml [abb51a8](https://github.com/dispoclavier/nouvel-azerty/commit/abb51a8d14e3e4ef0c4540e099050c2ef1bcd7fb)
* Documentation :
	* Windows : Installation : Citer CCM. Note-de-version.md [ec1d6fa](https://github.com/dispoclavier/nouvel-azerty/commit/ec1d6fa61f3d03a16161db1ec6f205cf3367b315), Démarrage-rapide.md, windows/Lisez-moi-svp.md [81ac4da](https://github.com/dispoclavier/nouvel-azerty/commit/81ac4dad8d8b02f7c537a4174e0fb73c0dbd897d)
	* Corriger et annoter le caractère mort de la touche morte « grec ou cerclé ». compose-2.yml [03faaa3](https://github.com/dispoclavier/nouvel-azerty/commit/03faaa3d29c707dcaa40df32d70e55bbfcd46243), [d869a5a](https://github.com/dispoclavier/nouvel-azerty/commit/d869a5a517dae2973dd96675804a968cb14f3bf4), [d57348f](https://github.com/dispoclavier/nouvel-azerty/commit/d57348f827eb920658a9407694b001ce137e947b)
	* Corriger et annoter le caractère mort de la touche morte « rayé ». compose-2.yml [468f279](https://github.com/dispoclavier/nouvel-azerty/commit/468f2796c02050550e8559457d7c1335238df271)
	* Corriger, compléter ou mettre à jour des annotations. compose-1.yml [b1a7dca](https://github.com/dispoclavier/nouvel-azerty/commit/b1a7dca94108e021c148d9ec50d3cd7c64be7b7e), compose-2.yml [5fb7ac4](https://github.com/dispoclavier/nouvel-azerty/commit/5fb7ac46c6293796359390927c36b008851891af), [59e4cf2](https://github.com/dispoclavier/nouvel-azerty/commit/59e4cf29c9d10d9b6524def6470c2dc3b5f76a7a), [e8c1cf6](https://github.com/dispoclavier/nouvel-azerty/commit/e8c1cf679bfcc27e94bdde8f9e60f7fad7fbda91), dispocla.cpp [4e6171f](https://github.com/dispoclavier/nouvel-azerty/commit/4e6171ff1af18f160e747642219515fbf5d4ef03)
* Builds :
	* 6.1.0.0 [3879914](https://github.com/dispoclavier/nouvel-azerty/commit/3879914249c6c09deea33655c043a85494fee431)
	* 6.1.0.1 [286020b](https://github.com/dispoclavier/nouvel-azerty/commit/286020b83706fe10348a6f07f7d76bd9f0a29276)
	* 6.1.0.2 [98ed3b1](https://github.com/dispoclavier/nouvel-azerty/commit/98ed3b14ca26120eb24a34c8e907d59497580bf9)

## Pour Windows

Les touches vives et les touches mortes de la version pour Windows sont à jour, sauf la touche de composition, encore à l’état de 2018. Le reste du fichier « Compose.yml » est transpilé en C pour Windows.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.1.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.0/Un-nouvel-AZERTY-Windows-6.1.0.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes de la version pour Linux sont à jour, mais la touche de composition est encore en cours de développement.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.0/Un-nouvel-AZERTY-Linux-6.1.0.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-10-23 |
|-|

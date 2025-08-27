# 6.0.4 (2025-08-27)

Mise à jour vers Unicode 17.0.

Dans réfléchi, "ʕ" U0295 est désormais par "G" au lieu de "q".

## Modifications

* Disposition : Disposer "🆗" U+1F197 sur toutes les combinaisons de touches qui fonctionnent sous Windows. kbazerty.h, kbbrFRs.C, kbbrFRs.klc, kbcomazerty.c, kbcommon.c, kbdeadtrans.c, kbfrFRs.C, kbfrFRs.klc, kbligatures.c [4f2c6d2](https://github.com/dispoclavier/nouvel-azerty/commit/4f2c6d2a912cee94aa75f39a9fc8190c607d4e66), kbcomredispo.c, kbfrFRsr.C, kbfrFRsr.klc, kbredispo.h [2ec8ac6](https://github.com/dispoclavier/nouvel-azerty/commit/2ec8ac6a983d50d01e5f0a797a0e6d5996791233)
* Transformations :
	* Groupes des lettres :
		* Groupe 4 :
			* Ajouter "꟒" U+A7D2 par "T". compose-3.yml [58a2c65](https://github.com/dispoclavier/nouvel-azerty/commit/58a2c650268a292feec3253470ba967625960d47)
			* Par "t", faire suivre "ꟓ" U+A7D3 du groupe 11 par "T" à la place de "ʨ" U+02A8, qui va par "C".
			* Ajouter "꟔" U+A7D4 par "W".
			* Permuter "ꟕ" U+A7D5 du groupe 11 et "ʍ" U+028D du groupe 4.
		* Groupes 3 et 5 : Permuter "Ꟃ" U+A7C2 et "Ƿ" U+01F7, "ꟃ" U+A7C3 et "ƿ" U+01BF.
	* Exposant :
		* Ajouter "꟱" U+A7F1 par "S". compose-2.yml [9440bdb](https://github.com/dispoclavier/nouvel-azerty/commit/9440bdbb9be8eb9ced2e995155341b5c724e7d61)
		* Suscrit :
			* Ajouter "᫙" U+1AD9 par "D", "᫚" U+1ADA par "B".
			* Ajouter "᫛" U+1ADB par "0", "᫠" U+1AE0 par "4", "᫡" U+1AE1 par "6".
			* Ajouter "᫤" U+1AE4 par "C", "᫫" U+1AEB par "F".
			* Groupe 1 : Ajouter "᫥" U+1AE5 par "m", "᫧" U+1AE7 par "M", "᫩" U+1AE9 par "c", "᫪" U+1AEA par "f", "᫫" U+1AEB par "F".
	* Tourné : Ajouter "᫣" U+1AE3 par "p".
	* Réfléchi :
		* Changer le caractère de base de "ʕ" U+0295 de "q" en "G".
		* Ajouter "꟎" U+A7CE par "Q" à la place de "ʢ" U+02A2, qui va dans réfléchi rayé par "q" 
		* Ajouter "꟏" U+A7CF par "q" à la place de "ʕ" U+0295, qui va par "G".
		* Réfléchi rayé : Ajouter pour "ʢ" U+02A2, qui était dans réfléchi par "Q".
	* Tilde :
		* Ajouter "͌" U+034C par "=" à la place de "͠" U+0360, qui est par "—" U+2014 et par "$".
		* Changer le caractère de base ASCII de "͠" U+0360 de "=" en "$".
	* Point en chef > ligne verticale en chef : Ajouter "᫐" U+1AD0, "᫑" U+1AD1, "᫒" U+1AD2, "᫓" U+1AD3, "᫔" U+1AD4, "᫕" U+1AD5, "᫖" U+1AD6, "᫗" U+1AD7 par les touches mortes impliquées suivies d’espace.
	* Symbole monétaire > symbole monétaire étendu : Ajouter "⃁" U+20C1 par "S" à la place de "₷" U+20B7, qui est par "s".
	* Brève inversée :
		* Changer le caractère de base ASCII de "͡" U+0361 de "=" en "$".
		* Brève inversée souscrite : Changer le caractère de base ASCII de "᷼" U+1DFC de "=" en "$".
	* Brève :
		* Changer le caractère de base ASCII de "͝" U+035D de "=" en "$".
		* Brève souscrite : Changer le caractère de base ASCII de "͜" U+035C de "=" en "$".
	* Rayé > Raie haute : Ajouter "᫢" U+1AE2 par espace à la place de "͆" U+0346, qui est dans le groupe 5 de "P".
	* Indice > souscrit :
		* Redonder "̼" U+033C par "m".
		* Ajouter "᫦" U+1AE6 par "M".
	* Macron :
		* Ajouter "᫘" U+1AD8 par les touches mortes impliquées suivies d’espace.
		* Changer le caractère de base ASCII de "͞" U+035E de "=" en "$".
		* Macron souscrit : Changer le caractère de base ASCII de "͟" U+035F de "=" en "$".
	* Accent circonflexe :
		* Supprimer "ſ" U+017F par "$".
		* Changer le caractère de base ASCII de "᷍" U+1DCD de "=" en "$".
	* Hatchek : Ajouter "᫏" U+1ACF par "w".
	* Drapeau : Ajouter "᫨" U+1AE8 par espace à la place de "͇" U+0347, qui va en double frappe à la place de "͌" U+034C, qui va dans tilde par "=".
	* Tréma :
		* Ajouter "᫜" U+1ADC par "^".
		* Tréma souscrit : Ajouter "᫝" U+1ADD par "*".
* Documentation : Convertir le Démarrage-rapide.txt de texte brut en Markdown et le fournir en PDF. Démarrage-rqpide.md [8d3d6e1](https://github.com/dispoclavier/nouvel-azerty/commit/8d3d6e17721137c34753a90b8b0e1c89f211159a)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai.

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.4/Un-nouvel-AZERTY-Windows-6.0.4.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

### Linux

Dans les dernières versions de Linux, il faut s’attendre à ce que le commutateur de dispositions de clavier est bogué ; mais en n’utilisant qu’une seule disposition, il n’y a pas de problème, comme expliqué dans le [mode d’emploi sous Linux sous le titre « Installation »](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation).

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.4/Un-nouvel-AZERTY-Linux-6.0.4.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.4/Un-nouvel-AZERTY-Linux-6.0.4.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation-manuelle).

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

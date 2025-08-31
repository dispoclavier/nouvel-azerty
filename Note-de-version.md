# 6.0.5 (2025-08-31)

Variantes pour la Polynésie française et pour l’Afrique francophone AZERTY sous Windows.

Rectification et simplification de séquences de composition.

## Modifications

* Disposition :
	* Variantes :
		* Ajouter la variante Polynésie française AZERTY sous Windows. kbfrPFs.C, kbfrPFs.klc, kbcomazerty.c [f3c0922](https://github.com/dispoclavier/nouvel-azerty/commit/f3c09220211458f3bf009d5e8a308749c79bec79), kbcomredispo.c [4e0f39e](https://github.com/dispoclavier/nouvel-azerty/commit/4e0f39ea52ccda80d6052c4e2928a12b859daace)
		* Ajouter la variante Afrique francophone AZERTY sous Windows. kbfrAFs.C, kbfrAFs.klc ibidem
* Composition :
	* Simplifier, améliorer ou corriger les séquences de "∱" U+2231, "∲" U+2232, "∳" U+2233, "∴" U+2234, "∵" U+2235. compose-1.yml [6bf5037](https://github.com/dispoclavier/nouvel-azerty/commit/6bf5037c7b71fe8c493e5143aab88cf68880a814)
	* Simplifier, améliorer ou corriger les séquences de "∷" U+2237, "∹" U+2239, "∺" U+223A, "∻" U+223B, "∾" U+223E, "∿" U+223F, "≀" U+2240, "≂" U+2242, "≋" U+224B, "≎" U+224E, "≎" U+224E, "≒" U+2252, "≓" U+2253, "≔" U+2254, "≕" U+2255, "≖" U+2256, "≗" U+2257, "≘" U+2258, "≙" U+2259, "≙" U+2259, "≚" U+225A, "≛" U+225B, "≝" U+225D. compose-1.yml [3f9ab87](https://github.com/dispoclavier/nouvel-azerty/commit/3f9ab8791478048f0e4f3b90bd02f53d1a2d023d)
* Documentation :
	* Mettre à jour les modes d’emploi. windows/readme.md [2c20a49](https://github.com/dispoclavier/nouvel-azerty/commit/2c20a496ae4916f6f621d2887d733cb25f657fa6), [9529865](https://github.com/dispoclavier/nouvel-azerty/commit/9529865df20c98d248cf882271885b3be2b850bf), [bd3c651](https://github.com/dispoclavier/nouvel-azerty/commit/bd3c651f6f8b484fa73e670c4974d278bc24b08c), Démarrage-rapide.md [d71be81](https://github.com/dispoclavier/nouvel-azerty/commit/d71be816c73cd7bf8bef1c71a9f84a2a1f552504), Lisez-moi-svp.md [0a31ebc](https://github.com/dispoclavier/nouvel-azerty/commit/0a31ebcff4ec7156ce443d9b18b57173edecfafb), linux-chromeos/readme.md [cbe0a60](https://github.com/dispoclavier/nouvel-azerty/commit/cbe0a60e0194d75d7f6d94aaaccbb195726fbd3e), Lisez-moi-svp.md [3a34a5b](https://github.com/dispoclavier/nouvel-azerty/commit/3a34a5b36d870f525a738265994b3848ddb616ab), [ad81541](https://github.com/dispoclavier/nouvel-azerty/commit/ad81541318b4b1e58066afaefaf8b15d76ed12f5)
	* Mieux décrire les bogues connus. kbcommon.c [f3c0922](https://github.com/dispoclavier/nouvel-azerty/commit/f3c09220211458f3bf009d5e8a308749c79bec79)
	* Simplifier la maintenance des séquences de composition. compose-1.yml [aa51478](https://github.com/dispoclavier/nouvel-azerty/commit/aa5147813f7872b2d3fe7faca6b3f6a5c6fd2ca6)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai. Toutes les touches vives sont à jour, toutes les touches mortes simples aussi.

Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.5/Un-nouvel-AZERTY-Windows-6.0.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

### Linux

La version pour Linux est entièrement à jour.

#### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.5/Un-nouvel-AZERTY-Linux-6.0.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.5/Un-nouvel-AZERTY-Linux-6.0.5.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.5/Un-nouvel-AZERTY-Linux-6.0.5.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation-manuelle).

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

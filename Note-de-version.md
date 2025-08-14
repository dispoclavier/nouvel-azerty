# 6.0.1 (2025-08-14)

Débogage du niveau Maj + AltLe + AltQr.

## Modifications

* Disposition : Niveau Maj + AltLe + AltQr :
	* Déboguer par rapport à la bascule VerrMod. kbfrFRs.C [d4d7bc1](https://github.com/dispoclavier/nouvel-azerty/commit/d4d7bc1305c97a80bdcd9cac1924bbb292ebd6b6), kbfrFRsr.C [5b3c05d](https://github.com/dispoclavier/nouvel-azerty/commit/5b3c05dfa4e52bb1264c80157e19631a1d99a7a8)
	* Doubler les touches de la colonne 02 (en panne) dans les colonnes 11 (rangées C, D, E) ou 07 (rangée B).
* Documentation :
	* Mettre à jour le mode d’emploi. windows/readme.md alias Mode-d-emploi-sous-Windows.md [d223b29](https://github.com/dispoclavier/nouvel-azerty/commit/d223b292108c9c17affc87ac9c9aa8354c4750e1)
	* Mettre à jour les tableaux de touches mortes. generate-deadkey-tables.pl [85f388a](https://github.com/dispoclavier/nouvel-azerty/commit/85f388a4dff37f7091056bbf9e663cd3de9ca0fd)
	* Nettoyer les annotations. compose-1.yml [6c32b58](https://github.com/dispoclavier/nouvel-azerty/commit/6c32b58e017dbf9ce4c4faa1778213e2132d79ec), compose-2.yml [0e7785d](https://github.com/dispoclavier/nouvel-azerty/commit/0e7785dba140b231d8f73102a9ef26c9306430d9), compose-3.yml [8b9bcec](https://github.com/dispoclavier/nouvel-azerty/commit/8b9bcec608fe969fc20297ffdd088597224d3561)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai.

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des touches mortes enchaînées et de la touche de composition est basé sur la précédente implémentation.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.1/Un-nouvel-AZERTY-Windows-6.0.1.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.txt) » ou dans « [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.txt) ».

### Linux

Dans les dernières versions de Linux, il faut s’attendre à ce que le commutateur de dispositions de clavier est bogué ; mais en n’utilisant qu’une seule disposition, il n’y a pas de problème, comme expliqué dans le [mode d’emploi sous Linux sous le titre « Installation »](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation).

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.1/Un-nouvel-AZERTY-Linux-6.0.1.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.1/Un-nouvel-AZERTY-Linux-6.0.1.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation-manuelle).

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

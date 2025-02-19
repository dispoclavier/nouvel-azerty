# 4.22.0 (2025-02-19)

Rectification et simplification de la séquence de composition de la ligature "ȹ" U0239.

## Modifications

* Composition : Rectifier et simplifier "ȹ" U+0239. compose-1.yml [17e32ec](https://github.com/dispoclavier/nouvel-azerty/commit/17e32ec85b5389b781cb05b1eac410eed46d9245)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [17e32ec](https://github.com/dispoclavier/nouvel-azerty/commit/17e32ec85b5389b781cb05b1eac410eed46d9245), [6a04730](https://github.com/dispoclavier/nouvel-azerty/commit/6a04730b325408bf94dc83bc1966625796543388)
	* Rectifier la note de version. Note-de-version.md [6b26aad](https://github.com/dispoclavier/nouvel-azerty/commit/6b26aadbe35e624463e7b1a44137c4525a5a1083)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.22.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.22.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.22.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v4.22.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.22.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.22.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.22.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.22.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

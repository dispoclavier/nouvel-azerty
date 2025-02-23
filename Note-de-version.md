# 4.23.0 (2025-02-23)

Rectification de touches mortes.

## Modifications

* Composition : Corriger les séquences de "⫨" U+2AE8, "⫭" U+2AED. compose-1.yml [9ffa049](https://github.com/dispoclavier/nouvel-azerty/commit/9ffa049ec9c978ecad7348db76cb7df251fff29d)
* Transformations : Exposant et crochet rétroflexe, groupes 1–5 : Rectifier "𐞟" U+1079F. compose-2.yml [4032c88](https://github.com/dispoclavier/nouvel-azerty/commit/4032c886ce318fd209cebbe744ec4e698df597ca)
* Documentation :
	* Corriger et compléter des annotations. compose-1.yml [ae2965f](https://github.com/dispoclavier/nouvel-azerty/commit/ae2965f626abf1185a0e89e5259c98c36b67630c), [9ffa049](https://github.com/dispoclavier/nouvel-azerty/commit/9ffa049ec9c978ecad7348db76cb7df251fff29d), compose-2.yml [4032c88](https://github.com/dispoclavier/nouvel-azerty/commit/4032c886ce318fd209cebbe744ec4e698df597ca), [71a17aa](https://github.com/dispoclavier/nouvel-azerty/commit/71a17aae237c1f1148c6edf161be49083d9d822f), compose-3.yml [76c7046](https://github.com/dispoclavier/nouvel-azerty/commit/76c7046aef59b07621ee3829ff090a41b759ad45)
	* Rectifier le journal des modifications. CHANGELOG.md [f734ec7](https://github.com/dispoclavier/nouvel-azerty/commit/f734ec792c0bfdde0ebb9a4086689c219aed9294), [e433b6d](https://github.com/dispoclavier/nouvel-azerty/commit/e433b6dabf39d6a0219349db933013ba60f3c0bd)
	* Rectifier la note de version. Note-de-version.md [185c875](https://github.com/dispoclavier/nouvel-azerty/commit/185c875fdb105c587f9a4ec8d65676b7c51ae054)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.23.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.23.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.23.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v4.23.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.23.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.23.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.23.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.23.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

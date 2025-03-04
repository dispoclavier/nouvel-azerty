# 4.24.0 (2025-03-04)

Correction de la prise en charge des émojis "☀" U+2600 et "☠" U+2620.

Rectification de la touche morte exposant.

## Modifications

* Composition :
	* Prendre en charge l’émoji "☀" U+2600 par « ¦sol », « ¦SOL », « ¦sun », « ¦SUN ». compose-1.yml [c4923d0](https://github.com/dispoclavier/nouvel-azerty/commit/c4923d0ab7f738e911a7552de60b6c3877891b52)
	* Prendre en charge l’émoji "☠" U+2620 par « ¦tox », « ¦TOX ». ibidem
* Transformations :
	* Groupes des symboles :
		* Groupes de "$" :
			* Ajouter "☼" U+263C dans le groupe 4 à la place de l’émoji "☀" U+2600, qui va dans un groupe extra et en composition. compose-3.yml [01d15e9](https://github.com/dispoclavier/nouvel-azerty/commit/01d15e93e1ab22206a075a9927fb191c5003d215), [c363b25](https://github.com/dispoclavier/nouvel-azerty/commit/c363b256878da34a2baf6e7d86e3430ddf1976c4), [14ff1e4](https://github.com/dispoclavier/nouvel-azerty/commit/14ff1e4372ea62a721aa3f3284b409511ae438e9), [35a0eae](https://github.com/dispoclavier/nouvel-azerty/commit/35a0eaed2eed6107e944e1833107ea5904904b01)
			* Ajouter un groupe extra pour l’émoji "☀" U+2600. ibidem
		* Groupes de "~" :
			* Ajouter "☥" U+2625 dans le groupe 5 à la place de l’émoji "☠" U+2620, qui va dans un groupe extra et en composition. ibidem
			* Ajouter un groupe extra pour l’émoji "☠" U+2620. ibidem
	* Exposant groupe 1 par "u" : Mettre "ᶷ" U+1DB7 à la place de "ᶿ" U+1DBF, qui est par "t". compose-2.yml [7a216e6](https://github.com/dispoclavier/nouvel-azerty/commit/7a216e61d3c65f7ac8aeee54e923c22d935f7095)
	* Exposant groupe 2 par "u" : Redonder "ᶿ" U+1DBF à la place de "ᶷ" U+1DB7, qui est dans exposant groupe 1. ibidem
	* Exposant et crochet rétroflexe : Rectifier la prise en charge de "𐞹" U+107B9, par "k" et "!" au lieu de "m". compose-2.yml [56ae33e](https://github.com/dispoclavier/nouvel-azerty/commit/56ae33eae52518643340c42a3a0314ecab84b42a)
* Documentation :
	* Corriger et compléter des annotations. compose-2.yml [d717a87](https://github.com/dispoclavier/nouvel-azerty/commit/d717a8770f1bf3f70ee0ad01e21ec6573a56bc9e), [21ccde6](https://github.com/dispoclavier/nouvel-azerty/commit/21ccde69698f9cb501bfbc3ae30fbdf8728cac14), compose-3.yml [9385cd1](https://github.com/dispoclavier/nouvel-azerty/commit/9385cd106731dadaf9d0ec6936b7a4a49dec3fa8), [35a0eae](https://github.com/dispoclavier/nouvel-azerty/commit/35a0eaed2eed6107e944e1833107ea5904904b01), dispocla.cpp [2849192](https://github.com/dispoclavier/nouvel-azerty/commit/28491921e564bc4d3f3376a90960dc920b3f0dd9)
	* Corriger le journal des modifications. CHANGELOG.md [b75f30a](https://github.com/dispoclavier/nouvel-azerty/commit/b75f30a241329b7ebe8c9630c28c46a8bbe4108f)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.24.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.24.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.24.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v4.24.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.24.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.24.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.24.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.24.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

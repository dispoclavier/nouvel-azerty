# 4.19.0 (2025-01-26)

Amélioration du groupe 1 des lettres pour plus d’intuitivité et de sûreté et moins de redondances.

Débogage, simplification ou correction de plusieurs séquences de composition.

## Modifications

* Composition :
	* Déboguer "⫊" U+2ACA. compose-1.yml [c54f712](https://github.com/dispoclavier/nouvel-azerty/commit/c54f7127f27bb73ec533caca54bf656682415d06)
	* Simplifier ou corriger les séquences de "⁄" U+2044, "ℋ" U+210B, "ℐ" U+2110, "ℒ" U+2112, "ℛ" U+211B, "ℱ" U+2131, "ℴ" U+2134, "⌀" U+2300, "⨢" U+2A22, "⫂" U+2AC2, "⫉" U+2AC9, "⫊" U+2ACA, "⫓" U+2AD3, "⫖" U+2AD6, "⫗" U+2AD7. ibidem
* Transformations :
	* Simplifier les lettres composées pour les langues du Togo. compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df)
	* Groupes des lettres :
		* Groupe 1 :
			* Mettre "ʿ" U+02BF dans le groupe 1 de "l" U+006C au lieu de "K", à la place de "ℓ" U+2113 qui est dans le groupe 1 de "L". compose-3.yml [8df19c1](https://github.com/dispoclavier/nouvel-azerty/commit/8df19c1e1fc6d85cb080720eaf5eeeacfca265d6)
			* Mettre "ʾ" U+02BE dans le groupe 1 de "m" au lieu de "k", à la place de "ɩ" U+0269. ibidem
			* Redonder "ʔ" U+0294 dans le groupe 1 de "M" à la place de "Ɩ" U+0196. ibidem
			* Mettre "Ɩ" U+0196, "ɩ" U+0269 dans le groupe 1 de "I", "i" à la place de "Ĳ" U+0132, "ĳ" U+0133 qui vont dans le groupe 1 de "J", "j" à la place de "Ɲ" U+019D, "ɲ" U+0272 qui vont dans le groupe 1 de "N", "n" à la place de "Ŋ" U+014A, "ŋ" U+014B qui vont dans le groupe 1 de "G", "g" à la place de "Ə" U+018F, "ə" U+0259 qui vont dans le groupe 1 de "H", "h" à la place de "Ǝ" U+018E, "ǝ" U+01DD qui vont dans le groupe 1 de "E", "e" à la place de "€" U+20AC qui est sur AltGr + E et sur AltFr + E. ibidem
			* Redonder "Ɑ" U+2C6D, "ɑ" U+0251 dans le groupe 1 de "K", "k" aux places laissées par "ʿ" U+02BF, "ʾ" U+02BE. ibidem
		* Groupe 2 :
			* Mettre "Ə" U+018F, "ə" U+0259 à la place de "Ǝ" U+018E, "ǝ" U+01DD, qui est dans le groupe 1. ibidem
			* Mettre "Ŋ" U+014A, "ŋ" à la place de "Ɲ" U+019D, "ɲ", qui est dans le groupe 1. ibidem
	* Macron :
		* Supprimer "ꭗ" U+AB57, qui est dans le groupe 5. compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df)
		* Supprimer "ꭙ" U+AB59, qui est dans le groupe 11. ibidem
	* Accent grave : Utiliser "*" au lieu de "x" comme caractère de base de "˟" U+02DF. ibidem
* Documentation : Corriger et compléter des annotations. compose-1.yml [c54f712](https://github.com/dispoclavier/nouvel-azerty/commit/c54f7127f27bb73ec533caca54bf656682415d06), compose-2.yml [6b4f097](https://github.com/dispoclavier/nouvel-azerty/commit/6b4f0974b0545e6db1234052a6a3e29e3d0441df), compose-3.yml [8df19c1](https://github.com/dispoclavier/nouvel-azerty/commit/8df19c1e1fc6d85cb080720eaf5eeeacfca265d6)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.19.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.19.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.19.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier dont le nom finit en « (installation) », puis dans celui qui commence par « kbfrFRs » (« kbfrFRs v4.19.0.0 installation ») et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.19.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.19.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.19.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.19.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

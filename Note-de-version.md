# 4.20.0 (2025-02-02)

Amélioration de l’utilité de la touche morte accent circonflexe par l’hatchek en double frappe.

Simplification ou correction de plusieurs séquences de composition.

## Modifications

* Composition :
	* Simplifier ou corriger les séquences de "⇝" U+21DD, "≄" U+2244, "≇" U+2247, "≉" U+2249, "≊" U+224A, "≌" U+224C, "⋍" U+22CD, "⌉" U+2309, "▴" U+25B4, "⟿" U+27FF, "⤨" U+2928, "⤩" U+2929, "⥲" U+2972, "⦭" U+29AD, "⦮" U+29AE, "⧩" U+29E9, "⨳" U+2A33, "⩡" U+2A61, "⩬" U+2A6C, "⩮" U+2A6E, "⪟" U+2A9F, "⪠" U+2AA0, "⫳" U+2AF3, "⭁" U+2B41, "⭇" U+2B47, "⭉" U+2B49. compose-1.yml [5f99d7a](https://github.com/dispoclavier/nouvel-azerty/commit/5f99d7a6eca6d996c7319866173f5e918ea3390b)
	* Simplifier ou corriger les séquences de "⋊" U+22CA, "◥" U+25E5, "◹" U+25F9, "⟁" U+27C1, "⤯" U+292F, "⥔" U+2954, "⦠" U+29A0, "⦡" U+29A1, "⦥" U+29A5, "⦩" U+29A9, "⦪" U+29AA, "⧋" U+29CB, "⧌" U+29CC, "⧕" U+29D5, "⧨" U+29E8, "⨲" U+2A32, "⨹" U+2A39, "⨺" U+2A3A, "⨻" U+2A3B. compose-1.yml [29fd230](https://github.com/dispoclavier/nouvel-azerty/commit/29fd2309db10dc20f63469c2696a209dbb53b1d4)
* Transformations :
	* Exposant : Reprendre "⁂" U+2042, qui était dans accent circonflexe. compose-2.yml [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed)
	* Exposant et indice (petite capitale) et rayé : Abréger la saisie de "ᶧ" U+1DA7. compose-2.yml [9f856a8](https://github.com/dispoclavier/nouvel-azerty/commit/9f856a82e1dd8b0c18d61ef15027827c81a3f12b)
	* Combinant en chef et cédille : Abréger la saisie de "ᷗ" U+1DD7. ibidem
	* Tilde et perluète : Redonder "△" U+25B3 à la place de "ǃ" U+01C3 comme caractère espaçant vedette, pour la cohérence avec "⃤" U+20E4 et la silhouette de la perluète. compose-2.yml [e2916a6](https://github.com/dispoclavier/nouvel-azerty/commit/e2916a6cad4db68b44a89ea35cf8c7f973d0a374)
	* Accent circonflexe : Supprimer "⁂" U+2042, qui va dans exposant. compose-2.yml [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed)
	* Hatchek : Simplifier le raccourci par accent circonflexe en remplaçant par la double frappe la triple frappe, désormais utilisée pour l’accent circonflexe souscrit, augmenté d’une facilité par l’accord accent circonflexe et rond en chef. ibidem
* Documentation : Corriger et compléter des annotations. compose-1.yml [5f99d7a](https://github.com/dispoclavier/nouvel-azerty/commit/5f99d7a6eca6d996c7319866173f5e918ea3390b), [fbd6680](https://github.com/dispoclavier/nouvel-azerty/commit/fbd6680fe8c9f79ebf08b55899cf8d19f9db9530), [1bb5e82](https://github.com/dispoclavier/nouvel-azerty/commit/1bb5e82ef535715cfcc3dd31eafb49cb2edc67b9), compose-2.yml [e2916a6](https://github.com/dispoclavier/nouvel-azerty/commit/e2916a6cad4db68b44a89ea35cf8c7f973d0a374), [9f856a8](https://github.com/dispoclavier/nouvel-azerty/commit/9f856a82e1dd8b0c18d61ef15027827c81a3f12b), [0a72cc6](https://github.com/dispoclavier/nouvel-azerty/commit/0a72cc6c39b50fe691827786ae014c534e5bb6ed), compose-3.yml [a7f700b](https://github.com/dispoclavier/nouvel-azerty/commit/a7f700b7397ba7c4ca412769291d25f8a93c71c0)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.20.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.20.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.20.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier dont le nom finit en « (installation) », puis dans celui qui commence par « kbfrFRs » (« kbfrFRs v4.20.0.0 installation ») et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.20.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.20.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.20.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.20.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

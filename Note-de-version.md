# 6.0.2 (2025-08-19)

Ajouter l’émoji du phoque sur touche vive sous Windows.

Simplifier les touches mortes.

## Modifications

* Disposition : E11, niveau 9 : Ajouter "🦭" U+1F9AD à la place de "*️⃣", qui est sur C12. kbfrFRs.C [87810e2](https://github.com/dispoclavier/nouvel-azerty/commit/87810e28077c6f8dfa7cc7558fc3b50ed1b79dfb), kbdeadtrans.c idem, kbfrFRsr.C [12f7083](https://github.com/dispoclavier/nouvel-azerty/commit/12f708311f1068818be416c81f2cd6bb1db0a792)
* Transformations :
	* Tourné et bouclé : Simplifier la saisie de "𝼍" U+1DF0D. compose-2.yml [152a0c5](https://github.com/dispoclavier/nouvel-azerty/commit/152a0c5ad60b1800779926ce7d548ac729e187c6)
	* Inversé et groupe 1 :
		* Simplifier la saisie de "ᴒ" U+1D12. ibidem
		* Simplifier la saisie de "℧" U+2127. ibidem
	* Inversé et bouclé : Simplifier la saisie de "𝼎" U+1DF0E. ibidem
	* Rayé et bouclé : Simplifier "𝼌" U+1DF0C. compose-2.yml [036d33d](https://github.com/dispoclavier/nouvel-azerty/commit/036d33d02386ee5ca662bdacd7df0829dd018014)
	* Exposant inversé : Simplifier la saisie de "ʶ" U+02B6, "ᵙ" U+1D59, "ꜞ" U+A71E. compose-2.yml [269d887](https://github.com/dispoclavier/nouvel-azerty/commit/269d8879c35021d3538e23bce138e7c81de71483)
	* Suscrit et cédille : Simplifier la saisie de "ᷗ" U+1DD7. ibidem
	* Suscrit et tréma : Simplifier la saisie de "ᷲ" U+1DF2, "ᷳ" U+1DF3, "ᷴ" U+1DF4. ibidem
	* Exposant tourné crochet rétroflexe : Simplifier la saisie de "𐞧" U+107A7. ibidem
	* Exposant tourné sanglé : Corriger puis simplifier la saisie de "𐞡" U+107A1. ibidem
	* Exposant réfléchi rayé : Simplifier la saisie de "𐞴" U+107B4. ibidem
	* Exposant crosse crochet rétroflexe : Simplifier la saisie de "𐞍" U+1078D. ibidem
	* Exposant crochet rétroflexe sanglé : Simplifier la saisie de "𐞝" U+1079D. ibidem
	* Exposant petite capitale crosse : Simplifier la saisie de "𐞔" U+10794. ibidem
	* Exposant petite capitale sanglée : Corriger puis simplifier la saisie de "𐞜" U+1079C. ibidem
	* Exposant petite capitale rayée : Simplifier la saisie de "ᶧ" U+1DA7. ibidem
	* Exposant barré : Simplifier la saisie de "𐞢" U+107A2. ibidem
	* Grec polytonique : Ajourner la prise en charge sous Windows. dead-key-convert.pl [f422ee2](https://github.com/dispoclavier/nouvel-azerty/commit/f422ee268e130436b0d9b2da349ddc04296998dd)
* Documentation :
	* Déboguer la symétrisation des touches mortes. compose-2.yml [269d887](https://github.com/dispoclavier/nouvel-azerty/commit/269d8879c35021d3538e23bce138e7c81de71483)
	* Corriger une annotation. compose-2.yml [68652c1](https://github.com/dispoclavier/nouvel-azerty/commit/68652c1fe505832e5710194dbb029d0a3a55e923)
	* Déplacer 2 sous-sections. ibidem
	* Déplacer 2 sous-sections. compose-2.yml [241ced3](https://github.com/dispoclavier/nouvel-azerty/commit/241ced375485ba550814c929fea021a2c989320e)
	* Corriger des annotations. compose-2.yml [152a0c5](https://github.com/dispoclavier/nouvel-azerty/commit/152a0c5ad60b1800779926ce7d548ac729e187c6), [036d33d](https://github.com/dispoclavier/nouvel-azerty/commit/036d33d02386ee5ca662bdacd7df0829dd018014), [052452c](https://github.com/dispoclavier/nouvel-azerty/commit/052452c7ad675cf414514b0f693b5090d8a0b6f8)
	* Corriger et compléter des annotations. compose-1.yml [a9f732a](https://github.com/dispoclavier/nouvel-azerty/commit/a9f732a6441200a1b824df997a93b9b87b48e290), compose-2.yml [e2c728b](https://github.com/dispoclavier/nouvel-azerty/commit/e2c728bb273d93813bd687269778dbdc2e65282c), compose-3.yml [5795e3b](https://github.com/dispoclavier/nouvel-azerty/commit/5795e3b373162fefc7d9a7d4395299b1d9ecf5a8)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai.

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des touches mortes enchaînées et de la touche de composition est basé sur la précédente implémentation.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.2/Un-nouvel-AZERTY-Windows-6.0.2.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.txt) » ou dans « [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.txt) ».

### Linux

Dans les dernières versions de Linux, il faut s’attendre à ce que le commutateur de dispositions de clavier est bogué ; mais en n’utilisant qu’une seule disposition, il n’y a pas de problème, comme expliqué dans le [mode d’emploi sous Linux sous le titre « Installation »](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation).

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.2/Un-nouvel-AZERTY-Linux-6.0.2.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.2/Un-nouvel-AZERTY-Linux-6.0.2.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation-manuelle).

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

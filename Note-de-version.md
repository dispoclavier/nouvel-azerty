# 6.0.3 (2025-08-24)

Variante bretonne AZERTY sous Windows.

Débogage de 2 touches AZERTY sous Windows.

## Modifications

* Disposition :
	* Déboguer les touches E07 et E08. kbfrFRs.klc [ac61bdd](https://github.com/dispoclavier/nouvel-azerty/commit/ac61bdd8d23a011b85ef3f30416531af1a8f8ff7), kbfrFRs.C [9a345fe](https://github.com/dispoclavier/nouvel-azerty/commit/9a345fe47ba09516e0fad02197433e4e9a43e7fc)
	* (AltGr +) AltFr + AltLe (+ AltQr) : Redonder le gluon U+2060 sur la barre d’espace. kbfrFRs.C [454cec1](https://github.com/dispoclavier/nouvel-azerty/commit/454cec12f53328113cde8017d9b1ccafcb19506c), kbfrFRsr.C [26edd8e](https://github.com/dispoclavier/nouvel-azerty/commit/26edd8ea8ea5e92832e32cf74dd5204d9aceb57e)
	* Simplifier les séquences. ibidem, kbfrFRs.C [2446f85](https://github.com/dispoclavier/nouvel-azerty/commit/2446f85262e50a1051eb4acca84cfd2970109af1), kbligatures.c idem, kbligazerty.c idem, kbfrFRsr.C [89205d9](https://github.com/dispoclavier/nouvel-azerty/commit/89205d9f64cec8da6cbc074812c10a350a33b523), kbligqzjfgy.c idem
	* Variantes régionales :
		* Compléter la simplification des sources. kbfrFRs.C [7c4f414](https://github.com/dispoclavier/nouvel-azerty/commit/7c4f414fd50b1a72ffe4ec94570349f1d0318309), kbcommon.c idem, kbfrFRsr.C [bb33ef4](https://github.com/dispoclavier/nouvel-azerty/commit/bb33ef48fbd1c709197647c96ea90e268cc1a1cb) ; kbfrFRs.C [b092d35](https://github.com/dispoclavier/nouvel-azerty/commit/b092d3571b0bd49b9af985cb6a509d2e1ab24062), kbcommon.c idem, kbcomazerty.c idem, kbligatures.c idem, kbfrFRsr.C [c79e328](https://github.com/dispoclavier/nouvel-azerty/commit/c79e328c434145357b2f71733761aa8474381e63), kbcomqzjfgy.c idem
			* Renommer kbfrFRs.H en kbazerty.h. kbazerty.h [48cd71b](https://github.com/dispoclavier/nouvel-azerty/commit/48cd71b279c87423b24f71a78f89ad4f109bf486), kbfrFRs.C [9a345fe](https://github.com/dispoclavier/nouvel-azerty/commit/9a345fe47ba09516e0fad02197433e4e9a43e7fc)
			* Renommer kbfrFRsr.H en kbqzjfgy.h. kbqzjfgy.h [48cf9f4](https://github.com/dispoclavier/nouvel-azerty/commit/48cf9f4e75d79278fdcd80950486951f6b6459f8), kbfrFRsr.C [cea8dfc](https://github.com/dispoclavier/nouvel-azerty/commit/cea8dfc7a8f02b11bbdf380c38d576da25abfc80)
			* Supprimer les fichiers .DEF. kbfrFRs.DEF [11e7ab3](https://github.com/dispoclavier/nouvel-azerty/commit/11e7ab384484ad5191707be9620011b673287051), kbfrFRs.C [9a345fe](https://github.com/dispoclavier/nouvel-azerty/commit/9a345fe47ba09516e0fad02197433e4e9a43e7fc), [edefb2a](https://github.com/dispoclavier/nouvel-azerty/commit/edefb2a74a6389fcab7853ef930e81fe17fb3c69), kbfrFRsr.DEF [3854057](https://github.com/dispoclavier/nouvel-azerty/commit/3854057d42bb7fb43c2fc4d11ed365904571184d), kbfrFRsr.C [cea8dfc](https://github.com/dispoclavier/nouvel-azerty/commit/cea8dfc7a8f02b11bbdf380c38d576da25abfc80), [8c477ab](https://github.com/dispoclavier/nouvel-azerty/commit/8c477abf7388b25f9481a4249731e0f918999a98)
		* Ajouter la variante bretonne AZERTY sous Windows. kbbrFRs.klc [2457768](https://github.com/dispoclavier/nouvel-azerty/commit/2457768fc41eaddd200212930466ceec46368eb9), kbbrFRs.C idem, kbbrFRs.RC idem, [8aff57c](https://github.com/dispoclavier/nouvel-azerty/commit/8aff57cd7715367b158e1a8448850c31fa6a6af2)
	* Variantes redisposées :
		* Déboguer (mettre à jour) #include "kbfrFRsr.h". kbfrFRsr.C [26edd8e](https://github.com/dispoclavier/nouvel-azerty/commit/26edd8ea8ea5e92832e32cf74dd5204d9aceb57e)
		* Génériquer les noms et chemins de fichier :
			* Renommer qzjfgy/kbqzjfgy.h en redispo/kbredispo.h. kbredispo.h. [adbb925](https://github.com/dispoclavier/nouvel-azerty/commit/adbb92571d127e32b5cb34c0f39e8acb6bdd646e), [edbd074](https://github.com/dispoclavier/nouvel-azerty/commit/edbd07459b12801dcfa89304d4e3013de98bd7a2), [88f0ae5](https://github.com/dispoclavier/nouvel-azerty/commit/88f0ae51f3d2f6588cded980ecc3b89b7b65de67), kbfrFRsr.C [aff7996](https://github.com/dispoclavier/nouvel-azerty/commit/aff799611295b94cbf56daf948146afb64e85d52), kbfrFRsr.klc [a1c3087](https://github.com/dispoclavier/nouvel-azerty/commit/a1c308705f024f19425671b0bfdef155dc218226), [d4c7249](https://github.com/dispoclavier/nouvel-azerty/commit/d4c7249a389566754498a97514f2e64b081b0299), kbfrFRsr.RC [40a92e5](https://github.com/dispoclavier/nouvel-azerty/commit/40a92e55d06815f36a1a2754c9c8477ec07f4706), [d4c7249](https://github.com/dispoclavier/nouvel-azerty/commit/d4c7249a389566754498a97514f2e64b081b0299)
			* Renommer qzjfgy/kbcomqzjfgy.c en redispo/kbcomredispo.c. kbcomredispo.c. [3a5be6c](https://github.com/dispoclavier/nouvel-azerty/commit/3a5be6c127c2459badc45bfce4c414060c980a06)
			* Renommer qzjfgy/kbligqzjfgy.c en redispo/kbligredispo.c. kbligredispo.c. [267e21a](https://github.com/dispoclavier/nouvel-azerty/commit/267e21a419206ee7b8977609912ebe813d6d6b4c)
* Documentation :
	* Mettre à jour les modes d’emploi sous Windows. windows/Lisez-moi-svp.txt [6108bc1](https://github.com/dispoclavier/nouvel-azerty/commit/6108bc1f24aa0118adf2c293809b912e34020a81), windows/readme.md alias Mode-d-emploi-sous-Windows.md [ae3cd54](https://github.com/dispoclavier/nouvel-azerty/commit/ae3cd54e6e7d21ef3f63e1fdaf3dbcee86c7d767)
	* Mettre à jour une annotation. kbfrFRsr.C [50a2645](https://github.com/dispoclavier/nouvel-azerty/commit/50a264556ba806f16aa97c82d3f02075bdf99a4b) ; dispocla.cpp [3113e61](https://github.com/dispoclavier/nouvel-azerty/commit/3113e617611a838f4c020d7f1e84b5fb7ef4a3a0)
	* Corriger et compléter les annotations. kbcommon.c [05665f6](https://github.com/dispoclavier/nouvel-azerty/commit/05665f6e25d3a3646ce00ee7e8c75b926298b221), kbfrFRs.C [5d8ecb5](https://github.com/dispoclavier/nouvel-azerty/commit/5d8ecb5000329041ec9a24ed35b36b86458388e7), kbfrFRsr.C [34f5162](https://github.com/dispoclavier/nouvel-azerty/commit/34f51624bf901e9af12227205da1cade1148a43e)
	* Compléter la documentation des bogues connus. kbcommon.c [e075f0a](https://github.com/dispoclavier/nouvel-azerty/commit/e075f0aaf8d1eba76d323517cbd1a49a9be93132), [0e92baf](https://github.com/dispoclavier/nouvel-azerty/commit/0e92baf5dc50e0dae3fe7f788b0fd36badbca719)

## Un nouvel AZERTY pour Linux et Windows, et bientôt pour macOS

### Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai.

Toutes les touches vives sont à jour, toutes les touches mortes simples aussi. Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018.

#### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.3/Un-nouvel-AZERTY-Windows-6.0.3.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.txt) » ou dans « [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.txt) ».

### Linux

Dans les dernières versions de Linux, il faut s’attendre à ce que le commutateur de dispositions de clavier est bogué ; mais en n’utilisant qu’une seule disposition, il n’y a pas de problème, comme expliqué dans le [mode d’emploi sous Linux sous le titre « Installation »](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation).

#### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.3/Un-nouvel-AZERTY-Linux-6.0.3.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre les instructions dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus.

Sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311), cette méthode est la seule qui fonctionne, en raison de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

#### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.3/Un-nouvel-AZERTY-Linux-6.0.3.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation-manuelle).

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

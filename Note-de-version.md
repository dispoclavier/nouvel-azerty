# 5.2.0 (2025-06-15)

Réimplémentation des touches mortes simples diacritiques ou transformationnelles sous Windows sur le modèle finalisé sous Linux.

Meilleure prise en charge des demi-codets hauts.

Simplification et complétion des touches mortes sous Linux.

Prise en charge d’un émoji supplémentaire sur touche vive.

## Modifications

* Disposition :
	* Ajouter "🙂" U+1F642 sur AltGr + AltFr + S à la place de "§" U+00A7, qui est sur sa touche historique B10. dispocla.cpp [8109e39](https://github.com/dispoclavier/nouvel-azerty/commit/8109e3963de158c46d85221115c85cef740a5106), kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), kbfredis.klc [1053c20](https://github.com/dispoclavier/nouvel-azerty/commit/1053c201fe9799b122c0e7c0bacb4e1eba4e2fe6), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), nouvel-azerty.json [8a5bc2b](https://github.com/dispoclavier/nouvel-azerty/commit/8a5bc2b3daecaf1603fd9cc3977c2baa1c5b83d4), [da1531d](https://github.com/dispoclavier/nouvel-azerty/commit/da1531d797674e522fc2591443523a69ddebdae6), nouvel-azerty-verrcap.json [8267eee](https://github.com/dispoclavier/nouvel-azerty/commit/8267eee327bd4223f220771f7d10db6cfb0785e0), [f0acf71](https://github.com/dispoclavier/nouvel-azerty/commit/f0acf718993293dc7a90c2e22402882c2d6142c6), nouvel-azerty-verrmod.json [155b470](https://github.com/dispoclavier/nouvel-azerty/commit/155b4700633c6d34b6fd7291aa42cbb66ab156a1), [272e1b1](https://github.com/dispoclavier/nouvel-azerty/commit/272e1b1e88d053a1344f968d691ee4addb696ede), nouvel-azerty-verrmod-verrcap.json [0362a5a](https://github.com/dispoclavier/nouvel-azerty/commit/0362a5a822f37001fa5d8e5e086eb0d290778f23), [37a385e](https://github.com/dispoclavier/nouvel-azerty/commit/37a385e38f651620d9bdbc5675f5997c141dff42)
	* Changer le caractère mort de la touche morte groupe de "²" U+00B2 en "①" U+2460. kbfredis.klc [13e3cd6](https://github.com/dispoclavier/nouvel-azerty/commit/13e3cd6c9b034d914dfa24768c1221c90b9b8465), kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95)
	* Changer le caractère mort de la touche morte cédille de "ȩ" U+0229 en "ç" U+00E7. kbfrFRs.klc [b28de47](https://github.com/dispoclavier/nouvel-azerty/commit/b28de473c5a2596b3be90716ace5e953859c1636), kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), kbfredis.klc [1053c20](https://github.com/dispoclavier/nouvel-azerty/commit/1053c201fe9799b122c0e7c0bacb4e1eba4e2fe6), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), dead-key-convert.pl [bc8d230](https://github.com/dispoclavier/nouvel-azerty/commit/bc8d2303cf88146c294391de05cd8aa9081b1140)
* Transformations :
	* Émulation de touche "ê" : Compléter le digramme "êq" en trigramme "êqu". compose-2.yml [bd2cbcb](https://github.com/dispoclavier/nouvel-azerty/commit/bd2cbcbfc7c2d8f7c996e30f60bf7c935e6c664e)
	* Atténuer la disruption de l’expérience utilisateur entre Linux/macOS et Windows en matière d’émulation de touches "ê" et "ç". kbfrFRs.C [e439bc6](https://github.com/dispoclavier/nouvel-azerty/commit/e439bc645b6eaad8f481c4e8d696b6892e193b95), [97701e0](https://github.com/dispoclavier/nouvel-azerty/commit/97701e0eb410ca910fd485db3b0163fdc3add50c), kbfredis.C [c7017f9](https://github.com/dispoclavier/nouvel-azerty/commit/c7017f9e95d89d00aa2a20e1d5010d2b9e2a3f02), [75ab534](https://github.com/dispoclavier/nouvel-azerty/commit/75ab53455834b4342c7035f3df3b394a1e04e528)
	* Convertir les touches mortes simples d’XCompose en C. dead-key-convert.pl [58d3c22](https://github.com/dispoclavier/nouvel-azerty/commit/58d3c2294dead063d317747af194fb67d0ae01ed), kbfredis.C [e2062be](https://github.com/dispoclavier/nouvel-azerty/commit/e2062be76f506149c71f61197e810e791da730dc), kbfrFRs.C [0563872](https://github.com/dispoclavier/nouvel-azerty/commit/05638729cb98e370a4d54b4df30d2dd425069011)
	* Prendre en charge les demi-codets hauts. dead-key-convert.pl [228e8de](https://github.com/dispoclavier/nouvel-azerty/commit/228e8de2dfd811d20843709cd7a4f6dd656608e6), [ad8fcb3](https://github.com/dispoclavier/nouvel-azerty/commit/ad8fcb3e1c7c8b3f7cf140fa51afc9e7bb1b8986), [28b1f18](https://github.com/dispoclavier/nouvel-azerty/commit/28b1f18fea37267e3300b5528c9d6a014c8701a2), [1337c45](https://github.com/dispoclavier/nouvel-azerty/commit/1337c45f970d465ed5357053dbbd13fd98fd8333), [7dc449d](https://github.com/dispoclavier/nouvel-azerty/commit/7dc449d71fa63a9f6cab651b1f653cdab5709f87), [5dabd2a](https://github.com/dispoclavier/nouvel-azerty/commit/5dabd2a39e8847c89f3ac38514e162ba16482fcf), kbfredis.C [c7f17d4](https://github.com/dispoclavier/nouvel-azerty/commit/c7f17d407333cab18f59d9b7ccd4a90ea1f01fe1), [bce4e8f](https://github.com/dispoclavier/nouvel-azerty/commit/bce4e8ff153c2e142c3a313a4821fe509768ad5a), [6b3445a](https://github.com/dispoclavier/nouvel-azerty/commit/6b3445a8dcf48b057b9c16927f1fa885821f0697), [5ddca95](https://github.com/dispoclavier/nouvel-azerty/commit/5ddca95c07f2a6f6ca06066a1805f8314f230c6c), kbfrFRs.C [0563872](https://github.com/dispoclavier/nouvel-azerty/commit/05638729cb98e370a4d54b4df30d2dd425069011), [dcc9e7b](https://github.com/dispoclavier/nouvel-azerty/commit/dcc9e7b6926ef3a412333f8c82163f78f75c6bfe), [7fcc8e1](https://github.com/dispoclavier/nouvel-azerty/commit/7fcc8e14be3892752be14afb7825720c18b3c6ac)
	* Simplifier la saisie de "𐞍" U+1078D, "𐞔" U+10794, "𐞜" U+1079C, "𐞝" U+1079D, "𐞡" U+107A1, "𐞢" U+107A2, "𐞧" U+107A7, "𐞴" U+107B4. compose-2.yml [f65ce6e](https://github.com/dispoclavier/nouvel-azerty/commit/f65ce6e0983576c1489a2df9af72323b6367105c)
	* Accent circonflexe groupe 2 : Prendre en charge "🙶" U+1F676. ibidem
	* Accent aigu groupe 2 : Prendre en charge "🙷" U+1F677. ibidem
	* Tréma : 
		* Groupe 2 : Prendre en charge "🙸" U+1F678. ibidem
		* Supprimer le demi-codet haut U+D835 des symboles mathématiques alphanumériques. ibidem
	* Drapeau : Supprimer le demi-codet haut U+D835 des symboles mathématiques alphanumériques. ibidem
	* Groupes 11 et 12 : Améliorer la prise en charge du demi-codet haut U+D83E des flèches. ibidem
* Documentation :
	* Corriger et compléter les modes d’emploi. readme.md alias Mode-d-emploi-commun.md [bdc4fb2](https://github.com/dispoclavier/nouvel-azerty/commit/bdc4fb2a3154765ce199a13ecb8ad06a1954184d), [bba3dfb](https://github.com/dispoclavier/nouvel-azerty/commit/bba3dfbd8af043d7f89c9857ba5a2a8e47844762), [f69bb7e](https://github.com/dispoclavier/nouvel-azerty/commit/f69bb7e8a6d29f9bfea080be5946e42b20918bf6), [4193fae](https://github.com/dispoclavier/nouvel-azerty/commit/4193faed977af52630c8a2381455c45b6c2b8f9f), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [efc166f](https://github.com/dispoclavier/nouvel-azerty/commit/efc166f66eb0370739b37d58ee253266b28030ba), [dc88756](https://github.com/dispoclavier/nouvel-azerty/commit/dc88756ff6bb08399fb7e45a19fe169d1bd7225c), [9ba26bb](https://github.com/dispoclavier/nouvel-azerty/commit/9ba26bb204933c3ee79cb6274e179b899cc95011), windows/readme.md alias Mode-d-emploi-sous-Windows.md [dcf4231](https://github.com/dispoclavier/nouvel-azerty/commit/dcf423167fa52a6ae0b1875bf68b846817e2ae46), [26b72c1](https://github.com/dispoclavier/nouvel-azerty/commit/26b72c16effdfa745cf4130f787845bb3c360425), [4d33148](https://github.com/dispoclavier/nouvel-azerty/commit/4d33148d594dec3d1a5365e4088a4d2b36f61a9e), [ed4c8af](https://github.com/dispoclavier/nouvel-azerty/commit/ed4c8af3f0e9d0a65e96c09b18e0fe00b8b11a0b), [d0ee7a6](https://github.com/dispoclavier/nouvel-azerty/commit/d0ee7a6833497a2d4880f53c3671dd51b3f3a76f)
	* Documenter le bogue de la touche C11 de l’AZERTY. windows/readme.md alias Mode-d-emploi-sous-Windows.md [26b72c1](https://github.com/dispoclavier/nouvel-azerty/commit/26b72c16effdfa745cf4130f787845bb3c360425), kbfrFRs.C [c22acd3](https://github.com/dispoclavier/nouvel-azerty/commit/c22acd3fab99782947ef3e14e8893476935325b4)
	* Corriger, ajouter ou supprimer des annotations. compose-2.yml [f65ce6e](https://github.com/dispoclavier/nouvel-azerty/commit/f65ce6e0983576c1489a2df9af72323b6367105c), compose-3.yml [c09300d](https://github.com/dispoclavier/nouvel-azerty/commit/c09300d79e9406cb9bed8bf72ec1119e7c90453c) ; compose-2.yml [f4eb2bc](https://github.com/dispoclavier/nouvel-azerty/commit/f4eb2bc4e0828917eafe871d824c3bd42bad66d1), dead-key-convert.pl [8d0987c](https://github.com/dispoclavier/nouvel-azerty/commit/8d0987c33a7dc36237092fb1e1737dc8c300bef5) ; compose-1.yml [afeb2ce](https://github.com/dispoclavier/nouvel-azerty/commit/afeb2ce1b2c2065174cfc6e89dae479296491460), compose-2.yml [c2f05e7](https://github.com/dispoclavier/nouvel-azerty/commit/c2f05e7da4370487b2a050b44a8755e9813f914d), dispocla.cpp [4570f8f](https://github.com/dispoclavier/nouvel-azerty/commit/4570f8fae107ea293c7f15aa57adb6335a9cdbf6)
	* Améliorer le tri. compose-1.yml [caf2515](https://github.com/dispoclavier/nouvel-azerty/commit/caf25150addfc74c11cb4696d3ac824fa14f6725) ; (Éviter de changer les keysyms d’XKB.) compose-1.yml [8755bd8](https://github.com/dispoclavier/nouvel-azerty/commit/8755bd8fb3a5558cfa491acd49b8fc5d33a69e60)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-5.2.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-5.2.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-5.2.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v5.2.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.2.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.2.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.2.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.2.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

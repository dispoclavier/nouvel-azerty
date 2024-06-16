# Un nouvel AZERTY pour Linux

## Systèmes

Ces fichiers sont développés, testés et compilés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule à la fois ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3**).

Quant à **Chrome OS**, il utilise certes XKB mais le fournit codé en dur, et même dans le conteneur Linux, l’image d’X11 est hors service. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks puissants. Le bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à Chrome OS.

## Extensions de fichiers

À l’usage, la plupart de ces fichiers sont sans extension. Les extensions `.c`, `.cpp` et `.yml` servent surtout à ajouter des couleurs, et aussi à faciliter l’ouverture de ces fichiers sous Windows. L’extension `.cpp` a été choisie pour éviter `dispocla.c` ; les noms de fichier « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives.

De toute manière, les statistiques de langage sont désactivées.

## Utilisation sans droits d’administrateur

La version de Linux recommandée pour cet usage est [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou l’équivalent, de cette époque, des autres distributions.

Télécharger le dossier `Nouvel-AZERTY-Linux-`version`.zip` sous le titre « Assets », et suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

## Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « Nouvel-AZERTY-Linux-`version`.zip » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh). On peut aussi installer chaque fichier manuellement.

### Script d’installation : mode d’emploi

Le script d’installation s’appelle « installer.sh » d’après le verbe français. Il se trouve ici sur GitHub ([installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh)) à la racine du dossier `linux-chromeos/`, ainsi qu’à la racine du paquet distribué `Nouvel-AZERTY-Linux-`version`.zip`. Selon les réglages, on peut le lancer en le cliquant ou en le double-cliquant, ou dans un terminal (./installer.sh).

Une fois lancé, le script analyse la situation et propose normalement soit d’installer ces dispositions de clavier, soit de les désinstaller.

Pour mettre à jour ces dispositions de clavier par le script, il faut lancer celui-ci deux fois afin de les désinstaller, puis de les réinstaller.

Les **redispositions de touches** sont sauvegardées lors de la désinstallation, aussi bien dans un dossier `sauvegarde/` créé à côté du script, que dans le dossier des configurations dans le dossier personnel de l’utilisateur qui effectue la mise à jour : `$HOME/.config/dispoclavier/keycodes/`. Au début de l’installation, le script propose d’utiliser le fichier sauvegardé à ces deux endroits s’il existe.

Le fichier sauvegardé à côté de ce script offre la facilité d’une personnalisation aisée avant sa réinstallation, tandis que celui dans les configurations personnelles assure la pérennité à travers les différentes mises à jour, tant du système d’exploitation que de ces dispositions de clavier.

### Installation manuelle

En cas d’incompatibilité ou de configurations logicielles particulières, l’installation manuelle est une solution de dernier recours.

1. [Compose.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/Compose.yml) : Prendre le fichier d’un seul tenant, qui se trouve aussi à la racine du dossier `Nouvel-AZERTY-Linux-[version].zip`, et l’ajouter à la fin du fichier `X11/locale/en_US.UTF-8/Compose`.
2. [dispotypes.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispotypes.c) : Prendre ce fichier et le mettre dans `/usr/share/X11/xkb/types/dispotypes`.
3. Dans `/usr/share/X11/xkb/types/complete`, ajouter `include "dispotypes"` sur une nouvelle ligne.
4. [dispocla.cpp](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispocla.cpp) : Prendre ce fichier et le mettre dans `/usr/share/X11/xkb/symbols/dispocla`.
5. [evdev-additions.xml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev-additions.xml) : Copier l’élément `<layout>` qui commence à la ligne 50 et le coller dans `/usr/share/X11/xkb/rules/evdev.xml` avant la balise `</layoutList>`.
6. Dans `/usr/share/X11/xkb/rules/evdev`, désactiver la ligne `*		*		=	+%l[2]%(v[2]):2` en l’effaçant ou en la commentant, en la remplaçant par `// * * = +%l[2]%(v[2]):2`. Cela sert à empêcher le système d’écraser le deuxième groupe vif.
7. [evdev.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev.c) : Mettre ce fichier à la place de `/usr/share/X11/xkb/keycodes/evdev` après avoir renommé celui-ci. Décommenter le cas échéant les définitions de touches souhaitées concernant Effacement arrière, AltFr et VerrCap.
8. [dispoled.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispoled.c) : Mettre ce fichier dans `/usr/share/X11/xkb/compat/dispoled`.
9. Dans `/usr/share/X11/xkb/compat/complete`, ajouter `include "dispoled"` sur une nouvelle ligne.
10. Veiller à ce que la méthode d’entrée soit XIM. Ce réglage se trouve par exemple (Ubuntu 24.04) dans `Système` > `Pays et langue` > `Système` > `Gérer les langues installées` > `Langue` > `Système de saisie au clavier` [iBus, XIM, Aucun].

Puis fermer la session et en rouvrir une. 

## Disposition de clavier par défaut

Si la disposition de clavier par défaut doit aussi être reconfigurée, ouvrir le fichier `/etc/default/keyboard` et changer les valeurs par exemple en `XKBLAYOUT="dispocla"` et `XKBVARIANT="kbfrFRs"`. Dans ce cas, on peut aussi laisser `XKBVARIANT=""` vide, car `"kbfrFRs"` est la disposition de base de ce nouvel AZERTY.

## Commutateur de dispositions de clavier

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier `Français (France)` sous le nom `Français France disposition de clavier semi-automatique` et peut être ajouté aux dispositions actives. Afin de l’activer, il est nécessaire de désactiver l’autre disposition, car [le commutateur ne fonctionne pas](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

## Vues de disposition autogénérées

Les vues de disposition se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues. Les rectangles avec un code sont des touches mortes ou des séquences définies dans le répertoire des touches mortes et des séquences Compose(.yml).

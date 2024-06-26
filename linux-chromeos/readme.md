# Un nouvel AZERTY pour Linux

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) et l’activation. Sur l’utilisation, il est vivement conseillé de se référer à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/symboles-mathematiques.pdf) est pareillement disponible en ligne.

## Alerte d’incompatibilité de Linux Mint

Linux Mint 21.3 (2024) est incompatible avec ce nouvel AZERTY, qui y est inutilisable. Plus d’informations sous le titre [### Linux Mint](#linux-mint) plus bas. Mieux vaut utiliser directement [Ubuntu](https://ubuntu.com/download/desktop), exempt de ces bogues.

## Activation sans droits d’administrateur

La version de Linux recommandée pour cet usage est [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou l’équivalent, de cette époque, des autres distributions.

Télécharger le dossier `Nouvel-AZERTY-Linux-`version`.zip` sous le titre « Assets », et suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

## Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « Nouvel-AZERTY-Linux-`version`.zip » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh). On peut aussi installer chaque fichier [manuellement](#installation-manuelle).

### Script d’installation : mode d’emploi

Le script d’installation s’appelle « installer.sh » d’après le verbe français. Il se trouve ici sur GitHub ([installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh)) à la racine du dossier `linux-chromeos/`, ainsi qu’à la racine du paquet distribué `Nouvel-AZERTY-Linux-`version`.zip`.

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande `./installer.sh` après avoir ouvert le dossier dans un terminal.

Le script commence par analyser la situation, et propose normalement soit d’installer ces dispositions de clavier, soit de les désinstaller.

Au début de l’installation, le script demande s’il faut **redisposer des touches.** Il s’agit de la touche AltFr, qui peut être redisposée sur la touche de Verrouillage des capitales, et de la touche d’Effacement arrière, qui peut être redisposée sur la touche Menu, ou sur Windows droite ou Contrôle droite.

Après la sortie d’une nouvelle version, pour **mettre à jour** ces dispositions de clavier par le script, il faut lancer celui-ci deux fois afin de les désinstaller, puis de les réinstaller.

Les **redispositions de touches** sont sauvegardées aussi bien lors de l’installation que lors de la désinstallation. Ces sauvegardes sont enregistrées dans le dossier des configurations dans le dossier personnel de l’utilisateur qui effectue la mise à jour : `$HOME/.config/dispoclavier/keycodes/`. Au moment de la désinstallation, le même fichier est sauvegardé aussi dans un dossier `sauvegarde/` créé à côté du script.

Au moment de l’installation, le script propose d’utiliser le fichier sauvegardé à ces deux endroits s’il existe.

Le fichier sauvegardé à côté de ce script offre la facilité d’une **personnalisation** aisée avant sa réinstallation, tandis que celui dans les configurations personnelles assure la pérennité à travers les différentes mises à jour, tant du système d’exploitation que de ces dispositions de clavier.

### Installation manuelle

En cas d’incompatibilité ou de configurations logicielles particulières, l’installation manuelle est une solution de dernier recours.

Par sécurité, il faut alerter, avant de suggérer de modifier manuellement des fichiers dans `/usr/share/X11/xkb/`, que le système risque d’avoir zéro tolérance sur une faute de frappe, une erreur de syntaxe ou l’absence d’un type de touche utilisé. Contrairement aux modifications dans `/usr/share/X11/locale/`, il ne suffit pas pour tester de rouvrir une application.

Un système d’exploitation avec une erreur dans XKB risque d’être inutilisable et de devoir être débogué depuis **une autre instance du système,** installée sur le même ordinateur ou chargée depuis une clé USB démarrable.

Pour faciliter ces opérations de fichiers, le plus simple est de déverrouiller le dossier `X11` par `sudo chmod --recursive 777 /usr/share/X11`, ou d’ouvrir une instance d’administrateur du navigateur de fichiers par `sudo nautilus` ou `sudo nemo`, ou quel que soit le nom de l’application.

Pour toute éventualité, la procédure d’installation est la suivante :

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

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier `Français (France)` sous le nom `Français France disposition de clavier semi-automatique` et peut être ajouté aux dispositions actives. Afin de l’activer sous une version de Linux sortie entre 2018 et 2024 (ou plus), il est nécessaire de désactiver l’autre disposition, car comme expliqué plus bas, le commutateur ne fonctionne plus.

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

## Vues de disposition

Les vues de ces dispositions dans Gnome se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues. Les rectangles avec un code sont des touches mortes ou des séquences définies dans le répertoire des touches mortes et des séquences Compose(.yml).

## Systèmes

Ces fichiers sont développés, testés et compilés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule à la fois ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3**).

### Linux Mint

Ce nouvel AZERTY est incompatible avec [Linux Mint Cinnamon 21.3 Virginia](https://www.linuxmint.com/edition.php?id=311), sorti en 2024, car il utilise la modificatrice de niveau 5 « ISO_Level5_Shift », qu’il appelle AltFr. Celle-ci est convertie en deuxième touche AltGr (« ISO_Level3_Shift ») sous Linux Mint 21.3. Ce bogue désactive toutes les ponctuations espacées, ainsi que le pavé numérique graphique disposé sur le bloc alphanumérique.

Linux Mint est aussi affecté par un autre bogue, qui transforme la bascule VerrMod en touche pour passer d’une disposition de clavier à une autre, parmi celles qui sont dans la liste du commutateur. VerrMod bascule entre « ISO_Last_Group » et « ISO_First_Group », soit entre les deux groupes de disposition de chaque touche, qui permettent de disposer les huit positions séparément pour le mode français et le mode ASCII. Cette deuxième bascule graphique, dédiée aux chiffres, permet de dédier aux lettres la bascule traditionnelle VerrMaj, désormais VerrCap.

Un troisième bogue est situé dans le compilateur, qui sous Linux Mint ne peut plus toujours lire les redéfinitions partielles de touches. Quand une touche d’une disposition incluse dans une autre disposition est partiellement redéfinie, et les autres positions sont omises ou remplacées par « NoSymbol » – qui ne signifie pas « aucun caractère », mais « pas de nouveau caractère » –, le compilateur peut effacer toute la touche et ne renseigner que les positions redéfinies. Ce bogue affecte les touches de la rangée E et met en panne des touches sur les variantes régionales et les variantes redisposées.

Un bogue supplémentaire affecte le commutateur de dispositions de clavier sous Linux Mint, qui peut être hors d’état d’activer une des dispositions de clavier de ce nouvel AZERTY. Mais ce bogue est de peu d’importance, puisque sous Linux Mint, ce nouvel AZERTY est de toute façon inutilisable. Sous Ubuntu, le commutateur est autrement bogué, mais il y est toujours possible d’activer une des dispositions de ce nouvel AZERTY, quelle qu’elle soit.

Ces bogues propres à Linux Mint ont dû être introduits au titre des modifications censées conférer à Ubuntu un air de Windows, puisqu’ils sont absents d’[Ubuntu 24.04](https://releases.ubuntu.com/noble/) et de toutes les versions antérieures. Pour éviter ces bogues, il aurait suffi de ne pas toucher au code d’XKB. L’intentionnalité suspectée vise principalement à rendre inutilisable ce nouvel AZERTY, et accessoirement à lui faire gaspiller du temps de développement. Mais le résultat conduit plutôt à décrédibiliser Linux Mint et à exposer la fragilité de ce projet et sa corruptibilité.

La solution consiste à **éviter Linux Mint** et à utiliser [Ubuntu](https://ubuntu.com/download/desktop) directement.

### Chrome OS

Quant à **Chrome OS**, il utilise certes XKB mais le fournit codé en dur, et même dans le conteneur Linux, l’image d’X11 est hors service. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks puissants. Le bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à Chrome OS.

## Extensions de fichiers

À l’usage, la plupart de ces fichiers sont sans extension. Les extensions .c, .cpp et .yml servent uniquement à la coloration syntaxique et à faciliter l’ouverture sous Windows dans un souci d’interopérabilité. L’extension `.cpp` a été choisie pour éviter `dispocla.c` (les noms « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives). De toute manière, les statistiques de langage sont désactivées.

## Note

Ce Lisez-moi est inclus dans les versions sous le nom de `Mode-d-emploi.md`.

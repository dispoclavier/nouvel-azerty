# Un nouvel AZERTY pour Linux

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) et l’[activation](#activation-sans-droits-dadministrateur). Sur l’[utilisation](#utilisation), il est vivement conseillé de se reporter à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne, ainsi qu’une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf) de la composition non mathématique.

## Alerte d’incompatibilité de Linux Mint

Sous Linux Mint 21.3 (2024), ce nouvel AZERTY fonctionne uniquement quand il est activé par xkbcomp comme indiqué sous le titre suivant, Quand il y est installé, il fonctionne partiellement. Il n’est pas inutile d’installer ce nouvel AZERTY sous Linux Mint, mais il faut prévoir, en plus, de l’activer par xkbcomp.

Plus d’informations sous le titre [Linux Mint](#linux-mint) plus bas.

## Activation sans droits d’administrateur

Télécharger le dossier `Un-nouvel-AZERTY-Linux-`version`.zip` sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

### Script d’activation : mode d’emploi

Le script d’activation « activer.sh » se trouve sur GitHub ([activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh)) à la racine du dossier `linux-chromeos/`, ainsi qu’à la racine du paquet distribué `Un-nouvel-AZERTY-Linux-`version`.zip`.

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande `./activer.sh` après avoir ouvert le dossier dans un terminal.

Ce script commence par sauvegarder la disposition de clavier actuelle, afin de pouvoir par la suite proposer de revenir à la disposition de clavier habituelle. Cela est utile pour rapidement mettre fin à un test, par la même méthode qui a mis ce test en route. Cette option était prévue dès le début quand le seul moyen était l’activation manuelle documentée dans le [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt).

Pour revenir à la disposition de clavier habituelle, on choisit l’option O ou P pour plus d’options, puis H.

Sinon, après avoir appuyé sur Entrée, on peut choisir la variante de disposition dans une liste, puis la sous-variante dans une autre liste ; mais on peut aussi abréger en appuyant chaque fois directement sur Entrée, afin d’activer la disposition de base de ce nouvel AZERTY sans redispositions de touches.

Pour finaliser l’activation, les chaînes de caractères pour touches vives et le contenu des touches mortes sont mis en place dans le dossier personnel, le cas échéant à la suite des séquences de composition existantes.

Par la suite, la disposition de clavier dernièrement utilisée parmi celles incluses dans ce nouvel AZERTY (qui inclut aussi les variantes redisposées) sera réactivée le plus facilement, après un appui sur Entrée. Ce sera la version la plus à jour disponible localement, si le script [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) est lancé depuis un paquetage téléchargé. Sinon ce sera la version dernièrement utilisée, mise en cache dans le dossier personnel, dans un sous-dossier `dispoclavier/activer/` au sein du sous-dossier caché `.config/`.

Le script d’activation propose aussi de (semi-)automatiser l’activation à l’ouverture de session selon une méthode uniformisée, utile pour compléter l’installation par l’activation, mais cette fonctionnalité est affectée par le problème mentionné ci-après.

### Bogue d’autostart avec xkbcomp

La méthode uniformisée de lancement à l’ouverture de session ne fonctionne pas pour xkbcomp. Ce bogue est documenté plus bas sous le titre [Xkbcomp](#xkbcomp).

Quand le navigateur de fichiers s’ouvre sur le script de réactivation de la dernière disposition utilisée, cela signifie que le lancement automatique d’xkbcomp a échoué et qu’il est nécessaire de le lancer manuellement.

Pour le navigateur de fichiers, dix logiciels sont pris en charge nativement, et on peut personnaliser le script pour en prendre en charge un autre.

## Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « `Un-nouvel-AZERTY-Linux-`version`.zip` » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh). On peut aussi installer chaque fichier [manuellement](#installation-manuelle).

### Script d’installation : mode d’emploi

Le script d’installation s’appelle « installer.sh » d’après le verbe français. Il se trouve sur GitHub ([installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh)) à la racine du dossier `linux-chromeos/`, ainsi qu’à la racine du paquet distribué `Un-nouvel-AZERTY-Linux-`version`.zip`.

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande `./installer.sh` après avoir ouvert le dossier dans un terminal.

Le script commence par analyser la situation, et propose normalement soit d’installer ces dispositions de clavier, soit de les mettre à jour ou de les désinstaller.

Au début de l’installation, le script demande s’il faut **redisposer des touches.** Il s’agit de la touche AltFr, qui peut être redisposée sur la touche de Verrouillage des Capitales, et de la touche d’Effacement arrière, qui peut être redisposée sur la touche Menu, ou sur Windows droite ou Contrôle droite.

Après la sortie d’une nouvelle version, pour **mettre à jour** ces dispositions de clavier par le script, il faut lancer celui-ci, appuyer sur Entrée, saisir le mot de passe administrateur et faire Entrée une dernière fois.

Les **redispositions de touches** sont sauvegardées aussi bien lors de l’installation que lors de la désinstallation et d’une mise à jour. Ces sauvegardes sont enregistrées dans le dossier des configurations dans le dossier personnel de l’utilisateur qui effectue la mise à jour : `$HOME/.config/dispoclavier/keycodes/`. Au cours de la désinstallation, le même fichier est sauvegardé aussi dans un dossier `sauvegarde/` créé à côté du script.

Au moment d’installer ou de réinstaller ces dispositions de clavier, si le script détecte un fichier à ces deux endroits, il propose de l’utiliser.

Le fichier de redisposition sauvegardé à côté de ce script offre la facilité d’une **personnalisation** aisée avant sa réinstallation, tandis que celui dans les configurations personnelles assure la pérennité des redispositions à travers les mises à jour du système d’exploitation.

### Installation manuelle

En cas d’incompatibilité ou de configurations logicielles particulières, l’installation manuelle est une solution de dernier recours.

#### Alerte de dépannage

Par sécurité, il faut alerter, avant de suggérer de modifier manuellement des fichiers dans `/usr/share/X11/xkb/`, que le système a zéro tolérance sur certaines fautes de frappe, erreurs de syntaxe et incohérences comme l’utilisation d’un type de touche non défini. Pour tester des modifications dans XKB, il ne suffit pas non plus de rouvrir une application, contrairement aux modifications dans XCompose (`/usr/share/X11/locale/`),

Ainsi, quand une erreur dans les fichiers de configuration d’XKB a rendu le système d’exploitation inutilisable, il ne peut être débogué que depuis **un(e) autre (instance du) système** dans une autre partition ou une clé USB démarrable.

#### Droits d’écriture

Pour faciliter ces opérations de fichiers, le plus simple est de déverrouiller le dossier `X11/` par la commande `sudo chmod --recursive 777 /usr/share/X11`, ou d’ouvrir une instance d’administrateur du navigateur de fichiers par `sudo `(nom de l’application), par exemple `sudo nemo` ou `sudo nautilus`.

#### L’installation pas à pas

Compte tenu de l’[alerte](#alerte-de-d%C3%A9pannage) plus haut, et pour toute éventualité, la procédure d’installation manuelle est la suivante :

1. [Compose.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/Compose.yml) : Prendre le fichier d’un seul tenant, qui se trouve aussi à la racine du dossier `Un-nouvel-AZERTY-Linux-`version`.zip`, et ajouter son contenu à la fin du fichier `X11/locale/en_US.UTF-8/Compose`.
2. [dispotypes.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispotypes.c) : Copier ce fichier vers `/usr/share/X11/xkb/types/dispotypes`.
3. Dans `/usr/share/X11/xkb/types/complete`, ajouter `include "dispotypes"` sur une nouvelle ligne.
4. [dispocla_perso.cpp](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispocla_perso.cpp) : Copier ce fichier vers `/usr/share/X11/xkb/symbols/dispocla_perso`.
5. [dispocla.cpp](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispocla.cpp) : Copier ce fichier vers `/usr/share/X11/xkb/symbols/dispocla`.
6. [evdev-additions.xml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev-additions.xml) : Copier l’élément `<layout>` qui commence à la ligne 50 et le coller dans `/usr/share/X11/xkb/rules/evdev.xml` avant la balise `</layoutList>`.
7. Dans `/usr/share/X11/xkb/rules/evdev`, désactiver la ligne `*		*		=	+%l[2]%(v[2]):2` en l’effaçant ou en la commentant, en la remplaçant par `// * * = +%l[2]%(v[2]):2`. Cela empêche le système d’écraser le deuxième groupe vif.
8. [evdev.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev.c) : Mettre ce fichier à la place de `/usr/share/X11/xkb/keycodes/evdev` après avoir renommé celui-ci. Décommenter le cas échéant les définitions de touches souhaitées concernant Effacement arrière, AltFr et VerrCap.
9. [dispoled.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispoled.c) : Copier ce fichier vers `/usr/share/X11/xkb/compat/dispoled`.
10. Dans `/usr/share/X11/xkb/compat/complete`, ajouter `include "dispoled"` sur une nouvelle ligne.
11. Veiller à ce que la méthode d’entrée soit XIM. Ce réglage se trouve par exemple (Ubuntu 24.04) dans `Système` > `Pays et langue` > `Système` > `Gérer les langues installées` > `Langue` > `Système de saisie au clavier` [iBus, XIM, Aucun]. Il peut aussi être effectué par la commande `im-config -n xim`.

Puis fermer la session et en rouvrir une.

#### Disposition de clavier par défaut

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

Les vues de ces dispositions dans Gnome se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues.

Sur les vues de disposition de ce nouvel AZERTY, sur le bloc alphabétique et la barre d’espace, le niveau 4 montre le niveau 5, c’est-à-dire les caractères disposés en AltFr, qui incluent les ponctuations non espacées et le pavé numérique graphique disposé sur le bloc alphanumérique, tandis que sur la rangée des chiffres, le niveau 4 montre réellement ce qui se trouve au niveau 4 : les positions rétrocompatibles du mode français. Car sur les touches des chiffres, le niveau 5 est identique au niveau 3 avec les chiffres, la touche moins a le symbole degré du niveau 2, et la touche plus a le symbole égal du niveau 1 du mode ASCII.

Les rectangles avec un code sont soit des touches mortes, comme la touche morte groupe « EFD0 » sur la touche [*], soit des séquences, comme les ponctuations espacées en Majuscule, ou le double zéro « EF6D » sur [B].

Ces touches mortes et ces séquences sont définies dans le répertoire des touches mortes et des séquences Compose(.yml), consultable sur GitHub en trois parties à cause d’une limitation de taille de fichier : [compose-1.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-1.yml) pour les séquences sur touches vives et les séquences de composition, [compose-2.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-2.yml) pour les touches mortes, et [compose-3.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-3.yml) pour les [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles) et les [groupes des lettres](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-lettres), qui font partie de la [touche morte groupe](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/).

## Utilisation

Ce mode d’emploi condensé ne peut pas remplacer la documentation détaillée citée [au début](#un-nouvel-azerty-pour-linux).

### Lettres

La disposition de toutes les minuscules, y compris accentuées ou avec cédille, est identique à l’AZERTY traditionnel. Les différences sont dans les touches mortes. Celle de l’accent circonflexe fonctionne optionnellement comme une touche [ê] avant [k], [l], [m], [n], [p], [q], [r], [t], [v] ; « ê » s’insère ensemble avec l’une de ces minuscules si le [e] n’est pas saisi avant. Cela fonctionne aussi en capitales, et [x] donne « êch ».

#### Verrouillage des capitales

Les majuscules qui manquent sur l’AZERTY traditionnel sont en Majuscule, ce pourquoi les chiffres pour leur part sont en AltGr. Quant aux capitales, aussi les É, È, Ç, À et Ù, elles sont toutes en Minuscule quand le clavier est en mode capitales par l’ancienne bascule Verrouillage Majuscule (VerrMaj), désormais appelée Verrouillage Capitales (VerrCap), parce qu’elle ne verrouille plus le clavier en Majuscule, mais uniquement les lettres en capitales, afin de rendre l’écriture tout-en-capitales aussi simple que l’écriture en minuscules. (C’est la manière dont fonctionnent la plupart des dispositions de clavier d’ordinateur.)

#### Touche morte groupe

Les lettres qui manquent même en minuscule, comme æ et œ, sont dans la touche morte groupe, notée « ① », disposée sur [*] en Minuscule et en AltGr, et documentée sur [cette page](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/). Répétée ou suivie d’un chiffre, la touche morte groupe peut activer 12 [groupes des lettres](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-lettres) et 12 [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles). Le o-e entrelacé est saisi par [①][o], sa majuscule par [①][O]. Dans chaque groupe, les chiffres sont aussi pris en charge en tant que caractères de base de cette touche morte. Dans les premiers groupes, quelques autres caractères fonctionnent aussi dans ce rôle.

#### Touche de composition

Deuxième touche morte générique après la touche morte groupe, la touche de composition se trouve en AltGr sur la dernière touche en haut à droite, [=]. En mode ASCII, elle est doublée à la place de la touche morte accent grave, en AltGr sur [$]. Son symbole ISO est [⎄] U+2384. Sur ce nouvel AZERTY, son symbole est le deux-barrettes [¦] U+00A6, souvent appelé barre brisée, plus facile à afficher, saisi le plus rapidement par la touche morte tréma suivie de la contre-oblique. La touche de composition offre une méthode de saisie alternative, quoique peu intéressante, pour le o-e entrelacé par [¦][o][e] ; elle est aussi le seul moyen de saisir des lettres comme « ꜳ » U+A733.

#### Touches mortes spécialisées

Plus généralement, toutes les lettres accentuées ou autrement diacritées sont dans les touches mortes, dont les deux les plus traditionnelles, l’accent circonflexe et le tréma, sont l’une à sa place historique, l’autre pareillement en Minuscule mais une touche plus loin au-dessus, sur [=], au lieu de rester en Majuscule sur la touche de l’accent circonflexe, cette place étant utilisée pour le guillemet français simple ouvrant. Mais la touche morte tréma y reste accessible en Maj + AltFr pour la rétrocompatibilité.

Les deux autres touches mortes de l’AZERTY traditionnel, qui ont fait leur entrée après l’avènement de l’AZERTY d’ordinateur, l’accent grave et le tilde, sont toujours en AltGr mais sur la touche de l’accent circonflexe pour le tilde, et sur la touche [$] pour l’accent grave, car en Minuscule, c’est la touche de la touche morte accent aigu, qui sert aussi à la saisie des [guillemets apostrophes](#guillemets-de-distanciation) doubles et simples, ensemble avec la touche morte accent circonflexe. Toutefois, pour la rétrocompatibilité, les touches mortes tilde et accent grave sont aussi sur leurs touches historiques, en Maj + AltGr en mode français, sous des formes rétrocompatibles qui émettent des symboles ASCII quand on fait suivre un appui sur la barre d’espace ou qu’on appuie deux fois sur l’une de ces touches mortes. Celles-ci sont destinées uniquement à assurer un maximum de rétrocompatibilité.

Toutes les 30 touches mortes diacritiques ou transformationnelles sont disposées en Maj + AltGr, chacune sur la touche de son équivalent en composition, sauf la touche morte grec ou cerclé sur [Y], disposée aussi en AltGr à la place de son équivalent en composition, l’arobase, en Minuscule sur [)]. Les autres touches mortes transformationnelles appliquent elles aussi des transformations aux lettres et aux chiffres plutôt que d’ajouter des diacritiques. Partiellement cela est aussi le cas des touches mortes diacritiques, comme pour la saisie des [guillemets apostrophes](#guillemets-de-distanciation). Elles sont toutes documentées sur [cette page](https://dispoclavier.com/nouvel-azerty/touches-mortes/).

### Chiffres

Les chiffres sont en Minuscule, en Majuscule pour la rétrocompatibilité, et en AltGr pour la synergie avec la touche morte « groupe » tant que le clavier est en mode ASCII par la bascule VerrMod sur la touche [²]. Sinon, en mode français, les chiffres sont en AltGr, afin de libérer les places en Majuscule pour les majuscules É, È, Ç et À et pour les tirets autres que le tiret du 6 et le tiret du 8, qui restent inchangés.

Les chiffres sont toujours aussi en AltFr, la nouvelle touche modificatrice sur la touche [><]. Pour les chiffres, AltFr fonctionne comme une deuxième touche AltGr. De plus, en AltFr, les chiffres sont aussi disposés en pavé en dessous des touches [7], [8], [9], avec le zéro sur [N], le double zéro sur [B], le point sur [P] et la virgule sur [M]. Le point et la virgule sont aussi en AltFr sur leurs touches traditionnelles quand le clavier est en mode ASCII.

En mode ASCII, les chiffres en AltFr sont complétés par les lettres hexadécimales A sur [ù], B sur [*], C sur [^], D sur [$], E sur [)] et F sur [=]. En mode français, ces six lettres sont en Maj + AltFr sur ces mêmes touches, afin que la saisie d’un chiffre hexadécimal en AltFr ne nécessite pas de basculer en mode ASCII.

Les émojis chiffres, complétés par les émojis des deux autres touches de téléphone étoile et croisillon ou dièse, sont en AltGr + AltFr sur la rangée des chiffres en mode français, ainsi qu’en Maj + AltGr + AltFr, avec la particularité que l’émoji 10 prend la place de l’émoji chiffre 0. Non toutefois en mode ASCII, où les niveaux AltGr + AltFr et Maj + AltGr sont pris par les [indices](#exposants-et-indices).

### Ponctuations

En Minuscule sur les deux premières touches après le [N], la virgule ne change pas de place, et le point est lui aussi sur sa touche traditionnelle mais en Minuscule. Sur les deux dernières touches, en mode français, les places en Minuscule sont données l’une à l’oblique sur sa touche traditionnelle, l’autre à la contre-oblique pour faciliter la saisie de diverses commandes et séquences d’échappement. En mode ASCII, le deux-points et le point-virgule redescendent en Minuscule en se permutant avec l’oblique et la contre-oblique.

#### Grandes ponctuations

En mode français, toutes les grandes ponctuations sont en Majuscule, et elles sont déjà espacées. Non espacées en mode français, elles sont en AltFr. Ainsi, le point d’interrogation est à sa place traditionnelle mais déjà espacé. Pour l’avoir non espacé, il faut appuyer sur AltFr au lieu d’appuyer sur Maj.

Le point d’exclamation quant à lui prend la place du point, afin de pouvoir laisser sa place au point-virgule. Mais le deux-points reste bien sur sa touche. Les [guillemets](#guillemets) français, au nombre de quatre — deux doubles et deux simples —, prennent les quatre places en Majuscule à gauche de la touche Entrée, les doubles aux places de [%] et [µ], les simples aux places de [¨] et [£]. Eux aussi sont en AltFr sans espace à l’intérieur, pour leur usage en allemand et dans d’autres langues.

L’espacement automatique des ponctuations en Majuscule se fait par la seule espace insécable Unicode utilisable à cet effet, l’espace fine insécable U+202F. L’autocorrection des traitements de texte, qui espace les ponctuations par l’espace insécable U+00A0, peut et doit être désactivée, avec d’autant plus de raison que l’espacement qu’elle applique [n’est pas français](#typographie) et fonctionne très mal voire pas du tout.

En cas de points d’interrogation ou d’exclamation multiples, l’espace devant le deuxième est évitée manuellement. Plutôt que de changer de touche modificatrice, on peut maintenir l’appui sur Majuscule et ajouter un appui sur AltFr.

En mode ASCII, les points d’interrogation et d’exclamation restent en Majuscule mais sans espace, tandis que le deux-points et le point-virgule redescendent en Minuscule tous les deux et laissent aux obliques leurs places en Majuscule. Ainsi la touche du deux-points se retrouve disposée à l’ancienne, tandis que la touche suivante a le point-virgule et la contre-oblique au lieu du point d’exclamation et du symbole paragraphe. En mode français, celui-ci y est toutefois en AltGr, en synergie avec les chiffres.

#### Ponctuations en haut

En mode français, les tirets du 6 et du 8 restent bien à leurs places éponymes, tandis qu’en mode ASCII, quand les chiffres sont verrouillés, ils n’y sont pas en Majuscule, mais plus facilement atteignables en Minuscule sur les touches [$] pour le tiret bas, et [*] pour le trait d’union, quand le guillemet et l’apostrophe bénéficient de facilités similaires, l’un à la place de la touche morte accent circonflexe [^], l’autre à la place du [ù].

En mode français, l’apostrophe en tant que telle reste elle aussi à sa place traditionnelle, mais elle y change de caractère pour devenir l’apostrophe courbe [’], très appréciée en français, tandis que l’apostrophe droite ['] (qu’on peut appeler « guillemet simple générique » ou « apostrophe ASCII ») prend la place du symbole égal, qui lui, est en AltFr sur cette touche.

Les parenthèses elles-mêmes sont désormais réunies en AltGr sur [D] et [F] comme « début » et « fin », sur la rangée de repos pour une saisie facile, et les crochets y sont sur [K] et [L] en synergie avec les points de suspension sur AltGr + [ù] pour faciliter la saisie des points de suspension entre crochets.

Le guillemet double générique en revanche reste inchangé en mode français, et avec lui comme caractère de base, tous les guillemets doubles typographiques autres que les guillemets chevrons sont en touches mortes, les ouvrants par accent circonflexe, les fermants par accent aigu, les ouvrants allemands à hauteur de virgule par tréma. Les réfléchis sont aussi accessibles, par accent grave. Cette méthode de saisie puissante et intuitive évite de mémoriser une multitude d’emplacements et permet une prise en charge plus complète. Les guillemets apostrophes simples en bénéficient pareillement, avec comme caractère de base l’apostrophe courbe (qui en fait partie) sur [4] ou l’apostrophe ASCII sur [=] au choix.

### Symboles ASCII

La plupart des symboles en Minuscule ou en AltGr sur les touches des chiffres y tiennent désormais des places en Majuscule + AltGr pour la rétrocompatibilité, en mode français uniquement. C’est le cas de la perluète sur Maj + AltGr + [1] parce qu’elle laisse sa place à l’exposant deux, du tilde sur [2] sous la forme de sa traditionnelle touche morte, du croisillon sur [3], de l’accolade ouvrante sur [4], du crochet ouvrant sur [5], de la barre verticale ou tube sur [6], de l’accent grave ASCII en touche morte sur [7], de la contre-oblique sur [8], du crochet fermant et de l’accolade fermante sur les deux dernières touches. Ces places sur [9] et [0] par contre sont utilisées pour disposer les parenthèses, parce que l’arobase est en Minuscule sur la touche suivante, et le circonflexe ASCII est en Majuscule + AltGr sur la touche de la touche morte accent circonflexe. 

Surtout, tous les symboles ASCII sauf la virgule et le point sont désormais disposés en AltGr sur les touches des lettres et les quatre touches de ponctuations qui leur font suite, sauf l’arobase qui reçoit une position stable en Minuscule à la place de la parenthèse fermante et permet ainsi d’utiliser sa place en AltGr sur [Y] pour une deuxième instance de la touche morte grec ou cerclé, et le guillemet double générique ou ASCII, qui garde sa place sur la touche [3"] et cède sa place en AltGr au symbole euro sur [E]. Le symbole dollar lui aussi a une place prédéfinie sur AltGr + [S].

Viennent ensuite tous les symboles ASCII appariés, parenthèses et chevrons sur la gauche, crochets et accolades sur la droite, ces dernières sur [I] et [O] pour respecter l’anatomie de la main, les crochets en dessous sur [K] et [L] pour la cohérence et la synergie avec les points de suspension sur AltGr + [ù], les parenthèses en regard sur [D] et [F], sous le symbole euro sur [E], à la suite du symbole dollar sur [S], et au-dessus des symboles inférieur/supérieur ou crochets pointus, qui sont disposés sur [C] et [V] à la suite de l’oblique sur [W] et de l’astérisque sur [X], pour les synergies requises en langages informatiques, au niveau des balises en SGML/HTML/XML et des commentaires (en blocs) C/C++/CSS/PHP.

D’autres symboles ASCII sont disposés sur les places vacantes avec des mnémoniques alphabétiques ou graphiques : la perluète [&] sur [P], le croisillon [#] sur [Q], le symbole pour cent [%] sur [Z], le circonflexe ASCII [^] sur [A], le tilde [~] sur [T], la contre-oblique [\\] sur [R], la barre verticale ou tuyau [|] sur [M] parce que c’est l’équivalent en composition de la touche morte macron, le symbole égal [=] sur [B], l’accent grave ASCII [`] sur [N], le tiret-moins [-] sur [G], le signe plus [+] sur [H], et enfin le tiret bas [_] sur [J], et l’apostrophe ASCII ['] sur [U].

Pour les quatre grandes ponctuations après la touche du [N], le point d’interrogation, le point d’exclamation, le deux-points et le point-virgule, la disposition varie légèrement entre les modes français et ASCII. En mode français, toutes sauf le point-virgule sont aussi en AltGr sur la touche où elles sont en Majuscule avec espace, et en AltFr sans espace. Le point-virgule cède sa place en AltGr au symbole paragraphe, afin que celui-ci soit en synergie avec les chiffres, pour la rétrocompatibilité avec le symbole paragraphe sur l’AZERTY traditionnel, où il est pareillement en synergie avec les chiffres, mais en Majuscule. En mode ASCII, toutes les quatre sont en AltGr, deux sont en Minuscule et en AltFr : le deux-points et le point-virgule ; et deux sont en Majuscule : les points d’interrogation et d’exclamation.

### Exposants et indices

L’exposant deux de l’AZERTY traditionnel change de touche suite à la réaffectation de sa touche traditionnelle [²] à la bascule VerrMod. Sauf sur les variantes pour le breton, pour la Polynésie française et pour l’Afrique francophone, l’exposant 2 est sur la touche [1&], et l’exposant 3 vient le rejoindre en Majuscule afin de couvrir toutes les utilisations d’unités de mesure au carré et au cube.

Au-delà du carré et du cube, les exposants de tous les dix chiffres sont en Maj + AltFr sur les touches des chiffres.

En mode capitales, l’indice 2 et l’indice 3 prennent la place des expoants 2 et 3 sur la touche [1&] pour simplifier l’écriture des deux formules chimiques les plus importantes de notre époque, celles du CO₂ et du CH₃, soit celles des deux gaz à effet de serre les plus puissants et les plus préoccupants. Si le dioxyde de carbone n’est plus à présenter, le méthane quant à lui est plus connu sous son nom français, assez bref pour l’emporter sur sa formule, de sorte que l’indice 3 vient compléter l’indice 2 davantage pour la cohérence et la logique que pour l’utilité.

Les indices de tous les dix chiffres sont présents uniquement en mode ASCII, mais alors aussi bien en Maj + AltGr qu’en AltGr + AltFr, car en mode français, le niveau Maj + AltGr des touches de la rangée des chiffres est pris par les caractères rétrocompatibles, et le niveau AltGr + AltFr n’est pas très pratique sur ces touches et sert à redonder les émojis chiffres avec le « 0️⃣ », non le nombre « 🔟 », sur la touche du zéro.

Ces exposants et indices servaient autrefois à composer des fractions ordinaires au-delà des quelques fractions précomposées d’Unicode, tant que la barre de fraction n’était pas encore implémentée comme elle était conçue, ou dans les logiciels où elle ne l’est toujours pas. Cela permet de coder en dur toutes les fractions ordinaires, au-delà des fractions précomposées qui sont en composition. Les fractions ordinaires s’écrivent à l’aide de la barre de fraction U+2044 qui est sur [/] en synergie avec les indices en AltGr + AltFr, et en mode ASCII, avec les exposants en Maj + AltFr (en mode français, c’est le deux-points sans espace).

En matière d’exposants, les minuscules des lettres de l’alphabet de base sont aussi prises en charge sur touches vives, en Maj + AltFr, chacune sur la touche de sa lettre de base. car ces exposants servent d’indicateurs d’abréviation, à commencer par les indicateurs ordinaux « ᵈ, ᵉ, ʳ, ˢ », dont le plus fréquent, « ᵉ », est aussi en AltGr sur [)] à la suite des chiffres et en synergie avec ceux-ci. Cela fonctionne aussi pour les lettres diacritées, car les accents peuvent être ajoutés même sur des exposants, pour peu que la police de caractères les prenne en charge. Après l’appui sur la touche morte correspondante, il ne manque plus que d’appuyer sur la barre d’espace.

### Barre d’espace

L’espace normale en Minuscule y est aussi en Majuscule comme sur l’AZERTY traditionnel, pour la synergie avec les grandes ponctuations espacées, tandis que les deux [espaces insécables](#espaces) les plus utiles sont en AltFr pour la fine, et en AltGr pour la justifiante, l’espace insécable tout court, qui dans les traitements de texte n’est justifiante que dans Word 2013, qui disparaît souvent au copier-coller, et qui dysfonctionne dans de nombreux logiciels, mais qui est néanmoins indispensable en français aussi, là où l’espace fine insécable ne convient pas.

Aucune espace importante n’est disposée sur Maj + AltGr + Espace, où se trouve l’espace nulle, aussi appelée césure conditionnelle U+200B, qui est utile pour fragmenter les URL une fois converties en hyperlien, pour leur affichage dans les navigateurs non conformes à Unicode qui [spécifie](https://www.unicode.org/reports/tr14/#SY) qu’à partir d’une certaine longueur, l’oblique doit fonctionner comme le trait d’union.

### Autres symboles

La plupart des symboles sont dans les [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles), mais un certain nombre sont aussi ou uniquement sur touches vives comme documenté ici.

Les 1 114 symboles et diacritiques mathématiques d’Unicode sont dans la touche de composition et documentés sur [cette page](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/) ([PDF](https://dispoclavier.com/doc/symboles-mathematiques.pdf))

Les infobulles de la [vue interactive](https://dispoclavier.com/nouvel-azerty/#vue-interactive) informent sur tous les détails de la disposition de ce nouvel AZERTY en cours de documentation.

#### Symboles de l’AZERTY

Les symboles pour cent et micro, le symbole livre et la touche morte tréma cèdent leurs places aux guillemets français, mais en mode français, ils sont tous en AltGr + AltFr sur leurs touches historiques. La nouvelle place du symbole pour cent est sur [Z] en AltGr et en AltFr, dans le cadre de la disposition des [symboles ASCII](#symboles-ascii) ; le symbole livre est en AltFr sur [R] pour l’accessibilité, et en AltGr + AltFr + [L] pour l’intuitivité, comme le symbole micro est sur AltGr + AltFr + [M].

#### Exposants et indices additionnels

En mode ASCII, quand les chiffres en indice sont en Maj + AltGr, ces indices sont complétés par les signes moins et plus en indice sur les touches moins et plus, nommées d’après leur fonctionnalité en Contrôle pour les raccourcis clavier, le « ₋ » sur la touche [)], le « ₊ » sur la touche [=]. S’y ajoutent le symbole égal en indice « ₌ » sur [$], et les parenthèses en indice « ₍ » sur [ù] et « ₎ » sur [*]. Sur [^], le tiret bas, symbole de l’indiciation, vient compléter l’ensemble. Pareil pour les chiffres en exposant en Maj + AltFr, toujours en mode ASCII, avec le circonflexe ASCII en tant que symbole de l’exponentiation.

#### Opérateurs arithmétiques

En AltFr, les chiffres sont accompagnés d’opérateurs non-ASCII et de symboles monétaires supplémentaires sur les touches dont les symboles ASCII ne sont pas nécessaires en AltFr : les symboles de multiplication et de division sur [C] et [V] dans la prolongation de l’oblique sur [W] et de l’astérisque sur [X], le signe moins sur [T] au-dessus du tiret-moins ASCII sur [G], le symbole livre sur [R] comme Royaume-Uni à côté du symbole euro, et le symbole yen sur [Y].

##### Opérateur point

L’opérateur point « ⋅ » U+22C5 est sur AltGr + AltFr + [X], et aussi dans le groupe 1 du deux-points, et dans le groupe 4 du point.

##### Barre de fraction

La barre de fraction U+2044 est sur AltGr + AltFr + [/]. Entre des chiffres ordinaires, elle déclenche la mise en forme de fraction ordinaire.

La partie entière peut être séparée par le signe plus invisible sur AltGr + AltFr + [H]. D’autres caractères, invisibles de préférence, comme l’antiliant sur AltGr + AltFr + [W], fonctionnent aussi, sans être destinés à cet usage.

##### Symbole rapport

Contrairement à beaucoup d’autres doublons inutiles pour lesquels même Unicode ne donne pas de bonne raison, le symbole rapport « ∶ » ne ressemble que superficiellement à un deux-points. Voici le symbole rapport et le deux-points : « ∶: ».

Car selon les polices, soit les deux points sont plus rapprochés, soit le symbole est surélevé et plus haut afin de s’aligner sur les chiffres (« 2∶3 »), non sur les minuscules comme le deux-points (« a:b »).

C’est pourquoi le symbole rapport a relayé le symbole racine carrée sur AltGr + AltFr + [R] à la sortie de la version 4.1.0, vu que les racines carrée, cubique et quatrième sont dans les groupes 2, 3 et 4 de l’oblique inverse sur [R].

### Séquences

La possibilité qu’a ce nouvel AZERTY d’émettre des séquences est utilisée aussi pour des séquences autres que les ponctuations avec espace fine insécable sur AltFr plus l’une des huit touches entre N et Majuscule droite ou entre P, M et Entrée. Le pavé numérique graphique dispose ainsi d’un double zéro sur AltFr + [B], qui figure aussi sur les vues du clavier. D’autres besoins sont couverts le plus mnémoniquement possible.

#### Abréviation numéro

Écrite avec un o en exposant, souvent émulé à l’aide du symbole degré, l’abréviation « numéro » est facile à saisir grâce à sa disposition comme séquence tout-en-un, avec son espace fine insécable, sur AltGr + AltFr + [N], et sa majuscule, en ajoutant Maj, sur Maj + AltGr + AltFr + [N].

#### Trigramme breton

Le trigramme breton « cʼh » avec lettre apostrophe est sur AltGr + AltFr + [A] afin de se trouver sur la première touche alphabétique, à l’instar de ce qui est fait sur le CʼHWERTY, la dispositon de clavier conçue pour le breton. Sa majuscule « Cʼh » est sur Maj + AltGr + AltFr + [A], tandis que sa capitale s’insère à la place de la minuscule quand les capitales sont verrouillées. Ce n’est pas qu’il manquerait la lettre apostrophe, dans le groupe 1 de l’apostrophe.

#### Espaces composées

L’espace suivie du gluon qui est le caractère régulier pour empêcher un retour à la ligne automatique : cette séquence est sur Maj + AltFr + [Espace], pour insérer une espace insécable justifiante dans LibreOffice Writer parce que l’espace insécable sur AltGr + Espace y est à chasse fixe pour espacer les ponctuations en français.

L’espace suivie de l’indicateur d’ordre des octets est sur AltGr + AltFr + [Espace], pour insérer une espace insécable justifiante sous les anciennes versions de Windows, où les polices ne contenaient pas le gluon, dans Microsoft Word parce que l’espace insécable y est justifiante uniquement dans Word 2013.

L’entité nommée de l’espace insécable « &‍nbsp; » est sur Maj + AltGr + AltFr + [Espace], et aussi sur Maj + AltGr + [Espace] en mode ASCII.

En mode ASCII, la référence de caractère numérique de l’espace fine insécable « &‍#x202F; » est sur Maj + AltFr + [Espace] et sur AltGr + AltFr + [Espace].

#### Séquences d’échappement

Les entités nommées des symboles « < » et « > », soit « &‍lt; » et « &‍gt; », sont sur AltGr + AltFr plus la touche où ils sont en AltGr : [C] ou [V].

Les entités nommées des symboles « " » et « ' », soit « &‍quot; » et « &‍apos; » (moins utilisée), sont sur Maj + AltGr + AltFr plus la touche où ils sont ou seraient en AltGr : [E] ou [U].

#### Références de caractères

Le préfixe « &‍#x » des références de caractères hexadécimales en HTML/XML est sur AltGr + AltFr + [K]. En mode ASCII, il est aussi sur la touche de la virgule en Maj + AltFr + [?,].

En mode ASCII, le préfixe « &‍# » des références de caractères décimales en HTML/XML est sur la touche du point en Maj + AltFr + [.;].

Le préfixe des codes hexadécimaux des caractères Unicode « U+ », utilisé en écriture courante, est sur AltGr + AltFr + [U].

Le préfixe « \u{ » est sur AltGr + AltFr + [I], qui est aussi la touche de l’accolade ouvrante.

### Émojis

Une sélection d’émojis documentée dans [ce tableau](https://dispoclavier.com/nouvel-azerty/#tableau-emojis)est disposée sur les places de touches vives qui restent, parce que cela doit fonctionner aussi sous Windows, système mal conçu, dysfonctionnel, dont les dispositions de clavier ont été programmées par un seul développeur, de qui les erreurs de conception ont durablement dégradé l’utilisabilité des ordinateurs de la majorité. Alors que tous les émojis codés sur deux ou trois octets à part les sinogrammes sont pris en charge par touches mortes dans les 12 [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles), seuls quelques émoji codés sur quatre octets, triés sur le volet, sont pris en charge, sur touches vives uniquement.

## Systèmes

Ces fichiers sont développés, testés et fusionnés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3** (datant de 2024)).

### Linux Mint

Ce nouvel AZERTY ne peut pas être installé normalement sous [Linux Mint Cinnamon 21.3 Virginia](https://www.linuxmint.com/edition.php?id=311), sorti en 2024 et bogué de façon protéiforme au regard des dispositions de clavier, tantôt comme décrit ci-après, tantôt avec des variations. La solution consiste à utiliser uniquement xkbcomp comme indiqué sous le titre [Activation sans droits d’administrateur](#activation-sans-droits-dadministrateur).

#### Bogue d’AltFr

Ce nouvel AZERTY utilise la modificatrice de niveau 5 `ISO_Level5_Shift`, qui s’y appelle « AltFr ». Or sous Linux Mint 21.3, celle-ci est parfois convertie en touche AltGr, qui en tant qu’`ISO_Level3_Shift` est bien distincte.

Quand il est en cours d’exécution, ce bogue désactive les ponctuations non espacées, le pavé numérique graphique disposé sur le bloc alphanumérique, l’alphabet minuscule en exposant sur touches vives ; en somme, tout ou partie des fonctionnalités disposées aux niveaux 5 à 8.

#### Bogue de VerrMod

Linux Mint est parfois aussi affecté par un bogue qui transforme la bascule « VerrMod » en touche pour passer d’une disposition de clavier à une autre, parmi celles qui sont dans le commutateur.

Sur ce nouvel AZERTY, « VerrMod » bascule entre `ISO_Last_Group` et `ISO_First_Group`, soit entre les deux groupes de disposition de chaque touche, qui permettent de disposer les huit positions séparément pour le mode français et le mode ASCII. Cette deuxième bascule graphique, dédiée aux chiffres, permet de dédier aux lettres la bascule traditionnelle VerrMaj, désormais VerrCap.

Sous Linux Mint, parfois on ne peut pas verrouiller les chiffres, et le mode ASCII est alors inaccessible.

#### Bogue du compilateur

Un troisième bogue est situé dans le compilateur, qui sous Linux Mint ne peut plus toujours lire les redéfinitions partielles de touches. Quand une touche d’une disposition incluse dans une autre disposition est partiellement redéfinie – les autres positions sont omises ou remplacées par `NoSymbol`, qui ne signifie pas « aucun caractère », mais « pas de nouveau caractère » –, le compilateur peut effacer toute la touche et ne renseigner que les positions redéfinies. Ce bogue affecte tout ou partie des touches de la rangée E et met en panne des touches sur les variantes régionales et les variantes redisposées. Il serait facile à contourner, mais vu les autres bogues, cela serait une perte de temps inutile.

#### Bogue du commutateur

Un bogue supplémentaire sous Linux Mint affecte le commutateur de dispositions de clavier, qui peut être hors d’état d’activer une des dispositions de clavier de ce nouvel AZERTY. Sous Ubuntu, le commutateur est autrement bogué, mais il y est toujours possible d’activer une des dispositions de ce nouvel AZERTY, quelle qu’elle soit.

#### Conclusions

La solution consiste à compléter l’installation par l’**utilisation d’xkbcomp**, présenté [ci-dessous](#xkbcomp), comme indiqué sous le titre [Activation sans droits d’administrateur](#activation-sans-droits-dadministrateur).

L’installation peut même être remplacée par l’activation, puisque l’installation n’aboutit pas à une disposition de clavier 100 % fonctionnelle. Mais en cas d’utilisation de variantes redisposées, une disposition défectueuse vaut mieux que pas de disposition du tout.

Les bogues propres à Linux Mint ont dû être introduits au titre des modifications censées conférer à Ubuntu un air de Windows, puisqu’ils sont absents d’[Ubuntu 24.04](https://releases.ubuntu.com/noble/) et antérieures.

### Xkbcomp

Xkbcomp, qui s’écrit tout en minuscules (« xkbcomp »), est un utilitaire de dispositions de clavier [documenté par IBM](https://www.ibm.com/docs/en/aix/7.3?topic=x-xkbcomp-command) avec une interface utilisateur en ligne de commande, invoqué par la commande « xkbcomp ».

L’intérêt d’xkbcomp est de pouvoir activer la partie disposition des touches d’une disposition de clavier à partir d’un seul fichier, sans droits d’administrateur. Les chaînes de caractères pour touches vives et le contenu des touches mortes ne sont pas pris en charge par xkbcomp, étant dans un autre fichier. Celui-ci peut aussi être placé dans le dossier personnel, afin de rendre la disposition de clavier opérationnelle, toujours sans droits d’administrateur.

Xkbcomp a le grand avantage de fonctionner à 100 % aussi sous Linux Mint. Cette caractéristique rend xkbcomp indispensable sous Linux Mint, qui a la particularité de mettre partiellement en panne les dispositions de clavier installées, comme documenté ci-dessus sous le titre [Linux Mint](#linux-mint). Sous Linux Mint, l’installation doit être complétée par l’activation, qui a pour effet de déboguer la disposition de clavier installée.

#### Automatisation

La nécessité d’invoquer xkbcomp à chaque ouverture de session sous Linux Mint rend l’automatisation de ce processus souhaitable. Or la procédure standard consistant à lancer un script à l’ouverture de session ne fonctionne pas et aboutit à l’affichage du script dans le navigateur de fichiers pour son lancement manuel, qui lui, fonctionne.

Les alternatives pour lancer un script au démarrage sont foison, mais elles conviennent uniquement sur les ordinateurs unipersonnels ou en cas d’accord sur la disposition de clavier utilisée.

L’automatisation proposée par le script [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) est cohérente avec xkbcomp, qui active une disposition de clavier pour une session.

Après avoir mis en place l’automatisation, le script [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) alerte que l’activation est seulement « censée être automatisée, et en principe, dès l’ouverture de session, la disposition dernièrement utilisée devrait être activée. Mais cela ne fonctionne que pour lancer la commande dans un terminal, voire, accéder au script dans un navigateur de fichiers. Ces deux solutions de dépannage sont aussi prises en charge. Quand vous verrez le navigateur de fichiers à l’ouverture de session, cela signifie que deux tentatives d’activation ont déjà échoué, une silencieuse et une dans le terminal. Dans le navigateur de fichiers, le même script attendra que vous le lanciez manuellement. Ce script ouvrira un terminal, dans lequel il vous confirmera l’activation réussie. »

Quant au bogue inconnu qui empêche xkbcomp de fonctionner sur invocation par un script lancé par [autostart](https://specifications.freedesktop.org/autostart-spec/latest/), il est peut-être expliqué par un faisceau de témoignages concordants trouvés [ici](https://forums.linuxmint.com/viewtopic.php?p=2373855#p2373855), [ici](https://forums.linuxmint.com/viewtopic.php?p=2376225&sid=0901bdee365911c4549d6dda5362842f#p2376225), [ici](https://forums.linuxmint.com/viewtopic.php?p=2368840#p2368840), [ici](https://forums.linuxmint.com/viewtopic.php?t=414342), [ici](https://ubuntuforums.org/showthread.php?t=2482076), [ici](https://askubuntu.com/questions/437584/xkbcomp-command-at-startup-using-xinitrc), [ici](https://superuser.com/questions/644521/linux-mint-mate-use-xkbcomp-to-load-a-keyboard-layout-on-startup), [ici](https://forum.beyond3d.com/threads/linux-is-a-pile-of-shit.60616/), [ici](https://itvision.altervista.org/why.linux.is.not.ready.for.the.desktop.current.html) et [ici](https://castingoutnines.wordpress.com/2009/07/17/why-i-am-not-a-linux-user-any-more/), mais il faut aussi noter que la [spécification d’Autostart](https://specifications.freedesktop.org/autostart-spec/latest/) est toujours une « ébauche » en chantier, puisque la [version courante](https://specifications.freedesktop.org/autostart-spec/latest/) est la [version 0.5](https://specifications.freedesktop.org/autostart-spec/0.5/) datant de 2006.

### ChromeOS

Quant à **ChromeOS**, il utilise certes XKB mais le fournit compilé en dur, et même dans le conteneur Linux, l’image d’X11 est hors service. Une erreur de conception que Google a échoué à pallier : Au lieu de permettre de recompiler XKB, Google demande à ajouter les dispositions de clavier dans un langage qui n’est pas adapté à ce type de service.

Sous ChromeOS, ajouter une disposition de clavier consiste à installer une extension dans le navigateur Chrome. Il existe deux cas de figure : Soit cette extension active une ou plusieurs dispositions de clavier distribuées avec Linux. Soit elle définit en JavaScript tout ou partie des fonctionnalités du clavier.

Or, utiliser une disposition de clavier ajoutée sous forme d’extension de Chrome est impossible, parce qu’au lieu de compiler la disposition comme sous Linux, ChromeOS l’exécute dans l’interpréteur JavaScript de Chrome, qui fait planter même un chromebook haut de gamme conçu pour un usage professionnel, dès la première demi-ligne de saisie de texte, même purement ASCII.

Ce bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutables sous ChromeOS.

Pour mettre le comble, Google ne met pas à jour sa bibliothèque de dispositions de clavier compilées en dur et fournies avec ChromeOS, restées figées à une époque plus loin dans le passé que 2019. Rien de tout ce qui a été ajouté ou modifié dans XKB depuis cinq ans voire plus n’est disponible sous ChromeOS.

Aussi les chromebooks sont-ils invendables à moins d’être bradés.

## Typographie

Ces quelques notes visent seulement à clarifier le [mode d’emploi condensé](#utilisation) de ce nouvel AZERTY, car au-delà de quelques notions communes, la typographie française est extrêmement hétéroclite et difficile à documenter.

### Espaces

Sous les systèmes d’exploitation qui prennent en charge le jeu de caractères Unicode, le français utilise trois espaces :

* L’espace normale U+0020, aussi appelée espace mot ou espace-mot, qui est sécable et justifiante (elle peut s’étirer quand le texte est aligné aussi bien à gauche qu’à droite) ;
* L’espace insécable U+00A0, ou espace mot insécable, qui a la même largeur qu’une espace normale, et qui est justifiante dans les navigateurs et dans Word 2013, mais pas dans les autres traitements de texte ;
* L’espace fine insécable U+202F, aussi appelée espace fine ou la fine (qui en principe est toujours insécable), à chasse fixe.

#### Nouvelle école de typographie française

L’espace fine (insécable U+202F) sert à espacer toutes les grandes ponctuations, ou les ponctuations doubles plus les guillemets chevrons simples. Selon [Le Robert](https://dictionnaire.lerobert.com/guide/ponctuation-et-espace), même le « deux-points est précédé d'une espace fine et suivi d'une espace normale ».

Cette nouvelle école ne s’est pas formellement constituée, mais claude72 l’a mentionnée déjà en 2005 sur [forums.macg.co](https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119).

#### Risques de confusion

Une autre espace fine d’Unicode est présente depuis le début au point de code U+2009, mais elle n’est pas directement utilisable en français, car elle est sécable, contrairement à l’espace chiffre tabulaire U+2007, qui est la seule espace insécable dans cette plage d’espaces allant de U+2000 à U+200A, où toutes les espaces autres que U+2000 et U+2001 étaient conçues comme insécables. Qu’elles ne le soient pas est une [irrégularité](https://dispoclavier.com/nouvel-azerty/#note-2250-2-a) ([archive](https://web.archive.org/web/20240524173357/https://dispoclavier.com/nouvel-azerty/#note-2250-2-a)).

Un autre nom de l’espace fine insécable, « espace insécable étroite », a été officialisé par calque sur son identifiant Unicode, mais il est corrigé dans les spécifications de base du Standard Unicode au chapitre 6 dans la [section consacrée aux caractères d’espacement](https://www.unicode.org/versions/Unicode15.0.0/ch06.pdf#G1834), à l’[alinéa qui parle de l’espace fine insécable](https://www.unicode.org/versions/Unicode15.0.0/ch06.pdf#page=13&zoom=100,0,340), avec le terme d’« espace fine insécable » en français dans le texte anglais, et pareillement dans l’[Annexe sur la coupure de ligne](https://www.unicode.org/reports/tr14/tr14-51.html#GL). L’identifiant a été choisi de façon à ne pas faire référence à l’espace fine U+2009, prévue pour être insécable, et qui ne doit son existence en tant qu’espace sécable qu’à un acte de vandalisme non documenté mais visiblement commis avant le lancement du jeu de caractères universel.

#### Espacement vieille école

Si l’espacement vieille école est préféré, il peut être réalisé manuellement grâce à la synergie de l’espace insécable avec le deux-points en AltGr. Car en plus d’être disposé en Majuscule avec espace et en AltFr sans espace, le deux-points sans espace est aussi en AltGr, pour la synergie avec les chiffres dans le format d’heure « 12:34:56 », qui est aussi facile à saisir en AltFr, et aussi pour la synergie avec l’espace insécable, qui en mode français est sur AltGr + Espace.

À part le deux-points, aucune autre ponctuation ne devrait être composée à l’ancienne, car les guillemets, qui selon le *Lexique des règles typographiques en usage à l’Imprimerie nationale* sont accompagnés d’une **espace mot insécable** (« espace mots insécable »), sont composés avec une **espace fine** (« espace fine insécable ») dans ce même *Lexique.*

### Guillemets

Les guillemets apostrophes et les guillemets doubles génériques « " » sur la touche [3"] sont collés aux mots, sans aucune espace à l’intérieur. La pratique contraire utilise les guillemets doubles génériques à la place des guillemets chevrons, absents de certaines dispositions de clavier, d’où le quiproquo.

À l’intérieur des guillemets chevrons doubles, l’« espace insécable » décrite sur [Le Robert](https://dictionnaire.lerobert.com/guide/ponctuation-et-espace) est bien l’espace fine, étant la seule espace insécable citée sur cette page web du Robert.

Quelques autres problèmes laissés en suspens sur [Le Robert](https://dictionnaire.lerobert.com/guide/guillemets) peuvent être résolus comme documenté dans la suite.

#### Guillemets de second niveau

Grâce au fait que les guillemets chevrons existent aussi en version simple, l’inclusion d’une citation dans une autre citation ne nécessite plus le recours aux « guillemets anglais », ni la répétition des guillemets chevrons doubles, avec omission du deuxième d’affilée en cas de collision de fins de citation (comme recommandé dans le *Lexique*).

Quitte à se résigner à l’emploi de « guillemets anglais », autant encastrer les guillemets à l’anglaise, ou à l’américaine, mais à la française. À l’anglaise au sens où les guillemets de second (ou deuxième) niveau sont simples si les guillemets de premier niveau (ou rang) sont doubles, comme c’est le cas en écrivant à l’américaine. À la française au sens où les guillemets sont des guillemets chevrons.

En mode français, ce nouvel AZERTY a les guillemets chevrons simples en Majuscule sur les touches [^] et [$], au-dessus des touches [ù] et [*] où les guillemets chevrons doubles sont disposés en Majuscule. Ces quatre guillemets sont déjà espacés à l’aide de la fine. Sur les mêmes touches en AltFr, les mêmes guillemets sont sans espace.

#### Guillemets en langues voisines

En allemand d’Allemagne et d’Autriche, où les guillemets chevrons servent aussi, les doubles pour les citations de premier niveau, les simples pour les citations de second niveau, leur saisie se fait sur les mêmes touches mais en AltFr et dans l’autre sens, en commençant par le guillemet pointant vers la fin « » » sur [*], ou « › » sur [$], et en finissant par le guillemet pointant vers le début « « » sur [ù], ou « ‹ » sur [^].

(On ne peut pas appeler ces guillemets « ouvrants » ou « fermants » sauf en précisant « français », car s’ils sont ouvrants ou fermants dépend de la langue. On ne peut pas les appeler « gauches » ou « droits » non plus, ni même « pointant vers la gauche » ou « pointant vers la droite », car dans toutes les écritures de droite à gauche, ces guillemets sont réfléchis. Par contre on peut les appeler « croissants » ou « décroissants » par analogie avec les symboles « inférieur à » ou « supérieur à », réfléchis eux aussi, si l’on veut éviter le recours aux termes « pointant vers le début » et « pointant vers la fin ».)

Contrairement à l’allemand d’Allemagne et d’Autriche, l’allemand de Suisse utilise tous ces guillemets dans le sens français, toujours les doubles pour les citations de premier niveau, les simples pour les citations de second niveau, et toujours sans espace fine à l’intérieur, comme ils sont disposés en AltFr. Par contre, en français de Suisse, les mêmes guillemets s’utilisent avec une fine à l’intérieur, comme ils sont disposés en Majuscule sur les mêmes touches. Depuis 2015, la Suisse romande applique aux ponctuations les mêmes règles d’espacement que la France.

#### Guillemets de distanciation

L’usage des guillemets chevrons simples pour les citations incluses permet de réserver les « guillemets anglais » aux usages où les guillemets ne signalent pas une citation, mais une distanciation. Dans ce sens, les guillemets sont aussi appelés « guillemets d’ironie », bien que l’ironie ne soit pas la seule connotation qu’ils véhiculent. Aussi s’appellent-ils en anglais « scare quotes ».

Plutôt que les guillemets doubles génériques de la touche [3"], les guillemets de distanciation et les guillemets en anglais – que ce soit en anglais britannique ou en anglais américain – sont les guillemets apostrophes doubles (distanciation en français, premier niveau en anglais américain) ou simples (premier niveau en anglais britannique), dont les ouvrants en français et en anglais sont dans la touche morte accent circonflexe, et les fermants, dans la touche morte accent aigu sur la touche à côté, [$].

En retour, ce système de guillemets de distanciation permet de réserver les guillemets chevrons aux citations. À la clé, les textes gagnent en univocité, et partant, en [clarté](https://www.ledevoir.com/societe/488139/mises-aux-points-les-antiguillemets-comme-symboles-de-la-postverite).

## Notes techniques

### Usage du liant

Les entités HTML documentées dans ce fichier à cause de leur disposition sur le clavier ne sont pas échappées par « &‍amp; », afin d’en garantir la lisibilité directe non seulement en affichage Markdown, mais aussi en texte brut. À la place, elles sont désactivées par l’insertion d’un liant après la perluète. Le caractère souvent préféré dans ce rôle est l’antiliant, disposé sur AltGr + AltFr + [W] à cause de son utilisation pour empêcher les ligatures typographiques intempestives. Mais ce nouvel AZERTY offre le choix entre l’antiliant U+200C sur AltGr + AltFr + [W], le liant U+200D sur AltGr + AltFr + [Q], et le signe plus invisible U+2064 sur AltGr + AltFr + [H]. Les deux premiers sont aussi dans la touche morte groupe, l’antiliant dans le groupe 10 du circonflexe ASCII sur [A], le liant dans le même groupe du symbole pour cent sur [Z]. Il y a aussi le gluon dans le même groupe du tiret du 6 sur [G]. Le signe plus invisible est aussi pris en charge par composition « ¦&+ » dans le cadre des symboles mathématiques.

L’essentiel pour désactiver une séquence quelle qu’elle soit est d’insérer un caractère invisible qui ne soit pas l’espace nulle.

### Extensions de fichiers

À l’usage, la plupart des fichiers pour Linux de ce nouvel AZERTY sont sans extension. Les extensions .c, .cpp et .yml servent uniquement à la coloration syntaxique et à faciliter l’ouverture sous Windows dans un souci d’interopérabilité. L’extension `.cpp` a été choisie pour éviter `dispocla.c`. (Les noms « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives.) Dans ce dépôt, les statistiques de langage sont de toute manière désactivées.

### Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier `linux-chromeos/` où il se trouve. Mais c’est sous le nom de `Mode-d-emploi.md` qu’il est inclus dans le dossier « `Un-nouvel-AZERTY-Linux-`version`.zip` ».

# Un nouvel AZERTY pour Linux

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) et l’[activation](#activation-sans-droits-dadministrateur). Sur l’[utilisation](#utilisation), il est vivement conseillé de se référer à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/) assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/symboles-mathematiques.pdf) est pareillement disponible en ligne.

## Alerte d’incompatibilité de Linux Mint

Linux Mint 21.3 (2024) est incompatible avec ce nouvel AZERTY, qui y est en grande partie inutilisable. Plus d’informations sous le titre [Linux Mint](#linux-mint) plus bas. Mieux vaut opter directement pour [Ubuntu](https://ubuntu.com/download/desktop), exempt de ces bogues.

## Activation sans droits d’administrateur

La version de Linux recommandée pour cet usage est [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou l’équivalent, de cette époque, des autres distributions.

Télécharger le dossier `Nouvel-AZERTY-Linux-`version`.zip` sous le titre « Assets », et suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

## Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « `Nouvel-AZERTY-Linux-`version`.zip` » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh). On peut aussi installer chaque fichier [manuellement](#installation-manuelle).

### Script d’installation : mode d’emploi

Le script d’installation s’appelle « installer.sh » d’après le verbe français. Il se trouve ici sur GitHub ([installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh)) à la racine du dossier `linux-chromeos/`, ainsi qu’à la racine du paquet distribué `Nouvel-AZERTY-Linux-`version`.zip`.

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande `./installer.sh` après avoir ouvert le dossier dans un terminal.

Le script commence par analyser la situation, et propose normalement soit d’installer ces dispositions de clavier, soit de les désinstaller.

Au début de l’installation, le script demande s’il faut **redisposer des touches.** Il s’agit de la touche AltFr, qui peut être redisposée sur la touche de Verrouillage des Capitales, et de la touche d’Effacement arrière, qui peut être redisposée sur la touche Menu, ou sur Windows droite ou Contrôle droite.

Après la sortie d’une nouvelle version, pour **mettre à jour** ces dispositions de clavier par le script, il faut lancer celui-ci deux fois afin de les désinstaller, puis de les réinstaller.

Les **redispositions de touches** sont sauvegardées aussi bien lors de l’installation que lors de la désinstallation. Ces sauvegardes sont enregistrées dans le dossier des configurations dans le dossier personnel de l’utilisateur qui effectue la mise à jour : `$HOME/.config/dispoclavier/keycodes/`. Au cours de la désinstallation, le même fichier est sauvegardé aussi dans un dossier `sauvegarde/` créé à côté du script.

Au moment d’installer ou de réinstaller ces dispositions de clavier, si le script détecte un fichier à ces deux endroits, il propose de l’utiliser.

Le fichier de redisposition sauvegardé à côté de ce script offre la facilité d’une **personnalisation** aisée avant sa réinstallation, tandis que celui dans les configurations personnelles assure la pérennité des redispositions à travers les mises à jour du système d’exploitation.

### Installation manuelle

En cas d’incompatibilité ou de configurations logicielles particulières, l’installation manuelle est une solution de dernier recours.

#### Alerte de dépannage

Par sécurité, il faut alerter, avant de suggérer de modifier manuellement des fichiers dans `/usr/share/X11/xkb/`, que le système risque d’avoir zéro tolérance sur une faute de frappe, une erreur de syntaxe ou l’absence d’un type de touche utilisé. Contrairement aux modifications dans `/usr/share/X11/locale/`, il ne suffit pas pour tester de rouvrir une application.

Un système d’exploitation avec une erreur dans XKB risque d’être inutilisable et de devoir être débogué depuis **une autre instance du système,** installée sur le même ordinateur ou chargée depuis une clé USB démarrable.

#### Droits d’écriture

Pour faciliter ces opérations de fichiers, le plus simple est de déverrouiller le dossier `X11/` par la commande `sudo chmod --recursive 777 /usr/share/X11`, ou d’ouvrir une instance d’administrateur du navigateur de fichiers par `sudo `(nom de l’application), par exemple `sudo nautilus` ou `sudo nemo`.

#### L’installation pas à pas

Pour toute éventualité, la procédure d’installation est la suivante :

1. [Compose.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/Compose.yml) : Prendre le fichier d’un seul tenant, qui se trouve aussi à la racine du dossier `Nouvel-AZERTY-Linux-`version`.zip`, et ajouter son contenu à la fin du fichier `X11/locale/en_US.UTF-8/Compose`.
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

Sur les vues de disposition de ce nouvel AZERTY, sur le bloc alphabétique et la barre d’espace, le niveau 4 montre le niveau 5, c’est-à-dire les caractères disposés en AltFr, qui incluent les ponctuations espacées et le pavé numérique graphique disposé sur le bloc alphanumérique, tandis que sur la rangée des chiffres, le niveau 4 montre réellement ce qui se trouve au niveau 4 : les positions rétrocompatibles du mode français. Car sur les touches des chiffres, le niveau 5 est identique au niveau 3 avec les chiffres, la touche moins a le symbole degré du niveau 2, et la touche plus a le symbole égal du niveau 1 du mode ASCII.

Les rectangles avec un code sont soit des touches mortes, comme la sélectrice de groupe « EFD0 » sur la touche [*], soit des séquences, comme le double zéro « EF6D » sur [B].

Ces touches mortes et ces séquences sont définies dans le répertoire des touches mortes et des séquences Compose(.yml), consultable sur GitHub en trois parties à cause d’une limitation de taille de fichier : [compose-1.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-1.yml) pour les séquences sur touches vives et les séquences de composition, [compose-2.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-2.yml) pour les touches mortes, et [compose-3.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-3.yml) pour les groupes des symboles et les groupes des lettres, qui font partie de la touche morte sélectrice de groupe.

## Utilisation

Ce mode d’emploi condensé ne peut pas remplacer la documentation détaillée citée [au début](#un-nouvel-azerty-pour-linux).

### Lettres

La disposition de toutes les minuscules, y compris accentuées ou avec cédille, est rigoureusement identique à l’AZERTY traditionnel. Les différences sont dans les touches mortes. Celle de l’accent circonflexe fonctionne optionnellement comme une touche [ê] avant k, l, m, n, p, q, r, t, v ; « ê » s’insère ensemble avec l’une de ces minuscules. Hormis sous Windows, cela fonctionne aussi en capitales, et x donne « êch ».

#### Verrouillage des capitales

Les majuscules qui manquent sur l’AZERTY traditionnel sont en Majuscule, ce pourquoi les chiffres à leur tour sont en AltGr. Les capitales pour leur part, aussi les É, È, Ç, À et Ù, sont toutes en Minuscule quand le clavier est en mode capitales par l’ancienne bascule Verrouillage Majuscule (VerrMaj), désormais appelée Verrouillage Capitales (VerrCap), parce qu’elle ne verrouille plus le clavier en Majuscule, mais uniquement les lettres en capitales, afin de rendre l’écriture tout-en-capitales aussi simple que l’écriture en minuscules. (La plupart des dispositions de clavier d’ordinateur fonctionnent ainsi.)

#### Sélectrice de groupe

Les lettres qui manquent même en minuscule, comme æ et œ, sont dans la touche morte sélectrice de groupe, appelée « groupe », notée « ① », disposée sur [*] en Minuscule et en AltGr, et documentée sur [cette page](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/). Répétée ou suivie d’un chiffre, la touche de groupe peut activer 12 groupes des lettres et 12 groupes des symboles. Le o-e entrelacé est saisi par [①][o], sa majuscule par [①][O]. Les chiffres et quelques autres caractères sont aussi pris en charge.

#### Touches mortes spécialisées

Plus généralement, toutes les lettres accentuées ou autrement diacritées sont dans les touches mortes, dont les deux les plus traditionnelles, l’accent circonflexe et le tréma, sont l’une à sa place historique, l’autre pareillement en Minuscule mais une touche plus loin au-dessus, sur [=], au lieu de rester en Majuscule sur la touche de l’accent circonflexe, cette place étant utilisée pour le guillemet français simple ouvrant. Mais la touche morte tréma y reste accessible en Maj + AltFr pour la rétrocompatibilité.

Les deux autres touches mortes de l’AZERTY traditionnel, qui ont fait leur entrée après l’avènement de l’AZERTY d’ordinateur, l’accent grave et le tilde, sont toujours en AltGr mais sur la touche de l’accent circonflexe pour le tilde, et sur la touche [$] pour l’accent grave, car en Minuscule, c’est la touche de la touche morte accent aigu, qui sert aussi à la saisie des [guillemets apostrophes](#guillemets-de-distanciation) doubles et simples, ensemble avec la touche morte accent circonflexe. Toutefois, pour la rétrocompatibilité, les touches mortes tilde et accent grave sont aussi sur leurs touches historiques, en Maj + AltGr en mode français, sous des formes rétrocompatibles qui émettent des symboles ASCII quand on fait suivre un appui sur la barre d’espace ou qu’on appuie deux fois sur l’une de ces touches mortes. Celles-ci sont destinées uniquement à assurer un maximum de rétrocompatibilité.

Toutes les 30 touches mortes diacritiques ou transformationnelles sont disposées en Maj + AltGr, chacune sur la touche de son équivalent en composition, sauf la touche morte grec ou cerclé sur [Y], disposée aussi en AltGr à la place de son équivalent en composition, l’arobase, en Minuscule sur [)]. Les autres touches mortes transformationnelles appliquent elles aussi des transformations aux lettres et aux chiffres plutôt que d’ajouter des diacritiques. Partiellement cela est aussi le cas des touches mortes diacritiques, comme pour la saisie des [guillemets apostrophes](#guillemets-de-distanciation). Elles sont toutes documentées sur [cette page](https://dispoclavier.com/nouvel-azerty/touches-mortes/).

La touche morte de composition, deuxième touche morte générique après la sélectrice de groupe, se trouve en AltGr sur la dernière touche en haut à droite, [=]. En mode ASCII, elle est doublée à la place de la touche morte accent grave, en AltGr sur [$]. Son symbole ISO est [⎄] U+2384. Sur ce nouvel AZERTY, son symbole est la barre brisée [¦] U+00A6, plus facile à afficher, saisie le plus rapidement par la touche morte tréma suivie de la contre-oblique. La touche de composition offre une méthode de saisie alternative, quoique peu intéressante, pour le o-e entrelacé par [¦][o][e] ; elle est aussi le seul moyen de saisir des lettres comme « ꜳ » U+A733 ; mais elle permet surtout de saisir les 1 114 symboles et diacritiques mathématiques pris en charge par ce nouvel AZERTY et documentés sur [cette page](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/) ([PDF](https://dispoclavier.com/doc/symboles-mathematiques.pdf)).

### Chiffres

Les chiffres sont en Minuscule, en Majuscule pour la rétrocompatibilité, et en AltGr pour la synergie avec la touche morte « groupe » tant que le clavier est en mode ASCII par la bascule VerrMod sur la touche [²]. Sinon, en mode français, les chiffres sont en AltGr, afin de libérer les places en Majuscule pour les majuscules É, È, Ç et À et pour les tirets autres que le tiret du 6 et le tiret du 8, qui restent inchangés.

Les chiffres sont toujours aussi en AltFr, la nouvelle touche modificatrice sur la touche [<>]. Pour les chiffres, AltFr fonctionne comme une deuxième touche AltGr. De plus, en AltFr, les chiffres sont aussi disposés en pavé en dessous des touches [7], [8], [9], avec le zéro sur [N], le double zéro sur [B], le point sur [P] et la virgule sur [M]. Le point et la virgule sont aussi en AltFr sur leurs touches traditionnelles quand le clavier est en mode ASCII.

En mode ASCII, les chiffres en AltFr sont complétés par les lettres hexadécimales A sur [ù], B sur [*], C sur [^], D sur [$], E sur [)] et F sur [=]. En mode français, ces six lettres sont en AltGr + AltFr sur ces mêmes touches, afin que la saisie d’un chiffre hexadécimal en AltFr ne nécessite pas de basculer en mode ASCII.

Les émojis chiffres, complétés par les émojis des deux autres touches de téléphone étoile et croisillon ou dièse, sont en Maj + AltFr sur la rangée des chiffres en mode français, ainsi qu’en Maj + AltGr + AltFr, avec la particularité que l’émoji 10 prend la place de l’émoji chiffre 0. Non toutefois en mode ASCII, où le niveau Maj + AltFr est pris par les [indices](#exposants-et-indices).

### Ponctuations

En Minuscule sur les deux premières touches après le [N], la virgule ne change pas de place, et le point est lui aussi sur sa touche traditionnelle mais en Minuscule. Sur les deux dernières touches, en mode français, les places en Minuscule sont données l’une à l’oblique sur sa touche traditionnelle, l’autre à la contre-oblique pour faciliter la saisie de diverses commandes et séquences d’échappement. En mode ASCII, le deux-points et le point-virgule redescendent en Minuscule en se permutant avec l’oblique et la contre-oblique.

#### Grandes ponctuations

En mode français, toutes les grandes ponctuations sont en Majuscule, à l’instar du point d’interrogation, qui est la seule grande ponctuation à ne pas changer de place, ou à ne pas faire son entrée sur le clavier. Le point d’exclamation prend la place du point, afin de pouvoir laisser sa place au point-virgule. Mais le deux-points reste bien sur sa touche. Les [guillemets](#guillemets) français, au nombre de quatre (deux doubles et deux simples), prennent les quatre places en Majuscule à gauche de la touche Entrée, les doubles aux places de [%] et [µ], les simples aux places de [¨] et [£].

Toujours en mode français, toutes les huit grandes ponctuations sont aussi en AltFr, soit presque en Majuscule à une touche près, AltFr étant la nouvelle touche modificatrice sur la touche [<>]. Comme toutes ces grandes ponctuations sont disposées dans la moitié droite du clavier, leur saisie en AltFr demande encore moins d’effort à la main gauche que la saisie des mêmes ponctuations en Majuscule. Et contrairement à ces dernières, les ponctuations en AltFr sont déjà espacées comme il faut, par le seul caractère d’espacement Unicode fonctionnel et interopérable, l’espace fine insécable U+202F. L’autocorrection des traitements de texte, qui espace les ponctuations par l’espace insécable U+00A0, peut et doit être désactivée, avec d’autant plus de raison que l’espacement qu’elle applique [n’est pas français](#typographie) et fonctionne très mal voire pas du tout.

En cas de points d’interrogation ou d’exclamation multiples, l’espace devant le deuxième est évitée manuellement. Plutôt que de changer de touche modificatrice, on peut maintenir l’appui sur AltFr et ajouter un appui sur Majuscule, soit après avoir commencé par actionner AltFr de l’annulaire, soit en appuyant sur Majuscule droite.

En mode ASCII, si les points d’interrogation et d’exclamation restent en Majuscule, tel n’est pas le cas du deux-points ni du point-virgule, qui redescendent en Minuscule tous les deux et laissent aux obliques leurs places en Majuscule. Ainsi la touche du deux-points se retrouve disposée à l’ancienne, tandis que la touche suivante a le point-virgule et la contre-oblique au lieu du point d’exclamation et du symbole paragraphe. En mode français, celui-ci y est toutefois en AltGr, en synergie avec les chiffres.

#### Ponctuations en haut

En mode français, les tirets du 6 et du 8 restent bien à leurs places éponymes, tandis qu’en mode ASCII, quand les chiffres sont verrouillés, ils n’y sont pas en Majuscule, mais plus facilement atteignables en Minuscule sur les touches [$] pour le tiret bas, et [*] pour le trait d’union, quand le guillemet et l’apostrophe bénéficient de facilités similaires, l’un sur la touche [^], l’autre sur [ù].

En mode français, l’apostrophe en tant que telle reste elle aussi à sa place traditionnelle, mais elle y change de caractère pour devenir l’apostrophe courbe [’], très appréciée en français, tandis que l’apostrophe droite ['] (qu’on peut appeler « guillemet simple générique » ou « apostrophe ASCII ») prend place sur la touche suivante au lieu de la parenthèse ouvrante.

Les parenthèses elles-mêmes sont désormais réunies en AltGr sur [D] et [F] comme « début » et « fin », sur la rangée de repos pour une saisie très facile, et les crochets y sont sur [K] et [L] en synergie avec les points de suspension sur AltGr + [ù] pour faciliter la saisie des points de suspension entre crochets.

Le guillemet double générique en revanche reste inchangé en mode français, et avec lui comme caractère de base, tous les guillemets doubles typographiques autres que les guillemets chevrons sont en touches mortes, les ouvrants par accent circonflexe, les fermants par accent aigu, les allemands par tréma (et les réfléchis par accent grave). Cette méthode de saisie est puissante et intuitive, car elle évite de mémoriser une multitude d’emplacements et permet une prise en charge plus complète. Les guillemets apostrophes en bénéficient pareillement, avec comme caractère de base l’apostrophe courbe (qui en fait partie) sur [4] ou l’apostrophe ASCII sur [5] au choix.

### Symboles ASCII

La plupart des symboles en Minuscule ou en AltGr sur les touches des chiffres y tiennent désormais des places en Majuscule + AltGr pour la rétrocompatibilité, en mode français uniquement. C’est le cas de la perluète sur Maj + AltGr + [1] parce qu’elle laisse sa place à l’exposant deux, du tilde sur [2] sous la forme de sa traditionnelle touche morte, du croisillon sur [3], de l’accolade ouvrante sur [4], du crochet ouvrant sur [5], de la barre verticale ou tube sur [6], de l’accent grave ASCII en touche morte sur [7], de la contre-oblique sur [8], du crochet fermant et de l’accolade fermante sur les deux dernières touches. Ces places sur [9] et [0] par contre sont utilisées pour disposer les parenthèses, parce que l’arobase est en Minuscule sur la touche suivante, et le circonflexe ASCII est en Majuscule + AltGr sur la touche de la touche morte accent circonflexe. 

Surtout, tous les symboles ASCII sauf la virgule et le point sont désormais disposés en AltGr sur les touches des lettres et les quatre touches de ponctuations qui leur font suite, sauf l’arobase qui reçoit une position stable en Minuscule à la place de la parenthèse fermante et permet ainsi d’utiliser sa place en AltGr sur [Y] pour une deuxième instance de la touche morte grec ou cerclé, et le guillemet double générique ou ASCII, qui garde sa place sur la touche du [3] et cède sa place en AltGr au symbole euro sur [E]. Le symbole dollar lui aussi a une place prédéfinie sur AltGr + [S].

Viennent ensuite tous les symboles ASCII appariés, parenthèses et chevrons sur la gauche, crochets et accolades sur la droite, ces dernières sur [I] et [O] pour respecter l’anatomie de la main droite, les crochets en dessous sur [K] et [L] pour la cohérence et la synergie avec les points de suspension sur AltGr + [ù], les parenthèses en regard sur [D] et [F] à la suite du [$], sous le [€], et au-dessus des [<] et [>] qui sur [C] et [V] sont disposés à la suite de l’oblique sur [W] et de l’astérisque sur [X] pour les synergies requises en langages informatiques.

D’autres symboles ASCII sont disposés sur les places vacantes avec des mnémoniques alphabétiques ou graphiques : la perluète [&] sur [P], le croisillon [#] sur [Q], le symbole pour cent [%] sur [Z], le circonflexe ASCII [^] sur [A], le tilde [~] sur [T], la contre-oblique [\\] sur [R], la barre verticale ou tuyau [|] sur [M] parce que c’est l’équivalent en composition de la touche morte macron, le symbole égal [=] sur [B], l’accent grave ASCII [`] sur [N], le tiret-moins [-] sur [G], le signe plus [+] sur [H], et enfin le tiret bas [_] sur [J], et l’apostrophe ASCII ['] sur [U].

Pour les quatre grandes ponctuations après la touche du [N], le point d’interrogation, le point d’exclamation, le deux-points et le point-virgule, la disposition varie légèrement entre les modes français et ASCII. En mode ASCII, chacune est aussi en AltGr sur la touche où elle est en Majuscule. En mode français, le point-virgule cède sa place en AltGr au symbole paragraphe, afin que celui-ci soit en synergie avec les chiffres, pour la rétrocompatibilité avec le symbole paragraphe sur l’AZERTY traditionnel, où il est pareillement en synergie avec les chiffres, mais en Majuscule.

### Exposants et indices

L’exposant deux de l’AZERTY traditionnel change de touche suite à l’utilisation de sa touche [²] pour la bascule VerrMod. Sauf sur les variantes pour le breton, pour la Polynésie française et pour l’Afrique francophone, l’exposant 2 est sur la touche du [1], et l’exposant 3 vient le rejoindre en Majuscule afin de couvrir toutes les utilisations d’unités de mesure au carré et au cube.

Au-delà du carré et du cube, les exposants de tous les dix chiffres sont en AltGr + AltFr sur les touches des chiffres, et les chiffres en indice y sont en Maj + AltFr. En mode ASCII, les exposants sont aussi en Maj + AltGr pour une saisie plus facile, aux dépens des positions rétrocompatibles, présentes uniquement en mode français. Cela permet d’écrire simplement toutes les fractions ordinaires, au-delà des fractions précomposées en composition, en intercalant la barre de fraction U+2044 qui est aussi bien sur [Q] en Maj + AltFr en synergie avec les indices, que sur [/] en synergie avec les exposants en AltGr + AltFr, et avec les indices en Maj + AltFr (ceci uniquement en mode ASCII, car en mode français, c’est le deux-points sans espace).

Alors que les exposants de toutes les minuscules servent d’indicateurs d’abréviation, à commencer par les indicateurs ordinaux « ᵈ, ᵉ, ʳ, ˢ », seul le plus fréquent, « ᵉ », est en AltGr sur [)] à la suite des chiffres et en synergie avec ceux-ci. Mais toutes les minuscules en exposant sont en AltGr + AltFr, chacun sur la touche de sa lettre de base. Les accents peuvent être ajoutés en appuyant sur une touche morte et ensuite sur la barre d’espace. L’accent sera placé parfaitement sur le ᵉ pour peu que la police de caractères le prenne en charge conformément au modèle de codage d’Unicode, qui vaut aussi bien pour les lettres de base que pour leurs exposants et indices.

### Autres symboles

Les symboles pour cent [%] et micro [µ], le symbole livre [£] et la touche morte tréma [¨] cèdent leurs places aux guillemets français, mais en mode français, ils sont tous en Maj + AltFr sur leurs touches historiques. Sur leurs nouvelles places, ces symboles sont bien plus accessibles. Ainsi le [symbole ASCII](#symboles-ascii) pour cent est sur [Z] en AltGr et en AltFr ; le symbole livre est en AltFr sur [R] pour l’accessibilité, et en Maj + AltFr + [L] pour l’intuitivité ; et le symbole micro est sur Maj + AltFr + [F] et sur Maj + AltFr + [M] dans la même logique.

En mode ASCII, quand ce sont les chiffres en indice qui sont en Maj + AltFr, ces indices sont complétés par les signes moins et plus en indice sur les touches moins et plus (nommées d’après leur fonctionnalité en Contrôle pour les raccourcis clavier), le « ₋ » sur la touche [)], le « ₊ » sur la touche [=]. S’y ajoutent le symbole égal en indice « ₌ » sur [$], et les parenthèses en indice « ₍ » sur [ù] et « ₎ » sur [*]. Sur [^], le tiret bas, symbole de l’indiciation, vient clore la sélection. Avec les chiffres en exposant en Maj + AltGr et en AltGr + AltFr, toujours en mode ASCII, on a les mêmes en exposant, avec le circonflexe ASCII, symbole de l’exponentiation.

En AltFr, les chiffres sont accompagnés d’opérateurs non-ASCII et de symboles monétaires supplémentaires sur les touches dont les symboles ASCII ne sont pas nécessaires en AltFr : les symboles de multiplication et de division sur [C] et [V] dans la prolongation de l’oblique sur [W] et de l’astérisque sur [X], le signe moins sur [T] au-dessus du tiret-moins ASCII sur [G], le symbole livre sur [R] comme Royaume-Uni à côté du symbole euro, et le symbole yen sur [Y].

Les infobulles sur la [vue interactive](https://dispoclavier.com/nouvel-azerty/#nouvel-azerty) informent sur tous les détails de la disposition de ce nouvel AZERTY en cours de documentation.

### Émojis

Une sélection d’émojis documentée dans [ce tableau](https://dispoclavier.com/nouvel-azerty/#tableau-emojis)est disposée sur les places de touches vives qui restent.

## Systèmes

Ces fichiers sont développés, testés et compilés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3** (datant de 2024)).

### Linux Mint

Ce nouvel AZERTY est incompatible avec [Linux Mint Cinnamon 21.3 Virginia](https://www.linuxmint.com/edition.php?id=311), sorti en 2024, car il utilise la modificatrice de niveau 5 `ISO_Level5_Shift`, qu’il appelle « AltFr ». Or sous Linux Mint 21.3, celle-ci est convertie en touche AltGr, qui en tant que `ISO_Level3_Shift` est bien distincte. Ce bogue désactive les ponctuations espacées, le pavé numérique graphique disposé sur le bloc alphanumérique, l’alphabet minuscule en exposant sur touches vives ; en somme, toutes les fonctionnalités disposées aux niveaux 5 à 8.

Linux Mint est aussi affecté par un bogue qui transforme la bascule « VerrMod » en touche pour passer d’une disposition de clavier à une autre, parmi celles qui sont dans le commutateur. Sur ce nouvel AZERTY, « VerrMod » bascule entre `ISO_Last_Group` et `ISO_First_Group`, soit entre les deux groupes de disposition de chaque touche, qui permettent de disposer les huit positions séparément pour le mode français et le mode ASCII. Cette deuxième bascule graphique, dédiée aux chiffres, permet de dédier aux lettres la bascule traditionnelle VerrMaj, désormais VerrCap. Sous Linux Mint, on ne peut pas verrouiller les chiffres, et le mode ASCII est inaccessible.

Un troisième bogue est situé dans le compilateur, qui sous Linux Mint ne peut plus toujours lire les redéfinitions partielles de touches. Quand une touche d’une disposition incluse dans une autre disposition est partiellement redéfinie, les autres positions sont omises ou remplacées par `NoSymbol` – qui ne signifie pas « aucun caractère », mais « pas de nouveau caractère » –, le compilateur peut effacer toute la touche et ne renseigner que les positions redéfinies. Ce bogue affecte les touches de la rangée E et met en panne des touches sur les variantes régionales et les variantes redisposées. Il serait facile à contourner, mais vu les autres bogues, cela serait une perte de temps inutile.

Un bogue supplémentaire sous Linux Mint affecte le commutateur de dispositions de clavier, qui peut être hors d’état d’activer une des dispositions de clavier de ce nouvel AZERTY. Mais ce bogue est de peu d’importance, puisque sous Linux Mint, ce nouvel AZERTY est de toute façon inutilisable. Sous Ubuntu, le commutateur est autrement bogué, mais il y est toujours possible d’activer une des dispositions de ce nouvel AZERTY, quelle qu’elle soit.

Les bogues propres à Linux Mint ont dû être introduits au titre des modifications censées conférer à Ubuntu un air de Windows, puisqu’ils sont absents d’[Ubuntu 24.04](https://releases.ubuntu.com/noble/) et de toutes les versions antérieures. Pour les éviter, il aurait suffi de ne pas toucher au code d’XKB. L’intentionnalité suspectée vise principalement à rendre inutilisable ce nouvel AZERTY sous Linux Mint, et accessoirement à lui faire gaspiller du temps de développement. Mais le résultat conduit plutôt à décrédibiliser Linux Mint et à exposer la fragilité du projet et sa corruptibilité. La solution consiste à **éviter Linux Mint** et à installer [Ubuntu](https://ubuntu.com/download/desktop) directement.

### ChromeOS

Quant à **ChromeOS**, il utilise certes XKB mais le fournit codé en dur, et même dans le conteneur Linux, l’image d’X11 est hors service.

Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible, parce qu’au lieu de compiler la disposition comme sous Linux, ChromeOS l’exécute dans l’interpréteur JavaScript de Chrome, qui fait planter même un chromebook puissant après la première demi-ligne de saisie.

Ce bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à ChromeOS.

## Typographie

Ces quelques notes ne visent qu’à clarifier le [mode d’emploi condensé](#utilisation).

### Espaces

Sous les systèmes d’exploitation qui prennent en charge le jeu de caractères Unicode, le français utilise trois espaces :

* L’espace normale U+0020, aussi appelée espace mot ou espace-mot, qui est sécable et justifiante (elle peut s’étirer quand le texte est aligné aussi bien à gauche qu’à droite) ;
* L’espace insécable U+00A0, ou espace mot insécable, qui a la même largeur qu’une espace normale, et qui est justifiante dans les navigateurs et dans Word 2013, mais pas dans les autres traitements de texte ;
* L’espace fine insécable U+202F, aussi appelée espace fine ou la fine (qui en principe est toujours insécable), à chasse fixe.

C’est cette fine qui sert à espacer toutes les grandes ponctuations, ou les ponctuations doubles plus les guillemets chevrons simples. Selon [Le Robert](https://dictionnaire.lerobert.com/guide/ponctuation-et-espace), même le « deux-points est précédé d'une espace fine et suivi d'une espace normale ». C’est la nouvelle école de typographie française, qui ne s’est pas formellement constituée, mais que claude72 cite déjà en 2005 sur [forums.macg.co](https://forums.macg.co/threads/typo-caracteres-capitales-accentues.25739/page-5#post-3151119).

L’autre espace fine d’Unicode est présente depuis le début au point de code U+2009, mais elle n’est pas directement utilisable en français, car elle est sécable, contrairement à l’espace chiffre tabulaire U+2007, qui est la seule espace insécable dans cette plage d’espaces qui va de U+2000 à U+200A et où toutes les espaces autres que U+2000 et U+2001 étaient conçues comme insécables. Qu’elles ne le soient pas est une [irrégularité](https://dispoclavier.com/nouvel-azerty/#note-2250-2-a) ([archive](https://web.archive.org/web/20240524173357/https://dispoclavier.com/nouvel-azerty/#note-2250-2-a)).

Un autre nom de l’espace fine insécable, « espace insécable étroite », a été officialisé par calque sur son identifiant Unicode, mais il est corrigé dans les spécifications de base du Standard Unicode au chapitre 6 dans la [section consacrée aux caractères d’espacement](https://www.unicode.org/versions/Unicode15.0.0/ch06.pdf#G1834), à l’[alinéa qui parle de l’espace fine insécable](https://www.unicode.org/versions/Unicode15.0.0/ch06.pdf#page=13&zoom=100,0,340), avec le terme d’« espace fine insécable » en français dans le texte anglais, et pareillement dans l’[Annexe sur la coupure de ligne](https://www.unicode.org/reports/tr14/tr14-51.html#GL). L’identifiant a été choisi de façon à ne pas faire référence à l’espace fine U+2009, prévue pour être insécable, et qui ne doit son existence en tant qu’espace sécable qu’à un acte de vandalisme, qui n’est pas documenté mais qui a visiblement été commis avant la publication du jeu de caractères universel.

#### Espacement vieille école

Si l’espacement vieille école est préféré, il peut être réalisé manuellement grâce à la synergie de l’espace insécable avec le deux-points en AltGr. Car en plus d’être disposé en Majuscule, le deux-points est aussi en AltGr, pour la synergie avec les chiffres dans le format d’heure « 12:34:56 » (qui en mode ASCII est facile à faire aussi en AltFr), mais aussi pour la synergie avec l’espace insécable, qui en mode français est sur AltGr + Espace.

À part le deux-points, aucune autre ponctuation ne devrait être composée à l’ancienne, car les guillemets, qui selon le *Lexique* de l’Imprimerie nationale sont accompagnés d’une **espace mot insécable** (« espace mots insécable »), sont composés avec une **espace fine** (« espace fine insécable ») dans ce même *Lexique des règles typographiques en usage à l’Imprimerie nationale.*

### Guillemets

Les guillemets apostrophes et les guillemets doubles génériques (["] sur la touche du [3]) sont collés aux mots, sans aucune espace à l’intérieur. La pratique contraire utilise ces derniers à la place des guillemets chevrons, absents de certaines dispositions de clavier, d’où le quiproquo.

À l’intérieur des guillemets chevrons doubles, l’« espace insécable » décrite sur [Le Robert](https://dictionnaire.lerobert.com/guide/ponctuation-et-espace) est bien l’espace fine, étant la seule espace insécable citée sur cette page web du Robert.

Quelques autres problèmes laissés en suspens sur [Le Robert](https://dictionnaire.lerobert.com/guide/guillemets) peuvent être résolus comme documenté dans la suite.

#### Guillemets de second niveau

Grâce au fait que les guillemets chevrons existent aussi en version simple, l’inclusion d’une citation dans une autre citation ne nécessite plus le recours aux « guillemets anglais », ni la répétition des guillemets chevrons doubles, avec omission du deuxième d’affilée en cas de collision de fins de citation (comme recommandé dans le *Lexique*).

Quitte à se résigner à l’emploi de « guillemets anglais », autant encastrer les guillemets à l’anglaise, ou à l’américaine, mais à la française. À l’anglaise au sens où les guillemets de second (ou deuxième) niveau sont simples si les guillemets de premier niveau (ou rang) sont doubles, comme c’est le cas en écrivant à l’américaine. À la française au sens où les guillemets sont des guillemets chevrons.

En mode français, ce nouvel AZERTY a les guillemets chevrons simples en Majuscule sur les touches [^] et [$], au-dessus des touches [ù] et [*] où les guillemets chevrons doubles sont disposés en Majuscule. Sur les mêmes touches en AltFr, les mêmes guillemets sont espacés à l’intérieur à l’aide de la fine.

#### Guillemets en langues voisines

Comme les mêmes guillemets servent aussi en allemand d’Allemagne et d’Autriche, les doubles pour les citations de premier niveau, les simples pour les citations de second niveau, leur saisie se fait en Majuscule sur les mêmes touches mais dans l’autre sens, en commençant par le guillemet pointant vers la fin [»] sur [*] ou [›] sur [$], et en finissant par le guillemet pointant vers le début [«] sur [ù] ou [‹] sur [^].

(On ne peut pas appeler ces guillemets « ouvrants » ou « fermants » sauf en précisant « français », car s’ils sont ouvrants ou fermants dépend de la langue. On ne peut pas les appeler « gauches » ou « droits » non plus, ni même « pointant vers la gauche » ou « pointant vers la droite », car dans toutes les écritures de droite à gauche, ces guillemets sont réfléchis. Par contre on peut les appeler « croissants » ou « décroissants » par analogie avec les symboles « inférieur à » [<] ou « supérieur à » [>] (réfléchis eux aussi), si l’on veut éviter le recours aux termes « pointant vers le début » et « pointant vers la fin ».)

Contrairement à l’allemand d’Allemagne et d’Autriche, l’allemand de Suisse utilise tous ces guillemets dans le sens français, toujours les doubles pour les citations de premier niveau, les simples pour les citations de second niveau, et toujours sans espace fine à l’intérieur, à saisir donc en Majuscule (et en mode français). Par contre, en français de Suisse, les mêmes guillemets s’utilisent avec une fine à l’intérieur, comme ils sont disposés en AltFr sur les mêmes touches, car depuis 2015, la Suisse romande applique aux ponctuations exactement les mêmes règles d’espacement que la France.

#### Guillemets de distanciation

L’usage des guillemets chevrons simples pour les citations incluses permet de réserver les « guillemets anglais » aux usages où les guillemets ne signalent pas une citation, mais une distanciation. Dans ce sens, les guillemets sont aussi appelés « guillemets d’ironie », bien que l’ironie ne soit pas la seule connotation véhiculée par ces guillemets, qui en anglais s’appellent avec justesse « scare quotes ».

Plutôt que les guillemets doubles génériques de la touche du [3], les guillemets de distanciation et les guillemets en anglais sont les guillemets apostrophes doubles ou simples, dont les ouvrants sont dans la touche morte accent circonflexe, inchangée sur ce nouvel AZERTY en mode français, et les fermants, dans la touche morte accent aigu sur la touche à côté, [$].

En retour, ce système de guillemets de distanciation permet de réserver les guillemets chevrons aux citations. À la clé, les textes gagnent en univocité, et partant, en [clarté](https://www.ledevoir.com/societe/488139/mises-aux-points-les-antiguillemets-comme-symboles-de-la-postverite).

## Extensions de fichiers

À l’usage, la plupart de ces fichiers sont sans extension. Les extensions .c, .cpp et .yml servent uniquement à la coloration syntaxique et à faciliter l’ouverture sous Windows dans un souci d’interopérabilité. L’extension `.cpp` a été choisie pour éviter `dispocla.c` (les noms « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives). De toute manière, les statistiques de langage sont désactivées.

## Note

Ce Lisez-moi est inclus dans les versions sous le nom de `Mode-d-emploi.md`.

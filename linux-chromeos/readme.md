# Un nouvel AZERTY pour Linux

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) et l’[activation](#activation-sans-droits-dadministrateur). Sur l’[utilisation](#utilisation), il est vivement conseillé de se reporter au [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md) ainsi qu’à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne, ainsi qu’une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf) de la composition non mathématique. Ces 5 PDF sont réunis dans le dossier « Un-nouvel-AZERTY-documentation-[version] ».

## Alerte d’incompatibilité de Linux Mint

Sous Linux Mint 21.3 (2024), ce nouvel AZERTY fonctionne uniquement quand il est activé par xkbcomp comme indiqué sous le titre suivant, Quand il y est installé, il fonctionne partiellement. Il n’est pas inutile d’installer ce nouvel AZERTY sous Linux Mint, mais il faut prévoir, en plus, de l’activer par xkbcomp.

Plus d’informations sous le titre [Linux Mint](#linux-mint) plus bas.

## Activation sans droits d’administrateur

Télécharger le dossier « Un-nouvel-AZERTY-Linux-[version].zip » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

### Script d’activation : mode d’emploi

Le script d’activation « activer.sh » se trouve sur GitHub ([activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh)) à la racine du dossier « linux-chromeos/ », ainsi qu’à la racine du paquet distribué « Un-nouvel-AZERTY-Linux-[version].zip ».

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande « ./activer.sh » après avoir ouvert le dossier dans un terminal.

Ce script commence par sauvegarder la disposition de clavier actuelle, afin de pouvoir par la suite proposer de revenir à la disposition de clavier habituelle. Cela est utile pour rapidement mettre fin à un test, par la même méthode qui a mis ce test en route. Cette option était prévue dès le début quand le seul moyen était l’activation manuelle documentée dans le [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt).

Pour revenir à la disposition de clavier habituelle, on choisit l’option O ou P pour plus d’options, puis H.

Sinon, après avoir appuyé sur Entrée, on peut choisir la variante de disposition dans une liste, puis la sous-variante dans une autre liste ; mais on peut aussi abréger en appuyant chaque fois directement sur Entrée, afin d’activer la disposition de base de ce nouvel AZERTY sans redispositions de touches.

Pour finaliser l’activation, les chaînes de caractères pour touches vives et le contenu des touches mortes sont mis en place dans le dossier personnel, le cas échéant à la suite des séquences de composition existantes.

Par la suite, la disposition de clavier dernièrement utilisée parmi celles incluses dans ce nouvel AZERTY (qui inclut aussi les variantes redisposées) sera réactivée le plus facilement, après un appui sur Entrée. Ce sera la version la plus à jour disponible localement, si le script [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) est lancé depuis un paquetage téléchargé. Sinon ce sera la version dernièrement utilisée, mise en cache dans le dossier personnel, dans un sous-dossier « dispoclavier/activer/ » au sein du sous-dossier caché « .config/ ».

Le script d’activation propose aussi de (semi-)automatiser l’activation à l’ouverture de session selon une méthode uniformisée, utile pour compléter l’installation par l’activation, mais cette fonctionnalité est affectée par le problème mentionné ci-après.

### Bogue d’autostart avec xkbcomp

La méthode uniformisée de lancement à l’ouverture de session ne fonctionne pas pour xkbcomp. Ce bogue est documenté plus bas sous le titre [Xkbcomp](#xkbcomp).

Quand le navigateur de fichiers s’ouvre sur le script de réactivation de la dernière disposition utilisée, cela signifie que le lancement automatique d’xkbcomp a échoué et qu’il est nécessaire de le lancer manuellement.

Pour le navigateur de fichiers, dix logiciels sont pris en charge nativement, et on peut personnaliser le script pour en prendre en charge un autre.

## Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « Un-nouvel-AZERTY-Linux-[version].zip » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh). On peut aussi installer chaque fichier [manuellement](#installation-manuelle).

### Script d’installation : mode d’emploi

Le script d’installation s’appelle « installer.sh » d’après le verbe français. Il se trouve sur GitHub ([installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/installer.sh)) à la racine du dossier « linux-chromeos/ », ainsi qu’à la racine du paquet distribué « Un-nouvel-AZERTY-Linux-[version].zip ».

Selon les réglages, on peut lancer ce script en le cliquant ou en le double-cliquant, et de toute manière par la commande « ./installer.sh » après avoir ouvert le dossier dans un terminal.

Le script commence par analyser la situation, et propose normalement soit d’installer ces dispositions de clavier, soit de les mettre à jour ou de les désinstaller.

Au début de l’installation, le script demande s’il faut **redisposer des touches.** Il s’agit de la touche AltFr, qui peut être redisposée sur la touche de Verrouillage des Capitales, et de la touche d’Effacement arrière, qui peut être redisposée sur la touche Menu, ou sur Windows droite ou Contrôle droite.

Après la sortie d’une nouvelle version, pour **mettre à jour** ces dispositions de clavier par le script, il faut lancer celui-ci, appuyer sur Entrée, saisir le mot de passe administrateur et faire Entrée une dernière fois.

Les **redispositions de touches** sont sauvegardées aussi bien lors de l’installation que lors de la désinstallation et d’une mise à jour. Ces sauvegardes sont enregistrées dans le dossier des configurations dans le dossier personnel de l’utilisateur qui effectue la mise à jour : « $HOME/.config/dispoclavier/keycodes/ ». Au cours de la désinstallation, le même fichier est sauvegardé aussi dans un dossier « sauvegarde/ » créé à côté du script.

Au moment d’installer ou de réinstaller ces dispositions de clavier, si le script détecte un fichier à ces deux endroits, il propose de l’utiliser.

Le fichier de redisposition sauvegardé à côté de ce script offre la facilité d’une **personnalisation** aisée avant sa réinstallation, tandis que celui dans les configurations personnelles assure la pérennité des redispositions à travers les mises à jour du système d’exploitation.

### Installation manuelle

En cas d’incompatibilité ou de configurations logicielles particulières, l’installation manuelle est une solution de dernier recours.

#### Alerte de dépannage

Par sécurité, il faut alerter, avant de suggérer de modifier manuellement des fichiers dans « /usr/share/X11/xkb/ », que le système a zéro tolérance sur certaines fautes de frappe, erreurs de syntaxe et incohérences comme l’utilisation d’un type de touche non défini. Pour tester des modifications dans XKB, il ne suffit pas non plus de rouvrir une application, contrairement aux modifications dans XCompose,

Ainsi, quand une erreur dans les fichiers de configuration d’XKB a rendu le système d’exploitation inutilisable, il ne peut être débogué que depuis **un(e) autre (instance du) système** dans une autre partition ou une clé USB démarrable.

#### Droits d’écriture

Pour faciliter ces opérations de fichiers, le plus simple est d’ouvrir une instance d’administrateur du navigateur de fichiers par sudo [nom de l’application].

#### L’installation pas à pas

Compte tenu de l’[alerte](#alerte-de-d%C3%A9pannage) plus haut, et pour toute éventualité, la procédure d’installation manuelle est la suivante :

1. [Compose.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/Compose.yml) : Prendre le fichier d’un seul tenant, qui se trouve aussi à la racine du dossier « Un-nouvel-AZERTY-Linux-[version].zip », et ajouter son contenu à la fin du fichier « X11/locale/en_US.UTF-8/Compose ».
2. [dispotypes.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispotypes.c) : Copier ce fichier vers « /usr/share/X11/xkb/types/dispotypes ».
3. Dans « /usr/share/X11/xkb/types/complete », ajouter « include "dispotypes" » sur une nouvelle ligne.
4. [dispocla_perso.cpp](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispocla_perso.cpp) : Copier ce fichier vers « /usr/share/X11/xkb/symbols/dispocla_perso ».
5. [dispocla.cpp](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispocla.cpp) : Copier ce fichier vers « /usr/share/X11/xkb/symbols/dispocla ».
6. [evdev-additions.xml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev-additions.xml) : Copier l’élément `<layout>` qui commence à la ligne 50, et le coller dans « /usr/share/X11/xkb/rules/evdev.xml » avant la balise `</layoutList>`.
7. Dans « /usr/share/X11/xkb/rules/evdev », empêcher le système d’écraser le deuxième groupe vif, en désactivant la ligne :

*		*		=	+%l[2]%(v[2]):2

   Pour ce faire, à défaut de supprimer cette ligne, on peut la remplacer par :
   
       // * * = +%l[2]%(v[2]):2

8. [evdev.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/evdev.c) : Mettre ce fichier à la place de « /usr/share/X11/xkb/keycodes/evdev » après avoir renommé celui-ci. Décommenter le cas échéant les définitions de touches souhaitées concernant Effacement arrière, AltFr et VerrCap.
9. [dispoled.c](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/dispoled.c) : Copier ce fichier vers « /usr/share/X11/xkb/compat/dispoled ».
10. Dans « /usr/share/X11/xkb/compat/complete », ajouter « include "dispoled" » sur une nouvelle ligne.
11. Veiller à ce que la méthode d’entrée soit XIM. Ce réglage se trouve par exemple (Ubuntu 24.04) dans Système > Pays et langue > Système > Gérer les langues installées > Langue > Système de saisie au clavier [iBus, XIM, Aucun]. Il peut aussi être effectué par la commande « im-config -n xim ».

Puis fermer la session et en rouvrir une.

#### Disposition de clavier par défaut

Si la disposition de clavier par défaut doit aussi être reconfigurée, ouvrir le fichier « /etc/default/keyboard » et changer les valeurs par exemple en « XKBLAYOUT="dispocla" » et « XKBVARIANT="kbfrFRs" ». Dans ce cas, on peut aussi laisser « XKBVARIANT="" » vide, car « "kbfrFRs" » est la disposition de base de ce nouvel AZERTY.

## Commutateur de dispositions de clavier

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier « Français (France) » sous le nom « Français France disposition de clavier semi-automatique » et peut être ajouté aux dispositions actives. Afin de l’activer sous une version de Linux sortie entre 2018 et 2024 (ou plus), il est nécessaire de désactiver l’autre disposition, car comme expliqué plus bas, le commutateur ne fonctionne plus.

Les variantes AZERTY s’appellent :

* Breton et français disposition de clavier semi-automatique ;
* Polynésie Française disposition de clavier semi-automatique ;
* Afrique francophone disposition de clavier semi-automatique ;
* Français Belgique disposition de clavier semi-automatique.

Les variantes redisposées QZJFGY s’appellent :

* Français France disposition de clavier semi-automatique redisposée ;
* Breton et français disposition de clavier semi-automatique redisposée ;
* Polynésie française disposition de clavier semi-automatique redisposée ;
* Afrique francophone disposition de clavier semi-automatique redisposée.

La variante belge ne se décline pas en variante redisposée parce que l’intérêt d’avoir une variante belge, c’est une assez bonne rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

## Vues de disposition

Les vues de ces dispositions dans Gnome se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues.

Sur les vues de disposition de ce nouvel AZERTY, sur le bloc alphabétique et la barre d’espace, le niveau 4 montre le niveau 5, c’est-à-dire les caractères disposés en AltFr, qui incluent les ponctuations non espacées et le pavé numérique graphique disposé sur le bloc alphanumérique, tandis que sur la rangée des chiffres, le niveau 4 montre réellement ce qui se trouve au niveau 4 : les positions rétrocompatibles du mode français. Car sur les touches des chiffres, le niveau 5 est identique au niveau 3 avec les chiffres, la touche moins a le symbole degré du niveau 2, et la touche plus a le symbole égal du niveau 1 du mode ASCII.

Les rectangles avec un code sont soit des touches mortes, comme la touche morte groupe « EFD0 » sur la touche [*], soit des séquences, comme les ponctuations espacées en Majuscule, ou le double zéro « EF6D » sur [B].

Ces touches mortes et ces séquences sont définies dans le répertoire des touches mortes et des séquences Compose(.yml), consultable sur GitHub en trois parties à cause d’une limitation de taille de fichier : [compose-1.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-1.yml) pour les séquences sur touches vives et les séquences de composition, [compose-2.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-2.yml) pour les touches mortes, et [compose-3.yml](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/compose/compose-3.yml) pour les [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles) et les [groupes des lettres](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-lettres), qui font partie de la [touche morte groupe](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/).

## Systèmes

Ces fichiers sont développés, testés et fusionnés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3** (datant de 2024)).

### Linux Mint

Ce nouvel AZERTY ne peut pas être installé normalement sous [Linux Mint Cinnamon 21.3 Virginia](https://www.linuxmint.com/edition.php?id=311), sorti en 2024 et bogué de façon protéiforme au regard des dispositions de clavier, tantôt comme décrit ci-après, tantôt avec des variations. La solution consiste à utiliser uniquement xkbcomp comme indiqué sous le titre [Activation sans droits d’administrateur](#activation-sans-droits-dadministrateur).

#### Bogue d’AltFr

Ce nouvel AZERTY utilise la modificatrice de niveau 5 « ISO_Level5_Shift », qui s’y appelle « AltFr ». Or sous Linux Mint 21.3, celle-ci est parfois convertie en touche AltGr, qui en tant qu’« ISO_Level3_Shift » est bien distincte.

Quand il est en cours d’exécution, ce bogue désactive les ponctuations non espacées, le pavé numérique graphique disposé sur le bloc alphanumérique, l’alphabet minuscule en exposant sur touches vives ; en somme, tout ou partie des fonctionnalités disposées aux niveaux 5 à 8.

#### Bogue de VerrMod

Linux Mint est parfois aussi affecté par un bogue qui transforme la bascule « VerrMod » en touche pour passer d’une disposition de clavier à une autre, parmi celles qui sont dans le commutateur.

Sur ce nouvel AZERTY, « VerrMod » bascule entre « ISO_Last_Group » et « ISO_First_Group », soit entre les deux groupes de disposition de chaque touche, qui permettent de disposer les huit positions séparément pour le mode français et le mode ASCII. Cette deuxième bascule graphique, dédiée aux chiffres, permet de dédier aux lettres la bascule traditionnelle VerrMaj, désormais VerrCap.

Sous Linux Mint, parfois on ne peut pas verrouiller les chiffres, et le mode ASCII est alors inaccessible.

#### Bogue du compilateur

Un troisième bogue est situé dans le compilateur, qui sous Linux Mint ne peut plus toujours lire les redéfinitions partielles de touches. Quand une touche d’une disposition incluse dans une autre disposition est partiellement redéfinie – les autres positions sont omises ou remplacées par « NoSymbol », qui ne signifie pas « aucun caractère », mais « pas de nouveau caractère » –, le compilateur peut effacer toute la touche et ne renseigner que les positions redéfinies. Ce bogue affecte tout ou partie des touches de la rangée E et met en panne des touches sur les variantes régionales et les variantes redisposées. Il serait facile à contourner, mais vu les autres bogues, cela serait une perte de temps inutile.

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

## Extensions de fichiers

À l’usage, la plupart des fichiers pour Linux de ce nouvel AZERTY sont sans extension. Les extensions « .c », « .cpp » et « .yml » servent uniquement à la coloration syntaxique et à faciliter l’ouverture sous Windows dans un souci d’interopérabilité. L’extension « .cpp » a été choisie pour éviter « dispocla.c ». (Les noms « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives.) Les statistiques de langage sont de toute manière désactivées dans ce dépôt.

## Utilisation

Les fonctionnalités implémentables sous tous les systèmes d’exploitation pris en charge sont présentées dans le [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md).

Ce mode d’emploi complémentaire présente uniquement ce qui est particulier à Linux.

### Lettres

#### Émulation de touche "ê"

L’émulation de touche "ê" par la touche morte accent circonflexe fonctionne aussi en capitales, "q" donne "êqu", et "x" donne "êch".
 
## Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier « linux-chromeos/ » où il se trouve. Mais c’est sous le nom de « Mode-d-emploi-sous-Linux.md » qu’il est inclus dans le dossier « Un-nouvel-AZERTY-Linux-[version].zip ».

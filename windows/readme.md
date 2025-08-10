# Un nouvel AZERTY pour Windows

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) des pilotes d’essai. Sur l’[utilisation](#utilisation) da la future version complète, il est vivement conseillé de se reporter au [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md) ainsi qu’à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne, ainsi qu’une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf) de la composition non mathématique. Ces 5 PDF sont réunis dans le dossier « Un-nouvel-AZERTY-documentation-[version].zip ».

## Installation

Télécharger le dossier « Un-nouvel-AZERTY-Windows-[version].zip » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « Démarrage-rapide.txt » ou dans « Lisez-moi-svp.txt ».

## Utilisation

Les fonctionnalités implémentables sous tous les systèmes d’exploitation pris en charge sont présentées dans le [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md).

Ce mode d’emploi complémentaire présente uniquement ce qui est particulier à Windows.

### Touches

#### Modificatrices

Ce nouvel AZERTY utilise toutes les modificatrices que Windows prend en charge, afin de dédommager de la mauvaise mise en œuvre des touches mortes sous Windows.

Alerter les personnes utilisatrices que les touches mortes façon Windows dysfonctionnent, sans leur proposer de compensations grâce aux points forts de Windows, serait extrêmement mauvais. En conséquence, les développeurs de dispositions de clavier sous Windows n’ont pas le droit de priver de fonctionnalités les personnes intéressées.

C’est pourquoi on ne saurait faire l’économie des modificatrices AltLe et AltQr ajoutées sur les bascules Verrouillage Capitales et Verrouillage Mode.

##### AltGr

D’habitude, sous Windows, AltGr est Contrôle + Alt. Comme cette émulation est [déconseillée](https://blog.keyman.com/2008/06/robust-key-mess/), elle est remplacée par l’une des quatre autres modificatrices disponibles.

##### AltFr

Pour mettre AltFr sur la touche de verrouillage des capitales, et VerrCap sur Contrôle droite, en cas d’absence de la touche ISO entre Majuscule gauche et [W], des fichiers de redisposition de codes matériels de touches se trouvent dans le dossier redispositions\\.

##### AltLe

"Le" dans le nom de la nouvelle modificatrice « AltLe » signifie « Lettres émojis ».

AltLe s’ajoute sur VerrCap. Tant que l’on appuie sur VerrCap, AltLe est active.

On peut alors saisir [tous les drapeaux nationaux](https://unicode.org/emoji/charts/emoji-list.html#country-flag) par leur [code ISO à deux lettres](https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2) ou AC 🇦🇨, CP 🇨🇵, DG 🇩🇬, EA 🇪🇦, EU 🇪🇺, IC 🇮🇨, TA 🇹🇦, UN 🇺🇳, XK 🇽🇰.

Plusieurs drapeaux – national, supranational, international – sont aussi précomposés :

* France 🇫🇷 : Maj + AltLe + [.;] ;
* Union Européenne 🇪🇺 : Maj + AltLe + [/:] ;
* Nations Unies 🇺🇳 : Maj + AltLe + [§!].

Les trois seuls drapeaux régionaux, [codés différemment](https://blog.unicode.org/2022/03/the-past-and-future-of-flag-emoji.html), sont précomposés :

* Angleterre 🏴󠁧󠁢󠁥󠁮󠁧󠁿 : Maj + AltLe + [£$¤] ;
* Écosse 🏴󠁧󠁢󠁳󠁣󠁴󠁿 : Maj + AltLe + [+=}] ;
* Pays de Galles 🏴󠁧󠁢󠁷󠁬󠁳󠁿 : Maj + AltLe + [µ*].

On peut aussi écrire en 🇱⁠🇪⁠🇹⁠🇹⁠🇷⁠🇪⁠🇸⁠ 🇪⁠🇲⁠🇴⁠🇯⁠🇮⁠🇸 non accentuées⁠. Deux possibilités pour cela :

* Entre deux lettres, appuyer sur la barre d’espace.
* Écrire en Maj + AltLe, en utilisant pour la lettre dans la colonne 2 de chaque rangée la touche après la dernière lettre de cette rangée, et appuyer sur la barre d’espace entre deux mots (sans avoir besoin de lever les doigts de Maj + AltLe).

##### AltQr

"Qr" dans le nom de la nouvelle modificatrice « AltQr » signifie « Quick response » comme dans les QR codes.

AltQr s’ajoute sur VerrMod. Tant que l’on appuie sur VerrMod, AltQr est active.

On peut alors saisir les lettres symboles mathématiques italiques, pour 𝑒́𝑐𝑟𝑖𝑟𝑒 𝑒𝑛 𝑖𝑡𝑎𝑙𝑖𝑞𝑢𝑒 même là où la mise en forme n’est pas prise en charge, avec des diacritiques ajoutés par un appui sur la touche morte suivi d’espace :

1. Symbole "𝑒" : AltQr + [E] ;
2. Accent aigu, étape 1 : [£$¤] ;
3. Accent aigu, étape 2 : Espace.

En AltFr + AltQr se trouvent les lettres symboles mathématiques calligraphiques grasses, pour 𝓮́𝓬𝓻𝓲𝓻𝓮 𝓮𝓷 𝓮́𝓬𝓻𝓲𝓽𝓾𝓻𝓮 𝓬𝓾𝓻𝓼𝓲𝓿𝓮 𝓬𝓪𝓵𝓵𝓲𝓰𝓻𝓪𝓹𝓱𝓲𝓺𝓾𝓮. (Grasses plutôt que normales parce que, codées dans un seul bloc, elles sont uniformes.)

En AltGr + AltQr se trouvent les lettres symboles mathématiques ajourées, pour 𝕖́𝕔𝕣𝕚𝕣𝕖 𝕖𝕟 𝕒𝕛𝕠𝕦𝕣𝕖́.

En AltGr + AltFr + AltQr se trouvent les lettres symboles mathématiques grasses sans empattements, pour 𝗲́𝗰𝗿𝗶𝗿𝗲 𝗲𝗻 𝗴𝗿𝗮𝘀.

La combinaison AltLe + AltQr fonctionne mal, mais on peut y utiliser les minuscules mathématiques calligraphiques normales, souvent incohérentes dans les polices de caractères car codées dans deux blocs. Toutes leurs majuscules sont en AltGr + AltLe + AltQr, et la plupart sont aussi en AltGr + AltLe + AltQr, sauf trois à cause d’un bogue dans la colonne 2.

#### Bascules

##### Verrouillage Capitales

Quand les capitales sont verrouillées, le guillemet ouvrant avec espace fine insécable est sans espace fine insécable. À la place, il faut le saisir en AltFr afin d’ajouter l’espace fine insécable, qui y est en synergie.

La raison est que ce guillemet est sur la touche [ù], qui nécessite une fonctionnalité appelée « capitales suisses-allemandes » (« Swiss-German Capitals »), qui ne prend en charge ni les touches mortes (voir [ce billet de blog](https://archives.miloush.net/michkap/archive/2008/02/09/7564967.html)), ni les séquences (voir [ce billet de blog](https://archives.miloush.net/michkap/archive/2006/01/16/513088.html), et un résumé dans [ce billet de blog](https://archives.miloush.net/michkap/archive/2010/07/07/10032340.html)), sans qu’il suffirait de ne définir que le niveau qui en a réellement besoin. Cet état inachevé est dû à l’insuffisance de tests faisant l’impasse sur les écritures codées sur 3 octets, à une époque où Unicode était de fait un jeu de caractères codé sur 2 octets, et par un développeur qui n’anticipait pas que cela n’allait pas rester comme cela, et qui était insuffisamment supervisé par la hiérarchie. Les déficiences qui en résultaient ont été palliées par des logiciels tiers, sous les pieds desquels Microsoft s’est abstenu de couper l’herbe par la suite, mais qui ne sont pas facilement adoptés par les personnes utilisatrices françaises pour autant, condamnées la plupart à se dépanner comme elles peuvent sur un système d’exploitation défectueux.

(La fonctionnalité « capitales suisses-allemandes » est un contournement du manque du moyen de spécifier pour chaque touche ce qu’elle sort quand le Verrouillage des Capitales est actif, moyen qui existe sous Linux et sous macOS, pour chaque niveau de touche pris en charge.)

Ce bogue n’affecte pas les variantes redisposées, où aucune lettre n’est sur la même touche qu’une ponctuation espacée, car la place du "ù" est prise par l’apostrophe, tandis que le "ù" prend la place du tiret du 6 (qui prend la place de la touche morte groupe, qui va sur la touche au-dessus à la place de la touche morte accent aigu, qui prend la place laissée par l’apostrophe).

Ce bogue est [documenté](https://github.com/dispoclavier/nouvel-azerty/commit/c22acd3fab99782947ef3e14e8893476935325b4).

### Lettres

#### Émulation de touche "ê"

L’émulation d’une touche "ê" par la touche morte accent circonflexe ne fonctionne pas en capitales, et "x" ne donne pas "êch". Pour atténuer ce mauvais fonctionnement, la touche morte accent circonflexe suivie de "x" donne "ê", afin d’éviter que l’on se retrouve avec "êx" et que l’on soit obligé d’effacer le "x" avant de pouvoir saisir le "ch" manquant dont on avait pris l’habitude sous Linux ou sous macOS.

De même, la touche morte accent circonflexe suivie de "K", "L", "M", "N", "P", "Q", "R", "T", "V" OU "X" donne "Ê", afin d’interrompre au minimum le flux de l’écriture et de permettre, dans la plupart des cas, de faire une double frappe sur la consonne pour obtenir le même résultat que la simple frappe donne sous Linux et sous macOS.

(La raison de ce dysfonctionnement est que sous Windows, les touches mortes sont incapables d’émettre des chaînes multicaractères et des caractères au-dessus d’U+FFFF, et que la situation n’est sauvée que grâce au fait que sous Windows, chaque touche morte a un caractère mort, et que ce caractère mort sort tel quel si le caractère de base, celui saisi après la touche morte, n’est pas pris en charge. Grâce à cette fonctionnalité de Windows, l’émulation de touche "ê" par la touche accent circonflexe fonctionne en minuscules.)

#### Touches mortes

##### Demi-codets hauts

Le demi-codet haut doit être saisi à part, avant de saisir le demi-codet bas. La nécessité de saisir séparément les deux moitiés des caractères Unicode au-dessus de U+FFFF concerne uniquement les touches mortes. Les touches vives sont capables d’émettre les deux moitiés d’affilée.

Les touches mortes diacritiques ou transformationnelles émettent un demi-codet haut quand elles sont suivies de l’espace nulle disposée au niveau 4 de la barre d’espace, au même niveau que la plupart des touches mortes.

Par exemple, en plus d’être sur touche vive, le "q" minuscule en exposant "𐞥" U+107A5 est dans la touche morte exposant. Pour le saisir, il faut appuyer deux fois sur la touche morte exposant sur Maj + AltGr + [A], entrecoupées d’un appui sur la barre d’espace, et ensuite appuyer sur [Q]. Soit en détail :

1. Maj + AltGr + [A]
2. Maj + AltGr + [Espace]
3. Maj + AltGr + [A]
4. [Q]

Les caractères pris en charge par les touches mortes de ce nouvel AZERTY nécessitent 8 demi-codets hauts, ainsi répartis sur les touches mortes :

* U+D801 exposant : lettres modificatives en exposant
* U+D807 tourné : "𑾰" U+11FB0 LETTRE LISSOU YHA
* U+D835 groupe : symboles mathématiques alphanumériques
* U+D837 rayé, brève, hameçon et autres touches mortes : lettres latines
* U+D83C drapeau, grec ou cerclé : lettres pour drapeaux, lettres encadrées
* U+D83D accent circonflexe, accent aigu, tréma : guillemets décoratifs
* U+D83E barré, groupes 11 et 12 comme intégré : flèches à pointe large
* U+DB40 drapeau : étiquettes

La raison de cette complication est que sous Windows, les caractères sont codés sur 16 bits, et le système Windows de pilotes de disposition a été conçu à une époque où Unicode était de fait un jeu de caractères sur 16 bits, car aucun caractère n’était plus grand que U+FFFF (et par un développeur qui pensait que cela allait rester comme cela).

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes, il aurait simplement fallu ajouter une colonne, et programmer Windows pour la consulter et ajouter son contenu s’il n’est pas nul.

##### Lettres composées

Les diacritiques des lettres composées doivent être saisis individuellement après la lettre de base. On ne peut pas utiliser les touches mortes pour émettre d’un seul coup des séquences faites d’une lettre de base et de diacritiques combinants.

Les touches mortes diacritiques éligibles émettent le diacrique combinant quand elles sont suivies de l’espace. (Traditionnellement, c’était le mode de saisie du diacritique espaçant, saisi désormais par la touche morte suivie d’une espace insécable.)

Par exemple, pour saisir le o ouvert accent aigu, il faut d’abord saisir le o ouvert tel quel, et ensuite le coiffer d’un accent aigu en faisant suivre un appui sur la touche morte accent aigu et un coup sur la barre d’espace. Soit en détail :

1. Touche morte groupe : [µ*] ;
2. [C] ;
3. Touche morte accent aigu : [£$¤] ;
4. Espace.

La raison de cette complication est que le système Windows de pilotes de disposition a été conçu à une époque où les langues les mieux établies et les plus réactives, comme le grec et le vietnamien, se faisaient doter de jeux complets de lettres diacritées précomposées, et par un développeur qui ne pensait sans doute pas aux autres langues, et qui n’était peut-être pas au courant du modèle d’encodage d’Unicode ni de la recommandation de prendre en charge les lettres composées par touches mortes.

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes il aurait simplement fallu ajouter 5 colonnes (ou plus, car on n’est pas à quelques kilooctets près, puisque les pilotes de ce nouvel AZERTY sont déjà dix fois plus lourds qu’un pilote moyen et restent parfaitement fonctionnels, et Windows aussi), et programmer Windows pour les consulter et ajouter leur contenu s’il n’est pas nul.

### Chiffres

#### Bascule de mode

##### Mode ASCII

En mode ASCII, le niveau 7 ne fonctionne pas, sur les touches qui sont en mode ASCII, les touches graphiques autres que les lettres simples, et la barre d’espace. Ces touches ne donnent rien en AltGr + AltFr, mais elles fonctionnent bien en Maj + AltFr et en Maj + AltGr + AltFr.

Afin de mitiger ce bogue du niveau 7, en mode ASCII, le niveau 7 est aussi redondant que possible. Ainsi les chiffres en indice sont en Maj + AltGr en plus d’être en AltGr + AltFr.

### Émojis

Tous les émojis codés sur deux ou trois octets à part les sinogrammes sont pris en charge par touches mortes dans les 12 [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles), seuls quelques émoji codés sur quatre octets, triés sur le volet, sont pris en charge, sur touches vives uniquement.

Une sélection d’émojis codés sur 4 octets est disposée sur les places de touches vives qui restent, et avec les nouvelles modificatrices il y a de la place pour en mettre plus.

## Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier « windows/ » où il se trouve. Mais c’est sous le nom de « Mode-d-emploi-sous-Windows.md » qu’il est inclus dans le dossier « Un-nouvel-AZERTY-Windows-[version].zip ».

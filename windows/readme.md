# Un nouvel AZERTY pour Windows

Ce mode d’emploi couvre l’[installation](#installation) et les particularités de l’[utilisation](#utilisation) sous Windows, afin de compléter le [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md).

Ces modes d’emploi complètent à leur tour la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) et sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf), la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi que la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf)) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne. Ces cinq PDF sont réunis dans le dossier « Un-nouvel-AZERTY-Documentation-[version].zip ».

## Installation

Télécharger le dossier « Un-nouvel-AZERTY-Windows-[version].zip » ou « Un-nouvel-AZERTY-Windows-variantes-[version].zip » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

## Utilisation

Les fonctionnalités implémentables sous tous les systèmes d’exploitation pris en charge sont présentées dans le [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md).

Ce mode d’emploi complémentaire présente ce qui est particulier à Windows.

### Touches

#### Modificatrices

Ce nouvel AZERTY permet d’utiliser toutes les modificatrices que Windows prend en charge, afin de dédommager de la mauvaise mise en œuvre des touches mortes par Microsoft (due à des problèmes de personnel, de qualification et d’assurance qualité), sur laquelle il faut forcément alerter et qu’il faut compenser en conséquence.

Quitte à alerter les personnes utilisatrices que les touches mortes façon Windows dysfonctionnent, autant mettre en valeur les points forts de Windows, car il ne s’agit pas de descendre en flammes un outil de travail incontournable. Il faut tirer le meilleur parti possible de l’existant, qui contrairement à d’autres parties de Windows n’est pas susceptible d’être amélioré à ce stade, ne serait-ce que pour déboguer le plus gros.

C’est pourquoi, afin de ne pas priver de fonctionnalités les personnes intéressées, on ne saurait faire l’économie des modificatrices AltEm et AltMa, ajoutées sur les bascules Verrouillage Capitales et Verrouillage Mode, et qui facilitent énormément la saisie des émojis drapeaux et de plusieurs alphabets mathématiques préformatés.

##### AltGr

D’habitude, sous Windows, AltGr est Contrôle + Alt et interfère avec les raccourcis clavier si les applications ne gèrent pas ces conflits. Word les gère très bien, mais c’est loin d’être le cas de tous les programmes. C’est pourquoi cette émulation est [déconseillée](https://blog.keyman.com/2008/06/robust-key-mess/) et remplacée par l’une des quatre autres modificatrices disponibles (peu importe laquelle, mais le plus logique est de prendre la première, 0x10).

##### AltFr

Comme AltFr est sur la touche ISO entre Majuscule gauche et ⟦W⟧, et que cette touche manque sur les agencements ANSI, on peut mettre AltFr sur la touche de verrouillage des capitales, et VerrCap sur Contrôle droite, utilisée pour la touche ISO sur les agencements ANSI pour disposition AZERTY. Pour ce faire, des fichiers de redisposition de codes matériels de touches sont disponibles dans le dossier « redispositions\\ ».

##### AltEm

La touche modificatrice des émojis, AltEm, s’ajoute sur VerrCap. Tant que l’on appuie sur VerrCap, AltEm est active.

On peut alors saisir [tous les drapeaux nationaux](https://unicode.org/emoji/charts/emoji-list.html#country-flag) par leur [code ISO à deux lettres](https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2) ou AC 🇦🇨, CP 🇨🇵, DG 🇩🇬, EA 🇪🇦, EU 🇪🇺, IC 🇮🇨, TA 🇹🇦, UN 🇺🇳, XK 🇽🇰.

Plusieurs drapeaux – national, supranational, international – sont aussi précomposés :

* France 🇫🇷 : Maj + AltEm + ⟦.;⟧ ;
* Union Européenne 🇪🇺 : Maj + AltEm + ⟦/:⟧ ;
* Nations Unies 🇺🇳 : Maj + AltEm + ⟦§!⟧.

Les trois seuls drapeaux régionaux, [codés différemment](https://blog.unicode.org/2022/03/the-past-and-future-of-flag-emoji.html), sont précomposés :

* Angleterre 🏴󠁧󠁢󠁥󠁮󠁧󠁿 : Maj + AltEm + ⟦£$¤⟧ ;
* Écosse 🏴󠁧󠁢󠁳󠁣󠁴󠁿 : Maj + AltEm + ⟦+=}⟧ ;
* Pays de Galles 🏴󠁧󠁢󠁷󠁬󠁳󠁿 : Maj + AltEm + ⟦µ*⟧.

On peut aussi écrire en 🇱⁠🇪⁠🇹⁠🇹⁠🇷⁠🇪⁠🇸⁠ 🇪⁠🇲⁠🇴⁠🇯⁠🇮⁠🇸 non accentuées⁠. Deux possibilités pour cela :

* Entre deux lettres, appuyer sur la barre d’espace.
* Écrire en Maj + AltEm, en utilisant pour la lettre dans la colonne 2 de chaque rangée la touche après la dernière lettre de cette rangée, et appuyer sur la barre d’espace entre deux mots sans avoir besoin de lever les doigts de Maj + AltEm.

##### AltMa

"Ma" dans le nom de la nouvelle modificatrice « AltMa » signifie « Mathématique » par rapport aux lettres préformatées à usage mathématique, souvent détournées pour simuler de la mise en forme en texte brut.

AltMa s’ajoute sur VerrMod. Tant que l’on appuie sur VerrMod, AltMa est active.

On peut alors saisir les lettres symboles mathématiques italiques, pour 𝑒́𝑐𝑟𝑖𝑟𝑒 𝑒𝑛 𝑖𝑡𝑎𝑙𝑖𝑞𝑢𝑒 même là où la mise en forme n’est pas prise en charge, avec des diacritiques ajoutés par un appui sur la touche morte suivi d’espace :

1. Symbole "𝑒" : AltMa + ⟦E⟧ ;
2. Accent aigu, étape 1 : ⟦£$¤⟧ ;
3. Accent aigu, étape 2 : ⟦Espace⟧.

En AltFr + AltMa se trouvent les lettres symboles mathématiques calligraphiques grasses, pour 𝓮́𝓬𝓻𝓲𝓻𝓮 𝓮𝓷 𝓮́𝓬𝓻𝓲𝓽𝓾𝓻𝓮 𝓬𝓾𝓻𝓼𝓲𝓿𝓮 𝓬𝓪𝓵𝓵𝓲𝓰𝓻𝓪𝓹𝓱𝓲𝓺𝓾𝓮. (Grasses plutôt que normales parce que, codées dans un seul bloc, elles sont uniformes.)

En AltGr + AltMa se trouvent les lettres symboles mathématiques ajourées, pour 𝕖́𝕔𝕣𝕚𝕣𝕖 𝕖𝕟 𝕒𝕛𝕠𝕦𝕣𝕖́.

En AltGr + AltFr + AltMa se trouvent les lettres symboles mathématiques grasses sans empattements, pour 𝗲́𝗰𝗿𝗶𝗿𝗲 𝗲𝗻 𝗴𝗿𝗮𝘀.

La combinaison AltEm + AltMa fonctionne mal, mais on peut y utiliser les minuscules mathématiques calligraphiques normales, souvent incohérentes dans les polices de caractères car codées dans deux blocs. Toutes leurs majuscules sont en AltGr + AltEm + AltMa, et elles sont aussi en Maj + AltEm + AltMa, sauf que celles sur ⟦Z⟧, ⟦S⟧ et ⟦X⟧ sont sur les touches après ⟦P⟧, ⟦M⟧ et ⟦N⟧. (La raison est qu’en Maj + AltEm, la colonne 02 est boguée.)

#### Bascules

##### Verrouillage Mode

###### Mode ASCII

En mode ASCII, le niveau 7 ne fonctionne pas, sur les touches qui sont en mode ASCII, les touches graphiques autres que les lettres simples, et la barre d’espace. Ces touches ne donnent rien en AltGr + AltFr, mais elles fonctionnent bien en Maj + AltFr et en Maj + AltGr + AltFr.

Afin de mitiger ce bogue du niveau 7, en mode ASCII, le niveau 7 est aussi redondant que possible. Ainsi les chiffres en indice sont en Maj + AltGr en plus d’être en AltGr + AltFr.

##### Verrouillage Capitales

Quand les capitales sont verrouillées, le guillemet ouvrant avec espace fine insécable est sans espace fine insécable. À la place, il faut le saisir en AltFr afin d’ajouter l’espace fine insécable, qui y est en synergie.

La raison est que ce guillemet est sur la touche ⟦%ù⟧, qui nécessite une fonctionnalité appelée « capitales suisses-allemandes » (abrégée en SGCaps pour « Swiss-German Capitals »), qui ne prend en charge ni les touches mortes (voir [ce billet de blog](https://archives.miloush.net/michkap/archive/2008/02/09/7564967.html)), ni les séquences (voir [ce billet de blog](https://archives.miloush.net/michkap/archive/2006/01/16/513088.html), et un résumé dans [ce billet de blog](https://archives.miloush.net/michkap/archive/2010/07/07/10032340.html)), sans qu’il suffirait de ne définir que le niveau qui en a réellement besoin. Cet état inachevé est dû à l’insuffisance de tests faisant l’impasse sur les écritures codées sur 3 ou 4 octets, à une époque où Unicode était de fait un jeu de caractères codé sur 2 octets. Les déficiences qui en ont résulté ont été palliées par des logiciels tiers, sous les pieds desquels Microsoft s’est abstenu de couper l’herbe par la suite, mais qui ne sont pas facilement adoptés par les personnes utilisatrices françaises pour autant, condamnées la plupart à se dépanner comme elles peuvent sur un système d’exploitation défectueux.

(La fonctionnalité « capitales suisses-allemandes » est un contournement du manque du moyen de spécifier pour chaque touche ce qu’elle sort quand le verrouillage des capitales est actif, moyen qui existe sous Linux et sous macOS, pour chaque niveau de touche pris en charge.)

Ce bogue n’affecte pas les variantes redisposées, où aucune lettre n’est sur la même touche qu’une ponctuation espacée, car la place du "ù" est prise par l’apostrophe, tandis que le "ù" prend la place du tiret du 6 (qui prend la place de la touche morte groupe, qui va sur la touche au-dessus, à la place de la touche morte accent aigu, qui prend la place laissée par l’apostrophe).

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

Par exemple, en plus d’être sur touche vive, le "q" minuscule en exposant "𐞥" U+107A5 est dans la touche morte exposant. Pour le saisir, il faut appuyer deux fois sur la touche morte exposant sur Maj + AltGr + ⟦A⟧, entrecoupées d’un appui sur la barre d’espace, et ensuite appuyer sur ⟦Q⟧. Soit en détail :

1. Maj + AltGr + ⟦A⟧
2. Maj + AltGr + ⟦Espace⟧
3. Maj + AltGr + ⟦A⟧
4. ⟦Q⟧

Les caractères pris en charge par les touches mortes de ce nouvel AZERTY nécessitent 8 demi-codets hauts, ainsi répartis sur les touches mortes :

* U+D801 dans la touche morte exposant : lettres modificatives en exposant
* U+D807 dans la touche morte tourné : "𑾰" U+11FB0 LETTRE LISSOU YHA
* U+D835 dans la touche morte groupe : symboles mathématiques alphanumériques
* U+D837 dans les touches mortes rayé, brève, hameçon et autres touches mortes : lettres latines
* U+D83C dans les touches mortes drapeau, grec-ou-cerclé : lettres pour drapeaux, lettres encadrées
* U+D83D dans les touches mortes accent circonflexe, accent aigu, tréma : guillemets décoratifs
* U+D83E dans la touche morte barré, groupes 11 et 12 comme intégré : flèches à pointe large
* U+DB40 dans la touche morte drapeau : étiquettes

La raison de cette complication est que sous Windows, les caractères sont codés sur 16 bits, et le système Windows de pilotes de disposition a été conçu à une époque où Unicode était de fait un jeu de caractères sur 16 bits, car aucun caractère n’était plus grand que U+FFFF, et à une époque où Unicode était encore d’accord pour précomposer les lettres diacritées utilisées en vietnamien, car composer "ơ" et "ư" était encore trop délicat.

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes, il aurait simplement fallu ajouter au moins une colonne, et programmer Windows pour la consulter et ajouter son contenu s’il n’est pas nul.

##### Lettres composées

Les diacritiques des lettres composées doivent être saisis individuellement après la lettre de base. On ne peut pas utiliser les touches mortes pour émettre d’un seul coup des séquences faites d’une lettre de base et de diacritiques combinants.

Les touches mortes diacritiques éligibles émettent le diacrique combinant quand elles sont suivies de l’espace. (Traditionnellement, c’était le mode de saisie du diacritique espaçant, saisi désormais par la touche morte suivie d’une espace insécable.)

Par exemple, pour saisir le o ouvert accent aigu, il faut d’abord saisir le o ouvert tel quel, et ensuite le coiffer d’un accent aigu en faisant suivre un appui sur la touche morte accent aigu et un coup sur la barre d’espace. Soit en détail :

1. Touche morte groupe : ⟦µ*⟧ ;
2. ⟦C⟧ ;
3. Touche morte accent aigu : ⟦£$¤⟧ ;
4. ⟦Espace⟧.

La raison de cette complication est que le système Windows de pilotes de disposition a été conçu à une époque où les langues les mieux établies et les plus réactives, comme le grec et le vietnamien, se faisaient doter de jeux complets de lettres diacritées précomposées, et sans penser aux autres langues, prises en charge par le modèle d’encodage d’Unicode assorti de la recommandation de permettre la saisie par touches mortes des lettres composées de la même manière que celle des lettres précomposées.

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes, il aurait simplement fallu ajouter 5 colonnes (ou plus, car on n’est pas à quelques kilooctets près, puisque les pilotes de disposition restent opérationnels jusqu’au vingtuple de leur taille moyenne, et Windows aussi), et programmer Windows pour les consulter et ajouter leur contenu s’il est non nul.

### Émojis

Tous les émojis codés sur deux ou trois octets à part les sinogrammes sont pris en charge par touches mortes dans les 12 [groupes des symboles](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/#1566-groupes-des-symboles), seuls quelques émoji codés sur quatre octets, triés sur le volet, sont pris en charge, sur touches vives uniquement.

Une sélection d’émojis codés sur 4 octets est disposée sur les places de touches vives qui restent, et avec les nouvelles modificatrices il y a de la place pour en mettre plus.

## Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier « windows/ » où il se trouve. Mais c’est sous le nom de « Mode-d-emploi-sous-Windows.pdf » qu’il est inclus dans le dossier « Un-nouvel-AZERTY-Windows-[version].zip ».

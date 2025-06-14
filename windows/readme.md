# Un nouvel AZERTY pour Windows

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) des pilotes d’essai. Sur l’[utilisation](#utilisation) da la future version complète, il est vivement conseillé de se reporter au [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md) ainsi qu’à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne, ainsi qu’une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf) de la composition non mathématique. Ces 5 PDF sont réunis dans le dossier « Un-nouvel-AZERTY-documentation-[version].zip ».

## Installation

Télécharger le dossier « Un-nouvel-AZERTY-Windows-[version].zip » sous le titre « Assets », l’extraire, aller dans le dossier dont le nom finit en « (installation) », puis dans celui qui commence par « kbfrFRs » (« kbfrFRs v4.16.0.0 installation ») et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Utilisation

Les fonctionnalités implémentables sous tous les systèmes d’exploitation pris en charge sont présentées dans le [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md).

Ce mode d’emploi complémentaire présente uniquement ce qui est particulier à Windows.

### Lettres

#### Émulation de touche "ê"

L’émulation d’une touche "ê" par la touche morte accent circonflexe ne fonctionne pas en capitales, et "x" ne donne pas "êch". Pour atténuer ce mauvais fonctionnement, la touche morte accent circonflexe suivie de "x" donne "ê", afin d’éviter que l’on se retrouve avec "êx" et que l’on soit obligé d’effacer le "x" avant de pouvoir saisir le "ch" manquant dont on avait pris l’habitude sous Linux ou sous macOS.

De même, la touche morte accent circonflexe suivie de "K", "L", "M", "N", "P", "Q", "R", "T", "V" OU "X" donne "Ê", afin d’interrompre au minimum le flux de l’écriture et de permettre, dans la plupart des cas, de faire une double frappe sur la consonne pour obtenir le même résultat que la simple frappe donne sous Linux et sous macOS.

(La raison de ce dysfonctionnement est que sous Windows, les touches mortes sont incapables d’émettre des chaînes multicaractères et des caractères au-dessus d’U+FFFF, et que la situation n’est sauvée que grâce au fait que sous Windows, chaque touche morte a un caractère mort, et que ce caractère mort sort tel quel si le caractère de base, celui saisi après la touche morte, n’est pas pris en charge. Grâce à cette fonctionnalité de Windows, l’émulation de touche "ê" par la touche accent circonflexe fonctionne en minuscules.)

#### Verrouillage des capitales

Quand les capitales sont verrouillées, le guillemet ouvrant avec espace fine insécable est sans espace fine insécable. À la place, il faut le saisir en AltFr afin d’ajouter l’espace fine insécable, qui y est en synergie.

La raison est que ce guillemet est sur la touche [ù], qui nécessite une fonctionalité appelée « capitales suisses-allemandes » (« Swiss-German Capitals »), qui ne prend en charge ni les touches mortes, ni les séquences, sans qu’il suffirait de ne définir que le niveau qui en a réellement besoin. Cet état inachevé est dû à l’insuffisance de tests faisant l’impasse sur les écritures codées sur 3 octets, à une époque où Unicode était de fait un jeu de caractères codé sur 2 octets, et par un développeur qui n’anticipait pas que cela n’allait pas rester comme cela, et qui était insuffisamment supervisé par la hiérarchie. Les déficiences qui en résultaient ont été palliées par des logiciels tiers, sous les pieds desquels Microsoft s’est abstenu de couper l’herbe par la suite, mais qui ne sont pas facilement adoptés par les utilisateurs français pour autant, condamnés la plupart à se dépanner comme ils peuvent sur un système d’exploitation défectueux.

(La fonctionnalité « capitales suisses-allemandes » est un contournement du manque du moyen de spécifier pour chaque touche ce qu’elle sort quand le Verrouillage des Capitales est actif, moyen qui existe sous Linux et sous macOS, pour chaque niveau de touche pris en charge.)

Ce bogue n’affecte pas les variantes redisposées, où aucune lettre n’est sur la même touche qu’une ponctuation espacée, car la place du "ù" est prise par l’apostrophe, tandis que le "ù" prend la place du tiret du 6 (qui prend la place de la touche morte groupe, qui va sur la touche au-dessus à la place de la touche morte accent aigu, qui prend la place laissée par l’apostrophe).

Ce bogue est [documenté](https://github.com/dispoclavier/nouvel-azerty/commit/c22acd3fab99782947ef3e14e8893476935325b4).

#### Touches mortes

##### Demi-codets hauts

Le demi-codet haut doit être saisi à part, avant de saisir le demi-codet bas. La nécessité de saisir séparément les deux moitiés des caractères Unicode au-dessus de U+FFFF concerne uniquement les touches mortes. Les touches vives sont capables d’émettre les deux moitiés d’affilée.

Les touches mortes diacritiques ou transformationnelles émettent un demi-codet haut quand elles sont suivies de l’espace nulle disposée au niveau 4 de la barre d’espace, au même niveau que la plupart des touches mortes.

Par exemple, en plus d’être sur touche vive, le "q" minuscule en exposant "𐞥" U+107A5 est dans la touche morte exposant. Pour le saisir, il faut appuyer deux fois sur la touche morte exposant sur Maj + AltGr + [A], entrecoupées d’un appui sur la barre d’espace, et ensuite appuyer sur [Q]. Soit en détail :

1. Maj + AltGr + [A]
2. Maj + AltGr + [Espace]
3. Maj + AltGr + [A]
4. [Q]

Les caractères pris en charge par les touches mortes de ce nouvel AZERTY nécessitent 7 demi-codets hauts, ainsi répartis sur les touches mortes :

* U+D801 exposant : lettres modificatives en exposant
* U+D807 tourné : "𑾰" U+11FB0 LETTRE LISSOU YHA
* U+D835 groupe : symboles mathématiques alphanumériques
* U+D837 rayé, brève, hameçon et autres touches mortes : lettres latines
* U+D83C drapeau, grec ou cerclé : lettres pour drapeaux, lettres encadrées
* U+D83D accent circonflexe, accent aigu, tréma : guillemets décoratifs
* U+D83E barré, groupes 11 et 12 comme intégré : flèches à pointe large

Cette méthode d’entrée des demi-codets hauts est basée sur une idée datant du 18 décembre 2024 à 22:28 (en lavant une courgette).

La raison de cette complication est que sous Windows, les caractères sont codés sur 16 bits, et le système Windows des pilotes de disposition a été conçu à une époque où Unicode était de fait un jeu de caractères sur 16 bits (aucun caractère n’était plus grand que U+FFFF), et par un développeur qui pensait que cela allait rester comme cela.

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes il aurait simplement fallu ajouter une colonne, et programmer Windows pour la consulter et ajouter son contenu s’il n’est pas nul.

##### Lettres composées

Les diacritiques des lettres composées doivent être saisis individuellement après la lettre de base. On ne peut pas utiliser les touches mortes pour émettre d’un seul coup des séquences faites d’une lettre de base et de diacritiques combinants.

Les touches mortes diacritiques éligibles émettent le diacrique combinant quand elles sont suivies de l’espace. (Traditionnellement, c’était le mode de saisie du diacritique espaçant, saisi désormais par la touche morte suivie d’une espace insécable.)

Par exemple, pour saisir le o ouvert accent aigu, il faut d’abord saisir le o ouvert tel quel, et ensuite le coiffer d’un accent aigu en faisant suivre un appui sur la touche morte et un coup sur la barre d’espace. Soit en détail :

1. Touche morte groupe sur [*]
2. [C]
3. Touche morte accent aigu sur [$]
4. [Espace]

La raison de cette complication est que le système Windows des pilotes de disposition a été conçu à une époque où les langues les mieux établies et les plus réactives, comme le grec et le vietnamien, se faisaient doter de jeux complets de lettres diacritées précomposées, et par un développeur qui ne pensait sans doute pas aux autres langues, et qui n’était peut-être pas au courant du modèle d’encodage d’Unicode ni de la recommandation de prendre en charge les lettres composées par touches mortes.

Ce dérangement n’est pas dû à une limitation technique intrinsèque, car dans le tableau des touches mortes il aurait simplement fallu ajouter cinq colonnes, et programmer Windows pour les consulter et ajouter leur contenu s’il n’est pas nul.

### Chiffres

#### Bascule de mode

##### Mode ASCII

En mode ASCII, le niveau 7 ne fonctionne pas, sur les touches qui sont en mode ASCII, les touches graphiques autres que les lettres simples, et la barre d’espace. Ces touches ne donnent rien en AltGr + AltFr, mais elles fonctionnent bien en Maj + AltFr et en Maj + AltGr + AltFr.

Afin de mitiger ce bogue du niveau 7, en mode ASCII, le niveau 7 est aussi redondant que possible. Ainsi les chiffres en indice sont en Maj + AltGr en plus d’être en AltGr + AltFr.

## Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier « windows/ » où il se trouve. Mais c’est sous le nom de « Mode-d-emploi-sous-Windows.md » qu’il est inclus dans le dossier « Un-nouvel-AZERTY-Windows-[version].zip ».

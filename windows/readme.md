# Un nouvel AZERTY pour Windows

Ceci est un mode d’emploi couvrant principalement l’[installation](#installation) des pilotes d’essai. Sur l’[utilisation](#utilisation) da la future version complète, il est vivement conseillé de se reporter au [Mode d’emploi commun](https://github.com/dispoclavier/nouvel-azerty/blob/main/readme.md) ainsi qu’à la page web [Un nouvel AZERTY](https://dispoclavier.com/nouvel-azerty/) ou sa [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty.pdf) et à la présentation des [touches mortes](https://dispoclavier.com/nouvel-azerty/touches-mortes/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touches-mortes.pdf) est aussi disponible en ligne, et qui est assortie de 30 sous-pages, une par touche morte diacritique ou transformationnelle, en particulier celle sur les douze [groupes](https://dispoclavier.com/nouvel-azerty/touches-mortes/groupe/) ([version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-touche-morte-groupe.pdf)), ainsi qu’à la présentation de la [touche de composition](https://dispoclavier.com/nouvel-azerty/composition/) accompagnée de la liste des [symboles mathématiques](https://dispoclavier.com/nouvel-azerty/composition/symboles-mathematiques/), dont une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-symboles-math.pdf) est pareillement disponible en ligne, ainsi qu’une [version en PDF](https://dispoclavier.com/doc/un-nouvel-azerty-composition-non-math.pdf) de la composition non mathématique. Ces 5 PDF sont réunis dans le dossier « Un-nouvel-AZERTY-documentation-[version].zip ».

## Installation

Télécharger le dossier « Un-nouvel-AZERTY-Windows-[version].zip » sous le titre « Assets », l’extraire, aller dans le dossier dont le nom finit en « (installation) », puis dans celui qui commence par « kbfrFRs » (« kbfrFRs v4.16.0.0 installation ») et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Utilisation

Les fonctionnalités implémentables sous tous les systèmes d’exploitation pris en charge sont présentées dans le « Mode-d-emploi-commun.md ».

Ce mode d’emploi complémentaire présente uniquement ce qui est particulier à Windows.

### Lettres

#### Émulation de touche « ê »

L’émulation d’une touche « ê » par la touche morte accent circonflexe ne fonctionne pas en capitales, et [x] ne donne pas « êch ».

La raison est que sous Windows, les touches mortes sont incapables d’émettre des chaînes multicaractères (et des caractères au-dessus d’U+FFFF), et que la situation n’est sauvée que grâce au fait que sous Windows, chaque touche morte a un caractère mort, et que ce caractère mort sort tel quel si le caractère de base, celui saisi après la touche morte, n’est pas pris en charge. Grâce à cette fonctionnalité de Windows, l’émulation de touche « ê » par la touche accent circonflexe fonctionne en minuscules.

#### Verrouillage des capitales

Quand les capitales sont verrouillées, le guillemet ouvrant avec espace fine insécable est sans espace fine insécable. À la place, il faut le saisir en AltFr afin d’ajouter l’espace fine insécable, qui y est en synergie.

La raison est que ce guillemet est sur la touche « ù », qui nécessite une fonctionalité appelée « capitales suisses-allemandes » (« Swiss-German Capitals »), qui ne prend en charge ni les touches mortes, ni les séquences, sans qu’il suffirait de ne définir que le niveau qui en a réellement besoin. Cet état inachevé est dû à l’insuffisance de tests faisant l’impasse sur les écritures codées sur 3 octets, à une époque où Unicode était de fait un jeu de caractères codé sur 2 octets, et par un développeur qui n’anticipait pas que cela n’allait pas rester comme cela, et qui était insuffisamment supervisé par la hiérarchie. Les déficiences qui en résultaient ont été palliées par des logiciels tiers, sous les pieds desquels Microsoft s’est abstenu de couper l’herbe par la suite, mais qui ne sont pas facilement adoptés par les utilisateurs français pour autant, condamnés la plupart à se dépanner comme ils peuvent sur un système d’exploitation défectueux.

(La fonctionnalité « capitales suisses-allemandes » est un contournement du manque du moyen de spécifier pour chaque touche ce qu’elle sort quand le Verrouillage des Capitales est actif, moyen qui existe sous Linux et sous macOS, pour chaque niveau de touche pris en charge.)

Ce bogue n’affecte pas les variantes redisposées, où aucune lettre n’est sur la même touche qu’une ponctuation espacée, car la place du « ù » est prise par l’apostrophe, tandis que le « ù » prend la place du tiret du 6 (qui prend la place de la touche morte groupe, qui va sur la touche au-dessus à la place de la touche morte accent aigu, qui prend la place laissée par l’apostrophe).

### Chiffres

#### Bascule de mode

##### Mode ASCII

En mode ASCII, le niveau 7 ne fonctionne pas, sur les touches qui sont en mode ASCII, les touches graphiques autres que les lettres simples, et la barre d’espace. Ces touches ne donnent rien en AltGr + AltFr, mais elles fonctionnent bien en Maj + AltFr et en Maj + AltGr + AltFr.

Afin de mitiger ce bogue du niveau 7, en mode ASCII, le niveau 7 est aussi redondant que possible. Ainsi les chiffres en indice sont en Maj + AltGr en plus d’être en AltGr + AltFr.

## Nom de fichier

Ce mode d’emploi porte le nom de fichier « readme.md » afin que GitHub l’affiche automatiquement à la racine du dossier « windows/ » où il se trouve. Mais c’est sous le nom de « Mode-d-emploi-sous-Windows.md » qu’il est inclus dans le dossier « Un-nouvel-AZERTY-Windows-[version].zip ».

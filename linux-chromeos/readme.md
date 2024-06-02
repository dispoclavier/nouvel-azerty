# Un nouvel AZERTY pour Linux

## Systèmes

Ces fichiers sont développés, testés et compilés sous **Ubuntu 16.04** depuis 2018 et toujours en 2024. Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule à la fois ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et sous des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3**).

Quant à **Chrome OS**, il utilise certes XKB mais le fournit codé en dur, et même dans le conteneur Linux, l’image d’X11 est hors service. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks puissants. Le bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à Chrome OS.

## Extensions de fichiers

À l’usage, ces fichiers sont sans extension. Les extensions `.c`, `.cpp` et `.yml` servent surtout à ajouter des couleurs, et aussi à faciliter l’ouverture de ces fichiers sous Windows. L’extension `.cpp` a été choisie pour éviter `dispocla.c` ; les noms de fichier « dispo », « disposyms » et « disposymbols » ne seraient pas de bonnes alternatives.

De toute manière, les statistiques de langage sont désactivées.

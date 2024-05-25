# Un nouvel AZERTY pour Linux

## Systèmes

Ces fichiers ont été développés, testés et compilés sous **Ubuntu 16.04.** Sur la fin, ces fichiers ont aussi été testés sous **Ubuntu 24.04,** où le commutateur affiche certes toutes les dispositions installées, qu’elles soient fournies ou ajoutées, mais ne permet d’en utiliser qu’une seule à la fois ; impossible d’utiliser le commutateur pour basculer entre plusieurs dispositions ; bogue confirmé sous **Debian 12.5.0** (datant de 2023) et des distributions de Linux postérieures à Ubuntu 16.04 (testé sous **Ubuntu 18.04, Ubuntu 20.04, Linux Mint 21.3**).

La prise en charge de dispositions ajoutées sous **Chrome OS** n’est pas effective, dû à la façon dont les dispositions de clavier sont implémentées. Dans le conteneur Linux, les fichiers d’X11 sont présents mais ne fonctionnent pas. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks assez puissants. Le bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à Chrome OS.

## Extensions de fichiers

Les extensions `.c`, `.cpp` et `.yml` servent à la coloration syntaxique. L’extension `.cpp` a été choisie pour éviter `dispocla.c`. À l’usage, ces fichiers sont sans extension.

En conséquence, les statistiques de langage sont désactivées.

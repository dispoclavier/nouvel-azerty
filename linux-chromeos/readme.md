# Un nouvel AZERTY pour Linux

## Systèmes
Ces fichiers ont été testés sous Ubuntu 24.04 et Linux Mint 21.3.

La prise en charge sous Chrome OS n’est pas effective, dû à la façon dont les dispositions de clavier sont implémentées. Dans le conteneur Linux sous Chrome OS, les fichiers d’X11 sont présents mais ne fonctionnent pas. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks assez puissants. Le bug a été [signalé](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité.

## Extensions de fichiers
Les extensions `.c`, `.cpp` et `.yml` servent à la coloration syntaxique. À l’usage, ces fichiers sont sans extension.

L’extension `.cpp` a été choisie pour éviter `dispocla.c`.

En conséquence, les statistiques de langage sont désactivées.

# Un nouvel AZERTY pour Linux

## Systèmes
Ces fichiers ont été développés, testés et compilés sous Ubuntu 16.04. À partir de la version 2.0, ce nouvel AZERTY pour Linux est toujours compilé sous Ubuntu 16.04, réinstallé en dual boot à côté de Windows 10. Sur la fin, ces fichiers ont aussi été testés sous Linux Mint 21.3, où le commutateur de dispositions est bogué au point que l’installation ne sert à rien, et sous Ubuntu 24.04, où le commutateur affiche certes les dispositions ajoutées mais ne permet pas de les activer, et où même les fichiers compilés sont inutilisables, malgré que la version d’XKBCOMP soit toujours 1.4.6 ; bogue confirmé sous Debian 12.5.0.

La présence d’une “disposition personnalisée définie par l’utilisateur” (« User-defined custom layout »), affichée dans le commutateur en tant que « custom », est probablement de la poudre aux yeux camouflant un embargo sur les dispositions ajoutées, qui paraissent être proscrites. Le ou les commanditaire(s) pourraient aussi être à l’origine du [logiciel malveillant distribué avec Windows](https://dispoclavier.com/nouvel-azerty/#2250-mais-windows-10-et-11-meme-le-windows-10-de-base-22h2-sans-aucune-mise-a-jour) mettant en panne une partie des fonctionnalités comme la barre de langues, les champs de texte, le gestionnaire de fichiers, l’importation de clés de registre, tant qu’une disposition de clavier “trop” performante n’est pas retirée et l’ordinateur, redémarré. Le temps et l’argent mis à les combattre prouvent la valeur de ces dispositions de clavier, qui rapatrient une partie des insertions là où est leur place, et ce faisant, empiètent forcément sur d’anciennes chasses gardées.

La prise en charge de dispositions ajoutées sous Chrome OS n’est pas effective du tout, dû à la façon dont les dispositions de clavier sont implémentées. Dans le conteneur Linux, les fichiers d’X11 sont présents mais ne fonctionnent pas. Utiliser une disposition de clavier ajoutée comme extension de Chrome est impossible à cause d’un problème de performance, même sur les chromebooks assez puissants. Le bogue a été [rapporté](https://github.com/google/extra-keyboards-for-chrome-os/issues/135) fin janvier 2024 mais n’est pas traité, pas plus que les autres rapports de bogue dans ce dépôt officiel des dispositions de clavier ajoutées à Chrome OS.

## Extensions de fichiers
Les extensions `.c`, `.cpp` et `.yml` servent à la coloration syntaxique. L’extension `.cpp` a été choisie pour éviter `dispocla.c`. À l’usage, ces fichiers sont sans extension.

En conséquence, les statistiques de langage sont désactivées.

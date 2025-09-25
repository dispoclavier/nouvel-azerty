# 6.0.8 (2025-09-25)

Débogage des pilotes de disposition pour Windows, phase 1.

## Modifications

* Disposition : Déboguer les pilotes de disposition. kbcommon-1.c [5b92ff9](https://github.com/dispoclavier/nouvel-azerty/commit/5b92ff973eb61eb4f057e47067788ac9af16e4c5), kbcommon-2.c, kbcommon-3.c, kbfrFRs-allo.c, kbbrFRs-allo.c, kbfrAFs-allo.c, kbfrPFs-allo.c, kbfrFRsr-allo.c [d66813e](https://github.com/dispoclavier/nouvel-azerty/commit/d66813e13e185a062389f6cc41d7a837b999ba4b), kbcommon-2.c, kbcommon-3.c [f077167](https://github.com/dispoclavier/nouvel-azerty/commit/f0771674b25954f226f6daaa225dc6c88d5e6800)
* Transformations :
	* Accent aigu : Remplacer "▾" U+25BE par "▿" U+25BF. compose-2.yml [356c03d](https://github.com/dispoclavier/nouvel-azerty/commit/356c03d251ee21812dadbb54f289635c63c5c2cb)
	* Tréma : Remplacer "▿" U+25BF par "▾" U+25BE. ibidem
* Documentation :
	* Corriger et mettre à jour le tableau des symboles mathématiques. compose-1.yml [4918828](https://github.com/dispoclavier/nouvel-azerty/commit/4918828f7c5561395eff70574214f178a59c1a7d), generate-math-table.pl [3e7a66b](https://github.com/dispoclavier/nouvel-azerty/commit/3e7a66b0bd107a875c2e9bbdb434fa00df888401), [b666539](https://github.com/dispoclavier/nouvel-azerty/commit/b666539125003ae72efe050c0247e1b5157fa8a1)
	* Mettre à jour les bogues connus, section Bogue des touches mortes. kbcommon.c [9fd4717](https://github.com/dispoclavier/nouvel-azerty/commit/9fd47172e75fbbb140d6201bde2c47660a53a22e), kbcommon-1.c [5b92ff9](https://github.com/dispoclavier/nouvel-azerty/commit/5b92ff973eb61eb4f057e47067788ac9af16e4c5)
* Build : 6.0.8.00 [d66813e](https://github.com/dispoclavier/nouvel-azerty/commit/d66813e13e185a062389f6cc41d7a837b999ba4b)

## Pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai. Toutes les touches vives sont à jour, toutes les touches mortes simples aussi.

Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018 (parce que le script qui transpile le fichier « Compose.yml » n’est pas fini).

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.8.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.8/Un-nouvel-AZERTY-Windows-6.0.8.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

## Pour Linux

La version pour Linux est entièrement à jour. Non seulement les touches vives, mais aussi le contenu des touches mortes, le fichier « Compose.yml » étant (partiellement) transpilé en C pour Windows.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.8.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.8/Un-nouvel-AZERTY-Linux-6.0.8.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

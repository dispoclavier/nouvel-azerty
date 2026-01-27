# 6.2.0 (2026-01-27)

Inversion des touches mortes point souscrit et virgule souscrite suite à la version 6.0.0 (2025-08-11).

Harmonisation du niveau 3 des touches du point-virgule et du point d’exclamation.

Harmonisation du contenu des touches mortes.

## Modifications

* Disposition :
	* Maj + AltGr : Inverser la touche morte point souscrit, qui va sur B10, et la touche morte virgule souscrite, qui va sur B08. dispocla.cpp [2574be2](https://github.com/dispoclavier/nouvel-azerty/commit/2574be2da636dab55a75ce3b8a19fefa1cda9ca0), kbcomazerty.c, kbcomredispo.c [4520be4](https://github.com/dispoclavier/nouvel-azerty/commit/4520be45b7ac8e86dfd6d41c68041ef3ef7f5cb6), compose-1.yml, compose-2.yml, compose-3.yml [2e82db8](https://github.com/dispoclavier/nouvel-azerty/commit/2e82db805376d66554c2678089d9d7e1ff7d5a31), [cfa8d12](https://github.com/dispoclavier/nouvel-azerty/commit/cfa8d12739a9f456f30e9ffbd26fe8bceb54bf6a), [b11199b](https://github.com/dispoclavier/nouvel-azerty/commit/b11199b64f45e6c510ae658f14bac41efe8cfaf0), nouvel-azerty.json, nouvel-azerty-verrcap.json, nouvel-azerty-verrmod.json, nouvel-azerty-verrmod-verrcap.json, qzjfgy.json [2858190](https://github.com/dispoclavier/nouvel-azerty/commit/2858190fa067f84e3ab74c68be1dffcd08831f4a), dead-key-convert.pl, generate-multikey.pl, generate-deadkey-tables.pl, generate-multikey-tables.pl [84f2f06](https://github.com/dispoclavier/nouvel-azerty/commit/84f2f062285f75b5b1ade0eb438cf6b807b38135)
	* AltGr :
		* Mode français : Redonder le point-virgule sur B08 à la place du point d’exclamation. ibidem
		* Mode ASCII : Inverser le point d’exclamation, qui va sur B10, et le point-virgule, qui va sur B08. ibidem
* Composition : Prendre en charge la séquence « ¦Mul » pour "¦" U+00A6. compose-1.yml [b11199b](https://github.com/dispoclavier/nouvel-azerty/commit/b11199b64f45e6c510ae658f14bac41efe8cfaf0)
*	Transformations :
	* Groupes des symboles :
		* Mettre "¡" U+00A1 à la place de "ː" U+02D0, qui prend la place laissée par "¡" U+00A1. compose-3.yml [b11199b](https://github.com/dispoclavier/nouvel-azerty/commit/b11199b64f45e6c510ae658f14bac41efe8cfaf0), [a413760](https://github.com/dispoclavier/nouvel-azerty/commit/a4137604e292d1c18c88af6d970be4ca4006165c)
		* Mettre "‼" U+203C à la place de "ˑ" U+02D1, qui prend la place laissée par "‼" U+203C. ibidem
		* Mettre "❕" U+2755 à la place de "⸫" U+2E2B, qui prend la place de "∴" U+2234, qui prend la place de "⏰" U+23F0, qui prend la place de "⌚" U+231A, qui prend la place de "⋯" U+22EF, qui prend la place laissée par "❕" U+2755. ibidem
		* Mettre "❗" U+2757 à la place de "⁛" U+205B, qui prend la place laissée par "❗" U+2757. ibidem
		* Mettre "⁉" U+2049 à la place de "⸪" U+2E2A, qui prend la place de "∵" U+2235, qui prend la place de "⧗" U+29D7, qui prend la place de "❣" U+2763, qui prend la place de "⏳" U+23F3, qui prend la place laissée par "⁉" U+2049. ibidem
		* Mettre "⚠" U+26A0 à la place de "⋱" U+22F1, qui prend la place de "⧖" U+29D6, qui prend la place de "❢" U+2762, qui prend la place de "⌛" U+231B, qui prend la place laissée par "⚠" U+26A0. ibidem
		* Mettre "⏱" U+23F1 à la place de "⋰" U+22F0, qui prend la place de "⏲" U+23F2, qui prend la place laissée par "⏱" U+23F1. ibidem
	* Séquences spécifiques à Windows : Prendre en charge les équivalents en composition. compose-2.yml [b11199b](https://github.com/dispoclavier/nouvel-azerty/commit/b11199b64f45e6c510ae658f14bac41efe8cfaf0)
* Documentation : Corriger ou ajouter des annotations. compose-1.yml, compose-2.yml, compose-3.yml [b11199b](https://github.com/dispoclavier/nouvel-azerty/commit/b11199b64f45e6c510ae658f14bac41efe8cfaf0)
* Build : 6.1.9.0 [1b44e3e](https://github.com/dispoclavier/nouvel-azerty/commit/1b44e3e0c63b0fa6379ce63b9bffd13c378618f9), [9ebae51](https://github.com/dispoclavier/nouvel-azerty/commit/9ebae512ac3df271039da8c998fe50bb8b7586e2), [6d7c695](https://github.com/dispoclavier/nouvel-azerty/commit/6d7c695ddecbb4b081bfedd330d3918bfa57b4fd)
* Build : 6.2.0.0 [32c4d2f](https://github.com/dispoclavier/nouvel-azerty/commit/32c4d2f5b17c1d16c48bd41d0ec61b9331ca1cf9)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.0/Un-nouvel-AZERTY-Windows-6.2.0.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.0/Un-nouvel-AZERTY-Windows-variantes-6.2.0.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.0/Un-nouvel-AZERTY-Linux-6.2.0.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-01-27 |
|-|

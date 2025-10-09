# 6.0.9 (2025-10-02)

| Dernière mise à jour le 9/10/2025 |
|-|

Dépannage des pilotes de disposition pour Windows, phase 2.

Complétion et simplification de séquences de composition.

## Modifications

* Pilotes de disposition :
	* Fournir des clones de dépannage. kbfrFRs2.C, kbfrFRr2.C [41512f2](https://github.com/dispoclavier/nouvel-azerty/commit/41512f2dbaad6c0b4263902214f486682053b310), [a361b04](https://github.com/dispoclavier/nouvel-azerty/commit/a361b04af93c721b97bf1c7214a1fc960b92ad19), kbbrFRs2.C, kbfrAFs2.C, kbfrPFs2.C [71edaea](https://github.com/dispoclavier/nouvel-azerty/commit/71edaea623bb75946c19cbef29408d5195d702c3)
	* Renommer les dispositions en kb****(s|r)1. [711d66f](https://github.com/dispoclavier/nouvel-azerty/commit/711d66f119a20f0c34410b7331355619871d0edb)
		* kbbrFRs.C devient kbbrFRs1.C [9ce57ca](https://github.com/dispoclavier/nouvel-azerty/commit/9ce57caa34e4a5f42f42a6f3c2b50daeefb23487)
		* kbbrFRs.klc devient kbbrFRs1.klc [190881e](https://github.com/dispoclavier/nouvel-azerty/commit/190881e9c8d7afa8d9a1046a6d029a93dedb846c)
		* kbbrFRs.RC devient kbbrFRs1.RC [6491d6e](https://github.com/dispoclavier/nouvel-azerty/commit/6491d6e4e91a095f6c65a3cf48d5d1d84998c1d4)
		* kbfrAFs.C devient kbfrAFs1.C [586c1fe](https://github.com/dispoclavier/nouvel-azerty/commit/586c1fed4efa4ade7d0ca7d3d1271fd1b98ec5db)
		* kbfrAFs.klc devient kbfrAFs1.klc [f709f58](https://github.com/dispoclavier/nouvel-azerty/commit/f709f58b9cf77ad0be0fd9f281a6519ca1e71407)
		* kbfrAFs.RC devient kbfrAFs1.RC [cfe535c](https://github.com/dispoclavier/nouvel-azerty/commit/cfe535cce332e6deff0bb3ed936c6f10f1c406ce)
		* kbfrFRs.C devient kbfrFRs1.C [77379ea](https://github.com/dispoclavier/nouvel-azerty/commit/77379ea358e03b9a9fb5ac3a86c8e3749bbd7a27)
		* kbfrFRs.klc devient kbfrFRs1.klc [7179f4a](https://github.com/dispoclavier/nouvel-azerty/commit/7179f4a4f121cf2068fb95580a6446c0485f0138)
		* kbfrFRs.RC devient kbfrFRs1.RC [ccfe777](https://github.com/dispoclavier/nouvel-azerty/commit/ccfe77790c74df267d1110806045421fed0329b8)
		* kbfrPFs.C devient kbfrPFs1.C [5c0f878](https://github.com/dispoclavier/nouvel-azerty/commit/5c0f8783cdd1d061b3eac89fef481ebae8559b8f)
		* kbfrPFs.klc devient kbfrPFs1.klc [f19b70b](https://github.com/dispoclavier/nouvel-azerty/commit/f19b70bf23681136ae707a3533aab188e5ae5668)
		* kbfrPFs.RC devient kbfrPFs1.RC [851306a](https://github.com/dispoclavier/nouvel-azerty/commit/851306ac953df549bcbe8f69a14c111487b67bb2)
		* redispo/kbfrFRsr.C devient redispo/kbfrFRr1.C [79c40ba](https://github.com/dispoclavier/nouvel-azerty/commit/79c40bad0737b1a1b1104ec52c484650bb5d9d8c)
		* redispo/kbfrFRsr.klc devient redispo/kbfrFRr1.klc [b64c48a](https://github.com/dispoclavier/nouvel-azerty/commit/b64c48ad923ccec292432f4177f7c90e3e2a971e)
		* redispo/kbfrFRsr.RC devient redispo/kbfrFRr1.RC [dc8ae9e](https://github.com/dispoclavier/nouvel-azerty/commit/dc8ae9e9d0d0953542297aa8ff625f920f5d1f1f)
		* redispo/kbfrFRsr-allo.c devient redispo/kbfrFRr-allo.c [a6c7d0e](https://github.com/dispoclavier/nouvel-azerty/commit/a6c7d0e49a2f0ac8d103b5382e1c61e711c36c2a)
		* kbcommon.H devient kbcommon.h [6dc70f2](https://github.com/dispoclavier/nouvel-azerty/commit/6dc70f26f58364e9e93a01edc54f7cded04bb1da)
	* Déboguer les numéros de version dans les métadonnées. kbbrFRs.RC, kbfrAFs.RC, kbfrFRr2.RC, kbfrFRs2.RC, kbfrFRs.RC, kbfrFRsr.RC, kbfrPFs.RC [1ec3bda](https://github.com/dispoclavier/nouvel-azerty/commit/1ec3bda65e4e885f0dc5aebf725c25b200f5c619)
	* Centraliser le versionnage. kbversion-int.RC, kbversion-str.RC, kbbrFRs.RC, kbfrAFs.RC, kbfrFRr2.RC, kbfrFRs2.RC, kbfrFRs.RC, kbfrFRsr.RC, kbfrPFs.RC [756a357](https://github.com/dispoclavier/nouvel-azerty/commit/756a357dab635d1ed7649514644c43c033373c0b)
	* Corriger le versionnage.
		* kbversion-int.rc [47e62a5](https://github.com/dispoclavier/nouvel-azerty/commit/47e62a5d7d3a1c654742870a63c93f9a27dd67d3)
		* kbversion-str.rc [a6e7acc](https://github.com/dispoclavier/nouvel-azerty/commit/a6e7acc3bfae74aeba61ad3f458153fab1408d38)
		* kbligatures.c [ddd6cb2](https://github.com/dispoclavier/nouvel-azerty/commit/ddd6cb2f894aedd4d9334059abceec3906d37793)
* Composition :
	* Simplifier et compléter les séquences de "⋇" U+22C7. compose-1.yml [cbb719d](https://github.com/dispoclavier/nouvel-azerty/commit/cbb719dcb4e26e1427c91c560f03d1b1060f305b), [105f4d7](https://github.com/dispoclavier/nouvel-azerty/commit/105f4d7b68211409cdf6b24d9918f15b2f8216d6)
	* Adapter la séquence de "🣖" U+1F8D6. ibidem
	* Compléter les séquences de "⋋" U+22CB, "⋌" U+22CC. compose-1.yml [a6e4f3e](https://github.com/dispoclavier/nouvel-azerty/commit/a6e4f3e56621cd22ae04ac6fd2b18ca11cdd0ca9), [248c997](https://github.com/dispoclavier/nouvel-azerty/commit/248c997805184ff64a8979987c40e0aefa547191)
* Documentation :
	* Mettre à jour le mode d’emploi condensé sous Windows. Lisez-moi-svp.md [059b202](https://github.com/dispoclavier/nouvel-azerty/commit/059b2023d70a48616e63f64d9133f2ad549c8992)
	* Corriger et mettre à jour des annotations dans les fichiers KLC. kbbrFRs.klc, kbfrAFs.klc, kbfrFRr2.klc, kbfrFRs2.klc, kbfrFRs.klc, kbfrFRsr.klc, kbfrPFs.klc [9e041f8](https://github.com/dispoclavier/nouvel-azerty/commit/9e041f8cbe829073c0793254509cdc02a3c06de1), [ddd6cb2](https://github.com/dispoclavier/nouvel-azerty/commit/ddd6cb2f894aedd4d9334059abceec3906d37793)
* Builds :
	* 6.0.9.00 [41512f2](https://github.com/dispoclavier/nouvel-azerty/commit/41512f2dbaad6c0b4263902214f486682053b310)
	* 6.0.9.01 [a361b04](https://github.com/dispoclavier/nouvel-azerty/commit/a361b04af93c721b97bf1c7214a1fc960b92ad19)
	* 6.0.9.02 [1ec3bda](https://github.com/dispoclavier/nouvel-azerty/commit/1ec3bda65e4e885f0dc5aebf725c25b200f5c619)
	* 6.0.9.03 mojibake.
	* 6.0.9.04 échec.
	* 6.0.9.05 [756a357](https://github.com/dispoclavier/nouvel-azerty/commit/756a357dab635d1ed7649514644c43c033373c0b)
	* 6.0.9.6 [9e041f8](https://github.com/dispoclavier/nouvel-azerty/commit/9e041f8cbe829073c0793254509cdc02a3c06de1)
	* 6.0.9.7 [ddd6cb2](https://github.com/dispoclavier/nouvel-azerty/commit/ddd6cb2f894aedd4d9334059abceec3906d37793)
	* 6.0.9.8 [711d66f](https://github.com/dispoclavier/nouvel-azerty/commit/711d66f119a20f0c34410b7331355619871d0edb)
	* 6.0.9.9 [71edaea](https://github.com/dispoclavier/nouvel-azerty/commit/71edaea623bb75946c19cbef29408d5195d702c3)

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

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis le 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie. Du total il faut soustraire les téléchargements effectués par SourceForge (156 jusqu’à la version 6.0.9).

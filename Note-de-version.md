# 6.0.10 (2025-10-12)

Complétion du mode d’emploi des fichiers d’inscription au Registre.

Correction, complétion et simplification de séquences de composition.

Complétion de la touche morte accent aigu.

## Modifications

* Composition :
	* Redonder les coups de glotte "ƾ" U+01BE, "Ɂ" U+0241, "ɂ" U+0242, "ʔ" U+0294, "ʕ" U+0295, "ʖ" U+0296, "ʡ" U+02A1, "ʢ" U+02A2, "ˀ" U+02C0, "ˁ" U+02C1, "ˤ" U+02E4, "𐞳" U+107B3, "𐞴" U+107B4, "𝼎" U+1DF0E. compose-1.yml [71360f5](https://github.com/dispoclavier/nouvel-azerty/commit/71360f5560e4b129e9e7fbd71e89c07423fdb723)
	* Redonder "ŉ" U+0149 par « ¦&n ». ibidem
	* Compléter les séquences de "ɮ" U+026E, "𐞊" U+1078A, "𐞞" U+1079E. compose-1.yml [55d9730](https://github.com/dispoclavier/nouvel-azerty/commit/55d9730f97708f0748792ff365a403b8345bb482)
	* Ajouter "⇱" U+21F1 à la place de "↸" U+21B8. compose-1.yml [b2ace6c](https://github.com/dispoclavier/nouvel-azerty/commit/b2ace6cff8d2ee232f2fcf900b2cd76caab26129)
	* Ajouter "⇲" U+21F2. ibidem
	* Simplifier les séquences de "⋎" U+22CE, "⋏" U+22CF, "⋔" U+22D4, "⋕" U+22D5, "⋘" U+22D8, "⋙" U+22D9, "⋞" U+22DE, "⋟" U+22DF, "⋠" U+22E0, "⋡" U+22E1. ibidem
	* Compléter les séquences de "⋐" U+22D0. ibidem
	* Simplifier et compléter les séquences de "⋢" U+22E2, "⋣" U+22E3, "⋤" U+22E4, "⋥" U+22E5. compose-1.yml [0236e61](https://github.com/dispoclavier/nouvel-azerty/commit/0236e61769521aa4aa1eadf7b2e6cc170cb3c6a4)
	* Simplifier les séquences de "⋦" U+22E6, "⋧" U+22E7, "⋨" U+22E8, "⋩" U+22E9. compose-1.yml [f5a5061](https://github.com/dispoclavier/nouvel-azerty/commit/f5a5061797ce1d51f665d337c2415295bd54b3ee)
* Transformations : Accent aigu :
	* Redonder "Ñ" U+00D1, "ñ" U+00F1 par "È" U+00C8, "è" U+00E8. compose-2.yml [](), kbdeadtrans.c [8101eb6](https://github.com/dispoclavier/nouvel-azerty/commit/8101eb63e73531313ccbf1fd94a85bfbbea71f71)
	* Redonder "ʔ" U+0294 par "ù" U+00F9, "Ù" U+00D9. ibidem
* Sous-variantes : Mettre à jour, corriger et compléter les fichiers d’inscription au Registre et leur mode d’emploi. windows/redispositions/readme.md alias _Scancode_Map.md [680a5b5](https://github.com/dispoclavier/nouvel-azerty/commit/680a5b5feff04b7baa0c21c25244ec43bb85ce6f), [25de410](https://github.com/dispoclavier/nouvel-azerty/commit/25de410b41e51c6732e63214dbc41992cab6b1a1), [135574f](https://github.com/dispoclavier/nouvel-azerty/commit/135574fd8e0ebbd460cd86a42359bd03dc844dec)
* Documentation :
	* Corriger les modes d’emploi. readme.md alias Mode-d-emploi-commun.md [0ce9a9a](https://github.com/dispoclavier/nouvel-azerty/commit/0ce9a9ab5813c366fb7fffd3592bdbe6dc9095d7), linux-chromeos/Lisez-moi-svp.md, windows/Lisez-moi-svp.md [a25897e](https://github.com/dispoclavier/nouvel-azerty/commit/a25897e82e8e097f55ab01d9f54b77baf7135b5c)
	* Corriger ou mettre à jour des annotations. compose-1.yml [71360f5](https://github.com/dispoclavier/nouvel-azerty/commit/71360f5560e4b129e9e7fbd71e89c07423fdb723), [55d9730](https://github.com/dispoclavier/nouvel-azerty/commit/55d9730f97708f0748792ff365a403b8345bb482), [874f34c](https://github.com/dispoclavier/nouvel-azerty/commit/874f34ca27fb1fa5bc712d65a5e8176a7db21e52) ; [b2ace6c](https://github.com/dispoclavier/nouvel-azerty/commit/b2ace6cff8d2ee232f2fcf900b2cd76caab26129), compose-2.yml ibidem ; kbdeadtrans.c [31c3ca4](https://github.com/dispoclavier/nouvel-azerty/commit/31c3ca4327013ff9f846ea05ec7e52348070ddef), [e3c2cda](https://github.com/dispoclavier/nouvel-azerty/commit/e3c2cda9c0b6dc70aed5b4450f4db744b9bcca23), [eddf873](https://github.com/dispoclavier/nouvel-azerty/commit/eddf873970063a0346791ed86c31810d0c65603e), dead-key-convert.pl [a2cecf8](https://github.com/dispoclavier/nouvel-azerty/commit/a2cecf8a2ba2c070bd30b6dc5a696723b7cf572f), [80b0bce](https://github.com/dispoclavier/nouvel-azerty/commit/80b0bce7e6a828a6557fde1c867fcd1429aee0a6)
* Build : 6.0.10.0 [7667a1b](https://github.com/dispoclavier/nouvel-azerty/commit/7667a1b35afe593a226d9a8e4311d5df4409b32e)

## Pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai. Toutes les touches vives sont à jour, toutes les touches mortes simples aussi.

Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018 (parce que le script qui transpile le fichier « Compose.yml » n’est pas fini).

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.10.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.10/Un-nouvel-AZERTY-Windows-6.0.10.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

La version pour Linux est entièrement à jour. Non seulement les touches vives, mais aussi le contenu des touches mortes, le fichier « Compose.yml » étant (partiellement) transpilé en C pour Windows.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.10.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.10/Un-nouvel-AZERTY-Linux-6.0.10.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-10-13 |
|-|

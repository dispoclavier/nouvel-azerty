# 6.1.1 (2025-10-29)

Transpilation pour Windows des enchaînements de touches mortes grecs polytoniques et monotoniques.

Correction, complétion et simplification de séquences de composition.

## Modifications

* Composition :
	* Compléter les séquences de "⋻" U+22FB (et supprimer "¶" U+00B6 par « ¦P| » et « ¦p| » qui ne sont pas dans en_US.UTF-8/Compose). compose-1.yml [0a8980e](https://github.com/dispoclavier/nouvel-azerty/commit/0a8980ef1bb08bbcb867e1ec00cdcc978d938889)
	* Simplifier les séquences de "⋬" U+22EC, "⋲" U+22F2, "⋵" U+22F5, "⋸" U+22F8, "⋹" U+22F9, "⋺" U+22FA, "⋼" U+22FC, "⋿" U+22FF, "⌈" U+2308, "⌋" U+230B. ibidem
	* Compléter et simplifier les séquences de "⍼" U+237C, "⏢" U+23E2. ibidem
	* Corriger les séquences de "▮" U+25AE. compose-1.yml [f76816b](https://github.com/dispoclavier/nouvel-azerty/commit/f76816bb88bb66fea8acb5a1da3ac35334309cb6)
	* Simplifier les séquences de "▯" U+25AF, "▰" U+25B0, "▱" U+25B1, "▲" U+25B2, "▶" U+25B6, "▾" U+25BE, "▿" U+25BF. ibidem
	* Simplifier les séquences de "◀" U+25C0, "◁" U+25C1. compose-1.yml [e18f928](https://github.com/dispoclavier/nouvel-azerty/commit/e18f9288c5314d38f3e7d67cae1fd59a87eb04c6)
	* Simplifier les séquences de "◊" U+25CA, "◐" U+25D0, "◢" U+25E2, "◣" U+25E3, "◤" U+25E4, "◧" U+25E7, "◨" U+25E8, "◩" U+25E9, "◪" U+25EA, "◫" U+25EB, "◬" U+25EC, "◸" U+25F8, "◻" U+25FB, "◼" U+25FC, "◾" U+25FE, "◿" U+25FF. compose-1.yml [1e9877d](https://github.com/dispoclavier/nouvel-azerty/commit/1e9877de5f466580266c5ae832daa224ffdbf68c)
* Transformations : Enchaînements de touches mortes grecs polytoniques et monotoniques : Porter sous Windows. dead-key-convert.pl [8c31ce0](https://github.com/dispoclavier/nouvel-azerty/commit/8c31ce0f94b27ffa54793e9972cd19aa77906a80), kbdeadtrans.c [aff9a9c](https://github.com/dispoclavier/nouvel-azerty/commit/aff9a9c06dc835525af7e0fef085c912dcee193b)
* Documentation :
	* Ajouter le tableau des lettres grecques diacritées. generate-deadkey-tables.pl [f8d8da2(https://github.com/dispoclavier/nouvel-azerty/commit/f8d8da248c717e8cfe6c6f140aee5feeacdb0744)
	* Mettre à jour le mode d’emploi. readme.md alias Mode-d-emploi-commun.md [c957d08](https://github.com/dispoclavier/nouvel-azerty/commit/c957d08efbfff17a9faaa42354e37d27c0a9bd5d)
	* Mettre à jour les infobulles des tableaux. generate-math-table.pl, generate-multikey-tables.pl, generate-deadkey-tables.pl [1071cc4](https://github.com/dispoclavier/nouvel-azerty/commit/1071cc4445b523f5f4d0142f310db9902e9b9efd), [a1458e8](https://github.com/dispoclavier/nouvel-azerty/commit/a1458e83cdd4c9789f0fb157cb7aaba30f8873dc)
	* Ajouter une note juridique. compose-1.yml [73efbca](https://github.com/dispoclavier/nouvel-azerty/commit/73efbca712887774d7fd1bab1f5b313f962b00f2)
	* Corriger des annotations. compose-1.yml [d4d59bf](https://github.com/dispoclavier/nouvel-azerty/commit/d4d59bf271b1fa27ad9e51a8742ee014c7dbfbcd), compose-3.yml [0a8980e](https://github.com/dispoclavier/nouvel-azerty/commit/0a8980ef1bb08bbcb867e1ec00cdcc978d938889)
* Build : 6.1.1.0 [aff9a9c](https://github.com/dispoclavier/nouvel-azerty/commit/aff9a9c06dc835525af7e0fef085c912dcee193b)

## Pour Windows

Les touches vives et les touches mortes de la version pour Windows sont à jour, sauf la touche de composition, encore à l’état de 2018. Le reste du fichier « Compose.yml » est transpilé en C pour Windows.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.1.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.1/Un-nouvel-AZERTY-Windows-6.1.1.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes de la version pour Linux sont à jour, mais la touche de composition est encore en cours de développement.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.1/Un-nouvel-AZERTY-Linux-6.1.1.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-10-29 |
|-|

# 6.1.4 (2025-12-22)

Transpilation pour Windows des séquences de composition dédiées.

Débogage, simplification ou correction de plusieurs séquences de composition.

## Modifications

* Composition :
	* Déboguer la séquence de "⤷" U+2937. compose-1.yml [451b4b7](https://github.com/dispoclavier/nouvel-azerty/commit/451b4b7f50a05d2f429789000bdf24162cd345f1)
	* Transpiler pour Windows les séquences de composition dédiées. dead-key-convert.pl [7284fab](https://github.com/dispoclavier/nouvel-azerty/commit/7284fab2f5fd9b723e53b91ba6de3fc38141056d), [d3ee05b](https://github.com/dispoclavier/nouvel-azerty/commit/d3ee05b94d048cdd86ef7af287737b2d49f65148), [caa8d64](https://github.com/dispoclavier/nouvel-azerty/commit/caa8d640714d395913e2863e9c1cd804d67f7f08), [ed5c46a](https://github.com/dispoclavier/nouvel-azerty/commit/ed5c46a252eff24e71b0623b111736261df1c789), kbdeadtrans.c, kbdeadtrans-multikey.c [912288a](https://github.com/dispoclavier/nouvel-azerty/commit/912288a235b4ff3352e417fbe2fc81d132bc33d9)
	* Compléter les séquences de "ℎ" U+210E, "ℏ" U+210F. compose-1.yml [8725e5f](https://github.com/dispoclavier/nouvel-azerty/commit/8725e5f675b7db452d8518b8edb14aa7e71d1de5), [b80ec55](https://github.com/dispoclavier/nouvel-azerty/commit/b80ec5563464dde3806d36c18321b48a0c6d276d)
* Documentation :
	* Corriger les tableaux des touches mortes et des séquences de composition. generate-deadkey-tables [1b589d6](https://github.com/dispoclavier/nouvel-azerty/commit/1b589d6245797649976a4ff6606bf461f63d49dd) ; idem, generate-multikey-tables, generate-math-table [02cdc01](https://github.com/dispoclavier/nouvel-azerty/commit/02cdc014e79654715161978b19ae760e9af8c032)
	* Tri des séquences de touches mortes et de composition : Raccourcir un nom de symbole. compose-1.yml [451b4b7](https://github.com/dispoclavier/nouvel-azerty/commit/451b4b7f50a05d2f429789000bdf24162cd345f1)
	* Compléter une annotation. compose-1.yml [8725e5f](https://github.com/dispoclavier/nouvel-azerty/commit/8725e5f675b7db452d8518b8edb14aa7e71d1de5)
* Build : 6.1.4.0 [912288a](https://github.com/dispoclavier/nouvel-azerty/commit/912288a235b4ff3352e417fbe2fc81d132bc33d9)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.4/Un-nouvel-AZERTY-Windows-6.1.4.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.4/Un-nouvel-AZERTY-Windows-variantes-6.1.4.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.4/Un-nouvel-AZERTY-Linux-6.1.4.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-12-22 |
|-|

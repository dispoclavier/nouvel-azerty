# 6.2.2 (2026-02-08)

Complétion des séquences de touches mortes spécifiques à Windows.

Correction et simplification du contenu des touches mortes.

Généralisation de raccourcis à touche morte développés sous Windows.

## Modifications

* Disposition : AltGr + Échap : Mettre à jour les descripteurs des dispositions de clavier redisposées. compose-1.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
*	Transformations :
	* Corriger la mise en forme. compose-2.yml [123f206](https://github.com/dispoclavier/nouvel-azerty/commit/123f20638ccb0ee08dd91779680235d5bf2f2ab8), [958bfa2](https://github.com/dispoclavier/nouvel-azerty/commit/958bfa2b0f937fffefd0555b181cb9c848e79954), [bc92f7f](https://github.com/dispoclavier/nouvel-azerty/commit/bc92f7f55cc0fdb6a33d9a2ff803fc0615553a32), [658a778](https://github.com/dispoclavier/nouvel-azerty/commit/658a77887fed8ce47fe7ef6c6d2c07c3e5909374), [9460077](https://github.com/dispoclavier/nouvel-azerty/commit/94600774a05e019429c5f409324757d24bf3b46f)
	* Groupes des symboles : Redonder "√" U+221A, "∛" U+221B, "∜" U+221C, "♻" U+267B, "☢" U+2622, "♼" U+267C, "♽" U+267D, "⛯" U+26EF, "♋" U+264B, "⌫" U+232B, "®" U+00AE, "∖" U+2216 par "·" U+00B7. compose-3.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
	* Réfléchi : Redonder "ʕ" U+0295 par "q", "Q" à la place de "꟎" U+A7CE, "꟏" U+A7CF, qui vont dans le groupe 1, et le supprimer par "G". compose-2.yml [044c99d](https://github.com/dispoclavier/nouvel-azerty/commit/044c99d30858177f380a0ffd55e584a69ed4b796)
	* Tilde et perluète : Redonder  "⃠" U+20E0 par "·" U+00B7. compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
	* Grec-ou-cerclé > Cerclé : Redonder "⦸" U+29B8 par "·" U+00B7. ibidem
	* Accent aigu :
		* Redonder "▿" U+25BF par la touche morte grec-ou-cerclé. compose-2.yml [21391b7](https://github.com/dispoclavier/nouvel-azerty/commit/21391b76bf27d010fb1f61fb03aa14681e19f101)
		* Groupe 1 : Redonder "Ŋ́", "ŋ́", "Ɔ́", "ɔ́". compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
	* Rayé : Redonder "ʢ" U+02A2 par "·" U+00B7. ibidem
	* Cornu :
		* Redonder "⃥" U+20E5 par "·" U+00B7. ibidem
		* Redonder "ꭕ" U+AB55 et "ꭙ" U+AB59. compose-2.yml [044c99d](https://github.com/dispoclavier/nouvel-azerty/commit/044c99d30858177f380a0ffd55e584a69ed4b796)
	* Macron :
		* Redonder "ꟾ" U+A7FE par "J", "j". compose-2.yml [bc92f7f](https://github.com/dispoclavier/nouvel-azerty/commit/bc92f7f55cc0fdb6a33d9a2ff803fc0615553a32)
		* Redonder "ⱷ" U+2C77 par "f". ibidem
		* Redonder "ɸ" U+0278 par "F". ibidem
		* Redonder "ꭆ" U+AB46 par "R" à la place de "ɺ" U+027A, qui va dans le groupe 1 et qui y est aussi dans tourné. compose-2.yml [63954a2](https://github.com/dispoclavier/nouvel-azerty/commit/63954a2841acccfd304c6314f33805ecb1f6ea30)
		* Groupe 1 :
			* Redonder "ɺ" U+027A par "r" et "R". ibidem
			* Redonder "Ƞ" U+0220, "ƞ" U+019E, pour Windows aussi dans le groupe 0. compose-2.yml [044c99d](https://github.com/dispoclavier/nouvel-azerty/commit/044c99d30858177f380a0ffd55e584a69ed4b796)
			* Compléter les séquences de "Ǣ" U+01E2, "ǣ" U+01E3, "Ƞ" U+0220, "ƞ" U+019E. compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
			* Compléter les séquences de "ꭕ" U+AB55, "ꭙ" U+AB59 pour Windows. ibidem
		* Groupe 2 :
			* Redonder "ꭕ" U+AB55 et "ꭙ" U+AB59, pour Windows aussi dans le groupe 1. ibidem
			* Compléter les séquences de "ʗ" U+0297, "ʗ" U+0297, "ꭕ" U+AB55, "ꭙ" U+AB59. ibidem
		* Groupe 3 : Compléter les séquences de "ꭕ" U+AB55, "ꭙ" U+AB59. ibidem
		* Macron et tilde : Compléter les séquences de "Ū̃", "ū̃". ibidem
		* Macron et accent aigu : Compléter les séquences de "᷄" U+1DC4, "Ḗ" U+1E16, "ḗ" U+1E17, "Ṓ" U+1E52, "ṓ" U+1E53, "Ū́", "ū́". ibidem
		* Macron souscrit : Redonder "⦥" U+29A5 par "·" U+00B7. ibidem
	* Accent circonflexe : Redonder "⍽" U+237D par la touche morte grec-ou-cerclé. compose-2.yml [21391b7](https://github.com/dispoclavier/nouvel-azerty/commit/21391b76bf27d010fb1f61fb03aa14681e19f101)
	* Hatchek :
		* Compléter les séquences de "Ʊ̌". compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
		* Groupe 1 : Compléter les séquences de "⸷" U+2E37, "Ǯ" U+01EE, "ǯ" U+01EF. ibidem
	* Drapeau :
		* Compléter les séquences de "⊇" U+2287, "⊆" U+2286. ibidem
		* Redonder "🏴󠁧󠁢󠁳󠁣󠁴󠁿" par la touche morte grec-ou-cerclé. compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
	* Cédille : Supprimer "ꭕ" U+AB55 et "ꭙ" U+AB59, qui vont dans cornu. compose-2.yml [044c99d](https://github.com/dispoclavier/nouvel-azerty/commit/044c99d30858177f380a0ffd55e584a69ed4b796)
	* Tréma : Redonder "▾" U+25BE par la touche morte grec-ou-cerclé. compose-2.yml [21391b7](https://github.com/dispoclavier/nouvel-azerty/commit/21391b76bf27d010fb1f61fb03aa14681e19f101)
* Documentation :
	* Tableaux de touches mortes :
		* Compléter avec les lettres pour les langues au Togo, qui étaient dans un tableau dédié. compose-2.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5), generate-deadkey-tables [59286c4](https://github.com/dispoclavier/nouvel-azerty/commit/59286c4fda55223407cb208da8637a0a514970bc), [6c0af06](https://github.com/dispoclavier/nouvel-azerty/commit/6c0af062f9d3a662ad91daf0752576135c252e27)
		* Corriger l’espacement des ponctuations. generate-deadkey-tables [59286c4](https://github.com/dispoclavier/nouvel-azerty/commit/59286c4fda55223407cb208da8637a0a514970bc)
	* Ajouter, corriger ou mettre à jour des annotations. compose-2.yml [044c99d](https://github.com/dispoclavier/nouvel-azerty/commit/044c99d30858177f380a0ffd55e584a69ed4b796), [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5), [658a778](https://github.com/dispoclavier/nouvel-azerty/commit/658a77887fed8ce47fe7ef6c6d2c07c3e5909374), [63954a2](https://github.com/dispoclavier/nouvel-azerty/commit/63954a2841acccfd304c6314f33805ecb1f6ea30), compose-1.yml, compose-3.yml [7af2bd2](https://github.com/dispoclavier/nouvel-azerty/commit/7af2bd29e29e1de1632f99ee40accc923b783cf5)
* Build : 6.2.2.0 [5d9fb4b](https://github.com/dispoclavier/nouvel-azerty/commit/5d9fb4bb873046ccb48ff152e238c94c09a42d80)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.2/Un-nouvel-AZERTY-Windows-6.2.2.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.2/Un-nouvel-AZERTY-Windows-variantes-6.2.2.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.2.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.2/Un-nouvel-AZERTY-Linux-6.2.2.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-02-08 |
|-|

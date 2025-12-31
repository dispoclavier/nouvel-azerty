# 6.1.5 (2025-12-31)

Correction des séquences de composition des ciseaux et des coups de glotte.

Simplification de la saisie de symboles mathématiques.

Prise en charge de "х" U0445 utilisé comme symbole de multiplication.

## Modifications

* Composition :
	* Corriger les séquences de "✀" U+2700, "✁" U+2701, "✂" U+2702, "✃" U+2703, "✄" U+2704. compose-1.yml [f14575e](https://github.com/dispoclavier/nouvel-azerty/commit/f14575e151b54d497ac8c2b52022aa83b1477391)
	* Corriger les séquences de "ƾ" U+01BE, "Ɂ" U+0241, "ɂ" U+0242, "ʔ" U+0294, "ʕ" U+0295, "ʖ" U+0296, "ʡ" U+02A1, "ʢ" U+02A2, "ˀ" U+02C0, "ˁ" U+02C1, "ˤ" U+02E4, "𐞳" U+107B3, "𐞴" U+107B4, "𝼎" U+1DF0E. ibidem
	* Prendre en charge "х" U+0445 pour son usage comme symbole de multiplication alternatif. compose-1.yml [d92a98b](https://github.com/dispoclavier/nouvel-azerty/commit/d92a98b8415d3ed23f74aa4b00d12d5ba6f4bc09), [60d9ada](https://github.com/dispoclavier/nouvel-azerty/commit/60d9ada2773f5178f740ce0f877893e51d94a0bb), [f531a41](https://github.com/dispoclavier/nouvel-azerty/commit/f531a4107feae9af8eea9affb5a5bc13c68c8f36)
	* Simplifier la saisie des séquences de "⤾" U+293E. compose-1.yml [6c75ee9](https://github.com/dispoclavier/nouvel-azerty/commit/6c75ee9e5adf473e9d65477c9c81daf8afda135e)
	* Simplifier la saisie des séquences de "϶" U+03F6, "᷏" U+1DCF, "⁡" U+2061, "⁢" U+2062, "⃘" U+20D8, "⃙" U+20D9, "⃚" U+20DA, "℩" U+2129, "⅄" U+2144, "↫" U+21AB, "↬" U+21AC, "⇴" U+21F4, "∀" U+2200, "∇" U+2207, "∐" U+2210, "√" U+221A, "∛" U+221B, "∜" U+221C, "∝" U+221D, "∧" U+2227, "∾" U+223E, "≙" U+2259, "≚" U+225A, "≝" U+225D, "≞" U+225E, "⊌" U+228C, "⊜" U+229C, "⊝" U+229D, "⊠" U+22A0, "⋀" U+22C0, "⋏" U+22CF. compose-1.yml [d92a98b](https://github.com/dispoclavier/nouvel-azerty/commit/d92a98b8415d3ed23f74aa4b00d12d5ba6f4bc09), [60d9ada](https://github.com/dispoclavier/nouvel-azerty/commit/60d9ada2773f5178f740ce0f877893e51d94a0bb), generate-math-table.pl [44860ab](https://github.com/dispoclavier/nouvel-azerty/commit/44860ab7ccc2f7406fa1f35f0435d95b50074001)
	* Adapter les séquences de "⩔" U+2A54, "⩚" U+2A5A, "⩜" U+2A5C, "⩟" U+2A5F, "⩠" U+2A60. compose-1.yml [60d9ada](https://github.com/dispoclavier/nouvel-azerty/commit/60d9ada2773f5178f740ce0f877893e51d94a0bb)
	* Simplifier la saisie des séquences de "∟" U+221F, "⊠" U+22A0, "⊰" U+22B0, "⊱" U+22B1, "⊾" U+22BE, "⋇" U+22C7, "⋎" U+22CE,"⋏" U+22CF, "⋐" U+22D0, "⋑" U+22D1, "⋒" U+22D2, "⋓" U+22D3, "⍼" U+237C, "●" U+25CF, "◐" U+25D0, "◑" U+25D1, "◒" U+25D2, "◓" U+25D3, "☑" U+2611, "☒" U+2612, "♣" U+2663, "♭" U+266D, "♮" U+266E, "♯" U+266F, "⟀" U+27C0, "⟁" U+27C1, "⟇" U+27C7, "⟎" U+27CE, "⟏" U+27CF, "⟑" U+27D1, "⟓" U+27D3, "⟔" U+27D4, "⟘" U+27D8, "⟟" U+27DF, "⟲" U+27F2, "⟳" U+27F3, "⤿" U+293F, "⥁" U+2941, "⥇" U+2947, "⥉" U+2949, "⥼" U+297C, "⥽" U+297D, "⥾" U+297E, "⥿" U+297F, "⦚" U+299A, "⦜" U+299C, "⦝" U+299D, "⦞" U+299E, "⦰" U+29B0, "⦷" U+29B7, "⦿" U+29BF, "⧖" U+29D6, "⧗" U+29D7, "⧘" U+29D8, "⧙" U+29D9, "⧚" U+29DA, "⧛" U+29DB, "⧜" U+29DC, "⧢" U+29E2, "⧫" U+29EB, "⨊" U+2A0A, "⨔" U+2A14, "⨯" U+2A2F, "⨰" U+2A30, "⨳" U+2A33, "⨴" U+2A34, "⨵" U+2A35, "⨹" U+2A39, "⨺" U+2A3A, "⨻" U+2A3B, "⨿" U+2A3F, "⩀" U+2A40, "⩁" U+2A41, "⩂" U+2A42, "⩃" U+2A43, "⩄" U+2A44, "⩅" U+2A45, "⩆" U+2A46, "⩇" U+2A47, "⩈" U+2A48, "⩉" U+2A49, "⩊" U+2A4A, "⩍" U+2A4D, "⩎" U+2A4E, "⩏" U+2A4F, "⩐" U+2A50, "⮽" U+2BBD. compose-1.yml [f14575e](https://github.com/dispoclavier/nouvel-azerty/commit/f14575e151b54d497ac8c2b52022aa83b1477391)
	* Adapter les séquences de "˹" U+02F9, "˺" U+02FA, "˻" U+02FB, "˼" U+02FC, "⊼" U+22BC, "꜠" U+A720, "꜡" U+A721. ibidem
	* Intervertir les séquences de "⨟" U+2A1F et "⨾" U+2A3E. ibidem
	* Windows :
		* Transpiler les séquences de composition dédiées :
			* Corriger la mise en page du code source. dead-key-convert.pl [7e3fd84](https://github.com/dispoclavier/nouvel-azerty/commit/7e3fd842bdacc49295ee1b76e54be7b3738a7f7c), [cd17e0e](https://github.com/dispoclavier/nouvel-azerty/commit/cd17e0e9241e2761512cc58f0cb24c2f5600b481), kbdeadtrans.c, kbdeadtrans-multikey.c [d407518](https://github.com/dispoclavier/nouvel-azerty/commit/d407518344a51924c34d294dba721d6552b69c06)
			* Améliorer la performance du transpilateur. ibidem, dead-key-convert.pl [0892662](https://github.com/dispoclavier/nouvel-azerty/commit/089266259f81c2d7df4ad7c2950c73e6badc5a44), [faded61](https://github.com/dispoclavier/nouvel-azerty/commit/faded6127b3d99005b8f50115795b3ddf4ca9f47), [00c2384](https://github.com/dispoclavier/nouvel-azerty/commit/00c23845a9e1017f861a41ef7de3df515c3402fa)
		* Transpiler les équivalents en composition des touches mortes. dead-key-convert.pl [3867ff7](https://github.com/dispoclavier/nouvel-azerty/commit/3867ff77445c933289d663485d042628d3f1d15a), kbdeadtrans.c, kbdeadtrans-multikey-equivalents.c [2202ac5](https://github.com/dispoclavier/nouvel-azerty/commit/2202ac50544ec5234a2099ee0fa96c144218042b)
		* Mettre en attente les équivalents en composition des touches mortes. dead-key-convert.pl [fb67cbc](https://github.com/dispoclavier/nouvel-azerty/commit/fb67cbceb7006b6e441cfbdced1dabdeebc31906), [1e0642b](https://github.com/dispoclavier/nouvel-azerty/commit/1e0642b4e81dda7383f1900b3a3d7a817e119d34), [7b5cf45](https://github.com/dispoclavier/nouvel-azerty/commit/7b5cf45e60f486abc1b26f7ef226534997b30c38), kbdeadtrans.c, kbdeadtrans-multikey-equivalents.c [3516ae7](https://github.com/dispoclavier/nouvel-azerty/commit/3516ae728b2d803dcc37d47d61b2a225ba511f5d)
* Transformations : Indice > Diacritique souscrit : Redonder "᷏" U+1DCF par "Z" pour le rendre insensible à la casse. compose-2.yml [d92a98b](https://github.com/dispoclavier/nouvel-azerty/commit/d92a98b8415d3ed23f74aa4b00d12d5ba6f4bc09)
* Documentation :
	* Corriger ou ajouter des annotations. compose-1.yml [d92a98b](https://github.com/dispoclavier/nouvel-azerty/commit/d92a98b8415d3ed23f74aa4b00d12d5ba6f4bc09), [f531a41](https://github.com/dispoclavier/nouvel-azerty/commit/f531a4107feae9af8eea9affb5a5bc13c68c8f36)
	* Corriger ou ajouter des annotations. compose-1.yml, compose-2.yml, compose-3.yml [f14575e](https://github.com/dispoclavier/nouvel-azerty/commit/f14575e151b54d497ac8c2b52022aa83b1477391)
* Builds :
	* 6.1.5.0 [d407518](https://github.com/dispoclavier/nouvel-azerty/commit/d407518344a51924c34d294dba721d6552b69c06)
	* 6.1.5.1 [58fcf2d](https://github.com/dispoclavier/nouvel-azerty/commit/58fcf2d805c495071d362b38926997bb66b50acc)
	* 6.1.5.2 [2202ac5](https://github.com/dispoclavier/nouvel-azerty/commit/2202ac50544ec5234a2099ee0fa96c144218042b)
	* 6.1.5.3 [3516ae7](https://github.com/dispoclavier/nouvel-azerty/commit/3516ae728b2d803dcc37d47d61b2a225ba511f5d)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.5/Un-nouvel-AZERTY-Windows-6.1.5.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.5/Un-nouvel-AZERTY-Windows-variantes-6.1.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.5/Un-nouvel-AZERTY-Linux-6.1.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2025-12-31 |
|-|

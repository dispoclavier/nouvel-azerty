# 6.2.3 (2026-02-23)

Débogage des séquences de composition dédiées en conflit avec des équivalents en composition de touches mortes.

Correction des noms donnés aux touches modificatrices supplémentaires sous Windows.

Correction et complétion du contenu des touches mortes.

Complétion des séquences de touches mortes spécifiques sous Windows.

Généralisation de raccourcis à touche morte développés sous Windows.

## Modifications

* Disposition :
	* Renommer AltLe en AltEm. kbcommon-1.c [4f7a9dc](https://github.com/dispoclavier/nouvel-azerty/commit/4f7a9dc242e44a6d6a089b779aa21f7b56439f4b), windows/readme.md alias Mode-d-emploi-sous-Windows.md [83c5798](https://github.com/dispoclavier/nouvel-azerty/commit/83c579898a4b6324b1b8c6fbe59145e514772eb4)
	* Renommer AltQr en AltMa. ibidem, dispocla.cpp [dd24fd5](https://github.com/dispoclavier/nouvel-azerty/commit/dd24fd51d8abd697d0c02c7ea6ab6bfc9b1bcd44)
* Composition : Déboguer "∓" U+2213 par « ¦-+ », "⫩" U+2AE9 par « ¦'=' », "⥍" U+294D par « ¦'!' », "⥠" U+2960 par « ¦'!| », "⥮" U+296E par « ¦'!! », […]. dead-key-convert.pl [3a8c224](https://github.com/dispoclavier/nouvel-azerty/commit/3a8c224608e03fd30a8edd2e41900d0e63d9e887) (entre les builds 0 et 1)
* Transformations :
	* Accent aigu : Redonder "‐" U+2010 à la place de "–" U+2013, qui est sur Maj + 3. compose-2.yml [3ce34f3](https://github.com/dispoclavier/nouvel-azerty/commit/3ce34f375659552d8aa288f814f71e423c832a2f)
	* Crosse > Bouclé :
		* Redonder "Ꜣ" U+A722, "ꜣ" U+A723 par "A", "a". ibidem
		* Redonder "Ꜥ" U+A724, "ꜥ" U+A725 par "H", "h". ibidem
	* Brève inversée : Redonder "ʿ" U+02BF par "d", "D". ibidem
	* Brève :
		* Redonder "ʾ" U+02BE par "d", "D". ibidem
		* Redonder "⁕" U+2055 par "*". ibidem
	* Macron :
		* Redonder "∓" U+2213 par "+" à la place de "†" U+2020, qui est dans tilde et dans le groupe 1 de "|". ibidem
		* Macron souscrit : Redonder "±" U+00B1 par "-". ibidem, compose-2.yml [7fd4841](https://github.com/dispoclavier/nouvel-azerty/commit/7fd48419ee0a490c7ddedd0e0f6d4fceddbd10bf)
	* Rond en chef groupe 1 : Redonder "Å" U+212B par "A", "a". compose-2.yml [3ce34f3](https://github.com/dispoclavier/nouvel-azerty/commit/3ce34f375659552d8aa288f814f71e423c832a2f)
	* Accent grave : Redonder "ſ" U+017F par "s" (et "S"). ibidem
	* Tréma :
		* Redonder "ẞ" U+1E9E, "ß" U+00DF par "S", "s" à la place de "ſ" U+017F, qui va par "z" et "$" et est dans accent grave. ibidem
		* Redonder "‡" U+2021 par "T" sous Windows. ibidem
		* Redonder "Å" U+00C5, "å" U+00E5 par "À" U+00C0, "à" U+00E0. compose-2.yml [3455aca](https://github.com/dispoclavier/nouvel-azerty/commit/3455aca6ce6dcdda88b12928a2b74044566400d9)
		* Redonder "ſ" U+017F  par "z". ibidem
		* Redonder "≠" U+2260 par "Z". ibidem
		* Redonder "…" U+2026 par ".". ibidem
* Documentation :
	* Corriger le mode d’emploi sous Windows. windows/readme.md alias Mode-d-emploi-sous-Windows.md [83c5798](https://github.com/dispoclavier/nouvel-azerty/commit/83c579898a4b6324b1b8c6fbe59145e514772eb4)
	* Corriger le journal des modifications. CHANGELOG.md [88dac7b](https://github.com/dispoclavier/nouvel-azerty/commit/88dac7b78c2cdccf6a629c6ca957210731f813a4)
	* Ajouter, corriger ou mettre à jour des annotations. compose-1.yml, compose-2.yml, compose-3.yml [3ce34f3](https://github.com/dispoclavier/nouvel-azerty/commit/3ce34f375659552d8aa288f814f71e423c832a2f), [3455aca](https://github.com/dispoclavier/nouvel-azerty/commit/3455aca6ce6dcdda88b12928a2b74044566400d9)
	* Regrouper la touche morte groupe dans la partie 3 pour maintenir l’affichabilité sur github.com. Compose.yml, compose-1.yml, compose-2.yml, compose-3.yml [3ce34f3](https://github.com/dispoclavier/nouvel-azerty/commit/3ce34f375659552d8aa288f814f71e423c832a2f), [4e1e20f](https://github.com/dispoclavier/nouvel-azerty/commit/4e1e20f269b5e021aa8f0261008275c954f88113), linux-chromeos/compose/readme.md [650aa4d](https://github.com/dispoclavier/nouvel-azerty/commit/650aa4db7326eb45f788a144bfc58edf8a5fd0f4), generate-deadkey-tables.pl [9041736](https://github.com/dispoclavier/nouvel-azerty/commit/9041736c61bc8afb1689821eaa1ed2bffd10f936)
* Builds :
	* 6.2.3.0 [4f7a9dc](https://github.com/dispoclavier/nouvel-azerty/commit/4f7a9dc242e44a6d6a089b779aa21f7b56439f4b)
	* 6.2.3.1 [c391aac](https://github.com/dispoclavier/nouvel-azerty/commit/c391aac3770a11ec714680d1231f4a172d1f00d4)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.3/Un-nouvel-AZERTY-Windows-6.2.3.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.3/Un-nouvel-AZERTY-Windows-variantes-6.2.3.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.3.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.3/Un-nouvel-AZERTY-Linux-6.2.3.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-02-23 |
|-|

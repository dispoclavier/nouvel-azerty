# 6.2.1 (2026-02-01)

Ajout de séquences de touches mortes spécifiques à Windows.

Correction et simplification du contenu des touches mortes.

## Modifications

* Composition : Sous Windows : Déboguer la séquence « ¦Mul » pour "¦" U00A6. kbdeadtrans-multikey.c [4df04ef](https://github.com/dispoclavier/nouvel-azerty/commit/4df04ef8f38fc7c5254836d6636c3af90b10e836)
*	Transformations :
	* Indice :
		* Indice et groupe 1 :
			* Corriger "ᴐ" U1D10 en redondant par "C". compose-2.yml [2ebf9a0](https://github.com/dispoclavier/nouvel-azerty/commit/2ebf9a0b972ccd1e22d944a6cbf1f402ec8defb3)
			* Redonder "ᴣ" U1D23 par "z". ibidem
		* Indice et groupe 2 :
			* Mettre "ᴐ" U1D10 par "o", et par "O" à la place de "ᴕ" U1D15, qui prend la place laissée par "ᴐ" U1D10 dans le groupe 3. ibidem
			* Redonder  par "". ibidem
		* Indice et tourné : Redonder "ꜟ" UA71F. ibidem
		* Indice et réfléchi : Redonder "ⱻ" U2C7B, "𝼐" U1DF10. ibidem
	* Macron :
		* Macron et accent aigu et accent grave : Simplifier la saisie de "᫘" U1AD8. ibidem
		* Macron souscrit : Redonder "⨱" U2A31 par ".". ibidem
	* Virgule souscrite :
		* Redonder "Ķ" U0136, "ķ" U0137 (qui sont aussi dans cédille) à la place de "Ꜯ" UA72E, "ꜯ" UA72F, qui vont par "C", "c", par "F", "f" et par "Q", "q". ibidem
		* Redonder "Ģ" U0122, "ģ", "Ļ" U013B, "ļ" U013C, "Ņ" U0145, "ņ" U0146, "Ŗ" U0156, "ŗ" U0157 (qui sont aussi dans cédille). compose-2.yml [5cc9c3b](https://github.com/dispoclavier/nouvel-azerty/commit/5cc9c3b6f50a0747375ad3555b1073d1a93103dd)
	* Sous Windows : Touche morte groupe : Supprimer la limitation des appuis multiples. kbdeadtrans.c [4df04ef](https://github.com/dispoclavier/nouvel-azerty/commit/4df04ef8f38fc7c5254836d6636c3af90b10e836)
* Documentation :
	* Mettre à jour et corriger le mode d’emploi. readme.md alias Mode-d-emploi-commun.md [d246dc0](https://github.com/dispoclavier/nouvel-azerty/commit/d246dc07dc159340e22218e00c17cbc6037839ce)
	* Déboguer les tableaux de touches mortes. generate-deadkey-tables.pl [6104dc2](https://github.com/dispoclavier/nouvel-azerty/commit/6104dc2daa26dfcd8309229ed498339346f885ed)
	* Corriger et mettre à jour les infobulles des tableaux. generate-deadkey-tables.pl, generate-multikey-tables.pl, generate-math-table [6104dc2](https://github.com/dispoclavier/nouvel-azerty/commit/6104dc2daa26dfcd8309229ed498339346f885ed)
	* Mettre à jour l’ordre des touches mortes. compose-2.yml [2529366](https://github.com/dispoclavier/nouvel-azerty/commit/2529366313410a59d3cf4fecb5933663e27eb157), [5cc9c3b](https://github.com/dispoclavier/nouvel-azerty/commit/5cc9c3b6f50a0747375ad3555b1073d1a93103dd)
	* Corriger des annotations. compose-1.yml, compose-2.yml [2ebf9a0](https://github.com/dispoclavier/nouvel-azerty/commit/2ebf9a0b972ccd1e22d944a6cbf1f402ec8defb3)
* Build : 6.2.1.0 [4df04ef](https://github.com/dispoclavier/nouvel-azerty/commit/4df04ef8f38fc7c5254836d6636c3af90b10e836)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.1/Un-nouvel-AZERTY-Windows-6.2.1.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.1/Un-nouvel-AZERTY-Windows-variantes-6.2.1.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.1.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.1/Un-nouvel-AZERTY-Linux-6.2.1.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-02-01 |
|-|

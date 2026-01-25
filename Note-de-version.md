# 6.1.8 (2026-01-25)

Portage sous Linux de la touche morte virtuelle traversant développée sous Windows.

Correction du contenu des touches mortes.

## Modifications

* Transformations :
	* Accent circonflexe et rond en chef : Ajouter comme raccourci pour l’accent circonflexe souscrit. compose-2.yml [4110edd](https://github.com/dispoclavier/nouvel-azerty/commit/4110edd799564331df667712671f3286020b8317), dead-key-convert.pl [a0a44b1](https://github.com/dispoclavier/nouvel-azerty/commit/a0a44b13d19be38623a008dbbe043b7e1bf397d5)
	* Cornu :
		* Redonder "¶" U+00B6 par "Q". compose-2.yml [5d7233c](https://github.com/dispoclavier/nouvel-azerty/commit/5d7233c292796e68866f74e57588135deee32785)
		* Redonder "⁋" U+204B par "P". ibidem
		* Redonder "⁌" U+204C par "q". ibidem
		* Redonder "⁍" U+204D par "p". ibidem
		* Traversant :
			* Ajouter en double frappe pour les diacritiques traversants ou entourants "⃞" U+20DE, "⃟" U+20DF, "⃠" U+20E0, "⃢" U+20E2, "⃣" U+20E3, "⃤" U+20E4, "⃧" U+20E7, "⃪" U+20EA, à la place du raccourci pour l’accent circonflexe souscrit, qui va dans accent circonflexe et rond en chef. compose-2.yml [4110edd](https://github.com/dispoclavier/nouvel-azerty/commit/4110edd799564331df667712671f3286020b8317)
			* Ajouter ou redonder "̴" U+0334, "̵" U+0335, "̶" U+0336, "̷" U+0337, "̸" U+0338, "᪾" U+1ABE, "⃒" U+20D2, "⃓" U+20D3, "⃘" U+20D8, "⃙" U+20D9, "⃚" U+20DA, "⃥" U+20E5, "⃦" U+20E6, "⃪" U+20EA, "⃫" U+20EB. compose-2.yml [1a70009](https://github.com/dispoclavier/nouvel-azerty/commit/1a7000904372e86f1e75f65d0e9ca02ff9577b7a)
			* Redonder "⃦" U+20E6 par "\"" et "€" U+20AC. compose-2.yml [c128b97](https://github.com/dispoclavier/nouvel-azerty/commit/c128b97fdf1cd94f9b106704414df42851ed1936)
			* Redonder "⃣" U+20E3 par "k", "K", "t" et "T". ibidem
* Documentation : Corriger ou ajouter des annotations. compose-1.yml, compose-2.yml [5d7233c](https://github.com/dispoclavier/nouvel-azerty/commit/5d7233c292796e68866f74e57588135deee32785)
* Build : 6.1.8.0 [9af2eac](https://github.com/dispoclavier/nouvel-azerty/commit/9af2eacb6a0bf364bcb159424c3fc1b1689da3c3)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.8.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.8/Un-nouvel-AZERTY-Windows-6.1.8.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.8.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.8/Un-nouvel-AZERTY-Windows-variantes-6.1.8.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.8.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.8/Un-nouvel-AZERTY-Linux-6.1.8.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-01-25 |
|-|

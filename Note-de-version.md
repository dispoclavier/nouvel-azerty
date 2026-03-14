# 6.2.5 (2026-03-08)

Simplification de la saisie de symboles mathématiques.

Mise à jour du contenu des touches mortes.

## Modifications

* Composition :
	* Supprimer "ẞ" U+1E9E par « ¦SS ». compose-1.yml [4cca3ed](https://github.com/dispoclavier/nouvel-azerty/commit/4cca3ed1fcf2cd80a67685554172e64de5950d15)
	* Simplifier les séquences de "⅀" U+2140. ibidem
	* Simplifier les séquences de "⁀" U+2040. compose-1.yml [5cf1669](https://github.com/dispoclavier/nouvel-azerty/commit/5cf16696380edc7460a304c93e2bb63e2e051bdc)
	* Compléter les séquences de "¡" U+00A1, "‎" U+200E, "‏" U+200F, "‪" U+202A, U+202B, "‬" U+202C, "‭" U+202D, U+202E, "⁦" U+2066, U+2067, "⁨" U+2068, "⁩" U+2069, "K" U+212A. compose-2.yml [37be705](https://github.com/dispoclavier/nouvel-azerty/commit/37be705dc3fc45b4644d91a4c9615e66ce89e221)
* Transformations : Désactiver des équivalents en composition en conflit avec des symboles mathématiques. compose-2.yml [5cf1669](https://github.com/dispoclavier/nouvel-azerty/commit/5cf16696380edc7460a304c93e2bb63e2e051bdc)
* Documentation :
	* Ajouter, corriger ou mettre à jour des annotations. compose-1.yml, compose-2.yml [37be705](https://github.com/dispoclavier/nouvel-azerty/commit/37be705dc3fc45b4644d91a4c9615e66ce89e221), [4cca3ed](https://github.com/dispoclavier/nouvel-azerty/commit/4cca3ed1fcf2cd80a67685554172e64de5950d15)
	* Corriger le journal des modifications. CHANGELOG.md [7ca1301](https://github.com/dispoclavier/nouvel-azerty/commit/7ca13015fc8afde167fc4f3a5781eef9b22f32ae)
* Build : 6.2.5.0 [01e75bf](https://github.com/dispoclavier/nouvel-azerty/commit/01e75bfda306c76633085e6d6c5d6f0d015ba79b)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour, mais sans les équivalents en composition des touches mortes, trop lourds pour Windows, qui tomberait en panne s’ils étaient pris en charge.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.5/Un-nouvel-AZERTY-Windows-6.2.5.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.5/Un-nouvel-AZERTY-Windows-variantes-6.2.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.5.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.5/Un-nouvel-AZERTY-Linux-6.2.5.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## Notes

1. Pour faire afficher un maximum de glyphes des caractères cités, il est nécessaire d’avoir [installé des polices complètes](https://support.microsoft.com/fr-fr/office/ajouter-une-police-b7c5f17c-4426-4b53-967f-455339c564c1) : [BabelStone Han](https://www.babelstone.co.uk/Fonts/Han.html), [DejaVu](https://en.wikipedia.org/wiki/DejaVu_fonts) ([Font Squirrel](https://www.fontsquirrel.com/fonts/dejavu-sans)), Kelvinch (mise à jour 2017 ; [1001 Fonts](https://www.1001fonts.com/kelvinch-font.html)), Nishiki-teki (mise à jour 2022 ; [Fontspace](https://www.fontspace.com/nishiki-teki-font-f86893)). Ces polices sont gratuites pour les usages aussi bien personnels que professionnels.

2. Le deux-barrettes "¦" U00A6 (barre brisée, barre discontinue, barre déjointe, barre à trou) représente la touche de composition "⎄" U2384. Les séquences de composition sont entre guillemets français pour la lisibilité : « ¦mul », « ¦MUL », « ¦!^ », « ¦:\ », « ¦#1: », « ¦¦ ».

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-03-14 |
|-|

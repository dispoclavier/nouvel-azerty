# 6.2.7 (2026-03-22)

Complétion des séquences droite-à-gauche pour symboles mathématiques.

## Modifications

* Composition :
	* Compléter les séquences de "⭀" U+2B40, "⭁" U+2B41, "⭂" U+2B42, "⭄" U+2B44. compose-1.yml [fb45879](https://github.com/dispoclavier/nouvel-azerty/commit/fb458796b6c42484f0b55a69031c685d437a6a57)
	* Adapter les séquences de "⥲" U+2972, "⬰" U+2B30, "⭇" U+2B47. ibidem
* Build : 6.2.7.0 [ad97918](https://github.com/dispoclavier/nouvel-azerty/commit/ad97918691bc7515fb2ea4185024e2031870725b)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour, mais sans les équivalents en composition des touches mortes, trop lourds pour Windows, qui tomberait en panne s’ils étaient pris en charge.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.7/Un-nouvel-AZERTY-Windows-6.2.7.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.7/Un-nouvel-AZERTY-Windows-variantes-6.2.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.7/Un-nouvel-AZERTY-Linux-6.2.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

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

| Dernière mise à jour : 2026-03-22 |
|-|

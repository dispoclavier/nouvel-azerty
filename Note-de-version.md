# 6.2.4 (2026-03-05)

Débogage des pilotes de disposition pour Windows par l’arrêt des équivalents en composition de touches mortes.

Simplification de la saisie de symboles mathématiques.

Correction de contenu de touche morte.

## Modifications

* Composition :
	* Sous Windows :
		* Déboguer les équivalents en composition par leur fusion avec les séquences de composition dédiées. dead-key-convert.pl [6d61802](https://github.com/dispoclavier/nouvel-azerty/commit/6d61802a303535d4ff63a505a7554ec0a9ea99db), kbdeadtrans.c, kbdeadtrans-multikey.c, kbdeadtrans-multikey-equivalents.c [6a251b1](https://github.com/dispoclavier/nouvel-azerty/commit/6a251b10484ff3ab73907f094b01a97bf51deb84)
		* Déboguer le système par l’arrêt de la prise en charge des équivalents en composition, afin de réduire la taille des pilotes de disposition. dead-key-convert.pl [6d61802](https://github.com/dispoclavier/nouvel-azerty/commit/6d61802a303535d4ff63a505a7554ec0a9ea99db), kbdeadtrans.c, kbdeadtrans-multikey.c, kbdeadtrans-multikey-equivalents.c [f2eb494](https://github.com/dispoclavier/nouvel-azerty/commit/f2eb494fa26307690ac37468b0090953869df5e7)
	* Simplifier les séquences de "≙" U+2259. compose-1.yml [ef34a55](https://github.com/dispoclavier/nouvel-azerty/commit/ef34a556042e7785e16356ef89aecf2e4f8388ea)
	* Compléter les séquences de "⁀" U+2040. ibidem
	* Corriger ou compléter les séquences de "¬" U+00AC, "⇁" U+21C1, "⫬" U+2AEC, "⫭" U+2AED. compose-1.yml [5a7edc1](https://github.com/dispoclavier/nouvel-azerty/commit/5a7edc1ced405ea228cc3271f87d791def378726)
* Transformations : Macron : Macron souscrit : Corriger "±" U+00B1 par "+". compose-2.yml [ef34a55](https://github.com/dispoclavier/nouvel-azerty/commit/ef34a556042e7785e16356ef89aecf2e4f8388ea), [5e0ec1d](https://github.com/dispoclavier/nouvel-azerty/commit/5e0ec1d83577ea9891d8fd04cb208f07d792529e)
* Documentation : Mettre à jour les modes d’emploi. readme.md alias Mode-d-emploi-commun.pdf [6da6c32](https://github.com/dispoclavier/nouvel-azerty/commit/6da6c325ba05e102a76a50bcd304bf23d42a914b), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.pdf [fd4e9fa](https://github.com/dispoclavier/nouvel-azerty/commit/fd4e9facc1c86d3cef3c6b8fbdf1a835408d418d), windows/readme.md alias Mode-d-emploi-sous-Windows.pdf [f7e85cf](https://github.com/dispoclavier/nouvel-azerty/commit/f7e85cf464d9a5e996fc28176ad9cf7414e368a0)
* Builds :
	* 6.2.4.0 [6a251b1](https://github.com/dispoclavier/nouvel-azerty/commit/6a251b10484ff3ab73907f094b01a97bf51deb84)
	* 6.2.4.1 [f2eb494](https://github.com/dispoclavier/nouvel-azerty/commit/f2eb494fa26307690ac37468b0090953869df5e7)
	* 6.2.4.2 [f5b40c9](https://github.com/dispoclavier/nouvel-azerty/commit/f5b40c9cf47e4b5db990507d34fb40e9937a5939)
	* 6.2.4.3 [0758b13](https://github.com/dispoclavier/nouvel-azerty/commit/0758b13173cc0500870e8564ead0e73fad548f79)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour, mais sans les équivalents en composition des touches mortes, trop lourds pour Windows, qui tomberait en panne s’ils étaient pris en charge.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.4/Un-nouvel-AZERTY-Windows-6.2.4.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.4/Un-nouvel-AZERTY-Windows-variantes-6.2.4.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.4.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.4/Un-nouvel-AZERTY-Linux-6.2.4.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-03-06 |
|-|

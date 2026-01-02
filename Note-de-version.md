# 6.1.6 (2026-01-02)

Prise en charge sous Windows des équivalents en composition des touches mortes simples.

## Modifications

* Composition :
	* Windows :
		* Déboguer le transpilateur. dead-key-convert.pl [f88bc8e](https://github.com/dispoclavier/nouvel-azerty/commit/f88bc8e384b28246f5a719b07ca843033b227727), [66144a6](https://github.com/dispoclavier/nouvel-azerty/commit/66144a6793cec86a8f701e8688a582f05a512e0e), [7dae1dc](https://github.com/dispoclavier/nouvel-azerty/commit/7dae1dc133b093fa65039718a629827dbe73814a), [1888071](https://github.com/dispoclavier/nouvel-azerty/commit/1888071c47aa4ee2c64a47e85572792ae93dd9ed), [56d542b](https://github.com/dispoclavier/nouvel-azerty/commit/56d542b799d5c83eabcab588b3e49865e26b59d6)
		* Transpiler les équivalents en composition des touches mortes simples. kbdeadtrans.c, kbdeadtrans-multikey-equivalents.c [d83ebb5](https://github.com/dispoclavier/nouvel-azerty/commit/d83ebb5ced6dae9805b109e50d35817951c5843f), [719b16b](https://github.com/dispoclavier/nouvel-azerty/commit/719b16be2a83b129158069c72569ba4066d86752), [a8fcc56](https://github.com/dispoclavier/nouvel-azerty/commit/a8fcc564493acd14c86b85a0cc8de8e401dcd96f)
* Documentation :
	* Ajouter des ancres aux aveux de culpabilité. readme.md alias Mode-d-emploi-commun.md [afad468](https://github.com/dispoclavier/nouvel-azerty/commit/afad4686215b8b593a66429a0d1e7b7e644fc985)
	* Versionnage : Clarifier le numéro de build. readme.md alias Mode-d-emploi-commun.md [3f9cf06](https://github.com/dispoclavier/nouvel-azerty/commit/3f9cf06c71a7d028fd98fe13438257d86a947a99)
* Builds :
	* 6.1.6.0 [d83ebb5](https://github.com/dispoclavier/nouvel-azerty/commit/d83ebb5ced6dae9805b109e50d35817951c5843f)
	* 6.1.6.1 [719b16b](https://github.com/dispoclavier/nouvel-azerty/commit/719b16be2a83b129158069c72569ba4066d86752)
	* 6.1.6.2 [a8fcc56](https://github.com/dispoclavier/nouvel-azerty/commit/a8fcc564493acd14c86b85a0cc8de8e401dcd96f)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.1.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.6/Un-nouvel-AZERTY-Windows-6.1.6.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.1.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.6/Un-nouvel-AZERTY-Windows-variantes-6.1.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.1.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.1.6/Un-nouvel-AZERTY-Linux-6.1.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

## Statistiques de téléchargement

Contrairement à [SourceForge](https://medium.com/@carlspring/the-rise-fall-and-resurgence-of-sourceforge-what-happened-to-the-open-source-pioneer-527e9288f9bb), où [ce nouvel AZERTY a un miroir des versions](https://sourceforge.net/projects/nouvel-azerty/) (depuis samedi 4/10/2025), GitHub n’affiche pas de statistiques de téléchargement, mais celles de ce dépôt sont affichées par [Somsubhra](https://somsubhra.github.io/github-release-stats/?username=dispoclavier&repository=nouvel-azerty&page=1&per_page=100) sur plusieurs pages, et par [GREV](https://hanadigital.github.io/grev/?user=dispoclavier&repo=nouvel-azerty) sur une page. [Qwertycube](https://qwertycube.com/github-release-stats/) les affiche après saisie.

Du total il faut soustraire les téléchargements effectués par SourceForge, soit un par fichier compressé (156 au moment de la mise en place du miroir 2 jours après la sortie de la version 6.0.9).

## À propos

Cette note est [versionnée](https://github.com/dispoclavier/nouvel-azerty/blob/main/Note-de-version.md).

| Dernière mise à jour : 2026-01-02 |
|-|

# 6.0.6 (2025-09-02)

Meilleure variante pour la Polynésie française avec le ʻeta en Minuscule.

Rectification et simplification de séquences de composition.

## Modifications

* Disposition : Variantes pour la Polynésie :
	* Mettre "ʻ" U+02BB en Minuscule sur E01 à la place de "²" U+00B2, qui est sur Maj + AltFr + 2 et dans accent circonflexe par "2". dispocla.cpp [ebd6683](https://github.com/dispoclavier/nouvel-azerty/commit/ebd6683497f3f8ddf3e11c94ee3710cfe3385333), compose-2.yml [844c0bf](https://github.com/dispoclavier/nouvel-azerty/commit/844c0bfc11f01c55c2e16c92c43a55cf03848319), compose-3.yml [3d8f321](https://github.com/dispoclavier/nouvel-azerty/commit/3d8f321bad3f40336de986504ae0534da8c5584f)
	* Rajouter "―" U+2015 en Majuscule sur E08 à la place de "ʻ" U+02BB, qui va sur E01. ibidem
	* Ajouter "ʼ" U+02BC en Majscule sur E01 à la place de "³" U+00B3, qui est sur Maj + AltFr + 3 et dans accent circonflexe par "3". ibidem
* Composition :
	* Changer la séquence de "⎋" U+238B de « ¦es » en « ¦esc ». compose-1.yml [94916d7](https://github.com/dispoclavier/nouvel-azerty/commit/94916d75a177870fbfebf901c9c179a0df22bd05)
	* Changer la séquence de "℮" U+212E de « ¦␣e » en « ¦est ». ibidem
	* Simplifier, améliorer ou corriger les séquences de "∋" U+220B, "∌" U+220C, "∍" U+220D, "≞" U+225E, "≟" U+225F, "≡" U+2261, "≢" U+2262, "≣" U+2263, "≨" U+2268, "≩" U+2269, "≭" U+226D, "≰" U+2270, "≱" U+2271, "≴" U+2274, "≵" U+2275, "≸" U+2278, "≹" U+2279, "⊀" U+2280, "⊁" U+2281, "⊃" U+2283, "⊅" U+2285, "⊇" U+2287, "⊉" U+2289, "⊐" U+2290, "⊒" U+2292, "⟄" U+27C4, "⥻" U+297B, "⋥" U+22E5, "⟄" U+27C4, "⟉" U+27C9. ibidem
* Transformations : Touche morte groupe : Groupe 1 : Supprimer "―" U+2015 par "ʻ" U+02BB, qui ne prend plus la place de "―" U+2015 sur les variantes pour la Polynésie. compose-3.yml [3d8f321](https://github.com/dispoclavier/nouvel-azerty/commit/3d8f321bad3f40336de986504ae0534da8c5584f)
* Documentation : Mettre à jour et déboguer les modes d’emploi :
	* Commun : readme.md [d66b174](https://github.com/dispoclavier/nouvel-azerty/commit/d66b1747204665b2f7a6ed60d075da06bce85356)
	* Linux : linux-chromeos/readme.md [8f51187](https://github.com/dispoclavier/nouvel-azerty/commit/8f511879a37714f0b82b6a0a36770eb8d3a3b989), Lisez-moi-svp.md [313a75f](https://github.com/dispoclavier/nouvel-azerty/commit/313a75f44083c1eb534f942acd3137a848570aea).
	* Windows : windows/readme.md [a850608](https://github.com/dispoclavier/nouvel-azerty/commit/a850608e538abe1c4802a6ddf49c8f55e442fde5), [58f8c55](https://github.com/dispoclavier/nouvel-azerty/commit/58f8c55b9fa3c487faf3391810f6348de05161f2), Lisez-moi-svp.md [c6d3121](https://github.com/dispoclavier/nouvel-azerty/commit/c6d3121199d121e79af28d6f2f95bf3b0d98b633)

## Pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai. Toutes les touches vives sont à jour, toutes les touches mortes simples aussi.

Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018 (parce que le script qui transpile le fichier « Compose.yml » n’est pas fini).

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.6/Un-nouvel-AZERTY-Windows-6.0.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

## Pour Linux

La version pour Linux est entièrement à jour. Non seulement les touches vives, mais aussi le contenu des touches mortes, le fichier « Compose.yml » étant (partiellement) transpilé en C pour Windows.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.6/Un-nouvel-AZERTY-Linux-6.0.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

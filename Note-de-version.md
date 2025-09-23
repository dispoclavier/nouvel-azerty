# 6.0.7 (2025-09-23)

Mise à niveau des symboles mathématiques vers [Unicode 17.0](https://www.unicode.org/versions/Unicode17.0.0/).

Complétion de touches mortes sous Linux et Windows.

Rectification et simplification de séquences de composition.

Harmonisation de la sortie des métadonnées sous Linux et Windows.

Meilleure personnalisabilité sous Linux.

## Modifications

* Disposition :
	* Windows :
		* Mettre le numéro de version sur AltGr + Échap au lieu de Maj + AltFr + Échap. kbligatures.c [c3f0eaa](https://github.com/dispoclavier/nouvel-azerty/commit/c3f0eaad69f3e9682c8d78267e589bdca4b822b4), [45745ef](https://github.com/dispoclavier/nouvel-azerty/commit/45745ef6070308f8621a0705428f4d7d87bc4d2a), kbcommon.c [07258e5](https://github.com/dispoclavier/nouvel-azerty/commit/07258e573fa5652614c4f32870ccc254d10acfcf), [45745ef](https://github.com/dispoclavier/nouvel-azerty/commit/45745ef6070308f8621a0705428f4d7d87bc4d2a)
		* Mettre l’identifiant de variante sur Maj + AltGr + Échap au lieu de AltFr + Échap. ibidem
	* Linux :
		* Égaliser avec Windows. dispocla.cpp, dispocla_perso.cpp [e6e59c6](https://github.com/dispoclavier/nouvel-azerty/commit/e6e59c6c4a7acff254bafa4aff2f00104936bd6e), [b7f2877](https://github.com/dispoclavier/nouvel-azerty/commit/b7f287736e5314121bac59a1a0a9c86ad155d560)
		* Redonder la bascule VerrMod sur VerrCap en AltGr (et en Maj, et en AltFr). ibidem
* Composition :
	* Prendre en charge "𜻰" U+1CEF0, "🣐" U+1F8D0, "🣑" U+1F8D1, "🣒" U+1F8D2, "🣓" U+1F8D3, "🣔" U+1F8D4, "🣕" U+1F8D5, "🣖" U+1F8D6, "🣗" U+1F8D7, "🣘" U+1F8D8. compose-1.yml [cfb3322](https://github.com/dispoclavier/nouvel-azerty/commit/cfb33228ba6a6eab4535eea80e31f1eaaa641f68)
	* Adapter les séquences de "⇌" U+21CC. ibidem
	* Rendre les séquences de "˧" U+02E7, "˨" U+02E8, "꜔" U+A714, "꜕" U+A715 sensibles à la casse. compose-1.yml [b692f9f](https://github.com/dispoclavier/nouvel-azerty/commit/b692f9f4d8c14c80b585d5b3228c3ba0989a6f43)
	* Compléter et simplifier les séquences des taquets et tourniquets :
		* Compléter et simplifier les séquences de "⊢" U+22A2, "⊣" U+22A3, "⟘" U+27D8, "⟙" U+27D9, "⫟" U+2ADF, "⫠" U+2AE0. compose-1.yml [eadda4a](https://github.com/dispoclavier/nouvel-azerty/commit/eadda4a3deedae6725f28b3c6cd110e1cb1952f2), [f4b2648](https://github.com/dispoclavier/nouvel-azerty/commit/f4b26481b1db8da576dfe92a35e42180103fa0d5)
		* Compléter et simplifier les séquences de "⊦" U+22A6, "⊧" U+22A7, "⊨" U+22A8, "⊩" U+22A9, "⊪" U+22AA, "⊫" U+22AB, "⊬" U+22AC, "⊭" U+22AD, "⊮" U+22AE, "⊯" U+22AF, "⟙" U+27D9, "⟚" U+27DA, "⟛" U+27DB, "⟝" U+27DD, "⟞" U+27DE, "⟟" U+27DF, "⫞" U+2ADE, "⫟" U+2ADF, "⫢" U+2AE2, "⫣" U+2AE3, "⫤" U+2AE4, "⫥" U+2AE5, "⫧" U+2AE7, "⫨" U+2AE8, "⫩" U+2AE9, "⫪" U+2AEA, "⫫" U+2AEB. compose-1.yml [e6f3202](https://github.com/dispoclavier/nouvel-azerty/commit/e6f32029e2e75ac0c16f6f664326d10121256695)
	* Simplifier, corriger ou compléter les séquences de "⊈" U+2288, "⊊" U+228A, "⊌" U+228C, "⊍" U+228D, "⊎" U+228E, "⊓" U+2293, "⊔" U+2294, "⊗" U+2297, "⊘" U+2298, "⊙" U+2299, "⊜" U+229C, "⊝" U+229D, "⊞" U+229E, "⊟" U+229F, "⊠" U+22A0, "⊡" U+22A1. compose-1.yml [f01f779](https://github.com/dispoclavier/nouvel-azerty/commit/f01f779bf8a154853fb866d1ae6c2758e932c12d)
	* Simplifier, corriger ou compléter les séquences de "⊰" U+22B0, "⊱" U+22B1, "⊶" U+22B6, "⊷" U+22B7, "⊹" U+22B9, "⊼" U+22BC, "⋀" U+22C0, "⋄" U+22C4, "◇" U+25C7, "♢" U+2662. compose-1.yml [fce1074](https://github.com/dispoclavier/nouvel-azerty/commit/fce1074a0e865c52306c051f8fc7287667578bf1), [afbc699](https://github.com/dispoclavier/nouvel-azerty/commit/afbc6997fa9f3c1a1dace533e4b10c64d0b4d743)
	* Simplifier, corriger ou compléter les séquences de "⋆" U+22C6, "★" U+2605, "☆" U+2606. compose-1.yml [fcfa226](https://github.com/dispoclavier/nouvel-azerty/commit/fcfa226eab800d1ee201870e993d793e0d6b769f)
* Transformations :
	* Tilde : Redonder "⟦" U+27E6, "⟧" U+27E7 par "[", "]". compose-2.yml [8b9bafe](https://github.com/dispoclavier/nouvel-azerty/commit/8b9bafe6cec762e5fa7879f0da9d176e3879b7e1), kbdeadtrans.c [c3f0eaa](https://github.com/dispoclavier/nouvel-azerty/commit/c3f0eaad69f3e9682c8d78267e589bdca4b822b4)
	* Accent aigu :
		* Redonder "⟦" U+27E6 par "/". compose-2.yml [9c63e6a](https://github.com/dispoclavier/nouvel-azerty/commit/9c63e6ab3187d1f0eb6d8a776ee5b3a0a0adf765), kbdeadtrans.c [c3f0eaa](https://github.com/dispoclavier/nouvel-azerty/commit/c3f0eaad69f3e9682c8d78267e589bdca4b822b4)
		* Redonder "⟧" U+27E7 par "\\", "·" U+00B7. ibidem, compose-2.yml [a0c8e36](https://github.com/dispoclavier/nouvel-azerty/commit/a0c8e36296ef2edf98a478d5d92da46c8fedfc1a), dead-key-convert.pl [c61f541](https://github.com/dispoclavier/nouvel-azerty/commit/c61f541e3ac94b6958a25853622b571a3434d014), kbdeadtrans.c [45745ef](https://github.com/dispoclavier/nouvel-azerty/commit/45745ef6070308f8621a0705428f4d7d87bc4d2a)
		* Redonder "▾" U+25BE par "@". compose-2.yml [830be4e](https://github.com/dispoclavier/nouvel-azerty/commit/830be4e353edf07472cce9139ec7605e193c7414)
	* Rond en chef : Redonder "⋆" U+22C6 par "8" à la place de "°" U+00B0, qui est par "0". compose-2.yml [f805702](https://github.com/dispoclavier/nouvel-azerty/commit/f8057023b693a6d36f01bae00d970902c0f9482e), kbdeadtrans.c [a0ce66e](https://github.com/dispoclavier/nouvel-azerty/commit/a0ce66e9b9f60f5b40ec6017a24fa62ce9962572)
	* Accent circonflexe : Redonder "⍽" U+237D par "@". compose-2.yml [830be4e](https://github.com/dispoclavier/nouvel-azerty/commit/830be4e353edf07472cce9139ec7605e193c7414)
	* Drapeau > Émoji drapeau : Redonder "🏴" U+1F3F4 par "·" U+00B7. compose-2.yml [a0c8e36](https://github.com/dispoclavier/nouvel-azerty/commit/a0c8e36296ef2edf98a478d5d92da46c8fedfc1a), dead-key-convert.pl [c61f541](https://github.com/dispoclavier/nouvel-azerty/commit/c61f541e3ac94b6958a25853622b571a3434d014)
	* Accent grave : Redonder "⟦" U+27E6, "⟧" U+27E7 par "[", "]". compose-2.yml [059a209](https://github.com/dispoclavier/nouvel-azerty/commit/059a20953480fecb38ea7b07d1dbea28054c8ceb), kbdeadtrans.c [4d0c038](https://github.com/dispoclavier/nouvel-azerty/commit/4d0c0380256e486c9c2d9ab2448c360aaff6913f), [617c9d8](https://github.com/dispoclavier/nouvel-azerty/commit/617c9d8fb753d1b7ff96a59904185b46b78cf380)
	* Tréma :
		* Redonder "¦" U+00A6 par "·" U+00B7. compose-2.yml [a0c8e36](https://github.com/dispoclavier/nouvel-azerty/commit/a0c8e36296ef2edf98a478d5d92da46c8fedfc1a), dead-key-convert.pl [c61f541](https://github.com/dispoclavier/nouvel-azerty/commit/c61f541e3ac94b6958a25853622b571a3434d014)
		* Redonder "▿" U+25BF par "@". compose-2.yml [830be4e](https://github.com/dispoclavier/nouvel-azerty/commit/830be4e353edf07472cce9139ec7605e193c7414)
* Documentation :
	* Mettre à jour le mode d’emploi commun. readme.md [7461550](https://github.com/dispoclavier/nouvel-azerty/commit/74615507010c87aef3694004cfe8ad9518eabb77), [95298b0](https://github.com/dispoclavier/nouvel-azerty/commit/95298b057e82aefdff2aa717f8dfc3d38755d2f2)
	* Corriger et mettre à jour les modes d’emploi des versions. linux-chromeos/Lisez-moi-svp.md [947f8b8](https://github.com/dispoclavier/nouvel-azerty/commit/947f8b8e50ea3dcf1de9d54b783f3eed13286abd), windows/Lisez-moi-svp.md [b33fffd](https://github.com/dispoclavier/nouvel-azerty/commit/b33fffdb93eeb4b7c2706679faac239b1e818f9e)
	* Corriger et mettre à jour le mode d’emploi de Compose.yml. linux-chromeos/compose/readme.md [00f83a7](https://github.com/dispoclavier/nouvel-azerty/commit/00f83a7e6ddd0c282dfe53ec4ee8f539820ee61e)
	* Corriger le mode d’emploi du redisposeur de codes matériels en vue de le fournir en PDF aussi. windows/redispositions/readme.md [70b1033](https://github.com/dispoclavier/nouvel-azerty/commit/70b10332c911f8881ac77dd70831825f3bd70c45)
	* Corriger ou compléter des annotations. compose-1.yml [eadda4a](https://github.com/dispoclavier/nouvel-azerty/commit/eadda4a3deedae6725f28b3c6cd110e1cb1952f2), [f4b2648](https://github.com/dispoclavier/nouvel-azerty/commit/f4b26481b1db8da576dfe92a35e42180103fa0d5), [b692f9f](https://github.com/dispoclavier/nouvel-azerty/commit/b692f9f4d8c14c80b585d5b3228c3ba0989a6f43), [e6f3202](https://github.com/dispoclavier/nouvel-azerty/commit/e6f32029e2e75ac0c16f6f664326d10121256695), [8030751](https://github.com/dispoclavier/nouvel-azerty/commit/8030751d281af31ec6a701f0e5bf73c2ea45c7dc), [cfb3322](https://github.com/dispoclavier/nouvel-azerty/commit/cfb33228ba6a6eab4535eea80e31f1eaaa641f68) ; compose-1.yml, compose-2.yml [483bcb8](https://github.com/dispoclavier/nouvel-azerty/commit/483bcb8a4d4af88b063c149ebd3d8d3c6edeec28) ; kbdeadtrans.c [a0ce66e](https://github.com/dispoclavier/nouvel-azerty/commit/a0ce66e9b9f60f5b40ec6017a24fa62ce9962572), kbcommon.c [07258e5](https://github.com/dispoclavier/nouvel-azerty/commit/07258e573fa5652614c4f32870ccc254d10acfcf) ; kbfrFRs.klc, kbbrFRs.klc, kbfrAFs.klc, kbfrPFs.klc, kbfrFRsr.klc [c3f0eaa](https://github.com/dispoclavier/nouvel-azerty/commit/c3f0eaad69f3e9682c8d78267e589bdca4b822b4), dispocla.cpp [b7f2877](https://github.com/dispoclavier/nouvel-azerty/commit/b7f287736e5314121bac59a1a0a9c86ad155d560)
	* Corriger le tri. compose-1.yml [cfb3322](https://github.com/dispoclavier/nouvel-azerty/commit/cfb33228ba6a6eab4535eea80e31f1eaaa641f68), dead-key-convert.pl [ce85428](https://github.com/dispoclavier/nouvel-azerty/commit/ce8542895e11a1bc356f9ba230c5f7a539a53635), kbdeadtrans.c [5db9438](https://github.com/dispoclavier/nouvel-azerty/commit/5db9438418d74ac2ecdbc217f1f5ad917c00acc0)
* Builds :
	* 6.0.7.02 [c3f0eaa](https://github.com/dispoclavier/nouvel-azerty/commit/c3f0eaad69f3e9682c8d78267e589bdca4b822b4)
	* 6.0.7.03 [45745ef](https://github.com/dispoclavier/nouvel-azerty/commit/45745ef6070308f8621a0705428f4d7d87bc4d2a)

## Pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai. Toutes les touches vives sont à jour, toutes les touches mortes simples aussi.

Le contenu des enchaînements de touches mortes, dont ceux de la touche de composition, est basé sur la précédente implémentation de 2018 (parce que le script qui transpile le fichier « Compose.yml » n’est pas fini).

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le dossier « [Un-nouvel-AZERTY-Windows-6.0.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.7/Un-nouvel-AZERTY-Windows-6.0.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

## Pour Linux

La version pour Linux est entièrement à jour. Non seulement les touches vives, mais aussi le contenu des touches mortes, le fichier « Compose.yml » étant (partiellement) transpilé en C pour Windows.

Toutes les variantes AZERTY ou redisposées sont incluses (installation) ou fournies (activation), et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.0.7.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.0.7/Un-nouvel-AZERTY-Linux-6.0.7.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

## Pour macOS

La version pour macOS est en instance de réimplémentation.

À ce jour, seule une [précédente mise en œuvre](https://dispoclavier.com/doc/kbfrintu/#macos) est disponible, encore sans fichiers de configuration pour [Karabiner-Elements](https://karabiner-elements.pqrs.org).

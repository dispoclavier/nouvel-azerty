# 5.1.0 (2025-05-29)

Mise à jour de la prise en charge des émojis suite à la mise à jour de la [page d’Unicode sur les fréquences](https://home.unicode.org/emoji/emoji-frequency/).

Rétablissement de la symétrie des enchaînements de touches mortes suite à la dissociation de celles-ci avec leur équivalent en composition.

Complétion des touches mortes grâce à cet allègement des contraintes.

Rectification et amélioration des groupes des symboles.

Reconception, rectification et simplification de séquences de composition.

## Modifications

* Disposition :
	* Prendre en charge "🥰" U+1F970 sur B05 "B", niveau 8, à la place de "💕" U+1F495. dispocla.cpp [88719a8](https://github.com/dispoclavier/nouvel-azerty/commit/88719a8cb290420dc871370eb3fa144d8c2087c8), kbfrFRs.klc [96950df](https://github.com/dispoclavier/nouvel-azerty/commit/96950dfbd1209398d6c02688b381c1461179f712), kbfrFRs.C [0c294ff](https://github.com/dispoclavier/nouvel-azerty/commit/0c294ff80c6591b9288255121bd84155229ca127), kbfredis.klc [5f45c24](https://github.com/dispoclavier/nouvel-azerty/commit/5f45c24d25c41d38379078a38cce830a3a34efc8), kbfredis.C [77e3126](https://github.com/dispoclavier/nouvel-azerty/commit/77e312667408bae9d2a8194f19a0d9348ff3f863)
	* Windows : Rectifier la touche D07, niveau 3, en redondant l’apostrophe "'" au lieu de la touche de composition. kbfrFRs.klc [e16f4bb](https://github.com/dispoclavier/nouvel-azerty/commit/e16f4bb5bad199136d7855ec46b02ececfde29b6), kbfrFRs.C [42d2fb2](https://github.com/dispoclavier/nouvel-azerty/commit/42d2fb21885b67775c19db38285609d0dffb0736), kbfredis.klc [c6e29fe](https://github.com/dispoclavier/nouvel-azerty/commit/c6e29fe9b7accb1382276f1e29208e453a534f66), kbfredis.C [5a234ba](https://github.com/dispoclavier/nouvel-azerty/commit/5a234bac99b16623547ca2e33a00265c95e56be1)
* Composition :
	* Prendre en charge les filets "─" U+2500.."╿" U+257F. compose-1.yml [2d9fe01](https://github.com/dispoclavier/nouvel-azerty/commit/2d9fe018da074d60c5f40d6a57798d0df83650cd), [184dcaa](https://github.com/dispoclavier/nouvel-azerty/commit/184dcaae7988e1816792983ec2b0dd4caa61e265)
	* Prendre en charge "ꜗ" U+A717, "ꜘ" U+A718, "ꜙ" U+A719, "ꜚ" U+A71A, qui sont dans point en chef (sans composition) et dans cornu. compose-1.yml [20cfb06](https://github.com/dispoclavier/nouvel-azerty/commit/20cfb0651da809faed004af544be7ff89999572a)
	* Redonder les guillemets "‘" U+2018, "’" U+2019, "‚" U+201A, "“" U+201C, "”" U+201D, "„" U+201E. compose-1.yml [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18)
	* Redonder le point médian "·" U+00B7, qui était dans point en chef. ibidem
	* Rectifier les séquences de "⫡" U+2AE1. ibidem
	* Améliorer la prise en charge de "⨣" U+2A23. compose-1.yml [986a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/986a2e86a3d87150ea7d30af36409eaef4db8748)
	* Redonder "¦" U+00A6 par double frappe de la touche de composition. ibidem
	* Simplifier les séquences de "⪁" U+2A81, "⪂" U+2A82. compose-1.yml [0f40ccf](https://github.com/dispoclavier/nouvel-azerty/commit/0f40ccf4ac4f8ab9e5bc3cd7fcad35b1497eba80)
	* Simplifier, améliorer ou corriger les séquences de "↨" U+21A8, "↩" U+21A9, "↪" U+21AA, "↬" U+21AC, "↭" U+21AD, "↮" U+21AE, "↯" U+21AF, "↰" U+21B0, "↶" U+21B6, "↷" U+21B7, "↽" U+21BD, "↾" U+21BE, "↿" U+21BF, "⇀" U+21C0, "⇁" U+21C1, "⇂" U+21C2, "⇃" U+21C3, "⇄" U+21C4, "⇅" U+21C5, "⇆" U+21C6, "⇇" U+21C7, "⇈" U+21C8, "⇉" U+21C9, "⇊" U+21CA, "⇋" U+21CB, "⇌" U+21CC, "⇎" U+21CE, "⇏" U+21CF, "⇚" U+21DA, "⇥" U+21E5, "⇵" U+21F5, "⇶" U+21F6, "⇷" U+21F7, "⇸" U+21F8, "⇹" U+21F9, "⇺" U+21FA, "⇼" U+21FC, "⇿" U+21FF. compose-1.yml [c856506](https://github.com/dispoclavier/nouvel-azerty/commit/c856506ff3f3e740949ee6b03413d2354dafc272), compose-2.yml [b72a8e5](https://github.com/dispoclavier/nouvel-azerty/commit/b72a8e5752e39e1c82c920dacdd54b93ca145ef7)
	* Prendre en charge "﬩" U+FB29 en tant que symbole mathématique. ibidem
	* Compléter ou rectifier les séquences de "¡" U+00A1, "•" U+2022, "‣" U+2023, "∎" U+220E, "▪" U+25AA, "▮" U+25AE, "▴" U+25B4, "▵" U+25B5, "▾" U+25BE, "▿" U+25BF, "◂" U+25C2, "◦" U+25E6, "☆" U+2606. compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7)
	* Simplifier, améliorer ou corriger les séquences de "∉" U+2209, "∊" U+220A, "∌" U+220C, "∍" U+220D, "∙" U+2219, "√" U+221A, "∛" U+221B, "∜" U+221C, "∝" U+221D. ibidem
* Transformations :
	* Rétablir la symétrie des enchaînements de touches mortes, suite à la dissociation des équivalents en composition. compose-2.yml [c32ffcc](https://github.com/dispoclavier/nouvel-azerty/commit/c32ffcc62ad3ff8ae66897924d31ab01730d9e91), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Accent circonflexe et accent aigu : Idem. compose-2.yml [63745d3](https://github.com/dispoclavier/nouvel-azerty/commit/63745d31059ee53796f7f93a7515f14a08729b95), [d2a4a05](https://github.com/dispoclavier/nouvel-azerty/commit/d2a4a059bd8e421dc473ca835838ed331f66ab7a), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Tréma et accent aigu : Idem. ibidem
		* Grec-ou-cerclé et tréma et accent aigu : Idem. compose-1.yml [1230ef2](https://github.com/dispoclavier/nouvel-azerty/commit/1230ef2da60b5ffcb573bbd8b56678122554cbb6), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18)
		* Grec-ou-cerclé et tréma et tonos : Idem. ibidem
		* Exposant et tourné et brève : Idem. compose-2.yml [19b1f60](https://github.com/dispoclavier/nouvel-azerty/commit/19b1f603bbe7e0f0f88e0a94063d1bbfe967f216), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Exposant et réfléchi et rayé : Idem. ibidem
		* Exposant et crochet rétroflexe et brève : Idem. ibidem
		* Exposant et brève : Idem. ibidem
		* Exposant et rayé : Idem. ibidem
		* Exposant et petite capitale et brève : Idem. ibidem
		* Exposant et petite capitale et rayé : Idem. ibidem
		* Indice et brève : Idem. ibidem
		* Indice et rayé : Idem. ibidem
	* Exposant : Désactiver l’équivalent en composition de "⁺" U+207A, "⁻" U+207B, "⁾" U+207E, en composition en tant que symboles mathématiques. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89), [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
	* Tourné : Améliorer la prise en charge de "⸸" U+2E38. compose-2.yml [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416)
	* Réfléchi :
		* Prendre en charge "⮈" U+2B88 par "_" dans les groupes 0, 1 et 12, par rapport à "⮊" U+2B8A dans le groupe 12 de "\_". compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "⦰" U+29B0 par "}". compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Tilde :
		* Redonder "⧤" U+29E4. ibidem
		* Caractère de base ASCII de "͠" U+0360 : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Grec-ou-cerclé :
		* Redonder "⊚" U+229A, "⊝" U+229D, "⦶" U+29B6, "⧀" U+29C0, "⧁" U+29C1, "⨸" U+2A38 sans les équivalents en composition. compose-2.yml [5a00d53](https://github.com/dispoclavier/nouvel-azerty/commit/5a00d539548302c022f9277a0a989bfc5863ce8c), [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00), [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Ajuster la prise en charge de "⊗" U+2297. compose-2.yml [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00)
		* Ajuster la prise en charge du chiffre zéro "⓪" U+24EA, "⓿" U+24FF, "🄋" U+1F10B, "🄌" U+1F10C. compose-2.yml [fa15571](https://github.com/dispoclavier/nouvel-azerty/commit/fa15571a7e0dfe12fa467fbd4955b8082f004984), [c0d9932](https://github.com/dispoclavier/nouvel-azerty/commit/c0d9932181bfc7c1875f77577f387710bae4e173), [7f1e8e5](https://github.com/dispoclavier/nouvel-azerty/commit/7f1e8e5733dd6517d63bf705d5df9cde7d4ac156), [fe9fa01](https://github.com/dispoclavier/nouvel-azerty/commit/fe9fa017586b55c94fdfbd2a2995fedf4685f391)
		* Cerclé : Redonder "⦸" U+29B8. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
		* Couleur inversée :
			* Permuter les lettres cerclées, désormais par minuscule, et encadrées, désormais par capitale. compose-2.yml [c4d9ef4](https://github.com/dispoclavier/nouvel-azerty/commit/c4d9ef462a88137b9a99aaa2719c48c34cd09c00)
			* Simplifier la prise en charge des nombres "⓫" U+24EB.."⓴" U+24F4. compose-2.yml [8eb991a](https://github.com/dispoclavier/nouvel-azerty/commit/8eb991aaa243edeefcb8fff07ae622d3ef050f28)
		* Nombre cerclé : Limiter aux nombres de 11 à 20 et supprimer "㉑" U+3251.."㊿" U+32BF, qui sont en composition. compose-2.yml [c862b14](https://github.com/dispoclavier/nouvel-azerty/commit/c862b145f8eb02890a5f2b341e75822c236e7c1b), [4dd4ec3](https://github.com/dispoclavier/nouvel-azerty/commit/4dd4ec3c8e190e5e5453f826b4537588037ff775), compose-1.yml [91eac71](https://github.com/dispoclavier/nouvel-azerty/commit/91eac71bd5f0dc0c536c4fb58c3ed756cc9e4759)
	* Crosse : Diacritique espaçant : Redonder "˞" U+02DE à la place de "˽" U+02FD, qui est dans crochet rétroflexe > crochet palatal. compose-2.yml [6214504](https://github.com/dispoclavier/nouvel-azerty/commit/621450437fd27b9f46410119752e0f9dc273ba6c)
	* Point en chef :
		* Prendre en charge "ꜗ" U+A717, qui était dans macron. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4), 
		* Prendre en charge "ꜘ" U+A718, qui était dans barré. ibidem
		* Prendre en charge "ꜙ" U+A719, qui était dans rayé. ibidem et compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "∔" U+2214, "∸" U+2238. compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "⩑" U+2A51, "⩒" U+2A52. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
		* Redonder "≐" U+2250, "⋵" U+22F5, "⧊" U+29CA, "⨰" U+2A30. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Supprimer "·" U+00B7, qui va en composition. ibidem
		* Redonder "⩧" U+2A67, "⩪" U+2A6A, "⩭" U+2A6D, "⪁" U+2A81, "⪂" U+2A82, "⫃" U+2AC3, "⫄" U+2AC4. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Brève inversée :
		* Supprimer les filets "╭" U+256D.."╰" U+2570, qui vont en composition. compose-2.yml [dce207f](https://github.com/dispoclavier/nouvel-azerty/commit/dce207faecef896a03c010d6d4fe8afc4f8ba10b)
		* Caractère de base ASCII de "͡" U+0361 : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Brève inversée souscrite : Caractère de base ASCII de "᷼" U+1DFC : Changer de "?" en "=". ibidem
	* Brève :
		* Supprimer les filets "─" U+2500.."╬" U+256C, "╱" U+2571.."╿" U+257F, qui vont en composition. compose-2.yml [dce207f](https://github.com/dispoclavier/nouvel-azerty/commit/dce207faecef896a03c010d6d4fe8afc4f8ba10b)
		* Caractère de base ASCII de "͝" U+035D : Changer de "?" en "=". compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Brève souscrite : Caractère de base ASCII de "͜" U+035C : Changer de "?" en "=". ibidem
	* Rayé :
		* Redonder "⦵" U+29B5 par "}". compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Supprimer "ꜙ" U+A719, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
	* Cornu : Redonder "⥆" U+2946, "⥅" U+2945. compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
	* Indice : Désactiver l’équivalent en composition de "₋" U+208B, "₎" U+208E, en composition en tant que symboles mathématiques. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Macron :
		* Redonder "⧶" U+29F6, "⨛" U+2A1B. ibidem
		* Redonder "⦱" U+29B1 par "}". ibidem
		* Redonder "⊼" U+22BC, "⊽" U+22BD. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Caractère de base ASCII de "͞" U+035E : Changer de "?" en "=". ibidem
		* Supprimer "ꜗ" U+A717, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
		* Redonder "⋶" U+22F6 par "L", "⋷" U+22F7 par "l". compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59)
		* Redonder "⋽" U+22FD par "M", "⋾" U+22FE par "m". ibidem
		* Redonder "⩂" U+2A42 par "'", "⩃" U+2A43 par "{". ibidem
		* Redonder "⫧" U+2AE7. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Macron souscrit :
			* Redonder "⊻" U+22BB. ibidem
			* Redonder "⦋" U+298B, "⦌" U+298C, "⦥" U+29A5, "⧋" U+29CB, "⨜" U+2A1C, "⨱" U+2A31. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
			* Redonder "⦤" U+29A4. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89), [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
			* Redonder "⩟" U+2A5F. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c)
			* Redonder "⫨" U+2AE8. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
			* Caractères de base de "͟" U+035F :
				* Changer de "?" en "=". ibidem
				* Supprimer "\"" et "€". ibidem
		* Ligne souscrite : Redonder "⩠" U+2A60, "⩣" U+2A63. compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c), [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
	* Barré :
		* Redonder "≢" U+2262 dans le groupe 1 à la place de "≠" U+2260, qui va dans le groupe 0. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Redonder "≰" U+2270 et "≱" U+2271 dans les groupes 1 et 2 à la place de "≮" U+226E et "≯" U+226F, qui vont dans le groupe 0. ibidem
		* Redonder "∤" U+2224 dans le groupe 0 sans équivalent en composition. compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "∦" U+2226 dans le groupe 1 à la place de "∤" U+2224, qui va dans le groupe 0. ibidem
		* Supprimer "ꜘ" U+A718, qui va dans point en chef et en composition. compose-2.yml [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4)
	* Rond en chef :
		* Redonder "ꭘ" U+AB58 par "X", "ꭔ" U+AB54 par "q". compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f)
		* Redonder "°" U+00B0 par "8" à la place de "∗" U+2217, qui est par "5". ibidem
		* Redonder "⟟" U+27DF par "T" et "t". compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Redonder "⦲" U+29B2 par "}". ibidem
		* Redonder "⫯" U+2AEF. compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc)
		* Rond souscrit : Redonder "⫰" U+2AF0, "⫱" U+2AF1. ibidem
	* Accent circonflexe :
		* Caractère de base ASCII de "᷍" U+1DCD : Changer de "?" en "=". ibidem
		* Changer le caractère de base de "᪰" U+1AB0 de "^" en "d" ou "D". ibidem
		* Supprimer la redondance par "d" ou "D" de "⌀" U+2300, qui est sur touche vive, dans le groupe 1 de "(" et en composition. ibidem
		* Redonder "⩯" U+2A6F. ibidem
		* Désactiver l’équivalent en composition de "‘" U+2018. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
		* Améliorer la prise en charge de "⸶" U+2E36. compose-2.yml [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416)
	* Hatchek :
		* Améliorer la prise en charge de "⸷" U+2E37. ibidem
	* Point souscrit : Redonder "⩦" U+2A66. compose-2.yml [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Point souscrit et point en chef :
		* Renommer de « point en chef et point souscrit ». ibidem
		* Redonder "≑" U+2251. ibidem
	* Tréma : Désactiver l’équivalent en composition de "‚" U+201A. ibidem
	* Groupes des symboles :
		* Groupes de "'" : Prendre en charge l’apostrophe typographique comme caractère de base. compose-3.yml [075700b](https://github.com/dispoclavier/nouvel-azerty/commit/075700be17fb3e6b12aa4be9af7111efd09ee72d)
		* Groupes de "*" : Mettre "∗" U+2217 dans le groupe 12 à la place de "※" U+203B, qui prend la place laissée par "∗" U+2217 dans le groupe 11. compose-3.yml [b3df10f](https://github.com/dispoclavier/nouvel-azerty/commit/b3df10fe04964c901f601a9c63112322386f7012)
		* Groupes de "+" :
			* Mettre "⁜" U+205C dans le groupe 11 à la place de "✜" U+271C. ibidem
			* Prendre en charge "﬩" U+FB29 à la place laissée par "⁜" U+205C dans le groupe 12. ibidem
		* Groupes de "=" : Mettre "⚖" U+2696 du groupe 9 dans le groupe 5 à la place de "☕" U+2615, qui va dans le groupe 9 à la place laissée par "⚖" U+2696. compose-3.yml [74a4686](https://github.com/dispoclavier/nouvel-azerty/commit/74a468640eb9fc578ba25a5f3017514137ecffe2)
		* Groupes de "#" : Mettre "▪" U+25AA du groupe 5 dans le groupe 4 à la place de "⏹" U+23F9, qui va dans le groupe 10 à la place de "⮽" U+2BBD, qui va dans le groupe 8 à la place de "⬛" U+2B1B, qui va dans le groupe 7 à la place de "◼" U+25FC, qui va dans le groupe 6 à la place de "◾" U+25FE, qui va dans le groupe 5 à la place laissée par "▪" U+25AA. ibidem
		* Groupes de "/" : Mettre "▫" U+25AB du groupe 5 dans le groupe 4 à la place de "⛆" U+26C6, qui va dans le groupe 8 à la place de "⬜" U+2B1C, qui va dans le groupe 7 à la place de "◻" U+25FB, qui va dans le groupe 6 à la place de "◽" U+25FD, qui va dans le groupe 5 à la place laissée par "▫" U+25AB. ibidem
		* Groupes de "@" :
			* Mettre "⏺" U+23FA du groupe 4 dans le groupe 10 à la place de "❍" U+274D, qui va dans le groupe 6 à la place de "○" U+25CB, qui va dans le groupe 5 à la place de "●" U+25CF, qui va dans le groupe 4 à la place laissée par "⏺" U+23FA. ibidem
			* Mettre "⚫" U+26AB du groupe 3 dans le groupe 2 à la place de "⚪" U+26AA, qui va dans le groupe 3 à la place laissée par "⚫" U+26AB. ibidem
		* Groupes de "<" : Mettre "⏪" U+23EA du groupe 6 dans le groupe 10 à la place de "▲" U+25B2, qui va dans le groupe 6 à la place laissée par "⏪" U+23EA. ibidem
		* Groupes de ">" : Mettre "⏩" U+23E9 du groupe 6 dans le groupe 10 à la place de "▼" U+25BC, qui va dans le groupe 6 à la place laissée par "⏩" U+23E9. ibidem
		* Groupes de "|" : Mettre "⏯" U+23EF du groupe 6 dans le groupe 7 à la place de "⏸" U+23F8, qui va dans le groupe 10 à la place de "Ⓜ" U+24C2, qui va dans le groupe 6 à la place laissée par "⏯" U+23EF. ibidem
		* Groupes de "_" : Ajouter "⬝" U+2B1D à la place de "♚" U+265A, qui prend la place de "♛" U+265B, qui prend la place de "♜" U+265C, qui prend la place de "♝" U+265D, qui prend la place de "♞" U+265E, qui prend la place de "♟" U+265F, qui prend la place de "⮈" U+2B88, qui va dans réfléchi. ibidem et compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda)
		* Groupes de "[" : Mettre "⟦" U+27E6 du groupe 10 dans le groupe 4 à la place de "♔" U+2654, qui prend la place de "♕" U+2655, qui prend la place de "♖" U+2656, qui prend la place de "♗" U+2657, qui prend la place de "♘" U+2658, qui prend la place de "♙" U+2659, qui prend la place laissée par "⟦" U+27E6. compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda)
		* Groupes de "]" : Mettre "⟧" U+27E7 du groupe 10 dans le groupe 4 à la place de "◊" U+25CA, qui prend la place laissée par "⟧" U+27E7. ibidem
	* Groupes des lettres : Remplir les places vides avec le numéro du groupe. compose-3.yml [c3fc88d](https://github.com/dispoclavier/nouvel-azerty/commit/c3fc88d3824d63fd1bda1c1c6d34c7e2d8131759), [cea6029](https://github.com/dispoclavier/nouvel-azerty/commit/cea6029db089f23c7761edf9b830b15bcb9fd8a8), generate-deadkey-tables.pl [858df5a](https://github.com/dispoclavier/nouvel-azerty/commit/858df5aa869acebf5f1479db14a14700793dc53f), [d7c45fe](https://github.com/dispoclavier/nouvel-azerty/commit/d7c45fe59b8d1ea6906bfe15f1ee76d72201c02b)
* Installation, activation :
	* Rectifier les mots-clés balises au début et à la fin du fichier Compose.yml. compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda), installer.sh [0defb75](https://github.com/dispoclavier/nouvel-azerty/commit/0defb7509be305fc463c6c17e80fbb9428541884), activer.sh [ee8fbfa](https://github.com/dispoclavier/nouvel-azerty/commit/ee8fbfa504dcb77fc5df52f299b2f7cfb3a145b1)
	* Confirmer le nom de fichier Compose.yml. installer.sh [0defb75](https://github.com/dispoclavier/nouvel-azerty/commit/0defb7509be305fc463c6c17e80fbb9428541884), [8783c09](https://github.com/dispoclavier/nouvel-azerty/commit/8783c09bbf4c245f2d7048e1c1fed55d9c165a26), activer.sh [ee8fbfa](https://github.com/dispoclavier/nouvel-azerty/commit/ee8fbfa504dcb77fc5df52f299b2f7cfb3a145b1), [7b88b38](https://github.com/dispoclavier/nouvel-azerty/commit/7b88b38c6bdfec2ace1ddd02ec74df279eec9c72), compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), [bb0a703](https://github.com/dispoclavier/nouvel-azerty/commit/bb0a703572d86236efa39c58e71d3b8f0a12bc97)
* Documentation :
	* Fusionner l’introduction et les deux modes d’emploi, et répartir le contenu sur trois modes d’emploi. readme.md alias Mode-d-emploi-commun.md [3483ed3](https://github.com/dispoclavier/nouvel-azerty/commit/3483ed3a70f3803d9d657a141c6d05a27004381d), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.md [5f2387c](https://github.com/dispoclavier/nouvel-azerty/commit/5f2387c05b1cec8a6c93b2216b6d780ea1962ba7), windows/readme.md alias Mode-d-emploi-sous-Windows.md [370efda](https://github.com/dispoclavier/nouvel-azerty/commit/370efdac4c75bce77c006adc5f2b93c0e98f3c53)
	* Améliorer le tri. compose-1.yml [90ec2e0](https://github.com/dispoclavier/nouvel-azerty/commit/90ec2e0ad57e8bc16d14b6bfcf8ad24312e27b75), [2e00217](https://github.com/dispoclavier/nouvel-azerty/commit/2e00217606c0cdde8a8e6c23e0b888fdb0cad5ab), [a5e998d](https://github.com/dispoclavier/nouvel-azerty/commit/a5e998da7547ff2ded9a28c1d505aa240cdb054a)
	* Améliorer la symétrisation des enchaînements de touches mortes. compose-1.yml [8d799a3](https://github.com/dispoclavier/nouvel-azerty/commit/8d799a3374fc7bb9679c45fea99d2deff6ccd3c6), [8b41337](https://github.com/dispoclavier/nouvel-azerty/commit/8b41337013b233365373cf59c089718629fddd31)
	* Améliorer l’intertitrage. compose-1.yml [2ab9521](https://github.com/dispoclavier/nouvel-azerty/commit/2ab9521d1730b4a149c61f9bf8816db1e4f2d8f9)
	* Annoter l’ordre des caractères de base. compose-2.yml [4b5268e](https://github.com/dispoclavier/nouvel-azerty/commit/4b5268e03c4619f06b1c6eec1f5e892101cfbe00), [8b4bc7a](https://github.com/dispoclavier/nouvel-azerty/commit/8b4bc7a0a788c4f6bc7044d2c430f1974784f94a)
	* Préciser des renvois. compose-2.yml [19b1f60](https://github.com/dispoclavier/nouvel-azerty/commit/19b1f603bbe7e0f0f88e0a94063d1bbfe967f216)
	* Corriger des renvois et en ajouter. compose-1.yml [fa0dc2e](https://github.com/dispoclavier/nouvel-azerty/commit/fa0dc2ed98cb0757d3030c9fa1a221dabc4fef0f), compose-2.yml [d2a4a05](https://github.com/dispoclavier/nouvel-azerty/commit/d2a4a059bd8e421dc473ca835838ed331f66ab7a)
	* Corriger des annotations. compose-1.yml [184dcaa](https://github.com/dispoclavier/nouvel-azerty/commit/184dcaae7988e1816792983ec2b0dd4caa61e265), [957f1cf](https://github.com/dispoclavier/nouvel-azerty/commit/957f1cfa73f977f4845a4efd60f92aac10eb4d18), compose-2.yml [15d00ee](https://github.com/dispoclavier/nouvel-azerty/commit/15d00ee4075c1288f7d6d90053f36e2d9bea7668https://github.com/dispoclavier/nouvel-azerty/commit/15d00ee4075c1288f7d6d90053f36e2d9bea7668)
	* Corriger et compléter des annotations. compose-1.yml [7a11210](https://github.com/dispoclavier/nouvel-azerty/commit/7a11210edd599fd205bdc112dddd9143e568ed4a), compose-2.yml [3d2dbed](https://github.com/dispoclavier/nouvel-azerty/commit/3d2dbedfc997570ad38ae7f1e909bd4ddde3390a), [9a22577](https://github.com/dispoclavier/nouvel-azerty/commit/9a22577ea15dc8cf5ffbff1742f06ee48dc190cf), dispocla.cpp [4716ff2](https://github.com/dispoclavier/nouvel-azerty/commit/4716ff265ad7b99acaed75b9b17f2893c9695d47) ; compose-1.yml [986a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/986a2e86a3d87150ea7d30af36409eaef4db8748). compose-2.yml [67f38c8](https://github.com/dispoclavier/nouvel-azerty/commit/67f38c8c2d76a92701afb1e8b1a28c35f377aa59), compose-3.yml [075700b](https://github.com/dispoclavier/nouvel-azerty/commit/075700be17fb3e6b12aa4be9af7111efd09ee72d)
	* Corriger, ajouter ou supprimer des annotations. compose-1.yml [20cfb06](https://github.com/dispoclavier/nouvel-azerty/commit/20cfb0651da809faed004af544be7ff89999572a), compose-2.yml [e0c82bf](https://github.com/dispoclavier/nouvel-azerty/commit/e0c82bf7f3c8e0b5f3ada1703203e48af9d40e7c), [278348c](https://github.com/dispoclavier/nouvel-azerty/commit/278348c54e2b70c60c6747e559bab6eda7f4ccb4) ; compose-1.yml [f6a48ca](https://github.com/dispoclavier/nouvel-azerty/commit/f6a48ca0edfffc1833271cde3e71a5241801cd28), compose-2.yml [6214504](https://github.com/dispoclavier/nouvel-azerty/commit/621450437fd27b9f46410119752e0f9dc273ba6c), compose-3.yml [e307dc8](https://github.com/dispoclavier/nouvel-azerty/commit/e307dc8f743d9e39abafde930f498eb74b35ea2f) ; compose-1.yml [d424a41](https://github.com/dispoclavier/nouvel-azerty/commit/d424a41a2a53831e0d461a71cc1b59ee292544e7), compose-2.yml [66ee349](https://github.com/dispoclavier/nouvel-azerty/commit/66ee34943f8c8c3e2c3894cadc0e700d32ef587f), compose-3.yml [92f0932](https://github.com/dispoclavier/nouvel-azerty/commit/92f0932217cf3a9187a3fa76efa93f849b553dda), dispocla.cpp [1f6ad90](https://github.com/dispoclavier/nouvel-azerty/commit/1f6ad9015dbcf31abe5d553b4a5baeb446d13358) ; compose-1.yml [bb0a703](https://github.com/dispoclavier/nouvel-azerty/commit/bb0a703572d86236efa39c58e71d3b8f0a12bc97), compose-2.yml [29c78c1](https://github.com/dispoclavier/nouvel-azerty/commit/29c78c1c6601a3f8d0f1a67d1f9760c63142e011), compose-3.yml [74a4686](https://github.com/dispoclavier/nouvel-azerty/commit/74a468640eb9fc578ba25a5f3017514137ecffe2) ; compose-1.yml [532df9c](https://github.com/dispoclavier/nouvel-azerty/commit/532df9cf266f0c119a18605d8799271504df7f28), compose-2.yml [e224a20](https://github.com/dispoclavier/nouvel-azerty/commit/e224a2098f91ffca46d43501ea59affeda972aef), compose-3.yml [c3fc88d](https://github.com/dispoclavier/nouvel-azerty/commit/c3fc88d3824d63fd1bda1c1c6d34c7e2d8131759) ; compose-1.yml [283f286](https://github.com/dispoclavier/nouvel-azerty/commit/283f2869fb27a95ff70688fa523d9f35b68e3514), [9ea3974](https://github.com/dispoclavier/nouvel-azerty/commit/9ea3974daa8a9742efd658f26e943b21ea98a8df), compose-2.yml [272ea17](https://github.com/dispoclavier/nouvel-azerty/commit/272ea17b45d76c445911fb466d54850519fe813c), compose-3.yml [937f581](https://github.com/dispoclavier/nouvel-azerty/commit/937f581c065e91a08128c44f6f6f143833874349), dispocla_perso.cpp [d17c4a1](https://github.com/dispoclavier/nouvel-azerty/commit/d17c4a14b6ce3b4c3ab657120d3d0c37f1643942), [002b724](https://github.com/dispoclavier/nouvel-azerty/commit/002b7240451ce026c0214b5d393763839cb1c175)
	* Corriger une annotation avant déplacement. compose-1.yml [24bb803](https://github.com/dispoclavier/nouvel-azerty/commit/24bb8035745d776af9fc13e8ddab1e4fcfff886c)
	* Mieux regrouper et titrer les annotations. compose-2.yml [9e228d6](https://github.com/dispoclavier/nouvel-azerty/commit/9e228d6709040837da41ed42b6ec3c367339cdff), compose-1.yml [8a2644a](https://github.com/dispoclavier/nouvel-azerty/commit/8a2644a4d96fa60a9e115daacbb6343bf12559df)
	* Rectifier ou mettre à jour des annotations. compose-1.yml [a9308e8](https://github.com/dispoclavier/nouvel-azerty/commit/a9308e80b970de8c0d3e6edafcac7a52d14e6196), [21b7535](https://github.com/dispoclavier/nouvel-azerty/commit/21b7535de26a51d8f0a8012299c7f66f853ffa18), [0c6da50](https://github.com/dispoclavier/nouvel-azerty/commit/0c6da5070b12c1ad9ffcef17197603f62d08779a), compose-2.yml [c04e68c](https://github.com/dispoclavier/nouvel-azerty/commit/c04e68cb7be8be8911d379a080d3345e579807d8), [88e4556](https://github.com/dispoclavier/nouvel-azerty/commit/88e45568700fa3e0aa2c63cf705b6b67d1287b89)
	* Clarifier ou compléter des annotations. compose-3.yml [f4fb201](https://github.com/dispoclavier/nouvel-azerty/commit/f4fb201fa970113e1f9529f5c36930d2a1a92524)
	* Ajouter, améliorer, mettre à jour ou corriger des annotations. compose-1.yml [0f40ccf](https://github.com/dispoclavier/nouvel-azerty/commit/0f40ccf4ac4f8ab9e5bc3cd7fcad35b1497eba80), compose-2.yml [d57828a](https://github.com/dispoclavier/nouvel-azerty/commit/d57828adffc367830d3a52152af215c113e7afbc), [dbe8193](https://github.com/dispoclavier/nouvel-azerty/commit/dbe8193eaa54bb9aa5f8a4c35a2fca7890ec7416), [fe803a1](https://github.com/dispoclavier/nouvel-azerty/commit/fe803a1d3c4dd599a406feb52c29bcc14e7d64ee)
	* Corriger le journal des modifications. CHANGELOG.md [e9f7eff](https://github.com/dispoclavier/nouvel-azerty/commit/e9f7eff4aa64d6f9c84c2535fd54e5607c971453)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-5.1.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-5.1.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-5.1.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v5.1.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.1.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.1.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.1.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.1.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

Puis fermer la session et en rouvrir une. 

Ce nouvel AZERTY figure dans le dossier des dispositions de clavier `Français (France)` sous le nom `Français France disposition de clavier semi-automatique` et peut être ajouté aux dispositions actives. Afin de l’activer, il est devenu nécessaire de désactiver l’autre disposition.

Les variantes AZERTY s’appellent :

* `Breton et français disposition de clavier semi-automatique` ;
* `Polynésie Française disposition de clavier semi-automatique` ;
* `Afrique francophone disposition de clavier semi-automatique` ;
* `Français Belgique disposition de clavier semi-automatique`.

Les variantes redisposées QZJFGY s’appellent :

* `Français France disposition de clavier semi-automatique redisposée` ;
* `Breton et français disposition de clavier semi-automatique redisposée` ;
* `Polynésie française disposition de clavier semi-automatique redisposée` ;
* `Afrique francophone disposition de clavier semi-automatique redisposée`.

La variante belge ne se décline pas en variante redisposée parce que l’intérêt d’avoir une variante belge, c’est une assez bonne rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

Les vues de disposition se veulent un compromis entre les 8 positions par touche programmables dans XKB et les 4 positions par touche pris en charge par les vues. Les rectangles avec un code sont des touches mortes ou des séquences définies dans le répertoire des touches mortes et des séquences Compose(.yml).

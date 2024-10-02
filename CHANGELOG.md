# Journal des modifications

Le deux-barrettes ou la barre brisée, barre discontinue, barre déjointe, barre à trou "¦" U+00A6 représente la touche de composition "⎄" U+2384. Les séquences de composition sont entre guillemets français pour la lisibilité : « ¦#' ».

## 4.4.6 (2024-10-02)

* Composition : Supprimer "ʼN" U+02BC U+004E. compose-1.yml [24b2f6b](https://github.com/dispoclavier/nouvel-azerty/commit/24b2f6bf215e1132ccfe135a5c14da97fcde61b3)
* Documentation : Corriger des annotations. dispocla.cpp [b9ca449](https://github.com/dispoclavier/nouvel-azerty/commit/b9ca449e93678f4ab94e23f323f2fa098d8c2bb7), compose-1.yml [24b2f6b](https://github.com/dispoclavier/nouvel-azerty/commit/24b2f6bf215e1132ccfe135a5c14da97fcde61b3), [ceffb2a](https://github.com/dispoclavier/nouvel-azerty/commit/ceffb2a5ea86d1ba50437ec913ee0c520bd3ec30), compose-2.yml [d72e791](https://github.com/dispoclavier/nouvel-azerty/commit/d72e791471c412d75dbab07ae709d69ef4b352d8), [2f12a33](https://github.com/dispoclavier/nouvel-azerty/commit/2f12a3398796c734d9ec5ee27d823b1d6ec778a1), compose-3.yml [07c7bee](https://github.com/dispoclavier/nouvel-azerty/commit/07c7bee6887a227028131bebfb7e318bc5c33c96)

## 4.4.5 (2024-09-30)

* Documentation : Corriger des annotations. compose-1.yml [e1ff957](https://github.com/dispoclavier/nouvel-azerty/commit/e1ff957eaf396e7d19ce20c4d332e4cc3afe5494)

## 4.4.4 (2024-09-30)

* Documentation : Corriger des annotations. compose-1.yml [1690492](https://github.com/dispoclavier/nouvel-azerty/commit/1690492790286bb4c6043e7202783d975cc20429)

## 4.4.3 (2024-09-29)

* Documentation : Corriger des annotations. compose-1.yml [154f6a5](https://github.com/dispoclavier/nouvel-azerty/commit/154f6a51ac081b8e88fe9413c3337c9c8d7ce6b3)

## 4.4.2 (2024-09-29)

* Documentation : Corriger des annotations. compose-1.yml [20c53d0](https://github.com/dispoclavier/nouvel-azerty/commit/20c53d0d5f5e8f240d77550c6e7eb27f9ab8cde9), compose-2.yml [8cc6866](https://github.com/dispoclavier/nouvel-azerty/commit/8cc6866e2f52ade8224ca12b636cc08956ce6e84)

## 4.4.1 (2024-09-27)

* Documentation : Corriger des annotations. compose-1.yml [52fb86d](https://github.com/dispoclavier/nouvel-azerty/commit/52fb86d165d3db5f392da3a259aaa69dfdd26645)

## 4.4.0 (2024-09-26)

Redisposition des trois premiers groupes du tiret bas.

* Transformations :
	* Groupes des symboles : Redonder "‣" U+2023 à la place de "◦" U+25E6, qui prend la place de "•" U+2022, qui prend la place de "―" U+2015, qui est sur touche vive ou dans le groupe 1 de "ɔ" U+0254, "Ɔ" U+0186, "ñ" U+00F1, "Ñ" U+00D1, "ʻ" U+02BB, "‑" U+2011, dans raie haute et en composition par « ¦8- ». compose-3.yml [d93a4d9](https://github.com/dispoclavier/nouvel-azerty/commit/d93a4d994914a50073429b5e6aade265eec61281), compose-1.yml [f57e338](https://github.com/dispoclavier/nouvel-azerty/commit/f57e3380a1d6ddd40c86891a0a7cc0bd630bcf75)
	* Accent aigu : Supprimer "ʻ" U+02BB (par ","), qui est dans le groupe 1 de "`" et va dans accent circonflexe (par ","). compose-2.yml [6994434](https://github.com/dispoclavier/nouvel-azerty/commit/6994434b505b5808e887099048acbd26c1da451d)
	* Accent circonflexe : Redonder "ʻ" U+02BB (par ",") à la place de "ʼ" U+02BC, qui est dans le groupe 1 de "'" et "’". ibidem
	* Accent grave : Supprimer "ʻ" U+02BB (par ","), qui est dans le groupe 1 de "`" et va dans accent circonflexe (par ","). ibidem
	* Cédille et accent aigu : Rétablir la symétrie des séquences. ibidem

## 4.3.1 (2024-09-22)

* Composition :
	* Adapter les séquences de "🅭" U+1F16D, "©" U+00A9 pour déboguer "©" U+00A9. compose-1.yml [cf47ccf](https://github.com/dispoclavier/nouvel-azerty/commit/cf47ccf1703b54cd0c7b116363632eef6964a769)
	* Adapter les séquences de "№" U+2116 pour le déboguer. ibidem
	* Adapter les séquences de "▾" U+25BE, "▿" U+25BF pour les déboguer. ibidem
	* Adapter les séquences de "‰" U+2030 pour le déboguer. ibidem
	* Adapter les séquences de "₱" U+20B1 pour le déboguer. ibidem
	* Adapter les séquences de "₴" U+20B4 pour le déboguer. ibidem
	* Adapter les séquences de "¤" U+00A4, "©" U+00A9 pour les déboguer. ibidem
	* Adapter les séquences de "⇪" U+21EA, "⇪" U+2BB8 pour les déboguer. ibidem
	* Adapter les séquences de "⇭" U+21ED pour l’intuitivité. ibidem
	* Adapter les séquences de "⎄" U+2384 pour déboguer "℅" U+2105. ibidem
	* Adapter les séquences de "‬" U+202C pour déboguer. ibidem
	* Adapter les séquences de "€" U+20AC pour déboguer. ibidem
	* Adapter les séquences de "℈" U+2108 pour déboguer. ibidem
	* Adapter les séquences de "⟲" U+27F2 pour déboguer "ℷ" U+2137. ibidem
	* Adapter les séquences de "♮" U+266E pour déboguer "♪" U+266A. ibidem
	* Adapter les séquences de "♫" U+266B pour déboguer. ibidem
	* Adapter les séquences de "⫛" U+2ADB pour déboguer "⫙" U+2AD9. ibidem
	* Adapter les séquences de "⧵" U+29F5 pour déboguer "⦰" U+29B0. ibidem
	* Adapter les séquences de "♣" U+2663 pour déboguer "⑧" U+2467. ibidem
* Transformations :
	* Rond en chef : Redonder "°" U+00B0 par "0" à la place de "∗" U+2217, qui est par "5" et par "8" et en composition. compose-2.yml [f1d465e](https://github.com/dispoclavier/nouvel-azerty/commit/f1d465e92b885ae0659bfaa5d3d418f18b7f2b13)
	* Tilde et perluète : Redonder "⃤" U+20E4 par espace, "ǃ" U+01C3 par espace insécable. compose-2.yml [200f140](https://github.com/dispoclavier/nouvel-azerty/commit/200f140f51a74d099094538508884a94f12e4dbf)
* Documentation :
	* Annoter les symboles verset et répons "℣" U+2123, "℟" U+211F. compose-3.yml [922c0cd](https://github.com/dispoclavier/nouvel-azerty/commit/922c0cd65df9b747ad51aaf3125deb9fe6ff5486)
	* Annoter le lambda latin "Ꟛ" U+A7DA, "ꟛ" U+A7DB nouveau dans Unicode 16.0. compose-3.yml [0a09f16](https://github.com/dispoclavier/nouvel-azerty/commit/0a09f168552723f476ad8fc6acfdad6c715037da)
	* Annoter l’histoire tourmentée de l’espace fine insécable U+202F. compose-1.yml [1760222](https://github.com/dispoclavier/nouvel-azerty/commit/1760222baa5718774890688739d38ffbaf62821d), [065cc9a](https://github.com/dispoclavier/nouvel-azerty/commit/065cc9ad20fd16e144d7c9c498e4e29a7f4d15d5)
	* Mettre à jour le dump de la feuille de calcul des groupes des lettres. compose-3.yml [2be2cb3](https://github.com/dispoclavier/nouvel-azerty/commit/2be2cb3a680f9fd36634d5a5be63764843b3c961)
	* Vérifier et déboguer les tableaux de touches mortes. generate-deadkey-tables.pl [4ae76f8](https://github.com/dispoclavier/nouvel-azerty/commit/4ae76f8964d06ff27d4d7e71eaea3d3455421088), [f2cccfa](https://github.com/dispoclavier/nouvel-azerty/commit/f2cccfa397e8868b3b1772aa1249a13e8ad7785d), generate-math-table.pl [14d4fee](https://github.com/dispoclavier/nouvel-azerty/commit/14d4feeeca766cb1a5ec3d4248c68cfba1833b28), [6928407](https://github.com/dispoclavier/nouvel-azerty/commit/6928407c1d24fc3723c1aa67e11c214a47b3b6b3), [4990388](https://github.com/dispoclavier/nouvel-azerty/commit/49903883bfb3ebf0676a56ea4c36e51fde4225cd), generate-multikey-tables.pl [fb2a13b](https://github.com/dispoclavier/nouvel-azerty/commit/fb2a13b6d0911ac898fc88bf3d67a84da1479c7a), [8daf19a](https://github.com/dispoclavier/nouvel-azerty/commit/8daf19ae6a320071325fb8f73538a368879b07a1)

## 4.3.0 (2024-09-15)

Mise à jour vers Unicode 16.0, bouclage de la prise en charge de l’écriture latine.

Permutation du liant et de l’antiliant, plus fréquent et désormais plus facile à saisir sur AltGr + AltFr + W.

* Disposition :
	* Permuter l’antiliant U+200C et le liant U+200D afin que l’antiliant soit sur AltGr + AltFr + W, et le liant sur AltGr + AltFr + Q. dispocla.cpp [b10b147](https://github.com/dispoclavier/nouvel-azerty/commit/b10b147daa058e2737e68176acae3debae34c259)
	* Annoter les apostrophes. dispocla.cpp [fc81a5e](https://github.com/dispoclavier/nouvel-azerty/commit/fc81a5e1e38d6226f136b979783dd4a5f020ba76)
* Composition :
	* Ajouter "˹" U+02F9 par « ¦h( », "˺" U+02FA par « ¦h) », "˻" U+02FB par « ¦b( », "˼" U+02FC par « ¦b) », "꜠" U+A720 par « ¦h'( », "꜡" U+A721 par « ¦b'( » et alternatives. compose-1.yml [087907a](https://github.com/dispoclavier/nouvel-azerty/commit/087907a93adceaefdab7e3a5083190fed269a4cc), [cb0c2fe](https://github.com/dispoclavier/nouvel-azerty/commit/cb0c2fe6d6c9e4fb8a3ada2db3d71666e05e60b2), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Redonder "—" U+2014 par « ¦---- ». compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
	* Redonder "ᴖ" U+1D16 par « ¦osup », "ᴗ" U+1D17 par « ¦oinf ». compose-1.yml [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Compléter les séquences de "ª" U+00AA, "º" U+00BA. compose-1.yml [5f16588](https://github.com/dispoclavier/nouvel-azerty/commit/5f16588846b8755832fc67dec60a1f578c0bf792)
	* Adapter les séquences de "⩵" U+2A75, "⩟" U+2A5F, "⩠" U+2A60. compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43)
	* Supprimer "‘" U+2018, "’" U+2019, "‚" U+201A, "“" U+201C, "”" U+201D, "„" U+201E, qui sont dans accent circonflexe, dans accent aigu ou dans tréma. compose-1.yml [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
	* Annoter les symboles "⎄" U+2384 et "¦" U+00A6. compose-1.yml [1ce8524](https://github.com/dispoclavier/nouvel-azerty/commit/1ce852455e81374dd67cf9ce7acec0be6c737179)
	* Corriger et mettre à jour. compose-1.yml [9fca357](https://github.com/dispoclavier/nouvel-azerty/commit/9fca35712d6873f5fceda410ab1b8ab578f99993)
* Transformations :
	* Déboguer "͚" U+035A, "͜" U+035C, "͝" U+035D, "͞" U+035E, "͟" U+035F, "∄" U+2204, "∉" U+2209, "∌" U+220C. compose-2.yml [22b3da4](https://github.com/dispoclavier/nouvel-azerty/commit/22b3da4dd3e2e0b5c9ef62794c15296584414a17)
	* Groupes des lettres :
		* Groupe 3 :
			* Ajouter "Ꟛ" U+A7DA à la place de "ꬷ" U+AB37, qui va dans le groupe 11 à la place de "℄" U+2104, qui est en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Ajouter "ꟛ" U+A7DB à la place de "ƛ" U+019B, qui va dans barré et groupe 1 à 3. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Groupe 4 :
			* Ajouter "Ɤ" U+A7CB. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Redonder "ⱷ" U+2C77 à la place de "ᴗ" U+1D17, qui est dans brève souscrite et va en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Redonder "Ω" U+2126 à la place de "ᴖ" U+1D16, qui est dans brève inversée souscrite et va en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Supprimer "℃" U+2103, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Groupe 11 :
			* Redonder "ʩ" U+02A9 à la place de "℉" U+2109, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
			* Supprimer "℉" U+2109, qui est dans rond en chef et en composition. compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
	* Groupes des symboles : Redonder "⁀" U+2040 et "‿" U+203F à la place de "❨" U+2768 et "❩" U+2769. compose-3.yml [d93e3f1](https://github.com/dispoclavier/nouvel-azerty/commit/d93e3f135ec7a44bd6e108311393c4ddf945383d), [7b5984c](https://github.com/dispoclavier/nouvel-azerty/commit/7b5984c6792f47ebbda409340f60d9e948aaff63), [e154597](https://github.com/dispoclavier/nouvel-azerty/commit/e1545979d2487809abe4ffd87048beb2f463335b), compose-2.yml [9598dbd](https://github.com/dispoclavier/nouvel-azerty/commit/9598dbd0530f1860d1df1adef0f2b5dad011bb2c)
	* Exposant : Ajouter "ꜛ" U+A71B par "<", "ꜜ" U+A71C par ">". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Exposant et groupe 1 : Ajouter "ᵸ" U+1D78. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Exposant > Suscrit :
		* Ajouter "᪻" U+1ABB par "(", "᪼" U+1ABC par ")", "⃰" U+20F0 par "*". compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
		* Ajouter "᷾" U+1DFE par "<", "͐" U+0350 par ">". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
	* Exposant > Suscrit et groupe 1 : Ajouter "᫆" U+1AC6 par espace. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Tilde :
		* Corriger les séquences de "⁓" U+2053, "͠" U+0360. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "︢" U+FE22, "︣" U+FE23. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Supprimer "¡" U+00A1, "¿" U+00BF, qui sont dans le groupe 1. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Tilde et barré : Rajouter "≁" U+2241. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Tilde et perluète :
		* Ajouter pour "᪾" U+1ABE, "⃞" U+20DE, "⃟" U+20DF, "⃠" U+20E0, "⃢" U+20E2, "⃣" U+20E3, "⃤" U+20E4, "⃧" U+20E7, "⃪" U+20EA. compose-2.yml [bbbe67d](https://github.com/dispoclavier/nouvel-azerty/commit/bbbe67d92836a2a2ba864d9ff65115f0d0e10b21)
		* Ajouter "᫁" U+1AC1, "᫂" U+1AC2, "᫃" U+1AC3, "᫄" U+1AC4, "᫇" U+1AC7, "᷹" U+1DF9, "︠" U+FE20, "︡" U+FE21, "︢" U+FE22, "︣" U+FE23, "︤" U+FE24, "︥" U+FE25, "︧" U+FE27, "︨" U+FE28, "︩" U+FE29, "︪" U+FE2A, "︫" U+FE2B, "︬" U+FE2C. compose-2.yml [f8e7710](https://github.com/dispoclavier/nouvel-azerty/commit/f8e7710f1bc622957a7429b8291c0090ddfe2d03), [61f95d9](https://github.com/dispoclavier/nouvel-azerty/commit/61f95d914c377c61b22d4f12d34750c66aad5c04), [4824efc](https://github.com/dispoclavier/nouvel-azerty/commit/4824efce2c60d3b7915bd0e9587a4529051e0406), [47251d6](https://github.com/dispoclavier/nouvel-azerty/commit/47251d6f660f6809e32c131442ce88cbfdac3372), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ǀ" U+01C0, "ǁ" U+01C1, "ǂ" U+01C2, "ǃ" U+01C3, "𐞹" U+107B9, "ʘ" U+0298. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Tilde > Tilde médian : Redonder "︩" U+FE29, "︪" U+FE2A. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Point en chef :
		* Redonder "·" U+00B7 pour la compatibilité ascendante avec la composition héritée. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
		* Redonder "ȷ" U+0237 en Majuscule. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Brève inversée :
		* Corriger les séquences de "͡" U+0361, "⁐" U+2050, "𝼀" U+1DF00. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "̯" U+032F (par "&"), qui est dans brève inversée souscrite par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Brève inversée > Brève inversée souscrite : Corriger les séquences de "᷼" U+1DFC. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Brève :
		* Corriger les séquences de "͝" U+035D. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "̮" U+032E (par "&"), qui est dans brève souscrite par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Brève > Brève souscrite :
		* Redonder "Ḫ" U+1E2A, "ḫ" U+1E2B. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Corriger les séquences de "͜" U+035C. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Rayé : Redonder "ꜙ" U+A719. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
	* Rayé > Double raie : Redonder "–" U+2013 pour la compatibilité ascendante avec la composition héritée. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Rayé > Raie haute : Redonder "―" U+2015. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Cornu : Ajouter "᫉" U+1AC9, "᫊" U+1ACA. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b), [b69f110](https://github.com/dispoclavier/nouvel-azerty/commit/b69f110ec20787cda555e6c7bd558f17b565c8b9)
	* Cornu : Ajouter "ꜚ" U+A71A à la place de "˖" U+02D6, qui va sur "p" et "P" et toutes les lettres inutilisées. compose-2.yml [30bb5de](https://github.com/dispoclavier/nouvel-azerty/commit/30bb5de97e8e1677a92f31ea1e34cd3b97a2a575)
	* Indice > Souscrit :
		* Ajouter "͎" U+034E et "͍" U+034D par "1" et "2". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter "᪸" U+1AB8 par "J". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter ""͢" U+0362 par "_". compose-2.yml [efd6db5](https://github.com/dispoclavier/nouvel-azerty/commit/efd6db58f7ef1fa17388962602f8a0d6eda04bd4)
		* Ajouter "᪽" U+1ABD à la place de "̜" U+031C et "̹" U+0339, qui sont dans le groupe 5 de D et F. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
	* Macron :
		* Corriger les séquences de "͞" U+035E. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ꜗ" U+A717 à la place de "͞" U+035E, qui sort par tiret cadratin et par arobase. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "ǀ" U+01C0 par "5" à la place de "¦" U+00A6, qui est dans le groupe 12 de "|", dans tréma et en composition. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ǁ" U+01C1 par "8" à la place de "⏸" U+23F8, qui est dans le groupe 7 de "|". compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "︤" U+FE24, "︥" U+FE25. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "¢" U+00A2 par "c". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
		* Redonder "ɺ" U+027A par "R". compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Macron > Macron souscrit :
		* Corriger les séquences de "͟" U+035F. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "︫" U+FE2B, "︬" U+FE2C. compose-2.yml [8506ccd](https://github.com/dispoclavier/nouvel-azerty/commit/8506ccd29d06433210287a8496c555d221fbcf0d), [a55770b](https://github.com/dispoclavier/nouvel-azerty/commit/a55770b2038fe8fcc863f1b9cb87e1cf4d3c705c), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Barré :
		* Ajouter "Ꝃ" U+A742, "ꝃ" U+A743 à la place de "Ꞣ" U+A7A2, "ꞣ" U+A7A3 qui vont dans barre inclinée. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Ajouter "Ꟍ" U+A7CC, "ꟍ" U+A7CD à la place de "Ꞩ" U+A7A8, "ꞩ" U+A7A9 qui vont dans barre inclinée. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "ꜘ" U+A718 à la place de "∉" U+2209, qui est dans le groupe 2 et en composition. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Redonder "∕" U+2215 à la place de "ꜘ" U+A718, qui sort par "€" U+20AC et par "\"". compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Supprimer "≁" U+2241, qui va dans tilde et barré pour être débogué. compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc)
	* Barré et groupe 1 à 3 : Ajouter "Ƛ" U+A7DC, "ƛ" U+019B. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Barré > Barre inclinée :
		* Renommer de « barre courte » en « barre inclinée ». compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Ajouter "Ꞣ" U+A7A2, "ꞣ" U+A7A3 à la place de "Ꝃ" U+A742, "ꝃ" U+A743 qui vont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Ajouter "Ꞡ" U+A7A0, "ꞡ" U+A7A1, "Ꞥ" U+A7A4, "ꞥ" U+A7A5, "Ꞧ" U+A7A6, "ꞧ" U+A7A7, "Ꞩ" U+A7A8, "ꞩ" U+A7A9. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "Ꝃ" U+A742, "ꝃ" U+A743, qui vont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Supprimer "Ꝙ" U+A758, "ꝙ" U+A759, qui sont dans barré. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "⟋" U+27CB à la place de "ꜗ" U+A717, qui va dans macron. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
	* Barré > Triple barre :
		* Renommer et ajouter "᷻" U+1DFB à la place de "⃫" U+20EB, qui est en composition. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
		* Ajouter "␥" U+2425 à la place de "ꜙ" U+A719, qui va dans rayé. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Rond en chef : Redonder "ʾ" U+02BE, "ʿ" U+02BF, "˒" U+02D2, "˓" U+02D3, "∗" U+2217. compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
	* Accent circonflexe :
		* Corriger les séquences de "᪰" U+1AB0, "᷍" U+1DCD. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2), [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c)
		* Redonder "•" U+2022. compose-2.yml [2fa4753](https://github.com/dispoclavier/nouvel-azerty/commit/2fa4753fd064af7f415af4c9ea575e5bf44ca3aa)
		* Supprimer "̭" U+032D (par "&"), qui est dans accent circonflexe souscrit par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Accent circonflexe > Accent circonflexe souscrit :
		* Redonder "ꞈ" U+A788 à la place de "‸" U+2038, qui est dans le groupe 11 de "^". compose-2.yml [7b1ceef](https://github.com/dispoclavier/nouvel-azerty/commit/7b1ceef466ad3adcefa214ee7ccbb3575e25e20a)
		* Ajouter "˿" U+02FF par "\"" et "€". compose-2.yml [03501b0](https://github.com/dispoclavier/nouvel-azerty/commit/03501b0b1c130f7beebbfaec430b3a247c40a1dc), [b69f110](https://github.com/dispoclavier/nouvel-azerty/commit/b69f110ec20787cda555e6c7bd558f17b565c8b9), [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Hatchek : Supprimer "̬" U+032C (par "&"), qui est dans hatchek souscrit par espace. compose-2.yml [99871f5](https://github.com/dispoclavier/nouvel-azerty/commit/99871f5da91216609c0c8ff460e676628ac84ef2)
	* Hatchek > Hatchek souscrit : Ajouter "ˬ" U+02EC par espace insécable ou espace fine insécable à la place de "˯" U+02EF, qui sort par "v" ou "V". compose-2.yml [e64dc0c](https://github.com/dispoclavier/nouvel-azerty/commit/e64dc0cd464f3b590aa32f4bba10adf2859b64ea)
	* Drapeau : Ajouter "˭" U+02ED à la place de "⚑" U+2691 et "⚐" U+2690, qui vont en double frappe, suivis par "🏴" U+1F3F4. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
	* Drapeau > Double drapeau : Redonder "͌" U+034C, rajouter "⚑" U+2691, "⚐" U+2690, "🏴" U+1F3F4. compose-2.yml [6b97616](https://github.com/dispoclavier/nouvel-azerty/commit/6b97616a40b931df209afcb96ebaf19ac2a2cf7b)
* Documentation :
	* Chaînes de caractères pour touches vives et contenu des touches mortes :
		* Corriger la description dans l’en-tête. compose-1.yml [823ba32](https://github.com/dispoclavier/nouvel-azerty/commit/823ba3231c7672af253778796ab3864802e91f7f), [ff713ff](https://github.com/dispoclavier/nouvel-azerty/commit/ff713ff537b12f08f25b898fb7c2e1f79528057b), [990db28](https://github.com/dispoclavier/nouvel-azerty/commit/990db28e0725537e3073bc0ddb8d5e0667bd4e43), compose-2.yml [f948ed2](https://github.com/dispoclavier/nouvel-azerty/commit/f948ed2ec1274c967845d8a360e7507cd5687b9c), compose-3.yml [e3d507e](https://github.com/dispoclavier/nouvel-azerty/commit/e3d507ecd767c2354831676804a152978b30e64a)
		* Corriger les notes à propos des tableaux. compose-1.yml [ff713ff](https://github.com/dispoclavier/nouvel-azerty/commit/ff713ff537b12f08f25b898fb7c2e1f79528057b), [8647ed0](https://github.com/dispoclavier/nouvel-azerty/commit/8647ed07e214334df54f6048c365461efcdfe889), [ed84348](https://github.com/dispoclavier/nouvel-azerty/commit/ed843489a2adb2bd0257f2ef4de3efc6ca0e19d7)
	* Arrêt de "∼" U+223C dans le groupe 1 (4.1.0) : Compléter l’annotation. compose-3.yml [6a129d8](https://github.com/dispoclavier/nouvel-azerty/commit/6a129d823e3ded94273e08be43c5fe855f86822f)
	* Journal des modifications :
		* Uniformiser l’ordre des entrées. CHANGELOG.md [018acd1](https://github.com/dispoclavier/nouvel-azerty/commit/018acd112a6808fed563582996b6aea7fb044f2b)
		* Supprimer les parenthèses autour des fichiers modifiés. CHANGELOG.md [882c246](https://github.com/dispoclavier/nouvel-azerty/commit/882c2461834633c76f6a31a05584850c36fd1077)
		* Corriger la désignation des sources de disposition fusionnées. CHANGELOG.md [c391350](https://github.com/dispoclavier/nouvel-azerty/commit/c391350e0e4399144e43b4ad62c1daaadb9c7058)
		* Copier dans les notes de version les résumés omis dans le journal des modifications. CHANGELOG.md [de3e0fe](https://github.com/dispoclavier/nouvel-azerty/commit/de3e0fe658bd43ee919ac8dbea8f92528d322615)
		* Corriger la notation des séquences de composition. CHANGELOG.md [a32211b](https://github.com/dispoclavier/nouvel-azerty/commit/a32211baf420d2b1d568eed504d00699209e2aff)
		* Corriger la notation des caractères de base. CHANGELOG.md [f5e86ed](https://github.com/dispoclavier/nouvel-azerty/commit/f5e86ed338ddd6f642f99cef00c2ed0ff1ca3719), [78b5ad8](https://github.com/dispoclavier/nouvel-azerty/commit/78b5ad8ab9f70f489e53093d12f24f67ee377e22)
		* Ajouter la légende de la touche de composition. CHANGELOG.md [97e4faa](https://github.com/dispoclavier/nouvel-azerty/commit/97e4faa49733ee698881a67e62372e5197bca4df), [e866674](https://github.com/dispoclavier/nouvel-azerty/commit/e8666740a1db17f7abe2ce95bbd7e24016199007), [daf5c44](https://github.com/dispoclavier/nouvel-azerty/commit/daf5c4461d97478c84e3a1874cc5db0c294d3764)

## 4.2.1 (2024-08-30)

* Activation : Protéger un fichier .XCompose préexistant. activer.sh [5294412](https://github.com/dispoclavier/nouvel-azerty/commit/52944122d4387903e7dcab78e086da68f9a79c39), linux-chromeos/readme.md [7507ed6](https://github.com/dispoclavier/nouvel-azerty/commit/7507ed68e69df11aa2fc4d7d33c7b95b6c164a07), Lisez-moi-svp.txt [f4941b0](https://github.com/dispoclavier/nouvel-azerty/commit/f4941b0d91da34069404fe9024dc59108992ac38)

## 4.2.0 (2024-08-30)

Facilitation des mises à jour par le script d’installation.

Simplification et automatisation de l’activation sans droits d’administrateur par le nouveau script d’activation.

* Installation : Faciliter les mises à jour. installer.sh [0c93aaa](https://github.com/dispoclavier/nouvel-azerty/commit/0c93aaa8bb2aca60787791bf497a292ba0d45a91), [172f1a2](https://github.com/dispoclavier/nouvel-azerty/commit/172f1a2773bc49e2b9952208492cff5598c65777), [cd024ef](https://github.com/dispoclavier/nouvel-azerty/commit/cd024ef57cf461fa586cb52215754b690a006f88), linux-chromeos/readme.md [1145307](https://github.com/dispoclavier/nouvel-azerty/commit/114530720e83ca1b7325c69fd4c6eab8cf01fad0)
* Activation :
	* Fournir un script pour faciliter l’activation. activer.sh [5fb5636](https://github.com/dispoclavier/nouvel-azerty/commit/5fb563605062fa49667bcb1f468a75074fc5fb2c), [06f0482](https://github.com/dispoclavier/nouvel-azerty/commit/06f04828103e593619a0de7886b18627d0e81fd0), [638dc31](https://github.com/dispoclavier/nouvel-azerty/commit/638dc31e6ba514de87b5cb394ee4e7f183747913), [062df8e](https://github.com/dispoclavier/nouvel-azerty/commit/062df8e46f5c6a8a46980b90ba4373e85d7e25f1), [26e0bee](https://github.com/dispoclavier/nouvel-azerty/commit/26e0beed9d211c07c9fcbb09bd59cf7df32a2d46) (aussi [10536e7](https://github.com/dispoclavier/nouvel-azerty/commit/10536e7e3d557e2e720a8533316cf1f6873d33ef), [064156b](https://github.com/dispoclavier/nouvel-azerty/commit/064156b60533a10360f8ddc2e45d218b89ce05df), [760efce](https://github.com/dispoclavier/nouvel-azerty/commit/760efcea392533981c3d52a1c749a0c40fc94756)), Lisez-moi-svp.txt [10b5b33](https://github.com/dispoclavier/nouvel-azerty/commit/10b5b330fa037cd0d6d45dbb12dbd3cff9b09092), linux-chromeos/readme.md [6dd8aec](https://github.com/dispoclavier/nouvel-azerty/commit/6dd8aeca92bde97bc35254db43adec7209626230), [3f6716d](https://github.com/dispoclavier/nouvel-azerty/commit/3f6716da00c70d9e1802070b4b29b35b98d48ed1)
	* Proposer d’automatiser l’activation au démarrage. activer.sh [46e54f8](https://github.com/dispoclavier/nouvel-azerty/commit/46e54f8ba7ce6c846bfece16a958269ef11d07ed), [4626000](https://github.com/dispoclavier/nouvel-azerty/commit/46260003e27d8c47b9108be75e52dad69de154c5), [76df7f0](https://github.com/dispoclavier/nouvel-azerty/commit/76df7f091b6b87df14047e0d290ba6db63b95545), [2352530](https://github.com/dispoclavier/nouvel-azerty/commit/2352530cdf4412656f9c1718c5f92d26e8894250), [db1b73e](https://github.com/dispoclavier/nouvel-azerty/commit/db1b73e71ec15ca162c406587e35e30426e3d43b), linux-chromeos/readme.md [6dd8aec](https://github.com/dispoclavier/nouvel-azerty/commit/6dd8aeca92bde97bc35254db43adec7209626230), [3f6716d](https://github.com/dispoclavier/nouvel-azerty/commit/3f6716da00c70d9e1802070b4b29b35b98d48ed1)
	* Prévoir la fourniture de dispositions compilées comme une alternative aux sources de disposition fusionnées. comp.sh [e63e247](https://github.com/dispoclavier/nouvel-azerty/commit/e63e24766508f87fb72af37802f64e8d98e6773e), [6229021](https://github.com/dispoclavier/nouvel-azerty/commit/622902160670f9539eda3068af419a765f282dd5), [bbd0f42](https://github.com/dispoclavier/nouvel-azerty/commit/bbd0f42b44a516ca740c647c57106e0f0007e128)

## 4.1.0 (2024-08-23)

Le symbole racine cède sa place sur touche vive au symbole rapport, plus utile seul.

* Disposition : Redonder "∶" U+2236 sur AltGr + AltFr + R à la place de "√" U+221A, qui est dans le groupe 2 de "\" avec "∛" U+221B dans le groupe 3 et "∜" U+221C dans le groupe 4. dispocla.cpp [173f7b0](https://github.com/dispoclavier/nouvel-azerty/commit/173f7b0b728821c322c241cba5e306a26f232dc8)
* Composition : Adapter les séquences de "∻" U+223B, "≀" U+2240, "≁" U+2241, "⟦" U+27E6, "⩳" U+2A73, "⫝" U+2ADD. compose-1.yml [6c30d09](https://github.com/dispoclavier/nouvel-azerty/commit/6c30d09f968239d96b81d904070d01b2fcdc45a6)
* Transformations:
	* Groupes des symboles :
		* Groupes 1 et 2 de "~" : Redonder "≈" U+2248 à la place de "≃" U+2243, qui prend la place de "∼" U+223C, (un doublon de "~") qui est en composition. compose-3.yml [26ccb63](https://github.com/dispoclavier/nouvel-azerty/commit/26ccb63af7e56d1a72acc6279f79e76e759bc5d7), [ec2dcd4](https://github.com/dispoclavier/nouvel-azerty/commit/ec2dcd43ad42ef16baae966a75f30592ad02d60f), compose-1.yml [544cb51](https://github.com/dispoclavier/nouvel-azerty/commit/544cb516d2a2d705313f76855b5a60ba4a6e5ae3)
		* Groupe 11 de "!" : Ajouter "⸙" U+2E19 à la place de "∎" U+220E, qui est en composition. compose-3.yml [4d31de6](https://github.com/dispoclavier/nouvel-azerty/commit/4d31de65dd1cb263f10b6eb65a9d7f43d0b434ca), compose-1.yml [98c1039](https://github.com/dispoclavier/nouvel-azerty/commit/98c103904a989a6a58dd5fa50aabd7f3399c3dd8)
		* Groupe 11 de ":" : Mettre "⁝" U+205D à la place de "⁚" U+205A, qui est dans point souscrit. compose-3.yml [4d31de6](https://github.com/dispoclavier/nouvel-azerty/commit/4d31de65dd1cb263f10b6eb65a9d7f43d0b434ca)
		* Ajouter l’étiquette « math ». compose-3.yml [7e943f5](https://github.com/dispoclavier/nouvel-azerty/commit/7e943f55e1d8fdeb76ece7275469944cdd16d3b7)
	* Exposant :
		* Ajouter "˸" U+02F8, qui était dans tréma souscrit. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Ajouter "ꜝ" U+A71D. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Exposant et groupe 1 : Ajouter "𐞁" U+10781, "𐞂" U+10782. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Exposant > Suscrit et groupe 1 :
		* Ajouter "ᫌ" U+1ACC, "ᫍ" U+1ACD, "ᫎ" U+1ACE. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
		* Supprimer "ᷣ" U+1DE3, qui va dans le groupe 2. ibidem
	* Exposant > Suscrit et groupe 2 : Ajouter pour "ᷣ" U+1DE3. ibidem
	* Exposant > Suscrit et groupe 12 : Ajouter "ᫌ" U+1ACC, "ᫍ" U+1ACD, "ᫎ" U+1ACE. ibidem
	* Double accent aigu : Adapter les séquences de "̎" U+030E. compose-2.yml [5fee200](https://github.com/dispoclavier/nouvel-azerty/commit/5fee20031626452970da5f23e1fc52e624abc4b9)
	* Double accent aigu > Triple accent aigu : Ajouter pour  "᫋" U+1ACB. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Tilde :
		* Ajouter "˔" U+02D4, "˕" U+02D5, "꭪" U+AB6A, "꭫" U+AB6B. compose-2.yml [67b2c87](https://github.com/dispoclavier/nouvel-azerty/commit/67b2c87366708c633f0f740b721d79c84e0469d1)
		* Ajouter "͠" U+0360 à la place de "”" U+201D, qui est dans accent aigu. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Compléter les séquences de "⁓" U+2053. ibidem
		* Redonder "͌" U+034C à la place de "≃" U+2243, qui est en composition et va dans le groupe 1 de "~" (et y était dans le groupe 2). compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
		* Supprimer "̰" U+0330, qui est dans tilde médian. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Supprimer "̴" U+0334, qui va dans tilde médian. ibidem
	* Tilde et tourné : Ajouter pour "̾" U+033E, "ⸯ" U+2E2F. ibidem
	* Tilde et barré : Ajouter pour "͊" U+034A. ibidem
	* Tilde et tréma : Ajouter "͋" U+034B. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Tilde > Tilde médian :
		* Rajouter "̴" U+0334. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
		* Ajouter "᷽" U+1DFD à la place de "≈" U+2248, qui est en composition et va dans le groupe 2 de "~". compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Grec ou cerclé et indice : Ajouter "ᴦ" U+1D26, "ᴧ" U+1D27, "ᴨ" U+1D28, "ᴩ" U+1D29, "ᴪ" U+1D2A, "ᵦ" U+1D66, "ᵧ" U+1D67, "ᵨ" U+1D68, "ᵩ" U+1D69, "ᵪ" U+1D6A. ibidem
	* Point en chef : Ajouter "͒" U+0352, "͘" U+0358, "᪴" U+1AB4, "᷸" U+1DF8, "᷺" U+1DFA. compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
	* Point en chef et accent aigu : Ajouter "᷁" U+1DC1. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Point en chef et accent grave : Ajouter "᷀" U+1DC0. ibidem
	* Brève : Corriger les séquences de "͝" U+035D. ibidem
	* Brève et macron : Ajouter pour "᷋" U+1DCB. ibidem
	* Brève et point en chef : Ajouter pour "̐" U+0310. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Brève > Brève souscrite : Corriger les séquences de "͜" U+035C (compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d))
	* Ogonek > Ogonek en chef : Ajouter pour "᷎" U+1DCE. ibidem
	* Indice : Ajouter "ᴦ" U+1D26, "ᴧ" U+1D27, "ᴨ" U+1D28, "ᴩ" U+1D29, "ᴪ" U+1D2A, "ᵦ" U+1D66, "ᵧ" U+1D67, "ᵨ" U+1D68, "ᵩ" U+1D69, "ᵪ" U+1D6A. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Indice et groupe 6 : Ajouter pour "ᴦ" U+1D26, "ᴧ" U+1D27, "ᴨ" U+1D28, "ᴩ" U+1D29, "ᴪ" U+1D2A, "ᵦ" U+1D66, "ᵧ" U+1D67, "ᵨ" U+1D68, "ᵩ" U+1D69, "ᵪ" U+1D6A. ibidem
	* Indice > Souscrit :
		* Ajouter "ᪿ" U+1ABF à la place de "̫" U+032B, qui est dans le groupe 12 de m. compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
		* Ajouter "᪵" U+1AB5. compose-2.yml [c050474](https://github.com/dispoclavier/nouvel-azerty/commit/c050474fd0b841ff9f71ad315cce4594230ccbdf)
	* Indice > Souscrit et tourné : Ajouter pour "ᫀ" U+1AC0. ibidem
	* Macron : Ajouter "͞" U+035E, "︦" U+FE26. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Macron et brève : Ajouter pour "᷌" U+1DCC. ibidem
	* Macron > Macron souscrit : Ajouter "͟" U+035F, "︭" U+FE2D. ibidem
	* Barré et tilde : Supprimer avec "≄" U+2244. compose-2.yml [5fee200](https://github.com/dispoclavier/nouvel-azerty/commit/5fee20031626452970da5f23e1fc52e624abc4b9)
	* Barré et tilde médian : Supprimer avec "≉" U+2249. ibidem
	* Rond en chef > Rond souscrit : Redonder "͚" U+035A. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Accent circonflexe :
		* Ajouter "᪰" U+1AB0 à la place de "•" U+2022, qui est dans le groupe 2 de "_". ibidem
		* Ajouter "᷍" U+1DCD à la place de "◦" U+25E6, qui est dans le groupe 3 de "_". ibidem
	* Drapeau : Ajouter "͇" U+0347 à la place de "⚐" U+2690, qui prend la place de "⚑" U+2691 par l’espace fine insécable. ibidem
	* Point souscrit : Ajouter "⃨" U+20E8 à la place de "⁝" U+205D, qui va dans le groupe 11 de ":". compose-2.yml [adebfe4](https://github.com/dispoclavier/nouvel-azerty/commit/adebfe4b6b60fc71b4c3e96da2d419a4dc2e2e96)
	* Tréma et rond en chef : Ajouter pour "᪱" U+1AB1. compose-2.yml [34dac7f](https://github.com/dispoclavier/nouvel-azerty/commit/34dac7f4edca177b1629186c8092adca575ffd1d)
	* Tréma > Tréma souscrit : Redonder "‥" U+2025 à la place de "˸" U+02F8, qui va dans exposant. ibidem
* Documentation :
	* Mettre à jour le nom anglais de l’espace fine insécable U+202F. compose-1.yml [386fa78](https://github.com/dispoclavier/nouvel-azerty/commit/386fa78123de7ef4a18af4a55603a43e1af3bce9), [9241b1a](https://github.com/dispoclavier/nouvel-azerty/commit/9241b1a2e3553150261c7fdb6031416a801af3e4), [1462c6a](https://github.com/dispoclavier/nouvel-azerty/commit/1462c6a62467e5ff96069499b6b9b40e1f7ebf4c), compose-2.yml [7d92df0](https://github.com/dispoclavier/nouvel-azerty/commit/7d92df027cb5b73ef4794480c4f8a2eb5c68a359)
	* Corriger l’abréviation de l’espace fine U+2009 et autres. ibidem, compose-3.yml [fce1ab7](https://github.com/dispoclavier/nouvel-azerty/commit/fce1ab7fdc020921f9558010170516dbdae27710)
	* Mettre à jour les commentaires. compose-1.yml [6c30d09](https://github.com/dispoclavier/nouvel-azerty/commit/6c30d09f968239d96b81d904070d01b2fcdc45a6), compose-2.yml [79578fa](https://github.com/dispoclavier/nouvel-azerty/commit/79578fa0ad3fc9300e5379f08472c54a55520d4f), compose-3.yml [7e943f5](https://github.com/dispoclavier/nouvel-azerty/commit/7e943f55e1d8fdeb76ece7275469944cdd16d3b7)
	* Corriger le mode d’emploi. linux-chromeos/readme.md [7e9a5ab](https://github.com/dispoclavier/nouvel-azerty/commit/7e9a5abc88c3378946db1732998e926f227f9a3c), [4a08530](https://github.com/dispoclavier/nouvel-azerty/commit/4a08530899d595c3c9402cdd94ac6cd31a4ea8c0), [da0daaf](https://github.com/dispoclavier/nouvel-azerty/commit/da0daaf7873c444db994d52ac07e4fb7b812a84e)
	* Orthographe. compose-1.yml [3746f5e](https://github.com/dispoclavier/nouvel-azerty/commit/3746f5e053db16f0e93514714b88ae1bd01226b4), compose-2.yml [67b2c87](https://github.com/dispoclavier/nouvel-azerty/commit/67b2c87366708c633f0f740b721d79c84e0469d1), compose-3.yml [92a0ade](https://github.com/dispoclavier/nouvel-azerty/commit/92a0ade87078b18982e09104b8e625b2a6e64aee)

## 4.0.0 (2024-08-11)

Permutation des ponctuations espacées et non espacées sur AltFr et Maj.

* Disposition :
	* Mettre les ponctuations espacées à la place des ponctuations non espacées en Maj, qui prennent les places en AltFr laissées par les ponctuations espacées. dispocla.cpp [ba9f321](https://github.com/dispoclavier/nouvel-azerty/commit/ba9f321504bc8042429bf931eb6f47d403d7fe13), dispotypes [e41b05b](https://github.com/dispoclavier/nouvel-azerty/commit/e41b05b03fa268244027b9a8ca2caba8035889e2)
	* Redonder l’opérateur point "⋅" U+22C5 sur AltGr + AltFr + X à la place du liant U+200D, qui prend la place de l’antiliant U+200C sur AltGr + AltFr + W, qui prend la place du ":" sur AltGr + AltFr + Q, qui est sur AltFr + la touche du deux-points.
* Documentation :
	* Mettre à jour le mode d’emploi. linux-chromeos/readme.md [3ab3d33](https://github.com/dispoclavier/nouvel-azerty/commit/3ab3d3331d0a3196936feb33a66bcba6e22cd8ff)
	* Mettre à jour le code source. compose-1.yml [0e1aedf](https://github.com/dispoclavier/nouvel-azerty/commit/0e1aedfb0b6646f672fa511567adf3141b071532), compose-2.yml [eaf2807](https://github.com/dispoclavier/nouvel-azerty/commit/eaf2807c711908fa26273a72ee573fc2c3c88f24)

## 3.5.1 (2024-08-10)

Prise en charge des barres de ton manquantes.

* Composition :
	* Ajouter les barres de ton additionnelles "꜈" U+A708, "꜉" U+A709, "꜊" U+A70A, "꜋" U+A70B, "꜌" U+A70C, "꜍" U+A70D, "꜎" U+A70E, "꜏" U+A70F, "꜐" U+A710, "꜑" U+A711, "꜒" U+A712, "꜓" U+A713, "꜔" U+A714, "꜕" U+A715, "꜖" U+A716. compose-1.yml [d8d4de5](https://github.com/dispoclavier/nouvel-azerty/commit/d8d4de52fb8ad1448957d5b7c022eae17bc5291e)
	* Adapter la séquence de "⁨" U+2068. ibidem
* Documentation. linux-chromeos/readme.md [8d712f9](https://github.com/dispoclavier/nouvel-azerty/commit/8d712f9d7129d5c46e4d1ca31ae65a7ba7360a83), compose-2.yml [e19e126](https://github.com/dispoclavier/nouvel-azerty/commit/e19e126dbfd8556c815c431353a5494e0c12633b), compose-3.yml [02651af](https://github.com/dispoclavier/nouvel-azerty/commit/02651afcc59bd886f0d4d8b2464b7ed57ca17948), dispocla.cpp [f281e69](https://github.com/dispoclavier/nouvel-azerty/commit/f281e69890dad1ae7bee4d234cf91cead365f0b8), [1b293ba](https://github.com/dispoclavier/nouvel-azerty/commit/1b293ba200c30f1dc02010e04c30a02be76d2588), [69e64f5](https://github.com/dispoclavier/nouvel-azerty/commit/69e64f587b8a88f6097af357d062ddbe6ba17108)

## 3.5.0 (2024-08-08)

* Composition :
	* Redonder "⁌" U+204C, "⁍" U+204D. compose-1.yml [9b7b785](https://github.com/dispoclavier/nouvel-azerty/commit/9b7b785d697158546d5edd532688941c0e359da8), [817b5d8](https://github.com/dispoclavier/nouvel-azerty/commit/817b5d8439cbd175ddaf714a14bc9884fd8e7b49)
	* Compléter les séquences de "∎" U+220E, "◂" U+25C2, "‣" U+2023, "●" U+25CF, "▬" U+25AC, "◦" U+25E6, "▫" U+25AB, "▮" U+25AE, "▭" U+25AD, "▵" U+25B5, "▿" U+25BF, "☆" U+2606, "•" U+2022, "▪" U+25AA, "▴" U+25B4, "▾" U+25BE. ibidem
	* Corriger les séquences de "☚" U+261A, "☛" U+261B. ibidem
	* Ajouter "👈" U+1F448, "👉" U+1F449. compose-1.yml [817b5d8](https://github.com/dispoclavier/nouvel-azerty/commit/817b5d8439cbd175ddaf714a14bc9884fd8e7b49)
* Transformations :
	* Groupes des symboles : (compose-3.yml [80afd99](https://github.com/dispoclavier/nouvel-azerty/commit/80afd99bc85cc719bf6b935c863533feb1921347))
		* Ajouter "⸿" U+2E3F à la place de "⁖" U+2056, qui prend la place de "⚐" U+2690, qui prend la place de "⁌" U+204C, qui va en composition avec les autres puces spécialisées, où elle est suivie par "⁍" U+204D. compose-3.yml [80d680b](https://github.com/dispoclavier/nouvel-azerty/commit/80d680bfcfb87809e6466ab6f5eb2857ecc5964d)
		* Redonder "⁘" U+2058 à l’ancienne place de "⁍" U+204D. ibidem
		* Permuter "⌘" U+2318 et "∎" U+220E. ibidem
		* Arrêter la prise en charge des diacritiques phototypes "🏻" U+1F3FB, "🏼" U+1F3FC, "🏽" U+1F3FD, "🏾" U+1F3FE, "🏿" U+1F3FF, inappropriée sur une disposition de clavier sans prise en charge extensive des émojis. compose-3.yml [7f517cc](https://github.com/dispoclavier/nouvel-azerty/commit/7f517cc69e6ef3d04350148c0e103fe5abec98f3)
		* Redonder "☚" U+261A à la place de "⸿" U+2E3F, qui prend la place laissée par "🏿" U+1F3FF. ibidem
		* Redonder "☛" U+261B à la place de "►" U+25BA, qui prend la place de "✀" U+2700, qui prend la place de "✂" U+2702, qui prend la place de "∐" U+2210, qui prend la place de "¶" U+00B6, qui prend la place de "℗" U+2117, qui est en composition. ibidem
		* Permuter "○" U+25CB et "●" U+25CF, "▢" U+25A2 et "⯀" U+2BC0. ibidem
		* Ajouter "⛯" U+26EF à la place de "⚯" U+26AF, qui prend la place de "⚮" U+26AE, qui prend la place de "∝" U+221D, qui prend la place laissée par "🏽" U+1F3FD. ibidem
		* Mettre "⤴" U+2934 à la place laissée par "🏼" U+1F3FC. ibidem
		* Mettre "⤵" U+2935 à la place laissée par "🏾" U+1F3FE. ibidem
		* Redonder "⁚" U+205A à la place laissée par "⤴" U+2934. ibidem
		* Redonder l’antiliant "‌" U+200C pour la mnémonique graphique à la place laissée par "🏻" U+1F3FB. ibidem
		* Redonder "⟰" U+27F0 à la place laissée par "⤵" U+2935. ibidem
	* Réfléchi :
		* Ajouter "⌐" U+2310. compose-2.yml [1422800](https://github.com/dispoclavier/nouvel-azerty/commit/14228002156f979d83c02316b08580df7c3966b6)
		* Compléter les séquences de "⁋" U+204B. ibidem
		* Redonder "⁌" U+204C, "⁍" U+204D. ibidem
	* Réfléchi et groupe 1 : Redonder "Ƹ" U+01B8, "ƹ" U+01B9. ibidem
	* Grec ou cerclé : Adapter les séquences de "⊗" U+2297. ibidem
	* Grec ou cerclé inversé :
		* Utiliser réfléchi au lieu de tourné. ibidem
		* Ajouter "🅐" U+1F150.."🅩" U+1F169, "🅰" U+1F170.."🆉" U+1F189. ibidem
	* Grec ou cerclé et tilde : Ajouter comme touche morte carré avec "🄰" U+1F130.."🅉" U+1F149. ibidem

## 3.4.3 (2024-07-31)

Prise en charge de lettres manquantes.

* Transformations :
	* Exposant et tourné : Ajouter "ꭩ" U+AB69. compose-2.yml [6962d96](https://github.com/dispoclavier/nouvel-azerty/commit/6962d966f780f4d8109fa431e68e69b8efb65ed8)
	* Tourné et tilde : Ajouter "ꭨ" U+AB68. ibidem
	* Grec et indice : Ajouter "ꭥ" U+AB65. ibidem
	* Tourné : Supprimer "ⸯ" U+2E2F. compose-2.yml [57cc11e](https://github.com/dispoclavier/nouvel-azerty/commit/57cc11eb43515cb98c12c6ac2f7a6657032c85bc)
	* Grec ou cerclé : Supprimer "⊝" U+229D par "_". ibidem

## 3.4.2 (2024-07-31)

Rajout d’un symbole mathématique perdu dans la version 1.7.3.

Prise en charge de lettres manquantes.

* Composition :
	* Restaurer "⋊" U+22CA, perdu dans la version 1.7.3. compose-1.yml [181f80f](https://github.com/dispoclavier/nouvel-azerty/commit/181f80f696d182232b23792169a111cbc6fe45a2)
	* Mettre "Ƣ" U+01A2, "ƣ" U+01A3 à la place de "Ȝ" U+021C, "ȝ" U+021D, qui est dans le groupe 2. ibidem
	* Ajouter "ꝰ" U+A770. ibidem
* Transformations :
	* Exposant et groupe 1 : Ajouter "ꟹ" U+A7F9. compose-2.yml [ac18a8c](https://github.com/dispoclavier/nouvel-azerty/commit/ac18a8c59b721a2e105bd62c218a36f7a992f25f)
	* Exposant et rayé : Ajouter "ꟸ" U+A7F8. ibidem
	* Réfléchi : Ajouter "Ꟶ" U+A7F5, "ꟶ" U+A7F6. ibidem
	* Rayé, double raie : Ajouter "Ꟈ" U+A7C7, "ꟈ" U+A7C8, "Ꟊ" U+A7C9, "ꟊ" U+A7CA. ibidem
	* Groupes des lettres :
		* Groupe 4 :
			* Ajouter "Ꟗ" U+A7D6 à la place de "℈" U+2108, qui est en composition. compose-3.yml [9633960](https://github.com/dispoclavier/nouvel-azerty/commit/96339608a6cf13d6900e72770a237d5c61d20465)
			* Ajouter "ꟗ" U+A7D7 à la place de "ʆ" U+0286, qui est en bouclé. ibidem
		* Groupe 5 : Ajouter "Ꟁ" U+A7C0, "ꟁ" U+A7C1 à la place de "ʘ" U+0298 par "O", qui est dans le groupe 5 par "B". ibidem
		* Groupe 11 :
			* Ajouter "Ꟑ" U+A7D0, "ꟑ" U+A7D1 à la place de "Ƣ" U+01A2, "ƣ" U+01A3, qui va en composition. ibidem
			* Ajouter "Ꟙ" U+A7D8, "ꟙ" U+A7D9 à la place de "Ƨ" U+01A7, "ƨ" U+01A8, qui est en composition. ibidem
			* Ajouter "ꟓ" U+A7D3 et "ꟕ" U+A7D5. ibidem

## 3.4.1 (2024-07-30)

Prise en charge du symbole som pour le Kirghizistan.

Débogages.

* Composition :
	* Mettre à jour le symbole monétaire par code ISO "Лв" U+041B U+0432 Som KYRGYZSTAN vers "⃀" U+20C0 SOM SIGN. compose-1.yml [9ea34e0](https://github.com/dispoclavier/nouvel-azerty/commit/9ea34e023b55c39301a7bb5bdd808fb065e2346b)
	* Corriger les séquences de "⟎" U+27CE pour déboguer "ą" U+0105. ibidem
	* Corriger les séquences de "⩗" U+2A57 pour déboguer "℣" U+2123. ibidem
	* Supprimer des doublons pour "⋀" U+22C0. ibidem
* Transformations : Indice et réfléchi : Corriger les séquences de "ᴙ" U+1D19 pour déboguer "ᴎ" U+1D0E et "ᴙ" U+1D19. compose-2.yml [9b4a4c0](https://github.com/dispoclavier/nouvel-azerty/commit/9b4a4c0efdc8000b8abb604fcf7368013b255261)

## 3.4.0 (2024-07-30)

Prise en charge du symbole som pour le Kirghizistan.

Remise à plat de nombreuses séquences de composition de symboles mathématiques.

Poursuite de l’amélioration de la prise en charge de l’écriture latine.

* Composition :
	* Corriger les séquences de "⁡" U+2061, "⁢" U+2062, "⁣" U+2063, "⁤" U+2064, "∇" U+2207, "∋" U+220B, "∌" U+220C, "∍" U+220D, "∐" U+2210, "∧" U+2227, "⊃" U+2283, "⊅" U+2285, "⊇" U+2287, "⊉" U+2289, "⊋" U+228B, "⊐" U+2290, "⊒" U+2292, "⊥" U+22A5, "⋀" U+22C0, "⋄" U+22C4, "⋏" U+22CF, "⋑" U+22D1, "⋣" U+22E3, "⋥" U+22E5, "⋺" U+22FA, "⋻" U+22FB, "⋼" U+22FC, "⋽" U+22FD, "⋾" U+22FE, "⟎" U+27CE, "⟏" U+27CF, "⟑" U+27D1, "⧘" U+29D8, "⧙" U+29D9, "⧚" U+29DA, "⧛" U+29DB, "⨇" U+2A07, "⨯" U+2A2F, "⨿" U+2A3F, "⩕" U+2A55, "⩗" U+2A57, "⩘" U+2A58, "⩙" U+2A59, "⩚" U+2A5A, "⩜" U+2A5C, "⩞" U+2A5E, "⩟" U+2A5F, "⩠" U+2A60, "⪃" U+2A83, "⪄" U+2A84, "⪾" U+2ABE, "⫀" U+2AC0, "⫂" U+2AC2, "⫄" U+2AC4, "⫆" U+2AC6, "⫈" U+2AC8, "⫊" U+2ACA, "⫌" U+2ACC, "⫐" U+2AD0, "⫑" U+2AD1, "⫒" U+2AD2, "⫓" U+2AD3, "⫖" U+2AD6, "⫘" U+2AD8, "⫪" U+2AEA, "⫫" U+2AEB, "⫾" U+2AFE. compose-1.yml [97ca5cb](https://github.com/dispoclavier/nouvel-azerty/commit/97ca5cb715405f1b28ce988c050921c7105dd1b3)
	* Ajouter "⁐" U+2050. ibidem
	* Redonder "⧠" U+29E0 et adapter les séquences de "❒" U+2752, "❑" U+2751, "❐" U+2750, "❏" U+274F. ibidem
* Transformations :
	* Groupes des symboles :
		* Ajouter "‸" U+2038 à la place de "✈" U+2708, qui prend la place de "∡" U+2221, qui est en composition. compose-3.yml [137dc95](https://github.com/dispoclavier/nouvel-azerty/commit/137dc958d8624d619e2d687ad6aebf65dc17ad46)
		* Ajouter "⁃" U+2043 à la place de "⹀" U+2E40, qui est dans plusieurs touches mortes et en composition. ibidem
		* Ajouter "⁖" U+2056 à la place de "‏" U+200F, qui est en composition. ibidem
		* Redonder "✀" U+2700 à la place de "►" U+25BA, qui prend la place de "‎" U+200E, qui est en composition. ibidem
	* Tilde : Ajouter "⁓" U+2053. compose-2.yml [b4470e1](https://github.com/dispoclavier/nouvel-azerty/commit/b4470e18c39451256e6020b3d51f18506905822d)
	* Symbole monétaire : Ajouter "⃀" U+20C0 à la place de "$", qui est sur touche vive. ibidem
	* Brève inversée : Redonder "⁐" U+2050. ibidem
	* Indice : Ajouter "ₜ" U+209C. ibidem
	* Accent circonflexe > Accent circonflexe souscrit : Redonder "‸" U+2038 à la place de "ꞈ" U+A788, qui est avec le caractère de base espace fine insécable. ibidem

## 3.3.0 (2024-07-26)

Amélioration de la prise en charge de l’écriture latine.

* Composition :
	* Paléographie médiévale :
		* Ajouter "ᷓ" U+1DD3, "ᷔ" U+1DD4, "ᷕ" U+1DD5, "ᷖ" U+1DD6. compose-1.yml [17d8731](https://github.com/dispoclavier/nouvel-azerty/commit/17d8731adc64bb15ea3b6aa8bb66e88ceab9c451)
		* Redonder "᷏" U+1DCF, "᷐" U+1DD0, "᷑" U+1DD1, "᷒" U+1DD2. ibidem
	* Chiffres romains non décomposables :
		* Ajouter "ↀ" U+2180, "ↂ" U+2182, "ↈ" U+2188, "ↁ" U+2181, "ↇ" U+2187, "ↅ" U+2185, "ↆ" U+2186. ibidem
	* Symboles de touches modificatrices :
		* Mettre "⟰" U+27F0 à la place de "⬆" U+2B06. ibidem
		* Simplifier les séquences. ibidem
	* Symboles de touche de composition :
		* Prendre en charge "¦" U+00A6. ibidem
		* Corriger la séquence de "⎄" U+2384. ibidem
* Transformations :
	* Exposant et groupe 1 :
		* Ajouter "ˀ" U+02C0. compose-2.yml [32f4db9](https://github.com/dispoclavier/nouvel-azerty/commit/32f4db95799bdfb438dcb58efebb243c58e7745a)
		* Ajouter "ᵞ" U+1D5E en Majuscule. ibidem
		* Redonder "ᵠ" U+1D60. ibidem
	* Indice ou petite capitale et réfléchi :
		* Ajouter "ᴎ" U+1D0E, "ᴙ" U+1D19. ibidem
	* Réfléchi :
		* Redonder "ᴎ" U+1D0E, "ᴙ" U+1D19. ibidem
	* Exposant > Suscrit et groupe 1 :
		* Ajouter "ᷘ" U+1DD8, "ᷙ" U+1DD9, "ᷣ" U+1DE3, "ᷥ" U+1DE5, "ᷧ" U+1DE7, "ᷩ" U+1DE9, "ᷪ" U+1DEA, "ᷬ" U+1DEC, "ᷭ" U+1DED, "ᷯ" U+1DEF, "ᷰ" U+1DF0. ibidem
		* Redonder "ᷓ" U+1DD3. ibidem
	* Exposant > Suscrit et groupe 12 :
		* Redonder "ᷘ" U+1DD8. ibidem
	* Tourné : Redonder "ɟ" U+025F à la place de "ⅎ" U+214E, qui passe en double pression. Permuter "Ⅎ" U+2132 et "ꓞ" U+A4DE. ibidem
* Documentation :
	* Corriger. compose-1.yml [17d8731](https://github.com/dispoclavier/nouvel-azerty/commit/17d8731adc64bb15ea3b6aa8bb66e88ceab9c451), compose-2.yml [32f4db9](https://github.com/dispoclavier/nouvel-azerty/commit/32f4db95799bdfb438dcb58efebb243c58e7745a), compose-3.yml [6b97818](https://github.com/dispoclavier/nouvel-azerty/commit/6b97818f83578fca6bf66b88b527e2ca79ac2745)
	* Déboguer linux-chromeos/readme.md. [31e6af7](https://github.com/dispoclavier/nouvel-azerty/commit/31e6af71d04aed655f64cfbbab1a8b7f7e5038ce)

## 3.2.2 (2024-07-25)

Débogage des fichiers servant à activer une disposition de clavier par xkbcomp.

* Activation : Déboguer les sources de disposition fusionnées en réactivant deux types de touches non utilisés et désactivés dans les distributions Linux de 2016. dispocla.cpp [6e6da51](https://github.com/dispoclavier/nouvel-azerty/commit/6e6da518aef27fac611ba90b6873328bf40d75c8), comp.sh [c0eecf0](https://github.com/dispoclavier/nouvel-azerty/commit/c0eecf0f0d8ca357b63c989d0ff3cd50daafa2e8)
* Documentation :
	* Point du pavé numérique : Corriger la référence du modèle cité, `kpdl(kposs)`, non `kpdl(dotoss)`. dispocla.cpp [3175e51](https://github.com/dispoclavier/nouvel-azerty/commit/3175e51073dfba773b12996fcc648dc55ba4558e)
	* Bogues des systèmes d’exploitation :
		* Documenter le recours à xkbcomp sous Linux Mint. comp.sh [bb82c93](https://github.com/dispoclavier/nouvel-azerty/commit/bb82c935ab22b17fa4eb235a5eab60cf203bc1f0), [5a71641](https://github.com/dispoclavier/nouvel-azerty/commit/5a71641554775d50bbb0d8cac15de0509444a7b2), Lisez-moi-svp.txt [258e86a](https://github.com/dispoclavier/nouvel-azerty/commit/258e86a720a3cbc9a6220d7bc3b60894fc9c26b2), [ed1664c](https://github.com/dispoclavier/nouvel-azerty/commit/ed1664c953631bfe3e0de94d11352d3b29a292cb), linux-chromeos/readme.md [8d4e19e](https://github.com/dispoclavier/nouvel-azerty/commit/8d4e19ea219b1ec9cd9646a6cbb3594a2507e371), [67d85af](https://github.com/dispoclavier/nouvel-azerty/commit/67d85afeaacf5cd8103d10fa15a7de38b84d84fd)
		* Préciser les bogues sous Linux Mint et sous ChromeOS. linux-chromeos/readme.md [2d1fc45](https://github.com/dispoclavier/nouvel-azerty/commit/2d1fc451e3463368481ebd8ff81e8c3e58425f59)
		* Préciser le bogue sous ChromeOS. linux-chromeos/readme.md [d235040](https://github.com/dispoclavier/nouvel-azerty/commit/d2350409ea06cb0acf657333def517bf2d9a9dae)
	* Personnalisation : Attirer l’attention sur la possibilité. Lisez-moi-svp.txt [711ee78](https://github.com/dispoclavier/nouvel-azerty/commit/711ee782775e7883b166d827da61ae189f8a1e5d)

## 3.2.1 (2024-07-14)

Rectification du carré plein centré et de la marque de répétition.

* Composition : Supprimer "⯀" U+2BC0. compose-1.yml [d746dbb](https://github.com/dispoclavier/nouvel-azerty/commit/d746dbb2a07cb2273a413f8b16570ea0b2a1a4f3)
* Transformations : Groupes des symboles : Rajouter "⯀" U+2BC0 dans le groupe 6 à la place de "〃" U+3003, qui est dans le groupe 12. compose-3.yml [7629ef3](https://github.com/dispoclavier/nouvel-azerty/commit/7629ef3b3a9039aa0f0fc49b92d7d73db0103da4)

## 3.2.0 (2024-07-09)

Meilleure prise en charge des émojis.

* Disposition : Permuter "😭" U+1F62D et "😱" U+1F631 pour la mnémonique. dispocla.cpp [35f423f](https://github.com/dispoclavier/nouvel-azerty/commit/35f423f998a9af26189352f6d4eb8ed5bb376860)
* Composition : Ajouter "⯀" U+2BC0 au nombre des puces. compose-1.yml [d9f67b1](https://github.com/dispoclavier/nouvel-azerty/commit/d9f67b10ebbf30578fa3df535076dc3410961392)
* Transformations : Groupes des symboles :
	* Redonder "▪" U+25AA dans le groupe 5 de "#" à la place de "☐" U+2610, qui est dans le groupe 1 et en composition. compose-3.yml [1218076](https://github.com/dispoclavier/nouvel-azerty/commit/121807642941fe311b5e4455c4217e101c756517)
	* Redonder "◾" U+25FE dans le groupe 6 de "#" à la place de "☑" U+2611, qui est dans le groupe 2 et en composition. ibidem
	* Redonder "◼" U+25FC dans le groupe 7 de "#" à la place de "☒" U+2612, qui est dans le groupe 3 et en composition. ibidem
	* Redonder "⬛" U+2B1B dans le groupe 8 de "#" à la place de "⯀" U+2BC0, qui est en composition. ibidem
	* Redonder "▫" U+25AB dans le groupe 5 de "/" à la place de "⛆" U+26C6, qui prend la place de "〰" U+3030, qui prend la place de "⊤" U+22A4, qui est en composition. ibidem
	* Redonder "◽" U+25FD dans le groupe 6 de "/" à la place de "⊢" U+22A2, qui est en composition. ibidem
	* Redonder "◻" U+25FB dans le groupe 7 de "/" à la place de "⊣" U+22A3, qui est en composition. ibidem
	* Redonder "⬜" U+2B1C dans le groupe 8 de "/" à la place de "⊥" U+22A5, qui est en composition. ibidem
* Documentation. linux-chromeos/readme.md [e96eda7](https://github.com/dispoclavier/nouvel-azerty/commit/e96eda7fac758277190d7e41251ed60a263c1969), dispocla.cpp [35f423f](https://github.com/dispoclavier/nouvel-azerty/commit/35f423f998a9af26189352f6d4eb8ed5bb376860), compose-2.yml [a119d4b](https://github.com/dispoclavier/nouvel-azerty/commit/a119d4b856f60bb01bcf44fb5c25a1c332e4cd18)

## 3.1.0 (2024-07-07)

Plusieurs caractères sont redisposés.

* Disposition :
	* Mettre le liant "‍" U+200D à la place de l’antiliant "‌" U+200C sur AltGr + AltFr + X, qui prend la place du deux-points sur AltGr + AltFr + W, qui prend la place de la barre de fraction "⁄" U+2044 sur (Maj puis) AltGr + AltFr + Q (depuis 1.0.9), qui prend la place du symbole micro "µ" U+00B5 sur AltGr + AltFr + F, qui est sur AltGr + AltFr + M. dispocla.cpp [157d828](https://github.com/dispoclavier/nouvel-azerty/commit/157d828f913b15f50666cc6d71e2124765c6390c)
	* Prendre en charge le gluon "⁠" U+2060 par touche vive sur AltGr + AltFr + G à la place du tiret demi-cadratin "–" U+2013, qui prend la place du tiret tabulaire "‒" U+2012 sur AltGr + AltFr + T, qui est dans le groupe 1 du signe moins "−" U+2212, et qui ne doit pas être sur touche vive. dispocla.cpp [2b0786b](https://github.com/dispoclavier/nouvel-azerty/commit/2b0786bff734f6ea883a67e542373a2bbdd36a27)
* Installation : Ajouter des messages affichés pendant le diagnostic. installer.sh [38cd80b](https://github.com/dispoclavier/nouvel-azerty/commit/38cd80b1ce9b9931f57fb1e5f81901c037f2abd3)
* Mode d’emploi :
	* Mettre à jour. linux-chromeos/readme.md [ecb2560](https://github.com/dispoclavier/nouvel-azerty/commit/ecb256088c841239f345fb9ed78bed970bf1ef4f)
	* Améliorer. linux-chromeos/readme.md [0d21efa](https://github.com/dispoclavier/nouvel-azerty/commit/0d21efa6e4f9a53804b8c59bb1a391839a8a5617)
	* Compléter. linux-chromeos/readme.md [b2012f1](https://github.com/dispoclavier/nouvel-azerty/commit/b2012f16d4946f2053e1288e1fa87fbcbe6c9fd9)
* Documentation :
	* Corriger, compléter. compose-1.yml [8bd49b1](https://github.com/dispoclavier/nouvel-azerty/commit/8bd49b1d5bbd93e01e8622c8621274b8472a35b9), compose-2.yml [22b8333](https://github.com/dispoclavier/nouvel-azerty/commit/22b83333eb44737f444e5abc7b603e4beaae18b5), compose-3.yml [9a3cb00](https://github.com/dispoclavier/nouvel-azerty/commit/9a3cb0042658aaa48f7b8d0a55b452a73272e418)
	* Ajouter et mettre à jour des infobulles. generate-deadkey-tables.pl [998c71d](https://github.com/dispoclavier/nouvel-azerty/commit/998c71db225a5bf180a1fd2fcc85b71726d18cab), generate-multikey-tables.pl [c3af782](https://github.com/dispoclavier/nouvel-azerty/commit/c3af782d1cc9143b8ad2aa98d5103827e57cb377), generate-math-table.pl [6a4d1c9](https://github.com/dispoclavier/nouvel-azerty/commit/6a4d1c9b3ac6ff4e6583b9f4bca86500c10402e0)

## 3.0.0 (2024-07-04)

Les exposants changent de niveau, d’AltGr + AltFr à Maj + AltFr, afin que la majuscule de l’abréviation Numéro (avec le o en exposant) puisse être saisie en ajoutant Maj, non en ajoutant AltGr, sur Maj + AltGr + AltFr + N, et afin que le trigramme breton (avec la lettre apostrophe) bénéficie de la même logique sur A, ainsi que pour faciliter la saisie des minuscules en exposant (comme indicateurs d’abréviation, indicateurs ordinaux), en Maj + AltFr, non en AltGr + AltFr. Permutation des niveaux 6 et 7 sur la plupart des touches.

* Permuter les niveaux 6 et 7. dispocla.cpp [eda4dd1](https://github.com/dispoclavier/nouvel-azerty/commit/eda4dd14bcca8f876eccbb5e68e9fccadcf130ee), [c74e5a8](https://github.com/dispoclavier/nouvel-azerty/commit/c74e5a82814311b1716389dae0ab351c1e3b2068), [e3924aa](https://github.com/dispoclavier/nouvel-azerty/commit/e3924aae79e0ebc30a08b21da8cd2e6fc47c92ed), [17f0984](https://github.com/dispoclavier/nouvel-azerty/commit/17f0984949b62b5fcd9825e618e7341ce596d9f6), dispotypes.c [fc8683b](https://github.com/dispoclavier/nouvel-azerty/commit/fc8683be9e555c4d5b86a9a4d6e55ea79502153f), [accfc83](https://github.com/dispoclavier/nouvel-azerty/commit/accfc83f04a40d4deb8f2511f8fcd41a274ac9cc)
* Remettre "=" comme caractère en Contrôle plutôt que "+". dispotypes.c [accfc83](https://github.com/dispoclavier/nouvel-azerty/commit/accfc83f04a40d4deb8f2511f8fcd41a274ac9cc)
* Ajouter les options manquantes. dispocla.cpp [18f13bd](https://github.com/dispoclavier/nouvel-azerty/commit/18f13bd5e82596554c21bf8877926015dae7b5e1)
* Différencier les descripteurs du deuxième groupe de disposition. dispocla.cpp [0923f88](https://github.com/dispoclavier/nouvel-azerty/commit/0923f88245b0747d29ce96600621d1c1ff4795a6)
* Supprimer la prise en charge du digramme breton, non disposé. compose-1.yml [1d21d06](https://github.com/dispoclavier/nouvel-azerty/commit/1d21d0677c1b3e49a532111d83660bb646fed1b7)
* Rectifier et compléter la documentation. ibidem, compose-1.yml [1f3776e](https://github.com/dispoclavier/nouvel-azerty/commit/1f3776e536fbe430d3ecd064c237eb1a47dc4816), [06deaac](https://github.com/dispoclavier/nouvel-azerty/commit/06deaacdff00d8c9486bff786924751d60d6052f), dispocla.cpp [7cf2831](https://github.com/dispoclavier/nouvel-azerty/commit/7cf2831394f9e7df65484b630010abde0aa1c6ac), [6feb19d](https://github.com/dispoclavier/nouvel-azerty/commit/6feb19ddad97d4f6f34bfd77263e58dc1baa81ab)
* Mode d’emploi :
	* Mettre à jour. linux-chromeos/readme.md [b1e3cb9](https://github.com/dispoclavier/nouvel-azerty/commit/b1e3cb9fe1f399c03633553a350aea8d31baeead), [103add8](https://github.com/dispoclavier/nouvel-azerty/commit/103add83fb6129d1642bde54385fc696079ed1cb), [785c7ca](https://github.com/dispoclavier/nouvel-azerty/commit/785c7caa8220a52909d854ac4f2a8cf9dc27fff1)
	* Améliorer et compléter. linux-chromeos/readme.md [95bc470](https://github.com/dispoclavier/nouvel-azerty/commit/95bc47000498f18bced4126714b44e7b906fc436), [305b322](https://github.com/dispoclavier/nouvel-azerty/commit/305b322ef276e17f274dd2859f7b552707e29a4e), [d78e4c2](https://github.com/dispoclavier/nouvel-azerty/commit/d78e4c28f39183fca9f6724fab71f6945aca70e3), [0a0e506](https://github.com/dispoclavier/nouvel-azerty/commit/0a0e506b0e0c5207b10ef423eae84dad8f6be830)

## 2.3.7 (2024-06-30)

* Installation :
	* Corriger les conditions du script. installer.sh [d523755](https://github.com/dispoclavier/nouvel-azerty/commit/d5237552c515ba2441574ec7eff110e1507fb3f5)
	* Clarifier et compléter des messages du script. ibidem
	* Harmoniser les retraits de début de ligne des messages du script. ibidem
* Améliorer et compléter le mode d’emploi. linux-chromeos/readme.md [5aee580](https://github.com/dispoclavier/nouvel-azerty/commit/5aee5804715e314faf18409ba726e380a91a7fe1), [1dffe31](https://github.com/dispoclavier/nouvel-azerty/commit/1dffe3190810907c466282964baa0bd0ec60c5dc), [be7dc68](https://github.com/dispoclavier/nouvel-azerty/commit/be7dc6820c16f4594bd2b2e3f18d0c561544221f), [f609e19](https://github.com/dispoclavier/nouvel-azerty/commit/f609e19c15a6d73ae49fd988120a3b2cbd4e2862), [0e9742a](https://github.com/dispoclavier/nouvel-azerty/commit/0e9742afdf4737520ffd38a7c775b97e23a29945), [54ab01c](https://github.com/dispoclavier/nouvel-azerty/commit/54ab01c8c5c6fb7385cd8c7ddce33904aae1d1ba), [7cb6d32](https://github.com/dispoclavier/nouvel-azerty/commit/7cb6d32fc8e7755308a4c86fc9a218afb09da42d), [a5e76da](https://github.com/dispoclavier/nouvel-azerty/commit/a5e76da2847ca456b3066d75b92527e50b4bfa80), [81d6e16](https://github.com/dispoclavier/nouvel-azerty/commit/81d6e16b2f805a6dcb66666f986ab302760e7fde)
* Alerter sur Linux Mint. linux-chromeos/readme.md [428dd59](https://github.com/dispoclavier/nouvel-azerty/commit/428dd59d1be592abde77b0a6286453362040bfe3), [e10dfc1](https://github.com/dispoclavier/nouvel-azerty/commit/e10dfc1932d5f2ae9c1ce2a30f5490caa9fad3c0), [823bba6](https://github.com/dispoclavier/nouvel-azerty/commit/823bba6fe9ea1cb6029b4c1b25160a001c500d15), [a74b9d6](https://github.com/dispoclavier/nouvel-azerty/commit/a74b9d6e0ba35cfdb1789d90991dabb79ac1abda), [5b7b147](https://github.com/dispoclavier/nouvel-azerty/commit/5b7b1475dec9c3a1d9c538d72938dd059e85d9fd), [d360eef](https://github.com/dispoclavier/nouvel-azerty/commit/d360eeff4a662da20179efa3530d7abf9aea68a0), [388d38e](https://github.com/dispoclavier/nouvel-azerty/commit/388d38e87dbe1878fc9c8f5984cc5a2b8e36dcdf), [17347e7](https://github.com/dispoclavier/nouvel-azerty/commit/17347e7eca3bfc1dbf6ba99e7281d4fded8a5b56)
* Documentation. compose-3.yml [c7c3d72](https://github.com/dispoclavier/nouvel-azerty/commit/c7c3d723c188629501290f910220f6b13e15dc60)

## 2.3.6 (2024-06-23)

* Installation :
	* Corriger des messages du script. installer.sh [6630958](https://github.com/dispoclavier/nouvel-azerty/commit/6630958a206e5077693a12a1d4e78edf0d87885c)
	* Clarifier des messages du script. ibidem
	* Harmoniser les retraits de début de ligne des messages du script. ibidem et installer.sh [07a3f1c](https://github.com/dispoclavier/nouvel-azerty/commit/07a3f1c3883b6ad9cb747c62baf36dd333e5300d)
* Documentation. compose-1.yml [0fac783](https://github.com/dispoclavier/nouvel-azerty/commit/0fac7837f998d0ce20ca9da83ebc1c76a74a7d86), compose-2.yml [0c9738a](https://github.com/dispoclavier/nouvel-azerty/commit/0c9738aa8f835ec9cc90fa4c8b9636031f00ae51), compose-3.yml [b518c7e](https://github.com/dispoclavier/nouvel-azerty/commit/b518c7e650eeacc6a0990dafc7049e683f6f3065), [359c1e1](https://github.com/dispoclavier/nouvel-azerty/commit/359c1e174374664d22cc6b4a64f9f46ecbd3b59c)

## 2.3.5 (2024-06-19)

* Installation : Déboguer le script. installer.sh [22b0887](https://github.com/dispoclavier/nouvel-azerty/commit/22b08870a5fe325ab6eabd947a2220cddf07f3db)

## 2.3.4 (2024-06-19)

Cette version vient avec un script d’installation qui prend en charge aussi les redispositions des sous-variantes.

* Sous-variantes :
	* Prendre en charge aussi les agencements ANSI purs. evdev.c [d98b5de](https://github.com/dispoclavier/nouvel-azerty/commit/d98b5de4daa2c29fb690f2d175b41a6301996deb)
	* Restaurer les touches de fonction 19 et 24 (désactivées pour la version 1.1.1). ibidem
	* Fournir un fichier `evdev.c` redisposé pour chaque catégorie de sous-variantes.
* Installation :
	* Gérer les redispositions de touches des sous-variantes pendant l’installation. installer.sh [bc51116](https://github.com/dispoclavier/nouvel-azerty/commit/bc51116238f53b2be4f7f28b31ab950a59078dd6), [df8aac7](https://github.com/dispoclavier/nouvel-azerty/commit/df8aac7e8389ec85af0a13c035c9aa6852f7448d)
	* Déverrouiller les fichiers sauvegardés pendant la désinstallation. ibidem
	* Améliorer la robustesse du script. ibidem
	* Améliorer l’intelligibilité des messages du script. installer.sh [3a56c32](https://github.com/dispoclavier/nouvel-azerty/commit/3a56c32fe8e10b186e1c69156222c269901889be)
* Documentation. compose-1.yml [c44a9d8](https://github.com/dispoclavier/nouvel-azerty/commit/c44a9d86810711b6ac1c1be019ded28bb9132bfb)

## 2.3.3 (2024-06-16)

Cette version vient avec un script d’installation amélioré.

* Installation :
	* Sortir le script du sous-dossier `outils/`. installer.sh [b48cd4a](https://github.com/dispoclavier/nouvel-azerty/commit/b48cd4a59b3a56354b3dae710e5e134488a268da)
	* Améliorer l’expérience utilisateur. installer.sh [013dd59](https://github.com/dispoclavier/nouvel-azerty/commit/013dd59b15a467bd3c18a2a4e8fe861961ded582)
	* Documentation. compose-1.yml [bc45134](https://github.com/dispoclavier/nouvel-azerty/commit/bc45134f03e377b2cb6eb3849d3e32cc8971998d), readme.md [e9eccec](https://github.com/dispoclavier/nouvel-azerty/commit/e9eccec9195f8f5986bcc71c74fd1960b59b00c2), [fa1644e](https://github.com/dispoclavier/nouvel-azerty/commit/fa1644e84ceab8ad426c5899ac8b60e77e6c62a2), [369d48f](https://github.com/dispoclavier/nouvel-azerty/commit/369d48f7d106132f5f82f86e21bb905b327b50ff)

## 2.3.2 (2024-06-15)

* Installation : Fournir un script pour automatiser l’installation. installer.sh [4dc1b1b](https://github.com/dispoclavier/nouvel-azerty/commit/4dc1b1b3a0c1ab4d5ac3fd9735cb309cbc6793f6)
* Documentation. evdev-additions.xml [37d393b](https://github.com/dispoclavier/nouvel-azerty/commit/37d393bf5a171f1f8e3733431236de0615799ae8), compose-1.yml [0c06057](https://github.com/dispoclavier/nouvel-azerty/commit/0c060578cb1276f95ed4b5cc297d2ab37fdfeb28), [ea8660d](https://github.com/dispoclavier/nouvel-azerty/commit/ea8660d076fe28eb9e84309508520a434c4fa650), [a2f1a7f](https://github.com/dispoclavier/nouvel-azerty/commit/a2f1a7f00c88c54129fd3cbd98a6824770afc0e2), compose-3.yml [e92cfb9](https://github.com/dispoclavier/nouvel-azerty/commit/e92cfb960be614513c6c94ee3caa14f9440a979b), [78d5438](https://github.com/dispoclavier/nouvel-azerty/commit/78d5438a5dd122ebf2b6dda38d8a20cbadd03729)

## 2.3.1 (2024-06-12)

* Variantes redisposées : Disposition : Restaurer la touche morte accent grave, perdue dès la version 2.0.0. dispocla.cpp [3447c5d](https://github.com/dispoclavier/nouvel-azerty/commit/3447c5dd892925f994af6e36f249f137b0a57e5f)
* Documentation. dispocla.cpp [ff2ae89](https://github.com/dispoclavier/nouvel-azerty/commit/ff2ae89b787340d93e2956e1561ef18e5cdbaca9), [a765295](https://github.com/dispoclavier/nouvel-azerty/commit/a765295c5159be22d6a8c4084850542870b8a25e), [abad9ea](https://github.com/dispoclavier/nouvel-azerty/commit/abad9ea974e0f2e65584a9f6262e6c3ebd017740), [3447c5d](https://github.com/dispoclavier/nouvel-azerty/commit/3447c5dd892925f994af6e36f249f137b0a57e5f), compose-1.yml [479e3fa](https://github.com/dispoclavier/nouvel-azerty/commit/479e3fa96252ef1396c917695fff971cb4a9ab20), [7b1dc2b](https://github.com/dispoclavier/nouvel-azerty/commit/7b1dc2ba2994e69c0b36f3dc345d1bb99e3f76ff), compose-2.yml [ca21e7b](https://github.com/dispoclavier/nouvel-azerty/commit/ca21e7b84d88fbfe062d0d7e26f812a7476e9ed0), compose-3.yml [41fd139](https://github.com/dispoclavier/nouvel-azerty/commit/41fd139c247d8c45cc70c0a208acd76f1a672ec4)

## 2.3.0 (2024-06-08)

* Disposition du pavé numérique :
	* Chiffres :
		* Mode français :
			* Majuscule :
				* Touche 4 : Mettre le préfixe Unicode complet "U+" à la place de "U" U+0055. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d)
				* Touche 7 : Mettre la barre de fraction "⁄" U+2044 à la place de l’espace fine insécable " " U+202F. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), [4c9e353](https://github.com/dispoclavier/nouvel-azerty/commit/4c9e353764d19bad4ecb48f583b96b2e45bbfbe6)
			* Permuter les flèches simples et les flèches émojis ; permuter les flèches doubles et les flèches pleines. dispocla.cpp [e3bf0c6](https://github.com/dispoclavier/nouvel-azerty/commit/e3bf0c60e26641106c106c4acda1dde9d32a34a8), compose-2.yml [5545ce0](https://github.com/dispoclavier/nouvel-azerty/commit/5545ce01c3ad79853b4db27f13acf4063798068b)
		* Mode ASCII :
			* Mettre "000" à la place de "0x", "#" à la place de "\\u{", "\\" U+005C à la place de "\\x{". dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d)
			* Permuter les flèches émojis et les flèches à tête triangulaire ; permuter les flèches pleines et les flèches ajourées. dispocla.cpp [e3bf0c6](https://github.com/dispoclavier/nouvel-azerty/commit/e3bf0c60e26641106c106c4acda1dde9d32a34a8), compose-2.yml [5545ce0](https://github.com/dispoclavier/nouvel-azerty/commit/5545ce01c3ad79853b4db27f13acf4063798068b)
	* Opérateurs :
		* Plus :
			* Majuscule : Redonder ":" à la place de "+". dispocla.cpp [f3bdb52](https://github.com/dispoclavier/nouvel-azerty/commit/f3bdb52d165f418ad11315bf662ef4e80ef47e6d), [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), dispotypes.c [4eef10d](https://github.com/dispoclavier/nouvel-azerty/commit/4eef10d6fc4f76bfd98c8b8ba33d9e87958b21e1), [90d5a43](https://github.com/dispoclavier/nouvel-azerty/commit/90d5a43d2e09c83433c18160a9ec01a4ab11ce43)
			* Mode ASCII : Rajouter "0x". ibidem
		* Moins : Mode ASCII : Mettre "=" à la place de "#". Rajouter "\\x{". ibidem
		* Multiplier : Mode ASCII : Redonder "}". ibidem
		* Diviser : Mode ASCII : Mettre "\\u{" à la place de la barre de fraction "⁄" U+2044. ibidem
	* Point :
		* Mode ASCII : Mettre l’espace fine insécable " " U+202F à la place de l’espace " " U+0020. dispocla.cpp [317541d](https://github.com/dispoclavier/nouvel-azerty/commit/317541d16dab837be37bb1f0f434a2ab1dd43b0d), [4109119](https://github.com/dispoclavier/nouvel-azerty/commit/41091193b9bb027145bd41b1561164bdf4ba727f)
		* Rectifier le code et la documentation. dispocla.cpp [e1803c3](https://github.com/dispoclavier/nouvel-azerty/commit/e1803c3f3bb56cf01d6063087fc8f22eb09e715e), [959b970](https://github.com/dispoclavier/nouvel-azerty/commit/959b9707531e0768d77a8b29ddb39f169c065efe), [3f12966](https://github.com/dispoclavier/nouvel-azerty/commit/3f12966eb664f25c5f0d24cb6b253cd61eb339c6)
	* Déboguer la touche virgule des claviers brésiliens. dispocla.cpp [e1803c3](https://github.com/dispoclavier/nouvel-azerty/commit/e1803c3f3bb56cf01d6063087fc8f22eb09e715e)
	* Prendre en charge aussi la touche B11 des claviers brésiliens. dispocla.cpp [339fed4](https://github.com/dispoclavier/nouvel-azerty/commit/339fed4643ab4e4f44d01409793b78b1f9d18929), [8f5ebba](https://github.com/dispoclavier/nouvel-azerty/commit/8f5ebba8383c90b2986994bcdad4202c30eddf55)

## 2.2.1 (2024-06-03)

* Sortie multi-caractères : Déboguer "&#" et "&#x". compose-1.yml [456f97e](https://github.com/dispoclavier/nouvel-azerty/commit/456f97e489a250088bb181f72eb3c199a92e579a)

## 2.2.0 (2024-06-02)

* Disposition : Mode ASCII : Touches C11, C12, D11, D12 en Maj + AltGr/Option et en AltFr + AltGr/Option : Mettre "⁽" U+207D à la place de "%" ou de "A" U+0041, "⁾" U+207E à la place de "*" ou de "B" U+0042, "^" à la place de "C" U+0043, "⁼" U+207C à la place de "$" ou de "D" U+0044 ; en Maj + AltFr : Mettre "_" à la place de la touche morte tréma, "₌" U+208C à la place de "£" U+00A3, "₍" U+208D à la place de "%", "₎" U+208E à la place de "µ" U+00B5. dispocla.cpp [78281d0](https://github.com/dispoclavier/nouvel-azerty/commit/78281d0d195d5b5497eb7c86c632e1121e0fb048), [4fd1c54](https://github.com/dispoclavier/nouvel-azerty/commit/4fd1c54304db7fbf2cfaad628e7444d411a6681f), [bfd180c](https://github.com/dispoclavier/nouvel-azerty/commit/bfd180c48541a316185d747ba7cdece768088cfe)
* Personnalisation :
	* Simplifier le code de la touche 1 des variantes pour le breton et pour l’Afrique francophone. dispocla.cpp [5d77c5e](https://github.com/dispoclavier/nouvel-azerty/commit/5d77c5e35c309b7af9a17351bb550e750bbd7a72), dispotypes.c [982d5d6](https://github.com/dispoclavier/nouvel-azerty/commit/982d5d62ab5b76d04b2fe594b2003d607447bea1)
	* Compacter le code pour faciliter la maintenance. dispocla.cpp [aba7eb0](https://github.com/dispoclavier/nouvel-azerty/commit/aba7eb063e7e121cbf2f86e7e8bb35efcc81e57c)
* Documentation. dispocla.cpp [8df14fd](https://github.com/dispoclavier/nouvel-azerty/commit/8df14fd2cde91256cad5c7ad4ba41fa9cf5e7702), dispotypes.c [bc83d02](https://github.com/dispoclavier/nouvel-azerty/commit/bc83d0210b7533e077baefde6038c56450cc1070)

## 2.1.0 (2024-05-31)

* Disposition :
	* Déboguer la touche 8 de la variante belge. dispocla.cpp [a2fa910](https://github.com/dispoclavier/nouvel-azerty/commit/a2fa910f037fc7ba63f2d1e52aaa9ac26239da5e)
	* Mode ASCII : Touche E11 en AltGr/Option : Mettre "-" U+002D à la place de "°" U+00B0. dispotypes.c [1372a36](https://github.com/dispoclavier/nouvel-azerty/commit/1372a366ff1b71065719d29e4aab58cf10d9a810), dispocla.cpp [a2fa910](https://github.com/dispoclavier/nouvel-azerty/commit/a2fa910f037fc7ba63f2d1e52aaa9ac26239da5e)

## 2.0.6 (2024-05-30)

* Disposition :
	* Déboguer "′" U+2032 sur la touche D02. dispotypes.c [a1d471a](https://github.com/dispoclavier/nouvel-azerty/commit/a1d471a49c216dd940c81e0d695957e93baf3614), dispocla.cpp [91aa602](https://github.com/dispoclavier/nouvel-azerty/commit/91aa602d43a1756e9cd053b0c817dae459869588)
	* Déboguer la touche D01 des variantes redisposées. ibidem
* Personnalisation : Améliorer la maintenabilité du code. dispotypes.c [a1d471a](https://github.com/dispoclavier/nouvel-azerty/commit/a1d471a49c216dd940c81e0d695957e93baf3614), [b7f2ae8](https://github.com/dispoclavier/nouvel-azerty/commit/b7f2ae8ed5d9e5aff78392c5720a352be3376c0c), [c98825a](https://github.com/dispoclavier/nouvel-azerty/commit/c98825a9c4119d45a0935bdea732d7310ab92f5e), dispocla.cpp [91aa602](https://github.com/dispoclavier/nouvel-azerty/commit/91aa602d43a1756e9cd053b0c817dae459869588), [b8c19bf](https://github.com/dispoclavier/nouvel-azerty/commit/b8c19bf8378b37d9c617326c8666a2d2aef8e978), [21780af](https://github.com/dispoclavier/nouvel-azerty/commit/21780af35e9a2ba556e34614156b599c0e3cbeb4)

## 2.0.5 (2024-05-28)

* Disposition : Déboguer la touche B06. dispotypes.c [e6fa645](https://github.com/dispoclavier/nouvel-azerty/commit/e6fa6456530e1d2b4d4d31056b57d01acf597e24)

## 2.0.4 (2024-05-27)

* Disposition :
	* Déboguer les touches 2, 7, 9 en mode ASCII. dispotypes.c [6eb5ada](https://github.com/dispoclavier/nouvel-azerty/commit/6eb5ada1baafa5e1a3ad9ad65ccdef221c0edfab)
	* Déboguer la touche 1 des variantes pour le breton. dispocla.cpp [5e36f73](https://github.com/dispoclavier/nouvel-azerty/commit/5e36f731ad7327582e8c298e18a49321933caa8a), dispotypes ibidem
* Vues de disposition : Optimiser pour un rendu intelligible. ibidem
* Commutateur : Documentation. evdev-additions.xml [e983458](https://github.com/dispoclavier/nouvel-azerty/commit/e983458faf769aeeb30da32b6fd9a88c332cb945), [9447c03](https://github.com/dispoclavier/nouvel-azerty/commit/9447c031b59d82360d041a27e962a94187aa8b6c)
* Sous-variantes : Documentation. evdev.c [ca470f1](https://github.com/dispoclavier/nouvel-azerty/commit/ca470f166bb947ece0ba07354ec10b03202ddf3e)

## 2.0.3 (2024-05-25)

* Commutateur : Mettre à jour par l’ajout des codes de pays. evdev-additions.xml [1d5bdf7](https://github.com/dispoclavier/nouvel-azerty/commit/1d5bdf770e3cb68a633748107e569bd36443b9e0)

## 2.0.2 (2024-05-23)

* Transformations : Documentation. compose-2.yml [d5274a3](https://github.com/dispoclavier/nouvel-azerty/commit/d5274a393d8c77e9063e7d11da962c48c6394c7f), [6242a03](https://github.com/dispoclavier/nouvel-azerty/commit/6242a039772829d27b53381994809623d5a518fe), [450eac7](https://github.com/dispoclavier/nouvel-azerty/commit/450eac78b64940e119aa68cd4c66850392e8a448)

## 2.0.1 (2024-05-22)

* Transformations : Déboguer les dispositions pour les systèmes postérieurs à octobre 2023 suite à la suppression du nom XKB de la touche morte barré. dispocla.cpp [9ec9fc2](https://github.com/dispoclavier/nouvel-azerty/commit/9ec9fc26ce3b3a31b60fa4e78ea456280ba0a4d7), compose-2.yml [6de07bb](https://github.com/dispoclavier/nouvel-azerty/commit/6de07bb4ae228c8c3e2277fbed21b8bf01ee1045), compose-1.yml [882ca8a](https://github.com/dispoclavier/nouvel-azerty/commit/882ca8a19e47b2fe544aa4f351cf49fa56613f6b)

## 2.0.0 (2024-05-20)

Version 2.0 due à la nécessité de redonder en AltGr le symbole euro, de redisposer 30 % des symboles ASCII, et de disposer en Minuscule, en mode français, l’apostrophe ASCII à côté de l’apostrophe française. compose-1.yml [8b62065](https://github.com/dispoclavier/nouvel-azerty/commit/8b6206594ebf9b02e36d94466f253d8fb0a18030)
* Disposition :
	* Redonder le symbole "€" U+20AC en AltGr/Option à la place de "{". dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [d7e798a](https://github.com/dispoclavier/nouvel-azerty/commit/d7e798a2ad558a15bb1808bf022a510150a26ffe), [f7d237b](https://github.com/dispoclavier/nouvel-azerty/commit/f7d237bd0cb41ae8a89c9c6318ff2ed8174ac8a5)
	* Redonder l’apostrophe ASCII "'" sur la touche 5 à la place de la touche morte accent grave, qui prend la place de la touche de composition, qui prend la place de "ʳ" U+02B3 sur AltGr/Option + +=, qui est sur AltGr/Option + AltFr + R et dans la touche morte exposant. En mode ASCII, redonder la touche de composition à son ancienne place, la nouvelle place d’accent grave. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [7a48fec](https://github.com/dispoclavier/nouvel-azerty/commit/7a48fec7cc58116bb2ebf58e5b16337eca67064f), dispotypes.c [073788e](https://github.com/dispoclavier/nouvel-azerty/commit/073788e985a58998b309ce5920e19611a600e72c)
	* Symboles ASCII :
		* Mettre "{" à la place de "'", qui prend la place de "\\"" U+0022, qui est sur la touche du 3 en mode français et sur la touche de l’accent circonflexe en mode ASCII, et qui est remplacé par "€" U+20AC à la place laissée par "{". dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Mettre "}" à la place de "`", qui prend la place de "\\" U+005C, qui prend la place laissée par "}". ibidem
		* Mettre "[" en dessous de "{" à la place de "]", qui prend la place de "_", qui prend la place laissée par "[". ibidem
		* Raccourcis contrôle : Déboguer Ctrl + "+" pour les applications ne fonctionnant pas avec Ctrl + "=". dispotypes.c [073788e](https://github.com/dispoclavier/nouvel-azerty/commit/073788e985a58998b309ce5920e19611a600e72c)
	* Touches mortes en Maj + AltGr/Option :
		* Faire suivre crosse ou crochet à la place d’accent aigu, qui prend la place de double accent aigu, qui prend la place laissée par crosse ou crochet. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420), [d908a99](https://github.com/dispoclavier/nouvel-azerty/commit/d908a997202108277a749a45d432dda0dbde25b2)
		* Faire suivre crochet rétroflexe à la place d’accent grave, qui prend la place de réfléchi, qui prend la place laissée par crochet rétroflexe. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Faire suivre ogonek à la place de crochet en chef, qui prend la place d’indice, qui prend la place laissée par ogonek. ibidem
	* Symboles en Maj + AltFr :
		* Permuter "″" U+2033 et "U+", qui passe de la touche E à la touche U. dispocla.cpp [55890e8](https://github.com/dispoclavier/nouvel-azerty/commit/55890e81e154fb3479635595a9cc8eed74f2a420)
		* Ajouter "\\u{" à la place de "′" U+2032 (touche I, nouvelle touche de "{"), qui prend la place de "‰" U+2030 (touche Z, à côté de "″" U+2033), qui est dans le groupe 1 de "%" et est tombé en désuétude. ibidem
		* Faire suivre "‾" U+203E de Maj + AltGr/Option + AltFr + L sur Maj + AltFr + J, la nouvelle touche de "_", à la place de "⟨" U+27E8, qui est dans le groupe 1 de "[". Redonder "&#x" sur K à la place de "⟩" U+27E9, qui est dans le groupe 1 de "]". ibidem
	* Séquences et émojis en Maj + AltGr/Option + AltFr :
		* Faire suivre "&amp;quot;" de la touche U sur la touche E à la place de "😁" U+1F601, qui prend la place de "🙏" U+1F64F sur la touche O, qui prend la place de "&amp;apos;" sur la touche I, qui prend la place laissée par "&amp;quot;" sur la touche U. ibidem
		* Ajouter "🤣" U+1F923, 4ᵉ émoji le plus utilisé du monde, à la place laissée par "‾" U+203E. dispocla.cpp [b0c9790](https://github.com/dispoclavier/nouvel-azerty/commit/b0c97906ee69331484dea6f3076a756bcd7ff0b5)
* Sortie multi-caractères : Déboguer pour les compilateurs défectueux qui ont besoin de commentaires de fin de ligne pour lire les séquences de composition (malgré ce qui est [spécifié](https://linux.die.net/man/3/xcompose) sous « File Format »). compose-1.yml [11eab8e](https://github.com/dispoclavier/nouvel-azerty/commit/11eab8eee4d86e79ca9175f4e04c12411fe40c72), [2e4fa01](https://github.com/dispoclavier/nouvel-azerty/commit/2e4fa0154d9a6ee4032d588153d2bfdee8bb3236)
* Composition :
	* Dupliquer "\\"" U+0022 par "€" U+20AC. compose-1.yml [223b3ec](https://github.com/dispoclavier/nouvel-azerty/commit/223b3ec15f4597cea59eda0d4ef95ec8cc037636)
	* Dupliquer ";" par "§" U+00A7. compose-1.yml [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Compléter les séquences de "∧" U+2227, "∨" U+2228, "⊻" U+22BB, "⊼" U+22BC, "⊽" U+22BD. Restreindre les séquences de "®" U+00AE. Diversifier les séquences de "©" U+00A9, "℗" U+2117, "®" U+00AE. compose-1.yml [3f1569e](https://github.com/dispoclavier/nouvel-azerty/commit/3f1569e94ae285d80b3a0a54f397565de36902bc)
	* Simplifier la séquence de "⁒" U+2052. compose-1.yml [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Mettre à jour les renvois. compose-1.yml [b40afd1](https://github.com/dispoclavier/nouvel-azerty/commit/b40afd1141823e5f65653ff9a3a753d98ad39f6c), [7f9d628](https://github.com/dispoclavier/nouvel-azerty/commit/7f9d628ed127a3e94d0e1a0558b5f3a0e567600a), [5e75dac](https://github.com/dispoclavier/nouvel-azerty/commit/5e75dacf841d71082f5b6b3fbdb33824d1504ac4)
	* Simplifier le fichier. compose-1.yml [731afa0](https://github.com/dispoclavier/nouvel-azerty/commit/731afa0d2fa108b55d76a8ecca8308af63399e17)
* Transformations :
	* Groupes des symboles :
		* Prendre en charge "€" U+20AC comme caractère de base aux côtés de "\\"" U+0022. compose-3.yml [4137c0d](https://github.com/dispoclavier/nouvel-azerty/commit/4137c0dc378711bd7ace334dd555f87619063418)
		* Mettre à jour les symboles de base. ibidem
		* Faire suivre "―" U+2015 à la place de "⟨" U+27E8, qui prend la place de "⟩" U+27E9, qui prend la place laissée par "―" U+2015. compose-3.yml [d535c12](https://github.com/dispoclavier/nouvel-azerty/commit/d535c12126bbee9d9fd9cd806b927a097b35e505)
		* Faire suivre "❰" U+2770 à la place de "❱" U+2771, qui prend la place de "•" U+2022, qui prend la place laissée par "❰" U+2770. ibidem
		* Faire suivre "❮" U+276E à la place de "❯" U+276F, qui prend la place de "◦" U+25E6, qui prend la place laissée par "❮" U+276E. ibidem
		* Faire suivre "❑" U+2751 à la place de "❏" U+274F, qui prend la place de "⮊" U+2B8A, qui prend la place laissée par "❑" U+2751. ibidem
		* Regrouper "❒" U+2752 à la place de "⟧" U+27E7, qui prend la place de "◊" U+25CA, qui prend la place de "➢" U+27A2, qui est dans accent circonflexe, où se trouve aussi "➣" U+27A3. ibidem
		* Regrouper "❐" U+2750 à la place de "➲" U+27B2, qui prend la place de "⟦" U+27E6, qui prend la place de "‪" U+202A, qui est dans composition. Ajouter "⮈" U+2B88 à la place de U+202B, qui est dans composition. ibidem
		* Faire suivre "ʻ" U+02BB à la place de "✅" U+2705, qui prend la place de "▻" U+25BB, qui n’est pris en charge que dans les versions 1.7.3 et 1.7.4. ibidem
		* Permuter "ʼ" U+02BC et "〃" U+3003. ibidem
		* Mettre "∅" U+2205 à la place de "Ω" U+2126, qui prend la place laissée par "ʻ" U+02BB. À la place laissée par "∅" U+2205, redonder "¶" U+00B6, normalement sur touche vive sur la touche du P. ibidem
		* Mettre "⏳" U+23F3 à la place de "⊲" U+22B2, qui prend la place laissée par "❐" U+2750. Mettre "⌛" U+231B à la place de "⊳" U+22B3, qui prend la place laissée par "❒" U+2752. Ajouter "⧖" U+29D6 à la place laissée par "⏳" U+23F3. Ajouter "⧗" U+29D7 à la place laissée par "⌛" U+231B. ibidem
		* Permuter "♦" U+2666 et "♣" U+2663 pour la mnémonique. ibidem
		* Mettre "†" U+2020 à la place de "µ" U+00B5, qui est normalement sur touche vive et qui prend la place de "∣" U+2223, qui est dans macron 1 et dans composition. Mettre "‡" U+2021 à la place de "∥" U+2225, qui est dans macron 4 et dans composition. Mettre "⹋" U+2E4B à la place de "‖" U+2016, qui est dans macron 2 et dans composition. compose-3.yml [46bf78c](https://github.com/dispoclavier/nouvel-azerty/commit/46bf78c15f1899121c2b306e72510701f7bbf648), [14f8844](https://github.com/dispoclavier/nouvel-azerty/commit/14f88440592521e180c14ab475af44be966c7620)
		* Mettre "∣" U+2223 à la place de "†" U+2020, qui est dans tilde 1. Mettre "‖" U+2016 à la place de "‡" U+2021, qui est dans tilde 2. Mettre "∥" U+2225 à la place de "⹋" U+2E4B, qui est dans tilde 3, avec "⸶" U+2E36 dans tilde 4, "⸸" U+2E38 dans tilde 5, et "⸷" U+2E37 dans tilde 6. compose-3.yml [c96516e](https://github.com/dispoclavier/nouvel-azerty/commit/c96516ecc88a40c2b6d538b5bda6a1ea3fb626a2), [6367a5a](https://github.com/dispoclavier/nouvel-azerty/commit/6367a5a76e794eeeb24a4dc8bd2ee54e7647368e), [f91879e](https://github.com/dispoclavier/nouvel-azerty/commit/f91879ecf13c591d9bdd4d6d9ed4b9a80af4b58d), compose-2.yml [4fa70b9](https://github.com/dispoclavier/nouvel-azerty/commit/4fa70b903241008b75d894271604ca07ccbfdf42)
		* Permuter "ˑ" U+02D1 et "ː" U+02D0. compose-3.yml [80fb096](https://github.com/dispoclavier/nouvel-azerty/commit/80fb0969cc0c0b465357b8e6ee9552eca3b21074)
		* Mettre "⤴" U+2934 et "⤵" U+2935 aux places de "※" U+203B et "⌨" U+2328, qui prennent les places de "⊲" U+22B2 et "⊳" U+22B3, qui sont dans composition. Mettre "∖" U+2216 à la place laissée par "⤵" U+2935. Permuter "∕" U+2215 et "▲" U+25B2, "⛛" U+26DB et "▼" U+25BC. Redonder "♮" U+266E à la place laissée par "∖" U+2216. Redonder "〃" U+3003 à la place laissée par "⤴" U+2934. compose-3.yml [4eea50a](https://github.com/dispoclavier/nouvel-azerty/commit/4eea50af7ba3c9cf85617669dfcb342b28e373be)
		* Ajouter "∡" U+2221 à la place de "⦜" U+299C, qui prend la place de "▪" U+25AA, qui est dans circonflexe 4. Ajouter "∟" U+221F à la place de "‣" U+2023, qui est dans circonflexe 6. ibidem
		* Dupliquer "@" par la touche morte grec ou cerclé. Nécessaire depuis la version 1.7.0.) (ibidem
		* Mettre "∟" U+221F à la place de "⦜" U+299C, qui prend la place de "◊" U+25CA, qui prend la place laissée par "∟" U+221F. Mettre "∠" U+2220 à la place de "⚛" U+269B, qui prend la place de "∡" U+2221, qui prend la place de "⚓" U+2693, qui prend la place de "♿" U+267F, qui prend la place laissée par "∠" U+2220. Permuter "⛵" U+26F5 et "⛷" U+26F7. Permuter "⛴" U+26F4 et "⚽" U+26BD. compose-3.yml [075cf20](https://github.com/dispoclavier/nouvel-azerty/commit/075cf20a74214ad255ffffb38c8c3e029017ffa4)
		* Permuter "⧖" U+29D6 et "⧗" U+29D7. compose-3.yml [0d80301](https://github.com/dispoclavier/nouvel-azerty/commit/0d803019a6173d4eabbc76a805648e56f0a17bc0)
		* Mettre "∧" U+2227 à la place de "¬" U+00AC, qui prend la place de "∨" U+2228, qui prend la place laissée par "¬" U+00AC. compose-3.yml [96c5653](https://github.com/dispoclavier/nouvel-azerty/commit/96c5653869fe9fc3c407623f19a49a8df9ba3d7d)
		* Permuter "⛆" U+26C6 et "〰" U+3030 pour que la pluie soit dans le même groupe que "☔" U+2614. ibidem
		* Mettre "∫" U+222B à la place de "〃" U+3003, qui est dans le groupe 12 de "€" U+20AC et "\\"" U+0022 et prend la place de "∬" U+222C, qui prend la place de "ˌ" U+02CC, qui prend la place de "⚧" U+26A7, qui prend la place de "⮽" U+2BBD, qui prend la place de "▢" U+25A2, qui prend la place laissée par "∫" U+222B. Mettre "∭" U+222D à la place de "ˈ" U+02C8, qui prend la place de "∝" U+221D, qui prend la place laissée par "∭" U+222D. ibidem et compose-2.yml [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
	* Dupliquer "\\"" U+0022 par "€" U+20AC. compose-2.yml [cbd46d7](https://github.com/dispoclavier/nouvel-azerty/commit/cbd46d7566a9a70801a536c050e665a6082260c4)
	* Mettre à jour l’ordre des répertoires de touches mortes. compose-2.yml [79bc1ba](https://github.com/dispoclavier/nouvel-azerty/commit/79bc1ba9d80262d0b5564eefae30b4b1e4b4deb9)
	* Mettre à jour les symboles de base. compose-2.yml [6603624](https://github.com/dispoclavier/nouvel-azerty/commit/660362419d1d97088c6da803853a43d9f6b0fef7), [e491173](https://github.com/dispoclavier/nouvel-azerty/commit/e49117376c902d4c21acce6e0ea66def18e54ee0), [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
	* Dupliquer ";" par "§" U+00A7. compose-2.yml [e491173](https://github.com/dispoclavier/nouvel-azerty/commit/e49117376c902d4c21acce6e0ea66def18e54ee0)
	* Grec ou cerclé : Compléter les séquences de "⊗" U+2297. compose-2.yml [4fa70b9](https://github.com/dispoclavier/nouvel-azerty/commit/4fa70b903241008b75d894271604ca07ccbfdf42)
	* Double accent aigu : Dupliquer "\\"" U+0022 par "€" U+20AC. compose-2.yml [559f988](https://github.com/dispoclavier/nouvel-azerty/commit/559f9880394d3724b67f06ba4e717c6e219817a3)
	* Tourné : Redonder "⁀" U+2040, "‿" U+203F. Inversé : Déplacer "⁔" U+2054 de la parenthèse fermante à la parenthèse ouvrante. Redonder "‿" U+203F par la parenthèse fermante. ibidem et compose-3.yml [12dd14a](https://github.com/dispoclavier/nouvel-azerty/commit/12dd14a90dcb04c72845e64dc5fc5e45f1149751)
	* Rond en chef : Redonder "∗" U+2217 par "0" et par "4". compose-2.yml [1510bb0](https://github.com/dispoclavier/nouvel-azerty/commit/1510bb04a2e041e24f0862ed64d34c606731bb4f)
	* Accent circonflexe :
		* Redonder "•" U+2022 par "1" U+0031 à la place de "♤" U+2664, "◦" U+25E6 par "2" U+0032 à la place de "♢" U+2662, "▪" U+25AA par "4" U+0034 à la place de "♡" U+2661, "▫" U+25AB par "5" U+0035 à la place de "♧" U+2667, "‣" U+2023 par "6" U+0036 à la place de "♠" U+2660. Ajouter "▹" U+25B9 par "7" U+0037 à la place de "♦" U+2666. Redonder "➢" U+27A2 par "9" U+0039 à la place de "♣" U+2663. Ajouter "➣" U+27A3 par "0" U+0030. Redonder "′" U+2032 par "²" U+00B2, "″" U+2033 par "³" U+00B3. compose-2.yml [6603624](https://github.com/dispoclavier/nouvel-azerty/commit/660362419d1d97088c6da803853a43d9f6b0fef7)
		* Mettre à jour le caractère de base et l’ordre de "♡" U+2661, "♧" U+2667, "♢" U+2662, "♤" U+2664, (ibidem)
	* Accent grave : Supprimer "(" et ")". ibidem
	* Tilde : Permuter "⸷" U+2E37 et "⸸" U+2E38. Compléter les séquences de "”" U+201D et "’" U+2019. ibidem et compose-2.yml [368d4aa](https://github.com/dispoclavier/nouvel-azerty/commit/368d4aa29927567a004b9c1a22fa1175104db332)
	* Barré : Barre courte : Redonder "Ꝙ" U+A758, "ꝙ" U+A759. compose-2.yml [2c72d23](https://github.com/dispoclavier/nouvel-azerty/commit/2c72d237681dc4e6e09f653977f4a53030fdbeb7)
* Commutateur : Variante Breton et français redisposée : Ajouter l’icône « br » manquante. evdev-additions.xml [4d148fe](https://github.com/dispoclavier/nouvel-azerty/commit/4d148fe24cae47953da873f6b3a9997330923b1b)

## 1.7.4 (2024-03-28)

* Composition :
	* Ajouter "☧" U+2627. compose-1.yml [9818410](https://github.com/dispoclavier/nouvel-azerty/commit/9818410af3054c84ab44dd700cbee88120c95921)
	* Compléter les séquences de "℀" U+2100, "⅍" U+214D, "℁" U+2101, "℅" U+2105, "℆" U+2106, "♩" U+2669, "♪" U+266A, "♫" U+266B, "♬" U+266C, "♭" U+266D, "♮" U+266E. Adapter les séquences de "₦" U+20A6, "⫓" U+2AD3, "⫔" U+2AD4, "⫖" U+2AD6. ibidem
* Transformations :
	* Groupes des symboles :
		* Remplacer "Ω" U+03A9 par "⚘" U+2698. compose-3.yml [b532280](https://github.com/dispoclavier/nouvel-azerty/commit/b532280a25cd0ecfa00341d44ae182403b2dda82)
		* Permuter "✈" U+2708 et "ª" U+00AA. Permuter "⚒" U+2692 et "º" U+00BA. ibidem
		* Mettre "⹀" U+2E40 à la place de "‐" U+2010, qui prend la place de "➟" U+279F, qui prend la place laissée par "⹀" U+2E40. ibidem
		* Permuter "➖" U+2796 et "⹀" U+2E40. Redonder "∓" U+2213 à la place de "➕" U+2795, qui prend la place de "+", qui est sur touches vives. compose-3.yml [acc6735](https://github.com/dispoclavier/nouvel-azerty/commit/acc6735b2da465dccd07db81983eb6b01a787704)
	* Crosse ou crochet : Corriger les séquences de "⁕" U+2055. compose-2.yml [e9bdab5](https://github.com/dispoclavier/nouvel-azerty/commit/e9bdab524a700ba870f0c12506ebba37bf2cc63e)
* Documentation : Procédure de vérification d’absence de conflits entre touches mortes. compose-1.yml [0112702](https://github.com/dispoclavier/nouvel-azerty/commit/01127020fa74acf1f31feb2b4055f96d26242878)

## 1.7.3 (2024-03-24)

* Composition :
	* Déboguer "℧" U+2127, "℥" U+2125. compose-1.yml [cf7f487](https://github.com/dispoclavier/nouvel-azerty/commit/cf7f487e4bb31ff85ecd1de94fccac3ccadb320f)
	* Corriger les séquences de "⋊" U+22CA. Adapter les séquences de "⨞" U+2A1E. ibidem
	* Ajouter "ª" U+00AA, "º" U+00BA. Limiter les séquences de "₳" U+20B3. Corriger les séquences de "⟠" U+27E0, "⩜" U+2A5C, "⩟" U+2A5F, "⩠" U+2A60, "⩝" U+2A5D, "⩞" U+2A5E, "⩚" U+2A5A, "⩙" U+2A59, "⊝" U+229D. Compléter les séquences de "⩢" U+2A62, "⩛" U+2A5B. ibidem
	* Tirets : Mettre "‑" U+2011 à la place de "‒" U+2012, qui prend la place de "―" U+2015, qui prend la place de "⹀" U+2E40, qui prend la place laissée par "‑" U+2011. ibidem
	* Redonder "❏" U+274F, "❐" U+2750, "❑" U+2751, "❒" U+2752. ibidem
* Transformations :
	* Groupes des symboles :
		* Permuter "⋅" U+22C5 et "‧" U+2027. Redonder "⋅" U+22C5 à la place de "ˑ" U+02D1, qui prend la place de "꞉" U+A789 sur B10, qui prend la place de "ː" U+02D0, qui prend la place de "⊢" U+22A2, qui prend la place de "⋌" U+22CC, qui est en composition. compose-3.yml [58ba0da](https://github.com/dispoclavier/nouvel-azerty/commit/58ba0da5aee3909c5ed375419708c053a95f1a41)
		* Redonder "−" U+2212 à la place de "‐" U+2010, qui prend la place de "⊖" U+2296, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "+" à la place de "⊕" U+2295, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "×" U+00D7 à la place de "❖" U+2756, qui prend la place de "✂" U+2702, qui prend la place de "✖" U+2716, qui prend la place de "⊗" U+2297, qui est dans grec ou cerclé et en composition. ibidem
		* Redonder "÷" U+00F7 à la place de "♥" U+2665 sur B01, qui prend la place de "❤" U+2764, qui prend la place de "‧" U+2027 sur la même touche B07, qui devient redondant. ibidem
		* Mettre "✅" U+2705 à la place de "✔" U+2714, qui prend la place de "✓" U+2713, qui prend la place de "✘" U+2718, qui prend la place de "⚠" U+26A0 sur B01, qui prend la place de "ª" U+00AA, qui passe en composition et prend la place de "✈" U+2708, qui prend la place de "※" U+203B, qui prend la place de "꞉" U+A789 sur B09 dans le groupe 11, qui devient redondant. ibidem
		* Mettre "ʻ" U+02BB à la place de "º" U+00BA, qui passe en composition et prend la place de "⛔" U+26D4, qui prend la place de "〰" U+3030, qui prend la place de "♠" U+2660, qui prend la place de "⛆" U+26C6, qui prend la place de "♣" U+2663, qui prend la place de "⁛" U+205B, qui prend la place de "⊥" U+22A5, qui prend la place de "⋊" U+22CA, qui est en composition. ibidem
		* Mettre "⭕" U+2B55 à la place de "∅" U+2205, qui prend la place de "Ω" U+2126, qui prend la place laissée par "ʻ" U+02BB. ibidem
		* Mettre "❌" U+274C à la place de "∗" U+2217, qui prend la place de "❎" U+274E, qui prend la place de "✴" U+2734, qui prend la place de "✳" U+2733, qui prend la place de "✨" U+2728, qui prend la place laissée par "❌" U+274C. ibidem
		* Ajouter "▻" U+25BB à la place de "►" U+25BA, qui prend la place de "➗" U+2797, qui prend la place de "♦" U+2666, qui prend la place de "♥" U+2665 sur B07 dans le groupe 3, qui devient redondant. ibidem
		* Redonder "⸫" U+2E2B à la place de "⊣" U+22A3, qui prend la place de "⋋" U+22CB, qui est en composition. ibidem
		* Redonder "⸪" U+2E2A à la place de "⊤" U+22A4, qui prend la place de "⋉" U+22C9, qui est en composition. ibidem
		* Redonder "⹀" U+2E40 à la place de "➸" U+27B8, qui prend la place laissée par "✅" U+2705. ibidem
		* Redonder "Ω" U+03A9 à la place laissée par "⭕" U+2B55. ibidem
	* Exposant : Déboguer "⁄" U+2044. compose-2.yml [ecc5889](https://github.com/dispoclavier/nouvel-azerty/commit/ecc5889cb8c2b741878468796abf9479668391d7)
	* Indice : Déboguer "⁄" U+2044. ibidem
	* Accent aigu : Supprimer "‐" U+2010. ibidem
	* Accent circonflexe : Supprimer "‌" U+200C. ibidem
	* Tilde : Supprimer "’" U+2019 par "'". ibidem
	* Tréma : Supprimer "‑" U+2011. ibidem

## 1.7.2 (2024-03-15)

* Composition : Déboguer "‬" U+202C. compose-1.yml [df24b01](https://github.com/dispoclavier/nouvel-azerty/commit/df24b01bd6e9e9220642158a8937810128f68bc9)
* Transformations : Groupes des symboles :
	* Redonder "±" U+00B1 dans le groupe 1 de + sur H à la place de "⚠" U+26A0, qui prend la place de "∕" U+2215, qui prend la place de "▲" U+25B2, qui prend la place de "▼" U+25BC, qui prend la place de "⛛" U+26DB, qui prend la place de "◊" U+25CA, qui prend la place de "➢" U+27A2, qui prend la place de "❖" U+2756, qui prend la place de "∘" U+2218, qui est en composition. compose-3.yml [e976bdb](https://github.com/dispoclavier/nouvel-azerty/commit/e976bdbe70e82c57a1df45ffa21b0bb1f6e2299e)
	* Permuter "Ⓜ" U+24C2 et "∣" U+2223. ibidem
	* Mettre "⛄" U+26C4 à la place de "¬" U+00AC, qui prend la place de "∖" U+2216, qui prend la place de "♮" U+266E, qui prend la place de "‬" U+202C, qui prend la place laissée par "⛄" U+26C4. ibidem
	* Mettre "☃" U+2603 à la place de "⛅" U+26C5, qui prend la place de "❄" U+2744, qui prend la place de "☁" U+2601, qui prend la place laissée par "☃" U+2603. ibidem
	* Ajouter "☏" U+260F à la place de "☎" U+260E, qui prend la place de "⌨" U+2328, qui prend la place de "❒" U+2752, qui prend la place de "❑" U+2751, qui prend la place de "⤴" U+2934, qui prend la place de "⁜" U+205C, qui prend la place de "˖" U+02D6, qui est dans cornu. ibidem
	* Redonder "⁞" U+205E à la place de "⋯" U+22EF, qui prend la place de "꞉" U+A789, qui prend la place de "❐" U+2750, qui prend la place de "❏" U+274F, qui prend la place de "⤵" U+2935, qui prend la place de "⏎" U+23CE, qui est en composition. ibidem
* Documentation : Touches mortes : Simplifier les identifiants. compose-2.yml [df24b01](https://github.com/dispoclavier/nouvel-azerty/commit/df24b01bd6e9e9220642158a8937810128f68bc9)


## 1.7.1 (2024-03-12)

* Transformations :
	* Groupes des symboles : Mettre "µ" U+00B5 à la place de "∣" U+2223, qui prend la place de "⌘" U+2318, qui prend la place de "◊" U+25CA, qui prend la place de "►" U+25BA, qui prend la place de "≻" U+227B. Redonder "Ω" U+2126 à la place de "∅" U+2205, qui prend la place de "⛱" U+26F1, qui prend la place de "∐" U+2210, qui prend la place de "≺" U+227A. compose-3.yml [b1e366d](https://github.com/dispoclavier/nouvel-azerty/commit/b1e366d53c5ab67ba91ca5e752b504ca5705cd7f)
	* Exposant :
		* Redonder "”" U+201D, "’" U+2019. 1.7.2 ; répercuter dans compose-2.yml [66de15c](https://github.com/dispoclavier/nouvel-azerty/commit/66de15cc74d44ea26a3742bd394b71d31345dad3)
		* Redonder "⁄" U+2044. compose-2.yml [72ec518](https://github.com/dispoclavier/nouvel-azerty/commit/72ec5183dabcd2be4cb289bd892b04c6f7094c65)
	* Indice : Redonder "⁄" U+2044. ibidem
	* Drapeau : Compatibilité. ibidem

## 1.7.0 (2024-03-02)

* Disposition : Redonder la touche morte grec ou cerclé à la place de "@" sur D06. dispocla.cpp [2b62fcd](https://github.com/dispoclavier/nouvel-azerty/commit/2b62fcd03c1403fa8ee37e2accaf5be25c53a034)
* Transformations : Tilde : Redonder les guillemets comme dans Accent aigu. compose-2.yml [b9a8c63](https://github.com/dispoclavier/nouvel-azerty/commit/b9a8c635e1cd079dfd625d7bc1af3f4bc56b16c5), [9d84d8f](https://github.com/dispoclavier/nouvel-azerty/commit/9d84d8f797d0687367d84de63b4c7dfc67191f98)
* Distribution : Ranger les sources de disposition fusionnées par variante dans 9 dossiers. comp.sh [28d932b](https://github.com/dispoclavier/nouvel-azerty/commit/28d932b0f03eb04368e73aa7091596c25c4b909e)
* Documentation : Restaurer l’historique des versions du répertoire des touches mortes. Compose.yml de [c6c939f](https://github.com/dispoclavier/nouvel-azerty/commit/c6c939f1ec1a84dc4a1ec4aaf49df552b887e5dd) à [bebf6f8](https://github.com/dispoclavier/nouvel-azerty/commit/bebf6f8e44270b5623bf4eae95454b8b657497e2)

## 1.6.0 (2024-02-09)

* Composition :
	* Ajouter "℣" U+2123, "℟" U+211F, "ꭈ" U+AB48. compose-1.yml [5de859b](https://github.com/dispoclavier/nouvel-azerty/commit/5de859b516c4eacd3c57c36f6b5da89ceacb0fb3), [bdf672e](https://github.com/dispoclavier/nouvel-azerty/commit/bdf672eed9f5279f37032658b624c993880ddc0b), [66d2d69](https://github.com/dispoclavier/nouvel-azerty/commit/66d2d69a5656bc06cd31c8d0a903e79a12279ffd), [f7b6b07](https://github.com/dispoclavier/nouvel-azerty/commit/f7b6b07e4104bc260d09c4881b76a3df6bd02da1), [37b670f](https://github.com/dispoclavier/nouvel-azerty/commit/37b670fc15f3df846e1f10f1e625a8e6908745ed)
	* Ajouter "℄" U+2104. Redonder "℃" U+2103, "℉" U+2109. Compléter les séquences de "℀" U+2100, "℅" U+2105, "©" U+00A9, "®" U+00AE. compose-1.yml [4d57287](https://github.com/dispoclavier/nouvel-azerty/commit/4d57287c33ddf1700da9269c7932bb23d8cf9d91)
	* Changer les séquences de "☚" U+261A, "☛" U+261B. Ajouter "℈" U+2108, "℔" U+2114, "⅊" U+214A, "℞" U+211E, "℥" U+2125, "℧" U+2127, "⅌" U+214C, "⅏" U+214F, "℠" U+2120, "℡" U+2121, "℻" U+213B, "Å" U+212B, "K" U+212A. Redonder "Ω" U+2126, "℗" U+2117. compose-1.yml [37b670f](https://github.com/dispoclavier/nouvel-azerty/commit/37b670fc15f3df846e1f10f1e625a8e6908745ed), [18f59a5](https://github.com/dispoclavier/nouvel-azerty/commit/18f59a55f4b71aa793716c56dab3199e1fcc71b7)
* Transformations :
	* Groupes des lettres :
		* Groupe 1 : Remplacer "Ǝ" U+018E et "ǝ" U+01DD par "℣" U+2123, "Ɲ" U+019D et "ɲ" U+0272 par "℟" U+211F. compose-3.yml [b97308c](https://github.com/dispoclavier/nouvel-azerty/commit/b97308ccd60a189e7b7eea5bf03900eddfb6eee6), compose-1.yml [920240d](https://github.com/dispoclavier/nouvel-azerty/commit/920240dade55b57e1aec45af08f4b551f2e9a09f), [0a432bf](https://github.com/dispoclavier/nouvel-azerty/commit/0a432bfd6249bca8a93486c86dcfc8f926a61c90)
		* Groupe 4 : Redonder "℣" U+2123, "℟" U+211F. Supprimer "ꭈ" U+AB48. Groupes 4, 5, 11, 12 : Permuter "ɷ" U+0277, "ʍ" U+028D, "Ꝩ" U+A768, "ꝩ" U+A769, "Ƿ" U+01F7, "ƿ" U+01BF, "ꭗ" U+AB57, "ꭙ" U+AB59, "ʭ" U+02AD, "̍" U+030D, "̩" U+0329, "̽" U+033D, "͓" U+0353. compose-3.yml [66965ea](https://github.com/dispoclavier/nouvel-azerty/commit/66965ea31611752be983205dffa2414eaf5df751)
		* Groupe 5 : Supprimer le doublon de "ꬷ" U+AB37 et cette prise en charge de "ʪ" U+02AA. Déplacer "ǁ" U+01C1 de H à L. Groupes 1–5 : Incrémenter "Ꜧ" U+A726 et "ꜧ" U+A727, "Ɦ" U+A7AA et "ɦ" U+0266, "Ɥ" U+A78D et "ɥ" U+0265, "Ⱶ" U+2C75 et "ⱶ" U+2C76. Groupe 12 : Mettre "˓" U+02D3 sur E, "˒" U+02D2 sur O. Groupe 1 : Regrouper "ʾ" U+02BE et "ʿ" U+02BF sur K. Redonder "Ɲ" U+019D et "ɲ" U+0272 sur J, "Ǝ" U+018E et "ǝ" U+01DD sur H. compose-3.yml [768915e](https://github.com/dispoclavier/nouvel-azerty/commit/768915e180bae47c1947ace1d21016d4296bb28e)
		* Remplacer "ʐ" U+0290 par Ⱬ" U+2C6B, ⱬ" U+2C6C, remplacés par "ʓ" U+0293, "ʑ" U+0291, remplacés par "Ɀ" U+2C7F, "ɀ" U+0240, remplacés par "℥" U+2125. Groupe 4 de S : Remplacer "ʲ" U+02B2 par "℈" U+2108. Groupe 12 de E : Redonder "℈" U+2108. compose-3.yml [cdb706c](https://github.com/dispoclavier/nouvel-azerty/commit/cdb706c42934ddacd567c6969f6f3d41b59e05f8)
		* Groupe 2 : Remplacer la redondance de "ſ" U+017F et "ẛ" U+1E9B par "ꬵ" U+AB35 et "ʩ" U+02A9 du groupe 4, remplacés par "ʾ" U+02BE et "͗" U+0357 du groupe 5, remplacés par "˒" U+02D2 et "̹" U+0339 du groupe 11. Groupe 4 : Remplacer cette prise en charge de "ʣ" U+02A3 et "ʤ" U+02A4 par "ʿ" U+02BF et "͑" U+0351 du groupe 5, remplacés par "̜" U+031C et "˓" U+02D3 des groupes 11 et 12. compose-3.yml [59759f4](https://github.com/dispoclavier/nouvel-azerty/commit/59759f4077089ba07a79d3aaf15d367d3f5875fc)
		* Groupe 3 : Redonder "Kʼ" U+004B U+02BC. Groupe 4 : Redonder "℃" U+2103. Groupe 11 : Redonder "℉" U+2109, "℄" U+2104. compose-3.yml [0e887c3](https://github.com/dispoclavier/nouvel-azerty/commit/0e887c34299ce2ace6443ba9c2cc94092d41ce15)
		* Groupe 12: Remplacer "ŉ" U+0149 par "Ꞑ" U+A790, "ꞑ" U+A791. Redonder "ℹ" U+2139, "Ω" U+2126. compose-3.yml [121256f](https://github.com/dispoclavier/nouvel-azerty/commit/121256f82fcb134892ecd8d8e5e36f6fcc323d17)
	* Tourné : Ajouter "℺" U+213A. compose-2.yml [a551b26](https://github.com/dispoclavier/nouvel-azerty/commit/a551b26f19930eb7f7840fa1c07eb305aabcae60)
	* Accent grave : Ajouter "(", ")" (prévu pour la version 1.5.0). compose-2.yml [0750b87](https://github.com/dispoclavier/nouvel-azerty/commit/0750b87a74978085e2ad0e5d63cf357fd2381ed8)
* Documentation :
	* Disposition : Symboles ASCII en AltGr/Option : Permuter l’accent grave et le guillemet double générique (1.2.0). compose-3.yml [81dbf30](https://github.com/dispoclavier/nouvel-azerty/commit/81dbf306d59a5e7887558d3129c04d5672c8a972), [d316791](https://github.com/dispoclavier/nouvel-azerty/commit/d316791df17e563b6630c66f5f09abc3c375bf7c), [9c79996](https://github.com/dispoclavier/nouvel-azerty/commit/9c7999602653aaf0c848bca9fab09389551b42f3)
	* Transformations : Groupes des lettres : Groupe 11 : "Ꞛ" U+A79A, "ꞛ" U+A79B, "Ꞝ" U+A79C, "ꞝ" U+A79D, "Ꞟ" U+A79E, "ꞟ" U+A79F. compose-3.yml [e5e02cd](https://github.com/dispoclavier/nouvel-azerty/commit/e5e02cde11131e7131b59e3085bf141057b894eb)

## 1.5.0 (2023-12-27)

* Disposition : Permuter les touches mortes tréma sur E05 et accent grave sur E12. dispocla.cpp [51701f8](https://github.com/dispoclavier/nouvel-azerty/commit/51701f8ac1f15c71bd2b013b0fca918242a38a16)
* Transformations : Accent grave : Ajouter "(", ")" (prévu pour la version 1.5.0). compose-2.yml [0750b87](https://github.com/dispoclavier/nouvel-azerty/commit/0750b87a74978085e2ad0e5d63cf357fd2381ed8)

## 1.4.0 (2023-12-06)

* Variantes : Polynésie :
	* Restaurer la touche morte accent grave. dispocla.cpp [dc8c459](https://github.com/dispoclavier/nouvel-azerty/commit/dc8c459efc700caa76344415f461a6d68f29efe6), [66de23c](https://github.com/dispoclavier/nouvel-azerty/commit/66de23c18921158c464c915a8baa7f117e826671)
	* Utiliser la touche E08 (ou E07 sur la variante redisposée) pour la touche morte macron et pour le ʻeta polynésien afin de l’avoir sur touche vive. ibidem
* Transformations : Groupes des symboles : Redonder "―" U+2015 et "‑" U+2011 par "ʻ" U+02BB et la touche morte macron sur E08 ou E07 des variantes pour la Polynésie. compose-2.yml [5506742](https://github.com/dispoclavier/nouvel-azerty/commit/55067425c798e52db60680c8ed445d86917392a2), dispocla.cpp [ff3a66d](https://github.com/dispoclavier/nouvel-azerty/commit/ff3a66d129082374dc9d814fa20b16ae11448ba3)
* Documentation. dispocla.cpp [9959c6c](https://github.com/dispoclavier/nouvel-azerty/commit/9959c6c9ec4961f59085ad5e3c53d83ff7f526b3), [d523e98](https://github.com/dispoclavier/nouvel-azerty/commit/d523e982523ad0b94aba1d74764c2cb4d0756641), [d5f1aef](https://github.com/dispoclavier/nouvel-azerty/commit/d5f1aef6c1cd367d09f4168269386836e259797b), compose-2.yml [98fd57a](https://github.com/dispoclavier/nouvel-azerty/commit/98fd57a526fd6418560a292a53ba2071d375a1c9), compose-3.yml [38b12b0](https://github.com/dispoclavier/nouvel-azerty/commit/38b12b0763755b030210de705fbc34caaa2c236a)

## 1.3.0 (2023-12-03)

* Variantes : Ajouter des variantes redisposées :
	* Breton et français disposition de clavier semi-automatique redisposée. dispocla.cpp [df98b31](https://github.com/dispoclavier/nouvel-azerty/commit/df98b3125d4f39de7e60a5c81333daa32e6063b9), [ef0eba1](https://github.com/dispoclavier/nouvel-azerty/commit/ef0eba1031c37950960ccfe59297cc638b4d485e), compose-1.yml [edd54e1](https://github.com/dispoclavier/nouvel-azerty/commit/edd54e1af53ff129c4ee63050ad0b221e338d88f), [259a61d](https://github.com/dispoclavier/nouvel-azerty/commit/259a61da12da22541050ae6faa2b9c9e10015c3e), evdev-additions.xml [b2317cd](https://github.com/dispoclavier/nouvel-azerty/commit/b2317cdfe18dadd19f5805fb4e6774d5662e3809), dispotypes.c [e6c157b](https://github.com/dispoclavier/nouvel-azerty/commit/e6c157b7bb4a235ee3641af0387dbe9b82c9c390), dispoled.c [69ab89f](https://github.com/dispoclavier/nouvel-azerty/commit/69ab89fbd6f88a1df2111c3e89ff8057b32a8c1e)
	* Polynésie française disposition de clavier semi-automatique redisposée. ibidem
	* Afrique francophone disposition de clavier semi-automatique redisposée. ibidem
* Composition : Adapter les séquences de "⋘" U+22D8 et "⋙" U+22D9. compose-1.yml [1f22bd3](https://github.com/dispoclavier/nouvel-azerty/commit/1f22bd396686d6c7d6924fbb493590547f6cd172)
* Transformations :
	* Groupes des symboles :
		* Ajouter le trait d’union insécable "‑" U+2011 dans le groupe 1 d’égal à la place de "✔" U+2714, qui prend la place de "∖" U+2216, qui prend la place de "∧" U+2227, qui prend la place de "∨" U+2228, qui prend la place de "∇" U+2207, qui prend la place de "⚠" U+26A0 redondé sur D/parenthèse ouvrante. compose-1.yml [595303e](https://github.com/dispoclavier/nouvel-azerty/commit/595303ed3bf46819c8792c155d8df28c2c423bc1), compose-2.yml [f78cf66](https://github.com/dispoclavier/nouvel-azerty/commit/f78cf6656ea32788a3471deba3d7270498b50606), compose-3.yml [b2c8c37](https://github.com/dispoclavier/nouvel-azerty/commit/b2c8c3776afe59e8b00c671c6af07ee6021356f6)
		* Groupe 1 du trait d’union insécable : Remplacer "‐" U+2010 par "―" U+2015. compose-1.yml [99f965c](https://github.com/dispoclavier/nouvel-azerty/commit/99f965cfe7e879f4cf91c89225c90f5880b3fc6e), compose-2.yml [651e8c0](https://github.com/dispoclavier/nouvel-azerty/commit/651e8c0f403b76f0f556ece375f4217c3fd54ae9), compose-3.yml [fc16dc6](https://github.com/dispoclavier/nouvel-azerty/commit/fc16dc6a06e36e68cfec4272b6c8c845e4afe0e6)
	* Tréma : Redonder "‑" U+2011 au lieu de "‐" U+2010. compose-2.yml [f78cf66](https://github.com/dispoclavier/nouvel-azerty/commit/f78cf6656ea32788a3471deba3d7270498b50606)
	* Accent aigu : Redonder "‐" U+2010. compose-1.yml [7cd3b81](https://github.com/dispoclavier/nouvel-azerty/commit/7cd3b81d5b9a190685497ebecc97d1f8a554093e), [bf3eebe](https://github.com/dispoclavier/nouvel-azerty/commit/bf3eebe3de583f174f23edd62bd46e259c59be14), [87bcf36](https://github.com/dispoclavier/nouvel-azerty/commit/87bcf362d9ed82ac1b7f7a617ce0d501c54e57ae), [compose-2.yml [c93e8bf](https://github.com/dispoclavier/nouvel-azerty/commit/c93e8bf5832e199d1312fc77b37f8f7ae1409902), [4cc2b0f](https://github.com/dispoclavier/nouvel-azerty/commit/4cc2b0f272bf91f2610f3fa6ee869e24366e24d7), [78c6e15](https://github.com/dispoclavier/nouvel-azerty/commit/78c6e155a207c2ed93ba24d440c6945cbea25a0e)
	* Hatchek : Compléter l’accès par triple circonflexe. Supprimer l’accès par aigu & grave. compose-2.yml [979ccce](https://github.com/dispoclavier/nouvel-azerty/commit/979cccee963ac67a30ba4cb8a19feefad7dea1d1)
	* Corriger la sortie de substitution des surrogats hauts. compose-2.yml [c19705f](https://github.com/dispoclavier/nouvel-azerty/commit/c19705f9a7ecf799a3e144e210821f1bb98a6080), [efba5c0](https://github.com/dispoclavier/nouvel-azerty/commit/efba5c099f12af142eca83677f25bc5d9eec75f3)
* Documentation. compose-1.yml [724b285](https://github.com/dispoclavier/nouvel-azerty/commit/724b285d5c8c563ac2952eb9675fea24eeda1c0a), [76158ee](https://github.com/dispoclavier/nouvel-azerty/commit/76158eeef170093d4c4a3c6daa7e584ea2d087b4), [af5ee65](https://github.com/dispoclavier/nouvel-azerty/commit/af5ee65eef301805eb3c4a1a821a805de3f8aa7e), [e0f085c](https://github.com/dispoclavier/nouvel-azerty/commit/e0f085ccd8d0273b8807e260e34763ab1b78a572), compose-2.yml [698ebfc](https://github.com/dispoclavier/nouvel-azerty/commit/698ebfc32c7800fb04acaedd2a7b26aa3ce4d737), [2249134](https://github.com/dispoclavier/nouvel-azerty/commit/2249134782683f48aeb038737e0eb532bb49531a), [507e6aa](https://github.com/dispoclavier/nouvel-azerty/commit/507e6aa9606b2107e931798ab9ddc0c227a55bff), [f91efa7](https://github.com/dispoclavier/nouvel-azerty/commit/f91efa783594295cc0540101e5d43d7a9a9c3205), compose-3.yml [15df2c4](https://github.com/dispoclavier/nouvel-azerty/commit/15df2c48a5fcb07107401aa6e908103bc0f9ace0), dispocla.cpp [5e69dfe](https://github.com/dispoclavier/nouvel-azerty/commit/5e69dfea9bd7f3f3e7f2048702f621b992ed364f), evdev.c [504a113](https://github.com/dispoclavier/nouvel-azerty/commit/504a11346d86f3d0265e6c65aae1371c78eb9f87)

## 1.2.1 (2023-11-27)

* Disposition : Touches d’édition : Déboguer en supprimant la prise en charge dédiée. dispocla.cpp [636715c](https://github.com/dispoclavier/nouvel-azerty/commit/636715cccf34da2a46a448ab5651ae03e31c288c)
* Transformations :
	* Exposant : Redonder "ʼ" U+02BC. compose-2.yml [9e82a33](https://github.com/dispoclavier/nouvel-azerty/commit/9e82a33c55b5047c85ac0f36ba2f72568de5b719)
	* Accent aigu : Redonder "ʻ" U+02BB. ibidem
	* Accent grave : Redonder "ʻ" U+02BB. ibidem
	* Accent circonflexe : Redonder "ʼ" U+02BC. ibidem
	* Cédille & accent aigu : Supprimer l’autre sens. ibidem
* Documentation :
	* Mettre à jour l’ordre. compose-2.yml [5ddffe3](https://github.com/dispoclavier/nouvel-azerty/commit/5ddffe388e8be20d81bbd81da861ef6120d53f03)
	* Groupes des symboles. compose-3.yml [276e31b](https://github.com/dispoclavier/nouvel-azerty/commit/276e31bd42001ef8a81ad0b6c447b62fb2f6fee3), [20d4eb1](https://github.com/dispoclavier/nouvel-azerty/commit/20d4eb19bc94f0ffdac5bcf33dda98ce59733b13)
	* Raccourcis divers. compose-2.yml [392c4c2](https://github.com/dispoclavier/nouvel-azerty/commit/392c4c2799eb7a63fe05a90f9c85c5268585de6d), [9d176f4](https://github.com/dispoclavier/nouvel-azerty/commit/9d176f495b6a2bde64327a75a1e8902c233361fc), [cf4a229](https://github.com/dispoclavier/nouvel-azerty/commit/cf4a229f505a364b34d61460662b5f5b2d6816ee)

## 1.2.0 (2023-11-24)

* Disposition : Symboles ASCII : Permuter l’accent grave et le guillemet double générique. Faire suivre les touches mortes accent grave et double accent aigu, les symboles Ohm "Ω" U+2126 et seconde "″" U+2033, l’émoji "🙏" U+1F64F et la séquence "`&quot;`". dispocla.cpp [ae49244](https://github.com/dispoclavier/nouvel-azerty/commit/ae49244e89327c83d7b378263b497c25861a05b1), compose-2.yml [5744ed5](https://github.com/dispoclavier/nouvel-azerty/commit/5744ed5be30e0d99877f40ed568b37ba205164bc)
* Transformations :
	* Groupes des symboles : Mettre "〃" U+3003 à la place de "ʻ" U+02BB, qui prend la place de "∅" U+2205, qui prend la place de "∐" U+2210, qui prend la place de "⛱" U+26F1, qui prend la place de "〃" U+3003. compose-3.yml [3ba78ba](https://github.com/dispoclavier/nouvel-azerty/commit/3ba78baf08ddefad0ee43bc3f43aedcf7605ce2a)
	* Exposant & tourné & crosse : Ajouter "ʵ" U+02B5. compose-2.yml [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f)
	* Exposant & tourné & crochet rétroflexe : Supprimer "ʵ" U+02B5. Ajouter "𐞧" U+107A7, "ᶭ" U+1DAD. compose-2.yml [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f), [8352e4c](https://github.com/dispoclavier/nouvel-azerty/commit/8352e4cd28029bd24acaa748f65065b591f4c73f), [92cb3f3](https://github.com/dispoclavier/nouvel-azerty/commit/92cb3f321681ebb80beab86e353b203b6a4070af)
	* Ajouter des caractères morts. compose-2.yml [a1b26c5](https://github.com/dispoclavier/nouvel-azerty/commit/a1b26c57721bf2f38fbbef6e8eb0c1db01d7db14), [94d376f](https://github.com/dispoclavier/nouvel-azerty/commit/94d376f4000d1e3dae85ae1e0bf8c589db4a5b1b), [fd4f6c1](https://github.com/dispoclavier/nouvel-azerty/commit/fd4f6c122bd3369d69e3fad6ebacc9bff9c86a6f), [92cb3f3](https://github.com/dispoclavier/nouvel-azerty/commit/92cb3f321681ebb80beab86e353b203b6a4070af), [9d33559](https://github.com/dispoclavier/nouvel-azerty/commit/9d33559452dc9e8d114815f10990af47b60af000)
* Documentation :
	* Remplacer “mode numérique” par “mode ASCII”. compose-1.yml [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5), [2848aef](https://github.com/dispoclavier/nouvel-azerty/commit/2848aef41086e87be67b96d8a37b9da650ec2b8c), dispocla.cpp [636715c](https://github.com/dispoclavier/nouvel-azerty/commit/636715cccf34da2a46a448ab5651ae03e31c288c)
	* Réunir la composition nouvelle école. compose-1.yml [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5)
	* Variantes :
		* Expliciter les noms. dispocla.cpp [4f09162](https://github.com/dispoclavier/nouvel-azerty/commit/4f091624c6e6f197f53f67dafef56926edf893b1)
		* Redisposée :
			* Renommer de “Français redisposé disposition de clavier semi-automatique” en “Français France disposition de clavier semi-automatique redisposée”. evdev-additions.xml [a381f32](https://github.com/dispoclavier/nouvel-azerty/commit/a381f325a2b68bda0de3fec47610c99358623d8b), Lisez-moi-svp.txt [d7c5421](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5421fd76df47e17dd215da8ad0c0b237b8e60)
			* Changer l’identifiant de “kbfrFRr” en “kbfrFRsr”. dispocla.cpp [4f09162](https://github.com/dispoclavier/nouvel-azerty/commit/4f091624c6e6f197f53f67dafef56926edf893b1), evdev-additions.xml [a381f32](https://github.com/dispoclavier/nouvel-azerty/commit/a381f325a2b68bda0de3fec47610c99358623d8b), Lisez-moi-svp.txt [d7c5421](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5421fd76df47e17dd215da8ad0c0b237b8e60), et en rattrapage (1.3.0) compose-1.yml [edd54e1](https://github.com/dispoclavier/nouvel-azerty/commit/edd54e1af53ff129c4ee63050ad0b221e338d88f)
	* Transformations : Groupes des lettres. compose-3.yml [54c7301](https://github.com/dispoclavier/nouvel-azerty/commit/54c7301aa6c1fe864a81734e2cfb3f2ee7697082)
	* Divers. compose-1.yml [9f21e47](https://github.com/dispoclavier/nouvel-azerty/commit/9f21e47bda5d15596f3ed503c716ee838210424d), [cbc5a07](https://github.com/dispoclavier/nouvel-azerty/commit/cbc5a07f5f5bb54e16e428bde4b2a60fff084fbb), [a2b5934](https://github.com/dispoclavier/nouvel-azerty/commit/a2b5934277d391ab8050c3e795c1044a76ea54d5), [25fc451](https://github.com/dispoclavier/nouvel-azerty/commit/25fc451de7888e27e0122c815803d8c98b7a1355), compose-2.yml [37332a7](https://github.com/dispoclavier/nouvel-azerty/commit/37332a79b4ace3028d142391dcf054040a777a2f)

## 1.1.7 (2023-11-05)

Nouvelle répartition pour rester en dessous de 2 Mo par fichier. compose-1.yml [71a5e2d](https://github.com/dispoclavier/nouvel-azerty/commit/71a5e2d0c91c4359ad2e3d4fb4a35a6e1fbe62b4), compose-2.yml [8a64209](https://github.com/dispoclavier/nouvel-azerty/commit/8a64209bb0c0c63b70661b8b3ba11885af366bc7), compose-3.yml [60d1889](https://github.com/dispoclavier/nouvel-azerty/commit/60d1889ac60af7ce367b377b441a6dd97e97b82d)
* Composition :
	* Déboguer "⫴" U+2AF4, "⟧" U+27E7, "⋘" U+22D8. compose-1.yml [7d54a6f](https://github.com/dispoclavier/nouvel-azerty/commit/7d54a6f5cae08b862526e5b722282aa82980bc72) (aussi [1b197a0](https://github.com/dispoclavier/nouvel-azerty/commit/1b197a039e765268c3b80d609a3a3194c8698e88))
	* Ajouter la termination par espace insécable pour tous les symboles terminés par espace. ibidem
* Transformations : Hatchek > Hatchek souscrit : Ajouter "˰" U+02F0, "˱" U+02F1, "˲" U+02F2. compose-2.yml [c267636](https://github.com/dispoclavier/nouvel-azerty/commit/c267636c75deb04aef6efe56f1175dd17269dab9) (aussi [e29ce4d](https://github.com/dispoclavier/nouvel-azerty/commit/e29ce4d2b18f50002cdbaec02b08b6226f2a6f3d))

## 1.1.6 (2023-11-04)

* Transformations :
	* Exposant & crochet rétroflexe & sanglé : Dupliquer "𐞝" U+1079D depuis Exposant & crochet rétroflexe & brève. compose-1.yml [18ee048](https://github.com/dispoclavier/nouvel-azerty/commit/18ee0489ab9b4e355702b29b75a3871af9fa458d)
	* Crochet rétroflexe & groupe 4 : Supprimer "ꞎ" U+A78E. ibidem
	* Crochet rétroflexe & sanglé : Dupliquer "ꞎ" U+A78E depuis Crochet rétroflexe & brève. ibidem
	* Brève > Sanglé : Remplacer "‿" U+203F par "⏑" U+23D1. ibidem
	* Brève > Sanglé & crochet palatal : Dupliquer "𝼓" U+1DF13 depuis Brève & crochet palatal. ibidem
	* Rayé > Raie haute : Ajouter "͆" U+0346, "˂" U+02C2, "˃" U+02C3, "˄" U+02C4, "˅" U+02C5. ibidem
	* Crochet en chef > Glottal : Ajouter "҆" U+0486, "᾿" U+1FBF. ibidem
	* Macron > Ligne souscrite : Déplacer ici depuis Indice > Ligne souscrite. ibidem
	* Barré > Barre courte, Double barre : Permuter les identifiants et les diacritiques. ibidem
	* Hatchek > Hatchek souscrit : Ajouter "˯" U+02EF. compose-2.yml [55e43b0](https://github.com/dispoclavier/nouvel-azerty/commit/55e43b09032bedfd58393d985a58a3ee8a0024e0)
	* Cédille > Cédille en chef : Ajouter "ʻ" U+02BB. ibidem
	* Tréma > Tréma souscrit : Ajouter "˸" U+02F8. ibidem
	* Virgule souscrite, Virgule souscrite > Virgule en chef : Redonder "Ꞻ" U+A7BA, "ꞻ" U+A7BB, "Ꞽ" U+A7BC, "ꞽ" U+A7BD, "Ꞿ" U+A7BE, "ꞿ" U+A7BF. ibidem

## 1.1.5 (2023-11-02)

* Sous-variantes : Verrouillage capitales : Remettre sur la touche traditionnelle par défaut, corriger l’erreur de la v1.1.2. evdev.c [d9a7bc0](https://github.com/dispoclavier/nouvel-azerty/commit/d9a7bc0bb805d0e1b1f736b2f2799f63bf48d56f)
* Composition : Déboguer "⦄" U+2984, "⫻" U+2AFB. compose-1.yml [3714679](https://github.com/dispoclavier/nouvel-azerty/commit/3714679605da4b54b7c5d0135b54beea2163aea2)
* Transformations :
	* Crochet rétroflexe > Crochet palatal : Déboguer "˽" U+02FD. ibidem
	* Barré > Double barré : Remplacer "̷" U+0337 par "⃫" U+20EB. compose-1.yml [b8b45a7](https://github.com/dispoclavier/nouvel-azerty/commit/b8b45a79f9065549de0d40fce143ef5df62c6acf) ; associé : compose-2.yml [2d52334](https://github.com/dispoclavier/nouvel-azerty/commit/2d52334a4f816b6c987dff9d786abf5141f7d6a3)
	* Ajouter Courte barre avec "̷" U+0337 et "ꜙ" U+A719. ibidem
* Transformations :
	* Crosse > Bouclé : Ajouter "͚" U+035A, "˓" U+02D3, "˒" U+02D2. compose-1.yml [9f8d263](https://github.com/dispoclavier/nouvel-azerty/commit/9f8d26396908e33a41594afffbfcb88ea958a64e)
	* Crosse > Fioriture : Ajouter "͚" U+035A, "˓" U+02D3, "˒" U+02D2. ibidem
	* Crochet rétroflexe > Paraphe : Ajouter "͜" U+035C, "‿" U+203F. ibidem
* Documentation. compose-1.yml [9f8d263](https://github.com/dispoclavier/nouvel-azerty/commit/9f8d26396908e33a41594afffbfcb88ea958a64e), compose-2.yml [b911cae](https://github.com/dispoclavier/nouvel-azerty/commit/b911caebaeeae8c72710626314cf4ed764ba269b)

## 1.1.4 (2023-11-01)

* Transformations :
	* Permuter les séquences avec espace fine insécable et espace insécable pour corriger l’affichage des tableaux. compose-1.yml [6bfb758](https://github.com/dispoclavier/nouvel-azerty/commit/6bfb7585f90d7bb66a4d4639f7c73a437e7f97bd), compose-2.yml [77ca45c](https://github.com/dispoclavier/nouvel-azerty/commit/77ca45c867df4309ca182dae5bdbce9a4ce6d999)
	* Tourné : Remplacer "≀" U+2240 par "ⸯ" U+2E2F. ibidem
	* Point en chef : Ajouter "˙" U+02D9 par espace insécable. ibidem
	* Rond en chef : Ajouter "⸰" U+2E30 par ".". ibidem
	* Point souscrit : Ajouter "⸳" U+2E33 par espace insécable et espace fine insécable. ibidem
	* Virgule souscrite : Ajouter "⸴" U+2E34 par espace insécable et espace fine insécable. ibidem
	* Drapeau :
		* Remplacer "‌" U+200C par "⚐" U+2690 avec les caractères de base espace ou césure conditionnelle. compose-2.yml [581516e](https://github.com/dispoclavier/nouvel-azerty/commit/581516edbf0de795d92989216ef7900222560427)
		* Ajouter "⚑" U+2691 et "🏴" U+1F3F4. ibidem
		* Corriger la casse. ibidem
* Transformations :
	* Exposant : Ajouter "‾" U+203E. compose-1.yml [f3e6573](https://github.com/dispoclavier/nouvel-azerty/commit/f3e65739016c562854b0644bc9a9d1ac95e049bf)
	* Exposant > Suscrit :
		* Remplacer "̎" U+030E par "̿" U+033F. ibidem
		* Ajouter "﹌" U+FE4C, "﹋" U+FE4B. ibidem
	* Tourné : Ajouter "ʻ" U+02BB. ibidem
	* Tourné > Inversé : Ajouter "̕" U+0315, "ʼ" U+02BC. ibidem
	* Crosse : Ajouter "˽" U+02FD. ibidem
	* Crochet rétroflexe : Ajouter "˾" U+02FE. ibidem
	* Crochet palatal : Ajouter "˽" U+02FD. ibidem
	* Tilde > Double tilde médian : Ajouter "~". ibidem
	* Grec/cerclé : Ajouter "ι" U+03B9 par espace insécable ou espace fine insécable. ibidem
	* Grec > Cerclé : Ajouter  "⃝" U+20DD, "⚪" U+26AA. ibidem
	* Point en chef > Ligne verticale en chef : Ajouter "̎" U+030E, "ˈ" U+02C8. ibidem
	* Brève inversée > Brève inversée souscrite : Ajouter "⁔" U+2054. ibidem
	* Brève > Brève souscrite : Ajouter "‿" U+203F. ibidem
	* Rayé > Double raie : Ajouter "꞊" U+A78A. ibidem
	* Cornu > Double cornu : Supprimer "᫉" U+1AC9, "᫊" U+1ACA. ibidem
	* Crochet en chef : Ajouter "ʾ" U+02BE, "ʿ" U+02BF. ibidem
	* Réfléchi : Ajouter "ʽ" U+02BD. compose-2.yml [5cd31ad](https://github.com/dispoclavier/nouvel-azerty/commit/5cd31ad2cdfa4d1988dc42dd50372a9c5d729cab)
	* Virgule souscrite > Virgule en chef : Ajouter "ʼ" U+02BC. ibidem

## 1.1.3 (2023-10-31)

* Transformations :
	* Grec/cerclé : Ajouter le iota souscrit avec les caractères de base espace ou césure conditionnelle. compose-1.yml [c54e67a](https://github.com/dispoclavier/nouvel-azerty/commit/c54e67aedb7fa430a9fbf532734412a4b287af4e)
	* Drapeau : Doubler l’antiliant "‌" U+200C avec les caractères de base espace ou césure conditionnelle. compose-2.yml [5621bee](https://github.com/dispoclavier/nouvel-azerty/commit/5621bee680e37b31f1752497cf1e6007cdd5bb9d)
* Documentation. compose-1.yml [c54e67a](https://github.com/dispoclavier/nouvel-azerty/commit/c54e67aedb7fa430a9fbf532734412a4b287af4e), [9238b44](https://github.com/dispoclavier/nouvel-azerty/commit/9238b44d970de629389f5b21cb0b8c4011e6233e), compose-2.yml [9905833](https://github.com/dispoclavier/nouvel-azerty/commit/99058337ad8a2b2872b44ae380a6a7258cf07717)

## 1.1.2 (2023-10-29)

* Transformations :
	* Tourné barré groupe 3 : Déboguer "ꭄ" U+AB44. compose-1.yml [2d88a4a](https://github.com/dispoclavier/nouvel-azerty/commit/2d88a4a349f9f36fa38520e9e6ccfba219fbaa1a)
* Transformations :
	* Point en chef > Ligne verticale en chef : Ajouter le diacritique "̍" U+030D. compose-1.yml [fba48cd](https://github.com/dispoclavier/nouvel-azerty/commit/fba48cd1cb74cb3d6806ed17003e67bcb701d418)
	* Virgule souscrite > Virgule en chef : Remplacer "̔" U+0314 par "̕" U+0315. compose-2.yml [f683794](https://github.com/dispoclavier/nouvel-azerty/commit/f683794097e02e2df794f6d179af2b7b93c496b1)
* Sous-variantes :
	* Rajouter les sous-variantes avec Effacement arrière sur Menu sans permutation. evdev.c [668cd26](https://github.com/dispoclavier/nouvel-azerty/commit/668cd264f8cbdac7fb3b09752c7b063ec1a36c75), comp.sh [886a1f2](https://github.com/dispoclavier/nouvel-azerty/commit/886a1f21bda5d9dac6a2ba67459b92efcd95d910)
	* Ajouter des sous-variantes avec VerrCap et touche ISO permutées et avec Effacement arrière sur Menu sans permutation. evdev.c [b57016c](https://github.com/dispoclavier/nouvel-azerty/commit/b57016c6c0d14aef8275f8b2619eac73fef99224), comp.sh [76bca78](https://github.com/dispoclavier/nouvel-azerty/commit/76bca78b35213b2a75efbd42493b3ba5ac47459e)

## 1.1.1 (2023-10-27)

* Transformations : Corriger la répartition des diacritiques combinants. compose-1.yml [c279c4e](https://github.com/dispoclavier/nouvel-azerty/commit/c279c4e671677025e2381d9f92478b9239d6b29c), compose-2.yml [403ceca](https://github.com/dispoclavier/nouvel-azerty/commit/403ceca95b46d3559d6fb1b0f7039c61a0b73fc2)
	* Exposant : Remplacer "̍" U+030D par "̅" U+0305. ibidem
	* Tourné : Remplacer "̅" U+0305 par "̒" U+0312. ibidem
	* Réfléchi : Ajouter "̔" U+0314. ibidem
* Sources de disposition fusionnées : Limiter les touches sans symboles à AB11 et AE13. evdev.c [fcdee06](https://github.com/dispoclavier/nouvel-azerty/commit/fcdee06e45540fc039bca322aeb581d7206e7a8c)
* Sous-variantes : Permuter correctement la touche d’Effacement arrière. evdev.c [d5068d3](https://github.com/dispoclavier/nouvel-azerty/commit/d5068d3580a84fce5b5e5a8c258e69305fa8c524)

## 1.1.0 (2023-10-24)

* Sous-variantes :
	* Ajouter des sous-variantes avec Effacement arrière sur Menu ou sur Contrôle droite. evdev.c [e62f925](https://github.com/dispoclavier/nouvel-azerty/commit/e62f925935d81418d2642e5adfd4d37debafdc29), [0f8e732](https://github.com/dispoclavier/nouvel-azerty/commit/0f8e7327dcf48e8561580cd0d21ea03a37bdc1df), [cae8105](https://github.com/dispoclavier/nouvel-azerty/commit/cae8105b2e3655b6f959861816cf04325d34b332)
	* Ajouter des sous-variantes avec Effacement arrière sur Menu pour claviers ANSI en AZERTY. ibidem
	* Améliorer les suffixes. ibidem
* Transformations :
	* Crochet palatal : Ajouter le diacritique combinant "̡" U+0321. compose-1.yml [57644a5](https://github.com/dispoclavier/nouvel-azerty/commit/57644a5f6bebe6e0e5797df9ef3a9e7260361751)
	* Tourné : Ajouter "ꓭ" U+A4ED, "ꓷ" U+A4F7, "ꓩ" U+A4E9, "ꓠ" U+A4E0, "ꓳ" U+A4F3, "ꓒ" U+A4D2, "ꓤ" U+A4E4, "ꓢ" U+A4E2, "ꓵ" U+A4F5, "ꓫ" U+A4EB, "ꓜ" U+A4DC. ibidem
	* Inversé :
		* Ajouter "ꓯ" U+A4EF, "ꓭ" U+A4ED, "ꓛ" U+A4DB, "ꓷ" U+A4F7, "ꓱ" U+A4F1, "ꓞ" U+A4DE, "ꓨ" U+A4E8, "ꓧ" U+A4E7, "ꓲ" U+A4F2, "ꓩ" U+A4E9, "ꓘ" U+A4D8, "ꓶ" U+A4F6, "ꓠ" U+A4E0, "ꓳ" U+A4F3, "ꓒ" U+A4D2, "ꓤ" U+A4E4, "ꓢ" U+A4E2, "ꓕ" U+A4D5, "ꓵ" U+A4F5, "ꓥ" U+A4E5, "ꓫ" U+A4EB, "𑾰" U+11FB0, "ꓜ" U+A4DC. ibidem
		* Supprimer "Ɐ" U+2C6F, "ꟷ" U+A7F7, "ʁ" U+0281. ibidem
	* Tréma : Redonder "Ø" U+00D8, "ø" U+00F8. compose-2.yml [3068d68](https://github.com/dispoclavier/nouvel-azerty/commit/3068d686bf5ecfc2c7dc153da98f7bd5812c4f3e)
* Documentation. compose-1.yml [57644a5](https://github.com/dispoclavier/nouvel-azerty/commit/57644a5f6bebe6e0e5797df9ef3a9e7260361751), [40b9b8f](https://github.com/dispoclavier/nouvel-azerty/commit/40b9b8fef20fa0c0d615fb68d3433994d2f90442), compose-2.yml [419310d](https://github.com/dispoclavier/nouvel-azerty/commit/419310d3cc5aefaf16584f1c3bee10677f94ff57)

## 1.0.14 (2023-09-29)

* Sous-variantes : Effacement arrière : Remettre sur la touche traditionnelle. evdev.c [375b83a](https://github.com/dispoclavier/nouvel-azerty/commit/375b83a11353f6135d39b65a2eca085400de34ee), annule [0559e8f](https://github.com/dispoclavier/nouvel-azerty/commit/0559e8ff5b8b34ce91f775624f6293e0a8f98973)
* Documentation : Mettre en sourdine la prise en charge de ChromeOS.

## 1.0.13 (2023-09-27)

* Composition :
	* Déboguer "ſ" U+017F, "ȸ" U+0238, "₳" U+20B3, "❜" U+275C. "⸺" U+2E3A, "⸻" U+2E3B. compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Déboguer "↉" U+2189. compose-1.yml [dc23892](https://github.com/dispoclavier/nouvel-azerty/commit/dc23892ccbd2b0fd6e51daf7cf1bca44cd4095c2)
	* Corriger "○" U+25CB, "●" U+25CF, "◑" U+25D1, "◔" U+25D4, "◕" U+25D5, "◴" U+25F4, "◵" U+25F5, "◶" U+25F6, "◷" U+25F7. ibidem
	* Adapter "⇉" U+21C9, "⇶" U+21F6, "≅" U+2245, "≆" U+2246, "⤐" U+2910, "⤳" U+2933, "⥱" U+2971. "⧇" U+29C7, "⨣" U+2A23, "⨺" U+2A3A, "⩰" U+2A70, "⫐" U+2AD0, "⫒" U+2AD2. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0)
	* Supprimer "⁨" U+2068 par « ¦fsi », "₫" U+20AB par « ¦D= » (maintenu par « ¦d= »), "⋒" U+22D2 par « ¦dblcap », "⋓" U+22D3 par « ¦dblcup ». ibidem
	* Supprimer "¦" U+00A6 par « ¦|: » et par « ¦:| ». compose-1.yml [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df)
	* Déboguer "⊼" U+22BC, "⍽" U+237D. compose-1.yml [c8eb228](https://github.com/dispoclavier/nouvel-azerty/commit/c8eb2280b056d964ad08ef28681c19487db958ad)
	* Adapter "⇭" U+21ED, "⊼" U+22BC, "♠" U+2660, "⟤" U+27E4, "⪤" U+2AA4, "⪥" U+2AA5, "⭄" U+2B44. ibidem
	* Supprimer "♭" U+266D par « ¦-# », "♯" U+266F par « ¦+# ». ibidem
	* Déboguer "♥" U+2665, "ꝴ" U+A774. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8), [5975c24](https://github.com/dispoclavier/nouvel-azerty/commit/5975c24f4c36c04838752189b746bc9b0843f3d6)
	* Adapter "♧" U+2667. ibidem
	* Déboguer "ꝴ" U+A774. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
	* Adapter "⪛" U+2A9B, "⪜" U+2A9C, "⫍" U+2ACD, "⫎" U+2ACE. ibidem
	* Supprimer " " U+00A0 par « ¦␣␣ », "␣" U+2423 par « ¦␣⍽ », " " U+202F par « ¦␣ ». à cause de conflits. ibidem
	* Adapter "≎" U+224E, "⨧" U+2A27. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
	* Supprimer U+202D par « ¦o> », U+202E par « ¦o< », "🄯" U+1F12F par « ¦%oc » (maintenu par « ¦%OC »). compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
	* Supprimer la termination par espace pour les séquences les plus longues. compose-1.yml [be9366c](https://github.com/dispoclavier/nouvel-azerty/commit/be9366ce76362789212a21f5df80d4856c0c9b5a)
* Transformations : Supprimer l’affichage des caractères morts. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b), compose-2.yml [eb82120](https://github.com/dispoclavier/nouvel-azerty/commit/eb82120550714a3344f22305821e6a409b62e891)
	* Groupes des symboles :
		* Supprimer "" U+000B, y déplacer "▢" U+25A2. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Déredonder "□" U+25A1 et "■" U+25A0, y redonder "☐" U+2610, "☑" U+2611, "☒" U+2612. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Déboguer "ʼ" U+02BC par « ¦#' », "∼" U+223C par « ¦#~ », "ˑ" U+02D1 par « ¦#: », "ʻ" U+02BB par « ¦#` », "✘" U+2718 par « ¦#< ». compose-1.yml [dc0a154](https://github.com/dispoclavier/nouvel-azerty/commit/dc0a15485cc60e631a9f03e515c6a5aca5bc3218), compose-2.yml [e3af08f](https://github.com/dispoclavier/nouvel-azerty/commit/e3af08fbc8f2415e9661b14eab326e074f2269d1)
		* Supprimer les accès rapides par touche morte diacritique. ibidem
	* Exposant :
		* Ajouter "᫈" U+1AC8. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Déboguer "⁺" U+207A, "⁻" U+207B, "⁾" U+207E. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Tourné : Déboguer "ᴑ" U+1D11.
	* Réfléchi :
		* Supprimer "∽" U+223D et les "❶" U+2776 à "❿" U+277F redondés. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Déplacer ici "∖" U+2216, "⟍" U+27CD, "⧵" U+29F5. "⧹" U+29F9, (ibidem)
	* Tilde :
		* Déboguer "≃" U+2243, "≈" U+2248. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "̰" U+0330, "̴" U+0334. ibidem
	* Grec/cerclé :
		* Déboguer "⊖" U+2296. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "❶" U+2776 à "❿" U+277F. ibidem
	* Accent aigu : Adapter "˶" U+02F6. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Brève inversée :
		* Déboguer "˓" U+02D3, "͡" U+0361. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Supprimer "˒" U+02D2. ibidem
		* Déboguer "͡" U+0361. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
		* Adapter "᷼" U+1DFC. ibidem
	* Brève :
		* Déboguer "˒" U+02D2. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Supprimer "˓" U+02D3. ibidem
		* Adapter "͝" U+035D, "͜" U+035C. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
	* Rayé:
		* Déboguer "⁅" U+2045, "⁆" U+2046, "ꜻ" U+A73B, "ꞓ" U+A793. compose-1.yml [c8eb228](https://github.com/dispoclavier/nouvel-azerty/commit/c8eb2280b056d964ad08ef28681c19487db958ad)
		* Supprimer "⊼" U+22BC dans le groupe 0. ibidem
		* Déboguer "⁆" U+2046.
	* Cornu/cramponné/cranté :
		* Supprimer "̟" U+031F, "᫈" U+1AC8. compose-1.yml [ce7072e](https://github.com/dispoclavier/nouvel-azerty/commit/ce7072e6c127c02426129ede66c4bca73542995b)
		* Déboguer "↓" U+2193.
	* Indice : Déboguer "͔" U+0354, "͕" U+0355, "₋" U+208B, "₎" U+208E.
	* Ogonek : Déboguer "ǫ" U+01EB. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Macron : Déboguer "ƃ" U+0183. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Barré :
		* Supprimer "∤" U+2224 et "≁" U+2241 dans le groupe 0. compose-1.yml [76bd931](https://github.com/dispoclavier/nouvel-azerty/commit/76bd931410ab9bc143b0c19cbcadd593b8446a48)
		* Déplacer "≠" U+2260, "≮" U+226E et "≯" U+226F dans le groupe 1. ibidem
		* Supprimer les flèches émojis redondées. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Déplacer ici "⁄" U+2044. "∕" U+2215, "⟋" U+27CB, "⧸" U+29F8, (ibidem)
	* Rond en chef : Déboguer "∮" U+222E. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Accent circonflexe :
		* Déboguer "❛" U+275B. compose-2.yml [a089368](https://github.com/dispoclavier/nouvel-azerty/commit/a0893686afff6fd180597a1dde2e0e3241b8aee8)
		* Supprimer "‌" U+200C par ".". ibidem
	* Hatchek : Déboguer "̬" U+032C. ibidem
	* Hatchek : Déboguer "₀" U+2080. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Drapeau : Déboguer "⹀" U+2E40. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Accent grave :
		* Déboguer "˴" U+02F4. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
		* Adapter "˵" U+02F5. ibidem
	* Tréma : Supprimer "≤" U+2264."≥" U+2265, "⊆" U+2286. compose-1.yml [93c9fe6](https://github.com/dispoclavier/nouvel-azerty/commit/93c9fe6483f8a0a75e6b604da4b1a087614721a0), [b35266a](https://github.com/dispoclavier/nouvel-azerty/commit/b35266aa9928dfd426678be46690cc88d53888df), compose-2.yml [6560a3a](https://github.com/dispoclavier/nouvel-azerty/commit/6560a3a379683d9146307c29fbe6c4fae9c544d9)
	* Améliorer le rendu des surrogats hauts sous les systèmes ne les utilisant pas. compose-1.yml [fb60dfb](https://github.com/dispoclavier/nouvel-azerty/commit/fb60dfb6edac409a1309a97cdc0f54cebc0f5862), compose-2.yml [80d347c](https://github.com/dispoclavier/nouvel-azerty/commit/80d347cf92bd6913981506e7f2879603921258e9)
* Documentation : Ajouter des caractères morts. compose-1.yml [be9366c](https://github.com/dispoclavier/nouvel-azerty/commit/be9366ce76362789212a21f5df80d4856c0c9b5a)

## 1.0.12 (2023-09-23)

* Composition :
	* Déboguer "¢" U+00A2. compose-1.yml [43ee671](https://github.com/dispoclavier/nouvel-azerty/commit/43ee671a295299b8d2c6dea90cf3bd7aa5c59a4f), compose-2.yml [addb73e](https://github.com/dispoclavier/nouvel-azerty/commit/addb73ef888be119bbfa9063147a81b1a78f0d8d)
	* Déboguer "⟮" U+27EE, "⟯" U+27EF, "‬" U+202C, "≛" U+225B, "⋊" U+22CA, "◁" U+25C1, "⟜" U+27DC, "⦧" U+29A7. ibidem
* Transformations :
	* Exposant : Déboguer "̽" U+033D. ibidem
	* Grec/cerclé : Supprimer l’accord rayé-crochet rétroflexe. ibidem
	* Groupe : Déboguer les caractères morts "①" U+2460 à "⑫" U+246B. ibidem
	* Point souscrit : Déboguer "̍" U+030D. ibidem
	* Tréma : Supprimer "‖" U+2016 par "|". ibidem

## 1.0.11 (2023-09-19)

* Transformations :
	* Double accent aigu : Redonder "⓵" U+24F5 à "⓾" U+24FE. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Réfléchi : Redonder "❶" U+2776 à "❿" U+277F. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Brève inversée : Déboguer "͡" U+0361. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Brève inversée souscrite : Ajouter "᷼" U+1DFC. ibidem
	* Brève : Adapter "͝" U+035D. ibidem
	* Brève souscrite : Adapter "͜" U+035C. ibidem
	* Rayé : Corriger les séquences avec chiffre du pavé numérique. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Cornu/cramponné/cranté : Redonder "←" U+2190 à "↙" U+2199. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Cornu/cramponné/cranté : Corriger les séquences avec chiffre du pavé numérique. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Ogonek : Redonder "➀" U+2780 à "➉" U+2789. ibidem
	* Crochet en chef : Redonder "➊" U+278A à "➓" U+2793. ibidem
	* Macron : Redonder "⫾" U+2AFE, "∣" U+2223, "‖" U+2016, "⦀" U+2980, "∥" U+2225, "¦" U+00A6, "⫴" U+2AF4, "⫿" U+2AFF, "⏸" U+23F8, "⫼" U+2AFC. ibidem
	* Barré : Redonder les émojis flèches "↕" U+2195, "↙" U+2199, "⬇" U+2B07, "↘" U+2198, "⬅" U+2B05, "↔" U+2194, "➡" U+27A1, "↖" U+2196, "⬆" U+2B06, "↗" U+2197. ibidem
	* Rond en chef : Corriger les séquences avec chiffre du pavé numérique. ibidem
	* Accent circonflexe : Redonder "❤" U+2764 et "♠" U+2660 à "♧" U+2667. ibidem
	* Drapeau : Redonder "⇐" U+21D0 à "⇙" U+21D9. compose-1.yml [0621f67](https://github.com/dispoclavier/nouvel-azerty/commit/0621f676489af0ccc1ac2d8cf96e0208c73ffc50), compose-2.yml [d60c810](https://github.com/dispoclavier/nouvel-azerty/commit/d60c810371d83c17f60b1040a22b95f9ef2faa83)
	* Cédille : Ajouter "⒈" U+2488 à "⒑" U+2491. compose-1.yml [60e7148](https://github.com/dispoclavier/nouvel-azerty/commit/60e7148c1ba8c54745cf17993625dc2135f8f733), compose-2.yml [2ca90bf](https://github.com/dispoclavier/nouvel-azerty/commit/2ca90bf0054af91b80128a7210cd75c0d18a5808)
	* Virgule souscrite : Ajouter "⒒" U+2492 à "⒛" U+249B. ibidem
* Documentation : Corriger et déployer l’information sur la configuration de la disposition de clavier de login. dispocla.cpp [66f0650](https://github.com/dispoclavier/nouvel-azerty/commit/66f065004e61d650dac7481400a1054cda27d99b), [7e12e97](https://github.com/dispoclavier/nouvel-azerty/commit/7e12e9739dfc10dd36b65350a1396a8d4bf58808) ; [7e12e97](https://github.com/dispoclavier/nouvel-azerty/commit/7e12e9739dfc10dd36b65350a1396a8d4bf58808) (1.7.1)

## 1.0.10 (2023-09-07)

* Transformations : Groupes des symboles :
	* Ajouter "―" U+2015 dans le groupe 1 du tiret bas. compose-1.yml [dab5b38](https://github.com/dispoclavier/nouvel-azerty/commit/dab5b38dfd2792fc739926bbcb7b00682b123de0), [05e88f5](https://github.com/dispoclavier/nouvel-azerty/commit/05e88f5ba6f33b0cbad3d0a80f906a626e928f53), compose-2.yml [585d0de](https://github.com/dispoclavier/nouvel-azerty/commit/585d0dee67043d97c4ef7b23f8afdb375bacc95a)
	* Supprimer les séparateurs de ligne " " U+2028 et de paragraphe " " U+2029. ibidem
	* Déplacer "➢" U+27A2, "➲" U+27B2, "▪" U+25AA, "‣" U+2023, "◦" U+25E6, "•" U+2022, "❖" U+2756, "⮊" U+2B8A, "¦" U+00A6, "⛰" U+26F0, "⏯" U+23EF, "✅" U+2705, "⛛" U+26DB, "⌘" U+2318 l’un à la place de l’autre. ibidem
	* Supprimer "±" U+00B1, "∓" U+2213, "₊" U+208A, "₋" U+208B. ibidem
	* Déplacer "˖" U+02D6. ibidem
	* Ajouter "✚" U+271A, "✙" U+2719, "✜" U+271C, "➸" U+27B8, "➟" U+279F. ibidem
* Documentation. ibidem, dispocla.cpp [e2a5f4a](https://github.com/dispoclavier/nouvel-azerty/commit/e2a5f4a7c50836b19c106d1013eac6ced86d34a7)

## 1.0.9 (2023-08-31)

* Disposition :
	* Redonder "§" U+00A7 sur Maj + AltFr + S. Déplacer "😒" U+1F612 de là sur AltGr + AltFr + B07 en mode français, "💙" U+1F499 de là sur Maj + AltGr + AltFr + B07 en mode français. dispocla.cpp [a7fc71a](https://github.com/dispoclavier/nouvel-azerty/commit/a7fc71a1d1437f2fc70b6892acac377c9f1f6af3), [93162ea](https://github.com/dispoclavier/nouvel-azerty/commit/93162ea09f509de0d3fc4bb9978ad31c4bf924a6)
	* Ajouter l’antiliant "‌" U+200C (seulement par touche morte jusqu’alors) sur Maj + AltFr + X. Déplacer le deux-points isolé redondé de là sur Maj + AltFr + W, "😢" U+1F622 de là sur Maj + AltGr + AltFr + W, "😭" U+1F62D de là sur AltGr + AltFr + B08 en mode français, "📢" U+1F4E2 de là sur Maj + AltGr + AltFr + B08 en mode numérique. Y supprimer "📣" U+1F4E3 (reste en mode français). dispocla.cpp [2cfd78d](https://github.com/dispoclavier/nouvel-azerty/commit/2cfd78d8032af18c8cd8b5cb62da647a4b034d11)
	* Redonder "⁄" U+2044 sur Maj + AltFr + Q. Déplacer "😐" U+1F610 de là sur Maj + AltGr + AltFr + Q. Y supprimer "😑" U+1F611. ibidem
* Transformations :
	* Tréma : Ajouter "‐" U+2010, "⸺" U+2E3A et "⸻" U+2E3B. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)
	* Groupe :
		* Ajouter "⸺" U+2E3A et "⸻" U+2E3B. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)
		* Déboguer "⸺" U+2E3A et "⸻" U+2E3B. compose-1.yml [c6f07b4](https://github.com/dispoclavier/nouvel-azerty/commit/c6f07b4569493d0b61077b5dc26084abcf28b3d5), [30057ba](https://github.com/dispoclavier/nouvel-azerty/commit/30057baa78f59f138c37354dae50055d0300e6e3), [ac69cd2](https://github.com/dispoclavier/nouvel-azerty/commit/ac69cd2e83e76df89d7727dbced63cddf23ac077)
		* Ajouter les jeux de flèches "⭰" U+2B70.."⭹" U+2B79 avec "⭾" U+2B7E et "⭿" U+2B7F, "🡠" U+1F860.."🡧" U+1F867 et "🢀" U+1F880.."🢇" U+1F887. compose-1.yml [910f538](https://github.com/dispoclavier/nouvel-azerty/commit/910f53879f91627ebb33def3cf7b4127b2da6647)
	* Déboguer les surrogats hauts. compose-2.yml [02ef351](https://github.com/dispoclavier/nouvel-azerty/commit/02ef3514ec2ccfb4efff8070cc1dbf58d4e4439f)
* Documentation : Corriger les commentaires (aussi pour les tableaux), équilibrer le contenu de la sélectrice de groupe. compose-1.yml [aac2dd6](https://github.com/dispoclavier/nouvel-azerty/commit/aac2dd6d65ccff619d0a2b9c718ef072ea23d408), [3b89562](https://github.com/dispoclavier/nouvel-azerty/commit/3b89562fd042be2e400b526349ae946745ef2454), [ac3fb81](https://github.com/dispoclavier/nouvel-azerty/commit/ac3fb812af391ce90941c8dae47f5b819a4d4b9d), [c6f07b4](https://github.com/dispoclavier/nouvel-azerty/commit/c6f07b4569493d0b61077b5dc26084abcf28b3d5), [30057ba](https://github.com/dispoclavier/nouvel-azerty/commit/30057baa78f59f138c37354dae50055d0300e6e3), [ac69cd2](https://github.com/dispoclavier/nouvel-azerty/commit/ac69cd2e83e76df89d7727dbced63cddf23ac077), compose-2.yml [c21a6c0](https://github.com/dispoclavier/nouvel-azerty/commit/c21a6c06dd2f73dcaf78da757ae5c7ab706fb5f8), [efd6e96](https://github.com/dispoclavier/nouvel-azerty/commit/efd6e96415eee69fc49c78793d3151bcae5fd10c), [d56ee24](https://github.com/dispoclavier/nouvel-azerty/commit/d56ee249087c6e3c429ccb5f6f1c1889e86661d8)

## 1.0.8 (2023-08-27)

* Transformations :
	* Supprimer la prise en charge du point d’interrogation comme caractère de base pour la saisie des guillemets apostrophes dans leurs touches mortes. compose-1.yml [d73a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/d73a2e877787e841b733fedaf9c1de5cd1b44ebc), compose-2.yml [beaf6c5](https://github.com/dispoclavier/nouvel-azerty/commit/beaf6c58d307920314aad8768a409f25937161b3)
	* Tourné : Déboguer "⸸" U+2E38. compose-1.yml [80a6a10](https://github.com/dispoclavier/nouvel-azerty/commit/80a6a10be101dd59b093ba250fdb18a6e6465e3e)
	* Grec ou cerclé : Compléter les séquences. compose-1.yml [fc72f73](https://github.com/dispoclavier/nouvel-azerty/commit/fc72f73bb3683afa7e5984eb8181272e200b2ea5)
	* Crochet en chef : Ajouter  "⃣" U+20E3 en symétrie avec l’ogonek. compose-1.yml [57a3afb](https://github.com/dispoclavier/nouvel-azerty/commit/57a3afb33bdde161de0c0afd8fad558a65646053)
	* Barré : Redonder plus de lettres rayées dans les lacunes. compose-1.yml [8908dae](https://github.com/dispoclavier/nouvel-azerty/commit/8908daec75443b66846db6eec7c2d468476ad438)
	* Accent grave : Déboguer "‛" U+201B. compose-1.yml [76eb4ff](https://github.com/dispoclavier/nouvel-azerty/commit/76eb4ffc3965b091d5ae5100d810ba02377efcc5)
	* Accent grave > Double accent grave : Ajouter "⹂" U+2E42. compose-1.yml [fc72f73](https://github.com/dispoclavier/nouvel-azerty/commit/fc72f73bb3683afa7e5984eb8181272e200b2ea5)
	* Tréma + accent grave : Ajouter "⹂" U+2E42. compose-1.yml [462dd44](https://github.com/dispoclavier/nouvel-azerty/commit/462dd44d86069fdf2a9789d6eb7a4968a9f805c2), compose-2.yml [5b46c26](https://github.com/dispoclavier/nouvel-azerty/commit/5b46c2650afa1f96474fc61b56ef15755b37e991)
* Documentation :
	* Ranger guillemets et raccourcis. compose-1.yml [d73a2e8](https://github.com/dispoclavier/nouvel-azerty/commit/d73a2e877787e841b733fedaf9c1de5cd1b44ebc), compose-2.yml [beaf6c5](https://github.com/dispoclavier/nouvel-azerty/commit/beaf6c58d307920314aad8768a409f25937161b3)
	* Corriger l’ordre des caractères de base. compose-1.yml [462dd44](https://github.com/dispoclavier/nouvel-azerty/commit/462dd44d86069fdf2a9789d6eb7a4968a9f805c2), compose-2.yml [5b46c26](https://github.com/dispoclavier/nouvel-azerty/commit/5b46c2650afa1f96474fc61b56ef15755b37e991)
	* Transformations : Accent aigu + tréma, Cornu/cramponné/cranté : Supprimer 14 doublons. compose-1.yml [48f9e00](https://github.com/dispoclavier/nouvel-azerty/commit/48f9e00d106648f5e9167a22587ed2520fcfe1d0)

## 1.0.7 (2023-08-19)

* Composition :
	* Déboguer la saisie de "⎋" U+238B. compose-1.yml [5d3f7a6](https://github.com/dispoclavier/nouvel-azerty/commit/5d3f7a618c77f2e01d23def1d93efeac0722a7ec)
	* Ajouter le caractère de "▮" U+25AE (openrectbullet). compose-1.yml [c1d9ec1](https://github.com/dispoclavier/nouvel-azerty/commit/c1d9ec15431e67f09f93d1b81f52ffa866207b7c)
	* Ajouter les contrôles bidirectionnels manquants. compose-1.yml [b253e1f](https://github.com/dispoclavier/nouvel-azerty/commit/b253e1f1a02f88667875ac9ee50832f1150c4005)
	* Ajouter la séquence `en_US.UTF-8/Compose`. ibidem
* Transformations : Point souscrit : Alerter sur la confusion des glyphes entre "⸪" U+2E2A, "⸫" U+2E2B, "⸬" U+2E2C. compose-2.yml [1782bca](https://github.com/dispoclavier/nouvel-azerty/commit/1782bcaa2011deaa6f039302de3b2fa4f4b518c9)
* Personnalisation :
	* Simplifier le code de la barre d’espace. dispocla.cpp [4c4a106](https://github.com/dispoclavier/nouvel-azerty/commit/4c4a106ff4921c1adae901f0e5e3b6e54a076c47), dispotypes.c [763d8b0](https://github.com/dispoclavier/nouvel-azerty/commit/763d8b0dc11221c335c1375e59f3f28960901cee)
	* Simplifier le code des touches B07..B10. dispocla.cpp [84d81db](https://github.com/dispoclavier/nouvel-azerty/commit/84d81dbf7fd34ac78fbab69db294cbd344e4018f), [08a425e](https://github.com/dispoclavier/nouvel-azerty/commit/08a425e4646dda045406b199198c6484b9d4a3ed), dispotypes.c [5acd8f8](https://github.com/dispoclavier/nouvel-azerty/commit/5acd8f8bdaaca2543f1a07b65954f3490d04b4e6), [074154a](https://github.com/dispoclavier/nouvel-azerty/commit/074154a4411c635d4d7f0eabe53ac3d412766e84), [3537120](https://github.com/dispoclavier/nouvel-azerty/commit/3537120e6583430f167af227d775ff835dac995a), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0)
	* Simplifier le code des touches B01..B06, C01..D12. dispocla.cpp [9485620](https://github.com/dispoclavier/nouvel-azerty/commit/9485620a726089ad6268f93cb6bbf2e315d3af7a), [6198799](https://github.com/dispoclavier/nouvel-azerty/commit/6198799c997d10faaf65eedac93ca94c7a5b1b13), [907ff0e](https://github.com/dispoclavier/nouvel-azerty/commit/907ff0e6517603c96667415223bdde3d2b33802c), dispotypes.c [1246e6d](https://github.com/dispoclavier/nouvel-azerty/commit/1246e6d4cbb109329649f9740a2a22131e0054c0), [89f1d98](https://github.com/dispoclavier/nouvel-azerty/commit/89f1d9823390ef2b6548e234b410308b07eb36f5), [cb5ab2a](https://github.com/dispoclavier/nouvel-azerty/commit/cb5ab2af0e965736278c55d6d72b0751c4b4802f), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0)
* Variantes :
	* Supprimer provisoirement les 2 variantes pour le Canada et la variante pour la Suisse pour faciliter la maintenance. dispocla.cpp [bd73f72](https://github.com/dispoclavier/nouvel-azerty/commit/bd73f72760988046ca1c9fcdaeba0ff59e577408)
	* Supprimer définitivement les 3 variantes hybrides. dispocla.cpp [31919ac](https://github.com/dispoclavier/nouvel-azerty/commit/31919ac3fa37cfb3114762809c6ecd39f0f0d3b3)
* Sous-variantes : Effacement arrière : Déplacer sur Windows droite par erreur. evdev.c [0559e8f](https://github.com/dispoclavier/nouvel-azerty/commit/0559e8ff5b8b34ce91f775624f6293e0a8f98973)

## 1.0.6 (2023-08-15)

* Composition : Compléter les séquences de "♥" U+2665. compose-1.yml [26166c2](https://github.com/dispoclavier/nouvel-azerty/commit/26166c2b5740016b4265cce3db5e80aa7b130e49)
* Transformations :
	* Accent circonflexe : Désactiver les chiffres en exposant. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
	* Hatchek : Ajouter l’équivalent en composition des chiffres en indice. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
	* Point souscrit : Ajouter ces ponctuations et les compléter. compose-2.yml [310cbde](https://github.com/dispoclavier/nouvel-azerty/commit/310cbde97cd94aecaae1d39d8b8936cafd001f5b)
	* Tréma :
		* Ajouter les chiffres en exposant. compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123)
		* Supprimer les ponctuations à base de chiffres. compose-2.yml [310cbde](https://github.com/dispoclavier/nouvel-azerty/commit/310cbde97cd94aecaae1d39d8b8936cafd001f5b)
		* Supprimer "≔" U+2254, "⹀" U+2E40. compose-2.yml [c231922](https://github.com/dispoclavier/nouvel-azerty/commit/c231922e1e83a7c3073496fdf7ba50a0cb5c4bce)
	* Ajouter l’équivalent en composition partout où il manquait. Supprimer ou déplacer les séquences en conflit. compose-1.yml [45a1a5d](https://github.com/dispoclavier/nouvel-azerty/commit/45a1a5d2d0fc4b2efeaf3b8bd5d1cf6618bb015c), compose-2.yml [8a8db25](https://github.com/dispoclavier/nouvel-azerty/commit/8a8db25f6c2f20fc141dbd946d3a8059406f6bdc)
* Prendre en charge le pavé numérique dans les séquences de composition et de touches mortes. compose-1.yml [a45dd68](https://github.com/dispoclavier/nouvel-azerty/commit/a45dd684b7fe473a1a5ccd9a9c983691bf9970e3), compose-2.yml [4e15ea0](https://github.com/dispoclavier/nouvel-azerty/commit/4e15ea0ed390df4b30d15cf36c9912c832043989)

## 1.0.5 (2023-08-11)

* Composition :
	* Corriger les séquences de "⋶" U+22F6, "⋷" U+22F7, "⋽" U+22FD, "⋾" U+22FE. compose-1.yml [4bd82a7](https://github.com/dispoclavier/nouvel-azerty/commit/4bd82a7cba326cca12e43042fb9977488d522d00)
	* Résoudre les conflits de "Ƨ" U+01A7 à "ƅ" U+0185 avec "˩" U+02E9 à "˥" U+02E5. compose-1.yml [57c4a09](https://github.com/dispoclavier/nouvel-azerty/commit/57c4a09e0775f80f8c377131c1d3e928e27808a4)
	* Compléter les séquences de "˩" U+02E9 à "˥" U+02E5. ibidem
	* Résoudre le conflit de "🅭" U+1F16D avec "©" U+00A9. ibidem
	* Compléter les séquences de "🅯" U+1F16F. compose-1.yml [4dab06f](https://github.com/dispoclavier/nouvel-azerty/commit/4dab06f19342b00324d8a92aa1fba4348e31169c)
	* Compléter les séquences de "✀" U+2700 à "✄" U+2704. ibidem
	* Corriger la séquence de "♥️" U+2665. compose-1.yml [b9922dd](https://github.com/dispoclavier/nouvel-azerty/commit/b9922dd39253485c707e4047eb088987e505fea4)
	* Ôter le sélecteur de variante style émoji de la sortie de "♥" U+2665, "⚡" U+26A1 et "✴" U+2734. compose-1.yml [13eefac](https://github.com/dispoclavier/nouvel-azerty/commit/13eefacd48cf9e73fa36cde0d6e64ce5e32ff667), compose-2.yml [5c9eec9](https://github.com/dispoclavier/nouvel-azerty/commit/5c9eec960f100518f62b3c62e2a094473719fae1), [48372c5](https://github.com/dispoclavier/nouvel-azerty/commit/48372c506def69f974704d75084bcbdf6f3163bb)
	* Corriger les séquences de "‖" U+2016, "⃛" U+20DB, "⃜" U+20DC, "⇇" U+21C7, "⇇" U+21C7, "⇈" U+21C8, "⇉" U+21C9, "⇊" U+21CA, "⇶" U+21F6, "√" U+221A, "∛" U+221B, "∜" U+221C, "∬" U+222C, "∭" U+222D, "∯" U+222F, "∰" U+2230, "⋐" U+22D0, "⋑" U+22D1, "⋒" U+22D2, "⋓" U+22D3, "♠" U+2660, "♡" U+2661, "⟁" U+27C1, "⦀" U+2980, "⧈" U+29C8, "⧉" U+29C9, "⧻" U+29FB, "⨌" U+2A0C, "⩎" U+2A4E, "⩏" U+2A4F, "⩓" U+2A53, "⩔" U+2A54, "⪡" U+2AA1, "⪢" U+2AA2, "⪣" U+2AA3, "⫷" U+2AF7, "⫸" U+2AF8, "⬱" U+2B31. compose-1.yml [0ef0194](https://github.com/dispoclavier/nouvel-azerty/commit/0ef019419172a2b22b343a75241cda914335eca4)
	* Compléter les séquences de "★" U+2605, "☆" U+2606, "♀" U+2640, "♂" U+2642. ibidem
	* Corriger les séquences de  "⃮" U+20EE, "⃯" U+20EF, "ℏ" U+210F, "ℼ" U+213C, "ℽ" U+213D, "ℾ" U+213E, "ℿ" U+213F, "⨋" U+2A0B. compose-1.yml [ce4c440](https://github.com/dispoclavier/nouvel-azerty/commit/ce4c440827307ba04b20e9e75b14b5a288bc2eda)
	* Compléter les séquences de "⃓" U+20D3, "⃚" U+20DA, "⃬" U+20EC, "⃭" U+20ED, "℩" U+2129, "⅀" U+2140. ibidem
	* Compléter la séquence de "ẞ" U+1E9E par "S" majuscule suivi du "s" minuscule. ibidem
	* Corriger les séquences de "↯" U+21AF, "↶" U+21B6, "↷" U+21B7, "⤸" U+2938, "⤻" U+293B, "⦔" U+2994. compose-1.yml [196fa3b](https://github.com/dispoclavier/nouvel-azerty/commit/196fa3bc630eb9f1e587a654a653970944516dc6)
	* Compléter la séquence de "⦓" U+2993. ibidem
* Transformations :
	* Accent circonflexe : Désactiver l’équivalent en composition des chiffres en exposant à cause du conflit entre "³" U+00B3 et "❤" U+2764. compose-2.yml [3cf1d35](https://github.com/dispoclavier/nouvel-azerty/commit/3cf1d35f46b3c380e05deb33fdd0078545931bb0), [7e0b9ce](https://github.com/dispoclavier/nouvel-azerty/commit/7e0b9ce9db86588ebe67c9056a5f33dc302d7004)
	* Hatchek : Désactiver l’équivalent en composition des chiffres en indice à cause du conflit entre "³" U+00B3 et "❤" U+2764, pour la cohérence avec la touche morte accent circonflexe. ibidem

## 1.0.4 (2023-07-30)

* Composition : Corriger les séquences de "⨼" U+2A3C et "⨽" U+2A3D. compose-1.yml [7f7615a](https://github.com/dispoclavier/nouvel-azerty/commit/7f7615ad97212712585262e528a2cd253c1315e2)
* Transformations :
	* Ajouter la prise en charge de l’apostrophe ASCII comme caractère de base pour la saisie des guillemets apostrophes. compose-2.yml [2ec9a02](https://github.com/dispoclavier/nouvel-azerty/commit/2ec9a02eb735ad7aa352b5c4a8a8121502eba41d), compose-1.yml [2c5626f](https://github.com/dispoclavier/nouvel-azerty/commit/2c5626f24ea1bce7e1e46525df968ecc839a8df9)
	* Groupes des symboles :
		* Permuter les symboles "⊳" U+22B3 et "⊲" U+22B2 ainsi que "⊢" U+22A2 et "⊣" U+22A3. compose-2.yml [aa77809](https://github.com/dispoclavier/nouvel-azerty/commit/aa77809a03a69eb462cec0d540f6d4dd76b79ab0)
		* Remplacer "∁" U+2201 par "⟂" U+27C2. compose-2.yml [13c46b3](https://github.com/dispoclavier/nouvel-azerty/commit/13c46b3783638c6ad6d7c1c62cf3606b071e29cc), [77a281f](https://github.com/dispoclavier/nouvel-azerty/commit/77a281f994ad25cd1e9bb8928eae881596702292), [cae6903](https://github.com/dispoclavier/nouvel-azerty/commit/cae6903280ed2105c27422d9c6524ade4c229cbd)
		* Permuter "ː" U+02D0 et "ˑ" U+02D1. ibidem
		* Réarranger "⊢" U+22A2, "⊣" U+22A3, "⊥" U+22A5, "⊤" U+22A4. ibidem
		* Déplacer "⋱" U+22F1, "⋰" U+22F0. ibidem
		* Dupliquer "꞉" U+A789. ibidem
	* Double accent aigu : Supprimer la touche morte virtuelle en double frappe. compose-1.yml [7c66f9e](https://github.com/dispoclavier/nouvel-azerty/commit/7c66f9eb00175be161f15b57997652efaa9c2b02)
	* Tilde : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent aigu :
		* Supprimer la touche morte virtuelle en double frappe. compose-1.yml [90ca4fe](https://github.com/dispoclavier/nouvel-azerty/commit/90ca4fed7741528d890334352e807042e3e5798f)
		* Déplacer sur la perluète le diacritique combinant supplémentaire. compose-1.yml [f4c1ef6](https://github.com/dispoclavier/nouvel-azerty/commit/f4c1ef6fc90d712606d9ed9b6cd6771b5def6ef0)
	* Brève inversée : Redonder sur la perluète le diacritique combinant souscrit. compose-1.yml [7c66f9e](https://github.com/dispoclavier/nouvel-azerty/commit/7c66f9eb00175be161f15b57997652efaa9c2b02)
	* Brève : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent circonflexe : Redonder sur la perluète le diacritique combinant souscrit. compose-2.yml [0e3eee2](https://github.com/dispoclavier/nouvel-azerty/commit/0e3eee23ef25fa529643e8a8c64ec360e4777bc7)
	* Hatchek : Redonder sur la perluète le diacritique combinant souscrit. ibidem
	* Accent grave :
		* Supprimer les touches mortes virtuelles à partir de la triple frappe. compose-1.yml [bef37b4](https://github.com/dispoclavier/nouvel-azerty/commit/bef37b451007ca6ea93b4961eb8eebf7901ba7b7)
		* Déplacer sur la perluète le diacritique combinant supplémentaire. compose-1.yml [f4c1ef6](https://github.com/dispoclavier/nouvel-azerty/commit/f4c1ef6fc90d712606d9ed9b6cd6771b5def6ef0)

## 1.0.3 (2023-07-22)

* Composition :
	* Corriger les séquences des opérateurs invisibles. compose-1.yml [5a7d1c8](https://github.com/dispoclavier/nouvel-azerty/commit/5a7d1c847cb2c9091037bf2684d85bbbd4f4d2aa)
	* Dupliquer avec guillemet apostrophe les séquences avec apostrophe ASCII autres que les primes. compose-1.yml [c4bebdc](https://github.com/dispoclavier/nouvel-azerty/commit/c4bebdc9ad993dc1cc2b452934f9c8f7fa617020)
	* Dupliquer avec majuscule les séquences des constantes d’Euler, de Planck et de Planck sur 2π. compose-1.yml [04ff35f](https://github.com/dispoclavier/nouvel-azerty/commit/04ff35fd21c77219e41459df60dcc1ca16c9006f)
	* Ajouter des séquences basées sur commandes TeX. compose-1.yml [d46e07a](https://github.com/dispoclavier/nouvel-azerty/commit/d46e07a25f0c5d6e62729c1a81ac67a9eecc30ec)
	* Symbole diamètre : Ajouter des séquences française et française simplifiée. compose-1.yml [be410ee](https://github.com/dispoclavier/nouvel-azerty/commit/be410ee29032427ea5bef8ea427026f9ad3a4f29)

## v1.0.2 (2023-07-14)

* Ajouter le correctif à faire dans rules/evdev. dispocla.cpp [afb2e77](https://github.com/dispoclavier/nouvel-azerty/commit/afb2e7707351092a70483116c64be9c8a05b5044)

## v1.0.1 (2023-07-14)

* Sous-variantes : Effacement arrière : Remettre sur la touche traditionnelle. evdev.c [616da80](https://github.com/dispoclavier/nouvel-azerty/commit/616da804a22914e68665f32d522c7c3c074fc55d)

## v1.0.0 (2023-07-14)

* Publication initiale.

# 5.0.0 (2025-04-15)

Amélioration de l’utilisabilité de la modificatrice AltFr et des touches B07 et B08 en mode ASCII par la stabilité des points d’interrogation et d’exclamation.

Complétion des touches mortes au-delà du contenu pris en charge par équivalence en composition, grâce à la dissociation des touches mortes et des équivalents en composition.

Amélioration des groupes des symboles :
* gain de trois places dans les premiers groupes du croisillon grâce à la dissociation des touches mortes et de leur équivalent en composition ;
* retour des cases à cocher sur "#" ;
* intégration des obèles les plus fréquents et de l’astérisme très populaire.

Amélioration des groupes des lettres :
* les lettres grecques latines passent du groupe 3 au groupe 2 ;
* le v de ronde est doté d’un raccourci dans le groupe 1 ;
* l’upsilon latin regagne sa place dans le groupe 1 de l’i grec.

Correction de la prise en charge de l’émoji "❄" U+2744, arrêt de celle de "😃" U+1F603.

Prise en charge sur touche vive du séparateur invisible "⁣" U+2063, comme du signe plus invisible "⁤" U+2064 pour les fractions ordinaires (depuis la version 4.14), améliorant la résilience des écritures bicamérales.

Rectification ou simplification de certaines séquences de composition.

## Modifications

* Disposition :
	* Mode ASCII : AltFr :
		* B07 : Redonder le point d’interrogation (aussi en Maj) à la place de la virgule, qui est sur C10. dispocla.cpp [1b7a98a](https://github.com/dispoclavier/nouvel-azerty/commit/1b7a98ac2f886804dded572df08529d689df77ce), kbfrFRs.klc [f835de6](https://github.com/dispoclavier/nouvel-azerty/commit/f835de68f40d2736936d8a0d3feb767d201d3468), kbfredis.klc [b436621](https://github.com/dispoclavier/nouvel-azerty/commit/b4366215cb044a0f65dc399a94cc64d4f478a866), kbfrFRs.C [a778bb5](https://github.com/dispoclavier/nouvel-azerty/commit/a778bb52b745b4e4fbb25f23324d50b649669069), kbfredis.C [bcd0465](https://github.com/dispoclavier/nouvel-azerty/commit/bcd0465eff0029e2a19de1a4a87ec93f1bc62e74), linux-chromeos/readme.md [7546107](https://github.com/dispoclavier/nouvel-azerty/commit/7546107da66076f5fc712893c153e2846a749915), windows/readme.md [db18230](https://github.com/dispoclavier/nouvel-azerty/commit/db1823061903937f073744f2b863bebf192a1cad)
		* B08 : Redonder le point d’exclamation (aussi en Maj) à la place du point, qui est sur D10. ibidem
		* B09 : Accueillir "😒" U+1F612 à la place de "😃" U+1F603, qui n’est pas très fréquent. dispocla.cpp [67628de](https://github.com/dispoclavier/nouvel-azerty/commit/67628dee23300fb985b258b346116f626b1a0a8a), [da79a94](https://github.com/dispoclavier/nouvel-azerty/commit/da79a9495e70559f0a42443e18dc8ea397d542f5), nouvel-azerty.json [3f4d68c](https://github.com/dispoclavier/nouvel-azerty/commit/3f4d68cd2b21d550f0078ec7ff480b054aa67c88), nouvel-azerty-verrcap.json [5fac7cc](https://github.com/dispoclavier/nouvel-azerty/commit/5fac7cc00d8ce7b4b9ded019a553c2b94137c4f2), nouvel-azerty-verrmod.json [170ae79](https://github.com/dispoclavier/nouvel-azerty/commit/170ae79cbd68d8a009e2627ed909dc1fe0ab4260), nouvel-azerty-verrmod-verrcap.json [f50688a](https://github.com/dispoclavier/nouvel-azerty/commit/f50688a1dd324050376c8b91d75056e3f14cd195), ibidem
	* Mode français : B07 : Redonder sur touche vive le séparateur invisible "⁣" U+2063 à la place de "😒" U+1F612, qui va sur B09. ibidem
	* Windows : Déboguer la touche "moins" (E11). ibidem, kbfrFRs.H [0445df6](https://github.com/dispoclavier/nouvel-azerty/commit/0445df6d054dfec850526d8bebd91d457540cd4d), kbfredis.H [74eda28](https://github.com/dispoclavier/nouvel-azerty/commit/74eda28e7e4bb186dfee878a5d3adde763a2cfdd)
* Composition :
	* Déboguer les séquences de "⋽" U+22FD en annulant une [suppression faite par accident](https://github.com/dispoclavier/nouvel-azerty/commit/b5f6783e5e7aab62c3d398aab596d8f50a2de086#diff-6ae5ae8eee6e3533cc8889ce0f10b2d6db4de1acaf99d4ddb60920440b879f2dR5675) en amont de la version 4.25.0. compose-1.yml [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08)
	* Rectifier la séquence de "⦬" U+29AC après la version 4.25.0. compose-1.yml [ac148a1](https://github.com/dispoclavier/nouvel-azerty/commit/ac148a1ba51cf8ef443309ab554879f59be3f35a)
	* Prendre en charge "❄" U+2744. compose-1.yml [6f73de7](https://github.com/dispoclavier/nouvel-azerty/commit/6f73de7717b799e3776e4b5a575403a123cfc496), [749b224](https://github.com/dispoclavier/nouvel-azerty/commit/749b2243b936372dcb154c6b8ec4ad56caa7b5e4), compose-3.yml [4f9dd88](https://github.com/dispoclavier/nouvel-azerty/commit/4f9dd885cbc434c7f331abfa4d028d906461646f), [be999dc](https://github.com/dispoclavier/nouvel-azerty/commit/be999dc7693ee4010ac0b65e6e628654acac9b0b)
	* Simplifier les séquences de "☀" U+2600. ibidem
	* Prendre en charge "❤" U+2764, "♥" U+2665 séparément suite au réaménagement de la touche morte accent circonflexe. compose-1.yml [642cd00](https://github.com/dispoclavier/nouvel-azerty/commit/642cd0052bf3940b2438aa3458b501e1c205a7b6)
	* Prendre en charge "•" U+2022, "‣" U+2023, "▪" U+25AA, "▫" U+25AB, "▹" U+25B9, "◦" U+25E6, "➢" U+27A2, "➣" U+27A3 pour compléter les séquences avec "<" et un chiffre. ibidem
	* Compléter les séquences de "⃮" U+20EE, "⃯" U+20EF, "⋑" U+22D1, "⋮" U+22EE, "▴" U+25B4, "▵" U+25B5. ibidem
	* Supprimer les séquences redondantes erronées de "⋭" U+22ED. ibidem
	* Rectifier les séquences de "⇓" U+21D3, "∯" U+222F, "♠" U+2660, "♣" U+2663. ibidem et [90bc457](https://github.com/dispoclavier/nouvel-azerty/commit/90bc457cdc7b604d4a8d6faf94ea49ed612a4538)
	* Simplifier et documenter les séquences de "⤄" U+2904, "⤅" U+2905, "⤊" U+290A, "⤋" U+290B, "⤐" U+2910, "⤑" U+2911, "⤖" U+2916, "⤞" U+291E, "⤟" U+291F, "⤠" U+2920, "⤤" U+2924, "⤥" U+2925, "⤧" U+2927, "⤪" U+292A, "⤭" U+292D, "⤮" U+292E, "⤰" U+2930, "⤱" U+2931, "⤲" U+2932. compose-1.yml [006c816](https://github.com/dispoclavier/nouvel-azerty/commit/006c816e3241aaff1b6dd42b10c0cf5f2b6fd4bd)
	* Mettre à jour et documenter la séquence de "⦽" U+29BD ; adapter celles de "⧀" U+29C0. compose-1.yml [4c4e436](https://github.com/dispoclavier/nouvel-azerty/commit/4c4e436f1315d25e37ef3b995277f65e76021abb), [b9b806d](https://github.com/dispoclavier/nouvel-azerty/commit/b9b806dadd4ad35b3404e33c4d1996d6ef6b5e08), [c40e9e1](https://github.com/dispoclavier/nouvel-azerty/commit/c40e9e1c6ae02691a0d247fbdc26c26220ebb79c)
	* Mettre à jour et simplifier les séquences de "⧪" U+29EA, "⧬" U+29EC, "⧭" U+29ED. compose-1.yml [2a7c850](https://github.com/dispoclavier/nouvel-azerty/commit/2a7c850d52db6defd80ad24f506d0b2fcc6ef6dc)
	* Simplifier et annoter les séquences de "⨝" U+2A1D ; annoter celles de "⋈" U+22C8. compose-1.yml [b78b3fd](https://github.com/dispoclavier/nouvel-azerty/commit/b78b3fd58cd68ea1362bba084e94c4db01e84fb4), [d0656a5](https://github.com/dispoclavier/nouvel-azerty/commit/d0656a56832868b2ef1468b5477c683d3c7772ef), [bac64f2](https://github.com/dispoclavier/nouvel-azerty/commit/bac64f2c88345c8375285e83ae3ccfd0f767e6a5)
	* Ajouter les séquences simplifiées optionnelles de "⬴" U+2B34, "⬵" U+2B35, "⬹" U+2B39, "⬺" U+2B3A, "⬼" U+2B3C, "⬽" U+2B3D ; adapter celles de "⇺" U+21FA. compose-1.yml [04eb081](https://github.com/dispoclavier/nouvel-azerty/commit/04eb0815a400ae835eadbafd5aa800fcf00fc36c)
	* Harmoniser les séquences de "⬿" U+2B3F avec celles de "⤳" U+2933, rectifiées ; adapter et simplifier celles de "⥲" U+2972, "⥳" U+2973. compose-1.yml [32bfd85](https://github.com/dispoclavier/nouvel-azerty/commit/32bfd85d1611ced2805a760b3cbf9d674574535d)
	* Rectifier, simplifier et annoter les séquences de "⥂" U+2942, "⥃" U+2943, "⥄" U+2944. compose-1.yml [b1ea7bf](https://github.com/dispoclavier/nouvel-azerty/commit/b1ea7bf3abc052f7b01495cb32ce8303aff13970)
	* Adapter les séquences de "▵" U+25B5 suite à l’amélioration de la prise en charge de "⁄" U+2044. compose-1.yml [fd89859](https://github.com/dispoclavier/nouvel-azerty/commit/fd8985931d1a7fa5cc172f12800b512d42db8422)
	* Rectifier les séquences de "⥷" U+2977, "⭃" U+2B43, "⥺" U+297A, "⭄" U+2B44, "⥇" U+2947, "⬾" U+2B3E. compose-1.yml [7ac242b](https://github.com/dispoclavier/nouvel-azerty/commit/7ac242b3af8e34a893223d4dd8c1e24b37736c4a)
	* Rectifier la séquence de "⤾" U+293E. compose-1.yml [c0c63bc](https://github.com/dispoclavier/nouvel-azerty/commit/c0c63bc806b8280b9a93c02cf0a25e0ae0f0b3a7)
	* Mettre à jour les séquences de "⥐" U+2950. compose-1.yml [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c)
	* Compléter les séquences de "⥀" U+2940, "⥁" U+2941, "⥏" U+294F. ibidem
	* Adapter les séquences de "⩹" U+2A79, "⩺" U+2A7A. ibidem
	* Rectifier ou compléter les séquences de "⦞" U+299E, "⦡" U+29A1, "⧖" U+29D6, "⧗" U+29D7. compose-1.yml [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [67e64f1](https://github.com/dispoclavier/nouvel-azerty/commit/67e64f1c8581be72cb96538e375a8ad1832e5713)
	* Rectifier les séquences de "⧚" U+29DA, "⧛" U+29DB. compose-1.yml [f9140f5](https://github.com/dispoclavier/nouvel-azerty/commit/f9140f58a7759f51e30d46040c79539ef44ba8ca), [a7f5913](https://github.com/dispoclavier/nouvel-azerty/commit/a7f5913d64859d600bbf86017735639d4976b070)
	* Simplifier les séquences de "⑥" U+2465, "⑦" U+2466, "⑧" U+2467, "⑨" U+2468, "⧘" U+29D8, "⧙" U+29D9. ibidem
	* Compléter les séquences de "⨢" U+2A22, "⨣" U+2A23. compose-1.yml [8e15584](https://github.com/dispoclavier/nouvel-azerty/commit/8e15584c36144da1f4b7fed6b7b4acf2487ed8a3), [6ed0e90](https://github.com/dispoclavier/nouvel-azerty/commit/6ed0e9048a44f1b899c170214d1720f40cf47b15)
	* Rectifier les séquences de "⃮" U+20EE, "⃯" U+20EF. compose-1.yml [45d10e1](https://github.com/dispoclavier/nouvel-azerty/commit/45d10e18f513ae00b44455ff9f0cabd4f8b5ddf1)
	* Simplifier les séquences de "ϐ" U+03D0, "ϑ" U+03D1, "ϑ" U+03D1, "ϒ" U+03D2, "ϕ" U+03D5, "ϰ" U+03F0, "ϱ" U+03F1, "ϴ" U+03F4, "ϴ" U+03F4, "ϵ" U+03F5, "϶" U+03F6, "‖" U+2016, "⁺" U+207A, "⁼" U+207C, "⁽" U+207D, "₊" U+208A, "₌" U+208C, "⃓" U+20D3, "⃮" U+20EE, "⃯" U+20EF, "ℇ" U+2107, "ℊ" U+210A, "ℌ" U+210C, "ℍ" U+210D, "ℎ" U+210E, "ℏ" U+210F, "ℑ" U+2111, "ℓ" U+2113, "ℕ" U+2115, "ℚ" U+211A, "ℜ" U+211C, "ℝ" U+211D, "ℤ" U+2124, "ℨ" U+2128, "℩" U+2129, "ℯ" U+212F, "ℷ" U+2137, "ℼ" U+213C, "ℽ" U+213D, "ℾ" U+213E, "ℿ" U+213F, "⅀" U+2140, "⅁" U+2141, "⅄" U+2144, "ⅆ" U+2146, "ⅇ" U+2147, "ⅈ" U+2148, "ⅉ" U+2149. ibidem et compose-1.yml [1dccbfb](https://github.com/dispoclavier/nouvel-azerty/commit/1dccbfbb98813746f824e76dc1f26aaddfbbfb4d), [48350a3](https://github.com/dispoclavier/nouvel-azerty/commit/48350a344bca00bb80c48c8a94b2e82f6497ff4f), [6c1ca09](https://github.com/dispoclavier/nouvel-azerty/commit/6c1ca09f77b5f1d79d23234c8bfb687ebcaddca4)
	* Corriger une séquence de "⨣" U+2A23. compose-1.yml [439fa55](https://github.com/dispoclavier/nouvel-azerty/commit/439fa5538931f0f777be44a6969492599066a033)
	* Compléter les séquences de "⨢" U+2A22. compose-1.yml [81c31c7](https://github.com/dispoclavier/nouvel-azerty/commit/81c31c7690af71b2cedc374d2c6c7eadfbe0791b)
	* Compléter, simplifier et mettre à jour les séquences de "⇆" U+21C6, "⟵" U+27F5, "⟶" U+27F6, "⟷" U+27F7, "⟸" U+27F8, "⟹" U+27F9, "⟺" U+27FA, "⟻" U+27FB, "⟼" U+27FC, "⟽" U+27FD, "⟾" U+27FE. compose-1.yml [bb3410c](https://github.com/dispoclavier/nouvel-azerty/commit/bb3410c6ec6234150fe6d180652ac016b14a728a), [1562be3](https://github.com/dispoclavier/nouvel-azerty/commit/1562be3e51b8fceadab03b396a534c385b09c698)
	* Rectifier les séquences de "↱" U+21B1. compose-1.yml [c704e9c](https://github.com/dispoclavier/nouvel-azerty/commit/c704e9c50416c21c25aa9f399bebb6e3fc3ce2f4)
	* Simplifier les séquences de "⨥" U+2A25, "⨧" U+2A27, "⨨" U+2A28, "⨩" U+2A29, "⨫" U+2A2B, "⨬" U+2A2C, "⨭" U+2A2D. ibidem
	* Rectifier les séquences de "≮" U+226E. compose-1.yml [ce651e2](https://github.com/dispoclavier/nouvel-azerty/commit/ce651e2da42b228cc5cfb6772feaca61ecda5120)
	* Simplifier les séquences de "↔" U+2194. ibidem
	* Adapter les séquences de "⧺" U+29FA. compose-1.yml [47e4f66](https://github.com/dispoclavier/nouvel-azerty/commit/47e4f66bf5d85172c24d58068dc549ca8c3facb4)
	* Simplifier les séquences de "↛" U+219B. compose-1.yml [7555ff0](https://github.com/dispoclavier/nouvel-azerty/commit/7555ff0d80afe1c2c414bc69385bd910d473906a)
* Transformations :
	* Groupes des lettres :
		* Groupes de "B" : Mettre "Ꞵ" U+A7B4, "ꞵ" U+A7B5 dans le groupe 2 aux places de "Ɓ" U+0181, "ɓ" U+0253, qui prennent les places laissées par "Ꞵ" U+A7B4, "ꞵ" U+A7B5 dans le groupe 3. compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "E" :
			* Mettre "Ɛ" U+0190, "ɛ" U+025B dans le groupe 2 aux places de "Ə" U+018F, "ə" U+0259, qui prennent les places laissées par "Ɛ" U+0190, "ɛ" U+025B dans le groupe 3. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2), [aed31c6](https://github.com/dispoclavier/nouvel-azerty/commit/aed31c60cb69df2a81d2e2ca49125247106850f2)
			* Mettre "ʚ" U+029A du groupe 5 de "E" dans le groupe 5 de "e" à la place de "ɞ" U+025E, qui prend la place du doublon de "ə" U+0259 dans le groupe 4. ibidem
			* Supprimer le doublon de "Ə" U+018F dans le groupe 4. ibidem
		* Groupes de "F" :
			* Minuscule : Mettre "ɸ" U+0278 dans le groupe 2 à la place de "ꬵ" U+AB35, qui prend la place laissée par "ɸ" U+0278 dans le groupe 3. ibidem
			* Majuscule : Mettre "ⱷ" U+2C77 dans le groupe 2 à la place de "ʩ" U+02A9, qui prend la place laissée par "ⱷ" U+2C77 dans le groupe 3. ibidem
		* Groupes de "G" : Mettre "Ɣ" U+0194, "ɣ" U+0263 dans le groupe 2 aux places de "Ȝ" U+021C, "ȝ" U+021D, qui vont dans le groupe 4 aux places de "Ɤ" U+A7CB, "ɤ" U+0264, qui prennent les places laissées par "Ɣ" U+0194, "ɣ" U+0263 dans le groupe 3. compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "H" : Mettre "Ɥ" U+A78D, "ɥ" U+0265 dans le groupe 2 aux places de "Ꜧ" U+A726, "ꜧ" U+A727, qui prennent les places laissées par "Ɥ" U+A78D, "ɥ" U+0265 dans le groupe 4. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2)
		* Groupes de "I" :
			* Sortir "ℹ" U+2139, qui est aussi dans le groupe 8 de "{" sur "I", du groupe 12 et le mettre dans le groupe 4 à la place de "Ꞽ" U+A7BC, "ꞽ" U+A7BD, qui vont dans le groupe 3 à la place de "Ɩ" U+0196, "ɩ" U+0269, qui sont dans le groupe 1. ibidem
			* Propager "ꟾ" U+A7FE de la majuscule à la minuscule du groupe 12 de "I", "i". ibidem
		* Groupes de "L" : Mettre "Ꟛ" U+A7DA, "ꟛ" U+A7DB dans le groupe 2 aux places de "Ꝇ" U+A746, "ꝇ" U+A747, qui prennent les places laissées par "Ꟛ" U+A7DA, "ꟛ" U+A7DB dans le groupe 3. ibidem
		* Groupes de "M" : Mettre "Ɯ" U+019C, "ɯ" U+026F dans le groupe 2 aux places de "Ɱ" U+2C6E, "ɱ" U+0271, qui prennent les places laissées par "Ɯ" U+019C, "ɯ" U+026F dans le groupe 4. ibidem
		* Groupes de "O" : Mettre "Ɔ" U+0186, "ɔ" U+0254 dans le groupe 2 aux places de "Ȣ" U+0222, "ȣ" U+0223, qui prennent les places laissées par "Ɔ" U+0186, "ɔ" U+0254 dans le groupe 3. ibidem
		* Groupes de "U" : Redonder "Ʋ" U+01B2, "ʋ" U+028B dans le groupe 1 aux places de "Ʊ" U+01B1, "ʊ" U+028A, qui vont dans le groupe 1 de "Y", "y". compose-3.yml [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
		* Groupes de "V" : Mettre "Ꞷ" U+A7B6, "ꞷ" U+A7B7 dans le groupe 2 aux places de "Ʋ" U+01B2, "ʋ" U+028B, qui prennent les places laissées par "Ꞷ" U+A7B6, "ꞷ" U+A7B7 dans le groupe 3. compose-3.yml [47e1f03](https://github.com/dispoclavier/nouvel-azerty/commit/47e1f034d678e830aac8034050e4138ef4e8f2b3)
		* Groupes de "X" : Mettre "Ꭓ" U+A7B3, "ꭓ" U+AB53 dans le groupe 2 aux places de "ꭘ" U+AB58, "ꭖ" U+AB56, qui prennent les places laissées par "Ꭓ" U+A7B3, "ꭓ" U+AB53 dans le groupe 3. compose-3.yml [c876ad6](https://github.com/dispoclavier/nouvel-azerty/commit/c876ad685c3b752dd04e61a6d106cd11315e2fa2)
		* Groupes de "Y" : Redonder "Ȝ" U+021C, "ȝ" U+021D dans le groupe 3 aux places de "Ʊ" U+01B1, "ʊ" U+028A, qui vont dans le groupe 1 aux places de "Ɣ" U+0194, "ɣ" U+0263, qui sont dans le groupe 2 de "G", "g". compose-3.yml [4e03419](https://github.com/dispoclavier/nouvel-azerty/commit/4e03419204df620598e49a5d2a926c0272e76e8b), [5a1f2bb](https://github.com/dispoclavier/nouvel-azerty/commit/5a1f2bb50e586ed546385353d1e872e7266b894c)
	* Lettres composées pour les langues du Togo : Prendre en charge les voyelles des groupes 2 et 3. compose-2.yml [a6d06d7](https://github.com/dispoclavier/nouvel-azerty/commit/a6d06d7a4d7aa351bccb4a2aa3986d36f8b669b4), [2c2d952](https://github.com/dispoclavier/nouvel-azerty/commit/2c2d952df5f95ac8c7929fd439eb0b09d05f986f), [fc60404](https://github.com/dispoclavier/nouvel-azerty/commit/fc60404a53064e8deaaf1ba5f327f1f67649b5f2), [27cf612](https://github.com/dispoclavier/nouvel-azerty/commit/27cf61243426ef4fd6c5644847d45222ee42b7a7), [e756e0f](https://github.com/dispoclavier/nouvel-azerty/commit/e756e0f330500b63c7f004d6512514d50b37f381), [9a2656e](https://github.com/dispoclavier/nouvel-azerty/commit/9a2656e84c2928c5138eac0f476917bae9490b30)
	* Groupes des symboles :
		* Groupes de "|" : Redonder l’obèle "†" U+2020 dans le groupe 1, le double obèle "‡" U+2021 dans le groupe 2, l’astérisme "⁂" U+2042 dans le groupe 3, à la place des cases à cocher "☐" U+2610, "☑" U+2611, "☒" U+2612, qui vont dans les trois premiers groupes de "#" et qui sont en composition. compose-3.yml [8e13367](https://github.com/dispoclavier/nouvel-azerty/commit/8e13367631c66f561fc5b348a3d90128cc744b3d)
		* Groupes de "#" : Remettre les cases à cocher "☐" U+2610, "☑" U+2611, "☒" U+2612 dans les trois premiers groupes, malgré la panne des équivalents en composition. ibidem
		* Groupes de "`" : Mettre "❆" U+2746 à la place de "❄" U+2744, qui va dans le groupe 1 bis et en composition. compose-3.yml [b701895](https://github.com/dispoclavier/nouvel-azerty/commit/b7018954a1abd8352ac9f57b773555dd8c944c14)
	* Exposant : Exposant et indice (petite capitale) : Améliorer la prise en charge de la barre de fraction "⁄" U+2044. compose-2.yml [962cce4](https://github.com/dispoclavier/nouvel-azerty/commit/962cce42aba2c3b20b24c939ec3f12939691b647), compose-1.yml [1d68090](https://github.com/dispoclavier/nouvel-azerty/commit/1d68090cad95777f33cc58b8766e2249c49cb942)
	* Tourné : Redonder "‿" U+203F sans équivalent en composition. compose-2.yml [953f79d](https://github.com/dispoclavier/nouvel-azerty/commit/953f79d565d2fd10020cc98e5dcddc4f8e8548aa)
	* Réfléchi :
		* Améliorer la prise en charge de "⁌" U+204C, "⁍" U+204D. compose-2.yml [933fc16](https://github.com/dispoclavier/nouvel-azerty/commit/933fc165dd53c6d6724e0b51c289e0b366db7892)
		* Supprimer "Ɜ" U+A7AB, "ɜ" U+025C dans les groupes 3 à 5 suite au réaménagement des groupes des lettres. compose-2.yml [0e64944](https://github.com/dispoclavier/nouvel-azerty/commit/0e6494436e1f5e65e613e261d6da73c849716f46)
		* Réfléchi et crochet :
			* Remplacer "ᵆ" U+1D46, "ᶛ" U+1D9B par "ɝ" U+025D. ibidem
			* Supprimer "ɝ" U+025D dans les groupes 3 à 5 suite au réaménagement des groupes des lettres. ibidem
		* Réfléchi et crochet rétroflexe : Supprimer "ᶔ" U+1D94 dans le groupe 3 suite au réaménagement des groupes des lettres. ibidem
	* Tilde :
		* Redonder "⨤" U+2A24 sans équivalent en composition. compose-2.yml [d723e98](https://github.com/dispoclavier/nouvel-azerty/commit/d723e985d995d45f08c5ef68e9e907cece1a152a), compose-1.yml [6dbb70b](https://github.com/dispoclavier/nouvel-azerty/commit/6dbb70b8aaec1fc54a91c022baa2d86c046322ed)
		* Améliorer la prise en charge de "⁓" U+2053. ibidem
		* Tilde médian ou souscrit : Redonder "⨦" U+2A26. compose-2.yml [677d02c](https://github.com/dispoclavier/nouvel-azerty/commit/677d02c0779cd82ace91a5cef816fb2af096d5b0)
	* Point souscrit : Redonder "⨪" U+2A2A. compose-2.yml [ac885cc](https://github.com/dispoclavier/nouvel-azerty/commit/ac885ccaa8755f39445de3c78111c2c50ac5ebfd)
	* Ogonek : Désactiver l’équivalent en composition de "⃣" U+20E3. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
	* Crochet en chef : Désactiver l’équivalent en composition de "⃣" U+20E3. ibidem
	* Barré : Redonder "≮" U+226E, "≯" U+226F dans le groupe 0, sans impliquer la touche morte groupe. compose-2.yml [5fe63b1](https://github.com/dispoclavier/nouvel-azerty/commit/5fe63b12b08fd0e6c71e60d448d31d285095dee6)
	* Rond en chef :
		* Redonder "⨢" U+2A22. compose-2.yml [d2bc8dc](https://github.com/dispoclavier/nouvel-azerty/commit/d2bc8dcad83d114bd6961301ab1802f9a520d2b4)
		* Redonder "K" U+212A. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
	* Accent circonflexe :
		* Redonder "⨣" U+2A23. compose-2.yml [d2bc8dc](https://github.com/dispoclavier/nouvel-azerty/commit/d2bc8dcad83d114bd6961301ab1802f9a520d2b4)
		* Redonder les chiffres en exposant "⁰" U+2070, "¹" U+00B9, "²" U+00B2, "³" U+00B3, "⁴" U+2074, "⁵" U+2075, "⁶" U+2076, "⁷" U+2077, "⁸" U+2078, "⁹" U+2079 sans équivalents en composition. compose-2.yml [4413a1b](https://github.com/dispoclavier/nouvel-azerty/commit/4413a1b514d28bda78eacce4db21f52effda99f0)
		* Adapter la prise en charge de "᪰" U+1AB0, désormais par "^". ibidem
		* Redonder "⁂" U+2042 par "*". compose-2.yml [b2f5789](https://github.com/dispoclavier/nouvel-azerty/commit/b2f57893e94413cbb54fac7993136cc522b915fb)
		* Accent circonflexe souscrit : Adapter le raccourci, désormais en double frappe de cornu. ibidem
	* Drapeau :
		* Désactiver les équivalents en composition de "‌" U+200C, "⁠" U+2060. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc)
		* Corriger l’équivalent en composition du demi-codet haut U+D83C. ibidem
	* Point souscrit : Redonder "⨥" U+2A25. compose-2.yml [e5fa902](https://github.com/dispoclavier/nouvel-azerty/commit/e5fa90243a958d5d8e862fd6f61bb77d8122de11), compose-1.yml [f6fb44f](https://github.com/dispoclavier/nouvel-azerty/commit/f6fb44fd13c3b8f80af0e01892e8fcfcf536de68)
	* Tréma :
		* Redonder "⁑" U+2051 par "*" sans équivalent en composition. compose-2.yml [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc), [43fa20e](https://github.com/dispoclavier/nouvel-azerty/commit/43fa20e8ef2aa3a316dc28048765cb69c54bf20e)
		* Supprimer "⸺" U+2E3A, "⸻" U+2E3B, qui sont dans les groupes 1..3 et en composition. compose-2.yml [8de617f](https://github.com/dispoclavier/nouvel-azerty/commit/8de617f5001bafa3627b8371c1b07d0c3f7aef0a)
* Documentation :
	* Ajouter un PDF documentant la touche morte groupe. linux-chromeos/readme.md [b70c9b7](https://github.com/dispoclavier/nouvel-azerty/commit/b70c9b7c26ca633276b98a19084d50a67ecfeaa1), windows/readme.md [0f70813](https://github.com/dispoclavier/nouvel-azerty/commit/0f708130443e4904770b614906f3e8614f57157a)
	* Mettre à jour les annotations suite à la version 4.25.0. compose-1.yml [26c6ea2](https://github.com/dispoclavier/nouvel-azerty/commit/26c6ea29b1aa65eb4176b267b29987ff3650f526), compose-3.yml [5899287](https://github.com/dispoclavier/nouvel-azerty/commit/5899287a877749eeaf9f463cde9d714ad4928b1d)
	* Mettre à jour les annotations suite à la divergence des touches mortes avec les équivalents en composition. compose-1.yml [ce651e2](https://github.com/dispoclavier/nouvel-azerty/commit/ce651e2da42b228cc5cfb6772feaca61ecda5120), [48745fb](https://github.com/dispoclavier/nouvel-azerty/commit/48745fb8b417239f979cb1d4cb463ee7861fd7ea), compose-2.yml [cb13225](https://github.com/dispoclavier/nouvel-azerty/commit/cb13225a0dacad95527cf853d667d0b197b8a4ec), [9b8e6e5](https://github.com/dispoclavier/nouvel-azerty/commit/9b8e6e5700127ded600d8fdaf32735fff445dc72)
	* Documenter les séquences tronquées en deçà de l’espace finale, pour faciliter leur éventuelle rallongation : Rajouter en commentaire les séquences tronquées jusque-là. compose-1.yml [7646b53](https://github.com/dispoclavier/nouvel-azerty/commit/7646b53b18ffc5a3c47374dd4303b008424d6fe7), [7b22e30](https://github.com/dispoclavier/nouvel-azerty/commit/7b22e30b71907f44b0fdcbff14bb7c4de0e0f3a4), [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08), [7e20c8f](https://github.com/dispoclavier/nouvel-azerty/commit/7e20c8f96e69c66aeed32db6e078b6a9f96e3998), [c0c63bc](https://github.com/dispoclavier/nouvel-azerty/commit/c0c63bc806b8280b9a93c02cf0a25e0ae0f0b3a7), [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c), [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [8e15584](https://github.com/dispoclavier/nouvel-azerty/commit/8e15584c36144da1f4b7fed6b7b4acf2487ed8a3), [752989e](https://github.com/dispoclavier/nouvel-azerty/commit/752989e704b5430af8d72b0ab7a64be50dfc5806), [dabd6c0](https://github.com/dispoclavier/nouvel-azerty/commit/dabd6c09dde6eeb2f187e265e1549bfbc3894f1d), [48745fb](https://github.com/dispoclavier/nouvel-azerty/commit/48745fb8b417239f979cb1d4cb463ee7861fd7ea)
	* Ajouter des annotations. compose-1.yml [73aa053](https://github.com/dispoclavier/nouvel-azerty/commit/73aa0530113510e8ab47194f603f159213679d0f), compose-2.yml [36bf48d](https://github.com/dispoclavier/nouvel-azerty/commit/36bf48d3c92f384b51f4d8710d1b9872734f8115)
	* Simplifier et émonder les annotations. compose-1.yml [1e68bae](https://github.com/dispoclavier/nouvel-azerty/commit/1e68baebff07069616dd97fc6153fe687532e82f), compose-2.yml [75751f0](https://github.com/dispoclavier/nouvel-azerty/commit/75751f0c60bf300a723aef54b32f29f295fec687), compose-3.yml [6256d8c](https://github.com/dispoclavier/nouvel-azerty/commit/6256d8c46cccd93a7e5eb910183b2d85dea47e90)
	* Corriger des annotations. compose-1.yml [dbc5212](https://github.com/dispoclavier/nouvel-azerty/commit/dbc52127f449863ee90888de8e6854f338dbeebd), compose-2.yml [2a55640](https://github.com/dispoclavier/nouvel-azerty/commit/2a5564030f4e290fe2fb5166f9bc4ddac53d1590), [43fa20e](https://github.com/dispoclavier/nouvel-azerty/commit/43fa20e8ef2aa3a316dc28048765cb69c54bf20e)
	* Mettre à jour des annotations. compose-1.yml [3566dba](https://github.com/dispoclavier/nouvel-azerty/commit/3566dba8c32f16b5499ee9a76ad2de46121d0a35), [95a2755](https://github.com/dispoclavier/nouvel-azerty/commit/95a2755129e3ae0ec03bc6c20c43ad3d3bc04ee0), compose-2.yml [62eea71](https://github.com/dispoclavier/nouvel-azerty/commit/62eea7124de4e87672959a9469d3f7e2eabd5a78), compose-3.yml [35881d2](https://github.com/dispoclavier/nouvel-azerty/commit/35881d2beab6e4bf663b73ca27db460e31c6b63c)¨; compose-2.yml [ed400b4](https://github.com/dispoclavier/nouvel-azerty/commit/ed400b481d7731782a577791d8d3a3e36ccab981), compose-3.yml [dd9a3f4](https://github.com/dispoclavier/nouvel-azerty/commit/dd9a3f4089db58ad4d5743d534fc849764deb22c) ; compose-1.yml [001ea1f](https://github.com/dispoclavier/nouvel-azerty/commit/001ea1f864826e24ed8566af066fe584f4b161db), compose-2.yml [5fe63b1](https://github.com/dispoclavier/nouvel-azerty/commit/5fe63b12b08fd0e6c71e60d448d31d285095dee6)
	* Mettre à jour, corriger et compléter des annotations. compose-1.yml [6dbb70b](https://github.com/dispoclavier/nouvel-azerty/commit/6dbb70b8aaec1fc54a91c022baa2d86c046322ed), [079f1fa](https://github.com/dispoclavier/nouvel-azerty/commit/079f1fa8ff5077b5efd219642b51097816aead8e), [6701124](https://github.com/dispoclavier/nouvel-azerty/commit/670112456fcf6510f326cf99f2e4e9243a17406d), compose-2.yml [953f79d](https://github.com/dispoclavier/nouvel-azerty/commit/953f79d565d2fd10020cc98e5dcddc4f8e8548aa), [933fc16](https://github.com/dispoclavier/nouvel-azerty/commit/933fc165dd53c6d6724e0b51c289e0b366db7892), [0e64944](https://github.com/dispoclavier/nouvel-azerty/commit/0e6494436e1f5e65e613e261d6da73c849716f46), [93e7599](https://github.com/dispoclavier/nouvel-azerty/commit/93e759962e2a1a86c42e886cd36d5522b43969c0), [2e3c2aa](https://github.com/dispoclavier/nouvel-azerty/commit/2e3c2aaa19f25f5ede9775abf6363011eb8c70cc), [8de617f](https://github.com/dispoclavier/nouvel-azerty/commit/8de617f5001bafa3627b8371c1b07d0c3f7aef0a), compose-3.yml [8ed9dc8](https://github.com/dispoclavier/nouvel-azerty/commit/8ed9dc8dff6ea2ad6c0ee3d2261c62407080f0d2)
	* Mettre à jour, corriger et compléter des annotations, améliorer la lisibilité. compose-1.yml [d648e75](https://github.com/dispoclavier/nouvel-azerty/commit/d648e752f362bc9e7cb92a78df2fad36aab00c0f), compose-2.yml [c072d9c](https://github.com/dispoclavier/nouvel-azerty/commit/c072d9c5d811d5bd0824e1c0b68cb1a52ddff0f3), compose-3.yml [bf0e9d3](https://github.com/dispoclavier/nouvel-azerty/commit/bf0e9d398211bd8700c26ba3999f9b4bc5a224ed)
	* Ajouter, compléter, corriger, mettre à jour ou supprimer des annotations. dispocla.cpp [1b7a98a](https://github.com/dispoclavier/nouvel-azerty/commit/1b7a98ac2f886804dded572df08529d689df77ce), [9e28652](https://github.com/dispoclavier/nouvel-azerty/commit/9e2865293ecc89d1dbafc38b5d3e73107a1e17be), compose-1.yml [d3bb0a6](https://github.com/dispoclavier/nouvel-azerty/commit/d3bb0a659bbf8e6b8cc7b2f952a2584f41c14ee5), [75c4a7e](https://github.com/dispoclavier/nouvel-azerty/commit/75c4a7e3b1542f49a3a3ee2bbdf5f577c8026b62), [006c816](https://github.com/dispoclavier/nouvel-azerty/commit/006c816e3241aaff1b6dd42b10c0cf5f2b6fd4bd), [d0656a5](https://github.com/dispoclavier/nouvel-azerty/commit/d0656a56832868b2ef1468b5477c683d3c7772ef), [b78b3fd](https://github.com/dispoclavier/nouvel-azerty/commit/b78b3fd58cd68ea1362bba084e94c4db01e84fb4), [748aae0](https://github.com/dispoclavier/nouvel-azerty/commit/748aae05fbcd9f157274725204949d76f5b33a08), [90bc457](https://github.com/dispoclavier/nouvel-azerty/commit/90bc457cdc7b604d4a8d6faf94ea49ed612a4538), [eb06a29](https://github.com/dispoclavier/nouvel-azerty/commit/eb06a29e76448c719524d34f3248afffb0a8c629), [7e20c8f](https://github.com/dispoclavier/nouvel-azerty/commit/7e20c8f96e69c66aeed32db6e078b6a9f96e3998), [83045e3](https://github.com/dispoclavier/nouvel-azerty/commit/83045e328c4407e3f1d2f2ac03d7c70663cfb19c), [e8379dd](https://github.com/dispoclavier/nouvel-azerty/commit/e8379dd550377ba238eee9b5985e40925f5f8d5b), [67e64f1](https://github.com/dispoclavier/nouvel-azerty/commit/67e64f1c8581be72cb96538e375a8ad1832e5713), [f9140f5](https://github.com/dispoclavier/nouvel-azerty/commit/f9140f58a7759f51e30d46040c79539ef44ba8ca), [44305b8](https://github.com/dispoclavier/nouvel-azerty/commit/44305b858cf4aaf9603e147f4e6038eb6fc1f791), [dff12bf](https://github.com/dispoclavier/nouvel-azerty/commit/dff12bf358ba212598d291ce15e3ad3efa173c38), [7b22e30](https://github.com/dispoclavier/nouvel-azerty/commit/7b22e30b71907f44b0fdcbff14bb7c4de0e0f3a4), [caa1e80](https://github.com/dispoclavier/nouvel-azerty/commit/caa1e80dad5fbc6f7ff02a7768ef39ca4d5eee67), [da25235](https://github.com/dispoclavier/nouvel-azerty/commit/da25235d1c1a8dc56caf23d12b0fbff4b0b56350), [dd9f997](https://github.com/dispoclavier/nouvel-azerty/commit/dd9f99709ff6010f0c5e917154819964cb924e12), [981862d](https://github.com/dispoclavier/nouvel-azerty/commit/981862dde5afdb1497e51db926e9e369dabe4631), [c68c2a3](https://github.com/dispoclavier/nouvel-azerty/commit/c68c2a3f6515e7f6a4a2252f496fa15d262e0536), [cec1df2](https://github.com/dispoclavier/nouvel-azerty/commit/cec1df2339ad9f71efd55d710c4b9dbfb171ab75), [439fa55](https://github.com/dispoclavier/nouvel-azerty/commit/439fa5538931f0f777be44a6969492599066a033), [86b4314](https://github.com/dispoclavier/nouvel-azerty/commit/86b4314f3f882aa9b7e302b34f18ee25d11fe4d4), [81c31c7](https://github.com/dispoclavier/nouvel-azerty/commit/81c31c7690af71b2cedc374d2c6c7eadfbe0791b), [a050c53](https://github.com/dispoclavier/nouvel-azerty/commit/a050c53294c8740c11ede2e8d27e546831a11ccd), [bb3410c](https://github.com/dispoclavier/nouvel-azerty/commit/bb3410c6ec6234150fe6d180652ac016b14a728a), [fa4d848](https://github.com/dispoclavier/nouvel-azerty/commit/fa4d848ed07dc45a0015cd82ecb558617a23c935) [7fc4e8e](https://github.com/dispoclavier/nouvel-azerty/commit/7fc4e8e73f94fa102e5510140df61ec0246a311d), compose-2.yml [f478020](https://github.com/dispoclavier/nouvel-azerty/commit/f47802067198ddd420fd7911e99945a96b3c7c85), [527a77d](https://github.com/dispoclavier/nouvel-azerty/commit/527a77df0e8e9126d955160edf26e1e690cf260d), [b2294aa](https://github.com/dispoclavier/nouvel-azerty/commit/b2294aa31e874653f7cb9b2c95a32b845731a7eb), [79f3356](https://github.com/dispoclavier/nouvel-azerty/commit/79f3356d231c6ceffc128677e3e3394f9cf12421)
	* Améliorer la lisibilité des annotations. compose-1.yml [eb06a29](https://github.com/dispoclavier/nouvel-azerty/commit/eb06a29e76448c719524d34f3248afffb0a8c629)
	* Mettre à jour les termes. kbcommon.h [3572a9f](https://github.com/dispoclavier/nouvel-azerty/commit/3572a9f3f175df501ce3c4c37fd597d6a6b583a2)
	* Mettre à jour le numéro de version. kbfrFRs.RC [4d87273](https://github.com/dispoclavier/nouvel-azerty/commit/4d872731726851e149a3bd51cd4dc4c602be13ee), kbfredis.RC [a6b183e](https://github.com/dispoclavier/nouvel-azerty/commit/a6b183e51dfa951e88f2d8311f7f62b7cc10a3a4)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-5.0.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-5.0.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-5.0.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier « kbfrFRs v5.0.0.0 installation » et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.0.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-5.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-5.0.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

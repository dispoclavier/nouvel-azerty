# 6.2.6 (2026-03-16)

Simplification de la saisie des symboles mathématiques.

Correction et mise à jour du contenu des touches mortes.

## Modifications

* Composition :
	* Déboguer et corriger les séquences de "⁦" U+2066, U+2067. compose-1.yml [ea26e6a](https://github.com/dispoclavier/nouvel-azerty/commit/ea26e6a11a048595abd47c4edec466d07ed2bad6)
	* Mettre à jour les séquences de "⨟" U+2A1F, "⨾" U+2A3E. ibidem
	* Mettre à jour les séquences de "↑" U+2191, "↓" U+2193, "↕" U+2195, "↟" U+219F, "↡" U+21A1, "↥" U+21A5, "↧" U+21A7, "↨" U+21A8, "↰" U+21B0, "↱" U+21B1, "↾" U+21BE, "↿" U+21BF, "⇂" U+21C2, "⇃" U+21C3, "⇅" U+21C5, "⇈" U+21C8, "⇊" U+21CA, "⇑" U+21D1, "⇓" U+21D3, "⇕" U+21D5, "⇵" U+21F5, "⋮" U+22EE, "⟰" U+27F0, "⟱" U+27F1, "⤈" U+2908, "⤉" U+2909, "⤊" U+290A, "⤋" U+290B, "⤒" U+2912, "⤓" U+2913, "⤴" U+2934, "⤵" U+2935, "⤶" U+2936, "⤷" U+2937, "⥉" U+2949, "⥌" U+294C, "⥍" U+294D, "⥏" U+294F, "⥑" U+2951, "⥔" U+2954, "⥕" U+2955, "⥘" U+2958, "⥙" U+2959, "⥜" U+295C, "⥝" U+295D, "⥠" U+2960, "⥡" U+2961, "⥣" U+2963, "⥥" U+2965, "⥮" U+296E, "⥯" U+296F, "⥾" U+297E, "⥿" U+297F, "⦽" U+29BD, "⧪" U+29EA, "⧬" U+29EC, "⧭" U+29ED, "⨡" U+2A21, "⫱" U+2AF1. ibidem
	* Corriger les séquences de "‐" U+2010, "‑" U+2011, "‒" U+2012, "–" U+2013, "—" U+2014, "―" U+2015, "⸺" U+2E3A, "⸻" U+2E3B, "⹀" U+2E40. ibidem
	* Simplifier la saisie de "⅀" U+2140, "↶" U+21B6, "⇉" U+21C9, "⇶" U+21F6. ibidem
	* Simplifier la saisie de "⁄" U+2044, "−" U+2212, "∕" U+2215, "∖" U+2216, "∗" U+2217, "∙" U+2219, "∣" U+2223, "∥" U+2225, "∧" U+2227, "∶" U+2236, "∷" U+2237, "∻" U+223B, "∼" U+223C, "≀" U+2240, "≁" U+2241, "≅" U+2245, "≆" U+2246, "≈" U+2248, "≋" U+224B, "≎" U+224E, "≖" U+2256, "⋅" U+22C5, "⋆" U+22C6, "⟋" U+27CB, "⟍" U+27CD, "⧵" U+29F5, "⧸" U+29F8, "⧹" U+29F9. compose-1.yml [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43)
	* Adapter les séquences de "≘" U+2258. compose-1.yml [eeb6a3d](https://github.com/dispoclavier/nouvel-azerty/commit/eeb6a3d66bb7d832f3f63839c87e96c6267852be)
	* Simplifier la saisie de "≣" U+2263. ibidem
	* Simplifier la saisie de "⇴" U+21F4. compose-1.yml [9cf17f3](https://github.com/dispoclavier/nouvel-azerty/commit/9cf17f35b4926411ade13ae643216e14517e75e6)
	* Adapter les séquences de "↬" U+21AC. ibidem
	* Simplifier la saisie de "≪" U+226A, "≫" U+226B, "⋘" U+22D8, "⋙" U+22D9. compose-1.yml [29475d5](https://github.com/dispoclavier/nouvel-azerty/commit/29475d5933ca92aeaad314dbc86926225e7e1c27)
	* Simplifier la saisie de "⊘" U+2298 [df62a94](https://github.com/dispoclavier/nouvel-azerty/commit/df62a9462d4f34881e21198ae63afd0e1ea18234)
	* Adapter les séquences de "⌀" U+2300. ibidem
	* Corriger les séquences de "☐" U+2610, "☑" U+2611, "☒" U+2612, "⮽" U+2BBD. compose-1.yml [6fcba08](https://github.com/dispoclavier/nouvel-azerty/commit/6fcba08a7a7aeafa3559f475568e4342100773f6)
	* Simplifier la saisie de "⊠" U+22A0. ibidem
	* Corriger les séquences de "⊪" U+22AA. compose-1.yml [f7ba731](https://github.com/dispoclavier/nouvel-azerty/commit/f7ba731161cd78723dc5d753b7fb14b01331659e)
	* Simplifier la saisie de "⊩" U+22A9, "⊪" U+22AA, "⟏" U+27CF. ibidem
	* Adapter les séquences de "⫲" U+2AF2, "⫵" U+2AF5. ibidem
	* Compléter les séquences de "⦀" U+2980. ibidem
	* Simplifier la saisie de "⊸" U+22B8, "⊹" U+22B9, "⊼" U+22BC, "⊽" U+22BD. compose-1.yml [5584578](https://github.com/dispoclavier/nouvel-azerty/commit/55845785b054fe0cc3d23c1397c57353959063fd)
	* Compléter les séquences de "϶" U+03F6, "⃚" U+20DA, "⃥" U+20E5, "℩" U+2129, "ℵ" U+2135, "ℶ" U+2136, "ℷ" U+2137, "ℸ" U+2138, "⅃" U+2143, "⅄" U+2144, "↖" U+2196, "↘" U+2198, "⇖" U+21D6, "⇘" U+21D8, "∋" U+220B, "∌" U+220C, "∍" U+220D, "∐" U+2210, "∖" U+2216, "∝" U+221D, "∢" U+2222, "∧" U+2227, "∽" U+223D, "∾" U+223E, "≌" U+224C, "≒" U+2252, "⊃" U+2283, "⊅" U+2285, "⊇" U+2287, "⊉" U+2289, "⊋" U+228B, "⊐" U+2290, "⊒" U+2292, "⋀" U+22C0, "⋈" U+22C8, "⋉" U+22C9, "⋊" U+22CA, "⋋" U+22CB, "⋌" U+22CC, "⋍" U+22CD, "⋏" U+22CF, "⋑" U+22D1, "⋣" U+22E3, "⋥" U+22E5, "⋱" U+22F1, "⋺" U+22FA, "⋻" U+22FB, "⋼" U+22FC, "⋽" U+22FD, "⋾" U+22FE, "⏢" U+23E2, "▲" U+25B2, "△" U+25B3, "▴" U+25B4, "▵" U+25B5, "▷" U+25B7, "▼" U+25BC, "▽" U+25BD, "▾" U+25BE, "▿" U+25BF, "◀" U+25C0, "◁" U+25C1, "◣" U+25E3, "◥" U+25E5, "◹" U+25F9, "◺" U+25FA, "❏" U+274F, "❑" U+2751, "⟁" U+27C1, "⟄" U+27C4, "⟈" U+27C8, "⟉" U+27C9, "⟍" U+27CD, "⟓" U+27D3, "⟔" U+27D4, "⟕" U+27D5, "⟖" U+27D6, "⟗" U+27D7, "⟘" U+27D8, "⟟" U+27DF, "⤡" U+2921, "⤣" U+2923, "⤥" U+2925, "⤧" U+2927, "⤨" U+2928, "⤩" U+2929, "⤪" U+292A, "⤫" U+292B, "⤬" U+292C, "⤭" U+292D, "⤮" U+292E, "⤯" U+292F, "⤰" U+2930, "⤲" U+2932, "⥻" U+297B, "⦛" U+299B, "⦠" U+29A0, "⦣" U+29A3, "⦥" U+29A5, "⦦" U+29A6, "⦩" U+29A9, "⦪" U+29AA, "⦮" U+29AE, "⦰" U+29B0, "⦸" U+29B8, "⧅" U+29C5, "⧊" U+29CA, "⧋" U+29CB, "⧌" U+29CC, "⧍" U+29CD, "⧑" U+29D1, "⧒" U+29D2, "⧓" U+29D3, "⧔" U+29D4, "⧕" U+29D5, "⧠" U+29E0, "⧢" U+29E2, "⧨" U+29E8, "⧩" U+29E9, "⧵" U+29F5, "⧷" U+29F7, "⧹" U+29F9, "⨝" U+2A1D, "⨞" U+2A1E, "⨫" U+2A2B, "⨲" U+2A32, "⨳" U+2A33, "⨹" U+2A39, "⨺" U+2A3A, "⨻" U+2A3B, "⨿" U+2A3F, "⩕" U+2A55, "⩙" U+2A59, "⩚" U+2A5A, "⩜" U+2A5C, "⩞" U+2A5E, "⩟" U+2A5F, "⩠" U+2A60, "⪝" U+2A9D, "⪞" U+2A9E, "⪟" U+2A9F, "⪠" U+2AA0, "⪾" U+2ABE, "⫀" U+2AC0, "⫂" U+2AC2, "⫄" U+2AC4, "⫆" U+2AC6, "⫈" U+2AC8, "⫊" U+2ACA, "⫌" U+2ACC, "⫙" U+2AD9, "⫠" U+2AE0, "⫨" U+2AE8, "⫩" U+2AE9, "⫫" U+2AEB, "⫮" U+2AEE, "⭁" U+2B41, "⭂" U+2B42, "⭄" U+2B44, "⭇" U+2B47, "⭈" U+2B48, "⭋" U+2B4B, "⭌" U+2B4C, "﬩" U+FB29, "🅮" U+1F16E. ibidem et compose-1.yml [81a3a8e](https://github.com/dispoclavier/nouvel-azerty/commit/81a3a8e3a0d22386269821456b5870457fba8893)
	* Simplifier la saisie de "⋄" U+22C4, "⋕" U+22D5, "⋲" U+22F2, "⋵" U+22F5, "⋶" U+22F6, "⋷" U+22F7, "⋻" U+22FB, "⋻" U+22FB, "⋼" U+22FC, "⋽" U+22FD, "⋾" U+22FE. compose-1.yml [4c8abff](https://github.com/dispoclavier/nouvel-azerty/commit/4c8abff6048a27a983b8f4d087165aa35f26cf24)
	* Adapter les séquences de "⁋" U+204B, "⫥" U+2AE5. ibidem
	* Simplifier la saisie de "▵" U+25B5, "▶" U+25B6, "▷" U+25B7, "★" U+2605, "☆" U+2606, "♯" U+266F. compose-1.yml [4f61efe](https://github.com/dispoclavier/nouvel-azerty/commit/4f61efe9f6db4c584ccfb1c2cb1bae9209b9375a)
	* Simplifier la saisie de "⟄" U+27C4, "⟈" U+27C8. compose-1.yml [569fa31](https://github.com/dispoclavier/nouvel-azerty/commit/569fa31642b7fc9b405205330394ae56994f4fc9)
	* Simplifier la saisie de "⟎" U+27CE, "⟏" U+27CF, "⟦" U+27E6, "⟧" U+27E7. compose-1.yml [df87858](https://github.com/dispoclavier/nouvel-azerty/commit/df8785820a88825df2355558f3a5bb269679cca4), [c34e51f](https://github.com/dispoclavier/nouvel-azerty/commit/c34e51ff2911d64f68938e5994e020131806671c), [58c0364](https://github.com/dispoclavier/nouvel-azerty/commit/58c0364385bbccedb43777c9dc724cdf6b657f3c)
	* Corriger les séquences de "⨛" U+2A1B. compose-1.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
	* Adapter les séquences de "¥" U+00A5, "§" U+00A7, "⋋" U+22CB, "⋌" U+22CC, "⤺" U+293A, "⤻" U+293B. ibidem
	* Compléter les séquences de "⫰" U+2AF0. ibidem
	* Simplifier la saisie de "⋈" U+22C8, "⤾" U+293E, "⥀" U+2940, "⥁" U+2941, "⥭" U+296D, "⥱" U+2971, "⥼" U+297C, "⥽" U+297D, "⥿" U+297F, "⦂" U+2982, "⦃" U+2983, "⦄" U+2984, "⦅" U+2985, "⦆" U+2986, "⦓" U+2993, "⦔" U+2994, "⦞" U+299E, "⦤" U+29A4, "⦧" U+29A7, "⦸" U+29B8, "⧵" U+29F5, "⧇" U+29C7, "⧖" U+29D6, "⧗" U+29D7, "⧝" U+29DD, "⧺" U+29FA, "⨋" U+2A0B, "⨝" U+2A1D, "⨢" U+2A22, "⨧" U+2A27, "⨨" U+2A28, "⨰" U+2A30, "⨳" U+2A33, "⨶" U+2A36. ibidem, compose-2.yml [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661)
	* Simplifier la saisie de "⨟" U+2A1F, "⨼" U+2A3C, "⨽" U+2A3D, "⨾" U+2A3E, "⩂" U+2A42, "⩃" U+2A43, "⩌" U+2A4C, "⩑" U+2A51, "⩒" U+2A52. compose-1.yml [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc)
	* Simplifier la saisie de "⩞" U+2A5E, "⩟" U+2A5F, "⩠" U+2A60, "⩢" U+2A62, "⩣" U+2A63. compose-1.yml [e2171d1](https://github.com/dispoclavier/nouvel-azerty/commit/e2171d1e3b82f6a2afda0d9e72bf25bcf4ae0cd4)
	* Adapter les séquences de "ª" U+00AA, "º" U+00BA. ibidem
	* Simplifier la saisie de "⎄" U+2384, "⩰" U+2A70, "⩹" U+2A79, "⩺" U+2A7A, "⪣" U+2AA3, "⫃" U+2AC3, "⫄" U+2AC4, "⫰" U+2AF0, "⫻" U+2AFB, "⫽" U+2AFD, "⫾" U+2AFE, "⫿" U+2AFF, "⬶" U+2B36. compose-2.yml [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661)
	* Compléter les séquences de "⬰" U+2B30, "⬱" U+2B31, "⬲" U+2B32, "⬳" U+2B33, "⬴" U+2B34, "⬵" U+2B35, "⬶" U+2B36, "⬸" U+2B38, "⬾" U+2B3E, "⬿" U+2B3F. compose-1.yml [e7348e0](https://github.com/dispoclavier/nouvel-azerty/commit/e7348e080f713993ad408cbbfb665819e032f183)
	* Adapter les séquences de "⟴" U+27F4, "⥇" U+2947. ibidem
* Transformations :
	* Tourné : Redonder "≀" U+2240. compose-2.yml [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43)
	* Double accent aigu : Corriger la touche morte triple accent aigu "᫋" U+1ACB. compose-2.yml [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc)
	* Réfléchi : Mettre à jour les séquences de "∖" U+2216, "⟍" U+27CD, "⧵" U+29F5, "⧹" U+29F9. compose-2.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
	* Tilde > tilde médian : Redonder "∻" U+223B. compose-2.yml [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43)
	* Accent aigu > double accent aigu : Redonder "᫋" U+1ACB. compose-2.yml [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc)
	* Point en chef : Redonder "⨰" U+2A30 par "*" au lieu de ";". compose-2.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
	* Brève inversée : Redonder "≘" U+2258. compose-2.yml [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43)
	* Macron : Redonder "¦" U+00A6, "∦" U+2226 à la place de "ǀ" U+01C0, "ǁ" U+01C1, qui sont dans le groupe 5 de "i" ou "l". compose-2.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
	* Barré :
		* Redonder "≁" U+2241. compose-2.yml [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43)
		* Mettre à jour les séquences de "⁄" U+2044, "∕" U+2215, "⟋" U+27CB, "⧸" U+29F8. compose-2.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
	* Accent circonflexe :
		* Redonder "⨶" U+2A36 par "×" U+00D7, et par "@" à la place de "⍽" U+237D, qui est dans le groupe 2 de "$". compose-2.yml [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359)
		* Redonder "⁻" U+207B par "-" à la place de "—" U+2014, qui est sur touche vive. compose-2.yml [eeb6a3d](https://github.com/dispoclavier/nouvel-azerty/commit/eeb6a3d66bb7d832f3f63839c87e96c6267852be)
		* Redonder "⁽" U+207D et "⁾" U+207E par "(" et ")". ibidem
		* Redonder "⁼" U+207C par "=" à la place de "≦" U+2266, qui est en composition. ibidem
	* Hatchek :
		* Redonder "₊" U+208A et "₋" U+208B par "+" et "-". ibidem
		* Redonder "₍" U+208D et "₎" U+208E par "(" et ")". ibidem
		* Redonder "₌" U+208C par "=" à la place de "≧" U+2267, qui est en composition. ibidem
	* Drapeau :
		* Redonder "🏳" U+1F3F3 par "/". compose-2.yml [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661)
		* Redonder "🏴" U+1F3F4 par "·­" U+00B7 et par "\". ibidem
	* Cédille > cédille en chef :
		* Supprimer "ʻ" U+02BB, qui est dans le groupe 1 de "`". compose-2.yml [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc)
		* Corriger la saisie de "̒" U+0312. ibidem
	* Tréma :
		* Redonder "⁺" U+207A par "+". compose-2.yml [eeb6a3d](https://github.com/dispoclavier/nouvel-azerty/commit/eeb6a3d66bb7d832f3f63839c87e96c6267852be)
		* Redonder "⁻" U+207B par "-" à la place de "⹀" U+2E40, qui est dans drapeau. ibidem
		* Redonder "⁽" U+207D et "⁾" U+207E par "(" et ")". ibidem
		* Redonder "⁼" U+207C par "=". ibidem
	* Groupes 11 et 12 : Réserver à Windows le demi-codet haut saisi par "0" ou par "5". compose-3.yml [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661)
	* Désactiver les équivalents en composition en conflit avec des séquences de composition. compose-2.yml, compose-3.yml [ea26e6a](https://github.com/dispoclavier/nouvel-azerty/commit/ea26e6a11a048595abd47c4edec466d07ed2bad6), [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43), [29475d5](https://github.com/dispoclavier/nouvel-azerty/commit/29475d5933ca92aeaad314dbc86926225e7e1c27), [6fcba08](https://github.com/dispoclavier/nouvel-azerty/commit/6fcba08a7a7aeafa3559f475568e4342100773f6), [f7ba731](https://github.com/dispoclavier/nouvel-azerty/commit/f7ba731161cd78723dc5d753b7fb14b01331659e), [5584578](https://github.com/dispoclavier/nouvel-azerty/commit/55845785b054fe0cc3d23c1397c57353959063fd), [4c8abff](https://github.com/dispoclavier/nouvel-azerty/commit/4c8abff6048a27a983b8f4d087165aa35f26cf24), [4f61efe](https://github.com/dispoclavier/nouvel-azerty/commit/4f61efe9f6db4c584ccfb1c2cb1bae9209b9375a), [9408d8b](https://github.com/dispoclavier/nouvel-azerty/commit/9408d8bfa8393e1abf92e2a21e86fbfd7ba4a1e9), [569fa31](https://github.com/dispoclavier/nouvel-azerty/commit/569fa31642b7fc9b405205330394ae56994f4fc9), [df87858](https://github.com/dispoclavier/nouvel-azerty/commit/df8785820a88825df2355558f3a5bb269679cca4), [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359), [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc), [e2171d1](https://github.com/dispoclavier/nouvel-azerty/commit/e2171d1e3b82f6a2afda0d9e72bf25bcf4ae0cd4), [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661)
* Documentation :
	* Mettre à jour les modes d’emploi. readme.md alias Mode-d-emploi-commun.pdf [e7ac701](https://github.com/dispoclavier/nouvel-azerty/commit/e7ac701df08201c90391f67eeec176b440ec9d07), linux-chromeos/readme.md alias Mode-d-emploi-sous-Linux.pdf [e6047b6](https://github.com/dispoclavier/nouvel-azerty/commit/e6047b6a6978d364a9a9a2c2a6a27065a3211d76), windows/readme.md alias Mode-d-emploi-sous-Windows.pdf [0231c52](https://github.com/dispoclavier/nouvel-azerty/commit/0231c52fc2f8529ff2e0773defcfe5033bc93655)
	* Ajouter, corriger ou mettre à jour des annotations. kbdeadtrans.c [e6a2080](https://github.com/dispoclavier/nouvel-azerty/commit/e6a2080efb0b5ec6cead95a8cb7cbff29db1aff8), compose-1.yml, compose-2.yml [ea26e6a](https://github.com/dispoclavier/nouvel-azerty/commit/ea26e6a11a048595abd47c4edec466d07ed2bad6), [9cf17f3](https://github.com/dispoclavier/nouvel-azerty/commit/9cf17f35b4926411ade13ae643216e14517e75e6), [09e7d3e](https://github.com/dispoclavier/nouvel-azerty/commit/09e7d3e8be5969e3808a34acdbd20cf675dbed43), [eeb6a3d](https://github.com/dispoclavier/nouvel-azerty/commit/eeb6a3d66bb7d832f3f63839c87e96c6267852be), [29475d5](https://github.com/dispoclavier/nouvel-azerty/commit/29475d5933ca92aeaad314dbc86926225e7e1c27), [df62a94](https://github.com/dispoclavier/nouvel-azerty/commit/df62a9462d4f34881e21198ae63afd0e1ea18234), [6fcba08](https://github.com/dispoclavier/nouvel-azerty/commit/6fcba08a7a7aeafa3559f475568e4342100773f6), [f7ba731](https://github.com/dispoclavier/nouvel-azerty/commit/f7ba731161cd78723dc5d753b7fb14b01331659e), [5584578](https://github.com/dispoclavier/nouvel-azerty/commit/55845785b054fe0cc3d23c1397c57353959063fd), [4c8abff](https://github.com/dispoclavier/nouvel-azerty/commit/4c8abff6048a27a983b8f4d087165aa35f26cf24), [4f61efe](https://github.com/dispoclavier/nouvel-azerty/commit/4f61efe9f6db4c584ccfb1c2cb1bae9209b9375a), [569fa31](https://github.com/dispoclavier/nouvel-azerty/commit/569fa31642b7fc9b405205330394ae56994f4fc9), [8a9b510](https://github.com/dispoclavier/nouvel-azerty/commit/8a9b51031faf13069541e75bf49d125f3561f8fc), [e1e45ad](https://github.com/dispoclavier/nouvel-azerty/commit/e1e45adfc32add34e43cf4e60120711618f1f832), [4854bde](https://github.com/dispoclavier/nouvel-azerty/commit/4854bdeb6e3562eb0c29b7340564ce65b50a6359), [f2a55b5](https://github.com/dispoclavier/nouvel-azerty/commit/f2a55b54db0e31fc23610766e5e2283a498f5abc), [120f2ba](https://github.com/dispoclavier/nouvel-azerty/commit/120f2ba87901fed976b090380fee18b97e4bc78c), [e2171d1](https://github.com/dispoclavier/nouvel-azerty/commit/e2171d1e3b82f6a2afda0d9e72bf25bcf4ae0cd4), [26cb429](https://github.com/dispoclavier/nouvel-azerty/commit/26cb42989e9b76ce9167682f394cd4e58e8d7661), [e7348e0](https://github.com/dispoclavier/nouvel-azerty/commit/e7348e080f713993ad408cbbfb665819e032f183)
* Builds :
	* 6.2.6.0 [956cab8](https://github.com/dispoclavier/nouvel-azerty/commit/956cab87715b88673d3f678eb26d2ff245a4862e)
	* 6.2.6.1 [040ed2b](https://github.com/dispoclavier/nouvel-azerty/commit/040ed2b0d6612d1361417ab1cd709581737d3475)

## Pour Windows

Les touches vives et les touches mortes y compris la touche de composition de la version pour Windows sont à jour, mais sans les équivalents en composition des touches mortes, trop lourds pour Windows, qui tomberait en panne s’ils étaient pris en charge.

La variante AZERTY pour la langue bretonne, celle pour la Polynésie française, celle pour l’Afrique francophone ainsi que la variante redisposée de base sont déjà fournies, et toutes les sous-variantes sont prises en charge par fichiers d’entrées d’inscription .reg pour le Registre.

### Installation

Télécharger le paquet « [Un-nouvel-AZERTY-Windows-6.2.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.6/Un-nouvel-AZERTY-Windows-6.2.6.zip) » ou le paquet « [Un-nouvel-AZERTY-Windows-variantes-6.2.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.6/Un-nouvel-AZERTY-Windows-variantes-6.2.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Démarrage-rapide.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/D%C3%A9marrage-rapide.md) » ou dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/Lisez-moi-svp.md) ».

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

## Pour Linux

Les touches vives et les touches mortes y compris la touche de composition de la version pour Linux sont à jour.

Toutes les variantes AZERTY ou redisposées sont incluses pour installation et fournies pour activation, et toutes les sous-variantes sont pareillement prises en charge.

### Activation ou installation

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-6.2.6.zip](https://github.com/dispoclavier/nouvel-azerty/releases/download/6.2.6/Un-nouvel-AZERTY-Linux-6.2.6.zip) » sous le titre « Assets », l’extraire, et procéder comme indiqué dans « [Lisez-moi-svp.pdf](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.md) ».

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

| Dernière mise à jour : 2026-03-16 |
|-|

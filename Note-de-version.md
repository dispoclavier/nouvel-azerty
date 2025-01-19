## 4.17.0 (2025-01-19)

Simplification des nombres cerclés et de nombreuses séquences de composition.

Amélioration de la prise en charge des symboles de recyclage.

## Modifications

* Composition :
	* Déboguer "ℊ" U210A, "ℋ" U210B, "ℐ" U2110, "ℒ" U2112, "ℓ" U2113, "℘" U2118, "ℛ" U211B, "ℬ" U212C, "ℯ" U212F, "ℰ" U2130, "ℱ" U2131, "ℳ" U2133, "ℴ" U2134. compose-1.yml [74fec91](https://github.com/dispoclavier/nouvel-azerty/commit/74fec9174c2db2b021320e5cc0cae29e254bd8f7)
	* Prendre en charge les nombres cerclés à la place de la touche morte Brève inversée. compose-1.yml [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8)
	* Simplifier les séquences des nombres cerclés. ibidem, compose-1.yml [7a5cb48](https://github.com/dispoclavier/nouvel-azerty/commit/7a5cb485b7065b34ea5325e234f728b7dc5a23a7)
	* Redonder les symboles de recyclage "♲" U2672, "♳" U2673, "♴" U2674, "♵" U2675, "♶" U2676, "♷" U2677, "♸" U2678, "♹" U2679, "♺" U267A, "♻" U267B par des sigles. compose-1.yml [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [f6383f4](https://github.com/dispoclavier/nouvel-azerty/commit/f6383f4e84ab90e1f04f3c2034dc831f403cf69e), [6f8ceeb](https://github.com/dispoclavier/nouvel-azerty/commit/6f8ceebb64353638181c8ea1aa51e49adb900944), [90ee438](https://github.com/dispoclavier/nouvel-azerty/commit/90ee438b4f7443052c501f6c39146fe67f1b3219), [09dcc1c](https://github.com/dispoclavier/nouvel-azerty/commit/09dcc1c1efb3e982ea25302da7b5ee4866dc4288), compose-2.yml [02a50f2](https://github.com/dispoclavier/nouvel-azerty/commit/02a50f2d473f340d2fdf449d3e5834620abb0ab8), compose-3.yml [e2d8f8f](https://github.com/dispoclavier/nouvel-azerty/commit/e2d8f8fa90cec54e93b2120394536d53b3bbde39)
	* Simplifier la séquence « ¦0/3 » de "↉" U2189 en « ¦0/ ». compose-1.yml [b9351a4](https://github.com/dispoclavier/nouvel-azerty/commit/b9351a4b4a5cf16439dab59c5cdf69cd9777a0b8)
	* Supprimer les caractères non critiques à la fin des séquences de "⇇" U21C7, "⇈" U21C8, "⇊" U21CA, "∯" U222F, "⋑" U22D1, "⟁" U27C1, "⦀" U2980, "⧈" U29C8, "⩎" U2A4E, "⩏" U2A4F, "⩓" U2A53, "⪢" U2AA2. compose-1.yml [7a5cb48](https://github.com/dispoclavier/nouvel-azerty/commit/7a5cb485b7065b34ea5325e234f728b7dc5a23a7)
	* Simplifier ou corriger les séquences de "⧉" U29C9. ibidem, compose-1.yml [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212)
	* Simplifier ou corriger les séquences de "ℬ" U212C, "ℵ" U2135, "ℶ" U2136, "∛" U221B, "∜" U221C, "∰" U2230, "♈" U2648, "♎" U264E, "♒" U2652, "♠" U2660, "♣" U2663, "⟠" U27E0, "⟵" U27F5, "⧞" U29DE, "⧻" U29FB, "⨌" U2A0C, "⨹" U2A39, "⨻" U2A3B, "⩘" U2A58, "⩚" U2A5A, "⫸" U2AF8, "⬱" U2B31, "꜡" UA721, "👈" U1F448, "👉" U1F449. compose-1.yml [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212)
	* Simplifier ou corriger les séquences de "϶" U03F6, "•" U2022, "ℂ" U2102, "ℭ" U212D, "ℰ" U2130, "ℸ" U2138, "ⅅ" U2145, "∄" U2204, "∇" U2207, "∐" U2210, "≜" U225C, "⋒" U22D2, "⋓" U22D3, "⌧" U2327, "⎄" U2384, "⎈" U2388, "⎋" U238B, "▪" U25AA, "▫" U25AB, "◦" U25E6, "♋" U264B, "✉" U2709, "⤾" U293E, "⫒" U2AD2. compose-1.yml [25d7ca8](https://github.com/dispoclavier/nouvel-azerty/commit/25d7ca85d883a34b0919af308b878cc0167a7567)
	* Simplifier ou corriger les séquences de "‣" U2023, "⁌" U204C, "⁍" U204D, "ℇ" U2107, "Ω" U2126, "℧" U2127, "∅" U2205, "∎" U220E, "⊛" U229B, "⌧" U2327, "▫" U25AB, "▴" U25B4, "▵" U25B5, "▾" U25BE, "▿" U25BF, "◂" U25C2, "◑" U25D1, "◒" U25D2, "◓" U25D3, "◦" U25E6, "☆" U2606, "☚" U261A, "☛" U261B, "⛎" U26CE, "⟴" U27F4, "⦷" U29B7, "⦹" U29B9, "⦺" U29BA, "⦻" U29BB, "⦼" U29BC, "⦽" U29BD, "⧀" U29C0, "⧁" U29C1, "⧬" U29EC, "⧭" U29ED, "⨀" U2A00, "🅭" U1F16D, "🅯" U1F16F. compose-1.yml [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb)
	* Simplifier ou corriger les séquences de "᷉" U1DC9, "᷏" U1DCF, "᷐" U1DD0, "᷒" U1DD2, "⁡" U2061, "⁢" U2062, "⁣" U2063, "⁤" U2064, "⃐" U20D0, "⃑" U20D1, "⃔" U20D4, "⃕" U20D5, "⃖" U20D6, "⃗" U20D7, "⃚" U20DA, "⃜" U20DC, "⃡" U20E1, "⃥" U20E5, "⃦" U20E6, "⃫" U20EB, "⃬" U20EC, "⃭" U20ED, "⃮" U20EE, "⃯" U20EF, "⅋" U214B, "↼" U21BC, "⥊" U294A, "⥌" U294C, "⥎" U294E, "⥏" U294F, "⥚" U295A, "⥜" U295C, "⥢" U2962, "⥣" U2963, "⥦" U2966, "⥪" U296A, "⥯" U296F, "⩯" U2A6F, "⫨" U2AE8, "⫩" U2AE9, "ꝰ" UA770, "𐞈" U10788, "𐞉" U10789, "𐞊" U1078A, "𐞐" U10790, "𐞞" U1079E, "𐞟" U1079F, "𐞫" U107AB, "𐞭" U107AD, "𐞮" U107AE. compose-1.yml [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db)
* Transformations :
	* Lettres pour les langues du Togo : Flexibiliser la sélection de groupe. compose-2.yml [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
	* Exposant et crosse : Dupliquer la plupart des lettres d’exposant et boucle. ibidem
	* Suscrit > Suscrit et cédille : Ajouter pour redonder "ᷗ" U1DD7. ibidem
	* Suscrit > Suscrit et tréma : Ajouter pour redonder "ᷲ" U1DF2, "ᷳ" U1DF3, "ᷴ" U1DF4. ibidem
	* Grec ou cerclé :
		* Prendre en charge les nombres cerclés. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
		* Redonder "⨸" U2A38. compose-2.yml [6d79c07](https://github.com/dispoclavier/nouvel-azerty/commit/6d79c07750106186bb7172ac933c28388a870eff)
	* Grec ou cerclé > cerclé :
		* Prendre en charge les nombres double-cerclés. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
		* Redonder "⧀" U29C0, "⧁" U29C1, "⨷" U2A37, "⨸" U2A38. compose-2.yml [6d79c07](https://github.com/dispoclavier/nouvel-azerty/commit/6d79c07750106186bb7172ac933c28388a870eff)
	* Grec ou cerclé > double-cerclé : Supprimer. compose-2.yml [07b6f3f](https://github.com/dispoclavier/nouvel-azerty/commit/07b6f3f9334f005f22d50a0570e65cd4a80ef453)
	* Brève inversée : Supprimer les nombres cerclés. ibidem
	* Accent aigu > Accent aigu et accent grave et accent aigu : Simplifier en supprimant les caractères de base. compose-2.yml [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
* Documentation :
	* Intégrer l’article indéfini dans les noms des dossiers téléchargeables et dans les noms de fichier de la documentation en PDF. Lisez-moi-svp.txt [69f833c](https://github.com/dispoclavier/nouvel-azerty/commit/69f833cbd7b26f4bfdfae2a9039924286a02a67a), linux-chromeos/readme.md [5eac510](https://github.com/dispoclavier/nouvel-azerty/commit/5eac51051dcb1921dc357bd60826b4503e7de87c), windows/readme.md [0fac9aa](https://github.com/dispoclavier/nouvel-azerty/commit/0fac9aa9d6f5a87651170aacb91e9513e6e7461c), Note-de-version.md [29c9fca](https://github.com/dispoclavier/nouvel-azerty/commit/29c9fca067f536144ee4863de0529117e6efc9a6)
	* Corriger le code. compose-2.yml [7d8c415](https://github.com/dispoclavier/nouvel-azerty/commit/7d8c41567ec0beddeb9a6ca5b543d99eb0da52db)
	* Corriger et compléter des annotations. compose-1.yml [212dee8](https://github.com/dispoclavier/nouvel-azerty/commit/212dee873e557c61e3a8df21be470edbf7ff1ad2), [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8), [fcc0cfe](https://github.com/dispoclavier/nouvel-azerty/commit/fcc0cfe45e58f0958e6257db876af94d5e0a9212), [74fec91](https://github.com/dispoclavier/nouvel-azerty/commit/74fec9174c2db2b021320e5cc0cae29e254bd8f7), [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [db5f40d](https://github.com/dispoclavier/nouvel-azerty/commit/db5f40d792b5229916a39730189f6dc788f190a1), [0f0d86a](https://github.com/dispoclavier/nouvel-azerty/commit/0f0d86a66ac1d710cbcca26fce4b477d4b9f067c), [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db), compose-2.yml [41be644](https://github.com/dispoclavier/nouvel-azerty/commit/41be64425c8506414374d48d22677329c0ea5a5f), [01dc79b](https://github.com/dispoclavier/nouvel-azerty/commit/01dc79bdba68aeee891838eb31915e3004d0a58e), [cd7aa79](https://github.com/dispoclavier/nouvel-azerty/commit/cd7aa794ad459cc97efa717d1e00c76865a72934)
	* Ajouter le code des vues. nouvel-azerty.json, nouvel-azerty-verrcap.json, nouvel-azerty-verrmod.json, nouvel-azerty-verrmod-verrcap.json, qzjfgy.json [44b72f3](https://github.com/dispoclavier/nouvel-azerty/commit/44b72f3e2597a9949010f157471012db3af8163e), readme.md [af1bd30](https://github.com/dispoclavier/nouvel-azerty/commit/af1bd3065f1941f77e4f61000278ac5efc94857a)
	* Afficher la vue redisposée. windows/qzjfgy/readme.md [7d67c86](https://github.com/dispoclavier/nouvel-azerty/commit/7d67c869a93e66e474600f09f056c33d5ea9c02c)
	* Améliorer le tri. compose-1.yml [212dee8](https://github.com/dispoclavier/nouvel-azerty/commit/212dee873e557c61e3a8df21be470edbf7ff1ad2), [b9351a4](https://github.com/dispoclavier/nouvel-azerty/commit/b9351a4b4a5cf16439dab59c5cdf69cd9777a0b8), [599d3dd](https://github.com/dispoclavier/nouvel-azerty/commit/599d3dd09b969e0ea6ab84a7fa8b4c71f4cf00ae), [01ffad1](https://github.com/dispoclavier/nouvel-azerty/commit/01ffad1ae691d6c5888e9be3447daefa0a2df2bd), [27e3c4d](https://github.com/dispoclavier/nouvel-azerty/commit/27e3c4d699cf1cc20ee1dfbcf78ae6dd26e4dfa8), [d7c5ebc](https://github.com/dispoclavier/nouvel-azerty/commit/d7c5ebcafd010b25b5fa65187831fda98d6e73fb), [db5f40d](https://github.com/dispoclavier/nouvel-azerty/commit/db5f40d792b5229916a39730189f6dc788f190a1), [38e6b9c](https://github.com/dispoclavier/nouvel-azerty/commit/38e6b9c2dbf82307ab6a5bc8eebb11f6410613db)

## Un nouvel AZERTY pour Windows

En cours de réimplémentation, la version pour Windows est disponible sous forme de pilotes d’essai dans le dossier [Un-nouvel-AZERTY-Windows-4.17.0.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Windows-4.17.0.0.zip).

### Installation

Télécharger le dossier « `Un-nouvel-AZERTY-Windows-4.17.0.0.zip` » sous le titre « Assets », l’extraire, aller dans le dossier dont le nom finit en « (installation) », puis dans celui qui commence par « kbfrFRs » (« kbfrFRs v4.17.0.0 installation ») et lancer le setup.exe. S’ouvre alors une fenêtre « Windows a protégé votre ordinateur », où il faut cliquer sur « Informations complémentaires » puis sur « Exécuter quand même ». Puis se laisser guider par le « France AZERTY semi-automatique Setup Wizard ». Une fois fini, il faut redémarrer l’ordinateur pour que la nouvelle disposition apparaisse dans la barre des langues près de l’horloge dans la barre des tâches.

## Un nouvel AZERTY pour Linux

Les dernières [versions de Linux sont défectueuses](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#installation) au niveau du commutateur de dispositions de clavier.

### Utilisation sans droits d’administrateur

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.17.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.17.0.zip) » sous le titre « Assets », et lancer le script d’activation [activer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/activer.sh) ou suivre le mode d’emploi dans le fichier [Lisez-moi-svp.txt](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/Lisez-moi-svp.txt) inclus dans ce dossier.

Cette méthode est la seule qui fonctionne sous [Linux Mint](https://www.linuxmint.com/edition.php?id=311) à cause de [bogues dans XKB sous Linux Mint](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#linux-mint).

### Installation

Sous les versions de Linux postérieures à [Ubuntu 16.04](https://releases.ubuntu.com/16.04/) ou équivalent, il ne paraît pas possible d’alterner entre plusieurs dispositions de clavier, mais on peut changer de disposition en désactivant l’ancienne après avoir activé la nouvelle.

Télécharger le dossier « [Un-nouvel-AZERTY-Linux-4.17.0.zip](https://github.com/dispoclavier/nouvel-azerty/releases/latest/download/Un-nouvel-AZERTY-Linux-4.17.0.zip) » sous le titre « Assets », et lancer le script [installer.sh](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/outils/installer.sh) ou installer chaque fichier [manuellement](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md).

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

# Journal des modifications

## 1.0.7 (2023-08-19)

* Séquences de composition : Déboguer la saisie de "⎋" U238B. (compose-1.yml [5d3f7a6](https://github.com/dispoclavier/nouvel-azerty/commit/5d3f7a618c77f2e01d23def1d93efeac0722a7ec))
* Séquences de composition : Ajouter le caractère de "▮" openrectbullet # U25AE. (compose-1.yml [c1d9ec1](https://github.com/dispoclavier/nouvel-azerty/commit/c1d9ec15431e67f09f93d1b81f52ffa866207b7c))
* Séquences de composition : Ajouter les contrôles bidirectionnels manquants. Ajouter la séquence `en_US.UTF-8/Compose`. (compose-1.yml [b253e1f](https://github.com/dispoclavier/nouvel-azerty/commit/b253e1f1a02f88667875ac9ee50832f1150c4005))
* Touches mortes : Point souscrit : Alerter sur la confusion des glyphes entre "⸪" U2E2A, "⸫" U2E2B, "⸬" U2E2C. (compose-2.yml [1782bca](https://github.com/dispoclavier/nouvel-azerty/commit/1782bcaa2011deaa6f039302de3b2fa4f4b518c9))
* Personnalisation : Simplifier le code de la barre d’espace. (dispocla.cpp [4c4a106](https://github.com/dispoclavier/nouvel-azerty/commit/4c4a106ff4921c1adae901f0e5e3b6e54a076c47), dispotypes.c [763d8b0](https://github.com/dispoclavier/nouvel-azerty/commit/763d8b0dc11221c335c1375e59f3f28960901cee))
* Personnalisation : Simplifier le code des touches B07..B10. (dispocla.cpp [84d81db](https://github.com/dispoclavier/nouvel-azerty/commit/84d81dbf7fd34ac78fbab69db294cbd344e4018f), [08a425e](https://github.com/dispoclavier/nouvel-azerty/commit/08a425e4646dda045406b199198c6484b9d4a3ed), dispotypes.c [5acd8f8](https://github.com/dispoclavier/nouvel-azerty/commit/5acd8f8bdaaca2543f1a07b65954f3490d04b4e6), [074154a](https://github.com/dispoclavier/nouvel-azerty/commit/074154a4411c635d4d7f0eabe53ac3d412766e84), [3537120](https://github.com/dispoclavier/nouvel-azerty/commit/3537120e6583430f167af227d775ff835dac995a), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0))
* Personnalisation : Simplifier le code des touches B01..B06, C01..D12. (dispocla.cpp [9485620](https://github.com/dispoclavier/nouvel-azerty/commit/9485620a726089ad6268f93cb6bbf2e315d3af7a), [6198799](https://github.com/dispoclavier/nouvel-azerty/commit/6198799c997d10faaf65eedac93ca94c7a5b1b13), [907ff0e](https://github.com/dispoclavier/nouvel-azerty/commit/907ff0e6517603c96667415223bdde3d2b33802c), dispotypes.c [1246e6d](https://github.com/dispoclavier/nouvel-azerty/commit/1246e6d4cbb109329649f9740a2a22131e0054c0), [89f1d98](https://github.com/dispoclavier/nouvel-azerty/commit/89f1d9823390ef2b6548e234b410308b07eb36f5), [cb5ab2a](https://github.com/dispoclavier/nouvel-azerty/commit/cb5ab2af0e965736278c55d6d72b0751c4b4802f), [ab6b2d6](https://github.com/dispoclavier/nouvel-azerty/commit/ab6b2d6a79067556ccc8d69793710004b9aae9d0))
* Variantes : Supprimer provisoirement les 2 variantes pour le Canada et la variante pour la Suisse pour faciliter la maintenance. (dispocla.cpp [bd73f72](https://github.com/dispoclavier/nouvel-azerty/commit/bd73f72760988046ca1c9fcdaeba0ff59e577408))
* Variantes : Supprimer définitivement les 3 variantes hybrides. (dispocla.cpp [31919ac](https://github.com/dispoclavier/nouvel-azerty/commit/31919ac3fa37cfb3114762809c6ecd39f0f0d3b3))

## 1.0.6 (2023-08-15)

* Séquences de composition : Compléter les séquences de "♥" U2665. (compose-1.yml [26166c2](https://github.com/dispoclavier/nouvel-azerty/commit/26166c2b5740016b4265cce3db5e80aa7b130e49))
* Touches mortes : Accent circonflexe : Désactiver les chiffres en exposant. Tréma : Ajouter les chiffres en exposant. Hatchek : Ajouter l’équivalent en composition des chiffres en indice. (compose-2.yml [1485b62](https://github.com/dispoclavier/nouvel-azerty/commit/1485b62fe83adb9cc72296d3dbbf71f8991fb123))
* Touches mortes : Tréma : Supprimer les ponctuations à base de chiffres. Point souscrit : Ajouter ces ponctuations et les compléter. (compose-2.yml [310cbde](https://github.com/dispoclavier/nouvel-azerty/commit/310cbde97cd94aecaae1d39d8b8936cafd001f5b))
* Touches mortes : Ajouter l’équivalent en composition partout où il manquait. Supprimer ou déplacer les séquences en conflit. (compose-1.yml [45a1a5d](https://github.com/dispoclavier/nouvel-azerty/commit/45a1a5d2d0fc4b2efeaf3b8bd5d1cf6618bb015c), compose-2.yml [8a8db25](https://github.com/dispoclavier/nouvel-azerty/commit/8a8db25f6c2f20fc141dbd946d3a8059406f6bdc))
* Touches mortes : Tréma : Supprimer "≔" U2254, "⹀" U2E40. (compose-2.yml [c231922](https://github.com/dispoclavier/nouvel-azerty/commit/c231922e1e83a7c3073496fdf7ba50a0cb5c4bce))
* Prendre en charge le pavé numérique dans les séquences de composition et de touches mortes. (compose-1.yml [a45dd68](https://github.com/dispoclavier/nouvel-azerty/commit/a45dd684b7fe473a1a5ccd9a9c983691bf9970e3), compose-2.yml [4e15ea0](https://github.com/dispoclavier/nouvel-azerty/commit/4e15ea0ed390df4b30d15cf36c9912c832043989))

## 1.0.5 (2023-08-11)

* Symboles mathématiques : Corriger les séquences de composition de "⋶" U22F6, "⋷" U22F7, "⋽" U22FD, "⋾" U22FE. (compose-1.yml [4bd82a7](https://github.com/dispoclavier/nouvel-azerty/commit/4bd82a7cba326cca12e43042fb9977488d522d00))
* Séquences de composition : Résoudre les conflits de "Ƨ" U01A7 à "ƅ" U0185 avec "˩" U02E9 à "˥" U02E5. Compléter les séquences de "˩" U02E9 à "˥" U02E5. Résoudre le conflit de "🅭" U1F16D avec "©" U00A9. (compose-1.yml [57c4a09](https://github.com/dispoclavier/nouvel-azerty/commit/57c4a09e0775f80f8c377131c1d3e928e27808a4))
* Séquences de composition : Compléter les séquences de "🅯" U1F16F. Compléter les séquences de "✀" U2700 à "✄" U2704. (compose-1.yml [4dab06f](https://github.com/dispoclavier/nouvel-azerty/commit/4dab06f19342b00324d8a92aa1fba4348e31169c))
* Séquences de composition : Corriger la séquence de "♥️" U2665. (compose-1.yml [b9922dd](https://github.com/dispoclavier/nouvel-azerty/commit/b9922dd39253485c707e4047eb088987e505fea4))
* Séquences de composition : Ôter le sélecteur de variante style émoji de la sortie de "♥" U2665, "⚡" U26A1 et "✴" U2734. (compose-1.yml [13eefac](https://github.com/dispoclavier/nouvel-azerty/commit/13eefacd48cf9e73fa36cde0d6e64ce5e32ff667), compose-2.yml [5c9eec9](https://github.com/dispoclavier/nouvel-azerty/commit/5c9eec960f100518f62b3c62e2a094473719fae1), [48372c5](https://github.com/dispoclavier/nouvel-azerty/commit/48372c506def69f974704d75084bcbdf6f3163bb))
* Symboles mathématiques : Corriger les séquences de composition de "‖" U2016, "⃛" U20DB, "⃜" U20DC, "⇇" U21C7, "⇇" U21C7, "⇈" U21C8, "⇉" U21C9, "⇊" U21CA, "⇶" U21F6, "√" U221A, "∛" U221B, "∜" U221C, "∬" U222C, "∭" U222D, "∯" U222F, "∰" U2230, "⋐" U22D0, "⋑" U22D1, "⋒" U22D2, "⋓" U22D3, "♠" U2660, "♡" U2661, "⟁" U27C1, "⦀" U2980, "⧈" U29C8, "⧉" U29C9, "⧻" U29FB, "⨌" U2A0C, "⩎" U2A4E, "⩏" U2A4F, "⩓" U2A53, "⩔" U2A54, "⪡" U2AA1, "⪢" U2AA2, "⪣" U2AA3, "⫷" U2AF7, "⫸" U2AF8, "⬱" U2B31. Compléter les séquences de composition de "★" U2605, "☆" U2606, "♀" U2640, "♂" U2642. (compose-1.yml [0ef0194](https://github.com/dispoclavier/nouvel-azerty/commit/0ef019419172a2b22b343a75241cda914335eca4))
* Touches mortes : Accent circonflexe, hatchek : Désactiver l’équivalent en composition des chiffres en exposant ou indice à cause du conflit entre "³" U00B3 et "❤" U2764. (compose-2.yml [3cf1d35](https://github.com/dispoclavier/nouvel-azerty/commit/3cf1d35f46b3c380e05deb33fdd0078545931bb0), [7e0b9ce](https://github.com/dispoclavier/nouvel-azerty/commit/7e0b9ce9db86588ebe67c9056a5f33dc302d7004))
* Symboles mathématiques : Corriger les séquences de composition de  "⃮" U20EE, "⃯" U20EF, "ℏ" U210F, "ℼ" U213C, "ℽ" U213D, "ℾ" U213E, "ℿ" U213F, "⨋" U2A0B. Compléter les séquences de composition de "⃓" U20D3, "⃚" U20DA, "⃬" U20EC, "⃭" U20ED, "℩" U2129, "⅀" U2140. Écriture : Compléter la séquence de composition de "ẞ" U1E9E. (compose-1.yml [ce4c440](https://github.com/dispoclavier/nouvel-azerty/commit/ce4c440827307ba04b20e9e75b14b5a288bc2eda))
* Symboles mathématiques : Corriger les séquences de composition de "↯" U21AF, "↶" U21B6, "↷" U21B7, "⤸" U2938, "⤻" U293B, "⦔" U2994. Compléter la séquence de composition de "⦓" U2993. (compose-1.yml [196fa3b](https://github.com/dispoclavier/nouvel-azerty/commit/196fa3bc630eb9f1e587a654a653970944516dc6))

## 1.0.4 (2023-07-30)

* Groupes des symboles : Permuter les symboles "⊳" U22B3 et "⊲" U22B2 ainsi que "⊢" U22A2 et "⊣" U22A3. (compose-2.yml [aa77809](https://github.com/dispoclavier/nouvel-azerty/commit/aa77809a03a69eb462cec0d540f6d4dd76b79ab0))
* Groupes des symboles : Remplacer "∁" U2201 par "⟂" U27C2, permuter "ː" U02D0 et "ˑ" U02D1, réarranger "⊢" U22A2, "⊣" U22A3, "⊥" U22A5, "⊤" U22A4, déplacer "⋱" U22F1, "⋰" U22F0, dupliquer "꞉" UA789. (compose-2.yml [13c46b3](https://github.com/dispoclavier/nouvel-azerty/commit/13c46b3783638c6ad6d7c1c62cf3606b071e29cc), [77a281f](https://github.com/dispoclavier/nouvel-azerty/commit/77a281f994ad25cd1e9bb8928eae881596702292), [cae6903](https://github.com/dispoclavier/nouvel-azerty/commit/cae6903280ed2105c27422d9c6524ade4c229cbd))
* Symboles mathématiques : Corriger les séquences de composition de "⨼" U2A3C et "⨽" U2A3D. (compose-1.yml [7f7615a](https://github.com/dispoclavier/nouvel-azerty/commit/7f7615ad97212712585262e528a2cd253c1315e2))
* Touches mortes : Supprimer la touche morte virtuelle double frappe d’accent aigu. (compose-1.yml [90ca4fe](https://github.com/dispoclavier/nouvel-azerty/commit/90ca4fed7741528d890334352e807042e3e5798f))
* Touches mortes : Ajouter la prise en charge de l’apostrophe ASCII comme caractère de base pour la saisie des guillemets apostrophes. (compose-2.yml [2ec9a02](https://github.com/dispoclavier/nouvel-azerty/commit/2ec9a02eb735ad7aa352b5c4a8a8121502eba41d), compose-1.yml [2c5626f](https://github.com/dispoclavier/nouvel-azerty/commit/2c5626f24ea1bce7e1e46525df968ecc839a8df9))
* Touches mortes : Supprimer les touches mortes virtuelles à partir de triple frappe d’accent grave. (compose-1.yml [bef37b4](https://github.com/dispoclavier/nouvel-azerty/commit/bef37b451007ca6ea93b4961eb8eebf7901ba7b7))
* Touches mortes : Accents aigu, grave : Déplacer les diacritiques combinants supplémentaires sur la perluète. (compose-1.yml [f4c1ef6](https://github.com/dispoclavier/nouvel-azerty/commit/f4c1ef6fc90d712606d9ed9b6cd6771b5def6ef0))
* Touches mortes : Accent circonflexe, hatchek : Redonder les diacritiques combinants souscrits sur la perluète. (compose-2.yml [0e3eee2](https://github.com/dispoclavier/nouvel-azerty/commit/0e3eee23ef25fa529643e8a8c64ec360e4777bc7))
* Touches mortes : Brève, brève inversée, tilde : Redonder les diacritiques combinants souscrits sur la perluète ; double accent aigu : supprimer la touche morte virtuelle double frappe. (compose-1.yml [7c66f9e](https://github.com/dispoclavier/nouvel-azerty/commit/7c66f9eb00175be161f15b57997652efaa9c2b02))

## 1.0.3 (2023-07-22)

* Symboles mathématiques : Corriger les séquences de composition des opérateurs invisibles. (compose-1.yml [5a7d1c8](https://github.com/dispoclavier/nouvel-azerty/commit/5a7d1c847cb2c9091037bf2684d85bbbd4f4d2aa))
* Symboles mathématiques : Dupliquer avec guillemet apostrophe les séquences avec apostrophe ASCII autres que les primes. (compose-1.yml [c4bebdc](https://github.com/dispoclavier/nouvel-azerty/commit/c4bebdc9ad993dc1cc2b452934f9c8f7fa617020))
* Symboles mathématiques : Dupliquer avec majuscule les séquences des constantes d’Euler, de Planck et de Planck sur 2π. (compose-1.yml [04ff35f](https://github.com/dispoclavier/nouvel-azerty/commit/04ff35fd21c77219e41459df60dcc1ca16c9006f))
* Symboles mathématiques : Ajouter des séquences basées sur commandes TeX. (compose-1.yml [d46e07a](https://github.com/dispoclavier/nouvel-azerty/commit/d46e07a25f0c5d6e62729c1a81ac67a9eecc30ec))
* Symboles mathématiques : Symbole diamètre : Ajouter des séquences française et française simplifiée. (compose-1.yml [be410ee](https://github.com/dispoclavier/nouvel-azerty/commit/be410ee29032427ea5bef8ea427026f9ad3a4f29))

## v1.0.2 (2023-07-14)

* Ajouter le correctif à faire dans rules/evdev. (dispocla.cpp [afb2e77](https://github.com/dispoclavier/nouvel-azerty/commit/afb2e7707351092a70483116c64be9c8a05b5044))

## v1.0.1 (2023-07-14)

* Régler la touche Retour arrière en mode par défaut. (evdev.c [616da80](https://github.com/dispoclavier/nouvel-azerty/commit/616da804a22914e68665f32d522c7c3c074fc55d))

## v1.0.0 (2023-07-14)

* Publication initiale.

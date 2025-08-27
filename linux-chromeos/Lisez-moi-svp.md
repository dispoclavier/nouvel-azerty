# Un nouvel AZERTY

Simplifier la dactylographie, pas le français.

Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.

Grand public et développeurs, écrivains, éditeurs, journalistes, programmeurs, rédacteurs, scientifiques, secrétaires, traducteurs, typographes.

                   Version : 6.0.4
                      Date : 2025-08-27T2132+0200
              Dépôt GitHub : https://github.com/dispoclavier/nouvel-azerty
             Documentation : https://dispoclavier.com/nouvel-azerty/
              Licence code : Apache 2.0
          URL licence code : https://www.apache.org/licenses/LICENSE-2.0
          Licence non-code : CC-BY 4.0
      URL Licence non-code : https://creativecommons.org/licenses/by/4.0/deed.fr
              Adresse mail : dev[arobase]dispoclavier.com

## Dossiers et fichiers

* Les chaînes de caractères pour touches vives et le contenu des touches mortes se trouvent dans le fichier Compose.yml. (L’extension .yml facilite la coloration syntaxique et l’interopérabilité.)

* Le reste des dispositions de clavier se trouve dans les dossiers installer/ et activer/. Les fichiers .xkb dans activer/ sont issus de la fusion de fichiers comme dans installer/.

### Dispositions de clavier : les variantes

* Les fichiers dont les noms commencent par "nouvel-azerty" contiennent la disposition de base de ce nouvel AZERTY. Ils sont rangés à la racine du dossier activer/, et ils sont identiques aux fichiers dont les noms commencent par "kbfrFRs", qui sont rangés dans un dossier du même nom à l’intérieur du dossier Variantes/.

* Les fichiers dans le dossier kbbrFRs/, dont les noms commencent par "kbbrFRs", contiennent une disposition optimisée pour la langue bretonne, avec le cʼh sur le 1, et le ñ sur le 8.

* Les fichiers dans le dossier kbfrPFs/, dont les noms commencent par "kbfrPFs", contiennent une disposition optimisée pour les langues de Polynésie française, avec une touche morte macron sur le 8, et le ʻeta sur Maj + 8.

* Les fichiers dans le dossier kbfrAFs/, dont les noms commencent par "kbfrAFs", contiennent une disposition optimisée pour les langues d’Afrique, pour le bambara en particulier, avec le ɛ sur le 1, et le ɔ sur le 8.

* Les fichiers dans le dossier kbfrBEs/, dont les noms commencent par "kbfrBEs", contiennent une disposition optimisée pour la Belgique, avec le § sur le 6, le tiret du 6 sur le 8, et le tiret du 8 sur Maj + 8. Cette disposition représente un compromis entre l’AZERTY belge et les fonctionnalités de ce nouvel AZERTY français.

* Les fichiers dont le nom – ou la première partie du nom pour les sous-variantes – se termine en "r" contiennent des dispositions optimisées pour une saisie un peu plus ergonomique de l’alphabet de base et des lettres diacritées, afin que les exigences d’ergonomie n’obligent pas à renoncer aux fonctionnalités de ce nouvel AZERTY.

La variante belge ne se décline pas en variante belge redisposée, parce que l’intérêt d’une variante belge est une plus grande rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

### Options de disposition : les sous-variantes

Outre la disposition standard et ses variantes, des optimisations optionnelles sont disponibles.

* Pour les claviers de portable sans la touche ISO entre Maj gauche et W, où la touche [><] prend la place de Contrôle droite, les touches ISO et Verrouillage Capitales sont permutées afin que la touche ISO, qui est la nouvelle modificatrice AltFr, reste située à gauche pour la saisie des grandes ponctuations espacées et l’utilisation du pavé numérique graphique. Ce sont les sous-variantes avec les suffixes "-ansi", "-ansi-menu", "-ansi-menu-sans".

* Selon une idée originale du Pʳ Yves Neuville, la touche Effacement arrière est mieux en bas. Avec Effacement arrière à droite d’AltGr, un petit geste du pouce remplace un grand mouvement de la main. Sur les claviers de bureau, cet effet est obtenu en plaçant Effacement arrière sur la touche Windows droite. Afin d’éviter d’actionner la touche Menu par erreur, celle-ci est optionnellement désactivée.

    * Les sous-variantes avec le suffixe "-win" ont Effacement arrière sur Windows droite. (Une sous-variante avec Windows droite sur Effacement arrière n’est pas distribuée, mais il est possible de la paramétrer dans le fichier evdev(.c) en installant ce nouvel AZERTY.)

    * Les sous-variantes avec le suffixe "-win-sans" ont Effacement arrière sur Windows droite, et la touche Menu est désactivée pour éviter l’ouverture intempestive du menu contextuel.

    * Les sous-variantes avec les suffixes "-menu" ou "-ansi-menu" ont Effacement arrière sur Menu, et Menu sur Effacement arrière.

    * Les sous-variantes avec les suffixes "-menu-sans" ou "-ansi-menu-sans" ont Effacement arrière sur Menu, tandis que la touche Effacement arrière reste telle quelle afin que des applications puissent lui attribuer des raccourcis comme "deleteLeft", et avec Contrôle, "deleteWordLeft".

    * Les sous-variantes avec le suffixe "-ctrl" ont les touches Effacement arrière et Contrôle droite permutées.


## Installer ou activer

* Activer une disposition de clavier ne nécessite pas de droits d’administrateur et fonctionne aussi sous Linux Mint. La marche à suivre est sous le titre "Comment activer ce nouvel AZERTY".

* Installer toutes les dispositions de clavier de ce nouvel AZERTY permet de passer l’étape d’activation, comme expliqué dans le fichier « Mode-d-emploi-sous-Linux.md ». Le plus simple est d’utiliser le script installer.sh, mais l’installation manuelle est aussi possible.

### Comment activer ce nouvel AZERTY

Linux est affecté par un certain nombre de problèmes détaillés dans le Mode-d-emploi-sous-Linux.pdf. Ainsi prévenu, on peut effectuer les étapes de l’activation.

#### Activation par le script activer.sh

Lancer le script activer.sh et se laisser guider.

Ce script est documenté dans son en-tête, dans le Mode-d-emploi-sous-Linux.pdf, et [sur GitHub](https://github.com/dispoclavier/nouvel-azerty/blob/main/linux-chromeos/readme.md#script-dactivation-mode-demploi).

#### Activation manuelle

1. Ouvrir un terminal dans le dossier personnel et sauvegarder la disposition actuelle dans un fichier que l’on pourra nommer "normal.xkb" et qui servira à revenir à la disposition actuelle sans fermer la session. (Si ":0" ne fonctionne pas, invoquer la variable d’environnement "$DISPLAY" à la place.)

        xkbcomp :0 normal.xkb

2. Copier les fichiers Compose.yml et nouvel-azerty.xkb (ou celui de la variante choisie) vers le dossier personnel.

3. Si le dossier personnel contient déjà un fichier invisible .XCompose, ajouter le contenu du fichier Compose.yml dans ce fichier au début pour ignorer les séquences en conflit, ou à la fin pour remplacer les séquences en conflit. Sinon, renommer Compose.yml en .XCompose. Si les règles de en_US.UTF-8/Compose doivent continuer de s’appliquer si elles ne sont pas en conflit, décommenter la ligne suivante et, si les règles de en_US.UTF-8/Compose sont prioritaires, la placer à la fin du fichier :

        include "%L"

4. Fermer et rouvrir les applications avec saisie de texte, afin d’y activer ce répertoire de touches mortes.

5. Activer ce nouvel AZERTY dans le terminal ouvert au point 1 (en remplaçant le cas échéant "nouvel-azerty.xkb" par le nom de la variante et sous-variante choisie). Il est normal qu’xkbcomp signale qu’aucun symbole n’est défini pour les touches de fonction 19 et 24, ni pour la touche AE13 qui, si elle est présente, se trouve entre Égal et Effacement arrière :

        xkbcomp nouvel-azerty.xkb :0

6. Veiller à ce que le système de saisie au clavier soit XIM. Ce réglage se trouve dans Système > Personnel > Langues > Langue > Méthode d’entrée, ou dans Système > Pays et langue > Système > Gérer les langues installées > Langue > Système de saisie au clavier. On a le choix entre iBus, XIM et Aucun. — Le système de saisie au clavier peut aussi être paramétré en ligne de commande. Pour ce faire, utiliser la commande suivante :

        im-config -n xim

Ce nouvel AZERTY peut maintenant être testé.

La commande pour désactiver ce nouvel AZERTY et réactiver la disposition précédente grâce au fichier mis en place à l’étape 1 est :

        xkbcomp normal.xkb :0

## Témoin lumineux

Le témoin lumineux d’Arrêt Défilement sert de témoin du verrouillage en mode ASCII par la bascule VerrMod sur la touche E00 au-dessus de Tab à gauche du 1.

Ce témoin lumineux manque sur beaucoup d’ordinateurs portables récents, mais il est présent sur la plupart des claviers externes, tels que les claviers compacts USB ou sans fil.

## Personnalisation

Les touches vives sont personnalisables dans le fichier .xkb utilisé pour l’activation, ou dans le fichier dispocla_perso.cpp installé sous le nom dispocla_perso

Les touches mortes sont personnalisables dans le dossier personnel, soit dans le fichier .XCompose qui y a été placé lors de l’activation, soit dans un fichier .XCompose ajouté en plus du fichier Compose.yml installé sous le nom de Compose dans son dossier système.

En ajoutant un fichier .XCompose dans le dossier personnel, il faut y mettre une ligne comme ceci :

    include "%L"

Puis ajouter en dessous, les séquences qui doivent remplacer des séquences existantes,

## Retours d’expérience, suggestions et critiques

N’hésitez pas à envoyer toutes critiques, conseils d’amélioration et retours d’expérience à l’adresse mail dev[arobase]dispoclavier.com.

N’hésitez pas non plus à [créer un rapport de bogue](https://github.com/dispoclavier/nouvel-azerty/issues) dans
le dépôt GitHub de ce nouvel AZERTY, ni à y [lancer une discussion](https://github.com/dispoclavier/nouvel-azerty/discussions).

De nouvelles fonctionnalités peuvent être demandées aussi bien sous forme d’un rapport de bogue que dans une discussion lancée à cet effet.

*Merci d’avance de tout retour.*

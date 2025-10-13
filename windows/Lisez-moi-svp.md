# Un nouvel AZERTY

Simplifier la dactylographie, pas le français.

Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.

Grand public et développeurs, écrivains, éditeurs, journalistes, programmeurs, rédacteurs, scientifiques, secrétaires, traducteurs, typographes.

                   Version : 6.0.10
    Version et nᵒ de build : 6.0.10.0
                      Date : 2025-10-12T1836+0200
              Dépôt GitHub : https://github.com/dispoclavier/nouvel-azerty
             Documentation : https://dispoclavier.com/nouvel-azerty/
              Licence code : Apache 2.0
          URL licence code : https://www.apache.org/licenses/LICENSE-2.0
          Licence non-code : CC-BY 4.0
      URL Licence non-code : https://creativecommons.org/licenses/by/4.0/deed.fr
              Adresse mail : dev[arobase]dispoclavier.com

## Clones de dépannage

Chaque jeu de pilotes de disposition est fourni en double et numéroté 1 et 2, parce que sous Windows, les pilotes de disposition tombent parfois en panne, et avoir un deuxième sous la main évite de redémarrer l’ordinateur tout de suite.

Pour essayer ce nouvel AZERTY, un seul jeu de pilotes suffit, mais pour une utilisation prolongée, installer aussi le deuxième permet de parer à toute éventualité. Cela dit, ces pannes sont quand même assez rares.

## Dossiers et fichiers

* Ce nouvel AZERTY se trouve dans le dossier « installer », dans les sous-dossiers « kbfrFRs1-6.0.10.0 » et « kbfrFRs2-6.0.10.0 », chacun avec ses 4 pilotes de disposition, ses 3 installateurs et son setup.exe.

* Dans le dossier « installer », le sous-dossier « Variantes » contient le reste de la gamme disponible sous Windows :

  * Le dossier « kbbrFRs1-6.0.10.0 » qui contient la variante AZERTY pour la langue bretonne, avec le "cʼh" sur le ⟦1⟧, et le "ñ" sur le ⟦8⟧ à la place du tiret bas (qui est aussi sur AltGr + ⟦J⟧), en Minuscule et en Majuscule.

  * Le dossier « kbfrPFs1-6.0.10.0 » qui contient la variante AZERTY pour la Polynésie française, avec le ʻeta sur le ⟦1⟧, et une touche morte tārava sur le ⟦8⟧.

  * Le dossier « kbfrAFs1-6.0.10.0 » qui contient la variante AZERTY pour l’Afrique francophone, pour le bambara en particulier, avec l’epsilon latin "ɛ" sur le ⟦1⟧, et le o ouvert "ɔ" sur le ⟦8⟧, en Minuscule et en Majuscule.

  * Le dossier « kbfrFRr1-6.0.10.0 » qui contient la variante redisposée de base de ce nouvel AZERTY, disposée en QZJFGY de manière plus ergonomique tout en restant assez proche de l’AZERTY, afin que les exigences d’ergonomie n’obligent pas à renoncer aux fonctionnalités de ce nouvel AZERTY.

* Dans le dossier « redispositions » se trouvent des fichiers d’inscription au Registre avec leur mode d’emploi « _Scancode_Map.pdf », fourni aussi comme fichier texte au format Markdown « _Scancode_Map.md » pour faciliter l’utilisation. Ces fichiers peuvent être utilisés pour mettre en place des redispositions similaires aux sous-variantes sous Linux.

## Installer

Le meilleur mode d’emploi [coule de source sûre dans CCM](https://www.commentcamarche.net/informatique/windows/33353-majuscules-accentuees-windows-quad/) pour une autre disposition de clavier. Il est facilement transposable au cas où.

En cliquant tout de suite sur le setup.exe, on ouvre une fenêtre bleue qui dit :

        Windows a protégé votre ordinateur
        Microsoft Defender SmartScreen a empêché le démarrage d’une application
            non reconnue.
        L’exécution de cette application peut mettre votre ordinateur en danger.
        Informations complémentaires

Prise à la lettre, c’est une fausse alerte, car ce qui « peut mettre votre ordinateur en danger » n’est pas l’« exécution de cette application », mais l’exécution d’une application non reconnue en général. Nuance. Cette application-ci est incapable de mettre votre ordinateur en danger.

Pour passer le Microsoft Defender SmartScreen, vous avez deux options. Pour ne pas le voir, il y a une seule option.

### Comment passer le Microsoft Defender SmartScreen

* Cliquer sur « Informations complémentaires ». Car en plus de celles-ci (« Application : setup.exe Éditeur : Éditeur inconnu ») s’affiche alors un bouton « Exécuter quand même ». Cliquer celui-ci ouvre tout de suite le Setup Wizard de la disposition, qui annonce que l’installation est terminée.

* Ouvrir les propriétés du setup.exe en faisant un clic droit dessus et en cliquant « Propriétés » tout en bas. Car au bas du premier onglet, on peut alors cocher la case « ☐ Débloquer » derrière « Sécurité : Ce fichier provient d’un autre ordinateur et peut éventuellement être bloqué pour protéger cet ordinateur. »

### Les étapes de l’installation

1. Cliquer sur « ☐ Débloquer » derrière « Sécurité : Ce fichier provient d’un autre ordinateur et peut éventuellement être bloqué pour protéger cet ordinateur. »

2. Valider en cliquant sur « OK » ou en appuyant sur Entrée.

3. Cliquer sur le setup.exe. Une fenêtre s’ouvre et se referme immédiatement, dû à un bogue dans ce logiciel pourtant de Microsoft. Il faut patienter 2 ou 3 secondes.

4. La suite dépend des paramètres du Contrôle de compte d’utilisateur. S’ils sont réglés au niveau par défaut, il faut éventuellement aller chercher la fenêtre dans la Barre des tâches, tout à la fin, où apparaît l’icône du Contrôle de compte d’utilisateur, et où il faut cliquer pour que la fenêtre s’affiche. S’ils sont réglés au niveau en dessous, le Bureau n’est pas estompé, et la fenêtre du Contrôle de compte d’utilisateur s’affiche directement, sans qu’il faille aller la chercher.

5. Répondre à la question du Contrôle de compte d’utilisateur : « Voulez-vous autoriser cette application provenant d’un éditeur inconnu à apporter des modifications à votre ordinateur ? » Éventuellement, cliquer sur « Afficher plus de détail » (le singulier est d’origine). Le logiciel indiqué est le *_amd64.msi, non le setup.exe, car celui-ci a déjà lancé le Paquetage pour Installateur Windows qui correspond à l’architecture de l’ordinateur.

6. Si la réponse est « Non », le Setup Wizard de la disposition de clavier indique que l’installation a été interrompue avant que « France AZERTY semi-automatique » a pu être installé, et qu’il faut relancer l’installateur pour essayer de nouveau (au sens où ‹ si jamais…, alors il faudrait… ›).  
  Si au contraire, la réponse est « Oui », le Setup Wizard de la disposition de clavier indique que l’installation est achevée, « Installation Complete », en précisant que la disposition de clavier a été installée avec succès, et invite à cliquer sur « Close » pour le quitter.  
  L’installation ajoute la nouvelle disposition automatiquement aux dispositions de clavier de la langue « Français (France) » mais ne l’ajoute pas tout de suite à la Barre de langues. Si celle-ci ne s’affichait pas, elle reste cachée jusqu’au prochain démarrage. Il en va de même du raccourci Windows + Espace, qui ne permet pas encore de basculer vers la nouvelle disposition.

7. Ouvrir éventuellement les Paramètres par Windows + i et aller dans Heure et langue > Langue > Clavier. Sous le titre « Remplacer la méthode d’entrée par défaut » se trouve un menu déroulant, où choisir « France AZERTY semi-automatique » active celle-ci immédiatement mais l’établit aussi comme disposition de clavier par défaut, jusqu’à nouvel ordre.

8. Après le prochain démarrage apparaît la Barre de langues près de l’horloge dans la Barre des tâches, si elle n’y était déjà, avec dans sa liste, la disposition de clavier « France AZERTY semi-automatique ».

### Comment éviter le Microsoft Defender SmartScreen

La seule manière d’éviter le Microsoft Defender SmartScreen est de louer pour plus de 500 € par an un certificat de signature de code à validation étendue (Extended Validation Code Signing Certificate).

    https://www.reddit.com/r/electronjs/comments/17sizjf/a_guide_to_code_signing_certificates_for_the/
    https://www.sectigo.com/ssl-certificates-tls/code-signing

Ce alors qu’en l’occurrence, les alertes de Windows sont à prendre avec des pincettes, puisque les logiciels critiqués n’ont été générés par rien d’autre qu’une suite de logiciels Microsoft :

* Le Microsoft Keyboard Layout Creator (MSKLC), [distribué par Microsoft à titre gratuit](https://www.microsoft.com/en-us/download/details.aspx?id=102134)

* Le Keyboard Table Generation Tool (Unicode), dont le nom de code est KbdUTool, et qui est inclus dans le MSKLC et utilisable à part en vertu du contrat de licence fourni avec le MSKLC, permettant l’utilisation des composants.

L’affirmation selon laquelle l’éditeur du setup.exe et des trois installateurs *_amd64.msi, *_i386.msi et *_ia64.msi serait inconnu est fausse en l’occurrence, puisque les seules modifications ont été faites par le MSKLC lui-même, en paquetant les pilotes de disposition compilés sur les ordres du KbdUTool.

À ce propos, on peut consulter les métadonnées, par exemple :

        Description :     Keyboard Layout Creator Bootstrap
        Copyright :       Copyright © 2007 Microsoft Corporation
        Type du fichier : Package Windows Installer (.msi)

### Faire compiler les pilotes soi-même

Pour pallier un manque de confiance, on peut toujours faire compiler et paqueter ses propres pilotes. Le logiciel est disponible chez Microsoft (ci-dessus), les sources sont sur GitHub, la licence permet la redistribution, et la marche à suivre est détaillée sur [la page de création de clavier de MNA](http://accentuez.mon.nom.free.fr/Clavier-CreationClavier.php).

Un mode d’emploi de la compilation figure aussi directement dans ce fichier, plus bas sous le titre « Personnalisation ».

Pour l’exhaustivité, le script creadispo.cmd doit aussi être mentionné. Conçu vers 2018 pour offrir une expérience utilisateur conviviale à bas seuil, il a le potentiel de faciliter tout ce travail ; mais étant un script, il nécessite une revue complète avant utilisation et [n’est disponible que sur GitHub](https://github.com/dispoclavier/nouvel-azerty/blob/main/windows/outils/creadispo.cmd), car tout comme les autres outils du projet, il est exclu des paquets de code source téléchargeables.

Une copie de ce script ne peut fonctionner que si elle a été téléchargée en entier, avec l’indicateur d’ordre des octets à son début, car l’IOO (BOM) au début n’est pas copié dans le presse-papiers ; or il est indispensable pour faire tourner sous Windows ce script, qui autrement sort n’importe quoi.

## Dispositions de clavier : les variantes

À présent, seules la disposition de base de ce nouvel AZERTY, la variante AZERTY pour la langue bretonne, et la variante redisposée de base QZJFGY sont disponibles.

À terme, toutes les variantes disponibles sous Linux seront disponibles aussi sous Windows :

* Variantes AZERTY :

    * Breton et français disposition de clavier semi-automatique

    * Polynésie Française disposition de clavier semi-automatique

    * Afrique francophone disposition de clavier semi-automatique

    * Français Belgique disposition de clavier semi-automatique

* Autres variantes redisposées QZJFGY :

    * Breton et français disposition de clavier semi-automatique redisposée

    * Polynésie française disposition de clavier semi-automatique redisposée

    * Afrique francophone disposition de clavier semi-automatique redisposée

La variante belge ne se décline pas en variante redisposée, parce que l’intérêt d’avoir une variante belge est un certain degré de rétrocompatibilité avec l’AZERTY belge, et la redisposition va à l’encontre de cet objectif.

## Options de disposition

Des optimisations optionnelles par redisposition de touches sont possibles indépendamment des pilotes de disposition. Elles font appel au Redisposeur de codes matériels pour claviers, un logiciel de Windows, et elles sont documentées dans le fichier « _Scancode_Map.pdf » dans le dossier « redispositions ».

* Sur les claviers de portable sans la touche ISO entre Maj gauche et W, mais avec un clavier disposé en AZERTY, où la touche ⟦><⟧ prend la place de Contrôle droite, les touches ISO et Verrouillage Capitales doivent être permutées, afin que la touche ISO, qui est la nouvelle modificatrice AltFr, reste située à gauche pour la saisie des grandes ponctuations espacées et l’utilisation du pavé numérique graphique. Ce sont les fichiers d’inscription au Registre dont les noms commencent par "ansi-iso".

* Selon une idée originale du Pʳ Yves Neuville, la touche Effacement arrière est mieux en bas. Avec Effacement arrière à droite d’AltGr, un petit geste du pouce remplace un grand mouvement de la main. Sur les claviers de bureau, cet effet est obtenu en plaçant Effacement arrière sur la touche Windows droite. Afin d’éviter d’actionner la touche Menu par erreur, celle-ci devient optionnellement une troisième touche d’Effacement arrière.

    * Les fichiers d’inscription au Registre dont les noms commencent par "win-dr=" redondent Effacement arrière sur Windows droite.

    * Le fichier d’inscription au Registre "win-dr=ret-arr_sans-menu.reg" redonde Effacement arrière aussi bien sur Windows droite que sur la touche Menu, afin d’éviter l’ouverture intempestive du menu contextuel.

    * Les fichiers d’inscription au Registre dont les noms contiennent "menu" mettent Effacement arrière sur Menu, et Menu sur Effacement arrière sauf si le nom se termine en "_sans-menu".

    * Le fichier d’inscription au Registre "ctrl-dr=x=ret-arr.reg" permute les touches Effacement arrière et Contrôle droite.

## Témoin lumineux

Le témoin lumineux d’Arrêt Défilement devrait pouvoir servir de témoin du verrouillage en mode ASCII par la bascule VerrMod sur la touche E00 au-dessus de Tab à gauche du 1, mais à ce jour, cela fonctionne sous Linux uniquement, sans compter que de nombreux ordinateurs portables sont dépourvus de ce témoin.

Si lors de la saisie de texte français, on s’aperçoit vite dans quel mode on se trouve, cela est possible aussi lors de la saisie de mots de passe, à condition de commencer la saisie par le chiffre 5, car en mode français, la touche ⟦5⟧ de ce nouvel AZERTY est la touche morte tréma, de sorte que l’absence de retour visuel indique tout de suite que le clavier est en mode français.

## Personnalisation

* La plupart des touches vives émettant une seule unité de code sont personnalisables dans la source *.C ou son partiel kbcomazerty.c, dans le tableau static ALLOC_SECTION_LDATA VK_TO_WCHARS33 aVkToWch33[].

* Les touches vives émettant plusieurs unités de code (et quelques-unes qui en émettent une seule) sont personnalisables dans le tableau static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] réparti sur les sources *.C, kbligazerty.c et kbligatures.c.

* Les touches mortes, toutes incapables d’émettre plusieurs unités de code, sont personnalisables dans la source kbdeadtrans.c dans le tableau static ALLOC_SECTION_LDATA DEADKEY aDeadKey[], avec les entrées modifiées placées avant les entrées d’origine.

Ensuite, il faut recompiler les pilotes de disposition comme mentionné sous le titre « Installer » :

1. Télécharger le Microsoft Keyboard Layout Creator (MSKLC) depuis sa page officielle :

        https://www.microsoft.com/en-us/download/details.aspx?id=102134

2. Cliquer sur le fichier MSKLC.exe et valider l’extraction du fichier vers le dossier MSKLC\\.

3. Dans le dossier MSKLC\\, cliquer sur le setup.exe et se laisser guider par le Microsoft Keyboard Layout Creator 1.4 Setup Wizard.

4. Appuyer sur la touche Windows et cliquer sur « Microsoft Keyboard Layout Creator 1.4 » sous le titre « Récemment ajoutées ».

5. Télécharger le code source de ce nouvel AZERTY depuis [la page d’accueil](https://github.com/dispoclavier/nouvel-azerty/archive/refs/heads/main.zip) ou [la page d’une version](https://github.com/dispoclavier/nouvel-azerty/archive/refs/tags/6.0.10.zip).

6. Ouvrir le fichier *.klc dans le MSKLC par Ctrl + O ou par « File > Load Source File… ».

7. Mettre à jour les propriétés par « Project > Properties… » en veillant à ce que les noms de fichier soient égaux au nom de la disposition, champ « Name », et comportent huit lettres ou chiffres ASCII maximum.

8. Faire générer le setup.exe et les trois paquetages d’Installateur Windows *.msi par « Project > Build DLL and Setup Package ». Quatre pilotes, des Dynamic Link Libraries, sont aussi générés mais sont d’une utilité quasi nulle, car ce fichier *.klc est incomplet, faute de quoi il ne pourrait servir à faire tourner le MSKLC et lui faire afficher un aperçu de la disposition, qui correspond à la disposition configurée dans ce fichier mais n’est pas la vraie disposition de ce nouvel AZERTY.

9. Faire compiler les vrais pilotes, les DLL, par le Keyboard Table Generation Tool (Unicode) qui se trouve dans le MSKLC :

        C:\Program Files (x86)\Microsoft Keyboard Layout Creator 1.4\bin\i386\kbdutool.exe

Contrairement à la licence de Windows, la licence du MSKLC n’interdit pas l’utilisation des composants, que Microsoft fournit intentionnellement au détail, sans les envelopper dans un exécutable monolithique.

Pour compiler, il faut mettre la source *.C en lecture seule, et veiller à ce que la source d’en-tête commune kbcommon.H soit aussi présente à côté, ainsi que les sources kbazerty.h, kbcommon.c, kbcomazerty.c, kbdeadtrans.c, kbligatures.c, kbligazerty.c (pour une disposition AZERTY).

Dans une invite de commande ouverte dans le dossier de ces sources, la commande pour le pilote amd64 est :

        "C:\Program Files (x86)\Microsoft Keyboard Layout Creator 1.4\bin\i386\kbdutool.exe" -u -m *.klc

Avec le nom de la disposition à la place de l’astérisque, même avec une seule source *.klc. Puis il faut emballer sans tarder le pilote généré dans son dossier amd64\, car le KbdUTool est incapable de lire un chemin de sortie, sort le pilote directement à côté de la source *.C, et l’écraserait par le suivant, le pilote wow64, généré sur cette commande :

     "C:\Program Files (x86)\Microsoft Keyboard Layout Creator 1.4\bin\i386\kbdutool.exe" -u -o *.klc

10. Enfin, il faut ou bien remplacer les pilotes d’origine dans deux dossiers système :

* amd64 : C:\Windows\System32\

* wow64 : C:\Windows\SysWOW64\

Ou bien, si les noms de fichier ont changé, il faut installer la nouvelle disposition de clavier :

1. Cliquer le nouveau setup.exe généré par le MSKLC.

2. Aller sur la fenêtre de Contrôle de compte d’utilisateur et approuver qu’il y aura des modifications.

3. Prendre connaissance du message d’achèvement du Setup Wizard de la nouvelle disposition.

4. Si la nouvelle disposition n’apparaît pas encore dans la barre des langues près de l’horloge dans la barre des tâches, après le prochain démarrage tout fonctionnera normalement, et ce nouvel AZERTY figurera dans la liste comme « France AZERTY semi-automatique » ou tel qu’il aura été renommé.

## Retours d’expérience, suggestions et critiques

N’hésitez pas à envoyer toutes critiques, conseils d’amélioration et retours d’expérience à l’adresse mail dev[arobase]dispoclavier.com.

N’hésitez pas non plus à [créer un rapport de bogue](https://github.com/dispoclavier/nouvel-azerty/issues) dans
le dépôt GitHub de ce nouvel AZERTY, ni à y [lancer une discussion](https://github.com/dispoclavier/nouvel-azerty/discussions).

De nouvelles fonctionnalités peuvent être demandées aussi bien sous forme d’un rapport de bogue que dans une discussion lancée à cet effet.

*Merci d’avance de tout retour.*

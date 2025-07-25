# Redisposition de codes matériels de touches de clavier

La partie logicielle nécessaire à la redisposition de codes matériels
de touches, le Redisposeur de codes matériels pour claviers, est
incluse dans Windows depuis Windows 2000. 

```
   ====================================================================
   |  Pour la forme, il faut prévenir que le procédé décrit ici       |
   |  modifie le Registre.                                            |
   |  Mais aucune information fournie nativement n’est concernée.     |
   ====================================================================
```
Les fichiers d’inscription dans le Registre réunis dans ce dossier
contiennent tous (sauf le fichier annulation.reg, qui la supprime)
la valeur "Scancode Map" qui sera ajoutée ou remplacée dans cette clé :

[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layout]

| La clé "Keyboard Layouts" au pluriel contient les clés des dispositions de clavier installées. |
|:----------------------------------------------------------------------------------------------:|

Le reste de la clé "Keyboard Layout" (qui par défaut contient deux autres
clés) n’est pas affecté. La nouvelle valeur est inscrite dans la clé, et
si une valeur du même nom existe déjà, celle-ci est remplacée sans nouvelle
demande de confirmation.

Si une valeur "Scancode Map" existe déjà et qu’elle doit être conservée,
par exemple parce qu’elle ne provient pas de l’une des clés incluses
dans ce dossier, commencer par l’étape 0. Sinon, commencer par l’étape 1.

Étape 0 : Ouvrir l’Éditeur de Registre regedit.exe – taper Windows + R,
          saisir "regedit", appuyer sur Entrée, et lui donner l’autorisation
          d’« apporter des modifications à votre appareil » –, aller à la clé
          [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layout]
          et renommer la valeur "Scancode Map" (p.ex. en "Scancode Map 0").
          Ou exporter la clé "Keyboard Layout" (clic droit ou menu Fichier),
          afin qu’elle puisse être réimportée pour la restaurer le cas échéant.

Étape 1 : Voir si l’une des redispositions proposées dans ce dossier répond
          aux attentes ; sinon choisir celle qui s’en rapproche le plus.

Étape 2 : Ouvrir ce fichier .reg dans un éditeur de texte pour le vérifier
          et, le cas échéant, pour le modifier.

Étape 3 : Ouvrir le fichier .reg fini avec l’Éditeur du Registre.

Étape 4 : Cliquer sur [Exécuter] dans l’Avertissement de sécurité.

Étape 5 : Cliquer sur [Oui] dans le Contrôle de compte d’utilisateur.

Étape 6 : Répondre par « Oui » à la question de l’Éditeur du Registre de savoir
          si vous êtes sûr de vouloir continuer.

Étape 7 : Lire et fermer l’alerte d’accomplissement affichée ensuite.

Étape 8 : Redémarrer l’ordinateur pour la prise d’effet.


Pour tout annuler :
===================

a) Si l’étape 0 n’a pas été faite :

     Suivre les étapes 2 à 8 en utilisant le fichier annulation.reg.

b) Si l’étape 0 a été faite :

b.a) Si la clé "Keyboard Layout" a été exportée :

       1. Importer la clé préalablement exportée ;

       2. Redémarrer l’ordinateur.

b.b) Si la valeur "Scancode Map" a été renommée :

       1. Supprimer la valeur "Scancode Map" existante ;

       2. Renommer l’autre valeur en "Scancode Map" ;

       3. Redémarrer l’ordinateur.



## Fichiers d’inscription dans le Registre présents dans ce dossier


### annulation.reg

Supprime la valeur "Scancode Map" pour restaurer l’état par défaut.


### win-dr=ret-arr.reg

Redonde l’Effacement arrière sur Windows droite.

* Windows droite devient une deuxième touche d’Effacement arrière ;
* La touche d’Effacement arrière conserve sa fonctionnalité.


### win-dr=ret-arr_sans-menu.reg

Redonde l’Effacement arrière sur Windows droite et sur la touche Menu.

* Windows droite devient une deuxième touche d’Effacement arrière ;
* Menu devient une troisième touche d’Effacement arrière ;
* La touche d’Effacement arrière conserve sa fonctionnalité.

Le but est d’empêcher l’ouverture accidentelle du menu.
Plutôt que de priver de fonctionnalité la touche Menu en la désactivant,
on lui fait endosser la même fonctionnalité qu’à sa voisine,
afin que le dépassement du pouce reste sans effet.


### menu=x=ret-arr.reg

Permute les touches d’Effacement arrière et Menu.

* Menu devient Effacement arrière ;
* Effacement arrière devient Menu.


### menu=ret-arr_sans-menu.reg

Redonde l’Effacement arrière sur la touche Menu
et laisse la touche d’Effacement arrière inchangée.

* Menu devient une deuxième touche d’Effacement arrière ;
* La touche d’Effacement arrière conserve sa fonctionnalité.


### ctrl-dr=x=ret-arr.reg

Permute les touches d’Effacement arrière et Contrôle droite.

* Contrôle droite devient Effacement arrière ;
* Effacement arrière devient Contrôle droite.


### ansi-iso.reg

Permute les touches de Verrouillage des Capitales et [><],
qui se trouve à la place de Contrôle droite
et qui devient la touche AltFr.

* VerrCap devient [><] sur Contrôle droite ;
* [><] sur Contrôle droite (AltFr) devient VerrCap.


### ansi-iso_menu=x=ret-arr.reg

Permute les touches de Verrouillage des Capitales et [><],
qui se trouve à la place de Contrôle droite
et qui devient la touche AltFr.

Permute aussi les touches d’Effacement arrière et Menu.

* VerrCap devient [><] et sert de touche AltFr ;
* [><] sur Contrôle droite devient VerrCap ;
* Menu devient Effacement arrière ;
* Effacement arrière devient Menu.


### ansi-iso_menu=ret-arr_sans-menu.reg

Permute les touches de Verrouillage des Capitales et [><],
qui se trouve à la place de Contrôle droite
et qui devient la touche AltFr.

Redonde aussi l’Effacement arrière sur la touche Menu,
et laisse la touche d’Effacement arrière inchangée.

* VerrCap devient [><] et sert de touche AltFr ;
* [><] sur Contrôle droite devient VerrCap ;
* Menu devient une deuxième touche d’Effacement arrière ;
* La touche d’Effacement arrière conserve sa fonctionnalité.


### ansi-pur.reg

Introduit la touche AltFr à gauche sur la touche de Verrouillage des Capitales,
qui passe sur Contrôle droite.

* VerrCap devient [><] (AltFr) ;
* Contrôle droite devient VerrCap.




## Références du Redisposeur de codes matériels pour claviers


### Nom anglais

Scancode Mapper for Keyboards


### Tutoriel en français

https://support.microsoft.com/fr-fr/help/310516/how-to-add--modify--or-delete-registry-subkeys-and-values-by-using-a


### Ressource en anglais

https://learn.microsoft.com/fr-fr/previous-versions/windows/hardware/hid/keyboard-and-mouse-class-drivers#scan-code-mapper-for-keyboards


### Syntaxe des annotations

https://stackoverflow.com/questions/27632612/comment-in-reg-file


### Article « Scancode » sur Wikipedia anglophone

https://en.wikipedia.org/wiki/Scancode#PC_compatibles


### Listes de codes matériels de touches de clavier

#### Microsoft

Ici, Retour arrière s’appelle « Delete », et Suppression s’appelle « Delete Forward ».

https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#scan-codes

#### Quadibloc

Ici, les codes matériels sont classés par codes sous l’alinéa qui commence par
Here is a table of keyboard scan codes

http://www.quadibloc.com/comp/scan.htm




## Syntaxe des codes matériels de touches

Ces fichiers d’inscription au Registre utilisent une syntaxe particulière.

Les deux chiffres hexadécimaux des octets se lisent de gauche à droite, mais
les groupes de quatre octets appelés « DWORD » se lisent de droite à gauche.

Cela fait que l’ancien code matériel figure à droite, le nouveau à gauche.
La relation est « devient ».

Chaque code matériel occupe un « WORD », dont le premier octet, nul par défaut,
est réservé au préfixe "E0" des codes matériels étendus.

Les codes matériels étendus sont ceux dont l’identifiant commence par "X".

Ces chiffres hexadécimaux sont insensibles à la casse, car les lettres peuvent
être aussi bien en capitales qu’en minuscules.

Les octets de ces chiffres sont séparés par une virgule, et ils doivent tous
être sur une seule et même ligne. C’est pourquoi, dans ces fichiers, les fins
de ligne sont échappées.

Les annotations dans ces fichiers sont des commentaires de fin de ligne, dont
le début est un point-virgule.




## Codes matériels de quelques touches

Cette liste ne contient qu’une sélection sur le bloc alphanumérique.

Entre parenthèses figure le code hexadécimal petit-boutien.

    T0E (0E,00) Retour arrière
    X53 (53,E0) Suppression

    T1C (1C,00) Entrée

    T3A (3A,00) Verrouillage Majuscules / Verrouillage Capitales

    T0F (0F,00) Tabulation

    T1D (1D,00) Contrôle gauche
    X1D (1D,E0) Contrôle droite

    T2A (2A,00) Majuscule gauche
    T36 (36,00) Majuscule droite

    T38 (38,00) Alt
    X38 (38,E0) AltGr

    X5B (5B,E0) Windows gauche
    X5C (5C,E0) Windows droite

    X5D (5D,E0) Menu

    T01 (01,00) Échappement
		
    T29 (29,00) Touche E00 [²]
    T56 (56,00) Touche B00 [><]

    T02 (02,00) Touche E01 [1&]
    T03 (03,00) Touche E02 [2é~]
    T04 (04,00) Touche E03 [3"#]
    T05 (05,00) Touche E04 [4'{]
    T06 (06,00) Touche E05 [5([]
    T07 (07,00) Touche E06 [6-|]
    T08 (08,00) Touche E07 [7è`]
    T09 (09,00) Touche E08 [8_\]
    T0A (0A,00) Touche E09 [9ç^]
    T0B (0B,00) Touche E10 [0à@]
    T0C (0C,00) Touche E11 [°)]]
    T0D (0D,00) Touche E12 [+=}]

    T10 (10,00) Touche D01 [A]
    T11 (11,00) Touche D02 [Z]
    T12 (12,00) Touche D03 [E]
    T13 (13,00) Touche D04 [R]
    T14 (14,00) Touche D05 [T]
    T15 (15,00) Touche D06 [Y]
    T16 (16,00) Touche D07 [U]
    T17 (17,00) Touche D08 [I]
    T18 (18,00) Touche D09 [O]
    T19 (19,00) Touche D10 [P]
    T1A (1A,00) Touche D11 [¨^]
    T1B (1B,00) Touche D12 [£$¤]

    T1E (1E,00) Touche C01 [Q]
    T1F (1F,00) Touche C02 [S]
    T20 (20,00) Touche C03 [D]
    T21 (21,00) Touche C04 [F]
    T22 (22,00) Touche C05 [G]
    T23 (23,00) Touche C06 [H]
    T24 (24,00) Touche C07 [J]
    T25 (25,00) Touche C08 [K]
    T26 (26,00) Touche C09 [L]
    T27 (27,00) Touche C10 [M]
    T28 (28,00) Touche C11 [%ù]
    T2B (2B,00) Touche C12 [µ*]

    T2C (2C,00) Touche B01 [W]
    T2D (2D,00) Touche B02 [X]
    T2E (2E,00) Touche B03 [C]
    T2F (2F,00) Touche B04 [V]
    T30 (30,00) Touche B05 [B]
    T31 (31,00) Touche B06 [N]
    T32 (32,00) Touche B07 [?,]
    T33 (33,00) Touche B08 [.;]
    T34 (34,00) Touche B09 [/:]
    T35 (35,00) Touche B10 [§!]

    T3B (02,00) F1
    T3C (03,00) F2
    T3D (04,00) F3
    T3E (05,00) F4
    T3F (06,00) F5
    T40 (07,00) F6
    T41 (08,00) F7
    T42 (09,00) F8
    T43 (0A,00) F9
    T44 (0B,00) F10
    T57 (0C,00) F11
    T58 (0D,00) F12

    Nul (00,00) Aucune touche



## Note sur d’autres systèmes d’exploitation

* Sous macOS, le même effet est obtenu grâce au logiciel Karabiner-Elements 
  de Takayama Fumihiko.
	https://pqrs.org/osx/karabiner/
* Sous Linux, plutôt que de redisposer des codes matériels de touches, on 
  redispose des codes logiciels de touches, ou les fonctionnalités selon 
  ce qui fonctionne le mieux, en éditant directement les fichiers de
  configuration.
  https://www.freedesktop.org/wiki/Software/XKeyboardConfig/



## À propos

Ce fichier est distribué dans le dossier redipositions/ sous le nom de _Scancode_Map.txt,
tandis que sur GitHub il sert de readme.md dans windows/redispositions/. Il est basé sur
une version précédente datant de 2018-08-10T1041+0200.

# Redisposition de codes matériels de touches

La partie logicielle nécessaire à la redisposition de codes matériels de
touches est fournie depuis Windows 2000. 

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

Le reste du contenu de cette clé n’est pas affecté par l’opération,
qui est une fusion. La nouvelle valeur est inscrite dans la clé, et
si une valeur du même nom existe déjà, celle-ci est remplacée sans
nouvelle demande de confirmation.

Si une valeur "Scancode Map" existe et qu’elle doit être conservée
(par exemple parce qu’elle ne provient pas de l’une des clés incluses
dans ce pack), commencer par l’étape 0. Sinon commencer par l’étape 1.

Étape 0 : Ouvrir l’Éditeur de Registre regedit.exe, aller à la clé
          [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layout]
          et renommer la valeur "Scancode Map" (p.ex. en "Scancode Map 0").
          Ou exporter la clé "Keyboard Layout" (clic droit ou menu Fichier),
          afin qu’elle puisse être restaurée le cas échéant.

Étape 1 : Voir si l’une des redispositions proposées dans ce dossier répond
          aux attentes, ou sinon choisir celle qui s’en rapproche le plus.

Étape 2 : Ouvrir ce fichier .reg dans un éditeur de texte pour le modifier,
          ou au moins pour le vérifier.

Étape 3 : Ouvrir le fichier .reg fini avec l’Éditeur du Registre.

Étape 4 : Confirmer en cliquant [Oui] dans l’alerte qui s’affiche.

Étape 5 : Lire et fermer l’alerte de accomplissement affichée ensuite.

Étape 6 : Redémarrer l’ordinateur pour une prise d’effet immédiate.


Pour tout annuler :
===================

a)  Si l’étape 0 n’a pas été faite :
    Suivre les étapes 3 à 5, ou 3 à 6, en utilisant le fichier 
    annulation.reg.

b)  Si l’étape 0 a été faite :

b1) Si la clé a été exportée :
    Importer la clé préalablement exportée.

b2) Si la valeur "Scancode Map" a été renommée :
    Supprimer la valeur "Scancode Map" existante, et
    renommer l’autre valeur en "Scancode Map".

Ensuite :
    Redémarrer l’ordinateur en cas de redémarrage après l’inscription à 
    annuler.
    Sinon, il n’est pas nécessaire de redémarrer l’ordinateur pour rendre
    l’annulation effective.


## Références du redisposeur de codes matériels de touches de clavier


0) Nom anglais : Scancode Mapper for Keyboards


1) Tutoriel en français :

https://support.microsoft.com/fr-fr/help/310516/how-to-add--modify--or-delete-registry-subkeys-and-values-by-using-a


2) Ressource en anglais :

https://msdn.microsoft.com/en-us/library/windows/hardware/jj128267(v=vs.85).aspx


3) Syntaxe des commentaires :

https://stackoverflow.com/questions/27632612/comment-in-reg-file


4) Article Wikipédia « Scancode »:

https://en.wikipedia.org/wiki/Scancode#PC_compatibles


5) Listes de codes matériels de touches de clavier :

http://www.quadibloc.com/comp/scan.htm




## Fichiers d’inscription dans le Registre présents dans ce dossier


### annulation.reg

Supprime la valeur "Scancode Map" pour restaurer l’état par défaut.


### win-dr=ret-arr.reg

Redonde l’Effacement arrière sur Windows droite.

* Windows droite devient une deuxième touche d’Effacement arrière.
* La touche d’Effacement arrière conserve sa fonctionnalité.


### win-dr=ret-arr_sans-menu.reg

Redonde l’Effacement arrière sur Windows droite et désactive la touche Menu.

* Windows droite devient une deuxième touche d’Effacement arrière.
* Menu devient une troisième touche d’Effacement arrière afin d’empêcher l’ouverture accidentelle du menu.
* La touche d’Effacement arrière conserve sa fonctionnalité.


### menu=x=ret-arr.reg

Permute les touches d’Effacement arrière et Menu.

* Menu devient Effacement arrière.
* Effacement arrière devient Menu.


### menu=ret-arr_sans-menu.reg

Redonde l’Effacement arrière sur la touche Menu et laisse la touche d’Effacement arrière inchangée.

* Menu devient une deuxième touche d’Effacement arrière.
* La touche d’Effacement arrière conserve sa fonctionnalité.


### ctrl-dr=x=ret-arr.reg

Permute les touches d’Effacement arrière et Contrôle droite.

* Contrôle droite devient Effacement arrière.
* Effacement arrière devient Contrôle droite.


### ansi-iso.reg

Permute les touches de Verrouillage des Capitales et [<>] qui se trouve à la place de Contrôle droite et qui devient la touche AltFr.

* VerrCap devient [<>] sur Contrôle droite.
* [<>] sur Contrôle droite (AltFr) devient VerrCap.


### ansi-iso_menu=x=ret-arr.reg

Permute les touches de Verrouillage des Capitales et [<>] qui se trouve à la place de Contrôle droite
et qui devient la touche AltFr.
Permute aussi les touches d’Effacement arrière et Menu.

* VerrCap devient [<>] et sert de touche AltFr.
* [<>] sur Contrôle droite devient VerrCap.
* Menu devient Effacement arrière.
* Effacement arrière devient Menu.


### ansi-iso_menu=ret-arr_sans-menu.reg

Permute les touches de Verrouillage des Capitales et [<>] qui se trouve à la place de Contrôle droite
et qui devient la touche AltFr.
Redonde aussi l’Effacement arrière sur la touche Menu et laisse la touche d’Effacement arrière inchangée.

* VerrCap devient [<>] et sert de touche AltFr.
* [<>] sur Contrôle droite devient VerrCap.
* Menu devient une deuxième touche d’Effacement arrière.
* La touche d’Effacement arrière conserve sa fonctionnalité.


### ansi-pur.reg

Introduit la touche AltFr à gauche sur la touche de Verrouillage des Capitales, qui passe sur Contrôle droite.

* VerrCap devient [<>] (AltFr).
* Contrôle droite devient VerrCap.



## Codes matériels de touches (scancodes)

Entre parenthèses figure le code hexadécimal petit-boutien.
Le sens de lecture est de gauche à droite dans les octets (groupes de 2 chiffres hex)
et dans l’ensemble, mais de droite à gauche dans les DWORDS (groupes de 4 octets).
L’ancien code matériel figure à droite, le nouveau à gauche. La relation est « devient ».
Chaque code matériel occupe un WORD (2 octets), dont le premier octet, nul par défaut,
est réservé au préfixe « E0 » des codes matériels étendus (notés « X## »).

Liste non exhaustive.

    T0E (0e,00) Retour arrière
    X53 (53,e0) Suppression

    T0F (0f,00) Tabulation
    T1C (1c,00) Entrée (bloc alphanumérique)

    T1D (1d,00) Ctrl gauche
    X1D (1d,e0) Ctrl droite

    T2A (2a,00) Maj gauche
    T36 (36,00) Maj droite

    T38 (38,00) Alt
    X38 (38,e0) AltGr

    T3A (3a,00) VerrCap / VerrMaj
    T45 (45,00) VerrNum (claviers compacts : + VerrFonction sur pavé numérique)

    X5B (5b,e0) Windows gauche
    X5C (5c,e0) Windows droite

    X5D (5d,e0) Menu/applications (Menu contextuel)

    T29 (29,00) Touche TLDE E00 [²]
    T2B (2b,00) Touche BKSL C12 [*]
    T56 (56,00) Touche LSGT B00 [<]

    T2C (2c,00) Touche AB01 [W]
    T2D (2d,00) Touche AB02 [X]
    T2E (2e,00) Touche AB03 [C]
    T2F (2f,00) Touche AB04 [V]
    T30 (30,00) Touche AB05 [B]



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

Ce fichier est distribué dans le dossier redipositions/ sous le nom de Scancode_Map.txt,
tandis que sur GitHub il sert de readme.md dans windows/redispositions/. Il est basé sur
une version précédente datant de 2018-08-10T1041+0200.

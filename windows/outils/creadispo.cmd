:: charset=OEM 65001 BOM
@echo off
chcp 65001
rem  La mise à niveau vers Unicode de l’interpréteur de commandes Windows est faite.
::
::  encodage     OEM 65001 (UTF-8) avec indicateur d’ordre des octets
::  nom          creadispo
::  description  programme de commandes en batch pour l’interpréteur cmd.exe de Windows
::               utilisant le KbdUTool 3.40 du Microsoft Keyboard Layout Creator 1.4
::  version      1.9.1
::  date         2025-07-07T1426+0200 (1.8.3 : 2018-03-15T1954+0100)
::  contact      dev@dispoclavier.net
::  ressources   https://dispoclavier.com
::
::  Licensed under the Apache License, Version 2.0 (the "License");
::  you may not use this file except in compliance with the License.
::  You may obtain a copy of the License at
::  
::      https://www.apache.org/licenses/LICENSE-2.0
::  
::  Unless required by applicable law or agreed to in writing, software
::  distributed under the License is distributed on an "AS IS" BASIS,
::  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
::  See the License for the specific language governing permissions and
::  limitations under the License.
::
:: Paramètres d’exécution de ce script
setlocal EnableExtensions EnableDelayedExpansion
:: titre de la fenêtre de cmd.exe
title Creadispo  1.9.0
color 13
rem  Cette couleur introduit la transition du fond noir par défaut vers le fond blanc.
rem  Les couleurs d’affichage sont personnalisables dans les préférences de ce script.

:: Initialise :
set MSKLCprofile="%ProgramFiles%\Microsoft Keyboard Layout Creator 1.4"
set soundfile="C:\Windows\Media\Windows Print complete.wav"
set seen=no
:: Crée les dossiers de stockage :
rem  Commandes longues pour la clarté :
rem    chdir  à la place de  cd
rem    mkdir  à la place de  md
rem    rename à la place de ren
if not exist  %ProgramData%\creadispo (
	mkdir  %ProgramData%\creadispo
echo  J’ai créé le dossier pour les données globales.
)
if not exist %LOCALAPPDATA%\creadispo (
	mkdir %LOCALAPPDATA%\creadispo
echo  J’ai créé le dossier pour les données utilisateur.
)
:: Lecture du profil utilisateur :
if exist %LOCALAPPDATA%\creadispo\userdata.txt call :readuserprofile
if defined enc (
	if "%enc%" neq "u" if "%enc%" neq "a" (
color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo    Je suis dans l’incapacité de lire correctement votre profil utilisateur.
echo.&echo.
echo                   Probablement votre profil est endommagé.
echo.&echo.
echo                   Je vais être obligé de le réinitialiser.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
		pause
		color fc
		goto userprofilereset
	)
) else (
color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo       Je ne peux pas extraire une variable de votre profil utilisateur.
echo.&echo.
echo    Probablement vous avez effacé votre profil pour que je le réinitialise.
echo.&echo.
echo                     Je vais le faire tout de suite.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
	call :milliwait
	color fc
	pause
	goto userprofilereset
)
echo  Je viens de lire mon fichier contenant votre profil utilisateur.
echo  Il est accessible depuis les Préférences.
color 30
goto globaldataread

:: Crée le profil utilisateur :
if not exist %LOCALAPPDATA%\creadispo\userdata.txt (
	set enc=u&set /a helplevel=0 & set bg=&set fg=& set /a times=3 &set adhoc=oui& set aready=oui&set arqtnok=non& set day=non& set eve=non& set sound=oui
	set datestamp=%DATE%
	call :saveuserprofile
	echo  J’ai créé votre profil utilisateur.
)
:: Réintialise un profil utilisateur corrompu :
:userprofilereset
color 2f
	set enc=u&set /a helplevel=7 & set bg=&set fg=& set /a times=3 &set adhoc=oui& set aready=oui&set arqtnok=oui& set day=non& set eve=non& set sound=oui
	set datestamp=%DATE%
	call :saveuserprofile
	echo  
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                 J’ai réinitialisé votre profil utilisateur.
echo.&echo.
echo    Au niveau du support je vous considère comme un utilisateur expérimenté.
echo.&echo.
echo   Pour toute modification de votre profil veuillez consulter les Préférences.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
call :milliwait
color f2
pause
)
:globaldataread
if exist  %ProgramData%\creadispo\globaldata.txt (
	rename %ProgramData%\creadispo\globaldata.txt globaldata.cmd
	call   %ProgramData%\creadispo\globaldata.cmd
	rename %ProgramData%\creadispo\globaldata.cmd globaldata.txt
echo  Je viens de lire mon fichier de données globales pour votre ordinateur.
)
color 80
:: Crée le script de données globales :
if not exist %ProgramData%\creadispo\globaldata.txt (
	echo @echo off> %ProgramData%\creadispo\globaldata.txt
	:: Stocke le type d’architecture au format MSKLC dans une variable courte :
	set machine=amd64
	if "%PROCESSOR_ARCHITECTURE%" equ "x86"  set machine=i386
	if "%PROCESSOR_ARCHITECTURE%" equ "IA64" set machine=ia64
	echo set machine=!machine!>> %ProgramData%\creadispo\globaldata.txt
echo  J’ai créé le script de données globales.
)
:: Lecture du fichier de propriétés du projet :
if exist creadispo-projet.txt (
	echo.
	call :readprojectprops
)
color 73
:: Adapte les formes grammaticales et les nombres :
if "%machine%" equ "i386" (
	set nmb=un&   set pls=&  set plx=&  set vbe=est&  set vba=a&   set ard=l’&   set ari=un&  set arp=du&  set pps=son&  set ppp=ses&   set bit=32
) else (
	set nmb=deux& set pls=s& set plx=x& set vbe=sont& set vba=ont& set ard=les & set ari=des& set arp=des& set pps=leur& set ppp=leurs& set bit=64
)
:: Adapte l’accueil à l’environnement et au niveau d’avancement :
:helpfork
call :allfilecheck
color b1
if "%allfiles%" equ "yes" if "%adhoc%" equ "oui" (
	if %helplevel% equ 0 goto welcompile
	if %helplevel% neq 0 goto freshen
)
if %helplevel% equ  0 goto welcome
if %helplevel% equ  1 if exist %MSKLCprofile%\MSKLC.exe ( goto callhelpMSKLCstart ) else ( goto MSKLCprofilehelp )
if %helplevel% equ  2 goto callhelpMSKLCenh0
if %helplevel% equ  3 goto callhelpMSKLCenh1
if %helplevel% equ  4 goto callhelpMSKLCenh2
if %helplevel% equ  5 goto callhelpMSKLCdvp
if %helplevel% equ  6 goto callhelpstart
if %helplevel% equ  7 goto callhelpedit
if %helplevel% equ  8 goto callhelpcompile
if %helplevel% equ  9 goto callhelpdebug
if %helplevel% equ 10 goto menu

:callhelpMSKLCstart
call :helpMSKLCstart
:callhelpMSKLCenh0
call :helpMSKLCenh0
:callhelpMSKLCenh1
call :helpMSKLCenh1
:callhelpMSKLCenh2
call :helpMSKLCenh2
:callhelpMSKLCdvp
call :helpMSKLCdvp
:callhelpstart
call :helpstart
:callhelpedit
call :helpsources
:callhelpcompile
call :helpcompile
:callhelpdebug
call :helpdebug
goto menu

:: Met à jour le rapport au temps :
:dateup
:: Marque la date du jour comme visitée :
if defined datestamp (
	if "%datestamp%" neq "%DATE%" (
		set datestamp=%DATE%
		set day=non
		set eve=non
		call :saveuserprofile
	)
)
:: Définit la forme de salutation :
if %TIME:~0,2% lss 18 (
	if "%day%" equ "non" (
		set hello=Bonjour
		set day=oui
		call :saveuserprofile
	) else (
		set hello=Rebonjour
	)
) else (
	if "%eve%" equ "non" (
		set hello=Bonsoir
		set eve=oui
		call :saveuserprofile
	) else (
		set hello=Rebonsoir
	)
)
:: Définit le moment de la journée :
if %TIME:~,2% lss 12 set moment=e matin&&       goto :eof
if %TIME:~,2% lss 18 set moment=et après-midi&& goto :eof
                     set moment=e soir&&        goto :eof

:: ######____MENU PRINCIPAL____########################################################
:menu
call :dateup
color f9
echo.&echo.&echo.
echo                                                M E N U   P R I N C I P A L
if "%seen%" equ "no" (
	echo        %hello%,
	echo.
	set seen=yes
) else (
	echo.&echo.
)
echo     ^>  Que puis-je pour vous c%moment% ?
echo.
echo    I = INSTALLATION d’une disposition compilée à partir de ses sources
echo.
echo    S = SOURCES en langage C et fichiers DEF / RC à partir d’une source KLC
echo.
echo    T = TEST d’une disposition après que vous avez modifié ses sources
echo.
echo    V = VERSION finie avec tous les pilotes et des installateurs d’origine
echo.
echo    R = RESTAURER %ard%ancien%pls% pilote%pls% d’origine après une série de tests
echo.
echo    A = obtenir de l’AIDE ou des informations ;  pour afficher le menu d’AIDE,
echo        "?" fonctionne pareillement, et aussi à d’autres occasions.
echo.
echo    P = PRÉFÉRENCES :  accès à votre profil, encodage sources KLC, couleurs…
echo.
echo    Appuyez sur Entrée après votre choix, ou sans choix pour me quitter.
echo               ^>  La lettre peut aussi être en minuscule.  ^<
echo.
color f1
set out=no
set option=
:menuwhat
set /p option= .                     Votre choix : 
rem     La commande CHOICE n’est pas utilisée car elle est absente de Windows XP,
rem     elle n’admet pas le point d’interrogation, et elle déclenche un signal sonore
rem     strident quand l’utilisateur se méprend de la lettre.
if defined option (
	if /i "%option:~,1%" equ "a" goto help
	if /i "%option:~,1%" equ "i" goto freshen
	if /i "%option:~,1%" equ "p" goto preferences
	if /i "%option:~,1%" equ "r" goto restore
	if /i "%option:~,1%" equ "s" goto sources
	if /i "%option:~,1%" equ "t" goto test
	if /i "%option:~,1%" equ "v" goto version
	if    "%option:~,1%" equ "?" goto help
)
if "%out%" equ "yes" goto eof
color 70
echo.
echo    Désolé, je peux faire uniquement ces 7 choses. Voudriez-vous retenter ?
echo    Pour me quitter pour de bon, appuyez encore une fois sur Entrée.
echo.
set out=yes
goto menuwhat

:: ######____PRÉSENTATIONS GÉNÉRALES____#########################################
:welcome
call :dateup
set seen=yes
echo.&echo.&echo.&echo.
echo    %hello%, je m’appelle Creadispo, je suis là pour vous assister à certaines
echo    étapes de la confection de dispositions de clavier pour votre ordinateur,
echo    compatibles Windows 11, 10, 8, 7, Vista, Server 2003, XP, 2000, et NT 4.0.
echo.

if exist %MSKLCprofile%\MSKLC.exe (

echo.
echo    Grâce au Microsoft Keyboard Layout Creator que vous avez -- félicitations
echo    au passage, car ce logiciel plutôt indispensable est trop peu connu --,
color b1

) else (

echo    Une fois que vous aurez le logiciel gratuit de création de dispositions
echo    de clavier Microsoft à son emplacement par défaut ou personnalisé,
)

color b1
echo    je pourrai faire générer les sources en langage C de la disposition
echo    de clavier de votre choix afin que vous puissiez les éditer pour aboutir
echo    à un clavier plus performant ; et je pourrai faire compiler les pilotes.
echo.

if exist %MSKLCprofile%\MSKLC.exe (

echo    Sans le MSKLC en effet, je ne peux absolument rien faire. Avec le MSKLC
echo    vous voilà donc bien équipé·e pour faire des claviers performants, pour
echo    peu que vous soyez prêt·e à éditer les sources aussi “à la main”. Car en
echo    pratique il n’y a rien que de très normal dans le travail avec les sources
echo    quel que soit votre rapport à l’informatique : bureautique, programmation…
echo.
echo    Je passe maintenant sur les points concernant le MSKLC, auxquels vous
echo    accéderez par le menu de l’aide si vous le souhaitez. Saisissez un "?"
echo    pour les voir de suite. Car j’aimerais vous expliquer directement comment
echo    je tâcherai de vous être utile.
echo                                          Pour continuer, appuyez sur Entrée.
color f1
	set /p welcomeok= .  
if %helplevel% neq 10 (
	set /a helplevel=4
	call :saveuserprofile
)
	if defined welcomeok (
		if "%welcomeok%" equ "?" goto help
	)
	goto helpfork
	
) else (

echo     ^>  Pour m’utiliser, le logiciel suivant vous est indispensable :
echo.
echo             Microsoft Keyboard Layout Creator MSKLC, version 1.4
echo.
echo        +1  Gratuit.  +2  Fait pour la NSA et le public.  +3  De Microsoft.
echo.&echo.
echo     ^>  Si vous avez le MSKLC mais pas à son emplacement par défaut,
echo        merci de m’indiquer sur quel disque et par quel chemin s.v.p. ;
echo        sinon, appuyez seulement sur Entrée.
echo.
set pathrequest=
color f1
set /p pathrequest= .  [Chemin] Valider : 
goto MSKLCprofilecheck
)

:: ######____PROFIL DU MSKLC (LECTEUR ET CHEMIN)____####### 0 ##################
:MSKLC
color f1
echo.&echo.&echo.
echo     ^>  Pour m’utiliser, le logiciel suivant vous est indispensable :
echo.
echo             Microsoft Keyboard Layout Creator MSKLC, version 1.4
echo.
echo        +1  Gratuit.  +2  Fait pour la NSA et le public.  +3  De Microsoft.
echo.&echo.
echo     ^>  Si vous avez déjà le MSKLC mais juste à un autre emplacement,
echo        merci de m’indiquer sur quel disque et par quel chemin s.v.p. ;
echo        sinon, appuyez seulement sur Entrée.
echo.
set pathrequest=
set /p pathrequest= .  [Chemin] Valider : 

:MSKLCprofilecheck
if not defined pathrequest (
	call :MSKLCdwnl
	goto :eof
) else (
	if "%pathrequest:~,1%" equ "?" (
		goto help
	) else (
		if exist "%pathrequest%\MSKLC.exe" (
			call :MSKLCprofilememo
		) else (
			goto MSKLCprofilehelp
		)
	)
)
if %helplevel% neq 10 (
	set /a helplevel=1
	call :saveuserprofile
)
goto helpfork

:MSKLCprofilehelp
color f2
echo.
echo    Désolé, je ne trouve pas le MSKLC.
echo.
echo    Pour m’indiquer le chemin exact du MSKLC dans votre ordinateur,
echo    voici comment vous pouvez procéder :
echo.
echo    1   Naviguez jusqu’à lui dans l’Explorateur Windows.
echo.
echo    2   Une fois dans son dossier racine, cliquez dans la partie droite
echo        de la barre de chemin.
echo.
echo    3   Faites Contrôle + C pour copier le chemin dans le Presse-papiers.
echo.
echo    4   Faites un clic droit dans ma fenêtre et choisissez Coller.
echo.
echo    5   Appuyez sur Entrée.
echo.
echo    On y va ?  Je vous attends ici.
echo.
echo          ^> Si vous n’avez pas encore le MSKLC, appuyez seulement sur Entrée.
echo.&echo.
set pathrequest=
set /p pathrequest= .  Collez ici le chemin du MSKLC dans votre ordinateur : 
goto MSKLCprofilecheck

:MSKLCprofilememo
set MSKLCprofile=%pathrequest%
echo set MSKLCprofile=%MSKLCprofile%>> %ProgramData%\creadispo\globaldata.txt
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo    Merci. Je l’ai mis en mémoire pour les prochaines fois.
echo.
echo    Il est désormais stocké dans %ProgramData%\creadispo\globaldata.txt
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo.
pause
goto :eof

:: Contrôle de présence du KbdUTool :
:MSKLCcheck
set MSKLCava=yes
if exist %MSKLCprofile%\MSKLC.exe goto :eof
set MSKLCava=no
color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo        Je ne trouve pas le MSKLC, qui inclut le KbdUTool dont j’ai besoin.
echo.
echo    Si vous ne l’avez pas ou que vous l’avez mais à un emplacement non standard,
echo.
echo              merci de bien vouloir faire le nécessaire.
echo.&echo.&echo.&echo.
echo     ^>  Appuyez sur une touche et je vous y emmène.
echo.
pause >nul
goto :eof

:: ######____PRÉSENTATIONS SPÉCIALES____#########################################
:welcompile
call :dateup
set seen=yes
echo.&echo.
echo    %hello%, je m’appelle Creadispo, et en l’occurrence je suis là pour faire
echo    le%pls% pilote%pls% de disposition de clavier à partir des sources ici, qui ser%vba%
echo    compatible%pls% Windows 11, 10, 8.1, 8, 7, Vista, Server 2003, XP, 2000, et NT 4.0.

if exist %MSKLCprofile%\MSKLC.exe (
echo.
echo    Grâce au Microsoft Keyboard Layout Creator que vous avez -- félicitations
echo    au passage, car ce logiciel plutôt indispensable est trop peu connu --,
) else (
echo    Une fois que vous aurez le logiciel gratuit de création de dispositions
echo    de clavier Microsoft à son emplacement par défaut ou personnalisé,
)
color b1

echo    je peux faire compiler le%pls% pilote%pls% adapté%pls% à l’architecture %bit% bit
echo    de votre ordinateur à partir des sources qui se trouvent auprès de moi,
echo    et comme j’ai aussi sous la main tout ce qu’il faut pour %ard%installer,
echo    je vais vous préparer un petit pack vite fait bien fait grâce auquel
echo    vous pourrez installer tout à l’heure sur votre ordinateur la disposition
echo    de clavier  %name%  du projet  %projectname%.
echo     _______________________________________________________________________
echo    /                                                                       \
echo    I  Vous avez la possibilité de vérifier à tout moment tant moi-même     I
echo    I  que les sources. Quant aux installateurs, si vous en préférez des    I
echo    I  frais émoulus du MSKLC cela est aussi possible, vous demanderez au   I
echo    I  MSKLC de vous en refaire sur la base de la source KLC ci-jointe.     I
echo    \_______________________________________________________________________/
echo.
echo    Si vous êtes prêt·e, appuyez sur Entrée, ou si vous avez des questions,
echo    n’hésitez pas, faites précéder d’un point d’interrogation :   ? Entrée.
color f1
set /p agree= .   
if %helplevel% neq 10 (
	set /a helplevel=1
	call :saveuserprofile
)
if "%agree:~,1%" equ "?" goto help
if exist %MSKLCprofile%\MSKLC.exe goto freshen
goto MSKLC

:allfilecheck
set allfiles=no
if exist creadispo-projet.txt (
	if exist %name%\%name%_%machine%.msi (
		if exist %name%.klc (
			set allfiles=klc
			if exist %name%.C (
				if exist %name%.H (
					set allfiles=near
					if exist %name%.RC (
						if exist %name%.DEF (
							set allfiles=yes
	))))))
	if exist C:\Windows\System32\%name%.dll set allfiles=nomatter
)
goto :eof

:: ######____AIDE :  MENU____#####################################################
:help
color fa
echo.
echo                                                M E N U   D E   L ’ A I D E
echo     ^>  Comment puis-je vous aider ?
echo.
echo    T = Téléchargement gratuit du MSKLC sur le site officiel de Microsoft      1
echo.   
echo    G = Guide en français pour l’initiation au MSKLC :  Forum HardWare.fr      2
echo.   
color fe
echo    U = Utilisation augmentée du MSKLC (3 pages, dont 2 exemples pratiques)  3-5
echo.   
echo    A = Aller plus loin avec le MSKLC :  le blog de M. S. KAPLAN (l’auteur)    6
echo.   
echo    P = Premières étapes pour créer une disposition de clavier performante     7
echo.   
echo    S = Sources en C :  les explications de M. G. GALÉRON (Mon Nom Accentué)   8
echo.   
echo    C = Compilation des pilotes de test et des pilotes d’une version           9
color fa
echo.   
echo    D = Déboguer une disposition de clavier :  AltGr, touches mortes, …     10
echo.
echo    R = Refaire le parcours de prise en main en commençant par l’étape 2 :  2-10
color f2
echo.
echo    M = Menu principal
echo.
set option=
set /p option= .                     Votre choix : 
rem     La commande CHOICE n’est pas utilisée car elle est absente de Windows XP,
rem     et elle déclenche un signal sonore quand l’utilisateur se méprend.
if not defined option goto help else (
	if /i "%option:~,1%" equ "a" call :helpMSKLCdvp
	if /i "%option:~,1%" equ "c" call :helpcompile
	if /i "%option:~,1%" equ "d" call :helpdebug
	if /i "%option:~,1%" equ "g" call :helpMSKLCstart
	if /i "%option:~,1%" equ "m" goto  menu
	if /i "%option:~,1%" equ "p" call :helpstart
	if /i "%option:~,1%" equ "r" set  /a helplevel=1 & call :saveuserprofile & goto helpfork
	if /i "%option:~,1%" equ "s" call :helpsources
	if /i "%option:~,1%" equ "t" call :MSKLCdwnl
	if /i "%option:~,1%" equ "u" call :helpMSKLCenh0 & call :helpMSKLCenh1 & call :helpMSKLCenh2
	goto help
)
:: ######____AIDE MSKLC :  TÉLÉCHARGEMENT____####### 1 ###########################
:MSKLCdwnl
color f9
echo.&echo.&echo.
echo       Pour faire des dispositions de clavier avec moi, vous devez avoir le
echo    Microsoft Keyboard Layout Creator (MSKLC). Ce logiciel gratuit vient droit
echo    de chez Microsoft et vous est donné au Centre de téléchargement Microsoft.
echo.
echo    Pour l’histoire, il est bon de savoir que si les logiciels inclus dans le
echo    dossier du MSKLC préexistaient, l’origine du MSKLC proprement dit remonte
echo    aux attentats du 11 septembre 2001 et à une demande émanant de la NSA, qui
echo    dut se mettre en état de créer elle-même les dispositions de clavier dont
echo    ses transcripteurs avaient besoin. Histoire de ne pas divulguer pour quelles
echo    langues exactement, à part une poignée de claviers fournis en urgence.
echo    Mis à la libre disposition de tous les utilisateurs de Windows, le MSKLC a
echo    aujourd’hui plus de 2 millions de téléchargements au compteur.
echo      ______________________________________________________________________
echo     /                                                                      \
echo    I  Le MSKLC et les pilotes de disposition qu’il génère sont entièrement  I
echo    I  compatibles avec toutes les versions de Windows de notre millénaire,  I
echo    I  y compris les dernières (Windows 11, 10, Windows 8 et 8.1, Windows 7).I
echo    I  Elles fonctionnent toutes parfaitement avec le MSKLC parce que        I
echo    I  les parties concernées du système d’exploitation avaient été figées   I
echo.   I  au tournant du siècle pour justement assurer la rétrocompatibilité.   I
echo     \______________________________________________________________________/
echo.
echo     ^>  Appuyez sur une touche pour visiter la page de téléchargement MSKLC.
color f2
pause >nul
start https://www.microsoft.com/en-us/download/details.aspx?id=22339
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo            Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                    Microsoft Keyboard Layout Creator 1.4
echo.&echo.
echo                  sur le site du Microsoft Download Center
echo.&echo.
echo         https://www.microsoft.com/en-us/download/details.aspx?id=22339
echo.&echo.&echo.&echo.&echo.&echo.
if %helplevel% neq 10 (
	set /a helplevel=1
	call :saveuserprofile
)
set /a count=0
:loop0
call :milliwait & color df
call :milliwait & color 5f
call :milliwait & color df
call :milliwait & color 72
set /a count+=1
if %count% lss 7 goto loop0
goto :eof

:: ######____AIDE MSKLC :  PRISE EN MAIN____######### 2 ########################
:helpMSKLCstart
color f9
echo.&echo.&echo.
echo    L’aide du MSKLC, richement illustrée de captures d’écran, est en anglais
echo    mais une page du Forum HardWare.fr présente un certain nombre de points
echo    essentiels dans notre langue, et les captures ne manquent pas non plus.
echo.
echo     ^>  Si vous ne l’avez déjà vue, je vous suggère de visiter cette page.
echo.
echo    Peut-être deux petites astuces avant d’y aller si vous voulez bien :
echo.
echo    1  L’apparence visuelle du MSKLC devient beaucoup plus jolie si vous
echo       redimensionnez sa fenêtre vers le bas pour faire des touches carrées.
echo       Ce paramètre sera enregistré pour les prochains démarrages.
echo.
echo       Les touches rectangulaires, à l’air tassé, ont été choisies par
echo       rapport au fait que le MSKLC gère aussi les séquences de caractères,
echo       jusqu’à quatre unités de code par emplacement de touche.
echo.
echo    2  De plus, vous pouvez colorer les touches du MSKLC à votre guise
echo       grâce à l’outil en bas à gauche. Cette fonctionnalité est aussi
echo       pointée dans l’aide du MSKLC. Mais curieusement elle reste souvent
echo       inutilisée, sans doute parce que le noir-et-blanc fait consensuel.
echo.
echo     ^>  Appuyez sur Entrée pour que je demande à votre navigateur d’afficher
echo        la page du forum Hardware.fr.     (Pour la sauter, tapez d’abord N.)
color f2
set forumvisit=
set /p forumvisit= .                             
if %helplevel% neq 10 (
	set /a helplevel=2
	call :saveuserprofile
)
if defined forumvisit (
	if    "%forumvisit:~,1%" equ "?" goto :eof
	if /i "%forumvisit:~,1%" equ "m" goto :eof
	if /i "%forumvisit:~,1%" equ "n" goto :eof
)
start https://forum.hardware.fr/hfr/WindowsSoftware/Logiciels/microsoft-keyboard-personnalisez-sujet_180317_1.htm
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo      MSKLC / Microsoft Keyboard Layout Creator, personnalisez votre clavier
echo.&echo.
echo                Logiciels - Windows ^& Software - FORUM HardWare.fr
echo.&echo.
echo              https://forum.hardware.fr/hfr/WindowsSoftware/Logiciels/
echo                microsoft-keyboard-personnalisez-sujet_180317_1.htm
echo.&echo.&echo.&echo.&echo.
set count=0
:loop1
call :milliwait & color 4f
call :milliwait & color 0f
call :milliwait & color 4f
call :milliwait & color 70
set /a count+=1
if %count% lss 7 goto loop1
goto :eof

:: ######____AIDE MSKLC :  UTILISATION AUGMENTÉE 0____######## 3 ####################
:helpMSKLCenh0
color f9
echo.&echo.&echo.
echo    Une chose importante à bien garder à l’esprit en travaillant avec le MSKLC
echo    est que la partie apparente, le logiciel proprement dit, est l’interface
echo    grand-public du Keyboard Table Generation Tool (Unicode) version 3.40,
echo    bref KbdUTool, qui lui aussi est inclus dans le dossier et qui a lui aussi
echo    une interface utilisateur, mais en ligne de commande. C’est l’outil qui, à
echo    partir d’une source simplifiée (KLC), fait les sources en C pour ensuite
echo    les donner aux compilateurs (un cl.exe pour chaque architecture).
echo.
echo    Microsoft a fait de nombreuses dispositions de clavier et en a ajouté ou
echo    amélioré un certain nombre au fil des versions de Windows. Au siège de la
echo    firme de Redmond on apprécie les efforts des utilisateurs visant à faire
echo    de meilleurs claviers. Microsoft ne peut juste pas prendre les devants et
echo    se mettre à la place des normalisateurs en divisant les utilisateurs.
echo.
echo    De plus, le créneau des dispositions de clavier est tenu depuis longtemps
echo    par d’autres éditeurs comme Tavultesoft (Keyman), tandis que les logiciels
echo    phares de Microsoft apportent leur lot de moyens pour compléter le clavier.
echo.
echo    La licence du MSKLC contient certes une clause interdisant de contourner les
echo    limitations techniques du logiciel, mais en plus de se trouver dans toutes
echo    les licences propriétaires, elle ne vise absolument pas à empêcher quiconque
echo    de mettre ce qu’il veut sur son clavier. Je vais vous ouvrir le dossier et
echo    la licence avant d’illustrer mes propos par deux exemples. Juste un appui…
color f2
pause >nul
call %MSKLCprofile%
call %MSKLCprofile%\license.rtf
if %helplevel% neq 10 (
	set /a helplevel=3
	call :saveuserprofile
)
goto :eof

:: ######____AIDE MSKLC :  UTILISATION AUGMENTÉE 1____######## 4 ####################
:helpMSKLCenh1
color f9
echo.&echo.&echo.
echo     ^>  Exemple 1 :  Davantage que des espaces sur la barre            ( 4/10 )
echo.
echo    Certes sur la barre d’espace les places sont comptées, en plus d’avoir
echo    l’espace sécable aussi en majuscule pour des raisons pratiques, et deux
echo    espaces insécables à caser. D’où le garde-fou du MSKLC réservant la barre
echo    aux espaces. Or cette bonne intention de l’auteur ne fait pas l’unanimité.
echo.
echo    Deux idées pour des allocations alternatives au niveau AltGr d’Espace :
echo.
echo    +  Le tiret bas, qui en général remplace l’espace, a été retenu pour cette
echo    place sur la Disposition francophone et ergonomique bépo :  https://bepo.fr
echo.
echo    +  La touche compose de la disposition, qui est une touche morte
echo    enchaînée, se combine ainsi facilement avec d’autres caractères en AltGr.
echo.
echo    Tout cela et bien plus, vous pouvez le faire si vous modifiez la source KLC
echo    dans un éditeur de texte, qui peut être très simple pour de petites choses.
echo    Vous pouvez aussi décider de le programmer en langage C.
echo.
echo    Avec le MSKLC vous passez toujours par les sources en C. Appuyez sur une
echo    touche et je vous montre où elles apparaissent. Et autre chose encore…
color f2
pause >nul
call %TEMP%
call %MSKLCprofile%\nameslist.txt
if %helplevel% neq 10 (
	set /a helplevel=4
	call :saveuserprofile
)
goto :eof

:: ######____AIDE MSKLC :  UTILISATION AUGMENTÉE 2____######## 5 ####################
:helpMSKLCenh2
color f9
echo.&echo.&echo.
echo     ^>  Exemple 2 :  Noms en français dans le MSKLC                    ( 5/10 )
echo.
echo    Pour que le MSKLC puisse afficher les noms des caractères, il est fourni
echo    avec le code source des tableaux de code Unicode dans leur version actuelle
echo    de son époque (5.0). C’est la Names List, destinée à la lecture humaine car
echo    son contenu n’est autre que le texte imprimé en tant que Code Charts. Ces
echo    dernières contiennent aussi pour chaque caractère un exemple de glyphe.
echo.
echo    Une fonctionnalité de mise à jour permet au MSKLC de télécharger sur demande
echo    la version la plus récente (Help ^> Update Unicode character data). Mais les
echo    noms seront toujours en anglais. Pour les avoir en français, utilisez la
echo    traduction française Liste des Noms, qui est le code source de la version
echo    française d’ISO 10646, l’avatar du standard Unicode au niveau de l’ISO.
echo.
echo    Sur le site québecois HAPAX vous trouverez une version assez récente de la
echo    Liste des Noms, sachant qu’elle est en cours de mise à jour ;  à la rubrique
echo    Tableaux de codes et liste de noms annotés (Unicode 5.0 et 7.0), cliquez sur
echo             Liste des noms Unicode 7.0 et ISO/CEI 10646:2014 annotés
echo.
echo    Placez-en une copie dans le(s) dossier(s) MSKLC utilisateur. Vous basculerez
echo    entre le français et l’anglais selon lequel des deux fichiers sera (re)nommé
echo    en "nameslist.txt". Je vais ouvrir votre dossier MSKLC, et faire afficher
echo    l’accueil d’Hapax et deux pages sur Unicode.org ;  appuyez sur une touche…
color f2
pause >nul
start "L'endroit où le MSKLC se garde pour vous une copie de la liste des noms" %LOCALAPPDATA%\MSKLC
start https://hapax.qc.ca/
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                    Hapax - Unicode et ISO 10646 en français
echo.&echo.
echo                              https://hapax.qc.ca/
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop2
call :milliwait & color cf
call :milliwait & color 0f
call :milliwait & color cf
call :milliwait & color f0
set /a count+=1
if %count% lss 3 goto loop2
start https://www.unicode.org/Public/latest/UCD/nameslist.txt
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                                NamesList.txt
echo.&echo.
echo                          Unicode Character Database
echo.&echo.
echo              https://www.unicode.org/Public/latest/UCD/nameslist.txt
echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop3
call :milliwait & color cf
call :milliwait & color 4f
call :milliwait & color cf
call :milliwait & color f0
set /a count+=1
if %count% lss 2 goto loop3
start https://www.unicode.org/charts/
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                                 Code Charts
echo.&echo.
echo                                   Unicode
echo.&echo.
echo                        https://www.unicode.org/charts/
echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop4
call :milliwait & color cf
call :milliwait & color 4f
call :milliwait & color cf
call :milliwait & color f0
set /a count+=1
if %count% lss 2 goto loop4
if %helplevel% neq 10 (
	set /a helplevel=5 
	call :saveuserprofile
)
goto :eof

:: ######____AIDE MSKLC :  ALLER PLUS LOIN____######## 6 ##########################
:helpMSKLCdvp
color f9
echo.&echo.&echo.
echo    Quand on utilise l’interface graphique du MSKLC, il faut être conscient
echo    qu’un certain nombre de limites sont contingentes et ne signifient pas que
echo    Microsoft insisterait pour qu’elles soient respectées. Tout au plus est-ce
echo    Michael S. KAPLAN, l’auteur du MSKLC, qui a exprimé par certaines d’entre
echo    elles son souci de voir ses utilisateurs faire de bons claviers. D’autres
echo    sont dues aux impératifs de simplicité, à une conviction, voire une erreur :
echo.
echo    - Les enchaînements de touches mortes sont indisponibles mais Michael KAPLAN
echo      a montré sur son blog comment les implémenter en éditant la source KLC.
echo.
echo    - Une bascule et des modificatrices supplémentaires sont indisponibles
echo      sauf en éditant les sources, et Michael KAPLAN en a parlé sur son blog.
color f1
echo.
echo    - L’appui sur une touche peut insérer jusqu’à 16 unités de code, ce qui
echo      équivaut à 16 lettres latines, sauf sur Maj+AltGr où la limite est 4.
echo      Le MSKLC généralise cette limite basse. -- Par ailleurs il ne gère pas
echo      ces séquences en AltGr, un bug que Michael KAPLAN a amèrement déploré
echo      et qu’il voulait corriger à la prochaine mise à jour, qui n’eut pas lieu.
echo.
echo     ^>  Michael S. KAPLAN est décédé en 2015. Son blog a été archivé.
echo        Je vous exhorte vivement à le visiter pour plus de renseignements.
echo.
echo    Pour y lire comment chaîner des touches mortes faites Entrée (N pour Non).
color f0
set /p blogvisit= .                              
if %helplevel% neq 10 (
	set /a helplevel=6
	call :saveuserprofile
)
if defined blogvisit (
	if    "%blogvisit:~,1%" equ "?" goto :eof
	if /i "%blogvisit:~,1%" equ "m" goto :eof
	if /i "%blogvisit:~,1%" equ "n" goto :eof
)
start https://archives.miloush.net/michkap/archive/2011/04/16/10154700.html
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                      Chain Chain Chain, Chain of Dead Keys
echo.&echo.
echo                            Sorting it all Out, v2!
echo.&echo.
echo                  https://archives.miloush.net/michkap/archive/2011/04/16/10154700.html
echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop5
call :milliwait & color 8f
call :milliwait & color 0a
call :milliwait & color 8f
call :milliwait & color 71
set /a count+=1
if %count% lss 7 goto loop5
goto :eof

:: ######____AIDE CRÉATION :  PREMIÈRES ÉTAPES____############ 7 ##################
:helpstart
color f9
echo.&echo.&echo.
echo    Voici les premières étapes de la création d’une disposition :       ( 7/10 )
echo.
echo    Créez une disposition de clavier personnalisée tant bien que mal, à titre
echo    provisoire, en suivant le guide fourni avec le MSKLC (Help ^> Contents). 
echo     ^>  Évitez dans tous les cas de choisir pour votre disposition un nom de
echo        fichier comportant un point, car ce point bloquerait la compilation.
echo        Je vous préviendrai le moment venu si je trouve un point dans un nom.
echo.
echo    Faites compiler les pilotes par le MSKLC et lancez l’installation. 
echo    Celle-ci prend entre une dizaine de secondes et plusieurs minutes, à cause 
echo    de la création automatique d’un point de restauration du système.
echo.
echo    Copiez-moi dans le dossier de travail du MSKLC, défini par vos soins au bas
echo    de l’interface graphique, appelé "Current working directory", où se trouvent
echo    la source KLC de votre nouvelle disposition de clavier ainsi que le dossier
echo    contenant les pilotes et, surtout, les fichiers d’installation générés par
echo    le MSKLC. Faites-moi tourner là-bas sur la source KLC modifiée, ou demandez-
echo    moi d’abord les sources en langage C, puis relancez-moi sur ces dernières.
echo    Je les ferai respecter du moment qu’elles se trouveront auprès de moi.
echo.
echo    Voici la principale source commune :  kbd.h. (Appuyez sur une touche…)
echo     ^>  Elle est dans le dossier du MSKLC, sous-dossier \inc\, mais je vous en
echo        mettrai une copie ici auprès de moi pour que vous l’ayez sous la main.
color f2
pause >nul
echo.
copy  %MSKLCprofile%\inc\kbd.h   kbd-H(copie_pour_lecture_humaine).txt
call kbd-H(copie_pour_lecture_humaine).txt
if %helplevel% neq 10 (
	set /a helplevel=7
	call :saveuserprofile
)
goto :eof

:: ######____AIDE CRÉATION :  ÉDITER LES SOURCES____######## 8 ####################
:helpsources
color f9
echo.&echo.&echo.
echo    Certaines fonctionnalités très utiles sont disponibles uniquement  ( 8/10 )
echo    lorsque les sources des pilotes de disposition sont éditées de manière
echo    traditionnelle, à l’aide d’éditeurs de texte et éventuellement de tableurs.
echo.
echo    La page   ^<^< Création d’un clavier Windows ^>^>   du site de l’association
echo    MON NOM ACCENTUÉ qui milite depuis longtemps pour l’orthographe complète,
echo    explique en détail la structure des sources de clavier Windows, exemple à
echo    l’appui car le CLAVIER GALÉRON, qui est un modèle de disposition complète,
echo    vous est partagé aussi sous forme de dossier de sources personnalisables.
echo.
echo     ^>  Appuyez sur une touche et je vous y emmène de suite.
echo.
echo    Bien sûr que certaines parties de ces sources ne sont pas très faciles à
echo    comprendre puisqu’elles sont écrites dans en langage C. Mais il n’est pas
echo    nécessaire de comprendre absolument tout, et en partant d’une bonne base,
echo    les modifications peuvent être simples.
echo.
echo     ^>  Petite astuce pour modifier les tableaux dans la source .C :
echo.
echo    Copiez-collez-les dans une feuille de calcul formatée 'Texte', où beaucoup
echo    de choses deviennent plus simples. Une fois finis, les tableaux seront
echo    copiés et collés en remplacement des tableaux d’origine dans la source.
echo                                                     Appuyez sur une touche…
color f2
pause >nul
if %helplevel% neq 10 (
	set /a helplevel=8
	call :saveuserprofile
)
start http://accentuez.mon.nom.free.fr/Clavier-CreationClavier.php
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                         Création d’un clavier Windows
echo.&echo.
echo                  sur le site de l’association Mon Nom Accentué
echo.&echo.
echo           http://accentuez.mon.nom.free.fr/Clavier-CreationClavier.php
echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop6
call :milliwait & color e0
call :milliwait & color 2f
call :milliwait & color e0
call :milliwait & color f0
set /a count+=1
if %count% lss 7 goto loop6
goto :eof

:: ######____AIDE CRÉATION :  COMPILATION____######### 9 ###########################
:helpcompile
color f9
echo.&echo.&echo.
echo    Je vous conseille de tester régulièrement vos modifications,        ( 9/10 )
if "%machine%" equ "i386" (
echo    et pour ce faire, de me demander de compiler un pilote de test, que
) else (
echo    et pour ce faire, de me demander de compiler les deux pilotes de test, que
)
echo    je vous mettrai directement dans le%pls% répertoire%pls% système, après avoir
echo    récupéré le%pls% pilote%pls% d’origine. Je peux faire compiler en tout quatre
echo    pilotes différents, mais je sais le%pls%quel%pls% il vous faut, parce que
echo    le type d’architecture %bit% bit de votre machine m’est connu par Windows.
echo.
echo    À votre prochaine ouverture ou réouverture de session, le%pls% pilote%pls%
echo    passer%vba% du disque dur dans la mémoire vive et ser%vba% testable%pls%.
echo.
echo     ^>  Veillez dans un premier temps à ce que le clavier associé à la
echo        langue d’entrée par défaut ne soit pas concerné par ces tests.
echo.
echo    Quand votre nouvelle disposition sera bonne, comptez sur moi pour déclencher
echo    la compilation des pilotes définitifs pour toutes les architectures.
echo    Je vous les emballerai avec des copies des installateurs d’origine.
echo.
echo    En complément je prépare des packs de recompilation, grâce auxquels toute
echo    personne ayant le MSKLC sera en état de personnaliser (et de refaire) les
echo    pilotes. Cela assure la transparence -- et aide à promouvoir la liberté.
echo.
echo     ^>  Si KbdUTool plante, ne vous inquiétez pas, c’est suivant l’encodage
echo        de la source KLC. Modifiez-le dans les Préférences ou sur le fichier.
color f2
pause >nul
if %helplevel% neq 10 (
	set /a helplevel=9
	call :saveuserprofile
)
goto :eof

:: ######____AIDE CRÉATION :  DÉBOGUER UNE DISPOSITION____######### 10 ############
:helpdebug
color f9
echo.&echo.&echo.
echo    Les claviers peuvent présenter des bugs assez surprenants :        ( 10/10 )
echo.
echo :( Si la disposition ne fonctionne pas dans certains programmes, vérifiez si
echo    elle contient une séquence de plus de 4 unités au niveau Maj + AltGr.
echo.
echo :( Si une ou plusieurs touches mortes ne fonctionnent pas dans tel navigateur
echo    (ni d’autres dans tel autre), vous êtes face à un bug assez courant dans
echo    les dispositions lourdes sous Windows. Je suppose que les navigateurs, dont
echo    l’interface de saisie n’est pas la priorité, y ont du mal à lire les
echo    bibliothèques de liens dynamiques (DLL) que sont les pilotes de disposition.
echo    Sans doute l’XML, utilisé sous Mac OS X, est plus stable et mieux adapté.
echo.
echo :( Si certains raccourcis clavier de vos programmes ne fonctionnent plus, ou si
echo    au contraire vous obtenez des fonctionnalités au lieu de pouvoir insérer des
echo    caractères en AltGr, vous êtes victime du choix (mal avisé) de Microsoft qui
echo    a implémenté AltGr en y associant la combinaison Contrôle + Alt. En effet,
echo    à cette époque, les raccourcis clavier des programmes étaient peu nombreux.
echo    Or il existe d’autres modificatrices, introduites sur les claviers japonais
echo    et utilisées dans le monde entier, notamment au Canada.
echo                                                             Tapez une touche…
color f2
pause >nul
if %helplevel% neq 10 (
	set /a helplevel=10
	call :saveuserprofile
)
start https://bepo.fr/wiki/Utilisateur:LeBret/Remplacer_AltGr_par_Kana
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             Veuillez patienter, votre navigateur va afficher la page
echo.&echo.
echo                   Utilisateur:LeBret/Remplacer AltGr par Kana - 
echo.&echo.
echo              Disposition de clavier francophone et ergonomique bépo
echo.&echo.
echo         https://bepo.fr/wiki/Utilisateur:LeBret/Remplacer_AltGr_par_Kana
echo.&echo.&echo.&echo.&echo.&echo.
set count=0
:loop7
call :milliwait & color 2f
call :milliwait & color 5f
call :milliwait & color cf
call :milliwait & color 9f
call :milliwait & color e0
set /a count+=1
if %count% lss 7 goto loop7
goto :eof

:: ######____R O U T I N E S____################################################

:: ######____ÉDITER LES RESSOURCES____##########################################

:: Lire et récrire le fichier des ressources .RC, automatiser le versionnage :
:resources

:: Lecture du fichier ressources .RC :
:readrc
echo  Merci de bien vouloir patienter, je suis en train de lire le fichier RC…
:: Lecture de la partie numérique :
:readnumbrc
set /a index=0
for /f "skip=1 usebackq tokens=1,2 delims= " %%E in ("%name%.RC") do (
	set "nbrc[!index!][0]=%%~E"
	set "nbrc[!index!][1]=%%~F"
	set /a index += 1
	if %index% gtr 10 goto parsenumrc
)
:parsenumrc
set /a inx=0
:parsenumloop
if "!nbrc[%inx%][0]!" equ "FILEVERSION"    set filvnbrrc=!nbrc[%inx%][1]!
if "!nbrc[%inx%][0]!" equ "PRODUCTVERSION" set provnbrrc=!nbrc[%inx%][1]!
if %inx% gtr %index% goto readchainrc
set /a inx+=1
goto parsenumloop

:: Lecture des chaînes :
:readchainrc
set /a index=0
for /f skip^=14^ usebackq^ tokens^=1^,2^,4^ delims^=^" %%G in ("%name%.RC") do (
	set "rc[!index!][0]=%%~G"
	set "rc[!index!][1]=%%~H"
	set "rc[!index!][2]=%%~I"
	set /a index += 1
)
set /a inx=0
:parsechainrc
if "!rc[%inx%][0]!" equ "    1000    "        set descriprc=!rc[%inx%][1]!
if "!rc[%inx%][0]!" equ "    1100    "        set langfulrc=!rc[%inx%][1]!
if "!rc[%inx%][0]!" equ "    1200    "        set langabbrc=!rc[%inx%][1]!
if "!rc[%inx%][1]!" equ "FileVersion"         set filvstrrc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "ProductName"         set pronamerc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "ProductVersion"      set provstrrc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "CompanyName"         set autcomprc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "Release Information" set relsinfrc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "LegalCopyright"      set copyrigrc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "LegalTrademarks"     set tramarkrc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "InternalName"        set intnamerc=!rc[%inx%][2]:~,-2!
if "!rc[%inx%][1]!" equ "OriginalFilename"    set ofinamerc=!rc[%inx%][2]:~,-2!
if %inx% lss %index% (
	set /a inx+=1
	goto parsechainrc
)
set rc
pause
:: Remplit les variables non définies :
if not defined descriprc set descriprc=nul
if not defined pronamerc set pronamerc=nul
if not defined autcomprc set autcomprc=nul
if not defined relsinfrc set relsinfrc=nul
if not defined copyrigrc set copyrigrc=nul
if not defined tramarkrc set tramarkrc=nul

:: Conversions :
:: Conversion de Windows 1252 ("ANSI") vers OEM 850 :
echo  Merci de patienter, je suis en train de convertir des lettres diacritées…
set item[1]=%descriprc%
set item[2]=%pronamerc%
set item[3]=%autcomprc%
set item[4]=%relsinfrc%
set item[5]=%copyrigrc%
set item[6]=%tramarkrc%
set /a ind=0
:converto850loop
set /a ind+=1
echo  Je suis en train de convertir la variable %ind%…
set it=!item[%ind%]!
call :convert1252to850
set item850[%ind%]=%it%
if %ind% lss 6 goto converto850loop
set descripcv=%item850[1]%
set pronamecv=%item850[2]%
set autcompcv=%item850[3]%
set relsinfcv=%item850[4]%
set copyrigcv=%item850[5]%
set tramarkcv=%item850[6]%
echo  La description est :  %descripcv%
echo  La langue est :  %langfulrc%
echo  L’abréviation de la langue est :  %langabbrc%
echo  Le nom du produit ou du projet est :  %pronamecv%
echo  Nom de l’auteur ou de l’entreprise :  %autcompcv%
echo  Informations de sortie :  %relsinfcv%
echo  Droits d’auteur, licences [champ facultatif] :  %copyrigcv%
echo  Marques déposées [champ facultatif] :  %tramarkcv%
echo  Le nom interne est :  %intnamerc%
echo  Le nom d’origine du fichier est :  %ofinamerc%

:: Analyse des numéros de version :
for /f "usebackq tokens=1-4 delims=, " %%v in ('%filvnbrrc%') do (
	set "fvnb[1]=%%~v"
	set "fvnb[2]=%%~w"
	set "fvnb[3]=%%~x"
	set "fvnb[4]=%%~y"
)
for /f "usebackq tokens=1-4 delims=, " %%v in ('%provnbrrc%') do (
	set "pvnb[1]=%%~v"
	set "pvnb[2]=%%~w"
	set "pvnb[3]=%%~x"
	set "pvnb[4]=%%~y"
)
for /f "usebackq tokens=1-4 delims=, " %%v in ('%filvstrrc%') do (
	set "fvst[1]=%%~v"
	set "fvst[2]=%%~w"
	set "fvst[3]=%%~x"
	set "fvst[4]=%%~y"
)
for /f "usebackq tokens=1-4 delims=, " %%v in ('%provstrrc%') do (
	set "pvst[1]=%%~v"
	set "pvst[2]=%%~w"
	set "pvst[3]=%%~x"
	set "pvst[4]=%%~y"
)
:: Vérification des numéros de version :
set verok=yes& set vnbequvst=yes
if %fvnb[1]% neq %fvst[1]% set vnbequvst=no
if %fvnb[2]% neq %fvst[2]% set vnbequvst=no
if %fvnb[3]% neq %fvst[3]% set vnbequvst=no
if %fvnb[4]% neq %fvst[4]% set vnbequvst=no
if %pvnb[1]% neq %pvst[1]% set vnbequvst=no
if %pvnb[2]% neq %pvst[2]% set vnbequvst=no
if %pvnb[3]% neq %pvst[3]% set vnbequvst=no
if %pvnb[4]% neq %pvst[4]% set vnbequvst=no
if "%vnbequvst%" equ "no"  set verok=no
set fvequpv=yes
if %fvnb[1]% neq %pvnb[1]% set fvequpv=no
if %fvnb[2]% neq %pvnb[2]% set fvequpv=no
if %fvnb[3]% neq %pvnb[3]% set fvequpv=no
if %fvnb[4]% neq %pvnb[4]% set fvequpv=no
if "%fvequpv%" equ "no"    set verok=no
if "%verok%" equ "no" goto versionwarning

:showver
set fv
set pv

:versionwarning
echo    Selon les informations contenues dans le fichier de ressources,
echo    La version du pilote de disposition est :  %filvnbrrc% (%filvstrrc%)
echo    La version du projet ou du produit est :   %provnbrrc% (%provstrrc%)
echo    

:versioning

:: Ajoute le numéro de version actuel dans les fichiers d’installation :
:msiupdate
set arch=i386
call :update
set arch=amd64
call :update
set arch=ia64
call :update
echo  J’ai mis à jour le numéro de version dans les fichiers d’installation.
goto whatsoever
:update
:: Lecture d’un fichier d’installation :
set /a msinx=0
for /f "usebackq tokens=* eof= delims=" %%M in ("%name%_%arch%.msi") do (
	set /a msinx += 1
	set "msiln[!msinx!]=%%~M"
)
:: Réécriture d’un fichier d’installation :
echo !msiln[1]!> "%name%_%arch%.msi"
for /l %%I in (2,1,%msinx%) do (
	echo !msiln[%%I]:1.0.3.40=%fvnb[1]%.%fvnb[2]%.%fvnb[3]%.%fvnb[4]%!>> "%name%_%arch%.msi"
)
goto :eof

:whatsoever
pause

:: Conversion d’OEM 850 vers ANSI :
:cv850ansi
echo  Merci de patienter, je suis en train de convertir des lettres diacritées…
set item[1]=%descripcv%
set item[2]=%pronamecv%
set item[3]=%autcompcv%
set item[4]=%relsinfcv%
set item[5]=%copyrigcv%
set item[6]=%tramarkcv%
set /a ind=0
:cvansiloop
set /a ind+=1
echo  Je suis en train de convertir la variable %ind%…
set it=!item[%ind%]!
call :convert850to1252
set itemansi[%ind%]=%it%
if %ind% lss 6 goto cvansiloop
set descriprc=%itemansi[1]%
set pronamerc=%itemansi[2]%
set autcomprc=%itemansi[3]%
set relsinfrc=%itemansi[4]%
set copyrigrc=%itemansi[5]%
set tramarkrc=%itemansi[6]%

set descriprc
set langfulrc
set langabbrc
set filvstrrc
set pronamerc
set provstrrc
set autcomprc
set relsinfrc
set copyrigrc
set tramarkrc

echo %descriprc%>  Note91.txt
echo %langfulrc%>> Note91.txt
echo %langabbrc%>> Note91.txt
echo %filvstrrc%>> Note91.txt
echo %pronamerc%>> Note91.txt
echo %provstrrc%>> Note91.txt
echo %autcomprc%>> Note91.txt
echo %relsinfrc%>> Note91.txt
echo %copyrigrc%>> Note91.txt
echo %tramarkrc%>> Note91.txt
echo %intnamerc%>> Note91.txt
echo %ofinamerc%>> Note91.txt

:saverc
echo #include "winver.h">%name%.RC
echo 1 VERSIONINFO>>%name%.RC
echo     FILEVERSION    %filver[1]%,%filver[2]%,%filver[3]%,%filver[4]%>>%name%.RC
echo     PRODUCTVERSION %prover[1]%,%prover[2]%,%prover[3]%,%prover[4]%>>%name%.RC
echo     FILEFLAGSMASK  0x3fL>>%name%.RC
echo     FILEFLAGS      0x0L>>%name%.RC
echo     FILEOS         0x40004L>>%name%.RC
echo     FILETYPE       VFT_DLL>>%name%.RC
echo     FILESUBTYPE    VFT2_DRV_KEYBOARD>>%name%.RC
echo BEGIN>>%name%.RC
echo     BLOCK "StringFileInfo">>%name%.RC
echo     BEGIN>>%name%.RC
echo         BLOCK "000004B0">>%name%.RC
echo         BEGIN>>%name%.RC
echo             VALUE "FileDescription",     "%descrip% Keyboard Layout\0">>%name%.RC
echo             VALUE "FileVersion",         "%filver[1]%.%filver[2]%.%filver[3]%.%filver[4]%\0">>%name%.RC
echo             VALUE "ProductName",         "%proname%\0">>%name%.RC
echo             VALUE "ProductVersion",      "%prover[1]%.%prover[2]%.%prover[3]%.%prover[4]%\0">>%name%.RC
echo             VALUE "CompanyName",         "%autcomp%\0">>%name%.RC
echo             VALUE "Release Information", "%relsinf%\0">>%name%.RC
echo             VALUE "LegalCopyright",      "%copyrig%\0">>%name%.RC
echo             VALUE "LegalTrademarks",     "%tramark%\0">>%name%.RC
echo             VALUE "InternalName",        "%name%\0">>%name%.RC
echo             VALUE "OriginalFilename",    "%name%\0">>%name%.RC
echo         END>>%name%.RC
echo     END>>%name%.RC
echo     BLOCK "VarFileInfo">>%name%.RC
echo     BEGIN>>%name%.RC
echo         VALUE "Translation", 0x0000, 0x04B0>>%name%.RC
echo     END>>%name%.RC
echo END>>%name%.RC
echo.>>%name%.RC
echo STRINGTABLE DISCARDABLE>>%name%.RC
echo LANGUAGE 9, 1>>%name%.RC
echo BEGIN>>%name%.RC
echo     1200    "%langabbsv%">>%name%.RC
echo END>>%name%.RC
echo.>>%name%.RC
echo.>>%name%.RC
echo STRINGTABLE DISCARDABLE>>%name%.RC
echo LANGUAGE 9, 1>>%name%.RC
echo BEGIN>>%name%.RC
echo     1000    "%descripsv%">>%name%.RC
echo END>>%name%.RC
echo.>>%name%.RC
echo.>>%name%.RC
echo STRINGTABLE DISCARDABLE>>%name%.RC
echo LANGUAGE 9, 1>>%name%.RC
echo BEGIN>>%name%.RC
echo     1100    "%langfulsv%">>%name%.RC
echo END>>%name%.RC

pause
goto eof

:convert850to1252
set it=%it:À=└%
set it=%it:Ë=╦%
set it=%it:à=Ë%
set it=%it:à=à%
set it=%it:È=╚%
set it=%it:â=È%
set it=%it:â=â%
set it=%it:ç=¦%
set it=%it:ç=ç%
set it=%it:Ã=+%
set it=%it:Ç=Ã%
set it=%it:Ù=┘%
set it=%it:ë=Ù%
set it=%it:ù=ù%
set it=%it:É=╔%
set it=%it:é=+%
set it=%it:é=é%
set it=%it:Â=┬%
set it=%it:Ê=╩%
set it=%it:Ò=Ê%
set it=%it:ã=Ò%
set it=%it:Î=╬%
set it=%it:î=¯%
set it=%it:ô=ô%
set it=%it:ê=█%
set it=%it:ê=ê%
set it=%it:û=¹%
set it=%it:ø=°%
set it=%it:Ï=¤%
set it=%it:Ø=Ï%
set it=%it:ï=´%
set it=%it:Ü=▄%
set it=%it:s=Ü%
set it=%it:ü=³%
set it=%it:Y=ƒ%
set it=%it:ÿ= %
set it=%it:Ì=¦%
set it=%it:è=Ì%
set it=%it:è=è%
set it=%it:S=è%
set it=%it:Ý=¦%
set it=%it:í=Ý%
set it=%it:ý=²%
set it=%it:ì=ý%
set it=%it:ò=^=%
set it=%it:Ä=-%
set it=%it:Z=Ä%
set it=%it:õ=§%
set it=%it:ä=õ%
set it=%it:Í=-%
set it=%it:Ö=Í%
set it=%it:ö=÷%
set it=%it:z=×%
set it=%it:Á=-%
set it=%it:ß=¯%
set it=%it:á=ß%
set it=%it:ó=¾%
set it=%it:ú=·%
set it=%it:Ñ=Ð%
set it=%it:ñ=±%
set it=%it:Õ=i%
goto :eof

:convert1252to850
set it=%it:└=À%
set it=%it:à=à%
set it=%it:Ë=à%
set it=%it:╦=Ë%
set it=%it:â=â%
set it=%it:È=â%
set it=%it:╚=È%
set it=%it:è=S%
set it=%it:è=è%
set it=%it:Ì=è%
set it=%it:¦=Ì%
set it=%it:ç=ç%
set it=%it:¦=ç%
set it=%it:Ã=Ç%
set it=%it:+=Ã%
set it=%it:Ù=ë%
set it=%it:┘=Ù%
set it=%it:ù=ù%
set it=%it:╔=É%
set it=%it:é=é%
set it=%it:+=é%
set it=%it:┬=Â%
set it=%it:Ò=ã%
set it=%it:Ê=Ò%
set it=%it:╩=Ê%
set it=%it:╬=Î%
set it=%it:¯=î%
set it=%it:ô=ô%
set it=%it:ê=ê%
set it=%it:█=ê%
set it=%it:¹=û%
set it=%it:°=ø%
set it=%it:Ï=Ø%
set it=%it:¤=Ï%
set it=%it:´=ï%
set it=%it:Ü=s%
set it=%it:▄=Ü%
set it=%it:³=ü%
set it=%it:ƒ=Y%
set it=%it: =ÿ%
set it=%it:Ý=í%
set it=%it:¦=Ý%
set it=%it:ý=ì%
set it=%it:²=ý%
set it=%it:^==ò%
set it=%it:Ä=Z%
set it=%it:-=Ä%
set it=%it:õ=ä%
set it=%it:§=õ%
set it=%it:Í=Ö%
set it=%it:-=Í%
set it=%it:÷=ö%
set it=%it:×=z%
set it=%it:-=Á%
set it=%it:ß=á%
set it=%it:¯=ß%
set it=%it:¾=ó%
set it=%it:·=ú%
set it=%it:Ð=Ñ%
set it=%it:±=ñ%
set it=%it:i=Õ%
goto :eof

:: ######____DÉFINIR LE PROJET____##############################################
:project
set cbg=a&set cfg=0
color %cbg%%cfg%
echo.&echo.&echo.
echo                     D É F I N I R   U N   P R O J E T
echo.&echo.
echo    Travailler avec un projet permet d’avoir la meilleure visibilité sur les
echo    différents paramètres et valeurs qui le concernent, et dont je me sers en
echo    partie à différentes étapes de la production de dispositions de clavier.
echo.
echo    Pour produire différentes variantes en parallèle, la seule manière de gérer
echo    le tout est de définir un projet listant le nom de fichier et la description
echo    visible de chaque disposition, les valeurs des champs communs des propriétés
echo    ainsi que certains paramètres comme le nom du fichier en-tête commun.
echo.
echo    Le nom du projet est égal au nom du produit, impossible à paramétrer dans
echo    le MSKLC, tout comme le numéro de version, que je me propose à vous aider
echo    à inscrire dans le pilote et dans l’installateur afin que ce qui s’affiche
echo    dans les différents endroits corresponde à ce que vous souhaitez y voir 
echo    figurer.

:: Lecture du fichier des propriétés du projet :
:names
color %cbg%%cfg%
if not exist creadispo-projet.txt goto newproject
echo.&echo.&echo.
echo    Vous avez un fichier de propriétés du projet "creadispo-projet.txt".
echo.&echo.&echo.&echo.
echo     ^>  Souhaitez-vous utiliser les propriétés du projet existant ou
echo.
echo        créer un nouveau projet ?
echo.
echo    Dans ce dernier cas je garderai les données existantes en renommant
echo    le fichier des données avec l’attribut "ANCIEN" et un numéro courant.
echo.&echo.&echo.
echo     +  Pour travailler sur le projet existant appuyez simplement sur Entrée.
echo.
echo     +  Pour créer un nouveau projet faites N (majuscule ou minuscule) Entrée.
echo.
echo                  Pour retourner au menu principal saisissez M.
echo                  Pour afficher le menu de l’aide saisissez A ou ?.
echo.
set option=
set /p option= .                     Votre choix : 
if defined option (
	if /i "%option:~,1%" equ "a" goto help
	if /i "%option:~,1%" equ "m" goto menu
	if /i "%option:~,1%" equ "n" goto newproject
	if    "%option:~,1%" equ "?" goto help
)
echo  Je lis les propriétés du projet…
call :readprojectprops
if defined projectname (
echo.
echo    Comme le projet %projectname% est un projet nommé,
echo    je créé -- pour les versions finies -- des surdossiers portant son nom,
echo    indépendamment du nombre [%number%] de dispositions.
echo    Les noms peuvent être modifiés en éditant le fichier des propriétés du projet.
echo.
) else (
	if %number% equ 1 (
echo.
echo    Ce projet comprend une seule disposition, et comme il ne porte pas de nom
echo    particulier, ses résultats ne seront jamais placés dans des surdossiers.
echo.
echo    Les noms peuvent être modifiés en éditant le fichier des propriétés du projet.
	) else (
		if not exist Multiprojet (
			set projectname=Multiprojet
		) else (
			:nbloop
			set /a mpnb+=1
			if not exist Multiprojet[%mpnb%] set projectname=Multiprojet[%mpnb%] else goto nbloop
		)
echo.
echo    Comme ce projet comprend %number% dispositions et qu’il ne porte pas
echo    de nom particulier, je l’appellerai %projectname% car c’est un projet
echo    multiple, dont les résultats seront groupés dans des surdossiers nommés.
echo    Les noms peuvent être modifiés en éditant le fichier des propriétés du projet.
	)
)
goto :eof

:: Créer un nouveau projet :
:newproject
:: Conserver les données d’un éventuel projet précédent :
if exist creadispo-projet.txt (
	set /a num=1
	:renpdata
	if exist "creadispo-projet - ANCIEN (!num!).txt" set /a num+=1 && goto renpdata
	rename creadispo-projet.txt "creadispo-projet - ANCIEN (!num!).txt"
) else goto searchname
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo    Votre projet précédent est maintenant dans le fichier dont le nom est :
echo.
echo                   creadispo-projet - ANCIEN (!num!).txt
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.

:: Analyse d’un éventuel fichier de définition de module :
:searchname
echo.
echo  Je cherche un fichier de définition de module pour lire un nom…
echo.
call :defcheck
if "%defname%" equ "yes" (
echo    Je trouve un fichier DEF quelque part autour d’ici dans ce dossier,
echo    et à l’intérieur je lis le nom de fichier de la disposition :  !name!.
echo.
	if "!defnameklc!" equ "yes" (
echo    C’est probablement exact car auprès de moi je trouve aussi le fichier
echo    !name!.klc tel que j’en ai besoin pour faire tourner l’utilitaire KbdUTool
echo    inclus dans le MSKLC.
	) else (
echo    Mais dommage qu’il n’y ait pas de source KLC à ce nom auprès de moi,
echo    car j’en ai absolument besoin pour faire tourner l’utilitaire KbdUTool
echo    inclus dans le MSKLC.
	)
) else (
:: Détection d’une éventuelle source KLC :
echo  Je cherche une source KLC dans ce dossier…
echo.
	call :klccheck
	if "!klcthere!" equ "yes" (
echo    Je trouve un fichier KLC quelque part autour d’ici dans ce dossier,
echo    mais à l’intérieur je n’arrive pas à lire le nom de la disposition,
echo    car mon interpréteur ne lit pas encore les fichiers dont le format
echo    d’encodage est selon Unicode ; tout ce que je peux récupérer de la
echo    première ligne, qui pourtant contient le nom de fichier, est "!klc1stline!".
	) else (
echo    Pour l’instant je ne trouve aucun fichier autour de moi qui contienne
echo    les renseignements dont j’aurai besoin. Je vais donc vous prier de me
echo    communiquer un certain nombre d’éléments pour que je puisse créér le
echo    fichier des propriétés du projet, qui sera nommé "creadispo-projet.txt".
	)
)
:: Renseigne les noms :
color %cbg%%cfg%
:nameqtn
echo.&echo.
echo     ^>  Quel est le nom de fichier de la disposition de clavier s.v.p. ?
echo.&echo.
echo    Ignorez l’extension de fichier et entrez uniquement le nom.
echo                                                               Aide :  ? Entrée
set name=
set /p name= .  Nom de fichier de la disposition de clavier : 
if not defined name (
	color cf
echo.&echo.&echo.
echo    Le nom de fichier est indispensable pour la suite ;  donnez-m’en un s.v.p.
echo.&echo.&echo.
	call :milliwait
	color %cbg%%cfg%
	goto nameqtn
)
if "%name%" equ "?" set helpreq=yes& goto :eof
call :namecheck
if "%renam%" equ "yes" goto nameqtn
color %cbg%%cfg%
echo.&echo.&echo.
echo     ^>  Le projet va-t-il porter un nom ?
echo.
echo    Nommer votre projet est utile surtout dans le cas d’un multiprojet.
echo.&echo.
echo    Il n’est pas nécessaire d’être sûr des différents noms maintenant,
echo    car le fichier des propriétés du projet est modifiable jusqu’au lancement
echo    des cycles de compilation.
echo.&echo.&echo.
echo     ^>  Si vous souhaitez laisser votre projet sans nom,
echo        appuyez seulement sur Entrée.
echo.
echo    Dans le cas d’un multiprojet j’utiliserai alors le nom générique :
echo    Multidispo.
echo.
echo    Dans le cas d’une disposition seule j’éviterai de la ranger dans
echo    un surdossier si le projet n’est pas nommé.
echo.
echo                                                               Aide :  ? Entrée
echo.
set projectname=Multidispo
set /p projectname= .  Nom du projet [libre] : 
if "%projectname%" equ "?" set helpreq=yes& goto :eof
echo.&echo.&echo.&echo.
echo     ^>  Utilisez-vous une source en-tête ou header commune ?
echo.&echo.
echo    Ce header commun, s’il existe, est utile pour rationaliser la gestion
echo    des headers des différentes dispositions d’un multiprojet, et/ou pour
echo    réutiliser les mêmes données à plusieurs reprises au fil du temps.
echo.&echo.&echo.
echo     ^>  Un en-tête commun doit être inclus en ajoutant dans la source C ou
echo        dans la source H dédiée, c’est-à-dire portant le nom de fichier de
echo        la disposition, la ligne de code suivante :
echo.
echo             #include "[nom de l’en-tête commun].h"
echo.&echo.&echo.
echo    Si vous n’utilisez pas d’en-tête commun, laissez ce champ en blanc
echo    en appuyant seulement sur Entrée.
echo                                                               Aide :  ? Entrée
echo.
set cmheader=
set /p cmheader= .  Nom de fichier sans extension : 
if "%cmheader%" equ "?" set helpreq=yes& goto :eof
echo.
echo    Merci, je vais créer maintenant le fichier "creadispo-projet.txt".
echo.
:: Ajoute un fichier de données projet contenant les noms :
call :saveprojectprops
goto :eof

:: Batterie de vérifications :
:namecheck
color %cbg%%cfg%
call :lengthcheck
if "%renam%" equ "yes" goto :eof
call :periodcheck
if "%renam%" equ "yes" goto :eof
call :initialcheck
if "%renam%" equ "yes" goto :eof
call :abilitycheck
echo.
echo  J’ai fini de vérifier le nom de fichier %name%.
echo.
goto :eof

:: Vérifie si le nom ne dépasse pas les 8 caractères :
:lengthcheck
set renam=yes
if "%name:~8,1%" equ "" set renam=no
if "%renam%" equ "yes" (
color cf
echo.&echo.&echo.&echo.
echo     ^>  La chaîne de caractères %name%
echo        ne peut pas être utilisée comme nom de fichier,
echo        car sa longueur dépasse 8 caractères.
echo.&echo.
echo    Vous pouvez toutefois utiliser %name%
echo    en tant que désignation.
echo    Ajoutez-la alors par la suite dans le fichier creadispo-projet.txt
echo    que je vais générer tout à l’heure, et n’omettez pas de mettre à jour
echo    le fichier .RC que KbdUTool va générer comme un élément des sources.
echo.&echo.
echo    La désignation figure au nombre des renseignements que le MSKLC vous
echo    propose de recueillir pour chaque disposition créée avec son concours.
echo.
echo    Ce que vous voyez dans la barre des langues ne sont pas les noms des
echo    dispositions. Ce sont les désignations. Ce que l’on appelle le nom de
echo    la disposition est son nom de fichier, qui pour des raisons techniques
echo    liées au système de fichier ne doit pas dépasser les huit caractères.
echo.&echo.
call :milliwait & call :milliwait
color fc
pause
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     ^>  Je reprends ma question du nom de fichier de la disposition :
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
color %cbg%%cfg%
goto :eof
) else (
echo.
echo  J’ai vérifié que %name% ne dépasse pas les 8 caractères.
)
goto :eof

:: Vérifie si le nom ne contient pas de point :
:periodcheck
set renam=no
set /a pos=0
:periodloop
if "!name:~%pos%,1!" equ "." set renam=yes
set /a pos+=1
if !pos! lss 8 goto periodloop
if "!renam!" equ "yes" (
	color cf
echo.&echo.&echo.&echo.
echo     ^>  La chaîne de caractères %name%
echo        ne peut être utilisée comme nom de fichier de disposition de clavier,
echo        car elle contient le caractère point.
echo.&echo.
echo    Les noms de fichier des dispositions de clavier doivent être exempts
echo    de points. Un point dans le nom d’une disposition de clavier conduit
echo    à un blocage au moment de la compilation.
echo.&echo.&echo.&echo.&echo.
echo    D’autres caractères inutilisables dans ce contexte sont "/", "\", et "?",
echo    ainsi que tous les caractères non ASCII.
echo.
echo    Mais à ce propos vous êtes prévenu directement par le MSKLC.
echo.&echo.&echo.&echo.
	call :milliwait & call :milliwait
	color fc
	pause
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     ^>  Je reprends ma question du nom de fichier de la disposition :
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
	color %cbg%%cfg%
	goto :eof
) else (
echo.
echo  J’ai vérifié que %name% ne contienne pas de point.
)
goto :eof

:: Vérifie si le nom commence par kb ou kbd :
:initialcheck
if /i "%name:~,2%" neq "kb" (
	color cf
echo.&echo.&echo.&echo.
echo     ^>  Il est recommandé de commencer le nom de fichier des
echo        pilotes de disposition par les lettres "kb", pour "keyboard",
echo        ou si possible même "kbd" pour "keyboard driver".
echo.&echo.
echo    Cette convention permet d’éviter d’éventuelles confusions,
echo    mais au-delà elle n’a rien d’obligatoire.
echo.&echo.&echo.&echo.&echo.&echo.
echo    Si vous souhaitez garder le nom %name% malgré qu’il ne commence pas
echo    par "kb" voire "kbd", dites Oui en tapant O ou o puis Entrée ci-dessous.
echo.
echo                 Sinon appuyez sur Entrée sans plus.
echo.&echo.&echo.&echo.
	call :milliwait
	color fc
	set chname=
	set /p chname= .   O pour Oui, ou juste Entrée pour changer le nom : 
	if defined chname (
		if /i "!chname:~,1!" equ "o" (
			set renam=no
			goto :eof
		) else goto renyes
	) else (
		:renyes
		set renam=yes
		color %cbg%%cfg%
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     ^>  Je reprends ma question du nom de fichier de la disposition :
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
	goto :eof
	)
) else (
set renam=no
echo.
echo  J’ai vérifié que %name% commence par "kb" même si ce n’est pas obligatoire.
)
goto :eof

:: Vérifie si le pilote ciblé est installé et testable :
:abilitycheck
color %cbg%%cfg%
set installed=no
if not exist C:\Windows\System32\%name%.dll goto notinstalled
set installed=yes
:: Vérifie si le pilote ciblé est celui d’une disposition d’origine :
set moving=unable
rename C:\Windows\System32\%name%.dll %name%-move.dll
if exist C:\Windows\System32\%name%-move.dll set moving=able
if "%moving%" equ "able" (
	goto able
) else (
	goto unable
)
:able
rename C:\Windows\System32\%name%-move.dll %name%.dll
set nameok=yes
echo  J’ai vérifié que %name% soit testable, en le renommant puis le dérenommant.
goto :eof
:unable
color cf
echo.
echo    Le%pls% pilote%pls% de cette disposition %vbe% inamovible%pls%.
echo.
echo    Normalement il s’agit d’une disposition d’origine, fournie avec Windows.
echo.
echo     ^>  Vous pouvez modifier cette disposition sous un nom différent :
echo.
echo    1   Chargez-la dans le MSKLC (File > Load existing keyboard).
echo.
echo    2   Changez-la de nom. Dans la plupart des cas de doublons vous êtes
echo        prévenu immédiatement, dans les autres, quand l’installation échoue.
echo.
echo    3   Faites enregistrer sa source par le MSKLC (File > Save source as).
echo.
echo    4   Modifiez la disposition pour qu’elle se rapproche le plus possible
echo        de votre objectif.
echo.
echo    5   Des modifications plus avancées sont possibles dans la source KLC
echo        à l’aide d’un éditeur de texte, et d’autres, très utiles, seulement
echo        en éditant les sources en C. Je ferai générer ces sources pour vous.
echo.
color fc
call :milliwait & call :milliwait
color %cbg%%cfg%
set nameok=no
pause
if "%machine%" neq "i386" (
	if not exist C:\Windows\SysWOW64\%name%.dll set installed=half
)
goto :eof
:notinstalled
color cf
echo.&echo.&echo.&echo.&echo.&echo.
echo    En ce moment je ne peux trouver aucune disposition de clavier à ce nom
echo    qui soit installée sur votre ordinateur.
echo.&echo.
echo    Je prends cela comme un inconvénient parce que je ne pourrai pas préparer
echo    de quoi la tester, à moins de commencer par une version finie.
echo.
echo    Comme pour tout logiciel -- un pilote de clavier est une sorte de petit
echo    logiciel --, développer une disposition de clavier oblige à faire des
echo    tests exhaustifs, surtout quand la programmation se fait directement
echo    dans les sources, ce qui est la seule méthode possible pour nombre
echo    de fonctionnalités.
echo.&echo.
echo     ^>  Si vous avez le pack d’installation, je vous suggère
echo        de procéder à l’installation dès maintenant.
echo.
echo     ^>  Dans le cas contraire, faites une disposition du même nom
echo        à l’aide du MSKLC, et installez-là sur votre ordinateur.
echo.&echo.
set renam=no
color fc
echo    Pour continuer, appuyez sur une touche.
pause >nul
color %cbg%%cfg%
goto :eof
:halfinstalled
color cf
echo.&echo.
echo    Cette disposition de clavier est installée mais il lui manque
echo    le pilote pour les applications 32 bit.
echo.&echo.
echo     ^>  Si vous avez le pack d’installation,
echo        lancez-le s.v.p pour réparer la disposition.
echo.
echo    Si vous n’avez pas ce qu’il faut, désinstallez-la et faites une
color fc
echo    disposition du même nom à l’aide du MSKLC, puis installez celle-ci.
echo.&echo.&echo.
set renam=no
pause
color %cbg%%cfg%
goto :eof

:: Crée le fichier de propriétés du projet :
:saveprojectprops
call :savemainprojectprops
call :addnames
goto :eof

:savemainprojectprops
:: En-tête du fichier :
echo Encodage OEM 850> creadispo-projet.txt
echo Propriétés du projet %projectname%>> creadispo-projet.txt
echo ------------------------------------------------------------------------------------------->> creadispo-projet.txt
echo Fichier datant du %DATE%, %TIME:~,8%>> creadispo-projet.txt
echo Pour un projet multiple, listez les noms en-dessous du 3e trait, un par ligne.>> creadispo-projet.txt
echo Le nom est le nom de fichier ;  dans la Barre des langues l’utilisateur lit la description.>> creadispo-projet.txt
echo Ajoutez un point-virgule et la description, par exemple :  kbdnom;Clavier pour Claude>> creadispo-projet.txt
echo N’utilisez pas de point-virgule par ailleurs, car il est pris pour un séparateur.>> creadispo-projet.txt
echo Pour une reconnaissance correcte des diacrités français ce fichier doit être en OEM 850.>> creadispo-projet.txt
echo Si l’édition des ressources est active, la description est celle figurant au fichier .RC.>> creadispo-projet.txt
echo N’effacez ni ligne ni caractères avant les signes "=" car la lecture dépend de la position.>> creadispo-projet.txt
echo ------------------------------------------------------------------------------------------->> creadispo-projet.txt
echo                       Nom du projet ou du produit=%projectname%>> creadispo-projet.txt
echo         Nom de l’éventuelle source header commune=%cmheader%>> creadispo-projet.txt
echo ----------------------------------------------------------------------------------------->> creadispo-projet.txt
:: Nom (et description) de la (première) disposition :
if defined description ( set separ=;) else ( set separ=)
echo %name%%separ%%description%>> creadispo-projet.txt
goto :eof

:addnames
:: Ajoute un à un les noms de disposition supplémentaires (pour multiprojets) :
color %cbg%%cfg%
echo.
echo    Je viens de créer le fichier de propriétés du projet. Vous le trouverez
echo    à côté de moi, il porte le nom "creadispo-projet".
echo.
echo    C’est un fichier texte que vous pouvez facilement ouvrir
echo    et éditer si vous le souhaitez.
echo.
echo     ^>  Je le fais ouvrir de suite si vous tapez o et Entrée ci-dessous.
echo.&echo.&echo.&echo.&echo.
echo    Je gère aussi les projets multiples, que j’appelle "multiprojets".
echo.&echo.
echo     ^>  Si votre projet a pour objectif de produire une disposition unique,
echo        nommée %name%, confirmez-le moi s.v.p. en appuyant sur Entrée.
echo.
echo     ^>  Si vous créez un multiprojet, je vous invite à entrer maintenant
echo         les autres noms de fichier un à un en validant chacun par Entrée.
echo.&echo.&echo.
:nextname
set nextname=
set /p nextname= .  Nom suivant, ou seulement Entrée pour terminer : 
if not defined nextname goto nonext
if "%nextname%" equ "o" call creadispo-projet.txt && goto :eof
set name=%nextname%
call :namecheck
if "%renam%" equ "no" ( echo %name%>> creadispo-projet.txt )
if "%renam%" equ "yes" (
	color d0
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo            Je ne peux pas ajouter ce nom, je suis navré.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
	pause
	color %cbg%%cfg%
)
	goto nextname

:nonext
color a0
echo.&echo.&echo.&echo.
echo        Votre projet est créé. Je m’en occuperai selon vos instructions.
echo.&echo.&echo.
echo     ^>  Vous pouvez maintenant ajouter une description à chaque nom.
echo        Cette information figurera dans le nom de dossier de la disposition,
echo        mais uniquement dans les packs d’installation et de recompilation.
echo        Cela est particulièrement utile dans les multiprojets, parce que les
echo        utilisateurs s’y retrouvent ainsi mieux face aux listes de dossiers.
echo.
echo        Ajoutez cette description directement dans le fichier des données du
echo        projet, séparée du nom de la disposition par un point-virgule sans espaces :
echo.
echo            Exemple :  kbd45678;Description de la disposition
echo.&echo.&echo.&echo.
echo     ^>  Appuyez sur Entrée pour que je fasse ouvrir le fichier projet.
echo        [Tapez d’abord N pour passer cette étape.]
echo.
call :milliwait
color %cbg%%cfg%
set desc=
set /p desc= .   Confirmer par Entrée [N pour Non] : 
if not defined desc call creadispo-projet.txt && pause && goto :eof
if "%desc:~,1%" equ "n" goto :eof
call creadispo-projet.txt
pause && goto readprojectprops && goto :eof

:: Lecture du fichier des propriétés du projet :
:readprojectprops
set /a index=-3
for /f "skip=12 usebackq tokens=1* delims=; eol=" %%I in ("creadispo-projet.txt") do (
    set "entry[!index!][0]=%%~I"
    set "entry[!index!][1]=%%~J"
    set /a index += 1
)
echo  J’ai pris lecture du fichier des propriétés du projet.
:: Extrait les variables contenant les propriétés du projet :
set projectname=%entry[-3][0]:~50%
set cmheader=%entry[-2][0]:~50%
set name=%entry[0][0]%
set description=%entry[0][1]%
set number=%index%
if %number% gtr 1 ( set npls=s) else ( set npls=)
echo  Le projet %projectname% contient %number% disposition%npls%.
echo  Voici la liste complète des dispositions contenues dans
echo  le projet %projectname% :
echo  ------------------------------------------------------------------------
echo  Numéro d’ordre :  Nom :     Description :
echo  ------------------------------------------------------------------------
set /a inx=0
:wrtarray
set /a rank=%inx%+1
set rankcellraw=  %rank%&                 set rankcell=!rankcellraw:~-3!
set namecellraw=!entry[%inx%][0]!       & set namecell=!namecellraw:~,8!
echo               %rankcell%  %namecell%  !entry[%inx%][1]!
set /a inx += 1
if %inx% lss %number% goto wrtarray
echo  ------------------------------------------------------------------------
if defined cmheader (
echo  Le projet %projectname% utilise
echo  une source en-tête commune :  %cmheader%.H
)
goto :eof

:: Contrôle de présence des sources KLC :
:klcavacheck
set klcavaok=yes
set /a cycle=0
call :readprojectprops
:klcavachecknext
set name=!entry[%cycle%][0]!
echo %name%.klc
if exist "%name%.klc" (
echo OK
) else (
	set klcavaok=no
echo Cette source est manquante.
)
set /a cycle+=1
if %cycle% lss %number% goto klcavachecknext
echo  J’ai terminé le contrôle de présence des sources KLC.
goto :eof

:: Contrôle de présence des pilotes installés concernés sous architecture 32 bit :
:driver32check
set driverok=yes
set /a cycle=0
:driver32checknext
set name=!entry[%cycle%][0]!
if not exist %windir%\System32\%name%.dll (
	set driverok=no
	color cf
echo.
echo               Pour %name% je ne trouve pas le pilote installé.
echo.
echo      Pour être testable, la disposition doit être proprement installée.
echo.
)
set /a cycle+=1
if %cycle% lss %number% goto driver32checknext
echo  J’ai terminé le contrôle de présence des pilotes installés concernés.
goto :eof

:: Contrôle de présence des pilotes installés concernés sous architecture 64 bit :
:driver64check
set driverok=yes
set /a cycle=0
:driver64checknext
set name=!entry[%cycle%][0]!
if not exist %windir%\System32\%name%.dll ( if not exist %windir%\SysWOW64\%name%.dll (
	set driverok=no
	color cf
echo.
echo               Pour %name% je ne trouve pas les pilotes installés.
echo.
echo      Pour être testable, la disposition doit être proprement installée.
echo.
))
set /a cycle+=1
if %cycle% lss %number% goto driver64checknext
echo  J’ai terminé le contrôle de présence des pilotes installés concernés.
goto :eof

:: Contrôle de présence du header commun si défini :
:cmhavacheck
if defined cmheader (
	if not exist %cmheader%.H (
color cf
echo.
echo    Je ne trouve pas le fichier source en-tête [header] %cmheader%
echo    commun à toutes les dispositions qui est prévu dans le projet.
echo.
echo    S’il porte un autre nom, merci de bien vouloir le corriger directement
echo    dans le fichier des propriétés du projet, que je vais ouvrir dès que
echo    vous aurez appuyé sur une touche.
echo.&echo.&echo.
echo    Au cas où vous décideriez de ne pas utiliser d’en-tête commun,
echo    je vous invite à simplement effacer son nom dans les données mais
echo    à laisser la ligne où il figure.
echo.
echo    J’attends jusqu’à ce que vous ayez enregistré vos modifications.
echo.
echo    Le moment venu, appuyez-moi de nouveau sur une touche,
echo    et je reprendrai lecture du fichier des propriétés du projet.
echo.&echo.
echo     ^>  Quand vous aurez appuyé sur une touche, j’ouvrirai le fichier.
		pause >nul
		call creadispo-projet.txt
echo.&echo.&echo.
echo     ^>  Quand vous aurez appuyé de nouveau, j’en reprendrai lecture.
		pause >nul
		color f1 & call :readprojectprops & goto cmhavacheck
	) else (
		set cmhavaok=yes
	)
)
:: et nom par nom pour son inclusion :
set /a cycle=0
:nameavacheck
set cmhavaok=yes
set name=!entry[%cycle%][0]!
if defined cmheader (
	if not exist %name%.C if not exist %name%.H (
		set cmhavaok=no
		color cf
echo.
echo    Afin que le header commun soit pris en compte, il doit être inclus dans
echo    [au moins] une des autres sources, .C ou .H peu importe.
echo.
echo    Mais je ne trouve aucune de ces sources, ce qui signifie que les sources
echo    utilisées seront celle que KbdUTool va fraîchement générer pour l’occasion.
echo.
echo           Ces sources ne contiendront aucune inclusion de %cmheader%.H.
echo.
echo     ^>  Je vous invite à prendre une de ces sources, d’y ajouter l’inclusion
echo                      #include "%cmheader%.H"
echo     et de la mettre à côté de %cmheader%.H pour que tout soit pris en compte.
echo.
		pause
		color f1 & goto nameavacheck
	) else (
		set cmhavaok=yes
	)
)
set /a cycle+=1
if %cycle% lss %number% goto nameavacheck
echo  J’ai terminé un contrôle de présence par rapport à la source en-tête commune.
goto :eof

:: Contrôle de présence des installateurs :
:msiavacheck
set /a cycle=0
call :readprojectprops
:msiavachecknext
set name=!entry[%cycle%][0]!
if exist %name% ( if exist %name%\%name%_i386.msi ( if exist %name%\%name%_amd64.msi ( if exist %name%\%name%_ia64.msi ( if exist %name%\setup.exe (
	set installeravaok=yes
))))) else (
	set installeravaok=no
echo.&echo.&echo.&echo.
echo    Je constate malheureusement que pour la disposition %name%,
echo    il manque tout ou partie des installateurs, qui doivent se trouver
echo    dans un dossier au nom de la disposition, tel que le MSKLC en produit.
echo.
echo     ^>  Avant d’aller de l’avant, je vous invite à placer le dossier des
echo        installateurs ici auprès de moi, afin que je l’aie à portée.
echo.
echo    Si le dossier d’installateurs est manquant, le MSKLC vous le fera sur
echo    simple demande en faisant compiler les pilotes à partir d’une source KLC.
echo.&echo.&echo.
pause
)
set /a cycle+=1
if %cycle% lss %number% goto msiavachecknext
echo  J’ai terminé le contrôle de présence des installateurs.
goto :eof

:: Lecture du début d’un fichier de définition de module :
:defcheck
for /r %%v in (*.DEF) do set /p DEF1stline=<%%v
set name=%DEF1stline:~8%
if defined %name% ( set defname=yes) else ( set defname=no)
if exist %name%.klc ( set defnameklc=yes) else ( set defnameklc=no)
goto :eof

:: Lecture du début d’un fichier de configuration de disposition de clavier :
:klccheck
for /r %%v in (*.klc) do set /p klc1stline=<%%v
if defined klc1stline ( set klcthere=yes) else ( set klcthere=no)
goto :eof

:: Maintien des sources modifiées :
:: Passe les sources en lecture seule pour qu’elles soient conservées :
:locksources
set /a nbroa=0
if exist %name%.C   attrib +R %name%.C   && set /a nbroa+=1
if exist %name%.H   attrib +R %name%.H   && set /a nbroa+=1
if exist %name%.RC  attrib +R %name%.RC  && set /a nbroa+=1
if exist %name%.DEF attrib +R %name%.DEF && set /a nbroa+=1
if %nbroa% neq 0 (
	if %nbroa% equ 1 (
echo  J’ai protégé la source présente contre la réécriture afin que cette source
echo  soit conservée lorsque KbdUTool tentera de la remplacer par celle qu’il
echo  va générer au cours de la procédure.
	) else (
echo  J’ai protégé %nbroa% des sources présentes contre la réécriture afin
echo  que ces %nbroa% sources soient conservées lorsque KbdUTool tentera
echo  de les remplacer par celles qu’il va générer au cours de la procédure.
	)
)
if exist %cmheader%.H (
echo  La source en-tête [header] commune -- %cmheader%.H -- n’a pas besoin d’être
echo  protégée contre la réécriture car KbdUTool ne génère pas de source à ce nom.
)
if %nbroa% gtr 0 (
echo.
echo    L’attribut "lecture seule" est le moyen habituel de faire tourner sur
echo    des sources C modifiées un KbdUTool qui ne vous oblige ainsi jamais à
echo    fournir à la fois le corps de source, l’en-tête, le fichier ressources et
echo    le fichier de définition. Par exemple vous pouvez décider de lui donner les
echo    sources C et H. Quand KbdUTool déclare ne pas pouvoir ouvrir un fichier pour
echo    le récrire [en anglais il affiche   NOM.EXTENSION : can’t open for write.],
echo    cela veut dire qu’il a gardé cette source telle que vous l’avez éditée.
echo.
)
goto :eof
:: Enlève l’attribut 'lecture seule' pour rendre les sources de nouveau modifiables :
:unlocksources
if exist %name%.C   attrib -R %name%.C
if exist %name%.H   attrib -R %name%.H
if exist %name%.RC  attrib -R %name%.RC
if exist %name%.DEF attrib -R %name%.DEF
if %nbroa% neq 0 (
	if %nbroa% equ 1 (
echo  J’ai enlevé l’attribut 'lecture seule' de la source où je l’avais mis,
echo  afin que cette source soit de nouveau modifiable.
	) else (
echo  J’ai enlevé l’attribut 'lecture seule' des %nbroa% sources où je l’avais mis,
echo  afin que toutes les sources soient de nouveau modifiables.
	)
)
goto :eof

:: ######____INSTALLATION AVEC PILOTES AD HOC____###############################
:freshen
color b1
call :allfilecheck
echo.&echo.&echo.
echo                   C O M P I L I N S T A L L A T I O N   
echo.&echo.
if "%allfiles%" equ "yes" (
echo    Je vais vous aider à installer la disposition de clavier %name%
	if defined projectname (
echo    qui fait partie du projet %projectname%,
	)
echo    à partir de ses sources qui se trouvent auprès de moi.
echo.
echo    Dans le dossier où je suis il y a tout ce qu’il faut, les sources et aussi
echo    l’installateur fourni par le Microsoft Keyboard Layout Creator [gratuit]
echo    à la fois pour la disposition %name% et pour l’architecture %bit% bit
echo    qui est celle de votre ordinateur.
echo.
echo    Si installer la disposition %name% est ce que vous souhaitez faire,
echo    confirmez-le moi s.v.p. en appuyant sur O avant d’appuyer sur Entrée.
echo.
echo    Dans le cas contraire, je ferai afficher le menu principal, par lequel
echo    vous pourrez aussi me quitter, quand vous aurez appuyé sur Entrée.
echo.
echo    Dans ce cas aussi je vais inscrire votre choix dans votre profil afin
echo    d’aller droit au menu la prochaine fois.
echo.&echo.
	set installconfirm=
	set /p installconfirm= .            Oui / Non ?  
	if defined installconfirm (
		if /i "%installconfirm:~,1%" equ "o" goto installahead
	)
	set adhoc=non
	call :saveuserprofile
	goto menu
)
if "%allfiles%" equ "nomatter" (
color a1
echo.&echo.&echo.&echo.
echo       La disposition %name% dont les sources se trouvent autour de moi
echo.
echo                  est déjà installée sur votre ordinateur.
echo.&echo.
echo     ^>  Si vous avez modifié ces sources et que vous souhaitez tester
echo        vos modifications, je vous conseille d’utiliser la rubrique TEST.
echo.&echo.&echo.&echo.&echo.
echo                  Pour aller à la rubrique TEST saisissez T.
echo                  Pour retourner au menu principal saisissez M.
echo                  Pour afficher le menu de l’aide saisissez A ou ?.
echo.
set option=
set /p option= .                     Votre choix : 
if defined option (
	if /i "%option:~,1%" equ "a" goto help
	if /i "%option:~,1%" equ "m" goto menu
	if /i "%option:~,1%" equ "t" goto test
	if    "%option:~,1%" equ "?" goto help
	goto menu
)
if "%allfiles%" equ "no" (

)
goto menu

:installahead
set compilindir="installation de %name% sur cet ordinateur %bit% bit"
mkdir %compilindir%
echo  J’ai créé le dossier %compilindir%.
echo.
:: Passe les sources en lecture seule pour qu’elles soient conservées :
call :locksources
:: Fait compiler le pilote pour ordinateurs 32 bit :
if "%machine%" equ "i386" (
	:: 'i386'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
echo.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
	%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -x %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote pour votre ordinateur,
echo.
	mkdir %compilindir%\i386
	move %name%.dll %compilindir%\i386\%name%.dll
echo  et je l’ai emballé dans le dossier.
echo.&echo.
	goto addmsi
)
:: Fait compiler le pilote principal pour ordinateurs 64 bit :
:: Pour AMD et Intel toutes architectures 64 bit sauf Itanium :
if "%machine%" equ "amd64" (
	:: 'amd64'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
	%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -m %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote principal pour votre ordinateur,
echo.
	mkdir %compilindir%\amd64
	move %name%.dll %compilindir%\amd64\%name%.dll
echo  et je l’ai emballé dans le dossier.
echo.&echo.
	goto wow64
)
:: Pour Intel Itanium Architecture :
if "%machine%" equ "ia64" (
	:: 'ia64'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
	if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
	%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -i %name%.klc
echo.&echo.
	if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote principal pour votre ordinateur,
echo.
	mkdir %compilindir%\ia64
	move %name%.dll %compilindir%\ia64\%name%.dll
echo  et je l’ai emballé dans le dossier.
echo.&echo.
)
:: Ajoute le pilote auxiliaire pour applications 32 bit :
:wow64
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -o %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote auxiliaire pour votre ordinateur,
echo.
mkdir %compilindir%\wow64
move %name%.dll %compilindir%\wow64\%name%.dll
echo  et je l’ai emballé dans le dossier.
echo.&echo.
:: Copie l’installateur approprié vers le dossier d’installation :
:addmsi
copy %name%\%name%_%machine%.msi  %compilindir%\%name%_%machine%.msi
echo  J’ai ajouté l’installateur que j’ai copié dans le dossier %name%.

:: Enlève l’attribut 'lecture seule' pour rendre les sources de nouveau modifiables :
call :unlocksources
:: Lance l’installation sur demande :
echo.
echo    J’ai préparé ce qu’il faut. Tout est prêt à installer.
echo.
echo     ^>  Souhaitez-vous que je lance l’installation ?
echo.
echo    Pour dire oui appuyez sur Entrée.
echo    Sinon tapez d’abord une lettre puis refermez-moi par Entrée.
echo.
set okinstall=
set /p okinstall= .   
if defined okinstall goto eof
:: Installation :
call %compilindir%\%name%_%machine%.msi
:: Message de confirmation :
echo.
echo    J’ai lancé l’installation de la disposition %name%.
echo.
echo    Vous pouvez faire autre chose le temps que Windows crée un point de
echo    restauration système comme prévu avant l’installation de tout nouveau
echo    logiciel, ne serait-ce qu’un pilote de disposition de clavier.
echo.
echo    Quand ce sera terminé, vous verrez sur la barre des tâches qu’un message
echo    s’est ouvert. Faites-le afficher et fermez-le après en avoir pris lecture.
echo.&echo.&echo.&echo.&echo.&echo.
echo         Bonne utilisation, et à bientôt.   (Refermez-moi par une touche.)
echo.&echo.&echo.
pause >nul
goto eof

:: ######____SOURCES____########################################################
:sources
set cbg=a&set cfg=0
color %cbg%%cfg%
echo.&echo.&echo.&echo.
echo                   O B T E N I R   L E S   S O U R C E S
echo.
echo    Pour chaque source KLC que vous me donnez vous obtiendrez 4 fichiers,
echo    dont 2 sources en langage C, un fichier ressources et un fichier de
echo    définition de module nécessaire pour la phase de compilation.
echo.
echo    Ces fichiers seront générés par un utilitaire inclus dans le MSKLC :
echo    le Keyboard Table Generation Tool (Unicode), version 3.40, bref KbdUTool.
echo    L’ancien KbdTool a été mis à niveau par Microsoft pour le support d’Unicode.
echo.
echo    Quand le KbdUTool génère un pilote, il commence toujours par générer ces
echo    mêmes fichiers, sauf qu’une fois que le pilote est fait il les efface. Mais
echo    il contient une commande lui permettant de les générer pour l’utilisateur.
echo.
echo    Si vous avez déjà des sources et que vous en laissez auprès de moi qui
echo    portent le nom d’une disposition dont je vais m’occuper, je les protège
echo    contre la réécriture et les fais prendre pleinement en compte. Ainsi je
echo    peux vous aider à compléter vos sources, par exemple avec un fichier DEF.
echo.
echo    Ma routine de génération des sources ne prévoit pas de surdossier projet.
echo    Ainsi les sources restent mieux accessibles pour vous -- et aussi pour moi.
echo.
echo    Pour continuer appuyez sur Entrée. Faites précéder de ? ou A pour l’aide.
set sourcesres=
set /p sourcesres= .  [Continuer] / A[ide] / M[enu principal] : 
if not defined sourcesres goto sourcesresume else (
	if "!sourcesres:~,1!" equ "a" goto help
	if "!sourcesres:~,1!" equ "m" goto menu
	if "!sourcesres:~,1!" equ "?" goto help
)
:sourcesresume
:: Contrôle de présence du MSKLC :
call :MSKLCcheck
if "%MSKLCava%" equ "no" goto MSKLC

:: Gestion des noms :
echo.&echo.
call :names
if "%helpreq%" equ "yes" set helpreq=no& goto help
:: Contrôle de présence des sources KLC :
call :klcavacheck
if "%klcavaok%" equ "no" (
	color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo               Il me manque une ou plusieurs sources KLC,
echo.
echo     que je dois présenter au KbdUTool pour qu’il puisse fonctionner.
echo.&echo.
echo     ^>  Si vous ne les avez sous la main, le MSKLC va vous en faire.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
pause
goto sources
)
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     ^>  Je suis maintenant prêt à déclencher la génération des sources.
echo        J’attends votre feu vert. Pour me lancer appuyez sur une touche.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
pause >nul
:: Initialise la boucle pour multiprojets (marche aussi pour un monoprojet) :
set /a cycle= 0 & set /a totnbroa= 0

:: Met à jour le nom et lance la routine :
:sourcesnext
set name=!entry[%cycle%][0]!
echo.
echo  C’est la disposition !name! dont je vais m’occuper maintenant.

:: Met en lecture seule les éventuelles sources présentes pour les conserver :
call :locksources
:: Produit les sources d’origine en langage C et les met à disposition :
call :generatesources
goto sourcesfinish
:generatesources
rem  Cette routine est utilisée par ailleurs.
echo.
echo  Je vais maintenant demander à KbdUTool de générer les sources de %name%.
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -s %name%.klc
echo  KbdUTool a terminé de générer les sources de %name%.
mkdir %name%_sources_origine
echo  J’ai créé le dossier "%name%_sources_origine"
copy %name%.klc %name%_sources_origine\%name%.klc
copy %name%.C   %name%_sources_origine\%name%.C  
copy %name%.H   %name%_sources_origine\%name%.H  
copy %name%.RC  %name%_sources_origine\%name%.RC 
copy %name%.DEF %name%_sources_origine\%name%.DEF
echo  et j’ai copié toutes les sources vers ce dossier.
goto :eof

:: Enlève l’attribut lecture seule des éventuelles sources présentes et les compte :
:sourcesfinish
set /a totnbroa=%totnbroa%+%nbroa%
call :unlocksources

:: Regarde si tout est fait :
set /a cycle+=1
if %cycle% equ %number% (
echo  J’ai fait passer toutes les dispositions du projet.
	goto sourcesend
) else (
	set /a rest=%number%-%cycle%
echo  Le projet contient encore d’autres dispositions, il en reste !rest! à faire.
echo  Je passe à la suivante.
	goto sourcesnext
)
:: Message final sources :
:sourcesend
color a1
echo.&echo.&echo.&echo.
echo                     Les sources sont maintenant au complet
echo.
echo                       et attendent que vous les modifiez.
echo.&echo.
if %totnbroa% equ 0 (
echo             Comme vous ne m’aviez apporté aucune source au départ,
echo.
echo                       je n’en ai eu aucune à conserver.
echo.
echo                       Les sources sont toutes fraîches.
) else (
echo            Au départ vous m’aviez montré %totnbroa% fichiers non-KLC.
echo.
echo                     Je les ai tous précieusement conservés.
echo.
echo              Vous les retrouverez au nombre des sources présentes.
)
echo.&echo.
echo             Je vous souhaite bon courage pour la personnalisation.
echo.&echo.&echo.&echo.
echo     ^>  Appuyez sur une touche pour me refermer.
echo.&echo.
pause >nul
goto eof

:: ######____TESTER____########################################################
:test
set cbg=b&set cfg=1
color %cbg%%cfg%
echo.&echo.&echo.
echo                   T E S T E R   U N E   D I S P O S I T I O N
echo.&echo.
echo    Avant de faire compiler et de mettre en place le%pls% pilote%pls% à tester, je
echo    récupère le%pls% pilote%pls% d’origine afin de pouvoir le restaurer sur demande.
echo.
:: Contrôle de présence du MSKLC :
call :MSKLCcheck
if "%MSKLCava%" equ "no" goto MSKLC

:: Gestion des noms :
call :names
if "%helpreq%" equ "yes" set helpreq=no& goto help

:: Contrôle de présence des pilotes installés concernés :
call :driver%bit%check
if "%driverok%" equ "no" (
	color cf
echo.&echo.&echo.&echo.&echo.
echo        Il manque un ou plusieurs pilotes parmi les pilotes installés.
echo.
echo         Cela signifie que les dispositions concernées par les tests
echo                    ne sont pas encore toutes installées.
echo.&echo.
echo    Si vous n’avez sous la main ce qu’il faut, le MSKLC va faire ça pour vous.
echo.&echo.&echo.&echo.
echo     ^>  Quand les pilotes seront installés, appuyez sur Entrée pour reprendre.
echo.
echo    Pour l’aide faites précéder de ? ou A, ou de M pour le menu principal.
echo.&echo.&echo.
	set testres=
	set /p testres= .  [Continuer] / A[ide] / M[enu principal] : 
	if not defined testres goto test else (
		if "!testres:~,1!" equ "a" goto help
		if "!testres:~,1!" equ "m" goto menu
		if "!testres:~,1!" equ "?" goto help
	)
)
:: Contrôle de présence des sources KLC :
call :klcavacheck
if "%klcavaok%" equ "no" (
	color cf
echo.&echo.&echo.&echo.&echo.&echo.
echo               Il me manque une ou plusieurs sources KLC,
echo.
echo     que je dois présenter au KbdUTool pour qu’il puisse fonctionner.
echo.&echo.
echo     ^>  Si vous ne les avez sous la main, le MSKLC va vous en faire.
echo.&echo.&echo.&echo.
echo     ^>  Quand les sources KLC seront là, appuyez sur Entrée pour reprendre.
echo.
echo    Pour l’aide faites précéder de ? ou A, ou de M pour le menu principal.
echo.&echo.&echo.
	set testres=
	set /p testres= .  [Continuer] / A[ide] / M[enu principal] : 
	if not defined testres goto test else (
		if "!testres:~,1!" equ "a" goto help
		if "!testres:~,1!" equ "m" goto menu
		if "!testres:~,1!" equ "?" goto help
	)
)
:: Contrôle de présence du header commun si défini et de ce qui va avec :
call :cmhavacheck
if "%cmhavaok%" neq "yes" (
	color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo              Il y a un problème avec la source en-tête commune.
echo.&echo.&echo.
echo    Vérifiez s.v.p. si tout se tient, ou mettez à jour les propriétés du projet.
echo.&echo.&echo.&echo.&echo.&echo.&echo.
pause & goto test
)
:: Définit l’identifiant chronologique autotriable :
if "%TIME:~,1%" equ " " (
set timestamp=%DATE:~6,4%-%DATE:~3,2%-%DATE:~,2%__0%TIME:~1,1%.%TIME:~3,2%.%TIME:~6,2%
) else (
set timestamp=%DATE:~6,4%-%DATE:~3,2%-%DATE:~,2%__%TIME:~,2%.%TIME:~3,2%.%TIME:~6,2%
)
:: Permet de personnaliser le dossier archivable du test :
echo.&echo.&echo.&echo.&echo.
echo     ^>  Souhaitez-vous ajouter une information dans le nom du dossier
echo        archivable de ce test ?
echo.&echo.
echo    Ce dossier portera, en plus du nom de la disposition, un identifiant
echo    autotriable, dont l’ordre alphabétique coïncide avec l’ordre chronologique.
echo.
echo    Cet identifiant se compose de la date du jour au format inversé avec tirets,
echo    et de l’heure à la seconde près pour éviter toute ambiguïté.
echo.
echo         Les séparateurs de l’heure seront des points, parce que
echo         les noms de fichier doivent être exempts de deux-points.
echo.
echo    Pour ce test, cet identifiant est %timestamp%
echo.
echo    L’information que vous ajouterez éventuellement sera accolée après
echo    %timestamp%_  (après un tiret bas).
echo.
echo    Mais vous pouvez sauter cette étape en appuyant seulement sur Entrée.
echo    Le nom de dossier complet sera alors %name%_test_%timestamp%.
echo.&echo.
set testinfo=
set /p testinfo=  Complément d’information facultatif : 
if defined testinfo (
if "%testinfo%" equ "?" goto help
set id=%timestamp%_%testinfo%
) else (
set id=%timestamp%
)
:: Initialise la boucle pour multiprojets (marche aussi pour un monoprojet) :
if defined projectname (
	set testdirproject="%projectname%_test_%id%"
	mkdir !testdirproject!
echo  J’ai créé le dossier !testdirproject!.
)
set /a cycle=0 & set /a totnbroa=0

:: Met à jour le nom et commence la routine :
:testnext
set name=!entry[%cycle%][0]!
echo  C’est la disposition !name! dont je vais m’occuper maintenant.

:: Partie archivage des anciens pilotes (uniquement d’origine, à ce nom) :
if defined RestorePath_%name% (
	goto testahead
) else (
echo  Je vais archiver le%spl% pilote%spl% car c’est le premier test de %name%.
)
:: Crée le log de restauration :
if not exist %ProgramData%\creadispo\Log_restore.txt (
	echo Dispositions de clavier archivées pour restauration :> %ProgramData%\creadispo\Log_restore.txt
	echo >> %ProgramData%\creadispo\Log_restore.txt
echo  J’ai créé le fichier log de restauration.
echo  Il se trouve à l’adresse %ProgramData%\creadispo\Log_restore.txt
)
:: Crée et référence le répertoire :
mkdir %ProgramData%\creadispo\%name%_ANCIEN
echo set RestorePath_%name%=%ProgramData%\creadispo\%name%_ANCIEN>> %ProgramData%\creadispo\globaldata.txt
echo set RestorePathDefaultName=%name%>> %ProgramData%\creadispo\globaldata.txt
echo  J’ai créé un dossier pour %ard%ancien%pls% pilote%pls%,
echo  et j’ai ajouté %pps%%pls% nom%pls% dans ma base de données.

:: Archive l’ancien pilote principal :
mkdir %ProgramData%\creadispo\%name%_ANCIEN\%machine%
move C:\Windows\System32\%name%.dll %ProgramData%\creadispo\%name%_ANCIEN\%machine%\%name%.dll

:: Remet une copie temporaire du pilote 32 bit dans le dossier système :
copy %ProgramData%\creadispo\%name%_ANCIEN\%machine%\%name%.dll C:\Windows\System32\%name%.dll

:: Archive l’ancien pilote auxiliaire :
if "%machine%" equ "i386" (
echo  J’ai archivé et emballé l’ancien pilote,
echo  et j’en ai remis une copie dans le dossier système au cas où.
) else (
	mkdir %ProgramData%\creadispo\%name%_ANCIEN\wow64
	move C:\Windows\SysWOW64\%name%.dll %ProgramData%\creadispo\%name%_ANCIEN\wow64\%name%.dll
	:: Remet une copie temporaire du pilote auxiliaire dans le dossier système :
	copy %ProgramData%\creadispo\%name%_ANCIEN\wow64\%name%.dll C:\Windows\SysWOW64\%name%.dll
echo  J’ai archivé et emballé l’ancien pilote principal,
echo  J’en ai fait de même pour l’ancien pilote auxiliaire,
echo  et j’ai remis une copie de chacun dans les dossiers système au cas où.
)
:: L’inscrit au log de restauration :
echo %name% archivée le %DATE% à %TIME%> %ProgramData%\creadispo\Log_restore.txt
echo  Je l’ai aussi inscrit au log de restauration.

:: Ajoute un fichier texte :
echo Le contenu de ce dossier permet de restaurer la disposition %name%> %ProgramData%\creadispo\%name%_ANCIEN\Note.txt
echo à l’état où elle se trouvait avant le test %name%_%timestamp%.>> %ProgramData%\creadispo\%name%_ANCIEN\Note.txt
echo.&echo.&echo.&echo.&echo.
echo    J’ai fini d’archiver les anciens pilotes. Je pourrai les restaurer à
echo    votre demande. Dans ce cas choisissez dans le menu l’option Restauration.
echo.&echo.&echo.&echo.&echo.

:: Partie test :
:testahead
:: Met en lecture seule les éventuelles sources présentes pour les conserver :
call :locksources
:: Constitue le dossier archivable des sources et du/des pilote(s) testé(s) :
set testdirname="%name%_test_%id%"
mkdir %testdirname%
echo  J’ai créé le dossier %testdirname%.
if exist %cmheader%.H copy %cmheader%.H %testdirname%\%cmheader%.H
if exist %name%.C     copy %name%.C     %testdirname%\%name%.C
if exist %name%.H     copy %name%.H     %testdirname%\%name%.H
if exist %name%.RC    copy %name%.RC    %testdirname%\%name%.RC
if exist %name%.DEF   copy %name%.DEF   %testdirname%\%name%.DEF
echo  J’y ai placé une copie de chaque source présente sauf la source KLC.

:: Bifurque vers les modules appropriés :
if /i "%machine%" equ "i386"  goto i386
if /i "%machine%" equ "amd64" goto amd64
if /i "%machine%" equ "ia64"  goto ia64

:: Compile le pilote pour les machines 32 bit :
:i386
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -x %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
mkdir %testdirname%\i386
copy %name%.dll %testdirname%\i386\%name%.dll
copy %name%.dll %testdirname%\i386\%name%.bak
move %name%.dll C:\Windows\System32\%name%.dll
echo  J’ai fait compiler le pilote 32 bit et l’ai placé dans le dossier système
echo  C:\Windows\System32  en remplacement de celui qui s’y trouvait. Et j’ai mis
echo  deux copies dans le dossier%testdirname%, dont
echo  une en .bak pour qu’elle survive aux restaurations du système
echo  (pour l’éventualité qu’il y en aura une).
goto finishtest

:: Compile le pilote 64 bit pour les machines 64 bit sauf Intel Itanium :
:amd64
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -m %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
mkdir %testdirname%\amd64
copy %name%.dll %testdirname%\amd64\%name%.dll
copy %name%.dll %testdirname%\amd64\%name%.bak
move %name%.dll C:\Windows\System32\%name%.dll
echo  J’ai fait compiler le pilote 64 bit et l’ai placé dans le dossier système
echo  C:\Windows\System32 (exact)  en remplacement de celui qui s’y trouvait.
goto wow64

:: Compile le pilote 64 bit pour les machines Intel Itanium :
:ia64test
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -i %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
mkdir %testdirname%\ia64
copy %name%.dll %testdirname%\ia64\%name%.dll
copy %name%.dll %testdirname%\ia64\%name%.bak
move %name%.dll C:\Windows\System32\%name%.dll
echo  J’ai fait compiler le pilote 64 bit et l’ai placé dans le dossier système
echo  C:\Windows\System32 (exact)  en remplacement de celui qui s’y trouvait.
goto wow64

:: Compile le pilote pour les applications 32 bit dans les machines 64 bit :
:wow64
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -o %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
mkdir %testdirname%\wow64
copy %name%.dll %testdirname%\wow64\%name%.dll
copy %name%.dll %testdirname%\wow64\%name%.bak
move %name%.dll C:\Windows\SysWOW64\%name%.dll
echo  J’ai fait compiler le pilote auxiliaire pour applications 32 bit et l’ai
echo  mis dans le dossier système  C:\Windows\SysWOW64  à la place de l’ancien.
echo  J’ai toujours aussi placé deux copies de chaque pilote dans le dossier
echo  %testdirname%, dont une en .bak pour qu’elle survive
echo  aux restaurations du système (pour l’éventualité qu’il y en aura une).

:: Range le dossier dans le surdossier :
:finishtest
if exist %projectname%_test_%id% (
	move %testdirname% %projectname%_test_%id%
echo  J’ai rangé le dossier %testdirname% dans le surdossier
echo  %projectname%_test_%id% du projet.
)
:: Enlève l’attribut 'lecture seule' pour rendre les sources de nouveau modifiables :
set /a totnbroa=%totnbroa%+%nbroa%
call :unlocksources

:: Regarde si tout est fait :
set /a cycle+=1
if %cycle%==%number% (
echo  J’ai fait passer toutes les dispositions du projet.
	goto testend
) else (
	set /a rest=%number%-%cycle%
echo  Le projet contient encore d’autres dispositions, il en reste !rest! à faire.
echo  Je passe à la suivante.
	goto testnext
)
:: Message final test :
:testend
set /a completed=%number%*4-%totnbroa%
color a1
echo.&echo.&echo.
echo           J’ai fait prendre en compte tous les %totnbroa% fichiers
if defined cmheader (
echo        que vous m’aviez donnés en plus de la source commune %cmheader%.
) else (
echo                           que vous m’aviez donnés.
)
echo.
if %completed% neq 0 (
echo                J’en ai ajouté %completed% pour compléter vos archives.
) else (
echo.
)
echo.&echo.
echo    Ce que j’ai fait faire attend maintenant le prochain démarrage de votre
echo    ordinateur pour être admis dans la mémoire vive. C’est à ce moment-là
echo    que vous pourrez commencer à faire tous les tests que vous prévoyez.
echo.
echo     ^>  ATTENTION :  Avant de quitter la présente session,
echo                      assurez-vous par précaution que la disposition
echo                      qui actuellement est définie comme clavier
echo                      associé à la langue d’entrée par défaut,
echo                      ne soit concernée par aucun changement de pilote
echo                      pour cause de tests.
echo.&echo.&echo.
if "%sound%" equ "oui" if not defined soundpref call %soundfile% else call %soundpref%
color cf
call :milliwait
color fc
call :milliwait & call :milliwait
color a1
echo    Pour me refermer, appuyez sur une touche…
echo.&echo.
pause >nul
goto eof

:: Message d’échec :
:failure
call :unlocksources
color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                Une erreur s’est produite lors de la compilation.
echo.
echo                   KbdUTool n’a pu produire le pilote demandé,
echo.
echo                      pour les raisons indiquées ci-dessus.
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo    Appuyez sur Entrée pour me changer de couleur puis me relancer.
echo.&echo.&echo.
set testres=
set /p testres= .  [Réessayer] / A[ide] / M[enu principal] / T[est] : 
if defined testres (
	if /i "!testres:~,1!" equ "a" goto help
	if /i "!testres:~,1!" equ "m" goto menu
	if /i "!testres:~,1!" equ "t" goto test
	if    "!testres:~,1!" equ "?" goto help
)
color f1
set testres=
set /p testres= .  [Réessayer] / A[ide] / M[enu principal] / T[est] : 
if defined testres (
	if /i "!testres:~,1!" equ "a" goto help
	if /i "!testres:~,1!" equ "m" goto menu
	if /i "!testres:~,1!" equ "t" goto test
	if    "!testres:~,1!" equ "?" goto help
)
color f0
set testres=
set /p testres= .  [Réessayer] / A[ide] / M[enu principal] / T[est] : 
if defined testres (
	if /i "!testres:~,1!" equ "a" goto help
	if /i "!testres:~,1!" equ "m" goto menu
	if /i "!testres:~,1!" equ "t" goto test
	if    "!testres:~,1!" equ "?" goto help
)
goto test

:: ######____RESTAURER LES PILOTES D’ORIGINE____#################################
:restore
color f5
echo.&echo.&echo.
echo         R E S T A U R A T I O N   D E   D I S P O S I T I O N
echo.
echo    Cette fonctionnalité restaure une disposition à l’état où elle se
echo    trouvait avant que des modifications soient testées sur elle avec
echo    mon concours. Les états antérieurs, dont je n’étais pas au courant,
echo    sont par contre au-delà de mes possibilités. En l’absence d’autres
echo    moyens, seule une restauration du système peut -- éventuellement --
echo    vous les restituer.
echo.
echo    La restauration de pilote que je peux faire vous évite au contraire
echo    d’avoir recours à la restauration du système par Windows si c’est
echo    uniquement pour une disposition de clavier.
echo.
if not exist RestorePathDefaultName (
echo.&echo.
echo    Actuellement je ne peux encore restaurer aucune disposition, car
echo    jusqu’à présent je n’ai pas eu l’occasion d’en archiver à cet effet.
echo.&echo.&echo.
echo     ^>  Pour retourner au menu, appuyez sur une touche…
echo.
pause >nul
goto menu
)
echo     ^>  Souhaitez-vous restaurer la disposition %RestorePathDefaultName% ?
echo.
echo    Pour restaurer une autre disposition, merci de bien vouloir entrer
echo    son nom et ensuite appuyer sur Entrée.
echo.
echo    S’il se trouve que c’est bien %RestorePathDefaultName% que vous souhaitez restaurer,
echo    il vous suffit d’appuyer simplement sur Entrée :
echo.
set restorewhich=
:restorewhichprompt
set /p restorewhich= .  %RestorePathDefaultName%, ou autre disposition : 
if defined %restorewhich% (
	if "%restorewhich%" equ "?" goto help
	if exist RestorePath%restorewhich% (
		set name=%restorewhich%
	) else (
echo.
echo    Je suis désolé, je suis dans l’incapacité de restaurer la disposition
echo    %restorewhich%, car elle ne se trouve pas dans ma base de données de
echo    restauration. Y aurait-il une méprise, et voudriez-vous ressaisir
echo    un autre nom ?  Si oui, je vous invite à le faire ci-dessous.
echo    Autrement, au cas où vous vouliez restaurer la disposition %RestorePathDefaultName%,
echo    merci d’appuyer simplement sur Entrée :
echo.
goto restorewhichprompt
	)
) else (
	set name=%RestorePathDefaultName%
)
echo.
echo    Très bien, je vais maintenant restaurer la disposition %name%.
echo    Voici la note qui s’y trouve jointe dans ma base de données de restauration ;
echo    appuyez sur une touche pour que je la fasse afficher.
echo    J’attendrai que vous en ayez pris connaissance.
pause >nul
call %ProgramData%\creadispo\%name%_ANCIEN\Note.txt
echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     ^>  Pour annuler, tapez A suivi d’Entrée. Pour valider, juste Entrée.
echo.&echo.&echo.&echo.&echo.&echo.&echo.
set restorecancel=
set /p restorecancel= .  
if defined restorecancel (
	if "%restorecancel:~,1%" equ "a" goto :eof
)
echo.
echo    Je procède maintenant à la restauration de la disposition %name%.
echo.
:: Crée une copie de sauvegarde du pilote principal à restaurer :
mkdir %ProgramData%\creadispo\%name%_ANCIEN\Copie
mkdir %ProgramData%\creadispo\%name%_ANCIEN\Copie\%machine%
copy %ProgramData%\creadispo\%name%_ANCIEN\%machine%\%name%.dll  %ProgramData%\creadispo\%name%_ANCIEN\Copie\%machine%\%name%.dll
echo  J’ai créé une copie de sauvegarde du pilote principal à restaurer.

:: Restaure le pilote principal :
move %ProgramData%\creadispo\%name%_ANCIEN\%machine%\%name%.dll  C:\Windows\System32\%name%.dll
echo  J’ai restauré le pilote principal.

:: Pour machines 64 bit :
if "%machine%" neq "i386" (
	:: Crée une copie de sauvegarde du pilote auxiliaire restauré :
	mkdir %ProgramData%\creadispo\%name%_ANCIEN\Copie\wow64
	copy %ProgramData%\creadispo\%name%_ANCIEN\wow64\%name%.dll  %ProgramData%\creadispo\%name%_ANCIEN\Copie\wow64\%name%.dll
	echo  J’ai créé une copie de sauvegarde du pilote auxiliaire à restaurer.
	
	:: Restaure le pilote auxiliaire :
	move %ProgramData%\creadispo\%name%_ANCIEN\wow64\%name%.dll  C:\Windows\SysWOW64\%name%.dll
	echo  J’ai restauré le pilote auxiliaire.
)
:: Inscrit la restauration au log de restauration :
echo %name% restaurée le %DATE% à %TIME%> %ProgramData%\creadispo\Log_restore.txt
echo  J’ai inscrit la restauration au log de restauration.
echo.&echo.&echo.&echo.&echo.&echo.&echo.
color a5
echo    J’ai fini de restaurer la disposition %name%.
echo.
echo     ^>  Vous pouvez maintenant fermer et rouvrir votre session
echo        pour activer le%pls% pilote%pls% restauré%pls%.
echo.&echo.&echo.&echo.&echo.
echo    Pour me refermer, appuyez sur une touche.
echo.
color f2
pause >nul
goto eof

:: ######____VERSION____########################################################
:version
color e1
echo.&echo.&echo.
echo             S O R T I R   U N E   V E R S I O N   F I N I E
echo.&echo.
echo    Ici je ferai compiler tous les pilotes d’une version distribuable,
echo    et je les emballerai avec les fichiers d’installation issus du MSKLC.
echo.
echo    Je préparerai pour chaque disposition de clavier :
echo.
echo     +  un dossier pour l’installer            [pack d’installation]
echo     +  un dossier pour recompiler les pilotes [pack de compilinstallation]
echo.
if "%aready%" equ "oui" (
echo     +  un dossier archivable avec les sources et les pilotes
) else (
echo.
)
echo.&echo.
if "%arqtnok%" equ "non" (
echo     ^>  Souhaitez-vous avoir aussi un dossier conçu pour être sauvegardé ?
echo        Il contiendra :  +  un dossier de sources ;
echo                         +  un dossier d’installation ;
echo                         +  des copies des pilotes avec l’extension .bak.
echo                         +  une copie du script creadispo avec l’extension .bak.
echo.
echo    Pour ajouter ce dossier, entrez A ou O suivi d’Entrée ; sinon juste Entrée.
echo.
	set aready=non
	set arqtn=
	set /p arqtn= .  Oui je souhaite obtenir aussi le dossier archivable : 
	if not defined arqtn set arqtnok=non else (
		if "!arqtn:~,1!" equ "a" set aready=oui&& set arqtnok=oui
		if "!arqtn:~,1!" equ "o" set aready=oui&& set arqtnok=oui
	)
call :saveuserprofile
echo.&echo.
echo    J’ai bien noté que votre réponse est :  !aready!  au dossier archivable.
echo    Vous pouvez la modifier dans les Préférences, rubrique Dossier archivable.
echo.&echo.
) else (
echo.&echo.
)
:: Contrôle de présence du MSKLC :
call :MSKLCcheck
if "%MSKLCava%" equ "no" goto MSKLC

:: Gestion des noms :
call :names
if "%helpreq%" equ "yes" set helpreq=no& goto help
:: Contrôle de présence des sources KLC :
call :klcavacheck
if "%klcavaok%" equ "yes" goto vncheck else (
	color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo               Il me manque une ou plusieurs sources KLC,
echo.
echo     que je dois présenter au KbdUTool pour qu’il puisse fonctionner.
echo.&echo.
echo     ^>  Si vous ne les avez sous la main, le MSKLC va vous en faire.
echo.&echo.&echo.&echo.
echo     ^>  Quand les sources KLC seront là, appuyez sur Entrée pour reprendre.
echo.
echo    Pour l’aide faites précéder de ? ou A, ou de M pour le menu principal.
echo.&echo.&echo.
	set versionres=
	set /p versionres= .  [Continuer] / A[ide] / M[enu principal] : 
	if not defined versionres goto version else (
		if "!versionres:~,1!" equ "a" goto help
		if "!versionres:~,1!" equ "m" goto menu
		if "!versionres:~,1!" equ "?" goto help
	)
)
:vncheck
:: Contrôle de présence du header commun si défini et de ce qui va avec :
call :cmhavacheck
:: Contrôle de présence des installateurs :
call :msiavacheck
if "%cmhavaok%" equ "yes" ( if "%installeravaok%" equ "yes" (
echo  J’ai fini de vérifier que des fichiers essentiels soient bien présents.
)) else (
	color cf
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo               Je suis navré de ne pouvoir faire cette version.
echo.
echo              Un ou plusieurs éléments importants sont manquants.
echo.&echo.
echo             Je vous remercie de bien vouloir faire le nécessaire.
echo.&echo.&echo.&echo.
echo     ^>  Quand tout sera prêt, appuyez sur Entrée pour reprendre.
echo.
echo    Pour l’aide faites précéder de ? ou A, ou de M pour le menu principal.
echo.&echo.&echo.
	set versionres=
	set /p versionres= .  [Continuer] / A[ide] / M[enu principal] : 
	if not defined versionres goto version else (
		if "!versionres:~,1!" equ "a" goto help
		if "!versionres:~,1!" equ "m" goto menu
		if "!versionres:~,1!" equ "?" goto help
	goto version
	)
)
:: Définit l’identifiant chronologique autotriable :
if "%TIME:~,1%" equ " " (
set timestamp=%DATE:~6,4%-%DATE:~3,2%-%DATE:~,2%__0%TIME:~1,1%.%TIME:~3,2%.%TIME:~6,2%
) else (
set timestamp=%DATE:~6,4%-%DATE:~3,2%-%DATE:~,2%__%TIME:~,2%.%TIME:~3,2%.%TIME:~6,2%
)
:: Renseigne le numéro de version :
:versioning
echo.&echo.&echo.&echo.&echo.
echo     ^>  De quelle version s’agit-il s.v.p. ?
echo.
echo    Cette information servira uniquement à marquer les dossiers à créer.
echo    Pour les pilotes, veuillez s.v.p. modifier le%npls% fichier%npls% .RC,
echo    aux lignes 3 et 4 ainsi qu’aux lignes 17 et 23 :
echo.
echo     +  Le MSKLC remet à 1.0 le numéro de version à chaque enregistrement.
echo.
echo     +  Le KbdUTool utilise son propre numéro de version pour renseigner les
echo        deux derniers des quatre champs usuels : "3.40", d’où "1,0,3,40".
echo.
echo     +  Dans le cas d’une disposition de clavier, cette version de FICHIER
echo        est celle des pilotes, tandis que le PRODUIT inclut la documentation.
echo        En pratique les deux numéros de version restent normalement synchros.
echo.
echo     +  Les valeurs numériques aux lignes 3-4 et les chaînes lignes 17 et 23
echo        devraient correspondre, sauf que les premières requièrent des virgules,
echo        tandis que les chaînes peuvent être écrites librement, aussi avec des
echo        points et sans espaces, car ceci sera repris à la lettre.
echo.
echo     +  On peut ajouter la chaîne "Comments" et modifier l’ordre.
echo                                                                [A]ide / M[enu]
set /p version= .  Cette version : 
if /i "%version%" equ "m" goto menu
if    "%version%" equ "?" goto help
echo.
:: Initialise la boucle pour multiprojets (marche aussi pour un monoprojet) :
set /a cycle=0 & set /a totnbroa=0
if not defined projectname goto versionnext
set idirproject="%projectname%_v%version%_(installation)"
mkdir %idirproject%
set comidirproject="%projectname%_v%version%_(compilinstallation)"
mkdir %comidirproject%
if "%aready%" equ "oui" (
	set bakdirproject="(a) %projectname% v%version%"
	mkdir !bakdirproject!
)
echo  J’ai créé les surdossiers de %projectname%.

:: Met à jour le nom et commence la routine :
:versionnext
call :readprojectprops
set name=!entry[%cycle%][0]!
set description=!entry[%cycle%][1]!
if defined description ( set sep= ) else ( set sep=)
echo  C’est la disposition %name% dont je vais m’occuper maintenant.

:: Met en lecture seule les éventuelles sources présentes pour les conserver :
call :locksources

:: Commence le dossier de compilinstallation contenant les sources :
set comidirname="%name%%sep%%description% v%version% compilinstallation"
mkdir %comidirname%
echo  J’ai créé le dossier %comidirname%,
copy %name%.klc %comidirname%\%name%.klc
echo  et à l’intérieur j’ai placé une copie de la source KLC %name%.klc.
set allsrc=yes
if exist %cmheader%.H ( copy %cmheader%.H %comidirname%\%cmheader%.H ) 
if exist %name%.C     ( copy %name%.C     %comidirname%\%name%.C     ) else set allsrc=no
if exist %name%.H     ( copy %name%.H     %comidirname%\%name%.H     ) else set allsrc=no
if exist %name%.RC    ( copy %name%.RC    %comidirname%\%name%.RC    ) else set allsrc=no
if exist %name%.DEF   ( copy %name%.DEF   %comidirname%\%name%.DEF   ) else set allsrc=no
if "%allsrc%" equ "yes" (
echo  J’y ai ajouté une copie de toutes les sources.
	goto versioncompile
)
:: Complète les sources manquantes :
if exist %name%_sources_origine\%name%.C if exist %name%_sources_origine\%name%.H if exist %name%_sources_origine\%name%.RC if exist %name%_sources_origine\%name%.DEF goto completesources
call :generatesources
echo  J’ai fait générer des sources pour compléter ce qui manque.
:completesources
if not exist %name%.C   copy %name%_sources_origine\%name%.C   %comidirname%\%name%.C  
if not exist %name%.H   copy %name%_sources_origine\%name%.H   %comidirname%\%name%.H  
if not exist %name%.RC  copy %name%_sources_origine\%name%.RC  %comidirname%\%name%.RC 
if not exist %name%.DEF copy %name%_sources_origine\%name%.DEF %comidirname%\%name%.DEF
echo  Les sources dans le dossier sont au complet.

:: Pack d’installation :
:versioncompile
:: Fait compiler et emballe les pilotes (avec une copie de sauvegarde) :
set idirname="%name%%sep%%description% v%version% installation"
mkdir %idirname%
echo  J’ai créé le dosssier %idirname%.

:: 'i386'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler le pilote 32 bit.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -x %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote 32 bit.
copy %name%.dll %name%.bak
echo  J’ai fait un double de sauvegarde du pilote.
mkdir %idirname%\i386
move %name%.dll %idirname%\i386\%name%.dll
move %name%.bak %idirname%\i386\%name%.bak
echo  J’ai rangé le tout dans le dossier.

:: 'amd64'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler le pilote 64 bit.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -m %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote 64 bit.
copy %name%.dll %name%.bak
echo  J’ai fait un double de sauvegarde du pilote.
mkdir %idirname%\amd64
move %name%.dll %idirname%\amd64\%name%.dll
move %name%.bak %idirname%\amd64\%name%.bak
echo  J’ai rangé le tout dans le dossier.

:: 'ia64'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler un pilote spécial.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -i %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote 64 bit pour Itanium.
copy %name%.dll %name%.bak
echo  J’ai fait un double de sauvegarde du pilote.
mkdir %idirname%\ia64
move %name%.dll %idirname%\ia64\%name%.dll
move %name%.bak %idirname%\ia64\%name%.bak
echo  J’ai rangé le tout dans le dossier.

:: 'wow64'
echo.
echo  Je vais maintenant demander à KbdUTool de compiler le pilote d’appoint.
if %nbroa% neq 0 (
echo    Quand KbdUTool ne pourra pas ouvrir une source pour la récrire,
echo    c’est parce que j’ai bloqué cette source. Donc c’est bon signe.
)
%MSKLCprofile%\bin\i386\kbdutool.exe -%enc% -v -w -o %name%.klc
echo.&echo.
if not exist %name%.dll goto failure
echo  J’ai fait compiler le pilote auxiliaire Windows On Windows (WoW)
echo  pour les programmes en 32 bit qui tournent sous 64 bit.
copy %name%.dll %name%.bak
echo  J’ai fait un double de sauvegarde du pilote.
mkdir %idirname%\wow64
move %name%.dll %idirname%\wow64\%name%.dll
move %name%.bak %idirname%\wow64\%name%.bak
echo  J’ai rangé le tout dans le dossier.

:: Copie les installateurs vers le dossier d’installation :
copy %name%\%name%_i386.msi  %idirname%\%name%_i386.msi
copy %name%\%name%_amd64.msi %idirname%\%name%_amd64.msi
copy %name%\%name%_ia64.msi  %idirname%\%name%_ia64.msi
copy %name%\setup.exe        %idirname%\setup.exe
echo  J’ai copié les installateurs vers le dossier d’installation.

:: Ajoute une note :
chdir %idirname%
echo Disposition de clavier %name%%sep%%description% v%version%> Note.txt
echo.>> Note.txt
echo Datant du %timestamp%>> Note.txt
echo.>> Note.txt
echo Cette disposition de clavier est compatible Windows 11, 10, 8.1, 8, 7, Vista,>> Note.txt
echo Server 2003, XP, 2000, et NT 4.0.>> Note.txt
echo.>> Note.txt
echo Elle est sous licence Apache 2.0.>> Note.txt
echo Visiter https://dispoclavier.com pour plus de renseignements.>> Note.txt
echo.>> Note.txt
echo Pour ajouter une disposition de clavier sur votre ordinateur,>> Note.txt
echo vous devez disposer des droits d’administrateur.>> Note.txt
echo.>> Note.txt
echo Les fichiers d’installation setup.exe et trois packs pour installateur>> Note.txt
echo Windows sont issus du MSKLC et peuvent être remplacés par des fichiers>> Note.txt
echo au même nom générés sur votre ordinateur par cet utilitaire Microsoft gratuit.>> Note.txt
echo.>> Note.txt
echo Pour une utilisation des packs d’installation téléchargés, l’accord explicite>> Note.txt
echo de l’utilisateur est demandé par Windows. Sous Windows 10 il est nécessaire de>> Note.txt
echo désactiver le blocage au préalable en ouvrant les propriétés du fichier et en>> Note.txt
echo cochant la case en bas à droite. Les versions antérieures montrent un bouton.>> Note.txt
echo.>> Note.txt
echo On peut lancer le setup.exe ou les fichiers MSI alternativement. D’entre ces>> Note.txt
echo derniers on aura le bon au premier essai en choisissant 'i386' pour une>> Note.txt
echo machine 32 bit, ou 'amd64' pour une machine 64 bit, sauf Intel Itanium qui>> Note.txt
echo est servi par le pack 'ia64'. 'amd64' est aussi pour processeurs Intel.>> Note.txt
echo.>> Note.txt
echo Les pilotes sont dans les dossiers aux mêmes désignations. Le pilote 'wow64'>> Note.txt
echo est nécessaire en plus sur les machines 64 bit pour les applications 32 bit.>> Note.txt
echo.>> Note.txt
echo La copie avec l’extension '.bak' (pour 'backup') qui se trouve à côté de>> Note.txt
echo chaque pilote de disposition, dont l’extension qui correspond est .dll pour>> Note.txt
echo Dynamic Link Library, sert à protéger ces pilotes contre la suppression>> Note.txt
echo par une procédure de restauration du système postérieure à leur compilation,>> Note.txt
echo pour le cas où ils ne seraient pas sauvegardés sur un volume externe.>> Note.txt
chdir ..
echo  J’ai ajouté une note.

:: Pack de compilinstallation (achèvement) :
:: Copie les installateurs vers le dossier de compilinstallation :
mkdir %comidirname%\%name%
copy %name%\%name%_i386.msi  %comidirname%\%name%\%name%_i386.msi
copy %name%\%name%_amd64.msi %comidirname%\%name%\%name%_amd64.msi
copy %name%\%name%_ia64.msi  %comidirname%\%name%\%name%_ia64.msi
copy %name%\setup.exe        %comidirname%\%name%\setup.exe
echo  J’ai copié les installateurs vers le dossier de compilinstallation,

:: Copie ce script vers le dossier de compilinstallation :
copy creadispo.cmd %comidirname%\creadispo.cmd
copy creadispo.cmd %comidirname%\creadispo.bak
echo  ainsi qu’une copie de moi-même et une copie de sauvegarde,

:: Ajoute un fichier des propriétés du projet :
chdir %comidirname%
call :savemainprojectprops
echo  et j’y ai généré un fichier des propriétés du projet.

:: Ajoute une note :
echo Disposition de clavier %name%%sep%%description% v%version%> Note.txt
echo.>> Note.txt
echo Datant du %timestamp%>> Note.txt
echo.>> Note.txt
echo Cette disposition de clavier est compatible Windows 11, 10, 8.1, 8, 7, Vista,>> Note.txt
echo Server 2003, XP, 2000, et NT 4.0.>> Note.txt
echo.>> Note.txt
echo Elle est sous licence Apache 2.0.>> Note.txt
echo Visiter https://dispoclavier.com pour plus de renseignements.>> Note.txt
echo.>> Note.txt
echo La source KLC n’est pas censée contenir cette disposition de clavier.>> Note.txt
echo Sa fonction est de permettre à l’utilisateur de recompiler les pilotes>> Note.txt
echo à l’aide du MSKLC et du KbdUTool qu’il contient, avec éventuellement>> Note.txt
echo l’assistance d’un script de commandes comme Creadispo.>> Note.txt
echo.>> Note.txt
echo Creadispo est un script interactif et convivial utilisable en présence du>> Note.txt
echo Microsoft Keyboard Layout Creator (MSKLC).>> Note.txt
echo.>> Note.txt
echo Ce script fait grâce des tâches techniques qui autrement incombent à>> Note.txt
echo l’utilisateur du fait que l’interface du Keyboard Table Generation Tool inclus>> Note.txt
echo dans le MSKLC n’est pas graphique mais en ligne de commande.>> Note.txt
chdir ..
echo  J’ai ajouté une note.

:: Crée un dossier archivable de cette version :
if "%aready%" equ "non" goto versioncomplete
set bakdirname="archive %name%%sep%%description% v%version% %timestamp%"
mkdir %bakdirname%
xcopy %comidirname%    %bakdirname%\%comidirname%\ /s /q
xcopy %idirname%\i386  %bakdirname%\%comidirname%\%name%\i386\  /s /q
xcopy %idirname%\amd64 %bakdirname%\%comidirname%\%name%\amd64\ /s /q
xcopy %idirname%\ia64  %bakdirname%\%comidirname%\%name%\ia64\  /s /q
xcopy %idirname%\wow64 %bakdirname%\%comidirname%\%name%\wow64\ /s /q

:: Ajoute un fichier texte
chdir %bakdirname%
echo Disposition de clavier %name%%sep%%description% v%version%> Note.txt
echo.>> Note.txt
echo Datant du %timestamp%>> Note.txt
echo.>> Note.txt
echo Cette disposition de clavier est compatible Windows 11, 10, 8.1, 8, 7, Vista,>> Note.txt
echo Server 2003, XP, 2000, et NT 4.0.>> Note.txt
echo.>> Note.txt
echo La source KLC n’est pas censée contenir cette disposition de clavier.>> Note.txt
echo Sa fonction est de permettre à l’utilisateur de recompiler les pilotes>> Note.txt
echo à l’aide du MSKLC et du KbdUTool qu’il contient, avec éventuellement>> Note.txt
echo l’assistance d’un script de commandes comme Creadispo.>> Note.txt
echo.>> Note.txt
echo La copie avec l’extension '.bak' (pour 'backup') qui se trouve à côté de>> Note.txt
echo chaque pilote de disposition, dont l’extension qui correspond est .dll pour>> Note.txt
echo Dynamic Link Library, sert à protéger ces pilotes contre la suppression>> Note.txt
echo par une procédure de restauration du système postérieure à leur compilation,>> Note.txt
echo pour le cas où ils ne seraient pas sauvegardés sur un volume externe.>> Note.txt
chdir ..
echo  J’ai fait un dossier archivable avec une note.
echo  Cette étape peut être désactivée dans les préférences.

:: Range le dossier archivable dans le surdossier correspondant du projet :
if exist %bakdirproject% (
	move %bakdirname%  %bakdirproject%
echo  J’ai rangé le dossier archivable dans son surdossier.
)
:versioncomplete
:: Range le dossier de compilinstallation dans le surdossier correspondant du projet :
if exist %comidirproject% (
	move %comidirname% %comidirproject%
echo  J’ai rangé le dosssier de compilinstallation de %name% dans son surdossier.
echo  du projet %projectname%.
)
:: Range le dossier d’installation dans le surdossier correspondant du projet :
if exist %idirproject% (
	move %idirname% %idirproject%
echo  J’ai rangé le dossier d’installation de %name% dans son surdossier.
)
:: Enlève l’attribut 'lecture seule' pour rendre les sources de nouveau modifiables :
set /a totnbroa=%totnbroa%+%nbroa%
call :unlocksources

:: Regarde si tout est fait :
set /a cycle+=1
if %cycle%==%number% (
echo  J’ai fait passer toutes les dispositions du projet.
	goto versionend
) else (
	set /a rest=%number%-%cycle%
echo  Le projet contient encore d’autres dispositions, il en reste !rest! à faire.
echo  Je passe à la suivante.
	goto versionnext
)
:: Message final version :
:versionend
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                       La version %version% est prête.
echo.&echo.
echo                Creadispo vous souhaite une bonne utilisation.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo    ^>  Appuyez sur une touche pour me refermer.
echo.&echo.&echo.
if "%sound%" equ "oui" if not defined soundpref call %soundfile% else call %soundpref%
pause >nul
goto eof

:: ######____PRÉFÉRENCES____########################################################
:preferences
color fa
echo.
echo                                                P R É F É R E N C E S
echo.
echo     ^>  Comment souhaitez-vous que je fonctionne ?
echo.
echo    Je suis programmé dans l’espoir de répondre aux attentes des utilisateurs.
echo    Pour m’en rapprocher davantage, des paramètres comme les couleurs et
echo    l’encodage des sources KLC sont personnalisables. Je serai ravi de vous
echo    aider à faire vos choix, mais il vous est aussi possible de modifier votre
echo    profil directement. Avec l’option P je vous l’ouvre dans votre éditeur de
echo    texte par défaut. Par l’option M retournez à tout moment au menu principal.
color fe
echo.
echo    P = Profil utilisateur de %USERNAME%
echo.
echo    R = Répertoire de stockage des données pour la restauration de pilotes
echo.   
echo    E = Encodage des sources KLC (par défaut comme enregistrées par le MSKLC)
echo.
color fa
echo    D = Dossier archivable (supplément lors de la finition d’une version)
echo.
echo    C = Couleurs d’affichage :  bloquez-moi sur vos couleurs préférées.
echo.
echo    S = Son         F = Fréquence de clignotement         M = Menu principal
echo.   
color f2
set option=
:prefwhat
set /p option= .                     Votre choix : 
if not defined option goto preferences else (
	if /i "%option:~,1%" equ "c" call :colours
	if /i "%option:~,1%" equ "d" call :archifolder
	if /i "%option:~,1%" equ "e" call :encoding
	if /i "%option:~,1%" equ "f" call :customwait
	if /i "%option:~,1%" equ "m" goto  menu
	if /i "%option:~,1%" equ "p" goto  userprofile
	if /i "%option:~,1%" equ "r" call :globaldata
	if /i "%option:~,1%" equ "s" call :soundsettings
	goto preferences
)
:: Profil utilisateur :
:userprofile
call %LOCALAPPDATA%\creadispo\userdata.txt
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo                    J’ai ouvert le fichier de votre profil.
echo.&echo.
echo             Quand vous aurez fait et enregistré vos modifications,
echo.&echo.
echo      appuyez-moi sur une touche pour que je puisse les prendre en compte.
echo.&echo.
echo                    Ensuite j’afficherai le menu principal.
echo.&echo.&echo.&echo.&echo.&echo.
pause >nul
call :readuserprofile
goto menu

:: Répertoire des données globales :
:globaldata
call %ProgramData%\creadispo
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo         J’ai ouvert pour vous le dossier où je range mes archives.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Encodage des sources KLC :
:encoding
echo.&echo.
echo    E N C O D A G E   D E S   S O U R C E S   K L C
echo.
echo    Le MSKLC encode ses sources dans un format Unicode afin que vous puissiez
echo    y voir tous les caractères produits par touches mortes. Vous les trouvez
echo    dans les commentaires de fin de ligne des répertoires de touches mortes.
echo.
echo    En conséquence, KbdUTool accepte ces sources au format Unicode utilisé,
echo    qui est celui de Windows :  UTF-16 petit-boutien (Little Endian), aussi
echo    appelé UCS-2 Little Endian (LE). UCS signifie 'Universal Character Set'.
echo    Puisque chaque unité de code comporte deux octets, il y a un ordre, qui
echo    sous Windows consiste à commencer par le petit bout, l’octet comprenant
echo    les unités et les seizaines.
echo.
echo    Je pars du principe que vous me donnez de telles sources KLC, et je
echo    demande à KbdUTool de considérer qu’elles sont dans ce format Unicode,
echo    donc je le lui spécifie. Si la source ne correspond pas, KbdUTool se
echo    referme et doit être relancé avec le bon paramètre -- ou sur une source
echo    au bon format.
echo    Si vous souhaitez travailler en ANSI, dites-le moi s.v.p. ci-dessous.
echo.
echo     ^>  Pour passer à ANSI, entrez A ;  pour revenir à Unicode, entrez U.
echo        Pour retourner au menu des préférences, faites juste [M puis] Entrée.
echo.
set encin=
set /p encin= .                Encodage des sources KLC : 
if not defined encin goto :eof else (
	if "%encin:~,1%" equ "a" set enc=a&& set format=ANSI&&    goto saveenc
	if "%encin:~,1%" equ "u" set enc=u&& set format=Unicode&& goto saveenc
	if "%encin:~,1%" equ "m" goto :eof
)
:saveenc
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo         J’ai enregistré votre choix pour l’encodage des sources KLC.
echo.&echo.
echo        Les sources KLC que vous utiliserez seront au format %format%.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Activer ou désactiver la confection des dossiers archivables :
:archifolder
echo.&echo.
echo    D O S S I E R   A R C H I V A B L E
echo.
echo    Comme résultats de la compilation d’une version, je fais régulièrement :
echo.
echo                 +  un dossier pour l’installer
echo                 +  un dossier pour recompiler les pilotes
echo                 +  un dossier avec toutes les sources
echo.&echo.
echo    Mais je peux faire aussi un dossier spécialement conçu pour vos archives.
echo.
echo        Il contiendra :  +  un dossier de sources ;
echo                         +  un dossier d’installation ;
echo                         +  des copies des pilotes avec l’extension .bak.
echo.&echo.
echo    Souhaitez-vous à l’avenir que je prépare un dossier archivable pour chaque
echo    disposition en plus des autres dossiers lorsque je fais compiler une
echo    version finie ?
echo.
echo                Pour retourner au menu faites juste Entrée, ou M puis Entrée.
echo.
set arqtn=
set /p arqtn= .                       Oui / Non : 
if not defined arqtn goto :eof else (
	if "%arqtn:~,1%" equ "o" set aready=oui& set do=ferai un&        goto arsave
	if "%arqtn:~,1%" equ "n" set aready=non& set do=ne ferai pas de& goto arsave
	if "%arqtn:~,1%" equ "m" goto :eof
)
:arsave
set arqtnok=oui
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     J’ai enregistré votre choix pour la confection des dossiers archivables.
echo.&echo.
echo               Lors de la compilation d’une version finie, %aready%,
echo.&echo.
echo      je %do% dossier archivable pour chaque disposition compilée.
echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Couleurs d’affichage uniformes :
:: ###############  Ajouter le paramétrage dans le corps du script :
::                                    "if defined bg ( color %bg%%fg% ) else "
:colours
echo.&echo.&echo.
echo    C O U L E U R S   D ’ A F F I C H A G E
echo.
echo    J’utilise des couleurs différenciées afin de rendre l’affichage plus
echo    significatif et plus vivant. Toutefois vous pourriez préconiser un
echo    affichage uniforme dans vos couleurs de fond et de texte préférées.
echo.
echo    Si vous éprouvez le besoin de vous familiariser avec les 16 couleurs
echo    de CMD.exe, je vous propose de les essayer à volonté ici. Chacune est
echo    appelée par un chiffre hexadécimal dans l’ordre où elles s’égrènent au
echo    nuancier de l’onglet Couleurs des Propriétés (clic droit en haut).
echo    Une même gamme se décline en sombre et en clair (0-8 ;  9-f).
echo.
echo     ^>  Voyez défiler les couleurs par paires en tapant V et Entrée.
echo.
echo     ^>  Pour la liste des noms de couleurs tapez L (ou autre) puis Entrée.
echo.
echo    Faites S pour enregistrer, R pour restaurer les couleurs contextuelles,
echo    ou M pour retourner au menu sans enregistrer, toujours suivis d’Entrée.
echo.
echo    Si la couleur pour le fond est la même que pour le texte ou inversement,
echo    CMD.exe attend votre prochain choix jusqu’à ce que les deux couleurs
echo    soient différentes.
echo.
set bgin=
:colourloop
set /p bgin= .  Fond : 
if defined bgin (
	if /i "%bgin:~,1%" equ "m" goto :eof
	if /i "%bgin:~,1%" equ "v" goto coloreview
	if /i "%bgin:~,1%" equ "r" goto colorestore
	if /i "%bgin:~,1%" equ "s" goto coloursave
	set bg=%bgin:~,1%
	color !bg!%fg%
)
set /p fgin= .  Texte : 
if defined fgin (
	if /i "%fgin:~,1%" equ "m" goto :eof
	if /i "%fgin:~,1%" equ "p" goto coloreview
	if /i "%fgin:~,1%" equ "r" goto colorestore
	if /i "%fgin:~,1%" equ "s" goto coloursave
	set fg=%fgin:~,1%
	color %bg%!fg!
)
goto colourloop

:: Fait défiler les couleurs par paires :
:coloreview
call :milliwait & color 1f & call :milliwait & color 9f
call :milliwait & color 2f & call :milliwait & color af
call :milliwait & color 3f & call :milliwait & color bf
call :milliwait & color 4f & call :milliwait & color cf
call :milliwait & color 5f & call :milliwait & color df
call :milliwait & color 6f & call :milliwait & color ef
call :milliwait & color 0f & call :milliwait & color 8f
call :milliwait & color 7f & call :milliwait & color f2
goto colourloop

:: Restaure les couleurs par défaut :
:colorestore
set bg=
set fg=
color a1
call :saveuserprofile
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo           J’ai enregistré votre choix pour les couleurs d’affichage.
echo.&echo.
echo                   J’ai restauré les couleurs par défaut
echo.&echo.
echo                      définies selon les cironstances.
echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Enregistre les couleurs choisies :
:coloursave
call :saveuserprofile
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo             J’ai sauvegardé les couleurs actuelles dans votre profil
echo.&echo.
echo                  pour qu’elles soient toujours utilisées,
echo.&echo.
echo                      indépendamment des circonstances.
echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Éteindre ou personnaliser le son de termination :
:soundsettings
echo.&echo.&echo.
echo    S O N   D E   T E R M I N A T I O N
echo.
echo    Quand les résultats d’une tâche potentiellement longue sont tous réunis --
echo    ce qui dans le cas de vos multiprojets peut prendre un bon moment --
echo    je vous en avertis aussi par un signal sonore, pour le cas où
echo    vous aurez pu faire autre chose entre-temps.
echo.
echo    Si vous préférez ne pas entendre de signal sonore, entrez N ci-dessous.
echo    Pour réactiver le signal sonore éteint, entrez O.
echo.
echo    Le signal par défaut est l’avertissement d’achèvement d’impression
echo    par défaut de Windows :  C:\Windows\Media\Windows Print complete.wav
echo.
echo      Actuellement le signal est :
if defined soundpref ( echo      %soundpref%) else ( echo       %soundfile%)
echo.
echo    Si vous préférez que ce soit un autre son, je peux vous proposer que
echo    vous colliez son chemin complet ci-dessous avant d’appuyer sur Entrée.
echo     ^>  Pour coller dans ma fenêtre cliquez droit dessus et choisissez Coller.
echo.
echo    Pour revenir au signal par défaut, entrez D.
echo    Pour retourner au menu des préférences faites simplement Entrée.
echo.
set soundprefin=
set /p soundprefin= .   O[ui]/N[on]/D[éfaut]/M[enu]/[Chemin] : 
if not defined soundpref goto :eof else (
	if "%soundprefin%" equ "o" set sound=oui& set do=ferai entendre un&        goto soundconfirm
	if "%soundprefin%" equ "n" set sound=non& set do=ne ferai pas entendre de& goto soundconfirm
	if "%soundprefin%" equ "d" goto soundfilereset
	if "%soundprefin%" equ "m" goto :eof
	if "%soundprefin:~8,1%" equ "" goto soundsettings
	goto soundfileset
)
:soundconfirm
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo            J’ai enregistré votre choix concernant le signal sonore.
echo.&echo.
echo            Lors de l’achèvement d’une tâche potentiellement longue
echo.
echo                     je %do% signal sonore.
echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof
:soundfileset
set soundpref="%soundprefin%"
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo            J’ai enregistré votre choix concernant le signal sonore.
echo.&echo.
echo          Votre signal personnel figure dans votre profil utilisateur.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof
:soundfilereset
set soundpref=
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo            J’ai enregistré votre choix concernant le signal sonore,
echo.&echo.
echo                      et j’ai remis mon son par défaut.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Personnaliser l’intervalle de l’émulation du minuteur :
:customwait
echo.&echo.&echo.
echo    F R É Q U E N C E   D E   C L I G N O T E M E N T
echo.
echo    Parfois je fais changer les couleurs pour renforcer une alerte, ou encore
echo    pour vous faire patienter le temps que votre navigateur prenne le relais.
echo.
echo    Comme le minuteur de CMD.exe est réglé en minutes entières, j’utilise une
echo    émulation de minuteur sous forme de mini-boucle, que je mets environ 50 ms
echo    à retrouver et 120 ms à parcourir sur une machine 32 bit cadencée 1,66 GHz.
echo    Mais les scripts en batch -- mon langage -- peuvent devenir lents au cours
echo    d’une session et redevenir plus rapides après le prochain redémarrage.
echo       (On pourrait aussi détourner la commande PING, dont les délais sont
echo       toutefois arrondis par tranches de 500 ms d’après ce qui a été constaté.)
echo.
echo    Par défaut je parcours la boucle 3 fois, et le tout fait 450 ms environ sur
echo    la machine de test. Mais la durée réelle varie selon les performances de
echo    l’ordinateur, tandis que la durée idéale est fonction de vos préférences.
echo.
echo     ^>  Réglez la vitesse en me donnant un nombre. La valeur actuelle est %times%.
echo     ^>  Pour restaurer la valeur par défaut, entrez R ou D.
echo.
echo    Je vous ferai voir le résultat dès que vous aurez appuyé sur Entrée.
echo     ^>  Entrez S pour le sauvegarder.
echo                                         Pour retourner au menu faites Entrée.
set /a qua=1
:timesinloop
set timesin=
set /p timesin= .  Nombre de tours : 
if not defined timesin goto :eof else (
if /i "%timesin:~,1%" equ "d" set /a times=3&& goto timestest
if /i "%timesin:~,1%" equ "m" goto :eof
if /i "%timesin:~,1%" equ "r" set /a times=3&& goto timestest
if /i "%timesin:~,1%" equ "s" goto timesave
if     %timesin%      gtr  0  set /a times=%timesin%
)
:timestest
if %qua% equ 1 call :milliwait & color 1f & call :milliwait & color 9f & call :milliwait & color 2f & call :milliwait & color af & call :milliwait & color f2 & set /a qua=2 & goto timesinloop
if %qua% equ 2 call :milliwait & color 3f & call :milliwait & color bf & call :milliwait & color 4f & call :milliwait & color cf & call :milliwait & color f2 & set /a qua=3 & goto timesinloop
if %qua% equ 3 call :milliwait & color 5f & call :milliwait & color df & call :milliwait & color 6f & call :milliwait & color ef & call :milliwait & color f2 & set /a qua=4 & goto timesinloop
if %qua% equ 4 call :milliwait & color 0f & call :milliwait & color 8f & call :milliwait & color 7f & call :milliwait & color f2                              & set /a qua=1 & goto timesinloop

:: Enregistre la nouvelle valeur :
:timesave
call :saveuserprofile
color a1
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo      J’ai enregistré le nouvel intervalle dans votre profil utilisateur.
echo.&echo.
echo                              La valeur est %times%.
echo.&echo.&echo.&echo.&echo.&echo.&echo.&echo.
echo     Pour retourner au menu des préférences, appuyez s.v.p. sur une touche.
echo.&echo.
pause >nul
goto :eof

:: Boucle d’attente émulant un minuteur pour des délais en-dessous de 1 seconde :
:milliwait
set /a milli=0
:milliloop
set /a milli+=1
if %milli% lss %times% ( goto milliloop ) else ( goto :eof )

:: Enregistrement du profil utilisateur :
:saveuserprofile
echo creadispo 1.7> %LOCALAPPDATA%\creadispo\userdata.txt
echo Profil de %USERNAME%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Il vous est possible d’apporter des modifications directement dans ce fichier.>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Pour tout remettre aux valeurs d’origine : effacez-moi, puis relancez creadispo.>> %LOCALAPPDATA%\creadispo\userdata.txt
echo ------------------------------------------------------------------------------>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Niveau de progression prise en main [maximum = 10] :%helplevel%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Encodage des sources KLC [u = Unicode, a = ANSI] . :%enc%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Couleurs [1-8 = sombres, 9-f = claires]  . .  Fond :%bg%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo [aucune valeur = selon les circonstances]    Texte :%fg%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Minuteur [nombre d’intervalles]  . . . . . . . . . :%times%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Viser la rubrique de compilinstallation [oui/non]  :%adhoc%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Produire un dossier archivable [oui/non] . . . . . :%aready%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Si la question du dossier archivable est faite . . :%arqtnok%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Date de l’utilisation d’avant  . . . . . . . . . . :%datestamp%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Si aujourd’hui je vous ai dit bonjour  . . . . . . :%day%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Si aujourd’hui je vous ai dit bonsoir  . . . . . . :%eve%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Si je peux faire entendre le son de termination  . :%sound%>> %LOCALAPPDATA%\creadispo\userdata.txt
echo Votre son de termination [aucun = le son standard] :%soundpref%>> %LOCALAPPDATA%\creadispo\userdata.txt
goto :eof

:: Lecture du profil utilisateur :
:readuserprofile
set /a N=0
for /f "skip=5 tokens=* delims=" %%a in (%LOCALAPPDATA%\creadispo\userdata.txt) do (
set v!N!=%%a
set /a N+=1
)
set helplevel=!v0:~52!
set enc=!v1:~52!
set bg=!v2:~52!
set fg=!v3:~52!
set times=!v4:~52!
set adhoc=!v5:~52!
set aready=!v6:~52!
set arqtnok=!v7:~52!
set datestamp=!v8:~52!
set day=!v9:~52!
set eve=!v10:~52!
set sound=!v11:~52!
set soundpref=!v12:~52!
goto :eof

:: FIN DE SCRIPT

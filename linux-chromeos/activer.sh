#!/bin/bash
#                       Date : 2024-08-26T1019+0200
#                    Fichier : activer.sh
#                   Encodage : UTF-8
#                       Type : script Bash
#                Description : Charge une source XKB fusionnée pour activer une disposition de clavier.
#     Système d’exploitation : Linux
#
#                     Projet : Dispoclavier
#              URL du projet : https://dispoclavier.com
#                     Maxime : Simplifier la dactylographie, pas le français.
#                Description : Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie
#              Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
#               Licence code : Apache 2.0
#     URL de la licence code : https://www.apache.org/licenses/LICENSE-2.0
#           Licence non-code : CC-BY 4.0
# URL de la licence non-code : https://creativecommons.org/licenses/by/4.0/deed.fr
#               Adresse mail : dev@dispoclavier.net
# 
#   Utilisation
#
#   • En ligne de commande :
#
#     ◦ Vérifier le contenu du script ci-dessous ;
#     ◦ Ouvrir un terminal dans le même dossier ;
#     ◦ Rendre ce script exécutable par « chmod +x installer.sh » ;
#     ◦ Lancer le script par la commande « ./installer.sh ».
#
#
#   • Dans le navigateur de fichiers :
#
#     ◦ Vérifier le contenu du script ci-dessous ;
#     ◦ Rendre le script exécutable dans Propriétés > Permissions > Exécuter ;
#     ◦ Aller dans Édition > Préférences > Comportement > Fichier texte exécutable :
#     ◦ Pour l’action à l’ouverture du fichier, choisir « Demander chaque fois » ;
#     ◦ Cliquer ou double-cliquer le script puis choisir « Lancer dans le terminal ».
#
#
#   Fichiers associés
#
#   Pour fonctionner, ce script a besoin des fichiers suivants dans cette arborescence.
#   Si l’un des 9 derniers fichiers manque, la redisposition des touches en fonction des
#   sous-variantes n’est pas prise en charge, mais l’installation standard fonctionne.
#
#      activer.sh
#      Compose.yml
#      activer/
#         nouvel-azerty.xkb
#         nouvel-azerty-ansi.xkb
#         nouvel-azerty-ansi-menu.xkb
#         nouvel-azerty-ansi-menu-sans.xkb
#         nouvel-azerty-ctrl.xkb
#         nouvel-azerty-menu.xkb
#         nouvel-azerty-menu-sans.xkb
#         nouvel-azerty-win.xkb
#         nouvel-azerty-win-sans.xkb
#         Variantes/
#            kbbrFRs/
#               kbbrFRs.xkb
#               kbbrFRs-ansi.xkb
#               kbbrFRs-ansi-menu.xkb
#               kbbrFRs-ansi-menu-sans.xkb
#               kbbrFRs-ctrl.xkb
#               kbbrFRs-menu.xkb
#               kbbrFRs-menu-sans.xkb
#               kbbrFRs-win.xkb
#               kbbrFRs-win-sans.xkb
#            kbbrFRsr/
#               kbbrFRsr.xkb
#               kbbrFRsr-ansi.xkb
#               kbbrFRsr-ansi-menu.xkb
#               kbbrFRsr-ansi-menu-sans.xkb
#               kbbrFRsr-ctrl.xkb
#               kbbrFRsr-menu.xkb
#               kbbrFRsr-menu-sans.xkb
#               kbbrFRsr-win.xkb
#               kbbrFRsr-win-sans.xkb
#            kbfrAFs/
#               kbfrAFs.xkb
#               kbfrAFs-ansi.xkb
#               kbfrAFs-ansi-menu.xkb
#               kbfrAFs-ansi-menu-sans.xkb
#               kbfrAFs-ctrl.xkb
#               kbfrAFs-menu.xkb
#               kbfrAFs-menu-sans.xkb
#               kbfrAFs-win.xkb
#               kbfrAFs-win-sans.xkb
#            kbfrAFsr/
#               kbfrAFsr.xkb
#               kbfrAFsr-ansi.xkb
#               kbfrAFsr-ansi-menu.xkb
#               kbfrAFsr-ansi-menu-sans.xkb
#               kbfrAFsr-ctrl.xkb
#               kbfrAFsr-menu.xkb
#               kbfrAFsr-menu-sans.xkb
#               kbfrAFsr-win.xkb
#               kbfrAFsr-win-sans.xkb
#            kbfrBEs/
#               kbfrBEs.xkb
#               kbfrBEs-ansi.xkb
#               kbfrBEs-ansi-menu.xkb
#               kbfrBEs-ansi-menu-sans.xkb
#               kbfrBEs-ctrl.xkb
#               kbfrBEs-menu.xkb
#               kbfrBEs-menu-sans.xkb
#               kbfrBEs-win.xkb
#               kbfrBEs-win-sans.xkb
#            kbfrFRs/
#               kbfrFRs.xkb
#               kbfrFRs-ansi.xkb
#               kbfrFRs-ansi-menu.xkb
#               kbfrFRs-ansi-menu-sans.xkb
#               kbfrFRs-ctrl.xkb
#               kbfrFRs-menu.xkb
#               kbfrFRs-menu-sans.xkb
#               kbfrFRs-win.xkb
#               kbfrFRs-win-sans.xkb
#            kbfrFRsr/
#               kbfrFRsr.xkb
#               kbfrFRsr-ansi.xkb
#               kbfrFRsr-ansi-menu.xkb
#               kbfrFRsr-ansi-menu-sans.xkb
#               kbfrFRsr-ctrl.xkb
#               kbfrFRsr-menu.xkb
#               kbfrFRsr-menu-sans.xkb
#               kbfrFRsr-win.xkb
#               kbfrFRsr-win-sans.xkb
#            kbfrPFs/
#               kbfrPFs.xkb
#               kbfrPFs-ansi.xkb
#               kbfrPFs-ansi-menu.xkb
#               kbfrPFs-ansi-menu-sans.xkb
#               kbfrPFs-ctrl.xkb
#               kbfrPFs-menu.xkb
#               kbfrPFs-menu-sans.xkb
#               kbfrPFs-win.xkb
#               kbfrPFs-win-sans.xkb
#            kbfrPFsr/
#               kbfrPFsr.xkb
#               kbfrPFsr-ansi.xkb
#               kbfrPFsr-ansi-menu.xkb
#               kbfrPFsr-ansi-menu-sans.xkb
#               kbfrPFsr-ctrl.xkb
#               kbfrPFsr-menu.xkb
#               kbfrPFsr-menu-sans.xkb
#               kbfrPFsr-win.xkb
#               kbfrPFsr-win-sans.xkb
#
#   Les sources de disposition de clavier fusionnées `.xkb` sont préférables
#   aux dispositions de clavier compilées `.xkm`, car elles sont vérifiables
#   et éditables pour de petites personnalisations.
#
# L’absence des booléens dans Bash est palliée par le recours aux comparaisons
# arithmétiques. On en profite pour inverser 0 et 1 — qui dans Bash signifient
# vrai et faux, contrairement à la plupart des autres langages où ils
# signifient faux et vrai — dans un souci de lisibilité.
#
intelligible=1 # Format XKB. Changer pour prendre en charge le format XKM.
if [ "$intelligible" -eq 1 ]; then
	mode="xkb"
else
	mode="xkm"
fi

function config_xim {
	if ! im-config -m | grep -q 'xim'; then
		echo -e "\n  ⚠  Ces dispositions de clavier fonctionnent uniquement"
		echo      '     si le système de saisie au clavier est XIM.'
		echo -e "\n  ⚠  Sans la X Window Input Method, toutes les séquences"
		echo      '     multi-caractères sont en panne.'
		echo      '     Or sans séquences multi-caractères, ces dispositions'
		echo      '     semi-automatiques ne peuvent être opérationnelles.'
		echo      '     Même les lettres composées qui sont dans les touches'
		echo      '     mortes ne peuvent être saisies, étant en panne.'
		echo -e "\n     XIM une fois sélectionnée, elle sera active"
		echo      '     dès la prochaine session.'
		echo -e "\n  ⚠  Avant d’installer ces dispositions de clavier,"
		echo      '     le mieux est de commencer par activer XIM.'
		echo -e "\n       Pour activer XIM, appuyez sur Entrée."
		echo      '       Pour quitter, tapez q ou n puis Entrée.'
		read -p   '    ' reponse
		case $reponse in
			[nNqQ])
				exit
			;;
			*)
				# Basculer vers le système de saisie au clavier XIM.
				im-config -n xim
				echo      '    XIM a maintenant été sélectionné.'
			;;
		esac
	fi
}

function options_de_disposition {
	config_xim
	echo -e "\n  ⚠  Vous pouvez opter pour ce nouvel AZERTY par défaut,"
	echo      '     ou choisir une variante et éventuellement une sous-variante.'
	echo -e "\n  ❓  Souhaitez-vous choisir rapidement dans deux listes ?"
	echo -e "\n       Si oui, appuyez sur Entrée."
	echo      '       Pour quitter, tapez q ou n puis Entrée.'
	read -p   '    ' repo
	case $repo in
		[nNqQ])
			exit
		;;
		*)
			echo -e "\n  ❓  Quelle variante souhaitez-vous activer ? Pour passer, faites Entrée."
			echo      '   1  Français France disposition de clavier semi-automatique – kbfrFRs'
			echo      '   2  Breton et français disposition de clavier semi-automatique – kbbrFRs'
			echo      '   3  Polynésie française disposition de clavier semi-automatique – kbfrPFs'
			echo      '   4  Afrique francophone disposition de clavier semi-automatique – kbfrAFs'
			echo      '   5  Français Belgique disposition de clavier semi-automatique – kbfrBEs'
			echo      '   6  Français France disposition de clavier semi-automatique redisposée – kbfrFRsr'
			echo      '   7  Breton et français disposition de clavier semi-automatique redisposée – kbbrFRsr'
			echo      '   8  Polynésie française disposition de clavier semi-automatique redisposée – kbfrPFsr'
			echo      '   9  Afrique francophone disposition de clavier semi-automatique redisposée – kbfrAFsr'
			read -p   '         ' re
			case $re in
				1) chemin="Variantes/kbfrFRs/kbfrFRs";;
				2) chemin="Variantes/kbbrFRs/kbbrFRs";;
				3) chemin="Variantes/kbfrPFs/kbfrPFs";;
				4) chemin="Variantes/kbfrAFs/kbfrAFs";;
				5) chemin="Variantes/kbfrBEs/kbfrBEs";;
				6) chemin="Variantes/kbfrFRsr/kbfrFRsr";;
				7) chemin="Variantes/kbbrFRsr/kbbrFRsr";;
				8) chemin="Variantes/kbfrPFsr/kbfrPFsr";;
				9) chemin="Variantes/kbfrAFsr/kbfrAFsr";;
				*) chemin="nouvel-azerty";;
			esac
		;;
	esac
	echo -e "\n  ❓  Quelle sous-variante souhaitez-vous ? Pour passer, faites Entrée."
	echo      "      o = Disposition ordinaire."
	echo      "      w = Effacement arrière sur Windows droite."
	echo      "     ws = Effacement arrière sur Windows droite sans Menu."
	echo      "      m = Effacement arrière sur Menu, Menu sur Effacement arrière."
	echo      "     ms = Effacement arrière sur Menu seulement, sans permutation."
	echo      "      c = Permuter Effacement arrière et Contrôle droite."
	echo      "      a = Permuter VerrCap et touche ISO pour claviers ANSI."
	echo      "     am = Permuter VerrCap et touche ISO, et Effacement arrière et Menu."
	echo      "    ams = Permuter VerrCap et touche ISO, Effacement arrière sur Menu."
	read -p   "          o, w, ws, m, ms, c, a, am, ams ?   " re
	case $re in
		o)   suffixe="";;
		w)   suffixe="-win";;
		ws)  suffixe="-win-sans";;
		m)   suffixe="-menu";;
		ms)  suffixe="-menu-sans";;
		c)   suffixe="-ctrl";;
		a)   suffixe="-ansi";;
		am)  suffixe="-ansi-menu";;
		ams) suffixe="-ansi-menu-sans";;
		*)   suffixe="";;
	esac
	chemin_complet="$chemin$suffixe.$mode"
	if [ -f "activer/$chemin_complet" ]; then
		xkbcomp activer/$chemin_complet :0
		mkdir -p ~/.config/dispoclavier/activer
		echo "$chemin_complet" > ~/.config/dispoclavier/activer/der.txt
		cp activer/$chemin_complet ~/.config/dispoclavier/activer/der.$mode
		echo -e "\n  ✅  La disposition de clavier vient d’être activée."
		echo -e "\n     Son fichier .$mode et son chemin ont été sauvegardés"
		echo      '         dans ~/.config/dispoclavier/activer/.'
		echo -e "\n     Tous les retours d’expérience sont les bienvenus."
		echo      '     S’il manque quoi que ce soit, ou à tout autre sujet relatif,'
		echo      '     n’hésitez pas à créer un rapport de bogue :'
		echo      '     https://github.com/dispoclavier/nouvel-azerty/issues'
		echo -e "\n     N’hésitez pas non plus à lancer une discussion :"
		echo      '     https://github.com/dispoclavier/nouvel-azerty/discussions'
		echo -e "\n             Bonne utilisation !\n"
	else
		echo -e "\n     Cette disposition de clavier n’a pas été activée, car"
		echo      '     le fichier à activer n’est pas accessible.'
		echo -e "\n     Le mieux est de télécharger un nouveau paquetage"
		echo      '     sur la page de la version la plus récente :'
		echo      '     https://github.com/dispoclavier/nouvel-azerty/releases/latest'
		echo -e "\n     Avec toutes nos excuses pour ce désagrément.\n"
	fi
}

echo -e "\n    Bienvenue dans l’activateur de dispositions de clavier Dispoclavier."
if [ -f "$HOME/.config/dispoclavier/activer/der.txt" ] && [ -d "activer" ]; then
	chemin=$(<"$HOME/.config/dispoclavier/activer/der.txt");
	if [ -f "activer/$chemin" ]; then
		echo -e "\n  ❓  Souhaitez-vous activer la version actuelle de"
		echo      '     la disposition dernièrement utilisée ?'
		echo -e "\n       Pour l’activer, appuyez sur Entrée."
		echo      '       Pour plus d’options, tapez o puis Entrée.'
		echo      '       Pour quitter, tapez q ou n puis Entrée.'
		read -p   '    ' reponse
		case $reponse in
			[nNqQ])
				exit
			;;
			[oO])
				options_de_disposition
			;;
			*)
				config_xim
				xkbcomp activer/$chemin :0
				echo -e "\n  ✅  La disposition de clavier vient d’être activée."
				echo -e "\n     Tous les retours d’expérience sont les bienvenus."
				echo      '     S’il manque quoi que ce soit, ou à tout autre sujet relatif,'
				echo      '     n’hésitez pas à créer un rapport de bogue :'
				echo      '     https://github.com/dispoclavier/nouvel-azerty/issues'
				echo -e "\n     N’hésitez pas non plus à lancer une discussion :"
				echo      '     https://github.com/dispoclavier/nouvel-azerty/discussions'
				echo -e "\n             Bonne utilisation !\n"
			;;
		esac
	else
		options_de_disposition
	fi
elif [ -f "$HOME/.config/dispoclavier/activer/der.$mode" ]; then
	echo -e "\n  ❓  Souhaitez-vous réactiver la disposition dernièrement utilisée ?"
	echo -e "\n       Pour la réactiver, appuyez sur Entrée."
	echo      '       Pour plus d’options, tapez o puis Entrée.'
	echo      '       Pour quitter, tapez q ou n puis Entrée.'
	read -p   '    ' reponse
	case $reponse in
		[nNqQ])
			exit
		;;
		[oO])
			options_de_disposition
		;;
		*)
			config_xim
			xkbcomp ~/.config/dispoclavier/activer/der.$mode :0
			echo -e "\n  ✅  La disposition de clavier vient d’être réactivée."
			echo -e "\n     Tous les retours d’expérience sont les bienvenus."
			echo      '     S’il manque quoi que ce soit, ou à tout autre sujet relatif,'
			echo      '     n’hésitez pas à créer un rapport de bogue :'
			echo      '     https://github.com/dispoclavier/nouvel-azerty/issues'
			echo -e "\n     N’hésitez pas non plus à lancer une discussion :"
			echo      '     https://github.com/dispoclavier/nouvel-azerty/discussions'
			echo -e "\n             Bonne utilisation !\n"
		;;
	esac
else
	options_de_disposition
fi
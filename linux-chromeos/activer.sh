#!/bin/bash
#                       Date : 2025-07-22T1912+0200
#                    Fichier : activer.sh
#                   Encodage : UTF-8
#                       Type : script Bash
#                Description : Fait charger une source XKB ou une disposition XKM pour activer une disposition de clavier.
#     Système d’exploitation : Linux
#
#                     Projet : Dispoclavier
#              URL du projet : https://dispoclavier.com
#               Licence code : Apache 2.0
#     URL de la licence code : https://www.apache.org/licenses/LICENSE-2.0
#           Licence non-code : CC-BY 4.0
# URL de la licence non-code : https://creativecommons.org/licenses/by/4.0/deed.fr
#               Adresse mail : dev[arobase]dispoclavier.com
#
#   ALERTES
#
#   Ce script utilise l’utilitaire xkbcomp documenté par IBM pour son OS AIX :
#   https://www.ibm.com/docs/en/aix/7.3?topic=x-xkbcomp-command
#
#   L’activation automatique à l’ouverture de session, faute de fonctionner par
#   un script, propose d’exécuter ce script manuellement en l’affichant dans le
#   navigateur de fichiers. Si ce n’est pas l’un des 10 recommandés sur la page
#   https://www.geeksforgeeks.org/10-best-file-managers-for-linux/
#   soit Dolphin, Double Commander, Konqueror, Krusader, Midnight Commander,
#   Nautilus (GNOME Files), Nemo, Nnn, PCManFM ou Thunar, et si votre terminal
#   n’est pas GNOME Terminal, ils peuvent être personnalisés plus bas dans :
#
#      emulateur_terminal="gnome-terminal" # Personnaliser si différent.
#      navigateur_fichiers="dolphin" # Personnaliser si différent.
#
#   De même, si le format XKB n’est pas préféré, le format compilé
#   peut être choisi en altérant la valeur 1 de cette variable :
#
#      intelligible=1 # 1 = format XKB. Changer pour prendre en charge le format XKM.
#
#   Toutefois, les fichiers d’activation au format XKM ne sont pas fournis, à cause
#   de leur opacité et de leur immuabilité.
#
#   Pour une activation manuelle, on peut utiliser l’alias ":0" de la variable
#   d’environnement $DISPLAY.
#
#
#   Utilisation
#
#   • En ligne de commande :
#
#     ◦ Vérifier le contenu du script ci-dessous ;
#     ◦ Ouvrir un terminal dans le même dossier ;
#     ◦ Rendre ce script exécutable par « chmod +x activer.sh » ;
#     ◦ Lancer le script par la commande « ./activer.sh ».
#
#
#   • Dans le navigateur de fichiers :
#
#     ◦ Vérifier le contenu du script ci-dessous ;
#     ◦ Rendre le script exécutable : Propriétés > Permissions > Exécuter ;
#     ◦ Dans Édition > Préférences > Comportement > Fichier texte exécutable :
#     ◦ Pour l’action à l’ouverture du fichier : « Demander chaque fois » ;
#     ◦ Cliquer ou double-cliquer ce script, puis « Lancer dans le terminal ».
#
#
#   Fichiers associés
#
#   Ce script est susceptible d’utiliser l’un des fichiers suivants :
#
#      [activer.sh]
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
# arithmétiques. Pour la lisibilité, 0 et 1 sont inversés en "vrai" et "faux".

intelligible=1 # 1 = format XKB. Changer pour prendre en charge le format XKM.
emulateur_terminal="gnome-terminal" # Personnaliser si différent.
navigateur_fichiers="dolphin" # Personnaliser si différent.
navigateur_fichiers_1="doublecmd-gtk"
navigateur_fichiers_2="konqueror"
navigateur_fichiers_3="krusader"
navigateur_fichiers_4="mc"
navigateur_fichiers_5="nautilus"
navigateur_fichiers_6="nemo"
navigateur_fichiers_7="nnn"
navigateur_fichiers_8="pcmanfm"
navigateur_fichiers_9="thunar"

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

function gestion_compose {
	message_compose='Ses chaînes de caractères pour touches vives et\n     le contenu de ses touches mortes '
	if [ -f "Compose.yml" ]; then
		if [ -f "$HOME/.XCompose" ]; then
			# Si le XCompose Dispoclavier est déjà dans le .XCompose, le supprimer.
			if ( grep -q 'START_additions_X\?Compose_Dispoclavier' ~/.XCompose && grep -q 'END_additions_X\?Compose_Dispoclavier' ~/.XCompose ); then
				sed -i '/START_additions_X\?Compose_Dispoclavier/,/END_additions_X\?Compose_Dispoclavier/d' ~/.XCompose
				message_compose+='ont été mis à jour dans\n     le fichier .XCompose existant.'
			else
				message_compose+='ont été ajoutés dans\n     le fichier .XCompose existant.'
			fi
			# Ajouter le XCompose Dispoclavier actuel dans le .XCompose.
			cat Compose.yml >> ~/.XCompose
		else
			# Placer le XCompose Dispoclavier actuel dans un nouveau .XCompose.
			cp Compose.yml ~/.XCompose
			message_compose+='ont été placés dans\n     un fichier .XCompose ajouté à la racine de\n     votre dossier personnel.'
		fi
		# Si le XCompose de la locale n’est pas déjà inclus, l’inclure.
		if ! grep -qP '^\s*include "%L"' ~/.XCompose; then
			sed -ri 's/\s*#.*\s*(include "%L")/\1/' ~/.XCompose
		fi
	else
		message_compose+='n’ont pas pu être\n     pris en charge, espérant qu’ils sont déjà en place.'
	fi
}

function options_de_disposition {
	config_xim
	echo -e "\n  ⚠  Vous pouvez opter pour la version par défaut de ce nouvel AZERTY,"
	echo      '     ou choisir une variante et éventuellement une sous-variante.'
	echo -e "\n  ❓  Souhaitez-vous choisir rapidement dans deux listes ?"
	echo -e "\n       Si oui, appuyez sur Entrée."
	if [ -f "$HOME/.config/dispoclavier/activer/dispo_habituelle.$mode" ]; then
		echo      '       Pour revenir à la disposition de clavier habituelle, tapez h puis Entrée.'
	else
		xkbcomp $DISPLAY ~/.config/dispoclavier/activer/dispo_habituelle.$mode
	fi
	echo      '       Pour quitter, tapez q ou n puis Entrée.'
	read -p   '    ' repo
	case $repo in
		[nNqQ])
			exit
		;;
		[hH])
			xkbcomp -w 0 ~/.config/dispoclavier/activer/dispo_habituelle.$mode $DISPLAY
			echo -e "\n  ✅  La disposition de clavier habituelle vient d’être réactivée.\n"
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
				xkbcomp -w 0 activer/$chemin_complet $DISPLAY
				mkdir -p ~/.config/dispoclavier/activer
				echo "$chemin_complet" > ~/.config/dispoclavier/activer/der.txt
				cp activer/$chemin_complet ~/.config/dispoclavier/activer/der.$mode
				gestion_compose
				echo -e "\n  ✅  La disposition de clavier vient d’être activée."
				echo -e "\n     Son fichier .$mode et son chemin ont été sauvegardés"
				echo      '         dans ~/.config/dispoclavier/activer/.'
				echo -e "\n     $message_compose"
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
		;;
	esac
}

echo -e "\n    Bienvenue dans l’activateur de dispositions de clavier Dispoclavier."
if [ -f "$HOME/.config/dispoclavier/activer/der.txt" ] && [ -d "activer" ]; then
	chemin=$(<"$HOME/.config/dispoclavier/activer/der.txt");
	if [ -f "activer/$chemin" ]; then
		echo -e "\n  ❓  Souhaitez-vous activer la version actuelle de"
		echo      '            la disposition dernièrement utilisée ?'
		echo -e "\n       Pour l’activer, appuyez sur Entrée."
		echo      '       Pour plus d’options, tapez o ou p puis Entrée.'
		if [ -f "$HOME/.config/autostart/activer-dispo.desktop" ]; then
			echo      '       Pour désactiver l’automatisation, tapez d puis Entrée.'
		else
			echo      '       Pour automatiser l’activation, tapez a puis Entrée.'
		fi
		echo      '       Pour quitter, tapez q ou n puis Entrée.'
		read -p   '    ' reponse
		case $reponse in
			[nNqQ])
				exit
			;;
			[oOpP])
				options_de_disposition
			;;
			[aA])
				if [ -f "$HOME/.config/dispoclavier/activer/der.$mode" ]; then
					mkdir -p ~/.config/autostart # Comme /etc/xdg/autostart/.
					cd ~/.config/autostart
					# https://specifications.freedesktop.org/autostart-spec/0.5/
					# https://specifications.freedesktop.org/desktop-entry-spec/latest/recognized-keys.html
					# https://forums.linuxmint.com/viewtopic.php?t=349397
					echo "#!/usr/bin/env xdg-open" > activer-dispo.desktop # Ajouté lors de la validation.
					echo "[Desktop Entry]" >> activer-dispo.desktop
					echo "Type=Application" >> activer-dispo.desktop
					echo "Exec=$HOME/.config/dispoclavier/activer/der.sh" >> activer-dispo.desktop
					echo "X-GNOME-Autostart-enabled=true" >> activer-dispo.desktop
					echo "X-KDE-Autostart-enabled=true" >> activer-dispo.desktop
					echo "NoDisplay=false" >> activer-dispo.desktop
					echo "Hidden=false" >> activer-dispo.desktop
					echo "Name=activer-dispo" >> activer-dispo.desktop
					echo "Comment=Activation de la dernière disposition de clavier utilisée" >> activer-dispo.desktop
					echo "X-GNOME-Autostart-Delay=3" >> activer-dispo.desktop
					echo "X-KDE-Autostart-Delay=3" >> activer-dispo.desktop
					chmod +x activer-dispo.desktop # Ajouté lors de la validation.
					cd ~/.config/dispoclavier/activer
					echo "#!/bin/bash" > der.sh
					echo "# $(date +"%Y-%m-%dT%H:%M:%S")" >> der.sh
					echo "# Activation de la dernière disposition de clavier utilisée." >> der.sh
					echo "# sleep 3 # La temporisation est dans autostart." >> der.sh
					echo "failed=0" >> der.sh
					echo "( $emulateur_terminal -- xkbcomp -w 0 der.$mode $DISPLAY && ( echo -e \"\n  ✅  La disposition de clavier vient d’être activée.\n     Je vous invite à appuyer sur Entrée pour me refermer.\n\n             Bonne utilisation !\n\"; read ) ) || failed=1" >> der.sh
					echo "if [ \"\$failed\" -eq 1 ]; then" >> der.sh
					echo -e "\tfailed=0" >> der.sh
					echo -e "\txkbcomp -w 0 der.$mode $DISPLAY || failed=1" >> der.sh
					echo "fi" >> der.sh
					echo "if [ \"\$failed\" -eq 1 ]; then" >> der.sh
					echo -e "\t$navigateur_fichiers $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_1 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_2 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_3 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_4 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_5 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_6 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_7 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_8 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo -e "\t$navigateur_fichiers_9 $HOME/.config/dispoclavier/activer/der.sh" >> der.sh
					echo "fi" >> der.sh
					chmod +x der.sh
					if [ -f "$HOME/.config/autostart/activer-dispo.desktop" ]; then
						echo -e "\n  ✅  L’activation est désormais censée être automatisée, et en principe,"
						echo      '      dès l’ouverture de session, la disposition dernièrement utilisée devrait'
						echo      '      être activée. Mais cela ne fonctionne que pour lancer la commande dans'
						echo      '      un terminal, voire, accéder au script dans un navigateur de fichiers.'
						echo      '      Ces deux solutions de dépannage sont aussi prises en charge.'
						echo -e "\n      Quand vous verrez le navigateur de fichiers à l’ouverture de session,"
						echo      '      cela signifie que deux tentatives d’activation ont déjà échoué, une'
						echo      '      silencieuse et une dans le terminal.'
						echo -e "\n      Dans le navigateur de fichiers, le même script attendra que vous le"
						echo      '      lanciez manuellement. Ce script ouvrira un terminal,'
						echo      '      dans lequel il vous confirmera l’activation réussie.'
						echo -e "\n    Pour désactiver cet automatisme, relancer ce script et choisir l’option D."
						echo -e "\n             Bonne utilisation !\n"
					else
						echo -e "\n  ⚠  L’automatisation a échoué, car le fichier n’a pas pu être créé."
						echo -e "\n     Avec toutes nos excuses pour ce désagrément.\n"
					fi
				else
					echo -e "\n  ⚠  L’automatisation n’est pas possible dans l’état actuel."
					echo -e "\n     Le mieux est d’activer une disposition par l’option O ou P,"
					echo      '     et ensuite de relancer la mise en place de l’automatisme, le'
					echo      '     tout éventuellement après que vous avez téléchargé un nouveau'
					echo      '     paquetage sur la page de la version la plus récente :'
					echo      '     https://github.com/dispoclavier/nouvel-azerty/releases/latest'
					echo -e "\n     Avec toutes nos excuses pour ce désagrément.\n"
				fi
			;;
			[dD])
				mkdir -p sauvegarde
				mv ~/.config/autostart/activer-dispo.desktop sauvegarde/activer-dispo.desktop
				echo -e "\n  ✅  L’activation automatique est désactivée.\n"
			;;
			*)
				config_xim
				xkbcomp -w 0 activer/$chemin $DISPLAY
				gestion_compose
				echo -e "\n  ✅  La disposition de clavier vient d’être activée."
				echo -e "\n     $message_compose"
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
	echo      '       Pour plus d’options, tapez o ou p puis Entrée.'
	echo      '       Pour quitter, tapez q ou n puis Entrée.'
	read -p   '    ' reponse
	case $reponse in
		[nNqQ])
			exit
		;;
		[oOpP])
			options_de_disposition
		;;
		*)
			config_xim
			xkbcomp -w 0 ~/.config/dispoclavier/activer/der.$mode $DISPLAY
			gestion_compose
			echo -e "\n  ✅  La disposition de clavier vient d’être réactivée."
			echo -e "\n     $message_compose"
			echo -e "\n     Tous les retours d’expérience sont les bienvenus."
			echo      '     S’il manque quoi que ce soit, ou à tout autre sujet relatif,'
			echo      '     n’hésitez pas à créer un rapport de bogue :'
			echo      '     https://github.com/dispoclavier/nouvel-azerty/issues'
			echo -e "\n     N’hésitez pas non plus à lancer une discussion :"
			echo      '     https://github.com/dispoclavier/nouvel-azerty/discussions'
			echo -e "\n             Bonne utilisation !\n"
		;;
	esac
elif [ -d "activer" ]; then
	options_de_disposition
else
		echo -e "\n     Les dispositions de clavier à activer ne sont pas présentes."
		echo -e "\n     Le mieux est de télécharger un nouveau paquetage"
		echo      '     sur la page de la version la plus récente :'
		echo      '     https://github.com/dispoclavier/nouvel-azerty/releases/latest'
		echo -e "\n     Avec toutes nos excuses pour ce désagrément.\n"
fi

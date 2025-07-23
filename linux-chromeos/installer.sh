#!/bin/bash
#                       Date : 2025-07-23T2302+0200
#                    Fichier : installer.sh
#                   Encodage : UTF-8
#                       Type : script Bash
#                Description : Installe, met à jour et désinstalle des dispositions de clavier.
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
#
#   AVERTISSEMENT
#
#   Ce script met tous les fichiers installés en lecture/écriture pour tout le
#   monde, "666", car même avec 644, l’administrateur est exclu, ce qui dégrade
#   l’expérience utilisateur. Si ces permissions ne conviennent pas, la valeur
#   doit être modifiée ici selon les exigences.
#
permissions=666
#
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
#     ◦ Rendre ce script exécutable dans Propriétés > Permissions > Exécuter ;
#     ◦ Dans Édition > Préférences > Comportement > Fichier texte exécutable,
#       choisir « Demander chaque fois » ;
#     ◦ Cliquer ou double-cliquer ce script puis « Lancer dans un terminal ».
#
#
#   Fichiers associés
#
#   Ce script utilise les fichiers suivants.
#   Si les 9 derniers fichiers ne sont pas au complet, les redispositions de
#   touches en fonction des sous-variantes ne sont pas prises en charge, mais
#   l’installation standard fonctionne.
#
#      [installer.sh]
#      Compose.yml
#      installer/
#         dispotypes.c
#         dispocla_perso.cpp
#         dispocla.cpp
#         evdev-additions.xml
#         dispoled.c
#         evdev.c
#         evdev-ansi.c
#         evdev-ansi-menu.c
#         evdev-ansi-menu-sans.c
#         evdev-ansi-pur.c
#         evdev-ctrl.c
#         evdev-menu.c
#         evdev-menu-sans.c
#         evdev-win.c
#         evdev-win-sans.c
#
#   Les extensions .c, .cpp et .yml servent à la coloration syntaxique et
#   à faciliter l’ouverture sous Windows dans un souci d’interopérabilité.
#
# L’absence des booléens dans Bash est palliée par le recours aux comparaisons
# arithmétiques. Pour la lisibilité, 0 et 1 sont inversés en "vrai" et "faux".

introduction=0 # Pas faite.
function afficher {
	if [ "$introduction" -eq 0 ]; then
		echo -e "\n    Bienvenue dans l’installateur de dispositions de clavier Dispoclavier.\n"
		echo      '    En vérifiant brièvement l’existant avant de commencer, on peut noter :'
		introduction=1 # Faite.
	fi
	echo "$fichier $1."
}

function confirmation {
	read -n 1 -s -r -p "  Pour valider, appuyez sur une touche."
}

function installer_dispo {
	if [ "$renouveler" -eq 1 ]; then
		echo 'Réinstallation du fichier de redisposition de touches'
		echo '  en utilisant "sauvegarde/evdev.c".'
		sudo cp sauvegarde/evdev.c $X11/xkb/keycodes/evdev
		sudo chmod $permissions $X11/xkb/keycodes/evdev
	fi
	# Installer les types de touches.
	echo 'Installation des types de touches.'
	sudo cp installer/dispotypes.c $X11/xkb/types/dispotypes
	sudo cp $X11/xkb/types/complete $X11/xkb/types/complete-types-avant-dispoclavier
	sudo sed -i '/\};/i \ \ \ \ include "dispotypes"' $X11/xkb/types/complete
	sudo chmod $permissions $X11/xkb/types/complete
	# Installer le fichier de personnalisation s’il n’est pas déjà présent.
	if [ "$dispocla_perso" -eq 0 ]; then
		echo 'Installation du fichier de personnalisation inclus.'
		sudo cp installer/dispocla_perso.cpp $X11/xkb/symbols/dispocla_perso
		sudo chmod $permissions $X11/xkb/symbols/dispocla_perso
	else
		echo 'Confirmation de la présence d’un fichier de personnalisation.'
		echo 'Un fichier "dispocla_perso" est présent et reste bien en place.'
	fi
	# Installer les tableaux d’allocation de touches.
	echo 'Installation des dispositions de clavier.'
	sudo cp installer/dispocla.cpp $X11/xkb/symbols/dispocla
	sudo chmod $permissions $X11/xkb/symbols/dispocla
	# Désactiver l’écrasement du deuxième groupe vif.
	echo 'Désactivation de l’écrasement du deuxième groupe vif.'
	sudo cp $X11/xkb/rules/evdev $X11/xkb/rules/evdev-rules-avant-dispoclavier
	sudo sed -ri 's/(\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2)/\/\/\ \1/' $X11/xkb/rules/evdev
	sudo chmod $permissions $X11/xkb/rules/evdev
	# Installer les séquences et le contenu des touches mortes.
	echo 'Installation des séquences et du contenu des touches mortes.'
	sudo cp $X11/locale/en_US.UTF-8/Compose $X11/locale/en_US.UTF-8/Compose-avant-dispoclavier
	sudo chmod $permissions $X11/locale/en_US.UTF-8/Compose
	cat Compose.yml >> $X11/locale/en_US.UTF-8/Compose
	sudo chmod $permissions $X11/locale/en_US.UTF-8/Compose
	# Ajouter une extension au commutateur de dispositions.
	echo 'Ajout de ces dispositions de clavier dans la liste du commutateur.'
	sudo cp $X11/xkb/rules/evdev.xml $X11/xkb/rules/evdev-xml-rules-avant-dispoclavier.xml
	sudo sed -i '/<\/layoutList>/i <!-- ajouts-dispoclavier -->' $X11/xkb/rules/evdev.xml
	sudo sed -n '/<layout><!-- Dispoclavier/,/<\/layout><!-- FIN_Dispoclavier/p' installer/evdev-additions.xml > installer/evdev-additions-seules.xml
	sudo sed -i '/ajouts-dispoclavier/r installer/evdev-additions-seules.xml' $X11/xkb/rules/evdev.xml
	sudo sed -i '/ajouts-dispoclavier/d' $X11/xkb/rules/evdev.xml
	sudo chmod $permissions $X11/xkb/rules/evdev.xml
	# Installer l’allumage du témoin lumineux Arrêt défilement en mode ASCII.
	echo 'Rattachement du témoin lumineux Arrêt défilement au mode ASCII.'
	sudo cp installer/dispoled.c $X11/xkb/compat/dispoled
	sudo chmod $permissions $X11/xkb/compat/dispoled
	sudo cp $X11/xkb/compat/complete $X11/xkb/compat/complete-compat-avant-dispoclavier
	sudo sed -i '/\};/i \ \ \ \ include "dispoled"' $X11/xkb/compat/complete
	# Afficher un dernier message.
	if [ "$renouveler" -eq 1 ]; then
		echo -e "\n  ✅  Ces dispositions de clavier viennent d’être mises à jour."
		echo      '     Les nouveautés prendront effet dès la prochaine session.'
	else
		echo -e "\n  ✅  Ces dispositions de clavier viennent d’être installées."
		echo      '     Elles sont activables dès la prochaine session.'
		echo -e "\n     Les redispositions actuelles de touches ont été sauvegardées"
		echo      '         dans ~/.config/dispoclavier/keycodes/evdev.'
	fi
	echo -e "\n     Tous les retours d’expérience sont les bienvenus."
	echo      '     S’il manque quoi que ce soit, ou à tout autre propos relatif,'
	echo -e   "     n’hésitez pas à créer un rapport de bogue :\n"
	echo      '         https://github.com/dispoclavier/nouvel-azerty/issues'
	echo -e "\n     N’hésitez pas non plus à lancer une discussion :\n"
	echo      '         https://github.com/dispoclavier/nouvel-azerty/discussions'
	echo -e "\n\n                       Bonne utilisation !\n\n"
	confirmation
}

function supprimer_dispo {
	# Commencer par la saisie du mot de passe administrateur.
	sudo echo ''
	# Désinstaller le rattachement du témoin lumineux Arrêt défilement au mode ASCII.
	mkdir -p sauvegarde/archive
	cp $X11/xkb/compat/complete sauvegarde/archive/complete-compat.c
	if [ "$dispoled" -eq 1 ]; then
		echo 'Détachement du témoin lumineux Arrêt défilement du mode ASCII.'
		sudo sed -i '/include "dispoled"/d' $X11/xkb/compat/complete
		sudo mv $X11/xkb/compat/dispoled sauvegarde/archive/dispoled.c
	fi
	if [ "$complete_compat_avant" -eq 1 ]; then
		sudo mv $X11/xkb/compat/complete-compat-avant-dispoclavier sauvegarde/archive/complete-compat-avant.c
	fi
	# Désinstaller et sauvegarder le fichier pour redisposer des touches.
	echo 'Sauvegarde du fichier permettant de redisposer des touches.'
	cp $X11/xkb/keycodes/evdev sauvegarde/evdev.c
	mkdir -p ~/.config/dispoclavier/keycodes
	cp $X11/xkb/keycodes/evdev ~/.config/dispoclavier/keycodes/evdev
	if [ "$evdev_keycodes_avant" -eq 1 ]; then
		echo 'Désinstallation du fichier permettant de redisposer des touches.'
		cp $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier sauvegarde/evdev-keycodes-avant.c
		sudo mv $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier $X11/xkb/keycodes/evdev
		sudo chmod $permissions $X11/xkb/keycodes/evdev
	fi
	# Supprimer l’extension du commutateur de dispositions.
	cp $X11/xkb/rules/evdev.xml sauvegarde/archive/evdev-xml-rules.xml
	if [ "$rules_dispoclavier" -eq 2 ]; then
		echo 'Suppression de ces dispositions de clavier dans la liste du commutateur.'
		sudo sed -i '/<layout><!-- Dispoclavier/,/<\/layout><!-- FIN_Dispoclavier/d' $X11/xkb/rules/evdev.xml
	else
		echo 'Ces dispositions de clavier n’ont pas pu être supprimées dans la liste du commutateur.'
		if [ "$rules_dispoclavier" -eq 1 ]; then
			echo 'Il est nécessaire de les supprimer manuellement.'
		fi
	fi
	if [ "$evdev_xml_rules_avant" -eq 1 ]; then
		sudo mv $X11/xkb/rules/evdev-xml-rules-avant-dispoclavier.xml sauvegarde/archive/evdev-xml-rules-avant.xml
	fi
	# Désinstaller les séquences et le contenu des touches mortes.
	cp $X11/locale/en_US.UTF-8/Compose sauvegarde/archive/Compose.yml
	if [ "$xcompose_dispoclavier" -eq 2 ]; then
		echo 'Désinstallation des séquences et du contenu des touches mortes.'
		sudo sed -i '/START_additions_X\?Compose_Dispoclavier/,/END_additions_X\?Compose_Dispoclavier/d' $X11/locale/en_US.UTF-8/Compose
	else
		echo 'Les séquences et le contenu des touches mortes n’ont pas pu être désinstallés.'
		if [ "$xcompose_dispoclavier" -eq 1 ]; then
			echo 'Il est nécessaire de les supprimer manuellement.'
		fi
	fi
	if [ "$xcompose_avant" -eq 1 ]; then
		sudo mv $X11/locale/en_US.UTF-8/Compose-avant-dispoclavier sauvegarde/archive/Compose-avant.yml
	fi
	# Réactiver l’écrasement du deuxième groupe vif.
	sudo cp $X11/xkb/rules/evdev sauvegarde/archive/evdev-rules.c
	if [ "$rules_n_ecrase_pas" -eq 1 ]; then
		echo 'Réactivation de l’écrasement du deuxième groupe vif.'
		sudo sed -ri 's/\/\/\s*(\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2)/\1/' $X11/xkb/rules/evdev
	fi
	if [ "$evdev_rules_avant" -eq 1 ]; then
		sudo mv $X11/xkb/rules/evdev-rules-avant-dispoclavier sauvegarde/archive/evdev-rules-avant.c
	fi
	# Désinstaller le fichier de personnalisation de dispositions.
	if [ "$dispocla_perso" -eq 1 ] && [ "$confirmer_suppression" -eq 1 ]; then
		echo 'Sauvegarde des personnalisations de dispositions de clavier.'
		mkdir -p ~/.config/dispoclavier/symbols
		cp $X11/xkb/symbols/dispocla_perso ~/.config/dispoclavier/symbols/dispocla_perso
		echo 'Désinstallation des personnalisations de dispositions de clavier.'
		sudo mv $X11/xkb/symbols/dispocla_perso sauvegarde/dispocla_perso.cpp
	else
		echo 'Confirmation de la présence d’un fichier de personnalisation.'
		echo 'Un fichier "dispocla_perso" est présent et reste bien en place.'
	fi
	# Désinstaller les tableaux d’allocation de touches.
	if [ "$dispocla" -eq 1 ]; then
		echo 'Désinstallation des dispositions de clavier.'
		sudo mv $X11/xkb/symbols/dispocla sauvegarde/archive/dispocla.cpp
	fi
	# Désinstaller les types de touches.
	cp $X11/xkb/types/complete sauvegarde/archive/complete-types.c
	if [ "$dispotypes" -eq 1 ]; then
		echo 'Désinstallation des types de touches.'
		sudo sed -i '/include "dispotypes"/d' $X11/xkb/types/complete
		sudo mv $X11/xkb/types/dispotypes sauvegarde/archive/dispotypes.c
	fi
	if [ "$complete_types_avant" -eq 1 ]; then
		sudo mv $X11/xkb/types/complete-types-avant-dispoclavier sauvegarde/archive/complete-types-avant.c
	fi
	# Pour rendre modifiables les fichiers sauvegardés.
	sudo chmod --recursive 666 sauvegarde
	if [ "$confirmer_suppression" -eq 1 ]; then
		# Afficher un dernier message.
		echo -e "\n  ✅  Ces dispositions de clavier viennent d’être désinstallées."
		echo -e "\n  ⚠  Les redispositions de touches ont été sauvegardées"
		echo      '         à côté dans sauvegarde/evdev.c'
		echo      '         et dans ~/.config/dispoclavier/keycodes/evdev.'
		echo -e "\n  ⚠  Les personnalisations de dispositions ont été sauvegardées"
		echo      '         à côté dans sauvegarde/dispocla_perso.cpp'
		echo      '         et dans ~/.config/dispoclavier/symbols/dispocla_perso.'
		echo -e "\n     Tous les retours d’expérience sont les bienvenus."
		echo -e "\n     N’hésitez pas à créer un rapport de bogue :\n"
		echo      '         https://github.com/dispoclavier/nouvel-azerty/issues'
		echo -e "\n     N’hésitez pas non plus à lancer une discussion :\n"
		echo      '         https://github.com/dispoclavier/nouvel-azerty/discussions'
		echo -e "\n\n             Merci d’avoir utilisé Dispoclavier.\n\n"
		confirmation
	fi
}

# Vérifier les fichiers à installer.
manque=0 # Il ne manque rien.
sous_variantes=1 # Les sous-variantes sont au complet.
faux=0 # Tout est bon.
fichier="Compose.yml"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
else
	if ! grep -q 'START_additions_X\?Compose_Dispoclavier' $fichier || ! grep -q 'END_additions_X\?Compose_Dispoclavier' $fichier; then
		faux=1
		afficher 'est défectueux'
	fi
fi
fichier="installer/dispocla_perso.cpp"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
fi
fichier="installer/dispocla.cpp"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
fi
fichier="installer/dispoled.c"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
fi
fichier="installer/dispotypes.c"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
fi
fichier="installer/evdev.c"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
fi
fichier="installer/evdev-additions.xml"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
else
	if ! grep -qP '<layout><!-- Dispoclavier.*-->' $fichier || ! grep -qP '<\/layout><!-- FIN_Dispoclavier.*-->' $fichier; then
		faux=1
		afficher 'est défectueux'
	fi
fi
fichier="installer/evdev-ansi.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-ansi-menu.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-ansi-menu-sans.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-ansi-pur.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-ctrl.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-menu.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-menu-sans.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-win.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
fichier="installer/evdev-win-sans.c"
if [ ! -f "$fichier" ]; then
	sous_variantes=0
	afficher 'manque'
fi
# Vérifier l’environnement.
fonctionne=1 # XKB est fonctionnel.
installation=1 # Dispoclavier est installé correctement.
trace=0 # Il n’y a pas de trace d’installation.
X11="/usr/share/X11"
# XCompose.
dossier="$X11/locale/en_US.UTF-8"
fichier="$dossier/Compose"
xcompose_dispoclavier=0
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if ! grep -q 'START_additions_X\?Compose_Dispoclavier' $fichier && ! grep -q 'END_additions_X\?Compose_Dispoclavier' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	else
		trace=1
		xcompose_dispoclavier=2
		if ! ( grep -q 'START_additions_X\?Compose_Dispoclavier' $fichier && grep -q 'END_additions_X\?Compose_Dispoclavier' $fichier ); then
			installation=0
			afficher 'est défectueux'
			xcompose_dispoclavier=1
		else
			afficher 'contient Dispoclavier'
		fi
	fi
fi
fichier="$dossier/Compose-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	xcompose_avant=1
else
	xcompose_avant=0
fi
# Keycodes.
dossier="$X11/xkb/keycodes"
fichier="$dossier/evdev"
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
fi
fichier="$dossier/evdev-keycodes-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	evdev_keycodes_avant=1
else
	evdev_keycodes_avant=0
fi
# Rules.
## Rules/evdev.
dossier="$X11/xkb/rules"
fichier="$dossier/evdev"
rules_n_ecrase_pas=0
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if ! grep -qP '\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2' $fichier; then
		fonctionne=0
		afficher 'est incomplet'
	fi
	if ! grep -qP '\/\/\s*\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2' $fichier; then
		installation=0
		afficher 'écrase le deuxième groupe vif'
	else
		rules_n_ecrase_pas=1
		afficher 'n’écrase pas le deuxième groupe vif'
	fi
fi
fichier="$dossier/evdev-rules-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	evdev_rules_avant=1
else
	evdev_rules_avant=0
fi
## Rules/evdev.xml.
fichier="$dossier/evdev.xml"
rules_dispoclavier=0
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if ! grep -qP '<layout><!-- Dispoclavier.*-->' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	else
		trace=1
		rules_dispoclavier=2
		if ! grep -qP '<\/layout><!-- FIN_Dispoclavier.*-->' $fichier; then
			installation=0
			afficher 'est défectueux'
			rules_dispoclavier=1
		else
			afficher 'contient Dispoclavier'
		fi
	fi
fi
fichier="$dossier/evdev-xml-rules-avant-dispoclavier.xml"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	evdev_xml_rules_avant=1
else
	evdev_xml_rules_avant=0
fi
# Symbols.
## Personnalisation.
dossier="$X11/xkb/symbols"
fichier="$dossier/dispocla_perso"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	dispocla_perso=1
else
	installation=0
	dispocla_perso=0
fi
## Dispositions.
fichier="$dossier/dispocla"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	dispocla=1
else
	installation=0
	dispocla=0
fi
# Types.
dossier="$X11/xkb/types"
fichier="$dossier/dispotypes"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	dispotypes=1
	fichier="$dossier/complete"
	if [ -f "$fichier" ]; then
		if ! grep -qP 'include\s*"dispotypes"' $fichier; then
			installation=0
			afficher 'n’inclut pas "dispotypes"'
		else
			afficher 'inclut "dispotypes"'
		fi
	else
		fonctionne=0
	fi
else
	installation=0
	dispotypes=0
fi
fichier="$dossier/complete-types-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	complete_types_avant=1
else
	complete_types_avant=0
fi
# Compat.
dossier="$X11/xkb/compat"
fichier="$dossier/dispoled"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	dispoled=1
	fichier="$dossier/complete"
	if [ -f "$fichier" ]; then
		if ! grep -qP 'include\s*"dispoled"' $fichier; then
			installation=0
			afficher 'n’inclut pas "dispoled"'
		else
			afficher 'inclut "dispoled"'
		fi
	else
		fonctionne=0
	fi
else
	installation=0
	dispoled=0
fi
fichier="$dossier/complete-compat-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	complete_compat_avant=1
else
	complete_compat_avant=0
fi

# À condition que l’environnement soit comme attendu.
if [ "$fonctionne" -eq 1 ]; then
	# À condition que Dispoclavier n’ait pas déjà été installé.
	if [ "$installation" -eq 0 ] && [ "$trace" -eq 0 ]; then
		renouveler=0
		# À condition que les fichiers à installer soient au complet et conformes.
		if [ "$manque" -eq 0 ] && [ "$faux" -eq 0 ]; then
			if [ "$renouveler" -eq 0 ]; then
				# Vérifier le système de saisie au clavier.
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
							echo      '    XIM a maintenant été sélectionnée.'
						;;
					esac
				fi
				# Installer ces dispositions de clavier.
				echo -e "\n  ❓  Souhaitez-vous installer ces dispositions de clavier ?"
				echo -e "\n       Pour les installer, appuyez sur Entrée."
				echo      '       Pour quitter, tapez q ou p puis Entrée.'
				read -p   '    ' reponse
				case $reponse in
					[pPqQ])
						exit
					;;
					*)
						# Installer le fichier permettant de redisposer des touches.
						sudo cp $X11/xkb/keycodes/evdev $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
						fait=0
						if [ -f "sauvegarde/evdev.c" ]; then
							echo -e "\n  ❓  Souhaitez-vous réinstaller les redispositions de touches"
							echo      '       sauvegardées ici à côté dans sauvegarde/evdev.c ?'
							echo -e "\n       Pour les réinstaller, appuyez sur Entrée."
							echo      '       Pour les ignorer, tapez i ou p puis Entrée.'
							echo      '       Pour quitter, tapez q puis Entrée.'
							prem=1
							read -p   '    ' repo
							case $repo in
								[iIpP])
									echo '    Le fichier "sauvegarde/evdev.c" a été ignoré.'
								;;
								[qQ])
									sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
									exit
								;;
								*)
									echo 'Réinstallation du fichier de redisposition de touches'
									echo '  en utilisant "sauvegarde/evdev.c".'
									sudo cp sauvegarde/evdev.c $X11/xkb/keycodes/evdev
									fait=1
								;;
							esac
						else
							prem=0
						fi
						if [ -f "$HOME/.config/dispoclavier/keycodes/evdev" ] && [ "$fait" -eq 0 ]; then
							if [ "$prem" -eq 1 ]; then
								echo -e "\n  ❓  Ou souhaitez-vous réinstaller les redispositions de touches"
								echo      '       sauvegardées, elles, dans ~/.config/dispoclavier/keycodes/ ?'
								echo -e "\n       Pour les réinstaller, appuyez sur Entrée."
								echo      '       Pour les ignorer aussi, tapez i ou p puis Entrée.'
							else
								echo -e "\n  ❓  Souhaitez-vous réinstaller les redispositions de touches"
								echo      '       sauvegardées dans ~/.config/dispoclavier/keycodes/ ?'
								echo -e "\n       Pour les réinstaller, appuyez sur Entrée."
								echo      '       Pour les ignorer, tapez i ou p puis Entrée.'
							fi
							echo      '       Pour quitter, tapez q puis Entrée.'
							read -p   '    ' repo
							case $repo in
								[iIpP])
									echo '    Le fichier "~/.config/dispoclavier/keycodes/evdev" a été ignoré.'
								;;
								[qQ])
									sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
									exit
								;;
								*)
									echo 'Réinstallation du fichier de redisposition de touches'
									echo '  en utilisant "~/.config/dispoclavier/keycodes/evdev".'
									sudo cp ~/.config/dispoclavier/keycodes/evdev $X11/xkb/keycodes/evdev
									fait=1
								;;
							esac
						fi
						if [ "$fait" -eq 0 ] && [ "$sous_variantes" -eq 1 ]; then
							echo -e "\n  ❓  Souhaitez-vous redisposer les touches AltFr ou"
							echo      '         Effacement arrière (Retour arrière) ?'
							echo -e "\n       Pour redisposer, tapez r ou o puis Entrée."
							echo      '       Pour ne rien redisposer, appuyez sur Entrée.'
							echo      '       Pour quitter, tapez q puis Entrée.'
							read -p   '    ' repo
							case $repo in
								[oOrR])
									suffixe=''
									echo -e "\n  ❓  Souhaitez-vous redisposer la touche AltFr ?"
									echo -e "\n  ⚠  Normalement, AltFr se trouve entre la touche"
									echo      '     Majuscule gauche et celle du W de l’AZERTY.'
									echo -e "\n       Pour la redisposer, tapez r ou o puis Entrée."
									echo      '       Pour ne pas la redisposer, appuyez sur Entrée.'
									echo      '       Pour quitter, tapez q puis Entrée.'
									read -p   '    ' rep
									ansipur=0
									case $rep in
										[oOrR])
											echo -e "\n  ⚠  La touche AltFr peut être disposée sur la touche"
											echo      '     de Verrouillage des Capitales. VerrCap sera alors'
											echo      '     disposée sur la touche Contrôle droite. Celle-ci'
											echo      '     peut être une vraie touche Contrôle (clavier ANSI)'
											echo      '     ou être de fait la touche [<>] (clavier AZERTY ANSI).'
											echo -e "\n  ❓  Souhaitez-vous disposer la touche AltFr pour un :"
											echo      '       a   clavier ANSI pur (sans autres options) ?'
											echo      '       h   clavier ANSI hybride disposé en AZERTY ?'
											echo      '       i   clavier ISO avec la touche [<>] à côté de Maj ?'
											echo      '       Pour laisser tomber, appuyez sur Entrée.'
											read -p   '    ' re
											case $re in
												[aA])
													echo 'Installation du fichier de redisposition de touches pour'
													echo '  un clavier ANSI pur, sans autres options de redisposition.'
													echo '  La touche d’Effacement arrière peut toujours être redisposée'
													echo '  manuellement dans installer/evdev.c ou dans sauvegarde/evdev.c.'
													sudo cp installer/evdev-ansi-pur.c $X11/xkb/keycodes/evdev
													ansipur=1
													fait=1
												;;
												[hH])
													suffixe="-ansi"
												;;
												[iI])
													echo '    La touche AltFr restera entre Maj et W.'
												;;
												*)
													echo '    La touche AltFr restera sur la touche [<>].'
												;;
											esac
										;;
										[qQ])
											sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
											exit
										;;
										*)
											echo '    La touche AltFr restera sur la touche [<>].'
										;;
									esac
									if [ "$ansipur" -eq 0 ]; then
										echo -e "\n  ❓  Souhaitez-vous redisposer Effacement arrière ?"
										echo -e "\n       Pour la redisposer, tapez r ou o puis Entrée."
										echo      '       Pour ne pas la redisposer, appuyez sur Entrée.'
										echo      '       Pour quitter, tapez q puis Entrée.'
										read -p   '    ' rep
										case $rep in
											[oOrR])
												echo -e "\n  ⚠  La touche d’Effacement arrière peut être redisposée"
												if [ "$suffixe" == "-ansi" ]; then
													echo      '     sur la touche Menu.'
												else
													echo      '     sur la touche Windows droite, sur la touche Menu,'
													echo      '     ou sur la touche Contrôle droite.'
												fi
												echo -e "\n  ❓  Souhaitez-vous disposer l’Effacement arrière sur :"
												echo      '       m   Menu ?'
												if [ ! "$suffixe" == "-ansi" ]; then
													echo      '       w   Windows droite ?'
													echo      '       c   Contrôle droite ?'
												fi
												echo      '       Pour laisser tomber, appuyez sur Entrée.'
												read -p   '    ' re
												case $re in
													[cC])
														if [ ! "$suffixe" == "-ansi" ]; then
															suffixe+="-ctrl"
														else
															echo '    Pour les agencements ANSI hybrides en AZERTY, l’option'
															echo '    Effacement arrière sur Contrôle droite n’est pas disponible,'
															echo '    car ce sont des claviers de portable sans Contrôle droite.'
														fi
													;;
													[mM])
														suffixe+="-menu"
														echo -e "\n  ⚠  La touche Effacement arrière servira de touche Menu,"
														echo      '     mais cela peut ne pas être souhaitable.'
														echo -e "\n  ❓  Souhaitez-vous redisposer la touche Effacement arrière"
														echo      '       sans redisposer aussi la touche Menu ?'
														echo -e "\n       Pour ne pas redisposer Menu, tapez n ou s puis Entrée."
														echo      '       Pour redisposer Menu, appuyez sur Entrée.'
														echo      '       Pour quitter, tapez q puis Entrée.'
														read -p   '    ' r
														case $r in
															[nNsS])
																suffixe+="-sans"
																echo '    La touche Menu ne sera pas redisposée.'
															;;
															[qQ])
																sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
																exit
															;;
															*)
																echo '    La touche Menu sera redisposée.'
															;;
														esac
													;;
													[wW])
														if [ ! "$suffixe" == "-ansi" ]; then
															suffixe+="-win"
															echo -e "\n  ⚠  L’utilisation de Windows droite comme Effacement arrière"
															echo      '     amène le risque d’ouvrir accidentellement le menu contextuel.'
															echo -e "\n  ❓  Souhaitez-vous désactiver la touche Menu ?"
															echo -e "\n       Pour la désactiver, tapez d ou o puis Entrée."
															echo      '       Pour ne pas la désactiver, appuyez sur Entrée.'
															echo      '       Pour quitter, tapez q puis Entrée.'
															read -p   '    ' r
															case $r in
																[dDoO])
																	suffixe+="-sans"
																	echo '    La touche Menu sera désactivée.'
																;;
																[qQ])
																	sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
																	exit
																;;
																*)
																	echo '    La touche Menu restera active.'
																;;
															esac
														else
															echo '    Pour les agencements ANSI hybrides en AZERTY, l’option'
															echo '    Effacement arrière sur Windows droite n’est pas disponible,'
															echo '    car ce sont des claviers de portable sans Windows droite.'
														fi
													;;
													*)
													;;
												esac
											;;
											[qQ])
												sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
												exit
											;;
											*)
												echo '    La touche d’Effacement arrière restera en haut.'
											;;
										esac
										echo -e "\nInstallation du fichier de redisposition de touches."
										sudo cp installer/evdev$suffixe.c $X11/xkb/keycodes/evdev
										fait=1
									fi
								;;
								[qQ])
									sudo rm $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
									exit
								;;
								*)
								;;
							esac
						fi
						if [ "$fait" -eq 0 ]; then
							echo 'Installation du fichier générique de redisposition de touches.'
							sudo cp installer/evdev.c $X11/xkb/keycodes/evdev
						fi
						# Sauvegarder le fichier installé de redisposition de touches.
						echo 'Sauvegarde des redispositions de touches.'
						mkdir -p ~/.config/dispoclavier/keycodes
						cp $X11/xkb/keycodes/evdev ~/.config/dispoclavier/keycodes/evdev
						# Installer.
						installer_dispo
					;;
				esac
			fi
		else
			echo -e "\n     Ces dispositions de clavier ne sont pas installées, mais"
			echo      '     il n’est pas possible de les installer maintenant :'
			if [ "$manque" -eq 1 ]; then
				echo      '     Les fichiers à installer ne sont pas au complet.'
			fi
			if [ "$faux" -eq 1 ]; then
				echo      '     Les fichiers à installer présentent des non-conformités.'
			fi
			echo -e "\n     Le mieux est de télécharger un nouveau paquetage"
			echo      '     sur la page de la version la plus récente :'
			echo      '     https://github.com/dispoclavier/nouvel-azerty/releases/latest'
			echo -e "\n\n         Avec toutes nos excuses pour ce désagrément.\n\n"
			confirmation
		fi
	else
		if [ "$installation" -eq 1 ]; then
			echo -e "\n     Ces dispositions de clavier sont bien installées."
			echo -e "\n  ❓  Souhaitez-vous les mettre à jour ?"
		elif [ "$trace" -eq 1 ]; then
			echo -e "\n     Ces dispositions de clavier ne sont pas bien installées, mais"
			echo      '     il y a des traces d’installation.'
			echo -e "\n     Le mieux est d’essayer d’en désinstaller autant que possible,"
			echo      '     puis de réinstaller ces dispositions de clavier le cas échéant,'
			echo      '     en relançant ce script dans la foulée ou plus tard.'
			echo -e "\n  ⚠  Les redispositions de touches seront sauvegardées dans :"
			echo      '         ~/.config/dispoclavier/keycodes/evdev'
			echo      '     Et ici à côté dans "sauvegarde/", où tout sera archivé.'
		fi
		echo -e "\n       Pour mettre à jour, appuyez sur Entrée."
		echo      '       Pour désinstaller, tapez d puis Entrée.'
		echo      '       Pour quitter, tapez q ou p puis Entrée.'
		read -p   '    ' reponse
		case $reponse in
			[pPqQ])
				exit
			;;
			[dD])
				confirmer_suppression=1
				supprimer_dispo
			;;
			*)
				confirmer_suppression=0
				supprimer_dispo
				renouveler=1
				installer_dispo
			;;
		esac
	fi
else
	echo -e "\n     Sous ce système, ce script ne peut pas installer ces dispositions"
	echo      '     de clavier, car XKB et XCompose ne se présentent pas comme attendu.'
	echo -e "\n     Peut-être serait-il envisageable d’installer ces dispositions de"
	echo      '     clavier manuellement selon le mode d’emploi figurant dans l’en-tête'
	echo      '     du fichier "Compose.yml", qui va dans le dossier personnel, et dans'
	echo      '     chacun des fichiers qui se trouvent dans le dossier "installer/"'.
	echo -e "\n\n         Avec toutes nos excuses pour ce désagrément.\n\n"
	confirmation
fi

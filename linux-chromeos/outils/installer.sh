#!/bin/bash
#                       Date : 2024-06-15T1225+0200
#                    Fichier : installer.sh
#                   Encodage : UTF-8
#                       Type : script Bash
#                Description : Installe des dispositions de clavier basées sur XKB et XCompose.
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
#
#   Utilisation
#
#   • En ligne de commande :
#
#     ◦ Vérifier le contenu du script ci-dessous ;
#     ◦ Ouvrir un terminal dans le même dossier ;
#     ◦ Rendre ce script exécutable par `chmod +x installer.sh` ;
#     ◦ Lancer le script par la commande `./installer.sh`.
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
# Le manque de booléens dans Bash est pallié par le recours à des comparaisons arithmétiques.
# C’est pourquoi on peut tout aussi bien inverser 0 et 1 (false dans Bash) pour la lisibilité.
introduction=0 # Pas faite.
function afficher {
	if [ "$introduction" -eq 0 ]; then
		echo "    Bienvenue dans l’installateur de dispositions de clavier Dispoclavier."
		echo "    En vérifiant brièvement l’existant avant de commencer, on peut noter :"
		introduction=1 # Faite.
	fi
	echo "$fichier $1."
}

# Vérifier les fichiers à installer.
manque=0 # Il ne manque rien.
faux=0 # Tout est bon.
fichier="Compose.yml"
if [ ! -f "$fichier" ]; then
	manque=1
	afficher 'manque'
else
	if ! grep -q 'START_additions_Compose_Dispoclavier' $fichier || ! grep -q 'END_additions_Compose_Dispoclavier' $fichier; then
		faux=1
		afficher 'est défectueux'
	fi
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
# Vérifier l’environnement.
fonctionne=1 # XKB est fonctionnel.
installation=1 # Dispoclavier est installé correctement.
trace=0 # Il n’y a pas de trace d’installation.
X11="/usr/share/X11"
# Compose.
dossier="$X11/locale/en_US.UTF-8"
fichier="$dossier/Compose"
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if ! grep -q 'START_additions_Compose_Dispoclavier' $fichier && ! grep -q 'END_additions_Compose_Dispoclavier' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	else
		trace=1
		if ! ( grep -q 'START_additions_Compose_Dispoclavier' $fichier && grep -q 'END_additions_Compose_Dispoclavier' $fichier ); then
			installation=0
			afficher 'est défectueux'
		fi
	fi
fi
fichier="$dossier/Compose-avant-dispoclavier"
if [ -f "$fichier" ]; then
	trace=1
	afficher 'est présent'
	compose_avant=1
else
	compose_avant=0
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
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if ! grep -qP '<layout><!-- Dispoclavier.*-->' $fichier || ! grep -qP '<\/layout><!-- FIN_Dispoclavier.*-->' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	else
		trace=1
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
dossier="$X11/xkb/symbols"
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
else
	installation=0
	dispotypes=0
fi
fichier="$dossier/complete"
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if [ "$dispotypes" -eq 1 ] && ! grep -q 'include "dispotypes"' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	fi
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
else
	installation=0
	dispoled=0
fi
fichier="$dossier/complete"
if [ ! -f "$fichier" ]; then
	fonctionne=0
	afficher 'manque'
else
	if [ "$dispoled" -eq 1 ] && ! grep -q 'include "dispoled"' $fichier; then
		installation=0
		afficher 'ne contient pas Dispoclavier'
	fi
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
		# À condition que les fichiers à installer soient au complet et conformes.
		if [ "$manque" -eq 0 ] && [ "$faux" -eq 0 ]; then
			# Vérifier le système de saisie au clavier.
			if ! im-config -m | grep -q 'xim'; then
				echo -e "\n  ⚠  Ces dispositions de clavier fonctionnent uniquement"
				echo      "     si le système de saisie au clavier est XIM."
				echo -e "\n  ⚠  Sans la X Window Input Method, toutes les séquences"
				echo      "     multi-caractères sont en panne."
				echo      "     Or sans séquences multi-caractères, ces dispositions"
				echo      "     semi-automatiques ne peuvent être opérationnelles."
				echo      "     Même les lettres composées qui sont dans les touches"
				echo      "     mortes ne peuvent être saisies, étant en panne."
				echo -e "\n     XIM une fois sélectionnée, elle sera active"
				echo      "     dès la prochaine session."
				echo -e "\n  ⚠  Avant d’installer ces dispositions de clavier,"
				echo      "     le mieux est de commencer par activer XIM."
				echo -e "\n       Pour activer XIM, appuyez sur Entrée."
				echo      "       Pour quitter, tapez Q ou N puis Entrée."
				read -p   "    " reponse
				case $reponse in
					[qQnN])
						exit
					;;
					*)
						# Basculer vers le système de saisie au clavier XIM.
						im-config -n xim
						echo      "     XIM a maintenant été sélectionné."
					;;
				esac
			fi
			# Installer ces dispositions de clavier.
			echo -e "\n  ❓  Souhaitez-vous installer ces dispositions de clavier ?"
			echo -e "\n       Pour installer, tapez I ou O puis Entrée."
			echo      "       Pour quitter, appuyez sur Entrée."
			read -p   "    " reponse
			case $reponse in
				[iIoO])
					# Installer le fichier permettant de redisposer des touches.
					sudo cp $X11/xkb/keycodes/evdev $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier
					fait=0
					# Vérifier s’il y a une sauvegarde à côté.
					if [ -f "sauvegarde/evdev.c" ]; then
						echo -e "\n  ❓  Souhaitez-vous réinstaller les redispositions de touches"
						echo      "       sauvegardées ici à côté dans sauvegarde/evdev.c ?"
						echo -e "\n       Pour les réinstaller, tapez S puis Entrée."
						echo      "       Pour les ignorer, appuyez sur Entrée."
						read -p   "    " reponse
						case $reponse in
							[sS])
								echo "Réinstallation du fichier permettant de redisposer des touches."
								sudo cp sauvegarde/evdev.c $X11/xkb/keycodes/evdev
								fait=1
							;;
							*)
							;;
						esac
					fi
					# Vérifier s’il y a une sauvegarde dans le dossier de configurations.
					if [ -e "$HOME/.config/dispoclavier/keycodes/evdev" ] && [ "$fait" -eq 0 ]; then
						echo -e "\n  ❓  Souhaitez-vous réinstaller les redispositions de touches"
						echo      "       sauvegardées dans ~/.config/dispoclavier/keycodes/ ?"
						echo -e "\n       Pour les réinstaller, tapez C puis Entrée."
						echo      "       Pour les ignorer, appuyez sur Entrée."
						read -p   "    " reponse
						case $reponse in
							[cC])
								echo "Réinstallation du fichier permettant de redisposer des touches."
								sudo cp ~/.config/dispoclavier/keycodes/evdev $X11/xkb/keycodes/evdev
								fait=1
							;;
							*)
							;;
						esac
					fi
					if [ "$fait" -eq 0 ]; then
						echo "Installation du fichier générique de redisposition des touches."
						sudo cp installer/evdev.c $X11/xkb/keycodes/evdev
					fi
					# Installer les types de touches.
					echo "Installation des types de touches."
					sudo cp installer/dispotypes.c $X11/xkb/types/dispotypes
					sudo cp $X11/xkb/types/complete $X11/xkb/types/complete-types-avant-dispoclavier
					sudo sed -i '/\};/i \ \ \ \ include "dispotypes"' $X11/xkb/types/complete
					# Installer les tableaux d’allocation de touches.
					echo "Installation des tableaux d’allocation de touches."
					sudo cp installer/dispocla.cpp $X11/xkb/symbols/dispocla
					# Désactiver l’écrasement du deuxième groupe vif.
					echo "Désactivation de l’écrasement du deuxième groupe vif."
					sudo cp $X11/xkb/rules/evdev $X11/xkb/rules/evdev-rules-avant-dispoclavier
					sudo sed -ri 's/(\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2)/\/\/\ \1/' $X11/xkb/rules/evdev
					# Installer les séquences et le contenu des touches mortes.
					echo "Installation des séquences et du contenu des touches mortes."
					sudo cp $X11/locale/en_US.UTF-8/Compose $X11/locale/en_US.UTF-8/Compose-avant-dispoclavier
					sudo chmod 666 $X11/locale/en_US.UTF-8/Compose
					cat Compose.yml >> $X11/locale/en_US.UTF-8/Compose
					sudo chmod 644 $X11/locale/en_US.UTF-8/Compose
					# Ajouter une extension au commutateur de dispositions.
					echo "Ajout dans le répertoire du commutateur de dispositions de clavier."
					sudo cp $X11/xkb/rules/evdev.xml $X11/xkb/rules/evdev-xml-rules-avant-dispoclavier.xml
					sudo sed -i '/<\/layoutList>/i <!-- ajouts-dispoclavier -->' $X11/xkb/rules/evdev.xml
					sudo sed -n '/<layout><!-- Dispoclavier/,/<\/layout><!-- FIN_Dispoclavier/p' installer/evdev-additions.xml > installer/evdev-additions-seules.xml
					sudo sed -i '/ajouts-dispoclavier/r installer/evdev-additions-seules.xml' $X11/xkb/rules/evdev.xml
					sudo sed -i '/ajouts-dispoclavier/d' $X11/xkb/rules/evdev.xml
					# Installer le témoin lumineux Arrêt défilement pour le mode ASCII.
					echo "Rattachement du témoin lumineux Arrêt défilement au mode ASCII."
					sudo cp installer/dispoled.c $X11/xkb/compat/dispoled
					sudo cp $X11/xkb/compat/complete $X11/xkb/compat/complete-compat-avant-dispoclavier
					sudo sed -i '/\};/i \ \ \ \ include "dispoled"' $X11/xkb/compat/complete
					# Afficher un dernier message.
					echo -e "\n  ✅  Ces dispositions de clavier viennent d’être installées."
					echo      "     Elles sont activables dès la prochaine session."
					echo      "     Tous les retours d’expérience sont les bienvenus."
					echo      "     S’il manque quoi que ce soit, ou à tout autre sujet relatif,"
					echo      "     n’hésitez pas à créer un rapport de bogue :"
					echo      "     https://github.com/dispoclavier/nouvel-azerty/issues"
					echo      "     N’hésitez pas non plus à lancer une discussion :"
					echo      "     https://github.com/dispoclavier/nouvel-azerty/discussions"
					echo -e   "             Bonne utilisation !\n"
				;;
				*)
					exit
				;;
			esac
		else
			echo -e "\n     Ces dispositions de clavier ne sont pas installées, mais"
			echo      "     il n’est pas possible de les installer maintenant :"
			if [ "$manque" -eq 1 ]; then
				echo      "     Les fichiers à installer ne sont pas au complet."
			fi
			if [ "$faux" -eq 1 ]; then
				echo      "     Les fichiers à installer présentent des non-conformités."
			fi
			echo      "     Le mieux est de télécharger un nouveau paquetage"
			echo      "     sur la page de la version la plus récente :"
			echo      "     https://github.com/dispoclavier/nouvel-azerty/releases/latest"
			echo -e   "     Avec toutes nos excuses pour ce désagrément.\n"
		fi
	else
		if [ "$installation" -eq 1 ]; then
			echo -e "\n     Ces dispositions de clavier étant déjà installées,"
			echo      "     le mieux est de les désinstaller, quitte à les réinstaller"
			echo      "     par la suite avec tous les fichiers à jour. Les redispositions"
			echo      "     de touches seront sauvegardées dans les configurations :"
			echo      "     ~/.config/dispoclavier/keycodes/evdev"
			echo      "     Et aussi ici à côté, où tout le reste sera pareillement archivé."
		elif [ "$trace" -eq 1 ]; then
			echo -e "\n     Ces dispositions de clavier ne sont pas bien installées, mais"
			echo      "     il y a des traces d’installation. Le mieux est de tout désinstaller,"
			echo      "     puis éventuellement de réinstaller le tout correctement plus tard."
		fi
		echo -e "\n  ❓  Souhaitez-vous désinstaller ces dispositions de clavier ?"
		echo -e "\n       Pour désinstaller, tapez D ou O puis Entrée."
		echo      "       Pour quitter, appuyez sur Entrée."
		read -p   "    " reponse
		case $reponse in
			[dDoO])
				# Désinstaller le témoin lumineux Arrêt défilement pour le mode ASCII.
				mkdir -p sauvegarde/archive
				cp $X11/xkb/compat/complete sauvegarde/archive/complete-compat.c
				sudo sed -i '/include "dispoled"/d' $X11/xkb/compat/complete
				echo "Détachement du témoin lumineux Arrêt défilement du mode ASCII."
				if [ "$complete_compat_avant" -eq 1 ]; then
					sudo mv $X11/xkb/compat/complete-compat-avant-dispoclavier sauvegarde/archive/complete-compat-avant.c
				fi
				if [ "$dispoled" -eq 1 ]; then
					sudo mv $X11/xkb/compat/dispoled sauvegarde/archive/dispoled.c
				fi
				# Désinstaller et sauvegarder le fichier pour redisposer des touches.
				echo "Désinstallation et sauvegarde du fichier permettant de redisposer des touches."
				cp $X11/xkb/keycodes/evdev sauvegarde/evdev.c
				mkdir -p ~/.config/dispoclavier/keycodes
				cp $X11/xkb/keycodes/evdev ~/.config/dispoclavier/keycodes/evdev
				if [ "$evdev_keycodes_avant" -eq 1 ]; then
					cp $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier sauvegarde/evdev-keycodes-avant.c
					sudo mv $X11/xkb/keycodes/evdev-keycodes-avant-dispoclavier $X11/xkb/keycodes/evdev
				fi
				# Supprimer l’extension du commutateur de dispositions.
				echo "Suppression dans le répertoire du commutateur de dispositions de clavier."
				cp $X11/xkb/rules/evdev.xml sauvegarde/archive/evdev-xml-rules.xml
				if [ "$evdev_xml_rules_avant" -eq 1 ]; then
					sudo mv $X11/xkb/rules/evdev-xml-rules-avant-dispoclavier.xml sauvegarde/archive/evdev-xml-rules-avant.xml
				fi
				sudo sed -i '/<layout><!-- Dispoclavier/,/<\/layout><!-- FIN_Dispoclavier/d' $X11/xkb/rules/evdev.xml
				# Désinstaller les séquences et le contenu des touches mortes.
				echo "Désinstallation des séquences et du contenu des touches mortes."
				cp $X11/locale/en_US.UTF-8/Compose sauvegarde/archive/Compose.yml
				sudo sed -i '/START_additions_Compose_Dispoclavier/,/END_additions_Compose_Dispoclavier/d' $X11/locale/en_US.UTF-8/Compose
				if [ "$compose_avant" -eq 1 ]; then
					sudo mv $X11/locale/en_US.UTF-8/Compose-avant-dispoclavier sauvegarde/archive/Compose-avant.yml
				fi
				# Réactiver l’écrasement du deuxième groupe vif.
				echo "Réactivation de l’écrasement du deuxième groupe vif."
				sudo cp $X11/xkb/rules/evdev sauvegarde/archive/evdev-rules.c
				sudo sed -ri 's/\/\/\s*(\*\s*\*\s*=\s*\+%l\[2\]%\(v\[2\]\):2)/\1/' $X11/xkb/rules/evdev
				if [ "$evdev_rules_avant" -eq 1 ]; then
					sudo mv $X11/xkb/rules/evdev-rules-avant-dispoclavier sauvegarde/archive/evdev-rules-avant.c
				fi
				# Désinstaller les tableaux d’allocation de touches.
				echo "Désinstallation des tableaux d’allocation de touches."
				if [ "$dispocla" -eq 1 ]; then
					sudo mv $X11/xkb/symbols/dispocla sauvegarde/archive/dispocla.cpp
				fi
				# Désinstaller les types de touches.
				echo "Désinstallation des types de touches."
				cp $X11/xkb/types/complete sauvegarde/archive/complete-types.c
				sudo sed -i '/include "dispotypes"/d' $X11/xkb/types/complete
				if [ "$complete_types_avant" -eq 1 ]; then
					sudo mv $X11/xkb/types/complete-types-avant-dispoclavier sauvegarde/archive/complete-types-avant.c
				fi
				if [ "$dispotypes" -eq 1 ]; then
					sudo mv $X11/xkb/types/dispotypes sauvegarde/archive/dispotypes.c
				fi
				# Afficher un dernier message.
				echo -e "\n  ✅  Ces dispositions de clavier viennent d’être désinstallées."
				echo      "     À moins d’être réinstallées dans la foulée, ces dispositions"
				echo      "     auront complètement disparu dès la prochaine session."
				echo -e "\n  ⚠  Les redispositions de touches ont été sauvegardées à côté et"
				echo      "     dans ~/.config/dispoclavier/keycodes/."
				echo -e   "             Merci d’avoir utilisé Dispoclavier.\n"
			;;
			*)
				exit
			;;
		esac
	fi
else
	echo -e "\n     Sous ce système, ce script ne peut pas installer ces dispositions"
	echo      "     de clavier, car XKB et XCompose ne se présentent pas comme attendu."
	echo      "     Peut-être serait-il envisageable d’installer ces dispositions de"
	echo      "     clavier manuellement selon le mode d’emploi figurant dans l’en-tête"
	echo      "     du fichier \"Compose.yml\", qui va dans le dossier personnel, et dans"
	echo      "     chacun des fichiers qui se trouvent dans le dossier \"installer/\"".
	echo -e   "     Avec toutes nos excuses pour ce désagrément.\n"
fi

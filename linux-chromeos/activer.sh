#!/bin/bash
#                       Date : 2024-08-25T0656+0200
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
# arithmétiques. On en profite pour inverser 0 et 1 (qui dans Bash signifient
# vrai et faux contrairement à la plupart des autres langages où ils signifient
# faux et vrai), dans un souci de lisibilité.
#
intelligible=1 # Format XKB. Changer ce nombre pour passer au format XKM.
if [ "$intelligible" -eq 1 ]; then
	mode="xkb"
else
	mode="xkm"
fi

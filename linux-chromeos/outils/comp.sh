#!/bin/bash
# 2023-01-14T1934+0100
# 2023-12-02T2050+0100
# 2024-08-25T0306+0200
# = last modified.
#
# Generates all-in-one keymap files from X display. X display is the installed
# and currently active keyboard layout. The recommended output format is `.xkb`
# keymap source files, but `.xkm` compiled keymap file output is also supported
# and can be activated by editing the de-facto boolean `human_readable` below.
# https://www.ibm.com/docs/en/aix/7.3?topic=x-xkbcomp-command
#
# Requires to manually configure the subvariants in xkb/keycodes/evdev.
#
# Automatically switches layouts while compiling a subvariant as configured.
# Courtesy https://askubuntu.com/questions/209597/how-do-i-change-keyboards-from-the-command-line
#
# For this to work, the keyboard layouts must be activated and set up in the
# Gnome switch in the following order:
#
#     0  kbfrFRsr
#     1  kbfrFRs
#     2  kbbrFRs
#     3  kbfrPFs
#     4  kbfrAFs
#     5  kbfrBEs
#     6  kbbrFRsr
#     7  kbfrPFsr
#     8  kbfrAFsr
#
# For these files to be usable in 2024 Linux distros, two previously commented-
# out key types are supposed to be uncommented, although these are not used in
# these keyboard layouts:
# EIGHT_LEVEL_LEVEL_FIVE_LOCK and EIGHT_LEVEL_ALPHABETIC_LEVEL_FIVE_LOCK, as in
# xkb/types/level5, required to prevent xkbcomp from throwing an error:
#
# X Error of failed request:  BadValue (integer parameter out of range for operation)
#   Major opcode of failed request:  135 (XKEYBOARD)
#   Minor opcode of failed request:  9 (XkbSetMap)
#   Value in failed request:  0x135b0038
#   Serial number of failed request:  170
#   Current serial number in output stream:  176
#
# Rather than distributing compiled `.xkm` files, distributing merged `.xkb` is
# preferable for transparency (the user is able to check what they got) and for
# usability alike, since the user can directly customize the layout by making a
# small edit right in the all-in-one human readable source file.
#
human_readable=1 # The integer 1 is used with `true` semantics.

if [ "$human_readable" -eq 1 ]; then
	mode="xkb" # Used both as a flag and as the output file extension.
	action="merged" # Used both as a dirname and in the confirmation.
else
	mode="xkm" # Used both as a flag and as the output file extension.
	action="compiled" # Used both as a dirname and in the confirmation.
fi

cd $(dirname "$0")
if [ ! -d "$action" ]; then
	mkdir $action
fi
cd $action
if [ ! -d "Variantes" ]; then
	mkdir Variantes
fi
cd Variantes
echo "      o = Disposition ordinaire."
echo "      w = Effacement arrière sur Windows droite."
echo "     ws = Effacement arrière sur Windows droite sans Menu."
echo "      m = Effacement arrière sur Menu, Menu sur Effacement arrière."
echo "     ms = Effacement arrière sur Menu seulement, sans permutation."
echo "      c = Permuter Effacement arrière et Contrôle droite."
echo "      a = Permuter VerrCap et touche ISO pour claviers ANSI."
echo "     am = Permuter VerrCap et touche ISO, et Effacement arrière et Menu."
echo "    ams = Permuter VerrCap et touche ISO, Effacement arrière sur Menu."
read -p "          o, w, ws, m, ms, c, a, am, ams ?   " re
case $re in
	o)   suffix="";;
	w)   suffix="-win";;
	ws)  suffix="-win-sans";;
	m)   suffix="-menu";;
	ms)  suffix="-menu-sans";;
	c)   suffix="-ctrl";;
	a)   suffix="-ansi";;
	am)  suffix="-ansi-menu";;
	ams) suffix="-ansi-menu-sans";;
	*)   exit
esac

function compile {
	echo "$1$suffix.$mode:"
	if [ ! -d "$1" ]; then
		mkdir $1
	fi
	gsettings set org.gnome.desktop.input-sources current $2
	sleep 1s
	xkbcomp -$mode :0 $1/$1$suffix.$mode
	echo  "$1$suffix.$mode $action."
}

compile "kbfrFRs"  "1"
compile "kbbrFRs"  "2"
compile "kbfrPFs"  "3"
compile "kbfrAFs"  "4"
compile "kbfrBEs"  "5"
compile "kbbrFRsr" "6"
compile "kbfrPFsr" "7"
compile "kbfrAFsr" "8"
compile "kbfrFRsr" "0"
cp kbfrFRs/kbfrFRs$suffix.$mode ../nouvel-azerty$suffix.$mode; echo "nouvel-azerty$suffix.$mode updated."

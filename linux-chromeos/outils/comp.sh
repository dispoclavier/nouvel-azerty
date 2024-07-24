#!/bin/bash
# 2023-01-14T1934+0100
# 2023-12-02T2050+0100
# 2024-07-24T2110+0200
# = last modified.
#
# Merges XKB source files into an all-in-one `.xkb` source, for the purpose of
# activating a keyboard layout as user.
#
# Requires to manually configure the subvariants in xkb/keycodes/evdev.
#
# Automatically switches layouts while compiling a subvariant as configured.
# Courtesy https://askubuntu.com/questions/209597/how-do-i-change-keyboards-from-the-command-line
#
# Rather than distributing compiled `.xkm` files, distributing merged `.xkb` is
# preferable for transparency (the user is able to check what they got) and for
# usability alike, since the user can directly customize the layout by making a
# small edit right in the all-in-one human readable source file.
#
# For these files to be usable, the key types EIGHT_LEVEL_LEVEL_FIVE_LOCK and
# EIGHT_LEVEL_ALPHABETIC_LEVEL_FIVE_LOCK must be uncommented. They are found in
# xkb/types/level5 and were commented out in 2016 distros. However, these types
# are not used in these keyboard layouts and only prevent xkbcomp from throwing
# an error:
#
# X Error of failed request:  BadValue (integer parameter out of range for operation)
#   Major opcode of failed request:  135 (XKEYBOARD)
#   Minor opcode of failed request:  9 (XkbSetMap)
#   Value in failed request:  0x135b0038
#   Serial number of failed request:  170
#   Current serial number in output stream:  176
#

cd $(dirname "$0")
if [ ! -d "compiled" ]; then
	mkdir compiled
fi
cd compiled
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
	echo "$1$suffix.xkb:"
	if [ ! -d "$1" ]; then
		mkdir $1
	fi
	gsettings set org.gnome.desktop.input-sources current $2
	sleep 1s
	xkbcomp :0 $1/$1$suffix.xkb
	echo  "$1$suffix.xkb compiled."
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
cp kbfrFRs/kbfrFRs$suffix.xkb ../nouvel-azerty$suffix.xkb; echo "nouvel-azerty$suffix.xkb updated."

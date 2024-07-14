#!/bin/bash
# 2023-01-14T1934+0100
# 2023-12-02T2050+0100
# 2024-07-14T1506+0200
# = last modified.
#
# Compiles XKB layout files for activating a keyboard layout as user.
# Requires to manually configure the subvariants in xkb/keycodes/evdev.
# Automatically switches layouts while compiling a subvariant as configured.
# Courtesy https://askubuntu.com/questions/209597/how-do-i-change-keyboards-from-the-command-line

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
	echo "$1$suffix.xkm:"
	if [ ! -d "$1" ]; then
		mkdir $1
	fi
	gsettings set org.gnome.desktop.input-sources current $2
	sleep 1s
	xkbcomp :0 $1/$1$suffix.xkm
	echo  "$1$suffix.xkm compiled."
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
cp kbfrFRs/kbfrFRs$suffix.xkm ../nouvel-azerty$suffix.xkm; echo "nouvel-azerty$suffix.xkm updated."

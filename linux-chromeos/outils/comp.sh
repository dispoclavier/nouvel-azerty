#!/bin/bash
# Compile .xkb
# 2023-01-14T1934+0100
# Last modified:
# 2023-10-29T0642+0100

cd $(dirname "$0")
if [[ ! -d "Variantes" ]]; then
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
read -p  "kbfrFRs$suffix.xkb?"; xkbcomp :0  kbfrFRs$suffix.xkb; echo  "kbfrFRs$suffix.xkb compiled."
read -p  "kbbrFRs$suffix.xkb?"; xkbcomp :0  kbbrFRs$suffix.xkb; echo  "kbbrFRs$suffix.xkb compiled."
read -p  "kbfrPFs$suffix.xkb?"; xkbcomp :0  kbfrPFs$suffix.xkb; echo  "kbfrPFs$suffix.xkb compiled."
read -p  "kbfrAFs$suffix.xkb?"; xkbcomp :0  kbfrAFs$suffix.xkb; echo  "kbfrAFs$suffix.xkb compiled."
read -p  "kbfrBEs$suffix.xkb?"; xkbcomp :0  kbfrBEs$suffix.xkb; echo  "kbfrBEs$suffix.xkb compiled."
read -p  "kbfrFRr$suffix.xkb?"; xkbcomp :0  kbfrFRr$suffix.xkb; echo  "kbfrFRr$suffix.xkb compiled."
cp kbfrFRs$suffix.xkb ../nouvel-azerty$suffix.xkb; echo "nouvel-azerty$suffix.xkb updated."

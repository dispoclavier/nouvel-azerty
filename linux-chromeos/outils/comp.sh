#!/bin/bash
# Compile .xkb
# 2023-01-14T1934+0100
# 2023-03-24T0156+0100
# 2023-03-24T0441+0100
# 2023-08-19T1949+0200
# 2023-10-24T1930+0200

if [[ ! -d "Variantes" ]]; then
	mkdir Variantes
fi
cd Variantes
echo "o = Dispositions ordinaires."
echo "w = Effacement arrière sur Windows droite."
echo "s = Effacement arrière sur Windows droite sans Menu."
echo "m = Effacement arrière sur Menu."
echo "c = Effacement arrière sur Contrôle droite."
echo "a = Permuter VerrCap et touche ISO pour claviers ANSI."
echo "b = Permuter VerrCap et touche ISO, Effacement arrière sur Menu."
read -p "o, w, s, m, c, a, b?   " re
case $re in
	[oO]) suffix="" ;;
	[wW]) suffix="-win" ;;
	[sS]) suffix="-win-sans" ;;
	[mM]) suffix="-menu" ;;
	[cC]) suffix="-ctrl" ;;
	[aA]) suffix="-ansi" ;;
	[bB]) suffix="-ansi-menu" ;;
	*) exit
esac
read -p  "kbfrFRs$suffix.xkb?"; xkbcomp :0  kbfrFRs$suffix.xkb; echo  "kbfrFRs$suffix.xkb compiled."
read -p  "kbbrFRs$suffix.xkb?"; xkbcomp :0  kbbrFRs$suffix.xkb; echo  "kbbrFRs$suffix.xkb compiled."
read -p  "kbfrPFs$suffix.xkb?"; xkbcomp :0  kbfrPFs$suffix.xkb; echo  "kbfrPFs$suffix.xkb compiled."
read -p  "kbfrAFs$suffix.xkb?"; xkbcomp :0  kbfrAFs$suffix.xkb; echo  "kbfrAFs$suffix.xkb compiled."
read -p  "kbfrBEs$suffix.xkb?"; xkbcomp :0  kbfrBEs$suffix.xkb; echo  "kbfrBEs$suffix.xkb compiled."
read -p  "kbfrFRr$suffix.xkb?"; xkbcomp :0  kbfrFRr$suffix.xkb; echo  "kbfrFRr$suffix.xkb compiled."
cp kbfrFRs$suffix.xkb ../nouvel-azerty$suffix.xkb; echo "nouvel-azerty$suffix.xkb updated."

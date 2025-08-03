#!/bin/bash
# 2023-01-14T1934+0100
# 2023-12-02T2050+0100
# 2024-08-26T0303+0200
# 2025-08-03T0408+0200
# == last modified.
#
# Generates all-in-one keymap files from X display, the installed and currently
# active keyboard layout.
#
# Requires to manually configure the subvariants in xkb/keycodes/evdev.
#
# Automatically switches layouts while compiling a subvariant as configured.
# By courtesy of Stack Overflow.
# https://askubuntu.com/questions/209597/how-do-i-change-keyboards-from-the-command-line
#
# The recommended output format is ".xkb" keymap source files, but the compiled
# ".xkm" keymap file output is also supported. This can be activated by editing
# the de-facto boolean "human_readable" below.
#
human_readable=1 # The integer 1 is used with "true" semantics.
#
# Rather than distributing compiled ".xkm" files, distributing merged ".xkb" is
# preferable for transparency (the user is able to check what they got) and for
# usability alike, since the user can directly customize the layout by making a
# small edit right in the source file.
#
# The xkbcomp command is documented by IBM.
# https://www.ibm.com/docs/en/aix/7.3?topic=x-xkbcomp-command
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
# For these files to be usable in recent Linux distros, two key types that were
# previously commented out are required to be uncommented, despite they are not
# used in these keyboard layouts:
#
#     EIGHT_LEVEL_LEVEL_FIVE_LOCK
#     EIGHT_LEVEL_ALPHABETIC_LEVEL_FIVE_LOCK
#
# These two types are defined in /usr/share/X11/xkb/types/level5.
#
# The issue with these two is that, when they are not defined, xkbcomp is prone
# to returning an error of failed request.
#
#     X Error of failed request:  BadValue (integer parameter out of range for operation)
#       Major opcode of failed request:  135 (XKEYBOARD)
#       Minor opcode of failed request:  9 (XkbSetMap)
#       Value in failed request:  0x135b0038
#       Serial number of failed request:  170
#       Current serial number in output stream:  176
#

if [ "$human_readable" -eq 1 ]; then
	# $mode is used both as a flag and as the output file extension.
	mode="xkb"
	# $action is used both as a dirname and in the confirmation message.
	action="merged"
else
	mode="xkm"
	action="compiled"
fi

function merge_or_compile {
	echo "$1$suffix.$mode:"
	if [ ! -d "$1" ]; then
		mkdir $1
	fi
	gsettings set org.gnome.desktop.input-sources current $2
	sleep 1s
	xkbcomp -$mode :0 $1/$1$suffix.$mode
	echo  "$1$suffix.$mode $action."
}

cd $(dirname "$0")
if [ ! -d "$action" ]; then
	mkdir $action
fi
cd $action
if [ ! -d "Variantes" ]; then
	mkdir Variantes
fi
cd Variantes
echo    "      o = Disposition ordinaire."
echo    "      w = Effacement arrière sur Windows droite."
echo    "     ws = Effacement arrière sur Windows droite sans Menu."
echo    "      m = Effacement arrière sur Menu, Menu sur Effacement arrière."
echo    "     ms = Effacement arrière sur Menu seulement, sans permutation."
echo    "      c = Permuter Effacement arrière et Contrôle droite."
echo    "      a = Permuter VerrCap et touche ISO pour claviers ANSI."
echo    "     am = Permuter VerrCap et touche ISO, et Effacement arrière et Menu."
echo    "    ams = Permuter VerrCap et touche ISO, Effacement arrière sur Menu."
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
	*)
		exit
	;;
esac

# Output the variants.
merge_or_compile "kbfrFRs"  "1"
merge_or_compile "kbbrFRs"  "2"
merge_or_compile "kbfrPFs"  "3"
merge_or_compile "kbfrAFs"  "4"
merge_or_compile "kbfrBEs"  "5"
merge_or_compile "kbbrFRsr" "6"
merge_or_compile "kbfrPFsr" "7"
merge_or_compile "kbfrAFsr" "8"
merge_or_compile "kbfrFRsr" "0"

# Copy the base layout to the folder’s root.
cp kbfrFRs/kbfrFRs$suffix.$mode ../nouvel-azerty$suffix.$mode
echo "nouvel-azerty$suffix.$mode mis à jour."

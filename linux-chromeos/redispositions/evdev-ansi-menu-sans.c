//                       Date: 2025-07-06T2056+0200
//        Operating file name: evdev
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: X key codes to XKB key labels map
//                   Platform: Linux using XKB with XCompose*
//            Particularités : Redisposition pour agencement ANSI en AZERTY, avec AltFr sur la touche de Verrouillage Majuscule, et le Verrouillage des capitales sur la touche [<>] de l’AZERTY à la place de Contrôle droite, avec l’Effacement arrière sur la touche Menu, sans Menu sur la touche d’Effacement arrière.
//
//               Project name: Dispoclavier
//                Project URL: https://dispoclavier.com
//                      Maxim: Simplify typewriting, not French.
//                    Maxime : Simplifier la dactylographie, pas le français.
//        English description: Keyboard layouts fit for national, regional and neighbor languages of Francophonie.
//     Description française : Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.
//              Target public: General public and developers, journalists, scientists, secretaries, translators, typographers and writers
//             Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev[arobase]dispoclavier.com
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, Linux is supported alongside ChromeOS, or through ChromeOS.
//
//               Installation: 1. Rename the file
//                                /usr/share/X11/xkb/keycodes/evdev
//                                as the original, e.g.
//                                /usr/share/X11/xkb/keycodes/evdev_ORIGINAL
//
//                             2. Add this file as
//                                /usr/share/X11/xkb/keycodes/evdev
//
//                             The changes take effect when reopening a session.
//
//             Uninstallation: Delete the new file and revert the renaming.
//
//
// # X key codes to XKB key labels map
//
// When Linux key codes are passed over to X, 8 is added. X key codes come on
// top of the Linux key codes and are mapped to XKB key labels in this file.
//
// Some applications may be ignoring some of these mappings, notably those
// about handling the Backspace key.
//
// Linux keycodes appear in /usr/inc/linux/input-event-codes.h.
// https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html
// http://manpages.ubuntu.com/manpages/xenial/man1/showkey.1.html
//
// ArchLinux gives the default scancodes-to-keycodes mapping in
// /usr/lib/udev/hwdb.d/60-keyboard.hwdb.
//
// This file covers key remappings that should apply system-wide
// rather than on a per-keylayout basis.
//
// Remappings on a per-user basis for built-in keyboards and without
// support for USB keyboards may be performed using setkeycodes.
// This has the upside of being done in the kernel, not in XKB, so it
// applies also in applications disregarding XKB remappings.
// http://manpages.ubuntu.com/manpages/xenial/man8/setkeycodes.8.html
//
//     sudo setkeycodes scancode keycode [...]
//
// Permutate Backspace and right Control:
//
//     sudo setkeycodes 0e 97 e01d 14
//
// This command has cross-session validity until shutdown.
// The remapping may be inadvertently lost once and need to be redone.
//
// The recommended way of editing this file is by moving the keylabels.
//

default xkb_keycodes "evdev" {
  minimum =   8;
  maximum = 255;

  //
  // The main layout and 8 distributable subvariants are configurable below.
  //
  // Since laptops with ANSI keyboard for ISO keyboard markets may have a Menu key,
  // the subvariants with Backspace on Menu are provided with swapped Caps/ISO too.
  //
  // When running `comp.sh`, the following arguments are used.
  //
  // Arg  Suffix             Features
  //
  //   o  ""                 Ordinary.
  //   w  "-win"             Backspace on right Windows.
  //  ws  "-win-sans"        Backspace on right Windows sans Menu.
  //   m  "-menu"            Backspace on Menu, Menu on Backspace.
  //  ms  "-menu-sans"       Backspace on Menu only, no permutation.
  //   c  "-ctrl"            Permutate Backspace and right Control.
  //   a  "-ansi"            Swap CapsLock and ISO key for ANSI keyboards.
  //  am  "-ansi-menu"       Swap CapsLock and ISO key, and Backspace and Menu.
  // ams  "-ansi-menu-sans"  Swap CapsLock and ISO key, with Backspace on Menu.
  //
  // Each key can be mapped only once, and the latest mapping overrides previous ones.
  //
  
      //<BKSP> =  22; // was <BKSP>   Overridden if Backspace on RWIN, MENU or RCTL.

      //<CAPS> =  66; // was <CAPS>   Common mapping for desktop and laptop.
      //<LSGT> =  94; // was <LSGT>   Common mapping for desktop and laptop.
        <RWIN> = 134; // was <RWIN>   Common mapping for desktop and laptop.
      //<MENU> = 135; // was <MENU>   Common mapping for desktop and laptop.
        <RCTL> = 105; // was <RCTL>   Common mapping for desktop and laptop.

  //
  // ## Pure ANSI keyboards without ISO key emulation
  //
  // On pure ANSI keyboards, key B00 needs to be introduced at the expense of
  // the right Control key, repurposed as CAPS, for the CapsLock key to become
  // the AltFr key LSGT, that needs to be lefthand. However, in case the CAPS
  // key is disliked, it does not need to be remapped, so RCTL is unaffected.

      //<LSGT> =  66; // was <CAPS>   Map ISO key on CapsLock for pure ANSI keyboards.
      //<CAPS> = 105; // was <RCTL>   Map CapsLock on right Control for pure ANSI keyboards.

  //
  // ## Hybrid ANSI keyboards with ISO key emulation
  //
  // Suffix: -ansi
  // Suffix: -ansi-menu
  // Suffix: -ansi-menu-sans
  //
  // On ANSI keyboards for ISO keyboard markets, key B00 is located where other
  // laptops — for the ANSI market or with ISO key — have the right Control key,
  // so that for AltFr to stay lefthand, keys LSGT and CAPS need to be swapped.
  // LSGT is key ISO B00, which on ISO keyboards is the AltFr modifier key.

        <LSGT> =  66; // was <CAPS>   Swap CapsLock and ISO key for hybrid ANSI keyboards.
        <CAPS> =  94; // was <LSGT>   Swap CapsLock and ISO key for hybrid ANSI keyboards.

  //
  // ## Backspace on right Windows key
  //
  // Suffix: -win
  // Suffix: -win-sans
  //
  // Yves NEUVILLE recommends the Backspace key at the bottom right rather than at the
  // top.
  // “Le Clavier bureautique et informatique”, Cedic/Nathan, 1975, ISBN 2-7124-1705-4;
  // see the drawings showing the Neuville keyboard, on page 51, pages 61 through 65.
  //
  // The options suggested below are intended for keyboards with the right Windows key
  // next to the AltGr key.

      //<BKSP> = 134; // was <RWIN>   Backspace on right Windows for desktop keyboards.
      //<RWIN> =  22; // was <BKSP>   Right Windows on Backspace instead for usability.
      //<HKTG> = 135; // was <MENU>   Additionally: Deactivates the Menu key.

  //
  // ## Backspace on Menu key
  //
  // Suffix: -menu
  // Suffix: -ansi-menu
  // Suffix: -menu-sans
  // Suffix: -ansi-menu-sans
  //
  // Menu on Backspace is optional since this may interfere with application keybindings.

        <BKSP> = 135; // was <MENU>   Backspace on Menu key for compact keyboards.
      //<MENU> =  22; // was <BKSP>   Menu key on Backspace instead for usability.

  //
  // ## Backspace on right Control key
  //
  // Suffix: -ctrl
  //
      //<BKSP> = 105; // was <RCTL>   Backspace on right Control for compact keyboards.
      //<RCTL> =  22; // was <BKSP>   Right Control on Backspace instead for usability.

  // Permutating BKSP and RCTL here fails in applications relying partly on keycodes,
  // such as VSCode in the editor, not in the search widget (where both work). That is
  // worked around by adding keybindings for deleteLeft and deleteWordLeft both on the
  // ContextMenu key and on Backspace. The right Windows key is still Meta and cannot
  // be assigned commands such as deleteLeft, using the VSCode keybinding customizer.
  //
  // Swapping BKSP and RCTL on built-in keyboards may be done using setkeycodes, but
  // that fails on external keyboards. See “setkeycodes not effective on USB keyboard”
  // https://bugzilla.redhat.com/show_bug.cgi?id=211803
  //

  // Other left-hand special keys

        <ESC>  =   9; // was <ESC>
        <TAB>  =  23; // was <TAB>
        <LCTL> =  37; // was <LCTL>
        <TLDE> =  49; // was <TLDE>   Now ModLock toggle: group1 lock ⭤ group2 lock.
        <LFSH> =  50; // was <LFSH>
        <LALT> =  64; // was <LALT>
        <LWIN> = 133; // was <LWIN>

  // Other right-hand special keys

  alias <MENU> = <COMP>;
        <RTRN> =  36; // was <RTRN>
        <RTSH> =  62; // was <RTSH>
        <RALT> = 108; // was <RALT>

  // Other keys

        <NMLK> =  77; // was <NMLK>   Compact keyboards use NMLK for the overlay numpad.
        <SCLK> =  78; // was <SCLK>
        <PRSC> = 107;
     // <SYRQ> = 107;
        <PAUS> = 127;
     // <BRK>  = 419;

  // Alphabetic keys

        <AE01> =  10;
        <AE02> =  11;
        <AE03> =  12;
        <AE04> =  13;
        <AE05> =  14;
        <AE06> =  15;
        <AE07> =  16;
        <AE08> =  17;
        <AE09> =  18;
        <AE10> =  19;
        <AE11> =  20;
        <AE12> =  21;

        <AD01> =  24;
        <AD02> =  25;
        <AD03> =  26;
        <AD04> =  27;
        <AD05> =  28;
        <AD06> =  29;
        <AD07> =  30;
        <AD08> =  31;
        <AD09> =  32;
        <AD10> =  33;
        <AD11> =  34;
        <AD12> =  35;
  alias <AD13> = <BKSL>;
        <BKSL> =  51;

        <AC01> =  38;
        <AC02> =  39;
        <AC03> =  40;
        <AC04> =  41;
        <AC05> =  42;
        <AC06> =  43;
        <AC07> =  44;
        <AC08> =  45;
        <AC09> =  46;
        <AC10> =  47;
        <AC11> =  48;
  alias <AC12> = <BKSL>;

        <AB01> =  52;
        <AB02> =  53;
        <AB03> =  54;
        <AB04> =  55;
        <AB05> =  56;
        <AB06> =  57;
        <AB07> =  58;
        <AB08> =  59;
        <AB09> =  60;
        <AB10> =  61;

        <SPCE> =  65;

  // Edit keys

        <UP>   = 111;
        <LEFT> = 113;
        <DOWN> = 116;
        <RGHT> = 114;

        <INS>  = 118;
        <DELE> = 119;
        <HOME> = 110;
        <END>  = 115;
        <PGUP> = 112;
        <PGDN> = 117;

  // Numeric keypad

        <KPEN> = 104;
        <KPEQ> = 125;

        <KPDV> = 106;
        <KPMU> =  63;
        <KPSU> =  82;
        <KPAD> =  86;

        <KP7>  =  79;
        <KP8>  =  80;
        <KP9>  =  81;

        <KP4>  =  83;
        <KP5>  =  84;
        <KP6>  =  85;

        <KP1>  =  87;
        <KP2>  =  88;
        <KP3>  =  89;

        <KP0>  =  90;
        <KPDL> =  91;

  // Function keys

        <FK01> =  67;
        <FK02> =  68;
        <FK03> =  69;
        <FK04> =  70;
        <FK05> =  71;
        <FK06> =  72;
        <FK07> =  73;
        <FK08> =  74;
        <FK09> =  75;
        <FK10> =  76;
        <FK11> =  95;
        <FK12> =  96;

        <FK13> = 191;
        <FK14> = 192;
        <FK15> = 193;
        <FK16> = 194;
        <FK17> = 195;
        <FK18> = 196;
        <FK19> = 197;
        <FK20> = 198;
        <FK21> = 199;
        <FK22> = 200;
        <FK23> = 201;
        <FK24> = 202;

  // Keys that are generated on Japanese keyboards

     // <HZTG> =  93; // Hankaku/Zenkakau toggle - not actually used
  alias <HZTG> = <TLDE>;
     // <HKTG> = 101; // Hiragana/Katakana toggle
        <AB11> =  97; // backslash/underscore
        <HENK> = 100; // Henkan
        <MUHE> = 102; // Muhenkan
        <AE13> = 132; // Yen
        <KATA> =  98; // Katakana
        <HIRA> =  99; // Hiragana
     // <JPCM> = 103; // KPJPComma
     // <RO>   =  97; // Romaji

  // Keys that are generated on Korean keyboards

        <HNGL> = 130; // Hangul Latin toggle
        <HJCV> = 131; // Hangul to Hanja conversion

  // Solaris compatibility

  alias <LMTA> = <LWIN>;
  alias <RMTA> = <RWIN>;
        <MUTE> = 121;
        <VOL-> = 122;
        <VOL+> = 123;
        <POWR> = 124;
        <STOP> = 136;
        <AGAI> = 137;
        <PROP> = 138;
        <UNDO> = 139;
        <FRNT> = 140;
        <COPY> = 141;
        <OPEN> = 142;
        <PAST> = 143;
        <FIND> = 144;
        <CUT>  = 145;
        <HELP> = 146;

  // Extended keys that may be generated on "Internet" keyboards.
  // evdev has standardize names for these.

        <LNFD> = 109; // #define KEY_LINEFEED            101
     // <I120> = 120; // #define KEY_MACRO               112
        <I126> = 126; // #define KEY_KPPLUSMINUS         118
        <I128> = 128; // #define KEY_SCALE               120
        <I129> = 129; // #define KEY_KPCOMMA             121
        <I147> = 147; // #define KEY_MENU                139
        <I148> = 148; // #define KEY_CALC                140
     // <I149> = 149; // #define KEY_SETUP               141
        <I150> = 150; // #define KEY_SLEEP               142
        <I151> = 151; // #define KEY_WAKEUP              143
        <I152> = 152; // #define KEY_FILE                144
        <I153> = 153; // #define KEY_SENDFILE            145
     // <I154> = 154; // #define KEY_DELETEFILE          146
        <I155> = 155; // #define KEY_XFER                147
        <I156> = 156; // #define KEY_PROG1               148
        <I157> = 157; // #define KEY_PROG2               149
        <I158> = 158; // #define KEY_WWW                 150
        <I159> = 159; // #define KEY_MSDOS               151
        <I160> = 160; // #define KEY_COFFEE              152
        <I161> = 161; // #define KEY_DIRECTION           153
        <I162> = 162; // #define KEY_CYCLEWINDOWS        154
        <I163> = 163; // #define KEY_MAIL                155
        <I164> = 164; // #define KEY_BOOKMARKS           156
        <I165> = 165; // #define KEY_COMPUTER            157
        <I166> = 166; // #define KEY_BACK                158
        <I167> = 167; // #define KEY_FORWARD             159
     // <I168> = 168; // #define KEY_CLOSECD             160
        <I169> = 169; // #define KEY_EJECTCD             161
        <I170> = 170; // #define KEY_EJECTCLOSECD        162
        <I171> = 171; // #define KEY_NEXTSONG            163
        <I172> = 172; // #define KEY_PLAYPAUSE           164
        <I173> = 173; // #define KEY_PREVIOUSSONG        165
        <I174> = 174; // #define KEY_STOPCD              166
        <I175> = 175; // #define KEY_RECORD              167
        <I176> = 176; // #define KEY_REWIND              168
        <I177> = 177; // #define KEY_PHONE               169
     // <I178> = 178; // #define KEY_ISO                 170
        <I179> = 179; // #define KEY_CONFIG              171
        <I180> = 180; // #define KEY_HOMEPAGE            172
        <I181> = 181; // #define KEY_REFRESH             173
        <I182> = 182; // #define KEY_EXIT                174
     // <I183> = 183; // #define KEY_MOVE                175
     // <I184> = 184; // #define KEY_EDIT                176
        <I185> = 185; // #define KEY_SCROLLUP            177
        <I186> = 186; // #define KEY_SCROLLDOWN          178
        <I187> = 187; // #define KEY_KPLEFTPAREN         179
        <I188> = 188; // #define KEY_KPRIGHTPAREN        180
        <I189> = 189; // #define KEY_NEW                 181
        <I190> = 190; // #define KEY_REDO                182
        <I208> = 208; // #define KEY_PLAYCD              200
        <I209> = 209; // #define KEY_PAUSECD             201
        <I210> = 210; // #define KEY_PROG3               202
        <I211> = 211; // #define KEY_PROG4               203 conflicts with AB11
        <I212> = 212; // #define KEY_DASHBOARD           204
        <I213> = 213; // #define KEY_SUSPEND             205
        <I214> = 214; // #define KEY_CLOSE               206
        <I215> = 215; // #define KEY_PLAY                207
        <I216> = 216; // #define KEY_FASTFORWARD         208
     // <I217> = 217; // #define KEY_BASSBOOST           209
        <I218> = 218; // #define KEY_PRINT               210
     // <I219> = 219; // #define KEY_HP                  211
        <I220> = 220; // #define KEY_CAMERA              212
     // <I221> = 221; // #define KEY_SOUND               213
     // <I222> = 222; // #define KEY_QUESTION            214
        <I223> = 223; // #define KEY_EMAIL               215
        <I224> = 224; // #define KEY_CHAT                216
        <I225> = 225; // #define KEY_SEARCH              217
        <I226> = 226; // #define KEY_CONNECT             218
        <I227> = 227; // #define KEY_FINANCE             219
        <I228> = 228; // #define KEY_SPORT               220
        <I229> = 229; // #define KEY_SHOP                221
     // <I230> = 230; // #define KEY_ALTERASE            222
        <I231> = 231; // #define KEY_CANCEL              223
        <I232> = 232; // #define KEY_BRIGHTNESSDOWN      224
        <I233> = 233; // #define KEY_BRIGHTNESSUP        225
        <I234> = 234; // #define KEY_MEDIA               226
        <I235> = 235; // #define KEY_SWITCHVIDEOMODE     227
        <I236> = 236; // #define KEY_KBDILLUMTOGGLE      228
        <I237> = 237; // #define KEY_KBDILLUMDOWN        229
        <I238> = 238; // #define KEY_KBDILLUMUP          230
        <I239> = 239; // #define KEY_SEND                231
        <I240> = 240; // #define KEY_REPLY               232
        <I241> = 241; // #define KEY_FORWARDMAIL         233
        <I242> = 242; // #define KEY_SAVE                234
        <I243> = 243; // #define KEY_DOCUMENTS           235
        <I244> = 244; // #define KEY_BATTERY             236
        <I245> = 245; // #define KEY_BLUETOOTH           237
        <I246> = 246; // #define KEY_WLAN                238
     // <I247> = 247; // #define KEY_UWB                 239
     // <I248> = 248; // #define KEY_UNKNOWN             240
     // <I249> = 249; // #define KEY_VIDEO_NEXT          241
     // <I250> = 250; // #define KEY_VIDEO_PREV          242
     // <I251> = 251; // #define KEY_BRIGHTNESS_CYCLE    243
     // <I252> = 252; // #define KEY_BRIGHTNESS_ZERO     244
     // <I253> = 253; // #define KEY_DISPLAY_OFF         245

  // Fake keycodes for virtual keys
        <LVL3> =  92;
        <MDSW> = 203;
        <ALT>  = 204;
        <META> = 205;
        <SUPR> = 206;
        <HYPR> = 207;

  // Status indicators
        indicator 1  = "Caps Lock";
        indicator 2  = "Num Lock";
        indicator 3  = "Scroll Lock";
        indicator 4  = "Compose";
        indicator 5  = "Kana";
        indicator 6  = "Sleep";
        indicator 7  = "Suspend";
        indicator 8  = "Mute";
        indicator 9  = "Misc";
        indicator 10 = "Mail";
        indicator 11 = "Charging";

  alias <ALGR> = <RALT>;

  // For Brazilian ABNT2
  alias <KPPT> = <I129>;
};

// PC98
xkb_keycodes "pc98" {
  include "evdev(evdev)"
};

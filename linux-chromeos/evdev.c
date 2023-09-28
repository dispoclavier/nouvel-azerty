//                       Date: 2023-09-29T0134+0200
//        Operating file name: evdev
//                   Encoding: UTF-8
//                       Type: text/XKB configuration
//                   Language: C-like
//                Description: X key code to XKB key label conversion
//                   Platform: Linux using XKB with XCompose*
//
//               Project name: Dispoclavier
//                Project URL: https://dispoclavier.com
//                      Maxim: Simplify typewriting, not French.
//                    Maxime : Simplifier la dactylographie, pas le français.
//        English description: Keyboard layouts fit for national, regional and neighbor languages of Francophonie.
//     Description française : Dispositions de clavier adaptées aux langues nationales, régionales et voisines de la Francophonie.
//              Target public: General public and developers, journalists, scientists, secretaries, translators, typographers and writers
//             Destinataires : Grand public et développeurs, écrivains, journalistes, scientifiques, secrétaires, traducteurs et typographes
//              Regular names: kb(brFRs|fr(AFs|BEs|CA(ms|s)|CHs|FR(h(w|z|y)|r|s)|PFs))
//   Full names, descriptions: kbbrFRs  Breton and French France semiautomatic keyboard layout
//                             kbfrAFs  Francophone Africa semiautomatic keyboard layout
//                             kbfrBEs  French Belgium semiautomatic keyboard layout
//                 (oncoming)  kbfrCAms French Canada multilingual semiautomatic keyboard layout
//                 (oncoming)  kbfrCAs  French Canada semiautomatic keyboard layout
//                 (oncoming)  kbfrCHs  French Switzerland semiautomatic keyboard layout
//                             kbfrFRr  French France remapped semiautomatic keyboard layout
//                             kbfrFRs  French France semiautomatic keyboard layout
//                             kbfrPFs  French Polynesia semiautomatic keyboard layout
//               Code licence: Apache 2.0
//           Code licence URL: https://www.apache.org/licenses/LICENSE-2.0
//           Non-code licence: CC-BY 4.0
//       Non-code licence URL: https://creativecommons.org/licenses/by/4.0/deed.fr
//              Email address: dev@dispoclavier.net
//
//   * In Unicode CLDR, this platform is labeled ChromeOS, and it is explained that
//     in the CLDR, *Linux* is supported alongside *ChromeOS*, or through ChromeOS.
//
//               Installation: 1. Rename the file
//                                /usr/share/X11/xkb/keycodes/evdev
//                                as the original, e.g.
//                                /usr/share/X11/xkb/keycodes/evdev_ORIGINAL
//                             2. Add this file in
//                                /usr/share/X11/xkb/keycodes/
//                             The change takes effect when reopening a session.
//
//             Uninstallation: Delete that file and revert the renaming.
//
//
// Mapping X key codes to XKB key labels
//
// CAUTION: These decimals are X key codes, not Linux key codes.
//          The difference is 8 added when passing Linux key codes
//          over to X. X key codes come on top of the Linux key codes
//          and are mapped to XKB key labels in this file.
//          Some widespread applications are sometimes ignoring these
//          labels, partly when handling the backspace key. However,
//          some essential remappings are performed here inside XKB.
//
// Linux keycodes appear in /usr/include/linux/input-event-codes.h.
// ArchLinux gives the default scancodes-to-keycodes mapping in
// /usr/lib/udev/hwdb.d/60-keyboard.hwdb.
// Some versions of Ubuntu like 16.04 do not have this.
//
// This file covers key remappings that should apply system-wide
// rather than on a per-keylayout basis.
// Certain remappings are useless when performed in symbols files.
// E.g. mapping NumLock to <TLDE> in a symbols/* file
// directs the Left Alt key to bug.
//
// From https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html
// scancodes: 0e = Backspace, e0 1d = RCtrl
// From /usr/inc/linux/input-event-codes.h:
// #define KEY_BACKSPACE        14
// #define KEY_RIGHTCTRL        97
// From http://manpages.ubuntu.com/manpages/xenial/man1/showkey.1.html
// sudo showkey [-s|--scancodes] | [-k|--keycodes] | [-a|--ascii] | [-h|--help]
// sudo showkey -k
// Backspace:
// keycode  14 press
// keycode  14 release
// (Right Control keypress:)
// keycode  97 press
// keycode  97 release
// sudo showkey -s
// (Backspace keypress:)
// 0x0e
// 0x8e
// Right Control:
// 0xe0 0x1d
// 0xe0 0x9d
// From http://manpages.ubuntu.com/manpages/xenial/man8/setkeycodes.8.html
// sudo setkeycodes scancode keycode [...]
// sudo setkeycodes 0e 97 e01d 14
// This command has cross-session validity until shutdown.
// The remapping may be inadvertently lost once and needs to be redone.

// When editing this file, please move the left-hand codes, keylabels.

default xkb_keycodes "evdev" {
  minimum =   8;
  maximum = 255;

  // Configuring distributable variants:

  // <LSGT> is key ISO B00, AltFr on ISO keyboards.
  // On ANSI keyboards for ISO keyboard markets, B00 is mapped on Right Control,
  // so that for AltFr to stay lefthand, keys LSGT and CAPS need to be swapped.

  // Permutating BKSP and RCTL here fails in applications relying partly on keycodes,
  // such as VSCode in the editor, not in the search widget (where both work). That is
  // worked around by adding a keybinding for deleteLeft on the legacy Backspace key,
  // and another one on ContextMenu. The right Windows key is still Meta and cannot be
  // assigned any command like deleteLeft, using the VSCode keybinding customizer.

  // Remapping BKSP and RCTL may be done using setkeycodes.
  // But setkeycodes only works for built-in keyboards, it fails on external keyboards.
  // Each key can be mapped only once, and the latest mapping overrides previous ones.
  // So BKSP needs to be mapped ad hoc on a per-user basis anyway, not distributable.
  // As a workaround, VSCode must use a keybinding on the backspace key for delete left.

  //    <CAPS> =  94;  // was <LSGT>   Swap CapsLock and ISO key for ANSI keyboards.
  //    <LSGT> =  66;  // was <CAPS>   Swap CapsLock and ISO key for ANSI keyboards.
        <LSGT> =  94;  // was <LSGT>   Common mappings for desktop and laptop.
        <CAPS> =  66;  // was <CAPS>   Common mappings for desktop and laptop.

        <BKSP> =  22;  // was <BKSP>   Overridden if Backspace on right Windows for desktop.

  //    <BKSP> = 134;  // was <RWIN>   Backspace on right Windows for desktop.
  //    <SCLK> = 135;  // was <COMP>   Backspace on right Windows for desktop: Deactivates the menu key.
        <RWIN> = 134;  // was <RWIN>   Common mappings for desktop and laptop.
        <COMP> = 135;  // was <COMP>   Common mappings for desktop and laptop.

  // Other left-hand functional keys:

        <ESC>  =   9;  // was <ESC>
        <TAB>  =  23;  // was <TAB>
        <LCTL> =  37;  // was <LCTL>
        <TLDE> =  49;  // was <TLDE> Now ModLock key switching lock between group1 and group2.
        <LFSH> =  50;  // was <LFSH>
        <LALT> =  64;  // was <LALT>
        <LWIN> = 133;  // was <LWIN>

  // Other right-hand functional keys:

  alias <MENU> = <COMP>;
        <RCTL> = 105;  // was <RCTL>
        <RTRN> =  36;  // was <RTRN>
        <RTSH> =  62;  // was <RTSH>
        <RALT> = 108;  // was <RALT>

  // Other keys:

        <NMLK> =  77;  // was <NMLK>   Compact keyboards use NMLK for the overlay numpad.
        <SCLK> =  78;  // was <SCLK>
        <PRSC> = 107;
     // <SYRQ> = 107;
        <PAUS> = 127;
     // <BRK>  = 419;

  // Alphabetic keys:

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

  // Edit keys:

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

  // Numeric keypad:

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

  // Function keys:

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
        <HKTG> = 101;   // Hiragana/Katakana toggle
        <AB11> =  97;  // backslash/underscore
        <HENK> = 100;   // Henkan
        <MUHE> = 102;   // Muhenkan
        <AE13> = 132;   // Yen
        <KATA> =  98;   // Katakana
        <HIRA> =  99;   // Hiragana
        <JPCM> = 103;   // KPJPComma
     // <RO>   =  97; // Romaji

  // Keys that are generated on Korean keyboards

        <HNGL> = 130;   // Hangul Latin toggle
        <HJCV> = 131;   // Hangul to Hanja conversion

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

        <LNFD> = 109;   // #define KEY_LINEFEED            101
        <I120> = 120;   // #define KEY_MACRO               112
        <I126> = 126;   // #define KEY_KPPLUSMINUS         118
        <I128> = 128;   // #define KEY_SCALE               120
        <I129> = 129;   // #define KEY_KPCOMMA             121
        <I147> = 147;   // #define KEY_MENU                139
        <I148> = 148;   // #define KEY_CALC                140
        <I149> = 149;   // #define KEY_SETUP               141
        <I150> = 150;   // #define KEY_SLEEP               142
        <I151> = 151;   // #define KEY_WAKEUP              143
        <I152> = 152;   // #define KEY_FILE                144
        <I153> = 153;   // #define KEY_SENDFILE            145
        <I154> = 154;   // #define KEY_DELETEFILE          146
        <I155> = 155;   // #define KEY_XFER                147
        <I156> = 156;   // #define KEY_PROG1               148
        <I157> = 157;   // #define KEY_PROG2               149
        <I158> = 158;   // #define KEY_WWW                 150
        <I159> = 159;   // #define KEY_MSDOS               151
        <I160> = 160;   // #define KEY_COFFEE              152
        <I161> = 161;   // #define KEY_DIRECTION           153
        <I162> = 162;   // #define KEY_CYCLEWINDOWS        154
        <I163> = 163;   // #define KEY_MAIL                155
        <I164> = 164;   // #define KEY_BOOKMARKS           156
        <I165> = 165;   // #define KEY_COMPUTER            157
        <I166> = 166;   // #define KEY_BACK                158
        <I167> = 167;   // #define KEY_FORWARD             159
        <I168> = 168;   // #define KEY_CLOSECD             160
        <I169> = 169;   // #define KEY_EJECTCD             161
        <I170> = 170;   // #define KEY_EJECTCLOSECD        162
        <I171> = 171;   // #define KEY_NEXTSONG            163
        <I172> = 172;   // #define KEY_PLAYPAUSE           164
        <I173> = 173;   // #define KEY_PREVIOUSSONG        165
        <I174> = 174;   // #define KEY_STOPCD              166
        <I175> = 175;   // #define KEY_RECORD              167
        <I176> = 176;   // #define KEY_REWIND              168
        <I177> = 177;   // #define KEY_PHONE               169
        <I178> = 178;   // #define KEY_ISO                 170
        <I179> = 179;   // #define KEY_CONFIG              171
        <I180> = 180;   // #define KEY_HOMEPAGE            172
        <I181> = 181;   // #define KEY_REFRESH             173
        <I182> = 182;   // #define KEY_EXIT                174
        <I183> = 183;   // #define KEY_MOVE                175
        <I184> = 184;   // #define KEY_EDIT                176
        <I185> = 185;   // #define KEY_SCROLLUP            177
        <I186> = 186;   // #define KEY_SCROLLDOWN          178
        <I187> = 187;   // #define KEY_KPLEFTPAREN         179
        <I188> = 188;   // #define KEY_KPRIGHTPAREN        180
        <I189> = 189;   // #define KEY_NEW                 181
        <I190> = 190;   // #define KEY_REDO                182
        <I208> = 208;   // #define KEY_PLAYCD              200
        <I209> = 209;   // #define KEY_PAUSECD             201
        <I210> = 210;   // #define KEY_PROG3               202
        <I211> = 211;   // #define KEY_PROG4               203 conflicts with AB11
        <I212> = 212;   // #define KEY_DASHBOARD           204
        <I213> = 213;   // #define KEY_SUSPEND             205
        <I214> = 214;   // #define KEY_CLOSE               206
        <I215> = 215;   // #define KEY_PLAY                207
        <I216> = 216;   // #define KEY_FASTFORWARD         208
        <I217> = 217;   // #define KEY_BASSBOOST           209
        <I218> = 218;   // #define KEY_PRINT               210
        <I219> = 219;   // #define KEY_HP                  211
        <I220> = 220;   // #define KEY_CAMERA              212
        <I221> = 221;   // #define KEY_SOUND               213
        <I222> = 222;   // #define KEY_QUESTION            214
        <I223> = 223;   // #define KEY_EMAIL               215
        <I224> = 224;   // #define KEY_CHAT                216
        <I225> = 225;   // #define KEY_SEARCH              217
        <I226> = 226;   // #define KEY_CONNECT             218
        <I227> = 227;   // #define KEY_FINANCE             219
        <I228> = 228;   // #define KEY_SPORT               220
        <I229> = 229;   // #define KEY_SHOP                221
        <I230> = 230;   // #define KEY_ALTERASE            222
        <I231> = 231;   // #define KEY_CANCEL              223
        <I232> = 232;   // #define KEY_BRIGHTNESSDOWN      224
        <I233> = 233;   // #define KEY_BRIGHTNESSUP        225
        <I234> = 234;   // #define KEY_MEDIA               226
        <I235> = 235;   // #define KEY_SWITCHVIDEOMODE     227
        <I236> = 236;   // #define KEY_KBDILLUMTOGGLE      228
        <I237> = 237;   // #define KEY_KBDILLUMDOWN        229
        <I238> = 238;   // #define KEY_KBDILLUMUP          230
        <I239> = 239;   // #define KEY_SEND                231
        <I240> = 240;   // #define KEY_REPLY               232
        <I241> = 241;   // #define KEY_FORWARDMAIL         233
        <I242> = 242;   // #define KEY_SAVE                234
        <I243> = 243;   // #define KEY_DOCUMENTS           235
        <I244> = 244;   // #define KEY_BATTERY             236
        <I245> = 245;   // #define KEY_BLUETOOTH           237
        <I246> = 246;   // #define KEY_WLAN                238
        <I247> = 247;   // #define KEY_UWB                 239
        <I248> = 248;   // #define KEY_UNKNOWN             240
        <I249> = 249;   // #define KEY_VIDEO_NEXT          241
        <I250> = 250;   // #define KEY_VIDEO_PREV          242
        <I251> = 251;   // #define KEY_BRIGHTNESS_CYCLE    243
        <I252> = 252;   // #define KEY_BRIGHTNESS_ZERO     244
        <I253> = 253;   // #define KEY_DISPLAY_OFF         245

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


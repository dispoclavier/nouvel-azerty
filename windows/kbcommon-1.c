/*****************************************************************************\
* Module Name: kbcommon-1.c
*
* Common keyboard layout data
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Move part of the code to kbcommon-2.c  6.0.8.00.02 Thu 2025-09-25T1113+0200
* Rename from kbcommon.c to kbcommon-1.c 6.0.8.00.01 Thu 2025-09-25T0613+0200
* Update ### Dead key bug                6.0.8.00.00 Thu 2025-09-25T0230+0200
* Move metadata to UX levels 3 and 4     6.0.7.03.00 Sun 2025-09-21T1349+0200
* Correct and update annotations         6.0.7.02.01 Sun 2025-09-21T0143+0200
* Move kbdeadtrans.c #inc to kbcommon.c  6.0.7.02.00 Tue 2025-09-16T0315+0200
* Add 6 spare modification numbers       6.0.5.00.00 Sat 2025-08-30T2106+0200
* Add mod# 33 in main allocation table   6.0.4.01.00 Wed 2025-08-27T1834+0200
* Redocument circumflex dead key bug     6.0.4.00.00 Wed 2025-08-27T1827+0200
* Document disordered table dead key bug 6.0.3.04.00 Sun 2025-08-24T1334+0200
* Edit annotations                       6.0.3.01.01 Thu 2025-08-21T0325+0200
* Move common remainder to kbcommon.c    6.0.3.01.00 Wed 2025-08-20T2203+0200
* Add partial file kbcommon.c            6.0.3.01.00 Wed 2025-08-20T2113+0200
*
* Known bugs are documented in this file.
* See ## Known bugs
*
\*****************************************************************************/

/*****************************************************************************\
* ausVK[] - Virtual Scan Code to Virtual Key conversion table
\*****************************************************************************/

static ALLOC_SECTION_LDATA USHORT ausVK[] = {
    T00, T01, T02, T03, T04, T05, T06, T07,
    T08, T09, T0A, T0B, T0C, T0D, T0E, T0F,
    T10, T11, T12, T13, T14, T15, T16, T17,
    T18, T19, T1A, T1B, T1C, T1D, T1E, T1F,
    T20, T21, T22, T23, T24, T25, T26, T27,
    T28, T29, T2A, T2B, T2C, T2D, T2E, T2F,
    T30, T31, T32, T33, T34, T35,

    /*
     * Right-hand Shift key must have KBDEXT bit set.
     */
    T36 | KBDEXT,

    T37 | KBDMULTIVK,               // numpad_* + Shift/Alt -> SnapShot

    T38, T39, T3A, T3B, T3C, T3D, T3E,
    T3F, T40, T41, T42, T43, T44,

    /*
     * NumLock Key:
     *     KBDEXT     - VK_NUMLOCK is an Extended key
     *     KBDMULTIVK - VK_NUMLOCK or VK_PAUSE (without or with CTRL)
     */
    T45 | KBDEXT | KBDMULTIVK,

    T46 | KBDMULTIVK,

    /*
     * Number Pad keys:
     *     KBDNUMPAD  - digits 0-9 and decimal point.
     *     KBDSPECIAL - require special processing by Windows
     */
    T47 | KBDNUMPAD | KBDSPECIAL,   // Numpad 7 (Home)
    T48 | KBDNUMPAD | KBDSPECIAL,   // Numpad 8 (Up),
    T49 | KBDNUMPAD | KBDSPECIAL,   // Numpad 9 (PgUp),
    T4A,
    T4B | KBDNUMPAD | KBDSPECIAL,   // Numpad 4 (Left),
    T4C | KBDNUMPAD | KBDSPECIAL,   // Numpad 5 (Clear),
    T4D | KBDNUMPAD | KBDSPECIAL,   // Numpad 6 (Right),
    T4E,
    T4F | KBDNUMPAD | KBDSPECIAL,   // Numpad 1 (End),
    T50 | KBDNUMPAD | KBDSPECIAL,   // Numpad 2 (Down),
    T51 | KBDNUMPAD | KBDSPECIAL,   // Numpad 3 (PgDn),
    T52 | KBDNUMPAD | KBDSPECIAL,   // Numpad 0 (Ins),
    T53 | KBDNUMPAD | KBDSPECIAL,   // Numpad . (Del),

    T54, T55, T56, T57, T58, T59, T5A, T5B,
    T5C, T5D, T5E, T5F, T60, T61, T62, T63,
    T64, T65, T66, T67, T68, T69, T6A, T6B,
    T6C, T6D, T6E, T6F, T70, T71, T72, T73,
    T74, T75, T76, T77, T78, T79, T7A, T7B,
    T7C, T7D, T7E

};

static ALLOC_SECTION_LDATA VSC_VK aE0VscToVk[] = {
        { 0x10, X10 | KBDEXT              },  // Speedracer: Previous Track
        { 0x19, X19 | KBDEXT              },  // Speedracer: Next Track
        { 0x1D, X1D | KBDEXT              },  // RControl
        { 0x20, X20 | KBDEXT              },  // Speedracer: Volume Mute
        { 0x21, X21 | KBDEXT              },  // Speedracer: Launch App 2
        { 0x22, X22 | KBDEXT              },  // Speedracer: Media Play/Pause
        { 0x24, X24 | KBDEXT              },  // Speedracer: Media Stop
        { 0x2E, X2E | KBDEXT              },  // Speedracer: Volume Down
        { 0x30, X30 | KBDEXT              },  // Speedracer: Volume Up
        { 0x32, X32 | KBDEXT              },  // Speedracer: Browser Home
        { 0x35, X35 | KBDEXT              },  // Numpad Divide
        { 0x37, X37 | KBDEXT              },  // Snapshot
        { 0x38, X38 | KBDEXT              },  // RMenu
        { 0x47, X47 | KBDEXT              },  // Home
        { 0x48, X48 | KBDEXT              },  // Up
        { 0x49, X49 | KBDEXT              },  // Prior
        { 0x4B, X4B | KBDEXT              },  // Left
        { 0x4D, X4D | KBDEXT              },  // Right
        { 0x4F, X4F | KBDEXT              },  // End
        { 0x50, X50 | KBDEXT              },  // Down
        { 0x51, X51 | KBDEXT              },  // Next
        { 0x52, X52 | KBDEXT              },  // Insert
        { 0x53, X53 | KBDEXT              },  // Delete
        { 0x5B, X5B | KBDEXT              },  // Left Win
        { 0x5C, X5C | KBDEXT              },  // Right Win
        { 0x5D, X5D | KBDEXT              },  // Application
        { 0x5F, X5F | KBDEXT              },  // Speedracer: Sleep
        { 0x65, X65 | KBDEXT              },  // Speedracer: Browser Search
        { 0x66, X66 | KBDEXT              },  // Speedracer: Browser Favorites
        { 0x67, X67 | KBDEXT              },  // Speedracer: Browser Refresh
        { 0x68, X68 | KBDEXT              },  // Speedracer: Browser Stop
        { 0x69, X69 | KBDEXT              },  // Speedracer: Browser Forward
        { 0x6A, X6A | KBDEXT              },  // Speedracer: Browser Back
        { 0x6B, X6B | KBDEXT              },  // Speedracer: Launch App 1
        { 0x6C, X6C | KBDEXT              },  // Speedracer: Launch Mail
        { 0x6D, X6D | KBDEXT              },  // Speedracer: Launch Media Selector
        { 0x1C, X1C | KBDEXT              },  // Numpad Enter
        { 0x46, X46 | KBDEXT              },  // Break (Ctrl + Pause)
        { 0,      0                       }
};

static ALLOC_SECTION_LDATA VSC_VK aE1VscToVk[] = {
        { 0x1D, Y1D                       },  // Pause
        { 0   ,   0                       }
};

/*****************************************************************************\
* aVkToBits[]  - map Virtual Keys to Modifier Bits
*
* See kbd.h for a full description.
*
* The keyboard has seven shifter keys:
*     SHIFT (L & R) affects alphanumeric keys
*     CTRL  (L & R) is used to generate control characters
*     ALT   (Left)  used for generating characters by number with numpad
*     0x10  (Right) used for the Alternate Graphic modifier key
*     0x20  (Left)  AltFr (Alt French) for unspaced punctuation, graphic numpad
*     0x40  (Left)  AltLe (Alt Letter emoji) for country flags, other emoji
*     0x80  (Left)  AltQr (Alt Quick response) for math alphabets and emoji
*
* The 8th shifter (0x08) is used by the Kana Lock toggle.
*
* AltGr is right Alt, but it is not emulated by the Ctrl + Alt combo any more.
*
* AltFr is the ISO key B00, or it goes on the Caps Lock key, and that toggle
* goes then on right Control.
*
* For Kana Lock and AltQr, key E00 is repurposed (given that on French AZERTY,
* E00 is just superscript 2).
\*****************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
    { VK_SHIFT    ,   KBDSHIFT     }, // 1
    { VK_CONTROL  ,   KBDCTRL      }, // 2
    { VK_MENU     ,   KBDALT       }, // 4
                                      // 8 is KANA
    { VK_OEM_AX   ,   16           }, // AltGr key
    { VK_OEM_102  ,   32           }, // AltFr key
    { VK_CAPITAL  ,   64           }, // AltLe key on top of Caps Lock
    { VK_KANA     ,   128          }, // AltQr key on top of Kana Lock
    { 0           ,   0            }
};

/*****************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
* This is an edited transpilation by KbdUTool.
*
* 33 is an extra modification number for broken modifier key combinations. It
* just outputs the okay emoji "🆗" U1F197 so nobody is afraid of missing out on
* anything when some keys happen to work in between. 
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {
    &aVkToBits[0],
    249, // Decimal # of the last shift state in this array.
         // Any shift state beyond is ignored.
    {
    //  Modification# //           Keys Pressed Or KanaLock Toggle On
    //  ============= // ============================================
        0,            //   0, 0x00
        1,            //   1, 0x01 Shift
        8,            //   2, 0x02 Control
        SHFT_INVALID, //   3, 0x03 Shift + Control
        SHFT_INVALID, //   4, 0x04 Menu
        SHFT_INVALID, //   5, 0x05 Shift + Menu
        SHFT_INVALID, //   6, 0x06 Control + Menu
        SHFT_INVALID, //   7, 0x07 Shift + Control + Menu
        9,            //   8, 0x08 KanaLock
        10,           //   9, 0x09 KanaLock + Shift
        SHFT_INVALID, //  10, 0x0a KanaLock + Control
        SHFT_INVALID, //  11, 0x0b KanaLock + Shift + Control
        SHFT_INVALID, //  12, 0x0c KanaLock + Menu
        SHFT_INVALID, //  13, 0x0d KanaLock + Shift + Menu
        SHFT_INVALID, //  14, 0x0e KanaLock + Control + Menu
        SHFT_INVALID, //  15, 0x0f KanaLock + Shift + Control + Menu
        2,            //  16, 0x10 OEM_AX
        3,            //  17, 0x11 Shift + OEM_AX
        SHFT_INVALID, //  18, 0x12 Control + OEM_AX
        SHFT_INVALID, //  19, 0x13 Shift + Control + OEM_AX
        SHFT_INVALID, //  20, 0x14 Menu + OEM_AX
        SHFT_INVALID, //  21, 0x15 Shift + Menu + OEM_AX
        SHFT_INVALID, //  22, 0x16 Control + Menu + OEM_AX
        SHFT_INVALID, //  23, 0x17 Shift + Control + Menu + OEM_AX
        11,           //  24, 0x18 KanaLock + OEM_AX
        12,           //  25, 0x19 KanaLock + Shift + OEM_AX
        SHFT_INVALID, //  26, 0x1a KanaLock + Control + OEM_AX
        SHFT_INVALID, //  27, 0x1b KanaLock + Shift + Control + OEM_AX
        SHFT_INVALID, //  28, 0x1c KanaLock + Menu + OEM_AX
        SHFT_INVALID, //  29, 0x1d KanaLock + Shift + Menu + OEM_AX
        SHFT_INVALID, //  30, 0x1e KanaLock + Control + Menu + OEM_AX
        SHFT_INVALID, //  31, 0x1f KanaLock + Shift + Control + Menu + OEM_AX
        4,            //  32, 0x20 OEM_102
        5,            //  33, 0x21 Shift + OEM_102
        SHFT_INVALID, //  34, 0x22 Control + OEM_102
        SHFT_INVALID, //  35, 0x23 Shift + Control + OEM_102
        SHFT_INVALID, //  36, 0x24 Menu + OEM_102
        SHFT_INVALID, //  37, 0x25 Shift + Menu + OEM_102
        SHFT_INVALID, //  38, 0x26 Control + Menu + OEM_102
        SHFT_INVALID, //  39, 0x27 Shift + Control + Menu + OEM_102
        13,           //  40, 0x28 KanaLock + OEM_102
        14,           //  41, 0x29 KanaLock + Shift + OEM_102
        SHFT_INVALID, //  42, 0x2a KanaLock + Control + OEM_102
        SHFT_INVALID, //  43, 0x2b KanaLock + Shift + Control + OEM_102
        SHFT_INVALID, //  44, 0x2c KanaLock + Menu + OEM_102
        SHFT_INVALID, //  45, 0x2d KanaLock + Shift + Menu + OEM_102
        SHFT_INVALID, //  46, 0x2e KanaLock + Control + Menu + OEM_102
        SHFT_INVALID, //  47, 0x2f KanaLock + Shift + Control + Menu + OEM_102
        6,            //  48, 0x30 OEM_AX + OEM_102
        7,            //  49, 0x31 Shift + OEM_AX + OEM_102
        SHFT_INVALID, //  50, 0x32
        SHFT_INVALID, //  51, 0x33
        SHFT_INVALID, //  52, 0x34
        SHFT_INVALID, //  53, 0x35
        SHFT_INVALID, //  54, 0x36
        SHFT_INVALID, //  55, 0x37 / This does not work.
        15,           //  56, 0x38 # KanaLock + OEM_AX + OEM_102
        16,           //  57, 0x39 KanaLock + Shift + OEM_AX + OEM_102
        SHFT_INVALID, //  58, 0x3a \ This works.
        SHFT_INVALID, //  59, 0x3b
        SHFT_INVALID, //  60, 0x3c
        SHFT_INVALID, //  61, 0x3d
        SHFT_INVALID, //  62, 0x3e
        SHFT_INVALID, //  63, 0x3f
        17,           //  64, 0x40 CAPITAL
        18,           //  65, 0x41 Shift + CAPITAL
        SHFT_INVALID, //  66, 0x42 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  67, 0x43
        SHFT_INVALID, //  68, 0x44
        SHFT_INVALID, //  69, 0x45
        SHFT_INVALID, //  70, 0x46
        SHFT_INVALID, //  71, 0x47
        17,           //  72, 0x48 KanaLock + CAPITAL
        18,           //  73, 0x49 KanaLock + Shift + CAPITAL
        SHFT_INVALID, //  74, 0x4a \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  75, 0x4b
        SHFT_INVALID, //  76, 0x4c
        SHFT_INVALID, //  77, 0x4d
        SHFT_INVALID, //  78, 0x4e
        SHFT_INVALID, //  79, 0x4f / This does not work.
        33,           //  80, 0x50 # OEM_AX + CAPITAL
        33,           //  81, 0x51 # Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  82, 0x52 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  83, 0x53
        SHFT_INVALID, //  84, 0x54
        SHFT_INVALID, //  85, 0x55
        SHFT_INVALID, //  86, 0x56
        SHFT_INVALID, //  87, 0x57 / This does not work.
        33,           //  88, 0x58 # KanaLock + OEM_AX + CAPITAL
        33,           //  89, 0x59 # KanaLock + Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  90, 0x5a \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  91, 0x5b
        SHFT_INVALID, //  92, 0x5c
        SHFT_INVALID, //  93, 0x5d
        SHFT_INVALID, //  94, 0x5e
        SHFT_INVALID, //  95, 0x5f / This only works on keys other than C05,06,11, D05,06,11,12.
        29,           //  96, 0x60 OEM_102 + CAPITAL
        33,           //  97, 0x61 # Shift + OEM_102 + CAPITAL
        SHFT_INVALID, //  98, 0x62 \ This does not work.
        SHFT_INVALID, //  99, 0x63
        SHFT_INVALID, // 100, 0x64
        SHFT_INVALID, // 101, 0x65
        SHFT_INVALID, // 102, 0x66
        SHFT_INVALID, // 103, 0x67 / This only works on keys other than C05,06,11, D05,06,11,12.
        29,           // 104, 0x68 KanaLock + OEM_102 + CAPITAL
        33,           // 105, 0x69 # KanaLock + Shift + OEM_102 + CAPITAL
        SHFT_INVALID, // 106, 0x6a \ This does not work.
        SHFT_INVALID, // 107, 0x6b
        SHFT_INVALID, // 108, 0x6c
        SHFT_INVALID, // 109, 0x6d
        SHFT_INVALID, // 110, 0x6e
        SHFT_INVALID, // 111, 0x6f / This only works on keys other than C05,06,11, D05,06,11,12.
        30,           // 112, 0x70 OEM_AX + OEM_102 + CAPITAL
        33,           // 113, 0x71 # Shift + OEM_AX + OEM_102 + CAPITAL
        SHFT_INVALID, // 114, 0x72 \ This does not work.
        SHFT_INVALID, // 115, 0x73
        SHFT_INVALID, // 116, 0x74
        SHFT_INVALID, // 117, 0x75
        SHFT_INVALID, // 118, 0x76
        SHFT_INVALID, // 119, 0x77 / This only works on keys other than C05,06,11, D05,06,11,12.
        30,           // 120, 0x78 KanaLock + OEM_AX + OEM_102 + CAPITAL
        33,           // 121, 0x79 # KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL
        SHFT_INVALID, // 122, 0x7a \ This does not work.
        SHFT_INVALID, // 123, 0x7b
        SHFT_INVALID, // 124, 0x7c
        SHFT_INVALID, // 125, 0x7d
        SHFT_INVALID, // 126, 0x7e
        SHFT_INVALID, // 127, 0x7f
        19,           // 128, 0x80 KANA
        20,           // 129, 0x81 Shift + KANA
        SHFT_INVALID, // 130, 0x82
        SHFT_INVALID, // 131, 0x83
        SHFT_INVALID, // 132, 0x84
        SHFT_INVALID, // 133, 0x85
        SHFT_INVALID, // 134, 0x86
        SHFT_INVALID, // 135, 0x87
        19,           // 136, 0x88 KanaLock + KANA
        20,           // 137, 0x89 KanaLock + Shift + KANA
        SHFT_INVALID, // 138, 0x8a
        SHFT_INVALID, // 139, 0x8b
        SHFT_INVALID, // 140, 0x8c
        SHFT_INVALID, // 141, 0x8d
        SHFT_INVALID, // 142, 0x8e
        SHFT_INVALID, // 143, 0x8f
        21,           // 144, 0x90 OEM_AX + KANA
        22,           // 145, 0x91 Shift + OEM_AX + KANA
        SHFT_INVALID, // 146, 0x92
        SHFT_INVALID, // 147, 0x93
        SHFT_INVALID, // 148, 0x94
        SHFT_INVALID, // 149, 0x95
        SHFT_INVALID, // 150, 0x96
        SHFT_INVALID, // 151, 0x97
        21,           // 152, 0x98 KanaLock + OEM_AX + KANA
        22,           // 153, 0x99 KanaLock + Shift + OEM_AX + KANA
        SHFT_INVALID, // 154, 0x9a
        SHFT_INVALID, // 155, 0x9b
        SHFT_INVALID, // 156, 0x9c
        SHFT_INVALID, // 157, 0x9d
        SHFT_INVALID, // 158, 0x9e
        SHFT_INVALID, // 159, 0x9f
        23,           // 160, 0xa0 OEM_102 + KANA
        24,           // 161, 0xa1 Shift + OEM_102 + KANA
        SHFT_INVALID, // 162, 0xa2
        SHFT_INVALID, // 163, 0xa3
        SHFT_INVALID, // 164, 0xa4
        SHFT_INVALID, // 165, 0xa5
        SHFT_INVALID, // 166, 0xa6
        SHFT_INVALID, // 167, 0xa7
        23,           // 168, 0xa8 KanaLock + OEM_102 + KANA
        24,           // 169, 0xa9 KanaLock + Shift + OEM_102 + KANA
        SHFT_INVALID, // 170, 0xaa
        SHFT_INVALID, // 171, 0xab
        SHFT_INVALID, // 172, 0xac
        SHFT_INVALID, // 173, 0xad
        SHFT_INVALID, // 174, 0xae
        SHFT_INVALID, // 175, 0xaf
        25,           // 176, 0xb0 OEM_AX + OEM_102 + KANA
        26,           // 177, 0xb1 Shift + OEM_AX + OEM_102 + KANA
        SHFT_INVALID, // 178, 0xb2
        SHFT_INVALID, // 179, 0xb3
        SHFT_INVALID, // 180, 0xb4
        SHFT_INVALID, // 181, 0xb5
        SHFT_INVALID, // 182, 0xb6
        SHFT_INVALID, // 183, 0xb7
        25,           // 184, 0xb8 KanaLock + OEM_AX + OEM_102 + KANA
        26,           // 185, 0xb9 KanaLock + Shift + OEM_AX + OEM_102 + KANA
        SHFT_INVALID, // 186, 0xba
        SHFT_INVALID, // 187, 0xbb
        SHFT_INVALID, // 188, 0xbc
        SHFT_INVALID, // 189, 0xbd
        SHFT_INVALID, // 190, 0xbe
        SHFT_INVALID, // 191, 0xbf
        27,           // 192, 0xc0 CAPITAL + KANA
        28,           // 193, 0xc1 Shift + CAPITAL + KANA
        SHFT_INVALID, // 194, 0xc2 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 195, 0xc3  \ Therefore it is redundant at 208, 0xd0.
        SHFT_INVALID, // 196, 0xc4
        SHFT_INVALID, // 197, 0xc5
        SHFT_INVALID, // 198, 0xc6
        SHFT_INVALID, // 199, 0xc7
        27,           // 200, 0xc8 KanaLock + CAPITAL + KANA
        28,           // 201, 0xc9 Shift + CAPITAL + KANA
        SHFT_INVALID, // 202, 0xca \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 203, 0xcb  \ Therefore it is redundant at 216, 0xd8.
        SHFT_INVALID, // 204, 0xcc
        SHFT_INVALID, // 205, 0xcd
        SHFT_INVALID, // 206, 0xce
        SHFT_INVALID, // 207, 0xcf / This is redundant for 193, 0xc1.
        28,           // 208, 0xd0 OEM_AX + CAPITAL + KANA
        33,           // 209, 0xd1 Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 210, 0xd2 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 211, 0xd3
        SHFT_INVALID, // 212, 0xd4
        SHFT_INVALID, // 213, 0xd5
        SHFT_INVALID, // 214, 0xd6
        SHFT_INVALID, // 215, 0xd7 / This is redundant for 201, 0xc9.
        28,           // 216, 0xd8 KanaLock + OEM_AX + CAPITAL + KANA
        33,           // 217, 0xd9 KanaLock + Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 218, 0xda \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 219, 0xdb
        SHFT_INVALID, // 220, 0xdc
        SHFT_INVALID, // 221, 0xdd
        SHFT_INVALID, // 222, 0xde
        SHFT_INVALID, // 223, 0xdf / This only works on keys other than C05,06,11, D05,06,11,12.
        31,           // 224, 0xe0 OEM_102 + CAPITAL + KANA
        33,           // 225, 0xe1 # Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 226, 0xe2 \ This does not work.
        SHFT_INVALID, // 227, 0xe3
        SHFT_INVALID, // 228, 0xe4
        SHFT_INVALID, // 229, 0xe5
        SHFT_INVALID, // 230, 0xe6
        SHFT_INVALID, // 231, 0xe7 / This only works on keys other than C05,06,11, D05,06,11,12.
        31,           // 232, 0xe8 KanaLock + OEM_102 + CAPITAL + KANA
        33,           // 233, 0xe9 # KanaLock + Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 234, 0xea \ This does not work.
        SHFT_INVALID, // 235, 0xeb
        SHFT_INVALID, // 236, 0xec
        SHFT_INVALID, // 237, 0xed
        SHFT_INVALID, // 238, 0xee
        SHFT_INVALID, // 239, 0xef / This only works on keys other than C05,06,11, D05,06,11,12.
        32,           // 240, 0xf0 OEM_AX + OEM_102 + CAPITAL + KANA
        33,           // 241, 0xf1 # Shift + OEM_AX + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 242, 0xf2 \ This does not work.
        SHFT_INVALID, // 243, 0xf3
        SHFT_INVALID, // 244, 0xf4
        SHFT_INVALID, // 245, 0xf5
        SHFT_INVALID, // 246, 0xf6
        SHFT_INVALID, // 247, 0xf7 / This only works on keys other than C05,06,11, D05,06,11,12.
        32,           // 248, 0xf8 KanaLock + OEM_AX + OEM_102 + CAPITAL + KANA
        33,           // 249, 0xf9 # KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL + KANA
     }                //           \ This does not work.
};

/*****************************************************************************\
* Allocation tables
*
* When the Keyboard Table Generation Tool (Unicode) transpiles a KLC file,
* it generates this list based on the assumption that keyboard layouts may use
* up to 56 shift states.
*
* aVkToWch2[]  - Virtual Key to WCHAR translation for 2 shift states
* aVkToWch3[]  - Virtual Key to WCHAR translation for 3 shift states
* aVkToWch4[]  - Virtual Key to WCHAR translation for 4 shift states
* aVkToWch5[]  - Virtual Key to WCHAR translation for 5 shift states
* aVkToWch6[]  - Virtual Key to WCHAR translation for 6 shift states
* aVkToWch7[]  - Virtual Key to WCHAR translation for 7 shift states
* aVkToWch8[]  - Virtual Key to WCHAR translation for 8 shift states
* aVkToWch9[]  - Virtual Key to WCHAR translation for 9 shift states
* aVkToWch10[]  - Virtual Key to WCHAR translation for 10 shift states
* aVkToWch11[]  - Virtual Key to WCHAR translation for 11 shift states
* aVkToWch12[]  - Virtual Key to WCHAR translation for 12 shift states
* aVkToWch13[]  - Virtual Key to WCHAR translation for 13 shift states
* aVkToWch14[]  - Virtual Key to WCHAR translation for 14 shift states
* aVkToWch15[]  - Virtual Key to WCHAR translation for 15 shift states
* aVkToWch16[]  - Virtual Key to WCHAR translation for 16 shift states
* aVkToWch17[]  - Virtual Key to WCHAR translation for 17 shift states
* aVkToWch18[]  - Virtual Key to WCHAR translation for 18 shift states
* aVkToWch19[]  - Virtual Key to WCHAR translation for 19 shift states
* aVkToWch20[]  - Virtual Key to WCHAR translation for 20 shift states
* aVkToWch21[]  - Virtual Key to WCHAR translation for 21 shift states
* aVkToWch22[]  - Virtual Key to WCHAR translation for 22 shift states
* aVkToWch23[]  - Virtual Key to WCHAR translation for 23 shift states
* aVkToWch24[]  - Virtual Key to WCHAR translation for 24 shift states
* aVkToWch25[]  - Virtual Key to WCHAR translation for 25 shift states
* aVkToWch26[]  - Virtual Key to WCHAR translation for 26 shift states
* aVkToWch27[]  - Virtual Key to WCHAR translation for 27 shift states
* aVkToWch28[]  - Virtual Key to WCHAR translation for 28 shift states
* aVkToWch29[]  - Virtual Key to WCHAR translation for 29 shift states
* aVkToWch30[]  - Virtual Key to WCHAR translation for 30 shift states
* aVkToWch31[]  - Virtual Key to WCHAR translation for 31 shift states
* aVkToWch32[]  - Virtual Key to WCHAR translation for 32 shift states
* aVkToWch33[]  - Virtual Key to WCHAR translation for 33 shift states
* aVkToWch34[]  - Virtual Key to WCHAR translation for 34 shift states
* aVkToWch35[]  - Virtual Key to WCHAR translation for 35 shift states
* aVkToWch36[]  - Virtual Key to WCHAR translation for 36 shift states
* aVkToWch37[]  - Virtual Key to WCHAR translation for 37 shift states
* aVkToWch38[]  - Virtual Key to WCHAR translation for 38 shift states
* aVkToWch39[]  - Virtual Key to WCHAR translation for 39 shift states
* aVkToWch40[]  - Virtual Key to WCHAR translation for 40 shift states
* aVkToWch41[]  - Virtual Key to WCHAR translation for 41 shift states
* aVkToWch42[]  - Virtual Key to WCHAR translation for 42 shift states
* aVkToWch43[]  - Virtual Key to WCHAR translation for 43 shift states
* aVkToWch44[]  - Virtual Key to WCHAR translation for 44 shift states
* aVkToWch45[]  - Virtual Key to WCHAR translation for 45 shift states
* aVkToWch46[]  - Virtual Key to WCHAR translation for 46 shift states
* aVkToWch47[]  - Virtual Key to WCHAR translation for 47 shift states
* aVkToWch48[]  - Virtual Key to WCHAR translation for 48 shift states
* aVkToWch49[]  - Virtual Key to WCHAR translation for 49 shift states
* aVkToWch50[]  - Virtual Key to WCHAR translation for 50 shift states
* aVkToWch51[]  - Virtual Key to WCHAR translation for 51 shift states
* aVkToWch52[]  - Virtual Key to WCHAR translation for 52 shift states
* aVkToWch53[]  - Virtual Key to WCHAR translation for 53 shift states
* aVkToWch54[]  - Virtual Key to WCHAR translation for 54 shift states
* aVkToWch55[]  - Virtual Key to WCHAR translation for 55 shift states
* aVkToWch56[]  - Virtual Key to WCHAR translation for 56 shift states
*
* Table attributes: Unordered Scan, null-terminated
*
* Search this table for an entry with a matching Virtual Key to find the
* corresponding unshifted and shifted WCHAR characters.
*
* Special values for VirtualKey (column 1)
*     0xff          - dead chars for the previous entry
*     0             - terminate the list
*
* Special values for Attributes (column 2)
*     CAPLOK bit    - CAPS-LOCK affects this key like SHIFT, that swaps effect.
*     SGCAPS        - Swiss-German Capitals: CAPS-LOCK remaps levels 1 & 2.
*                     This is also subject to KANA-LOCK.
*     KANALOK       - KANA-LOCK affects this key.
*     ALTGR         - KANA-LOCK affects this key (KbdUTool transpilation).
*     KBD           - CAPS-LOCK and KANA-LOCK affect this key (KbdUTool).
*
*                   See kbcommon.h subsection 7.3
*
* Special values for wch[*] (columns 3..)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (able to generate multiple code units)
*
*
* ## Known bugs
*    ‾‾‾‾‾‾‾‾‾‾
* ### Caps Lock bug
*
* The feature named Swiss German Capitals (SGCAPS) is unable to support dead
* keys, and above all, it is unable to support multiple code units (ligatures).
*
* https://archives.miloush.net/michkap/archive/2010/07/07/10032340.html
* https://archives.miloush.net/michkap/archive/2006/01/16/513088.html
*
* As a consequence, on AZERTY, where key C11 (VK_OEM_3) has "ù" and requires
* SGCaps to support "Ù", the spaced-out double angle quotation mark at the
* shift level of that key is unspaced-out when Caps Lock is on, because as a
* ligature it just does not work, given the feature is halfways broken.
*
* This bug was documented in the code as follows:
*
// This key is bugged, as neither the short form nor the long form works as designed. 2025-06-08T0338+0200
  {VK_OEM_3     ,SGCAPS ,0x00f9   ,WCH_LGTR ,0x2026   ,WCH_LGTR ,0x00ab   ,'%'      ,'A'      ,'\''     ,WCH_NONE ,'\''     ,'%'      ,'`'      ,0x208d   ,'A'      ,0x207d   ,0x208d   ,'\''     ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
//{0xff         ,0      ,0x00d9   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0xff         ,0      ,0x00d9   ,0x00ab   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
//{VK_OEM_3     ,0      ,0x00d9   ,WCH_LGTR }, // This does not work.
//{VK_OEM_3     ,0      ,0x00d9   ,0x00ab   }, // This works.
*
*
* ### Level 7 bug
*
* The level 7 (AltGr + AltFr, i.e. VK_OEM_AX + VK_OEM_102) does not work when
* KanaLock is on, if the key is subject to KanaLock.
*
* To work around this issue, the level 7 with KanaLock should be redundant.
*
*
* ### Level 10 bug
*
* The level 10 (Shift + CAPITAL, where CAPITAL is the modifier added on top
* of the Caps Lock toggle key) does not work on column 02, i.e. keys "2",
* "W", "S", "X" of the US-QWERTY.
*
* To work around this issue, mappings on these keys are replicated on unused
* keys.
*
*
* ### Dead key bug
*
* Dead keys may get buggy in that they are turned off, or the circumflex dead
* key randomly adds its diacritic without being pressed, like so:
*
*     ôoôooooôooôooôoôôôooôooooooooooooooôoôoooôooôooôoôoooôoǒôoôôôoôooôooooôoôoooooôô
*     2025-08-23T0656+0200
*
*     buĝ̂  2025-08-27T1133+0200 cîrĉumflêê̂ deâ᪰̂̂̂ ̂ key rân᪰᪰ômly âctîvâtêd̂̂ŵîtĥoût presŝinǧît
*
* (bug […] circumflex dead key randomly activated without pressing it)
*
* This bug occurred in builds 6.0.3.03 and 6.0.3.04, where windows.h was
* included in a header instead of being included in the main C source, and so
* was kbd.h.
*
* This bug not occurring since #include <windows.h> was moved back to C sources
* for next version 6.0.4.00 on Wed 2025-08-27T1304+0200 fooled into assuming a
* relationship with the way how the windows.h header is included.
*
* As in build 6.0.3.03, the main allocation table was also upside down, it
* seemed like this was causing the bug. But ultimately it was not.
*
* Anyway, build 6.0.3.03 is available as a pre-release for test purposes:
* https://github.com/dispoclavier/nouvel-azerty/releases/tag/6.0.3.03
*
* Build 6.0.3.04 was released as version 6.0.3 on 2025-08-24T2048+0200 because
* it seemed okay. It ended up turning crazy days later (2025-08-27T1133+0200).
*
* The bug occurred again at some point in build 6.0.7.00. While holding down
# the comma key, the output turned like so:
*
*     ḙ,ḙ,ȟ,ȟ,ḙ,ȟ,ȟ,ȟ,ȟ,ȟ,ḙ,ȟ,ḙ,ȟ,ḙ,ḙ,ḙ,ȟ,ȟ,ḙ,ȟ,ȟ,ḙ,ḙ,ȟ,ȟ,ḙ,ȟ,ḙ,ḙ,ḙ,ȟ,ḙ,ḙ,ḙ,ȟ,ȟ,ȟ,ȟ,ȟ,ḙ,ḙ,ḙ,ȟ,ȟ,ḙ,ḙ,ȟ,ȟ,ȟ,ȟ,ȟ,ḙ,ḙ,ȟ,
*     2025-09-15T0241+0200
*
*     ȟbṷǧ̌ďǐšḙpḙǒ̭̭̌̌
*     bug dispo debugged by reboot 2025-09-15T0246+0200
*
* Rebooting Windows 10 Pro 22H2 19045.2006 fixed it, indeed.
*
* Hunting down the cause of this bug led to the assumption that it might be
* a matter of where exactly in the C source the DEADTRANS macro call array is
* located. Since build 6.0.7.02, it is included exactly like when KbdUTool
* transpiles a KLC file, except that it was not followed by the ligature array,
* conveniently located in the C source at that point, because it contains the
* variant identifier string output.
* https://github.com/dispoclavier/nouvel-azerty/blob/c3f0eaad69f3e9682c8d78267e589bdca4b822b4/windows/kbcommon.c#L839
*
* But build 6.0.7.03, tested since 2025-09-23T0120+0200, and released as 6.0.7
* on 2025-09-23T0453+0200, exposed this hideous bug on 2025-09-24T2041+0200.
* While pressing the comma key, again:
*
*     ḙ,ḙ,ḙ,ḙ,ȟ,ȟ,ḙ,ȟ,ḙ,ȟ,ḙ,ḙ,ȟ,ȟ,ȟ,ȟ,ḙ,ȟ,ȟ,ḙ,ḙ,ḙ,ḙ,ḙ,ȟ,ȟ,ḙ,ȟ,ȟ,ȟ,ȟ,ḙ,ḙ,ȟ,ḙ,ḙ,ḙ,ḙ,ȟ,ȟ,ḙ,ḙ,ȟ,ȟ,ḙ,2025-09-24T2041+0200
*
* (Again.) Switching to another variant had the usual effect of stopping the
* bug, but after switching back, the bug resumed immediately, until Windows was
* rebooted.
*
* Subsequently, starting with build 6.0.8.00, the source code is additionally
* divided into even more snippets, included in a way exactly reproducing the
* transpilation order of KbdUTool, even if the definite order is determined in
* KbdTables.
* See kbcommon-3.c
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS2 aVkToWch2[] = {
  //                    |         |  Shift  |
  //                    |=========|=========|
  {VK_TAB       ,0      ,'\t'     ,'\t'     },
  {0            ,0      ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS9 aVkToWch9[] = {
  //                    |         |  Shift  |         |S+       |         |S+       |         |S+       |  Ctrl   |
  // Modification #     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |
  // UX Level           |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |  Ctrl   |
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {VK_BACK      ,0      ,'\b'     ,'\b'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x007f   },
  // The escape key yields the version # at level 3, and a short variant descriptor at level 4.
  {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x001b   },
  {VK_RETURN    ,0      ,'\r'     ,'\r'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'\n'     },
  {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0003   },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

// Here comes the main allocation table aVkToWch40[] of each variant.
// See kb*****[*]-allo.c

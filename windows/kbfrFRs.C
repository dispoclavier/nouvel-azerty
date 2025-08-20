/*****************************************************************************\
* Module Name: kbfrFRs.C
*
* keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
* Copyright (c) 2014-2025, Marcel Schneider dev[arobase]dispoclavier.com
*
* History:
* Move MCUs to kbligatures.c & others    6.0.3.00.00 Wed 2025-08-20T1930+0200
* Sync ligatures with kbfrFRsr.c         6.0.3.00.00
* U2060 on spacebar at mod# 29..32       6.0.3.00.00
* Move DEADTRANS calls to kbdeadtrans.c  6.0.2.01.00 Tue 2025-08-19T1952+0200
* Replace duplicate with SEAL U1F9AD     6.0.2.00.00 Tue 2025-08-19T1710+0200
* Debug Shift + CAPITAL + KANA           6.0.1.00.00 Wed 2025-08-13T1934+0200
* Use Shift + CAPITAL + KANA fwiw        6.0.0.06.00 Sun 2025-08-10T1736+0200
* Swap bold and monospace digits         6.0.0.05.00 Sun 2025-08-10T1547+0200
* Update dead key content                6.0.0.04.00 Sat 2025-08-09T2027+0200
* Move ligatures to the top              6.0.0.03.00 Fri 2025-08-08T1855+0200
* Update dead key content                6.0.0.02.00 Fri 2025-08-08T0942+0200
* Update dead key content "group"        6.0.0.01.00 Thu 2025-08-07T1824+0200
* Partially swap B08 and B10             6.0.0.00.00 Mon 2025-07-28T1434+0200
* Update dead key content "reversed"     5.3.0.34.00 Sat 2025-07-26T2136+0200
* Restore initial dead char U+1D19       5.3.0.33.00 Sat 2025-07-26T1723+0200
* Readd (move) currency sign             5.3.0.32.00 Fri 2025-07-25T2358+0200
* Add support for bracketed ellipsis     5.3.0.31.00 Fri 2025-07-25T2119+0200
* Swap ':', '#' on ADD, NP4 in ASCII     5.3.0.30.00 Tue 2025-07-22T0704+0200
* Swap colon, NBTSP on ADD, NUMPAD4      5.3.0.29.00 Tue 2025-07-22T0452+0200
* NBTSP U+202F on Shift + VK_NUMPAD4     5.3.0.28.00 Tue 2025-07-22T0353+0200
* Add all-in-one FR, EU, UN flags        5.3.0.27.00 Sun 2025-07-20T0233+0200
* Partial disruptive file renaming       5.3.0.26.00 Wed 2025-07-16T2113+0200
* Debug variant name output              5.3.0.25.00 Sat 2025-07-05T1742+0200
* Debug variant name output              5.3.0.24.00 Sat 2025-07-05T1706+0200
* Debug BACK, add variant&version        5.3.0.23.00 Sat 2025-07-05T1619+0200
* Fill unused levels of numpad keys      5.3.0.22.00 Thu 2025-07-03T2047+0200
* Upgrade numpad as designed             5.3.0.21.00 Wed 2025-07-02T1314+0200
* Test numpad Shift level                5.3.0.20.00 Tue 2025-07-01T1714+0200
* Test numpad extension                  5.3.0.19.00 Tue 2025-07-01T1604+0200
* Add script math alpha, more emoji      5.3.0.18.00 Mon 2025-06-30T1402+0200
* Prep support more live key emoji       5.3.0.17.00 Sun 2025-06-29T1634+0200
* Debug math alphabets on live keys      5.3.0.16.00 Sun 2025-06-29T0044+0200
* Add 4 math alphabets on live keys      5.3.0.15.00 Sat 2025-06-28T1957+0200
* Test alloc table emoji extension       5.3.0.14.00 Sat 2025-06-28T0859+0200
* Allocate 3 empty level-9 positions     5.3.0.13.00 Fri 2025-06-27T2327+0200
* Move ligatures below alloc tables      5.3.0.12.03 Thu 2025-06-26T1755+0200
* Improve dead key content layout        5.3.0.12.02 Thu 2025-06-26T1743+0200
* Debug dead key content sort order      5.3.0.12.01 Thu 2025-06-26T0819+0200
* Test KANA modifier on KanaLock key     5.3.0.12.00 Tue 2025-06-24T0450+0200
* Debug level-10 digit emoji             5.3.0.11.00 Sun 2025-06-22T0639+0200
* Append WJ to level-10 digit emoji      5.3.0.10.00 Sun 2025-06-22T0519+0200
* Replace cursive non-joiner with WJ      5.3.0.9.00 Sat 2025-06-21T0826+0200
* Debug level-10 letter emoji             5.3.0.8.00 Fri 2025-06-20T0934+0200
* Level-10 letter emoji, subdiv flags     5.3.0.7.00 Fri 2025-06-20T0717+0200
* Work around the column-02 bug           5.3.0.6.00 Thu 2025-06-19T0817+0200
* Debug level-10 tag characters           5.3.0.5.00 Thu 2025-06-19T0640+0200
* Level 10 for tag characters             5.3.0.4.00 Thu 2025-06-19T0504+0200
* Debug level-9 infrastructure            5.3.0.3.00 Wed 2025-06-18T0317+0200
* Complete level-9 infrastructure         5.3.0.2.00 Tue 2025-06-17T1656+0200
* Replicate row-E emoji on level 9        5.3.0.1.00 Mon 2025-06-16T2153+0200
* Support regional indicator letters      5.3.0.0.00 Mon 2025-06-16T1643+0200
* Debug circumflex in legacy code         5.2.0.5.00 Sun 2025-06-15T1248+0200
* Add U+1F642 emoji, debug cedilla        5.2.0.4.00 Fri 2025-06-13T0645+0200
* Change cedilla dead character           5.2.0.3.12 Thu 2025-06-12T2330+0200
* Extend DEADTRANS macro                             Wed 2025-06-11T1239+0200
* Document SGCaps bug                                Sun Jun 08 03:57 2025
* Debug key C11                           5.2.0.2    Sun Jun 08 03:02 2025
* Correct high surrogates                            Sat Jun 07 00:42 2025
* Add 0xD83D                                         Fri Jun 06 08:45 2025
* Support high surrogates                            Thu Jun 05 03:07 2025
* Simple deadkeys                         5.2.0.0    Thu Jun 05 03:07 2025
* Update group char v5.2                             Mon Jun 02 04:03 2025
* Sync key D07, v5.1                                 Mon Apr 28 09:20 2025
* Upgrade to v5.1                                    Fri Apr 18 02:32 2025
* Upgrade to v5 complete                             Sun Apr 13 18:44 2025
* Upgrade to v5                                      Tue Apr 01 13:32 2025
* Work around SGCaps bug                             Sat Dec 21 07:04 2024
* Debug layout                                       Fri Dec 20 23:55 2024
* Fix transpiled, extend                             Fri Dec 20 20:01 2024
* KBDTOOL v3.40 - Created                            Thu Dec 19 14:03:05 2024
\*****************************************************************************/

#include <windows.h>
#include "kbd.h"
#include "kbfrFRs.h"
#include "kbcommon.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

#include "kbdeadtrans.c"

static ALLOC_SECTION_LDATA LIGATURE16 aLigature[] = {

  #include "kbligazerty.c"

  {VK_ESCAPE    ,4      ,' '      ,'f'      ,'r'      ,'_'      ,'F'      ,'R'      ,'_'      ,'s'      ,'e'      ,'m'      ,'i'      ,'_'      ,'a'      ,'u'      ,'t'      ,'o'      },

  #include "kbligatures.c"

  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }

};

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
*     SHIFT (L & R) affects alphanumeric keys;
*     CTRL  (L & R) is used to generate control characters;
*     ALT   (Left)  used for generating characters by number with numpad.
*     0x10  (Right) emulates the Alternate Graphic modifier key
*     0x20  (Left)  AltFr (Alt French) for unspaced punctuation, graphic numpad
*     0x40  (Left)  AltLe (Alt Letter emoji) for country flags, other emoji
*     0x80  (Left)  AltQr (Alt Quick response) for math alphabets and emoji
*
* While AltGr is right Alt, AltFr is the ISO key B00, or it goes on Caps Lock,
* that goes then on right Control.
*
* For Kana Lock and AltQr, key E00 is repurposed (as on French AZERTY, this is
* superscript 2).
\*****************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
    { VK_SHIFT    ,   KBDSHIFT     },
    { VK_CONTROL  ,   KBDCTRL      },
    { VK_MENU     ,   KBDALT       },
    { VK_OEM_AX   ,   16           }, // AltGr key
    { VK_OEM_102  ,   32           }, // AltFr key
    { VK_CAPITAL  ,   64           }, // AltLe key on top of Caps Lock key
    { VK_KANA     ,   128          }, // AltQr key on top of Kana Lock key
    { 0           ,   0            }
};

/*****************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
* This is an edited transpilation by KbdUTool.
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
        15,           //  80, 0x50 # OEM_AX + CAPITAL
        18,           //  81, 0x51 # Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  82, 0x52 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  83, 0x53
        SHFT_INVALID, //  84, 0x54
        SHFT_INVALID, //  85, 0x55
        SHFT_INVALID, //  86, 0x56
        SHFT_INVALID, //  87, 0x57 / This does not work.
        15,           //  88, 0x58 # KanaLock + OEM_AX + CAPITAL
        18,           //  89, 0x59 # KanaLock + Shift + OEM_AX + CAPITAL
        SHFT_INVALID, //  90, 0x5a \ This only works on keys other than (B..E)02.
        SHFT_INVALID, //  91, 0x5b
        SHFT_INVALID, //  92, 0x5c
        SHFT_INVALID, //  93, 0x5d
        SHFT_INVALID, //  94, 0x5e
        SHFT_INVALID, //  95, 0x5f / This only works on keys other than C05,06,11, D05,06,11,12.
        29,           //  96, 0x60 # OEM_102 + CAPITAL
        18,           //  97, 0x61 # Shift + OEM_102 + CAPITAL
        SHFT_INVALID, //  98, 0x62 \ This does not work.
        SHFT_INVALID, //  99, 0x63
        SHFT_INVALID, // 100, 0x64
        SHFT_INVALID, // 101, 0x65
        SHFT_INVALID, // 102, 0x66
        SHFT_INVALID, // 103, 0x67 / This only works on keys other than C05,06,11, D05,06,11,12.
        29,           // 104, 0x68 # KanaLock + OEM_102 + CAPITAL
        18,           // 105, 0x69 # KanaLock + Shift + OEM_102 + CAPITAL
        SHFT_INVALID, // 106, 0x6a \ This does not work.
        SHFT_INVALID, // 107, 0x6b
        SHFT_INVALID, // 108, 0x6c
        SHFT_INVALID, // 109, 0x6d
        SHFT_INVALID, // 110, 0x6e
        SHFT_INVALID, // 111, 0x6f / This only works on keys other than C05,06,11, D05,06,11,12.
        30,           // 112, 0x70 # OEM_AX + OEM_102 + CAPITAL
        18,           // 113, 0x71 # Shift + OEM_AX + OEM_102 + CAPITAL
        SHFT_INVALID, // 114, 0x72 \ This does not work.
        SHFT_INVALID, // 115, 0x73
        SHFT_INVALID, // 116, 0x74
        SHFT_INVALID, // 117, 0x75
        SHFT_INVALID, // 118, 0x76
        SHFT_INVALID, // 119, 0x77 / This only works on keys other than C05,06,11, D05,06,11,12.
        30,           // 120, 0x78 # KanaLock + OEM_AX + OEM_102 + CAPITAL
        18,           // 121, 0x79 # KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL
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
        18,           // 209, 0xd1 Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 210, 0xd2 \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 211, 0xd3
        SHFT_INVALID, // 212, 0xd4
        SHFT_INVALID, // 213, 0xd5
        SHFT_INVALID, // 214, 0xd6
        SHFT_INVALID, // 215, 0xd7 / This is redundant for 201, 0xc9.
        28,           // 216, 0xd8 KanaLock + OEM_AX + CAPITAL + KANA
        18,           // 217, 0xd9 KanaLock + Shift + OEM_AX + CAPITAL + KANA
        SHFT_INVALID, // 218, 0xda \ This only works on keys other than (B..E)02.
        SHFT_INVALID, // 219, 0xdb
        SHFT_INVALID, // 220, 0xdc
        SHFT_INVALID, // 221, 0xdd
        SHFT_INVALID, // 222, 0xde
        SHFT_INVALID, // 223, 0xdf / This only works on keys other than C05,06,11, D05,06,11,12.
        31,           // 224, 0xe0 # OEM_102 + CAPITAL + KANA
        18,           // 225, 0xe1 # Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 226, 0xe2 \ This does not work.
        SHFT_INVALID, // 227, 0xe3
        SHFT_INVALID, // 228, 0xe4
        SHFT_INVALID, // 229, 0xe5
        SHFT_INVALID, // 230, 0xe6
        SHFT_INVALID, // 231, 0xe7 / This only works on keys other than C05,06,11, D05,06,11,12.
        31,           // 232, 0xe8 # KanaLock + OEM_102 + CAPITAL + KANA
        18,           // 233, 0xe9 # KanaLock + Shift + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 234, 0xea \ This does not work.
        SHFT_INVALID, // 235, 0xeb
        SHFT_INVALID, // 236, 0xec
        SHFT_INVALID, // 237, 0xed
        SHFT_INVALID, // 238, 0xee
        SHFT_INVALID, // 239, 0xef / This only works on keys other than C05,06,11, D05,06,11,12.
        32,           // 240, 0xf0 # OEM_AX + OEM_102 + CAPITAL + KANA
        18,           // 241, 0xf1 # Shift + OEM_AX + OEM_102 + CAPITAL + KANA
        SHFT_INVALID, // 242, 0xf2 \ This does not work.
        SHFT_INVALID, // 243, 0xf3
        SHFT_INVALID, // 244, 0xf4
        SHFT_INVALID, // 245, 0xf5
        SHFT_INVALID, // 246, 0xf6
        SHFT_INVALID, // 247, 0xf7 / This only works on keys other than C05,06,11, D05,06,11,12.
        32,           // 248, 0xf8 # KanaLock + OEM_AX + OEM_102 + CAPITAL + KANA
        18,           // 249, 0xf9 # KanaLock + Shift + OEM_AX + OEM_102 + CAPITAL + KANA
     }                //           \ This does not work.
};

/*****************************************************************************\
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
*     SGCAPS        - Swiss-German Capitals: CAPS-LOCK changes the map at levels 1 & 2.
*                     This is also subject to KANA-LOCK.
*     KANALOK       - KANA-LOCK affects this key.
*     ALTGR         - KANA-LOCK affects this key (KbdUTool transpilation).
*     KBD           - CAPS-LOCK and KANA-LOCK affect this key (KbdUTool transpilation).
*
*                   See kbcommon.h subsection 7.3
*
* Special values for wch[*] (columns 3..)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (able to generate multiple characters)
*
\*****************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS2 aVkToWch2[] = {
//                      |         |  Shift  |
//                      |=========|=========|
  {VK_TAB       ,0      ,'\t'     ,'\t'     },
  {0            ,0      ,0        ,0        }
};

/*****************************************************************************\
* Known bugs
*
* The level 7 (AltGr + AltFr, i.e. VK_OEM_AX + VK_OEM_102) does not work when
* KanaLock is on, if the key is subject to KanaLock. To work around this issue,
* the level 7 with KanaLock should be redundant.
*
* The level 10 (Shift + CAPITAL, where CAPITAL is the modifier added on top
* of the Caps Lock toggle key) does not work on column 02, i.e. keys "2",
* "W", "S", "X" of the US-QWERTY. To work around this issue, mappings on
* these keys are replicated on unused keys.
\*****************************************************************************/                                                                                             // KanaLock+AltGr+AltFr         Shift+CAPITAL
                                                                                                                                                                            // does not work.               does not work on keys
static ALLOC_SECTION_LDATA VK_TO_WCHARS33 aVkToWch33[] = {                                                                                                                  //|||||||||||                   (B..E)02.
  //                    |         |  Shift  |  AltGr  | S+AltGr |  AltFr  | S+AltFr |AltGr+Fr | S+Gr+Fr |  Ctrl   | KanaLock| KL+Shift| KL+AltGr|KL+S+AlGr| KL+AltFr|KL+S+AlFr|KL+AGr+Fr|KL+S+Gr+F| CAPITAL |S+CAPITAL|
  //                    |         |         |         |         |         |         |         |         |         |         |         |         |         |         |         |AlFr+AlQr|S+AFr+AQr|         |AGr+CAPIT|
  //                    |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |   17    |   18    |   19    |   20    |   21    |   22    |   23    |   24    |   25    |   26    |   27    |   28    |   29    |   30    |   31    |   32    |
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {VK_OEM_102   ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'1'          ,SGCAPS ,0x00b2   ,0x00b3   ,'1'      ,'&'      ,'1'      ,0x00b9   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'1'      ,'1'      ,'1'      ,0x2081   ,'1'      ,0x00b9   ,0x2081   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'1'          ,0      ,0x2082   ,0x2083   },
  {'2'          ,KBD    ,0x00e9   ,0x00c9   ,'2'      ,WCH_DEAD ,'2'      ,0x00b2   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'2'      ,'2'      ,'2'      ,0x2082   ,'2'      ,0x00b2   ,0x2082   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'~'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'3'          ,ALTGR  ,'\"'     ,0x2013   ,'3'      ,'#'      ,'3'      ,0x00b3   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'3'      ,'3'      ,'3'      ,0x2083   ,'3'      ,0x00b3   ,0x2083   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'4'          ,ALTGR  ,0x2019   ,0x2014   ,'4'      ,'{'      ,'4'      ,0x2074   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'4'      ,'4'      ,'4'      ,0x2084   ,'4'      ,0x2074   ,0x2084   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'5'          ,ALTGR  ,WCH_DEAD ,0x00ad   ,'5'      ,'['      ,'5'      ,0x2075   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'5'      ,'5'      ,'5'      ,0x2085   ,'5'      ,0x2075   ,0x2085   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'6'          ,ALTGR  ,'-'      ,0x2011   ,'6'      ,'|'      ,'6'      ,0x2076   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'6'      ,'6'      ,'6'      ,0x2086   ,'6'      ,0x2076   ,0x2086   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'7'          ,ALTGR  ,0x00e8   ,0x00c8   ,'7'      ,WCH_DEAD ,'7'      ,0x2077   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'7'      ,'7'      ,'7'      ,0x2087   ,'7'      ,0x2077   ,0x2087   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'`'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'8'          ,KBD    ,'_'      ,0x2015   ,'8'      ,'\\'     ,'8'      ,0x2078   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'8'      ,'8'      ,'8'      ,0x2088   ,'8'      ,0x2078   ,0x2088   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'9'          ,KBD    ,0x00e7   ,0x00c7   ,'9'      ,'('      ,'9'      ,0x2079   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'9'      ,'9'      ,'9'      ,0x2089   ,'9'      ,0x2079   ,0x2089   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {'0'          ,KBD    ,0x00e0   ,0x00c0   ,'0'      ,')'      ,'0'      ,0x2070   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'0'      ,'0'      ,'0'      ,0x2080   ,'0'      ,0x2070   ,0x2080   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_MINUS ,ALTGR  ,'@'      ,0x00b0   ,0x1d49   ,']'      ,0x00b0   ,0x207b   ,'E'      ,WCH_LGTR ,WCH_NONE ,'@'      ,0x00b0   ,'-'      ,0x208b   ,'E'      ,0x207b   ,0x208b   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {VK_OEM_PLUS  ,ALTGR  ,'\''     ,'+'      ,WCH_DEAD ,'}'      ,'='      ,0x207a   ,'F'      ,WCH_LGTR ,WCH_NONE ,'='      ,'+'      ,WCH_DEAD ,0x208a   ,'F'      ,0x207a   ,0x208a   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'A'          ,CAPLOK ,'a'      ,'A'      ,'^'      ,WCH_DEAD ,'^'      ,0x1d43   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'^'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Z'          ,CAPLOK ,'z'      ,'Z'      ,'%'      ,WCH_DEAD ,'%'      ,0x1dbb   ,0x2032   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0250   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'E'          ,CAPLOK ,'e'      ,'E'      ,0x20ac   ,WCH_DEAD ,0x20ac   ,0x1d49   ,0x2033   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0151   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'R'          ,CAPLOK ,'r'      ,'R'      ,'\\'     ,WCH_DEAD ,0x00a3   ,0x02b3   ,0x2236   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1D19   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'T'          ,CAPLOK ,'t'      ,'T'      ,'~'      ,WCH_DEAD ,0x2212   ,0x1d57   ,0x00b1   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Y'          ,CAPLOK ,'y'      ,'Y'      ,WCH_DEAD ,WCH_DEAD ,0x00b5   ,0x02b8   ,0x00a5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,0x03b5   ,0x03b5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'U'          ,CAPLOK ,'u'      ,'U'      ,'\''     ,WCH_DEAD ,'4'      ,0x1d58   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00e1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'I'          ,CAPLOK ,'i'      ,'I'      ,'{'      ,WCH_DEAD ,'5'      ,0x2071   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0192   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'O'          ,CAPLOK ,'o'      ,'O'      ,'}'      ,WCH_DEAD ,'6'      ,0x1d52   ,0x03a9   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0273   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'P'          ,CAPLOK ,'p'      ,'P'      ,'&'      ,WCH_DEAD ,'.'      ,0x1d56   ,0x00b6   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e57   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_6     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'^'      ,0x2039   ,WCH_DEAD ,'C'      ,'['      ,WCH_NONE ,'"'      ,'{'      ,'^'      ,'_'      ,'C'      ,'^'      ,'_'      ,'['      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00ea   ,WCH_NONE ,0x00f5   ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_1     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'$'      ,0x203a   ,0x00a3   ,'D'      ,']'      ,WCH_NONE ,'_'      ,'}'      ,WCH_DEAD ,0x00a4   ,'D'      ,0x207c   ,0x208c   ,']'      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x00e1   ,WCH_NONE ,0x00f2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'Q'          ,CAPLOK ,'q'      ,'Q'      ,'#'      ,WCH_DEAD ,'#'      ,WCH_LGTR ,0x200d   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'S'          ,CAPLOK ,'s'      ,'S'      ,'$'      ,WCH_DEAD ,'$'      ,0x02e2   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a4   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'D'          ,CAPLOK ,'d'      ,'D'      ,'('      ,WCH_DEAD ,'('      ,0x1d48   ,0x2300   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0213   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'F'          ,CAPLOK ,'f'      ,'F'      ,')'      ,WCH_DEAD ,')'      ,0x1da0   ,0x2013   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0115   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,CAPLOK ,'g'      ,'G'      ,'-'      ,WCH_DEAD ,'-'      ,0x1d4d   ,0x2192   ,0x21d2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x024d   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,CAPLOK ,'h'      ,'H'      ,'+'      ,WCH_DEAD ,'+'      ,0x02b0   ,0x2064   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x01a1   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,CAPLOK ,'j'      ,'J'      ,'_'      ,WCH_DEAD ,'1'      ,0x02b2   ,0x203e   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'_'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,CAPLOK ,'k'      ,'K'      ,'['      ,WCH_DEAD ,'2'      ,0x1d4f   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x01eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,CAPLOK ,'l'      ,'L'      ,']'      ,WCH_DEAD ,'3'      ,0x02e1   ,0x00a3   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1ebb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'M'          ,CAPLOK ,'m'      ,'M'      ,'|'      ,WCH_DEAD ,','      ,0x1d50   ,0x00b5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0101   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,SGCAPS ,0x00f9   ,WCH_LGTR ,0x2026   ,WCH_LGTR ,0x00ab   ,'%'      ,'A'      ,'\''     ,WCH_NONE ,'\''     ,'%'      ,'`'      ,0x208d   ,'A'      ,0x207d   ,0x208d   ,'\''     ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
//{0xff         ,0      ,0x00d9   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0xff         ,0      ,0x00d9   ,0x00ab   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
//{VK_OEM_3     ,0      ,0x00d9   ,WCH_LGTR }, // This does not work.
//{VK_OEM_3     ,0      ,0x00d9   ,0x00ab   }, // This works.
// This key is bugged, as neither the short form nor the long form works as designed. 2025-06-08T0338+0200
// https://archives.miloush.net/michkap/archive/2010/07/07/10032340.html
// https://archives.miloush.net/michkap/archive/2006/01/16/513088.html
  {VK_OEM_5     ,ALTGR  ,WCH_DEAD ,WCH_LGTR ,WCH_DEAD ,'*'      ,0x00bb   ,0x00b5   ,'B'      ,';'      ,WCH_NONE ,'-'      ,'*'      ,WCH_DEAD ,0x208e   ,'B'      ,0x207e   ,0x208e   ,';'      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,0x2460   ,WCH_NONE ,0x2460   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a6   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'W'          ,CAPLOK ,'w'      ,'W'      ,'/'      ,WCH_DEAD ,'/'      ,0x02b7   ,0x200c   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f8   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'X'          ,CAPLOK ,'x'      ,'X'      ,'*'      ,WCH_DEAD ,'*'      ,0x02e3   ,0x22c5   ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00e5   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,CAPLOK ,'c'      ,'C'      ,'<'      ,WCH_DEAD ,0x00d7   ,0x1d9c   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00ea   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'V'          ,CAPLOK ,'v'      ,'V'      ,'>'      ,WCH_DEAD ,0x00f7   ,0x1d5b   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x021f   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,CAPLOK ,'b'      ,'B'      ,'='      ,WCH_DEAD ,WCH_LGTR ,0x1d47   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x2690   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,CAPLOK ,'n'      ,'N'      ,'`'      ,WCH_DEAD ,'0'      ,0x207f   ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00f2   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_COMMA ,ALTGR  ,','      ,WCH_LGTR ,'?'      ,WCH_DEAD ,'?'      ,'?'      ,0x2063   ,WCH_LGTR ,WCH_NONE ,','      ,'?'      ,'?'      ,WCH_DEAD ,'?'      ,WCH_LGTR ,0x2007   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00E7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00E7   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_PERIOD,ALTGR  ,'.'      ,WCH_LGTR ,'!'      ,WCH_DEAD ,';'      ,';'      ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,'.'      ,'\\'     ,'!'      ,WCH_DEAD ,';'      ,WCH_LGTR ,0x2008   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x1e05   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,ALTGR  ,'/'      ,WCH_LGTR ,':'      ,WCH_DEAD ,':'      ,':'      ,0x2044   ,WCH_LGTR ,WCH_NONE ,':'      ,'/'      ,':'      ,WCH_DEAD ,':'      ,0x2044   ,0x2044   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00eb   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_8     ,ALTGR  ,0x00b7   ,WCH_LGTR ,0x00a7   ,WCH_DEAD ,'!'      ,'!'      ,0x00a7   ,WCH_LGTR ,WCH_NONE ,';'      ,'!'      ,';'      ,WCH_DEAD ,'!'      ,0x00a7   ,0x00a7   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0219   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0219   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_SPACE     ,ALTGR  ,' '      ,' '      ,0x00a0   ,0x200b   ,0x202f   ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,' '      ,' '      ,' '      ,' '      ,WCH_LGTR ,' '      ,WCH_LGTR ,WCH_LGTR ,WCH_LGTR ,0x2060   ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,0x2060   ,0x2060   ,0x2060   ,0x2060   },
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  //                    |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |   17    |   18    |   19    |   20    |   21    |   22    |   23    |   24    |   25    |   26    |   27    |   28    |   29    |   30    |   31    |   32    |
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS9 aVkToWch9[] = {
  //                    |         |  Shift  |         |S+       |         |S+       |         |S+       |  Ctrl   |
  // Modification #     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |
  // UX Level           |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |  Ctrl   |
  //                    |=========|=========|=========|=========|=========|=========|=========|=========|=========|
  // The backspace key is bugged with Shift and does not work with nor without the modification #1 allocation.
  {VK_BACK      ,0      ,'\b'     ,'\b'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x007f   },
  // The escape key yields the variant name at level 5, and the version # at level 6.
  {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,WCH_NONE ,WCH_NONE ,WCH_LGTR ,WCH_LGTR ,WCH_NONE ,WCH_NONE ,0x001b   },
  {VK_RETURN    ,0      ,'\r'     ,'\r'     ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'\n'     },
  {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x0003   },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch33)
// before considering the numpad (aVkToWch17).
//
// Numpad specials are deactivated as redundant and detrimentally affecting the
// user experience while the numlock toggle is repurposed for the integrated or
// overlay numpad on compact keyboards.
// See kbcommon.h subsection 6.1
//
// While on digit keys, all 8 levels are used for the sake of arrows, depending
// on the KanaLock toggle state, the decimal separator and operator keys offer
// only minimal functionality, as AltGr is unfit for the numpad. However, so as
// to prevent these keys from seeming broken, level 5 is replicated at levels 3
// and 7, and so is level 6 at levels 4 and 8.

static ALLOC_SECTION_LDATA VK_TO_WCHARS17 aVkToWch17[] = {
//                      |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14    |   15    |   16    |
//                      |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |  Ctrl   |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |
//                      |=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
  {VK_DIVIDE    ,KANALOK,'/'      ,0x00F7   ,0x221A   ,'('      ,0x221A   ,'('      ,0x221A   ,'('      ,WCH_NONE ,'/'      ,'('      ,'['      ,WCH_LGTR ,'['      ,WCH_LGTR ,'['      ,WCH_LGTR },
  {VK_MULTIPLY  ,KANALOK,'*'      ,0x00D7   ,'^'      ,')'      ,'^'      ,')'      ,'^'      ,')'      ,WCH_NONE ,'*'      ,')'      ,']'      ,WCH_LGTR ,']'      ,WCH_LGTR ,']'      ,WCH_LGTR },
  {VK_SUBTRACT  ,KANALOK,'-'      ,0x2212   ,'='      ,0x2243   ,'='      ,0x2243   ,'='      ,0x2243   ,WCH_NONE ,'-'      ,'^'      ,'='      ,'}'      ,'='      ,'}'      ,'='      ,'}'      },
  {VK_ADD       ,KANALOK,'+'      ,0x202F   ,0x00B1   ,0x2248   ,0x00B1   ,0x2248   ,0x00B1   ,0x2248   ,WCH_NONE ,'+'      ,'#'      ,0x00B1   ,WCH_LGTR ,0x00B1   ,WCH_LGTR ,0x00B1   ,WCH_LGTR },
  {VK_DECIMAL   ,CAPLOK ,'.'      ,','      ,0x202F   ,0x00A0   ,0x202F   ,0x00A0   ,0x202F   ,0x00A0   ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_NUMPAD0   ,KANALOK,'0'      ,WCH_LGTR ,0x2195   ,0x21D5   ,0x2195   ,0x2B0D   ,0x2B65   ,0x21F3   ,WCH_NONE ,'0'      ,WCH_LGTR ,0x2B65   ,0x21F3   ,0x2195   ,0x21D5   ,0x2195   ,0x2B0D   },
  {VK_NUMPAD1   ,KANALOK,'1'      ,WCH_LGTR ,0x2199   ,0x21D9   ,0x2199   ,0x2B0B   ,0x2B69   ,0x2B03   ,WCH_NONE ,'1'      ,WCH_LGTR ,0x2B69   ,0x2B03   ,0x2199   ,0x21D9   ,0x2199   ,0x2B0B   },
  {VK_NUMPAD2   ,KANALOK,'2'      ,'A'      ,0x2193   ,0x21D3   ,0x2B07   ,0x2B07   ,0x2B63   ,0x21E9   ,WCH_NONE ,'2'      ,'a'      ,0x2B63   ,0x21E9   ,0x2193   ,0x21D3   ,0x2B07   ,0x2B07   },
  {VK_NUMPAD3   ,KANALOK,'3'      ,'B'      ,0x2198   ,0x21D8   ,0x2198   ,0x2B0A   ,0x2B68   ,0x2B02   ,WCH_NONE ,'3'      ,'b'      ,0x2B68   ,0x2B02   ,0x2198   ,0x21D8   ,0x2198   ,0x2B0A   },
  {VK_NUMPAD4   ,KANALOK,'4'      ,':'      ,0x2190   ,0x21D0   ,0x2B05   ,0x2B05   ,0x2B60   ,0x21E6   ,WCH_NONE ,'4'      ,':'      ,0x2B60   ,0x21E6   ,0x2190   ,0x21D0   ,0x2B05   ,0x2B05   },
  {VK_NUMPAD5   ,KANALOK,'5'      ,'C'      ,0x2194   ,0x21D4   ,0x2194   ,0x2B0C   ,0x2B64   ,0x2B04   ,WCH_NONE ,'5'      ,'c'      ,0x2B64   ,0x2B04   ,0x2194   ,0x21D4   ,0x2194   ,0x2B0C   },
  {VK_NUMPAD6   ,KANALOK,'6'      ,'D'      ,0x2192   ,0x21D2   ,0x27A1   ,0x27A1   ,0x2B62   ,0x21E8   ,WCH_NONE ,'6'      ,'d'      ,0x2B62   ,0x21E8   ,0x2192   ,0x21D2   ,0x27A1   ,0x27A1   },
  {VK_NUMPAD7   ,KANALOK,'7'      ,0x2044   ,0x2196   ,0x21D6   ,0x2196   ,0x2B09   ,0x2B66   ,0x2B01   ,WCH_NONE ,'7'      ,'\\'     ,0x2B66   ,0x2B01   ,0x2196   ,0x21D6   ,0x2196   ,0x2B09   },
  {VK_NUMPAD8   ,KANALOK,'8'      ,'E'      ,0x2191   ,0x21D1   ,0x2B06   ,0x2B06   ,0x2B61   ,0x21E7   ,WCH_NONE ,'8'      ,'e'      ,0x2B61   ,0x21E7   ,0x2191   ,0x21D1   ,0x2B06   ,0x2B06   },
  {VK_NUMPAD9   ,KANALOK,'9'      ,'F'      ,0x2197   ,0x21D7   ,0x2197   ,0x2B08   ,0x2B67   ,0x2B00   ,WCH_NONE ,'9'      ,'f'      ,0x2B67   ,0x2B00   ,0x2197   ,0x21D7   ,0x2197   ,0x2B08   },
  {0            ,0      ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     ,'\0'     }
};

static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
  {  (PVK_TO_WCHARS1)aVkToWch2 ,  2, sizeof(aVkToWch2[0]) },
  {  (PVK_TO_WCHARS1)aVkToWch33, 33, sizeof(aVkToWch33[0]) },
  {  (PVK_TO_WCHARS1)aVkToWch9 ,  9, sizeof(aVkToWch9[0]) },
  {  (PVK_TO_WCHARS1)aVkToWch17, 17, sizeof(aVkToWch17[0]) },
  {                       NULL ,  0, 0                    },
};

/*****************************************************************************\
* aKeyNames[], aKeyNamesExt[]  - Virtual Scancode to Key Name tables
*
* Table attributes: Ordered Scan (by scancode), null-terminated
*
* Only the names of Extended, NumPad, Dead and Non-Printable keys are here.
* (Keys producing printable characters are named by that character)
\*****************************************************************************/

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNames[] = {
    0x01,    L"Esc",
    0x0e,    L"Backspace",
    0x0f,    L"Tab",
    0x1c,    L"Enter",
    0x1d,    L"Ctrl",
    0x2a,    L"Shift",
    0x36,    L"Right Shift",
    0x37,    L"Num *",
    0x38,    L"Alt",
    0x39,    L"Space",
    0x3a,    L"Caps Lock",
    0x3b,    L"F1",
    0x3c,    L"F2",
    0x3d,    L"F3",
    0x3e,    L"F4",
    0x3f,    L"F5",
    0x40,    L"F6",
    0x41,    L"F7",
    0x42,    L"F8",
    0x43,    L"F9",
    0x44,    L"F10",
    0x45,    L"Pause",
    0x46,    L"Scroll Lock",
    0x47,    L"Num 7",
    0x48,    L"Num 8",
    0x49,    L"Num 9",
    0x4a,    L"Num -",
    0x4b,    L"Num 4",
    0x4c,    L"Num 5",
    0x4d,    L"Num 6",
    0x4e,    L"Num +",
    0x4f,    L"Num 1",
    0x50,    L"Num 2",
    0x51,    L"Num 3",
    0x52,    L"Num 0",
    0x53,    L"Num Del",
    0x54,    L"Sys Req",
    0x57,    L"F11",
    0x58,    L"F12",
    0x7c,    L"F13",
    0x7d,    L"F14",
    0x7e,    L"F15",
    0x7f,    L"F16",
    0x80,    L"F17",
    0x81,    L"F18",
    0x82,    L"F19",
    0x83,    L"F20",
    0x84,    L"F21",
    0x85,    L"F22",
    0x86,    L"F23",
    0x87,    L"F24",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNamesExt[] = {
    0x1c,    L"Num Enter",
    0x1d,    L"Right Ctrl",
    0x35,    L"Num /",
    0x37,    L"Prnt Scrn",
    0x38,    L"Right Alt",
    0x45,    L"Num Lock",
    0x46,    L"Break",
    0x47,    L"Home",
    0x48,    L"Up",
    0x49,    L"Page Up",
    0x4b,    L"Left",
    0x4d,    L"Right",
    0x4f,    L"End",
    0x50,    L"Down",
    0x51,    L"Page Down",
    0x52,    L"Insert",
    0x53,    L"Delete",
    0x54,    L"<00>",
    0x56,    L"Help",
    0x5b,    L"Left Windows",
    0x5c,    L"Right Windows",
    0x5d,    L"Application",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA DEADKEY_LPWSTR aKeyNamesDead[] = {
    L"\x00eb"	L"MINUSCULE LATINE E TRÉMA",
    L"\x00e1"	L"MINUSCULE LATINE A ACCENT AIGU",
    L"^"	L"ACCENT CIRCONFLEXE",
    L"^"	L"ACCENT CIRCONFLEXE",
    L"\x0250"	L"MINUSCULE LATINE A TOURNÉ",
    L"\x0151"	L"MINUSCULE LATINE O DOUBLE ACCENT AIGU",
    L"\x1D19"	L"PETITE CAPITALE LATINE R RÉFLÉCHI",
    L"\x00f5"	L"MINUSCULE LATINE O TILDE",
    L"\x00a6"	L"DEUX-BARRETTES",
    L"\x03b5"	L"MINUSCULE GRECQUE EPSILON",
    L"\x00f2"	L"MINUSCULE LATINE O ACCENT GRAVE",
    L"\x00e1"	L"MINUSCULE LATINE A ACCENT AIGU",
    L"\x0192"	L"MINUSCULE LATINE F HAMEÇON",
    L"\x0273"	L"MINUSCULE LATINE N HAMEÇON RÉTROFLEXE",
    L"\x0e57"	L"MINUSCULE LATINE P POINT EN CHEF",
    L"\x00ea"	L"MINUSCULE LATINE E ACCENT CIRCONFLEXE",
    L"\x00b2"	L"EXPOSANT CHIFFRE DEUX",
    L"\x00b2"	L"EXPOSANT CHIFFRE DEUX",
    L"\x00a4"	L"SYMBOLE MONÉTAIRE GÉNÉRIQUE",
    L"\x0213"	L"MINUSCULE LATINE R BRÈVE INVERSÉE",
    L"\x0115"	L"MINUSCULE LATINE E BRÈVE",
    L"\x024d"	L"MINUSCULE LATINE R RAYÉ",
    L"\x01a1"	L"MINUSCULE LATINE O CORNU",
    L"_"	L"TIRET BAS",
    L"\x01eb"	L"MINUSCULE LATINE O OGONEK",
    L"\x0ebb"	L"MINUSCULE LATINE E CROCHET EN CHEF",
    L"\x0101"	L"MINUSCULE LATINE A MACRON",
    L"\x00f8"	L"MINUSCULE LATINE O BARRÉ",
    L"\x00e5"	L"MINUSCULE LATINE A ROND EN CHEF",
    L"\x00ea"	L"MINUSCULE LATINE E ACCENT CIRCONFLEXE",
    L"\x021f"	L"MINUSCULE LATINE H HATCHEK",
    L"\x0690"	L"DRAPEAU NEUTRE",
    L"\x00f2"	L"MINUSCULE LATINE O ACCENT GRAVE",
    L"\x00E7"	L"MINUSCULE LATINE C CÉDILLE",
    L"\x0e05"	L"MINUSCULE LATINE B POINT SOUSCRIT",
    L"\x00eb"	L"MINUSCULE LATINE E TRÉMA",
    L"\x0219"	L"MINUSCULE LATINE S VIRGULE SOUSCRITE",
    NULL
};

static ALLOC_SECTION_LDATA KBDTABLES KbdTables = {
    /*
     * Modifier keys
     */
    &CharModifiers,

    /*
     * Characters tables
     */
    aVkToWcharTable,

    /*
     * Diacritics
     */
    aDeadKey,

    /*
     * Names of Keys
     */
    aKeyNames,
    aKeyNamesExt,
    aKeyNamesDead,

    /*
     * Scan codes to Virtual Keys
     */
    ausVK,
    sizeof(ausVK) / sizeof(ausVK[0]),
    aE0VscToVk,
    aE1VscToVk,

    /*
     * Locale-specific special processing
     */
    MAKELONG(KLLF_ALTGR, KBD_VERSION),

    /*
     * Ligatures
     */
    16,
    sizeof(aLigature[0]),
    (PLIGATURE1)aLigature
};

PKBDTABLES KbdLayerDescriptor(VOID)
{
    return &KbdTables;
}
